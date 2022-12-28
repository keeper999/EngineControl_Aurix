/*******************************************************************************
*                    Delphi Diesel Systems
*
*                    This document is the property of
*                    Delphi Diesel Systems
*                    It must not be copied (in whole or in part)
*                    or disclosed without prior written consent
*                    of the company. Any copies by any method
*                    must also include a copy of this legend.
********************************************************************************
* Task File History: This comment block is automatically
*                    updated by the configuration management tool
*                    DO NOT Update manually
*------------------------------------------------------------------------------*
*
* Ref X:\integration_view_00PSASWC_E510D01\blois_psa_sstg\Software\Appli\TqAdpCmp\src\TQADPCMP_nvm.h
* Version int :/main/00PSASWC_E5/2 Date: 21/3/2012 15 h 10 m User:esnault 
*    TWK_model:NO_MODEL
*    comments :correct FDS A0204111
* Version dev :\main\branch_morisseau_tqadpcmp_view\2 Date: 5/3/2012 17 h 17 m User:morisseau 
*    TWK_model:NO_MODEL
*    comments :correct FDS A0204111
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 10/10/2011 9 h 13 m User:morisseau
*    TWK_model:NO_MODEL
*    comments :correction of FDS A0203388
* Version int :/main/00PSASWC_E5/1 Date: 6/6/2011 10 h 28 m User:meme
*    TWK_model:NO_MODEL
*    comments :correction of FDS A0201864
* Version dev :\main\branch_lemort_tqadpcmp_dev\1 Date: 26/5/2011 10 h 51 m User:lemort
*    TWK_model:NO_MODEL
*    comments :correction of FDS A0201864
*
*******************************************************************************/



#ifndef TQADPCMP_NVM_H
#define TQADPCMP_NVM_H

/*******************************************************************************
*  Software Component API Header File
*******************************************************************************/

#include "TqAdpCmp.h"

/*******************************************************************************
*  SWC Level Type Definitions
*******************************************************************************/


typedef struct
{
    UInt32 TqAdp_dstVehHld_NV;
} tqadpcmp_strnvm_z1_const_32bit;

typedef struct
{
    SInt16 TqAdp_prm_tqCorLrnDragRed_NV[TQADPCMP_8_SIZE];
    SInt16 TqAdp_prm_tqCorLrnNeut_NV[TQADPCMP_8_SIZE];
} tqadpcmp_strnvm_z1_const_16bit;

typedef struct
{
    SInt8 TqCmp_tAirDifMem_NV;
    SInt8 TqCmp_tAirEstimMem_NV;
    UInt8 TqAdp_ctDst_NV;
} tqadpcmp_strnvm_z1_const_8bit;

#endif


/*******************************************************************************
*  Software Component Level NVM Variables: Outputs to other Files
*******************************************************************************/

/* 32-bits variables definition */
#define TQADPCMP_START_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "TqAdpCmp_MemMap.h"
extern VAR(tqadpcmp_strnvm_z1_const_32bit, AUTOMATIC) TqAdpCmp_sNV_Z1_CST_32BIT;
#define TQADPCMP_STOP_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "TqAdpCmp_MemMap.h"

/* 16-bits variables definition */
#define TQADPCMP_START_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "TqAdpCmp_MemMap.h"
extern VAR(tqadpcmp_strnvm_z1_const_16bit, AUTOMATIC) TqAdpCmp_sNV_Z1_CST_16BIT;
#define TQADPCMP_STOP_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits variables definition */
#define TQADPCMP_START_SEC_VAR_SAVED_ZONE1_CONST_8BIT
#include "TqAdpCmp_MemMap.h"
extern VAR(tqadpcmp_strnvm_z1_const_8bit, AUTOMATIC) TqAdpCmp_sNV_Z1_CST_8BIT;
#define TQADPCMP_STOP_SEC_VAR_SAVED_ZONE1_CONST_8BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
*  Software Component Level NVM Variables recovery value
*******************************************************************************/


/* 32-bits variables definition */
#define TQADPCMP_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_32BIT
#include "TqAdpCmp_MemMap.h"
extern CONST(tqadpcmp_strnvm_z1_const_32bit, AUTOMATIC) TqAdpCmp_sNV_Z1_CST_32BIT_r;
#define TQADPCMP_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_32BIT
#include "TqAdpCmp_MemMap.h"

/* 16-bits variables definition */
#define TQADPCMP_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_16BIT
#include "TqAdpCmp_MemMap.h"
extern CONST(tqadpcmp_strnvm_z1_const_16bit, AUTOMATIC) TqAdpCmp_sNV_Z1_CST_16BIT_r;
#define TQADPCMP_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits variables definition */
#define TQADPCMP_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_8BIT
#include "TqAdpCmp_MemMap.h"
extern CONST(tqadpcmp_strnvm_z1_const_8bit, AUTOMATIC) TqAdpCmp_sNV_Z1_CST_8BIT_r;
#define TQADPCMP_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_8BIT
#include "TqAdpCmp_MemMap.h"

