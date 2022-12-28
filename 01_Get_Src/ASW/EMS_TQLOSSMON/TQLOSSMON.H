/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : TQLOSSMON                                                */
/*                                                                            */
/* !Module         : TQLOSSMON                                                */
/* !Description    : Public declarations for the component                    */
/*                                                                            */
/* !File           : TQLOSSMON.H                                              */
/*                                                                            */
/* !Scope          : Public                                                   */
/*                                                                            */
/* !Target         : Hitachi SH705x                                           */
/*                                                                            */
/* !Vendor         : VEMS                                                     */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT 2006 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQLOSSMON/TQLOSSMON.H_$*/
/* $Revision::   1.4      $$Author::   mbenfrad       $$Date::   26 Nov 2012 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef TQLOSSMON_H
#define TQLOSSMON_H

#include "STD_TYPES.h"

/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define SFTYMGT_FACCNVLOSS_SPD_T_COLS          (5)
#define SFTYMGT_FACCNVPWRTQR_M_LNS            (8)
#define SFTYMGT_FACCNVPWRTQR_M_COLS            (16)
#define SFTYMGT_FACCNVTQRPWR_M_LNS            (8)
#define SFTYMGT_FACCNVTQRPWR_M_COLS            (16)
#define SFTYMGT_FACFILTQACLOSSDOWN_T_COLS      (16)
#define SFTYMGT_FACFILTQACLOSSUP_T_COLS        (16)
#define SFTYMGT_FACFILTQCNVLOSSDOWN_T_COLS     (16)
#define SFTYMGT_FACFILTQCNVLOSSUP_T_COLS       (16)
#define SFTYMGT_FACFILTQSTGDOWN_T_COLS         (5)
#define SFTYMGT_FACFILTQSTGLOSSUP_T_COLS       (5)
#define SFTYMGT_FACSTGLNRLOSSNCK_T_COLS        (5)
#define SFTYMGT_FACSTGLNRLOSSSPD_T_COLS        (5)
#define SFTYMGT_FACSTGPMPTHDLOSSNCK_T_COLS     (5)
#define SFTYMGT_FACSTGTHDLOSSSPD_T_COLS        (5)
#define SFTYMGT_NCK_X_A_COLS                   (16)
#define SFTYMGT_NCK_Y_A_COLS                   (16)
#define SFTYMGT_NCKSTGPMP_A_COLS               (5)
#define SFTYMGT_PWR_X_A_COLS                   (8)
#define SFTYMGT_SPDTQCMP_A_COLS                (5)
#define SFTYMGT_TQ_X_A_COLS                    (8)
#define SFTYMGT_TQCKFRICLOSST_A_COLS           (16)
#define SFTYMGT_TQCKFRICLOSST_T_COLS           (16)
#define SFTYMGT_TQCKPMPLOSSMAX_A_COLS          (16)
#define SFTYMGT_TQCKPMPLOSSMAX_T_COLS          (16)

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CALIB_BOOLEAN
#include "MemMap.h"
extern const boolean  SftyMgt_bInhTqManGBxLoss_C;
extern const boolean  SftyMgt_bSumLossCmpCnv_C;
#define TMS_STOP_SEC_CALIB_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
extern const uint8  SftyMgt_facCnvLoss_Spd_T[SFTYMGT_FACCNVLOSS_SPD_T_COLS];
extern const uint8  SftyMgt_facStgLnrLossNCk_T[SFTYMGT_FACSTGLNRLOSSNCK_T_COLS];
extern const uint8  SftyMgt_facStgLnrLossSpd_T[SFTYMGT_FACSTGLNRLOSSSPD_T_COLS];
extern const uint8  SftyMgt_facStgPmpThdLossNCk_T[SFTYMGT_FACSTGPMPTHDLOSSNCK_T_COLS];
extern const uint8  SftyMgt_facStgThdLossSpd_T[SFTYMGT_FACSTGTHDLOSSSPD_T_COLS];
extern const uint8  SftyMgt_idxACTyp_C;
extern const uint8  SftyMgt_idxAltTyp_C;
extern const uint8  SftyMgt_idxStgPmpTyp_C;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
extern const sint16  SftyMgt_tqAltLossMax_C;
extern const sint16  SftyMgt_tqAltLossMin_C;
extern const sint16  SftyMgt_tqErrThdTqAuxLoss_C;
extern const uint16  SftyMgt_facCnvPwrTqr_M[SFTYMGT_FACCNVPWRTQR_M_LNS][SFTYMGT_FACCNVPWRTQR_M_COLS];
extern const uint16  SftyMgt_facCnvTqrPwr_M[SFTYMGT_FACCNVTQRPWR_M_LNS][SFTYMGT_FACCNVTQRPWR_M_COLS];
extern const uint16  SftyMgt_facFilTqACLoss_C;
extern const uint16  SftyMgt_facFilTqACLossDown_T[SFTYMGT_FACFILTQACLOSSDOWN_T_COLS];
extern const uint16  SftyMgt_facFilTqACLossUp_T[SFTYMGT_FACFILTQACLOSSUP_T_COLS];
extern const uint16  SftyMgt_facFilTqCnvLossDown_T[SFTYMGT_FACFILTQCNVLOSSDOWN_T_COLS];
extern const uint16  SftyMgt_facFilTqCnvLossUp_T[SFTYMGT_FACFILTQCNVLOSSUP_T_COLS];
extern const uint16  SftyMgt_facFilTqStgDown_T[SFTYMGT_FACFILTQSTGDOWN_T_COLS];
extern const uint16  SftyMgt_facFilTqStgLossUp_T[SFTYMGT_FACFILTQSTGLOSSUP_T_COLS];
extern const uint16  SftyMgt_facFilTqStgPmpLoss_C;
extern const uint16  SftyMgt_nCk_X_A[SFTYMGT_NCK_X_A_COLS];
extern const uint16  SftyMgt_nCk_Y_A[SFTYMGT_NCK_Y_A_COLS];
extern const uint16  SftyMgt_nCkStgPmp_A[SFTYMGT_NCKSTGPMP_A_COLS];
extern const uint16  SftyMgt_nStrtTqLossThd_C;
extern const uint16  SftyMgt_pwr_X_A[SFTYMGT_PWR_X_A_COLS];
extern const uint16  SftyMgt_pwrACMax_C;
extern const uint16  SftyMgt_spdDftCnvLoss_C;
extern const uint16  SftyMgt_spdDftStgPmp_C;
extern const uint16  SftyMgt_spdTqCmp_A[SFTYMGT_SPDTQCMP_A_COLS];
extern const uint16  SftyMgt_tiDlyEngLossAdp_C;
extern const uint16  SftyMgt_tiDlyEngLossDftOff_C;
extern const uint16  SftyMgt_tiDlyEngLossDftOn_C;
extern const uint16  SftyMgt_tiDlyLossAuxDftOff_C;
extern const uint16  SftyMgt_tiDlyLossAuxDftOn_C;
extern const uint16  SftyMgt_tiDlyLossBVADftOff_C;
extern const uint16  SftyMgt_tiDlyLossBVADftOn_C;
extern const uint16  SftyMgt_tiDlySumLossDftOff_C;
extern const uint16  SftyMgt_tiDlySumLossDftOn_C;
extern const uint16  SftyMgt_tiMaxStrtLoss_C;
extern const uint16  SftyMgt_tq_X_A[SFTYMGT_TQ_X_A_COLS];
extern const uint16  SftyMgt_tqAC3BasLossMax_C;
extern const uint16  SftyMgt_tqAC3OnLossMax_C;
extern const uint16  SftyMgt_tqACLossMax_C;
extern const uint16  SftyMgt_tqACLossMin_C;
extern const uint16  SftyMgt_tqAltLossMaxGAP_C;
extern const uint16  SftyMgt_tqAltLossMaxICCP_C;
extern const uint16  SftyMgt_tqAltLossMaxMEL_C;
extern const uint16  SftyMgt_tqCkEngLossMax_C;
extern const uint16  SftyMgt_tqCkEngLossMin_C;
extern const uint16  SftyMgt_tqCkFricLossT_A[SFTYMGT_TQCKFRICLOSST_A_COLS];
extern const uint16  SftyMgt_tqCkFricLossT_T[SFTYMGT_TQCKFRICLOSST_T_COLS];
extern const uint16  SftyMgt_tqCkPmpHiPLoss_C;
extern const uint16  SftyMgt_tqCkPmpLossMax_A[SFTYMGT_TQCKPMPLOSSMAX_A_COLS];
extern const uint16  SftyMgt_tqCkPmpLossMax_T[SFTYMGT_TQCKPMPLOSSMAX_T_COLS];
extern const uint16  SftyMgt_tqCkPmpLossOfs_C;
extern const uint16  SftyMgt_tqCkStrtLossMax_C;
extern const uint16  SftyMgt_tqCnvLossMax_C;
extern const uint16  SftyMgt_tqCnvLossMin_C;
extern const uint16  SftyMgt_tqErrThdSftyEngLoss_C;
extern const uint16  SftyMgt_tqErrThdSftyLossAux_C;
extern const uint16  SftyMgt_tqErrThdSftyLossBVA_C;
extern const uint16  SftyMgt_tqFanStrtLossMax_C;
extern const uint16  SftyMgt_tqRelThdSftyLossAdp_C;
extern const uint16  SftyMgt_tqStgPmpLnrLossMax_C;
extern const uint16  SftyMgt_tqStgPmpLossMax_C;
extern const uint16  SftyMgt_tqStgPmpLossMin_C;
extern const uint16  SftyMgt_tqStgPmpThdLossMax_C;
#define TMS_STOP_SEC_CALIB_16BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define TMS_START_SEC_VAR_BOOLEAN
#include "MemMap.h"
extern boolean SftyMgt_bDgoTqSumLossCmp;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
extern uint16 SftyMgt_tqSumLossCmpChkBuf;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CODE
#include "MemMap.h"
void SftyMgt_SdlMid_tqAuxSumLoss(void);
void SftyMgt_SdlMid_tqCkEngLossAdp(void);
void SftyMgt_SdlMid_tqCkFricLoss(void);
void SftyMgt_SdlMid_tqCnvLoss(void);
void SftyMgt_SdlMid_tqSumLossCmp(void);
void SftyMgt_SdlMid_tqSumLossCord(void);
void TQLOSSMON_vidEntryInit(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"


#endif /* TQLOSSMON_H */

/*-------------------------------- end of file -------------------------------*/
