/******************************************************************************/
/* !Layer           : SRVL                                                    */
/* !Component       : SWFAIL                                                  */
/* !Description     : Software Failure Management                             */
/*                                                                            */
/* !File            : SWFAIL_Private.asm                                      */
/* !Description     : SWFAIL Trap Management functions to save context        */
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
 * %PID: LIBEMB:A1720.A-SRC;4 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

   .extern SWFAIL_audtSaveContext,STT_OBJECT,0
   .extern SWFAIL_pfu32IllegalInstruction,STT_OBJECT,0
   .extern SWFAIL_u16SoftwareErrorCounter,STT_OBJECT,2
   .extern SWFAIL_pfErrorAddress,STT_OBJECT,4
   .extern SWFAIL_u32CpuIdx,STT_OBJECT,4
   .extern SWFAIL_u32StatusRegisterError,STT_OBJECT,4
   .extern SWFAIL_pfu32ProgramReturnError,STT_OBJECT,0
   .extern SWFAIL_u16ExceptionErrorCounter,STT_OBJECT,2
   .extern SWFAIL_bfErrorType,STT_OBJECT,0
   .extern SWFAIL_bfTrapType,STT_OBJECT,0
   .extern SWFAIL_vidPerformManualReset,STT_FUNC,0

/******************************************************************************/
/* DEFINES                                                                     /
/******************************************************************************/

/* !Comment: Defect codes definition for SWFAIL_bfErrorType Bit field         */
SWFAIL_bfSOFTWARE_ERROR                    = (1 << 0)
SWFAIL_bfMANUAL_RESET                      = (1 << 1)
SWFAIL_bfTRAP_DETECTION                    = (1 << 2)
SWFAIL_bfSTACK_OVERFLOW                    = (1 << 3)
SWFAIL_bfSTACK_UNDERFLOW                   = (1 << 4)
SWFAIL_bfCSA_OVERFLOW                      = (1 << 5)
SWFAIL_bfCSA_UNDERFLOW                     = (1 << 6)

/* !Comment: Defect codes definition for SWFAIL_bfTrapType Bit field          */
/*Trap 0*/
SWFAIL_bfTRAP_VIRTUAL_ADDR_FILL            = (1 << 0)
SWFAIL_bfTRAP_VIRTUAL_ADDR_PROTECTION      = (1 << 1)
/*Trap 1*/
SWFAIL_bfTRAP_PRIVILEGED_INSTRUCTION       = (1 << 2)
SWFAIL_bfTRAP_MEM_PROTECTION_R             = (1 << 3)
SWFAIL_bfTRAP_MEM_PROTECTION_W             = (1 << 4)
SWFAIL_bfTRAP_MEM_PROTECTION_EX            = (1 << 5)
SWFAIL_bfTRAP_MEM_PROTECTION_PERIPH_ACCESS = (1 << 6)
SWFAIL_bfTRAP_MEM_PROTECTION_NULL_ADDR     = (1 << 7)
SWFAIL_bfTRAP_GLOBAL_REG_PROTECTION_W      = (1 << 8)
/*Trap 2*/
SWFAIL_bfTRAP_ILLEGAL_OPCODE               = (1 << 9)
SWFAIL_bfTRAP_UNIMPLEMENTED_OPCODE         = (1 << 10)
SWFAIL_bfTRAP_INVALID_OPERANDE             = (1 << 11)
SWFAIL_bfTRAP_DATA_ADDR_ALIGNEMENT         = (1 << 12)
SWFAIL_bfTRAP_INVALID_LOCAL_MEM_ADDR       = (1 << 13)
/*Trap 3*/
SWFAIL_bfTRAP_FREE_CTX_LIST_DEPLETION      = (1 << 14)
SWFAIL_bfTRAP_CALL_DEPTH_OVERFLOW          = (1 << 15)
SWFAIL_bfTRAP_CALL_DEPTH_UNDERFLOW         = (1 << 16)
SWFAIL_bfTRAP_FREE_CTX_LIST_UNDERFLOW      = (1 << 17)
SWFAIL_bfTRAP_STACK_UNDERFLOW              = (1 << 18)
SWFAIL_bfTRAP_CTX_TYPE                     = (1 << 19)
SWFAIL_bfTRAP_NESTING_ERROR                = (1 << 20)
/*Trap 4*/
SWFAIL_bfTRAP_PROGRAM_FETCH_SYNC_ERROR     = (1 << 21)
SWFAIL_bfTRAP_DATA_ACCESS_SYNC_ERROR       = (1 << 22)
SWFAIL_bfTRAP_DATA_ACCESS_ASYNC_ERROR      = (1 << 23)
SWFAIL_bfTRAP_COPRO_TRAP_ASYNC_ERROR       = (1 << 24)
SWFAIL_bfTRAP_PROGRAM_MEM_INTEGRITY_ERROR  = (1 << 25)
SWFAIL_bfTRAP_DATA_MEM_INTEGRITY_ERROR     = (1 << 26)
SWFAIL_bfTRAP_TEMPORAL_ASYNCHRONOUS_ERROR  = (1 << 27)
/*Trap 5*/
SWFAIL_bfTRAP_ARITHMETIC_OVERFLOW          = (1 << 28)
SWFAIL_bfTRAP_STICKY_ARITHMETIC_OVERFLOW   = (1 << 29)
/*Trap 6*/
SWFAIL_bfTRAP_SYSTEM_CALL                  = (1 << 30)
/*Trap 7*/
SWFAIL_bfTRAP_NON_MASKABLE_INTERRUPT       = (1 << 31)

