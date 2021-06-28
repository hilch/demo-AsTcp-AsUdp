/* ------------------------------------------------------------------------------------------------------------
example for AsTCP- library
connect with 'udpclient.py'. 
---------------------------------------------------------------------------------------------------------------*/

#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif

/* --------------------------------------------------------------------------------------------------------
   startup after powerfail
--------------------------------------------------------------------------------------------------------
*/

           
void _INIT Initialisierung( void )
{
    brsmemset( (UDINT) &open, 0, sizeof(open) );
    brsmemset( (UDINT) &close, 0, sizeof(close) );
    brsmemset( (UDINT) &recv, 0, sizeof(recv) );
    brsmemset( (UDINT) &send, 0, sizeof(send) );
    
    open.enable = 1;
	open.options = 0;//udpOPT_REUSEPORT;
    open.port = PORT;  /* receive port */
    open.pIfAddr = 0; 
    UdpOpen( &open );
    
    recv.enable = 1;
    recv.ident = open.ident;
    recv.pData = (UDINT) &receive_buffer; 
	recv.pIpAddr = (UDINT) sender_ip_addr;
    recv.datamax = sizeof(receive_buffer);
    
    send.enable = 1;
    send.ident = open.ident;
    send.flags = 0; 
    send.pData = (UDINT) send_buffer;
    send.datalen = 0;
    
    
}


/* --------------------------------------------------------------------------------------------------------
    cyclic code
--------------------------------------------------------------------------------------------------------
*/

void _CYCLIC Zyklisch( void )
{
	UdpRecv( &recv );
	
	if( recv.status == 0 ){
		brsstrcpy( (UDINT) send_buffer, (UDINT) "echo: " );
		brsstrcat( (UDINT) send_buffer, (UDINT) receive_buffer );
		brsmemset( (UDINT) receive_buffer, 0 , sizeof(receive_buffer) );
		send.datalen = brsstrlen( (UDINT) send_buffer );
		send.pHost = (UDINT) sender_ip_addr; /* return back to sender */
		send.port = recv.port;
		send.enable = 1;
	}
	  
    UdpSend( &send );
    if( send.enable && send.status != ERR_FUB_BUSY ){
        send.enable = 0;
		brsmemset( (UDINT) send_buffer, 0 , sizeof(send_buffer) );		
    }
    
    
    
}

/* --------------------------------------------------------------------------------------------------------
   is called when overloading the task
--------------------------------------------------------------------------------------------------------
*/


void _EXIT Exit( void ){
    close.enable = 1;
    close.ident = open.ident;
    do {
        UdpClose( &close );
    }
    while( close.status == 65535 );
    
}
