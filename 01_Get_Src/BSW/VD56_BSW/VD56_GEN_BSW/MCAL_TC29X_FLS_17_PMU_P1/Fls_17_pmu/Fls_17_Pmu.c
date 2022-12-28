/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Fls_17_Pmu.c $                                             **
**                                                                           **
**  $CC VERSION : \main\70 $                                                 **
**                                                                           **
**  $DATE       : 2013-11-08 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION  : This file contains                                        **
**                 - functionality of Flash driver                           **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/
/******************************************************************************
   Traceability:
                 [cover parentID=SAS_AS_FLS107_FLS159,DS_AS_FLS208,
                  DS_AS_FLS267,DS_AS_FLS006_FLS260_FLS261,DS_NAS_PR912_1,
                  DS_NAS_PR912_2,DS_NAS_PR912_3,DS_NAS_PR624_PR759_PR760_PR761,
                  DS_NAS_PR919,DS_NAS_PR228]
                 [/cover]
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "IfxFlash_reg.h"

#include "IfxSrc_reg.h"

/* Inclusion of Mcal Specific Global Header File */
#include "Mcal.h"

/* Inclusion of Flash header file */
#include "Fls_17_Pmu.h"

/* Inclusion of Flash command cycles file */
#include "Fls_17_Pmu_ac.h"

/* Inclusion of Fls_17_Pmu module's local header file */
#include "Fls_17_Pmu_Local.h"

/*
 the macro FLS_RAM_EMULATION_TEST should be defined
 in Fls_17_Pmu_Cfg.h
 */
#ifdef FLS_RAM_EMULATION_TEST
#if (FLS_RAM_EMULATION_TEST == 1U)
#include "FlsEmulation.h"
#endif
#endif

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/*
For internal debugging, this macro maps the FSR bitfields to RAM for error
simulation
*/
#ifdef IFX_FLS_DEBUG
  extern volatile uint32 TestFls_DebugMask;
#endif
#ifdef IFX_FLS_DEBUG03
  extern volatile uint32 TestFls_DebugMask03;
#endif
#ifdef IFX_FLS_DEBUG04
  extern volatile uint32 TestFls_DebugMask04;
#endif
#ifdef IFX_FLS_DEBUG07
  extern volatile uint32 TestFls_DebugMask07;
#endif
#ifdef IFX_FLS_DEBUG08
  extern volatile uint32 TestFls_DebugMask08;
#endif

#define ZERO_VALUE               (0U)
#define TWO_VALUE                (2U)
#define THREE_VALUE              (3U)
#define FOUR_VALUE               (4U)

#define FLS_OPER_BIT_POSITION    (11U)

/* Linear Adress for data flash bank 0 */
#define DFLASH_BANK0_LINEAR      (FLS_BASE_ADDRESS + FLS_SECTOR_STARTADDRESS)

/* Linear Adress for data flash bank 1 */
#define DFLASH_BANK1_LINEAR      (DFLASH_BANK0_LINEAR + FLS_SECTOR_SIZE)

/* Page size mask used for checking if address is page aligned*/
/* ASSUMPTIONS : Page size is of the format 2^y ; y is a whole number */
#define PAGE_SIZE_MASK        (FLS_PAGE_SIZE-1U)  /* MOD_128 */

/* Protection and sequence errors */
#define FLS_PROER_SQER_ERROR   (0x00003000U)
/* Protection and sequence errors */
#define FLS_PVER_ERROR         (0x02000000U)
/* Operational error */
#define FLS_OPER_ERROR         (0x00000800U)
/* Uncorrectable bit error */
#define FLS_BIT_ERROR          (0x00200000U)
/* Dflash busy status */
#define FLS_D0BUSY             (0x00000002U)
/* FCON register setting */
#define FLS_FCON_SETTING       (0xFFFF803FU)
/* Disable traps on Uncorrectable errors */
#define FLS_MARD_TRAP          (0x00008000U)
/* SPND bit in MARD register */
#define FLS_MARD_SPND          (0x00000008U)

/* Word size - 4 bytes */
#define FLS_WORD_SIZE          (4U)
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

#define FLS_17_PMU_START_SEC_CODE
#include "MemMap.h"

static void Fls_lMainErase(uint8 BankType);

static void Fls_lMainWrite(uint8 BankType);

static void Fls_lMainRead(uint8 BankType);

static void Fls_lMainCompare(uint8 BankType);

static void Fls_lErrorHandler(uint8 JobType);

#if(FLS_AC_LOAD_ON_JOB_START == STD_ON)
static void Fls_lLoadAccessCode(uint8 JobRequest);

static void Fls_lUnLoadAccessCode(uint8 JobRequest);
#endif

static _INLINE_ boolean Fls_lSpndTimeout(uint32 TimeOutCount);

static _INLINE_ boolean Fls_lResmErTimeout(uint32 TimeOutCount);

static _INLINE_ boolean Fls_lPverChk(void);

#if (FLS_DEV_ERROR_DETECT == STD_ON)
static _INLINE_ uint8 Fls_lBusyDET_Read(const Fls_17_Pmu_StateType* StatePtr);

static _INLINE_ uint8 Fls_lBusyDET_Write(const Fls_17_Pmu_StateType* StatePtr);

static _INLINE_ uint8 Fls_lBusyDET_Erase(const Fls_17_Pmu_StateType* StatePtr);

static _INLINE_ uint8 Fls_lBusyDET_Compare
                                         (const Fls_17_Pmu_StateType* StatePtr);

static uint8 Fls_lUninitDET(const uint8 ServiceID);

static uint8 Fls_lTimeOutDET(const uint8 ServiceID);

static _INLINE_ void Fls_lCalculateWriteTimeoutCount(void);

static _INLINE_ Std_ReturnType Fls_lPageEraseCheck(const uint32 * AddrCheckPtr,
                                                   uint32 Length,
                                                   const uint8 ServiceID);

#if (FLS_IFX_FEE_USED == STD_OFF)
static _INLINE_ boolean Fls_lCheckWrittenPage(uint32 PageLength);
#endif

#endif /* End of FLS_DEV_ERROR_DETECT */

/*Check for command sequence error and protection error*/
static _INLINE_ uint32 Fls_lChkSeqProtErrors(void);

/*Check for operational error */
static _INLINE_ uint32 Fls_lChkOperError(void);

/*Check for double bit errors (DBER) */
static _INLINE_ uint32 Fls_lChkBitErrors(void);

/* Return the Busy status of the Data Flash Bank */
/* FLASH0_FSR.U & (1U<< (1U + (Bank) ) */
static _INLINE_ uint32 Fls_lHWBusyCheck(void);

/* get the write mode , page mode or burst mode */
static _INLINE_ uint8 Fls_lGetWriteMode(void);

/* Get max read length according to the FLS mode */
static _INLINE_ Fls_LengthType Fls_lGetReadModeLength(void);

#define FLS_17_PMU_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
#if (FLS_PB_FIXEDADDR == STD_OFF)


#define FLS_17_PMU_START_SEC_VAR_32BIT
#include "MemMap.h"
const Fls_17_Pmu_ConfigType *Fls_ConfigPtr;
#define FLS_17_PMU_STOP_SEC_VAR_32BIT
#include "MemMap.h"

#else

#define FLS_17_PMU_START_SEC_CONST_32BIT
#include "MemMap.h"
const Fls_17_Pmu_ConfigType * const Fls_ConfigPtr = &Fls_17_Pmu_ConfigRoot[0];
#define FLS_17_PMU_STOP_SEC_CONST_32BIT
#include "MemMap.h"


#endif

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define FLS_17_PMU_START_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
** Traceability : [cover parentID=DS_AS_FLS249,DS_AS_FLS351,DS_AS_FLS014,
   DS_AS_FLS191,DS_AS_FLS086,DS_AS_FLS323_FLS324,DS_AS_FLS268,
   DS_NAS_PR913,DS_NAS_PR734_1]
                 [/cover]
********************************************************************************
** Syntax : void Fls_17_Pmu_Init(const Fls_17_Pmu_ConfigType* ConfigPtr)      **
**                                                                            **
** Service ID:  0                                                             **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  ConfigPtr - Pointer to configuration set                **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Driver Module Initialization function                        **
** FLS014: Service for FLASH initialization. The Initialization function shall**
** initialize all Flash relevant registers with the values of the structure   **
** referenced by the parameter ConfigPtr.                                     **
**                                                                            **
*******************************************************************************/
void Fls_17_Pmu_Init(const Fls_17_Pmu_ConfigType* ConfigPtr)
{
  Fls_17_Pmu_StateType  *StatePtr;
  uint32 FconReg;
  uint32 DummyRetVal;

  #if( FLS_DEV_ERROR_DETECT == STD_ON )
  /*
  FLS015: ConfigPtr shall not be NULL pointer
  */
  #if (FLS_PB_FIXEDADDR == STD_OFF)
  if (ConfigPtr == NULL_PTR)
  #else
  if (ConfigPtr != &Fls_17_Pmu_ConfigRoot[0])
  #endif
  {
    Det_ReportError( (uint16)FLS_17_PMU_MODULE_ID, 
                     FLS_17_PMU_INSTANCE_ID,FLS_SID_INIT,
                      FLS_E_PARAM_CONFIG);/* Report to DET */
  }   
  /* Check if the driver is BUSY */
  else if( ( ConfigPtr->FlsStateVarPtr->FlsJobType[0] != FLS_NONE) ||
         ( ConfigPtr->FlsStateVarPtr->FlsJobType[1] != FLS_NONE ) )
  {
    Det_ReportError( (uint16)FLS_17_PMU_MODULE_ID, 
                     FLS_17_PMU_INSTANCE_ID,FLS_SID_INIT,
                      FLS_E_BUSY);/* Report to DET */
  }
  else
  /* FLS_DEV_ERROR_DETECT */
  #endif

  {
    /*  ------------------------------------------------------------------ **
    **                 Flash Module Initialization                         **
    **  ------------------------------------------------------------------ */
    /*
    FLS014: Initialization of flash driver and its relevant registers
    */
    /* Store the configuration pointer */
    #if (FLS_PB_FIXEDADDR == STD_OFF)
    Fls_ConfigPtr = (Fls_17_Pmu_ConfigType *)(void *)ConfigPtr;
    #else
    Fls_ConfigPtr->FlsStateVarPtr->DriverInitialised = (boolean)TRUE;
    #endif
 
    Fls_ResetReadCmdCycle();
    
    /* Enter Critical Section */
    Fls_lSchMEnter_Init();
 
    /* Reset End Init Protection to access regsiters */
    Mcal_ResetENDINIT();
 
    /* Clear the wait state setting for DFLash and Set Dflash Waitstates
       according to configuration  */
    FconReg = (uint32)FLASH0_FCON.U;
    FconReg &= FLS_FCON_SETTING;
    FconReg |= ((unsigned_int)(ConfigPtr->FlsWaitStates));
    FLASH0_FCON.U = (unsigned_int)FconReg;
 
    #if( FLS_USE_INTERRUPTS == STD_ON)
    /* Enable End of Busy Interrupt Mask */
    FLASH0_FCON.B.EOBM = 1U;
    #endif
 
    /* Disable traps on Uncorrectable errors */
    FLASH0_MARD.U |= FLS_MARD_TRAP;
 
     /* Set End Init Protection */
    Mcal_SetENDINIT();
 
    /* Exit Critical Section */
    Fls_lSchMExit_Init(); 
 
    #if( FLS_USE_INTERRUPTS == STD_ON)
    SRC_PMU00.B.SRE =1U;
    #endif
    
    /*  ------------------------------------------------------------------ **
    **                 Global Variable Initialization                      **
    **  ------------------------------------------------------------------ */
    /*
     After having finished the module initialization,
     the Flash Driver state shall be set to FLS_IDLE and and the jobs result
     shall be set to FLS_JOB_OK.
    */
    StatePtr = ConfigPtr->FlsStateVarPtr;
 
    /*Set JobResult to ok  */
    StatePtr->FlsJobResult = MEMIF_JOB_OK;
 
    /* Setting the Jobtype of bank0,1 to none */
    StatePtr->FlsJobType[BANK0] = FLS_NONE;
    StatePtr->FlsJobType[BANK1] = FLS_NONE;
    
    /* Assign default mode */
    StatePtr->FlsMode = Fls_lSetDefaultMode();

    /* Initialize OPER status */
    StatePtr->FlsOper = 0U;

    /* Check for OPER and update FlsOper accordingly */
    DummyRetVal = Fls_lChkOperError();

    /* FlsOper will be updated by Fls_lChkOperError() */
    UNUSED_PARAMETER(DummyRetVal)
  }
}/* End of Function: Fls_Init */

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_FLS250_FLS001_1,DS_AS_FLS218_221,
   DS_AS_FLS327,DS_AS_FLS328_FLS329,DS_AS_FLS330,DS_AS_FLS145,DS_AS_FLS209_1,
   DS_AS_FLS020_FLS021_FLS065_FLS023,DS_NAS_PR734_2,DS_NAS_PR1058_1]
                 [/cover]
********************************************************************************
** Syntax : Std_ReturnType Fls_17_Pmu_Erase( Fls_AddressType TargetAddress,   **
**                                    Fls_LengthType Length                   **
**                                  )                                         **
**                                                                            **
** Service ID:  1                                                             **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  TargetAddress and Length                                **
**                                                                            **
** Parameters (out): E_OK: command has been accepted                          **
**                   E_NOT_OK: command has not been accepted                  **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Erasing the given flash sector                               **
** FLS018: Service for erasing one or more complete flash sectors.This service**
** Copies the given parameters to driver internal variables,initiate a        **
** erase job,set driver status to MEMIF_E_BUSY and job result to              **
** MEMIF_JOB_PENDING.                                                         **
*******************************************************************************/
Std_ReturnType Fls_17_Pmu_Erase( Fls_AddressType TargetAddress,
                          Fls_LengthType Length
                        )
{
  Fls_17_Pmu_StateType*   StatePtr;
  volatile uint32  PhysicalAddress;
  uint8            JobType[2U];
  Std_ReturnType   ReturnValue;

/******************************* DET ******************************************/
  #if  ( FLS_DEV_ERROR_DETECT == STD_ON )
    /* FLS015: API  called before initialization */
  if(Fls_lUninitDET(FLS_SID_ERASE) == 1U)
  {
    ReturnValue = E_NOT_OK;
  }

  /* FLS020: Checking whether given TargetAddress is valid or not */
  else if(!(((FLS_BASE_ADDRESS+(uint32)TargetAddress) == DFLASH_BANK0_LINEAR) ||
        ((FLS_BASE_ADDRESS+(uint32)TargetAddress) == DFLASH_BANK1_LINEAR)))
  {
    Det_ReportError( (uint16)FLS_17_PMU_MODULE_ID, 
                     FLS_17_PMU_INSTANCE_ID,
                     FLS_SID_ERASE,
                     FLS_E_PARAM_ADDRESS);/* Report to DET */

    ReturnValue = E_NOT_OK;
  }
  /* FLS021: Checking whether given Length is valid or not */
  else if( (Length == (Fls_LengthType)0) ||
      (!(((TargetAddress + Length) == FLS_SECTOR_SIZE) ||
       ((TargetAddress + Length) == FLS_TOTAL_SIZE))))
  {
    Det_ReportError( (uint16)FLS_17_PMU_MODULE_ID, 
                      FLS_17_PMU_INSTANCE_ID,FLS_SID_ERASE,
                      FLS_E_PARAM_LENGTH);/* Report to DET */

    ReturnValue = E_NOT_OK;
  }
  else
  /* FLS_DEV_ERROR_DETECT */
  #endif

  {
    /* Initialise Local variables */
    StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
    /*By Default set the physical address to bank0 */
    PhysicalAddress = DFLASH_BANK0_PHYSICAL;
  
    JobType[0] = FLS_NONE;
    JobType[1] = FLS_NONE;
  
    /* Check for the bank type */
    if((TargetAddress + Length) <= FLS_SECTOR_SIZE)
    {
      /* Set the job type of Bank0 to Flash erase */
      JobType[0] = FLS_ERASE;
    }
    else if(TargetAddress == FLS_SECTOR_SIZE)
    {
      /* Set the job type of Bank1 to Flash erase */
      JobType[1] = FLS_ERASE;
      /*Set the physical address to bank1 */
      PhysicalAddress = DFLASH_BANK1_PHYSICAL;
    }
    else
    {
      /* Set the job type of both the Bank's to Flash erase */
      JobType[0] = FLS_ERASE;
      JobType[1] = FLS_ERASE;
    }
   
    /* Check for the BUSY DET */
    #if  ( FLS_DEV_ERROR_DETECT == STD_ON )
    if(Fls_lBusyDET_Erase(StatePtr) == 1U)
    {
      ReturnValue = E_NOT_OK;
    }
    else
    #endif /* FLS_DEV_ERROR_DETECT  == STD_ON*/
    {
      ReturnValue = E_OK;
  
      /* Check for hardware status and OPER error status */
      if(Fls_lHWBusyCheck() == 0U)
      {
        if(Fls_lChkOperError() == 0U)
        {
          #if(FLS_AC_LOAD_ON_JOB_START == STD_ON )
          Fls_lLoadAccessCode(FLS_ERASE);
          #endif
         
          /* 1. Set the flash job result to job pending */
          StatePtr->FlsJobResult = MEMIF_JOB_PENDING;
         
          /* 2. Update the new job on affected banks */
          /* The Bit OR operation is used as either s->FlsJobType[x] or */
          /* NewJobType[x] must be FLS_NONE else BUSY DET would have occured*/
          StatePtr->FlsJobType[0] |= JobType[0];
          StatePtr->FlsJobType[1] |= JobType[1];
    
          /* 3. Indicate that the ERASE Job has been started */
          StatePtr->JobStarted.U8 |= FLS_ERASE_JOBSTART;
      
          /* FLS_RAM_EMULATION_TEST */
          #ifdef FLS_RAM_EMULATION_TEST
          #if (FLS_RAM_EMULATION_TEST == 1U)
          if(FlsEmulation_EraseSyncError() != 0)
          {
            (void) FlsEmulation_Erase(PhysicalAddress);
          }
          else
          #endif
          #endif
          {
            /* Enter Critical Section */
            Fls_lSchMEnter_Erase();
            
            /* Execute the ERASE COMMAND CYCLES */
            Fls_CallEraseCommand(PhysicalAddress);
            
            /* Exit Crtical Section */
            Fls_lSchMExit_Erase();
          }
     
          /* Check for Sequence error,Protection error  */
          if(Fls_lChkSeqProtErrors())
          {
            ReturnValue = E_NOT_OK;
     
            /* Report Production errors to DEM */
            Fls_lDemReportError_Erase();
     
            Fls_lErrorHandler(FLS_ERASE);    
          }
          
          /* Check for command cycle Timeout */
          if (StatePtr->FlsTimeoutErr == FLS_ERASE)
          {
            /* Call to Fls_lErrorHandler local function */
            if(ReturnValue == E_OK)
            {
              Fls_lErrorHandler(FLS_ERASE);
            }
            ReturnValue = E_NOT_OK;
          }
     
          #if (FLS_DEV_ERROR_DETECT == STD_ON)
          else
          {
            /* Update Timeout count for erase */
            StatePtr->FlsEraseTimeoutCycleCount = 
                  (uint32)(FLS_17_PMU_ERASE_TIME / Fls_ConfigPtr->FlsCallCycle);
            if((FLS_17_PMU_ERASE_TIME % Fls_ConfigPtr->FlsCallCycle) != 0U)
            {
              StatePtr->FlsEraseTimeoutCycleCount++;
            }
            /* for erasing 2 sectors the count has to be doubled */
            if((JobType[0] == FLS_ERASE) && (JobType[1] == FLS_ERASE))
            {
              StatePtr->FlsEraseTimeoutCycleCount *= 2U;
            }
          }
          #endif /* FLS_DEV_ERROR_DETECT == STD_ON */
        }
        else
        {
          ReturnValue = E_NOT_OK;
        }
      }
      else
      {
        ReturnValue = E_NOT_OK;
      }
    }
  }
  return(ReturnValue);
}


