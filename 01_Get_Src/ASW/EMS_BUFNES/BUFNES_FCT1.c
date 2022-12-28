/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : BUFNES                                                  */
/* !Description     : BUFNES component.                                       */
/*                                                                            */
/* !Module          : BUFNES                                                  */
/* !Description     : RECORD THE CRANKSHAFT TEETH DURATION.                   */
/*                                                                            */
/* !File            : BUFNES_FCT1.C                                           */
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
/*   1 / BUFNES_vidInitOutput                                                 */
/*   2 / BUFNES_vidGlobal_View                                                */
/*   3 / BUFNES_vidActivateCalcBufRecord                                      */
/*   4 / BUFNES_vidRcrdCrankshafToothDrt                                      */
/*   5 / BUFNES_vidRplceOutptIfCalcDisabl                                     */
/*                                                                            */
/* !Reference   : V02 NT 11 01163 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_3145 / 01                                       */
/* !OtherRefs   : VEMS V02 ECU#053616                                         */
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
#include "BUFNES.h"
#include "BUFNES_L.h"
#include "BUFNES_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BUFNES_vidInitOutput                                       */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  output uint8 BufNEs_idxLstBufWr;                                          */
/*  output uint8 BufNEs_noNFillTi;                                            */
/*  output boolean BufNEs_bAcvClcBufNEs;                                      */
/*  output boolean BufNEs_bClcBufNEs;                                         */
/*  output uint8 BufNEs_noNFillTiRaw;                                         */
/*  output uint32 BufNEs_prm_tiCgtBuf[12];                                    */
/*  output boolean BUFNES_bRSTPrev;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BUFNES_vidInitOutput(void)
{
   uint8 u8LocalIndex;


   VEMS_vidSET(BufNEs_idxLstBufWr, 0);
   VEMS_vidSET(BufNEs_noNFillTi, 0);
   BufNEs_bAcvClcBufNEs = 0;
   BufNEs_bClcBufNEs = 0;
   BufNEs_noNFillTiRaw = 0;
   for(u8LocalIndex = 0;
       u8LocalIndex < BUFNES_PRM_TICGTBUF_COLS;
       u8LocalIndex++)
   {
      VEMS_vidSET1DArrayElement(BufNEs_prm_tiCgtBuf, u8LocalIndex, 500000);
   }

   BUFNES_bRSTPrev = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BUFNES_vidGlobal_View                                      */
/* !Description :  This block records the crankshaft tooth duration in a      */
/*                 buffer                                                     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01163_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void BUFNES_vidActivateCalcBufRecord();                       */
/*  extf argret void BUFNES_vidRcrdCrankshafToothDrt();                       */
/*  extf argret void BUFNES_vidRplceOutptIfCalcDisabl();                      */
/*  input boolean BufNEs_bClcBufNEs;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BUFNES_vidGlobal_View(void)
{
   BUFNES_vidActivateCalcBufRecord();

   if (BufNEs_bClcBufNEs !=0)
   {
      BUFNES_vidRcrdCrankshafToothDrt();
   }

   BUFNES_vidRplceOutptIfCalcDisabl();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BUFNES_vidActivateCalcBufRecord                            */
/* !Description :  This block disables the function calculation, if the engine*/
/*                 speed is higher than a threshold                           */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01163_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input boolean BufNEs_bClcBufNEs;                                          */
/*  input uint8 BufNEs_nThdAcvFct_C;                                          */
/*  output boolean BufNEs_bClcBufNEs;                                         */
/*  output boolean BufNEs_bAcvClcBufNEs;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BUFNES_vidActivateCalcBufRecord(void)
{
   boolean bLocalClcBufNEsPrev;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalBufNEs_nThdAcvFct_C;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   bLocalClcBufNEsPrev = BufNEs_bClcBufNEs;
   u16LocalBufNEs_nThdAcvFct_C = (uint16)(BufNEs_nThdAcvFct_C * 10);
   if (u16LocalExt_nEng <= u16LocalBufNEs_nThdAcvFct_C)
   {
      BufNEs_bClcBufNEs = 1;
   }
   else
   {
      BufNEs_bClcBufNEs = 0;
   }
   if (  (bLocalClcBufNEsPrev == 0)
      && (BufNEs_bClcBufNEs != 0))
   {
      BufNEs_bAcvClcBufNEs = 1;
   }
   else
   {
      BufNEs_bAcvClcBufNEs = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BUFNES_vidRcrdCrankshafToothDrt                            */
