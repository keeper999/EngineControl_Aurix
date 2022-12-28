/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC                                                     */
/*                                                                            */
/* !Component       : IfEOMInjSp                                              */
/* !Description     : CALCUL DES MASSES D ESSENCE À INJECTER                  */
/*                                                                            */
/* !Module          : IfEOMInjSp                                              */
/*                                                                            */
/* !File            : IfEOMInjSp.c                                            */
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
/* !Reference       : V01NT1006120 / 01                                       */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Fri Jun 01 12:04:59 2012                              */
/*   Model name       : IfEOMInjSp_AUTOCODE.mdl                               */
/*   Model version    : 1.102                                                 */
/*   Root subsystem   : /IfEOMInjSp                                           */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FUSYS/IFEOMINJSP/IfEOMInjSp.c_v $*/
/* $Revision::   1.2                                                         $*/
/* $Author::   etsasson                               $$Date::   07 Mar 2014 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "IfEOMInjSp.h"
#include "IfEOMInjSp_private.h"

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
#define IFEOMINJSP_START_SEC_VAR_UNSPECIFIED
#include "IfEOMInjSp_MemMap.h"

/* Block signals (auto storage) */
BlockIO_IfEOMInjSp IfEOMInjSp_B;

/* Block states (auto storage) */
D_Work_IfEOMInjSp IfEOMInjSp_DWork;

#define IFEOMINJSP_STOP_SEC_VAR_UNSPECIFIED
#include "IfEOMInjSp_MemMap.h"

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
/* !Comment: Define code in section "SEC_CODE" */
#define IFEOMINJSP_START_SEC_CODE
#include "IfEOMInjSp_MemMap.h"

void IfEOMInjSp_ASYNC1(int controlPortIdx)
{
}

/* Start for function-call system: '<S1>/F01_IfEOMInjSp' */
void IfEOMInjSp_F01_IfEOMInjSp_Start(void)
{
  /* Start for enable SubSystem: '<S5>/F01_IfEOMInjSp' */

  /* InitializeConditions for UnitDelay: '<S11>/FixPt Unit Delay2' */
  IfEOMInjSp_DWork.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S13>/FixPt Unit Delay2' */
  IfEOMInjSp_DWork.FixPtUnitDelay2_DSTATE_a = 1U;

  /* end of Start for SubSystem: '<S5>/F01_IfEOMInjSp' */
}

