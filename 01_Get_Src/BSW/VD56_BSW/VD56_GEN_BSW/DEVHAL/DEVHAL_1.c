/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : DEVHAL                                                  */
/* !Description     : DEVHAL Component                                        */
/*                                                                            */
/* !File            : DEVHAL_1.c                                              */
/* !Description     : DEVHAL Component                                        */
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
 * %PID: %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"

#include "DEVHAL_Cfg.h"
#include "DEVHAL_Def.h"
#include "DEVHAL_I.h"
#include "IfxCbs_reg.h"
#include "IfxEmem_reg.h"
#include "IfxOvc_reg.h"
#include "IfxScuWdt.h"
#include "IfxScu_reg.h"

#if ( (DEVHAL_OVERLAY_RAM_END_ADDRESS - DEVHAL_OVERLAY_RAM_START_ADDRESS) \
    < (DEVHAL_u32CALIB_END_ADDRESS - DEVHAL_u32CALIB_START_ADDRESS))
   #error Calibration Size shall be smaller than emulation RAM.
#endif

#if (DEVHAL_u16NB_BLOCKS > 32)
   #error Maximal number of Calibration block shall be 32. Check configuration.
#endif

#define DEVHAL_START_SEC_CODE
#include "DEVHAL_MemMap.h"

/******************************************************************************/
/* !FuncName    : DEVHAL_vidUnlockEMEM                                        */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : K. Rungasamy                                                */
/******************************************************************************/
void DEVHAL_vidUnlockEMEM(void)
{
   volatile Ifx_EMEM_SBRCTR     *udtLocalSbrctrReg       = &EMEM_SBRCTR;
   volatile Ifx_EMEM_CLC        *udtLocalClockControlReg = &EMEM_CLC;
   volatile Ifx_EMEM_TILECONFIG *udtLocalTileReg         = &EMEM_TILECONFIG;
   uint32 u32LocalCurrentState;

   COMPILER_UNUSED_PARAMETER(u32LocalCurrentState);
   /* Clock Enable */
   udtLocalClockControlReg->U = 0u;

   /* Wait a Cycle */
   u32LocalCurrentState = (uint32)(udtLocalClockControlReg->U);

   /* Unlock Sequence */
   udtLocalSbrctrReg->U = 0x2u;
   udtLocalSbrctrReg->U = 0x6u;
   udtLocalSbrctrReg->U = 0xEu;

   /* Wait a Cycle */
   u32LocalCurrentState = (uint32)(udtLocalSbrctrReg->U);

   /* Assigne Full EMEM to Calibration Memory */
   udtLocalTileReg->U = 0u;
}

/******************************************************************************/
/* !FuncName    : DEVHAL_vidCopyCalibERAM                                     */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : K. Rungasamy                                                */
/******************************************************************************/
void DEVHAL_vidCopyCalibToERAM(void)
{
   uint32 *pu32LocalRamPtr;
   uint32 *pu32LocalCalibPtr;

   pu32LocalRamPtr = (uint32*)DEVHAL_OVERLAY_RAM_START_ADDRESS;

   for (pu32LocalCalibPtr = (uint32*)DEVHAL_u32CALIB_START_ADDRESS;
        pu32LocalCalibPtr < (uint32*)DEVHAL_u32CALIB_END_ADDRESS;
        pu32LocalCalibPtr ++)
   {
      *pu32LocalRamPtr = *pu32LocalCalibPtr;
      pu32LocalRamPtr++;
   }
}

