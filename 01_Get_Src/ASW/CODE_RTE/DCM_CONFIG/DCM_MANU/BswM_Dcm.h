/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* !File            : BswM_Dcm.h                                              */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : Service Layer                                           */
/*                                                                            */
/* !Component       : BswM                                                    */
/* !Description     : Basic SW Manager                                        */
/*                                                                            */
/* !Component       : BswM                                                    */
/* !Description     : Basic SW Manager                                        */
/*                                                                            */
/* !File            : BswM_Dcm.h                                              */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : ALL                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEES                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2010 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/EBX6_2/LOG/ASW/REF/MODULES/DCM_CONFIG/DCM_MANU/Bsw$*/
/* $Revision::   1.2      $$Author::   pbakabad       $$Date::   22 May 2014 $*/
/******************************************************************************/

#ifndef BSWM_DCM_H
#define BSWM_DCM_H

#include "STD_TYPES.h"
#include "Dcm_Types.h"
#include "Rte_Type.h"

#include "DCM_MANU.h"
#include "DCM_MANU_L.h"
#include "DCM_MANU_IM.h"

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/*! \Description Autosar Release Major Version      \n
    \Range       4                                  \n
*******************************************************************************/
#define BSWM_AR_RELEASE_MAJOR_VERSION     (4U)
/******************************************************************************/
/*! \Description Autosar Release Minor Version      \n
    \Range       0                                  \n
*******************************************************************************/
#define BSWM_AR_RELEASE_MINOR_VERSION     (0U)

/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/
extern void BswM_Dcm_RequestSessionMode( Dcm_SesCtrlType RequestedMode );
extern void BswM_Dcm_RequestResetMode( Dcm_ResetModeType RequestedMode );

/******************************************************************************/
/* CALIBRATIONS DECLARATION                                                   */
/******************************************************************************/
extern const sint16 Srv_uDwnldMinVolt_C;
extern const sint16 Srv_uDwnldMaxVolt_C;
extern const uint8 Diag_seuil_vit_veh;

/******************************************************************************/
/* VARIABLES DECLARATION                                                      */
/******************************************************************************/
extern Dcm_ResetModeType DCM_MANU_ActionDmnd;

#endif  /* BSWM_DCM_H */
/*------------------------------ end of file -------------------------------*/
