/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : CJ135                                                                                           */
/* !Description     : Driver for Robert Bosch GmbH CJ135                                                              */
/*                                                                                                                    */
/* !File            : CJ135_Types.h                                                                                   */
/* !Description     : CJ135 Types definition                                                                          */
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
 * %PID: P2017_BSW:0A188677.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 **********************************************************************************************************************/

#ifndef CJ135_TYPES_H
#define CJ135_TYPES_H

#include "Std_Types.h"
#include "Spi.h"
#include "DGOHAL.h"

/* Forward declaration, needed to function pointer type declaration */
typedef struct CJ135_tstrConfig_tag CJ135_tstrConfig;
typedef struct CJ135_strData_tag    CJ135_strData;

/* For callout/callback functions */
typedef void (*CJ135_tpfVoidVoidFunction)(void);
typedef const CJ135_tpfVoidVoidFunction CJ135_tkpfVoidVoidFunction;


typedef struct
{
   uint8 Stuf;
} CJ135_ConfigType;

/* Function pointer type, on sequence start function */
typedef void (*CJ135_tpfvidSpiM_StartSeqFct)(const CJ135_tstrConfig *pkstrConfig, CJ135_strData *pstrData);
typedef const CJ135_tpfvidSpiM_StartSeqFct CJ135_tkpfvidSpiM_StartSeqFct;

/* Function pointer type, on sequence Tx function */
typedef void (*CJ135_tpfvidSpiM_TxConf)(const CJ135_tstrConfig *pkstrConfig, CJ135_strData *pstrData,
                                        uint16 u16ReceiveData, uint8 u8SpiError);
typedef const CJ135_tpfvidSpiM_TxConf CJ135_tkpfvidSpiM_TxConf;

/**********************************************************************************************************************/
/* List of Sequences to send by SPI, ordered by prioity                                                               */
/**********************************************************************************************************************/
typedef enum
{
   /* Sequences must be ordered highest priority first */
      /* The CJ135_SPIM_SEQ_INIT_CONF_REGISTER sequence must be higher priority than                 */
      /* CJ135_SPIM_SEQ_READ_CONF_REGISTER because we need to init register before reading them back */
   CJ135_SPIM_SEQ_INIT_CONF_REGISTER,
   CJ135_SPIM_SEQ_READ_CONF_REGISTER,
   CJ135_SPIM_SEQ_UPDATE_CONF_REGISTER,
   CJ135_SPIM_SEQ_WRITE_MODE,
   CJ135_SPIM_SEQ_READ_MODES,
   CJ135_SPIM_SEQ_READ_RICHNESS_TEMP,
   CJ135_SPIM_SEQ_READ_TEMP,
   CJ135_SPIM_SEQ_READ_DIAGNOSTIC,
   CJ135_SPIM_SEQ_READ_COMPENSATION,

   /* /!\ Don't change nor move following defines */
   CJ135_SPIM_SEQ_WAITING_STATE  /* Nothing to do, must be the last enum value */
} CJ135_tenuSpiMSequences;


/**********************************************************************************************************************/
/* Status of registers                                                                                                */
/**********************************************************************************************************************/
typedef enum
{
   CJ135_REGISTER_INIT_NOT_DONE,
   CJ135_REGISTER_INIT_RUNNING,
   CJ135_REGISTER_INIT_DONE,
   CJ135_REGISTER_INIT_FAIL
} CJ135_tenuSpiM_RegisterState;


/* This define is used for arrays size, computed from the last value of the enum  */
#define CJ135_SPIM_SEQ_NB_OF_CMD (CJ135_SPIM_SEQ_WAITING_STATE)

