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
/* !File            : MISFFAICTR_FCT5.C                                       */
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
/*   1 / MISFFAICTR_vidCataEmissPerCyl                                        */
/*   2 / MISFFAICTR_vidMfCyl_1_P2                                             */
/*   3 / MISFFAICTR_vidMfCyl_3_P2                                             */
/*   4 / MISFFAICTR_vidMfCyl_4_P2                                             */
/*   5 / MISFFAICTR_vidMfCyl_2_P2                                             */
/*   6 / MISFFAICTR_vidEmission                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_5069596 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFFAICTR/MISFFAICTR_FCT5.C_$*/
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
/* !Function    :  MISFFAICTR_vidCataEmissPerCyl                              */
/* !Description :  Cette fonction permet :  D’attribuer les dommages causés au*/
/*                 catalyseur par les misfires pour chaque cylindre.   De     */
/*                 compter pour chaque cylindre le nombre de misfires «       */
/*                 émission ».                                                */
/* !Number      :  FCT5.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFFAICTR_vidMfCyl_1_P2();                              */
/*  extf argret void MISFFAICTR_vidMfCyl_2_P2();                              */
/*  extf argret void MISFFAICTR_vidMfCyl_3_P2();                              */
/*  extf argret void MISFFAICTR_vidMfCyl_4_P2();                              */
/*  input boolean Mf_misfire_detected_uavb0;                                  */
/*  input boolean Mf_2_misfire_detected_uavb0;                                */
/*  input boolean MISFFAICTR_bMfMisfDetectedPrev;                             */
/*  input uint8 Misf_noCyl;                                                   */
/*  input uint8 Table_cyl_phys_misfire_detected[6];                           */
/*  input boolean Mf_1_mf_emiss_uavb0;                                        */
/*  input uint8 MISFFAICTR_u8MfCylEmisUavb0prev;                              */
/*  input boolean Mf_2_mf_emiss_uavb0;                                        */
/*  input uint8 Mf_cyl_emis_uavb0;                                            */
/*  input uint16 Mf_emiss_count_1_uavn0;                                      */
/*  input uint16 Mf_emiss_count_2_uavn0;                                      */
/*  input uint16 Mf_emiss_count_3_uavn0;                                      */
/*  input uint16 Mf_emiss_count_4_uavn0;                                      */
/*  output boolean Mf_2_mf_emiss_uavb0;                                       */
/*  output boolean Mf_1_mf_emiss_uavb0;                                       */
/*  output uint8 Mf_cyl_emis_uavb0;                                           */
/*  output uint16 Mf_emiss_count_cyl_uavn1[4];                                */
/*  output uint8 MISFFAICTR_u8MfCylEmisUavb0prev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidCataEmissPerCyl(void)
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
      Mf_2_mf_emiss_uavb0 = 1;
   }
   else
   {
      Mf_2_mf_emiss_uavb0 = 0;
   }
   if (  (MISFFAICTR_bMfMisfDetectedPrev == 0)
      && (bLocalMf_2_misf_detected_uavb0 != 0))
   {
      Mf_1_mf_emiss_uavb0 = 1;
   }
   else
   {
      Mf_1_mf_emiss_uavb0 = 0;
   }

   VEMS_vidGET(Misf_noCyl, u8LocalMisf_noCyl);
   u8LocalMisf_noCyl = (uint8)MATHSRV_udtMIN(u8LocalMisf_noCyl, 5);
   u8LocalResult = Table_cyl_phys_misfire_detected[u8LocalMisf_noCyl];
   Mf_cyl_emis_uavb0 = (uint8)MATHSRV_udtMIN(u8LocalResult, 6);

   if (  (  (Mf_1_mf_emiss_uavb0 != 0)
         && (MISFFAICTR_u8MfCylEmisUavb0prev == 1))
      || (  (Mf_2_mf_emiss_uavb0 != 0)
         && (Mf_cyl_emis_uavb0 == 1)))
   {
      MISFFAICTR_vidMfCyl_1_P2();
   }
   if (  (  (Mf_1_mf_emiss_uavb0 != 0)
         && (MISFFAICTR_u8MfCylEmisUavb0prev == 2))
      || (  (Mf_2_mf_emiss_uavb0 != 0)
         && (Mf_cyl_emis_uavb0 == 2)))
   {
      MISFFAICTR_vidMfCyl_2_P2();
   }
   if (  (  (Mf_1_mf_emiss_uavb0 != 0)
         && (MISFFAICTR_u8MfCylEmisUavb0prev == 3))
      || (  (Mf_2_mf_emiss_uavb0 != 0)
         && (Mf_cyl_emis_uavb0 == 3)))
   {
      MISFFAICTR_vidMfCyl_3_P2();
   }
   if (  (  (Mf_1_mf_emiss_uavb0 != 0)
         && (MISFFAICTR_u8MfCylEmisUavb0prev == 4))
      || (  (Mf_2_mf_emiss_uavb0 != 0)
         && (Mf_cyl_emis_uavb0 == 4)))
   {
      MISFFAICTR_vidMfCyl_4_P2();
   }

   Mf_emiss_count_cyl_uavn1[0] = Mf_emiss_count_1_uavn0;
   Mf_emiss_count_cyl_uavn1[1] = Mf_emiss_count_2_uavn0;
   Mf_emiss_count_cyl_uavn1[2] = Mf_emiss_count_3_uavn0;
   Mf_emiss_count_cyl_uavn1[3] = Mf_emiss_count_4_uavn0;

   MISFFAICTR_u8MfCylEmisUavb0prev = Mf_cyl_emis_uavb0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidMfCyl_1_P2                                   */
