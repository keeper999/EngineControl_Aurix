/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : Framework                                               */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : IFXSCUWDT.h                                             */
/* !Description     : Framework component managing WDT                        */
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
 * %PID: P2017_BSW:0A111775.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef IFXSCUWDT_H
#define IFXSCUWDT_H

#include "Ifx_Types.h"
#include "IfxScu_cfg.h"
#include "IfxScu_reg.h"

/** \addtogroup IfxLld_Scu_Wdt
 * \{  */

/** \brief Configuration structure for Scu Watchdog.
 * IfxScuWdt_Config is a type describing configuration structure of CPU and
 * Safety WDT registers defined in IfxScuWdt.h file.
 */
typedef struct
{
    uint16 password;                        /**< \brief password for access to WDTxCON0 reg */
    uint16 reload;                          /**< \brief WDT reload value */
    IfxScu_WDTCON1_IR inputFrequency;       /**< \brief input frequency of the WDT */
    boolean disableWatchdog;                /**< \brief Disable Request Control Bit */
    boolean enableSmuRestriction;           /**< \brief Unlock Restriction Request Control Bit */
    boolean enableAutomaticPasswordChange;  /**< \brief Password Auto-sequence Request Bit */
    boolean enableTimerCheck;               /**< \brief Counter Check Request Bit */
    boolean enableTimerCheckTolerance;      /**< \brief Timer Check Tolerance Request */
    boolean clrInternalResetFlag;           /**< \brief Clear Internal Reset Flag */
} IfxScuWdt_Config;

/******************************************************************************/
/*                           Function                                         */
/******************************************************************************/
#define IFXSCU_START_SEC_CODE
#include "IFXSCU_MemMap.h"

/**
 * \brief SCUWDT API to disable CPU Watchdog functionality.
 *
 * This API will disable Watchdog functionality of CPU WDT Hardware module. The Watchdog timers will stop counting
 * after this API call.
 * User need to have the password stored locally in the caller function, (use IfxScuWdt_getCpuWatchdogPassword).
 *
 * \param password Existing (Application specific) password for the Watchdog module.
 */
IFX_EXTERN void IfxScuWdt_disableCpuWatchdog (uint16 password);

/**
 * \brief SCUWDT API to Clear ENDINIT bit provided by Safety WDT Hardware module.
 *
 * This API will disable ENDINIT functionality provided by Safety WDT Hardware module.
 * User need to use this API call before modifying any ENDINIT protected register. User must
 * always set the ENDINIT bit using other API IfxScuWdt_setCpuEndinit. The sequence clear and set
 * ENDINIT shall not be interrupted by another interrupt/call.
 * User need to have the password stored locally in the caller function, (use IfxScuWdt_getSafetyWatchdogPassword).
 *
 * \param password Existing (Application specific) password for the Watchdog module.
 */
IFX_EXTERN void IfxScuWdt_clearSafetyEndinit (uint16 password);

/**
 * \brief SCUWDT API to Set ENDINIT bit provided by Safety WDT Hardware module.
 *
 * This API will enable ENDINIT functionality provided by Safety WDT Hardware module.
 * User need to use this API call after modifying any ENDINIT protected register.
 * User need to have the password stored locally in the caller function, (use IfxScuWdt_getSafetyWatchdogPassword).
 *
 * \param password Existing (Application specific) password for the Watchdog module.
 */
IFX_EXTERN void IfxScuWdt_setSafetyEndinit (uint16 password);

/**
 * \brief SCUWDT API to disable Safety Watchdog functionality.
 *
 * This API will disable Watchdog functionality of Safety WDT Hardware module. The Watchdog timers will stop counting
 * after this API call.
 * User need to have the password stored locally in the caller function, (use IfxScuWdt_getSafetyWatchdogPassword).
 *
 * \param password Existing (Application specific) password for the Watchdog module.
 */
IFX_EXTERN void IfxScuWdt_disableSafetyWatchdog (uint16 password);

/**
 * \brief SCUWDT API to fetch current password of Safety Watchdog module.
 *
 * This API will fetch current Watchdog password for Safety WDT Hardware module. password is needed to be passed
 * with most of the WDT APIs. Normally this API can be used to store the password locally in the caller function
 * or store the password globally in a global variable at the application memory.
 *
 * \return password Existing (Application specific) password for the Watchdog module.
 */
IFX_EXTERN uint16 IfxScuWdt_getSafetyWatchdogPassword (void);

