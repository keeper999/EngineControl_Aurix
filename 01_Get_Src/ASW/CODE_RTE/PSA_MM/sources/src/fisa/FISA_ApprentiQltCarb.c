/******************************************************************************/
/*                                                                            */
/* !Layer :                APPLI                                              */
/*                                                                            */
/* !Component :            FISA                                               */
/* !Description :                                                             */
/*                                                                            */
/* !Module :               FISA_ApprentiQltCarb                               */
/* !Description :          Apprentissage qualite carburant                    */
/*                                                                            */
/* !File :                 FISA_ApprentiQltCarb.c                             */
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
/* $Archive::   P:/LIBPSA/LOG/Ref/SWC_VEMS/FISA/LOG/FISA_ApprentiQltCarb.c_v          $*/
/* $Revision::   1.18      $$Author::   adelvare   $$Date::   22 Dec 2011 10:$*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/
/* FISA_ApprentiQltCarb_main                                                  */
/* FISA_ApprentiQltCarb_Init                                                  */
/* FISA_ApprentiQltCarb_Reference_rpm_developpement                           */
/* FISA_ApprentiQltCarb_rpm_delta                                             */
/* FISA_ApprentiQltCarb_Adaptation_steps                                      */
/******************************************************************************/
/******************************************************************************/
/* INCLUSIONS                                                                 */
/******************************************************************************/
#include "FISA_ApprentiQltCarb.h"
#include "FISA_Runnables.h"

/******************************************************************************/
/*                                                                            */
/* DECLARATION OF GLOBAL VARIABLES                                            */
/*                                                                            */
/******************************************************************************/



/******************************************************************************/
/*                                                                            */
/* DECLARATION OF VARIABLES OF MODULE                                         */
/*                                                                            */
/******************************************************************************/

#define FISA_START_SEC_INTERNAL_VAR_8BIT
#include "FISA_MemMap.h"

/*Cette variable est visualisable sous sa forme UInt8 mais n'est pas utilisee (d'ou le message MISRA)*/
VAR(UInt8,FISA_VAR)  FISA_facStrtGain_MP;
VAR(SInt8,FISA_VAR)  FISA_facDifStrt ;		 /*delta de coefficient de qualite carburant (precision : 0.01    Min : 0    Max : 1*/
VAR(SInt8,FISA_VAR)  FISA_facStepAdp_MP; /*pas d'adaptation    (precision : 0.01    Min : -1    Max : 1*/
VAR(SInt8,FISA_VAR)  FISA_StepAdp_MP;

#define FISA_STOP_SEC_INTERNAL_VAR_8BIT
#include "FISA_MemMap.h"

#define FISA_START_SEC_INTERNAL_VAR_16BIT
#include "FISA_MemMap.h"

/* @NS : 18/11/08 : rajout du visualisable FISA_facDifStrt */

/* Variables visualisables et apparaissant sur l'A2L */

VAR(SInt16,FISA_VAR) FISA_facNStrt_MP ;      /*Quotient de prise de regime   (precision : 0.01    Min : -1      Max : 4 )		*/
VAR(SInt16,FISA_VAR) FISA_nDifEng_MP ;       /*Gradient de regime reel   	 (precision : 1    	  Min : -7500   Max : +7500 )	*/
VAR(SInt16,FISA_VAR) FISA_nDifBurns_MP ;     /*Gradient de regime cible		 (precision : 1    	  Min : -7500   Max : +7500 )	*/

#define FISA_STOP_SEC_INTERNAL_VAR_16BIT
#include "FISA_MemMap.h"

#define FISA_START_SEC_VAR_16BIT
#include "FISA_MemMap.h"

_STATIC_ VAR(SInt16,FISA_VAR) FISA_nDifBurns_delay1 ; /*FISA_nDifBurns_MP avec un retard de cycle*/

/*variables utilisees pour les look up tables qui gardent l'ancien index de chaque recherche*/

_STATIC_ VAR(UInt16,FISA_VAR)  X_FISA_nRefMT_stCluOn_lastIndex;
_STATIC_ VAR(UInt16,FISA_VAR)  Y_FISA_nRefMT_stCluOn_lastIndex;

_STATIC_ VAR(UInt16,FISA_VAR)  X_FISA_nRefMT_stCluOff_lastIndex;
_STATIC_ VAR(UInt16,FISA_VAR)  Y_FISA_nRefMT_stCluOff_lastIndex;

