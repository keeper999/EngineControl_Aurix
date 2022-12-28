/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ADDONADVMAX                                             */
/* !Description     : ADDONADVMAX component                                   */
/*                                                                            */
/* !Module          : ADDONADVMAX                                             */
/* !Description     : Offset d'avance limite cliquetis                        */
/*                                                                            */
/* !File            : ADDONADVMAX_FCT3.C                                      */
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
/*   1 / ADDONADVMAX_vidVectorizeCalibs                                       */
/*   2 / ADDONADVMAX_vidSelect_Modes                                          */
/*   3 / ADDONADVMAX_vidInterpolation                                         */
/*                                                                            */
/* !Reference   : V02 NT 11 01471 / 01                                        */
/* !OtherRefs   : 01460_10_01465_2 / 01                                       */
/* !OtherRefs   : VEMS V02 ECU#053830                                         */
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
#include "ADDONADVMAX.h"
#include "ADDONADVMAX_L.h"
#include "ADDONADVMAX_IM.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMAX_vidVectorizeCalibs                             */
/* !Description :  Ce bloc permet de calculer l’offset d’avance maximale.     */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01471_021.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input sint16 IgSys_ofsAgIgMaxCal1;                                        */
/*  input sint16 IgSys_ofsAgIgMaxCal2;                                        */
/*  input sint16 IgSys_ofsAgIgMaxCal3;                                        */
/*  input sint16 IgSys_ofsAgIgMaxCal4;                                        */
/*  input sint16 IgSys_ofsAgIgMaxCal5;                                        */
/*  input sint16 IgSys_ofsAgIgMaxCal6;                                        */
/*  input sint16 IgSys_ofsAgIgMaxCal7;                                        */
/*  input sint16 IgSys_ofsAgIgMaxCal8;                                        */
/*  input sint16 IgSys_ofsAgIgMaxCal9;                                        */
/*  input sint16 IgSys_ofsAgIgMaxCal10;                                       */
/*  input sint16 IgSys_ofsAgIgMaxCal11;                                       */
/*  input sint16 IgSys_ofsAgIgMaxCal12;                                       */
/*  input sint16 IgSys_ofsAgIgMaxCal13;                                       */
/*  input sint16 IgSys_ofsAgIgMaxCal14;                                       */
/*  output sint16 IgSys_prm_ofsAgIgMax[14];                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMAX_vidVectorizeCalibs(void)
{
   IgSys_prm_ofsAgIgMax[0] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgMaxCal1, -96, 159);
   IgSys_prm_ofsAgIgMax[1] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgMaxCal2, -96, 159);
   IgSys_prm_ofsAgIgMax[2] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgMaxCal3, -96, 159);
   IgSys_prm_ofsAgIgMax[3] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgMaxCal4, -96, 159);
   IgSys_prm_ofsAgIgMax[4] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgMaxCal5, -96, 159);
   IgSys_prm_ofsAgIgMax[5] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgMaxCal6, -96, 159);
   IgSys_prm_ofsAgIgMax[6] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgMaxCal7, -96, 159);
   IgSys_prm_ofsAgIgMax[7] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgMaxCal8, -96, 159);
   IgSys_prm_ofsAgIgMax[8] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgMaxCal9, -96, 159);
   IgSys_prm_ofsAgIgMax[9] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgMaxCal10, -96, 159);
   IgSys_prm_ofsAgIgMax[10] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgMaxCal11, -96, 159);
   IgSys_prm_ofsAgIgMax[11] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgMaxCal12, -96, 159);
   IgSys_prm_ofsAgIgMax[12] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgMaxCal13, -96, 159);
   IgSys_prm_ofsAgIgMax[13] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgMaxCal14, -96, 159);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMAX_vidSelect_Modes                                */
