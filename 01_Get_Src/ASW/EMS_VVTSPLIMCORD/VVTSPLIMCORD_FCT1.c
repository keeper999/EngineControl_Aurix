/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VVTSPLIMCORD                                            */
/* !Description     : VVTSPLIMCORD component.                                 */
/*                                                                            */
/* !Module          : VVTSPLIMCORD                                            */
/* !Description     : OFFSET T3 SOUPAPE                                       */
/*                                                                            */
/* !File            : VVTSPLIMCORD_FCT1.C                                     */
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
/*   1 / VVTSPLIMCORD_vidInitOutput                                           */
/*   2 / VVTSPLIMCORD_vidExOfs                                                */
/*   3 / VVTSPLIMCORD_vidUnvectorize_Mode                                     */
/*   4 / VVTSPLIMCORD_vidMode_Mask                                            */
/*   5 / VVTSPLIMCORD_vidCalibrations                                         */
/*   6 / VVTSPLIMCORD_vidUnvect_Act_Bool                                      */
/*   7 / VVTSPLIMCORD_vidCalibration_1                                        */
/*   8 / VVTSPLIMCORD_vidCalibration_2                                        */
/*   9 / VVTSPLIMCORD_vidCalibration_3                                        */
/*   10 / VVTSPLIMCORD_vidCalibration_4                                       */
/*                                                                            */
/* !Reference   : V02 NT 11 02903 / 01                                        */
/* !OtherRefs   : 01460_10_01471_2 / 1                                        */
/* !OtherRefs   : VEMS V02 ECU#053815                                         */
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
#include "VVTSPLIMCORD.h"
#include "VVTSPLIMCORD_L.h"
#include "VVTSPLIMCORD_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VVTSPLIMCORD_vidInitOutput                                 */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output sint16 ExM_tExOfs;                                                 */
/*  output sint16 ExM_tExOfsCal1;                                             */
/*  output sint16 ExM_tExOfsCal2;                                             */
/*  output sint16 ExM_tExOfsCal3;                                             */
/*  output sint16 ExM_tExOfsCal4;                                             */
/*  output sint16 ExM_tExOfsCal5;                                             */
/*  output sint16 ExM_tExOfsCal6;                                             */
/*  output sint16 ExM_tExOfsCal7;                                             */
/*  output sint16 ExM_tExOfsCal8;                                             */
/*  output sint16 ExM_tExOfsCal9;                                             */
/*  output sint16 ExM_tExOfsCal10;                                            */
/*  output sint16 ExM_tExOfsCal11;                                            */
/*  output sint16 ExM_tExOfsCal12;                                            */
/*  output sint16 ExM_tExOfsCal13;                                            */
/*  output sint16 ExM_tExOfsCal14;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VVTSPLIMCORD_vidInitOutput(void)
{
   VEMS_vidSET(ExM_tExOfs, -1);
   ExM_tExOfsCal1 = 0;
   ExM_tExOfsCal2 = 0;
   ExM_tExOfsCal3 = 0;
   ExM_tExOfsCal4 = 0;
   ExM_tExOfsCal5 = 0;
   ExM_tExOfsCal6 = 0;
   ExM_tExOfsCal7 = 0;
   ExM_tExOfsCal8 = 0;
   ExM_tExOfsCal9 = 0;
   ExM_tExOfsCal10 = 0;
   ExM_tExOfsCal11 = 0;
   ExM_tExOfsCal12 = 0;
   ExM_tExOfsCal13 = 0;
   ExM_tExOfsCal14 = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VVTSPLIMCORD_vidExOfs                                      */
/* !Description :  La fonction est constituée de 5 blocs permettant de        */
/*                 calculer l’offset de la température des gaz d’échappement à*/
/*                 la sortie culasse.                                         */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_11_02903_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VVTSPLIMCORD_vidUnvectorize_Mode();                      */
/*  extf argret void VVTSPLIMCORD_vidMode_Mask();                             */
/*  extf argret void VVTSPLIMCORD_vidCalibrations();                          */
/*  extf argret void VVTSPLIMCORD_vidSelect_Modes();                          */
/*  extf argret void VVTSPLIMCORD_vidInterpolation();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VVTSPLIMCORD_vidExOfs(void)
{
   VVTSPLIMCORD_vidUnvectorize_Mode();
   VVTSPLIMCORD_vidMode_Mask();
   VVTSPLIMCORD_vidCalibrations();
   VVTSPLIMCORD_vidSelect_Modes();
   VVTSPLIMCORD_vidInterpolation();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VVTSPLIMCORD_vidUnvectorize_Mode                           */
