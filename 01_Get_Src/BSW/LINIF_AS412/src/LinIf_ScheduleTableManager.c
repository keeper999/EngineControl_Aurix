/******************************************************************************/
/*                                                                            */
/*!Layer           : HAL                                                     */
/*                                                                            */
/*!Component       : LinIf                                                   */
/*!Description     : The Lin Interface AutoSAR component                     */
/*                                                                            */
/*!Module          : STM                                                     */
/*!Description     : The Schedule Table Manager handles schedule tables and  */
/*                    entries and instruct the Main and Tp to send frame      */
/*                    according to schedule tables                            */
/*                                                                            */
/*!\File             LinIf_ScheduleTableManager.c                            */
/* \par              The Schedule Table Manager handles schedule tables and  */
/*                    entries and instruct the Main and Tp to send frame      */
/*                    according to schedule tables                            */
/*!Scope           : Private                                                 */
/*                                                                            */
/*!Target          : All                                                     */
/*                                                                            */
/*!Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2011 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/*!Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/20_LinIf/0$*/
/* $Revision::   1.27     $$Author::   MTAYMOUR       $$Date::   Feb 19 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/

/*!Deviation : Inhibit MISRA rule [0838]: Multiple Inclusion prevention       */
/*              macros solve this issue                                       */
/* PRQA S 0838 L1                                                             */
/*!Deviation : Inhibit MISRA rule [2215]: Indentation problem is caused by    */
/*              Compiler abstraction macros                                   */
/* PRQA S 2215 L1                                                             */
/*!Deviation : Inhibit MISRA rule [0862]: The MemMap.h is used to assign      */
/*              memory segments                                               */
/* PRQA S 0862 L1                                                             */
/*!Deviation : Inhibit MISRA rule [0850]: The value for the macros are        */
/*              redefined in the QAC for comptability with ANSI C             */
/* PRQA S 0850 L1                                                             */
/*!Deviation : Inhibit MISRA rule [0857]: Most of the macros are defined in   */
/*              Compiler_Cfg file                                             */
/* PRQA S 0857 L1                                                             */
/*!Deviation : Inhibit MISRA rule [5087]: The value for the macros are        */
/*              non preprocessor directives  					   		      */
/* PRQA S 5087 L1                                                             */
#include "LinIf.h"
#include "LinIf_Cfg.h"
#include "LinIf_Lcfg.h"
#include "LinIf_Types.h"
#include "LinIf_Types_Internal.h"
#include "LinIf_ScheduleTableManager.h"
#include "LinIf_Main.h"
#include "LinIf_LinTransportProtocol.h"

#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
#include "LinIf_DetErrors.h"

#endif
/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/

#define LINIF_START_SEC_CONST_UNSPECIFIED
#include "Memmap.h"

/*!\Description : The NULL_SCHEDULE                                          */
static CONST(LinIf_tstrScheduleTable, LINIF_CONST) kstrNULLSchedule = 
{
    (LinIf_SchHandleType)0,
    LinIf_RUN_CONTINUOUS,
    LinIf_START_FROM_BEGINNING,
    0,
    0
};

#define LINIF_STOP_SEC_CONST_UNSPECIFIED
#include "Memmap.h"
/*!Deviation : Inhibit MISRA rule [2215]: the macro is used for memory       */
/*              mapping                                                       */
/* PRQA S 3614 ++                                                             */
#define LINIF_START_SEC_CODE
/* PRQA S 3614 --                                                             */
#include "Memmap.h"
/******************************************************************************/
/* LOCAL FUNCTION Declaration                                                 */
/******************************************************************************/
/******************************************************************************/
/* Description : Changes a channel schedule table                             */
/******************************************************************************/
static FUNC(void, LINIF_CODE) vidChngChannelSchedule(
   VAR(uint8, AUTOMATIC) u8ChannelIndex,
   P2CONST(LinIf_tstrScheduleTable, AUTOMATIC, LINIF_CALIB_CONST) pkstrST,
   VAR(boolean, AUTOMATIC) bRevertBack);

/******************************************************************************/
/* Description : Handles a schedule request                                   */
/******************************************************************************/
static FUNC(void, LINIF_CODE) vidHandleSchTabChng(
    VAR(uint8, AUTOMATIC) u8ChannelIndex);

/******************************************************************************/
/* Description : Sends an Unconditional Frame                                 */
/******************************************************************************/
static FUNC(void, LINIF_CODE) vidSendUncondFrame(
   VAR(uint8, AUTOMATIC) u8ChannelIndex,
   P2CONST(LinIf_tstrFrame, AUTOMATIC, LINIF_CALIB_CONST) pkstrFrameToSend);

/******************************************************************************/
/* Description : Sends a Lin Frame header (for Rx and SlaveToSlave frames    */
/******************************************************************************/
static FUNC(void, LINIF_CODE) vidSendFrameHeader(
   VAR(uint8, AUTOMATIC) u8ChannelIndex,
   P2CONST(LinIf_tstrFrame, AUTOMATIC, LINIF_CALIB_CONST) pkstrFrameToSend);

/******************************************************************************/
/* Description : Handles a sporadic slot's frames                            */
/******************************************************************************/
static FUNC(void, LINIF_CODE) vidHandleSporadicSlot(
   VAR(uint8, AUTOMATIC) u8ChannelIndex,
   P2CONST(LinIf_tstrFrame, AUTOMATIC, LINIF_CALIB_CONST) pkstrFrameToSend);

/******************************************************************************/
/* Description : Gets the collision resolving schedule table of the current 
                 Event triggered frame on the input channel                   */
/******************************************************************************/
static FUNC(const LinIf_tstrScheduleTable *, LINIF_CODE) pkstrGetColResSchTab(
    VAR(uint8, AUTOMATIC) u8ChannelIndex);

/******************************************************************************/
/* Description : Gets PduId of RxFrame from its Pid, this is used in the case */
/******************************************************************************/
static FUNC(Std_ReturnType, LINIF_CODE) udtGetRxPduRefFromPid(
   VAR(uint8, AUTOMATIC) u8ChannelIndex,
   VAR(uint8, AUTOMATIC) u8InputPid,
   P2VAR(P2CONST(LinIf_tstrFrame, AUTOMATIC, LINIF_CALIB_CONST), AUTOMATIC, AUTOMATIC) pudtFrame);

/******************************************************************************/
/* Description : Handles a collision by switching to its collision resolving  */
/*               schedule table                                               */
/******************************************************************************/
static FUNC(void, LINIF_CODE) vidHandleColResolving(
   VAR(uint8, AUTOMATIC) u8ChannelIndex);


/******************************************************************************/
/* Description : Performs actions needed when a new schedule entry is due     */
/******************************************************************************/
static FUNC(void, LINIF_CODE) vidHandleNewEntry(
   VAR(uint8, AUTOMATIC) u8ChannelIndex);

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/
/******************************************************************************/
/*!Function    : vidChngChannelSchedule                                    */
/* \Description : Changes a channel schedule table                            
   \param[in] Index of the channel in the channels array \n
        \Range  0..LinIf_ku8eNumberOfChannels \n
   \param[in] pointer to the new schedule table \n
        \Range  NOT NULL \n
   \param[in] switch to indicate if this is a schedule change or a revert back 
                from a schedule change \n
        \Range  NOT NULL \n     */
