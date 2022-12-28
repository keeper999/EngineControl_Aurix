/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : TQVSCTLCHK                                               */
/*                                                                            */
/* !Module         : TQVSCTLCHK                                               */
/* !Description    : Private declarations for the component                   */
/*                                                                            */
/* !File           : TQVSCTLCHK_L.H                                           */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/TQVSCTLCHK/TQVSCTLCHK_$*/
/* $Revision::   1.2      $$Author::   mbenfrad       $$Date::   12 Mar 2013 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef TQVSCTLCHK_L_H
#define TQVSCTLCHK_L_H

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
extern const uint8  TQVSCTLCHK_u8Inhib;
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
extern boolean SftyMgt_bDftBrkPedPress_MP;
extern boolean SftyMgt_bDftTqVSCtl_MP;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_CALIB_16BIT
#include "MemMap.h"
extern sint16 SftyMgt_tqCkEfc_MP;
extern sint16 SftyMgt_tqEfcVSCtlSum_MP;
extern uint16 TQCKEFCFIL_u16BrkPedPressCounter;
extern uint16 TQCKEFCFIL_u16TqVSCtl_Counter;
#define TMS_STOP_SEC_CALIB_16BIT
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CODE
#include "MemMap.h"
void TQVSCTLCHK_vidDesacRVVAppuiFrein(void);
void TQVSCTLCHK_vidInitOutput(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"


#endif /* TQVSCTLCHK_L_H */

/*-------------------------------- end of file -------------------------------*/
