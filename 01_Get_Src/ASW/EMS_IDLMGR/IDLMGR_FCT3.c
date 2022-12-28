/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IDLMGR                                                  */
/* !Description     : IDLMGR component                                        */
/*                                                                            */
/* !Module          : IDLMGR                                                  */
/* !Description     : GESTION DU RALENTI                                      */
/*                                                                            */
/* !File            : IDLMGR_FCT3.C                                           */
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
/*   1 / IDLMGR_vidCalc_auto_coupure_inj                                      */
/*   2 / IDLMGR_vidCalc_condition_couple                                      */
/*   3 / IDLMGR_vidCalc_offset_coup_inj                                       */
/*   4 / IDLMGR_vidCalc_autorisation_inj                                      */
/*   5 / IDLMGR_vidCalc_couple_isop                                           */
/*   6 / IDLMGR_vidCalc_couple_init_reg                                       */
/*   7 / IDLMGR_vidPiloter_avances_mini                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_5010777 / 02                                        */
/* !OtherRefs   : CSMT_CGMT08_0003 / 2.9                                      */
/* !OtherRefs   : VEMS V02 ECU#063158                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/IDLMGR/IDLMGR_FCT$*/
/* $Revision::   1.19     $$Author::   mbenfrad       $$Date::   06 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   06 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "IDLMGR.h"
#include "IDLMGR_L.h"
#include "IDLMGR_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidCalc_auto_coupure_inj                            */
/* !Description :  Dans cette fonction, on calcule la condition d’autorisation*/
/*                 de coupure-injection pour le ralenti.                      */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_032.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void IDLMGR_vidCalc_condition_couple();                       */
/*  extf argret void IDLMGR_vidCalc_offset_coup_inj();                        */
/*  extf argret void IDLMGR_vidCalc_autorisation_inj();                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidCalc_auto_coupure_inj(void)
{
   IDLMGR_vidCalc_condition_couple();
   IDLMGR_vidCalc_offset_coup_inj();
   IDLMGR_vidCalc_autorisation_inj();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidCalc_condition_couple                            */
