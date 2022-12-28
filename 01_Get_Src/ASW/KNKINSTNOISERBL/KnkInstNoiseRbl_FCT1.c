/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KnkInstNoiseRbl                                         */
/* !Description     : KnkInstNoiseRbl component.                              */
/*                                                                            */
/* !Module          : KnkInstNoiseRbl                                         */
/* !Description     : ENGINE INSTANTANEOUS NOISE ESTIMATION(RUMBLE)           */
/*                                                                            */
/* !File            : knkinstnoiserbl_fct1.c                                  */
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
/*   1 / KNKINSTNOISERBL_vidInitOutput                                        */
/*   2 / KNKINSTNOISERBL_vidKnkInstNoiRbl                                     */
/*   3 / KNKINSTNOISERBL_vidIfDiagOffRbl                                      */
/*   4 / KNKINSTNOISERBL_vidGainStatLdRbl                                     */
/*   5 / KNKINSTNOISERBL_vidCyl1KnkNoiFmt                                     */
/*   6 / KNKINSTNOISERBL_vidCyl2KnkNoiFmt                                     */
/*   7 / KNKINSTNOISERBL_vidCyl3KnkNoiFmt                                     */
/*   8 / KNKINSTNOISERBL_vidCyl4KnkNoiFmt                                     */
/*                                                                            */
/* !Reference   : V02 NT 10 02580 / 04                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
/*QAC Warning(2:0838): Std_Types.h is included in all files generated from
                                       temp.mde producing this kind of error  */
