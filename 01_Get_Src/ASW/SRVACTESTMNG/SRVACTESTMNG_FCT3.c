/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SRVACTESTMNG                                            */
/* !Description     : SRVACTESTMNG component.                                 */
/*                                                                            */
/* !Module          : SRVACTESTMNG                                            */
/* !Description     : MANAGEUR DES TESTS ACTIONNEURS.                         */
/*                                                                            */
/* !File            : SRVACTESTMNG_FCT3.C                                     */
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
/*   1 / SRVACTESTMNG_vidExVVTTst                                             */
/*   2 / SRVACTESTMNG_vidInj4Tst                                              */
/*   3 / SRVACTESTMNG_vidCoil_4Tst                                            */
/*   4 / SRVACTESTMNG_vidBlowBy1                                              */
/*   5 / SRVACTESTMNG_vidBlowBy2                                              */
/*   6 / SRVACTESTMNG_vidThMgt                                                */
/*   7 / SRVACTESTMNG_CtlPmpReq                                               */
/*   8 / SRVACTESTMNG_PropFuPmp                                               */
/*   9 / SRVACTESTMNG_WgcCmd                                                  */
/*   10 / SRVACTESTMNG_vidTstCdnClcn                                          */
/*                                                                            */
/* !Reference   : PTS_DOC_5074355 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/SRVACTESTMNG/SRVACTESTMNG_FCT3.c$*/
/* $Revision::   1.7      $$Author::   pbakabad       $$Date::   Apr 11 2013 $*/
/* $Author::   pbakabad                               $$Date::   Apr 11 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "SRVACTESTMNG.h"
#include "SRVACTESTMNG_L.h"
#include "SRVACTESTMNG_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SRVACTESTMNG_vidExVVTTst                                   */
/* !Description :  Fonction permettant la détection des problèmes rencontrées */
/*                 en phase de test actionneur VVT                            */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean VlvAct_bExActrTestStatErrRef1;                              */
/*  input boolean VlvAct_bExActrTest1RampSpdErrIdc;                           */
/*  input boolean VlvAct_bExActrTestStatErrMax1;                              */
/*  input boolean VlvAct_bExActrTest2RampSpdErrIdc;                           */
/*  input boolean VlvAct_bExActrTestStatErrRef2;                              */
/*  input boolean VlvAct_bExActrTest3RampSpdErrIdc;                           */
/*  input boolean VlvAct_bExActrTestStatErrMax2;                              */
/*  input boolean VlvAct_bExActrTest4RampSpdErrIdc;                           */
/*  input boolean VlvAct_bExActrTestStatErrRef3;                              */
/*  output boolean ActrTstMng_VvtStatPb;                                      */
/*  output boolean ActrTstMng_VvtDynPb;                                       */
/*  output boolean ActrTstMng_bIntmCirc;                                      */
/*  output boolean ActrTstMng_bDurtyVlv;                                      */
/*  output boolean ActrTstMng_bStuckVlv;                                      */
/*  output boolean ActrTstMng_bCoh;                                           */
/*  output boolean ActrTstMng_bDftCmd;                                        */
/*  output boolean ActrTstMng_bDftEE;                                         */
/*  output boolean ActrTstMng_bFrq;                                           */
/*  output boolean ActrTstMng_bGavScp;                                        */
/*  output boolean ActrTstMng_bMap;                                           */
/*  output boolean ActrTstMng_bScpHiFan;                                      */
/*  output boolean ActrTstMng_bScgHiFan;                                      */
/*  output boolean ActrTstMng_bOcHiFan;                                       */
/*  output boolean ActrTstMng_bScp;                                           */
/*  output boolean ActrTstMng_bScg;                                           */
/*  output boolean ActrTstMng_bOc;                                            */
/*  output boolean ActrTstMng_bDftPrailLeak;                                  */
/*  output boolean ActrTstMng_bDftInjrFlow;                                   */
/*  output boolean ActrTstMng_bOcCTP2;                                        */
/*  output boolean ActrTstMng_bScpCTP2;                                       */
/*  output boolean ActrTstMng_bScgCTP2;                                       */
/*  output boolean ActrTstMng_bDftCTP1;                                       */
/*  output boolean ActrTstMng_bDftCTP2;                                       */
/*  output boolean ActrTstMng_bUsPlausFld;                                    */
/*  output boolean ActrTstMng_bUsPlausFco;                                    */
/*  output boolean ActrTstMng_bFlapFaild;                                     */
/*  output boolean ActrTstMng_bFlapBlockOp;                                   */
/*  output boolean ActrTstMng_bFlapStayOp;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SRVACTESTMNG_vidExVVTTst(void)
{
   boolean bLocalExActrTestStatErrRef1;
   boolean bLocalExActrTestStatErrMax1;
   boolean bLocalExActrTestStatErrRef2;
   boolean bLocalExActrTestStatErrMax2;
   boolean bLocalExActrTestStatErrRef3;
   boolean bLocalExActrTest1RampSpdErrIdc;
   boolean bLocalExActrTest2RampSpdErrIdc;
   boolean bLocalExActrTest3RampSpdErrIdc;
   boolean bLocalExActrTest4RampSpdErrIdc;


   VEMS_vidGET(VlvAct_bExActrTestStatErrRef1, bLocalExActrTestStatErrRef1);
   VEMS_vidGET(VlvAct_bExActrTest1RampSpdErrIdc,
               bLocalExActrTest1RampSpdErrIdc);
   VEMS_vidGET(VlvAct_bExActrTestStatErrMax1, bLocalExActrTestStatErrMax1);
   VEMS_vidGET(VlvAct_bExActrTest2RampSpdErrIdc,
               bLocalExActrTest2RampSpdErrIdc);
   VEMS_vidGET(VlvAct_bExActrTestStatErrRef2, bLocalExActrTestStatErrRef2);
   VEMS_vidGET(VlvAct_bExActrTest3RampSpdErrIdc,
               bLocalExActrTest3RampSpdErrIdc);
   VEMS_vidGET(VlvAct_bExActrTestStatErrMax2, bLocalExActrTestStatErrMax2);
   VEMS_vidGET(VlvAct_bExActrTest4RampSpdErrIdc,
               bLocalExActrTest4RampSpdErrIdc);
   VEMS_vidGET(VlvAct_bExActrTestStatErrRef3, bLocalExActrTestStatErrRef3);

   if (  (bLocalExActrTestStatErrRef1 != 0)
      || (bLocalExActrTestStatErrMax1 != 0)
      || (bLocalExActrTestStatErrRef2 != 0)
      || (bLocalExActrTestStatErrMax2 != 0)
      || (bLocalExActrTestStatErrRef3 != 0))
   {
      ActrTstMng_VvtStatPb = 1;
   }
   else
   {
      ActrTstMng_VvtStatPb = 0;
   }
   if (  (bLocalExActrTest1RampSpdErrIdc != 0)
      || (bLocalExActrTest2RampSpdErrIdc != 0)
      || (bLocalExActrTest3RampSpdErrIdc != 0)
      || (bLocalExActrTest4RampSpdErrIdc != 0))
   {
      ActrTstMng_VvtDynPb = 1;
   }
   else
   {
      ActrTstMng_VvtDynPb = 0;
   }

   ActrTstMng_bIntmCirc = 0;
   ActrTstMng_bDurtyVlv = 0;
   ActrTstMng_bStuckVlv = 0;
   ActrTstMng_bCoh = 0;
   ActrTstMng_bDftCmd = 0;
   ActrTstMng_bDftEE = 0;
   ActrTstMng_bFrq = 0;
   ActrTstMng_bGavScp = 0;
   ActrTstMng_bMap = 0;
   ActrTstMng_bScpHiFan = 0;
   ActrTstMng_bScgHiFan = 0;
   ActrTstMng_bOcHiFan = 0;
   ActrTstMng_bScp = 0;
   ActrTstMng_bScg = 0;
   ActrTstMng_bOc = 0;
   ActrTstMng_bDftPrailLeak = 0;
   ActrTstMng_bDftInjrFlow = 0;
   ActrTstMng_bOcCTP2 = 0;
   ActrTstMng_bScpCTP2 = 0;
   ActrTstMng_bScgCTP2 = 0;
   ActrTstMng_bDftCTP1 = 0;
   ActrTstMng_bDftCTP2 = 0;
   ActrTstMng_bUsPlausFld = 0;
   ActrTstMng_bUsPlausFco = 0;
   ActrTstMng_bFlapFaild = 0;
   ActrTstMng_bFlapBlockOp = 0;
   ActrTstMng_bFlapStayOp = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SRVACTESTMNG_vidInj4Tst                                    */