/* !Description :  L’autorisation de coupure injection est accordée lorsque le*/
/*                 couple du régulateur de ralenti est sur le couple minimum  */
/*                 du ralenti.                                                */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_033.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 IdlSys_tqIdcIdlMin;                                          */
/*  input sint16 IdlSys_tqIdcIdlNotSat;                                       */
/*  input uint8 IdlSys_noGear;                                                */
/*  input uint8 IdlSys_tqHiAuthInjCutOff_T[4];                                */
/*  output boolean IdlSys_bAuthInjCutOffTqMin;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidCalc_condition_couple(void)
{
   uint8  u8LocalIdlSys_noGear;
   uint16 u16LocalAuthInjCutOff;
   sint16 s16LocalIdlSys_tqIdcIdlMin;
   sint16 s16LocalIdlSys_tqIdcIdlNotSat;
   sint32 s32LocalDif;


   VEMS_vidGET(IdlSys_tqIdcIdlMin, s16LocalIdlSys_tqIdcIdlMin);
   VEMS_vidGET(IdlSys_tqIdcIdlNotSat, s16LocalIdlSys_tqIdcIdlNotSat);
   VEMS_vidGET(IdlSys_noGear, u8LocalIdlSys_noGear);

   s32LocalDif = (sint32)( s16LocalIdlSys_tqIdcIdlNotSat
                         - s16LocalIdlSys_tqIdcIdlMin);
   u8LocalIdlSys_noGear = (uint8)MATHSRV_udtMIN(u8LocalIdlSys_noGear, 3);
   u16LocalAuthInjCutOff =
      (uint16)(4 * IdlSys_tqHiAuthInjCutOff_T[u8LocalIdlSys_noGear]);
   if (s32LocalDif >= u16LocalAuthInjCutOff)
   {
      IdlSys_bAuthInjCutOffTqMin = 0;
   }
   else
   {
      if (s32LocalDif <= 0)
      {
         IdlSys_bAuthInjCutOffTqMin = 1;
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidCalc_offset_coup_inj                             */
/* !Description :  Un offset de régime est calculé pour autoriser la coupure  */
/*                 injection. Celui-ci est fonction du gradient de régime et  */
/*                 du rapport de boite, et peut être corrigé par un facteur   */
/*                 dépendant de la température moteur.                        */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_034.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 IdlSys_noGear;                                                */
/*  input sint16 IdlSys_nGrdEng;                                              */
/*  input uint16 IdlSys_nGrdEngInjCutOff_A[8];                                */
/*  input uint16 IdlSys_nOfsInjCutOff_M[8][4];                                */
/*  input sint16 IdlSys_tEng;                                                 */
/*  input uint8 IdlSys_tEng_A[8];                                             */
/*  input uint16 IdlSys_facCorNOfsCutOff_T[8];                                */
/*  output uint16 IdlSys_nOfsInjCutOff;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidCalc_offset_coup_inj(void)
{
   uint8  u8LocalIdlSys_noGear;
   uint8  u8LocalIdlSysTEng;
   uint16 u16LocalIdlSys_noGear;
   uint16 u16LocalCalcPara1;
   uint16 u16LocalCalcPara2;
   uint16 u16LocalInterp2;
   uint16 u16LocalInterp1;
   uint16 u16LocalInput;
   sint16 s16LocalIdlSysTEng;
   uint32 u32LocalIdlSysnOfsInj;
   sint32 s32LocalIdlSys_nGrdEng;


   VEMS_vidGET(IdlSys_noGear, u8LocalIdlSys_noGear);

   u8LocalIdlSys_noGear = (uint8)MATHSRV_udtMIN(u8LocalIdlSys_noGear, 3);
   u16LocalIdlSys_noGear = (uint16)(u8LocalIdlSys_noGear * 256);

   s32LocalIdlSys_nGrdEng = IdlSys_nGrdEng + 8000;
   u16LocalInput = (uint16)MATHSRV_udtMAX(s32LocalIdlSys_nGrdEng, 0);
   u16LocalCalcPara1 = MATHSRV_u16CalcParaIncAryU16(IdlSys_nGrdEngInjCutOff_A,
                                                    u16LocalInput,
                                                    8);

   u16LocalInterp1 = MATHSRV_u16Interp2d(&IdlSys_nOfsInjCutOff_M[0][0],
                                         u16LocalCalcPara1,
                                         u16LocalIdlSys_noGear,
                                         4);
   s16LocalIdlSysTEng = (sint16)((sint32)(IdlSys_tEng + 200) / 4);
   u8LocalIdlSysTEng = (uint8)MATHSRV_udtCLAMP(s16LocalIdlSysTEng, 0, 255);
   u16LocalCalcPara2 = MATHSRV_u16CalcParaIncAryU8(IdlSys_tEng_A,
                                                   u8LocalIdlSysTEng,
                                                   8);
   u16LocalInterp2 = MATHSRV_u16Interp1d(IdlSys_facCorNOfsCutOff_T,
                                         u16LocalCalcPara2);

   u32LocalIdlSysnOfsInj = (uint32)((u16LocalInterp1 * u16LocalInterp2) + 64)
                                   / 128;
   IdlSys_nOfsInjCutOff = (uint16)MATHSRV_udtMIN(u32LocalIdlSysnOfsInj, 8000);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidCalc_autorisation_inj                            */
