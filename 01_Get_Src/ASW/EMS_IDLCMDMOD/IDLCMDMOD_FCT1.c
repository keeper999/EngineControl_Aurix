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
/* !File            : IDLCMDMOD_FCT1.C                                        */
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
/*   1 / IDLCMDMOD_vidInitOutput                                              */
/*   2 / IDLCMDMOD_vidDtrminePwrtrainStat                                     */
/*   3 / IDLCMDMOD_vidUnvectorizeMode                                         */
/*   4 / IDLCMDMOD_vidDetermineSetpoint                                       */
/*   5 / IDLCMDMOD_vidCalibrations                                            */
/*   6 / IDLCMDMOD_vidSelectModes                                             */
/*   7 / IDLCMDMOD_vidInterpolation                                           */
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
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCMDMOD_vidInitOutput                                    */
/* !Description :  Fonction d'initialisation.                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 TqSys_nTarIdlCmbMod1Neut_C;                                  */
/*  input uint16 TqSys_nTarIdlCmbMod2Neut_C;                                  */
/*  input uint16 TqSys_nTarIdlCmbMod3Neut_C;                                  */
/*  input uint16 TqSys_nTarIdlCmbMod4Neut_C;                                  */
/*  input uint16 TqSys_nTarIdlCmbMod5Neut_C;                                  */
/*  input uint16 TqSys_nTarIdlCmbMod6Neut_C;                                  */
/*  output uint16 TqSys_nTarIdlCmbMod;                                        */
/*  output boolean TqSys_bAcvNTarIdlCmbModEgd;                                */
/*  output uint16 TqSys_nTarIdlCmbMod1;                                       */
/*  output uint16 TqSys_nTarIdlCmbMod2;                                       */
/*  output uint16 TqSys_nTarIdlCmbMod3;                                       */
/*  output uint16 TqSys_nTarIdlCmbMod4;                                       */
/*  output uint16 TqSys_nTarIdlCmbMod5;                                       */
/*  output uint16 TqSys_nTarIdlCmbMod6;                                       */
/*  output uint16 TqSys_nTarIdlCmbMod7;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCMDMOD_vidInitOutput(void)
{
   uint32 u32LocalTqSysNTarIdlCmbModNeut;


   VEMS_vidSET(TqSys_nTarIdlCmbMod, 0);

   TqSys_bAcvNTarIdlCmbModEgd = 0;

   u32LocalTqSysNTarIdlCmbModNeut = (uint32)(4 * TqSys_nTarIdlCmbMod1Neut_C);
   TqSys_nTarIdlCmbMod1 =
      (uint16)MATHSRV_udtMIN(u32LocalTqSysNTarIdlCmbModNeut, 32000);

   u32LocalTqSysNTarIdlCmbModNeut = (uint32)(4 * TqSys_nTarIdlCmbMod2Neut_C);
   TqSys_nTarIdlCmbMod2 =
      (uint16)MATHSRV_udtMIN(u32LocalTqSysNTarIdlCmbModNeut, 32000);

   u32LocalTqSysNTarIdlCmbModNeut = (uint32)(4 * TqSys_nTarIdlCmbMod3Neut_C);
   TqSys_nTarIdlCmbMod3 =
      (uint16)MATHSRV_udtMIN(u32LocalTqSysNTarIdlCmbModNeut, 32000);

   u32LocalTqSysNTarIdlCmbModNeut = (uint32)(4 * TqSys_nTarIdlCmbMod4Neut_C);
   TqSys_nTarIdlCmbMod4 =
      (uint16)MATHSRV_udtMIN(u32LocalTqSysNTarIdlCmbModNeut, 32000);

   u32LocalTqSysNTarIdlCmbModNeut = (uint32)(4 * TqSys_nTarIdlCmbMod5Neut_C);
   TqSys_nTarIdlCmbMod5 =
      (uint16)MATHSRV_udtMIN(u32LocalTqSysNTarIdlCmbModNeut, 32000);

   u32LocalTqSysNTarIdlCmbModNeut = (uint32)(4 * TqSys_nTarIdlCmbMod6Neut_C);
   TqSys_nTarIdlCmbMod6 =
      (uint16)MATHSRV_udtMIN(u32LocalTqSysNTarIdlCmbModNeut, 32000);

   TqSys_nTarIdlCmbMod7 = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCMDMOD_vidDtrminePwrtrainStat                           */
