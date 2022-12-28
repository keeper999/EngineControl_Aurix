/***************************************************************************
;**
;** FILE NAME      : IGCMDMISFGENR_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IGCMDMISFGENR_L_H
#define IGCMDMISFGENR_L_H

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

extern const uint8  IGCMDMISFGENR_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean Autorisation_misfire_confirmee;
extern boolean IgCmd_bEngPha;
extern boolean IGCMDMISFGENR_bAutorisMisfirPrev;
extern boolean IGCMDMISFGENR_bInhibMisfirePrev;
extern boolean IGCMDMISFGENR_bLocalRst_Prev;
extern boolean IGCMDMISFGENR_bLocalRst2_Prev;
extern boolean IGCMDMISFGENR_bLocalRstPrev_Prev;
extern boolean Misfire_al;
extern uint8 Misfire_cylindre_al;
extern uint8 Misfire_cylindre_det;
extern uint8 Msm_spark_counter;
extern uint16 Cnt_global;
extern uint16 Cnt_misfire;
extern uint16 IgCmd_MisfGenrTimer;
extern uint16 IGCMDMISFGENR_u16TauxmisfirePrev;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void IGCMDMISFGENR_vidAutorisMisfConf(void);
void IGCMDMISFGENR_vidCylSelection(void);
void IGCMDMISFGENR_vidDeterministMode(void);
void IGCMDMISFGENR_vidInhibMisfConf(void);
void IGCMDMISFGENR_vidInit(void);
void IGCMDMISFGENR_vidInitcompteurs(void);
void IGCMDMISFGENR_vidInitOutput(void);
void IGCMDMISFGENR_vidManageMisfCoils(void);
void IGCMDMISFGENR_vidMisfireCylinder(void);
void IGCMDMISFGENR_vidMisfireGenStop(void);
void IGCMDMISFGENR_vidMisfireRatio(void);
void IGCMDMISFGENR_vidNotReachedRecur(void);
void IGCMDMISFGENR_vidRandomMode(void);
void IGCMDMISFGENR_vidRazMsmSparkCnt(void);
void IGCMDMISFGENR_vidReachedRecur(void);
void IGCMDMISFGENR_vidTauxmisfirereel(void);


#endif /* IGCMDMISFGENR_L_H */

/*-------------------------------- end of file -------------------------------*/
