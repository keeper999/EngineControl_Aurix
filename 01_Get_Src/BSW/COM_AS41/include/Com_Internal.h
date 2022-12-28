/******************************************************************************/
/*                                                                            */
/* !Layer           : SRVL                                                    */
/*                                                                            */
/* !Component       : Com                                                     */
/* !Description     : AUTOSAR Communication Module                            */
/*                                                                            */
/* !Module          : Com                                                     */
/*                                                                            */
/* !File            : Com_Internal.h                                         */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : ALL                                                     */
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
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/03-Com/02_$*/
/* $Revision::   1.100                                                       $*/
/* PRQA S 0288 --                                                             */

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

/******************************************************************************/

/******************************************************************************/
/*! \file Com_Internal.h
*
* \par
*   Declarations of Com internal functions and link time data types */
/******************************************************************************/

/******************************************************************************/
/*! \defgroup module Com
* This is the grouping of the Com module members.
* \{
*/
/******************************************************************************/
#ifndef COM_INTERNAL_H
#define COM_INTERNAL_H

#include "Com.h"
#include "ComStack_Types.h"
#include "Com_Types.h"
#include "PduR_Com.h"



/******************************************************************************/
/* Configuration Data Types                                                   */
/******************************************************************************/

/******************************************************************************/
/*! \Description Defines a type of Pointer to error notification function \n */
/******************************************************************************/
typedef P2FUNC(void, AUTOMATIC, Com_tpfvidSigTxErrorNotif) (void);

/******************************************************************************/
/*! \Description Defines a type of Pointer to counter error function \n */
/******************************************************************************/
typedef P2FUNC(void, AUTOMATIC, Com_tpfvidCounterError) (
          PduIdType             ComPduId,
          VAR(uint8, AUTOMATIC) ExpectedCounter,
          VAR(uint8, AUTOMATIC) ReceivedCounter);

/******************************************************************************/
/*! \Description Defines a type of Pointer to invalid notification \n
                 function \n */
/******************************************************************************/
typedef P2FUNC(void, AUTOMATIC, Com_tpfvidSigInvalidNotif) (void);

/******************************************************************************/
/*! \Description Defines a type of Pointer to signal notification function \n */
/******************************************************************************/
typedef P2FUNC(void, AUTOMATIC, Com_tpfvidSignalNotification) (void);


/******************************************************************************/
/*! \Description Defines a type of Pointer to signal Time out notification \n
                 function  \n */
/******************************************************************************/
typedef P2FUNC(void, AUTOMATIC, Com_tpfvidTimeoutNotification) (void);

/******************************************************************************/
/*! \Description IPdu Run-Time Status Bits \n
                 --OPTIMIZATION  \n */
/******************************************************************************/
/* --OPTIMIZATION */
/* --OPTIMIZATION IPDU RAM FLAGs*/

/* 	7        6             5  			4            3            2            1           0
   DLMDT      WCONF 	 	  RX_DM_EN		CTR_ACC_ANY  SS_REQ                  DEFPROC    ACTIVE */

#define Com_u8ACTIVE_MASK          1u  /*! for Rx,Tx IPDU*/
#define Com_u8DEF_PROC_MASK  	   2u /*! for Rx,Tx IPDU*/
#define Com_u8CURR_TX_MO_FLG       4u  /*! for Tx IPDU*/
#define Com_u8SENDSIGNAL_RQ 	   8u  /*! for Tx IPDU*/
#define Com_u8CTR_ACC_ANY		   16u  /*! for Rx IPDU*/
#define Com_u8RX_DM_EN_TX_STOP	   32u /*! for Rx IPDU*/
#define Com_u8WAIT_CONF      	   64u	/*! for Tx IPDU*/
#define Com_u8D_MDT_MASK      	   128u  /*! for Tx IPDU*/

typedef uint8 Com_udtIPduStatus;



/* 7  6  5  4   	 3         	2       			1       			0
					            SS_REQ	          LAST_FILTER_RES	   GWS_Rx*/
			   
#define Com_u8GWS_RX 				1u
#define Com_u8LASTFILTER_RES 		2u
#define Com_u8SS_TMS_REQ			4u
#define Com_u8NEW_FILTER_RESULT		8u




typedef uint8 Com_udtSigStatus;


/******************************************************************************/
/*! \Description Defines the Data Invalid Action Symbols \n
                 COM_u8INVALID_ACTION_NOTIFY and COM_u8INVALID_ACTION_REPLACE \n
    \Range     \n
                 COM_u8INVALID_ACTION_NOTIFY  0 \n
                 COM_u8INVALID_ACTION_REPLACE 1 \n       */
/******************************************************************************/
#define Com_u8INVALID_ACT_NOTIFY   0
#define Com_u8INVALID_ACT_REPLACE  1

/******************************************************************************/
/*! \Description Defines the Timeout Action Symbols \n
                 COM_u8TIMEOUT_ACTION_NONE and COM_u8TIMEOUT_ACTION_REPLACE \n
    \Range     \n
                 COM_u8TIMEOUT_ACTION_NONE    0 \n
                 COM_u8TIMEOUT_ACTION_REPLACE 1 \n       */
/******************************************************************************/
#define Com_u8TIMEOUT_ACT_NONE     0
#define Com_u8TIMEOUT_ACT_REPLACE  1

