/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : RC01                                                    */
/* !Description     : RC01 Component                                          */
/*                                                                            */
/* !Module          : RC01                                                    */
/* !Description     : Gestion des Readiness Codes 01                          */
/*                                                                            */
/* !File            : RC01_FCT1.C                                             */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / RC01_vidF01_Rdy_Init                                                 */
/*   2 / RC01_vidF00_Def_Prio_Init                                            */
/*   3 / RC01_vidF02_Rdy_ValRdy                                               */
/*   4 / RC01_vidF03_Rdy_ReinitRdy                                            */
/*   5 / RC01_vidF04_Rdy_ValClasRdy                                           */
/*   6 / RC01_vidF06_Rdy_ValClasRdyCfOBD                                      */
/*                                                                            */
/* !Reference   : PTS_DOC_5263162 / 02                                        */
/* !OtherRefs   : VEMS V02 ECU#065983                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/GD/RC01/RC01_FCT1.C_v           $*/
/* $Revision::   1.11     $$Author::   mbenfrad       $$Date::   03 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   03 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "RC01.h"
#include "RC01_L.h"
#include "RC01_IM.h"
#include "GD_API.h"
#include "NVMSRV.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RC01_vidF01_Rdy_Init                                       */
/* !Description :  récupération de l’EEPROM des états des RC unitaires et     */
/*                 familiaux.                                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_E_11_03801_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean Rdy_bDftValMisf_C;                                          */
/*  input uint16 Rdy_u16ClasRdy_EEPROM;                                       */
/*  input boolean Rdy_bDftValLfbk_C;                                          */
/*  input boolean Rdy_bDftValCpt_C;                                           */
/*  input boolean Rdy_bDftValCat_C;                                           */
/*  input boolean Rdy_bDftValHeatCat_C;                                       */
/*  input boolean Rdy_bDftValEVAP_C;                                          */
/*  input boolean Rdy_bDftValIAE_C;                                           */
/*  input boolean Rdy_bDftValClim_C;                                          */
/*  input boolean Rdy_bDftValO2S_C;                                           */
/*  input boolean Rdy_bDftValHeatO2_C;                                        */
/*  input boolean Rdy_bDftValVVT_C;                                           */
/*  output uint16 Rdy_u16ClasRdy_EEPROM_prev;                                 */
/*  output uint8 Rdy_u8ClasRdyLSB;                                            */
/*  output uint8 Rdy_u8ClasRdyMSB;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RC01_vidF01_Rdy_Init(void)
{
   boolean bLocalTrue;


   bLocalTrue = 1;
   /* RC families */
   if (Rdy_bDftValMisf_C != FALSE)
   {
      /*QAC WARNING: Macro use if else*/
      GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, MISF, bLocalTrue);
   }

   if (Rdy_bDftValLfbk_C != FALSE)
   {
      /*QAC WARNING: Macro use if else*/
      GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, LFBK, bLocalTrue);
   }

   if (Rdy_bDftValCpt_C != FALSE)
   {
      /*QAC WARNING: Macro use if else*/
      GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, CPT, bLocalTrue);
   }

   if (Rdy_bDftValCat_C != FALSE)
   {
      /*QAC WARNING: Macro use if else*/
      GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, CAT, bLocalTrue);
   }

   if (Rdy_bDftValHeatCat_C != FALSE)
   {
      /*QAC WARNING: Macro use if else*/
      GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, HEATCAT, bLocalTrue);
   }

   if (Rdy_bDftValEVAP_C != FALSE)
   {
      /*QAC WARNING: Macro use if else*/
      GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, EVAP, bLocalTrue);
   }

   if (Rdy_bDftValIAE_C != FALSE)
   {
      /*QAC WARNING: Macro use if else*/
      GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, IAE, bLocalTrue);
   }

   if (Rdy_bDftValClim_C != FALSE)
   {
      /*QAC WARNING: Macro use if else*/
      GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, CLIM, bLocalTrue);
   }

   if (Rdy_bDftValO2S_C != FALSE)
   {
      /*QAC WARNING: Macro use if else*/
      GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, O2S, bLocalTrue);
   }

   if (Rdy_bDftValHeatO2_C != FALSE)
   {
      /*QAC WARNING: Macro use if else*/
      GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, HEATO2, bLocalTrue);
   }

   if (Rdy_bDftValVVT_C != FALSE)
   {
      /*QAC WARNING: Macro use if else*/
      GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, VVTRC01, bLocalTrue);
   }
   Rdy_u16ClasRdy_EEPROM_prev = Rdy_u16ClasRdy_EEPROM;
   Rdy_u8ClasRdyLSB = (uint8)(Rdy_u16ClasRdy_EEPROM & 0x00FF);
   Rdy_u8ClasRdyMSB = (uint8)((Rdy_u16ClasRdy_EEPROM & 0xFF00)>>8);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RC01_vidF00_Def_Prio_Init                                  */
