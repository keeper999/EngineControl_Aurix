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
/* !File            : Det.c                                                   */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2006 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.12     R2.2.0     AR3.0.0                                    */
/* Done by    : A.metwelly                                      Date : 5/06/12 */
/* Description: - Updated software version                             */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.11     R2.1.0     AR3.0.0                                    */
/* Done by    : M.Hegazy                                      Date : 11/03/12 */
/* Description: - Updated software version in modification log.               */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.10     R2.0.2     AR3.0.0                                    */
/* Done by    : M.Wadid                                      Date : 11/03/12 */
/* Description: - Solved teamtrack tickets                                    */
/*                   #2464,  #2466, #2468    */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.9     R2.0.0     AR3.0.0                                    */
/* Done by    : H.Salem                                       Date : 08/09/09 */
/* Description: - Solved teamtrack tickets                                    */
/*                   #01531, #01533, #01535, #01536, #01538, #01810           */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.8                                                           */
/* Done by    : Moustafa Adel                                Date : 17/07/08  */
/* Description: The new API DET_GetVersionInfo was implemented based on       */
/*              TeamTrack StdSW#00683                                         */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.7                                                           */
/* Done by    : M. Assem Gawdat                              Date : 18/10/07  */
/* Description: Changes due to Rework points ISS-DET-1,2,3,4,5,6,7,10,13,18,  */
/*              31,35,37,38,9,24,25,32                                        */
/******************************************************************************/
/* TFR        : None                                                          */
/* Rev        : 1.3                                                           */
/* Done by    : PEJ                                          Date : 14/12/07  */
/* Description: - TeamTrack 184 (SMF-DET-015.doc) : Justifications of the two */
/*                remaining PC-Lint errors.                                   */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by           */
/*              configuration management tool (PVCS)                          */
/* PRQA S 0288 ++                                                             */
/* PVCS Information                                                          
$Header:   I:/PROJETS/LIBEMB/LOG/SRV/DET/LOG/Det.c_v   1.0   06 Aug 2012 15:31:26   lvoilmy  $
*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/


/* !Trace_To: GSCSW-DET-SDD-001-0022                                          */
#include "Det.h"
#include "SchM_Det.h"



#if (DET_TYPE_IMPLEMENTED != DET_NONE)



/******************************************************************************/
/* Local Symbols definitions                                                  */
/******************************************************************************/

#if ((DET_TYPE_IMPLEMENTED == DET_RAM) || \
   ((DET_TYPE_IMPLEMENTED == DET_COM) && (DET_MAINFUNCTION_IMPLEMENTED == STD_ON)))

/******************************************************************************/
/* !Comment         : Array upper-limit derived from buffer size              */
/******************************************************************************/
#define u8LOG_ARRAY_LIMIT \
    (uint8)(DET_BUFFER_NB_OF_RECORD - 1)

#if ( DET_TYPE_MANAGEMENT == DET_FIFO_TYPE )
/******************************************************************************/
/* !Comment         : Maximum number of errors derived from buffer size       */
/******************************************************************************/
#define u8MAX_NUMBER_OF_ERRORS \
              (uint8)(DET_BUFFER_NB_OF_RECORD)
#endif


/******************************************************************************/
/* !Comment: The Det_u8NumberOfErrors value when there is no pending errors.  */
/******************************************************************************/
#define u8NO_PENDING_ERRORS 0U

/******************************************************************************/
/* !Comment: The entry number of the start of the buffer.                     */
/******************************************************************************/
#define u8BUFFER_START 0U

#endif              



#if (DET_TYPE_IMPLEMENTED == DET_COM) 

/******************************************************************************/
/* !Comment: The reset value of number of SCI sending retries.                */
/******************************************************************************/
#define u16RETRIES_RESET 0U

#endif

#endif /* if DET_TYPE_IMPLEMENTED != DET_NONE */

/******************************************************************************/
/* Private Enum Definitions                                                   */
/******************************************************************************/

/******************************************************************************/
/* !Comment         : DET module status enumeration type                      */
/******************************************************************************/
typedef enum 
{
  DET_UNINIT=0,
  DET_INIT,
  DET_STARTED
}tenuDetStatusType;





/******************************************************************************/
/* !Comment         : DET module status variable                              */
/*                  : Exists if DET_TYPE_IMPLEMENTED is not DET_NONE              */
/* !Trace_To        : GSCSW-DET-SDD-001-0033                                  */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
#define DET_START_SEC_VAR_INIT_UNSPECIFIED
/* !Trace_To: GSCSW-DET-SDD-001-0061                                          */
#include "MemMap.h"

STATIC VAR(tenuDetStatusType, DET_VAR) \
                                     Det_enuDetStatus = DET_UNINIT;
/* PRQA S 0850 --                                                             */

#define DET_STOP_SEC_VAR_INIT_UNSPECIFIED
/* !Trace_To: GSCSW-DET-SDD-001-0061                                          */
#include "MemMap.h"



/******************************************************************************/
/* Module local variables                                                     */
/******************************************************************************/

/******************************************************************************/
/* !Comment         : #if DET type is not DET_NONE                                */
/******************************************************************************/
#if ( DET_TYPE_IMPLEMENTED != DET_NONE )



#if ((DET_TYPE_IMPLEMENTED == DET_RAM) || \
   ((DET_TYPE_IMPLEMENTED == DET_COM) && (DET_MAINFUNCTION_IMPLEMENTED == STD_ON)))
/******************************************************************************/
/* !Comment: Start of memory mapping for DET non-initialized variables of     */
/*           unspecified size                                                 */
/******************************************************************************/
/* !Deviation:  Inhibit MISRA rule [750] because local non referenced macro is*/
/*              according to AUTOSAR specifications                           */
/* !Deviation:  Inhibit MISRA rule [760] because redundant macro defined is   */
/*              according to AUTOSAR specifications                           */
/* !Deviation:  Inhibit MISRA rule [961] because multiple use of #define is   */
/*              according to AUTOSAR specifications                           */
/* !Deviation:  Inhibit MISRA rule [537] because repeated include for Memmap  */
/*              is according to AUTOSAR specifications                        */
/* !Deviation:  Inhibit MISRA rule [960] because use of #undef is according to*/
/*              AUTOSAR specifications                                        */
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v                             */
/* !Deviation : inhibit MISRA rule [5087]: because #include is used after a   */
/*              non preprocessor directives                                   */
/* PRQA S 5087 L1                                                             */
#define DET_START_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
/* !Trace_To: GSCSW-DET-SDD-001-0061                                          */
#include "MemMap.h"
/* PRQA L:L1                                                                  */
/*lint -restore                                                               */