CORE_ID = 0xFE1C

#define SWFAIL_START_SEC_CODE
#include "SWFAIL_MemMap.h"

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/

/******************************************************************************/
/* !FuncName    : SWFAIL_vidExceptionProcessing                               */
/* !Description : Saves the register context before executing a manual reset  */
/*                                                                            */
/* !LastAuthor  :  L. Baglin                                                  */
/******************************************************************************/
   .global  SWFAIL_vidExceptionProcessing
   .type    SWFAIL_vidExceptionProcessing,@function

SWFAIL_vidExceptionProcessing:
/* !Pseudo: A2= start address of the table                                    */
/*          SWFAIL_audtSaveContext[SWFAIL_u8SAVE_CONTEXT_ARRAY_SIZE]          */
   movh.a   %a2,hi:(SWFAIL_audtSaveContext)
   lea      %a2,[%a2]lo:(SWFAIL_audtSaveContext)


/* !Pseudo: A2 = end address of the table (end @ = (size-1)*sizeof(word)      */
/*                                               + start @)                   */
/*          SWFAIL_audtSaveContext[SWFAIL_u8SAVE_CONTEXT_ARRAY_SIZE]          */
   mov      %d1,0x0000007C
   mov.d    %d2,%a2
   add      %d2,%d1
   mov.a    %a2,%d2


/* !Pseudo: A3 = address Stack Pointer                                        */
   mov.aa   %a3,%a10


/* !Pseudo: Value of A10 before exception                                     */
/* (depend du nombre de registre empile avant appel de la fonction (ici 6)    */
   mov      %d1,0x00000018
   mov.d    %d2,%a3
   add      %d2,%d1
   mov.a    %a3,%d2

/* !Pseudo: Save A15..A11 into the table                                      */
   mov.a    %a4,0x00000004

   st.a     [%a2],%a15
   st.a     [+%a2]-4,%a14
   st.a     [+%a2]-4,%a13
   st.a     [+%a2]-4,%a12
   st.a     [+%a2]-4,%a11


/* !Pseudo: Save value SP before exception (A3) into the table                */
   st.a     [+%a2]-4,%a3

/* !Pseudo: Save A9..A6 into the table                                        */
   st.a     [+%a2]-4,%a9
   st.a     [+%a2]-4,%a8
   st.a     [+%a2]-4,%a7
   st.a     [+%a2]-4,%a6
   st.a     [+%a2]-4,%a5