/* !Description :  Ce bloc permet de calculer l’offset d’avance maximale pour */
/*                 les modes courants et de consigne.                         */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01471_022.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 IgSys_idxOfsAgIgMaxBas1ModCur;                                */
/*  input sint16 IgSys_prm_ofsAgIgMax[14];                                    */
/*  input uint8 IgSys_idxOfsAgIgMaxBas2ModCur;                                */
/*  input uint8 IgSys_idxOfsAgIgMaxBas1ModTar;                                */
/*  input uint8 IgSys_idxOfsAgIgMaxBas2ModTar;                                */
/*  output sint16 IgSys_ofsAgIgMaxBas1ModCur;                                 */
/*  output sint16 IgSys_ofsAgIgMaxBas2ModCur;                                 */
/*  output sint16 IgSys_ofsAgIgMaxBas1ModTar;                                 */
/*  output sint16 IgSys_ofsAgIgMaxBas2ModTar;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMAX_vidSelect_Modes(void)
{
   uint8 u8LocalIndex;


   u8LocalIndex = (uint8)MATHSRV_udtCLAMP(IgSys_idxOfsAgIgMaxBas1ModCur, 1, 14);
   u8LocalIndex = (uint8)(u8LocalIndex - 1);
   IgSys_ofsAgIgMaxBas1ModCur =
      (sint16)MATHSRV_udtCLAMP(IgSys_prm_ofsAgIgMax[u8LocalIndex], -96, 159);

   u8LocalIndex = (uint8)MATHSRV_udtCLAMP(IgSys_idxOfsAgIgMaxBas2ModCur, 1, 14);
   u8LocalIndex = (uint8)(u8LocalIndex - 1);
   IgSys_ofsAgIgMaxBas2ModCur =
      (sint16)MATHSRV_udtCLAMP(IgSys_prm_ofsAgIgMax[u8LocalIndex], -96, 159);

   u8LocalIndex = (uint8)MATHSRV_udtCLAMP(IgSys_idxOfsAgIgMaxBas1ModTar, 1, 14);
   u8LocalIndex = (uint8)(u8LocalIndex - 1);
   IgSys_ofsAgIgMaxBas1ModTar =
      (sint16)MATHSRV_udtCLAMP(IgSys_prm_ofsAgIgMax[u8LocalIndex], -96, 159);

   u8LocalIndex = (uint8)MATHSRV_udtCLAMP(IgSys_idxOfsAgIgMaxBas2ModTar, 1, 14);
   u8LocalIndex = (uint8)(u8LocalIndex - 1);
   IgSys_ofsAgIgMaxBas2ModTar =
      (sint16)MATHSRV_udtCLAMP(IgSys_prm_ofsAgIgMax[u8LocalIndex], -96, 159);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMAX_vidInterpolation                               */
