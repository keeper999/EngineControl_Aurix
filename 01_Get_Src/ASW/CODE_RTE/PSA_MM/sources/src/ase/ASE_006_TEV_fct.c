/**************************************************************************************************\
 *** 
 *** Simulink model       : CoASEPwt_01460_10_02172_TL
 *** TargetLink subsystem : CoASEPwt_01460_10_02172_TL/ASE_006
 *** Codefile             : ase_006_tev_fct.c
 ***
 *** Generated by TargetLink, the dSPACE production quality code generator
 *** Generation date: 2011-05-20 10:16:58
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
 *** S0061                    CoASEPwt_01460_10_02172_TL/ASE_006
 *** S0062                    ASE_006/F01_Traitement_booleen
 *** S0063                    ASE_006/F02_Calcul_Transitions_Etat_GMP_SCAr
 *** S0064                    ASE_006/F03_Calcul_Etats_GMP
 *** S0065                    ASE_006/F01_Traitement_booleen/Traitement_booleen
 *** S0066                    ASE_006/F01_Traitement_booleen/Traitement_booleen1
 *** 
 *** SF-NODE   CORRESPONDING STATEFLOW NODE                           DESCRIPTION
 *** C0060     CoASEPwt_01460_10_02172_TL                             
 *** C0061     ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_GMP 
 *** C0062     ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_GMP
 ***           .Off                                                   
 *** C0063     ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_GMP
 ***           .On                                                    
 *** C0064     ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_GMP
 ***           .On.Sortie_calage                                      
 *** C0065     ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_GMP
 ***           .On.Calage_en_cours                                    
 *** C0066     ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_GMP
 ***           .On.Cale                                               
 *** C0067     ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_GMP
 ***           .Coupure_en_cours                                      
 *** 
 *** TargetLink version      : 3.0.1 from 26-May-2009
 *** Code generator version  : Build Id 3.0.1.7 from 2009-May-06 15:28:18
 *** Copyright (c) 2006 dSPACE GmbH
\**************************************************************************************************/

#ifndef _ASE_006_TEV_FCT_C_
#define _ASE_006_TEV_FCT_C_

/*----------------------------------------------------------------------------*\
  DEFINES (OPT)
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  INCLUDES
\*----------------------------------------------------------------------------*/
#include "ASE_006_TEV_fct.h"
#include "ASE_006_calibrations.h"
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
AR_IF_GLOBAL_8BIT UInt8 ASE_006_CoPTStNew_stEng_in /* 
   Description: Nouvel �tat moteur
   LSB: 2^0 OFF:  0 MIN/MAX:  1 .. 9 */;
AR_IF_GLOBAL_8BIT UInt8 CoPtASE_stPwt_out /* 
   Description: Etat_GMP_SCAr
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 10 */;

#define ASE_STOP_SEC_GLOBAL_8BIT
#include "ASE_MemMap.h"

#define ASE_START_SEC_GLOBAL_BOOLEAN
#include "ASE_MemMap.h"