/* !Pseudo: Get A4..A2 from the stack and save them into the table            */
   mov.d    %d2,%a3
   sub      %d2,%d1
   mov.a    %a3,%d2

   ld.a     %a4,[%a3+]
   st.a     [+%a2]-4,%a4

   ld.a     %a4,[%a3+]
   st.a     [+%a2]-4,%a4

   ld.a     %a4,[%a3+]
   st.a     [+%a2]-4,%a4


/* !Pseudo: Save A1..A0 into the table                                        */
   st.a     [+%a2]-4,%a1
   st.a     [+%a2]-4,%a0

   st.w     [+%a2]-4,%d15
   st.w     [+%a2]-4,%d14
   st.w     [+%a2]-4,%d13
   st.w     [+%a2]-4,%d12
   st.w     [+%a2]-4,%d11
   st.w     [+%a2]-4,%d10
   st.w     [+%a2]-4,%d9
   st.w     [+%a2]-4,%d8
   st.w     [+%a2]-4,%d7
   st.w     [+%a2]-4,%d6
   st.w     [+%a2]-4,%d5
   st.w     [+%a2]-4,%d4

/* !Pseudo: Get D3..D1 from the stack and save them into the table            */
   ld.a     %a4,[%a3+]
   st.a     [+%a2]-4,%a4

   ld.a     %a4,[%a3+]
   st.a     [+%a2]-4,%a4

   ld.a     %a4,[%a3+]
   st.a     [+%a2]-4,%a4

/* !Pseudo: Finally save D0 into the table                                    */
/*          SWFAIL_audtSaveContext[SWFAIL_u8SAVE_CONTEXT_ARRAY_SIZE]          */
   st.w     [+%a2]-4,%d0

/* !Pseudo: Save address of opcode being executed when exception appeared     */
/*          PC into SWFAIL_pfErrorAddress                                     */
   movh.a   %a3,hi:(SWFAIL_pfErrorAddress)
   lea      %a3,[%a3]lo:(SWFAIL_pfErrorAddress)

   st.a     [%a3],%a11

/* !Pseudo: Save opcode being executed when exception appeared                */
/*          PC into SWFAIL_pfu32IllegalInstruction                            */
   movh.a   %a3,hi:(SWFAIL_pfu32IllegalInstruction)
   lea      %a3,[%a3]lo:(SWFAIL_pfu32IllegalInstruction)

/* In case of address non align on 32 bits */
   mov.u    %d2,0xFFFC
   movh     %d1,0xFFFF
   or       %d2,%d1
   mov.d    %d1,%a11
   and      %d1,%d2
   mov.a    %a11,%d1

   ld.a     %a4,[%a11]
   st.a     [%a3],%a4

/* !Pseudo: Save the status register PSW into SWFAIL_u32StatusRegisterError   */
   movh.a   %a3,hi:(SWFAIL_u32StatusRegisterError)
   lea      %a3,[%a3]lo:(SWFAIL_u32StatusRegisterError)

   mfcr    %d2,$psw
   st.w     [%a3],%d2

/* !Pseudo: Save the CORE ID into SWFAIL_u8CoreIdx                            */
   movh.a   %a3,hi:(SWFAIL_u8CoreIdx)
   lea      %a3,[%a3]lo:(SWFAIL_u8CoreIdx)

   mfcr    %d2,CORE_ID
   st.b     [%a3],%d2

/* !Pseudo: Save program return PR into SWFAIL_pfu32ProgramReturnError        */
   movh.a   %a3,hi:(SWFAIL_pfu32ProgramReturnError)
   lea      %a3,[%a3]lo:(SWFAIL_pfu32ProgramReturnError)

   st.a     [%a3],%a11

/* !Pseudo: Save the defect type into SWFAIL_bfTrapType                       */
   movh.a   %a3,hi:(SWFAIL_bfTrapType)
   lea      %a3,[%a3]lo:(SWFAIL_bfTrapType)

   ld.w     %d2,[%a3]
   or       %d2,%d3
   st.w     [%a3],%d2

