/***************************************************************************
;**
;** FILE NAME      : ENGSTOUTPIDC.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ENGSTOUTPIDC_H
#define ENGSTOUTPIDC_H

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

extern const boolean  Config_info_moteur_tournant;
extern const boolean  Eng_st_output_for_test_bed;
extern const boolean  Eng_st_output_test_bed_mode;
extern const boolean  EngSt_bIniEngRun_Archi2010_C;
extern const boolean  EngSt_bIniEngRun_NotArchi2010_C;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean CoPTStHw_bEngRunSTT;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void EngSt_EveRst_EngStOutIdc(void);
void EngSt_SdlFast_EngStOutIdc(void);


#endif /* ENGSTOUTPIDC_H */

/*-------------------------------- end of file -------------------------------*/