/* !Description :  Fonction de test de l'injecteur 4                          */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  output boolean ActrTstMng_bDftEE;                                         */
/*  output boolean ActrTstMng_bIntmCirc;                                      */
/*  output boolean ActrTstMng_bDurtyVlv;                                      */
/*  output boolean ActrTstMng_bStuckVlv;                                      */
/*  output boolean ActrTstMng_bCoh;                                           */
/*  output boolean ActrTstMng_bDftCmd;                                        */
/*  output boolean ActrTstMng_bFrq;                                           */
/*  output boolean ActrTstMng_bGavScp;                                        */
/*  output boolean ActrTstMng_bMap;                                           */
/*  output boolean ActrTstMng_VvtStatPb;                                      */
/*  output boolean ActrTstMng_VvtDynPb;                                       */
/*  output boolean ActrTstMng_bScpHiFan;                                      */
/*  output boolean ActrTstMng_bScgHiFan;                                      */
/*  output boolean ActrTstMng_bOcHiFan;                                       */
/*  output boolean ActrTstMng_bOc;                                            */
/*  output boolean ActrTstMng_bScp;                                           */
/*  output boolean ActrTstMng_bScg;                                           */
/*  output boolean ActrTstMng_bDftPrailLeak;                                  */
/*  output boolean ActrTstMng_bDftInjrFlow;                                   */
/*  output boolean ActrTstMng_bOcCTP2;                                        */
/*  output boolean ActrTstMng_bScpCTP2;                                       */
/*  output boolean ActrTstMng_bScgCTP2;                                       */
/*  output boolean ActrTstMng_bDftCTP1;                                       */
/*  output boolean ActrTstMng_bDftCTP2;                                       */
/*  output boolean ActrTstMng_bUsPlausFld;                                    */
/*  output boolean ActrTstMng_bUsPlausFco;                                    */
/*  output boolean ActrTstMng_bFlapFaild;                                     */
/*  output boolean ActrTstMng_bFlapBlockOp;                                   */
/*  output boolean ActrTstMng_bFlapStayOp;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SRVACTESTMNG_vidInj4Tst(void)
{
   GDFRM_tenuGDUState LocalstDgoOc_Inj4Cmd;
   GDFRM_tenuGDUState LocalstDgoScp_Inj4Cmd;


   LocalstDgoOc_Inj4Cmd = GDGAR_tenuGetStDgo(GD_DFT_OC_INJ4CMD);
   LocalstDgoScp_Inj4Cmd = GDGAR_tenuGetStDgo(GD_DFT_SCP_INJ4CMD);
   if (  (LocalstDgoOc_Inj4Cmd == GDU_ETAT_PRESENT)
      || (LocalstDgoScp_Inj4Cmd ==  GDU_ETAT_PRESENT))
   {
      ActrTstMng_bDftEE = 1;
   }
   else
   {
      ActrTstMng_bDftEE = 0;
   }

   ActrTstMng_bIntmCirc = 0;
   ActrTstMng_bDurtyVlv = 0;
   ActrTstMng_bStuckVlv = 0;
   ActrTstMng_bCoh = 0;
   ActrTstMng_bDftCmd = 0;
   ActrTstMng_bFrq = 0;
   ActrTstMng_bGavScp = 0;
   ActrTstMng_bMap = 0;
   ActrTstMng_VvtStatPb = 0;
   ActrTstMng_VvtDynPb = 0;
   ActrTstMng_bScpHiFan = 0;
   ActrTstMng_bScgHiFan = 0;
   ActrTstMng_bOcHiFan = 0;
   ActrTstMng_bOc = 0;
   ActrTstMng_bScp = 0;
   ActrTstMng_bScg = 0;
   ActrTstMng_bDftPrailLeak = 0;
   ActrTstMng_bDftInjrFlow = 0;
   ActrTstMng_bOcCTP2 = 0;
   ActrTstMng_bScpCTP2 = 0;
   ActrTstMng_bScgCTP2 = 0;
   ActrTstMng_bDftCTP1 = 0;
   ActrTstMng_bDftCTP2 = 0;
   ActrTstMng_bUsPlausFld = 0;
   ActrTstMng_bUsPlausFco = 0;
   ActrTstMng_bFlapFaild = 0;
   ActrTstMng_bFlapBlockOp = 0;
   ActrTstMng_bFlapStayOp = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SRVACTESTMNG_vidCoil_4Tst                                  */
