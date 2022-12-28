/******************************************************************************/
/* !Layer           : SRVL                                                    */
/* !Component       : RSTSRV                                                  */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : RSTSRV_1.c                                              */
/* !Description     : Internal functions of RSTSRV Component                  */
/*                                                                            */
/* !Reference       : V03 NT 07 02929                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:A255.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "NvM.h"
#include "NvMIf.h"
#include "RSTSRV.h"
#include "RSTSRV_Private.h"
#include "SWFAIL.h"



#define RSTSRV_START_SEC_CODE
#include "RSTSRV_MemMap.h"

/******************************************************************************/
/* !FuncName    : RSTSRV_vidInitEntry                                         */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void RSTSRV_vidInitEntry(void)
{
   uint32 M2C_uint32_1;

   M2C_uint32_1 = 1u + ((uint32)RSTSRV_u16HotResetCtr);
   if (M2C_uint32_1 > 65535u)
   {
      M2C_uint32_1 = 65535u;
   }
   RSTSRV_u16HotResetCtr = (uint16)M2C_uint32_1;

   /* Equivalent to a Write Now */
   (void)NvM_WritePRAMBlock(NvM_BSW_BLOCK_RESET);
}

/******************************************************************************/
/* !FuncName    : RSTSRV_vidPowerDownEntry                                    */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void RSTSRV_vidPowerDownEntry(void)
{

   RSTSRV_u16HotResetCtr = UINT16_MIN;
}

/******************************************************************************/
/* !FuncName    : RSTSRV_vidPowerOnResetEntry                                 */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void RSTSRV_vidPowerOnResetEntry(RSTSRV_tudtResetType udtResetType)
{

   if (udtResetType == RSTSRV_udtSOFTWARE_RESET)
   {
      RSTSRV_bSWResetDetected = TRUE;
   }
   else
   {
      RSTSRV_bSWResetDetected = FALSE;
   }
}

#define RSTSRV_STOP_SEC_CODE
#include "RSTSRV_MemMap.h"

/*------------------------------- end of file --------------------------------*/
