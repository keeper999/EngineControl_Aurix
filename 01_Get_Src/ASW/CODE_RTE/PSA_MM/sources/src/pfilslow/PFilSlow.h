/*******************************************************************************
*                    Delphi Diesel Systems
*
*                    This document is the property of
*                    Delphi Diesel Systems
*                    It must not be copied (in whole or in part)
*                    or disclosed without prior written consent
*                    of the company. Any copies by any method
*                    must also include a copy of this legend.
********************************************************************************
* Task File History: This comment block is automatically
*                    updated by the configuration management tool
*                    DO NOT Update manually
*------------------------------------------------------------------------------*
*
* Ref X:\integration_view_00PSASWC_E310D01\blois_psa_sstg\Software\Appli\PFilSlow\src\PFilSlow.h
* Version int :/main/00PSASWC_E3/2 Date: 24/1/2011 15 h 34 m User:esnault 
*    TWK_model:NO_MODEL
*    comments :for PFilSlow 11.0
* Version dev :\main\branch_lemort_pfilslow_dev\1 Date: 24/1/2011 12 h 47 m User:lemort 
*    TWK_model:NO_MODEL
*    comments :for PFilSlow 11.0
* Version int :/main/00PSASWC_E3/1 Date: 23/7/2010 14 h 44 m User:esnault
*    TWK_model:NO_MODEL
*    comments :change STATIC
* Version dev :\main\branch_lemort_pfilslow_dev\2 Date: 23/7/2010 10 h 41 m User:lemort
*    TWK_model:NO_MODEL
*    comments :change STATIC
* Version dev :\main\branch_lemort_pfilslow_dev\1 Date: 1/7/2010 17 h 1 m User:lemort
*    TWK_model:NO_MODEL
*    comments :dev in progress
* Version int :/main/P2868/BR_06E3/2 Date: 7/9/2009 9 h 59 m User:langendorf
*    TWK_model:LDCR_Application_06E310_IMPL1
*    comments :for dev PFilSlow 2.0
* Version dev :\main\branch_lemort_pfilslow_dev\1 Date: 7/8/2009 14 h 19 m User:lemort
*    TWK_model:LDCR_Application_06E310_IMPL1
*    comments :for dev PFilSlow 2.0
* Version int :/main/P2868/BR_06E3/1 Date: 2/9/2008 15 h 30 m User:boucher
*    TWK_model:LDCR_Application_06E300_IMPL1
*    comments :First version.
* Version dev :\main\branch_girodon_pfilslow_1_dev\1 Date: 29/8/2008 10 h 47 m User:girodon
*    TWK_model:LDCR_Application_06E300_IMPL1
*    comments :First version.
*
*******************************************************************************/


#ifndef PFILSLOW_H
#define PFILSLOW_H

/*******************************************************************************
*  Library Include Files
*******************************************************************************/

#include "Rte_PFilSlow.h"


/*******************************************************************************
*  Minimum Library Version Required
*******************************************************************************/

#define PFILSLOW_DDS_LIB_VERSION_REQ 100

/*******************************************************************************
*  File Macro Definitions
*******************************************************************************/

#ifdef _DDS_STATIC_
#undef _DDS_STATIC_
#endif
/* For FS: Add static word */
#define _DDS_STATIC_


/*******************************************************************************
*  Task & Feature Global Function Prototype Region
*******************************************************************************/

#define PFILSLOW_START_SEC_CODE
#include "PFilSlow_MemMap.h"

extern FUNC(void, AUTOMATIC) PFILSLOW_Prev_Agr_Slow(UInt16 CoVSCtl_rAccPEng_swc_in, /* BIN7 */
													UInt16 Eng_nCkFil_swc_in, /* BIN2 */
													SInt16 TqLimEM_tqLimEM_swc_in, /* BIN4 */
													SInt16 TqSys_nDif_nEngNTrb_swc_in, /* BIN2 */
													UInt16 TqSys_nEngDeceIni_swc_in, /* BIN2 */
													UInt8 TqSys_noGearDece_swc_in, /* BIN0 */
													UInt8 TqSys_noGearCordDrivFil_swc_in, /* BIN0 */
													UInt8 TqSys_stDrivFilCfPha_swc_in, /* BIN0 */
													SInt16 TqSys_tqCkDeceIniIt_swc_in, /* BIN4 */
													SInt16 TqSys_tqCkEfcFil_swc_in, /* BIN4 */
													SInt16 TqSys_tqThdPha3It_swc_in, /* BIN4 */
													CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEfcAirFil_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) PFILSLOW_Coord_Slow_Esp(UInt8 CoCha_bTqReqASR_swc_in,
                                              UInt8 CoCha_bTqReqMSR_swc_in,
                                              UInt8 CoPt_stProt_swc_in, /* BIN0 */
                                              SInt16 CoPt_tqEfcMaxProtDftl_swc_in, /* BIN4 */
                                              UInt8 FRM_bInhESPReq_swc_in,
                                              SInt16 TqCha_tqAirTqDecReq_swc_in, /* BIN4 */
                                              SInt16 TqCha_tqAirTqIncReq_swc_in, /* BIN4 */
                                              SInt16 TqSys_tqCkEfcAirFil_swc_in, /* BIN4 */
                                              CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bAcvCllIt_swc_out,
                                              CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) CoCha_tiTranCllIt_swc_out, /* DEC2 */
                                              CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoCha_tqEfcAirReq_swc_out, /* BIN4 */
                                              CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoCha_tqIncCllIt_swc_out /* BIN4 */);


/*******************************************************************************
*  Task & Feature Initialisation Function Prototypes Region
*******************************************************************************/

extern FUNC(void, AUTOMATIC) PFILSLOW_Prev_Agr_Slow_Init( CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) TqSys_tqCkEfcAirFil_swc_out /* BIN4 */);

extern FUNC(void, AUTOMATIC) PFILSLOW_Coord_Slow_Esp_Init(CONSTP2VAR(UInt8, AUTOMATIC, AUTOMATIC) CoCha_bAcvCllIt_swc_out,
                                                   CONSTP2VAR(UInt16, AUTOMATIC, AUTOMATIC) CoCha_tiTranCllIt_swc_out, /* DEC2 */
                                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoCha_tqEfcAirReq_swc_out, /* BIN4 */
                                                   CONSTP2VAR(SInt16, AUTOMATIC, AUTOMATIC) CoCha_tqIncCllIt_swc_out /* BIN4 */);

/*******************************************************************************
*  Specific Macro Definitions (using RTE interface)
*******************************************************************************/

/* TIMERS */

#define PFILSLOW_STOP_SEC_CODE
#include "PFilSlow_MemMap.h"

#endif