/******************************************************************************/
static FUNC(void, LINIF_CODE) vidChngChannelSchedule(
   VAR(uint8, AUTOMATIC) u8ChannelIndex,
   P2CONST(LinIf_tstrScheduleTable, AUTOMATIC, LINIF_CALIB_CONST) pkstrST,
   VAR(boolean, AUTOMATIC) bRevertBack)
{
    P2CONST(LinIf_tstrScheduleTable, AUTOMATIC, LINIF_CALIB_CONST) pkstrCurrST;
	P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR)  pstrCurrChannelVars;
    pkstrCurrST = 
        LinIf_astreChannelsVars[u8ChannelIndex].pkstrCurrScheduleTab;
	pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);

    /*! If the request schedule table is NULL_SCHEDULE, change the schedule 
        directly without any further processing */
    if(pkstrST->kudtIndex == 0)
    {
        pstrCurrChannelVars->u16IntSchEntryIndex = 0;
        pstrCurrChannelVars->u16NextEntryIndex = 0;
        pstrCurrChannelVars->pkstrCurrScheduleTab = &kstrNULLSchedule;
    }
    /*! else If the pkstrCurrScheduleTab is of Mode LinIf_RUN_CONTINUOUS */
    else if(pkstrCurrST->enuRunMode == LinIf_RUN_CONTINUOUS)
    {
        /*! Save the pkstrCurrScheduleTab in pkstrPrevScheduleTab */
        pstrCurrChannelVars->pkstrPrevScheduleTab = 
            pstrCurrChannelVars->pkstrCurrScheduleTab;

        /*! If the new schedule is of Mode LinIf_RUN_ONCE */    
        /*\Trace_To: LinIf-CDD-0063(0) */
        if(pkstrST->enuRunMode == LinIf_RUN_ONCE)
        {
            /*!If the pkstrCurrScheduleTab's resume position is 
                LinIf_START_FROM_BEGINNING */
            if(pkstrCurrST->enuResumePosition == LinIf_START_FROM_BEGINNING)
            {
                /*!Set u16IntSchEntryIndex to the start of the current 
                    schedule table starting index */
                pstrCurrChannelVars->u16IntSchEntryIndex = 
                    pstrCurrChannelVars->pkstrCurrScheduleTab->u16StartEntryIndex;
            }
            /*! Else (LinIf_CONTINUE_AT_IT_POINT) */
            else
            {
                /*! Set u16IntSchEntryIndex to u16NextEntryIndex */
                pstrCurrChannelVars->u16IntSchEntryIndex = 
                pstrCurrChannelVars->u16NextEntryIndex;
            }
            /*!Endif */ 
        }
        /*!Endif */ 
    }
    else
    {
        /* Do nothing just for MISRA */
    }
    /*!Endif */ 

    /*! Set pkstrCurrScheduleTab to the input schedule table */
    pstrCurrChannelVars->pkstrCurrScheduleTab = pkstrST;
    /*! if the bRevertBack = true, set u16NextEntryIndex to u16IntSchEntryIndex
         (the interrupted index )else set it to u16StartEntryIndex */
    if(FALSE == bRevertBack)
    {

        pstrCurrChannelVars->u16NextEntryIndex = 
                          pkstrST->u16StartEntryIndex;
    }
    /*\Trace_To: LinIf-CDD-0063(0) */
    else
    {
        pstrCurrChannelVars->u16NextEntryIndex =
        pstrCurrChannelVars->u16IntSchEntryIndex;
    }
}
/******************************************************************************/
/*!Function    : vidHandleSchTabChng                                         */
/* \Description Handles a schedule request \n                            
   \param[in] Index of the channel in the channels array \n
        \Range  0..LinIf_ku8eNumberOfChannels \n                              */
/*\Trace_To    : LinIf-CDD-0061(0)                                           */
/******************************************************************************/
static FUNC(void, LINIF_CODE) vidHandleSchTabChng(
   VAR(uint8, AUTOMATIC) u8ChannelIndex)
{
    P2CONST(LinIf_tstrScheduleTable, AUTOMATIC, LINIF_CALIB_CONST) 
                                                                pkstrBufSchTab;
	P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR)  pstrCurrChannelVars;
	P2CONST(LinIf_tstrChannelCriticalSec, AUTOMATIC, LINIF_VAR)
													    pkstrCurrChnlCritsection;
    pstrCurrChannelVars =  &(LinIf_astreChannelsVars[u8ChannelIndex]);
	pkstrCurrChnlCritsection = &(LinIf_akstreChannelsCritSec[u8ChannelIndex]);
    /*!Enter critical section 001 */
    pkstrCurrChnlCritsection->pfvidEnterSecSchTab000();

    pkstrBufSchTab = pstrCurrChannelVars->pkstrBufferedSchTab;

    /*!if pkstrBufferedSchTab (buffered schedule request) is not NULL 
        (i.e. there is a request */
    if(pkstrBufSchTab 
       != 
       (P2CONST(LinIf_tstrScheduleTable, AUTOMATIC, LINIF_CALIB_CONST))NULL_PTR)
    {
        /*\Trace_To: LinIf-CDD-0056(0) */
        /*!if the requested schedule is the NULL_SCH or the current is of mode
            RUN_CONT */
        /* The NULL_SCHEDULE is treated in the same way as if the 
           currently running schedule is RUN_CONT even if it is LinIf_RUN_ONCE*/
        /*\Trace_To: LinIf-CDD-0058(0) */
        if( (pkstrBufSchTab->kudtIndex == 0)  /* NULL_SCHEDULE*/
            ||
            (pstrCurrChannelVars->pkstrCurrScheduleTab->
					enuRunMode == LinIf_RUN_CONTINUOUS) /* RUN_CONT */
          )
        {
            /*!Call vidChngChannelSchedule with the new schedule and 
                revert = false */
            vidChngChannelSchedule(u8ChannelIndex, pkstrBufSchTab, FALSE);
            /*! remove the new schedule from the buffer */
            pstrCurrChannelVars->pkstrBufferedSchTab = NULL_PTR;
			
			 /*!Exit critical section 001 */
			pkstrCurrChnlCritsection->pfvidExitSecSchTab000();

            /*!CALL schedule request confirmation */
            /*\Trace_To: LinIf-CDD-0060(0) */
            /*\Trace_To: LinIf-CDD-0280(0) */
            LinIf_pkstreGlobalConfig->
                pkstrChannels[u8ChannelIndex].pfvidSchReqConfrm(
                LinIf_udtGetChannelIdByIndex(u8ChannelIndex),
                pkstrBufSchTab->kudtIndex);
            
        }
        /*!Else (the current schedule is a LinIf_RUN_ONCE schedule) */
        /*\Trace_To: LinIf-CDD-0059(0) */
        else /* LinIf_RUN_ONCE */
        {
            /*!If the u16NextEntryIndex > the end of the current schedule 
                table entries */
            if(
                (pstrCurrChannelVars->u16NextEntryIndex) >=

                (pstrCurrChannelVars->pkstrCurrScheduleTab->
                u16StartEntryIndex 
                + 
                pstrCurrChannelVars->pkstrCurrScheduleTab->
                u16NumberOfEntries)
              )
            {
                /*!Call vidChngChannelSchedule with the new schedule and 
                    revert = false */
                vidChngChannelSchedule(u8ChannelIndex, pkstrBufSchTab, FALSE);

                /*! remove the new schedule from the buffer */
                pstrCurrChannelVars->pkstrBufferedSchTab = NULL_PTR;
				
				 /*!Exit critical section 001 */
				pkstrCurrChnlCritsection->pfvidExitSecSchTab000();

                /*!CALL schedule request confirmation */
                LinIf_pkstreGlobalConfig->pkstrChannels[u8ChannelIndex].
                    pfvidSchReqConfrm(
                    LinIf_udtGetChannelIdByIndex(u8ChannelIndex),
                    pkstrBufSchTab->kudtIndex);

            }
			else
			{	
				 /*!Exit critical section 001 */
				pkstrCurrChnlCritsection->pfvidExitSecSchTab000();
			}
        }
    }
	else
	{
		 /*!Exit critical section 001 */
        pkstrCurrChnlCritsection->pfvidExitSecSchTab000();
	}
}

