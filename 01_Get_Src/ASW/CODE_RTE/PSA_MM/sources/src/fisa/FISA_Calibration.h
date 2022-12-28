/******************************************************************************/
/*                                                                            */
/* !Layer :             APPLI                                                 */
/*                                                                            */
/* !Component :         FISA                                                  */
/* !Description :                                                             */
/*                                                                            */
/* !Module :            FISA_calibration                                      */
/* !Description :       fichier de calibration FISA                           */
/*                                                                            */
/* !File :              FISA_calibration.h                                    */
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
/* $Archive::   P:/LIBPSA/LOG/Ref/SWC_VEMS/FISA/LOG/FISA_Calibration.h_v          $*/
/* $Revision::   1.15      $$Author::   adelvare$$Date::   22 Dec 2011 10:27:$*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/


#ifndef __FISA_CALIBRATION_H__
#define __FISA_CALIBRATION_H__

#include "Rte_FISA.h"


/************************************************************************/
/*  global parameters                                                   */
/************************************************************************/

#define OFFSET_AIR_EXT_MES	((UInt16) 0)
#define OFFSET_TCOS_MES   	((SInt16) 0)

#define FISA_START_SEC_CALIB_16BIT
#include "FISA_MemMap.h"

extern CONST(UInt16,FISA_CALIB) FISA_epsilon ;

#define FISA_STOP_SEC_CALIB_16BIT
#include "FISA_MemMap.h"

#define FISA_EPSILON_EXP -20

/************************************************************************/
/*                                                                      */
/*  Valeur de calibration pour le Bypass                                */
/*                                                                      */
/************************************************************************/
#define FISA_START_SEC_CALIB_BOOLEAN
#include "FISA_MemMap.h"

extern CONST(Boolean,FISA_CALIB) FISA_INTEGRATION_TESTS_SC;

extern CONST(Boolean,FISA_CALIB) FISA_bAuthSave_BypC ;
extern CONST(Boolean,FISA_CALIB) FISA_bGrdWin_BypC ;
extern CONST(Boolean,FISA_CALIB) FISA_bInstWin_BypC ;
extern CONST(Boolean,FISA_CALIB) FISA_bAFRegWin_BypC ;
extern CONST(Boolean,FISA_CALIB) FISA_bRstAdpDone_BypC ;

#define FISA_STOP_SEC_CALIB_BOOLEAN
#include "FISA_MemMap.h"

#define FISA_START_SEC_CALIB_8BIT
#include "FISA_MemMap.h"

extern CONST(UInt8,FISA_CALIB) FISA_facAdp_BypC ;

#define FISA_STOP_SEC_CALIB_8BIT
#include "FISA_MemMap.h"

/************************************************************************/
/*                                                                      */
/*  Sub module : CSMT_CGMT07_1085                                       */
/*                                                                      */
/************************************************************************/

/************************************************************************/
/*  variable parameters length                                          */
/************************************************************************/

#define FISA_PAIREXTMES1_LENGTH 4
#define FISA_NENGRAL1_LENGTH 6
#define FISA_TCOMES1_LENGTH 12
#define FISA_TCOMES2_LENGTH 12
#define FISA_NMINCRK_STCLUON_LENGTH 12
#define FISA_NMINCRK_STCLUOFF_LENGTH 12
#define FISA_UMINGDSTRT_LENGTH 12
#define FISA_NOINJSTOPADP_LENGTH 12
#define FISA_TISTRTINSTCHK_LENGTH 12
#define FISA_TIINSTCHKEND_LENGTH 12
#define FISA_TIAFREGCHK_LENGTH 12
#define FISA_NOIGMSK_LENGTH 12
#define FISA_NMAX_ROW_LENGTH 4
/*#define FISA_NMAX_COLUMN_LENGTH 5  bad definition on spec : IQR QU 19*/
#define FISA_NMAX_COLUMN_LENGTH 6

/************************************************************************/
/*  variable parameters precision                                       */
/************************************************************************/

