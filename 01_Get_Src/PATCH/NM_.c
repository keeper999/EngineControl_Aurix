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
/* !File            : NM_.C                                                   */
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
/*  1 / StartNM                                                               */
/*  2 / StopNM                                                                */
/*  3 / GetStatus                                                             */
/*  4 / GetConfig                                                             */
/*  5 / InitConfig                                                            */
/*  6 / InitExtNodeMonitoring                                                 */
/*  7 / GoToMode                                                              */
/*  8 / CmpConfig                                                             */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/PATCH/NM_.c_v                     $*/
/* $Revision::   1.0      $$Author::   croche2        $$Date::   11 Mar 2014 $*/
/******************************************************************************/

#include "STD_TYPES.H"

// #include "COMDLL.H"
// #include "SWFAIL.H"

// #include "NM.H"
#include "NM_L.H"
// #include "OSEK_NM.H"

// #define OSEK_NM_START_SEC_CODE
// #include "MemMap.h"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Description :  StartNM initializes all internal NM variables.             */
/* !Number      :  1                                                          */
/* !Reference   :  V01 NT 08 05903 / 2                                        */
/*                                                                            */
/* !Trace_To :  VEMS_R_08_05903_003.01                                        */
/* !Trace_To :  VEMS_R_08_05903_004.01                                        */
/* !Trace_To :  VEMS_R_08_05903_005.01                                        */
/* !Trace_To :  VEMS_R_08_05903_006.01                                        */
/* !Trace_To :  VEMS_R_08_05903_007.01                                        */
/* !Trace_To :  VEMS_R_08_05903_008.01                                        */
/* !Trace_To :  VEMS_R_08_05903_009.01                                        */
/* !Trace_To :  VEMS_R_08_05903_010.01                                        */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  NM_vidExtractNWIndex(argin NetIdType NetId, argio    */
/*  uint8_least *pu8NWIndex);                                                 */
/*  extf argret StatusType  COMDLL_udtBusStateManagement(argin                */
/* OSEK_COM_tudtBusId udtBusId, argin COMDLL_tenuBusState enuBusState);       */
/*  extf argret void COMDLL_vidOnline(argin OSEK_COM_tudtBusId udtBusId);     */
/*  extf argret StatusType  InitConfig(argin NetIdType NetId);                */
/*  extf argret void NM_vidInitNetworkStatus(argin uint8_least                */
/* u8NetworkIndex);                                                           */
/*  extf argret void NM_vidDiagInit(argin uint8_least  u8NetworkIndex);       */
/*                                                                            */
/*                                                                            */
/*  output boolean NM_abDiagOn[NM_u8NETWORKS_NB];                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  :  Mohamed Mohi                                               */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
StatusType StartNM
(
   NetIdType NetId
)
{
  
      return( E_NOT_OK );
   
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Description :  StopNM stops the local network management.                 */
/* !Number      :  2                                                          */
/* !Reference   :  V01 NT 08 05903 / 2                                        */
/*                                                                            */
/* !Trace_To :  VEMS_R_08_05903_011.01                                        */
/* !Trace_To :  VEMS_R_08_05903_012.01                                        */
/* !Trace_To :  VEMS_R_08_05903_013.01                                        */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  NM_vidExtractNWIndex(argin NetIdType NetId, argio    */
/*  uint8_least *pu8NWIndex);                                                 */
/*  extf argret StatusType  COMDLL_udtBusStateManagement(argin                */
/* OSEK_COM_tudtBusId udtBusId, argin COMDLL_tenuBusState enuBusState);       */
/*  extf argret void NM_vidDiagInit(argin uint8_least  u8NetworkIndex);       */
/*                                                                            */
/*  input uint8 NM_au8OnOffStatus[NM_u8NETWORKS_NB];                          */
/*                                                                            */
/*  output uint8 NM_au8OnOffStatus[NM_u8NETWORKS_NB];                         */
/*  output boolean NM_abDiagOn[NM_u8NETWORKS_NB];                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  :  Mohamed Mohi                                               */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
// StatusType StopNM
// (
   // NetIdType NetId
// )
// {
   
      // return( E_NOT_OK );
  
// }


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Description :  GetStatus provides the current status of the network with  */
/*                 the format specified on §8.3.                              */
/* !Number      :  3                                                          */
/* !Reference   :  V01 NT 08 05903 / 2                                        */
/*                                                                            */
/* !Trace_To :  VEMS_R_08_05903_014.01                                        */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  NM_vidExtractNWIndex(argin NetIdType NetId, argio    */
/*  uint8_least *pu8NWIndex);                                                 */
/*                                                                            */
/*  input uint8 NM_au8OnOffStatus[NM_u8NETWORKS_NB];                          */
/*  input uint8 NM_au8BusStatus[NM_u8NETWORKS_NB];                            */
/*  input uint8 NM_au8BusSleepModeState[NM_u8NETWORKS_NB];                    */
/*  input boolean NM_abNmLimpHome[NM_u8NETWORKS_NB];                          */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  :  Mohamed Mohi                                               */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
// StatusType GetStatus
// (
   // NetIdType NetId,
   // NetworkStatusTypeRef NetworkStatus
// )
// {
   
      // return(E_NOT_OK);
  
// }


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Description :  This service provides the actual configuration of all      */
/*                 network nodes which the kind is specified by ConfigKind.   */
/*                 Each returned Config bit corresponds to a network node.    */
/* !Number      :  4                                                          */
/* !Reference   :  V01 NT 08 05903 / 2                                        */
/*                                                                            */
/* !Trace_To :  VEMS_R_08_05903_015.01                                        */
/* !Trace_To :  VEMS_R_08_05903_016.01                                        */
/* !Trace_To :  VEMS_R_08_05903_017.01                                        */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  NM_vidExtractNWIndex(argin NetIdType NetId, argio    */
/*  uint8_least *pu8NWIndex);                                                 */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*                                                                            */
/*  input ConfigType NM_abfNodesStatus[NM_u8NETWORKS_NB][2];                  */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  :  Mohamed Mohi                                               */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
// StatusType GetConfig
// (
   // NetIdType NetId,
   // ConfigRefType Config,
   // ConfigKindName ConfigKind
// )
// {
  
       // return(E_NOT_OK);
   
// }


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Description :  InitConfig (re)initializes node status to Absent state.    */
/* !Number      :  5                                                          */
/* !Reference   :  V01 NT 08 05903 / 2                                        */
/*                                                                            */
/* !Trace_To :  VEMS_R_08_05903_022.01                                        */
/* !Trace_To :  VEMS_R_08_05903_023.01                                        */
/* !Trace_To :  VEMS_R_08_05903_024.01                                        */
/* !Trace_To :  VEMS_R_08_05903_025.01                                        */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  NM_vidExtractNWIndex(argin NetIdType NetId, argio    */
/*  uint8_least *pu8NWIndex);                                                 */
/*                                                                            */
/*  input NM_tstrNetworkParameters NM_astrNetworkParameters[NM_u8NETWORKS_NB];*/
/*  input ConfigType NM_akbfAllModulesAbsent[NM_u8NETWORKS_NB];               */
/*  input uint8 NM_aku8NodesNumber[NM_u8NETWORKS_NB];                         */
/*                                                                            */
/*  output ConfigType NM_abfNodesStatus[NM_u8NETWORKS_NB][2];                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  :  Mohamed Mohi                                               */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
// StatusType InitConfig
// (
   // NetIdType NetId
// )
// {
   
      // return( E_NOT_OK);
 

// }


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Description :  Fault counter values are not affected by a call to this    */
/*                 InitExtNodeMonitoring API.                                 */
/* !Number      :  6                                                          */
/* !Reference   :  V01 NT 08 05903 / 2                                        */
/*                                                                            */
/* !Trace_To :  VEMS_R_08_05903_019.01                                        */
/* !Trace_To :  VEMS_R_08_05903_020.01                                        */
/* !Trace_To :  VEMS_R_08_05903_021.01                                        */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  NM_vidExtractNWIndex(argin NetIdType NetId, argio    */
/*  uint8_least *pu8NWIndex);                                                 */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*                                                                            */
/*  input NM_tstrNetworkParameters NM_astrNetworkParameters[NM_u8NETWORKS_NB];*/
/*  input uint8 NM_aku8NodesNumber[NM_u8NETWORKS_NB];                         */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  :  Mohamed Mohi                                               */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void InitExtNodeMonitoring
(
   NetIdType NetId,
   NodeIdType NodeId,
   uint8 DeltaInc,
   uint8 DeltaDec
)
{
   
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Description :                                                             */
/* !Number      :  8                                                          */
/* !Reference   :  V01 NT 08 05903 / 2                                        */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  NM_vidExtractNWIndex(argin NetIdType NetId, argio    */
/*  uint8_least *pu8NWIndex);                                                 */
/*  extf argret void COMDLL_vidOffline(argin OSEK_COM_tudtBusId udtBusId);    */
/*  extf argret void SetRelAlarm(argin ub AlarmID, argin ub Increment, argin  */
/* ub Cycle);                                                                 */
/*  extf argret StatusType  COMDLL_udtBusStateManagement(argin                */
/* OSEK_COM_tudtBusId udtBusId, argin COMDLL_tenuBusState enuBusState);       */
/*  extf argret void CancelAlarm(argin ub AlarmID);                           */
/*  extf argret void COMDLL_vidOnline(argin OSEK_COM_tudtBusId udtBusId);     */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*                                                                            */
/*  input boolean NM_kabSleepModeManagement[NM_u8NETWORKS_NB];                */
/*  input uint8 NM_au8BusSleepModeState[NM_u8NETWORKS_NB];                    */
/*  input AlarmType NM_akudtBusSleepAlarm[NM_u8NETWORKS_NB];                  */
/*  input TickType NM_akudtBusWaitSleepTimeOut[NM_u8NETWORKS_NB];             */
/*                                                                            */
/*  output uint8 NM_au8BusSleepModeState[NM_u8NETWORKS_NB];                   */
/*  output boolean NM_abDiagOn[NM_u8NETWORKS_NB];                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  :  Mohamed Mohi                                               */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
StatusType GoToMode
(
   NetIdType NetId,
   NMModeName NewMode
)
{
   StatusType   udtLocalErrorChangeBusState;
  
   return( udtLocalErrorChangeBusState );
}



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Description :  CmpConfig return the result of the NOT (<CMask> AND        */
/*                 (<TestConfig> EXOR <RefConfig>)) operation.                */
/* !Number      :  7                                                          */
/* !Reference   :  V01 NT 08 05903 / 2                                        */
/*                                                                            */
/* !Trace_To :  VEMS_R_08_05903_018.01                                        */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  :  Mohamed Mohi                                               */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
// StatusType CmpConfig
// (
   // NetIdType NetId,
   // const ConfigRefType TestConfig,
   // const ConfigRefType RefConfig,
   // const ConfigRefType CMask
// )
// {

   // StatusType udtLocalStatus;
   
   // return(udtLocalStatus);
// }

// #define OSEK_NM_STOP_SEC_CODE
// #include "MemMap.h"

/*------------------------------- end of file --------------------------------*/
