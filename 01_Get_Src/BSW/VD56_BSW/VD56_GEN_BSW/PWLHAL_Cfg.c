/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : PWLHAL                                                  */
/* !Description     : Power Latch Hardware Abstraction Layer                  */
/*                                                                            */
/* !File            : PWLHAL_Cfg.c                                            */
/* !Description     : PWLHAL configuration                                    */
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
 * %PID: P2017_BSW:0A192542.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Dio.h"
#include "HBHAL_E.h"
#include "HOD.h"
#include "IGNHAL.h"
#include "INJHAL.h"
#include "PMPHAL.h"
#include "Pwm.h"
#include "PWLHAL_Cfg.h"
#include "THRHAL.h"
#include "TLE8718_Gateway.h"

#define PWLHAL_START_SEC_CODE
#include "PWLHAL_MemMap.h"

/******************************************************************************/
/* !FuncName    : PWLHAL_vidDisableActuators                                  */
/* !Description : This function is used to disable all the actuators linked   */
/*                to the actuator relay or main relay upon shutdown.          */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void PWLHAL_vidDisableActuators(void)
{

/* !Comment: Deactivation of Boost GDI */
   PMPHAL_vidDisable();
   INJHAL_vidDisable(GDI_1_TO_3);
   Dio_WriteChannel(DioConf_DioChannel_M_ASIC_GDI_RST, STD_OFF);

/* List of actuators linked to actuator relay */
   IGNHAL_vidCoilsDisable();
   HBHAL_vidDisable(CM_18_CM_19_L9960);

/* Disable all Pwm command output from transistors */
   Pwm_SetOutputToIdle(Pwm_17_GtmConf_PwmChannel_M_SPARE_OUT_LSD_1);
   Pwm_SetOutputToIdle(Pwm_17_GtmConf_PwmChannel_M_SPARE_OUT_LSD_2);
   Pwm_SetOutputToIdle(Pwm_17_GtmConf_PwmChannel_M_SPARE_OUT_LSD_3);
   Pwm_SetOutputToIdle(Pwm_17_GtmConf_PwmChannel_M_SPARE_OUT_LSD_4);
   Pwm_SetOutputToIdle(Pwm_17_GtmConf_PwmChannel_M_CTRL_THERMOSTAT_VALVE);

   Pwm_SetOutputToIdle(Pwm_17_GtmConf_PwmChannel_M_RC_MAIN_UPS_LBDA_SNS_1);
   Pwm_SetOutputToIdle(Pwm_17_GtmConf_PwmChannel_M_RC_MAIN_UPS_LBDA_SNS_2);
   Pwm_SetOutputToIdle(Pwm_17_GtmConf_PwmChannel_M_RC_MAIN_DWN_LBDA_SNS_1);
   Pwm_SetOutputToIdle(Pwm_17_GtmConf_PwmChannel_M_RC_MAIN_DWN_LBDA_SNS_2);

/* Disable all Dio command output from transistors */
   Dio_WriteChannel(DioConf_DioChannel_M_CABIN_HEATER_1, STD_OFF);
   Dio_WriteChannel(DioConf_DioChannel_M_CABIN_HEATER_2, STD_OFF);

/* Disable all outputs of TLE8718 */
   /* Set the Mode DIO for all TLE8718 outputs */
   TLE8718_vidSetMode(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_1, HOD_MODE_DIO);
   TLE8718_vidSetMode(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_2, HOD_MODE_DIO);
   TLE8718_vidSetMode(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_3, HOD_MODE_DIO);
   TLE8718_vidSetMode(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_4, HOD_MODE_DIO);
   TLE8718_vidSetMode(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_5, HOD_MODE_DIO);
   TLE8718_vidSetMode(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_6, HOD_MODE_DIO);
   TLE8718_vidSetMode(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_7, HOD_MODE_DIO);
   TLE8718_vidSetMode(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_8, HOD_MODE_DIO);
   TLE8718_vidSetMode(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_9, HOD_MODE_DIO);
   TLE8718_vidSetMode(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_10, HOD_MODE_DIO);
   /* OUT_11 is the power relay and so shall not be cut here */
   /*TLE8718_vidSetMode(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_11, HOD_MODE_DIO);*/
   TLE8718_vidSetMode(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_12, HOD_MODE_DIO);
   TLE8718_vidSetMode(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_13, HOD_MODE_DIO);
   TLE8718_vidSetMode(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_14, HOD_MODE_DIO);
   TLE8718_vidSetMode(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_15, HOD_MODE_DIO);
   TLE8718_vidSetMode(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_16, HOD_MODE_DIO);
   TLE8718_vidSetMode(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_17, HOD_MODE_DIO);
   TLE8718_vidSetMode(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_18, HOD_MODE_DIO);

   /* Apply Std_Off level on all TLE8718 outputs */
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_1, STD_OFF);
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_2, STD_OFF); 
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_3, STD_OFF); 
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_4, STD_OFF); 
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_5, STD_OFF); 
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_6, STD_OFF); 
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_7, STD_OFF); 
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_8, STD_OFF); 
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_9, STD_OFF); 
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_10, STD_OFF);
   /* OUT_11 is the power relay and so shall not be cut here */
   /*TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_11, STD_OFF);*/
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_12, STD_OFF);
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_13, STD_OFF);
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_14, STD_OFF);
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_15, STD_OFF);
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_16, STD_OFF);
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_17, STD_OFF);
   TLE8718_vidDioWrite(TLE8718_udtINSTANCE_1, TLE8718_udtOUT_18, STD_OFF);
}

#define PWLHAL_STOP_SEC_CODE
#include "PWLHAL_MemMap.h"

/*------------------------------- end of file --------------------------------*/