_STATIC_ VAR(UInt16,FISA_VAR)  X_FISA_nRefAT_lastIndex;
_STATIC_ VAR(UInt16,FISA_VAR)  Y_FISA_nRefAT_lastIndex;

_STATIC_ VAR(UInt16,FISA_VAR)  X_FISA_facAltiRef_lastIndex;

_STATIC_ VAR(UInt16,FISA_VAR)  X_FISA_facStrtGain_lastIndex;
_STATIC_ VAR(UInt16,FISA_VAR)  Y_FISA_facStrtGain_lastIndex;

_STATIC_ VAR(UInt16,FISA_VAR)  X_FISA_facStepAdp_lastIndex;
_STATIC_ VAR(UInt16,FISA_VAR)  Y_FISA_facStepAdp_lastIndex;

_STATIC_ VAR(UInt16,FISA_VAR)  X_FISA_noIgMsk_lastIndex;

/*variables utilisees pour sauvegarder la valeur de Ext_nEng au 1 et 2 PMH precedent*/
_STATIC_ VAR(UInt16,FISA_VAR)  EXT_nEng_1;  /*Ext_nEng at t-1     precision : 0.01  min : -1  max : 4*/

_STATIC_ VAR(SInt16,FISA_VAR)  FISA_facDifStrt_mem ; /*variable qui permet de garder FISA_facDifStrt a t-1 en memoire*/

#define FISA_STOP_SEC_VAR_16BIT
#include "FISA_MemMap.h"

#define FISA_START_SEC_VAR_32BIT
#include "FISA_MemMap.h"

_STATIC_ VAR(SInt32,FISA_VAR)  FISA_facStrtGain_MP_S32;
_STATIC_ VAR(SInt32,FISA_VAR)  FISA_facStepAdp_MP_S32 ; /*pas d'adaptation    (precision : 0.01    Min : -1    Max : 1*/

#define FISA_STOP_SEC_VAR_32BIT
#include "FISA_MemMap.h"

#define FISA_START_SEC_VAR_UNSPECIFIED
#include "FISA_MemMap.h"

_STATIC_ VAR(ts_fixed,AUTOMATIC) tmp;
_STATIC_ VAR(ts_fixed,AUTOMATIC) MinSat_f;
_STATIC_ VAR(ts_fixed,AUTOMATIC) MaxSat_f;

#define FISA_STOP_SEC_VAR_UNSPECIFIED
#include "FISA_MemMap.h"

#define FISA_START_SEC_CONST_UNSPECIFIED
#include "FISA_MemMap.h"

/*Creation de notre structure qui contient l'adresse de nos 3 tables (lookup table 2D)*/
_STATIC_ CONST(MAP_Table_2D_yU16_S16,AUTOMATIC) FISA_nRefMT_stCluOn_map =
{
  FISA_TCOMES2_LENGTH            /* taille de FISA_tCoMes2_A*/,
  FISA_NENGREF1_LENGTH           /* taille de FISA_nEngRef1_A*/,
  &(FISA_tCoMes2_A[0])           /* x_table: vector with x-values */,
  &(FISA_nEngRef1_A[0])          /* y_table: vector with y-values */,
  &(FISA_nRefMT_stCluOn_M[0][0]) /* z_table: matrix with z-values */
};

/*Creation de notre structure qui contient l'adresse de nos 3 tables (lookup table 2D)*/
_STATIC_ CONST(MAP_Table_2D_yU16_S16,AUTOMATIC) FISA_nRefMT_stCluOff_map =
{
  FISA_TCOMES2_LENGTH             /* taille de FISA_tCoMes2_A*/,
  FISA_NENGREF1_LENGTH            /* taille de FISA_nEngRef1_A*/,
  &(FISA_tCoMes2_A[0])            /* x_table: vector with x-values */,
  &(FISA_nEngRef1_A[0])           /* y_table: vector with y-values */,
  &(FISA_nRefMT_stCluOff_M[0][0]) /* z_table: matrix with z-values */
};

