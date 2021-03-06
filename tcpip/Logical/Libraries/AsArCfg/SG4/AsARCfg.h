/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _ASARCFG_
#define _ASARCFG_

#include <bur/plctypes.h>

#ifndef _IEC_CONST
#define _IEC_CONST _WEAK const
#endif

/* Constants */
#ifdef _REPLACE_CONST
 #define cfgOPTION_ENABLE 1U
 #define cfgOPTION_DISABLE 0U
 #define cfgCONFIGMODE_DHCPCLIENT 1U
 #define cfgCONFIGMODE_MANUALLY 0U
 #define cfgOPTION_VOLATILE 0U
 #define cfgOPTION_NON_VOLATILE 1U
 #define cfgETHBAUDRATE_100FD 101U
 #define cfgETHBAUDRATE_100 100U
 #define cfgETHBAUDRATE_10FD 11U
 #define cfgETHBAUDRATE_10 10U
 #define cfgETHBAUDRATE_AUTO 0U
 #define cfgERR_SYSTEM 29013U
 #define cfgERR_SNTP_INTERVAL 29012U
 #define cfgERR_SNTP_CLIENT 29011U
 #define cfgERR_SNTP_SERVER 29010U
 #define cfgERR_PARAM_NOT_SET 29009U
 #define cfgERR_FTP_SDOWN 29008U
 #define cfgERR_FTP_SINIT 29007U
 #define cfgERR_INANODE_NOT_SUPPORTED 29006U
 #define cfgERR_ARREG 29005U
 #define cfgERR_SET_NOT_POSSIBLE 29004U
 #define cfgERR_VALUE_INVALID 29003U
 #define cfgERR_OPTION_INVALID 29002U
 #define cfgERR_DEVICE_INVALID 29001U
 #define cfgERR_DEVICE_NOT_EXIST 29000U
#else
 _IEC_CONST unsigned long cfgOPTION_ENABLE = 1U;
 _IEC_CONST unsigned long cfgOPTION_DISABLE = 0U;
 _IEC_CONST unsigned long cfgCONFIGMODE_DHCPCLIENT = 1U;
 _IEC_CONST unsigned long cfgCONFIGMODE_MANUALLY = 0U;
 _IEC_CONST unsigned long cfgOPTION_VOLATILE = 0U;
 _IEC_CONST unsigned long cfgOPTION_NON_VOLATILE = 1U;
 _IEC_CONST unsigned long cfgETHBAUDRATE_100FD = 101U;
 _IEC_CONST unsigned long cfgETHBAUDRATE_100 = 100U;
 _IEC_CONST unsigned long cfgETHBAUDRATE_10FD = 11U;
 _IEC_CONST unsigned long cfgETHBAUDRATE_10 = 10U;
 _IEC_CONST unsigned long cfgETHBAUDRATE_AUTO = 0U;
 _IEC_CONST unsigned short cfgERR_SYSTEM = 29013U;
 _IEC_CONST unsigned short cfgERR_SNTP_INTERVAL = 29012U;
 _IEC_CONST unsigned short cfgERR_SNTP_CLIENT = 29011U;
 _IEC_CONST unsigned short cfgERR_SNTP_SERVER = 29010U;
 _IEC_CONST unsigned short cfgERR_PARAM_NOT_SET = 29009U;
 _IEC_CONST unsigned short cfgERR_FTP_SDOWN = 29008U;
 _IEC_CONST unsigned short cfgERR_FTP_SINIT = 29007U;
 _IEC_CONST unsigned short cfgERR_INANODE_NOT_SUPPORTED = 29006U;
 _IEC_CONST unsigned short cfgERR_ARREG = 29005U;
 _IEC_CONST unsigned short cfgERR_SET_NOT_POSSIBLE = 29004U;
 _IEC_CONST unsigned short cfgERR_VALUE_INVALID = 29003U;
 _IEC_CONST unsigned short cfgERR_OPTION_INVALID = 29002U;
 _IEC_CONST unsigned short cfgERR_DEVICE_INVALID = 29001U;
 _IEC_CONST unsigned short cfgERR_DEVICE_NOT_EXIST = 29000U;
#endif


/* Variables */


/* Datatypes and datatypes of function blocks */
typedef struct CfgGetInaNode
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned char InaNode;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CfgGetInaNode_typ;

typedef struct CfgSetInaNode
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned char InaNode;
	unsigned long Option;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CfgSetInaNode_typ;

typedef struct CfgGetIPAddr
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned long pIPAddr;
	unsigned char Len;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CfgGetIPAddr_typ;

typedef struct CfgSetIPAddr
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned long pIPAddr;
	unsigned long Option;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CfgSetIPAddr_typ;

typedef struct CfgGetSubnetMask
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned long pSubnetMask;
	unsigned char Len;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CfgGetSubnetMask_typ;

