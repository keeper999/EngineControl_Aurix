/******************************************************************************/
/*                                                                            */
/* !Layer :                 APPLI                                             */
/*                                                                            */
/* !Component :             FISA                                              */
/* !Description :                                                             */
/*                                                                            */
/* !Module :                FISA_Calibration                                  */
/* !Description :       fichier de calibration FISA                           */
/*                                                                            */
/* !File :                  FISA_Calibration.c                                */
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
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/PSA/SWC-TURBO/FISA/5-SOFT-LIV/FIS$*/
/* $Revision::   1.0        $$Author::   adelvare   $$Date::   16 Mar 2012 14:$*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/
/*                                                                            */
/******************************************************************************/
#include "FISA_Calibration.h"

/************************************************************************/
/*                                                                      */
/*  Valeur de calibration pour le Bypass                                */
/*                                                                      */
/************************************************************************/
#define FISA_START_SEC_CALIB_BOOLEAN
#include "FISA_MemMap.h"

  CONST(Boolean,FISA_CALIB) FISA_INTEGRATION_TESTS_SC = FALSE;
  CONST(Boolean,FISA_CALIB) FISA_bAuthSave_BypC = 0;
  CONST(Boolean,FISA_CALIB) FISA_bGrdWin_BypC = 0;
  CONST(Boolean,FISA_CALIB) FISA_bInstWin_BypC = 0;
  CONST(Boolean,FISA_CALIB) FISA_bAFRegWin_BypC = 0;
  CONST(Boolean,FISA_CALIB) FISA_bRstAdpDone_BypC = 0;

  CONST(Boolean,FISA_CALIB)  FISA_bAcvGrdWin_C 	= 1 ;      /*  Unit : no ; precision : 1 ; min : 0 ; max : 1 ; init : 1 */
  CONST(Boolean,FISA_CALIB) FISA_bAcvAFRegWin_C  	= 1;       /*  Unit : no ; precision : 1 ; min : 0 ; max : 1 ; init : 1 */

#define FISA_STOP_SEC_CALIB_BOOLEAN
#include "FISA_MemMap.h"

#define FISA_START_SEC_CALIB_8BIT
#include "FISA_MemMap.h"

  CONST(UInt8,FISA_CALIB)   FISA_facAdp_BypC     = 0;
  CONST(SInt8,FISA_CALIB)   FISA_facDecMax_C     = -60 ;    /*  Unit : no ; precision : 0.01   ; min : -1 ; max : 0   ; init : -0.6  */
  CONST(UInt8,FISA_CALIB)   FISA_facIncMax_C     = 100 ;    /*  Unit : no ; precision : 0.01   ; min : 0  ; max : 1   ; init : 1	   */
  CONST(SInt8,FISA_CALIB)   FISA_facDecCorMax_C  = -10;     /*  Unit : no ; precision : 0.01   ; min : -1 ; max : 0   ; init : -0.1  */
  CONST(SInt8,FISA_CALIB)   FISA_facDecInst_C    = -10;     /*  Unit : no ; precision : 0.01   ; min : -1 ; max : 0   ; init : -0.1  */
  CONST(SInt8,FISA_CALIB)   FISA_facDecInstMax_C = -20;     /*  Unit : no ; precision : 0.01   ; min : -1 ; max : 0   ; init : -0.2  */
  CONST(UInt8,FISA_CALIB)   FISA_facIncCorMax_C  = 15;      /*  Unit : no ; precision : 0.01   ; min : 0  ; max : 1   ; init : 0.15  */
  CONST(UInt8,FISA_CALIB)   FISA_facIncInst_C    = 15;      /*  Unit : no ; precision : 0.01   ; min : 0  ; max : 1   ; init : 0.15  */
  CONST(UInt8,FISA_CALIB)   FISA_facIncInstMax_C = 40;      /*  Unit : no ; precision : 0.01   ; min : 0  ; max : 1   ; init : 0.4   */
  CONST(UInt8,FISA_CALIB)   FISA_noInstMax_C     = 25;      /*  Unit : no ; precision : 1      ; min : 0  ; max : 100 ; init : 25    */
  CONST(UInt8,FISA_CALIB)   FISA_noInstMin_C     = 5;       /*  Unit : no ; precision : 1      ; min : 0  ; max : 100 ; init : 5     */
  CONST(UInt8,FISA_CALIB)   FISA_noTDCInstAvr_C  = 5;       /*  Unit : no ; precision : 1      ; min : 0  ; max : 20  ; init : 5     */
  CONST(UInt8,FISA_CALIB)   FISA_tiStrtAFReg_C   = 10;      /*  Unit : s  ; precision : 0.1    ; min : 0  ; max : 10  ; init : 1     */
  CONST(UInt8,FISA_CARTO)   FISA_facPoor_C       = 0 ;      /*  Unit : no ; precision : 0.O1   ; min : 0  ; max : 1   ; init : 0	   */
  CONST(UInt8,FISA_CARTO)   FISA_facRich_C       = 100;     /*  Unit : no ; precision : 0.O1   ; min : 0  ; max : 1   ; init : 1     */
  CONST(UInt8,FISA_CARTO)   FISA_facSatLo_C       = 0 ;      /*  Unit : no ; precision : 0.O1   ; min : 0  ; max : 1   ; init : 0	   */
  CONST(UInt8,FISA_CARTO)   FISA_facSatHi_C       = 100;     /*  Unit : no ; precision : 0.O1   ; min : 0  ; max : 1   ; init : 1     */


