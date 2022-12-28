/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IDLSYSCUTOFF                                            */
/* !Description     : IDLSYSCUTOFF component.                                 */
/*                                                                            */
/* !Module          : IDLSYSCUTOFF                                            */
/* !Description     : Gestion coupure - reinjection agrement                  */
/*                                                                            */
/* !File            : IDLSYSCUTOFF_FCT1.C                                     */
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
/*   1 / IDLSYSCUTOFF_vidInitOutput                                           */
/*   2 / IDLSYSCUTOFF_vidCalculCondRegime                                     */
/*   3 / IDLSYSCUTOFF_vidCalculCondIVC                                        */
/*   4 / IDLSYSCUTOFF_vidCalcCondRegime                                       */
/*   5 / IDLSYSCUTOFF_vidCalcCondCouple                                       */
/*   6 / IDLSYSCUTOFF_vidCalcAutorCoupIVC                                     */
/*   7 / IDLSYSCUTOFF_vidAutoriCoupureInj                                     */
/*                                                                            */
/* !Reference   : V02 NT 10 04612 / 02                                        */
/* !OtherRefs   : 01460_10_01410 / 1.1                                        */
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
#include "VEMS.h"
#include "MATHSRV.h"
#include "IDLSYSCUTOFF.h"
#include "IDLSYSCUTOFF_L.h"
#include "IDLSYSCUTOFF_IM.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLSYSCUTOFF_vidInitOutput                                 */
/* !Description :  Reinitialisation des variables du module IDLSYSCUTOFF      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 TreatTDC_nCkGrd;                                             */
/*  output boolean IdlSys_bInjCutOff;                                         */
/*  output boolean IdlSys_bAuthInjCutOffIVC;                                  */
/*  output boolean IdlSys_bCdnNEngInjCutOffIVC;                               */
/*  output boolean IdlSys_bCdnTqInjCutOffIVC;                                 */
/*  output sint32 IDLSYSCUTOFF_s32FiltredTrtTDCMem;                           */
/*  output sint16 IdlSys_nGrdFilInjCutOff_MP;                                 */
/*  output uint16 IdlSys_nInhInjCutOffNEng_MP;                                */
/*  output boolean IdlSys_bAuthInjCutOffINEng;                                */
/*  output boolean IDLSYSCUTOFF_bPosHysOut;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLSYSCUTOFF_vidInitOutput(void)
{
   sint16 s16LocalTreatTDC_nCkGrd;


   VEMS_vidGET(TreatTDC_nCkGrd, s16LocalTreatTDC_nCkGrd);
   VEMS_vidSET(IdlSys_bInjCutOff, 0);
   IdlSys_bAuthInjCutOffIVC = 1;
   IdlSys_bCdnNEngInjCutOffIVC = 0;
   IdlSys_bCdnTqInjCutOffIVC = 0;
   IDLSYSCUTOFF_s32FiltredTrtTDCMem =
      (sint32)(s16LocalTreatTDC_nCkGrd * 65536);
   IdlSys_nGrdFilInjCutOff_MP =
      (sint16)MATHSRV_udtCLAMP(s16LocalTreatTDC_nCkGrd, -32000, 32000);
   IdlSys_nInhInjCutOffNEng_MP = 0;
   IdlSys_bAuthInjCutOffINEng = 0;
   IDLSYSCUTOFF_bPosHysOut = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLSYSCUTOFF_vidCalculCondRegime                           */