/******************************************************************************\
   AR_IF_GLOBAL_BOOLEAN: Global boolean for AUTOSAR modules | Width: 8
\******************************************************************************/
AR_IF_GLOBAL_BOOLEAN Boolean ASE_006_CoPtASE_bEngCutOffReq_in /* 
   Description: Demande de coupure du moteur thermique par la fonction Sortie Calage (A1 : Dde_Coupu
   re_SCAr_MTh)
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
AR_IF_GLOBAL_BOOLEAN Boolean ASE_006_CoPtASE_bEngStallReq_in /* 
   Description: Demande de calage venant de la fonction Sortie Calage (A1 : Dde_Calage_MTh)
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
AR_IF_GLOBAL_BOOLEAN Boolean ASE_006_CoSync_bDetNNull_in /* 
   Description: D�tection d'un r�gime nul
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
AR_IF_GLOBAL_BOOLEAN Boolean ASE_006_FRM_bAcvRunCoPtASE_in /* 
   Description: Reconfiguration for�ant le mode alternateur
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
AR_IF_GLOBAL_BOOLEAN Boolean RE_ASE_006_TEV_CoASE_bEngASEReqVld_in /* 
   Description: Demande de sortie calage valid�e
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
AR_IF_GLOBAL_BOOLEAN Boolean RE_ASE_006_TEV_CoStall_bEngStallAuth_in /* 
   Description: Autorisation d'entrer dans la fonction Sortie calage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
AR_IF_GLOBAL_BOOLEAN Boolean RE_ASE_006_TEV_CoStall_bEngStallReq_in /* 
   Description: Demande d'entr�e dans la fonction Sortie calage
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
AR_IF_GLOBAL_BOOLEAN Boolean RE_ASE_006_TEV_MgtStall_bEngASEEndTi_in /* 
   Description: Red�marrage en SCAr trop long
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;

#define ASE_STOP_SEC_GLOBAL_BOOLEAN
#include "ASE_MemMap.h"

#define ASE_START_SEC_VAR_8BIT
#include "ASE_MemMap.h"

/******************************************************************************\
   UserSFStaticGlobalInit: SFStaticGlobalInit = { AR_SEC_VAR_BOOLEAN AR_SEC_UNSPECIFIED AR_SEC_VAR_8
   BIT AR_SEC_VAR_16BIT AR_SEC_VAR_32BIT AR_SEC_UNSPECIFIED } | Width: 8
\******************************************************************************/
static UInt8 C0061_CoPtASE_stPwt /* LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 10 */;

#define ASE_STOP_SEC_VAR_8BIT
#include "ASE_MemMap.h"

#define ASE_START_SEC_VAR_UNSPECIFIED
#include "ASE_MemMap.h"

/******************************************************************************\
   UserSFStaticGlobal: SFStaticGlobal = { AR_SEC_VAR_BOOLEAN AR_SEC_UNSPECIFIED AR_SEC_VAR_8BIT AR_S
   EC_VAR_16BIT AR_SEC_VAR_32BIT AR_SEC_UNSPECIFIED } | Width: N.A.
\******************************************************************************/
static struct tag_SBFS_F03_01_Automate_Etats_GMP_006_tp SBFS_F03_01_Au__e_Etats_GMP_006 /* Descripti
   on: Structure containing bitfields for Stateflow chart  */;

#define ASE_STOP_SEC_VAR_UNSPECIFIED
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
 ***      ASE_005_MSE_ini
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
Void ASE_005_MSE_ini(Void)
{
   ASE_006_FctVarInit();
}

