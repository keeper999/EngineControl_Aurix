/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : L9960                                                                                           */
/* !Description     : Driver for H-Bridge device ST L9960                                                             */
/*                                                                                                                    */
/* !File            : L9960_Types.h                                                                                   */
/* !Description     : L9960 Types definition                                                                          */
/*                                                                                                                    */
/* !Reference       :                                                                                                 */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: LIBEMB:A6086.A-SRC;1 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#ifndef L9960_TYPES_H
#define L9960_TYPES_H

#include "Std_Types.h"
#include "Spi.h"
#include "Pwm.h"
#include "DGOHAL.h"

/* Forward declaration, needed to function pointer type declaration */
typedef struct L9960_tstrConfig_tag L9960_tstrConfig;
typedef struct L9960_strData_tag    L9960_strData;

/* For callout/callback functions */
typedef void (*L9960_tpfVoidVoidFunction)(void);
typedef const L9960_tpfVoidVoidFunction L9960_tkpfVoidVoidFunction;


typedef struct
{
   uint8 Stuf;
} L9960_ConfigType;

/* Function pointer type, on sequence start function */
typedef void (*L9960_tpfvidSpiM_StartSeqFct)(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData);
typedef const L9960_tpfvidSpiM_StartSeqFct L9960_tkpfvidSpiM_StartSeqFct;

/* Function pointer type, on sequence Tx function */
typedef void (*L9960_tpfvidSpiM_TxConf)(const L9960_tstrConfig *pkstrConfig, L9960_strData *pstrData,
                                        uint16 u16ReceiveData, uint8 u8SpiError);
typedef const L9960_tpfvidSpiM_TxConf L9960_tkpfvidSpiM_TxConf;

/**********************************************************************************************************************/
/* List of Sequences to send by SPI, ordered by prioity                                                               */
/**********************************************************************************************************************/
typedef enum
{
   /* Sequences must be ordered highest priority first */
   
   L9960_SPIM_SEQ_HWSC,   
   
      /* The L9960_SPIM_SEQ_INIT_ALL_REGISTER sequence must be higher priority than                  */
      /* L9960_SPIM_SEQ_CHECK_ALL_REGISTER because we need to init register before to read them back */
   L9960_SPIM_SEQ_INIT_ALL_REGISTER,
   L9960_SPIM_SEQ_CHECK_ALL_REGISTER,

   L9960_SPIM_SEQ_ON_DIAGNOSTIC_1,
   L9960_SPIM_SEQ_ON_DIAGNOSTIC_2,
   L9960_SPIM_SEQ_OFF_DIAGNOSTIC,

   /* /!\ Don't change nor move following defines */
   L9960_SPIM_SEQ_WAITING_STATE  /* Nothing to do, must be the last enum value */
} L9960_tenuSpiMSequences;


/**********************************************************************************************************************/
/* Status of registers                                                                                                */
/**********************************************************************************************************************/
typedef enum
{
   L9960_REGISTER_INIT_NOT_DONE,
   L9960_REGISTER_INIT_RUNNING,
   L9960_REGISTER_INIT_DONE,
   L9960_REGISTER_INIT_FAIL
} L9960_tenuSpiM_RegisterState;

typedef enum
{
   L9960_REGISTER_READ_NOT_DONE,
   L9960_REGISTER_READ_RUNNING,
   L9960_REGISTER_READ_DONE,
   L9960_REGISTER_READ_FAIL
} L9960_tenuSpiM_RegisterReadState;

/* This define is used for arrays size, computed from the last value of the enum  */
#define L9960_SPIM_SEQ_NB_OF_CMD (L9960_SPIM_SEQ_WAITING_STATE)

/**********************************************************************************************************************/
/* SpiM State machine to launch the HW Self Check                                                                     */
/**********************************************************************************************************************/
typedef enum
{
   /* Start by 1, because 0 is reserved for the state: NONE sequence are running */
   L9960_SPIM_SEQ_HWSC_SEND_RESTART_REG = 1,
   L9960_SPIM_SEQ_HWSC_READ_STATE_1,
   L9960_SPIM_SEQ_HWSC_RESEND_READ_STATE_1,

   /* shall be the last one, because it is used to start the next state machine enum values */
   L9960_SPIM_SEQ_HWSC_WAITING_STATE
} L9960_tenuSpiM_HwscSM;

