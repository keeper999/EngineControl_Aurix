/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IDLCMDMOD                                               */
/* !Description     : IDLCMDMOD Component                                     */
/*                                                                            */
/* !Module          : IDLCMDMOD                                               */
/* !Description     :  Consigne de régime de ralenti spécifique aux modes de  */
/*                    combustion essence                                      */
/*                                                                            */
/* !File            : IDLCMDMOD_FCT2.C                                        */
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
/*   1 / IDLCMDMOD_vidCalibration1                                            */
/*   2 / IDLCMDMOD_vidCalibration2                                            */
/*   3 / IDLCMDMOD_vidCalibration3                                            */
/*   4 / IDLCMDMOD_vidCalibration4                                            */
/*   5 / IDLCMDMOD_vidCalibration5                                            */
/*   6 / IDLCMDMOD_vidCalibration6                                            */
/*   7 / IDLCMDMOD_vidCalibration7                                            */
/*   8 / IDLCMDMOD_vidVectorizCalibration                                     */
/*                                                                            */
/* !Reference   : V02 NT 10 08588 / 02                                        */
/* !OtherRefs   : 01460_10_01430 / 1.1                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/IDLCMDMOD/IDLCMDM$*/
/* $Revision::   1.2      $$Author::   mbenfrad       $$Date::   06 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   06 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "IDLCMDMOD.h"
#include "IDLCMDMOD_L.h"
#include "IDLCMDMOD_IM.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCMDMOD_vidCalibration1                                  */
/* !Description :  Cette consigne de régime de ralenti est calculée pour le   */
/*                 mode de fonctionnement 1.                                  */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08588_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 TqSys_nIncTarIdlCmbMod1_C;                                   */
/*  input sint16 TqSys_nDecTarIdlCmbMod1_C;                                   */
/*  input boolean TqSys_bAcvNTarIdlCmbModEgd;                                 */
/*  input uint16 TqSys_nTarIdlCmbMod1Egd_C;                                   */
/*  input uint16 TqSys_nTarIdlCmbMod1Neut_C;                                  */
/*  input uint16 TqSys_nTarIdlCmbMod1;                                        */
/*  output uint16 TqSys_nTarIdlCmbMod1;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCMDMOD_vidCalibration1(void)
{
   uint16 u16LocalTqSysNIncMod1;
   uint16 u16LocalTqSysNDecMod1;
   uint16 u16LocalTqSysNTarIdlCmbMod1;
   uint16 u16LocalTqSys_nTarIdlCmbMod;
   uint32 u32LocalTqSysNTarIdlCmbMod1;
   sint16 s16LocalTqSysNDecMod1;


   u16LocalTqSysNIncMod1 = (uint16)(TqSys_nIncTarIdlCmbMod1_C / 25);
   s16LocalTqSysNDecMod1 = (sint16)MATHSRV_udtMIN(TqSys_nDecTarIdlCmbMod1_C, 0);
   u16LocalTqSysNDecMod1 = (uint16)(((-1) * s16LocalTqSysNDecMod1) / 25);

   if (TqSys_bAcvNTarIdlCmbModEgd != 0)
   {
      u32LocalTqSysNTarIdlCmbMod1 = (uint32)(TqSys_nTarIdlCmbMod1Egd_C * 4);
   }
   else
   {
      u32LocalTqSysNTarIdlCmbMod1 = (uint32)(TqSys_nTarIdlCmbMod1Neut_C * 4);
   }

   u16LocalTqSysNTarIdlCmbMod1 =
      (uint16)MATHSRV_udtMIN(u32LocalTqSysNTarIdlCmbMod1, 32000);

   u16LocalTqSys_nTarIdlCmbMod =
   MATHSRV_u16SlewFilter(  TqSys_nTarIdlCmbMod1,
                           u16LocalTqSysNTarIdlCmbMod1,
                           u16LocalTqSysNIncMod1,
                           u16LocalTqSysNDecMod1);
   TqSys_nTarIdlCmbMod1 =
      (uint16)MATHSRV_udtMIN(u16LocalTqSys_nTarIdlCmbMod, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCMDMOD_vidCalibration2                                  */
