/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IDLMGR                                                  */
/* !Description     : IDLMGR component                                        */
/*                                                                            */
/* !Module          : IDLMGR                                                  */
/* !Description     : GESTION DU RALENTI                                      */
/*                                                                            */
/* !File            : IDLMGR_FCT4.C                                           */
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
/*   1 / IDLMGR_vidDeterminer_etat_moteur                                     */
/*   2 / IDLMGR_vidCalculer_cond_regime                                       */
/*   3 / IDLMGR_vidDet_etat_moteur                                            */
/*   4 / IDLMGR_vidDeterminer_inj_dyn                                         */
/*   5 / IDLMGR_vidDet_regime_critique                                        */
/*   6 / IDLMGR_vidDet_ralenti_effectif                                       */
/*   7 / IDLMGR_vidDet_chang_etat_rampage                                     */
/*   8 / IDLMGR_vidReinit_en_surregime                                        */
/*   9 / IDLMGR_vidChange_rapport_boite                                       */
/*   10 / IDLMGR_vidDet_changement_mode                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_5010777 / 02                                        */
/* !OtherRefs   : CSMT_CGMT08_0003 / 2.9                                      */
/* !OtherRefs   : VEMS V02 ECU#063158                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/IDLMGR/IDLMGR_FCT$*/
/* $Revision::   1.18     $$Author::   mbenfrad       $$Date::   06 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   06 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "IDLMGR.h"
#include "IDLMGR_L.h"
#include "IDLMGR_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidDeterminer_etat_moteur                           */
/* !Description :  Dans ce bloc, si on peut autoriser l’activation du ralenti,*/
/*                 en fonction de l’état du moteur.                           */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_020.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IDLMGR_vidCalculer_cond_regime();                        */
/*  extf argret void IDLMGR_vidDet_etat_moteur();                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidDeterminer_etat_moteur(void)
{
   IDLMGR_vidCalculer_cond_regime();
   IDLMGR_vidDet_etat_moteur();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidCalculer_cond_regime                             */
/* !Description :  Lorsque le régime moteur est supérieur à l’offset calculé  */
/*                 plus la consigne de ralenti statique, alors  on autorise   */
/*                 l’activation du ralenti.                                   */
/* !Number      :  FCT4.2                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_021.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 IdlSys_tEng;                                                 */
/*  input uint8 IdlSys_tEng_A[8];                                             */
/*  input boolean CoPTSt_bRStrtSTT;                                           */
/*  input uint16 IdlSys_nOfsRstrtAuthIdlCtl_T[8];                             */
/*  input uint16 IdlSys_nOfsStrtAuthIdlCtl_T[8];                              */
/*  input uint16 TqSys_nTarIdl;                                               */
/*  input sint16 IdlSys_nOfsAuthIdlCtl_MP;                                    */
/*  input uint16 Ext_nEngClc0;                                                */
/*  output sint16 IdlSys_nOfsAuthIdlCtl_MP;                                   */
/*  output boolean IdlSys_bAuthIdlCtlNEng;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidCalculer_cond_regime(void)
{
   boolean bLocalCoPTSt_bRStrtSTT;
   uint8   u8LocalIdlSysTEng;
   uint16  u16LocalTqSys_nTarIdl;
   uint16  u16LocalExt_nEngClc0;
   uint16  u16LocalCalcPara1;
   uint16  u16LocalInterp2;
   sint16  s16LocalIdlSysTEng;
   sint32  s32LocalInterp;
   sint32  s32LocalCompare;


   s16LocalIdlSysTEng = (sint16)((sint32)(IdlSys_tEng + 200) / 4);
   u8LocalIdlSysTEng = (uint8)MATHSRV_udtCLAMP(s16LocalIdlSysTEng, 0, 255);
   u16LocalCalcPara1 = MATHSRV_u16CalcParaIncAryU8(IdlSys_tEng_A,
                                                   u8LocalIdlSysTEng,
                                                   8);
   VEMS_vidGET(CoPTSt_bRStrtSTT, bLocalCoPTSt_bRStrtSTT);
   if (bLocalCoPTSt_bRStrtSTT != 0)
   {
      u16LocalInterp2 = MATHSRV_u16Interp1d(IdlSys_nOfsRstrtAuthIdlCtl_T,
                                            u16LocalCalcPara1);
   }
   else
   {
      u16LocalInterp2 = MATHSRV_u16Interp1d(IdlSys_nOfsStrtAuthIdlCtl_T,
                                            u16LocalCalcPara1);
   }
   s32LocalInterp = (sint32)(u16LocalInterp2 - 8000);
   IdlSys_nOfsAuthIdlCtl_MP = (sint16)MATHSRV_udtMIN(s32LocalInterp, 8000);

   VEMS_vidGET(TqSys_nTarIdl, u16LocalTqSys_nTarIdl);
   s32LocalCompare = (sint32)( (4 * IdlSys_nOfsAuthIdlCtl_MP)
                             + u16LocalTqSys_nTarIdl);
   VEMS_vidGET(Ext_nEngClc0, u16LocalExt_nEngClc0);
   if (u16LocalExt_nEngClc0 >= s32LocalCompare)
   {
      IdlSys_bAuthIdlCtlNEng = 1;
   }
   else
   {
      IdlSys_bAuthIdlCtlNEng = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidDet_etat_moteur                                  */
