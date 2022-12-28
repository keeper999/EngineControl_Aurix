/***************************************************************************
;**
;** FILE NAME      : TUNCFG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef TUNCFG_L_H
#define TUNCFG_L_H

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

extern const uint8  TUNCFG_u8Inhib;

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

void TUNCFG_vidAltClassSel(void);
void TUNCFG_vidALTSel(void);
void TUNCFG_vidBVSel(void);
void TUNCFG_vidCANAdapt(void);
void TUNCFG_vidCARSel(void);
void TUNCFG_vidCHASel(void);
void TUNCFG_vidCLIMSel(void);
void TUNCFG_vidDAGMPSel(void);
void TUNCFG_vidDCTSel(void);
void TUNCFG_vidFRICSel(void);
void TUNCFG_vidGEESel(void);
void TUNCFG_vidProdCfg(void);
void TUNCFG_vidSelCfg(void);
void TUNCFG_vidTunCfg(void);
void TUNCFG_vidTunCfg1(void);
void TUNCFG_vidUCSelLsb(void);
void TUNCFG_vidUCSelMsb(void);


#endif /* TUNCFG_L_H */

/*-------------------------------- end of file -------------------------------*/
