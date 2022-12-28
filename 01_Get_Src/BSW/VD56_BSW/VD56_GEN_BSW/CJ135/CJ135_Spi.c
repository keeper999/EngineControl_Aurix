/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : CJ135                                                                                           */
/* !Description     : Driver for Robert Bosch GmbH CJ135                                                              */
/*                                                                                                                    */
/* !File            : CJ135_Spi.c                                                                                     */
/* !Description     : Low level SPI protocol                                                                          */
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
 * %PID: P2017_BSW:0A188661.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#include "Std_Types.h"
#include "Spi.h"
#include "CJ135.h"
#include "CJ135_Private.h"
#include "CJ135_Spi.h"
#include "CJ135_SpiM.h"
#include "CJ135_Types.h"
#include "SchM_CJ135.h"


/**********************************************************************************************************************/
/* FUNCTION DEFINITION                                                                                                */
/**********************************************************************************************************************/
#define CJ135_START_SEC_CODE
#include "CJ135_MemMap.h"


/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiInit                                                                                    */
/* !Description : Init function of Spi layer                                                                          */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
void CJ135_vidSpiInit(const CJ135_tstrConfig *pkstrConfig,
                      CJ135_strData          *pstrData)
{
   COMPILER_UNUSED_PARAMETER(pkstrConfig);

   pstrData->u16SpiLastSentCommand     = 0;   /* done but don't care, will be write before used */
   pstrData->u8SpiDiagnostic           = CJ135_u8SPI_OK;
   pstrData->u8SpiTransmitErrorCounter = 0;
}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiTxConfirmation                                                                          */
/* !Description : This function is called by all SPI handler end of seqeunce notification                             */
/*                The CJ135_Cfg.c provide on confirmation by instance, which call this function with good parameters  */
/*                For efficency, the CFG compute, in pre-build, most of needed parameters.                            */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
void CJ135_vidSpiTxConfirmation(const CJ135_tstrConfig *pkstrConfig,
                                CJ135_strData          *pstrData,
                                uint16                  u16ReceiveData)
{

   CJ135_vidSpiM_ManagerTxConf(pkstrConfig, pstrData, u16ReceiveData, CJ135_u8SPI_OK);

}

/**********************************************************************************************************************/
/* !FuncName    : CJ135_vidSpiResetErrorCounter                                                                       */
/* !Description : Set the transmission error counter to its default value.                                            */
/*                                                                                                                    */
/* !LastAuthor  : T. Boucher-Lambert                                                                                  */
/**********************************************************************************************************************/
void CJ135_vidSpiResetErrorCounter(const CJ135_tstrConfig *pkstrConfig, CJ135_strData *pstrData)
{
   COMPILER_UNUSED_PARAMETER(pkstrConfig);
   pstrData->u8SpiTransmitErrorCounter = CJ135_u8SPI_NB_SENT_MAX;
}


#define CJ135_STOP_SEC_CODE
#include "CJ135_MemMap.h"

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/
