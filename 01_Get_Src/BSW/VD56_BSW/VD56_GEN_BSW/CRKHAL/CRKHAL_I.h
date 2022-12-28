/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : CRKHAL                                                  */
/* !Description     : CRKHAL Component                                        */
/*                                                                            */
/* !File            : CRKHAL_I.h                                              */
/* !Description     : Component internal macros                               */
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
 * %PID: P2017_BSW:A18543.A-SRC;7 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef CRKHAL_I_H
#define CRKHAL_I_H

#include "CRKHAL.h"
#include "CRKHAL_Cfg.h"
#include "CRKHAL_Cfg_I.h"
#include "CRKHAL_I.h"
#include "CRKHAL_L.h"
#include "IfxGtm_CcuApi.h"
#include "IfxGtm_Tbu_Dpll.h"
#include "IfxGtm_Mcs.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/* !MComment: Channel B interrupts                                            */
#define CRKHAL_snSTALLING_ATUDRV_INT_CH     ATU_B_EV_PERIOD_LIM
#define CRKHAL_snTOOTH_ATUDRV_INT_CH        ATU_B_EV_MAX_CNT_NB
#define CRKHAL_snLONG_TOOTH_ATUDRV_INT_CH   ATU_B_MUL_CLK_CNT_EV_LONG_LIM

/* !Comment: Max time to be converted into angle                              */

#define CRKHAL_u32MAX_TIME_TO_CONVERT (300000U)
/* 60000000/CRKHAL_u16TOOTH_TIMER_RESOLUTION */
/*   ( (TDCHAL_u16TDC_OFFSET != UINT32_MIN) \
   ? (uint32)(UINT32_MAX / TDCHAL_u16TDC_OFFSET) \
   : (uint32)UINT32_MIN)
*/

/* Max Cnt for GLI to lock */
#define CRKHAL_u8MAX_CNT_TO_GLILOCK (4U)

/* Max Cnt for change of Mind */
#define CRKHAL_u8MAX_CNT_TO_FWDDir (1U)

/* Global Teeth Offset Correction Factor for adjusting Angle */
#define CRKHAL_u32GLB_TEETH_OFFSET_CORRECTION (0U)

/* Bi Direction THMI load/reset threshold correction */
#define CRKHAL_u8BiDir_THMI_THRESHOLD_CORRECTION (10U)

/******************************************************************************/
/* INTERRUPT DECLARATIONS                                                     */
/******************************************************************************/
/* !MComment: IT Type = ISR1                                                  */
/*#pragma interrupt(CRKHAL_ToothManagementMonitor)
#pragma interrupt(CRKHAL_vidLongToothDetection)
#pragma interrupt(CRKHAL_vidStallDetection)*/

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* Private Services                                                           */
/******************************************************************************/

/******************************************************************************/
/* !FuncName    : CRKHAL_vidInitTimCh                                         */
/* !Description : Initializes selected TIM channel to TIM variables.          */
/*                CRKHAL_Tim0CrkToDpll - TIM0CH0                              */
/*                CRKHAL_Tim0CrkToMcs - TIM0CH1                               */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidInitTimCh() IfxGtm_vidInitTimCh()

/******************************************************************************/
/* !Description : Disables the CRKHAL related interrupt.                      */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/* !Number      : 0x00                                                        */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidDISABLE_INTERRUPT(snItChannel) \
   GTM_DISABLE_INTERRUPT_##snItChannel

/******************************************************************************/
/* !Description : Enables the CRKHAL related interrupt.                       */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/* !Number      : 0x01                                                        */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidENABLE_INTERRUPT(snItChannel) \
   CRKHAL_vidCLEAR_INTERRUPT(snItChannel); \
   GTM_ENABLE_INTERRUPT_##snItChannel

/******************************************************************************/
/* !Description : Clears the CRKHAL related interrupt flag.                   */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/* !Number      : 0x02                                                        */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidCLEAR_INTERRUPT(snItChannel) \
   GTM_CLEAR_NOTIFY_##snItChannel

/******************************************************************************/
/* !Description : Clears the CRKHAL related interrupt flag.                   */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/* !Number      : 0x02                                                        */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_GetIRQ_NOTIFY(snItChannel) \
   GTM_IRQ_NOTIFY_##snItChannel

/******************************************************************************/
/* !Description : checks Interrupt Enable or Disable Status.                  */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/* !Number      : 0x02                                                        */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_GetIRQ_ENABLE_STATUS(snItChannel) \
   GET_GTM_INTERRUPT_ENABLE_STATUS_##snItChannel

/******************************************************************************/
/*                                                                            */
/* !Description : Reads ATOM configurations wrt to configured ALARM           */
/* !Number      : 0x01                                                        */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/*                                                                            */
/******************************************************************************/