#include "KNKINSTNOISERBL.h"
#include "KNKINSTNOISERBL_L.h"
#include "KNKINSTNOISERBL_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKINSTNOISERBL_vidInitOutput                              */
/* !Description :  Output's initialization                                    */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 Bruit_instantane_rbl[16][4];                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKINSTNOISERBL_vidInitOutput(void)
{
   uint8 u8LocalIndexR;
   uint8 u8LocalIndexC;


   for (u8LocalIndexR=0;u8LocalIndexR<=15;u8LocalIndexR++)
   {
      for (u8LocalIndexC=0;u8LocalIndexC<=3;u8LocalIndexC++)
      {
         Bruit_instantane_rbl[u8LocalIndexR][u8LocalIndexC] = 0;
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKINSTNOISERBL_vidKnkInstNoiRbl                           */
/* !Description :  The instant noise is calculated on the clanking noise task.*/
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void KNKINSTNOISERBL_vidIfDiagOffRbl();                       */
/*  input uint8 KnkRbl_noCyl;                                                 */
/*  input boolean Knk_sens_diag_act_uavb0;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKINSTNOISERBL_vidKnkInstNoiRbl(void)
{
   boolean bLocalKnk_sens_diag_act_uavb0;
   uint8   u8LocalKnkRbl_noCyl;

   VEMS_vidGET(KnkRbl_noCyl, u8LocalKnkRbl_noCyl);
   VEMS_vidGET(Knk_sens_diag_act_uavb0, bLocalKnk_sens_diag_act_uavb0);
   if (  (u8LocalKnkRbl_noCyl <= 3)
      && (bLocalKnk_sens_diag_act_uavb0 == 0))
   {
      KNKINSTNOISERBL_vidIfDiagOffRbl();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKINSTNOISERBL_vidIfDiagOffRbl                            */
/* !Description :  Calculation of instantaneous noise for each cylinder.      */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  extf argret void KNKINSTNOISERBL_vidGainStatLdRbl();                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 KnkRbl_noCyl;                                                 */
/*  input uint16 Knk_rbl_noi_ad_gain_uavn1[4];                                */
/*  input uint16 Somme_clq_rbl_cyl[16][4];                                    */
/*  input uint8 Knk_rbl_noi_fmt_uavn0;                                        */
/*  output uint16 Bruit_instantane_rbl[16][4];                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKINSTNOISERBL_vidIfDiagOffRbl(void)
{
   uint8   u8LocalIndex;
   uint8   u8LocalKnkRbl_noCyl;
   uint16  u16LocalKnk_rbl_noiad_gain_uavn1;
   uint32  u32LocalTemp;


   VEMS_vidGET(KnkRbl_noCyl, u8LocalKnkRbl_noCyl);
   VEMS_vidGET1DArrayElement(Knk_rbl_noi_ad_gain_uavn1,
                             u8LocalKnkRbl_noCyl,
                             u16LocalKnk_rbl_noiad_gain_uavn1);
   KNKINSTNOISERBL_vidGainStatLdRbl();

   if(u8LocalKnkRbl_noCyl <= 3)
   {
      for (u8LocalIndex=0;u8LocalIndex<=15;u8LocalIndex++)
      {
         u32LocalTemp =
             (uint32)(Somme_clq_rbl_cyl[u8LocalIndex][u8LocalKnkRbl_noCyl]
                    * u16LocalKnk_rbl_noiad_gain_uavn1) / 256;

         u32LocalTemp = ((u32LocalTemp * Knk_rbl_noi_fmt_uavn0) + 800) / 1600;

         Bruit_instantane_rbl[u8LocalIndex][u8LocalKnkRbl_noCyl] =
            (uint16)MATHSRV_udtMIN(u32LocalTemp,65535);
      }
   }
   else
   {
      SWFAIL_vidSoftwareErrorHook();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKINSTNOISERBL_vidGainStatLdRbl                           */
/* !Description :  The mapping Knk_noi_fmt_map_cylx_uacn2 is evaluated once a */
/*                 pmh                                                        */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void KNKINSTNOISERBL_vidCyl1KnkNoiFmt();                      */
/*  extf argret void KNKINSTNOISERBL_vidCyl2KnkNoiFmt();                      */
/*  extf argret void KNKINSTNOISERBL_vidCyl3KnkNoiFmt();                      */
/*  extf argret void KNKINSTNOISERBL_vidCyl4KnkNoiFmt();                      */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 KnkRbl_noCyl;                                                 */
/*  input uint8 Knk_rbl_noi_fmt_cyl1_uavn0;                                   */
/*  input uint8 Knk_rbl_noi_fmt_cyl2_uavn0;                                   */
/*  input uint8 Knk_rbl_noi_fmt_cyl3_uavn0;                                   */
/*  input uint8 Knk_rbl_noi_fmt_cyl4_uavn0;                                   */
/*  output uint8 Knk_rbl_noi_fmt_uavn0;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKINSTNOISERBL_vidGainStatLdRbl(void)
{
   uint8 u8LocalKnkRbl_noCyl;


   VEMS_vidGET(KnkRbl_noCyl, u8LocalKnkRbl_noCyl);
   switch (u8LocalKnkRbl_noCyl)
   {
      case 0:
         KNKINSTNOISERBL_vidCyl1KnkNoiFmt();
         /* warning QAC:Msg(2:2215) Indentation is not consistent with
            configured depth.This warning 2215 is to ignore if VEMS
            indentation rule is respected*/
         Knk_rbl_noi_fmt_uavn0 = Knk_rbl_noi_fmt_cyl1_uavn0;
         break;
      case 1:
         KNKINSTNOISERBL_vidCyl2KnkNoiFmt();
         Knk_rbl_noi_fmt_uavn0 = Knk_rbl_noi_fmt_cyl2_uavn0;
         break;
      case 2:
         KNKINSTNOISERBL_vidCyl3KnkNoiFmt();
         Knk_rbl_noi_fmt_uavn0 = Knk_rbl_noi_fmt_cyl3_uavn0;
         break;
      case 3:
         KNKINSTNOISERBL_vidCyl4KnkNoiFmt();
         Knk_rbl_noi_fmt_uavn0 = Knk_rbl_noi_fmt_cyl4_uavn0;
         break;
      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKINSTNOISERBL_vidCyl1KnkNoiFmt                           */
/* !Description :  Static gain noise instant normalizing (cylinder 1 Physics) */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf MATHSRV_u16CalcParaIncAryU16(????);                                  */
/*  extf MATHSRV_u16CalcParaIncAryU8(????);                                   */
/*  extf MATHSRV_u8Interp2d(????);                                            */
/*  input uint16 Ext_rTotLd;                                                  */
/*  input uint16 Knk_rbl_noi_fmt_load_bkpt_uacn1[9];                          */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Knk_rbl_noi_fmt_n_bkpt_uacn1[9];                              */
/*  input uint8 Knk_rbl_noi_fmt_map_cyl1_uacn2[9][9];                         */
/*  output uint8 Knk_rbl_noi_fmt_cyl1_uavn0;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKINSTNOISERBL_vidCyl1KnkNoiFmt(void)
{
/*QAC Warning(2:4152): The name 'KnkDetRbl_vidCyl1_rbl' depends on the block
  in the specs that follows the naming rules                                  */

   uint8   u8LocalRegime_moteur_32;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   uint16  u16LocalExt_rTotLd;

   VEMS_vidGET(Ext_rTotLd, u16LocalExt_rTotLd);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(Knk_rbl_noi_fmt_load_bkpt_uacn1,
                                                u16LocalExt_rTotLd,
                                                9);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(Knk_rbl_noi_fmt_n_bkpt_uacn1,
                                               u8LocalRegime_moteur_32,
                                               9);
   Knk_rbl_noi_fmt_cyl1_uavn0 =
      MATHSRV_u8Interp2d(&Knk_rbl_noi_fmt_map_cyl1_uacn2[0][0],
                         u16LocalParaX,
                         u16LocalParaY,
                         9);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKINSTNOISERBL_vidCyl2KnkNoiFmt                           */
/* !Description :  Static gain noise instant normalizing (cylinder 2 Physics) */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf MATHSRV_u16CalcParaIncAryU16(????);                                  */
/*  extf MATHSRV_u16CalcParaIncAryU8(????);                                   */
/*  extf MATHSRV_u8Interp2d(????);                                            */
/*  input uint16 Ext_rTotLd;                                                  */
/*  input uint16 Knk_rbl_noi_fmt_load_bkpt_uacn1[9];                          */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Knk_rbl_noi_fmt_n_bkpt_uacn1[9];                              */
/*  input uint8 Knk_rbl_noi_fmt_map_cyl2_uacn2[9][9];                         */
/*  output uint8 Knk_rbl_noi_fmt_cyl2_uavn0;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKINSTNOISERBL_vidCyl2KnkNoiFmt(void)
{
   uint8   u8LocalRegime_moteur_32;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   uint16  u16LocalExt_rTotLd;

   VEMS_vidGET(Ext_rTotLd, u16LocalExt_rTotLd);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(Knk_rbl_noi_fmt_load_bkpt_uacn1,
                                                u16LocalExt_rTotLd,
                                                9);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(Knk_rbl_noi_fmt_n_bkpt_uacn1,
                                               u8LocalRegime_moteur_32,
                                               9);
   Knk_rbl_noi_fmt_cyl2_uavn0 =
      MATHSRV_u8Interp2d(&Knk_rbl_noi_fmt_map_cyl2_uacn2[0][0],
                         u16LocalParaX,
                         u16LocalParaY,
                         9);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKINSTNOISERBL_vidCyl3KnkNoiFmt                           */
/* !Description :  Static gain noise instant normalizing (cylinder 3 Physics) */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf MATHSRV_u16CalcParaIncAryU16(????);                                  */
/*  extf MATHSRV_u16CalcParaIncAryU8(????);                                   */
/*  extf MATHSRV_u8Interp2d(????);                                            */
/*  input uint16 Ext_rTotLd;                                                  */
/*  input uint16 Knk_rbl_noi_fmt_load_bkpt_uacn1[9];                          */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Knk_rbl_noi_fmt_n_bkpt_uacn1[9];                              */
/*  input uint8 Knk_rbl_noi_fmt_map_cyl3_uacn2[9][9];                         */
/*  output uint8 Knk_rbl_noi_fmt_cyl3_uavn0;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKINSTNOISERBL_vidCyl3KnkNoiFmt(void)
{
   uint8   u8LocalRegime_moteur_32;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   uint16  u16LocalExt_rTotLd;

   VEMS_vidGET(Ext_rTotLd, u16LocalExt_rTotLd);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(Knk_rbl_noi_fmt_load_bkpt_uacn1,
                                                u16LocalExt_rTotLd,
                                                9);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(Knk_rbl_noi_fmt_n_bkpt_uacn1,
                                               u8LocalRegime_moteur_32,
                                               9);
   Knk_rbl_noi_fmt_cyl3_uavn0 =
      MATHSRV_u8Interp2d(&Knk_rbl_noi_fmt_map_cyl3_uacn2[0][0],
                         u16LocalParaX,
                         u16LocalParaY,
                         9);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKINSTNOISERBL_vidCyl4KnkNoiFmt                           */
/* !Description :  Static gain noise instant normalizing (cylinder 4 Physics) */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf MATHSRV_u16CalcParaIncAryU16(????);                                  */
/*  extf MATHSRV_u16CalcParaIncAryU8(????);                                   */
/*  extf MATHSRV_u8Interp2d(????);                                            */
/*  input uint16 Ext_rTotLd;                                                  */
/*  input uint16 Knk_rbl_noi_fmt_load_bkpt_uacn1[9];                          */
/*  input uint8 Regime_moteur_32;                                             */
/*  input uint8 Knk_rbl_noi_fmt_n_bkpt_uacn1[9];                              */
/*  input uint8 Knk_rbl_noi_fmt_map_cyl4_uacn2[9][9];                         */
/*  output uint8 Knk_rbl_noi_fmt_cyl4_uavn0;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKINSTNOISERBL_vidCyl4KnkNoiFmt(void)
{
   uint8   u8LocalRegime_moteur_32;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   uint16  u16LocalExt_rTotLd;

   VEMS_vidGET(Ext_rTotLd, u16LocalExt_rTotLd);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(Knk_rbl_noi_fmt_load_bkpt_uacn1,
                                                u16LocalExt_rTotLd,
                                                9);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(Knk_rbl_noi_fmt_n_bkpt_uacn1,
                                               u8LocalRegime_moteur_32,
                                               9);
   Knk_rbl_noi_fmt_cyl4_uavn0 =
      MATHSRV_u8Interp2d(&Knk_rbl_noi_fmt_map_cyl4_uacn2[0][0],
                         u16LocalParaX,
                         u16LocalParaY,
                         9);
}
/*--------------------------------- end of file ------------------------------*/