/**********************************************************************************************************************/
/* SpiM State machine to Initialize all L9960 registers                                                               */
/**********************************************************************************************************************/
typedef enum
{
   /* TODO: to finish */
   L9960_SPIM_SEQ_INIT_ALL_REG_RESTART_TRIGGER = L9960_SPIM_SEQ_HWSC_WAITING_STATE + 1,
   L9960_SPIM_SEQ_INIT_ALL_REG_CONFIG_1,
   L9960_SPIM_SEQ_INIT_ALL_REG_CONFIG_2,
   L9960_SPIM_SEQ_INIT_ALL_REG_CONFIG_3,
   L9960_SPIM_SEQ_INIT_ALL_REG_CONFIG_4,

   /* shall be the last one, because it is used to start the next state machine enum values */
   L9960_SPIM_SEQ_INIT_ALL_REG_WAITING_STATE
} L9960_tenuSpiM_InitAllRegSM;

/**********************************************************************************************************************/
/* SpiM State machine to check all L9960 registers                                                                    */
/**********************************************************************************************************************/
typedef enum
{
   /* TODO: to finish */
   L9960_SPIM_SEQ_CHECK_ALL_REG_READ_CONFIG_1 = L9960_SPIM_SEQ_INIT_ALL_REG_WAITING_STATE + 1,
   L9960_SPIM_SEQ_CHECK_ALL_REG_READ_CONFIG_2,
   L9960_SPIM_SEQ_CHECK_ALL_REG_READ_CONFIG_3,
   L9960_SPIM_SEQ_CHECK_ALL_REG_READ_CONFIG_5, /* note: the config 4 is empty, so no need to read it */

   /* shall be the last one, because it is used to start the next state machine enum values */
   L9960_SPIM_SEQ_CHECK_ALL_REG_WAITING_STATE
} L9960_tenuSpiM_CheckAllRegSM;

/**********************************************************************************************************************/
/* SpiM State machine to read diagnostics from L9960 registers, when L9960 is not in tristate                         */
/**********************************************************************************************************************/
/* The same state are used by onDiag Sequence 1 and 2 ... but not in same conditions. So this typedef is shared       */
typedef enum
{
   L9960_SPIM_SEQ_DIAG_ON_READ_STATE_1 = L9960_SPIM_SEQ_CHECK_ALL_REG_WAITING_STATE + 1,
   L9960_SPIM_SEQ_DIAG_ON_READ_STATE_2,
   L9960_SPIM_SEQ_DIAG_ON_READ_OVER_CURRENT,
   L9960_SPIM_SEQ_DIAG_ON_REQUEST_OPEN_LOAD,
   L9960_SPIM_SEQ_DIAG_ON_END,

   /* shall be the last one, because it is used to start the next state machine enum values */
   L9960_SPIM_SEQ_DIAG_ON_WAITING_STATE
} L9960_tenuSpiM_DiagOnSM;

/**********************************************************************************************************************/
/* SpiM State machine to read diagnostics from L9960 registers, when L9960 is in tristate                             */
/**********************************************************************************************************************/
typedef enum
{
   L9960_SPIM_SEQ_DIAG_OFF_READ_STATE_1 = L9960_SPIM_SEQ_DIAG_ON_WAITING_STATE + 1,
   L9960_SPIM_SEQ_DIAG_OFF_READ_STATE_2,
   L9960_SPIM_SEQ_DIAG_OFF_READ_OFF_STATE,

   /* shall be the last one, because it is used to start the next state machine enum values */
   L9960_SPIM_SEQ_DIAG_OFF_WAITING_STATE
} L9960_tenuSpiM_DiagOffSM;

/**********************************************************************************************************************/
/* SpiM State machine merging in an union                                                                             */
/**********************************************************************************************************************/
/* as only one sequence could be run, an union could be used to handle all sequences */
/* each enum use different value, that increase the robustness in case of bug:       */
/* prevent 2 state machine run in same time                                          */
typedef union
{
   enum {L9960_SPI_SEQ_IDLE = 0} All;
   L9960_tenuSpiM_HwscSM         HWSC;
   L9960_tenuSpiM_InitAllRegSM   InitAllReg;
   L9960_tenuSpiM_CheckAllRegSM  CheckAllReg;
   L9960_tenuSpiM_DiagOnSM       OnDiagnostic;
   L9960_tenuSpiM_DiagOffSM      OffDiagnostic;
} L9960_tudtSpiM_StateMachine;