/*******************************************************************************
** Traceability : [cover parentID=DS_AS_FLS223,DS_AS_FLS226,
DS_AS_FLS251_FLS001_2, DS_AS_FLS331_FLS332_FLS333,DS_AS_FLS334,DS_AS_FLS146,
DS_AS_FLS026_FLS027_FLS030_FLS066_FLS157,DS_AS_FLS209_2,
DS_NAS_PR734_3,DS_NAS_PR1058_2,DS_NAS_PR1068_1,DS_NAS_PR1068_2]
                 [/cover]
********************************************************************************
** Syntax : Std_ReturnType Fls_17_Pmu_Write( Fls_AddressType TargetAddress,   **
**                                    const uint8 *SourceAddressPtr,          **
**                                    Fls_LengthType Length                   **
**                                  )                                         **
**                                                                            **
** Service ID:  2                                                             **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :SourceAddressPtr,TargetAddress and Length                 **
**                                                                            **
** Parameters (out): E_OK: command has been accepted                          **
**                   E_NOT_OK: command has not been accepted                  **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Writing to given flash address.                              **
** FLS024: Service for writing one or more complete flash pages.This service  **
** shall Copies the given parameters to driver internal variables,initiate a  **
** Write job,set driver status to MEMIF_E_BUSY and job result to              **
** MEMIF_JOB_PENDING.                                                         **
*******************************************************************************/
Std_ReturnType Fls_17_Pmu_Write( Fls_AddressType TargetAddress,
                          const uint8 *SourceAddressPtr,
                          Fls_LengthType Length
                        )
{
  Fls_17_Pmu_StateType   *StatePtr;
  volatile uint32 PhysicalAddress;
  uint32          *PageStartAddressPtr;
  Std_ReturnType  RetVal;
  uint8           WriteMode;
  uint8            JobType[2];

  RetVal = E_OK;
/******************************* DET ******************************************/
  #if  ( FLS_DEV_ERROR_DETECT == STD_ON )
    /* FLS015: API  called before initialization */
  if(Fls_lUninitDET(FLS_SID_WRITE) == 1U)
  {
    RetVal = E_NOT_OK;
  }

  /* FLS026: Checking whether given TargetAddress is valid or not */
  else if( (TargetAddress > (FLS_TOTAL_SIZE - FLS_PAGE_SIZE)) ||
         ((TargetAddress & PAGE_SIZE_MASK) != 0U) )
  {
    Det_ReportError( (uint16)FLS_17_PMU_MODULE_ID, 
                     FLS_17_PMU_INSTANCE_ID,FLS_SID_WRITE,
                     FLS_E_PARAM_ADDRESS);/* Report to DET */

    RetVal = E_NOT_OK;
  }
  /* FLS027: Checking whether given Length is valid or not */
  else if((Length == 0U) || (((Length & PAGE_SIZE_MASK) != 0U)
          || ((TargetAddress + Length) > FLS_TOTAL_SIZE)))
  {
    Det_ReportError( (uint16)FLS_17_PMU_MODULE_ID, 
                     FLS_17_PMU_INSTANCE_ID,FLS_SID_WRITE,
                     FLS_E_PARAM_LENGTH);/* Report to DET */

    RetVal = E_NOT_OK;
  }
  /* FLS004: Check for Pointer to an application buffer */
  else if(SourceAddressPtr == NULL_PTR)
  {
    Det_ReportError( (uint16)FLS_17_PMU_MODULE_ID, 
                      FLS_17_PMU_INSTANCE_ID,FLS_SID_WRITE,
                     FLS_E_PARAM_DATA);/* Report to DET */

    RetVal = E_NOT_OK;
  }
  else
  /* FLS_DEV_ERROR_DETECT */
  #endif
/******************************************************************************/
  {
    /* Initialise Local variables */
    StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
    JobType[0] = FLS_NONE;
    JobType[1] = FLS_NONE;

    /* PVER check for IFX FEE, clear FlsPver */
    #if(FLS_VER_ERROR_CHECK == STD_ON)
    #if(FLS_IFX_FEE_USED == STD_ON)
    StatePtr->FlsPver = 0U;
    #endif
    #endif

    /* Check for whether write operation is only for Data Bank0 */
    if((TargetAddress + Length) <= FLS_SECTOR_SIZE)
    {
      /*Assign jobtype of Data Bank0 to write */
      JobType[0] = FLS_WRITE;
  
      /* Determine the page start address */
      PageStartAddressPtr = (uint32*)(FLS_BASE_ADDRESS + TargetAddress);
  
      /* Setting the PhysicalAddress to DataBank0 */
      PhysicalAddress = DFLASH_BANK0_PHYSICAL;
    }
    /* Check for whether write operation is only for Data Bank1 */
    else if((TargetAddress) >= FLS_SECTOR_SIZE)
    {
      /*Assign jobtype of Data Bank1 to write */
      JobType[BANK1] = FLS_WRITE;
      /* Setting the PageStartAddress to DataBank1 PageAddress */
      PageStartAddressPtr = (uint32*)( FLS_BASE_ADDRESS +
                                   (TargetAddress - FLS_SECTOR_SIZE) +
                                   FLS_OFFSET );
  
      /* Setting the PhysicalAddress to DataBank1 */
      PhysicalAddress = DFLASH_BANK1_PHYSICAL;
    }
    else
    {
      /* Assign jobtype of both the banks to write */
      JobType[BANK0] = FLS_WRITE;
      JobType[BANK1] = FLS_WRITE;
  
      /* Determine the page start address */
      PageStartAddressPtr = (uint32*)(FLS_BASE_ADDRESS + TargetAddress);
  
      /* Setting the PhysicalAddress to DataBank0 */
      PhysicalAddress = DFLASH_BANK0_PHYSICAL;
    }
  
  /******************************* DET ****************************************/
    /* Check for the BUSY DET */
    #if  ( FLS_DEV_ERROR_DETECT == STD_ON )
    /*If DET occurred then return without executing the routine.*/
    if(Fls_lBusyDET_Write(StatePtr) == 1U)
    {
      RetVal = E_NOT_OK;
    } 
    /***** Check for Flash Page value equal to zero ****/
    #if (FLS_IFX_FEE_USED == STD_OFF)
    
    else if(Fls_lPageEraseCheck(PageStartAddressPtr,Length,FLS_SID_WRITE) == 
                                                                      E_NOT_OK)
    {
      Fls_lErrorHandler(FLS_WRITE);
      RetVal = E_NOT_OK;
    } 
    #endif /*FLS_IFX_FEE_USED*/
    else
    #endif /* FLS_DEV_ERROR_DETECT */
  /***************************************************************************/
    {
      /* Check for hardware status and OPER error status */
      if(Fls_lHWBusyCheck() == 0U)
      {
        if(Fls_lChkOperError() == 0U)
        {
          #if( FLS_AC_LOAD_ON_JOB_START == STD_ON)
          Fls_lLoadAccessCode(FLS_WRITE);
          #endif
        
          /* 1. Set the flash job result to job pending */
          StatePtr->FlsJobResult = MEMIF_JOB_PENDING;
        
          /* By Default Setting the PageStartAddress to DataBank0 PageAddress */
          StatePtr->FlsWriteAddress =(uint32)PageStartAddressPtr;
        
          /* Assigning Length to global variable FlsWriteLength*/
          StatePtr->FlsWriteLength = Length;
        
          /* Assigning SourceAddressPtr to Global variable FlsWriteBufferPtr */
          StatePtr->FlsWriteBufferPtr = (uint8 *)(void *) SourceAddressPtr;
        
          /* 2. Update the new job on affected banks */
          /* The Bit OR operation is used as either s->FlsJobType[x] */
          /*  or NewJobType[x] must be FLS_NONE (0) else BUSY DET would have 
              occured */
          StatePtr->FlsJobType[0] |= JobType[0];
          StatePtr->FlsJobType[1] |= JobType[1];
    
          /* Indicate that the WRITE Job has started */
          StatePtr->JobStarted.U8 |= FLS_WRITE_JOBSTART;
        
          /* Enter Critical Section */
          Fls_lSchMEnter_Write(); 
        
          /******************* Execute the WRITE COMMAND CYCLES ***************/
          WriteMode = Fls_lGetWriteMode();
          Fls_CallWriteCommand(PhysicalAddress,StatePtr,WriteMode);
          
          /* Exit Crtical Section */
          Fls_lSchMExit_Write(); 
        
          #ifdef FLS_RAM_EMULATION_TEST
          #if  (FLS_RAM_EMULATION_TEST == 1U)
          (void) FlsEmulation_Write(StatePtr->FlsWriteAddress,
                             StatePtr->FlsWriteBufferPtr);
          #endif
          /* FLS_RAM_EMULATION_TEST */
          #endif
        
          /* Check for Sequence error,Protection error */
          if(Fls_lChkSeqProtErrors())
          {
            /* Report Production errors to DEM */
            Fls_lDemReportError_Write();
        
            /* Call to Fls_lErrorHandler local function */
            Fls_lErrorHandler(FLS_WRITE);
            RetVal = E_NOT_OK;
          }
          
          /* Check for command cycle Timeout */
          if (StatePtr->FlsTimeoutErr == FLS_WRITE)
          {
            if(RetVal == E_OK)
            {
              /* Call to Fls_lErrorHandler local function */
              Fls_lErrorHandler(FLS_WRITE); 
            }
            RetVal = E_NOT_OK;
          } 
           
          #if (FLS_DEV_ERROR_DETECT == STD_ON)
          else
          {
            Fls_lCalculateWriteTimeoutCount();
          }
          #endif /* FLS_DEV_ERROR_DETECT == STD_ON */
        }
        else
        {
          RetVal = E_NOT_OK;
        }
      }
      else
      {
        RetVal = E_NOT_OK;
      }
    }
  }
  return(RetVal);
}


#if (FLS_COMPARE_API == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=DS_AS_FLS257,DS_AS_FLS241,DS_AS_FLS244,
DS_AS_FLS150_FLS151_FLS152_FLS153_FLS273,DS_NAS_PR734_4,DS_AS_FLS209_3]
                 [/cover]
********************************************************************************
** Syntax : Std_ReturnType Fls_17_Pmu_Compare( Fls_AddressType SourceAddress, **
**                                      const uint8 *TargetAddressPtr,        **
**                                      Fls_LengthType Length                 **
**                                    );                                      **
**                                                                            **
** Service ID:  8                                                             **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :SourceAddressPtr,TargetAddress and Length                 **
**                                                                            **
** Parameters (out): E_OK: command has been accepted                          **
**                   E_NOT_OK: command has not been accepted                  **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Service for comparing the contents of an area of flash memory**
** with that of an application data buffer. This service shall copy the given **
** parameters to driver internal variables, initiate a comparejob, set the    **
** driver    status to MEMIF_BUSY, set the job result to MEMIF_JOB_PENDING    **
** and return with E_OK.                                                      **
*******************************************************************************/
Std_ReturnType Fls_17_Pmu_Compare( Fls_AddressType SourceAddress,
                            const uint8 *TargetAddressPtr,
                            Fls_LengthType Length
                           )
{
  Fls_17_Pmu_StateType   *StatePtr;
  volatile uint32 PhysicalAddress;
  uint8           JobType[2];
  Std_ReturnType  ReturnValue;

/****************************** DET *******************************************/
  #if( FLS_DEV_ERROR_DETECT == STD_ON )
  /*
  FLS015: API  called before initialization
  */
  if(Fls_lUninitDET(FLS_SID_COMPARE) == 1U)
  {
    ReturnValue = E_NOT_OK;
  }

  /*
  FLS026: Checking whether given SourceAddress is valid or not
  */
  else if( SourceAddress >= FLS_TOTAL_SIZE )
  {
    Det_ReportError( (uint16)FLS_17_PMU_MODULE_ID, FLS_17_PMU_INSTANCE_ID,
                     FLS_SID_COMPARE,
                     FLS_E_PARAM_ADDRESS
                   );/* Report to DET */

    ReturnValue = E_NOT_OK;
  }

  /*
  FLS004: Check for Pointer to an application buffer
  */
  else if(TargetAddressPtr == NULL_PTR)
  {
    Det_ReportError( (uint16)FLS_17_PMU_MODULE_ID, FLS_17_PMU_INSTANCE_ID,
                   FLS_SID_COMPARE,
                   FLS_E_PARAM_DATA
                 );/* Report to DET */

    ReturnValue = E_NOT_OK;
  }
  /*
  FLS027: Checking whether given Length is valid or not
  */
  else if((Length == 0U) || ((SourceAddress + Length) > FLS_TOTAL_SIZE))
  {
    Det_ReportError( (uint16)FLS_17_PMU_MODULE_ID, FLS_17_PMU_INSTANCE_ID,
                     FLS_SID_COMPARE,
                     FLS_E_PARAM_LENGTH
                   );/* Report to DET */

    ReturnValue = E_NOT_OK;
  }
  else
 #endif /* FLS_DEV_ERROR_DETECT == STD_ON */
/******************************************************************************/
  {
    /* Initialise Local variables */
    StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
    JobType[0] = FLS_NONE;
    JobType[1] = FLS_NONE;
    ReturnValue = E_OK;
  
    /* Check for whether read operation is only for Data Bank0 */
    if((SourceAddress + Length) <= FLS_SECTOR_SIZE)
    {
      /*Assign jobtype of Data Bank0 to Compare */
      JobType[0] = FLS_COMPARE;
      PhysicalAddress = (uint32)(FLS_BASE_ADDRESS + SourceAddress);
    }
    /* Check for whether read operation is only for Data Bank1 */
    else if(SourceAddress >= FLS_SECTOR_SIZE)
    {
      /*Assign jobtype of Data Bank1 to read */
      JobType[1] = FLS_COMPARE;
      PhysicalAddress = (uint32)( FLS_BASE_ADDRESS +
                                  (SourceAddress - FLS_SECTOR_SIZE) +
                                  FLS_OFFSET
                                );
    }
    else
    {
      /*Assign jobtype of both the banks to read */
      JobType[0] = FLS_COMPARE;
      JobType[1] = FLS_COMPARE;
      PhysicalAddress = (uint32)(FLS_BASE_ADDRESS + SourceAddress);
  
    }
  
  /************************* DET *******************************/
  
    /* Check for the BUSY DET */
    #if  ( FLS_DEV_ERROR_DETECT == STD_ON )
    /*If DET occurred then return without executing the routine.*/
    if(Fls_lBusyDET_Compare(StatePtr) == 1U)
    {
      ReturnValue = E_NOT_OK;
    }
    else
    #endif
  /****************************************************************************/
    {
      /* 1. Set the flash job result to job pending */
      StatePtr->FlsJobResult = MEMIF_JOB_PENDING;
    
      /* TargetAddressPtr is assigned to the ReadBufferPtr*/
      /* The Read Buffer is also used for Compare as parallel READ and COMPARE
         operations are NOT supported.Hence TargetAddressPtr is typecasted to
         uint8* and assigned ReadBufferPtr */
      StatePtr->FlsReadBufferPtr = (uint8 *)(void*)TargetAddressPtr;
    
      /* Assigning Length to Global variable FlsReadLength*/
      StatePtr->FlsReadLength = Length;
    
      StatePtr->FlsReadAddress = PhysicalAddress;
    
      /*3. Update the new job on affected banks */
      /* The Bit OR operation is used as either s->FlsJobType[x] */
      /*  or NewJobType[x] must be FLS_NONE (0) else 
         BUSY DET would have occured */
      StatePtr->FlsJobType[0] |= JobType[0];
      StatePtr->FlsJobType[1] |= JobType[1];
    }
  }
  return(ReturnValue);
}
/* FLS_COMPARE_API == STD_ON */
#endif


