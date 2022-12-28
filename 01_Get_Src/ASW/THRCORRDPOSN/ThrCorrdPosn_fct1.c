/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRCORRDPOSN                                            */
/* !Description     : THRCORRDPOSN component.                                 */
/*                                                                            */
/* !Module          : THRCORRDPOSN                                            */
/* !Description     : Calcul de la position papillon corrigée                 */
/*                                                                            */
/* !File            : THRCORRDPOSN_FCT1.C                                     */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / THRCORRDPOSN_vidInitOutput                                           */
/*   2 / THRCORRDPOSN_vidThrottlePosCorr                                      */
/*                                                                            */
/* !Reference   : V02 NT 08 05172 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/THR/THRCORRDPOSN/ThrCorrdPosn_fct1$*/
/* $Revision::   1.2      $$Author::   ACHEBINO       $$Date::   30 Jun 2011 $*/
/* $Author::   ACHEBINO                               $$Date::   30 Jun 2011 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "THRCORRDPOSN.h"
#include "THRCORRDPOSN_L.h"
#include "THRCORRDPOSN_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRCORRDPOSN_vidInitOutput                                 */
/* !Description :  Initialisation des variables produites par le module.      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  C.HALOUANI                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Tpac_corrected_throttle_position;                           */
/*  output uint8 Corrected_throttle_position;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRCORRDPOSN_vidInitOutput(void)
{
   VEMS_vidSET(Tpac_corrected_throttle_position, 0);
   VEMS_vidSET(Corrected_throttle_position, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRCORRDPOSN_vidThrottlePosCorr                            */
/* !Description :  La position papillon corrigée est calculée à partir de la  */
/*                 position brute en retranchant la valeur de la butée basse. */
/*                 La butée est choisie selon le mode de fonctionnement de    */
/*                 l'acquisition. Celle-ci est utilisée pour le calcul des    */
/*                 gains de l'asservissement.                                 */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  C.HALOUANI                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Thr_FLrnClCtl_bAcv;                                         */
/*  input uint16 Ssm_raw_filt_throttle_position;                              */
/*  input uint16 Ssm_closed_throttle_pos;                                     */
/*  input boolean Thr_bEnaClThrPosnByp_C;                                     */
/*  input uint16 Thr_ClThrPosnBypInLrn_C;                                     */
/*  output uint16 Tpac_corrected_throttle_position;                           */
/*  output uint8 Corrected_throttle_position;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRCORRDPOSN_vidThrottlePosCorr(void)
{
   boolean bLocalThr_FLrnClCtl_bAcv;
   uint8   u8LocalCorrected_throttposition;
   uint16  u16LocalTpacorectedthrotposition;
   uint16  u16LocalSsmrawfitthrotle_posit;
   uint16  u16LocalSsm_closed_throttle_pos;
   sint32  s32Loc;


   VEMS_vidGET(Thr_FLrnClCtl_bAcv, bLocalThr_FLrnClCtl_bAcv);
   VEMS_vidGET(Ssm_raw_filt_throttle_position, u16LocalSsmrawfitthrotle_posit);
   VEMS_vidGET(Ssm_closed_throttle_pos, u16LocalSsm_closed_throttle_pos);


   if (  (bLocalThr_FLrnClCtl_bAcv != 0)
      && (Thr_bEnaClThrPosnByp_C != 0))
   {
      s32Loc = (sint32)( u16LocalSsmrawfitthrotle_posit
                       - Thr_ClThrPosnBypInLrn_C);
      u16LocalTpacorectedthrotposition = (uint16)MATHSRV_udtCLAMP(s32Loc,
                                                                  0,
                                                                  1023);
      s32Loc = (s32Loc / 4);
      u8LocalCorrected_throttposition = (uint8)MATHSRV_udtCLAMP(s32Loc,
                                                                0,
                                                                255);
   }
   else
   {
      s32Loc = (sint32)( u16LocalSsmrawfitthrotle_posit
                       - u16LocalSsm_closed_throttle_pos);
      u16LocalTpacorectedthrotposition = (uint16)MATHSRV_udtCLAMP(s32Loc,
                                                                  0,
                                                                  1023);
      s32Loc = (s32Loc / 4);
      u8LocalCorrected_throttposition = (uint8)MATHSRV_udtCLAMP(s32Loc,
                                                                0,
                                                                255);
   }
   VEMS_vidSET(Tpac_corrected_throttle_position,
               u16LocalTpacorectedthrotposition);
   VEMS_vidSET(Corrected_throttle_position, u8LocalCorrected_throttposition);
}
/*------------------------------- End of file --------------------------------*/