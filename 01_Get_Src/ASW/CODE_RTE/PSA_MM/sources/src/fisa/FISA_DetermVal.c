/******************************************************************************/
/*                                                                            */
/* !Layer :                 APPLI                                             */
/*                                                                            */
/* !Component :             FISA                                              */
/* !Description :                                                             */
/*                                                                            */
/* !Module :                FISA_DetermVal                                    */
/* !Description :           Determination des valeurs de coefficient          */
/*                          de qualite carburant                              */
/* !File :                  FISA_DetermVal.c                                  */
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
/* $Archive::   P:/LIBPSA/LOG/Ref/SWC_VEMS/FISA/LOG/FISA_DetermVal.c_v          $*/
/* $Revision::   1.19      $$Author::   adelvare$$Date::   22 Dec 2011 10:$*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/
/*FISA_DetermFuelQuality                                                      */
/*FISA_DetermInit                                                             */
/*ComputeFacIniCur                                                            */
/*ComputeFacAdpCur                                                            */
/******************************************************************************/
/******************************************************************************/
/* INCLUSIONS                                                                 */
/******************************************************************************/
#include "FISA_DetermVal.h"
#include "FISA_lib.h"
#include "FISA_Runnables.h"

/*************************************
** LOCAL VARIABLES
*************************************/

#define FISA_START_SEC_VAR_16BIT
#include "FISA_MemMap.h"

/*variables utilisees pour les look up tables qui gardent l'ancien index de chaque recherche*/
_STATIC_ VAR(UInt16,AUTOMATIC)         X_FISA_facRstMax_lastIndex;
_STATIC_ VAR(UInt16,AUTOMATIC)         X_FISA_facDecIni_lastIndex;

#define FISA_STOP_SEC_VAR_16BIT
#include "FISA_MemMap.h"

#define FISA_START_SEC_VAR_BOOLEAN
#include "FISA_MemMap.h"

/*variables servant a la fonction de double retard*/
_STATIC_ VAR(Boolean,FISA_VAR) FISA_bRstAdpDone_n0;
_STATIC_ VAR(Boolean,FISA_VAR) FISA_bRstAdpDone_n1;

#define FISA_STOP_SEC_VAR_BOOLEAN
#include "FISA_MemMap.h"

#define FISA_START_SEC_INTERNAL_VAR_8BIT
#include "FISA_MemMap.h"

/*Valeur initialisee du coefficient de qualite carburant*/
 VAR(UInt8,FISA_VAR)   FISA_facIni_MP;    /*   Unite : non ; precision : 0.01 ; min : 0 ; max : 1 ; init :  non  */

/*Delta de coefficient de qualite carburant issu du demarrage en cours*/
/*cette variable est ecrite et jamais utilisee car c'est une variable observable*/
VAR(UInt8,FISA_VAR)   FISA_facDif_MP;     /*   Unite : non ; precision : 0.01 ; min : 0 ; max : 1 ; init :  non  */

#define FISA_STOP_SEC_INTERNAL_VAR_8BIT
#include "FISA_MemMap.h"


#define FISA_START_SEC_CONST_UNSPECIFIED
#include "FISA_MemMap.h"

/*Creation de notre structure qui contient l'adresse de nos 2 tables (lookup table 1D)*/
_STATIC_ CONST(MAP_Table_1D_U8,AUTOMATIC) FISA_facRstMax_map =
{
  (UInt8)FISA_TCOMES2_LENGTH     /* taille de FISA_tCoMes2_A*/,
  &(FISA_tCoMes2_A[0])           /* x_table: vector with x-values */,
  &(FISA_facRstMax_T[0])         /* z_table: matrix with z-values */
};



/*Creation de notre structure qui contient l'adresse de nos 2 tables (lookup table 1D)*/
_STATIC_ CONST(MAP_Table_1D_U8,AUTOMATIC) FISA_facDecIni_map =
{
  (UInt8)FISA_TCOMES2_LENGTH     /* taille de FISA_tCoMes2_A*/,
  &(FISA_tCoMes2_A[0])           /* x_table: vector with x-values */,
  &(FISA_facDecIni_T[0])         /* z_table: matrix with z-values */
};


