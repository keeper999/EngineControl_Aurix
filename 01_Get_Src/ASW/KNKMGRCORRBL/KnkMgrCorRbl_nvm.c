/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKMGRCORRBL_NVM                                        */
/* !Description     : KNKMGRCORRBL_NVM Component.                             */
/*                                                                            */
/* !Module          : KNKMGRCORRBL_NVM                                        */
/* !Description     : interface du module  KNKMGRCORRBL_NVM                   */
/*                                                                            */
/* !File            : KNKMGRCORRBL_NVM.c                                      */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32BIT                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/Main/KNKMGRCORRBL_NVM.c_v                 $*/
/* $Revision::   1.1      $$Author::   vvoyer        $$Date::   05 Oct 2009 1$*/
/* $Author::   vvoyer                                $$Date::   05 Oct 2009 1$*/
/******************************************************************************/
#include "KnkMgrCorRbl.h"
#include "Std_Types.h"
#include "KnkMgrCorRbl_nvm.h"

#define KNKMGRCORRBL_START_SEC_VAR_16BIT
#include "KnkMgrCorRbl_MemMap.h"

/* Type:    UInt16                                                            */
VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurKnkRblCyl1[3][3];

/* Type:    UInt16                                                            */
VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurKnkRblCyl2[3][3];

/* Type:    UInt16                                                            */
VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurKnkRblCyl3[3][3];

/* Type:    UInt16                                                            */
VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurKnkRblCyl4[3][3];

/* Type:    UInt16                                                            */
VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurRblCyl1[3][3];

/* Type:    UInt16                                                            */
VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurRblCyl2[3][3];

/* Type:    UInt16                                                            */
VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurRblCyl3[3][3];

/* Type:    UInt16                                                            */
VAR(UInt16, KNKMGRCORRBL_VAR) KnkMgt_ctOccurRblCyl4[3][3];

#define KNKMGRCORRBL_STOP_SEC_VAR_16BIT
#include "KnkMgrCorRbl_MemMap.h"


#define KNKMGRCORRBL_START_SEC_CODE
#include "KnkMgrCorRbl_MemMap.h"

void KNKMGRCORRBL_1__nvmini (void)
{
   sint32_least s32LocalIndex;
   UInt16 *u16localKnkMgt_ptr;
   u16localKnkMgt_ptr = &KnkMgt_ctOccurKnkRblCyl1[0][0];
   for (s32LocalIndex = 0; s32LocalIndex < 9; s32LocalIndex++)
   {
      u16localKnkMgt_ptr[s32LocalIndex] = 0;
   }
}

void KNKMGRCORRBL_2__nvmini (void)
{
   sint32_least s32LocalIndex;
   UInt16 *u16localKnkMgt_ptr;
   u16localKnkMgt_ptr = &KnkMgt_ctOccurKnkRblCyl2[0][0];
   for (s32LocalIndex = 0; s32LocalIndex < 9; s32LocalIndex++)
   {
      u16localKnkMgt_ptr[s32LocalIndex] = 0;
   }
}

void KNKMGRCORRBL_3__nvmini (void)
{
   sint32_least s32LocalIndex;
   UInt16 *u16localKnkMgt_ptr;
   u16localKnkMgt_ptr = &KnkMgt_ctOccurKnkRblCyl3[0][0];
   for (s32LocalIndex = 0; s32LocalIndex < 9; s32LocalIndex++)
   {
      u16localKnkMgt_ptr[s32LocalIndex] = 0;
   }
}

void KNKMGRCORRBL_4__nvmini (void)
{
   sint32_least s32LocalIndex;
   UInt16 *u16localKnkMgt_ptr;
   u16localKnkMgt_ptr = &KnkMgt_ctOccurKnkRblCyl4[0][0];
   for (s32LocalIndex = 0; s32LocalIndex < 9; s32LocalIndex++)
   {
      u16localKnkMgt_ptr[s32LocalIndex] = 0;
   }
}

void KNKMGRCORRBL_5__nvmini (void)
{
   sint32_least s32LocalIndex;
   UInt16 *u16localKnkMgt_ptr;
   u16localKnkMgt_ptr = &KnkMgt_ctOccurRblCyl1[0][0];
   for (s32LocalIndex = 0; s32LocalIndex < 9; s32LocalIndex++)
   {
      u16localKnkMgt_ptr[s32LocalIndex] = 0;
   }
}

void KNKMGRCORRBL_6__nvmini (void)
{
   sint32_least s32LocalIndex;
   UInt16 *u16localKnkMgt_ptr;
   u16localKnkMgt_ptr = &KnkMgt_ctOccurRblCyl2[0][0];
   for (s32LocalIndex = 0; s32LocalIndex < 9; s32LocalIndex++)
   {
      u16localKnkMgt_ptr[s32LocalIndex] = 0;
   }
}

void KNKMGRCORRBL_7__nvmini (void)
{
   sint32_least s32LocalIndex;
   UInt16 *u16localKnkMgt_ptr;
   u16localKnkMgt_ptr = &KnkMgt_ctOccurRblCyl3[0][0];
   for (s32LocalIndex = 0; s32LocalIndex < 9; s32LocalIndex++)
   {
      u16localKnkMgt_ptr[s32LocalIndex] = 0;
   }
}

void KNKMGRCORRBL_8__nvmini (void)
{
   sint32_least s32LocalIndex;
   UInt16 *u16localKnkMgt_ptr;
   u16localKnkMgt_ptr = &KnkMgt_ctOccurRblCyl4[0][0];
   for (s32LocalIndex = 0; s32LocalIndex < 9; s32LocalIndex++)
   {
      u16localKnkMgt_ptr[s32LocalIndex] = 0;
   }
}

#define KNKMGRCORRBL_STOP_SEC_CODE
#include "KnkMgrCorRbl_MemMap.h"