/* !Pseudo: Save the Trap detection info into SWFAIL_bfErrorType              */
   movh.a   %a3,hi:(SWFAIL_bfErrorType)
   lea      %a3,[%a3]lo:(SWFAIL_bfErrorType)

   movh     %d2,hi:(SWFAIL_bfTRAP_DETECTION)
   addi     %d2,%d2,lo:(SWFAIL_bfTRAP_DETECTION)
   ld.w     %d3,[%a3]
   or       %d2,%d3
   st.w     [%a3],%d2

/* !Pseudo: Increment SWFAIL_u16ExceptionErrorCounter                         */
   movh.a   %a3,hi:(SWFAIL_u16ExceptionErrorCounter)
   lea      %a3,[%a3]lo:(SWFAIL_u16ExceptionErrorCounter)

   ld.h     %d2,[%a3]
   addi     %d2,%d2,1
   st.h     [%a3],%d2

/* !Pseudo: Restore d1..d3, a2..a4                                            */
   ld.a     %a4,[%a10+]
   ld.a     %a3,[%a10+]
   ld.a     %a2,[%a10+]
   ld.w     %d3,[%a10+]
   ld.w     %d2,[%a10+]
   ld.w     %d1,[%a10+]

   CALL     SWFAIL_vidPerformManualReset
/* !Pseudo: Return from exception never executed because of the manual reset  */
  ret
  nop


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

/******************************************************************************/
/* !FuncName    : SWFAIL_vidManualResetDefect                                 */
/* !Description : Manual reset defect process                                 */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidManualResetDefect
   .type    SWFAIL_vidManualResetDefect,@function
SWFAIL_vidManualResetDefect:
/* !Pseudo: Store R1..R3 and PR in the stack                                  */
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3

/* !Pseudo: Save the manual reset defect type into SWFAIL_bfErrorType         */
   movh.a   %a3,hi:(SWFAIL_bfErrorType)
   lea      %a3,[%a3]lo:(SWFAIL_bfErrorType)
           
   ld.w     %d2,[%a3]
   mov.u    %d3,SWFAIL_bfMANUAL_RESET
   or       %d2,%d3

   st.w     [%a3],%d2

/* !Pseudo: Save the CORE ID into SWFAIL_u8CoreIdx                            */
   movh.a   %a3,hi:(SWFAIL_u8CoreIdx)
   lea      %a3,[%a3]lo:(SWFAIL_u8CoreIdx)

   mfcr    %d2,CORE_ID
   st.b     [%a3],%d2

/* !Pseudo: Save program return PR (R4 argument) into                         */
/*          SWFAIL_pfu32ProgramReturnError                                    */
   movh.a   %a3,hi:(SWFAIL_pfu32ProgramReturnError)
   lea      %a3,[%a3]lo:(SWFAIL_pfu32ProgramReturnError)

   st.a     [%a3],%a11

/* !Pseudo: Restore R1..R3 and PR                                             */
   ld.a     %a3,[%a10+]
   ld.a     %a2,[%a10+]
   ld.w     %d3,[%a10+]
   ld.w     %d2,[%a10+]
   ld.w     %d1,[%a10+]

   ret


/******************************************************************************/
/* !FuncName    : SWFAIL_vidSoftwareError                                     */
/* !Description : Software error process                                      */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidSoftwareError
   .type    SWFAIL_vidSoftwareError,@function
SWFAIL_vidSoftwareError:
/* !Pseudo: Store R1..R3 and PR in the stack                                  */
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3

/* !Pseudo: Save the software defect type into SWFAIL_bfErrorType             */
   movh.a   %a3,hi:(SWFAIL_bfErrorType)
   lea      %a3,[%a3]lo:(SWFAIL_bfErrorType)

   ld.w     %d2,[%a3]
   mov.u    %d3,SWFAIL_bfSOFTWARE_ERROR
   or       %d2,%d3

   st.w     [%a3],%d2