#define FISA_STOP_SEC_CONST_UNSPECIFIED
#include "FISA_MemMap.h"


/*************************************
** GLOBALS FUNCTIONS
*************************************/
#define FISA_START_SEC_CODE
#include "FISA_MemMap.h"


/*==============================================================================
** Name:  FISA_DetermInit
** Description: cette fonction est appele pour initialiser les variables
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
** UInt8 idxTypIni
**  Min = 1 Max = 4 Prec = 1
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/* !Reference: CSMT CGMT07 1088 V1.3                                             */
/* !Trace_To : Covers_GEENSYS_EXI_CODE_IMPL_FISA_DETERMINIT                      */
/* !Trace_To : GEENSYS_EXI_CODE_TEST_FISA_DETERMINIT                             */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : A. Vrignon (GEENSYS)                                           */
/*********************************************************************************/


/*initialisation des variables*/
FUNC(void,FISA_CODE) FISA_DetermInit(void)
{
  /*initialisation des sorties a 0 (FALSE pr les booleens)*/
  /* On n'initialise pas FISA_facAdp_NV a zero puisque la variable est deja a jour */
  FISA_Update_bRstAdpDone(FALSE);

  /*init pour le double retard*/
  FISA_bRstAdpDone_n0 = FALSE;
  FISA_bRstAdpDone_n1 = FALSE;

  /*init des variables intermediaires*/
  FISA_facDif_MP = 0;
  FISA_facIni_MP = 0;

  X_FISA_facRstMax_lastIndex = 0;
  X_FISA_facDecIni_lastIndex = 0;

  /* Altis 1613245 : le rte était mis à jour mais pas le visualisable */
  FISA_idxTypIni = RICH;
  Rte_IrvWrite_RE_FISA_CrankSync_idxTypIni(RICH);
}

/*==============================================================================
** Name:  FISA_DetermFuelQuality
** Description: cette fonction calcule le coefficient de qualite du craburant
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT:
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
** UInt8 FISA_facRst
**  Min = 0 Max = 100 Prec = 0.01
** UInt8 FISA_facOld
**  Min = 0 Max = 100 Prec = 0.01
**------------------------------------------------------------------------------
** RTE DataSendPoint
** UInt8 u8localFISA_facAdp
**  Min = 0 Max = 128 Prec = 0.0078125
** Boolean FISA_bRstAdpDone
**  Min = 0 Max = 1 Prec = 1
**------------------------------------------------------------------------------
** RTE Read IRV:
** UInt8 idxTypIni
**  Min = 1 Max = 4 Prec = 1
** UInt8 idxTypFac
**  Min = 1 Max = 4 Prec = 1
** UInt8 facDifStrt
**  Min = 0 Max = 100 Prec = 0.01
** UInt8 facDifAst
**  Min = 0 Max = 100 Prec = 0.01
** UInt8 facDifAFReg
**  Min = 0 Max = 100 Prec = 0.01
**------------------------------------------------------------------------------
** RTE Written IRV:
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/* !Reference: CSMT CGMT07 1088 V1.3                                             */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : A. Vrignon (GEENSYS)                                           */
/*********************************************************************************/


/*programme principal de la fonction*/

