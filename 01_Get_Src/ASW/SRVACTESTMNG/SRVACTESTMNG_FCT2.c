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
/* !File            : SRVACTESTMNG_FCT2.C                                     */
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
/*   1 / SRVACTESTMNG_vidCoil_3Tst                                            */
/*   2 / SRVACTESTMNG_vidHeatSenO2DsTst                                       */
/*   3 / SRVACTESTMNG_vidHeatSenO2UsTst                                       */
/*   4 / SRVACTESTMNG_vidPwrRlyTst                                            */
/*   5 / SRVACTESTMNG_vidCstrTst                                              */
/*   6 / SRVACTESTMNG_vidThrTst                                               */
/*   7 / SRVACTESTMNG_vidB2FanHiSpdTst                                        */
/*   8 / SRVACTESTMNG_vidB2FanLoSpdTst                                        */
/*   9 / SRVACTESTMNG_vidCFanTst                                              */
/*   10 / SRVACTESTMNG_vidInVVTTst                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_5074355 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/SRVACTESTMNG/SRVACTESTMNG_FCT2.C$*/
/* $Revision::   1.6      $$Author::   pbakabad       $$Date::   Apr 11 2013 $*/
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
/* !Function    :  SRVACTESTMNG_vidCoil_3Tst                                  */
/* !Description :  Fonction de test de la bobine 3..                          */
/* !Number      :  FCT2.1                                                     */
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
void SRVACTESTMNG_vidCoil_3Tst(void)
{
   GDFRM_tenuGDUState LocalStDgoOc_IgCoil_3Cmd;
   GDFRM_tenuGDUState LocalStDgoScp_IgCoil_3Cmd;


   LocalStDgoOc_IgCoil_3Cmd = GDGAR_tenuGetStDgo(GD_DFT_OC_IGCOIL3CMD);
   LocalStDgoScp_IgCoil_3Cmd = GDGAR_tenuGetStDgo(GD_DFT_SCP_IGCOIL3CMD);

   if (LocalStDgoOc_IgCoil_3Cmd == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bOc = 1;
   }
   else
   {
      ActrTstMng_bOc = 0;
   }
   if (LocalStDgoScp_IgCoil_3Cmd == GDU_ETAT_PRESENT)
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
/* !Function    :  SRVACTESTMNG_vidHeatSenO2DsTst                             */
/* !Description :  Fonction qui permet le test actionneur sonde aval.         */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  output boolean ActrTstMng_bScp;                                           */
/*  output boolean ActrTstMng_bScg;                                           */
/*  output boolean ActrTstMng_bOc;                                            */
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
void SRVACTESTMNG_vidHeatSenO2DsTst(void)
{
   GDFRM_tenuGDUState LocalstDgoHi_DrvrSenO2Ds;
   GDFRM_tenuGDUState LocalstDgoLo_DrvrSenO2Ds;


   LocalstDgoHi_DrvrSenO2Ds = GDGAR_tenuGetStDgo(GD_DFT_HI_DRVRSENO2DS);
   LocalstDgoLo_DrvrSenO2Ds = GDGAR_tenuGetStDgo(GD_DFT_LO_DRVRSENO2DS);
   if (LocalstDgoHi_DrvrSenO2Ds == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScp = 1;
   }
   else
   {
      ActrTstMng_bScp = 0;
   }
   if (LocalstDgoLo_DrvrSenO2Ds == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScg = 1;
   }
   else
   {
      ActrTstMng_bScg = 0;
   }
   ActrTstMng_bOc = 0;
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
/* !Function    :  SRVACTESTMNG_vidHeatSenO2UsTst                             */
/* !Description :  Fonction qui permet le test actionneur sonde amont.        */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  output boolean ActrTstMng_bScp;                                           */
/*  output boolean ActrTstMng_bScg;                                           */
/*  output boolean ActrTstMng_bOc;                                            */
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
void SRVACTESTMNG_vidHeatSenO2UsTst(void)
{
   GDFRM_tenuGDUState LocalstDgoHi_DrvrSenO2Us;
   GDFRM_tenuGDUState LocalstDgoLo_DrvrSenO2Us;


   LocalstDgoHi_DrvrSenO2Us = GDGAR_tenuGetStDgo(GD_DFT_HI_DRVRSENO2US);
   LocalstDgoLo_DrvrSenO2Us = GDGAR_tenuGetStDgo(GD_DFT_LO_DRVRSENO2US);
   if (LocalstDgoHi_DrvrSenO2Us == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScp = 1;
   }
   else
   {
      ActrTstMng_bScp = 0;
   }
   if (LocalstDgoLo_DrvrSenO2Us == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScg = 1;
   }
   else
   {
      ActrTstMng_bScg = 0;
   }
   ActrTstMng_bOc = 0;
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
/* !Function    :  SRVACTESTMNG_vidPwrRlyTst                                  */
/* !Description :  Fonction qui permet le test actionneur relais de puissance.*/
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  output boolean ActrTstMng_bScg;                                           */
/*  output boolean ActrTstMng_bScp;                                           */
/*  output boolean ActrTstMng_bOc;                                            */
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
void SRVACTESTMNG_vidPwrRlyTst(void)
{
   GDFRM_tenuGDUState LocalstDgoScg_PwrRly;
   GDFRM_tenuGDUState LocalstDgoScp_PwrRly;
   GDFRM_tenuGDUState LocalstDgoOc_PwrRly;


   LocalstDgoScg_PwrRly = GDGAR_tenuGetStDgo(GD_DFT_SCG_PWRRLY);
   LocalstDgoScp_PwrRly = GDGAR_tenuGetStDgo(GD_DFT_SCP_PWRRLY);
   LocalstDgoOc_PwrRly = GDGAR_tenuGetStDgo(GD_DFT_OC_PWRRLY);
   if (LocalstDgoScg_PwrRly == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScg = 1;
   }
   else
   {
      ActrTstMng_bScg = 0;
   }
   if (LocalstDgoScp_PwrRly == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScp = 1;
   }
   else
   {
      ActrTstMng_bScp = 0;
   }
   if (LocalstDgoOc_PwrRly == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bOc = 1;
   }
   else
   {
      ActrTstMng_bOc = 0;
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
/* !Function    :  SRVACTESTMNG_vidCstrTst                                    */
/* !Description :  Fonction du test actionneur purge canister.                */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  output boolean ActrTstMng_bScg;                                           */
/*  output boolean ActrTstMng_bScp;                                           */
/*  output boolean ActrTstMng_bOc;                                            */
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
void SRVACTESTMNG_vidCstrTst(void)
{
   GDFRM_tenuGDUState LocalstDgoLoCstrDrv;
   GDFRM_tenuGDUState LocalstDgoHiCstrDrv;


   LocalstDgoLoCstrDrv = GDGAR_tenuGetStDgo(GD_DFT_LOCSTRDRV);
   LocalstDgoHiCstrDrv = GDGAR_tenuGetStDgo(GD_DFT_HICSTRDRV);
   if (LocalstDgoLoCstrDrv == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScg = 1;
   }
   else
   {
      ActrTstMng_bScg = 0;
   }
   if (LocalstDgoHiCstrDrv == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScp = 1;
   }
   else
   {
      ActrTstMng_bScp = 0;
   }
   ActrTstMng_bOc = 0;
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
/* !Function    :  SRVACTESTMNG_vidThrTst                                     */
/* !Description :  Fonction permettant le test actionneur papillon.           */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/* u16IdxDft);                                                                */
/*  input boolean Thr_bGapActrTst;                                            */
/*  input boolean Thr_bDynActrTst;                                            */
/*  input boolean Srv_bInhCohRespActrTstThr_C;                                */
/*  output boolean ActrTstMng_bStuckVlv;                                      */
/*  output boolean ActrTstMng_bDurtyVlv;                                      */
/*  output boolean ActrTstMng_bScp;                                           */
/*  output boolean ActrTstMng_bScg;                                           */
/*  output boolean ActrTstMng_bCoh;                                           */
/*  output boolean ActrTstMng_bDftCmd;                                        */
/*  output boolean ActrTstMng_bOc;                                            */
/*  output boolean ActrTstMng_bIntmCirc;                                      */
/*  output boolean ActrTstMng_bDftEE;                                         */
/*  output boolean ActrTstMng_bFrq;                                           */
/*  output boolean ActrTstMng_bGavScp;                                        */
/*  output boolean ActrTstMng_bMap;                                           */
/*  output boolean ActrTstMng_VvtStatPb;                                      */
/*  output boolean ActrTstMng_VvtDynPb;                                       */
/*  output boolean ActrTstMng_bScpHiFan;                                      */
/*  output boolean ActrTstMng_bScgHiFan;                                      */
/*  output boolean ActrTstMng_bOcHiFan;                                       */
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
void SRVACTESTMNG_vidThrTst(void)
{
   boolean            bLocalThr_bDynActrTst;
   boolean            bLocalThr_bGapActrTst;
   GDFRM_tenuGDUState LocalstDgoScpPosnSnsr1;
   GDFRM_tenuGDUState LocalstDgoScpPosnSnsr2;
   GDFRM_tenuGDUState LocalstDgoScgPosnSnsr1;
   GDFRM_tenuGDUState LocalstDgoScgPosnSnsr2;
   GDFRM_tenuGDUState LocalstDgoOvld_ThrCmd;
   GDFRM_tenuGDUState LocalstDgoCohPosnSnsr;


   VEMS_vidGET(Thr_bGapActrTst, bLocalThr_bGapActrTst);
   VEMS_vidGET(Thr_bDynActrTst, bLocalThr_bDynActrTst);

   ActrTstMng_bStuckVlv = bLocalThr_bGapActrTst;
   if (  (bLocalThr_bGapActrTst == 0)
      && (bLocalThr_bDynActrTst != 0))
   {
      ActrTstMng_bDurtyVlv = 1;
   }
   else
   {
      ActrTstMng_bDurtyVlv = 0;
   }

   LocalstDgoScpPosnSnsr1 = GDGAR_tenuGetStDgo(GD_DFT_SCPPOSNSNSR1);
   LocalstDgoScpPosnSnsr2 = GDGAR_tenuGetStDgo(GD_DFT_SCPPOSNSNSR2);
   if (  (LocalstDgoScpPosnSnsr1 == GDU_ETAT_PRESENT)
      || (LocalstDgoScpPosnSnsr2 == GDU_ETAT_PRESENT))
   {
      ActrTstMng_bScp = 1;
   }
   else
   {
      ActrTstMng_bScp = 0;
   }

   LocalstDgoScgPosnSnsr1 = GDGAR_tenuGetStDgo(GD_DFT_SCGPOSNSNSR1);
   LocalstDgoScgPosnSnsr2 = GDGAR_tenuGetStDgo(GD_DFT_SCGPOSNSNSR2);
   if (  (LocalstDgoScgPosnSnsr1 == GDU_ETAT_PRESENT)
      || (LocalstDgoScgPosnSnsr2 == GDU_ETAT_PRESENT))
   {
      ActrTstMng_bScg = 1;
   }
   else
   {
      ActrTstMng_bScg = 0;
   }

   LocalstDgoCohPosnSnsr = GDGAR_tenuGetStDgo(GD_DFT_COHPOSNSNSR);
   if (  (LocalstDgoCohPosnSnsr == GDU_ETAT_PRESENT)
      && (Srv_bInhCohRespActrTstThr_C == 0))
   {
      ActrTstMng_bCoh = 1;
   }
   else
   {
      ActrTstMng_bCoh = 0;
   }

   LocalstDgoOvld_ThrCmd = GDGAR_tenuGetStDgo(GD_DFT_OVLD_THRCMD);
   if (LocalstDgoOvld_ThrCmd == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bDftCmd = 1;
   }
   else
   {
      ActrTstMng_bDftCmd = 0;
   }

   ActrTstMng_bOc = 0;
   ActrTstMng_bIntmCirc = 0;
   ActrTstMng_bDftEE = 0;
   ActrTstMng_bFrq = 0;
   ActrTstMng_bGavScp = 0;
   ActrTstMng_bMap = 0;
   ActrTstMng_VvtStatPb = 0;
   ActrTstMng_VvtDynPb = 0;
   ActrTstMng_bScpHiFan = 0;
   ActrTstMng_bScgHiFan = 0;
   ActrTstMng_bOcHiFan = 0;
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
/* !Function    :  SRVACTESTMNG_vidB2FanHiSpdTst                              */
/* !Description :  Fonction permettant le test des tensions hautes GMV1 et    */
/*                 GMV2.                                                      */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  output boolean ActrTstMng_bScpHiFan;                                      */
/*  output boolean ActrTstMng_bScgHiFan;                                      */
/*  output boolean ActrTstMng_bOcHiFan;                                       */
/*  output boolean ActrTstMng_bDftEE;                                         */
/*  output boolean ActrTstMng_bFrq;                                           */
/*  output boolean ActrTstMng_bGavScp;                                        */
/*  output boolean ActrTstMng_bMap;                                           */
/*  output boolean ActrTstMng_VvtStatPb;                                      */
/*  output boolean ActrTstMng_VvtDynPb;                                       */
/*  output boolean ActrTstMng_bScp;                                           */
/*  output boolean ActrTstMng_bScg;                                           */
/*  output boolean ActrTstMng_bOc;                                            */
/*  output boolean ActrTstMng_bStuckVlv;                                      */
/*  output boolean ActrTstMng_bDurtyVlv;                                      */
/*  output boolean ActrTstMng_bIntmCirc;                                      */
/*  output boolean ActrTstMng_bCoh;                                           */
/*  output boolean ActrTstMng_bDftCmd;                                        */
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
void SRVACTESTMNG_vidB2FanHiSpdTst(void)
{
   GDFRM_tenuGDUState LocalstDgoHi_DrvrFan2;
   GDFRM_tenuGDUState LocalstDgoHi_DrvrFan1;
   GDFRM_tenuGDUState LocalstDgoLo_DrvrFan2;
   GDFRM_tenuGDUState LocalstDgoLo_DrvrFan1;
   GDFRM_tenuGDUState LocalstDgoOc_DrvrFan2;
   GDFRM_tenuGDUState LocalstDgoOc_DrvrFan1;


   LocalstDgoHi_DrvrFan2 = GDGAR_tenuGetStDgo(GD_DFT_HI_DRVRFAN2);
   LocalstDgoHi_DrvrFan1 = GDGAR_tenuGetStDgo(GD_DFT_HI_DRVRFAN1);
   LocalstDgoLo_DrvrFan2 = GDGAR_tenuGetStDgo(GD_DFT_LO_DRVRFAN2);
   LocalstDgoLo_DrvrFan1 = GDGAR_tenuGetStDgo(GD_DFT_LO_DRVRFAN1);
   LocalstDgoOc_DrvrFan2 = GDGAR_tenuGetStDgo(GD_DFT_OC_DRVRFAN2);
   LocalstDgoOc_DrvrFan1 = GDGAR_tenuGetStDgo(GD_DFT_OC_DRVRFAN1);
   if (  (LocalstDgoHi_DrvrFan2 == GDU_ETAT_PRESENT)
      || (LocalstDgoHi_DrvrFan1 == GDU_ETAT_PRESENT))
   {
      ActrTstMng_bScpHiFan = 1;
   }
   else
   {
      ActrTstMng_bScpHiFan = 0;
   }
   if (  (LocalstDgoLo_DrvrFan2 == GDU_ETAT_PRESENT)
      || (LocalstDgoLo_DrvrFan1 == GDU_ETAT_PRESENT))
   {
      ActrTstMng_bScgHiFan = 1;
   }
   else
   {
      ActrTstMng_bScgHiFan = 0;
   }
   if (  (LocalstDgoOc_DrvrFan2 == GDU_ETAT_PRESENT)
      || (LocalstDgoOc_DrvrFan1 == GDU_ETAT_PRESENT))
   {
      ActrTstMng_bOcHiFan = 1;
   }
   else
   {
      ActrTstMng_bOcHiFan = 0;
   }

   ActrTstMng_bDftEE = 0;
   ActrTstMng_bFrq = 0;
   ActrTstMng_bGavScp = 0;
   ActrTstMng_bMap = 0;
   ActrTstMng_VvtStatPb = 0;
   ActrTstMng_VvtDynPb = 0;
   ActrTstMng_bScp = 0;
   ActrTstMng_bScg = 0;
   ActrTstMng_bOc = 0;
   ActrTstMng_bStuckVlv = 0;
   ActrTstMng_bDurtyVlv = 0;
   ActrTstMng_bIntmCirc = 0;
   ActrTstMng_bCoh = 0;
   ActrTstMng_bDftCmd = 0;
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
/* !Function    :  SRVACTESTMNG_vidB2FanLoSpdTst                              */
/* !Description :  Fonction permettant le test des tensions basses GMV 1 et   */
/*                 GMV 2.                                                     */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  output boolean ActrTstMng_bScp;                                           */
/*  output boolean ActrTstMng_bScg;                                           */
/*  output boolean ActrTstMng_bOc;                                            */
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
void SRVACTESTMNG_vidB2FanLoSpdTst(void)
{
   GDFRM_tenuGDUState LocalstDgoHi_DrvrFan2;
   GDFRM_tenuGDUState LocalstDgoHi_DrvrFan1;
   GDFRM_tenuGDUState LocalstDgoLo_DrvrFan2;
   GDFRM_tenuGDUState LocalstDgoLo_DrvrFan1;
   GDFRM_tenuGDUState LocalstDgoOc_DrvrFan2;
   GDFRM_tenuGDUState LocalstDgoOc_DrvrFan1;


   LocalstDgoHi_DrvrFan2 = GDGAR_tenuGetStDgo(GD_DFT_HI_DRVRFAN2);
   LocalstDgoHi_DrvrFan1 = GDGAR_tenuGetStDgo(GD_DFT_HI_DRVRFAN1);
   LocalstDgoLo_DrvrFan2 = GDGAR_tenuGetStDgo(GD_DFT_LO_DRVRFAN2);
   LocalstDgoLo_DrvrFan1 = GDGAR_tenuGetStDgo(GD_DFT_LO_DRVRFAN1);
   LocalstDgoOc_DrvrFan2 = GDGAR_tenuGetStDgo(GD_DFT_OC_DRVRFAN2);
   LocalstDgoOc_DrvrFan1 = GDGAR_tenuGetStDgo(GD_DFT_OC_DRVRFAN1);
   if (  (LocalstDgoHi_DrvrFan2 == GDU_ETAT_PRESENT)
      || (LocalstDgoHi_DrvrFan1 == GDU_ETAT_PRESENT))
   {
      ActrTstMng_bScp = 1;
   }
   else
   {
      ActrTstMng_bScp = 0;
   }
   if (  (LocalstDgoLo_DrvrFan2 == GDU_ETAT_PRESENT)
      || (LocalstDgoLo_DrvrFan1 == GDU_ETAT_PRESENT))
   {
      ActrTstMng_bScg = 1;
   }
   else
   {
      ActrTstMng_bScg = 0;
   }
   if (  (LocalstDgoOc_DrvrFan2 == GDU_ETAT_PRESENT)
      || (LocalstDgoOc_DrvrFan1 == GDU_ETAT_PRESENT))
   {
      ActrTstMng_bOc = 1;
   }
   else
   {
      ActrTstMng_bOc = 0;
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
/* !Function    :  SRVACTESTMNG_vidCFanTst                                    */
/* !Description :  Fonction qui permet le test des tensions hautes et basses  */
/*                 GMV1 et GMV2.                                              */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  output boolean ActrTstMng_bScp;                                           */
/*  output boolean ActrTstMng_bScg;                                           */
/*  output boolean ActrTstMng_bOc;                                            */
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
void SRVACTESTMNG_vidCFanTst(void)
{
   GDFRM_tenuGDUState LocalstDgoHi_DrvrFan2;
   GDFRM_tenuGDUState LocalstDgoHi_DrvrFan1;
   GDFRM_tenuGDUState LocalstDgoLo_DrvrFan2;
   GDFRM_tenuGDUState LocalstDgoLo_DrvrFan1;
   GDFRM_tenuGDUState LocalstDgoOc_DrvrFan2;
   GDFRM_tenuGDUState LocalstDgoOc_DrvrFan1;


   LocalstDgoHi_DrvrFan2 = GDGAR_tenuGetStDgo(GD_DFT_HI_DRVRFAN2);
   LocalstDgoHi_DrvrFan1 = GDGAR_tenuGetStDgo(GD_DFT_HI_DRVRFAN1);
   LocalstDgoLo_DrvrFan2 = GDGAR_tenuGetStDgo(GD_DFT_LO_DRVRFAN2);
   LocalstDgoLo_DrvrFan1 = GDGAR_tenuGetStDgo(GD_DFT_LO_DRVRFAN1 );
   LocalstDgoOc_DrvrFan2 = GDGAR_tenuGetStDgo(GD_DFT_OC_DRVRFAN2);
   LocalstDgoOc_DrvrFan1 = GDGAR_tenuGetStDgo(GD_DFT_OC_DRVRFAN1);
   if (  (LocalstDgoHi_DrvrFan2 == GDU_ETAT_PRESENT)
      || (LocalstDgoHi_DrvrFan1 == GDU_ETAT_PRESENT))
   {
      ActrTstMng_bScp = 1;
   }
   else
   {
      ActrTstMng_bScp = 0;
   }
   if (  (LocalstDgoLo_DrvrFan2 == GDU_ETAT_PRESENT)
      || (LocalstDgoLo_DrvrFan1 == GDU_ETAT_PRESENT))
   {
      ActrTstMng_bScg = 1;
   }
   else
   {
      ActrTstMng_bScg = 0;
   }
   if (  (LocalstDgoOc_DrvrFan2 == GDU_ETAT_PRESENT)
      || (LocalstDgoOc_DrvrFan1 == GDU_ETAT_PRESENT))
   {
      ActrTstMng_bOc = 1;
   }
   else
   {
      ActrTstMng_bOc = 0;
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
/* !Function    :  SRVACTESTMNG_vidInVVTTst                                   */
/* !Description :  Fonction permettant la détection des problèmes rencontrées */
/*                 en phase de test actionneur VVT                            */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean VlvAct_bInActrTestStatErrRef1;                              */
/*  input boolean VlvAct_bInActrTest1RampSpdErrIdc;                           */
/*  input boolean VlvAct_bInActrTestStatErrMax1;                              */
/*  input boolean VlvAct_bInActrTest2RampSpdErrIdc;                           */
/*  input boolean VlvAct_bInActrTestStatErrRef2;                              */
/*  input boolean VlvAct_bInActrTest3RampSpdErrIdc;                           */
/*  input boolean VlvAct_bInActrTestStatErrMax2;                              */
/*  input boolean VlvAct_bInActrTest4RampSpdErrIdc;                           */
/*  input boolean VlvAct_bInActrTestStatErrRef3;                              */
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
void SRVACTESTMNG_vidInVVTTst(void)
{
   boolean bLocalInActrTestStatErrRef1;
   boolean bLocalInActrTestStatErrMax1;
   boolean bLocalInActrTestStatErrRef2;
   boolean bLocalInActrTestStatErrMax2;
   boolean bLocalInActrTestStatErrRef3;
   boolean bLocalInActrTest1RampSpdErrIdc;
   boolean bLocalInActrTest2RampSpdErrIdc;
   boolean bLocalInActrTest3RampSpdErrIdc;
   boolean bLocalInActrTest4RampSpdErrIdc;


   VEMS_vidGET(VlvAct_bInActrTestStatErrRef1, bLocalInActrTestStatErrRef1);
   VEMS_vidGET(VlvAct_bInActrTest1RampSpdErrIdc,
               bLocalInActrTest1RampSpdErrIdc);
   VEMS_vidGET(VlvAct_bInActrTestStatErrMax1, bLocalInActrTestStatErrMax1);
   VEMS_vidGET(VlvAct_bInActrTest2RampSpdErrIdc,
               bLocalInActrTest2RampSpdErrIdc);
   VEMS_vidGET(VlvAct_bInActrTestStatErrRef2, bLocalInActrTestStatErrRef2);
   VEMS_vidGET(VlvAct_bInActrTest3RampSpdErrIdc,
               bLocalInActrTest3RampSpdErrIdc);
   VEMS_vidGET(VlvAct_bInActrTestStatErrMax2, bLocalInActrTestStatErrMax2);
   VEMS_vidGET(VlvAct_bInActrTest4RampSpdErrIdc,
               bLocalInActrTest4RampSpdErrIdc);
   VEMS_vidGET(VlvAct_bInActrTestStatErrRef3, bLocalInActrTestStatErrRef3);

   if (  (bLocalInActrTestStatErrRef1 != 0)
      || (bLocalInActrTestStatErrMax1 != 0)
      || (bLocalInActrTestStatErrRef2 != 0)
      || (bLocalInActrTestStatErrMax2 != 0)
      || (bLocalInActrTestStatErrRef3 != 0))
   {
      ActrTstMng_VvtStatPb = 1;
   }
   else
   {
      ActrTstMng_VvtStatPb = 0;
   }
   if (  (bLocalInActrTest1RampSpdErrIdc != 0)
      || (bLocalInActrTest2RampSpdErrIdc != 0)
      || (bLocalInActrTest3RampSpdErrIdc != 0)
      || (bLocalInActrTest4RampSpdErrIdc != 0))
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
/*---------------------------- end of file -----------------------------------*/