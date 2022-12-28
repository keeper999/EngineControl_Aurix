/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : agInjSp                                                 */
/* !Description     : agInjSp : INJECTION ANGLE SETPOINTS                     */
/*                                                                            */
/* !Module          : agInjSp                                                 */
/*                                                                            */
/* !File            : agInjSp.c                                               */
/*                                                                            */
/* !Target          : All (optimized for "32-bit Generic")                    */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/* !Reference       : V01NT1006217 / 01                                       */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Wed Nov 16 18:31:21 2011                              */
/*   Model name       : agInjSp_AUTOCODE.mdl                                  */
/*   Model version    : 1.142                                                 */
/*   Root subsystem   : /agInjSp                                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/AGINJSP/agInjSp.c_v       $*/
/* $Revision::   1.2                                                         $*/
/* $Author::   etsasson                               $$Date::   07 Mar 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "agInjSp.h"
#include "agInjSp_private.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
/* !Comment: Define data in section "SEC_VAR_UNSPECIFIED" */
#define AGINJSP_START_SEC_VAR_UNSPECIFIED
#include "agInjSp_MemMap.h"

/* Block signals (auto storage) */
BlockIO_agInjSp agInjSp_B;

#define AGINJSP_STOP_SEC_VAR_UNSPECIFIED
#include "agInjSp_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define AGINJSP_START_SEC_CODE
#include "agInjSp_MemMap.h"

void agInjSp_ASYNC1(int controlPortIdx)
{
}

/* Start for exported function: InjSys_EveRst_agInjSp */
void InjSys_EveRst_agInjSp_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S1>/expFcn' incorporates:
   *  Start for SubSystem: '<S3>/F01_Initialization'
   */
}

/* Output and update for exported function: InjSys_EveRst_agInjSp */
void InjSys_EveRst_agInjSp(void)
{
  /* S-Function (fcncallgen): '<S1>/expFcn' incorporates:
   *  SubSystem: '<S3>/F01_Initialization'
   */
  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET */
  VEMS_vidSET(InjSys_agInj1Sp, 3200U);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET1 */
  VEMS_vidSET(InjSys_agInj2Sp, 2133U);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET2 */
  VEMS_vidSET(InjSys_agInj3Sp, 640U);
}

/* Start for exported function: InjSys_SdlFast_agInjSp */
void InjSys_SdlFast_agInjSp_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S3>/F02_agInjSp'
   */
}

