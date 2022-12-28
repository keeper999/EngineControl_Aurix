
/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : CanTp                                                   */
/* !Description     : CanTp is the component between the PDU Router and the   */
/*                    CAN Interface module. The main purpose of the CanTp     */
/*                    component is to segment and reassemble CAN I-PDUs longer*/
/*                    than 8 bytes                                            */
/*                                                                            */
/* !File            : CanTp_Cfg.h                                             */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2011 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/19_CanTp/0$*/
/* $Revision::   1.3      $$Author::   sedrees        $$Date::   Feb 13 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/******************************************************************************/
/*! \file CanTp_Cfg.h
*
* \par
*   This file contains the pre-compile configuration parameters of the CanTp
    Component                                                                 */
/******************************************************************************/
#ifndef CANTP_CFG_H
#define CANTP_CFG_H

#include "Std_Types.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/


/******************************************************************************/
/*! \Description    This parameter, if set to true enables the
                    CanTp_ChangeParameter Api for this Module                 \n
    \Range          STD_ON/STD_OFF                                            \n
*******************************************************************************/
  
#define CanTp_bCHANGE_PARAMETER_API         STD_OFF
/*  \ConfigTool     Derived from CanTpGeneral\CanTpChangeParameterApi         */
/******************************************************************************/


/******************************************************************************/
/*! \Description    Switches the Development Error Detection and Notification
                    ON or OFF                                                 \n
    \Range          STD_ON/STD_OFF                                            \n
*******************************************************************************/

#define CanTp_bDEV_ERROR_DETECT             STD_ON
/*  \ConfigTool     Derived from CanTpGeneral\CanTpDevErrorDetect */
/******************************************************************************/

/******************************************************************************/
/*! \Description    Configuration parameter used to enable/disable version    
                    check between CanTp and other interfaced modules          \n
    \Range          STD_ON/STD_OFF                                            \n
*******************************************************************************/
#define CanTp_bINTER_MOD_VER_CHECK    STD_OFF
  
/*  \ConfigTool     Derived from CanTpGeneral\CanTpInterModVerCheck */
/******************************************************************************/

/******************************************************************************/
/*! \Description    Used for the initialization of unused bytes with a certain
                    value                                                     \n
    \Range          0..255                                                    \n
*******************************************************************************/
#define CanTp_u8PADDING_BYTE                0xFF
/*  \ConfigTool     Derived from CanTpGeneral\CanTpPaddingByte    */
/******************************************************************************/


/******************************************************************************/
/*! \Description    The function CanTp_GetVersionInfo is configurable (On/Off)
                    by this configuration parameter                           \n
    \Range          STD_ON/STD_OFF                                            \n
*******************************************************************************/

#define CanTp_bGET_VERSION_INFO_API         STD_OFF
/*  \ConfigTool     Derived from CanTpGeneral\CanTpVersionInfoApi */
/******************************************************************************/


/******************************************************************************/
/*! \Description    This parameter, if set to true enables the
                    CanTp_ReadParameter Api for this Module                   \n
    \Range          STD_ON/STD_OFF                                            \n
*******************************************************************************/
  
#define CanTp_bREAD_PARAMETER_API         STD_OFF
/*  \ConfigTool     Derived from CanTpGeneral\CanTpReadParameterApi         */
/******************************************************************************/

/******************************************************************************/
/*! \Description    A configuration parameter to select the type of the mode of
                    the block size value during reception.                    \n
                    If dynamic block size mode is used, then the block size
                    value _transmitted in each flow control for the
                    CanTpRxNSdu_ will depend of the buffer size available in
                    the upper layer.                                          \n
                    If the dynamic block size mode is not used, then the block
                    size value _transmitted in each flow control for the
                    CanTpRxNSdu_ will always be constant.                     \n
    \Range          STD_ON/STD_OFF                                            \n
*******************************************************************************/
  
#define CanTp_bDYNAMIC_RX_BLOCKSIZE         STD_ON
/*  \ConfigTool     Derived from CanTpGeneral\
                    CanTpDynamicBlockSize                                     */
/******************************************************************************/



/******************************************************************************/
/*! \Description    A configuration parameter to select whether the CanTp shall
                    issue a transmission retry in case the lower layer rejects
                    the transmission request or not.                          \n
                    If transmission retry is disabled, then the
                    transmission/reception operation will be aborted if the
                    lower layer rejects the transmission request.             \n
                    If transmission retry is enabled, then the CanTp will
                    perform a new retry on the next Main Function call till the
                    request is accepted or till the timeout N_As/N_Ar expires.\n
    \Range          STD_ON/STD_OFF                                            \n
*******************************************************************************/

#define CanTp_bCANIF_TRANSMIT_RETRY         STD_OFF
/*  \ConfigTool     Derived from CanTpGeneral\CanTpTransmitRetry  */
/******************************************************************************/




/******************************************************************************/
/*! \Description    Software Major Version of the CanTp Configuration         \n
    \Range          1                                                         \n
*******************************************************************************/
#define CANTP_CFG_MAJOR_VERSION             0x02


/******************************************************************************/
/*! \Description    Software Minor Version of the CanTp Configuration         \n
    \Range          0                                                         \n
*******************************************************************************/
#define CANTP_CFG_MINOR_VERSION             0x00
/******************************************************************************/
/*! \Description    CanTpRxNSdu Definitions                                   \n
*******************************************************************************/

#define    CanTp_UDS_PHYSICAL_6A8_RX    0
#define    CanTp_UDS_Functional_7FF_Rx    1
#define    CanTp_OBD_FUNCTIONNAL_7DF_Rx    2
#define    CanTp_OBD_PHYSICAL_7E0_Rx    3
  

/******************************************************************************/
/*! \Description    CanTpTxNSdu Definitions                                   \n
*******************************************************************************/

#define    CanTp_UDS_PHYSICAL_6A8_TX    0
#define    CanTp_UDS_Functional_7FF_Tx    1
#define    CanTp_OBD_FUNCTIONNAL_7DF_Tx    2
#define    CanTp_OBD_PHYSICAL_7E0_Tx    3


#endif /* CANTP_CFG_H */

/*-------------------------------- end of file -------------------------------*/
