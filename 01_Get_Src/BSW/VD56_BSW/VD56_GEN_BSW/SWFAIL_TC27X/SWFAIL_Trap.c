/******************************************************************************/
/* !Layer           : SRVL                                                    */
/* !Component       : SWFAIL                                                  */
/* !Description     : Software Failure Management                             */
/*                                                                            */
/* !File            : SWFAIL_Trap.c                                           */
/* !Description     : Core Trap Management                                    */
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
 * %PID: LIBEMB:A1719.A-SRC;4 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

/* Inclusion of Platform_Types.h and Compiler.h */
#include "Std_Types.h"

#include "SWFAIL_Private.h"

/* Own header file, this includes own configuration file also */
#include "SWFAIL_CFG.h"


#define SWFAIL_START_SEC_CODE
#include "SWFAIL_MemMap.h"

/******************************************************************************/
/* !FuncName    : SWFAIL_vidTrap_MemMngtErr                                   */
/* !Description : Trap Memory Managmeent Error Call Back Function             */
/*                                                                            */
/* !LastAuthor  : J. Soufflet                                                 */
/******************************************************************************/
DECLARE_IT(SWFAIL_vidTrap_MemMngtErr)
{
   __asm("svlcx");
   __asm(".extern   SWFAIL_vidVirtualAddrFill,STT_FUNC,0");
   __asm(".extern   SWFAIL_vidVirtualAddrProtection,STT_FUNC,0");

   __asm("JEQ   %d15,1,TRAP0_TIN1");
   __asm("JEQ   %d15,2,TRAP0_TIN2");
   __asm("J     TRAP0_END");

   /*Virtual Address Fill : VAF */
   __asm("TRAP0_TIN1:");
   __asm("J     SWFAIL_vidVirtualAddrFill");
   __asm("J     TRAP0_END");

   /*Virtual Address Protection : VAP */
   __asm("TRAP0_TIN2:");
   __asm("J     SWFAIL_vidVirtualAddrProtection");
   __asm("J     TRAP0_END");

   __asm("TRAP0_END:");
   __asm("CALL   SWFAIL_vidPerformManualReset");
}

/******************************************************************************/
/* !FuncName    : SWFAIL_vidTrapIntProtnErr                                   */
/* !Description : Trap Internal Protection Error Call Back Function           */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
DECLARE_IT(SWFAIL_vidTrapIntProtnErr)
{
   __asm("svlcx");
   __asm(".extern   SWFAIL_vidPriviledInstruction,STT_FUNC,0");
   __asm(".extern   SWFAIL_vidMemProtectionR,STT_FUNC,0");
   __asm(".extern   SWFAIL_vidMemProtectionW,STT_FUNC,0");
   __asm(".extern   SWFAIL_vidMemProtectionEx,STT_FUNC,0");
   __asm(".extern   SWFAIL_vidMemProtectionPeriphAccess,STT_FUNC,0");
   __asm(".extern   SWFAIL_vidMemProtectionNullAddr,STT_FUNC,0");
   __asm(".extern   SWFAIL_vidGlobagRegProtectionW,STT_FUNC,0");

   __asm("JEQ   %d15,1,TRAP1_TIN1");
   __asm("JEQ   %d15,2,TRAP1_TIN2");
   __asm("JEQ   %d15,3,TRAP1_TIN3");
   __asm("JEQ   %d15,4,TRAP1_TIN4");
   __asm("JEQ   %d15,5,TRAP1_TIN5");
   __asm("JEQ   %d15,6,TRAP1_TIN6");
   __asm("JEQ   %d15,7,TRAP1_TIN7");
   __asm("J     TRAP1_END");

   /*Privileged Instruction : PRIV */
   __asm("TRAP1_TIN1:");
   __asm("J     SWFAIL_vidPriviledInstruction");
   __asm("J     TRAP1_END");

   /*Memory Protection Read : MPR */
   __asm("TRAP1_TIN2:");
   __asm("J     SWFAIL_vidMemProtectionR");
   __asm("J     TRAP1_END");

   /*Memory Protection Write : MPW */
   __asm("TRAP1_TIN3:");
   __asm("J     SWFAIL_vidMemProtectionW");
   __asm("J     TRAP1_END");

   /*Memory Protection Execution : MPX */
   __asm("TRAP1_TIN4:");
   __asm("J     SWFAIL_vidMemProtectionEx");
   __asm("J     TRAP1_END");

   /*Memory Protection Peripheral Access : MPP */
   __asm("TRAP1_TIN5:");
   __asm("J     SWFAIL_vidMemProtectionPeriphAccess");
   __asm("J     TRAP1_END");

   /*Memory Protection Null Address : MPN */
   __asm("TRAP1_TIN6:");
   __asm("J     SWFAIL_vidMemProtectionNullAddr");
   __asm("J     TRAP1_END");

   /*Global Register (A0, A1, A8, A9) Write Protection : GRWP*/
   __asm("TRAP1_TIN7:");
   __asm("J     SWFAIL_vidGlobagRegProtectionW");
   __asm("J     TRAP1_END");

   __asm("TRAP1_END:");
   __asm("CALL   SWFAIL_vidPerformManualReset");
}

