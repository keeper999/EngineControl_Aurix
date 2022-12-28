/******************************************************************************
**                                                                           **
** Copyright (C) Infineon Technologies (2013)                                **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to Infineon      **
** Technologies. Passing on and copying of this document, and communication  **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
*******************************************************************************
**                                                                           **
**  $FILENAME   : Gtm.h $                                                    **
**                                                                           **
**  $CC VERSION : \main\60 $                                                 **
**                                                                           **
**  $DATE       : 2014-01-06 $                                               **
**                                                                           **
**  AUTHOR      : DL-AUTOSAR-Engineering                                     **
**                                                                           **
**  VENDOR      : Infineon Technologies                                      **
**                                                                           **
**  DESCRIPTION : This file contains                                         **
**                functionality of <> driver.                                **
**                                                                           **
**  MAY BE CHANGED BY USER [yes/no]: No                                      **
**                                                                           **
******************************************************************************/

/*  TRACEABILITY: 
[/cover]
*/

#ifndef GTM_H
#define GTM_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
  /* Include Standard Types */
#include "Std_Types.h"

/* Include sfr file */
#include "IfxGtm_reg.h"

/* Inclusion of Module configuration file */
#include "Gtm_Cfg.h"

/* Global functions like Set/Reset END INIT protection bit,
  Enable/Disable interrupts, Atomic write function */
#include "Mcal.h"

/* MISRA Rule Violation 19.1, 19.15, 3.4:
   a) Header file 'MemMap.h' repeatedly included but does not have a standard
      include guard. Memmap.h file is prepared according to Autosar rules and
      this cannot be avoided.
   b) Unrecognized pragma 'section' will be ignored. Linker specific keywords.
*/


/* MISRA Rule Violation 11.3:
   SFR file has address(unsigned int) to Sfr type conversion. This causes
   MISRA violation 11.3. This cannot be avoided.*/


/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

#define GTM_VALUE_ZERO (0U)
#define GTM_ONE (1)
#define GTM_ZERO (0)

#define GTM_ZERO_U (0U)
#define GTM_ONE_U (1U)
#define GTM_TWO_U (2U)
#define GTM_SIXTEEN_U (16U)
#define GTM_EIGHT_U (8U)
#define GTM_THREE_UL (3UL)

/* These defines are used for the TIMUsage element in Gtm_TimConfigType  */
#define GTM_DRIVER_COMPLEX (0U)
#define GTM_DRIVER_ICU     (1U)
#define GTM_DRIVER_GPT     (2U)
#define GTM_DRIVER_PWM     (3U)
#define GTM_DRIVER_PWM_MOD     (1U)
#define GTM_TOM_DRIVER_COMPLEX (3U)
#define GTM_TIM_DRIVER_COMPLEX (2U)

/*To indicate when GTM channel is not used by the other driver modules*/
#define GTM_TIM_CH_NOT_USEDBY_ICU    (0xFFU)
#define GTM_TOM_CH_NOT_USEDBY_GPT_PWM    (0xFFU)
#define GTM_ATOM_CH_NOT_USEDBY_GPT_PWM    (0xFFU)

/* Sleep Mode */
#define GTM_SLEEP_ENABLE  (1U)
#define GTM_SLEEP_DISABLE (0U)

/* SRE bit of SRC register */
#define GTM_BIT_SRE (10)
#define GTM_BIT_SRE_MASK (0x400U)


/* Configurable Clocks */
#define GTM_CONFIGURABLE_CLOCK_0   (0U)
#define GTM_CONFIGURABLE_CLOCK_1   (1U)
#define GTM_CONFIGURABLE_CLOCK_2   (2U)
#define GTM_CONFIGURABLE_CLOCK_3   (3U)
#define GTM_CONFIGURABLE_CLOCK_4   (4U)
#define GTM_CONFIGURABLE_CLOCK_5   (5U)
#define GTM_CONFIGURABLE_CLOCK_6   (6U)
#define GTM_CONFIGURABLE_CLOCK_7   (7U)

/* Fixed Clock */
#define GTM_FIXED_CLOCK_0 (0U)
#define GTM_FIXED_CLOCK_1 (1U)
#define GTM_FIXED_CLOCK_2 (2U)
#define GTM_FIXED_CLOCK_3 (3U)
#define GTM_FIXED_CLOCK_4 (4U)


/* To set a sub-module as not configured*/
#define GTM_SETUNUSED8  (uint8)(((uint8)0x01) << 7)
#define GTM_SETUNUSED32 (uint32)(1UL << 7)

/* To identify if BRC sub-module is configured or not */
#define GTM_SETBRCCHANNELUNUSED (uint16)(((uint16)0x0001) << 15)

/* To derive information from the Global Channel Number Type Structure */
#define GTM_MODULE_ID_MSK  (0xC0U)
#define GTM_MODULE_NO_MSK  (0x3CU)
#define GTM_TGCAGC_NO_MSK  (0x03U)

#define GTM_MODULE_ID_POS  (6U)
#define GTM_MODULE_NO_POS  (2U)
#define GTM_TGCAGC_NO_POS  (0U)

/* Bit Postions */
#define GTM_ATOM_SL_POS    (11)
#define GTM_ATOM_ACB0_POS  (4)
#define GTM_TOM_SL_POS     (11)
#define GTM_TOM_OSM_POS    (26)
#define GTM_DPLL_DEN_POS   (1)
#define GTM_DPLL_SWR_POS   (23)
#define GTM_SPE_AIP_POS    (12)
#define GTM_SPE_AIP_NIP_PIP_MASK (0x777UL)
#define GTM_ACTTB_TBTRIG_POS (24)
#define GTM_FIFO_FLUSH_POS (2)
#define GTM_MCS_RAMRST_POS (16)
#define GTM_DPLL_RMO_POS (31)
#define GTM_SPE_SPEEN_POS (0)
#define GTM_MCS_CHCTRL_EN_MASK (1UL)



#define GTM_SET_BIT (1UL)
#define GTM_TIM_CH_TO_EN_BIT (0x40000000UL)
#define GTM_UPPER_HALFWORD (16U)
#define GTM_ENABLE_CLK (2UL)
#define GTM_CMU_BITS_PER_CLK (2U)
#define GTM_TIMER_MASK (0x00FFFFFFU)
#define GTM_CLEAR_CONTENT (0UL)
#define GTM_BIT_SET (1UL)
#define GTM_TIM_TO_BIT_RESET (0x3FFFFFFFUL)
#define GTM_ZERO_UL (0UL)
#define GTM_TIM_TOV_MASK (0x0000FF00UL)
#define GTM_TIM_TDUV_POS (0)
#define GTM_TIM_TDUV_SIZE (8)
#define GTM_TIM_TCS_MASK (0x70000000U)
#define GTM_TIM_TCS_POS (28U)
#define GTM_TIM_TOCNT_MASK (0x000000FFU)

#define GTM_ARU_RREQ_POS  (12)
#define GTM_ARU_RREQ_MASK (1UL << GTM_ARU_RREQ_POS)
#define GTM_ARU_WREQ_POS  (13)
#define GTM_ARU_WREQ_MASK (1UL << GTM_ARU_WREQ_POS)
#define GTM_ARU_WREQ_RREQ_MASK (GTM_ARU_WREQ_MASK | GTM_ARU_RREQ_MASK)
#define GTM_DPLL_RAMRST_POS  (4)
#define GTM_DPLL_RAMRST_MASK (1UL << GTM_DPLL_RAMRST_POS)


#define GTM_TBU_CHAN_STATUS (3UL)
#define GTM_TBU_CHAN_ENABLE (2UL)
#define GTM_BITS_PER_TBU (2U)
#define GTM_TBU_BASE_MASK (0x07FFFFFFUL)
#define GTM_TIMER_VAL_200 (0x200UL)

#define GTM_TOM_TGC0_CHOSEN (8U)
#define GTM_TOM_TGC1_CHOSEN (16U)
#define GTM_TOM_ENABLE (2UL)
#define GTM_TOM_BITS_PER_CHAN (2U)
#define GTM_TOM_CHAN_DISABLE (1UL)
#define GTM_TOM_FUPD_START (16U)

#define GTM_ATOM_ENABLE (2UL)
#define GTM_ATOM_BITS_PER_CHAN (2U)
#define GTM_ATOM_FUPD_START (16U)
#define GTM_ATOM_CHAN_DISABLE (1UL)

#define GTM_OSM_REQUIRED (1U)
#define GTM_OSM_NOT_REQUIRED (0U)


#define GTM_TGC0 (0U)
#define GTM_TGC1 (1U)
#define GTM_AGC  (0U)


/* Module Identification */
#define GTM_TOM  (0U)
#define GTM_ATOM (1U)

/* Defines for FIFO Stream Enable and Disable */
#define GTM_FIFO_ENABLE  (2UL)
#define GTM_FIFO_DISABLE (1UL)
#define GTM_FIFO_BITS_PER_CHAN (2U)

/* Defines for ARU Read and Write API */
#define GTM_WRITE_ARU_FRAME   (0U)
#define GTM_READ_ARU_FRAME    (1U)
#define GTM_ISSUE_ARU_READ    (0U)
#define GTM_READ_ARU_CONTENT  (1U)

/* Defines for API Gtm_CtrlMcsIntrpt */
#define GTM_ENABLE_INTERRUPT  (0U)
#define GTM_DISABLE_INTERRUPT (1U)

/* Defines for identifying the offsets of TGC and TOM Modules */
#define GTM_TOM_TGC_OFFSET (0x200UL)
/*#define GTM_TOM_TGC_OFFSET (0x40UL >> 2)*/
#define GTM_TOM_MODULE_OFFSET (0x800UL)
/*#define GTM_TOM_MODULE_OFFSET (0x800UL >> 2)*/
#define GTM_ATOM_MODULE_OFFSET (0x800UL)
/*#define GTM_ATOM_MODULE_OFFSET (0x800UL >> 2)*/
#define GTM_ATOM_AGC_OFFSET (0x200UL)
/*Check if atleast one Channel is used by GTM complex driver*/
#if ((GTM_NO_OF_TIM_CH_CONF_NOTIF > 0U)  ||(GTM_NO_OF_TOM_CH_CONF_NOTIF > 0U) \
                                        ||(GTM_NO_OF_ATOM_CH_CONF_NOTIF > 0U))
                                        
#define GTM_MOD_CH_CONFIGURED (1U)

#endif

/*Check if GMT is used by atleast one driver*/
#if ((GTM_NO_OF_TOM_CH_CONF_NOTIF > 0U) ||                                    \
                                   (GTM_TOM_USED_BY_OTHER_DRIVERS == (STD_ON)))

#define GTM_TOM_MODULE_USED (STD_ON)

#endif

#if ((GTM_NO_OF_ATOM_CH_CONF_NOTIF > 0U) ||                                   \
                                   (GTM_ATOM_USED_BY_OTHER_DRIVERS == (STD_ON)))

#define GTM_ATOM_MODULE_USED (STD_ON)

#endif

#if (GTM_ICU_MODULE_USED == (STD_ON) || (GTM_NO_OF_TIM_CH_CONF_NOTIF > 0U))

#define GTM_TIM_MODULE_USED (STD_ON)

#endif
/*******************************************************************************
                           Global Type Definitions
*******************************************************************************/

/* TOM structures added to easier the acces to BStep registers*/

  typedef volatile struct
  {
    Ifx_GTM_TOM_CH_CTRL CTRL;           /**< \brief 0, TOM Channel 0 Control 
                                                           Register’ */
    Ifx_GTM_TOM_CH_SR0 SR0;      /**< \brief 4, TOM Channel 0 CCU0 Compare
                                    Shadow Register */
    Ifx_GTM_TOM_CH_SR1 SR1;      /**< \brief 8, TOM Channel 0 CCU1 Compare
                                     Shadow Register */
    Ifx_GTM_TOM_CH_CM0 CM0;      /**< \brief C, TOM Channel 0 CCU0 Compare
                                     Register */
    Ifx_GTM_TOM_CH_CM1 CM1;      /**< \brief 10, TOM Channel 0 CCU1 Compare
                                     Register */
    Ifx_GTM_TOM_CH_CN0 CN0;      /**< \brief 14, TOM Channel 0 CCU0
                                                            Counter Register */
    Ifx_GTM_TOM_CH_STAT STAT;    /**< \brief 18, TOM Channel Status Register */
    Ifx_GTM_TOM_CH_IRQ_NOTIFY IRQ_NOTIFY;   /**< \brief 1C, TOM Channel 0 
                                            Interrupt Notification Register */
    Ifx_GTM_TOM_CH_IRQ_EN IRQ_EN;       /**< \brief 20, TOM Channel 0 
                                                  Interrupt Enable Register */
    Ifx_GTM_TOM_CH_IRQ_FORCINT IRQ_FORCINT; /**< \brief 24, TOM Channel 0 
                                                           Software Interrupt 
                                                       Generation Register */
    Ifx_GTM_TOM_CH_IRQ_MODE IRQ_MODE;   /**< \brief 28, TOM IRQ Mode 
                                                   Configuration Register */
    unsigned char reserved_2C[20];    /**< \brief 2C */
  }Ifx_GTM_TOM_CH_TYPE;

  typedef volatile struct
  {
    Ifx_GTM_TOM_TGC0_GLB_CTRL GLB_CTRL;    /**< \brief 30, TOM TGC0 Global 
                                                           Control Register */
    Ifx_GTM_TOM_TGC0_ACT_TB ACT_TB;    /**< \brief 34, TOM TGC0 Action Time 
                                                           Base Register */
    Ifx_GTM_TOM_TGC0_FUPD_CTRL FUPD_CTRL;  /**< \brief 38, TOM TGC0 Force 
                                                  Update Control Register */
    Ifx_GTM_TOM_TGC0_INT_TRIG INT_TRIG;    /**< \brief 3C, TOM TGC0 Internal 
                                                 Trigger Control Register */
    unsigned char reserved_tgc0[48];                              
    Ifx_GTM_TOM_TGC0_ENDIS_CTRL ENDIS_CTRL;    /**< \brief 70, TOM TGC0 
                                             Enable/Disable Control Register */
    Ifx_GTM_TOM_TGC0_ENDIS_STAT ENDIS_STAT;    /**< \brief 74, TOM TGC0 
                                              Enable/Disable Status Register */
    Ifx_GTM_TOM_TGC0_OUTEN_CTRL OUTEN_CTRL;    /**< \brief 78, TOM TGC0 
                                               Output Enable Control Register */
    Ifx_GTM_TOM_TGC0_OUTEN_STAT OUTEN_STAT;    /**< \brief 7C, TOM TGC0 
                                                Output Enable Status Register */
    unsigned char reserved_tgc1[432];
  } Ifx_GTM_TOM_TGC_TYPE;

  typedef volatile struct
  {
    unsigned char reserved_tom0[48];
    Ifx_GTM_TOM_TGC_TYPE TGC[2];
    unsigned char reserved_tgc2[976];
  } Ifx_GTM_TOM_TGCx;


  typedef volatile struct
  {
    Ifx_GTM_TOM_CH_TYPE CH[16];
    unsigned char reserved_tom1[1024];
   }Ifx_GTM_TOM_CHx;



  typedef volatile union
  {
      /* For Accessing TOM TGC registers */
      Ifx_GTM_TOM_TGCx TOM_TGC[GTM_NO_OF_TOM_MODULES];
      /* For Accessing TOM channels */
      Ifx_GTM_TOM_CHx TOM_CH[GTM_NO_OF_TOM_MODULES];
      /* For accessing all contents */                              
      Ifx_GTM_TOM TOM[GTM_NO_OF_TOM_MODULES];
  } Ifx_GTM_TOMx;

