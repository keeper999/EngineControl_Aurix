/************************************************* <AUTO_FILE_HEADER> *************************************************/
/*                                                                                                                    */
/* !Layer           : HAL                                                                                             */
/*                                                                                                                    */
/* !Component       : PWMHAL                                                                                          */
/* !Description     : Pulse Width Modulation Hardware Abstraction Layer.                                              */
/*                                                                                                                    */
/* !Module          : PWMHAL                                                                                          */
/* !Description     : Pulse Width Modulation Hardware Abstraction Layer.                                              */
/*                                                                                                                    */
/* !File            : PWMHAL_Types.h                                                                                  */
/*                                                                                                                    */
/* !Scope           : Public                                                                                          */
/*                                                                                                                    */
/* !Target          : All                                                                                             */
/*                                                                                                                    */
/* !Vendor          : Valeo                                                                                           */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO                                                                                                    */
/* all rights reserved                                                                                                */
/*                                                                                                                    */
/**********************************************************************************************************************/
/**********************************************************************************************************************/
/************************************************ </AUTO_FILE_HEADER> *************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: LIBEMB:A384.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/
/* !VnrOff  : Names imposed by the customer                                                                           */
/**********************************************************************************************************************/

#ifndef PWMHAL_TYPES_H
#define PWMHAL_TYPES_H

#include "Std_Types.h"
#include "PWMHAL_Co.h"



#ifndef PWMHAL_coHOD_CHANNEL_EXIST
   #error "Define PWMHAL_coHOD_CHANNEL_EXIST is undefined"
#endif

#ifndef PWMHAL_coSPECIFIC_CHANNEL_EXIST
   #error "Define PWMHAL_coSPECIFIC_CHANNEL_EXIST is undefined"
#endif

#ifndef PWMHAL_coYES
   #error "Define PWMHAL_coYES is undefined"
#endif

#if  PWMHAL_coHOD_CHANNEL_EXIST == PWMHAL_coYES
   #include "HOD.h"
#endif

typedef uint8 PWMHAL_tudtChannel;
typedef uint16 PWMHAL_tudtDutyCycle;
typedef uint16 PWMHAL_tudtFrequency;

#if  PWMHAL_coHOD_CHANNEL_EXIST == PWMHAL_coYES
typedef void (*PWMHAL_tkpfvidHodWrPeriodDuty)(HOD_tudtInstance  udtInstance,
                                              HOD_tudtChannel   udtChannel,
                                              HOD_tudtPeriod    udtPeriod,
                                              HOD_tudtDutycycle udtDutyCycle);
typedef void (*PWMHAL_tkpfvidHodWrDuty)(HOD_tudtInstance  udtInstance,
                                        HOD_tudtChannel   udtChannel,
                                        HOD_tudtDutycycle udtDutyCycle);
typedef void (*PWMHAL_tkpfvidHodSetOutputToIdle)(HOD_tudtInstance udtInstance, HOD_tudtChannel  udtChannel);
#endif

#if  PWMHAL_coSPECIFIC_CHANNEL_EXIST == PWMHAL_coYES
typedef void (*PWMHAL_tkpfvidSpecificWrPeriodDuty)(uint8 u8Channel, uint16 u16Period, uint16 u16DutyCycle);
typedef void (*PWMHAL_tkpfvidSpecificWrDuty)(uint8 u8Channel, uint16 u16DutyCycle);
typedef void (*PWMHAL_tkpfvidSpecificSetOutputToIdle)(uint8 u8Channel);
#endif

typedef struct
{
   #if  PWMHAL_coHOD_CHANNEL_EXIST == PWMHAL_coYES
   PWMHAL_tkpfvidHodWrPeriodDuty       kpfvidHodWrPeriodDuty;
   PWMHAL_tkpfvidHodWrDuty             kpfvidHodWrDuty;
   PWMHAL_tkpfvidHodSetOutputToIdle    kpfvidHodSetOutputToIdle;
   #endif
   #if PWMHAL_coSPECIFIC_CHANNEL_EXIST == PWMHAL_coYES
   PWMHAL_tkpfvidSpecificWrPeriodDuty        kpfvidSpecificWrPeriodDuty;
   PWMHAL_tkpfvidSpecificWrDuty              kpfvidSpecificWrDuty;
   PWMHAL_tkpfvidSpecificSetOutputToIdle     kpfvidSpecificSetOutputToIdle;
   #endif
   uint32                u32FreqToPer;
   PWMHAL_tudtFrequency  udtMinFreq;
   uint16                u16ChannelId;
   uint8                 u8LinkType;
} PWMHAL_tstrConfig;


#endif /* PWMHAL_TYPES_H */

/*---------------------------------------------------- end of file ---------------------------------------------------*/