/* --OPTIMIZATION Rx IPDU ROM FLAGs*/

/* 7              6          		      5  		      4                     	   3               		2                1                	    0
            	  bfInvalidValue		  bfFilter	      bfRxDataTimeoutAction	       bfNotification       bfFirstTimeout   bfErrorNotification	 bfDataInvalidAction   */


#define Com_u8SIGLT_DATINVAL_ACT	  	        0x01 /*(SIGNALLT_DATAINVALID_ACTION) Will not remove it*/
#define Com_u8SIGLT_TIMEOUT_ACT     	    	0x10 /*(Com_u8SIGLT_TIMEOUT_ACT) Will not remove it*/

typedef uint8 Com_tu8SignalLTFlags;

/******************************************************************************/
/*! \Description Defines a type of ComSignalLT ROM Structure  \n */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description Pointer to error notification function \n
                     calculation method: equals to ComErrorNotification \n */
    /**************************************************************************/
    Com_tpfvidSigTxErrorNotif pfvidComErrorNotification;

    /**************************************************************************/
    /*! \Description Pointer to invalid notification function \n
                     calculation method: equals to ComInvalidNotification \n */
    /**************************************************************************/
    Com_tpfvidSigInvalidNotif pfvidInvalidNotification;

    /**************************************************************************/
    /*! \Description Pointer to signal notification function \n
                     calculation method: equals to ComNotification \n */
    /**************************************************************************/
    Com_tpfvidSignalNotification pfvidSignalNotifPtr;

    /**************************************************************************/
    /*! \Description Flags indicating optional/boolean parameters configured \n
                     for signal \n
                     calculation method: see Com_tbfSignalLTFlagsType \n
                     type definition \n */
    /**************************************************************************/
    VAR(Com_tu8SignalLTFlags, AUTOMATIC) udteSignalLTFlags;

    /**************************************************************************/
    /*! \Description Index in one of the invalid value arrays according to \n
                     signal type \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16SigInvalidValIndex;

    /**************************************************************************/
    /*! \Description For ComSignalType UINT8_N this parameter specifies the
                     length n in bytes. \n
                     For ComSignalType UINT8_DYN it specifies the maximum \n
                     length in bytes. \n
                     calculation method: equals to ComSignalLength \n
                     type definition \n
        \Range 0..4095 \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16SignalLength;

    /**************************************************************************/
    /*! \Description Pointer to timout notification function \n
                     calculation method: equals to ComTimeoutNotification \n */
    /**************************************************************************/
    Com_tpfvidTimeoutNotification pfvidTimeoutNotification;

    /**************************************************************************/
    /*! \Description Index in COM_akstrFilter array \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16FilterIndex;

    /**************************************************************************/
    /*! \Description ComHandleId \n */
    /**************************************************************************/
    VAR(Com_SignalIdType, AUTOMATIC) u16SignalId;
} Com_tstrSignalLT;


/* --OPTIMIZATION  Signal group ROM FLAGs*/

/* 7   6   4  		      				   3		               2			       1	                0        
 	       bfRxDataTimeoutAction	       bfNotification       bfFirstTimeout   bfErrorNotification	bfDataInvalidAction   */


#define Com_u8SIGPLT_DATAINVL_ACT	  	0x01 /*(Com_u8SIGNALGROUPLT_DATAINVALID_ACTION)Will not remove it*/
/*#define Com_u8SIGNALGROUPLT_ERROR_NOTIFICATION    0x02
#define Com_u8SIGNALGROUPLT_FIRSTTIMEOUT    		0x04
#define Com_u8SIGNALGROUPLT_NOTIFICATION           	0x08*/

#define Com_u8SIGPLT_TIMOUT_ACT     		0x10         /*Com_u8SIGNALGROUPLT_TIMEOUT_ACTION*/

typedef uint8 Com_tu8SignalGroupLTFlags;




/******************************************************************************/
/*! \Description Defines a type of ComSignalGroupLT ROM Structure  \n */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description Pointer to error notification function \n
                     calculation method: equals to ComErrorNotification \n */
    /**************************************************************************/
    Com_tpfvidSigTxErrorNotif pfvidComErrorNotification;

    /**************************************************************************/
    /*! \Description Pointer to invalid notification function \n
                     calculation method: equals to ComInvalidNotification \n */
    /**************************************************************************/
    Com_tpfvidSigInvalidNotif pfvidInvalidNotification;

    /**************************************************************************/
    /*! \Description Pointer to signal notification function \n
                     calculation method: equals to ComNotification \n */
    /**************************************************************************/
    Com_tpfvidSignalNotification pfvidSignalNotifPtr;

    /**************************************************************************/
    /*! \Description Flags indicating optional/boolean parameters configured \n
                     for signal \n
                     calculation method: see Com_tbfSignalLTFlagsType \n
                     type definition \n */
    /**************************************************************************/
    VAR(Com_tu8SignalGroupLTFlags, AUTOMATIC) udteSignalGroupLTFlags;

    /**************************************************************************/
    /*! \Description Pointer to timout notification function \n
                     calculation method: equals to ComTimeoutNotification \n */
    /**************************************************************************/
    Com_tpfvidTimeoutNotification pfvidTimeoutNotification;

} Com_tstrSignalGroupLT;


