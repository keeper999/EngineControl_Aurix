/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : rInjSp                                                  */
/* !Description     : V01NT1006234.001                                        */
/*                                                                            */
/* !Module          : rInjSp                                                  */
/*                                                                            */
/* !File            : rInjSp.c                                                */
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
/* !Reference       : PTS_DOC_5009687 / 01                                    */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Sun Jan 13 20:30:13 2013                              */
/*   Model name       : rInjSp_AUTOCODE.mdl                                   */
/*   Model version    : 1.181                                                 */
/*   Root subsystem   : /rInjSp                                               */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/RINJSP/rInjSp.c_v         $*/
/* $Revision::   1.4                                                         $*/
/* $Author::   etsasson                               $$Date::   07 Mar 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "rInjSp.h"
#include "rInjSp_private.h"

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
#define RINJSP_START_SEC_VAR_UNSPECIFIED
#include "rInjSp_MemMap.h"

/* Block signals (auto storage) */
BlockIO_rInjSp rInjSp_B;

#define RINJSP_STOP_SEC_VAR_UNSPECIFIED
#include "rInjSp_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define RINJSP_START_SEC_CODE
#include "rInjSp_MemMap.h"

void rInjSp_ASYNC1(int controlPortIdx)
{
}

/* Output and update for function-call system: '<S3>/F01_Initialisation' */
void rInjSp_F01_Initialisation(void)
{
  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET5 */
  VEMS_vidSET(InjSys_rInj1Sp, 32768U);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET6 */
  VEMS_vidSET(InjSys_rInj2Sp, 0U);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET7 */
  VEMS_vidSET(InjSys_rInj3Sp, 0U);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET4 */
  VEMS_vidSET(InjSys_noInjPat, ((UInt8)0U));

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET */
  VEMS_vidSET(InjSys_bAcvInjPat0, TRUE);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET1 */
  VEMS_vidSET(InjSys_bAcvInjPat1, FALSE);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET2 */
  VEMS_vidSET(InjSys_bAcvInjPat2, FALSE);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET3 */
  VEMS_vidSET(InjSys_bAcvInjPat3, FALSE);
}

/* Output and update for exported function: InjSys_EveRst_rInjSp */
void InjSys_EveRst_rInjSp(void)
{
  /* S-Function (fcncallgen): '<S1>/expFcn' incorporates:
   *  SubSystem: '<S3>/F01_Initialisation'
   */
  rInjSp_F01_Initialisation();
}

