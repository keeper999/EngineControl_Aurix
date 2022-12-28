/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : STUB                                                    */
/* !Description     : Stub of HAL components                                  */
/*                                                                            */
/* !File            : INJ_GATEWAY.h                                           */
/* !Description     : Gateway for INJ component                               */
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
 * %PID:%
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef INJ_GATEWAY_H
#define INJ_GATEWAY_H

#include "Std_Limits.h"
#include "Std_Types.h"
#include "INJHAL.h"


/******************************************************************************/
/* DEFINES */
/******************************************************************************/

/*-------------- Channel --------------*/
#define INJ_HAL_ALL_CYLINDER           INJHAL_u8ALL_CYLINDERS   /* 0xFF */
#define INJ_HAL_CYLINDER_A             CH_INJ_1_GDI
#define INJ_HAL_CYLINDER_B             CH_INJ_3_GDI
#define INJ_HAL_CYLINDER_C             CH_INJ_2_GDI
#define INJ_HAL_CYLINDER_D             INJ_HAL_CYLINDER_4

/*-------Stub a Supprimer----------*/
#define Ext_stTypElCmdInjrHiPres_SC 0
#define Ext_stTypElCmdInjrLoPres_SC 1
#define Ext_stTypElCmdInjrNom_SC 2
#define Ext_stTypElCmdInjrOverPres_SC 3

/*-------------- Time resolution --------------*/
#define INJHAL_u16TMR_RES_TO_100_NS    64

/*-------------- Injection Pulse --------------*/
#define INJ_HAL_INJECTION_PULSE_1      INJHAL_u8INJECTION_PULSE_1    /* 0x00 */
#define INJ_HAL_INJECTION_PULSE_2      INJHAL_u8INJECTION_PULSE_2    /* 0x01 */

/*-------------- Injection Mode --------------*/
#define INJ_HAL_MODE_1_INJ             INJHAL_u8MODE_1_INJECTION     /* 0x01 */
#define INJ_HAL_MODE_2_INJ             INJHAL_u8MODE_2_INJECTIONS    /* 0x02 */

/*----------- Injection Mask (Update, Inhibit, Seq PreInj Status) -----------*/
#define INJHAL_ENABLE_ALL_INJ          INJHAL_bfENABLE_ALL_INJ       /* 0x00 */
#define INJHAL_INHIB_ALL_INJ           INJHAL_bfINHIB_ALL_INJ        /* 0xFF */

#define INJHAL_ENABLE_INJ              0    /* 0 */
#define INJHAL_INHIB_INJ               1    /* 1 */

#define INJHAL_INJ_A_MASK              INJ_HAL_CYLINDER_1_MASK   /* 0x01 */
#define INJHAL_INJ_B_MASK              INJ_HAL_CYLINDER_3_MASK   /* 0x02 */
#define INJHAL_INJ_C_MASK              INJ_HAL_CYLINDER_2_MASK   /* 0x04 */
#define INJHAL_INJ_D_MASK              INJ_HAL_CYLINDER_4_MASK   /* 0x08 */

/*-------------- FG PreInj Status --------------*/
#define INJHAL_PREINJ_ACT              INJHAL_enuPREINJ_ACT    /* 0x01 */
#define INJHAL_PREINJ_END              INJHAL_enuPREINJ_END    /* 0x02 */
#define INJHAL_PREINJ_NONE             INJHAL_enuPREINJ_NONE   /* 0x00 */

/******************************************************************************/
/* MACRO FUNCTIONS */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/* !Description : Initialize internal variables of INJHAL component           */
/* !Number      : 0x00                                                        */
/* !Reference   :                                                             */
/*                                                                            */
/* !LastAuthor  : Yousf Badr                                                  */
/******************************************************************************/
#define InjHALInit()\
   INJHAL_vidInit()

/******************************************************************************/
/*                                                                            */
/* !Description : Activate the INJHAL component and start pre-injection stage */
/* !Number      : 0x01                                                        */
/* !Reference   :                                                             */
/*                                                                            */
/* !LastAuthor  : LBAG                                                        */
/******************************************************************************/
#define InjHALEnable() \
   INJHAL_vidEnable(MPI_1_TO_4)

/******************************************************************************/
/*                                                                            */
/* !Description : Disable INJHAL component                                    */
/* !Number      : 0x02                                                        */
/* !Reference   :                                                             */
/*                                                                            */
/* !LastAuthor  : LBAG                                                        */
/******************************************************************************/
#define InjHALDisable() \
   INJHAL_vidDisable(MPI_1_TO_4)

