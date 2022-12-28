/***************************************************************************
;**
;** FILE NAME      : IUPRSPCDEN.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IUPRSPCDEN_H
#define IUPRSPCDEN_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define DEF_IUPR_EX_CAM_DENOM_OK          6
#define DEF_IUPR_EX_VLV_DENOM_OK          4
#define DEF_IUPR_IN_CAM_DENOM_OK          5
#define DEF_IUPR_IN_VLV_DENOM_OK          3
#define DEF_IUPR_PSPG_DENOM_OK            7
#define DEF_IUPR_TCO_DENOM_OK             1
#define DEF_IUPR_TCO_DIAG_DENOM_OK        2

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

extern const boolean  Iupr_bTiBoostPIninTyp_C;
extern const uint8  Iupr_ctMinAcvExCmSen_C;
extern const uint8  Iupr_ctMinAcvExVlv_C;
extern const uint8  Iupr_ctMinAcvInCmSen_C;
extern const uint8  Iupr_ctMinAcvInVlv_C;
extern const uint8  Iupr_tiHiThdAcvExCmSen_C;
extern const uint8  Iupr_tiHiThdAcvExVlv_C;
extern const uint8  Iupr_tiHiThdAcvInCmSen_C;
extern const uint8  Iupr_tiHiThdAcvInVlv_C;
extern const uint8  Iupr_tiLoThdAcvExCmSen_C;
extern const uint8  Iupr_tiLoThdAcvExVlv_C;
extern const uint8  Iupr_tiLoThdAcvInCmSen_C;
extern const uint8  Iupr_tiLoThdAcvInVlv_C;
extern const uint8  Iupr_tiMinAcvSpg_C;
extern const uint8  Iupr_tiMinAcvtCoSen_C;
extern const sint16  Iupr_ColdStrtTAirOfs_C;
extern const sint16  Iupr_ColdStrtTCoMax_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean IUPRSPCDEN_UpdateDenomOkPrev;
extern uint8 u8Iupr_xxx_denom_ok;
extern uint8 u8Iupr_xxx_denom_ok_prev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IuprSpcDen_EveRst(void);
void IuprSpcDen_GlbDCStrt(void);
void IuprSpcDen_SdlSlow(void);


#endif /* IUPRSPCDEN_H */

/*-------------------------------- end of file -------------------------------*/