/**********************************************************************************************************************/
/* SpiM State machine to Initialize all CJ135 configuration registers                                                 */
/**********************************************************************************************************************/
typedef enum
{
   CJ135_SPIM_SEQ_INIT_CONF_REG_IPOFF_HB = 1,
   CJ135_SPIM_SEQ_INIT_CONF_REG_IPOFF_LB,
   CJ135_SPIM_SEQ_INIT_CONF_REG_IPOFF_ADDR,
   CJ135_SPIM_SEQ_INIT_CONF_REG_IPOFF_DUMMY,

   CJ135_SPIM_SEQ_INIT_CONF_REG_REFPAT_HB,
   CJ135_SPIM_SEQ_INIT_CONF_REG_REFPAT_LB,
   CJ135_SPIM_SEQ_INIT_CONF_REG_REFPAT_ADDR,
   CJ135_SPIM_SEQ_INIT_CONF_REG_REFPAT_DUMMY,

   CJ135_SPIM_SEQ_INIT_CONF_REG_STEERPAT_HB,
   CJ135_SPIM_SEQ_INIT_CONF_REG_STEERPAT_LB,
   CJ135_SPIM_SEQ_INIT_CONF_REG_STEERPAT_ADDR,
   CJ135_SPIM_SEQ_INIT_CONF_REG_STEERPAT_DUMMY,

   CJ135_SPIM_SEQ_INIT_CONF_REG_TRIM_HB,
   CJ135_SPIM_SEQ_INIT_CONF_REG_TRIM_LB,
   CJ135_SPIM_SEQ_INIT_CONF_REG_TRIM_ADDR,
   CJ135_SPIM_SEQ_INIT_CONF_REG_TRIM_DUMMY,

   CJ135_SPIM_SEQ_INIT_CONF_REG_UNSET_HB,
   CJ135_SPIM_SEQ_INIT_CONF_REG_UNSET_LB,
   CJ135_SPIM_SEQ_INIT_CONF_REG_UNSET_ADDR,
   CJ135_SPIM_SEQ_INIT_CONF_REG_UNSET_DUMMY,

   CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO0_HB,
   CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO0_LB,
   CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO0_ADDR,
   CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO0_DUMMY,

   CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO1_HB,
   CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO1_LB,
   CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO1_ADDR,
   CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO1_DUMMY,

   CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO2_HB,
   CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO2_LB,
   CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO2_ADDR,
   CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO2_DUMMY,

   CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO3_HB,
   CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO3_LB,
   CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO3_ADDR,
   CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO3_DUMMY,

   CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO4_HB,
   CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO4_LB,
   CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO4_ADDR,
   CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO4_DUMMY,

   CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO5_HB,
   CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO5_LB,
   CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO5_ADDR,
   CJ135_SPIM_SEQ_INIT_CONF_REG_UEGO5_DUMMY,

   CJ135_SPIM_SEQ_INIT_CONF_REG_UP0LEAN_HB,
   CJ135_SPIM_SEQ_INIT_CONF_REG_UP0LEAN_LB,
   CJ135_SPIM_SEQ_INIT_CONF_REG_UP0LEAN_ADDR,
   CJ135_SPIM_SEQ_INIT_CONF_REG_UP0LEAN_DUMMY,

   CJ135_SPIM_SEQ_INIT_CONF_REG_UP0RICH_HB,
   CJ135_SPIM_SEQ_INIT_CONF_REG_UP0RICH_LB,
   CJ135_SPIM_SEQ_INIT_CONF_REG_UP0RICH_ADDR,
   CJ135_SPIM_SEQ_INIT_CONF_REG_UP0RICH_DUMMY,

   CJ135_SPIM_SEQ_INIT_CONF_REG_FREE_HB,
   CJ135_SPIM_SEQ_INIT_CONF_REG_FREE_LB,
   CJ135_SPIM_SEQ_INIT_CONF_REG_FREE_ADDR,
   CJ135_SPIM_SEQ_INIT_CONF_REG_FREE_DUMMY,

   CJ135_SPIM_SEQ_INIT_CONF_REG_CONFIGDSP_HB,
   CJ135_SPIM_SEQ_INIT_CONF_REG_CONFIGDSP_LB,
   CJ135_SPIM_SEQ_INIT_CONF_REG_CONFIGDSP_ADDR,
   CJ135_SPIM_SEQ_INIT_CONF_REG_CONFIGDSP_DUMMY,

   CJ135_SPIM_SEQ_INIT_CONF_REG_MODE_HB,
   CJ135_SPIM_SEQ_INIT_CONF_REG_MODE_LB,
   CJ135_SPIM_SEQ_INIT_CONF_REG_MODE_ADDR,
   CJ135_SPIM_SEQ_INIT_CONF_REG_MODE_DUMMY,

   /* shall be the last one, because it is used to start the next state machine enum values */
   CJ135_SPIM_SEQ_INIT_CONF_REG_WAITING_STATE
} CJ135_tenuSpiM_InitConfRegSM;


