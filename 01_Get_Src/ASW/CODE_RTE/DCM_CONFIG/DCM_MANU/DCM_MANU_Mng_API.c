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
/* !File            : DCM_MANU_Mng_API.c                                      */
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
/*   1 / DCM_MANU_StartProtocol                                               */
/*   2 / DCM_MANU_StopProtocol                                                */
/*   3 / DCM_MANU_SupplierIndication                                          */
/*   4 / DCM_MANU_ManufacturerIndication                                      */
/*   5 / DCM_MANU_ManufSupplIndication                                        */
/*   6 / DCM_MANU_CheckFunctionalAvailability                                 */
/*                                                                            */
/* !Reference   : PTS_DOC_5074345 / 4                                         */
/* !Reference   : V02 NT 11 06099 / 3                                         */
/* !OtherRefs   : VEMS V02 ECU#062432                                         */
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

#include "DCM_MANU_FIX.h"

#include "Dcm.h"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_StartProtocol                                     */
/* !Description :  Indication of protocol start. Application is able to reject*/
/*                 further processing of requested protocol due to failed     */
/*                 conditions.                                                */
/* !Number      :  Mng_API.1                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_StartProtocol
(
   Dcm_ProtocolType ProtocolID
)
{
   Std_ReturnType u8localreturn;

   switch( ProtocolID )
   {
      case DCM_UDS_ON_CAN:
      /* UDS communication is allowed */
      u8localreturn = E_OK;
      break;

      case DCM_OBD_ON_CAN:
      /* OBD communication is allowed at this step */
      u8localreturn = E_OK;
      break;

      default:
      /* Other communications are forbidden */
      u8localreturn = E_NOT_OK;
      break;
   }

   return u8localreturn;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_StopProtocol                                      */
/* !Description :  Indication of protocol stop. If a running diagnostic       */
/*                 requested is preempted by a higher prior request (of an    */
/*                 other protocol, e.g. OBD), application is requested to     */
/*                 abort further processing of running request ProtocolID.    */
/* !Number      :  Mng_API.2                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_StopProtocol
(
   Dcm_ProtocolType ProtocolID
)
{
   /* For the Mockup, only UDS is available */
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_SupplierIndication                                */
/* !Description :  The interface ServiceRequestSupplierIndication indicates to*/
/*                 the Supplier Application that a service is about to be     */
/*                 executed and allows the Supplier Application to reject the */
/*                 execution of the service request.                          */
/* !Number      :  Mng_API.3                                                  */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_E_11_02667_017.01                                     */
/*                 VEMS_E_11_02667_016.01                                     */
/*                 VEMS_E_11_02667_018.01                                     */
/*                 VEMS_R_11_02667_001.02                                     */
/*                 VEMS_R_11_02667_005.02                                     */
/*                 VEMS_R_11_02667_006.01                                     */
/*                 VEMS_R_11_02667_008.01                                     */
/*                 VEMS_R_11_02667_009.01                                     */
/*                 VEMS_R_11_02667_010.01                                     */
/*                 VEMS_R_11_02667_011.01                                     */
/*                 VEMS_E_11_02667_019.01                                     */
/*                 VEMS_R_11_02667_002.01                                     */
/*                 VEMS_E_11_02667_022.01                                     */
/*                 VEMS_E_11_02667_021.01                                     */
/*                 VEMS_R_11_02667_004.01                                     */
/*                 VEMS_E_11_02667_015.01                                     */
/*                 VEMS_R_11_02667_003.01                                     */
/*                 VEMS_E_11_02667_025.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckVehicleCondition(argout         */
/*  Dcm_NegativeResponseCodeType *ErrorCode);                                 */
/*  extf argret Std_ReturnType  Dcm_GetSesCtrlType(argout uint8 *Data);       */
/*  extf argret Std_ReturnType  DCM_MANU_CheckChangeSessionSWCcondition(argin */
/* uint8 SesCtrlType, argin uint8 RequestedMode, argin                        */
/* Dcm_NegativeResponseCodeType *ErrorCode);                                  */
/*  extf argret void DCM_MANU_vidChgSesType();                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_SupplierIndication
(
   uint8 SID,
   uint8* RequestData,
   uint16 DataSize,
   uint8 ReqType,
   uint8 DcmRxPduId,
   uint8* ErrorCode
)
{
   uint8          u8LocalError;
   uint8          u8LocalSesCtrlType;
   uint8          u8LocalRequestedMode;

   Std_ReturnType u8localreturn;
   Std_ReturnType LocalDcm_GetSesCtrlType;

   if( ( DCM_RX_PDUID_0 == DcmRxPduId ) ||   /* DCM_UDS_PHYS_TYPE */
       ( DCM_RX_PDUID_1 == DcmRxPduId ) )    /* DCM_UDS_FUNC_TYPE */
   {
      /* DCM_bPSA_SPECIFIC_CONF = TRUE : Le DCM appelle cette fonction
         uniquement si le service dispose d'une sous fonction,
         c'est le cas du service $85 */
      if( DCM_MANU_CONTROLDTCSETTING_SID == SID )
      {
         u8localreturn = DCM_MANU_CheckVehicleCondition(&u8LocalError);
      }
      /* Traitements particulier pour le changement de Session */
      else if( SID == DCM_MANU_CHANGESESSION_SID)
      {
         LocalDcm_GetSesCtrlType = Dcm_GetSesCtrlType(&u8LocalSesCtrlType);
         u8LocalRequestedMode = RequestData[0];

         if(LocalDcm_GetSesCtrlType == E_OK)
         {
            u8localreturn =
                  DCM_MANU_CheckChangeSessionSWCcondition(u8LocalSesCtrlType,
                                          u8LocalRequestedMode,&u8LocalError);
            
            DCM_MANU_vidChgSesType();
         }
         else
         {
            u8localreturn = E_NOT_OK;
            u8LocalError = DCM_E_CONDITIONSNOTCORRECT;
         }
      }
      else
      {
         u8localreturn = E_OK;
         /* Initialisé à 0x00 mais non utilisé par le DCM dans ce cas. */
         u8LocalError = 0x00;
      }
   }
   else /* ( DCM_RX_PDUID_2 == DcmRxPduId ) || DCM_OBD_PHYS_TYPE
           ( DCM_RX_PDUID_3 == DcmRxPduId ) )  DCM_OBD_FUNC_TYPE */
   {
      /* Communication OBD */
      u8localreturn = E_OK;
      /* Initialisé à 0x00 mais non utilisé par le DCM dans ce cas. */
      u8LocalError = 0x00;
   }

   *ErrorCode = u8LocalError;
   /* QAC Warning 3347: If u8localreturn = E_OK, the return value *ErrorCode
      can be unset */

   return u8localreturn;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_ManufacturerIndication                            */