/*Creation de notre structure qui contient l'adresse de nos 3 tables (lookup table 2D)*/
_STATIC_ CONST(MAP_Table_2D_yU16_S16,AUTOMATIC) FISA_nRefAT_map =
{
  FISA_TCOMES2_LENGTH             /* taille de FISA_tCoMes2_A*/,
  FISA_NENGREF1_LENGTH            /* taille de FISA_nEngRef1_A*/,
  &(FISA_tCoMes2_A[0])            /* x_table: vector with x-values */,
  &(FISA_nEngRef1_A[0])           /* y_table: vector with y-values */,
  &(FISA_nRefAT_M[0][0])          /* z_table: matrix with z-values */
};

/*Creation de notre structure qui contient l'adresse de nos 2 tables (lookup table 1D)*/
_STATIC_ CONST(MAP_Table_1D_xU16_U8,AUTOMATIC) FISA_facAltiRef_map =
{
  FISA_PAIREXTMES1_LENGTH            /* taille de FISA_pAirExtMes1_A*/,
  &(FISA_pAirExtMes1_A[0])           /* x_table: vector with x-values */,
  &(FISA_facAltiRef_T[0])            /* z_table: matrix with z-values */
};

/*Creation de notre structure qui contient l'adresse de nos 3 tables*/
_STATIC_ CONST(MAP_Table_2D_U8,FISA_CARTO) FISA_facStrtGain_map =
{
  FISA_TCOMES2_LENGTH         /*taille de FISA_tCoMes2_A*/,
  FISA_NOINJ1_LENGTH          /* taille de FISA_noInj1_A*/,
  &(FISA_tCoMes2_A[0])        /* x_table: vector with x-values */,
  &(FISA_noInj1_A[0])         /* y_table: vector with y-values */,
  &(FISA_facStrtGain_M[0][0]) /* z_table: matrix with z-values */
};

/*Creation de notre structure qui contient l'adresse de nos 3 tables*/
_STATIC_ CONST(MAP_Table_2D_S8,FISA_CARTO) FISA_facStepAdp_map =
{
  FISA_TCOMES2_LENGTH        /*taille de FISA_tCoMes2_A*/,
  FISA_FACNENG1_LENGTH       /* taille de FISA_facNEng1_A*/,
  &(FISA_tCoMes2_A[0])       /* x_table: vector with x-values */,
  &(FISA_facNEng1_A[0])      /* y_table: vector with y-values */,
  &(FISA_facStepAdp_M[0][0]) /* z_table: matrix with z-values */
};

/*Creation de notre structure qui contient l'adresse de nos 2 tables (lookup table 1D)*/
_STATIC_ CONST(MAP_Table_1D_U8,AUTOMATIC) FISA_noIgMsk_map =
{
  FISA_TCOMES2_LENGTH            /* taille de FISA_nEngRef1_A*/,
  &(FISA_tCoMes2_A[0])           /* x_table: vector with x-values */,
  &(FISA_noIgMsk_T[0])           /* z_table: matrix with z-values */
};


#define FISA_STOP_SEC_CONST_UNSPECIFIED
#include "FISA_MemMap.h"


/******************************************************************************/
/* DEFINITION OF GLOBAL FUNCTIONS                                             */
/******************************************************************************/

#define FISA_START_SEC_CODE
#include "FISA_MemMap.h"


/*==============================================================================
** Name: FISA_ApprentiQltCarb_main
** Description: fonction principale de l'ensemble du bloc 1086 (apprentissage du facteur qualite carburant)
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT:
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
**
** UInt16  Ext_ctInj
**    compteur d'injection depuis la synchronisation   (precision : 1    Min : 0   Max : 65535 )
** UInt16  Ext_nEng
**    regime moteur instantane   (precision : 1    Min : 0   Max : 7500 )
** UInt16  Ext_pAirextMes
**    pression ambiante   (precision : 1    Min : 500   Max : 1500 )
** Boolean Ext_bCluPedPrss
**    booleen d'etat d'embrayage   (precision : 1    Min : 0   Max : 1 )
** UInt8   Ext_stGBxCf
**    type de transmission (0 : BVM , 1 : BMA , 2 : BVMP)    (precision : 1    Min : 0   Max : 2 )
** SInt16  Ext_tCoMes
**  temperature d'eau moteur   (precision : 1    Min : -40   Max : 214 )
**
**------------------------------------------------------------------------------
** RTE DataSendPoint
**------------------------------------------------------------------------------
** RTE Read IRV:
**
** Boolean FISA_bAuthClc
**   precision : 1    Min : 0   Max : 1
**------------------------------------------------------------------------------
** RTE Written IRV:
**
** UInt8  FISA_facDifStrt
**    delta de coefficient de qualite carburant   (precision : 0.01   Min : 0   Max : 1)
**
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/* !Reference: CSMT CGMT07 1086 V1.3                                             */
/* !Trace_To : Covers_GEENSYS_EXI_CODE_IMPL_FISA_APPRENTIQLTCARB_MAIN            */
/* !Trace_To : GEENSYS_EXI_CODE_TEST_FISA_APPRENTIQLTCARB_MAIN                   */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/