/* !Description :  Fonction de test de la bobine 4.                           */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  output boolean ActrTstMng_bOc;                                            */
/*  output boolean ActrTstMng_bScp;                                           */
/*  output boolean ActrTstMng_bIntmCirc;                                      */
/*  output boolean ActrTstMng_bDurtyVlv;                                      */
/*  output boolean ActrTstMng_bStuckVlv;                                      */
/*  output boolean ActrTstMng_bCoh;                                           */
/*  output boolean ActrTstMng_bDftCmd;                                        */
/*  output boolean ActrTstMng_bDftEE;                                         */
/*  output boolean ActrTstMng_bFrq;                                           */
/*  output boolean ActrTstMng_bGavScp;                                        */
/*  output boolean ActrTstMng_bMap;                                           */
/*  output boolean ActrTstMng_VvtStatPb;                                      */
/*  output boolean ActrTstMng_VvtDynPb;                                       */
/*  output boolean ActrTstMng_bScpHiFan;                                      */
/*  output boolean ActrTstMng_bScgHiFan;                                      */
/*  output boolean ActrTstMng_bOcHiFan;                                       */
/*  output boolean ActrTstMng_bDftInjrFlow;                                   */
/*  output boolean ActrTstMng_bDftPrailLeak;                                  */
/*  output boolean ActrTstMng_bScg;                                           */
/*  output boolean ActrTstMng_bOcCTP2;                                        */
/*  output boolean ActrTstMng_bScpCTP2;                                       */
/*  output boolean ActrTstMng_bScgCTP2;                                       */
/*  output boolean ActrTstMng_bDftCTP1;                                       */
/*  output boolean ActrTstMng_bDftCTP2;                                       */
/*  output boolean ActrTstMng_bUsPlausFld;                                    */
/*  output boolean ActrTstMng_bUsPlausFco;                                    */
/*  output boolean ActrTstMng_bFlapFaild;                                     */
/*  output boolean ActrTstMng_bFlapBlockOp;                                   */
/*  output boolean ActrTstMng_bFlapStayOp;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SRVACTESTMNG_vidCoil_4Tst(void)
{
   GDFRM_tenuGDUState LocalStDgoOc_IgCoil_4Cmd;
   GDFRM_tenuGDUState LocalStDgoScp_IgCoil_4Cmd;


   LocalStDgoOc_IgCoil_4Cmd = GDGAR_tenuGetStDgo(GD_DFT_OC_IGCOIL4CMD);
   LocalStDgoScp_IgCoil_4Cmd = GDGAR_tenuGetStDgo(GD_DFT_SCP_IGCOIL4CMD);

   if (LocalStDgoOc_IgCoil_4Cmd == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bOc = 1;
   }
   else
   {
      ActrTstMng_bOc = 0;
   }
   if (LocalStDgoScp_IgCoil_4Cmd == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScp = 1;
   }
   else
   {
      ActrTstMng_bScp = 0;
   }

   ActrTstMng_bIntmCirc = 0;
   ActrTstMng_bDurtyVlv = 0;
   ActrTstMng_bStuckVlv = 0;
   ActrTstMng_bCoh = 0;
   ActrTstMng_bDftCmd = 0;
   ActrTstMng_bDftEE = 0;
   ActrTstMng_bFrq = 0;
   ActrTstMng_bGavScp = 0;
   ActrTstMng_bMap = 0;
   ActrTstMng_VvtStatPb = 0;
   ActrTstMng_VvtDynPb = 0;
   ActrTstMng_bScpHiFan = 0;
   ActrTstMng_bScgHiFan = 0;
   ActrTstMng_bOcHiFan = 0;
   ActrTstMng_bDftInjrFlow = 0;
   ActrTstMng_bDftPrailLeak = 0;
   ActrTstMng_bScg = 0;
   ActrTstMng_bOcCTP2 = 0;
   ActrTstMng_bScpCTP2 = 0;
   ActrTstMng_bScgCTP2 = 0;
   ActrTstMng_bDftCTP1 = 0;
   ActrTstMng_bDftCTP2 = 0;
   ActrTstMng_bUsPlausFld = 0;
   ActrTstMng_bUsPlausFco = 0;
   ActrTstMng_bFlapFaild = 0;
   ActrTstMng_bFlapBlockOp = 0;
   ActrTstMng_bFlapStayOp = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SRVACTESTMNG_vidBlowBy1                                    */