/* !Description :  Dans l’état initial, le ralenti est désactivé. Ensuite pour*/
/*                 activer les fonctions ralenti, on considère l’état de la   */
/*                 structure couple, les demandes d’arrêt moteur, et le       */
/*                 franchissement d’un seuil de régime.                       */
/* !Number      :  FCT4.3                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_022.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  input uint8 CoStrtRStrt_stStopCutReq;                                     */
/*  input boolean IdlSys_bAcvStrtTqSys;                                       */
/*  input boolean CoEs_bAcvInjCutOffSTTEs;                                    */
/*  input boolean IdlSys_bDiCutOffSTTEs_C;                                    */
/*  input boolean IdlSys_bAuthIdlCtlStEng;                                    */
/*  input boolean IdlSys_bAuthIdlCtlNEng;                                     */
/*  input boolean IdlSys_bDiCutOffSTTEs;                                      */
/*  output boolean IdlSys_bDiCutOffSTTEs;                                     */
/*  output boolean IdlSys_bAuthIdlCtlStEng;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidDet_etat_moteur(void)
{
   boolean bLocalInhIdlSys;
   boolean bLocalIdlSys_bAcvStrtTqSys;
   boolean bLocalCoEs_bAcvInjCutOffSTTEs;
   uint8   u8LocalCoStrtRStrt_stStopCutReq;


   VEMS_vidGET(CoStrtRStrt_stStopCutReq, u8LocalCoStrtRStrt_stStopCutReq);
   VEMS_vidGET(IdlSys_bAcvStrtTqSys, bLocalIdlSys_bAcvStrtTqSys);
   VEMS_vidGET(CoEs_bAcvInjCutOffSTTEs, bLocalCoEs_bAcvInjCutOffSTTEs);
   bLocalInhIdlSys = GDGAR_bGetFRM(FRM_FRM_INHIDLSYS);
   IdlSys_bDiCutOffSTTEs = IdlSys_bDiCutOffSTTEs_C;
   if (IdlSys_bAuthIdlCtlStEng == 0)
   {
      if (  (u8LocalCoStrtRStrt_stStopCutReq  == 0)
         && (bLocalIdlSys_bAcvStrtTqSys != 0)
         && (IdlSys_bAuthIdlCtlNEng != 0)
         && (bLocalInhIdlSys == 0))
      {
         IdlSys_bAuthIdlCtlStEng = 1;
      }
   }
   else
   {
      if (  (u8LocalCoStrtRStrt_stStopCutReq == 1)
         || (  (u8LocalCoStrtRStrt_stStopCutReq == 2)
            && (  (bLocalCoEs_bAcvInjCutOffSTTEs != 0)
               || (IdlSys_bDiCutOffSTTEs != 0)))
         || (bLocalIdlSys_bAcvStrtTqSys == 0)
         || (bLocalInhIdlSys != 0))
      {
         IdlSys_bAuthIdlCtlStEng = 0;
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidDeterminer_inj_dyn                               */
/* !Description :  L’activation dynamique permet d’activer le régulateur de   */
/*                 ralenti sur une condition comparant la dynamique du moteur */
/*                 avec celle nécessaire pour réaliser l’entrée au ralenti    */
/*                 attendue.                                                  */
/* !Number      :  FCT4.4                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_023.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 IdlSys_jVeh;                                                 */
/*  input sint16 IdlSys_nGrdTarIdl;                                           */
/*  input sint16 IdlSys_nGrdEng;                                              */
/*  input sint16 IdlSys_tqEfcTarIdl_MP;                                       */
/*  input sint16 IdlSys_tqEfcEngReal_MP;                                      */
/*  input sint16 IdlSys_tqIdcIdlMin;                                          */
/*  input sint16 IdlSys_tqLoAcvIdlCtlDyn_MP;                                  */
/*  input uint8 IdlSys_noGear;                                                */
/*  input uint8 IdlSys_tqLoAcvIdlCtlDyn_T[4];                                 */
/*  input sint16 IdlSys_tqHiAcvIdlCtlDyn_MP;                                  */
/*  input uint8 IdlSys_tqHiAcvIdlCtlDyn_T[4];                                 */
/*  input uint16 Ext_nEngClc0;                                                */
/*  input uint16 TqSys_nTarIdl;                                               */
/*  input sint16 IdlSys_nInhInjDyn_T[4];                                      */
/*  input boolean IDLMGR_bBasculeRS;                                          */
/*  input boolean IdlSys_bAcvNThd_MP;                                         */
/*  output sint16 IdlSys_tqEfcTarIdl_MP;                                      */
/*  output sint16 IdlSys_tqEfcEngReal_MP;                                     */
/*  output sint16 IdlSys_tqLoAcvIdlCtlDyn_MP;                                 */
/*  output sint16 IdlSys_tqHiAcvIdlCtlDyn_MP;                                 */
/*  output boolean IDLMGR_bBasculeRS;                                         */
/*  output boolean IdlSys_bAcvNThd_MP;                                        */
/*  output boolean IdlSys_bAcvIdlCtlDyn;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidDeterminer_inj_dyn(void)
{
   uint8   u8LocalIdlSys_noGear;
   uint16  u16LocalLoAcvIdlCtlDyn;
   uint16  u16LocalExt_nEngClc0;
   uint16  u16LocalTqSys_nTarIdl;
   sint16  s16LocalIdlSys_tqIdcIdlMin;
   uint32  u32LocaltqEfcTarIdl_MP;
   sint32  s32LocalSum;
   sint32  s32LocalAcvIdlCtlDyn_MP;


   u32LocaltqEfcTarIdl_MP =
      (uint32)MATHSRV_udtABS(IdlSys_nGrdTarIdl * (IdlSys_jVeh + 1));
   if (u32LocaltqEfcTarIdl_MP > 2444619)
   {
      if (IdlSys_nGrdTarIdl > 0)
      {
         IdlSys_tqEfcTarIdl_MP = 32000;
      }
      else
      {
         IdlSys_tqEfcTarIdl_MP = -32000;
      }
   }
   else
   {
      if (IdlSys_nGrdTarIdl > 0)
      {
         IdlSys_tqEfcTarIdl_MP =
            (sint16)((u32LocaltqEfcTarIdl_MP * 71) / 5424);
      }
      else
      {
         IdlSys_tqEfcTarIdl_MP =
            (sint16)((sint32)((-1)*(u32LocaltqEfcTarIdl_MP * 71)) / 5424);
      }
   }
   u32LocaltqEfcTarIdl_MP =
      (uint32)MATHSRV_udtABS(IdlSys_nGrdEng * (IdlSys_jVeh + 1));
   if (u32LocaltqEfcTarIdl_MP > 2444619)
   {
      if (IdlSys_nGrdEng > 0)
      {
         IdlSys_tqEfcEngReal_MP = 32000;
      }
      else
      {
         IdlSys_tqEfcEngReal_MP = -32000;
      }
   }
   else
   {
      if (IdlSys_nGrdEng > 0)
      {
         IdlSys_tqEfcEngReal_MP =
            (sint16)((u32LocaltqEfcTarIdl_MP * 71) / 5424);
      }
      else
      {
         IdlSys_tqEfcEngReal_MP =
            (sint16)((sint32)((-1)*(u32LocaltqEfcTarIdl_MP * 71)) / 5424);
      }
   }
   s32LocalAcvIdlCtlDyn_MP = IdlSys_tqEfcTarIdl_MP - IdlSys_tqEfcEngReal_MP;
   IdlSys_tqLoAcvIdlCtlDyn_MP =
      (sint16)MATHSRV_udtCLAMP(s32LocalAcvIdlCtlDyn_MP, -32000, 32000);
   VEMS_vidGET(IdlSys_tqIdcIdlMin, s16LocalIdlSys_tqIdcIdlMin);
   s32LocalAcvIdlCtlDyn_MP =
      IdlSys_tqLoAcvIdlCtlDyn_MP - s16LocalIdlSys_tqIdcIdlMin;
   IdlSys_tqHiAcvIdlCtlDyn_MP =
      (sint16)MATHSRV_udtCLAMP(s32LocalAcvIdlCtlDyn_MP, -32000, 32000);

   s32LocalAcvIdlCtlDyn_MP = IdlSys_tqLoAcvIdlCtlDyn_MP + 400;
   VEMS_vidGET(IdlSys_noGear, u8LocalIdlSys_noGear);
   u8LocalIdlSys_noGear = (uint8)MATHSRV_udtMIN(u8LocalIdlSys_noGear, 3);

   u16LocalLoAcvIdlCtlDyn =
      (uint16)(4 * IdlSys_tqLoAcvIdlCtlDyn_T[u8LocalIdlSys_noGear]);
   if (s32LocalAcvIdlCtlDyn_MP < u16LocalLoAcvIdlCtlDyn)
   {
      IDLMGR_bBasculeRS = 0;
   }
   else
   {
      s32LocalAcvIdlCtlDyn_MP = IdlSys_tqHiAcvIdlCtlDyn_MP + 400;
      u16LocalLoAcvIdlCtlDyn =
         (uint16)(4 * IdlSys_tqHiAcvIdlCtlDyn_T[u8LocalIdlSys_noGear]);
      if (s32LocalAcvIdlCtlDyn_MP >= u16LocalLoAcvIdlCtlDyn)
      {
         IDLMGR_bBasculeRS = 1;
      }
   }
   VEMS_vidGET(Ext_nEngClc0, u16LocalExt_nEngClc0);
   VEMS_vidGET(TqSys_nTarIdl, u16LocalTqSys_nTarIdl);
   s32LocalSum = (sint32)(40 * IdlSys_nInhInjDyn_T[u8LocalIdlSys_noGear]);
   s32LocalSum = s32LocalSum + u16LocalTqSys_nTarIdl;
   if (u16LocalExt_nEngClc0 < s32LocalSum)
   {
      IdlSys_bAcvNThd_MP = 1;
   }
   else
   {
      IdlSys_bAcvNThd_MP = 0;
   }
   if (  (IDLMGR_bBasculeRS != 0)
      && (IdlSys_bAcvNThd_MP != 0))
   {
      IdlSys_bAcvIdlCtlDyn = 1;
   }
   else
   {
      IdlSys_bAcvIdlCtlDyn = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidDet_regime_critique                              */
