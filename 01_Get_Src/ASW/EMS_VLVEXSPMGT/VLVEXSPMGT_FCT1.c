/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVEXSPMGT                                              */
/* !Description     : VLVEXSPMGT component                                    */
/*                                                                            */
/* !Module          : VLVEXSPMGT                                              */
/* !Description     : Gestion de la consigne VVT échappement                  */
/*                                                                            */
/* !File            : VLVEXSPMGT_FCT1.C                                       */
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
/*   1 / VLVEXSPMGT_vidInit                                                   */
/*   2 / VLVEXSPMGT_vidInitOutput                                             */
/*   3 / VLVEXSPMGT_vidVlvExEna                                               */
/*   4 / VLVEXSPMGT_vidVlvEx                                                  */
/*   5 / VLVEXSPMGT_vidUnvectorize_Mode                                       */
/*   6 / VLVEXSPMGT_vidMode_Mask                                              */
/*   7 / VLVEXSPMGT_vidCalibrations                                           */
/*   8 / VLVEXSPMGT_vidSelect_Modes                                           */
/*   9 / VLVEXSPMGT_vidInterpolation                                          */
/*   10 / VLVEXSPMGT_vidUnvect_Activ_Bool                                     */
/*                                                                            */
/* !Reference   : V02 NT 11 02167 / 02                                        */
/* !OtherRefs   : CSMT_CGMT09_2177_2 / 1.1                                    */
/* !OtherRefs   : VEMS V02 ECU#053820                                         */
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
#include "VLVEXSPMGT.h"
#include "VLVEXSPMGT_L.h"
#include "VLVEXSPMGT_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVEXSPMGT_vidInit                                         */
/* !Description :  Initialisation de la consigne VVT à la butée de repos.     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02167_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint8 VlvSys_agCkClsExVlvReqRef0Min_C;                              */
/*  output sint8 VlvSys_agCkClsExVlvReq;                                      */
/*  output sint8 VlvSys_agCkClsExVlvReqRef0Min_C;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVEXSPMGT_vidInit(void)
{
   VEMS_vidSET(VlvSys_agCkClsExVlvReq, VlvSys_agCkClsExVlvReqRef0Min_C);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVEXSPMGT_vidInitOutput                                   */
/* !Description :  Fonction d'initialisation des variables internes.          */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output sint8 VlvSys_agCkClsExCal18;                                       */
/*  output sint8 VlvSys_agCkClsExCal17;                                       */
/*  output sint8 VlvSys_agCkClsExCal16;                                       */
/*  output sint8 VlvSys_agCkClsExCal15;                                       */
/*  output sint8 VlvSys_agCkClsExCal14;                                       */
/*  output sint8 VlvSys_agCkClsExCal13;                                       */
/*  output sint8 VlvSys_agCkClsExCal12;                                       */
/*  output sint8 VlvSys_agCkClsExCal11;                                       */
/*  output sint8 VlvSys_agCkClsExCal10;                                       */
/*  output sint8 VlvSys_agCkClsExCal9;                                        */
/*  output sint8 VlvSys_agCkClsExCal8;                                        */
/*  output sint8 VlvSys_agCkClsExCal7;                                        */
/*  output sint8 VlvSys_agCkClsExCal6;                                        */
/*  output sint8 VlvSys_agCkClsExCal5;                                        */
/*  output sint8 VlvSys_agCkClsExCal4;                                        */
/*  output sint8 VlvSys_agCkClsExCal3;                                        */
/*  output sint8 VlvSys_agCkClsExCal2;                                        */
/*  output sint8 VlvSys_agCkClsExCal1;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVEXSPMGT_vidInitOutput(void)
{
   VlvSys_agCkClsExCal18 = 0;
   VlvSys_agCkClsExCal17 = 0;
   VlvSys_agCkClsExCal16 = 0;
   VlvSys_agCkClsExCal15 = 0;
   VlvSys_agCkClsExCal14 = 0;
   VlvSys_agCkClsExCal13 = 0;
   VlvSys_agCkClsExCal12 = 0;
   VlvSys_agCkClsExCal11 = 0;
   VlvSys_agCkClsExCal10 = 0;
   VlvSys_agCkClsExCal9 = 0;
   VlvSys_agCkClsExCal8 = 0;
   VlvSys_agCkClsExCal7 = 0;
   VlvSys_agCkClsExCal6 = 0;
   VlvSys_agCkClsExCal5 = 0;
   VlvSys_agCkClsExCal4 = 0;
   VlvSys_agCkClsExCal3 = 0;
   VlvSys_agCkClsExCal2 = 0;
   VlvSys_agCkClsExCal1 = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVEXSPMGT_vidVlvExEna                                     */