/* !Description :  Fonction test pour défaut court circuit à l'alimentation   */
/*                 sur le Blowby1                                             */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  output boolean ActrTstMng_bOc;                                            */
/*  output boolean ActrTstMng_bScp;                                           */
/*  output boolean ActrTstMng_bScg;                                           */
/*  output boolean ActrTstMng_bIntmCirc;                                      */
/*  output boolean ActrTstMng_bDurtyVlv;                                      */
/*  output boolean ActrTstMng_bStuckVlv;                                      */
/*  output boolean ActrTstMng_bCoh;                                           */
/*  output boolean ActrTstMng_bDftCmd;                                        */
/*  output boolean ActrTstMng_bDftEE;                                         */
/*  output boolean ActrTstMng_bFrq;                                           */
/*  output boolean ActrTstMng_bGavScp;                                        */
/*  output boolean ActrTstMng_bMap;                                           */
/*  output boolean ActrTstMng_VvtStatPb;                                      */
/*  output boolean ActrTstMng_VvtDynPb;                                       */
/*  output boolean ActrTstMng_bScpHiFan;                                      */
/*  output boolean ActrTstMng_bScgHiFan;                                      */
/*  output boolean ActrTstMng_bOcHiFan;                                       */
/*  output boolean ActrTstMng_bDftInjrFlow;                                   */
/*  output boolean ActrTstMng_bDftPrailLeak;                                  */
/*  output boolean ActrTstMng_bOcCTP2;                                        */
/*  output boolean ActrTstMng_bScpCTP2;                                       */
/*  output boolean ActrTstMng_bScgCTP2;                                       */
/*  output boolean ActrTstMng_bDftCTP1;                                       */
/*  output boolean ActrTstMng_bDftCTP2;                                       */
/*  output boolean ActrTstMng_bUsPlausFld;                                    */
/*  output boolean ActrTstMng_bUsPlausFco;                                    */
/*  output boolean ActrTstMng_bFlapFaild;                                     */
/*  output boolean ActrTstMng_bFlapBlockOp;                                   */
/*  output boolean ActrTstMng_bFlapStayOp;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SRVACTESTMNG_vidBlowBy1(void)
{
   GDFRM_tenuGDUState LocalStDgoOc_BlowBy1;
   GDFRM_tenuGDUState LocalStDgoScp_BlowBy1;
   GDFRM_tenuGDUState LocalStDgoScg_BlowBy1;


   LocalStDgoOc_BlowBy1 = GDGAR_tenuGetStDgo(GD_DFT_OC_BLOWBY1);
   LocalStDgoScp_BlowBy1 = GDGAR_tenuGetStDgo(GD_DFT_SCP_BLOWBY1);
   LocalStDgoScg_BlowBy1 = GDGAR_tenuGetStDgo(GD_DFT_SCG_BLOWBY1);

   if (LocalStDgoOc_BlowBy1 == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bOc = 1;
   }
   else
   {
      ActrTstMng_bOc = 0;
   }
   if (LocalStDgoScp_BlowBy1 == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScp = 1;
   }
   else
   {
      ActrTstMng_bScp = 0;
   }
   if (LocalStDgoScg_BlowBy1 == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScg = 1;
   }
   else
   {
      ActrTstMng_bScg = 0;
   }

   ActrTstMng_bIntmCirc = 0;
   ActrTstMng_bDurtyVlv = 0;
   ActrTstMng_bStuckVlv = 0;
   ActrTstMng_bCoh = 0;
   ActrTstMng_bDftCmd = 0;
   ActrTstMng_bDftEE = 0;
   ActrTstMng_bFrq = 0;
   ActrTstMng_bGavScp = 0;
   ActrTstMng_bMap = 0;
   ActrTstMng_VvtStatPb = 0;
   ActrTstMng_VvtDynPb = 0;
   ActrTstMng_bScpHiFan = 0;
   ActrTstMng_bScgHiFan = 0;
   ActrTstMng_bOcHiFan = 0;
   ActrTstMng_bDftInjrFlow = 0;
   ActrTstMng_bDftPrailLeak = 0;
   ActrTstMng_bOcCTP2 = 0;
   ActrTstMng_bScpCTP2 = 0;
   ActrTstMng_bScgCTP2 = 0;
   ActrTstMng_bDftCTP1 = 0;
   ActrTstMng_bDftCTP2 = 0;
   ActrTstMng_bUsPlausFld = 0;
   ActrTstMng_bUsPlausFco = 0;
   ActrTstMng_bFlapFaild = 0;
   ActrTstMng_bFlapBlockOp = 0;
   ActrTstMng_bFlapStayOp = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SRVACTESTMNG_vidBlowBy2                                    */
