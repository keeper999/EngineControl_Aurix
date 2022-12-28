/***************************************************************************
;**
;** FILE NAME      : OILLVLACQ_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef OILLVLACQ_L_H
#define OILLVLACQ_L_H

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

/* enum st120 */
#define ACQUI_STOPPED                     2
#define ACQUI_DONE                        4
#define ACQUI_RUNNING                     8
#define INIT_ACQUI                        16
/*extern uint8 OILLVLACQ_stAcqMng;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  OILLVLACQ_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 OILLVLACQ_stAcqMng;
extern boolean Ext_bDgoGrd_OilLvlAcq;
extern boolean Ext_bDgoScg_OilLvlAcq;
extern boolean Ext_bDgoScp_OilLvlAcq;
extern boolean Ext_bMonRunGrd_OilLvlAcq;
extern boolean Ext_bMonRunScg_OilLvlAcq;
extern boolean Ext_bMonRunScp_OilLvlAcq;
extern boolean Ext_bOilLvlAcqDone;
extern boolean Oil_bOilLvlAcqOk;
extern uint16 Ext_tiMeasAuth;
extern uint16 Ext_uEngOilLvlAvg1;
extern uint16 Ext_uEngOilLvlAvg2;
extern uint16 Ext_uEngOilLvlRaw;
extern uint16 Oil_uEngOillLvlTOilCor;
extern uint16 Oil_uEngOilLvl;
extern uint16 Oil_uEngOilLvlICor;
extern uint16 Oil_uEngOilLvlTECUCor;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void OILLVLACQ_vidAcqBSW(void);
void OILLVLACQ_vidAcqMng(void);
void OILLVLACQ_vidAcquisition(void);
void OILLVLACQ_vidDiagGrd(void);
void OILLVLACQ_vidDiagnosis(void);
void OILLVLACQ_vidFailures(void);
void OILLVLACQ_vidInit(void);
void OILLVLACQ_vidInitOutput(void);
void OILLVLACQ_vidSelection(void);
void OILLVLACQ_vidTreatment(void);


#endif /* OILLVLACQ_L_H */

/*-------------------------------- end of file -------------------------------*/
