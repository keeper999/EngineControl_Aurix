/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : L9960                                                                                           */
/* !Description     : Driver for H-Bridge device ST L9960                                                             */
/*                                                                                                                    */
/* !File            : L9960_Registers.c                                                                               */
/* !Description     : Encode / Decode L9960 registers                                                                 */
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
 * %PID: LIBEMB:A6098.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "Std_Types.h"
#include "L9960_Private.h"
#include "L9960_Spi.h"
#include "L9960_Types.h"

#define L9960_START_SEC_CODE
#include "L9960_MemMap.h"


/**********************************************************************************************************************/
/* !FuncName    : L9960_udtCheckConfigValuesFromFlash                                                                 */
/* !Description : This function checks if L9960 registers are well configured.                                        */
/*                Comparaison is done from FLASH values (for safety)                                                  */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
Std_ReturnType L9960_udtCheckConfigValuesFromFlash(const L9960_tstrConfig *pkstrConfig,
                                                   L9960_strData          *pstrData)
{
   uint16  u16LocExpectedRegister;
   boolean bLocResult = E_NOT_OK;
   
   /* Nested if check to leave comparaison since we detect an error */
   u16LocExpectedRegister = L9960_u16SetDefaultValueRegConfig1(pkstrConfig, pstrData);
   if(L9960_udtCheckConfigReg_1(u16LocExpectedRegister, pstrData->u16SpiMChipRegConfig1) == E_OK)
   {
      u16LocExpectedRegister = L9960_u16SetDefaultValueRegConfig2(pkstrConfig, pstrData);
      if(L9960_udtCheckConfigReg_2(u16LocExpectedRegister, pstrData->u16SpiMChipRegConfig2) == E_OK)
      {
         u16LocExpectedRegister = L9960_u16SetDefaultValueRegConfig3(pkstrConfig, pstrData);
         if(L9960_udtCheckConfigReg_3(u16LocExpectedRegister, pstrData->u16SpiMChipRegConfig3) == E_OK)
         {
            u16LocExpectedRegister = L9960_u16SetDefaultValueRegConfig4(pkstrConfig, pstrData);
            if(L9960_udtCheckConfigReg_4(u16LocExpectedRegister, pstrData->u16SpiMChipRegConfig4) == E_OK)
            {
               /* CC Config is not configurable in this SW version */
               u16LocExpectedRegister = L9960_u16SPI_RESTART_TRIGGER_CC_CONFIG;
               if(L9960_udtCheckConfigReg_5(u16LocExpectedRegister, pstrData->u16SpiMChipRegConfig5) == E_OK)
               {
                  /* All registers are OK */
                  bLocResult = E_OK;
               }
            }
         }
      }
   }
   return(bLocResult);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_udtCheckConfigValuesFromRAM                                                                   */
/* !Description : This function check if L9960 register are well configured                                           */
/*                Comparaison is done from RAM values (to use only if configuration may change on runtime)            */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
Std_ReturnType L9960_udtCheckConfigValuesFromRAM(const L9960_tstrConfig *pkstrConfig,
                                                 L9960_strData          *pstrData)
{
   boolean bLocResult = E_NOT_OK;

   COMPILER_UNUSED_PARAMETER(pkstrConfig);
   
   /* Nested if check to leave comparaison since we detect an error */
   if(L9960_udtCheckConfigReg_1( pstrData->u16SpiMChipRegConfiguration1, pstrData->u16SpiMChipRegConfig1) == E_OK)
   {
      if(L9960_udtCheckConfigReg_2( pstrData->u16SpiMChipRegConfiguration2, pstrData->u16SpiMChipRegConfig2) == E_OK)
      {
         if(L9960_udtCheckConfigReg_3( pstrData->u16SpiMChipRegConfiguration3, pstrData->u16SpiMChipRegConfig3) == E_OK)
         {
            if(L9960_udtCheckConfigReg_4( pstrData->u16SpiMChipRegConfiguration4, pstrData->u16SpiMChipRegConfig4) == E_OK)
            {
               /* CC Config is not configurable in this SW version */
               if(L9960_udtCheckConfigReg_5(L9960_u16SPI_RESTART_TRIGGER_CC_CONFIG, pstrData->u16SpiMChipRegConfig5) == E_OK)
               {
                  /* All register are ok */
                  bLocResult = E_OK;
               }
            }
         }
      }
   }
   return(bLocResult);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_utdCheckConfigReg_1                                                                           */
/* !Description : This function checks if Register Configuration1 is OK                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
Std_ReturnType L9960_udtCheckConfigReg_1(uint16 u16ConfigReg, uint16 u16CheckReg)
{
   uint16 u16LocVal;
   
   /* The #7a is exactly the same content as #3 cmd : xor will set to 0 bits which are equal */
   u16LocVal = (u16ConfigReg ^ u16CheckReg);
   
   /* Apply a mask to hide address, parity and unused bit */
   /* TODO: shall we really mask the unused bit ? as we know their execpetd values */
   return( ( ( u16LocVal & 0x0FFAu) == 0u) ? E_OK : E_NOT_OK );
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_utdCheckConfigReg_2                                                                           */
/* !Description : This function checks if Register Configuration2 is OK                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
Std_ReturnType L9960_udtCheckConfigReg_2(uint16 u16ConfigReg, uint16 u16CheckReg)
{
   uint16 u16LocVal;
   
   /* The #7b answer is close equal to cmd #4 shifted by 1 bit */
   /* but bit In1_in2_if which is bit 11 in cmd #4 and bit 12 in the #7b */
   
   /* first: isolate the In1_in2_if bit */
   u16LocVal = (uint16)( (u16CheckReg & 0x0800u) >> 1);
   
   /* shift all other bit, and clear the In1_in2_if & In0_In1 bit (and address bits) */
   u16CheckReg = (uint16)( (u16CheckReg & 0x03FFu) << 1);
   u16CheckReg = u16CheckReg | u16LocVal;  /* insert the In1_in2_if bit */
   
   /* xor will set to 0 bit which are equal */
   u16LocVal = (u16ConfigReg ^ u16CheckReg);
   
   /* Apply a mask to hide address, parity and unused bit */
   /* TODO: shall we really mask the unused bit ? as we know their execpetd values */
   return( ( ( u16LocVal & 0x0FFAu) == 0u) ? E_OK : E_NOT_OK);
}
/**********************************************************************************************************************/
/* !FuncName    : L9960_utdCheckConfigReg_3                                                                           */
/* !Description : This function checks if Register Configuration3 is OK                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
Std_ReturnType L9960_udtCheckConfigReg_3(uint16 u16ConfigReg, uint16 u16CheckReg)
{
   uint16 u16LocVal;
   
   /* The #7c answer is close equal to cmd #5 */
   /* but bit OTWARN_SEC is bit 1 in cmd #5 and bit 0 in the #7c */
   
   /* first: move the OTWARN_SEC bit */
   u16LocVal = (uint16)( (u16CheckReg & 0x0001u) << 1);
   u16CheckReg = u16CheckReg & 0xFFFDu;
   u16CheckReg = u16CheckReg | u16LocVal;
   
   /* xor will set to 0 bit which are equal */
   u16LocVal = (u16ConfigReg ^ u16CheckReg);
   
   /* Apply a mask to hide address, parity and unused bit */
   /* TODO: shall we really mask the unused bit ? as we know their expected values */
   return( ( ( u16LocVal & 0x0F82u) == 0u) ? E_OK : E_NOT_OK);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_utdCheckConfigReg_4                                                                           */
/* !Description : This function checks if Register Configuration4 is OK                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
Std_ReturnType L9960_udtCheckConfigReg_4(uint16 u16ConfigReg, uint16 u16CheckReg)
{
   COMPILER_UNUSED_PARAMETER(u16ConfigReg);
   COMPILER_UNUSED_PARAMETER(u16CheckReg);

   /* TODO : The bit TSDR echo is not yet specified */
   return(E_OK);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_utdCheckConfigReg_5                                                                           */
/* !Description : This function checks if Register Configuration5 is OK                                               */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
Std_ReturnType L9960_udtCheckConfigReg_5(uint16 u16ConfigReg, uint16 u16CheckReg)
{
   uint16 u16LocVal;
   
   /* Only bit CC has to be checked */
   /* it is located in bit 8 in u16ConfigReg and in bit 10 in u16CheckReg */
   /* CC echo bit has the inverted config value. i.e. if CC=1, then echo = 0 */
   u16ConfigReg = ( (u16ConfigReg ^ 0x0100u)  & 0x0100u) << 2;
   
   /* xor will set to 0 bit which are equal */
   u16LocVal = (u16ConfigReg ^ u16CheckReg);
   
   /* Apply a mask to hide address, parity and unused bit */
   /* TODO: shall we really mask the unused bit ? as we know their execpetd values */
   return( ( ( u16LocVal & 0x0400u) == 0u) ? E_OK : E_NOT_OK);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_u16SetDefaultValueRegConfig1                                                                  */
/* !Description : This function set u16SpiMChipRegConfiguration1 with default values                                  */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
uint16 L9960_u16SetDefaultValueRegConfig1(const L9960_tstrConfig *pkstrConfig,
                                          L9960_strData          *pstrData)
{
   uint16 u16LocRegistervalue;

   COMPILER_UNUSED_PARAMETER(pstrData);

   u16LocRegistervalue = (L9960_u16SPI_POR_VALUE_CONFIG_1 /* Power on reset value */
                        /* Bits set to 1 : */
                        | 0x0u)
                        /* Bits set to 0 : */
                        & (0xFFFFu ^ ( L9960_u16SPI_CONFIG_REG_1_DIAG_CLR_EN_MASK
                                        | L9960_u16SPI_CONFIG_REG_1_NOSR_MASK
                                        | L9960_u16SPI_CONFIG_REG_1_TSW_LOW_CUR_MASK) )
                        /* Clear bits configured by calibration */
                        & (0xFFFFu ^ ( L9960_u16SPI_CONFIG_REG_1_ISR_MASK
                                        | L9960_u16SPI_CONFIG_REG_1_VSR_MASK
                                        | L9960_u16SPI_CONFIG_REG_1_TDIAG1_MASK
                                        | L9960_u16SPI_CONFIG_REG_1_CL_MASK) );
   
   if( *(pkstrConfig->pkbCurrentSlewRate) == 1)
   {
      u16LocRegistervalue |= L9960_u16SPI_CONFIG_REG_1_ISR_MASK;
   }

   if( *(pkstrConfig->pkbVoltageSlewRate) == 1)
   {
      u16LocRegistervalue |= L9960_u16SPI_CONFIG_REG_1_VSR_MASK;
   }
   
   u16LocRegistervalue |= (uint16)(((uint16)(*(pkstrConfig->pku8CurrentLimitRange))) << L9960_u16SPI_CONFIG_REG_1_CL_POS)
                          & L9960_u16SPI_CONFIG_REG_1_CL_MASK;
   u16LocRegistervalue |= (uint16)(((uint16)(*(pkstrConfig->pku8Tdiag1))) << L9960_u16SPI_CONFIG_REG_1_TDIAG1_POS)
                          & L9960_u16SPI_CONFIG_REG_1_TDIAG1_MASK;

   return(u16LocRegistervalue);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_u16SetDefaultValueRegConfig2                                                                  */
/* !Description : This function set u16SpiMChipRegConfiguration2 with default values                                  */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
uint16 L9960_u16SetDefaultValueRegConfig2(const L9960_tstrConfig *pkstrConfig,
                                          L9960_strData          *pstrData)
{
   uint16 u16LocRegistervalue;
   
   COMPILER_UNUSED_PARAMETER(pstrData);

   u16LocRegistervalue = L9960_u16SPI_POR_VALUE_CONFIG_2
                        /* Bits set to 0 : */
                        & (0xFFFFu ^ (L9960_u16SPI_CONFIG_REG_2_IN1_IN2_IF_MASK
                                     | L9960_u16SPI_CONFIG_REG_2_UV_PROT_EN_MASK
                                     | L9960_u16SPI_CONFIG_REG_2_NSPREAD_MASK
                                     | L9960_u16SPI_CONFIG_REG_2_UV_WIN_MASK) )
                        /* Clear bits configured by calibration */
                        & (0xFFFFu ^ ( L9960_u16SPI_CONFIG_REG_2_OTSD_THR_VAR_MASK
                                      | L9960_u16SPI_CONFIG_REG_2_OTWARN_THR_VAR_MASK) );

   u16LocRegistervalue |= (uint16)(((uint16)(*(pkstrConfig->pku8OtsdThrVar))) << L9960_u16SPI_CONFIG_REG_2_OTSD_THR_VAR_POS)
                          & L9960_u16SPI_CONFIG_REG_2_OTSD_THR_VAR_MASK;
   u16LocRegistervalue |= (uint16)(((uint16)(*(pkstrConfig->pku8OtwarnThrVar))) << L9960_u16SPI_CONFIG_REG_2_OTWARN_THR_VAR_POS)
                          & L9960_u16SPI_CONFIG_REG_2_OTWARN_THR_VAR_MASK;

   return(u16LocRegistervalue);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_u16SetDefaultValueRegConfig3                                                                  */
/* !Description : This function set u16SpiMChipRegConfiguration3 with default values                                  */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
uint16 L9960_u16SetDefaultValueRegConfig3(const L9960_tstrConfig *pkstrConfig,
                                          L9960_strData          *pstrData)
{
   uint16 u16LocRegistervalue;
   
   COMPILER_UNUSED_PARAMETER(pstrData);

   u16LocRegistervalue = (L9960_u16SPI_POR_VALUE_CONFIG_3
                        /* Bits set to 1 : */
                        | L9960_u16SPI_CONFIG_REG_3_TVVL_MASK)
                        /* Bits set to 0 : */
                        & (0xFFFFu ^ (L9960_u16SPI_CONFIG_REG_3_VVL_MODE_MASK))
                        /* Clear bits configured by calibration */
                        & (0xFFFFu ^ ( L9960_u16SPI_CONFIG_REG_3_OTWARN_TSEC_EN_MASK) );

   if( *(pkstrConfig->pkbTSecure) == 1)
   {
      u16LocRegistervalue |= L9960_u16SPI_CONFIG_REG_3_OTWARN_TSEC_EN_MASK;
   }

   return(u16LocRegistervalue);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_u16SetDefaultValueRegConfig4                                                                  */
/* !Description : This function set u16SpiMChipRegConfiguration4 with default values                                  */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
uint16 L9960_u16SetDefaultValueRegConfig4(const L9960_tstrConfig *pkstrConfig,
                                          L9960_strData          *pstrData)
{
   uint16 u16LocRegistervalue;

   COMPILER_UNUSED_PARAMETER(pstrData);
   
   u16LocRegistervalue = L9960_u16SPI_POR_VALUE_CONFIG_4
                        /* Bits set to 0 : */
                        & (0xFFFFu ^ (L9960_u16SPI_CONFIG_REG_4_OL_ON_MASK))
                        /* Clear bits configured by calibration */
                        & (0xFFFFu ^ ( L9960_u16SPI_CONFIG_REG_4_TDSR_MASK) );

   if( *(pkstrConfig->pkbTemperatureDependentSlewRate) == 1)
   {
      u16LocRegistervalue |= L9960_u16SPI_CONFIG_REG_4_TDSR_MASK;
   }

   return(u16LocRegistervalue);
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidDecodeRegState1                                                                            */
/* !Description : This function decode diagnostic of "state 1" register                                               */
/*                                                                                                                    */
/*                Inputs : u16SpiMChipRegState1                                                                       */
/*                Outputs: bSupplyVoltageFault and bILimitFault                                                       */
/*                Returns: NGFAIL bit                                                                                 */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidDecodeRegState1(const L9960_tstrConfig *pkstrConfig,
                               L9960_strData          *pstrData)
{
   uint16 u16LocRegState1;

   COMPILER_UNUSED_PARAMETER(pkstrConfig);

   u16LocRegState1 = pstrData->u16SpiMChipRegState1;

   /******************************************************************************************************/
   /* Treat NGFAIL bit                                                                                   */
   /******************************************************************************************************/
   pstrData->bNgFailFault = ( ( (u16LocRegState1 & L9960_bfSTATE_1_NGFAIL_BIT) != 0)
                            ? FALSE
                            : TRUE);
                             
   /******************************************************************************************************/
   /* Treat NDIS bit                                                                                     */
   /******************************************************************************************************/
   pstrData->bNDISPinFault = ( ( (u16LocRegState1 & L9960_bfSTATE_1_NDIS_BIT) == 0)
                             ? FALSE
                             : TRUE);
                             
   /******************************************************************************************************/
   /* Treat BRIDGE_EN bit                                                                                */
   /******************************************************************************************************/
   pstrData->bHBridgeDisableFault = ( ( (u16LocRegState1 & L9960_bfSTATE_1_BRIDGE_EN_BIT) != 0)
                                  ? FALSE
                                  : TRUE);
                             
   /******************************************************************************************************/
   /* Treat Supply faults                                                                                */
   /******************************************************************************************************/
   /* Supply fault are to done unconditionnaly                                                           */
   /* decode STATE 1 register                                                                            */
   /*    VPS_UV_REG  = 1 => H Bridge Supply under voltage detected                                       */
   /*    VDD_UV_REG  = 1 => L9960 Supply under voltage detected                                          */
   /*    VDD_OV_REG  = 1 => L9960 Supply over voltage detected                                           */
   /******************************************************************************************************/
   if( (u16LocRegState1 & (L9960_bfSTATE_1_VPS_UV_REG
                          | L9960_bfSTATE_1_VDD_OV_REG
                          | L9960_bfSTATE_1_VDD_UV_REG) ) != 0)
   {
      pstrData->bSupplyVoltageFault = TRUE;
   }
   else
   {
      pstrData->bSupplyVoltageFault = FALSE;
   }

   /******************************************************************************************************/
   /* Treat Current Limit                                                                                */
   /******************************************************************************************************/
   /* This info must be stored until OTWARN is read, to concate both states                              */
   /*                                                                                                    */
   /* decode STATE 1 register                                                                            */
   /*    I_LIM        = 1 => Over Current limitation                                                     */
   /******************************************************************************************************/
   pstrData->bILimitFault = ( ( (u16LocRegState1 & L9960_bfSTATE_1_ILIM_REG_BIT) == 0)
                             ? FALSE
                             : TRUE);
   
   /******************************************************************************************************/
   /* Treat hardware Self Check                                                                          */
   /******************************************************************************************************/
   /* If HWSC = 0xx that means that a reset occurs on L9960 and a re-init need                           */
   /* We use a keyword rather than a flag to request the re-init (for safety)                            */
   /******************************************************************************************************/
   /* TODO: add a filtering to prevent to re_init the L9960 in case of a SPI read corruption ? */ 
   if( (u16LocRegState1 & L9960_bfSTATE_1_HWSC_NOT_DONE_BIT) == 0)
   {
      pstrData->bHwscNotDoneFault = TRUE;
      /* TODO : launch the L9960 re-init ... but with filtering, to not reset the L9960 because the bit */
      /* L9960_bfSTATE_1_HWSC_NOT_DONE_BIT has been corrupted on SPI line during the read */
   }

}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidDecodeRegState2                                                                            */
/* !Description : This function decode diagnostic of "state 2" register                                               */
/*                                                                                                                    */
/*                Inputs : u16SpiMChipRegState2                                                                       */
/*                Outputs: bOverTemperatureFault, bOpenLoadDiagDone and bOpenLoadLastState                            */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidDecodeRegState2(const L9960_tstrConfig *pkstrConfig,
                              L9960_strData          *pstrData)
{
   uint16 u16LocRegState2;

   COMPILER_UNUSED_PARAMETER(pkstrConfig);

   u16LocRegState2 = pstrData->u16SpiMChipRegState2;

   /******************************************************************************************************/
   /* Treat Over Temperature fault                                                                       */
   /******************************************************************************************************/
   /* decode STATE 2 register                                                                            */
   /*    NOTSD        = 1  => H Bridge is in Over Temperature                                            */
   /******************************************************************************************************/
   pstrData->bOverTemperatureFault = ( ( (u16LocRegState2 & L9960_bfSTATE_2_NOTSD_REG_BIT)  != 0)
                                     ? FALSE
                                     : TRUE);

   /******************************************************************************************************/
   /* Treat Open load faults                                                                             */
   /******************************************************************************************************/
   /* decode STATE 2 register                                                                            */
   /*    OL_ON_STATUS = XX => Result of Open Load Diagnostic                                             */
   /*                 = 00 => No diag request (so no status)                                             */
   /*                 = 01 => No diag Done    (so no status)                                             */
   /*                 = 10 => Diag Done and Open Load detected                                           */
   /*                 = 11 => Diag Done and No Open Load detected                                        */
   /******************************************************************************************************/
   if( (u16LocRegState2 & L9960_bfSTATE_2_OL_ON_DONE_BIT)  != 0)
   {
      pstrData->bOpenLoadDiagDone = TRUE;
      pstrData->bOpenLoadLastState = ( ((u16LocRegState2 & L9960_bfSTATE_2_OL_ON_DETECTED_BIT)  != 0)
                                     ? FALSE
                                     : TRUE);
   }
   else
   {
      pstrData->bOpenLoadDiagDone = FALSE;
   }
}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidDecodeRegState5                                                                            */
/* !Description : This function decode diagnostic of "state 5" register                                               */
/*                                                                                                                    */
/*                Inputs : u16SpiMChipRegConfig5                                                                      */
/*                Outputs: bCCFault, bOpenLoadDiagDone and bOpenLoadLastState                                         */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidDecodeRegState5(const L9960_tstrConfig *pkstrConfig,
                              L9960_strData          *pstrData)
{
   uint16 u16LocRegState5;

   COMPILER_UNUSED_PARAMETER(pkstrConfig);

   u16LocRegState5 = pstrData->u16SpiMChipRegConfig5;

   /******************************************************************************************************/
   /* Treat Communcation Check fault                                                                     */
   /******************************************************************************************************/
   /* decode STATE 5 register                                                                            */
   /*    CC           = 1  => H Bridge is in tristate due to SPI communication timeout                   */
   /******************************************************************************************************/
   pstrData->bCCFault = ( ( (u16LocRegState5 & L9960_bfSTATE_5_CC_BIT)  == 0)
                        ? FALSE
                        : TRUE);

}

/**********************************************************************************************************************/
/* !FuncName    : L9960_vidDecodeRegOverCurrent                                                                       */
/* !Description : This function decode diagnostic of "over current" register                                          */
/*                                                                                                                    */
/*                Inputs : u16SpiMChipRegOverCurrent                                                                  */
/*                Outputs: bOverCurrentFault and bOverLoadFault                                                       */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
void L9960_vidDecodeRegOverCurrent(const L9960_tstrConfig *pkstrConfig,
                                   L9960_strData          *pstrData)
{
   uint16  u16LocRegOverCurrent;

   COMPILER_UNUSED_PARAMETER(pkstrConfig);

   u16LocRegOverCurrent = pstrData->u16SpiMChipRegOverCurrent;

   /******************************************************************************************************/
   /* Treat Over Current and Over Load faults                                                            */
   /******************************************************************************************************/
   /* Decode OverCurrent register                                                                        */
   /*    OCH1, OCH0, OCL1, OCL0 : Status of each mos                                                     */
   /*       10 : Diag Not done or No over current detected                                               */
   /*       00 : Diag done Over Current detected                                                         */
   /*       11 : Over Load detected                                                                      */
   /*                                                                                                    */
   /* Set Over current if at least one MOS  = 00                                                         */
   /* Set Over Load if at least one MOS  = 11                                                            */
   /******************************************************************************************************/
   
   if( ( (u16LocRegOverCurrent & L9960_bfOVER_CURRENT_OCH1_BITS) == 0)
       || ( (u16LocRegOverCurrent & L9960_bfOVER_CURRENT_OCH0_BITS) == 0)
       || ( (u16LocRegOverCurrent & L9960_bfOVER_CURRENT_OCL1_BITS) == 0)
       || ( (u16LocRegOverCurrent & L9960_bfOVER_CURRENT_OCL0_BITS) == 0) )
   {
      pstrData->bOverCurrentFault = TRUE;
   }
   else
   {
      pstrData->bOverCurrentFault = FALSE;
   }

   if( ( (u16LocRegOverCurrent & L9960_bfOVER_CURRENT_OCH1_BITS) == L9960_bfOVER_CURRENT_OCH1_BITS)
         || ( (u16LocRegOverCurrent & L9960_bfOVER_CURRENT_OCH0_BITS) == L9960_bfOVER_CURRENT_OCH0_BITS)
         || ( (u16LocRegOverCurrent & L9960_bfOVER_CURRENT_OCL1_BITS) == L9960_bfOVER_CURRENT_OCL1_BITS)
         || ( (u16LocRegOverCurrent & L9960_bfOVER_CURRENT_OCL0_BITS) == L9960_bfOVER_CURRENT_OCL0_BITS) )
   {
      pstrData->bOverLoadFault = TRUE;
   }
   else
   {
      pstrData->bOverLoadFault = FALSE;
   }

}

/**********************************************************************************************************************/
/* !FuncName    : L9960_bDecodeDiagnosticOff                                                                          */
/* !Description : Decode the OFF Diagnostic result register                                                           */
/*                It returns TRUE if diag was done, else it returns FALSE                                             */
/*                                                                                                                    */
/* !LastAuthor  : L. Voilmy                                                                                           */
/**********************************************************************************************************************/
boolean L9960_bDecodeDiagnosticOff(const L9960_tstrConfig *pkstrConfig,
                                   L9960_strData          *pstrData)
{
   uint16 u16LocRegOffDiag;
   boolean bLocReturnvalue = FALSE;

   COMPILER_UNUSED_PARAMETER(pkstrConfig);
   /* TODO: do a consistency check on register value  ? */

   /******************************************************************************************************/
   /* Treat Over Current and Over Load faults                                                            */
   /******************************************************************************************************/
   /* Decode Off Diag register                                                                           */
   /*    001 : Diag Done / Open Load detected                                                            */
   /*    010 : Short Circuit to VBatt (over current)                                                     */
   /*    011 : Short Circuit to Ground (over current)                                                    */
   /*    100 : Diag Done (no failure)                                                                    */
   /*    101 : Incorrect State to perform the Off diagnostic                                             */
   /*    110 : Diag not triggered (or Thz not expired)                                                   */
   /*    111 : Diag in progress                                                                          */
   /******************************************************************************************************/
   u16LocRegOffDiag     = pstrData->u16SpiMChipRegOffDiag;
   switch(u16LocRegOffDiag & L9960_bfOFF_DIAG_OFF_BITS)
   {
      case L9960_bfOFF_DIAG_OPEN_LOAD:
         pstrData->bOffDiagOverCurrentFault = FALSE;
         pstrData->bOffDiagOpenLoadFault = TRUE;
         bLocReturnvalue = TRUE;
         break;
         
      case L9960_bfOFF_DIAG_SHORT_VBATT:
      case L9960_bfOFF_DIAG_SHORT_GROUND:
         pstrData->bOffDiagOverCurrentFault = TRUE;
         pstrData->bOffDiagOpenLoadFault = FALSE;
         bLocReturnvalue = TRUE;
         break;

      case L9960_bfOFF_DIAG_NO_FAULT:
         pstrData->bOffDiagOverCurrentFault = FALSE;
         pstrData->bOffDiagOpenLoadFault = FALSE;
         bLocReturnvalue = TRUE;
         break;

      case L9960_bfOFF_DIAG_INCORRECT_STATE:
         /* Except the first call, it is an error, because the diag was triggered if this function is called */
         break;

      case L9960_bfOFF_DIAG_NOT_TRIGGED:
         /* Except the first call, it is an error, because the diag was triggered if this function is called */
         break;

      case L9960_bfOFF_DIAG_IN_PROGRESS:
         /* TODO: handle a timeout */
         break;

      default:
         break;
   }
   
   return(bLocReturnvalue);

}


#define L9960_STOP_SEC_CODE
#include "L9960_MemMap.h"

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/
