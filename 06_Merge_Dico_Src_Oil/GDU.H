/***************************************************************************
;**
;** FILE NAME      : GDU.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef GDU_H
#define GDU_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "GD_A.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define BSTPRES                           4
#define GD_ASTRDFTEEP_LNS                     ( 972 )
#define GDU_ASTRDFTUNIT_LNS                   ( 972 )
#define GDU_AU16CTDEC_COLS                     ( 972 )
#define GDU_AU16CTINC_COLS                     ( 972 )
#define GDU_DFT_THD                       32767

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

extern const boolean  GDU_bRstDftCal_C;
extern const uint16  GDU_au16CtDec[GDU_AU16CTDEC_COLS];
extern const uint16  GDU_au16CtInc[GDU_AU16CTINC_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern GD_tstrDftEep GD_astrDftEep[GD_ASTRDFTEEP_LNS];
extern GDU_tstrDft GDU_astrDftUnit[GDU_ASTRDFTUNIT_LNS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void GD_EveKOn_GDU(void);
void GD_EveRst_GDU(void);
void GD_EveRstDft_GDU(void);
void GD_EveRstDftObd_GDU(void);
void GDU_vidExitEveCDThd(uint16 u16DftIdx);
void GDU_vidExitEveCDThdUp(uint16 u16DftIdx);
void GDU_vidExitEveDftClr(uint16 u16IdxDft);
void GDU_vidExitEveFrfRec(uint16 u16IdxDft);
void GDU_vidExitEveRstDftCal(void);
void GDU_vidExitEveSt(uint16 u16IdxDft);
void GDU_vidExitEveUnval(uint16 u16IdxDft);
void GDU_vidGdu(uint16 u16IdxDft);
void GDU_vidGlbDCStrt(void);
void GDU_vidSdlSlow(void);
boolean GDU_bGetEndDiagStrt(uint16 u16IdxDft);
GDFRM_tenuGDUState GDU_tenuGetStDgo(uint16 u16IdxDft);


#endif /* GDU_H */

/*-------------------------------- end of file -------------------------------*/
