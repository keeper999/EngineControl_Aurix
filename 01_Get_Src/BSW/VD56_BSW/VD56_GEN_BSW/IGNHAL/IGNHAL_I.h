/******************************************************************************/
/* !Layer           : HAL                                                     */
/* !Component       : IGNHAL                                                  */
/* !Description     : Ignition Driver Component                               */
/*                                                                            */
/* !File            : IGNHAL_I.h                                              */
/* !Description     :                                                         */
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
 * %PID: P2017_BSW:A30395.A-SRC;4 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#ifndef IGNHAL_I_H
#define IGNHAL_I_H


#include "ADCHAL.h"
#include "CRKHAL.h"
#include "DGOHAL.h"
#include "IGNHAL_co_Cfg.h"
/*#include "IGNHAL_Cfg.h"*/
#include "SWFAIL.h"
#include "TSKSRV.h"
#include "IfxGtm_CCu.h"
#include "TDCHAL_E.h"
#include "IGNHAL_Def.h"
#include "IGNHAL_L.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/* !Comment : define for coil trims in twin-phys mode                         */
#define Icd_igbt_fdbk_gain_a_c        Icd_igbt_fdbk_gain_a
#define Icd_igbt_fdbk_gain_b_d        Icd_igbt_fdbk_gain_d

/* !Comment : define for minimum dwell time                                   */
#if (IGNHAL_coEXTERNAL_POWER_COILS == IGNHAL_coENABLED)

#define IGNHAL_u32DWELL_TIME_MIN \
   ( (IGNHAL_kbEnableExtPowerCoils == (boolean)TRUE) \
   ? (IGNHAL_u32TIME_150_US + IGNHAL_ku32DiagPointDelay1) \
   : (IGNHAL_u32TIME_150_US + IGNHAL_ku32SCToSupplyDiagDelay))

#else
/* modification : adding * 100 to IGNHAL_ku32SCToSupplyDiagDelay */
#define IGNHAL_u32DWELL_TIME_MIN \
   (IGNHAL_u32TIME_150_US + IGNHAL_ku32SCToSupplyDiagDelay)

#endif

/* !Comment : define for coil minimum ADV angle                               */
#define IGNHAL_u16COIL_A_MIN_ADV_ANGLE IGNHAL_u16MIN_ADV_ANGLE

#define IGNHAL_u16COIL_B_MIN_ADV_ANGLE ( IGNHAL_u16COIL_A_MIN_ADV_ANGLE \
                                       + IGNHAL_u16TDC_OFFSET)

#define IGNHAL_u16COIL_C_MIN_ADV_ANGLE ( IGNHAL_u16COIL_B_MIN_ADV_ANGLE \
                                       + IGNHAL_u16TDC_OFFSET)

#define IGNHAL_u16COIL_D_MIN_ADV_ANGLE ( IGNHAL_u16COIL_C_MIN_ADV_ANGLE \
                                       + IGNHAL_u16TDC_OFFSET)

/* !Comment : define for maximum dwell time angle                             */
#define IGNHAL_u16DWELL_ANGLE_MAX ( ((2U * IGNHAL_u16TDC_OFFSET) \
                                  - IGNHAL_u16TDC_TO_REF_TOOTH_ANGLE) \
                                  + IGNHAL_u16MIN_ADV_ANGLE)

/* !Comment : Define for coil ref tooth angle                                 */
#define IGNHAL_u16COIL_B_REF_TOOTH_ANGLE IGNHAL_u16TDC_TO_REF_TOOTH_ANGLE

#define IGNHAL_u16COIL_C_REF_TOOTH_ANGLE ( IGNHAL_u16COIL_B_REF_TOOTH_ANGLE \
                                         + IGNHAL_u16TDC_OFFSET)

#define IGNHAL_u16COIL_D_REF_TOOTH_ANGLE ( IGNHAL_u16COIL_B_REF_TOOTH_ANGLE \
                                         + (2U * IGNHAL_u16TDC_OFFSET))

#define IGNHAL_u16COIL_A_REF_TOOTH_ANGLE ( IGNHAL_u16COIL_B_REF_TOOTH_ANGLE \
                                         + (2U * IGNHAL_u16TDC_OFFSET))

/* !Comment : Define for engine speed adapt resolution                        */
#define IGNHAL_u32ENG_SPD_ADAPT_RESOL \
   ( (IGNHAL_ku8NumberOfCylinders != 0u) \
   ? (uint32) (600000000u / IGNHAL_ku8NumberOfCylinders) \
   : (uint32) UINT32_MIN)