#if  (FLS_CANCEL_API  ==  STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=DS_AS_FLS252,DS_AS_FLS229,DS_AS_FLS230,
DS_AS_FLS335,DS_AS_FLS336,DS_AS_FLS033,DS_AS_FLS147,DS_AS_FLS348,
DS_NAS_PR734_6]
                 [/cover]
********************************************************************************
** Syntax : Void Fls_17_Pmu_Cancel(Void)                                      **
**                                                                            **
** Service ID:  3                                                             **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description :                                                              **
** FLS031: Service for Canceling an ongoing flash write or erase job.         **
** This function shall abort a running job synchronously so that directly     **
** after returning from this function a new job can be started                **
*******************************************************************************/
void Fls_17_Pmu_Cancel(void)
{
  Fls_17_Pmu_StateType  *StatePtr;
  uint8* ArrPtr;
  boolean JobCanceled;

  #if  ( FLS_DEV_ERROR_DETECT == STD_ON )
  /*FLS015: API called before initialization */
  if (Fls_lUninitDET(FLS_SID_CANCEL) == 0U)
  #endif
  {
    StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
    ArrPtr = StatePtr->FlsJobType;
    JobCanceled = (boolean)FALSE;
  
    /* Cancel WRITE Job */
    if((FLS_WRITE == ArrPtr[0U]) || (FLS_WRITE == ArrPtr[1U]))
    {
      /* Set the JobType to NONE; 
         This shall be done before calling Fls_lUnLoadAccessCode() */
      ArrPtr[0U] = FLS_NONE;
      ArrPtr[1U] = FLS_NONE;

      #if (FLS_AC_LOAD_ON_JOB_START == STD_ON)
      Fls_lUnLoadAccessCode(FLS_WRITE);
      #endif

      StatePtr->FlsJobResult = MEMIF_JOB_CANCELED;

      JobCanceled = (boolean)TRUE;
    }
    /* Cancel ERASE Job */
    else if((FLS_ERASE == ArrPtr[0U]) || (FLS_ERASE == ArrPtr[1U]))
    {
      /* Set the JobType to NONE;
         This shall be done before calling Fls_lUnLoadAccessCode() */
      ArrPtr[0U] = FLS_NONE;
      ArrPtr[1U] = FLS_NONE;

      #if (FLS_AC_LOAD_ON_JOB_START == STD_ON)
      Fls_lUnLoadAccessCode(FLS_ERASE);
      #endif

      StatePtr->FlsJobResult = MEMIF_JOB_CANCELED;

      JobCanceled = (boolean)TRUE;
    }
    /* Cancel READ / COMPARE Job */
    else if((FLS_READ == ArrPtr[0U])    || (FLS_READ == ArrPtr[1U])  ||
            (FLS_COMPARE == ArrPtr[0U]) || (FLS_COMPARE == ArrPtr[1U]))
    {
      /* Set the JobType to NONE */
      ArrPtr[0U] = FLS_NONE;
      ArrPtr[1U] = FLS_NONE;

      StatePtr->FlsJobResult = MEMIF_JOB_CANCELED;

      JobCanceled = (boolean)TRUE;
    }
    else
    {
      /* Set the JobType to NONE */
      ArrPtr[0U] = FLS_NONE;
      ArrPtr[1U] = FLS_NONE;
    }
  
    /* Reset JobStartStatus */
    StatePtr->JobStarted.U8 = FLS_NONE;
  
    StatePtr->NotifCaller = FLS_CANCEL_JOB;
  
    if((JobCanceled == (boolean)TRUE) &&
       (Fls_ConfigPtr->FlsJobErrorNotificationPtr != NULL_PTR)
      )
    {
      /* FlsJobErrorNotificationPtr should be called */
      (Fls_ConfigPtr->FlsJobErrorNotificationPtr)();
    }
  
    StatePtr->NotifCaller = FLS_NO_JOB;
  }
}

#endif /* #if (FLS_CANCEL_API == STD_ON) */

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1084_PR123_7]
                 [/cover]
********************************************************************************
** Syntax : void Fls_17_Pmu_CancelNonEraseJobs(void)                          **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description :                                                              **
** FLS031: Service for Canceling an ongoing flash jobs except the erase job.  **
** This function shall abort a running job synchronously so that directly     **
** after returning from this function a new job can be started                **
*******************************************************************************/
void Fls_17_Pmu_CancelNonEraseJobs(void)
{
  Fls_17_Pmu_StateType  *StatePtr;
  uint8* ArrPtr;
  boolean JobCanceled;

  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
  ArrPtr = StatePtr->FlsJobType;
  JobCanceled = (boolean)FALSE;

  /* Cancel non-erase job on Bank 0 & 1 */

  /* Cancel WRITE Job */
  if((FLS_WRITE == ArrPtr[0U]) || (FLS_WRITE == ArrPtr[1U]))
  {
    ArrPtr[0U] = FLS_NONE;
    ArrPtr[1U] = FLS_NONE;
    #if (FLS_AC_LOAD_ON_JOB_START == STD_ON)
    Fls_lUnLoadAccessCode(FLS_WRITE);
    #endif

    StatePtr->FlsJobResult = MEMIF_JOB_CANCELED;

    JobCanceled = (boolean)TRUE;
  }
  /* Cancel READ / COMPARE Job */
  else if((FLS_READ == ArrPtr[0U])    || (FLS_READ == ArrPtr[1U]) ||
          (FLS_COMPARE == ArrPtr[0U]) || (FLS_COMPARE == ArrPtr[1U]))
  {
    ArrPtr[0U] = FLS_NONE;
    ArrPtr[1U] = FLS_NONE;

    StatePtr->FlsJobResult = MEMIF_JOB_CANCELED;

    JobCanceled = (boolean)TRUE;
  }
  else
  {
    /* Reset JobType of Non-Erase Job */
    ArrPtr[0] = ((ArrPtr[0] == FLS_ERASE) ? FLS_ERASE : FLS_NONE);
    ArrPtr[1] = ((ArrPtr[1] == FLS_ERASE) ? FLS_ERASE : FLS_NONE);
  }

  /* Reset JobStart Status for NonErase Jobs */
  StatePtr->JobStarted.U8 &= FLS_ERASE_JOBSTART;

  /* Set the NotifCaller to Cancel Job */
  Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_CANCEL_JOB;

  if((JobCanceled == (boolean)TRUE) &&
     (Fls_ConfigPtr->FlsJobErrorNotificationPtr != NULL_PTR)
    )
  {
    /* FlsJobErrorNotificationPtr should be called */
    (Fls_ConfigPtr->FlsJobErrorNotificationPtr)();
  }
  Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_NO_JOB;

}

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_FLS258,DS_AS_FLS156,DS_AS_FLS155,
DS_NAS_PR734_7]
                 [/cover]
********************************************************************************
** Syntax : void Fls_17_Pmu_SetMode(MemIf_ModeType Mode)                      **
**                                                                            **
** Service ID:  9                                                             **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  None Re-entrant                                               **
**                                                                            **
** Parameters (in) : Mode MEMIF_MODE_SLOW:                                    **
**                        Normal read access / normal SPI access.             **
**                                                                            **
**                        MEMIF_MODE_FAST:                                    **
**                        Fast read access / SPI burst access.                **
**                                                                            **
** Parameters (out): : None                                                   **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description :                                                              **
** The hardware does not support burst access/fast read access for DFlash     **
** This API is a Dummy API, it is supported for API confirmance               **
*******************************************************************************/
#if  (FLS_SET_MODE_API  ==  STD_ON)
void Fls_17_Pmu_SetMode(MemIf_ModeType Mode)
{
  #if  ( FLS_DEV_ERROR_DETECT == STD_ON )
  uint8 *ArrPtr;
  
  ArrPtr = Fls_ConfigPtr->FlsStateVarPtr->FlsJobType;

  /* Check if the driver is BUSY */
  if( (ArrPtr[0] != FLS_NONE) ||
      (ArrPtr[1] != FLS_NONE)
    )
  {
    Det_ReportError( (uint16)FLS_17_PMU_MODULE_ID, 
                             FLS_17_PMU_INSTANCE_ID,
                             FLS_SID_SETMODE,
                             FLS_E_BUSY);/* Report to DET */
  }
  else
  #endif 
  {  
    Fls_ConfigPtr->FlsStateVarPtr->FlsMode = Mode;
  }
  return ;
}
#endif

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_FLS269,DS_AS_FLS255,DS_AS_FLS038,
DS_AS_FLS037_FLS212,DS_AS_FLS040,DS_AS_FLS345,DS_AS_FLS346,DS_AS_FLS039,
DS_AS_FLS117,DS_AS_FLS272_FLS359_FLS360,
DS_AS_FLS196,DS_AS_FLS220_FLS225_FLS238_FLS243,DS_NAS_PR734_8]
                 [/cover]
********************************************************************************
** Syntax : void Fls_17_Pmu_MainFunction(void)                                **
**                                                                            **
** Service ID:  6                                                             **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out): : None                                                   **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description :                                                              **
** FLS037: This service shall perform the processing of the flash read,write  **
**         and erase jobs                                                     **
*******************************************************************************/
void Fls_17_Pmu_MainFunction(void)
{
  Fls_17_Pmu_StateType  *StatePtr;
  uint8 *ArrPtr;
  
  #if  ( FLS_DEV_ERROR_DETECT == STD_ON )
  uint8 ErrorUninitFlag;
  uint8 ErrorTimeoutFlag;
  
  /*FLS015: API  called before initialization */
  ErrorUninitFlag = Fls_lUninitDET(FLS_SID_MAIN);
  if (ErrorUninitFlag == 0U)
  {
    #ifdef VALEO_PATCH_MCAL_FLS_FIX_DET_TIMEOUT
    ErrorTimeoutFlag = 0U;
    #else
    ErrorTimeoutFlag = Fls_lTimeOutDET(FLS_SID_MAIN);
    #endif /* VALEO_PATCH_MCAL_FLS_FIX_DET_TIMEOUT */
    if (ErrorTimeoutFlag == 0U)   
  #endif
    {
      StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
      ArrPtr = StatePtr->FlsJobType;

      if( (ArrPtr[BANK0] != FLS_NONE) ||
          (ArrPtr[BANK1] != FLS_NONE)
        )
      {
      #if(FLS_USE_INTERRUPTS == STD_OFF)
 /******************************** ERASE *************************************/
        /* Check for erase operation is pending in either of the bank */
    
        if( Fls_lHWBusyCheck() == 0U)
        {
          if(ArrPtr[BANK0] == FLS_ERASE)
          {
            /* Fls_Main_Erase operation should be called  */
            Fls_lMainErase((uint8)BANK0);
          }
          else if(ArrPtr[BANK1] == FLS_ERASE)
          {
            /* Fls_Main_Erase operation should be called  */
            Fls_lMainErase((uint8)BANK1);
          }
          else{/* To avoid MISRA warning */}
        }
 
 /******************************** WRITE ************************************/
        /* Check for write operation is pending in either of the bank */
        if( Fls_lHWBusyCheck() == 0U)
        {
          if(ArrPtr[BANK0] == FLS_WRITE)
          {
            /* Fls_Main_Write operation should be called  */
            Fls_lMainWrite((uint8)BANK0);
          }
          else if(ArrPtr[BANK1] == FLS_WRITE)
          {
            /* Fls_Main_Write operation should be called  */
            Fls_lMainWrite((uint8)BANK1);
          }
          else{/* To avoid MISRA warning */}
        }
 
      /* FLS_USE_INTERRUPTS == STD_OFF */
      #endif
 /******************************** READ **************************************/
        /* Check for read operation is pending in either of the bank */
        if( Fls_lHWBusyCheck() == 0U)
        {
          if(ArrPtr[BANK0] == FLS_READ)
          {
            /* Fls_Main_Read operation should be called  */
            Fls_lMainRead((uint8)BANK0);
          }
          else if(ArrPtr[BANK1] == FLS_READ)
          {
            /* Fls_Main_Read operation should be called  */
            Fls_lMainRead((uint8)BANK1);
          }
          else{/* To avoid MISRA warning */}            
        }
 
 /****************************** COMPARE ************************************/
        /* Check for Compare operation is pending in bank 0 */
        if( Fls_lHWBusyCheck() == 0U)
        {
          if(ArrPtr[BANK0] == FLS_COMPARE)
          {
            /* Fls_Main_Compare operation should be called  */
            Fls_lMainCompare((uint8)BANK0);
          }
          else if(ArrPtr[BANK1] == FLS_COMPARE)
          {
            /* Fls_Main_Compare operation should be called  */
            Fls_lMainCompare((uint8)BANK1);
          }
          else{/* To avoid MISRA warning */}
        }
      }
    }
  #if  ( FLS_DEV_ERROR_DETECT == STD_ON )  
  }
  #endif
}

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_FLS236,DS_AS_FLS239,DS_AS_FLS209_4,
DS_AS_FLS097_FLS098_FLS099_FLS100_FLS158,DS_NAS_PR734_5,DS_AS_FLS256_FLS001_3]
                 [/cover]
