/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : AVRMISFCNT                                              */
/* !Description     : AVRMISFCNT component.                                   */
/*                                                                            */
/* !Module          : AVRMISFCNT                                              */
/* !Description     : MISFIRE COUNTER FOR OBD MODE$6                          */
/*                                                                            */
/* !File            : AVRMISFCNT_FCT1.C                                       */
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
/*   1 / AVRMISFCNT_vidInitOutput                                             */
/*   2 / AVRMISFCNT_vidInitCntMisf                                            */
/*   3 / AVRMISFCNT_vidRstEWMAMisfireMod4                                     */
/*   4 / AVRMISFCNT_vidReinit_Cnt_Misf                                        */
/*   5 / AVRMISFCNT_vidCntMisfPerCycleCyl                                     */
/*   6 / AVRMISFCNT_vidMisfDetectPerCyl                                       */
/*   7 / AVRMISFCNT_vidMisfCntCyl_1                                           */
/*   8 / AVRMISFCNT_vidMisfCntCyl_2                                           */
/*   9 / AVRMISFCNT_vidMisfCntCyl_3                                           */
/*   10 / AVRMISFCNT_vidMisfCntCyl_4                                          */
/*                                                                            */
/* !Reference   : V02 NT 11 05583 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/MISF/AVRMISFCNT/AVRMISFCNT_FCT1.$*/
/* $Revision::   1.1      $$Author::   etsasson       $$Date::   22 Feb 2012 $*/
/* $Author::   etsasson                               $$Date::   22 Feb 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "AVRMISFCNT.h"
#include "AVRMISFCNT_L.h"
#include "AVRMISFCNT_IM.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AVRMISFCNT_vidInitOutput                                   */
/* !Description :  Fonction d'initialisation des variables de sorties.        */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 MonMisf_ctOccurMfDCCyl1;                                    */
/*  output uint16 MonMisf_ctOccurMfDCCyl2;                                    */
/*  output uint16 MonMisf_ctOccurMfDCCyl3;                                    */
/*  output uint16 MonMisf_ctOccurMfDCCyl4;                                    */
/*  output uint16 MonMisf_ctOccurMfAvg10DCCyl1;                               */
/*  output uint16 MonMisf_ctOccurMfAvg10DCCyl2;                               */
/*  output uint16 MonMisf_ctOccurMfAvg10DCCyl3;                               */
/*  output uint16 MonMisf_ctOccurMfAvg10DCCyl4;                               */
/*  output boolean AVRMISFCNT_bMfMisfDetecUavb0Prev;                          */
/*  output uint8 AVRMISFCNT_u8MfNoCyMod6Uavb0Prev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AVRMISFCNT_vidInitOutput(void)
{
   VEMS_vidSET(MonMisf_ctOccurMfDCCyl1, 0);
   VEMS_vidSET(MonMisf_ctOccurMfDCCyl2, 0);
   VEMS_vidSET(MonMisf_ctOccurMfDCCyl3, 0);
   VEMS_vidSET(MonMisf_ctOccurMfDCCyl4, 0);
   VEMS_vidSET(MonMisf_ctOccurMfAvg10DCCyl1, 0);
   VEMS_vidSET(MonMisf_ctOccurMfAvg10DCCyl2, 0);
   VEMS_vidSET(MonMisf_ctOccurMfAvg10DCCyl3, 0);
   VEMS_vidSET(MonMisf_ctOccurMfAvg10DCCyl4, 0);
   AVRMISFCNT_bMfMisfDetecUavb0Prev = 0;
   AVRMISFCNT_u8MfNoCyMod6Uavb0Prev = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AVRMISFCNT_vidInitCntMisf                                  */
