/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : FFGEN                                                    */
/*                                                                            */
/* !Module         : FFGEN                                                    */
/* !Description    : Private declarations for the component                   */
/*                                                                            */
/* !File           : FFGEN_L.H                                                */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/FFGEN/FFGEN_L.H_v     $*/
/* $Revision::   1.0      $$Author::   lthibaud       $$Date::   17 Nov 2009 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef FFGEN_L_H
#define FFGEN_L_H

#include "STD_TYPES.h"


/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/
#define TMS_START_SEC_CODE
#include "MemMap.h"
void FFGEN_vidConstructionFrf(void);
void FFGEN_vidInitOutput(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

#define FFGEN_PrmBFrfSize                (uint8)8            /* 8 */


/******************************************************************************/
/* ENUMS                                                                      */
/******************************************************************************/



/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
extern const uint8      FFGEN_u8Inhib;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

/******************************************************************************/
/* BITFIELDS                                                                  */
/******************************************************************************/



/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/



#endif /* FFGEN_L_H */

/*-------------------------------- end of file -------------------------------*/
