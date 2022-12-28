/******************************************************************************/
/*! \file LinSM.c
*
* \brief
*   This file  containing the implementation of the Component APIs            */
/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : LinSM                                                   */
/* !Description     : LinSM is a part of the Communication service layer,     */
/*                    and it's responsible for:                               */  
/*                    -Switching Schedule tables when requested by Upper layer*/
/*                      - GotoSleep and Wakeup Handling.                      */
/*                      - Notification to the upper layer when new state entered*/
/*                                                                            */
/* !File            : LinSM.c                                                 */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2009 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* PRQA S 0292 ++                                                             */
/* $Archive::   Y:/Prod_01/DEI Team room/archives/E95110014/02_Modules/21_Lin$*/
/* $Revision::   1.17     $$Author::   AELSOHBY        $$Date::   Jun 25 2014 19$*/
/* PRQA S 0288 --                                                             */
/* PRQA S 0292 --                                                             */
/******************************************************************************/
/* PRQA S 0838 EOF                                                            */
/* !Deviation : Inhibit MISRA rule [0838]: Memmap.h is used for assignation   */
/*              memory segments in the linker                                 */
/* !Deviation : Inhibit MISRA rule [0838]: The header file included are       */
/*              required by the requirement.                                  */
/* PRQA S 0862 EOF                                                            */
/* !Deviation : Inhibit MISRA rule [0862]: Multiple inclusion prevention      */
/*              macros solves multiple/re-inclusions issues                   */

#include "Std_Types.h"
#include "Compiler.h"
#include "LinIf.h"
#include "LinIf_Main.h"
#include "Lin_GeneralTypes.h"
#include "ComM.h"
#include "ComM_BusSm.h"
#include "ComStack_Types.h"
#include "BswM.h"


#include "LinSM.h"
#include "LinSM_Cbk.h"
#include "SchM_LinSM.h"
#include "BswM_LinSM.h"

#if (LinSM_bDEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/******************************************************************************/
/****************************** Version Checking ******************************/
/******************************************************************************/

#define u8C_SW_MAJOR_VERSION    (2)
#define u8C_SW_MINOR_VERSION    (0)
/******************************************************************************/
/* Intra-Module Checking - Module Header Files and Module C Files             */
/******************************************************************************/
#if (u8C_SW_MAJOR_VERSION != LINSM_SW_MAJOR_VERSION)
    #error Incompatible LinSM SW major version between C & H files.
#endif

#if (u8C_SW_MINOR_VERSION != LINSM_SW_MINOR_VERSION)
    #error Incompatible LinSM SW minor version between C & H files.
#endif

#if(LinSM_bINTER_MOD_VER_CHECK == STD_ON)
/******************************************************************************/
/* Inter-Module Checking - Module Header Files and Module C Files             */
/******************************************************************************/
/* ------------------------------- Std Types -------------------------------- */
#if (LINSM_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION)
    #error Std AR RELEASE MAJOR VERSION is not compatible with LinSM AR \
           RELEASE MAJOR VERSION.
#endif
#if (LINSM_AR_RELEASE_MINOR_VERSION < STD_AR_RELEASE_MINOR_VERSION)
    #error Std AR RELEASE MINOR VERSION is not compatible with LinSM AR \
           RELEASE MINOR VERSION.
#endif
/* -------------------------------- Memmap ---------------------------------- */
#if (LINSM_AR_RELEASE_MAJOR_VERSION != MEM_AR_RELEASE_MAJOR_VERSION)
    #error Memmap AR RELEASE MAJOR VERSION is not compatible with LinSM AR \
           RELEASE MAJOR VERSION.
#endif
#if (LINSM_AR_RELEASE_MINOR_VERSION < MEM_AR_RELEASE_MINOR_VERSION)
    #error Memmap AR RELEASE MINOR VERSION is not compatible with LinSM AR \
           RELEASE MINOR VERSION.
#endif

/* ---------------------------- Platform Types ------------------------------ */
#if (LINSM_AR_RELEASE_MAJOR_VERSION != PLATFORM_AR_RELEASE_MAJOR_VERSION)
    #error Platform AR RELEASE MAJOR VERSION is not compatible with LinSM AR \
           RELEASE MAJOR VERSION.
#endif
#if (LINSM_AR_RELEASE_MINOR_VERSION < PLATFORM_AR_RELEASE_MINOR_VERSION)
    #error Platform AR RELEASE MINOR VERSION is not compatible with LinSM AR \
           RELEASE MINOR VERSION.
#endif

/* ------------------------------- Compiler --------------------------------- */
#if (LINSM_AR_RELEASE_MAJOR_VERSION != COMPILER_AR_RELEASE_MAJOR_VERSION)
    #error Compiler AR RELEASE MAJOR VERSION is not compatible with LinSM AR \
           RELEASE MAJOR VERSION.
#endif
#if (LINSM_AR_RELEASE_MINOR_VERSION < COMPILER_AR_RELEASE_MINOR_VERSION)
    #error Compiler AR RELEASE MINOR VERSION is not compatible with LinSM AR \
           RELEASE MINOR VERSION.
#endif

/* ---------------------------- ComStack Types ------------------------------ */
#if (LINSM_AR_RELEASE_MAJOR_VERSION != COMSTACKTYPE_AR_RELEASE_MAJOR_VERSION)
    #error ComStack Types AR RELEASE MAJOR VERSION is not compatible with LinSM\
           AR RELEASE MAJOR VERSION.
#endif
#if (LINSM_AR_RELEASE_MINOR_VERSION < COMSTACKTYPE_AR_RELEASE_MINOR_VERSION)
    #error ComStack Types AR RELEASE MINOR VERSION is not compatible with LinSM\
           AR RELEASE MINOR VERSION.
#endif

/* ------------------------------- LinIf ------------------------------------ */
#if (LINSM_AR_RELEASE_MAJOR_VERSION != LINIF_AR_RELEASE_MAJOR_VERSION)
    #error LinIf AR RELEASE MAJOR VERSION is not compatible with LinSM AR \
           RELEASE MAJOR VERSION.
#endif
#if (LINSM_AR_RELEASE_MINOR_VERSION != LINIF_AR_RELEASE_MINOR_VERSION)
    #error LinIf AR RELEASE MINOR VERSION is not compatible with LinSM AR \
           RELEASE MINOR VERSION.
#endif
/* ------------------------------- BswM ------------------------------------- */
#if (LINSM_AR_RELEASE_MAJOR_VERSION != BSWM_AR_RELEASE_MAJOR_VERSION)
    #error BswM AR RELEASE MAJOR VERSION is not compatible with LinSM AR \
           RELEASE MAJOR VERSION.
#endif
#if (LINSM_AR_RELEASE_MINOR_VERSION < BSWM_AR_RELEASE_MINOR_VERSION)
    #error BswM AR RELEASE MINOR VERSION is not compatible with LinSM AR \
           RELEASE MINOR VERSION.
#endif
/* ------------------------------- ComM ------------------------------------- */
#if (LINSM_AR_RELEASE_MAJOR_VERSION != COMM_AR_RELEASE_MAJOR_VERSION)
    #error ComM AR RELEASE MAJOR VERSION is not compatible with LinSM AR \
           RELEASE MAJOR VERSION.
#endif
#if (LINSM_AR_RELEASE_MINOR_VERSION != COMM_AR_RELEASE_MINOR_VERSION)
    #error ComM AR RELEASE MINOR VERSION is not compatible with LinSM AR \
           RELEASE MINOR VERSION.
#endif
/* -------------------------------- DEM ------------------------------------- */
#if (LINSM_AR_RELEASE_MAJOR_VERSION != DEM_AR_RELEASE_MAJOR_VERSION)
    #error Dem AR RELEASE MAJOR VERSION is not compatible with LinSM AR \
           RELEASE MAJOR VERSION.
#endif
#if (LINSM_AR_RELEASE_MINOR_VERSION < DEM_AR_RELEASE_MINOR_VERSION)
    #error Dem AR RELEASE MINOR VERSION is not compatible with LinSM AR \
           RELEASE MINOR VERSION.
