/******************************************************************************/
/* !Layer           : SRVL                                                    */
/* !Component       : SWFAIL                                                  */
/* !Description     : Software Failure Management                             */
/*                                                                            */
/* !File            : SWFAIL_Private.h                                        */
/* !Description     : Software Failure Management                             */
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
 * %PID: LIBEMB:A1718.A-SRC;3 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/
#ifndef SWFAIL_PRIVATE_H
#define SWFAIL_PRIVATE_H

#include "STD_TYPES.h"
#include "SWFAIL_Types.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* !Comment: Size of the SWFAIL_audtSaveContext table                         */
#define SWFAIL_u8SAVE_CONTEXT_ARRAY_SIZE          32u

/* !Comment: Error counters associated to each snChannel                      */
#define SWFAIL_u8STACK_ERROR_CNT                  SWFAIL_u16StackErrorCounter
#define SWFAIL_u8EXCEPTIONS_ERROR_CNT             SWFAIL_u16ExceptionErrorCounter
#define SWFAIL_u8SOFTWARE_ERROR_CNT               SWFAIL_u16SoftwareErrorCounter

/* !Comment: Defect codes definition for SWFAIL_bfErrorType Bit field         */
#define SWFAIL_bfSOFTWARE_ERROR                   0x00000001u
#define SWFAIL_bfMANUAL_RESET                     0x00000002u
#define SWFAIL_bfTRAP_DETECTION                   0x00000004u
#define SWFAIL_bfSTACK_OVERFLOW                   0x00000008u
#define SWFAIL_bfSTACK_UNDERFLOW                  0x00000010u
#define SWFAIL_bfCSA_OVERFLOW                     0x00000020u
#define SWFAIL_bfCSA_UNDERFLOW                    0x00000040u

/* !Comment: Defect codes definition for SWFAIL_bfTrapType Bit field          */
/*Trap 0*/
#define SWFAIL_bfTRAP_VIRTUAL_ADDR_FILL           0x00000001u
#define SWFAIL_bfTRAP_VIRTUAL_ADDR_PROTECTION     0x00000002u
/*Trap 1*/
#define SWFAIL_bfTRAP_PRIVILEGED_INSTRUCTION      0x00000004u
#define SWFAIL_bfTRAP_MEM_PROTECTION_R            0x00000008u
#define SWFAIL_bfTRAP_MEM_PROTECTION_W            0x00000010u
#define SWFAIL_bfTRAP_MEM_PROTECTION_EX           0x00000020u
#define SWFAIL_bfTRAP_MEM_PROTECT_PERIPH_ACCESS   0x00000040u
#define SWFAIL_bfTRAP_MEM_PROTECT_NULL_ADDR       0x00000080u
#define SWFAIL_bfTRAP_GLOBAL_REG_PROTECTION_W     0x00000100u
/*Trap 2*/
#define SWFAIL_bfTRAP_ILLEGAL_OPCODE              0x00000200u
#define SWFAIL_bfTRAP_UNIMPLEMENTED_OPCODE        0x00000400u
#define SWFAIL_bfTRAP_INVALID_OPERANDE            0x00000800u
#define SWFAIL_bfTRAP_DATA_ADDR_ALIGNEMENT        0x00001000u
#define SWFAIL_bfTRAP_INVALID_LOCAL_MEM_ADDR      0x00002000u
/*Trap 3*/
#define SWFAIL_bfTRAP_FREE_CTX_LIST_DEPLETION     0x00004000u
#define SWFAIL_bfTRAP_CALL_DEPTH_OVERFLOW         0x00008000u
#define SWFAIL_bfTRAP_CALL_DEPTH_UNDERFLOW        0x00010000u
#define SWFAIL_bfTRAP_FREE_CTX_LIST_UNDERFLOW     0x00020000u
#define SWFAIL_bfTRAP_TRAP_STACK_UNDERFLOW        0x00040000u
#define SWFAIL_bfTRAP_CTX_TYPE                    0x00080000u
#define SWFAIL_bfTRAP_NESTING_ERROR               0x00100000u
/*Trap 4*/
#define SWFAIL_bfTRAP_PROGRAM_FETCH_SYNC_ERROR    0x00200000u
#define SWFAIL_bfTRAP_DATA_ACCESS_SYNC_ERROR      0x00400000u
#define SWFAIL_bfTRAP_DATA_ACCESS_ASYNC_ERROR     0x00800000u
#define SWFAIL_bfTRAP_COPRO_TRAP_ASYNC_ERROR      0x01000000u
#define SWFAIL_bfTRAP_PROGRAM_MEM_INTEGRITY_ERROR 0x02000000u
#define SWFAIL_bfTRAP_DATA_MEM_INTEGRITY_ERROR    0x04000000u
#define SWFAIL_bfTRAP_TEMPORAL_ASYNCHRONOUS_ERROR 0x08000000u
/*Trap 5*/
#define SWFAIL_bfTRAP_ARITHMETIC_OVERFLOW         0x10000000u
#define SWFAIL_bfTRAP_STICKY_ARITHMETIC_OVERFLOW  0x20000000u
/*Trap 6*/
#define SWFAIL_bfTRAP_SYSTEM_CALL                 0x40000000u
/*Trap 7*/
#define SWFAIL_bfTRAP_NON_MASKABLE_INTERRUPT      0x80000000u

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

#define __ALIGN_TRAP_TAB__  __asm(" .align 5");
#define SWFAIL_vidFILL_TRAP_VECT(vidServiceRoutine) { \
    __asm ("ji\t %0": :"a" (vidServiceRoutine)); \
    __asm ("rfe"); \
    __ALIGN_TRAP_TAB__; \
}

/******************************************************************************/
/* Public services                                                            */
/******************************************************************************/

