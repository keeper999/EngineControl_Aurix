/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQLOSSMON                                               */
/* !Description     : TQLOSSMON component.                                    */
/*                                                                            */
/* !Module          : TQLOSSMON                                               */
/* !Description     : Safety TMS : Valider Pertes Globales                    */
/*                                                                            */
/* !File            : TQLOSSMON_FCT4.C                                        */
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
/*   1 / TQLOSSMON_vidDet_Pertes_Moteur                                       */
/*   2 / TQLOSSMON_vidDet_Pertes_Max_Fric                                     */
/*   3 / TQLOSSMON_vidDet_Pertes_Max_Pomp                                     */
/*   4 / TQLOSSMON_vidDet_Pertes_Max_Dem                                      */
/*   5 / TQLOSSMON_vidVal_Pertes_Pompe_HP                                     */
/*   6 / TQLOSSMON_vidDet_Pertes_Mot_Glob                                     */
/*   7 / TQLOSSMON_vidDet_Adaptatif_Perte                                     */
/*                                                                            */
/* !Reference   : V02 NT 10 01233 / 03                                        */
/* !OtherRefs   : CSCT_CGMT09_1793 / 1.5                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQLOSSMON/TQLOSSMON_FC$*/
/* $Revision::   1.7      $$Author::   mbenfrad       $$Date::   28 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   28 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TQLOSSMON.h"
#include "TQLOSSMON_L.h"
#include "TQLOSSMON_IM.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidDet_Pertes_Moteur                             */
/* !Description :  Cette fonction permet la validation des pertes moteur. Elle*/
/*                 réalise la comparaison des pertes calculées par l’ACS avec */
/*                 celles calculées par la TMS pour chacune des sous          */
/*                 fonctions.                                                 */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_023.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQLOSSMON_vidDet_Pertes_Max_Fric();                      */
/*  extf argret void TQLOSSMON_vidDet_Pertes_Max_Pomp();                      */
/*  extf argret void TQLOSSMON_vidDet_Pertes_Max_Dem();                       */
/*  extf argret void TQLOSSMON_vidVal_Pertes_Pompe_HP();                      */
/*  extf argret void TQLOSSMON_vidDet_Pertes_Mot_Glob();                      */
/*  input uint16 SftyMgt_tqCkFricLoss;                                        */
/*  input uint16 SftyMgt_tqCkPmpLoss;                                         */
/*  input uint16 SftyMgt_tqCkStrtLoss;                                        */
/*  output uint16 SftyMgt_tqCkFricLoss_MP;                                    */
/*  output uint16 SftyMgt_tqCkPmpLoss_MP;                                     */
/*  output uint16 SftyMgt_tqCkStrtLoss_MP;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidDet_Pertes_Moteur(void)
{
   TQLOSSMON_vidDet_Pertes_Max_Fric();
   SftyMgt_tqCkFricLoss_MP = (uint16)MATHSRV_udtMIN(SftyMgt_tqCkFricLoss, 8000);

   TQLOSSMON_vidDet_Pertes_Max_Pomp();
   SftyMgt_tqCkPmpLoss_MP = (uint16)MATHSRV_udtMIN(SftyMgt_tqCkPmpLoss, 8000);

   TQLOSSMON_vidDet_Pertes_Max_Dem();
   SftyMgt_tqCkStrtLoss_MP = (uint16)MATHSRV_udtMIN(SftyMgt_tqCkStrtLoss, 8000);

   TQLOSSMON_vidVal_Pertes_Pompe_HP();
   TQLOSSMON_vidDet_Pertes_Mot_Glob();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidDet_Pertes_Max_Fric                           */
