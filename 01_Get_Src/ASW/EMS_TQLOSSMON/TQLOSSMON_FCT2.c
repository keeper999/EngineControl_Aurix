/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQLOSSMON                                               */
/* !Description     : TQLOSSMON component.                                    */
/*                                                                            */
/* !Module          : TQLOSSMON                                               */
/* !Description     : Safety TMS : Valider Pertes Globales                    */
/*                                                                            */
/* !File            : TQLOSSMON_FCT2.C                                        */
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
/*   1 / TQLOSSMON_vidDet_Pertes_Clim                                         */
/*   2 / TQLOSSMON_vidDet_P_Conso_Type3                                       */
/*   3 / TQLOSSMON_vidDet_P_Conso_Type4                                       */
/*   4 / TQLOSSMON_vidConvertir_P_Couple                                      */
/*   5 / TQLOSSMON_vidChoisir_Type_Clim                                       */
/*   6 / TQLOSSMON_vidFiltrer_redond_ACS                                      */
/*   7 / TQLOSSMON_vidCalculer_Couple                                         */
/*   8 / TQLOSSMON_vidValider_Pertes_Clim                                     */
/*                                                                            */
/* !Reference   : V02 NT 10 01233 / 03                                        */
/* !OtherRefs   : CSCT_CGMT09_1793 / 1.5                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQLOSSMON/TQLOSSMON_FC$*/
/* $Revision::   1.7      $$Author::   mbenfrad       $$Date::   28 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   28 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TQLOSSMON.h"
#include "TQLOSSMON_L.h"
#include "TQLOSSMON_IM.h"
#include "SWFAIL.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidDet_Pertes_Clim                               */
/* !Description :  Le calcul qui permet de déterminer le couple prélevé par la*/
/*                 climatisation est composé de deux étapes                   */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQLOSSMON_vidDet_P_Conso_Type3();                        */
/*  extf argret void TQLOSSMON_vidDet_P_Conso_Type4();                        */
/*  extf argret void TQLOSSMON_vidConvertir_P_Couple();                       */
/*  extf argret void TQLOSSMON_vidValider_Pertes_Clim();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidDet_Pertes_Clim(void)
{
   TQLOSSMON_vidDet_P_Conso_Type3();
   TQLOSSMON_vidDet_P_Conso_Type4();
   TQLOSSMON_vidConvertir_P_Couple();
   TQLOSSMON_vidValider_Pertes_Clim();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidDet_P_Conso_Type3                             */
/* !Description :  Le calcul de la puissance prélevée par la clim de type 3 se*/
/*                 compose de deux modules : le couple de base et le couple à */
/*                 l’enclenchement.                                           */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_nCkFilBuf;                                           */
/*  input uint16 SftyMgt_tqAC3BasLossMax_C;                                   */
/*  input uint16 SftyMgt_tqAC3OnLossMax_C;                                    */
/*  input uint16 SftyMgt_tq_X_A[8];                                           */
/*  input uint16 TQLOSSMON_u16tqAC3LossMax;                                   */
/*  input uint16 SftyMgt_nCk_Y_A[16];                                         */
/*  input uint16 SftyMgt_facCnvTqrPwr_M[8][16];                               */
/*  output uint16 TQLOSSMON_u16tqAC3LossMax;                                  */
/*  output uint16 SftyMgt_pwrAC3Loss;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidDet_P_Conso_Type3(void)
{
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   uint16 u16LocalSftyMgt_nCkFilBuf;
   uint32 u32LocaltqAC3LossMax;


   VEMS_vidGET(SftyMgt_nCkFilBuf, u16LocalSftyMgt_nCkFilBuf);

   u32LocaltqAC3LossMax = (uint32)( SftyMgt_tqAC3BasLossMax_C
                                  + SftyMgt_tqAC3OnLossMax_C);
   TQLOSSMON_u16tqAC3LossMax = (uint16)MATHSRV_udtMIN(u32LocaltqAC3LossMax,
                                                      8000);

   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(SftyMgt_tq_X_A,
                                                    TQLOSSMON_u16tqAC3LossMax,
                                                    8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(SftyMgt_nCk_Y_A,
                                                    u16LocalSftyMgt_nCkFilBuf,
                                                    16);
   SftyMgt_pwrAC3Loss = MATHSRV_u16Interp2d(&SftyMgt_facCnvTqrPwr_M[0][0],
                                            u16LocalCalcParaX,
                                            u16LocalCalcParaY,
                                            16);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidDet_P_Conso_Type4                             */
