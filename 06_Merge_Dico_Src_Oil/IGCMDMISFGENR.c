/***************************************************************************
;**
;** FILE NAME      : IGCMDMISFGENR.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "IGCMDMISFGENR.H"
#include "IGCMDMISFGENR_L.H"
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
const boolean  Autorisation_misfire = 0;
const boolean  Mode_deterministe = 0;
const boolean  Mode_successif = 0;
const uint8  IGCMDMISFGENR_u8Inhib = 0;
const uint8  Msm_coupure_cylindre = 0;
const uint8  Recurrence_misfire_deterministe = 0;
const uint16  Taux_misfire_aleatoire = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean Autorisation_misfire_confirmee;
boolean IgCmd_bEngPha;
boolean IGCMDMISFGENR_bAutorisMisfirPrev;
boolean IGCMDMISFGENR_bInhibMisfirePrev;
boolean IGCMDMISFGENR_bLocalRst_Prev;
boolean IGCMDMISFGENR_bLocalRst2_Prev;
boolean IGCMDMISFGENR_bLocalRstPrev_Prev;
boolean Misfire_al;
uint8 Misfire_cylindre;
uint8 Misfire_cylindre_al;
uint8 Misfire_cylindre_det;
uint8 Msm_spark_counter;
uint16 Cnt_global;
uint16 Cnt_misfire;
uint16 IgCmd_MisfGenrTimer;
uint16 IGCMDMISFGENR_u16TauxmisfirePrev;
uint16 Taux_aleatoire;
uint16 Taux_deterministe;
uint16 Taux_misfire;
uint16 Taux_misfire_reel;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