/* !Description :  Pour affiner l’enveloppe max des pertes par friction, on   */
/*                 tient compte de leurs dépendances avec le régime moteur.   */
/* !Number      :  FCT4.2                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_024.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_nCkFilBuf;                                           */
/*  input uint16 SftyMgt_tqCkFricLossT_A[16];                                 */
/*  input uint16 SftyMgt_tqCkFricLossT_T[16];                                 */
/*  output uint16 SftyMgt_tqCkFricLoss;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidDet_Pertes_Max_Fric(void)
{
   uint16 u16LocalCalcPara;
   uint16 u16LocalCkFricLoss;
   uint16 u16LocalSftyMgt_nCkFilBuf;


   VEMS_vidGET(SftyMgt_nCkFilBuf, u16LocalSftyMgt_nCkFilBuf);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(SftyMgt_tqCkFricLossT_A,
                                                   u16LocalSftyMgt_nCkFilBuf,
                                                   16);
   u16LocalCkFricLoss = MATHSRV_u16Interp1d(SftyMgt_tqCkFricLossT_T,
                                            u16LocalCalcPara);

   SftyMgt_tqCkFricLoss = (uint16)MATHSRV_udtMIN(u16LocalCkFricLoss, 8000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidDet_Pertes_Max_Pomp                           */
/* !Description :  On détermine les pertes maximales par pompage. Celles-ci   */
/*                 correspondent à la somme de l’offset max et de l’enveloppe */
/*                 max des pertes par pompage nominales en fonction du régime */
/*                 moteur.                                                    */
/* !Number      :  FCT4.3                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_025.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_nCkFilBuf;                                           */
/*  input uint16 SftyMgt_tqCkPmpLossMax_A[16];                                */
/*  input uint16 SftyMgt_tqCkPmpLossMax_T[16];                                */
/*  input uint16 SftyMgt_tqCkPmpLossOfs_C;                                    */
/*  output uint16 SftyMgt_tqCkPmpLoss;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidDet_Pertes_Max_Pomp(void)
{
   uint16 u16LocalCalcPara;
   uint16 u16LocalCkFricLoss;
   uint16 u16LocalSftyMgt_nCkFilBuf;
   uint32 u32LocalCkPmpLoss;


   VEMS_vidGET(SftyMgt_nCkFilBuf, u16LocalSftyMgt_nCkFilBuf);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(SftyMgt_tqCkPmpLossMax_A,
                                                   u16LocalSftyMgt_nCkFilBuf,
                                                   16);
   u16LocalCkFricLoss = MATHSRV_u16Interp1d(SftyMgt_tqCkPmpLossMax_T,
                                            u16LocalCalcPara);

   u32LocalCkPmpLoss = (uint32)(u16LocalCkFricLoss + SftyMgt_tqCkPmpLossOfs_C);

   SftyMgt_tqCkPmpLoss = (uint16)MATHSRV_udtMIN(u32LocalCkPmpLoss, 8000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidDet_Pertes_Max_Dem                            */
/* !Description :  Les pertes au démarrage sont ajoutées pendant une courte   */
/*                 durée après le démarrage. L’enveloppe max est calculée     */
/*                 pendant cette durée et une fois le temps écoulé, elle est  */
/*                 égale à zéro.                                              */
/* !Number      :  FCT4.4                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_026.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_nCkFilBuf;                                           */
/*  input uint16 SftyMgt_nStrtTqLossThd_C;                                    */
/*  input uint16 TQLOSSMON_u16StrtLossCounter;                                */
/*  input uint16 SftyMgt_tiMaxStrtLoss_C;                                     */
/*  input uint16 SftyMgt_tqCkStrtLossMax_C;                                   */
/*  output uint16 TQLOSSMON_u16StrtLossCounter;                               */
/*  output uint16 SftyMgt_tqCkStrtLoss;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidDet_Pertes_Max_Dem(void)
{
   uint16 u16LocalSftyMgt_nCkFilBuf;
   uint32 u32LocalCounterScal;
   uint32 u32LocalStrtLossCounter;


   VEMS_vidGET(SftyMgt_nCkFilBuf, u16LocalSftyMgt_nCkFilBuf);
   if (u16LocalSftyMgt_nCkFilBuf > SftyMgt_nStrtTqLossThd_C)
   {
      u32LocalStrtLossCounter = (uint32)(TQLOSSMON_u16StrtLossCounter + 1);
      TQLOSSMON_u16StrtLossCounter =
         (uint16)MATHSRV_udtMIN(u32LocalStrtLossCounter, 16375);
   }
   else
   {
      TQLOSSMON_u16StrtLossCounter =
         (uint16)MATHSRV_udtMIN(TQLOSSMON_u16StrtLossCounter, 16375);
   }
   u32LocalCounterScal = (uint32)(TQLOSSMON_u16StrtLossCounter * 4);
   if (u32LocalCounterScal > SftyMgt_tiMaxStrtLoss_C)
   {
      SftyMgt_tqCkStrtLoss = 0;
   }
   else
   {
      SftyMgt_tqCkStrtLoss =
         (uint16)MATHSRV_udtMIN(SftyMgt_tqCkStrtLossMax_C, 8000);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidVal_Pertes_Pompe_HP                           */