/*TOM structures Ends */


/* ATOM structures added to easier the acces to BStep registers*/

  typedef volatile struct
  {
    Ifx_GTM_ATOM_CH_RDADDR RDADDR;      /**< \brief 0, ATOM Channel 0 ARU Read
                                             Address Register */
    Ifx_GTM_ATOM_CH_CTRL CTRL;          /**< \brief 4, ATOM Channel 0 
                                             Control in SOMI mode Register */
    Ifx_GTM_ATOM_CH_SR0 SR0;     /**< \brief 8, ATOM Channel 0 CCU0 Compare
                                     Shadow Register */
    Ifx_GTM_ATOM_CH_SR1 SR1;     /**< \brief C, ATOM Channel 0 CCU1 Compare
                                     Shadow Register */
    Ifx_GTM_ATOM_CH_CM0 CM0;     /**< \brief 10, ATOM Channel 0 CCU0 Compare
                                     Register */
    Ifx_GTM_ATOM_CH_CM1 CM1;     /**< \brief 14, ATOM Channel 0 CCU1 Compare
                                     Register */
    Ifx_GTM_ATOM_CH_CN0 CN0;     /**< \brief 18, ATOM Channel 0 
                                                CCU0 Counter Register */
    Ifx_GTM_ATOM_CH_STAT STAT;          /**< \brief 1C, ATOM Channel 0 
                                                       Status Register */
    Ifx_GTM_ATOM_CH_IRQ_NOTIFY IRQ_NOTIFY;  /**< \brief 20, ATOM Channel 0 
                                            Interrupt Notification Register */
    Ifx_GTM_ATOM_CH_IRQ_EN IRQ_EN;    /**< \brief 24, ATOM Channel 0 Interrupt 
                                                Enable Register */
    Ifx_GTM_ATOM_CH_IRQ_FORCINT IRQ_FORCINT;    /**< \brief 28, ATOM Channel 0 
                                      Software Interrupt Generation Register */
    Ifx_GTM_ATOM_CH_IRQ_MODE IRQ_MODE;  /**< \brief 2C, ATOM IRQ Mode
                                                 Configuration Register */
    unsigned char reserved_30[80];          /**< \brief 30 */
  }Ifx_GTM_ATOM_CH_TYPE;



  typedef volatile struct
  {
    Ifx_GTM_ATOM_CH_TYPE CH[8];
    unsigned char reserved_chx[1024];
  }Ifx_GTM_ATOM_CHx;


  typedef volatile struct
  {
      unsigned char reserved_30[64];
      Ifx_GTM_ATOM_AGC_GLB_CTRL AGC_GLB_CTRL; /**< \ ATOM AGC 
                                                      Global control register */
      Ifx_GTM_ATOM_AGC_ENDIS_CTRL AGC_ENDIS_CTRL; /**< \brief 44, 
                                  ATOM AGC Enable/Disable Control Register */
      Ifx_GTM_ATOM_AGC_ENDIS_STAT AGC_ENDIS_STAT; /**< \ ATOM AGC
                                           Enable/Disable Status Register */
      Ifx_GTM_ATOM_AGC_ACT_TB AGC_ACT_TB;  /**< \ TOM TGC0 
                                                Action  Time Base Register */
      Ifx_GTM_ATOM_AGC_OUTEN_CTRL AGC_OUTEN_CTRL; /**< \ ATOM AGC
                                             Output Enable Control Register */
      Ifx_GTM_ATOM_AGC_OUTEN_STAT AGC_OUTEN_STAT; /**< \, ATOM AGC
                                               Output Enable Status Register */
      Ifx_GTM_ATOM_AGC_FUPD_CTRL AGC_FUPD_CTRL;/**< \ ATOM AGC
                                               Force Update Control Register */
      Ifx_GTM_ATOM_AGC_INT_TRIG AGC_INT_TRIG;
      unsigned char reserved_chx[1952];
  }Ifx_GTM_ATOM_AGCx;



  typedef volatile union
  {
       /* For accessing Channel contents */
        Ifx_GTM_ATOM_CHx ATOM_CH[GTM_NO_OF_ATOM_MODULES];
        /* For accessing AGC contents */
        Ifx_GTM_ATOM_AGCx ATOM_AGC[GTM_NO_OF_ATOM_MODULES];    
        /* For accessing all contents */                              
        Ifx_GTM_ATOM ATOM[GTM_NO_OF_ATOM_MODULES];
  }Ifx_GTM_ATOMx;

/*ATOM structures Ends */


/* TIM structures added to easier the acces to BStep registers*/
  typedef volatile struct
  {
    Ifx_GTM_TIM_CH_GPR0 CH_GPR0; /**< \ TIM Channel 0 General 
                                                       Purpose 0 Register */
    Ifx_GTM_TIM_CH_GPR1 CH_GPR1;    /**< \brief 4, TIM Channel 0
                                                General Purpose 1 Register */
    Ifx_GTM_TIM_CH_CNT CH_CNT;      /**< \brief 8, TIM Channel 0
                                                  SMU Counter Register */
    Ifx_GTM_TIM_CH_ECNT CH_ECNT;    /**< \brief C, TIM Channel 0
                                                   Edge Counter Register */
    Ifx_GTM_TIM_CH_CNTS CH_CNTS;    /**< \brief 10, TIM Channel 0 
                                              SMU Shadow Counter Register */
    Ifx_GTM_TIM_CH_TDUC CH_TDUC;    /**< \brief 14, TIM Channel 0 
                                                       TDUC Register */
    Ifx_GTM_TIM_CH_TDUV CH_TDUV;    /**< \brief 18, TIM Channel 0 
                                                           TDUV Register */
    Ifx_GTM_TIM_CH_FLT_RE CH_FLT_RE;       /**< \brief 1C, GTM_TIM Channel 0 
                                               Filter Parameter 0 Register */
    Ifx_GTM_TIM_CH_FLT_FE CH_FLT_FE;       /**< \brief 20, TIM Channel 0 Filter 
                                                     Parameter 1 Register */
    Ifx_GTM_TIM_CH_CTRL CH_CTRL;    /**< \brief 24, TIM Channel 0 
                                                            Control Register */
    Ifx_GTM_TIM_CH_ECTRL CH_ECTRL;      /**< \brief 28, TIM Channel 0 External
                                                   Capture Control Register */
    Ifx_GTM_TIM_CH_IRQ_NOTIFY CH_IRQ_NOTIFY;   /**< \brief 2C, TIM Channel 0 
                                Interrupt Notification Register */
    Ifx_GTM_TIM_CH_IRQ_EN CH_IRQ_EN;       /**< \brief 30, TIM Channel 0 
                                   Interrupt Enable Register */
    Ifx_GTM_TIM_CH_IRQ_FORCINT CH_IRQ_FORCINT; /**< \brief 34, TIM Channel 0
                                         Software Interrupt Force Register */
    Ifx_GTM_TIM_CH_IRQ_MODE CH_IRQ_MODE;   /**< \brief 38, TIM IRQ Mode 
                                                Configuration Register */
    Ifx_GTM_TIM_CH_EIRQ_EN CH_EIRQ_EN;     /**< \brief 3C, TIM Channel 0 
                                       Error Interrupt Enable Register */
    unsigned char reserved_40[64];          /**< \brief 40 */
               
  }Ifx_GTM_TIM_CH_TYPE;
               
  typedef volatile struct
  {
    Ifx_GTM_TIM_IN_SRC IN_SRC;       /**< \brief 78, TIM_IN_SRC Long Name */
    Ifx_GTM_TIM_RST RST;             /**< \brief 7C, TIM Global Software 
                                                           Reset Register */
  }Ifx_GTM_TIM_IN_SRC_RESET_TYPE;
               
   typedef volatile struct
  {
    Ifx_GTM_TIM_CH_TYPE CH[8];
    unsigned char reserved_tim1[1024];               
  }Ifx_GTM_TIM_CHx;
  
  typedef volatile struct
  {
      unsigned char reserved_tim2[120];                
      Ifx_GTM_TIM_IN_SRC_RESET_TYPE IN_SRC_RESET;
      unsigned char reserved_tim3[1920];               
  }Ifx_GTM_TIM_IN_SRC_RSTx;

   typedef volatile union
   {
      /* For Accessing TIM IN_SRC and RST registers */
      Ifx_GTM_TIM_IN_SRC_RSTx IN_SRC_RST[GTM_NO_OF_TIM_MODULES];
      /* For Accessing TIM channels */
      Ifx_GTM_TIM_CHx CH_TIM[GTM_NO_OF_TIM_MODULES];
      /* For accessing all contents */                              
      Ifx_GTM_TIM TIM[GTM_NO_OF_TIM_MODULES];
  } Ifx_GTM_TIMx;
/*TIM structures ends*/


/* MCS structures added to easier the acces to BStep registers*/
  typedef volatile struct
  {
    Ifx_GTM_MCS_CH_R0 CH_R0;        /**< \brief 80, MCS Channel 1 
                                                 Program Counter Register 0 */
    Ifx_GTM_MCS_CH_R1 CH_R1;        /**< \brief 84, MCS Channel 1
                                                   Program Counter Register 1 */
    Ifx_GTM_MCS_CH_R2 CH_R2;        /**< \brief 88, MCS Channel 1
                                                   Program Counter Register 2 */
    Ifx_GTM_MCS_CH_R3 CH_R3;        /**< \brief 8C, MCS Channel 1
                                                   Program Counter Register 3 */
    Ifx_GTM_MCS_CH_R4 CH_R4;        /**< \brief 90, MCS Channel 1
                                                   Program Counter Register 4 */
    Ifx_GTM_MCS_CH_R5 CH_R5;        /**< \brief 94, MCS Channel 1
                                                   Program Counter Register 5 */
    Ifx_GTM_MCS_CH_R6 CH_R6;        /**< \brief 98, MCS Channel 1
                                                   Program Counter Register 6 */
    Ifx_GTM_MCS_CH_R7 CH_R7;        /**< \brief 9C, MCS Channel 1
                                                   Program Counter Register 7 */
    Ifx_GTM_MCS_CH_CTRL CH_CTRL;    /**< \brief A0, MCS Channel 
                                               Control Register */
    Ifx_GTM_MCS_CH_ACB CH_ACB;      /**< \brief A4, MCS Channel 
                                                   ACB Register */
    unsigned char reserved_A8[24];          /**< \brief A8 */
    Ifx_GTM_MCS_CH_PC CH_PC;        /**< \brief C0, MCS Channel 1
                                                   Program Counter Register */
    Ifx_GTM_MCS_CH_IRQ_NOTIFY CH_IRQ_NOTIFY;   /**< \brief C4, MCS Channel 1
                                  Interrupt notification register */
    Ifx_GTM_MCS_CH_IRQ_EN CH_IRQ_EN;       /**< \brief C8, MCS Channel 1
                                        Interrupt Enable Register */
    Ifx_GTM_MCS_CH_IRQ_FORCINT CH_IRQ_FORCINT; /**< \brief CC, MCS Channel 1
                                      Software Interrupt Generation Register */
    Ifx_GTM_MCS_CH_IRQ_MODE CH_IRQ_MODE;   /**< \brief D0, MCS IRQ Mode 
                                                     Configuration Register */
    Ifx_GTM_MCS_CH_EIRQ_EN CH_EIRQ_EN;     /**< \brief D4, MCS_Channel 1 
                                           Error Interrupt Enable Register */
    unsigned char reserved_D8[40];          /**< \brief D8 */
  }Ifx_GTM_MCS_CH_TYPE;
  
  typedef volatile struct
  {
      Ifx_GTM_MCS_CH_TYPE CH[8];
    unsigned char reserved_tim1[3072];               
  }Ifx_GTM_MCS_CHx;

  typedef volatile struct
  {
    unsigned char reserved_tim4[40];                               
    Ifx_GTM_MCS_CH0_CTRG CTRG;           /**< \brief 28, MCS Clear Trigger 
                                                   Control Register */
    Ifx_GTM_MCS_CH0_STRG STRG;         /**< \brief 2C, MCS Set Trigger Control
                                                           Register */
    unsigned char reserved_tim5[68];               
    Ifx_GTM_MCS_CTRL CTRL;           /**< \brief 74, MCS Control Register */
    Ifx_GTM_MCS_RST RST;             /**< \brief 78, MCS Channel 
                                                              Reset Register */
    Ifx_GTM_MCS_ERR ERR;             /**< \brief 7C, MCS Error Register */
    unsigned char reserved_tim6[3968];               
  }Ifx_GTM_MCS_TGR_MOD_CTRLx;

  typedef volatile union{
      /* For Accessing MCS CTRL and MSC trigger CTRL registers */
      Ifx_GTM_MCS_TGR_MOD_CTRLx TGR_MOD_CTRL[GTM_NO_OF_MCS_MODULES]; 
                              /* For Accessing MCS channels */
      Ifx_GTM_MCS_CHx CH_MCS[GTM_NO_OF_MCS_MODULES];
      /* For accessing all contents */                              
      Ifx_GTM_MCS MCS[GTM_NO_OF_MCS_MODULES];
  } Ifx_GTM_MCSx;

/*MCS structures Ends */


/* Enum of all the clocks */
  typedef enum
  {
    GTM_CONFIGURABLE_CLOCK0,
    GTM_CONFIGURABLE_CLOCK1,
    GTM_CONFIGURABLE_CLOCK2,
    GTM_CONFIGURABLE_CLOCK3,
    GTM_CONFIGURABLE_CLOCK4,
    GTM_CONFIGURABLE_CLOCK5,
    GTM_CONFIGURABLE_CLOCK6,
    GTM_CONFIGURABLE_CLOCK7,
    GTM_EXTERNAL_CLOCK0,
    GTM_EXTERNAL_CLOCK1,
    GTM_EXTERNAL_CLOCK2,
    GTM_FIXED_CLOCKS
  }Gtm_ClockSourceType;


/* Enum of all the configurable clocks */
  typedef enum
  {
    GTM_CONFIGURABLE_CLK0,
    GTM_CONFIGURABLE_CLK1,
    GTM_CONFIGURABLE_CLK2,
    GTM_CONFIGURABLE_CLK3,
    GTM_CONFIGURABLE_CLK4,
    GTM_CONFIGURABLE_CLK5,
    GTM_CONFIGURABLE_CLK6,
    GTM_CONFIGURABLE_CLK7
  }Gtm_ConfigurableClockType;


/* Used by Gtm_SetTomOutput function */
  typedef enum
  {
    GTM_LOW,
    GTM_HIGH
  }Gtm_OutputLevelType;

/* Used for Reading and Writing ARU frame */
  typedef enum
  {
    GTM_ARU_WRITE_FAILED,
    GTM_ARU_WRITE_SUCCESSFUL,
    GTM_ARU_RD_ISSUED_BUT_NOT_CMPLT,
    GTM_ARU_RD_ISSUED_AND_COMPLETED,
    GTM_ARU_READ_NOT_ISSUED,
    GTM_ARU_READ_FAILED,
    GTM_ARU_READ_SUCCESSFUL,
    GTM_INCORRECT_REQUEST
  }Gtm_AruReqStatusType;

  typedef enum
  {
    TOM_GLB_CTRL,
    TOM_ACT_TB,
    TOM_FUPD_CTRL,
    TOM_INT_TRIG,
    TOM_RESERVED_0,
    TOM_RESERVED_1,
    TOM_RESERVED_2,
    TOM_RESERVED_3,
    TOM_RESERVED_4,
    TOM_RESERVED_5,
    TOM_RESERVED_6,
    TOM_RESERVED_7,
    TOM_RESERVED_8,
    TOM_RESERVED_9,
    TOM_RESERVED_10,
    TOM_RESERVED_11,
    TOM_ENDIS_CTRL,
    TOM_ENDIS_STAT,
    TOM_OUTEN_CTRL,
    TOM_OUTEN_STAT
  }Gtm_TomTimerRegistersType;


  typedef enum
  {
    ATOM_GLB_CTRL,
    ATOM_ENDIS_CTRL,
    ATOM_ENDIS_STAT,
    ATOM_ACT_TB,
    ATOM_OUTEN_CTRL,
    ATOM_OUTEN_STAT,
    ATOM_FUPD_CTRL,
    ATOM_INT_TRIG
  }Gtm_AtomTimerRegistersType;


