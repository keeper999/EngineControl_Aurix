/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : PFCHAL                                                  */
/* !Description     : PFCHAL Component                                        */
/*                                                                            */
/* !File            : PFCHAL_I.h                                              */
/* !Description     : Declaration of internal data of PFCHAL Component        */
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
 * %PID: P2017_BSW:0A111602.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef PFCHAL_I_H
#define PFCHAL_I_H

#include "Std_Types.h"
#include "PFCHAL_Cfg_I.h"


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

#define PFCHAL_u8UNSET_MODE 0
#define PFCHAL_u8DIO_MODE   1
#define PFCHAL_u8PWM_MODE   2


/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/

#define PFCHAL_START_SEC_CONST_UNSPECIFIED
#include "PFCHAL_MemMap.h"

/* !Comment: Array of pointer to functions of all defined PFCHAL_vidConfig    */
extern void (* const PFCHAL_akpfvidChannelConfig[PFCHAL_u8CHANNEL_NB])(uint8);

#define PFCHAL_STOP_SEC_CONST_UNSPECIFIED
#include "PFCHAL_MemMap.h"


/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define PFCHAL_START_SEC_CODE
#include "PFCHAL_MemMap.h"

extern void PFCHAL_vidInitConfig(void);

#define PFCHAL_STOP_SEC_CODE
#include "PFCHAL_MemMap.h"


#endif /* PFCHAL_I_H */

/*-------------------------------- end of file -------------------------------*/