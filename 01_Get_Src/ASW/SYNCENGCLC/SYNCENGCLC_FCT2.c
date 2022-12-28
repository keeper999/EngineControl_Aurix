/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SYNCENGCLC                                              */
/* !Description     : SYNCENGCLC Component                                    */
/*                                                                            */
/* !Module          : SYNCENGCLC                                              */
/* !Description     : CALCUL DU REGIME RECENTRE.                              */
/*                                                                            */
/* !File            : SYNCENGCLC_FCT2.C                                       */
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
/*   1 / SYNCENGCLC_vidEngSpdInsideArea                                       */
/*   2 / SYNCENGCLC_vidAssigEngSpdArea                                        */
/*   3 / SYNCENGCLC_vidEngSpdMemrCylMot                                       */
/*   4 / SYNCENGCLC_vidProtectCalcSomme                                       */
/*   5 / SYNCENGCLC_vidEchtSumCyl_1_Areas                                     */
/*   6 / SYNCENGCLC_vidEchtSumCyl_2_Areas                                     */
/*   7 / SYNCENGCLC_vidEchtSumCyl_3_Areas                                     */
/*   8 / SYNCENGCLC_vidCalculMean                                             */
/*   9 / SYNCENGCLC_vidCalculCorrection                                       */
/*   10 / SYNCENGCLC_vidCorrectAssignment                                     */
/*                                                                            */
/* !Reference   : V02 NT 09 06456 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/SYNC/SYNCENGCLC/SYNCENGCLC_FCT2.$*/
/* $Revision::   1.0      $$Author::   HHAMLAOU       $$Date::   07 Aug 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   07 Aug 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "STD_LIMITS.h"
#include "MATHSRV.h"
#include "SYNCENGCLC.h"
#include "SYNCENGCLC_L.h"
#include "SYNCENGCLC_IM.h"
#include "VEMS.h"
#include "SWFAIL.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCENGCLC_vidEngSpdInsideArea                             */
/* !Description :  Ce sous système envoie un indicateur de présence du régime */
/*                 moteur dans la plage de régime correspondante. Par ailleurs*/
/*                 ce sous système est activé lorsque que le régime moteur se */
/*                 situe dans la plage calibrable Sync_ThdnEngClcMax_C et     */
/*                 Sync_ThdnEngClcMin_C.                                      */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  T.BENALI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Sync_nEngClc;                                                */
/*  input uint16 Sync_prm_nThdnEngClc;                                        */
/*  input uint8 SYNCENGCLC_u8NoArAcvnEngClc;                                  */
/*  output uint8 Sync_prm_bnEngInsdAr[20];                                    */
/*  output uint8 SYNCENGCLC_u8NoArAcvnEngClc;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGCLC_vidEngSpdInsideArea(void)
{
   uint8  u8LocalIndex;
   uint16 u16LocalSync_nEngClc;


   VEMS_vidGET(Sync_nEngClc, u16LocalSync_nEngClc);
   for (u8LocalIndex = 0; u8LocalIndex < NB_ACTIVE_ZONE; u8LocalIndex++)
   {
      if (  (u16LocalSync_nEngClc >= Sync_prm_nThdnEngClc[u8LocalIndex])
         && (u16LocalSync_nEngClc < Sync_prm_nThdnEngClc[u8LocalIndex + 1]))
      {
         Sync_prm_bnEngInsdAr[u8LocalIndex] = 1;
         SYNCENGCLC_u8NoArAcvnEngClc = u8LocalIndex;

      }
      else
      {
         Sync_prm_bnEngInsdAr[u8LocalIndex] = 0;
         SYNCENGCLC_u8NoArAcvnEngClc =
            (uint8)MATHSRV_udtMIN(SYNCENGCLC_u8NoArAcvnEngClc,
                                  (uint8)(NB_ACTIVE_ZONE - 1));
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCENGCLC_vidAssigEngSpdArea                              */
/* !Description :  Détermine, en fonction des indicateurs de présence, le     */
/*                 numéro de la plage active ainsi que le numéro du groupe de */
/*                 correction à saturer pour le régime recentré.              */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  T.BENALI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st95 SYNCENGCLC_StAssignEngArea;                                    */
/*  input boolean Sync_bnEngInsdAr;                                           */
/*  input uint8 SYNCENGCLC_u8NoArAcvnEngClc;                                  */
/*  output st95 SYNCENGCLC_StAssignEngArea;                                   */
/*  output uint8 Sync_no_ArAcvnEngClc;                                        */
/*  output uint8 Sync_no_BodyCorSatEngClc;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGCLC_vidAssigEngSpdArea(void)
{
   uint16 u16LocalVar;


   switch (SYNCENGCLC_StAssignEngArea)
   {
      case INIT_ENG_SPEED_IN_AREA:
         if (Sync_bnEngInsdAr != 0)
         {
            SYNCENGCLC_StAssignEngArea = ENG_SPEED_IN_AREA;
         }
         break;

      case ENG_SPEED_IN_AREA:
         if (Sync_bnEngInsdAr == 0)
         {
            SYNCENGCLC_StAssignEngArea = INIT_ENG_SPEED_IN_AREA;
            Sync_no_ArAcvnEngClc = 0;
            Sync_no_BodyCorSatEngClc = 0;
         }
         else
         {
            u16LocalVar = (uint16)(SYNCENGCLC_u8NoArAcvnEngClc + 1);
            Sync_no_ArAcvnEngClc = (uint8)MATHSRV_udtMIN(u16LocalVar, 20);

            u16LocalVar = (uint16)((SYNCENGCLC_u8NoArAcvnEngClc >> 2) + 1);
            Sync_no_BodyCorSatEngClc = (uint8)MATHSRV_udtMIN(u16LocalVar, 5);
         }
         break;

      default:
         SYNCENGCLC_StAssignEngArea = INIT_ENG_SPEED_IN_AREA;
         Sync_no_ArAcvnEngClc = 0;
         Sync_no_BodyCorSatEngClc = 0;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCENGCLC_vidEngSpdMemrCylMot                             */
