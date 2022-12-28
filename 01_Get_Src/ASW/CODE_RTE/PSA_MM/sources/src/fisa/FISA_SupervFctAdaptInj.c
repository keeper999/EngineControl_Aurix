/******************************************************************************/
/*                                                                            */
/* !Layer :                 APPLI                                             */
/*                                                                            */
/* !Component :             FISA                                              */
/* !Description :                                                             */
/*                                                                            */
/* !Module :                FISA_SupervFctAdaptInj                            */
/* !Description :           Superviseur de la fonction d'adaptation de        */
/*                          l'injection au demarrage                          */
/* !File :                  FISA_SupervFctAdaptInj.c                          */
/*                                                                            */
/* !Scope :                 Public                                            */
/*                                                                            */
/* !Target :                All                                               */
/*                                                                            */
/* !Vendor :                Valeo                                             */
/*                                                                            */
/* Coding language :  C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/LIBPSA/LOG/Ref/SWC_VEMS/FISA/LOG/FISA_SupervFctAdaptInj.c_v          $*/
/* $Revision::   1.19      $$Author::   flavergn$$Date::   21 Jul 2010 15:$*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/
/*FISA_SupervInit                                                             */
/*FISA_Sup_Action_Etat_M_Strat                                                */
/*FISA_Sup_Step_M_Analyse                                                     */
/*FISA_Sup_Step_M_Correction                                                  */
/*FISA_Sup_Step_M_Analyse_Discriminante                                       */
/*FISA_Sup_Step_M_Inst                                                        */
/*FISA_Sup_Step_M_Confirmation_FR                                             */
/*FISA_Sup_Action_Etat_M_Analyse_Discriminante                                */
/*FISA_Sup_Transition_M_Analyse_Discriminante                                 */
/*FISA_Sup_Step_M_Strategie_Active                                            */
/*FISA_Sup_Transition_M_Strategie_Active                                      */
/*FISA_Sup_Action_Etat_M_Strat_Active                                         */
/*FISA_Sup_Transition_M_Strategie                                             */
/*FISA_Sup_Action_Etat_M_Analyse                                              */
/*FISA_Sup_Transition_M_Analyse                                               */
/*FISA_Sup_Action_Etat_M_Inst                                                 */
/*FISA_Sup_Transition_M_Inst                                                  */
/*FISA_Sup_Action_Etat_M_Confirmation_FR                                      */
/*FISA_Sup_Transition_M_Confirmation_FR                                       */
/*FISA_Sup_Action_Etat_M_Correction                                           */
/*FISA_Sup_Transition_M_Correction                                            */
/*FISA_SetDefaultOutPuts                                                      */
/******************************************************************************/
/******************************************************************************/
/* INCLUSIONS                                                                 */
/******************************************************************************/

#include "FISA_SupervFctAdaptInj.h"
#include "FISA_Runnables.h"

/******************************************************************************/
/* DECLARATION OF GLOBAL VARIABLES                                            */
/******************************************************************************/

#define FISA_START_SEC_VAR_BOOLEAN
#include "FISA_MemMap.h"

VAR(Boolean,FISA_VAR) FISA_bAuthClc;

#define FISA_STOP_SEC_VAR_BOOLEAN
#include "FISA_MemMap.h"

#define FISA_START_SEC_VAR_8BIT
#include "FISA_MemMap.h"

VAR(UInt8,FISA_VAR)   FISA_idxIniPoor;
VAR(UInt8,FISA_VAR)   FISA_idxIniOld;
VAR(UInt8,FISA_VAR)   FISA_idxFacPoor;
VAR(UInt8,FISA_VAR)   FISA_idxIniRich;
VAR(UInt8,FISA_VAR)   FISA_idxFacRich;
VAR(UInt8,FISA_VAR)   FISA_idxTypFac;
VAR(UInt8,FISA_VAR)   FISA_idxFacCur;
VAR(UInt8,FISA_VAR)   FISA_idxIniRst;
VAR(UInt8,FISA_VAR)   FISA_idxTypIni;

#define FISA_STOP_SEC_VAR_8BIT
#include "FISA_MemMap.h"


#define FISA_START_SEC_VAR_16BIT
#include "FISA_MemMap.h"

VAR(SInt16,FISA_VAR) Etat_Courant_M_Strategie;
VAR(SInt16,FISA_VAR) Etat_Courant_M_Strategie_Active;
VAR(SInt16,FISA_VAR) Etat_Courant_M_Analyse;
VAR(SInt16,FISA_VAR) Etat_Courant_M_Analyse_Discriminante;
VAR(SInt16,FISA_VAR) Etat_Courant_M_Inst;
VAR(SInt16,FISA_VAR) Etat_Courant_M_Confirmation_FR;
VAR(SInt16,FISA_VAR) Etat_Courant_M_Correction;
VAR(UInt16,FISA_VAR) FISA_tiStrtInstChk;
VAR(UInt16,FISA_VAR) FISA_tiInstChkEnd;
VAR(UInt16,FISA_VAR) FISA_nMinCrkClu;
VAR(SInt16,FISA_VAR) FISA_noIgMsk;
VAR(UInt16,FISA_VAR) FISA_nMax;

#define FISA_STOP_SEC_VAR_16BIT
#include "FISA_MemMap.h"

#define FISA_START_SEC_VAR_32BIT
#include "FISA_MemMap.h"

VAR(UInt32,FISA_VAR) Instant_Init_Analyse_Inst_MP;
VAR(UInt32,FISA_VAR) Instant_Tempo_Analyse_Inst;
VAR(UInt32,FISA_VAR) Instant_Init_Confirmation_MP;
VAR(UInt32,FISA_VAR) Temp_Courant_MP;
VAR(UInt32,FISA_VAR) Tempo_MP;
VAR(UInt32,FISA_VAR) FISA_tiAFReg;

#define FISA_STOP_SEC_VAR_32BIT
#include "FISA_MemMap.h"

#define FISA_START_SEC_CONST_UNSPECIFIED
#include "FISA_MemMap.h"

CONST(MAP_Table_1D_U8,AUTOMATIC) FISA_noInjStopAdp_map =
{
  (UInt8)FISA_TCOMES2_LENGTH     /* taille de FISA_tCoMes2_A*/,
  &(FISA_tCoMes2_A[0])           /* x_table: vector with x-values */,
  &(FISA_noInjStopAdp_T[0])      /* z_table: matrix with z-values */
};

CONST(MAP_Table_1D_U16,AUTOMATIC) FISA_tiStrtInstChk_map =
{
  (UInt8)FISA_TCOMES2_LENGTH     /* taille de FISA_tCoMes2_A*/,
  &(FISA_tCoMes2_A[0])           /* x_table: vector with x-values */,
  &(FISA_tiStrtInstChk_T[0])     /* z_table: matrix with z-values */
};

CONST(MAP_Table_1D_U16,AUTOMATIC) FISA_tiInstChkEnd_map =
{
  (UInt8)FISA_TCOMES2_LENGTH     /* taille de FISA_tCoMes2_A*/,
  &(FISA_tCoMes2_A[0])           /* x_table: vector with x-values */,
  &(FISA_tiInstChkEnd_T[0])      /* z_table: matrix with z-values */
};

CONST(MAP_Table_1D_U16,AUTOMATIC) FISA_tiAFRegChk_map =
{
  (UInt8)FISA_TCOMES2_LENGTH     /* taille de FISA_tCoMes2_A*/,
  &(FISA_tCoMes2_A[0])           /* x_table: vector with x-values */,
  &(FISA_tiAFRegChk_T[0])        /* z_table: matrix with z-values */
};

CONST(MAP_Table_1D_U16,AUTOMATIC) FISA_nMinCrk_stCluOn_map =
{
  (UInt8)FISA_TCOMES2_LENGTH     /* taille de FISA_tCoMes2_A*/,
  &(FISA_tCoMes2_A[0])           /* x_table: vector with x-values */,
  &(FISA_nMinCrk_stCluOn_T[0])   /* z_table: matrix with z-values */
};

CONST(MAP_Table_1D_U16,AUTOMATIC) FISA_nMinCrk_stCluOff_map =
{
  (UInt8)FISA_TCOMES2_LENGTH     /* taille de FISA_tCoMes2_A*/,
  &(FISA_tCoMes2_A[0])           /* x_table: vector with x-values */,
  &(FISA_nMinCrk_stCluOff_T[0])  /* z_table: matrix with z-values */
};

CONST(MAP_Table_1D_U16,AUTOMATIC) FISA_uMinGdStrt_map =
{
  (UInt8)FISA_TCOMES2_LENGTH     /* taille de FISA_tCoMes2_A*/,
  &(FISA_tCoMes2_A[0])           /* x_table: vector with x-values */,
  &(FISA_uMinGdStrt_T[0])        /* z_table: matrix with z-values */
};

CONST(MAP_Table_1D_U8,AUTOMATIC) FISA_noIgMsk_map =
{
  (UInt8)FISA_TCOMES2_LENGTH     /* taille de FISA_tCoMes2_A*/,
  &(FISA_tCoMes2_A[0])           /* x_table: vector with x-values */,
  &(FISA_noIgMsk_T[0])           /* z_table: matrix with z-values */
};

CONST(MAP_Table_2D_xU16_U16,AUTOMATIC) FISA_nMax_M_map =
{
  (UInt8)FISA_NENGRAL1_LENGTH,
  (UInt8)FISA_PAIREXTMES1_LENGTH,
  &(FISA_nEngRal1_A[0])          /* x_table: vector with x-values */,
  &(FISA_pAirExtMes1_A[0])       /* y_table: matrix with z-values */,
  &(FISA_nMax_M[0][0])           /* z_table: matrix with z-values */
};

#define FISA_STOP_SEC_CONST_UNSPECIFIED
#include "FISA_MemMap.h"



/******************************************************************************/
/* DECLARATION OF VARIABLES OF MODULE                                         */
/******************************************************************************/

/******************************************************************************/
/* DEFINITION OF GLOBAL FUNCTIONS                                             */
/******************************************************************************/
#define FISA_START_SEC_CODE
#include "FISA_MemMap.h"

_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Action_Etat_M_Strat(void);
_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Step_M_Analyse(void);
_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Step_M_Correction(void);
_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Step_M_Analyse_Discriminante(void);
_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Step_M_Inst(void);
_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Step_M_Confirmation_FR(void);
_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Action_Etat_M_Analyse_Discriminante(void);
_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Transition_M_Analyse_Discriminante(void);
_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Step_M_Strategie_Active(void);
_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Transition_M_Strategie_Active(void);
_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Action_Etat_M_Strat_Active(void);
_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Transition_M_Strategie(void);
_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Action_Etat_M_Analyse(void);
_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Transition_M_Analyse(void);
_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Action_Etat_M_Inst(void);
_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Transition_M_Inst(void);
_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Action_Etat_M_Confirmation_FR(void);
_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Transition_M_Confirmation_FR(void);
_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Action_Etat_M_Correction(void);
_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Transition_M_Correction(void);
_STATIC_ FUNC(void,FISA_CODE)    FISA_SetDefaultOutPuts(void);



