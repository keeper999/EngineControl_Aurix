/******************************************************************************/
/*                                                                            */
/* !Layer           : HAL                                                     */
/*                                                                            */
/* !Component       : CanIf                                                   */
/*                                                                            */
/*!\Module          : CanIf_ModeHandler                                       */
/*!\file                : CanIf_ModeHandler.c                                 \n
    \Description        : This subcomponent is responsible for mode handling    
                          related functionalities                             */
/*                                                                            */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : VIAS                                                    */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2009 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* $Archive::   Y:/Prod_01/B791130I0/archives/B791130I0/02_Modules/17_CanIf/0$*/
/* $Revision::   1.32     $$Author::   mamroussy      $$Date::   Aug 03 2014 $*/
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/* PRQA S 0838,0863,0862 EOF */
/*MISRA Msg justification:   not included Multi Times QAC Violation           */

/* PRQA S 0850 EOF */
/*MISRA Msg justification:   Inhibit MISRA rule [0838]: AUTOMATIC keyword is    
                             defined as an empty macro                        */
/* PRQA S 0857 EOF */
/* MISRA Msg justification:  Number of macro definitions exceeds 1024 
                             as the module needs a lot of macro(s)            */								 
#include "CanIf.h"
#include "CanIf_LocalCfg.h"
#include "CanIf_LocalLCfg.h"
#include "CanIf_PBCfg.h"
#include"CanIf_General.h"
#include "CanIf_ModeHandler.h"
#include "CanIf_Transmission.h"
#include "SchM_CanIf.h"
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
#include "Det.h"
#endif

#if(CanIf_bDEM_ERR_DETECT == STD_ON)
#include "Dem.h"
#endif
/*****************************Version Checking*********************************/
#define u8C_SW_MAJOR_VERSION    (2)
#define u8C_SW_MINOR_VERSION    (0)
/******************************************************************************/
/*                      Implementation version checking                       */
/******************************************************************************/
/*                           Intra-Module Checking                            */
/******************************************************************************/
#if (u8C_SW_MAJOR_VERSION != CANIF_SW_MAJOR_VERSION)
    #error Incompatible ComM SW major version between C & H files.
#endif
#if (u8C_SW_MINOR_VERSION != CANIF_SW_MINOR_VERSION)
    #error Incompatible ComM SW minor version between C & H files.
#endif
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
#define u8SLEEPFLAG_CLEARD              0
#define u8SLEEPFLAG_SET                 1
/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
#define CANIF_START_SEC_CODE
#include "MemMap.h"
/******************************************************************************/
/*! \Description : This service calls the corresponding CAN Driver service for  
                   changing of the CAN controller mode.                       \n
    \param[in]     ControllerId:  Abstracted CanIf ControllerId which is        
                   assigned to a CAN controller, which is requested             
                   for mode transition.                                       \n
    \Range         0..CanIf_ku8eNumOfControllers-1                            \n
    \param[in]     ControllerMode:  Requested mode transition                 \n
    \Range         CANIF_CS_SLEEP,CANIF_CS_STARTED,CANIF_CS_STOPPED           \n
    \return        Controller mode request has been accepted or not           \n
    \Range         E_OK, E_NOT_OK                                             \n
    \Trace_To CANIF-CDD-0167(0)                                                 
*******************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE)CanIf_SetControllerMode(
    VAR(uint8, AUTOMATIC) ControllerId,
    VAR(CanIf_ControllerModeType, AUTOMATIC) ControllerMode)
{
    /* the return of the service                                              */
    VAR(Std_ReturnType, AUTOMATIC)              udtResult=E_NOT_OK;
    /* the retrun of the Set Controller Mode CanDrv offered service 
        as it is of type Can_ReturnType                                       */
    VAR(Can_ReturnType, AUTOMATIC)              enuSetModeResult;
    /*the mode of transition that will be requested from Can Drv              */
    VAR(Can_StateTransitionType, AUTOMATIC)     udtTransitionToRequest;
    /*the current Controller mode                                             */
    VAR(CanIf_ControllerModeType, AUTOMATIC)    udtCurrControllerMode;
    /* to abort setting controller mode in case of error occured              */
    VAR(Std_ReturnType, AUTOMATIC)              udtResumeSetMode=E_OK;
    /* Check that CanIf CanIf_bDEV_ERR_DETECT is Enabled                      */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
    /*! Check if CanIf isnot initialized                                      */
    /* \Trace_To CANIF-CDD-5031(0)                                            */
    /* \Trace_To CANIF-CDD-0169(0)                                            */
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
        /*! Report error CanIf isnot initialized to Det                       */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8SETCTRLMODE_API, CANIF_E_UNINIT);
    }
    /*! Check that ControllerId not exceeding range of configured Controllers   
    Ids                                                                       */
    /* \Trace_To CANIF-CDD-0170(0)*/
    else if(ControllerId>=CanIf_ku8eNumOfControllers)
    {
        /*! Report error ControllerId is exceeding range of Controllers Ids   */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8SETCTRLMODE_API,
            CANIF_E_PARAM_CONTROLLERID);
    }
    else
#endif
        /*! if non of previous errors detected resume                         */
    {

        /*!get Current Controller mode                                        */
        SchM_Enter_CanIf_CurrConMode_03();
        udtCurrControllerMode=CanIf_aenueCurrControllerMode[ControllerId];
        SchM_Exit_CanIf_CurrConMode_03();
        /*! check the upper layer requested mode transition is valid then check 
        each separately                                                       */
        /*! check upper layer requested mode transition                       */
        /*! then determine the mode to be requested from the CanDrv from type   
        Can_StateTransitionType                                               */
        switch(ControllerMode)
        {
        case CANIF_CS_STARTED:
            {
                /* \Trace_To CANIF-CDD-0077(0)                                */
                /* \Trace_To CANIF-CDD-0092(0)                                */
                udtTransitionToRequest =CAN_T_START;
            }
            break;
        case CANIF_CS_SLEEP:
            {
                /* \Trace_To CANIF-CDD-0097(0)                                */
                /* \Trace_To CANIF-CDD-0079(0)                                */
                udtTransitionToRequest =CAN_T_SLEEP;
            }
            break;
        case CANIF_CS_STOPPED:
            {
                if(udtCurrControllerMode==CANIF_CS_SLEEP)
                {
                    /* \Trace_To CANIF-CDD-0099(0)                            */
                    udtTransitionToRequest =CAN_T_WAKEUP;
                }
                else
                {
                    /* \Trace_To CANIF-CDD-0074(0)                            */
                    /* \Trace_To CANIF-CDD-0094(0)                            */
                    udtTransitionToRequest =CAN_T_STOP;
                }
            }
            break;
        default:
            /*!ControllerMode input parameter is invalid                      */
			udtTransitionToRequest =CAN_T_START;
            udtResumeSetMode=E_NOT_OK;
            break;
        }
        /*!call the CanDrv pfenuSetControllerMode service offeredby the         
        underlying CanDrv that this ControllerId is is assigned to with         
        input parameters Controller reference and the recently determined       
        requested mode from Can_StateTransitionType                           */

        /*! If during function CanIf_SetControllerMode() the call of            
        Can_SetControllerMode()returns with CAN_NOT_OK,                         
        CanIf_SetControllerMode() returns E_NOT_OK.                           */
        /* \Trace_To CANIF-CDD-0073(0)                                        */
        /* \Trace_To CANIF-CDD-0168(0)                                        */
        /*!check if ControllerMode is valid*/
        if(udtResumeSetMode==E_OK)
        {
/* PRQA S 3353 ++ */
/*MISRA Msg justification:  udtTransitionToRequest is sure 
                            set befor this point                              */
            enuSetModeResult= CanIf_akstreCanServicesPCCfg
                [CanIf_akstreCtrlLCfg[ControllerId].u8CanDrvId]
            .pfenuSetControllerMode(CanIf_akstreCtrlLCfg[ControllerId]
            .u8CtrlIdRef,udtTransitionToRequest);
/* PRQA S 3353 -- */
            if(enuSetModeResult==CAN_OK)
            {
                /*!Return is E_OK                                             */
                udtResult =E_OK;
            }
        }
    }
    /*!return the result of CanIf CanIf_SetControllerMode request to the        
    upperlayer                                                                */
    return(udtResult);
}
/******************************************************************************/
/*!\Description : This service reports about the current status of the          
                   requested CAN controller.                                  \n
    \param[in]     ControllerId:  Abstracted CanIf ControllerId which is        
                   assigned to a CAN controller, which is requested             
                   for mode transition.                                       \n
    \Range         0..CanIf_ku8eNumOfControllers-1                            \n
    \param[out]     ControllerModePtr:  Pointer to a memory location, where     
                   the current mode of the CAN controller will be stored.     \n
    \Range         Not NULL                                                   \n
    \return        Controller mode request has been accepted or not           \n
    \Range         E_OK, E_NOT_OK                                             \n
    \Trace_To CANIF-CDD-0172(0)                                                 
*******************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE)CanIf_GetControllerMode(
    VAR(uint8, AUTOMATIC) ControllerId,
    P2VAR(CanIf_ControllerModeType,AUTOMATIC,CANIF_APPL_DATA)
    ControllerModePtr)
{
/* PRQA S 3197 ++ */
/* MISRA Msg justification:  The variable must be initialized with a default
                             value to handle some cases where it will not be
							 updated later (under certain pre-processor
							 configuration parameters)                        */	
    /*! the return of the service                                             */
    VAR(Std_ReturnType, AUTOMATIC) udtResult=E_NOT_OK;
    /*! Check that CanIf CanIf_bDEV_ERR_DETECT is Enabled                     */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
    /*! Check if CanIf isnot initialized                                      */
    /* \Trace_To CANIF-CDD-5033(0)                                            */
    /* \Trace_To CANIF-CDD-0174(0)                                            */
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
        /*! Report error CanIf isnot initialized to Det                       */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8GETCTRLMODE_API, CANIF_E_UNINIT);
    }
    /*! Check that ControllerId not exceeding range of Controllers Ids        */
    /* \Trace_To CANIF-CDD-0175(0)*/
    else if(ControllerId>=CanIf_ku8eNumOfControllers)
    {
        /*! Report error ControllerId is exceeding range of Controllers Ids   */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8GETCTRLMODE_API,
            CANIF_E_PARAM_CONTROLLERID);
    }
    /*! Check that Output parameter ControllerModePtr isnot Null befor accessing
    it                                                                        */
    /* \Trace_To CANIF-CDD-0176(0)*/
    else if(ControllerModePtr == NULL_PTR)
    {
        /*! Report error ControllerModePtr is Null                            */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8GETCTRLMODE_API,
            CANIF_E_PARAM_POINTER);
    }
    /*if any of the previous errors occured Controller mode request has not been
    accepted.assign the return value to E_NOT_OK                              */
    else
#endif
        /*! if non of previous errors detected resume                         */
    {

        /*!assign the current Controller Id mode to value at the output         
        parameter ControllerModePtr                                           */
        /* \Trace_To CANIF-CDD-0173(0)                                        */
        SchM_Enter_CanIf_CurrConMode_04();
        *(ControllerModePtr) = CanIf_aenueCurrControllerMode[ControllerId];
        SchM_Exit_CanIf_CurrConMode_04();
        /*! Controller mode request has been accepted.assign the return of      
        CanIf_GetControllerMode to E_OK                                       */
        udtResult = E_OK;
    }
    return (udtResult);
/* PRQA S 3197 -- */
}
/******************************************************************************/
/*!\Description : This service indicates a controller state transition          
                   referring to the corresponding CAN controller.             \n
    \param[in]     CanDrvId: the driver Id that this  Controller                
                   mode indication requested from                             \n
    \Range         0..CanIf_u8NUM_OF_CAN_DRVS-1                               \n
    \param[in]     Controller:  CAN controller, which state has been            
                   transitioned.                                              \n
    \Range         Maximum Number of Controlers assigned to that CanDrvId     \n
    \param[in]     ControllerMode:  Mode to which the CAN controller            
                   transitioned                                               \n
    \Range         CANIF_CS_SLEEP,CANIF_CS_STARTED,CANIF_CS_STOPPED           \n
    \return        void                                                       \n
    \Range         N/A                                                        \n
*******************************************************************************/
FUNC(void, CANIF_CODE)CanIf_vidCntrlModeIndic(
    VAR(uint8, AUTOMATIC)                       Controller,
    VAR(CanIf_ControllerModeType, AUTOMATIC)    ControllerMode,
	VAR(uint8, AUTOMATIC)                       CanDrvId)
{
/* PRQA S 0781 ++ */
/*MISRA Msg justification:  no problem from the same name of u8ControllerId   */
    /* the abstcacted CanId Controller ID                                     */
    VAR(uint8, AUTOMATIC)   u8ControllerId;
/* PRQA S 0781 ++ */
    /*variable to use in search                                               */
    VAR(uint8, AUTOMATIC)   u8SearchIndex;
    /*boolean to indicate if controller found or not                          */
    VAR(boolean, AUTOMATIC) bControllerFound=FALSE;
    /* Check if CanIf isnot initialized                                       */
    /*If the CanIf was not initialized before calling                           
    CanIf_ControllerModeIndication(),then the function                          
    CanIf_ControllerModeIndication()shall not execute state transition 
    notification                                                              */
    /* \Trace_To CANIF-CDD-5090(0)                                            */
    /* \Trace_To CANIF-CDD-0335(0)                                            */
    /* \Trace_To CANIF-CDD-0336(0)                                            */
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
        /*! Check that CanIf CanIf_bDEV_ERR_DETECT is Enabled                 */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
        /*! Report error CanIf isnot initialized to Det                       */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8CTRLMODEINDIC_API, CANIF_E_UNINIT);
