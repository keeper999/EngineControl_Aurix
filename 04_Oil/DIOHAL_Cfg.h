/************************************************* <AUTO_FILE_HEADER> *************************************************/
/*                                                                                                                    */
/* !Layer           : HAL                                                                                             */
/*                                                                                                                    */
/* !Component       : DIOHAL                                                                                          */
/* !Description     : Allows access to the logical input/output of the ECU.                                           */
/*                                                                                                                    */
/* !Module          : DIOHAL                                                                                          */
/* !Description     : DIOHAL Configuration                                                                            */
/*                                                                                                                    */
/* !File            : DIOHAL_CFG.h                                                                                    */
/*                                                                                                                    */
/* !Scope           : Private Component                                                                               */
/*                                                                                                                    */
/* !Target          : ALL                                                                                             */
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
 * %PID: LIBEMB:A736.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/
/* !VnrOff  : Names imposed by the customer                                                                           */
/**********************************************************************************************************************/

#ifndef DIOHAL_CFG_H
#define DIOHAL_CFG_H

#include "STD_Types.h"

#include "Dio.h"
#include "LBHOT.h"
#include "PWLHAL.h"
#include "TLE8718_Gateway.h"


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* !MComment: Application software function                                   */
/* !Range   : Valid ECU pin                                                   */
#define CH_DIO_IN_IGNK       CH_52
#define CH_DIO_IN_DIAG_GMV       CH_47
#define CH_DIO_IN_KEY_PUSH_INFO_ACQ       CH_34
#define CH_DIO_IN_STARTLOCK_ACQ       CH_19
#define CH_DIO_IN_CLU_PDL_ACQ       CH_19
#define MAIN_RELAY       CH_62
#define CH_DIO_OUT_ACTR_RELAY_CMD       CH_61
#define CH_DIO_OUT_ENGST_OUTPUT       CH_69
#define CH_DIO_OUT_DML_RELAY       CH_68
#define CH_DIO_OUT_STT       CH_50
#define CH_DIO_OUT_DMTR       CH_67
#define CH_DIO_OUT_BLOW_BY_1       CM_106
#define CH_DIO_OUT_SO2_HEAT_UP       CM_103
#define CH_DIO_OUT_SO2_HEAT_DOWN       CM_84
#define CH_DIO_OUT_GMV_1       CH_63
#define CH_DIO_OUT_GMV_2       CH_64
#define CH_DIO_IN_OIL_PRES_ACQ       CH_22
#define CH_DIO_IN_BRK_PDL_ACQ       CH_56
#define CH_DIO_OUT_CTP_1       CH_65
#define CH_DIO_OUT_CTP_2       CH_66


#define DIOHAL_snCH_16_AUTOSAR_CHANNEL      DioConf_DioChannel_M_VEHICLE_SPD_INFO
#define DIOHAL_snCH_19_AUTOSAR_CHANNEL      DioConf_DioChannel_M_CLUTCH_PED_POS_OR_STARTLOCK
#define DIOHAL_snCH_20_AUTOSAR_CHANNEL      DioConf_DioChannel_M_INPUT_DIGITAL_SPARE_1
#define DIOHAL_snCH_21_AUTOSAR_CHANNEL      DioConf_DioChannel_M_LOW_PRES_FUEL_PUMP_VAR_INPUT
#define DIOHAL_snCH_25_AUTOSAR_CHANNEL      DioConf_DioChannel_M_MANUAL_GEARBOX_NEUTRAL_POS
#define DIOHAL_snCH_34_AUTOSAR_CHANNEL      DioConf_DioChannel_M_PUSH_ADML
#define DIOHAL_snCH_36_AUTOSAR_CHANNEL      DioConf_DioChannel_M_ETHANOL_RATE_FLEXFUEL
#define DIOHAL_snCH_38_AUTOSAR_CHANNEL      DioConf_DioChannel_M_STARTER_CMD_DIAG_INPUT
#define DIOHAL_snCH_47_AUTOSAR_CHANNEL      DioConf_DioChannel_M_FAN1_DIAG_INPUT
#define DIOHAL_snCH_48_AUTOSAR_CHANNEL      DioConf_DioChannel_M_INPUT_DIGITAL_SPARE_2
#define DIOHAL_snCH_52_AUTOSAR_CHANNEL      DioConf_DioChannel_M_STARTUP_IGK
#define DIOHAL_snCH_56_AUTOSAR_CHANNEL      DioConf_DioChannel_M_SEC_BRK_PED_SWITCH
#define DIOHAL_snCH_59_AUTOSAR_CHANNEL      DioConf_DioChannel_M_INPUT_DIGITAL_SPARE_3
#define DIOHAL_snCM_10_AUTOSAR_CHANNEL      DioConf_DioChannel_M_TURBO_ENG_COOL_WAT_PUMP_DIAG
#define DIOHAL_snCM_27_AUTOSAR_CHANNEL      DioConf_DioChannel_M_INPUT_DIGITAL_SPARE_4
#define DIOHAL_snCM_28_AUTOSAR_CHANNEL      DioConf_DioChannel_M_INPUT_DIGITAL_SPARE_5


