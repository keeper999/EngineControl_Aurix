/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ADDONADVOPTM                                            */
/* !Description     : ADDONADVOPTM component                                  */
/*                                                                            */
/* !Module          : ADDONADVOPTM                                            */
/* !Description     : TRAITEMENT TRAME 34DH                                   */
/*                                                                            */
/* !File            : ADDONADVOPTM_FCT3.C                                     */
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
/*   1 / ADDONADVOPTM_vidCalibration_15                                       */
/*   2 / ADDONADVOPTM_vidCalibration_16                                       */
/*   3 / ADDONADVOPTM_vidCalibration_17                                       */
/*   4 / ADDONADVOPTM_vidVectorize_Calib                                      */
/*   5 / ADDONADVOPTM_vidSelect_Modes                                         */
/*   6 / ADDONADVOPTM_vidInterpolation                                        */
/*                                                                            */
/* !Reference   : V02 NT 11 01474 / 01                                        */
/* !OtherRefs   : 01460_10_04403_2 / 01                                       */
/* !OtherRefs   : VEMS V02 ECU#053829                                         */
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
#include "ADDONADVOPTM.h"
#include "ADDONADVOPTM_L.h"
#include "ADDONADVOPTM_IM.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVOPTM_vidCalibration_15                             */
/* !Description :  Cette fonction  contient une des cartographies de la       */
/*                 fonction. Il n’est calculé que lorsque le mode de          */
/*                 fonctionnement  courant ou celui de consigne nécessite une */
/*                 interpolation dans cette cartographie                      */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01474_021.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgOptmShoIdl_A[8];                            */
/*  input uint16 IgSys_rAirLdOfsAgIgOptmShoIdl_A[8];                          */
/*  input uint8 IgSys_ofsAgIgOptmCal15_M[8][8];                               */
/*  output sint16 IgSys_ofsAgIgOptmCal15;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVOPTM_vidCalibration_15(void)
{
   uint8   u8LocalInterp2;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalEngM_rAirLdCor;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);

   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(IgSys_nEngOfsAgIgOptmShoIdl_A,
                                                u16LocalExt_nEng,
                                                8);


   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(IgSys_rAirLdOfsAgIgOptmShoIdl_A,
                                                u16LocalEngM_rAirLdCor,
                                                8);

   u8LocalInterp2 = MATHSRV_u8Interp2d(&IgSys_ofsAgIgOptmCal15_M[0][0],
                                       u16LocalParaX,
                                       u16LocalParaY,
                                       8);

   IgSys_ofsAgIgOptmCal15 = (sint16)(u8LocalInterp2 - 96);
}



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVOPTM_vidCalibration_16                             */
/* !Description :  Cette fonction  contient une des cartographies de la       */
/*                 fonction. Il n’est calculé que lorsque le mode de          */
/*                 fonctionnement  courant ou celui de consigne nécessite une */
/*                 interpolation dans cette cartographie                      */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01474_022.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 EngM_rAirLdCor;                                              */
/*  input uint16 IgSys_nEngOfsAgIgOptmShoIdl_A[8];                            */
/*  input uint16 IgSys_rAirLdOfsAgIgOptmShoIdl_A[8];                          */
/*  input uint8 IgSys_ofsAgIgOptmCal16_M[8][8];                               */
/*  output sint16 IgSys_ofsAgIgOptmCal16;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVOPTM_vidCalibration_16(void)
{
   uint8   u8LocalInterp2;
   uint16  u16LocalExt_nEng;
   uint16  u16LocalEngM_rAirLdCor;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;


   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(EngM_rAirLdCor, u16LocalEngM_rAirLdCor);


   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(IgSys_nEngOfsAgIgOptmShoIdl_A,
                                                u16LocalExt_nEng,
                                                8);

   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(IgSys_rAirLdOfsAgIgOptmShoIdl_A,
                                                u16LocalEngM_rAirLdCor,
                                                8);

   u8LocalInterp2 = MATHSRV_u8Interp2d(&IgSys_ofsAgIgOptmCal16_M[0][0],
                                       u16LocalParaX,
                                       u16LocalParaY,
                                       8);

   IgSys_ofsAgIgOptmCal16 = (sint16)(u8LocalInterp2 - 96);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVOPTM_vidCalibration_17                             */