/* Output and update for function-call system: '<S1>/F01_IfEOMInjSp' */
void IfEOMInjSp_F01_IfEOMInjSp(void)
{
  Float localSwitch1;
  Float localSum1;
  Float localProduct4;
  Float localInit;
  Boolean localRelationalOperator_e;
  Float localSwitch;
  SInt32 localtmp;

  /* Outputs for enable SubSystem: '<S5>/F01_IfEOMInjSp' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/MPM_rLdMaxIni_C'
   *  EnablePort: '<S6>/Enable'
   *  RelationalOperator: '<S5>/Relational Operator'
   */
  if (IfEOMInjSp_u8Inhib != 90) {
    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET3 */
    VEMS_vidGET1DArray(EOM_prm_idxBas1ModCur, 16, IfEOMInjSp_B.VEMS_vidGET3);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET23 */
    VEMS_vidSET(InjSys_idxBas1ModCurAgInj, IfEOMInjSp_B.VEMS_vidGET3[1]);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET24 */
    VEMS_vidSET(InjSys_idxBas1ModCurPfuSp, IfEOMInjSp_B.VEMS_vidGET3[0]);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET25 */
    VEMS_vidSET(InjSys_idxBas1ModCurRatInj, IfEOMInjSp_B.VEMS_vidGET3[2]);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET5 */
    VEMS_vidGET1DArray(EOM_prm_idxBas2ModCur, 16, IfEOMInjSp_B.VEMS_vidGET5);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET29 */
    VEMS_vidSET(InjSys_idxBas2ModCurAgInj, IfEOMInjSp_B.VEMS_vidGET5[1]);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET30 */
    VEMS_vidSET(InjSys_idxBas2ModCurPfuSp, IfEOMInjSp_B.VEMS_vidGET5[0]);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET31 */
    VEMS_vidSET(InjSys_idxBas2ModCurRatInj, IfEOMInjSp_B.VEMS_vidGET5[2]);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET4 */
    VEMS_vidGET1DArray(EOM_prm_idxBas1ModTar, 16, IfEOMInjSp_B.VEMS_vidGET4);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET26 */
    VEMS_vidSET(InjSys_idxBas1ModTarAgInj, IfEOMInjSp_B.VEMS_vidGET4[1]);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET27 */
    VEMS_vidSET(InjSys_idxBas1ModTarPfuSp, IfEOMInjSp_B.VEMS_vidGET4[0]);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET28 */
    VEMS_vidSET(InjSys_idxBas1ModTarRatInj, IfEOMInjSp_B.VEMS_vidGET4[2]);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET6 */
    VEMS_vidGET1DArray(EOM_prm_idxBas2ModTar, 16, IfEOMInjSp_B.VEMS_vidGET6);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET32 */
    VEMS_vidSET(InjSys_idxBas2ModTarAgInj, IfEOMInjSp_B.VEMS_vidGET6[1]);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET33 */
    VEMS_vidSET(InjSys_idxBas2ModTarPfuSp, IfEOMInjSp_B.VEMS_vidGET6[0]);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET34 */
    VEMS_vidSET(InjSys_idxBas2ModTarRatInj, IfEOMInjSp_B.VEMS_vidGET6[2]);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET */
    VEMS_vidGET1DArray(EOM_prm_facBasModCur, 16, IfEOMInjSp_B.VEMS_vidGET);

    /* DataTypeConversion: '<S6>/Data Type Conversion10' */
    localtmp = (SInt32)(((UInt32)(IfEOMInjSp_B.VEMS_vidGET[1] * 41)) >> 5);
    if (((UInt32)localtmp) > 255U) {
      IfEOMInjSp_B.DataTypeConversion10 = MAX_uint8_T;
    } else {
      IfEOMInjSp_B.DataTypeConversion10 = (UInt8)localtmp;
    }

    /* DataTypeConversion: '<S6>/Data Type Conversion11' */
    localtmp = (SInt32)(((UInt32)(IfEOMInjSp_B.VEMS_vidGET[2] * 41)) >> 5);
    if (((UInt32)localtmp) > 255U) {
      IfEOMInjSp_B.DataTypeConversion11 = MAX_uint8_T;
    } else {
      IfEOMInjSp_B.DataTypeConversion11 = (UInt8)localtmp;
    }

    /* DataTypeConversion: '<S6>/Data Type Conversion9' */
    localtmp = (SInt32)(((UInt32)(IfEOMInjSp_B.VEMS_vidGET[0] * 41)) >> 5);
    if (((UInt32)localtmp) > 255U) {
      IfEOMInjSp_B.DataTypeConversion9 = MAX_uint8_T;
    } else {
      IfEOMInjSp_B.DataTypeConversion9 = (UInt8)localtmp;
    }

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET */
    VEMS_vidSET(InjSys_facBasModCurAgInj, IfEOMInjSp_B.DataTypeConversion10);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET15 */
    VEMS_vidSET(InjSys_facBasModCurPfuSp, IfEOMInjSp_B.DataTypeConversion9);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET16 */
    VEMS_vidSET(InjSys_facBasModCurRatInj, IfEOMInjSp_B.DataTypeConversion11);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET1 */
    VEMS_vidGET1DArray(EOM_prm_facBasModTar, 16, IfEOMInjSp_B.VEMS_vidGET1);

    /* DataTypeConversion: '<S6>/Data Type Conversion12' */
    localtmp = (SInt32)(((UInt32)(IfEOMInjSp_B.VEMS_vidGET1[1] * 41)) >> 5);
    if (((UInt32)localtmp) > 255U) {
      IfEOMInjSp_B.DataTypeConversion12 = MAX_uint8_T;
    } else {
      IfEOMInjSp_B.DataTypeConversion12 = (UInt8)localtmp;
    }

    /* DataTypeConversion: '<S6>/Data Type Conversion13' */
    localtmp = (SInt32)(((UInt32)(IfEOMInjSp_B.VEMS_vidGET1[2] * 41)) >> 5);
    if (((UInt32)localtmp) > 255U) {
      IfEOMInjSp_B.DataTypeConversion13 = MAX_uint8_T;
    } else {
      IfEOMInjSp_B.DataTypeConversion13 = (UInt8)localtmp;
    }

    /* DataTypeConversion: '<S6>/Data Type Conversion4' */
    localtmp = (SInt32)(((UInt32)(IfEOMInjSp_B.VEMS_vidGET1[0] * 41)) >> 5);
    if (((UInt32)localtmp) > 255U) {
      IfEOMInjSp_B.DataTypeConversion4 = MAX_uint8_T;
    } else {
      IfEOMInjSp_B.DataTypeConversion4 = (UInt8)localtmp;
    }

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET17 */
    VEMS_vidSET(InjSys_facBasModTarAgInj, IfEOMInjSp_B.DataTypeConversion12);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET18 */
    VEMS_vidSET(InjSys_facBasModTarPfuSp, IfEOMInjSp_B.DataTypeConversion4);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET19 */
    VEMS_vidSET(InjSys_facBasModTarRatInj, IfEOMInjSp_B.DataTypeConversion13);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET9 */
    VEMS_vidGET(Ext_nEng, IfEOMInjSp_B.VEMS_vidGET9);

    /* DataTypeConversion: '<S6>/Data Type Conversion' */
    localSwitch1 = (Float)IfEOMInjSp_B.VEMS_vidGET9;

    /* Switch: '<S11>/Init' incorporates:
     *  UnitDelay: '<S11>/FixPt Unit Delay1'
     *  UnitDelay: '<S11>/FixPt Unit Delay2'
     */
    if (IfEOMInjSp_DWork.FixPtUnitDelay2_DSTATE != 0) {
      localInit = localSwitch1;
    } else {
      localInit = IfEOMInjSp_DWork.FixPtUnitDelay1_DSTATE;
    }

    /* Product: '<S12>/Divide' incorporates:
     *  Constant: '<S6>/InjSys_nEngDBInjSp_C'
     *  Constant: '<S7>/Constant'
     *  DataTypeConversion: '<S6>/Data Type Conversion3'
     */
    localSum1 = 0.5F * ((Float)InjSys_nEngDBInjSp_C);

    /* Sum: '<S7>/Sum' */
    localProduct4 = localSum1 + localSwitch1;

    /* RelationalOperator: '<S7>/Relational Operator' */
    localRelationalOperator_e = (localInit <= localProduct4);

    /* Sum: '<S7>/Sum1' */
    localSum1 = localSwitch1 - localSum1;

    /* Switch: '<S7>/Switch1' incorporates:
     *  RelationalOperator: '<S7>/Relational Operator2'
     */
    if (!(localInit > localProduct4)) {
      localProduct4 = localSum1;
    }

    /* Switch: '<S7>/Switch' incorporates:
     *  Logic: '<S7>/Logical Operator'
     *  RelationalOperator: '<S7>/Relational Operator1'
     */
    if ((localRelationalOperator_e) && (localInit >= localSum1)) {
      localSwitch = localInit;
    } else {
      localSwitch = localProduct4;
    }

    /* DataTypeConversion: '<S9>/OutDTConv' incorporates:
     *  Constant: '<S9>/offset'
     *  Constant: '<S9>/one_on_slope'
     *  Product: '<S9>/Product4'
     *  Sum: '<S9>/Add1'
     */
    if (localSwitch < 65536.0F) {
      if (localSwitch >= 0.0F) {
        IfEOMInjSp_B.OutDTConv = (UInt16)localSwitch;
      } else {
        IfEOMInjSp_B.OutDTConv = 0U;
      }
    } else {
      IfEOMInjSp_B.OutDTConv = MAX_uint16_T;
    }

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET36 */
    VEMS_vidSET(InjSys_nEngInjSp, IfEOMInjSp_B.OutDTConv);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET2 */
    VEMS_vidGET1DArray(EOM_prm_facTranMod, 16, IfEOMInjSp_B.VEMS_vidGET2);

    /* DataTypeConversion: '<S6>/Data Type Conversion1' */
    localtmp = (SInt32)(((UInt32)(IfEOMInjSp_B.VEMS_vidGET2[0] * 41)) >> 5);
    if (((UInt32)localtmp) > 255U) {
      IfEOMInjSp_B.DataTypeConversion1 = MAX_uint8_T;
    } else {
      IfEOMInjSp_B.DataTypeConversion1 = (UInt8)localtmp;
    }

    /* DataTypeConversion: '<S6>/Data Type Conversion14' */
    localtmp = (SInt32)(((UInt32)(IfEOMInjSp_B.VEMS_vidGET2[1] * 41)) >> 5);
    if (((UInt32)localtmp) > 255U) {
      IfEOMInjSp_B.DataTypeConversion14 = MAX_uint8_T;
    } else {
      IfEOMInjSp_B.DataTypeConversion14 = (UInt8)localtmp;
    }

    /* DataTypeConversion: '<S6>/Data Type Conversion15' */
    localtmp = (SInt32)(((UInt32)(IfEOMInjSp_B.VEMS_vidGET2[2] * 41)) >> 5);
    if (((UInt32)localtmp) > 255U) {
      IfEOMInjSp_B.DataTypeConversion15 = MAX_uint8_T;
    } else {
      IfEOMInjSp_B.DataTypeConversion15 = (UInt8)localtmp;
    }

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET20 */
    VEMS_vidSET(InjSys_facTranModAgInj, IfEOMInjSp_B.DataTypeConversion14);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET21 */
    VEMS_vidSET(InjSys_facTranModPfuSp, IfEOMInjSp_B.DataTypeConversion1);

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET22 */
    VEMS_vidSET(InjSys_facTranModRatInj, IfEOMInjSp_B.DataTypeConversion15);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET7 */
    VEMS_vidGET1DArray(EngM_prm_mAirPredInCyl, 6, IfEOMInjSp_B.VEMS_vidGET7);

    /* S-Function "vems_vidGET" Block: <S6>/VEMS_vidGET8 */
    VEMS_vidGET(Eng_noInNxtCyl, IfEOMInjSp_B.VEMS_vidGET8);

    /* DataTypeConversion: '<S6>/Data Type Conversion5' incorporates:
     *  Selector: '<S6>/Selector21'
     */
    localProduct4 = ((Float)
                     IfEOMInjSp_B.VEMS_vidGET7[IfEOMInjSp_B.VEMS_vidGET8 - 1]) *
      1.192016583E-007F;

    /* Switch: '<S13>/Init' incorporates:
     *  UnitDelay: '<S13>/FixPt Unit Delay1'
     *  UnitDelay: '<S13>/FixPt Unit Delay2'
     */
    if (IfEOMInjSp_DWork.FixPtUnitDelay2_DSTATE_a != 0) {
      localInit = localProduct4;
    } else {
      localInit = IfEOMInjSp_DWork.FixPtUnitDelay1_DSTATE_h;
    }

    /* Product: '<S14>/Divide' incorporates:
     *  Constant: '<S6>/InjSys_mAirDBInjSp_C'
     *  Constant: '<S8>/Constant'
     *  DataTypeConversion: '<S6>/Data Type Conversion6'
     */
    localSum1 = (((Float)InjSys_mAirDBInjSp_C) * 1.192016583E-007F) * 0.5F;

    /* Sum: '<S8>/Sum' */
    localSwitch1 = localSum1 + localProduct4;

    /* RelationalOperator: '<S8>/Relational Operator' */
    localRelationalOperator_e = (localInit <= localSwitch1);

    /* Sum: '<S8>/Sum1' */
    localSum1 = localProduct4 - localSum1;

    /* Switch: '<S8>/Switch1' incorporates:
     *  RelationalOperator: '<S8>/Relational Operator2'
     */
    if (!(localInit > localSwitch1)) {
      localSwitch1 = localSum1;
    }

    /* Switch: '<S8>/Switch' incorporates:
     *  Logic: '<S8>/Logical Operator'
     *  RelationalOperator: '<S8>/Relational Operator1'
     */
    if ((localRelationalOperator_e) && (localInit >= localSum1)) {
      localSwitch1 = localInit;
    }

    /* DataTypeConversion: '<S10>/OutDTConv' incorporates:
     *  Constant: '<S10>/offset'
     *  Constant: '<S10>/one_on_slope'
     *  Product: '<S10>/Product4'
     *  Sum: '<S10>/Add1'
     */
    localInit = 8.389145E+006F * localSwitch1;
    if (localInit < 65536.0F) {
      if (localInit >= 0.0F) {
        IfEOMInjSp_B.OutDTConv_a = (UInt16)localInit;
      } else {
        IfEOMInjSp_B.OutDTConv_a = 0U;
      }
    } else {
      IfEOMInjSp_B.OutDTConv_a = MAX_uint16_T;
    }

    /* S-Function "vems_vidSET" Block: <S6>/VEMS_vidSET35 */
    VEMS_vidSET(InjSys_mAirPredInjSp, IfEOMInjSp_B.OutDTConv_a);

    /* Update for UnitDelay: '<S11>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S11>/FixPt Constant'
     */
    IfEOMInjSp_DWork.FixPtUnitDelay2_DSTATE = 0U;

    /* Update for UnitDelay: '<S11>/FixPt Unit Delay1' */
    IfEOMInjSp_DWork.FixPtUnitDelay1_DSTATE = localSwitch;

    /* Update for UnitDelay: '<S13>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S13>/FixPt Constant'
     */
    IfEOMInjSp_DWork.FixPtUnitDelay2_DSTATE_a = 0U;

    /* Update for UnitDelay: '<S13>/FixPt Unit Delay1' */
    IfEOMInjSp_DWork.FixPtUnitDelay1_DSTATE_h = localSwitch1;
  }

  /* end of Outputs for SubSystem: '<S5>/F01_IfEOMInjSp' */
}

