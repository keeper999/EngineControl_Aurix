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
/* !File            : DIOHAL_CFG.C                                                                                    */
/*                                                                                                                    */
/* !Scope           : Public                                                                                          */
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
 * %PID: LIBEMB:A735.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/
/* !VnrOff  : Names imposed by the customer                                                                           */
/**********************************************************************************************************************/
#include "DIOHAL.h"
#include "DIOHAL_Def.h"
#include "DIOHAL_CFG.h"
#include "HOD.h"
#define DIOHAL_START_SEC_CODE
#include "DIOHAL_MemMap.h"

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/


/******************************************************************************/
/*                                                                            */
/* !Description: Read without filtering from the o/p ECU pin (CH_16)    */
/*                                                                            */
/******************************************************************************/
/* !Comment: Raw input                                                        */
boolean DIOHAL_bReadRaw_CH_16 (void)
{
   return ((boolean)Dio_ReadChannel(DIOHAL_snCH_16_AUTOSAR_CHANNEL ));
}

/******************************************************************************/
/*                                                                            */
/* !Description: Read without filtering from the o/p ECU pin (CH_19)    */
/*                                                                            */
/******************************************************************************/
/* !Comment: Raw input                                                        */
boolean DIOHAL_bReadRaw_CH_19 (void)
{
   return ((boolean)Dio_ReadChannel(DIOHAL_snCH_19_AUTOSAR_CHANNEL ));
}

/******************************************************************************/
/*                                                                            */
/* !Description: Read without filtering from the o/p ECU pin (CH_20)    */
/*                                                                            */
/******************************************************************************/
/* !Comment: Raw input                                                        */
boolean DIOHAL_bReadRaw_CH_20 (void)
{
   return ((boolean)Dio_ReadChannel(DIOHAL_snCH_20_AUTOSAR_CHANNEL ));
}

/******************************************************************************/
/*                                                                            */
/* !Description: Read without filtering from the o/p ECU pin (CH_21)    */
/*                                                                            */
/******************************************************************************/
/* !Comment: Raw input                                                        */
boolean DIOHAL_bReadRaw_CH_21 (void)
{
   return ((boolean)Dio_ReadChannel(DIOHAL_snCH_21_AUTOSAR_CHANNEL ));
}

/******************************************************************************/
/*                                                                            */
/* !Description: Read without filtering from the o/p ECU pin (CH_25)    */
/*                                                                            */
/******************************************************************************/
/* !Comment: Raw input                                                        */
boolean DIOHAL_bReadRaw_CH_25 (void)
{
   return ((boolean)Dio_ReadChannel(DIOHAL_snCH_25_AUTOSAR_CHANNEL ));
}

/******************************************************************************/
/*                                                                            */
/* !Description: Read without filtering from the o/p ECU pin (CH_34)    */
/*                                                                            */
/******************************************************************************/
/* !Comment: Raw input                                                        */
boolean DIOHAL_bReadRaw_CH_34 (void)
{
   return ((boolean)Dio_ReadChannel(DIOHAL_snCH_34_AUTOSAR_CHANNEL ));
}

/******************************************************************************/
/*                                                                            */
/* !Description: Read without filtering from the o/p ECU pin (CH_36)    */
/*                                                                            */
/******************************************************************************/
/* !Comment: Raw input                                                        */
boolean DIOHAL_bReadRaw_CH_36 (void)
{
   return ((boolean)Dio_ReadChannel(DIOHAL_snCH_36_AUTOSAR_CHANNEL ));
}

/******************************************************************************/
/*                                                                            */
/* !Description: Read without filtering from the o/p ECU pin (CH_38)    */
/*                                                                            */
/******************************************************************************/
/* !Comment: Raw input                                                        */
boolean DIOHAL_bReadRaw_CH_38 (void)
{
   return ((boolean)Dio_ReadChannel(DIOHAL_snCH_38_AUTOSAR_CHANNEL ));
}

/******************************************************************************/
/*                                                                            */
/* !Description: Read without filtering from the o/p ECU pin (CH_47)    */
/*                                                                            */
/******************************************************************************/
/* !Comment: Raw input                                                        */
boolean DIOHAL_bReadRaw_CH_47 (void)
{
   return ((boolean)Dio_ReadChannel(DIOHAL_snCH_47_AUTOSAR_CHANNEL ));
}

