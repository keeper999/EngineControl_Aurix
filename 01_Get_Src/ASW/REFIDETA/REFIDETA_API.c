/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : REFIDETA                                                */
/* !Description     : REFIDETA component                                      */
/*                                                                            */
/* !Module          : REFIDETA                                                */
/* !Description     : Gestion de la reference d'identification etalonnage     */
/*                                                                            */
/* !File            : REFIDETA_API.c                                          */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : ALL                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / REFIDETA_ReadDataLength                                              */
/*   2 / REFIDETA_ConditionCheck_ReadData                                     */
/*   3 / REFIDETA_ReadData_Uds                                                */
/*   4 / REFIDETA_WriteData                                                   */
/*   5 / REFIDETA_ReadData_Obd                                                */
/*                                                                            */
/* !Reference   : V02 NT 11 00995 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#056261                                         */
/* !OtherRefs   : VEMS V02 ECU#065790                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/REFIDETA/REFIDETA_API.c_v       $*/
/* $Revision::   1.5      $$Author::   pbakabad       $$Date::   Jun 11 2013 $*/
/* $Author::   pbakabad                               $$Date::   Jun 11 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "REFIDETA_Im.h"
#include "REFIDETA.h"
#include "REFIDETA_L.h"

#include "MEMSRV.H"
#include "NVMSRV.h"
#include "GDGAR.h"
#include "VEMS.h"
#include "SWFAIL.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  REFIDETA_ReadDataLength                                    */
/* !Description :  Fonction utilisée pour connaître la taille de la donnée    */
/*                 REFIDENTETAL                                               */
/* !Number      :  1                                                          */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType REFIDETA_ReadDataLength
(
   uint16* DataLength
)
{
   /* Size en bits */
   *DataLength = (uint16)(REF_IDENT_ETAL_LONGWITHCRC * 8);

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  REFIDETA_ConditionCheck_ReadData                           */
/* !Description :  Evènement vérifiant les conditions de lecture de la        */
/*                 Refideta                                                   */
/* !Number      :  API.1                                                      */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_R_11_00995_001.01                                     */
/*                 VEMS_R_11_00995_002.01                                     */
/*                 VEMS_R_11_00995_003.01                                     */
/*                 VEMS_R_11_00995_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  REFIDETA_CheckCondition(argin                 */
/*  Dcm_NegativeResponseCodeType *ErrorCode);                                 */
/*  extf argret void NVMSRV_vidRead(argin NVMSRV_tudtObjectList udtObject);   */
/*  extf argret uint8  NVMSRV_u8GetStatus(argin NVMSRV_tudtObjectList         */
/* udtObject);                                                                */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf argret boolean  CRC_bCheck(argout uint8 *DataPtr, argin uint32       */
/* DataLength, argin uint16 ExpectedCrc);                                     */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Ref_ident_etal_eep_status;                                    */
/*  input uint8 Ref_ident_etal[12];                                           */
/*  input uint8 Ref_ident_etal_tentative;                                     */
/*  input boolean Srv_bDgoInv_CalId;                                          */
/*  output uint8 Ref_ident_etal_tentative;                                    */
/*  output uint8 Ref_ident_etal_lecture_status;                               */
/*  output boolean Srv_bDgoInv_CalId;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType REFIDETA_ConditionCheck_ReadData
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16                        u16LocalDataCRC;
   uint8                         au8LocalIdentEtal[REF_IDENT_ETAL_LONGWITHCRC];
   Std_ReturnType                u8localreturn;
   Dcm_NegativeResponseCodeType  LocalErrorCode;
   boolean                       bLocalCrcOk;

   u8localreturn = REFIDETA_CheckCondition(&LocalErrorCode);

   if( E_OK == u8localreturn )
   {
      switch( OpStatus )
      {
         case DCM_INITIAL:
         u8localreturn = E_PENDING;
         Ref_ident_etal_tentative = 0;
         NVMSRV_vidRead(NVMSRV_u16OBJ_REFIDETA);
         break;

         case DCM_PENDING:
         Ref_ident_etal_lecture_status =
            NVMSRV_u8GetStatus(NVMSRV_u16OBJ_REFIDETA);

         if( NVMSRV_u8OK == Ref_ident_etal_eep_status )
         {
            VEMS_vidGET1DArray(Ref_ident_etal, REF_IDENT_ETAL_LONGWITHCRC,
               au8LocalIdentEtal);

            u16LocalDataCRC = (uint16)((((uint32)au8LocalIdentEtal[11]) << 8) |
                                         (uint32)au8LocalIdentEtal[10]);
            u16LocalDataCRC = (uint16)(u16LocalDataCRC ^ 0xFFFF);

            bLocalCrcOk = CRC_bCheck( &au8LocalIdentEtal[0],
                                      (uint32)REF_IDENT_ETAL_LONGUEUR,
                                      u16LocalDataCRC );

            if( CRC_u8CRC_OK == bLocalCrcOk )
            {
               u8localreturn = E_OK;
            }
            else
            {
               u8localreturn = E_NOT_OK;
               LocalErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            }
         }
         else
         {
            Ref_ident_etal_tentative = (uint8)(Ref_ident_etal_tentative + 1);
            if( Ref_ident_etal_tentative > REF_IDENT_TENTATIVE )
            {
               /* L'API de lecture de l'EEPROM semble défectueuse */
               u8localreturn = E_NOT_OK;
               LocalErrorCode = DCM_E_BUSYREPEATREQUEST;
               /* On lève la panne */
               VEMS_vidSET(Srv_bDgoInv_CalId, TRUE);
               GDGAR_vidGdu(GD_DFT_INV_CALID,Srv_bDgoInv_CalId,TRUE,DIAG_DISPO);
            }
            else
            {
               u8localreturn = E_PENDING;
            }
         }
         break;

         case DCM_CANCEL:
         u8localreturn = E_OK;
         break;

         default:
         u8localreturn = E_NOT_OK;
         LocalErrorCode = DCM_E_GENERALREJECT;
         /* Ce cas n'est pas possible */
         SWFAIL_vidSoftwareErrorHook();
         break;
      }
   }
   else
   {
      /* Calibration d'inhibition de la fonction activée */
   }

   *ErrorCode = LocalErrorCode;
   return u8localreturn;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  REFIDETA_ReadData_Uds                                      */
