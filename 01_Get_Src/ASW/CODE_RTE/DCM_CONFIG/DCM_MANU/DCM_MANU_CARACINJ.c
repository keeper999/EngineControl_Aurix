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
/* !File            : DCM_MANU_CARACINJ.C                                     */
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
/*   1 / DCM_MANU_CaracInjWriteReqInit                                        */
/*   2 / DCM_MANU_WriteCaracInj                                               */
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
/* !Function    :  DCM_MANU_CaracInjWriteReqInit                              */
/* !Description :  Fonction appelée pour initialiser les données liées à      */
/*                 l'écriture de la caractérisation des injecteurs.           */
/* !Number      :  CARACINJ.1                                                 */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  output uint8 Srv_prm_IdChrnInjr[2];                                       */
/*  output uint8 Srv_ctInjrChrnWrSt;                                          */
/*  output uint8 Srv_stInjrChrnGetSt;                                         */
/*  output uint8 Srv_stInjrChrnWrChck;                                        */
/*  output uint8 Srv_stInjrChrnWrSt;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_CaracInjWriteReqInit(void)
{
   uint32 index;
   uint8  tabLocal[DCM_MANU_SRV_PRM_IDCHRNINJR_SIZE];

   for( index = 0 ; index < (uint32)DCM_MANU_SRV_PRM_IDCHRNINJR_SIZE ; index++ )
   {
      tabLocal[index] = 0xFF;
   }

   VEMS_vidSET1DArray( Srv_prm_IdChrnInjr,
                       (uint32)DCM_MANU_SRV_PRM_IDCHRNINJR_SIZE,tabLocal);

   Srv_ctInjrChrnWrSt = 0;
   Srv_stInjrChrnGetSt = 0;
   Srv_stInjrChrnWrChck = WAIT_WRITING;
   Srv_stInjrChrnWrSt = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_WriteCaracInj                                     */