/* !Pseudo: Save the CORE ID into SWFAIL_u8CoreIdx                            */
   movh.a   %a3,hi:(SWFAIL_u8CoreIdx)
   lea      %a3,[%a3]lo:(SWFAIL_u8CoreIdx)

   mfcr    %d2,CORE_ID
   st.b     [%a3],%d2

/* !Pseudo: Save program return PR into SWFAIL_pfErrorAddress                 */
   movh.a   %a3,hi:(SWFAIL_pfErrorAddress)
   lea      %a3,[%a3]lo:(SWFAIL_pfErrorAddress)

   st.a     [%a3],%a11


/* !Pseudo: Increment SWFAIL_u16SoftwareErrorCounter                          */
   movh.a   %a3,hi:(SWFAIL_u16SoftwareErrorCounter)
   lea      %a3,[%a3]lo:(SWFAIL_u16SoftwareErrorCounter)

   ld.h     %d2,[%a3]
   addi     %d2,%d2,1
   st.h     [%a3],%d2


/* !Pseudo: Restore R1..R3 and PR                                             */
   ld.a     %a3,[%a10+]
   ld.a     %a2,[%a10+]
   ld.w     %d3,[%a10+]
   ld.w     %d2,[%a10+]
   ld.w     %d1,[%a10+]

   ret


/**********/
/* TRAP 0 */
/**********/

/******************************************************************************/
/* !FuncName    : SWFAIL_vidVirtualAddrFill                                   */
/* !Description : Error Virtual Address Fill                                  */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidVirtualAddrFill
   .type    SWFAIL_vidVirtualAddrFill,@function

SWFAIL_vidVirtualAddrFill:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_VIRTUAL_ADDR_FILL)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_VIRTUAL_ADDR_FILL)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret


/******************************************************************************/
/* !FuncName    : SWFAIL_vidVirtualAddrProtection                             */
/* !Description : Error Virtual Address Protection                            */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidVirtualAddrProtection
   .type    SWFAIL_vidVirtualAddrProtection,@function

SWFAIL_vidVirtualAddrProtection:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_VIRTUAL_ADDR_PROTECTION)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_VIRTUAL_ADDR_PROTECTION)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret


/**********/
/* TRAP 1 */
/**********/

/******************************************************************************/
/* !FuncName    : SWFAIL_vidPriviledInstruction                               */
/* !Description : Error Virtual Priviled Instruction                          */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidPriviledInstruction
   .type    SWFAIL_vidPriviledInstruction,@function

SWFAIL_vidPriviledInstruction:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_PRIVILEGED_INSTRUCTION)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_PRIVILEGED_INSTRUCTION)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret


/******************************************************************************/
/* !FuncName    : SWFAIL_vidMemProtectionR                                    */
/* !Description : Error Memory Protection Read                                */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidMemProtectionR
   .type    SWFAIL_vidMemProtectionR,@function

SWFAIL_vidMemProtectionR:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_MEM_PROTECTION_R)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_MEM_PROTECTION_R)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret


/******************************************************************************/
/* !FuncName    : SWFAIL_vidMemProtectionW                                    */
/* !Description : Error Memory Protection Write                               */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidMemProtectionW
   .type    SWFAIL_vidMemProtectionW,@function

SWFAIL_vidMemProtectionW:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_MEM_PROTECTION_W)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_MEM_PROTECTION_W)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret


/******************************************************************************/
/* !FuncName    : SWFAIL_vidMemProtectionEx                                   */
/* !Description : Error Memory Protection Execution                           */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidMemProtectionEx
   .type    SWFAIL_vidMemProtectionEx,@function

SWFAIL_vidMemProtectionEx:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_MEM_PROTECTION_EX)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_MEM_PROTECTION_EX)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret


