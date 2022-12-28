/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ADDONADVMIN                                             */
/* !Description     : ADDONADVMIN component                                   */
/*                                                                            */
/* !Module          : ADDONADVMIN                                             */
/* !Description     : Offset d'avance minimale                                */
/*                                                                            */
/* !File            : ADDONADVMIN_FCT3.c                                      */
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
/*   1 / ADDONADVMIN_vidVectorizeCalibs                                       */
/*   2 / ADDONADVMIN_vidSelect_Modes                                          */
/*   3 / ADDONADVMIN_vidInterpolation                                         */
/*                                                                            */
/* !Reference   : V02 NT 11 01472 / 01                                        */
/* !OtherRefs   : 01460_10_01466_2 / 01                                       */
/* !OtherRefs   : VEMS V02 ECU#058205                                         */
/* !OtherRefs   : VEMS V02 ECU#053831                                         */
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
#include "ADDONADVMIN.h"
#include "ADDONADVMIN_L.h"
#include "ADDONADVMIN_IM.h"
#include "VEMS.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMIN_vidVectorizeCalibs                             */
/* !Description :  Ce bloc permet de calculer l’offset d’avance minimale.     */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01472_021.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input sint16 IgSys_ofsAgIgMinCal1;                                        */
/*  input sint16 IgSys_ofsAgIgMinCal2;                                        */
/*  input sint16 IgSys_ofsAgIgMinCal3;                                        */
/*  input sint16 IgSys_ofsAgIgMinCal4;                                        */
/*  input sint16 IgSys_ofsAgIgMinCal5;                                        */
/*  input sint16 IgSys_ofsAgIgMinCal6;                                        */
/*  input sint16 IgSys_ofsAgIgMinCal7;                                        */
/*  input sint16 IgSys_ofsAgIgMinCal8;                                        */
/*  input sint16 IgSys_ofsAgIgMinCal9;                                        */
/*  input sint16 IgSys_ofsAgIgMinCal10;                                       */
/*  input sint16 IgSys_ofsAgIgMinCal11;                                       */
/*  input sint16 IgSys_ofsAgIgMinCal12;                                       */
/*  input sint16 IgSys_ofsAgIgMinCal13;                                       */
/*  input sint16 IgSys_ofsAgIgMinCal14;                                       */
/*  output sint16 IgSys_prm_ofsAgIgMin[14];                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMIN_vidVectorizeCalibs(void)
{
   IgSys_prm_ofsAgIgMin[0] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgMinCal1, -96, 159);
   IgSys_prm_ofsAgIgMin[1] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgMinCal2, -96, 159);
   IgSys_prm_ofsAgIgMin[2] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgMinCal3, -96, 159);
   IgSys_prm_ofsAgIgMin[3] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgMinCal4, -96, 159);
   IgSys_prm_ofsAgIgMin[4] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgMinCal5, -96, 159);
   IgSys_prm_ofsAgIgMin[5] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgMinCal6, -96, 159);
   IgSys_prm_ofsAgIgMin[6] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgMinCal7, -96, 159);
   IgSys_prm_ofsAgIgMin[7] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgMinCal8, -96, 159);
   IgSys_prm_ofsAgIgMin[8] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgMinCal9, -96, 159);
   IgSys_prm_ofsAgIgMin[9] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgMinCal10, -96, 159);
   IgSys_prm_ofsAgIgMin[10] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgMinCal11, -96, 159);
   IgSys_prm_ofsAgIgMin[11] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgMinCal12, -96, 159);
   IgSys_prm_ofsAgIgMin[12] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgMinCal13, -96, 159);
   IgSys_prm_ofsAgIgMin[13] =
      (sint16)MATHSRV_udtCLAMP(IgSys_ofsAgIgMinCal14, -96, 159);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMIN_vidSelect_Modes                                */
