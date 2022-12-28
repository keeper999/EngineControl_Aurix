/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : RELBRKASIACQ                                            */
/* !Description     : RELBRKASIACQ Component                                  */
/*                                                                            */
/* !Module          : RELBRKASIACQ                                            */
/* !Description     : Relative Mastervac Pressure Acquisition                 */
/*                                                                            */
/* !File            : RELBRKASIACQ_FCT1.C                                     */
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
/*   1 / RELBRKASIACQ_VidInitOutput                                           */
/*   2 / RELBRKASIACQ_vidInit                                                 */
/*   3 / RELBRKASIACQ_vidCalc                                                 */
/*   4 / RELBRKASIACQ_vidAcqusition                                           */
/*   5 / RELBRKASIACQ_vidDiagnosis                                            */
/*   6 / RELBRKASIACQ_vidScpScgDiag                                           */
/*   7 / RELBRKASIACQ_vidGrdDiag                                              */
/*   8 / RELBRKASIACQ_vidFiltering                                            */
/*   9 / RELBRKASIACQ_vidLinearization                                        */
/*   10 / RELBRKASIACQ_vidSelection                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_6547160 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/RELBRKASIACQ/RELBRKASIACQ_FCT1.C_v$*/
/* $Revision::   1.4      $$Author::   achebino       $$Date::   26 May 2014 $*/
/* $Author::   achebino                               $$Date::   26 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "RELBRKASIACQ.h"
#include "RELBRKASIACQ_L.h"
#include "RELBRKASIACQ_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RELBRKASIACQ_VidInitOutput                                 */
/* !Description :  Fonction d'initialisation                                  */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_pRelBrkAsiMesSI;                                          */
/*  input uint16 Ext_uRelBrkAsi;                                              */
/*  input boolean Ext_bDgoScp_pRelBrkAsi;                                     */
/*  input boolean Ext_bDgoScg_pRelBrkAsi;                                     */
/*  output boolean AirPres_bDftSftyScg_pRelBrkAsi;                            */
/*  output boolean AirPres_bDftSftyScp_pRelBrkAsi;                            */
/*  output uint16 Ext_uRelBrkAsi;                                             */
/*  output uint16 RELBRKASIACQ_u16ExtReBrAsiPrev;                             */
/*  output uint32 RELBRKASIACQ_u32OutFilterMem;                               */
/*  output uint8 Ext_pRelBrkAsiMem;                                           */
/*  output uint8 RELBRKASIACQ_u8CntFilt_1;                                    */
/*  output uint8 RELBRKASIACQ_u8CntFilt_2;                                    */
/*  output uint8 AirPres_ctDftSftyScp_pRelBrkAsi;                             */
/*  output uint8 AirPres_ctDftSftyScg_pRelBrkAsi;                             */
/*  output boolean Ext_bDgoScp_pRelBrkAsi;                                    */
/*  output boolean Ext_bDgoScg_pRelBrkAsi;                                    */
/*  output boolean Ext_bDgoGrd_pRelBrkAsi;                                    */
/*  output uint16 Ext_uRelBrkAsiFil;                                          */
/*  output boolean RELBRKASIACQ_bFilSig_1;                                    */
/*  output boolean RELBRKASIACQ_bFilSig_2;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RELBRKASIACQ_VidInitOutput(void)
{
   uint8 u8LocalExt_pRelBrkAsiMesSI;


   /* Outputs initialization */
   VEMS_vidSET(AirPres_bDftSftyScg_pRelBrkAsi, 0);
   VEMS_vidSET(AirPres_bDftSftyScp_pRelBrkAsi, 0);

   VEMS_vidGET(Ext_pRelBrkAsiMesSI, u8LocalExt_pRelBrkAsiMesSI);

   /* Previous values initialization */
   Ext_uRelBrkAsi = 0;
   RELBRKASIACQ_u16ExtReBrAsiPrev = Ext_uRelBrkAsi;
   RELBRKASIACQ_u32OutFilterMem = (uint32)(Ext_uRelBrkAsi * 65536);
   Ext_pRelBrkAsiMem =
      (uint8)MATHSRV_udtCLAMP(u8LocalExt_pRelBrkAsiMesSI, 2, 125);

   /* SAFETY counter initialization */
   RELBRKASIACQ_u8CntFilt_1 = 0;
   RELBRKASIACQ_u8CntFilt_2 = 0;
   AirPres_ctDftSftyScp_pRelBrkAsi = 0;
   AirPres_ctDftSftyScg_pRelBrkAsi = 0;
   Ext_bDgoScp_pRelBrkAsi = 0;
   Ext_bDgoScg_pRelBrkAsi = 0;
   Ext_bDgoGrd_pRelBrkAsi = 0;
   Ext_uRelBrkAsiFil = 0;
   RELBRKASIACQ_bFilSig_1 = Ext_bDgoScp_pRelBrkAsi;
   RELBRKASIACQ_bFilSig_2 = Ext_bDgoScg_pRelBrkAsi;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RELBRKASIACQ_vidInit                                       */
