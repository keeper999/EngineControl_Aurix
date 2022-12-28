/******************************************************************************/
/*                                                                            */
/* !Layer :             APPLI                                                 */
/*                                                                            */
/* !Component :         FISA                                                  */
/* !Description :                                                             */
/*                                                                            */
/* !Module :            FISA_SupervFctAdaptInj                                */
/* !Description :       Superviseur de fct d'adaptat. de l'inj. au demarrage  */
/*                                                                            */
/* !File :              FISA_SupervFctAdaptInj.h                              */
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/FISA/5-SOFT-LIV/FISA_SupervFct$*/
/* $Revision::   1.0       $$Author::   adelvare   $$Date::   16 Mar 2012 14:$*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/
#ifndef FISA_SUPERVFCTADAPTINJ_H_
#define FISA_SUPERVFCTADAPTINJ_H_



/******************************************************************************/
/* INCLUSIONS                                                                 */
/******************************************************************************/
#include "FISA_Calibration.h"
#include "FISA_lib.h"
#include "Rte_FISA.h"
#include "FISA_DetermVal.h"

/******************************************************************************/
/* DEFINITION OF CONSTANTS                                                    */
/******************************************************************************/

/******************************************************************************/
/* DEFINITION OF TYPES                                                        */
/******************************************************************************/

/******************************************************************************/
/* DEFINITION OF MACROS                                                       */
/******************************************************************************/

typedef enum Etats_M_Strategie
{
  ENTREE_M_Strategie,
  INIT_M_Strategie,
  INHIBITION_STRATEGIE,
  STRATEGIE_ACTIVE
} Enum_Etats_M_Strategie;

typedef enum Etats_M_Strategie_Active
{
  INIT_M_Strategie_Active,
  BESOIN_RICHE_SUR_DEFAUT_IMPLIQUE_INIT_RICHE_APPLIQUE_RICHE_SAVE_NOT,
  BESOIN_PAUVRE_IMPLIQUE_INIT_PAUVRE_APPLIQUE_PAUVRE,
  ANALYSE_ET_CORRECTION_EVENTUELLES
} Enum_Etats_M_Strategie_Active;

typedef enum Etats_M_Analyse
{
  ENTREE_M_Analyse,
  ANALYSE_DISCRIMINANTE,
  ANALYSE_AFTERSTART
} Enum_Etats_M_Analyse;

typedef enum Etats_M_Analyse_Discriminante
{
  ENTREE_Analyse_Discriminante,
  INIT_Analyse_Discriminante,
  ANALYSE_ON,
  MOTEUR_DEMARRE
} Enum_Etats_M_Analyse_Discriminante;

typedef enum Etats_M_Inst
{
  ENTREE_Inst,
  INIT_Inst,
  ANALYSE_Inst_ON,
  ANALYSE_INSTABILITE_INTERROMPUE_OU_FINIE
} Enum_Etats_M_Inst;

typedef enum Etats_M_Confirmation_FR
{
  ENTREE_Confirmation_FR,
  INIT_Confirmation_FR,
  ANALYSE_FR_ON,
  ANALYSE_FR_INTERROMPUE,
  ANALYSE_FR_TERMINEE
} Enum_Etats_M_Confirmation_FR;

typedef enum Etats_M_Correction
{
  ENTREE_Correction,
  INIT_Correction,
  AUTORISATION_APPLICATION_CORRECTION_ON,
  DEFAUT_SUR_DEM_EN_COURS_EGAL_FIN_ADAP_APPLIQUE_EN_COURS_SAVE_NOT,
  FIN_CORRECTION_DEM,
  BESOIN_PAUVRE_SUR_DEFAUT_EGAL_FIN_ADAP_APPLIQUE_PAUVRE_SAVE_NOT,
  CORRECTION_POST_DEM_INSTABILITY, FIN_CORRECTION_POST_DEM_INST,
  BESOIN_RICHE_SUR_DEFAUT_EGAL_ADAP_APPLIQUE_RICHE_SAVE_NOT,
  CORRECTION_POST_DEM_FR,
  FIN_CORRECTION_POST_DEM_FR
} Enum_Etats_M_Correction;

/******************************************************************************/
/* DECLARATION OF VARIABLES                                                   */
/******************************************************************************/

/******************************************************************************/
/* DECLARATION OF FUNCTIONS                                                   */
/******************************************************************************/

#define FISA_START_SEC_CODE
#include "FISA_MemMap.h"

extern FUNC(void,FISA_CODE) FISA_SupervInit(void);
extern FUNC(void,FISA_CODE) FISA_MachineCalculCalib(void);
extern FUNC(void,FISA_CODE) FISA_Sup_Step_M_Strategie(void);


#define FISA_STOP_SEC_CODE
#include "FISA_MemMap.h"

#endif /*FISA_SUPERVFCTADAPTINJ_H_*/
