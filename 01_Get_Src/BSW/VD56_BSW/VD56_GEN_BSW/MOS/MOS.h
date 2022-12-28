/************************************************* <AUTO_FILE_HEADER> *************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : MOS                                                                                             */
/* !Description     : Drive and Diag HW MOS component commanded through DIO                                           */
/*                                                                                                                    */
/* !File            : MOS.h                                                                                           */
/* !Description     : API for Diagnosis functions of the Component                                                    */
/*                                                                                                                    */
/* !Reference       : PTS_DOC_5012137 01                                                                              */
/* !Reference       : PTS_DOC_5199248 01                                                                              */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/************************************************ </AUTO_FILE_HEADER> *************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: LIBEMB:A2543.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/
#ifndef MOS_H
#define MOS_H

#include "MOS_Cfg.h"
#include "MOS_Types.h"
#include "MOS_Private.h"
#include "Std_Types.h"
#include "Hod.h"



/******************************************************************************/
/* Defines                                                                    */
/******************************************************************************/

#define MOS_u8CMD_DISABLED_DESTRUCT_FLT   2    /* 0x02 */
#define MOS_u8CMD_DISABLED_WITHOUT_FLT    1    /* 0x01 */
#define MOS_u8CMD_ENABLED                 0    /* 0x00 */

/******************************************************************************/
/* Prototypes                                                                 */
/******************************************************************************/

extern FUNC(void, MOS_CODE) MOS_vidInit(void);
extern FUNC(void, MOS_CODE) MOS_vidEnableDiag(HOD_tudtInstance udtInstance);
extern FUNC(void, MOS_CODE) MOS_vidDisableDiag(HOD_tudtInstance udtInstance);
extern FUNC(void, MOS_CODE) MOS_vidSetMode(HOD_tudtInstance udtInstance, HOD_tudtChannel udtChannel, HOD_tenuMode enuMode);
extern FUNC(void, MOS_CODE) MOS_vidEnableCmd(HOD_tudtInstance udtInstance, HOD_tenuCutMode enuCutMode);
extern FUNC(void, MOS_CODE) MOS_vidDisableCmd(HOD_tudtInstance udtInstance, HOD_tenuCutMode enuCutMode);
extern FUNC(void, MOS_CODE) MOS_vidSetMode(HOD_tudtInstance udtInstance, HOD_tudtChannel udtChannel, HOD_tenuMode enuMode);
extern FUNC(void, MOS_CODE) MOS_vidDioWrite(HOD_tudtInstance udtInstance, HOD_tudtChannel udtChannel, boolean bState);
extern FUNC(boolean, MOS_CODE) MOS_bDioRead(HOD_tudtInstance udtInstance, HOD_tudtChannel udtChannel);
extern FUNC(void, MOS_CODE) MOS_vidMainFunction(HOD_tudtInstance udtInstance);

#endif /* MOS_H  */
/*-------------------------------- end of file -------------------------------*/