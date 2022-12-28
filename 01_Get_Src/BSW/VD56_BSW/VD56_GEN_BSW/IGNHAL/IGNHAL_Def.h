/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : IGNHAL                                                  */
/* !Description     : Ignition Driver Component                               */
/*                                                                            */
/* !File            : IGNHAL_Def.h                                            */
/* !Description     : Data declaration                                        */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;
 * <Revision>
 * %PID: P2017_BSW:A30387.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "IGNHAL_Cfg.h"


/******************************************************************************/
/* DATA DECLARATION                                                           */
/******************************************************************************/

#define IGNHAL_START_SEC_VAR_CLEARED_BOOLEAN
#include "IGNHAL_MemMap.h"

extern boolean IGNHAL_abDiagDone[IGNHAL_COILS_CHANNEL_NB];
extern boolean IGNHAL_abDiagRequest[IGNHAL_COILS_CHANNEL_NB];
extern boolean IGNHAL_bAdaptCalcValid[IGNHAL_COILS_CHANNEL_NB];
extern boolean IGNHAL_bOCDefaultFlag[IGNHAL_COILS_CHANNEL_NB];
extern boolean IGNHAL_bSCDefaultFlag[IGNHAL_COILS_CHANNEL_NB];
extern boolean IGNHAL_bSlopeAcqValid[IGNHAL_COILS_CHANNEL_NB];
/* !Comment: external coil : not used currently                               */
extern boolean IGNHAL_bOORDefaultFlag[IGNHAL_COILS_CHANNEL_NB];
extern boolean IGNHAL_bSCGDefaultFlag[IGNHAL_COILS_CHANNEL_NB];

#define IGNHAL_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "IGNHAL_MemMap.h"


#define IGNHAL_START_SEC_VAR_CLEARED_8BIT
#include "IGNHAL_MemMap.h"

extern uint8 IGNHAL_au8DesiredVoltage[IGNHAL_COILS_CHANNEL_NB];
extern uint8 IGNHAL_u8EventStateMachine[IGNHAL_COILS_CHANNEL_NB];

#define IGNHAL_STOP_SEC_VAR_CLEARED_8BIT
#include "IGNHAL_MemMap.h"


#define IGNHAL_START_SEC_VAR_CLEARED_16BIT
#include "IGNHAL_MemMap.h"

extern sint16 IGNHAL_s16AdaptOffset[IGNHAL_COILS_CHANNEL_NB];
extern uint16 IGNHAL_u16AdaptFactor[IGNHAL_COILS_CHANNEL_NB];

extern uint16 IGNHAL_u16AngleSlope1[IGNHAL_COILS_CHANNEL_NB];
extern uint16 IGNHAL_u16AngleSlope2[IGNHAL_COILS_CHANNEL_NB];
extern uint16 IGNHAL_u16VoltageSlope1[IGNHAL_COILS_CHANNEL_NB];
extern uint16 IGNHAL_u16VoltageSlope2[IGNHAL_COILS_CHANNEL_NB];

extern uint16 IGNHAL_u16AbsAngleSlope1[IGNHAL_COILS_CHANNEL_NB];
extern uint16 IGNHAL_u16AbsAngleSlope2[IGNHAL_COILS_CHANNEL_NB];
extern uint16 IGNHAL_au16EndAngle[IGNHAL_COILS_CHANNEL_NB];

#define IGNHAL_STOP_SEC_VAR_CLEARED_16BIT
#include "IGNHAL_MemMap.h"


#define IGNHAL_START_SEC_VAR_CLEARED_32BIT
#include "IGNHAL_MemMap.h"

extern uint32 IGNHAL_u32DateOnCoil[IGNHAL_COILS_CHANNEL_NB];
extern uint32 IGNHAL_u32ScDateOnCoil[IGNHAL_COILS_CHANNEL_NB];
extern uint32 IGNHAL_u32DwellTime[IGNHAL_COILS_CHANNEL_NB];
extern uint32 IGNHAL_u32TimeSlope1[IGNHAL_COILS_CHANNEL_NB];
extern uint32 IGNHAL_u32TimeSlope2[IGNHAL_COILS_CHANNEL_NB];
extern uint32 IGNHAL_au32WdgDelay[IGNHAL_COILS_CHANNEL_NB];

#define IGNHAL_STOP_SEC_VAR_CLEARED_32BIT
#include "IGNHAL_MemMap.h"

/*------------------------------ end of file ---------------------------------*/