/******************************************************************************/
/*                                                                            */
/* !Description: Read without filtering from the o/p ECU pin (CH_48)    */
/*                                                                            */
/******************************************************************************/
/* !Comment: Raw input                                                        */
boolean DIOHAL_bReadRaw_CH_48 (void)
{
   return ((boolean)Dio_ReadChannel(DIOHAL_snCH_48_AUTOSAR_CHANNEL ));
}

/******************************************************************************/
/*                                                                            */
/* !Description: Read without filtering from the o/p ECU pin (CH_52)    */
/*                                                                            */
/******************************************************************************/
/* !Comment: Raw input                                                        */
boolean DIOHAL_bReadRaw_CH_52 (void)
{
   return ((boolean)Dio_ReadChannel(DIOHAL_snCH_52_AUTOSAR_CHANNEL ));
}

/******************************************************************************/
/*                                                                            */
/* !Description: Read without filtering from the o/p ECU pin (CH_56)    */
/*                                                                            */
/******************************************************************************/
/* !Comment: Raw input                                                        */
boolean DIOHAL_bReadRaw_CH_56 (void)
{
   return ((boolean)Dio_ReadChannel(DIOHAL_snCH_56_AUTOSAR_CHANNEL ));
}

/******************************************************************************/
/*                                                                            */
/* !Description: Read without filtering from the o/p ECU pin (CH_59)    */
/*                                                                            */
/******************************************************************************/
/* !Comment: Raw input                                                        */
boolean DIOHAL_bReadRaw_CH_59 (void)
{
   return ((boolean)Dio_ReadChannel(DIOHAL_snCH_59_AUTOSAR_CHANNEL ));
}

/******************************************************************************/
/*                                                                            */
/* !Description: Read without filtering from the o/p ECU pin (CM_10)    */
/*                                                                            */
/******************************************************************************/
/* !Comment: Raw input                                                        */
boolean DIOHAL_bReadRaw_CM_10 (void)
{
   return ((boolean)Dio_ReadChannel(DIOHAL_snCM_10_AUTOSAR_CHANNEL ));
}

/******************************************************************************/
/*                                                                            */
/* !Description: Read without filtering from the o/p ECU pin (CM_27)    */
/*                                                                            */
/******************************************************************************/
/* !Comment: Raw input                                                        */
boolean DIOHAL_bReadRaw_CM_27 (void)
{
   return ((boolean)Dio_ReadChannel(DIOHAL_snCM_27_AUTOSAR_CHANNEL ));
}

/******************************************************************************/
/*                                                                            */
/* !Description: Read without filtering from the o/p ECU pin (CM_28)    */
/*                                                                            */
/******************************************************************************/
/* !Comment: Raw input                                                        */
boolean DIOHAL_bReadRaw_CM_28 (void)
{
   return ((boolean)Dio_ReadChannel(DIOHAL_snCM_28_AUTOSAR_CHANNEL ));
}

/******************************************************************************/
/*                                                                            */
/* !Description: Read without filtering from the o/p ECU pin (CH_65)           */
/*                                                                            */
/******************************************************************************/
/* !Comment: Raw input                                                        */
boolean DIOHAL_bReadRaw_CH_65 (void)
{
   return (MOS_bDioRead(MOS_udtQ1504_1, MOS_udtVNS1_Q1504_1));
}


/******************************************************************************/
/*                                                                            */
/* !Description: Read without filtering from the o/p ECU pin (CH_66)           */
/*                                                                            */
/******************************************************************************/
/* !Comment: Raw input                                                        */
boolean DIOHAL_bReadRaw_CH_66 (void)
{
   return (MOS_bDioRead(MOS_udtQ1504_2, MOS_udtVNS1_Q1504_2));
}


/******************************************************************************/
/*                                                                            */
/* !Description: Read filtered input from ECU pin (CH_16)                      */
/*                                                                            */
/******************************************************************************/
/* !Comment: Filtered input                                                   */
boolean DIOHAL_bRead_CH_16 (void)
{
   uint16  u16LocalVar;
   boolean bLocalResult;

   u16LocalVar = DIOHAL_au16LowFreqFilterTable[DIOHAL_u8FILTER_VEC_INDX_CH_16];
   if((u16LocalVar & (uint16)( (uint16)1 << DIOHAL_u8READ_BIT_NBR_CH_16)) != 0)
   {
      bLocalResult = STD_ON;
   }
   else
   {
      bLocalResult = STD_OFF;
   }
   return (bLocalResult);
}

