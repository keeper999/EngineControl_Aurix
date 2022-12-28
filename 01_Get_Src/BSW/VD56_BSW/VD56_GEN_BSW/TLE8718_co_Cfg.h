/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : TLE8718                                                                                         */
/* !Description     : Driver To Manage TLE8718 Device                                                                 */
/*                                                                                                                    */
/* !File            : TLE8718_co_Cfg.h                                                                                */
/* !Description     : TLE8718 conditional compilation configurations                                                  */
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
 * %PID: P2017_BSW:0A192480.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#ifndef TLE8718_CO_CFG_H
#define TLE8718_CO_CFG_H

/**********************************************************************************************************************/
/* DEFINE                                                                                                             */
/**********************************************************************************************************************/

/* !MComment : Defines for Enabling or Disabling Strategies */
#define TLE8718_coENABLED               1u
#define TLE8718_coDISABLED              0u

/* !Comment : Defines for Enabling or Disabling Use of DMA to Receive Upstream Frames */
/* In our case we want to use DMA: */
#define TLE8718_coDMA_USE_FOR_FRAME_RX  TLE8718_coENABLED

#endif /* TLE8718_CO_CFG_H */

/*--------------------------------------------------- END OF FILE ----------------------------------------------------*/