/* !Description :  Before starting the engine (ECU On but engine stalled), the*/
/*                 counter is set to the value saved in EEPROM.               */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 MonMisf_ctOccurMfDCCyl1_eep;                                 */
/*  input uint16 MonMisf_ctOccurMfDCCyl2_eep;                                 */
/*  input uint16 MonMisf_ctOccurMfDCCyl3_eep;                                 */
/*  input uint16 MonMisf_ctOccurMfDCCyl4_eep;                                 */
/*  output uint16 MonMisf_ctOccurMfDCCyl1_Raw;                                */
/*  output uint16 MonMisf_ctOccurMfDCCyl2_Raw;                                */
/*  output uint16 MonMisf_ctOccurMfDCCyl3_Raw;                                */
/*  output uint16 MonMisf_ctOccurMfDCCyl4_Raw;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AVRMISFCNT_vidInitCntMisf(void)
{
   uint16 u16LocalMonMisfOccurMfDCCyl_1;
   uint16 u16LocalMonMisfOccurMfDCCyl_2;
   uint16 u16LocalMonMisfOccurMfDCCyl_3;
   uint16 u16LocalMonMisfOccurMfDCCyl_4;


   VEMS_vidGET(MonMisf_ctOccurMfDCCyl1_eep, u16LocalMonMisfOccurMfDCCyl_1);
   VEMS_vidGET(MonMisf_ctOccurMfDCCyl2_eep, u16LocalMonMisfOccurMfDCCyl_2);
   VEMS_vidGET(MonMisf_ctOccurMfDCCyl3_eep, u16LocalMonMisfOccurMfDCCyl_3);
   VEMS_vidGET(MonMisf_ctOccurMfDCCyl4_eep, u16LocalMonMisfOccurMfDCCyl_4);

   MonMisf_ctOccurMfDCCyl1_Raw = u16LocalMonMisfOccurMfDCCyl_1;
   MonMisf_ctOccurMfDCCyl2_Raw = u16LocalMonMisfOccurMfDCCyl_2;
   MonMisf_ctOccurMfDCCyl3_Raw = u16LocalMonMisfOccurMfDCCyl_3;
   MonMisf_ctOccurMfDCCyl4_Raw = u16LocalMonMisfOccurMfDCCyl_4;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AVRMISFCNT_vidRstEWMAMisfireMod4                           */
/* !Description :   Default erase by “mode 04” sets the EWMA to 0.            */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 MonMisf_ctOccurMfAvg10DCCyl1;                               */
/*  output uint16 MonMisf_ctOccurMfAvg10DCCyl2;                               */
/*  output uint16 MonMisf_ctOccurMfAvg10DCCyl3;                               */
/*  output uint16 MonMisf_ctOccurMfAvg10DCCyl4;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AVRMISFCNT_vidRstEWMAMisfireMod4(void)
{
   VEMS_vidSET(MonMisf_ctOccurMfAvg10DCCyl1, 0);
   VEMS_vidSET(MonMisf_ctOccurMfAvg10DCCyl2, 0);
   VEMS_vidSET(MonMisf_ctOccurMfAvg10DCCyl3, 0);
   VEMS_vidSET(MonMisf_ctOccurMfAvg10DCCyl4, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AVRMISFCNT_vidReinit_Cnt_Misf                              */
/* !Description :   When a new driving cycle starts (CRANK To Run), the       */
/*                 counter is set to zero.                                    */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 MonMisf_ctOccurMfDCCyl1_Raw;                                */
/*  output uint16 MonMisf_ctOccurMfDCCyl2_Raw;                                */
/*  output uint16 MonMisf_ctOccurMfDCCyl3_Raw;                                */
/*  output uint16 MonMisf_ctOccurMfDCCyl4_Raw;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AVRMISFCNT_vidReinit_Cnt_Misf(void)
{
   MonMisf_ctOccurMfDCCyl1_Raw = 0;
   MonMisf_ctOccurMfDCCyl2_Raw = 0;
   MonMisf_ctOccurMfDCCyl3_Raw = 0;
   MonMisf_ctOccurMfDCCyl4_Raw = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AVRMISFCNT_vidCntMisfPerCycleCyl                           */
/* !Description :  In this function, for a duration of a driving cycle, the   */
/*                 number of occurred misfires corresponding to each cylinder */
/*                 is calculated.                                             */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void AVRMISFCNT_vidMisfDetectPerCyl();                        */
/*  extf argret void AVRMISFCNT_vidMisfCntCyl_1();                            */
/*  extf argret void AVRMISFCNT_vidMisfCntCyl_2();                            */
/*  extf argret void AVRMISFCNT_vidMisfCntCyl_3();                            */
/*  extf argret void AVRMISFCNT_vidMisfCntCyl_4();                            */
/*  input boolean Misf_bEnaMisfCntCyl1;                                       */
/*  input boolean Misf_bEnaMisfCntCyl2;                                       */
/*  input boolean Misf_bEnaMisfCntCyl3;                                       */
/*  input boolean Misf_bEnaMisfCntCyl4;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AVRMISFCNT_vidCntMisfPerCycleCyl(void)
{
   AVRMISFCNT_vidMisfDetectPerCyl();
   if (Misf_bEnaMisfCntCyl1 != 0)
   {
      AVRMISFCNT_vidMisfCntCyl_1();
   }
   if (Misf_bEnaMisfCntCyl2 != 0)
   {
      AVRMISFCNT_vidMisfCntCyl_2();
   }
   if (Misf_bEnaMisfCntCyl3 != 0)
   {
      AVRMISFCNT_vidMisfCntCyl_3();
   }
   if (Misf_bEnaMisfCntCyl4 != 0)
   {
      AVRMISFCNT_vidMisfCntCyl_4();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AVRMISFCNT_vidMisfDetectPerCyl                             */