/* !Description :  Ce bloc permet de sélectionner les informations provenant  */
/*                 du gestionnaire de modes de fonctionnements                */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_11_02903_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  input uint8 EOM_prm_idxBas1ModCur[16];                                    */
/*  input uint8 EOM_prm_idxBas2ModCur[16];                                    */
/*  input uint8 EOM_prm_idxBas1ModTar[16];                                    */
/*  input uint8 EOM_prm_idxBas2ModTar[16];                                    */
/*  input uint8 EOM_prm_facBasModCur[16];                                     */
/*  input uint8 EOM_prm_facBasModTar[16];                                     */
/*  input uint8 EOM_prm_facTranMod[16];                                       */
/*  output uint8 ExM_idxBas1ModCur;                                           */
/*  output uint8 ExM_idxBas2ModCur;                                           */
/*  output uint8 ExM_idxBas1ModTar;                                           */
/*  output uint8 ExM_idxBas2ModTar;                                           */
/*  output uint8 ExM_facBasModCur;                                            */
/*  output uint8 ExM_facBasModTar;                                            */
/*  output uint8 ExM_facTranMod;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VVTSPLIMCORD_vidUnvectorize_Mode(void)
{
   uint8 u8LocalIndex_Bas1ModCur;
   uint8 u8LocalIndex_Bas2ModCur;
   uint8 u8LocalIndexBas1ModTar;
   uint8 u8LocalIndexBas2ModTar;
   uint8 u8LocalIndexfacBasModCur;
   uint8 u8LocalIndexfacBasModTar;
   uint8 u8LocalIndexfacTranMod;


   VEMS_vidGET1DArrayElement(EOM_prm_idxBas1ModCur,
                             13,
                             u8LocalIndex_Bas1ModCur);
   ExM_idxBas1ModCur = (uint8)MATHSRV_udtCLAMP(u8LocalIndex_Bas1ModCur, 1, 14);

   VEMS_vidGET1DArrayElement(EOM_prm_idxBas2ModCur,
                             13,
                             u8LocalIndex_Bas2ModCur);
   ExM_idxBas2ModCur = (uint8)MATHSRV_udtCLAMP(u8LocalIndex_Bas2ModCur, 1, 14);

   VEMS_vidGET1DArrayElement(EOM_prm_idxBas1ModTar,
                             13,
                             u8LocalIndexBas1ModTar);
   ExM_idxBas1ModTar = (uint8)MATHSRV_udtCLAMP(u8LocalIndexBas1ModTar, 1, 14);

   VEMS_vidGET1DArrayElement(EOM_prm_idxBas2ModTar,
                             13,
                             u8LocalIndexBas2ModTar);
   ExM_idxBas2ModTar = (uint8)MATHSRV_udtCLAMP(u8LocalIndexBas2ModTar, 1, 14);

   VEMS_vidGET1DArrayElement(EOM_prm_facBasModCur,
                             13,
                             u8LocalIndexfacBasModCur);
   u8LocalIndexfacBasModCur = (uint8)((u8LocalIndexfacBasModCur * 25) / 32);
   ExM_facBasModCur = (uint8)MATHSRV_udtMIN(u8LocalIndexfacBasModCur, 100);
   VEMS_vidGET1DArrayElement(EOM_prm_facBasModTar,
                             13,
                             u8LocalIndexfacBasModTar);
   u8LocalIndexfacBasModTar = (uint8)((u8LocalIndexfacBasModTar * 25) / 32);
   ExM_facBasModTar = (uint8)MATHSRV_udtMIN(u8LocalIndexfacBasModTar, 100);
   VEMS_vidGET1DArrayElement(EOM_prm_facTranMod, 13, u8LocalIndexfacTranMod);
   u8LocalIndexfacTranMod = (uint8)((u8LocalIndexfacTranMod * 25) / 32);
   ExM_facTranMod = (uint8)MATHSRV_udtMIN(u8LocalIndexfacTranMod, 100);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VVTSPLIMCORD_vidMode_Mask                                  */