/* !Description :  Les pertes de la pompe haute pression sont validées par    */
/*                 comparaison avec une valeur max.                           */
/* !Number      :  FCT4.5                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_027.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_tqCkPmpHiPUnChkBuf;                                  */
/*  input uint16 SftyMgt_tqErrThdSftyEngLoss_C;                               */
/*  input uint16 SftyMgt_tqCkPmpHiPLoss_C;                                    */
/*  output boolean SftyMgt_bDgoTqCkHiPLoss;                                   */
/*  output uint16 SftyMgt_tqCkPmpHiPLoss;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidVal_Pertes_Pompe_HP(void)
{
   uint16 u16LocalSftyMgt_tqCkPmpHiPUnChkB;
   uint32 u32LocalPmpHiPLoss;


   VEMS_vidGET(SftyMgt_tqCkPmpHiPUnChkBuf, u16LocalSftyMgt_tqCkPmpHiPUnChkB);

   u32LocalPmpHiPLoss = (uint32)( SftyMgt_tqErrThdSftyEngLoss_C
                                + SftyMgt_tqCkPmpHiPLoss_C);

   if (u32LocalPmpHiPLoss < u16LocalSftyMgt_tqCkPmpHiPUnChkB)
   {
      SftyMgt_bDgoTqCkHiPLoss = 1;
   }
   else
   {
      SftyMgt_bDgoTqCkHiPLoss = 0;
   }
   SftyMgt_tqCkPmpHiPLoss =
      (uint16)MATHSRV_udtMIN(u16LocalSftyMgt_tqCkPmpHiPUnChkB, 8000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidDet_Pertes_Mot_Glob                           */
/* !Description :  Cette fonction somme les différentes contributions des     */
/*                 pertes moteur et applique une  saturation au signal obtenu.*/
/* !Number      :  FCT4.6                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_028.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_tqCkEngLossUnChkBuf;                                 */
/*  input uint16 SftyMgt_tqCkFricLoss;                                        */
/*  input uint16 SftyMgt_tqCkPmpLoss;                                         */
/*  input uint16 SftyMgt_tqCkStrtLoss;                                        */
/*  input uint16 SftyMgt_tqCkPmpHiPLoss;                                      */
/*  input uint16 SftyMgt_tqCkEngLossMin_C;                                    */
/*  input uint16 SftyMgt_tqCkEngLossMax_C;                                    */
/*  input uint16 SftyMgt_tqErrThdSftyEngLoss_C;                               */
/*  input boolean SftyMgt_bDgoTqCkHiPLoss;                                    */
/*  output boolean SftyMgt_bDgoTqCkEngLoss;                                   */
/*  output uint16 SftyMgt_tqCkEngLossChkBuf;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidDet_Pertes_Mot_Glob(void)
{
   uint16 u16LocaltqCkEngLossUnChkBuf;
   uint16 u16LocaltqCkEngLoss;
   uint32 u32LocalLossSum;


   VEMS_vidGET(SftyMgt_tqCkEngLossUnChkBuf, u16LocaltqCkEngLossUnChkBuf);

   u32LocalLossSum = (uint32)((( SftyMgt_tqCkFricLoss
                               + SftyMgt_tqCkPmpLoss)
                              + SftyMgt_tqCkStrtLoss)
                             + SftyMgt_tqCkPmpHiPLoss);

   u16LocaltqCkEngLoss = (uint16)MATHSRV_udtCLAMP(u32LocalLossSum,
                                                  SftyMgt_tqCkEngLossMin_C,
                                                  SftyMgt_tqCkEngLossMax_C);

   u32LocalLossSum = (uint32)( u16LocaltqCkEngLoss
                             + SftyMgt_tqErrThdSftyEngLoss_C);

   if (  (u32LocalLossSum < u16LocaltqCkEngLossUnChkBuf)
      || (SftyMgt_bDgoTqCkHiPLoss != 0))
   {
      SftyMgt_bDgoTqCkEngLoss = 1;
   }
   else
   {
      SftyMgt_bDgoTqCkEngLoss = 0;
   }

   SftyMgt_tqCkEngLossChkBuf =
      (uint16)MATHSRV_udtMIN(u16LocaltqCkEngLossUnChkBuf, 8000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidDet_Adaptatif_Perte                           */
