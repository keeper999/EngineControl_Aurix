/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : L9781                                                                                           */
/* !Description     : L9781 ASIC Abstraction Layer                                                                    */
/*                                                                                                                    */
/* !File            : L9781_API.c                                                                                     */
/* !Description     : APIs of L9781 Component                                                                         */
/*                                                                                                                    */
/* !Reference       :                                                                                                 */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A189045.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "Std_Types.h"

#include "L9781.h"
#include "L9781_CFG_E.h"
#include "L9781_CFG_I.h"
#include "L9781_I.h"
#include "L9781_L.h"

#include "Dio.h"
#include "SchM_L9781.h"
#include "SWFAIL.h"

#define L9781_START_SEC_CODE
#include "L9781_MemMap.h"


/**********************************************************************************************************************/
/* !FuncName    : L9781_vidInit                                                                                       */
/* !Description : Initializes all internal L9781 variables.                                                           */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void L9781_vidInit(void)
{
   L9781_bEnableRequest       = FALSE;
   L9781_bFirstInitDone       = FALSE;
   L9781_bStopModeActive      = FALSE;
   L9781_enuStartupState      = L9781_enuSTART_CLK_EXT;
   L9781_u8SpiErrorCnt        = 0u;
   L9781_u8SpiFailureNbAtInit = 0u;
   L9781_bGdiAsicFullStopped  = FALSE;

   L9781_vidInternalInit();
}

/**********************************************************************************************************************/
/* !FuncName    : L9781_udtEnable                                                                                     */
/* !Description : L9781_udtEnable API shall enable the ASIC ST L9781 hardware component                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
Std_ReturnType L9781_udtEnable(void)
{
   Std_ReturnType udtLocalRetValue;
   boolean        bLocalEnableAuthorization = TRUE;


   /* !Comment: Check if component is already enabled */
   if (L9781_bEnabled == FALSE)
   {
      #ifdef L9781_bENABLE_AUTHORIZED_HOOK
      /* !Comment: Check if enable is authorized */
      bLocalEnableAuthorization = L9781_bENABLE_AUTHORIZED_HOOK();
      #endif /* ifdef L9781_bENABLE_AUTHORIZED_HOOK */
      if (bLocalEnableAuthorization != FALSE)
      {
         SchM_Enter_L9781_udtEnable();
         if ((L9781_bStartupComplete != FALSE) && (L9781_bGdiAsicFullStopped == FALSE))
         {
            Dio_WriteChannel(L9781_snDIO_ENABLE_CH, STD_HIGH);
            L9781_bEnableRequest = FALSE;
            L9781_bEnabled       = TRUE;
         }
         else
         {
            L9781_bEnableRequest = TRUE;
            L9781_bEnabled       = FALSE;
         }
         SchM_Exit_L9781_udtEnable();
         udtLocalRetValue = E_OK;
      }
      else
      {
         udtLocalRetValue = E_NOT_OK;
      }
   }
   else
   {
      /* !Comment: if component is already enabled then return E_OK  */
      udtLocalRetValue = E_OK;
   }

   return(udtLocalRetValue);
}

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidDisable                                                                                    */
/* !Description : L9781_vidDisable API shall disable the ASIC ST L9781 hardware component                             */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void L9781_vidDisable(void)
{
   SchM_Enter_L9781_vidDisable();
   Dio_WriteChannel(L9781_snDIO_ENABLE_CH, STD_LOW);
   L9781_bEnableRequest = FALSE;
   L9781_bEnabled       = FALSE;
   SchM_Exit_L9781_vidDisable();
}

/**********************************************************************************************************************/
/* !FuncName    : L9781_udtLoadInjectorProfile                                                                        */
/* !Description : Loads the desired injector profil with SPI request                                                  */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
Std_ReturnType L9781_udtLoadInjectorProfile
(
   uint8 u8Channel,
   uint8 u8InjProfile
)
{
   Std_ReturnType udtLocalRetValue;


   if ((u8Channel < L9781_u8NB_ASIC) && (u8InjProfile < L9781_u8NB_INJ_PROF_MAX))
   {
      udtLocalRetValue = E_OK;

      SchM_Enter_L9781_udtLoadInjProf();
      if ((L9781_bStartupComplete != FALSE) && (L9781_bGdiAsicFullStopped == FALSE))
      {
         L9781_bfInjProfUpdated &= (uint16)(~(0x0001U << (u8Channel) ) );

         if ((L9781_enuLoadingState == L9781_enuLOAD_IDLE) && (L9781_u8NbSpiRequest == 0u))
         {
            L9781_enuLoadingState   = L9781_enuLOAD_INJ_PROF;
            L9781_u8InjProfileIndex = u8InjProfile;
            L9781_vidSpiStartInit(u8Channel);
         }
         else
         {
            L9781_au8InjProfile[u8Channel] = u8InjProfile;

            L9781_vidSET_SPI_REQUEST(u8Channel, LOAD_INJ_PROF);
         }
      }
      else
      {
         udtLocalRetValue = E_NOT_OK;
      }
      SchM_Exit_L9781_udtLoadInjProf();
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
      udtLocalRetValue = E_NOT_OK;
   }

   return(udtLocalRetValue);
}

