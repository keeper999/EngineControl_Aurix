/******************************************************************************/
/*                                                                            */
/* !Layer :                 APPLI                                             */
/*                                                                            */
/* !Component :             FISA                                              */
/* !Description :                                                             */
/*                                                                            */
/* !Module :                FISA_ConfirmationApDem                            */
/* !Description :           Confirmation en apres demarrage de                */
/*                          l'apprentissage de la qualite                     */
/* !File :                  FISA_ConfirmationApDem.c                          */
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
/* $Archive::   P:/LIBPSA/LOG/Ref/SWC_VEMS/FISA/LOG/FISA_ConfirmationApDem.c_v          $*/
/* $Revision::   1.17      $$Author::   flavergn   $$Date::   21 Jul 2010 16:$*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/
/*FISA_ConfirmationApDem_main                                                 */
/*FISA_ConfirmInit                                                            */
/*FISA_ConfirmAfterInstabWatching                                             */
/*Calcul_indicateur_stability                                                 */
/*FISA_ConfirmFRWatching                                                      */
/******************************************************************************/
/******************************************************************************/
/* INCLUSIONS                                                                 */
/******************************************************************************/
#include "FISA_ConfirmationApDem.h"
#include "FISA_Runnables.h"

/******************************************************************************/
/* DECLARATION OF GLOBAL VARIABLES                                            */
/******************************************************************************/

/*Declaration des variables intermediaires visualisables*/

#define FISA_START_SEC_INTERNAL_VAR_8BIT
#include "FISA_MemMap.h"

 /* @NS 18/11/08 deplacement de FISA_facDifAFReg de la pile en static module */
VAR(SInt8,FISA_VAR) FISA_facDifAFReg;
 /* @NS 18/11/08 declaration de FISA_facDifAst en static module */
VAR(SInt8,FISA_VAR) FISA_facDifAst;

#define FISA_STOP_SEC_INTERNAL_VAR_8BIT
#include "FISA_MemMap.h"

#define FISA_START_SEC_INTERNAL_VAR_16BIT
#include "FISA_MemMap.h"

VAR(SInt16,FISA_VAR)  FISA_ctInst_MP;
VAR(UInt16,FISA_VAR)  FISA_facStabAvr_MP;

#define FISA_STOP_SEC_INTERNAL_VAR_16BIT
#include "FISA_MemMap.h"

#define FISA_START_SEC_VAR_16BIT
#include "FISA_MemMap.h"

_STATIC_ VAR(UInt16,FISA_VAR)  Ext_tiTDC_prev;
_STATIC_ VAR(UInt16,FISA_VAR)  out_accum_unit;
_STATIC_ VAR(UInt16,FISA_VAR)  out_accum_unit_prev;
_STATIC_ VAR(UInt16,FISA_VAR)  out_accum_unit_prev_modulo;

_STATIC_ VAR(SInt16,FISA_VAR)  FISA_ctInst_prev;
_STATIC_ VAR(SInt16,FISA_VAR)  FISA_ctInst_delay_unit;

_STATIC_ VAR(SInt16,FISA_VAR)  FISA_facDifInst_accum_delay;

/*variables utilisees pour les look up tables qui gardent l'ancien index de chaque recherche*/
_STATIC_ VAR(UInt16,FISA_VAR)  X_FISA_facInstMax_lastIndex;
_STATIC_ VAR(UInt16,FISA_VAR)  X_FISA_bAcvInstWin_lastIndex;

_STATIC_ VAR(UInt16,FISA_VAR)  X_FISA_facAFRegMax_lastIndex;
_STATIC_ VAR(UInt16,FISA_VAR)  X_FISA_facAFRegMin_lastIndex;

_STATIC_ VAR(UInt16,FISA_VAR)  Ext_tiTDC_delay;
_STATIC_ VAR(SInt16,FISA_VAR)  Accum_Sat_Analisys_mem;

#define FISA_STOP_SEC_VAR_16BIT
#include "FISA_MemMap.h"


#define FISA_START_SEC_VAR_32BIT
#include "FISA_MemMap.h"

_STATIC_ VAR(SInt32,FISA_VAR)  FISA_facDeltaAvr_tiTDC[FISA_FACDELTAAVR_TITDC_LENGTH];/*tableau de 100 cases*/

