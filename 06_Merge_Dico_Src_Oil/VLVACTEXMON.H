/***************************************************************************
;**
;** FILE NAME      : VLVACTEXMON.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VLVACTEXMON_H
#define VLVACTEXMON_H

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

extern const sint8  VlvAct_agExVlvDifThdMin_C;
extern const sint8  VlvAct_agExVlvThdMax_C;
extern const sint8  VlvAct_agExVlvThdMin_C;
extern const uint8  VlvAct_agExVlvAmpThdMin_C;
extern const uint8  VlvAct_agExVlvAmpThdMinC_C;
extern const uint8  VlvAct_agExVlvAmpThdMinH_C;
extern const uint8  VlvAct_agExVlvDifThdMax_C;
extern const uint8  VlvAct_nExVlvAmpC_C;
extern const uint8  VlvAct_nExVlvAmpH_C;
extern const uint8  VlvAct_tiOfsExVlvC_C;
extern const uint8  VlvAct_tiOfsExVlvH_C;
extern const sint16  VlvAct_agExVlvNegDif1_C;
extern const sint16  VlvAct_agExVlvNegDif2_C;
extern const sint16  VlvAct_agExVlvPosDif1_C;
extern const sint16  VlvAct_agExVlvPosDif2_C;
extern const sint16  VlvAct_tOilMaxExVlv_C;
extern const sint16  VlvAct_tOilMinExVlv_C;
extern const uint16  VlvAct_nEngMinExVlv_C;
extern const uint16  VlvAct_nExVlvPosStatThd_C;
extern const uint16  VlvAct_tiExVlvPosStatThd_C;

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

void VlvAct_Sdlfast_ExMon(void);
void VLVACTEXMON_vidEntryInit(void);


#endif /* VLVACTEXMON_H */

/*-------------------------------- end of file -------------------------------*/