#endif
/* -------------------------------- DET ------------------------------------- */
#if (LinSM_bDEV_ERROR_DETECT == STD_ON)
#if (LINSM_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION)
    #error Det AR RELEASE MAJOR VERSION is not compatible with LinSM AR \
           RELEASE MAJOR VERSION.
#endif
#if (LINSM_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION)
    #error Det AR RELEASE MINOR VERSION is not compatible with LinSM AR \
           RELEASE MINOR VERSION.
#endif
#endif/* LinSM_bDEV_ERROR_DETECT == STD_ON */
#endif /* LinSM_bINTER_MOD_VER_CHECK == STD_ON */

/* PRQA S 0850 EOF                                                            */
/* !Deviation : Inhibit MISRA rule [0850]: Memclass is defined as an empty    */
/*              macro                                                         */
/* PRQA S 4700 EOF                                                            */
/* !Deviation : Inhibit MISRA rule [4700]: Deviation in the number of stubs   */
/*              calling is required by the specification                      */
/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
/*! \Description  Type used to save the mode requested.                       */
/*! \Range   LINSM_NONE,LINSM_WAKEUP,LINSM_GOTOSLEEP                          */
/******************************************************************************/
typedef enum {
  LINSM_NONE,
  LINSM_WAKEUP,
  LINSM_GOTOSLEEP
} tenuRequestModeType;
/*****************************************************************************/
/* DATA DEFINITION                                                           */
/*****************************************************************************/
/* PRQA S 5087 L1                                                             */
#define LINSM_START_SEC_VAR_8
#include "Memmap.h"
/* PRQA L:L1                                                                  */
/*! \Description  Parameter used to report the State of LinSM state machine. */
/*! \Range    LinSM_u8UNINIT,LinSM_u8INIT                                    */
/*! \Trace_To LinSM-CDD-0027(0)                                              */
VAR(LinSM_tu8StateType, LINSM_VAR) LinSM_u8eState = LinSM_u8UNINIT;

/*! \Description  Parameter used to report the communication mode (Sub-State 
                  machine) for each LIN Channel                               */
/*! \Range    LINSM_FULL_COM,LINSM_NO_COM                                     */
VAR(LinSM_ModeType, LINSM_VAR) LinSM_au8eChannelMode[LinSM_u16MAX_CHANNEL_NUM];

/*! \Description  Flag set when a mode is requested when the function 
                  LinSM_RequestComMode is called for the selected network.   */
/*! \Range   LINSM_NONE,LINSM_WAKEUP,LINSM_GOTOSLEEP                         */
static VAR(tenuRequestModeType, LINSM_VAR) LinSM_audtModeRequested[LinSM_u16MAX_CHANNEL_NUM];
/* PRQA S 5087 L1                                                             */
#define LINSM_STOP_SEC_VAR_8
#include "Memmap.h"
/*****************************************************************************/
/* LOCAL DATA DEFINITION                                                     */
/*****************************************************************************/
#define LINSM_START_SEC_VAR_BOOLEAN
#include "Memmap.h"
/* PRQA L:L1                                                                  */
/*! \Description  Flag set when a Change of Schedule is requested when the 
                  function LinSM_ScheduleRequest is called for the 
                   selected network.                                         */
/*! \Range    TRUE,FALSE                                                     */
static VAR(boolean, LINSM_VAR) LinSM_abScheduleRequested[LinSM_u16MAX_CHANNEL_NUM];

/*! \Description  Flag set when LinIf_ScheduleRequest returns with E_NOT_OK  */
/*! \Range    TRUE,FALSE                                                     */
static VAR(boolean, LINSM_VAR) LinSM_abScheduleRefused[LinSM_u16MAX_CHANNEL_NUM];
/* PRQA S 5087 L1                                                             */
#define LINSM_STOP_SEC_VAR_BOOLEAN
#include "Memmap.h"
/*****************************************************************************/
#define LINSM_START_SEC_VAR_8
#include "Memmap.h"
/* PRQA L:L1                                                                  */
/*! \Description  Variable to hold the Current schedule table requested by 
                  ComM module.                                               */
/*! \Range    0..255                                                         */
static VAR(uint8, LINSM_VAR) LinSM_au8CurrentSchedule[LinSM_u16MAX_CHANNEL_NUM];

/*! \Description  Variable to hold the old schedule table, to be used if the 
                  schedule request timer is expired.                         */
/*! \Range    0..255                                                         */
static VAR(uint8, LINSM_VAR) LinSM_au8OldSchedule[LinSM_u16MAX_CHANNEL_NUM];
/* PRQA S 5087 L1                                                             */
#define LINSM_STOP_SEC_VAR_8
#include "Memmap.h"
/*****************************************************************************/
#define LINSM_START_SEC_VAR_16
#include "Memmap.h"
/* PRQA L:L1                                                                  */
/*! \Description  GotoSleep or Wakeup Requests Timeout Timer for each channel*/
/*! \Range    0..65535                                                       */
static VAR(uint16, LINSM_VAR) LinSM_au16RequestTimer[LinSM_u16MAX_CHANNEL_NUM];

/*! \Description  Schedule Request Timeout Timer for each channel.           */
/*! \Range    0..65535                                                       */
static VAR(uint16, LINSM_VAR) LinSM_au16ScheduleTimer[LinSM_u16MAX_CHANNEL_NUM];
/* PRQA S 5087 L1                                                             */
#define LINSM_STOP_SEC_VAR_16
#include "Memmap.h"
/*****************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                */
/*****************************************************************************/
#define LINSM_START_SEC_CODE
#include "Memmap.h"
/* PRQA L:L1                                                                  */
/******************************************************************************/
/*! \Description    Funtion to handle the transition to the LINSM_NO_COM mode.\n
    \param[in]      udtNetwork      The LIN Channel network ID                \n
                    \Range          0 .. 255                                  \n
    \return         Standard return value                                     \n
*******************************************************************************/
static FUNC(Std_ReturnType, LINSM_CODE) udtGotoSleep(
   NetworkHandleType udtNetwork);
/*****************************************************************************/
/*! \Description    Funtion to handle the transition to the LINSM_FULL_COM mode.\n
    \param[in]      udtNetwork      The LIN Channel network ID               \n
                    \Range          0 .. 255                                 \n
    \return         Standard return value                                    \n
******************************************************************************/
static FUNC(Std_ReturnType, LINSM_CODE) udtWakeupProcess(
   NetworkHandleType udtNetwork);  

/******************************************************************************/
/* LOCAL FUNCTIONS DEFINITION                                                 */
/******************************************************************************/

