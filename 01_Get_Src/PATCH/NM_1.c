/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : OSEK_NM                                                 */
/*                                                                            */
/* !Component       : NM                                                      */
/* !Description     : OSEK Communication Network Management                   */
/*                                                                            */
/* !Module          : NM_                                                     */
/* !Description     : API of NM Component                                     */
/*                                                                            */
/* !File            : NM_1.C                                                  */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEES                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2005-2009 VALEO                                                  */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/*  1 / NM_vidSetNodesConfig                                                  */
/*  2 / NM_vidGetCounters                                                     */
/*  3 / NM_vidInitNetworkStatus                                               */
/*  4 / NM_vidDiagInit                                                        */
/*  5 / NM_vidExtractNWIndex                                                  */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/PATCH/NM_1.c_v                    $*/
/* $Revision::   1.0      $$Author::   croche2        $$Date::   11 Mar 2014 $*/
/******************************************************************************/

#include "STD_TYPES.H"
// #include "OS_API.H"
// #include "SWFAIL.H"
// #include "memsrv.h"

// #include "osek_nm.h"
#include "nm_l.h"


// #define OSEK_NM_START_SEC_CODE
// #include "MemMap.h"



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Description :                                                             */
/* !Number      :  1.1                                                        */
/* !Reference   :  V01 NT 08 05903 / 2                                        */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  NM_vidExtractNWIndex(argin NetIdType NetId, argio    */
/*  uint8_least *pu8NWIndex);                                                 */
/*  extf argret void SetRelAlarm(argin ub AlarmID, argin ub Increment, argin  */
/* ub Cycle);                                                                 */
/*  extf argret void CancelAlarm(argin ub AlarmID);                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*                                                                            */
/*  input NM_tstrNetworkParameters NM_astrNetworkParameters[NM_u8NETWORKS_NB];*/
/*  input uint8 NM_aku8NodesNumber[NM_u8NETWORKS_NB];                         */
/*  input ConfigRefType NM_abfNodeDiagOnConfig[2];                            */
/*  input ConfigType NM_abfNodesStatus[NM_u8NETWORKS_NB][2];                  */
/*                                                                            */
/*  output ConfigRefType NM_abfNodeDiagOnConfig[2];                           */
/*  output ConfigType NM_abfNodesStatus[NM_u8NETWORKS_NB][2];                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  :  Mohamed Mohi                                               */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void NM_vidSetNodesConfig
(
   NetIdType NetId,
   const  tenuNMDiagConfig  * penuDiagConfig
)
{
   
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Description :                                                             */
/* !Number      :  1.2                                                        */
/* !Reference   :  V01 NT 08 05903 / 2                                        */
/*                                                                            */
/* !Trace_To :  VEMS_R_08_05903_032.01                                        */
/* !Trace_To :  VEMS_R_08_05903_033.01                                        */
/* !Trace_To :  VEMS_R_08_05903_034.01                                        */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  NM_vidExtractNWIndex(argin NetIdType NetId, argio    */
/*  uint8_least *pu8NWIndex);                                                 */
/*  extf argret void MEMSRV_vidCopyU8(argio uint8 *pu8Dest, argio const uint8 */
/* *pu8Src, argin uint16 u16ElementNumber);                                   */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*                                                                            */
/*  input NM_tstrNetworkParameters NM_astrNetworkParameters[NM_u8NETWORKS_NB];*/
/*  input uint8 NM_aku8NodesNumber[NM_u8NETWORKS_NB];                         */
/*  input uint8 NM_au8BusoffCnt[NM_u8NETWORKS_NB];                            */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  :  Mohamed Mohi                                               */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void NM_vidGetCounters
(
   uint8 NetId,
   uint8* pu8AbsentCounter
)
{
   

}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Description :                                                             */
/* !Number      :  1.3                                                        */
/* !Reference   :  V01 NT 08 05903 / 2                                        */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*  output uint8 NM_au8BusStatus[NM_u8NETWORKS_NB];                           */
/*  output uint8 NM_au8BusoffCnt[NM_u8NETWORKS_NB];                           */
/*  output uint8 NM_au8OnOffStatus[NM_u8NETWORKS_NB];                         */
/*  output boolean NM_abReceiveOk[NM_u8NETWORKS_NB];                          */
/*  output boolean NM_abTransmitOk[NM_u8NETWORKS_NB];                         */
/*  output uint8 NM_au8BusSleepModeState[NM_u8NETWORKS_NB];                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  :  Mohamed Mohi                                               */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
// void NM_vidInitNetworkStatus
// (
   // uint8_least u8NetworkIndex
// )
// {

   
// }


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Description :                                                             */
/* !Number      :  1.4                                                        */
/* !Reference   :  V01 NT 08 05903 / 2                                        */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*  output ConfigRefType NM_abfNodeDiagOnConfig[2];                           */
/*  output uint8 NM_au8MessageNotReceiveNumber[NM_u8NETWORKS_NB];             */
/*  output uint8 NM_au8BusOffNumber[NM_u8NETWORKS_NB];                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  :  Mohamed Mohi                                               */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
// void NM_vidDiagInit
// (
   // uint8_least u8NetworkIndex
// )
// {

  

// }







/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Description :  Find the Index of the network parameters configured for the*/
/*                 input Net ID                                               */
/* !Number      :  NON                                                        */
/* !Reference   :  NON /                                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*  input NetIdType NM_akudtNetId[NM_u8NETWORKS_NB];                          */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  :  Mohamed Mohi                                               */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
// boolean NM_vidExtractNWIndex
// (
   // NetIdType NetId,
   // uint8_least* pu8NWIndex
// )
// {
   
   // boolean        bLocalNetIdFound;

  
   // return(bLocalNetIdFound);
// }


// #define OSEK_NM_STOP_SEC_CODE
// #include "MemMap.h"

/*------------------------------ end of file -------------------------------*/
