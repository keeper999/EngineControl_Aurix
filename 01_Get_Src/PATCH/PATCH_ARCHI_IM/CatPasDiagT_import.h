/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SWC Layer                                               */
/*                                                                            */
/* !Component       : CatPasDiagT                                             */
/* !Description     : CatPasDiagT Software Component                          */
/*                                                                            */
/* !Module          : CatPasDiagT                                             */
/* !Description     : Imported Declarations                                   */
/*                                                                            */
/* !File            : CatPasDiagT_import.h                                    */
/*                                                                            */
/* !Target          : All (optimized for "Generic->Custom")                   */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Fri Apr 13 15:53:59 2012                              */
/*   Model name       : CatPasDiagT_AUTOSAR.mdl                               */
/*   Model version    : 1.544                                                 */
/*   Root subsystem   : /CatPasDiagT                                          */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/Projets/EB_DT_6_2/LOG/ASW/Ref/CONFIG/PATCH_ARCHI_IM/CatPas$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   ynicaise                               $$Date::   18 Aug 2014 $*/
/******************************************************************************/
#ifndef RTW_HEADER_CatPasDiagT_import_h_
#define RTW_HEADER_CatPasDiagT_import_h_

#include "NOPROD.h"
#include "INJCTL_INJFARCTLMGR.H"
#include "ENGRUNST.H"
#include "GDFRM.h"
#include "GDGAR.H"

/* use by CATPASDIAGT ,  creer une issue our ce define à voir FTOU */
#define GDU_ST_PRESENT GDU_ETAT_PRESENT

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/

/* Type:    UInt16                                                          */
/* Slope:   0.015625                                                          */
/* Bias:    0.0                                                               */
/* Units:   mg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 1023.984375                                                       */
extern CONST(UInt16, CATPASDIAGT_CALIB) OxC_mO2StgThdGas_C;

/* Type:    UInt16                                                          */
/* Slope:   0.015625                                                          */
/* Bias:    0.0                                                               */
/* Units:   mg                                                                */
/* PhysMin: 0                                                                 */
/* PhysMax: 1023.984375                                                       */
extern CONST(UInt16, CATPASDIAGT_CALIB) OxC_mO2StgThd_C;

#endif                                 /* RTW_HEADER_CatPasDiagT_import_h_ */

/*-------------------------------- end of file -------------------------------*/
