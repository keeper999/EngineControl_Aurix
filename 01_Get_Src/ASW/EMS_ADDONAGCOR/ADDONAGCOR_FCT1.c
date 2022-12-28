/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ADDONAGCOR                                              */
/* !Description     : ADDONAGCOR Component                                    */
/*                                                                            */
/* !Module          : ADDONAGCOR                                              */
/* !Description     : DEFORMATION DE LA COURBE UNIQUE                         */
/*                                                                            */
/* !File            : ADDONAGCOR_FCT1.C                                       */
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
/*   1 / ADDONAGCOR_vidInitOutput                                             */
/*   2 / ADDONAGCOR_vidUnvectorize_Mode                                       */
/*   3 / ADDONAGCOR_vidMode_Mask                                              */
/*   4 / ADDONAGCOR_vidCalibrations                                           */
/*   5 / ADDONAGCOR_vidSel_T_utilisee                                         */
/*   6 / ADDONAGCOR_vidUnvectorz_Act_Bool                                     */
/*   7 / ADDONAGCOR_vidCalibration_1                                          */
/*   8 / ADDONAGCOR_vidCalibration_2                                          */
/*   9 / ADDONAGCOR_vidVectorize_Calib                                        */
/*   10 / ADDONAGCOR_vidSelect_Modes                                          */
/*                                                                            */
/* !Reference   : V02 NT 11 01473 / 01                                        */
/* !OtherRefs   : 01460_10_01467_2 / 01                                       */
/* !OtherRefs   : VEMS V02 ECU#054464                                         */
/* !OtherRefs   : VEMS V02 ECU#053827                                         */
/* !OtherRefs   : VEMS V02 ECU#058132                                         */
/* !OtherRefs   : VEMS V02 ECU#058205                                         */
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
#include "ADDONAGCOR.h"
#include "ADDONAGCOR_L.h"
#include "ADDONAGCOR_IM.h"
#include "VEMS.h"
#include "SWFAIL.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONAGCOR_vidInitOutput                                   */
/* !Description :  Fonction d'initialisation des sorties.                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 IgSys_facTarAgCor;                                          */
/*  output uint16 IgSys_facAgCorCal1;                                         */
/*  output uint16 IgSys_facAgCorCal2;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONAGCOR_vidInitOutput(void)
{
   VEMS_vidSET(IgSys_facTarAgCor, 256);
   IgSys_facAgCorCal1 = 0;
   IgSys_facAgCorCal2 = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONAGCOR_vidUnvectorize_Mode                             */
/* !Description :  Fonction de sélection des informations provenant du        */
/*                 gestionnaire de modes de combustion EOM                    */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01473_003.01                                     */
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
/*  output uint8 IgSys_idxFacAgCorBas1ModCur;                                 */
/*  output uint8 IgSys_idxFacAgCorBas2ModCur;                                 */
/*  output uint8 IgSys_idxFacAgCorBas1ModTar;                                 */
/*  output uint8 IgSys_idxFacAgCorBas2ModTar;                                 */
/*  output uint8 IgSys_facFacAgCorBasModCur;                                  */
/*  output uint8 IgSys_facFacAgCorBasModTar;                                  */
/*  output uint8 IgSys_facFacAgCorTranMod;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONAGCOR_vidUnvectorize_Mode(void)
{
   uint8 u8localBas1ModCur;
   uint8 u8localBas2ModCur;
   uint8 u8localBas1ModTar;
   uint8 u8localBas2ModTar;
   uint8 u8localfacBasModCur;
   uint8 u8localfacBasModTar;
   uint8 u8localfacTranMod;


   VEMS_vidGET1DArrayElement(EOM_prm_idxBas1ModCur,12,u8localBas1ModCur);
   VEMS_vidGET1DArrayElement(EOM_prm_idxBas2ModCur,12,u8localBas2ModCur);
   VEMS_vidGET1DArrayElement(EOM_prm_idxBas1ModTar,12,u8localBas1ModTar);
   VEMS_vidGET1DArrayElement(EOM_prm_idxBas2ModTar,12,u8localBas2ModTar);
   VEMS_vidGET1DArrayElement(EOM_prm_facBasModCur,12,u8localfacBasModCur);
   VEMS_vidGET1DArrayElement(EOM_prm_facBasModTar,12,u8localfacBasModTar);
   VEMS_vidGET1DArrayElement(EOM_prm_facTranMod,12,u8localfacTranMod);

   IgSys_idxFacAgCorBas1ModCur = (uint8)MATHSRV_udtCLAMP(u8localBas1ModCur,
                                                         1,
                                                         2);

   IgSys_idxFacAgCorBas2ModCur = (uint8)MATHSRV_udtCLAMP(u8localBas2ModCur,
                                                         1,
                                                         2);

   IgSys_idxFacAgCorBas1ModTar = (uint8)MATHSRV_udtCLAMP(u8localBas1ModTar,
                                                         1,
                                                         2);

   IgSys_idxFacAgCorBas2ModTar = (uint8)MATHSRV_udtCLAMP(u8localBas2ModTar,
                                                         1,
                                                         2);

   u8localfacBasModCur = (uint8)((u8localfacBasModCur * 25) / 32);
   u8localfacBasModTar = (uint8)((u8localfacBasModTar * 25) / 32);
   u8localfacTranMod = (uint8)((u8localfacTranMod * 25) / 32);
   IgSys_facFacAgCorBasModCur = (uint8)MATHSRV_udtMIN(u8localfacBasModCur, 100);
   IgSys_facFacAgCorBasModTar = (uint8)MATHSRV_udtMIN(u8localfacBasModTar, 100);
   IgSys_facFacAgCorTranMod = (uint8)MATHSRV_udtMIN(u8localfacTranMod, 100);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONAGCOR_vidMode_Mask                                    */