FUNC(void,FISA_CODE) FISA_DetermFuelQuality(void)
{
  VAR(SInt16,AUTOMATIC)         richesse;
  VAR(Boolean,AUTOMATIC)        res_delay;
  VAR(Boolean,AUTOMATIC)        erreur;
  VAR(UInt8,AUTOMATIC)          u8localFISA_facAdp_0v01;
  VAR(UInt8,AUTOMATIC)          u8localFISA_facAdp_0v0078125;
  VAR(UInt8, AUTOMATIC)         u8local_FISA_facOldDec_NV;

  erreur = FALSE;

  /*initialisation du coefficient de qualite carburant (FISA_facIni_MP)*/
  richesse = (SInt8)Rte_IrvRead_RE_FISA_CrankSync_idxTypIni();

  u8local_FISA_facOldDec_NV = ComputeFacOldDec_NV(); /* Resol = 0.01 */
  
  switch(richesse)
  {
    case RICH:
      FISA_facIni_MP      = FISA_facRich_C;
      FISA_bRstAdpDone_n0 = FALSE;
      break;

    case POOR:
      FISA_facIni_MP      = FISA_facPoor_C;
      FISA_bRstAdpDone_n0 = FALSE;
      break;

    case OLD:
      FISA_facIni_MP = u8local_FISA_facOldDec_NV ;
      FISA_bRstAdpDone_n0 = FALSE;
      break;

    case CURRENT:
      FISA_facIni_MP      = ComputeFacIniCur();
      FISA_bRstAdpDone_n0 = TRUE;
      break;

    default:
      /*appel de la fonction d'erreur avec l'ID de l'erreur*/
      FISA_erreur (FISA_ERREUR_DETERMVAL);
      erreur = TRUE;
  }

  if (FALSE == erreur)
  {
    /*saturation de FISA_facIni_MP le cas echeant*/
    FISA_facIni_MP =  Saturation_INT_U8 (FISA_facIni_MP, FISA_facSatHi_C, FISA_facSatLo_C);

    if (TRUE==FISA_firstTime)
    {
      FISA_bRstAdpDone_n1 = 0;
      FISA_bRstAdpDone_n0 = 0;
      res_delay = 0;
    }
    else
    {
      /*Mise a jour du booleen indiquant que l'utilisation du reset sur detection de remplissage carburant a eu lieu*/
      res_delay = Delay1_Boolean( &FISA_bRstAdpDone_n0, &FISA_bRstAdpDone_n1);
    }

	FISA_Update_bRstAdpDone(res_delay);


    /*calcul du coefficient applique de qualite carburant (u8localFISA_facAdp)*/

    richesse = (SInt16)Rte_IrvRead_RE_FISA_CrankSync_idxTypFac();


    switch(richesse)
    {
      case RICH:
        u8localFISA_facAdp_0v01 = FISA_facRich_C;
        break;

      case POOR:
        u8localFISA_facAdp_0v01 = FISA_facPoor_C;
        break;

      case OLD:
        u8localFISA_facAdp_0v01 = u8local_FISA_facOldDec_NV;
        break;

      case CURRENT:
        u8localFISA_facAdp_0v01 = ComputeFacAdpCur();
        break;

      default:
        /*appel de la fonction d'erreur avec l'ID de l'erreur*/
        FISA_erreur (FISA_ERREUR_DETERMVAL);
        erreur = TRUE;
        u8localFISA_facAdp_0v01 = FISA_facRich_C;
    }

    if (FALSE == erreur)
    {
      /*calcul de FISA_facDif_MP*/
      if (u8localFISA_facAdp_0v01 > FISA_facIni_MP)
      {
        FISA_facDif_MP = (UInt8) (u8localFISA_facAdp_0v01 - FISA_facIni_MP) ;
      }
      else
      {
        FISA_facDif_MP = (UInt8) (FISA_facIni_MP - u8localFISA_facAdp_0v01);
      }
	  
      u8localFISA_facAdp_0v0078125 = (UInt8) ((u8localFISA_facAdp_0v01 * 128 + 50) / 100);
      FISA_Update_facAdp(u8localFISA_facAdp_0v0078125);
    }
  }
}

/*************************************
** LOCAL FUNCTIONS
*************************************/

/*==============================================================================
** Name:  ComputeFacIniCur
** Description: calcule le coefficient de qualite carburant de reset
** maxi pour la reinitialisation apres detection d'un plein
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT: UInt8 facIniCur
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
** SInt16  Ext_tCoMes
**  Min = -40 Max = 214 Prec = 1
** UInt8 FISA_facRst
**  Min = 0 Max = 100 Prec = 0.01
**------------------------------------------------------------------------------
** RTE DataSendPoint
**------------------------------------------------------------------------------
** RTE Read IRV:
**------------------------------------------------------------------------------
** RTE Written IRV:
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/* !Reference: CSMT CGMT07 1088 V1.3                                             */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : A. Vrignon (GEENSYS)                                           */
/*********************************************************************************/

