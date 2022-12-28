/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : ISR                                                     */
/* !Description     : ISR Management                                          */
/*                                                                            */
/* !File            : Spi_Isr.c                                               */
/* !Description     : ISR definition of Spi component                         */
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
 * %PID: P2017_BSW:0A192588.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Isr_Cfg.h"
#include "Os.h"
#include "Spi.h"

/******************************************************************************/
/* !Comment: INT linked to SRC_QSPI_QSPIx_HC (x = 0..5) not used              */
/******************************************************************************/

#define ISR_START_SEC_CODE
#include "ISR_MemMap.h"

/******************************************************************************/
/* !FuncName    : INT(SRC_QSPI_QSPI0_ERR_ISR)                                 */
/* !Description : Service for Error interrupt of QSPI0                        */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if ((SPI_QSPI0_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
#if (SRC_QSPI_QSPI0_ERR_USED == STD_ON)
INT(SRC_QSPI_QSPI0_ERR_ISR)
{
   /* Call QSPI0 Interrupt funtion */
   Spi_IsrQspiError(SPI_QSPI0_INDEX);
}
#endif /* if (SRC_QSPI_QSPI0_ERR_USED == STD_ON) */
#endif /* if ((SPI_QSPI0_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0)) */


/******************************************************************************/
/* !FuncName    : INT(SRC_QSPI_QSPI1_ERR_ISR)                                 */
/* !Description : Service for Error interrupt of QSPI1                        */
/*                                                                            */
/* !LastAuthor  : M. Sabry                                                    */
/******************************************************************************/
#if ((SPI_QSPI1_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
#if (SRC_QSPI_QSPI1_ERR_USED == STD_ON)
INT(SRC_QSPI_QSPI1_ERR_ISR)
{
   /* Call QSPI0 Interrupt funtion */
   Spi_IsrQspiError(SPI_QSPI1_INDEX);
}
#endif /* if (SRC_QSPI_QSPI1_ERR_USED == STD_ON) */
#endif /* if ((SPI_QSPI1_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0)) */


/******************************************************************************/
/* !FuncName    : INT(SRC_QSPI_QSPI2_ERR_ISR)                                 */
/* !Description : Service for Error interrupt of QSPI2                        */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if ((SPI_QSPI2_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
#if (SRC_QSPI_QSPI2_ERR_USED == STD_ON)
INT(SRC_QSPI_QSPI2_ERR_ISR)
{
   /* Call QSPI0 Interrupt funtion */
   Spi_IsrQspiError(SPI_QSPI2_INDEX);
}
#endif /* if (SRC_QSPI_QSPI2_ERR_USED == STD_ON) */
#endif /* if ((SPI_QSPI2_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0)) */


/******************************************************************************/
/* !FuncName    : INT(SRC_QSPI_QSPI3_ERR_ISR)                                 */
/* !Description : Service for Error interrupt of QSPI3                        */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if ((SPI_QSPI3_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
#if (SRC_QSPI_QSPI3_ERR_USED == STD_ON)
INT(SRC_QSPI_QSPI3_ERR_ISR)
{
   /* Call QSPI0 Interrupt funtion */
   Spi_IsrQspiError(SPI_QSPI3_INDEX);
}
#endif /* if (SRC_QSPI_QSPI3_ERR_USED == STD_ON) */
#endif /* if ((SPI_QSPI3_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0)) */


/******************************************************************************/
/* !FuncName    : INT(SRC_QSPI_QSPI4_ERR_ISR)                                 */
/* !Description : Service for Error interrupt of QSPI4                        */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if ((SPI_QSPI4_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
#if (SRC_QSPI_QSPI4_ERR_USED == STD_ON)
INT(SRC_QSPI_QSPI4_ERR_ISR)
{
   /* Call QSPI0 Interrupt funtion */
   Spi_IsrQspiError(SPI_QSPI4_INDEX);
}
#endif /* if (SRC_QSPI_QSPI4_ERR_USED == STD_ON) */
#endif /* if ((SPI_QSPI4_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0)) */


/******************************************************************************/
/* !FuncName    : INT(SRC_QSPI_QSPI5_ERR_ISR)                                 */
/* !Description : Service for Error interrupt of QSPI5                        */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if ((SPI_QSPI5_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
#if (SRC_QSPI_QSPI5_ERR_USED == STD_ON)
INT(SRC_QSPI_QSPI5_ERR_ISR)
{
   /* Call QSPI0 Interrupt funtion */
   Spi_IsrQspiError(SPI_QSPI5_INDEX);
}
#endif /* if (SRC_QSPI_QSPI5_ERR_USED == STD_ON) */
#endif /* if ((SPI_QSPI5_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0)) */


/******************************************************************************/
/* !FuncName    : INT(SRC_QSPI_QSPI0_PT_ISR)                                  */
/* !Description : Service for Phase transition interrupt (PT2) used by QSPI0  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if ((SPI_QSPI0_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
#if (SRC_QSPI_QSPI0_PT_USED == STD_ON)
INT(SRC_QSPI_QSPI0_PT_ISR)
{
   /* Call QSPI0 Interrupt funtion */
   Spi_IsrQspiPt(SPI_QSPI0_INDEX);
}
#endif /* if (SRC_QSPI_QSPI0_PT_USED == STD_ON) */
#endif /* if ((SPI_QSPI0_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0)) */


/******************************************************************************/
/* !FuncName    : INT(SRC_QSPI_QSPI1_PT_ISR)                                  */
/* !Description : Service for Phase transition interrupt (PT2) used by QSPI1  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if ((SPI_QSPI1_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
#if (SRC_QSPI_QSPI1_PT_USED == STD_ON)
INT(SRC_QSPI_QSPI1_PT_ISR)
{
   /* Call QSPI0 Interrupt funtion */
   Spi_IsrQspiPt(SPI_QSPI1_INDEX);
}
#endif /* if (SRC_QSPI_QSPI1_PT_USED == STD_ON) */
#endif /* if ((SPI_QSPI1_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0)) */


/******************************************************************************/
/* !FuncName    : INT(SRC_QSPI_QSPI2_PT_ISR)                                  */
/* !Description : Service for Phase transition interrupt (PT2) used by QSPI2  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if ((SPI_QSPI2_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
#if (SRC_QSPI_QSPI2_PT_USED == STD_ON)
INT(SRC_QSPI_QSPI2_PT_ISR)
{
   /* Call QSPI2 Interrupt funtion */
   Spi_IsrQspiPt(SPI_QSPI2_INDEX);
}
#endif /* if (SRC_QSPI_QSPI2_PT_USED == STD_ON) */
#endif /* if ((SPI_QSPI2_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0)) */


/******************************************************************************/
/* !FuncName    : INT(SRC_QSPI_QSPI3_PT_ISR)                                  */
/* !Description : Service for Phase transition interrupt (PT2) used by QSPI3  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if ((SPI_QSPI3_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
#if (SRC_QSPI_QSPI3_PT_USED == STD_ON)
INT(SRC_QSPI_QSPI3_PT_ISR)
{
   /* Call QSPI3 Interrupt funtion */
   Spi_IsrQspiPt(SPI_QSPI3_INDEX);
}
#endif /* if (SRC_QSPI_QSPI3_PT_USED == STD_ON) */
#endif /* if ((SPI_QSPI3_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0)) */


/******************************************************************************/
/* !FuncName    : INT(SRC_QSPI_QSPI4_PT_ISR)                                  */
/* !Description : Service for Phase transition interrupt (PT2) used by QSPI4  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if ((SPI_QSPI4_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
#if (SRC_QSPI_QSPI4_PT_USED == STD_ON)
INT(SRC_QSPI_QSPI4_PT_ISR)
{
   /* Call QSPI4 Interrupt funtion */
   Spi_IsrQspiPt(SPI_QSPI4_INDEX);
}
#endif /* if (SRC_QSPI_QSPI4_PT_USED == STD_ON) */
#endif /* if ((SPI_QSPI4_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0)) */


/******************************************************************************/
/* !FuncName    : INT(SRC_QSPI_QSPI5_PT_ISR)                                  */
/* !Description : Service for Phase transition interrupt (PT2) used by QSPI5  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if ((SPI_QSPI5_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
#if (SRC_QSPI_QSPI5_PT_USED == STD_ON)
INT(SRC_QSPI_QSPI5_PT_ISR)
{
   /* Call QSPI5 Interrupt funtion */
   Spi_IsrQspiPt(SPI_QSPI5_INDEX);
}
#endif /* if (SRC_QSPI_QSPI5_PT_USED == STD_ON) */
#endif /* if ((SPI_QSPI5_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0)) */


/******************************************************************************/
/* !FuncName    : INT(SRC_QSPI_QSPI0_U_ISR)                                   */
/* !Description : Service for User interrupt (PT1) used by QSPI0              */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if ((SPI_QSPI0_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
#if (SRC_QSPI_QSPI0_U_USED == STD_ON)
INT(SRC_QSPI_QSPI0_U_ISR)
{
   /* Call QSPI3 Interrupt funtion */
   Spi_IsrQspiUsr(SPI_QSPI0_INDEX);
}
#endif /* if (SRC_QSPI_QSPI0_U_USED == STD_ON) */
#endif /* if ((SPI_QSPI0_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0)) */


/******************************************************************************/
/* !FuncName    : INT(SRC_QSPI_QSPI1_U_ISR)                                   */
/* !Description : Service for User interrupt (PT1) used by QSPI1              */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if ((SPI_QSPI1_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
#if (SRC_QSPI_QSPI1_U_USED == STD_ON)
INT(SRC_QSPI_QSPI1_U_ISR)
{
   /* Call QSPI3 Interrupt funtion */
   Spi_IsrQspiUsr(SPI_QSPI1_INDEX);
}
#endif /* if (SRC_QSPI_QSPI1_U_USED == STD_ON) */
#endif /* if ((SPI_QSPI1_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0)) */


/******************************************************************************/
/* !FuncName    : INT(SRC_QSPI_QSPI2_U_ISR)                                   */
/* !Description : Service for User interrupt (PT1) used by QSPI2              */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if ((SPI_QSPI2_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
#if (SRC_QSPI_QSPI2_U_USED == STD_ON)
INT(SRC_QSPI_QSPI2_U_ISR)
{
   /* Call QSPI3 Interrupt funtion */
   Spi_IsrQspiUsr(SPI_QSPI2_INDEX);
}
#endif /* if (SRC_QSPI_QSPI2_U_USED == STD_ON) */
#endif /* if ((SPI_QSPI2_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0)) */


/******************************************************************************/
/* !FuncName    : INT(SRC_QSPI_QSPI3_U_ISR)                                   */
/* !Description : Service for User interrupt (PT1) used by QSPI3              */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if ((SPI_QSPI3_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
#if (SRC_QSPI_QSPI3_U_USED == STD_ON)
INT(SRC_QSPI_QSPI3_U_ISR)
{
   /* Call QSPI3 Interrupt funtion */
   Spi_IsrQspiUsr(SPI_QSPI3_INDEX);
}
#endif /* if (SRC_QSPI_QSPI3_U_USED == STD_ON) */
#endif /* if ((SPI_QSPI3_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0)) */


/******************************************************************************/
/* !FuncName    : INT(SRC_QSPI_QSPI4_U_ISR)                                   */
/* !Description : Service for User interrupt (PT1) used by QSPI4              */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if ((SPI_QSPI4_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
#if (SRC_QSPI_QSPI4_U_USED == STD_ON)
INT(SRC_QSPI_QSPI4_U_ISR)
{
   /* Call QSPI4 Interrupt funtion */
   Spi_IsrQspiUsr(SPI_QSPI4_INDEX);
}
#endif /* if (SRC_QSPI_QSPI4_U_USED == STD_ON) */
#endif /* if ((SPI_QSPI4_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0)) */


/******************************************************************************/
/* !FuncName    : INT(SRC_QSPI_QSPI5_U_ISR)                                   */
/* !Description : Service for User interrupt (PT1) used by QSPI5              */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if ((SPI_QSPI5_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0))
#if (SRC_QSPI_QSPI5_U_USED == STD_ON)
INT(SRC_QSPI_QSPI5_U_ISR)
{
   /* Call QSPI5 Interrupt funtion */
   Spi_IsrQspiUsr(SPI_QSPI5_INDEX);
}
#endif /* if (SRC_QSPI_QSPI5_U_USED == STD_ON) */
#endif /* if ((SPI_QSPI5_USED == STD_ON) && (SPI_LEVEL_DELIVERED != 0)) */


/******************************************************************************/
/* !FuncName    : INT(DMA_ISR_QSPI0RX)                                        */
/* !Description : Service for Receive Dma channel interrupt used by QSPI0     */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (DMA_ISR_QSPI0RX_USED == STD_ON)
#if ((SPI_QSPI0_USED == ON) && (SPI_LEVEL_DELIVERED != 0))
INT(DMA_ISR_QSPI0RX)
{
   uint32 DmaErrorstatus;
   DmaErrorstatus  = Spi_IsrCheckDmaError(SPI_QSPI0_INDEX);

   if (DmaErrorstatus == 0u)
   {
      Spi_IsrDmaQspiRx(SPI_QSPI0_INDEX);
   }
   else
   {
      Spi_IsrDmaError(SPI_QSPI0_INDEX);
   }
}
#endif /* if ((SPI_QSPI0_USED == ON) && (SPI_LEVEL_DELIVERED != 0)) */
#endif /* if (DMA_ISR_QSPI0RX_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(DMA_ISR_QSPI1RX)                                        */
/* !Description : Service for Receive Dma channel interrupt used by QSPI1     */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (DMA_ISR_QSPI1RX_USED == STD_ON)
#if ((SPI_QSPI1_USED == ON) && (SPI_LEVEL_DELIVERED != 0))
INT(DMA_ISR_QSPI1RX)
{
   uint32 DmaErrorstatus;
   DmaErrorstatus  = Spi_IsrCheckDmaError(SPI_QSPI1_INDEX);

   if (DmaErrorstatus == 0u)
   {
      Spi_IsrDmaQspiRx(SPI_QSPI1_INDEX);
   }
   else
   {
      Spi_IsrDmaError(SPI_QSPI1_INDEX);
   }
}
#endif /* if ((SPI_QSPI1_USED == ON) && (SPI_LEVEL_DELIVERED != 0)) */
#endif /* if defined(DMA_ISR_QSPI1RX) */


/******************************************************************************/
/* !FuncName    : INT(DMA_ISR_QSPI2RX)                                        */
/* !Description : Service for Receive Dma channel interrupt used by QSPI2     */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (DMA_ISR_QSPI2RX_USED == STD_ON)
#if ((SPI_QSPI2_USED == ON) && (SPI_LEVEL_DELIVERED != 0))
INT(DMA_ISR_QSPI2RX)
{
   uint32 DmaErrorstatus;
   DmaErrorstatus  = Spi_IsrCheckDmaError(SPI_QSPI2_INDEX);

   if (DmaErrorstatus == 0u)
   {
      Spi_IsrDmaQspiRx(SPI_QSPI2_INDEX);
   }
   else
   {
      Spi_IsrDmaError(SPI_QSPI2_INDEX);
   }
}
#endif /* if ((SPI_QSPI2_USED == ON) && (SPI_LEVEL_DELIVERED != 0)) */
#endif /* if defined(DMA_ISR_QSPI2RX) */


/******************************************************************************/
/* !FuncName    : INT(DMA_ISR_QSPI3RX)                                        */
/* !Description : Service for Receive Dma channel interrupt used by QSPI3     */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (DMA_ISR_QSPI3RX_USED == STD_ON)
#if ((SPI_QSPI3_USED == ON) && (SPI_LEVEL_DELIVERED != 0))
INT(DMA_ISR_QSPI3RX)
{
   uint32 DmaErrorstatus;
   DmaErrorstatus  = Spi_IsrCheckDmaError(SPI_QSPI3_INDEX);

   if (DmaErrorstatus == 0u)
   {
      Spi_IsrDmaQspiRx(SPI_QSPI3_INDEX);
   }
   else
   {
      Spi_IsrDmaError(SPI_QSPI3_INDEX);
   }
}
#endif /* if ((SPI_QSPI3_USED == ON) && (SPI_LEVEL_DELIVERED != 0)) */
#endif /* if defined(DMA_ISR_QSPI3RX) */


/******************************************************************************/
/* !FuncName    : INT(DMA_ISR_QSPI4RX)                                        */
/* !Description : Service for Receive Dma channel interrupt used by QSPI4     */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (DMA_ISR_QSPI4RX_USED == STD_ON)
#if ((SPI_QSPI4_USED == ON) && (SPI_LEVEL_DELIVERED != 0))
INT(DMA_ISR_QSPI4RX)
{
   uint32 DmaErrorstatus;
   DmaErrorstatus  = Spi_IsrCheckDmaError(SPI_QSPI4_INDEX);

   if (DmaErrorstatus == 0u)
   {
      Spi_IsrDmaQspiRx(SPI_QSPI4_INDEX);
   }
   else
   {
      Spi_IsrDmaError(SPI_QSPI4_INDEX);
   }
}
#endif /* if ((SPI_QSPI4_USED == ON) && (SPI_LEVEL_DELIVERED != 0)) */
#endif /* if defined(DMA_ISR_QSPI4RX) */


/******************************************************************************/
/* !FuncName    : INT(DMA_ISR_QSPI5RX)                                        */
/* !Description : Service for Receive Dma channel interrupt used by QSPI5     */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (DMA_ISR_QSPI5RX_USED == STD_ON)
#if ((SPI_QSPI5_USED == ON) && (SPI_LEVEL_DELIVERED != 0))
INT(DMA_ISR_QSPI5RX)
{
   uint32 DmaErrorstatus;
   DmaErrorstatus  = Spi_IsrCheckDmaError(SPI_QSPI5_INDEX);

   if (DmaErrorstatus == 0u)
   {
      Spi_IsrDmaQspiRx(SPI_QSPI5_INDEX);
   }
   else
   {
      Spi_IsrDmaError(SPI_QSPI5_INDEX);
   }
}
#endif /* if ((SPI_QSPI5_USED == ON) && (SPI_LEVEL_DELIVERED != 0)) */
#endif /* if defined(DMA_ISR_QSPI5RX) */


/******************************************************************************/
/* !FuncName    : INT(DMA_ISR_QSPI0TX)                                        */
/* !Description : Service for Transmit Dma channel interrupt used by QSPI0    */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (DMA_ISR_QSPI0TX_USED == STD_ON)
#if ((SPI_QSPI0_USED == ON) && (SPI_LEVEL_DELIVERED != 0))
INT(DMA_ISR_QSPI0TX)
{
   uint32 DmaErrorstatus;
   DmaErrorstatus  = Spi_IsrCheckDmaError(SPI_QSPI0_INDEX);

   if (DmaErrorstatus == 0u)
   {
      Spi_IsrDmaQspiTx(SPI_QSPI0_INDEX);
   }
   else
   {
      Spi_IsrDmaError(SPI_QSPI0_INDEX);
   }
}
#endif /* if ((SPI_QSPI0_USED == ON) && (SPI_LEVEL_DELIVERED != 0)) */
#endif /* if defined(DMA_ISR_QSPI0TX) */


/******************************************************************************/
/* !FuncName    : INT(DMA_ISR_QSPI1TX)                                        */
/* !Description : Service for Transmit Dma channel interrupt used by QSPI1    */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (DMA_ISR_QSPI1TX_USED == STD_ON)
#if ((SPI_QSPI1_USED == ON) && (SPI_LEVEL_DELIVERED != 0))
INT(DMA_ISR_QSPI1TX)
{
   uint32 DmaErrorstatus;
   DmaErrorstatus  = Spi_IsrCheckDmaError(SPI_QSPI1_INDEX);

   if (DmaErrorstatus == 0u)
   {
      Spi_IsrDmaQspiTx(SPI_QSPI1_INDEX);
   }
   else
   {
      Spi_IsrDmaError(SPI_QSPI1_INDEX);
   }
}
#endif /* if ((SPI_QSPI1_USED == ON) && (SPI_LEVEL_DELIVERED != 0)) */
#endif /* if defined(DMA_ISR_QSPI1TX) */


/******************************************************************************/
/* !FuncName    : INT(DMA_ISR_QSPI2TX)                                        */
/* !Description : Service for Transmit Dma channel interrupt used by QSPI2    */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (DMA_ISR_QSPI2TX_USED == STD_ON)
#if ((SPI_QSPI2_USED == ON) && (SPI_LEVEL_DELIVERED != 0))
INT(DMA_ISR_QSPI2TX)
{
   uint32 DmaErrorstatus;
   DmaErrorstatus  = Spi_IsrCheckDmaError(SPI_QSPI2_INDEX);

   if (DmaErrorstatus == 0u)
   {
      Spi_IsrDmaQspiTx(SPI_QSPI2_INDEX);
   }
   else
   {
      Spi_IsrDmaError(SPI_QSPI2_INDEX);
   }
}
#endif /* if ((SPI_QSPI2_USED == ON) && (SPI_LEVEL_DELIVERED != 0)) */
#endif /* if defined(DMA_ISR_QSPI2TX) */


/******************************************************************************/
/* !FuncName    : INT(DMA_ISR_QSPI3TX)                                        */
/* !Description : Service for Transmit Dma channel interrupt used by QSPI3    */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (DMA_ISR_QSPI3TX_USED == STD_ON)
#if ((SPI_QSPI3_USED == ON) && (SPI_LEVEL_DELIVERED != 0))
INT(DMA_ISR_QSPI3TX)
{
   uint32 DmaErrorstatus;
   DmaErrorstatus  = Spi_IsrCheckDmaError(SPI_QSPI3_INDEX);

   if (DmaErrorstatus == 0u)
   {
      Spi_IsrDmaQspiTx(SPI_QSPI3_INDEX);
   }
   else
   {
      Spi_IsrDmaError(SPI_QSPI3_INDEX);
   }
}
#endif /* if ((SPI_QSPI3_USED == ON) && (SPI_LEVEL_DELIVERED != 0)) */
#endif /* if defined(DMA_ISR_QSPI3TX) */


/******************************************************************************/
/* !FuncName    : INT(DMA_ISR_QSPI4TX)                                        */
/* !Description : Service for Transmit Dma channel interrupt used by QSPI4    */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (DMA_ISR_QSPI4TX_USED == STD_ON)
#if ((SPI_QSPI4_USED == ON) && (SPI_LEVEL_DELIVERED != 0))
INT(DMA_ISR_QSPI4TX)
{
   uint32 DmaErrorstatus;
   DmaErrorstatus  = Spi_IsrCheckDmaError(SPI_QSPI4_INDEX);

   if (DmaErrorstatus == 0u)
   {
      Spi_IsrDmaQspiTx(SPI_QSPI4_INDEX);
   }
   else
   {
      Spi_IsrDmaError(SPI_QSPI4_INDEX);
   }
}
#endif /* if ((SPI_QSPI4_USED == ON) && (SPI_LEVEL_DELIVERED != 0)) */
#endif /* if defined(DMA_ISR_QSPI4TX) */


/******************************************************************************/
/* !FuncName    : INT(DMA_ISR_QSPI5TX)                                        */
/* !Description : Service for Transmit Dma channel interrupt used by QSPI5    */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (DMA_ISR_QSPI5TX_USED == STD_ON)
#if ((SPI_QSPI5_USED == ON) && (SPI_LEVEL_DELIVERED != 0))
INT(DMA_ISR_QSPI5TX)
{
   uint32 DmaErrorstatus;
   DmaErrorstatus  = Spi_IsrCheckDmaError(SPI_QSPI5_INDEX);

   if (DmaErrorstatus == 0u)
   {
      Spi_IsrDmaQspiTx(SPI_QSPI5_INDEX);
   }
   else
   {
      Spi_IsrDmaError(SPI_QSPI5_INDEX);
   }
}
#endif /* if ((SPI_QSPI5_USED == ON) && (SPI_LEVEL_DELIVERED != 0)) */
#endif /* if defined(DMA_ISR_QSPI5TX) */


#define ISR_STOP_SEC_CODE
#include "ISR_MemMap.h"

/*-------------------------------- END OF FILE -------------------------------*/