/******************************************************************************/
/* !Comment         : Buffer to store the reported errors                     */
/*                  : Exists if ( DET_TYPE_IMPLEMENTED is DET_RAM or              */
/*                  :       (DET_TYPE_IMPLEMENTED is DET_COM and                  */
/*                  :        DET_MAINFUNCTION_IMPLEMENTED is STD_ON) )        */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
/* !Deviation : Inhibit MISRA rule [3218]: DET Buffer used by 2 services
                Det_ReportError and Det_MainFunction. Due to MemMap usage,
                this buffer can't be local to a function in order to be
                mapped by MemMap.h                                            */
/* PRQA S 3218 ++                                                             */

#if ((DET_CALLBACK_IMPLEMENTED == DET_CBK_DIRECT)||\
     (DET_TYPE_IMPLEMENTED == DET_COM)||           \
     (DET_CALLBACK_IMPLEMENTED == DET_CBK_MAIN))

STATIC_CONF VAR(Det_tstrReportError, DET_VAR_NOINIT)   \
                Det_astrRecordedErrors[DET_BUFFER_NB_OF_RECORD];

#endif

/* PRQA S 3218 --                                                             */
/* PRQA S 0850 --                                                             */


/******************************************************************************/
/* !Comment: End of memory mapping for DET non-initialized variables of       */
/*           unspecified size                                                 */
/******************************************************************************/
/* !Deviation:  Inhibit MISRA rule [750] because local non referenced macro is*/
/*              according to AUTOSAR specifications                           */
/* !Deviation:  Inhibit MISRA rule [760] because redundant macro defined is   */
/*              according to AUTOSAR specifications                           */
/* !Deviation:  Inhibit MISRA rule [961] because multiple use of #define is   */
/*              according to AUTOSAR specifications                           */
/* !Deviation:  Inhibit MISRA rule [537] because repeated include for Memmap  */
/*              is according to AUTOSAR specifications                        */
/* !Deviation:  Inhibit MISRA rule [960] because use of #undef is according to*/
/*              AUTOSAR specifications                                        */
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v                             */
/* !Deviation : inhibit MISRA rule [5087]: because #include is used after a   */
/*              non preprocessor directives                                   */
/* PRQA S 5087 L1                                                             */
#define DET_STOP_SEC_VAR_POWER_ON_CLEARED_UNSPECIFIED
/* !Trace_To: GSCSW-DET-SDD-001-0061                                          */
#include "MemMap.h"
/* PRQA L:L1                                                                  */
/*lint -restore                                        */
#endif

/******************************************************************************/
/* !Comment: Start of memory mapping for DET variables which are not          */
/*           initialized by startup code of uint8 size                        */
/******************************************************************************/
/* !Deviation:  Inhibit MISRA rule [750] because local non referenced macro is*/
/*              according to AUTOSAR specifications                           */
/* !Deviation:  Inhibit MISRA rule [760] because redundant macro defined is   */
/*              according to AUTOSAR specifications                           */
/* !Deviation:  Inhibit MISRA rule [961] because multiple use of #define is   */
/*              according to AUTOSAR specifications                           */
/* !Deviation:  Inhibit MISRA rule [537] because repeated include for Memmap  */
/*              is according to AUTOSAR specifications                        */
/* !Deviation:  Inhibit MISRA rule [960] because use of #undef is according to*/
/*              AUTOSAR specifications                                        */
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v                             */
/* !Deviation : inhibit MISRA rule [5087]: because #include is used after a   */
/*              non preprocessor directives                                   */
/* PRQA S 5087 L1                                                             */
#define DET_START_SEC_VAR_POWER_ON_CLEARED_8BIT
/* !Trace_To: GSCSW-DET-SDD-001-0061                                          */
#include "MemMap.h"
/* PRQA L:L1                                                                  */
/*lint -restore                                                               */

#if ((DET_TYPE_IMPLEMENTED == DET_RAM) || \
   ((DET_TYPE_IMPLEMENTED == DET_COM) && (DET_MAINFUNCTION_IMPLEMENTED == STD_ON)))

/******************************************************************************/
/* !Comment         : Index of the buffer head in the array                   */
/*                  : Exists if ( DET_TYPE_IMPLEMENTED is DET_RAM or              */
/*                  :       (DET_TYPE_IMPLEMENTED is DET_COM and                  */
/*                  :        DET_MAINFUNCTION_IMPLEMENTED is STD_ON) )        */
/* !Trace_To        : GSCSW-DET-SDD-001-0033                                  */
/* !Range           : 0..DET_BUFFER_NB_OF_RECORD -1                    */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
STATIC_CONF VAR(uint8, DET_VAR_NOINIT) Det_u8BufferHead;
/* PRQA S 0850 --                                                             */

/******************************************************************************/
/* !Comment         : Number of errors pending management                     */
/*                  : Exists if ( DET_TYPE_IMPLEMENTED is DET_RAM or              */
/*                  :       (DET_TYPE_IMPLEMENTED is DET_COM and                  */
/*                  :        DET_MAINFUNCTION_IMPLEMENTED is STD_ON) )        */
/* !Trace_To        : GSCSW-DET-SDD-001-0033                                  */
/* !Range           : 0 .. DET_BUFFER_NB_OF_RECORD                     */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
STATIC VAR(uint8, DET_VAR_NOINIT) Det_u8NumberOfErrors;
/* PRQA S 0850 --                                                             */



#endif


#if ( DET_MAINFUNCTION_IMPLEMENTED == STD_ON )
/******************************************************************************/
/* !Comment         : Index of the buffer tail in the array                   */
/*                  : Exists if DET_MAINFUNCTION_IMPLEMENTED is STD_ON        */
/* !Trace_To        : GSCSW-DET-SDD-001-0033                                  */
/* !Range           : 0..DET_BUFFER_NB_OF_RECORD -1                      */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
STATIC_CONF VAR(uint8, DET_VAR_NOINIT) Det_u8BufferTail;
/* PRQA S 0850 --                                                             */

#endif


/******************************************************************************/
/* !Comment: End of memory mapping for DET variables which are not            */
/*           initialized by startup code of uint8 size                        */
/******************************************************************************/
/* !Deviation:  Inhibit MISRA rule [750] because local non referenced macro is*/
/*              according to AUTOSAR specifications                           */
/* !Deviation:  Inhibit MISRA rule [760] because redundant macro defined is   */
/*              according to AUTOSAR specifications                           */
/* !Deviation:  Inhibit MISRA rule [961] because multiple use of #define is   */
/*              according to AUTOSAR specifications                           */
/* !Deviation:  Inhibit MISRA rule [537] because repeated include for Memmap  */
/*              is according to AUTOSAR specifications                        */
/* !Deviation:  Inhibit MISRA rule [960] because use of #undef is according to*/
/*              AUTOSAR specifications                                        */
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v                             */
/* !Deviation : inhibit MISRA rule [5087]: because #include is used after a   */
/*              non preprocessor directives                                   */
/* PRQA S 5087 L1                                                             */
#define DET_STOP_SEC_VAR_POWER_ON_CLEARED_8BIT
/* !Trace_To: GSCSW-DET-SDD-001-0061                                          */
#include "MemMap.h"
/* PRQA L:L1                                                                  */
/*lint -restore                                                               */