/******************************************************************************/
/*                                                                            */
/* !Description: Read filtered input from ECU pin (CH_19)                      */
/*                                                                            */
/******************************************************************************/
/* !Comment: Filtered input                                                   */
boolean DIOHAL_bRead_CH_19 (void)
{
   uint16  u16LocalVar;
   boolean bLocalResult;

   u16LocalVar = DIOHAL_au16LowFreqFilterTable[DIOHAL_u8FILTER_VEC_INDX_CH_19];
   if((u16LocalVar & (uint16)( (uint16)1 << DIOHAL_u8READ_BIT_NBR_CH_19)) != 0)
   {
      bLocalResult = STD_ON;
   }
   else
   {
      bLocalResult = STD_OFF;
   }
   return (bLocalResult);
}

/******************************************************************************/
/*                                                                            */
/* !Description: Read filtered input from ECU pin (CH_20)                      */
/*                                                                            */
/******************************************************************************/
/* !Comment: Filtered input                                                   */
boolean DIOHAL_bRead_CH_20 (void)
{
   uint16  u16LocalVar;
   boolean bLocalResult;

   u16LocalVar = DIOHAL_au16LowFreqFilterTable[DIOHAL_u8FILTER_VEC_INDX_CH_20];
   if((u16LocalVar & (uint16)( (uint16)1 << DIOHAL_u8READ_BIT_NBR_CH_20)) != 0)
   {
      bLocalResult = STD_ON;
   }
   else
   {
      bLocalResult = STD_OFF;
   }
   return (bLocalResult);
}

/******************************************************************************/
/*                                                                            */
/* !Description: Read filtered input from ECU pin (CH_21)                      */
/*                                                                            */
/******************************************************************************/
/* !Comment: Filtered input                                                   */
boolean DIOHAL_bRead_CH_21 (void)
{
   uint16  u16LocalVar;
   boolean bLocalResult;

   u16LocalVar = DIOHAL_au16LowFreqFilterTable[DIOHAL_u8FILTER_VEC_INDX_CH_21];
   if((u16LocalVar & (uint16)( (uint16)1 << DIOHAL_u8READ_BIT_NBR_CH_21)) != 0)
   {
      bLocalResult = STD_ON;
   }
   else
   {
      bLocalResult = STD_OFF;
   }
   return (bLocalResult);
}

/******************************************************************************/
/*                                                                            */
/* !Description: Read filtered input from ECU pin (CH_25)                      */
/*                                                                            */
/******************************************************************************/
/* !Comment: Filtered input                                                   */
boolean DIOHAL_bRead_CH_25 (void)
{
   uint16  u16LocalVar;
   boolean bLocalResult;

   u16LocalVar = DIOHAL_au16LowFreqFilterTable[DIOHAL_u8FILTER_VEC_INDX_CH_25];
   if((u16LocalVar & (uint16)( (uint16)1 << DIOHAL_u8READ_BIT_NBR_CH_25)) != 0)
   {
      bLocalResult = STD_ON;
   }
   else
   {
      bLocalResult = STD_OFF;
   }
   return (bLocalResult);
}

/******************************************************************************/
/*                                                                            */
/* !Description: Read filtered input from ECU pin (CH_34)                      */
/*                                                                            */
/******************************************************************************/
/* !Comment: Filtered input                                                   */
boolean DIOHAL_bRead_CH_34 (void)
{
   uint16  u16LocalVar;
   boolean bLocalResult;

   u16LocalVar = DIOHAL_au16LowFreqFilterTable[DIOHAL_u8FILTER_VEC_INDX_CH_34];
   if((u16LocalVar & (uint16)( (uint16)1 << DIOHAL_u8READ_BIT_NBR_CH_34)) != 0)
   {
      bLocalResult = STD_ON;
   }
   else
   {
      bLocalResult = STD_OFF;
   }
   return (bLocalResult);
}

/******************************************************************************/
/*                                                                            */
/* !Description: Read filtered input from ECU pin (CH_36)                      */
/*                                                                            */
/******************************************************************************/
/* !Comment: Filtered input                                                   */
boolean DIOHAL_bRead_CH_36 (void)
{
   uint16  u16LocalVar;
   boolean bLocalResult;

   u16LocalVar = DIOHAL_au16LowFreqFilterTable[DIOHAL_u8FILTER_VEC_INDX_CH_36];
   if((u16LocalVar & (uint16)( (uint16)1 << DIOHAL_u8READ_BIT_NBR_CH_36)) != 0)
   {
      bLocalResult = STD_ON;
   }
   else
   {
      bLocalResult = STD_OFF;
   }
   return (bLocalResult);
}