********************************************************************************
** Syntax : Std_ReturnType Fls_17_Pmu_Read( Fls_AddressType SourceAddress,    **
**                                   uint8 *TargetAddressPtr,                 **
**                                   Fls_LengthType Length                    **
**                                 );                                         **
**                                                                            **
** Service ID:  7                                                             **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) : SourceAddress,TargetAddressPtr and Length                **
**                                                                            **
** Parameters (out): E_OK: command has been accepted                          **
**                   E_NOT_OK: command has not been accepted                  **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description :                                                              **
** FLS018: Service for reading from flash memory.This service                 **
** shall Copies the given parameters to driver internal variables,initiate a  **
** read job,set driver status to MEMIF_E_BUSY and job result to               **
** MEMIF_JOB_PENDING.                                                         **
*******************************************************************************/
Std_ReturnType Fls_17_Pmu_Read( Fls_AddressType SourceAddress,
                         uint8 *TargetAddressPtr,
                         Fls_LengthType Length
                       )
{
  Fls_17_Pmu_StateType  *StatePtr;
  volatile uint32 PhysicalAddress;
  Std_ReturnType ReturnValue;
  uint8 JobType[2];

/**************************** DET *********************************************/
  #if  ( FLS_DEV_ERROR_DETECT == STD_ON )
  /* FLS015: API  called before initialization */
  if(Fls_lUninitDET(FLS_SID_READ) == 1U)
  {
    ReturnValue = E_NOT_OK;
  }
 /* FLS097: Checking whether given SourceAddress is valid or not */
  else if(SourceAddress >= (FLS_TOTAL_SIZE))
  {
    Det_ReportError( (uint16)FLS_17_PMU_MODULE_ID, 
                     FLS_17_PMU_INSTANCE_ID,FLS_SID_READ,
                     FLS_E_PARAM_ADDRESS);/* Report to DET */

    ReturnValue = E_NOT_OK;
  }
  /*Check for Pointer to an application buffer*/
  else if(TargetAddressPtr == NULL_PTR)
  {
    Det_ReportError( (uint16)FLS_17_PMU_MODULE_ID, 
                    FLS_17_PMU_INSTANCE_ID,FLS_SID_READ,
                     FLS_E_PARAM_DATA);/* Report to DET */

    ReturnValue = E_NOT_OK;
  }
  /* FLS098: Checking whether given Length is valid or not */
  else if((Length == 0U) || ((SourceAddress+Length) > (FLS_TOTAL_SIZE)))
  {
    Det_ReportError( (uint16)FLS_17_PMU_MODULE_ID, 
                     FLS_17_PMU_INSTANCE_ID, FLS_SID_READ,
                     FLS_E_PARAM_LENGTH);/* Report to DET */

    ReturnValue = E_NOT_OK;
  }
  else
  #endif
/*****************************************************************************/
  {
    /* Initialise Local variables */
    StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
    ReturnValue = (Std_ReturnType)E_OK;
  
    JobType[0] = FLS_NONE;
    JobType[1] = FLS_NONE;
  
    /* Check for whether read operation is only for Data Bank0 */
    if((SourceAddress + Length) <= FLS_SECTOR_SIZE)
    {
      /*Assign jobtype of Data Bank0 to read */
      JobType[BANK0] = FLS_READ;
      PhysicalAddress = (uint32)(FLS_BASE_ADDRESS + SourceAddress);
  
    }
    /* Check for whether read operation is only for Data Bank1 */
    else if(SourceAddress >= FLS_SECTOR_SIZE)
    {
       /*Assign jobtype of Data Bank1 to read */
      JobType[BANK1] = FLS_READ;
      PhysicalAddress = (uint32)( FLS_BASE_ADDRESS +
                                  (SourceAddress - FLS_SECTOR_SIZE) +
                                  FLS_OFFSET
                                );
    }
    else
    {
      /*Assign jobtype of both the banks to read */
      JobType[BANK0] = FLS_READ;
      JobType[BANK1] = FLS_READ;
      PhysicalAddress = (uint32)(FLS_BASE_ADDRESS + SourceAddress);
    }
  
  /*************************** DET ********************************************/
  
    /* Check for the BUSY DET */
    #if  ( FLS_DEV_ERROR_DETECT == STD_ON )
    /*If DET occurred then return without executing the routine.*/
    if(Fls_lBusyDET_Read(StatePtr) == 1U)
    {
      ReturnValue = E_NOT_OK;
    }
    else
    #endif
  /****************************************************************************/
    {
      /* 2. Set the flash job result to job pending */
      StatePtr->FlsJobResult = MEMIF_JOB_PENDING;
    
      /* Assigning TargetAddressPtr to Global variable FlsReadBufferPtr */
      StatePtr->FlsReadBufferPtr = TargetAddressPtr;
    
      /* Assigning Length to Global variable FlsReadLength*/
      StatePtr->FlsReadLength = Length;
    
      StatePtr->FlsReadAddress = PhysicalAddress;
    
      /*3. Update the new job on affected banks */
      /* The Bit OR operation is used as either s->FlsJobType[x] */
      /*  or NewJobType[x] must be FLS_NONE (0) 
          else BUSY DET would have occured */
      StatePtr->FlsJobType[0] |= JobType[0];
      StatePtr->FlsJobType[1] |= JobType[1];    
    }
  }
  return(ReturnValue);
}

/*********************** AUTOSAR SPECIFIC IMPLEMENTATION **********************/
#if (FLS_GET_STATUS_API  ==  STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=DS_AS_FLS253,DS_AS_FLS034,DS_NAS_PR734_11]
                 [/cover]
********************************************************************************
** Syntax : MemIf_StatusType Fls_17_Pmu_GetStatus(void)                       **
**                                                                            **
** Service ID:  4                                                             **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out): : None                                                   **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description :                                                              **
** FLS034: This service shall return the driver state synchronously           **
*******************************************************************************/
MemIf_StatusType Fls_17_Pmu_GetStatus(void)
{
  MemIf_StatusType ReturnValue;
  uint8* JobTypePtr;

  #if (FLS_PB_FIXEDADDR == STD_OFF)
  if(Fls_ConfigPtr == NULL_PTR)
  #else
  if(Fls_ConfigPtr->FlsStateVarPtr->DriverInitialised == (boolean)FALSE)
  #endif
  {
    ReturnValue = MEMIF_UNINIT;
  }
  else
  {
    JobTypePtr = Fls_ConfigPtr->FlsStateVarPtr->FlsJobType;

    if((JobTypePtr[0] != FLS_NONE) ||
       (JobTypePtr[1] != FLS_NONE)
      )
    {
      ReturnValue = MEMIF_BUSY;
    }
    else
    {
      ReturnValue = MEMIF_IDLE;
    }
  }
  /* FLS034: Service shall return driver state synchronously. */
  return(ReturnValue);
} /* End of Function: Fls_GetStatus */

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1085_PR123_6]
                 [/cover]
********************************************************************************
** Syntax : MemIf_StatusType Fls_17_Pmu_GetBankStatus(uint32 BankNum)         **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) :  BankNum                                                 **
**                                                                            **
** Parameters (out): : None                                                   **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description :                                                              **
** FLS034: This service shall return the driver state synchronously           **
*******************************************************************************/
MemIf_StatusType Fls_17_Pmu_GetBankStatus(uint32 BankNum)
{
  MemIf_StatusType ReturnValue;
  uint8* JobTypePtr;

  #if (FLS_PB_FIXEDADDR == OFF)
  if(Fls_ConfigPtr == NULL_PTR)
  #else
  if(Fls_ConfigPtr->FlsStateVarPtr->DriverInitialised == (boolean)FALSE)
  #endif
  {
    ReturnValue = MEMIF_UNINIT;
  }
  else
  {
    JobTypePtr = Fls_ConfigPtr->FlsStateVarPtr->FlsJobType;

    if(JobTypePtr[BankNum] != FLS_NONE)
    {
      ReturnValue = MEMIF_BUSY;
    }
    else
    {
      ReturnValue = MEMIF_IDLE;
    }
  }
  /* FLS034: Service shall return driver state synchronously. */
  return(ReturnValue);
} /* End of Function: Fls_GetStatus */

/* FLS_GET_STATUS_API  ==  STD_ON */
#endif

#if  (FLS_GET_JOB_RESULT_API  ==  STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=DS_AS_FLS254,DS_AS_FLS035,DS_NAS_PR734_12,
DS_AS_FLS036,DS_AS403_FLS358]
                 [/cover]
********************************************************************************
** Syntax : MemIf_JobResultType Fls_17_Pmu_GetJobResult(void)                 **
**                                                                            **
** Service ID:  5                                                             **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Re-entrant                                                    **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out): : None                                                   **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description :                                                              **
** FLS035: This service shall return the result of the last job synchronously **
*******************************************************************************/
MemIf_JobResultType Fls_17_Pmu_GetJobResult(void)
{
  Fls_17_Pmu_StateType  *StatePtr;
  MemIf_JobResultType RetVal;

  #if  ( FLS_DEV_ERROR_DETECT == STD_ON )
  /* FLS015: API  called before initialization */
  if (Fls_lUninitDET(FLS_SID_GETJOBRESULT) != 0U)
  {
     RetVal = MEMIF_JOB_FAILED;
  }
  else
  #endif
  {
    StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
    RetVal = StatePtr->FlsJobResult;
  }

  return(RetVal);
}
#endif
/*FLS_GET_JOB_RESULT_API == STD_ON */


#if (FLS_IFX_FEE_USED == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR734_10,DS_NAS_PR1147_PR123_1]
                 [/cover]
********************************************************************************
** Syntax : Std_ReturnType Fls_17_Pmu_ReadWordsSync( 
                                             Fls_AddressType SourceAddress,**
**                                           const uint32 *TargetAddressPtr,  **
**                                           uint32 Length                    **
**                                         );                                 **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) : SourceAddress,TargetAddressPtr and Length                **
**                                                                            **
** Parameters (out): E_OK: Read successful                                    **
**                   E_NOT_OK: HW busy or read failed with ECC error          **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Service for reading word data from flash bank synchronously  **
*******************************************************************************/
Std_ReturnType Fls_17_Pmu_ReadWordsSync( Fls_AddressType SourceAddress,
                                 const uint32 *TargetAddressPtr,
                                 uint32 Length
                               )
{
  Fls_17_Pmu_StateType  *StatePtr;
  uint8* JobTypePtr;
  volatile uint32 PhysicalAddress;
  Std_ReturnType RetVal;
  uint32 *SrcPtr;
  uint32 *DestPtr;
  uint32 BankNum;

  #ifdef FLS_RAM_EMULATION_TEST
  #if (FLS_RAM_EMULATION_TEST == 1U)
  uint32 EmulationLength;
  
  /* Convert to byte read for emulation */
  EmulationLength = Length << 2U;
  
  #endif
  #endif

  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
  JobTypePtr = StatePtr->FlsJobType;
  RetVal = E_OK;


  if(SourceAddress >= FLS_SECTOR_SIZE)
  {
    PhysicalAddress = (uint32)( FLS_BASE_ADDRESS +
                                (SourceAddress - FLS_SECTOR_SIZE) +
                                FLS_OFFSET
                              );
    BankNum = 1U;
  }
  else
  {
    PhysicalAddress = (uint32)( FLS_BASE_ADDRESS + SourceAddress );
    BankNum = 0U;
  }

  SrcPtr = (uint32*)PhysicalAddress;
  DestPtr = (uint32*)(void *)TargetAddressPtr;
  /* Check if no operation ongoing */
  if(JobTypePtr[BankNum] == FLS_NONE)
  {
    /* Modify the GlobalVar JobType so that no new requests can be accepted on *
     * the Bank till ReadSync is finished */
    JobTypePtr[BankNum] = FLS_READSYNC;
   
   do
    {
      *DestPtr = *SrcPtr;
      /* Point to the next word */
      DestPtr++;
       /* Increment by one word */
      SrcPtr++;
      Length--;
    }while(Length > 0U);  
       
    #ifdef FLS_RAM_EMULATION_TEST
    #if (FLS_RAM_EMULATION_TEST == 1U)
    {
      Std_ReturnType EmulationRetVal;

      FlsEmulation_ReadRequest.FlashAddress = PhysicalAddress;
      FlsEmulation_ReadRequest.Buffer = (uint8*)(void*)TargetAddressPtr;
      FlsEmulation_ReadRequest.Length = (uint32)EmulationLength;

      EmulationRetVal = FlsEmulation_Read(FlsEmulation_ReadRequest.FlashAddress,
                                    FlsEmulation_ReadRequest.Buffer,
                                    FlsEmulation_ReadRequest.Length);

      if (EmulationRetVal == E_NOT_OK)
      {
        /* Restore the JobType with previous tasks */
        JobTypePtr[BankNum] = FLS_NONE;
        Fls_lDemReportError_Read();
        RetVal = EmulationRetVal;
      }
    }
    #endif
    #endif

    /* Read the data */

    /* Restore the JobType with previous tasks */
    JobTypePtr[BankNum] = FLS_NONE;

    /* Check for uncorrectable bit error */
    if(Fls_lChkBitErrors())
    {
      /* FLS106: Read Job fails due to hardware error */
      /* Report Production errors to DEM */
      Fls_lDemReportError_Read();
     
      /* Return E_NOT_OK */
      RetVal = E_NOT_OK;
    }
  }
  else
  {
    RetVal = E_NOT_OK;
  }

   /* Execute Clear Status command */
  if( (StatePtr->FlsJobType[0] == FLS_NONE) &&
       (StatePtr->FlsJobType[1] == FLS_NONE)
    )
  {
    Fls_ClearStatusCmdCycle();
  }

  return(RetVal);
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1146_PR123_2]
                 [/cover]
********************************************************************************
** Syntax : Std_ReturnType Fls_17_Pmu_CompareWordsSync(                       **
                                             Fls_AddressType SourceAddress,   **
**                                           const uint32 *TargetAddressPtr,  **
**                                           uint32 Length);                  **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) : SourceAddress, TargetAddressPtr and Length               **
**                                                                            **
** Parameters (out): E_OK: command has been accepted and compare successful   **
**                   E_NOT_OK: HW busy or compare failed or ECC error         **
**                                                                            **
** Return value    :  None                                                    **
**                                                                            **
** Description : Service for comparing data from flash bank synchronously     **
*******************************************************************************/
Std_ReturnType Fls_17_Pmu_CompareWordsSync( Fls_AddressType SourceAddress,
                                 const uint32 *TargetAddressPtr,
                                 uint32 Length)
{
  Fls_17_Pmu_StateType  *StatePtr;
  uint8* JobTypePtr;
  volatile uint32 PhysicalAddress;
  Std_ReturnType RetVal;
  uint32 *SrcPtr;
  uint32 BankNum;

  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
  JobTypePtr = StatePtr->FlsJobType;
  RetVal = E_OK;

  if(SourceAddress >= FLS_SECTOR_SIZE)
  {
    PhysicalAddress = (uint32)( FLS_BASE_ADDRESS +
                                (SourceAddress - FLS_SECTOR_SIZE) +
                                 FLS_OFFSET
                              );
    BankNum = 1U;
  }
  else
  {
    PhysicalAddress = (uint32)( FLS_BASE_ADDRESS + SourceAddress );
    BankNum = 0U;
  }

  SrcPtr = (uint32*)PhysicalAddress;
  /* Check if no operation ongoing */
  if( (JobTypePtr[BankNum] == FLS_NONE)
        #if(FLS_VER_ERROR_CHECK == STD_ON)
        #if(FLS_IFX_FEE_USED == STD_ON)
        && (StatePtr->FlsPver == 0U)
        #endif
        #endif        
     )
  {
    /* Modify the GlobalVar JobType so that no new requests can be accepted on *
     * the Bank till CompareSync is finished */
    JobTypePtr[BankNum] = FLS_COMPARESYNC;

    #ifdef FLS_RAM_EMULATION_TEST
    #if (FLS_RAM_EMULATION_TEST == 1U)
    {
      Std_ReturnType EmulationRetVal;

      FlsEmulation_ReadRequest.FlashAddress = PhysicalAddress;
      FlsEmulation_ReadRequest.Buffer = (uint8*)(void*)TargetAddressPtr;
      FlsEmulation_ReadRequest.Length = (uint32)Length;

      EmulationRetVal = FlsEmulation_CompareSync(
                                    FlsEmulation_ReadRequest.FlashAddress,
                                    FlsEmulation_ReadRequest.Buffer,
                                    FlsEmulation_ReadRequest.Length);

      if (EmulationRetVal == E_NOT_OK)
      {
        /* Restore the JobType with previous tasks */
        JobTypePtr[BankNum] = FLS_NONE;
        RetVal = EmulationRetVal;
      }
    }
    #endif
    #endif

    do
    {
      /* COMPARE THE FLASH DATA WITH THE BUFFER DATA (word Compare)*/
      if( *TargetAddressPtr != *SrcPtr )
      {
        RetVal = E_NOT_OK;
        Length = 0U;
      }
      else
      {
        TargetAddressPtr++;
        SrcPtr++;
        Length--;
      }
    }while(Length > 0U);

    /* Restore the JobType with previous tasks */
    JobTypePtr[BankNum] = FLS_NONE;
  
    /* Check for uncorrectable bit error */
    if(Fls_lChkBitErrors())
    {
      /* Return E_NOT_OK */
      RetVal = E_NOT_OK;
    }
  }
  else
  {
    RetVal = E_NOT_OK;
  }

  /* Execute Clear Status command */
  if( (StatePtr->FlsJobType[0U] == FLS_NONE) &&
     (StatePtr->FlsJobType[1U] == FLS_NONE))
  {
    Fls_ClearStatusCmdCycle();
  }

  return(RetVal);
}


/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1145_PR123_3]
                  [/cover]