/* --OPTIMIZATION  Signal group ROM FLAGs*/

/* 7   6   4   3   2	  1	                0        
						bfInvalidValue		bfFilter   */

/*#define Com_u8GROUPSIGNALLT_FILTER	   		   0x01
#define Com_u8GROUPSIGNALLT_INVALID_VALUE      0x02*/


typedef uint8 Com_tu8GroupSignalLTFlags;

/******************************************************************************/
/*! \Description Defines a type of ComGroupSignalLT ROM Structure  \n */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description Index in one of the invalid value arrays according to \n
                     signal type \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16SigInvalidValIndex;

    /**************************************************************************/
    /*! \Description For ComSignalType UINT8_N this parameter specifies the
                     length n in bytes. \n
                     For ComSignalType UINT8_DYN it specifies the maximum \n
                     length in bytes. \n
                     calculation method: equals to ComSignalLength \n
                     type definition \n
        \Range 0..4095 \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16SignalLength;

    /**************************************************************************/
    /*! \Description Index in COM_akstrFilter array \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16FilterIndex;

    /**************************************************************************/
    /*! \Description ComHandleId \n */
    /**************************************************************************/
    VAR(Com_SignalIdType, AUTOMATIC) u16SignalId;
    /**************************************************************************/
    /*! \Description Signal Group ID containig this group signal \n */
    /**************************************************************************/
   VAR(Com_SignalGroupIdType, AUTOMATIC) u16SignalGroupId ;
   
} Com_tstrGroupSignalLT;


/******************************************************************************/
/*! \Description Defines the Filter Algorithms Symbols \n */
/******************************************************************************/
#define     Com_u8F_ALWAYS                          0u
#define	    Com_u8F_M_NEW_DIFF_M_OLD                1u
#define	    Com_u8F_MASKED_NEW_DIFF_X               2u
#define	    Com_u8F_MASKED_NEW_EQ_X                 3u
#define	    Com_u8F_NEVER                           4u
#define	    Com_u8F_NEW_IS_OUTSIDE                  5u
#define	    Com_u8F_NEW_IS_WITHIN                   6u
#define	    Com_u8F_ONE_EVERY_N                     7u

/******************************************************************************/
/*! \Description Defines a type of Signal Filter generic ROM Structure  \n */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description Index in one of the filter arrays according to \n
                     signal type \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16Index;

    /**************************************************************************/
    /*! \Description Filter Algorithm \n
        \Range
            Com_u8F_ALWAYS                \n
            Com_u8F_M_NEW_DIFF_M_OLD      \n
            COM_u8F_MASKED_NEW_DIFFERS_X  \n
            COM_u8F_MASKED_NEW_EQUALS_X   \n
            Com_u8F_NEVER                 \n
            Com_u8F_NEW_IS_OUTSIDE        \n
            Com_u8F_NEW_IS_WITHIN         \n
            Com_u8F_ONE_EVERY_N           \n */
    /**************************************************************************/
    VAR(uint8, AUTOMATIC)  u8FilterAlgorithm;
} Com_tstrFilter;


/******************************************************************************/
/*! \Description Definitions of types of Signal Masked New X Filter \n
                  ROM Structures. \n
                  These structures shall be used for filter algorithms: \n
                    COM_u8F_MASKED_NEW_DIFFERS_X  \n
                    COM_u8F_MASKED_NEW_EQUALS_X   \n */
/******************************************************************************/

/******************************************************************************/
/*! \Description Defines a type of Signal Mask Filter ROM Structure.  \n
                 This Filter type is specific for Signals of \n
                 ComSignalType = BOOLEAN */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description ComFilterX \n
                     calculation method: equals to ComFilterX*/
    /**************************************************************************/
    VAR(boolean, AUTOMATIC)  bFilterX;

    /**************************************************************************/
    /*! \Description ComFilterMask \n
                     calculation method: equals to ComFilterMask*/
    /**************************************************************************/
    VAR(boolean, AUTOMATIC)  bFilterMask;
} Com_tstrMaskFilterB;

/******************************************************************************/
/*! \Description Defines a type of Signal Mask Filter ROM Structure.  \n
                 This Filter type is specific for Signals of \n
                 ComSignalType = UINT8 */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description ComFilterX \n
                     calculation method: equals to ComFilterX*/
    /**************************************************************************/
    VAR(uint8, AUTOMATIC)  u8FilterX;

    /**************************************************************************/
    /*! \Description ComFilterMask \n
                     calculation method: equals to ComFilterMask*/
    /**************************************************************************/
    VAR(uint8, AUTOMATIC)  u8FilterMask;
} Com_tstrMaskFilterU8;

/******************************************************************************/
/*! \Description Defines a type of Signal Mask Filter ROM Structure.  \n
                 This Filter type is specific for Signals of \n
                 ComSignalType = SINT8 */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description ComFilterX \n
                     calculation method: equals to ComFilterX*/
    /**************************************************************************/
    VAR(sint8, AUTOMATIC) s8FilterX;

    /**************************************************************************/
    /*! \Description ComFilterMask \n
                     calculation method: equals to ComFilterMask*/
    /**************************************************************************/
    VAR(sint8, AUTOMATIC) s8FilterMask;
} Com_tstrMaskFilterS8;