/* !Description :  Ce  bloc  servant  à  l’élaboration  des  consignes  VVT   */
/*                 peut  être  désactivé  par  l’intermédiaire  du  booléen   */
/*                 VlvSys_bPresExServo_C dans le cas où le moteur n’est pas   */
/*                 équipé d’un système VVT à l’échappement.                   */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02167_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVEXSPMGT_vidVlvEx();                                   */
/*  input boolean VlvSys_bPresExServo_C;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVEXSPMGT_vidVlvExEna(void)
{
   if (VlvSys_bPresExServo_C != 0)
   {
      VLVEXSPMGT_vidVlvEx();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVEXSPMGT_vidVlvEx                                        */
/* !Description :  Ce bloc permet d'élaborer les consignes VVT à appliquer au */
/*                 système en fonction des modes de combustions. Les modes de */
/*                 combustion tiennent compte de l'état moteur (chaud/froid,  */
/*                 chauffe catalyseur, anticipation du ralenti, ...)          */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02167_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVEXSPMGT_vidUnvectorize_Mode();                        */
/*  extf argret void VLVEXSPMGT_vidMode_Mask();                               */
/*  extf argret void VLVEXSPMGT_vidCalibrations();                            */
/*  extf argret void VLVEXSPMGT_vidSelect_Modes();                            */
/*  extf argret void VLVEXSPMGT_vidInterpolation();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVEXSPMGT_vidVlvEx(void)
{
   VLVEXSPMGT_vidUnvectorize_Mode();
   VLVEXSPMGT_vidMode_Mask();
   VLVEXSPMGT_vidCalibrations();
   VLVEXSPMGT_vidSelect_Modes();
   VLVEXSPMGT_vidInterpolation();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVEXSPMGT_vidUnvectorize_Mode                             */