#endif
    }
    /* PRQA S 3356,3359,3201 ++                                               */
    /*MISRA Msg justification:  alwayes False ,only for protection            */
    else if(
        ((ControllerMode!=CANIF_CS_UNINIT)&&(ControllerMode!=CANIF_CS_STARTED))
        &&((ControllerMode!=CANIF_CS_SLEEP)&&(ControllerMode!=CANIF_CS_STOPPED))
        )
    {
        /*!Do nothing and odn't enter the normal Execution of the service     */
    }
    /*if any of the previous errors occured Controller mode request has not 
    been accepted.assign the return value to E_NOT_OK                         */
    else
    {
        /* PRQA S 3356,3359,3201 --                                           */
        /*! if non of previous errors detected resume                         */
        /*!search in CanIf_akstreCtrlLCfg for the u8ControllerId using the 
        Controller input parameter and the CanDrvId                           */
        u8SearchIndex=0;
        while((u8SearchIndex<CanIf_ku8eNumOfControllers)&&(bControllerFound
                ==FALSE))
        {
            if((CanIf_akstreCtrlLCfg[u8SearchIndex].u8CtrlIdRef==Controller)&&
                (CanIf_akstreCtrlLCfg[u8SearchIndex].u8CanDrvId==CanDrvId))
            {
                /*!if search found the specific u8ControllerId                */
                u8ControllerId = u8SearchIndex;
                /*!change the current modwe of thisController If to the         
                inputparameter ControllerMode                                 */
                /* \Trace_To CANIF-CDD-0075(0)                                */
                /* \Trace_To CANIF-CDD-0078(0)                                */
                /* \Trace_To CANIF-CDD-0080(0)                                */
                /* \Trace_To CANIF-CDD-0093(0)                                */
                /* \Trace_To CANIF-CDD-0095(0)                                */
                /* \Trace_To CANIF-CDD-0098(0)                                */
                /* \Trace_To CANIF-CDD-0100(0)                                */
                bControllerFound=TRUE;
                SchM_Enter_CanIf_CurrConMode_17();
                CanIf_aenueCurrControllerMode[u8ControllerId]=ControllerMode;
                /*! call User_ControllerModeIndication if configured          */
                if (CanIf_kstreDispatchLCfg.pfvidControllerModeIndic
                    !=NULL_PTR)
                {
                    /* \Trace_To CANIF-CDD-0103(0)                            */
                    /*!notify the upper layer with this Controllermode change */
                    CanIf_kstreDispatchLCfg.pfvidControllerModeIndic
                        (u8ControllerId,CanIf_aenueCurrControllerMode
                        [u8ControllerId]);
                }
                /*!check if the currnt mode after changing it has gone to 
                   CANIF_CS_STOPPED                                           */
                /* \Trace_To CANIF-CDD-5259(0)                                */
                if(CanIf_aenueCurrControllerMode[u8ControllerId]
                ==CANIF_CS_STOPPED)
                {
#if(CanIf_bTX_BUFFERING==STD_ON)
                    /* \Trace_To CANIF-CDD-5259(0)                            */
                    /*!Clear All Transnmit buffers                            */
                    CanIf_vidClearTransmitBuffers(u8ControllerId);
#endif
#if (CanIf_bTXCONF_POLL_SUPPORT == STD_ON)
                    SchM_Enter_CanIf_TxConfStat_17();
                    CanIf_vidClearTxConfirmState(u8ControllerId);
                    SchM_Exit_CanIf_TxConfStat_17();
#endif
                }
                SchM_Exit_CanIf_CurrConMode_17();
            }
            u8SearchIndex++;
        }
        if(bControllerFound==FALSE)
        {
            /*!search didn't find the specific ControllerId                   */
            /* \Trace_To CANIF-CDD-0334(0)                                    */
            /*! Check that CanIf CanIf_bDEV_ERR_DETECT is Enabled             */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
            /*! Report error that CANIF_E_PARAM_CONTROLLER is invalid         */
            CanIf_vidDET_REPORT_ERROR(CanIf_u8CTRLMODEINDIC_API,
                CANIF_E_PARAM_CONTROLLER);
#endif
        }
    }
}
#if(CanIf_u8NUM_OF_TRCV_DRVS !=0||CanIf_bDEV_ERR_DETECT==STD_ON)
/******************************************************************************/
/*!\Description : This service changes the operation mode of the tansceiver     
                  TransceiverId, via calling the corresponding CAN Transceiver  
                  Driver service.                                             \n
    \param[in]     TransceiverId: Abstracted CanIf TransceiverId,               
                   which is assigned to a CAN transceiver, which is requested   
                   for mode transition                                        \n
    \Range         0..CanIf_u8NUM_OF_TRCVS-1                                  \n
    \param[in]     Requested mode transition                                  \n
    \Range         Maximum Number of Controlers assigned to that CanDrvId     \n
    \return        transceiver changed to requestd to rquested mode or not    \n
    \Range         E_OK: Will be returned, if the transceiver state has been    
                   changed to the requested mode.                               
                   E_NOT_OK: Will be returned, if the transceiver state         
                   change has failed or the parameter is out of the allowed     
                   range.The previous state has not been changed.             \n
    \Trace_To CANIF-CDD-0263(0)                                                 
*******************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE)CanIf_SetTrcvMode(
    VAR(uint8, AUTOMATIC) TransceiverId,
    VAR(CanTrcv_TrcvModeType, AUTOMATIC) TransceiverMode)
{
/* PRQA S 3197 ++ */
/* MISRA Msg justification:  The variable must be initialized with a default
                             value to handle some cases where it will not be
							 updated later (under certain pre-processor
							 configuration parameters)                        */	
    /* the return of the service                                              */
    VAR(Std_ReturnType, AUTOMATIC) udtResult=E_NOT_OK;
    /* \Trace_To CANIF-CDD-5215(0)                                            */
/*! If this API operation isnot supported (NUM_OF_TRANS = 0)and it is requested,
    then the CanIf shall recognize this error as development error with error   
    code CANIF_E_NOK_NOSUPPORT.Because in that case this API isnot supported. */
#if(CanIf_u8NUM_OF_TRCVS==0)
    CanIf_vidDET_REPORT_ERROR(CanIf_u8SETTRCVMODE_API,CANIF_E_NOK_NOSUPPORT);
#else
/*! Check that CanIf CanIf_bDEV_ERR_DETECT is Enabled                         */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
    /*! Check if CanIf isnot initialized                                      */
    /* \Trace_To CANIF-CDD-5058(0)                                            */
    /* \Trace_To CANIF-CDD-0266(0)                                            */
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
        /*! Report error CanIf isnot initialized to Det                       */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8SETTRCVMODE_API, CANIF_E_UNINIT);
    }
    /*! Check that TransceiverId not exceeding range of configured Transceivers
        Ids                                                                   */
    /* \Trace_To CANIF-CDD-0265(0)                                            */
    else if(TransceiverId>=CanIf_u8NUM_OF_TRCVS)
    {
        /*! Report error TransceiverId is exceeding range of configured 
            Transceivers Ids                                                  */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8SETTRCVMODE_API, CANIF_E_PARAM_TRCV);
    }
    /* PRQA S 3356,3359,3201 ++ */
    /*MISRA Msg justification:  alwayes False ,only for protection            */
    /*! Check that If parameter TransceiverMode of CanIf_SetTrcvMode()
    has an invalid value                                                      */
    /* \Trace_To CANIF-CDD-0267(0)                                            */
    else if((TransceiverMode != CANTRCV_TRCVMODE_NORMAL)
        &&(TransceiverMode != CANTRCV_TRCVMODE_SLEEP)
        &&(TransceiverMode != CANTRCV_TRCVMODE_STANDBY))
    {
        /*!report development error code CANIF_E_PARAM_TRCVMODE to              
        the Det_ReportError service of the DET module as parameter              
        TransceiverMode of CanIf_SetTrcvMode()has an invalid value            */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8SETTRCVMODE_API,
            CANIF_E_PARAM_TRCVMODE);
    }
    /* PRQA S 3356,3359,3201 -- */
   /*if any of the previous errors occured Controller mode request has not      
    been accepted.assign the return value to E_NOT_OK                         */
    else
#endif
    {
        /*! if non of previous errors detected resume                         */
        /* \Trace_To CANIF-CDD-0264(0)                                        */
        /*! call the function CanTrcv_SetOpMode(Transceiver, OpMode)offered     
        by CAN Transceiver Driver module of the corresponding requested CAN     
        Transceiver reference*/
        /*! If during function CanIf_SetTrcvMode() the call of                  
        CanTrcv_SetOpMode()returns with CAN_NOT_OK,CanIf_SetTrcvMode() returns  
        E_NOT_OK.                                                             */
        udtResult = CanIf_akstreCanTrcvSrvcsPCCfg[CanIf_akstreCanTrcvPCCfg
                        [TransceiverId].u8TrcvDrvId].pfu8SetOpMode
                        (CanIf_akstreTransLCfg[TransceiverId].u8TrcvIdRef,
                        TransceiverMode);
    }
#endif/*CanIf_u8NUM_OF_TRCVS==0                                               */
    return(udtResult);
}
/* PRQA S 3197 -- */	
#endif/*CanIf_u8NUM_OF_TRCVS!=0||CanIf_bDEV_ERR_DETECT==STD_ON                */

#if(CanIf_u8NUM_OF_TRCV_DRVS !=0||CanIf_bDEV_ERR_DETECT==STD_ON)
/******************************************************************************/
/*!\Description : This function invokes CanTrcv_GetOpMode and updates           
                   the parameter TransceiverModePtr with the value              
                   OpMode provided by CanTrcv.                                \n
    \param[in]     TransceiverId: Abstracted CanIf TransceiverId, which is      
                   assigned to a CAN transceiver, which is requested for        
                   current operation mode.                                    \n
    \Range         0..CanIf_u8NUM_OF_TRCVS-1                                  \n
    \param[out]     TransceiverModePtr Requested mode of requested network      
                   the Transceiver is connected to.                           \n
    \Range         not Null                                                   \n
    \return        Transceiver mode request has been accepted or not          \n
    \Range         E_OK,E_NOT_OK                                              \n
    \Trace_To CANIF-CDD-0269(0)                                                 
*******************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE)CanIf_GetTrcvMode(
    P2VAR(CanTrcv_TrcvModeType,AUTOMATIC,CANIF_APPL_DATA)TransceiverModePtr,
    VAR(uint8, AUTOMATIC) TransceiverId)
{
/* PRQA S 3197 ++ */
/* MISRA Msg justification:  The variable must be initialized with a default
                             value to handle some cases where it will not be
							 updated later (under certain pre-processor
							 configuration parameters)                        */	
    /* the return of the service                                              */
    VAR(Std_ReturnType, AUTOMATIC) udtResult=E_NOT_OK;
/*! If this API operation isnot supported (NUM_OF_TRANS = 0) and it is requested
, then the CanIf shall recognize this error as development error with error code
CANIF_E_NOK_NOSUPPORT.Because in that case this API isnot supported.          */
    /* \Trace_To CANIF-CDD-5216(0)                                            */
#if(CanIf_u8NUM_OF_TRCVS==0)
    CanIf_vidDET_REPORT_ERROR(CanIf_u8GETTRCVMODE_API,CANIF_E_NOK_NOSUPPORT);
#else
/*! Check that CanIf CanIf_bDEV_ERR_DETECT is Enabled                         */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
    /*! Check if CanIf isnot initialized                                      */
    /* \Trace_To CANIF-CDD-0273(0)                                            */
    /* \Trace_To CANIF-CDD-5060(0)                                            */
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
        CanIf_vidDET_REPORT_ERROR(CanIf_u8GETTRCVMODE_API, CANIF_E_UNINIT);
    }
    /*! Check that TransceiverId not exceeding range of configured Transceivers
        Ids                                                                   */
    /* \Trace_To CANIF-CDD-0271(0)                                            */
    else if(TransceiverId>=CanIf_u8NUM_OF_TRCVS)
    {
        CanIf_vidDET_REPORT_ERROR(CanIf_u8GETTRCVMODE_API,CANIF_E_PARAM_TRCV);
    }
    /*!check If parameter TransceiverModePtr of CanIf_GetTrcvMode()has an       
    invalid value                                                             */
    /* \Trace_To CANIF-CDD-0272(0)                                            */
    else if(TransceiverModePtr == NULL_PTR)
    {
        /*!report development error code CANIF_E_PARAM_POINTER to the           
        Det_ReportError service                                               */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8GETTRCVMODE_API,
            CANIF_E_PARAM_POINTER);
    }
   /*if any of the previous errors occured Controller mode request has not been 
   accepted.assign the return value to E_NOT_OK                               */
    else
#endif
    {
        /*! if non of previous errors detected resume                         */
        /* \Trace_To CANIF-CDD-0270(0)                                        */
        /*! call the function CanTrcv_GetOpMode(Transceiver, OpMode)
        offered by CAN Transceiver Driver module of the corresponding requested 
        CAN Transceiver reference                                             */
        /*! If during function CanIf_GetTrcvMode() the call of                  
        CanTrcv_GetOpMode()returns with CAN_NOT_OK,CanIf_GetTrcvMode()          
        returns E_NOT_OK.                                                     */
        udtResult = CanIf_akstreCanTrcvSrvcsPCCfg[CanIf_akstreCanTrcvPCCfg
            [TransceiverId].u8TrcvDrvId].
            pfu8GetOpMode(CanIf_akstreTransLCfg
            [TransceiverId].u8TrcvIdRef,TransceiverModePtr);
        if(udtResult==E_OK)
        {
            /*! leave udtResult=E_OK                                          */
        }
        else
        {
            udtResult= E_NOT_OK;
        }
    }
#endif/*CanIf_u8NUM_OF_TRCVS==0                                               */
    return(udtResult);
}
/* PRQA S 3197 -- */
#endif/*CanIf_u8NUM_OF_TRCVS!=0||CanIf_bDEV_ERR_DETECT==STD_ON                */

