/***************************************************************************
;**
;** FILE NAME      : KNKINSTNOISERBL_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef KNKINSTNOISERBL_L_H
#define KNKINSTNOISERBL_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define KNKINSTNOISERBL_u8ARRAY_LENGTH    16

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

extern const uint8  KnkInstNoiseRbl_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Knk_rbl_noi_fmt_cyl1_uavn0;
extern uint8 Knk_rbl_noi_fmt_cyl2_uavn0;
extern uint8 Knk_rbl_noi_fmt_cyl3_uavn0;
extern uint8 Knk_rbl_noi_fmt_cyl4_uavn0;
extern uint8 Knk_rbl_noi_fmt_uavn0;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void KNKINSTNOISERBL_vidCyl1KnkNoiFmt(void);
void KNKINSTNOISERBL_vidCyl2KnkNoiFmt(void);
void KNKINSTNOISERBL_vidCyl3KnkNoiFmt(void);
void KNKINSTNOISERBL_vidCyl4KnkNoiFmt(void);
void KNKINSTNOISERBL_vidGainStatLdRbl(void);
void KNKINSTNOISERBL_vidIfDiagOffRbl(void);
void KNKINSTNOISERBL_vidInitOutput(void);
void KNKINSTNOISERBL_vidKnkInstNoiRbl(void);


#endif /* KNKINSTNOISERBL_L_H */

/*-------------------------------- end of file -------------------------------*/
