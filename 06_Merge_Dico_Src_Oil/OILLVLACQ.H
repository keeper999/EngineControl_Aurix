/***************************************************************************
;**
;** FILE NAME      : OILLVLACQ.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef OILLVLACQ_H
#define OILLVLACQ_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define ACTIF                             1
#define INACTIF                           0
#define OIL_FACCORTECU_T_COLS                  ( 10 )
#define OIL_TECU_A_COLS                        ( 10 )
#define OIL_TOIL_A_COLS                        ( 10 )
#define OIL_UENGOILLVLTOILCOR_M_LNS           ( 3 )
#define OIL_UENGOILLVLTOILCOR_M_COLS           ( 10 )
#define OIL_UOILLVL_A_COLS                     ( 3 )

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

extern const uint8  Oil_facCorTECU_T[OIL_FACCORTECU_T_COLS];
extern const uint8  Oil_tECU_A[OIL_TECU_A_COLS];
extern const uint8  Oil_tOil_A[OIL_TOIL_A_COLS];
extern const sint16  Ext_tMaxThres_C;
extern const uint16  Ext_iCurNom_C;
extern const uint16  Ext_tiMeasAuthEndMes_C;
extern const uint16  Ext_uBSIMax_C;
extern const uint16  Ext_uBSIMin_C;
extern const uint16  Ext_uCMMMax_C;
extern const uint16  Ext_uCMMMin_C;
extern const uint16  Ext_uEngOilLvlAGrdMax_C;
extern const uint16  Ext_uEngOilLvlAGrdMin_C;
extern const uint16  Ext_uEngOilLvlDft_C;
extern const uint16  Ext_uEngOilLvlIp_C;
extern const uint16  Oil_uEngOilLvlTOilCor_M[OIL_UENGOILLVLTOILCOR_M_LNS][OIL_UENGOILLVLTOILCOR_M_COLS];
extern const uint16  Oil_uOilLvl_A[OIL_UOILLVL_A_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 Ext_uEngOilLvl;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Oil_EveOilLvl_OilLvlAcq(void);
void Oil_EveRst_OilLvlAcq(void);
void Oil_SdlFast_OilLvlAcq(void);


#endif /* OILLVLACQ_H */

/*-------------------------------- end of file -------------------------------*/
