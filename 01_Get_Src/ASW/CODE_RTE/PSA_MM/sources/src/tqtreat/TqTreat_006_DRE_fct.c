/**************************************************************************************************\
 *** 
 *** Simulink model       : CSMT_CGMT06_2409_v5_0_EveSync
 *** TargetLink subsystem : CSMT_CGMT06_2409_v5_0_EveSync/F00_CalculVarElementaire
 *** Codefile             : TqTreat_006_DRE_fct.c
 ***
 *** Generated by TargetLink, the dSPACE production quality code generator
 *** Generation date: 2010-08-04 10:59:52
 ***
 *** CODE GENERATOR OPTIONS:
 *** Compiler                            : <unknown>
 *** Target                              : Generic
 *** ANSI-C compatible code              : yes
 *** Optimization level                  : 2
 *** Constant style                      : decimal
 *** Clean code option                   : enabled
 *** Logging mode                        : Do not log anything
 *** Linker sections                     : enabled
 *** Assembler statements                : disabled
 *** Variable name length                : 31 chars
 *** Use global bitfields                : disabled
 *** Stateflow: use of bitfields         : enabled
 *** State activity encoding limit       : 5
 *** Omit zero inits in restart function : disabled
 *** Share fcns between TL subsystems    : enabled
 *** Generate 64bit functions            : enabled
 *** Inlining Threshold                  : 6
 *** Line break limit                    : 100
 *** Target optimized boolean data type  : enabled
 *** Keep saturation elements            : disabled
 *** Extended variable sharing           : disabled
 *** Style definition file               : C:\dSPACE\Matlab\Tl\config\codegen\cconfig.xml
 *** Root style sheet                    : C:\dSPACE\Matlab\Tl\XML\CodeGen\Stylesheets\TL_CSourceCod
 ***                                       eSS.xsl
 *** Enable Multirate codegeneration     : disabled
 *** Add model checksum                  : disabled
 ***
 *** SUBSYS                   CORRESPONDING SIMULINK SUBSYSTEM
 *** S0061                    CSMT_CGMT06_2409_v5_0_EveSync/F00_CalculVarElementaire
 *** S0062                    F00_CalculVarElementaire/F01_CSMT_CGMT06_2409_v5_0
 *** S0063                    F00_CalculVarElementaire/F01_CSMT_CGMT06_2409_v5_0/F02_Calc_Regime_Syn
 ***                          chro_Moteur
 *** 
 *** SF-NODE   CORRESPONDING STATEFLOW NODE                           DESCRIPTION
 *** 
 *** TargetLink version      : 2.2.1 from 21-Jun-2007
 *** Code generator version  : Build Id 2.2.1.9 from 2007-06-21 12:36:51
 *** Copyright (c) 2006 dSPACE GmbH
\**************************************************************************************************/ 

#ifndef _TQTREAT_006_DRE_FCT_C_
#define _TQTREAT_006_DRE_FCT_C_

/*----------------------------------------------------------------------------*\
  DEFINES (OPT)
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  INCLUDES
\*----------------------------------------------------------------------------*/
#include "TqTreat_006_DRE_fct.h"
#include "TqTreat_006_calibrations.h"
/*----------------------------------------------------------------------------*\
  DEFINES
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  TYPEDEFS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  ENUMS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  VARIABLES
\*----------------------------------------------------------------------------*/

#define TQTREAT_START_SEC_GLOBAL_16BIT
#include "TqTreat_MemMap.h"
/******************************************************************************\
   AR_IF_GLOBAL_16BIT: Global 16 bits for AUTOSAR modules | Width: 16
\******************************************************************************/
AR_IF_GLOBAL_16BIT UInt16 Ext_nEng1_out /* 
   Unit       : RPM
   Description: Valeur pr�c�dente de Ext_nEng
   LSB: 2^-2 OFF:  0 MIN/MAX:  0 .. 8000 */;
AR_IF_GLOBAL_16BIT UInt16 Ext_nEng2_out /* 
   Unit       : RPM
   Description: Valeur pr�c�dente de Ext_nEng
   LSB: 2^-2 OFF:  0 MIN/MAX:  0 .. 8000 */;
AR_IF_GLOBAL_16BIT UInt16 Ext_nEngAvr_out /* 
   Unit       : RPM
   Description: R�gime moteur moyenn� sur 4 PMH / Mean engine speed on 4 TDC
   LSB: 2^-2 OFF:  0 MIN/MAX:  0 .. 8000 */;
AR_IF_GLOBAL_16BIT UInt16 Ext_nEngClc0_out /* 
   Unit       : RPM
   Description: R�gime recentr� recalcul� entre 2 synchro moteur
   LSB: 2^-2 OFF:  0 MIN/MAX:  0 .. 8000 */;
