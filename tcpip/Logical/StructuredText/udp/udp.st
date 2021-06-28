(********************************************************************
 * COPYRIGHT -- B&R Industrial Automation GmbH
 ********************************************************************
 * Program: udp
 * File: udp.st
 * Author: hilchenbachc
 * Created: June 28, 2021
 ********************************************************************
 * Implementation of program udp
 ********************************************************************)


(* --------------------------------------------------------------------------------------------------------
   startup after powerfail
--------------------------------------------------------------------------------------------------------
*)

PROGRAM _INIT

    brsmemset( ADR(open), 0, SIZEOF(open) );
    brsmemset( ADR(close), 0, SIZEOF(close) );
    brsmemset( ADR(recv), 0, SIZEOF(recv) );
    brsmemset( ADR(send), 0, SIZEOF(send) );
    
    open.enable := TRUE;
	open.options := 0; //udpOPT_REUSEPORT;
    open.port := PORT;  (* receive port *)
    open.pIfAddr := 0; 
    open();
    
    recv.enable := TRUE;
    recv.ident := open.ident;
    recv.pData := ADR(receive_buffer); 
	recv.pIpAddr := ADR(sender_ip_addr);
    recv.datamax := SIZEOF(receive_buffer);
    
    send.enable := TRUE;
    send.ident := open.ident;
    send.flags := 0; 
    send.pData := ADR(send_buffer);
    send.datalen := 0;

END_PROGRAM

(* --------------------------------------------------------------------------------------------------------
    cyclic code
--------------------------------------------------------------------------------------------------------
*)

PROGRAM _CYCLIC

	recv();
	
	IF recv.status = 0 THEN
		brsstrcpy( ADR(send_buffer), ADR('echo:') );
		brsstrcat( ADR(send_buffer), ADR(receive_buffer) );
		brsmemset( ADR(receive_buffer), 0 , SIZEOF(receive_buffer) );
		send.datalen := brsstrlen( ADR(send_buffer) );
		send.pHost := ADR(sender_ip_addr); (* return back to sender *)
		send.port := recv.port;
		send.enable := TRUE;
	END_IF
	  
    send();

    IF send.enable AND send.status <> ERR_FUB_BUSY THEN
        send.enable := FALSE;
		brsmemset( ADR(send_buffer), 0 , SIZEOF(send_buffer) );		
    END_IF
    
   
END_PROGRAM


(* --------------------------------------------------------------------------------------------------------
   is called when overloading the task
--------------------------------------------------------------------------------------------------------
*)


PROGRAM _EXIT

    close.enable := TRUE;
    close.ident := open.ident;
    REPEAT
        close();
    	UNTIL close.status <> ERR_FUB_BUSY
    END_REPEAT

END_PROGRAM

