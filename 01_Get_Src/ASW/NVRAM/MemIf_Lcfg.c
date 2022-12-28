
  /*****************************************************************************/
  /*                                                                           */
  /* !Layer           : ECU Abstraction Layer                                  */
  /*                                                                           */
  /* !Component       : MemIf                                                  */
  /* !Description     : AUTOSAR Memory Abstraction Interface component   */
  /*                                                                           */
  /* !Module          : MemIf_Cfg                                              */
  /* !Description     : Memory Abstraction Interface configuration module      */
  /*                                                                           */
  /* !File            : MemIf_Lcfg.c                                           */
  /*                                                                           */
  /* !Target          : All                                                    */
  /*                                                                           */
  /* !Vendor          : Valeo                                                  */
  /*                                                                           */
  /* Coding language  : C                                                      */
  /*                                                                           */
  /*       CAUTION:                                                            */
  /*           This version is available for re-use only,                      */
  /*           validation is under user responsibility                         */
  /*                                                                           */
  /* COPYRIGHT 2009 VALEO                                                      */
  /* all rights reserved                                                       */
  /*                                                                           */
  /*****************************************************************************/
  /*       THIS FILE IS CREATED AUTOMATICALY BY CONFIGURATION TOOLS            */
  /*****************************************************************************/
  /* PVCS Information                                                          */
  /* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by          */
  /*              configuration management tool (PVCS)                         */
  /* PRQA S 0288 ++                                                            */
  /* $Header:   P:/EBx_V46/LDA/REF/modules/NVRAM/MemIf_Lcfg.c_v   1.1   19 Sep 2014 17:10:14   wbouach  $
  ******************************************************************************/
  /* PRQA S 0288 --                                                            */
  /*****************************************************************************/
  /* MODIFICATION LOG :                                                        */
  /*****************************************************************************/
  /* TFR        : None                                                          */
/* Rev        : 1.3            R1.0.0   AR4.0                               */
/* Done by    : M.Hegazy                                  Date : 14/09/11 */
/* Description: - Removed "BASIS" word from the file.                    */
/******************************************************************************/
  /* TFR        : None                                                          */
/* Rev        : 1.2.0            R1.0.0   AR4.0                               */
/* Done by    : M.Hegazy                                  Date : 11/09/11 */
/* Description: - Updated after running VNR.                    */
/******************************************************************************/
  /* TFR        : None                                                          */
/* Rev        : 1.1.0            R1.0.0   AR4.0                               */
/* Done by    : M.Hegazy                                  Date : 11/09/11 */
/* Description: - Updated after solving peer review bugs.                    */
/******************************************************************************/
  /* TFR        : None                                                          */
  /* Rev        : 1.0.0            R1.0.0   AR4.0                               */
  /* Done by    : M.Hegazy                                  Date : 10/05/11 */
  /* Description: - Initial version for AUTOSAR Release 4.0.                    */
  /******************************************************************************/

  /*-- Include component internals --*/
  #include "MemIf.h"
  
/*===========================================================================*/
/*=== Array link time attributes ============================================*/
/*===========================================================================*/
/* !Trace_To  :  GSCSW-MemIf-SDD-001-0114                                  */

#if (MEMIF_NUMBER_OF_DEVICES > 1U)

/* inhibit message number 750 because local macro used on MemMap not         */
/* referenced                                                                */
/* inhibit message number 760 because Redundant macro used on MemMap         */
/* inhibit message number 961 because multiple use of #define for MemMap     */
/* inhibit message number 537 because Repeated include for MemMap            */
/* inhibit message number 960 because use of '#undef' is discouraged         */
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -v                            */

#define MEMIF_START_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h" /*## Open unknown size constant section ##               */
/*lint -restore                                                              */

/* !Parameter: MemIf_SetModeApiConfiguration container - vendor specific    
               Wrapping table of MemIf SetMode API to corresponding memory
               abstraction module SetMode APIs.                              */
/* !Size     : MEMIF_NUMBER_OF_DEVICES                                       */
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments     */
/*              either using AUTOSAR AUTOMATIC definition or by configurable */
/*              memory classes                                               */
/* PRQA S 0850 ++                                                            */
CONST(MemIf_tpfvidSetModeApi, MEMIF_CFG_CONST) 
      MemIf_kapfudteSetModeApiCfg[MEMIF_NUMBER_OF_DEVICES] =
/* PRQA S 0850 --                                                            */      
{
  
    
  /*-- Memory Device 0 --*/
    Fee_SetMode
};

/* !Parameter: MemIf_GetStatusApiConfiguration container - vendor specific    
               Wrapping table of MemIf GetStatus API to corresponding memory
               abstraction module GetStatus APIs.                            */
/* !Size     : MEMIF_NUMBER_OF_DEVICES                                       */
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments     */
/*              either using AUTOSAR AUTOMATIC definition or by configurable */
/*              memory classes                                               */
/* PRQA S 0850 ++                                                            */
CONST(MemIf_tpfenuGetStatusApi, MEMIF_CFG_CONST) 
      MemIf_kapfudteGetStatusApiCfg[MEMIF_NUMBER_OF_DEVICES] =
/* PRQA S 0850 --                                                            */      
{
   
  /*-- Memory Device 0 --*/
    Fee_GetStatus   
};

/* !Parameter: MemIf_GetJobResultApiConfiguration container - vendor specific    
               Wrapping table of MemIf GetJobResult API to corresponding memory
               abstraction module GetJobResult APIs.                         */