********************************************************************************
** Syntax : Std_ReturnType Fls_17_Pmu_VerifyErase( uint32 BankNum,            **
                                 uint32 * const UnerasedWordlineAddressPtr    **
                                 uint8 * const UnerasedWordlineCountPtr       **
**                               );                                           **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) : BankNum                                                  **
**                                                                            **
** Parameters (out): UnerasedWordlineAddressPtr,UnerasedWordlineCountPtr      **
**                                                                            **
** Return value    :  E_OK: command has been accepted and erase verification  **
**                          successful                                        **
**                    E_NOT_OK: HW busy or erase verification failed          **
**                                                                            **
** Description : Service for verifying erase of a sector                      **
*******************************************************************************/
Std_ReturnType Fls_17_Pmu_VerifyErase( uint32 BankNum,
                                   uint32 * UnerasedWordlineAddressPtr,
                                   uint8 * const UnerasedWordlineCountPtr )
{
  Fls_17_Pmu_StateType  *StatePtr;
  uint8* JobTypePtr;
  volatile uint32 PhysicalAddress;
  Std_ReturnType RetVal;
  uint32 *SrcPtr;
  uint32 Length;
  uint32 UnerasableWLAddr;
  uint8 FailCount;
  uint8 CompareFail;
  
  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
  JobTypePtr = StatePtr->FlsJobType;
  RetVal = E_OK;
  FailCount = 0U;
  
  if(BankNum == BANK0)
  {
    PhysicalAddress = DFLASH_BANK0_PHYSICAL;
  }
  else
  {
    PhysicalAddress = DFLASH_BANK1_PHYSICAL;
  }

  SrcPtr = (uint32*)PhysicalAddress;
  /* Check if no operation ongoing */
  if(JobTypePtr[BankNum] == FLS_NONE)
  {
    /* For verify erase testing */
    #ifdef FLS_17_PMU_VERIFYERASE_TEST
    #if (FLS_17_PMU_VERIFYERASE_TEST == 1U)
    RetVal = FlsEmulation_VerifyErase(PhysicalAddress,
                                      UnerasedWordlineAddressPtr,
                                      UnerasedWordlineCountPtr);
    #endif
    #endif

    /* Modify the GlobalVar JobType so that no new requests can be accepted on *
     * the Bank till VerifyErase is finished */
    JobTypePtr[BankNum] = FLS_VERIFYERASE;
    Length = FLS_SECTOR_SIZE;
    
    do
    {
      CompareFail = 0U;
      
      /* COMPARE THE FLASH DATA WITH zero (first 16 Bytes of the Wordline)*/
      if((*SrcPtr != 0U) || (*(SrcPtr + 1U) !=0U) ||
         (*(SrcPtr + 2U) !=0U) || (*(SrcPtr + 3U) !=0U) )
      {
        CompareFail = 1U;
      }
      if(Fls_lChkBitErrors())
      {
        CompareFail = 1U;
        Fls_ClearStatusCmdCycle();
      }
      
      if(CompareFail == 1U)
      {
        FailCount++;
        if(FailCount > FLS_WL_FAIL_COUNT)
        {
           RetVal = E_NOT_OK;
        }
        else
        {
          /* Update the Unerasable WL address */
          UnerasableWLAddr = (uint32)SrcPtr - PhysicalAddress;
                    
          if(PhysicalAddress == DFLASH_BANK1_PHYSICAL)
          {
            UnerasableWLAddr += FLS_SECTOR_SIZE;
          }
          
          *UnerasedWordlineAddressPtr = UnerasableWLAddr;
          
          /* increment SrcPtr to next wordline, divide by 4 for SrcPtr is
           uint32 ptr*/
          SrcPtr += (FLS_WORDLINE_SIZE/FLS_WORD_SIZE);
          Length -= FLS_WORDLINE_SIZE;
          UnerasedWordlineAddressPtr++;
        }
      }
      else
      {
        /* increment SrcPtr to next wordline, divide by 4 for SrcPtr is
           uint32 ptr*/
        SrcPtr += (FLS_WORDLINE_SIZE/FLS_WORD_SIZE);
        Length -= FLS_WORDLINE_SIZE;
      }
    
    }while((Length != 0U) && (FailCount <= FLS_WL_FAIL_COUNT) );
    
    *UnerasedWordlineCountPtr = FailCount;

    /* Restore the JobType with previous tasks */
    JobTypePtr[BankNum] = FLS_NONE;
  }
  else
  {
    RetVal = E_NOT_OK;
  }

  return(RetVal);
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1148_PR123_8]
                 [/cover]
********************************************************************************
** Syntax : Fls_17_Pmu_Job_Type Fls_17_Pmu_GetNotifCaller(void)               **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  FLS Job that raised the notification                    **
**                                                                            **
** Description :                                                              **
** Ths function returns the FLS Job that raised the notification              **
*******************************************************************************/
Fls_17_Pmu_Job_Type Fls_17_Pmu_GetNotifCaller(void)
{
  return(Fls_ConfigPtr->FlsStateVarPtr->NotifCaller);
}

#endif /* FLS_IFX_FEE_USED == STD_ON */

#if (FLS_USE_ERASESUSPEND == STD_ON)
/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1149_PR123_4]
                 [/cover]
********************************************************************************
** Syntax : Std_ReturnType  Fls_17_Pmu_SuspendErase (uint32 BankNum)          **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  BankNum - Sector on which erase is to be suspended      **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  E_OK - Erase suspend susccessful                        **
**                    E_NOT_OK - Erase suspend failed                         **
**                                                                            **
** Description :                                                              **
** Ths function suspends an ongoing erase of a sector.                        **
*******************************************************************************/
Std_ReturnType Fls_17_Pmu_SuspendErase(uint32 BankNum)
{
  Std_ReturnType RetVal;
  Fls_17_Pmu_StateType  *StatePtr;
  uint8* JobTypePtr;
  uint32 TimeOutCount;
  
  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
  JobTypePtr = StatePtr->FlsJobType;
  
  if(FLASH0_FSR.B.SPND == 1U)
  {
    RetVal = E_OK;
    /* Set job status for the bank to None */
    JobTypePtr[BankNum] = FLS_NONE;
    /* Reset JobStartStatus */
    StatePtr->JobStarted.U8 = FLS_NONE;
  }
  else
  {
    #ifdef IFX_FLS_DEBUG03
    if (TestFls_DebugMask03 != 1)
    #endif
    {
      FLASH0_MARD.U |= FLS_MARD_SPND;
    }
    TimeOutCount = FLS_ERASESUSPEND_TIMEOUT;
    do 
    {
      TimeOutCount-- ;
    }while( (FLASH0_FSR.B.SPND == 0U) && (TimeOutCount > 0U) );
  
    if ((boolean)TRUE == Fls_lSpndTimeout(TimeOutCount))
    {
      /* Clear the SPNDERR bit by writing 1 */
      FLASH0_MARD.B.SPNDERR = 1U;
      RetVal = E_NOT_OK;
    }
    else if(FLS_D0BUSY == Fls_lHWBusyCheck())
    {
      /* If hardware is still busy, Clear the SPNDERR bit by writing 1 */
      FLASH0_MARD.B.SPNDERR = 1U;
      RetVal = E_NOT_OK;
    }
    else
    {
      RetVal = E_OK;
      /* Set job status for the bank to None */
      JobTypePtr[BankNum] = FLS_NONE;
      /* Reset JobStartStatus */
      StatePtr->JobStarted.U8 = FLS_NONE;
      /* Set the flash job result to job ok */
      StatePtr->FlsJobResult = MEMIF_JOB_OK;
    }
  }
  
  return RetVal;
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1150_PR123_5]
                 [/cover]
********************************************************************************
** Syntax : Std_ReturnType Fls_17_Pmu_ResumeErase (uint32 BankNum )           **
**                                                                            **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  BankNum - Sector on which erase is to be resumed        **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  E_OK - Erase suspend susccessful                        **
**                    E_NOT_OK - Erase suspend failed                         **
**                                                                            **
** Description :                                                              **
** Ths function suspends an ongoing erase of a sector.                        **
*******************************************************************************/
Std_ReturnType Fls_17_Pmu_ResumeErase (uint32 BankNum)
{
  Std_ReturnType RetVal;
  Fls_17_Pmu_StateType  *StatePtr;
  uint8* JobTypePtr;
  volatile uint32 PhysicalAddress;
  uint32 TimeOutCount;
  
  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
  JobTypePtr = StatePtr->FlsJobType;
  RetVal = E_OK;
  
  if(FLASH0_FSR.B.SPND == 1U)
  {
    if(Fls_lChkOperError() == 0U)
    {
      if(BankNum == BANK0)
      {
        PhysicalAddress = DFLASH_BANK0_PHYSICAL;
      }
      else
      {
        PhysicalAddress = DFLASH_BANK1_PHYSICAL;
      }
      
      #if( FLS_AC_LOAD_ON_JOB_START == STD_ON)
      Fls_lLoadAccessCode(FLS_ERASE);
      #endif
      
      #ifdef IFX_FLS_DEBUG04
      if (TestFls_DebugMask04 != 0)
      #endif
      {
        /* Enter Critical Section */
        Fls_lSchMEnter_ResumeErase();
            
        /* Execute the Resume ERASE COMMAND CYCLES */
        Fls_ResumeEraseCmdCycle(PhysicalAddress);
            
        /* Exit Crtical Section */
        Fls_lSchMExit_ResumeErase(); 
      }
      
      if(Fls_lChkSeqProtErrors() != 0U)
      {
        /* Enter Critical Section */
        Fls_lSchMEnter_ResumeErase();
        
        Fls_ClearStatusCmdCycle();
        
        /* Exit Crtical Section */
        Fls_lSchMExit_ResumeErase(); 
        
        RetVal = E_NOT_OK;
      }
      else
      {
        TimeOutCount = FLS_ERASESUSPEND_TIMEOUT;
        do 
        {
          TimeOutCount-- ;
        }while( (FLASH0_FSR.B.SPND == 1U) && (TimeOutCount > 0U) );
          
        if(0U != Fls_lChkOperError())
        {
          /* OPER error occured */
          RetVal = E_NOT_OK;
        }
        else if((boolean)TRUE == Fls_lResmErTimeout(TimeOutCount))
        {
          /* If timeout happens and Suspend bit is not cleared return E_NOT_OK*/
          RetVal = E_NOT_OK;
        }
        else if(0U == Fls_lHWBusyCheck())
        {
          /* If hardware is still not busy i.e., if erase did not resume, 
             then return E_NOT_OK */
          RetVal = E_NOT_OK;
        }
        else
        {
          /* Restore the JobType with previous erase */
          JobTypePtr[BankNum] = FLS_ERASE;
          /* 1. Set the flash job result to job pending */
          StatePtr->FlsJobResult = MEMIF_JOB_PENDING;
          /*Indicate that the ERASE Job has been started */
          StatePtr->JobStarted.U8 |= FLS_ERASE_JOBSTART;
        }
      }
    }
    else
    {
      RetVal = E_NOT_OK;
    }
  }

  return RetVal;
}

#endif /* FLS_USE_ERASESUSPEND == STD_ON */

/*******************************************************************************
** Syntax : Std_ReturnType Fls_17_Pmu_GetOperStatus(void)                     **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non reentrant                                                 **
**                                                                            **
** Parameters (in) :  None                                                    **
**                                                                            **
** Parameters (out):  None                                                    **
**                                                                            **
** Return value    :  E_OK - No OPER error                                    **
**                    E_NOT_OK - OPER error has occured                       **
**                                                                            **
** Description : This function provides the OPER error status                 **
*******************************************************************************/
Std_ReturnType Fls_17_Pmu_GetOperStatus(void)
{
  Fls_17_Pmu_StateType   *StatePtr;
  uint32 OPER_Status;
  Std_ReturnType RetVal;

  RetVal = E_OK;
  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;

  #ifndef FLS_RAM_EMULATION_TEST
  #ifdef IFX_FLS_DEBUG
  OPER_Status = (( (uint32)FLASH0_FSR.U | TestFls_DebugMask )& FLS_OPER_ERROR);
  #else
  OPER_Status = ((uint32)FLASH0_FSR.U & FLS_OPER_ERROR);
  #endif
  #else
  OPER_Status = (FlsEmulation_ReadStatusRegister() & FLS_OPER_ERROR);
  #endif
  
  if((0U != OPER_Status) || (0U != StatePtr->FlsOper))
  {
    RetVal = E_NOT_OK;
  }
  
  return (RetVal);
}

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_FLS104,DS_AS_FLS022,
DS_AS403_FLS313,DS_AS403_FLS315,
DS_AS_FLS167_1,DS_AS_FLS347_1,DS_AS_FLS140_FLS_143_1,
DS_NAS_PR1058_3]
                 [/cover]
********************************************************************************
** Syntax : void Fls_lMainErase(uint8 BankType)                               **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  Non-reentrant                                                 **
**                                                                            **
** Parameters (in) : BankType    DFlash Bank                                  **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : Performs the erase operation during Interrupt/Cyclic         **
**               Job handling                                                 **
** Issues : eg. When Bank1 erase is requested and then Bank0 is requested.    **
**          Bank1 erase is started first. But the lMainErase checks for Bank0 **
**          busy state. Since Bank0 Erase is not started
*******************************************************************************/
static void Fls_lMainErase(uint8 BankType)
{
  Fls_17_Pmu_StateType       *StatePtr;
  MemIf_JobResultType LastJobResult;
  volatile uint32     PhysicalAddress;
  uint32              SeqProtErr;
  Std_ReturnType      RetVal;
  
  #if ( FLS_IFX_FEE_USED ==  STD_OFF )
  #if ( FLS_DEV_ERROR_DETECT == STD_ON )
  uint32              *ErasePtr;
  uint32 Count;
  #endif
  #endif

  /******************* Initialise the global variables ***************/
  RetVal = E_OK;
  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;

  LastJobResult = StatePtr->FlsJobResult;

  /* Obtain the physical address for the write operations */
  if(BankType == BANK0)
  {
    PhysicalAddress = DFLASH_BANK0_PHYSICAL;
  }
  else
  {
    PhysicalAddress = DFLASH_BANK1_PHYSICAL;
  }

  if(Fls_lChkOperError()) /* Check for operational error */
  {
    /* FLS104: Erase Job fails due to hardware error */
    /* Report Production errors to DEM */

    Fls_lDemReportError_Erase();
    
    /* Call Fls_lErrorHandler local function */
    Fls_lErrorHandler(FLS_ERASE);
    RetVal = E_NOT_OK;
  }
  
  /******************************** DET *************************************/
  #if ( FLS_IFX_FEE_USED ==  STD_OFF )
  #if ( FLS_DEV_ERROR_DETECT == STD_ON )
  else
  {
    /********* Check for DFlash Sector content equal to zero *****/
    ErasePtr = (uint32 *)PhysicalAddress;
    Count = 0U;
    do
    {
      if((*ErasePtr)== 0U)
      {
        Count++;
        ErasePtr++;
      }
      else
      {
        /* FLS022: If block is not completely erased error should be */
        /* reported                                                  */
        /* Call Fls_lErrorHandler local function */
        Det_ReportError( (uint16)FLS_17_PMU_MODULE_ID, 
                         FLS_17_PMU_INSTANCE_ID,FLS_SID_MAIN,
                         FLS_E_VERIFY_ERASE_FAILED);/* Report to DET */
        Fls_lErrorHandler(FLS_ERASE);
        RetVal = E_NOT_OK; /*return from function*/
        break;
      }
    } while(Count < (FLS_SECTOR_SIZE / FLS_WORD_SIZE));
    /*(FLS_SECTOR_SIZE / 4U) is used since it is a word comparison */
    /* FLS_DEV_ERROR_DETECT */
  }
  #endif
  #endif

  if(RetVal == E_OK)
  {
    StatePtr->FlsJobType[BankType] = FLS_NONE;
 
    /* Update the JobResult */
    StatePtr->FlsJobResult = LastJobResult;
 
    /* Set the Bank type to the next bank */
    BankType = BANK1;
    PhysicalAddress = DFLASH_BANK1_PHYSICAL;
  }

  if(RetVal == E_OK)
  {
    if(StatePtr->FlsJobType[BankType] == FLS_ERASE)
    {
      /*3. Indicate that the ERASE Job has been started */
      StatePtr->JobStarted.U8 |= FLS_ERASE_JOBSTART;
  
      /* Enter Critical Section */
      Fls_lSchMEnter_Main();
  
      /* Execute ACCESS CODE for erase operation */
      Fls_CallEraseCommand(PhysicalAddress);
  
      /* Exit Crtical Section */
      Fls_lSchMExit_Main();
  
      #ifdef FLS_RAM_EMULATION_TEST
      #if (FLS_RAM_EMULATION_TEST == 1U)
      (void) FlsEmulation_Erase(PhysicalAddress);
      #endif
      #endif
  
      SeqProtErr = Fls_lChkSeqProtErrors();
      /* Check for Sequence error,Protection error bit */
      if(SeqProtErr)
      {
        /* Report Production errors to DEM */
        Fls_lDemReportError_Erase();
         
        /* Call to Fls_lErrorHandler local function */
        Fls_lErrorHandler(FLS_ERASE);
      }
      /* Check for command cycle Timeout */
      else if (StatePtr->FlsTimeoutErr == FLS_ERASE)
      {
        /* Call to Fls_lErrorHandler local function */
        Fls_lErrorHandler(FLS_ERASE); 
      }
      else
      {
        /* dummy else */
      }
    }
    else /* Job completed successfully */
    {
      /* Set to JOB_OK if no warnings  */
      LastJobResult = MEMIF_JOB_OK;
       
      #if( FLS_AC_LOAD_ON_JOB_START == STD_ON)
      Fls_lUnLoadAccessCode(FLS_ERASE);
      #endif
  
      /* Execute Clear Status command */
      Fls_ClearStatusCmdCycle();
  
      Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_ERASE_JOB;
  
      if(Fls_ConfigPtr->FlsJobEndNotificationPtr != NULL_PTR)
      {
        /* FlsJobEndNotificationPtr should be called */
        (Fls_ConfigPtr->FlsJobEndNotificationPtr)();
      }
  
      Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_NO_JOB;
  
      /* Update the global status variables */
      StatePtr->FlsJobResult = LastJobResult;
  
      /* Clear JobStarted bit for operation JobType */
      StatePtr->JobStarted.B.Erase = 0U;
  
    }/* End of Job evaluation */
  }
}


