/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVINSPMGT                                              */
/* !Description     : VLVINSPMGT component                                    */
/*                                                                            */
/* !Module          : VLVINSPMGT                                              */
/* !Description     : Gestion de la consigne VVT admission                    */
/*                                                                            */
/* !File            : VLVINSPMGT_FCT1.C                                       */
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
/*   1 / VLVINSPMGT_vidInit                                                   */
/*   2 / VLVINSPMGT_vidInitOutput                                             */
/*   3 / VLVINSPMGT_vidVlvInEna                                               */
/*   4 / VLVINSPMGT_vidVlvIn                                                  */
/*   5 / VLVINSPMGT_vidUnvectorize_Mode                                       */
/*   6 / VLVINSPMGT_vidMode_Mask                                              */
/*   7 / VLVINSPMGT_vidCalibrations                                           */
/*   8 / VLVINSPMGT_vidSelect_Modes                                           */
/*   9 / VLVINSPMGT_vidInterpolation                                          */
/*   10 / VLVINSPMGT_vidUnvect_Activ_Bool                                     */
/*                                                                            */
/* !Reference   : V02 NT 11 02166 / 01                                        */
/* !OtherRefs   : CSMT_CGMT09_2176_2 / 1                                      */
/* !OtherRefs   : VEMS V02 ECU#053818                                         */
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
#include "VLVINSPMGT.h"
#include "VLVINSPMGT_L.h"
#include "VLVINSPMGT_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVINSPMGT_vidInit                                         */
/* !Description :  Initialisation de la consigne VVT à la butée de repos.     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02166_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint8 VlvSys_agCkOpInVlvReqRef0Max_C;                               */
/*  output sint8 VlvSys_agCkOpInVlvReq;                                       */
/*  output sint8 VlvSys_agCkOpInVlvReqRef0Max_C;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVINSPMGT_vidInit(void)
{
   VEMS_vidSET(VlvSys_agCkOpInVlvReq, VlvSys_agCkOpInVlvReqRef0Max_C);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVINSPMGT_vidInitOutput                                   */
/* !Description :  Fonction d'initialisation des variables internes.          */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output sint8 VlvSys_agCkOpInCal18;                                        */
/*  output sint8 VlvSys_agCkOpInCal17;                                        */
/*  output sint8 VlvSys_agCkOpInCal16;                                        */
/*  output sint8 VlvSys_agCkOpInCal15;                                        */
/*  output sint8 VlvSys_agCkOpInCal14;                                        */
/*  output sint8 VlvSys_agCkOpInCal13;                                        */
/*  output sint8 VlvSys_agCkOpInCal12;                                        */
/*  output sint8 VlvSys_agCkOpInCal11;                                        */
/*  output sint8 VlvSys_agCkOpInCal10;                                        */
/*  output sint8 VlvSys_agCkOpInCal9;                                         */
/*  output sint8 VlvSys_agCkOpInCal8;                                         */
/*  output sint8 VlvSys_agCkOpInCal7;                                         */
/*  output sint8 VlvSys_agCkOpInCal6;                                         */
/*  output sint8 VlvSys_agCkOpInCal5;                                         */
/*  output sint8 VlvSys_agCkOpInCal4;                                         */
/*  output sint8 VlvSys_agCkOpInCal3;                                         */
/*  output sint8 VlvSys_agCkOpInCal2;                                         */
/*  output sint8 VlvSys_agCkOpInCal1;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVINSPMGT_vidInitOutput(void)
{
   VlvSys_agCkOpInCal18 = 0;
   VlvSys_agCkOpInCal17 = 0;
   VlvSys_agCkOpInCal16 = 0;
   VlvSys_agCkOpInCal15 = 0;
   VlvSys_agCkOpInCal14 = 0;
   VlvSys_agCkOpInCal13 = 0;
   VlvSys_agCkOpInCal12 = 0;
   VlvSys_agCkOpInCal11 = 0;
   VlvSys_agCkOpInCal10 = 0;
   VlvSys_agCkOpInCal9 = 0;
   VlvSys_agCkOpInCal8 = 0;
   VlvSys_agCkOpInCal7 = 0;
   VlvSys_agCkOpInCal6 = 0;
   VlvSys_agCkOpInCal5 = 0;
   VlvSys_agCkOpInCal4 = 0;
   VlvSys_agCkOpInCal3 = 0;
   VlvSys_agCkOpInCal2 = 0;
   VlvSys_agCkOpInCal1 = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVINSPMGT_vidVlvInEna                                     */
