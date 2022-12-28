/***************************************************************************
;**
;** FILE NAME      : CSTRFUCONCESTIM_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CSTRFUCONCESTIM_L_H
#define CSTRFUCONCESTIM_L_H

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

extern const uint8  CSTRFUCONCESTIM_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Cpc_fuel_vapour_conc_err_near_0;
extern boolean Cstr_bBoostPresZone;
extern boolean Cstr_bEnaCllConcEstim;
extern boolean Cstr_bEnaOplConcEstim;
extern boolean Cstr_bOplPurgeCdn;
extern boolean CSTRFUCONCESTIM_CalreseterPrev;
extern boolean CSTRFUCONCESTIM_CalresetPrev;
extern uint32 CSTRFUCONCESTIM_u32FuelFilterMem;
extern uint8 Cpc_init_after_stall_count;
extern sint16 FuConcEstim_rLamThd;
extern uint16 CanPurg_rAirPresPurgVlv;
extern uint16 Cpc_conc_closed_loop_step;
extern uint16 Cpc_conc_open_loop_step;
extern uint16 Cpc_fuel_vap_conc_err_close_loop;
extern uint16 FuConcEstim_concFuVapThd;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CSTRFUCONCESTIM_vidCllConc(void);
void CSTRFUCONCESTIM_vidCllConcEstim(void);
void CSTRFUCONCESTIM_vidConcFuErr(void);
void CSTRFUCONCESTIM_vidConcFuEstim(void);
void CSTRFUCONCESTIM_vidCrk2RunIni(void);
void CSTRFUCONCESTIM_vidEstimMng(void);
void CSTRFUCONCESTIM_vidFuEstim(void);
void CSTRFUCONCESTIM_vidInitialization(void);
void CSTRFUCONCESTIM_vidOplConc(void);
void CSTRFUCONCESTIM_vidOplConcEstim(void);
void CSTRFUCONCESTIM_vidOutIf(void);
void CSTRFUCONCESTIM_vidStallTi(void);


#endif /* CSTRFUCONCESTIM_L_H */

/*-------------------------------- end of file -------------------------------*/
