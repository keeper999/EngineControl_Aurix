/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFFAICTR                                              */
/* !Description     : MISFFAICTR component.                                   */
/*                                                                            */
/* !Module          : MISFFAICTR                                              */
/* !Description     : Comptage Des Misfires Pour Les Emissions De Polluants Et*/
/*                    La Protection Composants .                              */
/*                                                                            */
/* !File            : MISFFAICTR_FCT2.C                                       */
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
/*   1 / MISFFAICTR_vidCataDamagePerCyl                                       */
/*   2 / MISFFAICTR_vidMfCyl_1                                                */
/*   3 / MISFFAICTR_vidMfCyl_3                                                */
/*   4 / MISFFAICTR_vidMfCyl_4                                                */
/*   5 / MISFFAICTR_vidMfCyl_2                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_5069596 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFFAICTR/MISFFAICTR_FCT2.C_$*/
/* $Revision::   1.13     $$Author::   wbouach        $$Date::   19 Jun 2012 $*/
/* $Author::   wbouach                                $$Date::   19 Jun 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "MISFFAICTR.h"
#include "MISFFAICTR_L.h"
#include "MISFFAICTR_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidCataDamagePerCyl                             */
/* !Description :  Ce bloc permet :    D’attribuer les dommages causés au     */
/*                 catalyseur par les misfires pour chaque cylindre.   De     */
/*                 compter l’ensemble des misfires « destruction catalyseur » */
/*                 qui se sont produits sur l’ensemble des cylindres.         */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFFAICTR_vidMfCyl_1();                                 */
/*  extf argret void MISFFAICTR_vidMfCyl_2();                                 */
/*  extf argret void MISFFAICTR_vidMfCyl_3();                                 */
/*  extf argret void MISFFAICTR_vidMfCyl_4();                                 */
/*  input boolean Mf_misfire_detected_uavb0;                                  */
/*  input boolean Mf_2_misfire_detected_uavb0;                                */
/*  input boolean MISFFAICTR_bMfMisfDetectedPrev;                             */
/*  input uint8 Misf_noCyl;                                                   */
/*  input uint8 Table_cyl_phys_misfire_detected[6];                           */
/*  input boolean Mf_1_mf_cat_dam_uavb0;                                      */
/*  input uint8 MISFFAICTR_u8MfCylCatDamUavbprev;                             */
/*  input boolean Mf_2_mf_cat_dam_uavb0;                                      */
/*  input uint8 Mf_cyl_cat_dam_uavb0;                                         */
/*  input uint16 Mf_cat_dam_wght_count_1_uavn0;                               */
/*  input uint16 Mf_cat_dam_wght_count_2_uavn0;                               */
/*  input uint16 Mf_cat_dam_wght_count_3_uavn0;                               */
/*  input uint16 Mf_cat_dam_wght_count_4_uavn0;                               */
/*  output boolean Mf_2_mf_cat_dam_uavb0;                                     */
/*  output boolean Mf_1_mf_cat_dam_uavb0;                                     */
/*  output uint8 Mf_cyl_cat_dam_uavb0;                                        */
/*  output uint16 Mf_cat_dam_wght_count_cyl_uavn1[4];                         */
/*  output uint8 MISFFAICTR_u8MfCylCatDamUavbprev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidCataDamagePerCyl(void)
{
   boolean bLocalMf_2_misf_detected_uavb0;
   boolean bLocalMf_misfire_detected_uavb0;
   uint8   u8LocalMisf_noCyl;
   uint8   u8LocalResult;


   VEMS_vidGET(Mf_misfire_detected_uavb0, bLocalMf_misfire_detected_uavb0);
   VEMS_vidGET(Mf_2_misfire_detected_uavb0, bLocalMf_2_misf_detected_uavb0);
   if (  (bLocalMf_misfire_detected_uavb0 != 0)
      || (bLocalMf_2_misf_detected_uavb0 != 0))
   {
      Mf_2_mf_cat_dam_uavb0 = 1;
   }
   else
   {
      Mf_2_mf_cat_dam_uavb0 = 0;
   }
   if (  (MISFFAICTR_bMfMisfDetectedPrev == 0)
      && (bLocalMf_2_misf_detected_uavb0 != 0))
   {
      Mf_1_mf_cat_dam_uavb0 = 1;
   }
   else
   {
      Mf_1_mf_cat_dam_uavb0 = 0;
   }

   VEMS_vidGET(Misf_noCyl, u8LocalMisf_noCyl);
   u8LocalMisf_noCyl = (uint8)MATHSRV_udtMIN(u8LocalMisf_noCyl, 5);
   u8LocalResult = Table_cyl_phys_misfire_detected[u8LocalMisf_noCyl];
   Mf_cyl_cat_dam_uavb0 = (uint8)MATHSRV_udtMIN(u8LocalResult, 6);

   if (  (  (Mf_1_mf_cat_dam_uavb0 != 0)
         && (MISFFAICTR_u8MfCylCatDamUavbprev == 1))
      || (  (Mf_2_mf_cat_dam_uavb0 != 0)
         && (Mf_cyl_cat_dam_uavb0 == 1)))
   {
      MISFFAICTR_vidMfCyl_1();
   }

   if (  (  (Mf_1_mf_cat_dam_uavb0 != 0)
         && (MISFFAICTR_u8MfCylCatDamUavbprev == 2))
      || (  (Mf_2_mf_cat_dam_uavb0 != 0)
         && (Mf_cyl_cat_dam_uavb0 == 2)))
   {
      MISFFAICTR_vidMfCyl_2();
   }

   if (  (  (Mf_1_mf_cat_dam_uavb0 != 0)
         && (MISFFAICTR_u8MfCylCatDamUavbprev == 3))
      || (  (Mf_2_mf_cat_dam_uavb0 != 0)
         && (Mf_cyl_cat_dam_uavb0 == 3)))
   {
      MISFFAICTR_vidMfCyl_3();
   }

   if (  (  (Mf_1_mf_cat_dam_uavb0 != 0)
         && (MISFFAICTR_u8MfCylCatDamUavbprev == 4))
      || (  (Mf_2_mf_cat_dam_uavb0 != 0)
         && (Mf_cyl_cat_dam_uavb0 == 4)))
   {
      MISFFAICTR_vidMfCyl_4();
   }

   Mf_cat_dam_wght_count_cyl_uavn1[0] = Mf_cat_dam_wght_count_1_uavn0;
   Mf_cat_dam_wght_count_cyl_uavn1[1] = Mf_cat_dam_wght_count_2_uavn0;
   Mf_cat_dam_wght_count_cyl_uavn1[2] = Mf_cat_dam_wght_count_3_uavn0;
   Mf_cat_dam_wght_count_cyl_uavn1[3] = Mf_cat_dam_wght_count_4_uavn0;

   MISFFAICTR_u8MfCylCatDamUavbprev = Mf_cyl_cat_dam_uavb0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidMfCyl_1                                      */