#define CRKHAL_snGET_ATOM_FROM_CFG(snAlarmName) \
   CRKHAL_sn##snAlarmName##_ATOM

#define CRKHAL_snGET_ATOM_Channel_FROM_CFG(snAlarmName) \
   CRKHAL_sn##snAlarmName##_CHANNEL

/******************************************************************************/
/* !Description : Reloads the tooth interrupt.                                */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/* !Number      : 0x03                                                        */
/*                                                                            */
/******************************************************************************/
/* #define CRKHAL_vidTOOTH_RELOAD_IT(snOperator,u8Value) (0) 				  */

/******************************************************************************/
/* !Description : Sets a value for Time Noise Canceler.                       */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/* !Number      : 0x04                                                        */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidWriteNoiseCanceler(u32Value) IfxGtm_vidTimNoiseConfig(u32Value)

/******************************************************************************/
/*                                                                            */
/* !Description : Reads the current angle counter of TBU [Relative Angle]     */
/*            This is used for Private Use Only.                              */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/* !Number      : 0x09                                                        */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidREAD_ANGULAR_COUNTER() GTM_TBU_ANGLE

/******************************************************************************/
/* !Description : Needed actions for Synchronisation loss                     */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/* !Number      : 0x0A                                                        */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidSYNC_LOSS() \
do \
{ \
   CRANKHAL_vidSET_CRK_TIMEOUT(CRKHAL_u32LongToothStalDetThd); \
   CRKHAL_enuCylinderNumber     = (CRKHAL_tenuCylinderNumber)CRKHAL_udtUNKNOWN_CYLINDER; \
   CRKHAL_bSynchronized         = (boolean)FALSE; \
   CRKHAL_bEngSynchronized      = (boolean)FALSE; \
   CRKHAL_bSingularityDetected  = (boolean)FALSE; \
   CRKHAL_bLtooFaultOccur       = (boolean)FALSE; \
   \
   \
   CRKHAL_u16TeethAftrLastSyncLoss = (uint16)UINT16_MIN; \
/*   CRKHAL_vidRESET_SYNC_CRITERIA(); \ */ \
   CRKHAL_bDesynchroThdEnabled = (boolean)FALSE; \
   CRKHAL_u32ToothMaxDuration  = (uint32)UINT32_MAX; \
   *CRKHAL_pu32McsTeeAfrLastSyLos  = (uint32)UINT32_MIN;\
} \
while (0)

/******************************************************************************/
/* !Description : Needed actions for Run to Stall transition                  */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/* !Number      : 0x0B                                                        */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidRUN_TO_STALL() \
do \
{ \
   CRKHAL_bRunning = (boolean)FALSE; \
} \
while (0)

/******************************************************************************/
/* !Description : Needed actions for signal loss                              */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/* !Number      : 0x0C                                                        */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidSIGNAL_LOSS() \
do \
{ \
   CRKHAL_vidSTOP_ANG_POS_COUNTER(); \
   \
   CRKHAL_bDetected   = (boolean)FALSE; \
   \
   /* !Comment: Disable Stalling Detection                                  */ \
   CRKHAL_vidDISABLE_INTERRUPT(ENG_STALL); \
} \
while (0)

/******************************************************************************/
/* !Description :Tries reading the cylinder number using "snMethod", if       */
/*               it failed CRKHAL_enuCylinderNumber remains as                */
/*               CRKHAL_udtUNKNOWN_CYLIDER.                                   */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/* !Number      : 0x0E                                                        */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidMETHOD_SYNC( \
\
   snMethod,      /* !Comment: The synchronisation method                   */ \
                  /* !Range: CRKHAL_snCAMHAL, CRKHAL_snEPMSRV,...           */ \
   snParentMethod,/* !Comment: The parent component of synchronisation      */ \
                  /* !Range: CRKHAL_snCAMHAL, CRKHAL_snEPMSRV,....          */ \
   udtStatus      /* !Comment: The status of                                */ \
                  /*           snMethod##_udtReadCylinderNumber             */ \
                  /* !Range: E_OK, E_NOT_OK                                 */ \
) \
do \
{ \
   CRKHAL_udtGET_CYL_NB_TYPE(snParentMethod) enuCylinderNumber; \
   \
   (udtStatus) = \
      CRKHAL_udtMETHOD_READ_CYL_NB(snMethod, &enuCylinderNumber); \
   if ((udtStatus) == (Std_ReturnType)E_OK) \
   { \
      CRKHAL_vidDET_CYL_NB(snParentMethod, \
                           enuCylinderNumber, \
                           CRKHAL_enuCylinderNumber); \
   } \
} \
while (0)

