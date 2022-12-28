/**********************************************************************************************************************/
/* !Layer           : HAL                                                                                             */
/* !Component       : L9781                                                                                           */
/* !Description     : L9781 ASIC Abstraction Layer                                                                    */
/*                                                                                                                    */
/* !File            : L9781_CFG_I.c                                                                                   */
/* !Description     : Configuration of the L9781 Component                                                            */
/*                                                                                                                    */
/* !Reference       :                                                                                                 */
/*                                                                                                                    */
/* Coding language  : C                                                                                               */
/*                                                                                                                    */
/* COPYRIGHT VALEO all rights reserved                                                                                */
/**********************************************************************************************************************/

#include "Std_Types.h"

#include "L9781.h"
#include "L9781_CFG_E.h"
#include "L9781_CFG_I.h"
#include "L9781_I.h"
#include "L9781_L.h"

#include "Spi.h"
#include "SWFAIL.h"

#define L9781_START_SEC_CODE
#include "L9781_MemMap.h"

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidSpiLoadGenConf                                                                             */
/* !Description : Loads the SPI buffer for General Config of considered ASIC                                          */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void L9781_vidSpiLoadGenConf
(
   uint8 u8Channel
)
{
   switch (u8Channel)
   {
     case L9781_u8ST1_CHANNEL:
        L9781_vidSPI_LOADING(ST1, GEN_CONF);
        break;

     case L9781_u8ST2_CHANNEL:
        L9781_vidSPI_LOADING(ST2, GEN_CONF);
        break;

     default:
        SWFAIL_vidSoftwareErrorHook();
        break;
    }
}

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidSpiLoadUnlock                                                                              */
/* !Description : Loads the SPI buffer to unlock the considered ASIC                                                  */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void L9781_vidSpiLoadUnlock
(
   uint8 u8Channel
)
{
   switch (u8Channel)
   {
     case L9781_u8ST1_CHANNEL:
        L9781_vidSPI_LOADING(ST1, UNLOCK);
        break;

     case L9781_u8ST2_CHANNEL:
        L9781_vidSPI_LOADING(ST2, UNLOCK);
        break;

     default:
        SWFAIL_vidSoftwareErrorHook();
        break;
    }
}

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidSpiLoadInjProf                                                                             */
/* !Description : Loads the SPI buffer for Inj Profile of considered ASIC                                             */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void L9781_vidSpiLoadInjProf
(
   uint8 u8Channel
)
{
   switch (u8Channel)
   {
     case L9781_u8ST1_CHANNEL:
        L9781_vidSPI_LOADING(ST1, INJ_PROF);
        break;

     case L9781_u8ST2_CHANNEL:
        L9781_vidSPI_LOADING(ST2, INJ_PROF);
        break;

     default:
        SWFAIL_vidSoftwareErrorHook();
        break;
    }
}

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidSpiLoadPmpProf                                                                             */
/* !Description : Loads the SPI buffer for Pmp Profile of considered ASIC                                             */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void L9781_vidSpiLoadPmpProf
(
   uint8 u8Channel
)
{
   switch (u8Channel)
   {
     case L9781_u8ST1_CHANNEL:
        L9781_vidSPI_LOADING(ST1, PMP_PROF);
        break;

     case L9781_u8ST2_CHANNEL:
        L9781_vidSPI_LOADING(ST2, PMP_PROF);
        break;

     default:
        SWFAIL_vidSoftwareErrorHook();
        break;
    }
}

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidSpiRequest                                                                                 */
/* !Description : SPI Request for Transmition on the considered ASIC                                                  */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void L9781_vidSpiRequest
(
   uint8 u8Channel
)
{
   switch (u8Channel)
   {
     case L9781_u8ST1_CHANNEL:
        L9781_vidSPI_TX(L9781_snSPI_ST1_CH, L9781_snSPI_ST1_SEQ);
        break;

     case L9781_u8ST2_CHANNEL:
        L9781_vidSPI_TX(L9781_snSPI_ST2_CH, L9781_snSPI_ST2_SEQ);
        break;

     default:
        SWFAIL_vidSoftwareErrorHook();
        break;
    }
}