/* !Description :  Fonction de test pour  défaut court circuit à              */
/*                 l'alimentation sur le Blowby2                              */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  output boolean ActrTstMng_bOc;                                            */
/*  output boolean ActrTstMng_bScp;                                           */
/*  output boolean ActrTstMng_bScg;                                           */
/*  output boolean ActrTstMng_bIntmCirc;                                      */
/*  output boolean ActrTstMng_bDurtyVlv;                                      */
/*  output boolean ActrTstMng_bStuckVlv;                                      */
/*  output boolean ActrTstMng_bCoh;                                           */
/*  output boolean ActrTstMng_bDftCmd;                                        */
/*  output boolean ActrTstMng_bDftEE;                                         */
/*  output boolean ActrTstMng_bFrq;                                           */
/*  output boolean ActrTstMng_bGavScp;                                        */
/*  output boolean ActrTstMng_bMap;                                           */
/*  output boolean ActrTstMng_VvtStatPb;                                      */
/*  output boolean ActrTstMng_VvtDynPb;                                       */
/*  output boolean ActrTstMng_bScpHiFan;                                      */
/*  output boolean ActrTstMng_bScgHiFan;                                      */
/*  output boolean ActrTstMng_bOcHiFan;                                       */
/*  output boolean ActrTstMng_bDftInjrFlow;                                   */
/*  output boolean ActrTstMng_bDftPrailLeak;                                  */
/*  output boolean ActrTstMng_bOcCTP2;                                        */
/*  output boolean ActrTstMng_bScpCTP2;                                       */
/*  output boolean ActrTstMng_bScgCTP2;                                       */
/*  output boolean ActrTstMng_bDftCTP1;                                       */
/*  output boolean ActrTstMng_bDftCTP2;                                       */
/*  output boolean ActrTstMng_bUsPlausFld;                                    */
/*  output boolean ActrTstMng_bUsPlausFco;                                    */
/*  output boolean ActrTstMng_bFlapFaild;                                     */
/*  output boolean ActrTstMng_bFlapBlockOp;                                   */
/*  output boolean ActrTstMng_bFlapStayOp;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SRVACTESTMNG_vidBlowBy2(void)
{
   GDFRM_tenuGDUState LocalStDgoOc_BlowBy2;
   GDFRM_tenuGDUState LocalStDgoScp_BlowBy2;
   GDFRM_tenuGDUState LocalStDgoScg_BlowBy2;


   LocalStDgoOc_BlowBy2 = GDGAR_tenuGetStDgo(GD_DFT_OC_BLOWBY2);
   LocalStDgoScp_BlowBy2 = GDGAR_tenuGetStDgo(GD_DFT_SCP_BLOWBY2);
   LocalStDgoScg_BlowBy2 = GDGAR_tenuGetStDgo(GD_DFT_SCG_BLOWBY2);

   if (LocalStDgoOc_BlowBy2 == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bOc = 1;
   }
   else
   {
      ActrTstMng_bOc = 0;
   }
   if (LocalStDgoScp_BlowBy2 == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScp = 1;
   }
   else
   {
      ActrTstMng_bScp = 0;
   }
   if (LocalStDgoScg_BlowBy2 == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScg = 1;
   }
   else
   {
      ActrTstMng_bScg = 0;
   }

   ActrTstMng_bIntmCirc = 0;
   ActrTstMng_bDurtyVlv = 0;
   ActrTstMng_bStuckVlv = 0;
   ActrTstMng_bCoh = 0;
   ActrTstMng_bDftCmd = 0;
   ActrTstMng_bDftEE = 0;
   ActrTstMng_bFrq = 0;
   ActrTstMng_bGavScp = 0;
   ActrTstMng_bMap = 0;
   ActrTstMng_VvtStatPb = 0;
   ActrTstMng_VvtDynPb = 0;
   ActrTstMng_bScpHiFan = 0;
   ActrTstMng_bScgHiFan = 0;
   ActrTstMng_bOcHiFan = 0;
   ActrTstMng_bDftInjrFlow = 0;
   ActrTstMng_bDftPrailLeak = 0;
   ActrTstMng_bOcCTP2 = 0;
   ActrTstMng_bScpCTP2 = 0;
   ActrTstMng_bScgCTP2 = 0;
   ActrTstMng_bDftCTP1 = 0;
   ActrTstMng_bDftCTP2 = 0;
   ActrTstMng_bUsPlausFld = 0;
   ActrTstMng_bUsPlausFco = 0;
   ActrTstMng_bFlapFaild = 0;
   ActrTstMng_bFlapBlockOp = 0;
   ActrTstMng_bFlapStayOp = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SRVACTESTMNG_vidThMgt                                      */
/* !Description :  Fonction de Test de défaut court circuit à la masse pompe à*/
/*                 eau                                                        */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  output boolean ActrTstMng_bOc;                                            */
/*  output boolean ActrTstMng_bScp;                                           */
/*  output boolean ActrTstMng_bScg;                                           */
/*  output boolean ActrTstMng_bIntmCirc;                                      */
/*  output boolean ActrTstMng_bDurtyVlv;                                      */
/*  output boolean ActrTstMng_bStuckVlv;                                      */
/*  output boolean ActrTstMng_bCoh;                                           */
/*  output boolean ActrTstMng_bDftCmd;                                        */
/*  output boolean ActrTstMng_bDftEE;                                         */
/*  output boolean ActrTstMng_bFrq;                                           */
/*  output boolean ActrTstMng_bGavScp;                                        */
/*  output boolean ActrTstMng_bMap;                                           */
/*  output boolean ActrTstMng_VvtStatPb;                                      */
/*  output boolean ActrTstMng_VvtDynPb;                                       */
/*  output boolean ActrTstMng_bScpHiFan;                                      */
/*  output boolean ActrTstMng_bScgHiFan;                                      */
/*  output boolean ActrTstMng_bOcHiFan;                                       */
/*  output boolean ActrTstMng_bDftInjrFlow;                                   */
/*  output boolean ActrTstMng_bDftPrailLeak;                                  */
/*  output boolean ActrTstMng_bOcCTP2;                                        */
/*  output boolean ActrTstMng_bScpCTP2;                                       */
/*  output boolean ActrTstMng_bScgCTP2;                                       */
/*  output boolean ActrTstMng_bDftCTP1;                                       */
/*  output boolean ActrTstMng_bDftCTP2;                                       */
/*  output boolean ActrTstMng_bUsPlausFld;                                    */
/*  output boolean ActrTstMng_bUsPlausFco;                                    */
/*  output boolean ActrTstMng_bFlapFaild;                                     */
/*  output boolean ActrTstMng_bFlapBlockOp;                                   */
/*  output boolean ActrTstMng_bFlapStayOp;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SRVACTESTMNG_vidThMgt(void)
{
   GDFRM_tenuGDUState LocalStDgoOc_TrbWaPmp;
   GDFRM_tenuGDUState LocalStDgoScp_TrbWaPmp;
   GDFRM_tenuGDUState LocalStDgoScg_TrbWaPmp;


   LocalStDgoOc_TrbWaPmp = GDGAR_tenuGetStDgo(GD_DFT_OC_TRBWAPMP);
   LocalStDgoScp_TrbWaPmp = GDGAR_tenuGetStDgo(GD_DFT_SCP_TRBWAPMP);
   LocalStDgoScg_TrbWaPmp = GDGAR_tenuGetStDgo(GD_DFT_SCG_TRBWAPMP);

   if (LocalStDgoOc_TrbWaPmp == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bOc = 1;
   }
   else
   {
      ActrTstMng_bOc = 0;
   }
   if (LocalStDgoScp_TrbWaPmp == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScp = 1;
   }
   else
   {
      ActrTstMng_bScp = 0;
   }
   if (LocalStDgoScg_TrbWaPmp == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScg = 1;
   }
   else
   {
      ActrTstMng_bScg = 0;
   }

   ActrTstMng_bIntmCirc = 0;
   ActrTstMng_bDurtyVlv = 0;
   ActrTstMng_bStuckVlv = 0;
   ActrTstMng_bCoh = 0;
   ActrTstMng_bDftCmd = 0;
   ActrTstMng_bDftEE = 0;
   ActrTstMng_bFrq = 0;
   ActrTstMng_bGavScp = 0;
   ActrTstMng_bMap = 0;
   ActrTstMng_VvtStatPb = 0;
   ActrTstMng_VvtDynPb = 0;
   ActrTstMng_bScpHiFan = 0;
   ActrTstMng_bScgHiFan = 0;
   ActrTstMng_bOcHiFan = 0;
   ActrTstMng_bDftInjrFlow = 0;
   ActrTstMng_bDftPrailLeak = 0;
   ActrTstMng_bOcCTP2 = 0;
   ActrTstMng_bScpCTP2 = 0;
   ActrTstMng_bScgCTP2 = 0;
   ActrTstMng_bDftCTP1 = 0;
   ActrTstMng_bDftCTP2 = 0;
   ActrTstMng_bUsPlausFld = 0;
   ActrTstMng_bUsPlausFco = 0;
   ActrTstMng_bFlapFaild = 0;
   ActrTstMng_bFlapBlockOp = 0;
   ActrTstMng_bFlapStayOp = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SRVACTESTMNG_CtlPmpReq                                     */