/**********************************************************************************************************************/
/* SpiM State machine to read all CJ135 configuration registers                                                       */
/**********************************************************************************************************************/
typedef enum
{
   CJ135_SPIM_SEQ_READ_CONF_REG_CONFIGDSP = CJ135_SPIM_SEQ_INIT_CONF_REG_WAITING_STATE + 1,
   CJ135_SPIM_SEQ_READ_CONF_REG_IPOFF,
   CJ135_SPIM_SEQ_READ_CONF_REG_MODE,
   CJ135_SPIM_SEQ_READ_CONF_REG_REFPAT,
   CJ135_SPIM_SEQ_READ_CONF_REG_STEERPAT,
   CJ135_SPIM_SEQ_READ_CONF_REG_TRIM,
   CJ135_SPIM_SEQ_READ_CONF_REG_UNSET,
   CJ135_SPIM_SEQ_READ_CONF_REG_UEGO0,
   CJ135_SPIM_SEQ_READ_CONF_REG_UEGO1,
   CJ135_SPIM_SEQ_READ_CONF_REG_UEGO2,
   CJ135_SPIM_SEQ_READ_CONF_REG_UEGO3,
   CJ135_SPIM_SEQ_READ_CONF_REG_UEGO4,
   CJ135_SPIM_SEQ_READ_CONF_REG_UEGO5,
   CJ135_SPIM_SEQ_READ_CONF_REG_UP0LEAN,
   CJ135_SPIM_SEQ_READ_CONF_REG_UP0RICH,
   CJ135_SPIM_SEQ_READ_CONF_REG_FREE,
   CJ135_SPIM_SEQ_READ_CONF_REG_DUMMY,

   /* shall be the last one, because it is used to start the next state machine enum values */
   CJ135_SPIM_SEQ_INIT_READ_REG_WAITING_STATE
} CJ135_tenuSpiM_ReadConfRegSM;


/**********************************************************************************************************************/
/* SpiM State machine to update the CJ135 configuration registers (to update reference or pump current)               */
/**********************************************************************************************************************/
typedef enum
{
   CJ135_SPIM_SEQ_UPDATE_CONF_REG_REFPAT_HB = CJ135_SPIM_SEQ_INIT_READ_REG_WAITING_STATE + 1,
   CJ135_SPIM_SEQ_UPDATE_CONF_REG_REFPAT_LB,
   CJ135_SPIM_SEQ_UPDATE_CONF_REG_REFPAT_ADDR,
   CJ135_SPIM_SEQ_UPDATE_CONF_REG_TRIM_HB,
   CJ135_SPIM_SEQ_UPDATE_CONF_REG_TRIM_LB,
   CJ135_SPIM_SEQ_UPDATE_CONF_REG_TRIM_ADDR,
   CJ135_SPIM_SEQ_UPDATE_CONF_REG_CONFIGDSP_HB,
   CJ135_SPIM_SEQ_UPDATE_CONF_REG_CONFIGDSP_LB,
   CJ135_SPIM_SEQ_UPDATE_CONF_REG_CONFIGDSP_ADDR,
   CJ135_SPIM_SEQ_UPDATE_CONF_REG_CONFIGDSP_DUMMY,

   /* shall be the last one, because it is used to start the next state machine enum values */
   CJ135_SPIM_SEQ_UPDATE_CONF_REG_WAITING_STATE
} CJ135_tenuSpiM_UpdateConfRegSM;


/**********************************************************************************************************************/
/* SpiM State machine to write mode register                                                                          */
/**********************************************************************************************************************/
typedef enum
{
   CJ135_SPIM_SEQ_WRITE_MODE_MODE_HB = CJ135_SPIM_SEQ_UPDATE_CONF_REG_WAITING_STATE + 1,
   CJ135_SPIM_SEQ_WRITE_MODE_MODE_LB,
   CJ135_SPIM_SEQ_WRITE_MODE_MODE_ADDR,
   CJ135_SPIM_SEQ_WRITE_MODE_MODE_DUMMY,

   /* shall be the last one, because it is used to start the next state machine enum values */
   CJ135_SPIM_SEQ_WRITE_MODE_WAITING_STATE
} CJ135_tenuSpiM_WriteModeSM;