/* !Description :  Cette consigne de régime de ralenti est calculée pour le   */
/*                 mode de fonctionnement 2.                                  */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08588_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 TqSys_nIncTarIdlCmbMod2_C;                                   */
/*  input sint16 TqSys_nDecTarIdlCmbMod2_C;                                   */
/*  input boolean TqSys_bAcvNTarIdlCmbModEgd;                                 */
/*  input uint16 TqSys_nTarIdlCmbMod2Egd_C;                                   */
/*  input uint16 TqSys_nTarIdlCmbMod2Neut_C;                                  */
/*  input uint16 TqSys_nTarIdlCmbMod2;                                        */
/*  output uint16 TqSys_nTarIdlCmbMod2;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCMDMOD_vidCalibration2(void)
{
   uint16 u16LocalTqSysNIncMod2;
   uint16 u16LocalTqSysNDecMod2;
   uint16 u16LocalTqSysNTarIdlCmbMod2;
   uint16 u16LocalTqSys_nTarIdlCmbMod;
   uint32 u32LocalTqSysNTarIdlCmbMod2;
   sint16 s16LocalTqSysNDecMod2;


   u16LocalTqSysNIncMod2 = (uint16)(TqSys_nIncTarIdlCmbMod2_C / 25);
   s16LocalTqSysNDecMod2 = (sint16)MATHSRV_udtMIN(TqSys_nDecTarIdlCmbMod2_C, 0);
   u16LocalTqSysNDecMod2 = (uint16)(((-1) * s16LocalTqSysNDecMod2) / 25);

   if (TqSys_bAcvNTarIdlCmbModEgd != 0)
   {
      u32LocalTqSysNTarIdlCmbMod2 = (uint32)(TqSys_nTarIdlCmbMod2Egd_C * 4);
   }
   else
   {
      u32LocalTqSysNTarIdlCmbMod2 = (uint32)(TqSys_nTarIdlCmbMod2Neut_C * 4);
   }

   u16LocalTqSysNTarIdlCmbMod2 =
      (uint16)MATHSRV_udtMIN(u32LocalTqSysNTarIdlCmbMod2, 32000);

   u16LocalTqSys_nTarIdlCmbMod =
   MATHSRV_u16SlewFilter(  TqSys_nTarIdlCmbMod2,
                           u16LocalTqSysNTarIdlCmbMod2,
                           u16LocalTqSysNIncMod2,
                           u16LocalTqSysNDecMod2);
   TqSys_nTarIdlCmbMod2 =
      (uint16)MATHSRV_udtMIN(u16LocalTqSys_nTarIdlCmbMod, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCMDMOD_vidCalibration3                                  */
/* !Description :  Cette consigne de régime de ralenti est calculée pour le   */
/*                 mode de fonctionnement 3.                                  */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08588_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 TqSys_nIncTarIdlCmbMod3_C;                                   */
/*  input sint16 TqSys_nDecTarIdlCmbMod3_C;                                   */
/*  input boolean TqSys_bAcvNTarIdlCmbModEgd;                                 */
/*  input uint16 TqSys_nTarIdlCmbMod3Egd_C;                                   */
/*  input uint16 TqSys_nTarIdlCmbMod3Neut_C;                                  */
/*  input uint16 TqSys_nTarIdlCmbMod3;                                        */
/*  output uint16 TqSys_nTarIdlCmbMod3;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCMDMOD_vidCalibration3(void)
{
   uint16 u16LocalTqSysNIncMod3;
   uint16 u16LocalTqSysNDecMod3;
   uint16 u16LocalTqSysNTarIdlCmbMod3;
   uint16 u16LocalTqSys_nTarIdlCmbMod;
   uint32 u32LocalTqSysNTarIdlCmbMod3;
   sint16 s16LocalTqSysNDecMod3;


   u16LocalTqSysNIncMod3 = (uint16)(TqSys_nIncTarIdlCmbMod3_C / 25);
   s16LocalTqSysNDecMod3 = (sint16)MATHSRV_udtMIN(TqSys_nDecTarIdlCmbMod3_C, 0);
   u16LocalTqSysNDecMod3 = (uint16)(((-1) * s16LocalTqSysNDecMod3) / 25);

   if (TqSys_bAcvNTarIdlCmbModEgd != 0)
   {
      u32LocalTqSysNTarIdlCmbMod3 = (uint32)(TqSys_nTarIdlCmbMod3Egd_C * 4);
   }
   else
   {
      u32LocalTqSysNTarIdlCmbMod3 = (uint32)(TqSys_nTarIdlCmbMod3Neut_C * 4);
   }

   u16LocalTqSysNTarIdlCmbMod3 =
      (uint16)MATHSRV_udtMIN(u32LocalTqSysNTarIdlCmbMod3, 32000);

   u16LocalTqSys_nTarIdlCmbMod =
   MATHSRV_u16SlewFilter(  TqSys_nTarIdlCmbMod3,
                           u16LocalTqSysNTarIdlCmbMod3,
                           u16LocalTqSysNIncMod3,
                           u16LocalTqSysNDecMod3);
   TqSys_nTarIdlCmbMod3 =
      (uint16)MATHSRV_udtMIN(u16LocalTqSys_nTarIdlCmbMod, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCMDMOD_vidCalibration4                                  */