/* !Description :  Ce bloc permet de calculer l’offset d’avance minimale pour */
/*                 les modes courants et de consigne.                         */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01472_022.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 IgSys_idxOfsAgIgMinBas1ModCur;                                */
/*  input sint16 IgSys_prm_ofsAgIgMin[14];                                    */
/*  input uint8 IgSys_idxOfsAgIgMinBas2ModCur;                                */
/*  input uint8 IgSys_idxOfsAgIgMinBas1ModTar;                                */
/*  input uint8 IgSys_idxOfsAgIgMinBas2ModTar;                                */
/*  output sint16 IgSys_ofsAgIgMinBas1ModCur;                                 */
/*  output sint16 IgSys_ofsAgIgMinBas2ModCur;                                 */
/*  output sint16 IgSys_ofsAgIgMinBas1ModTar;                                 */
/*  output sint16 IgSys_ofsAgIgMinBas2ModTar;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMIN_vidSelect_Modes(void)
{
   uint8 u8LocalIndex;


   u8LocalIndex = (uint8)MATHSRV_udtCLAMP(IgSys_idxOfsAgIgMinBas1ModCur, 1, 14);
   u8LocalIndex = (uint8)(u8LocalIndex - 1);
   IgSys_ofsAgIgMinBas1ModCur =
      (sint16)MATHSRV_udtCLAMP(IgSys_prm_ofsAgIgMin[u8LocalIndex], -96, 159);

   u8LocalIndex = (uint8)MATHSRV_udtCLAMP(IgSys_idxOfsAgIgMinBas2ModCur, 1, 14);
   u8LocalIndex = (uint8)(u8LocalIndex - 1);
   IgSys_ofsAgIgMinBas2ModCur =
      (sint16)MATHSRV_udtCLAMP(IgSys_prm_ofsAgIgMin[u8LocalIndex], -96, 159);

   u8LocalIndex = (uint8)MATHSRV_udtCLAMP(IgSys_idxOfsAgIgMinBas1ModTar, 1, 14);
   u8LocalIndex = (uint8)(u8LocalIndex - 1);
   IgSys_ofsAgIgMinBas1ModTar =
      (sint16)MATHSRV_udtCLAMP(IgSys_prm_ofsAgIgMin[u8LocalIndex], -96, 159);

   u8LocalIndex = (uint8)MATHSRV_udtCLAMP(IgSys_idxOfsAgIgMinBas2ModTar, 1, 14);
   u8LocalIndex = (uint8)(u8LocalIndex - 1);
   IgSys_ofsAgIgMinBas2ModTar =
      (sint16)MATHSRV_udtCLAMP(IgSys_prm_ofsAgIgMin[u8LocalIndex], -96, 159);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ADDONADVMIN_vidInterpolation                               */