/*******************************************************************************
** Traceability : [cover parentID=DS_AS_FLS106,DS_AS_FLS167_4,
   DS_AS_FLS347_4,DS_NAS_PR1057,DS_AS403_FLS317]
                 [/cover]
********************************************************************************
** Syntax : void Fls_lMainRead(uint8  BankType)                               **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non-reentrant                                                 **
**                                                                            **
** Parameters (in) : uint8   DFlash Bank                                      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : Performs the Read operation during Interrupt/Cyclic          **
**               Job handling                                                 **
*******************************************************************************/
static void Fls_lMainRead(uint8  BankType)
{
  Fls_17_Pmu_StateType       *StatePtr;
  Fls_LengthType      ReadCount;
  MemIf_JobResultType LastJobResult;
  uint8               *SourcePtr;
  Fls_LengthType      MaxRead;

  /************* Initialise Local Variables *****************************/
  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;

  /* Get max read length according to the FLS mode */
   MaxRead = Fls_lGetReadModeLength();
    
  /* Check whether the given length is greater than MAX_READ */
  if(StatePtr->FlsReadLength > MaxRead)
  {
    /* Load Max Byte to read in one cycle */
    ReadCount = MaxRead;
    /* Decrement the count from the totalcount to read */
    StatePtr->FlsReadLength = StatePtr->FlsReadLength - ReadCount;
  }
  else
  {
    ReadCount = StatePtr->FlsReadLength;
    StatePtr->FlsReadLength = 0U;
  }

  /* Obtain the Read Address */
  SourcePtr = (uint8 *)(StatePtr->FlsReadAddress);

  /**********************************************************************/
  #ifdef FLS_RAM_EMULATION_TEST
  #if (FLS_RAM_EMULATION_TEST == 1U)
  FlsEmulation_ReadRequest.FlashAddress = StatePtr->FlsReadAddress;
  FlsEmulation_ReadRequest.Buffer = StatePtr->FlsReadBufferPtr;
  FlsEmulation_ReadRequest.Length = ReadCount;
  #endif
  #endif

  do
  {  /* Determine the physical address for reading */
     /* Check whether sourceptr reached end of Bank0 */
    if( (SourcePtr == (uint8 *)(DFLASH_BANK0_PHYSICAL + FLS_SECTOR_SIZE)) &&
        ((BankType != BANK1) &&
        (StatePtr->FlsJobType[BANK1] == FLS_READ))
      )
    {
      StatePtr->FlsReadAddress = DFLASH_BANK1_PHYSICAL;
      SourcePtr = (uint8 *)(StatePtr->FlsReadAddress);
      BankType = BANK1;
      StatePtr->FlsJobType[BANK0] = FLS_NONE;

    }

    /* READ DATA AND STORE THE DATA AT DESTINATION */
    if( (ReadCount >= FLS_WORD_SIZE) &&
        ( (((uint32)SourcePtr & 0x03U) == 0U) &&
         (((uint32)(StatePtr->FlsReadBufferPtr) & 0x03U) == 0U))
      )
    {
      /* Perform Word Read to save runtime */
      *(uint32*)(void*)(StatePtr->FlsReadBufferPtr) = 
                                           *(uint32*)(void*)SourcePtr;
      (StatePtr->FlsReadBufferPtr)+= FLS_WORD_SIZE;
      SourcePtr+= FLS_WORD_SIZE;
      ReadCount -= FLS_WORD_SIZE;
    }
    else
    {
      *(StatePtr->FlsReadBufferPtr) = *SourcePtr;
      (StatePtr->FlsReadBufferPtr)++;
      SourcePtr++;
      ReadCount--;
    }

  }while(((ReadCount)) > 0U);

  #ifdef FLS_RAM_EMULATION_TEST
  #if (FLS_RAM_EMULATION_TEST == 1U)
  {
    uint32 x;
    x = FlsEmulation_Read(FlsEmulation_ReadRequest.FlashAddress,
                    FlsEmulation_ReadRequest.Buffer,
                    FlsEmulation_ReadRequest.Length);
    if (x == E_NOT_OK)
    {
      Fls_lDemReportError_Read();
      
      /* Call to Fls_lErrorHandler local function */
      Fls_lErrorHandler(FLS_READ);
    }
  }
  #endif
  #endif

  /* Update the Read Address */
  StatePtr->FlsReadAddress = (uint32)SourcePtr;

  /* Check for single bit or double bit error */

  if(Fls_lChkBitErrors())
  {
    /* FLS106: Read Job fails due to hardware error */
    /* Report Production errors to DEM */
    Fls_lDemReportError_Read();
    
    /* Call to Fls_lErrorHandler local function */
    Fls_lErrorHandler(FLS_READ);
  }
  else
  {

    if(StatePtr->FlsReadLength == 0U)
    {
      /* Set Job Result to JOB OK if no warnings */
      LastJobResult = MEMIF_JOB_OK;
      /* 1. Clear the Job request */
      StatePtr->FlsJobType[BankType] = FLS_NONE;

      /* 2. Update the global status variables */
      StatePtr->FlsJobResult = LastJobResult;

      /* 3. Clear JobStarted bit for operation JobType */
      StatePtr->JobStarted.B.Read = 0U;

      Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_READ_JOB;

      if(Fls_ConfigPtr->FlsJobEndNotificationPtr != NULL_PTR)
      {
         /* FlsJobEndNotificationPtr should be called */
         (Fls_ConfigPtr->FlsJobEndNotificationPtr)();
      }

      Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_NO_JOB;

    }
  }
}


/*******************************************************************************
** Traceability : [cover parentID=DS_AS_FLS154,DS_AS_FLS200,
   DS_AS_FLS167_3,DS_AS_FLS347_3_FLS349,DS_NAS_PR1057,DS_AS403_FLS318]
                 [/cover]
********************************************************************************
** Syntax : void Fls_lMainCompare(uint8  BankType)                            **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non-reentrant                                                 **
**                                                                            **
** Parameters (in) : uint8   DFlash Bank                                      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : Performs the Compare operation during Interrupt/Cyclic       **
**               Job handling                                                 **
*******************************************************************************/
static void Fls_lMainCompare(uint8  BankType)
{
  Fls_17_Pmu_StateType       *StatePtr;
  Fls_LengthType      ReadCount;
  MemIf_JobResultType LastJobResult;
  uint8               *SourcePtr;
  Fls_LengthType      MaxRead;
  
  /************ Initialise Local variables ****************************/
  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;

  LastJobResult = StatePtr->FlsJobResult;

  /* Get max read length according to the FLS mode */
  MaxRead = Fls_lGetReadModeLength();
  
  /* Check whether the given length is greater than MAX_READ */
  if(StatePtr->FlsReadLength > MaxRead)
  {
    /* Load Max Byte to read in one cycle */
    ReadCount = MaxRead;
    /* Decrement the count from the totalcount to read */
    StatePtr->FlsReadLength = StatePtr->FlsReadLength - ReadCount;
  }
  else
  {
    ReadCount = StatePtr->FlsReadLength;
    StatePtr->FlsReadLength = 0U;
  }

  /* Obtain the address for the compare operation */
  SourcePtr = (uint8 *)(StatePtr->FlsReadAddress);
  /**********************************************************************/
  do
  {
    /* Get the actual physical address when BankType changes */
    /* Check whether source ptr reached to end of Bank0 */
    if((SourcePtr == (uint8 *)(DFLASH_BANK0_PHYSICAL + FLS_SECTOR_SIZE)) &&
       ( (BankType != BANK1) &&
         (StatePtr->FlsJobType[BANK1] == FLS_COMPARE))
      )
    {
      SourcePtr = (uint8 *)(DFLASH_BANK1_PHYSICAL);
      BankType = BANK1;
      StatePtr->FlsJobType[BANK0] = FLS_NONE;
    }
    
    /* Check if Address is word aligned */
    if( (((uint32)SourcePtr & (FLS_WORD_SIZE - 1U)) == 0U) && 
       ((((uint32)(StatePtr->FlsReadBufferPtr) & (FLS_WORD_SIZE - 1U)) == 0U) &&
           (ReadCount >= FLS_WORD_SIZE)  )
      )
    {
      /* COMPARE THE FLASH DATA WITH THE BUFFER DATA (Word Compare) */
      if( *(uint32*)(void*)(StatePtr->FlsReadBufferPtr) != 
          *(uint32*)(void*)SourcePtr )
      {
        LastJobResult = MEMIF_BLOCK_INCONSISTENT;
        /* No need to compare any more data */
        ReadCount = 0U;
      }
      else
      {
        StatePtr->FlsReadBufferPtr += FLS_WORD_SIZE;
        SourcePtr += FLS_WORD_SIZE;
        ReadCount -= FLS_WORD_SIZE;
      }
    }
    else
    {
      /* COMPARE THE FLASH DATA WITH THE BUFFER DATA (Byte Compare)*/
      if( *(StatePtr->FlsReadBufferPtr) != *SourcePtr )
      {
        LastJobResult = MEMIF_BLOCK_INCONSISTENT;
        /* No need to compare any more data */
        ReadCount = 0U;

      }
      else
      {
        StatePtr->FlsReadBufferPtr++;
        SourcePtr++;
        ReadCount--;
      }
    }
  }while(ReadCount > 0U);

  /* Update the compare address */
  StatePtr->FlsReadAddress = (uint32)SourcePtr;

  /* Check if Non-correctable ECC error was present thus leading to failure */
  if(Fls_lChkBitErrors())
  {
    /* FLS154: Compare Job fails due to hardware error */
    /* Report Production errors to DEM */
    Fls_lDemReportError_Compare();
    
    /* Call to Fls_lErrorHandler local function */
    Fls_lErrorHandler(FLS_COMPARE);
  }
  /* Check if block was inconsistent */
  else if(LastJobResult == MEMIF_BLOCK_INCONSISTENT)
  {
    /* Update the global status variables */
    StatePtr->FlsJobResult = LastJobResult;

    /* Clear the failed Job from Bank0 */
    if(StatePtr->FlsJobType[BANK0] == FLS_COMPARE)
    {
      StatePtr->FlsJobType[BANK0] = FLS_NONE;
    }
    /* Clear the failed Job from Bank1 */
    if(StatePtr->FlsJobType[BANK1] == FLS_COMPARE)
    {
      StatePtr->FlsJobType[BANK1] = FLS_NONE;
    }

    /*Clear JobStarted bit for operation JobType */
    StatePtr->JobStarted.B.Compare = 0U;

    /* Execute Clear Status command */
    Fls_ClearStatusCmdCycle();

    Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_COMPARE_JOB;

    if(Fls_ConfigPtr->FlsJobErrorNotificationPtr != NULL_PTR)
    {
      /* FlsJobErrorNotificationPtr should be called */
      (Fls_ConfigPtr->FlsJobErrorNotificationPtr)();
    }
    Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_NO_JOB;
  }
  /* No failures detected */
  else
  {
    /* Job completed */
    if ( StatePtr->FlsReadLength == 0U)
    {
      /* Update the result to JOB_OK if no warnings */
      LastJobResult = MEMIF_JOB_OK;

      /* 1. Update the Global Status variables */
      StatePtr->FlsJobResult = LastJobResult;

      /* 2. Clear the Job request */
      StatePtr->FlsJobType[BankType] = FLS_NONE;

      /* 3. Clear JobStarted bit for operation JobType */
      StatePtr->JobStarted.B.Compare = 0U;

      Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_COMPARE_JOB;

      if(Fls_ConfigPtr->FlsJobEndNotificationPtr != NULL_PTR)
      {
         /* FlsJobEndNotificationPtr should be called */
         (Fls_ConfigPtr->FlsJobEndNotificationPtr)();
      }

      Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_NO_JOB;

    }
    /* Job not yet completed */
    else
    {
      /* Avoid MISRA error */
    }
  }
}

/*******************************************************************************
** Traceability : [cover parentID=DS_AS_FLS105,DS_AS_FLS055,
DS_AS_FLS056,DS_AS_FLS167_2,DS_AS_FLS347_2,
DS_AS_FLS141_FLS_143_2,DS_NAS_PR1058_4,DS_NAS_PR1059,
DS_AS403_FLS316,DS_AS403_FLS314]
                 [/cover]
********************************************************************************
** Syntax : void Fls_lMainWrite(uint8 BankType)                               **
**                                                                            **
** Service ID:  None                                                          **
**                                                                            **
** Sync/Async:  Asynchronous                                                  **
**                                                                            **
** Reentrancy:  Non-reentrant                                                 **
**                                                                            **
** Parameters (in) : BankType   DFlash Bank                                   **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : Performs the Write operation during Interrupt/Cyclic         **
**               Job handling                                                 **
*******************************************************************************/
static void Fls_lMainWrite(uint8 BankType)
{
  Fls_17_Pmu_StateType       *StatePtr;
  MemIf_JobResultType LastJobResult;
  volatile uint32     PhysicalAddress;
  uint32              SeqProtErr;
  boolean             Error;
  uint8               PageLength;
  uint8               WriteMode;

  /******************* Initialise local variables ********************/
  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;

  /* Obtain the physical address for the write operations */
  if(BankType == BANK0)
  {
     PhysicalAddress = DFLASH_BANK0_PHYSICAL;
  }
  else
  {
    PhysicalAddress = DFLASH_BANK1_PHYSICAL;
  }

  /* Check for operational error */
  if(Fls_lChkOperError())
  {
    /* FLS105: Write Job fails due to hardware error */
    /* Report Production errors to DEM */
    Fls_lDemReportError_Write();
    
    Error = (boolean)TRUE;
  }
  /* Check for Program verification error */
  #if(FLS_IFX_FEE_USED == STD_OFF)
  #if(FLS_VER_ERROR_CHECK == STD_ON)
  else if((boolean)TRUE == Fls_lPverChk())
  {
    Error = (boolean)TRUE;
    Fls_lDemReportError_Write();
  }     
  #endif  /* FLS_VER_ERROR_CHECK == STD_ON */
  #endif  /* FLS_IFX_FEE_USED == STD_OFF */
  else
  {
    if( Fls_lGetWriteMode() == PAGE_WRITE )
    {
      PageLength = FLS_PAGE_SIZE;
    }
    else
    {
      PageLength = FLS_BURST_PAGE_SIZE;
    }

    #if (FLS_IFX_FEE_USED == STD_OFF)
    #if (FLS_DEV_ERROR_DETECT == STD_ON)
    /* Check for DFLASHx Page content equal to Source value */
    Error = Fls_lCheckWrittenPage((uint32)PageLength);
    #else
    Error = (boolean)FALSE;
    #endif /* FLS_DEV_ERROR_DETECT == STD_ON */
    #else
    Error = (boolean)FALSE;
    #endif /* FLS_IFX_FEE_USED == STD_OFF */

    /* PageStartAddress is incremented by PageLength bytes */
    StatePtr->FlsWriteAddress += PageLength;
    /* length is decremented by PageLength */
    StatePtr->FlsWriteLength -= PageLength;
    StatePtr->FlsWriteBufferPtr = (StatePtr->FlsWriteBufferPtr +
                                 PageLength);

  }

  if(Error == (boolean)FALSE)
  {
    /* Check for Program verification error */
    #if(FLS_IFX_FEE_USED == STD_ON)
    #if(FLS_VER_ERROR_CHECK == STD_ON)
    if ((boolean)TRUE == Fls_lPverChk())
    {
        /* update FlsPver to be used in CompareWordsSync */
      StatePtr->FlsPver = 1U;
    }
    #endif  /* FLS_VER_ERROR_CHECK == STD_ON */
    #endif  /* FLS_IFX_FEE_USED == STD_ON */
      
    /* Check for Flash write Job is finished completely  */
    if(StatePtr->FlsWriteLength == 0U)
    {
      #if( FLS_AC_LOAD_ON_JOB_START == STD_ON)
      Fls_lUnLoadAccessCode(FLS_WRITE);
      #endif

      /* Indicate Job successfully completed if no warnings seen till now */
      LastJobResult = MEMIF_JOB_OK;
      /* 1. Update the global status variables */
      StatePtr->FlsJobResult = LastJobResult;
      /* 2. Clear the Write Job */
      StatePtr->FlsJobType[BankType] = FLS_NONE;
      /* 3. Clear the Write Job Started Status bit */
      StatePtr->JobStarted.B.Write = 0U;

      /* Execute Clear Status command */
      Fls_ClearStatusCmdCycle();

      Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_WRITE_JOB;

      if(Fls_ConfigPtr->FlsJobEndNotificationPtr != NULL_PTR)
      {
        /* FlsJobEndNotificationPtr should be called */
        (Fls_ConfigPtr->FlsJobEndNotificationPtr)();
      }
      Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_NO_JOB;

    }
    else
    {
      /* Mark that the Job has been started */
      StatePtr->JobStarted.U8 |= FLS_WRITE_JOBSTART;
      /* Update the physical address if end of Bank0 is reached */
      /* Check whether PageStartAddress is reached to end of Bank0 */
      if((StatePtr->FlsWriteAddress ==(DFLASH_BANK0_PHYSICAL + FLS_SECTOR_SIZE))
          &&
         (BankType != BANK1)
        )
      {
        StatePtr->FlsWriteAddress = DFLASH_BANK1_PHYSICAL;
        PhysicalAddress = DFLASH_BANK1_PHYSICAL;
        StatePtr->FlsJobType[BANK0] = FLS_NONE;
      }

  /****************************** DET *****************************************/
      #if (FLS_IFX_FEE_USED == STD_OFF)
      #if  ( FLS_DEV_ERROR_DETECT == STD_ON )
      /* CHECK FOR DFLASHx PAGE IS ERASED */
      if(Fls_lPageEraseCheck((uint32 *)(void*)(StatePtr->FlsWriteAddress),
                           StatePtr->FlsWriteLength,FLS_SID_MAIN) == E_NOT_OK)
      {
        Error = (boolean)TRUE;
        Fls_lErrorHandler(FLS_WRITE);
      }
  /****************************************************************************/
      /* Check needed only when DET is STD_ON */
      if(Error == (boolean)FALSE)
      #endif /* FLS_DEV_ERROR_DETECT == STD_ON */
      #endif /* FLS_IFX_FEE_USED == STD_OFF */

      {
        /*Enter Critical Section*/
        Fls_lSchMEnter_Main();
        /************* CALL WRITE COMMAND CYCLES *************/
        WriteMode = Fls_lGetWriteMode();
        Fls_CallWriteCommand(PhysicalAddress,StatePtr,WriteMode);
        
        /* Exit Crtical Section */
        Fls_lSchMExit_Main();

        #ifdef FLS_RAM_EMULATION_TEST
        #if (FLS_RAM_EMULATION_TEST == 1U)
        {
          (void) FlsEmulation_Write(StatePtr->FlsWriteAddress,
                                    StatePtr->FlsWriteBufferPtr);
        }
        #endif
        #endif

        SeqProtErr = Fls_lChkSeqProtErrors();

        /* Check for Sequence error,Protection error bit */
        if(SeqProtErr)
        {
          /* Report Production errors to DEM */
          Fls_lDemReportError_Write();
          
          /* Call to Fls_lErrorHandler local function */
          Fls_lErrorHandler(FLS_WRITE);
        }
          /* Check for Command Cycle Timeout Error */
        else if (StatePtr->FlsTimeoutErr == FLS_WRITE)
        {
          /* Call to Fls_lErrorHandler local function */
          Fls_lErrorHandler(FLS_WRITE); 
        } 
        else
        {
          /* dummy else */
        }
      }
    }
  }
  else
  {
    /* Call to Fls_lErrorHandler local function */
    Fls_lErrorHandler(FLS_WRITE);
  }
}/* end of Fls_lMainWrite */