/******************************************************************************/
/*!Function    : vidSendUncondFrame                                          */
/* \Description Sends an unconditional frame \n                            
   \param[in] Index of the channel in the channels array \n
        \Range  0..LinIf_ku8eNumberOfChannels \n
   \param[in] Pointer to the frame to be sent \n
        \Range  NOT NULL \n                                                   */
/******************************************************************************/
static FUNC(void, LINIF_CODE) vidSendUncondFrame(
   VAR(uint8, AUTOMATIC) u8ChannelIndex,
   P2CONST(LinIf_tstrFrame, AUTOMATIC, LINIF_CALIB_CONST) pkstrFrameToSend)
{
    VAR(Std_ReturnType, AUTOMATIC)  udtTemp;
    VAR(PduInfoType, AUTOMATIC)     strInfo;
	P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR) pstrCurrChannelVars;
    /*! Set pkstrCurrentFrame in the current channel to the input frame */
    /*! Call TriggerTransmit function that is pointed to by the input frame 
         with DataPtr in the PduInfo struct points au8DataBuffer of the 
         current channel*/
	pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);
    strInfo.SduDataPtr = 
                    &(pstrCurrChannelVars->au8DataBuffer[0]);

    pstrCurrChannelVars->pkstrCurrentFrame = pkstrFrameToSend;
    /*\Trace_To: LinIf-CDD-0042(0) */
    /*\Trace_To: LinIf-CDD-0296(0) */
    udtTemp = pkstrFrameToSend->pkstrTxParams->pfudtTxTriggerTransmit(
        pkstrFrameToSend->pkstrTxParams->udtLinIfTxPduRef,&strInfo);

#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
    /*!If the copied data length is not as the configured in the frame 
        report LinIf_u8E_INV_PDU_LEN to DET if DevErrorDetect is ON*/
    if( strInfo.SduLength 
        != 
        pstrCurrChannelVars->pkstrCurrentFrame->u8Length)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
            LINIF_INSTANCE_ID, 
            LinIf_u8LINIF_MAINFN_SRV_ID,
            LinIf_u8E_INV_PDU_LEN);
    }
    else
    {
#endif
        /*!If the call returns E_OK call LinIf_vidIFSendFrame with the output 
            length from TriggerTransmit*/
        if(E_OK == udtTemp)
        {
            LinIf_vidIFSendFrame(u8ChannelIndex, (uint8)(strInfo.SduLength));
        }
        /*\Trace_To: LinIf-CDD-5152(0) */
        /*!Else if the frame is sporadic clear the sporadic flag */
        else
        {
            if(FALSE != pkstrFrameToSend->bIsSporadic)
            {
				(*pkstrFrameToSend->pbSporadic) = FALSE;
            }
        }
        /*!EndIf */
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
    }
#endif
}

/******************************************************************************/
/*!Function    : vidSendFrameHeader                                          */
/* \Description Sends a frame header (for Rx and Slave to Slave frames) \n
   \param[in] Index of the channel in the channels array \n
        \Range  0..LinIf_ku8eNumberOfChannels \n
   \param[in] Pointer to the frame to be sent \n
        \Range  NOT NULL \n                                                   */
/******************************************************************************/
static FUNC(void, LINIF_CODE) vidSendFrameHeader(
   VAR(uint8, AUTOMATIC) u8ChannelIndex,
   P2CONST(LinIf_tstrFrame, AUTOMATIC, LINIF_CALIB_CONST) pkstrFrameToSend)
{
    /*! Set pkstrCurrentFrame in the current channel to the input frame */
    LinIf_astreChannelsVars[u8ChannelIndex].pkstrCurrentFrame = 
        pkstrFrameToSend;
    /*!Call LinIf_vidIFSendFrame with the length stored in the input frame */
    LinIf_vidIFSendFrame(u8ChannelIndex, pkstrFrameToSend->u8Length);
}


/******************************************************************************/
/*!Function    : udtGetRxPduRefFromPid                                       */
/* \Description Gets PduId of RxFrame from its Pid, this is used in the case 
                of 1 response for an event triggered frame \n
   \param[in] Index of the channel in the channels array \n
        \Range  0..LinIf_ku8eNumberOfChannels \n
   \param[in] The Pid to search for \n
        \Range  0..59 \n 
   \param[out] The Found PduIdRef \n
   \param[out] The length of the Found Pdu \n
   \return
        E_OK    : The Pid is found inside the collision resolver table of 
                  the current Event triggered frame
        E_NOT_OK: The Pid is not found inside the collision resolver table of 
                  the current Event triggered frame*/
/******************************************************************************/
static FUNC(Std_ReturnType, LINIF_CODE) udtGetRxPduRefFromPid(
   VAR(uint8, AUTOMATIC) u8ChannelIndex,
   VAR(uint8, AUTOMATIC) u8InputPid,
   P2VAR(P2CONST(LinIf_tstrFrame, AUTOMATIC, LINIF_CALIB_CONST), AUTOMATIC, AUTOMATIC) pudtFrame)
{
    P2CONST(LinIf_tstrScheduleTable, AUTOMATIC, LINIF_CALIB_CONST)  
                                                            pkstrColResSchTab;
    VAR(uint16, AUTOMATIC)                                  u16StartEntry;
    VAR(uint16_least, AUTOMATIC)                                  u16LoopIndex;
    VAR(uint16, AUTOMATIC)                                  u16TempFrameIndex;
    VAR(Std_ReturnType, AUTOMATIC)                          udtRet;
    VAR(boolean, AUTOMATIC)                                 bFrameFound;

    /*! Call pkstrGetColResSchTab to get pointer to the current Col resolver*/
    pkstrColResSchTab = pkstrGetColResSchTab(u8ChannelIndex);
    u16StartEntry = pkstrColResSchTab->u16StartEntryIndex;
    

    /*! Loop on the frames in the collision resolver if a frame matchs the Pid
         Set pudtRetPduId to its udtLinIfRxPduRef */
    bFrameFound = FALSE;
    for(u16LoopIndex = u16StartEntry;
        (u16LoopIndex < (u16StartEntry + pkstrColResSchTab->u16NumberOfEntries))
        &&
        (FALSE == bFrameFound);
        u16LoopIndex++)
    {
        u16TempFrameIndex =
            LinIf_pkstreGlobalConfig->pkstrScheduleEntries[u16LoopIndex].
            u16FrameIndex;

        if( LinIf_pkstreGlobalConfig->pkstrFrames[u16TempFrameIndex].u8Pid
            == 
            u8InputPid)
        {
			*pudtFrame = &LinIf_pkstreGlobalConfig->pkstrFrames[u16TempFrameIndex];
            
            bFrameFound = TRUE;
        }
    }

    /*!If a frame is found return E_OK, else return E_NOT_OK */
    if(FALSE == bFrameFound)
    {
        udtRet = E_NOT_OK;
    }
    else
    {
        udtRet = E_OK;
    }

    return udtRet;
}
/******************************************************************************/
/*!Function    : pkstrGetColResSchTab                                        */
/* \Description Gets pointer to the current Collision resolver for the current
                Event triggered frame\n                            
   \param[in] Index of the channel in the channels array \n
        \Range  0..LinIf_ku8eNumberOfChannels \n
   \return Pointer to the Collision resolver                                  */
