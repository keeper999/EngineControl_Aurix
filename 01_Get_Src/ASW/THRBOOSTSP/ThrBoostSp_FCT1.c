/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRBOOSTSP                                              */
/* !Description     : THRBOOSTSP component.                                   */
/*                                                                            */
/* !Module          : THRBOOSTSP                                              */
/* !Description     : BOOST DE LA CONSIGNE DE POSITION PAPILLON MOTORISE      */
/*                                                                            */
/* !File            : THRBOOSTSP_FCT1.C                                       */
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
/*   1 / THRBOOSTSP_InitReset                                                 */
/*   2 / THRBOOSTSP_BoostSetPointStrategy                                     */
/*   3 / THRBOOSTSP_ActivationTest                                            */
/*   4 / THRBOOSTSP_NominalMode                                               */
/*   5 / THRBOOSTSP_BoostMode                                                 */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/THR/THRBOOSTSP/THRBOOSTSP_FCT1.C_v$*/
/* $Revision::   1.1      $$Author::   acabresp       $$Date::   20 Nov 2009 $*/
/* $Author::   acabresp                               $$Date::   20 Nov 2009 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "THRBOOSTSP.h"
#include "THRBOOSTSP_L.h"
#include "THRBOOSTSP_IM.h"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : La stratégie est inhibée au reset. Le booléen d’activation  */
/*                est ainsi initialisé à zéro et la consigne à celle de la    */
/*                structure couple.                                           */
/* !Number      : FCT1.1                                                      */
/* !Reference   : V02 NT 08 04489 / 2                                         */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*   extf VEMS_vidGET(argin, argio);                                          */
/*   extf VEMS_vidSET(argout, argio);                                         */
/*                                                                            */
/*   input uint16 Dtc_throttle_position_ref_raw;                              */
/*                                                                            */
/*   output boolean Dtc_throt_pos_ref_boost_enable;                           */
/*   output uint16 Dtc_position_ref_raw_prev;                                 */
/*   output uint16 Dtc_throttle_position_reference;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : M.MOALLA                                                    */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBOOSTSP_InitReset(void)
{
   uint16 u16LocalDtc_throttle_ref_raw;
   uint16 u16LocalDtc_throttle_reference;


   VEMS_vidGET(Dtc_throttle_position_ref_raw, u16LocalDtc_throttle_ref_raw);

   u16LocalDtc_throttle_reference =
      (uint16)MATHSRV_udtMIN(u16LocalDtc_throttle_ref_raw, 1024);
   Dtc_position_ref_raw_prev = u16LocalDtc_throttle_ref_raw;
   Dtc_throt_pos_ref_boost_enable = 0;

   VEMS_vidSET(Dtc_throttle_position_reference, u16LocalDtc_throttle_reference);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : La stratégie comporte 3 parties principales : (1) Test des  */
/*                conditions d’activation  (2) Application du boost  (3) Mode */
/*                nominal, c’est-à-dire, recopie de la consigne issue de la   */
/*                structure couple.                                           */
/* !Number      : FCT1.2                                                      */
/* !Reference   : V02 NT 08 04489 / 2                                         */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*   extf VEMS_vidGET(argin, argio);                                          */
/*   extf argret void THRBOOSTSP_ActivationTest();                            */
/*   extf argret void THRBOOSTSP_NominalMode();                               */
/*   extf argret void THRBOOSTSP_BoostMode();                                 */
/*   extf VEMS_vidSET(argout, argio);                                         */
/*                                                                            */
/*   input uint8 Dtc_throttle_position_min_limit;                             */
/*   input uint8 Dtc_throttle_position_max_limit;                             */
/*   input uint16 Dtc_throttle_position_ref_raw;                              */
/*   input uint16 Dtc_position_ref_raw_prev;                                  */
/*   input sint16 Dtc_throttle_pos_ref_raw_deriv;                             */
/*   input boolean Dtc_throt_pos_ref_boost_enable;                            */
/*   input uint16 Dtc_throt_pos_ref_boost_temp;                               */
/*                                                                            */
/*   output sint16 Dtc_throttle_pos_ref_raw_deriv;                            */
/*   output uint16 Dtc_throt_pos_ref_raw_abs_deriv;                           */
/*   output uint16 Dtc_position_ref_raw_prev;                                 */
/*   output uint16 Dtc_throttle_position_reference;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : M.MOALLA                                                    */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBOOSTSP_BoostSetPointStrategy(void)
{
   uint8  u8LocalDtc_throttle_min_limit;
   uint8  u8LocalDtc_throttle_max_limit;
   uint16 u16LocalDtc_throttle_ref_raw;
   uint16 u16LocalDtc_throttle_reference;
   uint16 u16LocalMin;
   uint16 u16LocalMax;
   sint16 s16LocalDeriv;
   sint32 s32LocalDeriv;


   VEMS_vidGET(Dtc_throttle_position_min_limit, u8LocalDtc_throttle_min_limit);
   VEMS_vidGET(Dtc_throttle_position_max_limit, u8LocalDtc_throttle_max_limit);
   VEMS_vidGET(Dtc_throttle_position_ref_raw, u16LocalDtc_throttle_ref_raw);

   s32LocalDeriv = (sint32)( u16LocalDtc_throttle_ref_raw
                           - Dtc_position_ref_raw_prev);
   s16LocalDeriv  = (sint16)(s32LocalDeriv / 2);
   Dtc_throttle_pos_ref_raw_deriv = (sint16)MATHSRV_udtCLAMP(s16LocalDeriv,
                                                             -511,
                                                             512);
   Dtc_throt_pos_ref_raw_abs_deriv = (uint16)MATHSRV_udtABS(s32LocalDeriv);

   THRBOOSTSP_ActivationTest();

   if (Dtc_throt_pos_ref_boost_enable == 0)
   {
      THRBOOSTSP_NominalMode();
   }
   else
   {
      THRBOOSTSP_BoostMode();
   }
   u16LocalMin = (uint16)(u8LocalDtc_throttle_min_limit * 4);
   u16LocalMax = (uint16)(u8LocalDtc_throttle_max_limit * 4);
   u16LocalDtc_throttle_reference =
      (uint16)MATHSRV_udtCLAMP(Dtc_throt_pos_ref_boost_temp,
                               u16LocalMin,
                               u16LocalMax);

   Dtc_position_ref_raw_prev = u16LocalDtc_throttle_ref_raw;
   VEMS_vidSET(Dtc_throttle_position_reference, u16LocalDtc_throttle_reference);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : Le boost n’est appliqué que si la variation de la consigne  */
/*                est supérieure à un seuil (Si elle est du même ordre de     */
/*                grandeur que la  précision du capteur, elle sera considérée */
/*                comme nulle).                                               */
/* !Number      : FCT1.3                                                      */
/* !Reference   : V02 NT 08 04489 / 2                                         */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*   extf VEMS_vidGET(argin, argio);                                          */
/*                                                                            */
/*   input uint16 Ssm_limp_home_throttle_pos;                                 */
/*   input uint16 Dtc_throttle_position_ref_raw;                              */
/*   input uint16 Dtc_max_distance_to_limp_home;                              */
/*   input uint16 Dtc_throt_pos_ref_raw_abs_deriv;                            */
/*   input uint16 Dtc_throttle_pos_ref_raw_max_var;                           */
/*   input uint16 Dtc_throttle_pos_ref_raw_min_var;                           */
/*   input boolean Dtc_throt_pos_ref_boost_manu_inh;                          */
/*                                                                            */
/*   output boolean Dtc_throt_pos_ref_boost_enable;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : M.MOALLA                                                    */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBOOSTSP_ActivationTest(void)
{
   uint16 u16LocalDtc_throttle_ref_raw;
   uint16 u16LocalSsm_limp_throttle_pos;


   VEMS_vidGET(Ssm_limp_home_throttle_pos, u16LocalSsm_limp_throttle_pos);
   VEMS_vidGET(Dtc_throttle_position_ref_raw, u16LocalDtc_throttle_ref_raw);

   if (  (u16LocalDtc_throttle_ref_raw <= ( u16LocalSsm_limp_throttle_pos
                                          + Dtc_max_distance_to_limp_home))
      && (Dtc_throt_pos_ref_raw_abs_deriv <= Dtc_throttle_pos_ref_raw_max_var)
      && (Dtc_throt_pos_ref_raw_abs_deriv > Dtc_throttle_pos_ref_raw_min_var)
      && (Dtc_throt_pos_ref_boost_manu_inh == 0))
   {
      Dtc_throt_pos_ref_boost_enable = 1;
   }
   else
   {
      Dtc_throt_pos_ref_boost_enable = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : Dans ce mode, la consigne issue de la structure couple est  */
/*                recopiée directement dans la consigne finale à  appliquer.  */
/* !Number      : FCT1.4                                                      */
/* !Reference   : V02 NT 08 04489 / 2                                         */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*   extf VEMS_vidGET(argin, argio);                                          */
/*                                                                            */
/*   input uint16 Dtc_throttle_position_ref_raw;                              */
/*                                                                            */
/*   output uint16 Dtc_throt_pos_ref_boost_temp;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : M.MOALLA                                                    */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBOOSTSP_NominalMode(void)
{
   uint16 u16LocalDtc_throttle_ref_raw;


   VEMS_vidGET(Dtc_throttle_position_ref_raw, u16LocalDtc_throttle_ref_raw);

   Dtc_throt_pos_ref_boost_temp =
      (uint16)MATHSRV_udtMIN(u16LocalDtc_throttle_ref_raw, 1024);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : Lorsque les conditions d’activation de boost sont remplies, */
/*                on ajoute à la consigne « brute » une valeur calculée  à    */
/*                partir de sa variation et d’un gain qui lui est relatif.    */
/* !Number      : FCT1.5                                                      */
/* !Reference   : V02 NT 08 04489 / 2                                         */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*   input uint16 Dtc_throttle_position_ref_raw;                              */
/*   input sint16 Dtc_throttle_pos_ref_raw_deriv;                             */
/*   input uint16 Dtc_throt_pos_ref_raw_bkpt[7];                              */
/*   input uint16 Dtc_throttle_pos_ref_raw_drv_uw;                            */
/*   input uint8 Dtc_throt_pos_ref_boost_gain_map[7];                         */
/*                                                                            */
/*   output uint16 Dtc_throttle_pos_ref_raw_drv_uw;                           */
/*   output uint16 Dtc_throt_pos_ref_boost_temp;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : M.MOALLA                                                    */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBOOSTSP_BoostMode(void)
{
   uint8  u8LocalBoostGain;
   uint16 u16LocalPara;
   uint16 u16LocalDtc_throttle_ref_raw;
   sint32 s32Local;


   VEMS_vidGET(Dtc_throttle_position_ref_raw, u16LocalDtc_throttle_ref_raw);

   if (Dtc_throttle_pos_ref_raw_deriv <= -511)
   {
      Dtc_throttle_pos_ref_raw_drv_uw = 0;
   }
   else
   {
      Dtc_throttle_pos_ref_raw_drv_uw = (uint16)( Dtc_throttle_pos_ref_raw_deriv
                                                + 511);
   }
   u16LocalPara = MATHSRV_u16CalcParaIncAryU16(Dtc_throt_pos_ref_raw_bkpt,
                                               Dtc_throttle_pos_ref_raw_drv_uw,
                                               7);
   u8LocalBoostGain = MATHSRV_u8Interp1d(Dtc_throt_pos_ref_boost_gain_map,
                                         u16LocalPara);
   s32Local = (sint32)( (u8LocalBoostGain * 200)
                      * Dtc_throttle_pos_ref_raw_deriv);
   s32Local = ((u16LocalDtc_throttle_ref_raw * 255) + s32Local) / 255;

   Dtc_throt_pos_ref_boost_temp = (uint16)MATHSRV_udtCLAMP(s32Local, 0, 1024);
}
/*-------------------------------- end of file -------------------------------*/