/***************************************************************************
;**
;** FILE NAME      : AIRTQSTRUCTMNGT_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef AIRTQSTRUCTMNGT_L_H
#define AIRTQSTRUCTMNGT_L_H

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

extern const uint8  AIRTQSTRUCTMNGT_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean CrkMng_bIntrKeyHiEngSpd;
extern boolean CrkMng_bIntrKeyLoEngSpd;
extern boolean Dtc_structure_debouclee;
extern boolean Manu_coef_de_transition;
extern uint8 Dtc_obj_pres_ratio;
extern uint8 Dtc_seuil_ratio_pres_trans;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void AIRTQSTRUCTMNGT_StructState(void);
void AIRTQSTRUCTMNGT_vidCalcSecCrOffs(void);
void AIRTQSTRUCTMNGT_vidCalObjPres(void);
void AIRTQSTRUCTMNGT_vidDtcSecOffDel(void);
void AIRTQSTRUCTMNGT_vidFcDeTranToCyc(void);
void AIRTQSTRUCTMNGT_vidFcSurfStart(void);
void AIRTQSTRUCTMNGT_vidFcTransToCycl(void);
void AIRTQSTRUCTMNGT_vidFcTransToStop(void);
void AIRTQSTRUCTMNGT_vidFcTranToDecyc(void);
void AIRTQSTRUCTMNGT_vidInitOutput(void);
void AIRTQSTRUCTMNGT_vidInitSecCrOffs(void);
void AIRTQSTRUCTMNGT_vidManager(void);
void AIRTQSTRUCTMNGT_vidStructInit(void);


#endif /* AIRTQSTRUCTMNGT_L_H */

/*-------------------------------- end of file -------------------------------*/