/* Type to provide the Filter Rising and Falling Edge Values */
  typedef struct
  {
    uint32 FltRisingEdge;
    uint32 FltFallingEdge;
  }Gtm_TimFilterType;

  /*********************** Memory MAP START **********************/

  /* Internal Type definition for TBU */
  typedef Ifx_GTM_TBU_CH0_CTRL Gtm_TbuChCtrlType;
  typedef Ifx_GTM_TBU_CH0_BASE Gtm_TbuChBaseType;

  typedef struct
  {
    Gtm_TbuChCtrlType CH_CTRL;          /* TBU Channel 0 Control Register*/
    Gtm_TbuChBaseType CH_BASE;          /* TBU Channel 0 Base Register   */
  }Gtm_TbuChType;

  typedef struct
  {
    Ifx_GTM_TBU_CHEN CHEN;         /* TBU Global Channel Enable Register */
    Gtm_TbuChType GtmTbuCh[GTM_NO_OF_TBU_CHANNELS];
  }Gtm_TbuType;




/*********************** Memory MAP END**********************/

/* Type for reporting the DPLL status */
typedef struct
{
  uint32 DpllStatus;
  uint32 IntStatus;
}Gtm_DpllStatType;

/* Type for Port Configuration */
typedef struct
{
  uint32 TimInSel[GTM_NO_OF_TIM_MODULES];
  uint32 ToutSel[GTM_NO_OF_TOUTSEL_REGISTERS];
}Gtm_PortConfigType;


/* Type for Filter Configuration */
typedef struct
{
  uint32 TimRisingEdgeFilter;   /* Rising Edge Filter Value */
  uint32 TimFallingEdgeFilter;  /* Falling Edge Filter Value */

}Gtm_TimFltType;


  /* Type for TIM Configuration */
  typedef struct
  {
    uint8 TimUsage;         /* Bit coded information for TIM usage*/
    uint8  TimIrqEn;        /* Irq Enable and mode configuration  */
    uint8  TimErrIrqEn;            /* Error Irq Enable and mode 
                   configuration  */  
    uint8 TimAuxInSrcSel;          /* TIM Auxiliary input selection
                       source*/
    uint8 TimExtCapSrc;            /* TIM channel External Capture Source*/
    uint32 TimCtrlValue;           /* TIM Control value           */
    const Gtm_TimFltType * GtmTimFltPtr;  /* Pointer to Filter configuration  */
    uint32 TimCntsValue;           /* configured value for CNTS          */
    uint32 TimTduValue;            /* Timeout detection configuration    */
    uint32 TimInSrcSel;            /* TIM channel input source selection*/
 
  }Gtm_TimConfigType;

  /* Type for TIM Usage by other modules*/
  typedef struct 
  {
  /*Structure to hold the information about the GTM submodules (TIM/TOM/ATOM)
                                 usage by other drivers(ICU/GPT/PWM)*/

    uint8 Gtm_TimUsage[GTM_NO_OF_TIM_MODULES][GTM_CHANNELS_PER_TIM_MODULE];  
    uint8 Gtm_TomUsage[GTM_NO_OF_TOM_MODULES][GTM_CHANNELS_PER_TOM_MODULE];  
    uint8 Gtm_AtomUsage[GTM_NO_OF_ATOM_MODULES][GTM_CHANNELS_PER_ATOM_MODULE]; 
     
  }Gtm_ModUsageConfigType;

  /* ATOM AGC configuration */
  typedef struct
  { 
    uint16 GtmAtomUpdateEn;        /* Configured UPEN value       */
    uint16 GtmAtomEndisCtrl;       /* Configured ENDIS CTRL value        */
    uint16 GtmAtomEndisStat;       /* Configured ENDIS STAT value        */
    uint16 GtmAtomOutenCtrl;       /* Configured OUTEN CTRL value        */
    uint16 GtmAtomOutenStat;       /* Configured OUTEN STAT value        */
    uint32 GtmAtomFupd;        /* Configured FUPD value       */
  }Gtm_AtomAgcConfigGroupType;


/* ATOM AGC general configuration */
typedef struct
{
  uint16 GtmAtomIntTrig;         /* ACT TB configured value     */
  uint32 GtmAtomActTb;    /* ACT TB configured value     */
  /* GtmAtomAgcConfigGrpPtr will be NULL_PTR if none of the channels in this
     AGC is configured for Complex Driver */
  const Gtm_AtomAgcConfigGroupType * GtmAtomAgcConfigGrpPtr;
}Gtm_AtomAgcConfigType;

/* ATOM Channel configuration type */
typedef struct
{
  uint16 GtmAtomIrqEn;        /* Interrupt enable configured value */
  uint32 GtmAtomRdAddrValue;         /* Read Address value   */
  uint32 GtmAtomCn0Value;     /* CN0 configured value */
  uint32 GtmAtomCm0Value;     /* CM0 configured value */
  uint32 GtmAtomCm1Value;     /* CM1 configured value */
  uint32 GtmAtomSr0Value;     /* SR0 configured value */
  uint32 GtmAtomSr1Value;     /* SR1 configured value */
}Gtm_AtomChannelConfigType;

/* Atom configured value */
typedef struct
{
  uint8 GtmAtomUsage;    /* bit coded information for Atom usage*/
  uint16 GtmAtomIrqMode;        /* Interrupt Mode configured value     */  
  uint32 GtmAtomControlWord;    /* ATOM Control Word configured value  */
  /* This will be NULL_PTR for Channel used by GPT/PWM */
  const Gtm_AtomChannelConfigType * GtmAtomChannelCfgPtr;
}Gtm_AtomConfigType;


/* Gpt channel status */
typedef enum
{
  GTM_GPT_CHANNEL_STARTED,
  GTM_GPT_WRONG_PARAM,
  GTM_GPT_CHANNEL_BUSY
}Gtm_GptChannelStatusType;


/* Type for TOM TGC configuration */
typedef struct
{
  uint16 GtmTomUpdateEn;      /* Update enable configured value */
  uint16 GtmTomEndisCtrl;     /* Endis Control configured value */
  uint16 GtmTomEndisStat;     /* Endis Status configured value  */
  uint16 GtmTomOutenCtrl;     /* Outen Control configured value */
  uint16 GtmTomOutenStat;     /* Outen status configured value  */
  uint32 GtmTomFupd;          /* FUPD configured value          */
}Gtm_TomTgcConfigGroupType;


/* Type for TOM TGC configuration */
typedef struct
{
  uint16 GtmTomIntTrig;     /* Internal Trigger configured value */
  uint32 GtmTomActTb;       /* ACT TB configured value    */
  /* This will be NULL_PTR if none of the channels in this TGC is
     configured for Complex Driver */
  const Gtm_TomTgcConfigGroupType * GtmTomTgcConfigGrpPtr;
}Gtm_TomTgcConfigType;

/* Type for TOM channel configuration */
typedef struct
{
  uint8 GtmTomIrqEn;          /* Interrupt Enable configured value */
  uint16 GtmTomCn0Value;      /* CN0 configured value       */
  uint16 GtmTomCm0Value;      /* CM0 configured value       */
  uint16 GtmTomCm1Value;      /* CM1 configured value       */
  uint16 GtmTomSr0Value;      /* SR0 configured value       */
  uint16 GtmTomSr1Value;      /* SR1 configured value       */
}Gtm_TomChannelConfigType;


/* Type for TOM configuration */
typedef struct
{
  uint8 TomUsage;     /* Bit coded information for TOM configuration */
  uint8 GtmTomIrqMode;       /* Interrupt Mode configured value */  
  /* Only CLK and SL field will be updated when used in GPT/PWM mode */
  uint32 GtmTomControlWord;
  /* This will be NULL_PTR for Channel used by GPT/PWM */
  const Gtm_TomChannelConfigType * GtmTomChannelCfgPtr;
}Gtm_TomConfigType;


/* Type for External Clock */
typedef struct
{
  uint32  CmuEclkNum;  /* External Clock Numerator Value */
  uint32  CmuEclkDen;  /* External Clock Denominator Value */
}Gtm_ExtClkType;

/* Type for Clock Settings configuration */
typedef struct
{
  uint32 GtmClockEnable;     /* Clock Enable configured value */
  uint32 GtmCmuClkCnt[8];    /* CMU clock divider value       */
  uint32 GtmFxdClkControl; /* Fixed clock divider value  */
  Gtm_ExtClkType GtmEclk[3]; /* External clock divider value  */
}Gtm_ClockSettingType;


/* Type for General configuration */
typedef struct
{
  uint16  GtmCtrlValue;  /* Updated by GtmEnRSTAndForceIntFunctionality,
       GtmAeiTimeOutMode and GtmAeiTimeOutValue */
  uint16   GtmIrqEnable;  /* Updated by Contents of GtmAEIInterrupts . */
}Gtm_GeneralConfigType;


/* Type for TBU configuration */
typedef struct
{
  uint8  TbuChannelCtrl;  /* Lower 4 Bits - Ctrl Info.. Bit 5 - Channel Enable*/
  uint32 TbuBaseValue;    /* TBU base value */
}Gtm_TbuConfigType;


/* Type for BRC channel configuration */
typedef struct
{
  uint16 BrcChannelCtrl; /* Updated by BrcSourceARUAddress and BrcModeSelect  */
  uint32 BrcDestination; /* Updated by contents of BrcChannelDestinationSelect*/
}Gtm_BrcChannelType;


/* Type for BRC config type */
typedef struct
{
  uint16 BrcIrqEnable;  /* Bit 0 -12 Interrupt Enable. Bits 14-15 - Irq mode */
  uint16 BrcErrIrqEnable;  /* Bit 0 BRC destination error interrupt enable
    bit 1-12 BRC data incosistency detection error enable*/  
  const Gtm_BrcChannelType * BrcChannelPtr; /*Ptr to BRC channel configuration*/
}Gtm_BrcConfigType;


/* Type for FIFO configuration */
typedef struct
{
  uint8 FifoCtrl;      /* Updated by FifoChannelModeSelect,
     FifoEnDirectRamWriteAccess and
     FifoRamAccessHighestPriority  */
  uint8 FifoIrqEnable; /* Bits 6 and 7 constitute the Irq Mode. Bit 4 DMA Hys
     Mode Enable  Bit 5 DMA Direction */
  uint8 FifoErrIrqEnable; /* Bit 0 - EMPTY_ERROR_INT, Bit 1 - FULL_ERROR_INT,
         Bit 2 - LW_WM_ERR_EIRQ, Bit 3 - UW_WM_ERR_EIRQ */
  uint16 FifoStartAddress;    /* Start address for the FIFO channel */
  uint16 FifoEndAddress;      /* End address for the FIFO channel   */
  uint16 FifoUpperWatermark;  /* Updated by either FifoUpperWatermarkAddress
     or FifoGatePointerFromSLW2LWU  */
  uint16 FifoLowerWatermark;  /* Updated by either FifoLowerWatermarkAddress
     or FifoGatePointerFromLwu2Uwe  */
}Gtm_FifoConfigType;


/* Type for F2A configuration */
typedef struct
{
  uint8  F2aChannelConfig;  /* Bit 0-1 TMODE, Bit 2 DIR, Bit 4- Channel Enable*/
  uint16 F2aAruAddress;     /* ARU address for F2A */
}Gtm_F2aConfigType;


/* Type for MCS configuration */
typedef struct
{
  uint8 McsControl;   /* Bit 0 - SCHED, Bit1 HLT_SPOFL, */
  uint8 McsChannelConfig[GTM_NO_OF_MCS_CHANNELS];/*Bit 0 MCS Enable, Bit 1, 2,
         3 Interrupt Bit 6,7 IrqMode*/
  uint8 McsErrIrqEnable[GTM_NO_OF_MCS_CHANNELS];   /* Bit 0 - MCS_EIRQ, 
                                                      Bit 1 - STK_ERR_IRQ,
                                                      Bit 2 - MEM_ERR_EIRQ */

}Gtm_McsConfigType;


/* Type for DPLL configuration */
typedef struct
{
  uint8  DpllAps1c3;     /* APS1c3 configured value */
  uint16 DpllNtiCnt;     /* NTI_CNT configuration */
  uint16 DpllApt2c;      /* APT 2c configuration  */
  uint16 DpllCtrl2;      /* Upper 8 bits - WAD. Lower 8 Bits - AEN */
  uint16 DpllCtrl3;      /* Upper 8 bits - WAD. Lower 8 Bits - AEN */
  uint16 DpllCtrl4;      /* Upper 8 bits - WAD. Lower 8 Bits - AEN */
  uint16 DpllPmtr[GTM_DPLL_NO_OF_ACTIONS]; /* PMTR configuration value */
  uint32 DpllCtrl0;     /* DPLL Control 0 configuration */
  uint32 DpllCtrl1;     /* DPLL Control 1 configuration */
  uint32 DpllApt;       /* DPLL APT configuration */
  uint32 DpllAps;       /* DPLL APS configuration */
  uint32 DpllAssort0;   /* 0 -9 NUTE, 10 - FST, 11-16 - VTN, 17-18 - OSS
      19 - 24 NUSE, 25 - FSS, 26-31 - VSN*/
  /* If NUTE is > 0, then Set WNUT too. Similarly, if VTN is > 0,set WVTN too */
  uint32 DpllIrqEnable;  /* Higher 2 bits - Irq Mode */
  uint32 DpllErrIntEnable;   /* bits [0-27] specify Dpll Error Interrupt 
    Enable on DPLL*/
  uint32 DpllAddInLoad1; /* ADD_IN_LD_1 updates this */
  uint32 DpllAddInLoad2; /* ADD_IN_LD_2 updates this */
}Gtm_DpllConfigType;


/* Type for SPE configuration */
typedef struct
{
  uint8 SpeIrq;   /* Interrupt enable info.Bit 6 and 7 specifies Spe Irq Mode */
  uint8 SpeErrIrq;   /* Error Interrupt enable info. Bit [0 - 3] specifies SPE 
          error interrupt enable - disable */
  uint16 SpeOutput[GTM_NO_OF_SPE_PATTERNS]; /*SPE Output pattern configuration*/
  uint32 SpeCtrlStat;         /* SPE control status configured value */
  uint32 SpePattern;          /* SPE Input pattern configured value  */
  uint32 SpeRevCntr;   /* Bits [0 -23] specifies Input signal revolution counter
        for SPE*/
  uint32 SpeRevCmp;   /* Bits [0 -23] specifies Input signal revilution compare
         value for SPE*/

}Gtm_SpeConfigType;

/* Type for CMP configuration */
typedef struct
{
  uint32 CmpEnable;     /* CMP enable register configured value */
  uint32 CmpIntEnable;  /* Last 2 bits specify Irq Mode */
  uint32 CmpErrIntEnable;   /* bits [0-11] specify ABWCx_EN_EIRQ,
          [11-23] specify ABWCx_EN_EIRQ*/

}Gtm_CmpConfigType;