#define FISA_STOP_SEC_VAR_32BIT
#include "FISA_MemMap.h"

#define FISA_START_SEC_INTERNAL_VAR_BOOLEAN
#include "FISA_MemMap.h"

 VAR(Boolean,FISA_VAR)   FISA_bRstInstCnt_MP;
 VAR(Boolean,FISA_VAR)   FISA_bRstInstTmp_MP;

#define FISA_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "FISA_MemMap.h"


#define FISA_START_SEC_CONST_UNSPECIFIED
#include "FISA_MemMap.h"

/*Creation de notre structure qui contient l'adresse de nos 2 tables (lookup table 1D)*/
_STATIC_ CONST(MAP_Table_1D_U16,AUTOMATIC) FISA_facInstMax_map =
{
  FISA_TCOMES2_LENGTH             /* taille de FISA_tCoMes2_A */,
  &(FISA_tCoMes2_A[0])            /* x_table: vector with x-values */,
  &(FISA_facInstMax_T[0])         /* z_table: matrix with z-values */
};

/*Creation de notre structure qui contient l'adresse de nos 2 tables (lookup table 1D)*/
_STATIC_ CONST(MAP_Table_1D_U8,AUTOMATIC) FISA_bAcvInstWin_map =
{
  FISA_TCOMES1_LENGTH             /* taille de FISA_tCoMes1_A */,
  &(FISA_tCoMes1_A[0])            /* x_table: vector with x-values */,
  &(FISA_bAcvInstWin_T[0])        /* z_table: matrix with z-values */
};

/*Creation de notre structure qui contient l'adresse de nos 2 tables (lookup table 1D)*/
_STATIC_ CONST(MAP_Table_1D_U16,AUTOMATIC) FISA_facAFRegMax_map =
{
  FISA_TCOMES2_LENGTH             /* taille de FISA_tCoMes2_A */,
  &(FISA_tCoMes2_A[0])            /* x_table: vector with x-values */,
  &(FISA_facAFRegMax_T[0])        /* z_table: matrix with z-values */
};

/*Creation de notre structure qui contient l'adresse de nos 2 tables (lookup table 1D)*/
_STATIC_ CONST(MAP_Table_1D_U16,AUTOMATIC) FISA_facAFRegMin_map =
{
  FISA_TCOMES2_LENGTH             /* taille de FISA_tCoMes2_A */,
  &(FISA_tCoMes2_A[0])            /* x_table: vector with x-values */,
  &(FISA_facAFRegMin_T[0])        /* z_table: matrix with z-values */
};

#define FISA_STOP_SEC_CONST_UNSPECIFIED
#include "FISA_MemMap.h"

/******************************************************************************/
/* DEFINITION OF GLOBAL FUNCTIONS                                             */
/******************************************************************************/

#define FISA_START_SEC_CODE
#include "FISA_MemMap.h"

#define FISA_CTINST_MP_MAX  ((SInt16) 100)
#define EXT_TITDC_MAX		((UInt16) 100)		/* @V1.5 : avant 1000 */




/*==============================================================================
** Name:FISA_ConfirmationApDem_main
** Description: Fonction principale qui appel toutes les sous fonctions
**    FISA_ConfirmAfterInstabWatching et FISA_ConfirmFRWatching
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT:
**------------------------------------------------------------------------------
** IN/OUT:
**============================================================================*/
/************************************************************************************/
/*                                                                                  */
/* !Reference: CSMT CGMT07 1087 V1.3                                                */
/* !Trace_To : Covers_GEENSYS_EXI_CODE_IMPL_FISA_CONFIRMATIONAPDEM_MAIN             */
/* !Trace_To : GEENSYS_EXI_CODE_TEST_FISA_CONFIRMATIONAPDEM_MAIN                    */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                               */
/************************************************************************************/

FUNC(void,FISA_CODE) FISA_ConfirmationApDem_main(void)
{
  /*appel de la sous fonction qui analyse des instabilites de regime en apres demarrage*/
  FISA_ConfirmAfterInstabWatching();

  /*appel de sous fonction qui observe la deviation du facteur de regulation*/
  FISA_ConfirmFRWatching();
}


