
/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : Dsp                                                     */
/* !Description     : Diagnostic services processing                          */
/*                                                                            */
/* !Module          : Dcm_Dsp_DataServices                                    */
/* !Description     : DataServices automatically generated code               */
/*                                                                            */
/* !File            : Dcm_Dsp_DataServices.c                                  */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2011 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* PRQA S 0292 ++                                                             */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/DCM_CONFIG/DCM_GEN/Dcm_Dsp_DataS$*/
/* $Revision::   1.15     $$Author::   pbakabad       $$Date::   Mar 11 2013 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/



    
#include "Std_Types.h"
/* !Deviation : Inhibit MISRA rule [0838]: because the memmap file is used    */
/*              for memory allocation and should be included several times.   */
/* PRQA S 5087,0838 L1 */
#include "Dcm.h"
#include "Dcm_Internal.h"
/* PRQA L:L1 */
#include "Rte_Dcm.h"
#include "IoHwAb.h"


/* !Deviation : Inhibit MISRA rule [0310]: Casting to different object pointer
                type is needed to convert the input buffer type to match Rte
                API signature.   */
/* PRQA S 0310,3305 L1 */




        
/* PRQA L:L1 */