/* Type for MSC Set configuration */
typedef struct
{
  uint32 MscConnection[GTM_NO_MSC_CONTROLS_PER_SET];  /* MSC connnections */
}Gtm_MscSetType;

/* Type for MSC Input control  */
typedef struct
{
  uint32 MscLowControl;    /* MSC Input Low control  */
  uint32 MscHighControl;   /* MSC Input High control */
}Gtm_MscInputCtrlType;

/* Type for Msc connections */
typedef struct
{
  const Gtm_MscSetType * MscSets;     /* Pointer to MSC sets configuration */
  const Gtm_MscInputCtrlType * MscInputCtrlPtr;/* Ptr to MSC Input control */
}Gtm_MscConnectionsType;


/* Type for DSADC connections */
typedef struct
{
  uint32 DsadcInsel0;     /* DSADC input selection 0 configuration */
  uint32 DsadcInsel1;     /* DSADC input selection 1 configuration */
  uint32 DsadcInsel2;     /* DSADC input selection 2 configuration */
  uint32 DsadcOutsel00;   /* DSADC output selection 00 configuration */
  uint32 DsadcOutsel10;   /* DSADC output selection 10 configuration */
}Gtm_DsadcConnectionsType;

/* Type for Module configuration */
typedef struct
{
  uint8 GtmAruConfig;   /* Bits 0 -2 Irq Enable . Bit 6,7 Irq Mode */
  uint8 GtmMcfgConfig; /* MCFG configuration*/
  /* Module Sleep Enable configuration */
  uint8 GtmModuleSleepEnable;  
  uint32 GtmGclkNum;         /* Global Clock Numerator value     */
  uint32 GtmGclkDen;         /* Global Clock Denominator value   */
  uint32 GtmAccessEnable0;   /* Access Enable 0 configured value */
  uint32 GtmAccessEnable1;   /* Access Enable 1 configured value */
  /* Bit coded information specifies the driver that uses the channel
     2 - COMPLEX, 1- ICU */
  uint32 GtmTimModuleUsage[((GTM_MAX_TIM_CHANNELS -1U)/16U) + 1U];
  /* Bit coded information specifies if the channel is configured or not */
  uint32 GtmTimUsage[((GTM_MAX_TIM_CHANNELS -1U)/32U) + 1U];
  const Gtm_TimConfigType *GtmTimConfigPtr; /* Pointer to TIM configuration */
  /* Bit coded information specifies if the TGC is configured or not */
  uint32 GtmTomTgcUsage[(     \
    ((GTM_NO_OF_TOM_MODULES * GTM_NO_OF_TGC_PER_MODULE) - 1U)/32U\
          )+1U];
  const Gtm_TomTgcConfigType *GtmTomTgcConfigPtr ; /* Ptr to TOM TGC Config  */
  /* Bit coded information specifies the driver that uses the channel
     3 - COMPLEX, 1- PWM  2- GPT */
  uint32 GtmTomModuleUsage[((GTM_MAX_TOM_CHANNELS -1U)/16U) + 1U];
  /* Bit coded information specifies if the channel is configured or not */
  uint32 GtmTomUsage[((GTM_MAX_TOM_CHANNELS -1U)/32U) + 1U];
  const Gtm_TomConfigType *GtmTomConfigPtr; /* Pointer to TOM configuration */
  /* Bit coded information specifies if the AGC is configured or not */
  uint32 GtmAtomAgcUsage[(    \
         ((GTM_NO_OF_ATOM_MODULES * GTM_NO_OF_AGC_PER_MODULE) - 1U)/32U \
    ) + 1U];
  const Gtm_AtomAgcConfigType *GtmAtomAgcConfigPtr; /*Ptr to ATOM AGC Config */
  /* Bit coded information specifies the driver that uses the channel
     3 - COMPLEX, 1- PWM  2- GPT */
  uint32 GtmAtomModuleUsage[((GTM_MAX_ATOM_CHANNELS -1U)/16U) + 1U];
  /* Bit coded information specifies if the channel is configured or not */
  uint32 GtmAtomUsage[((GTM_MAX_ATOM_CHANNELS -1U)/32U) + 1U];
  const Gtm_AtomConfigType *GtmAtomConfigPtr; /* Pointer to ATOM configuration*/
  /* Pointer to GTM (TIM/TOM/ATOM) usage configuration*/
  const Gtm_ModUsageConfigType *GtmModUsageConfigPtr; 
  const Gtm_GeneralConfigType *GtmGeneralConfigPtr;/* Ptr to General Config   */
  /* Will be NULL_PTR if Tbu is not configured */
  const Gtm_TbuConfigType *GtmTbuConfigPtr; /* Pointer to TBU configuration*/
  const Gtm_BrcConfigType *GtmBrcConfigPtr; /* Pointer to BRC configuration*/
  const Gtm_FifoConfigType * const * GtmFifoConfigPtr;
    /* Pointer to FIFO configuration*/
  const Gtm_F2aConfigType *GtmF2aConfigPtr;   /* Pointer to F2A configuration*/
  const Gtm_McsConfigType *GtmMcsConfigPtr;   /* Pointer to MCS configuration*/
  uint32 GtmMapConfig; /* MAP configuration*/
  const Gtm_DpllConfigType *GtmDpllConfigPtr; /* Pointer to DPLL configuration*/
  /* Pointer to SPE configuration*/
  const Gtm_SpeConfigType *GtmSpeConfigPtr[GTM_NO_SPE_MODULES];
  const Gtm_CmpConfigType *GtmCmpConfigPtr;   /* Pointer to CMP configuration */
  /* Pointer to MSC Connections configuration*/
  const Gtm_MscConnectionsType *GtmMscConnectionsPtr;
  /* Pointer to DSADC Connections configuration*/
  const Gtm_DsadcConnectionsType *GtmDsadcConnectionsPtr;
  /* Upper Nibble represents Trigger 1 and Lower Nibble Trigger 0 */
  const uint8 * GtmAdcConnectionsPtr;
  /* TTCAN Trigger configuration */
  uint32 GtmTtcanTriggers[((GTM_NO_OF_TTCAN_TRIGGERS - 1U)/8U) + 1U];
  /* PSI5 Out Selection configuration */
  uint32 GtmPsi5OutSelect;
  /* PSI5 Out Selection configuration */
  uint32 GtmPsi5SOutSelect;
}Gtm_ModuleConfigType;



/* Notification Type for GTM dependent modules*/
typedef void (*Gtm_ModNotificationPtrType)(uint8 ChannelNo);

#ifdef GTM_MOD_CH_CONFIGURED
/* Notification Type for GTM complex driver configuration*/
typedef void (*Gtm_NotificationPtrType)(uint8 ModuleType, uint8 ModuleNo,
                   uint8 ChannelNo,uint16 IrqNotifVal);

/*GTM Notification configuration for TIM,TOM and ATOM*/
typedef struct 
{
  #if (GTM_NO_OF_TIM_CH_CONF_NOTIF > 0U)
  Gtm_NotificationPtrType TimNotifUsage[GTM_NO_OF_TIM_CH_CONF_NOTIF];
  #endif
  #if (GTM_NO_OF_TOM_CH_CONF_NOTIF > 0U)
  Gtm_NotificationPtrType TomNotifUsage[GTM_NO_OF_TOM_CH_CONF_NOTIF];
  #endif
  #if (GTM_NO_OF_ATOM_CH_CONF_NOTIF > 0U)
  Gtm_NotificationPtrType AtomNotifUsage[GTM_NO_OF_ATOM_CH_CONF_NOTIF];
  #endif
}Gtm_NotificationConfigType;

#endif




/* GTM root Configuration */
typedef struct Gtm_ConfigType
{
  const Gtm_ClockSettingType  * GtmClockSettingPtr; /* Ptr to Clock Setting */
  const Gtm_PortConfigType *GtmPortConfigPtr; /* Ptr to Port Configuration  */
  const Gtm_ModuleConfigType *GtmModuleConfigPtr; /* Module config Ptr      */
}Gtm_ConfigType;



/*******************************************************************************
**        Global Variable Declarations                                        **
*******************************************************************************/
#define MCU_START_SEC_POSTBUILDCFG
#include "MemMap.h"
/* Declaration of GTM Post Build Configuration */
extern const Gtm_ConfigType Gtm_ConfigRoot[];
#define MCU_STOP_SEC_POSTBUILDCFG
#include "MemMap.h"

#define GTM_START_SEC_VAR_32BIT
#include "MemMap.h"
extern Gtm_ConfigType const *Gtm_kConfigPtr;
#define GTM_STOP_SEC_VAR_32BIT
#include "MemMap.h"

/*******************************************************************************
**        Global Function Declarations                                        **
*******************************************************************************/
#define GTM_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Syntax : void Gtm_Init(const Gtm_ConfigType *ConfigPtr)                    **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       non reentrant                                            **
**                                                                            **
** Parameters (in):  ConfigPtr - Pointer to configuration set                 **
**                                                                            **
** Parameters (out): none                                                     **
**                                                                            **
** Return value:     none                                                     **
**                                                                            **
** Description :     This routine initializes the GTM module.                 **
**     This routine must be called before executing ICU / PWM /               **
**     GPT driver.                                                            **
**     The intention of this function is to make the                          **
**     configuration settings for GTM driver                                  **
**     also enable Interrupt Request for all resources that is                **
**     used across ICU/PWM/GPT and GTM modules.                               **
**     Clock Setting for GTM module clock and clock bus                       **
**     configuration will be done in this                                     **
**     function.                                                              **
**                                                                            **
*******************************************************************************/
extern void Gtm_Init(const Gtm_ConfigType *ConfigPtr);

/*******************************************************************************
** Syntax : void Gtm_IsrTomModule(uint8 ModuleNo, uint8 ChannelNumber)        **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - TOM Module Number                             **
**     ChannelNumber - Channel number (0,2,4,6,8,10,12,14)                    **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     All TOM Interrupt sources are mapped to this function.   **
**     On an interrupt request from TOM isr, channel number and               **
**     module number are passed as parameter. Since 2 interrupt               **
**     sources are mapped  to one Interrupt node, the parameter               **
**     to this function will be an even number only.                          **
*******************************************************************************/
extern void Gtm_IsrTomModule(uint8 ModuleNo, uint8 ChannelNumber);

/*******************************************************************************
** Syntax : void Gtm_IsrAtomModule(uint8 ModuleNo, uint8 ChannelNumber)       **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - ATOM Module number                            **
**     ChannelNumber - Channel number (0,2,4,6)                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     All ATOM Interrupt sources are mapped to this function.  **
**     On an interrupt request from ATOM isr, channel number and              **
**     Module Number are passed as parameter. Since 2 interrupt               **
**     sources are mapped to one Interrupt node, the parameter                **
**     to this function will be an even number only.                          **
*******************************************************************************/
extern void Gtm_IsrAtomModule(uint8 ModuleNo, uint8 ChannelNumber);

/*******************************************************************************
** Syntax : void Gtm_IsrTimModule(uint8 ModuleNo, uint8 ChannelNumber)        **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo: TIM Module Number                              **
**     ChannelNumber - Channel number (0 to 7)                                **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     All TIM Interrupt sources are mapped to this function.   **
**     On an interrupt request from TIM isr, channel number and               **
**     module number are passed as parameter. Notification                    **
**     function if configured, will be called                                 **
*******************************************************************************/
extern void Gtm_IsrTimModule(uint8 ModuleNo, uint8 ChannelNumber);


/*******************************************************************************
** Syntax : void Gtm_IsrAtom2Channel(                                         **
**       uint8 ChannelNumber                                                  **
**       )                                                                    **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ChannelNumber - Channel number (0,2,4,6)                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     All ATOM2 Interrupt sources are mapped to this function. **
**     On an interrupt request from ATOM isr, channel number is               **
**     sent as parameter. Since 2 interrupt sources are mapped                **
**     to one Interrupt node, the parameter to this function                  **
**     will be an even number only.                                           **
*******************************************************************************/
extern void Gtm_IsrAtom2Channel(uint8 ChannelNumber);


/*******************************************************************************
** Syntax : void Gtm_IsrAtom3Channel(                                         **
**       uint8 ChannelNumber                                                  **
**       )                                                                    **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ChannelNumber - Channel number (0,2,4,6)                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     All ATOM3 Interrupt sources are mapped to this function. **
**     On an interrupt request from ATOM isr, channel number is               **
**     sent as parameter. Since 2 interrupt sources are mapped                **
**     to one Interrupt node, the parameter to this function                  **
**     will be an even number only.                                           **
*******************************************************************************/
extern void Gtm_IsrAtom3Channel(uint8 ChannelNumber);


/*******************************************************************************
** Syntax : void Gtm_IsrAtom4Channel(                                         **
**       uint8 ChannelNumber                                                  **
**       )                                                                    **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ChannelNumber - Channel number (0,2,4,6)                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     All ATOM4 Interrupt sources are mapped to this function. **
**     On an interrupt request from ATOM isr, channel number is               **
**     sent as parameter. Since 2 interrupt sources are mapped                **
**     to one Interrupt node, the parameter to this function                  **
**     will be an even number only.                                           **
*******************************************************************************/
extern void Gtm_IsrAtom4Channel(uint8 ChannelNumber);



/*******************************************************************************
** Syntax : void Gtm_IsrTim0Channel(                                          **
**       uint8 ChannelNumber                                                  **
**       )                                                                    **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ChannelNumber - Channel number (0 to 7)                  **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     All TIM0 Interrupt sources are mapped to this function.  **
**     On an interrupt request from TIM isr, channel number is                **
**     sent as parameter.                                                     **
*******************************************************************************/
extern void Gtm_IsrTim0Channel(uint8 ChannelNumber);


/*******************************************************************************
** Syntax : void Gtm_IsrTim1Channel(                                          **
**       uint8 ChannelNumber                                                  **
**       )                                                                    **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ChannelNumber - Channel number (0 to 7)                  **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     All TIM1 Interrupt sources are mapped to this function.  **
**     On an interrupt request from TIM isr, channel number is                **
**     sent as parameter.    **
*******************************************************************************/
extern void Gtm_IsrTim1Channel(uint8 ChannelNumber);

/*******************************************************************************
** Syntax : void Gtm_IsrTim2Channel(                                         **
**                            uint8 ChannelNumber                             **
**                                   )                                        **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ChannelNumber - Channel number (0 to 7)                  **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     All TIM2 Interrupt sources are mapped to this function.  **
**                   On an interrupt request from TIM isr, channel number is  **
**                   sent as parameter.                                       **
*******************************************************************************/
extern void Gtm_IsrTim2Channel(uint8 ChannelNumber);


/*******************************************************************************
** Syntax : void Gtm_IsrTim3Channel(                                         **
**                            uint8 ChannelNumber                             **
**                                   )                                        **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ChannelNumber - Channel number (0 to 7)                  **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     All TIM3 Interrupt sources are mapped to this function.  **
**                   On an interrupt request from TIM isr, channel number is  **
**                   sent as parameter.                                       **
*******************************************************************************/
extern void Gtm_IsrTim3Channel(uint8 ChannelNumber);