/*******************************************************************************
** Traceability : [cover parentID=DS_AS_FLS234,DS_AS_FLS233,DS_AS_FLS235]
                 [/cover]
********************************************************************************
** Syntax : void Fls_17_Pmu_Isr(void)                                         **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : void                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine is used instead of Main function if configured  **
** for Erase and Write Jobs.                                                  **
*******************************************************************************/
#if( FLS_USE_INTERRUPTS == STD_ON)
void Fls_17_Pmu_Isr(void)
{
  Fls_17_Pmu_StateType  *StatePtr;
  uint8 *ArrPtr;

  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
  ArrPtr = StatePtr->FlsJobType;

  if( (ArrPtr[BANK0] != FLS_NONE) ||
      (ArrPtr[BANK1] != FLS_NONE)
    )
  {
/******************************** ERASE ***************************************/
    /* Check for erase operation is pending in either of the bank */
    if(ArrPtr[BANK0] == FLS_ERASE)
    {
      if((Fls_lHWBusyCheck() == 0U) && (FLASH0_FSR.B.SPND == 0U))
      {
        /* Fls_Main_Erase operation should be called  */
        Fls_lMainErase((uint8)BANK0);
      }
    }
    else if(ArrPtr[BANK1] == FLS_ERASE)
    {
      if((Fls_lHWBusyCheck() == 0U) && (FLASH0_FSR.B.SPND == 0U))
      {
        /* Fls_Main_Erase operation should be called  */
        Fls_lMainErase((uint8)BANK1);
      }
    }
    else
    {
      /* Avoid MISRA error */
    }

/******************************** WRITE ***************************************/
    /* Check for write operation is pending in either of the bank */
    if(ArrPtr[BANK0] == FLS_WRITE)
    {
      /* Fls_Main_Write operation should be called  */
      Fls_lMainWrite((uint8)BANK0);
    }
    /* Check for write operation is pending in either of the bank */
    else if(ArrPtr[BANK1] == FLS_WRITE)
    {
      /* Fls_Main_Write operation should be called  */
      Fls_lMainWrite((uint8)BANK1);
    }
    else
    {
      /* Avoid MISRA error */
    }
  }
}
/* FLS_USE_INTERRUPTS == STD_ON */
#endif

/*******************************************************************************
** Syntax : void Fls_lErrorHandler(uint8 JobType)                             **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : JobResult                                                **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine is called when error occured during             **
**               flash operations                                             **
*******************************************************************************/
static void Fls_lErrorHandler(uint8 JobType)
{
  Fls_17_Pmu_StateType  *StatePtr;
  uint8 *ArrPtr;

  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
  ArrPtr = StatePtr->FlsJobType;

  #if( FLS_AC_LOAD_ON_JOB_START == STD_ON)
  if(JobType == FLS_ERASE)
  {
    Fls_lUnLoadAccessCode(FLS_ERASE);
  }
  else if(JobType == FLS_WRITE)
  {
    Fls_lUnLoadAccessCode(FLS_WRITE);
  }
  else
  {
    /* Avoid MISRA 60 */
  }
  #endif

  /* Clear the failed Job from Bank0 */
  if(ArrPtr[BANK0] == JobType)
  {
    ArrPtr[BANK0] = FLS_NONE;
  }
  /* Clear the failed Job from Bank1 */
  if(ArrPtr[BANK1] == JobType)
  {
    ArrPtr[BANK1] = FLS_NONE;
  }

  /* Update the global status variables */
  StatePtr->FlsJobResult = MEMIF_JOB_FAILED;

  /* Clear JobStarted bit for operation JobType */
  StatePtr->JobStarted.U8 &= ((uint8)~((uint32)1 << JobType));

  /* Execute Clear Status command */
  #ifndef IFX_FLS_DEBUG 
  Fls_ClearStatusCmdCycle();
  #endif

  Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = JobType;

  if(Fls_ConfigPtr->FlsJobErrorNotificationPtr != NULL_PTR)
  {
    /* FlsJobErrorNotificationPtr should be called */
    (Fls_ConfigPtr->FlsJobErrorNotificationPtr)();
  }

  Fls_ConfigPtr->FlsStateVarPtr->NotifCaller = FLS_NO_JOB;
}

#if(FLS_AC_LOAD_ON_JOB_START == STD_ON)
/*******************************************************************************
** Syntax : void Fls_lLoadAccessCode(uint8 JobRequest)                        **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : JobResult                                                **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine is called to load the flash access code         **
**               in to RAM.                                                   **
*******************************************************************************/
static void Fls_lLoadAccessCode(uint8 JobRequest)
{
  uint32* SrcStartPtr;
  uint32* DestPtr;
  uint32* SrcEndPtr;
  volatile uint32 Size;

  /* Loading Write Access Code */
  if(JobRequest == FLS_WRITE)
  {
    SrcStartPtr = (uint32*)(void*)(&FLS_AC_WRITE_SOURCE_START);
    DestPtr = (uint32*)(void*)(Fls_ConfigPtr->FlsAccessCodeWritePtr);
    SrcEndPtr = (uint32*)(void*)(&FLS_AC_WRITE_SOURCE_END);
  }
  /* Loading Erase Access Code */
  else
  {
    SrcStartPtr = (uint32*)(void*)(&FLS_AC_ERASE_SOURCE_START);
    DestPtr = (uint32*)(void*)(Fls_ConfigPtr->FlsAccessCodeErasePtr);
    SrcEndPtr = (uint32*)(void*)(&FLS_AC_ERASE_SOURCE_END);
  }

  Size = (uint32)SrcEndPtr - (uint32)SrcStartPtr;

  /* Copy one more word for cases where actual size is not divisible by 4*/
  if((Size & THREE_VALUE) != 0U)
  {
    Size = Size + FOUR_VALUE;
  }
  
  /* Divide the Size by 4 to get Size in words */
  Size = Size >> (uint32)TWO_VALUE; 

  /* Copy access code to RAM */
  do
  {
    *DestPtr = *SrcStartPtr;
    DestPtr++;
    SrcStartPtr++;
    Size--;
  }while(Size != 0U);
}

/*******************************************************************************
** Syntax : void Fls_lUnLoadAccessCode(uint8 JobRequest)                      **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : JobResult                                                **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : void                                                     **
**                                                                            **
** Description : This routine is called to unload the flash access code.      **
**               Basically sets the RAM code area to 0                        **
*******************************************************************************/
static void Fls_lUnLoadAccessCode(uint8 JobRequest)
{
  uint32* SrcStartPtr;
  uint32* DestPtr;
  uint32* SrcEndPtr;
  volatile uint32 Size;

  /* UnLoading Write Access Code */
  if(JobRequest == FLS_WRITE)
  {
    SrcStartPtr = (uint32*)(void*)(&FLS_AC_WRITE_SOURCE_START);
    DestPtr = (uint32*)(void*)(Fls_ConfigPtr->FlsAccessCodeWritePtr);
    SrcEndPtr = (uint32*)(void*)(&FLS_AC_WRITE_SOURCE_END);
  }
  /* UnLoading Erase Access Code */
  else
  {
    SrcStartPtr = (uint32*)(void*)(&FLS_AC_ERASE_SOURCE_START);
    DestPtr = (uint32*)(void*)(Fls_ConfigPtr->FlsAccessCodeErasePtr);
    SrcEndPtr = (uint32*)(void*)(&FLS_AC_ERASE_SOURCE_END);
  }

  Size = (uint32)SrcEndPtr - (uint32)SrcStartPtr;

  /* Copy one more word for cases where actual size is not divisible by 4*/
  if((Size & THREE_VALUE) != 0U)
  {
    Size = Size + FOUR_VALUE;
  }
  
  /* Divide the Size by 4 to get Size in words */
  Size = Size >> (uint32)TWO_VALUE;

  do
  {
    *DestPtr = ZERO_VALUE;
    DestPtr++;
    Size--;
  }while(Size != 0U);
}
#endif
/* End of FLS_AC_LOAD_ON_JOB_START == STD_ON */

/*******************************************************************************
** Syntax: static _INLINE_ boolean Fls_lSpndTimeout(uint32 TimeOutCount)      **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : TimeOutCount - Timeout count                             **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : boolean                                                  **
**                                                                            **
** Description : This routine checks if erase suspend error or timeout error  **
**               occured                                                      **
*******************************************************************************/
static _INLINE_ boolean Fls_lSpndTimeout(uint32 TimeOutCount)
{
  boolean RetVal;
  
  #ifdef IFX_FLS_DEBUG03
  if (((FLASH0_MARD.B.SPNDERR | TestFls_DebugMask03) == 1U)
                                    || (TimeOutCount == 0U))
  #else
  if ((FLASH0_MARD.B.SPNDERR == 1U) || (TimeOutCount == 0U))
  #endif
  {
    RetVal = (boolean)TRUE; 
  }
  else
  {
    RetVal = (boolean)FALSE; 
  }
  return (RetVal);
}

/*******************************************************************************
** Syntax: static _INLINE_ boolean Fls_lResmErTimeout(uint32 TimeOutCount)    **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : TimeOutCount - Timeout count                             **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : boolean                                                  **
**                                                                            **
** Description : This routine checks if erase resume timeout error occured    **
*******************************************************************************/
static _INLINE_ boolean Fls_lResmErTimeout(uint32 TimeOutCount)
{
  boolean RetVal;
  
  #ifdef IFX_FLS_DEBUG04
  TimeOutCount = TimeOutCount & TestFls_DebugMask04;
  #endif

  if (TimeOutCount == 0U)
  {
    RetVal = (boolean)TRUE; 
  }
  else
  {
    RetVal = (boolean)FALSE; 
  }
  return (RetVal);
}

/*******************************************************************************
** Syntax: static _INLINE_ boolean Fls_lPverChk(void)                         **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : boolean                                                  **
**                                                                            **
** Description : This routine checks if PVER error occured                    **
*******************************************************************************/
static _INLINE_ boolean Fls_lPverChk(void)
{
  uint32 TempFSR;
  boolean RetVal;
  
  #ifdef IFX_FLS_DEBUG
  TempFSR = (uint32)FLASH0_FSR.U | TestFls_DebugMask;
  #else
  TempFSR = (uint32)FLASH0_FSR.U;
  #endif

  if ((TempFSR & FLS_PVER_ERROR) == FLS_PVER_ERROR)
  {
    RetVal = (boolean)TRUE; 
  }
  else
  {
    RetVal = (boolean)FALSE; 
  }
  return (RetVal);
}

#if(FLS_DEV_ERROR_DETECT == STD_ON)
/*******************************************************************************
** Syntax: inline uint8 Fls_lBusyDET_Read                                     **
**                                ( const Fls_17_Pmu_StateType* StatePtr)     **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : StatePtr : FLS Global variable structure                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : ErrorFlag - DET has occured (1) or not (0)               **
**                                                                            **
** Description : This routine detects if the new Read job can be accepted     **
*******************************************************************************/
static _INLINE_ uint8 Fls_lBusyDET_Read( const Fls_17_Pmu_StateType* StatePtr )
{
  uint8 ErrorFlag;

  const uint8 *ArrPtr;
  ArrPtr = StatePtr->FlsJobType;
  ErrorFlag = 0U;

  /* No other job has been accepted */
  if((ArrPtr[0] != FLS_NONE) || (ArrPtr[1] != FLS_NONE))
  {
    Det_ReportError( (uint16)FLS_17_PMU_MODULE_ID,
                     FLS_17_PMU_INSTANCE_ID,
                     FLS_SID_READ,
                     FLS_E_BUSY);/* Report to DET */
    ErrorFlag = 1U;
  }

  return(ErrorFlag);
}

/*******************************************************************************
** Syntax: inline uint8 Fls_lBusyDET_Compare                                  **
**                                   ( const Fls_17_Pmu_StateType* StatePtr)  **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : StatePtr : FLS Global variable structure                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : ErrorFlag - DET has occured (1) or not (0)               **
**                                                                            **
** Description : This routine detects if the new Compare job can be accepted  **
*******************************************************************************/
static _INLINE_ uint8 Fls_lBusyDET_Compare
                                     ( const Fls_17_Pmu_StateType* StatePtr )
{
  uint8 ErrorFlag;
  const uint8 *ArrPtr;
  ArrPtr = StatePtr->FlsJobType;
  ErrorFlag = 0U;

  /* No other job has been accepted */
  if((ArrPtr[0] != FLS_NONE) || (ArrPtr[1] != FLS_NONE))
  {
    Det_ReportError( (uint16)FLS_17_PMU_MODULE_ID,
                     FLS_17_PMU_INSTANCE_ID,
                     FLS_SID_COMPARE,
                     FLS_E_BUSY);/* Report to DET */
    ErrorFlag = 1U;
  }

  return(ErrorFlag);
}