/* Output and update for exported function: InjSys_SdlFast_agInjSp */
void InjSys_SdlFast_agInjSp(void)
{
  /* local block i/o variables */
  UInt16 localLookUpTable2D;
  UInt16 localLookUpTable2D_n;
  UInt16 localLookUpTable2D_l;
  UInt16 localLookUpTable2D_a;
  UInt16 localLookUpTable2D_k;
  UInt16 localLookUpTable2D_b;
  UInt16 localLookUpTable2D_i;
  UInt16 localLookUpTable2D_ax;
  UInt16 localLookUpTable2D_h;
  UInt16 localLookUpTable2D_f;
  UInt16 localLookUpTable2D_ba;
  UInt16 localLookUpTable2D_nv;
  UInt16 localLookUpTable2D_kb;
  UInt16 localLookUpTable2D_p;
  UInt16 localLookUpTable2D_e;
  UInt16 localLookUpTable2D_f3;
  UInt16 localLookUpTable2D_by;
  UInt16 localLookUpTable2D_p1;
  UInt16 localLookUpTable2D_g;
  UInt16 localLookUpTable2D_a3;
  UInt16 localLookUpTable2D_o;
  UInt16 localLookUpTable2D_kh;
  UInt16 localLookUpTable2D_kf;
  UInt16 localLookUpTable2D_nf;
  UInt16 localLookUpTable2D_ia;
  UInt16 localLookUpTable2D_i2;
  UInt16 localLookUpTable2D_m;
  UInt16 localLookUpTable2D_j;
  UInt16 localLookUpTable2D_b1;
  UInt16 localLookUpTable2D_hq;
  UInt16 localLookUpTable2D_hx;
  UInt16 localLookUpTable2D_it;
  UInt16 localLookUpTable2D_bj;
  UInt16 localLookUpTable2D_h0;
  UInt16 localLookUpTable2D_n1;
  UInt16 localLookUpTable2D_et;
  UInt16 localLookUpTable2D_nh;
  UInt16 localLookUpTable2D_p5;
  UInt16 localLookUpTable2D_mi;
  UInt16 localLookUpTable2D_bz;
  UInt16 localLookUpTable2D_ic;
  UInt16 localLookUpTable2D_p2;
  UInt16 localLookUpTable2D_lr;
  UInt16 localLookUpTable2D_gy;
  UInt16 localLookUpTable2D_ev;
  UInt16 localLookUpTable2D_jo;
  UInt16 localLookUpTable2D_fr;
  UInt16 localLookUpTable2D_hb;
  Boolean localAssignment2[15];
  UInt8 localSwitch2;
  Float localDivide_k;
  SInt32 locali;
  Double localtmp;

  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S3>/F02_agInjSp'
   */
  /* S-Function "vems_vidGET" Block: <S5>/VEMS_vidGET */
  VEMS_vidGET(Ext_nEng, agInjSp_B.VEMS_vidGET);

  /* DataTypeConversion Block: '<S8>/Data Type Conversion'
   *
   * Regarding '<S8>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S9>/Data Type Conversion'
   *
   * Regarding '<S9>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S10>/Data Type Conversion'
   *
   * Regarding '<S10>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* S-Function "vems_vidGET" Block: <S5>/VEMS_vidGET1 */
  VEMS_vidGET(Ext_pDsThrMesSI, agInjSp_B.VEMS_vidGET1);

  /* DataTypeConversion Block: '<S8>/Data Type Conversion1'
   *
   * Regarding '<S8>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S8>/Data Type Duplicate1'
   *
   * Regarding '<S8>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S9>/Data Type Conversion1'
   *
   * Regarding '<S9>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S9>/Data Type Duplicate1'
   *
   * Regarding '<S9>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S10>/Data Type Conversion1'
   *
   * Regarding '<S10>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S10>/Data Type Duplicate1'
   *
   * Regarding '<S10>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* S-Function "vems_vidGET" Block: <S5>/VEMS_vidGET9 */
  VEMS_vidGET(InjSys_mAirPredInjSp, agInjSp_B.VEMS_vidGET9);

  /* DataTypeConversion Block: '<S51>/Data Type Conversion1'
   *
   * Regarding '<S51>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S51>/Data Type Duplicate1'
   *
   * Regarding '<S51>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S52>/Data Type Conversion1'
   *
   * Regarding '<S52>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S52>/Data Type Duplicate1'
   *
   * Regarding '<S52>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S53>/Data Type Conversion1'
   *
   * Regarding '<S53>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S53>/Data Type Duplicate1'
   *
   * Regarding '<S53>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S54>/Data Type Conversion1'
   *
   * Regarding '<S54>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S54>/Data Type Duplicate1'
   *
   * Regarding '<S54>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S55>/Data Type Conversion1'
   *
   * Regarding '<S55>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S55>/Data Type Duplicate1'
   *
   * Regarding '<S55>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S56>/Data Type Conversion1'
   *
   * Regarding '<S56>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S56>/Data Type Duplicate1'
   *
   * Regarding '<S56>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S57>/Data Type Conversion1'
   *
   * Regarding '<S57>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S57>/Data Type Duplicate1'
   *
   * Regarding '<S57>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S58>/Data Type Conversion1'
   *
   * Regarding '<S58>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S58>/Data Type Duplicate1'
   *
   * Regarding '<S58>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S59>/Data Type Conversion1'
   *
   * Regarding '<S59>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S59>/Data Type Duplicate1'
   *
   * Regarding '<S59>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S60>/Data Type Conversion1'
   *
   * Regarding '<S60>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S60>/Data Type Duplicate1'
   *
   * Regarding '<S60>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S61>/Data Type Conversion1'
   *
   * Regarding '<S61>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S61>/Data Type Duplicate1'
   *
   * Regarding '<S61>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S62>/Data Type Conversion1'
   *
   * Regarding '<S62>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S62>/Data Type Duplicate1'
   *
   * Regarding '<S62>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S63>/Data Type Conversion1'
   *
   * Regarding '<S63>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S63>/Data Type Duplicate1'
   *
   * Regarding '<S63>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S64>/Data Type Conversion1'
   *
   * Regarding '<S64>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S64>/Data Type Duplicate1'
   *
   * Regarding '<S64>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S65>/Data Type Conversion1'
   *
   * Regarding '<S65>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S65>/Data Type Duplicate1'
   *
   * Regarding '<S65>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S118>/Data Type Conversion1'
   *
   * Regarding '<S118>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S118>/Data Type Duplicate1'
   *
   * Regarding '<S118>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S119>/Data Type Conversion1'
   *
   * Regarding '<S119>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S119>/Data Type Duplicate1'
   *
   * Regarding '<S119>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S120>/Data Type Conversion1'
   *
   * Regarding '<S120>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S120>/Data Type Duplicate1'
   *
   * Regarding '<S120>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S121>/Data Type Conversion1'
   *
   * Regarding '<S121>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S121>/Data Type Duplicate1'
   *
   * Regarding '<S121>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S122>/Data Type Conversion1'
   *
   * Regarding '<S122>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S122>/Data Type Duplicate1'
   *
   * Regarding '<S122>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S123>/Data Type Conversion1'
   *
   * Regarding '<S123>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S123>/Data Type Duplicate1'
   *
   * Regarding '<S123>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S124>/Data Type Conversion1'
   *
   * Regarding '<S124>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S124>/Data Type Duplicate1'
   *
   * Regarding '<S124>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S125>/Data Type Conversion1'
   *
   * Regarding '<S125>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S125>/Data Type Duplicate1'
   *
   * Regarding '<S125>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S126>/Data Type Conversion1'
   *
   * Regarding '<S126>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S126>/Data Type Duplicate1'
   *
   * Regarding '<S126>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S127>/Data Type Conversion1'
   *
   * Regarding '<S127>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S127>/Data Type Duplicate1'
   *
   * Regarding '<S127>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S128>/Data Type Conversion1'
   *
   * Regarding '<S128>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S128>/Data Type Duplicate1'
   *
   * Regarding '<S128>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S129>/Data Type Conversion1'
   *
   * Regarding '<S129>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S129>/Data Type Duplicate1'
   *
   * Regarding '<S129>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S130>/Data Type Conversion1'
   *
   * Regarding '<S130>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S130>/Data Type Duplicate1'
   *
   * Regarding '<S130>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S131>/Data Type Conversion1'
   *
   * Regarding '<S131>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S131>/Data Type Duplicate1'
   *
   * Regarding '<S131>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S132>/Data Type Conversion1'
   *
   * Regarding '<S132>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S132>/Data Type Duplicate1'
   *
   * Regarding '<S132>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S185>/Data Type Conversion1'
   *
   * Regarding '<S185>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S185>/Data Type Duplicate1'
   *
   * Regarding '<S185>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S186>/Data Type Conversion1'
   *
   * Regarding '<S186>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S186>/Data Type Duplicate1'
   *
   * Regarding '<S186>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S187>/Data Type Conversion1'
   *
   * Regarding '<S187>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S187>/Data Type Duplicate1'
   *
   * Regarding '<S187>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S188>/Data Type Conversion1'
   *
   * Regarding '<S188>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S188>/Data Type Duplicate1'
   *
   * Regarding '<S188>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S189>/Data Type Conversion1'
   *
   * Regarding '<S189>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S189>/Data Type Duplicate1'
   *
   * Regarding '<S189>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S190>/Data Type Conversion1'
   *
   * Regarding '<S190>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S190>/Data Type Duplicate1'
   *
   * Regarding '<S190>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S191>/Data Type Conversion1'
   *
   * Regarding '<S191>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S191>/Data Type Duplicate1'
   *
   * Regarding '<S191>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S192>/Data Type Conversion1'
   *
   * Regarding '<S192>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S192>/Data Type Duplicate1'
   *
   * Regarding '<S192>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S193>/Data Type Conversion1'
   *
   * Regarding '<S193>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S193>/Data Type Duplicate1'
   *
   * Regarding '<S193>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S194>/Data Type Conversion1'
   *
   * Regarding '<S194>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S194>/Data Type Duplicate1'
   *
   * Regarding '<S194>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S195>/Data Type Conversion1'
   *
   * Regarding '<S195>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S195>/Data Type Duplicate1'
   *
   * Regarding '<S195>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S196>/Data Type Conversion1'
   *
   * Regarding '<S196>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S196>/Data Type Duplicate1'
   *
   * Regarding '<S196>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S197>/Data Type Conversion1'
   *
   * Regarding '<S197>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S197>/Data Type Duplicate1'
   *
   * Regarding '<S197>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S198>/Data Type Conversion1'
   *
   * Regarding '<S198>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S198>/Data Type Duplicate1'
   *
   * Regarding '<S198>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* DataTypeConversion Block: '<S199>/Data Type Conversion1'
   *
   * Regarding '<S199>/Data Type Conversion1':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeDuplicate Block: '<S199>/Data Type Duplicate1'
   *
   * Regarding '<S199>/Data Type Duplicate1':
   *   Unused code path elimination
   */

  /* S-Function "vems_vidGET" Block: <S5>/VEMS_vidGET10 */
  VEMS_vidGET(InjSys_nEngInjSp, agInjSp_B.VEMS_vidGET10);

  /* DataTypeConversion Block: '<S51>/Data Type Conversion'
   *
   * Regarding '<S51>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S52>/Data Type Conversion'
   *
   * Regarding '<S52>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S53>/Data Type Conversion'
   *
   * Regarding '<S53>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S54>/Data Type Conversion'
   *
   * Regarding '<S54>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S55>/Data Type Conversion'
   *
   * Regarding '<S55>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S56>/Data Type Conversion'
   *
   * Regarding '<S56>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S57>/Data Type Conversion'
   *
   * Regarding '<S57>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S58>/Data Type Conversion'
   *
   * Regarding '<S58>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S59>/Data Type Conversion'
   *
   * Regarding '<S59>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S60>/Data Type Conversion'
   *
   * Regarding '<S60>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S61>/Data Type Conversion'
   *
   * Regarding '<S61>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S62>/Data Type Conversion'
   *
   * Regarding '<S62>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S63>/Data Type Conversion'
   *
   * Regarding '<S63>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S64>/Data Type Conversion'
   *
   * Regarding '<S64>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S65>/Data Type Conversion'
   *
   * Regarding '<S65>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S118>/Data Type Conversion'
   *
   * Regarding '<S118>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S119>/Data Type Conversion'
   *
   * Regarding '<S119>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S120>/Data Type Conversion'
   *
   * Regarding '<S120>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S121>/Data Type Conversion'
   *
   * Regarding '<S121>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S122>/Data Type Conversion'
   *
   * Regarding '<S122>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S123>/Data Type Conversion'
   *
   * Regarding '<S123>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S124>/Data Type Conversion'
   *
   * Regarding '<S124>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S125>/Data Type Conversion'
   *
   * Regarding '<S125>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S126>/Data Type Conversion'
   *
   * Regarding '<S126>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S127>/Data Type Conversion'
   *
   * Regarding '<S127>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S128>/Data Type Conversion'
   *
   * Regarding '<S128>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S129>/Data Type Conversion'
   *
   * Regarding '<S129>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S130>/Data Type Conversion'
   *
   * Regarding '<S130>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S131>/Data Type Conversion'
   *
   * Regarding '<S131>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S132>/Data Type Conversion'
   *
   * Regarding '<S132>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S185>/Data Type Conversion'
   *
   * Regarding '<S185>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S186>/Data Type Conversion'
   *
   * Regarding '<S186>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S187>/Data Type Conversion'
   *
   * Regarding '<S187>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S188>/Data Type Conversion'
   *
   * Regarding '<S188>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S189>/Data Type Conversion'
   *
   * Regarding '<S189>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S190>/Data Type Conversion'
   *
   * Regarding '<S190>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S191>/Data Type Conversion'
   *
   * Regarding '<S191>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S192>/Data Type Conversion'
   *
   * Regarding '<S192>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S193>/Data Type Conversion'
   *
   * Regarding '<S193>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S194>/Data Type Conversion'
   *
   * Regarding '<S194>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S195>/Data Type Conversion'
   *
   * Regarding '<S195>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S196>/Data Type Conversion'
   *
   * Regarding '<S196>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S197>/Data Type Conversion'
   *
   * Regarding '<S197>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S198>/Data Type Conversion'
   *
   * Regarding '<S198>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* DataTypeConversion Block: '<S199>/Data Type Conversion'
   *
   * Regarding '<S199>/Data Type Conversion':
   *   Eliminate redundant data type conversion
   */

  /* S-Function "vems_vidGET" Block: <S5>/VEMS_vidGET5 */
  VEMS_vidGET(InjSys_idxBas1ModCurAgInj, agInjSp_B.VEMS_vidGET5);

  /* DataTypeDuplicate Block: '<S22>/Data Type Duplicate'
   *
   * Regarding '<S22>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* DataTypeDuplicate Block: '<S23>/Data Type Duplicate'
   *
   * Regarding '<S23>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S24>/Data Type Propagation'
   *
   * Regarding '<S24>/Data Type Propagation':
   *   Unused code path elimination
   */

  /* DataTypeDuplicate Block: '<S89>/Data Type Duplicate'
   *
   * Regarding '<S89>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* DataTypeDuplicate Block: '<S90>/Data Type Duplicate'
   *
   * Regarding '<S90>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S91>/Data Type Propagation'
   *
   * Regarding '<S91>/Data Type Propagation':
   *   Unused code path elimination
   */

  /* DataTypeDuplicate Block: '<S156>/Data Type Duplicate'
   *
   * Regarding '<S156>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* DataTypeDuplicate Block: '<S157>/Data Type Duplicate'
   *
   * Regarding '<S157>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S158>/Data Type Propagation'
   *
   * Regarding '<S158>/Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function "vems_vidGET" Block: <S5>/VEMS_vidGET7 */
  VEMS_vidGET(InjSys_idxBas2ModCurAgInj, agInjSp_B.VEMS_vidGET7);

  /* DataTypeDuplicate Block: '<S25>/Data Type Duplicate'
   *
   * Regarding '<S25>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* DataTypeDuplicate Block: '<S26>/Data Type Duplicate'
   *
   * Regarding '<S26>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S27>/Data Type Propagation'
   *
   * Regarding '<S27>/Data Type Propagation':
   *   Unused code path elimination
   */

  /* DataTypeDuplicate Block: '<S92>/Data Type Duplicate'
   *
   * Regarding '<S92>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* DataTypeDuplicate Block: '<S93>/Data Type Duplicate'
   *
   * Regarding '<S93>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S94>/Data Type Propagation'
   *
   * Regarding '<S94>/Data Type Propagation':
   *   Unused code path elimination
   */

  /* DataTypeDuplicate Block: '<S159>/Data Type Duplicate'
   *
   * Regarding '<S159>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* DataTypeDuplicate Block: '<S160>/Data Type Duplicate'
   *
   * Regarding '<S160>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S161>/Data Type Propagation'
   *
   * Regarding '<S161>/Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function "vems_vidGET" Block: <S5>/VEMS_vidGET6 */
  VEMS_vidGET(InjSys_idxBas1ModTarAgInj, agInjSp_B.VEMS_vidGET6);

  /* DataTypeDuplicate Block: '<S28>/Data Type Duplicate'
   *
   * Regarding '<S28>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* DataTypeDuplicate Block: '<S29>/Data Type Duplicate'
   *
   * Regarding '<S29>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S30>/Data Type Propagation'
   *
   * Regarding '<S30>/Data Type Propagation':
   *   Unused code path elimination
   */

  /* DataTypeDuplicate Block: '<S95>/Data Type Duplicate'
   *
   * Regarding '<S95>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* DataTypeDuplicate Block: '<S96>/Data Type Duplicate'
   *
   * Regarding '<S96>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S97>/Data Type Propagation'
   *
   * Regarding '<S97>/Data Type Propagation':
   *   Unused code path elimination
   */

  /* DataTypeDuplicate Block: '<S162>/Data Type Duplicate'
   *
   * Regarding '<S162>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* DataTypeDuplicate Block: '<S163>/Data Type Duplicate'
   *
   * Regarding '<S163>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S164>/Data Type Propagation'
   *
   * Regarding '<S164>/Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function "vems_vidGET" Block: <S5>/VEMS_vidGET8 */
  VEMS_vidGET(InjSys_idxBas2ModTarAgInj, agInjSp_B.VEMS_vidGET8);

  /* DataTypeDuplicate Block: '<S31>/Data Type Duplicate'
   *
   * Regarding '<S31>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* DataTypeDuplicate Block: '<S32>/Data Type Duplicate'
   *
   * Regarding '<S32>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S33>/Data Type Propagation'
   *
   * Regarding '<S33>/Data Type Propagation':
   *   Unused code path elimination
   */

  /* DataTypeDuplicate Block: '<S98>/Data Type Duplicate'
   *
   * Regarding '<S98>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* DataTypeDuplicate Block: '<S99>/Data Type Duplicate'
   *
   * Regarding '<S99>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S100>/Data Type Propagation'
   *
   * Regarding '<S100>/Data Type Propagation':
   *   Unused code path elimination
   */

  /* DataTypeDuplicate Block: '<S165>/Data Type Duplicate'
   *
   * Regarding '<S165>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* DataTypeDuplicate Block: '<S166>/Data Type Duplicate'
   *
   * Regarding '<S166>/Data Type Duplicate':
   *   Unused code path elimination
   */

  /* S-Function Block: '<S167>/Data Type Propagation'
   *
   * Regarding '<S167>/Data Type Propagation':
   *   Unused code path elimination
   */

  /* S-Function "vems_vidGET" Block: <S5>/VEMS_vidGET2 */
  VEMS_vidGET(InjSys_facBasModCurAgInj, agInjSp_B.VEMS_vidGET2);

  /* S-Function "vems_vidGET" Block: <S5>/VEMS_vidGET3 */
  VEMS_vidGET(InjSys_facBasModTarAgInj, agInjSp_B.VEMS_vidGET3);

  /* S-Function "vems_vidGET" Block: <S5>/VEMS_vidGET4 */
  VEMS_vidGET(InjSys_facTranModAgInj, agInjSp_B.VEMS_vidGET4);

  /* If: '<S5>/If' incorporates:
   *  ActionPort: '<S6>/Action Port'
   *  ActionPort: '<S7>/Action Port'
   *  Constant: '<S5>/InjSys_bAcvETBagInjSp_C'
   *  SubSystem: '<S5>/F00_agInjSpETB'
   *  SubSystem: '<S5>/F01_agInjSpClcn'
   */
  if (InjSys_bAcvETBagInjSp_C) {
    /* Lookup2D: '<S8>/Look-Up Table (2-D)'
     * About '<S8>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U16  2^3
     * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_U16( &(localLookUpTable2D_jo), (&(InjSys_agInj1SpETB_M[0])),
                       agInjSp_B.VEMS_vidGET, (&(Ext_nEngX_A[0])), 15U,
                       agInjSp_B.VEMS_vidGET1, (&(Ext_pDsThrMesSIY_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S8>/Data Type Duplicate2'
     *
     * Regarding '<S8>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S9>/Look-Up Table (2-D)'
     * About '<S9>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U16  2^3
     * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_U16( &(localLookUpTable2D_fr), (&(InjSys_agInj2SpETB_M[0])),
                       agInjSp_B.VEMS_vidGET, (&(Ext_nEngX_A[0])), 15U,
                       agInjSp_B.VEMS_vidGET1, (&(Ext_pDsThrMesSIY_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S9>/Data Type Duplicate2'
     *
     * Regarding '<S9>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* Lookup2D: '<S10>/Look-Up Table (2-D)'
     * About '<S10>/Look-Up Table (2-D)':
     * Input0  Data Type:  Integer        U16
     * Input1  Data Type:  Fixed Point    U16  2^3
     * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_U16_U16_U16( &(localLookUpTable2D_hb), (&(InjSys_agInj3SpETB_M[0])),
                       agInjSp_B.VEMS_vidGET, (&(Ext_nEngX_A[0])), 15U,
                       agInjSp_B.VEMS_vidGET1, (&(Ext_pDsThrMesSIY_A[0])), 15U);

    /* DataTypeDuplicate Block: '<S10>/Data Type Duplicate2'
     *
     * Regarding '<S10>/Data Type Duplicate2':
     *   Unused code path elimination
     */

    /* MultiPortSwitch: '<S6>/Multiport Switch' incorporates:
     *  Constant: '<S6>/InjSys_agInj1SpETB_C'
     *  Constant: '<S6>/InjSys_noETBSelagInj1Sp_C'
     *  Lookup2D: '<S8>/Look-Up Table (2-D)'
     */
    if (InjSys_noETBSelagInj1Sp_C == 0) {
      agInjSp_B.Merge = InjSys_agInj1SpETB_C;
    } else {
      agInjSp_B.Merge = localLookUpTable2D_jo;
    }

    /* MultiPortSwitch: '<S6>/Multiport Switch1' incorporates:
     *  Constant: '<S6>/InjSys_agInj2SpETB_C'
     *  Constant: '<S6>/InjSys_noETBSelagInj2Sp_C'
     *  Lookup2D: '<S9>/Look-Up Table (2-D)'
     */
    if (InjSys_noETBSelagInj2Sp_C == 0) {
      agInjSp_B.Merge1 = InjSys_agInj2SpETB_C;
    } else {
      agInjSp_B.Merge1 = localLookUpTable2D_fr;
    }

    /* MultiPortSwitch: '<S6>/Multiport Switch2' incorporates:
     *  Constant: '<S6>/InjSys_agInj3SpETB_C'
     *  Constant: '<S6>/InjSys_noETBSelagInj3Sp_C'
     *  Lookup2D: '<S10>/Look-Up Table (2-D)'
     */
    if (InjSys_noETBSelagInj3Sp_C == 0) {
      agInjSp_B.Merge2 = InjSys_agInj3SpETB_C;
    } else {
      agInjSp_B.Merge2 = localLookUpTable2D_hb;
    }
  } else {
    /* SignalConversion: '<S14>/TmpSignal ConversionAtAssignmentInport1' incorporates:
     *  Constant: '<S14>/Constant5'
     */
    localAssignment2[0] = FALSE;
    localAssignment2[1] = FALSE;
    localAssignment2[2] = FALSE;
    localAssignment2[3] = FALSE;
    localAssignment2[4] = FALSE;
    localAssignment2[5] = FALSE;
    localAssignment2[6] = FALSE;
    localAssignment2[7] = FALSE;
    localAssignment2[8] = FALSE;
    localAssignment2[9] = FALSE;
    localAssignment2[10] = FALSE;
    localAssignment2[11] = FALSE;
    localAssignment2[12] = FALSE;
    localAssignment2[13] = FALSE;
    localAssignment2[14] = FALSE;

    /* Switch: '<S24>/Switch' incorporates:
     *  Constant: '<S14>/InjSys_idxModAgInjSatMin_C'
     *  RelationalOperator: '<S24>/UpperRelop'
     */
    if (agInjSp_B.VEMS_vidGET5 < InjSys_idxModAgInjSatMin_C) {
      localSwitch2 = InjSys_idxModAgInjSatMin_C;
    } else {
      localSwitch2 = agInjSp_B.VEMS_vidGET5;
    }

    /* Switch: '<S24>/Switch2' incorporates:
     *  Constant: '<S14>/InjSys_idxModAgInjSatMax_C'
     *  RelationalOperator: '<S24>/LowerRelop1'
     */
    if (agInjSp_B.VEMS_vidGET5 > InjSys_idxModAgInjSatMax_C) {
      localSwitch2 = InjSys_idxModAgInjSatMax_C;
    }

    /* Assignment: '<S14>/Assignment' incorporates:
     *  Constant: '<S14>/Constant6'
     */
    localAssignment2[localSwitch2 - 1] = TRUE;

    /* Switch: '<S27>/Switch' incorporates:
     *  Constant: '<S14>/InjSys_idxModAgInjSatMin_C2'
     *  RelationalOperator: '<S27>/UpperRelop'
     */
    if (agInjSp_B.VEMS_vidGET7 < InjSys_idxModAgInjSatMin_C) {
      localSwitch2 = InjSys_idxModAgInjSatMin_C;
    } else {
      localSwitch2 = agInjSp_B.VEMS_vidGET7;
    }

    /* Switch: '<S27>/Switch2' incorporates:
     *  Constant: '<S14>/InjSys_idxModAgInjSatMax_C2'
     *  RelationalOperator: '<S27>/LowerRelop1'
     */
    if (agInjSp_B.VEMS_vidGET7 > InjSys_idxModAgInjSatMax_C) {
      localSwitch2 = InjSys_idxModAgInjSatMax_C;
    }

    /* Assignment: '<S14>/Assignment1' incorporates:
     *  Constant: '<S14>/Constant7'
     */
    localAssignment2[localSwitch2 - 1] = TRUE;

    /* Switch: '<S30>/Switch' incorporates:
     *  Constant: '<S14>/InjSys_idxModAgInjSatMin_C3'
     *  RelationalOperator: '<S30>/UpperRelop'
     */
    if (agInjSp_B.VEMS_vidGET6 < InjSys_idxModAgInjSatMin_C) {
      localSwitch2 = InjSys_idxModAgInjSatMin_C;
    } else {
      localSwitch2 = agInjSp_B.VEMS_vidGET6;
    }

    /* Switch: '<S30>/Switch2' incorporates:
     *  Constant: '<S14>/InjSys_idxModAgInjSatMax_C3'
     *  RelationalOperator: '<S30>/LowerRelop1'
     */
    if (agInjSp_B.VEMS_vidGET6 > InjSys_idxModAgInjSatMax_C) {
      localSwitch2 = InjSys_idxModAgInjSatMax_C;
    }

    /* Assignment: '<S14>/Assignment2' incorporates:
     *  Constant: '<S14>/Constant8'
     */
    localAssignment2[localSwitch2 - 1] = TRUE;

    /* Switch: '<S33>/Switch' incorporates:
     *  Constant: '<S14>/InjSys_idxModAgInjSatMin_C4'
     *  RelationalOperator: '<S33>/UpperRelop'
     */
    if (agInjSp_B.VEMS_vidGET8 < InjSys_idxModAgInjSatMin_C) {
      localSwitch2 = InjSys_idxModAgInjSatMin_C;
    } else {
      localSwitch2 = agInjSp_B.VEMS_vidGET8;
    }

    /* Switch: '<S33>/Switch2' incorporates:
     *  Constant: '<S14>/InjSys_idxModAgInjSatMax_C4'
     *  RelationalOperator: '<S33>/LowerRelop1'
     */
    if (agInjSp_B.VEMS_vidGET8 > InjSys_idxModAgInjSatMax_C) {
      localSwitch2 = InjSys_idxModAgInjSatMax_C;
    }

    /* Assignment: '<S14>/Assignment3' incorporates:
     *  Constant: '<S14>/Constant9'
     */
    for (locali = 0; locali < 15; locali++) {
      InjSys_prm_bAcvAgInj1SpCal[(locali)] = localAssignment2[locali];
    }

    InjSys_prm_bAcvAgInj1SpCal[localSwitch2 - 1] = TRUE;

    /* SignalConversion: '<S34>/Signal Conversion' */
    InjSys_bAcvAgInj1SpCal1 = InjSys_prm_bAcvAgInj1SpCal[0];

    /* SignalConversion: '<S34>/Signal Conversion1' */
    InjSys_bAcvAgInj1SpCal2 = InjSys_prm_bAcvAgInj1SpCal[1];

    /* SignalConversion: '<S34>/Signal Conversion10' */
    InjSys_bAcvAgInj1SpCal11 = InjSys_prm_bAcvAgInj1SpCal[10];

    /* SignalConversion: '<S34>/Signal Conversion11' */
    InjSys_bAcvAgInj1SpCal12 = InjSys_prm_bAcvAgInj1SpCal[11];

    /* SignalConversion: '<S34>/Signal Conversion12' */
    InjSys_bAcvAgInj1SpCal13 = InjSys_prm_bAcvAgInj1SpCal[12];

    /* SignalConversion: '<S34>/Signal Conversion13' */
    InjSys_bAcvAgInj1SpCal14 = InjSys_prm_bAcvAgInj1SpCal[13];

    /* SignalConversion: '<S34>/Signal Conversion14' */
    InjSys_bAcvAgInj1SpCal15 = InjSys_prm_bAcvAgInj1SpCal[14];

    /* SignalConversion: '<S34>/Signal Conversion2' */
    InjSys_bAcvAgInj1SpCal3 = InjSys_prm_bAcvAgInj1SpCal[2];

    /* SignalConversion: '<S34>/Signal Conversion3' */
    InjSys_bAcvAgInj1SpCal4 = InjSys_prm_bAcvAgInj1SpCal[3];

    /* SignalConversion: '<S34>/Signal Conversion4' */
    InjSys_bAcvAgInj1SpCal5 = InjSys_prm_bAcvAgInj1SpCal[4];

    /* SignalConversion: '<S34>/Signal Conversion5' */
    InjSys_bAcvAgInj1SpCal6 = InjSys_prm_bAcvAgInj1SpCal[5];

    /* SignalConversion: '<S34>/Signal Conversion6' */
    InjSys_bAcvAgInj1SpCal7 = InjSys_prm_bAcvAgInj1SpCal[6];

    /* SignalConversion: '<S34>/Signal Conversion7' */
    InjSys_bAcvAgInj1SpCal8 = InjSys_prm_bAcvAgInj1SpCal[7];

    /* SignalConversion: '<S34>/Signal Conversion8' */
    InjSys_bAcvAgInj1SpCal9 = InjSys_prm_bAcvAgInj1SpCal[8];

    /* SignalConversion: '<S34>/Signal Conversion9' */
    InjSys_bAcvAgInj1SpCal10 = InjSys_prm_bAcvAgInj1SpCal[9];

    /* Outputs for enable SubSystem: '<S15>/F02_Calibration_1_agInj1Sp' incorporates:
     *  EnablePort: '<S35>/Enable'
     */
    if (InjSys_bAcvAgInj1SpCal1) {
      /* Lookup2D: '<S51>/Look-Up Table (2-D)'
       * About '<S51>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_ev), (&(InjSys_agInj1SpCal1_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal1X_A[0])),
                         15U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal1Y_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S51>/Data Type Duplicate2'
       *
       * Regarding '<S51>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S35>/DTC32' incorporates:
       *  Lookup2D: '<S51>/Look-Up Table (2-D)'
       */
      InjSys_agInj1SpCal1 = ((Float)localLookUpTable2D_ev) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S15>/F02_Calibration_1_agInj1Sp' */

    /* Outputs for enable SubSystem: '<S15>/F03_Calibration_2_agInj1Sp' incorporates:
     *  EnablePort: '<S36>/Enable'
     */
    if (InjSys_bAcvAgInj1SpCal2) {
      /* Lookup2D: '<S52>/Look-Up Table (2-D)'
       * About '<S52>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_gy), (&(InjSys_agInj1SpCal2_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal2X_A[0])),
                         15U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal2Y_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S52>/Data Type Duplicate2'
       *
       * Regarding '<S52>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S36>/DTC32' incorporates:
       *  Lookup2D: '<S52>/Look-Up Table (2-D)'
       */
      InjSys_agInj1SpCal2 = ((Float)localLookUpTable2D_gy) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S15>/F03_Calibration_2_agInj1Sp' */

    /* Outputs for enable SubSystem: '<S15>/F04_Calibration_3_agInj1Sp' incorporates:
     *  EnablePort: '<S37>/Enable'
     */
    if (InjSys_bAcvAgInj1SpCal3) {
      /* Lookup2D: '<S53>/Look-Up Table (2-D)'
       * About '<S53>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_lr), (&(InjSys_agInj1SpCal3_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal3X_A[0])),
                         15U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal3Y_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S53>/Data Type Duplicate2'
       *
       * Regarding '<S53>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S37>/DTC32' incorporates:
       *  Lookup2D: '<S53>/Look-Up Table (2-D)'
       */
      InjSys_agInj1SpCal3 = ((Float)localLookUpTable2D_lr) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S15>/F04_Calibration_3_agInj1Sp' */

    /* Outputs for enable SubSystem: '<S15>/F05_Calibration_4_agInj1Sp' incorporates:
     *  EnablePort: '<S38>/Enable'
     */
    if (InjSys_bAcvAgInj1SpCal4) {
      /* Lookup2D: '<S54>/Look-Up Table (2-D)'
       * About '<S54>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_p2), (&(InjSys_agInj1SpCal4_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal4X_A[0])),
                         15U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal4Y_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S54>/Data Type Duplicate2'
       *
       * Regarding '<S54>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S38>/DTC32' incorporates:
       *  Lookup2D: '<S54>/Look-Up Table (2-D)'
       */
      InjSys_agInj1SpCal4 = ((Float)localLookUpTable2D_p2) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S15>/F05_Calibration_4_agInj1Sp' */

    /* Outputs for enable SubSystem: '<S15>/F06_Calibration_5_agInj1Sp' incorporates:
     *  EnablePort: '<S39>/Enable'
     */
    if (InjSys_bAcvAgInj1SpCal5) {
      /* Lookup2D: '<S55>/Look-Up Table (2-D)'
       * About '<S55>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_ic), (&(InjSys_agInj1SpCal5_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal5X_A[0])),
                         15U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal5Y_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S55>/Data Type Duplicate2'
       *
       * Regarding '<S55>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S39>/DTC32' incorporates:
       *  Lookup2D: '<S55>/Look-Up Table (2-D)'
       */
      InjSys_agInj1SpCal5 = ((Float)localLookUpTable2D_ic) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S15>/F06_Calibration_5_agInj1Sp' */

    /* Outputs for enable SubSystem: '<S15>/F07_Calibration_6_agInj1Sp' incorporates:
     *  EnablePort: '<S40>/Enable'
     */
    if (InjSys_bAcvAgInj1SpCal6) {
      /* Lookup2D: '<S56>/Look-Up Table (2-D)'
       * About '<S56>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_bz), (&(InjSys_agInj1SpCal6_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal6X_A[0])),
                         15U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal6Y_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S56>/Data Type Duplicate2'
       *
       * Regarding '<S56>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S40>/DTC32' incorporates:
       *  Lookup2D: '<S56>/Look-Up Table (2-D)'
       */
      InjSys_agInj1SpCal6 = ((Float)localLookUpTable2D_bz) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S15>/F07_Calibration_6_agInj1Sp' */

    /* Outputs for enable SubSystem: '<S15>/F08_Calibration_7_agInj1Sp' incorporates:
     *  EnablePort: '<S41>/Enable'
     */
    if (InjSys_bAcvAgInj1SpCal7) {
      /* Lookup2D: '<S57>/Look-Up Table (2-D)'
       * About '<S57>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_mi), (&(InjSys_agInj1SpCal7_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal7X_A[0])),
                         15U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal7Y_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S57>/Data Type Duplicate2'
       *
       * Regarding '<S57>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S41>/DTC32' incorporates:
       *  Lookup2D: '<S57>/Look-Up Table (2-D)'
       */
      InjSys_agInj1SpCal7 = ((Float)localLookUpTable2D_mi) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S15>/F08_Calibration_7_agInj1Sp' */

    /* Outputs for enable SubSystem: '<S15>/F09_Calibration_8_agInj1Sp' incorporates:
     *  EnablePort: '<S42>/Enable'
     */
    if (InjSys_bAcvAgInj1SpCal8) {
      /* Lookup2D: '<S58>/Look-Up Table (2-D)'
       * About '<S58>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_p5), (&(InjSys_agInj1SpCal8_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal8X_A[0])),
                         15U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal8Y_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S58>/Data Type Duplicate2'
       *
       * Regarding '<S58>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S42>/DTC32' incorporates:
       *  Lookup2D: '<S58>/Look-Up Table (2-D)'
       */
      InjSys_agInj1SpCal8 = ((Float)localLookUpTable2D_p5) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S15>/F09_Calibration_8_agInj1Sp' */

    /* Outputs for enable SubSystem: '<S15>/F10_Calibration_9_agInj1Sp' incorporates:
     *  EnablePort: '<S43>/Enable'
     */
    if (InjSys_bAcvAgInj1SpCal9) {
      /* Lookup2D: '<S59>/Look-Up Table (2-D)'
       * About '<S59>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_nh), (&(InjSys_agInj1SpCal9_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal9X_A[0])),
                         15U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal9Y_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S59>/Data Type Duplicate2'
       *
       * Regarding '<S59>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S43>/DTC32' incorporates:
       *  Lookup2D: '<S59>/Look-Up Table (2-D)'
       */
      InjSys_agInj1SpCal9 = ((Float)localLookUpTable2D_nh) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S15>/F10_Calibration_9_agInj1Sp' */

    /* Outputs for enable SubSystem: '<S15>/F11_Calibration_10_agInj1Sp' incorporates:
     *  EnablePort: '<S44>/Enable'
     */
    if (InjSys_bAcvAgInj1SpCal10) {
      /* Lookup2D: '<S60>/Look-Up Table (2-D)'
       * About '<S60>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_et), (&(InjSys_agInj1SpCal10_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal10X_A[0])),
                         7U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal10Y_A[0])), 7U);

      /* DataTypeDuplicate Block: '<S60>/Data Type Duplicate2'
       *
       * Regarding '<S60>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S44>/DTC32' incorporates:
       *  Lookup2D: '<S60>/Look-Up Table (2-D)'
       */
      InjSys_agInj1SpCal10 = ((Float)localLookUpTable2D_et) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S15>/F11_Calibration_10_agInj1Sp' */

    /* Outputs for enable SubSystem: '<S15>/F12_Calibration_11_agInj1Sp' incorporates:
     *  EnablePort: '<S45>/Enable'
     */
    if (InjSys_bAcvAgInj1SpCal11) {
      /* Lookup2D: '<S61>/Look-Up Table (2-D)'
       * About '<S61>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_n1), (&(InjSys_agInj1SpCal11_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal11X_A[0])),
                         7U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal11Y_A[0])), 7U);

      /* DataTypeDuplicate Block: '<S61>/Data Type Duplicate2'
       *
       * Regarding '<S61>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S45>/DTC32' incorporates:
       *  Lookup2D: '<S61>/Look-Up Table (2-D)'
       */
      InjSys_agInj1SpCal11 = ((Float)localLookUpTable2D_n1) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S15>/F12_Calibration_11_agInj1Sp' */

    /* Outputs for enable SubSystem: '<S15>/F13_Calibration_12_agInj1Sp' incorporates:
     *  EnablePort: '<S46>/Enable'
     */
    if (InjSys_bAcvAgInj1SpCal12) {
      /* Lookup2D: '<S62>/Look-Up Table (2-D)'
       * About '<S62>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_h0), (&(InjSys_agInj1SpCal12_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal12X_A[0])),
                         7U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal12Y_A[0])), 7U);

      /* DataTypeDuplicate Block: '<S62>/Data Type Duplicate2'
       *
       * Regarding '<S62>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S46>/DTC32' incorporates:
       *  Lookup2D: '<S62>/Look-Up Table (2-D)'
       */
      InjSys_agInj1SpCal12 = ((Float)localLookUpTable2D_h0) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S15>/F13_Calibration_12_agInj1Sp' */

    /* Outputs for enable SubSystem: '<S15>/F14_Calibration_13_agInj1Sp' incorporates:
     *  EnablePort: '<S47>/Enable'
     */
    if (InjSys_bAcvAgInj1SpCal13) {
      /* Lookup2D: '<S63>/Look-Up Table (2-D)'
       * About '<S63>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_bj), (&(InjSys_agInj1SpCal13_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal13X_A[0])),
                         7U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal13Y_A[0])), 7U);

      /* DataTypeDuplicate Block: '<S63>/Data Type Duplicate2'
       *
       * Regarding '<S63>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S47>/DTC32' incorporates:
       *  Lookup2D: '<S63>/Look-Up Table (2-D)'
       */
      InjSys_agInj1SpCal13 = ((Float)localLookUpTable2D_bj) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S15>/F14_Calibration_13_agInj1Sp' */

    /* Outputs for enable SubSystem: '<S15>/F15_Calibration_14_agInj1Sp' incorporates:
     *  EnablePort: '<S48>/Enable'
     */
    if (InjSys_bAcvAgInj1SpCal14) {
      /* Lookup2D: '<S64>/Look-Up Table (2-D)'
       * About '<S64>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_it), (&(InjSys_agInj1SpCal14_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal14X_A[0])),
                         7U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal14Y_A[0])), 7U);

      /* DataTypeDuplicate Block: '<S64>/Data Type Duplicate2'
       *
       * Regarding '<S64>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S48>/DTC32' incorporates:
       *  Lookup2D: '<S64>/Look-Up Table (2-D)'
       */
      InjSys_agInj1SpCal14 = ((Float)localLookUpTable2D_it) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S15>/F15_Calibration_14_agInj1Sp' */

    /* Outputs for enable SubSystem: '<S15>/F16_Calibration_15_agInj1Sp' incorporates:
     *  EnablePort: '<S49>/Enable'
     */
    if (InjSys_bAcvAgInj1SpCal15) {
      /* Lookup2D: '<S65>/Look-Up Table (2-D)'
       * About '<S65>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_hx), (&(InjSys_agInj1SpCal15_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal15X_A[0])),
                         7U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal15Y_A[0])), 7U);

      /* DataTypeDuplicate Block: '<S65>/Data Type Duplicate2'
       *
       * Regarding '<S65>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S49>/DTC32' incorporates:
       *  Lookup2D: '<S65>/Look-Up Table (2-D)'
       */
      InjSys_agInj1SpCal15 = ((Float)localLookUpTable2D_hx) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S15>/F16_Calibration_15_agInj1Sp' */

    /* DataTypeConversion: '<S50>/DTC32' */
    InjSys_prm_agInj1SpCal[0] = InjSys_agInj1SpCal1;
    InjSys_prm_agInj1SpCal[1] = InjSys_agInj1SpCal2;
    InjSys_prm_agInj1SpCal[2] = InjSys_agInj1SpCal3;
    InjSys_prm_agInj1SpCal[3] = InjSys_agInj1SpCal4;
    InjSys_prm_agInj1SpCal[4] = InjSys_agInj1SpCal5;
    InjSys_prm_agInj1SpCal[5] = InjSys_agInj1SpCal6;
    InjSys_prm_agInj1SpCal[6] = InjSys_agInj1SpCal7;
    InjSys_prm_agInj1SpCal[7] = InjSys_agInj1SpCal8;
    InjSys_prm_agInj1SpCal[8] = InjSys_agInj1SpCal9;
    InjSys_prm_agInj1SpCal[9] = InjSys_agInj1SpCal10;
    InjSys_prm_agInj1SpCal[10] = InjSys_agInj1SpCal11;
    InjSys_prm_agInj1SpCal[11] = InjSys_agInj1SpCal12;
    InjSys_prm_agInj1SpCal[12] = InjSys_agInj1SpCal13;
    InjSys_prm_agInj1SpCal[13] = InjSys_agInj1SpCal14;
    InjSys_prm_agInj1SpCal[14] = InjSys_agInj1SpCal15;

    /* Selector: '<S16>/Selector' */
    InjSys_agInj1SpBas1ModCur = InjSys_prm_agInj1SpCal[agInjSp_B.VEMS_vidGET5 -
      1];

    /* Selector: '<S16>/Selector1' */
    InjSys_agInj1SpBas2ModCur = InjSys_prm_agInj1SpCal[agInjSp_B.VEMS_vidGET7 -
      1];

    /* Selector: '<S16>/Selector2' */
    InjSys_agInj1SpBas1ModTar = InjSys_prm_agInj1SpCal[agInjSp_B.VEMS_vidGET6 -
      1];

    /* Selector: '<S16>/Selector3' */
    InjSys_agInj1SpBas2ModTar = InjSys_prm_agInj1SpCal[agInjSp_B.VEMS_vidGET8 -
      1];

    /* DataTypeConversion: '<S17>/Data Type Conversion' */
    localDivide_k = ((Float)agInjSp_B.VEMS_vidGET3) * 0.0078125F;

    /* Switch: '<S72>/Switch2' incorporates:
     *  Constant: '<S66>/Constant'
     *  RelationalOperator: '<S72>/LowerRelop1'
     */
    if (localDivide_k > 1.0F) {
      localDivide_k = 1.0F;
    }

    /* Sum: '<S66>/Sum2' incorporates:
     *  Product: '<S66>/Divide'
     *  Sum: '<S66>/Sum3'
     */
    InjSys_agInj1SpModTar_MP = ((InjSys_agInj1SpBas1ModTar -
      InjSys_agInj1SpBas2ModTar) * localDivide_k) + InjSys_agInj1SpBas2ModTar;

    /* DataTypeConversion: '<S17>/Data Type Conversion1' */
    localDivide_k = ((Float)agInjSp_B.VEMS_vidGET2) * 0.0078125F;

    /* Switch: '<S76>/Switch2' incorporates:
     *  Constant: '<S67>/Constant'
     *  RelationalOperator: '<S76>/LowerRelop1'
     */
    if (localDivide_k > 1.0F) {
      localDivide_k = 1.0F;
    }

    /* Sum: '<S67>/Sum2' incorporates:
     *  Product: '<S67>/Divide'
     *  Sum: '<S67>/Sum3'
     */
    InjSys_agInj1SpModCur_MP = ((InjSys_agInj1SpBas1ModCur -
      InjSys_agInj1SpBas2ModCur) * localDivide_k) + InjSys_agInj1SpBas2ModCur;

    /* DataTypeConversion: '<S17>/Data Type Conversion2' */
    localDivide_k = ((Float)agInjSp_B.VEMS_vidGET4) * 0.0078125F;

    /* Switch: '<S80>/Switch2' incorporates:
     *  Constant: '<S68>/Constant'
     *  RelationalOperator: '<S80>/LowerRelop1'
     */
    if (localDivide_k > 1.0F) {
      localDivide_k = 1.0F;
    }

    /* Product: '<S68>/Divide' incorporates:
     *  Sum: '<S68>/Sum3'
     */
    localDivide_k *= InjSys_agInj1SpModTar_MP - InjSys_agInj1SpModCur_MP;

    /* Sum: '<S68>/Sum2' */
    localtmp = ((Double)(InjSys_agInj1SpModCur_MP + localDivide_k)) / 0.09375;
    if (localtmp < 65536.0) {
      if (localtmp >= 0.0) {
        agInjSp_B.Merge = (UInt16)localtmp;
      } else {
        agInjSp_B.Merge = 0U;
      }
    } else {
      agInjSp_B.Merge = MAX_uint16_T;
    }

    /* SignalConversion: '<S81>/TmpSignal ConversionAtAssignmentInport1' incorporates:
     *  Constant: '<S81>/Constant5'
     */
    localAssignment2[0] = FALSE;
    localAssignment2[1] = FALSE;
    localAssignment2[2] = FALSE;
    localAssignment2[3] = FALSE;
    localAssignment2[4] = FALSE;
    localAssignment2[5] = FALSE;
    localAssignment2[6] = FALSE;
    localAssignment2[7] = FALSE;
    localAssignment2[8] = FALSE;
    localAssignment2[9] = FALSE;
    localAssignment2[10] = FALSE;
    localAssignment2[11] = FALSE;
    localAssignment2[12] = FALSE;
    localAssignment2[13] = FALSE;
    localAssignment2[14] = FALSE;

    /* Switch: '<S91>/Switch' incorporates:
     *  Constant: '<S81>/InjSys_idxModAgInjSatMin_C'
     *  RelationalOperator: '<S91>/UpperRelop'
     */
    if (agInjSp_B.VEMS_vidGET5 < InjSys_idxModAgInjSatMin_C) {
      localSwitch2 = InjSys_idxModAgInjSatMin_C;
    } else {
      localSwitch2 = agInjSp_B.VEMS_vidGET5;
    }

    /* Switch: '<S91>/Switch2' incorporates:
     *  Constant: '<S81>/InjSys_idxModAgInjSatMax_C'
     *  RelationalOperator: '<S91>/LowerRelop1'
     */
    if (agInjSp_B.VEMS_vidGET5 > InjSys_idxModAgInjSatMax_C) {
      localSwitch2 = InjSys_idxModAgInjSatMax_C;
    }

    /* Assignment: '<S81>/Assignment' incorporates:
     *  Constant: '<S81>/Constant6'
     */
    localAssignment2[localSwitch2 - 1] = TRUE;

    /* Switch: '<S94>/Switch' incorporates:
     *  Constant: '<S81>/InjSys_idxModAgInjSatMin_C1'
     *  RelationalOperator: '<S94>/UpperRelop'
     */
    if (agInjSp_B.VEMS_vidGET7 < InjSys_idxModAgInjSatMin_C) {
      localSwitch2 = InjSys_idxModAgInjSatMin_C;
    } else {
      localSwitch2 = agInjSp_B.VEMS_vidGET7;
    }

    /* Switch: '<S94>/Switch2' incorporates:
     *  Constant: '<S81>/InjSys_idxModAgInjSatMax_C1'
     *  RelationalOperator: '<S94>/LowerRelop1'
     */
    if (agInjSp_B.VEMS_vidGET7 > InjSys_idxModAgInjSatMax_C) {
      localSwitch2 = InjSys_idxModAgInjSatMax_C;
    }

    /* Assignment: '<S81>/Assignment1' incorporates:
     *  Constant: '<S81>/Constant7'
     */
    localAssignment2[localSwitch2 - 1] = TRUE;

    /* Switch: '<S97>/Switch' incorporates:
     *  Constant: '<S81>/InjSys_idxModAgInjSatMin_C2'
     *  RelationalOperator: '<S97>/UpperRelop'
     */
    if (agInjSp_B.VEMS_vidGET6 < InjSys_idxModAgInjSatMin_C) {
      localSwitch2 = InjSys_idxModAgInjSatMin_C;
    } else {
      localSwitch2 = agInjSp_B.VEMS_vidGET6;
    }

    /* Switch: '<S97>/Switch2' incorporates:
     *  Constant: '<S81>/InjSys_idxModAgInjSatMax_C2'
     *  RelationalOperator: '<S97>/LowerRelop1'
     */
    if (agInjSp_B.VEMS_vidGET6 > InjSys_idxModAgInjSatMax_C) {
      localSwitch2 = InjSys_idxModAgInjSatMax_C;
    }

    /* Assignment: '<S81>/Assignment2' incorporates:
     *  Constant: '<S81>/Constant8'
     */
    localAssignment2[localSwitch2 - 1] = TRUE;

    /* Switch: '<S100>/Switch' incorporates:
     *  Constant: '<S81>/InjSys_idxModAgInjSatMin_C3'
     *  RelationalOperator: '<S100>/UpperRelop'
     */
    if (agInjSp_B.VEMS_vidGET8 < InjSys_idxModAgInjSatMin_C) {
      localSwitch2 = InjSys_idxModAgInjSatMin_C;
    } else {
      localSwitch2 = agInjSp_B.VEMS_vidGET8;
    }

    /* Switch: '<S100>/Switch2' incorporates:
     *  Constant: '<S81>/InjSys_idxModAgInjSatMax_C3'
     *  RelationalOperator: '<S100>/LowerRelop1'
     */
    if (agInjSp_B.VEMS_vidGET8 > InjSys_idxModAgInjSatMax_C) {
      localSwitch2 = InjSys_idxModAgInjSatMax_C;
    }

    /* Assignment: '<S81>/Assignment3' incorporates:
     *  Constant: '<S81>/Constant9'
     */
    for (locali = 0; locali < 15; locali++) {
      InjSys_prm_bAcvAgInj2SpCal[(locali)] = localAssignment2[locali];
    }

    InjSys_prm_bAcvAgInj2SpCal[localSwitch2 - 1] = TRUE;

    /* SignalConversion: '<S101>/Signal Conversion' */
    InjSys_bAcvAgInj2SpCal1 = InjSys_prm_bAcvAgInj2SpCal[0];

    /* SignalConversion: '<S101>/Signal Conversion1' */
    InjSys_bAcvAgInj2SpCal2 = InjSys_prm_bAcvAgInj2SpCal[1];

    /* SignalConversion: '<S101>/Signal Conversion10' */
    InjSys_bAcvAgInj2SpCal11 = InjSys_prm_bAcvAgInj2SpCal[10];

    /* SignalConversion: '<S101>/Signal Conversion11' */
    InjSys_bAcvAgInj2SpCal12 = InjSys_prm_bAcvAgInj2SpCal[11];

    /* SignalConversion: '<S101>/Signal Conversion12' */
    InjSys_bAcvAgInj2SpCal13 = InjSys_prm_bAcvAgInj2SpCal[12];

    /* SignalConversion: '<S101>/Signal Conversion13' */
    InjSys_bAcvAgInj2SpCal14 = InjSys_prm_bAcvAgInj2SpCal[13];

    /* SignalConversion: '<S101>/Signal Conversion14' */
    InjSys_bAcvAgInj2SpCal15 = InjSys_prm_bAcvAgInj2SpCal[14];

    /* SignalConversion: '<S101>/Signal Conversion2' */
    InjSys_bAcvAgInj2SpCal3 = InjSys_prm_bAcvAgInj2SpCal[2];

    /* SignalConversion: '<S101>/Signal Conversion3' */
    InjSys_bAcvAgInj2SpCal5 = InjSys_prm_bAcvAgInj2SpCal[4];

    /* SignalConversion: '<S101>/Signal Conversion4' */
    InjSys_bAcvAgInj2SpCal4 = InjSys_prm_bAcvAgInj2SpCal[3];

    /* SignalConversion: '<S101>/Signal Conversion5' */
    InjSys_bAcvAgInj2SpCal6 = InjSys_prm_bAcvAgInj2SpCal[5];

    /* SignalConversion: '<S101>/Signal Conversion6' */
    InjSys_bAcvAgInj2SpCal7 = InjSys_prm_bAcvAgInj2SpCal[6];

    /* SignalConversion: '<S101>/Signal Conversion7' */
    InjSys_bAcvAgInj2SpCal8 = InjSys_prm_bAcvAgInj2SpCal[7];

    /* SignalConversion: '<S101>/Signal Conversion8' */
    InjSys_bAcvAgInj2SpCal9 = InjSys_prm_bAcvAgInj2SpCal[8];

    /* SignalConversion: '<S101>/Signal Conversion9' */
    InjSys_bAcvAgInj2SpCal10 = InjSys_prm_bAcvAgInj2SpCal[9];

    /* Outputs for enable SubSystem: '<S82>/F02_Calibration_1_agInj2Sp' incorporates:
     *  EnablePort: '<S102>/Enable'
     */
    if (InjSys_bAcvAgInj2SpCal1) {
      /* Lookup2D: '<S118>/Look-Up Table (2-D)'
       * About '<S118>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_hq), (&(InjSys_agInj2SpCal1_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal1X_A[0])),
                         15U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal1Y_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S118>/Data Type Duplicate2'
       *
       * Regarding '<S118>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S102>/DTC32' incorporates:
       *  Lookup2D: '<S118>/Look-Up Table (2-D)'
       */
      InjSys_agInj2SpCal1 = ((Float)localLookUpTable2D_hq) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S82>/F02_Calibration_1_agInj2Sp' */

    /* Outputs for enable SubSystem: '<S82>/F03_Calibration_2_agInj2Sp' incorporates:
     *  EnablePort: '<S103>/Enable'
     */
    if (InjSys_bAcvAgInj2SpCal2) {
      /* Lookup2D: '<S119>/Look-Up Table (2-D)'
       * About '<S119>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_b1), (&(InjSys_agInj2SpCal2_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal2X_A[0])),
                         15U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal2Y_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S119>/Data Type Duplicate2'
       *
       * Regarding '<S119>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S103>/DTC32' incorporates:
       *  Lookup2D: '<S119>/Look-Up Table (2-D)'
       */
      InjSys_agInj2SpCal2 = ((Float)localLookUpTable2D_b1) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S82>/F03_Calibration_2_agInj2Sp' */

    /* Outputs for enable SubSystem: '<S82>/F04_Calibration_3_agInj2Sp' incorporates:
     *  EnablePort: '<S104>/Enable'
     */
    if (InjSys_bAcvAgInj2SpCal3) {
      /* Lookup2D: '<S120>/Look-Up Table (2-D)'
       * About '<S120>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_j), (&(InjSys_agInj2SpCal3_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal3X_A[0])),
                         15U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal3Y_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S120>/Data Type Duplicate2'
       *
       * Regarding '<S120>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S104>/DTC32' incorporates:
       *  Lookup2D: '<S120>/Look-Up Table (2-D)'
       */
      InjSys_agInj2SpCal3 = ((Float)localLookUpTable2D_j) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S82>/F04_Calibration_3_agInj2Sp' */

    /* Outputs for enable SubSystem: '<S82>/F05_Calibration_4_agInj2Sp' incorporates:
     *  EnablePort: '<S105>/Enable'
     */
    if (InjSys_bAcvAgInj2SpCal4) {
      /* Lookup2D: '<S121>/Look-Up Table (2-D)'
       * About '<S121>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_m), (&(InjSys_agInj2SpCal4_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal4X_A[0])),
                         15U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal4Y_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S121>/Data Type Duplicate2'
       *
       * Regarding '<S121>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S105>/DTC32' incorporates:
       *  Lookup2D: '<S121>/Look-Up Table (2-D)'
       */
      InjSys_agInj2SpCal4 = ((Float)localLookUpTable2D_m) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S82>/F05_Calibration_4_agInj2Sp' */

    /* Outputs for enable SubSystem: '<S82>/F06_Calibration_5_agInj2Sp' incorporates:
     *  EnablePort: '<S106>/Enable'
     */
    if (InjSys_bAcvAgInj2SpCal5) {
      /* Lookup2D: '<S122>/Look-Up Table (2-D)'
       * About '<S122>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_i2), (&(InjSys_agInj2SpCal5_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal5X_A[0])),
                         15U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal5Y_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S122>/Data Type Duplicate2'
       *
       * Regarding '<S122>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S106>/DTC32' incorporates:
       *  Lookup2D: '<S122>/Look-Up Table (2-D)'
       */
      InjSys_agInj2SpCal5 = ((Float)localLookUpTable2D_i2) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S82>/F06_Calibration_5_agInj2Sp' */

    /* Outputs for enable SubSystem: '<S82>/F07_Calibration_6_agInj2Sp' incorporates:
     *  EnablePort: '<S107>/Enable'
     */
    if (InjSys_bAcvAgInj2SpCal6) {
      /* Lookup2D: '<S123>/Look-Up Table (2-D)'
       * About '<S123>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_ia), (&(InjSys_agInj2SpCal6_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal6X_A[0])),
                         15U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal6Y_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S123>/Data Type Duplicate2'
       *
       * Regarding '<S123>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S107>/DTC32' incorporates:
       *  Lookup2D: '<S123>/Look-Up Table (2-D)'
       */
      InjSys_agInj2SpCal6 = ((Float)localLookUpTable2D_ia) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S82>/F07_Calibration_6_agInj2Sp' */

    /* Outputs for enable SubSystem: '<S82>/F08_Calibration_7_agInj2Sp' incorporates:
     *  EnablePort: '<S108>/Enable'
     */
    if (InjSys_bAcvAgInj2SpCal7) {
      /* Lookup2D: '<S124>/Look-Up Table (2-D)'
       * About '<S124>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_nf), (&(InjSys_agInj2SpCal7_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal7X_A[0])),
                         15U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal7Y_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S124>/Data Type Duplicate2'
       *
       * Regarding '<S124>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S108>/DTC32' incorporates:
       *  Lookup2D: '<S124>/Look-Up Table (2-D)'
       */
      InjSys_agInj2SpCal7 = ((Float)localLookUpTable2D_nf) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S82>/F08_Calibration_7_agInj2Sp' */

    /* Outputs for enable SubSystem: '<S82>/F09_Calibration_8_agInj2Sp' incorporates:
     *  EnablePort: '<S109>/Enable'
     */
    if (InjSys_bAcvAgInj2SpCal8) {
      /* Lookup2D: '<S125>/Look-Up Table (2-D)'
       * About '<S125>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_kf), (&(InjSys_agInj2SpCal8_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal8X_A[0])),
                         15U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal8Y_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S125>/Data Type Duplicate2'
       *
       * Regarding '<S125>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S109>/DTC32' incorporates:
       *  Lookup2D: '<S125>/Look-Up Table (2-D)'
       */
      InjSys_agInj2SpCal8 = ((Float)localLookUpTable2D_kf) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S82>/F09_Calibration_8_agInj2Sp' */

    /* Outputs for enable SubSystem: '<S82>/F10_Calibration_9_agInj2Sp' incorporates:
     *  EnablePort: '<S110>/Enable'
     */
    if (InjSys_bAcvAgInj2SpCal9) {
      /* Lookup2D: '<S126>/Look-Up Table (2-D)'
       * About '<S126>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_kh), (&(InjSys_agInj2SpCal9_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal9X_A[0])),
                         15U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal9Y_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S126>/Data Type Duplicate2'
       *
       * Regarding '<S126>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S110>/DTC32' incorporates:
       *  Lookup2D: '<S126>/Look-Up Table (2-D)'
       */
      InjSys_agInj2SpCal9 = ((Float)localLookUpTable2D_kh) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S82>/F10_Calibration_9_agInj2Sp' */

    /* Outputs for enable SubSystem: '<S82>/F11_Calibration_10_agInj2Sp' incorporates:
     *  EnablePort: '<S111>/Enable'
     */
    if (InjSys_bAcvAgInj2SpCal10) {
      /* Lookup2D: '<S127>/Look-Up Table (2-D)'
       * About '<S127>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_o), (&(InjSys_agInj2SpCal10_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal10X_A[0])),
                         7U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal10Y_A[0])), 7U);

      /* DataTypeDuplicate Block: '<S127>/Data Type Duplicate2'
       *
       * Regarding '<S127>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S111>/DTC32' incorporates:
       *  Lookup2D: '<S127>/Look-Up Table (2-D)'
       */
      InjSys_agInj2SpCal10 = ((Float)localLookUpTable2D_o) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S82>/F11_Calibration_10_agInj2Sp' */

    /* Outputs for enable SubSystem: '<S82>/F12_Calibration_11_agInj2Sp' incorporates:
     *  EnablePort: '<S112>/Enable'
     */
    if (InjSys_bAcvAgInj2SpCal11) {
      /* Lookup2D: '<S128>/Look-Up Table (2-D)'
       * About '<S128>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_a3), (&(InjSys_agInj2SpCal11_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal11X_A[0])),
                         7U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal11Y_A[0])), 7U);

      /* DataTypeDuplicate Block: '<S128>/Data Type Duplicate2'
       *
       * Regarding '<S128>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S112>/DTC32' incorporates:
       *  Lookup2D: '<S128>/Look-Up Table (2-D)'
       */
      InjSys_agInj2SpCal11 = ((Float)localLookUpTable2D_a3) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S82>/F12_Calibration_11_agInj2Sp' */

    /* Outputs for enable SubSystem: '<S82>/F13_Calibration_12_agInj2Sp' incorporates:
     *  EnablePort: '<S113>/Enable'
     */
    if (InjSys_bAcvAgInj2SpCal12) {
      /* Lookup2D: '<S129>/Look-Up Table (2-D)'
       * About '<S129>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_g), (&(InjSys_agInj2SpCal12_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal12X_A[0])),
                         7U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal12Y_A[0])), 7U);

      /* DataTypeDuplicate Block: '<S129>/Data Type Duplicate2'
       *
       * Regarding '<S129>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S113>/DTC32' incorporates:
       *  Lookup2D: '<S129>/Look-Up Table (2-D)'
       */
      InjSys_agInj2SpCal12 = ((Float)localLookUpTable2D_g) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S82>/F13_Calibration_12_agInj2Sp' */

    /* Outputs for enable SubSystem: '<S82>/F14_Calibration_13_agInj2Sp' incorporates:
     *  EnablePort: '<S114>/Enable'
     */
    if (InjSys_bAcvAgInj2SpCal13) {
      /* Lookup2D: '<S130>/Look-Up Table (2-D)'
       * About '<S130>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_p1), (&(InjSys_agInj2SpCal13_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal13X_A[0])),
                         7U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal13Y_A[0])), 7U);

      /* DataTypeDuplicate Block: '<S130>/Data Type Duplicate2'
       *
       * Regarding '<S130>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S114>/DTC32' incorporates:
       *  Lookup2D: '<S130>/Look-Up Table (2-D)'
       */
      InjSys_agInj2SpCal13 = ((Float)localLookUpTable2D_p1) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S82>/F14_Calibration_13_agInj2Sp' */

    /* Outputs for enable SubSystem: '<S82>/F15_Calibration_14_agInj2Sp' incorporates:
     *  EnablePort: '<S115>/Enable'
     */
    if (InjSys_bAcvAgInj2SpCal14) {
      /* Lookup2D: '<S131>/Look-Up Table (2-D)'
       * About '<S131>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_by), (&(InjSys_agInj2SpCal14_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal14X_A[0])),
                         7U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal14Y_A[0])), 7U);

      /* DataTypeDuplicate Block: '<S131>/Data Type Duplicate2'
       *
       * Regarding '<S131>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S115>/DTC32' incorporates:
       *  Lookup2D: '<S131>/Look-Up Table (2-D)'
       */
      InjSys_agInj2SpCal14 = ((Float)localLookUpTable2D_by) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S82>/F15_Calibration_14_agInj2Sp' */

    /* Outputs for enable SubSystem: '<S82>/F16_Calibration_15_agInj2Sp' incorporates:
     *  EnablePort: '<S116>/Enable'
     */
    if (InjSys_bAcvAgInj2SpCal15) {
      /* Lookup2D: '<S132>/Look-Up Table (2-D)'
       * About '<S132>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_f3), (&(InjSys_agInj2SpCal15_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal15X_A[0])),
                         7U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal15Y_A[0])), 7U);

      /* DataTypeDuplicate Block: '<S132>/Data Type Duplicate2'
       *
       * Regarding '<S132>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S116>/DTC32' incorporates:
       *  Lookup2D: '<S132>/Look-Up Table (2-D)'
       */
      InjSys_agInj2SpCal15 = ((Float)localLookUpTable2D_f3) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S82>/F16_Calibration_15_agInj2Sp' */

    /* DataTypeConversion: '<S117>/DTC32' */
    InjSys_prm_agInj2SpCal[0] = InjSys_agInj2SpCal1;
    InjSys_prm_agInj2SpCal[1] = InjSys_agInj2SpCal2;
    InjSys_prm_agInj2SpCal[2] = InjSys_agInj2SpCal3;
    InjSys_prm_agInj2SpCal[3] = InjSys_agInj2SpCal4;
    InjSys_prm_agInj2SpCal[4] = InjSys_agInj2SpCal5;
    InjSys_prm_agInj2SpCal[5] = InjSys_agInj2SpCal6;
    InjSys_prm_agInj2SpCal[6] = InjSys_agInj2SpCal7;
    InjSys_prm_agInj2SpCal[7] = InjSys_agInj2SpCal8;
    InjSys_prm_agInj2SpCal[8] = InjSys_agInj2SpCal9;
    InjSys_prm_agInj2SpCal[9] = InjSys_agInj2SpCal10;
    InjSys_prm_agInj2SpCal[10] = InjSys_agInj2SpCal11;
    InjSys_prm_agInj2SpCal[11] = InjSys_agInj2SpCal12;
    InjSys_prm_agInj2SpCal[12] = InjSys_agInj2SpCal13;
    InjSys_prm_agInj2SpCal[13] = InjSys_agInj2SpCal14;
    InjSys_prm_agInj2SpCal[14] = InjSys_agInj2SpCal15;

    /* Selector: '<S83>/Selector' */
    InjSys_agInj2SpBas1ModCur = InjSys_prm_agInj2SpCal[agInjSp_B.VEMS_vidGET5 -
      1];

    /* Selector: '<S83>/Selector1' */
    InjSys_agInj2SpBas2ModCur = InjSys_prm_agInj2SpCal[agInjSp_B.VEMS_vidGET7 -
      1];

    /* Selector: '<S83>/Selector2' */
    InjSys_agInj2SpBas1ModTar = InjSys_prm_agInj2SpCal[agInjSp_B.VEMS_vidGET6 -
      1];

    /* Selector: '<S83>/Selector3' */
    InjSys_agInj2SpBas2ModTar = InjSys_prm_agInj2SpCal[agInjSp_B.VEMS_vidGET8 -
      1];

    /* DataTypeConversion: '<S84>/Data Type Conversion1' */
    localDivide_k = ((Float)agInjSp_B.VEMS_vidGET3) * 0.0078125F;

    /* Switch: '<S139>/Switch2' incorporates:
     *  Constant: '<S133>/Constant'
     *  RelationalOperator: '<S139>/LowerRelop1'
     */
    if (localDivide_k > 1.0F) {
      localDivide_k = 1.0F;
    }

    /* Sum: '<S133>/Sum2' incorporates:
     *  Product: '<S133>/Divide'
     *  Sum: '<S133>/Sum3'
     */
    InjSys_agInj2SpModTar_MP = ((InjSys_agInj2SpBas1ModTar -
      InjSys_agInj2SpBas2ModTar) * localDivide_k) + InjSys_agInj2SpBas2ModTar;

    /* DataTypeConversion: '<S84>/Data Type Conversion2' */
    localDivide_k = ((Float)agInjSp_B.VEMS_vidGET2) * 0.0078125F;

    /* Switch: '<S143>/Switch2' incorporates:
     *  Constant: '<S134>/Constant'
     *  RelationalOperator: '<S143>/LowerRelop1'
     */
    if (localDivide_k > 1.0F) {
      localDivide_k = 1.0F;
    }

    /* Sum: '<S134>/Sum2' incorporates:
     *  Product: '<S134>/Divide'
     *  Sum: '<S134>/Sum3'
     */
    InjSys_agInj2SpModCur_MP = ((InjSys_agInj2SpBas1ModCur -
      InjSys_agInj2SpBas2ModCur) * localDivide_k) + InjSys_agInj2SpBas2ModCur;

    /* DataTypeConversion: '<S84>/Data Type Conversion3' */
    localDivide_k = ((Float)agInjSp_B.VEMS_vidGET4) * 0.0078125F;

    /* Switch: '<S147>/Switch2' incorporates:
     *  Constant: '<S135>/Constant'
     *  RelationalOperator: '<S147>/LowerRelop1'
     */
    if (localDivide_k > 1.0F) {
      localDivide_k = 1.0F;
    }

    /* Product: '<S135>/Divide' incorporates:
     *  Sum: '<S135>/Sum3'
     */
    localDivide_k *= InjSys_agInj2SpModTar_MP - InjSys_agInj2SpModCur_MP;

    /* Sum: '<S135>/Sum2' */
    localtmp = ((Double)(InjSys_agInj2SpModCur_MP + localDivide_k)) / 0.09375;
    if (localtmp < 65536.0) {
      if (localtmp >= 0.0) {
        agInjSp_B.Merge1 = (UInt16)localtmp;
      } else {
        agInjSp_B.Merge1 = 0U;
      }
    } else {
      agInjSp_B.Merge1 = MAX_uint16_T;
    }

    /* SignalConversion: '<S148>/TmpSignal ConversionAtAssignmentInport1' incorporates:
     *  Constant: '<S148>/Constant5'
     */
    localAssignment2[0] = FALSE;
    localAssignment2[1] = FALSE;
    localAssignment2[2] = FALSE;
    localAssignment2[3] = FALSE;
    localAssignment2[4] = FALSE;
    localAssignment2[5] = FALSE;
    localAssignment2[6] = FALSE;
    localAssignment2[7] = FALSE;
    localAssignment2[8] = FALSE;
    localAssignment2[9] = FALSE;
    localAssignment2[10] = FALSE;
    localAssignment2[11] = FALSE;
    localAssignment2[12] = FALSE;
    localAssignment2[13] = FALSE;
    localAssignment2[14] = FALSE;

    /* Switch: '<S158>/Switch' incorporates:
     *  Constant: '<S148>/InjSys_idxModAgInjSatMin_C'
     *  RelationalOperator: '<S158>/UpperRelop'
     */
    if (agInjSp_B.VEMS_vidGET5 < InjSys_idxModAgInjSatMin_C) {
      localSwitch2 = InjSys_idxModAgInjSatMin_C;
    } else {
      localSwitch2 = agInjSp_B.VEMS_vidGET5;
    }

    /* Switch: '<S158>/Switch2' incorporates:
     *  Constant: '<S148>/InjSys_idxModAgInjSatMax_C'
     *  RelationalOperator: '<S158>/LowerRelop1'
     */
    if (agInjSp_B.VEMS_vidGET5 > InjSys_idxModAgInjSatMax_C) {
      localSwitch2 = InjSys_idxModAgInjSatMax_C;
    }

    /* Assignment: '<S148>/Assignment' incorporates:
     *  Constant: '<S148>/Constant1'
     */
    localAssignment2[localSwitch2 - 1] = TRUE;

    /* Switch: '<S161>/Switch' incorporates:
     *  Constant: '<S148>/InjSys_idxModAgInjSatMin_C1'
     *  RelationalOperator: '<S161>/UpperRelop'
     */
    if (agInjSp_B.VEMS_vidGET7 < InjSys_idxModAgInjSatMin_C) {
      localSwitch2 = InjSys_idxModAgInjSatMin_C;
    } else {
      localSwitch2 = agInjSp_B.VEMS_vidGET7;
    }

    /* Switch: '<S161>/Switch2' incorporates:
     *  Constant: '<S148>/InjSys_idxModAgInjSatMax_C1'
     *  RelationalOperator: '<S161>/LowerRelop1'
     */
    if (agInjSp_B.VEMS_vidGET7 > InjSys_idxModAgInjSatMax_C) {
      localSwitch2 = InjSys_idxModAgInjSatMax_C;
    }

    /* Assignment: '<S148>/Assignment1' incorporates:
     *  Constant: '<S148>/Constant2'
     */
    localAssignment2[localSwitch2 - 1] = TRUE;

    /* Switch: '<S164>/Switch' incorporates:
     *  Constant: '<S148>/InjSys_idxModAgInjSatMin_C2'
     *  RelationalOperator: '<S164>/UpperRelop'
     */
    if (agInjSp_B.VEMS_vidGET6 < InjSys_idxModAgInjSatMin_C) {
      localSwitch2 = InjSys_idxModAgInjSatMin_C;
    } else {
      localSwitch2 = agInjSp_B.VEMS_vidGET6;
    }

    /* Switch: '<S164>/Switch2' incorporates:
     *  Constant: '<S148>/InjSys_idxModAgInjSatMax_C2'
     *  RelationalOperator: '<S164>/LowerRelop1'
     */
    if (agInjSp_B.VEMS_vidGET6 > InjSys_idxModAgInjSatMax_C) {
      localSwitch2 = InjSys_idxModAgInjSatMax_C;
    }

    /* Assignment: '<S148>/Assignment2' incorporates:
     *  Constant: '<S148>/Constant3'
     */
    localAssignment2[localSwitch2 - 1] = TRUE;

    /* Switch: '<S167>/Switch' incorporates:
     *  Constant: '<S148>/InjSys_idxModAgInjSatMin_C3'
     *  RelationalOperator: '<S167>/UpperRelop'
     */
    if (agInjSp_B.VEMS_vidGET8 < InjSys_idxModAgInjSatMin_C) {
      localSwitch2 = InjSys_idxModAgInjSatMin_C;
    } else {
      localSwitch2 = agInjSp_B.VEMS_vidGET8;
    }

    /* Switch: '<S167>/Switch2' incorporates:
     *  Constant: '<S148>/InjSys_idxModAgInjSatMax_C3'
     *  RelationalOperator: '<S167>/LowerRelop1'
     */
    if (agInjSp_B.VEMS_vidGET8 > InjSys_idxModAgInjSatMax_C) {
      localSwitch2 = InjSys_idxModAgInjSatMax_C;
    }

    /* Assignment: '<S148>/Assignment3' incorporates:
     *  Constant: '<S148>/Constant4'
     */
    for (locali = 0; locali < 15; locali++) {
      InjSys_prm_bAcvAgInj3SpCal[(locali)] = localAssignment2[locali];
    }

    InjSys_prm_bAcvAgInj3SpCal[localSwitch2 - 1] = TRUE;

    /* SignalConversion: '<S168>/Signal Conversion' */
    InjSys_bAcvAgInj3SpCal1 = InjSys_prm_bAcvAgInj3SpCal[0];

    /* SignalConversion: '<S168>/Signal Conversion1' */
    InjSys_bAcvAgInj3SpCal2 = InjSys_prm_bAcvAgInj3SpCal[1];

    /* SignalConversion: '<S168>/Signal Conversion10' */
    InjSys_bAcvAgInj3SpCal11 = InjSys_prm_bAcvAgInj3SpCal[10];

    /* SignalConversion: '<S168>/Signal Conversion11' */
    InjSys_bAcvAgInj3SpCal12 = InjSys_prm_bAcvAgInj3SpCal[11];

    /* SignalConversion: '<S168>/Signal Conversion12' */
    InjSys_bAcvAgInj3SpCal13 = InjSys_prm_bAcvAgInj3SpCal[12];

    /* SignalConversion: '<S168>/Signal Conversion13' */
    InjSys_bAcvAgInj3SpCal14 = InjSys_prm_bAcvAgInj3SpCal[13];

    /* SignalConversion: '<S168>/Signal Conversion14' */
    InjSys_bAcvAgInj3SpCal15 = InjSys_prm_bAcvAgInj3SpCal[14];

    /* SignalConversion: '<S168>/Signal Conversion2' */
    InjSys_bAcvAgInj3SpCal3 = InjSys_prm_bAcvAgInj3SpCal[2];

    /* SignalConversion: '<S168>/Signal Conversion3' */
    InjSys_bAcvAgInj3SpCal4 = InjSys_prm_bAcvAgInj3SpCal[3];

    /* SignalConversion: '<S168>/Signal Conversion4' */
    InjSys_bAcvAgInj3SpCal5 = InjSys_prm_bAcvAgInj3SpCal[4];

    /* SignalConversion: '<S168>/Signal Conversion5' */
    InjSys_bAcvAgInj3SpCal6 = InjSys_prm_bAcvAgInj3SpCal[5];

    /* SignalConversion: '<S168>/Signal Conversion6' */
    InjSys_bAcvAgInj3SpCal7 = InjSys_prm_bAcvAgInj3SpCal[6];

    /* SignalConversion: '<S168>/Signal Conversion7' */
    InjSys_bAcvAgInj3SpCal8 = InjSys_prm_bAcvAgInj3SpCal[7];

    /* SignalConversion: '<S168>/Signal Conversion8' */
    InjSys_bAcvAgInj3SpCal9 = InjSys_prm_bAcvAgInj3SpCal[8];

    /* SignalConversion: '<S168>/Signal Conversion9' */
    InjSys_bAcvAgInj3SpCal10 = InjSys_prm_bAcvAgInj3SpCal[9];

    /* Outputs for enable SubSystem: '<S149>/F02_Calibration_1_agInj3Sp' incorporates:
     *  EnablePort: '<S169>/Enable'
     */
    if (InjSys_bAcvAgInj3SpCal1) {
      /* Lookup2D: '<S185>/Look-Up Table (2-D)'
       * About '<S185>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_e), (&(InjSys_agInj3SpCal1_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal1X_A[0])),
                         15U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal1Y_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S185>/Data Type Duplicate2'
       *
       * Regarding '<S185>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S169>/DTC32' incorporates:
       *  Lookup2D: '<S185>/Look-Up Table (2-D)'
       */
      InjSys_agInj3SpCal1 = ((Float)localLookUpTable2D_e) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S149>/F02_Calibration_1_agInj3Sp' */

    /* Outputs for enable SubSystem: '<S149>/F03_Calibration_2_agInj3Sp' incorporates:
     *  EnablePort: '<S170>/Enable'
     */
    if (InjSys_bAcvAgInj3SpCal2) {
      /* Lookup2D: '<S186>/Look-Up Table (2-D)'
       * About '<S186>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_p), (&(InjSys_agInj3SpCal2_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal2X_A[0])),
                         15U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal2Y_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S186>/Data Type Duplicate2'
       *
       * Regarding '<S186>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S170>/DTC32' incorporates:
       *  Lookup2D: '<S186>/Look-Up Table (2-D)'
       */
      InjSys_agInj3SpCal2 = ((Float)localLookUpTable2D_p) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S149>/F03_Calibration_2_agInj3Sp' */

    /* Outputs for enable SubSystem: '<S149>/F04_Calibration_3_agInj3Sp' incorporates:
     *  EnablePort: '<S171>/Enable'
     */
    if (InjSys_bAcvAgInj3SpCal3) {
      /* Lookup2D: '<S187>/Look-Up Table (2-D)'
       * About '<S187>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_kb), (&(InjSys_agInj3SpCal3_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal3X_A[0])),
                         15U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal3Y_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S187>/Data Type Duplicate2'
       *
       * Regarding '<S187>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S171>/DTC32' incorporates:
       *  Lookup2D: '<S187>/Look-Up Table (2-D)'
       */
      InjSys_agInj3SpCal3 = ((Float)localLookUpTable2D_kb) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S149>/F04_Calibration_3_agInj3Sp' */

    /* Outputs for enable SubSystem: '<S149>/F05_Calibration_4_agInj3Sp' incorporates:
     *  EnablePort: '<S172>/Enable'
     */
    if (InjSys_bAcvAgInj3SpCal4) {
      /* Lookup2D: '<S188>/Look-Up Table (2-D)'
       * About '<S188>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_nv), (&(InjSys_agInj3SpCal4_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal4X_A[0])),
                         15U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal4Y_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S188>/Data Type Duplicate2'
       *
       * Regarding '<S188>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S172>/DTC32' incorporates:
       *  Lookup2D: '<S188>/Look-Up Table (2-D)'
       */
      InjSys_agInj3SpCal4 = ((Float)localLookUpTable2D_nv) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S149>/F05_Calibration_4_agInj3Sp' */

    /* Outputs for enable SubSystem: '<S149>/F06_Calibration_5_agInj3Sp' incorporates:
     *  EnablePort: '<S173>/Enable'
     */
    if (InjSys_bAcvAgInj3SpCal5) {
      /* Lookup2D: '<S189>/Look-Up Table (2-D)'
       * About '<S189>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_ba), (&(InjSys_agInj3SpCal5_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal5X_A[0])),
                         15U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal5Y_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S189>/Data Type Duplicate2'
       *
       * Regarding '<S189>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S173>/DTC32' incorporates:
       *  Lookup2D: '<S189>/Look-Up Table (2-D)'
       */
      InjSys_agInj3SpCal5 = ((Float)localLookUpTable2D_ba) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S149>/F06_Calibration_5_agInj3Sp' */

    /* Outputs for enable SubSystem: '<S149>/F07_Calibration_6_agInj3Sp' incorporates:
     *  EnablePort: '<S174>/Enable'
     */
    if (InjSys_bAcvAgInj3SpCal6) {
      /* Lookup2D: '<S190>/Look-Up Table (2-D)'
       * About '<S190>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_f), (&(InjSys_agInj3SpCal6_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal6X_A[0])),
                         15U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal6Y_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S190>/Data Type Duplicate2'
       *
       * Regarding '<S190>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S174>/DTC32' incorporates:
       *  Lookup2D: '<S190>/Look-Up Table (2-D)'
       */
      InjSys_agInj3SpCal6 = ((Float)localLookUpTable2D_f) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S149>/F07_Calibration_6_agInj3Sp' */

    /* Outputs for enable SubSystem: '<S149>/F08_Calibration_7_agInj3Sp' incorporates:
     *  EnablePort: '<S175>/Enable'
     */
    if (InjSys_bAcvAgInj3SpCal7) {
      /* Lookup2D: '<S191>/Look-Up Table (2-D)'
       * About '<S191>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_h), (&(InjSys_agInj3SpCal7_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal7X_A[0])),
                         15U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal7Y_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S191>/Data Type Duplicate2'
       *
       * Regarding '<S191>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S175>/DTC32' incorporates:
       *  Lookup2D: '<S191>/Look-Up Table (2-D)'
       */
      InjSys_agInj3SpCal7 = ((Float)localLookUpTable2D_h) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S149>/F08_Calibration_7_agInj3Sp' */

    /* Outputs for enable SubSystem: '<S149>/F09_Calibration_8_agInj3Sp' incorporates:
     *  EnablePort: '<S176>/Enable'
     */
    if (InjSys_bAcvAgInj3SpCal8) {
      /* Lookup2D: '<S192>/Look-Up Table (2-D)'
       * About '<S192>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_ax), (&(InjSys_agInj3SpCal8_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal8X_A[0])),
                         15U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal8Y_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S192>/Data Type Duplicate2'
       *
       * Regarding '<S192>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S176>/DTC32' incorporates:
       *  Lookup2D: '<S192>/Look-Up Table (2-D)'
       */
      InjSys_agInj3SpCal8 = ((Float)localLookUpTable2D_ax) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S149>/F09_Calibration_8_agInj3Sp' */

    /* Outputs for enable SubSystem: '<S149>/F10_Calibration_9_agInj3Sp' incorporates:
     *  EnablePort: '<S177>/Enable'
     */
    if (InjSys_bAcvAgInj3SpCal9) {
      /* Lookup2D: '<S193>/Look-Up Table (2-D)'
       * About '<S193>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_i), (&(InjSys_agInj3SpCal9_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal9X_A[0])),
                         15U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal9Y_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S193>/Data Type Duplicate2'
       *
       * Regarding '<S193>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S177>/DTC32' incorporates:
       *  Lookup2D: '<S193>/Look-Up Table (2-D)'
       */
      InjSys_agInj3SpCal9 = ((Float)localLookUpTable2D_i) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S149>/F10_Calibration_9_agInj3Sp' */

    /* Outputs for enable SubSystem: '<S149>/F11_Calibration_10_agInj3Sp' incorporates:
     *  EnablePort: '<S178>/Enable'
     */
    if (InjSys_bAcvAgInj3SpCal10) {
      /* Lookup2D: '<S194>/Look-Up Table (2-D)'
       * About '<S194>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_b), (&(InjSys_agInj3SpCal10_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal10X_A[0])),
                         7U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal10Y_A[0])), 7U);

      /* DataTypeDuplicate Block: '<S194>/Data Type Duplicate2'
       *
       * Regarding '<S194>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S178>/DTC32' incorporates:
       *  Lookup2D: '<S194>/Look-Up Table (2-D)'
       */
      InjSys_agInj3SpCal10 = ((Float)localLookUpTable2D_b) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S149>/F11_Calibration_10_agInj3Sp' */

    /* Outputs for enable SubSystem: '<S149>/F12_Calibration_11_agInj3Sp' incorporates:
     *  EnablePort: '<S179>/Enable'
     */
    if (InjSys_bAcvAgInj3SpCal11) {
      /* Lookup2D: '<S195>/Look-Up Table (2-D)'
       * About '<S195>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_k), (&(InjSys_agInj3SpCal11_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal11X_A[0])),
                         7U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal11Y_A[0])), 7U);

      /* DataTypeDuplicate Block: '<S195>/Data Type Duplicate2'
       *
       * Regarding '<S195>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S179>/DTC32' incorporates:
       *  Lookup2D: '<S195>/Look-Up Table (2-D)'
       */
      InjSys_agInj3SpCal11 = ((Float)localLookUpTable2D_k) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S149>/F12_Calibration_11_agInj3Sp' */

    /* Outputs for enable SubSystem: '<S149>/F13_Calibration_12_agInj3Sp' incorporates:
     *  EnablePort: '<S180>/Enable'
     */
    if (InjSys_bAcvAgInj3SpCal12) {
      /* Lookup2D: '<S196>/Look-Up Table (2-D)'
       * About '<S196>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_a), (&(InjSys_agInj3SpCal12_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal12X_A[0])),
                         7U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal12Y_A[0])), 7U);

      /* DataTypeDuplicate Block: '<S196>/Data Type Duplicate2'
       *
       * Regarding '<S196>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S180>/DTC32' incorporates:
       *  Lookup2D: '<S196>/Look-Up Table (2-D)'
       */
      InjSys_agInj3SpCal12 = ((Float)localLookUpTable2D_a) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S149>/F13_Calibration_12_agInj3Sp' */

    /* Outputs for enable SubSystem: '<S149>/F14_Calibration_13_agInj3Sp' incorporates:
     *  EnablePort: '<S181>/Enable'
     */
    if (InjSys_bAcvAgInj3SpCal13) {
      /* Lookup2D: '<S197>/Look-Up Table (2-D)'
       * About '<S197>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_l), (&(InjSys_agInj3SpCal13_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal13X_A[0])),
                         7U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal13Y_A[0])), 7U);

      /* DataTypeDuplicate Block: '<S197>/Data Type Duplicate2'
       *
       * Regarding '<S197>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S181>/DTC32' incorporates:
       *  Lookup2D: '<S197>/Look-Up Table (2-D)'
       */
      InjSys_agInj3SpCal13 = ((Float)localLookUpTable2D_l) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S149>/F14_Calibration_13_agInj3Sp' */

    /* Outputs for enable SubSystem: '<S149>/F15_Calibration_14_agInj3Sp' incorporates:
     *  EnablePort: '<S182>/Enable'
     */
    if (InjSys_bAcvAgInj3SpCal14) {
      /* Lookup2D: '<S198>/Look-Up Table (2-D)'
       * About '<S198>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_n), (&(InjSys_agInj3SpCal14_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal14X_A[0])),
                         7U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal14Y_A[0])), 7U);

      /* DataTypeDuplicate Block: '<S198>/Data Type Duplicate2'
       *
       * Regarding '<S198>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S182>/DTC32' incorporates:
       *  Lookup2D: '<S198>/Look-Up Table (2-D)'
       */
      InjSys_agInj3SpCal14 = ((Float)localLookUpTable2D_n) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S149>/F15_Calibration_14_agInj3Sp' */

    /* Outputs for enable SubSystem: '<S149>/F16_Calibration_15_agInj3Sp' incorporates:
     *  EnablePort: '<S183>/Enable'
     */
    if (InjSys_bAcvAgInj3SpCal15) {
      /* Lookup2D: '<S199>/Look-Up Table (2-D)'
       * About '<S199>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
       * Output0 Data Type:  Fixed Point    U16  2^-4  FSlope 1.5
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D), (&(InjSys_agInj3SpCal15_M[0])),
                         agInjSp_B.VEMS_vidGET10, (&(InjSys_nEngInjSpCal15X_A[0])),
                         7U, agInjSp_B.VEMS_vidGET9,
                         (&(InjSys_mAirInjSpCal15Y_A[0])), 7U);

      /* DataTypeDuplicate Block: '<S199>/Data Type Duplicate2'
       *
       * Regarding '<S199>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* DataTypeConversion: '<S183>/DTC32' incorporates:
       *  Lookup2D: '<S199>/Look-Up Table (2-D)'
       */
      InjSys_agInj3SpCal15 = ((Float)localLookUpTable2D) * 0.09375F;
    }

    /* end of Outputs for SubSystem: '<S149>/F16_Calibration_15_agInj3Sp' */

    /* DataTypeConversion: '<S184>/DTC32' */
    InjSys_prm_agInj3SpCal[0] = InjSys_agInj3SpCal1;
    InjSys_prm_agInj3SpCal[1] = InjSys_agInj3SpCal2;
    InjSys_prm_agInj3SpCal[2] = InjSys_agInj3SpCal3;
    InjSys_prm_agInj3SpCal[3] = InjSys_agInj3SpCal4;
    InjSys_prm_agInj3SpCal[4] = InjSys_agInj3SpCal5;
    InjSys_prm_agInj3SpCal[5] = InjSys_agInj3SpCal6;
    InjSys_prm_agInj3SpCal[6] = InjSys_agInj3SpCal7;
    InjSys_prm_agInj3SpCal[7] = InjSys_agInj3SpCal8;
    InjSys_prm_agInj3SpCal[8] = InjSys_agInj3SpCal9;
    InjSys_prm_agInj3SpCal[9] = InjSys_agInj3SpCal10;
    InjSys_prm_agInj3SpCal[10] = InjSys_agInj3SpCal11;
    InjSys_prm_agInj3SpCal[11] = InjSys_agInj3SpCal12;
    InjSys_prm_agInj3SpCal[12] = InjSys_agInj3SpCal13;
    InjSys_prm_agInj3SpCal[13] = InjSys_agInj3SpCal14;
    InjSys_prm_agInj3SpCal[14] = InjSys_agInj3SpCal15;

    /* Selector: '<S150>/Selector' */
    InjSys_agInj3SpBas1ModCur = InjSys_prm_agInj3SpCal[agInjSp_B.VEMS_vidGET5 -
      1];

    /* Selector: '<S150>/Selector1' */
    InjSys_agInj3SpBas2ModCur = InjSys_prm_agInj3SpCal[agInjSp_B.VEMS_vidGET7 -
      1];

    /* Selector: '<S150>/Selector2' */
    InjSys_agInj3SpBas1ModTar = InjSys_prm_agInj3SpCal[agInjSp_B.VEMS_vidGET6 -
      1];

    /* Selector: '<S150>/Selector3' */
    InjSys_agInj3SpBas2ModTar = InjSys_prm_agInj3SpCal[agInjSp_B.VEMS_vidGET8 -
      1];

    /* DataTypeConversion: '<S151>/Data Type Conversion1' */
    localDivide_k = ((Float)agInjSp_B.VEMS_vidGET3) * 0.0078125F;

    /* Switch: '<S206>/Switch2' incorporates:
     *  Constant: '<S200>/Constant'
     *  RelationalOperator: '<S206>/LowerRelop1'
     */
    if (localDivide_k > 1.0F) {
      localDivide_k = 1.0F;
    }

    /* Sum: '<S200>/Sum2' incorporates:
     *  Product: '<S200>/Divide'
     *  Sum: '<S200>/Sum3'
     */
    InjSys_agInj3SpModTar_MP = ((InjSys_agInj3SpBas1ModTar -
      InjSys_agInj3SpBas2ModTar) * localDivide_k) + InjSys_agInj3SpBas2ModTar;

    /* DataTypeConversion: '<S151>/Data Type Conversion2' */
    localDivide_k = ((Float)agInjSp_B.VEMS_vidGET2) * 0.0078125F;

    /* Switch: '<S210>/Switch2' incorporates:
     *  Constant: '<S201>/Constant'
     *  RelationalOperator: '<S210>/LowerRelop1'
     */
    if (localDivide_k > 1.0F) {
      localDivide_k = 1.0F;
    }

    /* Sum: '<S201>/Sum2' incorporates:
     *  Product: '<S201>/Divide'
     *  Sum: '<S201>/Sum3'
     */
    InjSys_agInj3SpModCur_MP = ((InjSys_agInj3SpBas1ModCur -
      InjSys_agInj3SpBas2ModCur) * localDivide_k) + InjSys_agInj3SpBas2ModCur;

    /* DataTypeConversion: '<S151>/Data Type Conversion3' */
    localDivide_k = ((Float)agInjSp_B.VEMS_vidGET4) * 0.0078125F;

    /* Switch: '<S214>/Switch2' incorporates:
     *  Constant: '<S202>/Constant'
     *  RelationalOperator: '<S214>/LowerRelop1'
     */
    if (localDivide_k > 1.0F) {
      localDivide_k = 1.0F;
    }

    /* Product: '<S202>/Divide' incorporates:
     *  Sum: '<S202>/Sum3'
     */
    localDivide_k *= InjSys_agInj3SpModTar_MP - InjSys_agInj3SpModCur_MP;

    /* Sum: '<S202>/Sum2' */
    localtmp = ((Double)(InjSys_agInj3SpModCur_MP + localDivide_k)) / 0.09375;
    if (localtmp < 65536.0) {
      if (localtmp >= 0.0) {
        agInjSp_B.Merge2 = (UInt16)localtmp;
      } else {
        agInjSp_B.Merge2 = 0U;
      }
    } else {
      agInjSp_B.Merge2 = MAX_uint16_T;
    }
  }

  /* S-Function "vems_vidSET" Block: <S5>/VEMS_vidSET */
  VEMS_vidSET(InjSys_agInj1Sp, agInjSp_B.Merge);

  /* S-Function "vems_vidSET" Block: <S5>/VEMS_vidSET1 */
  VEMS_vidSET(InjSys_agInj2Sp, agInjSp_B.Merge1);

  /* S-Function "vems_vidSET" Block: <S5>/VEMS_vidSET2 */
  VEMS_vidSET(InjSys_agInj3Sp, agInjSp_B.Merge2);
}

/* Model initialize function */
void agInjSp_initialize(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   */
  InjSys_EveRst_agInjSp_Start();
  InjSys_SdlFast_agInjSp_Start();
}

#define AGINJSP_STOP_SEC_CODE
#include "agInjSp_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