/*******************************************************************************
** Syntax : Gtm_AruReqStatusType Gtm_CtrlAruFrame(uint8 AruAddress, uint8     **
**                  ReqType, uint32* AruFrame, uint8 ReadReq)                 **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  AruAddress - ARU Address frame to be acted upon          **
                     ReqType – 0 – Request for Writing ARU frame              **
**                             1 – Request for Reading ARU frame              **
**                   AruFrame – Pointer to the location where                 **
**                              a)  In case of Write request, 2 uint32 ARU    **
**                                  frame content will be fetched from.       **
**                              b)  In case of read request, 2 uint32 ARU     **
**                                  frame will be written to.                 **
**                              Location pointed by AruFrame address will     **
**                              contain the Upper word of ARU frame. Location **
**                              pointer by AruFrame + 4 will contain the Lower**
**                              word of ARU frame.                            **
**                   ReadReq – This is applicable only if ReqType is 1        **
**                             0 – Only Issue a Read Request. ARU frame shall **
**                                 be reported only if the read is completed. **
**                             1 – Do not issue a Read Request. Only ARU frame**
**                                 content should be reported.                **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     Boolean Status –                                         **
**                   When ReqType = 0,                                        **
**                      TRUE – Write request issued successfully.             **
**                      FALSE – Write could not be issued because of a        **
**                              previously pending request                    **
**                   When ReqType = 1,                                        **
**                      TRUE – Read request issued successfully. ARU Frame    **
**                             also read. Content pointed by AruFrame will be **
**                             valid                                          **
**                      FALSE –                                               **
**                   When ReadReq is 0,                                       **
**                   a) Read request not issued successfully because of       **
**                      previously pending request.                           **
**                   b) Read request issued successfully but ARU frame reading**
**           Is not completed.                                     **
**                   When ReadReq is 1,                                       **
**                   a) ARU Frame not read as ARU reading is not complete.    **
**                      Content pointed by AruFrame will be invalid.          **
**                                                                            **
** Description :     This service provides read and write functionality of    **
**                   ARU frames                                               **
*******************************************************************************/
extern Gtm_AruReqStatusType Gtm_CtrlAruFrame(uint16 AruAddress, 
         uint8 ReqType,uint32* AruFrame,uint8 ReadReq);

/*******************************************************************************
** Syntax : void Gtm_ModifyOutputCtrl (uint8 TimerModule, uint8 ModuleNo,     **
**          uint8 ChannelNo, boolean ToEnable)                                **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  TimerModule - 0 – TOM,  1 - ATOM                         **
**                   ModuleNo – TOM Module Number                             **
**                   ChannelNo – TOM Channel Number                           **
**                   ToEnable – TRUE -> Enable TOM Output                     **
**                              FALSE -> Disable TOM Output                   **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This service enables/disables the TOM Channel output.    **
*******************************************************************************/
extern void Gtm_ModifyOutputCtrl (uint8 TimerModule, uint8 ModuleNo,
        uint8 ChannelNo, boolean ToEnable);

/*******************************************************************************
** Syntax          : void Gtm_InitCheck (const Gtm_ConfigType* ConfigPtr)     **
**                                                                            **
** Service ID      :    None                                                  **
**                                                                            **
** Sync/Async      :    Synchronous                                           **
**                                                                            **
** Reentrancy      :    Non Reentrant                                         **
**                                                                            **
** Parameters (in) :    ConfigPtr - Pointer to GTM Driver configuration set   **
**                                                                            **
** Parameters (out):    None                                                  **
**                                                                            **
** Return value    :    E_OK - if initialization comparison is success        **
**                      E_NOT_OK - if initialization comparison fails         **
**                                                                            **
** Description     : This routine verifies the initialization the GTM driver. **
**                                                                            **
*******************************************************************************/
Std_ReturnType Gtm_InitCheck (const Gtm_ConfigType* ConfigPtr);

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
/* Api's for Complex Usage */
/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1092_3]
** Syntax : void Gtm_SetTomHostTrigger(uint8 ModuleNo, uint8 TgcNumber)       **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - TOM Module Number (0 - 2)                     **
**                   TgcNumber - TGC number (0 - 1)                           **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This _INLINE_ function sets the Host Trigger Bit         **
**                   corresponding to the Tgc                                 **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_SetTomHostTrigger(uint8 ModuleNo, uint8 TgcNumber)
{
     (*(Ifx_GTM_TOMx*)(MODULE_GTM.TOM)).TOM_TGC[ModuleNo].
                             TGC[TgcNumber].GLB_CTRL.U|= (uint32_t)GTM_SET_BIT;
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1094_3]
** Syntax : void Gtm_SetAtomHostTrigger(uint8 ModuleNo)                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - TOM Module Number (0 - 4)                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This _INLINE_ function sets the Host Trigger Bit         **
**                   corresponding to the Agc                                 **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_SetAtomHostTrigger(uint8 ModuleNo)
{
  MODULE_GTM.ATOM[ModuleNo].AGC.GLB_CTRL.U |= (uint32_t)GTM_SET_BIT;
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1096_3]
** Syntax : void Gtm_SetTomCounterCn0(                                        **
**                              uint8 ModuleNo,                               **
**                              uint8 ChannelNo,                              **
**                              uint16 Cn0Value)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                   Cn0Value - CN0 Value to write                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This _INLINE_ function sets the value of CN0 of the TOM  **
**                   channel with the value given by Cn0Value                 **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_SetTomCounterCn0(
       uint8 ModuleNo,
       uint8 ChannelNo,
       uint16 Cn0Value
      )
{
  /* Get the Channel Register Pointer */


  ((*(Ifx_GTM_TOMx*)(MODULE_GTM.TOM)).TOM_CH[ModuleNo].CH[ChannelNo].CN0.U) = \
     (uint32_t)Cn0Value;

}


/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1097_3]
** Syntax : void Gtm_SetAtomCounterCn0(                                       **
**                              uint8 ModuleNo,                               **
**                              uint8 ChannelNo,                              **
**                              uint32 Cn0Value)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                   Cn0Value - CN0 Value to write                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This _INLINE_ function sets the value of CN0 of the ATOM **
**                   channel with the value given by Cn0Value                 **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_SetAtomCounterCn0(
         uint8 ModuleNo,
         uint8 ChannelNo,
         uint32 Cn0Value
       )
{
((*(Ifx_GTM_ATOMx*)(MODULE_GTM.ATOM)).                                        \
                               ATOM_CH[ModuleNo].CH[ChannelNo].CN0.U)=   \
                                         (uint32_t)(Cn0Value & GTM_TIMER_MASK);

}


/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1098_1]
** Syntax : uint16 Gtm_GetTomCounterCn0(                                      **
**                              uint8 ModuleNo,                               **
**                              uint8 ChannelNo)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     CN0 value                                                **
**                                                                            **
** Description :     This _INLINE_ function gets the value of CN0 of the TOM  **
**                   channel.                                                 **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ uint16 Gtm_GetTomCounterCn0(uint8 ModuleNo,uint8 ChannelNo)
{
  /* Get the Channel Register Pointer */


  return((uint16)((*(Ifx_GTM_TOMx*)(MODULE_GTM.TOM)).                          \
      TOM_CH[ModuleNo].CH[ChannelNo].CN0.U));

}


/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1099_1]
** Syntax : uint32 Gtm_GetAtomCounterCn0(                                     **
**                              uint8 ModuleNo,                               **
**                              uint8 ChannelNo)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     CN0 Value                                                **
**                                                                            **
** Description :     This _INLINE_ function gets the value of CN0 of the ATOM **
**                   channel.                                                 **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ uint32 Gtm_GetAtomCounterCn0(uint8 ModuleNo, 
        uint8 ChannelNo)
{
  return((uint32)((*(Ifx_GTM_ATOMx*)(MODULE_GTM.ATOM)).                        \
       ATOM_CH[ModuleNo].CH[ChannelNo].CN0.U));

}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1096_1]
** Syntax : void Gtm_SetTomCompareValCm0(                                     **
**                              uint8 ModuleNo,                               **
**                              uint8 ChannelNo,                              **
**                              uint16 Cm0Value)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                   Cm0Value - CM0 Value to write                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This _INLINE_ function sets the value of CM0 of the TOM  **
**                   channel with the value given by Cm0Value                 **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_SetTomCompareValCm0(
     uint8 ModuleNo,
     uint8 ChannelNo,
     uint16 Cm0Value)
{
  /* Get the Channel Register Pointer */

  ((*(Ifx_GTM_TOMx*)(MODULE_GTM.TOM)).TOM_CH[ModuleNo].CH[ChannelNo].CM0.U) =  \
     (uint32_t)Cm0Value;

}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1097_2]
** Syntax : void Gtm_SetAtomCompareValCm0(                                    **
**                              uint8 ModuleNo,                               **
**                              uint8 ChannelNo,                              **
**                              uint32 Cm0Value)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                   Cm0Value - CM0 Value to write                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This _INLINE_ function sets the value of CM0 of the ATOM **
**                   channel with the value given by Cm0Value                 **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_SetAtomCompareValCm0(
      uint8 ModuleNo,
      uint8 ChannelNo,
      uint32 Cm0Value
          )
{
  ((*(Ifx_GTM_ATOMx*)(MODULE_GTM.ATOM)).
                               ATOM_CH[ModuleNo].CH[ChannelNo].CM0.U) =   \
                                         (uint32_t)(Cm0Value & GTM_TIMER_MASK);
       
}


/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1098_5]
** Syntax : uint16 Gtm_GetTomCompareValCm0(                                   **
**                              uint8 ModuleNo,                               **
**                              uint8 ChannelNo)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     CM0 value                                                **
**                                                                            **
** Description :     This _INLINE_ function gets the value of CM0 of the TOM  **
**                   channel.                                                 **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ uint16 Gtm_GetTomCompareValCm0(uint8 ModuleNo, 
          uint8 ChannelNo)
{
  /* Get the Channel Register Pointer */

  return((uint16)((*(Ifx_GTM_TOMx*)(MODULE_GTM.TOM)).     \
        TOM_CH[ModuleNo].CH[ChannelNo].CM0.U));

}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1099_2]
** Syntax : uint32 Gtm_GetAtomCompareValCm0(                                  **
**                              uint8 ModuleNo,                               **
**                              uint8 ChannelNo)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     CM0 value                                                **
**                                                                            **
** Description :     This _INLINE_ function gets the value of CM0 of the ATOM **
**                   channel.                                                 **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ uint32 Gtm_GetAtomCompareValCm0(uint8 ModuleNo, 
    uint8 ChannelNo)
{
  return((uint32)(((*(Ifx_GTM_ATOMx*)(MODULE_GTM.ATOM)).       \
        ATOM_CH[ModuleNo].CH[ChannelNo].CM0.U)));
  
}


/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1096_2]
** Syntax : void Gtm_SetTomCompareValCm1(                                     **
**                              uint8 ModuleNo,                               **
**                              uint8 ChannelNo,                              **
**                              uint16 Cm1Value)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                   Cm1Value - CM1 Value to write                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This _INLINE_ function sets the value of CM1 of the TOM  **
**                   channel with the value given by Cm1Value                 **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_SetTomCompareValCm1(
       uint8 ModuleNo,
       uint8 ChannelNo,
       uint16 Cm1Value
         )
{
  /* Get the Channel Register Pointer */

  ((*(Ifx_GTM_TOMx*)(MODULE_GTM.TOM)).TOM_CH[ModuleNo].         \
         CH[ChannelNo].CM1.U) = (uint32)Cm1Value;

}


/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1097_1]
** Syntax : void Gtm_SetAtomCompareValCm1(                                    **
**                              uint8 ModuleNo,                               **
**                              uint8 ChannelNo,                              **
**                              uint32 Cm1Value)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                   Cm1Value - CM1 Value to write                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This _INLINE_ function sets the value of CM1 of the ATOM **
**                   channel with the value given by Cm1Value                 **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_SetAtomCompareValCm1(
      uint8 ModuleNo,
      uint8 ChannelNo,
      uint32 Cm1Value
          )
{
  ((*(Ifx_GTM_ATOMx*)(MODULE_GTM.ATOM)).ATOM_CH[ModuleNo].                    \
                  CH[ChannelNo].CM1.U) = (uint32_t)(Cm1Value & GTM_TIMER_MASK);
}


/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1098_6]
** Syntax : uint16 Gtm_GetTomCompareValCm1(                                   **
**                              uint8 ModuleNo,                               **
**                              uint8 ChannelNo)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     CM1 Value                                                **
**                                                                            **
** Description :     This _INLINE_ function gets the value of CM1 of the TOM  **
**                   channel.                                                 **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ uint16 Gtm_GetTomCompareValCm1(uint8 ModuleNo, 
          uint8 ChannelNo)
{
  /* Get the Channel Register Pointer */

  return((uint16)((*(Ifx_GTM_TOMx*)(MODULE_GTM.TOM)).     \
        TOM_CH[ModuleNo].CH[ChannelNo].CM1.U));

}


/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1099_3]
** Syntax : uint32 Gtm_GetAtomCompareValCm1(                                  **
**                              uint8 ModuleNo,                               **
**                              uint8 ChannelNo)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     CM1 value                                                **
**                                                                            **
** Description :     This _INLINE_ function gets the value of CM1 of the ATOM **
**                   channel.                                                 **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ uint32 Gtm_GetAtomCompareValCm1(uint8 ModuleNo, 
    uint8 ChannelNo)
{
  return((uint32)(((*(Ifx_GTM_ATOMx*)(MODULE_GTM.ATOM)).ATOM_CH[ModuleNo].     \
                                                       CH[ChannelNo].CM1.U)));
}


/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1096_4]
** Syntax : void Gtm_SetTomShadowValSr0(                                      **
**                              uint8 ModuleNo,                               **
**                              uint8 ChannelNo,                              **
**                              uint16 Sr0Value)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                   Sr0Value - SR0 Value to write                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This _INLINE_ function sets the value of SR0 of the TOM  **
**                   channel with the value given by Sr0Value                 **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_SetTomShadowValSr0(
    uint8 ModuleNo,
    uint8 ChannelNo,
    uint16 Sr0Value
        )
{
  /* Get the Channel Register Pointer */

  ((*(Ifx_GTM_TOMx*)(MODULE_GTM.TOM)).TOM_CH[ModuleNo].CH[ChannelNo].SR0.U) = \
     (uint32_t)Sr0Value;

}


/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1097_4]
** Syntax : void Gtm_SetAtomShadowValSr0(                                     **
**                              uint8 ModuleNo,                               **
**                              uint8 ChannelNo,                              **
**                              uint32 Sr0Value)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                   Sr0Value - SR0 Value to write                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This _INLINE_ function sets the value of SR0 of the TOM  **
**                   channel with the value given by Sr0Value                 **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_SetAtomShadowValSr0(
          uint8 ModuleNo,
          uint8 ChannelNo,
          uint32 Sr0Value
         )
{
  ((*(Ifx_GTM_ATOMx*)(MODULE_GTM.ATOM)).ATOM_CH[ModuleNo].                     \
                   CH[ChannelNo].SR0.U) = (uint32_t)(Sr0Value & GTM_TIMER_MASK);
}


/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1098_3]
** Syntax : uint16 Gtm_GetTomShadowValSr0(                                    **
**                              uint8 ModuleNo,                               **
**                              uint8 ChannelNo)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     SR0 value                                                **
**                                                                            **
** Description :     This _INLINE_ function gets the value of SR0 of the TOM  **
**                   channel.                                                 **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ uint16 Gtm_GetTomShadowValSr0(uint8 ModuleNo, 
         uint8 ChannelNo)
{
  /* Get the Channel Register Pointer */

  return((uint16)((*(Ifx_GTM_TOMx*)(MODULE_GTM.TOM)).     \
      TOM_CH[ModuleNo].CH[ChannelNo].SR0.U));

}


/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1099_4]
** Syntax : uint32 Gtm_GetAtomShadowValSr0(                                   **
**                              uint8 ModuleNo,                               **
**                              uint8 ChannelNo)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     SR0 value                                                **
**                                                                            **
** Description :     This _INLINE_ function gets the value of SR0 of the ATOM **
**                   channel.                                                 **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ uint32 Gtm_GetAtomShadowValSr0(uint8 ModuleNo, 
          uint8 ChannelNo)
{
  return((uint32)((*(Ifx_GTM_ATOMx*)(MODULE_GTM.ATOM)).                       \
                                        ATOM_CH[ModuleNo].CH[ChannelNo].SR0.U));
}


