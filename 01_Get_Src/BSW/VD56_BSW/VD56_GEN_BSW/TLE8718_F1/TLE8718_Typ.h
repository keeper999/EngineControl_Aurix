/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : TLE8718                                                                                         */
/* !Description     : Driver for TLE8718 Device                                                                       */
/*                                                                                                                    */
/* !File            : TLE8718_Typ.h                                                                                   */
/* !Description     : Internal Types of TLE8718 Component                                                             */
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
 * %PID: P2017_BSW:0A133930.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#ifndef TLE8718_TYP_H
#define TLE8718_TYP_H

#include "Std_Types.h"

/**********************************************************************************************************************/
/* TYPES                                                                                                              */
/**********************************************************************************************************************/

/* !Comment : TLE8718 Component State */
typedef enum
{
   TLE8718_STATE_UNINIT             = 0u,
   TLE8718_STATE_INIT_READY         = 1u,
   TLE8718_STATE_CONREG_INIT        = 2u,
   TLE8718_STATE_OUT1516REG_INIT    = 3u,
   TLE8718_STATE_ENA_DATA_FRAME_OUT = 4u,
   TLE8718_STATE_RUNNING            = 5u,
   TLE8718_STATE_EMERGENCY          = 6u
} TLE8718_tenuStateType;

typedef enum
{
   /* Sequences must be ordered highest priority first */
   TLE8718_MSCM_SEQ_WR_OUT1516      = 0u,   
   TLE8718_MSCM_SEQ_DIAG            = 1u,   
   TLE8718_MSCM_SEQ_SAFETY          = 2u,   
   TLE8718_MSCM_SEQ_CONREG_INIT     = 3u,
   TLE8718_MSCM_SEQ_OUT1516REG_INIT = 4u,
   TLE8718_MSCM_SEQ_ENA_DATA_FR_OUT = 5u,
   /* /!\ Don't change nor move following defines */
   TLE8718_MSCM_SEQ_WAITING_STATE   = 6u /* Nothing to do, must be the last enum value */
} TLE8718_tenuMscMSequences;

typedef enum
{
   TLE8718_udtSEQ_IDLE     = 0u,
   TLE8718_udtSEQ_RUNNING  = 1u,
   TLE8718_udtSEQ_SENT_OK  = 2u,
   TLE8718_udtSEQ_SENT_NOK = 3u
} TLE8718_tenuReturnType;

#endif /* TLE8718_TYP_H */

/*--------------------------------------------------- END OF FILE ----------------------------------------------------*/