/* !Description :  fonction de test de du défaut court circuit à              */
/*                 l'alimentation sur la pompe a l'huile.                     */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  output boolean ActrTstMng_bOc;                                            */
/*  output boolean ActrTstMng_bScp;                                           */
/*  output boolean ActrTstMng_bScg;                                           */
/*  output boolean ActrTstMng_bIntmCirc;                                      */
/*  output boolean ActrTstMng_bDurtyVlv;                                      */
/*  output boolean ActrTstMng_bStuckVlv;                                      */
/*  output boolean ActrTstMng_bCoh;                                           */
/*  output boolean ActrTstMng_bDftCmd;                                        */
/*  output boolean ActrTstMng_bDftEE;                                         */
/*  output boolean ActrTstMng_bFrq;                                           */
/*  output boolean ActrTstMng_bGavScp;                                        */
/*  output boolean ActrTstMng_bMap;                                           */
/*  output boolean ActrTstMng_VvtStatPb;                                      */
/*  output boolean ActrTstMng_VvtDynPb;                                       */
/*  output boolean ActrTstMng_bScpHiFan;                                      */
/*  output boolean ActrTstMng_bScgHiFan;                                      */
/*  output boolean ActrTstMng_bOcHiFan;                                       */
/*  output boolean ActrTstMng_bDftInjrFlow;                                   */
/*  output boolean ActrTstMng_bDftPrailLeak;                                  */
/*  output boolean ActrTstMng_bOcCTP2;                                        */
/*  output boolean ActrTstMng_bScpCTP2;                                       */
/*  output boolean ActrTstMng_bScgCTP2;                                       */
/*  output boolean ActrTstMng_bDftCTP1;                                       */
/*  output boolean ActrTstMng_bDftCTP2;                                       */
/*  output boolean ActrTstMng_bUsPlausFld;                                    */
/*  output boolean ActrTstMng_bUsPlausFco;                                    */
/*  output boolean ActrTstMng_bFlapFaild;                                     */
/*  output boolean ActrTstMng_bFlapBlockOp;                                   */
/*  output boolean ActrTstMng_bFlapStayOp;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SRVACTESTMNG_CtlPmpReq(void)
{
   GDFRM_tenuGDUState LocalStDgoOc_CtlPmpReq;
   GDFRM_tenuGDUState LocalStDgoScp_CtlPmpReq;
   GDFRM_tenuGDUState LocalStDgoScg_CtlPmpReq;


   LocalStDgoOc_CtlPmpReq = GDGAR_tenuGetStDgo(GD_DFT_OC_CTLPMPREQ);
   LocalStDgoScp_CtlPmpReq = GDGAR_tenuGetStDgo(GD_DFT_SCP_CTLPMPREQ);
   LocalStDgoScg_CtlPmpReq = GDGAR_tenuGetStDgo(GD_DFT_SCG_CTLPMPREQ);

   if (LocalStDgoOc_CtlPmpReq == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bOc = 1;
   }
   else
   {
      ActrTstMng_bOc = 0;
   }
   if (LocalStDgoScp_CtlPmpReq == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScp = 1;
   }
   else
   {
      ActrTstMng_bScp = 0;
   }
   if (LocalStDgoScg_CtlPmpReq == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScg = 1;
   }
   else
   {
      ActrTstMng_bScg = 0;
   }

   ActrTstMng_bIntmCirc = 0;
   ActrTstMng_bDurtyVlv = 0;
   ActrTstMng_bStuckVlv = 0;
   ActrTstMng_bCoh = 0;
   ActrTstMng_bDftCmd = 0;
   ActrTstMng_bDftEE = 0;
   ActrTstMng_bFrq = 0;
   ActrTstMng_bGavScp = 0;
   ActrTstMng_bMap = 0;
   ActrTstMng_VvtStatPb = 0;
   ActrTstMng_VvtDynPb = 0;
   ActrTstMng_bScpHiFan = 0;
   ActrTstMng_bScgHiFan = 0;
   ActrTstMng_bOcHiFan = 0;
   ActrTstMng_bDftInjrFlow = 0;
   ActrTstMng_bDftPrailLeak = 0;
   ActrTstMng_bOcCTP2 = 0;
   ActrTstMng_bScpCTP2 = 0;
   ActrTstMng_bScgCTP2 = 0;
   ActrTstMng_bDftCTP1 = 0;
   ActrTstMng_bDftCTP2 = 0;
   ActrTstMng_bUsPlausFld = 0;
   ActrTstMng_bUsPlausFco = 0;
   ActrTstMng_bFlapFaild = 0;
   ActrTstMng_bFlapBlockOp = 0;
   ActrTstMng_bFlapStayOp = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SRVACTESTMNG_PropFuPmp                                     */