/* !Description :  Fonction permet de compter les dommages catalyseur du 1    */
/*                 cylindre.                                                  */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 EngLim_tqIdcEngCur;                                          */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Cat_old_gain_obd;                                             */
/*  input uint16 Indicated_torque_3_bkpt_map[7];                              */
/*  input uint8 Regime_moteur_3_bkpt_map[16];                                 */
/*  input uint16 Mf_cat_dam_wght_old_map_uacn2[7][16];                        */
/*  input uint16 Mf_cat_dam_wght_map_uacn2[7][16];                            */
/*  input uint16 Mf_cat_dam_wght_count_1_uavn0;                               */
/*  input uint16 Mf_cat_dam_sum1_uavn0;                                       */
/*  output uint16 Mf_cat_dam_wght_count_1_uavn0;                              */
/*  output uint16 Mf_cat_dam_sum1_uavn0;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidMfCyl_1(void)
{
   uint8  u8LocalRegime_moteur_32;
   uint8  u8LocalCat_old_gain_obd;
   uint16 u16LocalDiff;
   uint16 u16LocalMISFFAICTRParaY;
   uint16 u16LocalMISFFAICTRParaX;
   uint16 u16LocalEngLimTqIdcEngCur;
   uint16 u16LocalMISFFAICTRMap1;
   uint16 u16LocalMISFFAICTRMap2;
   sint16 s16LocalEngLim_tqIdcEngCur;
   uint32 u32LocalMfCatDamSum1Uavn0;
   uint32 u32LocalAdd;
   sint32 s32LocalEngLimTqIdcEngCur;


   VEMS_vidGET(EngLim_tqIdcEngCur, s16LocalEngLim_tqIdcEngCur);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   VEMS_vidGET(Cat_old_gain_obd, u8LocalCat_old_gain_obd);
   s32LocalEngLimTqIdcEngCur = (sint32)(s16LocalEngLim_tqIdcEngCur + 32000);
   u16LocalEngLimTqIdcEngCur = (uint16)MATHSRV_udtMAX(s32LocalEngLimTqIdcEngCur,
                                                      0);
   u16LocalMISFFAICTRParaX =
      MATHSRV_u16CalcParaIncAryU16(Indicated_torque_3_bkpt_map,
                                   u16LocalEngLimTqIdcEngCur,
                                   7);
   u16LocalMISFFAICTRParaY =
      MATHSRV_u16CalcParaIncAryU8(Regime_moteur_3_bkpt_map,
                                  u8LocalRegime_moteur_32,
                                  16);
   u16LocalMISFFAICTRMap1 =
      MATHSRV_u16Interp2d(&Mf_cat_dam_wght_old_map_uacn2[0][0],
                          u16LocalMISFFAICTRParaX,
                          u16LocalMISFFAICTRParaY,
                          16);

   u16LocalMISFFAICTRMap2 =
      MATHSRV_u16Interp2d(&Mf_cat_dam_wght_map_uacn2[0][0],
                          u16LocalMISFFAICTRParaX,
                          u16LocalMISFFAICTRParaY,
                          16);

   u16LocalDiff = (uint16)(256 - u8LocalCat_old_gain_obd);
   u32LocalAdd = ( ( (uint32)(u16LocalMISFFAICTRMap2 * u8LocalCat_old_gain_obd)
                   + (uint32)(u16LocalDiff * u16LocalMISFFAICTRMap1)
                   + 128 )
                 / 256);

   u32LocalAdd = u32LocalAdd + Mf_cat_dam_wght_count_1_uavn0;
   Mf_cat_dam_wght_count_1_uavn0 = (uint16)MATHSRV_udtMIN(u32LocalAdd, 65535);

   u32LocalMfCatDamSum1Uavn0 = (uint32)(Mf_cat_dam_sum1_uavn0 + 1);

   Mf_cat_dam_sum1_uavn0 = (uint16)MATHSRV_udtMIN(u32LocalMfCatDamSum1Uavn0,
                                                  65535);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidMfCyl_3                                      */