/* !Description :  Fonction permet de compter les dommages catalyseur du 1    */
/*                 cylindre.                                                  */
/* !Number      :  FCT5.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Mf_emiss_count_1_uavn0;                                      */
/*  output uint16 Mf_emiss_count_1_uavn0;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidMfCyl_1_P2(void)
{
   if (Mf_emiss_count_1_uavn0 < 65535)
   {
      Mf_emiss_count_1_uavn0 = (uint16)(Mf_emiss_count_1_uavn0 + 1);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidMfCyl_3_P2                                   */
/* !Description :  Fonction permet de compter les dommages catalyseur du 3    */
/*                 cylindre.                                                  */
/* !Number      :  FCT5.3                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Mf_emiss_count_3_uavn0;                                      */
/*  output uint16 Mf_emiss_count_3_uavn0;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidMfCyl_3_P2(void)
{
   if (Mf_emiss_count_3_uavn0 < 65535)
   {
      Mf_emiss_count_3_uavn0 = (uint16)(Mf_emiss_count_3_uavn0 + 1);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidMfCyl_4_P2                                   */
/* !Description :  Fonction permet de compter les dommages catalyseur du 4    */
/*                 cylindre.                                                  */
/* !Number      :  FCT5.4                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Mf_emiss_count_4_uavn0;                                      */
/*  output uint16 Mf_emiss_count_4_uavn0;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidMfCyl_4_P2(void)
{
   if (Mf_emiss_count_4_uavn0 < 65535)
   {
      Mf_emiss_count_4_uavn0 = (uint16)(Mf_emiss_count_4_uavn0 + 1);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidMfCyl_2_P2                                   */
/* !Description :  Fonction permet de compter les dommages catalyseur du 2    */
/*                 cylindre.                                                  */
/* !Number      :  FCT5.5                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Mf_emiss_count_2_uavn0;                                      */
/*  output uint16 Mf_emiss_count_2_uavn0;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidMfCyl_2_P2(void)
{
   if (Mf_emiss_count_2_uavn0 < 65535)
   {
      Mf_emiss_count_2_uavn0 = (uint16)(Mf_emiss_count_2_uavn0 + 1);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFFAICTR_vidEmission                                     */
/* !Description :  Cette fonction permet si la mauvaise route est détectée    */
/*                 Mf_rough_road_emiss_sum_uavn0 =                            */
/*                 Mf_rough_road_emiss_thresh_uacn0.                          */
/* !Number      :  FCT5.6                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFFAICTR_vidRoughRoadDetEmiss();                       */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void MISFFAICTR_vidRoughRdNoDetEmiss();                       */
/*  input uint8 Coupure_decel_progr_inj;                                      */
/*  input uint8 MISFFAICTR_u8CoupDecProgrInjprev;                             */
/*  input uint16 Mf_rough_road_emiss_sum_uavn0;                               */
/*  input uint16 Mf_rough_road_emiss_thresh_uacn0;                            */
/*  output uint8 Coup_decel_progr_inj_emiss;                                  */
/*  output boolean Mf_emiss_test_achi_uavb0;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFFAICTR_vidEmission(void)
{
   uint8 u8LocalCoupure_decel_progr_inj;
   uint8 u8LocalCoup_decel_progr_inj_emis;

   VEMS_vidGET(Coupure_decel_progr_inj, u8LocalCoupure_decel_progr_inj);
   u8LocalCoup_decel_progr_inj_emis =
      (uint8)( u8LocalCoupure_decel_progr_inj
             | MISFFAICTR_u8CoupDecProgrInjprev);
   Coup_decel_progr_inj_emiss =
      (uint8)MATHSRV_udtMIN(u8LocalCoup_decel_progr_inj_emis, 15);

   if (Mf_rough_road_emiss_sum_uavn0 >= Mf_rough_road_emiss_thresh_uacn0)
   {
      MISFFAICTR_vidRoughRoadDetEmiss();
      VEMS_vidSET(Mf_emiss_test_achi_uavb0, 0);
   }
   else
   {
      VEMS_vidSET(Mf_emiss_test_achi_uavb0, 1);
      MISFFAICTR_vidRoughRdNoDetEmiss();
   }
}
/*------------------------------end of file-----------------------------------*/