/* !Description :  Fonction appelée sur réception de la requête d'écriture de */
/*                 la caractérisation des injecteurs.                         */
/* !Number      :  CARACINJ.2                                                 */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_R_11_02667_014.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf argret Std_ReturnType  DCM_MANU_CheckVehicleCondition(argout         */
/* Dcm_NegativeResponseCodeType *ErrorCode);                                  */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  extf argret void Srv_EveInjrChrn_InjrChrn();                              */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void Srv_EveErrInjrChrnWr_InjrChrn();                         */
/*  extf argret uint8  NVMSRV_u8WriteStatus(argin NVMSRV_tudtObjectList       */
/* udtObject);                                                                */
/*  extf argret uint8  NVMSRV_u8GetStatus(argin NVMSRV_tudtObjectList         */
/* udtObject);                                                                */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf argret void DCM_MANU_CaracInjWriteReqInit();                         */
/*  input uint8 Srv_InjrChrnDataSize_C;                                       */
/*  input st77 Srv_stInjrChrnEcuStatus;                                       */
/*  input uint8 Srv_stInjrChrnWrChck;                                         */
/*  input uint8 Srv_ctInjrChrnWrSt;                                           */
/*  input uint8 Srv_ctInjrChrnWrSt_C;                                         */
/*  input uint8 Srv_stInjrChrnWrSt;                                           */
/*  input uint8 Srv_stInjrChrnGetSt;                                          */
/*  output uint8 Srv_prm_IdChrnInjr[2];                                       */
/*  output uint8 Srv_InjrChrnDataSize_C;                                      */
/*  output uint8 Srv_stInjrChrnWrChck;                                        */
/*  output uint8 Srv_ctInjrChrnWrSt;                                          */
/*  output uint8 Srv_stInjrChrnWrSt;                                          */
/*  output uint8 Srv_stInjrChrnGetSt;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_WriteCaracInj
(
   uint8* Data_in,
   uint16 DataLength_in,
   Dcm_OpStatusType OpStatus_in,
   Dcm_NegativeResponseCodeType* ErrorCode_out
)
{
   Std_ReturnType                u8localreturn;
   Std_ReturnType                u8localtmp;
   Dcm_NegativeResponseCodeType  LocalErrorTmp;
   uint8                         u8LocalstInjrChEcuStat;

   if( DCM_INITIAL == OpStatus_in )
   {
      /* Le tableau Srv_prm_IdChrnInjr est de taille
      DCM_MANU_SRV_PRM_IDCHRNINJR_SIZE dans le soft,
      on ne peut donc pas écrire plus de donnée. */
      if( ( DataLength_in != Srv_InjrChrnDataSize_C          ) ||
          ( DataLength_in > DCM_MANU_SRV_PRM_IDCHRNINJR_SIZE ) )
      {
         /* incorrectMessageLengthOrInvalidFormat */
         LocalErrorTmp = DCM_E_INCORRECTLENGTH;
         u8localreturn = E_NOT_OK;
      }
      else
      {
         /* Test des conditions ADC */
         u8localtmp = DCM_MANU_CheckADCCondition(SRV_LAMBDA, &LocalErrorTmp);
         if( E_OK == u8localtmp )
         {
            /* Si les conditions sont bonnes */
            u8localtmp = DCM_MANU_CheckVehicleCondition(&LocalErrorTmp);
            if( E_OK == u8localtmp )
            {
               VEMS_vidSET1DArray(Srv_prm_IdChrnInjr,
                  (uint8)(Srv_InjrChrnDataSize_C),Data_in);
               /* Initilisation de l’automate Srv_stInjrChrnWrChck */
               Srv_stInjrChrnWrChck = WAIT_WRITING;
               /* Initialisation du fonctionnel d’écriture  */
               Srv_EveInjrChrn_InjrChrn();
               /* Fin du premier appel, l’écriture est lancée et le DCM
               rend la main */
               Srv_ctInjrChrnWrSt = 0;
               u8localreturn = E_PENDING;
               /* Initialisation du code d'erreur à 0 mais il ne sera
               pas utilisé par le DCM */
               LocalErrorTmp = 0x00;
            }
            else
            {
               /* Mauvaises conditions véhicule */
               u8localreturn = u8localtmp;
               /* LocalErrorTmp est déjà initialisé */
            }
         }
         else
         {
            /* Mauvaises conditions liées à l'ADC */
            u8localreturn = u8localtmp;
            /* LocalErrorTmp est déjà initialisé */
         }
      }
   }
   else if( DCM_PENDING == OpStatus_in )
   {
      VEMS_vidGET(Srv_stInjrChrnEcuStatus, u8LocalstInjrChEcuStat);
      switch( Srv_stInjrChrnWrChck )
      {
         case WAIT_WRITING:
         if( SRV_INJRCHRNECU_WRITE == u8LocalstInjrChEcuStat )
         {
            Srv_stInjrChrnWrChck = WAIT_WRITE_STATUS;
            /* Initialisation du compteur */
            Srv_ctInjrChrnWrSt = 0;
            u8localreturn = E_PENDING;
            /* Initialisation du code d'erreur à 0 mais il ne sera
            pas utilisé par le DCM */
            LocalErrorTmp = 0x00;
         }
         else if( SRV_INJRCHRNECU_DATANOK == u8LocalstInjrChEcuStat )
         {
            /* requestOutOfRange */
            LocalErrorTmp = DCM_E_REQUESTOUTOFRANGE;
            u8localreturn = E_NOT_OK;
         }
         else
         {
            Srv_ctInjrChrnWrSt = (uint8)(Srv_ctInjrChrnWrSt + 1);
            if(Srv_ctInjrChrnWrSt >= Srv_ctInjrChrnWrSt_C)
            {
               /* generalProgrammingFailure */
               LocalErrorTmp = DCM_E_GENERALPROGRAMMINGFAILURE;
               u8localreturn = E_NOT_OK;
               Srv_EveErrInjrChrnWr_InjrChrn();
            }
            else
            {
               u8localreturn = E_PENDING;
               /* Initialisation du code d'erreur à 0 mais il ne sera
               pas utilisé par le DCM */
               LocalErrorTmp = 0x00;
            }
         }
         break;

         case  WAIT_WRITE_STATUS:
         Srv_stInjrChrnWrSt = NVMSRV_u8WriteStatus(NVMSRV_udtOBJ_INJRCHRN);
         if( NVMSRV_u8OK == Srv_stInjrChrnWrSt )
         {
            Srv_stInjrChrnWrChck = WAIT_GET_STATUS;
            u8localreturn = E_PENDING;
            /* Initialisation du code d'erreur à 0 mais il ne sera
            pas utilisé par le DCM */
            LocalErrorTmp = 0x00;
         }
         else
         {
            Srv_ctInjrChrnWrSt++;
            if( Srv_ctInjrChrnWrSt >= Srv_ctInjrChrnWrSt_C )
            {
               /* generalProgrammingFailure */
               LocalErrorTmp = DCM_E_GENERALPROGRAMMINGFAILURE;
               u8localreturn = E_NOT_OK;
               Srv_EveErrInjrChrnWr_InjrChrn();
            }
            else
            {
               u8localreturn = E_PENDING;
               /* Initialisation du code d'erreur à 0 mais il ne sera
               pas utilisé par le DCM */
               LocalErrorTmp = 0x00;
            }
         }
         break;

         case WAIT_GET_STATUS:
         Srv_stInjrChrnGetSt = NVMSRV_u8GetStatus(NVMSRV_udtOBJ_INJRCHRN);
         if( NVMSRV_u8OK == Srv_stInjrChrnGetSt )
         {
            /* L’écriture s’est correctement effectué */
            u8localreturn = E_OK;
            /* Initialisation du code d'erreur à 0 mais il ne sera
            pas utilisé par le DCM */
            LocalErrorTmp = 0x00;
         }
         else
         {
            /* generalProgrammingFailure */
            LocalErrorTmp = DCM_E_GENERALPROGRAMMINGFAILURE;
            u8localreturn = E_NOT_OK;
            Srv_EveErrInjrChrnWr_InjrChrn();
         }
         break;

         default:
         SWFAIL_vidSoftwareErrorHook();
         u8localreturn = E_NOT_OK;
         /* generalReject */
         LocalErrorTmp = DCM_E_GENERALREJECT;
         break;
      }
   }
   else if( DCM_CANCEL == OpStatus_in )
   {
      DCM_MANU_CaracInjWriteReqInit();
      u8localreturn = E_OK;
      /* Initialisation du code d'erreur à 0 mais il ne sera
      pas utilisé par le DCM */
      LocalErrorTmp = 0x00;
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
      u8localreturn = E_NOT_OK;
      /* generalReject */
      LocalErrorTmp = DCM_E_GENERALREJECT;
   }

   *ErrorCode_out = LocalErrorTmp;
   return u8localreturn;
}