/******************************************************************************/
/* !FuncName    : SWFAIL_vidTrapInstructionErr                                */
/* !Description : Trap Instruction Error Call Back Function                   */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
DECLARE_IT(SWFAIL_vidTrapInstructionErr)
{
   __asm("svlcx");
   __asm(".extern   SWFAIL_vidIllegalOpcode,STT_FUNC,0");
   __asm(".extern   SWFAIL_vidUnimplementedOpcode,STT_FUNC,0");
   __asm(".extern   SWFAIL_vidInvalidOperand,STT_FUNC,0");
   __asm(".extern   SWFAIL_vidDataAddrAlignement,STT_FUNC,0");
   __asm(".extern   SWFAIL_vidInvalidLocalMemoryAddr,STT_FUNC,0");

   __asm("JEQ   %d15,1,TRAP2_TIN1");
   __asm("JEQ   %d15,2,TRAP2_TIN2");
   __asm("JEQ   %d15,3,TRAP2_TIN3");
   __asm("JEQ   %d15,4,TRAP2_TIN4");
   __asm("JEQ   %d15,5,TRAP2_TIN5");
   __asm("J     TRAP2_END");

   /* Illegal Opcode Trap : IOPC*/
   __asm("TRAP2_TIN1:");
   __asm("J     SWFAIL_vidIllegalOpcode");
   __asm("J     TRAP2_END");

   /* Unimplemented Opcode Trap : UOPC*/
   __asm("TRAP2_TIN2:");
   __asm("J     SWFAIL_vidUnimplementedOpcode");
   __asm("J     TRAP2_END");

   /* Invalid Operand Specification Trap : OPD*/
   __asm("TRAP2_TIN3:");
   __asm("J     SWFAIL_vidInvalidOperand");
   __asm("J     TRAP2_END");

   /* Data Address Alignment Trap : ALN*/
   __asm("TRAP2_TIN4:");
   __asm("J     SWFAIL_vidDataAddrAlignement");
   __asm("J     TRAP2_END");

   /* Invalid Local Memory Address Trap : MEM*/
   __asm("TRAP2_TIN5:");
   __asm("J     SWFAIL_vidInvalidLocalMemoryAddr");
   __asm("J     TRAP2_END");

 __asm("TRAP2_END:");
   __asm("CALL   SWFAIL_vidPerformManualReset");
}

