/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* !Component       : GAR                                                     */
/* !Description     : Matrice GAR                                             */
/* !Module          : GDGAR                                                   */
/* !Vendor          : Valeo VEMS                                              */
/* !Reference       : PTS_DOC_5018281 / 15                                    */
/* !Release: 1                                                                */
/* !Integrity : Full                                                          */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/CONFIG/TOOL_CONFIG/GAR_TblDft.csv $*/
/* $Revision::   1.0   $$Author::   fsanch$$Date::   04 Mar 2014 11:19:38    $*/
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/******************************************************************************/

/* Code generate with GeneFRM  Vers 3.3  */

#ifndef _FRM_CALIBRATION_H_
#define _FRM_CALIBRATION_H_

#include "STD_Types.h"
#include "FRM.h"
#include "FRM_L.h"

extern uint16 FRM_abRawTypAcvOptRvCcDdCnt[FRM_FRM_NB];

#pragma section ".calib" a

extern const uint16 FRM_u16CrossNb;

extern const uint8 FRM_au16LD_To_FRM_NbFRM_C[FRM_LD_NB];

extern const uint16 FRM_au16LD_To_FRM_PosDeb_C[FRM_LD_NB];

extern const uint16 FRM_au16LD_To_FRM_Tab_C[FRM_NB_MAX_LD_TO_FRM_TAB];

extern const uint16 FRM_au16FRM_To_LD_NbLD_C[FRM_FRM_NB];

extern const uint16 FRM_au16FRM_To_LD_PosDeb_C[FRM_FRM_NB];

extern const uint16 FRM_au16FRM_To_LD_Tab_C[FRM_NB_MAX_LD_TO_FRM_TAB];

#pragma section

#endif /* _FRM_CALIBRATION_H_ */
