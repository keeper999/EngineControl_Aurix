/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Component       : Det                                                     */
/* !Description     : AutoSAR BASIS DET Module                                */
/*                                                                            */
/* !Module          : Det                                                     */
/* !Description     : DET Module                                              */
/*                                                                            */
/* !File            : Det_Types.h                                             */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/*                                                                            */
/* COPYRIGHT 2006 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.2  R2.2.0  AR 3.0.0                                         */
/* Done by    : A.Metwelly                                     Date : 5/06/12 */
/* Description: Updated software version.                 						*/
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.1  R2.1.0  AR 3.0.0                                         */
/* Done by    : M.Hegazy                                      Date : 11/03/12 */
/* Description: Updated software version in modification log.                 */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.0  R2.0.0  AR 3.0.0                                         */
/* Done by    : H.Salem                                      Date : 27/12/09  */
/* Description: Added R & AR to modifucation log                              */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 0.4                                                           */
/* Done by    : M. Assem Gawdat                              Date : 18/10/07  */
/* Description: Changes due to Rework points ISS-DET-10,13,38,9,24,25,32      */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by           */
/*              configuration management tool (PVCS)                          */
/* PRQA S 0288 ++                                                             */
/* PVCS Information                                                          
   $Header:   I:/PROJETS/LIBEMB/LOG/SRV/DET/LOG/Det_Types.h_v   1.0   06 Aug 2012 15:31:30   lvoilmy  $
*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/


#ifndef Det_TYPES_H
#define Det_TYPES_H

/* !Trace_To: GSCSW-DET-SDD-001-0022                                          */
#include "Std_Types.h"

/******************************************************************************/
/* Symbol definitions                                                         */
/******************************************************************************/


/******************************************************************************/
/* !Comment         : Type of DET implementation                              */
/* !Range           : DET_NONE, DET_RAM, DET_COM                                          */
/* !Trace_To        : GSCSW-DET-SDD-001-0015                                  */
/******************************************************************************/
#define DET_NONE 11U
#define DET_RAM  12U
#define DET_COM  13U

/******************************************************************************/
/* !Comment         : Type of callback implementation                         */
/* !Range           : DET_CBK_DIRECT, DET_CBK_MAIN, STD_OFF                           */
/* !Trace_To        : GSCSW-DET-SDD-001-0015                                  */
/******************************************************************************/
#define DET_CBK_DIRECT 11U
#define DET_CBK_MAIN   12U


/******************************************************************************/
/* !Comment         : Type of error management                                */
/* !Range           : DET_FIFO_TYPE, DET_STACK_TYPE                                   */
/* !Trace_To        : GSCSW-DET-SDD-001-0017                                  */
/******************************************************************************/
#define DET_FIFO_TYPE  11U
#define DET_STACK_TYPE 12U




#endif /* Det_TYPES_H*/