/* !Description :  The output of the function is initialized at               */
/*                 Ext_pRelBrkAsiIni_C.                                       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_pRelBrkAsiIni_C;                                          */
/*  input uint8 AirPres_noAcvGrdDiag_C;                                       */
/*  output uint8 Ext_pRelBrkAsiMesSI;                                         */
/*  output uint8 Ext_pRelBrkAsiMes;                                           */
/*  output uint8 AirPres_ctAcvGrdDiag;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RELBRKASIACQ_vidInit(void)
{
   uint8    u8LocalExt_pRelBrkAsiMesSI;


   u8LocalExt_pRelBrkAsiMesSI = Ext_pRelBrkAsiIni_C;
   u8LocalExt_pRelBrkAsiMesSI =
      (uint8)MATHSRV_udtCLAMP(u8LocalExt_pRelBrkAsiMesSI, 2, 125);
   VEMS_vidSET(Ext_pRelBrkAsiMesSI, u8LocalExt_pRelBrkAsiMesSI);
   VEMS_vidSET(Ext_pRelBrkAsiMes, u8LocalExt_pRelBrkAsiMesSI);
   AirPres_ctAcvGrdDiag = (uint8)MATHSRV_udtMIN(AirPres_noAcvGrdDiag_C, 7);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RELBRKASIACQ_vidCalc                                       */
/* !Description :  This function calculates the relative mastervac pressure.  */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_E_11_07345_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void RELBRKASIACQ_vidAcqusition();                            */
/*  extf argret void RELBRKASIACQ_vidDiagnosis();                             */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  extf argret void RELBRKASIACQ_vidFiltering();                             */
/*  extf argret void RELBRKASIACQ_vidLinearization();                         */
/*  extf argret void RELBRKASIACQ_vidSelection();                             */
/*  input boolean Ext_bDgoScp_pRelBrkAsi;                                     */
/*  input boolean Ext_bMonRunScp_pRelBrkAsi;                                  */
/*  input boolean Ext_bDgoScg_pRelBrkAsi;                                     */
/*  input boolean Ext_bMonRunScg_pRelBrkAsi;                                  */
/*  input boolean Ext_bDgoGrd_pRelBrkAsi;                                     */
/*  input boolean Ext_bMonRunGrd_pRelBrkAsi;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RELBRKASIACQ_vidCalc(void)
{
   RELBRKASIACQ_vidAcqusition();
   RELBRKASIACQ_vidDiagnosis();
   GDGAR_vidGdu(GD_DFT_SCP_PRELBRKASI,
                Ext_bDgoScp_pRelBrkAsi,
                Ext_bMonRunScp_pRelBrkAsi,
                DIAG_DISPO);
   GDGAR_vidGdu(GD_DFT_SCG_PRELBRKASI,
                Ext_bDgoScg_pRelBrkAsi,
                Ext_bMonRunScg_pRelBrkAsi,
                DIAG_DISPO);
   GDGAR_vidGdu(GD_DFT_GRD_PRELBRKASI,
                Ext_bDgoGrd_pRelBrkAsi,
                Ext_bMonRunGrd_pRelBrkAsi,
                DIAG_DISPO);
   RELBRKASIACQ_vidFiltering();
   RELBRKASIACQ_vidLinearization();
   RELBRKASIACQ_vidSelection();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RELBRKASIACQ_vidAcqusition                                 */
