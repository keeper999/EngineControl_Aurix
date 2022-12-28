/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : Framework                                               */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : IFXSTM.h                                                */
/* !Description     : Framework component managing STM                        */
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
 * %PID: P2017_BSW:0A111691.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef IFXSTM_TIMER_H
#define IFXSTM_TIMER_H
/******************************************************************************/
#include "IfxStm_cfg.h"
#include "IfxSrc.h"
/******************************************************************************/
/*                           Type definitions                              */
/******************************************************************************/

/** \addtogroup IfxLld_Stm
 * \{ */
/** \name Comparator Configuration Structure
 * \{ */
/** \brief Comparator Configuration Structure
 */
typedef struct
{
    Priority triggerInterruptEnabled;
    IfxStm_ComparatorInterrupt comparatorInterrupt; /*Intrrupt request output */
    IfxStm_Comparator comparator;   /*Comparator Selection */
    IfxStm_ComparatorOffset compareOffset;  /*Offset for compare operation with STM timer */
    IfxStm_ComparatorSize compareSize;  /*Data size for compare operation in bits */
    uint32 ticks;               /*count for next comparison from current timer count */
    IfxSrc_Tos servProvider;    /*Type of service */
} IfxStm_CompareConfig;

/** \} */
/******************************************************************************/
/*                           Function prototypes                              */
/******************************************************************************/
#define IFXSTM_START_SEC_CODE
#include "IFXSTM_MemMap.h"

/** \name Timer functions
 * \{ */
IFX_EXTERN float32 IfxStm_getFrequency (Ifx_STM * stm);
IFX_INLINE uint32 IfxStm_getLower (Ifx_STM * stm);
IFX_INLINE uint32 IfxStm_getOffsetTimer (Ifx_STM * stm, uint8 offset);
IFX_INLINE uint32 IfxStm_getOffset4Timer (Ifx_STM * stm);
IFX_INLINE uint32 IfxStm_getOffset8Timer (Ifx_STM * stm);
IFX_INLINE uint32 IfxStm_getOffset12Timer (Ifx_STM * stm);
IFX_INLINE uint32 IfxStm_getOffset16Timer (Ifx_STM * stm);
IFX_INLINE uint32 IfxStm_getOffset20Timer (Ifx_STM * stm);
IFX_INLINE uint32 IfxStm_getOffset32Timer (Ifx_STM * stm);
/** \} */

/** \name Compare functions
 * \{ */
IFX_EXTERN void IfxStm_initCompareConfig (IfxStm_CompareConfig * cfg);
IFX_EXTERN boolean IfxStm_initCompare (Ifx_STM * stm, IfxStm_CompareConfig * cfg);
IFX_INLINE void IfxStm_updateCompare (Ifx_STM * stm, IfxStm_Comparator comparator, uint32 ticks);
IFX_INLINE uint32 IfxStm_getCompare (Ifx_STM * stm, IfxStm_Comparator comparator);
/** \} */

/** \name Other functions
 * \{ */
IFX_EXTERN IfxStm_ResourceStm IfxStm_getIndex (Ifx_STM * stm);
IFX_INLINE void IfxStm_enableOcdsSuspend (Ifx_STM * stm);
/** \} */

/** \} */

/******************************************************************************/
/*                           Functions                                         */
/******************************************************************************/
/** \brief enable suspend by debugger.
 *
 * \param stm System timer module
 */
IFX_INLINE void IfxStm_enableOcdsSuspend (Ifx_STM * stm)
{
    Ifx_STM_OCS ocs = stm->OCS;
    ocs.B.SUS_P = 1;
    ocs.B.SUS = 2;
    stm->OCS = ocs;
    stm->OCS.B.SUS_P = 0;
}

/** \brief Return system timer value.
 *
 * \param stm System timer module
 *
 * \return Returns system timer value.
 */
IFX_INLINE uint64 IfxStm_get (Ifx_STM * stm)
{
    uint64 result;
    result = stm->TIM0.U;
    result |= ((uint64) stm->CAP.U) << 32;
    return result;
}

/** \brief Return the lower system timer value.
 *
 * \param stm System timer module
 * \return Returns the lower system timer value.
 */
IFX_INLINE uint32 IfxStm_getLower (Ifx_STM * stm)
{
    return stm->TIM0.U;
}

/** \brief Update the compare register value.
 *
 * \param stm System timer module
 * \param comparator selection comparator
 */
IFX_INLINE void IfxStm_updateCompare (Ifx_STM * stm, IfxStm_Comparator comparator, uint32 ticks)
{
    stm->CMP[comparator].B.CMPVAL = ticks;
}

/** \brief Update the compare register value increased with given ticks.
 *
 * \param stm System timer module
 * \param comparator selection comparator
 */
IFX_INLINE void IfxStm_increaseCompare (Ifx_STM * stm, IfxStm_Comparator comparator, uint32 ticks)
{
    stm->CMP[comparator].B.CMPVAL = stm->CMP[comparator].B.CMPVAL + ticks;
}

/** \brief Update the compare register value.
 *
 * \param stm System timer module
 * \param comparator selection comparator
 * \return Returns the compare value.
 */
IFX_INLINE uint32 IfxStm_getCompare (Ifx_STM * stm, IfxStm_Comparator comparator)
{
    return stm->CMP[comparator].B.CMPVAL;
}

/** \brief Return the timer value shifted right by offset.
 *
 * \param stm System timer module
 * \param offset offset value
 * \return Returns the lower system timer value shifted by offset
 */
IFX_INLINE uint32 IfxStm_getOffsetTimer (Ifx_STM * stm, uint8 offset)
{
    uint64 now;
    now = IfxStm_get (stm);
    return (uint32) (now >> offset);
}

IFX_INLINE uint32 IfxStm_getOffset4Timer (Ifx_STM * stm)
{
    return stm->TIM1.U;
}

IFX_INLINE uint32 IfxStm_getOffset8Timer (Ifx_STM * stm)
{
    return stm->TIM2.U;
}

IFX_INLINE uint32 IfxStm_getOffset12Timer (Ifx_STM * stm)
{
    return stm->TIM3.U;
}

IFX_INLINE uint32 IfxStm_getOffset16Timer (Ifx_STM * stm)
{
    return stm->TIM4.U;
}

IFX_INLINE uint32 IfxStm_getOffset20Timer (Ifx_STM * stm)
{
    return stm->TIM5.U;
}

IFX_INLINE uint32 IfxStm_getOffset32Timer (Ifx_STM * stm)
{
    return stm->TIM6.U;
}

/** Wait for requested time
 *
 * The macro waits in while loop for the specified time in system timer ticks
 * \param stm System timer module
 * \param ticks Wait time in system timer ticks
 * \return None
 *
 */
IFX_INLINE void IfxStm_waitTicks (Ifx_STM * stm, uint32 ticks)
{
    uint32 beginTime;
    beginTime = IfxStm_getLower (stm);
    /*below code will work because of unsigned 32 bit calculation even at timer wrapping condition
     * As an example if beginTime = 0xFFFFFFFE and current time = 2 (after overflow), unsigned calculation
     * 2 - 0xFFFFFFFE will be 4*/
    while ((IfxStm_getLower (stm) - beginTime) < ticks)
    {
    }
}

#define IFXSTM_STOP_SEC_CODE
#include "IFXSTM_MemMap.h"

#endif /* IFXSTM_TIMER_H */

/*-------------------------------- end of file -------------------------------*/
