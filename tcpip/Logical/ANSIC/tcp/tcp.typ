
TYPE
	CLIENT_typ : 	STRUCT 
		connected : BOOL;
		data_received : BOOL;
		addr : STRING[19];
		portclnt : UINT;
		receive_buffer : ARRAY[0..255]OF USINT;
		recv : TcpRecv;
		send : TcpSend;
		close : TcpClose;
	END_STRUCT;
END_TYPE
