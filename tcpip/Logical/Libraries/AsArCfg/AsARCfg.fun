FUNCTION_BLOCK CfgGetInaNode
	VAR_INPUT
		enable			: BOOL;
		pDevice			: UDINT;
	END_VAR

	VAR_OUTPUT
		status			: UINT;
		InaNode			: USINT;
	END_VAR

	VAR
        i_state			: UINT;			(* internal variable *)
		i_result		: UINT;			(* internal variable *)
        i_tmp			: UDINT;		(* internal variable *)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK CfgSetInaNode
	VAR_INPUT
		enable			: BOOL;
		pDevice			: UDINT;
		InaNode			: USINT;
		Option			: UDINT;
	END_VAR

	VAR_OUTPUT
		status			: UINT;
	END_VAR

	VAR
        i_state			: UINT;			(* internal variable *)
		i_result		: UINT;			(* internal variable *)
        i_tmp			: UDINT;		(* internal variable *)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK CfgGetIPAddr
	VAR_INPUT
		enable			: BOOL;
		pDevice			: UDINT;
		pIPAddr			: UDINT;
		Len				: USINT;
	END_VAR

	VAR_OUTPUT
		status			: UINT;
	END_VAR

	VAR
        i_state			: UINT;			(* internal variable *)
		i_result		: UINT;			(* internal variable *)
        i_tmp			: UDINT;		(* internal variable *)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK CfgSetIPAddr
	VAR_INPUT
		enable			: BOOL;
		pDevice			: UDINT;
		pIPAddr			: UDINT;
		Option			: UDINT;
	END_VAR

	VAR_OUTPUT
		status			: UINT;
	END_VAR

	VAR
        i_state			: UINT;			(* internal variable *)
		i_result		: UINT;			(* internal variable *)
        i_tmp			: UDINT;		(* internal variable *)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK CfgGetSubnetMask
	VAR_INPUT
		enable			: BOOL;
		pDevice			: UDINT;
		pSubnetMask		: UDINT;
		Len				: USINT;
	END_VAR

	VAR_OUTPUT
		status			: UINT;
	END_VAR

	VAR
		i_state			: UINT;			(* internal variable *)
		i_result		: UINT;			(* internal variable *)
        i_tmp			: UDINT;		(* internal variable *)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK CfgSetSubnetMask
	VAR_INPUT
		enable			: BOOL;
		pDevice			: UDINT;
		pSubnetMask		: UDINT;
		Option			: UDINT;
	END_VAR

	VAR_OUTPUT
		status			: UINT;
	END_VAR

	VAR
        i_state			: UINT;			(* internal variable *)
		i_result		: UINT;			(* internal variable *)
        i_tmp			: UDINT;		(* internal variable *)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK CfgGetDefaultGateway
	VAR_INPUT
		enable			: BOOL;
		pDevice			: UDINT;
		pGateway		: UDINT;
		Len				: USINT;
	END_VAR

	VAR_OUTPUT
		status			: UINT;
	END_VAR

	VAR
        i_state			: UINT;			(* internal variable *)
		i_result		: UINT;			(* internal variable *)
        i_tmp			: UDINT;		(* internal variable *)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK CfgSetDefaultGateway
	VAR_INPUT
		enable			: BOOL;
		pDevice			: UDINT;
		pGateway		: UDINT;
		Option			: UDINT;
	END_VAR

	VAR_OUTPUT
		status			: UINT;
	END_VAR

	VAR
        i_state			: UINT;			(* internal variable *)
		i_result		: UINT;			(* internal variable *)
        i_tmp			: UDINT;		(* internal variable *)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK CfgGetBroadcastAddr
	VAR_INPUT
		enable			: BOOL;
		pDevice			: UDINT;
		pBroadcastAddr	: UDINT;
		Len				: USINT;
	END_VAR

	VAR_OUTPUT
		status			: UINT;
	END_VAR

	VAR
        i_state			: UINT;			(* internal variable *)
		i_result		: UINT;			(* internal variable *)
        i_tmp			: UDINT;		(* internal variable *)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK CfgSetBroadcastAddr
	VAR_INPUT
		enable			: BOOL;
		pDevice			: UDINT;
		pBroadcastAddr	: UDINT;
		Option			: UDINT;
	END_VAR

	VAR_OUTPUT
		status			: UINT;
	END_VAR

	VAR
        i_state			: UINT;			(* internal variable *)
		i_result		: UINT;			(* internal variable *)
        i_tmp			: UDINT;		(* internal variable *)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK CfgGetEthBaudrate
	VAR_INPUT
		enable			: BOOL;
		pDevice			: UDINT;
	END_VAR

	VAR_OUTPUT
		status			: UINT;
		Baudrate		: UDINT;
	END_VAR

	VAR
        i_state			: UINT;			(* internal variable *)
		i_result		: UINT;			(* internal variable *)
        i_tmp			: UDINT;		(* internal variable *)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK CfgSetEthBaudrate
	VAR_INPUT
		enable			: BOOL;
		pDevice			: UDINT;
		Baudrate		: UDINT;
		Option			: UDINT;
	END_VAR

	VAR_OUTPUT
		status			: UINT;
	END_VAR

	VAR
        i_state			: UINT;			(* internal variable *)
		i_result		: UINT;			(* internal variable *)
        i_tmp			: UDINT;		(* internal variable *)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK CfgGetEthConfigMode
	VAR_INPUT
		enable			: BOOL;
		pDevice			: UDINT;
	END_VAR

	VAR_OUTPUT
		status			: UINT;
		ConfigMode		: UDINT;
	END_VAR

	VAR
        i_state			: UINT;			(* internal variable *)
		i_result		: UINT;			(* internal variable *)
        i_tmp			: UDINT;		(* internal variable *)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK CfgSetEthConfigMode
	VAR_INPUT
		enable			: BOOL;
		pDevice			: UDINT;
		ConfigMode		: UDINT;
		Option			: UDINT;
	END_VAR

	VAR_OUTPUT
		status			: UINT;
	END_VAR

	VAR
        i_state			: UINT;			(* internal variable *)
		i_result		: UINT;			(* internal variable *)
        i_tmp			: UDINT;		(* internal variable *)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK CfgGetHostName
	VAR_INPUT
		enable			: BOOL;
		pHostName		: UDINT;
		Len				: USINT;
	END_VAR

	VAR_OUTPUT
		status			: UINT;
	END_VAR

	VAR
        i_state			: UINT;			(* internal variable *)
		i_result		: UINT;			(* internal variable *)
        i_tmp			: UDINT;		(* internal variable *)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK CfgSetHostName
	VAR_INPUT
		enable			: BOOL;
		pHostName		: UDINT;
		Option			: UDINT;
	END_VAR

	VAR_OUTPUT
		status			: UINT;
	END_VAR

	VAR
        i_state			: UINT;			(* internal variable *)
		i_result		: UINT;			(* internal variable *)
        i_tmp			: UDINT;		(* internal variable *)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK CfgGetMacAddr
	VAR_INPUT
		enable			: BOOL;			(* fub enable *)
		pDevice			: UDINT;		(* device name *)
		pMacAddr		: UDINT;		(* pointer to mac address *)
		Len				: USINT;		(* length of mac address *)
	END_VAR

	VAR_OUTPUT
		status			: UINT;
	END_VAR

	VAR
        i_state			: UINT;			(* internal variable *)
		i_result		: UINT;			(* internal variable *)
        i_tmp			: UDINT;		(* internal variable *)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK CfgSetFTPServer
	VAR_INPUT
		enable			: BOOL;
		Option			: UDINT;
	END_VAR

	VAR_OUTPUT
		status			: UINT;
	END_VAR

	VAR
        i_state			: UINT;			(* internal variable *)
		i_result		: UINT;			(* internal variable *)
        i_tmp			: UDINT;		(* internal variable *)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK CfgGetTimeOffset
	VAR_INPUT
		enable			: BOOL;
	END_VAR

	VAR_OUTPUT
		status			: UINT;
		timeoffset		: INT;
	END_VAR

	VAR
        i_state			: UINT;			(* internal variable *)
		i_result		: UINT;			(* internal variable *)
        i_tmp			: UDINT;		(* internal variable *)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK CfgSetTimeOffset
	VAR_INPUT
		enable			: BOOL;
        timeoffset		: INT;
        option			: UDINT;
	END_VAR

	VAR_OUTPUT
        status			: UINT;
	END_VAR

	VAR
        i_state			: UINT;			(* internal variable *)
		i_result		: UINT;			(* internal variable *)
        i_tmp			: UDINT;		(* internal variable *)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK CfgSetSntpServer
	VAR_INPUT
		enable			: BOOL;
        start			: UDINT;
        option			: UDINT;
	END_VAR

	VAR_OUTPUT
        status			: UINT;
	END_VAR

	VAR
        i_state			: UINT;			(* internal variable *)
		i_result		: UINT;			(* internal variable *)
        i_tmp			: UDINT;		(* internal variable *)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK CfgSetSntpClient
	VAR_INPUT
		enable			: BOOL;
		run				: UDINT;
		pServerAddr		: UDINT;
		sntpcInterval	: UINT;
		rtcInterval		: UINT;
		option			: UDINT;
	END_VAR

	VAR_OUTPUT
		status			: UINT;
		syncStatus		: USINT;
	END_VAR

	VAR
        i_state			: UINT;			(* internal variable *)
		i_result		: UINT;			(* internal variable *)
        i_tmp			: UDINT;		(* internal variable *)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK CfgGetSntpcData
	VAR_INPUT
		enable			: BOOL;
	END_VAR

	VAR_OUTPUT
		status			: UINT;
		run				: UDINT;
        pServerAddr		: UDINT;
        sntpcInterval	: UINT;
        rtcInterval		: UINT;
	END_VAR

	VAR
        i_state			: UINT;			(* internal variable *)
		i_result		: UINT;			(* internal variable *)
        i_tmp			: UDINT;		(* internal variable *)
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK CfgGetSntpsData
	VAR_INPUT
		enable			: BOOL;
	END_VAR

	VAR_OUTPUT
		status			: UINT;
		run				: UDINT;
	END_VAR

	VAR
        i_state			: UINT;			(* internal variable *)
		i_result		: UINT;			(* internal variable *)
        i_tmp			: UDINT;		(* internal variable *)
	END_VAR
END_FUNCTION_BLOCK