#define ASE_STOP_SEC_CODE
#include "ASE_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      ASE_006_TEV_fct
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
Void ASE_006_TEV_fct(Void)
{
   /* SLLocal: Default storage class for local variables | Width: 8 */
   Boolean Aux_;

   /* Variable 'S0063_Logical_Operator21' replaced by 'Aux_' */
   Aux_ = RE_ASE_006_TEV_CoASE_bEngASEReqVld_in && (!(RE_ASE_006_TEV_MgtStall_bEngASEEndTi_in));

   /* Multiport switch: ASE_006/F01_Traitement_booleen/Traitement_booleen/CoASEPwt_bDetNNull_visu */
   switch (CoASEPwt_stModDetNNull_C) {
      case 0: {
         CoASEPwt_bDetNNull = ASE_006_CoSync_bDetNNull_in;
         break;
      }
      case 1: {
         CoASEPwt_bDetNNull = !(ASE_006_CoSync_bDetNNull_in);
         break;
      }
      case 2: {
         CoASEPwt_bDetNNull = 0 /* 0. */;
         break;
      }
      case 3: {
         CoASEPwt_bDetNNull = 1 /* 1. */;
         break;
      }
   }

   /* Multiport switch: ASE_006/F01_Traitement_booleen/Traitement_booleen1/CoASEPwt_bAcvRunCoPtASE_v
      isu */
   switch (CoASEPwt_stModAcvRun_C) {
      case 0: {
         CoASEPwt_bAcvRunCoPtASE = ASE_006_FRM_bAcvRunCoPtASE_in;
         break;
      }
      case 1: {
         CoASEPwt_bAcvRunCoPtASE = !(ASE_006_FRM_bAcvRunCoPtASE_in);
         break;
      }
      case 2: {
         CoASEPwt_bAcvRunCoPtASE = 0 /* 0. */;
         break;
      }
      case 3: {
         CoASEPwt_bAcvRunCoPtASE = 1 /* 1. */;
         break;
      }
   }

   /* Begin execution of chart ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_GMP */
   if (SBFS_F03_01_Au__e_Etats_GMP_006.C0062_Off) {
      CoASEPwt_bOffToStallIpTran = RE_ASE_006_TEV_CoStall_bEngStallAuth_in &&
       RE_ASE_006_TEV_CoStall_bEngStallReq_in && (!(ASE_006_CoPtASE_bEngCutOffReq_in)) &&
       CoASEPwt_bTranOffToStallIp_C;

      /* Begin execution of state ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_GMP.Off */
      if (CoASEPwt_bOffToStallIpTran && (!(CoASEPwt_bAcvRunCoPtASE))) {
         /* State transition from ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_GMP.Off to ASE_
            006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_GMP.On.Calage_en_cours */
         SBFS_F03_01_Au__e_Etats_GMP_006.C0062_Off = 0;
         SBFS_F03_01_Au__e_Etats_GMP_006.C0063_On = 1;
         SBFS_F03_01_Au__e_Etats_GMP_006.C0065_Calage_en_cours = 1;
         C0061_CoPtASE_stPwt = 2 /* 2. */;
      }

      /* End execution of state ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_GMP.Off */
   }
   else {
      if (SBFS_F03_01_Au__e_Etats_GMP_006.C0063_On) {
         /* Begin execution of state ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_GMP.On */

         /* ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_GMP: Omitted comparison with constant
            . */
         if ((ASE_006_CoPTStNew_stEng_in == 1) || CoASEPwt_bAcvRunCoPtASE) {
            /* State transition from ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_GMP.On to AS
               E_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_GMP.Off */
            if (SBFS_F03_01_Au__e_Etats_GMP_006.C0064_Sortie_calage) {
               SBFS_F03_01_Au__e_Etats_GMP_006.C0064_Sortie_calage = 0;
            }
            else {
               if (SBFS_F03_01_Au__e_Etats_GMP_006.C0065_Calage_en_cours) {
                  SBFS_F03_01_Au__e_Etats_GMP_006.C0065_Calage_en_cours = 0;
               }
               else {
                  SBFS_F03_01_Au__e_Etats_GMP_006.C0066_Cale = 0;
               }
            }
            SBFS_F03_01_Au__e_Etats_GMP_006.C0063_On = 0;
            SBFS_F03_01_Au__e_Etats_GMP_006.C0062_Off = 1;
            C0061_CoPtASE_stPwt = 1 /* 1. */;
         }
         else {
            CoASEPwt_bOnToCutIpTran = ASE_006_CoPtASE_bEngCutOffReq_in && CoASEPwt_bTranOnToCutIp_C;
            if (CoASEPwt_bOnToCutIpTran) {
               /* State transition from ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_GMP.On to
                   ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_GMP.Coupure_en_cours */
               if (SBFS_F03_01_Au__e_Etats_GMP_006.C0064_Sortie_calage) {
                  SBFS_F03_01_Au__e_Etats_GMP_006.C0064_Sortie_calage = 0;
               }
               else {
                  if (SBFS_F03_01_Au__e_Etats_GMP_006.C0065_Calage_en_cours) {
                     SBFS_F03_01_Au__e_Etats_GMP_006.C0065_Calage_en_cours = 0;
                  }
                  else {
                     SBFS_F03_01_Au__e_Etats_GMP_006.C0066_Cale = 0;
                  }
               }
               SBFS_F03_01_Au__e_Etats_GMP_006.C0063_On = 0;
               SBFS_F03_01_Au__e_Etats_GMP_006.C0067_Coupure_en_cours = 1;
               C0061_CoPtASE_stPwt = 8 /* 8. */;
            }
            else {
               if (SBFS_F03_01_Au__e_Etats_GMP_006.C0064_Sortie_calage) {
                  /* Begin execution of state ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_GMP
                     .On.Sortie_calage */
                  if (ASE_006_CoPTStNew_stEng_in == 5) {
                     /* State transition from ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_GMP
                        .On.Sortie_calage to ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_GMP.
                        Off */
                     SBFS_F03_01_Au__e_Etats_GMP_006.C0064_Sortie_calage = 0;
                     SBFS_F03_01_Au__e_Etats_GMP_006.C0063_On = 0;
                     SBFS_F03_01_Au__e_Etats_GMP_006.C0062_Off = 1;
                     C0061_CoPtASE_stPwt = 1 /* 1. */;
                  }
                  else {
                     CoASEPwt_bASEToStallIpTran = ASE_006_CoPtASE_bEngStallReq_in &&
                      RE_ASE_006_TEV_CoStall_bEngStallAuth_in &&
                      (!(ASE_006_CoPtASE_bEngCutOffReq_in)) && CoASEPwt_bTranASEToStallIp_C;
                     if (CoASEPwt_bASEToStallIpTran) {
                        /* State transition from ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_
                           GMP.On.Sortie_calage to ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etat
                           s_GMP.On.Calage_en_cours */
                        SBFS_F03_01_Au__e_Etats_GMP_006.C0064_Sortie_calage = 0;
                        SBFS_F03_01_Au__e_Etats_GMP_006.C0065_Calage_en_cours = 1;
                        C0061_CoPtASE_stPwt = 2 /* 2. */;
                     }
                  }

                  /* End execution of state ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_GMP.O
                     n.Sortie_calage */
               }
               else {
                  if (SBFS_F03_01_Au__e_Etats_GMP_006.C0065_Calage_en_cours) {
                     CoASEPwt_bStallIpToStallTran = (!(Aux_)) && CoASEPwt_bDetNNull &&
                      (!(ASE_006_CoPtASE_bEngCutOffReq_in)) && CoASEPwt_bTranStallIpToStall_C;

                     /* Begin execution of state ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_
                        GMP.On.Calage_en_cours */
                     if (CoASEPwt_bStallIpToStallTran) {
                        /* State transition from ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_
                           GMP.On.Calage_en_cours to ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Et
                           ats_GMP.On.Cale */
                        SBFS_F03_01_Au__e_Etats_GMP_006.C0065_Calage_en_cours = 0;
                        SBFS_F03_01_Au__e_Etats_GMP_006.C0066_Cale = 1;
                        C0061_CoPtASE_stPwt = 4 /* 4. */;
                     }
                     else {
                        CoASEPwt_bStallIpToASETran = Aux_ && (!(ASE_006_CoPtASE_bEngCutOffReq_in))
                         && CoASEPwt_bTranStallIpToASE_C;
                        if (CoASEPwt_bStallIpToASETran) {
                           /* State transition from ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Eta
                              ts_GMP.On.Calage_en_cours to ASE_006/F03_Calcul_Etats_GMP/F03_01_Autom
                              ate_Etats_GMP.On.Sortie_calage */
                           SBFS_F03_01_Au__e_Etats_GMP_006.C0065_Calage_en_cours = 0;
                           SBFS_F03_01_Au__e_Etats_GMP_006.C0064_Sortie_calage = 1;
                           C0061_CoPtASE_stPwt = 6 /* 6. */;
                        }
                     }

                     /* End execution of state ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_GM
                        P.On.Calage_en_cours */
                  }
                  else {
                     if (SBFS_F03_01_Au__e_Etats_GMP_006.C0066_Cale) {
                        CoASEPwt_bStallToASETran = RE_ASE_006_TEV_CoASE_bEngASEReqVld_in &&
                         (!(ASE_006_CoPtASE_bEngCutOffReq_in)) && CoASEPwt_bTranStallToASE_C;

                        /* Begin execution of state ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Eta
                           ts_GMP.On.Cale */
                        if (CoASEPwt_bStallToASETran) {
                           /* State transition from ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Eta
                              ts_GMP.On.Cale to ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_G
                              MP.On.Sortie_calage */
                           SBFS_F03_01_Au__e_Etats_GMP_006.C0066_Cale = 0;
                           SBFS_F03_01_Au__e_Etats_GMP_006.C0064_Sortie_calage = 1;
                           C0061_CoPtASE_stPwt = 6 /* 6. */;
                        }

                        /* End execution of state ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats
                           _GMP.On.Cale */
                     }
                  }
               }
            }
         }

         /* End execution of state ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_GMP.On */
      }
      else {
         if (SBFS_F03_01_Au__e_Etats_GMP_006.C0067_Coupure_en_cours) {
            /* Begin execution of state ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_GMP.Coupu
               re_en_cours */

            /* ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_GMP: Omitted comparison with const
               ant. */
            if ((ASE_006_CoPTStNew_stEng_in == 1) || CoASEPwt_bAcvRunCoPtASE) {
               /* State transition from ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_GMP.Coupu
                  re_en_cours to ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_GMP.Off */
               SBFS_F03_01_Au__e_Etats_GMP_006.C0067_Coupure_en_cours = 0;
               SBFS_F03_01_Au__e_Etats_GMP_006.C0062_Off = 1;
               C0061_CoPtASE_stPwt = 1 /* 1. */;
            }

            /* End execution of state ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_GMP.Coupure
               _en_cours */
         }
         else {
            /* State transition to ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_GMP.Off */
            SBFS_F03_01_Au__e_Etats_GMP_006.C0062_Off = 1;
            C0061_CoPtASE_stPwt = 1 /* 1. */;
         }
      }
   }

   /* End execution of chart ASE_006/F03_Calcul_Etats_GMP/F03_01_Automate_Etats_GMP */

   /* TargetLink outport: ASE_006/CoPtASE_stPwt_out */
   CoPtASE_stPwt_out = C0061_CoPtASE_stPwt;
}