/* !Description :  Ce  bloc  servant  à  l’élaboration  des  consignes  VVT   */
/*                 peut  être  désactivé  par l’intermédiaire  du  booléen    */
/*                 VlvSys_bPresInServo_C dans le cas où le moteur n’est pas   */
/*                 équipé d’un système VVT à l’admission.                     */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02166_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVINSPMGT_vidVlvIn();                                   */
/*  input boolean VlvSys_bPresInServo_C;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVINSPMGT_vidVlvInEna(void)
{
   if (VlvSys_bPresInServo_C != 0)
   {
      VLVINSPMGT_vidVlvIn();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVINSPMGT_vidVlvIn                                        */
/* !Description :  Ce bloc permet d'élaborer les consignes VVT à appliquer au */
/*                 système en fonction des modes de combustions. Les modes de */
/*                 combustion tiennent compte de l'état moteur (chaud/froid,  */
/*                 chauffe catalyseur, anticipation du ralenti, ...)          */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02166_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVINSPMGT_vidUnvectorize_Mode();                        */
/*  extf argret void VLVINSPMGT_vidMode_Mask();                               */
/*  extf argret void VLVINSPMGT_vidCalibrations();                            */
/*  extf argret void VLVINSPMGT_vidSelect_Modes();                            */
/*  extf argret void VLVINSPMGT_vidInterpolation();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVINSPMGT_vidVlvIn(void)
{
   VLVINSPMGT_vidUnvectorize_Mode();
   VLVINSPMGT_vidMode_Mask();
   VLVINSPMGT_vidCalibrations();
   VLVINSPMGT_vidSelect_Modes();
   VLVINSPMGT_vidInterpolation();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVINSPMGT_vidUnvectorize_Mode                             */