typedef struct CfgSetSubnetMask
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned long pSubnetMask;
	unsigned long Option;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CfgSetSubnetMask_typ;

typedef struct CfgGetDefaultGateway
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned long pGateway;
	unsigned char Len;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CfgGetDefaultGateway_typ;

typedef struct CfgSetDefaultGateway
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned long pGateway;
	unsigned long Option;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CfgSetDefaultGateway_typ;

typedef struct CfgGetBroadcastAddr
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned long pBroadcastAddr;
	unsigned char Len;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CfgGetBroadcastAddr_typ;

typedef struct CfgSetBroadcastAddr
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned long pBroadcastAddr;
	unsigned long Option;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CfgSetBroadcastAddr_typ;

typedef struct CfgGetEthBaudrate
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long Baudrate;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CfgGetEthBaudrate_typ;

typedef struct CfgSetEthBaudrate
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned long Baudrate;
	unsigned long Option;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CfgSetEthBaudrate_typ;

typedef struct CfgGetEthConfigMode
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long ConfigMode;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CfgGetEthConfigMode_typ;

typedef struct CfgSetEthConfigMode
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned long ConfigMode;
	unsigned long Option;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CfgSetEthConfigMode_typ;

typedef struct CfgGetHostName
{
	/* VAR_INPUT (analog) */
	unsigned long pHostName;
	unsigned char Len;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CfgGetHostName_typ;

typedef struct CfgSetHostName
{
	/* VAR_INPUT (analog) */
	unsigned long pHostName;
	unsigned long Option;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CfgSetHostName_typ;

typedef struct CfgGetMacAddr
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned long pMacAddr;
	unsigned char Len;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CfgGetMacAddr_typ;

typedef struct CfgSetFTPServer
{
	/* VAR_INPUT (analog) */
	unsigned long Option;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CfgSetFTPServer_typ;

typedef struct CfgGetTimeOffset
{
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	signed short timeoffset;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CfgGetTimeOffset_typ;

typedef struct CfgSetTimeOffset
{
	/* VAR_INPUT (analog) */
	signed short timeoffset;
	unsigned long option;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CfgSetTimeOffset_typ;

typedef struct CfgSetSntpServer
{
	/* VAR_INPUT (analog) */
	unsigned long start;
	unsigned long option;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CfgSetSntpServer_typ;

typedef struct CfgSetSntpClient
{
	/* VAR_INPUT (analog) */
	unsigned long run;
	unsigned long pServerAddr;
	unsigned short sntpcInterval;
	unsigned short rtcInterval;
	unsigned long option;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned char syncStatus;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CfgSetSntpClient_typ;

typedef struct CfgGetSntpcData
{
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long run;
	unsigned long pServerAddr;
	unsigned short sntpcInterval;
	unsigned short rtcInterval;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CfgGetSntpcData_typ;

typedef struct CfgGetSntpsData
{
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long run;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} CfgGetSntpsData_typ;



/* Prototyping of functions and function blocks */
void CfgGetInaNode(struct CfgGetInaNode* inst);
void CfgSetInaNode(struct CfgSetInaNode* inst);
void CfgGetIPAddr(struct CfgGetIPAddr* inst);
void CfgSetIPAddr(struct CfgSetIPAddr* inst);
void CfgGetSubnetMask(struct CfgGetSubnetMask* inst);
void CfgSetSubnetMask(struct CfgSetSubnetMask* inst);
void CfgGetDefaultGateway(struct CfgGetDefaultGateway* inst);
void CfgSetDefaultGateway(struct CfgSetDefaultGateway* inst);
void CfgGetBroadcastAddr(struct CfgGetBroadcastAddr* inst);
void CfgSetBroadcastAddr(struct CfgSetBroadcastAddr* inst);
void CfgGetEthBaudrate(struct CfgGetEthBaudrate* inst);
void CfgSetEthBaudrate(struct CfgSetEthBaudrate* inst);
void CfgGetEthConfigMode(struct CfgGetEthConfigMode* inst);
void CfgSetEthConfigMode(struct CfgSetEthConfigMode* inst);
void CfgGetHostName(struct CfgGetHostName* inst);
void CfgSetHostName(struct CfgSetHostName* inst);
void CfgGetMacAddr(struct CfgGetMacAddr* inst);
void CfgSetFTPServer(struct CfgSetFTPServer* inst);
void CfgGetTimeOffset(struct CfgGetTimeOffset* inst);
void CfgSetTimeOffset(struct CfgSetTimeOffset* inst);
void CfgSetSntpServer(struct CfgSetSntpServer* inst);
void CfgSetSntpClient(struct CfgSetSntpClient* inst);
void CfgGetSntpcData(struct CfgGetSntpcData* inst);
void CfgGetSntpsData(struct CfgGetSntpsData* inst);



#endif /* _ASARCFG_ */

