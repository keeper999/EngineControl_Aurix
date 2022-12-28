/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : PFCHAL                                                  */
/* !Description     : Internal configurations of the PFCHAL component         */
/*                                                                            */
/* !File            : PFCHAL_CFG_I.h                                          */
/* !Description     : PFCHAL Internal configuration                           */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A192473.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef PFCHAL_CFG_I_H
#define PFCHAL_CFG_I_H

#include "Std_Types.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define PFCHAL_u8CHANNEL_NB       1u

/* !MComment: Index for the ECU channels                                      */
#define PFCHAL_u8CH_63            0u


/******************************************************************************/
/* DATA DECLARATIONS                                                          */
/******************************************************************************/

#define PFCHAL_START_SEC_VAR_8BIT
#include "PFCHAL_MemMap.h"

extern uint8 PFCHAL_au8CurrentMode[PFCHAL_u8CHANNEL_NB];

#define PFCHAL_STOP_SEC_VAR_8BIT
#include "PFCHAL_MemMap.h"


/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define PFCHAL_START_SEC_CODE
#include "PFCHAL_MemMap.h"

extern void PFCHAL_vidConfig_CH_63(uint8 u8Mode);

#define PFCHAL_STOP_SEC_CODE
#include "PFCHAL_MemMap.h"


#endif /* PFCHAL_CFG_I_H */


/*-------------------------------- end of file -------------------------------*/