FUNC(UInt8,FISA_CODE) ComputeFacIniCur(void)
{
    
  /*variables locales*/
  VAR(UInt8,AUTOMATIC)                   facIniCur;

  /*declaration des variables d'entree*/
  VAR(SInt16,AUTOMATIC)                  Ext_tCoMes ;
  VAR(UInt8,AUTOMATIC)                   FISA_facRst;

  /*Coefficient de qualite carburant de reset maxi*/
  VAR(UInt8,AUTOMATIC)          FISA_facRstMax;  /*    Unite : non  ; precision : 0.01 ; min : 0 ; max : 1 ; init : non*/

  
  /*Lecture des entrees via le RTE*/
  FISA_GetExt_tCoMes(&Ext_tCoMes);
  Ext_tCoMes = (SInt16) (Ext_tCoMes + OFFSET_TCOS_MES);
 
  FISA_GetfacRst(&FISA_facRst);

  /*calcul de FISA_facRstMax (sortie de la look-up table)*/
  FISA_facRstMax = lookup1D_U8(&(FISA_facRstMax_map), Ext_tCoMes, &(X_FISA_facRstMax_lastIndex),1,1);
   
  
  /*on recupere le plus petit entre FISA_facRst et FISA_facRstMax*/
  facIniCur = (UInt8)FISA_U8MIN(FISA_facRst, FISA_facRstMax);

  return (facIniCur);
}

/*==============================================================================
** Name:  ComputeFacOldDec_NV
**------------------------------------------------------------------------------
** IN: FISA_facOld_NV (Resol = 0.0078125)
**------------------------------------------------------------------------------
** OUT: UInt8 FISA_facOldDec_NV (Resol = 0.01)
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
**------------------------------------------------------------------------------
** RTE DataSendPoint
**------------------------------------------------------------------------------
** RTE Read IRV:
**------------------------------------------------------------------------------
** RTE Written IRV:
**============================================================================*/
FUNC(UInt8,FISA_CODE) ComputeFacOldDec_NV(void)
{
  /*variables locales*/
  VAR(UInt8,AUTOMATIC)                   facOldDec_NV;
  VAR(UInt8,AUTOMATIC)                   u8local_carto;
  VAR(SInt16,AUTOMATIC)                  s16local_sub;

  /*declaration des variables d'entree*/
  VAR(SInt16,AUTOMATIC)                  Ext_tCoMes ;
  VAR(UInt8,AUTOMATIC)                   u8local_facOld_NV;


  /*Lecture des entrees via le RTE*/
  FISA_GetExt_tCoMes(&Ext_tCoMes);
  Ext_tCoMes = (SInt16) (Ext_tCoMes + OFFSET_TCOS_MES);
       
  FISA_GetfacOld(&u8local_facOld_NV); /* Resol = 0.0078125 */
  u8local_facOld_NV = (UInt8) ((u8local_facOld_NV * 100 + 64) / 128); /* Resol = 0.01 */
  u8local_carto = lookup1D_U8(&(FISA_facDecIni_map), Ext_tCoMes, &(X_FISA_facDecIni_lastIndex),1,1); /* Resol = 0.01 */

  s16local_sub = (SInt16)((SInt16)u8local_facOld_NV - (SInt16)u8local_carto);
  if (s16local_sub > (SInt16)MAXUCHAR)
  {
    s16local_sub = MAXUCHAR;
  }
  else if (s16local_sub < (SInt16)MINUCHAR)
  {
    s16local_sub = MINUCHAR;
  }

  facOldDec_NV = Saturation_INT_U8((UInt8)s16local_sub, FISA_facSatHi_C, FISA_facSatLo_C);
  
  return (facOldDec_NV);
}