/*==============================================================================
** Name:  FISA_SupervInit
** Initialisation de la machine stateflow et de ses variables internes.
**
**------------------------------------------------------------------------------
** IN: void
**------------------------------------------------------------------------------
** OUT: Boolean res // resultat d'execusion TRUE si l'initialisation s'est deroulee correctement
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
** SInt16 Ext_tCoMes
** Precision: 1    Min:  -40  Max: 214   Unit: C
**
** Boolean Ext_bCluPedPrss
** Precision: 1    Min: 0  Max: 1  Unit: ----
**
** UInt16 Ext_pAirExtMes
** Precision: 1    Min: 500  Max: 1500  Unit: mbars
**
** UInt16 TqSys_nTarIdl
** Precision: 1/4    Min:0  Max:8000  Unit:Trs/mn
**------------------------------------------------------------------------------
** RTE DataSendPoint
**------------------------------------------------------------------------------
** RTE Read IRV:
**------------------------------------------------------------------------------
** RTE Written IRV:
**
** UInt8 FISA_idxTypFac
** Precision: 1   Min:1 Max:4  Unit:----
**
** UInt8 FISA_noInjStopAdp
** Precision: 1   Min:0 Max:255  Unit:----
**============================================================================*/
/************************************************************************************/
/*                                                                                  */
/* !Reference: CSMT CGMT07 1085 V1.3                                                */
/* !Trace_To : Covers_GEENSYS_EXI_CODE_IMPL_FISA_SUPERVINIT                         */
/* !Trace_To : GEENSYS_EXI_CODE_TEST_FONCTION_TEST_SUPERVADAPINJ                    */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : Y. Didierjean (GEENSYS)                                           */
/************************************************************************************/

FUNC(void,FISA_CODE) FISA_SupervInit(void)
{
  FISA_idxIniPoor = POOR;
  FISA_idxFacPoor = POOR;
  FISA_idxIniRich = RICH;
  FISA_idxFacRich = RICH;
  FISA_idxFacCur  = CURRENT;
  FISA_idxIniRst  = CURRENT;
  FISA_idxIniOld  = OLD;
  FISA_idxTypFac  = OLD;
  FISA_idxTypIni  = OLD;

  /*initialisation des sorties a 0 (FALSE pr les booleens)*/

  FISA_Update_bAuthSave(FALSE);
  FISA_Update_bGrdWin(FALSE);
  FISA_Update_bInstWin(FALSE);
  FISA_Update_bAFRegWin(FALSE);

  Rte_IrvWrite_RE_FISA_init_idxTypFac(OLD);
  Rte_IrvWrite_RE_FISA_init_bInstWin(FALSE);
  Rte_IrvWrite_RE_FISA_init_bGrdWin(FALSE);
  Rte_IrvWrite_RE_FISA_init_bAuthClc(FALSE);
  Rte_IrvWrite_RE_FISA_init_idxTypIni(FISA_idxIniOld);
  Rte_IrvWrite_RE_FISA_init_bAFRegWin(FALSE);

   /*Initialisation etats des differentes machines*/

  Etat_Courant_M_Strategie             = ENTREE_M_Strategie;
  Etat_Courant_M_Strategie_Active      = INIT_M_Strategie_Active ;
  Etat_Courant_M_Analyse               = ENTREE_M_Analyse;
  Etat_Courant_M_Analyse_Discriminante = ENTREE_Analyse_Discriminante;
  Etat_Courant_M_Inst                  = ENTREE_Inst;
  Etat_Courant_M_Confirmation_FR       = ENTREE_Confirmation_FR;
  Etat_Courant_M_Correction            = ENTREE_Correction;


  Instant_Init_Analyse_Inst_MP         = 0;
  Instant_Init_Confirmation_MP         = 0;
  Instant_Tempo_Analyse_Inst           = 0;
  Tempo_MP                             = 0;


  FISA_MachineCalculCalib();
}


/*==============================================================================
** Name:  FISA_MachineCalculCalib
** Calcul des valeurs des calibrations.
**
**------------------------------------------------------------------------------
** IN: void
**------------------------------------------------------------------------------
** OUT: void
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
** SInt16 Ext_tCoMes
** Precision: 1    Min:  -40  Max: 214   Unit: C
**
** Boolean Ext_bCluPedPrss
** Precision: 1    Min: 0  Max: 1  Unit: ----
**
** UInt16 Ext_pAirExtMes
** Precision: 1    Min: 500  Max: 1500  Unit: mbars
**
** UInt16 TqSys_nTarIdl
** Precision: 1/4    Min:0  Max:8000  Unit:Trs/mn
**------------------------------------------------------------------------------
** RTE DataSendPoint
**------------------------------------------------------------------------------
** RTE Read IRV:
**------------------------------------------------------------------------------
** RTE Written IRV:
**
** UInt8 FISA_idxTypFac
** Precision: 1   Min:1 Max:4  Unit:----
**
** UInt8 FISA_noInjStopAdp
** Precision: 1   Min:0 Max:255  Unit:----
**============================================================================*/
/************************************************************************************/
/*                                                                                  */
/* !Reference: CSMT CGMT07 1085 V1.3                                                */
/* !Trace_To : Covers_GEENSYS_EXI_CODE_IMPL_FISA_SUPERVINIT                         */
/* !Trace_To : GEENSYS_EXI_CODE_TEST_FONCTION_TEST_SUPERVADAPINJ                    */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : Y. Didierjean (GEENSYS)                                           */
/************************************************************************************/

FUNC(void,FISA_CODE) FISA_MachineCalculCalib(void)
{
  VAR(UInt16,AUTOMATIC)           Low_x;
  VAR(UInt16,AUTOMATIC)           Low_y;

  VAR(UInt16,AUTOMATIC)  Ext_pAirExtMes ;
  VAR(UInt16,AUTOMATIC)  TqSys_nTarIdl ;
  VAR(Boolean,AUTOMATIC) Ext_bCluPedPrss ;
  VAR(UInt16,AUTOMATIC)  FISA_uMinGdStrt ;
  VAR(UInt8,AUTOMATIC)   FISA_noInjStopAdp ;
  VAR(SInt16,AUTOMATIC)  Ext_tCoMes;

  FISA_GetExt_tCoMes(&Ext_tCoMes);
  FISA_GetExt_bCluPedPrss(&Ext_bCluPedPrss);
  FISA_GetExt_pAirExtMes(&Ext_pAirExtMes);
  FISA_GetTqSys_nTarIdl(&TqSys_nTarIdl);

  Ext_tCoMes = (SInt16) (Ext_tCoMes + OFFSET_TCOS_MES);
  Ext_pAirExtMes = (UInt16) (Ext_pAirExtMes+OFFSET_AIR_EXT_MES);


  Low_x=0;
  Low_y=0;
  FISA_noInjStopAdp = lookup1D_U8(&(FISA_noInjStopAdp_map),Ext_tCoMes,&Low_x, 10, 10);

  Rte_IrvWrite_RE_FISA_init_noInjStopAdp(FISA_noInjStopAdp);

  Low_x=0;
  FISA_tiStrtInstChk = lookup1D_U16(&(FISA_tiStrtInstChk_map),Ext_tCoMes,&Low_x, 1);
  Low_x=0;
  FISA_tiInstChkEnd = lookup1D_U16(&FISA_tiInstChkEnd_map,Ext_tCoMes,&Low_x, 1);
  Low_x=0;
  FISA_tiAFReg = lookup1D_rU32_U16(&FISA_tiAFRegChk_map,Ext_tCoMes,&Low_x);

  if(TRUE == Ext_bCluPedPrss )
  {
    Low_x=0;
    FISA_nMinCrkClu  = lookup1D_U16(&FISA_nMinCrk_stCluOn_map,Ext_tCoMes,&Low_x, 1);
  }
  else
  {
    Low_x=0;
    FISA_nMinCrkClu  = lookup1D_U16(&FISA_nMinCrk_stCluOff_map,Ext_tCoMes,&Low_x, 1);
  }

  Low_x=0;
  FISA_uMinGdStrt  = lookup1D_U16(&FISA_uMinGdStrt_map,Ext_tCoMes,&Low_x, 1);

  Rte_IrvWrite_RE_FISA_init_uMinGdStrt(FISA_uMinGdStrt);

  Low_x=0;
  FISA_noIgMsk = lookup1D_rS16_U8(&FISA_noIgMsk_map,Ext_tCoMes,&Low_x, 10);
  /*Initialisation valeurs de calibration*/

  Low_x=0;
  FISA_nMax  = lookup2D_xyU16_U16(&FISA_nMax_M_map,TqSys_nTarIdl,Ext_pAirExtMes ,&Low_x,&Low_y,1);
}

/*==============================================================================
** Name: FISA_SetDefaultOutPuts
** Positionne les sortie de la machine  leur valeur par dfaut
** Cette fonction est appele  l'initialisation et dans le cas d'inhibition
**------------------------------------------------------------------------------
** IN: void
**------------------------------------------------------------------------------
** OUT: Boolean TRUE si en erreur
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
**------------------------------------------------------------------------------
** RTE DataSendPoint
**
** Boolean FISA_bAuthSave
** Precision: 1    Min: 0  Max: 1  Unit: ----
**
** Boolean FISA_bGrdWin
** Precision: 1    Min: 0  Max: 1  Unit: ----
**
** Boolean FISA_bInstWin
** Precision: 1    Min: 0  Max: 1  Unit: ----
**
** Boolean FISA_bAFRegWin
** Precision: 1    Min: 0  Max: 1  Unit: ----
**
** Boolean FISA_bRstAdpDone
** Precision: 1    Min: 0  Max: 1  Unit: ----
**------------------------------------------------------------------------------
** RTE Read IRV:
**------------------------------------------------------------------------------
** RTE Written IRV:
**
** Boolean FISA_bGrdWin
** Precision: 1    Min: 0  Max: 1  Unit: ----
**
** Boolean FISA_bInstWin
** Precision: 1    Min: 0  Max: 1  Unit: ----
**
** Boolean FISA_bAFRegWin
** Precision: 1    Min: 0  Max: 1  Unit: ----
**============================================================================*/
/************************************************************************************/
/*                                                                                  */
/* !Reference: CSMT CGMT07 1085 V1.3                                                */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : Y. Didierjean (GEENSYS)                                           */
/************************************************************************************/

_STATIC_ FUNC(void,FISA_CODE) FISA_SetDefaultOutPuts(void)
{
	FISA_Update_bAuthSave(FALSE);
	FISA_Update_bGrdWin(FALSE);
	FISA_Update_bInstWin(FALSE);
	FISA_Update_bAFRegWin(FALSE);
	FISA_Update_bRstAdpDone(FALSE);

    Rte_IrvWrite_RE_FISA_init_bGrdWin(FALSE);
    Rte_IrvWrite_RE_FISA_init_bInstWin(FALSE);
    Rte_IrvWrite_RE_FISA_init_bAFRegWin(FALSE);
}

/*==============================================================================
** Name:  FISA_Sup_Action_Etat_M_Strat
**Effectue l'action associee a un etat de la machine Strategie
**
**------------------------------------------------------------------------------
** IN: void
**------------------------------------------------------------------------------
** OUT: Boolean TRUE si en erreur
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint

**------------------------------------------------------------------------------
** RTE DataSendPoint
**------------------------------------------------------------------------------
** RTE Read IRV:
**------------------------------------------------------------------------------
** RTE Written IRV:
** UInt8 FISA_idxTypIni
** Precision: 1    Min: 1  Max: 4  Unit: ----
** UInt8 FISA_idxTypFac
** Precision: 1    Min: 1  Max: 4  Unit: ----
**============================================================================*/
/************************************************************************************/
/*                                                                                  */
/* !Reference: CSMT CGMT07 1085 V1.3                                                */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : Y. Didierjean (GEENSYS)                                           */
/************************************************************************************/