/******************************************************************************/
/*! \Description Defines a type of Signal Mask Filter ROM Structure.  \n
                 This Filter type is specific for Signals of \n
                 ComSignalType = UINT16 */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description ComFilterX \n
                     calculation method: equals to ComFilterX*/
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16FilterX;

    /**************************************************************************/
    /*! \Description ComFilterMask \n
                     calculation method: equals to ComFilterMask*/
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16FilterMask;
} Com_tstrMaskFilterU16;

/******************************************************************************/
/*! \Description Defines a type of Signal Mask Filter ROM Structure.  \n
                 This Filter type is specific for Signals of \n
                 ComSignalType = SINT16 */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description ComFilterX \n
                     calculation method: equals to ComFilterX*/
    /**************************************************************************/
    VAR(sint16, AUTOMATIC) s16FilterX;

    /**************************************************************************/
    /*! \Description ComFilterMask \n
                     calculation method: equals to ComFilterMask*/
    /**************************************************************************/
    VAR(sint16, AUTOMATIC) s16FilterMask;
} Com_tstrMaskFilterS16;

/******************************************************************************/
/*! \Description Defines a type of Signal Mask Filter ROM Structure.  \n
                 This Filter type is specific for Signals of \n
                 ComSignalType = UINT32 */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description ComFilterX \n
                     calculation method: equals to ComFilterX*/
    /**************************************************************************/
    VAR(uint32, AUTOMATIC) u32FilterX;

    /**************************************************************************/
    /*! \Description ComFilterMask \n
                     calculation method: equals to ComFilterMask*/
    /**************************************************************************/
    VAR(uint32, AUTOMATIC) u32FilterMask;
} Com_tstrMaskFilterU32;

/******************************************************************************/
/*! \Description Defines a type of Signal Mask Filter ROM Structure.  \n
                 This Filter type is specific for Signals of \n
                 ComSignalType = SINT32 */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description ComFilterX \n
                     calculation method: equals to ComFilterX*/
    /**************************************************************************/
    VAR(sint32, AUTOMATIC) s32FilterX;

    /**************************************************************************/
    /*! \Description ComFilterMask \n
                     calculation method: equals to ComFilterMask*/
    /**************************************************************************/
    VAR(sint32, AUTOMATIC) s32FilterMask;
} Com_tstrMaskFilterS32;


/******************************************************************************/
/*! \Description Definitions of types of Signal Masked New Masked Old Filter \n
                 ROM Structures. \n
                 These structures shall be used for filter algorithms: \n
                                    Com_u8F_M_NEW_DIFF_M_OLD      \n */
/******************************************************************************/

/******************************************************************************/
/*! \Description Defines a type of Signal Masked New Masked Old Filter ROM \n
                 Structure.  \n
                 This Filter type is specific for Signals of \n
                 ComSignalType = BOOLEAN */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description Index of the COM_abFilterOldValueB Ram Array holding \n
                     the signal old value \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16OldValueIndex;

    /**************************************************************************/
    /*! \Description ComFilterMask \n
                     calculation method: equals to ComFilterMask*/
    /**************************************************************************/
    VAR(boolean, AUTOMATIC)  bFilterMask;
} Com_tstrMaskOldFilterB;

/******************************************************************************/
/*! \Description Defines a type of Signal Masked New Masked Old Filter ROM \n
                 Structure.  \n
                 This Filter type is specific for Signals of \n
                 ComSignalType = UINT8 */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description Index of the COM_au8FilterOldValueU8 Ram Array holding \n
                     the signal old value \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16OldValueIndex;

    /**************************************************************************/
    /*! \Description ComFilterMask \n
                     calculation method: equals to ComFilterMask*/
    /**************************************************************************/
    VAR(uint8, AUTOMATIC)  u8FilterMask;
} Com_tstrMaskOldFilterU8;

/******************************************************************************/
/*! \Description Defines a type of Signal Masked New Masked Old Filter ROM \n
                 Structure.  \n
                 This Filter type is specific for Signals of \n
                 ComSignalType = SINT8 */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description Index of the COM_aS8FilterOldValueS8 Ram Array holding \n
                     the signal old value \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16OldValueIndex;

    /**************************************************************************/
    /*! \Description ComFilterMask \n
                     calculation method: equals to ComFilterMask*/
    /**************************************************************************/
    VAR(sint8, AUTOMATIC) s8FilterMask;
} Com_tstrMaskOldFilterS8;

/******************************************************************************/
/*! \Description Defines a type of Signal Masked New Masked Old Filter ROM \n
                 Structure.  \n
                 This Filter type is specific for Signals of \n
                 ComSignalType = UINT16 */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description Index of the COM_au16FilterOldValueU16 Ram Array holding \n
                     the signal old value \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16OldValueIndex;

    /**************************************************************************/
    /*! \Description ComFilterMask \n
                     calculation method: equals to ComFilterMask*/
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16FilterMask;
} Com_tstrMaskOldFilterU16;

