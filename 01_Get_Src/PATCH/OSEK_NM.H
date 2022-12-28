/******************************************************************************/
/*                                                                            */
/* !Layer           : OSEK                                                    */
/*                                                                            */
/* !Component       : OSEK_NM                                                 */
/* !Description     : Network Manager OSEK / Indirect Mode                    */
/*                                                                            */
/* !Module          : NM                                                      */
/* !Description     : API of the OSEK_NM Component                            */
/*                                                                            */
/* !File            : OSEK_NM.H                                               */
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
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/PATCH/OSEK_NM.H_v                 $*/
/* $Revision::   1.0      $$Author::   croche2        $$Date::   11 Mar 2014 $*/
/******************************************************************************/
/* !VnrOff : OSEK Names                                                       */
/******************************************************************************/

#ifndef OSEK_NM_H
#define OSEK_NM_H

#include "STD_TYPES.H"
#include "nm_typ.h"
#include "oseknm_c.h"
// #include "nm.h"

/******************************************************************************/
/* DECLARATION                                                                */
/******************************************************************************/
StatusType  StartNM    (NetIdType NetId);
// StatusType  StartNM    (NetIdType NetId);
// StatusType  StopNM     (NetIdType NetId);
// StatusType  InitConfig (NetIdType NetId);
// StatusType  GetStatus  (NetIdType NetId, NetworkStatusTypeRef NetworkStatus);
StatusType  GoToMode   (NetIdType NetId, NMModeName  NewMode);
// StatusType  GetConfig
// (
   // NetIdType      NetId,
   // ConfigRefType  Config,
   // ConfigKindName ConfigKind
// );

void InitExtNodeMonitoring
(
   NetIdType  NetId,
   NodeIdType NodeId,
   uint8      DeltaInc,
   uint8      DeltaDec
);

void NM_vidSetNodesConfig
(
   NetIdType NetId,
   const tenuNMDiagConfig * penuDiagConfig
);

void NM_vidGetCounters
(
   NetIdType NetId,
   uint8 *        pu8AbsentCounter
);

// StatusType CmpConfig
// (
   // NetIdType     NetId,
   // const ConfigRefType TestConfig,
   // const ConfigRefType RefConfig,
   // const ConfigRefType CMask
// );


#endif /* OSEK_NM_H*/

/*-------------------------------- end of file -------------------------------*/
