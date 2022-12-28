/************************************************* <AUTO_FILE_HEADER> *************************************************/
/*                                                                                                                    */
/* !Layer           : SRVL                                                                                            */
/*                                                                                                                    */
/* !Component       : CCP                                                                                             */
/*                                                                                                                    */
/* !Module          : CCPUSR                                                                                          */
/* !Description     : User functions declaration                                                                      */
/*                                                                                                                    */
/* !File            : CCPUSR_Daq.h                                                                                    */
/*                                                                                                                    */
/* !Scope           : Public                                                                                          */
/*                                                                                                                    */
/* !Target          : All                                                                                             */
/*                                                                                                                    */
/* !Vendor          : Valeo                                                                                           */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT 2009 VALEO                                                                                               */
/* all rights reserved                                                                                                */
/*                                                                                                                    */
/**********************************************************************************************************************/
/************************************************ </AUTO_FILE_HEADER> *************************************************/
/* PVCS Information                                                                                                   */
/* $Archive::   P:/VE_S97/LOG/60_ComponentArchive/Archives/COMP_SWC_BSW_MCAL_MPC5676/Mcal.c_v                        $*/
/* $Revision::   1.7                                                                                                 $*/
/* $Author::   vbecquet                               $$Date::   14 Jun 2012 13:43:52                                $*/
/**********************************************************************************************************************/

#ifndef CCPUSR_DAQ_H
#define CCPUSR_DAQ_H

/**********************************************************************************************************************/
/* FUNCTIONS DECLARATION                                                                                              */
/**********************************************************************************************************************/
#define CCP_START_SEC_CODE
#include "Ccp_MemMap.h"

#if (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD)
   FUNC(void, CCP_USR_CODE) CCPUSR_vidDaqListIni(void);
#endif /* (CCP_coOPT_SRV_DAQ_LIST == CCP_coACVD) */

#define CCP_STOP_SEC_CODE
#include "Ccp_MemMap.h"

#endif /* CCPUSR_DAQ_H */

/*---------------------------------------------------- end of file ---------------------------------------------------*/
