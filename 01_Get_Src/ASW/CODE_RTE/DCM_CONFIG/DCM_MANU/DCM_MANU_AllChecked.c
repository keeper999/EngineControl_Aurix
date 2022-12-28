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
/* !File            : DCM_MANU_AllChecked.c                                   */
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
/*   1 / DCM_MANU_CheckVehicleCondition                                       */
/*   2 / DCM_MANU_CheckADCCondition                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_5074345 / 4                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/EBX6_2/LOG/ASW/REF/MODULES/DCM_CONFIG/DCM_MANU/DCM$*/
/* $Revision::   1.2      $$Author::   pbakabad       $$Date::   22 May 2014 $*/
/* $Author::   pbakabad                               $$Date::   22 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "DCM_MANU.h"
#include "DCM_MANU_L.h"
#include "DCM_MANU_IM.h"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckVehicleCondition                             */
/* !Description :  Check condition "Véhicule non roulant / Moteurarrêté "     */
/* !Number      :  AllChecked.1                                               */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bRun;                                                   */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 Diag_seuil_vit_veh;                                           */
/*  input uint8 CoPTSt_stEng;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_CheckVehicleCondition
(
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   Std_ReturnType u8localreturn;
   boolean        blocalextbrun;
   uint16         u16localspdveh;
   uint8          u8localcoptst;

   VEMS_vidGET(Ext_bRun, blocalextbrun);

   u8localreturn = E_OK;

   if(blocalextbrun != 0)
   {
      /* Envoi d’une réponse négative nack $83 (moteur tournant)
         gérée par le DCM */
      *ErrorCode = DCM_E_ENGINEISRUNNING;
      u8localreturn = E_NOT_OK;
   }
   else
   {
      VEMS_vidGET(Veh_spdVeh, u16localspdveh);
      u16localspdveh = (uint16)(u16localspdveh / 128);

      if(u16localspdveh > Diag_seuil_vit_veh)
      {
         /* Envoi d’une réponse négative nack $88 (vitesse véhicule trop rapide)
            gérée par le DCM */
         *ErrorCode = DCM_E_VEHICLESPEEDTOOHIGH;
         u8localreturn = E_NOT_OK;
      }
      else
      {
         VEMS_vidGET(CoPTSt_stEng, u8localcoptst);

         if(u8localcoptst != 1)
         {
            /* Envoi d'une réponse négative nack $22 gérée par le
               DCM */
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            u8localreturn = E_NOT_OK;
         }
      }
   }

   return u8localreturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckADCCondition                                 */
/* !Description :  Check condition "ADC"                                      */
/* !Number      :  AllChecked.2                                               */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 IMMO_stEcuLockStTyp;                                         */
/*  input uint8 IMMO_stEcuPairOffStTyp;                                       */
/*  input uint8 IMMO_stECUConf;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_CheckADCCondition
(
   uint8 SrvType,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16         u16LocalEcuLockStTyp;
   uint8          u8LocalEcuPairOffStTyp;
   uint8          u8LocalECUConf;
   Std_ReturnType u8LocalOutput;

   VEMS_vidGET(IMMO_stEcuLockStTyp, u16LocalEcuLockStTyp);

   if( SRV_LAMBDA == SrvType )
   {
      VEMS_vidGET(IMMO_stEcuPairOffStTyp, u8LocalEcuPairOffStTyp);

      if( ( IMMO_ECU_VIRGIN == u8LocalEcuPairOffStTyp ) ||
          ( IMMO_ECU_UNLOCKED == u16LocalEcuLockStTyp ) )
      {
         u8LocalOutput = E_OK;
      }
      else
      {
         u8LocalOutput = E_NOT_OK;
         *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
      }
   }
   else
   {
      VEMS_vidGET(IMMO_stECUConf, u8LocalECUConf);

      if( SRV_MATCHING == SrvType )
      {
         if( ( IMMO_ECU_PROG_1 == u8LocalECUConf     ) ||
             ( IMMO_ECU_PROG_2 == u8LocalECUConf     ) ||
             ( IMMO_ECU_PROG_3 == u8LocalECUConf     ) )
         {
            u8LocalOutput = E_OK;
         }
         else
         {
            u8LocalOutput = E_NOT_OK;
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
         }
      }
      else if( SRV_CODCHK == SrvType )
      {
         if(   ( IMMO_ECU_PROG_1 == u8LocalECUConf   ) ||
               ( IMMO_ECU_PROG_2 == u8LocalECUConf   ) ||
               ( IMMO_ECU_PROG_3 == u8LocalECUConf   ) ||
               ( IMMO_ECU_PAIRED == u8LocalECUConf   ))
         {
            u8LocalOutput = E_OK;
         }
         else
         {
            u8LocalOutput = E_NOT_OK;
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
         }
      }
      else /* SRV_CODPROG == SrvType */
      {
         if( ( IMMO_ECU_DEVELOPMENT == u8LocalECUConf ) ||
             ( IMMO_ECU_LIVRAISON == u8LocalECUConf   ) ||
             ( IMMO_ECU_PROG_1 == u8LocalECUConf      ) ||
             ( IMMO_ECU_PROG_2 == u8LocalECUConf      ) )
         {
            u8LocalOutput = E_OK;
         }
         else
         {
            u8LocalOutput = E_NOT_OK;
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
         }
      }
   }

   return u8LocalOutput;
}
