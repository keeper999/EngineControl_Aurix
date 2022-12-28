/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQCKEFCFIL                                              */
/* !Description     : TQCKEFCFIL Component                                    */
/*                                                                            */
/* !Module          : TQCKEFCFIL                                              */
/* !Description     : SAFETY TMS : VALIDER AGRÉMENT PRÉVENTIF                 */
/*                                                                            */
/* !File            : TQCKEFCFIL_FCT4.C                                       */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32Bit                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / TQCKEFCFIL_vidPriseCmptRapportBV                                     */
/*   2 / TQCKEFCFIL_vidcalIdxFacPreLookup                                     */
/*                                                                            */
/* !Reference   : V02 NT 10 01236 / 05                                        */
/* !OtherRefs   : VEMS V02 ECU#056922                                         */
/* !OtherRefs   : CSCT_CGMT09_2398 / 2.6                                      */
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
#include "TQCKEFCFIL.h"
#include "TQCKEFCFIL_L.h"
#include "TQCKEFCFIL_IM.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidPriseCmptRapportBV                           */
/* !Description :  Choix de la valeur du rapport de boite utilisée dans le    */
/*                 filtrage                                                   */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_039.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET1DArrayElement(argin, argin, argio);                      */
/*  input boolean SftyMgt_bNoGearDeceSel_C;                                   */
/*  input uint8 SftyMgt_noGearDeceIniTmp;                                     */
/*  input uint8 SftyMgt_prm_noGearCordDrivFil[5];                             */
/*  output uint8 SftyMgt_noGearDeceIni;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidPriseCmptRapportBV(void)
{
   uint8   u8LocalSftyMgt_noGearDeceIni;


   if( SftyMgt_bNoGearDeceSel_C != 0)
   {
      u8LocalSftyMgt_noGearDeceIni = SftyMgt_noGearDeceIniTmp;
   }
   else
   {
      VEMS_vidGET1DArrayElement(SftyMgt_prm_noGearCordDrivFil,
                                4,
                                u8LocalSftyMgt_noGearDeceIni);
   }
   SftyMgt_noGearDeceIni =
      (uint8)MATHSRV_udtMIN(u8LocalSftyMgt_noGearDeceIni, 8);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCKEFCFIL_vidcalIdxFacPreLookup                           */