/******************************************************************************/
static FUNC(const LinIf_tstrScheduleTable *, LINIF_CODE) pkstrGetColResSchTab(
    VAR(uint8, AUTOMATIC) u8ChannelIndex)
{
    P2CONST(LinIf_tstrScheduleTable, AUTOMATIC, LINIF_CALIB_CONST)  
                                                        pkstrColResSchTab;
    VAR(uint16, AUTOMATIC)                              u16CurrentEntryIndex;
	P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR) pstrCurrChannelVars;
    
	pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);
    /*!The col resolver is bound to the event triggered frame entry which 
        is the previous entry for sure */
    /*!If the current entry is the first entry in the current schedule table, 
        then the previous entry must be the last entry in the table */
    if(pstrCurrChannelVars->u16NextEntryIndex == 
        pstrCurrChannelVars->pkstrCurrScheduleTab->u16StartEntryIndex)
    {
        u16CurrentEntryIndex = 
            pstrCurrChannelVars->pkstrCurrScheduleTab->u16StartEntryIndex
            + 
            (pstrCurrChannelVars->pkstrCurrScheduleTab->u16NumberOfEntries - 1);

    }
    /*! Else the Event triggered entry is the current Entry-1 */
    else
    {
        u16CurrentEntryIndex = 
            pstrCurrChannelVars->u16NextEntryIndex - 1;
    }
    /*!EndIf */
    /*!return a pointer to the collision resolver bound to the event truggered
        entry */
    /*\Trace_To: LinIf-CDD-0022(0) */
    pkstrColResSchTab =
        &(LinIf_pkstreGlobalConfig->
        pkstrScheduleTables[LinIf_pkstreGlobalConfig->
        pkstrScheduleEntries[u16CurrentEntryIndex].u16ColResolvTabIndex]);

    return pkstrColResSchTab;
}

/******************************************************************************/
/*!Function    : vidHandleColResolving                                       */
/* \Description Handles a collision by switching to its collision resolver
                schedule table\n                            
   \param[in] Index of the channel in the channels array \n
        \Range  0..LinIf_ku8eNumberOfChannels \n                              */
/******************************************************************************/
static FUNC(void, LINIF_CODE) vidHandleColResolving(
   VAR(uint8, AUTOMATIC) u8ChannelIndex)
{
    P2CONST(LinIf_tstrScheduleTable, AUTOMATIC, LINIF_CALIB_CONST) 
        pkstrColResSchTab;
	P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR) pstrCurrChannelVars;
	
	pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);
    /*! Call pkstrGetColResSchTab to get pointer to the current Col resolver*/
    pkstrColResSchTab = pkstrGetColResSchTab(u8ChannelIndex);

    /*! Store pkstrCurrScheduleTab into pkstrPrevScheduleTab */
    pstrCurrChannelVars->pkstrPrevScheduleTab = 
        pstrCurrChannelVars->pkstrCurrScheduleTab;

    /*! Store u16NextEntryIndex into u16IntSchEntryIndex */
    pstrCurrChannelVars->u16IntSchEntryIndex = 
        pstrCurrChannelVars->u16NextEntryIndex;

    /*! Set pkstrCurrScheduleTab to the current Col resolver */
    pstrCurrChannelVars->pkstrCurrScheduleTab =
        pkstrColResSchTab;

    /*! Set u16NextEntryIndex to u16StartEntryIndex of the collision resolver*/
    pstrCurrChannelVars->u16NextEntryIndex = 
        pkstrColResSchTab->u16StartEntryIndex;
}

/******************************************************************************/
/*!Function    : vidHandleNewEntry                                           */
/* \Description Performs actions needed when a new schedule entry is due \n   
   \param[in] Index of the channel in the channels array \n
        \Range  0..LinIf_ku8eNumberOfChannels \n                              */
/******************************************************************************/
static FUNC(void, LINIF_CODE) vidHandleNewEntry(
   VAR(uint8, AUTOMATIC) u8ChannelIndex)
{

	P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR) pstrCurrChannelVars;
	
	pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);
    /*!Call LinIf_vidIFNewSchEntryCallout to enable The Main Sub-Component to
        handle new entry */
    LinIf_vidIFNewSchEntryCallout(u8ChannelIndex);

    /*!If there is an event triggered frame collision */
    /*\Trace_To: LinIf-CDD-0021(0) */
    if(FALSE != pstrCurrChannelVars->bIsEventTrigCol)
    {
        /*!Call vidHandleSchTabChng to handle event triggered frame 
            collision */
        vidHandleColResolving(u8ChannelIndex);
        pstrCurrChannelVars->bIsEventTrigCol = FALSE;
    }

    /*! Call vidHandleSchTabChng to handle schedule changes */
    vidHandleSchTabChng(u8ChannelIndex);
}

/******************************************************************************/
/*!Function    : vidHandleSporadicSlot                                       */
/*  \Description Handles a sporadic slot's frames \n   
    \param[in] Index of the channel in the channels array \n
        \Range  0..LinIf_ku8eNumberOfChannels \n
    \param[in] Pointer to the frame representing the sporadic slot \n
        \Range  0..LinIf_ku8eNumberOfChannels \n                              */
