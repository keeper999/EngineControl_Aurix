/***************************************************************************
;**
;** FILE NAME      : GDU_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef GDU_L_H
#define GDU_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "GD_A.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define GD_ABCTDETPREV_LNS                    ( 122 )
#define GD_ABTHDDOWN_LNS                      ( 122 )
#define GD_ABTHDDOWNPREV_LNS                  ( 122 )
#define GD_ABTHDUP_LNS                        ( 122 )
#define GD_ABTHDUPPREV_LNS                    ( 122 )

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

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean GD_abctDetPrev[GD_ABCTDETPREV_LNS];
extern boolean GD_abThdDown[GD_ABTHDDOWN_LNS];
extern boolean GD_abThdDownPrev[GD_ABTHDDOWNPREV_LNS];
extern boolean GD_abThdUp[GD_ABTHDUP_LNS];
extern boolean GD_abThdUpPrev[GD_ABTHDUPPREV_LNS];
extern boolean GDU_bMemRstDftCal;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void GDU_vidAutomate(uint16 u16IdxDft);
void GDU_vidF01_CntDet(uint16 u16DftIdx);
void GDU_vidF01_EndDiag(uint16 u16DftIdx);
void GDU_vidF02_IniCntDet(void);
void GDU_vidF02_IniEndDiag(void);
void GDU_vidF03_IniCntDetScanTool(void);
void GDU_vidF03_IniEndDiagScanTool(void);
void GDU_vidF04_IniCntDetGlbDCStrt(void);
void GDU_vidF04_IniCntDetGlbDCStrt_opt(void);
void GDU_vidF06_ClearCntDetEvents(void);
void GDU_vidF06_CntDetEvents(uint16 u16DftIdx);
void GDU_vidMngAutomateEntry(uint16 u16IdxDft);
void GDU_vidMngAutomateExit(uint16 u16IdxDft, GDFRM_tenuGDUState enuStDgo);
void GDU_vidMngEntryStAbsent(uint16 u16IdxDft);
void GDU_vidMngEntryStDeval(uint16 u16DftIdx);
void GDU_vidMngEntryStFugitif(uint16 u16IdxDft);
void GDU_vidMngEntryStPctlAbsent(uint16 u16IdxDft);
void GDU_vidMngEntryStPctlPresent(uint16 u16IdxDft);
void GDU_vidMngEntryStPresent(uint16 u16IdxDft);
void GDU_vidMngExitStAbsent(uint16 u16IdxDft);
void GDU_vidMngExitStDeval(uint16 u16IdxDft);
void GDU_vidMngExitStFugitif(uint16 u16IdxDft);
void GDU_vidMngExitStPctlAbsent(uint16 u16IdxDft);
void GDU_vidMngExitStPctlPresent(uint16 u16IdxDft);
void GDU_vidMngExitStPresent(uint16 u16IdxDft);
void GDU_vidTransAbs(uint16 u16IdxDft);
void GDU_vidTransDeval(uint16 u16IdxDft);
void GDU_vidTransFugit(uint16 u16IdxDft);
void GDU_vidTransPctlAbs(uint16 u16IdxDft);
void GDU_vidTransPctlPrst(uint16 u16IdxDft);
void GDU_vidTransPrst(uint16 u16IdxDft);
boolean GDU_bMngAutomateTrans(uint16 u16IdxDft);


#endif /* GDU_L_H */

/*-------------------------------- end of file -------------------------------*/