/* !Description :  Ne redondant pas le booléen d’embrayage du compresseur de  */
/*                 clim les filtrages ne peuvent être pris en compte. Pour    */
/*                 cette raison la puissance sortant de cette fonction est la */
/*                 puissance maximale autorisée.                              */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 SftyMgt_pwrACMax_C;                                          */
/*  output uint16 SftyMgt_pwrAC4Loss;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidDet_P_Conso_Type4(void)
{
   SftyMgt_pwrAC4Loss = (uint16)MATHSRV_udtMIN(SftyMgt_pwrACMax_C, 5000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidConvertir_P_Couple                            */
/* !Description :  Cette fonction se décompose en trois sous fonctions  :     */
/*                 Sélectionner le type de clim, Filtrer le signal, Déterminer*/
/*                 le couple prélevé                                          */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQLOSSMON_vidChoisir_Type_Clim();                        */
/*  extf argret void TQLOSSMON_vidFiltrer_redond_ACS();                       */
/*  extf argret void TQLOSSMON_vidCalculer_Couple();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidConvertir_P_Couple(void)
{
   TQLOSSMON_vidChoisir_Type_Clim();
   TQLOSSMON_vidFiltrer_redond_ACS();
   TQLOSSMON_vidCalculer_Couple();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidChoisir_Type_Clim                             */
/* !Description :  Cette fonction retient le signal correspondant au type de  */
/*                 clim du véhicule.                                          */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint16 SftyMgt_pwrAC5Loss;                                          */
/*  input uint8 SftyMgt_idxACTyp_C;                                           */
/*  input uint16 SftyMgt_pwrAC3Loss;                                          */
/*  input uint16 SftyMgt_pwrAC4Loss;                                          */
/*  output uint16 SftyMgt_pwrACLoss;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidChoisir_Type_Clim(void)
{
   uint16 u16LocalpwrACLoss;
   uint16 u16LocalSftyMgt_pwrAC5Loss;


   VEMS_vidGET(SftyMgt_pwrAC5Loss, u16LocalSftyMgt_pwrAC5Loss);

   switch (SftyMgt_idxACTyp_C)
   {
      case 0:
         u16LocalpwrACLoss = 0;
         break;
      case 1:
         u16LocalpwrACLoss = SftyMgt_pwrAC3Loss;
         break;
      case 2:
         u16LocalpwrACLoss = SftyMgt_pwrAC4Loss;
         break;
      case 3:
         u16LocalpwrACLoss = u16LocalSftyMgt_pwrAC5Loss;
         break;
      default:
         u16LocalpwrACLoss = u16LocalSftyMgt_pwrAC5Loss;
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
   SftyMgt_pwrACLoss = (uint16)MATHSRV_udtMIN(u16LocalpwrACLoss, 5000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidFiltrer_redond_ACS                            */
