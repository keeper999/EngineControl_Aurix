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
/* !File            : DCM_MANU_TELECODAGE.C                                   */
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
/*   1 / DCM_MANU_TelecodageWriteReqInit                                      */
/*   2 / DCM_MANU_WriteTelecodageMngt                                         */
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
/* !Function    :  DCM_MANU_TelecodageWriteReqInit                            */
/* !Description :  Fonction initialisant le Télécodage                        */
/* !Number      :  TELECODAGE.1                                               */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  input bool SRV_TELEACCESS_TELE_ENABLE;                                    */
/*  output st58 Srv_stTeleAccessStatus;                                       */
/*  output bool SRV_TELEACCESS_TELE_ENABLE;                                   */
/*  output boolean Srv_bTeleWrChck;                                           */
/*  output uint8 Tele_program_raw_data[11];                                   */
/*  output uint8 Srv_ctTeleWrSt;                                              */
/*  output uint8 Srv_stTeleWrChck;                                            */
/*  output uint8 Srv_stTeleWrSt;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DCM_MANU_TelecodageWriteReqInit(void)
{
   uint32 u8LocalIdx;
   uint8  tabLocal[DCM_MANU_TELE_PROGRAM_RAW_DATA_SIZE];

   VEMS_vidSET(Srv_stTeleAccessStatus, SRV_TELEACCESS_TELE_ENABLE);
   VEMS_vidSET(Srv_bTeleWrChck, TRUE);

   for( u8LocalIdx = 0;
        u8LocalIdx < (uint32)DCM_MANU_TELE_PROGRAM_RAW_DATA_SIZE;
        u8LocalIdx++ )
   {
      tabLocal[u8LocalIdx] = 0xFF;
   }

   VEMS_vidSET1DArray( Tele_program_raw_data,
                      (uint32)DCM_MANU_TELE_PROGRAM_RAW_DATA_SIZE,tabLocal);
   Srv_ctTeleWrSt = 0;
   Srv_stTeleWrChck = WAIT_WRITING;
   Srv_stTeleWrSt = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_WriteTelecodageMngt                               */
