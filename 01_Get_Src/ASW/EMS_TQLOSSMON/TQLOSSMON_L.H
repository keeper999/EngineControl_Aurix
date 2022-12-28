/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : TQLOSSMON                                                */
/*                                                                            */
/* !Module         : TQLOSSMON                                                */
/* !Description    : Private declarations for the component                   */
/*                                                                            */
/* !File           : TQLOSSMON_L.H                                            */
/*                                                                            */
/* !Scope          : Private                                                  */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQLOSSMON/TQLOSSMON_L.$*/
/* $Revision::   1.3      $$Author::   mbenfrad       $$Date::   26 Nov 2012 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef TQLOSSMON_L_H
#define TQLOSSMON_L_H

#include "STD_TYPES.h"

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

#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
extern const uint8  TQLOSSMON_u8Inhib;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define TMS_START_SEC_VAR_BOOLEAN
#include "MemMap.h"
extern boolean SftyMgt_bDgoEngLossAdp;
extern boolean SftyMgt_bDgoEngLossAdpRaw_MP;
extern boolean SftyMgt_bDgoEngLossBVA;
extern boolean SftyMgt_bDgoTqAC;
extern boolean SftyMgt_bDgoTqAltLoss;
extern boolean SftyMgt_bDgoTqAuxLoss;
extern boolean SftyMgt_bDgoTqCkEngLoss;
extern boolean SftyMgt_bDgoTqCkHiPLoss;
extern boolean SftyMgt_bDgoTqFanRes;
extern boolean SftyMgt_bDgoTqStg;
extern boolean TQLOSSMON_bCnvLossSat;
extern boolean TQLOSSMON_bDgoEngLossAdpRawPrev;
extern boolean TQLOSSMON_bDgoEngLossBVAPrev;
extern boolean TQLOSSMON_bDgoTqCkEngLossPrev;
extern boolean TQLOSSMON_bForDebOutput;
extern boolean TQLOSSMON_bFstDebOutput;
extern boolean TQLOSSMON_bFstFunctDebTODInPrev;
extern boolean TQLOSSMON_bSndDebOutput;
extern boolean TQLOSSMON_bSumLossCmpPrev;
extern boolean TQLOSSMON_bThdDebOutput;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
extern uint16 SftyMgt_facFilTqACLossDown_MP;
extern uint16 SftyMgt_facFilTqACLossFil_MP;
extern uint16 SftyMgt_facFilTqACLossUp_MP;
extern uint16 SftyMgt_facFilTqCnvLoss;
extern uint16 SftyMgt_facFilTqCnvLossDown_MP;
extern uint16 SftyMgt_facFilTqCnvLossFil_MP;
extern uint16 SftyMgt_facFilTqCnvLossUp_MP;
extern uint16 SftyMgt_facFilTqStgDown_MP;
extern uint16 SftyMgt_facFilTqStgLossUp_MP;
extern uint16 SftyMgt_facFilTqStgPmpLoss_MP;
extern uint16 SftyMgt_pwrAC3Loss;
extern uint16 SftyMgt_pwrAC4Loss;
extern uint16 SftyMgt_pwrACLoss;
extern uint16 SftyMgt_pwrACLossFil;
extern uint16 SftyMgt_pwrACLossSum_MP;
extern uint16 SftyMgt_spdSel;
extern uint16 SftyMgt_spdVehSel;
extern uint16 SftyMgt_tqACLoss;
extern uint16 SftyMgt_tqACLoss_MP;
extern uint16 SftyMgt_tqACLossChkBuf;
extern uint16 SftyMgt_tqAltLoss;
extern uint16 SftyMgt_tqAltLoss_MP;
extern uint16 SftyMgt_tqAltLossChkBuf;
extern uint16 SftyMgt_tqAuxSumLossCmp;
extern uint16 SftyMgt_tqCkEngLoss_MP;
extern uint16 SftyMgt_tqCkEngLossAdpChkBuf;
extern uint16 SftyMgt_tqCkEngLossChkBuf;
extern uint16 SftyMgt_tqCkFricLoss;
extern uint16 SftyMgt_tqCkFricLoss_MP;
extern uint16 SftyMgt_tqCkPmpHiPLoss;
extern uint16 SftyMgt_tqCkPmpLoss;
extern uint16 SftyMgt_tqCkPmpLoss_MP;
extern uint16 SftyMgt_tqCkStrtLoss;
extern uint16 SftyMgt_tqCkStrtLoss_MP;
extern uint16 SftyMgt_tqCnvLoss_MP;
extern uint16 SftyMgt_tqCnvLossChkBuf;
extern uint16 SftyMgt_tqCnvLossEstimMax;
extern uint16 SftyMgt_tqCnvLossNotFilNotSat;
extern uint16 SftyMgt_tqCnvLossNotSat;
extern uint16 SftyMgt_tqCnvLossSum_MP;
extern uint16 SftyMgt_tqFanStrtLoss;
extern uint16 SftyMgt_tqStgPmpLnrLoss;
extern uint16 SftyMgt_tqStgPmpLoss;
extern uint16 SftyMgt_tqStgPmpLoss_MP;
extern uint16 SftyMgt_tqStgPmpLossChkBuf;
extern uint16 SftyMgt_tqStgPmpLossNotFil;
extern uint16 SftyMgt_tqStgPmpLossSum_MP;
extern uint16 SftyMgt_tqStgPmpThdLoss;
extern uint16 SftyMgt_tqSumLossCmpEstim;
extern uint16 TQLOSSMON_u16EngLossAdpCounter;
extern uint16 TQLOSSMON_u16FirstDebFctCounter;
extern uint16 TQLOSSMON_u16FourthDebFctCounter;
extern uint16 TQLOSSMON_u16SecondDebFctCounter;
extern uint16 TQLOSSMON_u16StrtLossCounter;
extern uint16 TQLOSSMON_u16ThirdDebFctCounter;
extern uint16 TQLOSSMON_u16tqAC3LossMax;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CODE
#include "MemMap.h"
void TQLOSSMON_vidCalculer_Couple(void);
void TQLOSSMON_vidChoisir_Type_Clim(void);
void TQLOSSMON_vidConvertir_P_Couple(void);
void TQLOSSMON_vidCoord_Pertes_Access(void);
void TQLOSSMON_vidCoordonner_pertes(void);
void TQLOSSMON_vidDet_Adaptatif_Perte(void);
void TQLOSSMON_vidDet_Coef_Filtre(void);
void TQLOSSMON_vidDet_Consigne_Couple(void);
void TQLOSSMON_vidDet_Demande_Altern(void);
void TQLOSSMON_vidDet_P_Conso_Type3(void);
void TQLOSSMON_vidDet_P_Conso_Type4(void);
void TQLOSSMON_vidDet_Pertes_Access(void);
void TQLOSSMON_vidDet_Pertes_Altern(void);
void TQLOSSMON_vidDet_Pertes_BVA(void);
void TQLOSSMON_vidDet_Pertes_BVM(void);
void TQLOSSMON_vidDet_Pertes_Clim(void);
void TQLOSSMON_vidDet_Pertes_DA(void);
void TQLOSSMON_vidDet_Pertes_DA_Lin(void);
void TQLOSSMON_vidDet_Pertes_DA_OnOff(void);
void TQLOSSMON_vidDet_Pertes_Max_Dem(void);
void TQLOSSMON_vidDet_Pertes_Max_Fric(void);
void TQLOSSMON_vidDet_Pertes_Max_Pomp(void);
void TQLOSSMON_vidDet_Pertes_Mot_Glob(void);
void TQLOSSMON_vidDet_Pertes_Moteur(void);
void TQLOSSMON_vidFiltrer_consigne(void);
void TQLOSSMON_vidFiltrer_Pertes_DA(void);
void TQLOSSMON_vidFiltrer_redond_ACS(void);
void TQLOSSMON_vidInitOutput(void);
void TQLOSSMON_vidSelectioner_Type_DA(void);
void TQLOSSMON_vidTraiter_entrees(void);
void TQLOSSMON_vidTraiter_Vveh(void);
void TQLOSSMON_vidVal_Demande_Altern(void);
void TQLOSSMON_vidVal_Pertes_Pompe_HP(void);
void TQLOSSMON_vidValider_consigne(void);
void TQLOSSMON_vidValider_Pertes_Clim(void);
void TQLOSSMON_vidValider_Pertes_Glob(void);
void TQLOSSMON_vidValider_Reserve_GMV(void);
void TQLOSSMON_vidValider_signal_ACS(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"


#endif /* TQLOSSMON_L_H */

/*-------------------------------- end of file -------------------------------*/
