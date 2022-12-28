/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFDFTLRN_NVM                                          */
/* !Description     : MISFDFTLRN_NVM Component.                               */
/*                                                                            */
/* !Module          : MISFDFTLRN_NVM                                          */
/* !Description     : interface du module  MISFDFTLRN_NVM                     */
/*                                                                            */
/* !File            : MISFDFTLRN_NVM.c                                        */
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
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
#include "MISFDFTLRN.h"
#include "Std_Types.h"
#include "MISFDFTLRN_nvm.h"

#define MISFDFTLRN_START_SEC_VAR_16BIT
#include "MISFDFTLRN_MemMap.h"

/* Type:    SInt16                                                            */
VAR(SInt16, MISFDFTLRN_VAR) Misf_prm_tiDlyExpWinLrn[4][9];

/* Type:    SInt16                                                            */
VAR(SInt16, MISFDFTLRN_VAR) Misf_prm_tiDlyTDCWinLrn[4][9];

/* Type:    SInt16                                                            */
VAR(SInt16, MISFDFTLRN_VAR) Misf_prm_tiDlyBdcWinLrn[4][9];

/* Type:    SInt16                                                            */
VAR(SInt16, MISFDFTLRN_VAR) Misf_prm_tiDlyLongWinLrn[4][9];


#define MISFDFTLRN_STOP_SEC_VAR_16BIT
#include "MISFDFTLRN_MemMap.h"


#define MISFDFTLRN_START_SEC_CODE
#include "MISFDFTLRN_MemMap.h"

void MISFDFTLRN_1__nvmini (void)
{
   sint32_least s32LocalIndex;
   SInt16 *s16localMisf_prm_tiDlyExp;


   s16localMisf_prm_tiDlyExp = &Misf_prm_tiDlyExpWinLrn[0][0];
   for (s32LocalIndex = 0; s32LocalIndex < 36; s32LocalIndex++)
   {
      s16localMisf_prm_tiDlyExp[s32LocalIndex] = 0;
   }
}

void MISFDFTLRN_2__nvmini (void)
{
   sint32_least s32LocalIndex;
   SInt16 *s16localMisf_prm_tiDlyTDC;


   s16localMisf_prm_tiDlyTDC = &Misf_prm_tiDlyTDCWinLrn[0][0];
   for (s32LocalIndex = 0; s32LocalIndex < 36; s32LocalIndex++)
   {
      s16localMisf_prm_tiDlyTDC[s32LocalIndex] = 0;
   }
}

void MISFDFTLRN_3__nvmini (void)
{
   sint32_least s32LocalIndex;
   SInt16 *s16localMisf_prm_tiDlyBdc;


   s16localMisf_prm_tiDlyBdc = &Misf_prm_tiDlyBdcWinLrn[0][0];
   for (s32LocalIndex = 0; s32LocalIndex < 36; s32LocalIndex++)
   {
      s16localMisf_prm_tiDlyBdc[s32LocalIndex] = 0;
   }
}

void MISFDFTLRN_4__nvmini (void)
{
   sint32_least s32LocalIndex;
   SInt16 *s16localMisf_prm_tiDlyLong;


   s16localMisf_prm_tiDlyLong = &Misf_prm_tiDlyLongWinLrn[0][0];
   for (s32LocalIndex = 0; s32LocalIndex < 36; s32LocalIndex++)
   {
      s16localMisf_prm_tiDlyLong[s32LocalIndex] = 0;
   }
}
#define MISFDFTLRN_STOP_SEC_CODE
#include "MISFDFTLRN_MemMap.h"