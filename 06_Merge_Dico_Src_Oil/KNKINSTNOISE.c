/***************************************************************************
;**
;** FILE NAME      : KNKINSTNOISE.C75
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "KNKINSTNOISE.H"
#include "KNKINSTNOISE_L.H"
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
const uint8  Knk_noi_fmt_load_bkpt_uacn1[KNK_NOI_FMT_LOAD_BKPT_UACN1_COLS] = {0};
const uint8  Knk_noi_fmt_map_cyl1_uacn2[KNK_NOI_FMT_MAP_CYL1_UACN2_LNS][KNK_NOI_FMT_MAP_CYL1_UACN2_COLS] = {0};
const uint8  Knk_noi_fmt_map_cyl2_uacn2[KNK_NOI_FMT_MAP_CYL2_UACN2_LNS][KNK_NOI_FMT_MAP_CYL2_UACN2_COLS] = {0};
const uint8  Knk_noi_fmt_map_cyl3_uacn2[KNK_NOI_FMT_MAP_CYL3_UACN2_LNS][KNK_NOI_FMT_MAP_CYL3_UACN2_COLS] = {0};
const uint8  Knk_noi_fmt_map_cyl4_uacn2[KNK_NOI_FMT_MAP_CYL4_UACN2_LNS][KNK_NOI_FMT_MAP_CYL4_UACN2_COLS] = {0};
const uint8  Knk_noi_fmt_n_bkpt_uacn1[KNK_NOI_FMT_N_BKPT_UACN1_COLS] = {0};
const uint8  KNKINSTNOISE_u8Inhib = 0;
#pragma section

/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
uint16 Bruit_instantane[BRUIT_INSTANTANE_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

