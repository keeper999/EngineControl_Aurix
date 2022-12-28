/* PRQA S 8014, 8114, 8314, 8414, 8614 ++*/
/* !Deviation: [8014] [8114] [8314] [8614] Violates VNR on file naming rules
 * because file names are imposed by AutOSAR requirements */
/******************************************************************************/
/*                                                                            */
/* !Layer           : Service                                                 */
/*                                                                            */
/* !Component       : ComM                                                    */
/* !Description     : Communication Manager Module                            */
/*                                                                            */
/* !Module          : ComM                                                    */
/*                                                                            */
/* !File            : ComM_Cfg.c                                              */
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
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/04-ComM/02$*/
/* $Revision::   1.8      $$Author::   mtayel         $$Date::   Jan 01 2012 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/



#include "ComM.h"
#if (ComM_bDEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif /* ComM_bDEV_ERROR_DETECT */


#include "SchM_ComM.h"

#if (ComM_bMODE_LIMIT_ENABLE == TRUE)
#include "Users_NvM.h"
#endif /* ComM_bMODE_LIMIT_ENABLE */

#if (ComM_bCAN_USED == TRUE)
#include "CanSM_ComM.h"
#endif /* ComM_bCAN_USED */

#if (ComM_bLIN_USED == TRUE)
#include "LinSM.h"
#endif /* ComM_bLIN_USED */

#if (ComM_bFR_USED == TRUE)
#include "FrSM.h"
#endif /* ComM_bFR_USED */

#if (ComM_bETH_USED == TRUE)
#include "EthSM.h"
#endif /* ComM_bETH_USED */


#include "User_ComM.h"


#include "ComM_Internal.h"
/* !Deviation: [3453] Violates MISRA rule 93: "A function should be used in
    preference to a function-like macro." but these function-like macros are
    only to abbreviate long function calls to make the code more readable and to
    avoid breaking the 80 characters mark.
*/
/* !Deviation: [3456] "parameter X will be evaluated more than once when this
    macro is used", the only danger this imposes is when the argument is
    something like i++, but since there is another rule that inhibits this then
    no harm will be done.
*/
/* PRQA S 3453, 3456 ++*/

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/
#define bCHK_LIMNOCOM_GC ((ComM_u8eECUGClassification & 0x02) >> 1)
#define bCHK_NOWAKEUP_GC (ComM_u8eECUGClassification % 0x02)


#define bMANY_USERS_OF_CH(CH)   bTMANY_USERS_OF_CH(CH)
#define u8USER_OF_CHANNEL(CH)   u8TUSER_OF_CHANNEL(CH)
#define u8NO_USERS_OF_CH(CH)    u8TNO_USERS_OF_CH(CH)
#define u8NM_VARIANT(CH)        u8TNM_VARIANT(CH)
#define bINTERNAL_BUS(CH)       bTINTERNAL_BUS(CH)
#define u32NM_LIGHT_TIMEOUT(CH) u32TNM_LIGHT_TIMEOUT(CH)
#define u32MIN_FULL_COUNT(CH)   u32TMIN_FULL_COUNT(CH)
#define bFULL_COM_REQ_SRI(CH)   bTFULL_COM_REQ_SRI(CH)
#define vidMAIN_FUNC(CH)        vidTMAIN_FUNC(CH)
/* PRQA S 3453, 3456 --*/
#define bTMANY_USERS_OF_CH(CH)   ComM_bMANY_USERS_OF_CH_##CH
#define u8TUSER_OF_CHANNEL(CH)   ComM_u8USER_OF_CHANNEL_##CH
#define u8TNO_USERS_OF_CH(CH)    ComM_u8NO_USERS_OF_CH_##CH
#define u8TNM_VARIANT(CH)        ComM_u8NM_VARIANT_##CH
#define bTINTERNAL_BUS(CH)       ComM_bINTERNAL_BUS_##CH
#define u32TNM_LIGHT_TIMEOUT(CH) ComM_u32NM_LIGHT_TIMEOUT_##CH
#define u32TMIN_FULL_COUNT(CH)   ComM_u32MIN_FULL_COUNT_##CH
#define bTFULL_COM_REQ_SRI(CH)   ComM_bFULL_COM_REQ_SRI_##CH
#define vidTMAIN_FUNC(CH)        ComM_MainFunction_##CH


#define u8INSTANCE_ID          0x00
#define u8MAIN_FUNCTION_ID     0x60

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

#define COMM_START_CONFIG_DATA_UNSPECIFIED
/* PRQA S 0838, 5087 L1 */
#include "MemMap.h"
/* PRQA L:L1 */
/**********************************************/
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */

CONST(ComM_tpfu8ModeMSI, COMM_CFG_CONST) ComM_akpfu8eUserModeMSIArray[] =
{
    User_Switch_UM000_currentMode,
    User_Switch_UM001_currentMode
};


/* Users' Channels arrays */
/* !Deviation: [3674] magic numbers were used since these are statically defined
   arrays generated by a configuration tool.
 */
/* PRQA S 3674 ++*/


static CONST(NetworkHandleType, COMM_CFG_CONST) aku8Usr0Channels [] =
{
    0,
    1
};

static CONST(NetworkHandleType, COMM_CFG_CONST) aku8Usr1Channels [] =
{
    2
};

/**************************/


/* Channels' Users arrays */

