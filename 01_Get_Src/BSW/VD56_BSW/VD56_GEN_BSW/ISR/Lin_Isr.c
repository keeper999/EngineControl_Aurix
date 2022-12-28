/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : ISR                                                     */
/* !Description     : ISR Management                                          */
/*                                                                            */
/* !File            : Lin_Isr.c                                               */
/* !Description     : ISR definition of Lin component                         */
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
 * %PID: P2017_BSW:0A192569.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

/******************************************************************************/
/* !Comment: INT are not defined for following SRCs:                          */
/*           SRC_ASCLIN_ASCLINx_TX(Rx or ERR)_ISR (x = 0..3),                 */
/*           For each AUTOSAR LIN channel, LIN_ASCLINx_USED shall be          */
/*           configured                                                       */
/******************************************************************************/

#include "Std_Types.h"
#include "Isr_Cfg.h"
#include "Lin_17_AscLin.h"
#include "Os.h"


#define ISR_START_SEC_CODE
#include "ISR_MemMap.h"

/******************************************************************************/
/* !FuncName    : INT(SRC_ASCLIN_ASCLIN0_TX_ISR)                              */
/* !Description : INT managing LIN Tx IT linked to SRC_ASCLIN_ASCLIN0_TX      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_ASCLIN_ASCLIN0_TX_USED == STD_ON)
INT(SRC_ASCLIN_ASCLIN0_TX_ISR)
{
   /* Call TX Interrupt funtion */
   #if (LIN_ASCLIN0_USED == STD_ON)
   Lin_17_AscLin_IsrTransmit(LIN_ASCLIN0);
   #endif /* if (LIN_ASCLIN0_USED == STD_ON) */
}
#endif /* if (LIN_ASCLIN0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_ASCLIN_ASCLIN1_TX_ISR)                              */
/* !Description : INT managing LIN Tx IT linked to SRC_ASCLIN_ASCLIN1_TX      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_ASCLIN_ASCLIN1_TX_USED == STD_ON)
INT(SRC_ASCLIN_ASCLIN1_TX_ISR)
{
   /* Call TX Interrupt funtion */
   #if (LIN_ASCLIN1_USED == STD_ON)
   Lin_17_AscLin_IsrTransmit(LIN_ASCLIN1);
   #endif /* if (LIN_ASCLIN1_USED == STD_ON) */
}
#endif /* if (LIN_ASCLIN1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_ASCLIN_ASCLIN2_TX_ISR)                              */
/* !Description : INT managing LIN Tx IT linked to SRC_ASCLIN_ASCLIN2_TX      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_ASCLIN_ASCLIN2_TX_USED == STD_ON)
INT(SRC_ASCLIN_ASCLIN2_TX_ISR)
{
   /* Call TX Interrupt funtion */
   #if (LIN_ASCLIN2_USED == STD_ON)
   Lin_17_AscLin_IsrTransmit(LIN_ASCLIN2);
   #endif /* if (LIN_ASCLIN2_USED == STD_ON) */
}
#endif /* if (LIN_ASCLIN2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_ASCLIN_ASCLIN3_TX_ISR)                              */
/* !Description : INT managing LIN Tx IT linked to SRC_ASCLIN_ASCLIN3_TX      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_ASCLIN_ASCLIN3_TX_USED == STD_ON)
INT(SRC_ASCLIN_ASCLIN3_TX_ISR)
{
   /* Call TX Interrupt funtion */
   #if (LIN_ASCLIN3_USED == STD_ON)
   Lin_17_AscLin_IsrTransmit(LIN_ASCLIN3);
   #endif /* if (LIN_ASCLIN3_USED == STD_ON) */
}
#endif /* if (LIN_ASCLIN3_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_ASCLIN_ASCLIN0_RX_ISR)                              */
/* !Description : INT managing LIN Rx IT linked to SRC_ASCLIN_ASCLIN0_RX      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_ASCLIN_ASCLIN0_RX_USED == STD_ON)
INT(SRC_ASCLIN_ASCLIN0_RX_ISR)
{
   /* Call RX Interrupt funtion */
   #if (LIN_ASCLIN0_USED == STD_ON)
   Lin_17_AscLin_IsrReceive(LIN_ASCLIN0);
   #endif /* if (LIN_ASCLIN0_USED == STD_ON) */
}
#endif /* if (LIN_ASCLIN0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_ASCLIN_ASCLIN1_RX_ISR)                              */
/* !Description : INT managing LIN Rx IT linked to SRC_ASCLIN_ASCLIN1_RX      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_ASCLIN_ASCLIN1_RX_USED == STD_ON)
INT(SRC_ASCLIN_ASCLIN1_RX_ISR)
{
   /* Call RX Interrupt funtion */
   #if (LIN_ASCLIN1_USED == STD_ON)
   Lin_17_AscLin_IsrReceive(LIN_ASCLIN1);
   #endif /* if (LIN_ASCLIN1_USED == STD_ON) */
}
#endif /* if (LIN_ASCLIN1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_ASCLIN_ASCLIN2_RX_ISR)                              */
/* !Description : INT managing LIN Rx IT linked to SRC_ASCLIN_ASCLIN2_RX      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_ASCLIN_ASCLIN2_RX_USED == STD_ON)
INT(SRC_ASCLIN_ASCLIN2_RX_ISR)
{
   /* Call RX Interrupt funtion */
   #if (LIN_ASCLIN2_USED == STD_ON)
   Lin_17_AscLin_IsrReceive(LIN_ASCLIN2);
   #endif /* if (LIN_ASCLIN2_USED == STD_ON) */
}
#endif /* if (LIN_ASCLIN2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_ASCLIN_ASCLIN3_RX_ISR)                              */
/* !Description : INT managing LIN Rx IT linked to SRC_ASCLIN_ASCLIN3_RX      */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_ASCLIN_ASCLIN3_RX_USED == STD_ON)
INT(SRC_ASCLIN_ASCLIN3_RX_ISR)
{
   /* Call RX Interrupt funtion */
   #if (LIN_ASCLIN3_USED == STD_ON)
   Lin_17_AscLin_IsrReceive(LIN_ASCLIN3);
   #endif /* if (LIN_ASCLIN3_USED == STD_ON) */
}
#endif /* if (LIN_ASCLIN3_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_ASCLIN_ASCLIN0_ERR_ISR)                             */
/* !Description : INT managing LIN Error IT linked to SRC_ASCLIN_ASCLIN0_ERR  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_ASCLIN_ASCLIN0_ERR_USED == STD_ON)
INT(SRC_ASCLIN_ASCLIN0_ERR_ISR)
{
   /* Call the Error INT */
   #if (LIN_ASCLIN0_USED == STD_ON)
   Lin_17_AscLin_IsrError(LIN_ASCLIN0);
   #endif /* if (LIN_ASCLIN0_USED == STD_ON) */
}
#endif /* if (LIN_ASCLIN0_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_ASCLIN_ASCLIN1_ERR_ISR)                             */
/* !Description : INT managing LIN Error IT linked to SRC_ASCLIN_ASCLIN1_ERR  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_ASCLIN_ASCLIN1_ERR_USED == STD_ON)
INT(SRC_ASCLIN_ASCLIN1_ERR_ISR)
{
   /* Call the Error INT */
   #if (LIN_ASCLIN1_USED == STD_ON)
   Lin_17_AscLin_IsrError(LIN_ASCLIN1);
   #endif /* if (LIN_ASCLIN1_USED == STD_ON) */
}
#endif /* if (LIN_ASCLIN1_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_ASCLIN_ASCLIN2_ERR_ISR)                             */
/* !Description : INT managing LIN Error IT linked to SRC_ASCLIN_ASCLIN2_ERR  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_ASCLIN_ASCLIN2_ERR_USED == STD_ON)
INT(SRC_ASCLIN_ASCLIN2_ERR_ISR)
{
   /* Call the Error INT */
   #if (LIN_ASCLIN2_USED == STD_ON)
   Lin_17_AscLin_IsrError(LIN_ASCLIN2);
   #endif /* if (LIN_ASCLIN2_USED == STD_ON) */
}
#endif /* if (LIN_ASCLIN2_USED == STD_ON) */


/******************************************************************************/
/* !FuncName    : INT(SRC_ASCLIN_ASCLIN3_ERR_ISR)                             */
/* !Description : INT managing LIN Error IT linked to SRC_ASCLIN_ASCLIN3_ERR  */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#if (SRC_ASCLIN_ASCLIN3_ERR_USED == STD_ON)
INT(SRC_ASCLIN_ASCLIN3_ERR_ISR)
{
   /* Call the Error INT */
   #if (LIN_ASCLIN3_USED == STD_ON)
   Lin_17_AscLin_IsrError(LIN_ASCLIN3);
   #endif /* if (LIN_ASCLIN3_USED == STD_ON) */
}
#endif /* if (LIN_ASCLIN3_USED == STD_ON) */


#define ISR_STOP_SEC_CODE
#include "ISR_MemMap.h"

/*-------------------------------- END OF FILE -------------------------------*/