/******************************************************************************/
/*                                                                            */
/* !Description: Read filtered input from ECU pin (CH_38)                      */
/*                                                                            */
/******************************************************************************/
/* !Comment: Filtered input                                                   */
boolean DIOHAL_bRead_CH_38 (void)
{
   uint16  u16LocalVar;
   boolean bLocalResult;

   u16LocalVar = DIOHAL_au16LowFreqFilterTable[DIOHAL_u8FILTER_VEC_INDX_CH_38];
   if((u16LocalVar & (uint16)( (uint16)1 << DIOHAL_u8READ_BIT_NBR_CH_38)) != 0)
   {
      bLocalResult = STD_ON;
   }
   else
   {
      bLocalResult = STD_OFF;
   }
   return (bLocalResult);
}

/******************************************************************************/
/*                                                                            */
/* !Description: Read filtered input from ECU pin (CH_47)                      */
/*                                                                            */
/******************************************************************************/
/* !Comment: Filtered input                                                   */
boolean DIOHAL_bRead_CH_47 (void)
{
   uint16  u16LocalVar;
   boolean bLocalResult;

   u16LocalVar = DIOHAL_au16LowFreqFilterTable[DIOHAL_u8FILTER_VEC_INDX_CH_47];
   if((u16LocalVar & (uint16)( (uint16)1 << DIOHAL_u8READ_BIT_NBR_CH_47)) != 0)
   {
      bLocalResult = STD_ON;
   }
   else
   {
      bLocalResult = STD_OFF;
   }
   return (bLocalResult);
}

/******************************************************************************/
/*                                                                            */
/* !Description: Read filtered input from ECU pin (CH_48)                      */
/*                                                                            */
/******************************************************************************/
/* !Comment: Filtered input                                                   */
boolean DIOHAL_bRead_CH_48 (void)
{
   uint16  u16LocalVar;
   boolean bLocalResult;

   u16LocalVar = DIOHAL_au16LowFreqFilterTable[DIOHAL_u8FILTER_VEC_INDX_CH_48];
   if((u16LocalVar & (uint16)( (uint16)1 << DIOHAL_u8READ_BIT_NBR_CH_48)) != 0)
   {
      bLocalResult = STD_ON;
   }
   else
   {
      bLocalResult = STD_OFF;
   }
   return (bLocalResult);
}

/******************************************************************************/
/*                                                                            */
/* !Description: Read filtered input from ECU pin (CH_52)                      */
/*                                                                            */
/******************************************************************************/
/* !Comment: Filtered input                                                   */
boolean DIOHAL_bRead_CH_52 (void)
{
   uint16  u16LocalVar;
   boolean bLocalResult;

   u16LocalVar = DIOHAL_au16LowFreqFilterTable[DIOHAL_u8FILTER_VEC_INDX_CH_52];
   if((u16LocalVar & (uint16)( (uint16)1 << DIOHAL_u8READ_BIT_NBR_CH_52)) != 0)
   {
      bLocalResult = STD_ON;
   }
   else
   {
      bLocalResult = STD_OFF;
   }
   return (bLocalResult);
}

/******************************************************************************/
/*                                                                            */
/* !Description: Read filtered input from ECU pin (CH_56)                      */
/*                                                                            */
/******************************************************************************/
/* !Comment: Filtered input                                                   */
boolean DIOHAL_bRead_CH_56 (void)
{
   uint16  u16LocalVar;
   boolean bLocalResult;

   u16LocalVar = DIOHAL_au16LowFreqFilterTable[DIOHAL_u8FILTER_VEC_INDX_CH_56];
   if((u16LocalVar & (uint16)( (uint16)1 << DIOHAL_u8READ_BIT_NBR_CH_56)) != 0)
   {
      bLocalResult = STD_ON;
   }
   else
   {
      bLocalResult = STD_OFF;
   }
   return (bLocalResult);
}