static CONST(ComM_UserHandleType, COMM_CFG_CONST) aku8Ch0Users [] =
{
    0
};

static CONST(ComM_UserHandleType, COMM_CFG_CONST) aku8Ch1Users [] =
{
    0
};

static CONST(ComM_UserHandleType, COMM_CFG_CONST) aku8Ch2Users [] =
{
    1
};

CONST(ComM_tudtChannelsPerUserType, COMM_CFG_CONST)
             ComM_akudteChannelsPerUser[ComM_u8NO_OF_USERS] =
{
    {
        2,
        aku8Usr0Channels
    },
    {
        1,
        aku8Usr1Channels
    }
};

/* !Deviation: [0841] "The parameter identifiers in the prototypes of these
    functions/function pointers are different.", this is the initialisation of
    an an array of pointer-to-functions with these functions, this is neither a
    prototype nor a declaration.
 */
/* PRQA S 1334 ++*/

CONST(ComM_tpfu8RequestComMode, COMM_CFG_CONST)
                                ComM_akpfu8eRequestComModeArray[] =
{
    CanSM_RequestComMode,
    CanSM_RequestComMode,
    LinSM_RequestComMode
};

CONST(ComM_tpfu8GetCurrentComMode, COMM_CFG_CONST)
                                   ComM_akpfu8eGCurComModeArray[] =
{
    CanSM_GetCurrentComMode,
    CanSM_GetCurrentComMode,
    LinSM_GetCurrentComMode
};

/* PRQA S 1334 ++*/
/* ComMChannel --> ComMUserPerChannel
   each structure in the array corresponds to a channel, and each structure has
   an integer and an array, the integer is the multiplicity of the
   ComMUserPerChannel Container and the array members are the UserHandle member
   of the Container */
CONST(ComM_tudtUsersPerChannelType, COMM_CFG_CONST)
             ComM_akudteUsersPerChannel[ComM_u16NO_OF_CHANNELS] =
{
    {
        1,
        aku8Ch0Users
    },
    {
        1,
        aku8Ch1Users
    },
    {
        1,
        aku8Ch2Users
    }
};


/* PRQA S 0850 --                                                             */

/* PRQA S 3674 --*/


/* PRQA S 3674 --*/
#define COMM_STOP_CONFIG_DATA_UNSPECIFIED
/* PRQA S 0838, 5087 L1 */
#include "MemMap.h"
/* PRQA L:L1 */

#define COMM_START_SEC_CODE
/* PRQA S 0838, 5087 L1 */
#include "MemMap.h"
/* PRQA L:L1 */

/*! Tip for configuration tool: The following CHANNEL_ID and CHANNEL_ID_TEXT
    symbols definition will need to be undefined and redefined for each Main
    function so that each one can address both its configurations and its
    corresponding attributes in Data arrays.
    CHANNEL_ID needs to be defined with the channels number, preferably the
               hexa-decimal equivalent.
    CHANNEL_ID_TEXT ranges from "000" to "255" so that configurations can be
    sorted alphabetically. (imposed on the main function by the SWS document)
    */


#define CHANNEL_ID 0x00
/* !Deviation: [0841] "Macro defined as an octal constant." this is not an octal
    constant, this is a number to be pasted using token pasting to get channel's
    configurations, it is never used as a number, the Token that is used as
    a number is the previously defined CHANNEL_ID which is defined as a
    hexa-decimal value.
 */
/* PRQA S 0336 ++*/

#define CHANNEL_ID_TEXT 000
/* PRQA S 0336 --*/

/*! \Trace_To
    ComM-CDD-0179(0), ComM-CDD-5045(0), ComM-CDD-0058(0), ComM-CDD-5307(0),
    ComM-CDD-5134(0), ComM-CDD-5278(0), ComM-CDD-5077(0), ComM-CDD-5171(0),
    ComM-CDD-5087(0), ComM-CDD-5090(0), ComM-CDD-5091(0), ComM-CDD-5284(0),
    ComM-CDD-5095(0), ComM-CDD-5099(0), ComM-CDD-5102(0), ComM-CDD-0112(0),
    ComM-CDD-5118(0), ComM-CDD-5100(0), ComM-CDD-5106(0), ComM-CDD-5108(0),
    ComM-CDD-5037(0), ComM-CDD-5262(0), ComM-CDD-5114(0), ComM-CDD-5153(0),
    ComM-CDD-5160(0), ComM-CDD-0060(0), ComM-CDD-0061(0), ComM-CDD-0064(0),
    ComM-CDD-5212(0), ComM-CDD-5251(0), ComM-CDD-5253(0), ComM-CDD-5076(0),
    ComM-CDD-5092(0), ComM-CDD-5281(0), ComM-CDD-5277(0), ComM-CDD-5274(0),
    ComM-CDD-5279(0), ComM-CDD-0053(0), ComM-CDD-0054(0), ComM-CDD-5326(0),
    ComM-CDD-5327(0), ComM-CDD-5328(0), ComM-SRS-0300(0), ComM-CDD-5330(0),
    ComM-CDD-5332(0), ComM-CDD-5333(0), ComM-CDD-5334(0), ComM-CDD-5335(0),
    ComM-CDD-5336(0), ComM-CDD-5338(0), ComM-CDD-5339(0), ComM-CDD-5340(0),
    ComM-CDD-0257(0), ComM-CDD-0269(0), ComM-CDD-0273(0), ComM-CDD-0276(0),
    ComM-CDD-0278(0), ComM-CDD-0287(0), ComM-CDD-0290(0), ComM-CDD-0292(0),
    ComM-CDD-0293(0), ComM-CDD-5311(0), ComM-CDD-5312(0), ComM-CDD-5313(0),
    ComM-CDD-5314(0), ComM-CDD-5315(0), ComM-CDD-5310(0), ComM-CDD-5319(0),
    ComM-CDD-5341(0), ComM-CDD-0241(0), ComM-CDD-0300(0), ComM-CDD-5344(0),
    ComM-CDD-5345(0), ComM-CDD-0322(0), ComM-CDD-0323(0), ComM-CDD-0325(0)
    ComM-CDD-0336(0), ComM-CDD-0339(0)*/
