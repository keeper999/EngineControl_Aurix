/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : DET                                                     */
/* !Description     : AutoSAR BASIS DET Module                                */
/*                                                                            */
/* !File            : Det_Cbk.c                                               */
/* !Description     : AutoSAR BASIS DET Module                                */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A192464.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Det.h"
#include "SWFAIL.h"


#define DET_START_SEC_CODE
#include "Det_MemMap.h"

/******************************************************************************/
/* !FuncName    : TST_DGOHAL_vidInit                                          */
/* !Description : DET callback function prototype                             */
/*                This function is user defined                               */
/*                                                                            */
/* !Trace_To    : GSCSW-DET-SDD-001-0030                                      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
FUNC(void, DET_CODE) Det_CallBack \
              ( P2VAR(Det_tstrReportError, AUTOMATIC, DET_VAR_NOINIT) pstrError)
{ 
   COMPILER_UNUSED_PARAMETER(pstrError);
   SWFAIL_vidSoftwareErrorHook();
}


#define DET_STOP_SEC_CODE
#include "Det_MemMap.h"

/*------------------------------- end of file --------------------------------*/
