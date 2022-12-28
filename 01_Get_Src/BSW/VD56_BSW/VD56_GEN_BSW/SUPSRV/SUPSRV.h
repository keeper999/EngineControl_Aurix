/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : SUPSRV                                                  */
/* !Description     : Supplier Services component                             */
/*                                                                            */
/* !File            : SUPSRV.h                                                */
/* !Description     : SUPSRV services declaration                             */
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
 * %PID: P2017_BSW:0A157049.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef SUPSRV_H
#define SUPSRV_H

#include "Std_Types.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* !Comment: After Sale Area Address Begin                                    */
#define SUPSRV_u32AFTER_SALE_AREA_ADDRESS_BEG ( (uint32)0x0001CE00U)

/* !Comment: After Sale Area Granularity                                      */
#define SUPSRV_u16AFTER_SALE_AREA_GRANULATITY ( (uint16)256U)


/******************************************************************************/
/* GLOBAL FUNCTION DECLARATION                                                */
/******************************************************************************/

#define SUPSRV_START_SEC_CODE
#include "SUPSRV_MemMap.h"

void           SUPSRV_vidEnterReprogMode(uint16 u16MicroControllerTemp);

/* stubed functions */
uint16         SUPSRV_u16ReadAppliKey(uint8 *pau8Buffer, uint16 u16MaxSize);
uint16         SUPSRV_u16ReadHistoryArea(uint8 u8LidId, uint8 *pau8Buffer, uint16 u16MaxSize);
Std_ReturnType SUPSRV_udtJumpToFinalTest(uint8 u8TprodParameter);
Std_ReturnType SUPSRV_udtJumpToReliabTest(uint8 u8TprodParameter);
uint16         SUPSRV_u16ReadFuncProdNr(uint8 *pau8Buffer, uint16 u16MaxSize);
uint16         SUPSRV_u16ReadFuncSchemNr(uint8 *pau8Buffer, uint16 u16MaxSize);
uint16         SUPSRV_u16ECUIdentification(uint8 *pau8Buffer, uint16 u16MaxSize);
uint8*         SUPSRV_pu8AftSaleReadBaseAddr(void);
uint16         SUPSRV_u16AftSaleReadBlockSize(void);
Std_ReturnType SUPSRV_udtAftSaleWriteFlash(const uint8 *pku8SourceAddress, uint8 *pu8TargetAddress, uint32 u32Length);
uint8          SUPSRV_u8UnlockAlgorithm(uint8 *pau8Seed, uint8 u8SeedSize, uint8 *pau8UnlockKey);

#define SUPSRV_STOP_SEC_CODE
#include "SUPSRV_MemMap.h"


#endif /* SUPSRV_H */

/*------------------------------- end of file --------------------------------*/
