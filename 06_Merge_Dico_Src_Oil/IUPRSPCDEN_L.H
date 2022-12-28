/***************************************************************************
;**
;** FILE NAME      : IUPRSPCDEN_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IUPRSPCDEN_L_H
#define IUPRSPCDEN_L_H

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

extern const uint8  IUPRSPCDEN_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Iupr_bAcvExCmSen;
extern boolean Iupr_bAcvExVlv;
extern boolean Iupr_bAcvInCmSen;
extern boolean Iupr_bAcvInVlv;
extern boolean Iupr_bAcvSpgSen;
extern boolean Iupr_bAcvtCoSen;
extern boolean Iupr_bAvlExCmSen;
extern boolean Iupr_bAvlInCmSen;
extern boolean Iupr_bColdStrt;
extern boolean IUPRSPCDEN_bExCmSenReinit_prev;
extern boolean IUPRSPCDEN_bExVlvReinit_prev;
extern boolean IUPRSPCDEN_bInCmSenReinit_prev;
extern boolean IUPRSPCDEN_bInVlvReinit_prev;
extern boolean upr_bAvlInCmSen;
extern uint8 Iupr_ctAcvExCmSen;
extern uint8 Iupr_ctAcvExVlv;
extern uint8 Iupr_ctAcvInCmSen;
extern uint8 Iupr_ctAcvInVlv;
extern uint8 Iupr_tiAcvExCmSenReinit;
extern uint8 Iupr_tiAcvExCmSenSaved;
extern uint8 Iupr_tiAcvExVlvReinit;
extern uint8 Iupr_tiAcvExVlvSaved;
extern uint8 Iupr_tiAcvInCmSenReinit;
extern uint8 Iupr_tiAcvInCmSenSaved;
extern uint8 Iupr_tiAcvInVlvReinit;
extern uint8 Iupr_tiAcvInVlvSaved;
extern uint8 Iupr_tiAcvSpgSen;
extern uint8 Iupr_tiAcvtCoSen;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IUPRSPCDEN_vidF01_Ini(void);
void IUPRSPCDEN_vidF02_ColdStrtCdn(void);
void IUPRSPCDEN_vidF03_ClcnIncCdn(void);
void IUPRSPCDEN_vidInternalValueInit(void);
boolean IUPRSPCDEN_bF01_tCoSen(boolean blocal_iupr_gen_denom_ok_par);
boolean IUPRSPCDEN_bF06_pSpgSen(boolean blocal_iupr_gen_denom_ok_par, boolean blocal_trbAct_bBoostPresClCtlAcv_par);
boolean IUPRSPCDEN_bF0x_XxCmSen(boolean biupr_gen_denom_ok_par, boolean bacq_xxcam_tooth_det_vld_par, boolean bacq_xxcam_tooth_det_par, boolean biupr_tiAcvxxCmSenReinit_prev_par, uint8 u8iupr_tihithdacvxxcmsen_c_par, uint8 u8iupr_tilothdacvxxcmsen_c_par, uint8 u8iupr_ctminacvXXcmsen_c_par, boolean  *biupr_bavlxxcmsen_par, uint8  *u8iupr_tiacvxxCmSenSaved_par, uint8  *u8iupr_tiAcvxxCmSenReinit_par, uint8  *u8iupr_ctacvxxcmsen_par, boolean  *biupr_bacvxxcmsen_par);
boolean IUPRSPCDEN_bF0x_XxVlv(boolean biupr_gen_denom_ok_par, boolean bvlvact_bacvxxservo_par, boolean bTiAcvXxVlvReinit_prev_par, uint8 u8iupr_tihithdacvxxvlv_c_par, uint8 u8iupr_tilothdacvxxvlv_c_par, uint8 u8iupr_ctminacvxxvlv_c_par, uint8  *u8Iupr_tiAcvxxVlvSaved_par, boolean  *u8iupr_tiAcvXxVlvReinit_par, boolean  *biupr_bacvxxvlv_par, uint8  *u8iupr_ctacvxxvlv_par);
boolean IUPRSPCDEN_bF07_tCoDiag(boolean blocal_iupr_gen_denom_ok_par, boolean blocal_Iupr_bColdStrt_par);


#endif /* IUPRSPCDEN_L_H */

/*-------------------------------- end of file -------------------------------*/