/*Action associee a un Etat de la machine MachineStrategie*/

_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Action_Etat_M_Strat(void)
{
  VAR(Boolean,AUTOMATIC) returnErreur = FALSE;

  switch(Etat_Courant_M_Strategie)
  {
    case ENTREE_M_Strategie:
    /*ne doit pas arriver*/
    FISA_erreur(FISA_ERREUR_SUPERVFCTADAP);
    break;

    case INIT_M_Strategie:
    /*Initialisation des sorties a leurs valeurs par defaut*/
    FISA_SetDefaultOutPuts();
    break;

    case INHIBITION_STRATEGIE:
    /*On reste sur les anciennes valeurs apprises*/
    Rte_IrvWrite_RE_FISA_CrankSync_idxTypIni(OLD);
    Rte_IrvWrite_RE_FISA_CrankSync_idxTypFac(OLD);
    FISA_SetDefaultOutPuts();
    break;

    case STRATEGIE_ACTIVE:
    returnErreur = FISA_Sup_Step_M_Strategie_Active();
    break;

    default:
    FISA_erreur(FISA_ERREUR_SUPERVFCTADAP);
    returnErreur=TRUE;
	break;
  }
  return returnErreur;
}

/*==============================================================================
** Name:  FISA_Sup_Transition_M_Strategie
** Teste le franchissement d'une transition de la machine strategie
** et effectue le changement d'etat associe
**------------------------------------------------------------------------------
** IN: void
**------------------------------------------------------------------------------
** OUT: Boolean, TRUE si erreur
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
Boolean FISA_bInhFISA
Precision: 1    Min:  0  Max: 1   Unit:---

Boolean FISA_bRich
Precision: 1    Min:  0  Max: 1   Unit:---

Boolean FISA_bPoor
Precision: 1    Min:  0  Max: 1   Unit:---

SInt16 Ext_tCoMes
Precision: 1    Min:  -40  Max: 214   Unit: C

UInt16 Ext_nEng
Precision: 1    Min:  0  Max: 7500   Unit: Trs/mn

UInt16 Veh_spdVeh
Precision: 1/128    Min:  0  Max: 500   Unit: Km/h

UInt8 CoPt_noEgdGearCord
Precision: 1    Min:  0  Max: 7   Unit: ---

Boolean Ext_bEngReStrt
Precision: 1    Min:  0  Max: 1   Unit: ---
**------------------------------------------------------------------------------
** RTE DataSendPoint
**------------------------------------------------------------------------------
** RTE Read IRV:
**------------------------------------------------------------------------------
** RTE Written IRV:
**============================================================================*/
/************************************************************************************/
/*                                                                                  */
/* !Reference: CSMT CGMT07 1085 V1.3                                                */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : Y. Didierjean (GEENSYS)                                           */
/************************************************************************************/
/*Transition a verifier depuis un etat donne de la machine MachineStrategie*/

_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Transition_M_Strategie(void)
{
  VAR(Boolean,AUTOMATIC)           returnErreur =FALSE;
  VAR(Boolean,AUTOMATIC)		   FISA_blnhFISA;

  VAR(UInt16,AUTOMATIC)   Veh_spdVeh;
  VAR(UInt8,AUTOMATIC)    CoPt_noEgdGearCord;
  VAR(UInt16,AUTOMATIC)   Ext_pAirExtMes;
  VAR(Boolean,AUTOMATIC)  Ext_bEngReStrt;
  VAR(Boolean,AUTOMATIC)  Ext_bCluPedPrss;
  VAR(UInt16,AUTOMATIC)   TqSys_nTarIdl;

  VAR(UInt16,AUTOMATIC)   Ext_nEng;
  VAR(SInt16,AUTOMATIC)	  Ext_tCoMes;
  VAR(Boolean,AUTOMATIC)  FISA_bPoor;
  VAR(Boolean,AUTOMATIC)  FISA_bRich;

  switch(Etat_Courant_M_Strategie)
  {
    case ENTREE_M_Strategie:
    FISA_GetInhFISA(&FISA_blnhFISA);
    FISA_GetRich(&FISA_bRich);
    FISA_GetPoor(&FISA_bPoor);
    FISA_GetExt_tCoMes(&Ext_tCoMes);
    FISA_GetExt_nEng(&Ext_nEng);
	FISA_GetVeh_spdVeh(&Veh_spdVeh);
    FISA_GetCoPt_noEgdGearCord(&CoPt_noEgdGearCord);
	FISA_GetExt_bCluPedPrss(&Ext_bCluPedPrss);
    FISA_GetExt_pAirExtMes(&Ext_pAirExtMes);
    FISA_GetTqSys_nTarIdl(&TqSys_nTarIdl);
    FISA_GetExt_bEngReStrt(&Ext_bEngReStrt);

	Ext_tCoMes = (SInt16) (Ext_tCoMes + OFFSET_TCOS_MES);
    Ext_pAirExtMes = (UInt16) (Ext_pAirExtMes+OFFSET_AIR_EXT_MES);

    if(((TRUE == FISA_blnhFISA) && (FALSE == FISA_bRich) &&
    (FALSE == FISA_bPoor)) || (Ext_tCoMes< FISA_tMinAdp_C) || (Ext_tCoMes>FISA_tMaxAdp_C) ||
    (Ext_nEng<FISA_nMinCrkClu) || (Veh_spdVeh >FISA_spdMaxAdp_C) || (CoPt_noEgdGearCord !=0) ||
    (TRUE == Ext_bEngReStrt))
    {
      Etat_Courant_M_Strategie = INHIBITION_STRATEGIE;
    }
    else
    {
      Etat_Courant_M_Strategie = INIT_M_Strategie;
    }
	break;

    case INHIBITION_STRATEGIE:
      /* rien */
    break;

    case STRATEGIE_ACTIVE:
      /* rien */
    break;

    case INIT_M_Strategie:
    FISA_GetInhFISA(&FISA_blnhFISA);
    FISA_GetRich(&FISA_bRich);
    FISA_GetPoor(&FISA_bPoor);
    FISA_GetExt_tCoMes(&Ext_tCoMes);
    FISA_GetExt_nEng(&Ext_nEng);
	FISA_GetVeh_spdVeh(&Veh_spdVeh);
    FISA_GetCoPt_noEgdGearCord(&CoPt_noEgdGearCord);
	FISA_GetExt_bCluPedPrss(&Ext_bCluPedPrss);
    FISA_GetExt_pAirExtMes(&Ext_pAirExtMes);
    FISA_GetTqSys_nTarIdl(&TqSys_nTarIdl);
    FISA_GetExt_bEngReStrt(&Ext_bEngReStrt);

	Ext_tCoMes = (SInt16) (Ext_tCoMes + OFFSET_TCOS_MES);
    Ext_pAirExtMes = (UInt16) (Ext_pAirExtMes+OFFSET_AIR_EXT_MES);

    if(((TRUE == FISA_blnhFISA) && (FALSE == FISA_bRich) &&
    (FALSE == FISA_bPoor)) || (Ext_tCoMes< FISA_tMinAdp_C) || (Ext_tCoMes>FISA_tMaxAdp_C) ||
    (Ext_nEng<FISA_nMinCrkClu) || (Veh_spdVeh >FISA_spdMaxAdp_C) || (CoPt_noEgdGearCord !=0) ||
    (TRUE == Ext_bEngReStrt))
    {
      Etat_Courant_M_Strategie = INHIBITION_STRATEGIE;
    }
    else
    {
      Etat_Courant_M_Strategie = STRATEGIE_ACTIVE;
    }
    break;

    default:
      FISA_erreur(FISA_ERREUR_SUPERVFCTADAP);
      returnErreur=TRUE;
	  break;
  }
  return  returnErreur;
}

/*==============================================================================
** Name:  FISA_Sup_Step_M_Strategie
** Gere le fonctionnement d'un pas de la machine strategie
**
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT:
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
**------------------------------------------------------------------------------
** RTE DataSendPoint
**------------------------------------------------------------------------------
** RTE Read IRV:
**------------------------------------------------------------------------------
** RTE Written IRV:
**============================================================================*/
/************************************************************************************/
/*                                                                                  */
/* !Reference: CSMT CGMT07 1085 V1.3                                                */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : Y. Didierjean (GEENSYS)                                           */
/************************************************************************************/

/*Lance l'execution d'un pas de la machine MachineStrategie
 * La Machine Strategie est lance a l'appel du serviseur*/

FUNC(void,FISA_CODE) FISA_Sup_Step_M_Strategie(void)
{
  VAR(Boolean,AUTOMATIC) Erreur;

  Erreur = FISA_Sup_Transition_M_Strategie();
  if (!Erreur)
  {
    Erreur = FISA_Sup_Action_Etat_M_Strat();
  }

  if (TRUE == Erreur)
  {
    FISA_SupervInit();
  }
}


/*Machine_Strategie_Active*/
/*==============================================================================
** Name:  FISA_Sup_Action_Etat_M_Strat_Active
** Effectue l'action associee a un etat de la machine Strategie Active
**
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT: Boolean, TRUE si erreur
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
**------------------------------------------------------------------------------
** RTE DataSendPoint
**------------------------------------------------------------------------------
** RTE Read IRV:
**------------------------------------------------------------------------------
** RTE Written IRV:
** UInt8 FISA_idxTypIni
** Precision: 1    Min: 1  Max: 4   Unit: ---
**
** UInt8 FISA_idxTypFac
** Precision: 1    Min: 1  Max: 4   Unit: ---
**============================================================================*/
/************************************************************************************/
/*                                                                                  */
/* !Reference: CSMT CGMT07 1085 V1.3                                                */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : Y. Didierjean (GEENSYS)                                           */
/************************************************************************************/

/*Action associee a un Etat de la machine Machine_Strategie_Active*/

_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Action_Etat_M_Strat_Active(void)
{
  VAR(Boolean,AUTOMATIC) Erreur=FALSE;

  switch(Etat_Courant_M_Strategie_Active)
  {
    case INIT_M_Strategie_Active:
      /* rien */
      break;

    case BESOIN_RICHE_SUR_DEFAUT_IMPLIQUE_INIT_RICHE_APPLIQUE_RICHE_SAVE_NOT:
      /* @NS le 18/11/08 : rajout visualisable FISA_idxTypIni*/
	  FISA_idxTypIni = FISA_idxIniRich;
      Rte_IrvWrite_RE_FISA_init_idxTypIni(FISA_idxIniRich);

      /* @NS : 18/11/08 : rajout affectation visualisable FISA_idxTypFac */
	  FISA_idxTypFac = FISA_idxFacRich ;
      Rte_IrvWrite_RE_FISA_init_idxTypFac(FISA_idxFacRich);
      break;

    case BESOIN_PAUVRE_IMPLIQUE_INIT_PAUVRE_APPLIQUE_PAUVRE:
      /* @NS le 18/11/08 : rajout visualisable */
	  FISA_idxTypIni = FISA_idxIniPoor;
      Rte_IrvWrite_RE_FISA_init_idxTypIni(FISA_idxIniPoor);

      /* @NS : 18/11/08 : rajout affectation visualisable FISA_idxTypFac */
	  FISA_idxTypFac = FISA_idxFacPoor;
      Rte_IrvWrite_RE_FISA_init_idxTypFac(FISA_idxFacPoor);
      break;

    case ANALYSE_ET_CORRECTION_EVENTUELLES:
      /*Analyses et corrections eventuelles*/

      Erreur = FISA_Sup_Step_M_Analyse();
      if (!Erreur)
      {
        Erreur = FISA_Sup_Step_M_Correction();
      }
      break;

    default:
      FISA_erreur(FISA_ERREUR_SUPERVFCTADAP);
      Erreur=TRUE;
      break;
  }
  return Erreur;
}