/* !Description :  On demande l’activation du ralenti lorsque le régime moteur*/
/*                 est proche de la consigne statique.On demande la           */
/*                 désactivation du ralenti lorsque le régime moteur est      */
/*                 supérieur au seuil d’activation décrit précédemment plus un*/
/*                 offset calibrable.                                         */
/* !Number      :  FCT4.5                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_024.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 TqSys_nTarIdl;                                               */
/*  input uint8 IdlSys_noGear;                                                */
/*  input uint16 IdlSys_nOfsAcvIdlCtl_T[4];                                   */
/*  input uint16 IdlSys_nOfsDeacIdlCtl_T[4];                                  */
/*  input uint16 IdlSys_nOfsAcvIdlCtl_MP;                                     */
/*  input uint16 IdlSys_nOfsDeacIdlCtl_MP;                                    */
/*  input uint16 Ext_nEngClc0;                                                */
/*  output uint16 IdlSys_nOfsAcvIdlCtl_MP;                                    */
/*  output uint16 IdlSys_nOfsDeacIdlCtl_MP;                                   */
/*  output boolean IdlSys_bDeacIdlCtlEngSpd;                                  */
/*  output boolean IdlSys_bAcvIdlCtlEngSpd;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidDet_regime_critique(void)
{
   uint8  u8LocalIdlSys_noGear;
   uint16 u16LocalIdlSysIdlCtl;
   uint16 u16LocalTqSys_nTarIdl;
   uint16 u16LocalExt_nEngClc0;
   uint32 u32Localcomp;


   VEMS_vidGET(TqSys_nTarIdl, u16LocalTqSys_nTarIdl);
   VEMS_vidGET(IdlSys_noGear, u8LocalIdlSys_noGear);
   u8LocalIdlSys_noGear = (uint8)MATHSRV_udtMIN(u8LocalIdlSys_noGear, 3);
   u16LocalIdlSysIdlCtl = IdlSys_nOfsAcvIdlCtl_T[u8LocalIdlSys_noGear];
   IdlSys_nOfsAcvIdlCtl_MP = (uint16)MATHSRV_udtMIN(u16LocalIdlSysIdlCtl, 8000);
   u16LocalIdlSysIdlCtl = IdlSys_nOfsDeacIdlCtl_T[u8LocalIdlSys_noGear];
   IdlSys_nOfsDeacIdlCtl_MP =
      (uint16)MATHSRV_udtMIN(u16LocalIdlSysIdlCtl, 8000);
   u32Localcomp =
      (uint32)( ( ( IdlSys_nOfsAcvIdlCtl_MP
                  + IdlSys_nOfsDeacIdlCtl_MP)
                * 4)
              + u16LocalTqSys_nTarIdl);
   VEMS_vidGET(Ext_nEngClc0, u16LocalExt_nEngClc0);

   if (u32Localcomp < u16LocalExt_nEngClc0)
   {
      IdlSys_bDeacIdlCtlEngSpd = 1;
   }
   else
   {
      IdlSys_bDeacIdlCtlEngSpd = 0;
   }
   u32Localcomp = (uint32)( (4 * IdlSys_nOfsAcvIdlCtl_MP)
                          + u16LocalTqSys_nTarIdl);
   if (u16LocalExt_nEngClc0 <= u32Localcomp)
   {
      IdlSys_bAcvIdlCtlEngSpd = 1;
   }
   else
   {
      IdlSys_bAcvIdlCtlEngSpd = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidDet_ralenti_effectif                             */
