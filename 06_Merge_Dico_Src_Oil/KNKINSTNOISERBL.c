/***************************************************************************
;**
;** FILE NAME      : KNKINSTNOISERBL.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "KNKINSTNOISERBL.H"
#include "KNKINSTNOISERBL_L.H"
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
const uint8  Knk_rbl_noi_fmt_map_cyl1_uacn2[KNK_RBL_NOI_FMT_MAP_CYL1_UACN2_LNS][KNK_RBL_NOI_FMT_MAP_CYL1_UACN2_COLS] = {0};
const uint8  Knk_rbl_noi_fmt_map_cyl2_uacn2[KNK_RBL_NOI_FMT_MAP_CYL2_UACN2_LNS][KNK_RBL_NOI_FMT_MAP_CYL2_UACN2_COLS] = {0};
const uint8  Knk_rbl_noi_fmt_map_cyl3_uacn2[KNK_RBL_NOI_FMT_MAP_CYL3_UACN2_LNS][KNK_RBL_NOI_FMT_MAP_CYL3_UACN2_COLS] = {0};
const uint8  Knk_rbl_noi_fmt_map_cyl4_uacn2[KNK_RBL_NOI_FMT_MAP_CYL4_UACN2_LNS][KNK_RBL_NOI_FMT_MAP_CYL4_UACN2_COLS] = {0};
const uint8  Knk_rbl_noi_fmt_n_bkpt_uacn1[KNK_RBL_NOI_FMT_N_BKPT_UACN1_COLS] = {0};
const uint8  KnkInstNoiseRbl_u8Inhib = 0;
const uint16  Knk_rbl_noi_fmt_load_bkpt_uacn1[KNK_RBL_NOI_FMT_LOAD_BKPT_UACN1_COLS] = {0};
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint8 Knk_rbl_noi_fmt_cyl1_uavn0;
uint8 Knk_rbl_noi_fmt_cyl2_uavn0;
uint8 Knk_rbl_noi_fmt_cyl3_uavn0;
uint8 Knk_rbl_noi_fmt_cyl4_uavn0;
uint8 Knk_rbl_noi_fmt_uavn0;
uint16 Bruit_instantane_rbl[BRUIT_INSTANTANE_RBL_LNS][BRUIT_INSTANTANE_RBL_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