/******************************************************************************/
/* !FuncName    : SWFAIL_vidSOFTWARE_ERROR_HOOK_I                             */
/* !Description : Software error process                                      */
/*                                                                            */
/* !Trace_To    : VEES_R_06_02985_007.01                                      */
/* !Trace_To    : VEES_R_06_02985_008.01                                      */
/* !Trace_To    : VEES_R_06_02985_009.01                                      */
/*                                                                            */
/* !LastAuthor  : J. Soufflet                                                 */
/******************************************************************************/
#define SWFAIL_vidSOFTWARE_ERROR_HOOK_I() \
do \
{ \
   SWFAIL_vidSoftwareError(); \
   __nop(); \
} \
while (0)

/******************************************************************************/
/* !FuncName    : SWFAIL_u16READ_I                                            */
/* !Description : Returns the number of errors of "snChannel" type            */
/*                                                                            */
/* !Trace_To    : VEES_R_06_02985_010.01                                      */
/*                                                                            */
/* !LastAuthor  : J. Soufflet                                                 */
/******************************************************************************/
/* !Comment : Counter value                                                   */
/* !Range   : uint16                                                          */
#define SWFAIL_u16READ_I( \
\
   snChannel            /* !Comment : Error identification                  */ \
                        /* !Range   : SWFAIL_u8STACK_ERROR,                 */ \
                        /*            SWFAIL_u8EXCEPTIONS_ERROR,            */ \
                        /*            SWFAIL_u8SOFTWARE_ERROR               */ \
) \
   (snChannel##_CNT)

/******************************************************************************/
/* !FuncName    : SWFAIL_pfvidREAD_ERROR_ADDRESS_I                            */
/* !Description : Returns the address of opcode being executed when last      */
/*                exception appeared                                          */
/*                                                                            */
/* !Trace_To    : VEES_R_06_02985_011.01                                      */
/*                                                                            */
/* !LastAuthor  : J. Soufflet                                                 */
/******************************************************************************/
/* !Comment : Error address                                                   */
/* !Range   : uint32                                                          */
#define SWFAIL_pfvidREAD_ERROR_ADDRESS_I() \
   SWFAIL_pfErrorAddress

/******************************************************************************/
/* !FuncName    : SWFAIL_bfREAD_ERROR_TYPE_I                                  */
/* !Description : Returns the bitfield value of error type                    */
/*                                                                            */
/* !Trace_To    : VEES_R_06_02985_012.01                                      */
/*                                                                            */
/* !LastAuthor  : J. Soufflet                                                 */
/******************************************************************************/
/* !Comment : Bitfield value                                                  */
/* !Range   : SWFAIL_tbfErrorType                                             */
#define SWFAIL_bfREAD_ERROR_TYPE_I() \
   SWFAIL_bfErrorType

/******************************************************************************/
/* !FuncName    : SWFAIL_vidSTACK_OVERFLOW_HOOK_I                             */
/* !Description : Stack overflow error process                                */
/*                                                                            */
/* !Trace_To    : VEES_R_06_02985_019.01                                      */
/* !Trace_To    : VEES_R_06_02985_020.01                                      */
/* !Trace_To    : VEES_R_06_02985_021.01                                      */
/*                                                                            */
/* !LastAuthor  : A. Saporito                                                 */
/******************************************************************************/
#define SWFAIL_vidSTACK_OVERFLOW_HOOK_I(udtStackIdx) \
do \
{ \
   SWFAIL_bfErrorType = SWFAIL_bfErrorType | SWFAIL_bfSTACK_OVERFLOW; \
   SWFAIL_udtStackIdx = (udtStackIdx); \
   SWFAIL_u16StackErrorCounter = (uint16) \
                                 (SWFAIL_u16StackErrorCounter + 1u); \
} \
while (0)

/******************************************************************************/
/* !FuncName    : SWFAIL_vidSTACK_UNDERFLOW_HOOK_I                            */
/* !Description : Stack underflow error process                               */
/*                                                                            */
/* !Trace_To    : VEES_R_06_02985_019.01                                      */
/* !Trace_To    : VEES_R_06_02985_020.01                                      */
/* !Trace_To    : VEES_R_06_02985_021.01                                      */
/*                                                                            */
/* !LastAuthor  : A. Saporito                                                 */
/******************************************************************************/
#define SWFAIL_vidSTACK_UNDERFLOW_HOOK_I(udtStackIdx) \
do \
{ \
   SWFAIL_bfErrorType = SWFAIL_bfErrorType | SWFAIL_bfSTACK_UNDERFLOW; \
   SWFAIL_udtStackIdx = (udtStackIdx); \
   SWFAIL_u16StackErrorCounter = (uint16) \
                                 (SWFAIL_u16StackErrorCounter + 1u); \
} \
while (0)

/******************************************************************************/
/* !FuncName    : SWFAIL_udtREAD_STACK_IDX_I                                  */
/* !Description : Returns last stack error index                              */
/*                                                                            */
/* !Trace_To    : VEES_R_06_02985_022.01                                      */
/*                                                                            */
/* !LastAuthor  : J. Soufflet                                                 */
/******************************************************************************/
/* !Comment : Stack index                                                     */
/* !Range   : SWFAIL_tudtStackIdxType                                         */
#define SWFAIL_udtREAD_STACK_IDX_I() \
   SWFAIL_udtStackIdx

/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define SWFAIL_START_SEC_CODE
#include "SWFAIL_MemMap.h"

extern void SWFAIL_vidSoftwareError(void);

#define SWFAIL_STOP_SEC_CODE
#include "SWFAIL_MemMap.h"


#endif /* SWFAIL_PRIVATE_H */

/*------------------------------ end of file ---------------------------------*/