/******************************************************************************/
/*! \Description Defines a type of Signal Masked New Masked Old Filter ROM \n
                 Structure.  \n
                 This Filter type is specific for Signals of \n
                 ComSignalType = SINT16 */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description Index of the COM_as16FilterOldValueS16 Ram Array holding \n
                     the signal old value \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16OldValueIndex;

    /**************************************************************************/
    /*! \Description ComFilterMask \n
                     calculation method: equals to ComFilterMask*/
    /**************************************************************************/
    VAR(sint16, AUTOMATIC) s16FilterMask;
} Com_tstrMaskOldFilterS16;

/******************************************************************************/
/*! \Description Defines a type of Signal Masked New Masked Old Filter ROM \n
                 Structure.  \n
                 This Filter type is specific for Signals of \n
                 ComSignalType = UINT32 */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description Index of the COM_au32FilterOldValueU32 Ram Array holding \n
                     the signal old value \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16OldValueIndex;

    /**************************************************************************/
    /*! \Description ComFilterMask \n
                     calculation method: equals to ComFilterMask*/
    /**************************************************************************/
    VAR(uint32, AUTOMATIC) u32FilterMask;
} Com_tstrMaskOldFilterU32;

/******************************************************************************/
/*! \Description Defines a type of Signal Masked New Masked Old Filter ROM \n
                 Structure.  \n
                 This Filter type is specific for Signals of \n
                 ComSignalType = SINT32 */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description Index of the COM_as32FilterOldValueS32 Ram Array holding \n
                     the signal old value \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16OldValueIndex;

    /**************************************************************************/
    /*! \Description ComFilterMask \n
                     calculation method: equals to ComFilterMask*/
    /**************************************************************************/
    VAR(sint32, AUTOMATIC) s32FilterMask;
} Com_tstrMaskOldFilterS32;


/******************************************************************************/
/*! \Description Definitions of types of Signal Limits Filter \n
                 ROM Structures. \n
                 These structures shall be used for filter algorithms: \n
                                        Com_u8F_NEW_IS_OUTSIDE        \n
                                        Com_u8F_NEW_IS_WITHIN         \n */
/******************************************************************************/

/******************************************************************************/
/*! \Description Defines a type of Signal Limits Filter ROM Structure.  \n
                 This Filter type is specific for Signals of \n
                 ComSignalType = UINT8 */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description ComFilterMax \n
                     calculation method: equals to ComFilterMax \n*/
    /**************************************************************************/
    VAR(uint8, AUTOMATIC)  u8FilterMax;

    /**************************************************************************/
    /*! \Description ComFilterMin \n
                     calculation method: equals to ComFilterMin \n */
    /**************************************************************************/
    VAR(uint8, AUTOMATIC)  u8FilterMin;
} Com_tstrLimitsFilterU8;

/******************************************************************************/
/*! \Description Defines a type of Signal Limits Filter ROM Structure.  \n
                 This Filter type is specific for Signals of \n
                 ComSignalType = SINT8 */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description ComFilterMax \n
                     calculation method: equals to ComFilterMax*/
    /**************************************************************************/
    VAR(sint8, AUTOMATIC) s8FilterMax;

    /**************************************************************************/
    /*! \Description ComFilterMin \n
                     calculation method: equals to ComFilterMin*/
    /**************************************************************************/
    VAR(sint8, AUTOMATIC) s8FilterMin;
} Com_tstrLimitsFilterS8;

/******************************************************************************/
/*! \Description Defines a type of Signal Limits Filter ROM Structure.  \n
                 This Filter type is specific for Signals of \n
                 ComSignalType = UINT16 */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description ComFilterMax \n
                     calculation method: equals to ComFilterMax*/
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16FilterMax;

    /**************************************************************************/
    /*! \Description ComFilterMin \n
                     calculation method: equals to ComFilterMin*/
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16FilterMin;
} Com_tstrLimitsFilterU16;

/******************************************************************************/
/*! \Description Defines a type of Signal Limits Filter ROM Structure.  \n
                 This Filter type is specific for Signals of \n
                 ComSignalType = SINT16 */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description ComFilterMax \n
                     calculation method: equals to ComFilterMax*/
    /**************************************************************************/
    VAR(sint16, AUTOMATIC) s16FilterMax;

    /**************************************************************************/
    /*! \Description ComFilterMin \n
                     calculation method: equals to ComFilterMin*/
    /**************************************************************************/
    VAR(sint16, AUTOMATIC) s16FilterMin;
} Com_tstrLimitsFilterS16;

/******************************************************************************/
/*! \Description Defines a type of Signal Limits Filter ROM Structure.  \n
                 This Filter type is specific for Signals of \n
                 ComSignalType = UINT32 */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description ComFilterMax \n
                     calculation method: equals to ComFilterMax*/
    /**************************************************************************/
    VAR(uint32, AUTOMATIC) u32FilterMax;

    /**************************************************************************/
    /*! \Description ComFilterMin \n
                     calculation method: equals to ComFilterMin*/
    /**************************************************************************/
    VAR(uint32, AUTOMATIC) u32FilterMin;
} Com_tstrLimitsFilterU32;

/******************************************************************************/
/*! \Description Defines a type of Signal Limits Filter ROM Structure.  \n
                 This Filter type is specific for Signals of \n
                 ComSignalType = SINT32 */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description ComFilterMax \n
                     calculation method: equals to ComFilterMax*/
    /**************************************************************************/
    VAR(sint32, AUTOMATIC) s32FilterMax;

    /**************************************************************************/
    /*! \Description ComFilterMin \n
                     calculation method: equals to ComFilterMin*/
    /**************************************************************************/
    VAR(sint32, AUTOMATIC) s32FilterMin;
} Com_tstrLimitsFilterS32;


