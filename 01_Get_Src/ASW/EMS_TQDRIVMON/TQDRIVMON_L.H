/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : TQDRIVMON                                                */
/*                                                                            */
/* !Module         : TQDRIVMON                                                */
/* !Description    : Private declarations for the component                   */
/*                                                                            */
/* !File           : TQDRIVMON_L.H                                            */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQDRIVMON/TQDRIVMON_L.$*/
/* $Revision::   1.6      $$Author::   mbenfrad       $$Date::   12 Mar 2013 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef TQDRIVMON_L_H
#define TQDRIVMON_L_H

#include "STD_TYPES.h"

/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define TQDRIVMON_ASFTYMGT_TQCKEFC_NENGY_COLS  (16)

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
extern const uint8  TQDRIVMON_u8Inhib;
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
extern boolean SftyMgt_bAccPDZone_MP;
extern boolean SftyMgt_bDgo_rDrivTakeOff;
extern boolean SftyMgt_bDgo_rDrivTakeOff_MP;
extern boolean SftyMgt_bDgoTakeOffRaw_MP;
extern boolean SftyMgt_bDgoTqDemMax_MP;
extern boolean SftyMgt_bDgoTqDemMaxRaw_MP;
extern boolean SftyMgt_bModSptDft;
extern boolean SftyMgt_bTakeOffInh_MP;
extern boolean SftyMgt_bTqAccPOff_MP;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_VAR_8BIT
#include "MemMap.h"
extern uint8 SftyMgt_facAdpAccPOff_MP;
extern uint8 SftyMgt_facNIdl_MP;
#define TMS_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
extern sint16 SftyMgt_tqCkEfcWoutAntiDBTol;
extern sint16 SftyMgt_tqCkMaxAbs;
extern uint16 TQDRIVMON_aSftyMgt_tqCkEfc_nEngY[TQDRIVMON_ASFTYMGT_TQCKEFC_NENGY_COLS];
extern uint16 TQDRIVMON_u16facNEngIdl;
extern uint16 TQDRIVMON_u16TurnOnDelayCounter;
extern uint16 TQDRIVMON_u16TurnOnDelayCounter1;
extern uint16 TQDRIVMON_u16TurnOnDelayCounter2;
extern uint16 TQDRIVMON_u16TurnOnDelayCounter3;
extern uint16 TQDRIVMON_u16TurnOnDelayCounter4;
extern uint16 TQDRIVMON_u16TurnOnDelayCounter5;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CODE
#include "MemMap.h"
void TQDRIVMON_vidCalcCoupleSorIVC1(void);
void TQDRIVMON_vidEnveloppeCoupleMaxi(void);
void TQDRIVMON_vidGenererrDrivTakeOff(void);
void TQDRIVMON_vidInitOutput(void);
void TQDRIVMON_vidValAideDecollage(void);
void TQDRIVMON_vidValAntiCourseMorte(void);
void TQDRIVMON_vidValCoupleNivAppli(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"


#endif /* TQDRIVMON_L_H */

/*-------------------------------- end of file -------------------------------*/