/******************************************************************************/
/*                                                                            */
/* !Description: Read filtered input from ECU pin (CH_59)                      */
/*                                                                            */
/******************************************************************************/
/* !Comment: Filtered input                                                   */
boolean DIOHAL_bRead_CH_59 (void)
{
   uint16  u16LocalVar;
   boolean bLocalResult;

   u16LocalVar = DIOHAL_au16LowFreqFilterTable[DIOHAL_u8FILTER_VEC_INDX_CH_59];
   if((u16LocalVar & (uint16)( (uint16)1 << DIOHAL_u8READ_BIT_NBR_CH_59)) != 0)
   {
      bLocalResult = STD_ON;
   }
   else
   {
      bLocalResult = STD_OFF;
   }
   return (bLocalResult);
}

/******************************************************************************/
/*                                                                            */
/* !Description: Read filtered input from ECU pin (CM_10)                      */
/*                                                                            */
/******************************************************************************/
/* !Comment: Filtered input                                                   */
boolean DIOHAL_bRead_CM_10 (void)
{
   uint16  u16LocalVar;
   boolean bLocalResult;

   u16LocalVar = DIOHAL_au16LowFreqFilterTable[DIOHAL_u8FILTER_VEC_INDX_CM_10];
   if((u16LocalVar & (uint16)( (uint16)1 << DIOHAL_u8READ_BIT_NBR_CM_10)) != 0)
   {
      bLocalResult = STD_ON;
   }
   else
   {
      bLocalResult = STD_OFF;
   }
   return (bLocalResult);
}

/******************************************************************************/
/*                                                                            */
/* !Description: Read filtered input from ECU pin (CM_27)                      */
/*                                                                            */
/******************************************************************************/
/* !Comment: Filtered input                                                   */
boolean DIOHAL_bRead_CM_27 (void)
{
   uint16  u16LocalVar;
   boolean bLocalResult;

   u16LocalVar = DIOHAL_au16LowFreqFilterTable[DIOHAL_u8FILTER_VEC_INDX_CM_27];
   if((u16LocalVar & (uint16)( (uint16)1 << DIOHAL_u8READ_BIT_NBR_CM_27)) != 0)
   {
      bLocalResult = STD_ON;
   }
   else
   {
      bLocalResult = STD_OFF;
   }
   return (bLocalResult);
}

/******************************************************************************/
/*                                                                            */
/* !Description: Read filtered input from ECU pin (CM_28)                      */
/*                                                                            */
/******************************************************************************/
/* !Comment: Filtered input                                                   */
boolean DIOHAL_bRead_CM_28 (void)
{
   uint16  u16LocalVar;
   boolean bLocalResult;

   u16LocalVar = DIOHAL_au16LowFreqFilterTable[DIOHAL_u8FILTER_VEC_INDX_CM_28];
   if((u16LocalVar & (uint16)( (uint16)1 << DIOHAL_u8READ_BIT_NBR_CM_28)) != 0)
   {
      bLocalResult = STD_ON;
   }
   else
   {
      bLocalResult = STD_OFF;
   }
   return (bLocalResult);
}

/******************************************************************************/
/*                                                                            */
/* !Description: Write to the ECU pin (CH_65)                                  */
/*                                                                            */
/******************************************************************************/
void DIOHAL_vidWrite_CH_65 (boolean bState)
{
   MOS_vidDioWrite(MOS_udtQ1504_1, MOS_udtVNS1_Q1504_1, bState);
}

/******************************************************************************/
/*                                                                            */
/* !Description: Write to the ECU pin (CH_66)                                  */
/*                                                                            */
/******************************************************************************/
void DIOHAL_vidWrite_CH_66 (boolean bState)
{
   MOS_vidDioWrite(MOS_udtQ1504_2, MOS_udtVNS1_Q1504_2, bState);
}


#define DIOHAL_STOP_SEC_CODE
#include "DIOHAL_MemMap.h"

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

#define DIOHAL_START_SEC_CONST_UNSPECIFIED
#include "DIOHAL_MemMap.h"

