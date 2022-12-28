/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : IGNHAL                                                  */
/* !Description     : Ignition Driver Component                               */
/*                                                                            */
/* !File            : IGNHAL_Cfg.h                                            */
/* !Description     : IGNHAL configuration                                    */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;
 * <Revision>
 * %PID: P2017_BSW:0A192557.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef IGNHAL_CFG_H
#define IGNHAL_CFG_H

#include "IfxGtm_Def.h"
#include "IfxGtm_Typ.h"

#include "ADCHAL.h"
#include "CRKHAL.h"
#include "DGOHAL.h"
#include "IGNHAL_Typ.h"
#include "TDCHAL.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

#define IGNHAL_COILS_CHANNEL_NB 3U

/* Defines for Coil trims parameters                                          */
#define Icd_igbt_fdbk_gain_a IGNHAL_s8TrimGainOutput_CM_66  /* COIL A -> COIL 1 */
#define Icd_igbt_fdbk_gain_b IGNHAL_s8TrimGainOutput_CM_24  /* COIL B -> COIL 3 */
#define Icd_igbt_fdbk_gain_c IGNHAL_s8TrimGainOutput_CM_45  /* COIL C -> COIL 2 */
#define Icd_igbt_fdbk_gain_d IGNHAL_s8TrimGainOutput_CM_3   /* COIL D -> COIL 4 not used*/

/* !MComment: Defines for DGOHAL channel                                      */
#define IGNHAL_udtICD_A_DGO_CH DGOHAL_udtIGNITION_COIL_1  /* COIL A -> COIL 1 */
#define IGNHAL_udtICD_B_DGO_CH DGOHAL_udtIGNITION_COIL_3  /* COIL B -> COIL 3 */
#define IGNHAL_udtICD_C_DGO_CH DGOHAL_udtIGNITION_COIL_2  /* COIL C -> COIL 2 */
#define IGNHAL_udtICD_D_DGO_CH DGOHAL_udtIGNITION_COIL_4  /* COIL D -> COIL 4 not used  */

/* Defines for function tables                                                */
#define IGNHAL_FCT_COIL_CONDUCT_PROG_TABLE_LENGTH  IGNHAL_COILS_CHANNEL_NB
#define IGNHAL_FCT_READ_COUNTER_TABLE_LENGTH       IGNHAL_COILS_CHANNEL_NB

#define IGNHAL_snCOIL_A_Subblock_NAME     CRKHAL_snCOIL_A_CMD_ATOM
#define IGNHAL_snCOIL_B_Subblock_NAME     CRKHAL_snCOIL_B_CMD_ATOM
#define IGNHAL_snCOIL_C_Subblock_NAME     CRKHAL_snCOIL_C_CMD_ATOM

#define IGNHAL_snCOIL_A_CHANNEL_NAME      CRKHAL_snCOIL_A_CMD_CHANNEL
#define IGNHAL_snCOIL_B_CHANNEL_NAME      CRKHAL_snCOIL_B_CMD_CHANNEL
#define IGNHAL_snCOIL_C_CHANNEL_NAME      CRKHAL_snCOIL_C_CMD_CHANNEL

#define IGNHAL_snREF_TEETH_Subblock_NAME   CRKHAL_snIGN_REF_TEETH_ATOM
#define IGNHAL_snREF_TEETH_CHANNEL_NAME    CRKHAL_snIGN_REF_TEETH_CHANNEL

#define IGNHAL_snCOIL_A_DIAG_Subblock_NAME  IfxGtm_Atom_0
#define IGNHAL_snCOIL_A_DIAG_CHANNEL_NAME   IfxGtm_AtomCh_3
#define IGNHAL_snCOIL_B_DIAG_Subblock_NAME  IfxGtm_Atom_0
#define IGNHAL_snCOIL_B_DIAG_CHANNEL_NAME   IfxGtm_AtomCh_6
#define IGNHAL_snCOIL_C_DIAG_Subblock_NAME  IfxGtm_Atom_0
#define IGNHAL_snCOIL_C_DIAG_CHANNEL_NAME   IfxGtm_AtomCh_1

/* !Comment : Define for TDC offset configuration                             */
#define IGNHAL_u16TDC_OFFSET              TDCHAL_u16TDC_OFFSET

/* !Comment: Define for the min advance angle                                 */
/*           If value needs to change, don't forget to change MIN_ADV_ANGLE   */
/*           in ECU_IGNHAL.OIL                                                */
#define IGNHAL_u16MIN_ADV_ANGLE           (2304U) /* 36 crk deg               */

/* !Comment: Define for TDC reference tooth angle                             */
#define IGNHAL_u16TDC_TO_REF_TOOTH_ANGLE  IGNHAL_ku16TdcToRefAngle

/* !Comment: Define for CAMHAL channel                                        */
#define IGNHAL_udtCAMHAL_CH               CAMHAL_udtCH_CM_81

/* !Comment: Define for ADCHAL channel                                        */
#define IGNHAL_u8ADCHAL_CH                ADCHAL_IGN_BATT_VOLTAGE

