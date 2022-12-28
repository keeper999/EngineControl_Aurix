/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : SUPSRV                                                  */
/* !Description     : Supplier Services component                             */
/*                                                                            */
/* !File            : SUPSRV_Api.c                                            */
/* !Description     : SUPSRV services definition                              */
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
 * %PID: P2017_BSW:0A157046.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"

#include "RSTSRV.H"
#include "SUPSRV.h"
#include "VectorIntf.h"


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

#define SUPSRV_START_SEC_CODE
#include "SUPSRV_MemMap.h"

void SUPSRV_vidEnterReprogMode(uint16 u16MicroControllerTemp)
{
   COMPILER_UNUSED_PARAMETER(u16MicroControllerTemp);

   CallFblStart(FBL_START_PARAM);

   /* !Comment: No return from this function. On error, performs a reset      */
   RSTSRV_vidPerformReset(RSTSRV_udtHARDWARE_RESET);
}

#define SUPSRV_STOP_SEC_CODE
#include "SUPSRV_MemMap.h"


/*-------------------------------- end of file -------------------------------*/