/* !Description :  Ce  bloc  permet  de  récupérer  les  informations  servant*/
/*                  à  l'élaboration  des  consignes  VVT    et  provenant  du*/
/*                 gestionnaire de modes de combustion.                       */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02167_006.02                                     */
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
/*  output uint8 VlvSys_idxBas1ModCurClsEx;                                   */
/*  output uint8 VlvSys_idxBas2ModCurClsEx;                                   */
/*  output uint8 VlvSys_idxBas1ModTarClsEx;                                   */
/*  output uint8 VlvSys_idxBas2ModTarClsEx;                                   */
/*  output uint8 VlvSys_facBasModCurClsEx;                                    */
/*  output uint8 VlvSys_facBasModTarClsEx;                                    */
/*  output uint8 VlvSys_facTranModClsEx;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVEXSPMGT_vidUnvectorize_Mode(void)
{
   uint8 u8LocalVlvSys_idxBas1ModCurClsEx;
   uint8 u8LocalVlvSys_idxBas2ModCurClsEx;
   uint8 u8LocalVlvSys_idxBas1ModTarClsEx;
   uint8 u8LocalVlvSys_idxBas2ModTarClsEx;
   uint8 u8LocalVlvSys_facBasModCurClsEx;
   uint8 u8LocalVlvSys_facBasModTarClsEx;
   uint8 u8LocalVlvSys_facTranModClsEx;


   if (VlvSys_bAcvOEMBedMod_C != 0)
   {
      u8LocalVlvSys_idxBas1ModCurClsEx = VlvSys_idxBas1ModCurBedMod_C;
      u8LocalVlvSys_idxBas2ModCurClsEx = VlvSys_idxBas2ModCurBedMod_C;
      u8LocalVlvSys_idxBas1ModTarClsEx = VlvSys_idxBas1ModTarBedMod_C;
      u8LocalVlvSys_idxBas2ModTarClsEx = VlvSys_idxBas2ModTarBedMod_C;
      u8LocalVlvSys_facBasModCurClsEx = VlvSys_facBasModCurBedMod_C;
      u8LocalVlvSys_facBasModTarClsEx = VlvSys_facBasModTarBedMod_C;
      u8LocalVlvSys_facTranModClsEx = VlvSys_facTranModBedMod_C;
   }
   else
   {
      VEMS_vidGET1DArrayElement(EOM_prm_idxBas1ModCur,
                                4,
                                u8LocalVlvSys_idxBas1ModCurClsEx);
      VEMS_vidGET1DArrayElement(EOM_prm_idxBas2ModCur,
                                4,
                                u8LocalVlvSys_idxBas2ModCurClsEx);
      VEMS_vidGET1DArrayElement(EOM_prm_idxBas1ModTar,
                                4,
                                u8LocalVlvSys_idxBas1ModTarClsEx);
      VEMS_vidGET1DArrayElement(EOM_prm_idxBas2ModTar,
                                4,
                                u8LocalVlvSys_idxBas2ModTarClsEx);
      VEMS_vidGET1DArrayElement(EOM_prm_facBasModCur,
                                4,
                                u8LocalVlvSys_facBasModCurClsEx);
      u8LocalVlvSys_facBasModCurClsEx =
         (uint8)(((u8LocalVlvSys_facBasModCurClsEx * 25) + 16) / 32);

      VEMS_vidGET1DArrayElement(EOM_prm_facBasModTar,
                                4,
                                u8LocalVlvSys_facBasModTarClsEx);
      u8LocalVlvSys_facBasModTarClsEx =
         (uint8)(((u8LocalVlvSys_facBasModTarClsEx * 25) + 16) / 32);

      VEMS_vidGET1DArrayElement(EOM_prm_facTranMod,
                                4,
                                u8LocalVlvSys_facTranModClsEx);
      u8LocalVlvSys_facTranModClsEx =
         (uint8)(((u8LocalVlvSys_facTranModClsEx * 25) + 16) / 32);
   }
   VlvSys_idxBas1ModCurClsEx =
      (uint8)MATHSRV_udtCLAMP(u8LocalVlvSys_idxBas1ModCurClsEx, 1, 18);
   VlvSys_idxBas2ModCurClsEx =
      (uint8)MATHSRV_udtCLAMP(u8LocalVlvSys_idxBas2ModCurClsEx, 1, 18);
   VlvSys_idxBas1ModTarClsEx =
      (uint8)MATHSRV_udtCLAMP(u8LocalVlvSys_idxBas1ModTarClsEx, 1, 18);
   VlvSys_idxBas2ModTarClsEx =
      (uint8)MATHSRV_udtCLAMP(u8LocalVlvSys_idxBas2ModTarClsEx, 1, 18);
   VlvSys_facBasModCurClsEx =
      (uint8)MATHSRV_udtMIN(u8LocalVlvSys_facBasModCurClsEx, 100);
   VlvSys_facBasModTarClsEx =
      (uint8)MATHSRV_udtMIN(u8LocalVlvSys_facBasModTarClsEx, 100);
   VlvSys_facTranModClsEx =
      (uint8)MATHSRV_udtMIN(u8LocalVlvSys_facTranModClsEx, 100);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVEXSPMGT_vidMode_Mask                                    */