AR_IF_GLOBAL_16BIT UInt16 Ext_nEngClc1_out /* 
   Unit       : RPM
   Description: R�gime recentr� recalcul� entre 2 synchro moteur retard� d'une tache
   LSB: 2^-2 OFF:  0 MIN/MAX:  0 .. 8000 */;
AR_IF_GLOBAL_16BIT UInt16 TqTreat_006_Ext_nEngClc_in /* 
   Unit       : RPM
   Description: r�gime recentr�, valeur de remplacement : Ext_nEng,
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 8000 */;
AR_IF_GLOBAL_16BIT UInt16 TqTreat_006_Ext_nEng_in /* 
   Unit       : RPM
   Description: R�gime moteur mesur� sur une phase moteur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 7500 */;

#define TQTREAT_STOP_SEC_GLOBAL_16BIT
#include "TqTreat_MemMap.h"

#define TQTREAT_START_SEC_GLOBAL_8BIT
#include "TqTreat_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_8BIT: Global 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
AR_IF_GLOBAL_8BIT UInt8 TqTreat_006_Ext_noCylEng_in /* 
   Description: -
   LSB: 2^0 OFF:  0 MIN/MAX:  1 .. 12 */;

#define TQTREAT_STOP_SEC_GLOBAL_8BIT
#include "TqTreat_MemMap.h"

#define TQTREAT_START_SEC_VAR_16BIT
#include "TqTreat_MemMap.h"

/******************************************************************************\
   UserSLStaticGlobal: SLStaticGlobal = { AR_SEC_VAR_BOOLEAN AR_SEC_VAR_16BIT AR_SEC_VAR_8BIT AR_SEC
   _VAR_16BIT AR_SEC_VAR_32BIT AR_SEC_VAR_16BIT } | Width: 16
\******************************************************************************/
static UInt16 S0063_Switch2;
static UInt16 S0063_Switch3;
static UInt16 S0063_Unit_Delay;
static UInt16 S0063_Unit_Delay2;

#define TQTREAT_STOP_SEC_VAR_16BIT
#include "TqTreat_MemMap.h"

#define TQTREAT_START_SEC_VAR_16BIT
#include "TqTreat_MemMap.h"

/******************************************************************************\
   UserSLStaticGlobalInit: SLStaticGlobalInit = { AR_SEC_VAR_BOOLEAN AR_SEC_VAR_16BIT AR_SEC_VAR_8BI
   T AR_SEC_VAR_16BIT AR_SEC_VAR_32BIT AR_SEC_VAR_16BIT } | Width: 16
\******************************************************************************/
static UInt16 X_S0063_Unit_Delay;
static UInt16 X_S0063_Unit_Delay1;
static UInt16 X_S0063_Unit_Delay2;
static UInt16 X_S0063_Unit_Delay3;
static UInt16 X_S0063_Unit_Delay4;
static UInt16 X_S0063_Unit_Delay5;
static UInt16 X_S0063_Unit_Delay6;

#define TQTREAT_STOP_SEC_VAR_16BIT
#include "TqTreat_MemMap.h"

/*----------------------------------------------------------------------------*\
  PARAMETERIZED MACROS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION PROTOTYPES
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  INLINE FUNCTIONS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION DEFINITIONS
\*----------------------------------------------------------------------------*/

/**************************************************************************************************\
 ***  FUNCTION:
 ***      TqTreat_005_MSE_ini
 *** 
 ***  DESCRIPTION:
 ***      Main restart function
 ***      
 *** 
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***
 ***  RETURNS:
 ***      Void
 ***
 ***  SETTINGS:
 ***
\**************************************************************************************************/ 

#define TQTREAT_START_SEC_CODE
#include "TqTreat_MemMap.h"
Void TqTreat_005_MSE_ini(Void)
{
   TqTreat_005_FctVarInit();
}

#define TQTREAT_STOP_SEC_CODE
#include "TqTreat_MemMap.h"
/**************************************************************************************************\
 ***  FUNCTION:
 ***      TqTreat_006_DRE_fct
 *** 
 ***  DESCRIPTION:
 ***      
 *** 
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***
 ***  RETURNS:
 ***      Void
 ***
 ***  SETTINGS:
 ***
\**************************************************************************************************/ 