/* !Size     : MEMIF_NUMBER_OF_DEVICES                                       */
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments     */
/*              either using AUTOSAR AUTOMATIC definition or by configurable */
/*              memory classes                                               */
/* PRQA S 0850 ++                                                            */
CONST(MemIf_tpfenuGetJobResultApi, 
      MEMIF_CFG_CONST) MemIf_kapfudteGetJobResuApiCfg[MEMIF_NUMBER_OF_DEVICES] =
/* PRQA S 0850 --                                                            */      
{
   
  /*-- Memory Device 0 --*/
    Fee_GetJobResult
};

/* !Parameter: MemIf_ReadApiConfiguration container - vendor specific    
               Wrapping table of MemIf Read API to corresponding memory
               abstraction module Read APIs.                                 */
/* !Size     : MEMIF_NUMBER_OF_DEVICES                                       */
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments     */
/*              either using AUTOSAR AUTOMATIC definition or by configurable */
/*              memory classes                                               */
/* PRQA S 0850 ++                                                            */
CONST(MemIf_tpfudtReadApi, MEMIF_CFG_CONST) 
      MemIf_kapfudteReadApiCfg[MEMIF_NUMBER_OF_DEVICES] =
/* PRQA S 0850 --                                                            */      
{
   
  /*-- Memory Device 0 --*/
    Fee_Read   
};

/* !Parameter: MemIf_WriteApiConfiguration container - vendor specific    
               Wrapping table of MemIf Write API to corresponding memory
               abstraction module Write APIs.                                */
/* !Size     : MEMIF_NUMBER_OF_DEVICES                                       */
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments     */
/*              either using AUTOSAR AUTOMATIC definition or by configurable */
/*              memory classes                                               */
/* PRQA S 0850 ++                                                            */
CONST(MemIf_tpfudtWriteApi, MEMIF_CFG_CONST) 
      MemIf_kapfudteWriteApiCfg[MEMIF_NUMBER_OF_DEVICES] =
/* PRQA S 0850 --                                                            */      
{
   
  /*-- Memory Device 0 --*/
    Fee_Write   
};

#if (MEMIF_u8API_CONFIG_CLASS == MEMIF_u8API_CONFIG_CLASS_2)

/* !Parameter: MemIf_EraseImdtBlockApiConfiguration container - vendor specific    
               Wrapping table of MemIf EraseImdtBlock API to corresponding 
               memory abstraction module EraseImdtBlock APIs.                */
/* !Size     : MEMIF_NUMBER_OF_DEVICES                                       */
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments     */
/*              either using AUTOSAR AUTOMATIC definition or by configurable */
/*              memory classes                                               */
/* PRQA S 0850 ++                                                            */
CONST(MemIf_tpfudtEraseImdtBlockApi, MEMIF_CFG_CONST) 
      MemIf_kapfudteErsImdtBlckApiCfg[MEMIF_NUMBER_OF_DEVICES] =
/* PRQA S 0850 --                                                            */      
{
  
  /*-- Memory Device 0 --*/
    Fee_EraseImmediateBlock    
};

/* !Parameter: MemIf_InvalidateBlckApiConfiguration container - vendor specific    
               Wrapping table of MemIf InvalidateBlock API to corresponding 
               memory abstraction module InvalidateBlock APIs.               */
/* !Size     : MEMIF_NUMBER_OF_DEVICES                                       */
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments     */
/*              either using AUTOSAR AUTOMATIC definition or by configurable */
/*              memory classes                                               */
/* PRQA S 0850 ++                                                            */
CONST(MemIf_tpfudtInvalidateBlockApi, MEMIF_CFG_CONST) 
      MemIf_kapfudteInvalidBlckApiCfg[MEMIF_NUMBER_OF_DEVICES] =
/* PRQA S 0850 --                                                            */      
{
  
  /*-- Memory Device 0 --*/
    Fee_InvalidateBlock   
};

/* !Parameter: MemIf_CancelApiConfiguration container - vendor specific    
               Wrapping table of MemIf Cancel API to corresponding memory
               abstraction module Cancel APIs.                               */
/* !Size     : MEMIF_NUMBER_OF_DEVICES                                       */
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments     */
/*              either using AUTOSAR AUTOMATIC definition or by configurable */
/*              memory classes                                               */
/* PRQA S 0850 ++                                                            */
CONST(MemIf_tpfvidCancelApi, MEMIF_CFG_CONST) 
      MemIf_kapfudteCancelApiCfg[MEMIF_NUMBER_OF_DEVICES] =
/* PRQA S 0850 --                                                            */      
{
  
  /*-- Memory Device 0 --*/
    Fee_Cancel   
};

#endif /* MEMIF_u8API_CONFIG_CLASS */

/* inhibit message number 750 because local macro used on MemMap not         */
/* referenced                                                                */
/* inhibit message number 760 because Redundant macro used on MemMap         */
/* inhibit message number 961 because multiple use of #define for MemMap     */
/* inhibit message number 537 because Repeated include for MemMap            */
/* inhibit message number 960 because use of '#undef' is discouraged         */
/* inhibit message number 766 because include of MemMap at end of file       */
/*lint -save -vo -e750 -e760 -e961 -e537 -e960 -e766 -v                      */
#define MEMIF_STOP_CONFIG_DATA_UNSPECIFIED
#include "MemMap.h" /*## Close unknown size constant section ##              */

#endif /* MEMIF_NUMBER_OF_DEVICES */


  /*==== End of file ==========================================================*/

  