/* !Description :  Une panne est prioritaire si son RC associé est Catalyseur */
/*                 ou Misfire.                                                */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint16 ClasRdyMisf_T[10];                                           */
/*  input uint16 ClasRdyLfbk_T[40];                                           */
/*  output boolean GD_bPrioRdy[30];                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RC01_vidF00_Def_Prio_Init(void)
{
   sint32 s32LocalIdx1;
   sint32 s32LocalIdx2;
   sint32 s32LocalIdx3;
   uint16 u16LocalMisf;
   uint16 u16LocalLfbk;


   for (s32LocalIdx1 = 0; s32LocalIdx1 < GD_DFT_NB; s32LocalIdx1++)
   {
      VEMS_vidSET1DArrayElement(GD_bPrioRdy, (uint16)s32LocalIdx1, 0);
   }

   for(s32LocalIdx2 = 0; s32LocalIdx2 < CLASRDY_MISF_NB_DFT; s32LocalIdx2++)
   {
      u16LocalMisf = ClasRdyMisf_T[s32LocalIdx2];

      if (u16LocalMisf < GD_DFT_NB)
      {
         VEMS_vidSET1DArrayElement(GD_bPrioRdy, u16LocalMisf, 1);
      }
      else if (u16LocalMisf != 0xFFFF)
      {
         SWFAIL_vidSoftwareErrorHook();
      }
   }

   for(s32LocalIdx3 = 0; s32LocalIdx3 < CLASRDY_LFBK_NB_DFT; s32LocalIdx3++)
   {
      u16LocalLfbk = ClasRdyLfbk_T[s32LocalIdx3];

      if (u16LocalLfbk < GD_DFT_NB)
      {
         VEMS_vidSET1DArrayElement(GD_bPrioRdy, u16LocalLfbk, 1);
      }
      else if (u16LocalLfbk != 0xFFFF)
      {
         SWFAIL_vidSoftwareErrorHook();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RC01_vidF02_Rdy_ValRdy                                     */