/*==============================================================================
** Name:  FISA_Sup_Transition_M_Strategie_Active
** Teste le franchissement d'une transition de la machine strategie Active
** et effectue le changement d'etat associe
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT: Boolean, TRUE si erreur
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
** Boolean FISA_bRich
** Precision: 1    Min:0  Max: 1   Unit: ---
**
** Boolean RFuDet_bRstAdp
** Precision: 1    Min:0  Max: 1   Unit: ---
**
** Boolean Ext_bFirstStrt
** Precision: 1    Min:0  Max: 1   Unit: ---
**------------------------------------------------------------------------------
** RTE DataSendPoint
**------------------------------------------------------------------------------
** RTE Read IRV:
**------------------------------------------------------------------------------
** RTE Written IRV:
UInt8 FISA_idxTypIni
Precision: 1    Min: 1  Max: 4   Unit: ---

UInt8 FISA_idxTypFac
Precision: 1    Min: 1  Max: 4   Unit: ---
**============================================================================*/
/************************************************************************************/
/*                                                                                  */
/* !Reference: CSMT CGMT07 1085 V1.3                                                */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : Y. Didierjean (GEENSYS)                                           */
/************************************************************************************/

/*Transition a verifier depuis un etat donne de la machine Machine_Strategie_Active*/

_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Transition_M_Strategie_Active(void)
{
  VAR(Boolean,AUTOMATIC) Ext_bFirstStrt;
  VAR(Boolean,AUTOMATIC) RFuDet_bRstAdp;
  VAR(Boolean,AUTOMATIC) FISA_bPoor;
  VAR(Boolean,AUTOMATIC) FISA_bRich;

  VAR(Boolean,AUTOMATIC)          returnErreur=FALSE;


  switch(Etat_Courant_M_Strategie_Active)
  {
    case BESOIN_RICHE_SUR_DEFAUT_IMPLIQUE_INIT_RICHE_APPLIQUE_RICHE_SAVE_NOT:
      /* rien */
    break;

    case BESOIN_PAUVRE_IMPLIQUE_INIT_PAUVRE_APPLIQUE_PAUVRE:
      /* rien */
    break;

    case ANALYSE_ET_CORRECTION_EVENTUELLES:
      /* rien */
    break;

    case INIT_M_Strategie_Active:
    FISA_GetRich(&FISA_bRich);
	FISA_GetPoor(&FISA_bPoor);
    FISA_GetRFuDet_bRstAdp(&RFuDet_bRstAdp);
	FISA_GetExt_bFirstStrt(&Ext_bFirstStrt);

    if (TRUE == FISA_bRich )
    {
      Etat_Courant_M_Strategie_Active = BESOIN_RICHE_SUR_DEFAUT_IMPLIQUE_INIT_RICHE_APPLIQUE_RICHE_SAVE_NOT;
    }
    else
    {
      if ( (FALSE == FISA_bPoor )&& (TRUE == Ext_bFirstStrt ) )
      {
		/* @NS : 18/11/08 : rajout FISA_idxTypIni = FISA_idxIniRich */
		FISA_idxTypIni = FISA_idxIniRich;

        Rte_IrvWrite_RE_FISA_init_idxTypIni(FISA_idxIniRich);
        Etat_Courant_M_Strategie_Active = ANALYSE_ET_CORRECTION_EVENTUELLES;
      }
      else
      {
        if ((TRUE == RFuDet_bRstAdp ) && (FALSE == FISA_bPoor ) && (FALSE == Ext_bFirstStrt ))
        {
		  /* @NS : 18/11/08 : affectation visualisable FISA_idxTypFac */
		  FISA_idxTypFac	= FISA_idxFacCur;
          Rte_IrvWrite_RE_FISA_init_idxTypFac(FISA_idxFacCur);

		  /* @NS : 18/11/08 : rajout FISA_idxTypIni = FISA_idxIniRst */
		  FISA_idxTypIni = FISA_idxIniRst;
          Rte_IrvWrite_RE_FISA_init_idxTypIni(FISA_idxIniRst);
          Etat_Courant_M_Strategie_Active= ANALYSE_ET_CORRECTION_EVENTUELLES;
        }
        else
        {
          if (TRUE == FISA_bPoor )
          {
            Etat_Courant_M_Strategie_Active=BESOIN_PAUVRE_IMPLIQUE_INIT_PAUVRE_APPLIQUE_PAUVRE;
          }
          else
          {
			/* @NS : 18/11/08 : rajout FISA_idxTypIni = FISA_idxIniOld */
			FISA_idxTypIni = FISA_idxIniOld;
            Rte_IrvWrite_RE_FISA_init_idxTypIni(FISA_idxIniOld);
            Etat_Courant_M_Strategie_Active= ANALYSE_ET_CORRECTION_EVENTUELLES;
          }
        }
      }
    }

    break;

    default:
      FISA_erreur(FISA_ERREUR_SUPERVFCTADAP);
      returnErreur=TRUE;
	  break;
  }
  return returnErreur;
}
/*==============================================================================
** Name:  FISA_Sup_Step_M_Strategie_Active
** Gere le fonctionnement d'un pas de la machine strategie Active
**
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT:
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
**------------------------------------------------------------------------------
** RTE DataSendPoint
**------------------------------------------------------------------------------
** RTE Read IRV:
**------------------------------------------------------------------------------
** RTE Written IRV:
**============================================================================*/
/************************************************************************************/
/*                                                                                  */
/* !Reference: CSMT CGMT07 1085 V1.3                                                */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : Y. Didierjean (GEENSYS)                                           */
/************************************************************************************/

/*Lance l'execution d'un pas de la machine Machine_Strategie_Active*/

_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Step_M_Strategie_Active(void)
{
  VAR(Boolean, AUTOMATIC) Erreur;

  Erreur = FISA_Sup_Transition_M_Strategie_Active();
  if (!Erreur)
  {
    Erreur = FISA_Sup_Action_Etat_M_Strat_Active();
  }
  return Erreur;
}

/*Machine_Analyse*/
/*==============================================================================
** Name:  FISA_Sup_Action_Etat_M_Analyse
** Effectue l'action associee a un etat de la machine Analyse
**
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT: Boolean, TRUE si erreur
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
**------------------------------------------------------------------------------
** RTE DataSendPoint
**------------------------------------------------------------------------------
** RTE Read IRV:
**------------------------------------------------------------------------------
** RTE Written IRV:
**============================================================================*/
/************************************************************************************/
/*                                                                                  */
/* !Reference: CSMT CGMT07 1085 V1.3                                                */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : Y. Didierjean (GEENSYS)                                           */
/************************************************************************************/

/*Action associee a un Etat de la machine Machine_Analyse*/

_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Action_Etat_M_Analyse(void)
{
  VAR(Boolean,AUTOMATIC) Erreur = FALSE;

  switch(Etat_Courant_M_Analyse)
  {
    case ENTREE_M_Analyse:
    /*rien*/
    break;
    case ANALYSE_DISCRIMINANTE:

    /*Erreur = FISA_Sup_Action_Etat_M_Analyse_Discriminante();*/
      Erreur = FISA_Sup_Step_M_Analyse_Discriminante();

    break;

    case ANALYSE_AFTERSTART:
    Erreur = FISA_Sup_Step_M_Inst();
    if (!Erreur)
    {
      Erreur = FISA_Sup_Step_M_Confirmation_FR();
    }
    break;

    default:
    FISA_erreur(FISA_ERREUR_SUPERVFCTADAP);
    Erreur = TRUE;
	break;
  }
  return Erreur;
}
/*==============================================================================
** Name:  FISA_Sup_Transition_M_Analyse
** Teste le franchissement d'une transition de la machine Analyse
** et effectue le changement d'etat associe
**
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT:  Boolean, TRUE si erreur
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
** UInt32 Timer
** Precision: 1    Min:0  Max: ---   Unit: ms
**
** Boolean Ext_bStrtEnd
** Precision: 1    Min:0  Max: 1   Unit: ---
**------------------------------------------------------------------------------
** RTE DataSendPoint
**------------------------------------------------------------------------------
** RTE Read IRV:
**------------------------------------------------------------------------------
** RTE Written IRV:
**============================================================================*/
/************************************************************************************/
/*                                                                                  */
/* !Reference: CSMT CGMT07 1085 V1.3                                                */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : Y. Didierjean (GEENSYS)                                           */
/************************************************************************************/

/*Transition a verifier depuis un etat donne de la machine Machine_Strategie_Active*/

_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Transition_M_Analyse(void)
{
  VAR(Std_ReturnType,AUTOMATIC) res;

  VAR(Boolean,AUTOMATIC)        returnErreur = FALSE;
  VAR(Boolean,AUTOMATIC)        img_Rte_IRV_FISA_bGrdWin;
  VAR(Boolean,AUTOMATIC) 		Ext_bStrtEnd;

  res = RTE_E_OK;
  img_Rte_IRV_FISA_bGrdWin   = Rte_IrvRead_RE_FISA_CrankSync_bGrdWin();

  switch(Etat_Courant_M_Analyse)
  {
    case ENTREE_M_Analyse:
      Etat_Courant_M_Analyse = ANALYSE_DISCRIMINANTE;
      break;

    case ANALYSE_AFTERSTART:
      /* rien */
      break;

    case ANALYSE_DISCRIMINANTE:
      FISA_GetExt_bStrtEnd(&Ext_bStrtEnd);
      if ((TRUE == Ext_bStrtEnd ) && (FALSE == img_Rte_IRV_FISA_bGrdWin))
      {
        /*Action todo*/
        res = Rte_Call_R_FISA_GetTimer_1ms_U32_GetTimer_1ms_U32(&Temp_Courant_MP);
        if (RTE_E_OK != res)
        {
          FISA_erreur(FISA_ERREUR_READERROR);
          returnErreur=TRUE;
        }
        else
        {
          Instant_Init_Analyse_Inst_MP = Temp_Courant_MP;
          Etat_Courant_M_Analyse = ANALYSE_AFTERSTART;
        }
      }
      break;

    default:
      FISA_erreur(FISA_ERREUR_SUPERVFCTADAP);
      returnErreur=TRUE;
	  break;
  }
  return returnErreur;
}

/*Machine_Analyse_Discriminante*/
/*==============================================================================
** Name:   FISA_Sup_Step_M_Analyse_Discriminante
**  Gere le fonctionnement d'un pas de la machine  Analyse Discriminante
**
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT: Boolean, TRUE si erreur
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
**------------------------------------------------------------------------------
** RTE DataSendPoint
**------------------------------------------------------------------------------
** RTE Read IRV:
**------------------------------------------------------------------------------
** RTE Written IRV:
**============================================================================*/
/************************************************************************************/
/*                                                                                  */
/* !Reference: CSMT CGMT07 1085 V1.3                                                */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : Y. Didierjean (GEENSYS)                                           */
/************************************************************************************/

/*Lance l'execution d'un pas de la machine Machine_Analyse_Discriminante*/

