/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  $FILENAME   : Port.c $                                                   **
**                                                                            **
**  $CC VERSION : \main\58 $                                                 **
**                                                                            **
**  $DATE       : 2014-01-10 $                                               **
**                                                                            **
**  AUTHOR       : DL-AUTOSAR-Engineering                                     **
**                                                                            **
**  VENDOR       : Infineon Technologies                                      **
**                                                                            **
**  DESCRIPTION  : This file contains                                         **
**                 - functionality of Port driver.                            **
**                                                                            **
**  MAY BE CHANGED BY USER [Yes/No]: No                                       **
**                                                                            **
*******************************************************************************/
/*  TRACEABILITY : [cover parentID=DS_AS_PORT107_PORT146_4,DS_NAS_PORT_PR127,
                    SAS_NAS_PORT_PR913,DS_AS40X_PORT114,
                    DS_NAS_PORT_PR228,DS_AS_PORT107_PORT146,
                    SAS_AS_PORT080_PORT108_PORT130_PORT131_PORT133_PORT208]   
                   [/cover]                                                   */
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/* Inclusion of Tasking sfr file */

#include "IfxPort_reg.h"

/* Global functions like Set/Reset END INIT protection bit,
  Enable/Disable interrupts, Automic write function */
#include "Mcal.h"

/* Own header file, this includes own configuration file also */
/* PORT080: Inclusion structure */
#include "Port.h"

/*AS and SW version Specific include file */
#include "Port_Ver.h"

/* Inclusion from Safety Error */
#if (PORT_SAFETY_ENABLE == STD_ON)
#include "SafetyReport.h"
#endif 

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*
  Offset definitions for data in Port configuration
*/
/* Initial Control data offset */
#define PORT_DATA_OFS_CTL      (0U)
/* Initial level data offset */
#define PORT_DATA_OFS_LEVEL    (4U)

/* If pin mode changeable is enabled */
#if (PORT_SET_PIN_MODE_API == STD_ON)
/* Pin mode changeable or not offset */
#define PORT_DATA_OFS_MODE     (7U) 

#define PORT_OUT_PIN_MASK      (0xC0U)

#endif /* (PORT_SET_PIN_MODE_API) */

/* If Direction changeable is enabled */
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
/* If pin mode changeable is enabled */
#if (PORT_SET_PIN_MODE_API == STD_ON)
/* Pin direction data offset */
#define PORT_DATA_OFS_DIR      (8U) 
/* Control data 2 offset */
#define PORT_DATA_OFS_CTL2     (9U)

#else
/* Pin direction data offset */
#define PORT_DATA_OFS_DIR      (7U)
/* Control data 2 offset */
#define PORT_DATA_OFS_CTL2     (8U)

#endif /* (PORT_SET_PIN_MODE_API) */
#endif /* (PORT_SET_PIN_DIRECTION_API) */

#if((PORT_SET_PIN_DIRECTION_API == STD_ON) || (PORT_SET_PIN_MODE_API == STD_ON))
/* Mask to get direction info from Pin control value */
#define PORT_DIR_MSK           (0x80U)
#endif

/* IOCR0 register offset in Ifx_P */
#define PORT_IOCR0_REG_OFFSET  (4U)

/* TBD */
/* LPCR register offset in Ifx_P */
#define PORT_LPCR_REG_OFFSET   (0x28U)

/* PCSR register offset in Ifx_P */
#define PORT_PCSR_REG_OFFSET   (0x19U)

#if(PORT_DEV_ERROR_DETECT == STD_ON)
/* Status to indicate that PORT is initialized */
#define PORT_INITIALIZED  ((uint8)1)
#endif  /*(PORT_DEV_ERROR_DETECT == STD_ON)*/

/* Before Setting the Iocr register, To Check the Port number below
   macro's are used */

#define PORT_PIN_0_3           (0x000F)
#define PORT_PIN_4_7           (0x00F0)
#define PORT_PIN_8_11          (0x0F00)
#define PORT_PIN_12_15         (0xF000)

/* 8-bit mask value from 8th to 15th bit */
#define PORT_PDR1_MASK         (0xFF00U)

#if((PORT_SET_PIN_DIRECTION_API == STD_ON) || (PORT_SET_PIN_MODE_API == STD_ON))
/* offset value where the port number is present */
#define PORT_NUMBER_OFFSET     (4U)

/* lower 8-bit mask value in hex to get the port number */
#define PORT_NUM_LOW8_MASK     (0x000000FFU)

/* lower 4-bit mask value in hex to get the pin number of a port */
#define PORT_PIN_LOW4_MASK     (0x0FU)

#endif

/* lower 16-bit mask value in Hex */
#define PORT_LOWER_16BIT_MASK  (0x0000FFFFU)

/* 16-bit shift value */
#define PORT_16BIT_SHIFTVALUE  (16U)

/* general constants */
#define PORT_CONSTANT_16       (16U)
#define PORT_CONSTANT_10       (10U)
#define PORT_NUMBER_32         (32U)
#define PORT_NUMBER_31         (31U)
#define PORT_CONSTANT_0x01     (0x01U)


#if (PORT_SET_PIN_MODE_API == STD_ON) 
#if ((PORT_DEV_ERROR_DETECT == STD_ON) || (PORT_SAFETY_ENABLE == STD_ON))

/* Available Inverted Port Mask */
#define AVAILABLE_MODE_MASK    ((Port_PinModeType)(0xC7U))

#endif /*(PORT_SET_PIN_MODE_API==STD_ON) */
#endif 
/* ((PORT_DEV_ERROR_DETECT == STD_ON) || (PORT_SAFETY_ENABLE == STD_ON))*/

/* Maximum port pin number */
#define PORT_PIN_MAX_NUMBER    (15U)

/* Mcal Safety ENDINIT Timeout value */
#define PORT_ENDINIT_TIMEOUT   (150000U)

/*******************************************************************************
**                   Function like macro definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

#define PORT_START_SEC_CODE
/*mapping of code and data to specific memory sections via memory mapping file*/
#include "MemMap.h"

/*_INLINE_ function to initialize Port module*/
static _INLINE_ void Port_lIOInit(void);

/*_INLINE_ function to initialize Port module*/
static _INLINE_ void Port_lPDRInit(void);

/*_INLINE_ function to extract the Address of Px_OUT register */
static _INLINE_ Ifx_P *Port_lAdr(uint32 PortNumber); 

/*_INLINE_ function to to check if the port 
  is available or not for the microcontroller */
static _INLINE_ uint32 Port_lIsPortAvailable31(uint32 Port);

/*_INLINE_ function to check if the port 
  is available or not for the microcontroller */
static _INLINE_ uint32 Port_lIsPortAvailable40(uint32 Port);

/*_INLINE_ function to check if the port is 
  available or not for the microcontroller    */
static _INLINE_ uint32 Port_lIsPortAvailable(uint32 Port);

/*_INLINE_ function to check if the port is read only or it is writable */
static _INLINE_ uint32 Port_lIsPortReadOnly31(uint32 Port);

/*_INLINE_ function to check if the port is read only or it is writable */
static _INLINE_ uint32 Port_lIsPortReadOnly40(uint32 Port);

/*_INLINE_ function to check if the port is read only or it is writable*/
static _INLINE_ uint32 Port_lIsPortReadOnly(uint32 Port);

/*_INLINE_ function to check if the port pin is 
  available or not for the microcontroller      */
static _INLINE_ uint16 Port_lIsPinAvailable(uint32 Port,uint32 Pin);

/*_INLINE_ function to check if any of the 
  portpin 8-15 is available or not for the micro*/
static _INLINE_ uint16 Port_lIsPortPdr1Available(uint32 Port);

/*_INLINE_ function to check if the IOCRx register for the port
   is available or not for the micro */
static _INLINE_ uint16 Port_lIsPortIocrAvailable(uint32 Port,uint16 Pin);

#if (PORT_SET_PIN_MODE_API == STD_ON) 
#if ((PORT_DEV_ERROR_DETECT == STD_ON) || (PORT_SAFETY_ENABLE == STD_ON))

/*_INLINE_ function to check the error 
  in the Port_SetPinMode Api  */
static _INLINE_ uint32 Port_lModeErrChk
(
  uint8 Dir, Port_PinModeType Mode, uint32 ConfigIndex, uint32 PinNumber
);
static _INLINE_ uint8 Port_lChkPin
(
  Port_PinType Pin,uint32 PortNo,uint32 PinNo
);
#endif 
/*(PORT_SET_PIN_MODE_API==STD_ON) */
#endif 
/* ((PORT_DEV_ERROR_DETECT == STD_ON) || (PORT_SAFETY_ENABLE == STD_ON))*/

/*_INLINE_ function for OMR register value 
  to set the configured initial level      */
static _INLINE_ uint32 Port_lPinLevel(uint32 Level);

#if((PORT_SET_PIN_DIRECTION_API == STD_ON) || (PORT_SET_PIN_MODE_API == STD_ON))
/*_INLINE_ function to extract port number Port_PinType data */
static _INLINE_ uint32 Port_lNumber(Port_PinType Pin);

/*_INLINE_ function to extract pin number from Port_PinType data*/
static _INLINE_ uint32 Port_lPinNumber(Port_PinType Pin);
#endif

/*_INLINE_ function to to check if the port supports LVDS
   for the microcontroller */
static _INLINE_ uint32 Port_lIsPortLVDSAvailable31(uint32 Port);

/*_INLINE_ function to to check if the port supports LVDS
   for the microcontroller */
