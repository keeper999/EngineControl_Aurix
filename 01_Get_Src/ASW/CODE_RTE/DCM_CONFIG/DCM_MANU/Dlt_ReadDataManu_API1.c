/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DCM_MANU                                                */
/* !Description     : DCM_MANU Component                                      */
/*                                                                            */
/* !Module          : DCM_MANU                                                */
/* !Description     : Code Manuel du DCM                                      */
/*                                                                            */
/* !File            : Dlt_ReadDataManu_API1.c                                 */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32BIT                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / DLT_ReadDataLength_2101                                              */
/*   2 / DLT_ConditionCheckRead_2101                                          */
/*   3 / DLT_ReadData_2101                                                    */
/*   4 / DLT_ReadDataLength_2100                                              */
/*   5 / DLT_ConditionCheckRead_2100                                          */
/*   6 / DLT_ReadData_2100                                                    */
/*   7 / DLT_ReadDataLength_F080                                              */
/*   8 / DLT_ConditionCheckRead_F080                                          */
/*   9 / DLT_ReadData_F080                                                    */
/*   10 / DLT_ReadDataLength_F0FE                                             */
/*   11 / DLT_ConditionCheckRead_F0FE                                         */
/*   12 / DLT_ReadData_F0FE                                                   */
/*   13 / DLT_ReadDataLength_F18B                                             */
/*   14 / DLT_ConditionCheckRead_F18B                                         */
/*   15 / DLT_ReadData_F18B                                                   */
/*   16 / DLT_ConditionCheckRead_C001                                         */
/*   17 / DLT_ReadData_C001                                                   */
/*   18 / DLT_ReadDataLength_D500                                             */
/*   19 / DLT_ConditionCheckRead_D500                                         */
/*   20 / DLT_ReadData_D500                                                   */
/*   21 / DLT_ReadDataLength_F196                                             */
/*   22 / DLT_ConditionCheckRead_F196                                         */
/*   23 / DLT_ReadData_F196                                                   */
/*                                                                            */
/* !Reference   : PTS_DOC_5074345 / 4                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/EBX6_2/LOG/ASW/REF/MODULES/DCM_CONFIG/DCM_MANU/Dlt$*/
/* $Revision::   1.2      $$Author::   pbakabad       $$Date::   22 May 2014 $*/
/* $Author::   pbakabad                               $$Date::   22 May 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "Dlt.h"
#include "VEMS.H"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_2101                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called, to check data length                    */
/* !Number      :  RDATAMANU_API1.1                                           */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Srv_TeleDataSize_C;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadDataLength_2101
(
   uint16* DataLength
)
{
   uint16 u16LocalSize;

   if( Srv_TeleDataSize_C > DCM_MANU_TELE_PROGRAM_RAW_DATA_SIZE )
   {
      u16LocalSize = (uint16)(DCM_MANU_TELE_PROGRAM_RAW_DATA_SIZE);
   }
   else
   {
      u16LocalSize = (uint16)(Srv_TeleDataSize_C);
   }

   /* Il faut remonter la taille de la trame en bits */
   *DataLength = (uint16)(u16LocalSize * 8);
   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_2101                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API1.2                                           */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_2101
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_2101                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API1.3                                           */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Id_telecodage_eeprom;                                         */
/*  input uint8 Tele_program_fric;                                            */
/*  input uint8 Tele_program_press_clim;                                      */
/*  input uint8 Tele_program_gear_box;                                        */
/*  input uint16 Tele_program_alternator;                                     */
/*  input uint8 Tele_program_car;                                             */
/*  input uint8 Tele_program_add_heat;                                        */
/*  input uint32 Tele_program_uc;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_2101
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8  u8LocalId_telecodage_eeprom;
   uint8  u8LocalTele_program_fric;
   uint8  u8LocalTele_program_press_clim;
   uint8  u8LocalTele_program_gear_box;
   uint8  u8LocalTele_program_car;
   uint8  u8LocalTele_program_add_heat;
   uint16 u16LocalTele_program_alternator;
   uint32 u32LocalTele_program_uc;

   VEMS_vidGET(Id_telecodage_eeprom, u8LocalId_telecodage_eeprom);
   VEMS_vidGET(Tele_program_fric, u8LocalTele_program_fric);
   VEMS_vidGET(Tele_program_press_clim, u8LocalTele_program_press_clim);
   VEMS_vidGET(Tele_program_gear_box, u8LocalTele_program_gear_box);
   VEMS_vidGET(Tele_program_alternator, u16LocalTele_program_alternator);
   VEMS_vidGET(Tele_program_car, u8LocalTele_program_car);
   VEMS_vidGET(Tele_program_add_heat, u8LocalTele_program_add_heat);
   VEMS_vidGET(Tele_program_uc, u32LocalTele_program_uc);

   Data[0] = u8LocalId_telecodage_eeprom;
   Data[1] = u8LocalTele_program_fric;
   Data[2] = u8LocalTele_program_press_clim;
   Data[3] = u8LocalTele_program_gear_box;
   Data[4] = (uint8)(u16LocalTele_program_alternator & 0x00FF);
   Data[5] = (uint8)((u16LocalTele_program_alternator & 0xFF00) >> 8);
   Data[6] = u8LocalTele_program_car;
   Data[7] = u8LocalTele_program_add_heat;
   Data[8] = (uint8)(u32LocalTele_program_uc & 0x000000FF);
   Data[9] = (uint8)((u32LocalTele_program_uc & 0x0000FF00) >> 8);
   Data[10] = (uint8)((u32LocalTele_program_uc & 0x00FF0000) >> 16);

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_2100                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called, to check data length                    */
/* !Number      :  RDATAMANU_API1.4                                           */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 Srv_TeleDataSize_C;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadDataLength_2100
(
   uint16* DataLength
)
{
   uint16 u16LocalSize;

   if( Srv_TeleDataSize_C > DCM_MANU_TELE_PROGRAM_RAW_DATA_SIZE )
   {
      u16LocalSize = (uint16)(DCM_MANU_TELE_PROGRAM_RAW_DATA_SIZE);
   }
   else
   {
      u16LocalSize = (uint16)(Srv_TeleDataSize_C);
   }

   /* Il faut remonter la taille de la trame en bits */
   *DataLength = (uint16)( (u16LocalSize + 1) * 8 );
   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_2100                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API1.5                                           */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_2100
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_2100                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API1.6                                           */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Id_telecodage_eeprom;                                         */
/*  input uint8 Tele_program_nb;                                              */
/*  input uint8 Tele_available_fric;                                          */
/*  input uint8 Tele_available_press_clim;                                    */
/*  input uint8 Tele_available_gear_box;                                      */
/*  input uint16 Tele_available_alternator;                                   */
/*  input uint8 Tele_available_car;                                           */
/*  input uint8 Tele_available_add_heat;                                      */
/*  input uint32 Tele_available_uc;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_2100
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8  u8LocalId_telecodage_eeprom;
   uint8  u8LocalTele_program_nb;

   VEMS_vidGET(Id_telecodage_eeprom, u8LocalId_telecodage_eeprom);
   VEMS_vidGET(Tele_program_nb, u8LocalTele_program_nb);

   Data[0] = u8LocalId_telecodage_eeprom;
   Data[1] = Tele_available_fric;
   Data[2] = Tele_available_press_clim;
   Data[3] = Tele_available_gear_box;
   Data[4] = (uint8)(Tele_available_alternator & 0x00FF);
   Data[5] = (uint8)((Tele_available_alternator & 0xFF00) >> 8);
   Data[6] = Tele_available_car;
   Data[7] = Tele_available_add_heat;
   Data[8] = (uint8)(Tele_available_uc & 0x000000FF);
   Data[9] = (uint8)((Tele_available_uc & 0x0000FF00) >> 8);
   Data[10] = (uint8)((Tele_available_uc & 0x00FF0000) >> 16);
   Data[11] = u8LocalTele_program_nb;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadDataLength_F080
(
   uint16* DataLength
)
{
   /* Il faut remonter la taille de la trame en bits */
   *DataLength = (uint16)(DCM_MANU_ZA_BYTE_SIZE * 8);
   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_F080                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API1.8                                           */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret uint16  SUPSRV_u16ReadFuncSchemNr(argio uint8 *pau8Buffer,    */
/*  argin uint16 u16MaxSize);                                                 */
/*  extf argret uint16  SUPSRV_u16ReadFuncProdNr(argio uint8 *pau8Buffer,     */
/* argin uint16 u16MaxSize);                                                  */
/*  input uint8 DataBuffer[24];                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_F080
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   Std_ReturnType u8localreturn;
   uint16         u16LocalLengthRetSchemNr;
   uint16         u16LocalLengthRetProdNr;

   u8localreturn = E_OK;

   u16LocalLengthRetSchemNr =
     SUPSRV_u16ReadFuncSchemNr(&DataBuffer[0], BUF_SIZE);

   u16LocalLengthRetProdNr =
     SUPSRV_u16ReadFuncProdNr(&DataBuffer[5], (BUF_SIZE-5));

   if( ( u16LocalLengthRetSchemNr != 5 ) ||
       ( u16LocalLengthRetProdNr != 5  ) )
   {
      u8localreturn = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }
   return u8localreturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_F080                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API1.9                                           */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 DataBuffer[24];                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_F080
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   Data[0] = DataBuffer[0];
   Data[1] = DataBuffer[1];
   Data[2] = DataBuffer[2];
   Data[3] = DataBuffer[3];
   Data[4] = DataBuffer[4];
   Data[5] = 0x00;
   Data[6] = 0x06;
   Data[7] = DataBuffer[5];
   Data[8] = DataBuffer[6];
   Data[9] = DataBuffer[7];
   Data[10] = DataBuffer[8];
   Data[11] = DataBuffer[9];
   Data[12] = 0xFF;
   Data[13] = 0xFF;
   Data[14] = 0xFF;
   Data[15] = 0xFF;
   Data[16] = 0x00;
   Data[17] = 0x01;
   Data[18] = 0xFF;
   Data[19] = 0xFF;
   Data[20] = 0xFF;
   Data[21] = 0xFF;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_F0FE                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called, to check data length                    */
/* !Number      :  RDATAMANU_API1.10                                          */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadDataLength_F0FE
(
   uint16* DataLength
)
{
   /* Il faut remonter la taille de la trame en bits (24 * 8)*/
   *DataLength = (uint16)(DCM_MANU_ZI_BYTE_SIZE * 8);
   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_F0FE                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API1.11                                          */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret uint16  SUPSRV_u16ReadHistoryArea(argin uint8 u8LidId, argout */
/*  uint8 *pau8Buffer, argin uint16 u16MaxSize);                              */
/*  input uint8 DataBuffer[24];                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_F0FE
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16         u16LocalLength;
   Std_ReturnType u8localreturn;

   u8localreturn = E_OK;

   u16LocalLength =
      SUPSRV_u16ReadHistoryArea(0xFE, &DataBuffer[0], BUF_SIZE);

   if(u16LocalLength != BUF_SIZE)
   {
      u8localreturn = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }

   return u8localreturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_F0FE                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API1.12                                          */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 DataBuffer[24];                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_F0FE
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8 u8LocalIdx;

   for(u8LocalIdx=0; u8LocalIdx<BUF_SIZE; u8LocalIdx++)
   {
      Data[u8LocalIdx] = DataBuffer[u8LocalIdx];
   }

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_F18B                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called, to check data length                    */
/* !Number      :  RDATAMANU_API1.13                                          */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadDataLength_F18B
(
   uint16* DataLength
)
{
   /* Il faut remonter la taille de la trame en bits (3 * 8)*/
   *DataLength = (uint16)(DCM_MANU_MANUFACTURINGDATESIZE * 8);
   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_F18B                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API1.14                                          */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_11_02667_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret uint16  SUPSRV_u16ReadManufacturingDate(argio uint8           */
/*  *pau8Buffer, argin uint16 u16MaxSize);                                    */
/*  input uint8 DataBuffer[24];                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_F18B
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   uint16         u16LocalLength;
   Std_ReturnType u8localreturn;

   u8localreturn = E_OK;

   u16LocalLength =
      SUPSRV_u16ReadManufacturingDate(&DataBuffer[0], (uint16)BUF_SIZE);

   if( DCM_MANU_MANUFACTURINGDATESIZE != u16LocalLength )
   {
      u8localreturn = E_NOT_OK;
      *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
   }

   return u8localreturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_F18B                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API1.15                                          */
/* !Author      :  etsassong                                                  */
/* !Trace_To    :  VEMS_E_11_02667_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 DataBuffer[24];                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_F18B
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint32 u32index;

   for( u32index = 0; u32index < DCM_MANU_MANUFACTURINGDATESIZE; u32index++ )
   {
      Data[u32index] = DataBuffer[u32index];
   }

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_C001                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API1.16                                          */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_C001
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_C001                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API1.17                                          */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_C001
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   /* Nombre maximum de DID supporté dans une requête de lecture. */
   /* Fixé à 1 à causes des requêtes longues */
   Data[0] = 0x01;
   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_D500                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API1.18                                          */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadDataLength_D500
(
   uint16* DataLength
)
{
   /* Il faut remonter la taille de la trame en bits */
   *DataLength = (uint16)( DCM_MANU_SRV_PRM_IDCHRNINJR_SIZE * 8 );
   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_D500                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API1.19                                          */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_D500
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_D500                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API1.20                                          */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Srv_IdChrnInjr_C;                                             */
/*  input uint8 Ext_stTypInjr;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_D500
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   uint8 u8LocalTmp;

   Data[0] = Srv_IdChrnInjr_C;
   VEMS_vidGET(Ext_stTypInjr,u8LocalTmp);
   Data[1] = u8LocalTmp;

   return E_OK;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadDataLength_F196                                    */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called, to check data length                    */
/* !Number      :  RDATAMANU_API1.21                                          */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  REFIDETA_ReadDataLength(argout uint16         */
/*  *DataLength);                                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadDataLength_F196
(
   uint16* DataLength
)
{
   uint16          u16LocalSize;
   Std_ReturnType  u8LocalReturn;

   u8LocalReturn = REFIDETA_ReadDataLength(&u16LocalSize);

   *DataLength = u16LocalSize;

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ConditionCheckRead_F196                                */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called to see if Dlt_ReadData can be called.    */
/* !Number      :  RDATAMANU_API1.22                                          */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  REFIDETA_ConditionCheck_ReadData(argin        */
/*  Dcm_OpStatusType OpStatus, argout Dcm_NegativeResponseCodeType            */
/*  *ErrorCode);                                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ConditionCheckRead_F196
(
   Dcm_OpStatusType OpStatus,
   Dcm_NegativeResponseCodeType* ErrorCode
)
{
   Std_ReturnType               u8LocalReturn;
   Dcm_OpStatusType             u8LocalOpStatus;
   Dcm_NegativeResponseCodeType u8LocalErrorCode;

   u8LocalOpStatus = OpStatus;

   u8LocalReturn = REFIDETA_ConditionCheck_ReadData( u8LocalOpStatus,
                                                     &u8LocalErrorCode );

   *ErrorCode = u8LocalErrorCode;

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  DLT_ReadData_F196                                          */
/* !Description :  Is called from Dcm when UDS service ReadDataByIdendifer for*/
/*                 Dlt DID is called.                                         */
/* !Number      :  RDATAMANU_API1.23                                          */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  REFIDETA_ReadData_Uds(argin Dcm_OpStatusType  */
/*  OpStatus, argout uint8 *Data);                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType DLT_ReadData_F196
(
   Dcm_OpStatusType OpStatus,
   uint8* Data
)
{
   Std_ReturnType u8LocalReturn;

   u8LocalReturn = REFIDETA_ReadData_Uds( OpStatus,
                                      Data );
   return u8LocalReturn;
}