_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Step_M_Analyse_Discriminante(void)
{
  VAR(Boolean,AUTOMATIC) Erreur;

  Erreur = FISA_Sup_Transition_M_Analyse_Discriminante();
  if (!Erreur)
  {
    Erreur = FISA_Sup_Action_Etat_M_Analyse_Discriminante();
  }
  return Erreur;
}

/*==============================================================================
** Name:  FISA_Sup_Action_Etat_M_Analyse_Discriminante
** Effectue l'action associee a un etat de la machine Analyse Discriminante
**
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT: Boolean, TRUE si erreur
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
**------------------------------------------------------------------------------
** RTE DataSendPoint
** Boolean FISA_bGrdWin
** Precision: 1    Min:0  Max: 1   Unit: ---
**------------------------------------------------------------------------------
** RTE Read IRV:
**------------------------------------------------------------------------------
** RTE Written IRV:
** Boolean FISA_bGrdWin
** Precision: 1    Min:0  Max: 1   Unit: ---
**============================================================================*/
/************************************************************************************/
/*                                                                                  */
/* !Reference: CSMT CGMT07 1085 V1.3                                                */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : Y. Didierjean (GEENSYS)                                           */
/************************************************************************************/

/*Action associee a un Etat de la machine Machine_Analyse_Discriminante*/

_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Action_Etat_M_Analyse_Discriminante(void)
{
  VAR(Boolean,AUTOMATIC)        returnErreur = FALSE;

  switch(Etat_Courant_M_Analyse_Discriminante)
  {
    case ENTREE_Analyse_Discriminante:
    /* rien */
    break;

    case INIT_Analyse_Discriminante:
	FISA_Update_bGrdWin(FALSE);
    Rte_IrvWrite_RE_FISA_CrankSync_bGrdWin(FALSE);
    break;

    case ANALYSE_ON:
    FISA_Update_bGrdWin(TRUE);
    Rte_IrvWrite_RE_FISA_CrankSync_bGrdWin(TRUE);
    break;

    case MOTEUR_DEMARRE:
    FISA_Update_bGrdWin(FALSE);
    Rte_IrvWrite_RE_FISA_CrankSync_bGrdWin(FALSE);
    break;

    default:
    FISA_erreur(FISA_ERREUR_SUPERVFCTADAP);
    returnErreur=TRUE;
	break;
  }
  return returnErreur;
}

/*==============================================================================
** Name:  FISA_Sup_Transition_M_Analyse_Discriminante
** Teste le franchissement d'une transition de la machine Analyse Discriminante
** et effectue le changement d'etat associe
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT: Boolean, TRUE si erreur
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
** UInt16 Ext_ctInj
** Precision: 1    Min:0  Max: 65535   Unit: ---
**
** SInt16 Ext_uBattMes
** Precision: 0.01    Min:0  Max: 32   Unit: V
**
** Boolean  Ext_bSync
** Precision: 1    Min:0  Max: 1   Unit: ---
**------------------------------------------------------------------------------
** RTE DataSendPoint
**------------------------------------------------------------------------------
** RTE Read IRV:
** UInt8 FISA_noInjStopAdp
** Precision: 1    Min:0  Max: 255  Unit: ---
**
** UInt16 FISA_uMinGdStrt
** Precision: 1    Min:0  Max: 32 Unit: V
**------------------------------------------------------------------------------
** RTE Written IRV:
**============================================================================*/
/************************************************************************************/
/*                                                                                  */
/* !Reference: CSMT CGMT07 1085 V1.3                                                */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : Y. Didierjean (GEENSYS)                                           */
/************************************************************************************/

/*Transition a verifier depuis un etat donne de la machine Machine_Analyse_Discriminante*/

_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Transition_M_Analyse_Discriminante(void)
{
  VAR(Boolean,AUTOMATIC)    returnErreur = FALSE;
  VAR(UInt16,AUTOMATIC)     img_Rte_IRV_FISA_uMinGdStrt;
  VAR(UInt16,AUTOMATIC)     img_Rte_IRV_FISA_noInjStopAdp;

  VAR(UInt16,AUTOMATIC)     Ext_ctInj ;
  VAR(SInt16,AUTOMATIC)     Ext_uBattMes ;
  VAR(Boolean,AUTOMATIC)    Ext_bSync ;
  VAR(UInt16,AUTOMATIC)   	Ext_nEng;

  img_Rte_IRV_FISA_uMinGdStrt   = Rte_IrvRead_RE_FISA_CrankSync_uMinGdStrt();
  img_Rte_IRV_FISA_noInjStopAdp = (UInt16)Rte_IrvRead_RE_FISA_CrankSync_noInjStopAdp();

  switch(Etat_Courant_M_Analyse_Discriminante)
  {
    case ENTREE_Analyse_Discriminante:
    Etat_Courant_M_Analyse_Discriminante =INIT_Analyse_Discriminante;
    break;

    case MOTEUR_DEMARRE:
    /* rien */
    break;

    case INIT_Analyse_Discriminante:
    FISA_GetExt_ctInj(&Ext_ctInj );
    FISA_GetuBattMes(&Ext_uBattMes );
    FISA_GetExt_Ext_bSync(&Ext_bSync );

    if (((((SInt32)Ext_ctInj)*10) >(SInt32)FISA_noIgMsk) && (((SInt32)Ext_uBattMes) >((SInt32)img_Rte_IRV_FISA_uMinGdStrt)) && (TRUE == Ext_bSync ))
    {
      Etat_Courant_M_Analyse_Discriminante = ANALYSE_ON;
    }
    break;

    case ANALYSE_ON:
    FISA_GetExt_ctInj(&Ext_ctInj );
    FISA_GetExt_nEng(&Ext_nEng);
    if ((Ext_ctInj>img_Rte_IRV_FISA_noInjStopAdp ) || (Ext_nEng>FISA_nMax))
    {
      Etat_Courant_M_Analyse_Discriminante=MOTEUR_DEMARRE;
    }
    break;

  default:
    FISA_erreur(FISA_ERREUR_SUPERVFCTADAP);
    returnErreur=TRUE;
	break;
  }
  return returnErreur;
}

/*==============================================================================
** Name:   FISA_Sup_Step_M_Analyse
**  Gere le fonctionnement d'un pas de la machine  Analyse
**
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT: Boolean, TRUE si erreur
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
**------------------------------------------------------------------------------
** RTE DataSendPoint
**------------------------------------------------------------------------------
** RTE Read IRV:
**------------------------------------------------------------------------------
** RTE Written IRV:
**============================================================================*/
/************************************************************************************/
/*                                                                                  */
/* !Reference: CSMT CGMT07 1085 V1.3                                                */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : Y. Didierjean (GEENSYS)                                           */
/************************************************************************************/

/*Lance l'execution d'un pas de la machine Machine_Analyse*/

_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Step_M_Analyse(void)
{
  VAR(Boolean,AUTOMATIC) Erreur;

  Erreur = FISA_Sup_Transition_M_Analyse();
  if (!Erreur)
  {
    Erreur = FISA_Sup_Action_Etat_M_Analyse();
  }
  return Erreur;
}

/*Machine_Inst*/
/*==============================================================================
** Name:  FISA_Sup_Action_Etat_M_Inst
** Effectue l'action associee a un etat de la machine Instabilites
**
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT:  Boolean, TRUE si erreur
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
**------------------------------------------------------------------------------
** RTE DataSendPoint
**
** Boolean FISA_bInstWin
** Precision: 1    Min:0  Max: 1   Unit: ---
**------------------------------------------------------------------------------
** RTE Read IRV:
**------------------------------------------------------------------------------
** RTE Written IRV:
**============================================================================*/
/************************************************************************************/
/*                                                                                  */
/* !Reference: CSMT CGMT07 1085 V1.3                                                */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : Y. Didierjean (GEENSYS)                                           */
/************************************************************************************/

/*Action associee a un Etat de la machine Machine_Inst*/
_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Action_Etat_M_Inst(void)
{
  VAR(Boolean,AUTOMATIC)        returnErreur=FALSE;

  switch(Etat_Courant_M_Inst)
  {
    case ENTREE_Inst:
    /*rien*/
    break;

    case INIT_Inst:
    FISA_Update_bInstWin(FALSE);
    Rte_IrvWrite_RE_FISA_CrankSync_bInstWin(FALSE);
    break;

    case ANALYSE_Inst_ON:
    FISA_Update_bInstWin(TRUE);
    Rte_IrvWrite_RE_FISA_CrankSync_bInstWin(TRUE);
    break;

    case ANALYSE_INSTABILITE_INTERROMPUE_OU_FINIE:
    FISA_Update_bInstWin(FALSE);
    Rte_IrvWrite_RE_FISA_CrankSync_bInstWin(FALSE);
    break;

    default:
    FISA_erreur(FISA_ERREUR_SUPERVFCTADAP);
    returnErreur=TRUE;
	break;
  }
  return returnErreur;
}

/*==============================================================================
** Name:  FISA_Sup_Transition_M_Inst
** Teste le franchissement d'une transition de la machine Instabilites
** et effectue le changement d'etat associe
**
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT: Boolean, TRUE si erreur
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
** UInt32 Timer
** Precision: 1    Min:0  Max: infini   Unit: secondes
**
** Boolean Ext_bIdlAcv
** Precision: 1    Min:0  Max: 1  Unit: ---
**
** Boolean FISA_bInhInst
** Precision: 1    Min:0  Max: 1  Unit: ---
**
** Boolean AFReg_bAFRegAcv
** Precision: 1    Min:0  Max: 1  Unit: ---
**------------------------------------------------------------------------------
** RTE DataSendPoint
**------------------------------------------------------------------------------
** RTE Read IRV:
**------------------------------------------------------------------------------
** RTE Written IRV:
**============================================================================*/
/************************************************************************************/
/*                                                                                  */
/* !Reference: CSMT CGMT07 1085 V1.3                                                */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : Y. Didierjean (GEENSYS)                                           */
/************************************************************************************/

/*Transition a verifier depuis un etat donne de la machine Machine_Inst*/

_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Transition_M_Inst(void)
{
  VAR(Std_ReturnType,AUTOMATIC)     res;
  VAR(Boolean,AUTOMATIC)			AFReg_bAFRegAcv;
  VAR(Boolean,AUTOMATIC)			FISA_bInhInst;
  VAR(Boolean,AUTOMATIC)            returnErreur=FALSE;
  VAR(Boolean,AUTOMATIC)			Ext_bIdlAcv ;

  res = RTE_E_OK;
  switch(Etat_Courant_M_Inst)
  {
    case ANALYSE_INSTABILITE_INTERROMPUE_OU_FINIE:
      /* rien */
    break;

    case ENTREE_Inst:
    Etat_Courant_M_Inst = INIT_Inst;
    break;

    case INIT_Inst:
    res |= Rte_Call_R_FISA_GetTimer_1ms_U32_GetTimer_1ms_U32(&Temp_Courant_MP);
    FISA_GetExt_bIdlAcv(&Ext_bIdlAcv );
    FISA_GetInhInst(&FISA_bInhInst);

    if (RTE_E_OK == res)
    {
      if ((FALSE==FISA_bInhInst) &&
          ((Temp_Courant_MP*10)>((Instant_Init_Analyse_Inst_MP*10) + (((UInt32)FISA_tiStrtInstChk)*1000))) &&
          (TRUE == Ext_bIdlAcv ))
      {
        Instant_Tempo_Analyse_Inst =Temp_Courant_MP;
        Etat_Courant_M_Inst = ANALYSE_Inst_ON;
      }
    }
    else
    {
      FISA_erreur(FISA_ERREUR_READERROR);
      returnErreur = TRUE;
    }
    break;

    case ANALYSE_Inst_ON:
    res |= Rte_Call_R_FISA_GetTimer_1ms_U32_GetTimer_1ms_U32(&Temp_Courant_MP);
    FISA_GetAFReg_bAFRegAcv(&AFReg_bAFRegAcv);
	FISA_GetExt_bIdlAcv(&Ext_bIdlAcv );

    if (RTE_E_OK == res)
    {
      if ((TRUE==AFReg_bAFRegAcv) ||
          ((Temp_Courant_MP*10)>((Instant_Tempo_Analyse_Inst*10) + (((UInt32)FISA_tiInstChkEnd)*1000))) ||
          (FALSE == Ext_bIdlAcv ))
      {
        Etat_Courant_M_Inst=ANALYSE_INSTABILITE_INTERROMPUE_OU_FINIE;
      }
    }
    else
    {
      FISA_erreur(FISA_ERREUR_READERROR);
      returnErreur=TRUE;
    }
    break;

    default:
    FISA_erreur(FISA_ERREUR_SUPERVFCTADAP);
    returnErreur=TRUE;
    break;
  }
  return returnErreur;
}

