/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : WKU                                                     */
/* !Description     : WKU component.                                          */
/*                                                                            */
/* !Module          : WKU                                                     */
/* !Description     : GENERATION OF INFORMATION RELATED TO RCD .              */
/*                                                                            */
/* !File            : WKU_SCH.c                                               */
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
/*   1 / EcuSt_EveRst_Wku                                                     */
/*   2 / EcuSt_EveRxn432_Wku                                                  */
/*   3 / EcuSt_SdlMid_Wku                                                     */
/*   4 / EcuSt_SdlFast_Wku                                                    */
/*   5 / EcuSt_SdlSlow_Wku                                                    */
/*   6 / EcuSt_EveIni_Wku                                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_6765172 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ECUST/WKU/Wku_SCH.c_v             $*/
/* $Revision::   1.22     $$Author::   achebino       $$Date::   16 Jun 2014 $*/
/* $Author::   achebino                               $$Date::   16 Jun 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "WKU.h"
#include "WKU_L.h"
#include "WKU_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EcuSt_EveRst_Wku                                           */
/* !Description :  Fonction Reset                                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void WKU_vidInitWku();                                        */
/*  extf argret void WKU_vidInterface();                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EcuSt_EveRst_Wku                                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EcuSt_EveRst_Wku(void)
{
   WKU_vidInitWku();
   WKU_vidInterface();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EcuSt_EveRxn432_Wku                                        */
/* !Description :  Fonction ordonnanceur des taches actives sur evenement     */
/*                 EcuSt_EveRxnFrame432_Wku                                   */
/* !Number      :  SCH.2                                                      */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void WKU_vidFrameReception();                                 */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean bDiagStWait);                         */
/*  extf argret void WKU_vidInterface();                                      */
/*  input uint8 WKU_u8Inhib;                                                  */
/*  input boolean EcuSt_bAcvRcdMod_EcuMng;                                    */
/*  input boolean EcuSt_bDgoMainWkuDisrd;                                     */
/*  input boolean EcuSt_bMonRunMainWkuDisrd;                                  */
/*  input boolean EcuSt_bDgoMainWkuIncst;                                     */
/*  input boolean EcuSt_bMonRunMainWkuIncst;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EcuSt_EveRxn432_Wku                                            */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EcuSt_EveRxn432_Wku(void)
{
   boolean bLocalEcuSt_bAcvRcdMod_EcuMng;


   if (WKU_u8Inhib != 0x5A)
   {
      WKU_vidFrameReception();
      VEMS_vidGET(EcuSt_bAcvRcdMod_EcuMng, bLocalEcuSt_bAcvRcdMod_EcuMng);
      if (bLocalEcuSt_bAcvRcdMod_EcuMng == 0)
      {
         GDGAR_vidGdu(GD_DFT_MAINWKUDISRD,
                      EcuSt_bDgoMainWkuDisrd,
                      EcuSt_bMonRunMainWkuDisrd,
                      0);

         GDGAR_vidGdu(GD_DFT_MAINWKUINCST,
                      EcuSt_bDgoMainWkuIncst,
                      EcuSt_bMonRunMainWkuIncst,
                      0);
      }
      WKU_vidInterface();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EcuSt_SdlMid_Wku                                           */
/* !Description :  Englobe les fonctions activés sur le moniteur fixe         */
/*                 EcuSt_SdlMid_Wku                                           */
/* !Number      :  SCH.3                                                      */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void WKU_vidInterface();                                      */
/*  extf argret void WKU_vidFrameMonitoring();                                */
/*  extf argret void WKU_vidBlcPartWkADCAntCase();                            */
/*  extf argret void WKU_vidBlcPartWkEngStartPrep();                          */
/*  extf argret void WKU_vidBlcPartWkEngOilMesPrep();                         */
/*  extf argret void WKU_vidBlcPartWkEngPostVent();                           */
/*  extf argret void WKU_vidMainWkPassCANOutOfOrd();                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean bDiagStWait);                         */
/*  input uint8 WKU_u8Inhib;                                                  */
/*  input boolean EcuSt_bAcvRcdMod_EcuMng;                                    */
/*  input boolean Ext_bDgoRCDLineScg;                                         */
/*  input boolean Ext_bMonRunRCDLineScg;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EcuSt_SdlMid_Wku                                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EcuSt_SdlMid_Wku(void)
{
   boolean bLocalEcuSt_bAcvRcdMod_EcuMng;


   if (WKU_u8Inhib != 0x5A)
   {
      WKU_vidInterface();
      WKU_vidFrameMonitoring();
      WKU_vidBlcPartWkADCAntCase();
      WKU_vidBlcPartWkEngStartPrep();
      WKU_vidBlcPartWkEngOilMesPrep();
      WKU_vidBlcPartWkEngPostVent();
      WKU_vidMainWkPassCANOutOfOrd();

      VEMS_vidGET(EcuSt_bAcvRcdMod_EcuMng, bLocalEcuSt_bAcvRcdMod_EcuMng);
      if (bLocalEcuSt_bAcvRcdMod_EcuMng == 0)
      {
         GDGAR_vidGdu(GD_DFT_RCDLINESCG,
                      Ext_bDgoRCDLineScg,
                      Ext_bMonRunRCDLineScg,
                      0);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EcuSt_SdlFast_Wku                                          */
/* !Description :  Englobe les fonctions appelées à la récurence de           */
/*                 EcuSt_SdlFast_Wku                                          */
/* !Number      :  SCH.4                                                      */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void WKU_vidElectronicIntegration();                          */
/*  extf argret void WKU_vidTimerFlow();                                      */
/*  extf argret void WKU_vidInterface();                                      */
/*  extf argret void WKU_vidForcMainWkAtReqDiag();                            */
/*  input uint8 WKU_u8Inhib;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EcuSt_SdlFast_Wku                                              */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EcuSt_SdlFast_Wku(void)
{
   if (WKU_u8Inhib != 0x5A)
   {
      WKU_vidElectronicIntegration();
      WKU_vidTimerFlow();
      WKU_vidInterface();
      WKU_vidForcMainWkAtReqDiag();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EcuSt_SdlSlow_Wku                                          */
/* !Description :  Moniteur lent de la fonction EcuSt                         */
/* !Number      :  SCH.5                                                      */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void WKU_vidMainGradToPass();                                 */
/*  input uint8 WKU_u8Inhib;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  :EcuSt_SdlSlow_Wku                                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EcuSt_SdlSlow_Wku(void)
{
   if (WKU_u8Inhib != 0x5A)
   {
      WKU_vidMainGradToPass();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EcuSt_EveIni_Wku                                           */
/* !Description :  Reset pour déclenchement du premier Key ON                 */
/* !Number      :  SCH.6                                                      */
/* !Author      :  F.CHEFFI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void WKU_vidAPCFirstKeyOn();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : EcuSt_EveIni_Wku                                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void EcuSt_EveIni_Wku(void)
{
   WKU_vidAPCFirstKeyOn();
}

/*--------------------------------- end of file ------------------------------*/