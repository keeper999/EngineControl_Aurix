/**************************************************************************************************\
 *** 
 *** Simulink model       : MgtASE_01460_10_02175_TL
 *** TargetLink subsystem : MgtASE_01460_10_02175_TL/ASE_012
 *** Codefile             : ase_012_tev_fct.c
 ***
 *** Generated by TargetLink, the dSPACE production quality code generator
 *** Generation date: 2011-05-20 11:30:03
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
 *** Extended variable sharing           : enabled
 *** Style definition file               : C:\dSPACE301\Matlab\Tl\config\codegen\cconfig.xml
 *** Root style sheet                    : C:\dSPACE301\Matlab\Tl\XML\CodeGen\Stylesheets\TL_CSource
 ***                                       CodeSS.xsl
 *** Enable Multirate codegeneration     : disabled
 *** Add model checksum                  : disabled
 ***
 *** SUBSYS                   CORRESPONDING SIMULINK SUBSYSTEM
 *** S0121                    MgtASE_01460_10_02175_TL/ASE_012
 *** S0122                    ASE_012/F01_Traitement_booleen
 *** S0123                    ASE_012/F02_Gestion_Dde_Redem_SCAr_MTh
 *** S0124                    ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM
 *** S0125                    ASE_012/F01_Traitement_booleen/Traitement_booleen
 *** S0126                    ASE_012/F01_Traitement_booleen/Traitement_booleen1
 *** S0127                    ASE_012/F01_Traitement_booleen/Traitement_booleen2
 *** S0128                    ASE_012/F01_Traitement_booleen/Traitement_booleen3
 *** S0129                    ASE_012/F02_Gestion_Dde_Redem_SCAr_MTh/BasculeRS
 *** S01210                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/BasculeRS
 *** S01211                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOffDelay
 *** S01212                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay
 *** S01213                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay1
 *** S01214                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOffDelay/BasculeRSspecifiq
 ***                          ue
 *** S01215                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOffDelay/DetectSat
 *** S01216                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOffDelay/Turnoffdelay_Part
 *** S01217                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOffDelay/falling_edge
 *** S01218                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOffDelay/rising_edge2
 *** S01219                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay/BasculeRSspecifiqu
 ***                          e
 *** S01220                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay/DetectSat
 *** S01221                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay/Turnondelay_Part
 *** S01222                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay/rising_edge
 *** S01223                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay/rising_edge2
 *** S01224                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay1/BasculeRSspecifiq
 ***                          ue
 *** S01225                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay1/DetectSat
 *** S01226                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay1/Turnondelay_Part
 *** S01227                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay1/rising_edge
 *** S01228                   ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay1/rising_edge2
 *** 
 *** SF-NODE   CORRESPONDING STATEFLOW NODE                           DESCRIPTION
 *** 
 *** TargetLink version      : 3.0.1 from 26-May-2009
 *** Code generator version  : Build Id 3.0.1.7 from 2009-May-06 15:28:18
 *** Copyright (c) 2006 dSPACE GmbH
\**************************************************************************************************/

#ifndef _ASE_012_TEV_FCT_C_
#define _ASE_012_TEV_FCT_C_

/*----------------------------------------------------------------------------*\
  DEFINES (OPT)
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  INCLUDES
\*----------------------------------------------------------------------------*/
#include "ASE_012_TEV_fct.h"
#include "ASE_012_calibrations.h"
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

#define ASE_START_SEC_GLOBAL_8BIT
#include "ASE_MemMap.h"
/******************************************************************************\
   AR_IF_GLOBAL_8BIT: Global 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
AR_IF_GLOBAL_8BIT UInt8 ASE_012_CoEmCkg_stStrtRstrtFbCmd_in /* 
   Description: Retour de commande d�marrage red�marrage du SEEM
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;
AR_IF_GLOBAL_8BIT UInt8 ASE_012_CoPtASE_stPwt_in /* 
   Description: Etat_GMP_SCAr
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 10 */;

#define ASE_STOP_SEC_GLOBAL_8BIT
#include "ASE_MemMap.h"