/* !Description :  Ce bloc permet d’interpoler l’offset d’avance minimale     */
/*                 entre les valeurs pour les modes courants et de consigne.  */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_11_01472_023.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 IgSys_facOfsAgIgMinBasModTar;                                 */
/*  input sint16 IgSys_ofsAgIgMinBas1ModTar;                                  */
/*  input sint16 IgSys_ofsAgIgMinBas2ModTar;                                  */
/*  input uint8 IgSys_facOfsAgIgMinBasModCur;                                 */
/*  input sint16 IgSys_ofsAgIgMinBas1ModCur;                                  */
/*  input sint16 IgSys_ofsAgIgMinBas2ModCur;                                  */
/*  input uint8 IgSys_facOfsAgIgMinTranMod;                                   */
/*  input sint16 IgSys_agIgCmbModOfsMinTar_MP;                                */
/*  input sint16 IgSys_agIgCmbModOfsMinCur_MP;                                */
/*  output sint16 IgSys_agIgCmbModOfsMinTar_MP;                               */
/*  output sint16 IgSys_agIgCmbModOfsMinCur_MP;                               */
/*  output sint16 IgSys_agIgCmbModOfsMinCmb;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ADDONADVMIN_vidInterpolation(void)
{
   sint16 s16LocalAgIgCmbModOfsMinTar_MP;
   sint16 s16LocalAgIgCmbModOfsMinCur_MP;
   sint16 s16LocalIgSys_agIgCmbModOfsMin;


   /* Computing 1st Barycenter */
   if (  (IgSys_facOfsAgIgMinBasModTar > 0)
      && (IgSys_facOfsAgIgMinBasModTar < 100))
   {
      s16LocalAgIgCmbModOfsMinTar_MP =
         (sint16)( ( (sint32)( IgSys_ofsAgIgMinBas1ModTar
                             * IgSys_facOfsAgIgMinBasModTar)
                   + (sint32)( IgSys_ofsAgIgMinBas2ModTar
                             * ( 100
                               - IgSys_facOfsAgIgMinBasModTar)))
                   / 100);
   }
   else
   {
      if (IgSys_facOfsAgIgMinBasModTar >= 100)
      {
         s16LocalAgIgCmbModOfsMinTar_MP = IgSys_ofsAgIgMinBas1ModTar;
      }
      else
      {
         s16LocalAgIgCmbModOfsMinTar_MP = IgSys_ofsAgIgMinBas2ModTar;
      }
   }

   IgSys_agIgCmbModOfsMinTar_MP =
      (sint16)MATHSRV_udtCLAMP(s16LocalAgIgCmbModOfsMinTar_MP, -96, 159);

   /* Computing 2nd Barycenter */
   if (  (IgSys_facOfsAgIgMinBasModCur > 0)
      && (IgSys_facOfsAgIgMinBasModCur < 100))
   {
      s16LocalAgIgCmbModOfsMinCur_MP =
         (sint16)( ( (sint32)( IgSys_ofsAgIgMinBas1ModCur
                             * IgSys_facOfsAgIgMinBasModCur)
                   + (sint32)( IgSys_ofsAgIgMinBas2ModCur
                             * ( 100
                               - IgSys_facOfsAgIgMinBasModCur)))
                   / 100);
   }
   else
   {
      if (IgSys_facOfsAgIgMinBasModCur >= 100)
      {
         s16LocalAgIgCmbModOfsMinCur_MP = IgSys_ofsAgIgMinBas1ModCur;
      }
      else
      {
         s16LocalAgIgCmbModOfsMinCur_MP = IgSys_ofsAgIgMinBas2ModCur;
      }
   }

   IgSys_agIgCmbModOfsMinCur_MP =
      (sint16)MATHSRV_udtCLAMP(s16LocalAgIgCmbModOfsMinCur_MP, -96, 159);

      /* Computing 3rd Barycenter */
   if (  (IgSys_facOfsAgIgMinTranMod > 0)
      && (IgSys_facOfsAgIgMinTranMod < 100))
   {
      s16LocalIgSys_agIgCmbModOfsMin =
         (sint16)( ( (sint32)( IgSys_agIgCmbModOfsMinTar_MP
                             * ( IgSys_facOfsAgIgMinTranMod
                               * 3))
                   + (sint32)( IgSys_agIgCmbModOfsMinCur_MP
                             * ( 300
                               - ( IgSys_facOfsAgIgMinTranMod
                                 * 3))))
                   / 200);
   }
   else
   {
      if (IgSys_facOfsAgIgMinTranMod >= 100)
      {
         s16LocalIgSys_agIgCmbModOfsMin =
            (sint16)((IgSys_agIgCmbModOfsMinTar_MP * 3) / 2);
      }
      else
      {
         s16LocalIgSys_agIgCmbModOfsMin =
            (sint16)((IgSys_agIgCmbModOfsMinCur_MP * 3) / 2);
      }
   }

   VEMS_vidSET(IgSys_agIgCmbModOfsMinCmb, s16LocalIgSys_agIgCmbModOfsMin);
}
/*---------------------------------end of file--------------------------------*/