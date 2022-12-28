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
**  $FILENAME   : Gtm_Platform.c $                                           **
**                                                                           **
**  $CC VERSION : \main\12 $                                                 **
**                                                                           **
**  $DATE       : 2014-01-29 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                functionality of <> driver.                                **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Own header file, this includes own configuration file also */
#include "Gtm.h"
#include "Gtm_Local.h"
/* Include Irq definitions for IRQ */
#include "IfxSrc_reg.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define GTM_BRC_CLEAR_INTERRUPTS (0x1FFFUL)
/* Get the IRQ Mode Information from a 16 bit variable */
#define GTM_GET_MODE_VAL_16 (0xC000UL)
/* Bits to shift to get the mode information to LSB for a 16 bit variable */
#define GTM_SHIFT_TO_LSB_16 (14U)
/* Get the IRQ Enable Information from a 16 bit variable */
#define GTM_GET_IRQ_VAL_16 (0x1FFFUL)

/* Get the BRC EIRQ Enable Information from a 32 bit variable */
#define GTM_BRC_GET_EIRQ_VAL_32 (0x1FFFUL)

#define GTM_ADCCONNECT_GET_LOWER_NIBBLE (0x0FUL)
#define GTM_ADCCONNECT_GET_UPPER_NIBBLE (0xF0UL)
#define GTM_BITS_PER_ADC_CONNECTION (4U)
#define GTM_BITS_IN_U32 (32U)
#define GTM_CLEAR_INTERRUPT (3UL)
#define GTM_TOM_ATOM_CLK_POS (12U)
#define GTM_TOM_ATOM_TPWM_MODE_MASK (0x3U)

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*Memory Map of the GTM Code*/
#define GTM_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/* To set BRC sub-module as not configured*/
static _INLINE_ boolean Gtm_lGetBrcChannelUsed(uint16 CtrlVal)
{
  return(((CtrlVal & GTM_SETBRCCHANNELUNUSED) > GTM_VALUE_ZERO)?\
                                                  (boolean)TRUE:(boolean)FALSE);
}

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*******************************************************************************
** Syntax : void Gtm_lBrcConfig(void)                                         **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to initialize BRC                               **
*******************************************************************************/
 void Gtm_lBrcConfig(void)
{

  const Gtm_BrcConfigType *BrcConfigPtr;         /* Pointer to BRC Config     */
  const Gtm_BrcChannelType *BrcChannelPtr;       /* Pointer to BRC Channel    */
  Gtm_BrcType *BrcReg;                           /* Pointer to BRC Register   */

  uint8 Count;

  BrcConfigPtr = Gtm_kConfigPtr->GtmModuleConfigPtr->GtmBrcConfigPtr;
  /* Check if Brc is configured */
  if(BrcConfigPtr != NULL_PTR)
  {
    /* MISRA Rule Violation 11.4 and 1.2
       Unusual pointer cast (incompatible indirect types)
       cast from pointer to pointer
       Casting of BRC to Gtm_BrcType is done to change the base
       type of BRC as the type defined in SFR file is not flexible to
       provide an arrayed approach for accessing the BRC channels. */

    BrcReg = (Gtm_BrcType*)(void *)                                            \
                               (&(*(Ifx_GTM_BRCx*)(void *)(&(MODULE_GTM.BRC))));


    /* Check if any Brc Channel is configured */
    if(BrcConfigPtr->BrcChannelPtr != NULL_PTR)
    {
      for(Count = GTM_ZERO_U; Count < GTM_NUMBER_OF_BRC_SOURCE; Count++)
      {
        /* MISRA Rule Violation 17.4
           Pointer arithmetic other than array indexing used
           This cannot be avoided because of Post Build structure */

        BrcChannelPtr = &(BrcConfigPtr->BrcChannelPtr[Count]);


        /* Check if the Channel is configured */
        if(Gtm_lGetBrcChannelUsed(BrcChannelPtr->BrcChannelCtrl) == \
                                                                 (boolean)FALSE)
        {
          BrcReg->BrcSrc[Count].SRC_ADDR.U =                  \
                                        (uint32)(BrcChannelPtr->BrcChannelCtrl);
          BrcReg->BrcSrc[Count].SRC_DEST.U = BrcChannelPtr->BrcDestination;
        }
      }
    }
    /* Clear pending interrupts */
    BrcReg->IRQ_NOTIFY.U = GTM_BRC_CLEAR_INTERRUPTS;
    BrcReg->IRQ_MODE.U =                                      \
         (uint32_t)(((uint32)BrcConfigPtr->BrcIrqEnable & GTM_GET_MODE_VAL_16) \
         >> GTM_SHIFT_TO_LSB_16);
    BrcReg->IRQ_EN.U =                                        \
            (uint32_t)((uint32)BrcConfigPtr->BrcIrqEnable & GTM_GET_IRQ_VAL_16);

    BrcReg->EIRQ_EN.U =(uint32_t)                                              \
    ((uint32)BrcConfigPtr->BrcErrIrqEnable & GTM_BRC_GET_EIRQ_VAL_32);

    /* Enable SRN */
    MODULE_SRC.GTM.GTM[0].BRCIRQ.U |= (uint32_t)(GTM_BIT_SET << GTM_BIT_SRE);
  }
}