FUNC(void,FISA_CODE) FISA_ApprentiQltCarb_main (void)
{
    VAR(SInt16,AUTOMATIC)			 FISA_nDifBurns_ret ; /*Gradient de regime cibleprecision : 1    Min : -7500   Max : +7500 ) (retard)*/
    VAR(SInt16,AUTOMATIC)            FISA_facDifStrt_S16;     /*delta de coefficient de qualite carburant (precision : 0.01    Min : 0    Max : 1*/
    VAR(SInt8,AUTOMATIC)             FISA_facDifStrt_S8;     /*delta de coefficient de qualite carburant (precision : 0.01    Min : 0    Max : 1*/
    VAR(Boolean,AUTOMATIC)           FISA_bAuthClc ;      /*boolean d'autorisation de calcul (precision : 1    Min : 0    Max : 1*/

    if (TRUE==FISA_firstTime)
    {
      S32_to_fixed(0,0, &tmp);
      S32_to_fixed(MIN_SATURATION, MIN_SATURATION_EXP, &MinSat_f);
      S32_to_fixed(MAX_SATURATION, MAX_SATURATION_EXP, &MaxSat_f);
    }

    /*lecture de l'IRV FISA_bAuthClc*/
    FISA_bAuthClc = Rte_IrvRead_RE_FISA_CrankSync_bAuthClc();

    /*appel de la fonction qui calcule le delta de regime PMH a PMH*/
    FISA_nDifEng_MP = FISA_ApprentiQltCarb_rpm_delta();

    /*appel de la fonction qui definit le gradient de regime cible*/
    FISA_nDifBurns_MP = FISA_ApprentiQltCarb_Reference_rpm_developpement();

    /*appel de la fonction qui creee un retard de deux cycle en sortie*/
    if (TRUE==FISA_firstTime)
    {
      /* Au tout premier appel, la memoire en forcee a zero (vu avec simulink) */
      FISA_nDifBurns_delay1 = FISA_nDifBurns_MP; /* Altis 1682298 : il faut initialiser FISA_nDifBurns_delay1 à FISA_nDifBurns_MP pour prendre en compte les premiers PMH */
      FISA_nDifBurns_ret = 0;
    }
    else
    {
      FISA_nDifBurns_ret = Delay1_SINT16 (&FISA_nDifBurns_MP, &FISA_nDifBurns_delay1);
    }

    /*appel de la fonction qui divise FISA_nDifEng_MP par FISA_nDifBurns_MP */
    DivWithAntiDiVByZeroFix ( (SInt32) FISA_nDifEng_MP, (SInt32)FISA_NDIFENG_MP_EXP , (SInt32) FISA_nDifBurns_ret, FISA_NDIFBURNS_MP_EXP , &tmp);

    /*appel de la fonction de saturation entre MAX_SATURATION et MIN_SATURATION*/
    /* TU : La saturation empeche tout overflow sur le SInt16 */

    FISA_facNStrt_MP =  (SInt16)Saturation_tout_FIX (&tmp, &MaxSat_f, &MinSat_f, FISA_FACNSTRT_MP_EXP);

    /*appel de la fonction adaptation steps qui va permettre d'adapter le melange a la qualite reelle du carburant consomme par le moteur*/
    FISA_facStepAdp_MP_S32 = FISA_ApprentiQltCarb_Adaptation_steps();

    /*appel de Accum_Sat_Analyse qui calcul le delta du coefficient de l'entree puis ecriture dans l'IRV FISA_facDifStrt*/
    FISA_facDifStrt_S16 = Accum_Sat_Analisys_without_FIX ( (SInt16)FISA_facStepAdp_MP_S32, FISA_bAuthClc, (SInt16)FISA_facDecMax_C, (SInt16)FISA_facIncMax_C, &FISA_facDifStrt_mem, FISA_firstTime);

    /*pour eviter un overflow*/
    FISA_facDifStrt_S8 = Saturation_INT_S8 (FISA_facDifStrt_S16,MAXSCHAR,MINSCHAR);

   /*@NS : le 18/11/08 */
   /*@NS : modif pour que FISA_facDifStrt soit toujours compris dans [FISA_facDecMax_C ; FISA_facIncMax_C] */

    if ((FISA_facDifStrt_S8 <= FISA_facIncMax_C) && (FISA_facDifStrt_S8 >= FISA_facDecMax_C))
    {
      /* TU : La test precedent empeche d'ecrire une valeur hors plage */
      FISA_facDifStrt = FISA_facDifStrt_S8;
    }
    else
    {
    	if (FISA_facDifStrt_S8 < FISA_facDecMax_C)
    	{
      	FISA_facDifStrt = FISA_facDecMax_C;
    	}
    	else
    	{
      		if (FISA_facDifStrt_S8 > FISA_facIncMax_C)
			{
      			FISA_facDifStrt = (SInt8)FISA_facIncMax_C;
			}
		}
	}
    Rte_IrvWrite_RE_FISA_CrankSync_facDifStrt (FISA_facDifStrt);
}