/* !Description :  This function makes the acquisition of the relative        */
/*                 mastervac pressure sensor voltage.                         */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_E_11_07345_016.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_uRelBrkAsi;                                              */
/*  input uint16 Acquisition_press_mast_rel;                                  */
/*  input uint8 AirPres_ctAcvGrdDiag;                                         */
/*  output uint16 RELBRKASIACQ_u16ExtReBrAsiPrev;                             */
/*  output uint16 Ext_uRelBrkAsi;                                             */
/*  output uint8 AirPres_ctAcvGrdDiag;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RELBRKASIACQ_vidAcqusition(void)
{
   uint16   u16LocalAcquis_press_mast_rel;
   sint16   s16LocalAirPres_ctAcvGrdDiag;


   RELBRKASIACQ_u16ExtReBrAsiPrev = (uint16)MATHSRV_udtMIN(Ext_uRelBrkAsi,
                                                           4095);
   VEMS_vidGET(Acquisition_press_mast_rel, u16LocalAcquis_press_mast_rel);
   Ext_uRelBrkAsi = (uint16)MATHSRV_udtMIN(u16LocalAcquis_press_mast_rel, 4095);
   s16LocalAirPres_ctAcvGrdDiag = (sint16)(AirPres_ctAcvGrdDiag - 1);
   AirPres_ctAcvGrdDiag =
      (uint8)MATHSRV_udtCLAMP(s16LocalAirPres_ctAcvGrdDiag, 0, 7);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RELBRKASIACQ_vidDiagnosis                                  */
/* !Description :  This function makes the diagnosis of the information. There*/
/*                 are 3 different diagnosis, one for the max value of the    */
/*                 voltage, another one for the min value and the last one    */
/*                 controls the gradient of the measured voltage.             */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_E_11_07345_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf argret void RELBRKASIACQ_vidScpScgDiag();                            */
/*  extf argret void RELBRKASIACQ_vidGrdDiag();                               */
/*  input boolean Ext_bDgoScp_pRelBrkAsi;                                     */
/*  input boolean Ext_bDgoScg_pRelBrkAsi;                                     */
/*  input uint8 AirPres_ctAcvGrdDiag;                                         */
/*  output boolean Ext_bMonRunScp_pRelBrkAsi;                                 */
/*  output boolean Ext_bMonRunScg_pRelBrkAsi;                                 */
/*  output boolean Ext_bMonRunGrd_pRelBrkAsi;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RELBRKASIACQ_vidDiagnosis(void)
{
   boolean  bLocalFRM_bInhDiag_pRelBrkAsi;


   bLocalFRM_bInhDiag_pRelBrkAsi = GDGAR_bGetFRM(FRM_FRM_INHDIAG_PRELBRKASI);
   if (bLocalFRM_bInhDiag_pRelBrkAsi == 0)
   {
      RELBRKASIACQ_vidScpScgDiag();
      Ext_bMonRunScp_pRelBrkAsi = 1;
      Ext_bMonRunScg_pRelBrkAsi = 1;
      if (  (Ext_bDgoScp_pRelBrkAsi == 0)
         && (Ext_bDgoScg_pRelBrkAsi == 0)
         && (AirPres_ctAcvGrdDiag == 0))
      {
         Ext_bMonRunGrd_pRelBrkAsi = 1;
         RELBRKASIACQ_vidGrdDiag();
      }
      else
      {
         Ext_bMonRunGrd_pRelBrkAsi = 0;
      }
   }
   else
   {
      Ext_bMonRunScp_pRelBrkAsi = 0;
      Ext_bMonRunScg_pRelBrkAsi = 0;
      Ext_bMonRunGrd_pRelBrkAsi = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RELBRKASIACQ_vidScpScgDiag                                 */