/*==============================================================================
** Name:FISA_ConfirmInit
** Description: Initialisation des variables qui seront utilisees par la suite (delay, memoire, ...)
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT:
**------------------------------------------------------------------------------
** IN/OUT:
**============================================================================*/
/************************************************************************************/
/*                                                                                  */
/* !Reference: CSMT CGMT07 1087 V1.3                                                */
/* !Trace_To : Covers_GEENSYS_EXI_CODE_IMPL_FISA_CONFIRMINIT                        */
/* !Trace_To : GEENSYS_EXI_CODE_TEST_FISA_CONFIRMINIT                               */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                               */
/************************************************************************************/

FUNC(void,FISA_CODE) FISA_ConfirmInit(void)
{
  /* local variables */
  VAR(UInt8,AUTOMATIC)  i; /* use for table parsing */

/* @NS 18/11/08 : correction des valeurs d'init de FISA_facDifAFReg et FISA_facDifAst */
/* @NS 18/11/08 affectation des 2 visualisables FISA_facDifAFReg et FISA_facDifAst */

  FISA_facDifAFReg = 0;
  FISA_facDifAst   = 0;

  Rte_IrvWrite_RE_FISA_init_facDifAst(0);
  Rte_IrvWrite_RE_FISA_init_facDifAFReg(0);

  /*faire l'init de tout les variables de delay et temporaire*/
  FISA_bRstInstTmp_MP = FALSE;
  Ext_tiTDC_prev = 0;

  out_accum_unit = 0;
  out_accum_unit_prev = 0;
  out_accum_unit_prev_modulo = 0;

  FISA_ctInst_MP = 0;
  FISA_ctInst_prev = 0;
  FISA_ctInst_delay_unit = 0;

  FISA_facDifInst_accum_delay = 0;
  FISA_bRstInstCnt_MP = FALSE;

  for (i=0; i<FISA_FACDELTAAVR_TITDC_LENGTH; i++)
  {
    FISA_facDeltaAvr_tiTDC[i] = 0;
  }

  X_FISA_facInstMax_lastIndex = 0;
  X_FISA_bAcvInstWin_lastIndex = FALSE;

  X_FISA_facAFRegMax_lastIndex = 0;
  X_FISA_facAFRegMin_lastIndex = 0;

  Ext_tiTDC_delay = 0;
  Accum_Sat_Analisys_mem = 0;
}

/******************************************************************************/
/* DEFINITION OF FUNCTIONS OF MODULE                                          */
/******************************************************************************/