/******************************************************************************/
/* !FuncName    : SWFAIL_vidMemProtectionPeriphAccess                         */
/* !Description : Error Memory Protection Peripheral Access                   */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidMemProtectionPeriphAccess
   .type    SWFAIL_vidMemProtectionPeriphAccess,@function

SWFAIL_vidMemProtectionPeriphAccess:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_MEM_PROTECTION_PERIPH_ACCESS)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_MEM_PROTECTION_PERIPH_ACCESS)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret


/******************************************************************************/
/* !FuncName    : SWFAIL_vidMemProtectionNullAddr                             */
/* !Description : Error Memory Protection Null Address                        */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidMemProtectionNullAddr
   .type    SWFAIL_vidMemProtectionNullAddr,@function

SWFAIL_vidMemProtectionNullAddr:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_MEM_PROTECTION_NULL_ADDR)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_MEM_PROTECTION_NULL_ADDR)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret


/******************************************************************************/
/* !FuncName    : SWFAIL_vidGlobagRegProtectionW                              */
/* !Description : Error Global Register Protection Write                      */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidGlobagRegProtectionW
   .type    SWFAIL_vidGlobagRegProtectionW,@function

SWFAIL_vidGlobagRegProtectionW:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_GLOBAL_REG_PROTECTION_W)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_GLOBAL_REG_PROTECTION_W)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret


/**********/
/* TRAP 2 */
/**********/

/******************************************************************************/
/* !FuncName    : SWFAIL_vidIllegalOpcode                                     */
/* !Description : Error Illegal Opcode                                        */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidIllegalOpcode
   .type    SWFAIL_vidIllegalOpcode,@function

SWFAIL_vidIllegalOpcode:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_ILLEGAL_OPCODE)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_ILLEGAL_OPCODE)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret


/******************************************************************************/
/* !FuncName    : SWFAIL_vidUnimplementedOpcode                               */
/* !Description : Error Unimplemented Opcode                                  */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidUnimplementedOpcode
   .type    SWFAIL_vidUnimplementedOpcode,@function

SWFAIL_vidUnimplementedOpcode:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_UNIMPLEMENTED_OPCODE)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_UNIMPLEMENTED_OPCODE)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret


/******************************************************************************/
/* !FuncName    : SWFAIL_vidInvalidOperand                                    */
/* !Description : Error Invalid Operand                                       */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidInvalidOperand
   .type    SWFAIL_vidInvalidOperand,@function

SWFAIL_vidInvalidOperand:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_INVALID_OPERANDE)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_INVALID_OPERANDE)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret


/******************************************************************************/
/* !FuncName    : SWFAIL_vidDataAddrAlignement                                */
/* !Description : Error Data Address Alignement                               */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidDataAddrAlignement
   .type    SWFAIL_vidDataAddrAlignement,@function

SWFAIL_vidDataAddrAlignement:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_DATA_ADDR_ALIGNEMENT)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_DATA_ADDR_ALIGNEMENT)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret


/******************************************************************************/
/* !FuncName    : SWFAIL_vidInvalidLocalMemoryAddr                            */
/* !Description : Error Invalid Local Memory Address                          */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidInvalidLocalMemoryAddr
   .type    SWFAIL_vidInvalidLocalMemoryAddr,@function

SWFAIL_vidInvalidLocalMemoryAddr:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_INVALID_LOCAL_MEM_ADDR)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_INVALID_LOCAL_MEM_ADDR)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret


/**********/
/* TRAP 3 */
/**********/

/******************************************************************************/
/* !FuncName    : SWFAIL_vidFreeContextListDepletion                          */
/* !Description : Error Free Context List Depletion                           */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidFreeContextListDepletion
   .type    SWFAIL_vidFreeContextListDepletion,@function

SWFAIL_vidFreeContextListDepletion:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_FREE_CTX_LIST_DEPLETION)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_FREE_CTX_LIST_DEPLETION)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret


/******************************************************************************/
/* !FuncName    : SWFAIL_vidCallDepthOverflow                                 */
/* !Description : Error Call Depth Overflow                                   */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidCallDepthOverflow
   .type    SWFAIL_vidCallDepthOverflow,@function