/* !Description :  This function checks if the measured voltage is up to a max*/
/*                 defined threshold, then it activates the boolean of Scp    */
/*                 diagnosis. And if the measured voltage is under a min      */
/*                 defined threshold, it activates the boolean of Scg         */
/*                 diagnosis.                                                 */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_E_11_07345_012.01                                     */
/*                 VEMS_E_11_07345_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Ext_uRelBrkAsi;                                              */
/*  input uint16 Ext_uDgoScp_pRelBrkAsi_C;                                    */
/*  input uint16 Ext_uDgoScg_pRelBrkAsi_C;                                    */
/*  output boolean Ext_bDgoScp_pRelBrkAsi;                                    */
/*  output boolean Ext_bDgoScg_pRelBrkAsi;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RELBRKASIACQ_vidScpScgDiag(void)
{
   if (Ext_uRelBrkAsi > Ext_uDgoScp_pRelBrkAsi_C)
   {
      Ext_bDgoScp_pRelBrkAsi = 1;
   }
   else
   {
      Ext_bDgoScp_pRelBrkAsi = 0;
   }

   if (Ext_uRelBrkAsi < Ext_uDgoScg_pRelBrkAsi_C)
   {
      Ext_bDgoScg_pRelBrkAsi = 1;
   }
   else
   {
      Ext_bDgoScg_pRelBrkAsi = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RELBRKASIACQ_vidGrdDiag                                    */
/* !Description :  In thif function, if the difference between the current    */
/*                 voltage and the voltage at previous step is greater than a */
/*                 defined threshold, the Boolean of Grd diagnosis is         */
/*                 activated.                                                 */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_E_11_07345_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Ext_uRelBrkAsi;                                              */
/*  input uint16 RELBRKASIACQ_u16ExtReBrAsiPrev;                              */
/*  input uint16 Ext_uDgoGrd_pRelBrkAsi_C;                                    */
/*  output boolean Ext_bDgoGrd_pRelBrkAsi;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RELBRKASIACQ_vidGrdDiag(void)
{
   uint16 u16LocalABS;
   uint32 u32LocalExt_uDgoGrd_pRelBrkAsi_C;
   sint32 s32LocalExt_uRelBrkAsiDiff;


   s32LocalExt_uRelBrkAsiDiff =
      (sint32)(Ext_uRelBrkAsi - RELBRKASIACQ_u16ExtReBrAsiPrev);
   u16LocalABS = (uint16)MATHSRV_udtABS(s32LocalExt_uRelBrkAsiDiff);
   u32LocalExt_uDgoGrd_pRelBrkAsi_C =
      (uint32)(((Ext_uDgoGrd_pRelBrkAsi_C * 625) + 256) / 512);
   if (u16LocalABS > u32LocalExt_uDgoGrd_pRelBrkAsi_C)
   {
      Ext_bDgoGrd_pRelBrkAsi = 1;
   }
   else
   {
      Ext_bDgoGrd_pRelBrkAsi = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RELBRKASIACQ_vidFiltering                                  */
/* !Description :  In this function, the raw voltage of the relative mastervac*/
/*                 pressure sensor is filtered by a first order filter.       */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_E_11_07345_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Ext_facRelBrkAsiFilCoef_C;                                   */
/*  input uint32 RELBRKASIACQ_u32OutFilterMem;                                */
/*  input uint16 Ext_uRelBrkAsi;                                              */
/*  input uint16 Ext_uRelBrkAsiFil;                                           */
/*  output uint16 Ext_uRelBrkAsiFil;                                          */
/*  output uint32 RELBRKASIACQ_u32OutFilterMem;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RELBRKASIACQ_vidFiltering(void)
{
   uint16   u16LocalFilterGain;
   uint16   u16LocalExt_uRelBrkAsiFil;


   if (Ext_facRelBrkAsiFilCoef_C < 1000)
   {
      u16LocalFilterGain = (uint16)( ( (Ext_facRelBrkAsiFilCoef_C * 8192)
                                     + 63)
                                   / 125);
      u16LocalExt_uRelBrkAsiFil =
         MATHSRV_u16FirstOrderFilterGu16(u16LocalFilterGain,
                                         &RELBRKASIACQ_u32OutFilterMem,
                                         Ext_uRelBrkAsi);
   }
   else
   {
      u16LocalExt_uRelBrkAsiFil = Ext_uRelBrkAsi;
   }
   Ext_uRelBrkAsiFil = (uint16)MATHSRV_udtMIN(u16LocalExt_uRelBrkAsiFil, 4095);
   RELBRKASIACQ_u32OutFilterMem = (uint32)(Ext_uRelBrkAsiFil * 65536);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RELBRKASIACQ_vidLinearization                              */