/******************************************************************************/
static FUNC(void, LINIF_CODE) vidHandleSporadicSlot(
   VAR(uint8, AUTOMATIC) u8ChannelIndex,
   P2CONST(LinIf_tstrFrame, AUTOMATIC, LINIF_CALIB_CONST) pkstrFrameToSend)
{
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
    if(pkstrFrameToSend->u8NumberOfSubFrames != 0)
    {
#endif
        VAR(uint16_least, AUTOMATIC)  u16LoopIndex;
        VAR(uint16, AUTOMATIC)  u16StartOfNextContainer;
        VAR(boolean, AUTOMATIC) bFrameFound;

        u16StartOfNextContainer = 
            pkstrFrameToSend->u8NumberOfSubFrames
            +
            pkstrFrameToSend->u16SubFramesIndex;


        /*!LOOP on the substitution frames attached to the input frame from 
            lower index to higher index */
        bFrameFound = FALSE;
        /*\Trace_To: LinIf-CDD-0026(0) */
        /*\Trace_To: LinIf-CDD-0027(0) */
        /* the sporadic frames are ordered by priority from highest to lowest */
        for(u16LoopIndex = pkstrFrameToSend->u16SubFramesIndex; 
            (u16LoopIndex < u16StartOfNextContainer)
            &&
            (FALSE == bFrameFound);
            u16LoopIndex++)
        {
            
            /*!if the substitution frame's request flag 
                (pbSporadicFramesFlags[Frame.u16SporadicIndex]) is true */
			if( *(LinIf_pkstreGlobalConfig->
					pkstrSubstFrames[u16LoopIndex].pkstrFrame->pbSporadic) != FALSE)
            {
                /*!Call vidSendUncondFrame with input equal to the 
                    substitution frame */
                /*\Trace_To: LinIf-CDD-0026(0) */
                vidSendUncondFrame(
                    u8ChannelIndex, LinIf_pkstreGlobalConfig->pkstrSubstFrames
									[u16LoopIndex].pkstrFrame);

                bFrameFound = TRUE;
            }
            /*!Endif */
        }

#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
    }
    else
    {
        /*TODO: handle error*/
    }
#endif
       
}
/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
/******************************************************************************/
/*!Function    : LinIf_vidSTMHandlEvtTrigErr                                 */
/*  \Description Called when an event triggered collision is detected  \n   
    \param[in] Index of the channel in the channels array \n
        \Range  0..LinIf_ku8eNumberOfChannels \n                              */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_vidSTMHandlEvtTrigErr(
   VAR(uint8, AUTOMATIC) u8ChannelIndex)
{
    /*!Set bIsEventTrigCol of current channel to TRUE */
    LinIf_astreChannelsVars[u8ChannelIndex].bIsEventTrigCol = TRUE;
}
/******************************************************************************/
/*!Function    : LinIf_vidSTMInit                                            */
/*  \Description Initializes the STM module  \n   
    \param[in] Index of the channel in the channels array \n
        \Range  0..LinIf_ku8eNumberOfChannels \n                              */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_vidSTMInit(
   VAR(uint8, AUTOMATIC) u8ChannelIndex)
{
    P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR) pstrCurrChannelVars;
	/*\Trace_To: LinIf-CDD-0173(0) */
    /*!Set pkstrCurrScheduleTab of current channel to NULL_SCH */
	pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);
    pstrCurrChannelVars->pkstrCurrScheduleTab = 
                                            &kstrNULLSchedule;

    /*!Set pkstrPrevScheduleTab of current channel to NULL */
    pstrCurrChannelVars->pkstrPrevScheduleTab = NULL_PTR;

    /*!Set u8TimeToNextEntry, u16NextEntryIndex, u16IntSchEntryIndex 
        of current channel to 0 */
    pstrCurrChannelVars->u8TimeToNextEntry = 0;
    pstrCurrChannelVars->u16NextEntryIndex = 0;
    pstrCurrChannelVars->u16IntSchEntryIndex = 0;

    /*!Set pkstrBufferedSchTab of current channel to NULL */
    pstrCurrChannelVars->pkstrBufferedSchTab = NULL_PTR;

    /*!Set bIsNConfOngoing, bIsEventTrigCol of current channel to FALSE */
    pstrCurrChannelVars->bIsNConfOngoing = FALSE;
    pstrCurrChannelVars->bIsEventTrigCol = FALSE;
}

/******************************************************************************/
/*!Function    : LinIf_vidSTMTxConf                                          */
/*  \Description Callback from to indicate that a frame is sent successfully 
                 on the channel  \n   
    \param[in] Index of the channel in the channels array \n
        \Range  0..LinIf_ku8eNumberOfChannels \n                              */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_vidSTMTxConf(
   VAR(uint8, AUTOMATIC) u8ChannelIndex)
{
	P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR) pstrCurrChannelVars;
	
	pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);
    /*! Call TxConfirmation with the PduRef of the current frame*/
    /*\Trace_To: LinIf-CDD-0044(0) */
    /*\Trace_To: LinIf-CDD-0298(0) */
    pstrCurrChannelVars->pkstrCurrentFrame->pkstrTxParams->pfvidTxConfirmationUL
        (LinIf_astreChannelsVars[u8ChannelIndex].pkstrCurrentFrame->
        pkstrTxParams->udtLinIfTxPduRef);
    
    /*!Note if a frame is attached to a sporadic slot, then it cannot be
       existent in the same schedule table as an unconditional frame, so if 
       the confirmed frame has the properity IsSporadic = true, then it must 
       have been sent in a sporadic slot so we must clear the flag anyways. */
    /*!Clear the sporadic flag of the current frame if the frame has 
        bIsSporadic = TRUE */
    /*\Trace_To: LinIf-CDD-0047(0) */
    if( FALSE 
        !=
        pstrCurrChannelVars->pkstrCurrentFrame->bIsSporadic)
    {	
			*(pstrCurrChannelVars->pkstrCurrentFrame->
				pbSporadic) = FALSE;
    }
}

/******************************************************************************/
/*!Function    : LinIf_vidSTMRxInd                                           */
/*  \Description Callback from to indicate that a frame is received successfully
                 on the channel  \n   
    \param[in] Index of the channel in the channels array \n
        \Range  0..LinIf_ku8eNumberOfChannels \n                              */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_vidSTMRxInd(
   VAR(uint8, AUTOMATIC) u8ChannelIndex)
{
    P2CONST(LinIf_tstrFrame, AUTOMATIC, LINIF_CALIB_CONST)  pkstrLocFrame;
        
    VAR(PduInfoType, AUTOMATIC)                             strPduInfo;
    VAR(PduIdType, AUTOMATIC)                               udtRxRef;
    VAR(Std_ReturnType, AUTOMATIC)                          udtGetPidRet;
	P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR) pstrCurrChannelVars;
	pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);
    pkstrLocFrame = pstrCurrChannelVars->pkstrCurrentFrame;
    /*!If the received frame is an event triggered frame, call 
        udtGetRxPduRefFromPid to get the PduRef to call RxInd with */
    udtGetPidRet = E_OK;
    if(pkstrLocFrame->enuFrameType == LinIf_EVENT_TRIGGERED)
    {
        udtGetPidRet = 
            udtGetRxPduRefFromPid(
                u8ChannelIndex,
                pstrCurrChannelVars->au8DataBuffer[0],
                &pkstrLocFrame);
    }
    /*!EndIf */
	
	udtRxRef = pkstrLocFrame->pkstrRxParams->udtLinIfRxPduRef;
    strPduInfo.SduLength = pkstrLocFrame->u8Length;
    
    
    /*!RxIndication is called in 2 cases: udtGetRxPduRefFromPid returns E_OK,
        or the frame is not an event triggered frame */
    /*!The data to be sent in the RxInd si got from au8DataBuffer of 
        the current channel */
    if(E_OK == udtGetPidRet)
    {
        strPduInfo.SduDataPtr = 
            &(pstrCurrChannelVars->au8DataBuffer[0]);

        /*\Trace_To: LinIf-CDD-0034(0) */
        /*\Trace_To: LinIf-CDD-0300(0) */
        pkstrLocFrame->pkstrRxParams->pfvidRxIndication(udtRxRef, &strPduInfo);
    }
       
}