/* !Description :  The interface ServiceRequestManufacturerIndication         */
/*                 indicates to the Manufacturer Application that a service is*/
/*                 about to be executed and allows the Manufacturer           */
/*                 Application to reject the execution of the service request.*/
/* !Number      :  Mng_API.4                                                  */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_E_11_02667_015.01                                     */
/*                 VEMS_R_11_02667_003.01                                     */
/*                 VEMS_E_11_02667_017.01                                     */
/*                 VEMS_E_11_02667_016.01                                     */
/*                 VEMS_E_11_02667_018.01                                     */
/*                 VEMS_R_11_02667_001.02                                     */
/*                 VEMS_R_11_02667_005.02                                     */
/*                 VEMS_R_11_02667_006.01                                     */
/*                 VEMS_R_11_02667_008.01                                     */
/*                 VEMS_R_11_02667_009.01                                     */
/*                 VEMS_R_11_02667_010.01                                     */
/*                 VEMS_R_11_02667_011.01                                     */
/*                 VEMS_E_11_02667_019.01                                     */
/*                 VEMS_E_11_02667_021.01                                     */
/*                 VEMS_E_11_02667_022.01                                     */
/*                 VEMS_R_11_02667_002.01                                     */
/*                 VEMS_R_11_02667_004.01                                     */
/*                 VEMS_E_11_02667_025.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Clef_de_contact;                                            */
/*  input boolean Srv_bManuInhOBD_C;                                          */
/*  input uint8 Srv_bfMod9InfTypAvl_C;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_ManufacturerIndication
(
   uint8 SID,
   uint8* RequestData,
   uint16 DataSize,
   uint8 ReqType,
   uint8 DcmRxPduId,
   uint8* ErrorCode
)
{
   uint8          u8LocalError;
   uint8          u8LocalInftyp;
   Std_ReturnType u8localreturn;
   boolean        bLocalCleContact;

   VEMS_vidGET(Clef_de_contact, bLocalCleContact);

   if(bLocalCleContact != 0)
   {
      if( ( DCM_RX_PDUID_0 == DcmRxPduId ) ||   /* DCM_UDS_PHYS_TYPE */
          ( DCM_RX_PDUID_1 == DcmRxPduId ) )    /* DCM_UDS_FUNC_TYPE */
      {
         /* Les services UDS passent */
         u8LocalError = 0x00;
         u8localreturn = E_OK;
      }
      else if( ( DCM_RX_PDUID_2 == DcmRxPduId ) ||   /* DCM_OBD_PHYS_TYPE */
               ( DCM_RX_PDUID_3 == DcmRxPduId ) )    /* DCM_OBD_FUNC_TYPE */
      {
         if( FALSE == Srv_bManuInhOBD_C )
         {
            /* Tests particuliers pour le service09 */
            if( DCM_MANU_OBDSRV09_SID == SID)
            {
               u8LocalInftyp = RequestData[0];
               if( ( u8LocalInftyp == DCM_MANU_OBDSRV09_INFTYP_02)
                  && ((Srv_bfMod9InfTypAvl_C & 0x40) == 0x40)
                  )
               {
                  /* Le service OBDSRV09_INFTYP_02 passe */
                  u8LocalError = 0x00;
                  u8localreturn = E_OK;
               }
               else if( ( u8LocalInftyp == DCM_MANU_OBDSRV09_INFTYP_04)
                  && ((Srv_bfMod9InfTypAvl_C & 0x10) == 0x10)
                  )
               {
                  /* Le service OBDSRV09_INFTYP_04 passe */
                  u8LocalError = 0x00;
                  u8localreturn = E_OK;
               }
               else if( ( u8LocalInftyp == DCM_MANU_OBDSRV09_INFTYP_08)
                  && ((Srv_bfMod9InfTypAvl_C & 0x01) == 0x01)
                  )
               {
                   /* Le service OBDSRV09_INFTYP_08 passe */
                  u8LocalError = 0x00;
                  u8localreturn = E_OK;
               }
               else if(( u8LocalInftyp == DCM_MANU_OBDSRV09_INFTYP_00))
               {
                  /* Le service OBDSRV09_INFTYP_00 passe
                   dans tout cas de la calib Srv_bfMod9InfTypAvl_C */
                  u8LocalError = 0x00;
                  u8localreturn = E_OK;
               }
               else
               {
                  /* L'OBDSRV09_INFTYP_XX ne passe pas */
                  u8LocalError = 0x00;
                  u8localreturn = E_REQUEST_NOT_ACCEPTED;
               }
            }
            else
            {
               /* Les services OBD passent */
               u8LocalError = 0x00;
               u8localreturn = E_OK;
            }
         }
         else
         {
            /* Les services OBD ne passent pas. Le DCM ne répond pas */
            u8LocalError = 0x00;
            u8localreturn = E_REQUEST_NOT_ACCEPTED;
         }
      }
      else
      {
         /* Problème, la source n'est pas connue */
         u8localreturn = E_NOT_OK;
         u8LocalError = DCM_E_GENERALREJECT;
      }
   }
   else
   {
      /* Aucun service n'est autorisé. Le DCM ne répond pas*/
      u8LocalError = 0x00;
      u8localreturn = E_REQUEST_NOT_ACCEPTED;
   }

   *ErrorCode = u8LocalError;

   return u8localreturn;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_ManufSupplIndication                              */
