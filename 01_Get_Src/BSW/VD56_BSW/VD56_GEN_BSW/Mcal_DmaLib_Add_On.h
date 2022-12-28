/**********************************************************************************************************************/
/* !Layer           : MCAL                                                                                            */
/* !Component       : MCAL_DMALIB                                                                                     */
/* !Description     : Mcal Dma library routines                                                                       */
/*                                                                                                                    */
/* !File            : Mcal_DmaLib_Add_On.h                                                                            */
/* !Description     : This file defines the add-on API of the Mcal_DmaLib component.                                  */
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
 * %PID: P2017_BSW:0A192541.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#ifndef MCAL_DMALIB_ADD_ON_H
#define MCAL_DMALIB_ADD_ON_H

#include "Std_Types.h"
#include "IfxDma_bf.h"
#include "IfxDma_reg.h"

/**********************************************************************************************************************/
/* DEFINE                                                                                                             */
/**********************************************************************************************************************/
/* Dma CHCFGR register Channel RROAT mask */
#define DMA_CHCFGR_RROAT_MASK  (~(IFX_DMA_CH_CHCFGR_RROAT_MSK  << IFX_DMA_CH_CHCFGR_RROAT_OFF))
/* Dma CHCFGR register Channel PRSEL mask */
#define DMA_CHCFGR_PRSEL_MASK  (~(IFX_DMA_CH_CHCFGR_PRSEL_MSK  << IFX_DMA_CH_CHCFGR_PRSEL_OFF))
/* Dma CHCFGR register Channel CHMODE mask */
#define DMA_CHCFGR_CHMODE_MASK (~(IFX_DMA_CH_CHCFGR_CHMODE_MSK << IFX_DMA_CH_CHCFGR_CHMODE_OFF))

/**********************************************************************************************************************/
/* MACRO FUNCTIONS                                                                                                    */
/**********************************************************************************************************************/

/**********************************************************************************************************************/
/* !FuncName    : Mcal_DmaSetRroat                                                                                    */
/* !Description : Configuration of RROAT field of CHCFGR Register                                                     */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
_EXTERN_ _INLINE_ void Mcal_DmaSetRroat(Dma_ChannelType Channel, uint32 u32value)
{
   MODULE_DMA.CH[Channel].CHCFGR.U = ((MODULE_DMA.CH[Channel].CHCFGR.U  & (DMA_CHCFGR_RROAT_MASK))
                                   | ((u32value & IFX_DMA_CH_CHCFGR_RROAT_LEN) << IFX_DMA_CH_CHCFGR_RROAT_OFF));
}

/**********************************************************************************************************************/
/* !FuncName    : Mcal_DmaSetPrsel                                                                                    */
/* !Description : Configuration of PRSEL field of CHCFGR Register                                                     */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
_EXTERN_ _INLINE_ void Mcal_DmaSetPrsel(Dma_ChannelType Channel, uint32 u32value) 
{
   MODULE_DMA.CH[Channel].CHCFGR.U = ((MODULE_DMA.CH[Channel].CHCFGR.U  & (DMA_CHCFGR_PRSEL_MASK))
                                   | ((u32value & IFX_DMA_CH_CHCFGR_PRSEL_LEN) << IFX_DMA_CH_CHCFGR_PRSEL_OFF));
}

/**********************************************************************************************************************/
/* !FuncName    : Mcal_DmaSetChmode                                                                                   */
/* !Description : Configuration of CHMODE field of CHCFGR Register                                                    */
/*                                                                                                                    */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
_EXTERN_ _INLINE_ void Mcal_DmaSetChmode(Dma_ChannelType Channel, uint32 u32value) 
{
   MODULE_DMA.CH[Channel].CHCFGR.U = ((MODULE_DMA.CH[Channel].CHCFGR.U  & (DMA_CHCFGR_CHMODE_MASK))
                                   | ((u32value & IFX_DMA_CH_CHCFGR_CHMODE_LEN) << IFX_DMA_CH_CHCFGR_CHMODE_OFF));
}

#endif /* MCAL_DMALIB_ADD_ON_H */
/*--------------------------------------------------- END OF FILE ----------------------------------------------------*/
