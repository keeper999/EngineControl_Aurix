/***************************************************************************
;**
;** FILE NAME      : ADDONAGCOR.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "ADDONAGCOR.H"
#include "ADDONAGCOR_L.H"
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
const boolean  IgSys_bFlexFacAgCor_C = 0;
const boolean  IgSys_bGasFacAgCor_C = 0;
const boolean  IgSys_bInhTarAgCor_C = 0;
const uint8  ADDONAGCOR_u8Inhib = 0;
const uint8  IgSys_idxSelTUsr_C = 0;
const uint16  IgSys_facAgCorCal1_M[IGSYS_FACAGCORCAL1_M_LNS][IGSYS_FACAGCORCAL1_M_COLS] = {0};
const uint16  IgSys_facAgCorCal2_M[IGSYS_FACAGCORCAL2_M_LNS][IGSYS_FACAGCORCAL2_M_COLS] = {0};
const uint16  IgSys_facTarAgCor2Cal1_M[IGSYS_FACTARAGCOR2CAL1_M_LNS][IGSYS_FACTARAGCOR2CAL1_M_COLS] = {0};
const uint16  IgSys_facTarAgCor2Cal2_M[IGSYS_FACTARAGCOR2CAL2_M_LNS][IGSYS_FACTARAGCOR2CAL2_M_COLS] = {0};
const uint16  IgSys_nEng_FacAgCor_A[IGSYS_NENG_FACAGCOR_A_COLS] = {0};
const uint16  IgSys_rAirLd_FacAgCor_A[IGSYS_RAIRLD_FACAGCOR_A_COLS] = {0};
const uint16  IgSys_tSelUsr_TarAgCor_A[IGSYS_TSELUSR_TARAGCOR_A_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
boolean IgSys_bAcvFacAgCorCal1;
boolean IgSys_bAcvFacAgCorCal2;
boolean IgSys_prm_bAcvFacAgCorCal[IGSYS_PRM_BACVFACAGCORCAL_COLS];
uint8 IgSys_facFacAgCorBasModCur;
uint8 IgSys_facFacAgCorBasModTar;
uint8 IgSys_facFacAgCorTranMod;
uint8 IgSys_idxFacAgCorBas1ModCur;
uint8 IgSys_idxFacAgCorBas1ModTar;
uint8 IgSys_idxFacAgCorBas2ModCur;
uint8 IgSys_idxFacAgCorBas2ModTar;
uint16 IgSys_facAgCorBas1ModCur;
uint16 IgSys_facAgCorBas1ModTar;
uint16 IgSys_facAgCorBas2ModCur;
uint16 IgSys_facAgCorBas2ModTar;
uint16 IgSys_facAgCorCal1;
uint16 IgSys_facAgCorCal2;
uint16 IgSys_facAgCorSelTranFlex_MP;
uint16 IgSys_facAgCorTran;
uint16 IgSys_facAgCorTranCur_MP;
uint16 IgSys_facAgCorTranTar_MP;
uint16 IgSys_prm_facAgCor[IGSYS_PRM_FACAGCOR_COLS];
sint32 IgSys_tSelUsrFacAgCor;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