/******************************************************************************/
/* !Comment: Start of memory mapping for DET non-initialized variables of     */
/*           unspecified size                                                 */
/******************************************************************************/
/* !Deviation:  Inhibit MISRA rule [750] because local non referenced macro is*/
/*              according to AUTOSAR specifications                           */
/* !Deviation:  Inhibit MISRA rule [760] because redundant macro defined is   */
/*              according to AUTOSAR specifications                           */
/* !Deviation:  Inhibit MISRA rule [961] because multiple use of #define is   */
/*              according to AUTOSAR specifications                           */
/* !Deviation:  Inhibit MISRA rule [537] because repeated include for Memmap  */
/*              is according to AUTOSAR specifications                        */
/* !Deviation:  Inhibit MISRA rule [960] because use of #undef is according to*/
/*              AUTOSAR specifications                                        */
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v                             */
/* !Deviation : inhibit MISRA rule [5087]: because #include is used after a   */
/*              non preprocessor directives                                   */
/* PRQA S 5087 L1                                                             */
#define DET_START_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
/* !Trace_To: GSCSW-DET-SDD-001-0061                                          */
#include "MemMap.h"
/* PRQA L:L1                                                                  */
/*lint -restore                                                               */

#if ((DET_TYPE_IMPLEMENTED == DET_RAM) || \
   ((DET_TYPE_IMPLEMENTED == DET_COM) && (DET_MAINFUNCTION_IMPLEMENTED == STD_ON)))
   
/******************************************************************************/
/* !Comment         : Flag to indicate overflow                               */
/*                  : Exists if ( DET_TYPE_IMPLEMENTED is DET_RAM or              */
/*                  :       (DET_TYPE_IMPLEMENTED is DET_COM and                  */
/*                  :        DET_MAINFUNCTION_IMPLEMENTED is STD_ON) )        */
/* !Trace_To        : GSCSW-DET-SDD-001-0033                                  */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
/* !Deviation : Inhibit MISRA rule [3299]: Det_bOverflowOccured is a required
                flag to indicate the buffer overflow occurence. Required by
                GSCSW-DET-SRS-003-0019 & SIQ_3,4                              */
/* PRQA S 3229 ++                                                             */

#if ((DET_TYPE_IMPLEMENTED == DET_RAM)|| \
     ((DET_TYPE_IMPLEMENTED == DET_COM) && \
     (DET_MAINFUNCTION_IMPLEMENTED == STD_ON))|| \
     (DET_TYPE_MANAGEMENT == DET_STACK_TYPE))

STATIC_CONF VAR(boolean, DET_VAR_NOINIT) Det_bOverflowOccured;

#endif

/* PRQA S 3229 --                                                             */
/* PRQA S 0850 --                                                             */

#endif

/******************************************************************************/
/* !Comment: End of memory mapping for DET non-initialized variables of       */
/*           unspecified size                                                 */
/******************************************************************************/
/* !Deviation:  Inhibit MISRA rule [750] because local non referenced macro is*/
/*              according to AUTOSAR specifications                           */
/* !Deviation:  Inhibit MISRA rule [760] because redundant macro defined is   */
/*              according to AUTOSAR specifications                           */
/* !Deviation:  Inhibit MISRA rule [961] because multiple use of #define is   */
/*              according to AUTOSAR specifications                           */
/* !Deviation:  Inhibit MISRA rule [537] because repeated include for Memmap  */
/*              is according to AUTOSAR specifications                        */
/* !Deviation:  Inhibit MISRA rule [960] because use of #undef is according to*/
/*              AUTOSAR specifications                                        */
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v                             */
/* !Deviation : inhibit MISRA rule [5087]: because #include is used after a   */
/*              non preprocessor directives                                   */
/* PRQA S 5087 L1                                                             */
#define DET_STOP_SEC_VAR_POWER_ON_CLEARED_BOOLEAN
/* !Trace_To: GSCSW-DET-SDD-001-0061                                          */
#include "MemMap.h"
/* PRQA L:L1                                                                  */
/*lint -restore                                                               */

#endif /*#if DET_TYPE_IMPLEMENTED != DET_NONE */



/******************************************************************************/
/* Module functions                                                           */
/******************************************************************************/


/******************************************************************************/
/* !Comment: Start of memory mapping for DET code segment                     */
/******************************************************************************/
/* !Deviation:  Inhibit MISRA rule [750] because local non referenced macro is*/
/*              according to AUTOSAR specifications                           */
/* !Deviation:  Inhibit MISRA rule [760] because redundant macro defined is   */
/*              according to AUTOSAR specifications                           */
/* !Deviation:  Inhibit MISRA rule [961] because multiple use of #define is   */
/*              according to AUTOSAR specifications                           */
/* !Deviation:  Inhibit MISRA rule [537] because repeated include for Memmap  */
/*              is according to AUTOSAR specifications                        */
/* !Deviation:  Inhibit MISRA rule [960] because use of #undef is according to*/
/*              AUTOSAR specifications                                        */
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v                             */
/* !Deviation : inhibit MISRA rule [5087]: because #include is used after a   */
/*              non preprocessor directives                                   */
/* PRQA S 5087 L1                                                             */
#define DET_START_SEC_CODE
/* !Trace_To: GSCSW-DET-SDD-001-0061                                          */
#include "MemMap.h"
/* PRQA L:L1                                                                  */
/*lint -restore                                                               */



/******************************************************************************/
/* !Description      : DET module initialization service                      */
/* !Trace_To         : GSCSW-DET-SDD-001-0019                                 */
/*                                                                            */
/******************************************************************************/
/*  !Pseudo         :if DET_TYPE_IMPLEMENTED is not DET_NONE                      */
/*  !Pseudo         : if current status is DET_UNINIT                         */
/*  !Pseudo         :  set current status to DET_INIT                         */
/*  !Pseudo         : if ( DET_TYPE_IMPLEMENTED is DET_RAM or                     */
/*  !Pseudo         :       (DET_TYPE_IMPLEMENTED is DET_COM and                  */
/*  !Pseudo         :        DET_MAINFUNCTION_IMPLEMENTED is STD_ON) )        */
/*  !Pseudo         :  set buffer head to 0                                   */
/*  !Pseudo         :  set number of errors to 0                              */
/*  !Pseudo         :  clear overflow flag                                    */
/*  !Pseudo         :  if DET_MAINFUNCTION_IMPLEMENTED is STD_ON              */
/*  !Pseudo         :   set buffer tail to 0                                  */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
FUNC(void, DET_CODE) Det_Init ( void )
/* PRQA S 0850 --                                                             */
{
  /* !Comment: If DET_TYPE_IMPLEMENTED is not DET_NONE                            */
  #if (DET_TYPE_IMPLEMENTED != DET_NONE)

  /* !Comment: If current status is DET_UNINIT                                */
  if (Det_enuDetStatus == DET_UNINIT)
  {

    /* !Comment: Set current status to DET_INIT                               */
    Det_enuDetStatus = DET_INIT;    

    /*  !Comment: If (DET_TYPE_IMPLEMENTED is DET_RAM or                          */
    /*  !Comment:     (DET_TYPE_IMPLEMENTED is DET_COM and                        */
    /*  !Comment:      DET_MAINFUNCTION_IMPLEMENTED is STD_ON))               */
    #if ((DET_TYPE_IMPLEMENTED == DET_RAM) || \
     ((DET_TYPE_IMPLEMENTED == DET_COM) && (DET_MAINFUNCTION_IMPLEMENTED==STD_ON)))

    /* !Comment: Set number of errors to u8NO_PENDING_ERRORS                  */
    Det_u8NumberOfErrors = u8NO_PENDING_ERRORS;

    /* !Comment: Set buffer head to u8BUFFER_START                            */
    Det_u8BufferHead = u8BUFFER_START;

    /* !Comment: Clear overflow flag                                          */
    Det_bOverflowOccured = (boolean)FALSE;

    #endif    


    /* !Comment: If DET_MAINFUNCTION_IMPLEMENTED is STD_ON                    */
    #if ( DET_MAINFUNCTION_IMPLEMENTED == STD_ON )

    /* !Comment: Set buffer tail to u8BUFFER_START                            */
    Det_u8BufferTail = u8BUFFER_START;

    #endif

  }
  #endif /* #if DET_TYPE_IMPLEMENTED != DET_NONE */  
}