/******************************************************************************/
/*!\Description : This service indicates a transceiver state transition         
                   referring to the corresponding CAN transceiver.            \n
    \param[in]     CanTrcvDrvId: transceiver driver that this Transceiver is 
                   assignedt to                                               \n
    \Range         0..CanIf_u8NUM_OF_TRCV_DRVS-1                              \n
    \param[in]     Transceiver: CAN transceiver, which state has been           
                   transitioned.                                              \n
    \Range         0.. number oftransceivers assigned to that CanTrcvDrvId    \n
    \param[in]     TransceiverMode Mode to which the CAN transceiver            
                   transitioned                                               \n
    \Range         CANTRCV_TRCVMODE_NORMAL,CANTRCV_TRCVMODE_SLEEP,              
                   CANTRCV_TRCVMODE_STANDBY                                   \n
    \return        void                                                       \n
    \Range         N/A                                                        \n
*******************************************************************************/
#if(CanIf_u8NUM_OF_TRCV_DRVS !=0||CanIf_bDEV_ERR_DETECT==STD_ON)
FUNC(void, CANIF_CODE)CanIf_vidLocalTrcvModeIndic(
    VAR(uint8, AUTOMATIC) TransceiverId,
    VAR(CanTrcv_TrcvModeType, AUTOMATIC) TransceiverMode,
    VAR(uint8, AUTOMATIC) CanTrcvDrvId)
{
#if(CanIf_u8NUM_OF_TRCVS!=0)
    /*variable to be used in search                                           */
    VAR(uint8, AUTOMATIC)       u8SearchIndex;
    /*boolean to indicate that transceiver found or not                       */
    VAR(boolean, AUTOMATIC)     bTranceiverFound=FALSE;
#endif
/*! If this API operation isnot supported (NUM_OF_TRANS = 0)                    
and it is requested, then the CanIf shall recognize                             
this error as development error with error code CANIF_E_NOK_NOSUPPORT.          
Because in that case this API isnot supported.                                */
/* \Trace_To CANIF-CDD-5092(0)                                                */
#if(CanIf_u8NUM_OF_TRCVS==0)
    CanIf_vidDET_REPORT_ERROR(CanIf_u8TRCVMODEINDIC_API,CANIF_E_NOK_NOSUPPORT);
#else
    /*! Check if CanIf isnot initialized                                      */
    /*!If the CanIf was not initialized before calling                          
    CanIf_ControllerModeIndication(),then the function                          
    CanIf_ControllerModeIndication()shall not execute state transition          
    notification                                                              */
    /* \Trace_To CANIF-CDD-0342(0)                                            */
    /* \Trace_To CANIF-CDD-0341(0)                                            */
    /* \Trace_To CANIF-CDD-5093(0)                                            */
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
/*! Check that CanIf CanIf_bDEV_ERR_DETECT is Enabled                         */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
        /*! Report error CanIf isnot initialized to Det                       */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8TRCVMODEINDIC_API,CANIF_E_UNINIT);
#endif
    }
    /* PRQA S 3356,3359,3201 ++                                               */
    /*MISRA Msg justification:  alwayes False ,only for protection            */
    else if(
        ((TransceiverMode!=CANTRCV_TRCVMODE_NORMAL)
        &&(TransceiverMode!=CANTRCV_TRCVMODE_SLEEP))
        &&(TransceiverMode!=CANTRCV_TRCVMODE_STANDBY)
        )
    {
        /*!Do nothing and odn't enter the normal Execution of the service     */
    }
    /*if any of the previous errors occured Transceiver mode request has not    
    been accepted.assign the return value to E_NOT_OK                         */
    else
    {
        /* PRQA S 3356,3359,3201 --                                           */
        /*! if non of previous errors detected resume                         */
        /*!search in CanIf_akstreCanTrcvPCCfg and CanIf_akstreTransLCfg for the 
        TransceiverId using the Transceiver input parameter and the CanTrcvDrvId
                                                                              */
        u8SearchIndex=0;
        while((u8SearchIndex<CanIf_u8NUM_OF_TRCVS)&&(bTranceiverFound==FALSE))
        {
            if((CanIf_akstreCanTrcvPCCfg[u8SearchIndex].u8TrcvDrvId
                ==CanTrcvDrvId)&&(CanIf_akstreTransLCfg[u8SearchIndex].
                u8TrcvIdRef==TransceiverId))
            {
                bTranceiverFound=TRUE;
                /*!if search found the specific TransceiverId                 */
                /*!If no upper layer modules are configured for state transition
                notifications using <User_TrcvModeIndication>(), no state       
                transition notification needs to be configured.               */
                /*!Call User_TrcvModeIndication if configured                 */
                if(CanIf_kstreDispatchLCfg.pfvidTrcvModeIndic!=NULL_PTR)
                {
                    /* \Trace_To CANIF-CDD-0104(0)                            */
                    /*!state transition notification to UL                    */
                    CanIf_kstreDispatchLCfg.pfvidTrcvModeIndic(u8SearchIndex,
                        TransceiverMode);
                }
            }
            u8SearchIndex++;
        }
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
        if(bTranceiverFound==FALSE)
        {
            /*!search didn't find the specific TransceiverId                  */
            /* \Trace_To CANIF-CDD-0340(0)                                    */
            /*! Check that CanIf CanIf_bDEV_ERR_DETECT is Enabled             */
            CanIf_vidDET_REPORT_ERROR(CanIf_u8TRCVMODEINDIC_API,
                CANIF_E_PARAM_TRCV);
        }
#endif
    }
#endif/*CanIf_u8NUM_OF_TRCVS==0                                               */
}
#endif/*CanIf_u8NUM_OF_TRCVS!=0||CanIf_bDEV_ERR_DETECT==STD_ON                */

/* \Trace_To CANIF-CDD-0553(0)												  */
#if ((CanIf_bPUBLIC_PN_SUPPORT == STD_ON)&&(CanIf_bWAKUP_SUPPORT == STD_ON))
/******************************************************************************/
/*!\Description :  This service indicates that the transceiver has cleared 
															the WufFlag.	  \n
    \param[in]     CanTrcvDrvId: transceiver driver that this Transceiver is 
                   assignedt to                                               \n
    \Range         0..CanIf_u8NUM_OF_TRCV_DRVS-1                              \n
    \param[in]     TransceiverId: CAN transceiver, which state has been           
                   transitioned.                                              \n
    \Range         0.. number oftransceivers assigned to that CanTrcvDrvId    \n
    \return        void                                                       \n
*******************************************************************************/
#if(CanIf_u8NUM_OF_TRCV_DRVS !=0||CanIf_bDEV_ERR_DETECT==STD_ON)
/* \Trace_To CANIF-CDD-0521(0)												  */
FUNC(void, CANIF_CODE)CanIf_vidLocClrWuFlagIndic(
    VAR(uint8, AUTOMATIC) TransceiverId,
    VAR(uint8, AUTOMATIC) CanTrcvDrvId)
{
#if(CanIf_u8NUM_OF_TRCVS!=0)
    /*variable to be used in search                                           */
    VAR(uint8, AUTOMATIC)       u8SearchIndex;
    /*boolean to indicate that transceiver found or not                       */
    VAR(boolean, AUTOMATIC)     bTranceiverFound=FALSE;
#endif
	/*! If this API operation isnot supported (NUM_OF_TRANS = 0)                    
	and it is requested, then the CanIf shall recognize                             
	this error as development error with error code CANIF_E_NOK_NOSUPPORT.          
	Because in that case this API isnot supported.                                */
#if(CanIf_u8NUM_OF_TRCVS==0)
    CanIf_vidDET_REPORT_ERROR(CanIf_u8CLRTRCVWUFINDIC_API,CANIF_E_NOK_NOSUPPORT);
#else
	/*! Check that CanIf CanIf_bDEV_ERR_DETECT is Enabled                         */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
		/* \Trace_To CANIF-SRS-0549(0),CANIF-CDD-5283(0)                          */
        /*! Report error CanIf isnot initialized to Det                       */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8CLRTRCVWUFINDIC_API,CANIF_E_UNINIT);

    }
    /*! Check if TransceiverId is out of range                                */
    else if(TransceiverId>=CanIf_u8NUM_OF_TRCVS)
    {		
	/* \Trace_To CANIF-CDD-0547(0)                                            */
        /*! Report Det that TransceiverId is out of range                     */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8CLRTRCVWUFINDIC_API,CANIF_E_PARAM_TRCV);
    }
    else
#endif /*(CanIf_bDEV_ERR_DETECT == STD_ON)*/
	{
        /*!search in CanIf_akstreCanTrcvPCCfg and CanIf_akstreTransLCfg for the 
        TransceiverId using the Transceiver input parameter and the CanTrcvDrvId
                                                                              */
        u8SearchIndex=0;
        while((u8SearchIndex<CanIf_u8NUM_OF_TRCVS)&&(bTranceiverFound==FALSE))
        {
            if((CanIf_akstreCanTrcvPCCfg[u8SearchIndex].u8TrcvDrvId
                ==CanTrcvDrvId)&&(CanIf_akstreTransLCfg[u8SearchIndex].
                u8TrcvIdRef==TransceiverId))
            {
                bTranceiverFound=TRUE;
                /*!if search found the specific TransceiverId                 */
                /*!If no upper layer modules are configured for state transition
                notifications using <User_ClearTrcvWufFlagIndication>(), no state       
                transition notification needs to be configured.               */
                /*!Call User_ClearTrcvWufFlagIndicationif configured          */
				/* \Trace_To CANIF-CDD-0517(0)                                */
                if(CanIf_kstreDispatchLCfg.pfvidClearTrcvWuFlagIndic!=NULL_PTR)
                {
                    /*!state transition notification to UL                    */
                    CanIf_kstreDispatchLCfg.pfvidClearTrcvWuFlagIndic(u8SearchIndex);
                }
            }
            u8SearchIndex++;
        }
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
        if(bTranceiverFound==FALSE)
        {
            /*!search didn't find the specific TransceiverId                  */
            /*! Check that CanIf CanIf_bDEV_ERR_DETECT is Enabled             */
            CanIf_vidDET_REPORT_ERROR(CanIf_u8CLRTRCVWUFINDIC_API,
                CANIF_E_PARAM_TRCV);
        }
#endif
	}
#endif
}
#endif/*CanIf_u8NUM_OF_TRCVS!=0||CanIf_bDEV_ERR_DETECT==STD_ON                */
#endif/*(CanIf_bPUBLIC_PN_SUPPORT == STD_ON)*/

/* \Trace_To CANIF-CDD-0561(0)												  */
#if ((CanIf_bPUBLIC_PN_SUPPORT == STD_ON)&&(CanIf_bWAKUP_SUPPORT == STD_ON))
/******************************************************************************/
/*!\Description :  Requests the CanIf module to check the Wake flag of the 
												designated CAN transceiver.	  \n
    \param[in]     CanTrcvDrvId: transceiver driver that this Transceiver is 
                   assignedt to                                               \n
    \Range         0..CanIf_u8NUM_OF_TRCV_DRVS-1                              \n
    \param[in]     TransceiverId: CAN transceiver, which state has been           
                   transitioned.                                              \n
    \Range         0.. number oftransceivers assigned to that CanTrcvDrvId    \n
    \return        void                                                       \n
*******************************************************************************/
#if(CanIf_u8NUM_OF_TRCV_DRVS !=0||CanIf_bDEV_ERR_DETECT==STD_ON)
/* \Trace_To CANIF-CDD-0522(0)												  */
FUNC(void, CANIF_CODE)CanIf_vidLocChkTrcvWFIndic(
    VAR(uint8, AUTOMATIC) TransceiverId,
    VAR(uint8, AUTOMATIC) CanTrcvDrvId)
{
#if(CanIf_u8NUM_OF_TRCVS!=0)
    /*variable to be used in search                                           */
    VAR(uint8, AUTOMATIC)       u8SearchIndex;
    /*boolean to indicate that transceiver found or not                       */
    VAR(boolean, AUTOMATIC)     bTranceiverFound=FALSE;
#endif
	/*! If this API operation isnot supported (NUM_OF_TRANS = 0)                    
	and it is requested, then the CanIf shall recognize                             
	this error as development error with error code CANIF_E_NOK_NOSUPPORT.          
	Because in that case this API isnot supported.                                */
#if(CanIf_u8NUM_OF_TRCVS==0)
    CanIf_vidDET_REPORT_ERROR(CanIf_u8CHKTRCVWUFINDIC_API,CANIF_E_NOK_NOSUPPORT);
#else
	/*! Check that CanIf CanIf_bDEV_ERR_DETECT is Enabled                         */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
		/* \Trace_To CANIF-CDD-5284(0)										  */
        /*! Report error CanIf isnot initialized to Det                       */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8CHKTRCVWUFINDIC_API,CANIF_E_UNINIT);

    }
    /*! Check if TransceiverId is out of range                                */
    else if(TransceiverId>=CanIf_u8NUM_OF_TRCVS)
    {
		/* \Trace_To CANIF-CDD-0555(0)										  */
        /*! Report Det that TransceiverId is out of range                     */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8CHKTRCVWUFINDIC_API,CANIF_E_PARAM_TRCV);
    }
    else
#endif /*(CanIf_bDEV_ERR_DETECT == STD_ON)*/
	{
        /*!search in CanIf_akstreCanTrcvPCCfg and CanIf_akstreTransLCfg for the 
        TransceiverId using the Transceiver input parameter and the CanTrcvDrvId
                                                                              */
        u8SearchIndex=0;
        while((u8SearchIndex<CanIf_u8NUM_OF_TRCVS)&&(bTranceiverFound==FALSE))
        {
            if((CanIf_akstreCanTrcvPCCfg[u8SearchIndex].u8TrcvDrvId
                ==CanTrcvDrvId)&&(CanIf_akstreTransLCfg[u8SearchIndex].
                u8TrcvIdRef==TransceiverId))
            {
                bTranceiverFound=TRUE;
                /*!if search found the specific TransceiverId                 */
                /*!If no upper layer modules are configured for state transition
                notifications using <User_CheckTrcvWufFlagIndication>(), no state       
                transition notification needs to be configured.               */
                /*!Call User_CheckTrcvWufFlagIndication if configured         */
				/* \Trace_To CANIF-CDD-0518(0)                                */
                if(CanIf_kstreDispatchLCfg.pfvidCheckTrcvWuFlagIndic!=NULL_PTR)
                {
                    /*!state transition notification to UL                    */
                    CanIf_kstreDispatchLCfg.pfvidCheckTrcvWuFlagIndic
																(u8SearchIndex);
                }
            }
            u8SearchIndex++;
        }
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
        if(bTranceiverFound==FALSE)
        {
            /*!search didn't find the specific TransceiverId                  */
            /*! Check that CanIf CanIf_bDEV_ERR_DETECT is Enabled             */
            CanIf_vidDET_REPORT_ERROR(CanIf_u8CHKTRCVWUFINDIC_API,
                CANIF_E_PARAM_TRCV);
        }
#endif
	}