/* !Description :  Cette fonction de filtrage est redondée de l’ACS.          */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_nCkFilBuf;                                           */
/*  input boolean SftyMgt_bTqGrdLimBuf;                                       */
/*  input uint16 SftyMgt_nCk_X_A[16];                                         */
/*  input uint16 SftyMgt_facFilTqACLossUp_T[16];                              */
/*  input uint16 SftyMgt_facFilTqACLossDown_T[16];                            */
/*  input uint16 SftyMgt_facFilTqACLoss_C;                                    */
/*  input uint16 SftyMgt_pwrACLossFil;                                        */
/*  input uint16 SftyMgt_pwrACLoss;                                           */
/*  input uint16 SftyMgt_facFilTqACLossUp_MP;                                 */
/*  input uint16 SftyMgt_facFilTqACLossDown_MP;                               */
/*  input uint16 SftyMgt_pwrACLossSum_MP;                                     */
/*  input uint16 SftyMgt_facFilTqACLossFil_MP;                                */
/*  output uint16 SftyMgt_facFilTqACLossUp_MP;                                */
/*  output uint16 SftyMgt_facFilTqACLossDown_MP;                              */
/*  output uint16 SftyMgt_facFilTqACLossFil_MP;                               */
/*  output uint16 SftyMgt_pwrACLossSum_MP;                                    */
/*  output uint16 SftyMgt_pwrACLossFil;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidFiltrer_redond_ACS(void)
{
   boolean bLocalSftyMgt_bTqGrdLimBuf;
   uint16  u16LocalCalcPara;
   uint16  u16LocalInterpolation;
   uint16  u16LocalfacFilTqACLoss;
   uint16  u16LocalSftyMgt_nCkFilBuf;
   uint32  u32LocalModifCoef;
   uint32  u32LocalUnsignedDiff;
   sint32  s32LocalSignedDiff;
   sint32  s32LocaltqStgPmpLossSum;


   VEMS_vidGET(SftyMgt_nCkFilBuf, u16LocalSftyMgt_nCkFilBuf);
   VEMS_vidGET(SftyMgt_bTqGrdLimBuf, bLocalSftyMgt_bTqGrdLimBuf);

   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(SftyMgt_nCk_X_A,
                                                   u16LocalSftyMgt_nCkFilBuf,
                                                   16);
   u16LocalInterpolation =
      MATHSRV_u16Interp1d(SftyMgt_facFilTqACLossUp_T, u16LocalCalcPara);
   SftyMgt_facFilTqACLossUp_MP = (uint16)MATHSRV_udtMIN(u16LocalInterpolation,
                                                        999);

   u16LocalInterpolation =
      MATHSRV_u16Interp1d(SftyMgt_facFilTqACLossDown_T, u16LocalCalcPara);
   SftyMgt_facFilTqACLossDown_MP = (uint16)MATHSRV_udtMIN(u16LocalInterpolation,
                                                          999);

   if (bLocalSftyMgt_bTqGrdLimBuf != 0)
   {
      u16LocalfacFilTqACLoss = SftyMgt_facFilTqACLoss_C;
   }
   else
   {
      if (SftyMgt_pwrACLossFil <= SftyMgt_pwrACLoss)
      {
         u16LocalfacFilTqACLoss = SftyMgt_facFilTqACLossUp_MP;
      }
      else
      {
         u16LocalfacFilTqACLoss = SftyMgt_facFilTqACLossDown_MP;
      }
   }

   u32LocalModifCoef = (uint32)(1000000 / (u16LocalfacFilTqACLoss + 1));
   u32LocalModifCoef = (u32LocalModifCoef + 3000);
   u32LocalModifCoef = (4000000000uL / u32LocalModifCoef);
   u32LocalModifCoef = (u32LocalModifCoef - 1000);
   u32LocalModifCoef = ((u32LocalModifCoef + 500) / 1000);

   SftyMgt_facFilTqACLossFil_MP = (uint16)MATHSRV_udtMIN(u32LocalModifCoef,
                                                         999);

   s32LocalSignedDiff = (sint32)( SftyMgt_pwrACLoss
                                - SftyMgt_pwrACLossSum_MP);

   u32LocalUnsignedDiff = (uint32)(SftyMgt_facFilTqACLossFil_MP + 1);

   s32LocaltqStgPmpLossSum = s32LocalSignedDiff * (sint32)u32LocalUnsignedDiff;

   s32LocaltqStgPmpLossSum = s32LocaltqStgPmpLossSum
                           + (sint32)(SftyMgt_pwrACLossSum_MP * 1000);
   s32LocaltqStgPmpLossSum = (s32LocaltqStgPmpLossSum / 1000);

   SftyMgt_pwrACLossSum_MP = (uint16)MATHSRV_udtMIN(s32LocaltqStgPmpLossSum,
                                                    5000);

   if (u16LocalfacFilTqACLoss == 999)
   {
      SftyMgt_pwrACLossFil = (uint16)MATHSRV_udtMIN(SftyMgt_pwrACLoss, 5000);
   }
   else
   {
      SftyMgt_pwrACLossFil = SftyMgt_pwrACLossSum_MP;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidCalculer_Couple                               */