/******************************************************************************/
/* !Description      : DET module start service                               */
/* !Trace_To         : GSCSW-DET-SDD-001-0021                                 */
/*                                                                            */
/******************************************************************************/
/*  !Pseudo         :if DET_TYPE_IMPLEMENTED is not DET_NONE                      */
/*  !Pseudo         : if current status is DET_INIT                           */
/*  !Pseudo         :  set current status to DET_STARTED                      */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
FUNC(void, DET_CODE) Det_Start ( void )
/* PRQA S 0850 --                                                             */
{
  /* !Comment: If DET_TYPE_IMPLEMENTED is not DET_NONE                            */
  #if ( DET_TYPE_IMPLEMENTED != DET_NONE )

  /* !Comment: If current status is DET_INIT                                  */
  if ( Det_enuDetStatus == DET_INIT )
  {
    /* !Comment: Set current status to DET_STARTED                            */
    Det_enuDetStatus = DET_STARTED;    
  }

  #endif /* #if DET_TYPE_IMPLEMENTED != DET_NONE */  
}



/******************************************************************************/
/* !Description      : DET module error reporting service                     */
/* !Trace_To         : GSCSW-DET-SDD-001-0020, GSCSW-DET-SDD-001-0028         */
/* !Trace_To         : GSCSW-DET-SDD-001-0035                                 */
/*                                                                            */
/******************************************************************************/
/*  !Pseudo       : fill in the temporary error variable                      */
/*  !Pseudo       : if DET_TYPE_IMPLEMENTED is not DET_NONE                       */
/*  !Pseudo       :   if current status is DET_STARTED                        */

/*  !Pseudo       :    if ( DET_TYPE_IMPLEMENTED is DET_RAM or                    */
/*  !Pseudo       :       (DET_TYPE_IMPLEMENTED is DET_COM and                    */
/*  !Pseudo       :        DET_MAINFUNCTION_IMPLEMENTED is STD_ON))           */

/*  !Pseudo       :     if there is no buffer overflow                        */
/*  !Pseudo       :      store error data in RAM at position of buffer head   */
/*  !Pseudo       :      if DET_CALLBACK_IMPLEMENTED is set to DET_CBK_DIRECT     */
/*  !Pseudo       :       call callback                                       */
/*  !Pseudo       :      if buffer head reached end of buffer                 */
/*  !Pseudo       :       raise the overflow flag                             */
/*  !Pseudo       :       if DET_TYPE_MANAGEMENT is set to DET_FIFO_TYPE          */
/*  !Pseudo       :        set buffer head to 0                               */
/*  !Pseudo       :      else increment buffer head                           */
/*  !Pseudo       :     else if DET_CALLBACK_IMPLEMENTED is set to DET_CBK_DIRECT */
/*  !Pseudo       :      call callback with pointer to local error data       */

/*  !Pseudo       : else ( DET_TYPE_IMPLEMENTED is DET_COM and                    */
/*  !Pseudo       : DET_MAINFUNCTION_IMPLEMENTED is STD_OFF )                 */

/*  !Pseudo       :   if DET_CALLBACK_IMPLEMENTED is set to DET_CBK_DIRECT        */
/*  !Pseudo       :    call callback                                          */
/*  !Pseudo       :   set number of SCI trials to 0                           */
/*  !Pseudo       :   set exit_loop flag to FALSE                             */
/*  !Pseudo       :   Loop While number of trials has not exceeded maximun    */
/*  !Pseudo       :   if SCI is available                                     */
/*  !Pseudo       :    if data is sent correctly                              */
/*  !Pseudo       :     set exit_loop flag to TRUE                            */
/*  !Pseudo       :   increment number of SCI trials                          */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
FUNC(void, DET_CODE) Det_ReportError ( 
                         /* !Comment : Id of the Reporting Module             */
                         uint16 u16ModuleId,
                         /* !Comment : Id of the Reporting Instance           */
                         uint8  u8InstanceId,
                         /* !Comment : Id of the Reporting API                */
                         uint8  u8ApiId,
                         /* !Comment : Id of the Reported Error               */
                         uint8  u8ErrorId
                       )
