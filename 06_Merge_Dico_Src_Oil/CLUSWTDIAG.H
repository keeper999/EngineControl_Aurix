/***************************************************************************
;**
;** FILE NAME      : CLUSWTDIAG.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CLUSWTDIAG_H
#define CLUSWTDIAG_H

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

extern const uint8  Clu_spdMaxStuck_C;
extern const uint8  CLUSWTDIAG_u8Inhib;
extern const uint8  Cps_controle_coh_delay;
extern const uint8  Cps_reg_mot_min_init_diag;
extern const uint8  Cps_vit_veh_max_init_diag;
extern const uint8  Cps_vit_veh_min_init_diag;
extern const uint8  Cps_vitesse_max_diag_desac;
extern const uint8  Cps_vitesse_max_sans_debrayage;
extern const uint16  Cps_req_fuel_min_init_diag;
extern const uint16  Cps_tempo_emb_max;
extern const uint16  Cps_vitesse_vehicule_init_delay;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void Clu_EveCrTR_CluSwtDiag(void);
void Clu_EveKOn_CluSwtDiag(void);
void Clu_EveRst_CluSwtDiag(void);
void Clu_SdlMid_CluSwtDiag(void);
void Clu_SdlSlow_CluSwtDiag(void);


#endif /* CLUSWTDIAG_H */

/*-------------------------------- end of file -------------------------------*/
