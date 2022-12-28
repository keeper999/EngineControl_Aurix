/***************************************************************************
;**
;** FILE NAME      : ADDONAGCOR_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ADDONAGCOR_L_H
#define ADDONAGCOR_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define IGSYS_PRM_BACVFACAGCORCAL_COLS         ( 2 )
#define IGSYS_PRM_FACAGCOR_COLS                ( 2 )

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

extern const uint8  ADDONAGCOR_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern boolean IgSys_bAcvFacAgCorCal1;
extern boolean IgSys_bAcvFacAgCorCal2;
extern boolean IgSys_prm_bAcvFacAgCorCal[IGSYS_PRM_BACVFACAGCORCAL_COLS];
extern uint8 IgSys_facFacAgCorBasModCur;
extern uint8 IgSys_facFacAgCorBasModTar;
extern uint8 IgSys_facFacAgCorTranMod;
extern uint8 IgSys_idxFacAgCorBas1ModCur;
extern uint8 IgSys_idxFacAgCorBas1ModTar;
extern uint8 IgSys_idxFacAgCorBas2ModCur;
extern uint8 IgSys_idxFacAgCorBas2ModTar;
extern uint16 IgSys_facAgCorBas1ModCur;
extern uint16 IgSys_facAgCorBas1ModTar;
extern uint16 IgSys_facAgCorBas2ModCur;
extern uint16 IgSys_facAgCorBas2ModTar;
extern uint16 IgSys_facAgCorCal1;
extern uint16 IgSys_facAgCorCal2;
extern uint16 IgSys_facAgCorSelTranFlex_MP;
extern uint16 IgSys_facAgCorTran;
extern uint16 IgSys_facAgCorTranCur_MP;
extern uint16 IgSys_facAgCorTranTar_MP;
extern uint16 IgSys_prm_facAgCor[IGSYS_PRM_FACAGCOR_COLS];
extern sint32 IgSys_tSelUsrFacAgCor;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void ADDONAGCOR_vidCalibration_1(void);
void ADDONAGCOR_vidCalibration_2(void);
void ADDONAGCOR_vidCalibrations(void);
void ADDONAGCOR_vidCoordination(void);
void ADDONAGCOR_vidInitOutput(void);
void ADDONAGCOR_vidInterpolation(void);
void ADDONAGCOR_vidMode_Mask(void);
void ADDONAGCOR_vidSel_T_utilisee(void);
void ADDONAGCOR_vidSelect_Modes(void);
void ADDONAGCOR_vidUnvectorize_Mode(void);
void ADDONAGCOR_vidUnvectorz_Act_Bool(void);
void ADDONAGCOR_vidVectorize_Calib(void);


#endif /* ADDONAGCOR_L_H */

/*-------------------------------- end of file -------------------------------*/
