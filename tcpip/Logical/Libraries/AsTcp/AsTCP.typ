                                                                      
TYPE
    tcpLINGER_typ		: STRUCT	(*linger*)
		lOnOff			: UDINT;	(*linger on/off*)
		lLinger			: UDINT;	(*linger time (seconds)*)
	END_STRUCT;
	
	tcpSO_ADDRESS_typ	: STRUCT	(*socket address*)
		pPort			: UDINT;	(*pointer where to store the portnumber*)
		pIpAddr			: UDINT;	(*pointer where to store the socket ip address*)
	END_STRUCT;	

    AsTcpCipherVersionEnum :  
        (
            asTCP_TLS_1_3 := 2                (*TLS 1.3*) (**) (*#PAR*)
        );
        
    AsTcpMcsType : STRUCT
        name                : STRING[255];            (*Managed Certificate Store name*)
        tlsVersion          : AsTcpCipherVersionEnum; (*TLS version*)
        trustListValidation : BOOL;                   (*Enables/disables trust list validation*)
    END_STRUCT;
END_TYPE