/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
FUNC(void, COMM_CODE) vidMAIN_FUNC(CHANNEL_ID_TEXT)(void)
/* PRQA S 0850 --                                                             */
{
    /*0x60*/
    #if ((u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_LIGHT)\
       ||(u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_NONE))
    /* !Deviation: [3871] "Identifier with static storage duration declared at
        block scope."
        This is because some main functions need the timer counter and some do
        not, to define a global array of counters we will either have to assign
        a #define for each channel to map it to its value in that array (which
        is quite the overhead on configuration) or we will have to define that
        array with its size as the no. of channels which is a huge waste of
        memory, so a statically defined variable inside each main function that
        require a timer is a better idea.
    */
    /* PRQA S 3223 ++*/
    static uint32            LOC_u32Cycles = 0;
    /* PRQA S 3223 --*/
    #endif /* u8NM_VARIANT(CHANNEL_ID_TEXT) */
    #if (u8NM_VARIANT(CHANNEL_ID_TEXT) != ComM_u8NMVARIANT_PASSIVE)
    #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
    boolean                  bLimToNoCom;
    #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
    boolean                  bNoWakeUp;
    #endif /* ComM_bWAKEUP_INH_ENABLE */
    #endif /* ComM_bMODE_LIMIT_ENABLE */
    #endif /* u8NM_VARIANT(CHANNEL_ID_TEXT) */
    #if (bFULL_COM_REQ_SRI(CHANNEL_ID_TEXT) == TRUE)
    ComM_UserHandleArrayType udtSRIStruct;
    #endif /* bFULL_COM_REQ_SRI(CHANNEL_ID_TEXT) */
    #if ((u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_FULL)\
                ||(u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_PASSIVE))
    #if (ComM_bPNC_SUPPORT == TRUE)
    #if (ComM_bPNC_GW_ENABLED == TRUE)
    #if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
    uint8_least u8Idx;
    #endif /* ComM_u8NO_SIZE_OF_SIG_ARR */
    #endif /* ComM_bPNC_GW_ENABLED */
    #endif /* ComM_bPNC_SUPPORT */
    #endif /* (ComM_u8NMVARIANT_FULL)||(ComM_u8NMVARIANT_PASSIVE) */
    /*! Reject Service if ComM is not initialised */
    if (ComM_udteInitStatus != COMM_UNINIT)
    {
        #if ((u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_FULL)\
                ||(u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_PASSIVE))
        #if (ComM_bPNC_SUPPORT == TRUE)
        #if (ComM_bPNC_GW_ENABLED == TRUE)
        SchM_Enter_ComM_AggEraGwSignal();
        #if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
        for (u8Idx = 0; u8Idx < ComM_u8NO_SIZE_OF_SIG_ARR; u8Idx++)
        {
        #endif /*ComM_u8NO_SIZE_OF_SIG_ARR */
          ComM_au8T_SIG(ComM_au8eTxERAAgg,u8Idx) =
                                         ComM_au8T_SIG(ComM_au8eAggregERASig, u8Idx);
        #if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
        }
        #endif /*ComM_u8NO_SIZE_OF_SIG_ARR */
        SchM_Exit_ComM_AggEraGwSignal();
        #endif /* ComM_bPNC_GW_ENABLED */
        #endif /* ComM_bPNC_SUPPORT */
        #endif /* (ComM_u8NMVARIANT_FULL)||(ComM_u8NMVARIANT_PASSIVE) */

        /*! Check Channel's configuration and call the appropriate state manager
            with channel's specific arguments */
        #if   (u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_PASSIVE)
        ComM_vidManagePASSIVESM(CHANNEL_ID);
        #elif (u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_FULL)
        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
        bLimToNoCom = ((bCHK_LIMNOCOM_GC == 1)
                     &&(ComM_abeLimitToNoComStatus[CHANNEL_ID] != FALSE));
        #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
        bNoWakeUp = ((bCHK_NOWAKEUP_GC == 1) &&
                    (ComM_abeWakeUpInibitStatus[CHANNEL_ID] != FALSE));
        #endif /* ComM_bWAKEUP_INH_ENABLE */
        #endif /* ComM_bMODE_LIMIT_ENABLE */
        ComM_vidManageFULLSM(CHANNEL_ID,
                        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                        bLimToNoCom,
                        #endif /* ComM_bMODE_LIMIT_ENABLE */
                        ComM_bEvalChUserRequest(CHANNEL_ID)
                        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                        #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                        , bNoWakeUp
                        #endif /* ComM_bWAKEUP_INH_ENABLE */
                        #endif /* ComM_bMODE_LIMIT_ENABLE */
                        );
        #elif (u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_LIGHT)
        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
        bLimToNoCom = ((bCHK_LIMNOCOM_GC == 1)
                     &&(ComM_abeLimitToNoComStatus[CHANNEL_ID] != FALSE));
        #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
        bNoWakeUp = ((bCHK_NOWAKEUP_GC == 1) &&
                    (ComM_abeWakeUpInibitStatus[CHANNEL_ID] != FALSE));
        #endif /* ComM_bWAKEUP_INH_ENABLE */
        #endif /* ComM_bMODE_LIMIT_ENABLE */
        ComM_vidManageLIGHTSM(CHANNEL_ID,
                         #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                         bLimToNoCom,
                         #endif /* ComM_bMODE_LIMIT_ENABLE */
                         ComM_bEvalChUserRequest(CHANNEL_ID),
                         &LOC_u32Cycles,
                         u32MIN_FULL_COUNT(CHANNEL_ID_TEXT),
                         #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                         #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                         bNoWakeUp,
                         #endif /* ComM_bWAKEUP_INH_ENABLE */
                         #endif /* ComM_bMODE_LIMIT_ENABLE */
                         u32NM_LIGHT_TIMEOUT(CHANNEL_ID_TEXT));
        #elif ((u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_NONE)\
                && (bINTERNAL_BUS(CHANNEL_ID_TEXT) != FALSE))
        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
        bLimToNoCom = ((bCHK_LIMNOCOM_GC == 1)
                     &&(ComM_abeLimitToNoComStatus[CHANNEL_ID] != FALSE));
        #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
        bNoWakeUp = ((bCHK_NOWAKEUP_GC == 1) &&
                     (ComM_abeWakeUpInibitStatus[CHANNEL_ID] != FALSE));
        #endif /* ComM_bWAKEUP_INH_ENABLE */
        #endif /* ComM_bMODE_LIMIT_ENABLE */
        ComM_vidManInternalNONESM(CHANNEL_ID,
                             #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                             bLimToNoCom,
                             #endif /* ComM_bMODE_LIMIT_ENABLE */
                             ComM_bEvalChUserRequest(CHANNEL_ID),
                             &LOC_u32Cycles,
                             u32MIN_FULL_COUNT(CHANNEL_ID_TEXT)
                             #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                             #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                             , bNoWakeUp
                             #endif /* ComM_bWAKEUP_INH_ENABLE */
                             #endif /* ComM_bMODE_LIMIT_ENABLE */
                             );
        #else
        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
        bLimToNoCom = ((bCHK_LIMNOCOM_GC == 1)
                     &&(ComM_abeLimitToNoComStatus[CHANNEL_ID] != FALSE));
        #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
        bNoWakeUp = ((bCHK_NOWAKEUP_GC == 1) &&
                    (ComM_abeWakeUpInibitStatus[CHANNEL_ID] != FALSE));
        #endif /* ComM_bWAKEUP_INH_ENABLE */
        #endif /* ComM_bMODE_LIMIT_ENABLE */
        ComM_vidManNotInternalNONESM(CHANNEL_ID,
                                #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                                bLimToNoCom,
                                #endif /* ComM_bMODE_LIMIT_ENABLE */
                                ComM_bEvalChUserRequest(CHANNEL_ID),
                                &LOC_u32Cycles,
                                u32MIN_FULL_COUNT(CHANNEL_ID_TEXT)
                                #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                                #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                                , bNoWakeUp
                                #endif /* ComM_bWAKEUP_INH_ENABLE */
                                #endif /* ComM_bMODE_LIMIT_ENABLE */
                                );
        #endif /* u8NM_VARIANT(CHANNEL_ID_TEXT) */

        /*! if channel's fullComRequestors SenderReceiverInterface is enabled
            for this channel check channel's value in ComM_abChannelReqsUpdated
            */
        #if (bFULL_COM_REQ_SRI(CHANNEL_ID_TEXT) == TRUE)
        if (ComM_abeChannelReqsUpdated[CHANNEL_ID] != FALSE)
        {
            /*! if TRUE call vidCreateFCOMReqStruct() to create the structure */
            ComM_vidCreateFCOMReqStruct(CHANNEL_ID, &udtSRIStruct);
            /*! Call the SRI function to write the structure in the RTE */

            (void)User_Write_CR000_fullComRequestors(&udtSRIStruct);
        }
        #endif /* bFULL_COM_REQ_SRI(CHANNEL_ID_TEXT) */
        #if (ComM_bPNC_SUPPORT == TRUE)
        #if   ((u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_FULL)\
                || (u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_PASSIVE))
        if (ComM_bePncEnabled != FALSE)
        {
            ComM_vidEraEiraHEvaluate(CHANNEL_ID
              );
        }
        #endif  /* u8NM_VARIANT(CHANNEL_ID_TEXT) */
        #endif /* ComM_bPNC_SUPPORT */
    }
}
/* !Deviation: [0841] Violates MISRA Rule 92: "#undef should not be used", this
    rule is minor, and redefinition without #undef results in two QA C errors
    and a compiler warning, so ignoring the rule seems like a better idea.
 */
