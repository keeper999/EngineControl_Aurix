/***************************************************************************
;**
;** FILE NAME      : KNKINSTNOISERBL.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef KNKINSTNOISERBL_H
#define KNKINSTNOISERBL_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define BRUIT_INSTANTANE_RBL_LNS              ( 16 )
#define BRUIT_INSTANTANE_RBL_COLS              ( 4 )
#define KNK_RBL_NOI_FMT_LOAD_BKPT_UACN1_COLS   ( 9 )
#define KNK_RBL_NOI_FMT_MAP_CYL1_UACN2_LNS    ( 9 )
#define KNK_RBL_NOI_FMT_MAP_CYL1_UACN2_COLS    ( 9 )
#define KNK_RBL_NOI_FMT_MAP_CYL2_UACN2_LNS    ( 9 )
#define KNK_RBL_NOI_FMT_MAP_CYL2_UACN2_COLS    ( 9 )
#define KNK_RBL_NOI_FMT_MAP_CYL3_UACN2_LNS    ( 9 )
#define KNK_RBL_NOI_FMT_MAP_CYL3_UACN2_COLS    ( 9 )
#define KNK_RBL_NOI_FMT_MAP_CYL4_UACN2_LNS    ( 9 )
#define KNK_RBL_NOI_FMT_MAP_CYL4_UACN2_COLS    ( 9 )
#define KNK_RBL_NOI_FMT_N_BKPT_UACN1_COLS      ( 9 )

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

extern const uint8  Knk_rbl_noi_fmt_map_cyl1_uacn2[KNK_RBL_NOI_FMT_MAP_CYL1_UACN2_LNS][KNK_RBL_NOI_FMT_MAP_CYL1_UACN2_COLS];
extern const uint8  Knk_rbl_noi_fmt_map_cyl2_uacn2[KNK_RBL_NOI_FMT_MAP_CYL2_UACN2_LNS][KNK_RBL_NOI_FMT_MAP_CYL2_UACN2_COLS];
extern const uint8  Knk_rbl_noi_fmt_map_cyl3_uacn2[KNK_RBL_NOI_FMT_MAP_CYL3_UACN2_LNS][KNK_RBL_NOI_FMT_MAP_CYL3_UACN2_COLS];
extern const uint8  Knk_rbl_noi_fmt_map_cyl4_uacn2[KNK_RBL_NOI_FMT_MAP_CYL4_UACN2_LNS][KNK_RBL_NOI_FMT_MAP_CYL4_UACN2_COLS];
extern const uint8  Knk_rbl_noi_fmt_n_bkpt_uacn1[KNK_RBL_NOI_FMT_N_BKPT_UACN1_COLS];
extern const uint16  Knk_rbl_noi_fmt_load_bkpt_uacn1[KNK_RBL_NOI_FMT_LOAD_BKPT_UACN1_COLS];

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint16 Bruit_instantane_rbl[BRUIT_INSTANTANE_RBL_LNS][BRUIT_INSTANTANE_RBL_COLS];
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void KNKINSTNOISERBL_vidEntryInit(void);
void KnkTreat_EveRbl_KnkInstNoiseRbl(void);


#endif /* KNKINSTNOISERBL_H */

/*-------------------------------- end of file -------------------------------*/
