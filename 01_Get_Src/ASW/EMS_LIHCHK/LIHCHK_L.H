/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : LIHCHK                                                   */
/*                                                                            */
/* !Module         : LIHCHK                                                   */
/* !Description    : Private declarations for the component                   */
/*                                                                            */
/* !File           : LIHCHK_L.H                                               */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/LIHCHK/LIHCHK_L.H_v   $*/
/* $Revision::   1.1      $$Author::   lthibaud       $$Date::   07 Dec 2009 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef LIHCHK_L_H
#define LIHCHK_L_H

#include "STD_TYPES.h"


/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/
#define TMS_START_SEC_CODE
#include "MemMap.h"
void LIHCHK_vidDeterminer_Limitation(void);
void LIHCHK_vidInitOutput(void);
void LIHCHK_vidValider_Limitation(void);
void LIHCHK_vidValider_Limp_Home(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/



/******************************************************************************/
/* ENUMS                                                                      */
/******************************************************************************/



/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
extern const uint8      LIHCHK_u8Inhib;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

/******************************************************************************/
/* BITFIELDS                                                                  */
/******************************************************************************/



/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
#define TMS_START_SEC_VAR_BOOLEAN
#include "MemMap.h"
extern boolean  LIHCHK_bTurnOnDelayInPrev;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"
#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
extern uint16  SftyMgt_nEngLim;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"
#define TMS_START_SEC_VAR_8BIT
#include "MemMap.h"
extern uint8  LIHCHK_u8TurnOnDelayCnt;
#define TMS_STOP_SEC_VAR_8BIT
#include "MemMap.h"

#endif /* LIHCHK_L_H */

/*-------------------------------- end of file -------------------------------*/
