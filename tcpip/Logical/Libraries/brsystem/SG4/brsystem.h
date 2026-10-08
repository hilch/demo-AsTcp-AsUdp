/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BRSYSTEM_
#define _BRSYSTEM_
#ifdef __cplusplus
extern "C" 
{
#endif

#include <bur/plctypes.h>

#include <runtime.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
/* Datatypes and datatypes of function blocks */
typedef struct MEMxInfo
{
	/* VAR_INPUT (analog) */
	unsigned long mem_typ;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long MemSize;
	unsigned long FreeMemSize;
	unsigned long BiggestFreeBlockSize;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} MEMxInfo_typ;

typedef struct SysInfo
{
	/* VAR_OUTPUT (analog) */
	unsigned char init_reason;
	unsigned char init_count;
	unsigned long tick_count;
	unsigned long version;
	/* VAR_INPUT (digital) */
	plcbit enable;
} SysInfo_typ;

typedef struct RTInfo
{
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long cycle_time;
	signed char init_reason;
	signed char task_class;
	/* VAR_INPUT (digital) */
	plcbit enable;
} RTInfo_typ;

typedef struct TARGETInfo
{
	/* VAR_INPUT (analog) */
	unsigned long pOSVersion;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned char DataFormat;
	/* VAR_INPUT (digital) */
	plcbit enable;
} TARGETInfo_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void MEMxInfo(struct MEMxInfo* inst);
_BUR_PUBLIC void SysInfo(struct SysInfo* inst);
_BUR_PUBLIC void RTInfo(struct RTInfo* inst);
_BUR_PUBLIC void TARGETInfo(struct TARGETInfo* inst);
_BUR_PUBLIC unsigned long RTTolerance(void);
_BUR_PUBLIC plcbit RTCyclic(void);
_BUR_PUBLIC plcbit RTInit(void);
_BUR_PUBLIC plcbit RTExit(void);
_BUR_PUBLIC unsigned long OSVersionMajor(void);
_BUR_PUBLIC unsigned long OSVersionMinor(void);
_BUR_PUBLIC unsigned long OSVersionPatch(void);
_BUR_PUBLIC unsigned long OSVersionBuild(void);
_BUR_PUBLIC unsigned long RTCycleTime(signed char task_class);
_BUR_PUBLIC unsigned long RTCylceTime(signed char task_class);


/* Constants */
#ifdef _REPLACE_CONST
 #define brERR_NON_CYCLIC_CONTEXT 27252U
 #define brERR_INVALID_PARAMETER 27251U
 #define brGLOBAL_REMANENT_PV 5U
 #define brLOCAL_REMANENT_PV 4U
 #define brUSRROM 3U
 #define brSYSROM 2U
 #define brUSRRAM 1U
 #define brDRAM 0U
 #define TARGET_BIG_ENDIAN 2U
 #define TARGET_LITTLE_ENDIAN 1U
 #define INIT_REASON_UNKNOWN (-1)
 #define INIT_REASON_DOWNLOAD 3
 #define INIT_REASON_COLDSTART 2
 #define INIT_REASON_WARMSTART 1
#else
 _GLOBAL_CONST unsigned short brERR_NON_CYCLIC_CONTEXT;
 _GLOBAL_CONST unsigned short brERR_INVALID_PARAMETER;
 _GLOBAL_CONST unsigned long brGLOBAL_REMANENT_PV;
 _GLOBAL_CONST unsigned long brLOCAL_REMANENT_PV;
 _GLOBAL_CONST unsigned long brUSRROM;
 _GLOBAL_CONST unsigned long brSYSROM;
 _GLOBAL_CONST unsigned long brUSRRAM;
 _GLOBAL_CONST unsigned long brDRAM;
 _GLOBAL_CONST unsigned char TARGET_BIG_ENDIAN;
 _GLOBAL_CONST unsigned char TARGET_LITTLE_ENDIAN;
 _GLOBAL_CONST signed char INIT_REASON_UNKNOWN;
 _GLOBAL_CONST signed char INIT_REASON_DOWNLOAD;
 _GLOBAL_CONST signed char INIT_REASON_COLDSTART;
 _GLOBAL_CONST signed char INIT_REASON_WARMSTART;
#endif




#ifdef __cplusplus
};
#endif
#endif /* _BRSYSTEM_ */