#endif
}
#endif/*CanIf_u8NUM_OF_TRCVS!=0||CanIf_bDEV_ERR_DETECT==STD_ON                */
#endif/*(CanIf_bPUBLIC_PN_SUPPORT == STD_ON)*/

/* \Trace_To CANIF-CDD-0516(0)												  */
#if((CanIf_bPUBLIC_PN_SUPPORT == STD_ON)&&(CanIf_bWAKUP_SUPPORT == STD_ON))
/******************************************************************************/
/*!\Description :  A call back service that indicates if the transceiver is 
					running in PN communication mode.						  \n
    \param[in]     TransceiverId: Abstracted CanIf TransceiverId,               
                   which is assigned to a CAN transceiver, which is requested   
                   for mode transition                                        \n
    \Range         0..CanIf_u8NUM_OF_TRCVS-1                                  \n
    \param[in]     TransceiverId: CAN transceiver, which state has been           
                   transitioned.                                              \n
    \Range         0.. number oftransceivers assigned to that CanTrcvDrvId    \n
    \return        void														  \n
*******************************************************************************/
/* \Trace_To CANIF-CDD-0564(0)												  */
#if(CanIf_u8NUM_OF_TRCV_DRVS !=0||CanIf_bDEV_ERR_DETECT==STD_ON)
FUNC(void, CANIF_CODE) CanIf_vidLocConfPnAvilable (
	VAR(uint8, AUTOMATIC)  TransceiverId,
	VAR(uint8, AUTOMATIC) CanTrcvDrvId)
{
#if(CanIf_u8NUM_OF_TRCVS!=0)
    /*variable to be used in search                                           */
    VAR(uint8, AUTOMATIC)       u8SearchIndex;
    /*boolean to indicate that transceiver found or not                       */
    VAR(boolean, AUTOMATIC)     bTranceiverFound=FALSE;
#endif
	/*! If this API operation isnot supported (NUM_OF_TRANS = 0)                    
	and it is requested, then the CanIf shall recognize                             
	this error as development error with error code CANIF_E_NOK_NOSUPPORT.          
	Because in that case this API isnot supported.                                */
#if(CanIf_u8NUM_OF_TRCVS == 0)
    CanIf_vidDET_REPORT_ERROR(CanIf_u8CONFPNAVAILABL_API,CANIF_E_NOK_NOSUPPORT);
#else

#if (CanIf_bDEV_ERR_DETECT == STD_ON)
    /*! Check if CanIf isnot initialized                                      */
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
		/* \Trace_To CANIF-CDD-5275(0)										*/
        /*! Report error CanIf isnot initialized to Det                       */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8CONFPNAVAILABL_API,CANIF_E_UNINIT);
    }
    /*! Check that TransceiverId not exceeding range of configured Transceivers 
        Ids                                                                   */
    /* \Trace_To CANIF-CDD-0567(0)											  */
    else if(TransceiverId>=CanIf_u8NUM_OF_TRCVS)
    {
        /*! Report error TransceiverId is exceeding range of Transceivers Ids*/
        CanIf_vidDET_REPORT_ERROR(CanIf_u8CONFPNAVAILABL_API,CANIF_E_PARAM_TRCV);
    }
	else
#endif
	{
        /*!search in CanIf_akstreCanTrcvPCCfg and CanIf_akstreTransLCfg for the 
        TransceiverId using the Transceiver input parameter and the CanTrcvDrvId
                                                                              */
        u8SearchIndex=0;
        while((u8SearchIndex<CanIf_u8NUM_OF_TRCVS)&&(bTranceiverFound==FALSE))
        {
            if((CanIf_akstreCanTrcvPCCfg[u8SearchIndex].u8TrcvDrvId
                ==CanTrcvDrvId)&&(CanIf_akstreTransLCfg[u8SearchIndex].
                u8TrcvIdRef==TransceiverId))
            {
                bTranceiverFound=TRUE;
                /*!if search found the specific TransceiverId                 */
                /*!If no upper layer modules are configured for state transition
                notifications using <User_ConfirmPnAvailability>(), no state       
                transition notification needs to be configured.               */
                /*!Call User_ConfirmPnAvailability if configured         */
				/* \Trace_To CANIF-CDD-0515(0)                                */
                if(CanIf_kstreDispatchLCfg.pfvidConfPnAvailability!=NULL_PTR)
                {
                    /*!state transition notification to UL                    */
                    CanIf_kstreDispatchLCfg.pfvidConfPnAvailability
																(u8SearchIndex);
                }
            }
            u8SearchIndex++;
        }
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
        if(bTranceiverFound==FALSE)
        {
            /*!search didn't find the specific TransceiverId                  */
            /*! Check that CanIf CanIf_bDEV_ERR_DETECT is Enabled             */
            CanIf_vidDET_REPORT_ERROR(CanIf_u8CONFPNAVAILABL_API,
                CANIF_E_PARAM_TRCV);
        }
#endif

	}
#endif
}
#endif/*CanIf_u8NUM_OF_TRCVS!=0||CanIf_bDEV_ERR_DETECT==STD_ON                */
#endif

/******************************************************************************/
/*!\Description : This service sets the requested mode at the                   
                   L-PDUs of a predefined logical PDU channel.                \n
    \param[in]     ControllerId: All PDUs of the own ECU connected to the       
                   corresponding CanIf ControllerId, which is assigned to       
                   a physical CAN controller are addressed.                   \n
    \Range         0..CanIf_ku8eNumOfControllers                              \n
    \param[in]     PduModeRequest: Requested PDU mode change                  \n
    \Range         (see CanIf_PduSetModeType)                                 \n
    \return        Request for mode transition has been accepted or not       \n
    \Range         E_OK, E_NOT_OK                                             \n
    \Trace_To CANIF-CDD-0243(0),CANIF-CDD-0510(0)                                                 
*******************************************************************************/
/* PRQA S 4700 ++ */
    /*MISRA Msg justification:  Cant be divided into more services (Switch case 
                                based service)                                */
FUNC(Std_ReturnType, CANIF_CODE)CanIf_SetPduMode(
    VAR(uint8, AUTOMATIC) ControllerId,
    VAR(CanIf_PduSetModeType, AUTOMATIC) PduModeRequest)
{
    /*return of the service                                                   */
    VAR(Std_ReturnType, AUTOMATIC)       udtResult=E_NOT_OK;
    /*local copy for the current pdu channel mode                             */
    VAR(CanIf_tstrPduMode, AUTOMATIC)    udtLocalPduMode;
    /* Check that CanIf CanIf_bDEV_ERR_DETECT is Enabled                      */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
    /* \Trace_To CANIF-CDD-0245(0)                                            */
    /* \Trace_To CANIF-CDD-5050(0)                                            */
    /*! Check if CanIf isnot initialized                                      */
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
        /*! Report error CanIf isnot initialized to Det                       */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8SETPDUMODE_API, CANIF_E_UNINIT);
    }
    /* \Trace_To CANIF-CDD-0244(0)                                            */
    /*! Check that ControllerId not exceeding range of configured Controllers   
        Ids                                                                   */
    else if(ControllerId>=CanIf_ku8eNumOfControllers)
    {
        /*! Report error ControllerId is exceeding range of configured 
            Controllers Ids                                                   */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8SETPDUMODE_API,
            CANIF_E_PARAM_CONTROLLERID);
    }
    else
#endif
    {
        /*! if requested Pdu mode is CANIF_SET_OFFLINE or CANIF_SET_TX_OFFLINE  
        Clear All Transmit buffers                                            */
        /* \Trace_To CANIF-CDD-5012(0)                                        */
        /* \Trace_To CANIF-CDD-5017(0)                                        */
#if(CanIf_bTX_BUFFERING==STD_ON)
        if((PduModeRequest == CANIF_SET_OFFLINE)
            ||(PduModeRequest == CANIF_SET_TX_OFFLINE))
        {
            /*!Clear All Transmit buffers                                     */
            CanIf_vidClearTransmitBuffers(ControllerId);
        }
        else
        {
            /*!Do Nothing                                                     */
        }
#endif
        /*! Copy Global CanIf_astreCurrPduChannelMode to Local Pdu Mode of      
        required ControllerId                                                 */
        udtLocalPduMode.enuRxPath=CanIf_astreCurrPduChannelMode[ControllerId]
        .enuRxPath;
        udtLocalPduMode.enuTxPath=CanIf_astreCurrPduChannelMode[ControllerId]
        .enuTxPath;
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
		udtLocalPduMode.bPnTxfilter=CanIf_astreCurrPduChannelMode[ControllerId]
		.bPnTxfilter;
#endif
        /*! handle the requested mode                                         */
        switch (PduModeRequest)
        {
            /*!Case CANIF_SET_OFFLINE Disable Rx and Tx Path                  */
        case CANIF_SET_OFFLINE:
            {
                udtLocalPduMode.enuRxPath=CanIf_RX_PATH_OFFLINE;
                udtLocalPduMode.enuTxPath=CanIf_TX_PATH_OFFLINE;
                udtResult = E_OK;
            }
            break;
            /*!Case CANIF_SET_TX_OFFLINE Disable Tx Path                      */
        case CANIF_SET_TX_OFFLINE:
            {
                udtLocalPduMode.enuTxPath=CanIf_TX_PATH_OFFLINE;
                udtResult = E_OK;
            }
            break;
            /*!Case CANIF_SET_RX_OFFLINE Disable Rx Path                      */
        case CANIF_SET_RX_OFFLINE:
            {
                udtLocalPduMode.enuRxPath=CanIf_RX_PATH_OFFLINE;
                udtResult = E_OK;
            }
            break;
            /*!Case CANIF_SET_RX_ONLINE Enable Rx Path                        */
        case CANIF_SET_RX_ONLINE:
            {
                udtLocalPduMode.enuRxPath=CanIf_RX_PATH_ONLINE;
                udtResult = E_OK;
            }
            break;
            /*!Case CANIF_SET_TX_ONLINE Enable Tx Path                        */
        case CANIF_SET_TX_ONLINE:
            {
                udtLocalPduMode.enuTxPath=CanIf_TX_PATH_ONLINE;
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
				udtLocalPduMode.bPnTxfilter=TRUE;
#endif
                udtResult = E_OK;
            }
            break;
            /*!Case CANIF_SET_TX_OFFLINE_ACTIVE set Tx Path to OFFLINE ACTIVE */
        case CANIF_SET_TX_OFFLINE_ACTIVE:
            {
                udtLocalPduMode.enuTxPath=CanIf_TX_PATH_OFF_ACTIVE;
                udtResult = E_OK;
            }
            break;
            /*!Case CANIF_SET_ONLINE Enable Rx and Tx Path                    */
        case CANIF_SET_ONLINE:
            {
                udtLocalPduMode.enuRxPath=CanIf_RX_PATH_ONLINE;
                udtLocalPduMode.enuTxPath=CanIf_TX_PATH_ONLINE;
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
				udtLocalPduMode.bPnTxfilter=TRUE;
#endif
                udtResult = E_OK;
            }
            break;
        /*!default*/
        /* PRQA S 2018 ++                                                     */
        /*MISRA Msg justification:  Just for protection againest invalid        
        values                                                                */
        default:
            /*! Do nothing bad PduModeRequest                                 */
            break;
        /* PRQA S 2018 --                                                     */
        }
        SchM_Enter_CanIf_PduChnlMod_09();
        /*! Copy Local Pdu Mode to the Global                                   
            CanIf_astreCurrPduChannelMode of required ControllerId            */
        CanIf_astreCurrPduChannelMode[ControllerId].enuRxPath=udtLocalPduMode
            .enuRxPath;
        CanIf_astreCurrPduChannelMode[ControllerId].enuTxPath=udtLocalPduMode
            .enuTxPath;
    /* \Trace_To CANIF-CDD-0508(0)						*/
#if (CanIf_bPUBLIC_PN_SUPPORT==STD_ON)
		if (CanIf_udtGET_CTRL_PBCFG[ControllerId].bPnFilterIsEffective == TRUE)
		{
			CanIf_astreCurrPduChannelMode[ControllerId].bPnTxfilter=
											udtLocalPduMode.bPnTxfilter;
		}
#endif
        SchM_Exit_CanIf_PduChnlMod_09();
    }
    return(udtResult);
}
    /* PRQA S 4700-- */
    /*MISRA Msg justification:  Cant be divided into more services (Switch case 
                                based service)                                */
/******************************************************************************/
/*!\Description : This service reports the current mode of                      
                   a requested PDU channel.                                   \n
    \param[in]     ControllerId: All PDUs of the own ECU connected to the       
                   corresponding CanIf ControllerId, which is assigned to       
                   a physical CAN controller are addressed.                   \n
    \Range         0..CanIf_ku8eNumOfControllers                              \n
    \param[out]     PduModePtr:Pointer to a memory location, where the current 
                   mode of the logical PDU channel will be stored.            \n
    \Range         Not NULL                                                   \n
    \return        mode request has been accepted or not                      \n
    \Range         E_OK, E_NOT_OK                                             \n
    \Trace_To CANIF-CDD-0247(0)                                                 
*******************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE)CanIf_GetPduMode(
    VAR(uint8, AUTOMATIC) ControllerId,
    P2VAR(CanIf_PduGetModeType,AUTOMATIC,CANIF_APPL_DATA) PduModePtr)
{
    /*Local Copy of Pdu mode , the to be stored in PduModePtr                 */
    VAR(CanIf_PduGetModeType, AUTOMATIC) udtLocalPduMode;
    /*local copy of Current channel mode                                      */
    VAR(CanIf_tstrPduMode, AUTOMATIC)    udtLocalTxRxPathPdu;
    /*the return of the service                                               */
    VAR(Std_ReturnType, AUTOMATIC)       udtResult=E_NOT_OK;
    /* Check that CanIf CanIf_bDEV_ERR_DETECT is Enabled                      */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
    /* \Trace_To CANIF-CDD-0250(0)                                            */
    /* \Trace_To CANIF-CDD-5052(0)                                            */
    /*! Check if CanIf isnot initialized                                      */
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
        /*! Report error CanIf isnot initialized to Det                       */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8GETPDUMODE_API, CANIF_E_UNINIT);
    }
    /* \Trace_To CANIF-CDD-0248(0)                                            */
    /*! Check that ControllerId not exceeding range of configured Controllers   
        Ids                                                                   */
    else if(ControllerId>=CanIf_ku8eNumOfControllers)
    {
        /*! Report error ControllerId is exceeding range of configured          
        Controllers Ids                                                       */
        CanIf_vidDET_REPORT_ERROR(
            CanIf_u8GETPDUMODE_API,
            CANIF_E_PARAM_CONTROLLERID);
    }
    /* \Trace_To CANIF-CDD-0249(0)                                            */
    /*! Check that ControPduModePtr isnot NULL                                */
    else if(PduModePtr==NULL_PTR)
    {
        /*! Report error ControPduModePtr is NULL                             */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8GETPDUMODE_API,
            CANIF_E_PARAM_POINTER);
    }
    else
