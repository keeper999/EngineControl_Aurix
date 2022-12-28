/******************************************************************************/
/*                                                                            */
/* !Layer          : CRSCTLBSITREAT                                           */
/*                                                                            */
/* !Component      : CRSCTLBSITREAT                                           */
/*                                                                            */
/* !Module         : CRSCTLBSITREAT                                           */
/* !Description    : Contains internal defines of the CRSCTLBSITREAT component*/
/*                                                                            */
/* !File           : CRSCTLBSITREAT_I.C                                       */
/*                                                                            */
/* !Scope          : PrivateComponent                                         */
/*                                                                            */
/* !Target         : All                                                      */
/*                                                                            */
/* !Vendor         : Valeo                                                    */
/*                                                                            */
/* Coding language : C                                                        */
/*                                                                            */
/* COPYRIGHT 2009 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/CRSCTL/CRSCTLBSITREAT/CRSCTLBSIT$*/
/* $Revision::   1.0      $$Author::   alaouni        $$Date::   11 Apr 2012 $*/
/* $Author::   alaouni                                $$Date::   11 Apr 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.H"
#include "CRSCTLBSITREAT_I.H"

#define CRSCTLBSITREAT_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"
   uint8 XVV_Cc_rvv_drv_vh_spd_sp_mux_mem;
#define CRSCTLBSITREAT_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"

/*------------------------------- end of file --------------------------------*/