/* !Description :  The interface ServiceRequestManufSupplIndication indicates */
/*                 to the Manufacturer Application that a service is about to */
/*                 be executed and allows the Manufacturer                    */
/*                 Application to reject the execution of the service request */
/* !Number      :  Mng_API.5                                                  */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_R_11_02667_001.02                                     */
/*                 VEMS_R_11_02667_005.02                                     */
/*                 VEMS_R_11_02667_006.01                                     */
/*                 VEMS_R_11_02667_008.01                                     */
/*                 VEMS_R_11_02667_009.01                                     */
/*                 VEMS_R_11_02667_010.01                                     */
/*                 VEMS_R_11_02667_011.01                                     */
/*                 VEMS_E_11_02667_019.01                                     */
/*                 VEMS_E_11_02667_021.01                                     */
/*                 VEMS_E_11_02667_022.01                                     */
/*                 VEMS_R_11_02667_002.01                                     */
/*                 VEMS_R_11_02667_004.01                                     */
/*                 VEMS_E_11_02667_015.01                                     */
/*                 VEMS_R_11_02667_003.01                                     */
/*                 VEMS_E_11_02667_017.01                                     */
/*                 VEMS_E_11_02667_016.01                                     */
/*                 VEMS_E_11_02667_018.01                                     */
/*                 VEMS_E_11_01688_008.01                                     */
/*                 VEMS_E_11_02667_025.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/*  SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                 */
/*  extf argret Std_ReturnType  DCM_MANU_CheckVehicleCondition(argout         */
/* Dcm_NegativeResponseCodeType *ErrorCode);                                  */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret Std_ReturnType  DCM_MANU_CheckFunctionalAvailability(argin    */
/* uint8 SID, argin uint8 *RequestData, argin uint8 DcmRxPduId);              */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input boolean Clef_off_on_sans_dem;                                       */
/*  input boolean Ctrl_IS_VIN_WMI_BSI_4D2;                                    */
/*  input boolean Ctrl_IS_VIN_VDS_BSI_492;                                    */
/*  input boolean Ctrl_IS_VIN_VIS_BSI_4B2;                                    */
/*  output boolean Srv_ClearDTC_Dmnd;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_ManufSupplIndication
(
   uint8 SID,
   uint8* RequestData,
   uint16 DataSize,
   uint8 ReqType,
   uint8 DcmRxPduId,
   uint8* ErrorCode
)
{
   uint8          u8LocalError;
   Std_ReturnType u8localreturn;
   boolean        bLocalClef_off_on_sans_dem;
   uint8          u8LocalInftyp;
   boolean        bLocalbVINDft;
   boolean        bLocalwmiBsi4d2;
   boolean        bLocalvinBsi492;
   boolean        bLocalvinBsi4b2;

   if( ( DCM_RX_PDUID_0 == DcmRxPduId ) ||   /* DCM_UDS_PHYS_TYPE */
       ( DCM_RX_PDUID_1 == DcmRxPduId ) ||   /* DCM_UDS_FUNC_TYPE */
       ( DCM_RX_PDUID_2 == DcmRxPduId ) ||   /* DCM_OBD_PHYS_TYPE */
       ( DCM_RX_PDUID_3 == DcmRxPduId ) )    /* DCM_OBD_FUNC_TYPE */
   {
      /* DCM_bPSA_SPECIFIC_CONF = TRUE : Le service 14 ne dispose pas de
         sous-fonction, il faut donc passer par cette API */
      /* Les services OBD n'ont pas de sous-fonctions */
      if( ( DCM_MANU_CLRDTC_UDS_SID == SID ) ||
          ( DCM_MANU_CLRDTC_OBD_SID == SID ) )
      {
         u8localreturn = DCM_MANU_CheckADCCondition(SRV_LAMBDA, &u8LocalError);
         /* Si les conditions ADC sont bonnes, on peut tester les autres */
         if( E_OK == u8localreturn )
         {
            /* Test des conditions sur l'état du véhicule */
            u8localreturn = DCM_MANU_CheckVehicleCondition(&u8LocalError);
            if( E_OK == u8localreturn )
            {
               VEMS_vidGET(Clef_off_on_sans_dem, bLocalClef_off_on_sans_dem );
               if( ( DCM_MANU_CLRDTC_UDS_SID == SID     ) ||
                   ( TRUE == bLocalClef_off_on_sans_dem ) )
               {
                  /* Le service d'effacement des défauts par l'UDS ou
                  par l'OBD est accepté */
                  VEMS_vidSET(Srv_ClearDTC_Dmnd,TRUE);
               }
               else
               {
                  VEMS_vidSET(Srv_ClearDTC_Dmnd,FALSE);
                  u8localreturn = E_NOT_OK;
                  u8LocalError = DCM_E_CONDITIONSNOTCORRECT;
               }
            }
            else
            {
               /* Les conditions ADC ne sont pas bonnes */
               if( DCM_MANU_CLRDTC_OBD_SID == SID )
               {
                  u8LocalError = DCM_E_CONDITIONSNOTCORRECT;
               }
               /* Les conditions sur l'état véhicule ne sont pas bonnes */
               VEMS_vidSET(Srv_ClearDTC_Dmnd,FALSE);
            }
         }
         else
         {
            /* Les conditions ADC ne sont pas bonnes */
            if( DCM_MANU_CLRDTC_OBD_SID == SID )
            {
               u8LocalError = DCM_E_CONDITIONSNOTCORRECT;
            }
            /* Les conditions sur l'état véhicule ne sont pas bonnes */
            VEMS_vidSET(Srv_ClearDTC_Dmnd,FALSE);
         }
      }
      else if( ( DCM_MANU_READ_SID == SID  ) ||
               ( DCM_MANU_WRITE_SID == SID ) )
      {
         u8localreturn = DCM_MANU_CheckFunctionalAvailability( SID,
                                                               RequestData,
                                                               DcmRxPduId );
         if( E_REQUEST_NOT_ACCEPTED != u8localreturn )
         {
            u8localreturn = E_OK;
            /* Initialisé à 0x00 mais non utilisé par le DCM dans ce cas. */
            u8LocalError = 0x00;
         }
         else
         {
            /* Initialisé à 0x00 mais non utilisé par le DCM dans ce cas. */
            u8LocalError = 0x00;
            /* u8localreturn = E_REQUEST_NOT_ACCEPTED; */
         }
      }
      /* Condition pour lecture VIN en OBDMODE09 */
      else if( DCM_MANU_OBDSRV09_SID == SID)
      {
         u8localreturn = E_OK;
         u8LocalError = 0x00;

         /* Demande de lecture du VIN */
         u8LocalInftyp = RequestData[0];
         if(u8LocalInftyp == DCM_MANU_OBDSRV09_INFTYP_02)
         {
            bLocalbVINDft = GDGAR_bGetFRM(FRM_FRM_VINDFT);
            VEMS_vidGET(Ctrl_IS_VIN_WMI_BSI_4D2,bLocalwmiBsi4d2);
            VEMS_vidGET(Ctrl_IS_VIN_VDS_BSI_492,bLocalvinBsi492);
            VEMS_vidGET(Ctrl_IS_VIN_VIS_BSI_4B2,bLocalvinBsi4b2);

            if((bLocalbVINDft != FALSE) || (bLocalwmiBsi4d2 == FALSE)
               || (bLocalvinBsi492 == FALSE) || (bLocalvinBsi4b2 == FALSE))
            {
               u8localreturn = E_NOT_OK;
               u8LocalError = DCM_E_CONDITIONSNOTCORRECT;
            }
         }
      }
      else
      {
         /* Les autres SIDs ne sont pas à traiter */
         u8localreturn = E_OK;
         /* Initialisé à 0x00 mais non utilisé par le DCM dans ce cas. */
         u8LocalError = 0x00;
      }
   }
   else
   {
      /* Problème, la source n'est pas connue */
      u8localreturn = E_NOT_OK;
      u8LocalError = DCM_E_GENERALREJECT;
   }

   *ErrorCode = u8LocalError;
   /* QAC Warning 3347: If u8localreturn = E_OK, the return value *ErrorCode
      can be unset */

   return u8localreturn;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DCM_MANU_CheckFunctionalAvailability                       */