/**
 * \brief SCUWDT API to Clear ENDINIT bit provided by CPU WDT Hardware module.
 *
 * This API will disable ENDINIT functionality provided by CPU WDT Hardware module.
 * User need to use this API call before modifying any ENDINIT protected register. User must
 * always set the ENDINIT bit using other API IfxScuWdt_setCpuEndinit. The sequence clear and set
 * ENDINIT shall not be interrupted by another interrupt/call.
 * User need to have the password stored locally in the caller function, (use IfxScuWdt_getCpuWatchdogPassword).
 *
 * \param password Existing (Application specific) password for the Watchdog module.
 */
IFX_EXTERN void IfxScuWdt_clearCpuEndinit (uint16 password);

/**
 * \brief SCUWDT API to Set ENDINIT bit provided by CPU WDT Hardware module.
 *
 * This API will enable ENDINIT functionality provided by CPU WDT Hardware module.
 * User need to use this API call after modifying any ENDINIT protected register.
 * User need to have the password stored locally in the caller function, (use IfxScuWdt_getCpuWatchdogPassword).
 *
 * \param password Existing (Application specific) password for the Watchdog module.
 */
IFX_EXTERN void IfxScuWdt_setCpuEndinit (uint16 password);

/**
 * \brief SCUWDT Inline API to Clear ENDINIT bit provided by CPU WDT Hardware module.
 *
 * This Inline API will disable ENDINIT functionality provided by CPU WDT Hardware module.
 * This API is only meant to be used with startup routines where function call is not possible.
 * User need to use this API call before modifying any ENDINIT protected register. User must
 * always set the ENDINIT bit using other API IfxScuWdt_setCpuEndinit. The sequence clear and set
 * ENDINIT shall not be interrupted by another interrupt/call.
 * User need to have the password stored locally in the caller function, (use IfxScuWdt_getCpuWatchdogPassword).
 *
 * \param watchdog pointer to the watchdog
 * \param password Existing (Application specific) password for the Watchdog module.
 */
IFX_INLINE void IfxScuWdt_clearCpuEndinitInline (Ifx_SCU_WDTCPU * watchdog, uint16 password)
{
    /* Read Config_0 register */
    Ifx_SCU_WDTCPU_CON0 wdt_con0;
    wdt_con0.U = watchdog->CON0.U;

    if (wdt_con0.B.LCK)
    {
        /* see Table 1 (Pass.word Access Bit Pattern Requirements) */
        wdt_con0.B.ENDINIT = 1;
        wdt_con0.B.LCK = 0;
        wdt_con0.B.PW = password;

        /* Password ready. Store it to WDT_CON0 to unprotect the register */
        watchdog->CON0.U = wdt_con0.U;
    }

    /* Clear ENDINT and set LCK bit in Config_0 register */
    wdt_con0.B.ENDINIT = 0;
    wdt_con0.B.LCK = 1;
    watchdog->CON0.U = wdt_con0.U;

    /* read back ENDINIT and wait until it has been cleared */
    while (watchdog->CON0.B.ENDINIT == 1)
    {
    }
}

/**
 * \brief SCUWDT Inline API to Set ENDINIT bit provided by CPU WDT Hardware module.
 *
 * This API will enable ENDINIT functionality provided by CPU WDT Hardware module.
 * This API is only meant to be used with startup routines where function call is not possible.
 * User need to use this API call after modifying any ENDINIT protected register.
 * User need to have the password stored locally in the caller function, (use IfxScuWdt_getCpuWatchdogPassword).
 *
 * \param watchdog pointer to the watchdog
 * \param password Existing (Application specific) password for the Watchdog module.
 */
IFX_INLINE void IfxScuWdt_setCpuEndinitInline (Ifx_SCU_WDTCPU * watchdog, uint16 password)
{
    /* Read Config_0 register */
    Ifx_SCU_WDTCPU_CON0 wdt_con0;
    wdt_con0.U = watchdog->CON0.U;

    if (wdt_con0.B.LCK)
    {
        /* see Table 1 (Password Access Bit Pattern Requirements) */
        wdt_con0.B.ENDINIT = 1;
        wdt_con0.B.LCK = 0;
        wdt_con0.B.PW = password;

        /* Password ready. Store it to WDT_CON0 to unprotect the register */
        watchdog->CON0.U = wdt_con0.U;
    }

    /* Set ENDINT and set LCK bit in Config_0 register */
    wdt_con0.B.ENDINIT = 1;
    wdt_con0.B.LCK = 1;
    watchdog->CON0.U = wdt_con0.U;

    /* read back ENDINIT and wait until it has been set */
    while (watchdog->CON0.B.ENDINIT == 0)
    {
    }
    // FIXME: old version: removed this line after check: watchdog->CON0.U; /* read is required */
}

