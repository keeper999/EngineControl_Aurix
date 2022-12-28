#ifndef _ISFHCAN_DEF_H_
#define _ISFHCAN_DEF_H_

#include "Std_Types.h"
#include "COM.h"
#include "ISFHCAN.h"
#include "ISFHCAN_L.h"
#include "ISFHCAN_IM.h"

#define ACTIVATED 1
#define NOT_ACTIVATED 0

#define AVAILABLE 0
#define NOT_AVAILABLE 1

#define FHCAN_DISABLE 0
#define FHCAN_ENABLE 1

#define FHCAN_NOT_DETECTED 0
#define FHCAN_DETECTED 1

#define FHCAN_NOT_STORED 0
#define FHCAN_STORED 1

/* 0x608 frame signals routing*/  
#define Com_CODE_LID_CMM_608                          Com_CMM608Data1_CMM_608
#define Com_DATA_A_EOBD_PID_00_CMM_608                Com_CMM608Data2_CMM_608
#define Com_TEMP_LIQUIDE_REFROI_CMM_608               Com_CMM608Data2_CMM_608
#define Com_REGIME_MOTEUR_POIDS_FAIBLE_CMM_608        Com_CMM608Data2_CMM_608
#define Com_DATA_B_EOBD_CMM_CMM_608                   Com_CMM608Data3_CMM_608
#define Com_CORREC_RAP_CARBUR_RANG_1_CMM_608          Com_CMM608Data3_CMM_608
#define Com_REGIME_MOTEUR_POIDS_FORT_CMM_608          Com_CMM608Data3_CMM_608
#define Com_DATA_A_EOBD_PID_20_CMM_608                Com_CMM608Data4_CMM_608
#define Com_CORREC_LENTE_CARBUR_RANG_1_CMM_608        Com_CMM608Data4_CMM_608
#define Com_VITESSE_VEH_CMM_608                       Com_CMM608Data4_CMM_608
#define Com_RESERVE_8_CMM_608                         Com_CMM608Data5_CMM_608
#define Com_CORREC_RAP_CARBUR_RANG_2_CMM_608          Com_CMM608Data5_CMM_608
#define Com_DEBIT_AIR_POIDS_FAIBLE_CMM_608            Com_CMM608Data5_CMM_608
#define Com_ETAT_SYST_ALIM_1_CMM_608                  Com_CMM608Data6_CMM_608
#define Com_CORREC_LENTE_CARBUR_RANG_2_CMM_608        Com_CMM608Data6_CMM_608
#define Com_DEBIT_AIR_POIDS_FORT_CMM_608              Com_CMM608Data6_CMM_608
#define Com_ETAT_SYST_ALIM_2_CMM_608                  Com_CMM608Data7_CMM_608
#define Com_MANO_CARBURANT_CMM_608                    Com_CMM608Data7_CMM_608
#define Com_PRESSION_GAS_OIL_POIDS_FAIBLE_CMM_608     Com_CMM608Data7_CMM_608
#define Com_VALEUR_CHARGE_CALCULEE_CMM_608            Com_CMM608Data8_CMM_608
#define Com_PRESSION_ABS_TUB_ADMI_CMM_608             Com_CMM608Data8_CMM_608
#define Com_PRESSION_GAS_OIL_POIDS_FORT_CMM_608       Com_CMM608Data8_CMM_608

/* 0x768 frame signals routing*/
#define Com_KILOMETRAGE_JDD_NEW_JDD_CMM_768           Com_CODES_DEFAUT_NEW_JDD_CMM_768


/* 0x432 frame signals routing*/
#define Com_DDE_DEM_MAINTENU_2_BSI_432                Com_DDE_DEM_MAINTENU_2_SEV_DEM_BSI_432
#define Com_SEV_DEM_BSI_432                           Com_DDE_DEM_MAINTENU_2_SEV_DEM_BSI_432

/* 0x552 frame signals routing*/
#define Com_CMM552DATA1_BSI_552                       Com_CMM552DATA1_V2_BSI_552
#define Com_CMM552DATA2_BSI_552                       Com_CMM552DATA2_V2_BSI_552
#define Com_CMM552DATA3_BSI_552                       Com_CMM552DATA3_V2_BSI_552
#define Com_CMM552DATA4_BSI_552                       Com_CMM552DATA4_V2_BSI_552
#define Com_CMM552DATA5_BSI_552                       Com_CMM552DATA5_V2_BSI_552

/* 0x7F2 frame signals routing*/
#define Com_CMM7F2DATA4_CONTEXTE_1_7F2                Com_Data1_CONTEXTE_1_7F2
#define Com_CMM7F2DATA5_CONTEXTE_1_7F2                Com_Data2_CONTEXTE_1_7F2
#define Com_CMM7F2DATA6_CONTEXTE_1_7F2                Com_Data3_CONTEXTE_1_7F2
 
#endif /* _ISFHCAN_DEF_H_ */