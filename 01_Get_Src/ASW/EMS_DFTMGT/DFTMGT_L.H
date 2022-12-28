/******************************************************************************/
/*                                                                            */
/* !Layer          : APPLI                                                    */
/*                                                                            */
/* !Component      : DFTMGT                                                   */
/*                                                                            */
/* !Module         : DFTMGT                                                   */
/* !Description    : Private declarations for the component                   */
/*                                                                            */
/* !File           : DFTMGT_L.H                                               */
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
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/DFTMGT/DFTMGT_L.H_v   $*/
/* $Revision::   1.1      $$Author::   MBENFRAD       $$Date::   Oct 21 2011 $*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/

#ifndef DFTMGT_L_H
#define DFTMGT_L_H

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
extern const uint8  DFTMGT_u8Inhib;
#define TMS_STOP_SEC_CALIB_8BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define TMS_START_SEC_VAR_32BIT
#include "MemMap.h"
extern uint32 DFTMGT_u32SftyMgt_DftECU;
#define TMS_STOP_SEC_VAR_32BIT
#include "MemMap.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

#define TMS_START_SEC_CODE
#include "MemMap.h"
void DFTMGT_vidInitOutput(void);
void DFTMGT_vidInterfaceDftSftyMgt(void);
void DFTMGT_vidIntrfDftSftyMgtDftECU(void);
void DFTMGT_vidIntrfDftSftyMgtPrmDft(void);
#define TMS_STOP_SEC_CODE
#include "MemMap.h"


#endif /* DFTMGT_L_H */

/*-------------------------------- end of file -------------------------------*/