/* !Description :  Dans ce bloc, on détermine si le régulateur de ralenti     */
/*                 n’est plus effectif pour autoriser sa coupure.             */
/* !Number      :  FCT4.6                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_025.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 IdlSys_tqIdcIdlNotSat;                                       */
/*  input sint16 TqSys_tqIdcEngIdlCord;                                       */
/*  input uint8 IdlSys_noGear;                                                */
/*  input uint8 IdlSys_tqOfsLoEngNOnIdl_T[4];                                 */
/*  output boolean IdlSys_bEngNOnIdl;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidDet_ralenti_effectif(void)
{
   uint8  u8LocalIdlSys_noGear;
   sint16 s16LocalIdlSys_tqIdcIdlNotSat;
   sint16 s16LocalTqSys_tqIdcEngIdlCord;
   sint32 s32LocalEng;
   sint32 s32LocalDif;


   VEMS_vidGET(IdlSys_tqIdcIdlNotSat, s16LocalIdlSys_tqIdcIdlNotSat);
   VEMS_vidGET(TqSys_tqIdcEngIdlCord, s16LocalTqSys_tqIdcEngIdlCord);
   VEMS_vidGET(IdlSys_noGear, u8LocalIdlSys_noGear);

   s32LocalDif = s16LocalIdlSys_tqIdcIdlNotSat - s16LocalTqSys_tqIdcEngIdlCord;
   u8LocalIdlSys_noGear = (uint8)MATHSRV_udtMIN(u8LocalIdlSys_noGear, 3);
   s32LocalEng =
      (sint32)((4 * IdlSys_tqOfsLoEngNOnIdl_T[u8LocalIdlSys_noGear]) - 800);
   if (s32LocalDif <= s32LocalEng)
   {
      IdlSys_bEngNOnIdl = 0;
   }
   else
   {
      if (s32LocalDif >= 0)
      {
         IdlSys_bEngNOnIdl = 1;
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidDet_chang_etat_rampage                           */
/* !Description :  Dans ce bloc, on détermine si l’état de rampage BVMP a     */
/*                 changé d’état et de provoquer une réinitialisation du      */
/*                 régulateur si c’est le cas.                                */
/* !Number      :  FCT4.7                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_026.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean IdlSys_bAcvIdlCrawl;                                        */
/*  input boolean IDLMGR_bAcvIdlCrawlPrev;                                    */
/*  output boolean IdlSys_bIniIdlCtlCrawlChg;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidDet_chang_etat_rampage(void)
{

   if (  (  (IdlSys_bAcvIdlCrawl != 0)
         && (IDLMGR_bAcvIdlCrawlPrev == 0))
      || (  (IdlSys_bAcvIdlCrawl == 0)
         && ( IDLMGR_bAcvIdlCrawlPrev != 0)))
   {
      IdlSys_bIniIdlCtlCrawlChg = 1;
   }
   else
   {
      IdlSys_bIniIdlCtlCrawlChg = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidReinit_en_surregime                              */