/*Calibration*/
#define FISA_TMINADP_C_EXP 0
#define FISA_TMAXADP_C_EXP 0
#define FISA_SPDMAXADP_C_EXP /***!!!! precision de 1/127,9918 possible  : soit variable * (mantisse = 7813 et exp = -6) **/
#define FISA_RACCPMAXHIGHAFREG_C_EXP -1
#define FISA_RACCMAXLOWAFREG_C_EXP -1
#define FISA_RACCPMINHIGHAFREG_C_EXP -1
#define FISA_RACCPMINLOWAFREG_C_EXP -1
#define FISA_NMAXLOWAFREG_C_EXP 0
#define FISA_NMINHIGHAFREG_C_EXP 0
#define FISA_NMINLOWAFREG_C_EXP 0
#define FISA_RAIRLDMAXHIGHAFREG_C_EXP -1
#define FISA_RAIRLDMAXLOWAFREG_C_EXP -1
#define FISA_RAIRLDMINHIGHAFREG_C_EXP -1
#define FISA_RAIRLDMINLOWAFREG_C_EXP -1
#define FISA_TMAXAFREG_C_EXP 0
#define FISA_TMINAFREG_C_EXP 0

/*Cartographie*/
#define FISA_PAIREXTMES1_A_EXP 0
#define FISA_NENGRAL1_A_EXP 0
#define FISA_TCOMES1_C_EXP 0
#define FISA_TCOMES2_C_EXP 0
#define FISA_NMINCRK_STCLUON_T_EXP 0
#define FISA_NMINCRK_STCLUOFF_T_EXP 0
#define FISA_UMINGDSTRT_T_EXP -2
#define FISA_NOINJSTOPADP_T_EXP 0
#define FISA_TISTRTINSTCHK_T_EXP -1
#define FISA_TIINSTCHKEND_T_EXP -1
#define FISA_TIAFREGCHK_T_EXP -1
#define FISA_NOIGMSK_T_EXP 0
#define FISA_NMAX_M_EXP 0

/************************************************************************/
/*  variable parameters                                                 */
/************************************************************************/

#define FISA_START_SEC_CARTO_16BIT
#include "FISA_MemMap.h"

/************************************************************************/
/*  Dimension : 1                                                       */
/************************************************************************/

extern CONST(SInt16,FISA_CALIB) FISA_tMinAdp_C  ;
extern CONST(SInt16,FISA_CALIB) FISA_tMaxAdp_C ;
extern CONST(UInt16,FISA_CALIB) FISA_spdMaxAdp_C ;
extern CONST(UInt16,FISA_CALIB) FISA_rAccPMaxHighAFReg_C ;
extern CONST(UInt16,FISA_CALIB) FISA_rAccPMaxLowAFReg_C ;
extern CONST(UInt16,FISA_CALIB) FISA_rAccPMinHighAFReg_C  ;
extern CONST(UInt16,FISA_CALIB) FISA_rAccPMinLowAFReg_C  ;
extern CONST(UInt16,FISA_CALIB) FISA_nMaxHighAFReg_C ;
extern CONST(UInt16,FISA_CALIB) FISA_nMaxLowAFReg_C ;
extern CONST(UInt16,FISA_CALIB) FISA_nMinHighAFReg_C ;
extern CONST(UInt16,FISA_CALIB) FISA_nMinLowAFReg_C ;
extern CONST(UInt16,FISA_CALIB) FISA_rAirLdMaxHighAFReg_C ;
extern CONST(UInt16,FISA_CALIB) FISA_rAirLdMaxLowAFReg_C ;
extern CONST(UInt16,FISA_CALIB) FISA_rAirLdMinHighAFReg_C ;
extern CONST(UInt16,FISA_CALIB) FISA_rAirLdMinLowAFReg_C ;
extern CONST(SInt16,FISA_CALIB) FISA_tMaxAFReg_C ;
extern CONST(SInt16,FISA_CALIB) FISA_tMinAFReg_C ;
extern CONST(UInt16,FISA_CALIB) FISA_nEngThdDeac_C;


/************************************************************************/
/*  Dimension : [1 x 4]                                                 */
/************************************************************************/

extern CONST(UInt16,FISA_CARTO) FISA_pAirExtMes1_A[FISA_PAIREXTMES1_LENGTH] ;


/************************************************************************/
/*  Dimension : [1 x 6]                                                 */
/************************************************************************/

extern CONST(UInt16,FISA_CARTO) FISA_nEngRal1_A[FISA_NENGRAL1_LENGTH] ;


/************************************************************************/
/*  Dimension : [1 x 12]                                                */
/************************************************************************/

