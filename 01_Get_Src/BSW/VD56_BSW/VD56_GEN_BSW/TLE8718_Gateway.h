/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : TLE8718                                                                                         */
/* !Description     : Driver for TLE8718 Device                                                                       */
/*                                                                                                                    */
/* !File            : TLE8718_Gateway.h                                                                               */
/* !Description     : Gateway of TLE8718 Component                                                                    */
/*                                                                                                                    */
/* !Reference       :                                                                                                 */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A192518.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#ifndef TLE8718_GATEWAY_H
#define TLE8718_GATEWAY_H

#include "Std_Types.h"
#include "TLE8718.h"

#define TLE8718_START_SEC_CODE
#include "TLE8718_MemMap.h"

/* Gateway for PWM */
extern void TLE8718_vidSetDutyCycle_INST1(uint8 u8Channel, uint16 u16DutyCycle);
extern void TLE8718_vidSetPerAndDuty_INST1(uint8 u8Channel, uint16 u16Period, uint16 u16DutyCycle);
extern void TLE8718_vidSetPwmOutToIdle_INST1(uint8 u8Channel);

/* Gateway for DIO */
extern boolean TLE8718_bDioRead_INST1_OUT1(void);
extern void    TLE8718_vidDioWrite_INST1_OUT1(boolean bState);
extern boolean TLE8718_bDioRead_INST1_OUT2(void);
extern void    TLE8718_vidDioWrite_INST1_OUT2(boolean bState);
extern boolean TLE8718_bDioRead_INST1_OUT3(void);
extern void    TLE8718_vidDioWrite_INST1_OUT3(boolean bState);
extern boolean TLE8718_bDioRead_INST1_OUT4(void);
extern void    TLE8718_vidDioWrite_INST1_OUT4(boolean bState);
extern boolean TLE8718_bDioRead_INST1_OUT5(void);
extern void    TLE8718_vidDioWrite_INST1_OUT5(boolean bState);
extern boolean TLE8718_bDioRead_INST1_OUT6(void);
extern void    TLE8718_vidDioWrite_INST1_OUT6(boolean bState);
extern boolean TLE8718_bDioRead_INST1_OUT7(void);
extern void    TLE8718_vidDioWrite_INST1_OUT7(boolean bState);
extern boolean TLE8718_bDioRead_INST1_OUT8(void);
extern void    TLE8718_vidDioWrite_INST1_OUT8(boolean bState);
extern boolean TLE8718_bDioRead_INST1_OUT9(void);
extern void    TLE8718_vidDioWrite_INST1_OUT9(boolean bState);
extern boolean TLE8718_bDioRead_INST1_OUT10(void);
extern void    TLE8718_vidDioWrite_INST1_OUT10(boolean bState);
extern boolean TLE8718_bDioRead_INST1_OUT11(void);
extern void    TLE8718_vidDioWrite_INST1_OUT11(boolean bState);
extern boolean TLE8718_bDioRead_INST1_OUT12(void);
extern void    TLE8718_vidDioWrite_INST1_OUT12(boolean bState);
extern boolean TLE8718_bDioRead_INST1_OUT13(void);
extern void    TLE8718_vidDioWrite_INST1_OUT13(boolean bState);
extern boolean TLE8718_bDioRead_INST1_OUT14(void);
extern void    TLE8718_vidDioWrite_INST1_OUT14(boolean bState);
extern boolean TLE8718_bDioRead_INST1_OUT15(void);
extern void    TLE8718_vidDioWrite_INST1_OUT15(boolean bState);
extern boolean TLE8718_bDioRead_INST1_OUT16(void);
extern void    TLE8718_vidDioWrite_INST1_OUT16(boolean bState);
extern boolean TLE8718_bDioRead_INST1_OUT17(void);
extern void    TLE8718_vidDioWrite_INST1_OUT17(boolean bState);
extern boolean TLE8718_bDioRead_INST1_OUT18(void);
extern void    TLE8718_vidDioWrite_INST1_OUT18(boolean bState);

#define TLE8718_STOP_SEC_CODE
#include "TLE8718_MemMap.h"

#endif /* TLE8718_GATEWAY_H */

/*--------------------------------------------------- END OF FILE ----------------------------------------------------*/
