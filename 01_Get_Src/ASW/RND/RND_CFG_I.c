/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : RND                                                     */
/* !Description     : RND   component                                         */
/*                                                                            */
/* !Module          : RND                                                     */
/* !Description     : RANDOM                                                  */
/*                                                                            */
/* !File            : RND_CFG_I.c                                             */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32BIT                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2009 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / RND_vidReadRandomNumber                                              */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/RND/RND_CFG_I.C_v                 $*/
/* $Revision::   1.0      $$Author::   ftournai       $$Date::   10 Jul 2009 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "RND.h"
#include "RND_im.h"
#include "RND_L.h"
#include "RND_CFG_I.h"


#define RND_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


const uint8 RND_kuADCHAL[NB_MAX_ADC_CHANNEL] = { CH_ADC_AC_PRS_V,
                                                 CH_ADC_BAT_RLY_V,
                                                 CH_ADC_CRU_VSL_MOD_V,
                                                 CH_ADC_LBDW_V,
                                                 CH_ADC_LBUP_V,
                                                 CH_ADC_MAP_V,
                                                 CH_ADC_PDL_V_1,
                                                 CH_ADC_PDL_V_2,
                                                 CH_ADC_PWRS_V_1,
                                                 CH_ADC_PWRS_V_2,
                                                 CH_ADC_TCO_V,
                                                 CH_ADC_THR_V_1,
                                                 CH_ADC_THR_V_2,
                                                 CH_ADC_TIA_V
};

#define RND_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


/*-------------------------------- end of file -------------------------------*/

