/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : TLE8718                                                                                         */
/* !Description     : Driver for TLE8718 Device                                                                       */
/*                                                                                                                    */
/* !File            : TLE8718_Gateway.c                                                                               */
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
 * %PID: P2017_BSW:0A192591.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "Std_Types.h"
#include "TLE8718.h"

#define TLE8718_START_SEC_CODE
#include "TLE8718_MemMap.h"

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidSetDutyCycle_INST1                                                                       */
/* !Description : Function to Set Duty Cycle                                                                          */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidSetDutyCycle_INST1(uint8 u8Channel, uint16 u16DutyCycle)
{
   TLE8718_vidPwmWriteDutyCycle(TLE8718_udtINSTANCE_1, (HOD_tudtChannel)u8Channel, (HOD_tudtDutyCycle)u16DutyCycle);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidSetPerAndDuty_INST1                                                                      */
/* !Description : Function to Set Period ansd Duty Cycle                                                              */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidSetPerAndDuty_INST1(uint8 u8Channel, uint16 u16Period, uint16 u16DutyCycle)
{
   TLE8718_vidPwmWritePeriodAndDuty(TLE8718_udtINSTANCE_1,
                                    (HOD_tudtChannel)u8Channel,
                                    (HOD_tudtPeriod)u16Period,
                                    (HOD_tudtDutyCycle)u16DutyCycle);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidSetPwmOutToIdle_INST1                                                                    */
/* !Description : Function to Set Pwm Output in Idle State                                                            */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidSetPwmOutToIdle_INST1(uint8 u8Channel)
{
   TLE8718_vidPwmSetOutputToIdle(TLE8718_udtINSTANCE_1, (HOD_tudtChannel)u8Channel);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_bDioRead_INST1_OUT1                                                                         */
/* !Description : Function to Read TLE8718 Dio Channel                                                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
boolean TLE8718_bDioRead_INST1_OUT1(void)
{
   boolean bLocalDioState = TLE8718_bDioRead(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_1);
   return(bLocalDioState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDioWrite_INST1_OUT1                                                                      */
/* !Description : Function to Write TLE8718 Dio Channel                                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDioWrite_INST1_OUT1(boolean bState)
{
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_1, bState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_bDioRead_INST1_OUT2                                                                         */
/* !Description : Function to Read TLE8718 Dio Channel                                                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
boolean TLE8718_bDioRead_INST1_OUT2(void)
{
   boolean bLocalDioState = TLE8718_bDioRead(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_2);
   return(bLocalDioState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDioWrite_INST1_OUT2                                                                      */
/* !Description : Function to Write TLE8718 Dio Channel                                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDioWrite_INST1_OUT2(boolean bState)
{
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_2, bState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_bDioRead_INST1_OUT3                                                                         */
/* !Description : Function to Read TLE8718 Dio Channel                                                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
boolean TLE8718_bDioRead_INST1_OUT3(void)
{
   boolean bLocalDioState = TLE8718_bDioRead(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_3);
   return(bLocalDioState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDioWrite_INST1_OUT3                                                                      */
/* !Description : Function to Write TLE8718 Dio Channel                                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDioWrite_INST1_OUT3(boolean bState)
{
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_3, bState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_bDioRead_INST1_OUT4                                                                         */
/* !Description : Function to Read TLE8718 Dio Channel                                                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
boolean TLE8718_bDioRead_INST1_OUT4(void)
{
   boolean bLocalDioState = TLE8718_bDioRead(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_4);
   return(bLocalDioState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDioWrite_INST1_OUT4                                                                      */
/* !Description : Function to Write TLE8718 Dio Channel                                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDioWrite_INST1_OUT4(boolean bState)
{
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_4, bState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_bDioRead_INST1_OUT5                                                                         */
/* !Description : Function to Read TLE8718 Dio Channel                                                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
boolean TLE8718_bDioRead_INST1_OUT5(void)
{
   boolean bLocalDioState = TLE8718_bDioRead(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_5);
   return(bLocalDioState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDioWrite_INST1_OUT5                                                                      */
/* !Description : Function to Write TLE8718 Dio Channel                                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDioWrite_INST1_OUT5(boolean bState)
{
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_5, bState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_bDioRead_INST1_OUT6                                                                         */
/* !Description : Function to Read TLE8718 Dio Channel                                                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
boolean TLE8718_bDioRead_INST1_OUT6(void)
{
   boolean bLocalDioState = TLE8718_bDioRead(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_6);
   return(bLocalDioState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDioWrite_INST1_OUT6                                                                      */
/* !Description : Function to Write TLE8718 Dio Channel                                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDioWrite_INST1_OUT6(boolean bState)
{
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_6, bState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_bDioRead_INST1_OUT7                                                                         */
/* !Description : Function to Read TLE8718 Dio Channel                                                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
boolean TLE8718_bDioRead_INST1_OUT7(void)
{
   boolean bLocalDioState = TLE8718_bDioRead(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_7);
   return(bLocalDioState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDioWrite_INST1_OUT7                                                                      */
/* !Description : Function to Write TLE8718 Dio Channel                                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDioWrite_INST1_OUT7(boolean bState)
{
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_7, bState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_bDioRead_INST1_OUT8                                                                         */
/* !Description : Function to Read TLE8718 Dio Channel                                                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
boolean TLE8718_bDioRead_INST1_OUT8(void)
{
   boolean bLocalDioState = TLE8718_bDioRead(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_8);
   return(bLocalDioState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDioWrite_INST1_OUT8                                                                      */
/* !Description : Function to Write TLE8718 Dio Channel                                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDioWrite_INST1_OUT8(boolean bState)
{
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_8, bState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_bDioRead_INST1_OUT9                                                                         */
/* !Description : Function to Read TLE8718 Dio Channel                                                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
boolean TLE8718_bDioRead_INST1_OUT9(void)
{
   boolean bLocalDioState = TLE8718_bDioRead(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_9);
   return(bLocalDioState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDioWrite_INST1_OUT9                                                                      */
/* !Description : Function to Write TLE8718 Dio Channel                                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDioWrite_INST1_OUT9(boolean bState)
{
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_9, bState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_bDioRead_INST1_OUT10                                                                        */
/* !Description : Function to Read TLE8718 Dio Channel                                                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
boolean TLE8718_bDioRead_INST1_OUT10(void)
{
   boolean bLocalDioState = TLE8718_bDioRead(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_10);
   return(bLocalDioState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDioWrite_INST1_OUT10                                                                     */
/* !Description : Function to Write TLE8718 Dio Channel                                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDioWrite_INST1_OUT10(boolean bState)
{
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_10, bState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_bDioRead_INST1_OUT11                                                                        */
/* !Description : Function to Read TLE8718 Dio Channel                                                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
boolean TLE8718_bDioRead_INST1_OUT11(void)
{
   boolean bLocalDioState = TLE8718_bDioRead(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_11);
   return(bLocalDioState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDioWrite_INST1_OUT11                                                                     */
/* !Description : Function to Write TLE8718 Dio Channel                                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDioWrite_INST1_OUT11(boolean bState)
{
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_11, bState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_bDioRead_INST1_OUT12                                                                        */
/* !Description : Function to Read TLE8718 Dio Channel                                                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
boolean TLE8718_bDioRead_INST1_OUT12(void)
{
   boolean bLocalDioState = TLE8718_bDioRead(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_12);
   return(bLocalDioState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDioWrite_INST1_OUT12                                                                     */
/* !Description : Function to Write TLE8718 Dio Channel                                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDioWrite_INST1_OUT12(boolean bState)
{
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_12, bState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_bDioRead_INST1_OUT13                                                                        */
/* !Description : Function to Read TLE8718 Dio Channel                                                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
boolean TLE8718_bDioRead_INST1_OUT13(void)
{
   boolean bLocalDioState = TLE8718_bDioRead(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_13);
   return(bLocalDioState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDioWrite_INST1_OUT13                                                                     */
/* !Description : Function to Write TLE8718 Dio Channel                                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDioWrite_INST1_OUT13(boolean bState)
{
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_13, bState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_bDioRead_INST1_OUT14                                                                        */
/* !Description : Function to Read TLE8718 Dio Channel                                                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
boolean TLE8718_bDioRead_INST1_OUT14(void)
{
   boolean bLocalDioState = TLE8718_bDioRead(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_14);
   return(bLocalDioState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDioWrite_INST1_OUT14                                                                     */
/* !Description : Function to Write TLE8718 Dio Channel                                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDioWrite_INST1_OUT14(boolean bState)
{
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_14, bState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_bDioRead_INST1_OUT15                                                                        */
/* !Description : Function to Read TLE8718 Dio Channel                                                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
boolean TLE8718_bDioRead_INST1_OUT15(void)
{
   boolean bLocalDioState = TLE8718_bDioRead(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_15);
   return(bLocalDioState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDioWrite_INST1_OUT15                                                                     */
/* !Description : Function to Write TLE8718 Dio Channel                                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDioWrite_INST1_OUT15(boolean bState)
{
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_15, bState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_bDioRead_INST1_OUT16                                                                        */
/* !Description : Function to Read TLE8718 Dio Channel                                                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
boolean TLE8718_bDioRead_INST1_OUT16(void)
{
   boolean bLocalDioState = TLE8718_bDioRead(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_16);
   return(bLocalDioState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDioWrite_INST1_OUT16                                                                     */
/* !Description : Function to Write TLE8718 Dio Channel                                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDioWrite_INST1_OUT16(boolean bState)
{
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_16, bState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_bDioRead_INST1_OUT17                                                                        */
/* !Description : Function to Read TLE8718 Dio Channel                                                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
boolean TLE8718_bDioRead_INST1_OUT17(void)
{
   boolean bLocalDioState = TLE8718_bDioRead(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_17);
   return(bLocalDioState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDioWrite_INST1_OUT17                                                                     */
/* !Description : Function to Write TLE8718 Dio Channel                                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDioWrite_INST1_OUT17(boolean bState)
{
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_17, bState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_bDioRead_INST1_OUT18                                                                        */
/* !Description : Function to Read TLE8718 Dio Channel                                                                */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
boolean TLE8718_bDioRead_INST1_OUT18(void)
{
   boolean bLocalDioState = TLE8718_bDioRead(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_18);
   return(bLocalDioState);
}

/**********************************************************************************************************************/
/* !FuncName    : TLE8718_vidDioWrite_INST1_OUT18                                                                     */
/* !Description : Function to Write TLE8718 Dio Channel                                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void TLE8718_vidDioWrite_INST1_OUT18(boolean bState)
{
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_18, bState);
}

#define TLE8718_STOP_SEC_CODE
#include "TLE8718_MemMap.h"

/*--------------------------------------------------- END OF FILE ----------------------------------------------------*/