/* !Description :  L’autorisation de coupure injection est activée lorsque Le */
/*                 régulateur de ralenti n’est plus actif OU la condition     */
/*                 dynamique n’est plus remplie ET le couple issu  du         */
/*                 régulateur de ralenti est sur sa butée minimum.            */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_035.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint16 Ext_nEngClc0;                                                */
/*  input st1600 IDLMGR_stCutInj;                                             */
/*  input boolean IdlSys_bAuthIdlCtlStEng;                                    */
/*  input boolean IdlSys_bAcvIdlCtl;                                          */
/*  input boolean IdlSys_bAcvIdlCtlDyn;                                       */
/*  input boolean IdlSys_bAuthInjCutOffTqMin;                                 */
/*  input uint16 IdlSys_nAuthInjCutOff;                                       */
/*  input uint16 IdlSys_nOfsInjCutOff;                                        */
/*  output st1600 IDLMGR_stCutInj;                                            */
/*  output boolean IdlSys_bAuthInjCutOff;                                     */
/*  output uint16 IdlSys_nAuthInjCutOff;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidCalc_autorisation_inj(void)
{
   boolean bLocalIdlSys_bAcvIdlCtl;
   uint16  u16LocalExt_nEngClc0;
   uint32  u32LocalSum;


   VEMS_vidGET(Ext_nEngClc0, u16LocalExt_nEngClc0);

   switch (IDLMGR_stCutInj)
   {
      case IDLMGR_u8INHIB_CUT_INJ:
         if (IdlSys_bAuthIdlCtlStEng == 0)
         {
            IDLMGR_stCutInj = IDLMGR_u8AUTO_CUT_INJ;
            VEMS_vidSET(IdlSys_bAuthInjCutOff, 1);
         }
         else
         {
            VEMS_vidGET(IdlSys_bAcvIdlCtl, bLocalIdlSys_bAcvIdlCtl);
            if (  (bLocalIdlSys_bAcvIdlCtl == 0)
               || (  (IdlSys_bAcvIdlCtlDyn == 0)
                  && (IdlSys_bAuthInjCutOffTqMin != 0)))
            {
               if (u16LocalExt_nEngClc0 >= 32000)
               {
                  u16LocalExt_nEngClc0 = 8000;
               }
               else
               {
                  u16LocalExt_nEngClc0 =
                     (uint16)( (u16LocalExt_nEngClc0 + 2)
                             / 4);
               }

               IDLMGR_stCutInj = IDLMGR_u8TEMPO_CUT_INJ;
               VEMS_vidSET(IdlSys_bAuthInjCutOff, 0);
               IdlSys_nAuthInjCutOff = u16LocalExt_nEngClc0;
            }
         }
         break;

      case IDLMGR_u8TEMPO_CUT_INJ:
         if (  (IdlSys_bAuthIdlCtlStEng != 0)
            && (  (IdlSys_bAcvIdlCtlDyn != 0)
               || (IdlSys_bAuthInjCutOffTqMin == 0)))
         {
               IDLMGR_stCutInj = IDLMGR_u8INHIB_CUT_INJ;
               VEMS_vidSET(IdlSys_bAuthInjCutOff, 0);
               IdlSys_nAuthInjCutOff = 8000;
         }
         else
         {
            u32LocalSum = (uint32)( ( IdlSys_nAuthInjCutOff
                                    + IdlSys_nOfsInjCutOff)
                                  * 4);
            if (  (IdlSys_bAuthIdlCtlStEng == 0)
               || (u16LocalExt_nEngClc0 > u32LocalSum))
            {
               IDLMGR_stCutInj = IDLMGR_u8AUTO_CUT_INJ;
               VEMS_vidSET(IdlSys_bAuthInjCutOff, 1);
            }
         }
         break;

      case IDLMGR_u8AUTO_CUT_INJ:
         if (  (IdlSys_bAuthIdlCtlStEng != 0)
            && (  (IdlSys_bAcvIdlCtlDyn != 0)
               || (IdlSys_bAuthInjCutOffTqMin == 0)))
         {
               IDLMGR_stCutInj = IDLMGR_u8INHIB_CUT_INJ;
               VEMS_vidSET(IdlSys_bAuthInjCutOff, 0);
               IdlSys_nAuthInjCutOff = 8000;
         }
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         IDLMGR_stCutInj = IDLMGR_u8INHIB_CUT_INJ;
         VEMS_vidSET(IdlSys_bAuthInjCutOff, 0);
         IdlSys_nAuthInjCutOff = 8000;
         break;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidCalc_couple_isop                                 */
