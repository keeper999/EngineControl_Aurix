/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : NTARIDLCHK                                               */
/*                                                                            */
/* !Module         : NTARIDLCHK                                               */
/* !Description    : Private declarations for the component                   */
/*                                                                            */
/* !File           : NTARIDLCHK_L.H                                           */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/NTARIDLCHK/NTARIDLCHK_$*/
/* $Revision::   1.4      $$Author::   mbenfrad       $$Date::   05 Mar 2013 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef NTARIDLCHK_L_H
#define NTARIDLCHK_L_H

#include "STD_TYPES.h"

/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define SftyMgt_tiSdlNTarIdl_SC           40          /* 40 */

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
extern const uint8  NTARIDLCHK_u8Inhib;
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
extern boolean NTARIDLCHK_bTqSysAcvTqSysPrev;
extern boolean NTARIDLCHK_bTurnOnDlyTMS1;
extern boolean NTARIDLCHK_bTurnOnDlyTMS2;
extern boolean SftyMgt_bAcvIdlDynMon_MP;
#define TMS_STOP_SEC_VAR_BOOLEAN
#include "MemMap.h"

#define TMS_START_SEC_VAR_16BIT
#include "MemMap.h"
extern uint16 NTARIDLCHK_u16CounterTMS1;
extern uint16 NTARIDLCHK_u16CounterTMS2;
extern uint16 NTARIDLCHK_u16TarIdlDynIdSysPrev;
extern uint16 SftyMgt_nTarIdlStrt_MP;
extern uint16 SftyMgt_nTarIdlTqSysDly_MP;
extern uint16 SftyMgt_nTarIdlTqSysTol_MP;
#define TMS_STOP_SEC_VAR_16BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CODE
#include "MemMap.h"
void NTARIDLCHK_vidInitOutput(void);
void NTARIDLCHK_vidValConsigneRalenti(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"


#endif /* NTARIDLCHK_L_H */

/*-------------------------------- end of file -------------------------------*/