/*==============================================================================
** Name:  FISA_Sup_Step_M_Inst
** Gere le fonctionnement d'un pas de la machine  Instabilites
**
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT: Boolean, TRUE si erreur
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
**------------------------------------------------------------------------------
** RTE DataSendPoint
**------------------------------------------------------------------------------
** RTE Read IRV:
**------------------------------------------------------------------------------
** RTE Written IRV:
**============================================================================*/
/************************************************************************************/
/*                                                                                  */
/* !Reference: CSMT CGMT07 1085 V1.3                                                */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : Y. Didierjean (GEENSYS)                                           */
/************************************************************************************/

/*Lance l'execution d'un pas de la machine Machine_Strategie_Active*/

_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Step_M_Inst(void)
{
  VAR(Boolean, AUTOMATIC) Erreur;

  Erreur = FISA_Sup_Transition_M_Inst();
  if (!Erreur)
  {
    Erreur = FISA_Sup_Action_Etat_M_Inst();
  }
  return Erreur;
}

/*Machine_Confirmation_FR*/
/*==============================================================================
** Name:  FISA_Sup_Action_Etat_M_Confirmation_FR
**  Effectue l'action associee a un etat de la machine Confirmation_FR
**
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT: Boolean, TRUE si erreur
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
** UInt32 Timer
** Precision: 1    Min:0  Max: infini   Unit: secondes
**------------------------------------------------------------------------------
** RTE DataSendPoint
** Boolean FISA_bAFRegWin
** Precision: 1    Min:0  Max: 1  Unit: ---
**------------------------------------------------------------------------------
** RTE Read IRV:
**------------------------------------------------------------------------------
** RTE Written IRV:
** Boolean FISA_bAFRegWin
** Precision: 1    Min:0  Max: 1  Unit: ---
**============================================================================*/
/************************************************************************************/
/*                                                                                  */
/* !Reference: CSMT CGMT07 1085 V1.3                                                */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : Y. Didierjean (GEENSYS)                                           */
/************************************************************************************/

/*Action associee a un Etat de la machine Machine_Confirmation_FR()*/

_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Action_Etat_M_Confirmation_FR(void)
{
  VAR(Std_ReturnType,AUTOMATIC) res;
  VAR(Boolean,AUTOMATIC)        returnErreur=FALSE;

  res = RTE_E_OK;
  switch(Etat_Courant_M_Confirmation_FR)
  {
    case ENTREE_Confirmation_FR:
    /*rien*/
    break;

    case INIT_Confirmation_FR:
    FISA_Update_bAFRegWin(FALSE);
    Rte_IrvWrite_RE_FISA_init_bAFRegWin(FALSE);
    break;

    case ANALYSE_FR_ON:
    Rte_IrvWrite_RE_FISA_init_bAFRegWin(TRUE);
    FISA_Update_bAFRegWin(TRUE);
    break;

    case ANALYSE_FR_INTERROMPUE:
    res |= Rte_Call_R_FISA_GetTimer_1ms_U32_GetTimer_1ms_U32(&Temp_Courant_MP);

    if (RTE_E_OK != res)
    {
      FISA_erreur(FISA_ERREUR_READERROR);
      returnErreur=TRUE;
    }
    else
    {
      Rte_IrvWrite_RE_FISA_init_bAFRegWin(FALSE);
      FISA_Update_bAFRegWin(FALSE);
      if (Temp_Courant_MP>Instant_Init_Confirmation_MP)
      {
        /* TU : La difference ne peut pas etre negative suite au test */
        Tempo_MP=Temp_Courant_MP-Instant_Init_Confirmation_MP;
      }
      else
      {
        Tempo_MP = 0;
      }
    }
    break;

    case ANALYSE_FR_TERMINEE:
    Rte_IrvWrite_RE_FISA_init_bAFRegWin(FALSE);
    FISA_Update_bAFRegWin(FALSE);
    break;

    default:
    FISA_erreur(FISA_ERREUR_SUPERVFCTADAP);
    returnErreur=TRUE;
	break;
  }
  return returnErreur;
}

/*==============================================================================
** Name:  FISA_Sup_Transition_M_Confirmation_FR
** Teste le franchissement d'une transition de la machine Confirmation_FR
** et effectue le changement d'etat associe
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT:  Boolean, TRUE si erreur
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
** Boolean AFReg_bAFRegAcv
** Precision: 1    Min:0  Max: 1  Unit: ---
**
** Boolean Ext_bStrtEnd
** Precision: 1    Min:0  Max: 1  Unit: ---
**
** UInt16  Eng_rAirLd
** Precision: 0.1    Min:  0  Max: 300   Unit: %
**
** UInt16 Ext_nEng
** Precision: 1    Min:  0  Max: 7500   Unit: Trs/mn
**
**
** UInt16 AccP_rAccP
** Precision: 0.1    Min:  0  Max: 100  Unit: %
**
** SInt16 Ext_tCoMes
** Precision: 1    Min:  -40  Max: 214   Unit: C
**
** Uint32 Timer
** Precision: 1    Min:0  Max: infini   Unit: secondes
**------------------------------------------------------------------------------
** RTE DataSendPoint
**------------------------------------------------------------------------------
** RTE Read IRV:
**------------------------------------------------------------------------------
** RTE Written IRV:
**============================================================================*/
/************************************************************************************/
/*                                                                                  */
/* !Reference: CSMT CGMT07 1085 V1.3                                                */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : Y. Didierjean (GEENSYS)                                           */
/************************************************************************************/

/*Transition a verifier depuis un etat donne de la machine Machine_Confirmation_FR*/

_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Transition_M_Confirmation_FR(void)
{
  VAR(Std_ReturnType,AUTOMATIC) res;
  VAR(Boolean,AUTOMATIC)        returnErreur=FALSE;
  VAR(UInt16,AUTOMATIC)			Eng_rAirLd ;
  VAR(UInt16,AUTOMATIC)			AccP_rAccP ;
  VAR(UInt16,AUTOMATIC)   		Ext_nEng;
  VAR(SInt16,AUTOMATIC)			Ext_tCoMes;
  VAR(Boolean,AUTOMATIC) 		Ext_bStrtEnd;
  VAR(Boolean,AUTOMATIC)		AFReg_bAFRegAcv;

  res = RTE_E_OK;

  switch(Etat_Courant_M_Confirmation_FR)
  {
    case ENTREE_Confirmation_FR:
    Etat_Courant_M_Confirmation_FR = INIT_Confirmation_FR;
    break;

    case INIT_Confirmation_FR:
    FISA_GetAFReg_bAFRegAcv(&AFReg_bAFRegAcv);
	FISA_GetExt_bStrtEnd(&Ext_bStrtEnd);
	FISA_GetEng_rAirLd(&Eng_rAirLd);
	FISA_GetExt_nEng(&Ext_nEng);
	FISA_GetAccP_rAccP(&AccP_rAccP);
	FISA_GetExt_tCoMes(&Ext_tCoMes);
    Ext_tCoMes = (SInt16) (Ext_tCoMes + OFFSET_TCOS_MES);
	res |= Rte_Call_R_FISA_GetTimer_1ms_U32_GetTimer_1ms_U32(&Temp_Courant_MP);

    if (RTE_E_OK == res)
    {
      if(((TRUE == AFReg_bAFRegAcv ) &&
        (TRUE == Ext_bStrtEnd ) && (Eng_rAirLd>FISA_rAirLdMinHighAFReg_C) &&
        (Eng_rAirLd<FISA_rAirLdMaxLowAFReg_C) && (Ext_nEng>FISA_nMinHighAFReg_C) &&
        (Ext_nEng<FISA_nMaxLowAFReg_C) && (AccP_rAccP>FISA_rAccPMinHighAFReg_C) &&
        (AccP_rAccP<FISA_rAccPMaxLowAFReg_C ) && (Ext_tCoMes<FISA_tMaxAFReg_C) &&
        (Ext_tCoMes>FISA_tMinAFReg_C)))
      {
        Instant_Init_Confirmation_MP = Temp_Courant_MP;
        Etat_Courant_M_Confirmation_FR=ANALYSE_FR_ON;
      }
      else
      {
        if(Ext_tCoMes>=FISA_tMaxAFReg_C)
        {
          Etat_Courant_M_Confirmation_FR=ANALYSE_FR_TERMINEE;
        }
      }
    }
    else
    {
      FISA_erreur(FISA_ERREUR_READERROR);
      returnErreur=TRUE;
    }
    break;

  case ANALYSE_FR_ON:
    FISA_GetAFReg_bAFRegAcv(&AFReg_bAFRegAcv);
	FISA_GetExt_bStrtEnd(&Ext_bStrtEnd);
	FISA_GetEng_rAirLd(&Eng_rAirLd);
	FISA_GetExt_nEng(&Ext_nEng);
	FISA_GetAccP_rAccP(&AccP_rAccP);
	FISA_GetExt_tCoMes(&Ext_tCoMes);
        Ext_tCoMes = (SInt16) (Ext_tCoMes + OFFSET_TCOS_MES);
	res |= Rte_Call_R_FISA_GetTimer_1ms_U32_GetTimer_1ms_U32(&Temp_Courant_MP);

    if (RTE_E_OK == res)
    {
      if((((FALSE == AFReg_bAFRegAcv ) || (Eng_rAirLd>FISA_rAirLdMaxHighAFReg_C) ||
        (Eng_rAirLd<FISA_rAirLdMinLowAFReg_C) || (Ext_nEng<FISA_nMinHighAFReg_C) ||
        (Ext_nEng>FISA_nMaxLowAFReg_C) || (AccP_rAccP>FISA_rAccPMaxHighAFReg_C) ||
        (AccP_rAccP<FISA_rAccPMinLowAFReg_C ) || (Ext_tCoMes<FISA_tMinAFReg_C) ||
        (Ext_tCoMes>FISA_tMaxAFReg_C)) &&
        ((Temp_Courant_MP*10)<((Instant_Init_Confirmation_MP*10)+(FISA_tiAFReg*1000)))))
      {
        Etat_Courant_M_Confirmation_FR=ANALYSE_FR_INTERROMPUE;
      }
      else
      {
        if((Temp_Courant_MP*10)>((Instant_Init_Confirmation_MP*10)+(FISA_tiAFReg*1000)))
        {
          Etat_Courant_M_Confirmation_FR=ANALYSE_FR_TERMINEE;
        }
      }
    }
    else
    {
      FISA_erreur(FISA_ERREUR_READERROR);
      returnErreur=TRUE;
    }
    break;

  case ANALYSE_FR_INTERROMPUE:
    FISA_GetAFReg_bAFRegAcv(&AFReg_bAFRegAcv);
	FISA_GetExt_bStrtEnd(&Ext_bStrtEnd);
	FISA_GetEng_rAirLd(&Eng_rAirLd);
	FISA_GetExt_nEng(&Ext_nEng);
	FISA_GetAccP_rAccP(&AccP_rAccP);
	FISA_GetExt_tCoMes(&Ext_tCoMes);
        Ext_tCoMes = (SInt16) (Ext_tCoMes + OFFSET_TCOS_MES);
	res |= Rte_Call_R_FISA_GetTimer_1ms_U32_GetTimer_1ms_U32(&Temp_Courant_MP);

    if (RTE_E_OK == res)
    {
      if (((TRUE == AFReg_bAFRegAcv ) && (TRUE == Ext_bStrtEnd ) &&
        (Eng_rAirLd>FISA_rAirLdMinHighAFReg_C) && (Eng_rAirLd<FISA_rAirLdMaxLowAFReg_C) &&
        (Ext_nEng>FISA_nMinHighAFReg_C) && (Ext_nEng<FISA_nMaxLowAFReg_C) &&
        /* En l'etat AccP_rAccP>FISA_rAccPMinHighAFReg_C n'est pas possible, mais PSA peut changer la constante */
        (AccP_rAccP>FISA_rAccPMinHighAFReg_C) && (AccP_rAccP<FISA_rAccPMaxLowAFReg_C ) &&
        (Ext_tCoMes<FISA_tMaxAFReg_C) && (Ext_tCoMes>FISA_tMinAFReg_C)))
      {
        if (Temp_Courant_MP > Tempo_MP)
        {
          Instant_Init_Confirmation_MP = Temp_Courant_MP - Tempo_MP;
          Etat_Courant_M_Confirmation_FR=ANALYSE_FR_ON;
        }
        else
        {
          Temp_Courant_MP = 0;
        }
      }
    }
    else
    {
      FISA_erreur(FISA_ERREUR_READERROR);
      returnErreur=TRUE;
    }
    break;

    case ANALYSE_FR_TERMINEE:
    /* rien */
    break;

    default:
    FISA_erreur(FISA_ERREUR_SUPERVFCTADAP);
    returnErreur=TRUE;
	break;
  }
  return returnErreur;
}

