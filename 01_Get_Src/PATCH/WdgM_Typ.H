/******************************************************************************/
/*                                                                            */
/* !Layer          : SRV                                                      */
/*                                                                            */
/* !Component      : WdgM                                                     */
/*                                                                            */
/* !Module         : WdgM_Typ                                                 */
/* !Description    : Declaration of new types for WdgM Component              */
/*                                                                            */
/* !File           : WdgM_Typ.H                                               */
/*                                                                            */
/* !Scope          : Public                                                   */
/*                                                                            */
/* !Target         : All                                                      */
/*                                                                            */
/* !Vendor         : Valeo                                                    */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT 2011 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx6_2/LOG/ASW/Ref/Main/PATCH/WdgM_Typ.H_v                $*/
/* $Revision::   1.0      $$Author::   croche2        $$Date::   12 Mar 2014 $*/
/******************************************************************************/

#ifndef WDGM_TYP_H
#define WDGM_TYP_H

#include "STD_TYPES.H"

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/* !Comment: Supervised Entity reference                                      */
typedef uint8 WdgM_SupervisedEntityIdType;

/* !Comment: Local status of Supervised entity for Sequence and Timout Faults */
/* !Range  : WDGM_LOCAL_STATUS_OK .. WDGM_LOCAL_STATUS_FAILED                 */
typedef uint8 WdgM_LocalStatusType;

/* !Comment: Checkpoints reference per supervised entity                      */
typedef uint16 WdgM_CheckpointIdType;

/* !Comment: This structure works as a container for all configuration        */
/*           paramaeters sent by Application.                                 */
typedef struct
{
   WdgM_SupervisedEntityIdType udtNumberOfSE;
   WdgM_CheckpointIdType       *audtNumberOfCheckpoints;
   uint16                      *au16Timeout;
} WdgM_ConfigType;


#endif /* WDGM_TYP_H */

/*-------------------------------- end of file -------------------------------*/

