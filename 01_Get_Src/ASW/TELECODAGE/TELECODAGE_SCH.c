/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TELECODAGE                                              */
/* !Description     : TELECODAGE component.                                   */
/*                                                                            */
/* !Module          : TELECODAGE                                              */
/* !Description     : PROCÉDURE DE TÉLÉCODAGE SÉCURISÉ                        */
/*                                                                            */
/* !File            : TELECODAGE_SCH.C                                        */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / Srv_EveRst_TeleSrv                                                   */
/*   2 / Srv_SdlFast_TeleSrv                                                  */
/*   3 / Srv_EveSa_TeleSrv                                                    */
/*   4 / Srv_EveTele_TeleSrv                                                  */
/*                                                                            */
/* !Reference   : PTS_DOC_5074365 / 02                                        */
/* !OtherRefs   : VEMS V02 ECU#066577                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/TELECODAGE/TELECODAGE_SCH.C_v   $*/
/* $Revision::   1.9      $$Author::   pbakabad       $$Date::   Jul 29 2013 $*/
/* $Author::   pbakabad                               $$Date::   Jul 29 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "TELECODAGE.h"
#include "TELECODAGE_L.h"
#include "TELECODAGE_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_EveRst_TeleSrv                                         */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_11_02626_001.02                                     */
/*                 VEMS_R_11_02626_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TELECODAGE_vidInitOutput();                              */
/*  extf argret void TELECODAGE_vidInitDftBeforeTel();                        */
/*  extf argret void TELECODAGE_vidVarCodMng();                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Srv_EveRst_TeleSrv                                             */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_EveRst_TeleSrv(void)
{
   TELECODAGE_vidInitOutput();
   TELECODAGE_vidInitDftBeforeTel();
   TELECODAGE_vidVarCodMng();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_SdlFast_TeleSrv                                        */
/* !Description :  Moniteur rapide de la fonction service                     */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_11_02626_001.02                                     */
/*                 VEMS_R_11_02626_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TELECODAGE_vidVarCodDftMng();                            */
/*  extf argret void TELECODAGE_vidVarCodMng();                               */
/*  extf argret void TELECODAGE_vidInfoWrite();                               */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 TELECODAGE_u8Inhib;                                           */
/*  input boolean Srv_bDgoInv_VarCod;                                         */
/*  input boolean Srv_bMonRunInv_VarCod;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Srv_SdlFast_TeleSrv                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_SdlFast_TeleSrv(void)
{
   if (TELECODAGE_u8Inhib != 0x5A)
   {
      TELECODAGE_vidVarCodDftMng();
      TELECODAGE_vidVarCodMng();
      TELECODAGE_vidInfoWrite();
      GDGAR_vidGdu(GD_DFT_INV_VARCOD,
                   Srv_bDgoInv_VarCod,
                   Srv_bMonRunInv_VarCod,
                   DIAG_DISPO);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_EveSa_TeleSrv                                          */
/* !Description :  Runnable des fonctions de Security Access                  */
/* !Number      :  SCH.3                                                      */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_11_02626_001.02                                     */
/*                 VEMS_R_11_02626_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TELECODAGE_vidVarCodMng();                               */
/*  input uint8 TELECODAGE_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Srv_EveSa_TeleSrv                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_EveSa_TeleSrv(void)
{
   if (TELECODAGE_u8Inhib != 0x5A)
   {
      TELECODAGE_vidVarCodMng();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Srv_EveTele_TeleSrv                                        */
/* !Description :  Runnable de la fonction de télécodage                      */
/* !Number      :  SCH.4                                                      */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_11_02626_001.02                                     */
/*                 VEMS_R_11_02626_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TELECODAGE_vidDataVerification();                        */
/*  extf argret void TELECODAGE_vidVarCodMng();                               */
/*  extf argret void TELECODAGE_vidInfoWrite();                               */
/*  input uint8 TELECODAGE_u8Inhib;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Srv_EveTele_TeleSrv                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Srv_EveTele_TeleSrv(void)
{
   if (TELECODAGE_u8Inhib != 0x5A)
   {
      TELECODAGE_vidDataVerification();
      TELECODAGE_vidVarCodMng();
      TELECODAGE_vidInfoWrite();
   }
}

/*------------------------------- end of file --------------------------------*/