/* !Description :  Cette fonction  contient une des calibrations de la        */
/*                 fonction. Ce scalaire n’est calculé que lorsque le mode de */
/*                 fonctionnement courant ou celui de consigne nécessite un   */
/*                 appel de cette calibration.                                */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01474_023.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input sint16 IgSys_ofsAgIgOptmCal17_C;                                    */
/*  output sint16 IgSys_ofsAgIgOptmCal17;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVOPTM_vidCalibration_17(void)
{
   IgSys_ofsAgIgOptmCal17 =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgOptmCal17_C, -96, 159);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVOPTM_vidVectorize_Calib                            */
/* !Description :  Cette fonction  permet de calculer l’offset d’avance       */
/*                 optimale pour tous les modes.                              */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01474_024.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input sint16 IgSys_ofsAgIgOptmCal1;                                       */
/*  input sint16 IgSys_ofsAgIgOptmCal2;                                       */
/*  input sint16 IgSys_ofsAgIgOptmCal3;                                       */
/*  input sint16 IgSys_ofsAgIgOptmCal4;                                       */
/*  input sint16 IgSys_ofsAgIgOptmCal5;                                       */
/*  input sint16 IgSys_ofsAgIgOptmCal6;                                       */
/*  input sint16 IgSys_ofsAgIgOptmCal7;                                       */
/*  input sint16 IgSys_ofsAgIgOptmCal8;                                       */
/*  input sint16 IgSys_ofsAgIgOptmCal9;                                       */
/*  input sint16 IgSys_ofsAgIgOptmCal10;                                      */
/*  input sint16 IgSys_ofsAgIgOptmCal11;                                      */
/*  input sint16 IgSys_ofsAgIgOptmCal12;                                      */
/*  input sint16 IgSys_ofsAgIgOptmCal13;                                      */
/*  input sint16 IgSys_ofsAgIgOptmCal14;                                      */
/*  input sint16 IgSys_ofsAgIgOptmCal15;                                      */
/*  input sint16 IgSys_ofsAgIgOptmCal16;                                      */
/*  input sint16 IgSys_ofsAgIgOptmCal17;                                      */
/*  output sint16 IgSys_prm_ofsAgIgOptm[17];                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVOPTM_vidVectorize_Calib(void)
{

   IgSys_prm_ofsAgIgOptm[0] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgOptmCal1, -96, 159);
   IgSys_prm_ofsAgIgOptm[1] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgOptmCal2, -96, 159);
   IgSys_prm_ofsAgIgOptm[2] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgOptmCal3, -96, 159);
   IgSys_prm_ofsAgIgOptm[3] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgOptmCal4, -96, 159);
   IgSys_prm_ofsAgIgOptm[4] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgOptmCal5, -96, 159);
   IgSys_prm_ofsAgIgOptm[5] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgOptmCal6, -96, 159);
   IgSys_prm_ofsAgIgOptm[6] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgOptmCal7, -96, 159);
   IgSys_prm_ofsAgIgOptm[7] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgOptmCal8, -96, 159);
   IgSys_prm_ofsAgIgOptm[8] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgOptmCal9, -96, 159);
   IgSys_prm_ofsAgIgOptm[9] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgOptmCal10, -96, 159);
   IgSys_prm_ofsAgIgOptm[10] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgOptmCal11, -96, 159);
   IgSys_prm_ofsAgIgOptm[11] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgOptmCal12, -96, 159);
   IgSys_prm_ofsAgIgOptm[12] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgOptmCal13, -96, 159);
   IgSys_prm_ofsAgIgOptm[13] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgOptmCal14, -96, 159);
   IgSys_prm_ofsAgIgOptm[14] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgOptmCal15, -96, 159);
   IgSys_prm_ofsAgIgOptm[15] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgOptmCal16, -96, 159);
   IgSys_prm_ofsAgIgOptm[16] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgOptmCal17, -96, 159);

}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVOPTM_vidSelect_Modes                               */
/* !Description :  Cette fonction  permet de calculer l’offset d’avance       */
/*                 optimale pour les modes courants et de consigne.           */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01474_025.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 IgSys_idxOfsAgIgOpBas1ModCur;                                 */
/*  input sint16 IgSys_prm_ofsAgIgOptm[17];                                   */
/*  input uint8 IgSys_idxOfsAgIgOpBas2ModCur;                                 */
/*  input uint8 IgSys_idxOfsAgIgOpBas1ModTar;                                 */
/*  input uint8 IgSys_idxOfsAgIgOpBas2ModTar;                                 */
/*  output sint16 IgSys_ofsAgIgOptmBas1ModCur;                                */
/*  output sint16 IgSys_ofsAgIgOptmBas2ModCur;                                */
/*  output sint16 IgSys_ofsAgIgOptmBas1ModTar;                                */
/*  output sint16 IgSys_ofsAgIgOptmBas2ModTar;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVOPTM_vidSelect_Modes(void)
{
   uint8  u8LocalIdxOfsAgIgOpBas1ModCur;
   uint8  u8LocalIdxOfsAgIgOpBas2ModCur;
   uint8  u8LocalIdxOfsAgIgOpBas1ModTar;
   uint8  u8LocalIdxOfsAgIgOpBas2ModTar;
   sint16 s16LocalIgSys_ofsAgIgOptm;


   u8LocalIdxOfsAgIgOpBas1ModCur =
      (uint8)MATHSRV_udtCLAMP(IgSys_idxOfsAgIgOpBas1ModCur, 1, 17);
   u8LocalIdxOfsAgIgOpBas1ModCur = (uint8)(u8LocalIdxOfsAgIgOpBas1ModCur - 1);

   s16LocalIgSys_ofsAgIgOptm =
      IgSys_prm_ofsAgIgOptm[u8LocalIdxOfsAgIgOpBas1ModCur];

   IgSys_ofsAgIgOptmBas1ModCur =
      (sint16)MATHSRV_udtCLAMP(s16LocalIgSys_ofsAgIgOptm, -96, 159);


   u8LocalIdxOfsAgIgOpBas2ModCur =
      (uint8)MATHSRV_udtCLAMP(IgSys_idxOfsAgIgOpBas2ModCur, 1, 17);
   u8LocalIdxOfsAgIgOpBas2ModCur = (uint8)(u8LocalIdxOfsAgIgOpBas2ModCur - 1);

   s16LocalIgSys_ofsAgIgOptm =
      IgSys_prm_ofsAgIgOptm[u8LocalIdxOfsAgIgOpBas2ModCur];

   IgSys_ofsAgIgOptmBas2ModCur =
      (sint16)MATHSRV_udtCLAMP(s16LocalIgSys_ofsAgIgOptm, -96, 159);


   u8LocalIdxOfsAgIgOpBas1ModTar =
      (uint8)MATHSRV_udtCLAMP(IgSys_idxOfsAgIgOpBas1ModTar, 1, 17);
   u8LocalIdxOfsAgIgOpBas1ModTar = (uint8)(u8LocalIdxOfsAgIgOpBas1ModTar - 1);

   s16LocalIgSys_ofsAgIgOptm =
      IgSys_prm_ofsAgIgOptm[u8LocalIdxOfsAgIgOpBas1ModTar];

   IgSys_ofsAgIgOptmBas1ModTar =
      (sint16)MATHSRV_udtCLAMP(s16LocalIgSys_ofsAgIgOptm, -96, 159);


   u8LocalIdxOfsAgIgOpBas2ModTar =
      (uint8)MATHSRV_udtCLAMP(IgSys_idxOfsAgIgOpBas2ModTar, 1, 17);
   u8LocalIdxOfsAgIgOpBas2ModTar = (uint8)(u8LocalIdxOfsAgIgOpBas2ModTar - 1);

   s16LocalIgSys_ofsAgIgOptm =
      IgSys_prm_ofsAgIgOptm[u8LocalIdxOfsAgIgOpBas2ModTar];

   IgSys_ofsAgIgOptmBas2ModTar =
      (sint16)MATHSRV_udtCLAMP(s16LocalIgSys_ofsAgIgOptm, -96, 159);


}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVOPTM_vidInterpolation                              */
/* !Description :  Cette fonction  permet de calculer l’offset d’avance       */
/*                 optimale à partir des modes courants et de consigne.       */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01474_026.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 IgSys_facOfsAgIgOpBasModTar;                                  */
/*  input sint16 IgSys_ofsAgIgOptmBas1ModTar;                                 */
/*  input sint16 IgSys_ofsAgIgOptmBas2ModTar;                                 */
/*  input uint8 IgSys_facOfsAgIgOpBasModCur;                                  */
/*  input sint16 IgSys_ofsAgIgOptmBas1ModCur;                                 */
/*  input sint16 IgSys_ofsAgIgOptmBas2ModCur;                                 */
/*  input uint8 IgSys_facOfsAgIgOpTranMod;                                    */
/*  input sint16 IgSys_agIgCmbModOfsTar_MP;                                   */
/*  input sint16 IgSys_agIgCmbModOfsCur_MP;                                   */
/*  output sint16 IgSys_agIgCmbModOfsTar_MP;                                  */
/*  output sint16 IgSys_agIgCmbModOfsCur_MP;                                  */
/*  output uint8 IgSys_agIgCmbModOfs;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVOPTM_vidInterpolation(void)

{
   uint8  u8LocalIgSys_agIgCmbModOfs;
   sint16 s16LocalAgIgCmbModOfsTar_MP;
   sint16 s16LocalAgIgCmbModOfsCur_MP;
   sint16 s16LocalAgIgCmbModOfs;


  /* Computing 1st Barycenter */
   if (  (IgSys_facOfsAgIgOpBasModTar > 0)
      && (IgSys_facOfsAgIgOpBasModTar < 100))
   {
      s16LocalAgIgCmbModOfsTar_MP =
         (sint16)( ( (sint32)( IgSys_ofsAgIgOptmBas1ModTar
                             * IgSys_facOfsAgIgOpBasModTar)
                   + (sint32)( IgSys_ofsAgIgOptmBas2ModTar
                             * ( 100
                               - IgSys_facOfsAgIgOpBasModTar)))
                   / 100);
   }
   else
   {
      if (IgSys_facOfsAgIgOpBasModTar >= 100)
      {
         s16LocalAgIgCmbModOfsTar_MP = IgSys_ofsAgIgOptmBas1ModTar;
      }
      else
      {
         s16LocalAgIgCmbModOfsTar_MP = IgSys_ofsAgIgOptmBas2ModTar;
      }
   }

   IgSys_agIgCmbModOfsTar_MP =
      (sint16)MATHSRV_udtCLAMP(s16LocalAgIgCmbModOfsTar_MP, -96, 159);

   /* Computing 2nd Barycenter */
   if (  (IgSys_facOfsAgIgOpBasModCur > 0)
      && (IgSys_facOfsAgIgOpBasModCur < 100))
   {
      s16LocalAgIgCmbModOfsCur_MP =
         (sint16)( ( (sint32)( IgSys_ofsAgIgOptmBas1ModCur
                             * IgSys_facOfsAgIgOpBasModCur)
                   + (sint32)( IgSys_ofsAgIgOptmBas2ModCur
                             * ( 100
                               - IgSys_facOfsAgIgOpBasModCur)))
                   / 100);
   }
   else
   {
      if (IgSys_facOfsAgIgOpBasModCur >= 100)
      {
         s16LocalAgIgCmbModOfsCur_MP = IgSys_ofsAgIgOptmBas1ModCur;
      }
      else
      {
         s16LocalAgIgCmbModOfsCur_MP = IgSys_ofsAgIgOptmBas2ModCur;
      }
   }

   IgSys_agIgCmbModOfsCur_MP =
      (sint16)MATHSRV_udtCLAMP(s16LocalAgIgCmbModOfsCur_MP, -96, 159);

   /* Computing 3rd Barycenter */
   if (  (IgSys_facOfsAgIgOpTranMod > 0)
      && (IgSys_facOfsAgIgOpTranMod < 100))
   {
      s16LocalAgIgCmbModOfs =
         (sint16)( ( (sint32)( IgSys_agIgCmbModOfsTar_MP
                             * IgSys_facOfsAgIgOpTranMod)
                   + (sint32)( IgSys_agIgCmbModOfsCur_MP
                             * ( 100
                               - IgSys_facOfsAgIgOpTranMod)))
                   / 100);
   }
   else
   {
      if (IgSys_facOfsAgIgOpTranMod >= 100)
      {
         s16LocalAgIgCmbModOfs = IgSys_agIgCmbModOfsTar_MP;
      }
      else
      {
         s16LocalAgIgCmbModOfs = IgSys_agIgCmbModOfsCur_MP;
      }
   }
   u8LocalIgSys_agIgCmbModOfs = (uint8)(s16LocalAgIgCmbModOfs + 96);
   VEMS_vidSET(IgSys_agIgCmbModOfs, u8LocalIgSys_agIgCmbModOfs);
}

/*------------------------------end of file-----------------------------------*/