/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFDFTLRN_NVM                                          */
/* !Description     : MISFDFTLRN_NVM Component.                               */
/*                                                                            */
/* !Module          : MISFDFTLRN_NVM                                          */
/* !Description     : interface du module  MISFDFTLRN_NVM                     */
/*                                                                            */
/* !File            : MISFDFTLRN_NVM.H                                        */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32BIT                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
#ifndef MISFDFTLRN_NVM_H
#define MISFDFTLRN_NVM_H

#include "Rte_type.h"

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
#define MISFDFTLRN_START_SEC_VAR_16BIT
#include "MISFDFTLRN_MemMap.h"

/* Type:    SInt16                                                            */
extern VAR(SInt16, MISFDFTLRN_VAR) Misf_prm_tiDlyExpWinLrn[4][9];

/* Type:    SInt16                                                            */
extern VAR(SInt16, MISFDFTLRN_VAR) Misf_prm_tiDlyTDCWinLrn[4][9];

/* Type:    SInt16                                                            */
extern VAR(SInt16, MISFDFTLRN_VAR) Misf_prm_tiDlyBdcWinLrn[4][9];

/* Type:    SInt16                                                            */
extern VAR(SInt16, MISFDFTLRN_VAR) Misf_prm_tiDlyLongWinLrn[4][9];


#define MISFDFTLRN_STOP_SEC_VAR_16BIT
#include "MISFDFTLRN_MemMap.h"

#endif /*MISFDFTLRN_NVM_H */
/*-------------------------------- end of file -------------------------------*/