/******************************************************************************/
/* !Description : Determine the cylinder number to synchronize on depending   */
/*                on the number of cylinders "snNbCylinders" and the used     */
/*                "snMethod"                                                  */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/* !Number      : 0x0F                                                        */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
#define CRKHAL_vidDET_CYL_NB( \
\
   snMethod,        /* !Comment: Synchronization method name                */ \
                    /* !Range: CRKHAL_snCAMHAL, CRKHAL_snEPMSRV,...         */ \
   enuInputCylNb,   /* !Comment: The cylinder number as returned from the   */ \
                    /*           synchronization method.                    */ \
                    /* !Range: "snMethod"_FIRST_CYLINDER,                   */ \
                    /*         "snMethod"_SECOND_CYLINDER,...               */ \
   enuCrkCylNb      /* !Comment: The output detected CRKHAL cylinder number */ \
) \
   M1_CRKHAL_vidDET_CYL_NB(snMethod, enuInputCylNb, enuCrkCylNb)

   #define M1_CRKHAL_vidDET_CYL_NB(snMethod, enuInputCylNb, enuCrkCylNb) \
      M2_CRKHAL_vidDET_CYL_NB( \
         CRKHAL_vidGET_CYL_NB(snMethod, FIRST_CYLINDER), \
         CRKHAL_vidGET_CYL_NB(snMethod, SECOND_CYLINDER), \
         CRKHAL_vidGET_CYL_NB(snMethod, THIRD_CYLINDER), \
         CRKHAL_vidGET_CYL_NB(snMethod, FOURTH_CYLINDER), \
         CRKHAL_vidGET_CYL_NB(snMethod, UNKNOWN_CYLINDER), \
         enuInputCylNb, \
         enuCrkCylNb)

      #define M2_CRKHAL_vidDET_CYL_NB(udtFirstCyl, \
                                      udtSecondCyl, \
                                      udtThirdCyl, \
                                      udtFourthCyl, \
                                      udtUnknownCyl, \
                                      enuInputCylNb, \
                                      enuCrkCylNb) \
         M3_CRKHAL_vidDET_CYL_NB(udtFirstCyl, \
                                 udtSecondCyl, \
                                 udtThirdCyl, \
                                 udtFourthCyl, \
                                 udtUnknownCyl, \
                                 enuInputCylNb, \
                                 enuCrkCylNb)

      #define M3_CRKHAL_vidDET_CYL_NB(udtFirstCyl, \
                                      udtSecondCyl, \
                                      udtThirdCyl, \
                                      udtFourthCyl, \
                                      udtUnknownCyl, \
                                      enuInputCylNb, \
                                      enuCrkCylNb) \
      do \
      { \
         switch (enuInputCylNb) \
         { \
            case (udtFirstCyl): \
               if (CRKHAL_kbSyncOnFirstCylEn != (boolean)FALSE) \
               { \
                 (enuCrkCylNb) = (CRKHAL_tenuCylinderNumber)CRKHAL_udtFIRST_CYLINDER; \
               } \
               else \
               { \
                 (enuCrkCylNb) = (CRKHAL_tenuCylinderNumber)CRKHAL_udtUNKNOWN_CYLINDER; \
               } \
               break; \
            \
            case (udtSecondCyl): \
               if (CRKHAL_kbSyncOnSecondCylEn != (boolean)FALSE) \
               { \
                 (enuCrkCylNb) = (CRKHAL_tenuCylinderNumber)CRKHAL_udtSECOND_CYLINDER; \
               } \
               else \
               { \
                 (enuCrkCylNb) = (CRKHAL_tenuCylinderNumber)CRKHAL_udtUNKNOWN_CYLINDER; \
               } \
               break; \
            \
            case (udtThirdCyl): \
               if (CRKHAL_kbSyncOnThirdCylEn != (boolean)FALSE) \
               { \
                 (enuCrkCylNb) = (CRKHAL_tenuCylinderNumber)CRKHAL_udtTHIRD_CYLINDER; \
               } \
               else \
               { \
                 (enuCrkCylNb) = (CRKHAL_tenuCylinderNumber)CRKHAL_udtUNKNOWN_CYLINDER; \
               } \
               break; \
            \
            case (udtFourthCyl): \
               if (CRKHAL_kbSyncOnFourthCylEn != (boolean)FALSE) \
               { \
                 (enuCrkCylNb) = (CRKHAL_tenuCylinderNumber)CRKHAL_udtFOURTH_CYLINDER; \
               } \
               else \
               { \
                 (enuCrkCylNb) = (CRKHAL_tenuCylinderNumber)CRKHAL_udtUNKNOWN_CYLINDER; \
               } \
               break; \
            \
            case (udtUnknownCyl): \
               (enuCrkCylNb) = (CRKHAL_tenuCylinderNumber)CRKHAL_udtUNKNOWN_CYLINDER; \
               break; \
            \
            default: \
               (enuCrkCylNb) = (CRKHAL_tenuCylinderNumber)CRKHAL_udtUNKNOWN_CYLINDER; \
               SWFAIL_vidSoftwareErrorHook(); \
               break; \
         } \
      } \
      while (0)

