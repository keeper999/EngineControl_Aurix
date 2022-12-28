/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : Framework                                               */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : IFXSCUCCU.c                                             */
/* !Description     : Framework component managing CCU                        */
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
 * %PID: P2017_BSW:0A111788.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

/******************************************************************************/
#include "IfxScuCcu.h"
#include "IfxScuWdt.h"
#include "IfxStm_reg.h"

/******************************************************************************/

/** \brief Timeout count for the oscillator stability check wait loop.
 *
 */
#define IFXSCUCCU_OSC_STABLECHK_TIME      640U    /*Oscillator stability check timeout count */

/******************************************************************************/
/*                          Default Configuration                             */
/******************************************************************************/

#define IFXSCU_START_SEC_CONST_UNSPECIFIED
#include "IFXSCU_MemMap.h"

static const IfxScu_PllStepsConfig pllConfigSteps[] = IFXSCU_CFG_PLL_STEPS;

const IfxScuCcu_Config clockConfig = {
    sizeof (pllConfigSteps) / sizeof (IfxScu_PllStepsConfig),
    (IfxScu_PllStepsConfig *) pllConfigSteps,
    IFXSCU_CFG_PLL_INITIAL_STEP,
    IFXSCU_CFG_CLK_DISTRIBUTION
};

#define IFXSCU_STOP_SEC_CONST_UNSPECIFIED
#include "IFXSCU_MemMap.h"

/******************************************************************************/
/*                           Function                                         */
/******************************************************************************/
#define IFXSCU_START_SEC_CODE
#include "IFXSCU_MemMap.h"

/** \brief get source frequency fSOURCE.
 *
 */
float32 IfxScuCcu_getSourceFrequency (void)
{
    float32 sourcefreq;
    switch (MODULE_SCU.CCUCON0.B.CLKSEL)
    {
    case IfxScu_CCUCON0_CLKSEL_fBack:
        sourcefreq = IfxScuCcu_getEvrFrequency ();
        break;
    case IfxScu_CCUCON0_CLKSEL_fPll:
        sourcefreq = IfxScuCcu_getPllFrequency ();
        break;
    default:
        sourcefreq = 0;
        break;
    }
    return sourcefreq;
}

/** \brief Return the system timer frequency.
 *
 */
float32 IfxScuCcu_getStmFrequency (void)
{
    float32 freq;
    uint32 stmdiv = MODULE_SCU.CCUCON1.B.STMDIV;
    freq = IfxScuCcu_getFmaxFrequency () / stmdiv;

    return freq;
}

/** \brief Return the Fmax frequency
 *
 */
float32 IfxScuCcu_getFmaxFrequency (void)   /*TODO this name to be changed to IfxScuCcu_getMaxFrequency */
{
    float32 maxFrequency;
    
    maxFrequency = IfxScuCcu_getSourceFrequency ();
    
    switch (MODULE_SCU.CCUCON0.B.LPDIV)
    {
    case 0:                    /*Not in low power mode */
        if (MODULE_SCU.CCUCON5.B.MAXDIV == 0)
        {
            /*maxFrequency = IfxScuCcu_getSourceFrequency ();*/
        }
        else
            maxFrequency = maxFrequency/*IfxScuCcu_getSourceFrequency ()*/ / MODULE_SCU.CCUCON5.B.MAXDIV;
        break;
    case 1:
        maxFrequency = maxFrequency/*IfxScuCcu_getSourceFrequency ()*/ / 15;
        break;
    case 2:
        maxFrequency = maxFrequency/*IfxScuCcu_getSourceFrequency ()*/ / 30;
        break;
    case 3:
        maxFrequency = maxFrequency/*IfxScuCcu_getSourceFrequency ()*/ / 60;
        break;
    case 4:
        maxFrequency = maxFrequency/*IfxScuCcu_getSourceFrequency ()*/ / 120;
        break;
    default:
        maxFrequency = 0.0;
        break;
    }
    return maxFrequency;
}

/** \brief Return the EVR frequency
 *
 */
float32 IfxScuCcu_getEvrFrequency (void)
{
    return IFXSCU_EVR_OSC_FREQUENCY;
}

/** \brief Return the system PLL frequency.
 *
 */
float32 IfxScuCcu_getPllFrequency (void)
{
    Ifx_SCU *scu = &MODULE_SCU;
    float32 oscFreq;
    float32 freq;

    oscFreq = IfxScuCcu_getOscFrequency ();

    if (scu->PLLSTAT.B.VCOBYST == 1)
    {
        /* Prescaler mode */
        freq = oscFreq / (scu->PLLCON1.B.K1DIV + 1);
    }
    else if (scu->PLLSTAT.B.FINDIS == 1)
    {
        /* Free running mode */
        freq = IFXSCU_VCO_BASE_FREQUENCY / (scu->PLLCON1.B.K2DIV + 1);
    }
    else
    {
        /* Normal mode */
        freq = (oscFreq * (scu->PLLCON0.B.NDIV + 1)) / ((scu->PLLCON1.B.K2DIV + 1) * (scu->PLLCON0.B.PDIV + 1));
    }
    return freq;
}

/** \brief Return the fosc frequency.
 *
 */
float32 IfxScuCcu_getOscFrequency (void)
{
    if (MODULE_SCU.CCUCON1.B.INSEL == IfxScu_CCUCON1_INSEL_fOsc1)
    {
        return IFXSCU_EVR_OSC_FREQUENCY;
    }
    else if (MODULE_SCU.CCUCON1.B.INSEL == IfxScu_CCUCON1_INSEL_fOsc0)
    {
        return IFX_CFG_SCU_XTAL_FREQUENCY;
    }
    else
    {
        /* Reserved values, this */
        return 0.0;
    }
}

#define IFXSCU_STOP_SEC_CODE
#include "IFXSCU_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