/*******************************************************************************
** Syntax: inline uint8 Fls_lBusyDET_Write                                    **
**                                 ( const Fls_17_Pmu_StateType* StatePtr )   **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : StatePtr : FLS Global variable structure                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : ErrorFlag - DET has occured (1) or not (0)               **
**                                                                            **
** Description : This routine detects if the new Write job can be accepted    **
*******************************************************************************/
static _INLINE_ uint8 Fls_lBusyDET_Write( const Fls_17_Pmu_StateType* StatePtr )
{
  uint8 ErrorFlag;
  const uint8 *ArrPtr;
  ArrPtr = StatePtr->FlsJobType;
  ErrorFlag = 0U;

  /* No other job has been accepted */
  if((ArrPtr[0] != FLS_NONE) || (ArrPtr[1] != FLS_NONE))
  {
    Det_ReportError( (uint16)FLS_17_PMU_MODULE_ID,
                     FLS_17_PMU_INSTANCE_ID,
                     FLS_SID_WRITE,
                     FLS_E_BUSY);/* Report to DET */
    ErrorFlag = 1U;
  }

  return(ErrorFlag);
}

/*******************************************************************************
** Syntax: inline uint8 Fls_lBusyDET_Erase                                    **
**                                 ( const Fls_17_Pmu_StateType* StatePtr)    **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : StatePtr : FLS Global variable structure                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : ErrorFlag - DET has occured (1) or not (0)               **
**                                                                            **
** Description : This routine detects if the new Erase job can be accepted    **
*******************************************************************************/
static _INLINE_ uint8 Fls_lBusyDET_Erase( const Fls_17_Pmu_StateType* StatePtr )
{
  uint8 ErrorFlag;

  const uint8 *ArrPtr;
  ArrPtr = StatePtr->FlsJobType;
  ErrorFlag = 0U;

  /* No other job has been accepted */
  if((ArrPtr[0] != FLS_NONE) || (ArrPtr[1] != FLS_NONE))
  {
    Det_ReportError( (uint16)FLS_17_PMU_MODULE_ID,
                     FLS_17_PMU_INSTANCE_ID,
                     FLS_SID_ERASE,
                     FLS_E_BUSY);/* Report to DET */
    ErrorFlag = 1U;
  }

  return(ErrorFlag);
}

/*******************************************************************************
** Syntax: static  uint8 Fls_lUninitDET( const uint8 ServiceID )              **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : JobResult                                                **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : ErrorFlag - DET has occured (1) or not (0)               **
**                                                                            **
** Description : This routine performs the UNINIT DET check                   **
*******************************************************************************/
static uint8 Fls_lUninitDET( const uint8 ServiceID )
{
  uint8 ErrorFlag;

  ErrorFlag = 0U;
  #if (FLS_PB_FIXEDADDR == STD_OFF)
  if(Fls_ConfigPtr == NULL_PTR)
  #else
  if(Fls_ConfigPtr->FlsStateVarPtr->DriverInitialised == (boolean)FALSE)
  #endif
  {
     /* Report to DET */
     Det_ReportError( (uint16)FLS_17_PMU_MODULE_ID, 
                       FLS_17_PMU_INSTANCE_ID,ServiceID,
                      FLS_E_UNINIT);/* Report to DET */

     ErrorFlag = 1U;
  }

  return (ErrorFlag);
}

/*******************************************************************************
** Syntax: static  uint8 Fls_lTimeOutDET( const uint8 ServiceID )             **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : ServiceID                                                **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : ErrorFlag - DET has occured (1) or not (0)               **
**                                                                            **
** Description : This routine performs the TIMEOUT DET check                  **
*******************************************************************************/
static uint8 Fls_lTimeOutDET(const uint8 ServiceID)
{
  Fls_17_Pmu_StateType  *StatePtr;
  uint8 ErrorFlag;
  
  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;

  ErrorFlag = 0U;
  
  if(StatePtr->JobStarted.U8 & FLS_ERASE_JOBSTART)
  {
    if(StatePtr->FlsEraseTimeoutCycleCount == 0U)
    {
      ErrorFlag = 1U;
    }
    else
    {
      StatePtr->FlsEraseTimeoutCycleCount--;
    }
  }

  if(StatePtr->JobStarted.U8 & FLS_WRITE_JOBSTART)
  {
    if(StatePtr->FlsWriteTimeoutCycleCount == 0U)
    {
      ErrorFlag = 1U;
    }
    else
    {
      StatePtr->FlsWriteTimeoutCycleCount--;
    }
  }
  
  if(ErrorFlag == 1U)
  {
    /* Report timeout DEM */
    Det_ReportError( (uint16)FLS_17_PMU_MODULE_ID, 
                   FLS_17_PMU_INSTANCE_ID,ServiceID,
                   FLS_E_TIMEOUT);/* Report to DET */
  }
  
  return ErrorFlag;    
}

/*******************************************************************************
** Syntax: static _INLINE_ boolean Fls_lCheckWrittenPage(uint32 PageLength)   **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : PageLength                                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : TRUE - programing error , FALSE - No programming error   **
**                                                                            **
** Description : Checks if the page was written without errors                **
*******************************************************************************/
static _INLINE_ boolean Fls_lCheckWrittenPage(uint32 PageLength)
{
  Fls_17_Pmu_StateType   *StatePtr;
  uint32          *PageStartAddressPtr;
  uint32          *SourcePtr;
  uint32          Count;
  boolean         Error;
  
  Count = 0U;
  Error = (boolean)FALSE;
  
  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
  SourcePtr = (uint32 *)(void*)(StatePtr->FlsWriteBufferPtr);
  PageStartAddressPtr = (uint32 *)(void*)(StatePtr->FlsWriteAddress);      
  do
  {
    if(*(PageStartAddressPtr)== *(SourcePtr))
    {
      Count++;
      PageStartAddressPtr++;
      SourcePtr++;
    }
    else
    {
      /* FLS056: If the block has been not completely reprogrammed  */
      /*         after Writing a Flash block.                       */
      #if (FLS_DEV_ERROR_DETECT == STD_ON)
      Det_ReportError( (uint16)FLS_17_PMU_MODULE_ID, 
                       FLS_17_PMU_INSTANCE_ID,FLS_SID_MAIN,
                       FLS_E_VERIFY_WRITE_FAILED);/* Report to DET */
      #endif
      /* Call to Fls_lErrorHandler local function */
      Error = (boolean)TRUE;
      /*Nothing more to compare */
      Count = (PageLength/FLS_WORD_SIZE);
    }
  }while(Count < (PageLength/FLS_WORD_SIZE));
  
  if(Error == (boolean)FALSE)
  {
    /* Check for Non-correctable ECC errors during the above check */
    if(Fls_lChkBitErrors())
    {
       /* Report to DET */
       #if (FLS_DEV_ERROR_DETECT == STD_ON)           
       Det_ReportError( (uint16)FLS_17_PMU_MODULE_ID,FLS_17_PMU_INSTANCE_ID,
                        FLS_SID_MAIN,FLS_E_VERIFY_WRITE_FAILED);
       #endif
       Error = (boolean)TRUE;
    }
  }
  return Error;
}

/*******************************************************************************
** Syntax: static _INLINE_ void  Fls_lCalculateWriteTimeoutCount(void)        **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : None                                                     **
**                                                                            **
** Description : Calculates the write timeout count                           **
*******************************************************************************/
static _INLINE_ void Fls_lCalculateWriteTimeoutCount(void)
{
  Fls_17_Pmu_StateType   *StatePtr;
  uint32          Length;
  uint32          WriteTimeOutCount;
  uint32          PageStartAddress;

  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
  
  PageStartAddress = StatePtr->FlsWriteAddress;
  Length = StatePtr->FlsWriteLength;
  /* Update Timeout count for write */
  WriteTimeOutCount =
        (uint32)(FLS_17_PMU_WRITE_TIME / Fls_ConfigPtr->FlsCallCycle);
  if(WriteTimeOutCount == 0U)
  {
    WriteTimeOutCount = 1U;
  }
  else 
  { 
    if((FLS_17_PMU_WRITE_TIME % Fls_ConfigPtr->FlsCallCycle) != 0U)
    {
      WriteTimeOutCount++;
    }
  }
  
  while(Length > FLS_PAGE_SIZE)
  {
    if( (Length <= (FLS_BURST_PAGE_SIZE - FLS_PAGE_SIZE)) ||
        ((PageStartAddress & (FLS_BURST_PAGE_SIZE - 1U)) != 0U) )
    {
      Length -= FLS_PAGE_SIZE;
      PageStartAddress += FLS_PAGE_SIZE;
    }
    else
    {
      Length -= FLS_BURST_PAGE_SIZE;
      PageStartAddress += FLS_BURST_PAGE_SIZE;
    }
    WriteTimeOutCount++;        
  }
  
  /* Add one extra count since MainFunction needs to be called once after
     all the data is written for checking errors and to set status */
  StatePtr->FlsWriteTimeoutCycleCount = (WriteTimeOutCount + 1U);
}

/*******************************************************************************
**Syntax:static _INLINE_ Std_ReturnType Fls_lPageEraseCheck(                  **
**                                                  uint32* AddrCheckPtr,     **
**                                                  uint32 Length,            **
**                                                  const uint8 ServiceID)    **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : AddrCheckPtr - address of the page, Length - page length **
**                   ServiceID - Service ID of the API for the DET            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : E_OK - page was erased correctly                         **
**                   E_NOT_OK - Page was not erased correctly                 **
**                                                                            **
** Description : Checks if the page was erased correctly                      **
*******************************************************************************/
static _INLINE_ Std_ReturnType Fls_lPageEraseCheck(const uint32 * AddrCheckPtr, 
                                                   uint32 Length,
                                                   const uint8 ServiceID)
{
  Std_ReturnType  RetVal;
  uint8           Loop;
  uint8           PageLength;
  
  RetVal = E_OK;
  
  Loop = 0U;
  
  if( (Length <= (FLS_BURST_PAGE_SIZE - FLS_PAGE_SIZE)) ||
      ((((uint32)AddrCheckPtr) & (FLS_BURST_PAGE_SIZE - 1U)) != 0U) )
  {
    PageLength = FLS_PAGE_SIZE;
  }
  else
  {
    PageLength = FLS_BURST_PAGE_SIZE;
  }
  
  do
  {
    if((*(AddrCheckPtr)) == 0U)
    {
       Loop++;
       AddrCheckPtr++;
    }
    else
    {
       /* FLS055: Before Writing if block is not completely erased.*/
       /* Call to Fls_lErrorHandler local function */
       #if (FLS_DEV_ERROR_DETECT == STD_ON)
       Det_ReportError( (uint16)FLS_17_PMU_MODULE_ID, 
                        FLS_17_PMU_INSTANCE_ID,ServiceID,
                        FLS_E_VERIFY_ERASE_FAILED);/* Report to DET */
       #endif

       RetVal = E_NOT_OK; /* Return from FSunction */
    }
  } while((RetVal == E_OK) && (Loop < (PageLength/FLS_WORD_SIZE)));
  
  return RetVal;
}

#endif
/* FLS_DEV_ERROR_DETECT == STD_ON */

/*******************************************************************************
** Syntax:static _INLINE_ uint8 Fls_lGetWriteMode(void);                      **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : PAGE_WRITE - Page write to be done                       **
**                   BURST_WRITE - Burst write to be done                     **
**                                                                            **
** Description : Checks if the page was erased correctly                      **
*******************************************************************************/
static _INLINE_ uint8 Fls_lGetWriteMode(void)
{
  Fls_17_Pmu_StateType   *StatePtr;
  uint8           RetVal;
 
  RetVal = BURST_WRITE;
  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
  
  if( (StatePtr->FlsWriteLength <= (FLS_BURST_PAGE_SIZE - FLS_PAGE_SIZE)) ||
       ((StatePtr->FlsWriteAddress & (FLS_BURST_PAGE_SIZE - 1U)) != 0U) )
  {
    RetVal = PAGE_WRITE;
  }
  
  return RetVal;
}

/*******************************************************************************
** Syntax:static _INLINE_ Fls_LengthType Fls_lGetReadModeLength(void);        **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : max read length as per read mode                         **
**                                                                            **
** Description : Get max read length according to the FLS mode                **
*******************************************************************************/
static _INLINE_ Fls_LengthType Fls_lGetReadModeLength(void)
{
  Fls_17_Pmu_StateType   *StatePtr;
  Fls_LengthType  MaxRead;
 
  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;
  MaxRead = Fls_ConfigPtr->FlsFastRead;
  
  if(StatePtr->FlsMode == MEMIF_MODE_SLOW)
  {
    MaxRead = Fls_ConfigPtr->FlsSlowRead;
  }
  
  return MaxRead;
}

/*******************************************************************************
** Syntax: static _INLINE_ uint32 Fls_lChkSeqProtErrors(void)                 **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Seq and protection bits of FSR                           **
**                                                                            **
** Description : Checks for seq and protection errors                         **
*******************************************************************************/
static _INLINE_ uint32 Fls_lChkSeqProtErrors(void)
{
  uint32 RetVal;
  #ifndef FLS_RAM_EMULATION_TEST
  #ifdef IFX_FLS_DEBUG
  RetVal = (( (uint32)FLASH0_FSR.U | TestFls_DebugMask )& FLS_PROER_SQER_ERROR);
  #else
  RetVal = ((uint32)FLASH0_FSR.U & FLS_PROER_SQER_ERROR);
  #endif
  #else
  RetVal = (FlsEmulation_ReadStatusRegister() & FLS_PROER_SQER_ERROR);
  #endif
 
 return RetVal;
}


/*******************************************************************************
** Syntax: static _INLINE_ uint32 Fls_lChkOperError(void)                     **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : operational error bit of FSR                             **
**                                                                            **
** Description : Checks for operational error                                 **
*******************************************************************************/
static _INLINE_ uint32 Fls_lChkOperError(void)
{
  Fls_17_Pmu_StateType   *StatePtr;
  uint32 RetVal;
  
  StatePtr = Fls_ConfigPtr->FlsStateVarPtr;

  #ifndef FLS_RAM_EMULATION_TEST
  #ifdef IFX_FLS_DEBUG
  RetVal = (( (uint32)FLASH0_FSR.U | TestFls_DebugMask )& FLS_OPER_ERROR);
  #else
  RetVal = ((uint32)FLASH0_FSR.U & FLS_OPER_ERROR);
  #endif
  #else
  RetVal = (FlsEmulation_ReadStatusRegister() & FLS_OPER_ERROR);
  #endif
  
  if(RetVal != 0U)
  {
    StatePtr->FlsOper = 1U;
  }
  
  if(StatePtr->FlsOper != 0U)
  {
    RetVal = FLS_OPER_ERROR;
    if(Fls_ConfigPtr->FlsIllegalStateNotificationPtr != NULL_PTR)
    {
       /* FlsIllegalStateNotificationPtr should be called */
       (Fls_ConfigPtr->FlsIllegalStateNotificationPtr)();
    }
  }
  
  return (RetVal);
}

/*******************************************************************************
** Syntax: static _INLINE_ uint32 Fls_lChkBitErrors(void)                     **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Non correctable bit of FSR                               **
**                                                                            **
** Description : Checks for double ECC errors                                 **
*******************************************************************************/
static _INLINE_ uint32 Fls_lChkBitErrors(void)
{
  uint32 RetVal;
  #ifndef FLS_RAM_EMULATION_TEST
  #ifdef IFX_FLS_DEBUG
  RetVal = (( (uint32)FLASH0_FSR.U | TestFls_DebugMask )& FLS_BIT_ERROR);
  #else
  RetVal = ((uint32)FLASH0_FSR.U & FLS_BIT_ERROR);
  #endif
  #else
  RetVal = (FlsEmulation_ReadStatusRegister() & FLS_BIT_ERROR);
  #endif
 
 return RetVal;
}

/*******************************************************************************
** Syntax: static _INLINE_ uint32 Fls_lHWBusyCheck(void)                      **
**                                                                            **
** Service ID: None                                                           **
**                                                                            **
** Sync/Async:  Synchronous                                                   **
**                                                                            **
** Reentrancy:  Non Re-entrant                                                **
**                                                                            **
** Parameters (in) : None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value    : Busy bit of FSR                                          **
**                                                                            **
** Description : Checks for Busy status of the Data Flash Bank                **
*******************************************************************************/
static _INLINE_ uint32 Fls_lHWBusyCheck(void)
{
  uint32 RetVal;

  #ifdef IFX_FLS_DEBUG07
  RetVal = (( (uint32)FLASH0_FSR.U | TestFls_DebugMask07 ) & FLS_D0BUSY);
  #else
  #ifdef IFX_FLS_DEBUG08
  RetVal = (( (uint32)FLASH0_FSR.U & TestFls_DebugMask08 ) & FLS_D0BUSY);
  #else
  RetVal = ((uint32)FLASH0_FSR.U & FLS_D0BUSY);
  #endif
  #endif
 
  return RetVal;
}


#define FLS_17_PMU_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