/**********************************************************************************************************************/
/* SpiM State machine to read modes (register ACTUAL mode and mode in RAM)                                            */
/**********************************************************************************************************************/
typedef enum
{
   CJ135_SPIM_SEQ_READ_MODES_ACTUAL_MODE = CJ135_SPIM_SEQ_WRITE_MODE_WAITING_STATE + 1,
   CJ135_SPIM_SEQ_READ_MODES_RAM_MODE,
   CJ135_SPIM_SEQ_READ_MODES_RAM_MODE_DUMMY,

   /* shall be the last one, because it is used to start the next state machine enum values */
   CJ135_SPIM_SEQ_READ_MODES_WAITING_STATE
} CJ135_tenuSpiM_ReadModesSM;

/**********************************************************************************************************************/
/* SpiM State machine to recover richness and temperature                                                             */
/**********************************************************************************************************************/
typedef enum
{
   CJ135_SPIM_SEQ_READ_RICH_TEMP_RAM_IP1 = CJ135_SPIM_SEQ_READ_MODES_WAITING_STATE + 1,
   CJ135_SPIM_SEQ_READ_RICH_TEMP_RAM_URIE,
   CJ135_SPIM_SEQ_READ_RICH_TEMP_RAM_IP2,
   CJ135_SPIM_SEQ_READ_RICH_TEMP_RAM_UGO,
   CJ135_SPIM_SEQ_READ_RICH_TEMP_RAM_UN0,
   CJ135_SPIM_SEQ_READ_RICH_TEMP_RAM_IP3,
   CJ135_SPIM_SEQ_READ_RICH_TEMP_RAM_IP4,
   CJ135_SPIM_SEQ_READ_RICH_TEMP_RAM_UCAL,
   CJ135_SPIM_SEQ_READ_RICH_TEMP_RAM_IP5,
   CJ135_SPIM_SEQ_READ_RICH_TEMP_DUMMY,

   /* shall be the last one, because it is used to start the next state machine enum values */
   CJ135_SPIM_SEQ_READ_RICH_TEMP_WAITING_STATE
} CJ135_tenuSpiM_ReadRichTempSM;

/**********************************************************************************************************************/
/* SpiM State machine to recover temperature (only in WARMUP mode)                                                    */
/**********************************************************************************************************************/
typedef enum
{
   CJ135_SPIM_SEQ_READ_TEMP_RAM_URIE = CJ135_SPIM_SEQ_READ_RICH_TEMP_WAITING_STATE + 1,
   CJ135_SPIM_SEQ_READ_TEMP_RAM_UN0,
   CJ135_SPIM_SEQ_READ_TEMP_RAM_UCAL,
   CJ135_SPIM_SEQ_READ_TEMP_RAM_DUMMY,

   /* shall be the last one, because it is used to start the next state machine enum values */
   CJ135_SPIM_SEQ_READ_TEMP_WAITING_STATE
} CJ135_tenuSpiM_ReadTempSM;

/**********************************************************************************************************************/
/* SpiM State machine to recover diagnostic                                                                           */
/**********************************************************************************************************************/
typedef enum
{
   CJ135_SPIM_SEQ_READ_DIAGNOSTIC_DIAG0 = CJ135_SPIM_SEQ_READ_TEMP_WAITING_STATE + 1,
   CJ135_SPIM_SEQ_READ_DIAGNOSTIC_DIAG1,
   CJ135_SPIM_SEQ_READ_DIAGNOSTIC_DSPSTAT,
   CJ135_SPIM_SEQ_READ_DIAGNOSTIC_CHIPSTAT,
   CJ135_SPIM_SEQ_READ_DIAGNOSTIC_DUMMY,

   /* shall be the last one, because it is used to start the next state machine enum values */
   CJ135_SPIM_SEQ_READ_DIAGNOSTIC_WAITING_STATE
} CJ135_tenuSpiM_ReadDiagnosticSM;

/**********************************************************************************************************************/
/* SpiM State machine to recover various parameters used in compensation                                              */
/**********************************************************************************************************************/
typedef enum
{
   /* TBD */

   /* shall be the last one, because it is used to start the next state machine enum values */
   CJ135_SPIM_SEQ_READ_COMPENSATION_WAITING_STATE = CJ135_SPIM_SEQ_READ_DIAGNOSTIC_WAITING_STATE + 1
} CJ135_tenuSpiM_ReadCompensationSM;