/******************************************************************************/
/* !Description : Returns the cylinder numbers depending on the desired       */
/*                "snMethod"                                                  */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/* !Number      : 0x10                                                        */
/*                                                                            */
/* !LastAuthor  : A. Sallab                                                   */
/******************************************************************************/
#define CRKHAL_vidGET_CYL_NB( \
\
   snMethod,   /* !Comment: Used method to get the cylinder number          */ \
               /* !Range  : CRKHAL_snCAMHAL, CRKHAL_snEPMSRV,...            */ \
   snCylinder  /* !Comment: Cylinder number                                 */ \
               /* !Range  : FIRST_CYLINDER, SECOND_CYLINDER, THIRD_CYLINDER */ \
               /*           FOURTH_CYLINDER, UNKNOWN_CYLINDER               */ \
) \
   M1_CRKHAL_vidGET_CYL_NB(snMethod, snCylinder)

   #define M1_CRKHAL_vidGET_CYL_NB(snMethod, snCylinder) \
      snMethod##_udt##snCylinder

/******************************************************************************/
/* !Description :Recovers the read cylinder number function of the requested  */
/*               method                                                       */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/* !Number      : 0x11                                                        */
/*                                                                            */
/* !LastAuthor  : A. Sallab                                                   */
/******************************************************************************/
#define CRKHAL_udtMETHOD_READ_CYL_NB( \
\
   snMethod,     /* !Comment: Used method to get the cylinder number        */ \
                 /* !Range  : CRKHAL_snCAMHAL, CRKHAL_snEPMSRV,...          */ \
   enuCylinderNb /* !Comment: The returned cylinder number by the component */ \
) \
   M1_CRKHAL_udtMETHOD_READ_CYL_NB(snMethod, enuCylinderNb)

   #define M1_CRKHAL_udtMETHOD_READ_CYL_NB(snMethod, enuCylinderNb) \
      CRKHAL_udtMETHOD_READ_CYL_NB_##snMethod(enuCylinderNb)

/******************************************************************************/
/* !Description : Recovers the cylinder number type according to "snMethod"   */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/* !Number      : 0x12                                                        */
/*                                                                            */
/* !LastAuthor  : A. Sallab                                                   */
/******************************************************************************/
#define CRKHAL_udtGET_CYL_NB_TYPE( \
\
   snMethod      /* !Comment: Used method to get the cylinder number        */ \
                 /* !Range  : CRKHAL_snCAMHAL, CRKHAL_snEPMSRV,...          */ \
) \
   M1_CRKHAL_udtGET_CYL_NB_TYPE(snMethod)

   #define M1_CRKHAL_udtGET_CYL_NB_TYPE(snMethod) \
      snMethod##_tenuCylinderNumber

/******************************************************************************/
/* !Description : Sets the enuCrkCylNb to the default cylinder                */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/* !Number      : 0x13                                                        */
/*                                                                            */
/* !LastAuthor  : M. Sabry                                                    */
/******************************************************************************/
#define CRKHAL_udtSET_DEFAULT_CYL(enuCrkCylNb) \
do \
{ \
   switch (CRKHAL_ku8NumberOfCylinders) \
   { \
      case CRKHAL_u8THREE_CYLINDERS: \
         (enuCrkCylNb) = (CRKHAL_tenuCylinderNumber)CRKHAL_DEFAULT_CYL_THREE_CYL; \
         break; \
   \
      case CRKHAL_u8FOUR_CYLINDERS: \
         (enuCrkCylNb) = (CRKHAL_tenuCylinderNumber)CRKHAL_DEFAULT_CYL_FOUR_CYL; \
         break; \
   \
      default: \
         (enuCrkCylNb) = (CRKHAL_tenuCylinderNumber)CRKHAL_udtUNKNOWN_CYLINDER; \
         SWFAIL_vidSoftwareErrorHook(); \
         break; \
   } \
} \
while (0)

/******************************************************************************/
/* !Description : Needed actions for Synchronisation Criteria Reset           */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/* !Number      : 0x14                                                        */
/*                                                                            */
/******************************************************************************/
/*#define CRKHAL_vidRESET_SYNC_CRITERIA() () 
This function not used since all tooth duration is caluclated depedent on HW
CRKHAL_u8NbTeethWithoutLtoo - this variable used till sync, we don't require
any more.
*/

/******************************************************************************/
/* !Description : Enables the TBU Angular & Timer Counter                     */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/* !Number      : 0x15                                                        */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidENABLE_ANG_TMR_CNT() vidENABLE_TBU_ANG_TMR_CNTR()

/******************************************************************************/
/* !Description : Re Enables the Angle & Timer counter if disabled            */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/* !Number      : 0x15                                                        */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidREENABLE_ANG_TMR_CNT() IfxGtm_vidTbuReEnable()

