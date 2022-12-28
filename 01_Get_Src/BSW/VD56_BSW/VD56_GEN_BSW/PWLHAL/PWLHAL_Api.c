/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : PWLHAL                                                  */
/* !Description     : Power Latch Hardware Abstraction Layer                  */
/*                                                                            */
/* !File            : PWLHAL_Api.c                                            */
/* !Description     : APIs of PWLHAL Component                                */
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
 * %PID: P2017_BSW:A11988.A-SRC;3 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Dio.h"
#include "DGOHAL.h"
#include "Os.h"
#include "Os_DisableInterrupts.h"
#include "PWLHAL.h"
#include "PWLHAL_Cfg.h"
#include "PWLHAL_Def.h"
#include "RSTSRV.h"

#define PWLHAL_START_SEC_CODE
#include "PWLHAL_MemMap.h"

/******************************************************************************/
/* !FuncName    : PWLHAL_vidInit                                              */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Hamdi Saidi                                                 */
/******************************************************************************/
void PWLHAL_vidInit(void)
{

   PWLHAL_enuEcuPowerState = PWLHAL_ECU_POWER_ON;
   PWLHAL_vidSTART_DELAY_TIMER();
}

/******************************************************************************/
/* !FuncName    : PWLHAL_vidWriteMainRlyState                                 */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Hamdi Saidi                                                 */
/******************************************************************************/
void PWLHAL_vidWriteMainRlyState(boolean bValue)
{
   boolean bLocalKeyValue;


   if (bValue != STD_OFF)
   {
      Dio_WriteChannel(PWLHAL_udtPWL_MAIN_RLY, STD_HIGH);
   }
   else
   {
      PWLHAL_u16ShutdownCnt   = PWLHAL_ku16ActRlyShutdownDly;
      PWLHAL_enuEcuPowerState = PWLHAL_ACTR_CUT_OFF_DELAY;
      Os_DisableAllConfiguredInterrupts();
      PWLHAL_vidDisableActuators();
      while (1)
      {
         bLocalKeyValue = Dio_ReadChannel(PWLHAL_udtIGK_DIN);
         if (bLocalKeyValue == STD_LOW)
         {
            PWLHAL_vidREFRESH_WTDG();
            PWLHAL_vidPowerDownManagement();
            PWLHAL_vidDELAY_10MS();
         }
         else
         {
            SuspendAllInterrupts();
            while (1)
            {
            }
         }
      }
      ShutdownOS(E_OK);
   }
}

/******************************************************************************/
/* !FuncName    : PWLHAL_bReadRawMainRlyState                                 */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Hamdi Saidi                                                 */
/******************************************************************************/
boolean PWLHAL_bReadRawMainRlyState(void)
{
   boolean bLocalResult;


   bLocalResult = Dio_ReadChannel(PWLHAL_udtPWL_MAIN_RLY);
   return(bLocalResult);
}

/******************************************************************************/
/* !FuncName    : PWLHAL_vidReadKeyDiagMainRly                                */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Hamdi Saidi                                                 */
/******************************************************************************/
void PWLHAL_vidReadKeyDiagMainRly(void)
{
   boolean bLocalIgKey;


   bLocalIgKey = Dio_ReadChannel(PWLHAL_udtIGK_DIN);
   if (bLocalIgKey != STD_LOW)
   {
      PWLHAL_bIgnitionKeyAtReset = STD_ON;
   }
   else
   {
      PWLHAL_bIgnitionKeyAtReset = STD_OFF;
   }
}

/******************************************************************************/
/* !FuncName    : PWLHAL_vidDiagMainRly                                       */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : Hamdi Saidi                                                 */
/******************************************************************************/
void PWLHAL_vidDiagMainRly(void)
{

   RSTSRV_tudtResetType udtLocalResetType;

   udtLocalResetType = RSTSRV_udtReadResetState();
   if (udtLocalResetType == RSTSRV_udtSOFTWARE_RESET)
   {
      if ( (PWLHAL_u8MainRlyCutReq == PWLHAL_u8PWDWN_CUT_REQ)
         && (PWLHAL_bIgnitionKeyAtReset == STD_OFF))
      {
         DGOHAL_vidWrite( PWLHAL_udtMAIN_RELAY_DGO_CH,
                          (DGOHAL_bfVALID_OPEN | DGOHAL_bfVALID_GROUND)
                          | DGOHAL_bfVALID_SUPPLY,
                          (DGOHAL_bfFAULT_OPEN | DGOHAL_bfFAULT_GROUND)
                          | DGOHAL_bfFAULT_SUPPLY);
      }
   }
   else
   {
      if (udtLocalResetType == RSTSRV_udtNORMAL_STARTUP_RESET)
      {
         DGOHAL_vidWrite( PWLHAL_udtMAIN_RELAY_DGO_CH,
                          (DGOHAL_bfVALID_OPEN | DGOHAL_bfVALID_GROUND)
                          | DGOHAL_bfVALID_SUPPLY,
                          (DGOHAL_bfNO_FAULT_OPEN | DGOHAL_bfNO_FAULT_GROUND)
                          | DGOHAL_bfNO_FAULT_SUPPLY);
      }
   }
   PWLHAL_u8MainRlyCutReq = PWLHAL_u8PWDWN_NO_CUT_REQ;
}

#define PWLHAL_STOP_SEC_CODE
#include "PWLHAL_MemMap.h"

/*------------------------------- end of file --------------------------------*/
