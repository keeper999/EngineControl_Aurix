/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DCM_MANU                                                */
/* !Description     : DCM_MANU Component                                      */
/*                                                                            */
/* !Module          : DCM_MANU                                                */
/* !Description     : Code Manuel du DCM                                      */
/*                                                                            */
/* !File            : BswM_Dcm.c                                              */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32BIT                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / BswM_Dcm_RequestSessionMode                                          */
/*   2 / BswM_Dcm_RequestResetMode                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_5074345 / 4                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/EBX6_2/LOG/ASW/REF/MODULES/DCM_CONFIG/DCM_MANU/Bsw$*/
/* $Revision::   1.2      $$Author::   pbakabad       $$Date::   22 May 2014 $*/
/* $Author::   pbakabad                               $$Date::   22 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "BswM_Dcm.h"
#include "SchM_Dcm.h"
#include "DCM_MANU.h"
#include "DCM_MANU_L.h"
#include "DCM_MANU_IM.h"

#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BswM_Dcm_RequestSessionMode                                */
/* !Description :  Function called by DCM to request diagnostic modes.        */
/* !Number      :  Dcm.1                                                      */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void DCM_MANU_vidSetAftsVariables(argin boolean aftsValue);   */
/*  extf argret void Dcm_ExtendedDiagnosticSessionModeEntry();                */
/*  extf Dcm_VALEOSessionModeEntry(????);                                     */
/*  extf argret void Dcm_DefaultSessionModeEntry();                           */
/*  output boolean Srv_bReqDSCDiagReceived;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : BswM_Dcm_RequestSessionMode                                    */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BswM_Dcm_RequestSessionMode
(
   Dcm_SesCtrlType RequestedMode
)
{

   switch(RequestedMode)
   {
      case DCM_EXTENDED_DIAGNOSTIC_SESSION:
      DCM_MANU_vidSetAftsVariables(TRUE);
      Srv_bReqDSCDiagReceived = TRUE;
      (void)Dcm_ExtendedDiagnosticSessionModeEntry();
      break;

      case DCM_VALEO_DIAGNOSTIC_SESSION:
      DCM_MANU_vidSetAftsVariables(FALSE);
      Srv_bReqDSCDiagReceived = FALSE;
      (void)Dcm_VALEOSessionModeEntry();
      break;

      case DCM_DEFAULT_SESSION:
      default:
      DCM_MANU_vidSetAftsVariables(FALSE);
      Srv_bReqDSCDiagReceived = FALSE;
      (void)Dcm_DefaultSessionModeEntry();
      break;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BswM_Dcm_RequestResetMode                                  */
/* !Description :  Function called by DCM to request a reset of the ECU.      */
/* !Number      :  Dcm.2                                                      */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret Std_ReturnType  DCM_MANU_CheckVehicleCondition(argout         */
/* Dcm_NegativeResponseCodeType *ErrorCode);                                  */
/*  extf argret void Dcm_SsBootloaderResetModeEntry();                        */
/*  extf argret void Dcm_NoResetModeEntry();                                  */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/* SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                  */
/*  extf Dcm_SoftResetModeEntry(????);                                        */
/*  extf Dcm_KeyOnOffResetModeEntry(????);                                    */
/*  extf argret void SUPSRV_vidEnterReprogMode(argin uint16                   */
/* u16MicroControllerTemp);                                                   */
/*  extf argret void RSTSRV_vidPerformReset(argin RSTSRV_tudtResetType        */
/* udtRequestedResetType);                                                    */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input sint16 Ext_uBattMes;                                                */
/*  input uint8 IMMO_stECUConf;                                               */
/*  input uint16 IMMO_stEcuLockStTyp;                                         */
/*  input sint16 Srv_uDwnldMinVolt_C;                                         */
/*  input sint16 Srv_uDwnldMaxVolt_C;                                         */
/*  input boolean Srv_bInhImmoToBoot_C;                                       */
/*  input bool DCM_KEY_ON_OFF_RESET;                                          */
/*  input st666 DCM_MANU_ActionDmnd;                                          */
/*  input sint16 Ext_tECUMes;                                                 */
/*  output st666 DCM_MANU_ActionDmnd;                                         */
/*  output boolean Srv_bRstSw_DiagSrv;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : BswM_Dcm_RequestResetMode                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BswM_Dcm_RequestResetMode
(
   Dcm_ResetModeType RequestedMode
)
{
   sint16         s16localubattmes;
   sint16         s16localtecumes;
   uint8          u8local_error_code;
   uint8          u8LocalECUConf;
   uint16         u16LocalEcuLockStTyp;
   Std_ReturnType u8condcheck;

   switch( RequestedMode )
   {
      case DCM_SS_BOOTLOADER_RESET:

      VEMS_vidGET(Ext_uBattMes, s16localubattmes);
      VEMS_vidGET(IMMO_stECUConf, u8LocalECUConf);
      VEMS_vidGET(IMMO_stEcuLockStTyp, u16LocalEcuLockStTyp);
      u8condcheck = DCM_MANU_CheckVehicleCondition(&u8local_error_code);

      if( ( E_OK == u8condcheck                     ) &&
          ( s16localubattmes >= Srv_uDwnldMinVolt_C ) &&
          ( s16localubattmes <= Srv_uDwnldMaxVolt_C ) &&
          ( (u8LocalECUConf != IMMO_ECU_PAIRED)
            || (u16LocalEcuLockStTyp != IMMO_ECU_LOCKED)
            || (Srv_bInhImmoToBoot_C == 1))
          )
      {
         /* Les conditions sont respectées, le saut dans le boot
         est autorisé */
         DCM_MANU_ActionDmnd = DCM_SS_BOOTLOADER_RESET;
         (void)Dcm_SsBootloaderResetModeEntry();
      }
      else
      {
         /* Le saut dans le boot est interdit */
         DCM_MANU_ActionDmnd = DCM_NO_RESET;
         (void)Dcm_NoResetModeEntry();
      }
      break;

      case DCM_SOFT_RESET:

      u8condcheck = DCM_MANU_CheckADCCondition(SRV_LAMBDA,&u8local_error_code);
      /* Si les conditions ADC sont bonnes, on peut tester les autres */
      if( E_OK == u8condcheck )
      {
         /* Test des conditions sur l'état du véhicule */
         u8condcheck = DCM_MANU_CheckVehicleCondition(&u8local_error_code);
         if( E_OK == u8condcheck )
         {
            /* Les conditions sont respectées, le reset est autorisé */
            DCM_MANU_ActionDmnd = DCM_SOFT_RESET;
            (void)Dcm_SoftResetModeEntry();
         }
         else
         {
            /* Les conditions liées à l'état véhicule ne sont pas bonnes */
            /* Le reset est interdit */
            DCM_MANU_ActionDmnd = DCM_NO_RESET;
            (void)Dcm_NoResetModeEntry();
         }
      }
      else
      {
         /* Les conditions ADC ne sont pas bonnes */
         /* Le reset est interdit */
         DCM_MANU_ActionDmnd = DCM_NO_RESET;
         (void)Dcm_NoResetModeEntry();
      }
      break;

      case DCM_KEY_ON_OFF_RESET:

      u8condcheck = DCM_MANU_CheckADCCondition(SRV_LAMBDA,&u8local_error_code);
      /* Si les conditions ADC sont bonnes, on peut tester les autres */
      if( E_OK == u8condcheck )
      {
         /* Test des conditions sur l'état du véhicule */
         u8condcheck = DCM_MANU_CheckVehicleCondition(&u8local_error_code);
         if( E_OK == u8condcheck )
         {
            /* Les conditions sont respectées, le reset est autorisé */
            DCM_MANU_ActionDmnd = DCM_KEY_ON_OFF_RESET;
            (void)Dcm_KeyOnOffResetModeEntry();
         }
         else
         {
            /* Les conditions liées à l'état véhicule ne sont pas bonnes */
            /* Le reset est interdit */
            DCM_MANU_ActionDmnd = DCM_NO_RESET;
            (void)Dcm_NoResetModeEntry();
         }
      }
      else
      {
         /* Les conditions ADC ne sont pas bonnes */
         /* Le reset est interdit */
         DCM_MANU_ActionDmnd = DCM_NO_RESET;
         (void)Dcm_NoResetModeEntry();
      }
      break;

      case DCM_RESET_EXECUTION:
      /* Si on avait traité les conditions pour sauter dans le boot */
      if( DCM_SS_BOOTLOADER_RESET == DCM_MANU_ActionDmnd )
      {
         VEMS_vidGET(Ext_tECUMes, s16localtecumes);

         s16localtecumes = (sint16)(( s16localtecumes < 0 )
            ? 0 : s16localtecumes);

         /* API LdB pour sauter dans le boot avec param température */
         SUPSRV_vidEnterReprogMode( (uint16)s16localtecumes );
      }
      /* Les conditions pour le reset sont respectées */
      else if( DCM_SOFT_RESET == DCM_MANU_ActionDmnd )
      {
         /* Appel API de reset logiciel */
         RSTSRV_vidPerformReset(RSTSRV_udtSOFTWARE_RESET);
      }
      /* Les conditions pour le reset key On Off sont respectées */
      else if(DCM_KEY_ON_OFF_RESET == DCM_MANU_ActionDmnd)
      {
         /* On avertit les autres stratégie qu'une demande de
            reset va être traitée */
         VEMS_vidSET(Srv_bRstSw_DiagSrv, TRUE);
      }
      else
      {
         /* Sinon, on est dans la merde */
         SWFAIL_vidSoftwareErrorHook();
      }
      break;

      default:
      /* Aucune action n'est autorisée */
      (void)Dcm_NoResetModeEntry();
   }
}