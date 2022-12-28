/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : INJHAL                                                  */
/* !Description     : Injection Hardware Abstraction Layer                    */
/*                                                                            */
/* !File            : INJHAL_GTM_CFG.h                                        */
/* !Description     : Configuration of the INJHAL Component                   */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/

#ifndef INJHAL_GTM_CFG_H_
#define INJHAL_GTM_CFG_H_

#include "IfxPort_reg.h"

   #define INJHAL_SN_CM_66_TOUT      (71u)
   #define INJHAL_SN_CM_66_PORT      (&MODULE_P15)
   #define INJHAL_SN_CM_66_PIN       (0u)
   #define INJHAL_SN_CM_66_GTM_TIMER (2u)

/* Derived internal parameters */
   #define INJHAL_SN_CM_66_TOUT_REG   (INJHAL_SN_CM_66_TOUT / 16u)
   #define INJHAL_SN_CM_66_TOUT_SEL   (INJHAL_SN_CM_66_TOUT - (INJHAL_SN_CM_66_TOUT_REG * 16u))

   #define INJHAL_SN_CM_45_TOUT      (72u)
   #define INJHAL_SN_CM_45_PORT      (&MODULE_P15)
   #define INJHAL_SN_CM_45_PIN       (1u)
   #define INJHAL_SN_CM_45_GTM_TIMER (2u)

/* Derived internal parameters */
   #define INJHAL_SN_CM_45_TOUT_REG   (INJHAL_SN_CM_45_TOUT / 16u)
   #define INJHAL_SN_CM_45_TOUT_SEL   (INJHAL_SN_CM_45_TOUT - (INJHAL_SN_CM_45_TOUT_REG * 16u))

   #define INJHAL_SN_CM_24_TOUT      (73u)
   #define INJHAL_SN_CM_24_PORT      (&MODULE_P15)
   #define INJHAL_SN_CM_24_PIN       (2u)
   #define INJHAL_SN_CM_24_GTM_TIMER (2u)

/* Derived internal parameters */
   #define INJHAL_SN_CM_24_TOUT_REG   (INJHAL_SN_CM_24_TOUT / 16u)
   #define INJHAL_SN_CM_24_TOUT_SEL   (INJHAL_SN_CM_24_TOUT - (INJHAL_SN_CM_24_TOUT_REG * 16u))



#define INJHAL_START_SEC_CODE
#include "INJHAL_MemMap.h"

uint32 INJHAL_vidCheckIntr(uint8 Injector);
void INJHAL_vidCoilToPinDisconnect(void);

#define INJHAL_STOP_SEC_CODE
#include "INJHAL_MemMap.h"

#endif /* INJHAL_GTM_CFG_H_ */

/*------------------------------- end of file --------------------------------*/