/* !Description :  This function insures assignment of  detected misfire to   */
/*                 the corresponding cylinder in order to increment the       */
/*                 misfire counters.                                          */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Mf_misfire_detected_uavb0;                                  */
/*  input boolean Mf_2_misfire_detected_uavb0;                                */
/*  input boolean Ext_bDrvCyGlbl;                                             */
/*  input boolean Mf_rough_road_uavb0;                                        */
/*  input boolean AVRMISFCNT_bMfMisfDetecUavb0Prev;                           */
/*  input uint8 Misf_noCyl;                                                   */
/*  input uint8 Table_cyl_phys_misfire_detected[6];                           */
/*  input boolean Mf_2_mf_Mod6_uavb0;                                         */
/*  input uint8 Mf_no_cyl_mod6_uavb0;                                         */
/*  input boolean Mf_1_mf_Mod6_uavb0;                                         */
/*  input uint8 AVRMISFCNT_u8MfNoCyMod6Uavb0Prev;                             */
/*  output boolean Mf_2_mf_Mod6_uavb0;                                        */
/*  output boolean Mf_1_mf_Mod6_uavb0;                                        */
/*  output uint8 Mf_no_cyl_mod6_uavb0;                                        */
/*  output boolean Misf_bEnaMisfCntCyl1;                                      */
/*  output boolean Misf_bEnaMisfCntCyl2;                                      */
/*  output boolean Misf_bEnaMisfCntCyl3;                                      */
/*  output boolean Misf_bEnaMisfCntCyl4;                                      */
/*  output uint8 AVRMISFCNT_u8MfNoCyMod6Uavb0Prev;                            */
/*  output boolean AVRMISFCNT_bMfMisfDetecUavb0Prev;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AVRMISFCNT_vidMisfDetectPerCyl(void)
{
   boolean bLocalMf_misfire_detected_uavb0;
   boolean bLocalMf_2misfire_detected_uavb0;
   boolean bLocalExt_bDrvCyGlbl;
   boolean bLocalMf_rough_road_uavb0;
   uint8   u8LocalMfCylMod6Uavb0;
   uint8   u8LocalMisf_noCyl;


   VEMS_vidGET(Mf_misfire_detected_uavb0, bLocalMf_misfire_detected_uavb0);
   VEMS_vidGET(Mf_2_misfire_detected_uavb0, bLocalMf_2misfire_detected_uavb0);
   VEMS_vidGET(Ext_bDrvCyGlbl, bLocalExt_bDrvCyGlbl);
   VEMS_vidGET(Mf_rough_road_uavb0, bLocalMf_rough_road_uavb0);

   if (  (bLocalExt_bDrvCyGlbl == 0)
      || (bLocalMf_rough_road_uavb0 != 0))
   {
      Mf_2_mf_Mod6_uavb0 = 0;
      Mf_1_mf_Mod6_uavb0 = 0;
   }
   else
   {
      if (  (bLocalMf_misfire_detected_uavb0 != 0)
         || (bLocalMf_2misfire_detected_uavb0 != 0))
      {
         Mf_2_mf_Mod6_uavb0 = 1;
      }
      else
      {
         Mf_2_mf_Mod6_uavb0 = 0;
      }
      if (  (AVRMISFCNT_bMfMisfDetecUavb0Prev == 0)
         && (bLocalMf_2misfire_detected_uavb0 != 0))
      {
         Mf_1_mf_Mod6_uavb0 = 1;
      }
      else
      {
         Mf_1_mf_Mod6_uavb0 = 0;
      }
   }

   VEMS_vidGET(Misf_noCyl, u8LocalMisf_noCyl);
   u8LocalMisf_noCyl = (uint8)MATHSRV_udtMIN(u8LocalMisf_noCyl, 5);
   u8LocalMfCylMod6Uavb0 = Table_cyl_phys_misfire_detected[u8LocalMisf_noCyl];
   Mf_no_cyl_mod6_uavb0 = (uint8)MATHSRV_udtCLAMP(u8LocalMfCylMod6Uavb0, 1, 6);

   if (  (  (Mf_2_mf_Mod6_uavb0 != 0)
         && (Mf_no_cyl_mod6_uavb0 == 1))
      || (  (Mf_1_mf_Mod6_uavb0 != 0)
         && (AVRMISFCNT_u8MfNoCyMod6Uavb0Prev == 1)))
   {
      Misf_bEnaMisfCntCyl1 = 1;
   }
   else
   {
      Misf_bEnaMisfCntCyl1 = 0;
   }

   if (  (  (Mf_2_mf_Mod6_uavb0 != 0)
         && (Mf_no_cyl_mod6_uavb0 == 2))
      || (  (Mf_1_mf_Mod6_uavb0 != 0)
         && (AVRMISFCNT_u8MfNoCyMod6Uavb0Prev == 2)))
   {
      Misf_bEnaMisfCntCyl2 = 1;
   }
   else
   {
      Misf_bEnaMisfCntCyl2 = 0;
   }

   if (  (  (Mf_2_mf_Mod6_uavb0 != 0)
         && (Mf_no_cyl_mod6_uavb0 == 3))
      || (  (Mf_1_mf_Mod6_uavb0 != 0)
         && (AVRMISFCNT_u8MfNoCyMod6Uavb0Prev == 3)))
   {
      Misf_bEnaMisfCntCyl3 = 1;
   }
   else
   {
      Misf_bEnaMisfCntCyl3 = 0;
   }

   if (  (  (Mf_2_mf_Mod6_uavb0 != 0)
         && (Mf_no_cyl_mod6_uavb0 == 4))
      || (  (Mf_1_mf_Mod6_uavb0 != 0)
         && (AVRMISFCNT_u8MfNoCyMod6Uavb0Prev == 4)))
   {
      Misf_bEnaMisfCntCyl4 = 1;
   }
   else
   {
      Misf_bEnaMisfCntCyl4 = 0;
   }
   AVRMISFCNT_u8MfNoCyMod6Uavb0Prev = Mf_no_cyl_mod6_uavb0;
   AVRMISFCNT_bMfMisfDetecUavb0Prev = bLocalMf_misfire_detected_uavb0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AVRMISFCNT_vidMisfCntCyl_1                                 */