/******************************************************************************/
/* !Description : Disables the TBU Angular & Timer Counter                    */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/* !Number      : 0x16                                                        */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidDISABLE_ANG_TMR_CNT() vidDISABLE_TBU()

/******************************************************************************/
/* !Description : Stops the TBU Angular counter                               */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/* !Number      : 0x19                                                        */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidSTOP_ANG_POS_COUNTER() vidDISABLE_TBU_ANG_CNTR()

/******************************************************************************/
/* !Description : Starts the TBU Angular counter                              */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/* !Number      : 0x1A                                                        */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidSTART_ANG_POS_COUNTER() vidENABLE_TBU_ANG_CNTR()

/******************************************************************************/
/* !Description : Reads level of crk input signal                             */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/* !Number      : 0x1D                                                        */
/*                                                                            */
/******************************************************************************/
/*#define CRKHAL_bREAD_CRK_INPUT_SIGNAL() CRKHAL_bReadInputSgn1()*/

/******************************************************************************/
/* !Description : Initialize Crank Input pin configuration                    */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/* !Number      : 0x1E                                                        */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidLINK_PORT_TO_TIM(u8CrkInput) GTM_TIM0CH0_PIN_CONFIG(u8CrkInput)

/******************************************************************************/
/* !Description : DPLL Number of Recent TRIGGER Events  */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/* !Number      : 0x1F                                                        */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_udtNominalLenPrevTooth() snGET_DPLL_NUTC_SYN_old()

/******************************************************************************/
/* !Description : Configures the DPLL DPLL Number of recent TRIGGER events used*/
/*  			   for calculations (mod 2*(TNU +1-SYN_NT))  				  */
/******************************************************************************/
#define CRKHAL_vidSET_DPLL_NUTC_NUTE(Val) snSET_DPLL_NUTC_NUTE(Val)

/******************************************************************************/
/* !Description : Reads Actual signal TRIGGER time stamp register             */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/* !Number      : 0x23                                                        */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_u32READ_TOOTH_EDGE_DATE() (snGET_GTM_DPLL_TS())

/******************************************************************************/
/* !Description : Reads the Previous signal TRIGGER time stamp register       */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/* !Number      : 0x23                                                        */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_u32READ_TOOTH_EDGE_DATE_OLD() (snGET_GTM_DPLL_TS_OLD())

/******************************************************************************/
/* !Description : Reads the current level of the signal                       */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/* !Number      : 0x23                                                        */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_bREAD_EDGE_LEVEL() (IfxGtm_ubTimReadInputSgn(CRKHAL_udtCRKHAL_CH))

/******************************************************************************/
/* !Description : Initializes the duration of bidir significative pulse       */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/* !Number      : 0x24                                                        */
/*                                                                            */
/******************************************************************************/
/* #define CRKHAL_vidWRITE_BIDIR_PULSE_DUR(u32PulseDuration) \
   CcuBSLWrite(TOOTH_DIAG_EDGE_TIME, u32PulseDuration);                       */

/******************************************************************************/
/* !Description : Enables TIM                                                 */
/* !Reference   : V                                                           */
/* !Number      : 0x                                                          */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidEnableDetection() IfxGtm_vidTimEnableDetection()

/******************************************************************************/
/* !Description : Disable TIM                                                 */
/* !Reference   : V                                                           */
/* !Number      : 0x                                                          */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidDisableTim() IfxGtm_vidTimDisableDetection()

/******************************************************************************/
/* !Description : Disable Time out                                            */
/* !Reference   : V                                                           */
/* !Number      : 0x                                                          */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidDisableTimeOut() IfxGtm_vidDisableTimeOut()

/******************************************************************************/
/* !Description : returns tooth period                                        */
/* !Reference   : V                                                           */
/* !Number      : 0x                                                          */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_snGET_TOOTH_PERIOD() IfxGtm_snTimToothPeriod()

/******************************************************************************/
/* !Description : Returns the edge timestamp                                  */
/* !Reference   : V                                                           */
/* !Number      : 0x                                                          */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_snGET_EDGE_TIMESTAMP() IfxGtm_snTimEdgeTimeStamp()

/******************************************************************************/
/* !Description : gets last tooth count                                       */
/* !Reference   : V                                                           */
/* !Number      : 0x                                                          */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_snGetCurrentToothCount()   IfxGtm_u8GetTimToMcsToothCount()

/******************************************************************************/
/* !FuncName    : CRANKHAL_vidSET_CRK_TIMEOUT                                 */
/* !Description : Loads Time out        									  */
/******************************************************************************/
#define CRANKHAL_vidSET_CRK_TIMEOUT(Value) GTM_TIM_CAPTURE_TIMEOUT(Value)

