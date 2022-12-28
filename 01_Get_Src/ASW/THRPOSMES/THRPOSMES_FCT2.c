/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRPOSMES                                               */
/* !Description     : THRPOSMES component.                                    */
/*                                                                            */
/* !Module          : THRPOSMES                                               */
/* !Description     : Mesure de la position Papillon.                         */
/*                                                                            */
/* !File            : THRPOSMES_FCT2.c                                        */
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
/*   1 / THRPOSMES_vidCohPosnSnsrSafetyL2                                     */
/*   2 / THRPOSMES_vidSafetyLevel2                                            */
/*   3 / THRPOSMES_vidFilterU32                                               */
/*   4 / THRPOSMES_vidDbleDefaillanceThr                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_6658623 / 01                                        */
/* !OtherRefs   : VEMS V02 ECU#068658                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/THR/THRPOSMES/THRPOSMES_FCT2.C_v  $*/
/* $Revision::   1.3      $$Author::   wbouach        $$Date::   02 Jun 2014 $*/
/* $Author::   wbouach                                $$Date::   02 Jun 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "THRPOSMES.h"
#include "THRPOSMES_L.h"
#include "LIBSFTYLVL2.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSMES_vidCohPosnSnsrSafetyL2                           */
/* !Description :  Le but de cette stratégie est de sécuriser la cohérence des*/
/*                 entrées de mesure de la position papillon (capteur 1 et    */
/*                 capteur 2) via une stratégie de niveau 2 afin de se        */
/*                 prémunir contre les fautes latentes.                       */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Thr_bDgoCohPosnSnsr;                                        */
/*  input uint8 Thr_nUpTranThd_CohPosnSnsr_C;                                 */
/*  input uint8 Thr_nDownTranThd_CohPosnSnsr_C;                               */
/*  input uint8 Thr_nInitCptConf_CohPosnSnsr_C;                               */
/*  input uint8 Thr_nDecCpt_CohPosnSnsr_C;                                    */
/*  input uint8 THRPOSMES_u8CntFilt_1;                                        */
/*  input boolean THRPOSMES_bFilSig_1;                                        */
/*  input uint8 THRPOSMES_u8CountNiv2_1;                                      */
/*  input boolean THRPOSMES_bDftSftyCohPosnSnsr;                              */
/*  output boolean Thr_bDftSftyCohPosnSnsr;                                   */
/*  output boolean THRPOSMES_bDftSftyCohPosnSnsr;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSMES_vidCohPosnSnsrSafetyL2(void)
{
   /* CohPosnSnsr_Safety_Level2 */
   LIBSFTYLVL2_U8_Safety_Level2(Thr_bDgoCohPosnSnsr,
                                Thr_nUpTranThd_CohPosnSnsr_C,
                                Thr_nDownTranThd_CohPosnSnsr_C,
                                Thr_nInitCptConf_CohPosnSnsr_C,
                                Thr_nDecCpt_CohPosnSnsr_C,
                                &THRPOSMES_u8CntFilt_1,
                                &THRPOSMES_bFilSig_1,
                                &THRPOSMES_u8CountNiv2_1,
                                &THRPOSMES_bDftSftyCohPosnSnsr);
   VEMS_vidSET(Thr_bDftSftyCohPosnSnsr, THRPOSMES_bDftSftyCohPosnSnsr);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSMES_vidSafetyLevel2                                  */