/*==============================================================================
** Name: FISA_ConfirmAfterInstabWatching
** Description: Analyse des instabilites de regime en apres demarrage
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT:
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
**
** UInt16 Ext_tiTDC
**  Min = 0 Max = 100 Prec = 0.001
** SInt16  Ext_tCoMes
**  Min = -40 Max = 214 Prec = 1
**------------------------------------------------------------------------------
** RTE DataSendPoint
**------------------------------------------------------------------------------
** RTE Read IRV:
**
** Boolean FISA_bInstWin
**  Min = 0 Max = 1 Prec = 1
** Boolean  FISA_bAuthClc
**  Min = 0 Max = 1 Prec = 1
**------------------------------------------------------------------------------
** RTE Written IRV:
**
** UInt8 facDifAst
**  Min = 0 Max = 100 Prec = 0.01
**============================================================================*/
/************************************************************************************/
/*                                                                                  */
/* !Reference: CSMT CGMT07 1087 V1.3                                                */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                               */
/************************************************************************************/
FUNC(void,FISA_CODE) FISA_ConfirmAfterInstabWatching(void)
{
  /*Variables intermediaires non visualisable*/
  VAR(Boolean,AUTOMATIC)                     FISA_bInstWin;
  VAR(UInt16,AUTOMATIC)                      Ext_tiTDC;
  VAR(UInt8,AUTOMATIC)			     u8Ext_tiTDC;	/* @V1.5 variable rajouttee */
  VAR(SInt16,AUTOMATIC)                      Ext_tCoMes ;
  VAR(UInt16,AUTOMATIC)                      FISA_facInstMax ;
  VAR(SInt16,AUTOMATIC)                      FISA_facDifInst;
  VAR(Boolean,AUTOMATIC)                     FISA_bAuthClc;
  VAR(Boolean,AUTOMATIC)                     bTmp;
  VAR(Boolean,AUTOMATIC)                     FISA_bAcvInstWin;
  VAR(SInt16,AUTOMATIC)                      FISA_facDifAst_tmp; /*donnee de retour*/
  VAR(SInt16,AUTOMATIC)                      enter_add_1;
  VAR(SInt16,AUTOMATIC)                      enter_add_2;
  VAR(SInt16,AUTOMATIC)                      FISA_facDifInst_accum_out;

  /*lecture de l'IRV FISA_bInstWin*/
  FISA_bInstWin = Rte_IrvRead_RE_FISA_CrankSync_bInstWin();
  FISA_bAuthClc = Rte_IrvRead_RE_FISA_CrankSync_bAuthClc();

  /*lecture des entrees (RTE)*/
  FISA_GetExt_tiTDC(&(u8Ext_tiTDC));
  Ext_tiTDC = (UInt16) u8Ext_tiTDC;
  FISA_GetExt_tCoMes(&Ext_tCoMes);
  Ext_tCoMes = (SInt16) (Ext_tCoMes + OFFSET_TCOS_MES);

  if (TRUE == FISA_bInstWin)
  {
    if (TRUE == FISA_bRstInstTmp_MP)
    {
      /*FISA_erreur(FISA_ERREUR_CONFIRMATION);*/
      out_accum_unit = 0;
      out_accum_unit_prev = 0;
    }
    else
    {
      /*accumulateur unitaire qui ajoute a lui meme la valeur courante de Ext_tiTDC*/
        /*appel de la fonction qui creee un retard de deux cycle en sortie*/
      if (TRUE==FISA_firstTime)
      {
        /* Au tout premier appel, la memoire en forcee a zero (vu avec simulink) */
        out_accum_unit_prev = 0;
        out_accum_unit = Ext_tiTDC;
      }
      else
      {
        out_accum_unit = (UInt16) (out_accum_unit_prev + Ext_tiTDC);
        out_accum_unit_prev = out_accum_unit;
      }
    }

    /*pour ne pas diviser par zero*/
    if (0 != FISA_tiInstChk_C )
    {
      /*QAC voit une possible division par zero qui est pourtant empechee par le "if" au dessus*/
      out_accum_unit = (UInt16) (out_accum_unit % (FISA_tiInstChk_C*10));
    }
    else
    {
      /* TU : Ce bloc n'est pas execute pour l'instant car la constante est a FALSE,
      mais PSA pourrait la changer */
      FISA_erreur(FISA_ERREUR_CONFIRMATION);
      out_accum_unit = 0 ;
    }

    if ((FALSE==FISA_bRstInstCnt_MP) && (out_accum_unit_prev_modulo > out_accum_unit) && (out_accum_unit <= CST))
    {
      /* TU : Ce bloc n'est pas execute pour l'instant car la constante est a FALSE,
      mais PSA pourrait la changer */
      FISA_bRstInstCnt_MP = TRUE;
    }
    else
    {
      FISA_bRstInstCnt_MP = FALSE;
    }
    out_accum_unit_prev_modulo = out_accum_unit;
  }

  FISA_facStabAvr_MP = Calcul_indicateur_stability();

  /*Calcul de FISA_facInstMax (lookup 1D)*/
  FISA_facInstMax = lookup1D_U16(&(FISA_facInstMax_map),Ext_tCoMes,&(X_FISA_facInstMax_lastIndex),1);

  /*sortie du compteur unitaire*/
  FISA_ctInst_delay_unit = FISA_ctInst_prev;

  /*compteur d'instabilite*/
  if (TRUE==FISA_bRstInstCnt_MP)/*test de la valeur de reset*/
  {
    FISA_ctInst_prev = 0;
  }

  if (FISA_facStabAvr_MP >= (UInt16)FISA_facInstMax)/*test du ON*/
  {
    if (FISA_ctInst_MP < FISA_CTINST_MP_MAX)
    {
      /* TU : FISA_CTINST_MP_MAX etant egal a 100 il est impossible d'avoir un overflow sur l'incrementation */
      FISA_ctInst_MP = (SInt16) (FISA_ctInst_prev + 1) ;/*on incremente la sortie*/
    }
  }
  else
  {
    FISA_ctInst_MP = FISA_ctInst_prev;/*on garde la valeur precedente si ON = 0 (FISA_facStabAvr_MP < FISA_facInstMax)*/
  }

  /* Retard interne au compteur d'instabilite*/
  if (TRUE==FISA_firstTime)
  {
    FISA_ctInst_prev = 0;
  }
  else
  {
    FISA_ctInst_prev = FISA_ctInst_MP ;/*on recopie la valeur actuelle dans le retard*/
  }

  /*calcul de la 1ere entree de l'additionneur*/

  if ((FISA_ctInst_delay_unit <= FISA_noInstMin_C)&& (TRUE==FISA_bRstInstCnt_MP))
  {
    enter_add_1 = (SInt16)FISA_facDecInst_C ;
  }
  else
  {
    enter_add_1 = 0;
  }

   /*on sauvegarde la valeur courante de FISA_ctInst_MP pour le prochain PMH
    FISA_ctInst_delay_unit = FISA_ctInst_MP ; */

  /*calcul de la 2nde entree de l'additionneur*/

  bTmp = (Boolean)((FISA_ctInst_MP >= FISA_noInstMax_C) && (out_accum_unit <= (FISA_tiInstChk_C*10)));
  if (TRUE==bTmp)
  {
    enter_add_2 = (SInt16) FISA_facIncInst_C;
  }
  else
  {
    enter_add_2 = 0 ;
  }

  /*calcul de FISA_facDifInst*/
  FISA_facDifInst = (SInt16) (enter_add_1 + enter_add_2);

  if (TRUE==FISA_firstTime)
  {
    FISA_bRstInstTmp_MP = FALSE;
  }
  else
  {
    FISA_bRstInstTmp_MP = bTmp;
  }

  /*Appel de la fonction accum_sat_Analyse qui va donner le delta du coeffcient FISA_facDifInst*/
  FISA_facDifInst_accum_out = Accum_Sat_Analisys_without_FIX ( FISA_facDifInst, FISA_bAuthClc, (SInt16) FISA_facDecInstMax_C,(SInt16) FISA_facIncInstMax_C, &FISA_facDifInst_accum_delay, FISA_firstTime);

  FISA_bAcvInstWin = (Boolean)lookup1D_U8(&(FISA_bAcvInstWin_map),Ext_tCoMes,&(X_FISA_bAcvInstWin_lastIndex),1,1);

  if ( TRUE == FISA_bAcvInstWin )
  {
    FISA_facDifAst_tmp = FISA_facDifInst_accum_out ;
  }
  else
  {
    FISA_facDifAst_tmp = 0;
  }

  if (TRUE==FISA_bRstInstCnt_MP)/*test de la valeur de reset*/
  {
    FISA_ctInst_prev = 0;
  }

  /*pour eviter un overflow*/
  FISA_facDifAst = Saturation_INT_S8 (FISA_facDifAst_tmp,MAXSCHAR,MINSCHAR);

  /*@NS: modif du calcul de FISA_facDifAst */
  /*@NS: debut modif */

  /* if ((FISA_facDifAst <= FISA_facIncInstMax_C) && (FISA_facDifAst >= FISA_facDecInstMax_C)) */
  /* saturation entre FISA_facDecInstMax_C et FISA_facIncInstMax_C */

  if (FISA_facDifAst < FISA_facDecInstMax_C)
  {
    /* @NS : 18/11/08 : affectation de la visualisable FISA_facDifAst */
    FISA_facDifAst = FISA_facDecInstMax_C;
  }
  else
  {
     if (FISA_facDifAst > FISA_facIncInstMax_C)
     {
			/* @NS : 18/11/08 : affectation de la visualisable FISA_facDifAst */
			FISA_facDifAst = (SInt8)FISA_facIncInstMax_C;
     }
  }
  Rte_IrvWrite_RE_FISA_CrankSync_facDifAst ((SInt8)FISA_facDifAst);

}