/******************************************************************************/
/* !FuncName    : CRANKHAL_vidSET_CRANKOFF_DELAY                              */
/* !Description : Load Crank off Delay value        						  */
/******************************************************************************/
#define CRANKHAL_vidSET_CRANKOFF_DELAY(Value) GTM_TIM_PROCESS_TIMEOUT(Value)

/******************************************************************************/
/* !FuncName    : CRKHAL_vidSET_NTI                                           */
/* !Description : Load NTI value (Number of active TRIGGER events to interrupt)*/
/******************************************************************************/
#define CRKHAL_vidSET_NTI(Val)   (vidSET_DPLL_NTICNT_NTICNT(Val))

/******************************************************************************/
/* !FuncName    : CRKHAL_snGET_NTI                                            */
/* !Description : Get NTI value (Number of active TRIGGER events to interrupt)*/
/******************************************************************************/
#define CRKHAL_snGET_NTI()   (snGET_DPLL_NTICNT_NTICNT())

/******************************************************************************/
/* !FuncName    : CRKHAL_vidINCREMENT_ANG_CLOCK                               */
/* !Description : Increments MPVAL1 (Missing pulses to be added or subtracted */
/* 				  directly)        											  */
/******************************************************************************/
#define CRKHAL_vidINCREMENT_ANG_CLOCK()  \
   (vidSET_DPLL_MPVALL1(((uint32)CRKHAL_u16NORMAL_TOOTH_ANGLE)))

/******************************************************************************/
/* !FuncName    : CRKHAL_vidSET_ANG_CLOCK                                     */
/* !Description : Loads MPVAL1 (Missing pulses to be added or subtracted directly)*/
/******************************************************************************/
#define CRKHAL_vidSET_ANG_CLOCK(Val)   vidSET_DPLL_MPVALL1(Val)

/******************************************************************************/
/* !FuncName    : CRKHAL_vidDECREMENT_ANG_CLOCK                               */
/* !Description : Decrement MPVAL1  by One tooth      				          */
/******************************************************************************/
#define CRKHAL_vidDECREMENT_ANG_CLOCK() \
   GTM_DPLL_MPVAL1.U = ~((uint32)CRKHAL_u16NORMAL_TOOTH_ANGLE)

/******************************************************************************/
/* !FuncName    : CRKHAL_GetNomLenCurrTooth                                   */
/* !Description : Num of Recent Trigger                                       */
/******************************************************************************/
#define CRKHAL_GetNomLenCurrTooth  snGET_DPLL_NUTC_SYN_old()

/******************************************************************************/
/* !FuncName    : CRKHAL_CHECK_ENG_STALL                                      */
/* !Description : Check Eng Stall Notification                                */
/******************************************************************************/
#define CRKHAL_CHECK_ENG_STALL      GTM_CHECK_TIM_ENG_STALL

/******************************************************************************/
/* !FuncName    : CRKHAL_snGET_DIRECTION                                      */
/* !Description : Returns the Direction (FWD/BWD)                             */
/******************************************************************************/
#define CRKHAL_snGET_DIRECTION()    snGET_DPLL_STATUS_BWD

/******************************************************************************/
/* !FuncName    : CRKHAL_snGET_FALLING_EDGE_ANGLE                             */
/* !Description : Returns angle of the falling edge of the tooth              */
/******************************************************************************/
#define CRKHAL_snGET_FALLING_EDGE_ANGLE()  snGET_DPLL_PSTM

/******************************************************************************/
/* !FuncName    : CRKHAL_snGET_FALLING_EDGE_ANGLE_OLD                         */
/* !Description : Returns angle of the falling edge of the tooth              */
/******************************************************************************/
#define CRKHAL_snGET_FALLING_EDGE_ANGLE_OLD()  snGET_DPLL_PSTM_OLD

/******************************************************************************/
/* !FuncName    : CRKHAL_snGET_newTRIGGER                                     */
/* !Description : Returns Switch bit for LSB address of TRIGGER.              */
/******************************************************************************/
#define CRKHAL_snGET_newTRIGGER() snGET_DPLL_OSW_SWON_T

/******************************************************************************/
/* !FuncName    : CRKHAL_snGET_EDGE_ANGLE                                     */
/* !Description : Returns angle of edge of the tooth                          */
/******************************************************************************/
#define CRKHAL_snGET_EDGE_ANGLE()  IfxGtm_snTimEdgeAngleValue()

/******************************************************************************/
/* !FuncName    : CRKHAL_snGET_DPLL_TOOTH_DURATION                            */
/* !Description : Returns the Last Tooth Duration                             */
/******************************************************************************/
#define CRKHAL_snGET_DPLL_TOOTH_DURATION()   snGET_DPLL_DT_ACT()

/******************************************************************************/
/* !FuncName    : CRKHAL_snGET_DPLL_LOCK_STATUS                               */
/* !Description : Returns the Lock Status        							  */
/******************************************************************************/
#define CRKHAL_snGET_DPLL_LOCK_STATUS()   snGET_DPLL_STATUS_LOCK