#define ASE_START_SEC_GLOBAL_BOOLEAN
#include "ASE_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_BOOLEAN: Global boolean for AUTOSAR modules | Width: 8
\******************************************************************************/
AR_IF_GLOBAL_BOOLEAN Boolean ASE_012_CoPtASE_bEngCutOffReq_in /* 
   Description: Demande de coupure du moteur thermique par la fonction Sortie Calage (A1 : Dde_Coupu
   re_SCAr_MTh)
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
AR_IF_GLOBAL_BOOLEAN Boolean ASE_012_CoPtASE_bEngStallReq_in /* 
   Description: Demande de calage venant de la fonction Sortie Calage (A1 : Dde_Calage_MTh)
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
AR_IF_GLOBAL_BOOLEAN Boolean ASE_012_CoPtUH_bEngRstrtClsCluCdn_in /* 
   Description: Condition de pilotage du red�marrage CdT ferm�e
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
AR_IF_GLOBAL_BOOLEAN Boolean ASE_012_CoTqRStrt_bEngStrtSuc_in /* 
   Description: Signal indiquant que le d�marrage au sens large est r�ussi
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
AR_IF_GLOBAL_BOOLEAN Boolean ASE_012_EngReqH_bEngRStrtAutnAvl_in /* 
   Description: Capacit� Redem Autonome
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
AR_IF_GLOBAL_BOOLEAN Boolean ASE_012_PARM_bEngRstrtAutnAvl_in /* 
   Description: Capacit� Redem Autonome Dim = 1x1
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
AR_IF_GLOBAL_BOOLEAN Boolean CoPtASE_bAltRStrtTypASEReq_out /* 
   Description: Demande de sortie calage type red�marrage pour l'alternateur (A1 : Dde_Redem_SCAr_SE
   EM)
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
AR_IF_GLOBAL_BOOLEAN Boolean CoPtASE_bCdnInhRStrt_out /* 
   Description: Condition d'inhibition pour sortie calage (A1 : Inhibition_Redem_SEEM)
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
AR_IF_GLOBAL_BOOLEAN Boolean CoPtASE_bEngRStrtTypASEReq_out /* 
   Description: Demande de sortie calage type red�marrage (A1 : Dde_Redem_SCAr_MTh)
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
AR_IF_GLOBAL_BOOLEAN Boolean CoPtASE_bVSSNwAcvAuth_out /* 
   Description: Autorisation de maintien DMTR venant de la fonction Sortie Calage (A1 : Autorisation
   _maintien_DMTR)
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
AR_IF_GLOBAL_BOOLEAN Boolean RE_ASE_012_TEV_CoASE_bHiSpdRstrtAuth_in /* 
   Description: Autorisation de la demande de red�marrage pour l'alternateur sur vitesse haute
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;

#define ASE_STOP_SEC_GLOBAL_BOOLEAN
#include "ASE_MemMap.h"

#define ASE_START_SEC_VAR_16BIT
#include "ASE_MemMap.h"

/******************************************************************************\
   UserSLStaticGlobalInit: SLStaticGlobalInit = { AR_SEC_VAR_BOOLEAN AR_SEC_UNSPECIFIED AR_SEC_VAR_8
   BIT AR_SEC_VAR_16BIT AR_SEC_VAR_32BIT AR_SEC_UNSPECIFIED } | Width: 16
\******************************************************************************/
static SInt16 X_S01211_UnitDelay1 /* LSB: 0.01 OFF:  0 MIN/MAX:  -327.68 .. 327.67 */;
static SInt16 X_S01212_UnitDelay1 /* LSB: 0.01 OFF:  0 MIN/MAX:  -327.68 .. 327.67 */;

#define ASE_STOP_SEC_VAR_16BIT
#include "ASE_MemMap.h"

#define ASE_START_SEC_VAR_8BIT
#include "ASE_MemMap.h"

/******************************************************************************\
   UserSLStaticGlobalInit: SLStaticGlobalInit = { AR_SEC_VAR_BOOLEAN AR_SEC_UNSPECIFIED AR_SEC_VAR_8
   BIT AR_SEC_VAR_16BIT AR_SEC_VAR_32BIT AR_SEC_UNSPECIFIED } | Width: 8
\******************************************************************************/
static SInt8 X_S01213_UnitDelay1 /* LSB: 0.01 OFF:  0 MIN/MAX:  -1.28 .. 1.27 */;

#define ASE_STOP_SEC_VAR_8BIT
#include "ASE_MemMap.h"

#define ASE_START_SEC_VAR_BOOLEAN
#include "ASE_MemMap.h"

