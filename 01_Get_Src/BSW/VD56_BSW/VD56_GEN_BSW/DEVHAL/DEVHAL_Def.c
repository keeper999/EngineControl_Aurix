/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : DEVHAL                                                  */
/* !Description     : DEVHAL Component                                        */
/*                                                                            */
/* !File            : DEVHAL_Def.c                                            */
/* !Description     : DEVHAL data definition                                  */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "DEVHAL_Def.h"
#include "IfxOvc_reg.h"
#include "IfxOvc_regdef.h"

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

#define DEVHAL_START_SEC_VAR_CLEARED_BOOLEAN
#include "DEVHAL_MemMap.h"

boolean DEVHAL_bIsFlsLoaderInitialized;
boolean DEVHAL_bIsFlsLoaderErasing;
boolean DEVHAL_bIsFlsLoaderErased;
boolean DEVHAL_bIsFlsLoaderCopied;
boolean DEVHAL_bIsInitialized;

#define DEVHAL_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "DEVHAL_MemMap.h"

#define DEVHAL_START_SEC_VAR_CLEARED_8BIT
#include "DEVHAL_MemMap.h"

uint8 DEVHAL_u8CheckEngineState;

#define DEVHAL_STOP_SEC_VAR_CLEARED_8BIT
#include "DEVHAL_MemMap.h"

#define DEVHAL_START_SEC_VAR_INIT_UNSPECIFIED
#include "DEVHAL_MemMap.h"

/* !Comment: Core 0 Redirected Address Base Register                          */
volatile Ifx_OVC_BLK_RABR *OVMrabrXC0[32] =
{
   &OVC0_RABR0,
   &OVC0_RABR1,
   &OVC0_RABR2,
   &OVC0_RABR3,
   &OVC0_RABR4,
   &OVC0_RABR5,
   &OVC0_RABR6,
   &OVC0_RABR7,
   &OVC0_RABR8,
   &OVC0_RABR9,
   &OVC0_RABR10,
   &OVC0_RABR11,
   &OVC0_RABR12,
   &OVC0_RABR13,
   &OVC0_RABR14,
   &OVC0_RABR15,
   &OVC0_RABR16,
   &OVC0_RABR17,
   &OVC0_RABR18,
   &OVC0_RABR19,
   &OVC0_RABR20,
   &OVC0_RABR21,
   &OVC0_RABR22,
   &OVC0_RABR23,
   &OVC0_RABR24,
   &OVC0_RABR25,
   &OVC0_RABR26,
   &OVC0_RABR27,
   &OVC0_RABR28,
   &OVC0_RABR29,
   &OVC0_RABR30,
   &OVC0_RABR31
};

/* !Comment: Core 0 Overlay Target Register                                   */
volatile Ifx_OVC_BLK_OTAR *OVMotarXC0[32] =
{
   &OVC0_OTAR0,
   &OVC0_OTAR1,
   &OVC0_OTAR2,
   &OVC0_OTAR3,
   &OVC0_OTAR4,
   &OVC0_OTAR5,
   &OVC0_OTAR6,
   &OVC0_OTAR7,
   &OVC0_OTAR8,
   &OVC0_OTAR9,
   &OVC0_OTAR10,
   &OVC0_OTAR11,
   &OVC0_OTAR12,
   &OVC0_OTAR13,
   &OVC0_OTAR14,
   &OVC0_OTAR15,
   &OVC0_OTAR16,
   &OVC0_OTAR17,
   &OVC0_OTAR18,
   &OVC0_OTAR19,
   &OVC0_OTAR20,
   &OVC0_OTAR21,
   &OVC0_OTAR22,
   &OVC0_OTAR23,
   &OVC0_OTAR24,
   &OVC0_OTAR25,
   &OVC0_OTAR26,
   &OVC0_OTAR27,
   &OVC0_OTAR28,
   &OVC0_OTAR29,
   &OVC0_OTAR30,
   &OVC0_OTAR31
};