/* !Description :  Cette fonction permet de déterminer si la requête reçue est*/
/*                 bien autorisée en adressage fonctionnelle.                 */
/* !Number      :  Mng_API.6                                                  */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DCM_MANU_CheckFunctionalAvailability
(
   uint8 SID,
   uint8* RequestData,
   uint8 DcmRxPduId
)
{
   uint16         u16LocalDID;
   Std_ReturnType u8localreturn;

   /* Si on intercepte une requête de type fonctionnelle */
   if( DCM_RX_PDUID_1 == DcmRxPduId )
   {

      u16LocalDID = (uint16)((uint32)RequestData[0] << 8);
      u16LocalDID |= (uint16)RequestData[1];

      if( DCM_MANU_WRITE_SID == SID )
      {
         if( DCM_MANU_EREGORTYPEAPPRVLNUM_DID == u16LocalDID )
         {
            /* Seul le DID 0xF196 est autorisé en adressage fonctionnel */
            u8localreturn = E_OK;
         }
         else
         {
            /* Les autres DIDs sont rejetés (pas de réponse du DCM) */
            u8localreturn = E_REQUEST_NOT_ACCEPTED;
         }
      }
      else /* DCM_MANU_READ_SID == SID */
      {
         if( ( DCM_MANU_EREGORTYPEAPPRVLNUM_DID == u16LocalDID ) ||
             ( DCM_MANU_ZA_DID == u16LocalDID                  ) ||
             ( DCM_MANU_ZI_DID == u16LocalDID                  ) ||
             ( DCM_MANU_ECUMANUFDATE_DID == u16LocalDID        ) )
         {
            /* Seuls les DIDs ci-dessus sont autorisés en adressage
            fonctionnel */
            u8localreturn = E_OK;
         }
         else
         {
            /* Les autres DIDs sont rejetés (pas de réponse du DCM) */
            u8localreturn = E_REQUEST_NOT_ACCEPTED;
         }
      }
   }
   else
   {
      u8localreturn = E_OK;
   }

   return u8localreturn;
}