/* !Description :  fonction de test du défaut court circuit à l'alimentation  */
/*                 sur la pompe de gavage                                     */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  output boolean ActrTstMng_bOc;                                            */
/*  output boolean ActrTstMng_bScp;                                           */
/*  output boolean ActrTstMng_bScg;                                           */
/*  output boolean ActrTstMng_bGavScp;                                        */
/*  output boolean ActrTstMng_bMap;                                           */
/*  output boolean ActrTstMng_bFrq;                                           */
/*  output boolean ActrTstMng_bIntmCirc;                                      */
/*  output boolean ActrTstMng_bDurtyVlv;                                      */
/*  output boolean ActrTstMng_bStuckVlv;                                      */
/*  output boolean ActrTstMng_bCoh;                                           */
/*  output boolean ActrTstMng_bDftCmd;                                        */
/*  output boolean ActrTstMng_bDftEE;                                         */
/*  output boolean ActrTstMng_VvtStatPb;                                      */
/*  output boolean ActrTstMng_VvtDynPb;                                       */
/*  output boolean ActrTstMng_bScpHiFan;                                      */
/*  output boolean ActrTstMng_bScgHiFan;                                      */
/*  output boolean ActrTstMng_bOcHiFan;                                       */
/*  output boolean ActrTstMng_bDftInjrFlow;                                   */
/*  output boolean ActrTstMng_bDftPrailLeak;                                  */
/*  output boolean ActrTstMng_bOcCTP2;                                        */
/*  output boolean ActrTstMng_bScpCTP2;                                       */
/*  output boolean ActrTstMng_bScgCTP2;                                       */
/*  output boolean ActrTstMng_bDftCTP1;                                       */
/*  output boolean ActrTstMng_bDftCTP2;                                       */
/*  output boolean ActrTstMng_bUsPlausFld;                                    */
/*  output boolean ActrTstMng_bUsPlausFco;                                    */
/*  output boolean ActrTstMng_bFlapFaild;                                     */
/*  output boolean ActrTstMng_bFlapBlockOp;                                   */
/*  output boolean ActrTstMng_bFlapStayOp;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SRVACTESTMNG_PropFuPmp(void)
{
   GDFRM_tenuGDUState LocalStDgoOc_PropFuPmp;
   GDFRM_tenuGDUState LocalStDgoScp_PropFuPmp;
   GDFRM_tenuGDUState LocalStDgoScg_PropFuPmp;
   GDFRM_tenuGDUState LocalStDgoGravScp_PropFuPmp;
   GDFRM_tenuGDUState LocalStDgoMap_PropFuPmp;
   GDFRM_tenuGDUState LocalStDgoFRQ_PropFuPmp;


   LocalStDgoOc_PropFuPmp = GDGAR_tenuGetStDgo(GD_DFT_OC_PROPFUPMP);
   LocalStDgoScp_PropFuPmp = GDGAR_tenuGetStDgo(GD_DFT_SCP_PROPFUPMP);
   LocalStDgoScg_PropFuPmp = GDGAR_tenuGetStDgo(GD_DFT_SCG_PROPFUPMP);
   LocalStDgoGravScp_PropFuPmp = GDGAR_tenuGetStDgo(GD_DFT_GRAVSCP_PROPFUPMP);
   LocalStDgoMap_PropFuPmp = GDGAR_tenuGetStDgo(GD_DFT_MAP_PROPFUPMP);
   LocalStDgoFRQ_PropFuPmp = GDGAR_tenuGetStDgo(GD_DFT_FRQ_PROPFUPMP);

   if (LocalStDgoOc_PropFuPmp == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bOc = 1;
   }
   else
   {
      ActrTstMng_bOc = 0;
   }
   if (LocalStDgoScp_PropFuPmp == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScp = 1;
   }
   else
   {
      ActrTstMng_bScp = 0;
   }
   if (LocalStDgoScg_PropFuPmp == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScg = 1;
   }
   else
   {
      ActrTstMng_bScg = 0;
   }

   if (LocalStDgoGravScp_PropFuPmp == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bGavScp = 1;
   }
   else
   {
      ActrTstMng_bGavScp = 0;
   }
   if (LocalStDgoMap_PropFuPmp == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bMap = 1;
   }
   else
   {
      ActrTstMng_bMap = 0;
   }

   if (LocalStDgoFRQ_PropFuPmp == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bFrq = 1;
   }
   else
   {
      ActrTstMng_bFrq = 0;
   }

   ActrTstMng_bIntmCirc = 0;
   ActrTstMng_bDurtyVlv = 0;
   ActrTstMng_bStuckVlv = 0;
   ActrTstMng_bCoh = 0;
   ActrTstMng_bDftCmd = 0;
   ActrTstMng_bDftEE = 0;
   ActrTstMng_VvtStatPb = 0;
   ActrTstMng_VvtDynPb = 0;
   ActrTstMng_bScpHiFan = 0;
   ActrTstMng_bScgHiFan = 0;
   ActrTstMng_bOcHiFan = 0;
   ActrTstMng_bDftInjrFlow = 0;
   ActrTstMng_bDftPrailLeak = 0;
   ActrTstMng_bOcCTP2 = 0;
   ActrTstMng_bScpCTP2 = 0;
   ActrTstMng_bScgCTP2 = 0;
   ActrTstMng_bDftCTP1 = 0;
   ActrTstMng_bDftCTP2 = 0;
   ActrTstMng_bUsPlausFld = 0;
   ActrTstMng_bUsPlausFco = 0;
   ActrTstMng_bFlapFaild = 0;
   ActrTstMng_bFlapBlockOp = 0;
   ActrTstMng_bFlapStayOp = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SRVACTESTMNG_WgcCmd                                        */