/*==============================================================================
** Name: Calcul_indicateur_stability
** Description: Calcul de la moyenne glissante pour connaitre l'indice de stabilite
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT:
** UInt16 : valeur de retour de la fonction, c'est FISA_facStabAvr
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
**
** UInt16 Ext_tiTDC
**  Min = 0 Max = 100 Prec = 0.001
**------------------------------------------------------------------------------
** RTE DataSendPoint
**------------------------------------------------------------------------------
** RTE Read IRV:
**
** Boolean FISA_bInstWin
**  Min = 0 Max = 1 Prec = 1
**------------------------------------------------------------------------------
** RTE Written IRV:
**============================================================================*/
/************************************************************************************/
/*                                                                                  */
/* !Reference: CSMT CGMT07 1087 V1.3                                                */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                               */
/************************************************************************************/
FUNC(UInt16,FISA_CODE) Calcul_indicateur_stability(void)
{
  /* local variables */
  VAR(UInt8,AUTOMATIC)            i;                    /* use for table parsing */
  VAR(SInt32,AUTOMATIC)           stability_calcul;
  VAR(SInt32,AUTOMATIC)           stability_indice;
  VAR(UInt16,AUTOMATIC)           Ext_tiTDC;
  VAR(UInt8,AUTOMATIC)            u8Ext_tiTDC;			/* @V1.5 variable rajouttee */
  VAR(Boolean,AUTOMATIC)          FISA_bInstWin;
  VAR(ts_fixed,AUTOMATIC)         FISA_noTDCInstAvr_C_f;
  VAR(ts_fixed,AUTOMATIC)         result_div_f;
  VAR(ts_fixed,AUTOMATIC)         stability_indice_f;

  /*lecture de la variable d'entree Ext_tiTDC (RTE)*/
  FISA_GetExt_tiTDC( &(u8Ext_tiTDC));
  Ext_tiTDC = (UInt16)u8Ext_tiTDC;

  /*lecture de l'IRV FISA_bInstWin*/
  FISA_bInstWin = Rte_IrvRead_RE_FISA_CrankSync_bInstWin();

  /*decalage des donnees du tableau*/
  for(i=0; i<(FISA_FACDELTAAVR_TITDC_LENGTH - 1); i++)
  {
    FISA_facDeltaAvr_tiTDC[i] = FISA_facDeltaAvr_tiTDC[i+1];
  }

  /*on soustrait la valeur courante de Ext_tiTDC a sa valeur au PMH precedent*/
  stability_calcul = ((SInt32)(Ext_tiTDC - Ext_tiTDC_prev))*1000;

  /*division (sans division par 0)*/
  if (0 != Ext_tiTDC)
  {
    /*QAC voit une possible division par zero qui est pourtant empechee par le "if" au dessus*/
    stability_calcul = stability_calcul / (SInt16)Ext_tiTDC;
  }
  else
  {
    stability_calcul = 0 ;
  }

  /*on veut la valeur absolue de stability_calcul*/
  if (stability_calcul < 0)
  {
    FISA_facDeltaAvr_tiTDC[FISA_FACDELTAAVR_TITDC_LENGTH - 1] = (-stability_calcul);
  }
  else
  {
    FISA_facDeltaAvr_tiTDC[FISA_FACDELTAAVR_TITDC_LENGTH - 1] = stability_calcul;
  }

  /*init avant d'utiliser stability_indice*/
  stability_indice = 0;

  /* Compute stability indice PMH */
  /* TU : Le deuxieme terme est toujours vrai pour l'instant car la constante est a 5,
      mais PSA pourrait la changer */
  if ( (TRUE == FISA_bInstWin) && (0 != FISA_noTDCInstAvr_C) )
  {
    /* La somme ne se fait que sur les FISA_noTDCInstAvr_C dernieres valeurs, car les autres sont forcement nulles */
    for ( i = 0 ; i < FISA_noTDCInstAvr_C ; i++ )
    {
      stability_indice = stability_indice + FISA_facDeltaAvr_tiTDC[(FISA_FACDELTAAVR_TITDC_LENGTH - FISA_noTDCInstAvr_C)+i];
    }

    /* Sur les trois fonctions suivantes QAC nous dit que les structures pointees
       ne sont pas initialisees, ce n'est pas une erreur car elles sont la justement
       pour etre remplies */
    S32_to_fixed(stability_indice, STABILITY_INDICE_EXP, &stability_indice_f);
    U16_to_fixed(SIGNE_PLUS,(UInt16)FISA_noTDCInstAvr_C, FISA_NOTDCINSTAVR_C_EXP, &FISA_noTDCInstAvr_C_f);
    DIV_FIX ( stability_indice_f , FISA_noTDCInstAvr_C_f , &(result_div_f) );

    stability_indice = fixed_to_S16 (&(result_div_f) , STABILITY_INDICE_EXP  );
  }
  else
  {
    stability_indice = 0;
  }

  /* Save current value */
  Ext_tiTDC_prev = (UInt16) Ext_tiTDC;

  /*stability_indice ne peut etre negatif, ni depasser 20*1000*/
  return (UInt16)(stability_indice);
}


