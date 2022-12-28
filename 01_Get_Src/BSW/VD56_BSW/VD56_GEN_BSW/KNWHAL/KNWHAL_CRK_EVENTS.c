/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : KNWHAL                                                  */
/* !Description     : Knock Window Layer                                      */
/*                                                                            */
/* !File            : KNWHAL_CRK_EVENTS.c                                     */
/* !Description     : External function called by the KRN                     */
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
 * %PID: P2017_BSW:0A170691.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/
#include "KNWHAL_I.h"
#include "KNWHAL.h"

#define KNWHAL_START_SEC_CODE
#include "KNWHAL_MemMap.h"

/******************************************************************************/
/*                                                                            */
/* !FuncName    : KNWHAL_vidCrkSyncLostEntry / A                              */
/*                                                                            */
/* !Description  : Call back function when the synch is lost                  */
/* !LastAuthor  : Infineon                                                    */
/******************************************************************************/
void KNWHAL_vidCrkSyncLostEntry(void)
{
   KNWHAL_vidDeactivateResources();
}


#define KNWHAL_STOP_SEC_CODE
#include "KNWHAL_MemMap.h"

/*------------------------------- end of file --------------------------------*/