/******************************************************************************/
/* !FuncName    : DEVHAL_vidInitEmuCalib                                      */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : K. Rungasamy                                                */
/******************************************************************************/
void DEVHAL_vidInitEmuCalib(void)
{
   uint32 u32LocalEmuSizeOfCalib;
   uint32 u32LocalOffsetAddress;
   uint32 u32LocalOffsetAddressInOVMMem;
   uint32 u32LocalOselRegVal;
   uint16 u32LocalRedirectionMemory;
   uint16 u16LocalBlocIndex;
   uint16 u16LocalPassword;
   volatile Ifx_OVC_OSEL      *pudtLocalOselReg;
   volatile Ifx_SCU_OVCCON    *pudtLocalOvcconReg;
   volatile Ifx_SCU_OVCENABLE *pudtLocalOvcenableReg;

   u32LocalOselRegVal = 0u;

   /* !Comment: Overlay Registers are Safety Endinit Protected                */
   u16LocalPassword = IfxScuWdt_getSafetyWatchdogPassword();
   IfxScuWdt_clearSafetyEndinit(u16LocalPassword);

   /* !Comment: Disable Overlay on all Cores                                  */
   pudtLocalOvcenableReg          = &SCU_OVCENABLE;
   pudtLocalOvcenableReg->B.OVEN0 = 0x0u;
   pudtLocalOvcenableReg->B.OVEN1 = 0x0u;
   pudtLocalOvcenableReg->B.OVEN2 = 0x0u;

   /* !Comment: Initlialization of Emulated Calibration Size                  */
   u32LocalEmuSizeOfCalib =
      DEVHAL_u32GET_BLOCK_SIZE_MASK(DEVHAL_snDESIRED_BLOCK_SIZE);

   /* !Comment: Selects the Overlay RAM                                       */
   u32LocalRedirectionMemory =
      DEVHAL_u32GET_REDIRECT_MEMORY(DEVHAL_snREDIRECTION_AREA);

   /* !Comment: Offset Address of Calibration Area Start in Flash             */
   /*           Offset = Bit27..Bit5                                          */
   u32LocalOffsetAddress = (DEVHAL_u32CALIB_START_ADDRESS >> 5u) & 0x007FFFFFu;

   /* !Comment: Offset Address of Calibration Area Start in Overlay RAM       */
   /*           Offset = Bit21..Bit5                                          */
   u32LocalOffsetAddressInOVMMem =
      (DEVHAL_OVERLAY_RAM_START_ADDRESS >> 5u) & 0x0001FFFFu;

   /* !Comment: Initialization of the Overlay Blocks used for All Cores       */
   for (u16LocalBlocIndex = 0u;
        u16LocalBlocIndex < DEVHAL_u16NB_BLOCKS;
        u16LocalBlocIndex ++)
   {
      /* !Comment: Overlay Target Register: Init of Start Address */
      __dsync();
      OVMotarXC0[u16LocalBlocIndex]->B.TBASE = u32LocalOffsetAddress;
      __dsync();
      OVMotarXC1[u16LocalBlocIndex]->B.TBASE = u32LocalOffsetAddress;
      __dsync();
      OVMotarXC2[u16LocalBlocIndex]->B.TBASE = u32LocalOffsetAddress;

      /* !Comment: Offset Address of Next Calibration Block in Flash          */
      /*           Offset = Bit27..Bit5                                       */
      u32LocalOffsetAddress = (u32LocalOffsetAddress
         + (DEVHAL_u32GET_BLOCK_SIZE(DEVHAL_snDESIRED_BLOCK_SIZE) >> 5u))
         & 0x007FFFFFu;

      /* !Comment: Overlay Mask Address */
      __dsync();
      OVMomaskXC0[u16LocalBlocIndex]->B.OMASK = u32LocalEmuSizeOfCalib;
      __dsync();
      OVMomaskXC1[u16LocalBlocIndex]->B.OMASK = u32LocalEmuSizeOfCalib;
      __dsync();
      OVMomaskXC2[u16LocalBlocIndex]->B.OMASK = u32LocalEmuSizeOfCalib;

      /* !Comment: Redirected Address Base Register */
      __dsync();
      OVMrabrXC0[u16LocalBlocIndex]->B.OBASE = u32LocalOffsetAddressInOVMMem;
      __dsync();
      OVMrabrXC1[u16LocalBlocIndex]->B.OBASE = u32LocalOffsetAddressInOVMMem;
      __dsync();
      OVMrabrXC2[u16LocalBlocIndex]->B.OBASE = u32LocalOffsetAddressInOVMMem;

      /* !Comment: Offset Address of Next Calibration Block in Overlay RAM    */
      /*           Offset = Bit21..Bit5                                       */
      u32LocalOffsetAddressInOVMMem = (u32LocalOffsetAddressInOVMMem
         + (DEVHAL_u32GET_BLOCK_SIZE(DEVHAL_snDESIRED_BLOCK_SIZE) >> 5u))
         & 0x0001FFFFu;

      /* !Comment: Initilialization of Redirection Memory */
      __dsync();
      OVMrabrXC0[u16LocalBlocIndex]->B.OMEM = u32LocalRedirectionMemory;
      __dsync();
      OVMrabrXC1[u16LocalBlocIndex]->B.OMEM = u32LocalRedirectionMemory;
      __dsync();
      OVMrabrXC2[u16LocalBlocIndex]->B.OMEM = u32LocalRedirectionMemory;

      /* !Comment: Enable of Overlay Block */
      __dsync();
      OVMrabrXC0[u16LocalBlocIndex]->B.OVEN = 0x1u;
      __dsync();
      OVMrabrXC1[u16LocalBlocIndex]->B.OVEN = 0x1u;
      __dsync();
      OVMrabrXC2[u16LocalBlocIndex]->B.OVEN = 0x1u;

      /* !Comment: Action of Block */
      u32LocalOselRegVal |= (1u << u16LocalBlocIndex);
   }

   /* !Comment: Activation of Overlay Blocks in All Cores                     */
   pudtLocalOselReg    = &OVC0_OSEL;
   pudtLocalOselReg->U = u32LocalOselRegVal;
   pudtLocalOselReg    = &OVC1_OSEL;
   pudtLocalOselReg->U = u32LocalOselRegVal;
   pudtLocalOselReg    = &OVC2_OSEL;
   pudtLocalOselReg->U = u32LocalOselRegVal;

   /* !Comment: Overlay Global Register                                       */
   pudtLocalOvcconReg  = &SCU_OVCCON;

   /* !Comment: Core Selection                                                */
   pudtLocalOvcconReg->B.CSEL0    = 0x1u;
   pudtLocalOvcconReg->B.CSEL1    = 0x1u;
   pudtLocalOvcconReg->B.CSEL2    = 0x1u;

   /* !Comment: Overlay Start                                                 */
   pudtLocalOvcconReg->B.OVSTRT   = 0x1u;

   pudtLocalOvcconReg->B.POVCONF  = 0x1u;
   pudtLocalOvcconReg->B.OVCONF   = 0x1u;
   pudtLocalOvcconReg->B.POVCONF  = 0x0u;

   /* !Comment: Enable Overlay on All Cores                                   */
   pudtLocalOvcenableReg->B.OVEN0 = 0x1u;
   pudtLocalOvcenableReg->B.OVEN1 = 0x1u;
   pudtLocalOvcenableReg->B.OVEN2 = 0x1u;

   IfxScuWdt_setSafetyEndinit(u16LocalPassword);
}

#define DEVHAL_STOP_SEC_CODE
#include "DEVHAL_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