extern CONST(SInt16,FISA_CARTO) FISA_tCoMes1_A[FISA_TCOMES1_LENGTH] ;
extern CONST(SInt16,FISA_CARTO) FISA_tCoMes2_A[FISA_TCOMES2_LENGTH] ;
extern CONST(UInt16,FISA_CARTO) FISA_nMinCrk_stCluOn_T[FISA_NMINCRK_STCLUON_LENGTH] ;
extern CONST(UInt16,FISA_CARTO) FISA_nMinCrk_stCluOff_T[FISA_NMINCRK_STCLUOFF_LENGTH] ;
extern CONST(UInt16,FISA_CARTO) FISA_tiStrtInstChk_T[FISA_TISTRTINSTCHK_LENGTH] ;
extern CONST(UInt16,FISA_CARTO) FISA_tiInstChkEnd_T[FISA_TIINSTCHKEND_LENGTH] ;
extern CONST(UInt16,FISA_CARTO) FISA_tiAFRegChk_T[FISA_TIAFREGCHK_LENGTH] ;
extern CONST(UInt16,FISA_CARTO) FISA_uMinGdStrt_T[FISA_UMINGDSTRT_LENGTH] ;

#define FISA_STOP_SEC_CARTO_16BIT
#include "FISA_MemMap.h"

/************************************************************************/
/*  Dimension : [4x 5]                                                  */
/************************************************************************/

#define FISA_START_SEC_CARTO_16BIT
#include "FISA_MemMap.h"

extern CONST(UInt16,FISA_CARTO) FISA_nMax_M[FISA_NMAX_ROW_LENGTH][FISA_NMAX_COLUMN_LENGTH];

#define FISA_STOP_SEC_CARTO_16BIT
#include "FISA_MemMap.h"

/************************************************************************/
/*                                                                      */
/*  Sub module : CSMT_CGMT07_1086                                       */
/*                                                                      */
/************************************************************************/

/************************************************************************/
/*  variable parameters length                                          */
/************************************************************************/

/*#define FISA_PAIREXTMES1_LENGTH 4     !!! Already defined
#define FISA_TCOMES1_LENGTH 12              !!! Already defined
#define FISA_TCOMES2_LENGTH 12              !!! Already defined
#define FISA_NOIGMSK_LENGTH 12              !!! Already defined*/
#define FISA_FACALTIREF_LENGTH 4
#define FISA_FACNENG1_LENGTH 9
#define FISA_NENGREF1_LENGTH 13
#define FISA_NOINJ1_LENGTH  13
#define FISA_FACSTEPADP_ROW_LENGTH  12
#define FISA_FACSTEPADP_COLUMN_LENGTH 9
#define FISA_NREFMT_STCLUON_ROW_LENGTH  12
#define FISA_NREFMT_STCLUON_COLUMN_LENGTH 13
#define FISA_NREFMT_STCLUOFF_ROW_LENGTH 12
#define FISA_NREFMT_STCLUOFF_COLUMN_LENGTH  13
#define FISA_NREFAT_ROW_LENGTH  12
#define FISA_NREFAT_COLUMN_LENGTH 13
#define FISA_FACSTRTGAIN_ROW_LENGTH 12
#define FISA_FACSTRTGAIN_COLUMN_LENGTH  13


/************************************************************************/
/*  variable parameters precision                                       */
/************************************************************************/

/*Calibration*/
#define FISA_BACVGRDWIN_C_EXP 0
#define FISA_FACDECMAX_C_EXP -2
#define FISA_FACINCMAX_C_EXP -2

/*Cartographie*/
#define FISA_FACALTIREF_T_EXP -2
#define FISA_FACNENG1_A_EXP -2
#define FISA_NENGREF1_A_EXP 0
#define FISA_NOINJ1_A_EXP 0
#define FISA_FACSTEPADP_M_EXP -2
#define FISA_NREFMT_STCLUON_M_EXP 0
#define FISA_NREFMT_STCLUOFF_M_EXP 0
#define FISA_NREFAT_M_EXP 0
#define FISA_FACSTRTGAIN_M_EXP -2

/************************************************************************/
/*  variable parameters                                                 */
/************************************************************************/

/************************************************************************/
/*  Dimension : 1                                                       */
/************************************************************************/
#define FISA_START_SEC_CALIB_BOOLEAN
#include "FISA_MemMap.h"

extern CONST(Boolean,FISA_CALIB) FISA_bAcvGrdWin_C ;

#define FISA_STOP_SEC_CALIB_BOOLEAN
#include "FISA_MemMap.h"

#define FISA_START_SEC_CALIB_8BIT
#include "FISA_MemMap.h"

extern CONST(SInt8,FISA_CALIB)   FISA_facDecMax_C ;
extern CONST(UInt8,FISA_CALIB)   FISA_facIncMax_C ;

#define FISA_STOP_SEC_CALIB_8BIT
#include "FISA_MemMap.h"

