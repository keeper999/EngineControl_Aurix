/***************************************************************************
;**
;** FILE NAME      : ENGSTOUTPIDC.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ENGSTOUTPIDC.H"
#include "ENGSTOUTPIDC_L.H"
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
const boolean  Config_info_moteur_tournant = 0;
const boolean  Eng_st_output_for_test_bed = 0;
const boolean  Eng_st_output_test_bed_mode = 0;
const boolean  EngSt_bIniEngRun_Archi2010_C = 0;
const boolean  EngSt_bIniEngRun_NotArchi2010_C = 0;
const uint8  ENGSTOUTPIDC_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean CoPTStHw_bEngRunSTT;
boolean Ext_bDgoOc_EngStOutIdc;
boolean Ext_bDgoScg_EngStOutIdc;
boolean Ext_bDgoScp_EngStOutIdc;
boolean Ext_bMonRunOc_EngStOutIdc;
boolean Ext_bMonRunScg_EngStOutIdc;
boolean Ext_bMonRunScp_EngStOutIdc;
boolean Info_moteur_tournant;
boolean Info_moteur_tournant_applique;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