/**********************************************************************************************************************/
/* SpiM State machine merging in an union                                                                             */
/**********************************************************************************************************************/
/* as only one sequence could be run, an union could be used to handle all sequences */
/* each enum use different value, that increase the robustness in case of bug:       */
/* prevent 2 state machine run in same time                                          */
typedef union
{
   enum {CJ135_SPI_SEQ_IDLE = 0}     All;
   CJ135_tenuSpiM_InitConfRegSM      InitConfReg;
   CJ135_tenuSpiM_ReadConfRegSM      ReadConfReg;
   CJ135_tenuSpiM_UpdateConfRegSM    UpdateConfReg;
   CJ135_tenuSpiM_WriteModeSM        WriteMode;
   CJ135_tenuSpiM_ReadModesSM        ReadModes;
   CJ135_tenuSpiM_ReadRichTempSM     ReadRichTemp;
   CJ135_tenuSpiM_ReadTempSM         ReadTemp;
   CJ135_tenuSpiM_ReadDiagnosticSM   ReadDiagnostic;
   CJ135_tenuSpiM_ReadCompensationSM ReadCompensation;
} CJ135_tudtSpiM_StateMachine;


/**********************************************************************************************************************/
/* CJ135 Main state Machine                                                                                           */
/**********************************************************************************************************************/
typedef enum
{
   CJ135_STATE_RESET_OR_STARTUP = 0x0, /* CJ135 internal sequencer is in Reset or Startup mode */
   CJ135_STATE_IDLEMODE1 = 0x1,        /* CJ135 internal sequencer is in Idle Mode 1           */
   CJ135_STATE_SWITCHON = 0x2,         /* CJ135 internal sequencer is in Switch On             */
   CJ135_STATE_WARMUP = 0x5,           /* CJ135 internal sequencer is in Warm Up               */
   CJ135_STATE_NORMAL3 = 0x6,          /* CJ135 internal sequencer is in Normal 3              */
   CJ135_STATE_FAILUREMODE1 = 0x7,     /* CJ135 internal sequencer is in Failure Mode 1        */
   CJ135_STATE_HW_FAILURE = 0x8        /* CJ135 is disabled until next reset                   */

} CJ135_tenuChipState;
/* enum value are the same as corresponing value in MODE/ACTUAL_MODE                            */


/**********************************************************************************************************************/
/* Configuration Structure of a CJ135 Instance                                                                        */
/**********************************************************************************************************************/


/* Constant Data */
struct CJ135_tstrConfig_tag
{

   Spi_ChannelType            udtSpiChannelId;      /* AUTOSAR SPI Channel      */
   Spi_SequenceType           udtSpiSequenceId;     /* AUTOSAR Sequence Channel */

   /*****************************************/
   /* Data for the Diagnostic State machine */
   /*****************************************/
   DGOHAL_tudtChannel         udtDgohalActuatorChannel; /* Channel of the DGOHAL for Actuator faults */
   DGOHAL_tudtChannel         udtDgohalEcuChannel;      /* Channel of the DGOHAL for ECU faults      */

   const uint16               *pu16Rcal;  /* Calibration for Rcal resistor  */
   const uint16               *pu16Rgnds; /* Calibration for Rgnds resistor */

};

/**********************************************************************************************************************/
/* Variable data Structure of a CJ135 Instance                                                                        */
/**********************************************************************************************************************/
struct CJ135_strData_tag
{
   uint8                       u8InstanceNumber;       /* Identify the instance number of the component */

   CJ135_tudtSpiM_StateMachine udtSpiM_StateMachine;
   CJ135_tenuSpiMSequences     enuSpiM_SeqRunning;
   CJ135_tenuChipState         enuInternalSequencerState;       /* State Machine for the CJ135 */
   CJ135_tenuChipState         enuInternalRamSequencerState;    /* State Machine for the CJ135 */

   CJ135_tenuSpiM_RegisterState     enuSpiMRegisterInitialized; /* States of the CJ135 registers */

   uint16                      u16SpiLastSentCommand;        /* Last SPI comamnd sent (contain command byte and data
                                                               byte) */

   uint8                       u8SpiDiagnostic;                /* To store a low layer SPI error to report in DGOHAL*/
   uint8                       u8SpiTransmitErrorCounter;      /* Number of remaining allowed send command try (in case
                                                                 of SPI error) */

   uint8                       u8RegisterCheckCounter;   /* Number of try to do the register check */
   uint8                       u8RegisterInitCounter;   /* Number of try to do the register initialization */


   boolean                     abSpiM_SeqRequest[CJ135_SPIM_SEQ_NB_OF_CMD]; /* one bool per sequence. TRUE = sequence to
                                                                              run */
                                                                            /* the table order is same as
                                                                              CJ135_tenuSpiMSequences enums */