/* !Description :  Ce bloc permet de gérer la coupure - réinjection en        */
/*                 fonction du gradient de régime moteur.                     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_04612_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_tiTDC;                                                    */
/*  input sint16 TreatTDC_nCkGrd;                                             */
/*  input uint8 CoPt_noEgdGearCord;                                           */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input uint16 TqSys_nTarIdl;                                               */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 IdlSys_tiFilNGrdInjCutOff_C;                                 */
/*  input sint32 IDLSYSCUTOFF_s32FiltredTrtTDCMem;                            */
/*  input sint16 IdlSys_nGrdFilInjCutOff_MP;                                  */
/*  input uint16 IdlSys_nOfsInjCutOffNEng_T[8];                               */
/*  input uint16 IdlSys_nGrdInjCutOff_A[12];                                  */
/*  input uint16 IdlSys_nOfsAcvInjNEng_M[12][8];                              */
/*  input uint8 IdlSys_tCoInjCutOff_A[8];                                     */
/*  input uint8 IdlSys_facCorAcvInjNEng_T[8];                                 */
/*  input uint16 IdlSys_nInhInjCutOffNEng_MP;                                 */
/*  input boolean IdlSys_bAcvInjCutOffNEng_C;                                 */
/*  input boolean IDLSYSCUTOFF_bPosHysOut;                                    */
/*  output sint16 IdlSys_nGrdFilInjCutOff_MP;                                 */
/*  output sint32 IDLSYSCUTOFF_s32FiltredTrtTDCMem;                           */
/*  output uint16 IdlSys_nInhInjCutOffNEng_MP;                                */
/*  output boolean IDLSYSCUTOFF_bPosHysOut;                                   */
/*  output boolean IdlSys_bAuthInjCutOffINEng;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLSYSCUTOFF_vidCalculCondRegime(void)
{
   uint8  u8LocalExt_tiTDC;
   uint8  u8LocalExt_tCoMes;
   uint8  u8LocalIdlSysFacCorAcvInjNEngT;
   uint8  u8LocalCoPt_noEgdGearCord;
   uint16 u16LocalFilterGain;
   uint16 u16LocalCoPt_noEgdGearCord;
   uint16 u16LocalCalcPara;
   uint16 u16LocalIdlSysNGrdFilInjCutOffMP;
   uint16 u16LocalIdlSysNOfsInjCutOffNEngT;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalTqSys_nTarIdl;
   uint16 u16LocalIdlSysNOfsAcvInjNEng;
   uint16 u16LocalInjCutOffMP;
   uint16 u16LocalNInhInjCutOffNEngMMP;
   sint16 s16LocalTreatTDC_nCkGrd;
   sint16 s16LocalExt_tCoMes;
   uint32 u32LocalFilterGain;
   uint32 u32LocalProduct;
   uint32 u32LocalSum;
   uint32 u32LocalPosHysHigh;
   sint32 s32Localcacl;


   VEMS_vidGET(Ext_tiTDC, u8LocalExt_tiTDC);
   VEMS_vidGET(TreatTDC_nCkGrd, s16LocalTreatTDC_nCkGrd);
   VEMS_vidGET(CoPt_noEgdGearCord, u8LocalCoPt_noEgdGearCord);
   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   VEMS_vidGET(TqSys_nTarIdl, u16LocalTqSys_nTarIdl);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   /*Filter T*/
   u32LocalFilterGain =
      (uint32)((128 * u8LocalExt_tiTDC) + (125 * IdlSys_tiFilNGrdInjCutOff_C));

   if (  (u32LocalFilterGain == 0)
      || (IdlSys_tiFilNGrdInjCutOff_C == 0))
   {
      IdlSys_nGrdFilInjCutOff_MP = s16LocalTreatTDC_nCkGrd;
      IDLSYSCUTOFF_s32FiltredTrtTDCMem =
         (sint32)(s16LocalTreatTDC_nCkGrd * 65536);
   }
   else
   {
      u16LocalFilterGain = (uint16)( (uint32)(u8LocalExt_tiTDC * 8388608)
                           / u32LocalFilterGain);
      IdlSys_nGrdFilInjCutOff_MP =
         MATHSRV_s16FirstOrderFilterGu16(u16LocalFilterGain,
                                         &IDLSYSCUTOFF_s32FiltredTrtTDCMem,
                                         s16LocalTreatTDC_nCkGrd);

   }
   IdlSys_nGrdFilInjCutOff_MP =
      (sint16)MATHSRV_udtCLAMP(IdlSys_nGrdFilInjCutOff_MP, -32000, 32000);

   /*interpolation of dlSys_nOfsInjCutOffNEng_T*/
   u8LocalCoPt_noEgdGearCord =
      (uint8)MATHSRV_udtMIN(u8LocalCoPt_noEgdGearCord, 7);
   u16LocalIdlSysNOfsInjCutOffNEngT =
      IdlSys_nOfsInjCutOffNEng_T[u8LocalCoPt_noEgdGearCord];

   /*interpolation of IdlSys_nOfsAcvInjNEng_M*/
   u16LocalInjCutOffMP = (uint16)((IdlSys_nGrdFilInjCutOff_MP + 32000) / 4);
   u16LocalIdlSysNGrdFilInjCutOffMP =
      MATHSRV_u16CalcParaIncAryU16(IdlSys_nGrdInjCutOff_A,
                                   u16LocalInjCutOffMP,
                                   12);
   u16LocalCoPt_noEgdGearCord = (uint16)(u8LocalCoPt_noEgdGearCord * 256);

   u16LocalIdlSysNOfsAcvInjNEng =
      MATHSRV_u16Interp2d(&IdlSys_nOfsAcvInjNEng_M[0][0],
                          u16LocalIdlSysNGrdFilInjCutOffMP,
                          u16LocalCoPt_noEgdGearCord,
                          8);

   /*interpolation of IdlSys_facCorAcvInjNEng_T*/
   s32Localcacl = (sint32)(s16LocalExt_tCoMes + 40);
   u8LocalExt_tCoMes = (uint8)MATHSRV_udtCLAMP(s32Localcacl,0 , 254);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU8(IdlSys_tCoInjCutOff_A,
                                                  u8LocalExt_tCoMes,
                                                  8);

   u8LocalIdlSysFacCorAcvInjNEngT =
      MATHSRV_u8Interp1d(IdlSys_facCorAcvInjNEng_T,
                         u16LocalCalcPara);

   /*production of IdlSys_nInhInjCutOffNEng_MP*/
   u32LocalProduct = (uint32)( u16LocalIdlSysNOfsAcvInjNEng
                             * u8LocalIdlSysFacCorAcvInjNEngT);
   u32LocalProduct = (u32LocalProduct * 2) / 25;
   u32LocalSum = u32LocalProduct + (uint32)(u16LocalTqSys_nTarIdl);
   IdlSys_nInhInjCutOffNEng_MP = (uint16)(MATHSRV_udtMIN(u32LocalSum, 32000));

   /*Hysterisis*/

   u16LocalNInhInjCutOffNEngMMP = (uint16)(IdlSys_nInhInjCutOffNEng_MP / 4);

   if (u16LocalExt_nEng <= u16LocalNInhInjCutOffNEngMMP)
   {
      IDLSYSCUTOFF_bPosHysOut = 0;
   }
   else
   {
      u32LocalPosHysHigh = (uint32)((uint16)(IdlSys_nInhInjCutOffNEng_MP / 4)
                         + u16LocalIdlSysNOfsInjCutOffNEngT);

      if ((uint32)(u16LocalExt_nEng) >= u32LocalPosHysHigh)
      {
         IDLSYSCUTOFF_bPosHysOut = 1;
      }
   }

   /*production of IdlSys_bAuthInjCutOffINEng*/
   if (  (IdlSys_bAcvInjCutOffNEng_C != 0)
       || (IDLSYSCUTOFF_bPosHysOut != 0))
   {
      IdlSys_bAuthInjCutOffINEng = 1;
   }
   else
   {
      IdlSys_bAuthInjCutOffINEng = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLSYSCUTOFF_vidCalculCondIVC                              */
/* !Description :  Cette fonction calcule la condition de coupure injection   */
/*                 pour le besoin agrément.                                   */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_04612_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IDLSYSCUTOFF_vidCalcCondRegime(void);                    */
/*  extf argret void IDLSYSCUTOFF_vidCalcCondCouple(void);                    */
/*  extf argret void IDLSYSCUTOFF_vidCalcAutorCoupIVC(void);                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLSYSCUTOFF_vidCalculCondIVC(void)
{
   IDLSYSCUTOFF_vidCalcCondRegime();
   IDLSYSCUTOFF_vidCalcCondCouple();
   IDLSYSCUTOFF_vidCalcAutorCoupIVC();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLSYSCUTOFF_vidCalcCondRegime                             */
/* !Description :  On calcule une condition sur le régime moteur pour         */
/*                 autoriser la coupure agrément.                             */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_04612_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input uint8 CoPt_noEgdGearCord;                                           */
/*  input uint16 TqSys_nTarIdl;                                               */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint8 IdlSys_tCoInjCutOff_A[8];                                     */
/*  input uint16 IdlSys_nOfsAuthInjCutOffIVC_M[8][8];                         */
/*  output boolean IdlSys_bCdnNEngInjCutOffIVC;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLSYSCUTOFF_vidCalcCondRegime(void)
{
   uint8  u8LocalExt_tCoMes;
   uint8  u8LocalCoPt_noEgdGearCord;
   uint16 u16LocalParaExt_tCoMes;
   uint16 u16LocalCoPt_noEgdGearCord;
   uint16 u16LocalIdlSyNOfsAuthInjCutOfIVC;
   uint16 u16LocalTqSys_nTarIdl;
   uint16 u16LocalExt_nEng;
   sint16 s16LocalExt_tCoMes;
   uint32 u32LocalSum;
   sint32 s32Localcacl;


   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   VEMS_vidGET(CoPt_noEgdGearCord, u8LocalCoPt_noEgdGearCord);
   VEMS_vidGET(TqSys_nTarIdl, u16LocalTqSys_nTarIdl);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);

   s32Localcacl = (sint32)( s16LocalExt_tCoMes + 40);
   u8LocalExt_tCoMes = (uint8)MATHSRV_udtCLAMP(s32Localcacl, 0, 254);
   u16LocalParaExt_tCoMes =
      MATHSRV_u16CalcParaIncAryU8(IdlSys_tCoInjCutOff_A,
                                  u8LocalExt_tCoMes,
                                  8);
   u16LocalCoPt_noEgdGearCord = (uint16)(u8LocalCoPt_noEgdGearCord * 256);
   u16LocalIdlSyNOfsAuthInjCutOfIVC =
      MATHSRV_u16Interp2d(&IdlSys_nOfsAuthInjCutOffIVC_M[0][0],
                          u16LocalParaExt_tCoMes,
                          u16LocalCoPt_noEgdGearCord,
                          8);
   u32LocalSum =
        (uint32)(u16LocalIdlSyNOfsAuthInjCutOfIVC)
      + (uint32)(u16LocalTqSys_nTarIdl / 4);
   if ( ((uint32)u16LocalExt_nEng) > u32LocalSum )
   {
      IdlSys_bCdnNEngInjCutOffIVC = 1;
   }
   else
   {
      IdlSys_bCdnNEngInjCutOffIVC = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLSYSCUTOFF_vidCalcCondCouple                             */
/* !Description :  Lorsque le couple demandé par l’IVC est inférieur à un     */
/*                 seuil, on active un booléen permettant l’autorisation de la*/
/*                 coupure injection.                                         */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_04612_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 CoPt_tqIdcReqCord_nRegReq;                                   */
/*  input sint16 IdlSys_tqThdAuthInjCutOff_C;                                 */
/*  output boolean IdlSys_bCdnTqInjCutOffIVC;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLSYSCUTOFF_vidCalcCondCouple(void)
{
   sint16 s16LocalCoPtTqIdcReqCordNRegReq;
   sint32 s32LocalIdlSysTqThdAuthInjCutOff;


   VEMS_vidGET(CoPt_tqIdcReqCord_nRegReq, s16LocalCoPtTqIdcReqCordNRegReq);
   s32LocalIdlSysTqThdAuthInjCutOff = (sint32)(IdlSys_tqThdAuthInjCutOff_C * 4);
   if (  (sint32)(s16LocalCoPtTqIdcReqCordNRegReq)
         <  s32LocalIdlSysTqThdAuthInjCutOff)
   {
      IdlSys_bCdnTqInjCutOffIVC = 1;
   }
   else
   {
      IdlSys_bCdnTqInjCutOffIVC = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLSYSCUTOFF_vidCalcAutorCoupIVC                           */
/* !Description :  On autorise la coupure injection pour l’agrément lorsque : */
/*                 la condition sur le couple  ET la condition sur le régime  */
/*                 moteur sont actives OU lorsque le ralenti est effectif     */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_04612_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean TqSys_bEngNOnIdl;                                           */
/*  input boolean IdlSys_bAuthInjCutOffIVC;                                   */
/*  input boolean IdlSys_bCdnTqInjCutOffIVC;                                  */
/*  input boolean IdlSys_bCdnNEngInjCutOffIVC;                                */
/*  output boolean IdlSys_bAuthInjCutOffIVC;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLSYSCUTOFF_vidCalcAutorCoupIVC(void)
{
   boolean bLocalTqSys_bEngNOnIdl;


   VEMS_vidGET(TqSys_bEngNOnIdl, bLocalTqSys_bEngNOnIdl);

   if (IdlSys_bAuthInjCutOffIVC != 0)
   {
      if (IdlSys_bCdnTqInjCutOffIVC == 0)
      {
         IdlSys_bAuthInjCutOffIVC = 0;
      }
   }
   else
   {
      if (  (  (IdlSys_bCdnTqInjCutOffIVC != 0)
            && (IdlSys_bCdnNEngInjCutOffIVC != 0))
         || (bLocalTqSys_bEngNOnIdl != 0))
      {
         IdlSys_bAuthInjCutOffIVC = 1;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLSYSCUTOFF_vidAutoriCoupureInj                           */
/* !Description :  L’autorisation de coupure injection pour les besoins       */
/*                 agrément et ralenti fait la synthèse des autorisations de  */
/*                 coupure pour ces 2 fonctions.                              */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_04612_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean IdlSys_bInjCutOff;                                          */
/*  input boolean CoPt_bAcvAntiStallFil;                                      */
/*  input boolean IdlSys_bAcvAntiStall;                                       */
/*  input boolean IdlSys_bAuthInjCutOff;                                      */
/*  input boolean IdlSys_bAuthInjCutOffIVC;                                   */
/*  input boolean IdlSys_bAuthInjCutOffINEng;                                 */
/*  output boolean IdlSys_bInjCutOff;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLSYSCUTOFF_vidAutoriCoupureInj(void)
{
   boolean bLocalIdlSys_bInjCutOff;
   boolean bLocalCoPt_bAcvAntiStallFil;
   boolean bLocalIdlSys_bAcvAntiStall;
   boolean bLocalIdlSys_bAuthInjCutOff;


   VEMS_vidGET(IdlSys_bInjCutOff, bLocalIdlSys_bInjCutOff);
   VEMS_vidGET(CoPt_bAcvAntiStallFil, bLocalCoPt_bAcvAntiStallFil);
   VEMS_vidGET(IdlSys_bAcvAntiStall, bLocalIdlSys_bAcvAntiStall);
   VEMS_vidGET(IdlSys_bAuthInjCutOff, bLocalIdlSys_bAuthInjCutOff);

   if (bLocalIdlSys_bInjCutOff != 0)
   {
      if (  (bLocalCoPt_bAcvAntiStallFil != 0)
         || (bLocalIdlSys_bAcvAntiStall != 0)
         || (bLocalIdlSys_bAuthInjCutOff == 0)
         || (IdlSys_bAuthInjCutOffIVC == 0)
         || (IdlSys_bAuthInjCutOffINEng == 0))
      {
         VEMS_vidSET(IdlSys_bInjCutOff, 0);
      }
   }
   else
   {
      if (  (bLocalCoPt_bAcvAntiStallFil == 0)
         && (bLocalIdlSys_bAcvAntiStall == 0)
         && (bLocalIdlSys_bAuthInjCutOff != 0)
         && (IdlSys_bAuthInjCutOffIVC != 0)
         && (IdlSys_bAuthInjCutOffINEng != 0))
      {
         VEMS_vidSET(IdlSys_bInjCutOff, 1);
      }
   }
}
/*-------------------------------- end of file -------------------------------*/