#endif
    {
        SchM_Enter_CanIf_PduChnlMod_0a();
        /*! Copy Global CanIf_astreCurrPduChannelMode Pdu Mode to the local     
        Pdu Channel of required ControllerId                                  */
        udtLocalTxRxPathPdu.enuRxPath=CanIf_astreCurrPduChannelMode
            [ControllerId].enuRxPath;
        udtLocalTxRxPathPdu.enuTxPath=CanIf_astreCurrPduChannelMode
            [ControllerId].enuTxPath;
        SchM_Exit_CanIf_PduChnlMod_0a();
        switch (udtLocalTxRxPathPdu.enuTxPath)
        {
            /*!Case Tx Path CanIf_TX_PATH_ONLINE                              */
        case CanIf_TX_PATH_ONLINE:
            {
                /*!if Rx Path is Online                                       */
                if(udtLocalTxRxPathPdu.enuRxPath==CanIf_RX_PATH_ONLINE)
                {
                    /*!Current Channel Mode is CANIF_GET_ONLINE               */
                    udtLocalPduMode=CANIF_GET_ONLINE;
                }
                /*!else*/
                else
                {
                    /*!Current Channel Mode is CANIF_GET_TX_ONLINE            */
                    udtLocalPduMode=CANIF_GET_TX_ONLINE;
                }
                udtResult=E_OK;
            }
            break;
            /*!Case Tx Path CanIf_TX_PATH_ONLINE                              */
        case CanIf_TX_PATH_OFFLINE:
            {
                /*!if Rx Path is Online*/
                if(udtLocalTxRxPathPdu.enuRxPath==CanIf_RX_PATH_ONLINE)
                {
                    /*!Current Channel Mode is CANIF_GET_RX_ONLINE            */
                    udtLocalPduMode=CANIF_GET_RX_ONLINE;
                }
                /*!else*/
                else
                {
                    /*!Current Channel Mode is CANIF_GET_OFFLINE              */
                    udtLocalPduMode=CANIF_GET_OFFLINE;
                }
                udtResult=E_OK;
            }
            break;
            /*!Case Tx Path CanIf_TX_PATH_ONLINE                              */
        case CanIf_TX_PATH_OFF_ACTIVE:
            {
                /*!if Rx Path is Online                                       */
                if(udtLocalTxRxPathPdu.enuRxPath==CanIf_RX_PATH_ONLINE)
                {
                    /*!Current Channel Mode is                                  
                    CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE                        */
                    udtLocalPduMode=CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE;
                }
                /*!else                                                       */
                else
                {
                    /*!Current Channel Mode is CANIF_GET_OFFLINE_ACTIVE       */
                    udtLocalPduMode=CANIF_GET_OFFLINE_ACTIVE;
                }
                udtResult=E_OK;
            }
            break;
/* PRQA S 2018 ++ */
    /*MISRA Msg justification:  this default is for protection                */
        default:
            /*!default*/
            /*!Do nothing bad Tx Mode PduModeRequest only for protection      */
            /*!Leave return Value E_NOT_OK                                    */
			udtLocalPduMode=CANIF_GET_ONLINE;
            break;
/* PRQA S 2018 -- */
        }
        /*!Copy Local Pdu Channel Mode to UL Pointer of                       */
        *(PduModePtr)=udtLocalPduMode;
    }
    return(udtResult);
}
#if((CanIf_u8NUM_OF_TRCV_DRVS !=0||CanIf_bDEV_ERR_DETECT==STD_ON)&&(CanIf_bWAKUP_SUPPORT == STD_ON))
/******************************************************************************/
/*!\Description : This function shall call CanTrcv_SetTrcvWakeupMode.        \n
    \param[in]     TransceiverId: Abstracted CanIf TransceiverId, which is      
                   assigned to a CAN transceiver, which is requested            
                   for wake up reason.                                        \n
    \Range         0..CanIf_u8NUM_OF_TRCVS                                    \n
    \param[in]     TrcvWakeupMode:Requested transceiver wake up notification    
                   mode                                                       \n
    \Range         CANTRCV_WUMODE_CLEAR, CANTRCV_WUMODE_DISABLE,                
                   CANTRCV_WUMODE_ENABLE                                      \n
    \return        E_OK: Will be returned, if the wake up notifications state   
                   has been changed to the requested mode.                      
                   E_NOT_OK Will be returned, if the wake up notifications      
                   state change has failed or the parameter is out of           
                   the allowed range. The previous state has not been changed.\n
    \Range         E_OK, E_NOT_OK                                             \n
    \Trace_To CANIF-CDD-0281(0)                                                 
*******************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE)CanIf_SetTrcvWakeupMode(
    VAR(uint8, AUTOMATIC) TransceiverId,
    VAR(CanTrcv_TrcvWakeupModeType, AUTOMATIC) TrcvWakeupMode)
{
/* PRQA S 3197 ++ */
/* MISRA Msg justification:  The variable must be initialized with a default
                             value to handle some cases where it will not be
							 updated later (under certain pre-processor
							 configuration parameters)                        */	
    /*the retuen of the service                                               */
    VAR(Std_ReturnType, AUTOMATIC) udtResult=E_NOT_OK;
/*! If this API operation isnot supported (NUM_OF_TRANS = 0)and it is requested,
then the CanIf shall recognize this error as development error with error code  
CANIF_E_NOK_NOSUPPORT.Because in that case this API isnot supported.          */
   /* \Trace_To CANIF-CDD-5218(0)*/
#if(CanIf_u8NUM_OF_TRCVS==0)
    CanIf_vidDET_REPORT_ERROR(CanIf_u8SETTRCVWPMODE_API,CANIF_E_NOK_NOSUPPORT);
#else
/*! Check that CanIf CanIf_bDEV_ERR_DETECT is Enabled                         */
/* \Trace_To CANIF-CDD-0283(0)                                                */
/* \Trace_To CANIF-CDD-5064(0)                                                */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
    /*! Check if CanIf isnot initialized                                      */
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
        /*! Report error CanIf isnot initialized to Det                       */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8SETTRCVWPMODE_API,CANIF_E_UNINIT);
    }
    /*! Check that TransceiverId not exceeding range of configured Transceivers 
        Ids                                                                   */
    /* \Trace_To CANIF-CDD-0284(0)                                            */
    else if(TransceiverId>=CanIf_u8NUM_OF_TRCVS)
    {
        /*! Report error TransceiverId is exceeding range of Transceivers Ids*/
        CanIf_vidDET_REPORT_ERROR(CanIf_u8SETTRCVWPMODE_API,CANIF_E_PARAM_TRCV);
    }
    /*! check the upper layer requested mode transition is valid              */
    /* \Trace_To CANIF-CDD-0285(0)                                            */
    /* PRQA S 3356,3359,3201 ++ */
    /*MISRA Msg justification:  alwayes False ,only for protection            */
    else if((TrcvWakeupMode != CANTRCV_WUMODE_CLEAR)
                &&(TrcvWakeupMode != CANTRCV_WUMODE_DISABLE)
                &&(TrcvWakeupMode != CANTRCV_WUMODE_ENABLE))
    {
    /* PRQA S 3356,3359,3201 -- */
        /*report that upper layer requested mode transition is invalid        */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8SETTRCVWPMODE_API,
            CANIF_E_PARAM_TRCVWAKEUPMODE);
    }
    else
#endif
    {
        /* \Trace_To CANIF-CDD-0282(0)                                        */
        /*! The function CanIf_SetTrcvWakeupMode() shall call                   
        CanTrcv_SetWakeupMode(Transceiver, TrcvWakeupMode) on the corresponding 
        requested CanTrcv                                                     */
        /*! E_OK: Will be returned, if the wake up notifications state has been 
        changed to the requested mode.                                        */
        /*! E_NOT_OK returned, if the wake up notifications state change        
        has failed or the parameter is out of the allowed range. The            
        previous state has not been changed.                                  */
        udtResult = CanIf_akstreCanTrcvSrvcsPCCfg[CanIf_akstreCanTrcvPCCfg
            [TransceiverId].u8TrcvDrvId].
            pfu8SetWakeupMode(CanIf_akstreTransLCfg
            [TransceiverId].u8TrcvIdRef,TrcvWakeupMode);
        if(udtResult==E_OK)
        {
            /*! leave udtResult=E_OK                                          */
        }
        else
        {
            udtResult=E_NOT_OK;
        }
    }
#endif/*CanIf_u8NUM_OF_TRCVS==0*/
    return(udtResult);
/* PRQA S 3197 -- */
}
#endif/*CanIf_u8NUM_OF_TRCVS!=0||CanIf_bDEV_ERR_DETECT==STD_ON*/

#if((CanIf_u8NUM_OF_TRCV_DRVS !=0||CanIf_bDEV_ERR_DETECT==STD_ON)&&(CanIf_bWAKUP_SUPPORT == STD_ON))
/******************************************************************************/
/*!\Description : This service calls the corresponding CAN Driver service for   
                   changing of the CAN controller mode.                       \n
    \param[in]     TransceiverId: Abstracted CanIf TransceiverId, which is      
                   assigned to a CAN transceiver, which is requested            
                   for wake up reason.                                        \n
    \Range         0..CanIf_u8NUM_OF_TRCVS                                    \n
    \param[out]     TrcvWuReasonPtr:provided pointer to where the requested     
                   transceiver wake up reason shall be returned               \n
    \Range         Not NULL                                                   \n
    \return        Transceiver wake up reason request has been accepted.        
                   or not                                                     \n
    \Range         E_OK, E_NOT_OK                                             \n
    \Trace_To CANIF-CDD-0275(0)                                                 
*******************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE)CanIf_GetTrcvWakeupReason(
    VAR(uint8, AUTOMATIC) TransceiverId,
    P2VAR(CanTrcv_TrcvWakeupReasonType,AUTOMATIC,CANIF_APPL_DATA)
    TrcvWuReasonPtr)
{
/* PRQA S 3197 ++ */
/* MISRA Msg justification:  The variable must be initialized with a default
                             value to handle some cases where it will not be
							 updated later (under certain pre-processor
							 configuration parameters)                        */	

    /*the return of the service                                               */
    VAR(Std_ReturnType, AUTOMATIC) udtResult=E_NOT_OK;
/*! If this API operation isnot supported (NUM_OF_TRANS = 0)and it is requested,
then the CanIf shall recognize this error as development error with error code  
CANIF_E_NOK_NOSUPPORT.Because in that case this API isnot supported.          */
   /* \Trace_To CANIF-CDD-5217(0)                                             */
#if(CanIf_u8NUM_OF_TRCVS==0)
    CanIf_vidDET_REPORT_ERROR(CanIf_u8TRCVWPREASON_API,CANIF_E_NOK_NOSUPPORT);
#else
/*! Check that CanIf CanIf_bDEV_ERR_DETECT is Enabled                         */
   /* \Trace_To CANIF-CDD-0279(0)                                             */
   /* \Trace_To CANIF-CDD-5062(0)                                             */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
    /*! Check if CanIf isnot initialized                                      */
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
        /*! Report error CanIf isnot initialized to Det                       */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8TRCVWPREASON_API,CANIF_E_UNINIT);
    }
    /* \Trace_To CANIF-CDD-0277(0)                                            */
    /*! Check if TransceiverId is out of range                                */
    else if(TransceiverId>=CanIf_u8NUM_OF_TRCVS)
    {
        /*! Report Det that TransceiverId is out of range                     */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8TRCVWPREASON_API,CANIF_E_PARAM_TRCV);
    }
    /* \Trace_To CANIF-CDD-0278(0)                                            */
    /*! Check if TrcvWuReasonPtr is NULL                                      */
    else if(TrcvWuReasonPtr==NULL_PTR)
    {
    /*! Report Det that TrcvWuReasonPtr is NULL                               */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8TRCVWPREASON_API,
            CANIF_E_PARAM_POINTER);
    }
    else
#endif
    {
        /*! call CanTrcv_GetBusWuReason(Transceiver, Reason) on the             
        corresponding requested CanTrcv.                                      */
        /*! E_OK: Transceiver wake up reason request has been accepted.       */
        /*! E_NOT_OK: Transceiver wake up reason request has not been accepted*/
        /* \Trace_To CANIF-CDD-0276(0)                                        */
        udtResult = CanIf_akstreCanTrcvSrvcsPCCfg[CanIf_akstreCanTrcvPCCfg
            [TransceiverId].u8TrcvDrvId].pfu8GetBusWuReason
            (CanIf_akstreTransLCfg[TransceiverId].u8TrcvIdRef,
            TrcvWuReasonPtr);
        if(udtResult==E_OK)
        {
            /*! leave udtResult=E_OK                                          */
        }
        else
        {
            udtResult=E_NOT_OK;
        }
    }
#endif/*CanIf_u8NUM_OF_TRCVS==0                                               */
    return(udtResult);
}
/* PRQA S 3197 -- */
#endif/*CanIf_u8NUM_OF_TRCVS!=0||CanIf_bDEV_ERR_DETECT==STD_ON                */