/* !Description :  fonction permettant la validation des RC unitaires         */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_E_11_03801_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Rdy_au8Rdy_EEPROM;                                            */
/*  input GD_tstrDftEep GD_astrDftEep[30];                                    */
/*  input uint8 DC_au8DC_EEPROM;                                              */
/*  output uint8 Rdy_au8Rdy_EEPROM;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RC01_vidF02_Rdy_ValRdy(void)
{
   sint32 s32LocalDivision;
   sint32 s32LocalMask;
   sint32 s32LocalIdxDft;
   sint32 s32Local;


   s32LocalIdxDft = 0;
   for (s32LocalDivision = 0;
        s32LocalDivision < ((GD_DFT_NB+7)/8);
        s32LocalDivision++)
   {
      for (s32LocalMask = 1; s32LocalMask <256; s32LocalMask=s32LocalMask<<1)
      {
         s32Local = Rdy_au8Rdy_EEPROM[s32LocalDivision] &  s32LocalMask;
         /* RC enabled if not already done */
         if (s32Local == FALSE)
         {
            s32Local =
               ((GD_astrDftEep[s32LocalIdxDft].u8GduGobdManagement) & 0x01);
            if (s32Local != FALSE)
            {
               Rdy_au8Rdy_EEPROM[s32LocalDivision] =
                  (uint8)( Rdy_au8Rdy_EEPROM[s32LocalDivision]
                         & ~(s32LocalMask));
            }
            else
            {
               s32Local = DC_au8DC_EEPROM[s32LocalDivision] &  s32LocalMask;
               if(!s32Local)
               {
                  Rdy_au8Rdy_EEPROM[s32LocalDivision] =
                     (uint8)( Rdy_au8Rdy_EEPROM[s32LocalDivision]
                            & ~(s32LocalMask));
               }
               else
               {
                  Rdy_au8Rdy_EEPROM[s32LocalDivision] =
                     (uint8)( Rdy_au8Rdy_EEPROM[s32LocalDivision]
                            | (s32LocalMask));
               }
            }
         }

         if ( s32LocalIdxDft<(GD_DFT_NB-1))
         {
            s32LocalIdxDft++;
         } else
         {
            s32LocalMask = 256;
         }
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RC01_vidF03_Rdy_ReinitRdy                                  */
/* !Description :  Réinitialisation des RC sur requêtes APV et SCANTOOL       */
/*                 (mode4)                                                    */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_E_11_03801_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  input uint16 Rdy_u16ClasRdy_EEPROM;                                       */
/*  input boolean Rdy_bDftValCat_C;                                           */
/*  input boolean Rdy_bDftValHeatO2_C;                                        */
/*  input boolean Rdy_bDftValVVT_C;                                           */
/*  input boolean Rdy_bDftValIAE_C;                                           */
/*  input boolean Rdy_bDftValLfbk_C;                                          */
/*  input boolean Rdy_bDftValMisf_C;                                          */
/*  input boolean Rdy_bDftValEVAP_C;                                          */
/*  input boolean Rdy_bDftValCpt_C;                                           */
/*  input boolean Rdy_bDftValHeatCat_C;                                       */
/*  input boolean Rdy_bDftValClim_C;                                          */
/*  input boolean Rdy_bDftValO2S_C;                                           */
/*  output uint8 Rdy_au8Rdy_EEPROM;                                           */
/*  output uint16 Rdy_u16ClasRdy_EEPROM_prev;                                 */
/*  output uint8 Rdy_u8ClasRdyLSB;                                            */
/*  output uint8 Rdy_u8ClasRdyMSB;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RC01_vidF03_Rdy_ReinitRdy(void)
{
   sint32 s32LocalIdx;
   uint8  u8LocalNbMaxLoop;


   u8LocalNbMaxLoop = (uint8)((GD_DFT_NB / 8) + 1);
   for(s32LocalIdx = 0; s32LocalIdx < u8LocalNbMaxLoop; s32LocalIdx++)
   {
      VEMS_vidSET1DArrayElement(Rdy_au8Rdy_EEPROM, s32LocalIdx, 0);
   }
   /* RC family */
   /*QAC WARNING: Macro use if else*/
   GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, CAT, Rdy_bDftValCat_C);
   /*QAC WARNING: Macro use if else*/
   GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, HEATO2, Rdy_bDftValHeatO2_C);
   /*QAC WARNING: Macro use if else*/
   GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, VVTRC01, Rdy_bDftValVVT_C);
   /*QAC WARNING: Macro use if else*/
   GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, IAE, Rdy_bDftValIAE_C);
   /*QAC WARNING: Macro use if else*/
   GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, LFBK, Rdy_bDftValLfbk_C);
   /*QAC WARNING: Macro use if else*/
   GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, MISF, Rdy_bDftValMisf_C);
   /*QAC WARNING: Macro use if else*/
   GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, EVAP, Rdy_bDftValEVAP_C);
   /*QAC WARNING: Macro use if else*/
   GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, CPT, Rdy_bDftValCpt_C);
   /*QAC WARNING: Macro use if else*/
   GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, HEATCAT, Rdy_bDftValHeatCat_C);
   /*QAC WARNING: Macro use if else*/
   GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, CLIM, Rdy_bDftValClim_C);
   /*QAC WARNING: Macro use if else*/
   GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, O2S, Rdy_bDftValO2S_C);
   Rdy_u16ClasRdy_EEPROM_prev = Rdy_u16ClasRdy_EEPROM;
   Rdy_u8ClasRdyLSB = (uint8)(Rdy_u16ClasRdy_EEPROM & 0x00FF);
   Rdy_u8ClasRdyMSB = (uint8)((Rdy_u16ClasRdy_EEPROM & 0xFF00)>>8);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RC01_vidF04_Rdy_ValClasRdy                                 */