static FUNC(Std_ReturnType, LINSM_CODE) udtGotoSleep(
   /*! \param  udtNetwork    The LIN Channel network ID                      */
   /*! \Range   0..255                                                       */
   NetworkHandleType udtNetwork)
{
  VAR(Std_ReturnType, AUTOMATIC) udtReturnValue = E_NOT_OK;
  VAR(Std_ReturnType, AUTOMATIC) udtLinIFRequestReturn;
  VAR(ComM_ModeType, AUTOMATIC)  udtComMMode;
  VAR(uint8, AUTOMATIC)          u8ChannelIndex;
  
  (void)LinIf_udtGetChannelIndexById(udtNetwork, &u8ChannelIndex);
    
  /*! Check if the Channel Sub-State is FULL_COM else return E_NOT_OK        */
  /*! \Trace_To LinSM-CDD-5035(0), LinSM-CDD-0118(0)                         */
  if(LinSM_au8eChannelMode[u8ChannelIndex] == LINSM_FULL_COM )
  {
    /*!Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented       */
    /*              during integration phase                                    */
    /* PRQA S 3141 ++                                                           */
    /* PRQA S 3138 ++                                                           */
    /*! Call the function LinIf_GotoSleep                                    */
    SchM_Enter_LinSM_LINSM_ACCESS_000();
    /* PRQA S 3141 --                                                           */
    /* PRQA S 3138 --                                                           */
    /*************************************************************************/
    /*! Set the Request timer by the configuration parameter Confirmation 
        timeout for the specified network before calling 
        the LinIf_GotoSleep function                                         */
    /*! \Trace_To  LinSM-CDD-5047(0)                                         */
    LinSM_au16RequestTimer[u8ChannelIndex] = 
            LinSM_akstreChannelReference[u8ChannelIndex].u16ConfirmationTimeout;
    /*************************************************************************/
    /*!Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented   */
    /*              during integration phase                               */
    /* PRQA S 3141 ++                                                      */
    /* PRQA S 3138 ++                                                      */
    SchM_Exit_LinSM_LINSM_ACCESS_000();    
    /* PRQA S 3141 --                                                      */
    /* PRQA S 3138 --                                                      */
    /*! Set the gotoSleep Request flag for the selected network.             */
    /*! \Trace_To LinSM-CDD-5056(0)                                          */
    LinSM_audtModeRequested[u8ChannelIndex] = LINSM_GOTOSLEEP;    
       
    /*! \Trace_To  LinSM-CDD-0047(0)                                         */
    /*! \Trace_To  LinSM-CDD-5086(0)                                         */
    udtLinIFRequestReturn = LinIf_GotoSleep(udtNetwork);
    if(udtLinIFRequestReturn == E_OK)
    {
      /*! if the LinIf_GotoSleep returns with E_OK then returns 
          with E_OK                                                          */
      udtReturnValue = E_OK;
    }
    else
    {
      /*!Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented   */
      /*              during integration phase                               */
      /* PRQA S 3141 ++                                                      */
      /* PRQA S 3138 ++                                                      */
      SchM_Enter_LinSM_LINSM_ACCESS_000();
      /* PRQA S 3141 --                                                      */
      /* PRQA S 3138 --                                                      */
      /***********************************************************************/
      /*! if the LinIf_GotoSleep returns with E_NOT_OK then returns 
          with E_NOT_OK                                                      */
      /*! Reset the Request timer if the LinIf returns with E_NOT_OK         */
      LinSM_au16RequestTimer[u8ChannelIndex] = 0;
      /***********************************************************************/
      /*!Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented   */
      /*              during integration phase                               */
      /* PRQA S 3141 ++                                                      */
      /* PRQA S 3138 ++                                                      */
      SchM_Exit_LinSM_LINSM_ACCESS_000();
      /* PRQA S 3141 --                                                      */
      /* PRQA S 3138 --                                                      */
      /*! Reset the GotoSleep request flag                                   */
      LinSM_audtModeRequested[u8ChannelIndex] = LINSM_NONE;
      /*! Notify the ComM and BswM by the current mode                       */
      udtComMMode = COMM_FULL_COMMUNICATION;
      ComM_BusSM_ModeIndication( udtNetwork ,&udtComMMode );
      BswM_LinSM_CurrentState(udtNetwork,LINSM_FULL_COM);
      /*! if LinIf_GotoSleep return with NOT_OK then return with E_NOT_OK    */
      /*! \Trace_To LinSM-CDD-0048(0)                                        */    
            
    }
  }
  else
  {
    /*! if the requested mode is the same as the current mode then return 
        E_NOT_OK and LinIF shouldn't be called                               */
    /*! \Trace_To LinSM-CDD-5037(0)                                          */
      /*! Reset the GotoSleep request flag                                   */
    LinSM_audtModeRequested[u8ChannelIndex] = LINSM_NONE;
      /*! Notify the ComM and BswM by the current mode                       */
    udtComMMode = COMM_NO_COMMUNICATION;
    ComM_BusSM_ModeIndication( udtNetwork ,&udtComMMode );
    BswM_LinSM_CurrentState(udtNetwork,LINSM_NO_COM);
      /*! if LinIf_GotoSleep return with NOT_OK then return with E_NOT_OK    */
      /*! \Trace_To LinSM-CDD-0048(0)                                        */    
  }
    
  return udtReturnValue;
}

/*****************************************************************************/

static FUNC(Std_ReturnType, LINSM_CODE) udtWakeupProcess(
   /*! \param  udtNetwork    The LIN Channel network ID                      */
   /*! \Range   0..255                                                       */
   NetworkHandleType udtNetwork)
{
  VAR(Std_ReturnType, AUTOMATIC) udtReturnValue = E_NOT_OK;
  VAR(Std_ReturnType, AUTOMATIC) udtLinIFRequestReturn;
  VAR(ComM_ModeType, AUTOMATIC)  udtComMMode;
  VAR(uint8, AUTOMATIC)          u8ChannelIndex;
  
  (void)LinIf_udtGetChannelIndexById(udtNetwork, &u8ChannelIndex);
  
  if(LinSM_au8eChannelMode[u8ChannelIndex] == LINSM_NO_COM)
  {
    /*! if the Sleep is supported for the specified channel then call the
        LinIf_Wakeup function                                                */
    /*! \Trace_To LinSM-CDD-0118(0)                        */
    /*!Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented   */
    /*              during integration phase                               */
    /* PRQA S 3141 ++                                                      */
    /* PRQA S 3138 ++                                                      */
    SchM_Enter_LinSM_LINSM_ACCESS_000();
    /* PRQA S 3141 --                                                      */
    /* PRQA S 3138 --                                                      */
    /*************************************************************************/
    /*! Set the Request timer by the configuration parameter Confirmation
        timeout for the specified network                                    */
    /*! \Trace_To  LinSM-CDD-5048(0)                                         */
    LinSM_au16RequestTimer[u8ChannelIndex] = 
             LinSM_akstreChannelReference[u8ChannelIndex].u16ConfirmationTimeout;
    /*************************************************************************/
    /*!Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented   */
    /*              during integration phase                               */
    /* PRQA S 3141 ++                                                      */
    /* PRQA S 3138 ++                                                      */
    SchM_Exit_LinSM_LINSM_ACCESS_000();                
    /* PRQA S 3141 --                                                      */
    /* PRQA S 3138 --                                                      */
    /*! Set the Wakup request flag LinSM_audtModeRequested by LINSM_WAKEUP for
        the specified Channel                                                */
    /*! \Trace_To LinSM-CDD-5057(0)                                          */                            
    LinSM_audtModeRequested[u8ChannelIndex] = LINSM_WAKEUP;
    /*! call LinIf_Wakeup                                                    */
    /*! \Trace_To LinSM-CDD-5064(0)                                          */
    /*! \Trace_To LinSM-CDD-5086(0)                                          */
    udtLinIFRequestReturn = LinIf_Wakeup(udtNetwork);
    if(udtLinIFRequestReturn == E_OK)
    {
      udtReturnValue = E_OK;
    }
    else
    {
      /*! if the LinIf_Wakeup returns with E_NOT_OK then returns with 
          E_NOT_OK                                                           */
      /*!Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented   */
      /*              during integration phase                               */
      /* PRQA S 3141 ++                                                      */
      /* PRQA S 3138 ++                                                      */
      SchM_Enter_LinSM_LINSM_ACCESS_000();
      /* PRQA S 3141 --                                                      */
      /* PRQA S 3138 --                                                      */
      /***********************************************************************/
      /*! Reset the Request timer when the LinIf returns with E_NOT_OK       */
      LinSM_au16RequestTimer[u8ChannelIndex] = 0;
      /***********************************************************************/
      /*!Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented   */
      /*              during integration phase                               */
      /* PRQA S 3141 ++                                                      */
      /* PRQA S 3138 ++                                                      */
      SchM_Exit_LinSM_LINSM_ACCESS_000();    
      /* PRQA S 3141 --                                                      */
      /* PRQA S 3138 --                                                      */
      LinSM_audtModeRequested[u8ChannelIndex] = LINSM_NONE;
      /*! Notify the ComM and BswM by the current mode                       */
      udtComMMode = COMM_NO_COMMUNICATION;
      ComM_BusSM_ModeIndication( udtNetwork ,&udtComMMode );
      BswM_LinSM_CurrentState(udtNetwork,LINSM_NO_COM);
      /*!  If the LinIf_Wakeup returns E_NOT_OK return with E_NOT_OK         */
      /*! \Trace_To LinSM-CDD-0063(0)                                        */
    }                
  }
  else
  {
    /*! if the requested mode is the same as the current mode then 
        return E_NOT_OK                                                      */                    
    /*! \Trace_To LinSM-CDD-5045(0)                                          */ 

    LinSM_audtModeRequested[u8ChannelIndex] = LINSM_NONE;
      /*! Notify the ComM and BswM by the current mode                       */
    udtComMMode = COMM_FULL_COMMUNICATION;
    ComM_BusSM_ModeIndication( udtNetwork ,&udtComMMode );
    BswM_LinSM_CurrentState(udtNetwork,LINSM_FULL_COM);
  }
    
  return udtReturnValue;
} 
/*****************************************************************************/
 