/* !Comment : ADC channels configuration for coils                            */
/* !Comment : in mono-static mode                                             */
#define ANI_COIL_A                        ANI_IGN_COIL_1  /* COIL A -> COIL 1 */
#define ANI_COIL_B                        ANI_IGN_COIL_3  /* COIL B -> COIL 3 */
#define ANI_COIL_C                        ANI_IGN_COIL_2  /* COIL C -> COIL 2 */

                                                   
/* !Comment : Defines for generic DIAG TASK names                             */
#define IGNHAL_DIAG_COIL_A_OS_EVENT       OSTSK_S_DIAG_COIL_A
#define IGNHAL_DIAG_COIL_B_OS_EVENT       OSTSK_S_DIAG_COIL_B
#define IGNHAL_DIAG_COIL_C_OS_EVENT       OSTSK_S_DIAG_COIL_C

#define IGNHAL_INTERP_RESOL_COEF        32U   /*  equiv 3200ns                */
#define IGNHAL_DESIRED_RESOL_COEF       1U    /*  equiv 100ns                 */


/******************************************************************************/
/* DATA DECLARATIONS                                                          */
/******************************************************************************/

#define IGNHAL_START_SEC_CONST_UNSPECIFIED
#include "IGNHAL_MemMap.h"

extern IGNHAL_takpfCoilConductProg IGNHAL_akpfCoilConductProg[
   IGNHAL_FCT_COIL_CONDUCT_PROG_TABLE_LENGTH];
extern IGNHAL_takpfReadStartCounter IGNHAL_akpfReadStartCounter[
   IGNHAL_FCT_READ_COUNTER_TABLE_LENGTH];
extern IGNHAL_takpfCoilImmediateTrig IGNHAL_akpfCoilImmediateTrig[
   IGNHAL_FCT_COIL_CONDUCT_PROG_TABLE_LENGTH];

#define IGNHAL_STOP_SEC_CONST_UNSPECIFIED
#include "IGNHAL_MemMap.h"


#define IGNHAL_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "IGNHAL_MemMap.h"

extern volatile Ifx_GTM_ATOM_CH*  IGNHAL_pstrCOIL_A;
extern volatile Ifx_GTM_ATOM_AGC* IGNHAL_pstrAgcCOIL_A;
extern volatile Ifx_GTM_ATOM_CH*  IGNHAL_pstrCOIL_A_DIAG;
extern volatile Ifx_GTM_ATOM_AGC* IGNHAL_pstrAgcCOIL_A_DIAG;

extern volatile Ifx_GTM_ATOM_CH*  IGNHAL_pstrCOIL_B;
extern volatile Ifx_GTM_ATOM_AGC* IGNHAL_pstrAgcCOIL_B;
extern volatile Ifx_GTM_ATOM_CH*  IGNHAL_pstrCOIL_B_DIAG;
extern volatile Ifx_GTM_ATOM_AGC* IGNHAL_pstrAgcCOIL_B_DIAG;

extern volatile Ifx_GTM_ATOM_CH*  IGNHAL_pstrCOIL_C;
extern volatile Ifx_GTM_ATOM_AGC* IGNHAL_pstrAgcCOIL_C;
extern volatile Ifx_GTM_ATOM_CH*  IGNHAL_pstrCOIL_C_DIAG;
extern volatile Ifx_GTM_ATOM_AGC* IGNHAL_pstrAgcCOIL_C_DIAG;

extern volatile Ifx_GTM_ATOM_CH*  IGNHAL_pstrREF_TEETH;
extern volatile Ifx_GTM_ATOM_AGC* IGNHAL_pstrAgcREF_TEETH;

#define IGNHAL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "IGNHAL_MemMap.h"


/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define IGNHAL_START_SEC_CODE
#include "IGNHAL_MemMap.h"

void IGNHAL_vidCoilProg_COIL_A(uint16 u16Start);
void IGNHAL_vidCoilProg_COIL_B(uint16 u16Start);
void IGNHAL_vidCoilProg_COIL_C(uint16 u16Start);

void IGNHAL_vidImmediateTrig_COIL_A(void);
void IGNHAL_vidImmediateTrig_COIL_B(void);
void IGNHAL_vidImmediateTrig_COIL_C(void);

void IGNHAL_vidDiagIsr_COIL_A(uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo, uint16 IrqNotifVal);
void IGNHAL_vidDiagIsr_COIL_B(uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo, uint16 IrqNotifVal);
void IGNHAL_vidDiagIsr_COIL_C(uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo, uint16 IrqNotifVal);
void IGNHAL_vidDiagIsr_COIL_D(uint8 ModuleType, uint8 ModuleNo, uint8 ChannelNo, uint16 IrqNotifVal);

uint16 IGNHAL_u16ReadStartCntr_COIL_A(void);
uint16 IGNHAL_u16ReadStartCntr_COIL_B(void);
uint16 IGNHAL_u16ReadStartCntr_COIL_C(void);

#define IGNHAL_STOP_SEC_CODE
#include "IGNHAL_MemMap.h"


#endif /* IGNHAL_CFG_H */

/*------------------------------ end of file ---------------------------------*/