/******************************************************************************\
   UserSLStaticGlobalInit: SLStaticGlobalInit = { AR_SEC_VAR_BOOLEAN AR_SEC_UNSPECIFIED AR_SEC_VAR_8
   BIT AR_SEC_VAR_16BIT AR_SEC_VAR_32BIT AR_SEC_UNSPECIFIED } | Width: 8
\******************************************************************************/
static Boolean X_S01210_Unit_Delay;
static Boolean X_S01210_Unit_Delay1;
static Boolean X_S01211_Unit_Delay;
static Boolean X_S01212_Unit_Delay;
static Boolean X_S01213_Unit_Delay;
static Boolean X_S01214_Unit_Delay;
static Boolean X_S01217_UnitDelay;
static Boolean X_S01218_UnitDelay;
static Boolean X_S01219_Unit_Delay;
static Boolean X_S01222_UnitDelay;
static Boolean X_S01223_UnitDelay;
static Boolean X_S01224_Unit_Delay;
static Boolean X_S01227_UnitDelay;
static Boolean X_S01228_UnitDelay;
static Boolean X_S0129_Unit_Delay;
static Boolean X_S0129_Unit_Delay1;

#define ASE_STOP_SEC_VAR_BOOLEAN
#include "ASE_MemMap.h"

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
 ***      ASE_011_MSE_ini
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

#define ASE_START_SEC_CODE
#include "ASE_MemMap.h"
Void ASE_011_MSE_ini(Void)
{
   ASE_012_FctVarInit();
}

#define ASE_STOP_SEC_CODE
#include "ASE_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      ASE_012_TEV_fct
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

