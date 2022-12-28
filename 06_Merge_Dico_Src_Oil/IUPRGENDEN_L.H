/***************************************************************************
;**
;** FILE NAME      : IUPRGENDEN_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IUPRGENDEN_L_H
#define IUPRGENDEN_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "GD_A.h"
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

extern const uint8  IUPRGENDEN_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean IUPR_bExtCond;
extern boolean IUPR_bIdle;
extern boolean IUPR_bObdStrt;
extern boolean IUPR_bRstPrm_prev;
extern boolean IUPR_bSinceEngStrt;
extern boolean IUPR_bVehIdle;
extern boolean IUPR_bVehSpdOver40;
extern boolean Iupr_gen_denom_ok_prev;
extern boolean Iupr_obd_Strt_ok_prev;
extern uint16 IUPR_tiObdStrt;
extern uint16 IUPR_tiSinceEngStrt;
extern uint16 IUPR_tiVehIdle;
extern uint16 IUPR_tiVehSpdOver40;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IUPRGENDEN_vidF01_ObdCond(void);
void IUPRGENDEN_vidF01_SinceEngStrt(void);
void IUPRGENDEN_vidF02_bObdStrt(void);
void IUPRGENDEN_vidF02_ObdStrt(void);
void IUPRGENDEN_vidF02_VehSpdOver40(void);
void IUPRGENDEN_vidF03_GenDen(void);
void IUPRGENDEN_vidF03_VehIdle(void);
void IUPRGENDEN_vidF04_ReInitPrm(void);
void IUPRGENDEN_vidInitOutput(void);


#endif /* IUPRGENDEN_L_H */

/*-------------------------------- end of file -------------------------------*/