/* PRQA S 0850 --                                                             */
{
  /* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments    */
  /*              either using AUTOSAR AUTOMATIC definition or by configurable*/
  /*              memory classes                                              */
  /* PRQA S 0850 ++                                                           */
  VAR(Det_tstrReportError, AUTOMATIC) strTempErrorBuf;   
  /* PRQA S 0850 --                                                           */

  /* !Comment         : #if SCI sending is needed                             */
  #if ((DET_TYPE_IMPLEMENTED == DET_COM) && (DET_MAINFUNCTION_IMPLEMENTED==STD_OFF))
  
  /* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments    */
  /*              either using AUTOSAR AUTOMATIC definition or by configurable*/
  /*              memory classes                                              */
  /* PRQA S 0850 ++                                                           */
  /* !Comment   : static storage to store the error data till the Sci_Send
                  asynchronous service completed its task.                    */
 STATIC VAR(Det_tstrReportError, DET_VAR_NOINIT) LOC_strErrorBuf;   
  /* PRQA S 0850 --                                                           */

  /* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments    */
  /*              either using AUTOSAR AUTOMATIC definition or by configurable*/
  /*              memory classes                                              */
  /* PRQA S 0850 ++                                                           */
  /* !Comment   : Temporary buffer to hold the number of retries              */
  VAR(uint16, AUTOMATIC) u16NumberOfTrials = u16RETRIES_RESET;  
  /* PRQA S 0850 --                                                           */

  /* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments    */
  /*              either using AUTOSAR AUTOMATIC definition or by configurable*/
  /*              memory classes                                              */
  /* PRQA S 0850 ++                                                           */
  /*  !Comment        : flag to exit from SCI loop                            */
  VAR(boolean, AUTOMATIC) bExitCommLoop = (boolean)FALSE;
  /* PRQA S 0850 --                                                           */

  #endif

    strTempErrorBuf.u16ModuleId  = u16ModuleId;
    strTempErrorBuf.u8InstanceId = u8InstanceId;
    strTempErrorBuf.u8ApiId      = u8ApiId;
    strTempErrorBuf.u8ErrorId    = u8ErrorId; 

  /*  !Comment         :if DET_TYPE_IMPLEMENTED is not DET_NONE                   */
  #if ( DET_TYPE_IMPLEMENTED != DET_NONE )

    /*  !Comment         : if current status is DET_STARTED                   */
  if (Det_enuDetStatus == DET_STARTED )
  {

  /*  !Comment         :  if ( DET_TYPE_IMPLEMENTED is DET_RAM or                 */
  /*  !Comment         :  (DET_TYPE_IMPLEMENTED is DET_COM and                    */
  /*  !Comment         :  DET_MAINFUNCTION_IMPLEMENTED is STD_ON) )           */
  #if (DET_TYPE_IMPLEMENTED == DET_RAM) || \
    (( DET_TYPE_IMPLEMENTED == DET_COM )&&(DET_MAINFUNCTION_IMPLEMENTED == STD_ON))



/****************************** Storing in RAM ********************************/

    /* !Deviation : Inhibit MISRA rule [3141,960]: Macro is to be implemented */
    /*              during integration phase                                  */
    /* PRQA S 3141 ++                                                         */
    /*lint -save -vo -e960 -v                                                 */
    /*  !Comment       : enter critical region 001                            */
    SchM_Enter_Det(DET_ACCESS_001);
    /*lint -restore                                                           */
    /* PRQA S 3141 --                                                         */


    #if ( DET_TYPE_MANAGEMENT == DET_FIFO_TYPE )
  
    /* !Comment: If there is no buffer overflow                               */
    if ( Det_u8NumberOfErrors < u8MAX_NUMBER_OF_ERRORS )
    {

    #elif ( DET_TYPE_MANAGEMENT == DET_STACK_TYPE )
  
    /* !Comment: If there is no buffer overflow                               */
    if ( Det_bOverflowOccured != (boolean)TRUE )
    {

      #endif

      #if ((DET_CALLBACK_IMPLEMENTED == DET_CBK_DIRECT)||\
         (DET_TYPE_IMPLEMENTED == DET_COM)||           \
         (DET_CALLBACK_IMPLEMENTED == DET_CBK_MAIN))
       
      /* GSCSW-DET-SRC-001-0002                                               */
      /* !Comment: Store error data in RAM at position of buffer head         */
      Det_astrRecordedErrors[Det_u8BufferHead] = strTempErrorBuf; 
        
      /* !Comment: If DET_CALLBACK_IMPLEMENTED is set to DET_CBK_DIRECT           */
      
      #endif
      
      
      #if ( DET_CALLBACK_IMPLEMENTED == DET_CBK_DIRECT )
      
      /* !Comment: Call callback                                              */
      Det_CallBack(&Det_astrRecordedErrors[Det_u8BufferHead]);
      
      #endif

      /* GSCSW-DET-SRC-001-0003                                               */
      /* !Comment: Increment the global number_of_errors                      */
      Det_u8NumberOfErrors++;      
        
      if (Det_u8BufferHead == u8LOG_ARRAY_LIMIT)
      {

        /* !Comment: If DET_TYPE_MANAGEMENT is set to DET_FIFO_TYPE                */
        #if ( DET_TYPE_MANAGEMENT == DET_FIFO_TYPE )

        /* !Comment: Recycle the buffer head                                  */
        Det_u8BufferHead = u8BUFFER_START;
        
        #endif
        
        /* !Comment: Raise overflow flag                                      */
        Det_bOverflowOccured = (boolean)TRUE;  

      }
      else
      {
        /* GSCSW-DET-SRC-001-0004                                             */
        /* !Comment: Increment buffer head                                    */
        Det_u8BufferHead++;
      }

      /* !Deviation : Inhibit MISRA rule [3141,960]: Macro is to be
                      implemented during integration phase                    */
      /* PRQA S 3141 ++                                                       */
      /*lint -save -vo -e960 -v                                               */
      /* !Comment: Leave critical region 001                                  */
      SchM_Exit_Det(DET_ACCESS_001);
      /*lint -restore                                                         */
      /* PRQA S 3141 --                                                       */

    }
    else
    {

      /* !Deviation : Inhibit MISRA rule [3141,960]: Macro is to be
                      implemented during integration phase                    */
      /* PRQA S 3141 ++                                                       */
      /*lint -save -vo -e960 -v                                               */
      /* !Comment: Leave critical region 001                                  */
      SchM_Exit_Det(DET_ACCESS_001);
      /*lint -restore                                                         */
      /* PRQA S 3141 --                                                       */

      /* !Comment: If DET_CALLBACK_IMPLEMENTED is set to DET_CBK_DIRECT           */
      #if ( DET_CALLBACK_IMPLEMENTED == DET_CBK_DIRECT )

      /* !Deviation : Inhibit MISRA rule [0850]: Macro is to be implemented   */
      /*              during integration phase                                */
      /* PRQA S 0850 ++                                                       */
      /* !Deviation : Inhibit MISRA rule [3212,961]: This cast is not redundant
                      if DET_VAR_NOINIT is configured as unempty memclass     */
      /* PRQA S 3212 ++                                                       */
      /*lint -save -vo -e961 -v                                               */
      /* !Comment: Call callback with pointer to error data                   */
      Det_CallBack((P2VAR(Det_tstrReportError, AUTOMATIC, DET_VAR_NOINIT))
                                                              &strTempErrorBuf);
      /*lint -restore                                                         */
      /* PRQA S 3212 --                                                       */
      /* PRQA S 0850 --                                                       */
      #endif
    }                                     
  

    

/**************************** End of Storing in RAM ***************************/


    
  /*  !Comment       :  else ( DET_TYPE_IMPLEMENTED is DET_COM and                */
  /*  !Comment       :  DET_MAINFUNCTION_IMPLEMENTED is STD_OFF )             */
  #else      /* #if (DET_TYPE_IMPLEMENTED == DET_RAM) || \
    (( DET_TYPE_IMPLEMENTED == DET_COM )&&(DET_MAINFUNCTION_IMPLEMENTED==STD_ON)) */



/******************************** SCI Sending *********************************/


    /* !Comment: If DET_CALLBACK_IMPLEMENTED is set to DET_CBK_DIRECT             */
    #if ( DET_CALLBACK_IMPLEMENTED == DET_CBK_DIRECT )

    /* !Deviation : Inhibit MISRA rule [0850]: Macro is to be implemented     */
    /*              during integration phase                                  */
    /* PRQA S 0850 ++                                                         */
    /* !Deviation : Inhibit MISRA rule [3212,961]: This cast is not redundant
                    if DET_VAR_NOINIT is configured as unempty memclass       */
    /* PRQA S 3212 ++                                                         */
    /*lint -save -vo -e961 -v                                                 */
    /* !Comment: Call callback                                                */
    Det_CallBack((P2VAR(Det_tstrReportError, AUTOMATIC, DET_VAR_NOINIT))
                                                              &strTempErrorBuf);
    /*lint -restore                                                           */
    /* PRQA S 3212 --                                                         */
    /* PRQA S 0850 --                                                         */
  
    #endif

  
    /* GSCSW-DET-SRC-001-0006                                                 */
    /* !Comment: Loop While number of trials has not exceeded maximum
                 and data is not sent correctly                               */
    while ((u16NumberOfTrials <= (uint16)DET_SCI_NUM_RETRIES)
             && (bExitCommLoop == (boolean)FALSE)) 
    {
      /* !Comment: If SCI is available                                        */
      if (Det_ComGetStatus() == SCI_AVAILABLE)
      {

        /* !Deviation : Inhibit MISRA rule [3141,960]: Macro is to be
                        implemented during integration phase                  */
        /* PRQA S 3141 ++                                                     */
        /*lint -save -vo -e960 -v                                             */
        /*  !Comment       : enter critical region 002                        */
        SchM_Enter_Det(DET_ACCESS_002);
        /*lint -restore                                                       */
        /* PRQA S 3141 --                                                     */

        LOC_strErrorBuf = strTempErrorBuf;
        
        /* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty
                        arguments either using AUTOSAR AUTOMATIC definition or
                        by configurable memory classes                        */
        /* PRQA S 0850 ++                                                     */
        /* !Deviation : Inhibit MISRA rule [0310]: This pointer casting is
                        mandatory as the SCI service takes pointer to uint8
                        and the required object to send is a structure        */
        /* PRQA S 0310 ++                                                     */
        /* GSCSW-DET-SRC-001-0007                                             */
        /* !Comment: If data is sent correctly                                */
        if (Det_ComSend((P2VAR(uint8, AUTOMATIC, DET_VAR_NOINIT))&LOC_strErrorBuf,\
                                     (uint8)sizeof(LOC_strErrorBuf)) == E_OK)
        /* PRQA S 0310 --                                                     */
        /* PRQA S 0850 --                                                     */
        {
          /* GSCSW-DET-SRC-001-0008                                           */
          /* !Comment: Set exit_loop flag to TRUE                             */
          bExitCommLoop = (boolean)TRUE;
        }        

        /* !Deviation : Inhibit MISRA rule [3141,960]: Macro is to be
                        implemented during integration phase                  */
        /* PRQA S 3141 ++                                                     */
        /*lint -save -vo -e960 -v                                             */
        /* !Comment: Leave critical region 002                                */
        SchM_Exit_Det(DET_ACCESS_002);
        /*lint -restore                                                       */
        /* PRQA S 3141 --                                                     */
     
      }
    
      /* GSCSW-DET-SRC-001-0009                                               */
      /* !Comment: Increment number of SCI trials                             */
      u16NumberOfTrials++;
    }

    
/***************************** End of SCI Sending *****************************/


  #endif/* #if (DET_TYPE_IMPLEMENTED == DET_RAM) || \
    (( DET_TYPE_IMPLEMENTED == DET_COM )&&(DET_MAINFUNCTION_IMPLEMENTED==STD_ON)) */

  }
  
  
  #elif (DET_TYPE_IMPLEMENTED == DET_NONE)

  /* Breakpoint may be inserted here, callback is not called */
  /* The error data is stored in strTempErrorBuf */

  #endif /* DET_TYPE_IMPLEMENTED != DET_NONE */

  }
  