/* !Description :  Fonction de sélection de numéro des cartographies utiles   */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01473_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 IgSys_idxFacAgCorBas1ModCur;                                  */
/*  input uint8 IgSys_idxFacAgCorBas2ModCur;                                  */
/*  input uint8 IgSys_idxFacAgCorBas1ModTar;                                  */
/*  input uint8 IgSys_idxFacAgCorBas2ModTar;                                  */
/*  output boolean IgSys_prm_bAcvFacAgCorCal[2];                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONAGCOR_vidMode_Mask(void)
{
   uint8 u8LocalIndex;
   uint8 u8LocalIdx1ModCur;
   uint8 u8LocalIdx2ModCur;
   uint8 u8LocalIdx1ModTar;
   uint8 u8LocalIdx2ModTar;


   u8LocalIdx1ModCur = (uint8)MATHSRV_udtCLAMP(IgSys_idxFacAgCorBas1ModCur,
                                               1,
                                               2);

   u8LocalIdx2ModCur = (uint8)MATHSRV_udtCLAMP(IgSys_idxFacAgCorBas2ModCur,
                                               1,
                                               2);

   u8LocalIdx1ModTar = (uint8)MATHSRV_udtCLAMP(IgSys_idxFacAgCorBas1ModTar,
                                               1,
                                               2);

   u8LocalIdx2ModTar = (uint8)MATHSRV_udtCLAMP(IgSys_idxFacAgCorBas2ModTar,
                                               1,
                                               2);

   for(u8LocalIndex = 0; u8LocalIndex < 2; u8LocalIndex++)
   {
      IgSys_prm_bAcvFacAgCorCal[u8LocalIndex] = 0;
   }

   IgSys_prm_bAcvFacAgCorCal[u8LocalIdx1ModCur - 1] = 1;
   IgSys_prm_bAcvFacAgCorCal[u8LocalIdx2ModCur - 1] = 1;
   IgSys_prm_bAcvFacAgCorCal[u8LocalIdx1ModTar - 1] = 1;
   IgSys_prm_bAcvFacAgCorCal[u8LocalIdx2ModTar - 1] = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONAGCOR_vidCalibrations                                 */
/* !Description :  Fonction qui regroupe les différentes calibrations         */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01473_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ADDONAGCOR_vidSel_T_utilisee();                          */
/*  extf argret void ADDONAGCOR_vidUnvectorz_Act_Bool();                      */
/*  extf argret void ADDONAGCOR_vidCalibration_1();                           */
/*  extf argret void ADDONAGCOR_vidCalibration_2();                           */
/*  extf argret void ADDONAGCOR_vidVectorize_Calib();                         */
/*  input boolean IgSys_bAcvFacAgCorCal1;                                     */
/*  input boolean IgSys_bAcvFacAgCorCal2;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONAGCOR_vidCalibrations(void)
{
   ADDONAGCOR_vidSel_T_utilisee();
   ADDONAGCOR_vidUnvectorz_Act_Bool();
   if (IgSys_bAcvFacAgCorCal1 != 0)
   {
      ADDONAGCOR_vidCalibration_1();
   }
   if (IgSys_bAcvFacAgCorCal2 != 0)
   {
      ADDONAGCOR_vidCalibration_2();
   }
   ADDONAGCOR_vidVectorize_Calib();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONAGCOR_vidSel_T_utilisee                               */