/******************************************************************************/
/*                                                                            */
/* !Description : Macro to set configured angular timers values               */
/* !Number      : 0x06                                                        */
/* !Reference   : V03 NT 11 04452 / 03                                        */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidSetCfgAngCounter(snEnableClrValue)\
   vidSET_GTM_TBU_ANGLE(snEnableClrValue)

/******************************************************************************/
/* !FuncName    : CRKHAL_vidCFG_ANG_CNTR                                      */
/* !Description : Macro to configure angular timers GTM TBU                   */
/******************************************************************************/
#define CRKHAL_vidCFG_ANG_CNTR() vidSET_MODE_TBU()

/******************************************************************************/
/* !FuncName    : CRKHAL_vidCfgSignalInTimer                                  */
/* !Description : This function initializes TIM Channels used for Capture(DPLL)*/
/*                & Process (MCS) by calling functions:                       */
/*                IfxGtm_vidTimCaptureCfg();                                  */
/*                IfxGtm_vidTim0CrkToMcsCfg();                                */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidCfgSignalInTimer() IfxGtm_vidTimCfg()

/******************************************************************************/
/* !FuncName    : CRKHAL_vidMcsInit                                           */
/* !Description : Initializes Variable & MCS                                  */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidMcsInit() IfxGtm_vidMcs0Init()

/******************************************************************************/
/* !FuncName    : CRKHAL_vidMcsResetVars                                      */
/* !Description : Resets the MCS variable for CRKOFF                          */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidMcsResetVars() IfxGtm_vidMcsResetVars()

/******************************************************************************/
/* !FuncName    : CRKHAL_vidDpllConfig                                        */
/* !Description : Configures the DPLL Control registers                       */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidDpllConfig()   IfxGtm_vidDpllConfig(   \
   (uint8)(CRKHAL_ku16NbPhysTeeth + (2U * CRKHAL_ku8NumberOfSingularities)) \
   - 1U, \
   2U, \
   (uint16)CRKHAL_u16NORMAL_TOOTH_ANGLE, \
   (2U * CRKHAL_ku8NumberOfSingularities))

/******************************************************************************/
/* !FuncName    : CRKHAL_vidCrankProfileInit                                  */
/* !Description : Initializes the Crank Profiles to ADT ram profile           */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidCrankProfileInit()   IfxGtm_vidCrankProfileInit()

/******************************************************************************/
/* !FuncName    : CRKHAL_vidRESET_GTM_DPLL_APTs                               */
/* !Description : Resets the DPLL APT pointers APT2C & APT                    */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidRESET_GTM_DPLL_APTs  vidRESET_GTM_DPLL_APTs

/******************************************************************************/
/* !FuncName    : CRKHAL_vidRESET_GTM_DPLL_APT                                */
/* !Description : Resets the APT                                              */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidRESET_GTM_DPLL_APT() vidRESET_GTM_DPLL_APT()

/******************************************************************************/
/* !FuncName    : CRKHAL_vidSET_GTM_DPLL_APT2c                                */
/* !Description : Configures the APT2c as per passed parameter                */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidSET_GTM_DPLL_APT2c(snValue) GTM_DPLL_APT2C_SET((uint32)snValue)

/******************************************************************************/
/* !FuncName    : CRKHAL_vidSET_GTM_DPLL_APT_APT2b                            */
/* !Description : Configures the APT as per passed parameter                  */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidSET_GTM_DPLL_APT_APT2b(snValue) vidSET_GTM_DPLL_APT_APT2b(snValue)

/******************************************************************************/
/* !FuncName    : CRKHAL_vidSET_GTM_DPLL_APT_APT                              */
/* !Description : Configures the APT as per passed parameter                  */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidSET_GTM_DPLL_APT_APT(snValue) vidSET_GTM_DPLL_APT_APT(snValue)

/******************************************************************************/
/* !FuncName    : CRKHAL_snGET_DPLL_APT2C                                     */
/* !Description : Reads the APT2C value                                       */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_snGET_GTM_DPLL_APT2c    GTM_DPLL_APT2C_READ

/******************************************************************************/
/* !FuncName    : CRKHAL_snGET_GTM_DPLL_APT_APT2b                             */
/* !Description : Reads the APT2b value                                       */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_snGET_GTM_DPLL_APT_APT2b    GTM_DPLL_APT_APT2B_READ

/******************************************************************************/
/* !FuncName    : CRKHAL_snGET_GTM_DPLL_APT_APT                             */
/* !Description : Reads the APT value                                       */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_snGET_GTM_DPLL_APT_APT    GTM_DPLL_APT_APT_READ

