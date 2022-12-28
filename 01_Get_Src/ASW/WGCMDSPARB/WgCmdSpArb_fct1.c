/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : WgCmdSpArb                                              */
/* !Description     : WgCmdSpArb component.                                   */
/*                                                                            */
/* !Module          : WgCmdSpArb                                              */
/* !Description     : WASTEGATE COMMAND ARBITRATION                           */
/*                                                                            */
/* !File            : WGCMDSPARB_FCT1.C                                       */
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
/*   1 / WGCMDSPARB_vidWgArb                                                  */
/*                                                                            */
/* !Reference   : V02 NT 10 02950 / 05                                        */
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
#include "MATHSRV.h"
#include "WGCMDSPARB.h"
#include "WGCMDSPARB_L.h"
#include "WGCMDSPARB_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  WGCMDSPARB_vidWgArb                                        */
/* !Description :  Wastegate arbitration between the nominal mode and the     */
/*                 bench mode                                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 BoostAct_rDuCyReq;                                           */
/*  input boolean Wg_bActrTstInProgs;                                         */
/*  input uint16 Wg_rOpTrbActrTst;                                            */
/*  input boolean Wg_bWgCmdOplBenchModEna;                                    */
/*  input uint16 Wg_rWgCmdOplSpBenchMod;                                      */
/*  input boolean Ctrl_bSelWgCmdSpCf;                                         */
/*  input sint16 Wg_rWgCmdSp;                                                 */
/*  output uint16 Wg_rRCOReq;                                                 */
/*  output uint16 Wg_rAcvWgcCmdAppld;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void WGCMDSPARB_vidWgArb(void)
{
   boolean  bLocalInhInWgcCmd;
   boolean  bLocalWg_bActrTstInProgs;
   boolean  bLocalWg_bWgCmdOplBenchModEna;
   boolean  bLocalCtrl_bSelWgCmdSpCf;
   uint16   u16LocalBoostAct_rDuCyReq;
   uint16   u16LocalWg_rAcvWgcCmdAppld;
   sint16   s16LocalWg_rAcvWgcCmdAppld;


   bLocalInhInWgcCmd = GDGAR_bGetFRM(FRM_FRM_INHINWGCCMD);
   VEMS_vidGET(BoostAct_rDuCyReq, u16LocalBoostAct_rDuCyReq);

   if (bLocalInhInWgcCmd != 0)
   {
      u16LocalWg_rAcvWgcCmdAppld = 0;
   }
   else
   {
      VEMS_vidGET(Wg_bActrTstInProgs, bLocalWg_bActrTstInProgs);
      if (bLocalWg_bActrTstInProgs != 0)
      {
         VEMS_vidGET(Wg_rOpTrbActrTst, u16LocalWg_rAcvWgcCmdAppld);
      }
      else
      {
         VEMS_vidGET(Wg_bWgCmdOplBenchModEna, bLocalWg_bWgCmdOplBenchModEna);
         if (bLocalWg_bWgCmdOplBenchModEna != 0)
         {
            VEMS_vidGET(Wg_rWgCmdOplSpBenchMod, u16LocalWg_rAcvWgcCmdAppld);
         }
         else
         {
            VEMS_vidGET(Ctrl_bSelWgCmdSpCf, bLocalCtrl_bSelWgCmdSpCf);
            if (bLocalCtrl_bSelWgCmdSpCf != 0)
            {
               VEMS_vidGET(Wg_rWgCmdSp, s16LocalWg_rAcvWgcCmdAppld);
               u16LocalWg_rAcvWgcCmdAppld =
                  (uint16)MATHSRV_udtMAX(s16LocalWg_rAcvWgcCmdAppld, 0);
            }
            else
            {
               u16LocalWg_rAcvWgcCmdAppld =
                  (uint16)(u16LocalBoostAct_rDuCyReq / 2);
            }
         }
      }
   }
   u16LocalBoostAct_rDuCyReq = (uint16)(u16LocalBoostAct_rDuCyReq / 2) ;
   Wg_rRCOReq = u16LocalBoostAct_rDuCyReq;
   u16LocalWg_rAcvWgcCmdAppld =
      (uint16)MATHSRV_udtMIN(u16LocalWg_rAcvWgcCmdAppld, 32768);
   VEMS_vidSET(Wg_rAcvWgcCmdAppld, u16LocalWg_rAcvWgcCmdAppld);

}
/*------------------------------- end of file --------------------------------*/