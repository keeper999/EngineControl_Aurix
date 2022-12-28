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
/* !File            : VVTSPLIMCORD_FCT3.C                                     */
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
/*   1 / VVTSPLIMCORD_vidVectorize_Calib                                      */
/*   2 / VVTSPLIMCORD_vidSelect_Modes                                         */
/*   3 / VVTSPLIMCORD_vidInterpolation                                        */
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
/* !Function    :  VVTSPLIMCORD_vidVectorize_Calib                            */
/* !Description :  Ce bloc permet de calculer l’offset de la température des  */
/*                 gaz d’échappement à la sortie culasse.                     */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_11_02903_021.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input sint16 ExM_tExOfsCal1;                                              */
/*  input sint16 ExM_tExOfsCal2;                                              */
/*  input sint16 ExM_tExOfsCal3;                                              */
/*  input sint16 ExM_tExOfsCal4;                                              */
/*  input sint16 ExM_tExOfsCal5;                                              */
/*  input sint16 ExM_tExOfsCal6;                                              */
/*  input sint16 ExM_tExOfsCal7;                                              */
/*  input sint16 ExM_tExOfsCal8;                                              */
/*  input sint16 ExM_tExOfsCal9;                                              */
/*  input sint16 ExM_tExOfsCal10;                                             */
/*  input sint16 ExM_tExOfsCal11;                                             */
/*  input sint16 ExM_tExOfsCal12;                                             */
/*  input sint16 ExM_tExOfsCal13;                                             */
/*  input sint16 ExM_tExOfsCal14;                                             */
/*  output sint16 ExM_prm_tExOfsCal[14];                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VVTSPLIMCORD_vidVectorize_Calib(void)
{
   ExM_prm_tExOfsCal[0] = ExM_tExOfsCal1;
   ExM_prm_tExOfsCal[1] = ExM_tExOfsCal2;
   ExM_prm_tExOfsCal[2] = ExM_tExOfsCal3;
   ExM_prm_tExOfsCal[3] = ExM_tExOfsCal4;
   ExM_prm_tExOfsCal[4] = ExM_tExOfsCal5;
   ExM_prm_tExOfsCal[5] = ExM_tExOfsCal6;
   ExM_prm_tExOfsCal[6] = ExM_tExOfsCal7;
   ExM_prm_tExOfsCal[7] = ExM_tExOfsCal8;
   ExM_prm_tExOfsCal[8] = ExM_tExOfsCal9;
   ExM_prm_tExOfsCal[9] = ExM_tExOfsCal10;
   ExM_prm_tExOfsCal[10] = ExM_tExOfsCal11;
   ExM_prm_tExOfsCal[11] = ExM_tExOfsCal12;
   ExM_prm_tExOfsCal[12] = ExM_tExOfsCal13;
   ExM_prm_tExOfsCal[13] = ExM_tExOfsCal14;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VVTSPLIMCORD_vidSelect_Modes                               */