/* !Description :  fonction permettant la validation des RC familiaux         */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  C.GHARSALLI                                                */
/* !Trace_To    :  VEMS_E_11_03801_006.01                                     */
/*                 VEMS_E_11_03801_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint16 Rdy_u16ClasRdy_EEPROM_prev;                                  */
/*  input uint16 ClasRdyMisf_T[10];                                           */
/*  input uint8 Rdy_au8Rdy_EEPROM;                                            */
/*  input uint16 Rdy_u16ClasRdy_EEPROM;                                       */
/*  input uint16 ClasRdyLfbk_T[40];                                           */
/*  input uint16 ClasRdyCat_T[5];                                             */
/*  input uint16 ClasRdyO2S_T[20];                                            */
/*  input uint16 ClasRdyHeatO2_T[20];                                         */
/*  input uint16 ClasRdyVVT_T[20];                                            */
/*  output uint16 Rdy_u16ClasRdy_EEPROM_prev;                                 */
/*  output uint8 Rdy_u8ClasRdyLSB;                                            */
/*  output uint8 Rdy_u8ClasRdyMSB;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RC01_vidF04_Rdy_ValClasRdy(void)
{
   boolean bLocalRdy_bMisf;
   boolean bLocalRdy_bLfbk;
   boolean bLocalRdy_bCat;
   boolean bLocalRdy_bO2S;
   boolean bLocalRdy_bHeatO2;
   boolean bLocalRdy_bVVT;
   boolean bLocalMisf_Rdy;
   boolean bLocalLfbk_Rdy;
   boolean bLocalCat_Rdy;
   boolean bLocalO2S_Rdy;
   boolean bLocalHeatO2_Rdy;
   boolean bLocalVVT_Rdy;
   boolean bLocalRCVal;
   uint8   u8LocalRdy;
   uint8   u8LocalRatio;
   uint8   u8LocalLabel;
   uint16  u16LocalMisf1;
   uint16  u16LocalLfbk1;
   uint16  u16LocalCat1;
   uint16  u16LocalO2S1;
   uint16  u16LocalHeatO21;
   uint16  u16LocalVVT1;
   uint16  u16LocalDivision;
   sint32  s32LocalDefIdx;


   bLocalRCVal = GD_bBitRead16(Rdy_u16ClasRdy_EEPROM_prev, MISF);
   if (bLocalRCVal == 0)
   {
      bLocalMisf_Rdy = 0;
      for (s32LocalDefIdx = 0;
          (  (s32LocalDefIdx < CLASRDY_MISF_NB_DFT)
          && (bLocalMisf_Rdy == 0));
          s32LocalDefIdx++)
      {
         u16LocalMisf1 = ClasRdyMisf_T[s32LocalDefIdx];
         if (u16LocalMisf1 < GD_DFT_NB)
         {
            u16LocalDivision = (uint16)(u16LocalMisf1 / 8);
            u8LocalRatio = (uint8)(u16LocalMisf1 % 8);
            VEMS_vidGET1DArrayElement(Rdy_au8Rdy_EEPROM,
                                      u16LocalDivision,
                                      u8LocalLabel);
            u8LocalRdy = GD_bBitRead(u8LocalLabel, u8LocalRatio);
            if (u8LocalRdy == 0)
            {
               bLocalMisf_Rdy = 1;
            }
         }
         else
         {
            if (u16LocalMisf1 != 0xFFFF)
            {
               SWFAIL_vidSoftwareErrorHook();
            }
         }
      }
      if (bLocalMisf_Rdy == 0)
      {
         bLocalRdy_bMisf = 1;
         GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, MISF, bLocalRdy_bMisf);
      }
   }

   bLocalRCVal = GD_bBitRead16(Rdy_u16ClasRdy_EEPROM_prev, LFBK);
   if (bLocalRCVal == 0)
   {
      bLocalLfbk_Rdy = 0;
      for (s32LocalDefIdx = 0;
           (  (s32LocalDefIdx < CLASRDY_LFBK_NB_DFT)
           && (bLocalLfbk_Rdy == 0));
            s32LocalDefIdx++)
      {
         u16LocalLfbk1 = ClasRdyLfbk_T[s32LocalDefIdx];
         if (u16LocalLfbk1 < GD_DFT_NB)
         {
            u16LocalDivision = (uint16)(u16LocalLfbk1 / 8);
            u8LocalRatio = (uint8)(u16LocalLfbk1 % 8);
            VEMS_vidGET1DArrayElement(Rdy_au8Rdy_EEPROM,
                                      u16LocalDivision,
                                      u8LocalLabel);
            u8LocalRdy = GD_bBitRead(u8LocalLabel, u8LocalRatio);
            if (u8LocalRdy == 0)
            {
               bLocalLfbk_Rdy = 1;
            }
         }
         else
         {
            if (u16LocalLfbk1 != 0xFFFF)
            {
               SWFAIL_vidSoftwareErrorHook();
            }
         }
      }
      if (bLocalLfbk_Rdy == 0)
      {
         bLocalRdy_bLfbk = 1;
         GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, LFBK, bLocalRdy_bLfbk);
      }
   }

   bLocalRCVal = GD_bBitRead16(Rdy_u16ClasRdy_EEPROM_prev, CAT);
   if (bLocalRCVal == 0)
   {
      bLocalCat_Rdy = 0;
      for (s32LocalDefIdx = 0;
           (  (s32LocalDefIdx < CLASRDY_CAT_NB_DFT)
           && (bLocalCat_Rdy == 0));
           s32LocalDefIdx++)
      {
         u16LocalCat1 = ClasRdyCat_T[s32LocalDefIdx];
         if (u16LocalCat1 < GD_DFT_NB)
         {
            u16LocalDivision = (uint16)(u16LocalCat1 / 8);
            u8LocalRatio = (uint8)(u16LocalCat1 % 8);
            VEMS_vidGET1DArrayElement(Rdy_au8Rdy_EEPROM,
                                      u16LocalDivision,
                                      u8LocalLabel);
            u8LocalRdy = GD_bBitRead(u8LocalLabel, u8LocalRatio);

            if (u8LocalRdy == 0)
            {
               bLocalCat_Rdy = 1;
            }
         }
         else
         {
            if (u16LocalCat1 != 0xFFFF)
            {
               SWFAIL_vidSoftwareErrorHook();
            }
         }
      }
      if (bLocalCat_Rdy == 0)
      {
         bLocalRdy_bCat = 1;
         GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, CAT, bLocalRdy_bCat);
      }
   }

   bLocalRCVal = GD_bBitRead16(Rdy_u16ClasRdy_EEPROM_prev, O2S);
   if (bLocalRCVal == 0)
   {
      bLocalO2S_Rdy = 0;
      for (s32LocalDefIdx = 0;
           (  (s32LocalDefIdx < CLASRDY_O2S_NB_DFT)
           && (bLocalO2S_Rdy == 0));
           s32LocalDefIdx++)
      {
         u16LocalO2S1 = ClasRdyO2S_T[s32LocalDefIdx];
         if (u16LocalO2S1 < GD_DFT_NB)
         {
            u16LocalDivision = (uint16)(u16LocalO2S1 / 8);
            u8LocalRatio = (uint8)(u16LocalO2S1 % 8);
            VEMS_vidGET1DArrayElement(Rdy_au8Rdy_EEPROM,
                                      u16LocalDivision,
                                      u8LocalLabel);
            u8LocalRdy = GD_bBitRead(u8LocalLabel, u8LocalRatio);
            if (u8LocalRdy == 0)
            {
               bLocalO2S_Rdy = 1;
            }
         }
         else
         {
            if (u16LocalO2S1 != 0xFFFF)
            {
               SWFAIL_vidSoftwareErrorHook();
            }
         }
      }
      if (bLocalO2S_Rdy == 0)
      {
         bLocalRdy_bO2S = 1;
         GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, O2S, bLocalRdy_bO2S);
      }
   }

   bLocalRCVal = GD_bBitRead16(Rdy_u16ClasRdy_EEPROM_prev, HEATO2);
   if (bLocalRCVal == 0)
   {
      bLocalHeatO2_Rdy = 0;
      for (s32LocalDefIdx = 0;
           (  (s32LocalDefIdx < CLASRDY_HEATO2_NB_DFT)
           && (bLocalHeatO2_Rdy == 0));
           s32LocalDefIdx++)
      {
         u16LocalHeatO21 = ClasRdyHeatO2_T[s32LocalDefIdx];
         if (u16LocalHeatO21 < GD_DFT_NB)
         {
            u16LocalDivision = (uint16)(u16LocalHeatO21 / 8);
            u8LocalRatio = (uint8)(u16LocalHeatO21 % 8);
            VEMS_vidGET1DArrayElement(Rdy_au8Rdy_EEPROM,
                                      u16LocalDivision,
                                      u8LocalLabel);
            u8LocalRdy = GD_bBitRead(u8LocalLabel, u8LocalRatio);
            if (u8LocalRdy == 0)
            {
               bLocalHeatO2_Rdy = 1;
            }
         }
         else
         {
            if (u16LocalHeatO21 != 0xFFFF)
            {
               SWFAIL_vidSoftwareErrorHook();
            }
         }
      }
      if (bLocalHeatO2_Rdy == 0)
      {
         bLocalRdy_bHeatO2 = 1;
         GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, HEATO2, bLocalRdy_bHeatO2);
      }
   }

   bLocalRCVal = GD_bBitRead16(Rdy_u16ClasRdy_EEPROM_prev, VVTRC01);
   if (bLocalRCVal == 0)
   {
      bLocalVVT_Rdy = 0;
      for (s32LocalDefIdx = 0;
           (  (s32LocalDefIdx < CLASRDY_VVT_NB_DFT)
           && (bLocalVVT_Rdy == 0));
           s32LocalDefIdx++)
      {
         u16LocalVVT1 = ClasRdyVVT_T[s32LocalDefIdx];
         if (u16LocalVVT1 < GD_DFT_NB)
         {
            u16LocalDivision = (uint16)(u16LocalVVT1 / 8);
            u8LocalRatio = (uint8)(u16LocalVVT1 % 8);
            VEMS_vidGET1DArrayElement(Rdy_au8Rdy_EEPROM,
                                      u16LocalDivision,
                                      u8LocalLabel);
            u8LocalRdy = GD_bBitRead(u8LocalLabel, u8LocalRatio);
            if (u8LocalRdy == 0)
            {
               bLocalVVT_Rdy = 1;
            }
         }
         else
         {
            if (u16LocalVVT1 != 0xFFFF)
            {
               SWFAIL_vidSoftwareErrorHook();
            }
         }
      }
      if (bLocalVVT_Rdy == 0)
      {
         bLocalRdy_bVVT = 1;
         GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, VVTRC01, bLocalRdy_bVVT);
      }
   }
   Rdy_u16ClasRdy_EEPROM_prev = Rdy_u16ClasRdy_EEPROM;
   Rdy_u8ClasRdyLSB = (uint8)(Rdy_u16ClasRdy_EEPROM & 0x00FF);
   Rdy_u8ClasRdyMSB = (uint8)((Rdy_u16ClasRdy_EEPROM & 0xFF00)>>8);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  RC01_vidF06_Rdy_ValClasRdyCfOBD                            */
