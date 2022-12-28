/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : CAMHAL                                                  */
/* !Description     : CAMHAL Internal Configuration                           */
/*                                                                            */
/* !File            : CAMHAL_Cfg.h                                            */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;
 * <Revision>
 * %PID: P2017_BSW:0A192507.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef CAMHAL_CFG_H
#define CAMHAL_CFG_H

#include "Std_Types.h"
#include "ANGSCHED.h"
#include "CAMHAL_Cfg_I.h"
#include "CRKHAL.h"

/******************************************************************************/
/* GENERAL DEFINES                                                            */
/******************************************************************************/
#define CAMHAL_u8DEG_TO_TOOTH_FACTOR    CRKHAL_ku8CrankshaftFactor
#define CAMHAL_u16ENG_CYCLE_TICK_VALUE  CRKHAL_ku16EngineCycleAngle
#define CAMHAL_u16ENG_CYCLE_ANGLE_VALUE CRKHAL_u16ENGINE_CYCLE
#define CAMHAL_u16TDC_1_POSITION        CRKHAL_ku16TDC_1_Angle
#define CAMHAL_bENG_SYNC_ON_ANY_CYL     FALSE
#define CAMHAL_u8NUMBER_OF_CYLINDERS    CRKHAL_ku8NumberOfCylinders
#define CAMHAL_u8ANGSCHED_ALARM         ANGSCHED_u8ALARM_2

#define CAMHAL_snINTAKE_TIM           (CRKHAL_snCAMHAL_INCAM_EDGE_MNG_TIM)
#define CAMHAL_snEXHAUST_TIM          (CRKHAL_snCAMHAL_EXCAM_EDGE_MNG_TIM)


#define CAMHAL_snINTAKE_CHANNEL       (CRKHAL_snCAMHAL_INCAM_EDGE_MNG_CHANNEL)
#define CAMHAL_snEXHAUST_CHANNEL      (CRKHAL_snCAMHAL_EXCAM_EDGE_MNG_CHANNEL)


/******************************************************************************/
/* CALIBRATIONS DECLARATION */
/******************************************************************************/

#define CAMHAL_START_SEC_CALIB_8BIT
#include "CAMHAL_MemMap.h"

extern const uint8 CRKHAL_ku8CrankshaftFactor;
extern const uint8 CRKHAL_ku8NumberOfCylinders;

#define CAMHAL_STOP_SEC_CALIB_8BIT
#include "CAMHAL_MemMap.h"

#define CAMHAL_START_SEC_CALIB_16BIT
#include "CAMHAL_MemMap.h"

extern const uint16 CRKHAL_ku16EngineCycleAngle;
extern const uint16 CRKHAL_ku16TDC_1_Angle;

#define CAMHAL_STOP_SEC_CALIB_16BIT
#include "CAMHAL_MemMap.h"

#define CAMHAL_START_SEC_CALIB_BOOLEAN
#include "CAMHAL_MemMap.h"

extern const boolean CRKHAL_kbEngSyncOnAnyCylinder;

#define CAMHAL_STOP_SEC_CALIB_BOOLEAN
#include "CAMHAL_MemMap.h"


/******************************************************************************/
/* MACROS DEFINITIONS                                                         */
/******************************************************************************/
/* !Comment: Start the Angular Clock Generator counter                        */
#define CAMHAL_vidSTART_ANG_CLK_GEN_CNT() \
do \
{ \
} \
while(0)

/* !Comment: Stop the Angular Clock Generator counter                         */
#define CAMHAL_vidSTOP_ANG_CLK_GEN_CNT() \
do \
{ \
} \
while(0)

#endif /* CAMHAL_CFG_H */

/*------------------------------ end of file ---------------------------------*/