/* !Description :  Calcule les index et les facteurs d’interpolation linéaire */
/*                 des carto utilisées (pré lookup)                           */
/* !Number      :  FCT4.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_01236_040.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 SftyMgt_nEngTiDrivFil_A[8];                                  */
/*  input uint16 SftyMgt_nEngDeceIni;                                         */
/*  input uint16 TQCKEFCFIL_u16ClcParaIdxNEngTi;                              */
/*  input uint16 SftyMgt_nEngThdDrivFil_A[12];                                */
/*  input uint16 TQCKEFCFIL_u16ClcParaIdxNEngThd;                             */
/*  input uint8 SftyMgt_noGearDrivFil_A[7];                                   */
/*  input uint8 SftyMgt_noGearDeceIni;                                        */
/*  input uint16 TQCKEFCFIL_u16ClcParaIdxNoGear;                              */
/*  input sint16 SftyMgt_tqCkDeceIni;                                         */
/*  input uint16 SftyMgt_tqFilDrivFil_A[12];                                  */
/*  input uint16 TQCKEFCFIL_u16ClcParaIdxTqFil;                               */
/*  output uint16 TQCKEFCFIL_u16ClcParaIdxNEngTi;                             */
/*  output uint16 SftyMgt_idxNEngTiDrivFil[2];                                */
/*  output uint16 TQCKEFCFIL_u16ClcParaIdxNEngThd;                            */
/*  output uint16 SftyMgt_idxNEngThdDrivFil[2];                               */
/*  output uint16 TQCKEFCFIL_u16ClcParaIdxNoGear;                             */
/*  output uint16 SftyMgt_idxNoGearDrivFil[2];                                */
/*  output uint16 TQCKEFCFIL_u16ClcParaIdxTqFil;                              */
/*  output uint16 SftyMgt_idxTqFilDrivFil[2];                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCKEFCFIL_vidcalIdxFacPreLookup(void)
{
   uint8   u8LocalFractionParam1;
   uint8   u8LocalFractionParam2;
   uint8   u8LocalFractionParam3;
   uint8   u8LocalFractionParam4;
   uint16  u16LocalIndiceParam1;
   uint16  u16LocalIndiceParam2;
   uint16  u16LocalIndiceParam3;
   uint16  u16LocalIndiceParam4;
   uint16  u16LocalSftyMgt_tqCkDeceIni;
   sint32  s32LocalSftyMgt_tqCkDeceIni;


   /*Production of SftyMgt_idxNEngTiDrivFil*/
   TQCKEFCFIL_u16ClcParaIdxNEngTi =
      MATHSRV_u16CalcParaIncAryU16(SftyMgt_nEngTiDrivFil_A,
                                   SftyMgt_nEngDeceIni,
                                   8);
   u16LocalIndiceParam1 = (uint16)(TQCKEFCFIL_u16ClcParaIdxNEngTi >> 8);
   u16LocalIndiceParam1 = (uint16)(u16LocalIndiceParam1 * 100);
   u8LocalFractionParam1 = (uint8)(TQCKEFCFIL_u16ClcParaIdxNEngTi);
   u8LocalFractionParam1 =
      (uint8) ((uint16)((u8LocalFractionParam1 * 25) + 32) / (uint16)64);

   SftyMgt_idxNEngTiDrivFil[0] = u16LocalIndiceParam1;
   SftyMgt_idxNEngTiDrivFil[1] = (uint16)u8LocalFractionParam1;

   /*Production of SftyMgt_idxNEngThdDrivFil*/
   TQCKEFCFIL_u16ClcParaIdxNEngThd =
      MATHSRV_u16CalcParaIncAryU16(SftyMgt_nEngThdDrivFil_A,
                                   SftyMgt_nEngDeceIni,
                                   12);
   u16LocalIndiceParam2 = (uint16)(TQCKEFCFIL_u16ClcParaIdxNEngThd >> 8);
   u16LocalIndiceParam2 = (uint16)(u16LocalIndiceParam2 * 100);
   u8LocalFractionParam2 = (uint8)(TQCKEFCFIL_u16ClcParaIdxNEngThd);
   u8LocalFractionParam2 =
      (uint8)((uint16)((u8LocalFractionParam2 * 25) + 32) / (uint16)64);

   SftyMgt_idxNEngThdDrivFil[0] = u16LocalIndiceParam2;
   SftyMgt_idxNEngThdDrivFil[1] = (uint16)u8LocalFractionParam2;

   /*Production of SftyMgt_idxNoGearDrivFil*/
   TQCKEFCFIL_u16ClcParaIdxNoGear =
      MATHSRV_u16CalcParaIncAryU8(SftyMgt_noGearDrivFil_A,
                                  SftyMgt_noGearDeceIni,
                                  7);

   u16LocalIndiceParam3 = (uint16)(TQCKEFCFIL_u16ClcParaIdxNoGear >> 8);
   u16LocalIndiceParam3 = (uint16)(u16LocalIndiceParam3 * 100);
   u8LocalFractionParam3 = (uint8)(TQCKEFCFIL_u16ClcParaIdxNoGear);
   u8LocalFractionParam3 =
      (uint8)((uint16)((u8LocalFractionParam3 * 25) + 32) / (uint16)64);

   SftyMgt_idxNoGearDrivFil[0] = u16LocalIndiceParam3;
   SftyMgt_idxNoGearDrivFil[1] = (uint16)u8LocalFractionParam3;

   /*Production of SftyMgt_idxTqFilDrivFil*/
   s32LocalSftyMgt_tqCkDeceIni =(sint32)(SftyMgt_tqCkDeceIni + 32000);
   u16LocalSftyMgt_tqCkDeceIni =
      (uint16) MATHSRV_udtMAX(s32LocalSftyMgt_tqCkDeceIni, 0);
   TQCKEFCFIL_u16ClcParaIdxTqFil =
      MATHSRV_u16CalcParaIncAryU16(SftyMgt_tqFilDrivFil_A,
                                   u16LocalSftyMgt_tqCkDeceIni,
                                   12);

   u16LocalIndiceParam4 = (uint16)(TQCKEFCFIL_u16ClcParaIdxTqFil >> 8);
   u16LocalIndiceParam4 = (uint16)(u16LocalIndiceParam4 * 100);
   u8LocalFractionParam4 = (uint8)(TQCKEFCFIL_u16ClcParaIdxTqFil);
   u8LocalFractionParam4 =
      (uint8)((uint16)((u8LocalFractionParam4 * 25) + 32) / (uint16)64);

   SftyMgt_idxTqFilDrivFil[0] = u16LocalIndiceParam4;
   SftyMgt_idxTqFilDrivFil[1] = (uint16)u8LocalFractionParam4;
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/