/* !Description :  Ce bloc permet de sélectionner le numéro des cartographies */
/*                 utiles                                                     */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_11_02903_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 ExM_idxBas1ModCur;                                            */
/*  input uint8 ExM_idxBas2ModCur;                                            */
/*  input uint8 ExM_idxBas1ModTar;                                            */
/*  input uint8 ExM_idxBas2ModTar;                                            */
/*  output boolean ExM_prm_bAcvTExOfsCal[14];                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VVTSPLIMCORD_vidMode_Mask(void)
{
   uint8 u8LocalIndex;
   uint8 u8LocalIdx1ModCur;
   uint8 u8LocalIdx2ModCur;
   uint8 u8LocalIdx1ModTar;
   uint8 u8LocalIdx2ModTar;


   u8LocalIdx1ModCur = (uint8)MATHSRV_udtCLAMP(ExM_idxBas1ModCur, 1, 14);

   u8LocalIdx2ModCur = (uint8)MATHSRV_udtCLAMP(ExM_idxBas2ModCur, 1, 14);

   u8LocalIdx1ModTar = (uint8)MATHSRV_udtCLAMP(ExM_idxBas1ModTar, 1, 14);

   u8LocalIdx2ModTar = (uint8)MATHSRV_udtCLAMP(ExM_idxBas2ModTar, 1, 14);

   for(u8LocalIndex = 0; u8LocalIndex <= 13; u8LocalIndex++)
   {
      ExM_prm_bAcvTExOfsCal[u8LocalIndex] = 0;
   }

   ExM_prm_bAcvTExOfsCal[u8LocalIdx1ModCur - 1] = 1;
   ExM_prm_bAcvTExOfsCal[u8LocalIdx2ModCur - 1] = 1;
   ExM_prm_bAcvTExOfsCal[u8LocalIdx1ModTar - 1] = 1;
   ExM_prm_bAcvTExOfsCal[u8LocalIdx2ModTar - 1] = 1;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VVTSPLIMCORD_vidCalibrations                               */
