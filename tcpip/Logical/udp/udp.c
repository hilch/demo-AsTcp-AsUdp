/********************************************************************
 * COPYRIGHT -- br
 ********************************************************************
 * Program: udp
 * File: udp.c
 * uses udpecho.exe from http://www.mcrenox.com.ar/downloads/
 * Created: August 27, 2008
 ********************************************************************
 * Implementation of program udp
 ********************************************************************/

#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif

#include <string.h>

/* --------------------------------------------------------------------------------------------------------
    wird beim Hochstarten der CPU durchlaufen
--------------------------------------------------------------------------------------------------------
*/


            
void _INIT Initialisierung( void )
{
    memset( &open, 0, sizeof(open) );
    memset( &close, 0, sizeof(close) );
    memset( &recv, 0, sizeof(recv) );
    memset( &send, 0, sizeof(send) );
    
    open.enable = 1;
    open.options = udpOPT_REUSEPORT;
    open.port = 5042;  // default port von udpecho.exe */
    open.pIfAddr = 0; 
    UdpOpen( &open );
    
    recv.enable = 1;
    recv.ident = open.ident;
    recv.pData = (UDINT) &receive_buffer;  /* Empfangsbuffer */
    recv.datamax = sizeof(receive_buffer);
    
    send.enable = 1;
    send.ident = open.ident;
    send.flags = 0;
    send.pHost = (UDINT) "10.49.40.107";   /* die CPU sendet nach udpecho.exe */
    send.port = 5042;  // default port von udpecho.exe */
    send.pData = (UDINT) "Goofy";
    send.datalen = strlen( (char*) send.pData);
    
    
}


/* --------------------------------------------------------------------------------------------------------
    wird zyklisch durchlaufen
--------------------------------------------------------------------------------------------------------
*/

void _CYCLIC Zyklisch( void )
{
	UdpRecv( &recv );
    
    if( start ){
        start = 0;
        memset( &receive_buffer, 0 , sizeof(receive_buffer) );
        send.enable = 1;        
    }
    UdpSend( &send );
    if( send.enable && send.status != 65535 ){
        send.enable = 0;
    }
    
    
    
}

/* --------------------------------------------------------------------------------------------------------
    wird bei Overload des Task aufgerufen
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