/*******************************************************************************
** Syntax : void Gtm_lAdcConnectionsConfig(void)                              **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to initialize ADC Connections                   **
*******************************************************************************/
 void Gtm_lAdcConnectionsConfig(void)
{
  uint32 RegTemp1;          /* Temporary variable to store the register value */
  uint32 RegTemp2;          /* Temporary variable to store the register value */
  uint8 Count;

  /* Check if Adc Connections is configured */
  if(Gtm_kConfigPtr->GtmModuleConfigPtr->GtmAdcConnectionsPtr != NULL_PTR)
  {
    RegTemp1 = GTM_ZERO_UL;
    RegTemp2 = GTM_ZERO_UL;

    /* MISRA Rule Violation 17.4
       Pointer arithmetic other than array indexing used
       This cannot be avoided because of Post Build structure */

    for(Count=GTM_ZERO_U; Count < GTM_ADC_CONN_PER_REGISTER; Count++)
    {
      RegTemp1 |=                                                              \
       ((uint32)Gtm_kConfigPtr->GtmModuleConfigPtr->GtmAdcConnectionsPtr[Count]\
                                   & GTM_ADCCONNECT_GET_LOWER_NIBBLE) <<      \
                                    (GTM_BITS_PER_ADC_CONNECTION * Count);
      RegTemp2 |=                                                              \
      (((uint32)Gtm_kConfigPtr->GtmModuleConfigPtr->GtmAdcConnectionsPtr[Count]\
            & GTM_ADCCONNECT_GET_UPPER_NIBBLE) >> GTM_BITS_PER_ADC_CONNECTION)\
            << (GTM_BITS_PER_ADC_CONNECTION * Count);

    }
    GTM_ADCTRIG0OUT0.U = (uint32)RegTemp1;
    GTM_ADCTRIG1OUT0.U = (uint32)RegTemp2;


    RegTemp1 = GTM_ZERO_UL;
    RegTemp2 = GTM_ZERO_UL;
    for(Count=GTM_ZERO_U;
        Count < (GTM_NO_OF_ADC_MODULES - GTM_ADC_CONN_PER_REGISTER);
        Count++)
    {
      RegTemp1 |=                                                              \
      ((uint32)Gtm_kConfigPtr->GtmModuleConfigPtr->GtmAdcConnectionsPtr \
      [Count+GTM_ADC_CONN_PER_REGISTER] & GTM_ADCCONNECT_GET_LOWER_NIBBLE) <<
                 (GTM_BITS_PER_ADC_CONNECTION * Count);
      RegTemp2 |=                                                              \
     (((uint32)Gtm_kConfigPtr->GtmModuleConfigPtr->GtmAdcConnectionsPtr \
     [Count+GTM_ADC_CONN_PER_REGISTER] & GTM_ADCCONNECT_GET_UPPER_NIBBLE) >>  \
          GTM_BITS_PER_ADC_CONNECTION) << (GTM_BITS_PER_ADC_CONNECTION * Count);

    }
    GTM_ADCTRIG0OUT1.U = (uint32)RegTemp1;
    GTM_ADCTRIG1OUT1.U = (uint32)RegTemp2;

  }

}
/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1135_PR1137]
** Syntax : void Gtm_SelectBrcDest(uint8 SourceNo, uint32 SelDest)            **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  SourceNo – BRC source number                             **
**                   SelDest – Each bit field represents the Destination to be**
**                   selected for the BRC Source. If all destination need to  **
**                   be cleared then bit 22 should be set to activate the     **
**                   Trash bin functionality.                                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This service provides Trash bin functionality and        **
**                   Destination select for BRC Source.                       **
*******************************************************************************/
 void Gtm_SelectBrcDest(uint8 SourceNo, uint32 SelDest)
{

  ((Gtm_BrcType*)(void *)&(MODULE_GTM.BRC))->BrcSrc[SourceNo].SRC_DEST.U =
                                                              (uint32_t)SelDest;
}

