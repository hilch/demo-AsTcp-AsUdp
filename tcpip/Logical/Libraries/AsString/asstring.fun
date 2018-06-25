(********************************************************************
 * COPYRIGHT (C) BERNECKER + RAINER, AUSTRIA, A-5142 EGGELSBERG
 ********************************************************************
 * Library: AsString
 * File: AsString.fun
 * Created: 11.11.2003
 ********************************************************************
 * Functions and function blocks of library AsString
 ********************************************************************)
FUNCTION ftoa : UINT		(*converts a REAL value into a character string*)
	VAR_INPUT
		value	:REAL;		(*REAL (FLOAT) value to be converted into a character string*)
		pString	:UDINT;		(*pointer to the destination character string*)
	END_VAR
END_FUNCTION
FUNCTION atof : REAL		(*converts a character string into a REAL (FLOAT) value*)
	VAR_INPUT
		pString	:UDINT;		(*pointer to the character string to be converted*)
	END_VAR
END_FUNCTION
FUNCTION itoa : UINT		(*converts a DINT value into a character string*)
	VAR_INPUT
		value	:DINT;		(*numerical value to be converted into a string*)
		pString	:UDINT;		(*pointer to the destination character string*)
	END_VAR
END_FUNCTION
FUNCTION atoi : DINT		(*converts a character string into a DINT value*)
	VAR_INPUT
		pString	:UDINT;		(*pointer to the character string to be converted*)
	END_VAR
END_FUNCTION
FUNCTION memset : UDINT		(*fills the memory area with specific values*)
	VAR_INPUT
		pDest	:UDINT;		(*pointer to the destination memory*)
		value	:USINT;		(*initialization value*)
		length	:UDINT;		(*number of bytes to be initialized*)
	END_VAR
END_FUNCTION
FUNCTION memcpy : UDINT		(*copies the memory area*)
	VAR_INPUT
		pDest	:UDINT;		(*pointer to the destination memory*)
		pSrc	:UDINT;		(*pointer to the data to be copied*)
		length	:UDINT;		(*size of bytes to be copied*)
	END_VAR
END_FUNCTION
FUNCTION memmove : UDINT	(*copies the memory area (even if the memory areas overlap)*)
	VAR_INPUT
		pDest	:UDINT;		(*pointer to the destination memory*)
		pSrc	:UDINT;		(*pointer to the data to be copied*)
		length	:UDINT;		(*size of bytes to be copied*)
	END_VAR
END_FUNCTION
FUNCTION memcmp : DINT		(*compares memory areas*)
	VAR_INPUT
		pMem1	:UDINT;		(*pointer to the memory area 1*)
		pMem2	:UDINT;		(*pointer to the memory area 2*)
		length	:UDINT;		(*size of bytes to be checked*)
	END_VAR
END_FUNCTION
FUNCTION strcat : UDINT		(*attaches character strings to one another*)
	VAR_INPUT
		pDest	:UDINT;		(*pointer to the destination character string*)
		pSrc	:UDINT;		(*pointer to the source character string*)
	END_VAR
END_FUNCTION
FUNCTION strlen : UINT		(*provides the length of a character string*)
	VAR_INPUT
		pString	:UDINT;		(*pointer to the source character string*)
	END_VAR
END_FUNCTION
FUNCTION strcpy : UDINT		(*copies one character string into another*)
	VAR_INPUT
		pDest	:UDINT;		(*pointer to the destination character string*)
		pSrc	:UDINT;		(*pointer to the source character string*)
	END_VAR
END_FUNCTION
FUNCTION strcmp : DINT		(*compares two character strings*)
	VAR_INPUT
		pString1	:UDINT;	(*pointer to the first character string*)
		pString2	:UDINT;	(*pointer to the second character string*)
	END_VAR
END_FUNCTION
