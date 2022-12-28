
/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : PduR                                                    */
/* !Description     : PduR                                                    */
/*                                                                            */
/* !Module          : PduR                                                    */
/* !Description     : PduR                                                    */
/*                                                                            */
/* !File            : PduR_Cfg.c                                              */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VIAS - VALEO Egypt                                      */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2011 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/02_PduR/02$*/
/* $Revision::   1.18      $$Author::   sedrees       $$Date::   Aug 24 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/******************************************************************************/
/* Includes                                                                   */
/******************************************************************************/

/* !Deviation : Inhibit MISRA rule [0838]: Multiple inclusion prevention      */
/*              macros solves multiple/re-inclusions issues                   */
/* PRQA S 0838 L1                                                             */

/* !Deviation : Inhibit MISRA rule [0862]: Memmap.h is used for assignation   */
/*              memory segments in the linker                                 */
/* PRQA S 0862 L1                                                             */
/* PRQA S 5087 L1                                                             */

/* !Deviation : Inhibit MISRA rule [0850]: AUTOMATIC keyword is defined as an */
/*              empty macro                                                   */
/* PRQA S 0850 L1                                                             */

/* !Deviation : Inhibit MISRA rule [2213]: Better readability encountered     */
/*              when having all configuration parameters on same line         */
/* PRQA S 2213 L1                                                             */

/* !Deviation : Inhibit MISRA rule [3132]: Magic numbers are auto-generated   */
/*              the configuration tool as this is a configuration file        */
/* PRQA S 3132 L1                                                             */


#include "Std_Types.h"
#include "PduR_Types.h"
#include "PduR_LocalTypes.h"

#include "PduR.h"
#include "PduR_Cfg.h"
#include "PduR_LocalCfg.h"


#include  "PduR_Com.h"

#include  "PduR_CanTp.h"

/******************************************************************************/
/* Auto-Generated RAM arrays configured at Pre-Compile time                   */
/******************************************************************************/

#define PDUR_START_SEC_VAR_8
#include "Memmap.h"

/******************************************************************************/
/*! \Description    Holds actual data bytes buffered in the IF buffers \n
    \Size           Sigma (All IF buffers) [Buff Depth * Buff Length] \n
*******************************************************************************/


/******************************************************************************/
/*! \Description    Holds actual data bytes buffered in the TP buffers \n
    \Size           Sigma (All TP buffers) [Buff Length] \n
*******************************************************************************/



/******************************************************************************/
/*! \Description    Holds FIFO control information for each IF buffer \n
    \Size           PduR_u16MAX_TX_BUFFER_NUMBER \n
*******************************************************************************/
#if(PduR_u16MAX_TX_BUFFER_NUMBER > 0UL)
VAR(PduR_tstrTxCntrlType, PDUR_VAR)
                            PduR_astreTxBuffCtrl[PduR_u16MAX_TX_BUFFER_NUMBER];
#endif



/******************************************************************************/
/*! \Description    Holds the status of each global IPDU in the PduR module \n
    \Size           PduR_u16MAX_GLBL_IPDUS_NMBR \n
*******************************************************************************/
#if(PduR_u16MAX_GLBL_IPDUS_NMBR == 0UL)
VAR(PduR_tu8PduStateType, PDUR_VAR) PduR_au8eGlblPduState[1]; /* work around  */
#else
VAR(PduR_tu8PduStateType, PDUR_VAR)
                            PduR_au8eGlblPduState[PduR_u16MAX_GLBL_IPDUS_NMBR];
#endif

#define PDUR_STOP_SEC_VAR_8
#include "Memmap.h"

#define PDUR_START_SEC_VAR_16
#include "Memmap.h"

/******************************************************************************/
/*! \Description    Holds header information (PduId and stored length) for each
                    data entry that is buffered in the IF buffers \n
    \Size           Sigma (All IF buffers) [Buff Depth] \n
*******************************************************************************/


#define PDUR_STOP_SEC_VAR_16
#include "Memmap.h"

/******************************************************************************/
/* Configuration Parameters                                                   */
/******************************************************************************/

#if(PduR_bROUTING_GROUPS_PRESENT == STD_ON)
#define PDUR_START_CONFIG_DATA_BOOLEAN
#include "Memmap.h"

/******************************************************************************/
/*! \Description    Default state for routing path groups upon initialization \n
    \Size           PduR_u16MAX_ROUTE_GRP_NUMBER \n
--------------------------------------------------------------------------------
    \Configuration  Container   RoutingPathGroup.PduRIsEnabledAtInit
                    Range       0..PduR_u16MAX_ROUTE_GRP_NUMBER + 1
                    Values      TRUE, FALSE
*******************************************************************************/


CONST(boolean, PDUR_CFG_CONST)
                    PduR_akbeRGrpStatusPC[PduR_u16MAX_ROUTE_GRP_NUMBER + 1UL] =
{
    TRUE,
    TRUE,
    TRUE,
    TRUE,

    TRUE,                 /* Imaginary routing group used internally          */
};

#define PDUR_STOP_CONFIG_DATA_BOOLEAN
#include "Memmap.h"
#endif

#define PDUR_START_CONFIG_DATA_UNSPECIFIED
#include "Memmap.h"



/******************************************************************************/
/*! \Description    Array of poiter to function that is used to initialize the 
                    Upper and/or Tp modules \n
    \Size           # of TP destinations + # of Up destinations + 1 \n
*******************************************************************************/
CONST(PduR_tstrBswModInitFuncPtrType, PDUR_CALIB_CONST)
                        PduR_akstreBswModuleInitFnPtT[3] =
{
    {
        /* pfvidBswModuleInit       */  PduR_vidCanTpInit,
    },
    {
        /* pfvidBswModuleInit       */  PduR_vidComInit,
    },
    {
        /* pfvidBswModuleInit       */  NULL_PTR,
    }
};
    
#define PDUR_STOP_CONFIG_DATA_UNSPECIFIED
#include "Memmap.h"


/*------------------------------- end of file --------------------------------*/
/* PRQA L:L1                                                                 */
