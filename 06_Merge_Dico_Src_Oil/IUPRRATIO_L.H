/***************************************************************************
;**
;** FILE NAME      : IUPRRATIO_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IUPRRATIO_L_H
#define IUPRRATIO_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "gd_api.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define IUPR_NORATIO_LNS                      ( 100 )
#define UINT16_MAX_HALF                   32768

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
extern boolean IUPRRATIO_bFirstUse;
extern boolean IUPRRATIO_bRstPrm_prev;
extern uint16 IUPR_noRatio[IUPR_NORATIO_LNS];
extern uint16 u16MinRatioIdx;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IUPRRATIO_vidF01_CntDen(uint16 u16IdxDft);
void IUPRRATIO_vidF01_CntNum(uint16 u16IdxDft);
void IUPRRATIO_vidF01_DenNumCal(uint16 u16IdxDft, uint8 u8IdxGrpRat);
void IUPRRATIO_vidF01_Ratio(uint16 u16IdxIupr, uint16 u16IdxDft);
void IUPRRATIO_vidF02_CntNumDen(void);
void IUPRRATIO_vidInitOutput(void);


#endif /* IUPRRATIO_L_H */

/*-------------------------------- end of file -------------------------------*/
