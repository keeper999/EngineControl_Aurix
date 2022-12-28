/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : PDSTHRCHK                                                */
/*                                                                            */
/* !Module         : PDSTHRCHK                                                */
/* !Description    : Private declarations for the component                   */
/*                                                                            */
/* !File           : PDSTHRCHK_L.H                                            */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/PDSTHRCHK/PDSTHRCHK_L.$*/
/* $Revision::   1.4      $$Author::   mbenfrad       $$Date::   02 Jul 2013 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef PDSTHRCHK_L_H
#define PDSTHRCHK_L_H

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
extern const uint8  PDSTHRCHK_u8Inhib;
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
extern boolean PDSTHRCHK_bFiltredExtMesSI;
extern boolean SftyMgt_bDftAirExt;
extern boolean SftyMgt_bDftGrdAirExt;
extern boolean SftyMgt_bDftPresDsThr_MP;
extern boolean SftyMgt_bDftThdAirExt_MP;
extern boolean SftyMgt_bDftThdGrdAirExt_MP;
extern boolean SftyMgt_bDgoAirExt_MP;
extern boolean SftyMgt_bDgoGrdAirExt_MP;
extern boolean SftyMgt_bDgoPresDsThr_MP;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"


#define TMS_START_SEC_VAR_32BIT
#include "MemMap.h"
extern uint32 PDSTHRCHK_u32FiltredExtMesSIMem;
extern uint32 PDSTHRCHK_u32FiltredposnThrMem;
extern uint32 PDSTHRCHK_u32FiltredTrbActReqMem;
#define TMS_STOP_SEC_VAR_32BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
extern uint16 PDSTHRCHK_u16OutputFilter2;
extern uint16 PDSTHRCHK_u16SftyMgtAcReqFilPrev;
extern uint16 PDSTHRCHK_u16tiDlyAirExtDft;
extern uint16 PDSTHRCHK_u16tiDlyGrdAirExtDft;
extern uint16 PDSTHRCHK_u16tiDlyPresDsThrOn;
extern uint16 SftyMgt_pAirExtMesSIFil_MP;
extern uint16 SftyMgt_pDsThrEstim;
extern uint16 SftyMgt_pDsThrOfs;
extern uint16 SftyMgt_pPosnThr_MP;
extern uint16 SftyMgt_pTrbActCor_MP;
extern uint16 SftyMgt_rOpTrbActReqFil_MP;
extern uint16 SftyMgt_rOpTrbActReqGrd_MP;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CODE
#include "MemMap.h"
void PDSTHRCHK_vidCompSecurisation(void);
void PDSTHRCHK_vidEstimOffAppSec(void);
void PDSTHRCHK_vidEstimPresAdmission(void);
void PDSTHRCHK_vidInitOutput(void);
void PDSTHRCHK_vidSecurPressSensor(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"


#endif /* PDSTHRCHK_L_H */

/*-------------------------------- end of file -------------------------------*/