#define FISA_STOP_SEC_CALIB_8BIT
#include "FISA_MemMap.h"

#define FISA_START_SEC_CALIB_16BIT
#include "FISA_MemMap.h"

  CONST(UInt16,FISA_CALIB) FISA_epsilon = 22204; /*parameter used to privent dividing by zero (replace divisor equal zero in division)*/

  CONST(SInt16,FISA_CALIB) FISA_tMinAdp_C            = -30 ;   /*  Unit : C      ; precision : 1      ; min : -40 ; max : 214 ; init :  -30  	*/
  CONST(SInt16,FISA_CALIB) FISA_tMaxAdp_C            = 40 ;    /*  Unit : C      ; precision : 1      ; min : -40 ; max : 214 ; init :  40  	*/
  CONST(UInt16,FISA_CALIB) FISA_spdMaxAdp_C          = 2*128 ; /*  Unit : Km/h   ; precision : 1/128  ; min : 0   ; max : 255 ; init :  2 	*/
  CONST(UInt16,FISA_CALIB) FISA_rAccPMaxHighAFReg_C  = 1702 ;  /*  Unit : %      ; precision : 0.1    ; min : 0   ; max : 100 ; init :  13.3 	*/
  CONST(UInt16,FISA_CALIB) FISA_rAccPMaxLowAFReg_C   = 1574 ;  /*  Unit : %      ; precision : 0.1    ; min : 0   ; max : 100 ; init :  12.3 	*/
  CONST(UInt16,FISA_CALIB) FISA_rAccPMinHighAFReg_C  = 0 ;     /*  Unit : %      ; precision : 0.1    ; min : 0   ; max : 100 ; init :  0 	*/
  CONST(UInt16,FISA_CALIB) FISA_rAccPMinLowAFReg_C   = 0 ;     /*  Unit : %      ; precision : 0.1    ; min : 0   ; max : 100 ; init :  0 	*/
  CONST(UInt16,FISA_CALIB) FISA_nMaxHighAFReg_C      = 2600 ;  /*  Unit : Trs/mn ; precision : 1      ; min : 0   ; max : 7500; init :  2600 	*/
  CONST(UInt16,FISA_CALIB) FISA_nMaxLowAFReg_C       = 2500 ;  /*  Unit : Trs/mn ; precision : 1      ; min : 0   ; max : 7500; init :  2500 	*/
  CONST(UInt16,FISA_CALIB) FISA_nMinHighAFReg_C      = 600 ;   /*  Unit : Trs/mn ; precision : 1      ; min : 0   ; max : 7500; init :  600 	*/
  CONST(UInt16,FISA_CALIB) FISA_nMinLowAFReg_C       = 500 ;   /*  Unit : Trs/mn ; precision : 1      ; min : 0   ; max : 7500; init :  500 	*/
  CONST(UInt16,FISA_CALIB) FISA_rAirLdMaxHighAFReg_C = 704 ;   /*  Unit : %      ; precision : 0.1    ; min : 0   ; max : 100 ; init :  44 	*/
  CONST(UInt16,FISA_CALIB) FISA_rAirLdMaxLowAFReg_C  = 688 ;   /*  Unit : %      ; precision : 0.1    ; min : 0   ; max : 100 ; init :  43 	*/
  CONST(UInt16,FISA_CALIB) FISA_rAirLdMinHighAFReg_C = 480 ;   /*  Unit : %      ; precision : 0.1    ; min : 0   ; max : 100 ; init :  30 	*/
  CONST(UInt16,FISA_CALIB) FISA_rAirLdMinLowAFReg_C  = 464 ;   /*  Unit : %      ; precision : 0.1    ; min : 0   ; max : 100 ; init :  29 	*/
  CONST(SInt16,FISA_CALIB) FISA_tMaxAFReg_C          = 35 ;    /*  Unit : C      ; precision : 1      ; min : -40 ; max : 214 ; init :  35 	*/
  CONST(SInt16,FISA_CALIB) FISA_tMinAFReg_C          = -10 ;   /*  Unit : C      ; precision : 1      ; min : -40 ; max : 214 ; init :  -10  	*/
  CONST(UInt16,FISA_CALIB) FISA_nEngThdDeac_C        = 7500 ;  /*  Unit : Trs/mn ; precision : 1      ; min : 0   ; max : 7500; init :  --- 	*/

  CONST(UInt16,FISA_CALIB) FISA_facAFReg_C           = 10;      /*  Unit : no    ; precision : 0.0001 ; min : 0   ; max : 1   ; init :  0.001 */
  CONST(UInt16,FISA_CALIB) FISA_tiInstChk_C          = 100;     /*  Unit : s     ; precision : 0.01   ; min : 0   ; max : 10  ; init :  1     */