/* !Description :  Ce bloc a pour but de concaténer sur un seul flux          */
/*                 l'ensemble des modes de combustion activés par le          */
/*                 gestionnaire.                                              */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02167_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 VlvSys_idxBas1ModCurClsEx;                                    */
/*  input uint8 VlvSys_idxBas2ModCurClsEx;                                    */
/*  input uint8 VlvSys_idxBas1ModTarClsEx;                                    */
/*  input uint8 VlvSys_idxBas2ModTarClsEx;                                    */
/*  output boolean VlvSys_prm_bAcvClsExCal[18];                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVEXSPMGT_vidMode_Mask(void)
{
   uint8 u8LocalIndex;
   uint8 u8LocalIdx1ModCur;
   uint8 u8LocalIdx2ModCur;
   uint8 u8LocalIdx1ModTar;
   uint8 u8LocalIdx2ModTar;


   u8LocalIdx1ModCur =
      (uint8)MATHSRV_udtCLAMP(VlvSys_idxBas1ModCurClsEx, 1, 18);

   u8LocalIdx2ModCur =
      (uint8)MATHSRV_udtCLAMP(VlvSys_idxBas2ModCurClsEx, 1, 18);

   u8LocalIdx1ModTar =
      (uint8)MATHSRV_udtCLAMP(VlvSys_idxBas1ModTarClsEx, 1, 18);

   u8LocalIdx2ModTar =
      (uint8)MATHSRV_udtCLAMP(VlvSys_idxBas2ModTarClsEx, 1, 18);

   for(u8LocalIndex = 0; u8LocalIndex <= 17; u8LocalIndex++)
   {
      VlvSys_prm_bAcvClsExCal[u8LocalIndex] = 0;
   }

   VlvSys_prm_bAcvClsExCal[u8LocalIdx1ModCur - 1] = 1;
   VlvSys_prm_bAcvClsExCal[u8LocalIdx2ModCur - 1] = 1;
   VlvSys_prm_bAcvClsExCal[u8LocalIdx1ModTar - 1] = 1;
   VlvSys_prm_bAcvClsExCal[u8LocalIdx2ModTar - 1] = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVEXSPMGT_vidCalibrations                                 */
