/***************************************************************************
;**
;** FILE NAME      : ENGLIMEFCCORD_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ENGLIMEFCCORD_L_H
#define ENGLIMEFCCORD_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/


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

extern const uint8  ENGLIMEFCCORD_u8Inhib;

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

void ENGLIMEFCCORD_vidCoord_Lim_CME(void);
void ENGLIMEFCCORD_vidInitOutput(void);
void ENGLIMEFCCORD_vidLim_BVAuto_1(sint16 s16TqSys1, sint16 s16TqSys2, sint16 s16TqSys3);
void ENGLIMEFCCORD_vidLim_BVAuto_1_2(sint16 s16GbxBVAuto_1_2);
void ENGLIMEFCCORD_vidLim_BVAuto_2(sint16 s16TqSys1, sint16 s16TqSys2, sint16 s16TqSys3);
void ENGLIMEFCCORD_vidLim_BVAuto_2_2(sint16 s16ATBVAuto_2_2);
void ENGLIMEFCCORD_vidLim_ESP(sint16 s16TqSys1, sint16 s16TqSys2, sint16 s16TqSys3);
void ENGLIMEFCCORD_vidLim_ESP1(sint16 s16tqEfcESP1);
void ENGLIMEFCCORD_vidLim_ModSpt(sint16 s16TqSys1, sint16 s16TqSys2, sint16 s16TqSys3);
void ENGLIMEFCCORD_vidLim_ModSpt1(sint16 s16tqEfcModSpt1);
void ENGLIMEFCCORD_vidLim_Preventif(void);
void ENGLIMEFCCORD_vidLim_Stat_Air_Av(void);
void ENGLIMEFCCORD_vidLimit_Divers(void);
void ENGLIMEFCCORD_vidLimit_InterSys(void);
void ENGLIMEFCCORD_vidLimitCpleAirDsl(void);


#endif /* ENGLIMEFCCORD_L_H */

/*-------------------------------- end of file -------------------------------*/