/******************************************************************************/
/*!\Description : This service indicates a Controller BusOff event              
                  referring to the corresponding CAN Controller.              \n
    \param[in]     CanDrvId: the driver Id that this  Controller                
                   mode indication requested from                             \n
    \Range         0..CanIf_u8NUM_OF_CAN_DRVS-1                               \n
    \param[in]     Controller:  CAN controller, which state has been            
                   transitioned.                                              \n
    \Range         Maximum Number of Controlers assigned to that CanDrvId     \n
    \return        void                                                       \n
    \Range         N/A                                                        \n
*******************************************************************************/
/* PRQA S 4700 ++ */
/*MISRA Msg justification: ISR,time is critical                               */
FUNC(void, CANIF_CODE)CanIf_vidLocalCntrlBusOff(
     VAR(uint8, AUTOMATIC) Controller,
	 VAR(uint8, AUTOMATIC) CanDrvId)
{
    /*local variable to be use in search                                      */
    VAR(uint8, AUTOMATIC)   u8SearchIndex;
    /*the Abstracted Controller Id                                            */
    VAR(uint8, AUTOMATIC)   u8ControllerId;
    /*boolean to indicate that controller fund or not                         */
    VAR(boolean, AUTOMATIC) bControllerFound=FALSE;
/* \Trace_To CANIF-CDD-0329(0)                                                */
/* \Trace_To CANIF-CDD-0330(0)                                                */
/* \Trace_To CANIF-CDD-5088(0)                                                */
/*! Check that CanIf isnot initialized                                        */
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
/*! Check that CanIf CanIf_bDEV_ERR_DETECT is Enabled                         */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
        /*! Report that CanIf isnot initialized                               */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8CTRLBUSOFF_API, CANIF_E_UNINIT);
#endif
    }
    else
    {
        /*! Search for u8ControllerId using CanDrvId and Controller           */
        u8SearchIndex=0;
        while((u8SearchIndex<CanIf_ku8eNumOfControllers)
            &&(bControllerFound==FALSE))
        {
            /*! if u8ControllerId found                                       */
            if((CanIf_akstreCtrlLCfg[u8SearchIndex].u8CtrlIdRef==Controller)&&
                (CanIf_akstreCtrlLCfg[u8SearchIndex].u8CanDrvId==CanDrvId))
            {
                u8ControllerId = u8SearchIndex;
                /*! Change the Controller mode for found u8ControllerId to      
                be CANIF_CS_STOPPED                                           */
                /* \Trace_To CANIF-CDD-0072(0)                                */
                /* \Trace_To CANIF-CDD-0096(0)                                */
                SchM_Enter_CanIf_CurrConMode_16();
                CanIf_aenueCurrControllerMode[u8ControllerId]= CANIF_CS_STOPPED;
                SchM_Exit_CanIf_CurrConMode_16();
                bControllerFound=TRUE;
                /*! If CANIF_PUBLIC_TXCONFIRM_POLLING_SUPPORT is enabled, the   
                CanIf shall clear the information about a TxConfirmation      */
                /* \Trace_To CANIF-CDD-0101(0)                                */
#if (CanIf_bTXCONF_POLL_SUPPORT == STD_ON)
                /*Clear TxConfirmation for that controller                    */
                SchM_Enter_CanIf_TxConfStat_16();
                CanIf_vidClearTxConfirmState(u8ControllerId);
                SchM_Exit_CanIf_TxConfStat_16();
#endif    
#if(CanIf_bTX_BUFFERING==STD_ON)
                /* \Trace_To CANIF-CDD-5258(0)                                */
                /*!Clear All Transnmit buffers                                */
                CanIf_vidClearTransmitBuffers(u8ControllerId);
#endif
                /*! CanIf shall clear all temporarily stored wakeup events      
                corresponding to that state machine. Because it is considered   
                as explicit transition from CANIF_CS_INIT to CANIF_CS_INIT.   */
                /* \Trace_To CANIF-CDD-5219(0)                                */
#if ((CanIf_bWAKUP_CHK_VALID_API == STD_ON)&&(CanIf_bWAKUP_SUPPORT == STD_ON))
                if(CanIf_akstreCtrlLCfg[u8SearchIndex].bWakeupSupport==STD_ON)
                {
                    SchM_Enter_CanIf_CtrlWakeup_16();
                    CanIf_astreCtrlWakeup[CanIf_akstreCtrlLCfg[u8SearchIndex].
                        u8WkupEventIndex].bWakeupEvent=E_NOT_OK;
                    CanIf_astreCtrlWakeup[CanIf_akstreCtrlLCfg[u8SearchIndex].
                        u8WkupEventIndex].bWakeupValidation=E_NOT_OK;
                    SchM_Exit_CanIf_CtrlWakeup_16();
                }
#endif
                /*! Notify uper layer if configured,Call User_ControllerBusOff*/
                /* \Trace_To CANIF-CDD-0102(0)                                */
                if(CanIf_kstreDispatchLCfg.pfvidControllerBusOff!=NULL_PTR)
                {
                    CanIf_kstreDispatchLCfg.pfvidControllerBusOff
                        (u8ControllerId);
                }
            }
            u8SearchIndex++;
        }
        if(bControllerFound==FALSE)
        {
            /*!case that u8ControllerId not found after searching             */
            /* \Trace_To CANIF-CDD-0328(0)                                    */
            /*! Check that CanIf CanIf_bDEV_ERR_DETECT is Enabled             */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
            /*! report that Controller not found                              */
            CanIf_vidDET_REPORT_ERROR(CanIf_u8CTRLBUSOFF_API,
                CANIF_E_PARAM_CONTROLLER);
#endif
        }
    }
}
/* PRQA S 4700 -- */
/******************************************************************************/
/*!\Description : This service checks, whether an underlying CAN                
                   driver or a CAN transceiver driver already signals           
                   a wakeup event.                                            \n
    \param[in]     WakeupSource: Source device, which initiated the wake        
                   up event: CAN controller or CAN transceiver                \n
    \Range         0..31                                                      \n
    \return        Will be returned, if the check wake up request has           
                   been accepted or not                                       \n
    \Range         E_OK, E_NOT_OK                                             \n
    \Trace_To CANIF-CDD-0287(0)                                                 
*******************************************************************************/
/* PRQA S 4700 ++ */
    /*MISRA Msg justification:  Cant be divided into more services            */
#if (CanIf_bWAKUP_SUPPORT == STD_ON)
FUNC(Std_ReturnType, CANIF_CODE)CanIf_CheckWakeup(
    VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource)
{

    /* \Trace_To CANIF-CDD-0110(0)                                            */
    /*the return of the service                                               */
    VAR(Std_ReturnType, AUTOMATIC)              udtResult=E_NOT_OK;
    /*boolean to indicate that Controller not in sleep mode found             */
    VAR(uint8, AUTOMATIC)                       u8SleepFleg=u8SLEEPFLAG_CLEARD;
    /*local variable to be used in search                                     */
    VAR(uint8_least, AUTOMATIC)                       u8SearchIndex;
    /*the parameter that setwakeuevent will be called with                    */
    VAR(EcuM_WakeupSourceType, AUTOMATIC)       udtWakeupSourceout=0;
    /*the result of check wakeup for controllers                              */
    VAR(Can_ReturnType, AUTOMATIC)              udtCtrlCheckWpResult;
#if(CanIf_bDEV_ERR_DETECT==STD_ON)
    /*Det Error OccuredFlag                                                   */
    VAR(boolean, AUTOMATIC)                     bDetErrorOccured=FALSE;
#endif
#if(CanIf_u8NUM_OF_TRCV_DRVS>0)
    /*!the result of check wakeup for transceivers                            */
    VAR(Std_ReturnType, AUTOMATIC)              udtTrcvCheckWpResult;
#endif
    /*!local copy for Current Controller mode                                 */
    VAR(CanIf_ControllerModeType, AUTOMATIC)    udtCurrControllerMode;
#if (CanIf_bDEV_ERR_DETECT == STD_ON)	
   /*!invalid WakeupSource Flag                                               */
    VAR(boolean, AUTOMATIC)                     bInvalidWakeupSource=TRUE;
#endif	
/*! Check that CanIf CanIf_bDEV_ERR_DETECT is Enabled                         */
/* \Trace_To CANIF-CDD-5068(0)                                                */
/* \Trace_To CANIF-CDD-0289(0)                                                */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
/*! Check that CanIf isnot initialized                                        */
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
        /*! Report that CanIf isnot initialized                               */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8CHECKWAKEUP_API,CANIF_E_UNINIT);
        bDetErrorOccured=TRUE;
    }
    /*!else                                                                   */
    else 
    {
        /*!Loop for all Controllers                                           */
        for(u8SearchIndex=0;u8SearchIndex<CanIf_ku8eNumOfControllers;
            u8SearchIndex++)
        {
            /*!if at least one Controller matches WakeupSource in parameter   */
            if ((((WakeupSource)&(CanIf_u32GET_WKS_BIT(CanIf_akstreCtrlLCfg
                [u8SearchIndex].u8WakupSourceIn)))>0)&&(CanIf_akstreCtrlLCfg
                [u8SearchIndex].bWakeupSupport==STD_ON))
            {
                /*!WakeupSource is valid                                      */
                bInvalidWakeupSource=FALSE;
            }
            /*!else                                                           */
            else
            {
                /*!leave bInvalidWakeupSource=TRUE;                           */
            }
        }
#if(CanIf_u8NUM_OF_TRCV_DRVS>0)
        /*!Loop for all Transceivers                                          */
        for(u8SearchIndex=0;u8SearchIndex<CanIf_u8NUM_OF_TRCVS;
            u8SearchIndex++)
        {
            /*!if at least one Transceiver matches WakeupSource in parameter  */
            if ((((WakeupSource)&(CanIf_u32GET_WKS_BIT(CanIf_akstreCanTrcvPCCfg
                [u8SearchIndex].u8WakupSourceIn)))>0)&&(CanIf_akstreTransLCfg
                [u8SearchIndex].bWakeupSupport==STD_ON))
            {
                /*!WakeupSource is valid                                      */
                bInvalidWakeupSource=FALSE;
            }
            else
            {
                /*!leave bInvalidWakeupSource=TRUE;                           */
            }
        }
#endif
        /*!if WakeupSource is invalid                                         */
        if(bInvalidWakeupSource==TRUE)
        {
            /*! Report Invalid Wakeup Source                                  */
            /* \Trace_To CANIF-CDD-0288(0)                                    */
            CanIf_vidDET_REPORT_ERROR(CanIf_u8CHECKWAKEUP_API,
                CANIF_E_PARAM_WAKEUPSOURCE);
            bDetErrorOccured=TRUE;
        }
    }
    /*!if WakeupSource is invalid                                             */
    if(bDetErrorOccured==TRUE)
    {
        /*Do nothing                                                          */
    }
    /*!else                                                                   */
    else
