/***************************************************************************
;**
;** FILE NAME      : ADHEATCMD_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ADHEATCMD_L_H
#define ADHEATCMD_L_H

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

extern const uint8  ADHEATCMD_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean AC_bDgoOc_CTP1;
extern boolean AC_bDgoOc_CTP2;
extern boolean AC_bDgoScg_CTP1;
extern boolean AC_bDgoScg_CTP2;
extern boolean AC_bDgoScp_CTP1;
extern boolean AC_bDgoScp_CTP2;
extern boolean AC_bMonRunOc_CTP1;
extern boolean AC_bMonRunOc_CTP2;
extern boolean AC_bMonRunScg_CTP1;
extern boolean AC_bMonRunScg_CTP2;
extern boolean AC_bMonRunScp_CTP1;
extern boolean AC_bMonRunScp_CTP2;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ADHEATCMD_vidAdHeatCmdCalc(void);
void ADHEATCMD_vidCmdCTP1(void);
void ADHEATCMD_vidCmdCTP2(void);
void ADHEATCMD_vidDiagCTP1(void);
void ADHEATCMD_vidDiagCTP2(void);
void ADHEATCMD_vidInit(void);


#endif /* ADHEATCMD_L_H */

/*-------------------------------- end of file -------------------------------*/