/* !Description :  Fonction de lecture de la REFIDETA via une requete UDS     */
/* !Number      :  API.2                                                      */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  input uint8 Ref_ident_etal[12];                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType REFIDETA_ReadData_Uds
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   /* On utilise pas le paremetre OpStatus, la réponse est en effet immédiate */
   VEMS_vidGET1DArray(Ref_ident_etal,REF_IDENT_ETAL_LONGWITHCRC,Data);
   return E_OK;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  REFIDETA_WriteData                                         */
/* !Description :  Fonction d'écriture de la REFIDETA                         */
/* !Number      :  API.3                                                      */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  REFIDETA_CheckCondition(argin                 */
/*  Dcm_NegativeResponseCodeType *ErrorCode);                                 */
/*  extf argret Std_ReturnType  DCM_MANU_CheckADCCondition(argin uint8        */
/* SrvType, argout Dcm_NegativeResponseCodeType *ErrorCode);                  */
/*  extf argret Std_ReturnType  DCM_MANU_CheckVehicleCondition(argout         */
/* Dcm_NegativeResponseCodeType *ErrorCode);                                  */
/*  extf argret boolean  CRC_bCheck(argout uint8 *DataPtr, argin uint32       */
/* DataLength, argin uint16 ExpectedCrc);                                     */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  extf argret void NVMSRV_vidWrite(argin NVMSRV_tudtObjectList udtObject,   */
/* argin boolean bMode);                                                      */
/*  extf argret uint8  NVMSRV_u8WriteStatus(argin NVMSRV_tudtObjectList       */
/* udtObject);                                                                */
/*  extf argret void MEMSRV_vidSetU8(argio uint8 *pu8Dest, argin uint8        */
/* u8Value, argin uint16 u16ElementNumber);                                   */
/*  extf argret void NVMSRV_vidRead(argin NVMSRV_tudtObjectList udtObject);   */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  extf argret uint8  NVMSRV_u8GetStatus(argin NVMSRV_tudtObjectList         */
/* udtObject);                                                                */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st34 Srv_stRefidetaWrChck;                                          */
/*  input uint8 Ref_ident_etal_eep_status;                                    */
/*  input uint8 Ref_ident_etal_tentative;                                     */
/*  input boolean Srv_bDgoInv_CalId;                                          */
/*  input uint8 Ref_ident_etal[12];                                           */
/*  output uint8 Ref_ident_etal[12];                                          */
/*  output uint8 Ref_ident_etal_tentative;                                    */
/*  output st34 Srv_stRefidetaWrChck;                                         */
/*  output uint8 Ref_ident_etal_eep_status;                                   */
/*  output boolean Srv_bDgoInv_CalId;                                         */
/*  output uint8 Ref_ident_etal_lecture_status;                               */
/*  output boolean Ref_ident_etal_crc_ok;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType REFIDETA_WriteData
(
   uint8* Data,
   uint16 DataLength,
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16                        u16LocalDataCRC;
   uint8                         au8LocalIdentEtal[REF_IDENT_ETAL_LONGWITHCRC];
   Std_ReturnType                u8localreturn;
   Dcm_NegativeResponseCodeType  LocalErrorCode;
   boolean                       bLocalCrcOk;

   u8localreturn = REFIDETA_CheckCondition(&LocalErrorCode);

   if( E_OK == u8localreturn )
   {
      u8localreturn = DCM_MANU_CheckADCCondition( SRV_LAMBDA,
                                                  &LocalErrorCode );
      if( E_OK == u8localreturn )
      {
         u8localreturn = DCM_MANU_CheckVehicleCondition(&LocalErrorCode);

         if( E_OK == u8localreturn )
         {
            switch( OpStatus )
            {
               case DCM_INITIAL:
               if( REF_IDENT_ETAL_LONGWITHCRC == DataLength )
               {
                  u16LocalDataCRC =
                        (uint16)((((uint32)Data[11]) << 8) | (uint32)Data[10]);
                  u16LocalDataCRC = (uint16)(u16LocalDataCRC ^ 0xFFFF);

                  bLocalCrcOk = CRC_bCheck( &Data[0],
                                            (uint32)REF_IDENT_ETAL_LONGUEUR,
                                            u16LocalDataCRC );

                  if( CRC_u8CRC_OK == bLocalCrcOk )
                  {
                     /* Le CRC est bon */
                     VEMS_vidSET1DArray( Ref_ident_etal,
                                         REF_IDENT_ETAL_LONGWITHCRC,
                                         Data );
                     /* API d’accès en écriture de la référence à la volée
                     par le driver EEPROM */
                     NVMSRV_vidWrite(NVMSRV_u16OBJ_REFIDETA, NVMSRV_bSAVE_NOW);
                     Ref_ident_etal_tentative = 0;
                     Srv_stRefidetaWrChck = WAIT_WRITE_STATUS;
                     u8localreturn = E_PENDING;
                  }
                  else
                  {
                     /* La requete est refusée car le CRC n'est pas bon */
                     u8localreturn = E_NOT_OK;
                     Srv_stRefidetaWrChck = WAIT_WRITING;
                     LocalErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                  }
               }
               else
               {
                  /* La requete d'écriture n'est pas de bonne longueur */
                  u8localreturn = E_NOT_OK;
                  Srv_stRefidetaWrChck = WAIT_WRITING;
                  LocalErrorCode = DCM_E_INCORRECTLENGTH;
               }
               break;

               case DCM_PENDING:
               if( WAIT_WRITE_STATUS == Srv_stRefidetaWrChck )
               {
                  Ref_ident_etal_eep_status =
                        NVMSRV_u8WriteStatus(NVMSRV_u16OBJ_REFIDETA);

                  /* Ecriture terminée et OK */
                  if( NVMSRV_u8OK == Ref_ident_etal_eep_status )
                  {
                     Ref_ident_etal_tentative = 0;
                     /* Ref_ident_etal effacée de la RAM */
                     MEMSRV_vidSetU8( au8LocalIdentEtal,
                                      0,
                                      REF_IDENT_ETAL_LONGWITHCRC);

                     VEMS_vidSET1DArray( Ref_ident_etal,
                                         REF_IDENT_ETAL_LONGWITHCRC,
                                         au8LocalIdentEtal);

                     /* API d’accès en lecture de la référence
                        par le driver EEPROM */
                     NVMSRV_vidRead(NVMSRV_u16OBJ_REFIDETA);
                     Srv_stRefidetaWrChck = WAIT_GET_STATUS;
                     u8localreturn = E_PENDING;
                  }
                  else
                  {
                     Ref_ident_etal_tentative =
                           (uint8)(Ref_ident_etal_tentative + 1);

                     if( Ref_ident_etal_tentative > REF_IDENT_TENTATIVE )
                     {
                        /* L'écriture a échouée */
                        u8localreturn = E_NOT_OK;
                        Srv_stRefidetaWrChck = WAIT_WRITING;
                        LocalErrorCode = DCM_E_BUSYREPEATREQUEST;
                        /* On lève la panne */
                        VEMS_vidSET(Srv_bDgoInv_CalId, TRUE);
                        GDGAR_vidGdu(GD_DFT_INV_CALID,Srv_bDgoInv_CalId,TRUE,
                                                               DIAG_DISPO);
                     }
                     else
                     {
                        u8localreturn = E_PENDING;
                     }
                  }
               }
               else if( WAIT_GET_STATUS == Srv_stRefidetaWrChck )
               {
                  Ref_ident_etal_lecture_status =
                     NVMSRV_u8GetStatus(NVMSRV_u16OBJ_REFIDETA);

                  if( NVMSRV_u8OK == Ref_ident_etal_eep_status )
                  {
                     VEMS_vidGET1DArray( Ref_ident_etal,
                                         REF_IDENT_ETAL_LONGWITHCRC,
                                         au8LocalIdentEtal);

                     u16LocalDataCRC =
                              (uint16)((((uint32)au8LocalIdentEtal[11]) << 8) |
                                         (uint32)au8LocalIdentEtal[10]);
                     u16LocalDataCRC = (uint16)(u16LocalDataCRC ^ 0xFFFF);

                     bLocalCrcOk = CRC_bCheck( &au8LocalIdentEtal[0],
                                               (uint32)REF_IDENT_ETAL_LONGUEUR,
                                               u16LocalDataCRC );

                     if( CRC_u8CRC_OK == bLocalCrcOk )
                     {
                        u8localreturn = E_OK;
                        Srv_stRefidetaWrChck = WAIT_WRITING;
                        VEMS_vidSET(Srv_bDgoInv_CalId, FALSE);
                        GDGAR_vidGdu(GD_DFT_INV_CALID,Srv_bDgoInv_CalId,TRUE,
                                                   DIAG_DISPO);
                     }
                     else
                     {
                        u8localreturn = E_NOT_OK;
                        Srv_stRefidetaWrChck = WAIT_WRITING;
                        LocalErrorCode = DCM_E_GENERALPROGRAMMINGFAILURE;
                        /* On lève la panne */
                        VEMS_vidSET(Srv_bDgoInv_CalId, TRUE);
                        GDGAR_vidGdu(GD_DFT_INV_CALID,Srv_bDgoInv_CalId,TRUE,
                                                            DIAG_DISPO);
                     }
                  }
                  else
                  {
                     Ref_ident_etal_tentative =
                        (uint8)(Ref_ident_etal_tentative + 1);

                     if( Ref_ident_etal_tentative > REF_IDENT_TENTATIVE )
                     {
                        /* L'API de lecture de l'EEPROM semble défectueuse */
                        u8localreturn = E_NOT_OK;
                        Srv_stRefidetaWrChck = WAIT_WRITING;
                        LocalErrorCode = DCM_E_BUSYREPEATREQUEST;
                        /* On lève la panne */
                        VEMS_vidSET(Srv_bDgoInv_CalId, TRUE);
                        GDGAR_vidGdu(GD_DFT_INV_CALID,Srv_bDgoInv_CalId,TRUE,
                                                            DIAG_DISPO);
                     }
                     else
                     {
                        u8localreturn = E_PENDING;
                     }
                  }
               }
               else
               {
                  u8localreturn = E_NOT_OK;
                  Srv_stRefidetaWrChck = WAIT_WRITING;
                  LocalErrorCode = DCM_E_GENERALREJECT;
                  /* Ce cas n'est pas possible */
                  SWFAIL_vidSoftwareErrorHook();
               }

               break;

               case DCM_CANCEL:
               u8localreturn = E_OK;
               Srv_stRefidetaWrChck = WAIT_WRITING;
               Ref_ident_etal_tentative = 0;
               Ref_ident_etal_crc_ok = 0;
               break;

               default:
               u8localreturn = E_NOT_OK;
               Srv_stRefidetaWrChck = WAIT_WRITING;
               LocalErrorCode = DCM_E_GENERALREJECT;
               /* Ce cas n'est pas possible */
               SWFAIL_vidSoftwareErrorHook();
               break;
            }
         }
         else
         {
            /* Conditions Véhicules non respectées */
         }
      }
      else
      {
         /* Conditions ADC non respectées */
      }
   }
   else
   {
      /* Calibration d'inhibition de la fonction activée */
   }

   *ErrorCode = LocalErrorCode;
   /* QAC Warnings (2:3353: When u8localreturn = E_OK, LocalErrorCode
      can be unset */

   return u8localreturn;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  REFIDETA_ReadData_Obd                                      */
/* !Description :  Fonction de lecture de la REFIDETA via une requete OBDSRV09*/
/* !Number      :  API.4                                                      */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  input uint8 Ref_ident_etal[12];                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType REFIDETA_ReadData_Obd
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   /* On utilise pas le paremetre OpStatus, la réponse est en effet immédiate */
   VEMS_vidGET1DArray(Ref_ident_etal,REF_IDENT_ETAL_LONGUEUR,Data);
   Data[10] = 0x00;
   Data[11] = 0x00;
   Data[12] = 0x00;
   Data[13] = 0x00;
   Data[14] = 0x00;
   Data[15] = 0x00;

   return E_OK;
}