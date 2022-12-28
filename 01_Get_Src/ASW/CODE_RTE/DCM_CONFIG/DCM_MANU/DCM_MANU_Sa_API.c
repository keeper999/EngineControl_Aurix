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
/* !File            : DCM_MANU_Sa_API.c                                       */
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
/*   1 / DCM_MANU_GetSeed_SecLevel_2                                          */
/*   2 / DCM_MANU_CompareKey_SecLevel_2                                       */
/*   3 / DCM_MANU_SecurityAcessReqInit                                        */
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
/* !Function    :  DCM_MANU_GetSeed_SecLevel_2                                */
/* !Description :  Fonction appelée dans le DCM sur événement SA $27 $03      */
/* !Number      :  Sa_API.1                                                   */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_R_11_02667_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf argret Std_ReturnType  DCM_MANU_CheckVehicleCondition(argout         */
/* Dcm_NegativeResponseCodeType *ErrorCode);                                  */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void RND_vidReadRandomNumber( argio uint32 *                  */
/* pu32RandomNumber);                                                         */
/*  extf argret void DCM_MANU_SrvEveSa();                                     */
/*  input uint8 Tele_program_nb;                                              */
/*  input boolean Srv_bPostEquDone;                                           */
/*  input st57 Srv_stTeleEcuStatus;                                           */
/*  input uint8 Srv_stPostEquEcuStatus;                                       */
/*  input bool SRV_TELEECU_WAIT;                                              */
/*  input bool SRV_TELEECU_NEEDACCESS;                                        */
/*  input bool SRV_TELEACCESS_REQ_NOK;                                        */
/*  input st58 Srv_stTeleAccessStatus;                                        */
/*  input bool SRV_TELEACCESS_TELE_ENABLE;                                    */
/*  input bool SRV_TELEACCESS_REQ_OK;                                         */
/*  input uint32 DCM_MANU_TeleSaSeed;                                         */
/*  output st58 Srv_stTeleAccessStatus;                                       */
/*  output bool SRV_TELEACCESS_REQ_NOK;                                       */
/*  output uint32 DCM_MANU_TeleSaSeed;                                        */
/*  output bool SRV_TELEACCESS_REQ_OK;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_GetSeed_SecLevel_2
(
   uint8* SecurityAccessDataRecord,
   Dcm_OpStatusType OpStatus,
   uint8* pau8Seed,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   Std_ReturnType                u8localreturn;
   uint8                         u8Tele_program_nb;
   uint8                         u8LocalSrv_stTeleAccessStatus;
   Dcm_NegativeResponseCodeType  u8LocalError;
   uint8                         u8LocalSrv_stTeleEcuStatus;
   uint8                         u8LocalSrv_stPostEquEcuStatus;
   boolean                       bLocalSrv_bPostEquDone;

   /* Test des conditions ADC */
   u8localreturn = DCM_MANU_CheckADCCondition(SRV_LAMBDA,&u8LocalError);
   if( E_NOT_OK != u8localreturn )
   {
      /* Test des conditions liées à l'état du véhicule */
      u8localreturn = DCM_MANU_CheckVehicleCondition(&u8LocalError);
      if( E_NOT_OK != u8localreturn )
      {
         VEMS_vidGET(Tele_program_nb, u8Tele_program_nb);
         VEMS_vidGET(Srv_bPostEquDone, bLocalSrv_bPostEquDone);
         VEMS_vidGET(Srv_stTeleEcuStatus, u8LocalSrv_stTeleEcuStatus);
         VEMS_vidGET(Srv_stPostEquEcuStatus, u8LocalSrv_stPostEquEcuStatus);

         if(   (  ( (u8LocalSrv_stTeleEcuStatus != SRV_TELEECU_WAIT)
                     || (u8Tele_program_nb != 0)
                  )
                  && (u8LocalSrv_stTeleEcuStatus != SRV_TELEECU_NEEDACCESS)
               )
               && (  ( (u8LocalSrv_stPostEquEcuStatus != SRV_POSTEQUECU_WAIT)
                     || (bLocalSrv_bPostEquDone != 0)
                  )
                  && (u8LocalSrv_stPostEquEcuStatus !=
                                                      SRV_POSTEQUECU_NEEDACCESS)
               )
         )
         {
            VEMS_vidSET(Srv_stTeleAccessStatus, SRV_TELEACCESS_REQ_NOK);
            /* Envoi d’une réponse négative nack $22 gérée par le DCM */
            u8LocalError = DCM_E_CONDITIONSNOTCORRECT;
            u8localreturn = E_NOT_OK;
         }
         else
         {
            VEMS_vidGET(Srv_stTeleAccessStatus,
                        u8LocalSrv_stTeleAccessStatus);

            if(u8LocalSrv_stTeleAccessStatus == SRV_TELEACCESS_TELE_ENABLE)
            {
               /* L’ECU est déjà déverrouillé, la graine renvoyée vaut 0 */
               pau8Seed[0] = 0x00;
               pau8Seed[1] = 0x00;
               pau8Seed[2] = 0x00;
               pau8Seed[3] = 0x00;
               DCM_MANU_TeleSaSeed = 0;
               u8localreturn = E_OK;
            }
            else
            {
               VEMS_vidSET(Srv_stTeleAccessStatus, SRV_TELEACCESS_REQ_OK);
               /* Utilisation de l'API RND_vidReadrandomNumber pour
               le calcul de la graine */
               RND_vidReadRandomNumber(&DCM_MANU_TeleSaSeed);
               /* Envoi de la réponse positive $67 $03 $xxxxxxxx
               gérée par le DCM */
               pau8Seed[0] =
                  (uint8)((DCM_MANU_TeleSaSeed & 0xFF000000UL) >> 24);
               pau8Seed[1] =
                  (uint8)((DCM_MANU_TeleSaSeed & 0x00FF0000UL) >> 16);
               pau8Seed[2] =
                  (uint8)((DCM_MANU_TeleSaSeed & 0x0000FF00UL) >> 8);
               pau8Seed[3] =
                  (uint8)((DCM_MANU_TeleSaSeed & 0x000000FFUL));

               u8localreturn = E_OK;
            }
         }
      }
   }

   DCM_MANU_SrvEveSa(); /* Srv_EveSa_TeleSrv(); */

   *ErrorCode = u8LocalError;

   return u8localreturn;
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CompareKey_SecLevel_2                             */
/* !Description :  Function appelée dans le DCM sur l'événement SA $27 $04    */
/* !Number      :  Sa_API.2                                                   */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_R_11_02667_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret uint8  SUPSRV_u8UnlockAlgorithm(argin uint8 *pau8Seed, argin  */
/* uint8 u8SeedSize, argout uint8 *pau8UnlockKey);                            */
/*  extf argret void DCM_MANU_SrvEveSa();                                     */
/*  input st57 Srv_stTeleEcuStatus;                                           */
/*  input uint8 Srv_stPostEquEcuStatus;                                       */
/*  input bool SRV_TELEECU_SEED;                                              */
/*  input bool SRV_TELEECU_WAIT;                                              */
/*  input bool SRV_TELEACCESS_REQ_NOK;                                        */
/*  input uint32 DCM_MANU_TeleSaSeed;                                         */
/*  input uint32 DCM_MANU_SaCalcKeyAdr;                                       */
/*  input uint16 AppliKey;                                                    */
/*  input boolean Srv_bTeleSASeedInh_C;                                       */
/*  input boolean Srv_bTeleSAOkInh_C;                                         */
/*  input bool SRV_TELEACCESS_TELE_ENABLE;                                    */
/*  output st58 Srv_stTeleAccessStatus;                                       */
/*  output bool SRV_TELEACCESS_REQ_NOK;                                       */
/*  output bool SRV_TELEACCESS_TELE_ENABLE;                                   */
/*  output boolean DCM_MANU_bSaEnable;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_CompareKey_SecLevel_2
(
   uint8* Key,
   Dcm_OpStatusType OpStatus
)
{
   Std_ReturnType                u8localreturn;
   uint8                         u8LocalKeySize;
   uint32                        u32LocalSaReceivedKey;
   uint16                        u16LocalAppliKey;
   uint8                         u8LocalSrv_stTeleEcuStatus;
   uint8                         u8LocalSrv_stPostEquEcuStatus;

   VEMS_vidGET(Srv_stTeleEcuStatus, u8LocalSrv_stTeleEcuStatus);
   VEMS_vidGET(Srv_stPostEquEcuStatus, u8LocalSrv_stPostEquEcuStatus);

   if(   (  ( u8LocalSrv_stTeleEcuStatus != SRV_TELEECU_SEED )
            &&  ( u8LocalSrv_stTeleEcuStatus != SRV_TELEECU_WAIT )
         )
         &&
         (  ( u8LocalSrv_stPostEquEcuStatus != SRV_POSTEQUECU_SEED )
            &&  ( u8LocalSrv_stPostEquEcuStatus != SRV_POSTEQUECU_WAIT )
         )
    )
   {
      u8localreturn = E_NOT_OK;
      VEMS_vidSET(Srv_stTeleAccessStatus, SRV_TELEACCESS_REQ_NOK);
   }
   else
   {
      u8LocalKeySize =
         SUPSRV_u8UnlockAlgorithm( (uint8 *)&DCM_MANU_TeleSaSeed,
                                   4,
                                   (uint8 *)&DCM_MANU_SaCalcKeyAdr);

      u32LocalSaReceivedKey = (   (uint32)(Key[3])
                               + ((uint32)(Key[2]) << 8)
                               + ((uint32)(Key[1]) << 16)
                               + ((uint32)(Key[0]) << 24));

     VEMS_vidGET(AppliKey, u16LocalAppliKey);

      if (  ((0!=u8LocalKeySize)
            && (u32LocalSaReceivedKey == *(uint32 *)DCM_MANU_SaCalcKeyAdr))
            || (u16LocalAppliKey == 65535)
            || ((Srv_bTeleSASeedInh_C != 0)
            && (Srv_bTeleSAOkInh_C == 0))
      )
      {
         /* envoi de la réponse positive nack $35 gérée par le DCM */
         u8localreturn = E_OK;
         VEMS_vidSET(Srv_stTeleAccessStatus, SRV_TELEACCESS_TELE_ENABLE);
         DCM_MANU_bSaEnable = TRUE;
      }
      else
      {
         u8localreturn = E_COMPARE_KEY_FAILED;
         VEMS_vidSET(Srv_stTeleAccessStatus, SRV_TELEACCESS_REQ_NOK);
      }
   }

   DCM_MANU_SrvEveSa(); /* Srv_EveSa_TeleSrv(); */

   return u8localreturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_SecurityAcessReqInit                              */
/* !Description :  Fonction gérant l'initialisationdu SA                      */
/* !Number      :  Sa_API.3                                                   */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_R_11_02667_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SECUR_vidInit(const uint16 AppliKey, const uint32        */
/* SeedRead, const uint32 SeedWrite);                                         */
/*  input bool SRV_TELEACCESS_IDLE;                                           */
/*  input uint16 AppliKey;                                                    */
/*  input ???? NOPROD_PointeurFonctionNull;                                   */
/*  output st58 Srv_stTeleAccessStatus;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_SecurityAcessReqInit(void)
{
   uint16 u16LocalAppliKey;

   Srv_stTeleAccessStatus = SRV_TELEACCESS_IDLE;
   VEMS_vidGET(AppliKey, u16LocalAppliKey);
   SECUR_vidInit(u16LocalAppliKey,
                 (uint32)NOPROD_PointeurFonctionNull,
                 (uint32)NOPROD_PointeurFonctionNull);
/* QAC Warnings (0428, 0305): Due to a bad prototype of the LDB function to
   use function pointer */
}