/* !Description :  Cette consigne de régime de ralenti est calculée pour le   */
/*                 mode de fonctionnement 4.                                  */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08588_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 TqSys_nIncTarIdlCmbMod4_C;                                   */
/*  input sint16 TqSys_nDecTarIdlCmbMod4_C;                                   */
/*  input boolean TqSys_bAcvNTarIdlCmbModEgd;                                 */
/*  input uint16 TqSys_nTarIdlCmbMod4Egd_C;                                   */
/*  input uint16 TqSys_nTarIdlCmbMod4Neut_C;                                  */
/*  input uint16 TqSys_nTarIdlCmbMod4;                                        */
/*  output uint16 TqSys_nTarIdlCmbMod4;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCMDMOD_vidCalibration4(void)
{
   uint16 u16LocalTqSysNIncMod4;
   uint16 u16LocalTqSysNDecMod4;
   uint16 u16LocalTqSysNTarIdlCmbMod4;
   uint16 u16LocalTqSys_nTarIdlCmbMod;
   uint32 u32LocalTqSysNTarIdlCmbMod4;
   sint16 s16LocalTqSysNDecMod4;


   u16LocalTqSysNIncMod4 = (uint16)(TqSys_nIncTarIdlCmbMod4_C / 25);
   s16LocalTqSysNDecMod4 = (sint16)MATHSRV_udtMIN(TqSys_nDecTarIdlCmbMod4_C, 0);
   u16LocalTqSysNDecMod4 = (uint16)(((-1) * s16LocalTqSysNDecMod4) / 25);

   if (TqSys_bAcvNTarIdlCmbModEgd != 0)
   {
      u32LocalTqSysNTarIdlCmbMod4 = (uint32)(TqSys_nTarIdlCmbMod4Egd_C * 4);
   }
   else
   {
      u32LocalTqSysNTarIdlCmbMod4 = (uint32)(TqSys_nTarIdlCmbMod4Neut_C * 4);
   }

   u16LocalTqSysNTarIdlCmbMod4 =
      (uint16)MATHSRV_udtMIN(u32LocalTqSysNTarIdlCmbMod4, 32000);

   u16LocalTqSys_nTarIdlCmbMod =
   MATHSRV_u16SlewFilter(  TqSys_nTarIdlCmbMod4,
                           u16LocalTqSysNTarIdlCmbMod4,
                           u16LocalTqSysNIncMod4,
                           u16LocalTqSysNDecMod4);
   TqSys_nTarIdlCmbMod4 =
      (uint16)MATHSRV_udtMIN(u16LocalTqSys_nTarIdlCmbMod, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCMDMOD_vidCalibration5                                  */
