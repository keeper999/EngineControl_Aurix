
/***************************************************************************
;**
;** FILE NAME      : GD_A.H
;**
;** FILE AUTHOR    : lthibaud (VEMS)
;**
;**************************************************************************/

#ifndef GD_A_H
#define GD_A_H

#include "STD_Types.h"
#include "gdfrm.h"


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/
/* --- DETECTION CLASS FOR DEFAUT --- */
typedef struct 
{
   uint8 u8ClasFrfParam1;
   uint8 u8ClasFrfParam2;
   uint8 u8ClasFrfParam3;
   uint8 u8ClasFrfParam4;
   uint8 u8ClasFrfParam5;
   uint8 u8ClasFrfParam6;
   uint8 u8ClasFrfParam7;
   uint8 u8ClasFrfParam8;
   uint8 u8ClasFrfParam9;
}GD_tstrClasFrf;

/* struct GD_tstrFrf
{
   uint16 u16ClasFrf1;
   uint16 u16ClasFrf2;
   uint16 u16ClasFrf3;
   uint16 u16ClasFrf4;
   uint16 u16ClasFrf5;
   uint16 u16ClasFrf6;
   uint16 u16ClasFrf7;
   uint16 u16ClasFrf8;
   uint16 u16ClasFrf9;
}; */

typedef struct 
{
   uint8    u8GduGobdManagement;
   /*0 => bPresDC;      Indicate that the GDU manager go through the state    */
   /*   PRESENT on a "DC Applique".                                           */
   /*1 => bNCfDC;       Indicate that the Drinving Cycle meter has reached    */
   /*   its threshold.                                                        */
   /*2 => bAuthoDiagClr;Diagnosis authorization since the last erasure (Eep)  */
   /*3 => bEndDiagClr;  Information achievement of a full diagnosis  since the*/
   /*   last Erasure (Eep)                                                    */
   /*4 => bStPres;      Param which indicate the passage of the GDU manager   */
   /*   in the state PRESENT                                                  */
   
   uint8    u8ctErrorClr;        /* entry's meter in state PCTL_PRESENT, (Eep)*/
   GDFRM_tenuGDUState enuStDgo;  /* State of GDU Manager EEPROM               */
}GD_tstrDftEep;

typedef struct  
{
   boolean  bEndDiagStrt;     /* Information achievement of a full diagnosis  */
                              /* since KEY ON                                 */
   uint8    u8ctInt;          /* Intermittent default meter                   */
   sint16   s16ctDet;         /* Detection meter for default                  */
}GDU_tstrDft;


typedef struct 
{
   boolean bEnaSaveFrfClasDet;/* Table that defines if DTC and Freeze Frames are 
                                 saved or not */
   boolean bRstCntClasDet;    /* Table that defines if the fault detection 
                                 counter is initialised when the diagnostic’s 
                                 status is GD_INIT. */
   boolean bUpDownClasDet;    /* Table that defines if the fault detection 
                                 counter is initialised before it decrements. */
   boolean bLockDftClasDet;   /* Table that defines if the failure is 
                                 disconfirmed when the fault detection counter 
                                 reach its minimum threshold or by a Key ON 
                                 event. */
   boolean bReIniStKeyOnClasDet;  
                              /* Table that defines if the failure global state
                               GDU_PRESENT is saved at the powerlatch or not. */
}GD_strClasDet;

/* --- CLASS OBD --- */
typedef struct 
{
   boolean  bEnaSctl;            /* Choice to indicate or not the default code*/
                                 /* at the scantools.                         */
   boolean  bEnaMIL;             /* choice for switching on the MIL           */
   uint8    u8NoNCfDC;           /* number of consecutive DC necessary to     */
                                 /* confirm the default (sence OBD).          */
   uint8    u8NoHealDC;          /* number of consecutive DC necessary to     */
                                 /* unconfirm the default (OBD).              */
                                 /* Readness code family associate            */
}GD_strClasObd;

/* --- EEPROM DFT SLOT --- */
typedef struct 
{
   uint16 u16CtDiagClr;    /* Input counter in Diag mode since last clearing  */
                           /*   (APV Tool)                                    */

   uint8 u8GduEnuStDgo;    /* GDU State                                       */
   uint8 u8CptErrorClr;    /* Number Input in PCTL_PRESENT State since last   */
                           /*   clearing (APV Tool)                           */
   uint8 u8GobdEnuStDgo;   /* GOBD State                                      */        
   uint8 u8CtWuc;          /* WUC Remaining Counter                           */
   uint8 u8RnkStPrs;       /* Default Rank Appearence                         */
   uint8 u8RnkStUnval;     /* Default Rank Disappearance                      */
   uint8 u8RnkFrf;         /* Mode 02 Frf snapshot number                     */
   uint8 u8GobdCtDC;       /* GOBD applied DC counter                         */
   uint8 u8RdyCtDC;        /* Readiness Code DC counter                       */
   
	uint8 u8BitField;  
/* Bit0: Indicateur de défaut présent sur le DC en cours                      */
/* Bit1: Indicateur compteur de DC a atteint le seuil NS_noNCfDCTypCc_NameVar */
/* Bit2: Information d'autorisation du diagnostic depuis le dernier effacement*/
/*       envoyé à l'outil APV                                                 */
/* Bit3: Information de réalisation d'un diagnostic entier depuis le dernier  */
/*       effacement envoyé à l'outil APV                                      */
/* Bit4: Indicateur défaut déjà confirmé auparavant                           */
/* Bit5: Readiness Code unitaire                                              */
/* Bit6: Indicateur de défaut apparu sur le 1er DC                            */
/* Bit7: Driving Cycle Applied                                                */
}GD_tstrSaveDftEep;

/* --- CLASS DID --- */
typedef struct 
{
   uint16  u16ClasDid1;
   uint16  u16ClasDid2;
   uint16  u16ClasDid3;
   uint16  u16ClasDid4;
   uint16  u16ClasDid5;
   uint16  u16ClasDid6;
   uint16  u16ClasDid7;
   uint16  u16ClasDid8;
   uint16  u16ClasDid9;
}GD_strClasDID;

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/



#endif /* GD_A_H */

/*-------------------------------- end of file -------------------------------*/
