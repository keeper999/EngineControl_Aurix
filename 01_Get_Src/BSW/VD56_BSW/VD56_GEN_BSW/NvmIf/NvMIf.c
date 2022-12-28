/******************************************************************************/
/* !Layer           : SRVL                                                    */
/* !Component       : NvMIf                                                   */
/* !Description     : NVM interface between ASW and NvM stack                 */
/*                                                                            */
/* !File            : NvMIf.c                                                 */
/* !Description     : main source file                                        */
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
 * %PID: P2017_BSW:0A167737.A-SRC;3 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Fee.h"
#include "Fls.h"
#include "NvM.h"
#include "NvMIf.h"
#include "IfxStm.h"


#define NVMIF_START_SEC_CODE
#include "NVMIF_MemMap.h"

/******************************************************************************/
/* !FuncName    : NvMIf_vidInit                                               */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : L.Voilmy                                                    */
/******************************************************************************/
void NvMIf_vidInit(void)
{
   NvM_RequestResultType udtLocStatus;
   uint32                u32TimeStart;
   uint32                u32TimeMeas;

   Fls_17_Pmu_Init(&Fls_17_Pmu_ConfigRoot[0]);
   Fee_Init();
   NvM_Init();

   u32TimeStart = (uint32)IfxStm_getLower(&MODULE_STM0);
   NvM_ReadAll();
   do
   {
      NvM_MainFunction();
      Fee_MainFunction();
      Fls_17_Pmu_MainFunction();
      (void)NvM_GetErrorStatus(0, &udtLocStatus);
   } while(udtLocStatus == NVM_REQ_PENDING);
   u32TimeMeas = (uint32)( IfxStm_getLower(&MODULE_STM0) - u32TimeStart);
   u32TimeMeas = u32TimeMeas / 100; /* duration in µs */
   
   if(u32TimeMeas > NvmIf_u32NvMInitDuration_us)
   {
      NvmIf_u32NvMInitDuration_us = u32TimeMeas;
      (void)NvM_WritePRAMBlock(NvM_BSW_BLOCK_MEAS);
   }
}

/******************************************************************************/
/* !FuncName    : NvMIf_vidWriteAll                                           */
/* !Description :                                                             */
/*                                                                            */
/* !LastAuthor  : L.Voilmy                                                    */
/******************************************************************************/
void NvMIf_vidWriteAll(void)
{
   NvM_BlockIdType       udtBlockId;

   /* Set all Block to be saved by NvM_WriteAll                               */
   /* Be careful, only block configured with NvMSelectBlockForWriteAll = TRUE */
   for(udtBlockId = 1; udtBlockId <= NVM_udtNUM_OF_NVRAM_BLOCKS; udtBlockId++)
   {
      NvM_SetRamBlockStatus(udtBlockId, TRUE);
   }
   NvM_WriteAll();
}

#define NVMIF_STOP_SEC_CODE
#include "NVMIF_MemMap.h"

/*------------------------------ end of file ---------------------------------*/
