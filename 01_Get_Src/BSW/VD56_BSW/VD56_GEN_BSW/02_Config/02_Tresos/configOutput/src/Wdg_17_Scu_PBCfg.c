/* Traceability : [cover parentID=SAS_NAS_WDG_PR483][/cover]            */
/* Traceability : [cover parentID=SAS_NAS_WDG_PR913][/cover]            */
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2013)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Wdg_17_Scu_PBCfg.c                                            **
**                                                                            **
**  $CC VERSION : \main\37 $                                                 **
**                                                                            **
**  DATE, TIME: 2014-09-29, 11:35:20                                          **
**                                                                            **
**  GENERATOR : Build b131017-0205                                            **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : WDG configuration generated out of ECU configuration       **
**                 file  (Wdg_17_Scu.bmd and Wdg_17_Scu.xdm)                  **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: no                                       **
**                                                                            **
*******************************************************************************/




/******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/* Include module header File */

/* Module header file, which includes module configuration(Wdg_17_Cfg.h) file */
#include "Wdg_17_Scu.h"

/******************************************************************************
**                      Imported Compiler Switch Checks                      **
*******************************************************************************/

/******************************************************************************
**                      Private Macro Definitions                            **
*******************************************************************************/
/*
Configuration Options:
For fast mode, the divider is 256
*/

#define WDG_CLK_DIVIDER_FAST  (256U)

/*
Configuration Options:
For slow mode, the divider 16384
*/

#define WDG_CLK_DIVIDER_SLOW  (16384U)


/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

#define WDG_17_SCU_START_SEC_POSTBUILDCFG
#include "MemMap.h"



/*
Configuration: Wdg_17_Scu_ConfigType
Overall configuration of the WDT
*/
const Wdg_17_Scu_ConfigType Wdg_ConfigRoot[1]=
{

  {
    /* Traceability : [cover parentID=DS_AS_WDG090, DS_AS_WDG092] [/cover]*/




         
    /* These are the Gtm settings for this configuration instance */     
    {
       {
          /* GTM Configuration for WDG0 */
        
          1953U, /* Fast callback period in ticks. */
          3906U, /* Slow callback period in ticks. */
          5U, /* Fast callback period in ms */
          10U,/*  Slow callback period in ms */
          WDG_GTM_TOM_CHANNEL, /* GTM timer module */
          1U, /* Gtm Module number that services H/W Wdg */
          0U, /* Gtm channel number  that services H/W Wdg */
          (uint8)0U
        
      },

       {
          /* GTM Configuration for WDG1 */
        
          1953U, /* Fast callback period in ticks. */
          3906U, /* Slow callback period in ticks. */
          5U,/* Fast callback period in ms */
          10U,/*  Slow callback period in ms */
          WDG_GTM_TOM_CHANNEL, /* GTM timer module */
          1U, /* Gtm Module number that services H/W Wdg */
          2U, /* Gtm channel number  that services H/W Wdg */
          (uint8)0U
        
      },

      {
        /* GTM Configuration for WDG2 */
        
        1953U, /* Fast callback period in ticks. */
        3906U, /* Slow callback period in ticks. */
        5U,/* Fast callback period in ms */
        10U,/*  Slow callback period in ms */
        WDG_GTM_TOM_CHANNEL, /* GTM timer module */
        1U, /* Gtm Module number that services H/W Wdg */
        8U, /* Gtm channel number  that services H/W Wdg */
       (uint8)0U
        
      }

 
    },
 
     
    /* Resolution of watchdog timer in fast mode  : 0.00256 ms
       Minimum timeout period in fast mode        : 0.00256 ms
       Maximum timeout period in fast mode        : 167.77216 ms */

    {

      (uint16)57723U, /* Fast Mode Reload Value for WDG0 */


      (uint16)57723U, /* Fast Mode Reload Value for WDG1 */


      (uint16)57723U  /* Fast Mode Reload Value for WDG2 */

    },


    /* Resolution of watchdog timer in slow mode  : 0.16384 ms
       Minimum timeout period in slow mode        : 0.16384 ms
       Maximum timeout period in slow mode        : 10737.41824 ms */

    {
      (uint16)65407U, /* Slow Mode Reload Value for WDG0 */


      (uint16)65407U, /* Slow Mode Reload Value for WDG1 */ 


      (uint16)65407U  /* Slow Mode Reload Value for WDG2 */

    }, 



  
    /* Initial password */

    /* Configuration : WdgDefaultMode:
       Default mode for watchdog driver initialization: WDG083:
       - WDGIF_OFF_MODE
       - WDGIF_SLOW_MODE
       - WDGIF_FAST_MODE
    */
    


    {
      WDGIF_OFF_MODE, /*Default Mode for WDG0 */
      WDGIF_FAST_MODE, /*Default Mode for WDG1 */

      WDGIF_FAST_MODE /*Default Mode for WDG2 */
    },
    
    /* TimerTolerance */
    /*WdgSafetyProperty , 1 = WDGx safe; 0 WDGx QM */
    {
      (0U),
      (0U),
      (0U),
    },
    /* WdgSafeIndex */
    /*  WdgQmIndex*/ 
    {
      (0U),
      (1U),
      (2U),
    }
  }
  

};


#define WDG_17_SCU_STOP_SEC_POSTBUILDCFG
#include "MemMap.h"
/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