/* !Description :  L’état de la chaine de traction permet de sélectionner une */
/*                 consigne de régime de ralenti spécifique pour chaque mode  */
/*                 de combustion.                                             */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08588_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean TqSys_bCfNTarIdlCmbMod_C;                                   */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  input boolean CoPt_bTqTx;                                                 */
/*  input uint8 CoPt_stCpl;                                                   */
/*  input uint8 CoPt_noEgdGearCord;                                           */
/*  output boolean TqSys_bAcvNTarIdlCmbModEgd;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCMDMOD_vidDtrminePwrtrainStat(void)
{
   boolean bLocalCoPt_bTqTx;
   boolean bLocalInhGrDetNTarIdlCmbMod;
   uint8   u8LocalExt_stGBxCf;
   uint8   u8LocalCoPt_stCpl;
   uint8   u8LocalCoPt_noEgdGearCord;


   bLocalInhGrDetNTarIdlCmbMod = GDGAR_bGetFRM(FRM_FRM_INHGEARDETNTARIDLCMBMOD);
   if (bLocalInhGrDetNTarIdlCmbMod != 0)
   {
      TqSys_bAcvNTarIdlCmbModEgd = TqSys_bCfNTarIdlCmbMod_C;
   }
   else
   {
      VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);
      if (u8LocalExt_stGBxCf != 0)
      {
         VEMS_vidGET(CoPt_bTqTx, bLocalCoPt_bTqTx);
         if (bLocalCoPt_bTqTx != 0)
         {
            VEMS_vidGET(CoPt_stCpl, u8LocalCoPt_stCpl);
            if (u8LocalCoPt_stCpl <= 1)
            {
               TqSys_bAcvNTarIdlCmbModEgd = 0;
            }
            else
            {
               TqSys_bAcvNTarIdlCmbModEgd = 1;
            }
         }
         else
         {
            TqSys_bAcvNTarIdlCmbModEgd = 0;
         }
      }
      else
      {
         VEMS_vidGET(CoPt_noEgdGearCord, u8LocalCoPt_noEgdGearCord);
         if (u8LocalCoPt_noEgdGearCord != 0)
         {
            TqSys_bAcvNTarIdlCmbModEgd = 1;
         }
         else
         {
            TqSys_bAcvNTarIdlCmbModEgd = 0;
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCMDMOD_vidUnvectorizeMode                               */
/* !Description :  La composante 8 relative à la consigne de régime de ralenti*/
/*                 spécifique aux modes de combustion est sélectionnée pour   */
/*                 chaques vecteurs d’entrée EOM.                             */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08588_004.01                                     */
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
/*  output uint8 TqSys_idxBas1ModCur;                                         */
/*  output uint8 TqSys_idxBas2ModCur;                                         */
/*  output uint8 TqSys_idxBas1ModTar;                                         */
/*  output uint8 TqSys_idxBas2ModTar;                                         */
/*  output uint8 TqSys_facBasModCur;                                          */
/*  output uint8 TqSys_facBasModTar;                                          */
/*  output uint8 TqSys_facTranMod;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCMDMOD_vidUnvectorizeMode(void)
{
   uint8 u8LocalEOMPrmBas;


   VEMS_vidGET1DArrayElement(EOM_prm_idxBas1ModCur, 7,  u8LocalEOMPrmBas);
   TqSys_idxBas1ModCur = (uint8)MATHSRV_udtCLAMP(u8LocalEOMPrmBas, 1, 7);

   VEMS_vidGET1DArrayElement(EOM_prm_idxBas2ModCur, 7,  u8LocalEOMPrmBas);
   TqSys_idxBas2ModCur = (uint8)MATHSRV_udtCLAMP(u8LocalEOMPrmBas, 1, 7);

   VEMS_vidGET1DArrayElement(EOM_prm_idxBas1ModTar, 7,  u8LocalEOMPrmBas);
   TqSys_idxBas1ModTar = (uint8)MATHSRV_udtCLAMP(u8LocalEOMPrmBas, 1, 7);

   VEMS_vidGET1DArrayElement(EOM_prm_idxBas2ModTar, 7,  u8LocalEOMPrmBas);
   TqSys_idxBas2ModTar = (uint8)MATHSRV_udtCLAMP(u8LocalEOMPrmBas, 1, 7);

   VEMS_vidGET1DArrayElement(EOM_prm_facBasModCur, 7,  u8LocalEOMPrmBas);
   TqSys_facBasModCur = (uint8)MATHSRV_udtMIN(u8LocalEOMPrmBas, 128);

   VEMS_vidGET1DArrayElement(EOM_prm_facBasModTar, 7,  u8LocalEOMPrmBas);
   TqSys_facBasModTar = (uint8)MATHSRV_udtMIN(u8LocalEOMPrmBas, 128);

   VEMS_vidGET1DArrayElement(EOM_prm_facTranMod, 7,  u8LocalEOMPrmBas);
   TqSys_facTranMod = (uint8)MATHSRV_udtMIN(u8LocalEOMPrmBas, 128);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCMDMOD_vidDetermineSetpoint                             */