/* PRQA S 0841 ++*/
#undef CHANNEL_ID
#undef CHANNEL_ID_TEXT


#define CHANNEL_ID 0x01
/* !Deviation: [0841] "Macro defined as an octal constant." this is not an octal
    constant, this is a number to be pasted using token pasting to get channel's
    configurations, it is never used as a number, the Token that is used as
    a number is the previously defined CHANNEL_ID which is defined as a
    hexa-decimal value.
 */
/* PRQA S 0336 ++*/

#define CHANNEL_ID_TEXT 001
/* PRQA S 0336 --*/

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
FUNC(void, COMM_CODE) vidMAIN_FUNC(CHANNEL_ID_TEXT)(void)
/* PRQA S 0850 --                                                             */
{
    /*0x60*/
    #if ((u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_LIGHT)\
       ||(u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_NONE))
    /* !Deviation: [3871] "Identifier with static storage duration declared at
        block scope."
        This is because some main functions need the timer counter and some do
        not, to define a global array of counters we will either have to assign
        a #define for each channel to map it to its value in that array (which
        is quite the overhead on configuration) or we will have to define that
        array with its size as the no. of channels which is a huge waste of
        memory, so a statically defined variable inside each main function that
        require a timer is a better idea.
    */
    /* PRQA S 3223 ++*/
    static uint32            LOC_u32Cycles = 0;
    /* PRQA S 3223 --*/
    #endif /* u8NM_VARIANT(CHANNEL_ID_TEXT) */
    #if (u8NM_VARIANT(CHANNEL_ID_TEXT) != ComM_u8NMVARIANT_PASSIVE)
    #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
    boolean                  bLimToNoCom;
    #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
    boolean                  bNoWakeUp;
    #endif /* ComM_bWAKEUP_INH_ENABLE */
    #endif /* ComM_bMODE_LIMIT_ENABLE */
    #endif /* u8NM_VARIANT(CHANNEL_ID_TEXT) */
    #if (bFULL_COM_REQ_SRI(CHANNEL_ID_TEXT) == TRUE)
    ComM_UserHandleArrayType udtSRIStruct;
    #endif /* bFULL_COM_REQ_SRI(CHANNEL_ID_TEXT) */
    #if ((u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_FULL)\
                ||(u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_PASSIVE))
    #if (ComM_bPNC_SUPPORT == TRUE)
    #if (ComM_bPNC_GW_ENABLED == TRUE)
    #if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
    uint8_least u8Idx;
    #endif /* ComM_u8NO_SIZE_OF_SIG_ARR */
    #endif /* ComM_bPNC_GW_ENABLED */
    #endif /* ComM_bPNC_SUPPORT */
    #endif /* (ComM_u8NMVARIANT_FULL)||(ComM_u8NMVARIANT_PASSIVE) */
    /*! Reject Service if ComM is not initialised */
    if (ComM_udteInitStatus != COMM_UNINIT)
    {
        #if ((u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_FULL)\
                ||(u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_PASSIVE))
        #if (ComM_bPNC_SUPPORT == TRUE)
        #if (ComM_bPNC_GW_ENABLED == TRUE)
        SchM_Enter_ComM_AggEraGwSignal();
        #if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
        for (u8Idx = 0; u8Idx < ComM_u8NO_SIZE_OF_SIG_ARR; u8Idx++)
        {
        #endif /*ComM_u8NO_SIZE_OF_SIG_ARR */
          ComM_au8T_SIG(ComM_au8eTxERAAgg,u8Idx) =
                                         ComM_au8T_SIG(ComM_au8eAggregERASig, u8Idx);
        #if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
        }
        #endif /*ComM_u8NO_SIZE_OF_SIG_ARR */
        SchM_Exit_ComM_AggEraGwSignal();
        #endif /* ComM_bPNC_GW_ENABLED */
        #endif /* ComM_bPNC_SUPPORT */
        #endif /* (ComM_u8NMVARIANT_FULL)||(ComM_u8NMVARIANT_PASSIVE) */

        /*! Check Channel's configuration and call the appropriate state manager
            with channel's specific arguments */
        #if   (u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_PASSIVE)
        ComM_vidManagePASSIVESM(CHANNEL_ID);
        #elif (u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_FULL)
        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
        bLimToNoCom = ((bCHK_LIMNOCOM_GC == 1)
                     &&(ComM_abeLimitToNoComStatus[CHANNEL_ID] != FALSE));
        #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
        bNoWakeUp = ((bCHK_NOWAKEUP_GC == 1) &&
                    (ComM_abeWakeUpInibitStatus[CHANNEL_ID] != FALSE));
        #endif /* ComM_bWAKEUP_INH_ENABLE */
        #endif /* ComM_bMODE_LIMIT_ENABLE */
        ComM_vidManageFULLSM(CHANNEL_ID,
                        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                        bLimToNoCom,
                        #endif /* ComM_bMODE_LIMIT_ENABLE */
                        ComM_bEvalChUserRequest(CHANNEL_ID)
                        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                        #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                        , bNoWakeUp
                        #endif /* ComM_bWAKEUP_INH_ENABLE */
                        #endif /* ComM_bMODE_LIMIT_ENABLE */
                        );
        #elif (u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_LIGHT)
        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
        bLimToNoCom = ((bCHK_LIMNOCOM_GC == 1)
                     &&(ComM_abeLimitToNoComStatus[CHANNEL_ID] != FALSE));
        #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
        bNoWakeUp = ((bCHK_NOWAKEUP_GC == 1) &&
                    (ComM_abeWakeUpInibitStatus[CHANNEL_ID] != FALSE));
        #endif /* ComM_bWAKEUP_INH_ENABLE */
        #endif /* ComM_bMODE_LIMIT_ENABLE */
        ComM_vidManageLIGHTSM(CHANNEL_ID,
                         #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                         bLimToNoCom,
                         #endif /* ComM_bMODE_LIMIT_ENABLE */
                         ComM_bEvalChUserRequest(CHANNEL_ID),
                         &LOC_u32Cycles,
                         u32MIN_FULL_COUNT(CHANNEL_ID_TEXT),
                         #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                         #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                         bNoWakeUp,
                         #endif /* ComM_bWAKEUP_INH_ENABLE */
                         #endif /* ComM_bMODE_LIMIT_ENABLE */
                         u32NM_LIGHT_TIMEOUT(CHANNEL_ID_TEXT));
        #elif ((u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_NONE)\
                && (bINTERNAL_BUS(CHANNEL_ID_TEXT) != FALSE))
        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
        bLimToNoCom = ((bCHK_LIMNOCOM_GC == 1)
                     &&(ComM_abeLimitToNoComStatus[CHANNEL_ID] != FALSE));
        #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
        bNoWakeUp = ((bCHK_NOWAKEUP_GC == 1) &&
                     (ComM_abeWakeUpInibitStatus[CHANNEL_ID] != FALSE));
        #endif /* ComM_bWAKEUP_INH_ENABLE */
        #endif /* ComM_bMODE_LIMIT_ENABLE */
        ComM_vidManInternalNONESM(CHANNEL_ID,
                             #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                             bLimToNoCom,
                             #endif /* ComM_bMODE_LIMIT_ENABLE */
                             ComM_bEvalChUserRequest(CHANNEL_ID),
                             &LOC_u32Cycles,
                             u32MIN_FULL_COUNT(CHANNEL_ID_TEXT)
                             #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                             #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                             , bNoWakeUp
                             #endif /* ComM_bWAKEUP_INH_ENABLE */
                             #endif /* ComM_bMODE_LIMIT_ENABLE */
                             );
        #else
        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
        bLimToNoCom = ((bCHK_LIMNOCOM_GC == 1)
                     &&(ComM_abeLimitToNoComStatus[CHANNEL_ID] != FALSE));
        #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
        bNoWakeUp = ((bCHK_NOWAKEUP_GC == 1) &&
                    (ComM_abeWakeUpInibitStatus[CHANNEL_ID] != FALSE));
        #endif /* ComM_bWAKEUP_INH_ENABLE */
        #endif /* ComM_bMODE_LIMIT_ENABLE */
        ComM_vidManNotInternalNONESM(CHANNEL_ID,
                                #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                                bLimToNoCom,
                                #endif /* ComM_bMODE_LIMIT_ENABLE */
                                ComM_bEvalChUserRequest(CHANNEL_ID),
                                &LOC_u32Cycles,
                                u32MIN_FULL_COUNT(CHANNEL_ID_TEXT)
                                #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                                #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                                , bNoWakeUp
                                #endif /* ComM_bWAKEUP_INH_ENABLE */
                                #endif /* ComM_bMODE_LIMIT_ENABLE */
                                );
        #endif /* u8NM_VARIANT(CHANNEL_ID_TEXT) */

        /*! if channel's fullComRequestors SenderReceiverInterface is enabled
            for this channel check channel's value in ComM_abChannelReqsUpdated
            */
        #if (bFULL_COM_REQ_SRI(CHANNEL_ID_TEXT) == TRUE)
        if (ComM_abeChannelReqsUpdated[CHANNEL_ID] != FALSE)
        {
            /*! if TRUE call vidCreateFCOMReqStruct() to create the structure */
            ComM_vidCreateFCOMReqStruct(CHANNEL_ID, &udtSRIStruct);
            /*! Call the SRI function to write the structure in the RTE */

            (void)User_Write_CR001_fullComRequestors(&udtSRIStruct);
        }
        #endif /* bFULL_COM_REQ_SRI(CHANNEL_ID_TEXT) */
        #if (ComM_bPNC_SUPPORT == TRUE)
        #if   ((u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_FULL)\
                || (u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_PASSIVE))
        if (ComM_bePncEnabled != FALSE)
        {
            ComM_vidEraEiraHEvaluate(CHANNEL_ID
              );
        }
        #endif  /* u8NM_VARIANT(CHANNEL_ID_TEXT) */
        #endif /* ComM_bPNC_SUPPORT */
    }
}
/* !Deviation: [0841] Violates MISRA Rule 92: "#undef should not be used", this
    rule is minor, and redefinition without #undef results in two QA C errors
    and a compiler warning, so ignoring the rule seems like a better idea.
 */