/******************************************************************************/
/*!Function    : LinIf_vidSTMMain                                            */
/*  \Description The Main function of the Schedule Table manager, it operates
                 the currently running schedule table  \n   
    \param[in] Pointer to a channels post-build configuration structure \n
        \Range  0..LinIf_ku8eNumberOfChannels \n                              */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_vidSTMMain(
   P2CONST(LinIf_tstrChannelPBConf, AUTOMATIC, LINIF_CALIB_CONST) pkstrChannel)
{
    VAR(uint8, AUTOMATIC) u8ChannelIndex;
    P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR) pstrCurrChannelVars;
    u8ChannelIndex = pkstrChannel->u8ChannelIndx;
	pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);
    /*!If the u8TimeToNextEntry = 0 (the next entry is due)*/ 
    if(pstrCurrChannelVars->u8TimeToNextEntry == 0)
    {
        /*!Call vidHandleNewEntry to perform actions needed when a new entry 
            is due*/
        vidHandleNewEntry(u8ChannelIndex);

        /*!If the pkstrCurrScheduleTab is not NULL_SCH and there is 
            bGotoSleepFlag is false (no goto sleep command requested)*/
        if( (pstrCurrChannelVars->pkstrCurrScheduleTab->kudtIndex != 0 /*NULL_SCH*/
             ) 
             &&
             (FALSE == pstrCurrChannelVars->bSendGotoSleep)
          )
        {
            P2CONST(LinIf_tstrFrame, AUTOMATIC, LINIF_CALIB_CONST)
                                                        pkstrFrameToSend;
            VAR(uint16, AUTOMATIC)                      u16CurrentEntryIndex;
            
            /*!Get the new frame from the u16NextEntryIndex (now current 
                Entry index)*/
            u16CurrentEntryIndex =     
                pstrCurrChannelVars->u16NextEntryIndex;

                pkstrFrameToSend = 
                    &(LinIf_pkstreGlobalConfig->
                    pkstrFrames [LinIf_pkstreGlobalConfig->
                    pkstrScheduleEntries[u16CurrentEntryIndex].u16FrameIndex]);
                
            /*!Reload the delay to next entry from the delay in current entry,
                by setting u8TimeToNextEntry = CurrentEntry.u8Delay - 1*/

            pstrCurrChannelVars->u8TimeToNextEntry = 
                LinIf_pkstreGlobalConfig->
                pkstrScheduleEntries[u16CurrentEntryIndex].u8Delay - 1;

            /*!Increment u16NextEntryIndex by one */
            pstrCurrChannelVars->u16NextEntryIndex++;

            /*!If u16NextEntryIndex > the last index of pkstrCurrScheduleTab
                (u16StartEntryIndex + u16NumberOfEntries) */
            if(
                (pstrCurrChannelVars->u16NextEntryIndex) >=

                (pstrCurrChannelVars->pkstrCurrScheduleTab->
                u16StartEntryIndex 
                + 
                pstrCurrChannelVars->pkstrCurrScheduleTab->
                u16NumberOfEntries)
              )
            {
                /*!If pkstrCurrScheduleTab is a LinIf_RUN_CONTINUOUS schedule 
                    table */
                if(LinIf_RUN_CONTINUOUS == 
                    pstrCurrChannelVars->pkstrCurrScheduleTab->enuRunMode)
                {
                    /*! Set u16NextEntryIndex to u16StartEntryIndex */
                    pstrCurrChannelVars->u16NextEntryIndex = 
                        pstrCurrChannelVars->pkstrCurrScheduleTab->u16StartEntryIndex;
                }
                /*!Else (the schedule table is run once) */
                else
                {

                    /*! revert back to the last run_cont schedule table by 
                        calling vidChngChannelSchedule, with inputs 
                        pkstrPrevScheduleTab and revert = true          */
                    /*\Trace_To: LinIf-CDD-0062(0) */
                    vidChngChannelSchedule
                        (u8ChannelIndex,
                        pstrCurrChannelVars->pkstrPrevScheduleTab,
                        TRUE);
                }
                /*!Endif*/
            }
            /*!Endif*/

            /*! if enuFrameDirection of the current frame is LinIf_TX_PDU */
            switch(pkstrFrameToSend->enuFrameDirection)
            {
            case LinIf_TX_PDU:
                {
                    /*!if enuFrameType of the current frame is 
                        LinIf_UNCONDITIONAL */
                    if(LinIf_UNCONDITIONAL == pkstrFrameToSend->enuFrameType)
                    {
                        /*! Call vidSendUncondFrame with the new frame */
                        vidSendUncondFrame(u8ChannelIndex, pkstrFrameToSend);
                    }
                    /*!Else if enuFrameType of the current frame is 
                        LinIf_SPORADIC */
                    else if(LinIf_SPORADIC == pkstrFrameToSend->enuFrameType)
                    {
                        /*! Call vidHandleSporadicSlot with the new frame */
                        vidHandleSporadicSlot(u8ChannelIndex, pkstrFrameToSend);
                    }
                    else
                    {
                        /* do nothing, jsut for MISRA */   
                    }
                    /*!Endif*/
                }
                break;
            /*! Else If enuFrameDirection of the current frame is LinIf_RX_PDU
                or LinIf_SLAVE_TO_SLAVE_PDU */
            /*\Trace_To: LinIf-CDD-0032(0) */
            case LinIf_RX_PDU:
            /*\Trace_To: LinIf-CDD-0049(0) */
            case LinIf_SLAVE_TO_SLAVE_PDU:
                {
                    /*! Call vidSendFrameHeader with the new frame */
                    /*\Trace_To: LinIf-CDD-0032(0) */
                    /*\Trace_To: LinIf-CDD-0049(0) */
                    vidSendFrameHeader(u8ChannelIndex, pkstrFrameToSend);
                }
                break;
            /*! Else If enuFrameDirection of the current frame is 
                LinIf_INTERNAL_PDU */
            case LinIf_INTERNAL_PDU:
                {
                    /*! Call LinIf_vidTPSendFrame with the new frame to inform
                        that a TP/NC frame shall be processed */
                    LinIf_vidTPSendFrame(u8ChannelIndex, pkstrFrameToSend);
                }
                break;
                /*! Else do nothing error in configuration */
            default:
                {
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
                    /* TODO: REPORT ERROR */
#endif
                }
                break;
            }   
            /*!Endif*/
        }
        /*!Endif*/
    }
    /*! Else wait for the next entry*/
    else
    {
        /*\Trace_To: LinIf-CDD-0052(0) */
        /*!decrement u8TimeToNextEntry by 1 (time = 1 * time base tick) */
        pstrCurrChannelVars->u8TimeToNextEntry --;
    }                       
}


