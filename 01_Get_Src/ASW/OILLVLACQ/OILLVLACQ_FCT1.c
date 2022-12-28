/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : OILLVLACQ                                               */
/* !Description     : OILLVLACQ Component                                     */
/*                                                                            */
/* !Module          : OILLVLACQ                                               */
/* !Description     : OIL LEVEL ACQUISITION                                   */
/*                                                                            */
/* !File            : OILLVLACQ_FCT1.C                                        */
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
/*   1 / OILLVLACQ_vidInit                                                    */
/*   2 / OILLVLACQ_vidInitOutput                                              */
/*   3 / OILLVLACQ_vidAcquisition                                             */
/*   4 / OILLVLACQ_vidAcqBSW                                                  */
/*   5 / OILLVLACQ_vidAcqMng                                                  */
/*   6 / OILLVLACQ_vidDiagnosis                                               */
/*   7 / OILLVLACQ_vidFailures                                                */
/*   8 / OILLVLACQ_vidDiagGrd                                                 */
/*   9 / OILLVLACQ_vidTreatment                                               */
/*   10 / OILLVLACQ_vidSelection                                              */
/*                                                                            */
/* !Reference   : PTS_DOC_6872932 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/OILLVLACQ/OILLVLACQ_FCT1.C_v    $*/
/* $Revision::   1.6      $$Author::   mbenfrad       $$Date::   01 Sep 2014 $*/
/* $Author::   mbenfrad                               $$Date::   01 Sep 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "STD_LIMITS.h"
#include "MATHSRV.h"
#include "OILLVLACQ.h"
#include "OILLVLACQ_L.h"
#include "OILLVLACQ_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILLVLACQ_vidInit                                          */
/* !Description :  The engine oil level is initialized with                   */
/*                 Ext_uEngOilLvlIp_C.                                        */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_uEngOilLvlIp_C;                                          */
/*  output uint16 Ext_uEngOilLvl;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILLVLACQ_vidInit(void)
{
   uint16 u16LocalExt_uEngOilLvl;


   u16LocalExt_uEngOilLvl = (uint16)MATHSRV_udtMIN(Ext_uEngOilLvlIp_C, 4096);
   VEMS_vidSET(Ext_uEngOilLvl, u16LocalExt_uEngOilLvl);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILLVLACQ_vidInitOutput                                    */
/* !Description :  fonction d'initialisation des sorties.                     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Ext_stMeasAuth;                                            */
/*  output uint16 Ext_tiMeasAuth;                                             */
/*  output boolean Ext_bOilLvlAcqDone;                                        */
/*  output st120 OILLVLACQ_stAcqMng;                                          */
/*  output boolean Oil_bOilLvlAcqOk;                                          */
/*  output uint16 Ext_uEngOilLvlAvg1;                                         */
/*  output uint16 Ext_uEngOilLvlAvg2;                                         */
/*  output uint16 Ext_uEngOilLvlRaw;                                          */
/*  output boolean Ext_bMonRunScp_OilLvlAcq;                                  */
/*  output boolean Ext_bDgoScp_OilLvlAcq;                                     */
/*  output boolean Ext_bMonRunScg_OilLvlAcq;                                  */
/*  output boolean Ext_bDgoScg_OilLvlAcq;                                     */
/*  output boolean Ext_bMonRunGrd_OilLvlAcq;                                  */
/*  output boolean Ext_bDgoGrd_OilLvlAcq;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILLVLACQ_vidInitOutput(void)
{
   VEMS_vidSET(Ext_stMeasAuth, INACTIF);
   Ext_tiMeasAuth = 0;
   Ext_bOilLvlAcqDone = 0;
   OILLVLACQ_stAcqMng = INIT_ACQUI;
   Oil_bOilLvlAcqOk = 0;
   Ext_uEngOilLvlAvg1 = 0;
   Ext_uEngOilLvlAvg2 = 0;
   Ext_uEngOilLvlRaw = 0;
   Ext_bMonRunScp_OilLvlAcq = 0;
   Ext_bDgoScp_OilLvlAcq = 0;
   Ext_bMonRunScg_OilLvlAcq = 0;
   Ext_bDgoScg_OilLvlAcq = 0;
   Ext_bMonRunGrd_OilLvlAcq = 0;
   Ext_bDgoGrd_OilLvlAcq = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILLVLACQ_vidAcquisition                                   */
