/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : ADCHAL                                                                                          */
/* !Description     : Analog to digital conversion on HAL .                                                           */
/*                                                                                                                    */
/* !File            : ADCHAL_Api.c                                                                                    */
/* !Description     : This file defines the API of the ADCHAL component.                                              */
/*                                                                                                                    */
/* !Reference       : PTS_DOC_5465469                                                                                 */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: LIBEMB:A4320.A-SRC;3 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "std_types.h"
#include "SWFAIL.h"
#include "ADCHAL.h"
#include "ADCHAL_L.h"
#include "ADCHAL_Cfg.h"
#include "ADCHAL_Typ_Cfg.h"
#include "ADCHAL_Scale_Cfg.h"

/**********************************************************************************************************************/
/* Check that used define for conditionnal compilation exist                                                          */
/**********************************************************************************************************************/
#ifndef TRUE
   #error The macro-constant TRUE shall be defined
#endif


#ifndef ADCHAL_coCONTINUOUS_MODE_EXIST
   #error The macro-constant ADCHAL_coCONTINUOUS_MODE_EXIST shall be defined
#endif


#define ADCHAL_START_SEC_CODE
#include "ADCHAL_MemMap.h"

/**********************************************************************************************************************/
/* !FuncName    : ADCHAL_udtPrivateRead                                                                               */
/* !Description : Read acquisition value of the channel udtChannel                                                    */
/*                                                                                                                    */
/* !Trace_To    : VEES_R_08_05204_004.01                                                                              */
/* !Trace_To    : VEES_R_08_05204_005.01                                                                              */
/* !Trace_To    : VEES_R_08_05204_006.01                                                                              */
/* !Trace_To    : VEES_R_08_05204_007.01                                                                              */
/* !Trace_To    : VEES_R_08_05204_008.01                                                                              */
/* !Trace_To    : VEES_R_08_05204_009.01                                                                              */
/*                                                                                                                    */
/* !LastAuthor  :  L. Voilmy                                                                                          */
/**********************************************************************************************************************/

FUNC(Std_ReturnType, ADCHAL_CODE) ADCHAL_udtPrivateRead
(
   ADCHAL_tudtChannelType udtChannel,
   ADCHAL_tudtResultValue * pudtResultValue
)
{
   Std_ReturnType     udtLocalStatus;
   ADCHAL_tudtPinType udtLocalPin;
   uint32             u32LocalResult;


   if (udtChannel < ADCHAL_udtNUMBER_OF_CHANNELS)
   {
      udtLocalPin = ADCHAL_akudtChannelToPin[udtChannel];

      #if (ADCHAL_coCONTINUOUS_MODE_EXIST == TRUE)
      if (udtLocalPin < ADCHAL_udtCONTINUOUS_MODE_PIN_NB)
      {
         ADCHAL_akpfvidReadRaw[udtLocalPin]();
      }
      #endif /* if (ADCHAL_coCONTINUOUS_MODE_EXIST == TRUE) */

      /* Perform specific transfert function */
      if (ADCHAL_akpfu32ScalingFunction[udtChannel] != NULL_PTR)
      {
         u32LocalResult = ADCHAL_akpfu32ScalingFunction[udtChannel](ADCHAL_audtAcquisitionsRaw[udtLocalPin]);
      }
      else
      {
         u32LocalResult = ADCHAL_audtAcquisitionsRaw[udtLocalPin];
      }

      /* perform auto-scaling */
      u32LocalResult = ADCHAL_u32ACQUISITION_AUTO_SCALING(udtChannel, u32LocalResult);

      if (u32LocalResult <= ADCHAL_akudtResultDesiredMax[udtChannel])
      {
         udtLocalStatus = E_OK;
      }
      else
      {
         u32LocalResult = ADCHAL_akudtResultDesiredMax[udtChannel];
         udtLocalStatus = E_NOT_OK;
      }
      *pudtResultValue = (ADCHAL_tudtResultValue)u32LocalResult;
   }
   else
   {
      *pudtResultValue = 0;
      SWFAIL_vidSoftwareErrorHook();
      udtLocalStatus = E_NOT_OK;
   }
   return(udtLocalStatus);
}

/**********************************************************************************************************************/
/* !FuncName    : ADCHAL_udtPrivateDisableNotification                                                                */
/* !Description :                                                                                                     */
/*                                                                                                                    */
/*                                                                                                                    */
/* !LastAuthor  :  L. Voilmy                                                                                          */
/**********************************************************************************************************************/
FUNC(Std_ReturnType, ADCHAL_CODE)  ADCHAL_udtPrivateDisableNotification
(
   ADCHAL_tudtChannelType udtChannel
)
{
   COMPILER_UNUSED_PARAMETER(udtChannel);
   SWFAIL_vidSoftwareErrorHook();
   return(E_NOT_OK);
}

/**********************************************************************************************************************/
/* !FuncName    : ADCHAL_udtPrivateEnableNotification                                                                 */
/* !Description :                                                                                                     */
/*                                                                                                                    */
/*                                                                                                                    */
/* !LastAuthor  :  L. Voilmy                                                                                          */
/**********************************************************************************************************************/
FUNC(Std_ReturnType, ADCHAL_CODE) ADCHAL_udtPrivateEnableNotification
(
   ADCHAL_tudtChannelType udtChannel
)
{
   COMPILER_UNUSED_PARAMETER(udtChannel);
   SWFAIL_vidSoftwareErrorHook();
   return(E_NOT_OK);
}

#define ADCHAL_STOP_SEC_CODE
#include "ADCHAL_MemMap.h"

/*----------------------------------------------- end of file --------------------------------------------------------*/