/******************************************************************************/
/* !FuncName    : SWFAIL_vidTrapCtxtMngtErr                                   */
/* !Description : Trap Context Management Error Call Back Function            */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
DECLARE_IT(SWFAIL_vidTrapCtxtMngtErr)
{
//   __asm("svlcx"); // dbg
   __asm(".extern   SWFAIL_vidFreeContextListDepletion,STT_FUNC,0");
   __asm(".extern   SWFAIL_vidCallDepthOverflow,STT_FUNC,0");
   __asm(".extern   SWFAIL_vidCallDepthUnderflow,STT_FUNC,0");
   __asm(".extern   SWFAIL_vidFreeContextUnderflow,STT_FUNC,0");
   __asm(".extern   SWFAIL_vidCallStackUnderflow,STT_FUNC,0");
   __asm(".extern   SWFAIL_vidContextType,STT_FUNC,0");
   __asm(".extern   SWFAIL_vidNestingError,STT_FUNC,0");

   __asm("JEQ   %d15,1,TRAP3_TIN1");
   __asm("JEQ   %d15,2,TRAP3_TIN2");
   __asm("JEQ   %d15,3,TRAP3_TIN3");
   __asm("JEQ   %d15,4,TRAP3_TIN4");
   __asm("JEQ   %d15,5,TRAP3_TIN5");
   __asm("JEQ   %d15,6,TRAP3_TIN6");
   __asm("JEQ   %d15,7,TRAP3_TIN7");
   __asm("J     TRAP3_END");

   /* Free context list depletion trap : FCD*/
   __asm("TRAP3_TIN1:");
   __asm("J     SWFAIL_vidFreeContextListDepletion");
   __asm("J     TRAP3_END");

   /* Call depth overflow trap : CDO*/
   __asm("TRAP3_TIN2:");
   __asm("J     SWFAIL_vidCallDepthOverflow");
   __asm("J     TRAP3_END");

   /* Call depth underflow trap : CDU*/
   __asm("TRAP3_TIN3:");
   __asm("J     SWFAIL_vidCallDepthUnderflow");
   __asm("J     TRAP3_END");

   /* Free context list underflow trap : FCU*/
   __asm("TRAP3_TIN4:");
   __asm("J     SWFAIL_vidFreeContextUnderflow");
   __asm("J     TRAP3_END");

   /* Call stack underflow trap : CSU*/
   __asm("TRAP3_TIN5:");
   __asm("J     SWFAIL_vidCallStackUnderflow");
   __asm("J     TRAP3_END");

   /* context type trap : CTYP*/
   __asm("TRAP3_TIN6:");
   __asm("J     SWFAIL_vidContextType");
   __asm("J     TRAP3_END");

   /* Nesting error : NEST*/
   __asm("TRAP3_TIN7:");
   __asm("J     SWFAIL_vidNestingError");
   __asm("J     TRAP3_END");

 __asm("TRAP3_END:");
   __asm("CALL   SWFAIL_vidPerformManualReset");
}

/******************************************************************************/
/* !FuncName    : SWFAIL_vidTrapCtxtMngtErr                                   */
/* !Description : Trap Context Management Error Call Back Function            */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
DECLARE_IT(SWFAIL_vidTrapBusErr)
{
   __asm("svlcx");
   __asm(".extern   SWFAIL_vidProgramFetchSyncError,STT_FUNC,0");
   __asm(".extern   SWFAIL_vidDataAccessSyncError,STT_FUNC,0");
   __asm(".extern   SWFAIL_vidDataAccessAsyncError,STT_FUNC,0");
   __asm(".extern   SWFAIL_vidCoproTrapAsyncError,STT_FUNC,0");
   __asm(".extern   SWFAIL_vidProgramMemIntegrityError,STT_FUNC,0");
   __asm(".extern   SWFAIL_vidDataMemIntegrityError,STT_FUNC,0");
   __asm(".extern   SWFAIL_vidTemporalAsynchronousError,STT_FUNC,0");

   __asm("JEQ   %d15,1,TRAP4_TIN1");
   __asm("JEQ   %d15,2,TRAP4_TIN2");
   __asm("JEQ   %d15,3,TRAP4_TIN3");
   __asm("JEQ   %d15,4,TRAP4_TIN4");
   __asm("JEQ   %d15,5,TRAP4_TIN5");
   __asm("JEQ   %d15,6,TRAP4_TIN6");
   __asm("JEQ   %d15,7,TRAP4_TIN7");
   __asm("J     TRAP4_END");

   /*Program Fetch Synchronous Error : PSE */
   __asm("TRAP4_TIN1:");
   __asm("J     SWFAIL_vidProgramFetchSyncError");
   __asm("J     TRAP4_END");

   /*Sticky Data Access Synchronous Error : DSE */
   __asm("TRAP4_TIN2:");
   __asm("J     SWFAIL_vidDataAccessSyncError");
   __asm("J     TRAP4_END");

   /*Data Access Asynchronous Error : DAE */
   __asm("TRAP4_TIN3:");
   __asm("J     SWFAIL_vidDataAccessAsyncError");
   __asm("J     TRAP4_END");

   /*Coprocessor Trap Asynchronous Error : CAE */
   __asm("TRAP4_TIN4:");
   __asm("J     SWFAIL_vidCoproTrapAsyncError");
   __asm("J     TRAP4_END");

   /*Program Memory Integrity Error : PIE */
   __asm("TRAP4_TIN5:");
   __asm("J     SWFAIL_vidProgramMemIntegrityError");
   __asm("J     TRAP4_END");

   /*Data Memory Integrity Error : DIE */
   __asm("TRAP4_TIN6:");
   __asm("J     SWFAIL_vidDataMemIntegrityError");
   __asm("J     TRAP4_END");

   /*Temporal Asynchronous Error : TAE */
   __asm("TRAP4_TIN7:");
   __asm("J     SWFAIL_vidTemporalAsynchronousError");
   __asm("J     TRAP4_END");

 __asm("TRAP4_END:");
   __asm("CALL   SWFAIL_vidPerformManualReset");
}