/******************************************************************************/
/*!Function    : LinIf_Transmit                                              */
/*  \Description Indicates a sporadic frame transmit request.   \n   
    \param[in] Upper layer identification of the LIN frame to be transmitted 
               (not the LIN protected ID). 
               This parameter is used to determine the corresponding LIN 
               protected ID (PID) and implicitly the LIN Driver instance as well
               as the corresponding LIN Controller device.  \n
        \Range  0..LinIf_pkstreGlobalConfig->u16NumberOfTxFrames \n 
    \param[in] Pointer to a structure with frame related data: DLC and pointer
               to frame data buffer. This parameter is not used by this call\n
        \Range  NOT NULL \n
    \return  
    E_OK: Transmit request has been accepted. 
    E_NOT_OK: Transmit request has not been accepted due to one 
    or more of the following reasons: 
    - LIN Interface has not been initialized 
    - referenced PDU does not exist (identification is out of range) \n       */
/*\Trace_To    : LinIf-CDD-0180(0)                                           */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE) LinIf_Transmit(
   VAR(PduIdType, AUTOMATIC) udtLinTxPduId, 
/******************************************************************************/
/*!Deviation : Inhibit MISRA rule [3206]: the function parameters are        */
/*              mandated by AutoSAR                                           */
/* PRQA S 3206 ++                                                             */
/******************************************************************************/
   P2CONST(PduInfoType, AUTOMATIC, LINIF_APPL_DATA) pkstrPduInfoPtr)
/* PRQA S 3206 --                                                             */

{
    VAR(Std_ReturnType, AUTOMATIC)  udtRet;
    VAR(uint16, AUTOMATIC)          u16TxFrameIdx;

    udtRet = E_OK;
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
    /*!If the LinIf_u8eLinIfState is UNINIT and the DevErrorDetect is true,
        report to Det LINIF_E_UNINIT */
    /*\Trace_To: LinIf-CDD-5016(0) */
    if(LinIf_u8eLinIfState != LinIf_u8STATE_INIT)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
                LINIF_INSTANCE_ID, 
                LinIf_u8LINIF_TRNSMT_SRV_ID,
                LINIF_E_UNINIT);
        udtRet = E_NOT_OK;
    }
    /*!If the input pointer is NULL and DevErrorDetect is ON, report 
        LINIF_E_PARAMETER_POINTER to Det */
    /*\Trace_To: LinIf-CDD-0185(0) */
    else if(    (P2CONST(PduInfoType, AUTOMATIC, LINIF_APPL_DATA))NULL_PTR 
                == 
                pkstrPduInfoPtr)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
                LINIF_INSTANCE_ID, 
                LinIf_u8LINIF_TRNSMT_SRV_ID,
                LINIF_E_PARAMETER_POINTER);
        udtRet = E_NOT_OK;
    }
    /*!If the input Id is greater than or equal to 
        LinIf_pkstreGlobalConfig->u16NumberOfTxFrames
        and DevErrorDetect is ON, report LINIF_E_PARAMETER to Det */
    /*\Trace_To: LinIf-CDD-0186(0) */
    else if(udtLinTxPduId >= LinIf_pkstreGlobalConfig->u16NumberOfTxFrames)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
                LINIF_INSTANCE_ID, 
                LinIf_u8LINIF_TRNSMT_SRV_ID,
                LINIF_E_PARAMETER);
        udtRet = E_NOT_OK;
    }
    else
    {
#endif
		u16TxFrameIdx = 
			       LinIf_pkstreGlobalConfig->pku16TxMappingTable[udtLinTxPduId];

        /*! If the frame of the input Id does not have bIsSporadic set to true
            set the return to E_NOT_OK, and if DevErrorDetect is ON, report 
            LINIF_E_PARAMETER to Det */
        /*\Trace_To: LinIf-CDD-0024(0) */
        /*\Trace_To: LinIf-CDD-0182(0) */
        if(LinIf_pkstreGlobalConfig->pkstrFrames[u16TxFrameIdx]
                                            .bIsSporadic != TRUE)
        {
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
            (void)Det_ReportError(LINIF_MODULE_ID, 
                LINIF_INSTANCE_ID, 
                LinIf_u8LINIF_TRNSMT_SRV_ID,
                LINIF_E_PARAMETER);
#endif
            udtRet = E_NOT_OK;
        }
        else
        {
            /*! Set the flag in LinIf_pkstreGlobalConfig->pbSporadicFramesFlags 
                of the index specified in the u16SporadicIndex of the frame of 
                the input Id to true */

            /*\Trace_To: LinIf-CDD-0025(0) */
            /*\Trace_To: LinIf-CDD-0182(0) */
            /*\Trace_To: LinIf-CDD-0183(0) */
			*(LinIf_pkstreGlobalConfig->pkstrFrames[u16TxFrameIdx].
                pbSporadic) = TRUE;															
        }
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
    }
#endif
    return udtRet;
}

/******************************************************************************/
/*!Function    : LinIf_CancelTransmit                                        */
/*  \Description    Indicates a Cancel Transmit request. This is a dummy method 
                    introduced for interface compatibility.    \n   
    \param[in]  Upper layer identification of the LIN frame for which a 
                cancellation should be done.   \n
        \Range  0..LinIf_pkstreGlobalConfig->u16NumberOfTxFrames \n 
    \return   
        E_NOT_OK: Cancel Transmit request has not been accepted. 
        Dummy method will always return E_OK. \n       */

/******************************************************************************/
#if (LinIf_bCANCEL_TX_SUPPORT == STD_ON)
FUNC(Std_ReturnType, LINIF_CODE) LinIf_CancelTransmit(
/******************************************************************************/
/* Deviation : Inhibit MISRA rules [3206]: The parmeter is not used except    */
/*             when LinIfDevErrorDetect is ON                                 */
/* PRQA S 3206 ++                                                             */
   VAR(PduIdType, AUTOMATIC) udtLinTxPduId)
/* PRQA S 3206 --                                                             */
{
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
    /*\Trace_To    : LinIf-CDD-0231(0)                                       */

    /*!If the LinIf_u8eLinIfState is UNINIT and the DevErrorDetect is true,
        report to Det LINIF_E_UNINIT */
    /*\Trace_To: LinIf-CDD-5032(0) */
    if(LinIf_u8eLinIfState != LinIf_u8STATE_INIT)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
                LINIF_INSTANCE_ID, 
                LinIf_u8LINIF_CNCLTX_SRV_ID,
                LINIF_E_UNINIT);
    }
    /*!If the input Id is greater than or equal to 
        LinIf_pkstreGlobalConfig->u16NumberOfTxFrames
        and DevErrorDetect is ON, report LINIF_E_PARAMETER to Det */
    /*\Trace_To: LinIf-CDD-0233(0) */
    else if(udtLinTxPduId >= LinIf_pkstreGlobalConfig->u16NumberOfTxFrames)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
                LINIF_INSTANCE_ID, 
                LinIf_u8LINIF_CNCLTX_SRV_ID,
                LINIF_E_PARAMETER);
    }
    /*!Do nothig just return E_OK if non of the previous error happened,
        else return E_NOT_OK */
    else
    {
        /* do nothing just for MISRA */
    }
    return E_NOT_OK;
#endif
    
}
#endif