/* !Description :  Fonction de sélection de la température à prendre en       */
/*                 compte.                                                    */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01473_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 IgSys_idxSelTUsr_C;                                           */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input sint16 Ext_tDsThrMes;                                               */
/*  input uint16 InThM_tAirUsInVlvEstim;                                      */
/*  output sint32 IgSys_tSelUsrFacAgCor;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONAGCOR_vidSel_T_utilisee(void)
{
   uint16 u16localInThM_tAirUsInVlvEstim;
   sint16 s16localExt_tCoMes;
   sint16 s16localExt_tDsThrMes;
   sint32 s32localsoustract;


   switch (IgSys_idxSelTUsr_C)
   {
      case 0:
         VEMS_vidGET(Ext_tCoMes, s16localExt_tCoMes);
         s32localsoustract = (sint32)(s16localExt_tCoMes * 128);
         break;

      case 1:
         VEMS_vidGET(Ext_tDsThrMes, s16localExt_tDsThrMes);
         s32localsoustract = (sint32)(s16localExt_tDsThrMes * 128);
         break;

      case 2:
         VEMS_vidGET(InThM_tAirUsInVlvEstim, u16localInThM_tAirUsInVlvEstim);
         s32localsoustract = (sint32)(u16localInThM_tAirUsInVlvEstim - 6400);
         break;

      default:
         VEMS_vidGET(InThM_tAirUsInVlvEstim, u16localInThM_tAirUsInVlvEstim);
         s32localsoustract = (sint32)(u16localInThM_tAirUsInVlvEstim - 6400);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
   IgSys_tSelUsrFacAgCor = MATHSRV_udtCLAMP(s32localsoustract, -6400, 59008);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONAGCOR_vidUnvectorz_Act_Bool                           */
/* !Description :  Fonction de démultiplication du flux de sélection des      */
/*                 cartographies utiles                                       */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01473_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean IgSys_prm_bAcvFacAgCorCal[2];                               */
/*  output boolean IgSys_bAcvFacAgCorCal1;                                    */
/*  output boolean IgSys_bAcvFacAgCorCal2;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONAGCOR_vidUnvectorz_Act_Bool(void)
{
   if(IgSys_prm_bAcvFacAgCorCal[0] != 0)
   {
      IgSys_bAcvFacAgCorCal1 = 1;
   }
   else
   {
      IgSys_bAcvFacAgCorCal1 = 0;
   }
   if(IgSys_prm_bAcvFacAgCorCal[1] != 0)
   {
      IgSys_bAcvFacAgCorCal2 = 1;
   }
   else
   {
      IgSys_bAcvFacAgCorCal2 = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONAGCOR_vidCalibration_1                                */