/* !Description :  The beginning of the measure is based on vehicle request   */
/*                 and conditions on engine speed and water temperature. Once */
/*                 the acquisition is completely done, it will not be         */
/*                 restarted until the next Key Off.                          */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_02972_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OILLVLACQ_vidAcqMng();                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILLVLACQ_vidAcquisition(void)
{
   OILLVLACQ_vidAcqMng();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILLVLACQ_vidAcqBSW                                        */
/* !Description :  The two voltage average are produced by the BSW            */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 FisrtAcqui_uEngOilLvl;                                       */
/*  input uint16 SecondAcqui_uEngOilLvl;                                      */
/*  input uint8 AcquiState_stEngOilLvl;                                       */
/*  output uint16 Ext_uEngOilLvlAvg1;                                         */
/*  output uint16 Ext_uEngOilLvlAvg2;                                         */
/*  output uint16 Ext_uEngOilLvlRaw;                                          */
/*  output boolean Oil_bOilLvlAcqOk;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILLVLACQ_vidAcqBSW(void)
{
   uint8  u8LocalAcquiState;
   uint16 u16LocalFisrtAcqui;
   uint16 u16LocalSecondAcqui;
   sint32 s32LocalDiff;


   VEMS_vidGET(FisrtAcqui_uEngOilLvl, u16LocalFisrtAcqui);
   VEMS_vidGET(SecondAcqui_uEngOilLvl, u16LocalSecondAcqui);
   VEMS_vidGET(AcquiState_stEngOilLvl, u8LocalAcquiState);

   Ext_uEngOilLvlAvg1 = (uint16)MATHSRV_udtMIN(u16LocalFisrtAcqui, 4096);
   Ext_uEngOilLvlAvg2 = (uint16)MATHSRV_udtMIN(u16LocalSecondAcqui, 4096);
   s32LocalDiff = (sint32)(u16LocalSecondAcqui - u16LocalFisrtAcqui);
   Ext_uEngOilLvlRaw = (uint16)MATHSRV_udtCLAMP(s32LocalDiff, 0, 4096);

   if (u8LocalAcquiState != E_OK)
   {
      Oil_bOilLvlAcqOk = 0;
   }
   else
   {
      Oil_bOilLvlAcqOk = 1;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILLVLACQ_vidAcqMng                                        */
/* !Description :  Automate                                                   */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean UCE_bPwrlAcv;                                               */
/*  input uint16 Ext_nEng;                                                    */
/*  input st120 OILLVLACQ_stAcqMng;                                           */
/*  input boolean CoReqVeh_bOilMesReq;                                        */
/*  input boolean CoReqVeh_bOilWkuReq;                                        */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input sint16 Ext_tMaxThres_C;                                             */
/*  input uint16 Ext_tiMeasAuth;                                              */
/*  input uint16 Ext_tiMeasAuthEndMes_C;                                      */
/*  input boolean Oil_bOilLvlAcqOk;                                           */
/*  output st120 OILLVLACQ_stAcqMng;                                          */
/*  output boolean Ext_stMeasAuth;                                            */
/*  output boolean Ext_bOilLvlAcqDone;                                        */
/*  output uint16 Ext_tiMeasAuth;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILLVLACQ_vidAcqMng(void)
{
   boolean bLocalCoReqVeh_bOilMesReq;
   boolean bLocalCoReqVeh_bOilWkuReq;
   boolean bLocalUCE_bPwrlAcv;
   uint16  u16LocalExt_nEng;
   sint16  s16LocalExt_tCoMes;


   VEMS_vidGET(UCE_bPwrlAcv, bLocalUCE_bPwrlAcv);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   switch (OILLVLACQ_stAcqMng)
   {
      case INIT_ACQUI:
         VEMS_vidGET(CoReqVeh_bOilMesReq, bLocalCoReqVeh_bOilMesReq);
         VEMS_vidGET(CoReqVeh_bOilWkuReq, bLocalCoReqVeh_bOilWkuReq);
         VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);

         if (  (  (bLocalCoReqVeh_bOilMesReq != 0)
               || (bLocalCoReqVeh_bOilWkuReq != 0))
            && (u16LocalExt_nEng == 0)
            && (s16LocalExt_tCoMes < Ext_tMaxThres_C)
            && (bLocalUCE_bPwrlAcv == 0))
         {
            OILLVLACQ_stAcqMng = ACQUI_RUNNING;
            VEMS_vidSET(Ext_stMeasAuth, ACTIF);
         }
         break;

      case ACQUI_RUNNING:
         if (Ext_tiMeasAuth >= Ext_tiMeasAuthEndMes_C)
         {
            if (Oil_bOilLvlAcqOk != 0)
            {
               OILLVLACQ_stAcqMng = ACQUI_DONE;
               VEMS_vidSET(Ext_stMeasAuth, INACTIF);
               Ext_bOilLvlAcqDone = 1;
            }
            else
            {
               OILLVLACQ_stAcqMng = ACQUI_STOPPED;
               VEMS_vidSET(Ext_stMeasAuth, INACTIF);
            }
         }
         else
         {
            if (u16LocalExt_nEng != 0)
            {
               OILLVLACQ_stAcqMng = ACQUI_STOPPED;
               VEMS_vidSET(Ext_stMeasAuth, INACTIF);
            }
            else
            {
               if (Ext_tiMeasAuth < 5000)
               {
                  Ext_tiMeasAuth = (uint16)( Ext_tiMeasAuth
                                           + Oil_SampleTiFast_SC);
               }
               else
               {
                  Ext_tiMeasAuth = 5000;
               }
            }
         }
         break;

      case ACQUI_DONE:
         if (bLocalUCE_bPwrlAcv != 0)
         {
            OILLVLACQ_stAcqMng = INIT_ACQUI;
            VEMS_vidSET(Ext_stMeasAuth, INACTIF);
            Ext_tiMeasAuth = 0;
            Ext_bOilLvlAcqDone = 0;
         }
         break;

      case ACQUI_STOPPED:
         if (bLocalUCE_bPwrlAcv != 0)
         {
            OILLVLACQ_stAcqMng = INIT_ACQUI;
            VEMS_vidSET(Ext_stMeasAuth, INACTIF);
            Ext_tiMeasAuth = 0;
            Ext_bOilLvlAcqDone = 0;
         }
         break;

      default:
         OILLVLACQ_stAcqMng = INIT_ACQUI;
         VEMS_vidSET(Ext_stMeasAuth, INACTIF);
         Ext_tiMeasAuth = 0;
         Ext_bOilLvlAcqDone = 0;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILLVLACQ_vidDiagnosis                                     */
/* !Description :  Diagnosis are run only when an acquisition has been carried*/
/*                 out.                                                       */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_02972_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void OILLVLACQ_vidFailures();                                 */
/*  extf argret void OILLVLACQ_vidDiagGrd();                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILLVLACQ_vidDiagnosis(void)
{
   OILLVLACQ_vidFailures();
   OILLVLACQ_vidDiagGrd();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILLVLACQ_vidFailures                                      */
/* !Description :  Three diagnosis are carried out : short-circuit to ground, */
/*                 short-circuit to “plus”, and voltage difference incoherent */
/*                 (too small or too big).                                    */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input boolean Dft_oc_OilLvlAcq;                                           */
/*  input boolean Dft_scp_OilLvlAcq;                                          */
/*  input boolean Dena_oc_OilLvlAcq;                                          */
/*  input boolean Dena_scp_OilLvlAcq;                                         */
/*  input boolean Dena_scg_OilLvlAcq;                                         */
/*  input boolean Dft_scg_OilLvlAcq;                                          */
/*  output boolean Ext_bDgoScp_OilLvlAcq;                                     */
/*  output boolean Ext_bMonRunScp_OilLvlAcq;                                  */
/*  output boolean Ext_bMonRunScg_OilLvlAcq;                                  */
/*  output boolean Ext_bDgoScg_OilLvlAcq;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILLVLACQ_vidFailures(void)
{
   boolean bLocalDft_oc_OilLvlAcq;
   boolean bLocalDft_scp_OilLvlAcq;
   boolean bLocalDena_oc_OilLvlAcq;
   boolean bLocalDena_scp_OilLvlAcq;
   boolean bLocalDena_scg_OilLvlAcq;
   boolean bLocalDft_scg_OilLvlAcq;
   boolean bLocalInhDiag_OilLvlAcq;


   VEMS_vidGET(Dft_oc_OilLvlAcq, bLocalDft_oc_OilLvlAcq);
   VEMS_vidGET(Dft_scp_OilLvlAcq, bLocalDft_scp_OilLvlAcq);
   VEMS_vidGET(Dena_oc_OilLvlAcq, bLocalDena_oc_OilLvlAcq);
   VEMS_vidGET(Dena_scp_OilLvlAcq, bLocalDena_scp_OilLvlAcq);
   VEMS_vidGET(Dena_scg_OilLvlAcq, bLocalDena_scg_OilLvlAcq);
   VEMS_vidGET(Dft_scg_OilLvlAcq, bLocalDft_scg_OilLvlAcq);
   bLocalInhDiag_OilLvlAcq = GDGAR_bGetFRM(FRM_FRM_INHDIAG_OILLVLACQ);

   if (  (bLocalDft_oc_OilLvlAcq != 0)
      || (bLocalDft_scp_OilLvlAcq != 0))
   {
      Ext_bDgoScp_OilLvlAcq = 1;
   }
   else
   {
      Ext_bDgoScp_OilLvlAcq = 0;
   }

   if (bLocalInhDiag_OilLvlAcq != 0)
   {
      Ext_bMonRunScp_OilLvlAcq = 0;
      Ext_bMonRunScg_OilLvlAcq = 0;
   }
   else
   {
      if (  (bLocalDena_oc_OilLvlAcq != 0)
         || (bLocalDena_scp_OilLvlAcq != 0))
      {
         Ext_bMonRunScp_OilLvlAcq = 1;
      }
      else
      {
         Ext_bMonRunScp_OilLvlAcq = 0;
      }
      if (bLocalDena_scg_OilLvlAcq != 0)
      {
         Ext_bMonRunScg_OilLvlAcq = 1;
      }
      else
      {
         Ext_bMonRunScg_OilLvlAcq = 0;
      }
   }
   if (bLocalDft_scg_OilLvlAcq != 0)
   {
      Ext_bDgoScg_OilLvlAcq = 1;
   }
   else
   {
      Ext_bDgoScg_OilLvlAcq = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILLVLACQ_vidDiagGrd                                       */
/* !Description :  Diagnostic based on voltage difference incoherent (Too smal*/
/*                 or too big)                                                */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  input boolean Ext_bOilLvlAcqDone;                                         */
/*  input uint16 Ext_uEngOilLvlAGrdMin_C;                                     */
/*  input uint16 Ext_uEngOilLvlRaw;                                           */
/*  input uint16 Ext_uEngOilLvlAGrdMax_C;                                     */
/*  output boolean Ext_bMonRunGrd_OilLvlAcq;                                  */
/*  output boolean Ext_bDgoGrd_OilLvlAcq;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILLVLACQ_vidDiagGrd(void)
{
   boolean bLocalINHDIAGGRD_OILLVLACQ;


   bLocalINHDIAGGRD_OILLVLACQ = GDGAR_bGetFRM(FRM_FRM_INHDIAGGRD_OILLVLACQ);

   if (Ext_bOilLvlAcqDone == 0)
   {
      Ext_bMonRunGrd_OilLvlAcq = 0;
      Ext_bDgoGrd_OilLvlAcq = 0;
   }
   else
   {
      if (bLocalINHDIAGGRD_OILLVLACQ == 0)
      {
         Ext_bMonRunGrd_OilLvlAcq = 1;
      }
      else
      {
         Ext_bMonRunGrd_OilLvlAcq = 0;
      }
      if (  (Ext_uEngOilLvlAGrdMin_C > Ext_uEngOilLvlRaw)
         || (Ext_uEngOilLvlRaw > Ext_uEngOilLvlAGrdMax_C))
      {
         Ext_bDgoGrd_OilLvlAcq = 1;
      }
      else
      {
         Ext_bDgoGrd_OilLvlAcq = 0;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILLVLACQ_vidTreatment                                     */
/* !Description :  Several corrections are done on the raw acquisition. There */
/*                 are corrections depending on oil temperature, current, ECU */
/*                 temperature. A change of scale is also performed in order  */
/*                 to respect the BSI range.                                  */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_02972_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Oil_uOilLvl_A[3];                                            */
/*  input uint16 Ext_uEngOilLvlRaw;                                           */
/*  input sint16 Ext_tOil;                                                    */
/*  input uint8 Oil_tOil_A[10];                                               */
/*  input uint16 Oil_uEngOilLvlTOilCor_M[3][10];                              */
/*  input uint16 Ext_iCurMes;                                                 */
/*  input uint16 Ext_iCurNom_C;                                               */
/*  input uint16 Oil_uEngOillLvlTOilCor;                                      */
/*  input uint8 SenAct_tECUAcq;                                               */
/*  input uint8 Oil_tECU_A[10];                                               */
/*  input uint8 Oil_facCorTECU_T[10];                                         */
/*  input uint16 Oil_uEngOilLvlICor;                                          */
/*  input uint16 Ext_uBSIMin_C;                                               */
/*  input uint16 Ext_uBSIMax_C;                                               */
/*  input uint16 Ext_uCMMMin_C;                                               */
/*  input uint16 Ext_uCMMMax_C;                                               */
/*  input uint16 Oil_uEngOilLvlTECUCor;                                       */
/*  output uint16 Oil_uEngOillLvlTOilCor;                                     */
/*  output uint16 Oil_uEngOilLvlICor;                                         */
/*  output uint16 Oil_uEngOilLvlTECUCor;                                      */
/*  output uint16 Oil_uEngOilLvl;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILLVLACQ_vidTreatment(void)
{
   uint8  u8Localresult1;
   uint8  u8LocalExt_tOil;
   uint8  u8LocalSenAct_tECUAcq;
   uint16 u16LocalExt_iCurMes;
   uint16 u16LocalParaX;
   uint16 u16LocalParaY;
   uint16 u16LocalPara;
   uint16 u16Localinterpo;
   uint32 u32Localresult2;
   uint32 u32LocalABS1;
   uint32 u32LocalABS2;
   uint32 u32LocalMUL1;
   uint32 u32LocalMUL2;
   uint32 u32Localresult3;
   uint32 u32Localresult4;
   uint32 u32LocalAff;
   uint32 u32Localresult1;
   uint32 u32LocalDIV;
   uint32 u32LocalPROD;
   sint16 s16LocalExt_tOil;
   uint32 u32LocalDiv1;
   uint32 u32LocalDiv2;
   sint32 s32LocalDiff1;
   sint32 s32LocalDiff2;
   sint32 s32LocalFinalResult;


   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(Oil_uOilLvl_A,
                                                Ext_uEngOilLvlRaw,
                                                3);
   VEMS_vidGET(Ext_tOil, s16LocalExt_tOil);
   s16LocalExt_tOil = (sint16)((s16LocalExt_tOil + 200) / 4);
   u8LocalExt_tOil = (uint8)MATHSRV_udtCLAMP(s16LocalExt_tOil, 0, 255);

   u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(Oil_tOil_A,
                                               u8LocalExt_tOil,
                                               10);
   u16Localinterpo =
      MATHSRV_u16Interp2d(&Oil_uEngOilLvlTOilCor_M[0][0],
                          u16LocalParaX,
                          u16LocalParaY,
                          10);

   Oil_uEngOillLvlTOilCor = (uint16)MATHSRV_udtMIN(u16Localinterpo, 4096);

   VEMS_vidGET(Ext_iCurMes, u16LocalExt_iCurMes);

   if (u16LocalExt_iCurMes != 0)
   {
      if (  (Ext_iCurNom_C != 0)
         && (Oil_uEngOillLvlTOilCor != 0))
      {
         u32LocalDiv1 = (UINT32_MAX / (uint32)Ext_iCurNom_C);
         u32LocalDiv2 = (UINT32_MAX / (uint32)Oil_uEngOillLvlTOilCor);
         u32LocalAff = (uint32)(Ext_iCurNom_C * Ext_iCurNom_C);

         if (u32LocalAff < u32LocalDiv1)
         {
            u32LocalAff = (u32LocalAff * Ext_iCurNom_C);
            if (u32LocalAff < u32LocalDiv2)
            {
               u32LocalAff = (u32LocalAff * Oil_uEngOillLvlTOilCor);

               u32LocalDIV = (UINT32_MAX / (uint32)(u16LocalExt_iCurMes));
               u32LocalPROD = (uint32)( u16LocalExt_iCurMes
                                      * u16LocalExt_iCurMes);
               if (u32LocalPROD < u32LocalDIV)
               {
                  u32LocalAff = ( u32LocalAff
                                / (uint32)( u16LocalExt_iCurMes
                                          * u16LocalExt_iCurMes
                                          * u16LocalExt_iCurMes));
               }
               else
               {
                  u32LocalAff = ( u32LocalAff
                                / (uint32)( u16LocalExt_iCurMes
                                          * u16LocalExt_iCurMes));
                  u32LocalAff = (u32LocalAff / u16LocalExt_iCurMes);
               }
            }
            else
            {
               u32LocalAff = (u32LocalAff / u16LocalExt_iCurMes);
               if (u32LocalAff < u32LocalDiv2)
               {
                  u32LocalAff = (u32LocalAff * Oil_uEngOillLvlTOilCor);
                  u32LocalAff = ( u32LocalAff
                                / (uint32)( u16LocalExt_iCurMes
                                          * u16LocalExt_iCurMes));
               }
               else
               {
                  u32LocalAff = (u32LocalAff / u16LocalExt_iCurMes);
                  if (u32LocalAff < u32LocalDiv2)
                  {
                     u32LocalAff = (u32LocalAff * Oil_uEngOillLvlTOilCor);
                     u32LocalAff = (u32LocalAff / u16LocalExt_iCurMes);
                  }
                  else
                  {
                     u32LocalAff = (u32LocalAff / u16LocalExt_iCurMes);
                     if (u32LocalAff < u32LocalDiv2)
                     {
                        u32LocalAff = (u32LocalAff * Oil_uEngOillLvlTOilCor);
                     }
                     else
                     {
                        u32LocalAff = UINT32_MAX;
                     }
                  }
               }
            }
         }
         else
         {
            u32LocalAff = (u32LocalAff / u16LocalExt_iCurMes);
            if (u32LocalAff < u32LocalDiv1)
            {
               u32LocalAff = (u32LocalAff * Ext_iCurNom_C);
               if (u32LocalAff < u32LocalDiv2)
               {
                  u32LocalAff = (u32LocalAff * Oil_uEngOillLvlTOilCor);
                  u32LocalAff = ( u32LocalAff
                                / (uint32)( u16LocalExt_iCurMes
                                          * u16LocalExt_iCurMes));
               }
               else
               {
                  u32LocalAff = (u32LocalAff / u16LocalExt_iCurMes);
                  if (u32LocalAff < u32LocalDiv2)
                  {
                     u32LocalAff = (u32LocalAff * Oil_uEngOillLvlTOilCor);
                     u32LocalAff = (u32LocalAff / u16LocalExt_iCurMes);
                  }
                  else
                  {
                     u32LocalAff = (u32LocalAff / u16LocalExt_iCurMes);
                     if (u32LocalAff < u32LocalDiv2)
                     {
                        u32LocalAff = (u32LocalAff * Oil_uEngOillLvlTOilCor);
                     }
                     else
                     {
                        u32LocalAff = UINT32_MAX;
                     }
                  }
               }
            }
            else
            {
               u32LocalAff = (u32LocalAff / u16LocalExt_iCurMes);
               if (u32LocalAff < u32LocalDiv1)
               {
                  u32LocalAff = (u32LocalAff * Ext_iCurNom_C);
                  if (u32LocalAff < u32LocalDiv2)
                  {
                     u32LocalAff = (u32LocalAff * Oil_uEngOillLvlTOilCor);
                     u32LocalAff = (u32LocalAff / u16LocalExt_iCurMes);
                  }
                  else
                  {
                     u32LocalAff = (u32LocalAff / u16LocalExt_iCurMes);
                     if (u32LocalAff < u32LocalDiv2)
                     {
                        u32LocalAff = (u32LocalAff * Oil_uEngOillLvlTOilCor);
                     }
                     else
                     {
                        u32LocalAff = UINT32_MAX;
                     }
                  }
               }
               else
               {
                  u32LocalAff = (u32LocalAff / u16LocalExt_iCurMes);
                  if (u32LocalAff < u32LocalDiv1)
                  {
                     u32LocalAff = (u32LocalAff * Ext_iCurNom_C);
                     if (u32LocalAff < u32LocalDiv2)
                     {
                        u32LocalAff = (u32LocalAff * Oil_uEngOillLvlTOilCor);
                     }
                     else
                     {
                        u32LocalAff = UINT32_MAX;
                     }
                  }
                  else
                  {
                     u32LocalAff = UINT32_MAX;
                  }
               }
            }
         }
         Oil_uEngOilLvlICor = (uint16)MATHSRV_udtMIN(u32LocalAff, 4096);
      }
      else
      {
         Oil_uEngOilLvlICor = 0;
      }
   }
   else
   {
      Oil_uEngOilLvlICor = Oil_uEngOillLvlTOilCor;
   }

   /*interp1D*/

   VEMS_vidGET(SenAct_tECUAcq, u8LocalSenAct_tECUAcq);
   u8LocalSenAct_tECUAcq = (uint8)((uint16)(u8LocalSenAct_tECUAcq * 5) / 8);
   u16LocalPara =
      MATHSRV_u16CalcParaIncAryU8(Oil_tECU_A, u8LocalSenAct_tECUAcq, 10);
   u8Localresult1 =
      MATHSRV_u8Interp1d(Oil_facCorTECU_T, u16LocalPara);

   u32Localresult2 = (uint32)(u8Localresult1 * Oil_uEngOilLvlICor);
   u32Localresult1 = (u32Localresult2 / 100);
   Oil_uEngOilLvlTECUCor = (uint16)MATHSRV_udtMIN(u32Localresult1, 4096);

   s32LocalDiff1 = (sint32)(Ext_uBSIMin_C - Ext_uBSIMax_C);
   s32LocalDiff2 = (sint32)(Ext_uCMMMin_C - Ext_uCMMMax_C);

   u32LocalABS1 = (uint32)MATHSRV_udtABS(s32LocalDiff1);
   u32LocalABS2 = (uint32)MATHSRV_udtABS(s32LocalDiff2);

   u32LocalMUL1 = u32LocalABS1 * Oil_uEngOilLvlTECUCor;
   u32LocalMUL2 = u32LocalABS1 * Ext_uCMMMax_C;
   if (u32LocalABS2 != 0)
   {
      u32Localresult3 = u32LocalMUL1 / u32LocalABS2;
      u32Localresult4 = u32LocalMUL2 / u32LocalABS2;


      if (  (  (Ext_uBSIMin_C > Ext_uBSIMax_C)
            && (Ext_uCMMMin_C > Ext_uCMMMax_C))
         || (  (Ext_uBSIMin_C < Ext_uBSIMax_C)
            && (Ext_uCMMMin_C < Ext_uCMMMax_C)))
      {
         s32LocalFinalResult = (sint32)( ( Ext_uBSIMax_C
                                         + u32Localresult3)
                                       - u32Localresult4);
         Oil_uEngOilLvl = (uint16)MATHSRV_udtCLAMP(s32LocalFinalResult,
                                                   0,
                                                   4096);
         /*QAC Warning : Msg(3:3356), the clamp is well covered by tests*/
      }

      if (  (  (Ext_uBSIMin_C > Ext_uBSIMax_C)
             && (Ext_uCMMMin_C < Ext_uCMMMax_C))
         || (  (Ext_uBSIMin_C < Ext_uBSIMax_C)
             && (Ext_uCMMMin_C > Ext_uCMMMax_C)))
      {
         s32LocalFinalResult = (sint32)( ( Ext_uBSIMax_C
                                         - u32Localresult3)
                                       + u32Localresult4);
         Oil_uEngOilLvl = (uint16)MATHSRV_udtCLAMP(s32LocalFinalResult,
                                                   0,
                                                   4096);
         /*QAC Warning : Msg(3:3356), the clamp is well covered by tests*/
      }
   }
   else
   {
      Oil_uEngOilLvl = (uint16)MATHSRV_udtMIN(Ext_uBSIMax_C, 4096);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILLVLACQ_vidSelection                                     */
/* !Description :  This block manages the priorities between the computed     */
/*                 value, the default value, and the “measure running” value. */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_02972_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_uEngOilLvlDft_C;                                         */
/*  input boolean Ext_bDgoScg_OilLvlAcq;                                      */
/*  input boolean Ext_bDgoScp_OilLvlAcq;                                      */
/*  input boolean Ext_bDgoGrd_OilLvlAcq;                                      */
/*  input uint16 Ext_uEngOilLvl;                                              */
/*  input boolean Ext_bOilLvlAcqDone;                                         */
/*  input uint16 Oil_uEngOilLvl;                                              */
/*  input uint16 Ext_uEngOilLvlIp_C;                                          */
/*  output uint16 Ext_uEngOilLvl;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILLVLACQ_vidSelection(void)
{
   boolean bLocalAcvDftMod_OilLvlAcq;
   uint16  u16LocalExt_uEngOilLvl;


   bLocalAcvDftMod_OilLvlAcq = GDGAR_bGetFRM(FRM_FRM_ACVDFTMOD_OILLVLACQ);

   if (bLocalAcvDftMod_OilLvlAcq != 0)
   {
      u16LocalExt_uEngOilLvl = Ext_uEngOilLvlDft_C;
   }
   else
   {
      if (  (Ext_bDgoScg_OilLvlAcq != 0)
         || (Ext_bDgoScp_OilLvlAcq != 0)
         || (Ext_bDgoGrd_OilLvlAcq != 0))
      {
         VEMS_vidGET(Ext_uEngOilLvl, u16LocalExt_uEngOilLvl);
      }
      else
      {
         if (Ext_bOilLvlAcqDone != 0)
         {
            u16LocalExt_uEngOilLvl = Oil_uEngOilLvl;
         }
         else
         {
            u16LocalExt_uEngOilLvl = Ext_uEngOilLvlIp_C;
         }
      }
   }
   u16LocalExt_uEngOilLvl =
      (uint16)MATHSRV_udtMIN(u16LocalExt_uEngOilLvl, 4096);
   VEMS_vidSET(Ext_uEngOilLvl, u16LocalExt_uEngOilLvl);
}
/*-------------------------------- end of file -------------------------------*/