/***************************************************************************
;**
;** FILE NAME      : VLVACTINMON.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTINMON_H
#define VLVACTINMON_H

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

extern const sint8  VlvAct_agInVlvDifThdMin_C;
extern const sint8  VlvAct_agInVlvThdMax_C;
extern const sint8  VlvAct_agInVlvThdMin_C;
extern const uint8  VlvAct_agInVlvAmpThdMin_C;
extern const uint8  VlvAct_agInVlvAmpThdMinC_C;
extern const uint8  VlvAct_agInVlvAmpThdMinH_C;
extern const uint8  VlvAct_agInVlvDifThdMax_C;
extern const uint8  VlvAct_nInVlvAmpC_C;
extern const uint8  VlvAct_nInVlvAmpH_C;
extern const uint8  VlvAct_tiOfsInVlvC_C;
extern const uint8  VlvAct_tiOfsInVlvH_C;
extern const sint16  VlvAct_agInVlvNegDif1_C;
extern const sint16  VlvAct_agInVlvNegDif2_C;
extern const sint16  VlvAct_agInVlvPosDif1_C;
extern const sint16  VlvAct_agInVlvPosDif2_C;
extern const sint16  VlvAct_tOilMaxInVlv_C;
extern const sint16  VlvAct_tOilMinInVlv_C;
extern const uint16  VlvAct_nEngMinInVlv_C;
extern const uint16  VlvAct_nInVlvPosStatThd_C;
extern const uint16  VlvAct_tiInVlvPosStatThd_C;

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

void VlvAct_Sdlfast_InMon(void);
void VLVACTINMON_vidEntryInit(void);


#endif /* VLVACTINMON_H */

/*-------------------------------- end of file -------------------------------*/