/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1096_5]
** Syntax : void Gtm_SetTomShadowValSr1(                                      **
**                              uint8 ModuleNo,                               **
**                              uint8 ChannelNo,                              **
**                              uint16 Sr1Value)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                   Sr1Value - SR1 Value to write                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This _INLINE_ function sets the value of SR1 of the TOM  **
**                   channel with the value given by Sr1Value                 **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_SetTomShadowValSr1(
    uint8 ModuleNo,
    uint8 ChannelNo,
    uint16 Sr1Value
        )
{
  /* Get the Channel Register Pointer */

  ((*(Ifx_GTM_TOMx*)(MODULE_GTM.TOM)).TOM_CH[ModuleNo].CH[ChannelNo].SR1.U) = \
     (uint32_t)Sr1Value;

}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1097_5]
** Syntax : void Gtm_SetAtomShadowValSr1(                                     **
**                              uint8 ModuleNo,                               **
**                              uint8 ChannelNo,                              **
**                              uint32 Sr1Value)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                   Sr1Value - SR1 Value to write                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This _INLINE_ function sets the value of SR1 of the ATOM **
**                   channel with the value given by Sr1Value                 **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_SetAtomShadowValSr1(
       uint8 ModuleNo,
       uint8 ChannelNo,
       uint32 Sr1Value
         )
{
  (*(Ifx_GTM_ATOMx*)(MODULE_GTM.ATOM)).                                        \
  ATOM_CH[ModuleNo].CH[ChannelNo].SR1.U = (uint32_t)(Sr1Value & GTM_TIMER_MASK);
}


/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1098_4]
** Syntax : uint16 Gtm_GetTomShadowValSr1(                                    **
**                              uint8 ModuleNo,                               **
**                              uint8 ChannelNo)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     SR1 value                                                **
**                                                                            **
** Description :     This _INLINE_ function gets the value of SR1 of the TOM  **
**                   channel.                                                 **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ uint16 Gtm_GetTomShadowValSr1(uint8 ModuleNo, 
         uint8 ChannelNo)
{
  /* Get the Channel Register Pointer */

  return((uint16)((*(Ifx_GTM_TOMx*)(MODULE_GTM.TOM)).
      TOM_CH[ModuleNo].CH[ChannelNo].SR1.U));

}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1099_5]
** Syntax : uint16 Gtm_GetAtomShadowValSr1(                                   **
**                              uint8 ModuleNo,                               **
**                              uint8 ChannelNo)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     SR1 value                                                **
**                                                                            **
** Description :     This _INLINE_ function gets the value of SR1 of the ATOM **
**                   channel.                                                 **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ uint32 Gtm_GetAtomShadowValSr1(uint8 ModuleNo, 
          uint8 ChannelNo)
{
  return((uint32)((*(Ifx_GTM_ATOMx*)(MODULE_GTM.ATOM)).          \
        ATOM_CH[ModuleNo].CH[ChannelNo].SR1.U));
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1098_2]
** Syntax : Gtm_OutputLevelType Gtm_GetTomOutputState(uint8 ModuleNo,         **
**                                                    uint8 ChannelNo)        **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     Output state                                             **
**                                                                            **
** Description :     Inline function to get the TOM Output                    **
*******************************************************************************/
/* Channel must be enabled prior to calling this */
_IFXEXTERN_ _INLINE_ Gtm_OutputLevelType Gtm_GetTomOutputState(uint8 ModuleNo,
         uint8 ChannelNo)
{
  /* Get the Channel Register Pointer */

  /* Returns the OUT bit of the channel Status register */
  return((Gtm_OutputLevelType)\
  (((*(Ifx_GTM_TOMx*)(MODULE_GTM.TOM)).TOM_CH[ModuleNo].CH[ChannelNo].STAT.U) \
        & GTM_BIT_SET));

}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1099_6]
** Syntax : Gtm_OutputLevelType Gtm_GetAtomOutputState(uint8 ModuleNo,        **
**                                                     uint8 ChannelNo)       **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     Output state                                             **
**                                                                            **
** Description :     Inline function to get the TOM Output                    **
*******************************************************************************/
/* Channel must be enabled prior to calling this */
_IFXEXTERN_ _INLINE_ Gtm_OutputLevelType Gtm_GetAtomOutputState(uint8 ModuleNo,
          uint8 ChannelNo)
{
  /* Returns the OUT bit of the channel Status register */
  return((Gtm_OutputLevelType)((*(Ifx_GTM_ATOMx*)(MODULE_GTM.ATOM)).          \
      ATOM_CH[ModuleNo].CH[ChannelNo].STAT.U & GTM_BIT_SET));
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1100]
** Syntax : void Gtm_SetTimCounterShadowValCnts(                              **
**                              uint8 ModuleNo,                               **
**                              uint8 ChannelNo                               **
**                              uint32 CntsValue)                             **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                   CntsValue - CNTS value to set                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Inline function to set CNTS value of the corresponding   **
**                   TIM Channel. The Channel must either be in  TIPM or TBCM **
**                   for using this API, else there will be no effect of this **
**                   API                                                      **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_SetTimCounterShadowValCnts(
      uint8 ModuleNo,
      uint8 ChannelNo,
      uint32 CntsValue
         )
{
  (*(Ifx_GTM_TIMx*)(MODULE_GTM.TIM)).CH_TIM[ModuleNo].                        \
            CH[ChannelNo].CH_CNTS.U = (uint32_t)(CntsValue & GTM_TIMER_MASK);
    
}


/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1101_1]
** Syntax : uint32 Gtm_GetTimCounterShadowValCnts(                            **
**                              uint8 ModuleNo,                               **
**                              uint8 ChannelNo)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Inline function to get CNTS value of the corresponding   **
**                   TIM Channel.                                             **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ uint32 Gtm_GetTimCounterShadowValCnts(uint8 ModuleNo,
          uint8 ChannelNo)
{
     
  return((uint32)(*(Ifx_GTM_TIMx*)(MODULE_GTM.TIM)).
          CH_TIM[ModuleNo].CH[ChannelNo].CH_CNTS.U);
}



/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1101_2]
** Syntax : uint32 Gtm_GetTimCounterValCnt(                                   **
**                              uint8 ModuleNo,                               **
**                              uint8 ChannelNo)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Inline function to get CNT value of the corresponding    **
**                   TIM Channel.                                             **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ uint32 Gtm_GetTimCounterValCnt(uint8 ModuleNo, 
          uint8 ChannelNo)
{
  return((uint32)((*(Ifx_GTM_TIMx*)(MODULE_GTM.TIM)).    \
     CH_TIM[ModuleNo].CH[ChannelNo].CH_CNT.U));
}


/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1101_3]
** Syntax : uint32 Gtm_GetTimGeneralPurposeRegGpr0(                           **
**                              uint8 ModuleNo,                               **
**                              uint8 ChannelNo)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Inline function to get GPR0 value of the corresponding   **
**                   TIM Channel.                                             **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ uint32 Gtm_GetTimGeneralPurposeRegGpr0(uint8 ModuleNo,
    uint8 ChannelNo)
{
  return((uint32)((*(Ifx_GTM_TIMx*)(MODULE_GTM.TIM)).CH_TIM[ModuleNo].       \
    CH[ChannelNo].CH_GPR0.U));
}


/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1101_4]
** Syntax : uint32 Gtm_GetTimGeneralPurposeRegGpr1(                           **
**                              uint8 ModuleNo,                               **
**                              uint8 ChannelNo)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Inline function to get GPR1 value of the corresponding   **
**                   TIM Channel.                                             **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ uint32 Gtm_GetTimGeneralPurposeRegGpr1(uint8 ModuleNo,
    uint8 ChannelNo)
{
  return((uint32)((*(Ifx_GTM_TIMx*)(MODULE_GTM.TIM)).     \
         CH_TIM[ModuleNo].CH[ChannelNo].CH_GPR1.U));
}


/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1102_4]
** Syntax : void Gtm_SetTimTimeoutVal(                                        **
**                              uint8 ModuleNo,                               **
**                              uint8 ChannelNo                               **
**                              uint8 TimeOutDuration)                        **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                   TimeOutDuration - value for timeout detection            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Inline function to set the Timeout duration for the TIM  **
**                   Channel to the parameter TimeOutDuration.                **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_SetTimTimeoutVal(
     uint8 ModuleNo,
     uint8 ChannelNo,
     uint8 TimeOutDuration
      )
{
  Mcal_SetAtomic(
  (sint32*)&((*(Ifx_GTM_TIMx*)(MODULE_GTM.TIM)).CH_TIM[ModuleNo].
   CH[ChannelNo].CH_TDUV), (sint32)(TimeOutDuration), (sint32)GTM_TIM_TDUV_POS,
          GTM_TIM_TDUV_SIZE);

}


/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1102_2]
** Syntax : void Gtm_EnableTimTimeoutDetection(                               **
**                              uint8 ModuleNo,                               **
**                              uint8 ChannelNo)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Inline function to enable Timeout detection for the TIM  **
**                   Channel.                                                 **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_EnableTimTimeoutDetection(uint8 ModuleNo,
       uint8 ChannelNo)
{
  (*(Ifx_GTM_TIMx*)(MODULE_GTM.TIM)).CH_TIM[ModuleNo].CH[ChannelNo].CH_CTRL.U |=
      (uint32_t)GTM_TIM_CH_TO_EN_BIT;
      
}


/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1102_1]
** Syntax : void Gtm_DisableTimTimeoutDetection(                              **
**                              uint8 ModuleNo,                               **
**                              uint8 ChannelNo)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Inline function to disable Timeout detection for the TIM **
**                   Channel.                                                 **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_DisableTimTimeoutDetection(uint8 ModuleNo,
        uint8 ChannelNo)
{
  (*(Ifx_GTM_TIMx*)(MODULE_GTM.TIM)).
  CH_TIM[ModuleNo].CH[ChannelNo].CH_CTRL.U &=(uint32_t)(GTM_TIM_TO_BIT_RESET); \
}


/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1102_3]
** Syntax : void Gtm_SelectTimTimeoutClock(                                   **
**                              uint8 ModuleNo,                               **
**                              uint8 ChannelNo                               **
**                              Gtm_ConfigurableClockType ClockSource)        **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                   ClockSource - Clock Source for Timeout detection         **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Inline function to select the clock source used for      **
**                   Timeout detection for the TIM Channel.                   **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_SelectTimTimeoutClock(
    uint8 ModuleNo,
    uint8 ChannelNo,
    Gtm_ConfigurableClockType ClockSource
    )
{
  uint32 RegVal;
  RegVal =  (*(Ifx_GTM_TIMx*)(MODULE_GTM.TIM)).CH_TIM[ModuleNo].
                                                        CH[ChannelNo].CH_TDUV.U;
  RegVal &= ~GTM_TIM_TCS_MASK;
  RegVal |= ((uint32)ClockSource) << GTM_TIM_TCS_POS;

  (*(Ifx_GTM_TIMx*)(MODULE_GTM.TIM)).CH_TIM[ModuleNo].CH[ChannelNo].CH_TDUV.U =\
       (uint32_t)RegVal;
}