/*==============================================================================
** Name:  FISA_Sup_Step_M_Confirmation_FR
**  Gere le fonctionnement d'un pas de la machine  Confirmation_FR
**
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT:  Boolean, TRUE si erreur
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
**------------------------------------------------------------------------------
** RTE DataSendPoint
**------------------------------------------------------------------------------
** RTE Read IRV:
**------------------------------------------------------------------------------
** RTE Written IRV:
**============================================================================*/
/************************************************************************************/
/*                                                                                  */
/* !Reference: CSMT CGMT07 1085 V1.3                                                */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : Y. Didierjean (GEENSYS)                                           */
/************************************************************************************/

/*Lance l'execution d'un pas de la machine Machine_Strategie_Active*/

_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Step_M_Confirmation_FR(void)
{
  VAR(Boolean,AUTOMATIC) Erreur;

  Erreur = FISA_Sup_Transition_M_Confirmation_FR();
  if (!Erreur)
  {
    Erreur = FISA_Sup_Action_Etat_M_Confirmation_FR();
  }
  return Erreur;
}

/*Machine_Correction*/
/*==============================================================================
** Name:  FISA_Sup_Action_Etat_M_Correction
** Effectue l'action associee a un etat de la machine Correction
**
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT:  Boolean, TRUE si erreur
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
**------------------------------------------------------------------------------
** RTE DataSendPoint
** Boolean FISA_bAuthSave
** Precision: 1    Min:0  Max: 1  Unit: ---
**
**------------------------------------------------------------------------------
** RTE Read IRV:
**------------------------------------------------------------------------------
** RTE Written IRV:
** Boolean FISA_bAuthClc
** Precision: 1    Min:0  Max: 1  Unit: ---
**
** UInt8 FISA_idxTypFac
** Precision: 1    Min: 1  Max: 4   Unit: ---
**============================================================================*/
/************************************************************************************/
/*                                                                                  */
/* !Reference: CSMT CGMT07 1085 V1.3                                                */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : Y. Didierjean (GEENSYS)                                           */
/************************************************************************************/

/*Action associee a un Etat de la machine Machine_Correction()*/

_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Action_Etat_M_Correction(void)
{
  VAR(Boolean,AUTOMATIC)        returnErreur=FALSE;

  switch(Etat_Courant_M_Correction)
  {
    case ENTREE_Correction:
    /* rien */
    break;

    case INIT_Correction:
	/* @NS 18/11/08 affectation de la visualisable FISA_bAuthClc */
	FISA_bAuthClc = FALSE;
    Rte_IrvWrite_RE_FISA_CrankSync_bAuthClc(FALSE);
    break;

    case AUTORISATION_APPLICATION_CORRECTION_ON:
	/* @NS 18/11/08 affectation de la visualisable FISA_bAuthClc */
	FISA_bAuthClc = TRUE;
    Rte_IrvWrite_RE_FISA_CrankSync_bAuthClc(TRUE);
    FISA_Update_bAuthSave(TRUE);

	/* @NS : 18/11/08 : affectation visualisable FISA_idxTypFac */
	FISA_idxTypFac = FISA_idxFacCur;
    Rte_IrvWrite_RE_FISA_init_idxTypFac(FISA_idxFacCur);
    break;

    case DEFAUT_SUR_DEM_EN_COURS_EGAL_FIN_ADAP_APPLIQUE_EN_COURS_SAVE_NOT:
	/* @NS 18/11/08 affectation de la visualisable FISA_bAuthClc */
	FISA_bAuthClc = FALSE;
    Rte_IrvWrite_RE_FISA_CrankSync_bAuthClc(FALSE);
    FISA_Update_bAuthSave(FALSE);
    break;

    case FIN_CORRECTION_DEM:
	/* @NS 18/11/08 affectation de la visualisable FISA_bAuthClc */
	FISA_bAuthClc = FALSE;
    Rte_IrvWrite_RE_FISA_CrankSync_bAuthClc(FALSE);
    break;

    case BESOIN_PAUVRE_SUR_DEFAUT_EGAL_FIN_ADAP_APPLIQUE_PAUVRE_SAVE_NOT:
	/* @NS 18/11/08 affectation de la visualisable FISA_bAuthClc */
	FISA_bAuthClc = FALSE;
    Rte_IrvWrite_RE_FISA_CrankSync_bAuthClc(FALSE);
    FISA_Update_bAuthSave(FALSE);

	/*@NS : 18/11/08 : affectation viualisable FISA_idxTypFac */
	FISA_idxTypFac = FISA_idxFacPoor;
    Rte_IrvWrite_RE_FISA_init_idxTypFac(FISA_idxFacPoor);
    break;

    case CORRECTION_POST_DEM_INSTABILITY :
	/*@NS : 18/11/08 : affectation viualisable FISA_idxTypFac */
	FISA_idxTypFac = FISA_idxFacCur;
    Rte_IrvWrite_RE_FISA_init_idxTypFac(FISA_idxFacCur);
    break;

    case FIN_CORRECTION_POST_DEM_INST:
	/* @NS 18/11/08 affectation de la visualisable FISA_bAuthClc */
	FISA_bAuthClc = FALSE;
    Rte_IrvWrite_RE_FISA_CrankSync_bAuthClc(FALSE);
    break;

    case BESOIN_RICHE_SUR_DEFAUT_EGAL_ADAP_APPLIQUE_RICHE_SAVE_NOT:
	/* @NS 18/11/08 affectation de la visualisable FISA_bAuthClc */
	FISA_bAuthClc = FALSE;
    Rte_IrvWrite_RE_FISA_CrankSync_bAuthClc(FALSE);
    FISA_Update_bAuthSave(FALSE);

	/*@NS : 18/11/08 : affectation viualisable FISA_idxTypFac */
	FISA_idxTypFac = FISA_idxFacRich;
    Rte_IrvWrite_RE_FISA_init_idxTypFac(FISA_idxFacRich);
    break;

    case CORRECTION_POST_DEM_FR:
		/*@NS : 18/11/08 : affectation viualisable FISA_idxTypFac */
	FISA_idxTypFac = FISA_idxFacCur;
    Rte_IrvWrite_RE_FISA_init_idxTypFac(FISA_idxFacCur);
    break;

    case FIN_CORRECTION_POST_DEM_FR:
	FISA_bAuthClc = FALSE;
    Rte_IrvWrite_RE_FISA_CrankSync_bAuthClc(FALSE);
    break;

    default:
    FISA_erreur(FISA_ERREUR_SUPERVFCTADAP);
    returnErreur=TRUE;
	break;
  }
  return returnErreur;
}

/*==============================================================================
** Name:  FISA_Sup_Transition_M_Correction
**Teste le franchissement d'une transition de la machine Correction
** et effectue le changement d'etat associe
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT:  Boolean, TRUE si erreur
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
** Boolean FISA_bRich
** Precision: 1    Min:0  Max: 1  Unit: ---
**
** Boolean FISA_bPoor
** Precision: 1    Min:0  Max: 1  Unit: ---
**
** Boolean FISA_bInhFISA
** Precision: 1    Min:0  Max: 1  Unit: ---
**
** Boolean FISA_bInhInst
** Precision: 1    Min:0  Max: 1  Unit: ---
**------------------------------------------------------------------------------
** RTE DataSendPoint
**------------------------------------------------------------------------------
** RTE Read IRV:
** Boolean FISA_bGrdWin
** Precision: 1    Min:0  Max: 1  Unit: ---
**
** Boolean FISA_bInstWin
** Precision: 1    Min:0  Max: 1  Unit: ---
**
** Boolean FISA_bAFRegWin
** Precision: 1    Min:0  Max: 1  Unit: ---
**------------------------------------------------------------------------------
** RTE Written IRV:
**============================================================================*/
/************************************************************************************/
/*                                                                                  */
/* !Reference: CSMT CGMT07 1085 V1.3                                                */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : Y. Didierjean (GEENSYS)                                           */
/************************************************************************************/

/*Transition a verifier depuis un etat donne de la machine Machine_Confirmation_FR*/