/*****************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                */
/*****************************************************************************/

FUNC(void, LINSM_CODE) LinSM_Init(void)
{
  VAR(uint16, AUTOMATIC) u16Loop;
    
  /*! Initialize the LinSM state to Initialize state                         */
  /*! \Trace_To LinSM-CDD-0029(0)                                            */
  LinSM_u8eState = LinSM_u8INIT;
    
  /*! Initialize all the Lin Channel Sub-State to LISM_NO_COM mode           */
  for(u16Loop=0; u16Loop < LinSM_u16MAX_CHANNEL_NUM ; u16Loop++ )
  {
    /*! Initialize the Channel mode by the LINSM_NO_COM                    */
    /*! \Trace_To LinSM-CDD-0030(0), LinSM-CDD-0032(0)                       */
    LinSM_au8eChannelMode[u16Loop] = LINSM_NO_COM;
    /*! Initiaze all the global variables to their default values            */
    /*! \Trace_To LinSM-CDD-0031(0)                                          */
    LinSM_audtModeRequested[u16Loop] = LINSM_NONE;
    LinSM_abScheduleRequested[u16Loop] = FALSE;
    LinSM_abScheduleRefused[u16Loop] = FALSE;
    LinSM_au8CurrentSchedule[u16Loop] = 0;
    LinSM_au8OldSchedule[u16Loop] = 0;
  }
    
}
/*****************************************************************************/

FUNC(Std_ReturnType, LINSM_CODE) LinSM_ScheduleRequest( 
    NetworkHandleType udtNetwork, 
    LinIf_SchHandleType udtSchedule )
{
  VAR(Std_ReturnType, AUTOMATIC) udtReturnValue = E_NOT_OK;
  VAR(Std_ReturnType, AUTOMATIC) udtLinIFRequestReturn;
  VAR(Std_ReturnType, AUTOMATIC) udtLinIfChannelIDReturn;
  VAR(uint8, AUTOMATIC)          u8ChannelIndex;
  
  udtLinIfChannelIDReturn = LinIf_udtGetChannelIndexById(udtNetwork, &u8ChannelIndex);
    
  #if (LinSM_bDEV_ERROR_DETECT == STD_ON)
  /*! if the LinSM is not Initialized then Det should be called by 
      LINSM_E_UNINIT                                                         */
  /*! \Trace_To   LinSM-CDD-0097(0)                                          */
  if(LinSM_u8eState == LinSM_u8UNINIT)
  {
    LinSM_vidREPORT_DET_ERROR(LinSM_u8SCHEDULEREQUEST_ID,LINSM_E_UNINIT);
  }
  else if(udtLinIfChannelIDReturn == E_NOT_OK)
  {
    /*! if the Network index is invalid then Det should be called 
        by LINSM_E_NONEXISTENT_NETWORK                                       */
    /*! \Trace_To   LinSM-CDD-0095(0)                                        */    
    LinSM_vidREPORT_DET_ERROR(LinSM_u8SCHEDULEREQUEST_ID,
                              LINSM_E_NONEXISTENT_NETWORK);
  }
  else if( (udtSchedule >  LinSM_akstreChannelReference[u8ChannelIndex].u8MaxScheduleEntries )
          || (udtSchedule == 0) )
  {
    /*! if the Schedule index is invalid then Det should be called 
        by LINSM_E_PARAMETER                                                 */
    /*! \Trace_To   LinSM-CDD-0096(0)                                        */    
    LinSM_vidREPORT_DET_ERROR(LinSM_u8SCHEDULEREQUEST_ID,LINSM_E_PARAMETER);
  }
  else
  {    
  #endif /*(LinSM_bDEV_ERROR_DETECT == STD_ON)*/
        
    LinSM_au8OldSchedule[u8ChannelIndex] = LinSM_au8CurrentSchedule[u8ChannelIndex];
    /*! if there is no Schedule is requested on the same channel 
        else return with E_NOT_OK                                            */
    /*! \Trace_To LinSM-CDD-0098(0)                                          */    
    if(LinSM_abScheduleRequested[u8ChannelIndex] == FALSE)
    {
        /*! if the Channel Sub-State is not equal to LINSM_FULL_COM 
            E_NOT_OK should be returned                                        */
        /*! \Trace_To LinSM-CDD-0099(0),LinSM-CDD-5028(0)                      */
      if(LinSM_au8eChannelMode[u8ChannelIndex] == LINSM_FULL_COM)
      {
          /*!Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented   */
          /*              during integration phase                               */
          /* PRQA S 3141 ++                                                      */
          /* PRQA S 3138 ++                                                      */
        SchM_Enter_LinSM_LINSM_ACCESS_000();
          /* PRQA S 3141 --                                                      */
          /* PRQA S 3138 --                                                      */
          /*********************************************************************/
          /*! Set the Schedule timer by the configuration parameter Confirmation 
              timeout for the specified network                                */
          /*! \Trace_To  LinSM-CDD-5049(0)                                     */
        LinSM_au16ScheduleTimer[u8ChannelIndex] = 
        LinSM_akstreChannelReference[u8ChannelIndex].u16ConfirmationTimeout;
          /*********************************************************************/
          /*!Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented   */
          /*              during integration phase                               */
          /* PRQA S 3141 ++                                                      */
          /* PRQA S 3138 ++                                                      */
        SchM_Exit_LinSM_LINSM_ACCESS_000();
          /* PRQA S 3141 --                                                      */
          /* PRQA S 3138 --                                                      */
          /*! Set the Schedule request flag by TRUE                            */
          /*! \Trace_To LinSM-CDD-5040(0)                                      */
        LinSM_abScheduleRequested[u8ChannelIndex] = TRUE;
          /*! Forward the Schedule request to LinIf                            */
          /*! \Trace_To LinSM-CDD-0052(0)                                      */
          /*! \Trace_To LinSM-CDD-5085(0)                                      */
        udtLinIFRequestReturn = LinIf_ScheduleRequest(udtNetwork,udtSchedule);
            
          /*! if the LinIf request returns with E_OK return E_OK ,
              else return E_NOT_OK                                             */
        if (udtLinIFRequestReturn == E_OK)
        {
            /*! if the LinIf_ScheduleRequest returns with E_OK then 
                return with E_OK                                               */
            /*! \Trace_To LinSM-CDD-0053(0)                                    */
          udtReturnValue = E_OK;
        }
        else
        {
            /*! Clear the Schedule request flag                                */
          LinSM_abScheduleRequested[u8ChannelIndex] = FALSE;
            /*!Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented   */
            /*              during integration phase                               */
            /* PRQA S 3141 ++                                                      */
            /* PRQA S 3138 ++                                                      */
          SchM_Enter_LinSM_LINSM_ACCESS_000();
            /* PRQA S 3141 --                                                      */
            /* PRQA S 3138 --                                                      */
            /*******************************************************************/
            /*! if the LinIf returns with NOT_OK then reset the Schedule timer.*/
          LinSM_au16ScheduleTimer[u8ChannelIndex] = 0 ;
            /*******************************************************************/
            /*!Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented   */
            /*              during integration phase                               */
            /* PRQA S 3141 ++                                                      */
            /* PRQA S 3138 ++                                                      */
          SchM_Exit_LinSM_LINSM_ACCESS_000();
            /* PRQA S 3141 --                                                      */
            /* PRQA S 3138 --                                                      */
            /*! Set the Schedule Refused flag by TRUE                          */
            /*! \Trace_To LinSM-CDD-5042(0)                                    */
          LinSM_abScheduleRefused[u8ChannelIndex] = TRUE;
            /*! if the LinIf_ScheduleRequest returns with E_NOT_OK  
                then return with E_NOT_OK                                      */
            /*! \Trace_To LinSM-CDD-0054(0)                                    */
        }
              
      }
      else
      {
          /*! if the Channel Sub-State is NO_COM return E_NOT_OK               */
      }
    }
    else
    {
        /*! if there is another request is in process for the same LIN 
            Channel return E_NOT_OK                                            */
    }
  #if (LinSM_bDEV_ERROR_DETECT == STD_ON)        
  }
  #endif
    
  return udtReturnValue;
}
/******************************************************************************/

