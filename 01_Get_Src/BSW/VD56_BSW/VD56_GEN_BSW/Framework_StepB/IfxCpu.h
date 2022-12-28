/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : Framework                                               */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : IFXCPU.h                                                */
/* !Description     : Framework component to manage CPU                       */
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
 * %PID: P2017_BSW:0A111769.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef IFX_CPU_H
#define IFX_CPU_H
/******************************************************************************/
#include "IfxCpu_cfg.h"
#include "IfxSrc_reg.h"
#include "IfxScu_reg.h"
#include "IfxScuWdt.h"

/******************************************************************************/
/*                           Enum                                             */
/******************************************************************************/
/** \addtogroup IfxLld_Cpu_Core
 * \{  */

/** \brief Enumeration for the Cpu mode.
 *
 */
typedef enum
{
    IfxCpu_CoreMode_halt,
    IfxCpu_CoreMode_run,
    IfxCpu_CoreMode_idle,
    IfxCpu_CoreMode_sleep,
    IfxCpu_CoreMode_stby,
    IfxCpu_CoreMode_unknown
} IfxCpu_CoreMode;

/** Performance conunter modes
 *
 */
typedef enum
{
    IfxCpu_CounterMode_normal = 0,  /**< \brief Normal counter mode:the counter increments on their respective triggers */
    IfxCpu_CounterMode_task = 1     /**< \brief Normal counter mode:additional gating control from the debug unit which allows the data gathered in the performance counters to be filtered by some specific criteria */
}IfxCpu_CounterMode;

/** Performance counter result
 *
 */
typedef struct
{
    struct{
        uint32 counter;  /**< \brief Counter value */
        boolean overlfow;  /**< \brief Sticky overflow */
    }instruction;           /**< \brief Instruction counter */
    struct{
        uint32 counter;  /**< \brief Counter value */
        boolean overlfow;  /**< \brief Sticky overflow */
    }clock;                 /**< \brief CPU clock counter */
    struct{
        uint32 counter;  /**< \brief Counter value */
        boolean overlfow;  /**< \brief Sticky overflow */
    }counter1;              /**< \brief Multi counter 1 */
    struct{
        uint32 counter;  /**< \brief Counter value */
        boolean overlfow;  /**< \brief Sticky overflow */
    }counter2;              /**< \brief Multi counter 2 */
    struct{
        uint32 counter;  /**< \brief Counter value */
        boolean overlfow;  /**< \brief Sticky overflow */
    }counter3;              /**< \brief Multi counter 3*/
} IfxCpu_Perf;

/** \}  */

/******************************************************************************/
/*                       Function prototypes                                  */
/******************************************************************************/
#define IFXCPU_START_SEC_CODE
#include "IFXCPU_MemMap.h"

/** \brief API to get resource index of the CPU of the caller.
 *
 * \return Resource index of the CPU.
 */
IFX_INLINE uint32 IfxCpu_getCoreId (void);

/******************************************************************************/
/*                         Inline Functions                                   */
/******************************************************************************/

/** \brief API to get resource index of the CPU of the caller.
 *
 */
IFX_INLINE uint32 IfxCpu_getCoreId (void)
{
    Ifx_CPU_CORE_ID reg;
    reg.U = __mfcr (CPU_CORE_ID);
    return reg.B.CORE_ID;
}

/** \brief API to enable or bypass the data cache for the CPU which calls this API.
 *
 */
IFX_INLINE void IfxCpu_setDataCache (boolean enable)
{
    uint32 coreId = IfxCpu_getCoreId ();
    uint16 wdtPassword = IfxScuWdt_getCpuWatchdogPasswordInline (&MODULE_SCU.WDTCPU[coreId]);
    /*PCACHE enable steps */
    {                           /* Step 1: Set PCBYP to 0 if cache is enabled */
        IfxScuWdt_clearCpuEndinitInline (&MODULE_SCU.WDTCPU[coreId], wdtPassword);
        Ifx_CPU_DCON0 dcon0;
        dcon0.U = 0;
        dcon0.B.DCBYP = enable ? 0 : 1; /*depending on the enable bypas bit is reset/set */
        __mtcr (CPU_DCON0, dcon0.U);
        IfxScuWdt_clearCpuEndinitInline (&MODULE_SCU.WDTCPU[coreId], wdtPassword);
    }
    /* Step 2: Call Isync */
    __isync ();
}

/** \brief API to enable or bypass the program cache for the CPU which calls this API.
 *
 */
IFX_INLINE void IfxCpu_setProgramCache (boolean enable)
{
    uint32 coreId = IfxCpu_getCoreId ();
    uint16 wdtPassword = IfxScuWdt_getCpuWatchdogPasswordInline (&MODULE_SCU.WDTCPU[coreId]);
    /*PCACHE enable steps */
    {                           /* Step 1: Set PCBYP to 0 if cache is enabled */
        IfxScuWdt_clearCpuEndinitInline (&MODULE_SCU.WDTCPU[coreId], wdtPassword);
        Ifx_CPU_PCON0 pcon0;
        pcon0.U = 0;
        pcon0.B.PCBYP = enable ? 0 : 1; /*depending on the enable bypass bit is reset/set */
        __mtcr (CPU_PCON0, pcon0.U);
        IfxScuWdt_clearCpuEndinitInline (&MODULE_SCU.WDTCPU[coreId], wdtPassword);
    }
    /* Step 2: Call Isync */
    __isync ();
    if (enable)
    {                           /* Step 3: Initiate invalidation of current cache contents if any */
        Ifx_CPU_PCON1 pcon1;
        pcon1.U = 0;
        pcon1.B.PCINV = 1;
        __mtcr (CPU_PCON1, pcon1.U);
    }
}

#define IFXCPU_STOP_SEC_CODE
#include "IFXCPU_MemMap.h"

#endif /* IFX_CPU_H */

/*-------------------------------- end of file -------------------------------*/