/*==============================================================================
** Name: FISA_ApprentiQltCarb_Init
** Description: Initialise les variables intermediaires qui serviront pour la fonction globale
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT:
**------------------------------------------------------------------------------
** IN/OUT:
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/* !Reference: CSMT CGMT07 1086 V1.3                                             */
/* !Trace_To : Covers_GEENSYS_EXI_CODE_IMPL_FISA_APPRENTIQLTCARB_INIT            */
/* !Trace_To : GEENSYS_EXI_CODE_TEST_FISA_APPRENTIQLTCARB_INIT                   */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

FUNC(void,FISA_CODE) FISA_ApprentiQltCarb_Init(void)
{
  /*init des variables visualisables*/
  FISA_nDifEng_MP = 0;
  FISA_facNStrt_MP =0;
  FISA_nDifBurns_MP =0;
  FISA_facStepAdp_MP =0;
  FISA_StepAdp_MP =0;
  FISA_facStepAdp_MP_S32 =0;
  FISA_facStrtGain_MP =0;
  FISA_facStrtGain_MP_S32 =0;
  FISA_facDifStrt = 0;


  FISA_nDifBurns_delay1 = 0;   /*les variables de retard de FISA_nDifBurns_MP sont initialise a zero*/
  FISA_facDifStrt_mem = 0; /* la variable de retard est initialisee a zero */

  /*init des variables pr la recherche dans les lookup table*/
  X_FISA_nRefMT_stCluOn_lastIndex = 0;
  Y_FISA_nRefMT_stCluOn_lastIndex = 0;

  X_FISA_nRefMT_stCluOff_lastIndex = 0;
  Y_FISA_nRefMT_stCluOff_lastIndex = 0;

  X_FISA_nRefAT_lastIndex = 0;
  Y_FISA_nRefAT_lastIndex = 0;

  X_FISA_facAltiRef_lastIndex = 0;


  X_FISA_facStrtGain_lastIndex = 0;
  Y_FISA_facStrtGain_lastIndex = 0;

  X_FISA_facStepAdp_lastIndex = 0;
  Y_FISA_facStepAdp_lastIndex = 0;

  X_FISA_noIgMsk_lastIndex = 0;

  /*init des variables de retard*/
  EXT_nEng_1 = 0;

  Rte_IrvWrite_RE_FISA_init_facDifStrt(FISA_facDifStrt);
}