/* !Description :  Cette fonction vérifie dans le cas ou un défaut OBD si il  */
/*                 est présent dans l’une  des famille de readines code et    */
/*                 passer le RC01 familial à Etat_FAIT le cas échéant.        */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  C.GHARSALLI                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Rdy_u16ClasRdy_EEPROM_prev;                                  */
/*  input uint16 ClasRdyMisf_T[10];                                           */
/*  input uint16 Rdy_u16ClasRdy_EEPROM;                                       */
/*  input uint16 ClasRdyLfbk_T[40];                                           */
/*  input uint16 ClasRdyCat_T[5];                                             */
/*  input uint16 ClasRdyO2S_T[20];                                            */
/*  input uint16 ClasRdyHeatO2_T[20];                                         */
/*  input uint16 ClasRdyVVT_T[20];                                            */
/*  output uint16 Rdy_u16ClasRdy_EEPROM_prev;                                 */
/*  output uint8 Rdy_u8ClasRdyLSB;                                            */
/*  output uint8 Rdy_u8ClasRdyMSB;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void RC01_vidF06_Rdy_ValClasRdyCfOBD
(
   uint16 u16IdxDft
)
{
   boolean bLocalRdy_bMisfPrev;
   boolean bLocalRdy_bLfbkfPrev;
   boolean bLocalRdy_bCatPrev;
   boolean bLocalRdy_bO2SPrev;
   boolean bLocalRdy_bHeatO2Prev;
   boolean bLocalRdy_bVvtPrev;
   boolean bLocalRdy_bMisf;
   boolean bLocalRdy_bLfbk;
   boolean bLocalRdy_bCat;
   boolean bLocalRdy_bO2S;
   boolean bLocalRdy_bHeatO2;
   boolean bLocalRdy_bVVT;
   uint16  u16LocalMisf;
   uint16  u16LocalLfbk;
   uint16  u16LocalCat;
   uint16  u16LocalO2S;
   uint16  u16LocalHeatO2;
   uint16  u16LocalVVT;
   sint32  s32LocalDefIdx;


   bLocalRdy_bMisfPrev = GD_bBitRead16(Rdy_u16ClasRdy_EEPROM_prev, MISF);
   if (bLocalRdy_bMisfPrev == 0)
   {
      bLocalRdy_bMisf = 0;
      for (s32LocalDefIdx = 0;
           (  (s32LocalDefIdx < CLASRDY_MISF_NB_DFT)
           && (bLocalRdy_bMisf == 0));
           s32LocalDefIdx++)
      {
         u16LocalMisf = ClasRdyMisf_T[s32LocalDefIdx];
         if (u16LocalMisf != 0xFFFF)
         {
            if (u16LocalMisf == u16IdxDft)
            {
               bLocalRdy_bMisf = 1;
               GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, MISF, bLocalRdy_bMisf);
            }
         }
      }
   }

   bLocalRdy_bLfbkfPrev = GD_bBitRead16(Rdy_u16ClasRdy_EEPROM_prev, LFBK);
   if (bLocalRdy_bLfbkfPrev == 0)
   {
      bLocalRdy_bLfbk = 0;
      for (s32LocalDefIdx = 0;
           (  (s32LocalDefIdx < CLASRDY_LFBK_NB_DFT)
           && (bLocalRdy_bLfbk == 0));
           s32LocalDefIdx++)
      {
         u16LocalLfbk = ClasRdyLfbk_T[s32LocalDefIdx];

         if (u16LocalLfbk != 0xFFFF)
         {
            if (u16LocalLfbk == u16IdxDft)
            {
               bLocalRdy_bLfbk = 1;
               GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, LFBK, bLocalRdy_bLfbk);
            }
         }
      }
   }

   bLocalRdy_bCatPrev = GD_bBitRead16(Rdy_u16ClasRdy_EEPROM_prev, CAT);
   if (bLocalRdy_bCatPrev == 0)
   {
      bLocalRdy_bCat = 0;
      for (s32LocalDefIdx = 0;
           (  (s32LocalDefIdx < CLASRDY_CAT_NB_DFT)
           && (bLocalRdy_bCat == 0));
           s32LocalDefIdx++)
      {
         u16LocalCat = ClasRdyCat_T[s32LocalDefIdx];
         if (u16LocalCat != 0xFFFF)
         {
            if (u16LocalCat == u16IdxDft)
            {
               bLocalRdy_bCat = 1;
               GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, CAT, bLocalRdy_bCat);
            }
         }
      }
   }

   bLocalRdy_bO2SPrev = GD_bBitRead16(Rdy_u16ClasRdy_EEPROM_prev, O2S);
   if (bLocalRdy_bO2SPrev == 0)
   {
      bLocalRdy_bO2S = 0;
      for (s32LocalDefIdx = 0;
           (  (s32LocalDefIdx < CLASRDY_O2S_NB_DFT)
           && (bLocalRdy_bO2S == 0));
           s32LocalDefIdx++)
      {
         u16LocalO2S = ClasRdyO2S_T[s32LocalDefIdx];
         if (u16LocalO2S != 0xFFFF)
         {
            if (u16LocalO2S == u16IdxDft)
            {
               bLocalRdy_bO2S = 1;
               GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, O2S, bLocalRdy_bO2S);
            }
         }
      }
   }

   bLocalRdy_bHeatO2Prev = GD_bBitRead16(Rdy_u16ClasRdy_EEPROM_prev, HEATO2);
   if (bLocalRdy_bHeatO2Prev == 0)
   {
      bLocalRdy_bHeatO2 = 0;
      for (s32LocalDefIdx = 0;
           (  (s32LocalDefIdx < CLASRDY_HEATO2_NB_DFT)
           && (bLocalRdy_bHeatO2 == 0));
           s32LocalDefIdx++)
      {
         u16LocalHeatO2 = ClasRdyHeatO2_T[s32LocalDefIdx];
         if (u16LocalHeatO2 != 0xFFFF)
         {
            if (u16LocalHeatO2 == u16IdxDft)
            {
               bLocalRdy_bHeatO2 = 1;
               GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM,
                                HEATO2,
                                bLocalRdy_bHeatO2);
            }
         }
      }
   }
   bLocalRdy_bVvtPrev = GD_bBitRead16(Rdy_u16ClasRdy_EEPROM_prev, VVTRC01);
   if (bLocalRdy_bVvtPrev == 0)
   {
      bLocalRdy_bVVT = 0;
      for (s32LocalDefIdx = 0;
           (  (s32LocalDefIdx < CLASRDY_VVT_NB_DFT)
           && (bLocalRdy_bVVT == 0));
           s32LocalDefIdx++)
      {
         u16LocalVVT = ClasRdyVVT_T[s32LocalDefIdx];
         if (u16LocalVVT != 0xFFFF)
         {
            if (u16LocalVVT == u16IdxDft)
            {
               bLocalRdy_bVVT = 1;
               GD_vidBitWrite16(Rdy_u16ClasRdy_EEPROM, VVTRC01, bLocalRdy_bVVT);
            }
         }
      }
   }
   Rdy_u16ClasRdy_EEPROM_prev = Rdy_u16ClasRdy_EEPROM;
   Rdy_u8ClasRdyLSB = (uint8)(Rdy_u16ClasRdy_EEPROM & 0x00FF);
   Rdy_u8ClasRdyMSB = (uint8)((Rdy_u16ClasRdy_EEPROM & 0xFF00)>>8);
}
/*--------------------------------- end of file ------------------------------*/