/* !Description :  Ce module  détecte  le  besoin  de  réinitialiser  le      */
/*                 régulateur  de  ralenti  et  la  consigne  dynamique  lors */
/*                 d’une forte envolée de régime.                             */
/* !Number      :  FCT4.8                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_027.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 TqSys_nTarIdl;                                               */
/*  input uint16 Ext_nEngClc0;                                                */
/*  input uint16 IdlSys_nOfsIniTarIdl_C;                                      */
/*  input uint16 IdlSys_nOfsIniTarIdlDyn_C;                                   */
/*  input uint16 IdlSys_nTarIdlDynPrev;                                       */
/*  input boolean IdlSys_bAcvIdlCtlDyn;                                       */
/*  input boolean IDLMGR_bAcvIdlCtlDynPrev;                                   */
/*  output boolean IdlSys_bIniIdlCtlDyn;                                      */
/*  output boolean IDLMGR_bAcvIdlCtlDynPrev;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidReinit_en_surregime(void)
{
   uint16 u16LocalExt_nEngClc0;
   uint16 u16LocalTqSys_nTarIdl;
   uint32 u32LocalSumOpOut;
   uint32 u32LocalSumOp2Out;


   VEMS_vidGET(TqSys_nTarIdl, u16LocalTqSys_nTarIdl);
   VEMS_vidGET(Ext_nEngClc0, u16LocalExt_nEngClc0);
   u32LocalSumOpOut = (uint32)( u16LocalTqSys_nTarIdl
                              + (IdlSys_nOfsIniTarIdl_C * 4));
   u32LocalSumOp2Out = (uint32)( (IdlSys_nOfsIniTarIdlDyn_C * 4)
                               + IdlSys_nTarIdlDynPrev);

   if (  (u32LocalSumOpOut < u16LocalExt_nEngClc0)
      && (u16LocalExt_nEngClc0 > u32LocalSumOp2Out)
      && (IdlSys_bAcvIdlCtlDyn != 0)
      && (IDLMGR_bAcvIdlCtlDynPrev == 0))
   {
      IdlSys_bIniIdlCtlDyn = 1;
   }
   else
   {
      IdlSys_bIniIdlCtlDyn = 0;
   }
   IDLMGR_bAcvIdlCtlDynPrev = IdlSys_bAcvIdlCtlDyn;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidChange_rapport_boite                             */
