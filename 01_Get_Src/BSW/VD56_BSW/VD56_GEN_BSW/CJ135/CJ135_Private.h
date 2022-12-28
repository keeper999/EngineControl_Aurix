/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : CJ135                                                                                           */
/* !Description     : Driver for Robert Bosch GmbH CJ135                                                              */
/*                                                                                                                    */
/* !File            : CJ135_Private.h                                                                                 */
/* !Description     : CJ135 Private definition                                                                        */
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
 * %PID: P2017_BSW:0A188667.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/
#ifndef CJ135_PRIVATE_H
#define CJ135_PRIVATE_H

#include "CJ135_Cfg.h"
#include "CJ135_Types.h"


/**********************************************************************************************************************/
/* DEFINES                                                                                                            */
/**********************************************************************************************************************/

/* Masks used for SPI reading  */
#define CJ135_u16MASK_MEASURING_WORD 0xFFFE
#define CJ135_u16MASK_IP_WORD        0xFFFC

/* Macros used for bit handling in registers*/
#define CJ135_u16CLEAR_TAKEDATA(u16RegisterMode) ((u16RegisterMode)&0xFFFE)
#define CJ135_u16SET_TAKEDATA(u16RegisterMode) ((u16RegisterMode)|0x0001)
#define CJ135_u16CLEAR_MODE(u16RegisterMode) ((u16RegisterMode)&0xFFF1)
#define CJ135_u16SHIFT_MODE(udtState) ((((uint16)udtState)<<1)&0x000E)
#define CJ135_u16EXTRACT_MODE(u16RegisterMode) ((uint16)((u16RegisterMode>>1)&0x0007))
#define CJ135_u16CLEAR_TRIMSQR(u16RegisterTrim) ((u16RegisterTrim)&0xFF80)
#define CJ135_u16SHIFT_TRIMSQR(u8TRIMSQrValue) (((uint16)u8TRIMSQrValue)&0x7F)
#define CJ135_u16CLEAR_TRIMSQ(u16RegisterTrim) ((u16RegisterTrim)&0xC07F)
#define CJ135_u16SHIFT_TRIMSQ(u8TRIMSQValue) ((((uint16)u8TRIMSQValue)<<7)&0x3F80)
#define CJ135_u16SET_RESREG_RESDSP(u16RegisterConfigDSP) ((u16RegisterConfigDSP)|0x0300)

/* Number max -1 of allowed of failed Check register read  */
/* TODO: generate by OIL ? */
#define CJ135_u8REGISTER_CHECK_NUMBER_OF_TRY 2
#define CJ135_u8REGISTER_INIT_NUMBER_OF_TRY 3

/**********************************************************************************************************************/
/* return value of SpiM notifications                                                                                 */
/**********************************************************************************************************************/
#define CJ135_E_OK            0
#define CJ135_E_NOT_OK        1
#define CJ135_E_SPI_ERROR     2
#define CJ135_E_SPI_RUNNING   3


/**********************************************************************************************************************/
/* SPI protocol defines                                                                                               */
/**********************************************************************************************************************/

/* Error Code */
#define CJ135_u8SPI_OK                          0
#define CJ135_u8SPI_RESEND                      1
#define CJ135_u8SPI_FAILURE                     2
#define CJ135_u8SPI_SEND_WRONG_CMD              3

/**********************************************************************************************************************/
/* CONSTANTS                                                                                                          */
/**********************************************************************************************************************/
#define CJ135_START_SEC_CONST_UNSPECIFIED
#include "CJ135_MemMap.h"

extern const CJ135_tstrConfig CJ135_akstrConfig[CJ135_u8NB_OF_DEVICE];

#define CJ135_STOP_SEC_CONST_UNSPECIFIED
#include "CJ135_MemMap.h"


/**********************************************************************************************************************/
/* CALIBRATIONS                                                                                                       */
/**********************************************************************************************************************/

#define CJ135_START_SEC_CALIB_16BIT
#include "CJ135_MemMap.h"

extern const uint16 CJ135_ku16RegConfigDsp;
extern const uint16 CJ135_ku16RegIpOff;
extern const uint16 CJ135_ku16RegMode;
extern const uint16 CJ135_ku16RegRefpat;
extern const uint16 CJ135_ku16RegSteerpat;
extern const uint16 CJ135_ku16RegTrim;
extern const uint16 CJ135_ku16RegUnset;
extern const uint16 CJ135_ku16RegUego0;
extern const uint16 CJ135_ku16RegUego1;
extern const uint16 CJ135_ku16RegUego2;
extern const uint16 CJ135_ku16RegUego3;
extern const uint16 CJ135_ku16RegUego4;
extern const uint16 CJ135_ku16RegUego5;
extern const uint16 CJ135_ku16RegUp0lean;
extern const uint16 CJ135_ku16RegUp0rich;
extern const uint16 CJ135_ku16RegFree;

#define CJ135_STOP_SEC_CALIB_16BIT
#include "CJ135_MemMap.h"

/**********************************************************************************************************************/
/* VARIABLES                                                                                                          */
/**********************************************************************************************************************/
#define CJ135_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CJ135_MemMap.h"

extern CJ135_strData CJ135_astrData[CJ135_u8NB_OF_DEVICE];

#define CJ135_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CJ135_MemMap.h"


/**********************************************************************************************************************/
/* FUNCTIONS DECLARATION                                                                                              */
/**********************************************************************************************************************/
#define CJ135_START_SEC_CODE
#include "CJ135_MemMap.h"
extern void CJ135_vidPeriodicFunction(const CJ135_tstrConfig *pkstrConfig, CJ135_strData *pstrData);
extern void CJ135_vidReceiveFirstIRQ(CJ135_strData  *pstrData);
extern void CJ135_vidSendFirstIRQ(CJ135_strData  *pstrData);
extern void CJ135_vidStateMachineMain(const CJ135_tstrConfig *pkstrConfig, CJ135_strData *pstrData);
extern void CJ135_vidStateMachinePost(const CJ135_tstrConfig *pkstrConfig, CJ135_strData *pstrData);
extern Std_ReturnType CJ135_udtCheckConfig(CJ135_strData  *pstrData);
extern Std_ReturnType CJ135_udtCalculateRie(const CJ135_tstrConfig *pkstrConfig, CJ135_strData  *pstrData);
extern Std_ReturnType CJ135_udtCalculateIpeff(const CJ135_tstrConfig *pkstrConfig, CJ135_strData  *pstrData);
#define CJ135_STOP_SEC_CODE
#include "CJ135_MemMap.h"


#endif /* CJ135_PRIVATE_H */

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/