/* !Description :  Cette fonction permet de convertir la puissance en couple  */
/*                 via une cartographie fonction du régime moteur et de la    */
/*                 puissance filtrée.                                         */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_nCkFilBuf;                                           */
/*  input uint16 SftyMgt_pwr_X_A[8];                                          */
/*  input uint16 SftyMgt_pwrACLossFil;                                        */
/*  input uint16 SftyMgt_nCk_Y_A[16];                                         */
/*  input uint16 SftyMgt_facCnvPwrTqr_M[8][16];                               */
/*  input uint16 SftyMgt_tqACLossMin_C;                                       */
/*  input uint16 SftyMgt_tqACLossMax_C;                                       */
/*  output uint16 SftyMgt_tqACLoss;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidCalculer_Couple(void)
{
   uint16 u16LocalCalcParaX;
   uint16 u16LocalCalcParaY;
   uint16 u16LocalfacCnvPwrTqr;
   uint16 u16LocalSftyMgt_tqACLoss;
   uint16 u16LocalSftyMgt_nCkFilBuf;
   uint32 u32LocalfacCnvPwrTqr;


   VEMS_vidGET(SftyMgt_nCkFilBuf, u16LocalSftyMgt_nCkFilBuf);
   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(SftyMgt_pwr_X_A,
                                                    SftyMgt_pwrACLossFil,
                                                    8);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU16(SftyMgt_nCk_Y_A,
                                                    u16LocalSftyMgt_nCkFilBuf,
                                                    16);
   u16LocalfacCnvPwrTqr = MATHSRV_u16Interp2d(&SftyMgt_facCnvPwrTqr_M[0][0],
                                              u16LocalCalcParaX,
                                              u16LocalCalcParaY,
                                              16);
   u32LocalfacCnvPwrTqr = (uint32)(u16LocalfacCnvPwrTqr * 16);
   u16LocalSftyMgt_tqACLoss = (uint16)MATHSRV_udtCLAMP(u32LocalfacCnvPwrTqr,
                                                       SftyMgt_tqACLossMin_C,
                                                       SftyMgt_tqACLossMax_C);
   SftyMgt_tqACLoss = (uint16)MATHSRV_udtMIN(u16LocalSftyMgt_tqACLoss, 8000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQLOSSMON_vidValider_Pertes_Clim                           */
/* !Description :  Cette fonction permet de valider la sortie du couple clim  */
/*                 en s’assurant que ce couple est inférieur au couple max    */
/*                 calculé par son équivalent dans l’ACS.                     */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_01233_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_tqACLossUnChkBuf;                                    */
/*  input uint16 SftyMgt_tqErrThdSftyLossAux_C;                               */
/*  input uint16 SftyMgt_tqACLoss;                                            */
/*  input uint16 SftyMgt_tqACLoss_MP;                                         */
/*  output uint16 SftyMgt_tqACLoss_MP;                                        */
/*  output boolean SftyMgt_bDgoTqAC;                                          */
/*  output uint16 SftyMgt_tqACLossChkBuf;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQLOSSMON_vidValider_Pertes_Clim(void)
{
   uint16 u16LocalSftyMgt_tqACLossUnChkBuf;
   uint32 u32LocaltqACLoss;


   VEMS_vidGET(SftyMgt_tqACLossUnChkBuf, u16LocalSftyMgt_tqACLossUnChkBuf);

   u32LocaltqACLoss = (uint32)( SftyMgt_tqErrThdSftyLossAux_C
                              + SftyMgt_tqACLoss);
   SftyMgt_tqACLoss_MP = (uint16)MATHSRV_udtMIN(u32LocaltqACLoss, 8000);

   if (SftyMgt_tqACLoss_MP < u16LocalSftyMgt_tqACLossUnChkBuf)
   {
      SftyMgt_bDgoTqAC = 1;
   }
   else
   {
      SftyMgt_bDgoTqAC = 0;
   }

   SftyMgt_tqACLossChkBuf =
      (uint16)MATHSRV_udtMIN(u16LocalSftyMgt_tqACLossUnChkBuf, 8000);
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"

/*---------------------------- end of file -----------------------------------*/