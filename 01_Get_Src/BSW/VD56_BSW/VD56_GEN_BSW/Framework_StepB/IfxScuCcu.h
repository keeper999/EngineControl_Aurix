/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : Framework                                               */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : IFXSCUCCU.h                                             */
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
 * %PID: P2017_BSW:0A111708.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef IFXSCUCCU_H
#define IFXSCUCCU_H
/******************************************************************************/
#include "Ifx_Types.h"
#include "IfxScu_cfg.h"
#include "IfxCpu_cfg.h"

/** \addtogroup IfxLld_Scu_Ccu
 * \{  */

/** \brief Function pointer type for the hooks.
 *
 */
typedef void (*IfxScu_PllStepsFunctionHook) (void);

/** \brief Configuration structure type for the Pll Steps for current jump control.
 *
 */
typedef struct
{
    uint8 k2Step;                               /**< K2 divider value for this step*/
    float32 waitTime;                           /**< Wait time for for this step*/
    IfxScu_PllStepsFunctionHook hookFunction;   /**< Hook Function called at the end of this step*/
} IfxScu_PllStepsConfig;

/** \brief Configuration structure type for the Pll initial step.
 * This structure must be used to configure the P, N and K2 dividers for initial step.
 */
typedef struct
{
    uint8 pDivider;                             /**< P divider value for basic (initial) step*/
    uint8 nDivider;                             /**< N divider value for basic (initial) step*/
    uint8 k2Initial;                            /**< K2 divider value for basic (initial) step*/
    float32 waitTime;                           /**< Wait time for for basic (initial) step*/
} IfxScu_InitialStepConfig;

/** \brief Configuration structure type for CCUCON values.
 *
 */
typedef struct
{
    uint32 value;                               /**< CCUCON Register value to be updated*/
    uint32 mask;                                /**< CCUCON Mask to select the bit field to be updated*/
} IfxScuCcu_CcuconRegConfig;

/** \brief Configuration structure type for all the CCUCON registers.
 *
 */
typedef struct
{
    IfxScuCcu_CcuconRegConfig ccucon0;          /**< CCUCON0 Register configuration*/
    IfxScuCcu_CcuconRegConfig ccucon1;          /**< CCUCON1 Register configuration*/
    IfxScuCcu_CcuconRegConfig ccucon2;          /**< CCUCON2 Register configuration*/
    IfxScuCcu_CcuconRegConfig ccucon5;          /**< CCUCON5 Register configuration*/
    IfxScuCcu_CcuconRegConfig ccucon6;          /**< CCUCON6 Register configuration*/
    IfxScuCcu_CcuconRegConfig ccucon7;          /**< CCUCON7 Register configuration*/
    IfxScuCcu_CcuconRegConfig ccucon8;          /**< CCUCON8 Register configuration*/
} IfxScu_ClockDistributionConfig;

/** \brief Configuration structure SCU module.
 *
 */
typedef struct
{
    uint8 numOfPllDividerSteps;                         /**< Number of PLL divider steps during clock throttling*/
    IfxScu_PllStepsConfig *pllDividerStep;              /**< Pointer to the array of Pll divider step configuration*/
    IfxScu_InitialStepConfig pllInitialStep;            /**< Configuration of first step which is same as internal osc frequency*/
    IfxScu_ClockDistributionConfig clockDistribution;   /**< Configuration of of bus clocks and other module clock distribution*/
} IfxScuCcu_Config;

/** \brief Clock configuration structure instance.
 * This structure provided standard PLL configuration values defined at library.
 */
#define IFXSCU_START_SEC_CONST_UNSPECIFIED
#include "IFXSCU_MemMap.h"

IFX_EXTERN const IfxScuCcu_Config clockConfig;

#define IFXSCU_STOP_SEC_CONST_UNSPECIFIED
#include "IFXSCU_MemMap.h"

/******************************************************************************/
/*                           Function                                         */
/******************************************************************************/
#define IFXSCU_START_SEC_CODE
#include "IFXSCU_MemMap.h"

IFX_EXTERN float32 IfxScuCcu_getEvrFrequency (void);

/** \brief API to get FMAX divider frequency.
 *
 * This API returns the fMax frequency based on the divider value in CCUCON register and the input oscillator.
 *
 * \return Max frequency (fMAX) in Hz.
 *
 */
IFX_EXTERN float32 IfxScuCcu_getFmaxFrequency (void);


/** \brief API to get Oscillator frequency.
 *
 * This API returns the fOsc frequency based on the divider value in CCUCON register and the input oscillator.
 *
 * \return Osc frequency (fOSC) in Hz.
 *
 */
IFX_EXTERN float32 IfxScuCcu_getOscFrequency (void);


/** \brief API to get actual PLL (normal) frequency.
 *
 * This API returns the based on the divider values in CCUCON, PLLCON registers and the input oscillator.
 *
 * \return Frequency out PLL.
 *
 */
IFX_EXTERN float32 IfxScuCcu_getPllFrequency (void);



/** \brief API to get STM divider frequency.
 *
 * This API returns the based on the divider value in CCUCON register and the input oscillator.
 *
 * \return Frequency out of the STM divider
 *
 */
IFX_EXTERN float32 IfxScuCcu_getStmFrequency (void);


/** \brief API to get the module frequency.
 *
 * \param fdrU FDR register value for which the clock frequency is returned.
 *
 * \return Returns the module clock in Hz.
 */

#define IFXSCU_STOP_SEC_CODE
#include "IFXSCU_MemMap.h"

#endif /* IFXSCUCCU_H */

/*-------------------------------- end of file -------------------------------*/