/******************************************************************************/
/*! \Description Definition of a type of Signal OneEveryN Filter \n
                 ROM Structures. \n
                 This structures shall be used for filter algorithms: \n
                                    Com_u8F_ONE_EVERY_N \n */
/******************************************************************************/

/******************************************************************************/
/*! \Description Defines a type of Signal OneEveryN ROM \n
                 Structure.  \n
                 This Filter type is used for all ComSignalType values \n */
/******************************************************************************/
typedef struct
{
    /**************************************************************************/
    /*! \Description Index in the COM_au32OneEveryNFilterCounter Ram Array \n
                     holding the filter counter \n */
    /**************************************************************************/
    VAR(uint16, AUTOMATIC) u16CounterIndex;

    /**************************************************************************/
    /*! \Description ComFilterOffset \n
                     calculation method: equals to ComFilterOffset \n
        \Range  0..(ComFilterPeriod-1)    \n */
    /**************************************************************************/
    VAR(uint32, AUTOMATIC) u32FilterOffset;
	
} Com_tstrOneEveryNFilter;

/******************************************************************************/
/*! \Description Defines the I-PDU Group/I-PDU Group Reception Deadline \n
                 Monitoring state Symbols \n */
/******************************************************************************/
#define     Com_u8IPDU_GROUP_STOPPED     (uint8) 0
#define	    Com_u8IPDU_GROUP_STARTED     (uint8) 1

/******************************************************************************/
/*! \Description Defines a type of signal length for GW signals  \n
                 calculation method: equals to ComSignalLength \n
    \Range  0..4095    \n */
/******************************************************************************/
typedef uint16 Com_tu16GWSignalLength;

/******************************************************************************/
/*! \Description Defines a type of I-PDU un-used areas default  \n
                 calculation method:  equals to ComTxIPduUnusedAreasDefault \n
    \Range  0..255    \n */
/******************************************************************************/
typedef uint8 Com_tu8TxUnusedAreasDefault;

/******************************************************************************/
/*! \Description Defines a type of Signal Container  \n
    \Range  Com_u8SIGNAL,Com_u8SIGNAL_GROUP,DEST_DESCRIPTION,SRC_DESCRIPTION    \n */
/******************************************************************************/
typedef uint8 Com_tu8SignalContainerType ;

typedef P2CONST(void,AUTOMATIC,COM_CALIB_CONST) Com_tpkvidConstCalibPtr;
typedef P2CONST(void,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)
                                                Com_tpkvidMaxCalibDataConstPtr;
typedef P2VAR(void, AUTOMATIC, COM_MAX_CALIB_APPL_CFGCONST)
                                                Com_tpvidMaxCalibDataConstPtr;
typedef P2VAR(uint8, AUTOMATIC, COM_MAX_CALIB_APPL_CFGCONST)
                                                Com_tpu8MaxCalibDataConstPtr;
typedef P2CONST(uint8, AUTOMATIC, COM_MAX_CALIB_APPL_CFGCONST)
                                                Com_tpku8MaxCalibDataConstPtr;

#define Com_u8TSIGNAL 0
#define Com_u8SIGNAL_GROUP 1
#define Com_u8DEST_DESCRIPTION 2
#define Com_u8SRC_DESCRIPTION 3
/******************************************************************************/
/*! \Description Defines the invalid value of the Ipdu Ram buffer index  \n
    \Range   0xFFFFFFFFUL  \n */
/******************************************************************************/
#define Com_u32INVALID_BUFFER_INDEX           0xFFFFFFFFUL 
#define Com_u16INVALID_IPDU_ID                0xFFFFU

/******************************************************************************/
/*! \Description Defines the possible return values of the unpack function  \n
    \Range   Com_u8UNPACK_OK , Com_u8UNPACK_NOT_OK ,Com_u8UNPACK_NOK_FLTR_OUT \n
             Com_u8UNPACK_NOK_INV_REP ,Com_u8UNPACK_NOK_INV_NOT    */
/******************************************************************************/
/******************************************************************************/
#define Com_u8UNPACK_OK              0
#define Com_u8UNPACK_NOT_OK          1
#define Com_u8UNPACK_NOK_FLTR_OUT    2
#define Com_u8UNPACK_NOK_INV_REP     3
#define Com_u8UNPACK_NOK_INV_NOT     4
/*****************************************************************************/
/*! \Description Defines the size in byte taken by the dynamic signal length.\n
                 This offset will be added to the signal object index to     \n
                 to retrive the actual signal object value
    \Range   2  \n */
/******************************************************************************/
#define Com_u8U8DYN_OBJ_IX_OFFSET         0x02

/******************************************************************************/
/*! \Description Holds the pointer to the main PB configuration \n */
/******************************************************************************/
#if (Com_bRCV_SIG_GEN_ENABLE == STD_OFF)
#define COM_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
extern P2CONST(Com_ConfigType,AUTOMATIC,COM_CALIB_CONST) Com_pkstreMainConfig;
#define COM_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"
#endif