#define ASE_START_SEC_CODE
#include "ASE_MemMap.h"
Void ASE_012_TEV_fct(Void)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   SInt16 Aux_I16 /* LSB: 0.01 OFF:  0 MIN/MAX:  -327.68 .. 327.67 */;
   SInt16 Aux_I16_a /* LSB: 0.01 OFF:  0 MIN/MAX:  -327.68 .. 327.67 */;
   SInt16 Aux_I16_b /* LSB: 0.01 OFF:  0 MIN/MAX:  -327.68 .. 327.67 */;
   SInt16 Aux_I16_c /* LSB: 0.01 OFF:  0 MIN/MAX:  -327.68 .. 327.67 */;
   SInt16 Aux_I16_d /* LSB: 0.01 OFF:  0 MIN/MAX:  -327.68 .. 327.67 */;
   UInt16 Aux_U16;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   SInt8 Aux_I8 /* LSB: 0.01 OFF:  0 MIN/MAX:  -1.28 .. 1.27 */;
   SInt8 Aux_I8_a /* LSB: 0.01 OFF:  0 MIN/MAX:  -1.28 .. 1.27 */;
   SInt8 Aux_I8_b /* LSB: 0.01 OFF:  0 MIN/MAX:  -1.28 .. 1.27 */;
   UInt8 Aux_U8;
   Boolean Aux__c;
   Boolean Aux__d;
   Boolean Aux__e;
   Boolean Aux__f;
   Boolean Aux__g;
   Boolean Aux__h;
   Boolean Aux__i;
   Boolean Aux__j;
   Boolean Aux__k;
   Boolean Aux__l;
   Boolean Aux__m;
   Boolean Aux__n;

   /* Multiport switch: ASE_012/F01_Traitement_booleen/Traitement_booleen/MgtASE_bEngRstrtAutnAvl_vi
      su */
   switch (MgtASE_stModEngRstrtAutnAvl_C) {
      case 0: {
         MgtASE_bEngRstrtAutnAvl = ASE_012_EngReqH_bEngRStrtAutnAvl_in;
         break;
      }
      case 1: {
         MgtASE_bEngRstrtAutnAvl = !(ASE_012_EngReqH_bEngRStrtAutnAvl_in);
         break;
      }
      case 2: {
         MgtASE_bEngRstrtAutnAvl = 0 /* 0. */;
         break;
      }
      case 3: {
         MgtASE_bEngRstrtAutnAvl = 1 /* 1. */;
         break;
      }
   }

   /* Multiport switch: ASE_012/F01_Traitement_booleen/Traitement_booleen2/MgtASE_bRstrtAutnAvlPARM_
      visu */
   switch (MgtASE_stModRstrtAutnAvlPARM_C) {
      case 0: {
         MgtASE_bRstrtAutnAvlPARM = ASE_012_PARM_bEngRstrtAutnAvl_in;
         break;
      }
      case 1: {
         MgtASE_bRstrtAutnAvlPARM = !(ASE_012_PARM_bEngRstrtAutnAvl_in);
         break;
      }
      case 2: {
         MgtASE_bRstrtAutnAvlPARM = 0 /* 0. */;
         break;
      }
      case 3: {
         MgtASE_bRstrtAutnAvlPARM = 1 /* 1. */;
         break;
      }
   }

   /* Switch: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/BasculeRS/Switch
      ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/BasculeRS/Switch: Omitted comparison with constant. */
   if (X_S01210_Unit_Delay1) {
      /* Multiport switch: ASE_012/F01_Traitement_booleen/Traitement_booleen1/MgtASE_bEngStrtSuc_vis
         u */
      switch (MgtASE_stModEngStrtSuc_C) {
         case 0: {
            MgtASE_bEngStrtSuc = ASE_012_CoTqRStrt_bEngStrtSuc_in;
            break;
         }
         case 1: {
            MgtASE_bEngStrtSuc = !(ASE_012_CoTqRStrt_bEngStrtSuc_in);
            break;
         }
         case 2: {
            MgtASE_bEngStrtSuc = 0 /* 0. */;
            break;
         }
         case 3: {
            MgtASE_bEngStrtSuc = 1 /* 1. */;
            break;
         }
      }

      /* Variable 'S0124_Logical_Operator3' replaced by 'Aux__c' */
      Aux__c = (ASE_012_CoPtASE_stPwt_in == 6 /* 6. */) && (!(ASE_012_CoPtASE_bEngCutOffReq_in)) &&
       (!(ASE_012_CoPtASE_bEngStallReq_in)) && (!(MgtASE_bEngStrtSuc)) &&
       RE_ASE_012_TEV_CoASE_bHiSpdRstrtAuth_in;
      MgtASE_bAltRstrtReqSet_MP = (!(MgtASE_bEngRstrtAutnAvl || MgtASE_bRstrtAutnAvlPARM)) &&
       Aux__c;

      /* Variable 'S01210_Switch' replaced by 'Aux__d' */
      Aux__d = (MgtASE_bAltRstrtReqSet_MP && Aux__c) || ((!(MgtASE_bAltRstrtReqSet_MP)) && Aux__c &&
        X_S01210_Unit_Delay);
   }
   else {
      /* Variable 'S01210_Switch' replaced by 'Aux__d' */
      Aux__d = 0 /* 0. */;
   }

   /* ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/MgtASE_bAltRstrtTypASEReq_visu */
   MgtASE_bAltRstrtTypASEReq_MP = Aux__d;
   Aux_U16 = MgtASE_tiAltRstrtTypASEReq_C;

   /* MinMax: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay/MinMax1 */
   if (Aux_U16) {
      /* Variable 'S01212_MinMax1' replaced by 'Aux_I16' */
      Aux_I16 = (SInt16) Aux_U16;
   }
   else {
      /* Variable 'S01212_MinMax1' replaced by 'Aux_I16' */
      Aux_I16 = 0 /* 0. */;
   }

   /* Variable 'S01212_Relational_Operator1' replaced by 'Aux__c' */
   Aux__c = Aux_I16 == 0 /* 0. */;

   /* Sum: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay/Sum2
      Variable 'S01212_Sum2' replaced by 'Aux_I16_a'
      # combined # Product: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay/Divide2
      ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay/Divide2: folded operation multiplication t
      o constant value 0.1 */
   Aux_I16_a = (SInt16) (Aux_I16 + 10 /* 0.1 */);

   /* Switch: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay/Turnondelay_Part/Switch1
      ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay/Turnondelay_Part/Switch1: Omitted comparis
      on with constant. */
   if (X_S01212_Unit_Delay || (MgtASE_bAltRstrtTypASEReq_MP && (!(X_S01222_UnitDelay)))) {
      /* Variable 'S01221_Switch1' replaced by 'Aux_I16_b' */
      Aux_I16_b = 0 /* 0. */;
   }
   else {
      /* MinMax: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay/DetectSat/MinMax1 */
      if (X_S01212_UnitDelay1 > 0) {
         /* Variable 'S01220_MinMax1' replaced by 'Aux_I16_c' */
         Aux_I16_c = X_S01212_UnitDelay1;
      }
      else {
         /* Variable 'S01220_MinMax1' replaced by 'Aux_I16_c' */
         Aux_I16_c = 0 /* 0. */;
      }

      /* MinMax: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay/DetectSat/MinMax2 */
      if (Aux_I16_a < Aux_I16_c) {
         /* Variable 'S01220_MinMax2' replaced by 'Aux_I16_d' */
         Aux_I16_d = Aux_I16_a;
      }
      else {
         /* Variable 'S01220_MinMax2' replaced by 'Aux_I16_d' */
         Aux_I16_d = Aux_I16_c;
      }

      /* # combined # Sum: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay/Sum1
         Variable 'S01221_Switch1' replaced by 'Aux_I16_b' */
      Aux_I16_b = (SInt16) (((UInt16) Aux_I16_d) + 1);
   }

   /* Variable 'S01212_Relational_Operator2' replaced by 'Aux__e'
      # combined # Sum: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay/Sum3
      # combined # Product: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay/Divide1
      ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay/Divide1: folded operation division to cons
      tant value 0.001 */
   Aux__e = (((SInt32) Aux_I16_b) * 10) >= ((SInt32) (SInt16) (((UInt16) (SInt16) (((SInt16)
    (Aux_I16 * 10)) + 1 /* 0.001 */)) - 10));

   /* Switch: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay/Switch2
      ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay/Switch2: Omitted comparison with constant.
    */
   if (!(Aux__c)) {
      /* Variable 'S01212_Switch2' replaced by 'Aux__f' */
      Aux__f = Aux__e && (!(X_S01223_UnitDelay));
   }
   else {
      /* Variable 'S01212_Switch2' replaced by 'Aux__f' */
      Aux__f = 1 /* 1. */;
   }

   /* Variable 'S01219_Logical_Operator5' replaced by 'Aux__g' */
   Aux__g = (!(MgtASE_bAltRstrtTypASEReq_MP)) || ((!(Aux__f)) && X_S01219_Unit_Delay);
   Aux_U8 = MgtASE_tiCdnInhRstrt_C;

   /* MinMax: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay1/MinMax1 */
   if (Aux_U8) {
      /* Variable 'S01213_MinMax1' replaced by 'Aux_I8' */
      Aux_I8 = (SInt8) Aux_U8;
   }
   else {
      /* Variable 'S01213_MinMax1' replaced by 'Aux_I8' */
      Aux_I8 = 0 /* 0. */;
   }

   /* Variable 'S01213_Relational_Operator1' replaced by 'Aux__f' */
   Aux__f = Aux_I8 == 0 /* 0. */;

   /* Sum: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay1/Sum2
      Variable 'S01213_Sum2' replaced by 'Aux_I8_a'
      # combined # Product: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay1/Divide2
      ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay1/Divide2: folded operation multiplication 
      to constant value 0.1 */
   Aux_I8_a = (SInt8) (Aux_I8 + 10 /* 0.1 */);

   /* Switch: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay1/Turnondelay_Part/Switch1
      ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay1/Turnondelay_Part/Switch1: Omitted compari
      son with constant. */
   if (X_S01213_Unit_Delay || ((!(Aux__g)) && (!(X_S01227_UnitDelay)))) {
      /* Variable 'S01226_Switch1' replaced by 'Aux_I8_b' */
      Aux_I8_b = 0 /* 0. */;
   }
   else {
      /* SLLocal: Default storage class for local variables | Width: 8 */
      SInt8 Aux_I8_c /* LSB: 0.01 OFF:  0 MIN/MAX:  -1.28 .. 1.27 */;
      SInt8 Aux_I8_d /* LSB: 0.01 OFF:  0 MIN/MAX:  -1.28 .. 1.27 */;

      /* MinMax: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay1/DetectSat/MinMax1 */
      if (X_S01213_UnitDelay1 > 0) {
         /* Variable 'S01225_MinMax1' replaced by 'Aux_I8_c' */
         Aux_I8_c = X_S01213_UnitDelay1;
      }
      else {
         /* Variable 'S01225_MinMax1' replaced by 'Aux_I8_c' */
         Aux_I8_c = 0 /* 0. */;
      }

      /* MinMax: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay1/DetectSat/MinMax2 */
      if (Aux_I8_a < Aux_I8_c) {
         /* Variable 'S01225_MinMax2' replaced by 'Aux_I8_d' */
         Aux_I8_d = Aux_I8_a;
      }
      else {
         /* Variable 'S01225_MinMax2' replaced by 'Aux_I8_d' */
         Aux_I8_d = Aux_I8_c;
      }

      /* # combined # Sum: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay1/Sum1
         Variable 'S01226_Switch1' replaced by 'Aux_I8_b' */
      Aux_I8_b = (SInt8) (((UInt8) Aux_I8_d) + 1);
   }

   /* Variable 'S01213_Relational_Operator2' replaced by 'Aux__h'
      # combined # Sum: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay1/Sum3
      # combined # Product: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay1/Divide1
      ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay1/Divide1: folded operation division to con
      stant value 0.001 */
   Aux__h = (((SInt16) Aux_I8_b) * 10) >= ((SInt16) (((UInt16) (SInt16) (((SInt16) (((SInt16)
    Aux_I8) * 10)) + 1 /* 0.001 */)) - 10));

   /* Switch: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay1/Switch2
      ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay1/Switch2: Omitted comparison with constant
      . */
   if (!(Aux__f)) {
      /* Variable 'S01213_Switch2' replaced by 'Aux__i' */
      Aux__i = Aux__h && (!(X_S01228_UnitDelay));
   }
   else {
      /* Variable 'S01213_Switch2' replaced by 'Aux__i' */
      Aux__i = 1 /* 1. */;
   }

   /* Variable 'S01224_Logical_Operator5' replaced by 'Aux__j' */
   Aux__j = Aux__g || ((!(Aux__i)) && X_S01224_Unit_Delay);
   Aux_U16 = MgtASE_tiDlyVSSNwEndAcv_C;

   /* MinMax: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOffDelay/MinMax1 */
   if (Aux_U16) {
      /* Variable 'S01211_MinMax1' replaced by 'Aux_I16' */
      Aux_I16 = (SInt16) Aux_U16;
   }
   else {
      /* Variable 'S01211_MinMax1' replaced by 'Aux_I16' */
      Aux_I16 = 0 /* 0. */;
   }

   /* Variable 'S01211_Relational_Operator1' replaced by 'Aux__i' */
   Aux__i = Aux_I16 == 0 /* 0. */;

   /* Sum: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOffDelay/Sum2
      Variable 'S01211_Sum2' replaced by 'Aux_I16_a'
      # combined # Product: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOffDelay/Divide2
      ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOffDelay/Divide2: folded operation multiplication 
      to constant value 0.1 */
   Aux_I16_a = (SInt16) (Aux_I16 + 10 /* 0.1 */);

   /* Switch: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOffDelay/Turnoffdelay_Part/Switch1
      ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOffDelay/Turnoffdelay_Part/Switch1: Omitted compar
      ison with constant. */
   if (X_S01211_Unit_Delay || ((!(MgtASE_bAltRstrtTypASEReq_MP)) && X_S01217_UnitDelay)) {
      /* Variable 'S01216_Switch1' replaced by 'Aux_I16_c' */
      Aux_I16_c = 0 /* 0. */;
   }
   else {
      /* SLLocal: Default storage class for local variables | Width: 16 */
      SInt16 Aux_I16_e /* LSB: 0.01 OFF:  0 MIN/MAX:  -327.68 .. 327.67 */;

      /* MinMax: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOffDelay/DetectSat/MinMax1 */
      if (X_S01211_UnitDelay1 > 0) {
         /* Variable 'S01215_MinMax1' replaced by 'Aux_I16_d' */
         Aux_I16_d = X_S01211_UnitDelay1;
      }
      else {
         /* Variable 'S01215_MinMax1' replaced by 'Aux_I16_d' */
         Aux_I16_d = 0 /* 0. */;
      }

      /* MinMax: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOffDelay/DetectSat/MinMax2 */
      if (Aux_I16_a < Aux_I16_d) {
         /* Variable 'S01215_MinMax2' replaced by 'Aux_I16_e' */
         Aux_I16_e = Aux_I16_a;
      }
      else {
         /* Variable 'S01215_MinMax2' replaced by 'Aux_I16_e' */
         Aux_I16_e = Aux_I16_d;
      }

      /* # combined # Sum: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOffDelay/Sum1
         Variable 'S01216_Switch1' replaced by 'Aux_I16_c' */
      Aux_I16_c = (SInt16) (((UInt16) Aux_I16_e) + 1);
   }

   /* Variable 'S01211_Relational_Operator2' replaced by 'Aux__k'
      # combined # Sum: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOffDelay/Sum3
      # combined # Product: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOffDelay/Divide1
      ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOffDelay/Divide1: folded operation division to con
      stant value 0.001 */
   Aux__k = (((SInt32) Aux_I16_c) * 10) >= ((SInt32) (SInt16) (((UInt16) (SInt16) (((SInt16)
    (Aux_I16 * 10)) + 1 /* 0.001 */)) - 10));

   /* Switch: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOffDelay/Switch2
      ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOffDelay/Switch2: Omitted comparison with constant
      . */
   if (!(Aux__i)) {
      /* Variable 'S01211_Switch2' replaced by 'Aux__l' */
      Aux__l = Aux__k && (!(X_S01218_UnitDelay));
   }
   else {
      /* Variable 'S01211_Switch2' replaced by 'Aux__l' */
      Aux__l = 1 /* 1. */;
   }

   /* Variable 'S01214_Logical_Operator5' replaced by 'Aux__m' */
   Aux__m = MgtASE_bAltRstrtTypASEReq_MP || ((!(Aux__l)) && X_S01214_Unit_Delay);

   /* Switch: ASE_012/F02_Gestion_Dde_Redem_SCAr_MTh/BasculeRS/Switch
      ASE_012/F02_Gestion_Dde_Redem_SCAr_MTh/BasculeRS/Switch: Omitted comparison with constant. */
   if (X_S0129_Unit_Delay1) {
      /* Multiport switch: ASE_012/F01_Traitement_booleen/Traitement_booleen3/MgtASE_bEngStrtSuc_vis
         u */
      switch (MgtASE_stModEngRstrtClsCluCdn_C) {
         case 0: {
            MgtASE_bEngRstrtClsCluCdn = ASE_012_CoPtUH_bEngRstrtClsCluCdn_in;
            break;
         }
         case 1: {
            MgtASE_bEngRstrtClsCluCdn = !(ASE_012_CoPtUH_bEngRstrtClsCluCdn_in);
            break;
         }
         case 2: {
            MgtASE_bEngRstrtClsCluCdn = 0 /* 0. */;
            break;
         }
         case 3: {
            MgtASE_bEngRstrtClsCluCdn = 1 /* 1. */;
            break;
         }
      }

      /* Variable 'S0123_Logical_Operator3' replaced by 'Aux__l' */
      Aux__l = (ASE_012_CoPtASE_stPwt_in == 6 /* 6. */) && (!(ASE_012_CoPtASE_bEngCutOffReq_in)) &&
       (!(ASE_012_CoPtASE_bEngStallReq_in));
      MgtASE_bEngRstrtTypASEReq_MP = ((ASE_012_CoEmCkg_stStrtRstrtFbCmd_in == 1 /* 1. */) ||
       MgtASE_bEngRstrtAutnAvl || MgtASE_bRstrtAutnAvlPARM || MgtASE_bEngRstrtClsCluCdn) && Aux__l;

      /* Variable 'S0129_Switch' replaced by 'Aux__n' */
      Aux__n = (MgtASE_bEngRstrtTypASEReq_MP && Aux__l) || ((!(MgtASE_bEngRstrtTypASEReq_MP)) &&
       Aux__l && X_S0129_Unit_Delay);
   }
   else {
      /* Variable 'S0129_Switch' replaced by 'Aux__n' */
      Aux__n = 0 /* 0. */;
   }

   /* TargetLink outport: ASE_012/CoPtASE_bVSSNwAcvAuth_out */
   CoPtASE_bVSSNwAcvAuth_out = Aux__m;
   CoPtASE_bCdnInhRStrt_out = Aux__j;

   /* TargetLink outport: ASE_012/CoPtASE_bAltRStrtTypASEReq_out */
   CoPtASE_bAltRStrtTypASEReq_out = !(Aux__g);

   /* TargetLink outport: ASE_012/CoPtASE_bEngRStrtTypASEReq_out */
   CoPtASE_bEngRStrtTypASEReq_out = Aux__n;

   /* Unit delay: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/BasculeRS/Unit Delay1 */
   X_S01210_Unit_Delay1 = 1 /* 1. */;

   /* Unit delay: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/BasculeRS/Unit Delay */
   X_S01210_Unit_Delay = Aux__d;

   /* Unit delay: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay/Unit Delay */
   X_S01212_Unit_Delay = Aux__c;

   /* Unit delay: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay/rising_edge/UnitDelay */
   X_S01222_UnitDelay = MgtASE_bAltRstrtTypASEReq_MP;

   /* Unit delay: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay/UnitDelay1 */
   X_S01212_UnitDelay1 = Aux_I16_b;

   /* Unit delay: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay/rising_edge2/UnitDelay */
   X_S01223_UnitDelay = Aux__e;

   /* Unit delay: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay/BasculeRSspecifique/Unit Delay
    */
   X_S01219_Unit_Delay = Aux__g;

   /* Unit delay: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay1/Unit Delay */
   X_S01213_Unit_Delay = Aux__f;

   /* Unit delay: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay1/rising_edge/UnitDelay */
   X_S01227_UnitDelay = !(Aux__g);

   /* Unit delay: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay1/UnitDelay1 */
   X_S01213_UnitDelay1 = Aux_I8_b;

   /* Unit delay: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay1/rising_edge2/UnitDelay */
   X_S01228_UnitDelay = Aux__h;

   /* Unit delay: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOnDelay1/BasculeRSspecifique/Unit Dela
      y */
   X_S01224_Unit_Delay = Aux__j;

   /* Unit delay: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOffDelay/Unit Delay */
   X_S01211_Unit_Delay = Aux__i;

   /* Unit delay: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOffDelay/falling_edge/UnitDelay */
   X_S01217_UnitDelay = MgtASE_bAltRstrtTypASEReq_MP;

   /* Unit delay: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOffDelay/UnitDelay1 */
   X_S01211_UnitDelay1 = Aux_I16_c;

   /* Unit delay: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOffDelay/rising_edge2/UnitDelay */
   X_S01218_UnitDelay = Aux__k;

   /* Unit delay: ASE_012/F03_Gestion_Dde_Redem_SCAr_SEEM/TurnOffDelay/BasculeRSspecifique/Unit Dela
      y */
   X_S01214_Unit_Delay = Aux__m;

   /* Unit delay: ASE_012/F02_Gestion_Dde_Redem_SCAr_MTh/BasculeRS/Unit Delay1 */
   X_S0129_Unit_Delay1 = 1 /* 1. */;

   /* Unit delay: ASE_012/F02_Gestion_Dde_Redem_SCAr_MTh/BasculeRS/Unit Delay */
   X_S0129_Unit_Delay = Aux__n;
}

