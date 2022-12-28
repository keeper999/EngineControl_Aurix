/******************************************************************************/
/* !Layer           : SRVL                                                    */
/* !Component       : SWFAIL                                                  */
/* !Description     : Software Failure Management                             */
/*                                                                            */
/* !File            : SWFAIL.c                                                */
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
 * %PID: LIBEMB:A1716.A-SRC;4 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "STD_TYPES.h"
#include "SWFAIL.h"

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
#define SWFAIL_START_SEC_CODE
#include "SWFAIL_MemMap.h"

/******************************************************************************/
/* !FuncName    : SWFAIL_vidInit                                              */
/* !Description : Initialisation of the component                             */
/*                                                                            */
/* !Trace_To    : VEES_R_06_02985_003.01                                      */
/* !Trace_To    : VEES_R_06_02985_004.01                                      */
/*                                                                            */
/* !LastAuthor  :  L. Baglin                                                  */
/******************************************************************************/
void SWFAIL_vidInit(void)
{
}

/******************************************************************************/
/* !FuncName    : SWFAIL_vidErase                                             */
/* !Description : Clear all component data                                    */
/*                                                                            */
/* !Trace_To    : VEES_R_06_02985_006.01                                      */
/*                                                                            */
/* !LastAuthor  :  L. Baglin                                                  */
/******************************************************************************/
void SWFAIL_vidErase(void)
{
   uint8_least u8LocalIndex;


   SWFAIL_bfErrorType              = 0u;
   SWFAIL_bfTrapType               = 0u;
   SWFAIL_pfErrorAddress           = 0u;
   SWFAIL_pfu32IllegalInstruction  = 0u;
   SWFAIL_pfu32ProgramReturnError  = 0u;
   SWFAIL_u16ExceptionErrorCounter = 0u;
   SWFAIL_u16SoftwareErrorCounter  = 0u;
   SWFAIL_u16StackErrorCounter     = 0u;
   SWFAIL_u32StatusRegisterError   = 0u;
   SWFAIL_u8CoreIdx                = 0u;
   SWFAIL_udtStackIdx              = 0u;

   for (u8LocalIndex = 0u;
        u8LocalIndex < SWFAIL_u8SAVE_CONTEXT_ARRAY_SIZE;
        u8LocalIndex++)
   {
      SWFAIL_audtSaveContext[u8LocalIndex] = 0u;
   }
}

#define SWFAIL_STOP_SEC_CODE
#include "SWFAIL_MemMap.h"


/*------------------------------ end of file ---------------------------------*/