/******************************************************************************/
/*! \Description Holds COM module status \n */
/******************************************************************************/
#define COM_START_SEC_VAR_8
#include "MemMap.h"
extern VAR(Com_StatusType,COM_VAR) Com_enueStatus ;
#define COM_STOP_SEC_VAR_8
#include "MemMap.h"


/******************************************************************************/
/*!	\Description Size of Com_aku8eBitMaskArray
*******************************************************************************/
#define COM_u8BIT_MASK_ARRAY_SIZE (uint8) 8

extern CONST(uint8, COM_CONST)
                          Com_aku8eBitMaskArray [COM_u8BIT_MASK_ARRAY_SIZE];
						  
/* !Deviation: [3412] and [3459]  It's typical do-while(0) loop & it's safe, Resolving such an issue shall lower the readability of the code with no benifits */
/* PRQA S 3412, 3459 L1 */
#define Com_bGETBIT(pku8Vector, u16BitPosition, bRetunValue) \
do \
{ \
  VAR(uint16, AUTOMATIC)    u16BytePos; \
  VAR(uint8, AUTOMATIC)     u8MaskIndex; \
  u16BytePos = (u16BitPosition) >> 3; \
  u8MaskIndex = (uint8)((u16BitPosition) & 0x0007);\
  if(((pku8Vector)[u16BytePos] & Com_aku8eBitMaskArray[u8MaskIndex]) == \
                               Com_aku8eBitMaskArray[u8MaskIndex]) \
  { \
    (bRetunValue) = TRUE; \
  } \
  else \
  { \
    (bRetunValue) = FALSE; \
  } \
}while(0)

 /* PRQA S 3453 ++ */
#define Com_bGETBITRXSIGNAL(pku8Vector, u16BitPosition) \
	(((pku8Vector)[(u16BitPosition) >> 3]) >> ((uint8)((u16BitPosition) & 0x0007) & (0x0001)))
 
#define Com_bGETBITOPT(pku8Vector, u16BitPosition) \
(boolean)((pku8Vector)[ ((u16BitPosition) >> 3) ] & ((uint16)1u <<((u16BitPosition) & 7))) 
/* PRQA S 3453 -- */

	
#define Com_vidSETBIT(pu8Vector, u16BitPosition, bBitValue) \
do \
{ \
  if((bBitValue) == FALSE) \
  { \
    (pu8Vector)[(u16BitPosition) >> 3] = \
      ((pu8Vector)[(u16BitPosition) >> 3] & \
        (uint8)(~Com_aku8eBitMaskArray[(((u16BitPosition) & 0x0007))])); \
  } \
  else \
  { \
    (pu8Vector)[(u16BitPosition) >> 3] = \
             ((pu8Vector)[(u16BitPosition) >> 3] | \
                (Com_aku8eBitMaskArray[(((u16BitPosition) & 0x0007))])); \
  } \
}while(0)
/* PRQA L:L1 */

/******************************************************************************/
/*! \Description Checks the status of the I-PDU group containing \n
                 the I-PDU identified by PduId. This macro is used at both \n
                 sender and receiver sides.
*******************************************************************************/
/*! \Trace_To  */

 /* PRQA S 3453 ++ */
#define Com_vidIPDUCHECKACTIVE(PduId) \
	((Com_audteIPduStatus[PduId] & (Com_u8ACTIVE_MASK)) != FALSE)
 /* PRQA S 3453 -- */
	

/******************************************************************************/
/*! \Description Holds the  status of the COM module \n
    \Range  COM_UNINIT , COM_INIT*/
/******************************************************************************/


/******************************************************************************/
/*! \Description Internal function declarations \n */
/******************************************************************************/
#define COM_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, COM_CODE)
    Com_vidInitTxIpdu ( VAR(PduIdType, AUTOMATIC) u16PduId,
                        VAR(boolean, AUTOMATIC) bBulkInitMode );

extern FUNC(void, COM_CODE)
  Com_vidInitRxIpdu ( VAR(PduIdType, AUTOMATIC) u16PduId,
                      VAR(boolean, AUTOMATIC) bBulkInitMode );

extern FUNC(boolean,COM_CODE)
  Com_bExtractBitVector( P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)
                                                                    pku8Vector,
                         VAR(uint16,AUTOMATIC) u16BitPosition );

extern FUNC(void,COM_CODE)
  Com_vidSetBitVector( P2VAR(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)
                                             pu8Vector,
                       VAR(uint16,AUTOMATIC) u16BitPosition,
                       VAR(boolean,AUTOMATIC) bBitValue);

extern FUNC(boolean, COM_CODE)
  Com_bIpduCheckActive( CONST(PduIdType, AUTOMATIC) PduId );


extern FUNC(boolean, COM_CODE)
  Com_bEvaluateTxMode( VAR(PduIdType,AUTOMATIC) PduId );

extern FUNC(PduR_ReturnType, COM_CODE)
 Com_u8SendIPdu( VAR(PduIdType, AUTOMATIC) u16PduId,
                 VAR(boolean, AUTOMATIC) bDecMDT);

extern FUNC(boolean, COM_CODE)
  Com_bSignalIsChanged( VAR(Com_SignalIdType,AUTOMATIC)   u16SignalId,
                        P2CONST(void,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)
                                                          pkvidSignalNewDataPtr,
                        VAR(uint16, AUTOMATIC)            u16DynLength);

