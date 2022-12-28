/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : PFCHAL                                                  */
/* !Description     : PFCHAL Component                                        */
/*                                                                            */
/* !File            : PFCHAL_Api.c                                            */
/* !Description     : Api of the PFCHAL Component                             */
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
 * %PID: P2017_BSW:0A111666.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "PFCHAL.h"
#include "PFCHAL_Cfg_I.h"
#include "PFCHAL_I.h"
#include "SWFAIL.h"

/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

#define PFCHAL_START_SEC_CODE
#include "PFCHAL_MemMap.h"

/******************************************************************************/
/* !Description: Initializes all internal PFCHAL variables to default values  */
/* !Reference  : V03 NT 09 03587.01                                           */
/* !TraceTo    : VEES_R_09_03587_001.01,                                      */
/*                                                                            */
/* !LastAuthor : M.El-Beih                                                    */
/******************************************************************************/
void PFCHAL_vidInit(void)
{
	uint8 u8LocalIndex;

	for (u8LocalIndex = 0; u8LocalIndex < PFCHAL_u8CHANNEL_NB; u8LocalIndex++)
	{
      PFCHAL_au8CurrentMode[u8LocalIndex] = PFCHAL_u8UNSET_MODE;
	}
}

/******************************************************************************/
/* !Description: Initializes all PFCHAL pins to configured default functions  */
/* !Reference  : V03 NT 09 03587.01                                           */
/* !TraceTo    : VEES_R_09_03587_005.01,                                      */
/*               VEES_R_09_03587_006.01,                                      */
/*                                                                            */
/* !LastAuthor : M.El-Beih                                                    */
/******************************************************************************/
void PFCHAL_vidEnable(void)
{
   PFCHAL_vidInitConfig();
}

/******************************************************************************/
/* !Description: configure all basic software resources needed to allow the   */
/*               application to access the ECU pin identified by u8Channel    */
/*               with the DIOHAL component interfaces.                        */
/* !Reference  : V03 NT 09 03587.01                                           */
/* !TraceTo    : VEES_R_09_03587_008.01,                                      */
/*               VEES_R_09_03587_009.01                                       */
/*                                                                            */
/* !LastAuthor : M.El-Beih                                                    */
/******************************************************************************/
void PFCHAL_vidDioEnable
(
   uint8 u8Channel /* !Comment: DIOHAL channel identifier.                    */
)
{
   if (u8Channel < PFCHAL_u8CHANNEL_NB)
   {
      PFCHAL_akpfvidChannelConfig[u8Channel] (PFCHAL_u8DIO_MODE);
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/******************************************************************************/
/* !Description: configure all basic software resources needing to allow the  */
/*               application to access the ECU pin identified by u8Channel    */
/*               with the PWMHAL component interfaces.                        */
/* !Reference  : V03 NT 09 03587.01                                           */
/* !TraceTo    : VEES_R_09_03587_011.01,                                      */
/*               VEES_R_09_03587_012.01                                       */
/*                                                                            */
/* !LastAuthor : M.El-Beih                                                    */
/******************************************************************************/
void PFCHAL_vidPwmEnable
(
   uint8 u8Channel /* !Comment: PWMHAL channel identifier.                    */
)
{
   if (u8Channel < PFCHAL_u8CHANNEL_NB)
   {
      PFCHAL_akpfvidChannelConfig[u8Channel] (PFCHAL_u8PWM_MODE);
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

#define PFCHAL_STOP_SEC_CODE
#include "PFCHAL_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