#define FISA_START_SEC_CARTO_16BIT
#include "FISA_MemMap.h"

extern CONST(SInt16,FISA_CARTO) FISA_facNEng1_A[FISA_FACNENG1_LENGTH] ;

/************************************************************************/
/*  Dimension : [1 x 13]                                                */
/************************************************************************/

extern  CONST(UInt16,FISA_CARTO)  FISA_nEngRef1_A[FISA_NENGREF1_LENGTH] ;
extern  CONST(UInt16,FISA_CARTO)  FISA_noInj1_A[FISA_NOINJ1_LENGTH] ;

/************************************************************************/
/*  Dimension : [12 x 13]                                               */
/************************************************************************/

extern  CONST(SInt16,FISA_CARTO)  FISA_nRefMT_stCluOn_M[FISA_NREFMT_STCLUON_ROW_LENGTH][FISA_NREFMT_STCLUON_COLUMN_LENGTH] ;
extern  CONST(SInt16,FISA_CARTO)  FISA_nRefMT_stCluOff_M[FISA_NREFMT_STCLUOFF_ROW_LENGTH][FISA_NREFMT_STCLUOFF_COLUMN_LENGTH] ;
extern  CONST(SInt16,FISA_CARTO)  FISA_nRefAT_M[FISA_NREFAT_ROW_LENGTH][FISA_NREFAT_COLUMN_LENGTH] ;

#define FISA_STOP_SEC_CARTO_16BIT
#include "FISA_MemMap.h"

/************************************************************************/
/*                                                                      */
/*  Sub module : CSMT_CGMT07_1087                                       */
/*                                                                      */
/************************************************************************/

/*#define FISA_TCOMES1_LENGTH 12 ;              !!! Already defined
#define FISA_TCOMES2_LENGTH 12 ;                !!! Already defined*/
#define FISA_FACAFREGMAX_LENGTH 12
#define FISA_FACAFREGMIN_LENGTH 12
#define FISA_BACVINSTWIN_LENGTH 12
#define FISA_FACINSTMAX_LENGTH 12

/************************************************************************/
/*  variable parameters precision                                       */
/************************************************************************/

/*Calibration*/
#define FISA_BACVAFREGWIN_C_EXP 0
#define FISA_FACDECCORMAX_C_EXP -2
#define FISA_FACDECINST_C_EXP -2
#define FISA_FACDECINSTMAX_C_EXP -2
#define FISA_FACINCCORMAX_C_EXP -2
#define FISA_FACINCINST_C_EXP -2
#define FISA_FACINCINSTMAX_C_EXP -2
#define FISA_FACAFREG_C_EXP -4
#define FISA_NOINSTMAX_C_EXP 0
#define FISA_NOINSTMIN_C_EXP 0
#define FISA_NOTDCINSTAVR_C_EXP 0
#define FISA_TIINSTCHK_C_EXP -2
#define FISA_TISTRTAFREG_C_EXP -1

/*Cartographie*/
#define FISA_FACAFREGMAX_T_EXP -2
#define FISA_FACAFREGMIN_T_EXP -2
#define FISA_BACVINSTWIN_T_EXP 0
#define FISA_FACINSTMAX_T_EXP -3

/************************************************************************/
/*  variable parameters                                                 */
/************************************************************************/

/************************************************************************/
/*  Dimension : 1                                                       */
/************************************************************************/

#define FISA_START_SEC_CALIB_BOOLEAN
#include "FISA_MemMap.h"

extern CONST(Boolean,FISA_CALIB) FISA_bAcvAFRegWin_C ;

#define FISA_STOP_SEC_CALIB_BOOLEAN
#include "FISA_MemMap.h"

#define FISA_START_SEC_CALIB_8BIT
#include "FISA_MemMap.h"

extern CONST(SInt8,FISA_CALIB)   FISA_facDecCorMax_C ;
extern CONST(SInt8,FISA_CALIB)   FISA_facDecInst_C ;
extern CONST(SInt8,FISA_CALIB)   FISA_facDecInstMax_C ;
extern CONST(UInt8,FISA_CALIB)   FISA_facIncCorMax_C ;
extern CONST(UInt8,FISA_CALIB)   FISA_facIncInst_C ;
extern CONST(UInt8,FISA_CALIB)   FISA_facIncInstMax_C ;
extern CONST(UInt8,FISA_CALIB)   FISA_noInstMax_C ;
extern CONST(UInt8,FISA_CALIB)   FISA_noInstMin_C ;
extern CONST(UInt8,FISA_CALIB)   FISA_noTDCInstAvr_C ;
extern CONST(UInt8,FISA_CALIB)   FISA_tiStrtAFReg_C ;