/* Output and update for function-call system: '<S3>/F02_rInjSp' */
void rInjSp_F02_rInjSp(void)
{
  /* local block i/o variables */
  UInt16 localLookUpTable2D;
  UInt16 localLookUpTable2D_p;
  UInt8 localLookUpTable2D_n;
  Float32 localSwitch2;
  Float32 localSwitch2_k;
  Float32 localAdd2_p;
  Boolean localRelationalOperator3;
  Boolean localRelationalOperator4;
  Boolean localAssignment2_n[13];
  UInt8 localSwitch2_c;
  UInt8 localSwitch3;
  UInt16 localSwitch;
  SInt32 locali;
  Float32 localtmp;

  /* Outputs for enable SubSystem: '<S5>/F02_rInjSp' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/RINJSP_u8Inhib'
   *  EnablePort: '<S6>/Enable'
   *  RelationalOperator: '<S5>/Relational Operator'
   */
  if (RINJSP_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET */
    VEMS_vidGET(Ext_nEng, rInjSp_B.VEMS_vidGET);

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

    /* DataTypeConversion Block: '<S11>/Data Type Conversion'
     *
     * Regarding '<S11>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET1 */
    VEMS_vidGET(Ext_pDsThrMesSI, rInjSp_B.VEMS_vidGET1);

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

    /* DataTypeConversion Block: '<S11>/Data Type Conversion1'
     *
     * Regarding '<S11>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S11>/Data Type Duplicate1'
     *
     * Regarding '<S11>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET9 */
    VEMS_vidGET(InjSys_mAirPredInjSp, rInjSp_B.VEMS_vidGET9);

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

    /* DataTypeConversion Block: '<S66>/Data Type Conversion1'
     *
     * Regarding '<S66>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S66>/Data Type Duplicate1'
     *
     * Regarding '<S66>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S67>/Data Type Conversion1'
     *
     * Regarding '<S67>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S67>/Data Type Duplicate1'
     *
     * Regarding '<S67>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S68>/Data Type Conversion1'
     *
     * Regarding '<S68>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S68>/Data Type Duplicate1'
     *
     * Regarding '<S68>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S69>/Data Type Conversion1'
     *
     * Regarding '<S69>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S69>/Data Type Duplicate1'
     *
     * Regarding '<S69>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S70>/Data Type Conversion1'
     *
     * Regarding '<S70>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S70>/Data Type Duplicate1'
     *
     * Regarding '<S70>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S71>/Data Type Conversion1'
     *
     * Regarding '<S71>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S71>/Data Type Duplicate1'
     *
     * Regarding '<S71>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S72>/Data Type Conversion1'
     *
     * Regarding '<S72>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S72>/Data Type Duplicate1'
     *
     * Regarding '<S72>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S73>/Data Type Conversion1'
     *
     * Regarding '<S73>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S73>/Data Type Duplicate1'
     *
     * Regarding '<S73>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S74>/Data Type Conversion1'
     *
     * Regarding '<S74>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S74>/Data Type Duplicate1'
     *
     * Regarding '<S74>/Data Type Duplicate1':
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

    /* DataTypeConversion Block: '<S133>/Data Type Conversion1'
     *
     * Regarding '<S133>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S133>/Data Type Duplicate1'
     *
     * Regarding '<S133>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S134>/Data Type Conversion1'
     *
     * Regarding '<S134>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S134>/Data Type Duplicate1'
     *
     * Regarding '<S134>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S135>/Data Type Conversion1'
     *
     * Regarding '<S135>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S135>/Data Type Duplicate1'
     *
     * Regarding '<S135>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* DataTypeConversion Block: '<S136>/Data Type Conversion1'
     *
     * Regarding '<S136>/Data Type Conversion1':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeDuplicate Block: '<S136>/Data Type Duplicate1'
     *
     * Regarding '<S136>/Data Type Duplicate1':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET10 */
    VEMS_vidGET(InjSys_nEngInjSp, rInjSp_B.VEMS_vidGET10);

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

    /* DataTypeConversion Block: '<S66>/Data Type Conversion'
     *
     * Regarding '<S66>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S67>/Data Type Conversion'
     *
     * Regarding '<S67>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S68>/Data Type Conversion'
     *
     * Regarding '<S68>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S69>/Data Type Conversion'
     *
     * Regarding '<S69>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S70>/Data Type Conversion'
     *
     * Regarding '<S70>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S71>/Data Type Conversion'
     *
     * Regarding '<S71>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S72>/Data Type Conversion'
     *
     * Regarding '<S72>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S73>/Data Type Conversion'
     *
     * Regarding '<S73>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S74>/Data Type Conversion'
     *
     * Regarding '<S74>/Data Type Conversion':
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

    /* DataTypeConversion Block: '<S133>/Data Type Conversion'
     *
     * Regarding '<S133>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S134>/Data Type Conversion'
     *
     * Regarding '<S134>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S135>/Data Type Conversion'
     *
     * Regarding '<S135>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* DataTypeConversion Block: '<S136>/Data Type Conversion'
     *
     * Regarding '<S136>/Data Type Conversion':
     *   Eliminate redundant data type conversion
     */

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET5 */
    VEMS_vidGET(InjSys_idxBas1ModCurRatInj, rInjSp_B.VEMS_vidGET5);

    /* DataTypeDuplicate Block: '<S36>/Data Type Duplicate'
     *
     * Regarding '<S36>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S37>/Data Type Duplicate'
     *
     * Regarding '<S37>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S38>/Data Type Propagation'
     *
     * Regarding '<S38>/Data Type Propagation':
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

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET7 */
    VEMS_vidGET(InjSys_idxBas2ModCurRatInj, rInjSp_B.VEMS_vidGET7);

    /* DataTypeDuplicate Block: '<S39>/Data Type Duplicate'
     *
     * Regarding '<S39>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S40>/Data Type Duplicate'
     *
     * Regarding '<S40>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S41>/Data Type Propagation'
     *
     * Regarding '<S41>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S101>/Data Type Duplicate'
     *
     * Regarding '<S101>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S102>/Data Type Duplicate'
     *
     * Regarding '<S102>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S103>/Data Type Propagation'
     *
     * Regarding '<S103>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET6 */
    VEMS_vidGET(InjSys_idxBas1ModTarRatInj, rInjSp_B.VEMS_vidGET6);

    /* DataTypeDuplicate Block: '<S42>/Data Type Duplicate'
     *
     * Regarding '<S42>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S43>/Data Type Duplicate'
     *
     * Regarding '<S43>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S44>/Data Type Propagation'
     *
     * Regarding '<S44>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S104>/Data Type Duplicate'
     *
     * Regarding '<S104>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S105>/Data Type Duplicate'
     *
     * Regarding '<S105>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S106>/Data Type Propagation'
     *
     * Regarding '<S106>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET8 */
    VEMS_vidGET(InjSys_idxBas2ModTarRatInj, rInjSp_B.VEMS_vidGET8);

    /* DataTypeDuplicate Block: '<S45>/Data Type Duplicate'
     *
     * Regarding '<S45>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S46>/Data Type Duplicate'
     *
     * Regarding '<S46>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S47>/Data Type Propagation'
     *
     * Regarding '<S47>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S107>/Data Type Duplicate'
     *
     * Regarding '<S107>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S108>/Data Type Duplicate'
     *
     * Regarding '<S108>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S109>/Data Type Propagation'
     *
     * Regarding '<S109>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET2 */
    VEMS_vidGET(InjSys_facBasModCurRatInj, rInjSp_B.VEMS_vidGET2);

    /* DataTypeDuplicate Block: '<S83>/Data Type Duplicate'
     *
     * Regarding '<S83>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S84>/Data Type Duplicate'
     *
     * Regarding '<S84>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S85>/Data Type Propagation'
     *
     * Regarding '<S85>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S141>/Data Type Duplicate'
     *
     * Regarding '<S141>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S142>/Data Type Duplicate'
     *
     * Regarding '<S142>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S143>/Data Type Propagation'
     *
     * Regarding '<S143>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET3 */
    VEMS_vidGET(InjSys_facBasModTarRatInj, rInjSp_B.VEMS_vidGET3);

    /* DataTypeDuplicate Block: '<S79>/Data Type Duplicate'
     *
     * Regarding '<S79>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S80>/Data Type Duplicate'
     *
     * Regarding '<S80>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S81>/Data Type Propagation'
     *
     * Regarding '<S81>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S145>/Data Type Duplicate'
     *
     * Regarding '<S145>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S146>/Data Type Duplicate'
     *
     * Regarding '<S146>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S147>/Data Type Propagation'
     *
     * Regarding '<S147>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET4 */
    VEMS_vidGET(InjSys_facTranModRatInj, rInjSp_B.VEMS_vidGET4);

    /* DataTypeDuplicate Block: '<S87>/Data Type Duplicate'
     *
     * Regarding '<S87>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S88>/Data Type Duplicate'
     *
     * Regarding '<S88>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S89>/Data Type Propagation'
     *
     * Regarding '<S89>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S149>/Data Type Duplicate'
     *
     * Regarding '<S149>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* DataTypeDuplicate Block: '<S150>/Data Type Duplicate'
     *
     * Regarding '<S150>/Data Type Duplicate':
     *   Unused code path elimination
     */

    /* S-Function Block: '<S151>/Data Type Propagation'
     *
     * Regarding '<S151>/Data Type Propagation':
     *   Unused code path elimination
     */

    /* If: '<S6>/If' incorporates:
     *  ActionPort: '<S7>/Action Port'
     *  ActionPort: '<S8>/Action Port'
     *  Constant: '<S6>/InjSys_bAcvETBrInjSp_C'
     *  SubSystem: '<S6>/F00_rInjSpETB'
     *  SubSystem: '<S6>/F01_FuMassClcn'
     */
    if (InjSys_bAcvETBrInjSp_C) {
      /* Lookup2D: '<S11>/Look-Up Table (2-D)'
       * About '<S11>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^3
       * Output0 Data Type:  Fixed Point    U16  2^-15
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D), (&(InjSys_rInj3SpETB_M[0])),
                         rInjSp_B.VEMS_vidGET, (&(Ext_nEngX_A[0])), 15U,
                         rInjSp_B.VEMS_vidGET1, (&(Ext_pDsThrMesSIY_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S11>/Data Type Duplicate2'
       *
       * Regarding '<S11>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* MultiPortSwitch: '<S7>/Multiport Switch' incorporates:
       *  Constant: '<S7>/InjSys_noETBSelrInj3Sp_C'
       *  Constant: '<S7>/InjSys_rInj3SpETB_C'
       *  Lookup2D: '<S11>/Look-Up Table (2-D)'
       */
      if (InjSys_noETBSelrInj3Sp_C == 0) {
        localSwitch = InjSys_rInj3SpETB_C;
      } else {
        localSwitch = localLookUpTable2D;
      }

      /* DataTypeConversion: '<S7>/Data Type Conversion1' */
      localSwitch2_k = ((Float32)localSwitch) * 3.051757813E-005F;

      /* Switch: '<S22>/Switch2' incorporates:
       *  Constant: '<S7>/InjSys_facGainPresDsThrMesETB_C5'
       *  RelationalOperator: '<S22>/LowerRelop1'
       */
      if (localSwitch2_k > 1.0F) {
        localSwitch2_k = 1.0F;
      }

      /* Sum: '<S7>/Add1' incorporates:
       *  Constant: '<S7>/InjSys_facGainPresDsThrMesETB_C2'
       */
      localAdd2_p = 1.0F - localSwitch2_k;

      /* Lookup2D: '<S10>/Look-Up Table (2-D)'
       * About '<S10>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^3
       * Output0 Data Type:  Fixed Point    U16  2^-15
       * Lookup Method: Linear_Endpoint
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      Look2D_U16_U16_U16( &(localLookUpTable2D_p), (&(InjSys_rInj2SpETB_M[0])),
                         rInjSp_B.VEMS_vidGET, (&(Ext_nEngX_A[0])), 15U,
                         rInjSp_B.VEMS_vidGET1, (&(Ext_pDsThrMesSIY_A[0])), 15U);

      /* DataTypeDuplicate Block: '<S10>/Data Type Duplicate2'
       *
       * Regarding '<S10>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* MultiPortSwitch: '<S7>/Multiport Switch1' incorporates:
       *  Constant: '<S7>/InjSys_noETBSelrInj2Sp_C'
       *  Constant: '<S7>/InjSys_rInj2SpETB_C'
       *  Lookup2D: '<S10>/Look-Up Table (2-D)'
       */
      if (InjSys_noETBSelrInj2Sp_C == 0) {
        localSwitch = InjSys_rInj2SpETB_C;
      } else {
        localSwitch = localLookUpTable2D_p;
      }

      /* DataTypeConversion: '<S7>/Data Type Conversion2' */
      InjSys_rInj2SpETBTmp_MP = ((Float32)localSwitch) * 3.051757813E-005F;

      /* Switch: '<S19>/Switch' incorporates:
       *  Constant: '<S7>/InjSys_facGainPresDsThrMesETB_C4'
       *  RelationalOperator: '<S19>/UpperRelop'
       */
      if (InjSys_rInj2SpETBTmp_MP < 0.0F) {
        localSwitch2 = 0.0F;
      } else {
        localSwitch2 = InjSys_rInj2SpETBTmp_MP;
      }

      /* Switch: '<S19>/Switch2' incorporates:
       *  RelationalOperator: '<S19>/LowerRelop1'
       */
      if (!(InjSys_rInj2SpETBTmp_MP > localAdd2_p)) {
        localAdd2_p = localSwitch2;
      }

      /* Lookup2D: '<S9>/Look-Up Table (2-D)'
       * About '<S9>/Look-Up Table (2-D)':
       * Input0  Data Type:  Integer        U16
       * Input1  Data Type:  Fixed Point    U16  2^3
       * Output0 Data Type:  Integer        U8
       * Lookup Method: Nearest
       *
       * Row Data    parameter uses the same data type and scaling as Input0
       * Column Data parameter uses the same data type and scaling as Input1
       * Table Data  parameter uses the same data type and scaling as Output0
       */
      {
        UInt32 iRowIndex1, iColumnIndex1;
        BINARYSEARCH_U16_Near_iL( &(iRowIndex1), rInjSp_B.VEMS_vidGET,
          (&(Ext_nEngX_A[0])), 15U);
        BINARYSEARCH_U16_Near_iL( &(iColumnIndex1), rInjSp_B.VEMS_vidGET1,
          (&(Ext_pDsThrMesSIY_A[0])), 15U);
        localLookUpTable2D_n = InjSys_noInjPatETB_M[iRowIndex1+16*iColumnIndex1];
      }

      /* DataTypeDuplicate Block: '<S9>/Data Type Duplicate2'
       *
       * Regarding '<S9>/Data Type Duplicate2':
       *   Unused code path elimination
       */

      /* MultiPortSwitch: '<S7>/Multiport Switch2' incorporates:
       *  Constant: '<S7>/InjSys_noETBSelnoInjPat_C'
       *  Constant: '<S7>/InjSys_noInjPatETB_C'
       *  Lookup2D: '<S9>/Look-Up Table (2-D)'
       */
      if (InjSys_noETBSelnoInjPat_C == 0) {
        localSwitch2_c = InjSys_noInjPatETB_C;
      } else {
        localSwitch2_c = localLookUpTable2D_n;
      }

      /* RelationalOperator: '<S7>/Relational Operator' incorporates:
       *  Constant: '<S7>/Constant'
       */
      rInjSp_B.Merge4 = (localSwitch2_c == 0);

      /* RelationalOperator: '<S7>/Relational Operator1' incorporates:
       *  Constant: '<S7>/Constant1'
       */
      rInjSp_B.Merge5 = (localSwitch2_c == 1);

      /* RelationalOperator: '<S7>/Relational Operator2' incorporates:
       *  Constant: '<S7>/Constant2'
       */
      rInjSp_B.Merge6 = (localSwitch2_c == 2);

      /* RelationalOperator: '<S7>/Relational Operator3' incorporates:
       *  Constant: '<S7>/Constant3'
       */
      rInjSp_B.Merge7 = (localSwitch2_c == 3);

      /* SignalConversion: '<S7>/Signal Conversion2' */
      rInjSp_B.Merge3 = localSwitch2_c;

      /* DataTypeConversion: '<S14>/OutDTConv' incorporates:
       *  Constant: '<S14>/offset'
       *  Constant: '<S14>/offset1'
       *  Constant: '<S14>/one_on_slope'
       *  Product: '<S14>/Product4'
       *  Sum: '<S14>/Add1'
       *  Sum: '<S14>/Add2'
       */
      localtmp = (32768.0F * localAdd2_p) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          rInjSp_B.Merge1 = (UInt16)localtmp;
        } else {
          rInjSp_B.Merge1 = 0U;
        }
      } else {
        rInjSp_B.Merge1 = MAX_uint16_T;
      }

      /* DataTypeConversion: '<S15>/OutDTConv' incorporates:
       *  Constant: '<S15>/offset'
       *  Constant: '<S15>/offset1'
       *  Constant: '<S15>/one_on_slope'
       *  Product: '<S15>/Product4'
       *  Sum: '<S15>/Add1'
       *  Sum: '<S15>/Add2'
       */
      rInjSp_B.Merge2 = (UInt16)((32768.0F * localSwitch2_k) + 0.5F);

      /* DataTypeConversion: '<S16>/OutDTConv' incorporates:
       *  Constant: '<S16>/offset'
       *  Constant: '<S16>/offset1'
       *  Constant: '<S16>/one_on_slope'
       *  Constant: '<S7>/InjSys_facGainPresDsThrMesETB_C1'
       *  Product: '<S16>/Product4'
       *  Sum: '<S16>/Add1'
       *  Sum: '<S16>/Add2'
       *  Sum: '<S7>/Add2'
       */
      localtmp = (((1.0F - localSwitch2_k) - localAdd2_p) * 32768.0F) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          rInjSp_B.Merge = (UInt16)localtmp;
        } else {
          rInjSp_B.Merge = 0U;
        }
      } else {
        rInjSp_B.Merge = MAX_uint16_T;
      }
    } else {
      /* Outputs for atomic SubSystem: '<S8>/F01_FuMass3Tmp' */

      /* Outputs for atomic SubSystem: '<S23>/F02_Mode_Mask_FuMass3Tmp' */

      /* SignalConversion: '<S28>/TmpSignal ConversionAtAssignmentInport1' incorporates:
       *  Constant: '<S28>/Constant'
       */
      localAssignment2_n[0] = FALSE;
      localAssignment2_n[1] = FALSE;
      localAssignment2_n[2] = FALSE;
      localAssignment2_n[3] = FALSE;
      localAssignment2_n[4] = FALSE;
      localAssignment2_n[5] = FALSE;
      localAssignment2_n[6] = FALSE;
      localAssignment2_n[7] = FALSE;
      localAssignment2_n[8] = FALSE;
      localAssignment2_n[9] = FALSE;
      localAssignment2_n[10] = FALSE;
      localAssignment2_n[11] = FALSE;
      localAssignment2_n[12] = FALSE;

      /* Switch: '<S38>/Switch' incorporates:
       *  Constant: '<S28>/InjSys_idxModRatInjSatMin_C'
       *  RelationalOperator: '<S38>/UpperRelop'
       */
      if (rInjSp_B.VEMS_vidGET5 < InjSys_idxModRatInjSatMin_C) {
        localSwitch2_c = InjSys_idxModRatInjSatMin_C;
      } else {
        localSwitch2_c = rInjSp_B.VEMS_vidGET5;
      }

      /* Switch: '<S38>/Switch2' incorporates:
       *  Constant: '<S28>/InjSys_idxModRatInjSatMax_C'
       *  RelationalOperator: '<S38>/LowerRelop1'
       */
      if (rInjSp_B.VEMS_vidGET5 > InjSys_idxModRatInjSatMax_C) {
        localSwitch2_c = InjSys_idxModRatInjSatMax_C;
      }

      /* Assignment: '<S28>/Assignment' incorporates:
       *  Constant: '<S28>/Constant1'
       */
      localAssignment2_n[localSwitch2_c - 1] = TRUE;

      /* Switch: '<S41>/Switch' incorporates:
       *  Constant: '<S28>/InjSys_idxModRatInjSatMin_C1'
       *  RelationalOperator: '<S41>/UpperRelop'
       */
      if (rInjSp_B.VEMS_vidGET7 < InjSys_idxModRatInjSatMin_C) {
        localSwitch2_c = InjSys_idxModRatInjSatMin_C;
      } else {
        localSwitch2_c = rInjSp_B.VEMS_vidGET7;
      }

      /* Switch: '<S41>/Switch2' incorporates:
       *  Constant: '<S28>/InjSys_idxModRatInjSatMax_C1'
       *  RelationalOperator: '<S41>/LowerRelop1'
       */
      if (rInjSp_B.VEMS_vidGET7 > InjSys_idxModRatInjSatMax_C) {
        localSwitch2_c = InjSys_idxModRatInjSatMax_C;
      }

      /* Assignment: '<S28>/Assignment1' incorporates:
       *  Constant: '<S28>/Constant2'
       */
      localAssignment2_n[localSwitch2_c - 1] = TRUE;

      /* Switch: '<S44>/Switch' incorporates:
       *  Constant: '<S28>/InjSys_idxModRatInjSatMin_C2'
       *  RelationalOperator: '<S44>/UpperRelop'
       */
      if (rInjSp_B.VEMS_vidGET6 < InjSys_idxModRatInjSatMin_C) {
        localSwitch2_c = InjSys_idxModRatInjSatMin_C;
      } else {
        localSwitch2_c = rInjSp_B.VEMS_vidGET6;
      }

      /* Switch: '<S44>/Switch2' incorporates:
       *  Constant: '<S28>/InjSys_idxModRatInjSatMax_C2'
       *  RelationalOperator: '<S44>/LowerRelop1'
       */
      if (rInjSp_B.VEMS_vidGET6 > InjSys_idxModRatInjSatMax_C) {
        localSwitch2_c = InjSys_idxModRatInjSatMax_C;
      }

      /* Assignment: '<S28>/Assignment2' incorporates:
       *  Constant: '<S28>/Constant3'
       */
      localAssignment2_n[localSwitch2_c - 1] = TRUE;

      /* Switch: '<S47>/Switch' incorporates:
       *  Constant: '<S28>/InjSys_idxModRatInjSatMin_C3'
       *  RelationalOperator: '<S47>/UpperRelop'
       */
      if (rInjSp_B.VEMS_vidGET8 < InjSys_idxModRatInjSatMin_C) {
        localSwitch2_c = InjSys_idxModRatInjSatMin_C;
      } else {
        localSwitch2_c = rInjSp_B.VEMS_vidGET8;
      }

      /* Switch: '<S47>/Switch2' incorporates:
       *  Constant: '<S28>/InjSys_idxModRatInjSatMax_C3'
       *  RelationalOperator: '<S47>/LowerRelop1'
       */
      if (rInjSp_B.VEMS_vidGET8 > InjSys_idxModRatInjSatMax_C) {
        localSwitch2_c = InjSys_idxModRatInjSatMax_C;
      }

      /* Assignment: '<S28>/Assignment3' incorporates:
       *  Constant: '<S28>/Constant4'
       */
      for (locali = 0; locali < 13; locali++) {
        InjSys_prm_bAcvRatInj3SpCal[(locali)] = localAssignment2_n[locali];
      }

      InjSys_prm_bAcvRatInj3SpCal[localSwitch2_c - 1] = TRUE;

      /* end of Outputs for SubSystem: '<S23>/F02_Mode_Mask_FuMass3Tmp' */

      /* Outputs for atomic SubSystem: '<S23>/F03_Calibrations_FuMass3Tmp' */

      /* Outputs for atomic SubSystem: '<S29>/F01_Unvectorize_Activation_Boolean_FuMass3Tmp' */

      /* SignalConversion: '<S48>/Signal Conversion' */
      InjSys_bAcvRatInj3SpCal1 = InjSys_prm_bAcvRatInj3SpCal[0];

      /* SignalConversion: '<S48>/Signal Conversion1' */
      InjSys_bAcvRatInj3SpCal2 = InjSys_prm_bAcvRatInj3SpCal[1];

      /* SignalConversion: '<S48>/Signal Conversion10' */
      InjSys_bAcvRatInj3SpCal11 = InjSys_prm_bAcvRatInj3SpCal[10];

      /* SignalConversion: '<S48>/Signal Conversion11' */
      InjSys_bAcvRatInj3SpCal12 = InjSys_prm_bAcvRatInj3SpCal[11];

      /* SignalConversion: '<S48>/Signal Conversion12' */
      InjSys_bAcvRatInj3SpCal13 = InjSys_prm_bAcvRatInj3SpCal[12];

      /* SignalConversion: '<S48>/Signal Conversion2' */
      InjSys_bAcvRatInj3SpCal3 = InjSys_prm_bAcvRatInj3SpCal[2];

      /* SignalConversion: '<S48>/Signal Conversion3' */
      InjSys_bAcvRatInj3SpCal4 = InjSys_prm_bAcvRatInj3SpCal[3];

      /* SignalConversion: '<S48>/Signal Conversion4' */
      InjSys_bAcvRatInj3SpCal5 = InjSys_prm_bAcvRatInj3SpCal[4];

      /* SignalConversion: '<S48>/Signal Conversion5' */
      InjSys_bAcvRatInj3SpCal6 = InjSys_prm_bAcvRatInj3SpCal[5];

      /* SignalConversion: '<S48>/Signal Conversion6' */
      InjSys_bAcvRatInj3SpCal7 = InjSys_prm_bAcvRatInj3SpCal[6];

      /* SignalConversion: '<S48>/Signal Conversion7' */
      InjSys_bAcvRatInj3SpCal8 = InjSys_prm_bAcvRatInj3SpCal[7];

      /* SignalConversion: '<S48>/Signal Conversion8' */
      InjSys_bAcvRatInj3SpCal9 = InjSys_prm_bAcvRatInj3SpCal[8];

      /* SignalConversion: '<S48>/Signal Conversion9' */
      InjSys_bAcvRatInj3SpCal10 = InjSys_prm_bAcvRatInj3SpCal[9];

      /* end of Outputs for SubSystem: '<S29>/F01_Unvectorize_Activation_Boolean_FuMass3Tmp' */

      /* Outputs for enable SubSystem: '<S29>/F02_Calibration_1_FuMass3Tmp' incorporates:
       *  EnablePort: '<S49>/Enable'
       */
      if (InjSys_bAcvRatInj3SpCal1) {
        /* Lookup2D: '<S63>/Look-Up Table (2-D)'
         * About '<S63>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Nearest
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        {
          UInt32 iRowIndex1, iColumnIndex1;
          BINARYSEARCH_U16_Near_iL( &(iRowIndex1), rInjSp_B.VEMS_vidGET10,
            (&(InjSys_nEngInjSpCal1X_A[0])), 15U);
          BINARYSEARCH_U16_Near_iL( &(iColumnIndex1), rInjSp_B.VEMS_vidGET9,
            (&(InjSys_mAirInjSpCal1Y_A[0])), 15U);
          InjSys_rInj3SpCal1 = InjSys_rInj3Cal1_M[iRowIndex1+16*iColumnIndex1];
        }

        /* DataTypeDuplicate Block: '<S63>/Data Type Duplicate2'
         *
         * Regarding '<S63>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S29>/F02_Calibration_1_FuMass3Tmp' */

      /* Outputs for enable SubSystem: '<S29>/F03_Calibration_2_FuMass3Tmp' incorporates:
       *  EnablePort: '<S50>/Enable'
       */
      if (InjSys_bAcvRatInj3SpCal2) {
        /* Lookup2D: '<S64>/Look-Up Table (2-D)'
         * About '<S64>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Nearest
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        {
          UInt32 iRowIndex1, iColumnIndex1;
          BINARYSEARCH_U16_Near_iL( &(iRowIndex1), rInjSp_B.VEMS_vidGET10,
            (&(InjSys_nEngInjSpCal2X_A[0])), 15U);
          BINARYSEARCH_U16_Near_iL( &(iColumnIndex1), rInjSp_B.VEMS_vidGET9,
            (&(InjSys_mAirInjSpCal2Y_A[0])), 15U);
          InjSys_rInj3SpCal2 = InjSys_rInj3Cal2_M[iRowIndex1+16*iColumnIndex1];
        }

        /* DataTypeDuplicate Block: '<S64>/Data Type Duplicate2'
         *
         * Regarding '<S64>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S29>/F03_Calibration_2_FuMass3Tmp' */

      /* Outputs for enable SubSystem: '<S29>/F04_Calibration_3_FuMass3Tmp' incorporates:
       *  EnablePort: '<S51>/Enable'
       */
      if (InjSys_bAcvRatInj3SpCal3) {
        /* Lookup2D: '<S65>/Look-Up Table (2-D)'
         * About '<S65>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Nearest
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        {
          UInt32 iRowIndex1, iColumnIndex1;
          BINARYSEARCH_U16_Near_iL( &(iRowIndex1), rInjSp_B.VEMS_vidGET10,
            (&(InjSys_nEngInjSpCal3X_A[0])), 15U);
          BINARYSEARCH_U16_Near_iL( &(iColumnIndex1), rInjSp_B.VEMS_vidGET9,
            (&(InjSys_mAirInjSpCal3Y_A[0])), 15U);
          InjSys_rInj3SpCal3 = InjSys_rInj3Cal3_M[iRowIndex1+16*iColumnIndex1];
        }

        /* DataTypeDuplicate Block: '<S65>/Data Type Duplicate2'
         *
         * Regarding '<S65>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S29>/F04_Calibration_3_FuMass3Tmp' */

      /* Outputs for enable SubSystem: '<S29>/F05_Calibration_4_FuMass3Tmp' incorporates:
       *  EnablePort: '<S52>/Enable'
       */
      if (InjSys_bAcvRatInj3SpCal4) {
        /* Lookup2D: '<S66>/Look-Up Table (2-D)'
         * About '<S66>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Nearest
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        {
          UInt32 iRowIndex1, iColumnIndex1;
          BINARYSEARCH_U16_Near_iL( &(iRowIndex1), rInjSp_B.VEMS_vidGET10,
            (&(InjSys_nEngInjSpCal4X_A[0])), 15U);
          BINARYSEARCH_U16_Near_iL( &(iColumnIndex1), rInjSp_B.VEMS_vidGET9,
            (&(InjSys_mAirInjSpCal4Y_A[0])), 15U);
          InjSys_rInj3SpCal4 = InjSys_rInj3Cal4_M[iRowIndex1+16*iColumnIndex1];
        }

        /* DataTypeDuplicate Block: '<S66>/Data Type Duplicate2'
         *
         * Regarding '<S66>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S29>/F05_Calibration_4_FuMass3Tmp' */

      /* Outputs for enable SubSystem: '<S29>/F06_Calibration_5_FuMass3Tmp' incorporates:
       *  EnablePort: '<S53>/Enable'
       */
      if (InjSys_bAcvRatInj3SpCal5) {
        /* Lookup2D: '<S67>/Look-Up Table (2-D)'
         * About '<S67>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Nearest
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        {
          UInt32 iRowIndex1, iColumnIndex1;
          BINARYSEARCH_U16_Near_iL( &(iRowIndex1), rInjSp_B.VEMS_vidGET10,
            (&(InjSys_nEngInjSpCal5X_A[0])), 15U);
          BINARYSEARCH_U16_Near_iL( &(iColumnIndex1), rInjSp_B.VEMS_vidGET9,
            (&(InjSys_mAirInjSpCal5Y_A[0])), 15U);
          InjSys_rInj3SpCal5 = InjSys_rInj3Cal5_M[iRowIndex1+16*iColumnIndex1];
        }

        /* DataTypeDuplicate Block: '<S67>/Data Type Duplicate2'
         *
         * Regarding '<S67>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S29>/F06_Calibration_5_FuMass3Tmp' */

      /* Outputs for enable SubSystem: '<S29>/F07_Calibration_6_FuMass3Tmp' incorporates:
       *  EnablePort: '<S54>/Enable'
       */
      if (InjSys_bAcvRatInj3SpCal6) {
        /* Lookup2D: '<S68>/Look-Up Table (2-D)'
         * About '<S68>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Nearest
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        {
          UInt32 iRowIndex1, iColumnIndex1;
          BINARYSEARCH_U16_Near_iL( &(iRowIndex1), rInjSp_B.VEMS_vidGET10,
            (&(InjSys_nEngInjSpCal6X_A[0])), 15U);
          BINARYSEARCH_U16_Near_iL( &(iColumnIndex1), rInjSp_B.VEMS_vidGET9,
            (&(InjSys_mAirInjSpCal6Y_A[0])), 15U);
          InjSys_rInj3SpCal6 = InjSys_rInj3Cal6_M[iRowIndex1+16*iColumnIndex1];
        }

        /* DataTypeDuplicate Block: '<S68>/Data Type Duplicate2'
         *
         * Regarding '<S68>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S29>/F07_Calibration_6_FuMass3Tmp' */

      /* Outputs for enable SubSystem: '<S29>/F08_Calibration_7_FuMass3Tmp' incorporates:
       *  EnablePort: '<S55>/Enable'
       */
      if (InjSys_bAcvRatInj3SpCal7) {
        /* Lookup2D: '<S69>/Look-Up Table (2-D)'
         * About '<S69>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Nearest
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        {
          UInt32 iRowIndex1, iColumnIndex1;
          BINARYSEARCH_U16_Near_iL( &(iRowIndex1), rInjSp_B.VEMS_vidGET10,
            (&(InjSys_nEngInjSpCal7X_A[0])), 15U);
          BINARYSEARCH_U16_Near_iL( &(iColumnIndex1), rInjSp_B.VEMS_vidGET9,
            (&(InjSys_mAirInjSpCal7Y_A[0])), 15U);
          InjSys_rInj3SpCal7 = InjSys_rInj3Cal7_M[iRowIndex1+16*iColumnIndex1];
        }

        /* DataTypeDuplicate Block: '<S69>/Data Type Duplicate2'
         *
         * Regarding '<S69>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S29>/F08_Calibration_7_FuMass3Tmp' */

      /* Outputs for enable SubSystem: '<S29>/F09_Calibration_8_FuMass3Tmp' incorporates:
       *  EnablePort: '<S56>/Enable'
       */
      if (InjSys_bAcvRatInj3SpCal8) {
        /* Lookup2D: '<S70>/Look-Up Table (2-D)'
         * About '<S70>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Nearest
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        {
          UInt32 iRowIndex1, iColumnIndex1;
          BINARYSEARCH_U16_Near_iL( &(iRowIndex1), rInjSp_B.VEMS_vidGET10,
            (&(InjSys_nEngInjSpCal8X_A[0])), 15U);
          BINARYSEARCH_U16_Near_iL( &(iColumnIndex1), rInjSp_B.VEMS_vidGET9,
            (&(InjSys_mAirInjSpCal8Y_A[0])), 15U);
          InjSys_rInj3SpCal8 = InjSys_rInj3Cal8_M[iRowIndex1+16*iColumnIndex1];
        }

        /* DataTypeDuplicate Block: '<S70>/Data Type Duplicate2'
         *
         * Regarding '<S70>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S29>/F09_Calibration_8_FuMass3Tmp' */

      /* Outputs for enable SubSystem: '<S29>/F10_Calibration_9_FuMass3Tmp' incorporates:
       *  EnablePort: '<S57>/Enable'
       */
      if (InjSys_bAcvRatInj3SpCal9) {
        /* Lookup2D: '<S71>/Look-Up Table (2-D)'
         * About '<S71>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Nearest
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        {
          UInt32 iRowIndex1, iColumnIndex1;
          BINARYSEARCH_U16_Near_iL( &(iRowIndex1), rInjSp_B.VEMS_vidGET10,
            (&(InjSys_nEngInjSpCal9X_A[0])), 15U);
          BINARYSEARCH_U16_Near_iL( &(iColumnIndex1), rInjSp_B.VEMS_vidGET9,
            (&(InjSys_mAirInjSpCal9Y_A[0])), 15U);
          InjSys_rInj3SpCal9 = InjSys_rInj3Cal9_M[iRowIndex1+16*iColumnIndex1];
        }

        /* DataTypeDuplicate Block: '<S71>/Data Type Duplicate2'
         *
         * Regarding '<S71>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S29>/F10_Calibration_9_FuMass3Tmp' */

      /* Outputs for enable SubSystem: '<S29>/F11_Calibration_10_FuMass3Tmp' incorporates:
       *  EnablePort: '<S58>/Enable'
       */
      if (InjSys_bAcvRatInj3SpCal10) {
        /* Lookup2D: '<S72>/Look-Up Table (2-D)'
         * About '<S72>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Nearest
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        {
          UInt32 iRowIndex1, iColumnIndex1;
          BINARYSEARCH_U16_Near_iL( &(iRowIndex1), rInjSp_B.VEMS_vidGET10,
            (&(InjSys_nEngInjSpCal10X_A[0])), 7U);
          BINARYSEARCH_U16_Near_iL( &(iColumnIndex1), rInjSp_B.VEMS_vidGET9,
            (&(InjSys_mAirInjSpCal10Y_A[0])), 7U);
          InjSys_rInj3SpCal10 = InjSys_rInj3Cal10_M[iRowIndex1+8*iColumnIndex1];
        }

        /* DataTypeDuplicate Block: '<S72>/Data Type Duplicate2'
         *
         * Regarding '<S72>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S29>/F11_Calibration_10_FuMass3Tmp' */

      /* Outputs for enable SubSystem: '<S29>/F12_Calibration_11_FuMass3Tmp' incorporates:
       *  EnablePort: '<S59>/Enable'
       */
      if (InjSys_bAcvRatInj3SpCal11) {
        /* Lookup2D: '<S73>/Look-Up Table (2-D)'
         * About '<S73>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Nearest
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        {
          UInt32 iRowIndex1, iColumnIndex1;
          BINARYSEARCH_U16_Near_iL( &(iRowIndex1), rInjSp_B.VEMS_vidGET10,
            (&(InjSys_nEngInjSpCal11X_A[0])), 7U);
          BINARYSEARCH_U16_Near_iL( &(iColumnIndex1), rInjSp_B.VEMS_vidGET9,
            (&(InjSys_mAirInjSpCal11Y_A[0])), 7U);
          InjSys_rInj3SpCal11 = InjSys_rInj3Cal11_M[iRowIndex1+8*iColumnIndex1];
        }

        /* DataTypeDuplicate Block: '<S73>/Data Type Duplicate2'
         *
         * Regarding '<S73>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S29>/F12_Calibration_11_FuMass3Tmp' */

      /* Outputs for enable SubSystem: '<S29>/F13_Calibration_12_FuMass3Tmp' incorporates:
       *  EnablePort: '<S60>/Enable'
       */
      if (InjSys_bAcvRatInj3SpCal12) {
        /* Lookup2D: '<S74>/Look-Up Table (2-D)'
         * About '<S74>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Nearest
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        {
          UInt32 iRowIndex1, iColumnIndex1;
          BINARYSEARCH_U16_Near_iL( &(iRowIndex1), rInjSp_B.VEMS_vidGET10,
            (&(InjSys_nEngInjSpCal12X_A[0])), 7U);
          BINARYSEARCH_U16_Near_iL( &(iColumnIndex1), rInjSp_B.VEMS_vidGET9,
            (&(InjSys_mAirInjSpCal12Y_A[0])), 7U);
          InjSys_rInj3SpCal12 = InjSys_rInj3Cal12_M[iRowIndex1+8*iColumnIndex1];
        }

        /* DataTypeDuplicate Block: '<S74>/Data Type Duplicate2'
         *
         * Regarding '<S74>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S29>/F13_Calibration_12_FuMass3Tmp' */

      /* Outputs for enable SubSystem: '<S29>/F14_Calibration_13_FuMass3Tmp' incorporates:
       *  EnablePort: '<S61>/Enable'
       */
      if (InjSys_bAcvRatInj3SpCal13) {
        /* Constant: '<S61>/InjSys_rInj3SpCal13_C' */
        InjSys_rInj3SpCal13 = InjSys_rInj3SpCal13_C;
      }

      /* end of Outputs for SubSystem: '<S29>/F14_Calibration_13_FuMass3Tmp' */

      /* Outputs for atomic SubSystem: '<S29>/F20_Vectorize_Calibrations_FuMass3Tmp' */

      /* SignalConversion: '<S62>/Signal Conversion' */
      InjSys_prm_rInj3SpCal[0] = InjSys_rInj3SpCal1;
      InjSys_prm_rInj3SpCal[1] = InjSys_rInj3SpCal2;
      InjSys_prm_rInj3SpCal[2] = InjSys_rInj3SpCal3;
      InjSys_prm_rInj3SpCal[3] = InjSys_rInj3SpCal4;
      InjSys_prm_rInj3SpCal[4] = InjSys_rInj3SpCal5;
      InjSys_prm_rInj3SpCal[5] = InjSys_rInj3SpCal6;
      InjSys_prm_rInj3SpCal[6] = InjSys_rInj3SpCal7;
      InjSys_prm_rInj3SpCal[7] = InjSys_rInj3SpCal8;
      InjSys_prm_rInj3SpCal[8] = InjSys_rInj3SpCal9;
      InjSys_prm_rInj3SpCal[9] = InjSys_rInj3SpCal10;
      InjSys_prm_rInj3SpCal[10] = InjSys_rInj3SpCal11;
      InjSys_prm_rInj3SpCal[11] = InjSys_rInj3SpCal12;
      InjSys_prm_rInj3SpCal[12] = InjSys_rInj3SpCal13;

      /* end of Outputs for SubSystem: '<S29>/F20_Vectorize_Calibrations_FuMass3Tmp' */

      /* end of Outputs for SubSystem: '<S23>/F03_Calibrations_FuMass3Tmp' */

      /* Outputs for atomic SubSystem: '<S23>/F04_Select_Modes_FuMass3Tmp' */

      /* DataTypeConversion: '<S30>/Data Type Conversion' incorporates:
       *  Selector: '<S30>/Selector_cyl1'
       */
      InjSys_rInj3SpBas1ModCur = ((Float32)
        InjSys_prm_rInj3SpCal[rInjSp_B.VEMS_vidGET5 - 1]) * 3.051757813E-005F;

      /* DataTypeConversion: '<S30>/Data Type Conversion1' incorporates:
       *  Selector: '<S30>/Selector_cyl2'
       */
      InjSys_rInj3SpBas2ModCur = ((Float32)
        InjSys_prm_rInj3SpCal[rInjSp_B.VEMS_vidGET7 - 1]) * 3.051757813E-005F;

      /* DataTypeConversion: '<S30>/Data Type Conversion2' incorporates:
       *  Selector: '<S30>/Selector_cyl3'
       */
      InjSys_rInj3SpBas1ModTar = ((Float32)
        InjSys_prm_rInj3SpCal[rInjSp_B.VEMS_vidGET6 - 1]) * 3.051757813E-005F;

      /* DataTypeConversion: '<S30>/Data Type Conversion3' incorporates:
       *  Selector: '<S30>/Selector_cyl4'
       */
      InjSys_rInj3SpBas2ModTar = ((Float32)
        InjSys_prm_rInj3SpCal[rInjSp_B.VEMS_vidGET8 - 1]) * 3.051757813E-005F;

      /* end of Outputs for SubSystem: '<S23>/F04_Select_Modes_FuMass3Tmp' */

      /* Outputs for atomic SubSystem: '<S23>/F05_Interpolation_FuMass3Tmp' */

      /* Switch: '<S81>/Switch' incorporates:
       *  Constant: '<S75>/Constant1'
       *  RelationalOperator: '<S81>/UpperRelop'
       */
      localSwitch2_c = rInjSp_B.VEMS_vidGET3;

      /* Switch: '<S81>/Switch2' incorporates:
       *  Constant: '<S75>/Constant'
       *  RelationalOperator: '<S81>/LowerRelop1'
       */
      if (rInjSp_B.VEMS_vidGET3 > 128) {
        localSwitch2_c = 128U;
      }

      /* Sum: '<S75>/Sum2' incorporates:
       *  Product: '<S75>/Divide'
       *  Sum: '<S75>/Sum3'
       */
      InjSys_rInj3SpModTar_MP = ((InjSys_rInj3SpBas1ModTar -
        InjSys_rInj3SpBas2ModTar) * (((Float32)localSwitch2_c) * 0.0078125F)) +
        InjSys_rInj3SpBas2ModTar;

      /* Switch: '<S85>/Switch' incorporates:
       *  Constant: '<S76>/Constant1'
       *  RelationalOperator: '<S85>/UpperRelop'
       */
      localSwitch2_c = rInjSp_B.VEMS_vidGET2;

      /* Switch: '<S85>/Switch2' incorporates:
       *  Constant: '<S76>/Constant'
       *  RelationalOperator: '<S85>/LowerRelop1'
       */
      if (rInjSp_B.VEMS_vidGET2 > 128) {
        localSwitch2_c = 128U;
      }

      /* Sum: '<S76>/Sum2' incorporates:
       *  Product: '<S76>/Divide'
       *  Sum: '<S76>/Sum3'
       */
      InjSys_rInj3SpModCur_MP = ((InjSys_rInj3SpBas1ModCur -
        InjSys_rInj3SpBas2ModCur) * (((Float32)localSwitch2_c) * 0.0078125F)) +
        InjSys_rInj3SpBas2ModCur;

      /* Switch: '<S89>/Switch' incorporates:
       *  Constant: '<S77>/Constant1'
       *  RelationalOperator: '<S89>/UpperRelop'
       */
      localSwitch2_c = rInjSp_B.VEMS_vidGET4;

      /* Switch: '<S89>/Switch2' incorporates:
       *  Constant: '<S77>/Constant'
       *  RelationalOperator: '<S89>/LowerRelop1'
       */
      if (rInjSp_B.VEMS_vidGET4 > 128) {
        localSwitch2_c = 128U;
      }

      /* Sum: '<S77>/Sum2' incorporates:
       *  Product: '<S77>/Divide'
       *  Sum: '<S77>/Sum3'
       */
      InjSys_rInj3Tmp = ((InjSys_rInj3SpModTar_MP - InjSys_rInj3SpModCur_MP) *
                         (((Float32)localSwitch2_c) * 0.0078125F)) +
        InjSys_rInj3SpModCur_MP;

      /* end of Outputs for SubSystem: '<S23>/F05_Interpolation_FuMass3Tmp' */

      /* end of Outputs for SubSystem: '<S8>/F01_FuMass3Tmp' */

      /* Outputs for atomic SubSystem: '<S8>/F02_FuMass2Tmp' */

      /* Outputs for atomic SubSystem: '<S24>/F02_Mode_Mask_FuMass2Tmp' */

      /* SignalConversion: '<S90>/TmpSignal ConversionAtAssignmentInport1' incorporates:
       *  Constant: '<S90>/Constant'
       */
      localAssignment2_n[0] = FALSE;
      localAssignment2_n[1] = FALSE;
      localAssignment2_n[2] = FALSE;
      localAssignment2_n[3] = FALSE;
      localAssignment2_n[4] = FALSE;
      localAssignment2_n[5] = FALSE;
      localAssignment2_n[6] = FALSE;
      localAssignment2_n[7] = FALSE;
      localAssignment2_n[8] = FALSE;
      localAssignment2_n[9] = FALSE;
      localAssignment2_n[10] = FALSE;
      localAssignment2_n[11] = FALSE;
      localAssignment2_n[12] = FALSE;

      /* Switch: '<S100>/Switch' incorporates:
       *  Constant: '<S90>/InjSys_idxModRatInjSatMin_C'
       *  RelationalOperator: '<S100>/UpperRelop'
       */
      if (rInjSp_B.VEMS_vidGET5 < InjSys_idxModRatInjSatMin_C) {
        localSwitch2_c = InjSys_idxModRatInjSatMin_C;
      } else {
        localSwitch2_c = rInjSp_B.VEMS_vidGET5;
      }

      /* Switch: '<S100>/Switch2' incorporates:
       *  Constant: '<S90>/InjSys_idxModRatInjSatMax_C'
       *  RelationalOperator: '<S100>/LowerRelop1'
       */
      if (rInjSp_B.VEMS_vidGET5 > InjSys_idxModRatInjSatMax_C) {
        localSwitch2_c = InjSys_idxModRatInjSatMax_C;
      }

      /* Assignment: '<S90>/Assignment' incorporates:
       *  Constant: '<S90>/Constant1'
       */
      localAssignment2_n[localSwitch2_c - 1] = TRUE;

      /* Switch: '<S103>/Switch' incorporates:
       *  Constant: '<S90>/InjSys_idxModRatInjSatMin_C1'
       *  RelationalOperator: '<S103>/UpperRelop'
       */
      if (rInjSp_B.VEMS_vidGET7 < InjSys_idxModRatInjSatMin_C) {
        localSwitch2_c = InjSys_idxModRatInjSatMin_C;
      } else {
        localSwitch2_c = rInjSp_B.VEMS_vidGET7;
      }

      /* Switch: '<S103>/Switch2' incorporates:
       *  Constant: '<S90>/InjSys_idxModRatInjSatMax_C1'
       *  RelationalOperator: '<S103>/LowerRelop1'
       */
      if (rInjSp_B.VEMS_vidGET7 > InjSys_idxModRatInjSatMax_C) {
        localSwitch2_c = InjSys_idxModRatInjSatMax_C;
      }

      /* Assignment: '<S90>/Assignment1' incorporates:
       *  Constant: '<S90>/Constant2'
       */
      localAssignment2_n[localSwitch2_c - 1] = TRUE;

      /* Switch: '<S106>/Switch' incorporates:
       *  Constant: '<S90>/InjSys_idxModRatInjSatMin_C2'
       *  RelationalOperator: '<S106>/UpperRelop'
       */
      if (rInjSp_B.VEMS_vidGET6 < InjSys_idxModRatInjSatMin_C) {
        localSwitch2_c = InjSys_idxModRatInjSatMin_C;
      } else {
        localSwitch2_c = rInjSp_B.VEMS_vidGET6;
      }

      /* Switch: '<S106>/Switch2' incorporates:
       *  Constant: '<S90>/InjSys_idxModRatInjSatMax_C2'
       *  RelationalOperator: '<S106>/LowerRelop1'
       */
      if (rInjSp_B.VEMS_vidGET6 > InjSys_idxModRatInjSatMax_C) {
        localSwitch2_c = InjSys_idxModRatInjSatMax_C;
      }

      /* Assignment: '<S90>/Assignment2' incorporates:
       *  Constant: '<S90>/Constant3'
       */
      localAssignment2_n[localSwitch2_c - 1] = TRUE;

      /* Switch: '<S109>/Switch' incorporates:
       *  Constant: '<S90>/InjSys_idxModRatInjSatMin_C3'
       *  RelationalOperator: '<S109>/UpperRelop'
       */
      if (rInjSp_B.VEMS_vidGET8 < InjSys_idxModRatInjSatMin_C) {
        localSwitch2_c = InjSys_idxModRatInjSatMin_C;
      } else {
        localSwitch2_c = rInjSp_B.VEMS_vidGET8;
      }

      /* Switch: '<S109>/Switch2' incorporates:
       *  Constant: '<S90>/InjSys_idxModRatInjSatMax_C3'
       *  RelationalOperator: '<S109>/LowerRelop1'
       */
      if (rInjSp_B.VEMS_vidGET8 > InjSys_idxModRatInjSatMax_C) {
        localSwitch2_c = InjSys_idxModRatInjSatMax_C;
      }

      /* Assignment: '<S90>/Assignment3' incorporates:
       *  Constant: '<S90>/Constant4'
       */
      for (locali = 0; locali < 13; locali++) {
        InjSys_prm_bAcvRatInj2SpCal[(locali)] = localAssignment2_n[locali];
      }

      InjSys_prm_bAcvRatInj2SpCal[localSwitch2_c - 1] = TRUE;

      /* end of Outputs for SubSystem: '<S24>/F02_Mode_Mask_FuMass2Tmp' */

      /* Outputs for atomic SubSystem: '<S24>/F03_Calibrations_FuMass2Tmp' */

      /* Outputs for atomic SubSystem: '<S91>/F01_Unvectorize_Activation_Boolean_FuMass2Tmp' */

      /* SignalConversion: '<S110>/Signal Conversion' */
      InjSys_bAcvRatInj2SpCal1 = InjSys_prm_bAcvRatInj2SpCal[0];

      /* SignalConversion: '<S110>/Signal Conversion1' */
      InjSys_bAcvRatInj2SpCal2 = InjSys_prm_bAcvRatInj2SpCal[1];

      /* SignalConversion: '<S110>/Signal Conversion10' */
      InjSys_bAcvRatInj2SpCal11 = InjSys_prm_bAcvRatInj2SpCal[10];

      /* SignalConversion: '<S110>/Signal Conversion11' */
      InjSys_bAcvRatInj2SpCal12 = InjSys_prm_bAcvRatInj2SpCal[11];

      /* SignalConversion: '<S110>/Signal Conversion12' */
      InjSys_bAcvRatInj2SpCal13 = InjSys_prm_bAcvRatInj2SpCal[12];

      /* SignalConversion: '<S110>/Signal Conversion2' */
      InjSys_bAcvRatInj2SpCal3 = InjSys_prm_bAcvRatInj2SpCal[2];

      /* SignalConversion: '<S110>/Signal Conversion3' */
      InjSys_bAcvRatInj2SpCal4 = InjSys_prm_bAcvRatInj2SpCal[3];

      /* SignalConversion: '<S110>/Signal Conversion4' */
      InjSys_bAcvRatInj2SpCal5 = InjSys_prm_bAcvRatInj2SpCal[4];

      /* SignalConversion: '<S110>/Signal Conversion5' */
      InjSys_bAcvRatInj2SpCal6 = InjSys_prm_bAcvRatInj2SpCal[5];

      /* SignalConversion: '<S110>/Signal Conversion6' */
      InjSys_bAcvRatInj2SpCal7 = InjSys_prm_bAcvRatInj2SpCal[6];

      /* SignalConversion: '<S110>/Signal Conversion7' */
      InjSys_bAcvRatInj2SpCal8 = InjSys_prm_bAcvRatInj2SpCal[7];

      /* SignalConversion: '<S110>/Signal Conversion8' */
      InjSys_bAcvRatInj2SpCal9 = InjSys_prm_bAcvRatInj2SpCal[8];

      /* SignalConversion: '<S110>/Signal Conversion9' */
      InjSys_bAcvRatInj2SpCal10 = InjSys_prm_bAcvRatInj2SpCal[9];

      /* end of Outputs for SubSystem: '<S91>/F01_Unvectorize_Activation_Boolean_FuMass2Tmp' */

      /* Outputs for enable SubSystem: '<S91>/F02_Calibration_1_FuMass2Tmp' incorporates:
       *  EnablePort: '<S111>/Enable'
       */
      if (InjSys_bAcvRatInj2SpCal1) {
        /* Lookup2D: '<S125>/Look-Up Table (2-D)'
         * About '<S125>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Nearest
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        {
          UInt32 iRowIndex1, iColumnIndex1;
          BINARYSEARCH_U16_Near_iL( &(iRowIndex1), rInjSp_B.VEMS_vidGET10,
            (&(InjSys_nEngInjSpCal1X_A[0])), 15U);
          BINARYSEARCH_U16_Near_iL( &(iColumnIndex1), rInjSp_B.VEMS_vidGET9,
            (&(InjSys_mAirInjSpCal1Y_A[0])), 15U);
          InjSys_rInj2SpCal1 = InjSys_rInj2Cal1_M[iRowIndex1+16*iColumnIndex1];
        }

        /* DataTypeDuplicate Block: '<S125>/Data Type Duplicate2'
         *
         * Regarding '<S125>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S91>/F02_Calibration_1_FuMass2Tmp' */

      /* Outputs for enable SubSystem: '<S91>/F03_Calibration_2_FuMass2Tmp' incorporates:
       *  EnablePort: '<S112>/Enable'
       */
      if (InjSys_bAcvRatInj2SpCal2) {
        /* Lookup2D: '<S126>/Look-Up Table (2-D)'
         * About '<S126>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Nearest
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        {
          UInt32 iRowIndex1, iColumnIndex1;
          BINARYSEARCH_U16_Near_iL( &(iRowIndex1), rInjSp_B.VEMS_vidGET10,
            (&(InjSys_nEngInjSpCal2X_A[0])), 15U);
          BINARYSEARCH_U16_Near_iL( &(iColumnIndex1), rInjSp_B.VEMS_vidGET9,
            (&(InjSys_mAirInjSpCal2Y_A[0])), 15U);
          InjSys_rInj2SpCal2 = InjSys_rInj2Cal2_M[iRowIndex1+16*iColumnIndex1];
        }

        /* DataTypeDuplicate Block: '<S126>/Data Type Duplicate2'
         *
         * Regarding '<S126>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S91>/F03_Calibration_2_FuMass2Tmp' */

      /* Outputs for enable SubSystem: '<S91>/F04_Calibration_3_FuMass2Tmp' incorporates:
       *  EnablePort: '<S113>/Enable'
       */
      if (InjSys_bAcvRatInj2SpCal3) {
        /* Lookup2D: '<S127>/Look-Up Table (2-D)'
         * About '<S127>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Nearest
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        {
          UInt32 iRowIndex1, iColumnIndex1;
          BINARYSEARCH_U16_Near_iL( &(iRowIndex1), rInjSp_B.VEMS_vidGET10,
            (&(InjSys_nEngInjSpCal3X_A[0])), 15U);
          BINARYSEARCH_U16_Near_iL( &(iColumnIndex1), rInjSp_B.VEMS_vidGET9,
            (&(InjSys_mAirInjSpCal3Y_A[0])), 15U);
          InjSys_rInj2SpCal3 = InjSys_rInj2Cal3_M[iRowIndex1+16*iColumnIndex1];
        }

        /* DataTypeDuplicate Block: '<S127>/Data Type Duplicate2'
         *
         * Regarding '<S127>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S91>/F04_Calibration_3_FuMass2Tmp' */

      /* Outputs for enable SubSystem: '<S91>/F05_Calibration_4_FuMass2Tmp' incorporates:
       *  EnablePort: '<S114>/Enable'
       */
      if (InjSys_bAcvRatInj2SpCal4) {
        /* Lookup2D: '<S128>/Look-Up Table (2-D)'
         * About '<S128>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Nearest
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        {
          UInt32 iRowIndex1, iColumnIndex1;
          BINARYSEARCH_U16_Near_iL( &(iRowIndex1), rInjSp_B.VEMS_vidGET10,
            (&(InjSys_nEngInjSpCal4X_A[0])), 15U);
          BINARYSEARCH_U16_Near_iL( &(iColumnIndex1), rInjSp_B.VEMS_vidGET9,
            (&(InjSys_mAirInjSpCal4Y_A[0])), 15U);
          InjSys_rInj2SpCal4 = InjSys_rInj2Cal4_M[iRowIndex1+16*iColumnIndex1];
        }

        /* DataTypeDuplicate Block: '<S128>/Data Type Duplicate2'
         *
         * Regarding '<S128>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S91>/F05_Calibration_4_FuMass2Tmp' */

      /* Outputs for enable SubSystem: '<S91>/F06_Calibration_5_FuMass2Tmp' incorporates:
       *  EnablePort: '<S115>/Enable'
       */
      if (InjSys_bAcvRatInj2SpCal5) {
        /* Lookup2D: '<S129>/Look-Up Table (2-D)'
         * About '<S129>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Nearest
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        {
          UInt32 iRowIndex1, iColumnIndex1;
          BINARYSEARCH_U16_Near_iL( &(iRowIndex1), rInjSp_B.VEMS_vidGET10,
            (&(InjSys_nEngInjSpCal5X_A[0])), 15U);
          BINARYSEARCH_U16_Near_iL( &(iColumnIndex1), rInjSp_B.VEMS_vidGET9,
            (&(InjSys_mAirInjSpCal5Y_A[0])), 15U);
          InjSys_rInj2SpCal5 = InjSys_rInj2Cal5_M[iRowIndex1+16*iColumnIndex1];
        }

        /* DataTypeDuplicate Block: '<S129>/Data Type Duplicate2'
         *
         * Regarding '<S129>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S91>/F06_Calibration_5_FuMass2Tmp' */

      /* Outputs for enable SubSystem: '<S91>/F07_Calibration_6_FuMass2Tmp' incorporates:
       *  EnablePort: '<S116>/Enable'
       */
      if (InjSys_bAcvRatInj2SpCal6) {
        /* Lookup2D: '<S130>/Look-Up Table (2-D)'
         * About '<S130>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Nearest
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        {
          UInt32 iRowIndex1, iColumnIndex1;
          BINARYSEARCH_U16_Near_iL( &(iRowIndex1), rInjSp_B.VEMS_vidGET10,
            (&(InjSys_nEngInjSpCal6X_A[0])), 15U);
          BINARYSEARCH_U16_Near_iL( &(iColumnIndex1), rInjSp_B.VEMS_vidGET9,
            (&(InjSys_mAirInjSpCal6Y_A[0])), 15U);
          InjSys_rInj2SpCal6 = InjSys_rInj2Cal6_M[iRowIndex1+16*iColumnIndex1];
        }

        /* DataTypeDuplicate Block: '<S130>/Data Type Duplicate2'
         *
         * Regarding '<S130>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S91>/F07_Calibration_6_FuMass2Tmp' */

      /* Outputs for enable SubSystem: '<S91>/F08_Calibration_7_FuMass2Tmp' incorporates:
       *  EnablePort: '<S117>/Enable'
       */
      if (InjSys_bAcvRatInj2SpCal7) {
        /* Lookup2D: '<S131>/Look-Up Table (2-D)'
         * About '<S131>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Nearest
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        {
          UInt32 iRowIndex1, iColumnIndex1;
          BINARYSEARCH_U16_Near_iL( &(iRowIndex1), rInjSp_B.VEMS_vidGET10,
            (&(InjSys_nEngInjSpCal7X_A[0])), 15U);
          BINARYSEARCH_U16_Near_iL( &(iColumnIndex1), rInjSp_B.VEMS_vidGET9,
            (&(InjSys_mAirInjSpCal7Y_A[0])), 15U);
          InjSys_rInj2SpCal7 = InjSys_rInj2Cal7_M[iRowIndex1+16*iColumnIndex1];
        }

        /* DataTypeDuplicate Block: '<S131>/Data Type Duplicate2'
         *
         * Regarding '<S131>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S91>/F08_Calibration_7_FuMass2Tmp' */

      /* Outputs for enable SubSystem: '<S91>/F09_Calibration_8_FuMass2Tmp' incorporates:
       *  EnablePort: '<S118>/Enable'
       */
      if (InjSys_bAcvRatInj2SpCal8) {
        /* Lookup2D: '<S132>/Look-Up Table (2-D)'
         * About '<S132>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Nearest
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        {
          UInt32 iRowIndex1, iColumnIndex1;
          BINARYSEARCH_U16_Near_iL( &(iRowIndex1), rInjSp_B.VEMS_vidGET10,
            (&(InjSys_nEngInjSpCal8X_A[0])), 15U);
          BINARYSEARCH_U16_Near_iL( &(iColumnIndex1), rInjSp_B.VEMS_vidGET9,
            (&(InjSys_mAirInjSpCal8Y_A[0])), 15U);
          InjSys_rInj2SpCal8 = InjSys_rInj2Cal8_M[iRowIndex1+16*iColumnIndex1];
        }

        /* DataTypeDuplicate Block: '<S132>/Data Type Duplicate2'
         *
         * Regarding '<S132>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S91>/F09_Calibration_8_FuMass2Tmp' */

      /* Outputs for enable SubSystem: '<S91>/F10_Calibration_9_FuMass2Tmp' incorporates:
       *  EnablePort: '<S119>/Enable'
       */
      if (InjSys_bAcvRatInj2SpCal9) {
        /* Lookup2D: '<S133>/Look-Up Table (2-D)'
         * About '<S133>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Nearest
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        {
          UInt32 iRowIndex1, iColumnIndex1;
          BINARYSEARCH_U16_Near_iL( &(iRowIndex1), rInjSp_B.VEMS_vidGET10,
            (&(InjSys_nEngInjSpCal9X_A[0])), 15U);
          BINARYSEARCH_U16_Near_iL( &(iColumnIndex1), rInjSp_B.VEMS_vidGET9,
            (&(InjSys_mAirInjSpCal9Y_A[0])), 15U);
          InjSys_rInj2SpCal9 = InjSys_rInj2Cal9_M[iRowIndex1+16*iColumnIndex1];
        }

        /* DataTypeDuplicate Block: '<S133>/Data Type Duplicate2'
         *
         * Regarding '<S133>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S91>/F10_Calibration_9_FuMass2Tmp' */

      /* Outputs for enable SubSystem: '<S91>/F11_Calibration_10_FuMass2Tmp' incorporates:
       *  EnablePort: '<S120>/Enable'
       */
      if (InjSys_bAcvRatInj2SpCal10) {
        /* Lookup2D: '<S134>/Look-Up Table (2-D)'
         * About '<S134>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Nearest
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        {
          UInt32 iRowIndex1, iColumnIndex1;
          BINARYSEARCH_U16_Near_iL( &(iRowIndex1), rInjSp_B.VEMS_vidGET10,
            (&(InjSys_nEngInjSpCal10X_A[0])), 7U);
          BINARYSEARCH_U16_Near_iL( &(iColumnIndex1), rInjSp_B.VEMS_vidGET9,
            (&(InjSys_mAirInjSpCal10Y_A[0])), 7U);
          InjSys_rInj2SpCal10 = InjSys_rInj2Cal10_M[iRowIndex1+8*iColumnIndex1];
        }

        /* DataTypeDuplicate Block: '<S134>/Data Type Duplicate2'
         *
         * Regarding '<S134>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S91>/F11_Calibration_10_FuMass2Tmp' */

      /* Outputs for enable SubSystem: '<S91>/F12_Calibration_11_FuMass2Tmp' incorporates:
       *  EnablePort: '<S121>/Enable'
       */
      if (InjSys_bAcvRatInj2SpCal11) {
        /* Lookup2D: '<S135>/Look-Up Table (2-D)'
         * About '<S135>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Nearest
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        {
          UInt32 iRowIndex1, iColumnIndex1;
          BINARYSEARCH_U16_Near_iL( &(iRowIndex1), rInjSp_B.VEMS_vidGET10,
            (&(InjSys_nEngInjSpCal11X_A[0])), 7U);
          BINARYSEARCH_U16_Near_iL( &(iColumnIndex1), rInjSp_B.VEMS_vidGET9,
            (&(InjSys_mAirInjSpCal11Y_A[0])), 7U);
          InjSys_rInj2SpCal11 = InjSys_rInj2Cal11_M[iRowIndex1+8*iColumnIndex1];
        }

        /* DataTypeDuplicate Block: '<S135>/Data Type Duplicate2'
         *
         * Regarding '<S135>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S91>/F12_Calibration_11_FuMass2Tmp' */

      /* Outputs for enable SubSystem: '<S91>/F13_Calibration_12_FuMass2Tmp' incorporates:
       *  EnablePort: '<S122>/Enable'
       */
      if (InjSys_bAcvRatInj2SpCal12) {
        /* Lookup2D: '<S136>/Look-Up Table (2-D)'
         * About '<S136>/Look-Up Table (2-D)':
         * Input0  Data Type:  Integer        U16
         * Input1  Data Type:  Fixed Point    U16  2^-24  FSlope 1.999872
         * Output0 Data Type:  Fixed Point    U16  2^-15
         * Lookup Method: Nearest
         *
         * Row Data    parameter uses the same data type and scaling as Input0
         * Column Data parameter uses the same data type and scaling as Input1
         * Table Data  parameter uses the same data type and scaling as Output0
         */
        {
          UInt32 iRowIndex1, iColumnIndex1;
          BINARYSEARCH_U16_Near_iL( &(iRowIndex1), rInjSp_B.VEMS_vidGET10,
            (&(InjSys_nEngInjSpCal12X_A[0])), 7U);
          BINARYSEARCH_U16_Near_iL( &(iColumnIndex1), rInjSp_B.VEMS_vidGET9,
            (&(InjSys_mAirInjSpCal12Y_A[0])), 7U);
          InjSys_rInj2SpCal12 = InjSys_rInj2Cal12_M[iRowIndex1+8*iColumnIndex1];
        }

        /* DataTypeDuplicate Block: '<S136>/Data Type Duplicate2'
         *
         * Regarding '<S136>/Data Type Duplicate2':
         *   Unused code path elimination
         */
      }

      /* end of Outputs for SubSystem: '<S91>/F13_Calibration_12_FuMass2Tmp' */

      /* Outputs for enable SubSystem: '<S91>/F14_Calibration_13_FuMass2Tmp' incorporates:
       *  EnablePort: '<S123>/Enable'
       */
      if (InjSys_bAcvRatInj2SpCal13) {
        /* Constant: '<S123>/InjSys_rInj2SpCal13_C' */
        InjSys_rInj2SpCal13 = InjSys_rInj2SpCal13_C;
      }

      /* end of Outputs for SubSystem: '<S91>/F14_Calibration_13_FuMass2Tmp' */

      /* Outputs for atomic SubSystem: '<S91>/F20_Vectorize_Calibrations_FuMass2Tmp' */

      /* SignalConversion: '<S124>/Signal Conversion' */
      InjSys_prm_rInj2SpCal[0] = InjSys_rInj2SpCal1;
      InjSys_prm_rInj2SpCal[1] = InjSys_rInj2SpCal2;
      InjSys_prm_rInj2SpCal[2] = InjSys_rInj2SpCal3;
      InjSys_prm_rInj2SpCal[3] = InjSys_rInj2SpCal4;
      InjSys_prm_rInj2SpCal[4] = InjSys_rInj2SpCal5;
      InjSys_prm_rInj2SpCal[5] = InjSys_rInj2SpCal6;
      InjSys_prm_rInj2SpCal[6] = InjSys_rInj2SpCal7;
      InjSys_prm_rInj2SpCal[7] = InjSys_rInj2SpCal8;
      InjSys_prm_rInj2SpCal[8] = InjSys_rInj2SpCal9;
      InjSys_prm_rInj2SpCal[9] = InjSys_rInj2SpCal10;
      InjSys_prm_rInj2SpCal[10] = InjSys_rInj2SpCal11;
      InjSys_prm_rInj2SpCal[11] = InjSys_rInj2SpCal12;
      InjSys_prm_rInj2SpCal[12] = InjSys_rInj2SpCal13;

      /* end of Outputs for SubSystem: '<S91>/F20_Vectorize_Calibrations_FuMass2Tmp' */

      /* end of Outputs for SubSystem: '<S24>/F03_Calibrations_FuMass2Tmp' */

      /* Outputs for atomic SubSystem: '<S24>/F04_Select_Modes_FuMass2Tmp' */

      /* DataTypeConversion: '<S92>/Data Type Conversion' incorporates:
       *  Selector: '<S92>/Selector_cyl1'
       */
      InjSys_rInj2SpBas1ModCur = ((Float32)
        InjSys_prm_rInj2SpCal[rInjSp_B.VEMS_vidGET5 - 1]) * 3.051757813E-005F;

      /* DataTypeConversion: '<S92>/Data Type Conversion1' incorporates:
       *  Selector: '<S92>/Selector_cyl2'
       */
      InjSys_rInj2SpBas2ModCur = ((Float32)
        InjSys_prm_rInj2SpCal[rInjSp_B.VEMS_vidGET7 - 1]) * 3.051757813E-005F;

      /* DataTypeConversion: '<S92>/Data Type Conversion2' incorporates:
       *  Selector: '<S92>/Selector_cyl3'
       */
      InjSys_rInj2SpBas1ModTar = ((Float32)
        InjSys_prm_rInj2SpCal[rInjSp_B.VEMS_vidGET6 - 1]) * 3.051757813E-005F;

      /* DataTypeConversion: '<S92>/Data Type Conversion3' incorporates:
       *  Selector: '<S92>/Selector_cyl4'
       */
      InjSys_rInj2SpBas2ModTar = ((Float32)
        InjSys_prm_rInj2SpCal[rInjSp_B.VEMS_vidGET8 - 1]) * 3.051757813E-005F;

      /* end of Outputs for SubSystem: '<S24>/F04_Select_Modes_FuMass2Tmp' */

      /* Outputs for atomic SubSystem: '<S24>/F05_Interpolation_FuMass2Tmp' */

      /* Switch: '<S143>/Switch' incorporates:
       *  Constant: '<S137>/Constant1'
       *  RelationalOperator: '<S143>/UpperRelop'
       */
      localSwitch2_c = rInjSp_B.VEMS_vidGET2;

      /* Switch: '<S143>/Switch2' incorporates:
       *  Constant: '<S137>/Constant'
       *  RelationalOperator: '<S143>/LowerRelop1'
       */
      if (rInjSp_B.VEMS_vidGET2 > 128) {
        localSwitch2_c = 128U;
      }

      /* Sum: '<S137>/Sum2' incorporates:
       *  Product: '<S137>/Divide'
       *  Sum: '<S137>/Sum3'
       */
      InjSys_rInj2SpModCur_MP = ((InjSys_rInj2SpBas1ModCur -
        InjSys_rInj2SpBas2ModCur) * (((Float32)localSwitch2_c) * 0.0078125F)) +
        InjSys_rInj2SpBas2ModCur;

      /* Switch: '<S147>/Switch' incorporates:
       *  Constant: '<S138>/Constant1'
       *  RelationalOperator: '<S147>/UpperRelop'
       */
      localSwitch2_c = rInjSp_B.VEMS_vidGET3;

      /* Switch: '<S147>/Switch2' incorporates:
       *  Constant: '<S138>/Constant'
       *  RelationalOperator: '<S147>/LowerRelop1'
       */
      if (rInjSp_B.VEMS_vidGET3 > 128) {
        localSwitch2_c = 128U;
      }

      /* Sum: '<S138>/Sum2' incorporates:
       *  Product: '<S138>/Divide'
       *  Sum: '<S138>/Sum3'
       */
      InjSys_rInj2SpModTar_MP = ((InjSys_rInj2SpBas1ModTar -
        InjSys_rInj2SpBas2ModTar) * (((Float32)localSwitch2_c) * 0.0078125F)) +
        InjSys_rInj2SpBas2ModTar;

      /* Switch: '<S151>/Switch' incorporates:
       *  Constant: '<S139>/Constant1'
       *  RelationalOperator: '<S151>/UpperRelop'
       */
      localSwitch2_c = rInjSp_B.VEMS_vidGET4;

      /* Switch: '<S151>/Switch2' incorporates:
       *  Constant: '<S139>/Constant'
       *  RelationalOperator: '<S151>/LowerRelop1'
       */
      if (rInjSp_B.VEMS_vidGET4 > 128) {
        localSwitch2_c = 128U;
      }

      /* Sum: '<S139>/Sum2' incorporates:
       *  Product: '<S139>/Divide'
       *  Sum: '<S139>/Sum3'
       */
      InjSys_rInj2Tmp = ((InjSys_rInj2SpModTar_MP - InjSys_rInj2SpModCur_MP) *
                         (((Float32)localSwitch2_c) * 0.0078125F)) +
        InjSys_rInj2SpModCur_MP;

      /* end of Outputs for SubSystem: '<S24>/F05_Interpolation_FuMass2Tmp' */

      /* end of Outputs for SubSystem: '<S8>/F02_FuMass2Tmp' */

      /* Outputs for atomic SubSystem: '<S8>/F03_SatInj' */

      /* Switch: '<S162>/Switch' incorporates:
       *  Constant: '<S25>/InjSys_facGainPresDsThrMesETB_C3'
       *  RelationalOperator: '<S162>/UpperRelop'
       */
      if (InjSys_rInj3Tmp < 0.0F) {
        localSwitch2 = 0.0F;
      } else {
        localSwitch2 = InjSys_rInj3Tmp;
      }

      /* Switch: '<S162>/Switch2' incorporates:
       *  Constant: '<S25>/InjSys_facGainPresDsThrMesETB_C5'
       *  RelationalOperator: '<S162>/LowerRelop1'
       */
      if (InjSys_rInj3Tmp > 1.0F) {
        localSwitch2 = 1.0F;
      }

      /* Sum: '<S25>/Add1' incorporates:
       *  Constant: '<S25>/InjSys_facGainPresDsThrMesETB_C2'
       */
      localSwitch2_k = 1.0F - localSwitch2;

      /* Switch: '<S159>/Switch' incorporates:
       *  Constant: '<S25>/InjSys_facGainPresDsThrMesETB_C4'
       *  RelationalOperator: '<S159>/UpperRelop'
       */
      if (InjSys_rInj2Tmp < 0.0F) {
        localAdd2_p = 0.0F;
      } else {
        localAdd2_p = InjSys_rInj2Tmp;
      }

      /* Switch: '<S159>/Switch2' incorporates:
       *  RelationalOperator: '<S159>/LowerRelop1'
       */
      if (!(InjSys_rInj2Tmp > localSwitch2_k)) {
        localSwitch2_k = localAdd2_p;
      }

      /* DataTypeConversion: '<S154>/OutDTConv' incorporates:
       *  Constant: '<S154>/offset'
       *  Constant: '<S154>/offset1'
       *  Constant: '<S154>/one_on_slope'
       *  Product: '<S154>/Product4'
       *  Sum: '<S154>/Add1'
       *  Sum: '<S154>/Add2'
       */
      localtmp = (32768.0F * localSwitch2_k) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          InjSys_rInj2TmpSat = (UInt16)localtmp;
        } else {
          InjSys_rInj2TmpSat = 0U;
        }
      } else {
        InjSys_rInj2TmpSat = MAX_uint16_T;
      }

      /* DataTypeConversion: '<S155>/OutDTConv' incorporates:
       *  Constant: '<S155>/offset'
       *  Constant: '<S155>/offset1'
       *  Constant: '<S155>/one_on_slope'
       *  Constant: '<S25>/InjSys_facGainPresDsThrMesETB_C1'
       *  Product: '<S155>/Product4'
       *  Sum: '<S155>/Add1'
       *  Sum: '<S155>/Add2'
       *  Sum: '<S25>/Add2'
       */
      localtmp = (((1.0F - localSwitch2_k) - localSwitch2) * 32768.0F) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          InjSys_rInj1TmpSat = (UInt16)localtmp;
        } else {
          InjSys_rInj1TmpSat = 0U;
        }
      } else {
        InjSys_rInj1TmpSat = MAX_uint16_T;
      }

      /* DataTypeConversion: '<S156>/OutDTConv' incorporates:
       *  Constant: '<S156>/offset'
       *  Constant: '<S156>/offset1'
       *  Constant: '<S156>/one_on_slope'
       *  Product: '<S156>/Product4'
       *  Sum: '<S156>/Add1'
       *  Sum: '<S156>/Add2'
       */
      localtmp = (32768.0F * localSwitch2) + 0.5F;
      if (localtmp < 65536.0F) {
        if (localtmp >= 0.0F) {
          InjSys_rInj3TmpSat = (UInt16)localtmp;
        } else {
          InjSys_rInj3TmpSat = 0U;
        }
      } else {
        InjSys_rInj3TmpSat = MAX_uint16_T;
      }

      /* end of Outputs for SubSystem: '<S8>/F03_SatInj' */

      /* Outputs for atomic SubSystem: '<S8>/F04_InjPat' */

      /* RelationalOperator: '<S26>/Relational Operator3' incorporates:
       *  Constant: '<S26>/Constant4'
       */
      localRelationalOperator3 = (InjSys_rInj2TmpSat > 0);

      /* RelationalOperator: '<S26>/Relational Operator4' incorporates:
       *  Constant: '<S26>/Constant5'
       */
      localRelationalOperator4 = (InjSys_rInj3TmpSat > 0);

      /* Logic: '<S26>/Logical Operator9' incorporates:
       *  Logic: '<S26>/Logical Operator10'
       */
      InjSys_bTestInjPat2_MP = ((!localRelationalOperator3) &&
        (localRelationalOperator4));

      /* Switch: '<S26>/Switch' incorporates:
       *  Constant: '<S26>/InjSys_facGainPresDsThrMesETB_C1'
       *  Constant: '<S26>/InjSys_facGainPresDsThrMesETB_C4'
       */
      if (localRelationalOperator3) {
        InjSys_noInjPatTmp1_MP = 1U;
      } else {
        InjSys_noInjPatTmp1_MP = 0U;
      }

      /* Switch: '<S26>/Switch1' incorporates:
       *  Constant: '<S26>/Constant8'
       */
      if (localRelationalOperator4) {
        InjSys_noInjPatTmp2_MP = 3U;
      } else {
        InjSys_noInjPatTmp2_MP = InjSys_noInjPatTmp1_MP;
      }

      /* Switch: '<S26>/Switch2' incorporates:
       *  Constant: '<S26>/Constant9'
       */
      if (InjSys_bTestInjPat2_MP) {
        localSwitch2_c = 2U;
      } else {
        localSwitch2_c = InjSys_noInjPatTmp2_MP;
      }

      /* RelationalOperator: '<S26>/Relational Operator' incorporates:
       *  Constant: '<S26>/Constant'
       */
      localRelationalOperator3 = (localSwitch2_c == 0);

      /* RelationalOperator: '<S26>/Relational Operator1' incorporates:
       *  Constant: '<S26>/Constant1'
       */
      rInjSp_B.Merge5 = (localSwitch2_c == 1);

      /* RelationalOperator: '<S26>/Relational Operator2' incorporates:
       *  Constant: '<S26>/Constant2'
       */
      rInjSp_B.Merge6 = (localSwitch2_c == 2);

      /* RelationalOperator: '<S26>/Relational Operator5' incorporates:
       *  Constant: '<S26>/Constant3'
       */
      localRelationalOperator4 = (localSwitch2_c == 3);

      /* end of Outputs for SubSystem: '<S8>/F04_InjPat' */

      /* Outputs for atomic SubSystem: '<S8>/F05_FuMass' */

      /* RelationalOperator: '<S27>/Relational Operator' incorporates:
       *  Constant: '<S27>/InjSys_rInjM1Min_C'
       */
      InjSys_bInj1Acv = (InjSys_rInj1TmpSat > InjSys_rInjM1Min_C);

      /* Logic: '<S27>/Logical Operator2' incorporates:
       *  Constant: '<S27>/Constant6'
       *  Logic: '<S27>/Logical Operator1'
       *  RelationalOperator: '<S27>/Relational Operator1'
       */
      InjSys_bAcvRatInj31_MP = ((!InjSys_bInj1Acv) && (InjSys_rInj3TmpSat != 0));

      /* Logic: '<S27>/Logical Operator3' incorporates:
       *  Constant: '<S27>/Constant7'
       *  Logic: '<S27>/Logical Operator4'
       *  RelationalOperator: '<S27>/Relational Operator2'
       */
      InjSys_bAcvRatInj21_MP = ((!InjSys_bInj1Acv) && (InjSys_rInj2TmpSat != 0));

      /* Switch: '<S27>/Switch3' incorporates:
       *  Constant: '<S27>/Constant10'
       *  Constant: '<S27>/Constant9'
       */
      if (localRelationalOperator4) {
        localSwitch3 = 100U;
      } else {
        localSwitch3 = 0U;
      }

      /* Sum: '<S27>/Sum1' incorporates:
       *  Constant: '<S27>/Constant8'
       */
      InjSys_facInjRemain = (UInt8)(100 + localSwitch3);

      /* Sum: '<S27>/Sum2' incorporates:
       *  Product: '<S165>/Divide'
       */
      InjSys_rInj31Tmp_MP = ((Float32)(ACTEMS_LdexpF((Float32d)InjSys_rInj1TmpSat,
        -15) / (((Float32d)InjSys_facInjRemain) * 0.01))) + (((Float32)
        InjSys_rInj3TmpSat) * 3.051757813E-005F);

      /* Sum: '<S27>/Sum3' incorporates:
       *  Product: '<S166>/Divide'
       */
      InjSys_rInj21Tmp_MP = ((Float32)(ACTEMS_LdexpF((Float32d)InjSys_rInj1TmpSat,
        -15) / (((Float32d)InjSys_facInjRemain) * 0.01))) + (((Float32)
        InjSys_rInj2TmpSat) * 3.051757813E-005F);

      /* Switch: '<S27>/Switch' incorporates:
       *  Constant: '<S27>/Constant2'
       */
      if (InjSys_bInj1Acv) {
        localSwitch = InjSys_rInj1TmpSat;
      } else {
        localSwitch = 0U;
      }

      /* Switch: '<S27>/Switch1' incorporates:
       *  Constant: '<S164>/offset'
       *  Constant: '<S164>/offset1'
       *  Constant: '<S164>/one_on_slope'
       *  DataTypeConversion: '<S164>/OutDTConv'
       *  Product: '<S164>/Product4'
       *  Sum: '<S164>/Add1'
       *  Sum: '<S164>/Add2'
       */
      if (InjSys_bAcvRatInj21_MP) {
        localtmp = (32768.0F * InjSys_rInj21Tmp_MP) + 0.5F;
        if (localtmp < 65536.0F) {
          if (localtmp >= 0.0F) {
            rInjSp_B.Merge1 = (UInt16)localtmp;
          } else {
            rInjSp_B.Merge1 = 0U;
          }
        } else {
          rInjSp_B.Merge1 = MAX_uint16_T;
        }
      } else {
        rInjSp_B.Merge1 = InjSys_rInj2TmpSat;
      }

      /* Switch: '<S27>/Switch2' incorporates:
       *  Constant: '<S163>/offset'
       *  Constant: '<S163>/offset1'
       *  Constant: '<S163>/one_on_slope'
       *  DataTypeConversion: '<S163>/OutDTConv'
       *  Product: '<S163>/Product4'
       *  Sum: '<S163>/Add1'
       *  Sum: '<S163>/Add2'
       */
      if (InjSys_bAcvRatInj31_MP) {
        localtmp = (32768.0F * InjSys_rInj31Tmp_MP) + 0.5F;
        if (localtmp < 65536.0F) {
          if (localtmp >= 0.0F) {
            rInjSp_B.Merge2 = (UInt16)localtmp;
          } else {
            rInjSp_B.Merge2 = 0U;
          }
        } else {
          rInjSp_B.Merge2 = MAX_uint16_T;
        }
      } else {
        rInjSp_B.Merge2 = InjSys_rInj3TmpSat;
      }

      /* Switch: '<S27>/Switch4' */
      if (localRelationalOperator3) {
        rInjSp_B.Merge = InjSys_rInj1TmpSat;
      } else {
        rInjSp_B.Merge = localSwitch;
      }

      /* end of Outputs for SubSystem: '<S8>/F05_FuMass' */

      /* SignalConversion: '<S8>/Signal Conversion1' */
      rInjSp_B.Merge4 = localRelationalOperator3;

      /* SignalConversion: '<S8>/Signal Conversion2' */
      rInjSp_B.Merge7 = localRelationalOperator4;

      /* SignalConversion: '<S8>/Signal Conversion3' */
      rInjSp_B.Merge3 = localSwitch2_c;
    }

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET */
    VEMS_vidSET(InjSys_bAcvInjPat0, rInjSp_B.Merge4);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET1 */
    VEMS_vidSET(InjSys_bAcvInjPat1, rInjSp_B.Merge5);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET2 */
    VEMS_vidSET(InjSys_bAcvInjPat2, rInjSp_B.Merge6);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET3 */
    VEMS_vidSET(InjSys_bAcvInjPat3, rInjSp_B.Merge7);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET4 */
    VEMS_vidSET(InjSys_noInjPat, rInjSp_B.Merge3);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET5 */
    VEMS_vidSET(InjSys_rInj1Sp, rInjSp_B.Merge);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET6 */
    VEMS_vidSET(InjSys_rInj2Sp, rInjSp_B.Merge1);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET7 */
    VEMS_vidSET(InjSys_rInj3Sp, rInjSp_B.Merge2);
  }

  /* end of Outputs for SubSystem: '<S5>/F02_rInjSp' */
}

/* Output and update for exported function: InjSys_SdlFast_rInjSp */
void InjSys_SdlFast_rInjSp(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S3>/F02_rInjSp'
   */
  rInjSp_F02_rInjSp();
}

/* Model initialize function */
void rInjSp_initialize(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   */
}

#define RINJSP_STOP_SEC_CODE
#include "rInjSp_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