/* !Description :  Ce bloc permet de calculer l’offset de la température des  */
/*                 gaz d’échappement à la sortie culasse pour les modes       */
/*                 courants et de consigne                                    */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_11_02903_022.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 ExM_idxBas1ModCur;                                            */
/*  input sint16 ExM_prm_tExOfsCal[14];                                       */
/*  input uint8 ExM_idxBas2ModCur;                                            */
/*  input uint8 ExM_idxBas1ModTar;                                            */
/*  input uint8 ExM_idxBas2ModTar;                                            */
/*  output sint16 ExM_tExOfsBas1ModCur;                                       */
/*  output sint16 ExM_tExOfsBas2ModCur;                                       */
/*  output sint16 ExM_tExOfsBas1ModTar;                                       */
/*  output sint16 ExM_tExOfsBas2ModTar;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VVTSPLIMCORD_vidSelect_Modes(void)
{
   uint8  u8LocalExM_idxBas1ModCur;
   uint8  u8LocalExM_idxBas2ModCur;
   uint8  u8LocalExM_idxBas1ModTar;
   uint8  u8LocalExM_idxBas2ModTar;


   u8LocalExM_idxBas1ModCur = (uint8)MATHSRV_udtCLAMP(ExM_idxBas1ModCur, 1, 14);
   ExM_tExOfsBas1ModCur = ExM_prm_tExOfsCal[u8LocalExM_idxBas1ModCur - 1];

   u8LocalExM_idxBas2ModCur = (uint8)MATHSRV_udtCLAMP(ExM_idxBas2ModCur, 1, 14);
   ExM_tExOfsBas2ModCur = ExM_prm_tExOfsCal[u8LocalExM_idxBas2ModCur - 1];

   u8LocalExM_idxBas1ModTar = (uint8)MATHSRV_udtCLAMP(ExM_idxBas1ModTar, 1, 14);
   ExM_tExOfsBas1ModTar = ExM_prm_tExOfsCal[u8LocalExM_idxBas1ModTar - 1];

   u8LocalExM_idxBas2ModTar = (uint8)MATHSRV_udtCLAMP(ExM_idxBas2ModTar, 1, 14);
   ExM_tExOfsBas2ModTar = ExM_prm_tExOfsCal[u8LocalExM_idxBas2ModTar - 1];
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VVTSPLIMCORD_vidInterpolation                              */
/* !Description :  Ce bloc permet d’interpoler l’offset de la température des */
/*                 gaz d’échappement à la sortie culasse entre les valeurs    */
/*                 pour les modes courants et de consigne.                    */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_11_02903_023.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 ExM_facBasModTar;                                             */
/*  input sint16 ExM_tExOfsBas1ModTar;                                        */
/*  input sint16 ExM_tExOfsBas2ModTar;                                        */
/*  input uint8 ExM_facBasModCur;                                             */
/*  input sint16 ExM_tExOfsBas1ModCur;                                        */
/*  input sint16 ExM_tExOfsBas2ModCur;                                        */
/*  input uint8 ExM_facTranMod;                                               */
/*  input sint16 ExM_tExOfsModTar_MP;                                         */
/*  input sint16 ExM_tExOfsModCur_MP;                                         */
/*  output sint16 ExM_tExOfsModTar_MP;                                        */
/*  output sint16 ExM_tExOfsModCur_MP;                                        */
/*  output sint16 ExM_tExOfs;                                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VVTSPLIMCORD_vidInterpolation(void)
{
   uint8  u8LocalDiff;
   sint16 s16LocalExM_tExOfs;
   sint32 s32LocalProd1;
   sint32 s32LocalProd2;
   sint32 s32LocalExM_tExOfs;
   sint32 s32LocalExM_tExOfsModTar_MP;
   sint32 s32LocalExM_tExOfsModCur_MP;


   /*Barycentre 1 */
   if (  (ExM_facBasModTar > 0)
      && (ExM_facBasModTar < 100))
   {
      s32LocalProd1 = (ExM_tExOfsBas1ModTar * ExM_facBasModTar);

      u8LocalDiff = (uint8)(100 - ExM_facBasModTar);
      s32LocalProd2 = (ExM_tExOfsBas2ModTar * u8LocalDiff);

      s32LocalExM_tExOfsModTar_MP = (s32LocalProd1 + s32LocalProd2);
      if (s32LocalExM_tExOfsModTar_MP > 0)
      {
         s32LocalExM_tExOfsModTar_MP = (s32LocalExM_tExOfsModTar_MP + 50) / 100;
      }
      else
      {
         s32LocalExM_tExOfsModTar_MP = (s32LocalExM_tExOfsModTar_MP - 50) / 100;
      }
      ExM_tExOfsModTar_MP = (sint16)s32LocalExM_tExOfsModTar_MP;
   }
   else
   {
      if (ExM_facBasModTar == 0)
      {
         ExM_tExOfsModTar_MP = ExM_tExOfsBas2ModTar;
      }
      else
      {
         ExM_tExOfsModTar_MP = ExM_tExOfsBas1ModTar;
      }
   }

   /* Barycentre 2 */
   if (  (ExM_facBasModCur > 0)
      && (ExM_facBasModCur < 100))
   {
      s32LocalProd1 = (ExM_tExOfsBas1ModCur * ExM_facBasModCur);

      u8LocalDiff = (uint8)(100 - ExM_facBasModCur);
      s32LocalProd2 = (ExM_tExOfsBas2ModCur * u8LocalDiff);

      s32LocalExM_tExOfsModCur_MP = (s32LocalProd1 + s32LocalProd2);
      if (s32LocalExM_tExOfsModCur_MP > 0)
      {
         s32LocalExM_tExOfsModCur_MP = (s32LocalExM_tExOfsModCur_MP + 50) / 100;
      }
      else
      {
         s32LocalExM_tExOfsModCur_MP = (s32LocalExM_tExOfsModCur_MP - 50) / 100;
      }
      ExM_tExOfsModCur_MP = (sint16)s32LocalExM_tExOfsModCur_MP;
   }
   else
   {
      if (ExM_facBasModCur == 0)
      {
         ExM_tExOfsModCur_MP = ExM_tExOfsBas2ModCur;
      }
      else
      {
         ExM_tExOfsModCur_MP = ExM_tExOfsBas1ModCur;
      }
   }

   /* Barycentre 3 */
   if (  (ExM_facTranMod > 0)
      && (ExM_facTranMod < 100))
   {
      s32LocalProd1 = (ExM_tExOfsModTar_MP * ExM_facTranMod);

      u8LocalDiff = (uint8)(100 - ExM_facTranMod);
      s32LocalProd2 = (ExM_tExOfsModCur_MP * u8LocalDiff);

      s32LocalExM_tExOfs = (s32LocalProd1 + s32LocalProd2);
      if (s32LocalExM_tExOfs > 0)
      {
         s32LocalExM_tExOfs = (s32LocalExM_tExOfs + 50) / 100;
      }
      else
      {
         s32LocalExM_tExOfs = (s32LocalExM_tExOfs - 50) / 100;
      }
   }
   else
   {
      if (ExM_facTranMod == 0)
      {
         s32LocalExM_tExOfs = ExM_tExOfsModCur_MP;
      }
      else
      {
         s32LocalExM_tExOfs = ExM_tExOfsModTar_MP;
      }
   }
   s32LocalExM_tExOfs = s32LocalExM_tExOfs - 1;
   s16LocalExM_tExOfs =
      (sint16)(MATHSRV_udtMAX(s32LocalExM_tExOfs,-32768));
   VEMS_vidSET(ExM_tExOfs, s16LocalExM_tExOfs);
}
/*---------------------------------end of file--------------------------------*/