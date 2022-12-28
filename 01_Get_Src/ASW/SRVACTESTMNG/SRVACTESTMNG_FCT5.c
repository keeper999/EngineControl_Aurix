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
/* !File            : SRVACTESTMNG_FCT5.C                                     */
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
/*   1 / SRVACTESTMNG_vidDumpValveTst                                         */
/*   2 / SRVACTESTMNG_vidMEAPtst                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_5074355 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
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
/* !Function    :  SRVACTESTMNG_vidDumpValveTst                               */
/* !Description :  Fonction de detection d'un défaut court circuit à la masse */
/*                 sur GMV grande  vitesse lors du dernier test actionneur    */
/* !Number      :  FCT5.1                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret GDFRM_tenuGDUState  GDGAR_tenuGetStDgo(argin uint16           */
/*  u16IdxDft);                                                               */
/*  output boolean ActrTstMng_bScp;                                           */
/*  output boolean ActrTstMng_bScg;                                           */
/*  output boolean ActrTstMng_bDftCmd;                                        */
/*  output boolean ActrTstMng_bDftEE;                                         */
/*  output boolean ActrTstMng_bCoh;                                           */
/*  output boolean ActrTstMng_bStuckVlv;                                      */
/*  output boolean ActrTstMng_bDurtyVlv;                                      */
/*  output boolean ActrTstMng_bIntmCirc;                                      */
/*  output boolean ActrTstMng_bOc;                                            */
/*  output boolean ActrTstMng_bGavScp;                                        */
/*  output boolean ActrTstMng_VvtStatPb;                                      */
/*  output boolean ActrTstMng_bFrq;                                           */
/*  output boolean ActrTstMng_bMap;                                           */
/*  output boolean ActrTstMng_VvtDynPb;                                       */
/*  output boolean ActrTstMng_bUsPlausFco;                                    */
/*  output boolean ActrTstMng_bUsPlausFld;                                    */
/*  output boolean ActrTstMng_bDftInjrFlow;                                   */
/*  output boolean ActrTstMng_bDftPrailLeak;                                  */
/*  output boolean ActrTstMng_bScpHiFan;                                      */
/*  output boolean ActrTstMng_bScgHiFan;                                      */
/*  output boolean ActrTstMng_bOcHiFan;                                       */
/*  output boolean ActrTstMng_bDftCTP1;                                       */
/*  output boolean ActrTstMng_bOcCTP2;                                        */
/*  output boolean ActrTstMng_bScgCTP2;                                       */
/*  output boolean ActrTstMng_bScpCTP2;                                       */
/*  output boolean ActrTstMng_bDftCTP2;                                       */
/*  output boolean ActrTstMng_bFlapFaild;                                     */
/*  output boolean ActrTstMng_bFlapBlockOp;                                   */
/*  output boolean ActrTstMng_bFlapStayOp;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SRVACTESTMNG_vidDumpValveTst(void)
{
   GDFRM_tenuGDUState LocalStDgoHi_DMPVLVCMD;
   GDFRM_tenuGDUState LocalStDgoLo_DMPVLVCMD;


   LocalStDgoHi_DMPVLVCMD = GDGAR_tenuGetStDgo(GD_DFT_HI_DMPVLVCMD);
   LocalStDgoLo_DMPVLVCMD = GDGAR_tenuGetStDgo(GD_DFT_LO_DMPVLVCMD);
   if (LocalStDgoHi_DMPVLVCMD == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScp = 1;
   }
   else
   {
      ActrTstMng_bScp = 0;
   }
   if (LocalStDgoLo_DMPVLVCMD == GDU_ETAT_PRESENT)
   {
      ActrTstMng_bScg = 1;
   }
   else
   {
      ActrTstMng_bScg = 0;
   }
   ActrTstMng_bDftCmd = 0;
   ActrTstMng_bDftEE = 0;
   ActrTstMng_bCoh = 0;
   ActrTstMng_bStuckVlv = 0;
   ActrTstMng_bDurtyVlv = 0;
   ActrTstMng_bIntmCirc = 0;
   ActrTstMng_bOc = 0;
   ActrTstMng_bGavScp = 0;
   ActrTstMng_VvtStatPb = 0;
   ActrTstMng_bFrq = 0;
   ActrTstMng_bMap = 0;
   ActrTstMng_VvtDynPb = 0;
   ActrTstMng_bUsPlausFco = 0;
   ActrTstMng_bUsPlausFld = 0;
   ActrTstMng_bDftInjrFlow = 0;
   ActrTstMng_bDftPrailLeak = 0;
   ActrTstMng_bScpHiFan = 0;
   ActrTstMng_bScgHiFan = 0;
   ActrTstMng_bOcHiFan = 0;
   ActrTstMng_bDftCTP1 = 0;
   ActrTstMng_bOcCTP2 = 0;
   ActrTstMng_bScgCTP2 = 0;
   ActrTstMng_bScpCTP2 = 0;
   ActrTstMng_bDftCTP2 = 0;
   ActrTstMng_bFlapFaild = 0;
   ActrTstMng_bFlapBlockOp = 0;
   ActrTstMng_bFlapStayOp = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SRVACTESTMNG_vidMEAPtst                                    */