#define FISA_STOP_SEC_CALIB_16BIT
#include "FISA_MemMap.h"

#define FISA_START_SEC_CARTO_8BIT
#include "FISA_MemMap.h"

  /*Name : FISA_facRstMax_T        Unit : no ; precision : 0.01 ; min : 0 ; max : 1 ; init : 0*/
  CONST(UInt8,FISA_CARTO)   FISA_facRstMax_T[FISA_FACRSTMAX_LENGTH] =
  {
    50 , 50 , 100 , 100 , 50 , 50 , 100 , 100 , 50 , 50 , 100 , 100
  };


  /*Name : FISA_facDecIni_T        Unit : no ; precision : 0.01 ; min : 0 ; max : 1 ; init : 0*/
  CONST(UInt8,FISA_CARTO)   FISA_facDecIni_T[FISA_FACDECINI_LENGTH] =
  {
    50 , 50 , 100 , 100 , 50 , 50 , 100 , 100 , 50 , 50 , 100 , 100
  };


  /*Name : FISA_noIgMsk_T   Unit : no ; precision : 1 ; min : 0 ; max : 100 ; init :    */
  CONST(UInt8,FISA_CARTO) FISA_noIgMsk_T[FISA_NOIGMSK_LENGTH] =
  {
    6 , 6 , 6 , 5 , 5 , 4 , 3 , 3 , 3 , 3 , 3 , 3
  };

  /*Name : FISA_noInjStopAdp_T    Unit : Trs/mn ; precision : 1 ; min : 0 ; max : 7500 ; init :   */
  CONST(UInt8,FISA_CARTO) FISA_noInjStopAdp_T[FISA_NOINJSTOPADP_LENGTH] =
  {
      6 , 6 , 6 , 5 , 5 , 4 , 3 , 3 , 3 , 3 , 3 , 3
  };

  CONST(UInt8,FISA_CARTO) FISA_facAltiRef_T[FISA_FACALTIREF_LENGTH] =
  {
    80 , 95 , 100 , 105
  };

  /*Name : FISA_facStepAdp_M    Unit : no ; precision : 0.01 ; min : -1 ; max : 1 ; init : no */
  /*Valeurs multipliees par dix pour eviter la perte de precision dans les calculs*/
  CONST(SInt8,FISA_CARTO) FISA_facStepAdp_M[FISA_FACSTEPADP_ROW_LENGTH][FISA_FACSTEPADP_COLUMN_LENGTH] =
  {
    { 84 , 80 , 40 , 0 , 0 , 0 , -20 , -40 , -50  },
    { 84 , 80 , 40 , 0 , 0 , 0 , -20 , -40 , -50  },
    { 84 , 80 , 40 , 0 , 0 , 0 , -20 , -40 , -50  },
    { 84 , 80 , 40 , 0 , 0 , 0 , -20 , -40 , -50  },
    { 84 , 80 , 40 , 0 , 0 , 0 , -20 , -40 , -50  },
    { 84 , 80 , 40 , 0 , 0 , 0 , -20 , -40 , -50  },
    { 84 , 80 , 40 , 0 , 0 , 0 , -20 , -40 , -50  },
    { 84 , 80 , 40 , 0 , 0 , 0 , -20 , -40 , -50  },
    { 84 , 80 , 40 , 0 , 0 , 0 , -20 , -40 , -50  },
    { 84 , 80 , 40 , 0 , 0 , 0 , -20 , -40 , -50  },
    { 84 , 80 , 40 , 0 , 0 , 0 , -20 , -40 , -50  },
    { 84 , 80 , 40 , 0 , 0 , 0 , -20 , -40 , -50  }
  };

  /*Name : FISA_facstrtGain_M     Unit : no ; precision : 0.01 ; min : 0 ; max : 1 ; init : no*/
  CONST(UInt8,FISA_CARTO) FISA_facStrtGain_M[FISA_FACSTRTGAIN_ROW_LENGTH][FISA_FACSTRTGAIN_COLUMN_LENGTH] =
  {
    { 0 , 50 , 75 , 100 , 100 , 100 , 100 , 75 , 50 , 40 , 30 , 0 , 0 },
    { 0 , 50 , 75 , 100 , 100 , 100 , 100 , 75 , 50 , 40 , 30 , 0 , 0 },
    { 0 , 50 , 75 , 100 , 100 , 100 , 100 , 75 , 50 , 40 , 30 , 0 , 0 },
    { 0 , 50 , 75 , 100 , 100 , 100 , 100 , 75 , 50 , 40 , 30 , 0 , 0 },
    { 0 , 50 , 75 , 100 , 100 , 100 , 100 , 75 , 50 , 40 , 30 , 0 , 0 },
    { 0 , 50 , 75 , 100 , 100 , 100 , 100 , 75 , 50 , 40 , 30 , 0 , 0 },
    { 0 , 50 , 75 , 100 , 100 , 100 , 100 , 75 , 50 , 40 , 30 , 0 , 0 },
    { 0 , 50 , 75 , 100 , 100 , 100 , 100 , 75 , 50 , 40 , 30 , 0 , 0 },
    { 0 , 50 , 75 , 100 , 100 , 100 , 100 , 75 , 50 , 40 , 30 , 0 , 0 },
    { 0 , 50 , 75 , 100 , 100 , 100 , 100 , 75 , 50 , 40 , 30 , 0 , 0 },
    { 0 , 50 , 75 , 100 , 100 , 100 , 100 , 75 , 50 , 40 , 30 , 0 , 0 },
    { 0 , 50 , 75 , 100 , 100 , 100 , 100 , 75 , 50 , 40 , 30 , 0 , 0 }
  };

  /*Name : FISA_bAcvInstWin_T       Unit : no ; precision : 1 ; min : 0 ; max : 1 ; init :  no*/
  CONST(UInt8,FISA_CARTO) FISA_bAcvInstWin_T[FISA_BACVINSTWIN_LENGTH] =
  {
    0 , 0 , 0 , 0 , 1 , 1 , 0 , 0 , 1 , 1 , 0 , 0
  };