/**********************************************************************************************************************/
/* L9960 Main state Machine                                                                                           */
/**********************************************************************************************************************/
typedef enum
{
   L9960_STATE_UNINIT,                  /* reset value: L9960_vidInit not yet called  */
   L9960_STATE_HWSC_START,              /* transient state to launch the HWSC process */
   L9960_STATE_HWSC_RUNNING,            /* HWSC in progress                           */
   L9960_STATE_REGISTERS_INIT_START,    /* transient state to launch the init reg     */
   L9960_STATE_REGISTERS_INIT_RUNNING,  /* Register init in progress                  */
   L9960_STATE_REGISTERS_CHECK_RUNNING, /* Check register config in progress          */
   L9960_STATE_ENABLE,                  /* Normal Operation and enable                */
   L9960_STATE_DISABLE,                 /* Normal operation but disable               */
   L9960_STATE_TRISTATE,                /* L9960 is in tristate                       */
   L9960_STATE_HW_FAILURE               /* L9960 is disable until next reset          */

} L9960_tenuChipState;


/**********************************************************************************************************************/
/* Configuration Structure of a L9960 Instance                                                                        */
/**********************************************************************************************************************/


/* Constant Data */
struct L9960_tstrConfig_tag
{
   const boolean                    *pkbCurrentSlewRate; /* point to the calibration which define the current slew rate: slow/fast */
   const boolean                    *pkbVoltageSlewRate; /* point to the calibration which define the voltage slew rate: slow/fast */
   const boolean                    *pkbTemperatureDependentSlewRate; /* point to the calibration which define the TDSR value */
   const boolean                    *pkbTSecure; /* point to the calibration which define the TSECURE value */
   const uint8                      *pku8CurrentLimitRange; /* point to the calibration which define the CL ranges */
   const uint8                      *pku8Tdiag1; /* point to the calibration which define the TDIAG1 value */
   const uint8                      *pku8OtsdThrVar; /* point to the calibration which define the OTSD_th_var value */
   const uint8                      *pku8OtwarnThrVar; /* point to the calibration which define the OTWARN_th_var value */

   /* Leave Tristate Mode functions ptr */
   L9960_tkpfVoidVoidFunction pfvidSetDisPinToHigh; /* callout to set DIS pin to STD_HIGH level */
   L9960_tkpfVoidVoidFunction pfvidSetDisPinToLow;  /* callout to set DIS pin to STD_LOW level  */

   Spi_ChannelType            udtSpiChannelId;      /* AUTOSAR SPI Channel      */
   Spi_SequenceType           udtSpiSequenceId;     /* AUTOSAR Sequence Channel */

   Pwm_ChannelType            udtPwmChannel;        /* PWM channel ID for the PWM output pin */
   Pwm_ChannelType            udtDirChannel;        /* PWM channel ID for the DIR output pin */

   /*****************************************/
   /* Data for the Diagnostic State machine */
   /*****************************************/
   DGOHAL_tudtChannel         udtDgohalActuatorChannel; /* Channel of the DGOHAL for Actuator faults */
   DGOHAL_tudtChannel         udtDgohalEcuChannel;      /* Channel of the DGOHAL for ECU faults      */

   /* Number of MainFunction period to let DIS pin in high state in the leave tristate mode sequence  */
   /* This value shall be choosen accroding these requirements:                                       */
   /* - DIS pin must be in High level during a minimum time of XXX (tbd) to have a valid leave        */
   /*   disable mode.                                                                                 */
   /* - HSI requirement for minimum time to wait a certain time before to try to re enable the output */
   uint8                      u8TristateTimerReload;

};

/**********************************************************************************************************************/
/* Variable data Structure of a L9960 Instance                                                                        */
/**********************************************************************************************************************/
struct L9960_strData_tag
{
   L9960_tudtSpiM_StateMachine udtSpiM_StateMachine;
   L9960_tenuSpiMSequences     enuSpiM_SeqRunning;
   L9960_tenuChipState         enuHBridgeState;          /* State Machine for the H Bridge */
   
   L9960_tenuSpiM_RegisterState     enuSpiMRegisterInitialized; /* States of the L9960 registers */
   L9960_tenuSpiM_RegisterReadState enuSpiMRegisterRead;        /* State of the L9960 registers read */

   uint16                      u16LastRequestedDirDutyCycle; /* PWM pin duty cycle setpoint required by last
                                                               L9960_vidWrite call */
   uint16                      u16LastRequestedPwmDutyCycle; /* DIS pin duty cycle setpoint required by last
                                                               L9960_vidWrite call */

   uint16                      u16SpiLastSentCommand;        /* Last SPI comamnd sent (contain command byte and data
                                                               byte) */


   uint16                      u16SpiMChipRegConfiguration1; /* Expected value of #3 word (Configuration 1) */
   uint16                      u16SpiMChipRegConfiguration2; /* Expected value of #4 word (Configuration 2) */
   uint16                      u16SpiMChipRegConfiguration3; /* Expected value of #5 word (Configuration 3) */
   uint16                      u16SpiMChipRegConfiguration4; /* Expected value of #6 word (Configuration 4) */