_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Transition_M_Correction(void)
{
  VAR(Boolean,AUTOMATIC)        returnErreur = FALSE;
  VAR(Boolean,AUTOMATIC)        img_Rte_IRV_FISA_bAFRegWin;
  VAR(Boolean,AUTOMATIC)        img_Rte_IRV_FISA_bGrdWin;
  VAR(Boolean,AUTOMATIC)        img_Rte_IRV_FISA_bInstWin;
  VAR(Boolean,AUTOMATIC)		FISA_blnhFISA;

  VAR(Boolean,AUTOMATIC) FISA_bPoor;
  VAR(Boolean,AUTOMATIC) FISA_bRich;
  VAR(Boolean,AUTOMATIC) FISA_bInhInst;


  img_Rte_IRV_FISA_bAFRegWin = Rte_IrvRead_RE_FISA_CrankSync_bAFRegWin();
  img_Rte_IRV_FISA_bGrdWin   = Rte_IrvRead_RE_FISA_CrankSync_bGrdWin();
  img_Rte_IRV_FISA_bInstWin  = Rte_IrvRead_RE_FISA_CrankSync_bInstWin();

  switch(Etat_Courant_M_Correction)
  {
    case ENTREE_Correction:
    Etat_Courant_M_Correction =INIT_Correction;
    break;

    case INIT_Correction:
    if(TRUE ==img_Rte_IRV_FISA_bGrdWin)
    {
      Etat_Courant_M_Correction=AUTORISATION_APPLICATION_CORRECTION_ON;
    }
    break;

    case AUTORISATION_APPLICATION_CORRECTION_ON:
    FISA_GetRich(&FISA_bRich);
	FISA_GetPoor(&FISA_bPoor);
	FISA_GetInhFISA(&FISA_blnhFISA);

    if ((FALSE == FISA_bPoor )&&(FALSE == FISA_bRich )&&(TRUE == FISA_blnhFISA ))
    {
      Etat_Courant_M_Correction=DEFAUT_SUR_DEM_EN_COURS_EGAL_FIN_ADAP_APPLIQUE_EN_COURS_SAVE_NOT;
    }
    else
    {
      if ((TRUE == FISA_bPoor )&&(FALSE == FISA_bRich ))
      {
        Etat_Courant_M_Correction=BESOIN_PAUVRE_SUR_DEFAUT_EGAL_FIN_ADAP_APPLIQUE_PAUVRE_SAVE_NOT;
      }
      else
      {
        if (TRUE == FISA_bRich )
        {
          Etat_Courant_M_Correction=BESOIN_RICHE_SUR_DEFAUT_EGAL_ADAP_APPLIQUE_RICHE_SAVE_NOT;
        }
        else
        {
          if ((FALSE ==img_Rte_IRV_FISA_bGrdWin) && (FALSE==img_Rte_IRV_FISA_bInstWin))
          {
            Etat_Courant_M_Correction=FIN_CORRECTION_DEM;
          }
        }
      }
    }
    break;

    case DEFAUT_SUR_DEM_EN_COURS_EGAL_FIN_ADAP_APPLIQUE_EN_COURS_SAVE_NOT:
    FISA_GetRich(&FISA_bRich);
	FISA_GetPoor(&FISA_bPoor);
    if ((TRUE == FISA_bPoor ) && (FALSE == FISA_bRich ))
    {
      Etat_Courant_M_Correction=BESOIN_PAUVRE_SUR_DEFAUT_EGAL_FIN_ADAP_APPLIQUE_PAUVRE_SAVE_NOT;
    }
    break;

    case FIN_CORRECTION_DEM:
    FISA_GetRich(&FISA_bRich);
	FISA_GetPoor(&FISA_bPoor);
	FISA_GetInhFISA(&FISA_blnhFISA);
	FISA_GetInhInst(&FISA_bInhInst);

    if ((FALSE == FISA_bPoor )&&(FALSE == FISA_bRich )&&(TRUE == FISA_blnhFISA ))
    {
      Etat_Courant_M_Correction=DEFAUT_SUR_DEM_EN_COURS_EGAL_FIN_ADAP_APPLIQUE_EN_COURS_SAVE_NOT;
    }
    else
    {
      if ((TRUE == FISA_bPoor )&&(FALSE == FISA_bRich ))
      {
        Etat_Courant_M_Correction=BESOIN_PAUVRE_SUR_DEFAUT_EGAL_FIN_ADAP_APPLIQUE_PAUVRE_SAVE_NOT;
      }
      else
      {
        if (TRUE == FISA_bRich )
        {
          Etat_Courant_M_Correction=BESOIN_RICHE_SUR_DEFAUT_EGAL_ADAP_APPLIQUE_RICHE_SAVE_NOT;
        }
        else
        {
          if ((TRUE == img_Rte_IRV_FISA_bInstWin) && (FALSE == FISA_bInhInst ))
          {
		    /* @NS 18/11/08 affectation de la visualisable FISA_bAuthClc */
	 		FISA_bAuthClc = TRUE;
            Rte_IrvWrite_RE_FISA_CrankSync_bAuthClc(TRUE);
            Etat_Courant_M_Correction=CORRECTION_POST_DEM_INSTABILITY;
          }
          else
          {
            if ((FALSE == FISA_blnhFISA ) &&
            (TRUE == FISA_bInhInst )  && (FALSE == FISA_bPoor ) && (FALSE == FISA_bRich ))
            {
              Etat_Courant_M_Correction=FIN_CORRECTION_POST_DEM_INST;
            }
          }
        }
      }
    }
    break;

    case BESOIN_PAUVRE_SUR_DEFAUT_EGAL_FIN_ADAP_APPLIQUE_PAUVRE_SAVE_NOT:
    FISA_GetRich(&FISA_bRich);
    if (TRUE == FISA_bRich )
    {
       Etat_Courant_M_Correction=BESOIN_RICHE_SUR_DEFAUT_EGAL_ADAP_APPLIQUE_RICHE_SAVE_NOT;
    }
    break;

    case CORRECTION_POST_DEM_INSTABILITY:
    FISA_GetRich(&FISA_bRich);
	FISA_GetPoor(&FISA_bPoor);
	FISA_GetInhFISA(&FISA_blnhFISA);

    if ((FALSE == FISA_bPoor ) && (FALSE == FISA_bRich ) && (TRUE == FISA_blnhFISA ))
    {
      Etat_Courant_M_Correction=DEFAUT_SUR_DEM_EN_COURS_EGAL_FIN_ADAP_APPLIQUE_EN_COURS_SAVE_NOT;
    }
    else
    {
      if ((TRUE == FISA_bPoor ) && (FALSE == FISA_bRich ))
      {
        Etat_Courant_M_Correction=BESOIN_PAUVRE_SUR_DEFAUT_EGAL_FIN_ADAP_APPLIQUE_PAUVRE_SAVE_NOT;
      }
      else
      {
        if (TRUE == FISA_bRich )
        {
          Etat_Courant_M_Correction=BESOIN_RICHE_SUR_DEFAUT_EGAL_ADAP_APPLIQUE_RICHE_SAVE_NOT;
        }
        else
        {
          if (FALSE == img_Rte_IRV_FISA_bInstWin)
          {
            Etat_Courant_M_Correction=FIN_CORRECTION_POST_DEM_INST;
          }
        }
      }
    }
    break;

    case FIN_CORRECTION_POST_DEM_INST:
    FISA_GetRich(&FISA_bRich);
	FISA_GetPoor(&FISA_bPoor);
	FISA_GetInhFISA(&FISA_blnhFISA);

    if ((FALSE == FISA_bPoor ) && (FALSE == FISA_bRich ) && (TRUE == FISA_blnhFISA ))
    {
      Etat_Courant_M_Correction=DEFAUT_SUR_DEM_EN_COURS_EGAL_FIN_ADAP_APPLIQUE_EN_COURS_SAVE_NOT;
    }
    else
    {
      if ((TRUE == FISA_bPoor ) && (FALSE == FISA_bRich ))
      {
        Etat_Courant_M_Correction=BESOIN_PAUVRE_SUR_DEFAUT_EGAL_FIN_ADAP_APPLIQUE_PAUVRE_SAVE_NOT;
      }
      else
      {
        if (TRUE == FISA_bRich )
        {
          Etat_Courant_M_Correction=BESOIN_RICHE_SUR_DEFAUT_EGAL_ADAP_APPLIQUE_RICHE_SAVE_NOT;
        }
        else
        {
          if ((TRUE == img_Rte_IRV_FISA_bAFRegWin))
          {
  		    /* @NS 18/11/08 affectation de la visualisable FISA_bAuthClc */
	 	    FISA_bAuthClc = TRUE;

            Rte_IrvWrite_RE_FISA_CrankSync_bAuthClc(TRUE);
            Etat_Courant_M_Correction=CORRECTION_POST_DEM_FR;
          }
          else
          {
            /* rien */
          }
        }
      }
    }
    break;

    case BESOIN_RICHE_SUR_DEFAUT_EGAL_ADAP_APPLIQUE_RICHE_SAVE_NOT:
    /* rien */
    break;

    case CORRECTION_POST_DEM_FR:
    FISA_GetRich(&FISA_bRich);
	FISA_GetPoor(&FISA_bPoor);
	FISA_GetInhFISA(&FISA_blnhFISA );

    if ((FALSE == FISA_bPoor ) && (FALSE == FISA_bRich ) && (TRUE == FISA_blnhFISA ))
    {
      Etat_Courant_M_Correction=DEFAUT_SUR_DEM_EN_COURS_EGAL_FIN_ADAP_APPLIQUE_EN_COURS_SAVE_NOT;
    }
    else
    {
      if ((TRUE == FISA_bPoor ) && (FALSE == FISA_bRich ))
      {
        Etat_Courant_M_Correction=BESOIN_PAUVRE_SUR_DEFAUT_EGAL_FIN_ADAP_APPLIQUE_PAUVRE_SAVE_NOT;
      }
      else
      {
        if (TRUE == FISA_bRich )
        {
          Etat_Courant_M_Correction=BESOIN_RICHE_SUR_DEFAUT_EGAL_ADAP_APPLIQUE_RICHE_SAVE_NOT;
        }
        else
        {
          if (FALSE == img_Rte_IRV_FISA_bAFRegWin)
          {
            Etat_Courant_M_Correction=FIN_CORRECTION_POST_DEM_FR;
          }
          else
          {
            /* rien */
          }
        }
      }
    }
    break;

    case FIN_CORRECTION_POST_DEM_FR:
    if ((TRUE == img_Rte_IRV_FISA_bAFRegWin))
    {
	  /* @NS 18/11/08 affectation de la visualisable FISA_bAuthClc */
	  FISA_bAuthClc = TRUE;

      Rte_IrvWrite_RE_FISA_CrankSync_bAuthClc(TRUE);
      Etat_Courant_M_Correction=CORRECTION_POST_DEM_FR;
    }
    break;

    default:
    FISA_erreur(FISA_ERREUR_SUPERVFCTADAP);
    returnErreur=TRUE;
	break;
  }
  return returnErreur;
}

/*==============================================================================
** Name:  FISA_Sup_Step_M_Correction
** Gere le fonctionnement d'un pas de la machine Correction
**
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT:  Boolean, TRUE si erreur
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
**------------------------------------------------------------------------------
** RTE DataSendPoint
**------------------------------------------------------------------------------
** RTE Read IRV:
**------------------------------------------------------------------------------
** RTE Written IRV:
**============================================================================*/
/************************************************************************************/
/*                                                                                  */
/* !Reference: CSMT CGMT07 1085 V1.3                                                */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : Y. Didierjean (GEENSYS)                                           */
/************************************************************************************/

/*Lance l'execution d'un pas de la machine Machine_Correction*/

_STATIC_ FUNC(Boolean,FISA_CODE) FISA_Sup_Step_M_Correction(void)
{
  VAR(Boolean,AUTOMATIC) Erreur;

  Erreur = FISA_Sup_Transition_M_Correction();
  if (!Erreur)
  {
    Erreur = FISA_Sup_Action_Etat_M_Correction();
  }
  return Erreur;
}

#define FISA_STOP_SEC_CODE
#include "FISA_MemMap.h"

