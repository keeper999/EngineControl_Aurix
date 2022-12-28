/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DMPVLVCMDSPARB                                          */
/* !Description     : DMPVLVCMDSPARB Component                                */
/*                                                                            */
/* !Module          : DMPVLVCMDSPARB                                          */
/* !Description     : DUMP-VALVE COMMAND ARBITRATION                          */
/*                                                                            */
/* !File            : DMPVLVCMDSPARB_FCT1.C                                   */
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
/*   1 / DMPVLVCMDSPARB_vidDmpVlvArb                                          */
/*                                                                            */
/* !Reference   : V02 NT 12 02202 / 02                                        */
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
#include "DMPVLVCMDSPARB.h"
#include "DMPVLVCMDSPARB_L.h"
#include "DMPVLVCMDSPARB_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DMPVLVCMDSPARB_vidDmpVlvArb                                */
/* !Description :  describes the Dump-Valve command arbitration between       */
/*                 different setpoints. It selects the bench mode and the     */
/*                 nominal mode with the help of DmpVlvAct_bDmpVlvOplCmdEna.  */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean DmpVlv_bAcvDmpVlv;                                          */
/*  input boolean DmpVlvAct_bDmpVlvOplCmdEna;                                 */
/*  input uint16 DmpVlvAct_rDmpVlvOplCmdSp;                                   */
/*  input boolean DmpVlv_bActrTstInProgs;                                     */
/*  input uint16 DmpVlv_rSpReqPosnActrTst;                                    */
/*  input uint16 DmpVlv_rDmpVlvCmd;                                           */
/*  output uint16 DmpVlv_rDmpVlvCmd;                                          */
/*  output uint16 DmpVlv_rDmpVlvCmdAppld;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DMPVLVCMDSPARB_vidDmpVlvArb(void)
{
   boolean bLocalFRM_bInhDmpVlvCmd;
   boolean bLocalDmpVlvAct_bDmpVlvOplCmdEna;
   boolean bLocalDmpVlv_bAcvDmpVlv;
   boolean bLocalDmpVlv_bActrTstInProgs;
   uint16  u16LocalDmpVlvAct_rDmpVlvOpCmdSp;
   uint16  u16LocalDmpVlv_rDmpVlvCmdAppld;
   uint16  u16LocalDmpVlv_rSpReqPosnActrTst;


   bLocalFRM_bInhDmpVlvCmd = GDGAR_bGetFRM(FRM_FRM_INHDMPVLVCMD);
   VEMS_vidGET(DmpVlv_bAcvDmpVlv, bLocalDmpVlv_bAcvDmpVlv);
   if (bLocalDmpVlv_bAcvDmpVlv != 0)
   {
      DmpVlv_rDmpVlvCmd = 32768;
   }
   else
   {
      DmpVlv_rDmpVlvCmd = 0;
   }

   if (bLocalFRM_bInhDmpVlvCmd != 0)
   {
      u16LocalDmpVlv_rDmpVlvCmdAppld = 0;
   }
   else
   {
      VEMS_vidGET(DmpVlvAct_bDmpVlvOplCmdEna, bLocalDmpVlvAct_bDmpVlvOplCmdEna);
      if (bLocalDmpVlvAct_bDmpVlvOplCmdEna != 0)
      {
         VEMS_vidGET(DmpVlvAct_rDmpVlvOplCmdSp,
                     u16LocalDmpVlvAct_rDmpVlvOpCmdSp);
         u16LocalDmpVlv_rDmpVlvCmdAppld =
            (uint16)MATHSRV_udtMIN(u16LocalDmpVlvAct_rDmpVlvOpCmdSp, 32768);
      }
      else
      {
         VEMS_vidGET(DmpVlv_bActrTstInProgs, bLocalDmpVlv_bActrTstInProgs);
         if (bLocalDmpVlv_bActrTstInProgs != 0)
         {
            VEMS_vidGET(DmpVlv_rSpReqPosnActrTst,
                        u16LocalDmpVlv_rSpReqPosnActrTst);
            u16LocalDmpVlv_rDmpVlvCmdAppld =
               (uint16)MATHSRV_udtMIN(u16LocalDmpVlv_rSpReqPosnActrTst, 32768);
         }
         else
         {
            u16LocalDmpVlv_rDmpVlvCmdAppld = DmpVlv_rDmpVlvCmd;
         }
      }
   }
   VEMS_vidSET(DmpVlv_rDmpVlvCmdAppld, u16LocalDmpVlv_rDmpVlvCmdAppld);
}
/*------------------------------- end of file --------------------------------*/