/* !Description :  Ce  bloc  permet  de  récupérer  les  informations  servant*/
/*                  à  l'élaboration  des  consignes  VVT    et  provenant  du*/
/*                 gestionnaire de modes de combustion.                       */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02166_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  input boolean VlvSys_bAcvOEMBedMod_C;                                     */
/*  input uint8 VlvSys_idxBas1ModCurBedMod_C;                                 */
/*  input uint8 VlvSys_idxBas2ModCurBedMod_C;                                 */
/*  input uint8 VlvSys_idxBas1ModTarBedMod_C;                                 */
/*  input uint8 VlvSys_idxBas2ModTarBedMod_C;                                 */
/*  input uint8 VlvSys_facBasModCurBedMod_C;                                  */
/*  input uint8 VlvSys_facBasModTarBedMod_C;                                  */
/*  input uint8 VlvSys_facTranModBedMod_C;                                    */
/*  input uint8 EOM_prm_idxBas1ModCur[16];                                    */
/*  input uint8 EOM_prm_idxBas2ModCur[16];                                    */
/*  input uint8 EOM_prm_idxBas1ModTar[16];                                    */
/*  input uint8 EOM_prm_idxBas2ModTar[16];                                    */
/*  input uint8 EOM_prm_facBasModCur[16];                                     */
/*  input uint8 EOM_prm_facBasModTar[16];                                     */
/*  input uint8 EOM_prm_facTranMod[16];                                       */
/*  output uint8 VlvSys_idxBas1ModCurOpIn;                                    */
/*  output uint8 VlvSys_idxBas2ModCurOpIn;                                    */
/*  output uint8 VlvSys_idxBas1ModTarOpIn;                                    */
/*  output uint8 VlvSys_idxBas2ModTarOpIn;                                    */
/*  output uint8 VlvSys_facBasModCurOpIn;                                     */
/*  output uint8 VlvSys_facBasModTarOpIn;                                     */
/*  output uint8 VlvSys_facTranModOpIn;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVINSPMGT_vidUnvectorize_Mode(void)
{
   uint8 u8LocalVlvSys_idxBas1ModCurOpIn;
   uint8 u8LocalVlvSys_idxBas2ModCurOpIn;
   uint8 u8LocalVlvSys_idxBas1ModTarOpIn;
   uint8 u8LocalVlvSys_idxBas2ModTarOpIn;
   uint8 u8LocalVlvSys_facBasModCurOpIn;
   uint8 u8LocalVlvSys_facBasModCurOpIn1;
   uint8 u8LocalVlvSys_facBasModTarOpIn;
   uint8 u8LocalVlvSys_facBasModTarOpIn1;
   uint8 u8LocalVlvSys_facTranModOpIn;
   uint8 u8LocalVlvSys_facTranModOpIn1;


   if (VlvSys_bAcvOEMBedMod_C != 0)
   {
      u8LocalVlvSys_idxBas1ModCurOpIn = VlvSys_idxBas1ModCurBedMod_C;
      u8LocalVlvSys_idxBas2ModCurOpIn = VlvSys_idxBas2ModCurBedMod_C;
      u8LocalVlvSys_idxBas1ModTarOpIn = VlvSys_idxBas1ModTarBedMod_C;
      u8LocalVlvSys_idxBas2ModTarOpIn = VlvSys_idxBas2ModTarBedMod_C;
      u8LocalVlvSys_facBasModCurOpIn = VlvSys_facBasModCurBedMod_C;
      u8LocalVlvSys_facBasModTarOpIn = VlvSys_facBasModTarBedMod_C;
      u8LocalVlvSys_facTranModOpIn = VlvSys_facTranModBedMod_C;
   }
   else
   {
      VEMS_vidGET1DArrayElement(EOM_prm_idxBas1ModCur,
                                4,
                                u8LocalVlvSys_idxBas1ModCurOpIn);
      VEMS_vidGET1DArrayElement(EOM_prm_idxBas2ModCur,
                                4,
                                u8LocalVlvSys_idxBas2ModCurOpIn);
      VEMS_vidGET1DArrayElement(EOM_prm_idxBas1ModTar,
                                4,
                                u8LocalVlvSys_idxBas1ModTarOpIn);
      VEMS_vidGET1DArrayElement(EOM_prm_idxBas2ModTar,
                                4,
                                u8LocalVlvSys_idxBas2ModTarOpIn);

      VEMS_vidGET1DArrayElement(EOM_prm_facBasModCur,
                                4,
                                u8LocalVlvSys_facBasModCurOpIn1);
      u8LocalVlvSys_facBasModCurOpIn =
         (uint8)((25 * u8LocalVlvSys_facBasModCurOpIn1) / 32);

      VEMS_vidGET1DArrayElement(EOM_prm_facBasModTar,
                                4,
                                u8LocalVlvSys_facBasModTarOpIn1);
      u8LocalVlvSys_facBasModTarOpIn =
         (uint8)((25 * u8LocalVlvSys_facBasModTarOpIn1) / 32);

      VEMS_vidGET1DArrayElement(EOM_prm_facTranMod,
                                4,
                                u8LocalVlvSys_facTranModOpIn1);
      u8LocalVlvSys_facTranModOpIn =
         (uint8)((25 * u8LocalVlvSys_facTranModOpIn1) / 32);
   }
   VlvSys_idxBas1ModCurOpIn =
      (uint8)MATHSRV_udtCLAMP(u8LocalVlvSys_idxBas1ModCurOpIn, 1, 18);
   VlvSys_idxBas2ModCurOpIn =
      (uint8)MATHSRV_udtCLAMP(u8LocalVlvSys_idxBas2ModCurOpIn, 1, 18);
   VlvSys_idxBas1ModTarOpIn =
      (uint8)MATHSRV_udtCLAMP(u8LocalVlvSys_idxBas1ModTarOpIn, 1, 18);
   VlvSys_idxBas2ModTarOpIn =
      (uint8)MATHSRV_udtCLAMP(u8LocalVlvSys_idxBas2ModTarOpIn, 1, 18);
   VlvSys_facBasModCurOpIn =
      (uint8)MATHSRV_udtMIN(u8LocalVlvSys_facBasModCurOpIn, 100);
   VlvSys_facBasModTarOpIn =
      (uint8)MATHSRV_udtMIN(u8LocalVlvSys_facBasModTarOpIn, 100);
   VlvSys_facTranModOpIn =
      (uint8)MATHSRV_udtMIN(u8LocalVlvSys_facTranModOpIn, 100);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVINSPMGT_vidMode_Mask                                    */
