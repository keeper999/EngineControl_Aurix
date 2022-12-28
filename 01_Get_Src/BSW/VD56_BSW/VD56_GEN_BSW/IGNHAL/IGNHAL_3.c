/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : IGNHAL                                                  */
/* !Description     : Ignition Driver Component                               */
/*                                                                            */
/* !File            : IGNHAL_3.c                                              */
/* !Description     :                                                         */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;
 * <Revision>
 * %PID: P2017_BSW:A30385.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/


#include "IGNHAL_I.h"

#define IGNHAL_START_SEC_CODE
#include "IGNHAL_MemMap.h"

/******************************************************************************/
/*                                                                           */
/* !FuncName    : diagnostic_bobine_a                                        */
/* !Description : Call back function of Diagnostic Handling for Coil A.      */
/*                                                                           */
/******************************************************************************/
void diagnostic_bobine_a(void)
{
   IGNHAL_vidDIAGNOSIS(COIL_A);
}
/******************************************************************************/
/*                                                                           */
/* !FuncName    : diagnostic_bobine_b                                        */
/* !Description : Call back function of Diagnostic Handling for Coil B.      */
/*                                                                           */
/******************************************************************************/
void diagnostic_bobine_b(void)
{
   IGNHAL_vidDIAGNOSIS(COIL_B);
}
/******************************************************************************/
/*                                                                           */
/* !FuncName    : diagnostic_bobine_c                                        */
/* !Description : Call back function of Diagnostic Handling for Coil C.      */
/*                                                                           */
/******************************************************************************/
void diagnostic_bobine_c(void)
{
   IGNHAL_vidDIAGNOSIS(COIL_C);
}
/******************************************************************************/
/*                                                                           */
/* !FuncName    : diagnostic_bobine_d                                        */
/* !Description : Call back function of Diagnostic Handling for Coil D.      */
/*                                                                           */
/******************************************************************************/

#define IGNHAL_STOP_SEC_CODE
#include "IGNHAL_MemMap.h"


/*------------------------------- end of file --------------------------------*/
