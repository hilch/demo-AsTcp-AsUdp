(*
example FOR AsTCP- library
connect with 'tcpclient.py'. Multiple connections in parallel are possible.
*)


(* startup after powerfail *)
PROGRAM _INIT

	(* this could be useful when task is overloaded... *)
	brsmemset( ADR(open), 0, SIZEOF(open) );
	brsmemset( ADR(close), 0, SIZEOF(close) );
	brsmemset( ADR(server), 0, SIZEOF(server) );
	brsmemset( ADR(getipaddr), 0, SIZEOF(getipaddr) );

	brsmemset( ADR(client), 0, SIZEOF(client) );

	server.enable := 1;

	getipaddr.enable := 1;
	getipaddr.pDevice := ADR('IF2');
	getipaddr.pIPAddr := ADR(myip);
	getipaddr.Len := SIZEOF(myip);

	step := SERVER_OPEN;



END_PROGRAM


(* cyclic code *)
PROGRAM _CYCLIC

	getipaddr();
	IF getipaddr.status = 0 THEN
		getipaddr.enable := FALSE;
	END_IF


	CASE step OF
	SERVER_OPEN:
		step_str := 'TcpOpen()';
		open.enable := TRUE;
		open.pIfAddr := 0;
		open.port := PORT;
		open.options := tcpOPT_REUSEADDR ;
		open();
		IF open.status = 0 THEN
			server.ident := open.ident;
			server.backlog := 10;
			server.pIpAddr := ADR(tempstring);
			step := SERVER_RUNNING;
		ELSIF open.status <> ERR_FUB_BUSY THEN
			errstring := 'error TcpOpen()';
			error := open.status;
			step := SERVER_ERROR;
		END_IF
		


	SERVER_RUNNING:
		step_str := 'server is running';
		server();
		IF  server.status = 0 THEN  (* a new client has connected *)
			FOR i := 0 TO (MAX_CLIENTS-1) DO
				IF NOT(client[i].connected)THEN
					client[i].connected := TRUE;
					client[i].addr := tempstring;	
					client[i].recv.ident := server.identclnt;
					client[i].portclnt := server.portclnt;
					client[i].recv.enable := TRUE;
					client[i].recv.pData := ADR(client[i].receive_buffer);
					client[i].recv.datamax := SIZEOF(client[i].receive_buffer);
					client[i].recv.flags := 0;
					client[i].send.ident := server.identclnt;
					client[i].send.pData := ADR(welcome_message);
					client[i].send.datalen := brsstrlen(ADR(welcome_message));
					client[i].send.enable := TRUE;
					client[i].close.enable := FALSE;
					client[i].close.ident := server.identclnt;
					EXIT;
				END_IF
			END_FOR	
		END_IF	


		(* Noodle through all clients *)
		FOR i := 0 TO (MAX_CLIENTS-1) DO 
			(* receive data... *)
			client[i].recv();

			IF client[i].recv.status = tcpERR_NOT_CONNECTED OR client[i].recv.status = tcpERR_INVALID_IDENT OR client[i].recv.status = tcpERR_SYSTEM THEN
				client[i].close.enable := TRUE;
			ELSIF client[i].recv.status = 0 THEN
				IF client[i].recv.recvlen <> 0 THEN
					client[i].data_received := TRUE; (* Flag: Data has been received *)
				ELSIF client[i].recv.recvlen = 0 THEN  (* Remote station has closed write direction *)
					client[i].close.enable := TRUE;
				END_IF
            END_IF
	

			(* Process input data ...*)
			IF client[i].data_received AND client[i].send.enable = 0 THEN  (* Data has arrived AND send buffer is free *)
				client[i].data_received := FALSE;
				CASE client[i].receive_buffer[0] OF
					49:  (* ascii '1' *)
					client[i].send.pData := ADR(first_message);
					client[i].send.datalen := brsstrlen( client[i].send.pData ); 
					client[i].send.enable := TRUE;
				
					50: (* ascii '2' *)
					client[i].send.pData := ADR(second_message);
					client[i].send.datalen := brsstrlen( client[i].send.pData ); 
					client[i].send.enable := TRUE;
		
					51: (* ascii '3' *)
					client[i].send.pData := ADR('bye, bye$n');
					client[i].send.datalen := brsstrlen( client[i].send.pData ); 
					client[i].send.enable := TRUE;                                   
					client[i].close.enable := TRUE;
				END_CASE
			END_IF


			(* send output data *)
			client[i].send();
			IF client[i].send.status = 0 THEN (* sent successfully *)
				client[i].send.enable := FALSE;
			ELSIF client[i].send.status <> ERR_FUB_BUSY AND client[i].send.status <> ERR_FUB_ENABLE_FALSE THEN (* error *)
				client[i].send.enable := FALSE;
			END_IF


			(* Release socket when connection is lost *)
			client[i].close();
			IF client[i].close.enable AND client[i].close.status = 0 THEN
				brsmemset( ADR(client[i]), 0, SIZEOF(CLIENT_typ) );
			END_IF
		END_FOR


	SERVER_ERROR:
		step_str := 'error';


	END_CASE

END_PROGRAM


(* is called on overload of the task *)
PROGRAM _EXIT
	
	FOR i := 0 TO (MAX_CLIENTS-1) DO 
		REPEAT	
			client[i].close();
			UNTIL client[i].close.status <> ERR_FUB_BUSY
		END_REPEAT
	END_FOR
	
	REPEAT 
		close.enable := TRUE;
		close.ident := open.ident;
		close.how := 0;
		close();
		UNTIL close.status <> ERR_FUB_BUSY
	END_REPEAT

END_PROGRAM