#endif
    {
/**********************Controller Check Wakeup*********************************/
        /* \Trace_To CANIF-CDD-0106(0)                                        */
        /*! loop on all CanIf Controllers                                     */
        u8SearchIndex = 0;
        while((u8SearchIndex<CanIf_ku8eNumOfControllers)
            &&(u8SleepFleg==u8SLEEPFLAG_CLEARD))
        {
            /*! Check if Wakeup Support functionality is enabled for that       
                controller                                                    */
            if(CanIf_akstreCtrlLCfg[u8SearchIndex].bWakeupSupport
                ==STD_ON)
            {
                /*! The mapping of parameter WakeupSource of                    
                    CanIf_CheckWakeup()to the appropriate HW device (controller)
                    could be done via CANIF_CTRL_WAKEUP_SOURCE_IN_REF         */
                if ((WakeupSource&(CanIf_u32GET_WKS_BIT(CanIf_akstreCtrlLCfg
                    [u8SearchIndex].u8WakupSourceIn)))>0)
                {
                    /*! Check if the controller is in Sleep mode              */
                    /* \Trace_To CANIF-CDD-0111(0)                            */
                    /* \Trace_To CANIF-CDD-5066(0)                            */
                    /* \Trace_To CANIF-CDD-5067(0)                            */
                    SchM_Enter_CanIf_CurrConMode_11();
                    udtCurrControllerMode=CanIf_aenueCurrControllerMode
                        [u8SearchIndex];
                    SchM_Exit_CanIf_CurrConMode_11();
                    if(udtCurrControllerMode!=CANIF_CS_SLEEP)
                    {
                    /* \Trace_To CANIF-CDD-0111(0)                            */
                    /* \Trace_To CANIF-CDD-5066(0)                            */
                    /* \Trace_To CANIF-CDD-5067(0)                            */
                        /*raise the production error code CANIF_E_NOT_SLEEP   */
#if(CanIf_bDEM_ERR_DETECT == STD_ON)
                        Dem_ReportErrorStatus(CANIF_E_NOT_SLEEP,
                            DEM_EVENT_STATUS_FAILED);
#endif
                        /*! set u8SleepFleg to u8SLEEPFLAG_SET to break from    
                        Transceiver for loop                                  */
                        u8SleepFleg = u8SLEEPFLAG_SET;
                        /*! return E_NOT_OK.                                  */
                        /* \Trace_To CANIF-CDD-0111(0)                        */
                        udtResult = E_NOT_OK;
                        /*! set u8SearchIndex to CanIf_ku8eNumOfControllers to  
                        break from Transceiver for loop                       */
        /* PRQA S 2469 ++ */
        /*MISRA Msg justification: edit the Loop Control to save time and 
                                   exit for loop                              */
                        u8SearchIndex=CanIf_ku8eNumOfControllers;
        /* PRQA S 2469 -- */
                        /*! clear all detected Wakeupsources from               
                            udtWakeupSourceout                                */
                        udtWakeupSourceout = 0;
                    }
                    else
                    {
                        /*! Call Can_CheckWakeup for the current controller     
                            and assign the result to udtCtrlCheckWpResult     */
                        /* \Trace_To CANIF-CDD-0108(0)                        */
                        udtCtrlCheckWpResult=CanIf_akstreCanServicesPCCfg
                            [CanIf_akstreCtrlLCfg[u8SearchIndex].u8CanDrvId].
                            pfenuCheckWakeup(CanIf_akstreCtrlLCfg[u8SearchIndex]
                            .u8CtrlIdRef);
                        /* \Trace_To CANIF-CDD-0110(0)                        */
                        /* \Trace_To CANIF-CDD-0108(0)                        */
                        /*! check if the reurn of Can_CheckWakeup is E_OK     */
                        if(udtCtrlCheckWpResult==CAN_OK)
                        {
                            /* \Trace_To CANIF-CDD-0113(0)                    */
                            /* \Trace_To CANIF-CDD-0114(0)                    */
#if (CanIf_bWAKUP_CHK_VALID_API==STD_ON)
                            /*! Set Wakeup Event for that Controller          */
                            SchM_Enter_CanIf_CtrlWakeup_11();
                            CanIf_astreCtrlWakeup[CanIf_akstreCtrlLCfg
                                [u8SearchIndex].u8WkupEventIndex].bWakeupEvent
                                =E_OK;
                            SchM_Exit_CanIf_CtrlWakeup_11();
#endif                      
                            /* \Trace_To CANIF-CDD-0107(0)                    */
                            /*! The mapping of the specific HW devices          
                                (controller or transceiver), which detected     
                                the wake up, to the parameter sources of        
                                <User_SetWakeupEvent>()                         
                                done via CANIF_CTRL_WAKEUP_SOURCE_OUT_REF     */
                            udtWakeupSourceout|=
                                (CanIf_u32GET_WKS_BIT(CanIf_akstreCtrlLCfg
                                [u8SearchIndex].u8WakupSourceOut));
                            /*! at least on controller Wakeup detected          
                                return E_OK                                   */
                            /* \Trace_To CANIF-CDD-0109(0)                    */
                            udtResult = E_OK;
                        }
                        /* \Trace_To CANIF-CDD-0108(0)                        */
                            /*! u8CheckWakeupResult==CAN_NOT_OK               */
                            /*! Only bus wake up sources shall be reported via  
                            <User_SetWakeupEvent>(EcuM_WakeupSourceType sources)
                            .Thus Can_CheckWakeup() or CanTrcv_CheckWakeup()    
                            shall only return (CAN_OK / E_OK) if a wake up has  
                            been detected at the CAN bus. tehere for no CAN_BUSY
                            can be returned*/
                            /*! Do nothing                                    */
                    }
                }
            }
            u8SearchIndex++;
        }
#if(CanIf_u8NUM_OF_TRCV_DRVS !=0)
        /* \Trace_To CANIF-CDD-0106(0)                                        */
/**************************Transceiver Check Wakeup****************************/
        /*! check u8SleepFleg if it is u8SLEEPFLAG_SET to break from Transceiver
        for loop                                                              */
        if(u8SleepFleg == u8SLEEPFLAG_CLEARD)
        {
            u8SearchIndex=0;
            /*! loop on all CanIf transceivers                                */
            while(u8SearchIndex<CanIf_u8NUM_OF_TRCVS)
            {
                if(CanIf_akstreTransLCfg[u8SearchIndex].bWakeupSupport==STD_ON)
                {
                    /*! The mapping of parameter WakeupSource of                
                    CanIf_CheckWakeup()to the appropriate HW device             
                    (transceiver) done via CANIF_TRCV_WAKEUP_SOURCE_IN_REF    */
                    if (((WakeupSource)&(CanIf_u32GET_WKS_BIT
                        (CanIf_akstreCanTrcvPCCfg
                        [u8SearchIndex].u8WakupSourceIn)))>0)
                    {
                        /*! Call CanTrcv_CheckWakeup() for the current          
                        transceiver and assign the result to                    
                        udtTrcvCheckWpResult                                  */
                        /* \Trace_To CANIF-CDD-0108(0)                        */
                        udtTrcvCheckWpResult=
                            CanIf_akstreCanTrcvSrvcsPCCfg
                            [CanIf_akstreCanTrcvPCCfg[u8SearchIndex].
                            u8TrcvDrvId].pfu8CheckWakeup(CanIf_akstreTransLCfg
                            [u8SearchIndex].u8TrcvIdRef );
                        /*! check if the reurn of CanTrcv_CheckWakeup is E_OK */
                        /* \Trace_To CANIF-CDD-0108(0)                        */
                        /* \Trace_To CANIF-CDD-0110(0)                        */
                        if(udtTrcvCheckWpResult==CAN_OK)
                        {
                            /*! The mapping of the specific HW devices          
                            (controller or transceiver),which detected the      
                            wake up, to the parameter sources of                
                            <User_SetWakeupEvent>()done via                     
                            CANIF_CTRL_WAKEUP_SOURCE_OUT_REF                  */
                            /* \Trace_To CANIF-CDD-0107(0)                    */
                            udtWakeupSourceout|=
                                (CanIf_u32GET_WKS_BIT(CanIf_akstreCanTrcvPCCfg
                                [u8SearchIndex].u8WakupSourceOut));
                            /* \Trace_To CANIF-CDD-0109(0)                    */
                            udtResult = E_OK;
                        }
                        /* \Trace_To CANIF-CDD-0108(0)                        */
                            /*! u8CheckWakeupResult==CAN_NOT_OK               */
                            /*! Only bus wake up sources shall be reported via  
                            <User_SetWakeupEvent>(EcuM_WakeupSourceType         
                            sources).                                           
                            Thus Can_CheckWakeup() or CanTrcv_CheckWakeup()     
                            shall only return (CAN_OK / E_OK) if a wake up has  
                            been detected at the CAN bus. tehere for no         
                            CAN_BUSY can be returned                          */
                            /*Do nothing                                      */
                    }
                }
                u8SearchIndex++;
            }
        }
        else
        {
            /*! Do nothing udtResult already E_NOT_OK because one               
                investigated Controllers was in sleep mode                    */
        }
#endif/*(CanIf_u8NUM_OF_TRCVS!=0)                                             */
        /* \Trace_To CANIF-CDD-0107(0)                                        */
        /* \Trace_To CANIF-CDD-0110(0)*/
        /*! Call User_SetWakeupEvent if Configured                            */
        if(CanIf_kstreDispatchLCfg.pfvidSetWakeupEvent!=NULL_PTR)
        {
            CanIf_kstreDispatchLCfg.pfvidSetWakeupEvent(udtWakeupSourceout);
        }
    }
    /* \Trace_To CANIF-CDD-0110(0)                                            */
    return (udtResult);
}
#endif
/* PRQA S 4700 -- */
#if((CanIf_bWAKUP_CHK_VALID_API==STD_ON||CanIf_bDEV_ERR_DETECT==STD_ON)&&(CanIf_bWAKUP_SUPPORT == STD_ON))
/******************************************************************************/
/*!\Description : Service is performed to validate a previous wakeup event    \n
    \param[in]     WakeupSource: Source device which initiated the wake-up      
                   event and which has to be validated: CAN controller          
                   or CAN transceiver                                         \n
    \Range         0..31                                                      \n
    \return        Will be returned, if the check validation request has        
                   been accepted or not                                       \n
    \Range         E_OK, E_NOT_OK                                             \n
    \Trace_To CANIF-CDD-0292(0)                                                 
*******************************************************************************/
/* PRQA S 3206 ++ */
/* MISRA Msg justification: WakeupSource can't be removed from the function 
		declaration even if it was not used because it is an Autosar service*/
FUNC(Std_ReturnType, CANIF_CODE)CanIf_CheckValidation(
    VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource)
{
/* PRQA S 3206 -- */
/* PRQA S 3197 ++ */
/* MISRA Msg justification:  The variable must be initialized with a default
                             value to handle some cases where it will not be
							 updated later (under certain pre-processor
							 configuration parameters)                        */	
							 
    /*the return of the service                                               */
    VAR(Std_ReturnType, AUTOMATIC)          udtResult=E_NOT_OK;
#if(CanIf_bWAKUP_CHK_VALID_API==STD_ON)
    /*local variable to used in search                                        */
    VAR(uint8_least, AUTOMATIC)                   u8SearchIndex;
    /*local variable to be used in calling of Validare Wakeup Event service   */
    VAR(EcuM_WakeupSourceType, AUTOMATIC)   udtWakeupSourceout=0;
#if(CanIf_bDEV_ERR_DETECT==STD_ON)		
    /*invalid WakeupSource Flag*/
    VAR(boolean, AUTOMATIC)                 bInvalidWakeupSource=TRUE;
    /*!Det Error OccuredFlag                                                  */
    VAR(boolean, AUTOMATIC)                 bDetErrorOccured=FALSE;
#endif
#endif
/* \Trace_To CANIF-CDD-5070(0)                                                */
#if(CanIf_bWAKUP_CHK_VALID_API==STD_OFF)
    CanIf_vidDET_REPORT_ERROR(CanIf_u8CHECKVALIDWP_API,CANIF_E_NOK_NOSUPPORT);
#else
/*! Check that CanIf CanIf_bDEV_ERR_DETECT is Enabled                         */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
     /* \Trace_To CANIF-CDD-0294(0)                                           */
     /* \Trace_To CANIF-CDD-5071(0)                                           */
    /*! Check that CanIf isnot initialized                                    */
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
        /*! Report that CanIf isnot initialized                               */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8CHECKVALIDWP_API,CANIF_E_UNINIT);
        bDetErrorOccured=TRUE;
    }
    /*!else                                                                   */
    else 
    {
        /*!Loop for all controllers                                           */
        for(u8SearchIndex=0;u8SearchIndex<CanIf_ku8eNumOfControllers;
            u8SearchIndex++)
        {
            /*!if at least one Controllers Match with WakeupSource in           
            Parameter*/
            if ((((WakeupSource)&(CanIf_u32GET_WKS_BIT(CanIf_akstreCtrlLCfg
                [u8SearchIndex].u8WakupSourceIn)))>0)&&
                (CanIf_akstreCtrlLCfg[u8SearchIndex].bWakeupSupport==STD_ON))
            {
                /*!WakeupSource Input parameter is valid                      */
                bInvalidWakeupSource=FALSE;
            }
            /*!else                                                           */
            else
            {
                /*!leave bInvalidWakeupSource=TRUE;                           */
            }
        }
        /*!if WakeupSource Input parameter is invalid                         */
        if(bInvalidWakeupSource==TRUE)
        {
            bDetErrorOccured=TRUE;
            /*! Report Invalid Wakeup Source                                  */
            /* \Trace_To CANIF-CDD-0293(0)*/
            CanIf_vidDET_REPORT_ERROR(CanIf_u8CHECKVALIDWP_API,
                CANIF_E_PARAM_WAKEUPSOURCE);
        }
    }
    /*!if Det Error Occured                                                   */
    if(bDetErrorOccured==TRUE)
    {
        /*!Do nothing                                                         */
    }
    /*!else                                                                   */
    else
#endif
    {
        /*! loop for all Canif Controllers                                    */
        for(u8SearchIndex = 0;u8SearchIndex<
                        CanIf_ku8eNumOfControllers;u8SearchIndex++)
        {
            /*! check if the wakeup supported for that controller and Wakeup    
            Source in is what is required from WakeupSource input parametr    */
            if((CanIf_akstreCtrlLCfg[u8SearchIndex].bWakeupSupport
                ==STD_ON)&&(((WakeupSource)&(CanIf_u32GET_WKS_BIT
                (CanIf_akstreCtrlLCfg[u8SearchIndex].u8WakupSourceIn)))>0))
            {
                /* \Trace_To CANIF-CDD-0117(0)                                */
                /*!check if this wakeupsource is validated for that             
                   Controller                                                 */
                SchM_Enter_CanIf_CtrlWakeup_12();
                if(CanIf_astreCtrlWakeup[CanIf_akstreCtrlLCfg[u8SearchIndex].
                    u8WkupEventIndex].bWakeupValidation==E_OK)
                {
                    /* \Trace_To CANIF-CDD-0117(0)                            */
                    /*! set udtWakeupSourceout with validated wakeup source     
                        to be sent to upper lauer in the call of                
                        ValidateWakeupEvent()                                 */
                    udtWakeupSourceout|=
                        (CanIf_u32GET_WKS_BIT(CanIf_akstreCtrlLCfg
                        [u8SearchIndex].u8WakupSourceOut));
                        /* \Trace_To CANIF-CDD-0119(0)                        */
                    CanIf_astreCtrlWakeup[CanIf_akstreCtrlLCfg[u8SearchIndex]
                        .u8WkupEventIndex].bWakeupEvent=E_NOT_OK;
                    CanIf_astreCtrlWakeup[CanIf_akstreCtrlLCfg[u8SearchIndex]
                    .u8WkupEventIndex].bWakeupValidation=E_NOT_OK;
                    /*! return E_OK                                           */
                    udtResult = E_OK;
                }
                /*! if wakeup event isnot validated udtWakeupSourceout          
                    will still cleared for that source                        */
                /*! leave return result E_NOT_OK                              */
                /* \Trace_To CANIF-CDD-0118(0)                                */
                SchM_Exit_CanIf_CtrlWakeup_12();
            }
        }
        /*! call USER_ValidateWakeupEvent whereas sources is set to WakeupSource
        .and for wakeup sources validated and cleared for wakeup sources not    
        validated                                                             */
        /*!Call User_ValidateWakeupEvent if Configured                        */
        if(CanIf_kstreDispatchLCfg.pfvidValidWakeupEvent!=NULL_PTR)
        {
            CanIf_kstreDispatchLCfg.pfvidValidWakeupEvent(udtWakeupSourceout);
        }
    }
#endif/*CanIf_bWAKUP_CHK_VALID_API==STD_OFF                                   */
    return(udtResult);
}
/* PRQA S 3197 -- */
#endif/*CanIf_bWAKUP_CHK_VALID_API==STD_ON||CanIf_bDEV_ERR_DETECT==STD_ON     */

/* \Trace_To CANIF-CDD-0526(0),CANIF-CDD-0562(0)                       */

