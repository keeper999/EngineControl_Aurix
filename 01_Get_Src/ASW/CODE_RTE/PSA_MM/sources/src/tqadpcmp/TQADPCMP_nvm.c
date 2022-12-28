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
* Ref X:\integration_view_00PSASWC_E510D01\blois_psa_sstg\Software\Appli\TqAdpCmp\src\TQADPCMP_nvm.c
* Version int :/main/L02_01/1 Date: 21/3/2012 15 h 10 m User:esnault 
*    TWK_model:TQADPCMP_Nvm_L02_010_IMPL1
*    comments :correct FDS A0204111
* Version dev :\main\branch_morisseau_tqadpcmp_view\2 Date: 5/3/2012 17 h 17 m User:morisseau 
*    TWK_model:TQADPCMP_Nvm_L02_010_IMPL1
*    comments :correct FDS A0204111
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 2/3/2012 14 h 6 m User:morisseau
*    TWK_model:TQADPCMP_Nvm_L02_010_IMPL1
*    comments :update model only (prm size correction)
* Version int :/main/L01_01/2 Date: 6/6/2011 10 h 28 m User:meme
*    TWK_model:TQADPCMP_Nvm_L01_010_IMPL2_D
*    comments :update optimisation for TqAdpCmp 10.5
* Version dev :\main\branch_lemort_tqadpcmp_dev\1 Date: 26/5/2011 10 h 51 m User:lemort
*    TWK_model:TQADPCMP_Nvm_L01_010_IMPL2_D
*    comments :update optimisation for TqAdpCmp 10.5
* Version int :/main/L01_01/1 Date: 13/9/2010 14 h 21 m User:esnault
*    TWK_model:TQADPCMP_Nvm_L01_010_IMPL2
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\6 Date: 13/9/2010 9 h 59 m User:morisseau
*    TWK_model:TQADPCMP_Nvm_L01_010_IMPL2
*    comments :for TqAdpCmp euro 6
* Version dev :\main\branch_morisseau_tqadpcmp_view\5 Date: 9/7/2010 16 h 23 m User:morisseau
*    TWK_model:TQADPCMP_Nvm_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\4 Date: 8/7/2010 18 h 5 m User:morisseau
*    TWK_model:TQADPCMP_Nvm_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\3 Date: 7/7/2010 9 h 24 m User:morisseau
*    TWK_model:TQADPCMP_Nvm_L01_010_IMPL1
*    comments :work in progress
* Version dev :\main\branch_morisseau_tqadpcmp_view\2 Date: 29/6/2010 11 h 49 m User:morisseau
*    TWK_model:TQADPCMP_Eeprom_L01_010_IMPL1
*    comments :for TqAdpCmp 1.0
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 23/6/2010 14 h 22 m User:morisseau
*    TWK_model:TQADPCMP_Eeprom_L01_010_IMPL1
*    comments :for TqAdpCmp: just structure of file
*
*******************************************************************************/

/*******************************************************************************
*  Library Include Files
*******************************************************************************/

/* DDS Library */
#include "dds_lib.h"


/*******************************************************************************
*  Software Component API Header File
*******************************************************************************/

#include "TqAdpCmp.h"
#include "TQADPCMP_nvm.h"

/*******************************************************************************
* File Macro Definitions
*******************************************************************************/



/*******************************************************************************
* File Level Type Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Variables: Inputs from other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Constants: Inputs from other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Calibration: Inputs from other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Scalar Calibration Definitions: Outputs to other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Map Calibration Definitions: Outputs to other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
*  Software Component Level NVM Variables: Outputs to other Files
*******************************************************************************/

/* 32-bits variables definition */
#define TQADPCMP_START_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "TqAdpCmp_MemMap.h"
/* <PRQA_COMMENT><3211> Only NVM value declaration </3211></PRQA_COMMENT> */
VAR(tqadpcmp_strnvm_z1_const_32bit, AUTOMATIC) TqAdpCmp_sNV_Z1_CST_32BIT;
#define TQADPCMP_STOP_SEC_VAR_SAVED_ZONE1_CONST_32BIT
#include "TqAdpCmp_MemMap.h"

/* 16-bits variables definition */
#define TQADPCMP_START_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "TqAdpCmp_MemMap.h"
/* <PRQA_COMMENT><3211> Only NVM value declaration </3211></PRQA_COMMENT> */
VAR(tqadpcmp_strnvm_z1_const_16bit, AUTOMATIC) TqAdpCmp_sNV_Z1_CST_16BIT;
#define TQADPCMP_STOP_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits variables definition */
#define TQADPCMP_START_SEC_VAR_SAVED_ZONE1_CONST_8BIT
#include "TqAdpCmp_MemMap.h"
/* <PRQA_COMMENT><3211> Only NVM value declaration </3211></PRQA_COMMENT> */
VAR(tqadpcmp_strnvm_z1_const_8bit, AUTOMATIC) TqAdpCmp_sNV_Z1_CST_8BIT;
#define TQADPCMP_STOP_SEC_VAR_SAVED_ZONE1_CONST_8BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
*  Software Component Level NVM Variables recovery value
*******************************************************************************/


/* 32-bits variables definition */
#define TQADPCMP_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_32BIT
#include "TqAdpCmp_MemMap.h"
/* <PRQA_COMMENT><3211> Only NVM value declaration </3211></PRQA_COMMENT> */
CONST(tqadpcmp_strnvm_z1_const_32bit, AUTOMATIC) TqAdpCmp_sNV_Z1_CST_32BIT_r =
{
    /* TqAdp_dstVehHld_NV */
    (CONST(UInt32, AUTOMATIC))(0 * BIN0)
};
#define TQADPCMP_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_32BIT
#include "TqAdpCmp_MemMap.h"

/* 16-bits variables definition */
#define TQADPCMP_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_16BIT
#include "TqAdpCmp_MemMap.h"
/* <PRQA_COMMENT><3211> Only NVM value declaration </3211></PRQA_COMMENT> */
CONST(tqadpcmp_strnvm_z1_const_16bit, AUTOMATIC) TqAdpCmp_sNV_Z1_CST_16BIT_r =
{
    { /* TqAdp_prm_tqCorLrnDragRed_NV[TQADPCMP_4_SIZE] */
        (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
        (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
        (SInt16)(0 * BIN4), (SInt16)(0 * BIN4)
    },
    { /* TqAdp_prm_tqCorLrnNeut_NV[TQADPCMP_4_SIZE] */
        (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
        (SInt16)(0 * BIN4), (SInt16)(0 * BIN4), (SInt16)(0 * BIN4),
        (SInt16)(0 * BIN4), (SInt16)(0 * BIN4)
    }
};
#define TQADPCMP_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits variables definition */
#define TQADPCMP_START_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_8BIT
#include "TqAdpCmp_MemMap.h"
/* <PRQA_COMMENT><3211> Only NVM value declaration </3211></PRQA_COMMENT> */
CONST(tqadpcmp_strnvm_z1_const_8bit, AUTOMATIC) TqAdpCmp_sNV_Z1_CST_8BIT_r =
{
    /* TqCmp_tAirDifMem_NV */
    (CONST(SInt8, AUTOMATIC))(0 * BIN0),
    /* TqCmp_tAirEstimMem */
    (CONST(SInt8, AUTOMATIC))(0 * BIN0),
    /* TqAdp_ctDst_NV */
    (CONST(UInt8, AUTOMATIC))(0 * BIN0)
};
#define TQADPCMP_STOP_SEC_VAR_SAVED_RECOVERY_ZONE1_CONST_8BIT
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "TqAdpCmp_MemMap.h"