/* !Description :  Ce bloc a pour but de concaténer sur un seul flux          */
/*                 l'ensemble des modes de combustion activés par le          */
/*                 gestionnaire.                                              */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02166_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 VlvSys_idxBas1ModCurOpIn;                                     */
/*  input uint8 VlvSys_idxBas2ModCurOpIn;                                     */
/*  input uint8 VlvSys_idxBas1ModTarOpIn;                                     */
/*  input uint8 VlvSys_idxBas2ModTarOpIn;                                     */
/*  output boolean VlvSys_prm_bAcvOpInCal[18];                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVINSPMGT_vidMode_Mask(void)
{
   uint8 u8LocalIndex;
   uint8 u8LocalIdx1ModCur;
   uint8 u8LocalIdx2ModCur;
   uint8 u8LocalIdx1ModTar;
   uint8 u8LocalIdx2ModTar;


   u8LocalIdx1ModCur = (uint8)MATHSRV_udtCLAMP(VlvSys_idxBas1ModCurOpIn, 1, 18);

   u8LocalIdx2ModCur = (uint8)MATHSRV_udtCLAMP(VlvSys_idxBas2ModCurOpIn, 1, 18);

   u8LocalIdx1ModTar = (uint8)MATHSRV_udtCLAMP(VlvSys_idxBas1ModTarOpIn, 1, 18);

   u8LocalIdx2ModTar = (uint8)MATHSRV_udtCLAMP(VlvSys_idxBas2ModTarOpIn, 1, 18);

   for(u8LocalIndex = 0; u8LocalIndex <= 17; u8LocalIndex++)
   {
      VlvSys_prm_bAcvOpInCal[u8LocalIndex] = 0;
   }

   VlvSys_prm_bAcvOpInCal[u8LocalIdx1ModCur - 1] = 1;
   VlvSys_prm_bAcvOpInCal[u8LocalIdx2ModCur - 1] = 1;
   VlvSys_prm_bAcvOpInCal[u8LocalIdx1ModTar - 1] = 1;
   VlvSys_prm_bAcvOpInCal[u8LocalIdx2ModTar - 1] = 1;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVINSPMGT_vidCalibrations                                 */
