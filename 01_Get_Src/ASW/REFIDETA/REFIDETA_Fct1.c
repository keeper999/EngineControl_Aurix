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
/* !File            : REFIDETA_Fct1.c                                         */
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
/*   1 / REFIDETA_Init                                                        */
/*   2 / REFIDETA_sdlFast                                                     */
/*   3 / REFIDETA_CheckCondition                                              */
/*                                                                            */
/* !Reference   : V02 NT 11 00995 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#056261                                         */
/* !OtherRefs   : VEMS V02 ECU#065790                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/REFIDETA/refideta_fct1.c_v      $*/
/* $Revision::   1.6      $$Author::   pbakabad       $$Date::   Jun 20 2013 $*/
/* $Author::   pbakabad                               $$Date::   Jun 20 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "REFIDETA_Im.h"
#include "REFIDETA.h"
#include "REFIDETA_L.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  REFIDETA_Init                                              */
/* !Description :  Initialisation of outputs                                  */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 Ref_ident_etal_tentative;                                    */
/*  output boolean Srv_bDgoInv_CalId;                                         */
/*  output boolean Srv_ClearDTC_Dmnd;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void REFIDETA_Init(void)
{
   Ref_ident_etal_tentative = 0;
   VEMS_vidSET(Srv_bDgoInv_CalId, 0);
   /* Par défaut à l’init on lance la vérification de cohérence de la réf */
   VEMS_vidSET( Srv_ClearDTC_Dmnd, TRUE );

}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  REFIDETA_sdlFast                                           */
/* !Description :  Evènement fast de la Refideta                              */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  PBAKABAD                                                   */
/* !Trace_To    :  VEMS_R_11_00995_001.01                                     */
/*                 VEMS_R_11_00995_002.01                                     */
/*                 VEMS_R_11_00995_003.01                                     */
/*                 VEMS_R_11_00995_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf argret boolean  CRC_bCheck(argout uint8 *DataPtr, argin uint32       */
/* DataLength, argin uint16 ExpectedCrc);                                     */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input boolean Srv_ClearDTC_Dmnd;                                          */
/*  input boolean Manu_inh_ref_ident_etal;                                    */
/*  input uint8 Ref_ident_etal[12];                                           */
/*  input boolean Srv_bDgoInv_CalId;                                          */
/*  output boolean Srv_bDgoInv_CalId;                                         */
/*  output boolean Srv_ClearDTC_Dmnd;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void REFIDETA_sdlFast(void)
{
   uint16   u16LocalDataCRC;
   uint8    au8LocalIdentEtal[REF_IDENT_ETAL_LONGWITHCRC];
   boolean  bLocalClearDTC;
   boolean  bLocalRefIdentEtatCrcOk;

   VEMS_vidGET(Srv_ClearDTC_Dmnd,bLocalClearDTC);

   if(Manu_inh_ref_ident_etal == 0)
   {
      if( TRUE == bLocalClearDTC )
      {
         VEMS_vidGET1DArray( Ref_ident_etal,
                             REF_IDENT_ETAL_LONGWITHCRC,
                             au8LocalIdentEtal );

         u16LocalDataCRC = (uint16)(((uint32)au8LocalIdentEtal[11] << 8) +
                                     (uint32)au8LocalIdentEtal[10]);
         u16LocalDataCRC = (uint16)(u16LocalDataCRC ^ 0xFFFF);

         bLocalRefIdentEtatCrcOk = CRC_bCheck( &au8LocalIdentEtal[0],
                                               (uint32)REF_IDENT_ETAL_LONGUEUR,
                                               u16LocalDataCRC);

         if( CRC_u8CRC_NOK == bLocalRefIdentEtatCrcOk )
         {
            VEMS_vidSET(Srv_bDgoInv_CalId, TRUE); /* Montée du défaut */
            GDGAR_vidGdu(GD_DFT_INV_CALID,Srv_bDgoInv_CalId,TRUE,DIAG_DISPO);
         }
         else
         {
            VEMS_vidSET(Srv_bDgoInv_CalId, FALSE);
            GDGAR_vidGdu(GD_DFT_INV_CALID,Srv_bDgoInv_CalId,TRUE,DIAG_DISPO);
         }

         VEMS_vidSET( Srv_ClearDTC_Dmnd, FALSE );
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  REFIDETA_CheckCondition                                    */
/* !Description :  Evènement vérifiant les conditions de la Refideta          */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean Manu_inh_ref_ident_etal;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType REFIDETA_CheckCondition
(
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   Std_ReturnType                u8localreturn;
   Dcm_NegativeResponseCodeType  LocalErrorCode;

   if(Manu_inh_ref_ident_etal != 0)
   {
      LocalErrorCode = DCM_E_REQUESTOUTOFRANGE;
      u8localreturn = E_NOT_OK;
   }
   else
   {
      u8localreturn = E_OK;
      LocalErrorCode = 0x00;
   }

   *ErrorCode = LocalErrorCode;

   return u8localreturn;
}