/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1103]
** Syntax : uint8 Gtm_GetTimCurrentTimeoutVal(                                **
**                              uint8 ModuleNo,                               **
**                              uint8 ChannelNo)                              **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     TimeOut value is ticks                                   **
**                                                                            **
** Description :     Inline function to return the current Timeout value for  **
**                   Timeout detection for the TIM Channel.                   **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ uint8 Gtm_GetTimCurrentTimeoutVal(uint8 ModuleNo,
      uint8 ChannelNo)
{

  return((uint8)(((*(Ifx_GTM_TIMx*)(MODULE_GTM.TIM)).    \
  CH_TIM[ModuleNo].CH[ChannelNo].CH_TDUC.U & GTM_TIM_TOCNT_MASK) ));
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1106_1]
** Syntax : void Gtm_EnableTbuChannel(uint8 TbuChannelNo)                     **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  TbuChannelNo - TBU Channel Number                        **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Inline function to enable the TBU Channel.               **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_EnableTbuChannel(uint8 TbuChannelNo)
{
  if(TbuChannelNo < GTM_NO_OF_TBU_CHANNELS)
  {
    GTM_TBU_CHEN.U |=  \
    (uint32_t)(GTM_TBU_CHAN_ENABLE << (TbuChannelNo * GTM_BITS_PER_TBU));
  }
  else
  {
    /* Do Nothing */
  }
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1106_2]
** Syntax : void Gtm_DisableTbuChannel(uint8 TbuChannelNo)                    **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  TbuChannelNo - TBU Channel Number                        **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Inline function to disable the TBU Channel.              **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_DisableTbuChannel(uint8 TbuChannelNo)
{
  if(TbuChannelNo < GTM_NO_OF_TBU_CHANNELS)
  {
    GTM_TBU_CHEN.U &= \
        (uint32_t)(~(GTM_TBU_CHAN_ENABLE << (TbuChannelNo * GTM_BITS_PER_TBU)));
  }
  else
  {
    /* Do Nothing */
  }
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1106]
** Syntax : boolean Gtm_GetTbuChannelStatus(uint8 TbuChannelNo)               **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  TbuChannelNo - TBU Channel Number                        **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     ChannelStatus - TRUE  - TBU channel is enabled           **
**                                   FALSE - TBU channel is disabled          **
**                                                                            **
** Description :     Inline function to get the enabled status of TBU Channel.**
*******************************************************************************/
_IFXEXTERN_ _INLINE_ boolean Gtm_GetTbuChannelStatus(uint8 TbuChannelNo)
{
  boolean ChannelStatus;
  uint8 ChannelPos;

  ChannelStatus = FALSE;
  /* Check if it is a valid TBU channel */
  if(TbuChannelNo < GTM_NO_OF_TBU_CHANNELS)
  {
    /* Extract the Channel Enable information from TBU CHEN register for
       individual channels */
    /* TbuChannelNo << 1 is done to  multiply TbuChannelNo by 2, since 2 bits
       are provided for each TBU channel */
    ChannelPos = (TbuChannelNo << 1);
    if(Mcal_Extract(GTM_TBU_CHEN.U, ChannelPos, 2U) > 0)
    {
      /* Return true if the channel is enabled */
      ChannelStatus = TRUE;
    }
  }
  else
  {
    /* Do Nothing */
  }
  return(ChannelStatus);
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1109]
** Syntax : uint32 Gtm_GetTbuTimerValue(uint8 TbuChannelNo)                   **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  TbuChannelNo - TBU Channel Number                        **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     Base Timer Value                                         **
**                                                                            **
** Description :     Inline function to read the Base timer value of a TBU    **
**     Channel.       **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ uint32 Gtm_GetTbuTimerValue(uint8 TbuChannelNo)
{
  uint32 RetVal;


  if(TbuChannelNo < GTM_NO_OF_TBU_CHANNELS)
  {
    /* MISRA Rule Violation 11.5, 1.2 and 11.4
       Cast away const/volatile from a pointer or reference
       Unusual pointer cast (incompatible indirect types)
       cast from pointer to pointer
       Casting of TBU to Gtm_TbuType is done to change to base type of TBU
       as the type defined in SFR file is not flexible to provide an arrayed
       approach for accessing the TBU channels. */

    RetVal =((Gtm_TbuType*)&(MODULE_GTM.TBU))->GtmTbuCh[TbuChannelNo].CH_BASE.U\
    & GTM_TBU_BASE_MASK;

  }
  else
  {
    RetVal = GTM_CLEAR_CONTENT;
  }
  return(RetVal);
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1092_1]
** Syntax : void Gtm_EnableTomChannel(uint8 ModuleNo, uint8 ChannelNo)        **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel Number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Inline function to enable the TOM Channel.               **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_EnableTomChannel(uint8 ModuleNo,uint8 ChannelNo)
{
  if(ChannelNo < GTM_TOM_TGC0_CHOSEN)
  {
    (*(Ifx_GTM_TOMx*)(MODULE_GTM.TOM)).TOM_TGC[ModuleNo].
                                                TGC[GTM_TGC0].ENDIS_STAT.U =   \
              (uint32_t)(GTM_TOM_ENABLE << (GTM_TOM_BITS_PER_CHAN * ChannelNo));
  }
  else if(ChannelNo < GTM_TOM_TGC1_CHOSEN)
  {
    (*(Ifx_GTM_TOMx*)(MODULE_GTM.TOM)).TOM_TGC[ModuleNo].
                                               TGC[GTM_TGC1].ENDIS_STAT.U =   \
        (uint32_t)(GTM_TOM_ENABLE <<  (GTM_TOM_BITS_PER_CHAN * 
                                      (ChannelNo - GTM_TOM_CHANNELS_PER_TGC)));
  }
  else
  {
    /* Do Nothing */
  }
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1092_2]
** Syntax : void Gtm_DisableTomChannel(uint8 ModuleNo, uint8 ChannelNo)       **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel Number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Inline function to disable the TOM Channel.              **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_DisableTomChannel(uint8 ModuleNo,uint8 ChannelNo)
{
  if(ChannelNo < GTM_TOM_TGC0_CHOSEN)
  {
    (*(Ifx_GTM_TOMx*)(MODULE_GTM.TOM)).TOM_TGC[ModuleNo].
                                               TGC[GTM_TGC0].ENDIS_STAT.U =   \
        (uint32_t)(GTM_TOM_CHAN_DISABLE << (GTM_TOM_BITS_PER_CHAN * ChannelNo));
  }
  else if(ChannelNo < GTM_TOM_TGC1_CHOSEN)
  {
    (*(Ifx_GTM_TOMx*)(MODULE_GTM.TOM)).TOM_TGC[ModuleNo].
                                               TGC[GTM_TGC1].ENDIS_STAT.U =   \
        (uint32_t)(GTM_TOM_CHAN_DISABLE << \
        (GTM_TOM_BITS_PER_CHAN * (ChannelNo - GTM_TOM_CHANNELS_PER_TGC)));
  }
  else
  {
    /* Do Nothing */
  }
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1097]
** Syntax : void Gtm_EnableTomCoherantUpdate(uint8 ModuleNo, uint8 ChannelNo) **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel Number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Inline function to Enable Coherant update for TOM Channel**
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_EnableTomCoherantUpdate(uint8 ModuleNo,
     uint8 ChannelNo)
{
 (*(Ifx_GTM_TOMx*)(MODULE_GTM.TOM)).TOM_TGC[ModuleNo].    \
   TGC[ChannelNo/ GTM_TOM_CHANNELS_PER_TGC].GLB_CTRL.U =         \
   (uint32_t)(GTM_TOM_ENABLE << ((GTM_TOM_BITS_PER_CHAN *        \
  (ChannelNo % GTM_TOM_CHANNELS_PER_TGC)) + GTM_TOM_FUPD_START));
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1096]
** Syntax : void Gtm_EnableAtomCoherantUpdate(uint8 ModuleNo, uint8 ChannelNo)**
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel Number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Inline function to Enable Coherant update for ATOM       **
**     Channel        **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_EnableAtomCoherantUpdate(uint8 ModuleNo,
      uint8 ChannelNo)
{
   (*(Ifx_GTM_ATOMx*)(MODULE_GTM.ATOM)).ATOM_AGC[ModuleNo].AGC_GLB_CTRL.U |=   \
   (uint32_t)(GTM_ATOM_ENABLE << ((GTM_ATOM_BITS_PER_CHAN *        \
  (ChannelNo % GTM_ATOM_CHANNELS_PER_AGC)) + GTM_ATOM_FUPD_START));
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1094_1]
** Syntax : void Gtm_EnableAtomChannel(uint8 ModuleNo, uint8 ChannelNo)       **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel Number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Inline function to enable the ATOM Channel.              **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_EnableAtomChannel(uint8 ModuleNo,uint8 ChannelNo)
{

  if(ChannelNo < GTM_CHANNELS_PER_ATOM_MODULE)
  {
    MODULE_GTM.ATOM[ModuleNo].AGC.ENDIS_STAT.U =    \
     (uint32_t)(GTM_ATOM_ENABLE << (GTM_ATOM_BITS_PER_CHAN * ChannelNo));
  }
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1094_2]
** Syntax : void Gtm_DisableAtomChannel(uint8 ModuleNo, uint8 ChannelNo)      **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel Number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Inline function to disable the ATOM Channel.             **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_DisableAtomChannel(uint8 ModuleNo,uint8 ChannelNo)
{
  if(ChannelNo < GTM_CHANNELS_PER_ATOM_MODULE)
  {
    MODULE_GTM.ATOM[ModuleNo].AGC.ENDIS_STAT.U =    \
      (uint32_t)(GTM_ATOM_CHAN_DISABLE << (GTM_ATOM_BITS_PER_CHAN * ChannelNo));
  }
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1112_2]
** Syntax : void Gtm_AddFifoEntry(                                            **
**                                 uint8  FifoChannel,                        **
**                                 uint32 Entry                               **
**                                )                                           **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  FifoChannel - Module Number                              **
**                   Entry - Channel Number                                   **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Inline function to write into FIFO.                      **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void  Gtm_AddFifoEntry(uint8 FifoChannel,uint32 Entry)
{

  MODULE_GTM.AFD0.CH[FifoChannel].BUF_ACC.U = (uint32_t)Entry;
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1112_1]
** Syntax : uint32 Gtm_ReadFifoEntry (uint8 FifoChannel)                      **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - Module Number                                 **
**                   ChannelNo - Channel Number                               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     Fifo entry                                               **
**                                                                            **
** Description :     Inline function to return the topmost FIFO entry.        **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ uint32 Gtm_ReadFifoEntry(uint8 FifoChannel)
{
  return((uint32)(MODULE_GTM.AFD0.CH[FifoChannel].BUF_ACC.U));
}


/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1121_2]
** Syntax : void Gtm_EnableDpll()                                             **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Inline function to enable DPLL.                          **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_EnableDpll(void)
{
  GTM_DPLL_CTRL_1.U |= (uint32_t)(GTM_BIT_SET << GTM_DPLL_DEN_POS);
}


/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1121_1]
** Syntax : void Gtm_DisableDpll()                                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     Inline function to disable DPLL.                         **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_DisableDpll(void)
{
  GTM_DPLL_CTRL_1.U &= (uint32_t)(~(GTM_BIT_SET << GTM_DPLL_DEN_POS));
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1092_5_PR1094_5]
** Syntax : void Gtm_TrigActTimebase (uint8 TimerModule, uint8 ModuleNo,      **
**                                    uint8 GroupNo)                          **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  TimerModule – 0 – TOM, 1 - ATOM                          **
**                   ModuleNo – TOM/ATOM Module Number                        **
**                   GroupNo – TGC/AGC Number                                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This service sets Action Timebase trigger request for the**
**     corresponding TGC/AGC of the TOM/ATOM module.     **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_TrigActTimebase (uint8 TimerModule,uint8 ModuleNo,
       uint8 GroupNo)
{
  if ((TimerModule == GTM_TOM) && (GroupNo < GTM_NO_OF_TGC_PER_MODULE))
  {
      ((*(Ifx_GTM_TOMx*)(MODULE_GTM.TOM)).TOM_TGC[ModuleNo].
                                                     TGC[GroupNo].ACT_TB.U) |= \
                                        (uint32_t)(1UL << GTM_ACTTB_TBTRIG_POS);
  }
  else if ((TimerModule == GTM_ATOM) && (GroupNo == GTM_AGC))
  {
      ((*(Ifx_GTM_ATOMx*)(MODULE_GTM.ATOM)).                                  \
       ATOM_AGC[ModuleNo].AGC_ACT_TB.U) |=                                    \
                                        (uint32_t)(1UL << GTM_ACTTB_TBTRIG_POS);
  }
  else
  {
    /* Do Nothing */
  }
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1104]
** Syntax : void Gtm_SetTimFilterThreshold (uint8 ModuleNo,uint8 ChannelNo,   **
**               uint32 FltRisingEdge, uint32 FltFallingEdge)                 **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo – TIM Module Number                             **
**                   ChannelNo – Channel Number                               **
**                   FltRisingEdge – Filter Threshold for Rising Edge         **
**                   FltFallingEdge – Filter Threshold for Falling Edge       **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This service sets Action Timebase trigger request for the**
**     corresponding TGC/AGC of the TOM/ATOM module.     **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_SetTimFilterThreshold (uint8 ModuleNo,
      uint8 ChannelNo,uint32 FltRisingEdge, uint32 FltFallingEdge)
{
  ((*(Ifx_GTM_TIMx*)(MODULE_GTM.TIM)).CH_TIM[ModuleNo].                        \
                                     CH[ChannelNo].CH_FLT_RE.U) = FltRisingEdge;
  ((*(Ifx_GTM_TIMx*)(MODULE_GTM.TIM)).CH_TIM[ModuleNo].
                                   CH[ChannelNo].CH_FLT_FE.U) = FltFallingEdge;
  
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1105]
** Syntax : void Gtm_GetTimFilterThreshold (uint8 ModuleNo, uint8 ChannelNo,  **
**                                          Gtm_TimFilterType* FltValuePtr)   **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo – TIM Module Number                             **
**                   ChannelNo – Channel Number                               **
**                   FltValuePtr->FltRisingEdge – Filter Threshold for Rising **
**                                                Edge                        **
**                   FltValuePtr->FltFallingEdge – Filter Threshold for       **
**                                                 Falling Edge               **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This service retrieves the Filter rising and falling     **
**                   edge parameters.                                         **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_GetTimFilterThreshold (uint8 ModuleNo, 
     uint8 ChannelNo,Gtm_TimFilterType* FltValuePtr)
{
  /* Updates the Filter parameters in the structure FltValuePtr */
  FltValuePtr->FltRisingEdge  = ((*(Ifx_GTM_TIMx*)(MODULE_GTM.TIM)).
                                   CH_TIM[ModuleNo].CH[ChannelNo].CH_FLT_RE.U);
  FltValuePtr->FltFallingEdge = ((*(Ifx_GTM_TIMx*)(MODULE_GTM.TIM)).
                                   CH_TIM[ModuleNo].CH[ChannelNo].CH_FLT_FE.U);


}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1110_1]
** Syntax : void Gtm_FlushFifo (uint8 FifoChannelNo)                          **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  FifoChannelNo – FIFO channel Number                      **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This service flushes the FIFO channel.                   **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_FlushFifo(uint8 FifoChannelNo)
{
  MODULE_GTM.FIFO0.CH[FifoChannelNo].CTRL.U |= \
       (uint32_t)(1UL << GTM_FIFO_FLUSH_POS);
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1110_2]
** Syntax : void Gtm_CtrlFifoStream (uint8 FifoChannelNo, boolean ToStart)    **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  FifoChannelNo – FIFO channel Number                      **
**                   ToStart – TRUE – Start FIFO Stream                       **
**                             FALSE – Stop FIFO Stream                       **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This service flushes the FIFO channel.                   **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_CtrlFifoStream (uint8 FifoChannelNo, 
    boolean ToStart)
{
  uint32 Action;

  Action = ((ToStart == TRUE)?GTM_FIFO_ENABLE:GTM_FIFO_DISABLE);

  GTM_F2A0_ENABLE.U = \
          (uint32_t)(Action << (FifoChannelNo * GTM_FIFO_BITS_PER_CHAN));
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1116_1]
** Syntax : void Gtm_ClearMcsRam (uint8 McsModule)                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  McsModule – MCS module Number                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This service clears the MCS RAM. It should be ensured    **
**     that no MCS channel of the chosen MCS module is active   **
**     and RF_PORT bit in GTM_CTRL is cleared before this       **
**     function is called.          **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_ClearMcsRam(uint8 McsModule)
{
  MODULE_GTM.MCS[McsModule].CTRL.U |= (uint32_t)(1UL << GTM_MCS_RAMRST_POS);
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1116_2]
** Syntax : void Gtm_CtrlMcsTrigger (uint8 McsModule, uint8 TriggerNo,        **
**                                   boolean TriggerCtrl )                    **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  McsModule – MCS module Number                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This service flushes the FIFO channel.                   **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_CtrlMcsTrigger (uint8 McsModule, uint8 TriggerNo,
      boolean TriggerCtrl )
{
  if(TriggerCtrl == TRUE)
  {
    MODULE_GTM.MCS[McsModule].CH0.STRG.U |= (uint32_t)(1UL << TriggerNo);
  }
  else
  {
    MODULE_GTM.MCS[McsModule].CH0.CTRG.U |= (uint32_t)(1UL << TriggerNo);
  }
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1122]
** Syntax : void Gtm_TrigDpllSwRst ()                                         **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This service resets all register and internal states of  **
**     the DPLL.      **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_TrigDpllSwRst(void)
{
  GTM_DPLL_CTRL_1.U |= (uint32_t)(GTM_BIT_SET << GTM_DPLL_SWR_POS);
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1124]
** Syntax : void Gtm_GetDpllStatus(Gtm_DpllStatType* StatusPtr)               **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): StatusPtr :-                                             **
**                           DpllStatus – Provides the DPLL status            **
**                IntStatus – Provides the DPLL interrupt Status   **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :                                                              **
** 1) Returns the content of GTM_DPLL_STATUS register in DpllStatus register. **
** 2) Returns the content of GTM_DPLL_IRQ_NOTIFY register in IntStatus.       **
**      **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_GetDpllStatus(Gtm_DpllStatType* StatusPtr)
{
  StatusPtr->DpllStatus = GTM_DPLL_STATUS.U;
  StatusPtr->IntStatus = GTM_DPLL_IRQ_NOTIFY.U;
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1126]
** Syntax : void Gtm_SetDpllRefMode(uint8 RefMode)                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  RefMode – 0 -> Normal Mode                               **
**                             1 -> Emergency Mode                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This service sets the Reference mode of the DPLL module  **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_SetDpllRefMode(uint8 RefMode)
{
  if(RefMode == 1U)
  {
    GTM_DPLL_CTRL_0.U |= (uint32_t)(1UL << GTM_DPLL_RMO_POS);
  }
  else
  {
    GTM_DPLL_CTRL_0.U &= (uint32_t)(~(1UL << GTM_DPLL_RMO_POS));
  }
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1127]
** Syntax : void Gtm_CtrlSpeModule(uint8 ModuleNo, Boolean ToEnable)          **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - SPE Module Number                             **
**                   ToEnable – TRUE -> Enable SPE Module                     **
**                              FALSE -> Disable SPE Module                   **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This service enables/disables SPE module                 **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_CtrlSpeModule(uint8 ModuleNo, uint8 ToEnable)
{
  if(ToEnable == 1U)
  {
    MODULE_GTM.SPE[ModuleNo].CTRL_STAT.U |= (uint32_t)1UL;
  }
  else
  {
    MODULE_GTM.SPE[ModuleNo].CTRL_STAT.U &= (uint32_t)~(1UL);
  }
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1129]
** Syntax : uint16 Gtm_GetSpeInputPat(uint8 ModuleNo)                         **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - SPE Module Number                             **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     uint16 InputPat ->                                       **
**                                 Bit 0 to 2  : AIP (Actual Input Pattern)   **
**                                 Bit 3       : 0                            **
**                                 Bit 4 to 6  : PIP (Previous Input Pattern) **
**                                 Bit 7       : 0                            **
**                                 Bit 8 to 10 : NIP (New Input Pattern)      **
** Description :     This service provides the Input Pattern history of SPE   **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ uint16 Gtm_GetSpeInputPat(uint8 ModuleNo)
{

  uint16 RetVal;
  RetVal = (uint16)((MODULE_GTM.SPE[ModuleNo].CTRL_STAT.U >> GTM_SPE_AIP_POS) \
       & (uint32)GTM_SPE_AIP_NIP_PIP_MASK);
  return (RetVal);
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1133_PR1134]
** Syntax : void Gtm_CtrlMapInput(uint32 MapInput)                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  MapInput – Same format as Gtm_Map_Ctrl register          **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This service provides the Input selection for MAP module.**
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_CtrlMapInput(uint32 MapInput)
{
  GTM_MAP_CTRL.U = (uint32_t)MapInput;
}




