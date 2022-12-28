/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTEXIF                                              */
/* !Description     : VLVACTEXIF component                                    */
/*                                                                            */
/* !Module          : VLVACTEXIF                                              */
/* !Description     : INTERFACE D’ADAPTATION DES CONSIGNE ET MESURE AAC POUR  */
/*                    LA FONCTION VVT ECHAPPEMENT                             */
/*                                                                            */
/* !File            : VLVACTEXIF_FCT1.C                                       */
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
/*   1 / VLVACTEXIF_vidInitOutput                                             */
/*   2 / VLVACTEXIF_vidInitialisation                                         */
/*   3 / VLVACTEXIF_vidVVTToothErrDet                                         */
/*   4 / VLVACTEXIF_vidCmOfsCmp                                               */
/*   5 / VLVACTEXIF_vidVlvActCmToothOfs                                       */
/*   6 / VLVACTEXIF_vidVlvActOfsCmp                                           */
/*   7 / VLVACTEXIF_vidVVTPosition                                            */
/*   8 / VLVACTEXIF_vidVVTSetpoint                                            */
/*   9 / VLVACTEXIF_vidCalcSatSetpoint                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_5320145 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTEX/VLVACTEXIF/VLVACTEXIF_F$*/
/* $Revision::   1.8      $$Author::   mbenfrad       $$Date::   19 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   19 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VLVACTEXIF.h"
#include "VLVACTEXIF_L.h"
#include "VLVACTEXIF_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXIF_vidInitOutput                                   */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidSET1DArrayElement(argout, argout, argio);                    */
/*  output uint16 Vxx_vvtc_ex_angl_sp;                                        */
/*  output boolean VlvAct_bExSpFuncIntlHiOutIdc;                              */
/*  output boolean VlvAct_bExSpFuncIntlLoOutIdc;                              */
/*  output sint8 VlvAct_agCkClsExVlvReqRef0;                                  */
/*  output boolean VlvAct_bCmdExServoLocLop;                                  */
/*  output uint16 VLVACTEXIF_u16SlewRateOut;                                  */
/*  output boolean VLVACTEXIF_bTimerInputPrev;                                */
/*  output uint8 VLVACTEXIF_u8TimerCount;                                     */
/*  output boolean VlvAct_bExSpFuncIntlHiOutIdcInt;                           */
/*  output boolean VlvAct_bExSpFuncIntlLoOutIdcInt;                           */
/*  output boolean VLVACTEXIF_bLihPosTimerOut;                                */
/*  output uint16 VlvAct_prm_agCkClsExVlvMax[4];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXIF_vidInitOutput(void)
{
   uint8 u8LocalIdx;


   VEMS_vidSET(Vxx_vvtc_ex_angl_sp, 0);
   VEMS_vidSET(VlvAct_bExSpFuncIntlHiOutIdc, 0);
   VEMS_vidSET(VlvAct_bExSpFuncIntlLoOutIdc, 0);
   VEMS_vidSET(VlvAct_agCkClsExVlvReqRef0, 0);
   VEMS_vidSET(VlvAct_bCmdExServoLocLop, 0);
   VLVACTEXIF_u16SlewRateOut = 0;
   VLVACTEXIF_bTimerInputPrev = 0;
   VLVACTEXIF_u8TimerCount = 0;
   VlvAct_bExSpFuncIntlHiOutIdcInt = 0;
   VlvAct_bExSpFuncIntlLoOutIdcInt = 0;
   VLVACTEXIF_bLihPosTimerOut = 0;
   for (u8LocalIdx = 0;
        u8LocalIdx < VLVACT_PRM_AGCKCLSEXVLVMAX_COLS;
        u8LocalIdx++)
   {
      VEMS_vidSET1DArrayElement(VlvAct_prm_agCkClsExVlvMax, u8LocalIdx, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXIF_vidInitialisation                               */
/* !Description :  initialisations des sorties.                               */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  input sint16 Ext_agCkClsExVlvEstimRef0_C;                                 */
/*  input sint8 VlvAct_agCkClsExVlvReqRef0Max_C;                              */
/*  input sint8 VlvAct_agCkClsExVlvReqRef0Min_C;                              */
/*  input uint16 Vta_exhaust_reference_angle[4];                              */
/*  output sint16 Ext_agCkClsExVlvEstimRef0;                                  */
/*  output sint8 VlvAct_agCkClsExVlvReqRef0Max;                               */
/*  output sint8 VlvAct_agCkClsExVlvReqRef0Max_C;                             */
/*  output sint8 VlvAct_agCkClsExVlvReqRef0Min;                               */
/*  output sint8 VlvAct_agCkClsExVlvReqRef0Min_C;                             */
/*  output uint16 VlvAct_prm_agCkClsExVlvBol[4];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXIF_vidInitialisation(void)
{
   uint8    u8LocalCounter;
   uint16   u16LocalCkClsExVlvBol[VCPE_CAM_OFFSETS_COLS];
   sint16   s16LocalExt_agCkClsExVlvEstimRef;
   uint32   u32LocalVta_exhaust_reference[VCPE_CAM_OFFSETS_COLS];


   s16LocalExt_agCkClsExVlvEstimRef =
      (sint16)MATHSRV_udtCLAMP(Ext_agCkClsExVlvEstimRef0_C, -1024, 1023);
   VEMS_vidSET(Ext_agCkClsExVlvEstimRef0, s16LocalExt_agCkClsExVlvEstimRef);
   VEMS_vidSET(VlvAct_agCkClsExVlvReqRef0Max, VlvAct_agCkClsExVlvReqRef0Max_C);
   VEMS_vidSET(VlvAct_agCkClsExVlvReqRef0Min, VlvAct_agCkClsExVlvReqRef0Min_C);
   for (u8LocalCounter = 0; u8LocalCounter < 4; u8LocalCounter++)
   {
      u32LocalVta_exhaust_reference[u8LocalCounter] =
         (Vta_exhaust_reference_angle[u8LocalCounter] * 3) / 2;
      u16LocalCkClsExVlvBol[u8LocalCounter] =
         (uint16)MATHSRV_udtMIN(u32LocalVta_exhaust_reference[u8LocalCounter],
                                11520);
   }
   VEMS_vidSET1DArray(VlvAct_prm_agCkClsExVlvBol, 4, u16LocalCkClsExVlvBol);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXIF_vidVVTToothErrDet                               */
