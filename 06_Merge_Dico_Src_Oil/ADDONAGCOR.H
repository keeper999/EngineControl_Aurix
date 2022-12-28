/***************************************************************************
;**
;** FILE NAME      : ADDONAGCOR.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ADDONAGCOR_H
#define ADDONAGCOR_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define IGSYS_FACAGCORCAL1_M_LNS              ( 9 )
#define IGSYS_FACAGCORCAL1_M_COLS              ( 9 )
#define IGSYS_FACAGCORCAL2_M_LNS              ( 9 )
#define IGSYS_FACAGCORCAL2_M_COLS              ( 9 )
#define IGSYS_FACTARAGCOR2CAL1_M_LNS          ( 9 )
#define IGSYS_FACTARAGCOR2CAL1_M_COLS          ( 9 )
#define IGSYS_FACTARAGCOR2CAL2_M_LNS          ( 9 )
#define IGSYS_FACTARAGCOR2CAL2_M_COLS          ( 9 )
#define IGSYS_NENG_FACAGCOR_A_COLS             ( 9 )
#define IGSYS_RAIRLD_FACAGCOR_A_COLS           ( 9 )
#define IGSYS_TSELUSR_TARAGCOR_A_COLS          ( 9 )

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

extern const boolean  IgSys_bFlexFacAgCor_C;
extern const boolean  IgSys_bGasFacAgCor_C;
extern const boolean  IgSys_bInhTarAgCor_C;
extern const uint8  IgSys_idxSelTUsr_C;
extern const uint16  IgSys_facAgCorCal1_M[IGSYS_FACAGCORCAL1_M_LNS][IGSYS_FACAGCORCAL1_M_COLS];
extern const uint16  IgSys_facAgCorCal2_M[IGSYS_FACAGCORCAL2_M_LNS][IGSYS_FACAGCORCAL2_M_COLS];
extern const uint16  IgSys_facTarAgCor2Cal1_M[IGSYS_FACTARAGCOR2CAL1_M_LNS][IGSYS_FACTARAGCOR2CAL1_M_COLS];
extern const uint16  IgSys_facTarAgCor2Cal2_M[IGSYS_FACTARAGCOR2CAL2_M_LNS][IGSYS_FACTARAGCOR2CAL2_M_COLS];
extern const uint16  IgSys_nEng_FacAgCor_A[IGSYS_NENG_FACAGCOR_A_COLS];
extern const uint16  IgSys_rAirLd_FacAgCor_A[IGSYS_RAIRLD_FACAGCOR_A_COLS];
extern const uint16  IgSys_tSelUsr_TarAgCor_A[IGSYS_TSELUSR_TARAGCOR_A_COLS];

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

void ADDONAGCOR_vidEntryInit(void);
void IgSys_EveTDC_AddOnAgCor(void);


#endif /* ADDONAGCOR_H */

/*-------------------------------- end of file -------------------------------*/