/* !Description :  Ce bloc permet d'effectuer uniquement  les calculs des     */
/*                 cartographies correspondants aux modes de combustion       */
/*                 activés.                                                   */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02167_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVEXSPMGT_vidUnvect_Activ_Bool();                       */
/*  extf argret void VLVEXSPMGT_vidCalibration_1();                           */
/*  extf argret void VLVEXSPMGT_vidCalibration_2();                           */
/*  extf argret void VLVEXSPMGT_vidCalibration_3();                           */
/*  extf argret void VLVEXSPMGT_vidCalibration_4();                           */
/*  extf argret void VLVEXSPMGT_vidCalibration_5();                           */
/*  extf argret void VLVEXSPMGT_vidCalibration_6();                           */
/*  extf argret void VLVEXSPMGT_vidCalibration_7();                           */
/*  extf argret void VLVEXSPMGT_vidCalibration_8();                           */
/*  extf argret void VLVEXSPMGT_vidCalibration_9();                           */
/*  extf argret void VLVEXSPMGT_vidCalibration_10();                          */
/*  extf argret void VLVEXSPMGT_vidCalibration_11();                          */
/*  extf argret void VLVEXSPMGT_vidCalibration_12();                          */
/*  extf argret void VLVEXSPMGT_vidCalibration_13();                          */
/*  extf argret void VLVEXSPMGT_vidCalibration_14();                          */
/*  extf argret void VLVEXSPMGT_vidCalibration_15();                          */
/*  extf argret void VLVEXSPMGT_vidCalibration_16();                          */
/*  extf argret void VLVEXSPMGT_vidCalibration_17();                          */
/*  extf argret void VLVEXSPMGT_vidCalibration_18();                          */
/*  extf argret void VLVEXSPMGT_vidVectorize_Calibs();                        */
/*  input boolean VlvSys_bAcvClsExCal1;                                       */
/*  input boolean VlvSys_bAcvClsExCal2;                                       */
/*  input boolean VlvSys_bAcvClsExCal3;                                       */
/*  input boolean VlvSys_bAcvClsExCal4;                                       */
/*  input boolean VlvSys_bAcvClsExCal5;                                       */
/*  input boolean VlvSys_bAcvClsExCal6;                                       */
/*  input boolean VlvSys_bAcvClsExCal7;                                       */
/*  input boolean VlvSys_bAcvClsExCal8;                                       */
/*  input boolean VlvSys_bAcvClsExCal9;                                       */
/*  input boolean VlvSys_bAcvClsExCal10;                                      */
/*  input boolean VlvSys_bAcvClsExCal11;                                      */
/*  input boolean VlvSys_bAcvClsExCal12;                                      */
/*  input boolean VlvSys_bAcvClsExCal13;                                      */
/*  input boolean VlvSys_bAcvClsExCal14;                                      */
/*  input boolean VlvSys_bAcvClsExCal15;                                      */
/*  input boolean VlvSys_bAcvClsExCal16;                                      */
/*  input boolean VlvSys_bAcvClsExCal17;                                      */
/*  input boolean VlvSys_bAcvClsExCal18;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVEXSPMGT_vidCalibrations(void)
{
   VLVEXSPMGT_vidUnvect_Activ_Bool();
   if (VlvSys_bAcvClsExCal1 != 0)
   {
      VLVEXSPMGT_vidCalibration_1();
   }
   if (VlvSys_bAcvClsExCal2 != 0)
   {
      VLVEXSPMGT_vidCalibration_2();
   }
   if (VlvSys_bAcvClsExCal3 != 0)
   {
      VLVEXSPMGT_vidCalibration_3();
   }
   if (VlvSys_bAcvClsExCal4 != 0)
   {
      VLVEXSPMGT_vidCalibration_4();
   }
   if (VlvSys_bAcvClsExCal5 != 0)
   {
      VLVEXSPMGT_vidCalibration_5();
   }
   if (VlvSys_bAcvClsExCal6 != 0)
   {
      VLVEXSPMGT_vidCalibration_6();
   }
   if (VlvSys_bAcvClsExCal7 != 0)
   {
      VLVEXSPMGT_vidCalibration_7();
   }
   if (VlvSys_bAcvClsExCal8 != 0)
   {
      VLVEXSPMGT_vidCalibration_8();
   }
   if (VlvSys_bAcvClsExCal9 != 0)
   {
      VLVEXSPMGT_vidCalibration_9();
   }
   if (VlvSys_bAcvClsExCal10 != 0)
   {
      VLVEXSPMGT_vidCalibration_10();
   }
   if (VlvSys_bAcvClsExCal11 != 0)
   {
      VLVEXSPMGT_vidCalibration_11();
   }
   if (VlvSys_bAcvClsExCal12 != 0)
   {
      VLVEXSPMGT_vidCalibration_12();
   }
   if (VlvSys_bAcvClsExCal13 != 0)
   {
      VLVEXSPMGT_vidCalibration_13();
   }
   if (VlvSys_bAcvClsExCal14 != 0)
   {
      VLVEXSPMGT_vidCalibration_14();
   }
   if (VlvSys_bAcvClsExCal15 != 0)
   {
      VLVEXSPMGT_vidCalibration_15();
   }
   if (VlvSys_bAcvClsExCal16 != 0)
   {
      VLVEXSPMGT_vidCalibration_16();
   }
   if (VlvSys_bAcvClsExCal17 != 0)
   {
      VLVEXSPMGT_vidCalibration_17();
   }
   if (VlvSys_bAcvClsExCal18 != 0)
   {
      VLVEXSPMGT_vidCalibration_18();
   }
   VLVEXSPMGT_vidVectorize_Calibs();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVEXSPMGT_vidSelect_Modes                                 */