/* !Description :  Cette consigne de régime de ralenti est calculée pour le   */
/*                 mode de fonctionnement 5.                                  */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08588_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 TqSys_nIncTarIdlCmbMod5_C;                                   */
/*  input sint16 TqSys_nDecTarIdlCmbMod5_C;                                   */
/*  input boolean TqSys_bAcvNTarIdlCmbModEgd;                                 */
/*  input uint16 TqSys_nTarIdlCmbMod5Egd_C;                                   */
/*  input uint16 TqSys_nTarIdlCmbMod5Neut_C;                                  */
/*  input uint16 TqSys_nTarIdlCmbMod5;                                        */
/*  output uint16 TqSys_nTarIdlCmbMod5;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCMDMOD_vidCalibration5(void)
{
   uint16 u16LocalTqSysNIncMod5;
   uint16 u16LocalTqSysNDecMod5;
   uint16 u16LocalTqSysNTarIdlCmbMod5;
   uint16 u16LocalTqSys_nTarIdlCmbMod;
   uint32 u32LocalTqSysNTarIdlCmbMod5;
   sint16 s16LocalTqSysNDecMod5;


   u16LocalTqSysNIncMod5 = (uint16)(TqSys_nIncTarIdlCmbMod5_C / 25);
   s16LocalTqSysNDecMod5 = (sint16)MATHSRV_udtMIN(TqSys_nDecTarIdlCmbMod5_C, 0);
   u16LocalTqSysNDecMod5 = (uint16)(((-1) * s16LocalTqSysNDecMod5) / 25);

   if (TqSys_bAcvNTarIdlCmbModEgd != 0)
   {
      u32LocalTqSysNTarIdlCmbMod5 = (uint32)(TqSys_nTarIdlCmbMod5Egd_C * 4);
   }
   else
   {
      u32LocalTqSysNTarIdlCmbMod5 = (uint32)(TqSys_nTarIdlCmbMod5Neut_C * 4);
   }

   u16LocalTqSysNTarIdlCmbMod5 =
      (uint16)MATHSRV_udtMIN(u32LocalTqSysNTarIdlCmbMod5, 32000);

   u16LocalTqSys_nTarIdlCmbMod =
   MATHSRV_u16SlewFilter(  TqSys_nTarIdlCmbMod5,
                           u16LocalTqSysNTarIdlCmbMod5,
                           u16LocalTqSysNIncMod5,
                           u16LocalTqSysNDecMod5);
   TqSys_nTarIdlCmbMod5 =
      (uint16)MATHSRV_udtMIN(u16LocalTqSys_nTarIdlCmbMod, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCMDMOD_vidCalibration6                                  */
/* !Description :  Cette consigne de régime de ralenti est calculée pour le   */
/*                 mode de fonctionnement 6.                                  */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08588_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 TqSys_nIncTarIdlCmbMod6_C;                                   */
/*  input sint16 TqSys_nDecTarIdlCmbMod6_C;                                   */
/*  input boolean TqSys_bAcvNTarIdlCmbModEgd;                                 */
/*  input uint16 TqSys_nTarIdlCmbMod6Egd_C;                                   */
/*  input uint16 TqSys_nTarIdlCmbMod6Neut_C;                                  */
/*  input uint16 TqSys_nTarIdlCmbMod6;                                        */
/*  output uint16 TqSys_nTarIdlCmbMod6;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCMDMOD_vidCalibration6(void)
{
   uint16 u16LocalTqSysNIncMod6;
   uint16 u16LocalTqSysNDecMod6;
   uint16 u16LocalTqSysNTarIdlCmbMod6;
   uint16 u16LocalTqSys_nTarIdlCmbMod;
   uint32 u32LocalTqSysNTarIdlCmbMod6;
   sint16 s16LocalTqSysNDecMod6;


   u16LocalTqSysNIncMod6 = (uint16)(TqSys_nIncTarIdlCmbMod6_C / 25);
   s16LocalTqSysNDecMod6 = (sint16)MATHSRV_udtMIN(TqSys_nDecTarIdlCmbMod6_C, 0);
   u16LocalTqSysNDecMod6 = (uint16)(((-1) * s16LocalTqSysNDecMod6) / 25);

   if (TqSys_bAcvNTarIdlCmbModEgd != 0)
   {
      u32LocalTqSysNTarIdlCmbMod6 = (uint32)(TqSys_nTarIdlCmbMod6Egd_C * 4);
   }
   else
   {
      u32LocalTqSysNTarIdlCmbMod6 = (uint32)(TqSys_nTarIdlCmbMod6Neut_C * 4);
   }

   u16LocalTqSysNTarIdlCmbMod6 =
      (uint16)MATHSRV_udtMIN(u32LocalTqSysNTarIdlCmbMod6, 32000);

   u16LocalTqSys_nTarIdlCmbMod =
   MATHSRV_u16SlewFilter(  TqSys_nTarIdlCmbMod6,
                           u16LocalTqSysNTarIdlCmbMod6,
                           u16LocalTqSysNIncMod6,
                           u16LocalTqSysNDecMod6);

   TqSys_nTarIdlCmbMod6 =
      (uint16)MATHSRV_udtMIN(u16LocalTqSys_nTarIdlCmbMod, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCMDMOD_vidCalibration7                                  */
