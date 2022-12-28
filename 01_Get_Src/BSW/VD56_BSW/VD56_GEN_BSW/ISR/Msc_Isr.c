/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : ISR                                                     */
/* !Description     : ISR Management                                          */
/*                                                                            */
/* !File            : Msc_Isr.c                                               */
/* !Description     : ISR definition of Msc component                         */
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
 * %PID: P2017_BSW:0A192578.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Isr_Cfg.h"
#include "Msc.h"
#include "Os.h"

/******************************************************************************/
/* !Comment: INT linked to SRC_MSC_MSCx_SRy (x = 0..2) (y = 0..4)             */
/******************************************************************************/

#define ISR_START_SEC_CODE
#include "ISR_MemMap.h"

/******************************************************************************/
/* !FuncName    : INT(SRC_MSC_MSC0_SR0_ISR)                                   */
/* !Description : Interrupts linked to SRC_MSC_MSC0_SR0                       */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_MSC_MSC0_SR0_USED == STD_ON)
INT(SRC_MSC_MSC0_SR0_ISR)
{
   /* Parameters are MSC Module Number and Service Request Number */
   Msc_InterruptHandler(0,0);
}
#endif /* if (SRC_MSC_MSC0_SR0_USED == STD_ON) */

/******************************************************************************/
/* !FuncName    : INT(SRC_MSC_MSC0_SR1_ISR)                                   */
/* !Description : Interrupts linked to SRC_MSC_MSC0_SR1                       */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_MSC_MSC0_SR1_USED == STD_ON)
INT(SRC_MSC_MSC0_SR1_ISR)
{
   /* Parameters are MSC Module Number and Service Request Number */
   Msc_InterruptHandler(0,1);
}
#endif /* if (SRC_MSC_MSC0_SR1_USED == STD_ON) */

/******************************************************************************/
/* !FuncName    : INT(SRC_MSC_MSC0_SR2_ISR)                                   */
/* !Description : Interrupts linked to SRC_MSC_MSC0_SR2                       */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_MSC_MSC0_SR2_USED == STD_ON)
INT(SRC_MSC_MSC0_SR2_ISR)
{
   /* Parameters are MSC Module Number and Service Request Number */
   Msc_InterruptHandler(0,2);
}
#endif /* if (SRC_MSC_MSC0_SR2_USED == STD_ON) */

/******************************************************************************/
/* !FuncName    : INT(SRC_MSC_MSC0_SR3_ISR)                                   */
/* !Description : Interrupts linked to SRC_MSC_MSC0_SR3                       */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_MSC_MSC0_SR3_USED == STD_ON)
INT(SRC_MSC_MSC0_SR3_ISR)
{
   /* Parameters are MSC Module Number and Service Request Number */
   Msc_InterruptHandler(0,3);
}
#endif /* if (SRC_MSC_MSC0_SR3_USED == STD_ON) */

/******************************************************************************/
/* !FuncName    : INT(SRC_MSC_MSC0_SR4_ISR)                                   */
/* !Description : Interrupts linked to SRC_MSC_MSC0_SR4                       */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_MSC_MSC0_SR4_USED == STD_ON)
extern void Msc_Interrupt_HandlerMSC0_SR4(void);
INT(SRC_MSC_MSC0_SR4_ISR)
{
   Msc_Interrupt_HandlerMSC0_SR4();
}
#endif /* if (SRC_MSC_MSC0_SR4_USED == STD_ON) */

/******************************************************************************/
/* !FuncName    : INT(DMA_ISR_MSC0RX)                                         */
/* !Description : Service for Receive Dma channel interrupt used by MSC0      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (DMA_ISR_MSC0RX_USED == STD_ON)
extern void Msc_Interrupt_HandlerMSC0RxFrame(void);
INT(DMA_ISR_MSC0RX)
{
   Msc_Interrupt_HandlerMSC0RxFrame();
}
#endif /* if  (DMA_ISR_MSC0RX_USED == STD_ON) */

/******************************************************************************/
/* !FuncName    : INT(SRC_MSC_MSC1_SR0_ISR)                                   */
/* !Description : Interrupts linked to SRC_MSC_MSC1_SR0                       */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_MSC_MSC1_SR0_USED == STD_ON)
INT(SRC_MSC_MSC1_SR0_ISR)
{
   /* Parameters are MSC Module Number and Service Request Number */
   Msc_InterruptHandler(1,0);
}
#endif /* if (SRC_MSC_MSC1_SR0_USED == STD_ON) */

/******************************************************************************/
/* !FuncName    : INT(SRC_MSC_MSC1_SR1_ISR)                                   */
/* !Description : Interrupts linked to SRC_MSC_MSC1_SR1                       */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_MSC_MSC1_SR1_USED == STD_ON)
INT(SRC_MSC_MSC1_SR1_ISR)
{
   /* Parameters are MSC Module Number and Service Request Number */
   Msc_InterruptHandler(1,1);
}
#endif /* if (SRC_MSC_MSC1_SR1_USED == STD_ON) */

