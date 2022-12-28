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
/* !File            : SYNCENGCLC_FCT3.C                                       */
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
/*   1 / SYNCENGCLC_vidMngIdlSpdInsidArea                                     */
/*   2 / SYNCENGCLC_vidContinuityRules                                        */
/*   3 / SYNCENGCLC_vidApplication                                            */
/*   4 / SYNCENGCLC_vidSelectCorrection                                       */
/*   5 / SYNCENGCLC_vidEcritureAdapt                                          */
/*                                                                            */
/* !Reference   : V02 NT 09 06456 / 05                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/SYNC/SYNCENGCLC/SYNCENGCLC_FCT3.$*/
/* $Revision::   1.0      $$Author::   HHAMLAOU       $$Date::   07 Aug 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   07 Aug 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "SYNCENGCLC.h"
#include "SYNCENGCLC_L.h"
#include "SYNCENGCLC_IM.h"
#include "VEMS.h"
#include "SWFAIL.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCENGCLC_vidMngIdlSpdInsidArea                           */
/* !Description :  Ce bloc test la présence du régime de ralenti dans la zone */
/*                 active.                                                    */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  T.BENALI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Sync_no_ArAcvnEngClc;                                         */
/*  input uint16 IdlSys_nTarIdlDyn;                                           */
/*  input uint16 Sync_prm_nThdnEngClc;                                        */
/*  output boolean Sync_bIdlSpdInsdArAcv;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGCLC_vidMngIdlSpdInsidArea(void)
{
   uint16 u16LocalIdlSys_nTarIdlDyn;
   uint32 u32LocalThdnEngClc;


   if (  (Sync_no_ArAcvnEngClc >= 1)
      && (Sync_no_ArAcvnEngClc <= NB_ACTIVE_ZONE))
   {
      VEMS_vidGET(IdlSys_nTarIdlDyn, u16LocalIdlSys_nTarIdlDyn);
      u32LocalThdnEngClc =
         (uint32)(Sync_prm_nThdnEngClc[Sync_no_ArAcvnEngClc - 1] * 4);
      if (u16LocalIdlSys_nTarIdlDyn >= u32LocalThdnEngClc)
      {
         Sync_bIdlSpdInsdArAcv = 1;
      }
      else
      {
         Sync_bIdlSpdInsdArAcv = 0;
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }

}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCENGCLC_vidContinuityRules                              */
/* !Description :  Application des règles de continuité pour les valeurs de   */
/*                 correction.                                                */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  T.BENALI                                                   */
/* !Trace_To    :  VEMS_R_09_06456_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  input uint8 Sync_prm_bLrnCorAr[20];                                       */
/*  input sint8 Sync_prm_nCornEngCyl1[20];                                    */
/*  input sint8 Sync_prm_nCornEngCyl2[20];                                    */
/*  input sint8 Sync_prm_nCornEngCyl3[20];                                    */
/*  input uint16 Sync_prm_nThdnEngClc;                                        */
/*  output sint8 Sync_prm_nCorContnsCyl1[20];                                 */
/*  output sint8 Sync_prm_nCorContnsCyl2[20];                                 */
/*  output sint8 Sync_prm_nCorContnsCyl3[20];                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGCLC_vidContinuityRules(void)
{
   boolean bLocalLrnCorAll;
   boolean bLocalMem_m;
   boolean bLocalMem_d;
   uint8   u8LocalIdx;
   uint8   u8LocalIdx2;
   uint8   u8LocalNbrCyl;
   uint8   u8LocalImpair;
   uint8   u8LocalDesc;
   uint8   u8LocalVal_End;
   uint8   u8LocalStart;
   uint8   u8LocalEnd;
   uint8   u8LocalSync_prm_bLrnCorAr[NB_ACTIVE_ZONE];
   uint8   u8LocalTabb[NB_ACTIVE_ZONE];
   uint16  u16LocalTabg2[NB_ACTIVE_ZONE];
   sint8   s8LocalYa;
   sint8   s8LocalSync_prm_nCornEngCy1[NB_ACTIVE_ZONE];
   sint8   s8LocalSync_prm_nCornEngCyl2[NB_ACTIVE_ZONE];
   sint8   s8LocalSync_prm_nCornEngCyl3[NB_ACTIVE_ZONE];
   sint16  s16LocalDiffY;
   sint32  s32LocalTabg1[NB_ACTIVE_ZONE];
   sint32  s32LocalDiffX;
   sint32  s32LocalXa;
   sint32  s32LocalVar;


   bLocalMem_m = 0;
   bLocalMem_d = 0;
   u8LocalVal_End = 0;
   u8LocalDesc = 0;
   bLocalLrnCorAll = 1;
   for (u8LocalIdx = 0; u8LocalIdx < NB_ACTIVE_ZONE; u8LocalIdx++)
   {
      u8LocalTabb[u8LocalIdx] = 0;
      u8LocalSync_prm_bLrnCorAr[u8LocalIdx] = 0;
      s8LocalSync_prm_nCornEngCy1[u8LocalIdx] = 0;
      s8LocalSync_prm_nCornEngCyl2[u8LocalIdx] = 0;
      s8LocalSync_prm_nCornEngCyl3[u8LocalIdx] = 0;
   }
   VEMS_vidGET1DArray(Sync_prm_bLrnCorAr,
                      NB_ACTIVE_ZONE,
                      u8LocalSync_prm_bLrnCorAr);
   VEMS_vidGET1DArray(Sync_prm_nCornEngCyl1,
                      NB_ACTIVE_ZONE,
                      s8LocalSync_prm_nCornEngCy1);
   VEMS_vidGET1DArray(Sync_prm_nCornEngCyl2,
                      NB_ACTIVE_ZONE,
                      s8LocalSync_prm_nCornEngCyl2);
   VEMS_vidGET1DArray(Sync_prm_nCornEngCyl3,
                      NB_ACTIVE_ZONE,
                      s8LocalSync_prm_nCornEngCyl3);
   for (u8LocalIdx = 0; u8LocalIdx < NB_ACTIVE_ZONE; u8LocalIdx++)
   {
      if (  (u8LocalSync_prm_bLrnCorAr[u8LocalIdx] == 0)
         && (bLocalLrnCorAll != 0))
      {
         bLocalLrnCorAll = 0;
      }
   }

   if (bLocalLrnCorAll == 0)
   {
      /*Areas to be treated*/
      for (u8LocalIdx = NB_ACTIVE_ZONE; u8LocalIdx > 0; u8LocalIdx--)
      {

         u16LocalTabg2[u8LocalIdx - 1] =
            (uint16)( ( Sync_prm_nThdnEngClc[u8LocalIdx]
                      + Sync_prm_nThdnEngClc[u8LocalIdx - 1])
                    / 2);
         if (  (u8LocalIdx == NB_ACTIVE_ZONE)
            && (u8LocalSync_prm_bLrnCorAr[u8LocalIdx - 1] == 0))
         {
            bLocalMem_m = 1;
         }

         if (u8LocalIdx > 1)
         {
            if (  (u8LocalSync_prm_bLrnCorAr[u8LocalIdx - 1] == 0)
               && (u8LocalSync_prm_bLrnCorAr[u8LocalIdx - 2] != 0)
               && (bLocalMem_m != 0))
            {
               u8LocalVal_End = (uint8)(u8LocalIdx - 1);
               bLocalMem_m = 0;
            }

            if (  (u8LocalSync_prm_bLrnCorAr[u8LocalIdx - 1] != 0)
               && (u8LocalSync_prm_bLrnCorAr[u8LocalIdx - 2] == 0))
            {
               bLocalMem_d = 1;
               u8LocalTabb[u8LocalDesc] = (uint8)(u8LocalIdx - 1);
               u8LocalDesc = (uint8)(u8LocalDesc + 1);
            }

            if (  (bLocalMem_d != 0)
               && (u8LocalSync_prm_bLrnCorAr[u8LocalIdx - 1] == 0)
               && (u8LocalSync_prm_bLrnCorAr[u8LocalIdx - 2] != 0))
            {
               u8LocalTabb[u8LocalDesc] = (uint8)(u8LocalIdx - 2);
               u8LocalDesc = (uint8)(u8LocalDesc + 1);
               bLocalMem_d = 0;
            }
         }
      }
      u8LocalImpair = (uint8)(u8LocalDesc % 2);

      /*Continuity corrections for 3 Cylinders*/
      for (u8LocalNbrCyl = 1; u8LocalNbrCyl < 4; u8LocalNbrCyl++)
      {
         if (u8LocalNbrCyl == 1)
         {
            for (u8LocalIdx = 0; u8LocalIdx < NB_ACTIVE_ZONE; u8LocalIdx++)
            {
               s32LocalTabg1[u8LocalIdx] =
                  s8LocalSync_prm_nCornEngCy1[u8LocalIdx];
            }
         }
         else
         {
            if (u8LocalNbrCyl == 2)
            {
               for (u8LocalIdx = 0; u8LocalIdx < NB_ACTIVE_ZONE; u8LocalIdx++)
               {
                  s32LocalTabg1[u8LocalIdx] =
                     s8LocalSync_prm_nCornEngCyl2[u8LocalIdx];
               }
            }
            else
            {
               for (u8LocalIdx = 0; u8LocalIdx < NB_ACTIVE_ZONE; u8LocalIdx++)
               {
                  s32LocalTabg1[u8LocalIdx] =
                     s8LocalSync_prm_nCornEngCyl3[u8LocalIdx];
               }
            }
         }
         /*Rising correction*/
         if (u8LocalVal_End > 0)
         {
            for (u8LocalIdx = u8LocalVal_End;
                 u8LocalIdx < NB_ACTIVE_ZONE;
                 u8LocalIdx++)
            {
               s32LocalTabg1[u8LocalIdx] = s32LocalTabg1[u8LocalVal_End - 1];
            }
         }

         /*Downward correction*/
         for (u8LocalIdx = 1; u8LocalIdx <= u8LocalDesc; u8LocalIdx+=2)
         {
            u8LocalStart = u8LocalTabb[u8LocalIdx - 1];
            if (  (u8LocalIdx == u8LocalDesc)
               && (u8LocalImpair == 1))
            {
               u8LocalEnd = 0;
               s8LocalYa = 0;
               s32LocalXa = (sint32)( ( (3 * Sync_prm_nThdnEngClc[0])
                                      - Sync_prm_nThdnEngClc[1])
                                    / 2);
            }
            else
            {
               u8LocalEnd = (uint8)(u8LocalTabb[u8LocalIdx] + 1);
               s8LocalYa = (sint8)s32LocalTabg1[u8LocalEnd - 1];
               s32LocalXa = (sint32)u16LocalTabg2[u8LocalEnd - 1];

            }
            s32LocalDiffX = u16LocalTabg2[u8LocalStart] - s32LocalXa;
            s16LocalDiffY = (sint16)(s32LocalTabg1[u8LocalStart] - s8LocalYa);
            for (u8LocalIdx2 = u8LocalStart;
                 u8LocalIdx2 >= (uint8)(u8LocalEnd + 1);
                 u8LocalIdx2--)
            {
               /*Linear interpolation*/
               s32LocalVar = (u16LocalTabg2[u8LocalIdx2 - 1] - s32LocalXa)
                           * s16LocalDiffY;
               if (s32LocalDiffX != 0)
               {
                  s32LocalTabg1[u8LocalIdx2 - 1] =
                     s8LocalYa + (s32LocalVar / s32LocalDiffX);
               }
               else
               {
                  if (s32LocalVar >= 0)
                  {
                     s32LocalTabg1[u8LocalIdx2 - 1] = 100;
                  }
                  else
                  {
                     s32LocalTabg1[u8LocalIdx2 - 1] = -100;
                  }
               }
            }
         }
        /*Output Writing*/
         if (u8LocalNbrCyl == 1)
         {
            for (u8LocalIdx = 0; u8LocalIdx < NB_ACTIVE_ZONE; u8LocalIdx++)
            {
               Sync_prm_nCorContnsCyl1[u8LocalIdx] =
                  (sint8)MATHSRV_udtCLAMP(s32LocalTabg1[u8LocalIdx], -100, 100);
            }
         }
         else
         {
            if (u8LocalNbrCyl == 2)
            {
               for (u8LocalIdx = 0; u8LocalIdx < NB_ACTIVE_ZONE; u8LocalIdx++)
               {
                  Sync_prm_nCorContnsCyl2[u8LocalIdx] =
                     (sint8)MATHSRV_udtCLAMP(s32LocalTabg1[u8LocalIdx],
                                             -100,
                                             100);
               }
            }
            else
            {
               for (u8LocalIdx = 0; u8LocalIdx < NB_ACTIVE_ZONE; u8LocalIdx++)
               {
                  Sync_prm_nCorContnsCyl3[u8LocalIdx] =
                     (sint8)MATHSRV_udtCLAMP(s32LocalTabg1[u8LocalIdx],
                                             -100,
                                             100);
               }
            }
         }
      }
   }
   else
   {
      /*All areas are learned: Output = Input*/
      for (u8LocalIdx = 0; u8LocalIdx < NB_ACTIVE_ZONE; u8LocalIdx++)
      {
         Sync_prm_nCorContnsCyl1[u8LocalIdx] =
            (sint8)MATHSRV_udtCLAMP(s8LocalSync_prm_nCornEngCy1[u8LocalIdx],
                                    -100,
                                    100);
         Sync_prm_nCorContnsCyl2[u8LocalIdx] =
            (sint8)MATHSRV_udtCLAMP(s8LocalSync_prm_nCornEngCyl2[u8LocalIdx],
                                    -100,
                                    100);
         Sync_prm_nCorContnsCyl3[u8LocalIdx] =
            (sint8)MATHSRV_udtCLAMP(s8LocalSync_prm_nCornEngCyl3[u8LocalIdx],
                                    -100,
                                    100);
      }
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCENGCLC_vidApplication                                  */
/* !Description :  Ce sous-système sélectionne et applique la correction      */
/*                 (apprise ou non) au régime courant en fonction du numéro de*/
/*                 cylindre en phase de combustion. De plus si le régime de   */
/*                 ralenti est dans la zone active on applique zéro en        */
/*                 correction.                                                */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  T.BENALI                                                   */
/* !Trace_To    :  VEMS_R_09_06456_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SYNCENGCLC_vidSelectCorrection();                        */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Eng_noCmbCyl;                                                 */
/*  input boolean Sync_bIdlSpdInsdArAcv;                                      */
/*  input uint8 Sync_no_ArAcvnEngClc;                                         */
/*  input sint8 Sync_nCorContnsCyl1;                                          */
/*  input sint8 Sync_nCorContnsCyl2;                                          */
/*  input sint8 Sync_nCorContnsCyl3;                                          */
/*  input sint8 Sync_nCorContnsCylCmb;                                        */
/*  output sint8 Sync_nCorContnsCylCmb;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGCLC_vidApplication(void)
{
   uint8 u8LocalEng_noCmbCyl;
   sint8 s8LocalCorContnsCylCmb;


   VEMS_vidGET(Eng_noCmbCyl, u8LocalEng_noCmbCyl);
   if (  (u8LocalEng_noCmbCyl < 4)
      && (u8LocalEng_noCmbCyl > 0))
   {
      if (  (Sync_bIdlSpdInsdArAcv != 0)
         || (Sync_no_ArAcvnEngClc == 0))
      {
         s8LocalCorContnsCylCmb = 0;
      }
      else
      {
         SYNCENGCLC_vidSelectCorrection();
         switch (u8LocalEng_noCmbCyl)
         {
            case 1:
               s8LocalCorContnsCylCmb = Sync_nCorContnsCyl1;
               break;

            case 2:
               s8LocalCorContnsCylCmb = Sync_nCorContnsCyl2;
               break;

            default:
               s8LocalCorContnsCylCmb = Sync_nCorContnsCyl3;
               break;
         }
      }
   }
   else
   {
      s8LocalCorContnsCylCmb = Sync_nCorContnsCylCmb;
      SWFAIL_vidSoftwareErrorHook();
   }
   Sync_nCorContnsCylCmb =
      (sint8)MATHSRV_udtCLAMP(s8LocalCorContnsCylCmb, -100, 100);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCENGCLC_vidSelectCorrection                             */
/* !Description :  Selection de la correction en fonction du numéro de        */
/*                 cylindre en phase de combustion.                           */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  T.BENALI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Sync_no_ArAcvnEngClc;                                         */
/*  input sint8 Sync_prm_nCorContnsCyl1[20];                                  */
/*  input sint8 Sync_prm_nCorContnsCyl2[20];                                  */
/*  input sint8 Sync_prm_nCorContnsCyl3[20];                                  */
/*  output sint8 Sync_nCorContnsCyl1;                                         */
/*  output sint8 Sync_nCorContnsCyl2;                                         */
/*  output sint8 Sync_nCorContnsCyl3;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGCLC_vidSelectCorrection(void)
{
   uint8 u8LocalIndex;

   if (  (Sync_no_ArAcvnEngClc >= 1)
      && (Sync_no_ArAcvnEngClc <= NB_ACTIVE_ZONE))
   {
      u8LocalIndex = (uint8)(Sync_no_ArAcvnEngClc - 1);

      Sync_nCorContnsCyl1 =
         (sint8)MATHSRV_udtCLAMP(Sync_prm_nCorContnsCyl1[u8LocalIndex],
                                 -100,
                                 100);

      Sync_nCorContnsCyl2 =
         (sint8)MATHSRV_udtCLAMP(Sync_prm_nCorContnsCyl2[u8LocalIndex],
                                 -100,
                                 100);

      Sync_nCorContnsCyl3 =
         (sint8)MATHSRV_udtCLAMP(Sync_prm_nCorContnsCyl3[u8LocalIndex],
                                 -100,
                                 100);
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SYNCENGCLC_vidEcritureAdapt                                */
/* !Description :  Fonction de mise à jour des données adaptatives            */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  T.BENALI                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  input uint8 Srv_prm_nCornEngCyl1_eep[20];                                 */
/*  input uint8 Srv_prm_nCornEngCyl2_eep[20];                                 */
/*  input uint8 Srv_prm_nCornEngCyl3_eep[20];                                 */
/*  output sint8 Sync_prm_nCornEngCyl1[20];                                   */
/*  output sint8 Sync_prm_nCornEngCyl2[20];                                   */
/*  output sint8 Sync_prm_nCornEngCyl3[20];                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SYNCENGCLC_vidEcritureAdapt(void)
{
   uint8  u8LocalIndex;
   uint8  u8LocalSrv_prm_nCornEngCy1_eep;
   uint8  u8LocalSrv_prm_nCornEngCyl2_eep;
   uint8  u8LocalSrv_prm_nCornEngCyl3_eep;
   sint8  s8LocalSync_prm_nCornEngCy1;
   sint8  s8LocalSync_prm_nCornEngCyl2;
   sint8  s8LocalSync_prm_nCornEngCyl3;
   sint16 s16LocalnCornEngCyl;


   for (u8LocalIndex = 0; u8LocalIndex < NB_ACTIVE_ZONE; u8LocalIndex++)
   {
      VEMS_vidGET1DArrayElement(Srv_prm_nCornEngCyl1_eep,
                                u8LocalIndex,
                                u8LocalSrv_prm_nCornEngCy1_eep);

      s16LocalnCornEngCyl = (sint16)(u8LocalSrv_prm_nCornEngCy1_eep - 100);
      s8LocalSync_prm_nCornEngCy1 = (sint8)MATHSRV_udtMIN(s16LocalnCornEngCyl,
                                                           100);

      VEMS_vidSET1DArrayElement(Sync_prm_nCornEngCyl1,
                                u8LocalIndex,
                                s8LocalSync_prm_nCornEngCy1);

      VEMS_vidGET1DArrayElement(Srv_prm_nCornEngCyl2_eep,
                                u8LocalIndex,
                                u8LocalSrv_prm_nCornEngCyl2_eep);

      s16LocalnCornEngCyl = (sint16)(u8LocalSrv_prm_nCornEngCyl2_eep - 100);
      s8LocalSync_prm_nCornEngCyl2 = (sint8)MATHSRV_udtMIN(s16LocalnCornEngCyl,
                                                           100);

      VEMS_vidSET1DArrayElement(Sync_prm_nCornEngCyl2,
                                u8LocalIndex,
                                s8LocalSync_prm_nCornEngCyl2);

      VEMS_vidGET1DArrayElement(Srv_prm_nCornEngCyl3_eep,
                                u8LocalIndex,
                                u8LocalSrv_prm_nCornEngCyl3_eep);

      s16LocalnCornEngCyl = (sint16)(u8LocalSrv_prm_nCornEngCyl3_eep - 100);
      s8LocalSync_prm_nCornEngCyl3 = (sint8)MATHSRV_udtMIN(s16LocalnCornEngCyl,
                                                           100);

      VEMS_vidSET1DArrayElement(Sync_prm_nCornEngCyl3,
                                u8LocalIndex,
                                s8LocalSync_prm_nCornEngCyl3);
   }
}
/*------------------------------end of file-----------------------------------*/