/******************************************************************************/
/* DEFINITION OF FUNCTIONS OF MODULE                                          */
/******************************************************************************/
/*==============================================================================
** Name: FISA_ApprentiQltCarb_Reference_rpm_developpement
** Description: Initialise les variables intermediaires qui serviront pour la fonction globale
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT:
** SInt16 FISA_nDifBurns_MP
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
**
** UInt16  Ext_nEng
**    regime moteur instantane   (precision : 1    Min : 0   Max : 7500 )
** UInt16  Ext_pAirextMes
**    pression ambiante   (precision : 1    Min : 500   Max : 1500 )
** Boolean Ext_bCluPedPrss
**    precision : 1    Min : 0   Max : 1
** UInt8   Ext_stGBxCf
**    type de transmission (0 : BVM , 1 : BMA , 2 : BVMP)    (precision : 1    Min : 0   Max : 2 )
** SInt16  Ext_tCoMes
**    temperature d'eau moteur   (precision : 1    Min : -40   Max : 214 )
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/* !Reference: CSMT CGMT07 1086 V1.3                                             */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/
FUNC(SInt16,FISA_CODE)  FISA_ApprentiQltCarb_Reference_rpm_developpement (void)
{
    /*sorties des lookup table*/
    VAR(SInt16,AUTOMATIC)                  output_nRef;
    VAR(SInt16,AUTOMATIC)                  output_facAltiRef;

    /*Declaration des variables intermediaires*/
    VAR(UInt16,AUTOMATIC)                  Ext_nEng ;
    VAR(UInt16,AUTOMATIC)                  Ext_pAirExtMes ;
    VAR(Boolean,AUTOMATIC)                 Ext_bCluPedPrss ;
    VAR(UInt8,AUTOMATIC)                   Ext_stGBxCf ;
    VAR(SInt16,AUTOMATIC)                  Ext_tCoMes ;

    /*declaration des structures pour la multiplication en fixe*/
    VAR(ts_fixed,AUTOMATIC)                Mul1_f;
    VAR(ts_fixed,AUTOMATIC)                Mul2_f;
    VAR(ts_fixed,AUTOMATIC)                result_f;

    /*lecture des variables globales RTE*/
    FISA_GetExt_nEng(&Ext_nEng);
    FISA_GetExt_pAirExtMes(&Ext_pAirExtMes);
    Ext_pAirExtMes = (UInt16)(Ext_pAirExtMes + OFFSET_AIR_EXT_MES);
	FISA_GetExt_bCluPedPrss(&Ext_bCluPedPrss);
    FISA_GetExt_stGBxCf(&Ext_stGBxCf);
	FISA_GetExt_tCoMes(&Ext_tCoMes);
    Ext_tCoMes = (SInt16) (Ext_tCoMes + OFFSET_TCOS_MES);

    /*init de output_nRef a zero pour etre sur qu'elle n'est pas une valeur absurde s'il est n'est pas mise a jour*/
    output_nRef = 0 ;

    /*en fonction du type de boite de vitesse*/
    switch ((SInt16)Ext_stGBxCf)
    {
      case BVM :
        /*si Ext_bCluPedPrss est egal a 1 on utilise la table FISA_nRefMT_stCluOn sinon FISA_nRefMT_stCluOff*/
        if ( TRUE == Ext_bCluPedPrss)
        {
          /*Calcul de FISA_nRefMT_stCluOn*/
          output_nRef = lookup2D_yU16_S16(&FISA_nRefMT_stCluOn_map, Ext_tCoMes, Ext_nEng, &(X_FISA_nRefMT_stCluOn_lastIndex),&(Y_FISA_nRefMT_stCluOn_lastIndex),10);
        }
        else
        {
          /*Calcul de FISA_nRefMT_stCluOff*/
          output_nRef = lookup2D_yU16_S16(&FISA_nRefMT_stCluOff_map, Ext_tCoMes, Ext_nEng, &(X_FISA_nRefMT_stCluOff_lastIndex),&(Y_FISA_nRefMT_stCluOff_lastIndex),10);
        }
      break;

      case BVA :
        /*Calcul de FISA_nRefAT*/
        output_nRef = lookup2D_yU16_S16(&FISA_nRefAT_map, Ext_tCoMes, Ext_nEng, &(X_FISA_nRefAT_lastIndex),&(Y_FISA_nRefAT_lastIndex),10);
      break;

      case BVMP :
        /*Calcul de FISA_nRefMT_stCluOn*/
        output_nRef = lookup2D_yU16_S16(&FISA_nRefMT_stCluOn_map, Ext_tCoMes, Ext_nEng, &(X_FISA_nRefMT_stCluOn_lastIndex),&(Y_FISA_nRefMT_stCluOn_lastIndex),10);
      break;

      default :
        FISA_erreur(FISA_ERREUR_APPRENTIQLT);
    }

    /*Calcul de facAltiRef*/
    output_facAltiRef = lookup1D_rS16_xU16_U8(&(FISA_facAltiRef_map),Ext_pAirExtMes,&(X_FISA_facAltiRef_lastIndex),10);

    /* QAC donne une erreur 3348 sur Mul1_f Mul2_f et result_f, comme quoi il ne sont pas initialises
       hors ils n'ont pas a l'etre car S16_to_fixed et MUL_FIX ne les prennent pas en const */
    S16_to_fixed(output_nRef, FISA_NREFAT_M_EXP, &Mul1_f);
    S16_to_fixed(output_facAltiRef, FISA_FACALTIREF_T_EXP-1, &Mul2_f);

    /*multiplication en fixe*/
    MUL_FIX(Mul1_f,Mul2_f,&result_f);

    /*passage de fixe en SInt16*/
    FISA_nDifBurns_MP = fixed_to_S16(&result_f,FISA_NDIFBURNS_MP_EXP);

    return(FISA_nDifBurns_MP);
}