/******************************************************************************/
/* !FuncName    : INT(SRC_MSC_MSC1_SR2_ISR)                                   */
/* !Description : Interrupts linked to SRC_MSC_MSC1_SR2                       */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_MSC_MSC1_SR2_USED == STD_ON)
INT(SRC_MSC_MSC1_SR2_ISR)
{
   /* Parameters are MSC Module Number and Service Request Number */
   Msc_InterruptHandler(1,2);
}
#endif /* if (SRC_MSC_MSC1_SR2_USED == STD_ON) */

/******************************************************************************/
/* !FuncName    : INT(SRC_MSC_MSC1_SR3_ISR)                                   */
/* !Description : Interrupts linked to SRC_MSC_MSC1_SR3                       */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_MSC_MSC1_SR3_USED == STD_ON)
INT(SRC_MSC_MSC1_SR3_ISR)
{
   /* Parameters are MSC Module Number and Service Request Number */
   Msc_InterruptHandler(1,3);
}
#endif /* if (SRC_MSC_MSC1_SR3_USED == STD_ON) */

/******************************************************************************/
/* !FuncName    : INT(SRC_MSC_MSC1_SR4_ISR)                                   */
/* !Description : Interrupts linked to SRC_MSC_MSC1_SR4                       */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_MSC_MSC1_SR4_USED == STD_ON)
extern void Msc_Interrupt_HandlerMSC1_SR4(void);
INT(SRC_MSC_MSC1_SR4_ISR)
{
   Msc_Interrupt_HandlerMSC1_SR4();
}
#endif /* if (SRC_MSC_MSC1_SR4_USED == STD_ON) */

/******************************************************************************/
/* !FuncName    : INT(DMA_ISR_MSC1RX)                                         */
/* !Description : Service for Receive Dma channel interrupt used by MSC1      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (DMA_ISR_MSC1RX_USED == STD_ON)
extern void Msc_Interrupt_HandlerMSC1RxFrame(void);
INT(DMA_ISR_MSC1RX)
{
   Msc_Interrupt_HandlerMSC1RxFrame();
}
#endif /* if  (DMA_ISR_MSC1RX_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_MSC_MSC2_SR0_ISR)                                   */
/* !Description : Interrupts linked to SRC_MSC_MSC2_SR0                       */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_MSC_MSC2_SR0_USED == STD_ON)
INT(SRC_MSC_MSC2_SR0_ISR)
{
   /* Parameters are MSC Module Number and Service Request Number */
   Msc_InterruptHandler(2,0);
}
#endif /* if (SRC_MSC_MSC2_SR0_USED == STD_ON) */

/******************************************************************************/
/* !FuncName    : INT(SRC_MSC_MSC2_SR1_ISR)                                   */
/* !Description : Interrupts linked to SRC_MSC_MSC2_SR1                       */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_MSC_MSC2_SR1_USED == STD_ON)
INT(SRC_MSC_MSC2_SR1_ISR)
{
   /* Parameters are MSC Module Number and Service Request Number */
   Msc_InterruptHandler(2,1);
}
#endif /* if (SRC_MSC_MSC2_SR1_USED == STD_ON) */

/******************************************************************************/
/* !FuncName    : INT(SRC_MSC_MSC2_SR2_ISR)                                   */
/* !Description : Interrupts linked to SRC_MSC_MSC2_SR2                       */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_MSC_MSC2_SR2_USED == STD_ON)
INT(SRC_MSC_MSC2_SR2_ISR)
{
   /* Parameters are MSC Module Number and Service Request Number */
   Msc_InterruptHandler(2,2);
}
#endif /* if (SRC_MSC_MSC2_SR2_USED == STD_ON) */

/******************************************************************************/
/* !FuncName    : INT(SRC_MSC_MSC2_SR3_ISR)                                   */
/* !Description : Interrupts linked to SRC_MSC_MSC2_SR3                       */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_MSC_MSC2_SR3_USED == STD_ON)
INT(SRC_MSC_MSC2_SR3_ISR)
{
   /* Parameters are MSC Module Number and Service Request Number */
   Msc_InterruptHandler(2,3);
}
#endif /* if (SRC_MSC_MSC2_SR3_USED == STD_ON) */

/******************************************************************************/
/* !FuncName    : INT(SRC_MSC_MSC2_SR4_ISR)                                   */
/* !Description : Interrupts linked to SRC_MSC_MSC2_SR4                       */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_MSC_MSC2_SR4_USED == STD_ON)
extern void Msc_Interrupt_HandlerMSC2_SR4(void);
INT(SRC_MSC_MSC2_SR4_ISR)
{
   Msc_Interrupt_HandlerMSC2_SR4();
}
#endif /* if (SRC_MSC_MSC2_SR4_USED == STD_ON) */

/******************************************************************************/
/* !FuncName    : INT(DMA_ISR_MSC2RX)                                         */
/* !Description : Service for Receive Dma channel interrupt used by MSC2      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (DMA_ISR_MSC2RX_USED == STD_ON)
extern void Msc_Interrupt_HandlerMSC2RxFrame(void);
INT(DMA_ISR_MSC2RX)
{
   Msc_Interrupt_HandlerMSC2RxFrame();
}
#endif /* if  (DMA_ISR_MSC2RX_USED == STD_ON) */


#define ISR_STOP_SEC_CODE
#include "ISR_MemMap.h"

/*-------------------------------- END OF FILE -------------------------------*/
