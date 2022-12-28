/***************************************************************************
;**
;** FILE NAME      : KNKINSTNOISE.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef KNKINSTNOISE_H
#define KNKINSTNOISE_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define BRUIT_INSTANTANE_COLS                  ( 4 )
#define KNK_NOI_FMT_LOAD_BKPT_UACN1_COLS       ( 16 )
#define KNK_NOI_FMT_MAP_CYL1_UACN2_LNS        ( 16 )
#define KNK_NOI_FMT_MAP_CYL1_UACN2_COLS        ( 8 )
#define KNK_NOI_FMT_MAP_CYL2_UACN2_LNS        ( 16 )
#define KNK_NOI_FMT_MAP_CYL2_UACN2_COLS        ( 8 )
#define KNK_NOI_FMT_MAP_CYL3_UACN2_LNS        ( 16 )
#define KNK_NOI_FMT_MAP_CYL3_UACN2_COLS        ( 8 )
#define KNK_NOI_FMT_MAP_CYL4_UACN2_LNS        ( 16 )
#define KNK_NOI_FMT_MAP_CYL4_UACN2_COLS        ( 8 )
#define KNK_NOI_FMT_N_BKPT_UACN1_COLS          ( 8 )

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

extern const uint8  Knk_noi_fmt_load_bkpt_uacn1[KNK_NOI_FMT_LOAD_BKPT_UACN1_COLS];
extern const uint8  Knk_noi_fmt_map_cyl1_uacn2[KNK_NOI_FMT_MAP_CYL1_UACN2_LNS][KNK_NOI_FMT_MAP_CYL1_UACN2_COLS];
extern const uint8  Knk_noi_fmt_map_cyl2_uacn2[KNK_NOI_FMT_MAP_CYL2_UACN2_LNS][KNK_NOI_FMT_MAP_CYL2_UACN2_COLS];
extern const uint8  Knk_noi_fmt_map_cyl3_uacn2[KNK_NOI_FMT_MAP_CYL3_UACN2_LNS][KNK_NOI_FMT_MAP_CYL3_UACN2_COLS];
extern const uint8  Knk_noi_fmt_map_cyl4_uacn2[KNK_NOI_FMT_MAP_CYL4_UACN2_LNS][KNK_NOI_FMT_MAP_CYL4_UACN2_COLS];
extern const uint8  Knk_noi_fmt_n_bkpt_uacn1[KNK_NOI_FMT_N_BKPT_UACN1_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 Bruit_instantane[BRUIT_INSTANTANE_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void KnkTreat_EveCkSnOn_InstNoise(void);
void KnkTreat_EveKnk_InstNoise(void);
void KnkTreat_EveRst_InstNoise(void);


#endif /* KNKINSTNOISE_H */

/*-------------------------------- end of file -------------------------------*/
