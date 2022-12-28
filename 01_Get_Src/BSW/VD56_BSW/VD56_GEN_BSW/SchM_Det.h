/******************************************************************************/
/* !Layer           : SRV                                                     */
/* !Component       : SchM                                                    */
/* !Description     : AutoSAR BASIS SchM Module                               */
/*                                                                            */
/* !File            : SchM_Det.h                                              */
/* !Description     : Scheduler module configuration to manage DET Component  */
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
 * %PID: P2017_BSW:0A192534.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef SchM_DET_H
#define SchM_DET_H

#include "KRN.h"
#include "Os.h"

/******************************************************************************/
/* Symbol definitions                                                         */
/******************************************************************************/

/******************************************************************************/
/* !Comment         : DET critical section constant to protect the RAM buffer */
/*                    variables                                               */
/* !Trace_To        : GSCSW-DET-SDD-001-0032, GSCSW-DET-SDD-001-0034          */
/******************************************************************************/
#define DET_ACCESS_001


/******************************************************************************/
/* !Comment         : DET critical section constant to protect LOC_strErrorBuf*/
/*                    in Det_ReportError                                      */
/* !Trace_To        : GSCSW-DET-SDD-001-0032, GSCSW-DET-SDD-001-0034          */
/******************************************************************************/
#define DET_ACCESS_002

/******************************************************************************/
/* !Comment         : DET enter critical section macro                        */
/* !Trace_To        : GSCSW-DET-SDD-001-0032, GSCSW-DET-SDD-001-0034          */
/******************************************************************************/
#define SchM_Enter_Det(RegionName)   SCHM_ENTER_DET_##RegionName()

/******************************************************************************/
/* !Comment         : DET leave critical section macro                        */
/* !Trace_To        : GSCSW-DET-SDD-001-0032, GSCSW-DET-SDD-001-0034          */
/******************************************************************************/
#define SchM_Exit_Det(RegionName)    SCHM_EXIT_DET_##RegionName()


/******************************************************************************/
/* !Comment         : DET enter critical section macro to protect the RAM     */
/*                    buffer variables                                        */
/* !Trace_To        : GSCSW-DET-SDD-001-0032, GSCSW-DET-SDD-001-0034          */
/******************************************************************************/
#define SCHM_ENTER_DET_DET_ACCESS_001() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      DisableAllInterrupts(); \
   } \
} \
while (0)


/******************************************************************************/
/* !Comment         : DET leave critical section macro to protect the RAM     */
/*                    buffer variables                                        */
/* !Trace_To        : GSCSW-DET-SDD-001-0032, GSCSW-DET-SDD-001-0034          */
/******************************************************************************/
#define SCHM_EXIT_DET_DET_ACCESS_001() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      EnableAllInterrupts(); \
   } \
} \
while (0)


/******************************************************************************/
/* !Comment         : DET enter critical section macro to protect             */
/*                    LOC_strErrorBuf in Det_ReportError                      */
/* !Trace_To        : GSCSW-DET-SDD-001-0032, GSCSW-DET-SDD-001-0034          */
/******************************************************************************/
#define SCHM_ENTER_DET_DET_ACCESS_002() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      DisableAllInterrupts(); \
   } \
} \
while (0)


/******************************************************************************/
/* !Comment         : DET leave critical section macro to protect             */
/*                    LOC_strErrorBuf in Det_ReportError                      */
/* !Trace_To        : GSCSW-DET-SDD-001-0032, GSCSW-DET-SDD-001-0034          */
/******************************************************************************/
#define SCHM_EXIT_DET_DET_ACCESS_002() \
do \
{ \
   if (KRN_bReadOsAccessAuthorized() != FALSE) \
   { \
      EnableAllInterrupts(); \
   } \
} \
while (0)


#endif /* SchM_DET_H */