/* !Description :  Le principe de ce bloc est de mémoriser le régime moteur   */
/*                 par cylindre correspondant à la phase de combustion, et    */
/*                 mise à jour à la fin de chaque cycle moteur.               */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  T.BENALI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Eng_noCmbCyl;                                                 */
/*  input uint16 Sync_nEngClc;                                                */
/*  input uint8 Sync_no_PrevMemrArAcvnEngClc;                                 */
/*  input uint8 Sync_no_MemrArAcvnEngClc;                                     */
/*  input uint8 Sync_ct_MemrnEngCyl;                                          */
/*  input uint16 Sync_nMemrCyl1;                                              */
/*  input uint16 Sync_nMemrCyl2;                                              */
/*  input uint16 Sync_nMemrCyl3;                                              */
/*  input uint8 Sync_no_ArAcvnEngClc;                                         */
/*  output uint8 Sync_ct_MemrnEngCyl;                                         */
/*  output uint16 Sync_nMemrCyl1;                                             */
/*  output boolean Sync_bEndMemrnCycEng;                                      */
/*  output uint16 Sync_nMemrCyl2;                                             */
/*  output uint16 Sync_nMemrCyl3;                                             */
/*  output uint16 Sync_nCycEngMemrCyl1;                                       */
/*  output uint16 Sync_nCycEngMemrCyl2;                                       */
/*  output uint16 Sync_nCycEngMemrCyl3;                                       */
/*  output uint8 Sync_no_PrevMemrArAcvnEngClc;                                */
/*  output uint8 Sync_no_MemrArAcvnEngClc;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGCLC_vidEngSpdMemrCylMot(void)
{
   uint8  u8LocalEng_noCmbCyl;
   uint16 u16LocalMemrnEngCyl;
   uint16 u16LocalSync_nEngClc;


   VEMS_vidGET(Eng_noCmbCyl, u8LocalEng_noCmbCyl);
   VEMS_vidGET(Sync_nEngClc, u16LocalSync_nEngClc);

   if (Sync_no_PrevMemrArAcvnEngClc != Sync_no_MemrArAcvnEngClc)
   {
      Sync_ct_MemrnEngCyl = 0;
   }

   switch (u8LocalEng_noCmbCyl)
   {
      case 1:
         Sync_nMemrCyl1 =
            (uint16)MATHSRV_udtMIN(u16LocalSync_nEngClc, 8191);
         u16LocalMemrnEngCyl = (uint16)(Sync_ct_MemrnEngCyl + 1);
         Sync_bEndMemrnCycEng = 0;
         break;

      case 2:
         Sync_nMemrCyl2 =
            (uint16)MATHSRV_udtMIN(u16LocalSync_nEngClc, 8191);
         u16LocalMemrnEngCyl = (uint16)(Sync_ct_MemrnEngCyl + 1);
         Sync_bEndMemrnCycEng = 0;
         break;

      case 3:
         Sync_nMemrCyl3 =
            (uint16)MATHSRV_udtMIN(u16LocalSync_nEngClc, 8191);
         u16LocalMemrnEngCyl = (uint16)(Sync_ct_MemrnEngCyl + 1);
         Sync_bEndMemrnCycEng = 0;
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         u16LocalMemrnEngCyl = Sync_ct_MemrnEngCyl;
         break;
   }

   Sync_ct_MemrnEngCyl = (uint8)MATHSRV_udtMIN(u16LocalMemrnEngCyl, 3);

   if (Sync_ct_MemrnEngCyl == 3)
   {
      Sync_nCycEngMemrCyl1 = (uint16)MATHSRV_udtMIN(Sync_nMemrCyl1, 8191);
      Sync_nCycEngMemrCyl2 = (uint16)MATHSRV_udtMIN(Sync_nMemrCyl2, 8191);
      Sync_nCycEngMemrCyl3 = (uint16)MATHSRV_udtMIN(Sync_nMemrCyl3, 8191);
      Sync_bEndMemrnCycEng = 1;
      Sync_ct_MemrnEngCyl = 0;
      Sync_nMemrCyl1 = 0;
      Sync_nMemrCyl2 = 0;
      Sync_nMemrCyl3 = 0;
   }
   Sync_no_PrevMemrArAcvnEngClc =
      (uint8)MATHSRV_udtMIN(Sync_no_MemrArAcvnEngClc, 20);
   Sync_no_MemrArAcvnEngClc =
      (uint8)MATHSRV_udtMIN(Sync_no_ArAcvnEngClc, 20);

}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCENGCLC_vidProtectCalcSomme                             */
/* !Description :  Cette fonction permet de protéger le calcul de chaque somme*/
/*                 et nombres d’échantillons lors de décélérations lentes     */
/*                 contre le dépassement de leur dynamique.                   */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  T.BENALI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean Sync_bChgnoArAcvnEngClc;                                    */
/*  input uint16 Sync_nCycEngMemrCyl1;                                        */
/*  input uint16 Sync_nCycEngMemrCyl2;                                        */
/*  input uint16 Sync_nCycEngMemrCyl3;                                        */
/*  input uint32 Sync_nSumCyl1ArAcvPrev;                                      */
/*  input uint32 Sync_nSumCyl2ArAcvPrev;                                      */
/*  input uint32 Sync_nSumCyl3ArAcvPrev;                                      */
/*  output boolean Sync_bProtClcSum;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGCLC_vidProtectCalcSomme(void)
{
   uint32  u32LocalDiffCyl_1;
   uint32  u32LocalDiffCyl_2;
   uint32  u32LocalDiffCyl_3;


   /*Bascule RS*/
   if (Sync_bChgnoArAcvnEngClc != 0)
   {
      Sync_bProtClcSum = 0;
   }
   else
   {
      u32LocalDiffCyl_1 = UINT32_MAX - (uint32)Sync_nCycEngMemrCyl1;
      u32LocalDiffCyl_2 = UINT32_MAX - (uint32)Sync_nCycEngMemrCyl2;
      u32LocalDiffCyl_3 = UINT32_MAX - (uint32)Sync_nCycEngMemrCyl3;

      if (  (Sync_nSumCyl1ArAcvPrev > u32LocalDiffCyl_1)
         || (Sync_nSumCyl2ArAcvPrev > u32LocalDiffCyl_2)
         || (Sync_nSumCyl3ArAcvPrev > u32LocalDiffCyl_3))
      {
         Sync_bProtClcSum = 1;
      }
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCENGCLC_vidEchtSumCyl_1_Areas                           */
/* !Description :  Calcul de la somme des régimes et du nombre d’échantillon  */
/*                 du premier cylindre.                                       */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  T.BENALI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean Sync_bProtClcSum;                                           */
/*  input boolean Sync_bChgnoArAcvnEngClc;                                    */
/*  input uint16 Sync_nCycEngMemrCyl1;                                        */
/*  input uint32 Sync_nSumCyl1ArAcv;                                          */
/*  input uint32 Sync_ct_SampleCyl1ArAcv;                                     */
/*  output uint32 Sync_nSumCyl1ArAcv;                                         */
/*  output uint32 Sync_ct_SampleCyl1ArAcv;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGCLC_vidEchtSumCyl_1_Areas(void)
{
   uint32 u32LocalVar;


   if (Sync_bProtClcSum == 0)
   {
      if (Sync_bChgnoArAcvnEngClc != 0)
      {
         Sync_nSumCyl1ArAcv = (uint32)Sync_nCycEngMemrCyl1;
         Sync_ct_SampleCyl1ArAcv = 1;
      }
      else
      {
         u32LocalVar = UINT32_MAX - (uint32)Sync_nCycEngMemrCyl1;
         if ( Sync_nSumCyl1ArAcv < u32LocalVar)
         {
            Sync_nSumCyl1ArAcv = Sync_nCycEngMemrCyl1 + Sync_nSumCyl1ArAcv;
         }
         else
         {
            Sync_nSumCyl1ArAcv = UINT32_MAX;
         }

         if (Sync_ct_SampleCyl1ArAcv < UINT32_MAX)
         {
            Sync_ct_SampleCyl1ArAcv = Sync_ct_SampleCyl1ArAcv + 1;
         }
         else
         {
            Sync_ct_SampleCyl1ArAcv = 0;
         }
      }
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCENGCLC_vidEchtSumCyl_2_Areas                           */
/* !Description :  Calcul de la somme des régimes et du nombre d’échantillon  */
/*                 du deuxième cylindre.                                      */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  T.BENALI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean Sync_bProtClcSum;                                           */
/*  input boolean Sync_bChgnoArAcvnEngClc;                                    */
/*  input uint16 Sync_nCycEngMemrCyl2;                                        */
/*  input uint32 Sync_nSumCyl2ArAcv;                                          */
/*  input uint32 Sync_ct_SampleCyl2ArAcv;                                     */
/*  output uint32 Sync_nSumCyl2ArAcv;                                         */
/*  output uint32 Sync_ct_SampleCyl2ArAcv;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGCLC_vidEchtSumCyl_2_Areas(void)
{
   uint32 u32LocalVar;


   if (Sync_bProtClcSum == 0)
   {
      if (Sync_bChgnoArAcvnEngClc != 0)
      {
         Sync_nSumCyl2ArAcv = (uint32)Sync_nCycEngMemrCyl2;
         Sync_ct_SampleCyl2ArAcv = 1;
      }
      else
      {
         u32LocalVar = UINT32_MAX - (uint32)Sync_nCycEngMemrCyl2;
         if ( Sync_nSumCyl2ArAcv < u32LocalVar)
         {
            Sync_nSumCyl2ArAcv = Sync_nCycEngMemrCyl2 + Sync_nSumCyl2ArAcv;
         }
         else
         {
            Sync_nSumCyl2ArAcv = UINT32_MAX;
         }

         if (Sync_ct_SampleCyl2ArAcv < UINT32_MAX)
         {
            Sync_ct_SampleCyl2ArAcv = Sync_ct_SampleCyl2ArAcv + 1;
         }
         else
         {
            Sync_ct_SampleCyl2ArAcv = 0;
         }
      }
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCENGCLC_vidEchtSumCyl_3_Areas                           */
/* !Description :  Calcul de la somme des régimes et du nombre d’échantillon  */
/*                 du troisième cylindre.                                     */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  T.BENALI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean Sync_bProtClcSum;                                           */
/*  input boolean Sync_bChgnoArAcvnEngClc;                                    */
/*  input uint16 Sync_nCycEngMemrCyl3;                                        */
/*  input uint32 Sync_nSumCyl3ArAcv;                                          */
/*  input uint32 Sync_ct_SampleCyl3ArAcv;                                     */
/*  output uint32 Sync_nSumCyl3ArAcv;                                         */
/*  output uint32 Sync_ct_SampleCyl3ArAcv;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGCLC_vidEchtSumCyl_3_Areas(void)
{
   uint32 u32LocalVar;


   if (Sync_bProtClcSum == 0)
   {
      if (Sync_bChgnoArAcvnEngClc != 0)
      {
         Sync_nSumCyl3ArAcv = (uint32)Sync_nCycEngMemrCyl3;
         Sync_ct_SampleCyl3ArAcv = 1;
      }
      else
      {
         u32LocalVar = UINT32_MAX - (uint32)Sync_nCycEngMemrCyl3;
         if ( Sync_nSumCyl3ArAcv < u32LocalVar)
         {
            Sync_nSumCyl3ArAcv = Sync_nCycEngMemrCyl3 + Sync_nSumCyl3ArAcv;
         }
         else
         {
            Sync_nSumCyl3ArAcv = UINT32_MAX;
         }

         if (Sync_ct_SampleCyl3ArAcv < UINT32_MAX)
         {
            Sync_ct_SampleCyl3ArAcv = Sync_ct_SampleCyl3ArAcv + 1;
         }
         else
         {
            Sync_ct_SampleCyl3ArAcv = 0;
         }
      }
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCENGCLC_vidCalculMean                                   */
/* !Description :  Si le nombre d'échantillon pour la plage de régime donnée  */
/*                 est inférieur à une valeur mini Sync_NrSampleMin_C, on ne  */
/*                 tient alors pas en compte du calcul de la moyenne en cours.*/
/* !Number      :  FCT2.8                                                     */
/* !Author      :  T.BENALI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Sync_NrSampleMin_C;                                           */
/*  input uint32 Sync_ct_SampleCyl1ArAcv;                                     */
/*  input uint32 Sync_nSumCyl1ArAcv;                                          */
/*  input uint32 Sync_ct_SampleCyl2ArAcv;                                     */
/*  input uint32 Sync_nSumCyl2ArAcv;                                          */
/*  input uint32 Sync_ct_SampleCyl3ArAcv;                                     */
/*  input uint32 Sync_nSumCyl3ArAcv;                                          */
/*  input boolean Sync_bAckdMvCyl1ArAcv;                                      */
/*  input boolean Sync_bAckdMvCyl2ArAcv;                                      */
/*  input boolean Sync_bAckdMvCyl3ArAcv;                                      */
/*  input uint8 Sync_no_BodyCorSatEngClc;                                     */
/*  output boolean Sync_bAckdMvCyl1ArAcv;                                     */
/*  output uint16 Sync_nMvCyl1ArAcv;                                          */
/*  output boolean Sync_bAckdMvCyl2ArAcv;                                     */
/*  output uint16 Sync_nMvCyl2ArAcv;                                          */
/*  output boolean Sync_bAckdMvCyl3ArAcv;                                     */
/*  output uint16 Sync_nMvCyl3ArAcv;                                          */
/*  output boolean Sync_bLrnCorArAcv;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGCLC_vidCalculMean(void)
{
   uint16 u16LocalNrSampleMin;
   uint32 u32LocalMvAllCylArAcv;


   u16LocalNrSampleMin = (uint16)(Sync_NrSampleMin_C + 1);

   /*Cyl_1*/
   if (Sync_ct_SampleCyl1ArAcv >= u16LocalNrSampleMin)
   {
      Sync_bAckdMvCyl1ArAcv = 1;
      u32LocalMvAllCylArAcv = Sync_nSumCyl1ArAcv / Sync_ct_SampleCyl1ArAcv;
      Sync_nMvCyl1ArAcv = (uint16)MATHSRV_udtMIN(u32LocalMvAllCylArAcv, 8192);
   }
   else
   {
      Sync_bAckdMvCyl1ArAcv = 0;
      Sync_nMvCyl1ArAcv = 0;
   }

   /*Cyl_2*/
   if (Sync_ct_SampleCyl2ArAcv >= u16LocalNrSampleMin)
   {
      Sync_bAckdMvCyl2ArAcv = 1;
      u32LocalMvAllCylArAcv = Sync_nSumCyl2ArAcv / Sync_ct_SampleCyl2ArAcv;
      Sync_nMvCyl2ArAcv = (uint16)MATHSRV_udtMIN(u32LocalMvAllCylArAcv, 8192);
   }
   else
   {
      Sync_bAckdMvCyl2ArAcv = 0;
      Sync_nMvCyl2ArAcv = 0;
   }

   /*Cyl_3*/
   if (Sync_ct_SampleCyl3ArAcv >= u16LocalNrSampleMin)
   {
      Sync_bAckdMvCyl3ArAcv = 1;
      u32LocalMvAllCylArAcv = Sync_nSumCyl3ArAcv / Sync_ct_SampleCyl3ArAcv;
      Sync_nMvCyl3ArAcv = (uint16)MATHSRV_udtMIN(u32LocalMvAllCylArAcv, 8192);
   }
   else
   {
      Sync_bAckdMvCyl3ArAcv = 0;
      Sync_nMvCyl3ArAcv = 0;
   }

   if (  (Sync_bAckdMvCyl1ArAcv != 0)
      && (Sync_bAckdMvCyl2ArAcv != 0)
      && (Sync_bAckdMvCyl3ArAcv != 0)
      && (Sync_no_BodyCorSatEngClc != 0))
   {
      Sync_bLrnCorArAcv = 1;
   }
   else
   {
      Sync_bLrnCorArAcv = 0;
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCENGCLC_vidCalculCorrection                             */
/* !Description :  Ce sous-système détermine les corrections par cylindre à   */
/*                 apporter au régime courant. Ces corrections sont bornées   */
/*                 par 5 saturations par groupe de 4 plages.                  */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  T.BENALI                                                   */
/* !Trace_To    :  VEMS_R_09_06456_006.01                                     */
/*                 VEMS_R_09_06456_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint16 Sync_nMvCyl3ArAcv;                                           */
/*  input uint16 Sync_nMvCyl2ArAcv;                                           */
/*  input uint16 Sync_nMvCyl1ArAcv;                                           */
/*  input uint8 Sync_no_BodyCorSatEngClc;                                     */
/*  input sint8 Sync_MaxCorBody1_C;                                           */
/*  input sint8 Sync_MaxCorBody2_C;                                           */
/*  input sint8 Sync_MaxCorBody3_C;                                           */
/*  input sint8 Sync_MaxCorBody4_C;                                           */
/*  input sint8 Sync_MaxCorBody5_C;                                           */
/*  input uint16 Sync_nMvAllCylArAcv;                                         */
/*  output uint16 Sync_nMvAllCylArAcv;                                        */
/*  output sint8 Sync_CorCyl1ArAcv;                                           */
/*  output sint8 Sync_CorCyl2ArAcv;                                           */
/*  output sint8 Sync_CorCyl3ArAcv;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGCLC_vidCalculCorrection(void)
{
   uint32 u32LocalMvAllCylArAcv;
   sint8  s8LocalThreshCorr;
   sint8  s8LocalMaxCorr;
   sint8  s8LocalMinCorr;
   sint32 s32LocalVar;


   u32LocalMvAllCylArAcv = (uint32)( ( Sync_nMvCyl3ArAcv
                                     + Sync_nMvCyl2ArAcv
                                     + Sync_nMvCyl1ArAcv)
                                   / 3);
   Sync_nMvAllCylArAcv = (uint16)MATHSRV_udtMIN(u32LocalMvAllCylArAcv, 8192);

   switch (Sync_no_BodyCorSatEngClc)
   {
      case 1:
         s8LocalThreshCorr = Sync_MaxCorBody1_C;
         break;

      case 2:
         s8LocalThreshCorr = Sync_MaxCorBody2_C;
         break;

      case 3:
         s8LocalThreshCorr = Sync_MaxCorBody3_C;
         break;

      case 4:
         s8LocalThreshCorr = Sync_MaxCorBody4_C;
         break;

      case 5:
         s8LocalThreshCorr = Sync_MaxCorBody5_C;
         break;

      default :
         s8LocalThreshCorr = 0;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   s8LocalThreshCorr =
      (sint8)MATHSRV_udtCLAMP(s8LocalThreshCorr, -100, 100);

   s8LocalMaxCorr = (sint8)MATHSRV_udtABS(s8LocalThreshCorr);
   s8LocalMinCorr = (sint8)(-s8LocalMaxCorr);

   /*Cyl_1*/
   s32LocalVar = (sint32)(Sync_nMvAllCylArAcv - Sync_nMvCyl1ArAcv);
   Sync_CorCyl1ArAcv =
      (sint8)MATHSRV_udtCLAMP(s32LocalVar, s8LocalMinCorr, s8LocalMaxCorr);

   /*Cyl_2*/
   s32LocalVar = (sint32)(Sync_nMvAllCylArAcv - Sync_nMvCyl2ArAcv);
   Sync_CorCyl2ArAcv =
      (sint8)MATHSRV_udtCLAMP(s32LocalVar, s8LocalMinCorr, s8LocalMaxCorr);

   /*Cyl_3*/
   s32LocalVar = (sint32)(Sync_nMvAllCylArAcv - Sync_nMvCyl3ArAcv);
   Sync_CorCyl3ArAcv =
      (sint8)MATHSRV_udtCLAMP(s32LocalVar, s8LocalMinCorr, s8LocalMaxCorr);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCENGCLC_vidCorrectAssignment                            */
/* !Description :  Le principe de ce sous-système est d’affecter les          */
/*                 corrections et le booléen d’apprentissage à leurs vecteurs */
/*                 correspondants.                                            */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  T.BENALI                                                   */
/* !Trace_To    :  VEMS_R_09_06456_008.01                                     */
/*                 VEMS_R_09_06456_011.01                                     */
/*                 VEMS_R_09_06456_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Sync_no_ArAcvnEngClc;                                         */
/*  input uint8 Sync_prm_bLrnCorAr[20];                                       */
/*  input sint8 Sync_CorCyl1ArAcv;                                            */
/*  input sint8 Sync_CorCyl2ArAcv;                                            */
/*  input sint8 Sync_CorCyl3ArAcv;                                            */
/*  input sint8 Sync_prm_nCornEngCyl1[20];                                    */
/*  input sint8 Sync_prm_nCornEngCyl2[20];                                    */
/*  input sint8 Sync_prm_nCornEngCyl3[20];                                    */
/*  output uint8 Sync_prm_bLrnCorAr[20];                                      */
/*  output sint8 Sync_prm_nCornEngCyl1[20];                                   */
/*  output sint8 Sync_prm_nCornEngCyl2[20];                                   */
/*  output sint8 Sync_prm_nCornEngCyl3[20];                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGCLC_vidCorrectAssignment(void)
{
   uint8 u8LocalIndex;
   uint8 u8LocalSync_prm_bLrnCorAr;
   sint8 s8LocalCornEngCyl_1;
   sint8 s8LocalCornEngCyl_2;
   sint8 s8LocalCornEngCyl_3;
   sint8 s8LocalSync_prm_nCornEngCy1;
   sint8 s8LocalSync_prm_nCornEngCyl2;
   sint8 s8LocalSync_prm_nCornEngCyl3;


   if (  (Sync_no_ArAcvnEngClc >= 1)
      && (Sync_no_ArAcvnEngClc <= NB_ACTIVE_ZONE))
   {
      u8LocalIndex = (uint8)(Sync_no_ArAcvnEngClc - 1);
      VEMS_vidGET1DArrayElement(Sync_prm_bLrnCorAr,
                                u8LocalIndex,
                                u8LocalSync_prm_bLrnCorAr);
      if (u8LocalSync_prm_bLrnCorAr == 0)
      {
         s8LocalCornEngCyl_1 = Sync_CorCyl1ArAcv;
         s8LocalCornEngCyl_2 = Sync_CorCyl2ArAcv;
         s8LocalCornEngCyl_3 = Sync_CorCyl3ArAcv;
      }
      else
      {
         VEMS_vidGET1DArrayElement(Sync_prm_nCornEngCyl1,
                                   u8LocalIndex,
                                   s8LocalSync_prm_nCornEngCy1);
         VEMS_vidGET1DArrayElement(Sync_prm_nCornEngCyl2,
                                   u8LocalIndex,
                                   s8LocalSync_prm_nCornEngCyl2);
         VEMS_vidGET1DArrayElement(Sync_prm_nCornEngCyl3,
                                   u8LocalIndex,
                                   s8LocalSync_prm_nCornEngCyl3);
         s8LocalCornEngCyl_1 = (sint8)( ( s8LocalSync_prm_nCornEngCy1
                                        + Sync_CorCyl1ArAcv)
                                      / 2);
         s8LocalCornEngCyl_2 = (sint8)( ( s8LocalSync_prm_nCornEngCyl2
                                        + Sync_CorCyl2ArAcv)
                                      / 2);
         s8LocalCornEngCyl_3 = (sint8)( ( s8LocalSync_prm_nCornEngCyl3
                                        + Sync_CorCyl3ArAcv)
                                      / 2);
      }
      s8LocalSync_prm_nCornEngCy1 =
         (sint8)MATHSRV_udtCLAMP(s8LocalCornEngCyl_1, -100, 100);

      s8LocalSync_prm_nCornEngCyl2 =
         (sint8)MATHSRV_udtCLAMP(s8LocalCornEngCyl_2, -100, 100);

      s8LocalSync_prm_nCornEngCyl3 =
         (sint8)MATHSRV_udtCLAMP(s8LocalCornEngCyl_3, -100, 100);

      VEMS_vidSET1DArrayElement(Sync_prm_bLrnCorAr, u8LocalIndex, 1);
      VEMS_vidSET1DArrayElement(Sync_prm_nCornEngCyl1,
                                u8LocalIndex,
                                s8LocalSync_prm_nCornEngCy1);
      VEMS_vidSET1DArrayElement(Sync_prm_nCornEngCyl2,
                                u8LocalIndex,
                                s8LocalSync_prm_nCornEngCyl2);
      VEMS_vidSET1DArrayElement(Sync_prm_nCornEngCyl3,
                                u8LocalIndex,
                                s8LocalSync_prm_nCornEngCyl3);
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}
/*------------------------------end of file-----------------------------------*/
