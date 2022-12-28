/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : FFGEN                                                    */
/*                                                                            */
/* !Module         : FFGEN                                                    */
/* !Description    : Definitions for the component                            */
/*                                                                            */
/* !File           : FFGEN.C75                                                */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/FFGEN/FFGEN.c7v       $*/
/* $Revision::   1.0      $$Author::   lthibaud       $$Date::   17 Nov 2009 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#include "STD_TYPES.h"
#include "FFGEN.h"
#include "FFGEN_l.h"


/******************************************************************************/
/* ENUMS                                                                      */
/******************************************************************************/



/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
#define TMS_START_SEC_CALIB_8BIT
#include "MemMap.h"
const uint8      FFGEN_u8Inhib = 0;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"



/******************************************************************************/
/* BITFIELDS                                                                  */
/******************************************************************************/



/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/
#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
uint16  SftyMgt_prm_bFrf[SFTYMGT_PRM_BFRF_COLS];
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"
/*-------------------------------- end of file -------------------------------*/