/* PRQA S 0841 ++*/
#undef CHANNEL_ID
#undef CHANNEL_ID_TEXT


#define CHANNEL_ID 0x02
/* !Deviation: [0841] "Macro defined as an octal constant." this is not an octal
    constant, this is a number to be pasted using token pasting to get channel's
    configurations, it is never used as a number, the Token that is used as
    a number is the previously defined CHANNEL_ID which is defined as a
    hexa-decimal value.
 */
/* PRQA S 0336 ++*/

#define CHANNEL_ID_TEXT 002
/* PRQA S 0336 --*/

/* !Deviation : Inhibit MISRA rule [0850]: Macro expects empty arguments      */
/*              either using AUTOSAR AUTOMATIC definition or by configurable  */
/*              memory classes                                                */
/* PRQA S 0850 ++                                                             */
FUNC(void, COMM_CODE) vidMAIN_FUNC(CHANNEL_ID_TEXT)(void)
/* PRQA S 0850 --                                                             */
{
    /*0x60*/
    #if ((u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_LIGHT)\
       ||(u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_NONE))
    /* !Deviation: [3871] "Identifier with static storage duration declared at
        block scope."
        This is because some main functions need the timer counter and some do
        not, to define a global array of counters we will either have to assign
        a #define for each channel to map it to its value in that array (which
        is quite the overhead on configuration) or we will have to define that
        array with its size as the no. of channels which is a huge waste of
        memory, so a statically defined variable inside each main function that
        require a timer is a better idea.
    */
    /* PRQA S 3223 ++*/
    static uint32            LOC_u32Cycles = 0;
    /* PRQA S 3223 --*/
    #endif /* u8NM_VARIANT(CHANNEL_ID_TEXT) */
    #if (u8NM_VARIANT(CHANNEL_ID_TEXT) != ComM_u8NMVARIANT_PASSIVE)
    #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
    boolean                  bLimToNoCom;
    #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
    boolean                  bNoWakeUp;
    #endif /* ComM_bWAKEUP_INH_ENABLE */
    #endif /* ComM_bMODE_LIMIT_ENABLE */
    #endif /* u8NM_VARIANT(CHANNEL_ID_TEXT) */
    #if (bFULL_COM_REQ_SRI(CHANNEL_ID_TEXT) == TRUE)
    ComM_UserHandleArrayType udtSRIStruct;
    #endif /* bFULL_COM_REQ_SRI(CHANNEL_ID_TEXT) */
    #if ((u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_FULL)\
                ||(u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_PASSIVE))
    #if (ComM_bPNC_SUPPORT == TRUE)
    #if (ComM_bPNC_GW_ENABLED == TRUE)
    #if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
    uint8_least u8Idx;
    #endif /* ComM_u8NO_SIZE_OF_SIG_ARR */
    #endif /* ComM_bPNC_GW_ENABLED */
    #endif /* ComM_bPNC_SUPPORT */
    #endif /* (ComM_u8NMVARIANT_FULL)||(ComM_u8NMVARIANT_PASSIVE) */
    /*! Reject Service if ComM is not initialised */
    if (ComM_udteInitStatus != COMM_UNINIT)
    {
        #if ((u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_FULL)\
                ||(u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_PASSIVE))
        #if (ComM_bPNC_SUPPORT == TRUE)
        #if (ComM_bPNC_GW_ENABLED == TRUE)
        SchM_Enter_ComM_AggEraGwSignal();
        #if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
        for (u8Idx = 0; u8Idx < ComM_u8NO_SIZE_OF_SIG_ARR; u8Idx++)
        {
        #endif /*ComM_u8NO_SIZE_OF_SIG_ARR */
          ComM_au8T_SIG(ComM_au8eTxERAAgg,u8Idx) =
                                         ComM_au8T_SIG(ComM_au8eAggregERASig, u8Idx);
        #if (ComM_u8NO_SIZE_OF_SIG_ARR > 1)
        }
        #endif /*ComM_u8NO_SIZE_OF_SIG_ARR */
        SchM_Exit_ComM_AggEraGwSignal();
        #endif /* ComM_bPNC_GW_ENABLED */
        #endif /* ComM_bPNC_SUPPORT */
        #endif /* (ComM_u8NMVARIANT_FULL)||(ComM_u8NMVARIANT_PASSIVE) */

        /*! Check Channel's configuration and call the appropriate state manager
            with channel's specific arguments */
        #if   (u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_PASSIVE)
        ComM_vidManagePASSIVESM(CHANNEL_ID);
        #elif (u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_FULL)
        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
        bLimToNoCom = ((bCHK_LIMNOCOM_GC == 1)
                     &&(ComM_abeLimitToNoComStatus[CHANNEL_ID] != FALSE));
        #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
        bNoWakeUp = ((bCHK_NOWAKEUP_GC == 1) &&
                    (ComM_abeWakeUpInibitStatus[CHANNEL_ID] != FALSE));
        #endif /* ComM_bWAKEUP_INH_ENABLE */
        #endif /* ComM_bMODE_LIMIT_ENABLE */
        ComM_vidManageFULLSM(CHANNEL_ID,
                        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                        bLimToNoCom,
                        #endif /* ComM_bMODE_LIMIT_ENABLE */
                        ComM_bEvalChUserRequest(CHANNEL_ID)
                        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                        #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                        , bNoWakeUp
                        #endif /* ComM_bWAKEUP_INH_ENABLE */
                        #endif /* ComM_bMODE_LIMIT_ENABLE */
                        );
        #elif (u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_LIGHT)
        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
        bLimToNoCom = ((bCHK_LIMNOCOM_GC == 1)
                     &&(ComM_abeLimitToNoComStatus[CHANNEL_ID] != FALSE));
        #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
        bNoWakeUp = ((bCHK_NOWAKEUP_GC == 1) &&
                    (ComM_abeWakeUpInibitStatus[CHANNEL_ID] != FALSE));
        #endif /* ComM_bWAKEUP_INH_ENABLE */
        #endif /* ComM_bMODE_LIMIT_ENABLE */
        ComM_vidManageLIGHTSM(CHANNEL_ID,
                         #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                         bLimToNoCom,
                         #endif /* ComM_bMODE_LIMIT_ENABLE */
                         ComM_bEvalChUserRequest(CHANNEL_ID),
                         &LOC_u32Cycles,
                         u32MIN_FULL_COUNT(CHANNEL_ID_TEXT),
                         #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                         #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                         bNoWakeUp,
                         #endif /* ComM_bWAKEUP_INH_ENABLE */
                         #endif /* ComM_bMODE_LIMIT_ENABLE */
                         u32NM_LIGHT_TIMEOUT(CHANNEL_ID_TEXT));
        #elif ((u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_NONE)\
                && (bINTERNAL_BUS(CHANNEL_ID_TEXT) != FALSE))
        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
        bLimToNoCom = ((bCHK_LIMNOCOM_GC == 1)
                     &&(ComM_abeLimitToNoComStatus[CHANNEL_ID] != FALSE));
        #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
        bNoWakeUp = ((bCHK_NOWAKEUP_GC == 1) &&
                     (ComM_abeWakeUpInibitStatus[CHANNEL_ID] != FALSE));
        #endif /* ComM_bWAKEUP_INH_ENABLE */
        #endif /* ComM_bMODE_LIMIT_ENABLE */
        ComM_vidManInternalNONESM(CHANNEL_ID,
                             #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                             bLimToNoCom,
                             #endif /* ComM_bMODE_LIMIT_ENABLE */
                             ComM_bEvalChUserRequest(CHANNEL_ID),
                             &LOC_u32Cycles,
                             u32MIN_FULL_COUNT(CHANNEL_ID_TEXT)
                             #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                             #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                             , bNoWakeUp
                             #endif /* ComM_bWAKEUP_INH_ENABLE */
                             #endif /* ComM_bMODE_LIMIT_ENABLE */
                             );
        #else
        #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
        bLimToNoCom = ((bCHK_LIMNOCOM_GC == 1)
                     &&(ComM_abeLimitToNoComStatus[CHANNEL_ID] != FALSE));
        #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
        bNoWakeUp = ((bCHK_NOWAKEUP_GC == 1) &&
                    (ComM_abeWakeUpInibitStatus[CHANNEL_ID] != FALSE));
        #endif /* ComM_bWAKEUP_INH_ENABLE */
        #endif /* ComM_bMODE_LIMIT_ENABLE */
        ComM_vidManNotInternalNONESM(CHANNEL_ID,
                                #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                                bLimToNoCom,
                                #endif /* ComM_bMODE_LIMIT_ENABLE */
                                ComM_bEvalChUserRequest(CHANNEL_ID),
                                &LOC_u32Cycles,
                                u32MIN_FULL_COUNT(CHANNEL_ID_TEXT)
                                #if (ComM_bMODE_LIMIT_ENABLE == TRUE)
                                #if (ComM_bWAKEUP_INH_ENABLE == TRUE)
                                , bNoWakeUp
                                #endif /* ComM_bWAKEUP_INH_ENABLE */
                                #endif /* ComM_bMODE_LIMIT_ENABLE */
                                );
        #endif /* u8NM_VARIANT(CHANNEL_ID_TEXT) */

        /*! if channel's fullComRequestors SenderReceiverInterface is enabled
            for this channel check channel's value in ComM_abChannelReqsUpdated
            */
        #if (bFULL_COM_REQ_SRI(CHANNEL_ID_TEXT) == TRUE)
        if (ComM_abeChannelReqsUpdated[CHANNEL_ID] != FALSE)
        {
            /*! if TRUE call vidCreateFCOMReqStruct() to create the structure */
            ComM_vidCreateFCOMReqStruct(CHANNEL_ID, &udtSRIStruct);
            /*! Call the SRI function to write the structure in the RTE */

            (void)User_Write_CR002_fullComRequestors(&udtSRIStruct);
        }
        #endif /* bFULL_COM_REQ_SRI(CHANNEL_ID_TEXT) */
        #if (ComM_bPNC_SUPPORT == TRUE)
        #if   ((u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_FULL)\
                || (u8NM_VARIANT(CHANNEL_ID_TEXT) == ComM_u8NMVARIANT_PASSIVE))
        if (ComM_bePncEnabled != FALSE)
        {
            ComM_vidEraEiraHEvaluate(CHANNEL_ID
              );
        }
        #endif  /* u8NM_VARIANT(CHANNEL_ID_TEXT) */
        #endif /* ComM_bPNC_SUPPORT */
    }
}
/* !Deviation: [0841] Violates MISRA Rule 92: "#undef should not be used", this
    rule is minor, and redefinition without #undef results in two QA C errors
    and a compiler warning, so ignoring the rule seems like a better idea.
 */
/* PRQA S 0841 ++*/
#undef CHANNEL_ID
#undef CHANNEL_ID_TEXT




#define COMM_STOP_SEC_CODE
/* PRQA S 0838, 5087 L1 */
#include "MemMap.h"
/* PRQA L:L1 */