/* !Description :  Ce bloc permet de récupérer les consignes VVT              */
/*                 correspondantes aux modes de combustion.                   */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02167_029.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 VlvSys_idxBas1ModCurClsEx;                                    */
/*  input sint8 VlvSys_prm_agCkClsExCal[18];                                  */
/*  input uint8 VlvSys_idxBas2ModCurClsEx;                                    */
/*  input uint8 VlvSys_idxBas1ModTarClsEx;                                    */
/*  input uint8 VlvSys_idxBas2ModTarClsEx;                                    */
/*  output sint8 VlvSys_agCkClsExBas1ModCur;                                  */
/*  output sint8 VlvSys_agCkClsExBas2ModCur;                                  */
/*  output sint8 VlvSys_agCkClsExBas1ModTar;                                  */
/*  output sint8 VlvSys_agCkClsExBas2ModTar;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVEXSPMGT_vidSelect_Modes(void)
{
   uint8  u8LocalIndex;
   uint8  u8LocalVlvSys_idxBas1ModCurClsEx;
   uint8  u8LocalVlvSys_idxBas2ModCurClsEx;
   uint8  u8LocalVlvSys_idxBas1ModTarClsEx;
   uint8  u8LocalVlvSys_idxBas2ModTarClsEx;
   sint8  s8LocalVlvSys_prm_agCkClsExCal;


   u8LocalVlvSys_idxBas1ModCurClsEx =
      (uint8)MATHSRV_udtCLAMP(VlvSys_idxBas1ModCurClsEx, 1, 18);
   u8LocalIndex = (uint8)(u8LocalVlvSys_idxBas1ModCurClsEx - 1);

   s8LocalVlvSys_prm_agCkClsExCal = VlvSys_prm_agCkClsExCal[u8LocalIndex];
   VlvSys_agCkClsExBas1ModCur = s8LocalVlvSys_prm_agCkClsExCal;

   u8LocalVlvSys_idxBas2ModCurClsEx =
      (uint8)MATHSRV_udtCLAMP(VlvSys_idxBas2ModCurClsEx, 1, 18);
   u8LocalIndex = (uint8)(u8LocalVlvSys_idxBas2ModCurClsEx - 1);
   s8LocalVlvSys_prm_agCkClsExCal = VlvSys_prm_agCkClsExCal[u8LocalIndex];
   VlvSys_agCkClsExBas2ModCur = s8LocalVlvSys_prm_agCkClsExCal;

   u8LocalVlvSys_idxBas1ModTarClsEx =
      (uint8)MATHSRV_udtCLAMP(VlvSys_idxBas1ModTarClsEx, 1, 18);
   u8LocalIndex = (uint8)(u8LocalVlvSys_idxBas1ModTarClsEx - 1);
   s8LocalVlvSys_prm_agCkClsExCal = VlvSys_prm_agCkClsExCal[u8LocalIndex];
   VlvSys_agCkClsExBas1ModTar = s8LocalVlvSys_prm_agCkClsExCal;

   u8LocalVlvSys_idxBas2ModTarClsEx =
      (uint8)MATHSRV_udtCLAMP(VlvSys_idxBas2ModTarClsEx, 1, 18);
   u8LocalIndex = (uint8)(u8LocalVlvSys_idxBas2ModTarClsEx - 1);
   s8LocalVlvSys_prm_agCkClsExCal = VlvSys_prm_agCkClsExCal[u8LocalIndex];
   VlvSys_agCkClsExBas2ModTar = s8LocalVlvSys_prm_agCkClsExCal;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVEXSPMGT_vidInterpolation                                */