SWFAIL_vidCallDepthOverflow:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_CALL_DEPTH_OVERFLOW)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_CALL_DEPTH_OVERFLOW)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret


/******************************************************************************/
/* !FuncName    : SWFAIL_vidCallDepthUnderflow                                */
/* !Description : Error Call Depth Underflow                                  */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidCallDepthUnderflow
   .type    SWFAIL_vidCallDepthUnderflow,@function

SWFAIL_vidCallDepthUnderflow:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_CALL_DEPTH_UNDERFLOW)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_CALL_DEPTH_UNDERFLOW)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret


/******************************************************************************/
/* !FuncName    : SWFAIL_vidFreeContextUnderflow                              */
/* !Description : Error Free Context Underflow                                */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidFreeContextUnderflow
   .type    SWFAIL_vidFreeContextUnderflow,@function

SWFAIL_vidFreeContextUnderflow:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_FREE_CTX_LIST_UNDERFLOW)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_FREE_CTX_LIST_UNDERFLOW)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret


/******************************************************************************/
/* !FuncName    : SWFAIL_vidCallStackUnderflow                                */
/* !Description : Error Call Stack Underflow                                  */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidCallStackUnderflow
   .type    SWFAIL_vidCallStackUnderflow,@function

SWFAIL_vidCallStackUnderflow:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_STACK_UNDERFLOW)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_STACK_UNDERFLOW)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret


/******************************************************************************/
/* !FuncName    : SWFAIL_vidContextType                                       */
/* !Description : Error Context Type                                          */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidContextType
   .type    SWFAIL_vidContextType,@function

SWFAIL_vidContextType:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_CTX_TYPE)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_CTX_TYPE)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret


/******************************************************************************/
/* !FuncName    : SWFAIL_vidNestingError                                      */
/* !Description : Nesting Error                                               */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidNestingError
   .type    SWFAIL_vidNestingError,@function

SWFAIL_vidNestingError:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_NESTING_ERROR)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_NESTING_ERROR)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret


/**********/
/* TRAP 4 */
/**********/

/******************************************************************************/
/* !FuncName    : SWFAIL_vidProgramFetchSyncError                             */
/* !Description : Program Fetch Synchronous Error                             */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidProgramFetchSyncError
   .type    SWFAIL_vidProgramFetchSyncError,@function

SWFAIL_vidProgramFetchSyncError:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_PROGRAM_FETCH_SYNC_ERROR)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_PROGRAM_FETCH_SYNC_ERROR)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret


/******************************************************************************/
/* !FuncName    : SWFAIL_vidDataAccessSyncError                               */
/* !Description : Data Access Synchronous Error                               */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidDataAccessSyncError
   .type    SWFAIL_vidDataAccessSyncError,@function

SWFAIL_vidDataAccessSyncError:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_DATA_ACCESS_SYNC_ERROR)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_DATA_ACCESS_SYNC_ERROR)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret


/******************************************************************************/
/* !FuncName    : SWFAIL_vidDataAccessAsyncError                              */
/* !Description : Data Access Asynchronous Error                              */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidDataAccessAsyncError
   .type    SWFAIL_vidDataAccessAsyncError,@function

SWFAIL_vidDataAccessAsyncError:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_DATA_ACCESS_ASYNC_ERROR)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_DATA_ACCESS_ASYNC_ERROR)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret


/******************************************************************************/
/* !FuncName    : SWFAIL_vidCoproTrapAsyncError                               */
/* !Description : Coprocessor Trap Asynchronous Error                         */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidCoproTrapAsyncError
   .type    SWFAIL_vidCoproTrapAsyncError,@function

SWFAIL_vidCoproTrapAsyncError:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_COPRO_TRAP_ASYNC_ERROR)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_COPRO_TRAP_ASYNC_ERROR)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret


/******************************************************************************/
/* !FuncName    : SWFAIL_vidProgramMemIntegrityError                          */
/* !Description : Program Memory Integrity Error                              */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidProgramMemIntegrityError
   .type    SWFAIL_vidProgramMemIntegrityError,@function

SWFAIL_vidProgramMemIntegrityError:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_PROGRAM_MEM_INTEGRITY_ERROR)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_PROGRAM_MEM_INTEGRITY_ERROR)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret


/******************************************************************************/
/* !FuncName    : SWFAIL_vidDataMemIntegrityError                             */
/* !Description : Data Memory Integrity Error                                 */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidDataMemIntegrityError
   .type    SWFAIL_vidDataMemIntegrityError,@function

SWFAIL_vidDataMemIntegrityError:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_PROGRAM_MEM_INTEGRITY_ERROR)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_PROGRAM_MEM_INTEGRITY_ERROR)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret


/******************************************************************************/
/* !FuncName    : SWFAIL_vidTemporalAsynchronousError                         */
/* !Description : Temporal Asynchronous Error                                 */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidTemporalAsynchronousError
   .type    SWFAIL_vidTemporalAsynchronousError,@function

SWFAIL_vidTemporalAsynchronousError:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_TEMPORAL_ASYNCHRONOUS_ERROR)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_TEMPORAL_ASYNCHRONOUS_ERROR)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret


/**********/
/* TRAP 5 */
/**********/

/******************************************************************************/
/* !FuncName    : SWFAIL_vidArithmeticOverflow                                */
/* !Description : Error Arithmetic Overflow                                   */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidArithmeticOverflow
   .type    SWFAIL_vidArithmeticOverflow,@function

SWFAIL_vidArithmeticOverflow:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_ARITHMETIC_OVERFLOW)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_ARITHMETIC_OVERFLOW)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret


/******************************************************************************/
/* !FuncName    : SWFAIL_vidStickyArithmeticOverflow                          */
/* !Description : Error Sticky Arithmetic Overflow                            */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidStickyArithmeticOverflow
   .type    SWFAIL_vidStickyArithmeticOverflow,@function

SWFAIL_vidStickyArithmeticOverflow:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_STICKY_ARITHMETIC_OVERFLOW)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_STICKY_ARITHMETIC_OVERFLOW)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret


/**********/
/* TRAP 6 */
/**********/

/******************************************************************************/
/* !FuncName    : SWFAIL_vidSystemCall                                        */
/* !Description : System Call                                                 */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidSystemCall
   .type    SWFAIL_vidSystemCall,@function

SWFAIL_vidSystemCall:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_SYSTEM_CALL)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_SYSTEM_CALL)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret


/**********/
/* TRAP 7 */
/**********/

/******************************************************************************/
/* !FuncName    : SWFAIL_vidNonMaskableInterrupt                              */
/* !Description : Non Maskable Interrupt                                      */
/*                                                                            */
/* !LastAuthor  : L.Baglin                                                    */
/******************************************************************************/
   .global  SWFAIL_vidNonMaskableInterrupt
   .type    SWFAIL_vidNonMaskableInterrupt,@function

SWFAIL_vidNonMaskableInterrupt:
   st.w     [+%a10]-4,%d1
   st.w     [+%a10]-4,%d2
   st.w     [+%a10]-4,%d3
   st.a     [+%a10]-4,%a2
   st.a     [+%a10]-4,%a3
   st.a     [+%a10]-4,%a4

   /*stocke type de defaut*/
   movh     %d3,hi:(SWFAIL_bfTRAP_NON_MASKABLE_INTERRUPT)
   addi     %d3,%d3,lo:(SWFAIL_bfTRAP_NON_MASKABLE_INTERRUPT)

   /*appel fonction _vidExceptionProcessing*/
   j        SWFAIL_vidExceptionProcessing

   nop
   ret

#define SWFAIL_STOP_SEC_CODE
#include "SWFAIL_MemMap.h"

/*------------------------------- end of file --------------------------------*/
