#define TQTREAT_START_SEC_CODE
#include "TqTreat_MemMap.h"
Void TqTreat_006_DRE_fct(Void)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   UInt16 S0063_Sum1;
   UInt16 S0063_Sum2;
   UInt16 S0063_Unit_Delay3;
   UInt16 S0063_Unit_Delay4;
   UInt16 Aux_U16;

   /* Unit delay: F00_CalculVarElementaire/F01_CSMT_CGMT06_2409_v5_0/F02_Calc_Regime_Synchro_Moteur/
      Unit Delay */
   S0063_Unit_Delay = X_S0063_Unit_Delay;

   /* Unit delay: F00_CalculVarElementaire/F01_CSMT_CGMT06_2409_v5_0/F02_Calc_Regime_Synchro_Moteur/
      Unit Delay2 */
   S0063_Unit_Delay2 = X_S0063_Unit_Delay2;

   /* Sum: F00_CalculVarElementaire/F01_CSMT_CGMT06_2409_v5_0/F02_Calc_Regime_Synchro_Moteur/Sum2 */
   Aux_U16 = TqTreat_006_Ext_nEng_in;
   Aux_U16 += S0063_Unit_Delay;
   S0063_Sum2 = (UInt16) (Aux_U16 + S0063_Unit_Delay2);

   /* Unit delay: F00_CalculVarElementaire/F01_CSMT_CGMT06_2409_v5_0/F02_Calc_Regime_Synchro_Moteur/
      Unit Delay3 */
   S0063_Unit_Delay3 = X_S0063_Unit_Delay3;

   /* Sum: F00_CalculVarElementaire/F01_CSMT_CGMT06_2409_v5_0/F02_Calc_Regime_Synchro_Moteur/Sum1 */
   S0063_Sum1 = (UInt16) (S0063_Sum2 + S0063_Unit_Delay3);

   /* Unit delay: F00_CalculVarElementaire/F01_CSMT_CGMT06_2409_v5_0/F02_Calc_Regime_Synchro_Moteur/
      Unit Delay4 */
   S0063_Unit_Delay4 = X_S0063_Unit_Delay4;

   /* SwitchF00_CalculVarElementaire/F01_CSMT_CGMT06_2409_v5_0/F02_Calc_Regime_Synchro_Moteur/Switch
      1
      
      F00_CalculVarElementaire/F01_CSMT_CGMT06_2409_v5_0/F02_Calc_Regime_Synchro_Moteur/Switch1: Omi
      tted comparison with constant. */
   if (TqTreat_006_Ext_noCylEng_in == 3) 
   {
      /* # combined # TargetLink outport: F00_CalculVarElementaire/Ext_nEngAvr_ */
      Ext_nEngAvr_out = (UInt16) (((UInt32) (((UInt32) S0063_Sum2) << 2)) / 3 /* 3. */);
   }
   else 
   {
      /* SwitchF00_CalculVarElementaire/F01_CSMT_CGMT06_2409_v5_0/F02_Calc_Regime_Synchro_Moteur/Swi
         tch4
         
         F00_CalculVarElementaire/F01_CSMT_CGMT06_2409_v5_0/F02_Calc_Regime_Synchro_Moteur/Switch4: 
         Omitted comparison with constant. */
      if (TqTreat_006_Ext_noCylEng_in == 4) 
      {
         /* # combined # TargetLink outport: F00_CalculVarElementaire/Ext_nEngAvr_ */
         Ext_nEngAvr_out = (UInt16) (((UInt32) (((UInt32) S0063_Sum1) << 2)) / 4 /* 4. */);
      }
      else 
      {
         /* Sum: F00_CalculVarElementaire/F01_CSMT_CGMT06_2409_v5_0/F02_Calc_Regime_Synchro_Moteur/S
            um3 */
         Aux_U16 = S0063_Sum1;
         Aux_U16 += S0063_Unit_Delay4;

         /* # combined # TargetLink outport: F00_CalculVarElementaire/Ext_nEngAvr_ */
         Ext_nEngAvr_out = (UInt16) (((UInt32) (((UInt32) (UInt16) (Aux_U16 + X_S0063_Unit_Delay5))
          << 2)) / 6 /* 6. */);
      }
   }

   /* SwitchF00_CalculVarElementaire/F01_CSMT_CGMT06_2409_v5_0/F02_Calc_Regime_Synchro_Moteur/Switch
      3
      
      F00_CalculVarElementaire/F01_CSMT_CGMT06_2409_v5_0/F02_Calc_Regime_Synchro_Moteur/Switch3: Omi
      tted comparison with constant. */
   if (TqSys_bNEngSel_C) 
   {
      S0063_Switch3 = X_S0063_Unit_Delay1;
   }
   else 
   {
      S0063_Switch3 = X_S0063_Unit_Delay6;
   }

   /* SwitchF00_CalculVarElementaire/F01_CSMT_CGMT06_2409_v5_0/F02_Calc_Regime_Synchro_Moteur/Switch
      2
      
      F00_CalculVarElementaire/F01_CSMT_CGMT06_2409_v5_0/F02_Calc_Regime_Synchro_Moteur/Switch2: Omi
      tted comparison with constant. */
   if (TqSys_bNEngSel_C) 
   {
      S0063_Switch2 = TqTreat_006_Ext_nEngClc_in;
   }
   else 
   {
      S0063_Switch2 = TqTreat_006_Ext_nEng_in;
   }

   /* Unit delay: F00_CalculVarElementaire/F01_CSMT_CGMT06_2409_v5_0/F02_Calc_Regime_Synchro_Moteur/
      Unit Delay */
   X_S0063_Unit_Delay = TqTreat_006_Ext_nEng_in;

   /* Unit delay: F00_CalculVarElementaire/F01_CSMT_CGMT06_2409_v5_0/F02_Calc_Regime_Synchro_Moteur/
      Unit Delay2 */
   X_S0063_Unit_Delay2 = S0063_Unit_Delay;

   /* Unit delay: F00_CalculVarElementaire/F01_CSMT_CGMT06_2409_v5_0/F02_Calc_Regime_Synchro_Moteur/
      Unit Delay3 */
   X_S0063_Unit_Delay3 = S0063_Unit_Delay2;

   /* Unit delay: F00_CalculVarElementaire/F01_CSMT_CGMT06_2409_v5_0/F02_Calc_Regime_Synchro_Moteur/
      Unit Delay4 */
   X_S0063_Unit_Delay4 = S0063_Unit_Delay3;

   /* Unit delay: F00_CalculVarElementaire/F01_CSMT_CGMT06_2409_v5_0/F02_Calc_Regime_Synchro_Moteur/
      Unit Delay5 */
   X_S0063_Unit_Delay5 = S0063_Unit_Delay4;

   /* Unit delay: F00_CalculVarElementaire/F01_CSMT_CGMT06_2409_v5_0/F02_Calc_Regime_Synchro_Moteur/
      Unit Delay1 */
   X_S0063_Unit_Delay1 = TqTreat_006_Ext_nEngClc_in;

   /* Unit delay: F00_CalculVarElementaire/F01_CSMT_CGMT06_2409_v5_0/F02_Calc_Regime_Synchro_Moteur/
      Unit Delay6 */
   X_S0063_Unit_Delay6 = TqTreat_006_Ext_nEng_in;

   /* TargetLink outport: F00_CalculVarElementaire/Ext_nEngClc1_ */
   Ext_nEngClc1_out = (UInt16) (S0063_Switch3 << 2);

   /* TargetLink outport: F00_CalculVarElementaire/Ext_nEngClc0_ */
   Ext_nEngClc0_out = (UInt16) (S0063_Switch2 << 2);

   /* TargetLink outport: F00_CalculVarElementaire/Ext_nEng2_ */
   Ext_nEng2_out = (UInt16) (S0063_Unit_Delay2 << 2);

   /* TargetLink outport: F00_CalculVarElementaire/Ext_nEng1_ */
   Ext_nEng1_out = (UInt16) (S0063_Unit_Delay << 2);
}