/* !Comment: Array of pointer to functions of all defined ReadRaw for ECU pins*/
boolean (* const DIOHAL_akpfbReadRaw[DIOHAL_u8READ_TABLE_SIZE])(void) =
{
   &TLE8718_bDioRead_INST1_OUT5,
   &TLE8718_bDioRead_INST1_OUT6,
   &TLE8718_bDioRead_INST1_OUT8,
   &TLE8718_bDioRead_INST1_OUT11,
   &TLE8718_bDioRead_INST1_OUT12,
   &TLE8718_bDioRead_INST1_OUT13,
   &TLE8718_bDioRead_INST1_OUT14,
   &TLE8718_bDioRead_INST1_OUT15,
   &TLE8718_bDioRead_INST1_OUT16,
   &DIOHAL_bReadRaw_CH_65,
   &DIOHAL_bReadRaw_CH_66,
   &PWLHAL_bReadRawMainRlyState,
   &LBHOT_bReadRawLbupHotState,
   &LBHOT_bReadRawLbdwHotState,
   &DIOHAL_bReadRaw_CH_16,
   &DIOHAL_bReadRaw_CH_19,
   &DIOHAL_bReadRaw_CH_20,
   &DIOHAL_bReadRaw_CH_21,
   &DIOHAL_bReadRaw_CH_25,
   &DIOHAL_bReadRaw_CH_34,
   &DIOHAL_bReadRaw_CH_36,
   &DIOHAL_bReadRaw_CH_38,
   &DIOHAL_bReadRaw_CH_47,
   &DIOHAL_bReadRaw_CH_48,
   &DIOHAL_bReadRaw_CH_52,
   &DIOHAL_bReadRaw_CH_56,
   &DIOHAL_bReadRaw_CH_59,
   &DIOHAL_bReadRaw_CM_10,
   &DIOHAL_bReadRaw_CM_27,
   &DIOHAL_bReadRaw_CM_28,

};



/* !Comment: Array of pointer to functions of all defined Read for ECU pins   */
/* !Range  : DIOHAL_bReadRaw_O/P_PIN and  DIOHAL_bRead_I/P_PIN                */
boolean (* const DIOHAL_akpfbRead[DIOHAL_u8READ_TABLE_SIZE])(void) =
{
   &TLE8718_bDioRead_INST1_OUT5,
   &TLE8718_bDioRead_INST1_OUT6,
   &TLE8718_bDioRead_INST1_OUT8,
   &TLE8718_bDioRead_INST1_OUT11,
   &TLE8718_bDioRead_INST1_OUT12,
   &TLE8718_bDioRead_INST1_OUT13,
   &TLE8718_bDioRead_INST1_OUT14,
   &TLE8718_bDioRead_INST1_OUT15,
   &TLE8718_bDioRead_INST1_OUT16,
   &DIOHAL_bReadRaw_CH_65,
   &DIOHAL_bReadRaw_CH_66,
   &PWLHAL_bReadRawMainRlyState,
   &LBHOT_bReadRawLbupHotState,
   &LBHOT_bReadRawLbdwHotState,
   &DIOHAL_bRead_CH_16,
   &DIOHAL_bRead_CH_19,
   &DIOHAL_bRead_CH_20,
   &DIOHAL_bRead_CH_21,
   &DIOHAL_bRead_CH_25,
   &DIOHAL_bRead_CH_34,
   &DIOHAL_bRead_CH_36,
   &DIOHAL_bRead_CH_38,
   &DIOHAL_bRead_CH_47,
   &DIOHAL_bRead_CH_48,
   &DIOHAL_bRead_CH_52,
   &DIOHAL_bRead_CH_56,
   &DIOHAL_bRead_CH_59,
   &DIOHAL_bRead_CM_10,
   &DIOHAL_bRead_CM_27,
   &DIOHAL_bRead_CM_28,

};

/* !Comment: Array of pointer to functions of all defined Write for ECU pins  */
void (* const DIOHAL_akpfvidWrite[DIOHAL_u8WRITE_TABLE_SIZE])(boolean) =
{
   &TLE8718_vidDioWrite_INST1_OUT5,
   &TLE8718_vidDioWrite_INST1_OUT6,
   &TLE8718_vidDioWrite_INST1_OUT8,
   &TLE8718_vidDioWrite_INST1_OUT11,
   &TLE8718_vidDioWrite_INST1_OUT12,
   &TLE8718_vidDioWrite_INST1_OUT13,
   &TLE8718_vidDioWrite_INST1_OUT14,
   &TLE8718_vidDioWrite_INST1_OUT15,
   &TLE8718_vidDioWrite_INST1_OUT16,
   &DIOHAL_vidWrite_CH_65,
   &DIOHAL_vidWrite_CH_66,
   &PWLHAL_vidWriteMainRlyState,
   &LBHOT_vidWriteLbupHotState,
   &LBHOT_vidWriteLbdwHotState,

















};

#define DIOHAL_STOP_SEC_CONST_UNSPECIFIED
#include "DIOHAL_MemMap.h"

/*------------------------------ end of file ---------------------------------*/