/* !Description :  Ce bloc regroupe les différentes calibrations de la        */
/*                 fonction                                                   */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_11_02903_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VVTSPLIMCORD_vidUnvect_Act_Bool();                       */
/*  extf argret void VVTSPLIMCORD_vidCalibration_1();                         */
/*  extf argret void VVTSPLIMCORD_vidCalibration_2();                         */
/*  extf argret void VVTSPLIMCORD_vidCalibration_3();                         */
/*  extf argret void VVTSPLIMCORD_vidCalibration_4();                         */
/*  extf argret void VVTSPLIMCORD_vidCalibration_5();                         */
/*  extf argret void VVTSPLIMCORD_vidCalibration_6();                         */
/*  extf argret void VVTSPLIMCORD_vidCalibration_7();                         */
/*  extf argret void VVTSPLIMCORD_vidCalibration_8();                         */
/*  extf argret void VVTSPLIMCORD_vidCalibration_9();                         */
/*  extf argret void VVTSPLIMCORD_vidCalibration_10();                        */
/*  extf argret void VVTSPLIMCORD_vidCalibration_11();                        */
/*  extf argret void VVTSPLIMCORD_vidCalibration_12();                        */
/*  extf argret void VVTSPLIMCORD_vidCalibration_13();                        */
/*  extf argret void VVTSPLIMCORD_vidCalibration_14();                        */
/*  extf argret void VVTSPLIMCORD_vidVectorize_Calib();                       */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input boolean ExM_bAcvTExOfsCal1;                                         */
/*  input boolean ExM_bAcvTExOfsCal2;                                         */
/*  input boolean ExM_bAcvTExOfsCal3;                                         */
/*  input boolean ExM_bAcvTExOfsCal4;                                         */
/*  input boolean ExM_bAcvTExOfsCal5;                                         */
/*  input boolean ExM_bAcvTExOfsCal6;                                         */
/*  input boolean ExM_bAcvTExOfsCal7;                                         */
/*  input boolean ExM_bAcvTExOfsCal8;                                         */
/*  input boolean ExM_bAcvTExOfsCal9;                                         */
/*  input boolean ExM_bAcvTExOfsCal10;                                        */
/*  input boolean ExM_bAcvTExOfsCal11;                                        */
/*  input boolean ExM_bAcvTExOfsCal12;                                        */
/*  input boolean ExM_bAcvTExOfsCal13;                                        */
/*  input boolean ExM_bAcvTExOfsCal14;                                        */
/*  output uint16 ExM_nEngCor;                                                */
/*  output uint16 ExM_rAirLdCor;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VVTSPLIMCORD_vidCalibrations(void)
{
   uint16 u16LocalExM_nEngCor;
   uint16 u16LocalExM_rAirLdCor;


   VEMS_vidGET(Ext_nEng, u16LocalExM_nEngCor);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalExM_rAirLdCor);
   ExM_nEngCor = (uint16)MATHSRV_udtMIN(u16LocalExM_nEngCor, 7500);
   ExM_rAirLdCor = (uint16)MATHSRV_udtMIN(u16LocalExM_rAirLdCor, 49152);

   VVTSPLIMCORD_vidUnvect_Act_Bool();

   if (ExM_bAcvTExOfsCal1 != 0)
   {
      VVTSPLIMCORD_vidCalibration_1();
   }
   if (ExM_bAcvTExOfsCal2 != 0)
   {
      VVTSPLIMCORD_vidCalibration_2();
   }
   if (ExM_bAcvTExOfsCal3 != 0)
   {
      VVTSPLIMCORD_vidCalibration_3();
   }
   if (ExM_bAcvTExOfsCal4 != 0)
   {
      VVTSPLIMCORD_vidCalibration_4();
   }
   if (ExM_bAcvTExOfsCal5 != 0)
   {
      VVTSPLIMCORD_vidCalibration_5();
   }
   if (ExM_bAcvTExOfsCal6 != 0)
   {
      VVTSPLIMCORD_vidCalibration_6();
   }
   if (ExM_bAcvTExOfsCal7 != 0)
   {
      VVTSPLIMCORD_vidCalibration_7();
   }
   if (ExM_bAcvTExOfsCal8 != 0)
   {
      VVTSPLIMCORD_vidCalibration_8();
   }
   if (ExM_bAcvTExOfsCal9 != 0)
   {
      VVTSPLIMCORD_vidCalibration_9();
   }
   if (ExM_bAcvTExOfsCal10 != 0)
   {
      VVTSPLIMCORD_vidCalibration_10();
   }
   if (ExM_bAcvTExOfsCal11 != 0)
   {
      VVTSPLIMCORD_vidCalibration_11();
   }
   if (ExM_bAcvTExOfsCal12 != 0)
   {
      VVTSPLIMCORD_vidCalibration_12();
   }
   if (ExM_bAcvTExOfsCal13 != 0)
   {
      VVTSPLIMCORD_vidCalibration_13();
   }
   if (ExM_bAcvTExOfsCal14 != 0)
   {
      VVTSPLIMCORD_vidCalibration_14();
   }

   VVTSPLIMCORD_vidVectorize_Calib();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VVTSPLIMCORD_vidUnvect_Act_Bool                            */
