/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TOILEST                                                 */
/* !Description     : TOILEST Component                                       */
/*                                                                            */
/* !Module          : TOILEST                                                 */
/* !Description     : ESTIMATION DE LA TEMPERATURE D'HUILE                    */
/*                                                                            */
/* !File            : TOILEST_FCT2.C                                          */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / TOILEST_vidCalculEtatEstimateur                                      */
/*   2 / TOILEST_vidCalcThuileInit                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_5050596 / 02                                        */
/* !OtherRefs   : CSMT_CGMT08_2341 / 2.7                                      */
/* !OtherRefs   : VEMS V02 ECU#050185                                         */
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
#include "TOILEST_im.h"
#include "TOILEST.h"
#include "TOILEST_l.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TOILEST_vidCalculEtatEstimateur                            */
/* !Description :  Cette fonction permet de déterminer l’état de calcul de    */
/*                 l’estimateur de température d’huile ainsi qu’un flag       */
/*                 activant l’initialisation du modèle.                       */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_07613_005.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean CoPTSt_bEngRun;                                             */
/*  input uint8 Eng_stTOilCalc;                                               */
/*  input sint8 Ext_tAir;                                                     */
/*  input sint8 Eng_tAirVldMax_C;                                             */
/*  input uint8 Eng_tiInvldTAir;                                              */
/*  input uint8 Eng_tiInvldTAirMax_C;                                         */
/*  output uint8 Eng_stTOilCalc;                                              */
/*  output boolean Eng_bIniTOil;                                              */
/*  output uint8 Eng_tiInvldTAir;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TOILEST_vidCalculEtatEstimateur(void)
{
   boolean  bLocalCoPTSt_bEngRun;
   sint8    s8LocalExt_tAir;


   VEMS_vidGET(CoPTSt_bEngRun, bLocalCoPTSt_bEngRun);
   switch (Eng_stTOilCalc)
   {
      case 0:
         VEMS_vidGET(Ext_tAir, s8LocalExt_tAir);
         if (  (s8LocalExt_tAir <= Eng_tAirVldMax_C)
            || (Eng_tiInvldTAir >= Eng_tiInvldTAirMax_C))
         {
            Eng_stTOilCalc = 1;
            Eng_bIniTOil = 1;
         }
         else
         {
            Eng_tiInvldTAir = (uint8)(Eng_tiInvldTAir + 1);
         }
         Eng_tiInvldTAir = (uint8)MATHSRV_udtMIN(Eng_tiInvldTAir, 250);
         break;

      case 1:
         Eng_bIniTOil = 0;
         Eng_stTOilCalc = 2;
         break;

      case 2:
         Eng_bIniTOil = 0;
         if (bLocalCoPTSt_bEngRun != 0)
         {
            Eng_stTOilCalc = 3;
         }
         break;

      case 3:
         Eng_bIniTOil = 0;
         if (bLocalCoPTSt_bEngRun == 0)
         {
            Eng_stTOilCalc = 2;
         }
         break;

      default:
         Eng_stTOilCalc = 0;
         Eng_bIniTOil = 0;
         Eng_tiInvldTAir = 0;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TOILEST_vidCalcThuileInit                                  */