/* !Description :  Ce bloc permet d’interpoler l’offset d’avance maximale     */
/*                 entre les valeurs pour les modes courants et de consigne.  */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01471_023.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 IgSys_facOfsAgIgMaxBasModTar;                                 */
/*  input sint16 IgSys_ofsAgIgMaxBas1ModTar;                                  */
/*  input sint16 IgSys_ofsAgIgMaxBas2ModTar;                                  */
/*  input uint8 IgSys_facOfsAgIgMaxBasModCur;                                 */
/*  input sint16 IgSys_ofsAgIgMaxBas1ModCur;                                  */
/*  input sint16 IgSys_ofsAgIgMaxBas2ModCur;                                  */
/*  input uint8 IgSys_facOfsAgIgMaxTranMod;                                   */
/*  input sint16 IgSys_agIgCmbModOfsMaxTar_MP;                                */
/*  input sint16 IgSys_agIgCmbModOfsMaxCur_MP;                                */
/*  output sint16 IgSys_agIgCmbModOfsMaxTar_MP;                               */
/*  output sint16 IgSys_agIgCmbModOfsMaxCur_MP;                               */
/*  output uint8 IgSys_agIgCmbModOfsMax;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMAX_vidInterpolation(void)
{
   uint8  u8LocalAgIgCmbModOfsMax;
   sint16 s16LocalAgIgCmbModOfsMaxTar_MP;
   sint16 s16LocalAgIgCmbModOfsMaxCur_MP;
   sint16 s16LocalAgIgCmbModOfsMax;


   /* Computing 1st Barycenter */
   if (  (IgSys_facOfsAgIgMaxBasModTar > 0)
      && (IgSys_facOfsAgIgMaxBasModTar < 100))
   {
      s16LocalAgIgCmbModOfsMaxTar_MP =
         (sint16)( ( (sint32)( IgSys_ofsAgIgMaxBas1ModTar
                             * IgSys_facOfsAgIgMaxBasModTar)
                   + (sint32)( IgSys_ofsAgIgMaxBas2ModTar
                             * ( 100
                               - IgSys_facOfsAgIgMaxBasModTar)))
                   / 100);
   }
   else
   {
      if (IgSys_facOfsAgIgMaxBasModTar >= 100)
      {
         s16LocalAgIgCmbModOfsMaxTar_MP = IgSys_ofsAgIgMaxBas1ModTar;
      }
      else
      {
         s16LocalAgIgCmbModOfsMaxTar_MP = IgSys_ofsAgIgMaxBas2ModTar;
      }
   }

   IgSys_agIgCmbModOfsMaxTar_MP =
      (sint16)MATHSRV_udtCLAMP(s16LocalAgIgCmbModOfsMaxTar_MP, -96, 159);

   /* Computing 2nd Barycenter */
   if (  (IgSys_facOfsAgIgMaxBasModCur > 0)
      && (IgSys_facOfsAgIgMaxBasModCur < 100))
   {
      s16LocalAgIgCmbModOfsMaxCur_MP =
         (sint16)( ( (sint32)( IgSys_ofsAgIgMaxBas1ModCur
                             * IgSys_facOfsAgIgMaxBasModCur)
                   + (sint32)( IgSys_ofsAgIgMaxBas2ModCur
                             * ( 100
                               - IgSys_facOfsAgIgMaxBasModCur)))
                   / 100);
   }
   else
   {
      if (IgSys_facOfsAgIgMaxBasModCur >= 100)
      {
         s16LocalAgIgCmbModOfsMaxCur_MP = IgSys_ofsAgIgMaxBas1ModCur;
      }
      else
      {
         s16LocalAgIgCmbModOfsMaxCur_MP = IgSys_ofsAgIgMaxBas2ModCur;
      }
   }

   IgSys_agIgCmbModOfsMaxCur_MP =
      (sint16)MATHSRV_udtCLAMP(s16LocalAgIgCmbModOfsMaxCur_MP, -96, 159);

   /* Computing 3rd Barycenter */
   if (  (IgSys_facOfsAgIgMaxTranMod > 0)
      && (IgSys_facOfsAgIgMaxTranMod < 100))
   {
      s16LocalAgIgCmbModOfsMax =
         (sint16)( ( (sint32)( IgSys_agIgCmbModOfsMaxTar_MP
                             * IgSys_facOfsAgIgMaxTranMod)
                   + (sint32)( IgSys_agIgCmbModOfsMaxCur_MP
                             * ( 100
                               - IgSys_facOfsAgIgMaxTranMod)))
                   / 100);
   }
   else
   {
      if (IgSys_facOfsAgIgMaxTranMod >= 100)
      {
         s16LocalAgIgCmbModOfsMax = IgSys_agIgCmbModOfsMaxTar_MP;
      }
      else
      {
         s16LocalAgIgCmbModOfsMax = IgSys_agIgCmbModOfsMaxCur_MP;
      }
   }

   u8LocalAgIgCmbModOfsMax = (uint8)(s16LocalAgIgCmbModOfsMax + 96);
   VEMS_vidSET(IgSys_agIgCmbModOfsMax, u8LocalAgIgCmbModOfsMax);
}
/*---------------------------------end of file--------------------------------*/