/******************************************************************************/
/* !FuncName    : SWFAIL_vidTrapAssertion                                     */
/* !Description : Trap Assertion Call Back Function                           */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
DECLARE_IT(SWFAIL_vidTrapAssertion)
{
   __asm("svlcx");
   __asm(".extern   SWFAIL_vidArithmeticOverflow,STT_FUNC,0");
   __asm(".extern   SWFAIL_vidStickyArithmeticOverflow,STT_FUNC,0");

   __asm("JEQ   %d15,1,TRAP5_TIN1");
   __asm("JEQ   %d15,2,TRAP5_TIN2");
   __asm("J     TRAP5_END");

   /*Arithemetic Overflow : OVF */
   __asm("TRAP5_TIN1:");
   __asm("J     SWFAIL_vidArithmeticOverflow");
   __asm("J     TRAP5_END");

   /*Sticky Arithemetic Overflow : SOVF */
   __asm("TRAP5_TIN2:");
   __asm("J     SWFAIL_vidStickyArithmeticOverflow");
   __asm("J     TRAP5_END");

 __asm("TRAP5_END:");
   __asm("CALL   SWFAIL_vidPerformManualReset");
}

/******************************************************************************/
/* !FuncName    : SWFAIL_vidTrapAssertion                                     */
/* !Description : Trap Assertion Call Back Function                           */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
DECLARE_IT(SWFAIL_vidTrapSysCall)
{
   __asm("svlcx");
   __asm(".extern   SWFAIL_vidSystemCall,STT_FUNC,0");

   __asm("J     TRAP6_TIN0");
   __asm("J     TRAP6_END");

   /*System Call : SYS */
   __asm("TRAP6_TIN0:");
   __asm("J     SWFAIL_vidSystemCall");
   __asm("J     TRAP6_END");

   __asm("TRAP6_END:");
   __asm("CALL   SWFAIL_vidPerformManualReset");
}

/******************************************************************************/
/* !FuncName    : SWFAIL_vidTrapAssertion                                     */
/* !Description : Trap Assertion Call Back Function                           */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
DECLARE_IT(SWFAIL_vidTrapNMI)
{
   __asm("svlcx");
   __asm(".extern   SWFAIL_vidNonMaskableInterrupt,STT_FUNC,0");

   __asm("JEQ   %d15,0,TRAP7_TIN0");
   __asm("J     TRAP7_END");

   /*Non-Maskable Interrupt Trap : NMI */
   __asm("TRAP7_TIN0:");
   __asm("J     SWFAIL_vidNonMaskableInterrupt");
   __asm("J     TRAP7_END");

   __asm("TRAP7_END:");
   __asm("CALL   SWFAIL_vidPerformManualReset");
}

#define SWFAIL_STOP_SEC_CODE
#include "SWFAIL_MemMap.h"

/******************************************************************************/
/* !FuncName    : TRAP VECTOR TABLE 0 FILLING                                 */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#define SWFAIL_START_SEC_TRAPTAB
#include "SWFAIL_MemMap.h"

void SWFAIL_vidTrapVectTbl(void)
{
   SWFAIL_vidFILL_TRAP_VECT(SWFAIL_vidTrap_MemMngtErr);
   SWFAIL_vidFILL_TRAP_VECT(SWFAIL_vidTrapIntProtnErr);
   SWFAIL_vidFILL_TRAP_VECT(SWFAIL_vidTrapInstructionErr);
   SWFAIL_vidFILL_TRAP_VECT(SWFAIL_vidTrapCtxtMngtErr);
   SWFAIL_vidFILL_TRAP_VECT(SWFAIL_vidTrapBusErr);
   SWFAIL_vidFILL_TRAP_VECT(SWFAIL_vidTrapAssertion);
   SWFAIL_vidFILL_TRAP_VECT(SWFAIL_vidTrapSysCall);
   SWFAIL_vidFILL_TRAP_VECT(SWFAIL_vidTrapNMI);
}

#define SWFAIL_STOP_SEC_TRAPTAB
#include "SWFAIL_MemMap.h"

/*------------------------------ end of file ---------------------------------*/
