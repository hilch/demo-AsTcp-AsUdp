
TYPE
	CLIENT_typ : {REDUND_UNREPLICABLE} 	STRUCT 
		connected : {REDUND_UNREPLICABLE} BOOL;
		data_received : {REDUND_UNREPLICABLE} BOOL;
		addr : {REDUND_UNREPLICABLE} STRING[19];
		portclnt : {REDUND_UNREPLICABLE} UINT;
		receive_buffer : {REDUND_UNREPLICABLE} ARRAY[0..255]OF USINT;
		recv : {REDUND_UNREPLICABLE} TcpRecv;
		send : {REDUND_UNREPLICABLE} TcpSend;
		close : {REDUND_UNREPLICABLE} TcpClose;
	END_STRUCT;
END_TYPE