/******************************************************************************/
/* !Description      : DET module main handling function                      */
/* !Trace_To         : GSCSW-DET-SDD-001-0029, GSCSW-DET-SDD-001-0035         */
/*                                                                            */
/******************************************************************************/
/*  !Pseudo       :if DET_TYPE_IMPLEMENTED is not DET_NONE                        */
/*  !Pseudo       : clear exit main loop flag                                 */
/*  !Pseudo       : if current status is DET_STARTED                          */

/*  !Pseudo       :  loop while (there are pending errors entries and         */
/*  !Pseudo       :  exit main loop is false)                                 */
/*  !Pseudo       :  get the error at buffer tail position                    */

/*  !Pseudo       :  if DET_CALLBACK_IMPLEMENTED is DET_CBK_MAIN                  */
/*  !Pseudo       :   if this error was not callbacked before then call its   */
/*  !Pseudo       :   callback                                                */

/*  !Pseudo       :  if DET_TYPE_IMPLEMENTED is DET_COM                           */
/*  !Pseudo       :    if SCI is available                                    */
/*  !Pseudo       :     if data is sent correctly                             */
/*  !Pseudo       :      set exit_loop flag to TRUE                           */
/*  !Pseudo       :      increment buffer tail                                */
/*  !Pseudo       :      if DET_TYPE_MANAGEMENT is DET_FIFO_TYPE                  */
/*  !Pseudo       :       if buffer tail reached end of buffer                */
/*  !Pseudo       :        set buffer tail to 0                               */
/*  !Pseudo       :      increment number of SCI trials                       */

/*  !Pseudo       :  if DET_TYPE_IMPLEMENTED is DET_RAM                           */
/*  !Pseudo       :   increment buffer tail                                   */
/*  !Pseudo       :    if DET_TYPE_MANAGEMENT is DET_FIFO_TYPE                    */
/*  !Pseudo       :     if buffer tail reached end of buffer                  */
/*  !Pseudo       :      set buffer tail to 0                                 */

/*  !Pseudo       :  next loop                                                */
/******************************************************************************/
#if (DET_MAINFUNCTION_IMPLEMENTED == STD_ON )

  #if ( DET_CALLBACK_IMPLEMENTED == DET_CBK_MAIN )
  #if ( DET_TYPE_IMPLEMENTED == DET_COM )
  /* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments    */
  /*              either using AUTOSAR AUTOMATIC definition or by configurable*/
  /*              memory classes                                              */
  /* PRQA S 0850 ++                                                           */
  /*  !Comment        : flag to indicate that this error info has been sent to
                        the callback before                                   */