#define TQTREAT_STOP_SEC_CODE
#include "TqTreat_MemMap.h"
/**************************************************************************************************\
 ***  FUNCTION:
 ***      TqTreat_FctVarInit
 *** 
 ***  DESCRIPTION:
 ***      AR_SEC_VAR_32BIT
 *** 
 ***  PARAMETERS:
 ***      Type               Name                Description
 ***      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 ***
 ***  RETURNS:
 ***      Void
 ***
 ***  SETTINGS:
 ***
\**************************************************************************************************/ 

#define TQTREAT_START_SEC_CODE
#include "TqTreat_MemMap.h"
Void TqTreat_005_FctVarInit(Void)
{
   X_S0063_Unit_Delay = 0 /* 0. */;
   X_S0063_Unit_Delay1 = 0 /* 0. */;
   X_S0063_Unit_Delay2 = 0 /* 0. */;
   X_S0063_Unit_Delay3 = 0 /* 0. */;
   X_S0063_Unit_Delay4 = 0 /* 0. */;
   X_S0063_Unit_Delay5 = 0 /* 0. */;
   X_S0063_Unit_Delay6 = 0 /* 0. */;
   
Ext_nEng1_out = 0;
Ext_nEng2_out = 0;
Ext_nEngAvr_out = 0;
Ext_nEngClc0_out = 0;
Ext_nEngClc1_out = 0;   
   
}

#define TQTREAT_STOP_SEC_CODE
#include "TqTreat_MemMap.h"
/*----------------------------------------------------------------------------*\
  MODULE LOCAL FUNCTION DEFINITIONS
\*----------------------------------------------------------------------------*/

#endif/*_TQTREAT_006_DRE_FCT_C_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