FUNC(Std_ReturnType, LINSM_CODE) LinSM_GetCurrentComMode( 
    NetworkHandleType udtNetwork, 
    ComM_ModeType* udtpMode 
){

  VAR(Std_ReturnType, AUTOMATIC) udtReturnValue = E_NOT_OK;
  VAR(Std_ReturnType, AUTOMATIC) udtLinIfChannelIDReturn;
  VAR(uint8, AUTOMATIC)          u8ChannelIndex;
  
  udtLinIfChannelIDReturn = LinIf_udtGetChannelIndexById(udtNetwork, &u8ChannelIndex);
  
  /*! if the LinSM is not Initialized then Det should be called by 
      LINSM_E_UNINIT                                                         */
  /*! \Trace_To   LinSM-CDD-0108(0)                                          */
  if(LinSM_u8eState == LinSM_u8UNINIT)
  {
    /*! if the LIN Channel State is UNINIT return COMM_NO_COMMUNICATION      */
    /*! \Trace_To   LinSM-CDD-0111(0)                                        */        
    *udtpMode = COMM_NO_COMMUNICATION;
  #if (LinSM_bDEV_ERROR_DETECT == STD_ON)
    LinSM_vidREPORT_DET_ERROR(LinSM_u8GETCURRENTMODE_ID,LINSM_E_UNINIT);
    
  }
  else if(udtLinIfChannelIDReturn == E_NOT_OK)
  {
    /*! if the Network index is invalid then Det should be called 
        by LINSM_E_NONEXISTENT_NETWORK                                       */
    /*! \Trace_To   LinSM-CDD-0106(0)                                        */    
    LinSM_vidREPORT_DET_ERROR(LinSM_u8GETCURRENTMODE_ID,
                              LINSM_E_NONEXISTENT_NETWORK);
  }
  else if(udtpMode == NULL_PTR)
  {
    /*! if the udtpMode is invalid (NULL pointer) then Det should be 
        called by LINSM_E_PARAMETER_POINTER                                  */
    /*! \Trace_To   LinSM-CDD-0107(0)                                        */    
    LinSM_vidREPORT_DET_ERROR(LinSM_u8GETCURRENTMODE_ID,
                              LINSM_E_PARAMETER_POINTER);
  #endif                                  
  }
  else
  {
    if(LinSM_au8eChannelMode[u8ChannelIndex] == LINSM_FULL_COM)
    {
      /*! if the LIN Channel Sub-State is FULL_COM return 
          COMM_FULL_COMMUNICATION                                            */
      /*! \Trace_To   LinSM-CDD-0110(0)                                      */
      *udtpMode = COMM_FULL_COMMUNICATION;
      udtReturnValue = E_OK;
    }
    else
    {
      /*! else the LIN Channel Sub-State is NO_COM return 
          COMM_NO_COMMUNICATION                                              */
      /*! \Trace_To   LinSM-CDD-0109(0)                                      */    
      *udtpMode = COMM_NO_COMMUNICATION;
      udtReturnValue = E_OK;
    }
  }
    
  return udtReturnValue;
}
/******************************************************************************/

FUNC(Std_ReturnType, LINSM_CODE) LinSM_RequestComMode( 
    NetworkHandleType udtNetwork, 
    ComM_ModeType udtMode 
)
{
  VAR(Std_ReturnType, AUTOMATIC) udtReturnValue = E_NOT_OK;
  VAR(ComM_ModeType, AUTOMATIC)  udtComMMode;
  VAR(Std_ReturnType, AUTOMATIC) udtLinIfChannelIDReturn;
  VAR(uint8, AUTOMATIC)          u8ChannelIndex;
  
  udtLinIfChannelIDReturn = LinIf_udtGetChannelIndexById(udtNetwork, &u8ChannelIndex);
  #if (LinSM_bDEV_ERROR_DETECT == STD_ON)

  if(LinSM_u8eState == LinSM_u8UNINIT)
  {        
    /*! if the LinSM is not Initialized then Det should be called by 
        LINSM_E_UNINIT                                                       */
    /*! \Trace_To   LinSM-CDD-0115(0)                                        */
    LinSM_vidREPORT_DET_ERROR(LinSM_u8REQUESTCOMMODE_ID,LINSM_E_UNINIT);    
  }
  else if( udtLinIfChannelIDReturn == E_NOT_OK)
  {
    /*! if the Network index is invalid then Det should be called 
        by LINSM_E_NONEXISTENT_NETWORK                                       */
    /*! \Trace_To   LinSM-CDD-0113(0)                                        */    
    LinSM_vidREPORT_DET_ERROR(LinSM_u8REQUESTCOMMODE_ID,
                              LINSM_E_NONEXISTENT_NETWORK);
  }
  else
  {
  #endif
    /*! Check if there is no another request is in process                   */
    /*! \Trace_To LinSM-CDD-5053(1), LinSM-CDD-0049(0)                       */
    if( LinSM_audtModeRequested[u8ChannelIndex] == LINSM_NONE )
    {
      switch (udtMode)
      {    
        case COMM_NO_COMMUNICATION:
        udtReturnValue = udtGotoSleep(udtNetwork);
        break;
                
        case COMM_FULL_COMMUNICATION:
        udtReturnValue = udtWakeupProcess(udtNetwork);
        break;
                  
        case COMM_SILENT_COMMUNICATION:
          /*! if the requested mode is COMM_SILENT_COMMUNICATION return
              with E_NOT_OK                                                    */
          /*! \Trace_To LinSM-CDD-0117(0)                                      */
        if(LinSM_au8eChannelMode[u8ChannelIndex] == LINSM_NO_COM)
        {
          udtComMMode = COMM_NO_COMMUNICATION;
          ComM_BusSM_ModeIndication( udtNetwork ,&udtComMMode );
          BswM_LinSM_CurrentState(udtNetwork,LINSM_NO_COM );                        
        }
        else
        {
          udtComMMode = COMM_FULL_COMMUNICATION;
          ComM_BusSM_ModeIndication( udtNetwork ,&udtComMMode );
          BswM_LinSM_CurrentState( udtNetwork, LINSM_FULL_COM );
        }
        break;
                  
        default:
          /*! if the udtMode is invalid then Det should be called by
              LINSM_E_PARAMETER                                                */
          /*! \Trace_To   LinSM-CDD-0114(0)                                    */
        #if (LinSM_bDEV_ERROR_DETECT == STD_ON)                    
        LinSM_vidREPORT_DET_ERROR(LinSM_u8REQUESTCOMMODE_ID,
                                    LINSM_E_PARAMETER);
        #endif                            
        break;
      }
    }
    else
    {
        /*! Decline the request as another request is in process               */
      if(LinSM_audtModeRequested[udtNetwork] == LINSM_GOTOSLEEP)
      {
              /*! notify the ComM and BswM by the current mode                 */
              /*! \Trace_To LinSM-CDD-0071(0)                                  */
        udtComMMode = COMM_FULL_COMMUNICATION;                        
        ComM_BusSM_ModeIndication( udtNetwork, &udtComMMode );
              /*! \Trace_To LinSM-CDD-0072(0)                                  */    
        BswM_LinSM_CurrentState( udtNetwork, LINSM_FULL_COM );
      }
      else
      {
              /*! notify the ComM and BswM by the current mode                 */
              /*! \Trace_To LinSM-CDD-0071(0)                                  */
        udtComMMode = COMM_NO_COMMUNICATION;
        ComM_BusSM_ModeIndication( udtNetwork , &udtComMMode );
              /*! \Trace_To LinSM-CDD-0072(0)                                  */
        BswM_LinSM_CurrentState( udtNetwork , LINSM_NO_COM);
      }
    }
         
  #if (LinSM_bDEV_ERROR_DETECT == STD_ON)
  }
  #endif
    
  return udtReturnValue;    
}
/******************************************************************************/