/* !Description :  fonction de test du  défaut court circuit à l'alimentation */
/*                 wastegate.                                                 */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Wg_bDynActrTst;                                             */
/*  input boolean Wg_bGapActrTst;                                             */
/*  output boolean ActrTstMng_bScp;                                           */
/*  output boolean ActrTstMng_bScg;                                           */
/*  output boolean ActrTstMng_bIntmCirc;                                      */
/*  output boolean ActrTstMng_bCoh;                                           */
/*  output boolean ActrTstMng_bDftCmd;                                        */
/*  output boolean ActrTstMng_bDftEE;                                         */
/*  output boolean ActrTstMng_bFrq;                                           */
/*  output boolean ActrTstMng_bGavScp;                                        */
/*  output boolean ActrTstMng_bMap;                                           */
/*  output boolean ActrTstMng_VvtStatPb;                                      */
/*  output boolean ActrTstMng_VvtDynPb;                                       */
/*  output boolean ActrTstMng_bScpHiFan;                                      */
/*  output boolean ActrTstMng_bScgHiFan;                                      */
/*  output boolean ActrTstMng_bOcHiFan;                                       */
/*  output boolean ActrTstMng_bDftInjrFlow;                                   */
/*  output boolean ActrTstMng_bDftPrailLeak;                                  */
/*  output boolean ActrTstMng_bOcCTP2;                                        */
/*  output boolean ActrTstMng_bScpCTP2;                                       */
/*  output boolean ActrTstMng_bScgCTP2;                                       */
/*  output boolean ActrTstMng_bDftCTP1;                                       */
/*  output boolean ActrTstMng_bDftCTP2;                                       */
/*  output boolean ActrTstMng_bUsPlausFld;                                    */
/*  output boolean ActrTstMng_bUsPlausFco;                                    */
/*  output boolean ActrTstMng_bFlapFaild;                                     */
/*  output boolean ActrTstMng_bFlapBlockOp;                                   */
/*  output boolean ActrTstMng_bFlapStayOp;                                    */
/*  output boolean ActrTstMng_bOc;                                            */
/*  output boolean ActrTstMng_bDurtyVlv;                                      */
/*  output boolean ActrTstMng_bStuckVlv;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SRVACTESTMNG_WgcCmd(void)
{
   boolean            bLocalWg_bDynActrTst;
   boolean            bLocalWg_bGapActrTst;
   GDFRM_tenuGDUState LocalStDgoHi_WgcCmd;
   GDFRM_tenuGDUState LocalStDgoLo_WgcCmd;


   LocalStDgoHi_WgcCmd = GDGAR_tenuGetStDgo(GD_DFT_HI_WGCCMD);
   LocalStDgoLo_WgcCmd = GDGAR_tenuGetStDgo(GD_DFT_LO_WGCCMD);

   if (LocalStDgoHi_WgcCmd == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScp = 1;
   }
   else
   {
      ActrTstMng_bScp = 0;
   }
   if (LocalStDgoLo_WgcCmd == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScg = 1;
   }
   else
   {
      ActrTstMng_bScg = 0;
   }
   VEMS_vidGET(Wg_bDynActrTst, bLocalWg_bDynActrTst);
   VEMS_vidGET(Wg_bGapActrTst, bLocalWg_bGapActrTst);
   ActrTstMng_bIntmCirc = 0;
   ActrTstMng_bCoh = 0;
   ActrTstMng_bDftCmd = 0;
   ActrTstMng_bDftEE = 0;
   ActrTstMng_bFrq = 0;
   ActrTstMng_bGavScp = 0;
   ActrTstMng_bMap = 0;
   ActrTstMng_VvtStatPb = 0;
   ActrTstMng_VvtDynPb = 0;
   ActrTstMng_bScpHiFan = 0;
   ActrTstMng_bScgHiFan = 0;
   ActrTstMng_bOcHiFan = 0;
   ActrTstMng_bDftInjrFlow = 0;
   ActrTstMng_bDftPrailLeak = 0;
   ActrTstMng_bOcCTP2 = 0;
   ActrTstMng_bScpCTP2 = 0;
   ActrTstMng_bScgCTP2 = 0;
   ActrTstMng_bDftCTP1 = 0;
   ActrTstMng_bDftCTP2 = 0;
   ActrTstMng_bUsPlausFld = 0;
   ActrTstMng_bUsPlausFco = 0;
   ActrTstMng_bFlapFaild = 0;
   ActrTstMng_bFlapBlockOp = 0;
   ActrTstMng_bFlapStayOp = 0;
   ActrTstMng_bOc = 0;
   ActrTstMng_bDurtyVlv = bLocalWg_bDynActrTst;
   ActrTstMng_bStuckVlv = bLocalWg_bGapActrTst;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SRVACTESTMNG_vidTstCdnClcn                                 */
/* !Description :  Fcontion de calcul de Srv_bActrTstCndClcd                  */
/* !Number      :  FCT3.10                                                    */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Code_test_action;                                             */
/*  input boolean Srv_bTestCdnRunning;                                        */
/*  input boolean Srv_bTestCdn;                                               */
/*  output boolean Srv_bActrTstCndClcd;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SRVACTESTMNG_vidTstCdnClcn(void)
{
   boolean bLocalSrv_bTestCdn;
   boolean bLocalSrv_bTestCdnRunning;
   uint8   u8LocalCode_test_action;


   VEMS_vidGET(Code_test_action, u8LocalCode_test_action);
   if (  (u8LocalCode_test_action == CODE_TEST_VVT_ADM)
      || (u8LocalCode_test_action == CODE_TEST_VVT_ECH)
      || (u8LocalCode_test_action == CODE_TEST_TURBO)
      || (u8LocalCode_test_action == CODE_TEST_HPPMP)
      || (u8LocalCode_test_action == CODE_TEST_FARSP))
   {
      VEMS_vidGET(Srv_bTestCdnRunning, bLocalSrv_bTestCdnRunning);
      Srv_bActrTstCndClcd = bLocalSrv_bTestCdnRunning;
   }
   else
   {
      VEMS_vidGET(Srv_bTestCdn, bLocalSrv_bTestCdn);
      Srv_bActrTstCndClcd = bLocalSrv_bTestCdn;
   }
}
/*---------------------------- end of file -----------------------------------*/