/* !Description :  Fonction gérant l'écriture du Télécodage                   */
/* !Number      :  TELECODAGE.2                                               */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_R_11_02667_012.01                                     */
/*                 VEMS_E_11_02667_020.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/* SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                  */
/*  extf argret Std_ReturnType  DCM_MANU_CheckVehicleCondition(argout         */
/* Dcm_NegativeResponseCodeType *ErrorCode);                                  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  extf argret void DCM_MANU_SrvEveTele();                                   */
/*  extf argret uint8  NVMSRV_u8WriteStatus(argin NVMSRV_tudtObjectList       */
/* udtObject);                                                                */
/*  extf argret void DCM_MANU_EveErrTeleWr();                                 */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf argret void DCM_MANU_TelecodageWriteReqInit();                       */
/*  input st57 Srv_stTeleEcuStatus;                                           */
/*  input uint8 Tele_program_nb;                                              */
/*  input uint8 Srv_TeleDataSize_C;                                           */
/*  input bool SRV_TELEECU_WAIT;                                              */
/*  input bool SRV_TELEACCESS_PRGM;                                           */
/*  input uint8 Srv_stTeleWrChck;                                             */
/*  input bool SRV_TELEECU_WRITE;                                             */
/*  input bool SRV_TELEECU_DATANOK;                                           */
/*  input boolean DCM_MANU_bSaEnable;                                         */
/*  input bool SRV_TELEACCESS_IDLE;                                           */
/*  input bool SRV_TELEACCESS_TELE_ENABLE;                                    */
/*  input uint8 Srv_stTeleWrSt;                                               */
/*  input uint8 Srv_ctTeleWrSt;                                               */
/*  input uint8 Srv_ctTeleWrSt_C;                                             */
/*  output st58 Srv_stTeleAccessStatus;                                       */
/*  output bool SRV_TELEACCESS_PRGM;                                          */
/*  output uint8 Tele_program_raw_data[11];                                   */
/*  output uint8 Srv_TeleDataSize_C;                                          */
/*  output boolean Srv_bTeleWrChck;                                           */
/*  output uint8 Srv_stTeleWrChck;                                            */
/*  output uint8 Srv_ctTeleWrSt;                                              */
/*  output bool SRV_TELEACCESS_IDLE;                                          */
/*  output bool SRV_TELEACCESS_TELE_ENABLE;                                   */
/*  output uint8 Srv_stTeleWrSt;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_WriteTelecodageMngt
(
   uint8* Data_in,
   uint16 DataLength_in,
   Dcm_OpStatusType OpStatus_in,
   Dcm_NegativeResponseCodeType* ErrorCode_out
)
{
   uint8                         u8LocalSrv_stTeleEcuStatus;
   uint8                         u8Tele_program_nb;
   Dcm_NegativeResponseCodeType  LocalErrorCode;
   Std_ReturnType                u8localreturn;
   Std_ReturnType                u8localtmp;

   VEMS_vidGET(Srv_stTeleEcuStatus, u8LocalSrv_stTeleEcuStatus);
   VEMS_vidGET(Tele_program_nb, u8Tele_program_nb);

   /* premier appel par le DCM */
   if( DCM_INITIAL == OpStatus_in )
   {
      if( ( DataLength_in != (uint16)Srv_TeleDataSize_C         ) ||
          ( DataLength_in > DCM_MANU_TELE_PROGRAM_RAW_DATA_SIZE ) )
      {
         /* incorrectMessageLengthOrInvalidFormat */
         LocalErrorCode = DCM_E_INCORRECTLENGTH;
         u8localreturn = E_NOT_OK;
      }
      else
      {
         if(u8LocalSrv_stTeleEcuStatus != SRV_TELEECU_WAIT)
         {
            /* securityAccessDenied */
            LocalErrorCode = DCM_E_SECURITYACCESSDENIED;
            u8localreturn = E_NOT_OK;
         }
         else
         {
            /* Test des conditions ADC */
            u8localtmp = DCM_MANU_CheckADCCondition(SRV_LAMBDA,&LocalErrorCode);
            if( E_OK == u8localtmp )
            {
               /* Si les conditions sont bonnes */
               u8localtmp = DCM_MANU_CheckVehicleCondition(&LocalErrorCode);
               if( E_OK == u8localtmp )
               {
                  VEMS_vidSET(Srv_stTeleAccessStatus,
                  SRV_TELEACCESS_PRGM);

                  VEMS_vidSET1DArray(Tele_program_raw_data,
                     (uint8)(Srv_TeleDataSize_C),Data_in);

                  /* Changement du check */
                  VEMS_vidSET(Srv_bTeleWrChck, FALSE);

                  /* Initialisation de l'automate Srv_stTeleWrChck */
                  Srv_stTeleWrChck = WAIT_WRITING;

                  /* Initialisation du fonctionnel telecodage */
                  /* Appel de la fonction de gestion de configuration */
                  /* Interfaçage des variables de gestion de configuration */
                  DCM_MANU_SrvEveTele();

                  /* Fin du premier appel, le télécodage est lancé et le
                     DCM rend la main */
                  u8localreturn = E_PENDING;

                  /* Initialisation du code d'erreur à 0 mais il ne sera
                  pas utilisé par le DCM */
                  LocalErrorCode = 0x00;
               }
               else
               {
                  /* Mauvaises conditions vehicule */
                  u8localreturn = u8localtmp;
                  /* LocalErrorCode = 0xXX */
               }
            }
            else
            {
               /* Mauvaises conditions ADC */
               u8localreturn = u8localtmp;
               /* LocalErrorCode = 0xXX */
            }
         }
      }
   }
   /* poursuite de l'action en cours suite main rendu par DCM à la cam */
   else if( DCM_PENDING == OpStatus_in )
   {
      switch( Srv_stTeleWrChck )
      {
         /* Cet état teste si la fonction télécodage a lancé l'écriture des
         données */
         case WAIT_WRITING:
         /* test de l'état de la fonction télécodage */
         if( SRV_TELEECU_WRITE == u8LocalSrv_stTeleEcuStatus )
         {
            /* l’étape suivante est la vérification de la fin d’écriture */
            Srv_stTeleWrChck = WAIT_WRITE_STATUS;
            /* Initialisation du compteur pour tester la fin d’écriture */
            Srv_ctTeleWrSt = 0;
            /* La fonction télécodage n’est plus bloquée en writing */
            VEMS_vidSET(Srv_bTeleWrChck, TRUE);
            /* Le DCM rend la main avant de passer dans l’état suivant */
            u8localreturn = E_PENDING;
            /* Initialisation du code d'erreur à 0 mais il ne sera
            pas utilisé par le DCM */
            LocalErrorCode = 0x00;
         }
         else
         {
            if( SRV_TELEECU_DATANOK == u8LocalSrv_stTeleEcuStatus )
            {
               /* requestOutOfRange */
               LocalErrorCode = DCM_E_REQUESTOUTOFRANGE;
               u8localreturn = E_NOT_OK;
               VEMS_vidSET(Srv_bTeleWrChck, TRUE);

               if(DCM_MANU_bSaEnable == FALSE)
               {
                  if(u8Tele_program_nb == 0)
                  {
                     VEMS_vidSET(Srv_stTeleAccessStatus, SRV_TELEACCESS_IDLE);
                  }
                  else
                  {
                     VEMS_vidSET(Srv_stTeleAccessStatus,
                                                   SRV_TELEACCESS_TELE_ENABLE);
                  }
               }
               else
               {
                  VEMS_vidSET(Srv_stTeleAccessStatus,
                                                   SRV_TELEACCESS_TELE_ENABLE);
               }
            }
            else
            {
               /* La fonction télécodage n’est pas dans un état final
               d’écriture */
               u8localreturn = E_PENDING;
               /* Initialisation du code d'erreur à 0 mais il ne sera
               pas utilisé par le DCM */
               LocalErrorCode = 0x00;
            }
         }
         break;

         /* Cet état teste si l’écriture en eeprom a pu se terminer */
         case WAIT_WRITE_STATUS:
         Srv_stTeleWrSt = NVMSRV_u8WriteStatus(NVMSRV_udtOBJ_TELECODAGE);
         if( NVMSRV_u8OK == Srv_stTeleWrSt )
         {
            /* L’écriture est terminée */
            Srv_stTeleWrChck = WAIT_GET_STATUS;
            u8localreturn = E_PENDING;
            /* Initialisation du code d'erreur à 0 mais il ne sera
            pas utilisé par le DCM */
            LocalErrorCode = 0x00;
         }
         else
         {
            /* délai d'écriture dépassé, renvoi réponse NACK $72 à l’outil */
            if (Srv_ctTeleWrSt < 255)
            {
               Srv_ctTeleWrSt = (uint8)(Srv_ctTeleWrSt + 1);
            }
            else
            {
               Srv_ctTeleWrSt = Srv_ctTeleWrSt_C;
            }

            if( Srv_ctTeleWrSt >= Srv_ctTeleWrSt_C )
            {
               LocalErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
               u8localreturn = E_NOT_OK;
               /* Evénement pour informer que l'écriture s'est mal passée */
               DCM_MANU_EveErrTeleWr(); /*Srv_EveErrTeleWr_TeleSrv();*/

               if(DCM_MANU_bSaEnable == FALSE)
               {
                  if(u8Tele_program_nb == 0)
                  {
                     VEMS_vidSET(Srv_stTeleAccessStatus, SRV_TELEACCESS_IDLE);
                  }
                  else
                  {
                     VEMS_vidSET(Srv_stTeleAccessStatus,
                                                   SRV_TELEACCESS_TELE_ENABLE);
                  }
               }
               else
               {
                  VEMS_vidSET(Srv_stTeleAccessStatus,
                                                   SRV_TELEACCESS_TELE_ENABLE);
               }
            }
            else
            {
               u8localreturn = E_PENDING;
               /* Initialisation du code d'erreur à 0 mais il ne sera
               pas utilisé par le DCM */
               LocalErrorCode = 0x00;
            }
         }
         break;

         /* Cet état teste si l’écriture en eeprom est correcte */
         case WAIT_GET_STATUS:

         /* Le télécodage s’est correctement effectué
          Envoi de la réponse positive par le DCM */
         u8localreturn = E_OK;
         /* Initialisation du code d'erreur à 0 mais il ne sera
         pas utilisé par le DCM */
         LocalErrorCode = 0x00;

         if(DCM_MANU_bSaEnable == FALSE)
         {
            if((u8Tele_program_nb == 1) || (u8Tele_program_nb == 0))
            {
               VEMS_vidSET(Srv_stTeleAccessStatus, SRV_TELEACCESS_IDLE);
            }
            else
            {
               VEMS_vidSET(Srv_stTeleAccessStatus,
                                                SRV_TELEACCESS_TELE_ENABLE);
            }
         }
         else
         {
            VEMS_vidSET(Srv_stTeleAccessStatus, SRV_TELEACCESS_TELE_ENABLE);
         }
         break;

         default:
         /* Ce cas n'est pas possible */
         SWFAIL_vidSoftwareErrorHook();
         u8localreturn = E_NOT_OK;
         /* generalReject */
         LocalErrorCode = DCM_E_GENERALREJECT;
         break;
      }
   }
   /* Initialisation des variables */
   else if( DCM_CANCEL == OpStatus_in )
   {
      DCM_MANU_TelecodageWriteReqInit();
      u8localreturn = E_OK;
      /* Initialisation du code d'erreur à 0 mais il ne sera
      pas utilisé par le DCM */
      LocalErrorCode = 0x00;
      if(DCM_MANU_bSaEnable == FALSE)
      {
         if(u8Tele_program_nb == 0)
         {
            VEMS_vidSET(Srv_stTeleAccessStatus, SRV_TELEACCESS_IDLE);
         }
         else
         {
            VEMS_vidSET(Srv_stTeleAccessStatus,SRV_TELEACCESS_TELE_ENABLE);
         }
      }
      else
      {
         VEMS_vidSET(Srv_stTeleAccessStatus, SRV_TELEACCESS_TELE_ENABLE);
      }
   }
   else
   {
      /* En théorie, on ne doit pas arriver ici */
      SWFAIL_vidSoftwareErrorHook();
      u8localreturn = E_NOT_OK;
      /* generalReject */
      LocalErrorCode = DCM_E_GENERALREJECT;
   }

   *ErrorCode_out = LocalErrorCode;
   /* QAC Warnings (2:3353: When u8localreturn = E_OK, LocalErrorCode
   can be unset */

   return u8localreturn;
}