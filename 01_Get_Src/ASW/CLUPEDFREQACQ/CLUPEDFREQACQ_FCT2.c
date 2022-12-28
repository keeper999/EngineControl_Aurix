/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CLUPEDFREQACQ                                           */
/* !Description     : CLUPEDFREQACQ component.                                */
/*                                                                            */
/* !Module          : CLUPEDFREQACQ                                           */
/* !Description     : ACQUISITION DE LA MESURE DU CAPTEUR D’EMBRAYAGE         */
/*                    PROPORTIONNEL.                                          */
/*                                                                            */
/* !File            : CLUPEDFREQACQ_FCT2.C                                    */
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
/*   1 / CLUPEDFREQACQ_vidGDUGrad                                             */
/*   2 / CLUPEDFREQACQ_vidDiagnosticniv2                                      */
/*   3 / CLUPEDFREQACQ_vidCluPedLnr                                           */
/*                                                                            */
/* !Reference   : PTS_DOC_6562175 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/CLUPEDFREQACQ/CLUPEDFREQACQ_FCT2.C$*/
/* $Revision::   1.5      $$Author::   achebino       $$Date::   21 May 2014 $*/
/* $Author::   achebino                               $$Date::   21 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "CLUPEDFREQACQ.h"
#include "CLUPEDFREQACQ_L.h"
#include "CLUPEDFREQACQ_IM.h"
#include "LIBSFTYLVL2.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUPEDFREQACQ_vidGDUGrad                                   */
/* !Description :  Ce bloc définit les appels au GDU pour les défauts de type */
/*                 gradient                                                   */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft,argin boolean        */
/*  bDgo,argin boolean bMonRun,argin boolean Ns_bMonWait);                    */
/*  input boolean Ext_bDgoORng_rCluPedPrssMes;                                */
/*  input boolean Ext_bMonRunORng_rCluPedPrssMes;                             */
/*  input boolean Ext_bDgoGrd_rCluPedPrssMes;                                 */
/*  input boolean Ext_bMonRunGrd_rCluPedPrssMes;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUPEDFREQACQ_vidGDUGrad(void)
{
   GDGAR_vidGdu(GD_DFT_ORNG_RCLUPEDPRSSMES,
                Ext_bDgoORng_rCluPedPrssMes,
                Ext_bMonRunORng_rCluPedPrssMes,
                DIAG_DISPO);
   GDGAR_vidGdu(GD_DFT_GRD_RCLUPEDPRSSMES,
                Ext_bDgoGrd_rCluPedPrssMes,
                Ext_bMonRunGrd_rCluPedPrssMes,
                DIAG_DISPO);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUPEDFREQACQ_vidDiagnosticniv2                            */
/* !Description :  Les diagnostics de niveau 2 sont ajoutés pour sécuriser le */
/*                 diagnostic                                                 */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bDgoScg_rCluPedPrssMes;                                 */
/*  input uint8 Clu_nUpTranThd_ScgPrssMes_C;                                  */
/*  input uint8 Clu_nDownTranThd_ScgPrssMes_C;                                */
/*  input uint8 Clu_nInitCpt_ScgPrssMes_C;                                    */
/*  input uint8 Clu_nDecCpt_ScgPrssMes_C;                                     */
/*  input uint8 CLUPEDFREQACQ_u8CntFilt_1;                                    */
/*  input boolean CLUPEDFREQACQ_bFilSig_1;                                    */
/*  input uint8 Ext_ctDftSftyScg_rCluPedPrssMes;                              */
/*  input boolean CLUPEDFREQACQ_bScgrCluPedPrsMes;                            */
/*  input boolean Ext_bDgoScp_rCluPedPrssMes;                                 */
/*  input uint8 Clu_nUpTranThd_ScpPrssMes_C;                                  */
/*  input uint8 Clu_nDownTranThd_ScpPrssMes_C;                                */
/*  input uint8 Clu_nInitCpt_ScpPrssMes_C;                                    */
/*  input uint8 Clu_nDecCpt_ScpPrssMes_C;                                     */
/*  input uint8 CLUPEDFREQACQ_u8CntFilt_2;                                    */
/*  input boolean CLUPEDFREQACQ_bFilSig_2;                                    */
/*  input uint8 Ext_ctDftSftyScp_rCluPedPrssMes;                              */
/*  input boolean CLUPEDFREQACQ_bScprCluPedPrsMes;                            */
/*  output boolean Ext_bDftSftyScg_rCluPedPrssMes;                            */
/*  output boolean CLUPEDFREQACQ_bScgrCluPedPrsMes;                           */
/*  output boolean Ext_bDftSftyScp_rCluPedPrssMes;                            */
/*  output boolean CLUPEDFREQACQ_bScprCluPedPrsMes;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUPEDFREQACQ_vidDiagnosticniv2(void)
{
   /*Safety_Level2_Scp*/
   LIBSFTYLVL2_U8_Safety_Level2(Ext_bDgoScg_rCluPedPrssMes,
                                Clu_nUpTranThd_ScgPrssMes_C,
                                Clu_nDownTranThd_ScgPrssMes_C,
                                Clu_nInitCpt_ScgPrssMes_C,
                                Clu_nDecCpt_ScgPrssMes_C,
                                &CLUPEDFREQACQ_u8CntFilt_1,
                                &CLUPEDFREQACQ_bFilSig_1,
                                &Ext_ctDftSftyScg_rCluPedPrssMes,
                                &CLUPEDFREQACQ_bScgrCluPedPrsMes);
   VEMS_vidSET(Ext_bDftSftyScg_rCluPedPrssMes, CLUPEDFREQACQ_bScgrCluPedPrsMes);
   /*Safety_Level2_Scg*/
   LIBSFTYLVL2_U8_Safety_Level2(Ext_bDgoScp_rCluPedPrssMes,
                                Clu_nUpTranThd_ScpPrssMes_C,
                                Clu_nDownTranThd_ScpPrssMes_C,
                                Clu_nInitCpt_ScpPrssMes_C,
                                Clu_nDecCpt_ScpPrssMes_C,
                                &CLUPEDFREQACQ_u8CntFilt_2,
                                &CLUPEDFREQACQ_bFilSig_2,
                                &Ext_ctDftSftyScp_rCluPedPrssMes,
                                &CLUPEDFREQACQ_bScprCluPedPrsMes);
   VEMS_vidSET(Ext_bDftSftyScp_rCluPedPrssMes, CLUPEDFREQACQ_bScprCluPedPrsMes);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CLUPEDFREQACQ_vidCluPedLnr                                 */
