/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : FFGEN                                                    */
/*                                                                            */
/* !Module         : FFGEN                                                    */
/* !Description    : Public declarations for the component                    */
/*                                                                            */
/* !File           : FFGEN.H                                                  */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/FFGEN/FFGEN.H_v       $*/
/* $Revision::   1.1      $$Author::   lthibaud       $$Date::   01 Feb 2010 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef FFGEN_H
#define FFGEN_H

#include "STD_TYPES.h"


/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/
#define TMS_START_SEC_CODE
#include "MemMap.h"
void FFGEN_vidEntryInit(void);
void SftyMgt_SdlMid_FrfGen(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

#define SFTYMGT_PRM_BFRF_COLS                  ( 8 )            /* FFGEN_PrmBFrfSize */


/******************************************************************************/
/* ENUMS                                                                      */
/******************************************************************************/



/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/



/******************************************************************************/
/* BITFIELDS                                                                  */
/******************************************************************************/



/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
extern uint16  SftyMgt_prm_bFrf[SFTYMGT_PRM_BFRF_COLS];
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"

#endif /* FFGEN_H */

/*-------------------------------- end of file -------------------------------*/