/*******************************************************************************
** Syntax : void Gtm_lTomComplexConfig(void)                                  **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to initialize Complex Configuration of TOM      **
*******************************************************************************/
void Gtm_lTomComplexConfig(void)
{
  const Gtm_TomConfigType *TomChannelConfigPtr;  /* Pointer to TOM Channel    */
  Ifx_GTM_TOM_CH_TYPE *TomChannelRegPtr;       /* Ptr to TOM Channel Reg    */
  uint8 TomCnt;             /* Variable to TOM Channel Initialization Count   */
  uint8 MajorCnt;           /* Variable to maintain Loop Count                */
  uint8 MinorCnt;           /* Variable to maintain Loop Count                */
  uint8 ModuleNo;           /* Variable to hold Module Number                 */
  uint8 ChannelNo;          /* Variable to hold Channel Number                */

  /* Count to maintain track of the index in TOM Channel Config  */
  TomCnt = GTM_ZERO_U;

  /* MajorCnt -Count to maintain an index to the GtmTomUsage Array            */
  /* MinorCnt -Count to maintain an index to the channels in GtmTomUsage Array*/
  for(MajorCnt = GTM_ZERO_U;
      MajorCnt < (((GTM_MAX_TOM_CHANNELS - GTM_ONE_U)/GTM_BITS_IN_U32) +
                    GTM_ONE_U);
      MajorCnt++)
  {
    for(MinorCnt = GTM_ZERO_U;
       (MinorCnt < GTM_BITS_IN_U32) 
       &&(((MajorCnt * GTM_BITS_IN_U32)+ MinorCnt) < GTM_MAX_TOM_CHANNELS);     
       MinorCnt++)
    {
      /* Check if the channel is configured */
      if((Gtm_kConfigPtr->GtmModuleConfigPtr->GtmTomUsage[MajorCnt] &          \
        (GTM_BIT_SET << MinorCnt)) > GTM_ZERO_UL)
      {
        /* MISRA Rule Violation 17.4
           Pointer arithmetic other than array indexing used
           This cannot be avoided because of Post Build structure */

        /* Get the Pointer to the Channel Configuration Register */
        TomChannelConfigPtr =
                 &(Gtm_kConfigPtr->GtmModuleConfigPtr->GtmTomConfigPtr[TomCnt]);

        TomCnt++;
        /* Initialize the channels if the channel is configured as Complex*/
        if(TomChannelConfigPtr->TomUsage == GTM_DRIVER_COMPLEX)
        {
          /* Extract Module Number and Channel Number from the Loop Count     */
          ModuleNo = ((MajorCnt * GTM_BITS_IN_U32) + MinorCnt)/
                       GTM_CHANNELS_PER_TOM_MODULE;
          ChannelNo = MinorCnt % GTM_CHANNELS_PER_TOM_MODULE;

          /* MISRA Rule Violation 11.4 and 1.2
             Unusual pointer cast (incompatible indirect types)
             cast from pointer to pointer
             Casting of TOM to Gtm_TomChannelRegType is done to change the base
             type of TOM as the type defined in SFR file is not flexible to
             provide an arrayed approach for accessing the TOM channels. */
          /*Get the reference to the TOM channel pointer reg*/
          TomChannelRegPtr = &((((*(Ifx_GTM_TOMx*)(void *)(MODULE_GTM.TOM)).   \
                                            TOM_CH[ModuleNo])).CH[ChannelNo]);

          /* Initialize the Channel parameters */
          TomChannelRegPtr->CN0.U   =                                \
                       TomChannelConfigPtr->GtmTomChannelCfgPtr->GtmTomCn0Value;
          TomChannelRegPtr->CM0.U   =                                \
                       TomChannelConfigPtr->GtmTomChannelCfgPtr->GtmTomCm0Value;
          TomChannelRegPtr->CM1.U   =                                \
                       TomChannelConfigPtr->GtmTomChannelCfgPtr->GtmTomCm1Value;
          TomChannelRegPtr->SR0.U   =                                \
                       TomChannelConfigPtr->GtmTomChannelCfgPtr->GtmTomSr0Value;
          TomChannelRegPtr->SR1.U   =                                \
                       TomChannelConfigPtr->GtmTomChannelCfgPtr->GtmTomSr1Value;

          TomChannelRegPtr->IRQ_MODE.U = \
                                     (uint32)TomChannelConfigPtr->GtmTomIrqMode;
          TomChannelRegPtr->CTRL.U = TomChannelConfigPtr->GtmTomControlWord;

          /* Clear the Pending Interrupts */
          TomChannelRegPtr->IRQ_NOTIFY.U = GTM_CLEAR_INTERRUPT;
          TomChannelRegPtr->IRQ_EN.U =                                \
                  (uint32)TomChannelConfigPtr->GtmTomChannelCfgPtr->GtmTomIrqEn;

          /* Enable SRN */
          MODULE_SRC.GTM.GTM[0].TOM[ModuleNo][ChannelNo/2U].U |=          \
                                       (uint32_t)(GTM_BIT_SET << GTM_BIT_SRE);

        }
      }
    }
  }
}