/* !Description :  Ce bloc permet d'effectuer uniquement  les calculs des     */
/*                 cartographies correspondants aux modes de combustion       */
/*                 activés.                                                   */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02166_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVINSPMGT_vidUnvect_Activ_Bool();                       */
/*  extf argret void VLVINSPMGT_vidCalibration_1();                           */
/*  extf argret void VLVINSPMGT_vidCalibration_2();                           */
/*  extf argret void VLVINSPMGT_vidCalibration_3();                           */
/*  extf argret void VLVINSPMGT_vidCalibration_4();                           */
/*  extf argret void VLVINSPMGT_vidCalibration_5();                           */
/*  extf argret void VLVINSPMGT_vidCalibration_6();                           */
/*  extf argret void VLVINSPMGT_vidCalibration_7();                           */
/*  extf argret void VLVINSPMGT_vidCalibration_8();                           */
/*  extf argret void VLVINSPMGT_vidCalibration_9();                           */
/*  extf argret void VLVINSPMGT_vidCalibration_10();                          */
/*  extf argret void VLVINSPMGT_vidCalibration_11();                          */
/*  extf argret void VLVINSPMGT_vidCalibration_12();                          */
/*  extf argret void VLVINSPMGT_vidCalibration_13();                          */
/*  extf argret void VLVINSPMGT_vidCalibration_14();                          */
/*  extf argret void VLVINSPMGT_vidCalibration_15();                          */
/*  extf argret void VLVINSPMGT_vidCalibration_16();                          */
/*  extf argret void VLVINSPMGT_vidCalibration_17();                          */
/*  extf argret void VLVINSPMGT_vidCalibration_18();                          */
/*  extf argret void VLVINSPMGT_vidVectorize_Calibs();                        */
/*  input boolean VlvSys_bAcvOpInCal1;                                        */
/*  input boolean VlvSys_bAcvOpInCal2;                                        */
/*  input boolean VlvSys_bAcvOpInCal3;                                        */
/*  input boolean VlvSys_bAcvOpInCal4;                                        */
/*  input boolean VlvSys_bAcvOpInCal5;                                        */
/*  input boolean VlvSys_bAcvOpInCal6;                                        */
/*  input boolean VlvSys_bAcvOpInCal7;                                        */
/*  input boolean VlvSys_bAcvOpInCal8;                                        */
/*  input boolean VlvSys_bAcvOpInCal9;                                        */
/*  input boolean VlvSys_bAcvOpInCal10;                                       */
/*  input boolean VlvSys_bAcvOpInCal11;                                       */
/*  input boolean VlvSys_bAcvOpInCal12;                                       */
/*  input boolean VlvSys_bAcvOpInCal13;                                       */
/*  input boolean VlvSys_bAcvOpInCal14;                                       */
/*  input boolean VlvSys_bAcvOpInCal15;                                       */
/*  input boolean VlvSys_bAcvOpInCal16;                                       */
/*  input boolean VlvSys_bAcvOpInCal17;                                       */
/*  input boolean VlvSys_bAcvOpInCal18;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVINSPMGT_vidCalibrations(void)
{
   VLVINSPMGT_vidUnvect_Activ_Bool();
   if (VlvSys_bAcvOpInCal1 != 0)
   {
      VLVINSPMGT_vidCalibration_1();
   }
   if (VlvSys_bAcvOpInCal2 != 0)
   {
      VLVINSPMGT_vidCalibration_2();
   }
   if (VlvSys_bAcvOpInCal3 != 0)
   {
      VLVINSPMGT_vidCalibration_3();
   }
   if (VlvSys_bAcvOpInCal4 != 0)
   {
      VLVINSPMGT_vidCalibration_4();
   }
   if (VlvSys_bAcvOpInCal5 != 0)
   {
      VLVINSPMGT_vidCalibration_5();
   }
   if (VlvSys_bAcvOpInCal6 != 0)
   {
      VLVINSPMGT_vidCalibration_6();
   }
   if (VlvSys_bAcvOpInCal7 != 0)
   {
      VLVINSPMGT_vidCalibration_7();
   }
   if (VlvSys_bAcvOpInCal8 != 0)
   {
      VLVINSPMGT_vidCalibration_8();
   }
   if (VlvSys_bAcvOpInCal9 != 0)
   {
      VLVINSPMGT_vidCalibration_9();
   }
   if (VlvSys_bAcvOpInCal10 != 0)
   {
      VLVINSPMGT_vidCalibration_10();
   }
   if (VlvSys_bAcvOpInCal11 != 0)
   {
      VLVINSPMGT_vidCalibration_11();
   }
   if (VlvSys_bAcvOpInCal12 != 0)
   {
      VLVINSPMGT_vidCalibration_12();
   }
   if (VlvSys_bAcvOpInCal13 != 0)
   {
      VLVINSPMGT_vidCalibration_13();
   }
   if (VlvSys_bAcvOpInCal14 != 0)
   {
      VLVINSPMGT_vidCalibration_14();
   }
   if (VlvSys_bAcvOpInCal15 != 0)
   {
      VLVINSPMGT_vidCalibration_15();
   }
   if (VlvSys_bAcvOpInCal16 != 0)
   {
      VLVINSPMGT_vidCalibration_16();
   }
   if (VlvSys_bAcvOpInCal17 != 0)
   {
      VLVINSPMGT_vidCalibration_17();
   }
   if (VlvSys_bAcvOpInCal18 != 0)
   {
      VLVINSPMGT_vidCalibration_18();
   }
   VLVINSPMGT_vidVectorize_Calibs();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVINSPMGT_vidSelect_Modes                                 */