extern FUNC(boolean, COM_CODE) Com_bSignalGroupIsChanged(
                        VAR(Com_SignalGroupIdType, AUTOMATIC) u16SignalGroupId);

extern FUNC(boolean,COM_CODE) Com_bSignalApplyFilter(
                       VAR(Com_SignalIdType,AUTOMATIC) u16SigIx,
                       P2CONST(void,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST) pkvidSignalDataPtr,
					   VAR(uint8,AUTOMATIC)            u8SigStrcture) ;

extern FUNC(void,COM_CODE)
  Com_vidSignalEditUpdateBit( VAR(Com_tu8SignalContainerType,AUTOMATIC) u8SigContainer,
                              VAR(uint16,AUTOMATIC)              u16Index,
							  VAR(uint16,AUTOMATIC)              u16UpdateBitPosition,
                              VAR(boolean,AUTOMATIC)             bValue );


extern FUNC(boolean,COM_CODE)
  Com_bSignalCheckUpdateBit ( P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)
                                                                pku8IpduFirstByte,
								VAR(uint16,AUTOMATIC)            u16UBIx);

extern FUNC(uint8,COM_CODE)
  Com_u8SignalUnPackSignal( VAR(Com_SignalIdType,AUTOMATIC)       u16SignalId,
                                P2CONST(PduInfoType,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)
                                                                   pkstrPduInfoPtr );

extern FUNC(Std_ReturnType,COM_CODE)
  Com_u8IpduCheckDataSeq ( VAR(uint16,AUTOMATIC)               u16IPduIx,
                           P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)
                                                            pku8IpduFirstByte );

extern FUNC(void,COM_CODE)
  Com_vidIpduPackDataSeq ( VAR(PduIdType,AUTOMATIC) u16IPduId );

extern FUNC(void,COM_CODE) Com_vidRxIpduResetDM(
                         VAR(uint16,AUTOMATIC)  u16IpduIx);
						 
extern FUNC(boolean,COM_CODE) Com_bRxIpduCheckDM (
                         VAR(PduIdType,AUTOMATIC)  u16IpduIx) ;
extern FUNC(void,COM_CODE) Com_vidSignalResetDM(
                       VAR(Com_tu8SignalContainerType,AUTOMATIC)       u8SigContainer,
                       VAR(uint16,AUTOMATIC)                    u16Index );

extern FUNC(void,COM_CODE) Com_vidSignalHandleDM(
                    VAR(Com_tu8SignalContainerType,AUTOMATIC) u8SigContainer ,
                    VAR(uint16,AUTOMATIC)              u16Index);

extern FUNC(Com_tpkvidConstCalibPtr,COM_CODE)
  Com_pkvidInitSigObjnOldVal(
                    VAR(Com_tu8SignalContainerType,AUTOMATIC)   u8SigStructType ,
                    VAR(uint16,AUTOMATIC)                       u16SigIx,
                    VAR(boolean,AUTOMATIC)                      bInitOldVal);

extern FUNC(boolean, COM_CODE)
  Com_bIpduCheckRxDMActive(CONST(PduIdType, AUTOMATIC) ku16PduId);

/******************************************************************************/
/*! \Description This function returns group signal shadow buffer pointer
  \param[in]   u16SignalId  signal Handle ID
  \return      group signal shadow buffer pointer in the form of pointer to void
*******************************************************************************/
extern FUNC(Com_tpvidMaxCalibDataConstPtr, COM_CODE)
        Com_pvidGetGSigShadowPtr(VAR(Com_SignalIdType, AUTOMATIC) u16SignalIx);

/******************************************************************************/
/*! \Description  This service initializes timeout for Rx I-PDU
    \param[in]  RxPduId I-PDU ID which timeout shall be reset
*******************************************************************************/
/*! \Trace_To   */
extern FUNC(void, COM_CODE)
      Com_vidInitTORxIpdu(CONST(uint16, AUTOMATIC) ku16IPduIndex);
/******************************************************************************/
/*! \Description  This service clears timeout for Tx I-PDU
    \param[in]  TxPduId I-PDU ID which timeout shall be cleared
*******************************************************************************/
/*! \Trace_To   */

extern FUNC(void, COM_CODE)
      Com_vidClearTOTxIpdu(CONST(uint16, AUTOMATIC) ku16TxPduIx);

extern FUNC(void,COM_CODE) Com_vidCopySigObj2Shadow(
                    VAR(Com_SignalGroupIdType,AUTOMATIC)         u16SignalGroupId);
					
					
/******************************************************************************/
/*! \Description This function returns signal, group signal or GW \n
                 description object pointer
  \param[in]   u16SignalId  signal Handle ID
  \return      Signal, group signal or GW description object pointer in the \n
               form of pointer to void
*******************************************************************************/
extern FUNC(Com_tpkvidMaxCalibDataConstPtr, COM_CODE)
            Com_pkvidGetSigObjPtr(VAR(Com_SignalIdType, AUTOMATIC) u16SignalId);

#define COM_STOP_SEC_CODE
#include "MemMap.h"


#endif /* COM_INTERNAL_H */
/* PRQA S 0850 --                                                              */
/** \} */ /* end of Com module group */