/*==============================================================================
** Name:  ComputeFacAdpCur
** Description: calcule le coefficient de qualite carburant actuel
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT: UInt8 facAdpCur
**------------------------------------------------------------------------------
** IN/OUT:
**------------------------------------------------------------------------------
** RTE DataReceivePoint
**------------------------------------------------------------------------------
** RTE DataSendPoint
**------------------------------------------------------------------------------
** RTE Read IRV:
** UInt8 facDifStrt
**  Min = 0 Max = 100 Prec = 0.01
** UInt8 facDifAst
**  Min = 0 Max = 100 Prec = 0.01
** UInt8 facDifAFReg
**  Min = 0 Max = 100 Prec = 0.01
**------------------------------------------------------------------------------
** RTE Written IRV:
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/* !Reference: CSMT CGMT07 1088 V1.3                                             */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : A. Vrignon (GEENSYS)                                           */
/*********************************************************************************/

FUNC(UInt8,FISA_CODE) ComputeFacAdpCur(void)
{
  /*variable locale*/
  VAR(UInt8,AUTOMATIC)   facAdpCur;
  VAR(SInt8,AUTOMATIC)   facDif;


  facDif = Rte_IrvRead_RE_FISA_CrankSync_facDifStrt();
  /* FISA_facAdpCur calcule avec le coefficient de qualite carburant (FISA_facDifStrt : recuperer par l'analyse du gradient du regime moteur) et la valeur a l'init (FISA_facIni_MP) */

  if (((SInt16)((SInt16)FISA_facIni_MP+(SInt16)facDif)) > (SInt16)MAXUCHAR)
  {
    facAdpCur = MAXUCHAR;
  }
  else if (((SInt16)((SInt16)FISA_facIni_MP+(SInt16)facDif)) < (SInt16)0)
  {
    facAdpCur = 0;
  }
  else
  {
    facAdpCur = (UInt8) (FISA_facIni_MP + facDif);
  }
  facAdpCur = Saturation_INT_U8(facAdpCur, FISA_facSatHi_C, FISA_facSatLo_C );
  facDif = Rte_IrvRead_RE_FISA_CrankSync_facDifAst();

/*@NS: le 18/11/08 */
/*@NS: debut modif sur les saturations pour le calcul de facAdpCur */
  if (((SInt16)((SInt16)facAdpCur + (SInt16)facDif)) > (SInt16)MAXUCHAR)
  {
    facAdpCur = MAXUCHAR;
  }
  else if (((SInt16)((SInt16)facAdpCur + (SInt16)facDif)) < (SInt16)0)
  {
	facAdpCur = 0;
  }
  else
  {
    facAdpCur = (UInt8) (facAdpCur + facDif);
  }

/*@NS: Fin modif sur les saturations pour le calcul de facAdpCur */


  facAdpCur = Saturation_INT_U8(facAdpCur, FISA_facSatHi_C, FISA_facSatLo_C );
  facDif = Rte_IrvRead_RE_FISA_CrankSync_facDifAFReg();

  /*FISA_facAdpCur calcule avec le coefficient de qualite carburant (FISA_facDifAFReg : recupere par le facteur du control de richesse) */

/*@NS: le 18/11/08 */
/*@NS: debut modif sur les saturations pour le calcul de facAdpCur */

  if (((SInt16)((SInt16)facAdpCur + (SInt16)facDif)) > (SInt16)MAXUCHAR)
  {
    facAdpCur = MAXUCHAR;
  }
  else if (((SInt16)((SInt16)facAdpCur + (SInt16)facDif)) < (SInt16)0)
  {
    facAdpCur = 0;
  }
  else
  {
    facAdpCur = (UInt8) (facAdpCur + facDif);
  }

  facAdpCur = Saturation_INT_U8(facAdpCur, FISA_facSatHi_C, FISA_facSatLo_C);

  return facAdpCur;
}

#define FISA_STOP_SEC_CODE
#include "FISA_MemMap.h"

