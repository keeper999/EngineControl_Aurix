/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : KRN                                                     */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : KRN_Types.h                                             */
/* !Description     : Type definition of KRN Component                        */
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
 * %PID: P2017_BSW:0A192471.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef KRN_TYPES_H
#define KRN_TYPES_H

#include "Std_Types.h"
#include "SWFAIL.h"

/******************************************************************************/
/* DEFINE                                                                     */
/******************************************************************************/
/* Must be equal to the NvMNvBlockLength of BSW_BLOCK_EXCEPTIONS NvM block    */
/* Should be in KRN_Private.h, but I prefer to put all nvM related object in  */
/* same file. And in a futur nvM plugin, this define will disappear           */
#define KRN_NVM_SIZE_OF_EXCEPTION_REGS 12


/******************************************************************************/
/* TYPEDEF                                                                    */
/******************************************************************************/
/* BE CAREFULL : If structure size change, you must update Tresos NvM and Fee configuration */
/* to configure BSW_BLOCK_EXCEPTIONS blocks with the new size                               */
typedef struct
{
   void *                  pfvidLocalErrorAddress;
   SWFAIL_tbfErrorType     bfLocalErrorType;
   uint16                  u16LocalExceptionsErrorCnt;
   uint16                  u16LocalStackErrorCnt;
} KRN_tstrExceptionRegs;



#endif /* KRN_TYPES_H */

/*-------------------------------- end of file -------------------------------*/