/*******************************************************************************
** Syntax : void Gtm_lAtomComplexConfig(void)                                 **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to initialize ATOM Complex Channels             **
*******************************************************************************/
void Gtm_lAtomComplexConfig(void)
{
  const Gtm_AtomConfigType *AtomChannelConfigPtr;/* Pointer to ATOM Channel   */
  Ifx_GTM_ATOM_CH_TYPE* AtomChannelRegPtr;      /* Ptr to ATOM Channel Reg   */
  uint8 AtomCnt;            /* Variable to ATOM Channel Initialization Count  */
  uint8 MajorCnt;           /* Variable to maintain Loop Count                */
  uint8 MinorCnt;           /* Variable to maintain Loop Count                */
  uint8 ModuleNo;           /* Variable to hold Module Number                 */
  uint8 ChannelNo;          /* Variable to hold Channel Number                */

  /* Count to maintain track of the index in ATOM Channel Config */
  AtomCnt = GTM_ZERO_U;

  /* MajorCnt -Count to maintain an index to the GtmAtomUsage Array           */
  /* MinorCnt -Count to maintain an index to the channels in GtmAtomUsage
     Array */
  for(MajorCnt = GTM_ZERO_U;
      MajorCnt < (((GTM_MAX_ATOM_CHANNELS - GTM_ONE_U)/GTM_BITS_IN_U32) +
                   GTM_ONE_U);
      MajorCnt++)
  {
   
    for(MinorCnt = GTM_ZERO_U;
       (MinorCnt < GTM_BITS_IN_U32) &&
       (((MajorCnt * GTM_BITS_IN_U32) + MinorCnt) < GTM_MAX_ATOM_CHANNELS);
       MinorCnt++)
    {
      /* Check if the channel is configured */
      if((Gtm_kConfigPtr->GtmModuleConfigPtr->GtmAtomUsage[MajorCnt] &
         (GTM_BIT_SET << MinorCnt)) > GTM_ZERO_UL)
      {

        /* Get the Pointer to the Channel Configuration Register */
        AtomChannelConfigPtr =           \
               &(Gtm_kConfigPtr->GtmModuleConfigPtr->GtmAtomConfigPtr[AtomCnt]);


        AtomCnt++;
        /* Initialize the channels if the channel is configured as Complex*/
        if(AtomChannelConfigPtr->GtmAtomUsage == GTM_DRIVER_COMPLEX)
        {
          /* Extract Module Number and Channel Number from the Loop Count     */
          ModuleNo = ((MajorCnt * 32U) + MinorCnt)/GTM_CHANNELS_PER_ATOM_MODULE;
          ChannelNo = MinorCnt%GTM_CHANNELS_PER_ATOM_MODULE;

          AtomChannelRegPtr =  &((*(Ifx_GTM_ATOMx*)(void *)
                       (MODULE_GTM.ATOM)).ATOM_CH[ModuleNo].CH[ChannelNo]);


          /* Initialize the Channel parameters */
          AtomChannelRegPtr->CN0.U   =                              \
                    AtomChannelConfigPtr->GtmAtomChannelCfgPtr->GtmAtomCn0Value;
          AtomChannelRegPtr->CM0.U   =                              \
                    AtomChannelConfigPtr->GtmAtomChannelCfgPtr->GtmAtomCm0Value;
          AtomChannelRegPtr->CM1.U   =                              \
                    AtomChannelConfigPtr->GtmAtomChannelCfgPtr->GtmAtomCm1Value;
          AtomChannelRegPtr->SR0.U   =                              \
                    AtomChannelConfigPtr->GtmAtomChannelCfgPtr->GtmAtomSr0Value;
          AtomChannelRegPtr->SR1.U   =                              \
                    AtomChannelConfigPtr->GtmAtomChannelCfgPtr->GtmAtomSr1Value;

          AtomChannelRegPtr->RDADDR.U  =                            \
                 AtomChannelConfigPtr->GtmAtomChannelCfgPtr->GtmAtomRdAddrValue;
          AtomChannelRegPtr->IRQ_MODE.U =                            \
                                   (uint32)AtomChannelConfigPtr->GtmAtomIrqMode;
          AtomChannelRegPtr->CTRL.U = AtomChannelConfigPtr->GtmAtomControlWord;

          /* Clear the Pending Interrupts */
          AtomChannelRegPtr->IRQ_NOTIFY.U = GTM_CLEAR_INTERRUPT;
          AtomChannelRegPtr->IRQ_EN.U = \
               (uint32)AtomChannelConfigPtr->GtmAtomChannelCfgPtr->GtmAtomIrqEn;

          /* Enable SRN */
          MODULE_SRC.GTM.GTM[0].ATOM[ModuleNo][ChannelNo/2U].U |=         \
                                         (uint32_t)(GTM_BIT_SET << GTM_BIT_SRE);

        }
      }
    }
  }
}