/* !Description :  Ce bloc permet la démultiplication des flux de sélection   */
/*                 des cartographies utiles.                                  */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_11_02903_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean ExM_prm_bAcvTExOfsCal[14];                                  */
/*  output boolean ExM_bAcvTExOfsCal1;                                        */
/*  output boolean ExM_bAcvTExOfsCal2;                                        */
/*  output boolean ExM_bAcvTExOfsCal3;                                        */
/*  output boolean ExM_bAcvTExOfsCal4;                                        */
/*  output boolean ExM_bAcvTExOfsCal5;                                        */
/*  output boolean ExM_bAcvTExOfsCal6;                                        */
/*  output boolean ExM_bAcvTExOfsCal7;                                        */
/*  output boolean ExM_bAcvTExOfsCal8;                                        */
/*  output boolean ExM_bAcvTExOfsCal9;                                        */
/*  output boolean ExM_bAcvTExOfsCal10;                                       */
/*  output boolean ExM_bAcvTExOfsCal11;                                       */
/*  output boolean ExM_bAcvTExOfsCal12;                                       */
/*  output boolean ExM_bAcvTExOfsCal13;                                       */
/*  output boolean ExM_bAcvTExOfsCal14;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VVTSPLIMCORD_vidUnvect_Act_Bool(void)
{
   if (ExM_prm_bAcvTExOfsCal[0] != 0)
   {
      ExM_bAcvTExOfsCal1 = 1;
   }
   else
   {
      ExM_bAcvTExOfsCal1 = 0;
   }
   if (ExM_prm_bAcvTExOfsCal[1] != 0)
   {
      ExM_bAcvTExOfsCal2 = 1;
   }
   else
   {
      ExM_bAcvTExOfsCal2 = 0;
   }
   if (ExM_prm_bAcvTExOfsCal[2] != 0)
   {
      ExM_bAcvTExOfsCal3 = 1;
   }
   else
   {
      ExM_bAcvTExOfsCal3 = 0;
   }
   if (ExM_prm_bAcvTExOfsCal[3] != 0)
   {
      ExM_bAcvTExOfsCal4 = 1;
   }
   else
   {
      ExM_bAcvTExOfsCal4 = 0;
   }
   if (ExM_prm_bAcvTExOfsCal[4] != 0)
   {
      ExM_bAcvTExOfsCal5 = 1;
   }
   else
   {
      ExM_bAcvTExOfsCal5 = 0;
   }
   if (ExM_prm_bAcvTExOfsCal[5] != 0)
   {
      ExM_bAcvTExOfsCal6 = 1;
   }
   else
   {
      ExM_bAcvTExOfsCal6 = 0;
   }
   if (ExM_prm_bAcvTExOfsCal[6] != 0)
   {
      ExM_bAcvTExOfsCal7 = 1;
   }
   else
   {
      ExM_bAcvTExOfsCal7 = 0;
   }
   if (ExM_prm_bAcvTExOfsCal[7] != 0)
   {
      ExM_bAcvTExOfsCal8 = 1;
   }
   else
   {
      ExM_bAcvTExOfsCal8 = 0;
   }
   if (ExM_prm_bAcvTExOfsCal[8] != 0)
   {
      ExM_bAcvTExOfsCal9 = 1;
   }
   else
   {
      ExM_bAcvTExOfsCal9 = 0;
   }
   if (ExM_prm_bAcvTExOfsCal[9] != 0)
   {
      ExM_bAcvTExOfsCal10 = 1;
   }
   else
   {
      ExM_bAcvTExOfsCal10 = 0;
   }
   if (ExM_prm_bAcvTExOfsCal[10] != 0)
   {
      ExM_bAcvTExOfsCal11 = 1;
   }
   else
   {
      ExM_bAcvTExOfsCal11 = 0;
   }
   if (ExM_prm_bAcvTExOfsCal[11] != 0)
   {
      ExM_bAcvTExOfsCal12 = 1;
   }
   else
   {
      ExM_bAcvTExOfsCal12 = 0;
   }
   if (ExM_prm_bAcvTExOfsCal[12] != 0)
   {
      ExM_bAcvTExOfsCal13 = 1;
   }
   else
   {
      ExM_bAcvTExOfsCal13 = 0;
   }
   if (ExM_prm_bAcvTExOfsCal[13] != 0)
   {
      ExM_bAcvTExOfsCal14 = 1;
   }
   else
   {
      ExM_bAcvTExOfsCal14 = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VVTSPLIMCORD_vidCalibration_1                              */