/* !Description :  Ce bloc permet de récupérer les consignes VVT              */
/*                 correspondantes aux modes de combustion.                   */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02166_029.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 VlvSys_idxBas1ModCurOpIn;                                     */
/*  input sint8 VlvSys_prm_agCkOpInCal[18];                                   */
/*  input uint8 VlvSys_idxBas2ModCurOpIn;                                     */
/*  input uint8 VlvSys_idxBas1ModTarOpIn;                                     */
/*  input uint8 VlvSys_idxBas2ModTarOpIn;                                     */
/*  output sint8 VlvSys_agCkOpInVlvBas1ModCur;                                */
/*  output sint8 VlvSys_agCkOpInVlvBas2ModCur;                                */
/*  output sint8 VlvSys_agCkOpInVlvBas1ModTar;                                */
/*  output sint8 VlvSys_agCkOpInVlvBas2ModTar;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVINSPMGT_vidSelect_Modes(void)
{
   uint8  u8LocalIndex;
   uint8  u8LocalVlvSys_idxBas1ModCurOpIn;
   uint8  u8LocalVlvSys_idxBas2ModCurOpIn;
   uint8  u8LocalVlvSys_idxBas1ModTarOpIn;
   uint8  u8LocalVlvSys_idxBas2ModTarOpIn;
   sint8  s8LocalVlvSys_prm_agCkOpInCal;


   u8LocalVlvSys_idxBas1ModCurOpIn =
      (uint8)MATHSRV_udtCLAMP(VlvSys_idxBas1ModCurOpIn, 1, 18);
   u8LocalIndex = (uint8)(u8LocalVlvSys_idxBas1ModCurOpIn - 1);

   s8LocalVlvSys_prm_agCkOpInCal = VlvSys_prm_agCkOpInCal[u8LocalIndex];
   VlvSys_agCkOpInVlvBas1ModCur = s8LocalVlvSys_prm_agCkOpInCal;

   u8LocalVlvSys_idxBas2ModCurOpIn =
      (uint8)MATHSRV_udtCLAMP(VlvSys_idxBas2ModCurOpIn, 1, 18);
   u8LocalIndex = (uint8)(u8LocalVlvSys_idxBas2ModCurOpIn - 1);
   s8LocalVlvSys_prm_agCkOpInCal = VlvSys_prm_agCkOpInCal[u8LocalIndex];
   VlvSys_agCkOpInVlvBas2ModCur = s8LocalVlvSys_prm_agCkOpInCal;

   u8LocalVlvSys_idxBas1ModTarOpIn =
      (uint8)MATHSRV_udtCLAMP(VlvSys_idxBas1ModTarOpIn, 1, 18);
   u8LocalIndex = (uint8)(u8LocalVlvSys_idxBas1ModTarOpIn - 1);
   s8LocalVlvSys_prm_agCkOpInCal = VlvSys_prm_agCkOpInCal[u8LocalIndex];
   VlvSys_agCkOpInVlvBas1ModTar = s8LocalVlvSys_prm_agCkOpInCal;

   u8LocalVlvSys_idxBas2ModTarOpIn =
      (uint8)MATHSRV_udtCLAMP(VlvSys_idxBas2ModTarOpIn, 1, 18);
   u8LocalIndex = (uint8)(u8LocalVlvSys_idxBas2ModTarOpIn - 1);
   s8LocalVlvSys_prm_agCkOpInCal = VlvSys_prm_agCkOpInCal[u8LocalIndex];
   VlvSys_agCkOpInVlvBas2ModTar = s8LocalVlvSys_prm_agCkOpInCal;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVINSPMGT_vidInterpolation                                */