/*==============================================================================
** Name: FISA_ApprentiQltCarb_rpm_delta
** Description: Calcule le delta de regime PMH a PMH
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT:
**
** SInt16 FISA_nDifEng_MP
**    Gradient de regime reel   (precision : 1    Min : -7500   Max : 7500)
**
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
**
** UInt16 Ext_nEng
**    regime moteur instantane  (precision : 1    Min : 0   Max : 7500)
**
**------------------------------------------------------------------------------
** RTE DataSendPoint
**------------------------------------------------------------------------------
** RTE Read IRV:
**------------------------------------------------------------------------------
** RTE Written IRV:
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/* !Reference: CSMT CGMT07 1086 V1.3                                             */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/
FUNC(SInt16,FISA_CODE) FISA_ApprentiQltCarb_rpm_delta (void)
{
  VAR(UInt16,AUTOMATIC)           EXT_nEng_tmp;
  VAR(UInt16,AUTOMATIC)           Ext_nEng;  /*regime moteur instantane   precision : 0.01  min : -1  max : 4*/

  FISA_GetExt_nEng (&Ext_nEng);/*lecture de Ext_nEng (variable du RTE)*/

  if (TRUE==FISA_firstTime)
  {
    /* Au tout premier appel, la memoire en forcee a zero (vu avec simulink) */
    EXT_nEng_1 = Ext_nEng; /* Altis 1681119 : il faut initialiser EXT_nEng_1 à la valeur de Ext_nEng pour que sa valeur soit pris en compte au pas d'après */
    EXT_nEng_tmp =0;
  }
  else
  {
    EXT_nEng_tmp = Delay1_UINT16 (&Ext_nEng, &EXT_nEng_1);   /*retrieve value at t -2 of Ext_nEng*/
  }

  FISA_nDifEng_MP = (SInt16) ( FISA_MIN((SInt32)Ext_nEng,MAXSSHORT) - ( FISA_MIN((SInt32)EXT_nEng_tmp,MAXSSHORT)) );/*calcul entre la valeur courante et la valeur a t-2*/

  return (FISA_nDifEng_MP);
}

