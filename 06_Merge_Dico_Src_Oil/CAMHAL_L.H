/***************************************************************************
;**
;** FILE NAME      : CAMHAL_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CAMHAL_L_H
#define CAMHAL_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "CAMHAL_API.h"
#include "CAMHAL_E.h"
#include "CAMHAL_Typ.h"
#include "IfxGtm_Typ.h"
#include "TYPE.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define CAMHAL_bLONG_TOOTH                1
#define CAMHAL_bNSN_4CYL_ALLOWED          0
#define CAMHAL_bPSA_3CYL_ALLOWED          1
#define CAMHAL_bPSA_4CYL_ALLOWED          0
#define CAMHAL_bRSA_STD_ALLOWED           0
#define CAMHAL_bSHORT_TOOTH               0
#define CAMHAL_bSTANDARD_ALLOWED          1
#define CAMHAL_TBU_OFFSET                 16777216
#define CAMHAL_u16CAM_TOOTH_PER_RESOL     200
#define CAMHAL_u16COEF_DESIRED_RESOL      2
#define CAMHAL_u16COEF_TIMER_RESOL        1
#define CAMHAL_u16NO_CAMSHAFT             1
#define CAMHAL_u16NSN_4CYL_CAMSHAFT       2
#define CAMHAL_u16PERIOD_ANGLE            15360
#define CAMHAL_u16PSA_3CYL_CAMSHAFT       16
#define CAMHAL_u16PSA_4CYL_CAMSHAFT       32
#define CAMHAL_u16RLDB_TMR_RESOL          200
#define CAMHAL_u16RSA_STD_CAMSHAFT        4
#define CAMHAL_u16STANDARD_CAMSHAFT       8
#define CAMHAL_u16TIMEOUT_DETECT_RESOL    50000
#define CAMHAL_u16TIMEOUT_RESOL           10000000
#define CAMHAL_u8ENABLE_CAP_TH_NR_NSN     2
#define CAMHAL_u8FOUR_CYLINDERS           4
#define CAMHAL_u8LONG_TOOTH_RATIO_RESOL   8
#define CAMHAL_u8MAX_TEETH_NB             4
#define CAMHAL_u8PSA_4CYL_EDGE_NB         6
#define CAMHAL_u8THREE_CYLINDERS          3
#define CAMHAL_udtCHANNELS_NUMBER         2
#define CAMHAL_udtPATTERN_DETECTED        8
#define CAMHAL_udtPATTERN_DIAG_DISABLED   1
#define CAMHAL_udtPATTERN_DIAG_NOT_READY  2
#define CAMHAL_udtPATTERN_DIAG_OK         4
#define CAMHAL_udtPATTERN_IN_1_PERIOD     4
#define CAMHAL_udtPATTERN_IN_2_PERIOD     2
#define CAMHAL_udtPATTERN_NOT_DETECTED    1
#define CAMHAL_udtPOSITION_1              14
#define CAMHAL_udtPOSITION_2              4
#define CAMHAL_udtPOSITION_3              8
#define CAMHAL_udtPOSITION_4              0
#define CAMHAL_udtPOSITION_5              9
#define CAMHAL_udtPOSITION_6              3
#define CAMHAL_udtPOSITION_INIT           255

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a


#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
extern boolean CAMHAL_bACGInhibitFirstManager;
extern boolean CAMHAL_bBackwardRotationDetected;
extern CAMHAL_tudtChannel CAMHAL_udtEvtActivationChannel;
extern uint8 CAMHAL_u8AngClkGenEdgeCounter;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/



#endif /* CAMHAL_L_H */

/*-------------------------------- end of file -------------------------------*/