STATIC VAR(boolean, DET_VAR) LOC_bCbkSent = (boolean)FALSE;
  /* PRQA S 0850 --                                                           */
  #endif /* DET_CALLBACK_IMPLEMENTED == DET_CBK_MAIN                              */
  #endif

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
FUNC(void, DET_CODE) Det_MainFunction (void)
/* PRQA S 0850 --                                                             */
{
  /****************************************************************************/
  /* !Comment         : #if DET type is not DET_NONE                              */
  /****************************************************************************/

  /*  !Comment         :if DET_TYPE_IMPLEMENTED is not DET_NONE                   */
  #if (DET_TYPE_IMPLEMENTED != DET_NONE)

  #if (DET_TYPE_IMPLEMENTED == DET_COM) || (DET_CALLBACK_IMPLEMENTED == DET_CBK_MAIN)

  /* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments    */
  /*              either using AUTOSAR AUTOMATIC definition or by configurable*/
  /*              memory classes                                              */

  /* !Deviation : inhibit MISRA rule [625]: because PC-Lint doesn't           */
  /*              understand the usage of __far keyword in the same way as    */
  /*              the compiler.                                               */
  /*lint -save -vo -e625 -v                                                   */
  /* PRQA S 0850 ++                                                           */

  /*  !Comment        : temporary buffer pointer to point to the error        */
  P2VAR(Det_tstrReportError, AUTOMATIC, DET_VAR_NOINIT) pstrError;

  /* PRQA S 0850 --                                                           */
  /*lint -restore                                                             */
  
  #endif

  #if ( DET_TYPE_IMPLEMENTED == DET_COM )

  /* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments    */
  /*              either using AUTOSAR AUTOMATIC definition or by configurable*/
  /*              memory classes                                              */
  /* PRQA S 0850 ++                                                           */
  /*  !Comment        : temporary buffer to hold the number of retries        */
  VAR(uint16, AUTOMATIC) u16NumberOfTrials;
  /* PRQA S 0850 --                                                           */

  /* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments    */
  /*              either using AUTOSAR AUTOMATIC definition or by configurable*/
  /*              memory classes                                              */
  /* PRQA S 0850 ++                                                           */

  /*  !Comment        : flag to exit from SCI loop                            */
  VAR(boolean, AUTOMATIC) bExitCommLoop;
  /* PRQA S 0850 --                                                           */

  /* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments    */
  /*              either using AUTOSAR AUTOMATIC definition or by configurable*/
  /*              memory classes                                              */
  /* PRQA S 0850 ++                                                           */
  /*  !Comment        : flag to exit from main loop in case of hanging SCI    */
  VAR(boolean, AUTOMATIC) bExitMainLoop = (boolean)FALSE; 
  /* PRQA S 0850 --                                                           */





  #endif /* DET_TYPE_IMPLEMENTED == DET_COM */ 
  


  /*  !Comment       : if current status is DET_STARTED                       */
  if (Det_enuDetStatus == DET_STARTED)
  {

    #if (DET_TYPE_IMPLEMENTED == DET_COM)
    
    while ((Det_u8NumberOfErrors > u8NO_PENDING_ERRORS) &&
               (bExitMainLoop == (boolean)FALSE))

    #elif (DET_TYPE_IMPLEMENTED == DET_RAM)
    
    while (Det_u8NumberOfErrors > u8NO_PENDING_ERRORS)
    
    #endif
    
    {

      #if (DET_TYPE_IMPLEMENTED == DET_COM) || \
          (DET_CALLBACK_IMPLEMENTED == DET_CBK_MAIN)
      
  /* !Deviation : inhibit MISRA rule [619]: because PC-Lint doesn't           */
  /*              understand the usage of __far keyword in the same way as    */
  /*              the compiler.                                               */
  /*lint -save -vo -e619 -v                                                   */

      /*  !Comment       :  get the error at buffer tail position             */
      pstrError = &Det_astrRecordedErrors[Det_u8BufferTail];

  /*lint -restore                                                             */
      #endif

      /*  !Comment       :  if DET_CALLBACK_IMPLEMENTED is DET_CBK_MAIN           */
      #if ( DET_CALLBACK_IMPLEMENTED == DET_CBK_MAIN )
      
      /*  !Comment       :   call callback                                    */
      #if ( DET_TYPE_IMPLEMENTED == DET_COM )
      if (LOC_bCbkSent == (boolean)FALSE)
      {
      #endif
      
        Det_CallBack(pstrError);
      
      #if ( DET_TYPE_IMPLEMENTED == DET_COM )
        LOC_bCbkSent = (boolean)TRUE;
      }
      #endif
      
      #endif


      /*  !Comment       :  if DET_TYPE_IMPLEMENTED is DET_COM                    */
      #if ( DET_TYPE_IMPLEMENTED == DET_COM )

      bExitCommLoop = (boolean)FALSE;
      u16NumberOfTrials = u16RETRIES_RESET;

      /*  !Comment       :   loop while number of trials has not exceeded
                             maximun and data is not sent correctly           */
      while (    (u16NumberOfTrials <= (uint16)DET_SCI_NUM_RETRIES)
                 && (bExitCommLoop == (boolean)FALSE) ) 
      {
        /*  !Comment       :    if SCI is available                           */
        if (Det_ComGetStatus() == SCI_AVAILABLE )
        {

          /* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty
                          arguments either using AUTOSAR AUTOMATIC definition
                          or by configurable memory classes                   */
          /* PRQA S 0850 ++                                                   */
          /* !Deviation : Inhibit MISRA rule [0310]: This pointer casting is
                          mandatory as the SCI service takes pointer to uint8
                          and the required object to send is a structure      */
          /* PRQA S 0310 ++                                                   */
          /*  !Comment       :     if data is sent correctly                  */
          if (Det_ComSend ((P2VAR(uint8, AUTOMATIC, DET_VAR_NOINIT))pstrError,\
                          (uint8)sizeof(Det_tstrReportError)) == E_OK )
          /* PRQA S 0310 --                                                   */
          /* PRQA S 0850 --                                                   */
          {
            /*  !Comment       :      set exit_loop flag to TRUE              */
            bExitCommLoop = (boolean)TRUE;
            
            /*  !Comment       :  if DET_CALLBACK_IMPLEMENTED is DET_CBK_MAIN     */
            #if ( DET_CALLBACK_IMPLEMENTED == DET_CBK_MAIN )

            /*  !Comment       :  Reset the callback sent flag                */
            LOC_bCbkSent = (boolean)FALSE;
            
            #endif

            /* !Deviation : Inhibit MISRA rule [3141,960]: Macro is to be
                      implemented during integration phase                    */
            /* PRQA S 3141 ++                                                 */
            /*lint -save -vo -e960 -v                                         */
            /* !Comment: Enter critical region 001                            */
            SchM_Enter_Det(DET_ACCESS_001);
            /*lint -restore                                                   */
            /* PRQA S 3141 --                                                 */

            /* GSCSW-DET-SRC-001-0001                                         */
            /*  !Comment       :   decrement the global number_of_errors      */
            Det_u8NumberOfErrors--;      

            /* !Deviation : Inhibit MISRA rule [3141,960]: Macro is to be
                      implemented during integration phase                    */
            /* PRQA S 3141 ++                                                 */
            /*lint -save -vo -e960 -v                                         */
            /*  !Comment       :  leave critical region 001                   */
            SchM_Exit_Det(DET_ACCESS_001);
            /*lint -restore                                                   */
            /* PRQA S 3141 --                                                 */

            if (Det_u8BufferTail < u8LOG_ARRAY_LIMIT)
            {

              /* GSCSW-DET-SRC-001-0005                                       */
              /*  !Comment       :    increment buffer tail                   */
              Det_u8BufferTail++;
            }
              
            /*  !Comment      :  if DET_TYPE_MANAGEMENT is set to DET_FIFO_TYPE    */
            #if ( DET_TYPE_MANAGEMENT == DET_FIFO_TYPE )
              
            else
            {
              /*  !Comment       :     Recycle the buffer tail                */
              Det_u8BufferTail = u8BUFFER_START;
            }

            #endif
 
          }
        }

        /*  !Comment       :        increment number of SCI trials            */
        u16NumberOfTrials++;

      }
      
      /* !Comment       :   if SCI exceeded NumberOfTrials                    */
      if (bExitCommLoop == (boolean)FALSE )
      {
        /* !Comment     :   set the exit main loop to true to exit main loop  */
        bExitMainLoop = (boolean)TRUE;
      }


      #endif /* DET_TYPE_IMPLEMENTED == DET_COM */    
  

      /*  !Comment       :  if DET_TYPE_IMPLEMENTED is DET_RAM                    */
      #if ( DET_TYPE_IMPLEMENTED == DET_RAM )


      /* !Deviation : Inhibit MISRA rule [3141,960]: Macro is to be
                      implemented during integration phase                    */
      /* PRQA S 3141 ++                                                       */
      /*lint -save -vo -e960 -v                                               */
      /* !Comment: Enter critical region 001                                  */
      SchM_Enter_Det(DET_ACCESS_001);
      /*lint -restore                                                         */
      /* PRQA S 3141 --                                                       */

      /*  !Comment       :   decrement the global number_of_errors            */
      Det_u8NumberOfErrors--;      
        
      /* !Deviation : Inhibit MISRA rule [3141,960]: Macro is to be
                      implemented during integration phase                    */
      /* PRQA S 3141 ++                                                       */
      /*lint -save -vo -e960 -v                                               */
      /*  !Comment       :  leave critical region 001                         */
      SchM_Exit_Det(DET_ACCESS_001);
      /*lint -restore                                                         */
      /* PRQA S 3141 --                                                       */

      if (Det_u8BufferTail < u8LOG_ARRAY_LIMIT)
      {

        /*  !Comment       :    increment buffer tail                         */
        Det_u8BufferTail++;
      }
              
      /*  !Comment      :  if DET_TYPE_MANAGEMENT is set to DET_FIFO_TYPE          */
      #if ( DET_TYPE_MANAGEMENT == DET_FIFO_TYPE )
              
      else
      {
        /*  !Comment       :     Recycle the buffer tail                      */
        Det_u8BufferTail = u8BUFFER_START;
      }

      #endif
      
      #endif

    }
  }
 
  #endif /* #if DET_TYPE_IMPLEMENTED != DET_NONE */

}