/* !Comment: Core 0 Overlay Mask Address                                      */
volatile Ifx_OVC_BLK_OMASK *OVMomaskXC0[32] =
{
   &OVC0_OMASK0,
   &OVC0_OMASK1,
   &OVC0_OMASK2,
   &OVC0_OMASK3,
   &OVC0_OMASK4,
   &OVC0_OMASK5,
   &OVC0_OMASK6,
   &OVC0_OMASK7,
   &OVC0_OMASK8,
   &OVC0_OMASK9,
   &OVC0_OMASK10,
   &OVC0_OMASK11,
   &OVC0_OMASK12,
   &OVC0_OMASK13,
   &OVC0_OMASK14,
   &OVC0_OMASK15,
   &OVC0_OMASK16,
   &OVC0_OMASK17,
   &OVC0_OMASK18,
   &OVC0_OMASK19,
   &OVC0_OMASK20,
   &OVC0_OMASK21,
   &OVC0_OMASK22,
   &OVC0_OMASK23,
   &OVC0_OMASK24,
   &OVC0_OMASK25,
   &OVC0_OMASK26,
   &OVC0_OMASK27,
   &OVC0_OMASK28,
   &OVC0_OMASK29,
   &OVC0_OMASK30,
   &OVC0_OMASK31
};

/* !Comment: Core 1 Redirected Address Base Register                          */
volatile Ifx_OVC_BLK_RABR *OVMrabrXC1[32] =
{
   &OVC1_RABR0,
   &OVC1_RABR1,
   &OVC1_RABR2,
   &OVC1_RABR3,
   &OVC1_RABR4,
   &OVC1_RABR5,
   &OVC1_RABR6,
   &OVC1_RABR7,
   &OVC1_RABR8,
   &OVC1_RABR9,
   &OVC1_RABR10,
   &OVC1_RABR11,
   &OVC1_RABR12,
   &OVC1_RABR13,
   &OVC1_RABR14,
   &OVC1_RABR15,
   &OVC1_RABR16,
   &OVC1_RABR17,
   &OVC1_RABR18,
   &OVC1_RABR19,
   &OVC1_RABR20,
   &OVC1_RABR21,
   &OVC1_RABR22,
   &OVC1_RABR23,
   &OVC1_RABR24,
   &OVC1_RABR25,
   &OVC1_RABR26,
   &OVC1_RABR27,
   &OVC1_RABR28,
   &OVC1_RABR29,
   &OVC1_RABR30,
   &OVC1_RABR31
};

/* !Comment: Core 1 Overlay Target Register                                   */
volatile Ifx_OVC_BLK_OTAR *OVMotarXC1[32] =
{
   &OVC1_OTAR0,
   &OVC1_OTAR1,
   &OVC1_OTAR2,
   &OVC1_OTAR3,
   &OVC1_OTAR4,
   &OVC1_OTAR5,
   &OVC1_OTAR6,
   &OVC1_OTAR7,
   &OVC1_OTAR8,
   &OVC1_OTAR9,
   &OVC1_OTAR10,
   &OVC1_OTAR11,
   &OVC1_OTAR12,
   &OVC1_OTAR13,
   &OVC1_OTAR14,
   &OVC1_OTAR15,
   &OVC1_OTAR16,
   &OVC1_OTAR17,
   &OVC1_OTAR18,
   &OVC1_OTAR19,
   &OVC1_OTAR20,
   &OVC1_OTAR21,
   &OVC1_OTAR22,
   &OVC1_OTAR23,
   &OVC1_OTAR24,
   &OVC1_OTAR25,
   &OVC1_OTAR26,
   &OVC1_OTAR27,
   &OVC1_OTAR28,
   &OVC1_OTAR29,
   &OVC1_OTAR30,
   &OVC1_OTAR31
};

/* !Comment: Core 1 Overlay Mask Address                                      */
volatile Ifx_OVC_BLK_OMASK *OVMomaskXC1[32] =
{
   &OVC1_OMASK0,
   &OVC1_OMASK1,
   &OVC1_OMASK2,
   &OVC1_OMASK3,
   &OVC1_OMASK4,
   &OVC1_OMASK5,
   &OVC1_OMASK6,
   &OVC1_OMASK7,
   &OVC1_OMASK8,
   &OVC1_OMASK9,
   &OVC1_OMASK10,
   &OVC1_OMASK11,
   &OVC1_OMASK12,
   &OVC1_OMASK13,
   &OVC1_OMASK14,
   &OVC1_OMASK15,
   &OVC1_OMASK16,
   &OVC1_OMASK17,
   &OVC1_OMASK18,
   &OVC1_OMASK19,
   &OVC1_OMASK20,
   &OVC1_OMASK21,
   &OVC1_OMASK22,
   &OVC1_OMASK23,
   &OVC1_OMASK24,
   &OVC1_OMASK25,
   &OVC1_OMASK26,
   &OVC1_OMASK27,
   &OVC1_OMASK28,
   &OVC1_OMASK29,
   &OVC1_OMASK30,
   &OVC1_OMASK31
};