/* !Description :  Cette consigne de régime de ralenti est calculée pour le   */
/*                 mode de fonctionnement 7.                                  */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08588_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 TqSys_nTarIdlCmbMod7;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCMDMOD_vidCalibration7(void)
{
   TqSys_nTarIdlCmbMod7 = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCMDMOD_vidVectorizCalibration                           */
/* !Description :  Cette fonction crée un vecteur de consignes de régime de   */
/*                 ralenti applicables.                                       */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08588_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 TqSys_nTarIdlCmbMod1;                                        */
/*  input uint16 TqSys_nTarIdlCmbMod2;                                        */
/*  input uint16 TqSys_nTarIdlCmbMod3;                                        */
/*  input uint16 TqSys_nTarIdlCmbMod4;                                        */
/*  input uint16 TqSys_nTarIdlCmbMod5;                                        */
/*  input uint16 TqSys_nTarIdlCmbMod6;                                        */
/*  input uint16 TqSys_nTarIdlCmbMod7;                                        */
/*  output uint16 TqSys_prm_nTarIdlCmbMod[7];                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCMDMOD_vidVectorizCalibration(void)
{
   uint16 u16LocalTqSys_nTarIdlCmbMod;


   u16LocalTqSys_nTarIdlCmbMod =
      (uint16)MATHSRV_udtMIN(TqSys_nTarIdlCmbMod1, 32000);
   TqSys_prm_nTarIdlCmbMod[0] = u16LocalTqSys_nTarIdlCmbMod;
   u16LocalTqSys_nTarIdlCmbMod =
      (uint16)MATHSRV_udtMIN(TqSys_nTarIdlCmbMod2, 32000);
   TqSys_prm_nTarIdlCmbMod[1] = u16LocalTqSys_nTarIdlCmbMod;
   u16LocalTqSys_nTarIdlCmbMod =
      (uint16)MATHSRV_udtMIN(TqSys_nTarIdlCmbMod3, 32000);
   TqSys_prm_nTarIdlCmbMod[2] = u16LocalTqSys_nTarIdlCmbMod;
   u16LocalTqSys_nTarIdlCmbMod =
      (uint16)MATHSRV_udtMIN(TqSys_nTarIdlCmbMod4, 32000);
   TqSys_prm_nTarIdlCmbMod[3] = u16LocalTqSys_nTarIdlCmbMod;
   u16LocalTqSys_nTarIdlCmbMod =
      (uint16)MATHSRV_udtMIN(TqSys_nTarIdlCmbMod5, 32000);
   TqSys_prm_nTarIdlCmbMod[4] = u16LocalTqSys_nTarIdlCmbMod;
   u16LocalTqSys_nTarIdlCmbMod =
      (uint16)MATHSRV_udtMIN(TqSys_nTarIdlCmbMod6, 32000);
   TqSys_prm_nTarIdlCmbMod[5] = u16LocalTqSys_nTarIdlCmbMod;
   u16LocalTqSys_nTarIdlCmbMod =
      (uint16)MATHSRV_udtMIN(TqSys_nTarIdlCmbMod7, 32000);
   TqSys_prm_nTarIdlCmbMod[6] = u16LocalTqSys_nTarIdlCmbMod;
}

/*------------------------------- end of file --------------------------------*/