/* !MComment: The port index of the array defined in DIOHAL_vidGET_SAMPLE     */
/* !Range   : 0 .. DIOHAL_u8FILTERED_PORTS_NBR-1                              */
#define DIOHAL_u8INDEX_OF_DIO_PORT_1                0
#define DIOHAL_u8INDEX_OF_DIO_PORT_33                1
#define DIOHAL_u8INDEX_OF_DIO_PORT_0                2
#define DIOHAL_u8INDEX_OF_DIO_PORT_10                3
#define DIOHAL_u8INDEX_OF_DIO_PORT_2                4
#define DIOHAL_u8INDEX_OF_DIO_PORT_32                5
#define DIOHAL_u8INDEX_OF_DIO_PORT_11                6



/* !MComment: The index of the array defined in DIOHAL_vidGET_SAMPLE
              (Filter Table); equivalent to the port containing the Autosar channel
              DIOHAL_snX_AUTOSAR_CHANNEL;
              where X=X in DIOHAL_u8READ_VECTOR_INDEX_X.
              It is used in filtered READ functions.                          */
/* !Range   : 0 .. DIOHAL_u8FILTERED_PORTS_NBR-1                              */
#define DIOHAL_u8FILTER_VEC_INDX_CH_16    DIOHAL_u8INDEX_OF_DIO_PORT_1
#define DIOHAL_u8FILTER_VEC_INDX_CH_19    DIOHAL_u8INDEX_OF_DIO_PORT_33
#define DIOHAL_u8FILTER_VEC_INDX_CH_20    DIOHAL_u8INDEX_OF_DIO_PORT_0
#define DIOHAL_u8FILTER_VEC_INDX_CH_21    DIOHAL_u8INDEX_OF_DIO_PORT_10
#define DIOHAL_u8FILTER_VEC_INDX_CH_25    DIOHAL_u8INDEX_OF_DIO_PORT_2
#define DIOHAL_u8FILTER_VEC_INDX_CH_34    DIOHAL_u8INDEX_OF_DIO_PORT_32
#define DIOHAL_u8FILTER_VEC_INDX_CH_36    DIOHAL_u8INDEX_OF_DIO_PORT_1
#define DIOHAL_u8FILTER_VEC_INDX_CH_38    DIOHAL_u8INDEX_OF_DIO_PORT_33
#define DIOHAL_u8FILTER_VEC_INDX_CH_47    DIOHAL_u8INDEX_OF_DIO_PORT_11
#define DIOHAL_u8FILTER_VEC_INDX_CH_48    DIOHAL_u8INDEX_OF_DIO_PORT_0
#define DIOHAL_u8FILTER_VEC_INDX_CH_52    DIOHAL_u8INDEX_OF_DIO_PORT_0
#define DIOHAL_u8FILTER_VEC_INDX_CH_56    DIOHAL_u8INDEX_OF_DIO_PORT_1
#define DIOHAL_u8FILTER_VEC_INDX_CH_59    DIOHAL_u8INDEX_OF_DIO_PORT_33
#define DIOHAL_u8FILTER_VEC_INDX_CM_10    DIOHAL_u8INDEX_OF_DIO_PORT_1
#define DIOHAL_u8FILTER_VEC_INDX_CM_27    DIOHAL_u8INDEX_OF_DIO_PORT_1
#define DIOHAL_u8FILTER_VEC_INDX_CM_28    DIOHAL_u8INDEX_OF_DIO_PORT_33


