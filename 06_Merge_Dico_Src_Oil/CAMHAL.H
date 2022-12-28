/***************************************************************************
;**
;** FILE NAME      : CAMHAL.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CAMHAL_H
#define CAMHAL_H

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

#define CAMHAL_bFALLING_EDGE              0
#define CAMHAL_bRISING_EDGE               1
#define CAMHAL_u8DETECTED                 1
#define CAMHAL_u8ENG_SYNCHRONISED         8
#define CAMHAL_u8RUNNING                  2
#define CAMHAL_u8SYNCHRONISED             4
#define CAMHAL_udtCH_CM_72                1
#define CAMHAL_udtCH_CM_81                0
#define CAMHAL_udtCH_EXHAUST_CAMSHAFT     1
#define CAMHAL_udtCH_INTAKE_CAMSHAFT      0
#define CAMHAL_udtDOWNGRADED_MODE         4
#define CAMHAL_udtFIRST_CYLINDER          2
#define CAMHAL_udtFOURTH_CYLINDER         16
#define CAMHAL_udtNORMAL_MODE             2
#define CAMHAL_udtNOT_SET                 1
#define CAMHAL_udtSECOND_CYLINDER         4
#define CAMHAL_udtTHIRD_CYLINDER          8
#define CAMHAL_udtUNKNOWN_CYLINDER        1

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

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/



#endif /* CAMHAL_H */

/*-------------------------------- end of file -------------------------------*/