/* !Description :  Ce bloc permet d'effectuer un barycentre sur  les          */
/*                 différentes consignes VVT correspondantes à chaque mode de */
/*                 combustion afin d'assurer les transitions entre modes de   */
/*                 combustion.                                                */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02167_030.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 VlvSys_facBasModTarClsEx;                                     */
/*  input sint8 VlvSys_agCkClsExBas1ModTar;                                   */
/*  input sint8 VlvSys_agCkClsExBas2ModTar;                                   */
/*  input uint8 VlvSys_facBasModCurClsEx;                                     */
/*  input sint8 VlvSys_agCkClsExBas1ModCur;                                   */
/*  input sint8 VlvSys_agCkClsExBas2ModCur;                                   */
/*  input uint8 VlvSys_facTranModClsEx;                                       */
/*  output sint8 VlvSys_agCkClsExVlvReq;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVEXSPMGT_vidInterpolation(void)
{
   uint8  u8LocalDiff;
   sint8  s8LocalVlvSys_agCkClsExVlvReq;
   sint16 s16LocalModTar;
   sint16 s16LocalModCur;
   sint16 s16LocalProd1;
   sint16 s16LocalProd2;
   sint16 s16LocalVlvSys_agCkClsExVlvReq;
   sint32 s32LocalProd1;
   sint32 s32LocalProd2;


   /*Barycentre 1 */
   if (  (VlvSys_facBasModTarClsEx > 0)
      && (VlvSys_facBasModTarClsEx < 100))
   {
      s16LocalProd1 =
         (sint16)(VlvSys_agCkClsExBas1ModTar * VlvSys_facBasModTarClsEx);
      u8LocalDiff = (uint8)(100 - VlvSys_facBasModTarClsEx);
      s16LocalProd2 = (sint16)(VlvSys_agCkClsExBas2ModTar * u8LocalDiff);
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
      if (VlvSys_facBasModTarClsEx == 0)
      {
         s16LocalModTar = (sint16)VlvSys_agCkClsExBas2ModTar;
      }
      else
      {
         s16LocalModTar = (sint16)VlvSys_agCkClsExBas1ModTar;
      }
   }

   /* Barycentre 2 */
   if (  (VlvSys_facBasModCurClsEx > 0)
      && (VlvSys_facBasModCurClsEx < 100))
   {
      s16LocalProd1 =
         (sint16)(VlvSys_agCkClsExBas1ModCur * VlvSys_facBasModCurClsEx);
      u8LocalDiff = (uint8)(100 - VlvSys_facBasModCurClsEx);
      s16LocalProd2 = (sint16)(VlvSys_agCkClsExBas2ModCur * u8LocalDiff);
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
      if (VlvSys_facBasModCurClsEx == 0)
      {
         s16LocalModCur = (sint16)VlvSys_agCkClsExBas2ModCur;
      }
      else
      {
         s16LocalModCur = (sint16)VlvSys_agCkClsExBas1ModCur;
      }
   }

   /* Barycentre 3 */
   if (  (VlvSys_facTranModClsEx > 0)
      && (VlvSys_facTranModClsEx < 100))
   {
      s32LocalProd1 = (s16LocalModTar * VlvSys_facTranModClsEx);
      u8LocalDiff = (uint8)(100 - VlvSys_facTranModClsEx);
      s32LocalProd2 = (s16LocalModCur * u8LocalDiff);
      s16LocalVlvSys_agCkClsExVlvReq = (sint16)(s32LocalProd1 + s32LocalProd2);
      if (s16LocalVlvSys_agCkClsExVlvReq < 0)
      {
         s16LocalVlvSys_agCkClsExVlvReq =
            (sint16)((s16LocalVlvSys_agCkClsExVlvReq - 50) / 100);
      }
      else
      {
         s16LocalVlvSys_agCkClsExVlvReq =
            (sint16)((s16LocalVlvSys_agCkClsExVlvReq + 50) / 100);
      }
   }
   else
   {
      if (VlvSys_facTranModClsEx == 0)
      {
         s16LocalVlvSys_agCkClsExVlvReq = s16LocalModCur;
      }
      else
      {
         s16LocalVlvSys_agCkClsExVlvReq = s16LocalModTar;
      }
   }
   s8LocalVlvSys_agCkClsExVlvReq = (sint8)s16LocalVlvSys_agCkClsExVlvReq;
   VEMS_vidSET(VlvSys_agCkClsExVlvReq, s8LocalVlvSys_agCkClsExVlvReq);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVEXSPMGT_vidUnvect_Activ_Bool                            */