   boolean                     bFault;     /* VPS or VDD error detected */

   uint16                      u16ExpectedRegConfigDsp; /* expected value of register */
   uint16                      u16ExpectedRegIpOff; /* expected value of register */
   uint16                      u16ExpectedRegMode; /* expected value of register */
   uint16                      u16ExpectedRegRefpat; /* expected value of register */
   uint16                      u16ExpectedRegSteerpat; /* expected value of register */
   uint16                      u16ExpectedRegTrim; /* expected value of register */
   uint16                      u16ExpectedRegUnset; /* expected value of register */
   uint16                      u16ExpectedRegUego0; /* expected value of register */
   uint16                      u16ExpectedRegUego1; /* expected value of register */
   uint16                      u16ExpectedRegUego2; /* expected value of register */
   uint16                      u16ExpectedRegUego3; /* expected value of register */
   uint16                      u16ExpectedRegUego4; /* expected value of register */
   uint16                      u16ExpectedRegUego5; /* expected value of register */
   uint16                      u16ExpectedRegUp0lean; /* expected value of register */
   uint16                      u16ExpectedRegUp0rich; /* expected value of register */
   uint16                      u16ExpectedRegFree; /* expected value of register */
   uint16                      u16ExpectedRegActualMode; /* expected value of register */

   uint16                      u16SpiMChipRegConfigDsp; /* last read value of register */
   uint16                      u16SpiMChipRegIpOff; /* last read value of register */
   uint16                      u16SpiMChipRegMode; /* last read value of register */
   uint16                      u16SpiMChipRegRefpat; /* last read value of register */
   uint16                      u16SpiMChipRegSteerpat; /* last read value of register */
   uint16                      u16SpiMChipRegTrim; /* last read value of register */
   uint16                      u16SpiMChipRegUnset; /* last read value of register */
   uint16                      u16SpiMChipRegUego0; /* last read value of register */
   uint16                      u16SpiMChipRegUego1; /* last read value of register */
   uint16                      u16SpiMChipRegUego2; /* last read value of register */
   uint16                      u16SpiMChipRegUego3; /* last read value of register */
   uint16                      u16SpiMChipRegUego4; /* last read value of register */
   uint16                      u16SpiMChipRegUego5; /* last read value of register */
   uint16                      u16SpiMChipRegUp0lean; /* last read value of register */
   uint16                      u16SpiMChipRegUp0rich; /* last read value of register */
   uint16                      u16SpiMChipRegFree; /* last read value of register */
   uint16                      u16SpiMChipRegActualMode; /* last read value of register */

   uint16                      u16SpiMChipRegDiag0; /* last read value of register */
   uint16                      u16SpiMChipRegDiag1; /* last read value of register */
   uint16                      u16SpiMChipRegChipStat; /* last read value of register */
   uint16                      u16SpiMChipRegDspStat; /* last read value of register */

   boolean                     bSendFirstIRQ; /* boolean to manage the sending of first IRQ */
   boolean                     bWaitForIRQ; /* boolean to manage the sending of first IRQ */

   boolean                     bSchedulerStarted; /* boolean to manage the temporal aspect of CJ135 */
   boolean                     bModeRead; /* boolean to manage periodic reading of modes */

   uint16                      u16RamDataMode; /* value read in RAM */
   sint16                      s16RamIP1; /* value read in RAM */
   sint16                      s16RamUrie; /* value read in RAM */
   sint16                      s16RamIP2; /* value read in RAM */
   sint16                      s16RamUg0; /* value read in RAM */
   sint16                      s16RamUn0; /* value read in RAM */
   sint16                      s16RamIP3; /* value read in RAM */
   sint16                      s16RamIP4; /* value read in RAM */
   sint16                      s16RamUcal; /* value read in RAM */
   sint16                      s16RamIP5; /* value read in RAM */

   sint16                      s16Mean5IP; /* value used for calculation */

   sint16                      s16Ipeff; /* calculated value, richness information */
   uint16                      u16Rie; /* calculated value, Rie in normal3 with LN=1 */
   uint16                      u16RieWU; /* calculated value, Rie in normal3 with LN=0 or warm up */

};

#endif /* CJ135_TYPES_H */

/*------------------------------------------------- END OF FILE ------------------------------------------------------*/