/* !Description :  Le but de cette stratégie est de sécuriser les entrées de  */
/*                 mesure de la position papillon (capteur 1 et capteur 2) via*/
/*                 une stratégie de niveau 2 afin de se prémunir contre les   */
/*                 fautes latentes.                                           */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Thr_bDgoScpPosnSnsr1;                                       */
/*  input uint8 Thr_nUpTranThd_ScpPosnSnsr1_C;                                */
/*  input uint8 Thr_nDownTranThd_ScpPosnSnsr1_C;                              */
/*  input uint8 Thr_nInitCptConf_ScpPosnSnsr1_C;                              */
/*  input uint8 Thr_nDecCpt_ScpPosnSnsr1_C;                                   */
/*  input uint8 THRPOSMES_u8CntFilt_2;                                        */
/*  input boolean THRPOSMES_bFilSig_2;                                        */
/*  input uint8 THRPOSMES_u8CountNiv2_2;                                      */
/*  input boolean THRPOSMES_bDftSftyScpPosnSnsr1;                             */
/*  input boolean Thr_bDgoScpPosnSnsr2;                                       */
/*  input uint8 Thr_nUpTranThd_ScpPosnSnsr2_C;                                */
/*  input uint8 Thr_nDownTranThd_ScpPosnSnsr2_C;                              */
/*  input uint8 Thr_nInitCptConf_ScpPosnSnsr2_C;                              */
/*  input uint8 Thr_nDecCpt_ScpPosnSnsr2_C;                                   */
/*  input uint8 THRPOSMES_u8CntFilt_3;                                        */
/*  input boolean THRPOSMES_bFilSig_3;                                        */
/*  input uint8 THRPOSMES_u8CountNiv2_3;                                      */
/*  input boolean THRPOSMES_bDftSftyScpPosnSnsr2;                             */
/*  input boolean Thr_bDgoScgPosnSnsr1;                                       */
/*  input uint8 Thr_nUpTranThd_ScgPosnSnsr1_C;                                */
/*  input uint8 Thr_nDownTranThd_ScgPosnSnsr1_C;                              */
/*  input uint8 Thr_nInitCptConf_ScgPosnSnsr1_C;                              */
/*  input uint8 Thr_nDecCpt_ScgPosnSnsr1_C;                                   */
/*  input uint8 THRPOSMES_u8CntFilt_4;                                        */
/*  input boolean THRPOSMES_bFilSig_4;                                        */
/*  input uint8 THRPOSMES_u8CountNiv2_4;                                      */
/*  input boolean THRPOSMES_bDftSftyScgPosnSnsr1;                             */
/*  input boolean Thr_bDgoScgPosnSnsr2;                                       */
/*  input uint8 Thr_nUpTranThd_ScgPosnSnsr2_C;                                */
/*  input uint8 Thr_nDownTranThd_ScgPosnSnsr2_C;                              */
/*  input uint8 Thr_nInitCptConf_ScgPosnSnsr2_C;                              */
/*  input uint8 Thr_nDecCpt_ScgPosnSnsr2_C;                                   */
/*  input uint8 THRPOSMES_u8CntFilt_5;                                        */
/*  input boolean THRPOSMES_bFilSig_5;                                        */
/*  input uint8 THRPOSMES_u8CountNiv2_5;                                      */
/*  input boolean THRPOSMES_bDftSftyScgPosnSnsr2;                             */
/*  output boolean Thr_bDftSftyScpPosnSnsr1;                                  */
/*  output boolean THRPOSMES_bDftSftyScpPosnSnsr1;                            */
/*  output boolean Thr_bDftSftyScpPosnSnsr2;                                  */
/*  output boolean THRPOSMES_bDftSftyScpPosnSnsr2;                            */
/*  output boolean Thr_bDftSftyScgPosnSnsr1;                                  */
/*  output boolean THRPOSMES_bDftSftyScgPosnSnsr1;                            */
/*  output boolean Thr_bDftSftyScgPosnSnsr2;                                  */
/*  output boolean THRPOSMES_bDftSftyScgPosnSnsr2;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSMES_vidSafetyLevel2(void)
{
   /*  2_Safety_Level2 */
   LIBSFTYLVL2_U8_Safety_Level2(Thr_bDgoScpPosnSnsr1,
                                Thr_nUpTranThd_ScpPosnSnsr1_C,
                                Thr_nDownTranThd_ScpPosnSnsr1_C,
                                Thr_nInitCptConf_ScpPosnSnsr1_C,
                                Thr_nDecCpt_ScpPosnSnsr1_C,
                                &THRPOSMES_u8CntFilt_2,
                                &THRPOSMES_bFilSig_2,
                                &THRPOSMES_u8CountNiv2_2,
                                &THRPOSMES_bDftSftyScpPosnSnsr1);
   VEMS_vidSET(Thr_bDftSftyScpPosnSnsr1, THRPOSMES_bDftSftyScpPosnSnsr1);

   LIBSFTYLVL2_U8_Safety_Level2(Thr_bDgoScpPosnSnsr2,
                                Thr_nUpTranThd_ScpPosnSnsr2_C,
                                Thr_nDownTranThd_ScpPosnSnsr2_C,
                                Thr_nInitCptConf_ScpPosnSnsr2_C,
                                Thr_nDecCpt_ScpPosnSnsr2_C,
                                &THRPOSMES_u8CntFilt_3,
                                &THRPOSMES_bFilSig_3,
                                &THRPOSMES_u8CountNiv2_3,
                                &THRPOSMES_bDftSftyScpPosnSnsr2);
   VEMS_vidSET(Thr_bDftSftyScpPosnSnsr2, THRPOSMES_bDftSftyScpPosnSnsr2);

   LIBSFTYLVL2_U8_Safety_Level2(Thr_bDgoScgPosnSnsr1,
                                Thr_nUpTranThd_ScgPosnSnsr1_C,
                                Thr_nDownTranThd_ScgPosnSnsr1_C,
                                Thr_nInitCptConf_ScgPosnSnsr1_C,
                                Thr_nDecCpt_ScgPosnSnsr1_C,
                                &THRPOSMES_u8CntFilt_4,
                                &THRPOSMES_bFilSig_4,
                                &THRPOSMES_u8CountNiv2_4,
                                &THRPOSMES_bDftSftyScgPosnSnsr1);
   VEMS_vidSET(Thr_bDftSftyScgPosnSnsr1, THRPOSMES_bDftSftyScgPosnSnsr1);

   LIBSFTYLVL2_U8_Safety_Level2(Thr_bDgoScgPosnSnsr2,
                                Thr_nUpTranThd_ScgPosnSnsr2_C,
                                Thr_nDownTranThd_ScgPosnSnsr2_C,
                                Thr_nInitCptConf_ScgPosnSnsr2_C,
                                Thr_nDecCpt_ScgPosnSnsr2_C,
                                &THRPOSMES_u8CntFilt_5,
                                &THRPOSMES_bFilSig_5,
                                &THRPOSMES_u8CountNiv2_5,
                                &THRPOSMES_bDftSftyScgPosnSnsr2);
   VEMS_vidSET(Thr_bDftSftyScgPosnSnsr2, THRPOSMES_bDftSftyScgPosnSnsr2);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSMES_vidFilterU32                                     */
