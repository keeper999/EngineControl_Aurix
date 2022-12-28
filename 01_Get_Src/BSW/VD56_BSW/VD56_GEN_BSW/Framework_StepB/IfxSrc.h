/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : Framework                                               */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : IFXSRC.h                                                */
/* !Description     : Framework component managing SRC                        */
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
 * %PID: P2017_BSW:0A111670.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef IFXSRC_H
#define IFXSRC_H

/******************************************************************************/
#include "IfxSrc_cfg.h"

/** \addtogroup IfxLld_Src
 * \{ */

/******************************************************************************/
/*                           Enum                              */
/******************************************************************************/


/******************************************************************************/
/*                           Functions                                        */
/******************************************************************************/
#define IFXSRC_START_SEC_CODE
#include "IFXSRC_MemMap.h"

/** \brief Disable a specific interrupt service request
 *
 * \param src Specifies the Service Request Control register for which the
 * interrupt has to be disabled.
 *
 * \return none.
 */
IFX_INLINE void IfxSrc_disable (volatile Ifx_SRC_SRCR * src)
{
    src->B.SRE = 0;
}

/** \brief Enable a specific interrupt service request
 *
 * \param src Specifies the Service Request Control register for which the
 * interrupt has to be enabled.
 *
 * \return none.
 */
IFX_INLINE void IfxSrc_enable (volatile Ifx_SRC_SRCR * src)
{
    src->B.SRE = 1;
}

/** \brief Reset a specific interrupt service by software
 *
 * \param src Specifies the Service Request Control register which the interrupt
 * has to be requested.
 *
 * \return none.
 */
IFX_INLINE void IfxSrc_clearRequest (volatile Ifx_SRC_SRCR * src)
{
    src->B.CLRR = 1;
}

/** \brief Request a specific interrupt service by software
 *
 * \param src Specifies the Service Request Control register which the interrupt
 * has to be requested.
 *
 * \return none.
 */
IFX_INLINE void IfxSrc_setRequest (volatile Ifx_SRC_SRCR * src)
{
    src->B.SETR = 1;
}

/** \brief Initialize the service request control register
 *
 * \param src Specifies the Service Request Control register
 * \param typOfService Type of service
 * \param priority Interrupt priority
 *
 * \return none.
 */
IFX_INLINE void IfxSrc_init (volatile Ifx_SRC_SRCR * src, IfxSrc_Tos typOfService, uint16 priority)
{
    src->B.SRPN = priority;
    src->B.TOS = typOfService;
    IfxSrc_clearRequest (src);
}

IFX_INLINE void IfxSrc_deinit (volatile Ifx_SRC_SRCR * src)
{
    src->U = 0;
}

/** \} */

/*Documentation */
/** \addtogroup IfxLld_Src_Usage
 * \{ */
/** \page Ifx_Src_Usage How to use service request mechanism?
 *
 * For Aurix controllers peripherals that can generate service requests is connected to one
 * or more Service Request Nodes (SRNs) in the central Interrupt Router module. Refer to Controller
 * User Manual for more details\n
 *
 * IfxSrc driver provides the APIs to configure and control service requests. Refer \ref Ifx_Src for
 * details of these APIs.
 *
 * \section Ifx_Src_UsageInit Initialize the Service Request Node
 * Service request node is initialized to configure the following,\n
 * 1) Route the interrupt trigger to service provider, which are:\n
 * __a. One of the available CPUs or\n
 * __b. DMA controller\n
 * 2) Priority of CPU Interrupt or DMA trigger.
 *
 * For Interrupt or DMA to be correctly triggered, following steps are to be done in the user code:
 *
 * \subsection Ifx_Src_UsageInitStep1 Step1: Configure the node
 * User must configure the service request node in the application / driver files.
 *
 * \subsection Ifx_Src_UsageInitStep2 Step2: Enable the trigger
 * Enable the service request node to connect the trigger event from the hardware to service provider.
 *
 * Example:
 * Following example show the configuration for STM0 Service request 0 trigger configured to trigger
 * CPU1 with the priority specified by IFX_INTPRIO_STM0 (from the example at IfxCpu_Irq)
 *
 * \code
 * //file: myApplication.c
 *
 * #include "Ifx_IntPrioDef.h" // to get the priority numbers
 *
 * void myDriverInitFunction(void)
 * {
 *   //driver init code
 *   // :
 *
 *   //Step1: Call the function to route the trigger from for SRC_STM0_SR0 to CPU1
 *   //and priority specified at Ifx_IntPrioDef.h globally
 *   IfxSrc_init (&MODULE_SRC.STM[0].SR[0], IfxSrc_Tos_cpu1, IFX_INTPRIO_STM0);
 *
 *   //Step2: Enable the service request node
 *   IfxSrc_enable (&MODULE_SRC.STM[0].SR[0]);
 *   // :
 * }
 * \endcode
 *
 */

#define IFXSRC_STOP_SEC_CODE
#include "IFXSRC_MemMap.h"

#endif /* IFXSRC_H */

/*-------------------------------- end of file -------------------------------*/