/* !Description :  Fonction appelée lorsque le mode de fonctionnement courant */
/*                 ou celui de consigne nécessite une interpolation dans la   */
/*                 cartographie de la fonction                                */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01473_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEng_FacAgCor_A[9];                                    */
/*  input uint16 IgSys_rAirLd_FacAgCor_A[9];                                  */
/*  input uint16 IgSys_facAgCorCal1_M[9][9];                                  */
/*  input sint32 IgSys_tSelUsrFacAgCor;                                       */
/*  input uint16 IgSys_tSelUsr_TarAgCor_A[9];                                 */
/*  input uint16 IgSys_facTarAgCor2Cal1_M[9][9];                              */
/*  output uint16 IgSys_facAgCorCal1;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONAGCOR_vidCalibration_1(void)
{
   uint16 u16LocalIgSys_facAgCorCal;
   uint16 u16LocalIgSys_facTarAgCor2Cal;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalParaX1;
   uint16 u16LocalParaX2;
   uint16 u16LocalParaY;
   uint16 u16LocaltSelUsrFacAgCor;
   uint32 u32LocalSOMMME;
   sint32 s32LocalIgSys;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);
   /*Map1*/
   u16LocalParaX1 = MATHSRV_u16CalcParaIncAryU16(IgSys_nEng_FacAgCor_A,
                                                 u16LocalExt_nEng,
                                                 9);

   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(IgSys_rAirLd_FacAgCor_A,
                                                u16LocalEngM_rAirLdCor,
                                                9);

   u16LocalIgSys_facAgCorCal = MATHSRV_u16Interp2d(&IgSys_facAgCorCal1_M[0][0],
                                                   u16LocalParaX1,
                                                   u16LocalParaY,
                                                   9);
   /*Map2*/
   s32LocalIgSys = MATHSRV_udtCLAMP(IgSys_tSelUsrFacAgCor, -6400, 59008);
   u16LocaltSelUsrFacAgCor = (uint16)(s32LocalIgSys + 6400);
   u16LocalParaX2 = MATHSRV_u16CalcParaIncAryU16(IgSys_tSelUsr_TarAgCor_A,
                                                 u16LocaltSelUsrFacAgCor,
                                                 9);

   u16LocalIgSys_facTarAgCor2Cal =
      MATHSRV_u16Interp2d(&IgSys_facTarAgCor2Cal1_M[0][0],
                          u16LocalParaX2,
                          u16LocalParaY,
                          9);
   /*Output*/
   u32LocalSOMMME =
      (uint32)(u16LocalIgSys_facAgCorCal + u16LocalIgSys_facTarAgCor2Cal);
   IgSys_facAgCorCal1 = (uint16)MATHSRV_udtMIN(u32LocalSOMMME, 512UL);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONAGCOR_vidCalibration_2                                */
/* !Description :  Fonction appelée lorsque le mode de fonctionnement courant */
/*                 ou celui de consigne nécessite une interpolation dans la   */
/*                 cartographie de la fonction                                */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01473_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEng_FacAgCor_A[9];                                    */
/*  input uint16 IgSys_rAirLd_FacAgCor_A[9];                                  */
/*  input uint16 IgSys_facAgCorCal2_M[9][9];                                  */
/*  input sint32 IgSys_tSelUsrFacAgCor;                                       */
/*  input uint16 IgSys_tSelUsr_TarAgCor_A[9];                                 */
/*  input uint16 IgSys_facTarAgCor2Cal2_M[9][9];                              */
/*  output uint16 IgSys_facAgCorCal2;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONAGCOR_vidCalibration_2(void)
{
   uint16 u16LocalIgSys_facAgCorCal2;
   uint16 u16LocalIgSys_facTarAgCor2Cal2;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalEngM_rAirLdCor;
   uint16 u16LocalParaX1;
   uint16 u16LocalParaX2;
   uint16 u16LocalParaY;
   uint16 u16LocaltSelUsrFacAgCor;
   uint32 u32LocalSOMMME;
   sint32 s32LocalIgSys;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);
   /*Map1*/
   u16LocalParaX1 = MATHSRV_u16CalcParaIncAryU16(IgSys_nEng_FacAgCor_A,
                                                 u16LocalExt_nEng,
                                                 9);

   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(IgSys_rAirLd_FacAgCor_A,
                                                u16LocalEngM_rAirLdCor,
                                                9);

   u16LocalIgSys_facAgCorCal2 = MATHSRV_u16Interp2d(&IgSys_facAgCorCal2_M[0][0],
                                                  u16LocalParaX1,
                                                  u16LocalParaY,
                                                  9);
   /*Map2*/
   s32LocalIgSys = MATHSRV_udtCLAMP(IgSys_tSelUsrFacAgCor, -6400, 59008);
   u16LocaltSelUsrFacAgCor = (uint16)(s32LocalIgSys + 6400);
   u16LocalParaX2 = MATHSRV_u16CalcParaIncAryU16(IgSys_tSelUsr_TarAgCor_A,
                                                 u16LocaltSelUsrFacAgCor,
                                                 9);

   u16LocalIgSys_facTarAgCor2Cal2 =
      MATHSRV_u16Interp2d(&IgSys_facTarAgCor2Cal2_M[0][0],
                          u16LocalParaX2,
                          u16LocalParaY,
                          9);
   /*Output*/
   u32LocalSOMMME =
      (uint32)(u16LocalIgSys_facAgCorCal2 + u16LocalIgSys_facTarAgCor2Cal2);
   IgSys_facAgCorCal2 = (uint16)MATHSRV_udtMIN(u32LocalSOMMME, 512);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONAGCOR_vidVectorize_Calib                              */