FUNC(void, LINSM_CODE) LinSM_MainFunction( void)
{
  VAR(ComM_ModeType, AUTOMATIC)     udtComMMode;
  VAR(uint16, AUTOMATIC)            u16Loop;
  VAR(NetworkHandleType, AUTOMATIC) udtNetworkID;
    
  #if (LinSM_bDEV_ERROR_DETECT == STD_ON)
  if(LinSM_u8eState == LinSM_u8UNINIT)
  {        
    /*! if the LinSM is not Initialized then Det should be called by 
        LINSM_E_UNINIT                                                       */
    /*! \Trace_To   LinSM-CDD-0115(0)                                        */
    /*! \Trace_To   LinSM-CDD-0121(0)                                        */
    LinSM_vidREPORT_DET_ERROR(LinSM_u8MAINFUNCTION_ID,LINSM_E_UNINIT);    
  }
  else
  {
  #endif
    for(u16Loop = 0 ; u16Loop < LinSM_u16MAX_CHANNEL_NUM ; u16Loop++)
    {
        /*!Deviation : Inhibit MISRA rule [3736]: To be fixed                  */
        /*               in the next release                                   */
        /* PRQA S 3746 ++ */
      udtNetworkID = LinIf_udtGetChannelIdByIndex(u16Loop);
        /* PRQA S 3746 -- */
        /*! if the Schedule table request was refused then notify the 
           BSWM by the old Schedule table                                      */
        /*! \Trace_To LinSM-CDD-5043(0)                                        */
      if(LinSM_abScheduleRefused[u16Loop] == TRUE)
      {
        LinSM_abScheduleRefused[u16Loop] = FALSE;
        BswM_LinSM_CurrentSchedule( udtNetworkID,
                                      LinSM_au8OldSchedule[u16Loop] );
      }

      if(LinSM_abScheduleRequested[u16Loop] == TRUE)
      {
          /*!Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented   */
          /*              during integration phase                               */
          /* PRQA S 3141 ++                                                      */
          /* PRQA S 3138 ++                                                      */
        SchM_Enter_LinSM_LINSM_ACCESS_000();
          /* PRQA S 3141 --                                                      */
          /* PRQA S 3138 --                                                      */
          /*********************************************************************/
        if(LinSM_au16ScheduleTimer[u16Loop] > 0 )
        {
            /*! Decrement the Schedule Request Timer                           */
            /*! \Trace_To LinSM-CDD-0065(0), LinSM-CDD-5070(0)                 */
          LinSM_au16ScheduleTimer[u16Loop]--; 
            /*******************************************************************/
            /*!Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented   */
            /*              during integration phase                               */
            /* PRQA S 3141 ++                                                      */
            /* PRQA S 3138 ++                                                      */
          SchM_Exit_LinSM_LINSM_ACCESS_000();
            /* PRQA S 3141 --                                                      */
            /* PRQA S 3138 --                                                      */
        }
        else if ( (LinSM_akstreChannelReference[u16Loop].u16ConfirmationTimeout != 0) )
        {
            /*******************************************************************/
            /*!Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented   */
            /*              during integration phase                               */
            /* PRQA S 3141 ++                                                      */
            /* PRQA S 3138 ++                                                      */
          SchM_Exit_LinSM_LINSM_ACCESS_000();
            /* PRQA S 3141 --                                                      */
            /* PRQA S 3138 --                                                      */
            #if (LinSM_bDEV_ERROR_DETECT == STD_ON)
            /*! Timeout occured report LINSM_E_CONFIRMATION_TIMEOUT to DET     */
            /*! \Trace_To LinSM-CDD-0070(1)                                    */
          LinSM_vidREPORT_DET_ERROR( LinSM_u8MAINFUNCTION_ID,
                                      LINSM_E_CONFIRMATION_TIMEOUT);                    
            #endif                           
            /*! Timeout Expired then:
                - Set the Schedule request flag by False
                - notify the BswM by the old Schedule table                    */
            /*! \Trace_To LinSM-CDD-5052(1)                                    */    
          LinSM_abScheduleRequested[u16Loop] = FALSE;
            /*! \Trace_To LinSM-CDD-0057(0)                                    */
          BswM_LinSM_CurrentSchedule( udtNetworkID,
                                        LinSM_au8OldSchedule[u16Loop]);
        }
        else
        {
            /*! Do nothing the Confirmation timeout is equal to 0              */
            /*! Trace _To LinSM-CDD-0073(0)                                    */
            /*!Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented   */
            /*              during integration phase                               */
            /* PRQA S 3141 ++                                                      */
            /* PRQA S 3138 ++                                                      */
          SchM_Exit_LinSM_LINSM_ACCESS_000();
            /* PRQA S 3141 --                                                      */
            /* PRQA S 3138 --                                                      */
        }
      }
              
      if( LinSM_audtModeRequested[u16Loop] != LINSM_NONE ) 
      {
          /*!Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented   */
          /*              during integration phase                               */
          /* PRQA S 3141 ++                                                      */
          /* PRQA S 3138 ++                                                      */
        SchM_Enter_LinSM_LINSM_ACCESS_000();
          /* PRQA S 3141 --                                                      */
          /* PRQA S 3138 --                                                      */
          /*********************************************************************/
        if(LinSM_au16RequestTimer[u16Loop] > 0)
        {
            /*! Decrement the Request Timer                                    */
            /*! \Trace_To LinSM-CDD-0065(0), LinSM-CDD-5069(0)                 */
          LinSM_au16RequestTimer[u16Loop]--;
            /*******************************************************************/
            /*!Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented   */
            /*              during integration phase                               */
            /* PRQA S 3141 ++                                                      */
            /* PRQA S 3138 ++                                                      */
          SchM_Exit_LinSM_LINSM_ACCESS_000();
            /* PRQA S 3141 --                                                      */
            /* PRQA S 3138 --                                                      */
        }
        else if( (LinSM_akstreChannelReference[u16Loop].u16ConfirmationTimeout != 0) )
        {
            /*******************************************************************/
            /*!Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented   */
            /*              during integration phase                               */
            /* PRQA S 3141 ++                                                      */
            /* PRQA S 3138 ++                                                      */
          SchM_Exit_LinSM_LINSM_ACCESS_000();
            /* PRQA S 3141 --                                                      */
            /* PRQA S 3138 --                                                      */
            #if (LinSM_bDEV_ERROR_DETECT == STD_ON)
            /*! Timeout occured report LINSM_E_CONFIRMATION_TIMEOUT to DET     */
            /*! \Trace_To LinSM-CDD-0070(1)                                    */    
          LinSM_vidREPORT_DET_ERROR( LinSM_u8MAINFUNCTION_ID,
                                       LINSM_E_CONFIRMATION_TIMEOUT);
            #endif                             
            /*! \Trace_To LinSM-CDD-5051(1)                                    */
            
          if(LinSM_audtModeRequested[u16Loop] == LINSM_GOTOSLEEP)
          {
              /*! notify the ComM and BswM by the current mode                 */
              /*! \Trace_To LinSM-CDD-0071(0)                                  */
            udtComMMode = COMM_FULL_COMMUNICATION;                        
            ComM_BusSM_ModeIndication( udtNetworkID, &udtComMMode );
              /*! \Trace_To LinSM-CDD-0072(0)                                  */    
            BswM_LinSM_CurrentState( udtNetworkID, LINSM_FULL_COM );
            LinSM_audtModeRequested[u16Loop] = LINSM_NONE;
          }
          else
          {
              /*! notify the ComM and BswM by the current mode                 */
              /*! \Trace_To LinSM-CDD-0071(0)                                  */
            udtComMMode = COMM_NO_COMMUNICATION;
            ComM_BusSM_ModeIndication( udtNetworkID , &udtComMMode );
              /*! \Trace_To LinSM-CDD-0072(0)                                  */
            BswM_LinSM_CurrentState( udtNetworkID , LINSM_NO_COM); 
            LinSM_audtModeRequested[u16Loop] = LINSM_NONE;
          }
        }
        else
        {
            /*! Do nothing the Confirmation timeout is equal to 0              */
            /*! \Trace_To LinSM-CDD-0073(0)                                    */
            /*!Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented   */
            /*              during integration phase                               */
            /* PRQA S 3141 ++                                                      */
            /* PRQA S 3138 ++                                                      */
          SchM_Exit_LinSM_LINSM_ACCESS_000();
            /* PRQA S 3141 --                                                      */
            /* PRQA S 3138 --                                                      */
        }
      }
    }
  #if (LinSM_bDEV_ERROR_DETECT == STD_ON)
  }
  #endif
}