#if((CanIf_bPUBLIC_PN_SUPPORT == STD_ON)&&(CanIf_bWAKUP_SUPPORT == STD_ON))
/******************************************************************************/
/*!\Description :  Requests the CanIf module to check the Wake flag of the 
												designated CAN transceiver    \n
    \param[in]     TransceiverId: Abstracted CanIf TransceiverId,               
                   which is assigned to a CAN transceiver, which is requested   
                   for mode transition                                        \n
    \Range         0..CanIf_u8NUM_OF_TRCVS-1                                  \n
    \return        Controller mode request has been accepted or not           \n
    \Range         E_OK, E_NOT_OK											  \n
*******************************************************************************/
/* \Trace_To CANIF-CDD-0520(0)                        */
#if(CanIf_u8NUM_OF_TRCV_DRVS !=0||CanIf_bDEV_ERR_DETECT==STD_ON)
FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckTrcvWakeFlag (
	VAR(uint8, AUTOMATIC)  TransceiverId)
{
	VAR(Std_ReturnType, AUTOMATIC) udtResult;
	udtResult=E_NOT_OK;
	/*! If this API operation is not supported (NUM_OF_TRANS = 0)and it is requested,
	then the CanIf shall recognize this error as development error with error code  
	CANIF_E_NOK_NOSUPPORT.Because in that case this API isnot supported.          */
#if(CanIf_u8NUM_OF_TRCVS==0)
    CanIf_vidDET_REPORT_ERROR(CanIf_u8CHKTRCVWUFFLAG_API,CANIF_E_NOK_NOSUPPORT);
#else
	/*! Check that CanIf CanIf_bDEV_ERR_DETECT is Enabled                         */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
    /*! Check if CanIf is not initialized                                      */
	/* \Trace_To CANIF-CDD-5277(0)						                       */
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
        /*! Report error CanIf isnot initialized to Det                       */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8CHKTRCVWUFFLAG_API,CANIF_E_UNINIT);
    }
    /*! Check if TransceiverId is out of range                                */
	/* \Trace_To CANIF-CDD-0525(0)                        */
    else if(TransceiverId>=CanIf_u8NUM_OF_TRCVS)
    {
        /*! Report Det that TransceiverId is out of range                     */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8CHKTRCVWUFFLAG_API,CANIF_E_PARAM_TRCV);
    }
    else
#endif
    {
        /*! call CanTrCv_CheckTrcvWufFlag(Transceiver) on the corresponding 
					requested CanTrcv.                                      */
		/* \Trace_To CANIF-CDD-0523(0)                        */
        udtResult = CanIf_akstreCanTrcvSrvcsPCCfg[CanIf_akstreCanTrcvPCCfg
            [TransceiverId].u8TrcvDrvId].pfu8CheckTrcvWufFlag
            (CanIf_akstreTransLCfg[TransceiverId].u8TrcvIdRef);
        if(udtResult==E_OK)
        {
            /*! leave udtResult=E_OK                                          */
        }
        else
        {
            udtResult=E_NOT_OK;
        }
    }
#endif /*CanIf_u8NUM_OF_TRCVS==0 */
    return(udtResult);
}

/******************************************************************************/
/*!\Description :  Requests the CanIf module to clear the Wake flag of the 
												designated CAN transceiver    \n
    \param[in]     TransceiverId: Abstracted CanIf TransceiverId,               
                   which is assigned to a CAN transceiver, which is requested   
                   for mode transition                                        \n
    \Range         0..CanIf_u8NUM_OF_TRCVS-1                                  \n
    \return        Controller mode request has been accepted or not           \n
    \Range         E_OK, E_NOT_OK											  \n
*******************************************************************************/
/* \Trace_To CANIF-CDD-0519(0)                        */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_ClearTrcvWufFlag (
	VAR(uint8, AUTOMATIC)  TransceiverId)
{
	VAR(Std_ReturnType, AUTOMATIC) udtResult;
	udtResult=E_NOT_OK;
	/*! If this API operation is not supported (NUM_OF_TRANS = 0)and it is requested,
	then the CanIf shall recognize this error as development error with error code  
	CANIF_E_NOK_NOSUPPORT.Because in that case this API isnot supported.          */
#if(CanIf_u8NUM_OF_TRCVS==0)
    CanIf_vidDET_REPORT_ERROR(CanIf_u8CLRTRCVWUFFLAG_API,CANIF_E_NOK_NOSUPPORT);
#else
	/*! Check that CanIf CanIf_bDEV_ERR_DETECT is Enabled                         */
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
    /*! Check if CanIf is not initialized                                      */
	/* \Trace_To CANIF-CDD-5276(0)                      */
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
        /*! Report error CanIf isnot initialized to Det                       */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8CLRTRCVWUFFLAG_API,CANIF_E_UNINIT);
    }
/* \Trace_To CANIF-CDD-0581(0)                       */
    /*! Check if TransceiverId is out of range                                */
    else if(TransceiverId>=CanIf_u8NUM_OF_TRCVS)
    {
        /*! Report Det that TransceiverId is out of range                     */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8CLRTRCVWUFFLAG_API,CANIF_E_PARAM_TRCV);
    }
    else
#endif
    {
        /*! call CanTrCv_ClearTrcvWufFlag(Transceiver) on the corresponding 
					requested CanTrcv.                                      */
		/* \Trace_To CANIF-CDD-0524(0)										*/
        udtResult = CanIf_akstreCanTrcvSrvcsPCCfg[CanIf_akstreCanTrcvPCCfg
            [TransceiverId].u8TrcvDrvId].pfu8ClearTrcvWufFlag
            (CanIf_akstreTransLCfg[TransceiverId].u8TrcvIdRef);
        if(udtResult==E_OK)
        {
            /*! leave udtResult=E_OK                                          */
        }
        else
        {
            udtResult=E_NOT_OK;
        }
    }
#endif /*CanIf_u8NUM_OF_TRCVS==0 */
    return(udtResult);
}
#endif	/*(CanIf_u8NUM_OF_TRCV_DRVS !=0||CanIf_bDEV_ERR_DETECT==STD_ON)*/
#endif /* CanIf_bPUBLIC_PN_SUPPORT */


/******************************************************************************/
/*! \Description : This service shall check, if a certain CAN controller 
					supports a requested
					baudrate Please note that this API is deprecated and is 
					kept only for backward compatibility reasons. In the 
					next major release this API will be deleted.              \n
    \param[in]     ControllerId:  CAN Controller to check for the support 
								  of a certain baudrate                       \n
    \Range         0..CanIf_ku8eNumOfControllers-1                            \n
    \param[in]     Baudrate:  Baudrate to check in kbps		                  \n
    \Range														              \n
    \return														              \n
    \Range         E_OK, E_NOT_OK                                             \n
    \Trace_To CANIF-CDD-0667(0)                                              
*******************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE)CanIf_CheckBaudrate(
/* !Deviation : Inhibit MISRA rule [3206]: Parameter is not used because      */
/*             function is not implemented yet. The suppression is to be      */
/*                      removed when the function will be implemented         */
/* PRQA S 3206 ++                                                             */
    VAR(uint8, AUTOMATIC) ControllerId,
    CONST(uint16 ,AUTOMATIC)Baudrate)
/* PRQA S 3206 --                                                             */    
{
    /* the return of the service                                              */
    VAR(Std_ReturnType, AUTOMATIC)              udtResult=E_NOT_OK;
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
    /*! Check if CanIf is not initialized                                      */
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
        /*! Report error CanIf isnot initialized to Det                       */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8CHKBAUDRATE_API,CANIF_E_UNINIT);
    }
#endif    
	/*! return E_NOT_OK since this service is not supported in the current release*/
	return udtResult;
}

/******************************************************************************/
/*! \Description : This service shall change the baudrate of the CAN controller.
					Please note that this API is deprecated and is 
					kept only for backward compatibility reasons. In the 
					next major release this API will be deleted.              \n
    \param[in]     ControllerId:  CAN Controller to check for the support 
								  of a certain baudrate                       \n
    \Range         0..CanIf_ku8eNumOfControllers-1                            \n
    \param[in]     Baudrate:  Baudrate to check in kbps		                  \n
    \Range														              \n
    \return														              \n
    \Range         E_OK, E_NOT_OK                                             \n
    \Trace_To CANIF-CDD-0672(0)         
*******************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE)CanIf_ChangeBaudrate(
/* !Deviation : Inhibit MISRA rule [3206]: Parameter is not used because      */
/*             function is not implemented yet. The suppression is to be      */
/*                      removed when the function will be implemented         */
/* PRQA S 3206 ++                                                             */
    VAR(uint8, AUTOMATIC) ControllerId,
    CONST(uint16 ,AUTOMATIC)Baudrate)
/* PRQA S 3206 --                                                             */
{
    /* the return of the service                                              */
    VAR(Std_ReturnType, AUTOMATIC)              udtResult=E_NOT_OK;
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
    /*! Check if CanIf is not initialized                                      */
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
        /*! Report error CanIf isnot initialized to Det                       */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8CHANGEBAUDRATE_API,CANIF_E_UNINIT);
    }
#endif    
	/*! return E_NOT_OK since this service is not supported in the current release*/
	return udtResult;
}

/******************************************************************************/
/*! \Description : This service shall set the baudrate of the CAN controller.
					Please note that this API is deprecated and is 
					kept only for backward compatibility reasons. In the 
					next major release this API will be deleted.              \n
    \param[in]     ControllerId:  CAN Controller to set the baudrate for      \n
    \Range         0..CanIf_ku8eNumOfControllers-1                            \n
    \param[in]     Baudrate:  Baudrate to set in kbps		                  \n
    \Range														              \n
    \return														              \n
    \Range         E_OK, E_NOT_OK                                             \n
    \Trace_To      CANIF-CDD-0677(0)                                         
*******************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE)CanIf_SetBaudrate(
/* !Deviation : Inhibit MISRA rule [3206]: Parameter is not used because      */
/*             function is not implemented yet. The suppression is to be      */
/*                      removed when the function will be implemented         */
/* PRQA S 3206 ++                                                             */
    VAR(uint8, AUTOMATIC) ControllerId,
    CONST(uint16 ,AUTOMATIC)Baudrate)
/* PRQA S 3206 --                                                             */
{
    /* the return of the service                                              */
    VAR(Std_ReturnType, AUTOMATIC)              udtResult=E_NOT_OK;
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
    /*! Check if CanIf is not initialized                                      */
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
        /*! Report error CanIf isnot initialized to Det                       */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8SETBAUDRATE_API,CANIF_E_UNINIT);
    }
#endif    
	/*! return E_NOT_OK since this service is not supported in the current release*/
	return udtResult;
}

/******************************************************************************/
/*! \Description : This service shall change the Icom Configuration of a 
				   CAN controller to the requested one.				          \n
    \param[in]     ControllerId:  CAN Controller to set the baudrate for      \n
    \Range         0..CanIf_ku8eNumOfControllers-1                            \n
    \param[in]     ConfigurationId:  Requested Configuration                  \n
    \Range														              \n
    \return														              \n
    \Range         E_OK, E_NOT_OK                                             \n
    \Trace_To CANIF-CDD-0682(0)                                              
*******************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE)CanIf_SetIcomConfiguration(
/* !Deviation : Inhibit MISRA rule [3206]: Parameter is not used because      */
/*             function is not implemented yet. The suppression is to be      */
/*                      removed when the function will be implemented         */
/* PRQA S 3206 ++                                                             */
    VAR(uint8, AUTOMATIC) ControllerId,
    VAR(IcomConfigIdType ,AUTOMATIC)ConfigurationId)
/* PRQA S 3206 --                                                             */
{
    /* the return of the service                                              */
    VAR(Std_ReturnType, AUTOMATIC)              udtResult=E_NOT_OK;
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
    /*! Check if CanIf is not initialized                                      */
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
        /*! Report error CanIf isnot initialized to Det                       */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8SETICOMCONFIGURATION_API,CANIF_E_UNINIT);
    }
#endif    
	/*! return E_NOT_OK since this service is not supported in the current release*/
	return udtResult;
}

/******************************************************************************/
/*! \Description : This service shall inform about the change of the 
					Icom Configuration of a CAN controller.			          \n
    \param[in]     ControllerId:  CAN Controller to set the baudrate for      \n
    \Range         0..CanIf_ku8eNumOfControllers-1                            \n
    \param[in]     ConfigurationId:  Requested Configuration                  \n
    \Range		   0..255										              \n
	\param[in]     Error:  Requested Configuration                            \n
    \Range		   ICOM_SWITCH_E_OK, ICOM_SWITCH_E_FAILED		              \n
    \return														              \n
    \Range         E_OK, E_NOT_OK                                             \n
    \Trace_To CANIF-CDD-0694(0)                                              
*******************************************************************************/
FUNC(Std_ReturnType, CANIF_CODE)CanIf_CurrentIcomConfiguration(
/* !Deviation : Inhibit MISRA rule [3206]: Parameter is not used because      */
/*             function is not implemented yet. The suppression is to be      */
/*                      removed when the function will be implemented         */
/* PRQA S 3206 ++                                                             */
    VAR(uint8, AUTOMATIC) ControllerId,
    VAR(IcomConfigIdType ,AUTOMATIC)ConfigurationId,
	VAR(IcomSwitch_ErrorType ,AUTOMATIC)Error)
/* PRQA S 3206 --                                                             */    
{
    /* the return of the service                                              */
    VAR(Std_ReturnType, AUTOMATIC)              udtResult=E_NOT_OK;
#if (CanIf_bDEV_ERR_DETECT == STD_ON)
    /*! Check if CanIf is not initialized                                      */
    if (CanIf_enueGeneralState !=CanIf_INITIALAIZED )
    {
        /*! Report error CanIf isnot initialized to Det                       */
        CanIf_vidDET_REPORT_ERROR(CanIf_u8CURRENTICOMCONFIGURATION_API,
			CANIF_E_UNINIT);
    }
#endif    
	/*! return E_NOT_OK since this service is not supported in the current release*/
	return udtResult;
}


/*!Deviation : inhibit MISRA rule [5087]: because the memmap file is used   */ 
/*        for memory allocation and should be included several times.  */ 
/* PRQA S 5087 L1 */ 
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
/* PRQA L:L1 */ 