/* Start for exported function: InjSys_SdlFast_IfEOMInjSp */
void InjSys_SdlFast_IfEOMInjSp_Start(void)
{
  /* Start for S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  Start for SubSystem: '<S1>/F01_IfEOMInjSp'
   */
  IfEOMInjSp_F01_IfEOMInjSp_Start();
}

/* Output and update for exported function: InjSys_SdlFast_IfEOMInjSp */
void InjSys_SdlFast_IfEOMInjSp(void)
{
  /* S-Function (fcncallgen): '<S2>/expFcn' incorporates:
   *  SubSystem: '<S1>/F01_IfEOMInjSp'
   */
  IfEOMInjSp_F01_IfEOMInjSp();
}

/* Output and update for function-call system: '<S1>/F00_Init' */
void IfEOMInjSp_F00_Init(void)
{
  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET10 */
  VEMS_vidSET(InjSys_idxBas1ModCurPfuSp, ((UInt8)1U));

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET9 */
  VEMS_vidSET(InjSys_idxBas1ModCurAgInj, ((UInt8)1U));

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET11 */
  VEMS_vidSET(InjSys_idxBas1ModCurRatInj, ((UInt8)1U));

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET16 */
  VEMS_vidSET(InjSys_idxBas2ModCurPfuSp, ((UInt8)1U));

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET15 */
  VEMS_vidSET(InjSys_idxBas2ModCurAgInj, ((UInt8)1U));

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET17 */
  VEMS_vidSET(InjSys_idxBas2ModCurRatInj, ((UInt8)1U));

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET13 */
  VEMS_vidSET(InjSys_idxBas1ModTarPfuSp, ((UInt8)1U));

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET12 */
  VEMS_vidSET(InjSys_idxBas1ModTarAgInj, ((UInt8)1U));

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET14 */
  VEMS_vidSET(InjSys_idxBas1ModTarRatInj, ((UInt8)1U));

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET19 */
  VEMS_vidSET(InjSys_idxBas2ModTarPfuSp, ((UInt8)1U));

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET18 */
  VEMS_vidSET(InjSys_idxBas2ModTarAgInj, ((UInt8)1U));

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET20 */
  VEMS_vidSET(InjSys_idxBas2ModTarRatInj, ((UInt8)1U));

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET1 */
  VEMS_vidSET(InjSys_facBasModCurPfuSp, 0U);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET */
  VEMS_vidSET(InjSys_facBasModCurAgInj, 0U);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET2 */
  VEMS_vidSET(InjSys_facBasModCurRatInj, 0U);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET4 */
  VEMS_vidSET(InjSys_facBasModTarPfuSp, 0U);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET3 */
  VEMS_vidSET(InjSys_facBasModTarAgInj, 0U);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET5 */
  VEMS_vidSET(InjSys_facBasModTarRatInj, 0U);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET7 */
  VEMS_vidSET(InjSys_facTranModPfuSp, 0U);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET6 */
  VEMS_vidSET(InjSys_facTranModAgInj, 0U);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET8 */
  VEMS_vidSET(InjSys_facTranModRatInj, 0U);

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET22 */
  VEMS_vidSET(InjSys_nEngInjSp, ((UInt16)0U));

  /* S-Function "vems_vidSET" Block: <S4>/VEMS_vidSET21 */
  VEMS_vidSET(InjSys_mAirPredInjSp, ((UInt16)0U));
}

/* Output and update for exported function: InjSys_EveRst_IfEOMInjSp */
void InjSys_EveRst_IfEOMInjSp(void)
{
  /* S-Function (fcncallgen): '<S3>/expFcn' incorporates:
   *  SubSystem: '<S1>/F00_Init'
   */
  IfEOMInjSp_F00_Init();
}

/* Model initialize function */
void IfEOMInjSp_initialize(void)
{
  /* Start for S-Function (expFcnGen): '<Root>/__FcnCallGen__0' incorporates:
   *  Start for SubSystem: '<Root>/__ExpFcn__1'
   *  Start for SubSystem: '<Root>/__ExpFcn__2'
   */
  InjSys_SdlFast_IfEOMInjSp_Start();
}

#define IFEOMINJSP_STOP_SEC_CODE
#include "IfEOMInjSp_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
