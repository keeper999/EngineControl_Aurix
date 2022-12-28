/***************************************************************************
;**
;** FILE NAME      : IUPRSPCDEN.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "IUPRSPCDEN.H"
#include "IUPRSPCDEN_L.H"
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
const boolean  Iupr_bTiBoostPIninTyp_C = 0;
const uint8  Iupr_ctMinAcvExCmSen_C = 0;
const uint8  Iupr_ctMinAcvExVlv_C = 0;
const uint8  Iupr_ctMinAcvInCmSen_C = 0;
const uint8  Iupr_ctMinAcvInVlv_C = 0;
const uint8  Iupr_tiHiThdAcvExCmSen_C = 0;
const uint8  Iupr_tiHiThdAcvExVlv_C = 0;
const uint8  Iupr_tiHiThdAcvInCmSen_C = 0;
const uint8  Iupr_tiHiThdAcvInVlv_C = 0;
const uint8  Iupr_tiLoThdAcvExCmSen_C = 0;
const uint8  Iupr_tiLoThdAcvExVlv_C = 0;
const uint8  Iupr_tiLoThdAcvInCmSen_C = 0;
const uint8  Iupr_tiLoThdAcvInVlv_C = 0;
const uint8  Iupr_tiMinAcvSpg_C = 0;
const uint8  Iupr_tiMinAcvtCoSen_C = 0;
const uint8  IUPRSPCDEN_u8Inhib = 0;
const sint16  Iupr_ColdStrtTAirOfs_C = 0;
const sint16  Iupr_ColdStrtTCoMax_C = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Iupr_bAcvExCmSen;
boolean Iupr_bAcvExVlv;
boolean Iupr_bAcvInCmSen;
boolean Iupr_bAcvInVlv;
boolean Iupr_bAcvSpgSen;
boolean Iupr_bAcvtCoSen;
boolean Iupr_bAvlExCmSen;
boolean Iupr_bAvlInCmSen;
boolean Iupr_bColdStrt;
boolean IUPRSPCDEN_bExCmSenReinit_prev;
boolean IUPRSPCDEN_bExVlvReinit_prev;
boolean IUPRSPCDEN_bInCmSenReinit_prev;
boolean IUPRSPCDEN_bInVlvReinit_prev;
boolean IUPRSPCDEN_UpdateDenomOkPrev;
boolean upr_bAvlInCmSen;
uint8 Iupr_ctAcvExCmSen;
uint8 Iupr_ctAcvExVlv;
uint8 Iupr_ctAcvInCmSen;
uint8 Iupr_ctAcvInVlv;
uint8 Iupr_tiAcvExCmSenReinit;
uint8 Iupr_tiAcvExCmSenSaved;
uint8 Iupr_tiAcvExVlvReinit;
uint8 Iupr_tiAcvExVlvSaved;
uint8 Iupr_tiAcvInCmSenReinit;
uint8 Iupr_tiAcvInCmSenSaved;
uint8 Iupr_tiAcvInVlvReinit;
uint8 Iupr_tiAcvInVlvSaved;
uint8 Iupr_tiAcvSpgSen;
uint8 Iupr_tiAcvtCoSen;
uint8 u8Iupr_xxx_denom_ok;
uint8 u8Iupr_xxx_denom_ok_prev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