/*==============================================================================
** Name:FISA_ConfirmFRWatching
** Description: cette fonction agit sur la robustification de la fonction FISA
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT:
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
**
** UInt16 Ext_tiTDC
**  Min = 0 Max = 100 Prec = 0.001
** SInt16  Ext_tCoMes
**  Min = -40 Max = 214 Prec = 1
** UInt16 AFReg_facCorRich
**  Min = 0 Max = 100 Prec = 0.01
**------------------------------------------------------------------------------
** RTE DataSendPoint
**------------------------------------------------------------------------------
** RTE Read IRV:
** Boolean FISA_bAuthClc
**  Min = 0 Max = 1 Prec = 1
** Boolean FISA_bAFRegWin
**  Min = 0 Max = 1 Prec = 1
**------------------------------------------------------------------------------
** RTE Written IRV:
** FISA_facDifAFReg
**  Min = 0 Max = 10 Prec = 0.01
**============================================================================*/
/************************************************************************************/
/*                                                                                  */
/* !Reference: CSMT CGMT07 1087 V1.3                                                */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                               */
/************************************************************************************/
FUNC(void,FISA_CODE) FISA_ConfirmFRWatching(void)
{
  /*Variables intermediaires non visualisable*/
  VAR(SInt16,AUTOMATIC)                      Ext_tCoMes ;
  VAR(UInt16,AUTOMATIC)                      Ext_tiTDC;
  VAR(UInt8,AUTOMATIC)                       u8Ext_tiTDC;			/* @V1.5 : variable rajouttee */
  VAR(UInt16,AUTOMATIC)                      AFReg_facCorRich;
  VAR(UInt16,AUTOMATIC)                      FISA_facAFRegMax_MP;
  VAR(UInt16,AUTOMATIC)                      FISA_facAFRegMin_MP;
  VAR(Boolean,AUTOMATIC)                     FISA_bAFRegWin;
  VAR(Boolean,AUTOMATIC)                     FISA_bAuthClc;

  VAR(SInt16,AUTOMATIC)                      FISA_facDifAFReg_s16;
  VAR(SInt16,AUTOMATIC)                      Inc_Accum_Sat_Confirm;
  VAR(Boolean,AUTOMATIC)                     Turn_ON_delay_out;

  /*lecture des entrees (RTE)*/
  FISA_GetExt_tiTDC( &(u8Ext_tiTDC));
  Ext_tiTDC = (UInt16)u8Ext_tiTDC;
  FISA_GetExt_tCoMes(&Ext_tCoMes);
  Ext_tCoMes = (SInt16) (Ext_tCoMes + OFFSET_TCOS_MES);
  FISA_GetAFReg_facCorRich(&AFReg_facCorRich);


  /*lecture des IRV*/
  FISA_bAuthClc = Rte_IrvRead_RE_FISA_CrankSync_bAuthClc();
  FISA_bAFRegWin = Rte_IrvRead_RE_FISA_CrankSync_bAFRegWin();

  /*calcul de FISA_facAFRegMax_MP et FISA_facAFRegMin_MP (lookuptable 1D)*/
  FISA_facAFRegMax_MP = lookup1D_U16(&FISA_facAFRegMax_map,Ext_tCoMes,&(X_FISA_facAFRegMax_lastIndex),1);
  FISA_facAFRegMin_MP = lookup1D_U16(&FISA_facAFRegMin_map,Ext_tCoMes,&(X_FISA_facAFRegMin_lastIndex),1);

  /* TU : Le dernier terme est toujours vrai pour l'instant car la constante est a 1,
      mais PSA pourrait la changer */

  if ( (!((FISA_facAFRegMin_MP < AFReg_facCorRich) && (FISA_facAFRegMax_MP > AFReg_facCorRich))) && FISA_bAFRegWin && FISA_bAcvAFRegWin_C )
  {
	if ((UInt32) ((UInt32)Ext_tiTDC + (UInt32) Ext_tiTDC_delay) < (UInt32)( MAXUSHORT))
	{
      Ext_tiTDC = (UInt16) (Ext_tiTDC + Ext_tiTDC_delay);
    }


    /*on sauvegarde Ext_tiTDC pour le prochain PMH*/
    if ( TRUE==FISA_firstTime )
    {
      Ext_tiTDC_delay = 0;
    }
    else
    {
      Ext_tiTDC_delay = Ext_tiTDC;
    }

    /* Ext_tiTDC a une precision de 0.1 et FISA_tiStrtAFReg_C de 0.001 */
    if ( Ext_tiTDC >= (((UInt16)FISA_tiStrtAFReg_C)*100))
    {
      Turn_ON_delay_out = TRUE ;
    }
    else
    {
      Turn_ON_delay_out = FALSE ;
    }
  }
  else
  {
    Ext_tiTDC_delay = 0 ;
    Turn_ON_delay_out = FALSE ;
  }

  /*on definit le signe de la multiplication (peut etre zero)*/
  if ( (AFReg_facCorRich == 100) || (FALSE == Turn_ON_delay_out ) )
  {
    Inc_Accum_Sat_Confirm = 0;
  }
  else
  {
    if ( AFReg_facCorRich < 100 )
    {
      Inc_Accum_Sat_Confirm = (SInt16) (-FISA_facAFReg_C)  ;
    }
    else
    {
      Inc_Accum_Sat_Confirm = (SInt16)FISA_facAFReg_C ;
    }
  }

  /*appel de la fonction accumu_sat_analisys*/
  /*la valeur qui a ete mise au niveau de l'Accum_Sat_Analyse a une precision de 0.0001 alors que FISA_facDifAFReg a une precision de 0.01*/
  FISA_facDifAFReg_s16 = Accum_Sat_Analyse_SInt16 (Inc_Accum_Sat_Confirm, FISA_FACAFREG_C_EXP, FISA_bAuthClc, (SInt16) FISA_facDecCorMax_C , FISA_FACDECCORMAX_C_EXP,(SInt16) FISA_facIncCorMax_C, FISA_FACINCCORMAX_C_EXP, &Accum_Sat_Analisys_mem, FISA_FACAFREG_C_EXP,FISA_firstTime);

  if (FISA_facDifAFReg_s16>0)
  {
    FISA_facDifAFReg_s16 = (SInt16) ( (FISA_facDifAFReg_s16+50)/100 );
  }
  else
  {
    FISA_facDifAFReg_s16 = (SInt16) ( (FISA_facDifAFReg_s16-50)/100 );
  }

  /*pour eviter un overflow*/
  FISA_facDifAFReg = Saturation_INT_S8 (FISA_facDifAFReg_s16,MAXSCHAR,MINSCHAR);

  /*@NS : 18/11/08 modif sur la saturation de FISA_facDifAFReg */
  /*      affectation de la visualisable */

  /* saturation entre FISA_facDecCorMax_C et  FISA_facIncCorMax_C	  		 */
  /*   if ((FISA_facDifAFReg <= FISA_facIncCorMax_C) && (FISA_facDifAFReg >= FISA_facDecCorMax_C)) */

  if (FISA_facDifAFReg > FISA_facIncCorMax_C)
  {
    FISA_facDifAFReg = (SInt8)FISA_facIncCorMax_C;
  }
  else
  {
  	  if (FISA_facDifAFReg < FISA_facDecCorMax_C)
  	  {
     		FISA_facDifAFReg = FISA_facDecCorMax_C;
  	  }
  }
  Rte_IrvWrite_RE_FISA_CrankSync_facDifAFReg (FISA_facDifAFReg);

}



#define FISA_STOP_SEC_CODE
#include "FISA_MemMap.h"