/* !Description :  Ce bloc sert à dévectoriser le flux contenant l'ensemble   */
/*                 des modes de combustion activés.                           */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02167_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean VlvSys_prm_bAcvClsExCal[18];                                */
/*  output boolean VlvSys_bAcvClsExCal1;                                      */
/*  output boolean VlvSys_bAcvClsExCal2;                                      */
/*  output boolean VlvSys_bAcvClsExCal3;                                      */
/*  output boolean VlvSys_bAcvClsExCal4;                                      */
/*  output boolean VlvSys_bAcvClsExCal5;                                      */
/*  output boolean VlvSys_bAcvClsExCal6;                                      */
/*  output boolean VlvSys_bAcvClsExCal7;                                      */
/*  output boolean VlvSys_bAcvClsExCal8;                                      */
/*  output boolean VlvSys_bAcvClsExCal9;                                      */
/*  output boolean VlvSys_bAcvClsExCal10;                                     */
/*  output boolean VlvSys_bAcvClsExCal11;                                     */
/*  output boolean VlvSys_bAcvClsExCal12;                                     */
/*  output boolean VlvSys_bAcvClsExCal13;                                     */
/*  output boolean VlvSys_bAcvClsExCal14;                                     */
/*  output boolean VlvSys_bAcvClsExCal15;                                     */
/*  output boolean VlvSys_bAcvClsExCal16;                                     */
/*  output boolean VlvSys_bAcvClsExCal17;                                     */
/*  output boolean VlvSys_bAcvClsExCal18;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVEXSPMGT_vidUnvect_Activ_Bool(void)
{
   if (VlvSys_prm_bAcvClsExCal[0] != 0)
   {
      VlvSys_bAcvClsExCal1 = 1;
   }
   else
   {
      VlvSys_bAcvClsExCal1 = 0;
   }
   if (VlvSys_prm_bAcvClsExCal[1] != 0)
   {
      VlvSys_bAcvClsExCal2 = 1;
   }
   else
   {
      VlvSys_bAcvClsExCal2 = 0;
   }
   if (VlvSys_prm_bAcvClsExCal[2] != 0)
   {
      VlvSys_bAcvClsExCal3 = 1;
   }
   else
   {
      VlvSys_bAcvClsExCal3 = 0;
   }
   if (VlvSys_prm_bAcvClsExCal[3] != 0)
   {
      VlvSys_bAcvClsExCal4 = 1;
   }
   else
   {
      VlvSys_bAcvClsExCal4 = 0;
   }
   if (VlvSys_prm_bAcvClsExCal[4] != 0)
   {
      VlvSys_bAcvClsExCal5 = 1;
   }
   else
   {
      VlvSys_bAcvClsExCal5 = 0;
   }
   if (VlvSys_prm_bAcvClsExCal[5] != 0)
   {
      VlvSys_bAcvClsExCal6 = 1;
   }
   else
   {
      VlvSys_bAcvClsExCal6 = 0;
   }
   if (VlvSys_prm_bAcvClsExCal[6] != 0)
   {
      VlvSys_bAcvClsExCal7 = 1;
   }
   else
   {
      VlvSys_bAcvClsExCal7 = 0;
   }
   if (VlvSys_prm_bAcvClsExCal[7] != 0)
   {
      VlvSys_bAcvClsExCal8 = 1;
   }
   else
   {
      VlvSys_bAcvClsExCal8 = 0;
   }
   if (VlvSys_prm_bAcvClsExCal[8] != 0)
   {
      VlvSys_bAcvClsExCal9 = 1;
   }
   else
   {
      VlvSys_bAcvClsExCal9 = 0;
   }
   if (VlvSys_prm_bAcvClsExCal[9] != 0)
   {
      VlvSys_bAcvClsExCal10 = 1;
   }
   else
   {
      VlvSys_bAcvClsExCal10 = 0;
   }
   if (VlvSys_prm_bAcvClsExCal[10] != 0)
   {
      VlvSys_bAcvClsExCal11 = 1;
   }
   else
   {
      VlvSys_bAcvClsExCal11 = 0;
   }
   if (VlvSys_prm_bAcvClsExCal[11] != 0)
   {
      VlvSys_bAcvClsExCal12 = 1;
   }
   else
   {
      VlvSys_bAcvClsExCal12 = 0;
   }
   if (VlvSys_prm_bAcvClsExCal[12] != 0)
   {
      VlvSys_bAcvClsExCal13 = 1;
   }
   else
   {
      VlvSys_bAcvClsExCal13 = 0;
   }
   if (VlvSys_prm_bAcvClsExCal[13] != 0)
   {
      VlvSys_bAcvClsExCal14 = 1;
   }
   else
   {
      VlvSys_bAcvClsExCal14 = 0;
   }
   if (VlvSys_prm_bAcvClsExCal[14] != 0)
   {
      VlvSys_bAcvClsExCal15 = 1;
   }
   else
   {
      VlvSys_bAcvClsExCal15 = 0;
   }
   if (VlvSys_prm_bAcvClsExCal[15] != 0)
   {
      VlvSys_bAcvClsExCal16 = 1;
   }
   else
   {
      VlvSys_bAcvClsExCal16 = 0;
   }
   if (VlvSys_prm_bAcvClsExCal[16] != 0)
   {
      VlvSys_bAcvClsExCal17 = 1;
   }
   else
   {
      VlvSys_bAcvClsExCal17 = 0;
   }
   if (VlvSys_prm_bAcvClsExCal[17] != 0)
   {
      VlvSys_bAcvClsExCal18 = 1;
   }
   else
   {
      VlvSys_bAcvClsExCal18 = 0;
   }
}

/*---------------------------------end of file--------------------------------*/