/* !Description :  Linéarisation et saturation de l'information pédale        */
/*                 d'embrayage proportionnelle                                */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Zoubeida.harran                                            */
/* !Trace_To    :  VEMS_E_12_01136_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Clu_rCluPedPrssLnrMes;                                       */
/*  input uint16 Ext_rCluPedPrssBrutMes;                                      */
/*  input uint16 Clu_Rco_Bkpt[2];                                             */
/*  input uint16 Clu_PosPed_Map[2];                                           */
/*  output uint16 Clu_rCluPedPrssLnrMesPrev;                                  */
/*  output uint16 Clu_rCluPedPrssLnrMes;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CLUPEDFREQACQ_vidCluPedLnr(void)
{
   uint16 u16LocalExt_rCluPedPrssBrutMes;
   uint16 u16LocalBKPTSup;
   uint16 u16LocalBKPTInf;
   uint16 u16LocalMapSup;
   uint16 u16LocalMapInf;
   uint16 u16LocalInterpolation;
   uint16 u16LocalSiteInterpolation;
   uint16 u16Local;
   sint32 s32LocalInterpolation;
   uint32 u32LocalDeltaValue;
   uint32 u32LocalInterpolation;
   uint32 u32LocalResultValue;


   Clu_rCluPedPrssLnrMesPrev = (uint16)MATHSRV_udtMIN(Clu_rCluPedPrssLnrMes,
                                                      1024);
   VEMS_vidGET(Ext_rCluPedPrssBrutMes, u16LocalExt_rCluPedPrssBrutMes);

   if (Clu_Rco_Bkpt[1] >= Clu_Rco_Bkpt[0])
   {
      u16LocalBKPTSup = Clu_Rco_Bkpt[1];
      u16LocalBKPTInf = Clu_Rco_Bkpt[0];
      u16LocalMapSup = Clu_PosPed_Map[1];
      u16LocalMapInf = Clu_PosPed_Map[0];
   }
   else
   {
      u16LocalBKPTSup = Clu_Rco_Bkpt[0];
      u16LocalBKPTInf = Clu_Rco_Bkpt[1];
      u16LocalMapSup = Clu_PosPed_Map[0];
      u16LocalMapInf = Clu_PosPed_Map[1];
   }
   if (Clu_Rco_Bkpt[1] != Clu_Rco_Bkpt[0])
   {
      if (u16LocalExt_rCluPedPrssBrutMes >= u16LocalBKPTSup)
      {
         Clu_rCluPedPrssLnrMes =
            (uint16)MATHSRV_udtMIN(u16LocalMapSup, 1024);
      }
      if (u16LocalExt_rCluPedPrssBrutMes < u16LocalBKPTInf)
      {
         Clu_rCluPedPrssLnrMes =
            (uint16)MATHSRV_udtMIN(u16LocalMapInf, 1024);
      }
      if (  (u16LocalExt_rCluPedPrssBrutMes < u16LocalBKPTSup)
         && (u16LocalExt_rCluPedPrssBrutMes >= u16LocalBKPTInf))
      {
         /* Calculate the "Para" value of u16LocalExt_rCluPedPrssBrutMes with
            Clu_PosPed_Map */

         u32LocalDeltaValue =
            (uint32)MATHSRV_udtABS( u16LocalExt_rCluPedPrssBrutMes
                                  - Clu_Rco_Bkpt[0]);
         u32LocalDeltaValue = u32LocalDeltaValue << 16;
         u16LocalInterpolation =(uint16)(u16LocalBKPTSup - u16LocalBKPTInf);
         u16LocalSiteInterpolation =
            (uint16)(u32LocalDeltaValue / u16LocalInterpolation);
         /* Calculate the interpolation value on Clu_PosPed_Map */

         s32LocalInterpolation = (sint32)Clu_PosPed_Map[1] -
                                 (sint32)Clu_PosPed_Map[0];
         u16Local = (uint16)MATHSRV_udtABS(s32LocalInterpolation);
         if (s32LocalInterpolation > 0)
         {
            u32LocalInterpolation = u16Local * u16LocalSiteInterpolation;
            s32LocalInterpolation = (sint32)(u32LocalInterpolation / 65536);
         }
         else
         {
            u32LocalInterpolation = u16Local * u16LocalSiteInterpolation;
            s32LocalInterpolation = (sint32)(u32LocalInterpolation / 65536);
            s32LocalInterpolation = ((-1) * s32LocalInterpolation);
         }

         u32LocalResultValue =
            (uint32)((sint32)Clu_PosPed_Map[0] + s32LocalInterpolation);
         Clu_rCluPedPrssLnrMes =
            (uint16)MATHSRV_udtMIN((uint16)u32LocalResultValue, (uint16)1024);
      }
   }
   else
   {
      Clu_rCluPedPrssLnrMes =
         (uint16)MATHSRV_udtMIN(Clu_PosPed_Map[0], 1024);
   }
}

/*------------------------------- end of file --------------------------------*/