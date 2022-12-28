/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : IFX_CFG                                                 */
/* !Description     : Configuration of MCAL Ifx Component                     */
/*                                                                            */
/* !File            : IFX_CFG.h                                               */
/* !Description     : Configuration of MCAL Ifx Component                     */
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
 * %PID: P2017_BSW:0A111638.A-SRC;3 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef IFXCFG_H
#define IFXCFG_H


/******************************************************************************/
/* Configuration of Clock                                                     */
/******************************************************************************/

/* Clk init */
#define IFX_CFG_SCU_XTAL_FREQUENCY    (20000000u)  /* Allowed values 16000000u, 20000000u or 40000000u */
#define IFX_CFG_SCU_PLL_FREQUENCY     (200000000u) /* Allowed values 80000000u, 133000000u, 160000000u or 200000000u */

/******************************************************************************/
/* Configuration of PSW                                                       */
/******************************************************************************/
/* !Comment: For each core:                                                   */
/*           IS bit  set to 1  => Shared Global Stack                         */
/*           IO bits set to 10 => Supervisor Mode                             */
#define STARTUP_CORE0_PSW_DEFAULT     (0x00000B80)
#define STARTUP_CORE1_PSW_DEFAULT     (0x00000B80)
#define STARTUP_CORE2_PSW_DEFAULT     (0x00000B80)

/******************************************************************************/
/* Configuration of PCX_O                                                     */
/******************************************************************************/
#define STARTUP_CORE0_PCX_O_S_DEFAULT (0xfff00000u)
#define STARTUP_CORE1_PCX_O_S_DEFAULT (0xfff00000u)
#define STARTUP_CORE2_PCX_O_S_DEFAULT (0xfff00000u)

/******************************************************************************/
/* Enable of Program Cache                                                    */
/******************************************************************************/
#define STARTUP_CORE0_ENA_PCACHE      (1u) /* Program Cache enabled for CPU0  */
#define STARTUP_CORE1_ENA_PCACHE      (1u) /* Program Cache enabled for CPU1  */
#define STARTUP_CORE2_ENA_PCACHE      (1u) /* Program Cache enabled for CPU2  */

/******************************************************************************/
/* Enable of Data Cache                                                       */
/******************************************************************************/
#define STARTUP_CORE0_ENA_DCACHE      (1u) /* Data Cache enabled for CPU0     */
#define STARTUP_CORE1_ENA_DCACHE      (1u) /* Data Cache enabled for CPU1     */
#define STARTUP_CORE2_ENA_DCACHE      (1u) /* Data Cache enabled for CPU2     */

#endif /* IFX_CFG_H */

/*-------------------------------- end of file -------------------------------*/