/* !Description :  A partir du gradient de régime d’entrée au ralenti, on     */
/*                 calcule un couple indiqué permettant d’assurer l’entrée au */
/*                 ralenti.Il est possible de moduler l’impact de ce couple en*/
/*                 fonction de l’erreur de régime.                            */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_036.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 TqSys_nTarIdl;                                               */
/*  input uint16 IdlSys_nTarIdlDyn;                                           */
/*  input sint16 IdlSys_tqLoss;                                               */
/*  input uint16 IdlSys_nEng;                                                 */
/*  input uint16 IdlSys_nErrIdlStabX_A[8];                                    */
/*  input uint16 IDLMGR_u16StabX_A;                                           */
/*  input uint16 IdlSys_nErrIdlStabY_A[8];                                    */
/*  input uint16 IDLMGR_u16StabY_A;                                           */
/*  input uint16 IdlSys_facCorTqIdlStab_M[8][8];                              */
/*  input uint16 IdlSys_jVeh;                                                 */
/*  input sint16 IdlSys_nGrdTarIdl;                                           */
/*  output uint16 IDLMGR_u16StabY_A;                                          */
/*  output uint16 IDLMGR_u16StabX_A;                                          */
/*  output sint16 IdlSys_tqIdcIdlStab;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidCalc_couple_isop(void)
{
   uint16 u16LocalGrdTarIdl;
   uint16 u16LocalCalcPara1;
   uint16 u16LocalIdlSys_nTarIdlDyn;
   uint16 u16LocalTqSys_nTarIdl;
   uint16 u16LocalCalcPara2;
   uint16 u16LocalInterp1;
   sint16 s16LocalIdlSys_tqLoss;
   sint16 s16LocaltqIdcIdlStab;
   uint32 u32LocalGrdTarIdl;
   uint32 u32LocaljVeh;
   sint32 s32LocalnTarIdl;
   sint32 s32LocaltqIdcIdlStab;


   VEMS_vidGET(TqSys_nTarIdl, u16LocalTqSys_nTarIdl);
   VEMS_vidGET(IdlSys_nTarIdlDyn, u16LocalIdlSys_nTarIdlDyn);
   VEMS_vidGET(IdlSys_tqLoss, s16LocalIdlSys_tqLoss);
   s32LocalnTarIdl =
      (sint32)((u16LocalTqSys_nTarIdl - u16LocalIdlSys_nTarIdlDyn) + 32000) / 4;
   IDLMGR_u16StabY_A = (uint16)MATHSRV_udtMAX(s32LocalnTarIdl, 0);

   s32LocalnTarIdl = (sint32)( (u16LocalTqSys_nTarIdl - IdlSys_nEng) + 32000)
                             / 4;
   IDLMGR_u16StabX_A = (uint16)MATHSRV_udtMAX(s32LocalnTarIdl, 0);
   u16LocalCalcPara1 = MATHSRV_u16CalcParaIncAryU16(IdlSys_nErrIdlStabX_A,
                                                    IDLMGR_u16StabX_A,
                                                    8);
   u16LocalCalcPara2 = MATHSRV_u16CalcParaIncAryU16(IdlSys_nErrIdlStabY_A,
                                                    IDLMGR_u16StabY_A,
                                                    8);
   u16LocalInterp1 = MATHSRV_u16Interp2d(&IdlSys_facCorTqIdlStab_M[0][0],
                                         u16LocalCalcPara1,
                                         u16LocalCalcPara2,
                                         8);
   u32LocaljVeh = (IdlSys_jVeh + 1) * u16LocalInterp1;
   u16LocalGrdTarIdl = (uint16)MATHSRV_udtABS(IdlSys_nGrdTarIdl);
   if (u16LocalGrdTarIdl != 0)
   {
      u32LocalGrdTarIdl = (uint32)(633301504 / u16LocalGrdTarIdl);
      if (u32LocaljVeh > u32LocalGrdTarIdl)
      {
         if (IdlSys_nGrdTarIdl > 0)
         {
            s32LocaltqIdcIdlStab = 32000;
         }
         else
         {
            s32LocaltqIdcIdlStab = -32000;
         }
      }
      else
      {
         s32LocaltqIdcIdlStab = (sint32)u32LocaljVeh * IdlSys_nGrdTarIdl;
         s32LocaltqIdcIdlStab =
            (s32LocaltqIdcIdlStab + (s16LocalIdlSys_tqLoss * 9778)) / 9778;
      }
   }
   else
   {
       s32LocaltqIdcIdlStab = s16LocalIdlSys_tqLoss;
   }
   s16LocaltqIdcIdlStab =
      (sint16)MATHSRV_udtCLAMP(s32LocaltqIdcIdlStab, -32000, 32000);
   VEMS_vidSET(IdlSys_tqIdcIdlStab, s16LocaltqIdcIdlStab);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidCalc_couple_init_reg                             */