/*==============================================================================
** Name: FISA_ApprentiQltCarb_Adaptation_steps
** Description: Initialise les variables intermediaires qui serviront pour la fonction globale
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT:
** SInt8 ret
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
**
** UInt16  Ext_nEng
**    regime moteur instantane   (precision : 1    Min : 0   Max : 7500 )
** SInt16  Ext_tCoMes
**  temperature d'eau moteur   (precision : 1    Min : -40   Max : 214 )
**------------------------------------------------------------------------------
** RTE Read IRV:
**
** Boolean FISA_bGrdWin
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/* !Reference: CSMT CGMT07 1086 V1.3                                             */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/
FUNC(SInt8,FISA_CODE) FISA_ApprentiQltCarb_Adaptation_steps (void)
{
    /*declaration des variables d'entree*/
    VAR(Boolean,AUTOMATIC)               FISA_bGrdWin;
    VAR(SInt16,AUTOMATIC)                Ext_tCoMes;
    VAR(UInt16,AUTOMATIC)                Ext_ctInj;
    VAR(SInt32,AUTOMATIC)                Ext_ctInj_signed;

    /*sortie de lookup 1D FISA_noIgMsk_T*/
    VAR(SInt16,AUTOMATIC)                FISA_noIgMsk_output ;

    /*Lecure des entrees via le RTE*/
    FISA_GetExt_tCoMes(&Ext_tCoMes);
    Ext_tCoMes = (SInt16) (Ext_tCoMes + OFFSET_TCOS_MES);
    FISA_GetExt_ctInj(&Ext_ctInj);

    /*Lecture de l'IRV FISA_bGrdWin*/
    FISA_bGrdWin = Rte_IrvRead_RE_FISA_CrankSync_bGrdWin();

    /*Calcul de FISA_noIgMsk*/
    FISA_noIgMsk_output = (SInt16) ( (lookup1D_rS16_U8(&(FISA_noIgMsk_map), Ext_tCoMes, &(X_FISA_noIgMsk_lastIndex),10)+5)/10 );
	
    Ext_ctInj_signed = ((SInt32)Ext_ctInj) - FISA_noIgMsk_output;

    /*Si Ext_ctInj est inferieur a zero, on la force a zero*/
    if ( 0 >= Ext_ctInj_signed )
    {
      Ext_ctInj = 0;
    }
    else
    {
      /* TU : Puisque l'on vient d'eliminer tous les cas negatifs,
         et comme Ext_ctInj a pour maximum MAXINT16, il n'y pas de risque de perte d'information dans le cast suivant */
      Ext_ctInj = (UInt16)Ext_ctInj_signed;
    }

    /*Calcul de FISA_facStrtGain_MP*/
    FISA_facStrtGain_MP_S32 = lookup2D_rS32_U8(&(FISA_facStrtGain_map), Ext_tCoMes, Ext_ctInj, &(X_FISA_facStrtGain_lastIndex), &(Y_FISA_facStrtGain_lastIndex),10);

    /*Calcul de FISA_facStepAdp_MP*/
    FISA_facStepAdp_MP_S32 = lookup2D_rS32_S8(&(FISA_facStepAdp_map), Ext_tCoMes, FISA_facNStrt_MP, &(X_FISA_facStepAdp_lastIndex), &(Y_FISA_facStepAdp_lastIndex));

  /* Altis 1683673 : ajout du visualisable FISA_StepAdp_MP */
	if ( (FISA_facStepAdp_MP_S32 > MAXSCHAR) || (FISA_facStepAdp_MP_S32 < MINSCHAR) )
  {
    FISA_erreur(FISA_ERREUR_HORSPLAGE);
  }
  else /*pas de debordement possible sinon erreur generee*/
  {
      FISA_StepAdp_MP = (SInt8)FISA_facStepAdp_MP_S32;
  }
	
		
    FISA_facStepAdp_MP_S32 = (SInt32)((FISA_facStepAdp_MP_S32 * FISA_facStrtGain_MP_S32)/1000);/*la division par mille remet dans une bonne precision*/
	
    FISA_facStrtGain_MP_S32 = (SInt32)(FISA_facStrtGain_MP_S32/10);
	
    if ( (FISA_facStrtGain_MP_S32 > MAXUCHAR) || (FISA_facStrtGain_MP_S32 < MINUCHAR) )
    {
        FISA_erreur(FISA_ERREUR_HORSPLAGE);
    }
    else /*pas de debordement possible sinon erreur generee precedemment*/
    {
       FISA_facStrtGain_MP = (UInt8)FISA_facStrtGain_MP_S32;
    }

   


    /*Si FISA_bAcvGrdWin_C AND FISA_bGrdWin est superieur a zero alors one retourne la valeur du calcul precedent sinon zero*/
    /* TU : La condition FISA_bGrdWin n'est pas testee car FISA_bAcvGrdWin_C est toujours vrai,
      mais PSA pourrait vouloir la changer */
    if ( 0 != (FISA_bAcvGrdWin_C && FISA_bGrdWin ) )
    {
      if ( (FISA_facStepAdp_MP_S32 > MAXSCHAR) || (FISA_facStepAdp_MP_S32 < MINSCHAR) )
   	  {
        FISA_erreur(FISA_ERREUR_HORSPLAGE);
      }
      else /*pas de debordement possible sinon erreur generee*/
      {
        FISA_facStepAdp_MP = (SInt8)FISA_facStepAdp_MP_S32;
      }
    }
    else
    {
      FISA_facStepAdp_MP = 0;
    }

	 /* Altis 1683673 : decalage de FISA_facStepAdp_MP à la sortie du bloc */
    return FISA_facStepAdp_MP;
}



#define FISA_STOP_SEC_CODE
#include "FISA_MemMap.h"