/* !Description :  Fonction permet de compter les dommages catalyseur du 3    */
/*                 cylindre.                                                  */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 EngLim_tqIdcEngCur;                                          */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Cat_old_gain_obd;                                             */
/*  input uint16 Indicated_torque_3_bkpt_map[7];                              */
/*  input uint8 Regime_moteur_3_bkpt_map[16];                                 */
/*  input uint16 Mf_cat_dam_wght_old_map_uacn2[7][16];                        */
/*  input uint16 Mf_cat_dam_wght_map_uacn2[7][16];                            */
/*  input uint16 Mf_cat_dam_wght_count_3_uavn0;                               */
/*  input uint16 Mf_cat_dam_sum3_uavn0;                                       */
/*  output uint16 Mf_cat_dam_wght_count_3_uavn0;                              */
/*  output uint16 Mf_cat_dam_sum3_uavn0;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidMfCyl_3(void)
{
   uint8  u8LocalRegime_moteur_32;
   uint8  u8LocalCat_old_gain_obd;
   uint16 u16LocalDiff;
   uint16 u16LocalMISFFAICTRParaY;
   uint16 u16LocalMISFFAICTRParaX;
   uint16 u16LocalEngLimTqIdcEngCur;
   sint16 s16LocalEngLim_tqIdcEngCur;
   uint16 u16LocalMISFFAICTRMap1;
   uint16 u16LocalMISFFAICTRMap2;
   uint32 u32LocalMfCatDamSum3Uavn0;
   uint32 u32LocalAdd;
   sint32 s32LocalEngLimTqIdcEngCur;


   VEMS_vidGET(EngLim_tqIdcEngCur, s16LocalEngLim_tqIdcEngCur);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   VEMS_vidGET(Cat_old_gain_obd, u8LocalCat_old_gain_obd);
   s32LocalEngLimTqIdcEngCur = (sint32)(s16LocalEngLim_tqIdcEngCur + 32000);
   u16LocalEngLimTqIdcEngCur = (uint16)MATHSRV_udtMAX(s32LocalEngLimTqIdcEngCur,
                                                      0);
   u16LocalMISFFAICTRParaX =
      MATHSRV_u16CalcParaIncAryU16(Indicated_torque_3_bkpt_map,
                                   u16LocalEngLimTqIdcEngCur,
                                   7);
   u16LocalMISFFAICTRParaY =
      MATHSRV_u16CalcParaIncAryU8(Regime_moteur_3_bkpt_map,
                                  u8LocalRegime_moteur_32,
                                  16);
   u16LocalMISFFAICTRMap1 =
      MATHSRV_u16Interp2d(&Mf_cat_dam_wght_old_map_uacn2[0][0],
                          u16LocalMISFFAICTRParaX,
                          u16LocalMISFFAICTRParaY,
                          16);

   u16LocalMISFFAICTRMap2 =
      MATHSRV_u16Interp2d(&Mf_cat_dam_wght_map_uacn2[0][0],
                          u16LocalMISFFAICTRParaX,
                          u16LocalMISFFAICTRParaY,
                          16);

   u16LocalDiff = (uint16)(256 - u8LocalCat_old_gain_obd);
   u32LocalAdd = ( ( (uint32)(u16LocalMISFFAICTRMap2 * u8LocalCat_old_gain_obd)
                   + (uint32)(u16LocalDiff * u16LocalMISFFAICTRMap1)
                   + 128 )
                 / 256);

   u32LocalAdd = u32LocalAdd + Mf_cat_dam_wght_count_3_uavn0;
   Mf_cat_dam_wght_count_3_uavn0 = (uint16)MATHSRV_udtMIN(u32LocalAdd, 65535);

   u32LocalMfCatDamSum3Uavn0 = (uint32)(Mf_cat_dam_sum3_uavn0 + 1);
   Mf_cat_dam_sum3_uavn0 = (uint16)MATHSRV_udtMIN(u32LocalMfCatDamSum3Uavn0,
                                                  65535);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidMfCyl_4                                      */
