/******************************************************************************/
/*                                                                            */
/* !Layer :             APPLI                                                 */
/*                                                                            */
/* !Component :         FISA                                                  */
/* !Description :                                                             */
/*                                                                            */
/* !Module :            FISA_ConfirmationApDem                                */
/* !Description :       confirmation demande apprentissage FISA               */
/*                                                                            */
/* !File :              FISA_ConfirmationApDem.h                              */
/*                                                                            */
/* !Scope :             Public                                                */
/*                                                                            */
/* !Target :            All                                                   */
/*                                                                            */
/* !Vendor :            Valeo                                                 */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/LIBPSA/LOG/Ref/SWC_VEMS/FISA/LOG/FISA_ConfirmationApDem.h_v          $*/
/* $Revision::   1.9       $$Author::   flavergn   $$Date::   21 Jul 2010 16:$*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef _FISA_CONFIRMATIONAPDEM_H_
#define _FISA_CONFIRMATIONAPDEM_H_

#include "Rte_FISA.h"
#include "FISA_lib.h"
#include "FISA_calibration.h"
/******************************************************************************/
/* INCLUSIONS                                                                 */
/******************************************************************************/

/******************************************************************************/
/* DEFINITION OF CONSTANTS                                                    */
/******************************************************************************/

#define FISA_FACDELTAAVR_TITDC_LENGTH 100

#define STABILITY_INDICE_EXP -3

#define CST 100 /*cette valeur vaut 0.1 qui doit etre converti avec une precision de 0.001 (100*0.001 = 0.1)*/

#define FISA_FACDIFAFREG_EXP  -2

/******************************************************************************/
/* DEFINITION OF TYPES                                                        */
/******************************************************************************/

/******************************************************************************/
/* DEFINITION OF MACROS                                                       */
/******************************************************************************/

/******************************************************************************/
/* DECLARATION OF VARIABLES                                                   */
/******************************************************************************/

/*Declaration des varaiables intermediaires visualisables*/
#define FISA_START_SEC_INTERNAL_VAR_16BIT
#include "FISA_MemMap.h"


#define FISA_STOP_SEC_INTERNAL_VAR_16BIT
#include "FISA_MemMap.h"

#define FISA_START_SEC_INTERNAL_VAR_8BIT
#include "FISA_MemMap.h"


#define FISA_STOP_SEC_INTERNAL_VAR_8BIT
#include "FISA_MemMap.h"

#define FISA_START_SEC_INTERNAL_VAR_BOOLEAN
#include "FISA_MemMap.h"


#define FISA_STOP_SEC_INTERNAL_VAR_BOOLEAN
#include "FISA_MemMap.h"

/******************************************************************************/
/* DECLARATION OF FUNCTIONS                                                   */
/******************************************************************************/

#define FISA_START_SEC_CODE
#include "FISA_MemMap.h"

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
extern FUNC(void,FISA_CODE) FISA_ConfirmInit(void);

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
extern FUNC(void,FISA_CODE) FISA_ConfirmationApDem_main(void);


/*==============================================================================
** Name: FISA_ConfirmAfterInstabWatching
** Description: Analyse des instabilites de regime en apres demarrage
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT:
**------------------------------------------------------------------------------
** IN/OUT:
**============================================================================*/
extern FUNC(void,FISA_CODE) FISA_ConfirmAfterInstabWatching(void);


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
**============================================================================*/
extern FUNC(UInt16,FISA_CODE) Calcul_indicateur_stability(void);


/*==============================================================================
** Name:FISA_ConfirmFRWatching
** Description: cette fonction agit sur la robustification de la fonction FISA
**------------------------------------------------------------------------------
** IN:
**------------------------------------------------------------------------------
** OUT:
**------------------------------------------------------------------------------
** IN/OUT:
**============================================================================*/
extern FUNC(void,FISA_CODE) FISA_ConfirmFRWatching(void);


#define FISA_STOP_SEC_CODE
#include "FISA_MemMap.h"

#endif /* _FISA_CONFIRMATIONAPDEM_H_ */