/**********************************************************************************************************************/
/* !FuncName    : L9781_udtLoadPumpProfile                                                                            */
/* !Description : Loads the desired pump profile with SPI request                                                     */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
Std_ReturnType L9781_udtLoadPumpProfile
(
   uint8 u8Channel,
   uint8 u8PmpProfile
)
{
   Std_ReturnType udtLocalRetValue;


   if ((u8Channel < L9781_u8NB_ASIC) && (u8PmpProfile < L9781_u8NB_PMP_PROF_MAX))
   {
      udtLocalRetValue = E_OK;

      SchM_Enter_L9781_udtLoadPmpProf();
      if ((L9781_bStartupComplete == TRUE) && (L9781_bGdiAsicFullStopped == FALSE))
      {
         L9781_bfPmpProfUpdated &= (uint16)(~(0x0001U << (u8Channel) ) );

         if ((L9781_enuLoadingState == L9781_enuLOAD_IDLE) && (L9781_u8NbSpiRequest == 0u))
         {
            L9781_enuLoadingState   = L9781_enuLOAD_PMP_PROF;
            L9781_u8PmpProfileIndex = u8PmpProfile;
            L9781_vidSpiStartInit(u8Channel);
         }
         else
         {
            L9781_au8PmpProfile[u8Channel] = u8PmpProfile;

            L9781_vidSET_SPI_REQUEST(u8Channel, LOAD_PMP_PROF);
         }
      }
      else
      {
         udtLocalRetValue = E_NOT_OK;
      }
      SchM_Exit_L9781_udtLoadPmpProf();
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
      udtLocalRetValue = E_NOT_OK;
   }

   return(udtLocalRetValue);
}

/**********************************************************************************************************************/
/* !FuncName    : L9781_udtGetInjProfileStatus                                                                        */
/* !Description : Returns the status from the last updating of the injector profile.                                  */
/*                E_OK = Updated; E_NOT_OK = Not updated.                                                             */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
Std_ReturnType L9781_udtGetInjProfileStatus
(
   uint8 u8Channel
)
{
   boolean        bLocalStatus;
   Std_ReturnType udtLocalRetValue;


   if (u8Channel < L9781_u8NB_ASIC)
   {
      bLocalStatus = (boolean)(! ( !(L9781_bfInjProfUpdated & (uint16)(0x0001U << (u8Channel)))));

      if (bLocalStatus != FALSE)
      {
         udtLocalRetValue = E_OK;
      }
      else
      {
         udtLocalRetValue = E_NOT_OK;
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
      udtLocalRetValue = E_NOT_OK;
   }

   return(udtLocalRetValue);
}

/**********************************************************************************************************************/
/* !FuncName    : L9781_udtGetPumpProfileStatus                                                                       */
/* !Description : Returns the status from the last updating of the pump.                                              */
/*                E_OK = Updated; E_NOT_OK = Not updated.                                                             */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
Std_ReturnType L9781_udtGetPumpProfileStatus
(
   uint8 u8Channel
)
{
   boolean        bLocalStatus;
   Std_ReturnType udtLocalRetValue;


   if (u8Channel < L9781_u8NB_ASIC)
   {
      bLocalStatus = (boolean)(! ( !(L9781_bfPmpProfUpdated & (uint16)(0x0001U << (u8Channel)))));

      if (bLocalStatus != FALSE)
      {
         udtLocalRetValue = E_OK;
      }
      else
      {
         udtLocalRetValue = E_NOT_OK;
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
      udtLocalRetValue = E_NOT_OK;
   }

   return(udtLocalRetValue);
}

/**********************************************************************************************************************/
/* !FuncName    : L9781_udtFullStop                                                                                   */
/* !Description : Forces the ASIC GDI in reset mode.                                                                  */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
Std_ReturnType L9781_udtFullStop(void)
{
   Std_ReturnType udtLocalRetValue;

   /* !Comment: L9781_udtFullStop() returns E_OK only when initialization is  */
   /*           fully finished :                                              */
   /*           - start up sequence finished (L9781_bStartupComplete = TRUE)  */

   if (L9781_bStartupComplete != FALSE)
   {
      /* !Comment: if ASIC GDI is already in STOP Mode, then no action will   */
      /*           be performed and E_OK will be returned in order to inform  */
      /*           upper layer that request is accepted.                      */
      udtLocalRetValue = E_OK;

      if (L9781_bGdiAsicFullStopped == FALSE)
      {
         /* !Comment: Reset Request Flag                                      */
         L9781_bGdiAsicFullStopped = TRUE;
         /* !Comment: Enter Stop Mode                                         */
         L9781_vidEnterStopMode();
      }
   }
   else
   {
      /* !Comment: Conditions are not satified to call this API               */
      udtLocalRetValue = E_NOT_OK;
   }
   return(udtLocalRetValue);
}

/**********************************************************************************************************************/
/* !FuncName    : L9781_udtReInitialize                                                                               */
/* !Description : Performs a full re-initialization of the ASIC GDI.                                                  */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
Std_ReturnType L9781_udtReInitialize(void)
{
   Std_ReturnType udtLocalRetValue;


   /* !Comment: L9781_udtReInitialize() returns E_OK only when initialization */
   /*           is fully finished :                                           */
   /*           - start up sequence finished (L9781_bStartupComplete = TRUE)  */

   if (L9781_bStartupComplete != FALSE)
   {
      /* !Comment: if ASIC GDI already exits the STOP Mode, then no action    */
      /*           will be performed and E_OK will be returned in order to    */
      /*           inform ASW layer that request is accepted.                 */
      udtLocalRetValue = E_OK;

      if (L9781_bGdiAsicFullStopped != FALSE)
      {
         L9781_bGdiAsicFullStopped = FALSE;
         /* !Comment: Request a re-initialization of the ASIC GDI             */
         L9781_vidReInit();
      }
   }
   else
   {
      /* !Comment: Conditions are not satified to call this API               */
      udtLocalRetValue = E_NOT_OK;
   }
   return(udtLocalRetValue);
}


#define L9781_STOP_SEC_CODE
#include "L9781_MemMap.h"

/*--------------------------------------------------- END OF FILE ----------------------------------------------------*/