/**
 * \brief SCUWDT Inline API to fetch current password of CPU Watchdog module.
 *
 * This API will fetch current Watchdog password for CPU WDT Hardware module. password is needed to be passed
 * with most of the WDT APIs. Normally this API can be used to store the password locally in the caller function
 * or store the password globally in a global variable at the application memory.
 * This API is only meant to be used with startup routines where function call is not possible.
 *
 * \param watchdog pointer to the watchdog
 * \return password Existing (Application specific) password for the Watchdog module.
 */
IFX_INLINE uint16 IfxScuWdt_getCpuWatchdogPasswordInline (Ifx_SCU_WDTCPU * watchdog)
{
    uint16 password;

    /* Read Password from CON0 register
     * !!! NOTE: !!! when read bottom six bit of password are inverted so we have
     * to toggle them before returning password */
    password = watchdog->CON0.B.PW;
    password ^= 0x003F;

    return (password);
}

/**
 * \brief SCUWDT Inline API to Clear ENDINIT bit provided by Safety WDT Hardware module.
 *
 * This API will disable ENDINIT functionality provided by Safety WDT Hardware module.
 * This API is only meant to be used with startup routines where function call is not possible.
 * User need to use this API call before modifying any ENDINIT protected register. User must
 * always set the ENDINIT bit using other API IfxScuWdt_setCpuEndinit. The sequence clear and set
 * ENDINIT shall not be interrupted by another interrupt/call.
 * User need to have the password stored locally in the caller function, (use IfxScuWdt_getSafetyWatchdogPassword).
 *
 * \param password Existing (Application specific) password for the Watchdog module.
 */
IFX_INLINE void IfxScuWdt_clearSafetyEndinitInline (uint16 password)
{
    Ifx_SCU_WDTS *watchdog = &MODULE_SCU.WDTS;
    /* Read Config_0 register */
    Ifx_SCU_WDTS_CON0 wdt_con0;
    wdt_con0.U = watchdog->CON0.U;

    if (wdt_con0.B.LCK)
    {
        /* see Table 1 (Password Access Bit Pattern Requirements) */
        wdt_con0.B.ENDINIT = 1;
        wdt_con0.B.LCK = 0;
        wdt_con0.B.PW = password;

        /* Password ready. Store it to WDT_CON0 to unprotect the register */
        watchdog->CON0.U = wdt_con0.U;
    }

    /* Clear ENDINT and set LCK bit in Config_0 register */
    wdt_con0.B.ENDINIT = 0;
    wdt_con0.B.LCK = 1;
    watchdog->CON0.U = wdt_con0.U;

    /* read back ENDINIT and wait until it has been cleared */
    while (watchdog->CON0.B.ENDINIT == 1)
    {
    }
}

/**
 * \brief SCUWDT Inline API to Set ENDINIT bit provided by Safety WDT Hardware module.
 *
 * This API will enable ENDINIT functionality provided by Safety WDT Hardware module.
 * This API is only meant to be used with startup routines where function call is not possible.
 * User need to use this API call after modifying any ENDINIT protected register.
 * User need to have the password stored locally in the caller function, (use IfxScuWdt_getSafetyWatchdogPassword).
 *
 * \param password Existing (Application specific) password for the Watchdog module.
 */
IFX_INLINE void IfxScuWdt_setSafetyEndinitInline (uint16 password)
{
    Ifx_SCU_WDTS *watchdog = &MODULE_SCU.WDTS;

    /* Read Config_0 register */
    Ifx_SCU_WDTS_CON0 wdt_con0;
    wdt_con0.U = watchdog->CON0.U;

    if (wdt_con0.B.LCK)
    {
        /* see Table 1 (Password Access Bit Pattern Requirements) */
        wdt_con0.B.ENDINIT = 1;
        wdt_con0.B.LCK = 0;
        wdt_con0.B.PW = password;

        /* Password ready. Store it to WDT_CON0 to unprotect the register */
        watchdog->CON0.U = wdt_con0.U;
    }

    /* Set ENDINT and set LCK bit in Config_0 register */
    wdt_con0.B.ENDINIT = 1;
    wdt_con0.B.LCK = 1;
    watchdog->CON0.U = wdt_con0.U;

    /* read back ENDINIT and wait until it has been set */
    while (watchdog->CON0.B.ENDINIT == 0)
    {
    }
}

