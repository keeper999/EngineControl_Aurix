/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : TQLOSSMON                                                */
/*                                                                            */
/* !Module         : TQLOSSMON                                                */
/* !Description    : Definitions for the component                            */
/*                                                                            */
/* !File           : TQLOSSMON.C75                                            */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQLOSSMON/TQLOSSMON.c7$*/
/* $Revision::   1.4      $$Author::   mbenfrad       $$Date::   26 Nov 2012 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#include "STD_TYPES.h"
#include "TQLOSSMON.h"
#include "TQLOSSMON_l.h"

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

#define TMS_START_SEC_CALIB_BOOLEAN
#include "MemMap.h"
const boolean  SftyMgt_bInhTqManGBxLoss_C = 0;
const boolean  SftyMgt_bSumLossCmpCnv_C = 0;
#define TMS_STOP_SEC_CALIB_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
const uint8  SftyMgt_facCnvLoss_Spd_T[SFTYMGT_FACCNVLOSS_SPD_T_COLS] = {0};
const uint8  SftyMgt_facStgLnrLossNCk_T[SFTYMGT_FACSTGLNRLOSSNCK_T_COLS] = {0};
const uint8  SftyMgt_facStgLnrLossSpd_T[SFTYMGT_FACSTGLNRLOSSSPD_T_COLS] = {0};
const uint8  SftyMgt_facStgPmpThdLossNCk_T[SFTYMGT_FACSTGPMPTHDLOSSNCK_T_COLS] = {0};
const uint8  SftyMgt_facStgThdLossSpd_T[SFTYMGT_FACSTGTHDLOSSSPD_T_COLS] = {0};
const uint8  SftyMgt_idxACTyp_C = 0;
const uint8  SftyMgt_idxAltTyp_C = 0;
const uint8  SftyMgt_idxStgPmpTyp_C = 0;
const uint8  TQLOSSMON_u8Inhib = 0;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
const sint16  SftyMgt_tqAltLossMax_C = 0;
const sint16  SftyMgt_tqAltLossMin_C = 0;
const sint16  SftyMgt_tqErrThdTqAuxLoss_C = 0;
const uint16  SftyMgt_facCnvPwrTqr_M[SFTYMGT_FACCNVPWRTQR_M_LNS][SFTYMGT_FACCNVPWRTQR_M_COLS] = {0};
const uint16  SftyMgt_facCnvTqrPwr_M[SFTYMGT_FACCNVTQRPWR_M_LNS][SFTYMGT_FACCNVTQRPWR_M_COLS] = {0};
const uint16  SftyMgt_facFilTqACLoss_C = 0;
const uint16  SftyMgt_facFilTqACLossDown_T[SFTYMGT_FACFILTQACLOSSDOWN_T_COLS] = {0};
const uint16  SftyMgt_facFilTqACLossUp_T[SFTYMGT_FACFILTQACLOSSUP_T_COLS] = {0};
const uint16  SftyMgt_facFilTqCnvLossDown_T[SFTYMGT_FACFILTQCNVLOSSDOWN_T_COLS] = {0};
const uint16  SftyMgt_facFilTqCnvLossUp_T[SFTYMGT_FACFILTQCNVLOSSUP_T_COLS] = {0};
const uint16  SftyMgt_facFilTqStgDown_T[SFTYMGT_FACFILTQSTGDOWN_T_COLS] = {0};
const uint16  SftyMgt_facFilTqStgLossUp_T[SFTYMGT_FACFILTQSTGLOSSUP_T_COLS] = {0};
const uint16  SftyMgt_facFilTqStgPmpLoss_C = 0;
const uint16  SftyMgt_nCk_X_A[SFTYMGT_NCK_X_A_COLS] = {0};
const uint16  SftyMgt_nCk_Y_A[SFTYMGT_NCK_Y_A_COLS] = {0};
const uint16  SftyMgt_nCkStgPmp_A[SFTYMGT_NCKSTGPMP_A_COLS] = {0};
const uint16  SftyMgt_nStrtTqLossThd_C = 0;
const uint16  SftyMgt_pwr_X_A[SFTYMGT_PWR_X_A_COLS] = {0};
const uint16  SftyMgt_pwrACMax_C = 0;
const uint16  SftyMgt_spdDftCnvLoss_C = 0;
const uint16  SftyMgt_spdDftStgPmp_C = 0;
const uint16  SftyMgt_spdTqCmp_A[SFTYMGT_SPDTQCMP_A_COLS] = {0};
const uint16  SftyMgt_tiDlyEngLossAdp_C = 0;
const uint16  SftyMgt_tiDlyEngLossDftOff_C = 0;
const uint16  SftyMgt_tiDlyEngLossDftOn_C = 0;
const uint16  SftyMgt_tiDlyLossAuxDftOff_C = 0;
const uint16  SftyMgt_tiDlyLossAuxDftOn_C = 0;
const uint16  SftyMgt_tiDlyLossBVADftOff_C = 0;
const uint16  SftyMgt_tiDlyLossBVADftOn_C = 0;
const uint16  SftyMgt_tiDlySumLossDftOff_C = 0;
const uint16  SftyMgt_tiDlySumLossDftOn_C = 0;
const uint16  SftyMgt_tiMaxStrtLoss_C = 0;
const uint16  SftyMgt_tq_X_A[SFTYMGT_TQ_X_A_COLS] = {0};
const uint16  SftyMgt_tqAC3BasLossMax_C = 0;
const uint16  SftyMgt_tqAC3OnLossMax_C = 0;
const uint16  SftyMgt_tqACLossMax_C = 0;
const uint16  SftyMgt_tqACLossMin_C = 0;
const uint16  SftyMgt_tqAltLossMaxGAP_C = 0;
const uint16  SftyMgt_tqAltLossMaxICCP_C = 0;
const uint16  SftyMgt_tqAltLossMaxMEL_C = 0;
const uint16  SftyMgt_tqCkEngLossMax_C = 0;
const uint16  SftyMgt_tqCkEngLossMin_C = 0;
const uint16  SftyMgt_tqCkFricLossT_A[SFTYMGT_TQCKFRICLOSST_A_COLS] = {0};
const uint16  SftyMgt_tqCkFricLossT_T[SFTYMGT_TQCKFRICLOSST_T_COLS] = {0};
const uint16  SftyMgt_tqCkPmpHiPLoss_C = 0;
const uint16  SftyMgt_tqCkPmpLossMax_A[SFTYMGT_TQCKPMPLOSSMAX_A_COLS] = {0};
const uint16  SftyMgt_tqCkPmpLossMax_T[SFTYMGT_TQCKPMPLOSSMAX_T_COLS] = {0};
const uint16  SftyMgt_tqCkPmpLossOfs_C = 0;
const uint16  SftyMgt_tqCkStrtLossMax_C = 0;
const uint16  SftyMgt_tqCnvLossMax_C = 0;
const uint16  SftyMgt_tqCnvLossMin_C = 0;
const uint16  SftyMgt_tqErrThdSftyEngLoss_C = 0;
const uint16  SftyMgt_tqErrThdSftyLossAux_C = 0;
const uint16  SftyMgt_tqErrThdSftyLossBVA_C = 0;
const uint16  SftyMgt_tqFanStrtLossMax_C = 0;
const uint16  SftyMgt_tqRelThdSftyLossAdp_C = 0;
const uint16  SftyMgt_tqStgPmpLnrLossMax_C = 0;
const uint16  SftyMgt_tqStgPmpLossMax_C = 0;
const uint16  SftyMgt_tqStgPmpLossMin_C = 0;
const uint16  SftyMgt_tqStgPmpThdLossMax_C = 0;
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
boolean SftyMgt_bDgoEngLossAdp;
boolean SftyMgt_bDgoEngLossAdpRaw_MP;
boolean SftyMgt_bDgoEngLossBVA;
boolean SftyMgt_bDgoTqAC;
boolean SftyMgt_bDgoTqAltLoss;
boolean SftyMgt_bDgoTqAuxLoss;
boolean SftyMgt_bDgoTqCkEngLoss;
boolean SftyMgt_bDgoTqCkHiPLoss;
boolean SftyMgt_bDgoTqFanRes;
boolean SftyMgt_bDgoTqStg;
boolean SftyMgt_bDgoTqSumLossCmp;
boolean TQLOSSMON_bCnvLossSat;
boolean TQLOSSMON_bDgoEngLossAdpRawPrev;
boolean TQLOSSMON_bDgoEngLossBVAPrev;
boolean TQLOSSMON_bDgoTqCkEngLossPrev;
boolean TQLOSSMON_bForDebOutput;
boolean TQLOSSMON_bFstDebOutput;
boolean TQLOSSMON_bFstFunctDebTODInPrev;
boolean TQLOSSMON_bSndDebOutput;
boolean TQLOSSMON_bSumLossCmpPrev;
boolean TQLOSSMON_bThdDebOutput;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
uint16 SftyMgt_facFilTqACLossDown_MP;
uint16 SftyMgt_facFilTqACLossFil_MP;
uint16 SftyMgt_facFilTqACLossUp_MP;
uint16 SftyMgt_facFilTqCnvLoss;
uint16 SftyMgt_facFilTqCnvLossDown_MP;
uint16 SftyMgt_facFilTqCnvLossFil_MP;
uint16 SftyMgt_facFilTqCnvLossUp_MP;
uint16 SftyMgt_facFilTqStgDown_MP;
uint16 SftyMgt_facFilTqStgLossUp_MP;
uint16 SftyMgt_facFilTqStgPmpLoss_MP;
uint16 SftyMgt_pwrAC3Loss;
uint16 SftyMgt_pwrAC4Loss;
uint16 SftyMgt_pwrACLoss;
uint16 SftyMgt_pwrACLossFil;
uint16 SftyMgt_pwrACLossSum_MP;
uint16 SftyMgt_spdSel;
uint16 SftyMgt_spdVehSel;
uint16 SftyMgt_tqACLoss;
uint16 SftyMgt_tqACLoss_MP;
uint16 SftyMgt_tqACLossChkBuf;
uint16 SftyMgt_tqAltLoss;
uint16 SftyMgt_tqAltLoss_MP;
uint16 SftyMgt_tqAltLossChkBuf;
uint16 SftyMgt_tqAuxSumLossCmp;
uint16 SftyMgt_tqCkEngLoss_MP;
uint16 SftyMgt_tqCkEngLossAdpChkBuf;
uint16 SftyMgt_tqCkEngLossChkBuf;
uint16 SftyMgt_tqCkFricLoss;
uint16 SftyMgt_tqCkFricLoss_MP;
uint16 SftyMgt_tqCkPmpHiPLoss;
uint16 SftyMgt_tqCkPmpLoss;
uint16 SftyMgt_tqCkPmpLoss_MP;
uint16 SftyMgt_tqCkStrtLoss;
uint16 SftyMgt_tqCkStrtLoss_MP;
uint16 SftyMgt_tqCnvLoss_MP;
uint16 SftyMgt_tqCnvLossChkBuf;
uint16 SftyMgt_tqCnvLossEstimMax;
uint16 SftyMgt_tqCnvLossNotFilNotSat;
uint16 SftyMgt_tqCnvLossNotSat;
uint16 SftyMgt_tqCnvLossSum_MP;
uint16 SftyMgt_tqFanStrtLoss;
uint16 SftyMgt_tqStgPmpLnrLoss;
uint16 SftyMgt_tqStgPmpLoss;
uint16 SftyMgt_tqStgPmpLoss_MP;
uint16 SftyMgt_tqStgPmpLossChkBuf;
uint16 SftyMgt_tqStgPmpLossNotFil;
uint16 SftyMgt_tqStgPmpLossSum_MP;
uint16 SftyMgt_tqStgPmpThdLoss;
uint16 SftyMgt_tqSumLossCmpChkBuf;
uint16 SftyMgt_tqSumLossCmpEstim;
uint16 TQLOSSMON_u16EngLossAdpCounter;
uint16 TQLOSSMON_u16FirstDebFctCounter;
uint16 TQLOSSMON_u16FourthDebFctCounter;
uint16 TQLOSSMON_u16SecondDebFctCounter;
uint16 TQLOSSMON_u16StrtLossCounter;
uint16 TQLOSSMON_u16ThirdDebFctCounter;
uint16 TQLOSSMON_u16tqAC3LossMax;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