/*******************************************************************************
** Syntax : void Gtm_lTomClockSetting(void)                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to initialize TOM Clock information             **
*******************************************************************************/
void Gtm_lTomClockSetting(void)
{
  const Gtm_TomConfigType *TomChannelConfigPtr;  /* Pointer to TOM Channel    */
  Ifx_GTM_TOM_CH_TYPE *TomChannelRegPtr;         /* Ptr to TOM Channel Reg    */
  Ifx_GTM_TOM_TGC_TYPE *TomTgcRegPtr;            /* Pointer to TOM TGC Reg    */
  uint8 TomCnt;             /* Variable to TOM Channel Initialization Count   */
  uint8 MajorCnt;           /* Variable to maintain Loop Count                */
  uint8 MinorCnt;           /* Variable to maintain Loop Count                */
  uint8 ModuleNo;           /* Variable to hold Module Number                 */
  uint8 ChannelNo;          /* Variable to hold Channel Number                */
  uint8 TgcNumber;          /* Variable to hold TGC Number                    */



  /* Clock Setting for GPT and PWM Modules */
  /* Count to maintain track of the index in TOM Channel Config   */
  TomCnt = GTM_ZERO_U;
  /* MajorCnt -Count to maintain an index to the GtmTomUsage Array            */
  /* MinorCnt -Count to maintain an index to the channels in GtmTomUsage Array*/
  for(MajorCnt = GTM_ZERO_U;
      MajorCnt < (((GTM_MAX_TOM_CHANNELS - GTM_ONE_U)/GTM_BITS_IN_U32) +
                                                                     GTM_ONE_U);
      MajorCnt++)
  {
    for(MinorCnt = GTM_ZERO_U;
       (MinorCnt < GTM_BITS_IN_U32) 
       &&(((MajorCnt * GTM_BITS_IN_U32)+ MinorCnt) < GTM_MAX_TOM_CHANNELS);     
       MinorCnt++)
    {
      /* Check if the TOM channel is configured */
      if((Gtm_kConfigPtr->GtmModuleConfigPtr->GtmTomUsage[MajorCnt] &          \
                                       (GTM_BIT_SET << MinorCnt)) > GTM_ZERO_UL)
      {
        /* MISRA Rule Violation 17.4
           Pointer arithmetic other than array indexing used
           This cannot be avoided because of Post Build structure */

        /* Get reference to the Channel configuration */
        TomChannelConfigPtr =                                                  \
                 &(Gtm_kConfigPtr->GtmModuleConfigPtr->GtmTomConfigPtr[TomCnt]);

        TomCnt++;
        /* Check if the channel is configured for GPT or PWM */
        {
          /* Extract module number and channel number from the Loop
             Count information */
          ModuleNo = ((MajorCnt * GTM_BITS_IN_U32) + MinorCnt)/
                                                    GTM_CHANNELS_PER_TOM_MODULE;
          ChannelNo = MinorCnt % GTM_CHANNELS_PER_TOM_MODULE;
          TgcNumber =                                                          \
                 (MinorCnt/GTM_TOM_CHANNELS_PER_TGC) % GTM_NO_OF_TGC_PER_MODULE;

          /* MISRA Rule Violation 11.4 and 1.2
             Unusual pointer cast (incompatible indirect types)
             cast from pointer to pointer
             Casting of TOM to Gtm_TomChannelRegType is done to change the base
             type of TOM as the type defined in SFR file is not flexible to
             provide an arrayed approach for accessing the TOM channels. */

          /* Get reference to the Channel Register */
          TomChannelRegPtr = &((((*(Ifx_GTM_TOMx*)(void *)(MODULE_GTM.TOM)).   \
                                             TOM_CH[ModuleNo])).CH[ChannelNo]);


          /*Set the CTRL value*/
          TomChannelRegPtr->CTRL.B.CLK_SRC_SR  =                               \
            ((TomChannelConfigPtr->GtmTomControlWord) >> GTM_TOM_ATOM_CLK_POS);
           
          
          /*Set the IRQ_MODE value*/

          TomChannelRegPtr->IRQ_MODE.U = TomChannelConfigPtr->GtmTomIrqMode;
          /*Get the TGC reg pointer reference*/
          TomTgcRegPtr = &(((*(Ifx_GTM_TOMx*)(void *)(MODULE_GTM.TOM)).
                                TOM_TGC[ModuleNo].TGC[TgcNumber]));
          /*Set the FUPD_CTRL value*/
          TomTgcRegPtr->FUPD_CTRL.U |=                               \
                         (uint32_t)(GTM_TOM_ENABLE << (GTM_TOM_BITS_PER_CHAN * \
                         (ChannelNo% GTM_TOM_CHANNELS_PER_TGC)));
          /* Enable SRN */
          MODULE_SRC.GTM.GTM[0].TOM[ModuleNo][ChannelNo/2U].U |=          \
                                         (uint32_t)(GTM_BIT_SET << GTM_BIT_SRE);
        }
      }
    }
  }
}