/* !Description :  Ce bloc permet d'effectuer un barycentre sur  les          */
/*                 différentes consignes VVT correspondantes à chaque mode de */
/*                 combustion afin d'assurer les transitions entre modes de   */
/*                 combustion.                                                */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02166_030.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 VlvSys_facBasModTarOpIn;                                      */
/*  input sint8 VlvSys_agCkOpInVlvBas1ModTar;                                 */
/*  input sint8 VlvSys_agCkOpInVlvBas2ModTar;                                 */
/*  input uint8 VlvSys_facBasModCurOpIn;                                      */
/*  input sint8 VlvSys_agCkOpInVlvBas1ModCur;                                 */
/*  input sint8 VlvSys_agCkOpInVlvBas2ModCur;                                 */
/*  input uint8 VlvSys_facTranModOpIn;                                        */
/*  output sint8 VlvSys_agCkOpInVlvReq;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVINSPMGT_vidInterpolation(void)
{
   uint8  u8LocalDiff;
   sint8  s8LocalVlvSys_agCkOpInVlvReq;
   sint16 s16LocalModTar;
   sint16 s16LocalModCur;
   sint16 s16LocalProd1;
   sint16 s16LocalProd2;
   sint16 s16LocalVlvSys_agCkOpInVlvReq;
   sint32 s32LocalProd1;
   sint32 s32LocalProd2;



   /*Barycentre 1 */
   if (  (VlvSys_facBasModTarOpIn > 0)
      && (VlvSys_facBasModTarOpIn < 100))
   {
      s16LocalProd1 =
         (sint16)(VlvSys_agCkOpInVlvBas1ModTar * VlvSys_facBasModTarOpIn);
      u8LocalDiff = (uint8)(100 - VlvSys_facBasModTarOpIn);
      s16LocalProd2 = (sint16)(VlvSys_agCkOpInVlvBas2ModTar * u8LocalDiff);
      s16LocalModTar = (sint16)(s16LocalProd1 + s16LocalProd2);
      if (s16LocalModTar < 0)
      {
         s16LocalModTar = (sint16)((s16LocalModTar - 50) / 100);
      }
      else
      {
         s16LocalModTar = (sint16)((s16LocalModTar + 50) / 100);
      }
   }
   else
   {
      if (VlvSys_facBasModTarOpIn == 0)
      {
         s16LocalModTar = (sint16)VlvSys_agCkOpInVlvBas2ModTar;
      }
      else
      {
         s16LocalModTar = (sint16)VlvSys_agCkOpInVlvBas1ModTar;
      }
   }

   /* Barycentre 2 */
   if (  (VlvSys_facBasModCurOpIn > 0)
      && (VlvSys_facBasModCurOpIn < 100))
   {
      s16LocalProd1 =
         (sint16)(VlvSys_agCkOpInVlvBas1ModCur * VlvSys_facBasModCurOpIn);
      u8LocalDiff = (uint8)(100 - VlvSys_facBasModCurOpIn);
      s16LocalProd2 = (sint16)(VlvSys_agCkOpInVlvBas2ModCur * u8LocalDiff);
      s16LocalModCur = (sint16)(s16LocalProd1 + s16LocalProd2);
      if (s16LocalModCur < 0)
      {
         s16LocalModCur = (sint16)((s16LocalModCur - 50) / 100);
      }
      else
      {
         s16LocalModCur = (sint16)((s16LocalModCur + 50) / 100);
      }
   }
   else
   {
      if (VlvSys_facBasModCurOpIn == 0)
      {
         s16LocalModCur = (sint16)VlvSys_agCkOpInVlvBas2ModCur;
      }
      else
      {
         s16LocalModCur = (sint16)VlvSys_agCkOpInVlvBas1ModCur;
      }
   }

   /* Barycentre 3 */
   if (  (VlvSys_facTranModOpIn > 0)
      && (VlvSys_facTranModOpIn < 100))
   {
      s32LocalProd1 = (s16LocalModTar * VlvSys_facTranModOpIn);
      u8LocalDiff = (uint8)(100 - VlvSys_facTranModOpIn);
      s32LocalProd2 = (s16LocalModCur * u8LocalDiff);
      s16LocalVlvSys_agCkOpInVlvReq = (sint16)(s32LocalProd1 + s32LocalProd2);
      if (s16LocalVlvSys_agCkOpInVlvReq < 0)
      {
         s16LocalVlvSys_agCkOpInVlvReq =
            (sint16)((s16LocalVlvSys_agCkOpInVlvReq - 50) / 100);
      }
      else
      {
         s16LocalVlvSys_agCkOpInVlvReq =
            (sint16)((s16LocalVlvSys_agCkOpInVlvReq + 50) / 100);
      }
   }
   else
   {
      if (VlvSys_facTranModOpIn == 0)
      {
         s16LocalVlvSys_agCkOpInVlvReq = s16LocalModCur;
      }
      else
      {
         s16LocalVlvSys_agCkOpInVlvReq = s16LocalModTar;
      }
   }
   s8LocalVlvSys_agCkOpInVlvReq = (sint8)s16LocalVlvSys_agCkOpInVlvReq;
   VEMS_vidSET(VlvSys_agCkOpInVlvReq, s8LocalVlvSys_agCkOpInVlvReq);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVINSPMGT_vidUnvect_Activ_Bool                            */