/* !Description :  Cette fonction estime la température de l'huile à          */
/*                 l’initialisation du calculateur.                           */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_06089_014.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint8 Ext_tAir;                                                     */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input uint32 Ext_ctSecEngStop;                                            */
/*  input uint16 Eng_rCorTOilIni_A[12];                                       */
/*  input uint8 Eng_rCorTOilIni_T[12];                                        */
/*  input uint8 Eng_rTOilIni_C;                                               */
/*  input sint8 Ext_tAir_NV;                                                  */
/*  input sint16 Ext_tCoMes_NV;                                               */
/*  input sint16 Eng_tOilEstim_NV;                                            */
/*  input sint16 Eng_tOilEstimIni2_MP;                                        */
/*  input uint16 Eng_rCorTOilIni_MP;                                          */
/*  input sint16 Eng_tOilEstimIni1_MP;                                        */
/*  input sint16 Eng_tOilEstimIni3_MP;                                        */
/*  output uint16 Eng_rCorTOilIni_MP;                                         */
/*  output sint16 Eng_tOilEstimIni1_MP;                                       */
/*  output sint16 Eng_tOilEstimIni2_MP;                                       */
/*  output sint16 Eng_tOilEstimIni3_MP;                                       */
/*  output sint16 Eng_tOilEstimIni;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TOILEST_vidCalcThuileInit(void)
{
   sint8  s8LocalExt_tAir;
   uint16 u16LocalPara;
   uint16 u16LocalEOM_ctSecEngStop;
   uint16 u16LocalEng_rCorTOilIni_MP;
   sint16 s16LocalExt_tCoMes;
   sint16 s16LocalEng_tOilEstimIni;
   uint32 u32LocalExt_ctSecEngStop;
   sint32 s32LocalEng_tOilDeltaIni1;
   sint32 s32LocalEng_tOilDeltaIni2;
   sint32 s32LocalEng_tOilDeltaIni3;


   VEMS_vidGET(Ext_tAir, s8LocalExt_tAir);
   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   VEMS_vidGET(Ext_ctSecEngStop, u32LocalExt_ctSecEngStop);

   /* Computing temperature correction factor using 1D interpolation */
   u16LocalEOM_ctSecEngStop =
      (uint16)MATHSRV_udtMIN(u32LocalExt_ctSecEngStop, 65535);
   u16LocalPara = MATHSRV_u16CalcParaIncAryU16(Eng_rCorTOilIni_A,
                                               u16LocalEOM_ctSecEngStop,
                                               12);
   u16LocalEng_rCorTOilIni_MP = MATHSRV_u8Interp1d(Eng_rCorTOilIni_T,
                                                   u16LocalPara);
   u16LocalEng_rCorTOilIni_MP = (uint16)(u16LocalEng_rCorTOilIni_MP * 8);
   Eng_rCorTOilIni_MP = (uint16)MATHSRV_udtMIN(u16LocalEng_rCorTOilIni_MP,
                                               1024);

   /* Computing intermediate initialization temperatures */
   s32LocalEng_tOilDeltaIni1 = ( ( (sint32)( s16LocalExt_tCoMes
                                           - (sint16)s8LocalExt_tAir)
                                 * Eng_rTOilIni_C)
                               / 32);
   Eng_tOilEstimIni1_MP = (sint16)MATHSRV_udtCLAMP(s32LocalEng_tOilDeltaIni1,
                                                   -200,
                                                   800);

   s32LocalEng_tOilDeltaIni2 = ( ( (sint32)( (sint16)Ext_tAir_NV
                                           - Ext_tCoMes_NV)
                                 * Eng_rTOilIni_C)
                               / 32);
   Eng_tOilEstimIni2_MP = (sint16)MATHSRV_udtCLAMP(s32LocalEng_tOilDeltaIni2,
                                                   -800,
                                                   200);

   s32LocalEng_tOilDeltaIni3 = ( (sint32)( Eng_tOilEstim_NV
                                         - (sint16)Ext_tAir_NV)
                               * 4);

   s32LocalEng_tOilDeltaIni3 = ( ( ( Eng_tOilEstimIni2_MP
                                   + s32LocalEng_tOilDeltaIni3)
                                 * Eng_rCorTOilIni_MP)
                               + 512)
                             / 1024;
   Eng_tOilEstimIni3_MP = (sint16)MATHSRV_udtCLAMP(s32LocalEng_tOilDeltaIni3,
                                                   -200,
                                                   800);

   /* Computing oil temperature at ECU reset */
   s16LocalEng_tOilEstimIni = (sint16)( (s8LocalExt_tAir * 4)
                              + Eng_tOilEstimIni1_MP
                              + Eng_tOilEstimIni3_MP);
   Eng_tOilEstimIni = (sint16)MATHSRV_udtCLAMP(s16LocalEng_tOilEstimIni,
                                               -200,
                                               800);
}
/*--------------------------------- end of file ------------------------------*/