/* !MComment: The bit number represents the equivalent BSL channel in its PORT*/
#define DIOHAL_u8READ_BIT_NBR_CH_16    5
#define DIOHAL_u8READ_BIT_NBR_CH_19    0
#define DIOHAL_u8READ_BIT_NBR_CH_20    3
#define DIOHAL_u8READ_BIT_NBR_CH_21    7
#define DIOHAL_u8READ_BIT_NBR_CH_25    11
#define DIOHAL_u8READ_BIT_NBR_CH_34    7
#define DIOHAL_u8READ_BIT_NBR_CH_36    6
#define DIOHAL_u8READ_BIT_NBR_CH_38    5
#define DIOHAL_u8READ_BIT_NBR_CH_47    7
#define DIOHAL_u8READ_BIT_NBR_CH_48    5
#define DIOHAL_u8READ_BIT_NBR_CH_52    8
#define DIOHAL_u8READ_BIT_NBR_CH_56    3
#define DIOHAL_u8READ_BIT_NBR_CH_59    1
#define DIOHAL_u8READ_BIT_NBR_CM_10    7
#define DIOHAL_u8READ_BIT_NBR_CM_27    4
#define DIOHAL_u8READ_BIT_NBR_CM_28    15


/* !Comment: Number of channels supporting READ or READRAW operations, i.e.
             array of pointers to functions size                              */
/* !Range  : 0 .. 127 (Max number of pins in the ECU                          */
#define DIOHAL_u8READ_TABLE_SIZE  30

/* !Comment: Number of channels supporting WRITE operation, i.e. array of
             pointers to functions size                                       */
/* !Range  : 0 .. 127 (Max number of pins in the ECU                          */
#define DIOHAL_u8WRITE_TABLE_SIZE  14


/* !MComment: Index for the ECU channels, It should be sortined the order as
              in DIOHAL_akpfbReadRaw, DIOHAL_akpfbRead, and DIOHAL_akpfvidWrite.
              Putting the OUTPUT ports first                                  */
#define CH_68    0
#define CM_106    1
#define CH_22    2
#define CH_61    3
#define CH_63    4
#define CH_64    5
#define CH_50    6
#define CH_69    7
#define CH_67    8
#define CH_65    9
#define CH_66    10
#define CH_62    11
#define CM_103    12
#define CM_84    13
#define CH_16    14
#define CH_19    15
#define CH_20    16
#define CH_21    17
#define CH_25    18
#define CH_34    19
#define CH_36    20
#define CH_38    21
#define CH_47    22
#define CH_48    23
#define CH_52    24
#define CH_56    25
#define CH_59    26
#define CM_10    27
#define CM_27    28
#define CM_28    29


/******************************************************************************/
/* Filter related configurations                                              */
/******************************************************************************/

/* !Parameter: Number of samples in the low frequency filter.                 */
#define DIOHAL_u8LOW_FREQ_SAMPLE_NBR   3

/* !Parameter: Number of samples in the high frequency filter.                */
#define DIOHAL_u8HIGH_FREQ_SAMPLE_NBR  3