/* !Description :  Ce bloc contient une des cartographies de la fonction. Il  */
/*                 n’est calculé que lorsque le mode de fonctionnement courant*/
/*                 ou celui de consigne nécessite une interpolation dans cette*/
/*                 cartographie.                                              */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_11_02903_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 ExM_nEngCorX_A[8];                                           */
/*  input uint16 ExM_nEngCor;                                                 */
/*  input uint16 ExM_rAirCorY_A[8];                                           */
/*  input uint16 ExM_rAirLdCor;                                               */
/*  input uint8 ExM_tExOfsCal1_M[8][8];                                       */
/*  output sint16 ExM_tExOfsCal1;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VVTSPLIMCORD_vidCalibration_1(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;


   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(ExM_nEngCorX_A,
                                                    ExM_nEngCor,
                                                    8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(ExM_rAirCorY_A,
                                                    ExM_rAirLdCor,
                                                    8);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&ExM_tExOfsCal1_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                          8);
   ExM_tExOfsCal1 = (sint16)((u8LocalInterp2d - 128) * 32);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VVTSPLIMCORD_vidCalibration_2                              */
/* !Description :  Ce bloc contient une des cartographies de la fonction. Il  */
/*                 n’est calculé que lorsque le mode de fonctionnement courant*/
/*                 ou celui de consigne nécessite une interpolation dans cette*/
/*                 cartographie.                                              */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_11_02903_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 ExM_nEngCorX_A[8];                                           */
/*  input uint16 ExM_nEngCor;                                                 */
/*  input uint16 ExM_rAirCorY_A[8];                                           */
/*  input uint16 ExM_rAirLdCor;                                               */
/*  input uint8 ExM_tExOfsCal2_M[8][8];                                       */
/*  output sint16 ExM_tExOfsCal2;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VVTSPLIMCORD_vidCalibration_2(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;


   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(ExM_nEngCorX_A,
                                                    ExM_nEngCor,
                                                    8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(ExM_rAirCorY_A,
                                                    ExM_rAirLdCor,
                                                    8);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&ExM_tExOfsCal2_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);
   ExM_tExOfsCal2 = (sint16)((u8LocalInterp2d - 128) * 32);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VVTSPLIMCORD_vidCalibration_3                              */
/* !Description :  Ce bloc contient une des cartographies de la fonction. Il  */
/*                 n’est calculé que lorsque le mode de fonctionnement courant*/
/*                 ou celui de consigne nécessite une interpolation dans cette*/
/*                 cartographie.                                              */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_11_02903_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 ExM_nEngCorX_A[8];                                           */
/*  input uint16 ExM_nEngCor;                                                 */
/*  input uint16 ExM_rAirCorY_A[8];                                           */
/*  input uint16 ExM_rAirLdCor;                                               */
/*  input uint8 ExM_tExOfsCal3_M[8][8];                                       */
/*  output sint16 ExM_tExOfsCal3;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VVTSPLIMCORD_vidCalibration_3(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;


   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(ExM_nEngCorX_A,
                                                    ExM_nEngCor,
                                                    8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(ExM_rAirCorY_A,
                                                    ExM_rAirLdCor,
                                                    8);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&ExM_tExOfsCal3_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);
   ExM_tExOfsCal3 = (sint16)((u8LocalInterp2d - 128) * 32);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VVTSPLIMCORD_vidCalibration_4                              */
/* !Description :  Ce bloc contient une des cartographies de la fonction. Il  */
/*                 n’est calculé que lorsque le mode de fonctionnement courant*/
/*                 ou celui de consigne nécessite une interpolation dans cette*/
/*                 cartographie.                                              */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_11_02903_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 ExM_nEngCorX_A[8];                                           */
/*  input uint16 ExM_nEngCor;                                                 */
/*  input uint16 ExM_rAirCorY_A[8];                                           */
/*  input uint16 ExM_rAirLdCor;                                               */
/*  input uint8 ExM_tExOfsCal4_M[8][8];                                       */
/*  output sint16 ExM_tExOfsCal4;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VVTSPLIMCORD_vidCalibration_4(void)
{
   uint8  u8LocalInterp2d;
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;


   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(ExM_nEngCorX_A,
                                                    ExM_nEngCor,
                                                    8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(ExM_rAirCorY_A,
                                                    ExM_rAirLdCor,
                                                    8);
   u8LocalInterp2d = MATHSRV_u8Interp2d(&ExM_tExOfsCal4_M[0][0],
                                        u16LocalCalcParaX,
                                        u16LocalCalcParaY,
                                        8);
   ExM_tExOfsCal4 = (sint16)((u8LocalInterp2d - 128) * 32);
}
/*---------------------------------end of file--------------------------------*/