/******************************************************************************/
/* !FuncName    : CRKHAL_vidUpdateToothTskDurationThd                         */
/* !Description : Updates the Tooth Task Duration Threshold                   */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidUpdateToothTskDurationThd(u32Val) \
   IfxGtm_vidUpdateToothTskDurationThd(u32Val)

/******************************************************************************/
/* !FuncName    : CRKHAL_vidDPLL_DIS_INTR                                     */
/* !Description : Disable DPLL IRQ                                            */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidDPLL_DIS_INTR()   vidDISABLE_DPLL_IRQ()

/******************************************************************************/
/* !FuncName    : CRKHAL_vidDPLL_EN_INTR                                      */
/* !Description : Enables DPLL IRQ                                            */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidDPLL_EN_INTR() vidENABLE_DPLL_IRQ()

/******************************************************************************/
/* !FuncName    : CRKHAL_vidDPLL_DISABLE                                      */
/* !Description : Disable DPLL                                                */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidDPLL_DISABLE() vidDISABLE_DPLL_CTRL_DEN()

/******************************************************************************/
/* !FuncName    : CRKHAL_vidDPLL_ENABLE                                       */
/* !Description : Enables DPLL                                                */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidDPLL_ENABLE()  vidENABLE_DPLL_CTRL_DEN()

/******************************************************************************/
/* !FuncName    : CRKHAL_TBU_ANGLE                                            */
/* !Description : Returns TBU Angle                                           */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_TBU_ANGLE   GTM_TBU_ANGLE

/******************************************************************************/
/* !FuncName    : CRKHAL_u16TbuConvRelToAbsAng                                */
/* !Description : Conversion for Relative to Absolute angle                   */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_u16TbuConvRelToAbsAng(Value)  IfxGtm_u16TbuConvRelToAbsAng(Value)

/******************************************************************************/
/* !FuncName    : CRKHAL_vidENABLE_TIMEOUT                                    */
/* !Description : Enables TIM Time out                                        */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidENABLE_TIMEOUT(Timer)  GTM_ENABLE_TIM_TIMEOUT_##Timer

/******************************************************************************/
/* !FuncName    : CRKHAL_vidDISABLE_TIMEOUT                                   */
/* !Description : Disable TIM Time out                                        */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidDISABLE_TIMEOUT(Timer) GTM_DISABLE_TIM_TIMEOUT_##Timer

/******************************************************************************/
/* !FuncName    : CRKHAL_vidENABLE_MCS                                        */
/* !Description : Enable MCS                                                  */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidENABLE_MCS()           GTM_ENABLE_MCS

/******************************************************************************/
/* !FuncName    : CRKHAL_vidDISABLE_MCS                                       */
/* !Description : Disable MCS                                                 */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidDISABLE_MCS()          GTM_DISABLE_MCS

/******************************************************************************/
/* !FuncName    : CRKHAL_vidSET_TRIGGER_HOLD_TIME                             */
/* !Description : Configures the Trigger Hold Time for DPLL	                  */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidSET_TRIGGER_HOLD_TIME(Val) GTM_SET_TRIGGER_HOLD_TIME(Val)

/******************************************************************************/
/* !FuncName    : CRKHAL_vidSET_TRIGGERlockingrange                           */
/* !Description : Configures teh Trigger Locking range for DPLL               */
/*                                                                            */
/******************************************************************************/
/*#define CRKHAL_vidSET_TRIGGER_LOCK_RANGE(Val) GTM_SET_TLR(Val)*/

/******************************************************************************/
/* !FuncName    : CRKHAL_vidSET_TRIGGERlockingrange                           */
/* !Description : Time Out Value of active TRIGGER Slope					                                          */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidSET_TOV_Active_TRIGGER(Val) GTM_SET_TOV(Val)

/******************************************************************************/
/* !FuncName    : CRKHAL_vidGTM_SET_DPLL_CTRL_1                               */
/* !Description : Configures the DPLL CTRL_1 register                         */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_vidGTM_SET_DPLL_CTRL_1() GTM_SET_DPLL_CTRL_1(2U * CRKHAL_ku8NumberOfSingularities)

/******************************************************************************/
/* !FuncName    : CRKHAL_snGET_CRK_PROF_APT2c_PTR                             */
/* !Description : Reads the APT2C pointer value                               */
/*                                                                            */
/******************************************************************************/
#define CRKHAL_snGET_CRK_PROF_APT2c_PTR(u32LocalApt2cIdx) \
do \
{ \
   u32LocalApt2cIdx = CRKHAL_snGTM_DPLL_APT2C_PTR; \
   \
   if (u32LocalApt2cIdx == (uint32)UINT32_MIN) \
   { \
      u32LocalApt2cIdx = CRKHAL_u16PhyTeethFullScale1Ms; \
   } \
   else \
   { \
      u32LocalApt2cIdx -= (1U); \
   } \
} \
while (0)

#endif /* CRKHAL_I_H */

/*-------------------------------- end of file -------------------------------*/