/* !Description :  Selon l’état du superviseur de ralenti                     */
/*                 (IdlSys_bAcvIdlCtl),on calcule la valeur d’initialisation  */
/*                 des couples du régulateur(branche air et avance).          */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_037.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean IdlSys_bAcvIdlCtl;                                          */
/*  input uint8 IdlSys_noGear;                                                */
/*  input sint16 IdlSys_tqLoss;                                               */
/*  input boolean IdlSys_bAcvAntiStallAT;                                     */
/*  input uint8 IdlSys_noGearPrev;                                            */
/*  input uint16 Ext_nEngClc0;                                                */
/*  input uint16 TqSys_nTarIdl;                                               */
/*  input sint16 IdlSys_nEngLowIni_C;                                         */
/*  input uint8 IdlSys_idxIniIdlGearNeut_C;                                   */
/*  input uint8 IdlSys_idxIniIdlGearDec_C;                                    */
/*  input uint8 IdlSys_idxIniIdlGearInc_C;                                    */
/*  input uint8 IdlSys_idxIniIdlTq_MP;                                        */
/*  input sint16 IdlSys_tqIdcIdlStab;                                         */
/*  input sint16 IdlSys_tqIniNEngLow_C;                                       */
/*  input sint16 IdlSys_tEng;                                                 */
/*  input uint8 IdlSys_tEng_A[8];                                             */
/*  input uint16 IdlSys_facCorTqAntiStallAT_T[8];                             */
/*  input sint16 IdlSys_nGrdEng;                                              */
/*  input uint16 IdlSys_nGrdEngAntiStallAT_A[8];                              */
/*  input uint16 IdlSys_tqIdcAntiStallAT_M[8][4];                             */
/*  input sint16 IdlSys_tqIdcIdlMin;                                          */
/*  input sint16 TqSys_tqIdcAirLimCordWoutRes;                                */
/*  input boolean TqSys_bIniIdlReq;                                           */
/*  input sint16 TqSys_tqIniIdlReq;                                           */
/*  input boolean IdlSys_bAcvIdlCtlStrt;                                      */
/*  input sint16 EngLim_tqIdcEngCurGBx;                                       */
/*  input sint16 TqSys_tqIdcEngIdlCord;                                       */
/*  output uint8 IdlSys_idxIniIdlTq_MP;                                       */
/*  output sint16 IdlSys_tqIdcIdlIni;                                         */
/*  output sint16 IdlSys_tqIdcIdlIniAir;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidCalc_couple_init_reg(void)
{
   boolean bLocalIdlSys_bAcvIdlCtl;
   boolean bLocalTqSys_bIniIdlReq;
   uint8   u8LocalIdlSysTEng;
   uint8   u8LocalIdlSys_idxIniIdlTq_MP;
   uint8   u8LocalIdlSys_noGear;
   uint16  u16LocalCalcPara1;
   uint16  u16LocalInterp2;
   uint16  u16LocalInterp1;
   uint16  u16LocalIdlSysAeng;
   uint16  u16LocalIdlSys_noGear;
   uint16  u16LocalExt_nEngClc0;
   uint16  u16LocalTqSys_nTarIdl;
   sint16  s16LocalIdlSys_tqLoss;
   sint16  s16LocalIdlSys_tqIdcIdlIni;
   sint16  s16LocalIIdlSys_tqIdcIdlIniAir;
   sint16  s16LocalIdlSys_tqIdcIdlMin;
   sint16  s16LocalTqSys_tqIdcAirLimCordRes;
   sint16  s16LocalTqSys_tqIdcEngIdlCord;
   sint16  s16LocalEngLim_tqIdcEngCurGBx;
   sint16  s16LocalIdlSysTEng;
   sint16  s16LocalIdlSys_tqIdcCur;
   sint16  s16LocalTqSys_tqIniIdlReq;
   sint16  s16LocalIdlSys_tqIdcIdlStab;
   sint32  s32LocalIdlSys_tqIdcIdlIni;
   sint32  s32LocalIdlSysAEng;
   sint32  s32LocalIIdlSys_tqIdcIdlIniAir;
   sint32  s32LocalVar;


   VEMS_vidGET(IdlSys_bAcvIdlCtl, bLocalIdlSys_bAcvIdlCtl);
   VEMS_vidGET(IdlSys_noGear, u8LocalIdlSys_noGear);
   VEMS_vidGET(IdlSys_tqLoss, s16LocalIdlSys_tqLoss);
   if (IdlSys_bAcvAntiStallAT != 0)
   {
      u8LocalIdlSys_idxIniIdlTq_MP = 3;
   }
   else
   {
      if (u8LocalIdlSys_noGear == IdlSys_noGearPrev)
      {
         VEMS_vidGET(Ext_nEngClc0, u16LocalExt_nEngClc0);
         VEMS_vidGET(TqSys_nTarIdl, u16LocalTqSys_nTarIdl);
         s32LocalVar = (sint32)(40 * IdlSys_nEngLowIni_C);
         s32LocalVar = u16LocalTqSys_nTarIdl - s32LocalVar;
         if (u16LocalExt_nEngClc0 < s32LocalVar)
         {
            u8LocalIdlSys_idxIniIdlTq_MP = 4;
         }
         else
         {
            u8LocalIdlSys_idxIniIdlTq_MP = 1;
         }
      }
      else
      {
         if (u8LocalIdlSys_noGear == 0)
         {
            u8LocalIdlSys_idxIniIdlTq_MP = IdlSys_idxIniIdlGearNeut_C;
         }
         else
         {
            if (IdlSys_noGearPrev > u8LocalIdlSys_noGear)
            {
               u8LocalIdlSys_idxIniIdlTq_MP = IdlSys_idxIniIdlGearDec_C;
            }
            else
            {
               u8LocalIdlSys_idxIniIdlTq_MP = IdlSys_idxIniIdlGearInc_C;
            }
         }
      }
   }
   IdlSys_idxIniIdlTq_MP =
      (uint8)MATHSRV_udtMIN(u8LocalIdlSys_idxIniIdlTq_MP, 4);

   if (bLocalIdlSys_bAcvIdlCtl != 0)
   {
      if (IdlSys_idxIniIdlTq_MP == 4)
      {
         VEMS_vidGET(IdlSys_tqIdcIdlStab, s16LocalIdlSys_tqIdcIdlStab);
         s32LocalIIdlSys_tqIdcIdlIniAir = (sint32)(16 * IdlSys_tqIniNEngLow_C);
         s32LocalIIdlSys_tqIdcIdlIniAir =
            (s32LocalIIdlSys_tqIdcIdlIniAir + s16LocalIdlSys_tqIdcIdlStab);
         s32LocalIdlSys_tqIdcIdlIni = s32LocalIIdlSys_tqIdcIdlIniAir;
      }
      else
      {
         if (IdlSys_idxIniIdlTq_MP == 3)
         {
            s16LocalIdlSysTEng = (sint16)((sint32)(IdlSys_tEng + 200) / 4);
            u8LocalIdlSysTEng =
               (uint8)MATHSRV_udtCLAMP(s16LocalIdlSysTEng, 0, 255);
            u16LocalCalcPara1 = MATHSRV_u16CalcParaIncAryU8(IdlSys_tEng_A,
                                                            u8LocalIdlSysTEng,
                                                            8);
            u16LocalInterp2 = MATHSRV_u16Interp1d(IdlSys_facCorTqAntiStallAT_T,
                                                  u16LocalCalcPara1);

            u8LocalIdlSys_noGear =
               (uint8)MATHSRV_udtMIN(u8LocalIdlSys_noGear, 3);
            u16LocalIdlSys_noGear = (uint16)(u8LocalIdlSys_noGear * 256);
            s32LocalIdlSysAEng = (sint32)(IdlSys_nGrdEng + 8000);
            u16LocalIdlSysAeng = (uint16)MATHSRV_udtMAX(s32LocalIdlSysAEng, 0);
            u16LocalCalcPara1 =
               MATHSRV_u16CalcParaIncAryU16(IdlSys_nGrdEngAntiStallAT_A,
                                            u16LocalIdlSysAeng,
                                            8);
            u16LocalInterp1 =
               MATHSRV_u16Interp2d(&IdlSys_tqIdcAntiStallAT_M[0][0],
                                   u16LocalCalcPara1,
                                   u16LocalIdlSys_noGear,
                                   4);
            /*IdlSys_tEng = u16LocalInterp2;*/
            s32LocalIIdlSys_tqIdcIdlIniAir =
             (sint32)((uint32)(u16LocalInterp1 * u16LocalInterp2) / 32);
            s32LocalIdlSys_tqIdcIdlIni = s32LocalIIdlSys_tqIdcIdlIniAir;
         }
         else
         {
            VEMS_vidGET(IdlSys_tqIdcIdlMin, s16LocalIdlSys_tqIdcIdlMin);
            VEMS_vidGET(TqSys_tqIdcAirLimCordWoutRes,
                        s16LocalTqSys_tqIdcAirLimCordRes);
            VEMS_vidGET(TqSys_bIniIdlReq, bLocalTqSys_bIniIdlReq);

            if (bLocalTqSys_bIniIdlReq != 0)
            {
               VEMS_vidGET(TqSys_tqIniIdlReq, s16LocalTqSys_tqIniIdlReq);
               s16LocalIdlSys_tqIdcCur = s16LocalTqSys_tqIniIdlReq;
            }
            else
            {
               if (IdlSys_bAcvIdlCtlStrt !=0)
               {
                  VEMS_vidGET(EngLim_tqIdcEngCurGBx,
                              s16LocalEngLim_tqIdcEngCurGBx);
                  s16LocalIdlSys_tqIdcCur = s16LocalEngLim_tqIdcEngCurGBx;
               }
               else
               {
                  VEMS_vidGET(TqSys_tqIdcEngIdlCord,
                              s16LocalTqSys_tqIdcEngIdlCord);
                  s16LocalIdlSys_tqIdcCur = s16LocalTqSys_tqIdcEngIdlCord;
               }
            }
            if (IdlSys_idxIniIdlTq_MP == 2)
            {
               s32LocalIdlSys_tqIdcIdlIni =
                  (sint32)MATHSRV_udtMAX(s16LocalIdlSys_tqIdcCur,
                                         s16LocalIdlSys_tqIdcIdlMin);
               s32LocalIIdlSys_tqIdcIdlIniAir =
                  (sint32)MATHSRV_udtMAX(s16LocalTqSys_tqIdcAirLimCordRes,
                                         s16LocalIdlSys_tqIdcIdlMin);
               s32LocalIIdlSys_tqIdcIdlIniAir =
                  MATHSRV_udtMAX(s32LocalIIdlSys_tqIdcIdlIniAir,
                                 s16LocalIdlSys_tqLoss);
            }
            else
            {
               if (IdlSys_idxIniIdlTq_MP == 1)
               {
                  s32LocalIdlSys_tqIdcIdlIni =
                     (sint32)MATHSRV_udtMAX(s16LocalIdlSys_tqIdcCur,
                                            s16LocalIdlSys_tqIdcIdlMin);
                  s32LocalIIdlSys_tqIdcIdlIniAir =
                  (sint32)MATHSRV_udtMAX(s16LocalTqSys_tqIdcAirLimCordRes,
                                         s16LocalIdlSys_tqIdcIdlMin);
               }
               else
               {
                  s32LocalIdlSys_tqIdcIdlIni = s16LocalIdlSys_tqLoss;
                  s32LocalIIdlSys_tqIdcIdlIniAir = s16LocalIdlSys_tqLoss;
               }
            }
         }
      }
   s16LocalIdlSys_tqIdcIdlIni =
      (sint16)MATHSRV_udtCLAMP(s32LocalIdlSys_tqIdcIdlIni, -32000, 32000);
      VEMS_vidSET(IdlSys_tqIdcIdlIni, s16LocalIdlSys_tqIdcIdlIni);
   s16LocalIIdlSys_tqIdcIdlIniAir =
      (sint16)MATHSRV_udtCLAMP(s32LocalIIdlSys_tqIdcIdlIniAir, -32000, 32000);
      VEMS_vidSET(IdlSys_tqIdcIdlIniAir, s16LocalIIdlSys_tqIdcIdlIniAir);
   }
   else
   {
      VEMS_vidSET(IdlSys_tqIdcIdlIni, 0);
      VEMS_vidSET(IdlSys_tqIdcIdlIniAir, 0);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLMGR_vidPiloter_avances_mini                             */
/* !Description :  Dans ce bloc, on vient piloter spécifiquement les avances  */
/*                 minimum pour l’agrément lors de l’activation du régulateur */
/*                 de ralenti.                                                */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_08591_038.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean IdlSys_bAcvIdlCtl;                                          */
/*  input boolean IDLMGR_bAcvIdlCtlPrev;                                      */
/*  input boolean IDLMGR_bAcvIdlCtlSecPrev;                                   */
/*  input uint8 IdlSys_noGear;                                                */
/*  input uint8 IdlSys_tiAcvIgMinSpc_T[4];                                    */
/*  input uint8 Ext_tiTDC;                                                    */
/*  input uint16 IDLMGR_u16TurnOffDlyCnt2;                                    */
/*  input boolean IdlSys_bAcvIgMinSpc_C;                                      */
/*  input boolean IDLMGR_bTurnOffDelayOut2;                                   */
/*  output boolean IDLMGR_bTurnOffDelayOut2;                                  */
/*  output uint16 IDLMGR_u16TurnOffDlyCnt2;                                   */
/*  output boolean IdlSys_bAcvIgMinSpc;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLMGR_vidPiloter_avances_mini(void)
{
   boolean bLocalIdlSys_bAcvIdlCtl;
   uint8   u8LocalIdlSys_noGear;
   uint8   u8LocalExt_tiTDC;
   uint8   u8Localtemporisation;
   uint16  u16LocalTurnOffDlyCnt2;


   VEMS_vidGET(IdlSys_bAcvIdlCtl, bLocalIdlSys_bAcvIdlCtl);
   if (  (bLocalIdlSys_bAcvIdlCtl != 0)
      && (IDLMGR_bAcvIdlCtlPrev == 0))
   {
      IDLMGR_bTurnOffDelayOut2 = 1 ;
   }
   else
   {
      if (  (IDLMGR_bAcvIdlCtlPrev != 0)
         && (IDLMGR_bAcvIdlCtlSecPrev == 0))
      {
         VEMS_vidGET(IdlSys_noGear, u8LocalIdlSys_noGear);
         u8LocalIdlSys_noGear = (uint8)MATHSRV_udtMIN(u8LocalIdlSys_noGear, 3);
         u8Localtemporisation = IdlSys_tiAcvIgMinSpc_T[u8LocalIdlSys_noGear];
         u16LocalTurnOffDlyCnt2 = (uint16)((u8Localtemporisation * 125) / 2);
         IDLMGR_u16TurnOffDlyCnt2 =
            (uint16)MATHSRV_udtMIN(u16LocalTurnOffDlyCnt2, 5000);
      }
      else
      {
         VEMS_vidGET(Ext_tiTDC, u8LocalExt_tiTDC);
         if (IDLMGR_u16TurnOffDlyCnt2 >= u8LocalExt_tiTDC)
         {
            u16LocalTurnOffDlyCnt2 = (uint16)( IDLMGR_u16TurnOffDlyCnt2
                                             - u8LocalExt_tiTDC);
            IDLMGR_u16TurnOffDlyCnt2 =
               (uint16)MATHSRV_udtMIN(u16LocalTurnOffDlyCnt2, 5000);
         }
         else
         {
            IDLMGR_u16TurnOffDlyCnt2 = 0;
         }
      }
      if (IDLMGR_u16TurnOffDlyCnt2 != 0)
      {
         IDLMGR_bTurnOffDelayOut2 = 1;
      }
      else
      {
         IDLMGR_bTurnOffDelayOut2 = 0;
      }
   }
   if (  (IdlSys_bAcvIgMinSpc_C != 0)
      && (bLocalIdlSys_bAcvIdlCtl != 0)
      && (IDLMGR_bTurnOffDelayOut2 != 0))
   {
      VEMS_vidSET(IdlSys_bAcvIgMinSpc, 1);
   }
   else
   {
      VEMS_vidSET(IdlSys_bAcvIgMinSpc, 0);
   }
}
/*------------------------------- end of file --------------------------------*/