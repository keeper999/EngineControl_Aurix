/******************************************************************************/
/*                                                                            */
/* !Layer           : OSEK                                                    */
/*                                                                            */
/* !Module          : NM_TYP                                                  */
/* !Description     : External Data Types of OSEK_NM Component                */
/*                                                                            */
/* !File            : NM_TYP.H                                                */
/*                                                                            */
/* !Scope           : Public                                                  */
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
/* PVCS Information                                                           */
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/PATCH/NM_TYP.H_v                  $*/
/* $Revision::   1.0      $$Author::   croche2        $$Date::   11 Mar 2014 $*/
/******************************************************************************/
/* !VnrOff : OSEK Names                                                       */
/******************************************************************************/

#ifndef FILE_NM_TYP_H_INCLUDED
#define FILE_NM_TYP_H_INCLUDED

#include "STD_TYPES.H"
// #include "osek_com.h"


/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
/******************************************************************************/
/* !Comment :  Type for references to several communication networks.         */
/******************************************************************************/
typedef uint8 NetIdType;
typedef uint8 NMModeName;

/******************************************************************************/
/* !Comment :  Type of Network Status (Bitfield).                             */
/******************************************************************************/
// typedef uint8                NetworkStatusType;
// typedef NetworkStatusType *  NetworkStatusTypeRef;
// #define NM_STATE_BUSON          (0x00)
// #define NM_STATE_BUSOFF         (0x01)
// #define NM_STATE_BUSOFF_CONF    (0x02)

// #define NM_ON                   (0x00)
// #define NM_OFF                  (0x04)

// #define NM_STATE_LIMPHOME       (0x08)

// #define NM_STATE_BUS_AWAKE      (0x00)
// #define NM_STATE_BUS_SLEEP      (0x10)
// #define NM_STATE_WAIT_BUS_SLEEP (0x20)



#define BusSleep            (0x00)
#define Awake               (0x01)
/******************************************************************************/
/* !Comment : Requested type of configuration                                 */
/******************************************************************************/
// typedef enum
// {
   // NM_CONFIG_NORMAL   = 0,
   // NM_CONFIG_EXTENDED = 1
// }
// ConfigKindName;

// #define NM_CONFIG_KIND_NUMBER  2




// typedef struct
// {
   // SymbolicName udtMessageId;
   // uint8        bDirection;
   // AlarmType    udtAlarmId;

// }
// NM_tstrNodeMonitoringConfig;


// typedef struct
// {
   // TickType Timeout;
   // uint8    Threshold;

// }
// NM_tstrBusoffDLLRestart;


// #define NM_bMESSAGE_DIRECTION        (0x01)
// #define NM_bMESSAGE_DIRECTION_EMIT   (0x00)
// #define NM_bMESSAGE_DIRECTION_RECEPT (0x01)



/******************************************************************************/
/* !Comment : Type of Node Diagnostic control  (for API hal_nm_config)        */
/******************************************************************************/
typedef enum
{
   E_HAL_NM_STOP           = 0,
   E_HAL_NM_START_RESUME   = 1,
   E_HAL_NM_HOLD           = 2
}
tenuNMDiagConfig;

/******************************************************************************/
/* !Comment :  Type for references to several nodes.                          */
/******************************************************************************/
typedef uint8 NodeIdType;


#endif /* FILE_NM_TYP_H_INCLUDED */

/*------------------------------- end of file -------------------------------*/