/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1111]
** Syntax : uint8 Gtm_GetFifoStatus (uint8 FifoChannelNo)                     **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  Uint8 – Fifo Channel status – FIFO full, FIFO empty, FIFO**
**                   Lower watermark reached, FIFO Upper Watermark reached.   **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This service provides the status of the referred FIFO    **
**                   channel number                                           **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ uint8 Gtm_GetFifoStatus (uint8 FifoChannelNo)
{
  return((uint8)(MODULE_GTM.FIFO0.CH[FifoChannelNo].STATUS.U));
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1117_2_PR1115_2]
** Syntax : boolean Gtm_GetMcsRamRstStat (uint8 McsModule)                    **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  McsModule – MCS module number                            **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     status –                                                 **
**                            TRUE – MCS RAM reset in progress                **
**                            FALSE – no MCS RAM reset active                 **
**                                                                            **
** Description :     This service provides the status of MCS Ram Reset        **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ boolean Gtm_GetMcsRamRstStat (uint8 McsModule)
{
  return((boolean)\
    ((MODULE_GTM.MCS[McsModule].CTRL.U & (1UL << GTM_MCS_RAMRST_POS)) \
          >>  GTM_MCS_RAMRST_POS));
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1119]
** Syntax : void Gtm_WriteMcsRam (uint32* McsStartAddress,                    **
**                                const uint32* const McsCodePtr,             **
**                                uint32 CodeSize)                            **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  McsStartAddress – Start Address from where the code has  **
**                                     to be written to.                      **
**                   McsCodePtr – Pointer to the microcode that has to be     **
**                                written into MCS Ram                        **
**                   CodeSize – Size of MCS microcode(Number of Words(4 bytes)**
**                              to be written                                 **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This service writes microcode into MCS RAM               **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_WriteMcsRam (uint32* McsStartAddress,
          const uint32* const McsCodePtr,
          uint32 CodeSize)
{
  uint32 Count;
  /* Write corresponding locations of MCS the content at McsCodePtr */
  for (Count=0UL; Count < CodeSize; Count++)
  {
    /* MISRA Rule Violation 17.4
       Pointer arithmetic other than array indexing used.
       Pointer Arithmetic is used to simplify the code */

    McsStartAddress[Count] = McsCodePtr[Count];


  }
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1114_1]
** Syntax : boolean Gtm_CtrlMcsChannel (uint8 McsModNo, uint8 McsChannel,     **
**                                   uint8 Activity)                          **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  McsModNo – MCS module number                             **
**                   McsChannel – MCS Channel Number                          **
**                   Activity – 1 – Start MCS channel                         **
**                              0 – Stop MCS Channel                          **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     TRUE - Function exected successfully                     **
**                   FALSE - Function could not be executed since RAM reset   **
**                Is ongoing.                                      **
**                                                                            **
** Description :     This service starts or stops an MCS channel              **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ boolean Gtm_CtrlMcsChannel (uint8 McsModNo,
                                  uint8 McsChannel, uint8 Activity)
{
  boolean RetVal;
  RetVal = FALSE;
  if(Gtm_GetMcsRamRstStat(McsModNo) == FALSE)
  {
    if(Activity == 1UL)
    {
        ((*(Ifx_GTM_MCSx*)(MODULE_GTM.MCS)).      \
      CH_MCS[McsModNo].CH[McsChannel].CH_CTRL.U) |= (uint32_t)1UL;
    }
    else
    {
       ((*(Ifx_GTM_MCSx*)(MODULE_GTM.MCS)).       \
          CH_MCS[McsModNo].CH[McsChannel].CH_CTRL.U) &= (uint32_t)~(1UL);
    }
    RetVal = TRUE;
  }
  return(RetVal);

}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1114_2]
** Syntax : boolean Gtm_InitMcsProgCntr (uint8 McsModNo, uint8 McsChannel,    **
**                                    uint16 PcValue)                         **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  McsModNo – MCS module number                             **
**                   McsChannel – MCS Channel Number                          **
**                   PcValue – Program Counter Value to be initialized        **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     TRUE: PC written Successfully                            **
**                   FALSE: PC not written since Channel is enabled           **
**                                                                            **
** Description :     This service initializes the program counter of MCS      **
**                   channel with the value given in PcValue.                 **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ boolean Gtm_InitMcsProgCntr (uint8 McsModNo, 
       uint8 McsChannel,uint16 PcValue)
{
  boolean RetVal;
  RetVal = FALSE;
  /* Check if the channel is disabled */
    if(((((*(Ifx_GTM_MCSx*)(MODULE_GTM.MCS)).CH_MCS[McsModNo].         \
    CH[McsChannel].CH_CTRL.U) & GTM_MCS_CHCTRL_EN_MASK) == 0U))
  {
    /* Set the PC value only if the channel is disabled */
    ((*(Ifx_GTM_MCSx*)(MODULE_GTM.MCS)).CH_MCS[McsModNo].        \
                                    CH[McsChannel].CH_PC.U) = (uint32_t)PcValue;
    RetVal = TRUE;
  }
  return(RetVal);

}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1114_4]
** Syntax : void Gtm_TrigMcsIntrpt (uint8 McsModNo, uint8 McsChannel,         **
**                                  uint8 IntrptToTrig)                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  McsModNo – MCS module number                             **
**                   McsChannel – MCS Channel Number                          **
**        IntrptToTrig –                                           **
**                           0 – MCS Channel Interrupt                        **
**                           1 – Stack Counter Overflow/Underflow Interrupt   **
**                           2 – Memory Access out of range interrupt         **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This service force triggers interrupt of type specified  **
**     by IntrptToTrigger. RF_PROT bit in GTM_CTRL shoud be     **
**     cleared for this functionality to work     **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_TrigMcsIntrpt (uint8 McsModNo, uint8 McsChannel,
     uint8 IntrptToTrig)
{

  ((*(Ifx_GTM_MCSx*)(MODULE_GTM.MCS)).CH_MCS[McsModNo].CH[McsChannel].         \
      CH_IRQ_FORCINT.U) |= (uint32_t)(1UL << IntrptToTrig);
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1114_3]
** Syntax : void Gtm_CtrlMcsIntrpt (uint8 McsModNo, uint8 McsChannel,         **
**                                  uint8 IntrptToCtrl, uint8 CtrlType)       **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  McsModNo – MCS module number                             **
**                   McsChannel – MCS Channel Number                          **
**        IntrptToCtrl –                                           **
**                           0 – MCS Channel Interrupt                        **
**                           1 – Stack Counter Overflow/Underflow Interrupt   **
**                           2 – Memory Access out of range interrupt         **
**                   CtrlType – 0 – Enable Interrupt                          **
**                              1 – Disable Interrupt                         **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This service enables or disables interrupt of type       **
**                   specified by IntrptToCtrl.                               **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_CtrlMcsIntrpt (uint8 McsModNo, uint8 McsChannel,
     uint8 IntrptToCtrl, uint8 CtrlType)
{

  if(CtrlType == GTM_ENABLE_INTERRUPT)
  {
    ((*(Ifx_GTM_MCSx*)(MODULE_GTM.MCS)).CH_MCS[McsModNo].CH[McsChannel].
          CH_IRQ_EN.U) |= (uint32_t)(1UL << IntrptToCtrl);
  }
  else if(CtrlType == GTM_DISABLE_INTERRUPT)
  {
    ((*(Ifx_GTM_MCSx*)(MODULE_GTM.MCS)).CH_MCS[McsModNo].CH[McsChannel].
    CH_IRQ_EN.U) &= (uint32_t)~(1UL << IntrptToCtrl);

  }
  else
  {
    /* Do Nothing */
  }
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1116_3]
** Syntax : void Gtm_TrigMcsReset (uint8 McsModNo, uint32 ResetVal)           **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  McsModNo – MCS module number                             **
**                   ResetVal – Resetting Channel, Cancelling Aru transfer and**
**                              WURM instruction in the structure of MCS_RST  **
**                              register.                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value:     None                                                     **
**                                                                            **
** Description :     This service writes the content of ResetVal into         **
**                   GTM_MCSi_RST register where i depends on MCS module no.  **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_TrigMcsReset (uint8 McsModNo, uint32 ResetVal)
{
  /* Writes MCS RST register with the content of ResetVal */
  MODULE_GTM.MCS[McsModNo].RST.U = (uint32_t)ResetVal;
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1117_1_PR1115_1]
** Syntax : uint32 Gtm_GetMcsErrTrigStatus (uint8 McsModNo)                   **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  McsModNo – MCS module number                             **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value :    ErrTrigStatus – Lower 16 bits holds the Trigger Status of**
**                   all the channels in the MCS modules. Upper 16 bits holds **
**                   the error information of all the channels.               **
**                                                                            **
** Description :     This service returns the error and trigger status of all **
**                   the channels of the MCS module.                          **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ uint32 Gtm_GetMcsErrTrigStatus (uint8 McsModNo)
{
  uint32 RetVal;

  /* Lower 16 bits is stored with the Trigger information */
  RetVal = MODULE_GTM.MCS[McsModNo].CH0.STRG.U;
  /* Upper 16 bits is filled with error information */
  RetVal |= MODULE_GTM.MCS[McsModNo].ERR.U << GTM_UPPER_HALFWORD;

  return((uint32)RetVal);
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1116_4]
** Syntax : void Gtm_ResetMcsErrStatus (uint8 McsModNo, uint8 McsChannel)     **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  McsModNo – MCS module number                             **
**                   McsChannel – MCS Channel Number                          **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value :    None                                                     **
**                                                                            **
** Description :     This service resets the error information of the         **
**                   requested MCS channel.                                   **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_ResetMcsErrStatus (uint8 McsModNo, 
                                                               uint8 McsChannel)
{
  /* Writes a value 1 to the Channel error position to clear the error */
  MODULE_GTM.MCS[McsModNo].ERR.U |= (uint32)(GTM_BIT_SET << McsChannel);
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1120]
** Syntax : void Gtm_InitDpllRam (void)                                       **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  None                                                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value :    None                                                     **
**                                                                            **
** Description :     This service initializes the DPLL RAM. This API does not **
**                   wait till the completion of RAM Initialization. DPLL     **
**                   should be in the disabled state before this API is called**
*******************************************************************************/
_IFXEXTERN_ _INLINE_ void Gtm_InitDpllRam (void)
{
  /* Sets the INIT_RAM bit of DPLL_RAM_INI register */
  GTM_DPLL_RAM_INI.U |= (uint32_t)GTM_DPLL_RAMRST_MASK;
}

/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1093_PR1095]
** Syntax : _INLINE_ uint32 Gtm_GetTimerRegisters(                            **
**              uint8 ModuleNo,uint8 GroupNo, Gtm_TimerRegistersType RegName) **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - TOM/ATOM Module Number                        **
**                   GroupNo - TOM TGC/ATOm AGC number                        **
**                   RegName - Name of the Register to be read                **
**                   ModType - 0(GTM_TOM) -  TOM Channel                      **
**                             1(GTM_ATOM) - ATOM Channel                     **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value :    RegVal - Register Value                                  **
**                                                                            **
** Description :     This service returns the register values of the requested**
**     register                                                               **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ uint32 Gtm_GetTomTimerRegisters( uint8 ModuleNo,
         uint8 GroupNo, Gtm_TomTimerRegistersType RegName)
{
  volatile uint32* RegPtr;
  volatile uint32 RegVal;

  RegVal = 0UL;

  /* 
     Type conversion of GTM_TOM0_AGC_GLB_CTRL to uint32* is performed to abide 
     to the type of ReqPtr. The code is structured to access different 
     registers starting from the base address. Since type of different 
      registers are different, this casting is done.

     Pointer arithmetic is performed to get different register contents starting
     from Base address. This is to simplify the implementation.
  */

    /* Set the base address to the first Register of TOM TGC */
    RegPtr = (uint32*)&GTM_TOM0_TGC0_GLB_CTRL;

    /* Get the value of the Requested register by adding the Index to the base
       address */
    RegVal = *(RegPtr + ((GTM_TOM_TGC_OFFSET * GroupNo) + \
       (GTM_TOM_MODULE_OFFSET * ModuleNo) + (uint32_t)RegName));

  

  return(RegVal);
}
/*******************************************************************************
** Traceability : [cover parentID=DS_NAS_PR1093_PR1095]
** Syntax : _INLINE_ uint32 Gtm_GetAtomTimerRegisters( uint8 ModuleNo,        **
**        uint8 GroupNo, Gtm_TimerRegistersType RegName)                      **
** [/cover]                                                                   **
**                                                                            **
** Service ID:       none                                                     **
**                                                                            **
** Sync/Async:       Synchronous                                              **
**                                                                            **
** Reentrancy:       reentrant                                                **
**                                                                            **
** Parameters (in):  ModuleNo - TOM/ATOM Module Number                        **
**     GroupNo - TOM TGC/ATOm AGC number                                      **
**     RegName - Name of the Register to be read                              **
**                                                                            **
** Parameters (out): None                                                     **
**                                                                            **
** Return value :    RegVal - Register Value                                  **
**                                                                            **
** Description :     This service returns the register values of the requested**
**     register                                                               **
*******************************************************************************/
_IFXEXTERN_ _INLINE_ uint32 Gtm_GetAtomTimerRegisters( uint8 ModuleNo,
         uint8 GroupNo, Gtm_AtomTimerRegistersType RegName)
{
  volatile uint32* RegPtr;
  volatile uint32 RegVal;

  RegVal = 0UL;

  /* 
     Type conversion of GTM_ATOM0_AGC_GLB_CTRL to uint32* is performed to abide 
     to the type of ReqPtr. The code is structured to access different 
     registers starting from the base address. Since type of different 
      registers are different, this casting is done.

     Pointer arithmetic is performed to get different register contents starting
     from Base address. This is to simplify the implementation.
  */

    /* Set the base address to the first Register of ATOM AGC */
    RegPtr = (uint32*)&GTM_ATOM0_AGC_GLB_CTRL;

    /* Get the value of the Requested register by adding the Index to the base
       address */
    RegVal = *(RegPtr + ((GTM_ATOM_AGC_OFFSET * GroupNo) + \
       (GTM_ATOM_MODULE_OFFSET * ModuleNo) + (uint32_t)RegName));


  return(RegVal);
}


#define GTM_STOP_SEC_CODE
#include "MemMap.h"


#endif
 /* #ifndef GTM_H */