#define ASE_STOP_SEC_CODE
#include "ASE_MemMap.h"

/**************************************************************************************************\
 ***  FUNCTION:
 ***      ASE_006_FctVarInit
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
Void ASE_006_FctVarInit(Void)
{
   C0061_CoPtASE_stPwt = 0 /* 0. */;
   SBFS_F03_01_Au__e_Etats_GMP_006.C0062_Off = 0 /* 0. */;
   SBFS_F03_01_Au__e_Etats_GMP_006.C0063_On = 0 /* 0. */;
   SBFS_F03_01_Au__e_Etats_GMP_006.C0064_Sortie_calage = 0 /* 0. */;
   SBFS_F03_01_Au__e_Etats_GMP_006.C0065_Calage_en_cours = 0 /* 0. */;
   SBFS_F03_01_Au__e_Etats_GMP_006.C0066_Cale = 0 /* 0. */;
   SBFS_F03_01_Au__e_Etats_GMP_006.C0067_Coupure_en_cours = 0 /* 0. */;
}

#define ASE_STOP_SEC_CODE
#include "ASE_MemMap.h"

/*----------------------------------------------------------------------------*\
  MODULE LOCAL FUNCTION DEFINITIONS
\*----------------------------------------------------------------------------*/

#endif/*_ASE_006_TEV_FCT_C_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
