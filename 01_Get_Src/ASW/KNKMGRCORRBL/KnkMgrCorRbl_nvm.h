/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKMGRCORRBL_NVM                                        */
/* !Description     : KNKMGRCORRBL_NVM Component.                             */
/*                                                                            */
/* !Module          : KNKMGRCORRBL_NVM                                        */
/* !Description     : interface du module  KNKMGRCORRBL_NVM                   */
/*                                                                            */
/* !File            : KNKMGRCORRBL_NVM.H                                      */
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
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/Main/KNKMGRCORRBL_NVM.H_v                 $*/
/* $Revision::   1.1      $$Author::   vvoyer        $$Date::   05 Oct 2009 1$*/
/* $Author::   vvoyer                                $$Date::   05 Oct 2009 1$*/
/******************************************************************************/
#ifndef KNKMGRCORRBL_NVM_H
#define KNKMGRCORRBL_NVM_H

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/

/******************************************************************************/
/* CONSTANTS DECLARATION                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
#define KNKMGRCORRBL_START_SEC_VAR_16BIT
#include "KnkMgrCorRbl_MemMap.h"

/* Type:    UInt16                                                            */
extern VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurKnkRblCyl1[3][3];

/* Type:    UInt16                                                            */
extern VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurKnkRblCyl2[3][3];

/* Type:    UInt16                                                            */
extern VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurKnkRblCyl3[3][3];

/* Type:    UInt16                                                            */
extern VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurKnkRblCyl4[3][3];

/* Type:    UInt16                                                            */
extern VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurRblCyl1[3][3];

/* Type:    UInt16                                                            */
extern VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurRblCyl2[3][3];

/* Type:    UInt16                                                            */
extern VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurRblCyl3[3][3];

/* Type:    UInt16                                                            */
extern VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurRblCyl4[3][3];

#define KNKMGRCORRBL_STOP_SEC_VAR_16BIT
#include "KnkMgrCorRbl_MemMap.h"

#endif /*KNKMGRCORRBL_NVM_H */
/*-------------------------------- end of file -------------------------------*/