/* !Description :  Ce bloc sert à dévectoriser le flux contenant l'ensemble   */
/*                 des modes de combustion activés.                           */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02166_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean VlvSys_prm_bAcvOpInCal[18];                                 */
/*  output boolean VlvSys_bAcvOpInCal1;                                       */
/*  output boolean VlvSys_bAcvOpInCal2;                                       */
/*  output boolean VlvSys_bAcvOpInCal3;                                       */
/*  output boolean VlvSys_bAcvOpInCal4;                                       */
/*  output boolean VlvSys_bAcvOpInCal5;                                       */
/*  output boolean VlvSys_bAcvOpInCal6;                                       */
/*  output boolean VlvSys_bAcvOpInCal7;                                       */
/*  output boolean VlvSys_bAcvOpInCal8;                                       */
/*  output boolean VlvSys_bAcvOpInCal9;                                       */
/*  output boolean VlvSys_bAcvOpInCal10;                                      */
/*  output boolean VlvSys_bAcvOpInCal11;                                      */
/*  output boolean VlvSys_bAcvOpInCal12;                                      */
/*  output boolean VlvSys_bAcvOpInCal13;                                      */
/*  output boolean VlvSys_bAcvOpInCal14;                                      */
/*  output boolean VlvSys_bAcvOpInCal15;                                      */
/*  output boolean VlvSys_bAcvOpInCal16;                                      */
/*  output boolean VlvSys_bAcvOpInCal17;                                      */
/*  output boolean VlvSys_bAcvOpInCal18;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVINSPMGT_vidUnvect_Activ_Bool(void)
{
   if (VlvSys_prm_bAcvOpInCal[0] != 0)
   {
      VlvSys_bAcvOpInCal1 = 1;
   }
   else
   {
      VlvSys_bAcvOpInCal1 = 0;
   }
   if (VlvSys_prm_bAcvOpInCal[1] != 0)
   {
      VlvSys_bAcvOpInCal2 = 1;
   }
   else
   {
      VlvSys_bAcvOpInCal2 = 0;
   }
   if (VlvSys_prm_bAcvOpInCal[2] != 0)
   {
      VlvSys_bAcvOpInCal3 = 1;
   }
   else
   {
      VlvSys_bAcvOpInCal3 = 0;
   }
   if (VlvSys_prm_bAcvOpInCal[3] != 0)
   {
      VlvSys_bAcvOpInCal4 = 1;
   }
   else
   {
      VlvSys_bAcvOpInCal4 = 0;
   }
   if (VlvSys_prm_bAcvOpInCal[4] != 0)
   {
      VlvSys_bAcvOpInCal5 = 1;
   }
   else
   {
      VlvSys_bAcvOpInCal5 = 0;
   }
   if (VlvSys_prm_bAcvOpInCal[5] != 0)
   {
      VlvSys_bAcvOpInCal6 = 1;
   }
   else
   {
      VlvSys_bAcvOpInCal6 = 0;
   }
   if (VlvSys_prm_bAcvOpInCal[6] != 0)
   {
      VlvSys_bAcvOpInCal7 = 1;
   }
   else
   {
      VlvSys_bAcvOpInCal7 = 0;
   }
   if (VlvSys_prm_bAcvOpInCal[7] != 0)
   {
      VlvSys_bAcvOpInCal8 = 1;
   }
   else
   {
      VlvSys_bAcvOpInCal8 = 0;
   }
   if (VlvSys_prm_bAcvOpInCal[8] != 0)
   {
      VlvSys_bAcvOpInCal9 = 1;
   }
   else
   {
      VlvSys_bAcvOpInCal9 = 0;
   }
   if (VlvSys_prm_bAcvOpInCal[9] != 0)
   {
      VlvSys_bAcvOpInCal10 = 1;
   }
   else
   {
      VlvSys_bAcvOpInCal10 = 0;
   }
   if (VlvSys_prm_bAcvOpInCal[10] != 0)
   {
      VlvSys_bAcvOpInCal11 = 1;
   }
   else
   {
      VlvSys_bAcvOpInCal11 = 0;
   }
   if (VlvSys_prm_bAcvOpInCal[11] != 0)
   {
      VlvSys_bAcvOpInCal12 = 1;
   }
   else
   {
      VlvSys_bAcvOpInCal12 = 0;
   }
   if (VlvSys_prm_bAcvOpInCal[12] != 0)
   {
      VlvSys_bAcvOpInCal13 = 1;
   }
   else
   {
      VlvSys_bAcvOpInCal13 = 0;
   }
   if (VlvSys_prm_bAcvOpInCal[13] != 0)
   {
      VlvSys_bAcvOpInCal14 = 1;
   }
   else
   {
      VlvSys_bAcvOpInCal14 = 0;
   }
   if (VlvSys_prm_bAcvOpInCal[14] != 0)
   {
      VlvSys_bAcvOpInCal15 = 1;
   }
   else
   {
      VlvSys_bAcvOpInCal15 = 0;
   }
   if (VlvSys_prm_bAcvOpInCal[15] != 0)
   {
      VlvSys_bAcvOpInCal16 = 1;
   }
   else
   {
      VlvSys_bAcvOpInCal16 = 0;
   }
   if (VlvSys_prm_bAcvOpInCal[16] != 0)
   {
      VlvSys_bAcvOpInCal17 = 1;
   }
   else
   {
      VlvSys_bAcvOpInCal17 = 0;
   }
   if (VlvSys_prm_bAcvOpInCal[17] != 0)
   {
      VlvSys_bAcvOpInCal18 = 1;
   }
   else
   {
      VlvSys_bAcvOpInCal18 = 0;
   }
}

/*---------------------------------end of file--------------------------------*/