/* !Description :  Le calcul des erreurs de géométrie ainsi que des offsets de*/
/*                 décalage de montage de la cible et de l’actionneur VVT est */
/*                 effectué après chaque apprentissage des butées de repos.   */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTEXIF_vidCmOfsCmp();                                */
/*  input boolean Vcpe_cam_offsets_are_learned;                               */
/*  input boolean VLVACTEXIF_bVcpeCamOffsetLndPrev;                           */
/*  output boolean VLVACTEXIF_bVcpeCamOffsetLndPrev;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXIF_vidVVTToothErrDet(void)
{
   boolean bLocalVcpe_cam_offsets_are_learn;


   VEMS_vidGET(Vcpe_cam_offsets_are_learned, bLocalVcpe_cam_offsets_are_learn);
   if (  (bLocalVcpe_cam_offsets_are_learn != 0)
      && (VLVACTEXIF_bVcpeCamOffsetLndPrev == 0))
   {
      VLVACTEXIF_vidCmOfsCmp();
   }
   VLVACTEXIF_bVcpeCamOffsetLndPrev = bLocalVcpe_cam_offsets_are_learn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXIF_vidCmOfsCmp                                     */
/* !Description :  Le calcul du décalage de montage de l’ensemble cible AAC + */
/*                 actionneur VVT est déterminé lorsque l’ensemble des dents  */
/*                 de la cible AAC sont décalés dans le même sens par rapport */
/*                 à leur position théorique dans le référentiel moteur.      */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf argret void VLVACTEXIF_vidVlvActCmToothOfs();                        */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Vcpe_cam_offsets[4];                                         */
/*  input uint16 Vta_exhaust_reference_angle[4];                              */
/*  input uint8 Vta_exhaust_tooth_nb;                                         */
/*  input sint16 VlvAct_agCkExCmVlvActOfs;                                    */
/*  input sint16 VlvAct_agCkExCmToothOfs;                                     */
/*  output sint16 VlvAct_agCkExCmOfs;                                         */
/*  output sint16 VlvAct_agCkExCmToothErr[4];                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXIF_vidCmOfsCmp(void)
{
   uint8  u8LocalCounter;
   uint16 u16LocalVcpe_cam_offsets[VCPE_CAM_OFFSETS_COLS];
   /*qac warning due to the use of VEMS_vidGET1DArray macro*/
   sint16 s16LocalVlvAct_agCkExCmVlvActOfs;
   sint32 s32LocalCamOffsetsDiff[VCPE_CAM_OFFSETS_COLS];
   sint32 s32LocalMin;
   sint32 s32LocalVlvActAgCkExCmToothErr;


   VEMS_vidGET1DArray(Vcpe_cam_offsets,
                      VCPE_CAM_OFFSETS_COLS,
                      u16LocalVcpe_cam_offsets);

   for(u8LocalCounter = 0;
       u8LocalCounter < VCPE_CAM_OFFSETS_COLS;
       u8LocalCounter++)
   {
      s32LocalCamOffsetsDiff[u8LocalCounter] =
         (sint32)( u16LocalVcpe_cam_offsets[u8LocalCounter]
                 - Vta_exhaust_reference_angle[u8LocalCounter]);
   }

   if (Vta_exhaust_tooth_nb == 2)
   {
      if (  (  (s32LocalCamOffsetsDiff[0] > 0)
            && (s32LocalCamOffsetsDiff[1] > 0)
            && (s32LocalCamOffsetsDiff[2] > 0)))
      {
         s32LocalMin = MATHSRV_udtMIN(s32LocalCamOffsetsDiff[0],
                                      s32LocalCamOffsetsDiff[1]);
         s32LocalMin = MATHSRV_udtMIN(s32LocalMin, s32LocalCamOffsetsDiff[2]);

         VlvAct_agCkExCmOfs = (sint16)MATHSRV_udtMIN(s32LocalMin, 1023);
      }
      else
      {
         if (  (s32LocalCamOffsetsDiff[0] <= 0)
            && (s32LocalCamOffsetsDiff[1] <= 0)
            && (s32LocalCamOffsetsDiff[2] <= 0))
         {
            s32LocalMin = MATHSRV_udtMAX(s32LocalCamOffsetsDiff[0],
                                         s32LocalCamOffsetsDiff[1]);
            s32LocalMin =
               MATHSRV_udtMAX(s32LocalMin, s32LocalCamOffsetsDiff[2]);

            VlvAct_agCkExCmOfs = (sint16)MATHSRV_udtMAX(s32LocalMin, -1024);
         }
         else
         {
            VlvAct_agCkExCmOfs = 0;
         }
      }
   }
   else
   {
      if (  (  (s32LocalCamOffsetsDiff[0] > 0)
            && (s32LocalCamOffsetsDiff[1] > 0)
            && (s32LocalCamOffsetsDiff[2] > 0)
            && (s32LocalCamOffsetsDiff[3] > 0)))
      {
         s32LocalMin = MATHSRV_udtMIN(s32LocalCamOffsetsDiff[0],
                                      s32LocalCamOffsetsDiff[1]);
         s32LocalMin = MATHSRV_udtMIN(s32LocalMin, s32LocalCamOffsetsDiff[2]);
         s32LocalMin = MATHSRV_udtMIN(s32LocalMin, s32LocalCamOffsetsDiff[3]);

         VlvAct_agCkExCmOfs = (sint16)MATHSRV_udtMIN(s32LocalMin, 1023);
      }
      else
      {
         if (  (s32LocalCamOffsetsDiff[0] <= 0)
            && (s32LocalCamOffsetsDiff[1] <= 0)
            && (s32LocalCamOffsetsDiff[2] <= 0)
            && (s32LocalCamOffsetsDiff[3] <= 0))
         {
            s32LocalMin = MATHSRV_udtMAX(s32LocalCamOffsetsDiff[0],
                                         s32LocalCamOffsetsDiff[1]);
            s32LocalMin =
               MATHSRV_udtMAX(s32LocalMin, s32LocalCamOffsetsDiff[2]);
            s32LocalMin =
               MATHSRV_udtMAX(s32LocalMin, s32LocalCamOffsetsDiff[3]);

            VlvAct_agCkExCmOfs = (sint16)MATHSRV_udtMAX(s32LocalMin, -1024);
         }
         else
         {
            VlvAct_agCkExCmOfs = 0;
         }
      }
   }

   VLVACTEXIF_vidVlvActCmToothOfs();
   VEMS_vidGET(VlvAct_agCkExCmVlvActOfs, s16LocalVlvAct_agCkExCmVlvActOfs);
   for(u8LocalCounter = 0;
       u8LocalCounter < VCPE_CAM_OFFSETS_COLS;
       u8LocalCounter++)
   {
      s32LocalVlvActAgCkExCmToothErr = ( (s32LocalCamOffsetsDiff[u8LocalCounter]
                                         - s16LocalVlvAct_agCkExCmVlvActOfs)
                                       - (sint32)VlvAct_agCkExCmToothOfs);

      VlvAct_agCkExCmToothErr[u8LocalCounter] =
         (sint16)MATHSRV_udtCLAMP(s32LocalVlvActAgCkExCmToothErr,
                                  -1024,
                                  1023);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXIF_vidVlvActCmToothOfs                             */
/* !Description :  Calcul du parametre VlvAct_agCkExCmToothOfs                */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXIF_vidVlvActOfsCmp();                            */
/*  input boolean VlvAct_bExCmVlvActOfsEna_C;                                 */
/*  input sint16 VlvAct_agCkExCmOfs;                                          */
/*  output sint16 VlvAct_agCkExCmToothOfs;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXIF_vidVlvActCmToothOfs(void)
{
   if (VlvAct_bExCmVlvActOfsEna_C != 0)
   {
      VLVACTEXIF_vidVlvActOfsCmp();
   }
   else
   {
      VlvAct_agCkExCmToothOfs =
         (sint16)MATHSRV_udtCLAMP(VlvAct_agCkExCmOfs, -1024, 1023);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXIF_vidVlvActOfsCmp                                 */
/* !Description :  Lorsqu’il est activé, ce bloc permet d’estimer le décalage */
/*                 de montage de l’actionneur VVT à partir de l’offset de     */
/*                 décalage constaté pour l’ensemble cible AAC + actionneur   */
/*                 VVT                                                        */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 VlvAct_agCkExCmOfs;                                          */
/*  input sint16 VlvAct_agCkExCmToothOfsMax_C;                                */
/*  output sint16 VlvAct_agCkExCmVlvActOfs;                                   */
/*  output sint16 VlvAct_agCkExCmToothOfs;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXIF_vidVlvActOfsCmp(void)
{
   uint16 u16LocalVlvAct_agCkExCmOfs;
   sint16 s16LocalVlvActAgCkExCmVlvActOfs;
   sint16 s16LocalVlvActAgCkExCmToothOfs;
   sint32 s32LocalVlvActAgCkExCmVlvActOfs;
   sint32 s32LocalVlvActAgCkExCmToothOfs;


   u16LocalVlvAct_agCkExCmOfs = (uint16)MATHSRV_udtABS(VlvAct_agCkExCmOfs);

   if (u16LocalVlvAct_agCkExCmOfs <= VlvAct_agCkExCmToothOfsMax_C)
   {
      s32LocalVlvActAgCkExCmVlvActOfs = 0;
   }
   else
   {
      if (VlvAct_agCkExCmOfs < 0)
      {
         s32LocalVlvActAgCkExCmVlvActOfs =
            (sint32)(VlvAct_agCkExCmOfs + VlvAct_agCkExCmToothOfsMax_C);
      }
      else
      {
         if (VlvAct_agCkExCmOfs > 0)
         {
            s32LocalVlvActAgCkExCmVlvActOfs =
               (sint32)( u16LocalVlvAct_agCkExCmOfs
                       - VlvAct_agCkExCmToothOfsMax_C);
         }
         else
         {
            s32LocalVlvActAgCkExCmVlvActOfs = 0;
         }
      }
   }

   s16LocalVlvActAgCkExCmVlvActOfs =
      (sint16)MATHSRV_udtCLAMP(s32LocalVlvActAgCkExCmVlvActOfs, -1024, 1023);

   s32LocalVlvActAgCkExCmToothOfs =
      (VlvAct_agCkExCmOfs - s16LocalVlvActAgCkExCmVlvActOfs);

   s16LocalVlvActAgCkExCmToothOfs =
      (sint16)MATHSRV_udtCLAMP(s32LocalVlvActAgCkExCmToothOfs, -1024, 1023);

   VEMS_vidSET(VlvAct_agCkExCmVlvActOfs, s16LocalVlvActAgCkExCmVlvActOfs);
   VlvAct_agCkExCmToothOfs = s16LocalVlvActAgCkExCmToothOfs;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXIF_vidVVTPosition                                  */
/* !Description :  La position réelle de fermeture des soupapes d’échappement */
/*                 dans le référentiel moteur est calculée à partir de la     */
/*                 valeur estimée du décalage d’AAC, issue de la loi de       */
/*                 commande VVT échappement.                                  */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_08_06205_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16Channel);              */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 VlvAct_agCkExCmVlvActOfs;                                    */
/*  input uint16 VlvAct_agCmExPosnEstim;                                      */
/*  input sint16 VlvAct_agCkExCmRefOfs_C;                                     */
/*  input boolean VLVACTEXIF_bTimerInputPrev;                                 */
/*  input uint8 VlvAct_tiExLihPosDly_C;                                       */
/*  input uint8 VLVACTEXIF_u8TimerCount;                                      */
/*  input boolean VLVACTEXIF_bLihPosTimerOut;                                 */
/*  input boolean VlvAct_bExSelDefPos_C;                                      */
/*  input uint16 VlvAct_agExLihPos_C;                                         */
/*  output uint8 VLVACTEXIF_u8TimerCount;                                     */
/*  output boolean VLVACTEXIF_bLihPosTimerOut;                                */
/*  output boolean VLVACTEXIF_bTimerInputPrev;                                */
/*  output sint16 Ext_agCkClsExVlvEstimRef0;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXIF_vidVVTPosition(void)
{
   boolean bLocalAcvVlvActExInIfLihPosCalc;
   uint16  u16LocalVlvAct_agCmExPosnEstim;
   sint16  s16LocalExtAgCkOpExVlvEstimRef0;
   sint16  s16LocalVlvActAgCkExCmVlvActOfs;
   sint32  s32LocalExtAgCkOpExVlvEstimRef0;

   VEMS_vidGET(VlvAct_agCkExCmVlvActOfs, s16LocalVlvActAgCkExCmVlvActOfs);
   VEMS_vidGET(VlvAct_agCmExPosnEstim, u16LocalVlvAct_agCmExPosnEstim);
   s32LocalExtAgCkOpExVlvEstimRef0 = (sint32)( s16LocalVlvActAgCkExCmVlvActOfs
                                             + VlvAct_agCkExCmRefOfs_C);
   bLocalAcvVlvActExInIfLihPosCalc =
      GDGAR_bGetFRM(FRM_FRM_ACVVLVACTEXINIFLIHPOSCALC);
   if (  (bLocalAcvVlvActExInIfLihPosCalc != 0)
      && (VLVACTEXIF_bTimerInputPrev == 0))
   {
      VLVACTEXIF_u8TimerCount = VlvAct_tiExLihPosDly_C;
      if (VLVACTEXIF_u8TimerCount == 0)
      {
         VLVACTEXIF_bLihPosTimerOut = 1;
      }
      else
      {
         VLVACTEXIF_bLihPosTimerOut = 0;
      }
   }
   else
   {
      if (VLVACTEXIF_u8TimerCount > 0)
      {
         VLVACTEXIF_u8TimerCount = (uint8)(VLVACTEXIF_u8TimerCount - 1);
         if (VLVACTEXIF_u8TimerCount == 0)
         {
            VLVACTEXIF_bLihPosTimerOut = 1;
         }
         else
         {
            VLVACTEXIF_bLihPosTimerOut = 0;
         }
      }
   }
   VLVACTEXIF_bTimerInputPrev = bLocalAcvVlvActExInIfLihPosCalc;
   if (  (bLocalAcvVlvActExInIfLihPosCalc != 0)
      && (VLVACTEXIF_bLihPosTimerOut != 0))
   {
      if (VlvAct_bExSelDefPos_C == 0)
      {
         s32LocalExtAgCkOpExVlvEstimRef0 = s32LocalExtAgCkOpExVlvEstimRef0
                                         + VlvAct_agExLihPos_C;
      }
   }
   else
   {
      s32LocalExtAgCkOpExVlvEstimRef0 = s32LocalExtAgCkOpExVlvEstimRef0
                                      + u16LocalVlvAct_agCmExPosnEstim;
   }
   s16LocalExtAgCkOpExVlvEstimRef0 =
      (sint16)MATHSRV_udtCLAMP(s32LocalExtAgCkOpExVlvEstimRef0, -1024, 1023);

   VEMS_vidSET(Ext_agCkClsExVlvEstimRef0, s16LocalExtAgCkOpExVlvEstimRef0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXIF_vidVVTSetpoint                                  */