/* !Description :  Sur  variation  de  l’information  rapport  de  boite      */
/*                 engagé  d’une  mesure  à  l’autre,  une  information       */
/*                 indiquant un changement de rapport est levée.              */
/* !Number      :  FCT4.9                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_028.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 IdlSys_noGear;                                                */
/*  input uint8 IdlSys_noGearPrev;                                            */
/*  output boolean IdlSys_bIniIdlCtlGearChg;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidChange_rapport_boite(void)
{
   uint8 u8LocalIdlSys_noGear;


   VEMS_vidGET(IdlSys_noGear, u8LocalIdlSys_noGear);
   if (u8LocalIdlSys_noGear != IdlSys_noGearPrev)
   {
      IdlSys_bIniIdlCtlGearChg = 1;
   }
   else
   {
      IdlSys_bIniIdlCtlGearChg = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidDet_changement_mode                              */
/* !Description :  Sur variation du sélecteur de gains pour le régulateur     */
/*                 d’une mesure à l’autre, une information indiquant un       */
/*                 changement de rapport est levée, et une réinitialisation du*/
/*                 régulateur est effectuée.                                  */
/* !Number      :  FCT4.10                                                    */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_029.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 IdlSys_idxIdlCtlMod;                                          */
/*  input uint8 IDLMGR_u8IdxIdlCtlModPrev;                                    */
/*  output boolean IdlSys_bIniIdlCtlModChg;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidDet_changement_mode(void)
{
   uint8 u8LocalIdlSys_idxIdlCtlMod;


   VEMS_vidGET(IdlSys_idxIdlCtlMod, u8LocalIdlSys_idxIdlCtlMod);
   if (u8LocalIdlSys_idxIdlCtlMod != IDLMGR_u8IdxIdlCtlModPrev)
   {
      IdlSys_bIniIdlCtlModChg = 1;
   }
   else
   {
      IdlSys_bIniIdlCtlModChg = 0;
   }
}
/*------------------------------- end of file --------------------------------*/