#define ASE_STOP_SEC_CODE
#include "ASE_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      ASE_012_FctVarInit
 *** 
 ***  DESCRIPTION:
 ***      AR_INTERNAL_VAR_DISP_BOOLEAN
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

#define ASE_START_SEC_CODE
#include "ASE_MemMap.h"
Void ASE_012_FctVarInit(Void)
{
   X_S01210_Unit_Delay = 0 /* 0. */;
   X_S01210_Unit_Delay1 = 0 /* 0. */;
   X_S01211_UnitDelay1 = 0 /* 0. */;
   X_S01211_Unit_Delay = 0 /* 0. */;
   X_S01212_UnitDelay1 = 0 /* 0. */;
   X_S01212_Unit_Delay = 0 /* 0. */;
   X_S01213_UnitDelay1 = 0 /* 0. */;
   X_S01213_Unit_Delay = 0 /* 0. */;
   X_S01214_Unit_Delay = 0 /* 0. */;
   X_S01217_UnitDelay = 0 /* 0. */;
   X_S01218_UnitDelay = 0 /* 0. */;
   X_S01219_Unit_Delay = 0 /* 0. */;
   X_S01222_UnitDelay = 0 /* 0. */;
   X_S01223_UnitDelay = 0 /* 0. */;
   X_S01224_Unit_Delay = 0 /* 0. */;
   X_S01227_UnitDelay = 0 /* 0. */;
   X_S01228_UnitDelay = 0 /* 0. */;
   X_S0129_Unit_Delay = 0 /* 0. */;
   X_S0129_Unit_Delay1 = 0 /* 0. */;
}

#define ASE_STOP_SEC_CODE
#include "ASE_MemMap.h"

/*----------------------------------------------------------------------------*\
  MODULE LOCAL FUNCTION DEFINITIONS
\*----------------------------------------------------------------------------*/

#endif/*_ASE_012_TEV_FCT_C_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