/* !Description :  Fonction de détection d'un défaut volet lors du dernier    */
/*                 test actionneur .                                          */
/* !Number      :  FCT5.2                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Meap_bFlapFaild;                                            */
/*  input boolean Meap_bFlapBlockOp;                                          */
/*  input boolean Meap_bFlapStayOp;                                           */
/*  output boolean ActrTstMng_bFlapFaild;                                     */
/*  output boolean ActrTstMng_bFlapBlockOp;                                   */
/*  output boolean ActrTstMng_bFlapStayOp;                                    */
/*  output boolean ActrTstMng_bDftCmd;                                        */
/*  output boolean ActrTstMng_bDftEE;                                         */
/*  output boolean ActrTstMng_bCoh;                                           */
/*  output boolean ActrTstMng_bStuckVlv;                                      */
/*  output boolean ActrTstMng_bDurtyVlv;                                      */
/*  output boolean ActrTstMng_bIntmCirc;                                      */
/*  output boolean ActrTstMng_bOc;                                            */
/*  output boolean ActrTstMng_bGavScp;                                        */
/*  output boolean ActrTstMng_bScg;                                           */
/*  output boolean ActrTstMng_VvtStatPb;                                      */
/*  output boolean ActrTstMng_bFrq;                                           */
/*  output boolean ActrTstMng_bMap;                                           */
/*  output boolean ActrTstMng_VvtDynPb;                                       */
/*  output boolean ActrTstMng_bScp;                                           */
/*  output boolean ActrTstMng_bUsPlausFco;                                    */
/*  output boolean ActrTstMng_bUsPlausFld;                                    */
/*  output boolean ActrTstMng_bDftInjrFlow;                                   */
/*  output boolean ActrTstMng_bDftPrailLeak;                                  */
/*  output boolean ActrTstMng_bScpHiFan;                                      */
/*  output boolean ActrTstMng_bScgHiFan;                                      */
/*  output boolean ActrTstMng_bOcHiFan;                                       */
/*  output boolean ActrTstMng_bDftCTP1;                                       */
/*  output boolean ActrTstMng_bOcCTP2;                                        */
/*  output boolean ActrTstMng_bScgCTP2;                                       */
/*  output boolean ActrTstMng_bScpCTP2;                                       */
/*  output boolean ActrTstMng_bDftCTP2;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SRVACTESTMNG_vidMEAPtst(void)
{
   boolean bLocalMeap_bFlapFaild;
   boolean bLocalMeap_bFlapBlockOp;
   boolean bLocalMeap_bFlapStayOp;


   VEMS_vidGET(Meap_bFlapFaild, bLocalMeap_bFlapFaild);
   VEMS_vidGET(Meap_bFlapBlockOp, bLocalMeap_bFlapBlockOp);
   VEMS_vidGET(Meap_bFlapStayOp, bLocalMeap_bFlapStayOp);

   ActrTstMng_bFlapFaild = bLocalMeap_bFlapFaild;
   ActrTstMng_bFlapBlockOp = bLocalMeap_bFlapBlockOp;
   ActrTstMng_bFlapStayOp = bLocalMeap_bFlapStayOp;
   ActrTstMng_bDftCmd = 0;
   ActrTstMng_bDftEE = 0;
   ActrTstMng_bCoh = 0;
   ActrTstMng_bStuckVlv = 0;
   ActrTstMng_bDurtyVlv = 0;
   ActrTstMng_bIntmCirc = 0;
   ActrTstMng_bOc = 0;
   ActrTstMng_bGavScp = 0;
   ActrTstMng_bScg = 0;
   ActrTstMng_VvtStatPb = 0;
   ActrTstMng_bFrq = 0;
   ActrTstMng_bMap = 0;
   ActrTstMng_VvtDynPb = 0;
   ActrTstMng_bScp = 0;
   ActrTstMng_bUsPlausFco = 0;
   ActrTstMng_bUsPlausFld = 0;
   ActrTstMng_bDftInjrFlow = 0;
   ActrTstMng_bDftPrailLeak = 0;
   ActrTstMng_bScpHiFan = 0;
   ActrTstMng_bScgHiFan = 0;
   ActrTstMng_bOcHiFan = 0;
   ActrTstMng_bDftCTP1 = 0;
   ActrTstMng_bOcCTP2 = 0;
   ActrTstMng_bScgCTP2 = 0;
   ActrTstMng_bScpCTP2 = 0;
   ActrTstMng_bDftCTP2 = 0;
}

/*---------------------------- end of file -----------------------------------*/