static _INLINE_ uint32 Port_lIsPortLVDSAvailable40(uint32 Port);

/*_INLINE_ function to to check if the port supports LVDS
   for the microcontroller */
static _INLINE_ uint32 Port_lIsPortLVDSAvailable(uint32 Port);

/*_INLINE_ function to to check if the port supports PCSR
   for the microcontroller */
static _INLINE_ uint32 Port_lIsPortPCSRAvailable31(uint32 Port);

/*_INLINE_ function to to check if the port supports PCSR
   for the microcontroller */
static _INLINE_ uint32 Port_lIsPortPCSRAvailable40(uint32 Port);

/*_INLINE_ function to to check if the port supports PCSR
   for the microcontroller */
static _INLINE_ uint32 Port_lIsPortPCSRAvailable(uint32 Port);

/*_INLINE_ function to to check if the port supports PCSR
   for the microcontroller */
static _INLINE_ uint32 Port_lIsPortPinPairAvailable(uint32 PortLPCRvalue);

#if (PORT_INIT_CHECK_API == STD_ON)
static _INLINE_ uint8 Port_lChkIocr(uint32 PortNo,const uint32 *DataPtr);
static _INLINE_ uint8 Port_lChkLVDS(uint32 PortNo,const uint32 *LVDSDataPtr);
static _INLINE_ uint8 Port_lChkPDR(uint32 PortNo,uint32 Data_PDR0, 
                                   uint32 Data_PDR1);
#endif

#define PORT_STOP_SEC_CODE
/*mapping of code and data to specific memory sections via memory mapping file*/
#include "MemMap.h"

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/
/* Mapping of 16 bit constant */
#define PORT_START_SEC_CONST_16BIT
#include "MemMap.h"

/* Total pin count for each port, This constant is used during DET check */
static const uint16 Port_kAvailablePins[] =
{
  PORT_AVAILABLE_PINS_PORT0,
  PORT_AVAILABLE_PINS_PORT1,
  PORT_AVAILABLE_PINS_PORT2,
  PORT_AVAILABLE_PINS_PORT3,
  PORT_AVAILABLE_PINS_PORT4,
  PORT_AVAILABLE_PINS_PORT5,
  PORT_AVAILABLE_PINS_PORT6,
  PORT_AVAILABLE_PINS_PORT7,
  PORT_AVAILABLE_PINS_PORT8,
  PORT_AVAILABLE_PINS_PORT9,
  PORT_AVAILABLE_PINS_PORT10,
  PORT_AVAILABLE_PINS_PORT11,
  PORT_AVAILABLE_PINS_PORT12,
  PORT_AVAILABLE_PINS_PORT13,
  PORT_AVAILABLE_PINS_PORT14,
  PORT_AVAILABLE_PINS_PORT15,
  PORT_AVAILABLE_PINS_PORT16,
  PORT_AVAILABLE_PINS_PORT17,
  PORT_AVAILABLE_PINS_PORT18,
  PORT_AVAILABLE_PINS_PORT19,
  PORT_AVAILABLE_PINS_PORT20,
  PORT_AVAILABLE_PINS_PORT21,
  PORT_AVAILABLE_PINS_PORT22,
  PORT_AVAILABLE_PINS_PORT23,
  PORT_AVAILABLE_PINS_PORT24,
  PORT_AVAILABLE_PINS_PORT25,
  PORT_AVAILABLE_PINS_PORT26,
  PORT_AVAILABLE_PINS_PORT27,
  PORT_AVAILABLE_PINS_PORT28,
  PORT_AVAILABLE_PINS_PORT29,
  PORT_AVAILABLE_PINS_PORT30,
  PORT_AVAILABLE_PINS_PORT31,
  PORT_AVAILABLE_PINS_PORT32,
  PORT_AVAILABLE_PINS_PORT33,
  PORT_AVAILABLE_PINS_PORT34,
  PORT_AVAILABLE_PINS_PORT35,
  PORT_AVAILABLE_PINS_PORT36,
  PORT_AVAILABLE_PINS_PORT37,
  PORT_AVAILABLE_PINS_PORT38,
  PORT_AVAILABLE_PINS_PORT39,
  PORT_AVAILABLE_PINS_PORT40
};

#define PORT_STOP_SEC_CONST_16BIT
#include "MemMap.h"
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#if(PORT_PB_FIXEDADDR == STD_OFF)
#define PORT_START_SEC_VAR_32BIT
#include "MemMap.h"

/* To store the Port driver configuration pointer */
static  const Port_ConfigType  *Port_kConfigPtr;

#define PORT_STOP_SEC_VAR_32BIT
#include "MemMap.h"

#endif /*(PORT_PB_FIXEDADDR == STD_OFF) */

#if(PORT_PB_FIXEDADDR == STD_ON)
#define PORT_START_SEC_CONST_32BIT
#include "MemMap.h"

/* To store the Port driver configuration pointer */
static  const Port_ConfigType * const Port_kConfigPtr = &Port_ConfigRoot[0];


#define PORT_STOP_SEC_CONST_32BIT
#include "MemMap.h"
#endif /*(PORT_PB_FIXEDADDR == STD_ON) */


#if(PORT_DEV_ERROR_DETECT == STD_ON)
/* Start 8 bit variable section */
#define PORT_START_SEC_VAR_8BIT
#include "MemMap.h"
/* Init Status Variable. It has to be initialized to "0U" after every reset as 0
   represents the deinitialized state */
static uint8 Port_InitStatus;
/* Stop 8 bit variable section */
#define PORT_STOP_SEC_VAR_8BIT
#include "MemMap.h"
#endif  /*(PORT_DEV_ERROR_DETECT == STD_ON)*/
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/* Mapping the code */
#define PORT_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Traceability     : [cover parentID=DS_AS_PORT140,DS_AS_PORT003,
                        DS_AS_PORT101_PORT211_1,DS_AS_PORT107_PORT146_1,
                        DS_AS_PORT107_PORT146_4,DS_AS_PORT087_1,DS_AS_PORT105,
                        DS_AS_PORT148,DS_AS_PORT005,
                        DS_AS_PORT077,DS_AS_PORT082,SAS_MCAL_SWSC_PORT_0402,
                        SAS_MCAL_SWSC_PORT_0407,SAS_MCAL_SWSC_PORT_0415,
                        DS_MCAL_SWSC_PORT_0415,DS_MCAL_SWSC_PORT_0417,
                        DS_MCAL_SWSC_PORT_0402,DS_AS_PORT107_PORT146_4]       **
