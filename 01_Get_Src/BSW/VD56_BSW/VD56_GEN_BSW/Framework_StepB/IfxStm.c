/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : Framework                                               */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : IFXSTM.c                                                */
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
 * %PID: P2017_BSW:0A111671.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "IfxScuCcu.h"
#include "IfxSrc.h"
#include "IfxStm.h"

#define IFXSTM_START_SEC_CODE
#include "IFXSTM_MemMap.h"

/******************************************************************************/
/** \brief Initialise stm compare register.
 *
 * \param stm System timer module
 * \param cfg pointer to configuration structure
 */
boolean IfxStm_initCompare (Ifx_STM * stm, IfxStm_CompareConfig * cfg)
{
/*    sint32 index;                                                                // dbg */
    boolean result;
    Ifx_STM_CMCON comcon = stm->CMCON;
    Ifx_STM_ICR icr = stm->ICR;
    Ifx_STM_ISCR iscr = stm->ISCR;

    (void)IfxStm_getIndex (stm);
/*    index = IfxStm_getIndex (stm);                                               // dbg */
/*    if ((cfg->triggerInterruptEnabled > 0) && (index >= 0))                      // dbg */
/*    { // dbg */                       /* configure interrupt */
/*        volatile Ifx_SRC_SRCR *srcr;                                             // dbg */
/*        if (cfg->comparatorInterrupt == IfxStm_ComparatorInterrupt_Ir0)          // dbg */
/*        {                                                                        // dbg */
/*            srcr = &(MODULE_SRC.STM.STM[index].SR0);                             // dbg */
/*        }                                                                        // dbg */
/*        else                                                                     // dbg */
/*        {                                                                        // dbg */
/*            srcr = &(MODULE_SRC.STM.STM[index].SR1);                             // dbg */
/*        }                                                                        // dbg */
/*        IfxSrc_init (srcr, cfg->servProvider, cfg->triggerInterruptEnabled);     // dbg */
/*        IfxSrc_enable (srcr);                                                    // dbg */
/*    }                                                                            // dbg */
/* dbg because src configured in intbsl */

    /*Configure the comparator ticks */
    stm->CMP[cfg->comparator].U = IfxStm_getOffsetTimer (stm, cfg->compareOffset) + cfg->ticks;

    if (cfg->comparator == 0)
    {
        comcon.B.MSIZE0 = cfg->compareSize;
        comcon.B.MSTART0 = cfg->compareOffset;
        icr.B.CMP0OS = cfg->comparatorInterrupt;
        icr.B.CMP0EN = cfg->triggerInterruptEnabled ? 1 : 0;
        iscr.B.CMP0IRR = 1; /* dbg */
        result = TRUE;
    }
    else if (cfg->comparator == 1)
    {
        comcon.B.MSIZE1 = cfg->compareSize;
        comcon.B.MSTART1 = cfg->compareOffset;
        icr.B.CMP1OS = cfg->comparatorInterrupt;
        icr.B.CMP1EN = cfg->triggerInterruptEnabled ? 1 : 0;
        iscr.B.CMP1IRR = 1; /* dbg */
        result = TRUE;
    }
    else
    {
        /*Invalid value */
        result = FALSE;
    }
    stm->CMCON = comcon;
    stm->ISCR = iscr;
    stm->ICR = icr;

    return result;
}

/** \brief Initialise compare configuration with default values.
 *
 * \param cfg pointer to configuration structure
 */
void IfxStm_initCompareConfig (IfxStm_CompareConfig * cfg)
{
    cfg->comparator = IfxStm_Comparator_0;
    cfg->compareOffset = IfxStm_ComparatorOffset_0;
    cfg->compareSize = IfxStm_ComparatorSize_32Bits;
    cfg->triggerInterruptEnabled = TRUE; //dbg
    cfg->comparatorInterrupt = IfxStm_ComparatorInterrupt_Ir0;  /*User must select the interrupt output */
    cfg->ticks = 0xFFFFFFFF;
    /* TODO add interrupt configuration */
}

/** \brief API to get the resource index of the STM specified.
 *
 * \param stm System timer module
 *
 * \return Returns system timer resource index.
 */
IfxStm_ResourceStm IfxStm_getIndex (Ifx_STM * stm)
{
   uint32 index;
   IfxStm_ResourceStm result;

   result = IfxStm_ResourceStm_none;

    for (index = 0; index < IFXSTM_COUNT; index++)
    {
        if (IfxStm_cfg_indexMap[index].module == stm)
        {
            result = IfxStm_cfg_indexMap[index].index;
            break;
        }
    }
    return result;
}

/** \brief Return the system timer frequency
 *
 * \return Return the system timer frequency in Hz
 */
float32 IfxStm_getFrequency (Ifx_STM * stm)
{
    float32 result;
    COMPILER_UNUSED_PARAMETER(stm);

    result = IfxScuCcu_getStmFrequency ();
    return result;
}

#define IFXSTM_STOP_SEC_CODE
#include "IFXSTM_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