/******************************************************************************/
/*                                                                            */
/* !Description : Force the update of injection times and angles              */
/* !Number      : 0x03                                                        */
/* !Reference   :                                                             */
/*                                                                            */
/* !LastAuthor  : LBAG                                                        */
/******************************************************************************/
#define InjHALUpdate() \
   (uint16)INJHAL_bfUpdate(MPI_1_TO_4)


/******************************************************************************/
/*                                                                            */
/* !Description : update the principal and secondary injection times          */
/* !Number      : 0x04                                                        */
/* !Reference   :                                                             */
/*                                                                            */
/* !LastAuthor  : Yousf Badr                                                  */
/******************************************************************************/
#define InjHALWriteTime(u8Channel, u8Injection_number, u32Time) \
   INJHAL_vidWriteTime((u8Channel), \
                       (u8Injection_number), \
                       (u32Time)*INJHAL_u16TMR_RES_TO_100_NS)

/******************************************************************************/
/*                                                                            */
/* !Description : update the principal and secondary injection phases         */
/* !Number      : 0x05                                                        */
/* !Reference   :                                                             */
/*                                                                            */
/* !LastAuthor  : Yousf Badr                                                  */
/******************************************************************************/
#define InjHALWriteAngle(u8Channel, u8Injection_number, u16Angle) \
   INJHAL_vidWriteAngle((u8Channel), (u8Injection_number), (u16Angle))

/******************************************************************************/
/*                                                                            */
/* !Description : shall authorize or disable injections on selected cylinder  */
/* !Number      : 0x06                                                        */
/* !Reference   :                                                             */
/*                                                                            */
/* !LastAuthor  : SGUE                                                        */
/******************************************************************************/
#define InjHALInhibit(u8Disable_mask) \
   INJHAL_vidInhibit(MPI_1_TO_4, (INJHAL_tbfInhibitMask)(u8Disable_mask))

/******************************************************************************/
/*                                                                            */
/* !Description :  return TRUE if at least one injector have been opened since*/
/*                 the last reset or the last call to                         */
/*                 InjHALResetInjectionStarted , else FALSE.                  */
/* !Number      : 0x07                                                        */
/* !Reference   :                                                             */
/*                                                                            */
/* !LastAuthor  : LBAG                                                        */
/******************************************************************************/
#define InjHALInjectionStarted() \
   INJHAL_bInjectionStarted(MPI_1_TO_4)

/******************************************************************************/
/*                                                                            */
/* !Description : change the injection mode of the desired “Channel” into one */
/*                injection per cycle mode or two injections per cycle mode   */
/*                depending on the “Mode” parameter                           */
/* !Number      : 0x08                                                        */
/* !Reference   :                                                             */
/*                                                                            */
/* !LastAuthor  : LBAG                                                        */
/******************************************************************************/
#define InjHALWriteMode(u8Channel, u8Mode) \
   INJHAL_vidWriteMode(MPI_1_TO_4, (u8Channel), (u8Mode))

/******************************************************************************/
/*                                                                            */
/* !Description : provide the full group pre-injection time, applied to the   */
/*                three injectors                                             */
/* !Number      : 0x09                                                        */
/* !Reference   :                                                             */
/*                                                                            */
/* !LastAuthor  : LBAG                                                        */
/******************************************************************************/
#define InjHALWriteFGPreInjTime(u32Time) \
   INJHAL_vidWriteFGPreInjTime(MPI_1_TO_4, \
                  (u32Time) * INJHAL_u16TMR_RES_TO_100_NS)

/******************************************************************************/
/*                                                                            */
/* !Description : authorize the full group pre-injection                      */
/* !Number      : 0x0A                                                        */
/* !Reference   :                                                             */
/*                                                                            */
/* !LastAuthor  : LBAG                                                        */
/******************************************************************************/
#define InjHALEnableFGPreInj() \
   INJHAL_vidEnableFGPreInj(MPI_1_TO_4)

/******************************************************************************/
/*                                                                            */
/* !Description : disable the full group pre-injection                        */
/* !Number      : 0x0B                                                        */
/* !Reference   :                                                             */
/*                                                                            */
/* !LastAuthor  : LBAG                                                        */
/******************************************************************************/
#define InjHALDisableFGPreInj() \
   INJHAL_vidDisableFGPreInj(MPI_1_TO_4)