/* !Description :  In this function, the measured filtered voltage is         */
/*                 converted into a pressure information.  This conversion is */
/*                 done by an interpolation between 2 setpoints.              */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_E_11_07345_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 AirPres_uRelBrkAsi_A[2];                                     */
/*  input uint8 AirPres_pRelBrkAsi_T[2];                                      */
/*  input uint16 Ext_uRelBrkAsiFil;                                           */
/*  output uint8 Ext_pRelBrkAsiLnr;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RELBRKASIACQ_vidLinearization(void)
{
   uint16   u16LocalBKPTSup;
   uint16   u16LocalBKPTInf;
   uint16   u16LocalMapSup;
   uint16   u16LocalMapInf;
   uint16   u16LocalDiff;
   uint16   u16LocalInterpolation;
   uint16   u16LocalSiteInterpolation;
   uint16   u16LocalExt_pRelBrkAsiLnr;
   uint32   u32LocalDeltaValue;
   uint32   u32LocalInterpolation;
   uint32   u32LocalResultValue;
   sint32   s32LocalInterpolation;


   u16LocalExt_pRelBrkAsiLnr = 0;
   if (AirPres_uRelBrkAsi_A[1] >= AirPres_uRelBrkAsi_A[0])
   {
      u16LocalBKPTSup = AirPres_uRelBrkAsi_A[1];
      u16LocalBKPTInf = AirPres_uRelBrkAsi_A[0];
      u16LocalMapSup = AirPres_pRelBrkAsi_T[1];
      u16LocalMapInf = AirPres_pRelBrkAsi_T[0];
   }
   else
   {
      u16LocalBKPTSup = AirPres_uRelBrkAsi_A[0];
      u16LocalBKPTInf = AirPres_uRelBrkAsi_A[1];
      u16LocalMapSup = AirPres_pRelBrkAsi_T[0];
      u16LocalMapInf = AirPres_pRelBrkAsi_T[1];
   }
   if (AirPres_uRelBrkAsi_A[1] != AirPres_uRelBrkAsi_A[0])
   {
      if (Ext_uRelBrkAsiFil >= u16LocalBKPTSup)
      {
         u16LocalExt_pRelBrkAsiLnr = u16LocalMapSup;
      }
      if (Ext_uRelBrkAsiFil < u16LocalBKPTInf)
      {
         u16LocalExt_pRelBrkAsiLnr = u16LocalMapInf;
      }
      if (  (Ext_uRelBrkAsiFil < u16LocalBKPTSup)
         && (Ext_uRelBrkAsiFil >= u16LocalBKPTInf))
      {
         /* Calculate the "Para" value of Ext_uRelBrkAsiFil with
            AirPres_uRelBrkAsi_A */

         u32LocalDeltaValue = (uint32)(Ext_uRelBrkAsiFil - u16LocalBKPTInf);
         u32LocalDeltaValue = u32LocalDeltaValue << 16;
         u16LocalInterpolation = (uint16)(u16LocalBKPTSup - u16LocalBKPTInf);
         u16LocalSiteInterpolation =
            (uint16)(u32LocalDeltaValue / u16LocalInterpolation);
         /* Calculate the interpolation value on AirPres_pRelBrkAsi_T */

         s32LocalInterpolation = (sint32)(u16LocalMapSup - u16LocalMapInf);
         u16LocalDiff = (uint16)MATHSRV_udtABS(s32LocalInterpolation);
         if (s32LocalInterpolation > 0)
         {
            u32LocalInterpolation = u16LocalDiff * u16LocalSiteInterpolation;
            s32LocalInterpolation = (sint32)( (u32LocalInterpolation + 32768)
                                            / 65536);
         }
         else
         {
            u32LocalInterpolation = u16LocalDiff * u16LocalSiteInterpolation;
            s32LocalInterpolation = (sint32)(( u32LocalInterpolation + 32768)
                                             / 65536);
            s32LocalInterpolation = ((-1) * s32LocalInterpolation);
         }

         u32LocalResultValue =
            (uint32)((sint32)u16LocalMapInf + s32LocalInterpolation);
         u16LocalExt_pRelBrkAsiLnr = (uint16)u32LocalResultValue;
      }
   }
   else
   {
      u16LocalExt_pRelBrkAsiLnr = u16LocalMapInf;
   }
   Ext_pRelBrkAsiLnr =
      (uint8)MATHSRV_udtCLAMP(u16LocalExt_pRelBrkAsiLnr, 2, 125);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RELBRKASIACQ_vidSelection                                  */