/* !Description :  La consigne de régime de ralenti spécifique aux modes de   */
/*                 combustion est calculée en 3 étapes en prenant en compte   */
/*                 les entrées EOM.                                           */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08588_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IDLCMDMOD_vidCalibrations();                             */
/*  extf argret void IDLCMDMOD_vidSelectModes();                              */
/*  extf argret void IDLCMDMOD_vidInterpolation();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCMDMOD_vidDetermineSetpoint(void)
{
   IDLCMDMOD_vidCalibrations();
   IDLCMDMOD_vidSelectModes();
   IDLCMDMOD_vidInterpolation();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCMDMOD_vidCalibrations                                  */
/* !Description :  Un vecteur de consigne est calculé à partir des différents */
/*                 modes de fonctionnement possibles.                         */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08588_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IDLCMDMOD_vidCalibration1();                             */
/*  extf argret void IDLCMDMOD_vidCalibration2();                             */
/*  extf argret void IDLCMDMOD_vidCalibration3();                             */
/*  extf argret void IDLCMDMOD_vidCalibration4();                             */
/*  extf argret void IDLCMDMOD_vidCalibration5();                             */
/*  extf argret void IDLCMDMOD_vidCalibration6();                             */
/*  extf argret void IDLCMDMOD_vidCalibration7();                             */
/*  extf argret void IDLCMDMOD_vidVectorizCalibration();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCMDMOD_vidCalibrations(void)
{
   IDLCMDMOD_vidCalibration1();
   IDLCMDMOD_vidCalibration2();
   IDLCMDMOD_vidCalibration3();
   IDLCMDMOD_vidCalibration4();
   IDLCMDMOD_vidCalibration5();
   IDLCMDMOD_vidCalibration6();
   IDLCMDMOD_vidCalibration7();
   IDLCMDMOD_vidVectorizCalibration();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCMDMOD_vidSelectModes                                   */
