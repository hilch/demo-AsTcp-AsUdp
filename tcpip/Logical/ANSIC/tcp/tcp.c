/* ------------------------------------------------------------------------------------------------------------
example for AsTCP- library
connect with 'tcpclient.py'. Multiple connections in parallel are possible.
---------------------------------------------------------------------------------------------------------------*/

#define _REPLACE_CONST

/*
	using _REPLACE_CONST enables defining constants in *.var files
	and automatically creates #defines from them.

	on the other hand, this leads to a warning 6424 being generated which
	can be suppressed by adding 
		-W 6424
	to 'Additional build options' (either to complete project or 'tcp' task only) 
*/

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif
#include <bur/plctypes.h>


char*				p_step_str;
char*				p_step_str_old;




/* --------------------------------------------------------------------------------------------------------
	startup after powerfail
--------------------------------------------------------------------------------------------------------
*/


void _INIT Initialisierung( void ){
    
	/* this could be useful when task is overloaded... */
	brsmemset( (UDINT) &open, 0, sizeof(open) );
	brsmemset( (UDINT) &close, 0, sizeof(close) );
	brsmemset( (UDINT) &server, 0, sizeof(server) );
	brsmemset( (UDINT) &getipaddr, 0, sizeof(getipaddr) );

	brsmemset( (UDINT) &client, 0, sizeof(client) );
    

	welcome_message = (USINT*) "Welcome to B&R Automation Runtime\nPress\n'1' for first message\n'2' for second message\n'3' to abort connection\n";
	first_message = (USINT*) "Hi Mickey Mouse\n";
	second_message = (USINT*) "Hi Donald Duck\n";

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
	cyclic code
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
			brsstrcpy( (UDINT) errstring, (UDINT) "error TcpOpen()" );
			error = open.status;
			step = SERVER_ERROR;
		}
		break;


	case SERVER_RUNNING:
		p_step_str = "server is running";
		TcpServer( &server );
		if( server.status == 0 ){  /* a new client has connected */
			for( i = 0; i < MAX_CLIENTS; ++i ){
				if( !client[i].connected ){
					client[i].connected = 1;
					brsstrcpy( (UDINT) client[i].addr, (UDINT) tempstring );
					client[i].recv.ident = server.identclnt;
					client[i].portclnt = server.portclnt;
					client[i].recv.enable = 1;
					client[i].recv.pData = (UDINT) client[i].receive_buffer;
					client[i].recv.datamax = sizeof(client[i].receive_buffer);
					client[i].recv.flags = 0;
					client[i].send.ident = server.identclnt;
					client[i].send.pData = (UDINT) welcome_message;
					client[i].send.datalen = brsstrlen( (UDINT) welcome_message );
					client[i].send.enable = 1;
					client[i].close.enable = 0;
					client[i].close.ident = server.identclnt;
					break;
				}
			}
		}


		/* Noodle through all clients */
		for( i = 0; i < MAX_CLIENTS; ++i ){

			/* receive data... */
			TcpRecv( &client[i].recv );

			if( client[i].recv.status == tcpERR_NOT_CONNECTED || client[i].recv.status == tcpERR_INVALID_IDENT || client[i].recv.status == tcpERR_SYSTEM ){
				client[i].close.enable = 1;
			}
			else if( client[i].recv.status == 0 ){
				if( client[i].recv.recvlen != 0 ){
					client[i].data_received = 1; /* Flag: Data has been received */
                }
                else if( client[i].recv.recvlen == 0 ){  /* Remote station has closed write direction */
                    client[i].close.enable = 1;
                }
                
			}


			/* Process input data ...*/
			if( client[i].data_received && client[i].send.enable == 0 ){  /* Data has arrived and send buffer is free */
				client[i].data_received = 0;
				switch( client[i].receive_buffer[0] ){
				case '1':
					client[i].send.pData = (UDINT) first_message;
					client[i].send.datalen = brsstrlen( (UDINT) client[i].send.pData );
					client[i].send.enable = 1;
					break;

				case '2':
					client[i].send.pData = (UDINT) second_message;
					client[i].send.datalen = brsstrlen( (UDINT) client[i].send.pData );
					client[i].send.enable = 1;
					break;

				case '3':
                    client[i].send.pData = (UDINT) "bye, bye\n";
                    client[i].send.datalen = brsstrlen( (UDINT) client[i].send.pData ); 
                    client[i].send.enable = 1;                                   
					client[i].close.enable = 1;
					break;
				}
			}


			/* send output data */
			TcpSend( &client[i].send );
			if( client[i].send.status == 0 ){ /* sent successfully */
				client[i].send.enable = 0;
			}
			else if( (client[i].send.status != ERR_FUB_BUSY) && (client[i].send.status != ERR_FUB_ENABLE_FALSE) ){ /* error */
				client[i].send.enable = 0;
			}



			/* Release socket when connection is lost */
			TcpClose( &client[i].close );
            if( client[i].close.enable == 1 && client[i].close.status == 0 ){
               brsmemset( (UDINT) &client[i], 0, sizeof(CLIENT_typ) );
            }            
		} /* end for( i = 0; i < MAX_CLIENTS... */

		break;




	case SERVER_ERROR:
		p_step_str = "error";

		break;

	}




	if( p_step_str != p_step_str_old ){
		p_step_str_old = p_step_str;
		brsstrcpy( (UDINT) step_str, (UDINT) p_step_str );
	}





}


/* --------------------------------------------------------------------------------------------------------
	is called on overload of the task
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