/* !Description :  La consigne de décalage AAC échappement, utilisée par la   */
/*                 loi de commande VVT échappement est calculée à  partir de  */
/*                 la consigne en position de fermeture des soupapes à        */
/*                 l’échappement dans le référentiel moteur.                  */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_E_08_06205_007.01                                     */
/*                 VEMS_R_08_06205_001.02                                     */
/*                 VEMS_R_08_06205_005.01                                     */
/*                 VEMS_R_08_06205_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf VEMS_vidSET1DArray(argout, argout, argio);                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void VLVACTEXIF_vidCalcSatSetpoint();                         */
/*  input boolean VlvAct_bExVlvSpBenchModEna;                                 */
/*  input uint16 VlvAct_agCkExVlvSpBenchMod;                                  */
/*  input uint8 VlvSys_agCkClsExVlvCorRaw;                                    */
/*  input uint16 VlvAct_agExActrTestPosSp;                                    */
/*  input boolean Srv_bActrTstExVVTEna;                                       */
/*  input sint16 VlvAct_agCkExCmVlvActOfs;                                    */
/*  input uint16 Vcpe_cam_offsets[4];                                         */
/*  input sint16 VlvAct_agCkExCmSpMax_C;                                      */
/*  input uint8 VlvAct_agExMaxSlopVlvSpPos_C;                                 */
/*  input uint8 VlvAct_agExMinSlopVlvSpPos_C;                                 */
/*  input uint16 VLVACTEXIF_u16SlewRateOut;                                   */
/*  input uint16 Vxx_vvtc_ex_angl_sp_cal;                                     */
/*  input boolean Vxx_vvtc_ex_angl_test_bed;                                  */
/*  input sint16 VlvAct_agCkExCmRefOfs_C;                                     */
/*  input uint16 VlvAct_agExSpFuncIntlThd_C;                                  */
/*  input uint16 VlvAct_agExSpFuncIntlThdHysInf_C;                            */
/*  input uint16 VlvAct_agExSpFuncIntlThdHys_C;                               */
/*  input uint16 VlvAct_agExSpFuncIntlThdLo_C;                                */
/*  input uint16 VlvAct_agExSpFuncIntlThdLoHys_C;                             */
/*  input uint16 VlvAct_agExSpFuncIntlThdHi_C;                                */
/*  input uint16 VlvAct_agExSpFuncIntlThdHiHys_C;                             */
/*  input uint16 VlvAct_agExSpFuncIntlThdMax_C;                               */
/*  input uint16 VlvAct_agExSpFuncIntlThdMaxHys_C;                            */
/*  input uint16 VlvAct_agExSpFuncIntThdMaxHys1_C;                            */
/*  input boolean VlvAct_bExSpFuncIntlHiOutIdcInt;                            */
/*  input boolean VlvAct_bExSpFuncIntlHiOutIdc;                               */
/*  input boolean VlvAct_bExSpFuncIntlLoOutIdcInt;                            */
/*  input boolean VlvAct_bExSpFuncIntlLoOutIdc;                               */
/*  input sint16 VlvAct_agCkExCmSpMin_C;                                      */
/*  input uint16 Vxx_vvtc_ex_angl_sp_Int;                                     */
/*  input uint16 VlvAct_agExSpFuncIntlThdHi;                                  */
/*  input boolean VlvAct_bAcvExServo;                                         */
/*  output uint16 VlvAct_prm_agCkClsExVlvBol[4];                              */
/*  output uint16 VlvAct_prm_agCkClsExVlvMax[4];                              */
/*  output uint16 VLVACTEXIF_u16SlewRateOut;                                  */
/*  output uint16 Vxx_vvtc_ex_angl_sp_Int;                                    */
/*  output boolean VlvAct_bExSpFuncIntlLoOutIdc;                              */
/*  output boolean VlvAct_bExSpFuncIntlLoOutIdcInt;                           */
/*  output boolean VlvAct_bExSpFuncIntlHiOutIdcInt;                           */
/*  output boolean VlvAct_bExSpFuncIntlHiOutIdc;                              */
/*  output uint16 Vxx_vvtc_ex_angl_sp;                                        */
/*  output uint16 VlvAct_agExSpFuncIntlThdHi;                                 */
/*  output uint16 VlvAct_agExSpFuncIntlThdLo;                                 */
/*  output sint8 VlvAct_agCkClsExVlvReqRef0;                                  */
/*  output boolean VlvAct_bCmdExServoLocLop;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXIF_vidVVTSetpoint(void)
{
   boolean bLocalSrv_bActrTstExVVTEna;
   boolean bLocalVlvAct_bExSpFuncIntlLo;
   boolean bLocalVlvAct_bExSpFuncIntlHi;
   boolean bLocalVlvAct_bExVlvSpBenchModEna;
   boolean bLocalVlvActbExSpFuncIntlHi;
   boolean bLocalVlvActbExSpFuncIntlLo;
   boolean bLocalVlvAct_bAcvExServo;
   uint8   u8LocalVlvSys_agCkClsExVlvCorRaw;
   uint8   u8LocalCounter;
   uint16  u16LocalMax;
   uint16  u16LocalMin;
   uint16  u16LocalVxx_vvtc_ex_angl_sp1;
   uint16  u16LocalVlvAct_agExActrTestPosSp;
   uint16  u16LocalVcpe_cam_offsets[VCPE_CAM_OFFSETS_COLS];
   /* !QAC Warning, Msg(2:3204) due to the use of VEMS_vidGET1DArray macro*/
   uint16  u16LocalVlvAct_agCkExVlvBenchMod;
   uint16  u16LocalVlvActprmagCkClsExVlvMax[VLVACT_PRM_AGCKCLSEXVLVMAX_COLS];
   uint16  u16LocalVlvActagCkClsExVlvBol[VLVACT_PRM_AGCKCLSEXVLVBOL_COLS];
   uint16  u16LocalSlewRateOut;
   sint16  s16LocalVlvAct_agCkExCmVlvActOfs;
   uint32  u32LocalCamOffsets[VCPE_CAM_OFFSETS_COLS];
   sint8   s8LocalVlvAct_agCkClsExVlvRqRf0;
   sint32  s32LocalVxx_vvtc_ex_angl_sp;
   sint32  s32LocalVlvagExSpFuncIntlThdHi;
   sint32  s32LocalHyst1High;
   sint32  s32LocalHyst1Low;
   sint32  s32LocalLocalVvtcExAnglSp;
   sint32  s32LocalCamOffsets[VCPE_CAM_OFFSETS_COLS];
   sint32  s32LocalCalc1;
   sint32  s32LocalVlvAct_agCkClsExVlvRqRf0;


   VEMS_vidGET(VlvAct_bExVlvSpBenchModEna, bLocalVlvAct_bExVlvSpBenchModEna);
   VEMS_vidGET(VlvAct_agCkExVlvSpBenchMod, u16LocalVlvAct_agCkExVlvBenchMod);
   VEMS_vidGET(VlvSys_agCkClsExVlvCorRaw, u8LocalVlvSys_agCkClsExVlvCorRaw);
   VEMS_vidGET(VlvAct_agExActrTestPosSp, u16LocalVlvAct_agExActrTestPosSp);
   VEMS_vidGET(Srv_bActrTstExVVTEna, bLocalSrv_bActrTstExVVTEna);
   VEMS_vidGET(VlvAct_agCkExCmVlvActOfs, s16LocalVlvAct_agCkExCmVlvActOfs);
   VEMS_vidGET1DArray(Vcpe_cam_offsets,
                      VCPE_CAM_OFFSETS_COLS,
                      u16LocalVcpe_cam_offsets);

   for (u8LocalCounter = 0;
        u8LocalCounter < VCPE_CAM_OFFSETS_COLS;
        u8LocalCounter++)
   {
      u32LocalCamOffsets[u8LocalCounter] =
         (u16LocalVcpe_cam_offsets[u8LocalCounter] * 3) / 2;
      u16LocalVlvActagCkClsExVlvBol[u8LocalCounter] =
         (uint16)MATHSRV_udtMIN(u32LocalCamOffsets[u8LocalCounter], 11520);

      s32LocalCamOffsets[u8LocalCounter] =
         (sint32)( ( ( u16LocalVcpe_cam_offsets[u8LocalCounter]
                     + VlvAct_agCkExCmSpMax_C) * 3) / 2);
      s32LocalCamOffsets[u8LocalCounter] =
         MATHSRV_udtMAX(s32LocalCamOffsets[u8LocalCounter], -11520);
      u16LocalVlvActprmagCkClsExVlvMax[u8LocalCounter] =
            (uint16)( (s32LocalCamOffsets[u8LocalCounter] + 11520) % 11520);
   }
   VEMS_vidSET1DArray(VlvAct_prm_agCkClsExVlvBol,
                      VLVACT_PRM_AGCKCLSEXVLVBOL_COLS,
                      u16LocalVlvActagCkClsExVlvBol);
   VEMS_vidSET1DArray(VlvAct_prm_agCkClsExVlvMax,
                      VLVACT_PRM_AGCKCLSEXVLVMAX_COLS,
                      u16LocalVlvActprmagCkClsExVlvMax);
   u16LocalMax = (uint16)(((VlvAct_agExMaxSlopVlvSpPos_C * 25) + 3) / 6);
   u16LocalMin = (uint16)(((VlvAct_agExMinSlopVlvSpPos_C * 25) + 3) / 6);
   u16LocalSlewRateOut = MATHSRV_u16SlewFilter(VLVACTEXIF_u16SlewRateOut,
                                               Vxx_vvtc_ex_angl_sp_cal,
                                               u16LocalMax,
                                               u16LocalMin);
   VLVACTEXIF_u16SlewRateOut = (uint16)MATHSRV_udtMIN(u16LocalSlewRateOut,
                                                      1066);
   if (bLocalVlvAct_bExVlvSpBenchModEna != 0)
   {
      s32LocalLocalVvtcExAnglSp = (sint32)u16LocalVlvAct_agCkExVlvBenchMod;
   }
   else
   {
      if (Vxx_vvtc_ex_angl_test_bed != 0)
      {
         s32LocalLocalVvtcExAnglSp = (sint32)VLVACTEXIF_u16SlewRateOut;
      }
      else
      {
         if (bLocalSrv_bActrTstExVVTEna != 0)
         {
            s32LocalLocalVvtcExAnglSp =
               (sint32)u16LocalVlvAct_agExActrTestPosSp;
         }
         else
         {
            s32LocalLocalVvtcExAnglSp =
            (sint32)( ( ( 8 * u8LocalVlvSys_agCkClsExVlvCorRaw)
                      - s16LocalVlvAct_agCkExCmVlvActOfs)
                    - 1024
                    - VlvAct_agCkExCmRefOfs_C);
         }
      }
   }
   Vxx_vvtc_ex_angl_sp_Int =
      (uint16)MATHSRV_udtCLAMP(s32LocalLocalVvtcExAnglSp, 0, 1066);

   /*SCHMITT_TRIGGER_1*/
   s32LocalHyst1Low = (sint32)( VlvAct_agExSpFuncIntlThd_C
                              - VlvAct_agExSpFuncIntlThdHysInf_C);
   s32LocalHyst1High = (sint32)( VlvAct_agExSpFuncIntlThd_C
                               + VlvAct_agExSpFuncIntlThdHys_C);
   if (s32LocalLocalVvtcExAnglSp > s32LocalHyst1High)
   {
      VEMS_vidSET(VlvAct_bExSpFuncIntlLoOutIdc, 0);
   }
   else
   {
      if (s32LocalLocalVvtcExAnglSp <= s32LocalHyst1Low)
      {
         VEMS_vidSET(VlvAct_bExSpFuncIntlLoOutIdc, 1);
      }
   }
   /*SCHMITT_TRIGGER_2*/
   s32LocalHyst1High = (sint32)( VlvAct_agExSpFuncIntlThdLo_C
                               + VlvAct_agExSpFuncIntlThdLoHys_C);
   if (s32LocalLocalVvtcExAnglSp > s32LocalHyst1High)
   {
      VlvAct_bExSpFuncIntlLoOutIdcInt = 0;
   }
   else
   {
      if (s32LocalLocalVvtcExAnglSp <= VlvAct_agExSpFuncIntlThdLo_C)
      {
         VlvAct_bExSpFuncIntlLoOutIdcInt = 1;
      }
   }
   /*SCHMITT_TRIGGER_3*/
   s32LocalHyst1Low = (sint32)( VlvAct_agExSpFuncIntlThdHi_C
                              - VlvAct_agExSpFuncIntlThdHiHys_C);
   if (s32LocalLocalVvtcExAnglSp > VlvAct_agExSpFuncIntlThdHi_C)
   {
      VlvAct_bExSpFuncIntlHiOutIdcInt = 1;
   }
   else
   {
      if (s32LocalLocalVvtcExAnglSp <= s32LocalHyst1Low)
      {
         VlvAct_bExSpFuncIntlHiOutIdcInt = 0;
      }
   }
   /*SCHMITT_TRIGGER_4*/
   s32LocalHyst1Low = (sint32)( VlvAct_agExSpFuncIntlThdMax_C
                              - VlvAct_agExSpFuncIntlThdMaxHys_C);
   s32LocalHyst1High = (sint32)( VlvAct_agExSpFuncIntlThdMax_C
                               + VlvAct_agExSpFuncIntThdMaxHys1_C);
   if (s32LocalLocalVvtcExAnglSp > s32LocalHyst1High)
   {
      VEMS_vidSET(VlvAct_bExSpFuncIntlHiOutIdc, 1);
   }
   else
   {
      if (s32LocalLocalVvtcExAnglSp <= s32LocalHyst1Low)
      {
         VEMS_vidSET(VlvAct_bExSpFuncIntlHiOutIdc, 0);
      }
   }
   /*Production of Vxx_vvtc_ex_angl_sp*/
   if (VlvAct_bExSpFuncIntlHiOutIdcInt != 0)
   {
      VEMS_vidGET(VlvAct_bExSpFuncIntlHiOutIdc, bLocalVlvActbExSpFuncIntlHi);
      if (bLocalVlvActbExSpFuncIntlHi != 0)
      {
         s32LocalVxx_vvtc_ex_angl_sp = VlvAct_agCkExCmSpMax_C;
      }
      else
      {
         s32LocalVxx_vvtc_ex_angl_sp = (sint32)VlvAct_agExSpFuncIntlThdHi_C;
      }
   }
   else
   {
      if (VlvAct_bExSpFuncIntlLoOutIdcInt != 0)
      {
         VEMS_vidGET(VlvAct_bExSpFuncIntlLoOutIdc, bLocalVlvActbExSpFuncIntlLo);
         if (bLocalVlvActbExSpFuncIntlLo != 0)
         {
            s32LocalVxx_vvtc_ex_angl_sp = VlvAct_agCkExCmSpMin_C;
         }
         else
         {
            s32LocalVxx_vvtc_ex_angl_sp = (sint32)VlvAct_agExSpFuncIntlThdLo_C;
         }
      }
      else
      {
         s32LocalVxx_vvtc_ex_angl_sp = (sint32)Vxx_vvtc_ex_angl_sp_Int;
      }
   }
   u16LocalVxx_vvtc_ex_angl_sp1 =
      (uint16)MATHSRV_udtCLAMP(s32LocalVxx_vvtc_ex_angl_sp, 0, 1066);
   VEMS_vidSET(Vxx_vvtc_ex_angl_sp, u16LocalVxx_vvtc_ex_angl_sp1);
   /*Production of VlvAct_agExSpFuncIntlThdHi*/
   VEMS_vidGET(VlvAct_bExSpFuncIntlHiOutIdc, bLocalVlvAct_bExSpFuncIntlHi);
   if (bLocalVlvAct_bExSpFuncIntlHi != 0)
   {
      s32LocalVlvagExSpFuncIntlThdHi = VlvAct_agCkExCmSpMax_C;
   }
   else
   {
      s32LocalVlvagExSpFuncIntlThdHi = (sint32)VlvAct_agExSpFuncIntlThdHi_C;
   }
   VlvAct_agExSpFuncIntlThdHi =
      (uint16)MATHSRV_udtCLAMP(s32LocalVlvagExSpFuncIntlThdHi, 0, 1066);
   /*Production of VlvAct_agExSpFuncIntlThdLo*/
   if (VlvAct_bExSpFuncIntlLoOutIdcInt != 0)
   {
      VEMS_vidGET(VlvAct_bExSpFuncIntlLoOutIdc, bLocalVlvAct_bExSpFuncIntlLo);
      if (bLocalVlvAct_bExSpFuncIntlLo != 0)
      {
         VlvAct_agExSpFuncIntlThdLo =
            (uint16)MATHSRV_udtCLAMP(VlvAct_agCkExCmSpMin_C, 0, 1066);
      }
      else
      {
         VlvAct_agExSpFuncIntlThdLo =
            (uint16)MATHSRV_udtMIN(VlvAct_agExSpFuncIntlThdLo_C, 1066);
      }
   }
   else
   {
      if (VlvAct_bExSpFuncIntlHiOutIdcInt != 0)
      {
         VlvAct_agExSpFuncIntlThdLo = VlvAct_agExSpFuncIntlThdHi;
      }
      else
      {
         VlvAct_agExSpFuncIntlThdLo = Vxx_vvtc_ex_angl_sp_Int;
      }
   }
   VLVACTEXIF_vidCalcSatSetpoint();
   /*Production of VlvAct_agCkClsExVlvReqRef0*/
   s32LocalCalc1 = ( ( VlvAct_agCkExCmRefOfs_C
                     + s32LocalVxx_vvtc_ex_angl_sp)
                   + s16LocalVlvAct_agCkExCmVlvActOfs);
   if (s32LocalCalc1 >= 0)
   {
      s32LocalVlvAct_agCkClsExVlvRqRf0 = ((s32LocalCalc1 + 4) / 8);
   }
   else
   {
      s32LocalVlvAct_agCkClsExVlvRqRf0 = ((s32LocalCalc1 - 4) / 8);
   }
   s8LocalVlvAct_agCkClsExVlvRqRf0 =
      (sint8)MATHSRV_udtCLAMP(s32LocalVlvAct_agCkClsExVlvRqRf0, -128, 127);
   VEMS_vidSET(VlvAct_agCkClsExVlvReqRef0, s8LocalVlvAct_agCkClsExVlvRqRf0);
   /*Production of VlvAct_bCmdExServoLocLop*/
   VEMS_vidGET(VlvAct_bAcvExServo, bLocalVlvAct_bAcvExServo);
   if (  (VlvAct_bExSpFuncIntlHiOutIdcInt == 0)
      && (VlvAct_bExSpFuncIntlLoOutIdcInt == 0)
      && (bLocalVlvAct_bAcvExServo != 0))
   {
      VEMS_vidSET(VlvAct_bCmdExServoLocLop, 1);
   }
   else
   {
      VEMS_vidSET(VlvAct_bCmdExServoLocLop, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXIF_vidCalcSatSetpoint                              */
/* !Description :  En cas d’incursion en dehors de la plage fonctionnelle     */
/*                 définie par les calibrations, on renvoie à la boucle d’air */
/*                 les valeurs des consignes saturées qui sont mises  toutes  */
/*                 les deux à la même valeur de reconfiguration.              */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 VlvAct_agCkExCmVlvActOfs;                                    */
/*  input sint16 VlvAct_agCkExCmRefOfs_C;                                     */
/*  input boolean VlvAct_bExSpFuncIntlLoOutIdcInt;                            */
/*  input boolean VlvAct_bExSpFuncIntlHiOutIdcInt;                            */
/*  input boolean VlvAct_bAcvVlvAgReqRef0Sat_C;                               */
/*  input uint16 VlvAct_agExSpFuncIntlThdLo;                                  */
/*  input uint16 VlvAct_agExSpFuncIntlThdHi;                                  */
/*  input sint16 VlvAct_agCkExCmSpMin_C;                                      */
/*  input sint16 VlvAct_agCkExCmSpMax_C;                                      */
/*  output sint8 VlvAct_agCkClsExVlvReqRef0Min;                               */
/*  output sint8 VlvAct_agCkClsExVlvReqRef0Max;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXIF_vidCalcSatSetpoint(void)
{
   sint8   s8LocalCalc;
   sint8   s8LocalCalcMin;
   sint8   s8LocalCalcMax;
   sint16  s16LocalVlvAct_agCkExCmVlvActOfs;
   sint32  s32LocalCalc;
   sint32  s32LocalCalcMin;
   sint32  s32LocalCalcMax;

   VEMS_vidGET(VlvAct_agCkExCmVlvActOfs, s16LocalVlvAct_agCkExCmVlvActOfs);
   s32LocalCalc = VlvAct_agCkExCmRefOfs_C + s16LocalVlvAct_agCkExCmVlvActOfs;

   if (  (  (VlvAct_bExSpFuncIntlLoOutIdcInt != 0)
         || (VlvAct_bExSpFuncIntlHiOutIdcInt != 0))
      && (VlvAct_bAcvVlvAgReqRef0Sat_C != 0))
   {
      if (VlvAct_bExSpFuncIntlLoOutIdcInt != 0)
      {
         s32LocalCalc = s32LocalCalc + VlvAct_agExSpFuncIntlThdLo;
         if (s32LocalCalc >= 0)
         {
            s32LocalCalc = (s32LocalCalc + 4) / 8;
         }
         else
         {
            s32LocalCalc = (s32LocalCalc - 4) / 8;
         }
         s8LocalCalc = (sint8)MATHSRV_udtCLAMP(s32LocalCalc, -128, 127);
         VEMS_vidSET(VlvAct_agCkClsExVlvReqRef0Min, s8LocalCalc);
         VEMS_vidSET(VlvAct_agCkClsExVlvReqRef0Max, s8LocalCalc);
      }
      else
      {
         s32LocalCalc = s32LocalCalc + VlvAct_agExSpFuncIntlThdHi;
         if (s32LocalCalc >= 0)
         {
            s32LocalCalc = (s32LocalCalc + 4) / 8;
         }
         else
         {
            s32LocalCalc = (s32LocalCalc - 4) / 8;
         }
         s8LocalCalc = (sint8)MATHSRV_udtCLAMP(s32LocalCalc, -128, 127);
         VEMS_vidSET(VlvAct_agCkClsExVlvReqRef0Min, s8LocalCalc);
         VEMS_vidSET(VlvAct_agCkClsExVlvReqRef0Max, s8LocalCalc);
      }
   }
   else
   {
      s32LocalCalcMin = s32LocalCalc + VlvAct_agCkExCmSpMin_C;
      if (s32LocalCalcMin >= 0)
      {
         s32LocalCalcMin = (s32LocalCalcMin + 4) / 8;
      }
      else
      {
         s32LocalCalcMin = (s32LocalCalcMin - 4) / 8;
      }
      s8LocalCalcMin = (sint8)MATHSRV_udtCLAMP(s32LocalCalcMin, -128, 127);
      VEMS_vidSET(VlvAct_agCkClsExVlvReqRef0Min, s8LocalCalcMin);

      s32LocalCalcMax = s32LocalCalc + VlvAct_agCkExCmSpMax_C;
      if (s32LocalCalcMax >= 0)
      {
         s32LocalCalcMax = (s32LocalCalcMax + 4) / 8;
      }
      else
      {
         s32LocalCalcMax = (s32LocalCalcMax - 4) / 8;
      }
      s8LocalCalcMax = (sint8)MATHSRV_udtCLAMP(s32LocalCalcMax, -128, 127);
      VEMS_vidSET(VlvAct_agCkClsExVlvReqRef0Max, s8LocalCalcMax);
   }
}
/*------------------------------- end of file --------------------------------*/