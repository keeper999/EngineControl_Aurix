/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : INJHAL                                                  */
/* !Description     : Injection Hardware Abstraction Layer                    */
/*                                                                            */
/* !File            : INJHAL_CFG_E.h                                          */
/* !Description     : Configuration of the INJHAL Component                   */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/

#ifndef INJHAL_CFG_E_H
#define INJHAL_CFG_E_H

#include "Std_Types.h"

#include "INJHAL_CFG_I.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/*************************************************************************/
/* INJHAL Injector Instances ID For The Appli                            */
/*************************************************************************/


/*************************************************************************/
/* INJHAL Injector Channels ID For The Appli                             */
/*************************************************************************/
#define CH_INJ_1_GDI CM_66
#define CH_INJ_2_GDI CM_45
#define CH_INJ_3_GDI CM_24


/*************************************************************************/
/* Injector Masks For The Appli                                          */
/*************************************************************************/
#define INJ_HAL_CYLINDER_1_MASK CM_66_MASK
#define INJ_HAL_CYLINDER_2_MASK CM_45_MASK
#define INJ_HAL_CYLINDER_3_MASK CM_24_MASK


/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/
#define INJHAL_START_SEC_CODE
#include "INJHAL_MemMap.h"


extern FUNC(void, INJHAL_CODE) INJHAL_vidAngleTimeNotif_CM_66(uint16 IrqNotifVal);
extern FUNC(void, INJHAL_CODE) INJHAL_vidAngleTimeNotif_CM_45(uint16 IrqNotifVal);
extern FUNC(void, INJHAL_CODE) INJHAL_vidAngleTimeNotif_CM_24(uint16 IrqNotifVal);


#define INJHAL_STOP_SEC_CODE
#include "INJHAL_MemMap.h"

#endif /* INJHAL_CFG_E_H */

/*------------------------------- end of file --------------------------------*/