/**********************************************************************************************************************/
/* !FuncName    : L9781_bReadIrqDiag                                                                                  */
/* !Description : Reads the IRQ Diag state (DIOBSL) of considered ASIC                                                */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
boolean L9781_bReadIrqDiag
(
   uint8 u8Channel
)
{
   boolean bLocalIrqDiagState;


   switch (u8Channel)
   {
     case L9781_u8ST1_CHANNEL:
        bLocalIrqDiagState = L9781_bREAD_IRQ_DIAG_STATE(ST1);
        break;

     case L9781_u8ST2_CHANNEL:
        bLocalIrqDiagState = L9781_bREAD_IRQ_DIAG_STATE(ST2);
        break;

     default:
        bLocalIrqDiagState = TRUE;
        SWFAIL_vidSoftwareErrorHook();
        break;
    }

   return(bLocalIrqDiagState);
}

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidUpdateDiag                                                                                 */
/* !Description : Updates the electrical diagnosis of considered ASIC                                                 */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void L9781_vidUpdateDiag
(
   uint8 u8Channel
)
{
   switch (u8Channel)
   {
     case L9781_u8ST1_CHANNEL:
        L9781_vidDIAGNOSIS(ST1,BANK_AX);
        L9781_vidDIAGNOSIS(ST1,BANK_BX);
        L9781_vidDIAGNOSIS(ST1,BANK_FP);
        L9781_vidDIAGNOSIS(ST1,ASIC);
        break;

     case L9781_u8ST2_CHANNEL:
        L9781_vidDIAGNOSIS(ST2,BANK_AX);
        L9781_vidDIAGNOSIS(ST2,ASIC);
        break;

     default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/**********************************************************************************************************************/
/* !FuncName    : L9781_vidClearAllDiag                                                                               */
/* !Description : Clear all fault detection of channel according to the bank driving configuration.                   */
/* !LastAuthor  : L. Baglin                                                                                           */
/**********************************************************************************************************************/
void L9781_vidClearAllDiag
(
   uint8 u8Channel
)
{
   switch (u8Channel)
   {
     case L9781_u8ST1_CHANNEL:
        L9781_vidCLEAR_DIAG(ST1,BANK_AX);
        L9781_vidCLEAR_DIAG(ST1,BANK_BX);
        L9781_vidCLEAR_DIAG(ST1,BANK_FP);
        L9781_vidCLEAR_DIAG(ST1,ASIC);
        break;

     case L9781_u8ST2_CHANNEL:
        L9781_vidCLEAR_DIAG(ST2,BANK_AX);
        L9781_vidCLEAR_DIAG(ST2,ASIC);
        break;

     default:
        SWFAIL_vidSoftwareErrorHook();
        break;
    }
}


#define L9781_STOP_SEC_CODE
#include "L9781_MemMap.h"

/**********************************************************************************************************************/
/* CONSTANT DEFINITION                                                                                                */
/**********************************************************************************************************************/
/****************/
/* uint32 Const */
/****************/
#define L9781_START_SEC_CONST_32BIT
#include "L9781_MemMap.h"


const uint32* const L9781_kapku32AbFra1Para1[L9781_u8NB_INJ_PROF_MAX] =
{
   &L9781_ku32AbFra1Para1Prof1,
   &L9781_ku32AbFra1Para1Prof2,
   &L9781_ku32AbFra1Para1Prof3,
   &L9781_ku32AbFra1Para1Prof4,
};

const uint32* const L9781_kapku32AbFra1Para2[L9781_u8NB_INJ_PROF_MAX] =
{
   &L9781_ku32AbFra1Para2Prof1,
   &L9781_ku32AbFra1Para2Prof2,
   &L9781_ku32AbFra1Para2Prof3,
   &L9781_ku32AbFra1Para2Prof4,
};

const uint32* const L9781_kapku32AbFra1Para3[L9781_u8NB_INJ_PROF_MAX] =
{
   &L9781_ku32AbFra1Para3Prof1,
   &L9781_ku32AbFra1Para3Prof2,
   &L9781_ku32AbFra1Para3Prof3,
   &L9781_ku32AbFra1Para3Prof4,
};

const uint32* const L9781_kapku32AbFra1Para4[L9781_u8NB_INJ_PROF_MAX] =
{
   &L9781_ku32AbFra1Para4Prof1,
   &L9781_ku32AbFra1Para4Prof2,
   &L9781_ku32AbFra1Para4Prof3,
   &L9781_ku32AbFra1Para4Prof4,
};

const uint32* const L9781_kapku32AbFra2Para1[L9781_u8NB_INJ_PROF_MAX] =
{
   &L9781_ku32AbFra2Para1Prof1,
   &L9781_ku32AbFra2Para1Prof2,
   &L9781_ku32AbFra2Para1Prof3,
   &L9781_ku32AbFra2Para1Prof4,
};

const uint32* const L9781_kapku32AbFra2Para2[L9781_u8NB_INJ_PROF_MAX] =
{
   &L9781_ku32AbFra2Para2Prof1,
   &L9781_ku32AbFra2Para2Prof2,
   &L9781_ku32AbFra2Para2Prof3,
   &L9781_ku32AbFra2Para2Prof4,
};

const uint32* const L9781_kapku32AbFra2Para3[L9781_u8NB_INJ_PROF_MAX] =
   {
   &L9781_ku32AbFra2Para3Prof1,
   &L9781_ku32AbFra2Para3Prof2,
   &L9781_ku32AbFra2Para3Prof3,
   &L9781_ku32AbFra2Para3Prof4,
   };

const uint32* const L9781_kapku32AbFra2Para4[L9781_u8NB_INJ_PROF_MAX] =
{
   &L9781_ku32AbFra2Para4Prof1,
   &L9781_ku32AbFra2Para4Prof2,
   &L9781_ku32AbFra2Para4Prof3,
   &L9781_ku32AbFra2Para4Prof4,
};

const uint32* const L9781_kapku32AbFra3Para1[L9781_u8NB_INJ_PROF_MAX] =
{
   &L9781_ku32AbFra3Para1Prof1,
   &L9781_ku32AbFra3Para1Prof2,
   &L9781_ku32AbFra3Para1Prof3,
   &L9781_ku32AbFra3Para1Prof4,
};

const uint32* const L9781_kapku32AbFra3Para2[L9781_u8NB_INJ_PROF_MAX] =
{
   &L9781_ku32AbFra3Para2Prof1,
   &L9781_ku32AbFra3Para2Prof2,
   &L9781_ku32AbFra3Para2Prof3,
   &L9781_ku32AbFra3Para2Prof4,
};

const uint32* const L9781_kapku32AbFra3Para3[L9781_u8NB_INJ_PROF_MAX] =
{
   &L9781_ku32AbFra3Para3Prof1,
   &L9781_ku32AbFra3Para3Prof2,
   &L9781_ku32AbFra3Para3Prof3,
   &L9781_ku32AbFra3Para3Prof4,
};
const uint32* const L9781_kapku32FpFra1Para1[L9781_u8NB_PMP_PROF_MAX] =
{
   &L9781_ku32FpFra1Para1Prof1,
   &L9781_ku32FpFra1Para1Prof2,
   &L9781_ku32FpFra1Para1Prof3,
   &L9781_ku32FpFra1Para1Prof4,
   &L9781_ku32FpFra1Para1Prof5,
   &L9781_ku32FpFra1Para1Prof6,
   &L9781_ku32FpFra1Para1Prof7,
   &L9781_ku32FpFra1Para1Prof8,
   &L9781_ku32FpFra1Para1Prof9,
   &L9781_ku32FpFra1Para1Prof10,
   &L9781_ku32FpFra1Para1Prof11,
   &L9781_ku32FpFra1Para1Prof12,
   &L9781_ku32FpFra1Para1Prof13,
   &L9781_ku32FpFra1Para1Prof14,
   &L9781_ku32FpFra1Para1Prof15,
   &L9781_ku32FpFra1Para1Prof16,
   &L9781_ku32FpFra1Para1Prof17,
   &L9781_ku32FpFra1Para1Prof18,
   &L9781_ku32FpFra1Para1Prof19,
   &L9781_ku32FpFra1Para1Prof20,
   &L9781_ku32FpFra1Para1Prof21,
   &L9781_ku32FpFra1Para1Prof22,
   &L9781_ku32FpFra1Para1Prof23,
   &L9781_ku32FpFra1Para1Prof24,
   &L9781_ku32FpFra1Para1Prof25,
   &L9781_ku32FpFra1Para1Prof26,
};

const uint32* const L9781_kapku32FpFra1Para2[L9781_u8NB_PMP_PROF_MAX] =
{
   &L9781_ku32FpFra1Para2Prof1,
   &L9781_ku32FpFra1Para2Prof2,
   &L9781_ku32FpFra1Para2Prof3,
   &L9781_ku32FpFra1Para2Prof4,
   &L9781_ku32FpFra1Para2Prof5,
   &L9781_ku32FpFra1Para2Prof6,
   &L9781_ku32FpFra1Para2Prof7,
   &L9781_ku32FpFra1Para2Prof8,
   &L9781_ku32FpFra1Para2Prof9,
   &L9781_ku32FpFra1Para2Prof10,
   &L9781_ku32FpFra1Para2Prof11,
   &L9781_ku32FpFra1Para2Prof12,
   &L9781_ku32FpFra1Para2Prof13,
   &L9781_ku32FpFra1Para2Prof14,
   &L9781_ku32FpFra1Para2Prof15,
   &L9781_ku32FpFra1Para2Prof16,
   &L9781_ku32FpFra1Para2Prof17,
   &L9781_ku32FpFra1Para2Prof18,
   &L9781_ku32FpFra1Para2Prof19,
   &L9781_ku32FpFra1Para2Prof20,
   &L9781_ku32FpFra1Para2Prof21,
   &L9781_ku32FpFra1Para2Prof22,
   &L9781_ku32FpFra1Para2Prof23,
   &L9781_ku32FpFra1Para2Prof24,
   &L9781_ku32FpFra1Para2Prof25,
   &L9781_ku32FpFra1Para2Prof26,
};

const uint32* const L9781_kapku32FpFra1Para3[L9781_u8NB_PMP_PROF_MAX] =
{
   &L9781_ku32FpFra1Para3Prof1,
   &L9781_ku32FpFra1Para3Prof2,
   &L9781_ku32FpFra1Para3Prof3,
   &L9781_ku32FpFra1Para3Prof4,
   &L9781_ku32FpFra1Para3Prof5,
   &L9781_ku32FpFra1Para3Prof6,
   &L9781_ku32FpFra1Para3Prof7,
   &L9781_ku32FpFra1Para3Prof8,
   &L9781_ku32FpFra1Para3Prof9,
   &L9781_ku32FpFra1Para3Prof10,
   &L9781_ku32FpFra1Para3Prof11,
   &L9781_ku32FpFra1Para3Prof12,
   &L9781_ku32FpFra1Para3Prof13,
   &L9781_ku32FpFra1Para3Prof14,
   &L9781_ku32FpFra1Para3Prof15,
   &L9781_ku32FpFra1Para3Prof16,
   &L9781_ku32FpFra1Para3Prof17,
   &L9781_ku32FpFra1Para3Prof18,
   &L9781_ku32FpFra1Para3Prof19,
   &L9781_ku32FpFra1Para3Prof20,
   &L9781_ku32FpFra1Para3Prof21,
   &L9781_ku32FpFra1Para3Prof22,
   &L9781_ku32FpFra1Para3Prof23,
   &L9781_ku32FpFra1Para3Prof24,
   &L9781_ku32FpFra1Para3Prof25,
   &L9781_ku32FpFra1Para3Prof26,
};

const uint32* const L9781_kapku32FpFra1Para4[L9781_u8NB_PMP_PROF_MAX] =
{
   &L9781_ku32FpFra1Para4Prof1,
   &L9781_ku32FpFra1Para4Prof2,
   &L9781_ku32FpFra1Para4Prof3,
   &L9781_ku32FpFra1Para4Prof4,
   &L9781_ku32FpFra1Para4Prof5,
   &L9781_ku32FpFra1Para4Prof6,
   &L9781_ku32FpFra1Para4Prof7,
   &L9781_ku32FpFra1Para4Prof8,
   &L9781_ku32FpFra1Para4Prof9,
   &L9781_ku32FpFra1Para4Prof10,
   &L9781_ku32FpFra1Para4Prof11,
   &L9781_ku32FpFra1Para4Prof12,
   &L9781_ku32FpFra1Para4Prof13,
   &L9781_ku32FpFra1Para4Prof14,
   &L9781_ku32FpFra1Para4Prof15,
   &L9781_ku32FpFra1Para4Prof16,
   &L9781_ku32FpFra1Para4Prof17,
   &L9781_ku32FpFra1Para4Prof18,
   &L9781_ku32FpFra1Para4Prof19,
   &L9781_ku32FpFra1Para4Prof20,
   &L9781_ku32FpFra1Para4Prof21,
   &L9781_ku32FpFra1Para4Prof22,
   &L9781_ku32FpFra1Para4Prof23,
   &L9781_ku32FpFra1Para4Prof24,
   &L9781_ku32FpFra1Para4Prof25,
   &L9781_ku32FpFra1Para4Prof26,
};

const uint32* const L9781_kapku32FpFra2Para1[L9781_u8NB_PMP_PROF_MAX] =
{
   &L9781_ku32FpFra2Para1Prof1,
   &L9781_ku32FpFra2Para1Prof2,
   &L9781_ku32FpFra2Para1Prof3,
   &L9781_ku32FpFra2Para1Prof4,
   &L9781_ku32FpFra2Para1Prof5,
   &L9781_ku32FpFra2Para1Prof6,
   &L9781_ku32FpFra2Para1Prof7,
   &L9781_ku32FpFra2Para1Prof8,
   &L9781_ku32FpFra2Para1Prof9,
   &L9781_ku32FpFra2Para1Prof10,
   &L9781_ku32FpFra2Para1Prof11,
   &L9781_ku32FpFra2Para1Prof12,
   &L9781_ku32FpFra2Para1Prof13,
   &L9781_ku32FpFra2Para1Prof14,
   &L9781_ku32FpFra2Para1Prof15,
   &L9781_ku32FpFra2Para1Prof16,
   &L9781_ku32FpFra2Para1Prof17,
   &L9781_ku32FpFra2Para1Prof18,
   &L9781_ku32FpFra2Para1Prof19,
   &L9781_ku32FpFra2Para1Prof20,
   &L9781_ku32FpFra2Para1Prof21,
   &L9781_ku32FpFra2Para1Prof22,
   &L9781_ku32FpFra2Para1Prof23,
   &L9781_ku32FpFra2Para1Prof24,
   &L9781_ku32FpFra2Para1Prof25,
   &L9781_ku32FpFra2Para1Prof26,
};

const uint32* const L9781_kapku32FpFra2Para2[L9781_u8NB_PMP_PROF_MAX] =
{
   &L9781_ku32FpFra2Para2Prof1,
   &L9781_ku32FpFra2Para2Prof2,
   &L9781_ku32FpFra2Para2Prof3,
   &L9781_ku32FpFra2Para2Prof4,
   &L9781_ku32FpFra2Para2Prof5,
   &L9781_ku32FpFra2Para2Prof6,
   &L9781_ku32FpFra2Para2Prof7,
   &L9781_ku32FpFra2Para2Prof8,
   &L9781_ku32FpFra2Para2Prof9,
   &L9781_ku32FpFra2Para2Prof10,
   &L9781_ku32FpFra2Para2Prof11,
   &L9781_ku32FpFra2Para2Prof12,
   &L9781_ku32FpFra2Para2Prof13,
   &L9781_ku32FpFra2Para2Prof14,
   &L9781_ku32FpFra2Para2Prof15,
   &L9781_ku32FpFra2Para2Prof16,
   &L9781_ku32FpFra2Para2Prof17,
   &L9781_ku32FpFra2Para2Prof18,
   &L9781_ku32FpFra2Para2Prof19,
   &L9781_ku32FpFra2Para2Prof20,
   &L9781_ku32FpFra2Para2Prof21,
   &L9781_ku32FpFra2Para2Prof22,
   &L9781_ku32FpFra2Para2Prof23,
   &L9781_ku32FpFra2Para2Prof24,
   &L9781_ku32FpFra2Para2Prof25,
   &L9781_ku32FpFra2Para2Prof26,
};


const uint32* const L9781_kapku32FpFra2Para3[L9781_u8NB_PMP_PROF_MAX] =
{
   &L9781_ku32FpFra2Para3Prof1,
   &L9781_ku32FpFra2Para3Prof2,
   &L9781_ku32FpFra2Para3Prof3,
   &L9781_ku32FpFra2Para3Prof4,
   &L9781_ku32FpFra2Para3Prof5,
   &L9781_ku32FpFra2Para3Prof6,
   &L9781_ku32FpFra2Para3Prof7,
   &L9781_ku32FpFra2Para3Prof8,
   &L9781_ku32FpFra2Para3Prof9,
   &L9781_ku32FpFra2Para3Prof10,
   &L9781_ku32FpFra2Para3Prof11,
   &L9781_ku32FpFra2Para3Prof12,
   &L9781_ku32FpFra2Para3Prof13,
   &L9781_ku32FpFra2Para3Prof14,
   &L9781_ku32FpFra2Para3Prof15,
   &L9781_ku32FpFra2Para3Prof16,
   &L9781_ku32FpFra2Para3Prof17,
   &L9781_ku32FpFra2Para3Prof18,
   &L9781_ku32FpFra2Para3Prof19,
   &L9781_ku32FpFra2Para3Prof20,
   &L9781_ku32FpFra2Para3Prof21,
   &L9781_ku32FpFra2Para3Prof22,
   &L9781_ku32FpFra2Para3Prof23,
   &L9781_ku32FpFra2Para3Prof24,
   &L9781_ku32FpFra2Para3Prof25,
   &L9781_ku32FpFra2Para3Prof26,
};

#define L9781_STOP_SEC_CONST_32BIT
#include "L9781_MemMap.h"


/**********************************************************************************************************************/
/* DATA DECLARATION                                                                                                   */
/**********************************************************************************************************************/
/*********************/
/* boolean Variables */
/*********************/
#define L9781_START_SEC_VAR_CLEARED_BOOLEAN
#include "L9781_MemMap.h"

boolean L9781_abFirstDiagRead[L9781_u8NB_ASIC];
boolean L9781_abBankLock[L9781_u8NB_BANK];

#define L9781_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "L9781_MemMap.h"


/*******************/
/* uint8 Variables */
/*******************/
#define L9781_START_SEC_VAR_CLEARED_8BIT
#include "L9781_MemMap.h"

uint8 L9781_au8UnlockTimeOut[L9781_u8NB_BANK][L9781_u8NB_ASIC];
uint8 L9781_au8PmpProfile[L9781_u8NB_ASIC];
uint8 L9781_au8InjProfile[L9781_u8NB_ASIC];

#define L9781_STOP_SEC_VAR_CLEARED_8BIT
#include "L9781_MemMap.h"


/********************/
/* uint16 Variables */
/********************/
#define L9781_START_SEC_VAR_CLEARED_16BIT
#include "L9781_MemMap.h"

uint16 L9781_au16FailureCounter[L9781_u8NB_BANK][L9781_u8NB_ASIC];

#define L9781_STOP_SEC_VAR_CLEARED_16BIT
#include "L9781_MemMap.h"


/********************/
/* uint32 Variables */
/********************/
#define L9781_START_SEC_VAR_CLEARED_32BIT
#include "L9781_MemMap.h"

uint32 L9781_au32DiagFpFrame[L9781_u8NB_ASIC];
uint32 L9781_au32IcStatusFrame[L9781_u8NB_ASIC];
uint32 L9781_au32DiagBankAFrame[L9781_u8NB_ASIC];
uint32 L9781_au32DiagBankBFrame[L9781_u8NB_ASIC];
uint32 L9781_au32BankToUnlock[L9781_u8NB_ASIC];
uint32 L9781_au32InjProfBkpBuffSt1[L9781_u8NB_FRAME_INJ_PROF];
uint32 L9781_au32PmpProfBkpBuffSt1[L9781_u8NB_FRAME_PMP_PROF];
uint32 L9781_au32InjProfBkpBuffSt2[L9781_u8NB_FRAME_INJ_PROF];
uint32 L9781_au32PmpProfBkpBuffSt2[L9781_u8NB_FRAME_PMP_PROF];

#define L9781_STOP_SEC_VAR_CLEARED_32BIT
#include "L9781_MemMap.h"

/*--------------------------------------------------- END OF FILE ----------------------------------------------------*/