/******************************************************************************/

FUNC(void, LINSM_CODE) LinSM_ScheduleRequestConfirmation( 
    NetworkHandleType udtNetwork, 
    LinIf_SchHandleType udtSchedule 
)
{
  VAR(uint8, AUTOMATIC)          u8ChannelIndex;
  VAR(Std_ReturnType, AUTOMATIC) udtLinIfChannelIDReturn;
  
  udtLinIfChannelIDReturn = LinIf_udtGetChannelIndexById(udtNetwork, &u8ChannelIndex);
  
  #if (LinSM_bDEV_ERROR_DETECT == STD_ON)
  if(LinSM_u8eState == LinSM_u8UNINIT)
  {        
    /*! if the LinSM is not Initialized then Det should be called by 
        LINSM_E_UNINIT                                                        */
    /*! \Trace_To   LinSM-CDD-0124(1)                                         */ 
    LinSM_vidREPORT_DET_ERROR(LinSM_u8SCHEDULEREQCNF_ID,LINSM_E_UNINIT);    
  }
  else if(udtLinIfChannelIDReturn == E_NOT_OK)
  {
    /*! if the Network index is invalid then Det should be called 
        by LINSM_E_NONEXISTENT_NETWORK                                       */
    /*! \Trace_To   LinSM-CDD-0123(0)                                        */
    LinSM_vidREPORT_DET_ERROR(LinSM_u8SCHEDULEREQCNF_ID,
                              LINSM_E_NONEXISTENT_NETWORK);
  }
  else
  {
  #endif
    /*! if the Request is not yet expired                                    */
    if(LinSM_abScheduleRequested[u8ChannelIndex] == TRUE)
    {
        /*! Set the current Schedule by the confirmed schedule                 */
      LinSM_au8CurrentSchedule[u8ChannelIndex] = udtSchedule;
        /*! Clear the schedule request flag                                    */
        /*! \Trace_To LinSM-CDD-5050(0)                                        */
      LinSM_abScheduleRequested[u8ChannelIndex] = FALSE;
        /*!Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented   */
        /*              during integration phase                               */
        /* PRQA S 3141 ++                                                      */
        /* PRQA S 3138 ++                                                      */
      SchM_Enter_LinSM_LINSM_ACCESS_000();
        /* PRQA S 3141 --                                                      */
        /* PRQA S 3138 --                                                      */
        /***********************************************************************/
        /*! clear the schedule request timer                                   */
        /*! \Trace_To LinSM-CDD-5050(0),LinSM-CDD-0069(0)                      */
      LinSM_au16ScheduleTimer[u8ChannelIndex] = 0;
        /***********************************************************************/
        /*!Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented   */
        /*              during integration phase                               */
        /* PRQA S 3141 ++                                                      */
        /* PRQA S 3138 ++                                                      */
      SchM_Exit_LinSM_LINSM_ACCESS_000();
        /* PRQA S 3141 --                                                      */
        /* PRQA S 3138 --                                                      */
        /*! \Trace_To LinSM-CDD-5066(0)                                        */
      BswM_LinSM_CurrentSchedule(udtNetwork,udtSchedule);
    }
    else if (LinSM_au8CurrentSchedule[u8ChannelIndex] == udtSchedule)
    {
        /*! if the LinIf confirms a schedule switch without a preceding 
            call to request new schedule table then notify the BswM by the 
            current schedule table                                             */
        /*! \Trace_To LinSM-CDD-5044(0)                                        */  
      BswM_LinSM_CurrentSchedule(udtNetwork, udtSchedule);    
    }
    else
    {
        /*! The request is expired then do nothing                             */
    }
  #if (LinSM_bDEV_ERROR_DETECT == STD_ON)
  }
  #endif
}

/******************************************************************************/

FUNC(void, LINSM_CODE) LinSM_GotoSleepConfirmation( 
    NetworkHandleType udtNetwork, 
    boolean bSuccess 
)
{
  VAR(ComM_ModeType, AUTOMATIC)  udtComMMode;
  VAR(uint8, AUTOMATIC)          u8ChannelIndex;
  VAR(Std_ReturnType, AUTOMATIC) udtLinIfChannelIDReturn;
  
  udtLinIfChannelIDReturn = LinIf_udtGetChannelIndexById(udtNetwork, &u8ChannelIndex);
  
  #if (LinSM_bDEV_ERROR_DETECT == STD_ON)
  if(LinSM_u8eState == LinSM_u8UNINIT)
  {        
    /*! if the LinSM is not Initialized then Det should be called by 
        LINSM_E_UNINIT                                                       */
    /*! \Trace_To   LinSM-CDD-0127(0)                                        */
    LinSM_vidREPORT_DET_ERROR(LinSM_u8GOTOSLEEPCNF_ID,LINSM_E_UNINIT);    
  }
  else if(udtLinIfChannelIDReturn == E_NOT_OK)
  {
    /*! if the Network index is invalid then Det should be called 
        by LINSM_E_NONEXISTENT_NETWORK                                       */
    /*! \Trace_To   LinSM-CDD-0126(0)                                        */    
    LinSM_vidREPORT_DET_ERROR(LinSM_u8GOTOSLEEPCNF_ID,
                              LINSM_E_NONEXISTENT_NETWORK);
  }
  else
  {
  #endif
    /*! if the GotoSleep request is not yet expired                          */
    if(LinSM_audtModeRequested[u8ChannelIndex] == LINSM_GOTOSLEEP)
    {
        /*! set the GotoSleep request flag by False                            */
      LinSM_audtModeRequested[u8ChannelIndex] = LINSM_NONE;
        /*!Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented   */
        /*              during integration phase                               */
        /* PRQA S 3141 ++                                                      */
        /* PRQA S 3138 ++                                                      */
      SchM_Enter_LinSM_LINSM_ACCESS_000();
        /* PRQA S 3141 --                                                      */
        /* PRQA S 3138 --                                                      */
        /***********************************************************************/
        /*! Clear the Request timer                                            */
        /*! \Trace_To LinSM-CDD-0069(0)                                        */
      LinSM_au16RequestTimer[u8ChannelIndex] = 0;
        /***********************************************************************/
        /*!Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented   */
        /*              during integration phase                               */
        /* PRQA S 3141 ++                                                      */
        /* PRQA S 3138 ++                                                      */
      SchM_Exit_LinSM_LINSM_ACCESS_000();
        /* PRQA S 3141 --                                                      */
        /* PRQA S 3138 --                                                      */
       
      if(bSuccess == TRUE)
      {
          /*! if the bSuccess is True then set the Channel Sub-State by
              LINSM_NO_COM                                                   */
          /*! \Trace_To LinSM-CDD-0050(0),LinSM-CDD-5025(0)                    */    
        LinSM_au8eChannelMode[u8ChannelIndex] = LINSM_NO_COM;
          /*! \Trace_To LinSM-CDD-5026(0)                                      */
        udtComMMode = COMM_NO_COMMUNICATION;
        ComM_BusSM_ModeIndication( udtNetwork ,&udtComMMode );
          /*! \Trace_To LinSM-CDD-5027(0)                                      */
        BswM_LinSM_CurrentState(udtNetwork,LINSM_NO_COM);
        /*! \Trace_To LinSM-CDD-5090(0)                                      */
        #if (LinSM_bLIN_TRNCVR_USED == STD_ON)
          /*! Set the LinTrcv mode by Standby if the 
              bTrncvrPassiveMode is TRUE Sleep mode is set otherwise           */
          /*! \Trace_To LinSM-CDD-5029(1)                                      */
        if(LinSM_akstreChannelReference[u8ChannelIndex].bTrncvrPassiveMode == TRUE)
        {
            /*! \Trace_To LinSM-CDD-5087(0)                                    */
          (void)LinIf_SetTrcvMode(udtNetwork, LINTRCV_TRCV_MODE_STANDBY);
        }
        else
        {
            /*! \Trace_To LinSM-CDD-5087(0)                                    */
          (void)LinIf_SetTrcvMode(udtNetwork, LINTRCV_TRCV_MODE_SLEEP);
        }   
        #endif        
      }
      else
      {
          /*! else the bSuccess is False then set the Channel Sub-State
              by LINSM_NO_COM                                                */
          /*! \Trace_To LinSM-CDD-0051(0)                                      */
        LinSM_au8eChannelMode[u8ChannelIndex] = LINSM_FULL_COM;
          /*! \Trace_To LinSM-CDD-5060(0)                                      */
        udtComMMode = COMM_FULL_COMMUNICATION;
        ComM_BusSM_ModeIndication( udtNetwork ,&udtComMMode );
          /*! \Trace_To LinSM-CDD-5061(0)                                      */
        BswM_LinSM_CurrentState(udtNetwork,LINSM_FULL_COM);
        #if (LinSM_bLIN_TRNCVR_USED == STD_ON)
          /*! \Trace_To LinSM-CDD-5063(1)                                      */
          /*! \Trace_To LinSM-CDD-5087(0)                                      */
        (void)LinIf_SetTrcvMode(udtNetwork, LINTRCV_TRCV_MODE_NORMAL);
        #endif
      }
    }
    else
    {
        /*! The request is expired then do nothing                             */          
    }
  #if (LinSM_bDEV_ERROR_DETECT == STD_ON)
  }    
  #endif
}
/******************************************************************************/