#endif /* DET_MAINFUNCTION_IMPLEMENTED == STD_ON */




/* If version information API is supported                                    */
/* !Trace_To: GSCSW-DET-SDD-001-0060                                          */
#if (DET_VERSION_INFO_API == STD_ON)

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
/******************************************************************************/
/* !Description: This service returns the version information of this module  */
/* !Trace_To: GSCSW-DET-SDD-001-0058, GSCSW-DET-SDD-001-0059                  */
/******************************************************************************/
FUNC(void, DET_CODE) Det_GetVersionInfo
              (
               /* !Comment: Pointer to where to store the version information */
               /*           of this module                                    */
               /* !Size: 1 Std_VersionInfoType element                        */
               P2VAR(Std_VersionInfoType, AUTOMATIC, DET_APPL_DATA) versioninfo
              )
/* PRQA S 0850 --                                                             */
{
    /* !Pseudo: Set versioninfo's vendor ID field to DET_VENDOR_ID            */
    /* !Pseudo: Set versioninfo's module ID field to DET_MODULE_ID            */
    /* !Pseudo: Set versioninfo's SW major version field to                   */
    /* !Pseudo: DET_SW_MAJOR_VERSION                                          */
    /* !Pseudo: Set versioninfo's SW minor version field to                   */
    /* !Pseudo: DET_SW_MINOR_VERSION                                          */
    /* !Pseudo: Set versioninfo's SW patch level field to                     */
    /* !Pseudo: DET_SW_PATCH_VERSION                                          */

    if (versioninfo != NULL_PTR)
    {
        versioninfo->vendorID = DET_VENDOR_ID;
        versioninfo->moduleID = (uint16)DET_MODULE_ID;
        versioninfo->instanceID = 0;
        versioninfo->sw_major_version = (uint8)DET_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = (uint8)DET_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = (uint8)DET_SW_PATCH_VERSION;
    }
}
                               
#endif /* (DET_VERSION_INFO_API == STD_ON) */



/******************************************************************************/
/* !Comment: End of memory mapping for DET code segment                       */
/******************************************************************************/
/* !Deviation:  Inhibit MISRA rule [750] because local non referenced macro is*/
/*              according to AUTOSAR specifications                           */
/* !Deviation:  Inhibit MISRA rule [760] because redundant macro defined is   */
/*              according to AUTOSAR specifications                           */
/* !Deviation:  Inhibit MISRA rule [961] because multiple use of #define is   */
/*              according to AUTOSAR specifications                           */
/* !Deviation:  Inhibit MISRA rule [537] because repeated include for Memmap  */
/*              is according to AUTOSAR specifications                        */
/* !Deviation:  Inhibit MISRA rule [960] because use of #undef is according to*/
/*              AUTOSAR specifications                                        */
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v                             */
/* !Deviation : inhibit MISRA rule [5087]: because #include is used after a   */
/*              non preprocessor directives                                   */
/* PRQA S 5087 L1                                                             */
#define DET_STOP_SEC_CODE
/* !Trace_To: GSCSW-DET-SDD-001-0061                                          */
#include "MemMap.h"
/* PRQA L:L1                                                                  */
/*lint -restore                                                               */


/* !Deviation : Inhibit MISRA rule [551]: Det_bOverflowOccured is a required
                flag to indicate the buffer overflow occurence. Required by
                GSCSW-DET-SRS-003-0019 & SIQ_3,4                              */
/*lint -save -vo -e551 -v                                                     */

/* !Deviation:  Inhibit MISRA rule [766] because inclusion of Memmap is
                according to AUTOSAR specifications and MemMap is unconfigured*/
/*lint -vo -e766 -v                                                           */

/* Note that the above lint inhibtions should be opened and not closed by
   a restore instruction in order to be able to inhibit this error message.   */