/*******************************************************************************
** Syntax : void Gtm_lAtomClockSetting(void)                                  **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non-reentrant                                            **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Function to configure ATOM clock                         **
*******************************************************************************/
void Gtm_lAtomClockSetting(void)
{
  const Gtm_AtomConfigType *AtomChannelConfigPtr;/* Pointer to ATOM Channel   */
  Ifx_GTM_ATOM_CH_TYPE *AtomChannelRegPtr;      /* Ptr to ATOM Channel Reg   */
  Ifx_GTM_ATOM *AtomAgcRegPtr;             /* Pointer to ATOM Reg   */
  uint8 AtomCnt;            /* Variable to ATOM Channel Initialization Count  */
  uint8 MajorCnt;           /* Variable to maintain Loop Count                */
  uint8 MinorCnt;           /* Variable to maintain Loop Count                */
  uint8 ModuleNo;           /* Variable to hold Module Number                 */
  uint8 ChannelNo;          /* Variable to hold Channel Number                */



  /* Clock Setting for GPT and PWM Modules */
  /* Count to maintain track of the index in ATOM Channel Config */
  AtomCnt = GTM_ZERO_U;
  /* MajorCnt -Count to maintain an index to the GtmTomUsage Array            */
  /* MinorCnt -Count to maintain an index to the channels in GtmTomUsage Array*/
  for(MajorCnt = GTM_ZERO_U;
      MajorCnt < (((GTM_MAX_ATOM_CHANNELS - GTM_ONE_U)/GTM_BITS_IN_U32) +
                    GTM_ONE_U);
      MajorCnt++)
  {
    for(MinorCnt = GTM_ZERO_U;
       (MinorCnt < GTM_BITS_IN_U32) &&
       (((MajorCnt * GTM_BITS_IN_U32) + MinorCnt) < GTM_MAX_ATOM_CHANNELS);
       MinorCnt++)
    {
      /* Check if the ATOM channel is configured */
      if((Gtm_kConfigPtr->GtmModuleConfigPtr->GtmAtomUsage[MajorCnt] &
                                       (GTM_BIT_SET << MinorCnt)) > GTM_ZERO_UL)
      {
        /* MISRA Rule Violation 17.4
           Pointer arithmetic other than array indexing used
           This cannot be avoided because of Post Build structure */

        /* Get reference to the Channel configuration */
        AtomChannelConfigPtr =
               &(Gtm_kConfigPtr->GtmModuleConfigPtr->GtmAtomConfigPtr[AtomCnt]);


        AtomCnt++;

          /* Extract module number and channel number from the Loop
             Count information */
          ModuleNo = ((MajorCnt * GTM_BITS_IN_U32) + MinorCnt)/
                       GTM_CHANNELS_PER_ATOM_MODULE;
          ChannelNo = MinorCnt % GTM_CHANNELS_PER_ATOM_MODULE;

          /* Get reference to the Channel Register */
          AtomChannelRegPtr = &((*(Ifx_GTM_ATOMx*)(void *)
                       (MODULE_GTM.ATOM)).ATOM_CH[ModuleNo].CH[ChannelNo]);
          AtomChannelRegPtr->CTRL.B.CLK_SRC  =  \
          ((AtomChannelConfigPtr->GtmAtomControlWord)>>GTM_TOM_ATOM_CLK_POS);
          AtomChannelRegPtr->CTRL.B.MODE  =  \
          ((AtomChannelConfigPtr->GtmAtomControlWord)&
                                                GTM_TOM_ATOM_TPWM_MODE_MASK);

          AtomChannelRegPtr->IRQ_MODE.U = AtomChannelConfigPtr->GtmAtomIrqMode;

          AtomAgcRegPtr = &(MODULE_GTM.ATOM[ModuleNo]);
          AtomAgcRegPtr->AGC.FUPD_CTRL.U |=                             \
          (uint32_t)(GTM_ATOM_ENABLE << (GTM_ATOM_BITS_PER_CHAN * (ChannelNo)));

          /* Enable SRN */
          MODULE_SRC.GTM.GTM[0].ATOM[ModuleNo][ChannelNo/2U].U |=         \
                                         (uint32_t)(GTM_BIT_SET << GTM_BIT_SRE);


      }
    }
  }
}

#define GTM_STOP_SEC_CODE
#include "MemMap.h"