/* !Description :  The number of occurred misfires during the current driving */
/*                 cycle is calculated for the cylinder 1.                    */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 MonMisf_ctOccurMfDCCyl1_Raw;                                 */
/*  output uint16 MonMisf_ctOccurMfDCCyl1_Raw;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AVRMISFCNT_vidMisfCntCyl_1(void)
{
   if (MonMisf_ctOccurMfDCCyl1_Raw < 65535)
   {
      MonMisf_ctOccurMfDCCyl1_Raw = (uint16)(MonMisf_ctOccurMfDCCyl1_Raw + 1);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AVRMISFCNT_vidMisfCntCyl_2                                 */
/* !Description :  The number of occurred misfires during the current driving */
/*                 cycle is calculated for the cylinder 2.                    */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 MonMisf_ctOccurMfDCCyl2_Raw;                                 */
/*  output uint16 MonMisf_ctOccurMfDCCyl2_Raw;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AVRMISFCNT_vidMisfCntCyl_2(void)
{
   if (MonMisf_ctOccurMfDCCyl2_Raw < 65535)
   {
      MonMisf_ctOccurMfDCCyl2_Raw = (uint16)(MonMisf_ctOccurMfDCCyl2_Raw + 1);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AVRMISFCNT_vidMisfCntCyl_3                                 */
/* !Description :  The number of occurred misfires during the current driving */
/*                 cycle is calculated for the cylinder 3.                    */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 MonMisf_ctOccurMfDCCyl3_Raw;                                 */
/*  output uint16 MonMisf_ctOccurMfDCCyl3_Raw;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AVRMISFCNT_vidMisfCntCyl_3(void)
{
   if (MonMisf_ctOccurMfDCCyl3_Raw < 65535)
   {
      MonMisf_ctOccurMfDCCyl3_Raw = (uint16)(MonMisf_ctOccurMfDCCyl3_Raw + 1);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AVRMISFCNT_vidMisfCntCyl_4                                 */
/* !Description :  The number of occurred misfires during the current driving */
/*                 cycle is calculated for the cylinder 4.                    */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 MonMisf_ctOccurMfDCCyl4_Raw;                                 */
/*  output uint16 MonMisf_ctOccurMfDCCyl4_Raw;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AVRMISFCNT_vidMisfCntCyl_4(void)
{
   if (MonMisf_ctOccurMfDCCyl4_Raw < 65535)
   {
      MonMisf_ctOccurMfDCCyl4_Raw = (uint16)(MonMisf_ctOccurMfDCCyl4_Raw + 1);
   }
}
/*------------------------------- end of file --------------------------------*/