/* !Description :  In thid function, if a punctual diagnosis is detected or if*/
/*                 the recovery flag to inhibit electrical diagnosis is set   */
/*                 then the relative mastervac pressure is frozen to its last */
/*                 valid value.                                               */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  S.BOUBAKER                                                 */
/* !Trace_To    :  VEMS_E_11_07345_010.01                                     */
/*                 VEMS_E_11_07345_015.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_pRelBrkAsiMesSI;                                          */
/*  input uint8 Ext_pRelBrkAsiRcv_C;                                          */
/*  input boolean Ext_bDgoScp_pRelBrkAsi;                                     */
/*  input boolean Ext_bDgoScg_pRelBrkAsi;                                     */
/*  input boolean Ext_bDgoGrd_pRelBrkAsi;                                     */
/*  input uint8 Ext_pRelBrkAsiLnr;                                            */
/*  output uint8 Ext_pRelBrkAsiMem;                                           */
/*  output uint8 Ext_pRelBrkAsiMesSI;                                         */
/*  output uint8 Ext_pRelBrkAsiMes;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RELBRKASIACQ_vidSelection(void)
{
   boolean  bLocalFRM_bAcvDftModpRelBrkAsi;
   boolean  bLocalFRM_bInhDiag_pRelBrkAsi;
   uint8    u8LocalExt_pRelBrkAsiMesSI;


   bLocalFRM_bAcvDftModpRelBrkAsi = GDGAR_bGetFRM(FRM_FRM_ACVDFTMOD_PRELBRKASI);
   VEMS_vidGET(Ext_pRelBrkAsiMesSI, u8LocalExt_pRelBrkAsiMesSI);
   Ext_pRelBrkAsiMem =
      (uint8)MATHSRV_udtCLAMP(u8LocalExt_pRelBrkAsiMesSI, 2, 125);
   if (bLocalFRM_bAcvDftModpRelBrkAsi != 0)
   {
      u8LocalExt_pRelBrkAsiMesSI = Ext_pRelBrkAsiRcv_C;
   }
   else
   {
      bLocalFRM_bInhDiag_pRelBrkAsi = GDGAR_bGetFRM(FRM_FRM_INHDIAG_PRELBRKASI);
      if (  (bLocalFRM_bInhDiag_pRelBrkAsi != 1)
         && (Ext_bDgoScp_pRelBrkAsi != 1)
         && (Ext_bDgoScg_pRelBrkAsi != 1)
         && (Ext_bDgoGrd_pRelBrkAsi != 1))
      {
         u8LocalExt_pRelBrkAsiMesSI = Ext_pRelBrkAsiLnr;
      }
   }
   u8LocalExt_pRelBrkAsiMesSI =
      (uint8)MATHSRV_udtCLAMP(u8LocalExt_pRelBrkAsiMesSI, 2, 125);
   VEMS_vidSET(Ext_pRelBrkAsiMesSI, u8LocalExt_pRelBrkAsiMesSI);
   VEMS_vidSET(Ext_pRelBrkAsiMes,u8LocalExt_pRelBrkAsiMesSI);
}
/*---------------------------- end of file -----------------------------------*/