/**
 * \brief SCUWDT Inline API to fetch current password of Safety Watchdog module.
 *
 * This API will fetch current Watchdog password for Safety WDT Hardware module. password is needed to be passed
 * with most of the WDT APIs. Normally this API can be used to store the password locally in the caller function
 * or store the password globally in a global variable at the application memory.
 * This API is only meant to be used with startup routines where function call is not possible.
 *
 * \return password Existing (Application specific) password for the Watchdog module.
 */
IFX_INLINE uint16 IfxScuWdt_getSafetyWatchdogPasswordInline (void)
{
    uint16 password;
    Ifx_SCU_WDTS *watchdog = &MODULE_SCU.WDTS;

    /* Read Password from Safety WDT CON0 register
     * !!! NOTE: !!! when read bottom six bit of password are inverted so we have
     * to toggle them before returning password */
    password = watchdog->CON0.B.PW;
    password ^= 0x003F;

    return (password);
}

/**
 * \brief SCUWDT Inline API utility to Calculte new 14-bit LFSR.
 *
 * This API will Calculte new 14-bit LFSR (Linear Feedback Shift Register) with characteristic polynomial
 * x14+x13+x12+x2+1.
 *
 * \param password Password for which LFSR value to be calculated.
 * \return New LFSR.
 */
IFX_INLINE unsigned IfxScuWdt_calculateLfsr (uint16 password)
{
    uint16 res;
  __asm ("xor.t  %0,%1,#0,%1,#2   \n\
           xor.t  %0,%0,#0,%1,#12  \n\
           xor.t  %0,%1,#0,%1,#13  \n\
           xor.t  %0,%1,#0,%1,#14  \n\
           sh     %1,#-1 \n\
           ins.t  %0,%0,#1,%1,#14   \n": "=d" (res):"d" (password));
    return res;
}

/** \brief Macro to get LFSR bit field.
 *
 */
#define WDT_LFSR(pwd) (((pwd & 1)^(pwd>>2&1)^(pwd>>12&1)^(pwd>>13&1)^(pwd>>14&1))<<14 | (pwd>>1))

/** \}  */

/** \addtogroup IfxLld_Scu_Wdt_Endinit_Usage
 * \{  */

/** \page Ifx_Scu_Wdt_Endinit_Usage Using APIs for Endinit functionality
 * Tricore micorcontrollers provide protection for certain key registers via Endinit features.
 * pleaser refer micorcontrollers user manual for more details.
 *
 * To update such key registers the endinit functionality need to be disabled. For Aurix devices, these
 * functionality is linked with password which can be changed by user during runtime.
 *
 * Aurix controllers provide the Watchdog modules for each available CPUs and one for safety functionality.
 * Each CPU can access its own watchdog and corresponding endinit. Safety endinit is accessible by all
 * CPUs (if such access is not disabled explicitly).
 *
 * Following example show how to use endinit reset and set functions for CPU watchdog.
 * \code
 * //file: myInitFile1.c
 * //Example to use CPU endinit functions.
 *
 * #include "IfxScu_Wdt.h" //To get the APIs from IfxScu_Wdt driver
 *
 * void myInitFunction1(void)
 * {
 *   //Store the password for watchdog module of caller CPU
 *   uint16 password = IfxScuWdt_getCpuWatchdogPassword ();
 *
 *   //call API to reset endinit bit
 *   IfxScuWdt_clearCpuEndinit (password);
 *
 *   //user code to modify CPU endinit protected registers
 *   // :
 *
 *   //call API to set endinit bit
 *   IfxScuWdt_setCpuEndinit (password);
 * }
 * \endcode
 * \note The API access the watchdog of caller CPU. User need not care about the access restrictions.
 *
 * Following example show how to use endinit reset and set functions for Safety watchdog.
 * \code
 * //file: myInitFile2.c
 * //Example to use CPU endinit functions.
 *
 * #include "IfxScu_Wdt.h" //To get the APIs from IfxScu_Wdt driver
 *
 * void myInitFunction2(void)
 * {
 *   //Store the password for watchdog module of caller CPU
 *   uint16 password = IfxScuWdt_getSafetyWatchdogPassword ();
 *
 *   //call API to reset endinit bit
 *   IfxScuWdt_clearSafetyEndinit (password);
 *
 *   //user code to modify CPU endinit protected registers
 *   // :
 *
 *   //call API to set endinit bit
 *   IfxScuWdt_setSafetyEndinit (password);
 * }
 *
 * \endcode
 */
/** \}  */

#define IFXSCU_STOP_SEC_CODE
#include "IFXSCU_MemMap.h"

#endif /* IFXSCUWDT_H */

/*-------------------------------- end of file -------------------------------*/