/* !Comment : IGNHAL_kau16CoilVoltageThreshold array size                     */
#define IGNHAL_u8COILS_FAULTS_NB 10


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* Private Services                                                           */
/******************************************************************************/
/******************************************************************************/
/*                                                                            */
/* !Description : Gets the timer subblock name from configuration, that       */
/*                corresponds to coil snCoilName. Private Use Only            */
/*                                                                            */
/******************************************************************************/
#define IGNHAL_snGET_ATOM_Subblock_FROM_CFG(snCoilName) \
   (IGNHAL_sn##snCoilName##_Subblock_NAME)

/******************************************************************************/
/*                                                                            */
/* !Description : Gets the timer channel name from configuration,             */
/*                that corresponds to coil snCoilName. Private Use Only       */
/*                                                                            */
/******************************************************************************/
#define IGNHAL_snGET_ATOM_Channel_FROM_CFG(snCoilName) \
   (IGNHAL_sn##snCoilName##_CHANNEL_NAME)

/******************************************************************************/
/*                                                                            */
/* !Description : Treatment at the begin of the coil conduction               */
/*                                                                            */
/******************************************************************************/
#define IGNHAL_vidSTART_OF_CONDUCTION(coil)  \
             M1_IGNHAL_vidSTART_OF_CONDUCTION(coil)
   #define M1_IGNHAL_vidSTART_OF_CONDUCTION(coil) \
      M2_IGNHAL_vidCONDUCTION_##coil

#define M2_IGNHAL_vidCONDUCTION_COIL_A  IGNHAL_vidConduction_start_a( )
#define M2_IGNHAL_vidCONDUCTION_COIL_B  IGNHAL_vidConduction_start_b( )
#define M2_IGNHAL_vidCONDUCTION_COIL_C  IGNHAL_vidConduction_start_c( )

/******************************************************************************/
/*                                                                            */
/* !Description : Configures to treat Event T0                                */
/*                                                                            */
/******************************************************************************/
#define IGNHAL_vidEvent_T0(coil)  M1_IGNHAL_vidEvent_T0(coil)
   /* Internal macros */
   #define M1_IGNHAL_vidEvent_T0(coil)  M2_IGNHAL_vidEvent_T0_##coil

   #define M2_IGNHAL_vidEvent_T0_COIL_A  IGNHAL_vidConfigureT0_a()
   #define M2_IGNHAL_vidEvent_T0_COIL_B  IGNHAL_vidConfigureT0_b()
   #define M2_IGNHAL_vidEvent_T0_COIL_C  IGNHAL_vidConfigureT0_c()

/******************************************************************************/
/*                                                                            */
/* !Description : Treatment at the end of Event T1 after T0                   */
/*                                                                            */
/******************************************************************************/
#define IGNHAL_vid_EVENT_PROCESSING_T1(coil) \
     M1_IGNHAL_vidEVENT_PROCESS_T1(coil)
     
   /* Internal macros */
   #define M1_IGNHAL_vidEVENT_PROCESS_T1(coil) \
      M2_IGNHAL_EVENT_PRO_T1_##coil()

   #define M2_IGNHAL_EVENT_PRO_T1_COIL_A()     IGNHAL_vidEventT1_a()
   #define M2_IGNHAL_EVENT_PRO_T1_COIL_C()     IGNHAL_vidEventT1_c()
   #define M2_IGNHAL_EVENT_PRO_T1_COIL_B()     IGNHAL_vidEventT1_b()

/******************************************************************************/
/*                                                                            */
/* !Description : Treatment at the end of Event T2 after T0                   */
/*                                                                            */
/******************************************************************************/
#define IGNHAL_vid_EVENT_PROCESSING_T2(coil ) \
     M1_IGNHAL_vidEVENT_PROCESS_T2(coil )
                                                                                             
   /* Internal macros */                                                                     
   #define M1_IGNHAL_vidEVENT_PROCESS_T2(coil) \
      M2_IGNHAL_EVENT_PRO_T2_##coil()
                                                                                             
   #define M2_IGNHAL_EVENT_PRO_T2_COIL_A()     IGNHAL_vidEventT2_a()
   #define M2_IGNHAL_EVENT_PRO_T2_COIL_C()     IGNHAL_vidEventT2_c()
   #define M2_IGNHAL_EVENT_PRO_T2_COIL_B()     IGNHAL_vidEventT2_b()

/******************************************************************************/
/*                                                                            */
/* !Description : Treatment at the end of Event T1 and before T0              */
/*                                                                            */
/******************************************************************************/
#define IGNHAL_vidEvent_T0_T2(coil)    M1_IGNHAL_vidEvent_T0_T2(coil)
   /* Internal macros */
   #define M1_IGNHAL_vidEvent_T0_T2(coil) M2_IGNHAL_vidEvent_T0_T2_##coil()

   #define M2_IGNHAL_vidEvent_T0_T2_COIL_A()     IGNHAL_vidConfigureT0_T2_a()
   #define M2_IGNHAL_vidEvent_T0_T2_COIL_B()     IGNHAL_vidConfigureT0_T2_b()
   #define M2_IGNHAL_vidEvent_T0_T2_COIL_C()     IGNHAL_vidConfigureT0_T2_c()

/******************************************************************************/
/*                                                                            */
/* !Description : Calls the SC Diagnostic function                            */
/*                                                                            */
/******************************************************************************/                                             
#define IGNHAL_vidSC_DIAG(coil, value) \
   M1_IGNHAL_vidSC_DIAG(coil, value)                
                                                    
   /* Internal macros */                            
   #define M1_IGNHAL_vidSC_DIAG(coil, value) \
      M2_IGNHAL_vidSC_DIAG_##coil(value)            
                                                    
   #define M2_IGNHAL_vidSC_DIAG_COIL_A(value)   diag_ccbat_a(value)
   #define M2_IGNHAL_vidSC_DIAG_COIL_C(value)   diag_ccbat_c(value)
   #define M2_IGNHAL_vidSC_DIAG_COIL_B(value)   diag_ccbat_b(value)

/******************************************************************************/
/*                                                                            */
/* !Description : Launches the SC Diagnostics events                          */
/*                                                                            */
/******************************************************************************/
#define IGNHAL_vidLAUNCH_EVENT(coil) \
   M1_IGNHAL_vidLAUNCH_EVENT(coil)

   /* Internal macros */
   #define M1_IGNHAL_vidLAUNCH_EVENT(coil) \
      M2_IGNHAL_LAUNCH_EVENT_##coil()

   #define M2_IGNHAL_LAUNCH_EVENT_COIL_A()   IGNHAL_vidConfigureT0_T1_a()
   #define M2_IGNHAL_LAUNCH_EVENT_COIL_C()   IGNHAL_vidConfigureT0_T1_c()
   #define M2_IGNHAL_LAUNCH_EVENT_COIL_B()   IGNHAL_vidConfigureT0_T1_b()

/******************************************************************************/
/*                                                                            */
/* !Description : Processing on Diag Events                                   */
/*                                                                            */
/******************************************************************************/
#define IGNHAL_vidEVENT_PROCESSING(coil, IrqNotifVal) \
   M1_IGNHAL_vidEVENT_PROCESSING(coil, IrqNotifVal)

/* !Comment: Check if specific external power coils code is present           */
#if (IGNHAL_coEXTERNAL_POWER_COILS == IGNHAL_coENABLED)

#else

   #define M1_IGNHAL_vidEVENT_PROCESSING(coil, IrqNotifVal) \
      M2_IGNHAL_vidEVENT_PROCESSING(coil, IrqNotifVal)

#endif

   #define M2_IGNHAL_vidEVENT_PROCESSING(coil, IrqNotifVal) \
   do \
   { \
      uint16 u16LocalCoilVoltage; \
      \
      \
      /* In case if T0 (time happens) the control enters the if statement */ \
      if (0U == IrqNotifVal) \
      { \
         IGNHAL_vidDisableSCWNotif(IGNHAL_u8##coil, \
                                  (uint8)IfxGtm_Compare_Unit_0); \
         u16LocalCoilVoltage = (ADCBSL_u16Read(ANI_##coil)); \
         IGNHAL_vidSC_DIAG(coil, u16LocalCoilVoltage); \
      } \
      else\
      { \
        /* If T1 comes before T0 the processing of diagnostics */\
           if (  IGNHAL_u8EVENT_T0_T1 \
              == IGNHAL_u8EventStateMachine[IGNHAL_u8##coil]) \
           { \
            IGNHAL_vid_EVENT_PROCESSING_T1(coil); \
              IGNHAL_vidEvent_T0_T2(coil); \
            IGNHAL_u8EventStateMachine[IGNHAL_u8##coil] = IGNHAL_u8EVENT_T0_T2; \
         }\
         /* If T2 comes before T0 the processing of diagnostics */ \
         else \
         { \
           if (  IGNHAL_u8EVENT_T0_T2 \
              == IGNHAL_u8EventStateMachine[IGNHAL_u8##coil]) \
            { \
               IGNHAL_vid_EVENT_PROCESSING_T2(coil); \
               \
               IGNHAL_vidEvent_T0(coil); \
               IGNHAL_u8EventStateMachine[IGNHAL_u8##coil] = IGNHAL_u8EVENT_T0; \
               \
            } \
         } \
      } \
   } \
   while (0)


/******************************************************************************/
/*                                                                            */
/* !Description : Mono Coil Manager                                           */
/*                                                                            */
/******************************************************************************/
#define IGNHAL_vidMONO_COIL_MANAGER(coil_to_command) \
   M1_IGNHAL_vidMONO_COIL_MANAGER(coil_to_command)

   /* Internal macros */
   #define M1_IGNHAL_vidMONO_COIL_MANAGER(coil_to_command) \
   do \
   { \
      switch(coil_to_command) \
      { \
      case IGNHAL_u8COIL_A: \
         IGNHAL_vidCOIL_MANAGER(COIL_A, IGNHAL_u16COIL_A_MIN_ADV_ANGLE); \
         break; \
      case IGNHAL_u8COIL_B: \
         IGNHAL_vidCOIL_MANAGER(COIL_B, IGNHAL_u16COIL_B_MIN_ADV_ANGLE); \
         break; \
      case IGNHAL_u8COIL_C: \
         IGNHAL_vidCOIL_MANAGER(COIL_C, IGNHAL_u16COIL_C_MIN_ADV_ANGLE); \
         break; \
      /*case IGNHAL_u8COIL_D: */\
         /*IGNHAL_vidCOIL_MANAGER(COIL_D, IGNHAL_u16COIL_D_MIN_ADV_ANGLE); \*/\
         /* break; */\
      default: \
         SWFAIL_vidSoftwareErrorHook(); \
         break; \
      } \
   } \
   while (0)

/******************************************************************************/
/*                                                                            */
/* !Description : Jumo Coil Manager                                           */
/*                                                                            */
/******************************************************************************/
#define IGNHAL_vidJUMO_COIL_MANAGER(coil_to_command) \
   M1_IGNHAL_vidJUMO_COIL_MANAGER(coil_to_command)

   /* Internal macros */
   #define M1_IGNHAL_vidJUMO_COIL_MANAGER(coil_to_command) \
   do \
   { \
      switch(coil_to_command) \
      { \
      case IGNHAL_u8COIL_A: \
         IGNHAL_vidCOIL_MANAGER(COIL_A_C, IGNHAL_u16COIL_A_MIN_ADV_ANGLE); \
         break; \
      case IGNHAL_u8COIL_B: \
         /*IGNHAL_vidCOIL_MANAGER(COIL_B_D, \
                                  IGNHAL_u16COIL_B_MIN_ADV_ANGLE); \*/\
         break; \
      case IGNHAL_u8COIL_C: \
         IGNHAL_vidCOIL_MANAGER(COIL_A_C, IGNHAL_u16COIL_C_MIN_ADV_ANGLE); \
         break; \
           /* case IGNHAL_u8COIL_D: */\
         /*IGNHAL_vidCOIL_MANAGER(COIL_B_D, */\
                                  /*IGNHAL_u16COIL_D_MIN_ADV_ANGLE); \*/\
       /*  break;*/ \
      default: \
         SWFAIL_vidSoftwareErrorHook(); \
         break; \
      } \
   } \
   while (0)

/******************************************************************************/
/*                                                                            */
/* !Description : Coil Manager                                                */
/*                                                                            */
/******************************************************************************/
#define IGNHAL_vidCOIL_MANAGER(coil, evt_offset) \
   M1_IGNHAL_vidCOIL_MANAGER(coil, evt_offset)

   /* Internal macros */
   #define M1_IGNHAL_vidCOIL_MANAGER(coil, evt_offset) \
   do \
   { \
      IGNHAL_vidDwellTimeLimitCalc(); \
      IGNHAL_vidCoilDwellTimeCalc(IGNHAL_u8##coil); \
      IGNHAL_vidCoilCommand(IGNHAL_u8##coil, evt_offset); \
   } \
   while (0)

/******************************************************************************/
/*                                                                            */
/* !Description : Deprograms the conduction of a coil                         */
/* In IFX AURIX IGNHAL implementation these are the same alarms since they    */
/* correspond to the same hardware resource ATOM[i]_CH[x] compare unit CCU1.  */
/* Therefore, only one function will be used with new parameter as follows    */
/* CRKHAL_vidDisableAlarmNotif(CRKHAL_u8ALARM_COIL_X_CMD);                    */
/* In IFX AURIX IGNHAL implementation new function/macro                      */
/* IGNHAL_vidDisableCmd(IGNHAL_u8COIL_X);                                     */
/* will be implemented to disable ATOM channel used to manage conduction of   */
/* coil X. This function will also cut the command (stop the conduction)      */
/* immediately. Output pin state will be changed to inactive level - low      */
/* In IFX AURIX IGNHAL implementation new function                            */
/* IGNHAL_vidDisableWtdgNotif(IGNHAL_u8COIL_X);                               */
/* will be implemented to disable notification on ATOM[i]_CH[x] compare unit0 */
/* programmed with maximum coil conduction time allowed as described in 5.1.1 */
/* In IFX AURIX IGNHAL implementation executing new function/macro            */
/* IGNHAL_vidDisableCmd(IGNHAL_u8COIL_X);                                     */
/* to disable ATOM channel, used to manage conduction of coil X will at       */
/* the same time disable any watch-dog timer event. Therefore, there is no    */
/* need for any explicit action related to coil conduction watch-dog here     */
/******************************************************************************/
#define IGNHAL_vidCOIL_CUT_OFF(coilname) \
   M1_IGNHAL_vidCOIL_CUT_OFF(coilname)

   /* Internal macros */
   #define M1_IGNHAL_vidCOIL_CUT_OFF(coilname) \
   do \
   { \
      CRKHAL_vidDisableAlarmNotif(CRKHAL_u8ALARM_##coilname##_CMD); \
      IGNHAL_vidDisableWtdgNotif(IGNHAL_u8##coilname); \
      IGNHAL_vidDisableCmd(IGNHAL_u8##coilname); \
   } \
   while (0)

/******************************************************************************/
/*                                                                            */
/* !Description : Treatment at the end of the coil conduction                 */
/*                                                                            */
/*
 * In IFX AURIX IGNHAL implementation new function
 * IGNHAL_vidDisableSCWNotif(IGNHAL_u8COIL_X);
 * will be implemented to disable notification on ATOM[i]_CH[y] compare unit0,
 * programmed with tuned delay normally set to 500 µs, and used to trigger
 * conduction coil X short circuit to battery diagnostic, as described in 5.1.2
 * If current measurement has been completed on both points T1 and T2 we can use
 * coil current acquisition values to calculate Adaptation parameters.
 * Set diagnostic status to Finished otherwise indicate that current slope
 * acquisitions are invalid
 * Trigger diagnostics activating Diagnostic Event Task
 * TSKSRV_vidActivateTask(IGNHAL_DIAG_##coil##_EVENT);
 * with parameter passed describing coil as IGNHAL_DIAG_COIL_X_EVENT */
/******************************************************************************/

#define IGNHAL_vidEND_OF_CONDUCTION(coil) \
   M1_IGNHAL_vidEND_OF_CONDUCTION(coil)

/* !Comment: check if specific external power coils code is present   */
#if (IGNHAL_coEXTERNAL_POWER_COILS == IGNHAL_coENABLED)

#else

   #define M1_IGNHAL_vidEND_OF_CONDUCTION(coil) \
      M3_IGNHAL_vidEND_OF_CONDUCTION(coil)
#endif

/*  !Comment: Internal macros                                                */
   #define M3_IGNHAL_vidEND_OF_CONDUCTION(coil) \
   do \
   { \
      CRKHAL_vidDisableAlarmNotif(CRKHAL_u8ALARM_##coil##_CMD); \
      IGNHAL_vidDisableWtdgNotif(IGNHAL_u8##coil); \
      IGNHAL_vidDisableSCWNotif(IGNHAL_u8##coil,\
           (uint8)IfxGtm_Compare_Unit_0);\
      IGNHAL_vidDisableSCWNotif(IGNHAL_u8##coil,\
           (uint8)IfxGtm_Compare_Unit_1);\
      IGNHAL_vidDisableDiagnostic(IGNHAL_u8##coil);\
      if ((IGNHAL_u8EventStateMachine[IGNHAL_u8##coil] == \
           IGNHAL_u8EVENT_FINISHED) || \
          (IGNHAL_u8EventStateMachine[IGNHAL_u8##coil] == \
              IGNHAL_u8EVENT_T0)) \
      { \
          if(IGNHAL_u8EventStateMachine[IGNHAL_u8##coil] == \
                IGNHAL_u8EVENT_T0)\
         { \
           IGNHAL_u8EventStateMachine[IGNHAL_u8##coil] = \
           IGNHAL_u8EVENT_FINISHED; \
         } \
      } \
      else \
      { \
         IGNHAL_bSlopeAcqValid[IGNHAL_u8##coil] = \
         (boolean)FALSE; \
      } \
      TSKSRV_vidActivateTask(IGNHAL_DIAG_##coil##_EVENT); \
   } \
   while (0)

/******************************************************************************/
/*                                                                            */
/* !Description : Treatment on Start of conduction                            */
/*                                                                            */
/******************************************************************************/
#define IGNHAL_vidOCR_IT_PROCESSING(coil) \
   M1_IGNHAL_vidOCR_IT_PROCESSING(coil)

/* !Comment: check if specific external power coils code is present   */
#if (IGNHAL_coEXTERNAL_POWER_COILS == IGNHAL_coENABLED)

#else

   #define M1_IGNHAL_vidOCR_IT_PROCESSING(coil) \
      M3_IGNHAL_vidOCR_IT_PROCESSING(coil)

#endif

/*  !Comment: Internal macros                                                 */
   #define M3_IGNHAL_vidOCR_IT_PROCESSING(coil) \
   do \
   { \
      uint32 localConductionTime; \
   \
   \
      localConductionTime = IfxGtm_u32ReadCapTime(IGNHAL_pstr##coil); \
      { \
         IGNHAL_u32DateOnCoil[IGNHAL_u8##coil] = localConductionTime; \
         IGNHAL_vidSTART_OF_CONDUCTION(coil);\
         IGNHAL_u8EventStateMachine[IGNHAL_u8##coil] = IGNHAL_u8EVENT_T0_T1; \
         /* The IGNHAL_ku32SCToSupplyDiagDelay is at 100ns*/\
         IGNHAL_u32ScDateOnCoil[IGNHAL_u8##coil] = (localConductionTime + \
               IGNHAL_ku32SCToSupplyDiagDelay) & (0x00FFFFFFU); \
         IGNHAL_vidLAUNCH_EVENT(coil); \
      } \
   } \
   while (0)

/******************************************************************************/
/*                                                                            */
/* !Description : Diagnosis processing                                        */
/*                                                                            */
/******************************************************************************/
#define IGNHAL_vidDIAGNOSIS(snCoil) \
   M1_IGNHAL_vidDIAGNOSIS(snCoil)

/* !Comment: check if specific external power coils code is present   */
#if (IGNHAL_coEXTERNAL_POWER_COILS == IGNHAL_coENABLED)

#else

   #define M1_IGNHAL_vidDIAGNOSIS(coil) \
      M3_IGNHAL_vidDIAGNOSIS(coil)

#endif

   /* Internal macros */
   #define M3_IGNHAL_vidDIAGNOSIS(snCoil) \
do \
   { \
      if ((IGNHAL_bSCDefaultFlag[IGNHAL_u8##snCoil]) == (boolean)FALSE) \
      {  \
        if ((IGNHAL_bSlopeAcqValid[IGNHAL_u8##snCoil]) != (boolean)FALSE)\
        { \
           if ( (sint32)IGNHAL_u16VoltageSlope2[IGNHAL_u8##snCoil] \
              > ((sint32)IGNHAL_ku16OCDetectionThreshold)) \
           { \
              IGNHAL_vidMAJ_DIAG(snCoil, \
                                 DGOHAL_bfVALID_OPEN | \
                                 DGOHAL_bfVALID_GROUND, \
                                 DGOHAL_bfNO_FAULT_OPEN | \
                                 DGOHAL_bfNO_FAULT_GROUND); \
              IGNHAL_bOCDefaultFlag[IGNHAL_u8##snCoil] = (boolean)FALSE; \
           } \
           else \
           { \
              IGNHAL_vidMAJ_DIAG(snCoil, \
                                 DGOHAL_bfVALID_OPEN | \
                                 DGOHAL_bfVALID_GROUND, \
                                 DGOHAL_bfFAULT_GROUND | \
                                 DGOHAL_bfFAULT_OPEN); \
              IGNHAL_bOCDefaultFlag[IGNHAL_u8##snCoil] = (boolean)TRUE; \
           } \
        } \
      } \
      else \
      { \
         IGNHAL_vidMAJ_DIAG(snCoil, \
                            DGOHAL_bfVALID_OPEN | \
                            DGOHAL_bfVALID_GROUND, \
                            DGOHAL_bfNO_FAULT_OPEN | \
                            DGOHAL_bfNO_FAULT_GROUND); \
         IGNHAL_bOCDefaultFlag[IGNHAL_u8##snCoil] = (boolean)FALSE; \
      } \
   } \
   while (0)

/******************************************************************************/
/*                                                                            */
/* !Description : Diagnosis processing, calls the good DGOHAL_vidWrite        */
/*                                                                            */
/******************************************************************************/
#define IGNHAL_vidMAJ_DIAG(snCoil, u8Mask, u8Value) \
   M1_IGNHAL_vidMAJ_DIAG(snCoil, u8Mask, u8Value)

   /* Internal macros */
   #define M1_IGNHAL_vidMAJ_DIAG(snCoil, u8Mask, u8Value) \
      M2_IGNHAL_vidMAJ_DIAG_##snCoil(u8Mask, u8Value)

   #define M2_IGNHAL_vidMAJ_DIAG_COIL_A(u8Mask, u8Value) \
      DGOHAL_vidWrite(IGNHAL_udtICD_A_DGO_CH, u8Mask, u8Value)

   #define M2_IGNHAL_vidMAJ_DIAG_COIL_B(u8Mask, u8Value) \
      DGOHAL_vidWrite(IGNHAL_udtICD_B_DGO_CH, u8Mask, u8Value)

   #define M2_IGNHAL_vidMAJ_DIAG_COIL_C(u8Mask, u8Value) \
      DGOHAL_vidWrite(IGNHAL_udtICD_C_DGO_CH, u8Mask, u8Value)

   #define M2_IGNHAL_vidMAJ_DIAG_COIL_D(u8Mask, u8Value) \
      DGOHAL_vidWrite(IGNHAL_udtICD_D_DGO_CH, u8Mask, u8Value)

   #define M2_IGNHAL_vidMAJ_DIAG_COIL_A_C(u8Mask, u8Value) \
   do \
   { \
      DGOHAL_vidWrite(IGNHAL_udtICD_A_DGO_CH, u8Mask, u8Value); \
      DGOHAL_vidWrite(IGNHAL_udtICD_C_DGO_CH, u8Mask, u8Value); \
   } \
   while (0)

   #define M2_IGNHAL_vidMAJ_DIAG_COIL_B_D(u8Mask, u8Value) \
   do \
   { \
      DGOHAL_vidWrite(IGNHAL_udtICD_B_DGO_CH, u8Mask, u8Value); \
      DGOHAL_vidWrite(IGNHAL_udtICD_D_DGO_CH, u8Mask, u8Value); \
   } \
   while (0)


/******************************************************************************/
/*                                                                            */
/* !Description : Manager to allow coil conduction                            */
/*                                                                            */
/******************************************************************************/
#define IGNHAL_vidALLOW_COIL_MNG() \
   M1_IGNHAL_vidALLOW_COIL_MNG()

   /* Internal macros */
   #define M1_IGNHAL_vidALLOW_COIL_MNG() \
   do \
   { \
      switch(IgnHALCoilToCommand) \
      { \
         case IGNHAL_u8COIL_A: \
            IGNHAL_bCutCylinderA = (boolean)FALSE; \
            break; \
         case IGNHAL_u8COIL_B: \
            IGNHAL_bCutCylinderB = (boolean)FALSE; \
            break; \
         case IGNHAL_u8COIL_C: \
            IGNHAL_bCutCylinderC = (boolean)FALSE; \
            break; \
         /*case IGNHAL_u8COIL_D:*/ \
            /*IGNHAL_bCutCylinderD = (boolean)FALSE;*/ \
            /*break;*/ \
         default: \
            SWFAIL_vidSoftwareErrorHook(); \
            break; \
      } \
   } \
   while (0)

/******************************************************************************/
/* !FuncName    : IGNHAL_vidRefreshCoilToCommand                              */
/* !Description : The API shall find the coil to command                      */
/******************************************************************************/
#define IGNHAL_vidRefreshCoilToCommand() \
do \
{ \
   IgnHALCoilToCommand = IGNHAL_u8CoilToCommand(); \
} \
while(0)


/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/

#define IGNHAL_START_SEC_CODE
#include "IGNHAL_MemMap.h"

void diag_ccbat_a(uint16 Tension_bob_a);
void diag_ccbat_a_c(uint16 Tension_bob_a_c);
void diag_ccbat_b(uint16 Tension_bob_b);
void diag_ccbat_b_d(uint16 Tension_bob_b_d);
void diag_ccbat_c(uint16 Tension_bob_c);
void diag_ccbat_d(uint16 Tension_bob_d);
void IGNHAL_vidCalcNextTeethRef(void);
void IGNHAL_vidChangeToWantedMode(void);
void IGNHAL_vidCoilCommand(uint8 u8Coil, uint16 Event_bob_offset);
void IGNHAL_vidCoilDwellTimeCalc(uint8 u8Coil);
void IGNHAL_vidComputeDiagPointTime(uint32 u32TestTime);
void IGNHAL_vidConduction_start_a(void);
void IGNHAL_vidConduction_start_b(void);
void IGNHAL_vidConduction_start_c(void);
void IGNHAL_vidConfigureT0_a(void);
void IGNHAL_vidConfigureT0_b(void);
void IGNHAL_vidConfigureT0_c(void);
void IGNHAL_vidConfigureT0_T1_a(void);
void IGNHAL_vidConfigureT0_T1_b(void);
void IGNHAL_vidConfigureT0_T1_c(void);
void IGNHAL_vidConfigureT0_T2_a(void);
void IGNHAL_vidConfigureT0_T2_b(void);
void IGNHAL_vidConfigureT0_T2_c(void);
void IGNHAL_vidConfigureT0_T3_a(void);
void IGNHAL_vidConfigureT0_T3_b(void);
void IGNHAL_vidConfigureT0_T3_c(void);
void IGNHAL_vidConfigureT1_a(void);
void IGNHAL_vidConfigureT1_b(void);
void IGNHAL_vidConfigureT1_c(void);
void IGNHAL_vidConfigureT2_a(void);
void IGNHAL_vidConfigureT2_b(void);
void IGNHAL_vidConfigureT2_c(void);
void IGNHAL_vidCurrentJumoCoilManager(void);
void IGNHAL_vidCurrentMonoCoilManager(void);
void IGNHAL_vidDisableCmd(uint8 u8Coil);
void IGNHAL_vidDisableDiagnostic(uint8 u8Coil);
void IGNHAL_vidDisableSCWNotif(uint8 u8Coil ,uint8 Ccu_toDisable);
void IGNHAL_vidDisableWtdgNotif(uint8 u8Coil);
void IGNHAL_vidDwellTimeLimitCalc(void);
void IGNHAL_vidEventT1_a(void);
void IGNHAL_vidEventT1_b(void);
void IGNHAL_vidEventT1_c(void);
void IGNHAL_vidEventT2_a(void);
void IGNHAL_vidEventT2_b(void);
void IGNHAL_vidEventT2_c(void);
void IGNHAL_vidNextJumoCoilManager(void);
void IGNHAL_vidNextMonoCoilManager(void);
void it_fin_de_conduction_bobine_a(void);
void it_fin_de_conduction_bobine_b(void);
void it_fin_de_conduction_bobine_c(void);
void it_fin_de_conduction_bobine_d(void);
void it_ocr_bobine_a(void);
void it_ocr_bobine_b(void);
void it_ocr_bobine_c(void);
void it_ocr_bobine_d(void);
void it_tdwell_tact(void);
void lance_it_diag_tact(uint32 u32Time);
boolean IGNHAL_bCutManager(uint8 u8Coil);
uint32 IGNHAL_vidCheckDiagnosticsIntr(uint8 u8Coil);
uint8 IGNHAL_u8CoilToCommand(void);

#define IGNHAL_STOP_SEC_CODE
#include "IGNHAL_MemMap.h"


#endif /* IGNHAL_I_H */

/*-------------------------------- end of file -------------------------------*/