/* !Comment: Core 2 Redirected Address Base Register                          */
volatile Ifx_OVC_BLK_RABR *OVMrabrXC2[32] =
{
   &OVC2_RABR0,
   &OVC2_RABR1,
   &OVC2_RABR2,
   &OVC2_RABR3,
   &OVC2_RABR4,
   &OVC2_RABR5,
   &OVC2_RABR6,
   &OVC2_RABR7,
   &OVC2_RABR8,
   &OVC2_RABR9,
   &OVC2_RABR10,
   &OVC2_RABR11,
   &OVC2_RABR12,
   &OVC2_RABR13,
   &OVC2_RABR14,
   &OVC2_RABR15,
   &OVC2_RABR16,
   &OVC2_RABR17,
   &OVC2_RABR18,
   &OVC2_RABR19,
   &OVC2_RABR20,
   &OVC2_RABR21,
   &OVC2_RABR22,
   &OVC2_RABR23,
   &OVC2_RABR24,
   &OVC2_RABR25,
   &OVC2_RABR26,
   &OVC2_RABR27,
   &OVC2_RABR28,
   &OVC2_RABR29,
   &OVC2_RABR30,
   &OVC2_RABR31
};

/* !Comment: Core 2 Overlay Target Register                                   */
volatile Ifx_OVC_BLK_OTAR *OVMotarXC2[32] =
{
   &OVC2_OTAR0,
   &OVC2_OTAR1,
   &OVC2_OTAR2,
   &OVC2_OTAR3,
   &OVC2_OTAR4,
   &OVC2_OTAR5,
   &OVC2_OTAR6,
   &OVC2_OTAR7,
   &OVC2_OTAR8,
   &OVC2_OTAR9,
   &OVC2_OTAR10,
   &OVC2_OTAR11,
   &OVC2_OTAR12,
   &OVC2_OTAR13,
   &OVC2_OTAR14,
   &OVC2_OTAR15,
   &OVC2_OTAR16,
   &OVC2_OTAR17,
   &OVC2_OTAR18,
   &OVC2_OTAR19,
   &OVC2_OTAR20,
   &OVC2_OTAR21,
   &OVC2_OTAR22,
   &OVC2_OTAR23,
   &OVC2_OTAR24,
   &OVC2_OTAR25,
   &OVC2_OTAR26,
   &OVC2_OTAR27,
   &OVC2_OTAR28,
   &OVC2_OTAR29,
   &OVC2_OTAR30,
   &OVC2_OTAR31
};

/* !Comment: Core 2 Overlay Mask Address                                      */
volatile Ifx_OVC_BLK_OMASK *OVMomaskXC2[32] =
{
   &OVC2_OMASK0,
   &OVC2_OMASK1,
   &OVC2_OMASK2,
   &OVC2_OMASK3,
   &OVC2_OMASK4,
   &OVC2_OMASK5,
   &OVC2_OMASK6,
   &OVC2_OMASK7,
   &OVC2_OMASK8,
   &OVC2_OMASK9,
   &OVC2_OMASK10,
   &OVC2_OMASK11,
   &OVC2_OMASK12,
   &OVC2_OMASK13,
   &OVC2_OMASK14,
   &OVC2_OMASK15,
   &OVC2_OMASK16,
   &OVC2_OMASK17,
   &OVC2_OMASK18,
   &OVC2_OMASK19,
   &OVC2_OMASK20,
   &OVC2_OMASK21,
   &OVC2_OMASK22,
   &OVC2_OMASK23,
   &OVC2_OMASK24,
   &OVC2_OMASK25,
   &OVC2_OMASK26,
   &OVC2_OMASK27,
   &OVC2_OMASK28,
   &OVC2_OMASK29,
   &OVC2_OMASK30,
   &OVC2_OMASK31
};

#define DEVHAL_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "DEVHAL_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
