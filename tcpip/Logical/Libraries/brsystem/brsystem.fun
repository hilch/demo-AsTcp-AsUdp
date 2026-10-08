                                                                      
{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK MEMxInfo				(*returns information about the memory areas available in the system; asynchronous execution*)
	VAR_INPUT
		enable	:BOOL;   			(*enables execution*)
		mem_typ	:UDINT;				(*memory type: brDRAM, brUSRRAM, brSYSROM, brUSRROM*)
	END_VAR
	VAR_OUTPUT
		status	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		MemSize	:UDINT;				(*total memory size in bytes*)
		FreeMemSize	:UDINT;			(*size of available memory in bytes*)
		BiggestFreeBlockSize	:UDINT;	(*size of the largest available block in memory in bytes*)
	END_VAR
	VAR
		i_state	:UINT;				(*internal variable*)
		i_result	:UINT;			(*internal variable*)
		i_tmp	:UDINT;				(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK SysInfo				(*returns information about the target system*)
	VAR_INPUT
		enable	:BOOL;				(*enables execution*)
	END_VAR
	VAR_OUTPUT
		init_reason	:USINT;			(*reason for initialization*)
		init_count	:USINT;			(*not used, always 0*)
		tick_count	:UDINT;			(*tick count*)
		version	:UDINT;				(*not used, always 0*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK RTInfo				(*returns runtime information about the program*)
	VAR_INPUT
		enable	:BOOL;				(*enables execution*)
	END_VAR
	VAR_OUTPUT
		status	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		cycle_time	:UDINT;			(*cycle time in microsec*)
		init_reason	:SINT;			(*reason for initialization*)
		task_class	:SINT;			(*task class (#1 - #8)*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK TARGETInfo			(*returns information about the target system used*)
	VAR_INPUT
		enable	:BOOL;				(*enables execution*)
		pOSVersion	:UDINT;			(*not used*)
	END_VAR
	VAR_OUTPUT
		status	:UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		DataFormat	:USINT;			(*wether "big endian" or "little endian" ("TARGET_BIG_ENDIAN"/"TARGET_LITTLE_ENDIAN")*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} FUNCTION RTTolerance : UDINT (*returns the tolerance [microsec] of the programs task class*)
END_FUNCTION

{REDUND_OK} FUNCTION RTCyclic : BOOL (*returns true, if function is called in the cyclic part of the program, false otherwise*)
END_FUNCTION

{REDUND_OK} FUNCTION RTInit : BOOL (*returns true, if function is called in the init part of the program, false otherwise*)
END_FUNCTION

{REDUND_OK} FUNCTION RTExit : BOOL (*returns true, if function is called in the exit part of the program, false otherwise*)
END_FUNCTION

{REDUND_OK} FUNCTION OSVersionMajor : UDINT (*returns the major number of the operating system version*)
END_FUNCTION

{REDUND_OK} FUNCTION OSVersionMinor : UDINT (*returns the minor number of the operating system version*)
END_FUNCTION

{REDUND_OK} FUNCTION OSVersionPatch : UDINT (*returns the patch number of the operating system version*)
END_FUNCTION

{REDUND_OK} FUNCTION OSVersionBuild : UDINT (*returns the build number of the operating system version*)
END_FUNCTION

{REDUND_OK} FUNCTION RTCycleTime	: UDINT (*returns the cycle time [microsec] of the task class*)
	VAR_INPUT
		task_class	: SINT;			(*task class (#1 - #8)*)
	END_VAR
END_FUNCTION

{REDUND_OK} FUNCTION RTCylceTime	: UDINT (*OBSOLETE (only for compatibility reasons) - use RTCycleTime*)
	VAR_INPUT
		task_class	: SINT;			(*task class (#1 - #8)*)
	END_VAR
END_FUNCTION
 