/* !Parameter: Number of ports required to be filtered                        */
#define DIOHAL_u8FILTERED_PORTS_NBR    7


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/* !Description: This is a configuration function, it gets a sample of all    */
/*               filtered input channels                                      */
/*                                                                            */
/* !LastAuthor : AISL (VIAS)                                                  */
/******************************************************************************/
#define DIOHAL_vidGET_SAMPLE( \
   au16Array \
) \
   M1_DIOHAL_vidGET_SAMPLE(au16Array)   /* !Comment: au16Array: raw samples vector                                    */

   /* internal macro */

   #define M1_DIOHAL_vidGET_SAMPLE(au16Array) \
   do \
   { \
      au16Array[DIOHAL_u8INDEX_OF_DIO_PORT_1  ] = Dio_ReadPort(DIO_PORT_1); \
      au16Array[DIOHAL_u8INDEX_OF_DIO_PORT_33  ] = Dio_ReadPort(DIO_PORT_33); \
      au16Array[DIOHAL_u8INDEX_OF_DIO_PORT_0  ] = Dio_ReadPort(DIO_PORT_0); \
      au16Array[DIOHAL_u8INDEX_OF_DIO_PORT_10  ] = Dio_ReadPort(DIO_PORT_10); \
      au16Array[DIOHAL_u8INDEX_OF_DIO_PORT_2  ] = Dio_ReadPort(DIO_PORT_2); \
      au16Array[DIOHAL_u8INDEX_OF_DIO_PORT_32  ] = Dio_ReadPort(DIO_PORT_32); \
      au16Array[DIOHAL_u8INDEX_OF_DIO_PORT_11  ] = Dio_ReadPort(DIO_PORT_11); \
   } \
   while (0)

/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/
#define DIOHAL_START_SEC_CODE
#include "DIOHAL_MemMap.h"

/******************************************************************************/
/* Supported Read, Write, ReadRaw functions for different ECU pins            */
/******************************************************************************/
extern boolean DIOHAL_bReadRaw_CH_65(void);
extern boolean DIOHAL_bReadRaw_CH_66(void);
extern boolean DIOHAL_bReadRaw_CH_16(void);
extern boolean DIOHAL_bReadRaw_CH_19(void);
extern boolean DIOHAL_bReadRaw_CH_20(void);
extern boolean DIOHAL_bReadRaw_CH_21(void);
extern boolean DIOHAL_bReadRaw_CH_25(void);
extern boolean DIOHAL_bReadRaw_CH_34(void);
extern boolean DIOHAL_bReadRaw_CH_36(void);
extern boolean DIOHAL_bReadRaw_CH_38(void);
extern boolean DIOHAL_bReadRaw_CH_47(void);
extern boolean DIOHAL_bReadRaw_CH_48(void);
extern boolean DIOHAL_bReadRaw_CH_52(void);
extern boolean DIOHAL_bReadRaw_CH_56(void);
extern boolean DIOHAL_bReadRaw_CH_59(void);
extern boolean DIOHAL_bReadRaw_CM_10(void);
extern boolean DIOHAL_bReadRaw_CM_27(void);
extern boolean DIOHAL_bReadRaw_CM_28(void);
extern boolean DIOHAL_bRead_CH_16(void);
extern boolean DIOHAL_bRead_CH_19(void);
extern boolean DIOHAL_bRead_CH_20(void);
extern boolean DIOHAL_bRead_CH_21(void);
extern boolean DIOHAL_bRead_CH_25(void);
extern boolean DIOHAL_bRead_CH_34(void);
extern boolean DIOHAL_bRead_CH_36(void);
extern boolean DIOHAL_bRead_CH_38(void);
extern boolean DIOHAL_bRead_CH_47(void);
extern boolean DIOHAL_bRead_CH_48(void);
extern boolean DIOHAL_bRead_CH_52(void);
extern boolean DIOHAL_bRead_CH_56(void);
extern boolean DIOHAL_bRead_CH_59(void);
extern boolean DIOHAL_bRead_CM_10(void);
extern boolean DIOHAL_bRead_CM_27(void);
extern boolean DIOHAL_bRead_CM_28(void);
extern void    DIOHAL_vidWrite_CH_65(boolean bState);
extern void    DIOHAL_vidWrite_CH_66(boolean bState);



#define DIOHAL_STOP_SEC_CODE
#include "DIOHAL_MemMap.h"


#endif  /* DIOHAL_CFG_H */

/*---------------------------------------------------- end of file ---------------------------------------------------*/

