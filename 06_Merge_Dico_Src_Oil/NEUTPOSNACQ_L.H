/***************************************************************************
;**
;** FILE NAME      : NEUTPOSNACQ_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef NEUTPOSNACQ_L_H
#define NEUTPOSNACQ_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  NEUTPOSNACQ_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Ext_bDgoORng_bNeut;
extern boolean Ext_bDgoScg_bNeut;
extern boolean Ext_bDgoScp_bNeut;
extern boolean Ext_bMonRunORng_bNeut;
extern boolean Ext_bMonRunScg_bNeut;
extern boolean Ext_bMonRunScp_bNeut;
extern boolean Ext_bNeutNom;
extern boolean NEUTPOSNACQ_bFilSig_1;
extern boolean NEUTPOSNACQ_bFilSig_2;
extern boolean NEUTPOSNACQ_bFilSig_3;
extern boolean NEUTPOSNACQ_bORng_bNeut;
extern boolean NEUTPOSNACQ_bScg_bNeut;
extern boolean NEUTPOSNACQ_bScp_bNeut;
extern uint8 NeutPosnAcq_ctDftSftyORng_bNeut;
extern uint8 NeutPosnAcq_ctDftSftyScg_bNeut;
extern uint8 NeutPosnAcq_ctDftSftyScp_bNeut;
extern uint8 NEUTPOSNACQ_u8CntFilt_1;
extern uint8 NEUTPOSNACQ_u8CntFilt_2;
extern uint8 NEUTPOSNACQ_u8CntFilt_3;
extern uint16 Ext_PerNeut;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void NEUTPOSNACQ_vidbDgoORngCalcn(void);
void NEUTPOSNACQ_vidbDgoScgCalcn(void);
void NEUTPOSNACQ_vidbDgoScpCalcn(void);
void NEUTPOSNACQ_vidBneutNom(void);
void NEUTPOSNACQ_vidInitialization(void);
void NEUTPOSNACQ_vidInitOutput(void);
void NEUTPOSNACQ_vidNeutPosnAcq(void);
void NEUTPOSNACQ_vidNeutPosnDiag(void);
void NEUTPOSNACQ_vidNeutPosnTreat(void);
void NEUTPOSNACQ_vidOS(void);
void NEUTPOSNACQ_vidSafetyLevel2(void);


#endif /* NEUTPOSNACQ_L_H */

/*-------------------------------- end of file -------------------------------*/
