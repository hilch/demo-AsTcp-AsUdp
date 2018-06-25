/* ------------------------------------------------------------------------------------------------------------
Beispiel zur AsTCP- Library
Test mit "telnet 10.49.40.221 1000" in der Console (kann auch mehrfach gleichzeitig geöffnet werden)
---------------------------------------------------------------------------------------------------------------*/


#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif
#include <bur/plctypes.h>
#include <string.h>


#define		ERR_FUB_BUSY	65535
#define     PORT            1000


#define 	SERVER_OPEN			0
#define		SERVER_RUNNING		10
#define		SERVER_ERROR		900


char*				p_step_str;
char*				p_step_str_old;




/* --------------------------------------------------------------------------------------------------------
	wird beim Hochstarten der CPU durchlaufen
--------------------------------------------------------------------------------------------------------
*/


void _INIT Initialisierung( void ){
    int dummy;
    dummy = MAX_CLIENT_INDEX;  /* wg. Compiler- warning */
    
	memset( &open, 0, sizeof(open) );
	memset( &close, 0, sizeof(close) );
	memset( &server, 0, sizeof(server) );
	memset( &getipaddr, 0, sizeof(getipaddr) );
    memset( &hwinfo, 0, sizeof(hwinfo) );

	memset( &client, 0, sizeof(client) );
    
    hwinfo.enable = 1;
    hwinfo.first = 1;
    hwinfo.pName = 0;
    HWInfo( &hwinfo);
    
    
    

	welcome_message = (USINT*) "\r\n\tWelcome to B&R\r\n\tPress\r\n\t1 -- first message\r\n\t2 -- second message\r\n\t3 -- abort connection\r\n\r\n\t-->";
	first_message = (USINT*) "\r\nMickey Mouse\r\n\r\n\t-->";
	second_message = (USINT*) "\r\nDonald Duck\r\n\r\n\t-->";

	server.enable = 1;

	getipaddr.enable = 1;
	getipaddr.pDevice = (UDINT) "IF2";
	getipaddr.pIPAddr = (UDINT) myip;
	getipaddr.Len = sizeof(myip);

	step = SERVER_OPEN;
	p_step_str = "INIT_UP";
	p_step_str_old = 0;
}


/* --------------------------------------------------------------------------------------------------------
	wird zyklisch durchlaufen
--------------------------------------------------------------------------------------------------------
*/



void _CYCLIC Zyklisch( void ){
	int i;

	CfgGetIPAddr( &getipaddr );
	if( getipaddr.status == 0 ){
		getipaddr.enable = 0;
	}


	switch( step ){
	case SERVER_OPEN:
		p_step_str = "TcpOpen()";
		open.enable = 1;
		open.pIfAddr = 0;
		open.port = PORT;
		open.options = tcpOPT_REUSEADDR ;
		TcpOpen( &open );
		if( open.status == 0 ){
			server.ident = open.ident;
			server.backlog = 10;
			server.pIpAddr = (UDINT) tempstring;
			step = SERVER_RUNNING;
		}
		else if( open.status != ERR_FUB_BUSY ){
			strcpy( errstring, "Fehler bei TcpOpen()" );
			error = open.status;
			step = SERVER_ERROR;
		}
		break;


	case SERVER_RUNNING:
		p_step_str = "Server laeuft";
		TcpServer( &server );
		if( server.status == 0 ){  /* ein neuer Client hat sich verbunden */
			for( i = 0; i < MAX_CLIENTS; ++i ){
				if( !client[i].connected ){
					client[i].connected = 1;
					strcpy( client[i].addr, tempstring );
					client[i].recv.ident = server.identclnt;
					client[i].portclnt = server.portclnt;
					client[i].recv.enable = 1;
					client[i].recv.pData = (UDINT) client[i].receive_buffer;
					client[i].recv.datamax = sizeof(client[i].receive_buffer);
					client[i].recv.flags = 0;
					client[i].send.ident = server.identclnt;
					client[i].send.pData = (UDINT) welcome_message;
					client[i].send.datalen = strlen( (char*) welcome_message );
					client[i].send.enable = 1;
					client[i].close.enable = 0;
					client[i].close.ident = server.identclnt;
					break;
				}
			}
		}


		/* alle Clients durchnudeln */
		for( i = 0; i < MAX_CLIENTS; ++i ){

			/* Daten empfangen */
			TcpRecv( &client[i].recv );

			if( client[i].recv.status == tcpERR_NOT_CONNECTED || client[i].recv.status == tcpERR_INVALID_IDENT){
				client[i].close.enable = 1;
			}
			else if( client[i].recv.status == 0 ){
				if( client[i].recv.recvlen != 0 ){
					client[i].data_received = 1; /* Flag: Daten sind empfangen worden */
                }
                else if( client[i].recv.recvlen == 0 ){  /* Gegenstelle hat Schreibrichtung geschlossen */
                    client[i].close.enable = 1;
                }
                
			}


			/* Eingangsdaten verarbeiten ...*/
			if( client[i].data_received && client[i].send.enable == 0 ){  /* Daten sind angekommen und Sendebuffer ist frei */
				client[i].data_received = 0;
				switch( client[i].receive_buffer[0] ){
				case '1':
					client[i].send.pData = (UDINT) first_message;
					client[i].send.datalen = strlen( (char*) client[i].send.pData );
					client[i].send.enable = 1;
					break;

				case '2':
					client[i].send.pData = (UDINT) second_message;
					client[i].send.datalen = strlen( (char*) client[i].send.pData );
					client[i].send.enable = 1;
					break;

				case '3':
                    client[i].send.pData = (UDINT) "\nbye, bye";
                    client[i].send.datalen = strlen( (char*) client[i].send.pData ); 
                    client[i].send.enable = 1;                                   
					client[i].close.enable = 1;
					break;
				}
			}


			/* Daten senden */
			TcpSend( &client[i].send );
			if( client[i].send.status == 0 ){ /* erfolgreich gesendet */
				client[i].send.enable = 0;
			}



			/* Socket bei Verbindugsabbruch wieder freigeben */
			TcpClose( &client[i].close );
            if( client[i].close.enable == 1 && client[i].close.status == 0 ){
                memset( &client[i], 0, sizeof(CLIENT_typ) );
            }            
		}

		break;




	case SERVER_ERROR:
		p_step_str = "Fehler";

		break;

	}




	if( p_step_str != p_step_str_old ){
		p_step_str_old = p_step_str;
		strcpy( step_str, p_step_str );
	}





}


/* --------------------------------------------------------------------------------------------------------
	wird bei Overload des Task aufgerufen
--------------------------------------------------------------------------------------------------------
*/


void _EXIT Exit( void ){
	int i;
	
	for( i = 0; i < MAX_CLIENTS; ++i ){
		do	
			TcpClose( &client[i].close );
		while( client[i].close.status == ERR_FUB_BUSY );
	}
	
	do {
		close.enable = 1;
		close.ident = open.ident;
		close.how = 0;
		TcpClose( &close );
	}
	while( close.status == ERR_FUB_BUSY );

}