/* !Description :  This block creates several variables:  A buffer of the     */
/*                 crankshaft teeth, A number of the valid elements recorde,  */
/*                 The index of the last recorded element                     */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01163_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  input uint8 BufNEs_idxLstBufWr;                                           */
/*  input boolean Sync_bDgoCkSig;                                             */
/*  input boolean Sync_bBackUpCkSig;                                          */
/*  input uint32 Ext_tiCgt;                                                   */
/*  input uint32 BufNEs_prm_tiCgtBuf[12];                                     */
/*  input boolean BufNEs_bAcvClcBufNEs;                                       */
/*  input boolean BUFNES_bRSTPrev;                                            */
/*  input uint8 BufNEs_noNFillTiRaw;                                          */
/*  output uint8 BufNEs_idxLstBufWr;                                          */
/*  output uint32 BufNEs_prm_tiCgtBuf[12];                                    */
/*  output ???? BUFNES_PRM_TICGTBUF_COLS;                                     */
/*  output uint8 BufNEs_noNFillTiRaw;                                         */
/*  output boolean BUFNES_bRSTPrev;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BUFNES_vidRcrdCrankshafToothDrt(void)
{
   boolean bLocalSync_bDgoCkSig;
   boolean bLocalAcvCoSyncDftCk;
   boolean bLocalSync_bBackUpCkSig;
   uint8   u8LocalIndex;
   uint8   u8LocalBufNEs_idxLstBufWr;
   uint32  au32LocalBufNEs_prm_tiCgtBuf[BUFNES_PRM_TICGTBUF_COLS];
   uint32  u32LocalExt_tiCgt;


   bLocalAcvCoSyncDftCk = GDGAR_bGetFRM(FRM_FRM_ACVCOSYNCDFTCK);

   VEMS_vidGET(BufNEs_idxLstBufWr, u8LocalBufNEs_idxLstBufWr);
   VEMS_vidGET(Sync_bDgoCkSig, bLocalSync_bDgoCkSig);
   VEMS_vidGET(Sync_bBackUpCkSig, bLocalSync_bBackUpCkSig);
   VEMS_vidGET(Ext_tiCgt, u32LocalExt_tiCgt);

   u8LocalBufNEs_idxLstBufWr =
      (uint8)MATHSRV_udtMIN(u8LocalBufNEs_idxLstBufWr, 11);

   if (u8LocalBufNEs_idxLstBufWr < 11)
   {
      u8LocalBufNEs_idxLstBufWr = (uint8)(u8LocalBufNEs_idxLstBufWr + 1);
   }
   else
   {
      u8LocalBufNEs_idxLstBufWr = 0;
   }

   VEMS_vidSET(BufNEs_idxLstBufWr, u8LocalBufNEs_idxLstBufWr);

   VEMS_vidGET1DArray(BufNEs_prm_tiCgtBuf,
                      BUFNES_PRM_TICGTBUF_COLS,
                      au32LocalBufNEs_prm_tiCgtBuf);
   au32LocalBufNEs_prm_tiCgtBuf[u8LocalBufNEs_idxLstBufWr] = u32LocalExt_tiCgt;

   for (u8LocalIndex = 0;
        u8LocalIndex < BUFNES_PRM_TICGTBUF_COLS;
        u8LocalIndex++)
   {
      au32LocalBufNEs_prm_tiCgtBuf[u8LocalIndex] =
         MATHSRV_udtMIN(au32LocalBufNEs_prm_tiCgtBuf[u8LocalIndex], 500000);
   }
   VEMS_vidSET1DArray(BufNEs_prm_tiCgtBuf,
                      BUFNES_PRM_TICGTBUF_COLS,
                      au32LocalBufNEs_prm_tiCgtBuf);

   if (  (BufNEs_bAcvClcBufNEs != 0)
      || (bLocalSync_bDgoCkSig != 0)
      || (bLocalAcvCoSyncDftCk != 0)
      || (bLocalSync_bBackUpCkSig != 0))
   {
      if (BUFNES_bRSTPrev == 0)
      {
         BufNEs_noNFillTiRaw = 0;
      }
      BUFNES_bRSTPrev = 1;
   }
   else
   {
      BUFNES_bRSTPrev = 0;
      if (BufNEs_noNFillTiRaw < 255)
      {
         BufNEs_noNFillTiRaw = (uint8)(BufNEs_noNFillTiRaw + 1);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  BUFNES_vidRplceOutptIfCalcDisabl                           */
/* !Description :  This block disables the valid elements recorded in the     */
/*                 buffer, if the engine speed is higher than a threshold     */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01163_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean BufNEs_bClcBufNEs;                                          */
/*  input uint8 BufNEs_noNFillTiRaw;                                          */
/*  output uint8 BufNEs_noNFillTi;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void BUFNES_vidRplceOutptIfCalcDisabl(void)
{
   uint8 u8LocalBufNEs_noNFillTi;


   if (BufNEs_bClcBufNEs != 0)
   {
      u8LocalBufNEs_noNFillTi = BufNEs_noNFillTiRaw;
   }
   else
   {
      u8LocalBufNEs_noNFillTi = 0;
   }

   VEMS_vidSET(BufNEs_noNFillTi, u8LocalBufNEs_noNFillTi);
}
/*------------------------------end-of-file-----------------------------------*/