/* !Description :  Cette fonction permet de valider l’adaptation des pertes   */
/*                 réal isée par l’ACS. Pour être accepté, le couple de       */
/*                 recalage doit être inférieur à un seuil calibrable.        */
/* !Number      :  FCT4.7                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_029.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 SftyMgt_tqCkEngLossAdpUnChkBuf;                              */
/*  input uint16 SftyMgt_tqRelThdSftyLossAdp_C;                               */
/*  input boolean SftyMgt_bDgoEngLossAdpRaw_MP;                               */
/*  input boolean TQLOSSMON_bDgoEngLossAdpRawPrev;                            */
/*  input uint16 SftyMgt_tiDlyEngLossAdp_C;                                   */
/*  input uint16 TQLOSSMON_u16EngLossAdpCounter;                              */
/*  output uint16 SftyMgt_tqCkEngLossAdpChkBuf;                               */
/*  output boolean SftyMgt_bDgoEngLossAdpRaw_MP;                              */
/*  output uint16 TQLOSSMON_u16EngLossAdpCounter;                             */
/*  output boolean SftyMgt_bDgoEngLossAdp;                                    */
/*  output boolean TQLOSSMON_bDgoEngLossAdpRawPrev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidDet_Adaptatif_Perte(void)
{
   sint16 s16LocalTqCkEngLossAdpUnChkBuf;
   sint32 s32LocalCounter;


   VEMS_vidGET(SftyMgt_tqCkEngLossAdpUnChkBuf, s16LocalTqCkEngLossAdpUnChkBuf);

   SftyMgt_tqCkEngLossAdpChkBuf =
      (uint16)MATHSRV_udtCLAMP(s16LocalTqCkEngLossAdpUnChkBuf, 0, 8000);
   if (SftyMgt_tqRelThdSftyLossAdp_C < s16LocalTqCkEngLossAdpUnChkBuf)
   {
      SftyMgt_bDgoEngLossAdpRaw_MP = 1;
   }
   else
   {
      SftyMgt_bDgoEngLossAdpRaw_MP = 0;
   }

   /* Turn_On_Delay */
   if (SftyMgt_bDgoEngLossAdpRaw_MP != 0)
   {
      if (TQLOSSMON_bDgoEngLossAdpRawPrev == 0)
      {
         TQLOSSMON_u16EngLossAdpCounter =
            (uint16)MATHSRV_udtMIN(SftyMgt_tiDlyEngLossAdp_C, 50000);
      }
      else
      {
         if (TQLOSSMON_u16EngLossAdpCounter > 0)
         {
            s32LocalCounter = (sint32)(TQLOSSMON_u16EngLossAdpCounter - 4);
            TQLOSSMON_u16EngLossAdpCounter =
               (uint16)MATHSRV_udtCLAMP(s32LocalCounter, 0, 50000);
         }
      }

      if (TQLOSSMON_u16EngLossAdpCounter == 0)
      {
         SftyMgt_bDgoEngLossAdp = 1;
      }
      else
      {
         SftyMgt_bDgoEngLossAdp = 0;
      }
   }
   else
   {
      SftyMgt_bDgoEngLossAdp = 0;
   }
   TQLOSSMON_bDgoEngLossAdpRawPrev = SftyMgt_bDgoEngLossAdpRaw_MP;
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"

/*---------------------------- end of file -----------------------------------*/