/* !Description :  First order filter executed on a uint32 value with an uint8*/
/*                 gain                                                       */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSMES_vidFilterU32
(
   uint8 u8FilterGain,
   uint32* pu32AccuracyFilterValue,
   uint32 u32MeasuredValue
)
{
   sint32 s32LocalAccuracyNewFilterValue;
   uint32 u32LocalPreviousFilterValue;


   u32LocalPreviousFilterValue = *pu32AccuracyFilterValue + 127;
   u32LocalPreviousFilterValue = u32LocalPreviousFilterValue / 256;

   s32LocalAccuracyNewFilterValue = (sint32)u32MeasuredValue
                                  - (sint32)u32LocalPreviousFilterValue;
   s32LocalAccuracyNewFilterValue = u8FilterGain
                                  * s32LocalAccuracyNewFilterValue;
   s32LocalAccuracyNewFilterValue = (sint32)(*pu32AccuracyFilterValue)
                                  + s32LocalAccuracyNewFilterValue;
   if (s32LocalAccuracyNewFilterValue > 0)
   {
      *pu32AccuracyFilterValue = (uint32)(s32LocalAccuracyNewFilterValue);
   }
   else
   {
      *pu32AccuracyFilterValue = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRPOSMES_vidDbleDefaillanceThr                            */
/* !Description :  Gestion du défaut relatif à la double défaillance THR      */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Zoubeida.harran                                            */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean Thr_bDgoScpPosnSnsr1;                                       */
/*  input boolean Thr_bDgoScgPosnSnsr1;                                       */
/*  input boolean Thr_bDgoScpPosnSnsr2;                                       */
/*  input boolean Thr_bDgoScgPosnSnsr2;                                       */
/*  output boolean Ext_bDgoDftSenr_Thr;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRPOSMES_vidDbleDefaillanceThr(void)
{
   if (  (  (Thr_bDgoScpPosnSnsr1 != 0)
         || (Thr_bDgoScgPosnSnsr1 != 0))
      && (  (Thr_bDgoScpPosnSnsr2 != 0)
         || (Thr_bDgoScgPosnSnsr2 != 0)))
   {
      Ext_bDgoDftSenr_Thr = 1;
   }
   else
   {
      Ext_bDgoDftSenr_Thr = 0;
   }
}

/*------------------------------- end of file --------------------------------*/