FUNC(void, LINSM_CODE) LinSM_WakeupConfirmation( 
    NetworkHandleType udtNetwork, 
    boolean bSuccess 
)
{
  VAR(ComM_ModeType, AUTOMATIC)  udtComMMode;
  VAR(uint8, AUTOMATIC)          u8ChannelIndex;
  VAR(Std_ReturnType, AUTOMATIC) udtLinIfChannelIDReturn;
 
  udtLinIfChannelIDReturn = LinIf_udtGetChannelIndexById(udtNetwork, &u8ChannelIndex);
    
  #if (LinSM_bDEV_ERROR_DETECT == STD_ON)
  if(LinSM_u8eState == LinSM_u8UNINIT)
  {        
    /*! if the LinSM is not Initialized then Det should be called by 
        LINSM_E_UNINIT                                                       */
    /*! \Trace_To   LinSM-CDD-0131(0)                                        */
    LinSM_vidREPORT_DET_ERROR(LinSM_u8WAKEUPCNF_ID,LINSM_E_UNINIT);    
  }
  else if(udtLinIfChannelIDReturn == E_NOT_OK)
  {
    /*! if the Network index is invalid then Det should be called 
        by LINSM_E_NONEXISTENT_NETWORK                                       */
    /*! \Trace_To   LinSM-CDD-0130(0)                                        */    
    LinSM_vidREPORT_DET_ERROR(LinSM_u8WAKEUPCNF_ID,
                              LINSM_E_NONEXISTENT_NETWORK);
  }
  else
  {
  #endif
    /*! if the GotoSleep request is not yet expired                          */
    if(LinSM_audtModeRequested[u8ChannelIndex] == LINSM_WAKEUP)
    {
        /*! set the GotoSleep request flag by False                            */
      LinSM_audtModeRequested[u8ChannelIndex] = LINSM_NONE;
        /*!Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented   */
        /*              during integration phase                               */
        /* PRQA S 3141 ++                                                      */
        /* PRQA S 3138 ++                                                      */
      SchM_Enter_LinSM_LINSM_ACCESS_000();
        /* PRQA S 3141 --                                                      */
        /* PRQA S 3138 --                                                      */
        /***********************************************************************/
        /*! Clear the Request timer                                            */
        /*! \Trace_To LinSM-CDD-0069(0)                                        */
      LinSM_au16RequestTimer[u8ChannelIndex] = 0;
        /***********************************************************************/
        /*!Deviation : Inhibit MISRA rule [3141]: Macro is to be implemented   */
        /*              during integration phase                               */
        /* PRQA S 3141 ++                                                      */
        /* PRQA S 3138 ++                                                      */
      SchM_Exit_LinSM_LINSM_ACCESS_000();            
        /* PRQA S 3141 --                                                      */
        /* PRQA S 3138 --                                                      */
      if(bSuccess == TRUE)
      {
          /*! if the wakeup notification is received then set the 
              Sub-State to LINSM_FULL_COM                                    */
          /*! \Trace_To LinSM-CDD-5067(0)                                      */            
        LinSM_au8eChannelMode[u8ChannelIndex] = LINSM_FULL_COM;
          /*! \Trace_To LinSM-CDD-5032(0)                                      */
        udtComMMode = COMM_FULL_COMMUNICATION;
        ComM_BusSM_ModeIndication( udtNetwork ,&udtComMMode );
          /*! \Trace_To LinSM-CDD-5033(0)                                      */
        BswM_LinSM_CurrentState(udtNetwork,LINSM_FULL_COM);
        #if (LinSM_bLIN_TRNCVR_USED == STD_ON)
          /*! \Trace_To LinSM-CDD-5034(1)                                      */
        (void)LinIf_SetTrcvMode(udtNetwork, LINTRCV_TRCV_MODE_NORMAL);       
        #endif        
      }
      else
      {
          /*! \Trace_To LinSM-CDD-5068(0)                                      */
        LinSM_au8eChannelMode[u8ChannelIndex] = LINSM_NO_COM;
          /*! \Trace_To LinSM-CDD-5058(0)                                      */
        udtComMMode = COMM_NO_COMMUNICATION;
        ComM_BusSM_ModeIndication( udtNetwork ,&udtComMMode );
          /*! \Trace_To LinSM-CDD-5059(0)                                      */
        BswM_LinSM_CurrentState(udtNetwork,LINSM_NO_COM );
        /*! \Trace_To LinSM-CDD-5091(0)                                      */
        #if (LinSM_bLIN_TRNCVR_USED == STD_ON)
          /*! Set the LinTrcv mode by Standby if the 
              bTrncvrPassiveMode is TRUE Sleep mode is set otherwise           */
          /*! \Trace_To LinSM-CDD-5062(1)                                      */
        if(LinSM_akstreChannelReference[u8ChannelIndex].bTrncvrPassiveMode == TRUE)
        {
            /*! \Trace_To LinSM-CDD-5088(0)                                    */
          (void)LinIf_SetTrcvMode(udtNetwork, LINTRCV_TRCV_MODE_STANDBY);
        }
        else
        {
            /*! \Trace_To LinSM-CDD-5088(0)                                    */
          (void)LinIf_SetTrcvMode(udtNetwork, LINTRCV_TRCV_MODE_SLEEP);
        } 
        #endif        
      }
    }
    else
    {
        /*! The request is expired then do nothing                             */
    }
  #if (LinSM_bDEV_ERROR_DETECT == STD_ON)    
  }
  #endif
}
/******************************************************************************/
/* PRQA S 5087 L1                                                             */
#define LINSM_STOP_SEC_CODE
#include "Memmap.h"
/* PRQA L:L1                                                                  */
/*-------------------------------- end of file -------------------------------*/