#define FISA_STOP_SEC_CARTO_8BIT
#include "FISA_MemMap.h"

#define FISA_START_SEC_CARTO_16BIT
#include "FISA_MemMap.h"

  /*Name : FISA_pAirExtMes1_A         Unit : mbars ; precision : 1 ; min : 500 ; max : 1500 ; init :    */
  CONST(UInt16,FISA_CARTO) FISA_pAirExtMes1_A[FISA_PAIREXTMES1_LENGTH] =
  {
    800 , 900 , 1000 , 1100
  } ;

  /*Name : FISA_nEngRal1_A              Unit : Trs/mn ; precision : 1 ; min : 0 ; max : 7500 ; init :    */
  CONST(UInt16,FISA_CARTO) FISA_nEngRal1_A[FISA_NENGRAL1_LENGTH] =
  {
    650 , 700 , 800 , 900 , 1000 , 1200
  } ;

  /*Name :  FISA_tCoMes1_A            Unit : C ; precision : 1 ; min : -40 ; max : 214 ; init :      *//*les precalibrations sont approximees par rapport a la spec*/
  CONST(SInt16,FISA_CARTO) FISA_tCoMes1_A[FISA_TCOMES1_LENGTH]=
  {
  -30 , -25 , -24 , -11 , -9 , -4 , -2 , 14 , 16 , 27 , 29 , 90
  } ;

  /*Name :  FISA_tCoMes2_A            Unit : C ; precision : 1 ; min : -40 ; max : 214 ; init :      */
  CONST(SInt16,FISA_CARTO) FISA_tCoMes2_A[FISA_TCOMES2_LENGTH] =
  {
   -30 , -25 , -20 , -15 , -10 , 7 , 15 , 35 , 45 , 70 , 90 , 120
  } ;

  /*Name : FISA_nMinCrk_stCluOn_T   Unit : Trs/mn ; precision : 1 ; min : 0 ; max : 7500 ; init :   */
  CONST(UInt16,FISA_CARTO) FISA_nMinCrk_stCluOn_T[FISA_NMINCRK_STCLUON_LENGTH] =
  {
    53 , 55 , 56 , 57 , 60 , 71 , 71 , 71 , 71 , 71 , 71 , 71
  } ;

  /*Name :  FISA_nMinCrk_stCluOff_T   Unit : Trs/mn ; precision : 1 ; min : 0 ; max : 7500 ; init :   */
  CONST(UInt16,FISA_CARTO) FISA_nMinCrk_stCluOff_T[FISA_NMINCRK_STCLUOFF_LENGTH] =
  {
    53 , 55 , 56 , 57 , 60 , 71 , 71 , 71 , 71 , 71 , 71 , 71
  } ;

  /*Name : FISA_tiStrtInstChk_T   Unit : s ; precision : 0.1 ; min : 0 ; max : 100 ; init :     */
  CONST(UInt16,FISA_CARTO) FISA_tiStrtInstChk_T[FISA_TISTRTINSTCHK_LENGTH] =
  {
    60 , 50 , 50 , 30 , 30 , 30 , 20 , 20 , 20 , 20 , 20 , 20
  };

  /*Name : FISA_tiInstChkEnd_T    Unit : s ; precision : 0.1 ; min : 0 ; max : 100 ; init :     */
  CONST(UInt16,FISA_CARTO) FISA_tiInstChkEnd_T[FISA_TIINSTCHKEND_LENGTH] =
  {
    200 , 200 , 150 , 150 , 100 , 100 , 50 , 50 , 50 , 0 , 0 , 0
  };

  /*Name : FISA_tiAFRegChk_T    Unit : s ; precision : 0.1 ; min : 0 ; max : 100 ; init :     */
  CONST(UInt16,FISA_CARTO) FISA_tiAFRegChk_T[FISA_TIAFREGCHK_LENGTH] =
  {
    50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50 , 50
  };

  /*Name : FISA_uMinGdStrt_T  Unit : V ; precision : 0.1 ; min : 0 ; max : 32 ; init :   */  /*"precision" a redefinir : question IQR n : 13, defini comme 1 dans la spec CSMT_CGMT07_1085*/
  CONST(UInt16,FISA_CARTO) FISA_uMinGdStrt_T[FISA_UMINGDSTRT_LENGTH] =
  {
    650 , 650 , 650 , 650 , 650 , 650 , 650 , 650 , 650 , 650 , 650 , 650
  };


  /*Name : FISA_nMax_M      Unit : Trs/mn ; precision : 1 ; min : 0 ; max : 7500 ; init :   */
  CONST(UInt16,FISA_CARTO) FISA_nMax_M[FISA_NMAX_ROW_LENGTH][FISA_NMAX_COLUMN_LENGTH] =
  {
    { 1150 , 1200 , 1250 , 1300 , 1300 , 1300 },
    { 1150 , 1200 , 1250 , 1300 , 1300 , 1300 },
    { 1150 , 1200 , 1250 , 1300 , 1300 , 1300 },
    { 1150 , 1200 , 1250 , 1300 , 1300 , 1300 }
  };


  /*Name : FISA_facNeng1_A    Unit : no ; precision : 0.01 ; min : -1 ; max : 4 ; init :  */
  CONST(SInt16,FISA_CARTO) FISA_facNEng1_A[FISA_FACNENG1_LENGTH] =
  {
    -100 , 0 , 50 , 90 , 100 , 105 , 110 , 150 , 200
  };

  /*Name : FISA_nEngRef_A     Unit : Trs/mn ; precision : 1 ; min : 0 ; max : 7500 ; init :   */
  CONST(UInt16,FISA_CARTO) FISA_nEngRef1_A[FISA_NENGREF1_LENGTH] =
  {
    0 , 200 , 250 , 300 , 550 , 750 , 950 , 1100 , 1200 , 1300 , 1350 , 1400 , 1425
  };

  /*Name : FISA_noInj1_A    Unit : Trs/mn ; precision : 1 ; min : 0 ; max : 7500 ; init : no */
  CONST(UInt16,FISA_CARTO) FISA_noInj1_A[FISA_NOINJ1_LENGTH] =
  {
    0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 15 , 20
  };

  /*Name : FISA_nRefMT_stCluOn_M      Unit : Trs/mn ; precision : 1 ; min : -3500 ; max : 3500 ; init : no*/
  CONST(SInt16,FISA_CARTO) FISA_nRefMT_stCluOn_M[FISA_NREFMT_STCLUON_ROW_LENGTH][FISA_NREFMT_STCLUON_COLUMN_LENGTH] =
  {
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  }
  };

  /*Name : FISA_nRefMT_stCluOff_M     Unit : Trs/mn ; precision : 1 ; min : -3500 ; max : 3500 ; init : no*/
  CONST(SInt16,FISA_CARTO) FISA_nRefMT_stCluOff_M[FISA_NREFMT_STCLUOFF_ROW_LENGTH][FISA_NREFMT_STCLUOFF_COLUMN_LENGTH] =
  {
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  }
  };

  /*Name : FISA_nRefAT_M     Unit : Trs/mn ; precision : 1 ; min : -3500 ; max : 3500 ; init : no*/
  CONST(SInt16,FISA_CARTO) FISA_nRefAT_M[FISA_NREFAT_ROW_LENGTH][FISA_NREFAT_COLUMN_LENGTH] =
  {
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  },
    { 0 , 25 , 225 , 225 , 210 , 185 , 135 , 120 , 105 , 80 , 50 , 0 , 0  }
  };


  /*Name : FISA_facAFRegMax_T       Unit : no ; precision : 0.01 ; min : 0 ; max : 10 ; init :  no*/
  CONST(UInt16,FISA_CARTO) FISA_facAFRegMax_T[FISA_FACAFREGMAX_LENGTH] =
  {
    115 , 115 , 110 , 110 , 110 , 105 , 105 , 103 , 103 , 100 , 100 , 100
  };

  /*Name : FISA_facAFRegMin_T       Unit : no ; precision : 0.01 ; min : 0 ; max : 10 ; init :  no*/
  CONST(UInt16,FISA_CARTO) FISA_facAFRegMin_T[FISA_FACAFREGMIN_LENGTH] =
  {
    85 , 85 , 90 , 90 , 90 , 95 , 95 , 97 , 97 , 100 , 100 , 100
  };

  /*Name : FISA_facInstMax_T         Unit : no ; precision : 0.001 ; min : 0 ; max : 1 ; init :  no*/
  CONST(UInt16,FISA_CARTO) FISA_facInstMax_T[FISA_FACINSTMAX_LENGTH] =
  {
    6 , 6 , 5 , 5 , 4 , 4 , 3 , 3 , 3 , 3 , 3 , 3
  };

#define FISA_STOP_SEC_CARTO_16BIT
#include "FISA_MemMap.h"

