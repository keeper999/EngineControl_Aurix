/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : SECUBV                                                   */
/*                                                                            */
/* !Module         : SECUBV                                                   */
/* !Description    : Private declarations for the component                   */
/*                                                                            */
/* !File           : SECUBV_L.H                                               */
/*                                                                            */
/* !Scope          : Private                                                  */
/*                                                                            */
/* !Target         : Hitachi SH705x                                           */
/*                                                                            */
/* !Vendor         : VEES                                                     */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT 2006 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/SECUBV/SECUBV_L.H_v   $*/
/* $Revision::   1.6      $$Author::   mbenfrad       $$Date::   12 Mar 2013 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef SECUBV_L_H
#define SECUBV_L_H

#include "STD_TYPES.h"

/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define SECUBV_u8ARRAY_LENGTH             5            /* 5 */

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
extern const uint8  SECUBV_u8Inhib;
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
extern boolean SECUBV_bEnaDftDeltaTqIRunPrev;
extern boolean SECUBV_bEnaSIPCntRun_Prev;
extern boolean SftyMgt_bDeac0TqGBxATAMTCf;
extern boolean SftyMgt_bDeac0TqGBxMTCf;
extern boolean SftyMgt_bDftDeltaTq;
extern boolean SftyMgt_bDftDeltaTqI;
extern boolean SftyMgt_bDftSIPFRM;
extern boolean SftyMgt_bDftSIPInvld;
extern boolean SftyMgt_bDftSIPORng;
extern boolean SftyMgt_bDgoDeltaTq;
extern boolean SftyMgt_bDgoDeltaTqCord;
extern boolean SftyMgt_bDgoDeltaTqCordAL4;
extern boolean SftyMgt_bDgoDeltaTqCordNotAL4;
extern boolean SftyMgt_bDgoDeltaTqI;
extern boolean SftyMgt_bDgoSIPCord;
extern boolean SftyMgt_bDgoSIPNotIp;
extern boolean SftyMgt_bDgoTqGBxATAMTCf;
extern boolean SftyMgt_bDgoTqGBxMTCf;
extern boolean SftyMgt_bEnaAL4;
extern boolean SftyMgt_bEnaATAMTCf;
extern boolean SftyMgt_bEnaDftDeltaTqIRst;
extern boolean SftyMgt_bEnaDftDeltaTqIRun;
extern boolean SftyMgt_bEnaMTCf;
extern boolean SftyMgt_bEnaNbTarGearChgSIPRst;
extern boolean SftyMgt_bEnaNbTarGearChgSIPRun;
extern boolean SftyMgt_bEnaNbTarGearChgTqIRst;
extern boolean SftyMgt_bEnaNbTarGearChgTqIRun;
extern boolean SftyMgt_bEnaNotAL4;
extern boolean SftyMgt_bEnaNRegReqChgSIPRst;
extern boolean SftyMgt_bEnaNRegReqChgSIPRun;
extern boolean SftyMgt_bEnaSIPCntRst;
extern boolean SftyMgt_bEnaSIPCntRun;
extern boolean SftyMgt_bInhSIPCord_MP;
extern boolean SftyMgt_bNbTarGearChgSIP;
extern boolean SftyMgt_bNbTarGearChgSIPRst;
extern boolean SftyMgt_bNbTarGearChgSIPRun;
extern boolean SftyMgt_bNbTarGearChgTqI;
extern boolean SftyMgt_bNbTarGearChgTqIRst;
extern boolean SftyMgt_bNbTarGearChgTqIRun;
extern boolean SftyMgt_bNRegReqChgSIP;
extern boolean SftyMgt_bNRegReqChgSIPRst;
extern boolean SftyMgt_bNRegReqChgSIPRun;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_VAR_8BIT
#include "MemMap.h"
extern uint8 SECUBV_u8SftyMgt_bDgoSIPNotIpCnt;
extern uint8 SECUBV_u8tiDlyOnDgoDeltaTq_Cnt;
extern uint8 SECUBV_u8tiDlyOnDgoDeltaTqI_Cnt;
#define TMS_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
extern sint16 SftyMgt_tqTiDeltaTqI;
extern sint16 SftyMgt_tqTiDeltaTqIRst;
extern sint16 SftyMgt_tqTiDeltaTqIRun;
extern uint16 SECUBV_u16tiDlyOnDgoTqGBx_Cnt;
extern uint16 SECUBV_u16tiDlyOnDgoTqGBx_Cnt_1;
extern uint16 SECUBV_u16tiDlyOnDgoTqGBx_Cnt_2;
extern uint16 SftyMgt_tiSIPCnt;
extern uint16 SftyMgt_tiSIPCntRst;
extern uint16 SftyMgt_tiSIPCntRun;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CODE
#include "MemMap.h"
void SECUBV_vidAL4AT8Presente(void);
void SECUBV_vidAutre(void);
void SECUBV_vidBVABVMPConfiguration(void);
void SECUBV_vidBVConfiguration(void);
void SECUBV_vidBVMConfiguration(void);
void SECUBV_vidCalculSIPOutOfRange(void);
void SECUBV_vidComparaisonSeuilSIP(void);
void SECUBV_vidCompSeuilIntegrSurcple(void);
void SECUBV_vidCompteurSIP(void);
void SECUBV_vidConfiguationAL4(void);
void SECUBV_vidCoordDebounceSIPErreur(void);
void SECUBV_vidCoordinationAL4Erreur(void);
void SECUBV_vidCoordinationDefautsAL4(void);
void SECUBV_vidDebounDefDeltaAirAvAl4(void);
void SECUBV_vidDebounDefIntSurcpleAL4(void);
void SECUBV_vidDetectErrCplLentCplRap(void);
void SECUBV_vidDetectErrIntegrSurcple(void);
void SECUBV_vidDetectionSIPInvalide(void);
void SECUBV_vidIFTHENCompteurSIP(void);
void SECUBV_vidIFTHENIntegraleSurcple(void);
void SECUBV_vidIncrementeCompteurSIP(void);
void SECUBV_vidInitOutput(void);
void SECUBV_vidIntegraleSurcouple(void);
void SECUBV_vidIntegraleSurcple(void);
void SECUBV_vidRAZCompteurSIP(void);
void SECUBV_vidRAZCompteursSurChange(void);
void SECUBV_vidRAZIntegraleSurcouple(void);
void SECUBV_vidSecurisaMiseEnPlaceFRM(void);
void SECUBV_vidSecurisationGBxActive(void);
void SECUBV_vidSecurisationSpecifAL4(void);
void SECUBV_vidSecurisationTempsSIP(void);
void SECUBV_vidStrategieRAZFctBoite(void);
void SECUBV_vidSyntheseDefaut(void);
void SECUBV_vidTraiChgRapInCpleNiv1V2(void);
void SECUBV_vidTraiChgRapInCpleRst(void);
void SECUBV_vidTraiChgRapInCpleRun(void);
void SECUBV_vidTraiChgRapSIPRst(void);
void SECUBV_vidTraiChgRapSIPRun(void);
void SECUBV_vidTraiChgRapSIPSdlNiv1V2(void);
void SECUBV_vidTrRegulRegAM6Rst(void);
void SECUBV_vidTrRegulRegAM6Run(void);
void SECUBV_vidTrRegulRegAM6SdlNiv1V2(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"


#endif /* SECUBV_L_H */

/*-------------------------------- end of file -------------------------------*/