/* !Description :  Fonction de calcule de la valeur du coefficient de         */
/*                 déformation de la courbe de rendement d’avance pour les    */
/*                 différents modes.                                          */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01473_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 IgSys_facAgCorCal1;                                          */
/*  input uint16 IgSys_facAgCorCal2;                                          */
/*  output uint16 IgSys_prm_facAgCor[2];                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONAGCOR_vidVectorize_Calib(void)
{
   IgSys_prm_facAgCor[0] = (uint16)MATHSRV_udtMIN(IgSys_facAgCorCal1, 512);
   IgSys_prm_facAgCor[1] = (uint16)MATHSRV_udtMIN(IgSys_facAgCorCal2, 512);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONAGCOR_vidSelect_Modes                                 */
/* !Description :  Fonction de calcule des valeurs du coefficient de          */
/*                 déformation de la courbe de rendement d’avance pour les    */
/*                 modes courants et de consigne.                             */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01473_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 IgSys_idxFacAgCorBas1ModCur;                                  */
/*  input uint8 IgSys_idxFacAgCorBas2ModCur;                                  */
/*  input uint8 IgSys_idxFacAgCorBas1ModTar;                                  */
/*  input uint8 IgSys_idxFacAgCorBas2ModTar;                                  */
/*  input uint16 IgSys_prm_facAgCor[2];                                       */
/*  output uint16 IgSys_facAgCorBas1ModCur;                                   */
/*  output uint16 IgSys_facAgCorBas2ModCur;                                   */
/*  output uint16 IgSys_facAgCorBas1ModTar;                                   */
/*  output uint16 IgSys_facAgCorBas2ModTar;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONAGCOR_vidSelect_Modes(void)
{
   uint8  u8LocalIdx1ModCur;
   uint8  u8LocalIdx2ModCur;
   uint8  u8LocalIdx1ModTar;
   uint8  u8LocalIdx2ModTar;
   uint16 u16LocalIgSysfacAgCorBas1ModCur;
   uint16 u16LocalIgSysfacAgCorBas2ModCur;
   uint16 u16LocalIgSysfacAgCorBas1ModTar;
   uint16 u16LocalIgSysfacAgCorBas2ModTar;


   u8LocalIdx1ModCur = (uint8)MATHSRV_udtCLAMP(IgSys_idxFacAgCorBas1ModCur,
                                               1,
                                               2);

   u8LocalIdx2ModCur = (uint8)MATHSRV_udtCLAMP(IgSys_idxFacAgCorBas2ModCur,
                                                1,
                                                2);

   u8LocalIdx1ModTar = (uint8)MATHSRV_udtCLAMP(IgSys_idxFacAgCorBas1ModTar,
                                               1,
                                               2);

   u8LocalIdx2ModTar = (uint8)MATHSRV_udtCLAMP(IgSys_idxFacAgCorBas2ModTar,
                                               1,
                                               2);
   u16LocalIgSysfacAgCorBas1ModCur = IgSys_prm_facAgCor[u8LocalIdx1ModCur - 1];
   u16LocalIgSysfacAgCorBas2ModCur = IgSys_prm_facAgCor[u8LocalIdx2ModCur - 1];
   u16LocalIgSysfacAgCorBas1ModTar = IgSys_prm_facAgCor[u8LocalIdx1ModTar - 1];
   u16LocalIgSysfacAgCorBas2ModTar = IgSys_prm_facAgCor[u8LocalIdx2ModTar - 1];

   IgSys_facAgCorBas1ModCur =
      (uint16)MATHSRV_udtMIN(u16LocalIgSysfacAgCorBas1ModCur, 512);
   IgSys_facAgCorBas2ModCur =
      (uint16)MATHSRV_udtMIN(u16LocalIgSysfacAgCorBas2ModCur, 512);
   IgSys_facAgCorBas1ModTar =
      (uint16)MATHSRV_udtMIN(u16LocalIgSysfacAgCorBas1ModTar, 512);
   IgSys_facAgCorBas2ModTar =
      (uint16)MATHSRV_udtMIN(u16LocalIgSysfacAgCorBas2ModTar, 512);
}

/*------------------------------- end of file --------------------------------*/
