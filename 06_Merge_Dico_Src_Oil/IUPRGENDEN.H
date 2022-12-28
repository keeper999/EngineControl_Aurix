/***************************************************************************
;**
;** FILE NAME      : IUPRGENDEN.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef IUPRGENDEN_H
#define IUPRGENDEN_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "GD_A.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define DEF_IUPR_GEN_DENOM_OK             0

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

extern const boolean  IUPR_bRstPrm_C;
extern const uint8  Iupr_ambient_temp_thresh;
extern const uint16  GOBD_nObdStrtThd_C;
extern const uint16  Iupr_gen_denom_cumul_delay;
extern const uint16  Iupr_gen_denom_idle_delay;
extern const uint16  Iupr_gen_denom_over_40kph_delay;
extern const uint16  Iupr_pressure_thresh;
extern const uint16  IUPR_tiObdStrtThd_C;
extern const uint16  Iupr_vitesse_veh_idle_thresh;
extern const uint16  Iupr_vitesse_vehicule_thresh;

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

void GD_EveRst_IuprGenDen(void);
void IUPRGENDEN_vidMngEveGlbDCStrt(void);
void IUPRGENDEN_vidMngEveSdlFast(void);
void IUPRGENDEN_vidMngEveSdlSlow(void);


#endif /* IUPRGENDEN_H */

/*-------------------------------- end of file -------------------------------*/