/******************************************************************************/
/*                                                                            */
/* !Description : return the full group pre-injection status                  */
/* !Number      : 0x0C                                                        */
/* !Reference   :                                                             */
/*                                                                            */
/* !LastAuthor  : LBAG                                                        */
/******************************************************************************/
#define InjHALReadFGPreInjStatus() \
   (uint8)INJHAL_enuReadFGPreInjStatus(MPI_1_TO_4)

/******************************************************************************/
/*                                                                            */
/* !Description : provide the pre-injection waiting angle (the same for full  */
/*                group and sequential), applied to the three injectors       */
/* !Number      : 0x0D                                                        */
/* !Reference   :                                                             */
/*                                                                            */
/* !LastAuthor  : LBAG                                                        */
/******************************************************************************/
#define InjHALWriteAngleBeforePreInj(u16Angle) \
   INJHAL_vidWriteAngleBeforePreInj(MPI_1_TO_4, (u16Angle))

/******************************************************************************/
/*                                                                            */
/* !Description : cancel the injector A angular alarm to avoid phase problems */
/*                when the synchronisation is found while the component is    */
/*                waiting the angle provided by InjHALWriteAngleBeforePreIn   */
/* !Number      : 0x0E                                                        */
/* !Reference   :                                                             */
/*                                                                            */
/* !LastAuthor  : LBAG                                                        */
/******************************************************************************/
#define InjHALCancelAlarmInjA() \
   INJHAL_vidCancelInjGroupAlarms(MPI_1_TO_4)

/******************************************************************************/
/*                                                                            */
/* !Description : authorize the sequential pre-injection                      */
/* !Number      : 0x0F                                                        */
/* !Reference   :                                                             */
/*                                                                            */
/* !LastAuthor  : LBAG                                                        */
/******************************************************************************/
#define InjHALEnableSeqPreInj() \
   INJHAL_vidEnableSeqPreInj(MPI_1_TO_4)

/******************************************************************************/
/*                                                                            */
/* !Description : disable the sequential pre-injection                        */
/* !Number      : 0x10                                                        */
/* !Reference   :                                                             */
/*                                                                            */
/* !LastAuthor  : LBAG                                                        */
/******************************************************************************/
#define InjHALDisableSeqPreInj() \
   INJHAL_vidDisableSeqPreInj(MPI_1_TO_4)

/******************************************************************************/
/*                                                                            */
/* !Description : provide the waiting angle before starting the sequential    */
/*                pre-injection to a given cylinder                           */
/* !Number      : 0x11                                                        */
/* !Reference   :                                                             */
/*                                                                            */
/* !LastAuthor  : LBAG                                                        */
/******************************************************************************/
#define InjHALWriteSeqPreInjAngle(u8Channel, u16Angle) \
   INJHAL_vidWriteSeqPreInjAngle(MPI_1_TO_4, \
                                 (u8Channel), \
                                 (u16Angle))

/******************************************************************************/
/*                                                                            */
/* !Description : provide the sequential pre-injection time to given cylinder */
/* !Number      : 0x12                                                        */
/* !Reference   :                                                             */
/*                                                                            */
/* !LastAuthor  : LBAG                                                        */
/******************************************************************************/
#define InjHALWriteSeqPreInjTime(u8Channel, u32Time) \
   INJHAL_vidWriteSeqPreInjTime(MPI_1_TO_4, \
                                (u8Channel), \
                                (u32Time) * INJHAL_u16TMR_RES_TO_100_NS)

/******************************************************************************/
/*                                                                            */
/* !Description : return the sequential pre-injection status of injectors.    */
/* !Number      : 0x13                                                        */
/* !Reference   :                                                             */
/*                                                                            */
/* !LastAuthor  : SGUE                                                        */
/******************************************************************************/
#define InjHALReadSeqPreInjStatus() \
   ((uint8) INJHAL_bfReadSeqPreInjStatus(MPI_1_TO_4))

/******************************************************************************/
/*                                                                            */
/* !Description : reset the variable describing if at least one injection has */
/*                been done during the trip so that the InjHALInjectionStarted*/
/*                API returns FALSE if called just after                      */
/*                InjHALResetInjectionStarted                                 */
/* !Number      : 0x14                                                        */
/* !Reference   :                                                             */
/*                                                                            */
/* !LastAuthor  : LBAG                                                        */
/******************************************************************************/
#define InjHALResetInjectionStarted() \
   INJHAL_vidResetInjectionStarted(MPI_1_TO_4)


#endif /* INJ_GATEWAY_H */

/*-------------------------------- end of file -------------------------------*/