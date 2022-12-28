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
**  FILENAME  : Can_GeneralTypes.h                                            **
**                                                                            **
**  VERSION   : 0.0.4                                                         **
**                                                                            **
**  DATE      : 2013-03-18                                                    **
**                                                                            **
**  VARIANT   : VariantPB                                                     **
**                                                                            **
**  PLATFORM  : Infineon Aurix                                                **
**                                                                            **
**  COMPILER  : Tasking / GNU / Diab                                          **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : This header file contains                                  **
**                 - types and constants that are shared among Can, CanIf     **
**                   and CanTrcv                                              **
**                                                                            **
**  SPECIFICATION(S) : AUTOSAR_SWS_CANDriver, Release 4.0.3                   **
**                                                                            **
**  MAY BE CHANGED BY USER [yes/no]: yes                                      **
**                                                                            **
*******************************************************************************/

/******************************************************************************
**                      Author(s) Identity                                   **
*******************************************************************************
**                                                                           **
** Initials     Name                                                         **
** --------------------------------------------------------------------------**
** SGN          Gururaj Nath S                                               **
**                                                                           **
**                                                                           **
**                                                                           **
******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 *
 *
 * V0.0.4: 2013-03-18, SGN  : Removed the inclusion of Std_Types.h and 
 *                            ComStack_Types.h
 * V0.0.3: 2013-01-03, Vani : Updated for CanTrcv
 * V0.0.2: 2012-12-18, SGN  : Updated for AS4.0.3
 * V0.0.1: 2012-05-01, SGN  : initial version
 */

#ifndef CAN_GENERALTYPES_H
#define CAN_GENERALTYPES_H

#include "ComStack_Types.h"


/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/

/* CAN Id and Mask type */
typedef uint32 Can_IdType;   /* Both Std and Ext IDs are used */

/* CAN protocol data unit type. Used to provide ID, DLC and SDU from
   CAN Interface to CAN driver */
typedef struct Can_PduType
{
  PduIdType swPduHandle;    /* SW Handle that will identify the request in
                               the confirmation callback function. */
  uint8 length;             /* DLC */
  Can_IdType id;            /* Identifier of L-PDU */
  uint8 *sdu;               /* Pointer to L-SDU */
} Can_PduType;

/* CAN Hardware Object Handle Type */
/* Maximum of 256 hardware objects in the CAN hardware unit */
typedef uint8 Can_HwHandleType;

/* CAN state transition type */
typedef enum
{
  CAN_T_START,    /* CAN controller transition value to request state STARTED */
  CAN_T_STOP,     /* CAN controller transition value to request state STOPPED */
  CAN_T_SLEEP,    /* CAN controller transition value to request state SLEEP */
  CAN_T_WAKEUP    /* CAN controller transition value to request state STOPPED
                     from state SLEEP  */
} Can_StateTransitionType;

/* Type for return values of few of the CAN Driver APIs */
typedef enum
{
  CAN_OK,        /* success */
  CAN_NOT_OK,    /* error occurred or wakeup occurred during sleep transition */
  CAN_BUSY       /* transmit request could not be processed because no transmit 
                    object was available */
} Can_ReturnType;




/* Operating modes of the CAN Transceiver Driver. */
typedef enum
{
  CANTRCV_TRCVMODE_NORMAL,        /* Transceiver mode NORMAL */
  CANTRCV_TRCVMODE_SLEEP,    /* Transceiver mode SLEEP */
  CANTRCV_TRCVMODE_STANDBY       /*Transceiver mode STANDBY */
} CanTrcv_TrcvModeType;

/* Operating modes of the CAN Transceiver Driver. */
typedef enum
{
  CANTRCV_WUMODE_ENABLE,    /*The notification for wakeup events is 
                          enabled on the addressed transceiver. */
  CANTRCV_WUMODE_CLEAR,     /*A stored wakeup event is cleared on the 
                                 addressed transceiver. */
  CANTRCV_WUMODE_DISABLE    /* The notification for wakeup events is 
                            disabled on the addressed transceiver. */        
} CanTrcv_TrcvWakeupModeType;

/* Operating modes of the CAN Transceiver Driver. */
typedef enum
{
  CANTRCV_WU_ERROR,        /*Due to an error wake up reason was not detected. 
      This value may only be reported when error was reported to DEM before.*/
  CANTRCV_WU_BY_BUS,     /*The transceiver has detected, that the network has caused the wake up of the ECU. */
  CANTRCV_WU_BY_PIN,    /* The transceiver has detected a wake-up event at one of the transceiver's pins (not at the CAN bus).*/
  CANTRCV_WU_INTERNALLY, /*The transceiver has detected, that the network has woken up by the ECU via a request to NORMAL mode.*/
  CANTRCV_WU_NOT_SUPPORTED, /*The transceiver does not support any information for the wake up reason.*/
  CANTRCV_WU_POWER_ON, /*The transceiver has detected, that the "wake up" is due to an ECU reset after power on.*/
  CANTRCV_WU_RESET, /*The transceiver has detected, that the "wake up" is due to an ECU reset.*/
  CANTRCV_WU_BY_SYSERR /*The transceiver has detected, that the wake up of the ECU was caused by a HW related device fail-ure.*/
        
} CanTrcv_TrcvWakeupReasonType;
/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif /* #ifndef CAN_GENERALTYPES_H */

