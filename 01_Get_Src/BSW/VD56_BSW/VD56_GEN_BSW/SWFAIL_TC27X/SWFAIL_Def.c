/******************************************************************************/
/* !Layer           : SRVL                                                    */
/* !Component       : SWFAIL                                                  */
/* !Description     : Software Failure Management                             */
/*                                                                            */
/* !File            : SWFAIL_DEF.c                                            */
/* !Description     : Data Definition  of SWFAIL Component                    */
/*                                                                            */
/* !Reference       : PTS_DOC_5417247                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: LIBEMB:A1715.A-SRC;4 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/
#include "Std_types.h"
#include "SWFAIL_types.h"
#include "SWFAIL.h"


/******************************************************************************/
/* CALIBRATIONS DEFINITION                                                    */
/******************************************************************************/


/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define SWFAIL_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
#include "SWFAIL_MemMap.h"
VAR(void *, SWFAIL_VAR) SWFAIL_pfErrorAddress;
VAR(SWFAIL_tudtStackIdxType, SWFAIL_VAR) SWFAIL_udtStackIdx;
VAR(SWFAIL_tbfErrorType, SWFAIL_VAR) SWFAIL_bfErrorType;
VAR(SWFAIL_tbfErrorType, SWFAIL_VAR) SWFAIL_bfTrapType;
#define SWFAIL_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
#include "SWFAIL_MemMap.h"

#define SWFAIL_START_SEC_VAR_POWER_ON_CLEARED_8BIT
#include "SWFAIL_MemMap.h"
VAR(uint8, SWFAIL_VAR) SWFAIL_u8CoreIdx;
#define SWFAIL_STOP_SEC_VAR_POWER_ON_CLEARED_8BIT
#include "SWFAIL_MemMap.h"

#define SWFAIL_START_SEC_VAR_POWER_ON_CLEARED_16BIT
#include "SWFAIL_MemMap.h"
VAR(uint16, SWFAIL_VAR) SWFAIL_u16ExceptionErrorCounter;
VAR(uint16, SWFAIL_VAR) SWFAIL_u16SoftwareErrorCounter;
VAR(uint16, SWFAIL_VAR) SWFAIL_u16StackErrorCounter;
#define SWFAIL_STOP_SEC_VAR_POWER_ON_CLEARED_16BIT
#include "SWFAIL_MemMap.h"

#define SWFAIL_START_SEC_VAR_POWER_ON_CLEARED_32BIT
#include "SWFAIL_MemMap.h"
VAR(uint32, SWFAIL_VAR) SWFAIL_audtSaveContext[SWFAIL_u8SAVE_CONTEXT_ARRAY_SIZE] = {0};
VAR(uint32, SWFAIL_VAR) SWFAIL_pfu32IllegalInstruction;
VAR(uint32, SWFAIL_VAR) SWFAIL_pfu32ProgramReturnError;
VAR(uint32, SWFAIL_VAR) SWFAIL_u32StatusRegisterError;
#define SWFAIL_STOP_SEC_VAR_POWER_ON_CLEARED_32BIT
#include "SWFAIL_MemMap.h"

/*------------------------------ end of file ---------------------------------*/