**                                                                            **
** Syntax           : void Port_Init                                          **
**                    (                                                       **
**                      const Port_ConfigType * ConfigPtr                     **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x00                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : ConfigPtr - Pointer to PORT configuration               **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - PORT041: PORT042: Initializes all the ports as per configuration       **
**   - PORT001: This API initializes the whole port structure of MCU          **
**   - PORT003: This API can be used to initialize and reinitialize the       **
**     port with different configuration                                      **
**   - PORT078: This function should be called first in order to initialize   **
**     the port for use                                                       **
**                                                                            **
*******************************************************************************/
void Port_Init ( const Port_ConfigType * ConfigPtr )
{
  #if ((PORT_DEV_ERROR_DETECT == STD_ON) || (PORT_SAFETY_ENABLE == STD_ON))
  uint8 ErrStatus;
  ErrStatus = 0U;
  
  #if(PORT_PB_FIXEDADDR == STD_OFF)
  
  if (ConfigPtr == NULL_PTR)
  {
    
    /* Report PORT_E_PARAM_CONFIG DET */
    #if (PORT_DEV_ERROR_DETECT == STD_ON)  
    Det_ReportError((uint16)PORT_MODULE_ID,PORT_INSTANCE_ID,
        PORT_SID_INIT,PORT_E_PARAM_CONFIG);
    #endif  
    /* PORT087: Skip the API functionality and return from the API */
    
    /* Report a safety error */
    #if (PORT_SAFETY_ENABLE == STD_ON)
    SafeMcal_ReportError ((uint16)PORT_MODULE_ID,PORT_INSTANCE_ID,
                     PORT_SID_INIT,PORT_E_PARAM_CONFIG);
    #endif
        
    ErrStatus = 1U;
  }
  #else
  if (ConfigPtr != Port_kConfigPtr)
  {

    /* Report PORT_E_PARAM_CONFIG DET */
    #if (PORT_DEV_ERROR_DETECT == STD_ON)  
    Det_ReportError((uint16)PORT_MODULE_ID,PORT_INSTANCE_ID,
      PORT_SID_INIT,PORT_E_PARAM_CONFIG);
    #endif  
    /* PORT087: Skip the API functionality and return from the API */
    
    /* Report a safety error */
    #if (PORT_SAFETY_ENABLE == STD_ON)
    SafeMcal_ReportError ((uint16)PORT_MODULE_ID,PORT_INSTANCE_ID,
                     PORT_SID_INIT,PORT_E_PARAM_CONFIG);
    #endif
        
    ErrStatus = 1U;
  }
  #endif /*(PORT_PB_FIXEDADDR == STD_ON)*/
  
  #if (PORT_SAFETY_ENABLE == STD_ON)
  if ((ErrStatus != 1U) &&
      (ConfigPtr->PortMarker != ((uint32)PORT_MODULE_ID << 16U)))
  {
    /* report to upper layer */
    SafeMcal_ReportError ((uint16)PORT_MODULE_ID,PORT_INSTANCE_ID,
                     PORT_SID_INIT,PORT_E_PARAM_CONFIG);
    ErrStatus = 1U;
    
  }
  #endif 
  /*End Of PORT_SAFETY_ENABLE*/
  #endif 
  /*(PORT_DEV_ERROR_DETECT == STD_ON) || (PORT_SAFETY_ENABLE == STD_ON)*/
  
  
  #if ((PORT_DEV_ERROR_DETECT == STD_ON) || (PORT_SAFETY_ENABLE == STD_ON))
  if (ErrStatus == 0U)
  #endif 
  {
    /* PORT002: The function Port_Init() shall also initialize all variables
       used by the PORT driver module to an initial state.
       There are no such variables in the port module
    */
    #if(PORT_PB_FIXEDADDR == STD_OFF)
      Port_kConfigPtr = ConfigPtr; 
    #else
      /* To remove GNU warning of unused parameter ConfigPtr */
      UNUSED_PARAMETER(ConfigPtr)
    #endif  /*(PORT_PB_FIXEDADDR == STD_OFF)*/

    /* Initialise General Purpose I/O Ports and Peripheral I/O Lines */
    Port_lIOInit();

    #if(PORT_DEV_ERROR_DETECT == STD_ON)
    /* Set Status to indicate that initialization is done */
    Port_InitStatus = PORT_INITIALIZED;
    #endif  
  }
}/* Port_Init */


#if (PORT_INIT_CHECK_API == STD_ON)
/*******************************************************************************
** Traceability     : [cover parentID=SAS_MCAL_SWSC_PORT_0402,
                      SAS_MCAL_SWSC_PORT_0405,SAS_MCAL_SWSC_PORT_0406,
                      SAS_MCAL_SWSC_PORT_0407,SAS_MCAL_SWSC_PORT_0431,
                      DS_MCAL_SWSC_PORT_0403,DS_MCAL_SWSC_PORT_0403_1,
                      DS_MCAL_SWSC_PORT_0404,DS_MCAL_SWSC_PORT_0405,
                      DS_MCAL_SWSC_PORT_0406,DS_MCAL_SWSC_PORT_0417]          **
**                                                                            **
** Syntax           : Std_ReturnType Port_InitCheck                           **
**                    (                                                       **
**                      const Port_ConfigType * ConfigPtr                     **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters(in)   : ConfigPtr - Pointer to PORT configuration               **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function checks Port SFR's and Global              **
**                      variables initialized by Port_Init Api                **
**                    This API is available only if PortInitCheckApi is TRUE  **
*******************************************************************************/
Std_ReturnType Port_InitCheck ( const Port_ConfigType * ConfigPtr )
{

  uint8 ErrStatus;
  uint8 ErrPdr;
  uint32 PortNumber;
  /* Index to identify the port configuration information
  from the configuration array  */
  uint8 ConfigIndex;
  Ifx_P  *PortAddressPtr;
  
  const uint32 *DataPtr;
  const Port_n_ConfigType *ConfigDataPtr;
  
  const uint32  *LVDSDataPtr;
  const uint32  *PCSRDataPtr;
  volatile uint32  *PCSRRegPtr;

  uint8 LevelFlag;
  uint8 IocrFlag;

  uint8 LVDSFlag;
  uint8 PCSRFlag;
  
  ErrStatus = E_OK;
  ConfigIndex = 0U;
  LevelFlag = 1U;
  LVDSFlag = 0U;
  PCSRFlag = 1U;
  
    
  if (Port_kConfigPtr != ConfigPtr) 
  {
  
     ErrStatus = E_NOT_OK;
  }
  else
  {

    LVDSDataPtr = (const uint32*)(const void*)
                               (Port_kConfigPtr->Port_LVDSConfigTypePtr);
    
    PCSRDataPtr = (const uint32*)(const void*)
                               (Port_kConfigPtr->Port_PCSRConfigTypePtr);

    for (PortNumber = 0U; PortNumber <= PORT_MAX_NUMBER ; PortNumber++)
    {

      /* Parameter Port is checked for validity */
      if(Port_lIsPortAvailable(PortNumber) != 0U)
      {
        
        /* Check PDR Registers Initialization */
        
        /* Port driver strength is configured in Port PDR0 register */

        PortAddressPtr = Port_lAdr(PortNumber);
        
        ErrPdr = Port_lChkPDR(PortNumber,
        Port_kConfigPtr->PortConfigSetPtr[ConfigIndex].DriverStrength0, 
        Port_kConfigPtr->PortConfigSetPtr[ConfigIndex].DriverStrength1);
        
        if (ErrPdr == 0U)
        {
          ConfigDataPtr = (Port_kConfigPtr->PortConfigSetPtr) + ConfigIndex ;
  
          /* Address of each port configuration */
          DataPtr = (const uint32 *)(const void*)(ConfigDataPtr);
  
        
          /* Check Port Level Registers Initialization */
          
          if(Port_lIsPortReadOnly(PortNumber) == 0U)
          {
            if(PortAddressPtr->OUT.U == (*(DataPtr + PORT_DATA_OFS_LEVEL)))
            {
              LevelFlag = 0U;
            }
          }
          else
          {
             LevelFlag = 0U;
          }
   
          if (LevelFlag == 0U)
          {
            
             /* Check IOCR0,4,8,12 Registers Initialization */
            
             IocrFlag = Port_lChkIocr(PortNumber,DataPtr);      
                
             if (IocrFlag == 0U)
             {
               /* Check Port LVDS and PCSR Registers Initialization */
               if(Port_lIsPortLVDSAvailable(PortNumber) != 0U)
               {
                 LVDSFlag = Port_lChkLVDS(PortNumber,LVDSDataPtr);
                 LVDSDataPtr += PORT_MAX_LPCR_REG;
               }
           
               if(LVDSFlag == 0U)
               {
                 if(Port_lIsPortPCSRAvailable(PortNumber) != 0U)
                 {
                   PCSRRegPtr = ((volatile uint32*)
                                 (volatile void*)PortAddressPtr +
                                  PORT_PCSR_REG_OFFSET);
                   if (*PCSRRegPtr == *PCSRDataPtr)
                   {
                     PCSRFlag = 0U;
                   }
                   PCSRDataPtr++;
                 }
                 /* PCSR is not available then make PCSRFlag as FALSE */
                 else
                 {
                    PCSRFlag = 0U;
                 }
               }
             }
          }
        }    
        /* If LVDSFlag or PCSRFlag as True, then return as error */                                                                 
        if((LVDSFlag != 0U) || (PCSRFlag != 0U))
        {
           ErrStatus = E_NOT_OK;
           break;
        }  
     ConfigIndex++; 
     }

     LevelFlag = 1U;
     PCSRFlag = 1U;
 
     if(PortNumber == PORT_MAX_NUMBER)
     {
       if (P40_PDISC.U != *(Port_kConfigPtr->PDiscSet))
       {
         ErrStatus = E_NOT_OK;
       }
     } 
    } /* For loop */
  } /* Else */
  return(ErrStatus);
}
/*******************************************************************************
** Syntax           : Port_lChkPDR                                            **
**                    (                                                       **
**                      uint32 PortNo,uint32 Data_PDR0, uint32 Data_PDR1      **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Port - Port PDR to be checked                           **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal  0 for OK and 1 for NOT_OK                       **
**                                                                            **
** Description      :                                                         **
** - The function like macro is to check if configured  Port PDR value is     **
**    same as read PDR value                                                  **
*******************************************************************************/
static _INLINE_ uint8 Port_lChkPDR(uint32 PortNo,uint32 Data_PDR0, 
                                   uint32 Data_PDR1)
{
  uint8 ErrPdr = 0U;
  Ifx_P  *PortAddressPtr;
    
  PortAddressPtr = Port_lAdr(PortNo);
  
  if(PortNo < PORT_MAX_NUMBER)
  {
    if(PortAddressPtr->PDR0.U != Data_PDR0)
    {
      ErrPdr = 1U;
    }
  
    if(Port_lIsPortPdr1Available(PortNo) != 0U)
    {
  
      if(PortAddressPtr->PDR1.U != Data_PDR1)
      {
        ErrPdr = 1U;
      }
    }
  }
  return(ErrPdr);
}
/*******************************************************************************
** Syntax           : Port_lChkIocr                                           **
**                    (                                                       **
**                      PortNo,DataPtr                                        **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Port - Port Iocr to be checked                          **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal  0 for OK and 1 for NOT_OK                       **
**                                                                            **
** Description      :                                                         **
** - The function like macro is to check if configured  Port Iocr value is    **
**    same as read Iocr value                                                 **
*******************************************************************************/
static _INLINE_ uint8 Port_lChkIocr(uint32 PortNo,const uint32 *DataPtr)
{
  uint8 RetVal;
  Ifx_P  *PortAddressPtr;
  uint32 Index;
  uint16 PinAvailable;
  uint32 PinMask;
  uint8 PinPosition;
  
  RetVal = 0U;
      
  PortAddressPtr = Port_lAdr(PortNo);
       
  if(Port_lIsPortIocrAvailable(PortNo,(uint16)PORT_PIN_0_3)!= 0U)
  {
    PinPosition = 0U;
    PinMask = 0U; 
    for(Index = 0U; Index<4U ; Index++)
    {
      
       PinAvailable  = Port_lIsPinAvailable(PortNo,Index);
       
       if (PinAvailable)
       {
         PinMask |= ((uint32)0xF8U << PinPosition);
       }
      
      PinPosition += 8U;  
    }
    if((PortAddressPtr->IOCR0.U & PinMask) != ((*DataPtr) & PinMask))
    {
      RetVal = 1U;
    }
  }
  DataPtr++;

  if(Port_lIsPortIocrAvailable(PortNo,(uint16)PORT_PIN_4_7)!= 0U)
  {
    PinPosition = 0U;
    PinMask = 0U;     
    for(Index = 4U; Index<8U ; Index++)
    {
      
       PinAvailable  = Port_lIsPinAvailable(PortNo,Index);
       
       if (PinAvailable)
       {
         PinMask |= ((uint32)0xF8U << PinPosition);
       }
      PinPosition += 8U;          
    } 
    if((PortAddressPtr->IOCR4.U & PinMask) != ((*DataPtr) & PinMask))
    {
      RetVal = 1U;
    } 
  }
  DataPtr++;  
    
  if(Port_lIsPortIocrAvailable(PortNo,(uint16)PORT_PIN_8_11)!= 0U)
  {
    PinPosition = 0U;
    PinMask = 0U;     
    for(Index = 8U; Index<12U ; Index++)
    {
      
       PinAvailable  = Port_lIsPinAvailable(PortNo,Index);
       
       if (PinAvailable)
       {
         PinMask |= ((uint32)0xF8U << PinPosition);
       }
      PinPosition += 8U;
    }
  
    if((PortAddressPtr->IOCR8.U & PinMask) != ((*DataPtr) & PinMask))
    {
      RetVal = 1U;
    }  
  }  
  DataPtr++;   
    
  if(Port_lIsPortIocrAvailable(PortNo,(uint16)PORT_PIN_12_15)!= 0U)
  {
    PinPosition = 0U;
    PinMask = 0U;     
    for(Index = 12U; Index<16U ; Index++)
    {
      
       PinAvailable  = Port_lIsPinAvailable(PortNo,Index);
       
       if (PinAvailable)
       {
         PinMask |= ((uint32)0xF8U << PinPosition);
       }
      PinPosition += 8U;        
    }
    if((PortAddressPtr->IOCR12.U & PinMask) != ((*DataPtr) & PinMask))
    {
      RetVal = 1U;
    }  
  }       

  return(RetVal);
}

/*******************************************************************************
** Syntax           : Port_lChkLVDS                                           **
**                    (                                                       **
**                      PortNo,LVDSDataPtr                                    **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Port - Port LVDS to be checked                          **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal 0 for OK and 1 for NOT_OK                        **
**                                                                            **
** Description      :                                                         **
** - The function like macro is to check if configured  Port Lvds value is    **
**    same as read Lvds value                                                 **
*******************************************************************************/
static _INLINE_ uint8 Port_lChkLVDS(uint32 PortNo,const uint32 *LVDSDataPtr)
{ 
 
  uint8 counter;
  uint8 RetVal;
  volatile uint32 *LVDSRegPtr;
  Ifx_P  *PortAddressPtr;
  
  RetVal = 0U;

  PortAddressPtr = Port_lAdr(PortNo);
  
  /* Check Port LVDS Initialization */
        
    LVDSRegPtr  = ((volatile uint32*)(volatile void*)PortAddressPtr + 
                  PORT_LPCR_REG_OFFSET);
    for(counter = 0U; (counter < PORT_MAX_LPCR_REG); counter++)
    {
      if(Port_lIsPortPinPairAvailable(*LVDSDataPtr) == 0U)
      {
        /* LPCRn */
        if(*LVDSRegPtr != *LVDSDataPtr)
        {
          RetVal = 1U; 
          break;
        }

      }
      LVDSRegPtr++;
      LVDSDataPtr++;
    }

  return(RetVal);   
         
}
#endif

/* Enable / Disable the use of the function */
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
/*******************************************************************************
** Traceability     : [cover parentID=DS_AS_PORT141,DS_AS_PORT086,
                       DS_AS_PORT075_1,
                       DS_MCAL_SWSC_PORT_0416,DS_AS_PORT063,DS_AS_PORT137,
                       DS_AS_PORT101_PORT211_2,DS_AS_PORT107_PORT146_2,
                       DS_AS_PORT087_2,DS_AS_PORT054,DS_AS_PORT213,
                       DS_AS_PORT138,DS_AS_PORT077,DS_NAS_PORT_PR912_1,
                       SAS_MCAL_SWSC_PORT_0411,SAS_MCAL_SWSC_PORT_0415,
                       DS_MCAL_SWSC_PORT_0417, DS_AS_PORT107_PORT146_4,
                       DS_MCAL_SWSC_PORT_0411_1]                              **
**                                                                            **
** Syntax           : void Port_SetPinDirection                               **
**                    (                                                       **
**                      Port_PinType Pin,                                     **
**                      Port_PinDirectionType Direction                       **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x01                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Re-entrant                                              **
**                    (This function shall be re-entrant if accessing         **
**                     different pins, independent of port.)                  **
**                                                                            **
** Parameters (in)  : Pin - port pin ID whose direction has to be set         **
**                    Direction - port pin direction to be set                **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**  - PORT063: sets the port pin direction during runtime                     **
**  - PORT059: This functionality is available for parameter Pin              **
**     whose direction is configured as changeable during run time            **
**  - PORT086: This function is only available if the pre-compiler switch     **
**    PORT_SET_PIN_DIRECTION_API is set STD_ON.                               **
**                                                                            **
*******************************************************************************/
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
{
  /* Each Port Number for the hardware unit  */
  uint32               PortNumber;
  uint32               PinNumber;
  #if ((PORT_DEV_ERROR_DETECT == STD_ON) || (PORT_SAFETY_ENABLE == STD_ON))
  uint8                ErrStatus;
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  uint32               PortAvailable;
  uint32               PortReadOnly;
  uint32               PinAvailable;
  #endif /*PORT_DEV_ERROR_DETECT == STD_ON */
  #endif /*PORT_DEV_ERROR_DETECT == STD_ON) || (PORT_SAFETY_ENABLE == STD_ON */
  uint32               ConfigIndex;
  uint32               Index;
  const uint8         *IocrDataPtr;
  volatile uint8      *IocrRegPtr;
  const uint32        *DataPtr;
  Ifx_P               *PortAddressPtr;
  
  
  #if ((PORT_DEV_ERROR_DETECT == STD_ON) || (PORT_SAFETY_ENABLE == STD_ON))
  ErrStatus = 0U;
  #endif
   
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* Check for DET: PORT_E_UNINIT */
  if (Port_InitStatus != PORT_INITIALIZED)
  {
    /* Report PORT_E_UNINIT DET if Port initialisation is not done */
    Det_ReportError((uint16)PORT_MODULE_ID,PORT_INSTANCE_ID,
        PORT_SID_SETPINDIRECTION,PORT_E_UNINIT);
      
    /* PORT087: Skip the API functionality and return from the API */
  }
  else
  #endif /* PORT_DEV_ERROR_DETECT */
  {
    /* Extract the port number and pin number from the Pin Symbolic ID */
    PortNumber = (uint32)Port_lNumber(Pin);
    PinNumber  = (uint32)Port_lPinNumber(Pin);

    #if ((PORT_DEV_ERROR_DETECT == STD_ON) || (PORT_SAFETY_ENABLE == STD_ON))
    /* PORT077: Function parameters are checked in the order in which they are
               passed.
    */
    /* PORT087: Check if Pin is valid */
   
    #if (PORT_DEV_ERROR_DETECT == STD_ON)
    PortAvailable = Port_lIsPortAvailable(PortNumber);
    PortReadOnly  = Port_lIsPortReadOnly(PortNumber);
   
    PinAvailable = 0U;
    if( PortAvailable != 0U )
    {
      PinAvailable  = Port_lIsPinAvailable(PortNumber,PinNumber);
    }

    if ( (Pin > PORT_MAX_PIN_ID) ||
         ((PortReadOnly != 0U) || (PinAvailable == 0U))
       )
    {
   
      /*Report PORT_E_PARAM_PIN DET if the pin is out of range */
      Det_ReportError((uint16)PORT_MODULE_ID,PORT_INSTANCE_ID,
          PORT_SID_SETPINDIRECTION,PORT_E_PARAM_PIN); 

      ErrStatus = 1U;
   
    }
    #endif
   
    #if (PORT_SAFETY_ENABLE == STD_ON)   
    if(Pin > PORT_MAX_PIN_ID)
    {
      /*Report Safety Error if the pin is out of range */
      SafeMcal_ReportError ((uint16)PORT_MODULE_ID,PORT_INSTANCE_ID,
         PORT_SID_SETPINDIRECTION,PORT_E_PARAM_PIN);
        
      ErrStatus = 1U;
      
    } 
      
   if((Direction != PORT_PIN_IN) && (Direction != PORT_PIN_OUT))
   {
     /*Report Safety Error if the direction is out of range */
     SafeMcal_ReportError ((uint16)PORT_MODULE_ID,PORT_INSTANCE_ID,
                     PORT_SID_SETPINDIRECTION,PORT_E_PARAM_DIRECTION);
     
     ErrStatus = 1U;

   }
   #endif
   #endif /* PORT_DEV_ERROR_DETECT and PORT_SAFETY_ENABLE */
   
   
   #if ((PORT_DEV_ERROR_DETECT == STD_ON) || (PORT_SAFETY_ENABLE == STD_ON))
   if (ErrStatus == 0U)
   #endif
   {
    ConfigIndex = 0U;
    for(Index = 0U;Index < PortNumber;Index++)
    {
      if(Port_lIsPortAvailable(Index) != 0U)
      {
        ConfigIndex++; /* to identify the Index of configuration*/
      }
    }

    /* Get the config data location for specified Port */
    DataPtr =(const uint32*)(const void*)(
              (Port_kConfigPtr->PortConfigSetPtr)+ConfigIndex);

    /*parameter Pin is valid, check for pin direction changeable DET error */
    /*
    PORT059: PORT087: Check if the direction is configured as changeable or not
    */
    if ( ((*(DataPtr + PORT_DATA_OFS_DIR)) & ((uint32)0x01U << PinNumber))
           == PORT_PIN_DIR_NOT_CHANGEABLE
            )
    {
     #if (PORT_DEV_ERROR_DETECT == STD_ON)
       /* Report PORT_E_DIRECTION_UNCHANGEABLE DET if pin is configured for
          direction not changeable
       */
       Det_ReportError(
         (uint16)PORT_MODULE_ID,
         PORT_INSTANCE_ID,
         PORT_SID_SETPINDIRECTION,
         PORT_E_DIRECTION_UNCHANGEABLE);
     #endif /* PORT_DEV_ERROR_DETECT */
    }
    else
    {
     IocrDataPtr = (const uint8*)(const void*)(DataPtr + PORT_DATA_OFS_CTL);

     /* Get Port Address */
     PortAddressPtr = Port_lAdr(PortNumber);
     /* Get the IOCR0 register address of particular port */
     IocrRegPtr = (volatile uint8*)(volatile void*)
                  ((volatile uint32*)(volatile void*)PortAddressPtr + \
                                             PORT_IOCR0_REG_OFFSET);

     if((*(IocrDataPtr + PinNumber) & (uint8)PORT_DIR_MSK)==(uint8)Direction)
     {
       *(IocrRegPtr + PinNumber) = *(IocrDataPtr + PinNumber);
     }
     else
     {
      *(IocrRegPtr + PinNumber) =*((const uint8*)(const void*)
                                   (DataPtr + PORT_DATA_OFS_CTL2)+ PinNumber);
     }
    }
   }
  }
} /* Port_SetPinDirection */
#endif /* Direction changes allowed / Port_SetPinDirection API is ON */

/*******************************************************************************
** Traceability     : [cover parentID=DS_AS_PORT142,DS_AS_PORT075_2,
                        DS_AS_PORT101_PORT211_3,DS_AS_PORT107_PORT146_3,
                        DS_AS_PORT087_3,DS_AS_PORT060_PORT061_PORT066,
                        DS_AS_PORT213,SAS_MCAL_SWSC_PORT_0411,
                        DS_AS_PORT107_PORT146_4,DS_MCAL_SWSC_PORT_0411_2]     **
**                                                                            **
** Syntax           : void Port_RefreshPortDirection ( void )                 **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x02                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : non - reentrant                                         **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - PORT060: PORT061: PORT066: refreshes the direction for all the port    **
**     pins that are configured as direction not changeable during run time   **
**                                                                            **
*******************************************************************************/
void Port_RefreshPortDirection(void)
{
  uint32                LoopCtr;
  /* Each Port Number for the hardware unit  */
  uint32                PortNumber;
  uint32                ConfigIndex;
  #if (PORT_SET_PIN_DIRECTION_API == STD_ON)
  /* Direction changeable allowed */
  uint32                DirectionData;
  uint32                PinPos;
  #endif /* PORT_SET_PIN_DIRECTION_API */
  const uint32          *DataPtr;
  const uint8           *IocrDataPtr;
  volatile uint8        *IocrRegPtr;
  Ifx_P *PortAddressPtr;
  
  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  /* Check for DET: PORT_E_UNINIT */
  if (Port_InitStatus != PORT_INITIALIZED)
  {
    /* Report PORT_E_UNINIT DET if Port initialisation is not done
    */
   Det_ReportError(
      (uint16)PORT_MODULE_ID,
      PORT_INSTANCE_ID,
      PORT_SID_REFRESHPORTDIR,
      PORT_E_UNINIT);
    /* PORT087: Skip the API functionality and return from the API */
  }
  else
  #endif /* (PORT_DEV_ERROR_DETECT) == STD_ON*/
  {
   /* Loop from Port 0 till last Port */
   PortNumber = 0U;
   ConfigIndex = 0U;
   do
   {
     if(Port_lIsPortAvailable(PortNumber) != 0U)
     {
       /* Pointer to the data for the port */
       DataPtr = (const uint32*)(const void*)
                 ((Port_kConfigPtr->PortConfigSetPtr) + ConfigIndex);

       #if (PORT_SET_PIN_DIRECTION_API == STD_ON)
       /* Direction changeable allowed */
       /* Get the direction changeable configuration for all the port pins */
       DirectionData = *(DataPtr + PORT_DATA_OFS_DIR);
       #endif /* PORT_SET_PIN_DIRECTION_API == STD_ON*/
   
       /* Pointer to control data for the first pin */
       IocrDataPtr = (const uint8*)(const void*)(DataPtr + PORT_DATA_OFS_CTL);

       /* Pointer to control register for the first pin */
       /* Get Port Address */
       PortAddressPtr = Port_lAdr(PortNumber);
       /* Get the IOCR0 register address of particular port */
       IocrRegPtr = (volatile uint8*)(volatile void*)
                     ((volatile uint32 *)(volatile void*)PortAddressPtr + \
                                               PORT_IOCR0_REG_OFFSET);

       /* Start from the first pin */
       #if (PORT_SET_PIN_DIRECTION_API == STD_ON)
       PinPos = 0x01U;
       #endif /* PORT_SET_PIN_DIRECTION_API */

       LoopCtr = 0U;
       do
       {
        if(Port_lIsPinAvailable(PortNumber,LoopCtr) != 0U)
        {
          #if (PORT_SET_PIN_DIRECTION_API == STD_ON)
          /* Direction changeable is enabled */
          if ( (DirectionData & PinPos) == PORT_PIN_DIR_NOT_CHANGEABLE)
          {
            /* Direction of the pin cannot be changed during run time */
            /* Write the default value to the control bit fields of the Pin */
            *IocrRegPtr = *IocrDataPtr;
          }
          #else
          /* Direction changeable is disabled */
          /* Write the default value to the control bit fields of the Pin */
          *IocrRegPtr = *IocrDataPtr;
          #endif /* PORT_SET_PIN_DIRECTION_API */
        }
        
        /* Increment to point to the next data set */
        IocrRegPtr++;
        IocrDataPtr++;

        #if (PORT_SET_PIN_DIRECTION_API == STD_ON)
        /* Shift the pin position to next pin */
        PinPos = PinPos << 1U;
        #endif /* PORT_SET_PIN_DIRECTION_API */

        /* Loop for each pin in the port */
        LoopCtr++;
       } while (LoopCtr <= PORT_PIN_MAX_NUMBER ); 

      ConfigIndex++;
     }
    PortNumber++;
   } while (PortNumber <= PORT_MAX_NUMBER); /* Loop for all the ports */
  }
}/* Port_RefreshPortDirection */

/* Enable / Disable the use of the function */
#if (PORT_SET_PIN_MODE_API == STD_ON)
/*******************************************************************************
** Traceability     : [cover parentID=DS_AS_PORT145,DS_AS_PORT125,
                        DS_AS_PORT128,DS_AS_PORT101_PORT211_5,
                        DS_AS_PORT107_PORT146_5,DS_AS_PORT087_5,
                        DS_AS_PORT223,DS_AS_PORT213,DS_AS_PORT077,
                        DS_NAS_PORT_PR912_3,SAS_MCAL_SWSC_PORT_0409,
                        SAS_MCAL_SWSC_PORT_0415,SAS_MCAL_SWSC_PORT_0410,
                        DS_MCAL_SWSC_PORT_0417,DS_MCAL_SWSC_PORT_0409]        **
**                                                                            **
** Syntax           : void Port_SetPinMode                                    **
**                    (                                                       **
**                      Port_PinType Pin,                                     **
**                      Port_PinModeType Mode                                 **
**                    )                                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : 0x04                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Re-entrant                                              **
**                                                                            **
** Parameters (in)  : Pin - port pin ID whose mode has to be set              **
**                    Mode - port pin mode to be set                          **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - PORT125: Sets the port pin mode during runtime.                        **
**   - This function is available if the PORT_SET_PIN_MODE_API is set ON      **
**                                                                            **
*******************************************************************************/
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
{
  /* Each Port Number for the hardware unit  */
  uint32           PortNumber;
  uint32           PinNumber;
  #if ((PORT_DEV_ERROR_DETECT == STD_ON) || (PORT_SAFETY_ENABLE == STD_ON))
  uint32           ErrMode;
  uint8            ErrStatus;
  uint8            Direction;
  uint32           ConfigIndex;
  uint32           Index;
  const uint32     *DataPtr;
  #endif
  volatile uint8  *IocrRegPtr;
  uint8            ReadMode;
  uint8            SetMode;
  Ifx_P           *PortAddressPtr;

  #if ((PORT_DEV_ERROR_DETECT == STD_ON) || (PORT_SAFETY_ENABLE == STD_ON))
  IocrRegPtr = NULL_PTR;
  ConfigIndex = 0U;
  #endif 
  
  /* Extract the port number and pin number from the Pin Symbolic ID */
  PortNumber = (uint32)Port_lNumber(Pin);
  PinNumber  = (uint32)Port_lPinNumber(Pin);

  #if (PORT_DEV_ERROR_DETECT == STD_ON)
  if (Port_InitStatus != PORT_INITIALIZED)
  {
    /* Report PORT_E_UNINIT DET if Port initialisation is not done
    */
    Det_ReportError((uint16)PORT_MODULE_ID,PORT_INSTANCE_ID,
      PORT_SID_SETPINMODE,PORT_E_UNINIT);
    
    ErrStatus = 1U;
  }
  else
  #endif /* PORT_DEV_ERROR_DETECT == STD_ON */
  {
    #if ((PORT_DEV_ERROR_DETECT == STD_ON) || (PORT_SAFETY_ENABLE == STD_ON))
    /* PORT077: Function parameters are checked in the order in which they are
                passed.
    */
    /* PORT087: Check if Pin is valid */
   
    ErrStatus = Port_lChkPin(Pin,PortNumber,PinNumber);
    #endif
        
    #if ((PORT_DEV_ERROR_DETECT == STD_ON) || (PORT_SAFETY_ENABLE == STD_ON))
    if (ErrStatus == 0U)
    #endif
    {
      /* Get Port Address */
      PortAddressPtr = Port_lAdr(PortNumber);
      /* Get the IOCR0 register address of particular port */
      IocrRegPtr = (volatile uint8*)(volatile void*)
                   ((volatile uint32*)(volatile void*)PortAddressPtr + \
                                                 PORT_IOCR0_REG_OFFSET);

      #if ((PORT_DEV_ERROR_DETECT == STD_ON) || (PORT_SAFETY_ENABLE == STD_ON))
      for(Index = 0U; Index < PortNumber;Index++)
      {
        if(Port_lIsPortAvailable(Index) != 0U)
        {
          ConfigIndex++; /* to identify the Index of configuration*/
        }
      }

        /* Get the config data location for specified Port */
      DataPtr =(const uint32*)(const void*)
               ((Port_kConfigPtr->PortConfigSetPtr)+ConfigIndex);

      if ((((*(DataPtr + PORT_DATA_OFS_MODE)) & ((uint32)0x01U << PinNumber))
            == PORT_PIN_MODE_NOT_CHANGEABLE)
         )
      {
        /*PORT223: Report PORT_E_MODE_UNCHANGEABLE DET if the pin is configured
         as mode not changeable */
        #if (PORT_DEV_ERROR_DETECT == STD_ON)    
        Det_ReportError((uint16)PORT_MODULE_ID,PORT_INSTANCE_ID,
          PORT_SID_SETPINMODE,PORT_E_MODE_UNCHANGEABLE);
        #endif

        ErrStatus = 1U;
      }
      else
      {

        Direction = *(IocrRegPtr + PinNumber);
  
        ErrMode = Port_lModeErrChk(Direction, Mode, ConfigIndex, PinNumber);

        if (ErrMode == 1U)
        {
          #if (PORT_DEV_ERROR_DETECT == STD_ON)    
          /* Report PORT_E_PARAM_INVALID_MODE DET if pin mode is not valid */
          Det_ReportError((uint16)PORT_MODULE_ID,PORT_INSTANCE_ID,
            PORT_SID_SETPINMODE,PORT_E_PARAM_INVALID_MODE);
          #endif
            
   
          /*Report Safety Error if the Mode is out of range */
          #if (PORT_SAFETY_ENABLE == STD_ON)
          SafeMcal_ReportError ((uint16)PORT_MODULE_ID,PORT_INSTANCE_ID,
             PORT_SID_SETPINMODE,PORT_E_PARAM_INVALID_MODE);
          #endif
          
          ErrStatus = 1U;
          
        }
      }
      #endif
    }
  }
  
  #if ((PORT_DEV_ERROR_DETECT == STD_ON) || (PORT_SAFETY_ENABLE == STD_ON))
  if (ErrStatus == 0U)
  #endif
  {

    /*Read the IOCR register value for the Pin */
    ReadMode = *(IocrRegPtr + PinNumber);
  
    /* Get the IOCR register value for new Mode */
    SetMode = ((ReadMode & (uint8)PORT_OUT_PIN_MASK) | (uint8)Mode);

    /* Set the new mode in IOCR register */
    *(IocrRegPtr + PinNumber) = SetMode;
  }
}/* Port_SetPinMode */

#if ((PORT_DEV_ERROR_DETECT == STD_ON) || (PORT_SAFETY_ENABLE == STD_ON))
/*******************************************************************************
** Syntax           : static _INLINE_ uint32 Port_lModeErrChk                 **
**                    (                                                       **
**                      uint8 Dir,                                            **
**                      Port_PinModeType Mode,                                **
**                      uint32 ConfigIndex,                                   **
**                      uint32 PinNumber                                      **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Re-entrant                                              **
**                                                                            **
** Parameters (in)  : Dir - Current direction of a pin                        **
**                    Mode - port pin mode to be set                          **
**                    ConfigIndex - Array Index                               **
**                    PinNumber - port pin number                             **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : uint32                                                  **
**                                                                            **
** Description      : This function:                                          **
**   - Checks for the error.                                                  **
**   - This function is available if the PORT_SET_PIN_MODE_API is set ON      **
**                                                                            **
*******************************************************************************/
static _INLINE_ uint32 Port_lModeErrChk
(
  uint8 Dir, Port_PinModeType Mode, uint32 ConfigIndex, uint32 PinNumber
)
{
  uint32 ErrStatus;

  ErrStatus = 0U;
  
  /* parameter Pin is valid, check for the pin valid mode */
  if ((Dir & (uint8)PORT_DIR_MSK) == (uint8)PORT_PIN_IN)
  {
    if (Mode != (Port_PinModeType)PORT_PIN_MODE_GPIO)
    {
      ErrStatus = 1U;
    }
  }
  else if ( (Mode & AVAILABLE_MODE_MASK) != 0U)
  {
    ErrStatus = 1U;
  }
  else
  {
    uint32 Position;        /* Variables for determining if the specified*/
    uint32 Mode_supported;  /* mode is supported or not */
  
    Position = Mode >> PORT_IOCR_PC_POS;
    Mode_supported = (uint32)1U << Position;
  
    if(((uint32)(Port_kConfigPtr->
                  PortPinHwSupportedModes[ConfigIndex].U[PinNumber]) &
          Mode_supported ) == 0U
      )
    {
      ErrStatus = 1U;
    }
  }

  return(ErrStatus);
}
/*******************************************************************************
** Syntax           : static _INLINE_ uint8 Port_lChkPin                      **
**                    (                                                       **
**                      Port_PinType Pin,                                     **
**                      uint32 PortNo,                                        **
**                      uint32 PinNo                                          **
**                    )                                                       **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Re-entrant                                              **
**                                                                            **
** Parameters (in)  : port pin ID whose mode has to be set                    **
**                    PinNo - port pin number                                 **
**                    PortNo - port number                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : uint8 RetVal 0 for OK and 1 for NOT_OK                  **
**                                                                            **
** Description      : This function:                                          **
**   - Checks for the error.                                                  **
**   - This function is available if the PORT_SET_PIN_MODE_API is set ON      **
**                                                                            **
*******************************************************************************/
static _INLINE_ uint8 Port_lChkPin(Port_PinType Pin,uint32 PortNo,uint32 PinNo)
{
  uint8 RetVal;
  #if ((PORT_DEV_ERROR_DETECT == STD_ON) || (PORT_SAFETY_ENABLE == STD_ON)) 
  uint32 PortReadOnly;
  uint32 PinAvailable;
  uint32 PortAvailable;
  #endif
  
  RetVal = 0U;
  #if ((PORT_DEV_ERROR_DETECT == STD_OFF) && (PORT_SAFETY_ENABLE == STD_OFF))
  UNUSED_PARAMETER(PortNo)
  UNUSED_PARAMETER(PinNo)
  #endif
  
  #if ((PORT_DEV_ERROR_DETECT == STD_ON) || (PORT_SAFETY_ENABLE == STD_ON))
    
  PortAvailable = Port_lIsPortAvailable(PortNo);
  PortReadOnly  = Port_lIsPortReadOnly(PortNo);
    
  if( PortAvailable != 0U )
  {
    PinAvailable  = Port_lIsPinAvailable(PortNo,PinNo);
  }
  else
  {
    /* If Port is not available, then Pin also Not available */
    PinAvailable = 0U;
  }


  if ( (Pin > PORT_MAX_PIN_ID) ||
        ((PortReadOnly != 0U) || (PinAvailable == 0U))
     )
  {
  #if (PORT_DEV_ERROR_DETECT == STD_ON)   
    /*Report PORT_E_PARAM_PIN DET if the pin is out of range */
    Det_ReportError((uint16)PORT_MODULE_ID,PORT_INSTANCE_ID,
      PORT_SID_SETPINMODE,PORT_E_PARAM_PIN);
      
  #endif   
      
  #if (PORT_SAFETY_ENABLE == STD_ON)   
    /*Report Safety Error if the pin is out of range */
    SafeMcal_ReportError ((uint16)PORT_MODULE_ID,PORT_INSTANCE_ID,
        PORT_SID_SETPINMODE,PORT_E_PARAM_PIN);
      
  #endif 

  RetVal = 1U;   
  }
 
  #endif  
  
 return(RetVal);
    
}
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
#endif /* (PORT_SET_PIN_MODE_API == STD_ON) */
/*******************************************************************************
** Traceability     : [cover parentID=DS_AS_PORT043_PORT055,
                       DS_AS_PORT001_PORT002_PORT041,DS_AS_PORT214,
                       DS_AS_PORT042]                                         **
**                                                                            **
** Syntax           : static _INLINE_ void Port_lIOInit(void)                 **
**                                                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : None Re-entrant                                         **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - _INLINE_ function to initialize Port registers                         **
**                                                                            **
*******************************************************************************/
static _INLINE_ void Port_lIOInit(void)
{
  const uint32            *DataPtr;
  const Port_n_ConfigType *ConfigDataPtr;
  /* Each Port Number for the hardware unit */
  uint32                   PortNumber;
  /* Each Port level for the hardware unit */
  uint32                   PortLevel;
  /* Index to identify the port configuration information
  from the configuration array  */
  uint32                   ConfigIndex;
  Ifx_P                   *PortAddressPtr;
  const uint32            *LVDSDataPtr;
  const uint32            *PCSRDataPtr;
  volatile uint32         *LVDSRegPtr;
  volatile uint32         *PCSRRegPtr;
  uint32                   counter;

  /* Function call to initialize PDR registers */
  Port_lPDRInit();

  ConfigIndex = 0U;

  LVDSDataPtr = (const uint32*)(const void*)
                               (Port_kConfigPtr->Port_LVDSConfigTypePtr);
    
  PCSRDataPtr = (const uint32*)(const void*)
                               (Port_kConfigPtr->Port_PCSRConfigTypePtr);

  /* writing P_OUT and IOCR registers */
  for (PortNumber = 0U; PortNumber <= PORT_MAX_NUMBER ; PortNumber++)
  {

    if(Port_lIsPortAvailable(PortNumber) != 0U)
    {
      ConfigDataPtr = (Port_kConfigPtr->PortConfigSetPtr) + ConfigIndex ;

      /* Address of each port configuration */
      DataPtr = (const uint32 *)(const void*)(ConfigDataPtr);

      PortAddressPtr = Port_lAdr(PortNumber);

      /*
       PORT043: PORT055: OUT register is written before IOCR bit field to avoid
       the glitches on the pin
      */
      if(Port_lIsPortReadOnly(PortNumber) == 0U)
      {
        PortLevel = (*(DataPtr + PORT_DATA_OFS_LEVEL));
        PortAddressPtr->OMR.U = (uint32)Port_lPinLevel(PortLevel);
      }
      
      if(Port_lIsPortIocrAvailable(PortNumber,(uint16)PORT_PIN_0_3)!= 0U)
      {
        PortAddressPtr->IOCR0.U  = *DataPtr;
      }
      DataPtr++;
      
      if(Port_lIsPortIocrAvailable(PortNumber,(uint16)PORT_PIN_4_7) != 0U)
      {
        PortAddressPtr->IOCR4.U  = *DataPtr;
      }
      DataPtr++;
      
      if(Port_lIsPortIocrAvailable(PortNumber,(uint16)PORT_PIN_8_11)!= 0U)
      {
        PortAddressPtr->IOCR8.U  = *DataPtr;
      }
      DataPtr++;
      
      if(Port_lIsPortIocrAvailable(PortNumber,(uint16)PORT_PIN_12_15)!= 0U)
      {
        PortAddressPtr->IOCR12.U = *DataPtr;
      }

      if(Port_lIsPortLVDSAvailable(PortNumber) != 0U)
      {
         LVDSRegPtr  = ((volatile uint32*)(volatile void*)PortAddressPtr + 
                                          PORT_LPCR_REG_OFFSET);
         for(counter = 0U; (counter < PORT_MAX_LPCR_REG); counter++)
         {
          if(Port_lIsPortPinPairAvailable(*LVDSDataPtr) == 0U)
            {
              Mcal_ResetENDINIT();
              /* LPCRn */
             *LVDSRegPtr = *LVDSDataPtr;
              Mcal_SetENDINIT();
            }
            LVDSRegPtr++;
            LVDSDataPtr++;
         }
      }

      if(Port_lIsPortPCSRAvailable(PortNumber) != 0U)
      {
         PCSRRegPtr = ((volatile uint32*)(volatile void*)PortAddressPtr +
                                         PORT_PCSR_REG_OFFSET);
         Mcal_ResetSafetyENDINIT_Timed(PORT_ENDINIT_TIMEOUT);
         /* PCSRn */
        *PCSRRegPtr = *PCSRDataPtr;
         Mcal_SetSafetyENDINIT_Timed();

         PCSRDataPtr++;
      }

      ConfigIndex++;
    }
  } /* For loop */

  /* Initialize PORT 40 Pad Disable control register */
  /* Reset endinit protect */
  Mcal_ResetENDINIT();
  
  P40_PDISC.U = *(Port_kConfigPtr->PDiscSet);
  
  /* Set endinit protect */
  Mcal_SetENDINIT();
  
}
/*******************************************************************************
** Syntax           : static _INLINE_ void Port_lPDRInit(void)                **
**                                                                            **
** Service ID       : NA                                                      **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : None Re-entrant                                         **
**                                                                            **
** Parameters (in)  : none                                                    **
**                                                                            **
** Parameters (out) : none                                                    **
**                                                                            **
** Return value     : none                                                    **
**                                                                            **
** Description      : This function:                                          **
**   - _INLINE_ function to initialize Port PDR registers                     **
**                                                                            **
*******************************************************************************/
static _INLINE_ void Port_lPDRInit(void)
{
  /* Each Port Number for the hardware unit  */
  uint32                  PortNumber;
  /* Index to identify the port configuration information
  from the configuration array  */
  uint32                  ConfigIndex;
  Ifx_P            *PortAddressPtr;

  ConfigIndex = 0U;
  /* Reset endinit protect */

  /* Port driver strength is configured in Port PDR0 register */
  for (PortNumber = 0U; PortNumber < PORT_MAX_NUMBER ; PortNumber++)
  {
    /* Parameter Port is checked for validity */
    if(Port_lIsPortAvailable(PortNumber) != 0U)
    {
      Mcal_ResetENDINIT();
      PortAddressPtr = Port_lAdr(PortNumber);
      PortAddressPtr->PDR0.U =
        Port_kConfigPtr->PortConfigSetPtr[ConfigIndex].DriverStrength0;

      if(Port_lIsPortPdr1Available(PortNumber) != 0U)
      {
        PortAddressPtr = Port_lAdr(PortNumber);
        PortAddressPtr->PDR1.U =
          Port_kConfigPtr->PortConfigSetPtr[ConfigIndex].DriverStrength1;
      }
      Mcal_SetENDINIT();
      ConfigIndex++;
    }
  }/* For loop */
}
/*******************************************************************************
** Syntax           : Port_lAdr                                               **
**                    (                                                       **
**                      PortNumber                                            **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : PortNumber                                              **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function like macro is to extract the Address of Px_OUT              **
**   register.                                                                **
*******************************************************************************/
static _INLINE_ Ifx_P * Port_lAdr(uint32 PortNumber)
{
  Ifx_P *RetVal;

  RetVal = ( ((Ifx_P *)(void *)&P00_OUT + 
              (((PortNumber / PORT_CONSTANT_10) * PORT_CONSTANT_16) +
              (PortNumber % PORT_CONSTANT_10)))
           );
  return(RetVal);
}


/*******************************************************************************
** Syntax           : Port_lIsPortAvailable31                                 **
**                    (                                                       **
**                      Port                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Port - Port to be checked                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function like macro is to check if the port is available or not      **
**   for the microcontroller.                                                 **
*******************************************************************************/
static _INLINE_ uint32 Port_lIsPortAvailable31(uint32 Port)
{
  uint32 RetVal;

  RetVal = ( ((uint32)(PORT_CONSTANT_0x01) << (Port)) &
             ((uint32)PORTS_AVAILABLE_00_31)
           );
  return(RetVal);
}


/*******************************************************************************
** Syntax           : Port_lIsPortAvailable40                                 **
**                    (                                                       **
**                      Port                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Port - Port to be checked                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function like macro is to check if the port is available or not      **
**   for the microcontroller.                                                 **
*******************************************************************************/
static _INLINE_ uint32 Port_lIsPortAvailable40(uint32 Port)
{
  uint32 RetVal;
  
  RetVal = ( ((uint32)(PORT_CONSTANT_0x01) << (Port - PORT_NUMBER_32)) &
             ((uint32)PORTS_AVAILABLE_32_40)
           );
  return(RetVal);
}


/*******************************************************************************
** Syntax           : Port_lIsPortAvailable                                   **
**                    (                                                       **
**                      Port                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Port - Port to be checked                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function like macro is to check if the port is read only or          **
**   it is writable.                                                          **
*******************************************************************************/
static _INLINE_ uint32 Port_lIsPortAvailable(uint32 Port)
{
  uint32 RetVal;
  
  RetVal = ((Port > PORT_NUMBER_31) ? (Port_lIsPortAvailable40(Port)) :
            (Port_lIsPortAvailable31(Port))
           );
  return(RetVal); 
}

/*******************************************************************************
** Syntax           : Port_lIsPortReadOnly31                                  **
**                    (                                                       **
**                      Port                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Port - Port to be checked                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function like macro is to check if the port is read only or          **
**   it is writable.                                                          **
*******************************************************************************/
static _INLINE_ uint32 Port_lIsPortReadOnly31(uint32 Port)
{
  uint32 RetVal;
  
  RetVal = ( ((uint32)(PORT_CONSTANT_0x01) << (Port)) & 
             ((uint32)PORTS_READONLY_00_31) 
            );
  return(RetVal);
}

/*******************************************************************************
** Syntax           : Port_lIsPortReadOnly40                                  **
**                    (                                                       **
**                      Port                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Port - Port to be checked                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function like macro is to check if the port is read only or          **
**   it is writable.                                                          **
*******************************************************************************/
static _INLINE_ uint32 Port_lIsPortReadOnly40(uint32 Port)
{
  uint32 RetVal;

  RetVal = ( ((uint32)(PORT_CONSTANT_0x01) << (Port - PORT_NUMBER_32)) &
             ((uint32)PORTS_READONLY_32_40)
            );
  return(RetVal);
}

/*******************************************************************************
** Syntax           : Port_lIsPortReadOnly                                    **
**                    (                                                       **
**                      Port                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Port - Port to be checked                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function like macro is to check if the port is read only or          **
**   it is writable.                                                          **
*******************************************************************************/
static _INLINE_ uint32 Port_lIsPortReadOnly(uint32 Port)
{
  uint32 RetVal;
  
  RetVal = ((Port <= PORT_NUMBER_31) ? (Port_lIsPortReadOnly31(Port)) : 
                                         (Port_lIsPortReadOnly40(Port)) 
            );
  return(RetVal);
}

/*******************************************************************************
** Syntax           : Port_lIsPinAvailable                                    **
**                    (                                                       **
**                      Port,Pin                                              **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Port,Pin - Port and Pin to be checked                   **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function like macro is to check if the port pin is available or not  **
**   for the microcontroller.                                                 **
*******************************************************************************/
static _INLINE_ uint16 Port_lIsPinAvailable(uint32 Port,uint32 Pin)
{
  uint16 RetVal;
  
  RetVal = (uint16)( ((uint32)PORT_CONSTANT_0x01 << (Pin)) &
                      (Port_kAvailablePins[(Port)]) 
                   );
  return(RetVal);
}

/*******************************************************************************
** Syntax           : Port_lIsPortPdr1Available                               **
**                    (                                                       **
**                      Port                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Port - Port to be checked                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function like macro is to check if any of the port pin 8 - 15        **
**   is available or not for the microcontroller.                             **
*******************************************************************************/
static _INLINE_ uint16 Port_lIsPortPdr1Available(uint32 Port)
{
  uint16 RetVal;
  
  RetVal = (uint16)(((uint32)(PORT_PDR1_MASK)) & (Port_kAvailablePins[(Port)]));
  return(RetVal);
}

/*******************************************************************************
** Syntax           : Port_lIsPortIocrAvailable                               **
**                    (                                                       **
**                      Port,Pin                                              **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Port,Pin - Port and Pin to be checked                   **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function like macro is to check if the IOCRx register for the port   **
**   is available or not for the microcontroller.                             **
*******************************************************************************/
static _INLINE_ uint16 Port_lIsPortIocrAvailable(uint32 Port,uint16 Pin)
{
  uint16 RetVal;
  
  RetVal = (uint16)( ((uint32)(Pin)) & (Port_kAvailablePins[(Port)]) );
  return(RetVal);
}

#if((PORT_SET_PIN_DIRECTION_API == STD_ON) || (PORT_SET_PIN_MODE_API == STD_ON))
/*******************************************************************************
** Syntax           : Port_lNumber                                            **
**                    (                                                       **
**                      pin                                                   **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Pin                                                     **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - Defines to extract port number Port_PinType data, bit4 to bit 11 (8 bit) **
**   represents the Port Number, to get that value Right shifted              **
**   by 4 and Mask with 0xFF                                                  **
*******************************************************************************/
static _INLINE_ uint32 Port_lNumber(Port_PinType Pin)
{
   uint32 RetVal;
   
   RetVal = (((Pin) >> PORT_NUMBER_OFFSET) & PORT_NUM_LOW8_MASK);
   return(RetVal);
}

/*******************************************************************************
** Syntax           : Port_lPinNumber                                         **
**                    (                                                       **
**                      pin                                                   **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Pin                                                     **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
**  -Defines to extract pin number from Port_PinType data                     **
**   least significant 4-bit represents the Pin Number, to get that           **
**   value Masked with 0x0F                                                   **
*******************************************************************************/
static _INLINE_ uint32 Port_lPinNumber(Port_PinType Pin)
{
   uint32 RetVal;
   
   RetVal = ((Pin) & PORT_PIN_LOW4_MASK);
   
   return(RetVal);
}
#endif

/*******************************************************************************
** Syntax           : Port_lPinLevel                                          **
**                    (                                                       **
**                      level                                                 **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Pin                                                     **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** -OMR register value to set the configured initial level                    **
**  To get the port pin level Masked with 0x0000FFFFU and left shited by 16   **
*******************************************************************************/
static _INLINE_ uint32 Port_lPinLevel(uint32 Level)
{
  uint32 RetVal;
  
  RetVal = ((((~(Level)) & PORT_LOWER_16BIT_MASK) << PORT_16BIT_SHIFTVALUE) |
              (Level)
           );

  return(RetVal);
}

/*******************************************************************************
** Syntax           : Port_lIsPortLVDSAvailable31                             **
**                    (                                                       **
**                      Port                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Port - Port to be checked                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function like macro is to check if the port supports LVDS            **
**   for the microcontroller.                                                 **
*******************************************************************************/
static _INLINE_ uint32 Port_lIsPortLVDSAvailable31(uint32 Port)
{
  uint32 RetVal;

  RetVal = ( ((uint32)(PORT_CONSTANT_0x01) << (Port)) &
             ((uint32)PORTS_LVDS_00_31)
           );
  return(RetVal);
}

/*******************************************************************************
** Syntax           : Port_lIsPortLVDSAvailable40                             **
**                    (                                                       **
**                      Port                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Port - Port to be checked                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function like macro is to check if the port supports LVDS            **
**   for the microcontroller.                                                 **
*******************************************************************************/
static _INLINE_ uint32 Port_lIsPortLVDSAvailable40(uint32 Port)
{
  uint32 RetVal;
  
  RetVal = ( ((uint32)(PORT_CONSTANT_0x01) << (Port - PORT_NUMBER_32)) & 
             ((uint32)PORTS_LVDS_32_40)
           );
  return(RetVal);
}

/*******************************************************************************
** Syntax           : Port_lIsPortLVDSAvailable                               **
**                    (                                                       **
**                      Port                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Port - Port to be checked                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function like macro is to check if the port supports LVDS            **
**   for the microcontroller.                                                 **
*******************************************************************************/
static _INLINE_ uint32 Port_lIsPortLVDSAvailable(uint32 Port)
{
  uint32 RetVal;
  
  RetVal = ((Port > PORT_NUMBER_31) ? (Port_lIsPortLVDSAvailable40(Port)) :
            (Port_lIsPortLVDSAvailable31(Port))
           );
  return(RetVal); 
}


/*******************************************************************************
** Syntax           : Port_lIsPortPCSRAvailable31                             **
**                    (                                                       **
**                      Port                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Port - Port to be checked                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function like macro is to check if the port supports PCSR            **
**   for the microcontroller.                                                 **
*******************************************************************************/
static _INLINE_ uint32 Port_lIsPortPCSRAvailable31(uint32 Port)
{
  uint32 RetVal;

  RetVal = ( ((uint32)(PORT_CONSTANT_0x01) << (Port)) &
             ((uint32)PORTS_PCSR_00_31)
           );
  return(RetVal);
}

/*******************************************************************************
** Syntax           : Port_lIsPortPCSRAvailable40                             **
**                    (                                                       **
**                      Port                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Port - Port to be checked                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function like macro is to check if the port supports PCSR            **
**   for the microcontroller.                                                 **
*******************************************************************************/
static _INLINE_ uint32 Port_lIsPortPCSRAvailable40(uint32 Port)
{
  uint32 RetVal;
  
  RetVal = ( ((uint32)(PORT_CONSTANT_0x01) << (Port - PORT_NUMBER_32)) & 
             ((uint32)PORTS_PCSR_32_40)
           );
  return(RetVal);
}

/*******************************************************************************
** Syntax           : Port_lIsPortPCSRAvailable                               **
**                    (                                                       **
**                      Port                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : Port - Port to be checked                               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function like macro is to check if the port supports PCSR            **
**   for the microcontroller.                                                 **
*******************************************************************************/
static _INLINE_ uint32 Port_lIsPortPCSRAvailable(uint32 Port)
{
  uint32 RetVal;
  
  RetVal = ((Port > PORT_NUMBER_31) ? (Port_lIsPortPCSRAvailable40(Port)) :
            (Port_lIsPortPCSRAvailable31(Port))
           );
  return(RetVal); 
}

/*******************************************************************************
** Syntax           : Port_lIsPortPinPairAvailable                            **
**                    (                                                       **
**                      Port                                                  **
**                    )                                                       **
**                                                                            **
** Service ID       : None                                                    **
**                                                                            **
** Sync/Async       : Synchronous                                             **
**                                                                            **
** Reentrancy       : Non reentrant                                           **
**                                                                            **
** Parameters (in)  : PortLPCRvalue: Port LPCR Reg value to be checked        **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Return value     : RetVal                                                  **
**                                                                            **
** Description      :                                                         **
** - The function like macro is to check if the portpinpair for lvds is       **
**     avialable for the microcontroller.                                     **
*******************************************************************************/
static _INLINE_ uint32 Port_lIsPortPinPairAvailable(uint32 PortLPCRvalue)
{
  uint32 RetVal;
  
  RetVal = ( (PortLPCRvalue >> (uint32)16) & 0xFFFFU );
  return(RetVal); 
}

/*Memory Map of the PORT Code*/
#define PORT_STOP_SEC_CODE
#include "MemMap.h"