/* !Description :  Les calibrations actives sont utilisées d’après les flux en*/
/*                 provenance du manager de mode de fonctionnement EOM pour   */
/*                 chacun des quatre modes.                                   */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08588_015.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 TqSys_idxBas1ModCur;                                          */
/*  input uint16 TqSys_prm_nTarIdlCmbMod[7];                                  */
/*  input uint8 TqSys_idxBas2ModCur;                                          */
/*  input uint8 TqSys_idxBas1ModTar;                                          */
/*  input uint8 TqSys_idxBas2ModTar;                                          */
/*  output uint16 TqSys_nTarIdlBas1ModCur;                                    */
/*  output uint16 TqSys_nTarIdlBas2ModCur;                                    */
/*  output uint16 TqSys_nTarIdlBas1ModTar;                                    */
/*  output uint16 TqSys_nTarIdlBas2ModTar;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCMDMOD_vidSelectModes(void)
{
   uint8 u8LocalTqSys_idxBas;
   uint8 u8LocalIndex;


   u8LocalTqSys_idxBas = (uint8)MATHSRV_udtCLAMP(TqSys_idxBas1ModCur, 1, 7);
   u8LocalIndex = (uint8)(u8LocalTqSys_idxBas - 1);
   TqSys_nTarIdlBas1ModCur =
      (uint16)MATHSRV_udtMIN( TqSys_prm_nTarIdlCmbMod[u8LocalIndex],
                              32000);

   u8LocalTqSys_idxBas = (uint8)MATHSRV_udtCLAMP(TqSys_idxBas2ModCur, 1, 7);
   u8LocalIndex = (uint8)(u8LocalTqSys_idxBas - 1);
   TqSys_nTarIdlBas2ModCur =
      (uint16)MATHSRV_udtMIN( TqSys_prm_nTarIdlCmbMod[u8LocalIndex],
                              32000);

   u8LocalTqSys_idxBas = (uint8)MATHSRV_udtCLAMP(TqSys_idxBas1ModTar, 1, 7);
   u8LocalIndex = (uint8)(u8LocalTqSys_idxBas - 1);
   TqSys_nTarIdlBas1ModTar =
      (uint16)MATHSRV_udtMIN( TqSys_prm_nTarIdlCmbMod[u8LocalIndex],
                              32000);

   u8LocalTqSys_idxBas = (uint8)MATHSRV_udtCLAMP(TqSys_idxBas2ModTar, 1, 7);
   u8LocalIndex = (uint8)(u8LocalTqSys_idxBas - 1);
   TqSys_nTarIdlBas2ModTar =
      (uint16)MATHSRV_udtMIN( TqSys_prm_nTarIdlCmbMod[u8LocalIndex],
                              32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCMDMOD_vidInterpolation                                 */
/* !Description :  Deux interpolations successives permettent de calculer la  */
/*                 consigne de régime de ralenti finale à appliquer.          */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08588_016.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 TqSys_facBasModCur;                                           */
/*  input uint8 TqSys_facBasModTar;                                           */
/*  input uint8 TqSys_facTranMod;                                             */
/*  input uint16 TqSys_nTarIdlBas1ModTar;                                     */
/*  input uint16 TqSys_nTarIdlBas2ModTar;                                     */
/*  input uint16 TqSys_nTarIdlBas1ModCur;                                     */
/*  input uint16 TqSys_nTarIdlBas2ModCur;                                     */
/*  output uint16 TqSys_nTarIdlCmbMod;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCMDMOD_vidInterpolation(void)
{
   uint8  u8LocalTqSys_facBasModCur;
   uint8  u8LocalTqSys_facBasModTar;
   uint8  u8LocalTqSys_facTranMod;
   uint16 u16LocalTqSys_nTarIdlCmbMod;
   uint32 u32Localbaryout1;
   uint32 u32Localbaryout2;
   uint32 u32LocalTqSys_nTarIdlCmbMod;


   u8LocalTqSys_facBasModCur = (uint8)MATHSRV_udtMIN(TqSys_facBasModCur, 128);
   u8LocalTqSys_facBasModTar = (uint8)MATHSRV_udtMIN(TqSys_facBasModTar, 128);
   u8LocalTqSys_facTranMod = (uint8)MATHSRV_udtMIN(TqSys_facTranMod, 128);

   u32Localbaryout1 = (uint32)( ( ( TqSys_nTarIdlBas1ModTar
                                  * u8LocalTqSys_facBasModTar)
                                + ( (128 - u8LocalTqSys_facBasModTar)
                                  * TqSys_nTarIdlBas2ModTar)
                                + 64)
                              / 128);

   u32Localbaryout2 = (uint32)( ( ( TqSys_nTarIdlBas1ModCur
                                  * u8LocalTqSys_facBasModCur)
                                + ( (128 - u8LocalTqSys_facBasModCur)
                                  * TqSys_nTarIdlBas2ModCur)
                                + 64)
                              / 128);

   u32LocalTqSys_nTarIdlCmbMod = ( ( ( u32Localbaryout1
                                     * u8LocalTqSys_facTranMod)
                                   + ( (uint32)(128 - u8LocalTqSys_facTranMod)
                                     * u32Localbaryout2)
                                   + 64)
                                 / 128);
   u16LocalTqSys_nTarIdlCmbMod =
      (uint16)MATHSRV_udtMIN( u32LocalTqSys_nTarIdlCmbMod,32000);
   VEMS_vidSET(TqSys_nTarIdlCmbMod, u16LocalTqSys_nTarIdlCmbMod);
}

/*------------------------------- end of file --------------------------------*/