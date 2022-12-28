/******************************************************************************/
/* !Layer           : SRVL                                                    */
/* !Component       : SWFAIL                                                  */
/* !Description     : Software Failure Management                             */
/*                                                                            */
/* !File            : SWFAIL.h                                                */
/* !Description     : API of the SWFAIL Component                             */
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
 * %PID: LIBEMB:A1717.A-SRC;4 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef SWFAIL_H
#define SWFAIL_H

#include "SWFAIL_Private.h"
#include "SWFAIL_Types.h"

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
#define SWFAIL_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
#include "SWFAIL_MemMap.h"
extern VAR(void *, SWFAIL_VAR) SWFAIL_pfErrorAddress;
extern VAR(SWFAIL_tbfErrorType, SWFAIL_VAR) SWFAIL_bfErrorType;
extern VAR(SWFAIL_tbfErrorType, SWFAIL_VAR) SWFAIL_bfTrapType;
extern VAR(SWFAIL_tudtStackIdxType, SWFAIL_VAR) SWFAIL_udtStackIdx;
#define SWFAIL_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
#include "SWFAIL_MemMap.h"

#define SWFAIL_START_SEC_VAR_POWER_ON_CLEARED_8BIT
#include "SWFAIL_MemMap.h"
extern VAR(uint8, SWFAIL_VAR) SWFAIL_u8CoreIdx;
#define SWFAIL_STOP_SEC_VAR_POWER_ON_CLEARED_8BIT
#include "SWFAIL_MemMap.h"

#define SWFAIL_START_SEC_VAR_POWER_ON_CLEARED_16BIT
#include "SWFAIL_MemMap.h"
extern VAR(uint16, SWFAIL_VAR) SWFAIL_u16ExceptionErrorCounter;
extern VAR(uint16, SWFAIL_VAR) SWFAIL_u16SoftwareErrorCounter;
extern VAR(uint16, SWFAIL_VAR) SWFAIL_u16StackErrorCounter;
#define SWFAIL_STOP_SEC_VAR_POWER_ON_CLEARED_16BIT
#include "SWFAIL_MemMap.h"

#define SWFAIL_START_SEC_VAR_POWER_ON_CLEARED_32BIT
#include "SWFAIL_MemMap.h"
extern VAR(uint32, SWFAIL_VAR) SWFAIL_audtSaveContext[SWFAIL_u8SAVE_CONTEXT_ARRAY_SIZE];
extern VAR(uint32, SWFAIL_VAR) SWFAIL_pfu32IllegalInstruction;
extern VAR(uint32, SWFAIL_VAR) SWFAIL_pfu32ProgramReturnError;
extern VAR(uint32, SWFAIL_VAR) SWFAIL_u32StatusRegisterError;
#define SWFAIL_STOP_SEC_VAR_POWER_ON_CLEARED_32BIT
#include "SWFAIL_MemMap.h"


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* !FuncName    : SWFAIL_vidSoftwareErrorHook                                 */
/* !Description : Software error process                                      */
/*                                                                            */
/* !Trace_To    : VEES_R_06_02985_007.01                                      */
/* !Trace_To    : VEES_R_06_02985_008.01                                      */
/* !Trace_To    : VEES_R_06_02985_009.01                                      */
/*                                                                            */
/* !LastAuthor  :  J.Bekaert                                                  */
/******************************************************************************/

#define SWFAIL_vidSoftwareErrorHook() \
   SWFAIL_vidSOFTWARE_ERROR_HOOK_I()

/******************************************************************************/
/* !FuncName    : SWFAIL_u16Read                                              */
/* !Description : Returns the number of errors of snChannel type              */
/*                                                                            */
/* !Trace_To    : VEES_R_06_02985_010.01                                      */
/*                                                                            */
/* !LastAuthor  :  J.Bekaert                                                  */
/******************************************************************************/

#define SWFAIL_u16Read( \
\
   snChannel            /* !Comment : Error identification                  */ \
                        /* !Range   : SWFAIL_u8STACK_ERROR,                 */ \
                        /*            SWFAIL_u8EXCEPTIONS_ERROR,            */ \
                        /*            SWFAIL_u8SOFTWARE_ERROR               */ \
) \
   SWFAIL_u16READ_I(snChannel)

/******************************************************************************/
/* !FuncName    : SWFAIL_pfvidReadErrorAddress                                */
/* !Description : Returns the address of opcode being executed when last      */
/*                exception appeared                                          */
/*                                                                            */
/* !Trace_To    : VEES_R_06_02985_011.01                                      */
/*                                                                            */
/* !LastAuthor  :  J.Bekaert                                                  */
/******************************************************************************/

#define SWFAIL_pfvidReadErrorAddress() \
   SWFAIL_pfvidREAD_ERROR_ADDRESS_I()

/******************************************************************************/
/* !FuncName    : SWFAIL_bfReadErrorType                                      */
/* !Description : Returns the bitfield value of error type                    */
/*                                                                            */
/* !Trace_To    : VEES_R_06_02985_012.01                                      */
/*                                                                            */
/* !LastAuthor  :  J.Bekaert                                                  */
/******************************************************************************/

#define SWFAIL_bfReadErrorType() \
   SWFAIL_bfREAD_ERROR_TYPE_I()


/******************************************************************************/
/* !FuncName    : SWFAIL_vidStackOverflowHook                                 */
/* !Description : Stack overflow error process                                */
/*                                                                            */
/* !Trace_To    : VEES_R_06_02985_016.01                                      */
/* !Trace_To    : VEES_R_06_02985_017.01                                      */
/* !Trace_To    : VEES_R_06_02985_018.01                                      */
/*                                                                            */
/* !LastAuthor  :  J.Bekaert                                                  */
/******************************************************************************/

#define SWFAIL_vidStackOverflowHook(udtStackIdx) \
   SWFAIL_vidSTACK_OVERFLOW_HOOK_I(udtStackIdx)

/******************************************************************************/
/* !FuncName    : SWFAIL_vidStackUnderflowHook                                */
/* !Description : Stack underflow error process                               */
/*                                                                            */
/* !Trace_To    : VEES_R_06_02985_019.01                                      */
/* !Trace_To    : VEES_R_06_02985_020.01                                      */
/* !Trace_To    : VEES_R_06_02985_021.01                                      */
/*                                                                            */
/* !LastAuthor  :  J.Bekaert                                                  */
/******************************************************************************/

#define SWFAIL_vidStackUnderflowHook(udtStackIdx) \
   SWFAIL_vidSTACK_UNDERFLOW_HOOK_I(udtStackIdx)

/******************************************************************************/
/* !FuncName    : SWFAIL_udtReadStackIdx                                      */
/* !Description : Returns last stack error index                              */
/*                                                                            */
/* !Trace_To    : VEES_R_06_02985_022.01                                      */
/*                                                                            */
/* !LastAuthor  :  J.Bekaert                                                  */
/******************************************************************************/

#define SWFAIL_udtReadStackIdx() \
   SWFAIL_udtREAD_STACK_IDX_I()


/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define SWFAIL_START_SEC_CODE
#include "SWFAIL_MemMap.h"

extern void SWFAIL_vidInit(void);
extern void SWFAIL_vidErase(void);

#define SWFAIL_STOP_SEC_CODE
#include "SWFAIL_MemMap.h"


#endif /* SWFAIL_H */

/*------------------------------ end of file ---------------------------------*/

