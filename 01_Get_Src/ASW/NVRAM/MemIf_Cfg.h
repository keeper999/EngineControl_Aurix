
/*****************************************************************************/
/*                                                                           */
/* !Layer           : ECU Abstraction Layer                                  */
/*                                                                           */
/* !Component       : MemIf                                                  */
/* !Description     : AUTOSAR Memory Abstraction Interface component         */
/*                                                                           */
/* !Module          : MemIf                                                  */
/* !Description     : Memory Abstraction Interface configuration module      */
/*                                                                           */
/* !File            : MemIf_Cfg.h                                            */
/*                                                                           */
/* !Scope           : Public                                                 */
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
/* $Header:   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/13_MemIf/   */
/*            02_Development/02_Source_Code/01_Config_Files/                 */
/*            MemIf_Cfg.h-arc   1.3   Sep 14 2011 19:42:44   mhegazy         */
/*****************************************************************************/
/* PRQA S 0288 --                                                            */
/*****************************************************************************/
/* MODIFICATION LOG :                                                        */
/*****************************************************************************/
/* TFR        : None                                                         */
/* Rev        : 1.2            R1.0.0   AR4.0                                */
/* Done by    : M.Hegazy                                  Date : 14/09/11    */
/* Description: - Removed "BASIS" word from the file.                        */
/*****************************************************************************/
/* TFR        : None                                                         */
/* Rev        : 1.1.0            R1.0.0   AR4.0                              */
/* Done by    : M.Hegazy                                  Date : 11/09/11    */
/* Description: - Updated after solving peer review bugs.                    */
/*****************************************************************************/
/* TFR        : None                                                         */
/* Rev        : 1.0.0            R1.0.0   AR4.0                              */
/* Done by    : M.Hegazy                                  Date : 10/05/11    */
/* Description: - Initial version for AUTOSAR Release 4.0.                   */
/*****************************************************************************/

#ifndef MEMIF_CFG_H
#define MEMIF_CFG_H
 
/* !Trace_To : GSCSW-MemIf-SDD-001-0029               */

#include "Fee.h"



/* !Parameter: Pre-processor switch used to indicate whither there is Ea 
               module or not                                                  */
/* !Range    : [STD_ON, STD_OFF]                                              */
/* !Unit     : -                                                              */
#define MEMIF_bUSE_EA STD_OFF


/* !Parameter: Pre-processor switch used to indicate whither there is Fee 
               module or not                                                  */
/* !Range    : [STD_ON, STD_OFF]                                              */
/* !Unit     : -                                                              */
#define MEMIF_bUSE_FEE STD_ON

/*===========================================================================*/
/*=== Configuration Version Information =====================================*/
/*===========================================================================*/
/* !Trace_To: GSCSW-MEMIF-SDD-001-0035                                       */

/* !Comment : Major version number of the module's configuration.
              The numbering is vendor specific.                              */

#define MEMIF_CFG_MAJOR_VERSION               (2U)

/* !Comment : Minor version number of the module's configuration.
              The numbering is vendor specific.                              */
#define MEMIF_CFG_MINOR_VERSION               (0U)


/*===========================================================================*/
/*=== Pre-compile Attributes ================================================*/
/*===========================================================================*/
/* !Trace_To : GSCSW-MemIf-SDD-001-0033, GSCSW-MemIf-SDD-001-0109            */
/* !Trace_To : GSCSW-MemIf-SDD-001-0003                                      */

/*--- AUTOSAR Attributes ----------------------------------------------------*/

/* !Parameter: Pre-processor switch to enable/disable development error
               detection (i.e. parameter checks and DET reporting).          */
/* !Range    : [STD_ON, STD_OFF]                                             */
/* !Unit     : -                                                             */
/* !Trace_To  :  GSCSW-MemIf-SDD-001-0103                                  */

#define MEMIF_DEV_ERROR_DETECT                STD_ON
/* !Parameter: Defines number of underlying memory abstraction devices to be
               used, i.e. number of EA/FEE modules instanciations to wrap.   */
/* !Range    : [1..254]                                                      */
/* !Unit     : Memory abstraction devices (i.e. modules)                     */
/* !Trace_To  :  GSCSW-MemIf-SDD-001-0104                                  */

#define MEMIF_NUMBER_OF_DEVICES               (1U)

