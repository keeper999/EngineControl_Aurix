/***************************************************************************
;**
;** FILE NAME      : BATTVOLTACQ_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef BATTVOLTACQ_L_H
#define BATTVOLTACQ_L_H

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

extern const uint8  BATTVOLTACQ_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bDgoHi_uBattMes;
extern boolean Ext_bDgoLo_uBattMes;
extern boolean Ext_bDgoLo_uBattSpc;
extern boolean Ext_bMonRunHi_uBattMes;
extern boolean Ext_bMonRunLo_uBattMes;
extern boolean Ext_bMonRunLo_uBattSpc;
extern boolean Pwr_bAcvEveInjStra;
extern boolean Pwr_bHysVoltAcqFil;
extern uint32 BATTVOLTACQ_u32FiltPosErrorMem;
extern uint16 Pwr_uBattDiagAcq;
extern uint16 Pwr_uBattEveInjAcq;
extern uint16 Pwr_uBattFilAcq;
extern uint16 Pwr_uBattRaw1;
extern uint16 Pwr_uBattRaw2;
extern uint16 Pwr_uBattRaw3;
extern uint16 Pwr_uBattRaw4;
extern uint16 Pwr_uBattRaw5;
extern uint16 Tension_batterie_acq_prec;
extern uint16 Tension_batterie_filtree;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void BATTVOLTACQ_vidBattAcqOn2ms(void);
void BATTVOLTACQ_vidBattAcqOnEveInj(void);
void BATTVOLTACQ_vidBattAcqReset(void);
void BATTVOLTACQ_vidBattDiag(void);
void BATTVOLTACQ_vidBattFil(void);
void BATTVOLTACQ_vidBattFilt(void);
void BATTVOLTACQ_vidbattFiltMng(void);
void BATTVOLTACQ_vidBattIni(void);
void BATTVOLTACQ_vidFilClcnAcv(void);
void BATTVOLTACQ_vidFilClcnVal(void);
void BATTVOLTACQ_vidInitOutput(void);
void BATTVOLTACQ_vidWeightedAvr(void);


#endif /* BATTVOLTACQ_L_H */

/*-------------------------------- end of file -------------------------------*/