   uint8                       u8SpiDiagnostic;                /* To store a low layer SPI error to report in DGOHAL
                                                                                  */
   uint8                       u8SpiTransmitErrorCounter;      /* Number of remaining allowed send command try (in case
                                                                 of SPI error) */

   uint16                      u16SpiMChipRegOverCurrent;      /* last read value of #1 (Over Current Register) */
   uint16                      u16SpiMChipRegState1;           /* last read value of #8a (State 1 Register) */
   uint16                      u16SpiMChipRegState2;           /* last read value of #8b (State 2 Register) */
   uint16                      u16SpiMChipRegOffDiag;          /* last read value of #8b (State 2 Register) */

   uint16                      u16SpiMChipRegConfig1;          /* last read value of #7a (Config 1 Register) */
   uint16                      u16SpiMChipRegConfig2;          /* last read value of #7b (Config 2 Register) */
   uint16                      u16SpiMChipRegConfig3;          /* last read value of #7c (Config 3 Register) */
   uint16                      u16SpiMChipRegConfig4;          /* last read value of #7c (Config 4 Register) */
   uint16                      u16SpiMChipRegConfig5;          /* last read value of #7e (Config 5 Register) */

   uint8                       u8TristateModeTimer;            /* SW timer to handle HIGH time of DIS pin */
                                                               /* 1 dec = MainFunction period */
                                                               
   uint8                      u8SpiM_HWSCTimeout;                   /* Timeout to got a HWSC result  */
   uint8                      u8SpiM_HWSCCheckCounter;              /* Number max of HWSC result read */
   uint8                      u8HWSCLastStatus;                     /* Last HWSC status */
   
   uint8                      u8RegisterCheckCounter;   /* Number of try to do the register check */
   uint8                      u8RegisterInitCounter;   /* Number of try to do the register initialization */


   boolean                     bOnDiagnosticIsAvailable;       /* TRUE: new diagnostic, when chip is on, was read from L9960 chip */
   boolean                     bOffDiagnosticIsAvailable;      /* TRUE: new diagnostic, when chip is in tristate, was read from L9960 chip */


   boolean                     abSpiM_SeqRequest[L9960_SPIM_SEQ_NB_OF_CMD]; /* one bool per sequence. TRUE = sequence to
                                                                              run */
                                                                            /* the table order is same as
                                                                              L9960_tenuSpiMSequences enums */

   boolean                    bLeaveTristateModeAllowed;    /* Goes to TRUE when u8TristateModeTimer elapse */
                                                                              
   boolean                    bEnableSetpoint; /* =1 on L9960_vidEnable call, and 0 on L9960_vidDisable call */
                                                                              
   boolean                    bSpiDummyFrameSent;  /* Boolean set when we send the dummy frame */
   boolean                    bSpiMNewRegOverCurrent;   /* Register #1 (Over Current Register) has been updated */
   boolean                    bSpiMNewRegState2;        /* Register #8b (State 2 Register) has been updated */
   boolean                    bSpiMNewRegState5;        /* Register #7e (State 5 Register) has been updated */


                                                         
   boolean                    bHWSCPassed;             /* Result of the HW Self Check, = TRUE then HWSC success */ 
   
   boolean                    bSupplyVoltageFault;     /* VPS or VDD error detected */
   boolean                    bILimitFault;            /* ILIM warning detected */
   boolean                    bOverCurrentFault;       /* An overcurrent has been detected */
   boolean                    bOffDiagOverCurrentFault; /* An overcurrent has been detected during Off state diagnostic */
   boolean                    bOverLoadFault;          /* An overload has been detected */
   boolean                    bOverTemperatureFault;   /* An over temperature has been detected */
   boolean                    bOpenLoadLastState;      /* Last Open load state (0= no open laod / 1= open load */
                                                       /* Used by diangostic manager to choose which SPI sequence to launch */
   boolean                    bOpenLoadDiagDone;       /* The open load diagnostic was done or not */
   boolean                    bOffDiagOpenLoadFault;   /* Open load detected during Off state diagnostic */
   boolean                    bCCFault;                /* Communcation check fault */
   boolean                    bHwscNotDoneFault;       /* Used only on runtime, to detect a L9960 chip reset */
   boolean                    bNDISPinFault;           /* = TRUE, the h bridge is disabled due to NDIS pin */
   boolean                    bHBridgeDisableFault;    /* = TRUE when L9960 answer that bridge is disable */
   boolean                    bNgFailFault;            /* Value of NGFAIL bit */
};

#endif /* L9960_TYPES_H */

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/