#define FISA_STOP_SEC_CALIB_8BIT
#include "FISA_MemMap.h"

#define FISA_START_SEC_CALIB_16BIT
#include "FISA_MemMap.h"

extern CONST(UInt16,FISA_CALIB) FISA_facAFReg_C ;
extern CONST(UInt16,FISA_CALIB) FISA_tiInstChk_C ;

#define FISA_STOP_SEC_CALIB_16BIT
#include "FISA_MemMap.h"

/************************************************************************/
/*  Dimension : [1 x 12]                                                */
/************************************************************************/

#define FISA_START_SEC_CARTO_16BIT
#include "FISA_MemMap.h"

extern CONST(UInt16,FISA_CARTO)  FISA_facAFRegMax_T[FISA_FACAFREGMAX_LENGTH] ;
extern CONST(UInt16,FISA_CARTO)  FISA_facAFRegMin_T[FISA_FACAFREGMIN_LENGTH] ;
extern CONST(UInt16,FISA_CARTO)  FISA_facInstMax_T[FISA_FACINSTMAX_LENGTH] ;

#define FISA_STOP_SEC_CARTO_16BIT
#include "FISA_MemMap.h"

/************************************************************************/
/*                                                                      */
/*  Sub module : CSMT_CGMT07_1088                                       */
/*                                                                      */
/************************************************************************/

#define FISA_FACRSTMAX_LENGTH 12
#define FISA_FACDECINI_LENGTH 12
#define FISA_TCOMESX_LENGTH 12

/************************************************************************/
/*  variable parameters precision                                       */
/************************************************************************/

/*Calibration*/
#define FISA_FACPOOR_C_EXP -2
#define FISA_FACRICH_C_EXP -2

/*Cartographie*/
#define FISA_FACRSTMAX_T_EXP -2

/************************************************************************/
/*  variable parameters                                                 */
/************************************************************************/

/************************************************************************/
/*  Dimension : 1                                                       */
/************************************************************************/

#define FISA_START_SEC_CALIB_8BIT
#include "FISA_MemMap.h"

extern CONST(UInt8,FISA_CALIB)   FISA_facPoor_C ;
extern CONST(UInt8,FISA_CALIB)   FISA_facRich_C ;
extern CONST(UInt8,FISA_CALIB)   FISA_facSatHi_C ;
extern CONST(UInt8,FISA_CALIB)   FISA_facSatLo_C ;

#define FISA_STOP_SEC_CALIB_8BIT
#include "FISA_MemMap.h"

/************************************************************************/
/*  Dimension : [1 x 12]                                                */
/************************************************************************/

#define FISA_START_SEC_CARTO_8BIT
#include "FISA_MemMap.h"

extern CONST(UInt8,FISA_CARTO) FISA_facRstMax_T[FISA_FACRSTMAX_LENGTH] ;     /*  Unit : no ; precision : 0.01 ; min : 0 ; max : 1 ; init : 0*/
extern CONST(UInt8,FISA_CARTO) FISA_facDecIni_T[FISA_FACDECINI_LENGTH];
extern CONST(UInt8,FISA_CARTO)  FISA_noInjStopAdp_T[FISA_NOINJSTOPADP_LENGTH] ;
extern CONST(UInt8,FISA_CARTO)  FISA_noIgMsk_T[FISA_NOIGMSK_LENGTH] ;
extern CONST(UInt8,FISA_CARTO) FISA_facAltiRef_T[FISA_FACALTIREF_LENGTH] ;

/************************************************************************/
/*  Dimension : [12 x 9]                                                */
/************************************************************************/

extern CONST(SInt8,FISA_CARTO)  FISA_facStepAdp_M[FISA_FACSTEPADP_ROW_LENGTH][FISA_FACSTEPADP_COLUMN_LENGTH] ;
extern CONST(UInt8,FISA_CARTO)  FISA_facStrtGain_M[FISA_FACSTRTGAIN_ROW_LENGTH][FISA_FACSTRTGAIN_COLUMN_LENGTH] ;
extern CONST(UInt8,FISA_CARTO)  FISA_bAcvInstWin_T[FISA_BACVINSTWIN_LENGTH] ;

#define FISA_STOP_SEC_CARTO_8BIT
#include "FISA_MemMap.h"

#endif /*  __FISA_CALIBRATION_H__ */
