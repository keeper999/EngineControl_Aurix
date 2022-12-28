/***************************************************************************
;**
;** FILE NAME      : OILLVLACQ.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "OILLVLACQ.H"
#include "OILLVLACQ_L.H"
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
const uint8  Oil_facCorTECU_T[OIL_FACCORTECU_T_COLS] = {0};
const uint8  Oil_tECU_A[OIL_TECU_A_COLS] = {0};
const uint8  Oil_tOil_A[OIL_TOIL_A_COLS] = {0};
const uint8  OILLVLACQ_u8Inhib = 0;
const sint16  Ext_tMaxThres_C = 0;
const uint16  Ext_iCurNom_C = 0;
const uint16  Ext_tiMeasAuthEndMes_C = 0;
const uint16  Ext_uBSIMax_C = 0;
const uint16  Ext_uBSIMin_C = 0;
const uint16  Ext_uCMMMax_C = 0;
const uint16  Ext_uCMMMin_C = 0;
const uint16  Ext_uEngOilLvlAGrdMax_C = 0;
const uint16  Ext_uEngOilLvlAGrdMin_C = 0;
const uint16  Ext_uEngOilLvlDft_C = 0;
const uint16  Ext_uEngOilLvlIp_C = 0;
const uint16  Oil_uEngOilLvlTOilCor_M[OIL_UENGOILLVLTOILCOR_M_LNS][OIL_UENGOILLVLTOILCOR_M_COLS] = {0};
const uint16  Oil_uOilLvl_A[OIL_UOILLVL_A_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 OILLVLACQ_stAcqMng;
boolean Ext_bDgoGrd_OilLvlAcq;
boolean Ext_bDgoScg_OilLvlAcq;
boolean Ext_bDgoScp_OilLvlAcq;
boolean Ext_bMonRunGrd_OilLvlAcq;
boolean Ext_bMonRunScg_OilLvlAcq;
boolean Ext_bMonRunScp_OilLvlAcq;
boolean Ext_bOilLvlAcqDone;
boolean Oil_bOilLvlAcqOk;
uint16 Ext_tiMeasAuth;
uint16 Ext_uEngOilLvl;
uint16 Ext_uEngOilLvlAvg1;
uint16 Ext_uEngOilLvlAvg2;
uint16 Ext_uEngOilLvlRaw;
uint16 Oil_uEngOillLvlTOilCor;
uint16 Oil_uEngOilLvl;
uint16 Oil_uEngOilLvlICor;
uint16 Oil_uEngOilLvlTECUCor;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