/******************************************************************************/
/*!Function    : LinIf_ScheduleRequest                                       */
/*  \Description    Requests a schedule table to be executed.     \n   
    \param[in]  Channel index.    \n
        \Range  0..LinIf_ku8eNumberOfChannels \n 
    \param[in]  Identification of the new schedule to be set.     \n
        \Range  0..Number of schedule tables in the channel referenced 
                by the first parameter \n 
    \return  
        E_OK: Schedule table request has been accepted. 
        E_NOT_OK: Schedule table switch request has not been 
        accepted due to one of the following reasons: 
        - LIN Interface has not been initialized 
        - referenced channel does not exist (identification is out of range)
        - referenced schedule table does not exist (identification is out of 
        range) 
        - State is sleep  \n       */
/*\Trace_To    : LinIf-CDD-0187(0), LinIf-CDD-0189(0)                        */
/******************************************************************************/
FUNC(Std_ReturnType, LINIF_CODE)  LinIf_ScheduleRequest( 
    VAR(NetworkHandleType, AUTOMATIC) udtChannel, 
    VAR(LinIf_SchHandleType, AUTOMATIC) udtSchedule)
{
    VAR(Std_ReturnType, AUTOMATIC)  udtRet;
    VAR(uint8, AUTOMATIC)           u8ChannelIndex;
	P2VAR(LinIf_tstrChannelVars, AUTOMATIC, LINIF_VAR) pstrCurrChannelVars;
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
    /*!If the LinIf_u8eLinIfState is UNINIT and the DevErrorDetect is true,
        report to Det LINIF_E_UNINIT */

    /*\Trace_To: LinIf-CDD-5018(0) */
    if(LinIf_u8eLinIfState != LinIf_u8STATE_INIT)
    {
        (void)Det_ReportError(LINIF_MODULE_ID, 
            LINIF_INSTANCE_ID, 
            LinIf_u8LINIF_SCHREQ_SRV_ID,
            LINIF_E_UNINIT);
        udtRet = E_NOT_OK;
    }
    else
    {
#endif
        /*!Call LinIf_udtGetChannelIndexById to get the referenced channel 
            Index in the channels array */
        /*!If LinIf_udtGetChannelIndexById returns E_NOT_OK and the 
            DevErrorDetect is true, report to Det LINIF_E_NONEXISTENT_CHANNEL */

        /*\Trace_To: LinIf-CDD-0191(0) */
        udtRet = LinIf_udtGetChannelIndexById(udtChannel, &u8ChannelIndex);
		pstrCurrChannelVars = &(LinIf_astreChannelsVars[u8ChannelIndex]);
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
        if(E_NOT_OK == udtRet)
        {
            (void)Det_ReportError(LINIF_MODULE_ID, 
                LINIF_INSTANCE_ID, 
                LinIf_u8LINIF_SCHREQ_SRV_ID,
                LINIF_E_NONEXISTENT_CHANNEL);
        }
    /*!If the input schedule Id is greater than Number of schedule tables 
        in the channel referenced by the Id and the DevErrorDetect is true,
        report to Det LINIF_E_PARAMETER */
        /*!Note that the number refereneced in the channel is number of 
            schedules - 1. this is because the NULL_SCH is not counted 
            while it has an Id (0)*/
        /* > only to accomodate NULL_SCH, as u8NumberOfSchTabs = 
            number of schedule tables - 1*/
        else if(udtSchedule > 
            LinIf_pkstreGlobalConfig->pkstrChannels[u8ChannelIndex].
            u8NumberOfSchTabs) 
        {
            (void)Det_ReportError(LINIF_MODULE_ID, 
                LINIF_INSTANCE_ID, 
                LinIf_u8LINIF_SCHREQ_SRV_ID,
                LINIF_E_SCHEDULE_REQUEST_ERROR);
            udtRet = E_NOT_OK;
        }

        /*!If the u8IFChannelState is SLEEP and the DevErrorDetect is true,
            report to Det LINIF_E_SCHEDULE_REQUEST_ERROR */
        /*\Trace_To: LinIf-CDD-0057(0) */
        /*\Trace_To: LinIf-CDD-0192(0) */
        else if(LinIf_u8CHANNEL_SLEEP == 
            pstrCurrChannelVars->u8IFChannelState)
        {
            (void)Det_ReportError(LINIF_MODULE_ID, 
                LINIF_INSTANCE_ID, 
                LinIf_u8LINIF_SCHREQ_SRV_ID,
                LINIF_E_SCHEDULE_REQUEST_ERROR);
            udtRet = E_NOT_OK;
        }
        else
        {
#endif
            /*!If any of the above errors is detected return E_NOT_OK */
            /*!Else */
            /*!If bGotoSleepFlag = False (no sleep request) */
            /*\Trace_To: LinIf-CDD-5156(0) */
            if(FALSE == pstrCurrChannelVars->bGotoSleepFlag)
            {
                /*!Enter critical section 001*/
                LinIf_akstreChannelsCritSec[u8ChannelIndex].
                                                        pfvidEnterSecSchTab001();

                /*! If the requested schedule is NULL_SCHEDULE (Id = 0)
                    set pkstrBufferedSchTab to kstrNULLSchedule */
                if(udtSchedule == 0)
                {
                    pstrCurrChannelVars->pkstrBufferedSchTab=
                        &kstrNULLSchedule;
                }
                else
                {
                    /*! else Set pkstrBufferedSchTab (the buffered request) to 
                        the schedule whose index in the schdule tables array =
                        u16ScheduleTablesIndex in the current channel + 
                        the input schedule Id - 1 */
                    pstrCurrChannelVars->pkstrBufferedSchTab=
                        &(LinIf_pkstreGlobalConfig->pkstrScheduleTables
                        [
                            LinIf_pkstreGlobalConfig->
                            pkstrChannels[u8ChannelIndex].u16ScheduleTablesIndex
                            + 
                            (udtSchedule - 1)  /* zero already handled */
                        ]);
                }
                /*!Exit critical section 001*/
                LinIf_akstreChannelsCritSec[u8ChannelIndex].
                                                        pfvidExitSecSchTab001();
            }
            else /*!Else reject request, the module is going to sleep */
            {
                
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
                /*! If DevErrorDetect is ON report 
                    LINIF_E_SCHEDULE_REQUEST_ERROR */
                (void)Det_ReportError(LINIF_MODULE_ID, 
                LINIF_INSTANCE_ID, 
                LinIf_u8LINIF_SCHREQ_SRV_ID,
                LINIF_E_SCHEDULE_REQUEST_ERROR);
#endif

                udtRet = E_NOT_OK;
            }
            /*!EndIf */
#if (LinIf_u8DEV_ERROR_DETECT == STD_ON)
        }
        /*!EndIf */
    }
#endif
    return udtRet;
}

/******************************************************************************/
/*!Function    : LinIf_vidSTMSetNullSchedule                                 */
/*  \Description    Requests a NULL_SCH table to be set for the input channel.\n
    \param[in]  Channel index.    \n                                          */
/******************************************************************************/
FUNC(void, LINIF_CODE) LinIf_vidSTMSetNullSchedule(
    VAR(uint8, AUTOMATIC) u8ChannelIndex)
{
    /*!Set pkstrCurrScheduleTab to NULL_SCH */
    LinIf_astreChannelsVars[u8ChannelIndex].pkstrCurrScheduleTab = 
        &kstrNULLSchedule;
}
#define LINIF_STOP_SEC_CODE
#include "Memmap.h"

/*-------------------------------- end of file -------------------------------*/
/* PRQA L:L1                                                                  */