/* !Parameter: Pre-processor switch to enable/disable the API to read out
               the modules version information.                              */
/* !Range    : [STD_ON, STD_OFF]                                             */
/* !Trace_To  :  GSCSW-MemIf-SDD-001-0105                                  */

#define MEMIF_VERSION_INFO_API                STD_OFF

/*--- Vendor specific attributes --------------------------------------------*/

/* !Parameter: Pre-processor switch to enable/disable some API calls which
               are related to MemIf API configuration classes.               */
/* !Range    : [MEMIF_u8API_CONFIG_CLASS_1, MEMIF_u8API_CONFIG_CLASS_2]      */
/* !Trace_To  :  GSCSW-MemIf-SDD-001-0110                                  */

#define MEMIF_u8API_CONFIG_CLASS              MEMIF_u8API_CONFIG_CLASS_2
#define  NVMRAM  0
/* !Deviation: [3453]  the following functions like macros , helps to increase
the readability of the code , by accessing the required configuration parameter
, through a macro . Macros were used instead of functions in order to increase
the code performance by reducing the time required by the context switching*/
/* PRQA S 3453 ++ */
/*--- Vendor specific wrapping macros ---------------------------------------*/
#if (MEMIF_NUMBER_OF_DEVICES == 1U)

  /***************************************************************************/
  /* !Description : SetMode API single wrapper                               */
  /***************************************************************************/
  #define MemIf_SetMode(Mode)                                                 \
                Fee_SetMode(Mode)
  /***************************************************************************/
  /* !Description : GetStatus API single wrapper                             */
  /***************************************************************************/
  #define MemIf_GetStatus(DeviceIdx)                                          \
                Fee_GetStatus()

  /***************************************************************************/
  /* !Description : GetJobResult API single wrapper                          */
  /***************************************************************************/
  #define MemIf_GetJobResult(DeviceIdx)                                       \
                Fee_GetJobResult()

  /***************************************************************************/
  /* !Description : Read API single wrapper                                  */
  /***************************************************************************/
  #define MemIf_Read(DeviceIdx, BlockNb, BlockOfst, DataBfrPtr, Lgth)         \
                Fee_Read((BlockNb), (BlockOfst), (DataBfrPtr), (Lgth))

  /***************************************************************************/
  /* !Description : Write API single wrapper                                 */
  /***************************************************************************/
  
  #define MemIf_Write(DeviceIdx, BlockNb, DataBfrPtr)                         \
                Fee_Write((BlockNb), (DataBfrPtr))

/* !Deviation:  Inhibit MISRA rule [97] because   configuration calsses  are */
/*                  defined in MemIf_Types.h which is included through  the  */
/*         abstarction modules according to the modified file  architecture    */
/*         specified by CEE requirements                                       */
/*lint -save -vo -e553 -v                                                    */
/* !Deviation:  Inhibit MISRA rule [3332] because configuration calsses  are */
/*                  defined in MemIf_Types.h which is included through  the  */
/*         abstarction modules according to the modified file  architecture    */
/*         specified by CEE requirements                                       */
/* PRQA S 3332 ++                                                            */
#if (MEMIF_u8API_CONFIG_CLASS == MEMIF_u8API_CONFIG_CLASS_2)
/* PRQA S 3332 --                                                            */
/*lint -restore                                                              */
  /***************************************************************************/
  /* !Description : InvalidateBlock API single wrapper                       */
  /***************************************************************************/
  #define MemIf_InvalidateBlock(DeviceIdx, BlockNb)                           \
                Fee_InvalidateBlock((BlockNb))

  /***************************************************************************/
  /* !Description : EraseImmediateBlock API single wrapper                   */
  /***************************************************************************/
  #define MemIf_EraseImmediateBlock(DeviceIdx, BlockNb)                       \
                Fee_EraseImmediateBlock((BlockNb))

  /***************************************************************************/
  /* !Description : Cancel API single wrapper                                */
  /***************************************************************************/
  #define MemIf_Cancel(DeviceIdx)                                             \
                Fee_Cancel()
#endif /* MEMIF_u8API_CONFIG_CLASS */

#endif /* MEMIF_NUMBER_OF_DEVICES */
/* PRQA S 3453 -- */


#endif /* MEMIF_CFG_H */

/*==== End of file ==========================================================*/

        