/* !Description :  Fonction permet de compter les dommages catalyseur du 4    */
/*                 cylindre.                                                  */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 EngLim_tqIdcEngCur;                                          */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Cat_old_gain_obd;                                             */
/*  input uint16 Indicated_torque_3_bkpt_map[7];                              */
/*  input uint8 Regime_moteur_3_bkpt_map[16];                                 */
/*  input uint16 Mf_cat_dam_wght_old_map_uacn2[7][16];                        */
/*  input uint16 Mf_cat_dam_wght_map_uacn2[7][16];                            */
/*  input uint16 Mf_cat_dam_wght_count_4_uavn0;                               */
/*  input uint16 Mf_cat_dam_sum4_uavn0;                                       */
/*  output uint16 Mf_cat_dam_wght_count_4_uavn0;                              */
/*  output uint16 Mf_cat_dam_sum4_uavn0;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidMfCyl_4(void)
{
   uint8  u8LocalRegime_moteur_32;
   uint8  u8LocalCat_old_gain_obd;
   uint16 u16LocalDiff;
   uint16 u16LocalMISFFAICTRParaY;
   uint16 u16LocalMISFFAICTRParaX;
   uint16 u16LocalEngLimTqIdcEngCur;
   uint16 u16LocalMISFFAICTRMap1;
   uint16 u16LocalMISFFAICTRMap2;
   sint16 s16LocalEngLim_tqIdcEngCur;
   uint32 u32LocalMfCatDamSum4Uavn0;
   uint32 u32LocalAdd;
   sint32 s32LocalEngLimTqIdcEngCur;


   VEMS_vidGET(EngLim_tqIdcEngCur, s16LocalEngLim_tqIdcEngCur);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   VEMS_vidGET(Cat_old_gain_obd, u8LocalCat_old_gain_obd);
   s32LocalEngLimTqIdcEngCur = (sint32)(s16LocalEngLim_tqIdcEngCur + 32000);
   u16LocalEngLimTqIdcEngCur = (uint16)MATHSRV_udtMAX(s32LocalEngLimTqIdcEngCur,
                                                      0);
   u16LocalMISFFAICTRParaX =
      MATHSRV_u16CalcParaIncAryU16(Indicated_torque_3_bkpt_map,
                                   u16LocalEngLimTqIdcEngCur,
                                   7);
   u16LocalMISFFAICTRParaY =
      MATHSRV_u16CalcParaIncAryU8(Regime_moteur_3_bkpt_map,
                                  u8LocalRegime_moteur_32,
                                  16);
   u16LocalMISFFAICTRMap1 =
      MATHSRV_u16Interp2d(&Mf_cat_dam_wght_old_map_uacn2[0][0],
                          u16LocalMISFFAICTRParaX,
                          u16LocalMISFFAICTRParaY,
                          16);

   u16LocalMISFFAICTRMap2 =
      MATHSRV_u16Interp2d(&Mf_cat_dam_wght_map_uacn2[0][0],
                          u16LocalMISFFAICTRParaX,
                          u16LocalMISFFAICTRParaY,
                          16);

   u16LocalDiff = (uint16)(256 - u8LocalCat_old_gain_obd);
   u32LocalAdd = ( ( (uint32)(u16LocalMISFFAICTRMap2 * u8LocalCat_old_gain_obd)
                   + (uint32)(u16LocalDiff * u16LocalMISFFAICTRMap1)
                   + 128 )
                 / 256);

   u32LocalAdd = u32LocalAdd + Mf_cat_dam_wght_count_4_uavn0;
   Mf_cat_dam_wght_count_4_uavn0 = (uint16)MATHSRV_udtMIN(u32LocalAdd, 65535);

   u32LocalMfCatDamSum4Uavn0 = (uint32)(Mf_cat_dam_sum4_uavn0 + 1);
   Mf_cat_dam_sum4_uavn0 = (uint16)MATHSRV_udtMIN(u32LocalMfCatDamSum4Uavn0,
                                                  65535);

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidMfCyl_2                                      */
/* !Description :  Fonction permet de compter les dommages catalyseur du 2    */
/*                 cylindre.                                                  */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 EngLim_tqIdcEngCur;                                          */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Cat_old_gain_obd;                                             */
/*  input uint16 Indicated_torque_3_bkpt_map[7];                              */
/*  input uint8 Regime_moteur_3_bkpt_map[16];                                 */
/*  input uint16 Mf_cat_dam_wght_old_map_uacn2[7][16];                        */
/*  input uint16 Mf_cat_dam_wght_map_uacn2[7][16];                            */
/*  input uint16 Mf_cat_dam_wght_count_2_uavn0;                               */
/*  input uint16 Mf_cat_dam_sum2_uavn0;                                       */
/*  output uint16 Mf_cat_dam_wght_count_2_uavn0;                              */
/*  output uint16 Mf_cat_dam_sum2_uavn0;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidMfCyl_2(void)
{
   uint8  u8LocalRegime_moteur_32;
   uint16 u16LocalDiff;
   uint8  u8LocalCat_old_gain_obd;
   uint16 u16LocalMISFFAICTRParaY;
   uint16 u16LocalMISFFAICTRParaX;
   uint16 u16LocalEngLimTqIdcEngCur;
   uint16 u16LocalMISFFAICTRMap1;
   uint16 u16LocalMISFFAICTRMap2;
   sint16 s16LocalEngLim_tqIdcEngCur;
   uint32 u32LocalMfCatDamSum2Uavn0;
   uint32 u32LocalAdd;
   sint32 s32LocalEngLimTqIdcEngCur;


   VEMS_vidGET(EngLim_tqIdcEngCur, s16LocalEngLim_tqIdcEngCur);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   VEMS_vidGET(Cat_old_gain_obd, u8LocalCat_old_gain_obd);
   s32LocalEngLimTqIdcEngCur = (sint32)(s16LocalEngLim_tqIdcEngCur + 32000);
   u16LocalEngLimTqIdcEngCur = (uint16)MATHSRV_udtMAX(s32LocalEngLimTqIdcEngCur,
                                                      0);
   u16LocalMISFFAICTRParaX =
      MATHSRV_u16CalcParaIncAryU16(Indicated_torque_3_bkpt_map,
                                   u16LocalEngLimTqIdcEngCur,
                                   7);
   u16LocalMISFFAICTRParaY =
      MATHSRV_u16CalcParaIncAryU8(Regime_moteur_3_bkpt_map,
                                  u8LocalRegime_moteur_32,
                                  16);
   u16LocalMISFFAICTRMap1 =
      MATHSRV_u16Interp2d(&Mf_cat_dam_wght_old_map_uacn2[0][0],
                          u16LocalMISFFAICTRParaX,
                          u16LocalMISFFAICTRParaY,
                          16);

   u16LocalMISFFAICTRMap2 =
      MATHSRV_u16Interp2d(&Mf_cat_dam_wght_map_uacn2[0][0],
                          u16LocalMISFFAICTRParaX,
                          u16LocalMISFFAICTRParaY,
                          16);

   u16LocalDiff = (uint16)(256 - u8LocalCat_old_gain_obd);
   u32LocalAdd = ( ( (uint32)(u16LocalMISFFAICTRMap2 * u8LocalCat_old_gain_obd)
                   + (uint32)(u16LocalDiff * u16LocalMISFFAICTRMap1)
                   + 128 )
                 / 256);

   u32LocalAdd = u32LocalAdd + Mf_cat_dam_wght_count_2_uavn0;
   Mf_cat_dam_wght_count_2_uavn0 = (uint16)MATHSRV_udtMIN(u32LocalAdd, 65535);

   u32LocalMfCatDamSum2Uavn0 = (uint32)(Mf_cat_dam_sum2_uavn0 + 1);
   Mf_cat_dam_sum2_uavn0 = (uint16)MATHSRV_udtMIN(u32LocalMfCatDamSum2Uavn0,
                                                  65535);
}
/*------------------------------end of file-----------------------------------*/