/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : TQCOMON                                                  */
/*                                                                            */
/* !Module         : TQCOMON                                                  */
/* !Description    : Private declarations for the component                   */
/*                                                                            */
/* !File           : TQCOMON_L.H                                              */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQCOMON/TQCOMON_L.H_v $*/
/* $Revision::   1.1      $$Author::   acabresp       $$Date::   19 Oct 2009 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef TQCOMON_L_H
#define TQCOMON_L_H

#include "STD_TYPES.h"


/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define TMS_START_SEC_CODE
#include "MemMap.h"

void TQCOMON_vidConversion_CME_CMI(void);
void TQCOMON_vidCoordonner_Agrement(void);
void TQCOMON_vidCoordonner_Couple_BV(void);
void TQCOMON_vidCoordonner_Couple_ESP(void);
void TQCOMON_vidCoordonner_XVV(void);
void TQCOMON_vidCoordonnerLimRalenti(void);
void TQCOMON_vidCoordRelanceRegimeBV(void);
void TQCOMON_vidInitOutput(void);

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

#define TMS_START_SEC_CALIB_UNSPECIFIED
#include "MemMap.h"

extern const uint8      TQCOMON_u8Inhib;

#define TMS_STOP_SEC_CALIB_UNSPECIFIED
#include "MemMap.h"

/******************************************************************************/
/* BITFIELDS                                                                  */
/******************************************************************************/



/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
#define TMS_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

extern boolean  TQCOMON_bDebounceInputPrev;
extern sint16  SftyMgt_tqCoCha_MP;
extern uint16  TQCOMON_u16TiDlyCounter;

#define TMS_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#endif /* TQCOMON_L_H */

/*-------------------------------- end of file -------------------------------*/
