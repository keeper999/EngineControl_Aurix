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
* Ref X:\integration_view_00PSASWC_E510D01\blois_psa_sstg\Software\Appli\TqAdpCmp\src\TQADPCMP_Loss_Nvm.c
* Version int :/main/L02_01/1 Date: 21/3/2012 15 h 10 m User:esnault 
*    TWK_model:TQADPCMP_Loss_Nvm_L02_010_IMPL1
*    comments :For TqAdpCmp_11_0_e6
* Version dev :\main\branch_halouane_tqadpcmp_e6\1 Date: 7/3/2012 12 h 8 m User:halouane 
*    TWK_model:TQADPCMP_Loss_Nvm_L02_010_IMPL1
*    comments :For TqAdpCmp_11_0_e6
* Version int :/main/L01_01/2 Date: 6/6/2011 10 h 27 m User:meme
*    TWK_model:TQADPCMP_Loss_Nvm_L01_010_IMPL1_D
*    comments :QAC warning
* Version dev :\main\branch_lemort_tqadpcmp_dev\2 Date: 26/5/2011 15 h 3 m User:lemort
*    TWK_model:TQADPCMP_Loss_Nvm_L01_010_IMPL1_D
*    comments :QAC warning
* Version dev :\main\branch_lemort_tqadpcmp_dev\1 Date: 26/5/2011 14 h 24 m User:lemort
*    TWK_model:TQADPCMP_Loss_Nvm_L01_010_IMPL1_D
*    comments :include nvm.h
* Version int :/main/L01_01/1 Date: 13/9/2010 14 h 21 m User:esnault
*    TWK_model:TQADPCMP_Loss_Nvm_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\7 Date: 2/9/2010 11 h 34 m User:morisseau
*    TWK_model:TQADPCMP_Loss_Nvm_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\6 Date: 22/7/2010 16 h 6 m User:morisseau
*    TWK_model:TQADPCMP_Loss_Nvm_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\5 Date: 9/7/2010 16 h 23 m User:morisseau
*    TWK_model:TQADPCMP_Loss_Nvm_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\4 Date: 8/7/2010 18 h 5 m User:morisseau
*    TWK_model:TQADPCMP_Loss_Nvm_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\3 Date: 7/7/2010 9 h 23 m User:morisseau
*    TWK_model:TQADPCMP_Loss_Nvm_L01_010_IMPL1
*    comments :work in progress
* Version dev :\main\branch_morisseau_tqadpcmp_view\2 Date: 29/6/2010 11 h 49 m User:morisseau
*    TWK_model:TQADPCMP_Loss_Nvm_L01_010_IMPL1
*    comments :for TqAdpCmp 1.0
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 23/6/2010 14 h 22 m User:morisseau
*    TWK_model:TQADPCMP_Loss_Nvm_L01_010_IMPL1
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

/* 16-bits variables definition */
#define TQADPCMP_START_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "TqAdpCmp_MemMap.h"
extern VAR(tqadpcmp_strnvm_z1_const_16bit, AUTOMATIC) TqAdpCmp_sNV_Z1_CST_16BIT;
#define TQADPCMP_STOP_SEC_VAR_SAVED_ZONE1_CONST_16BIT
#include "TqAdpCmp_MemMap.h"

/* 16-bits variables definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"
extern VAR(SInt16, AUTOMATIC) TqAdp_prm_tqCorLrnDragRed[TQADPCMP_8_SIZE]; /* BIN4 */
extern VAR(SInt16, AUTOMATIC) TqAdp_prm_tqCorLrnNeut[TQADPCMP_8_SIZE]; /* BIN4 */
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"


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
* Software Component Level Non-displayable Variables: Outputs to other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Displayable Variables: Outputs to other Files
*******************************************************************************/

/* 16-bits variables definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"
VAR(SInt16, AUTOMATIC) TqAdp_prm_tqCorLrnDragRedIni[TQADPCMP_8_SIZE]; /* BIN4 */
VAR(SInt16, AUTOMATIC) TqAdp_prm_tqCorLrnNeutIni[TQADPCMP_8_SIZE]; /* BIN4 */
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* Software Component Level Constants: Outputs to other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Scalar Calibration Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* 8-bits variable definition */
#define TQADPCMP_START_SEC_VAR_8BIT
#include "TqAdpCmp_MemMap.h"
STATIC VAR(UInt8, AUTOMATIC) loss_nvm_lec_done;
#define TQADPCMP_STOP_SEC_VAR_8BIT
#include "TqAdpCmp_MemMap.h"

/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_tqCorLrnDragRedIni1_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_tqCorLrnDragRedIni2_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_tqCorLrnDragRedIni3_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_tqCorLrnDragRedIni4_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_tqCorLrnDragRedIni5_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_tqCorLrnDragRedIni6_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_tqCorLrnDragRedIni7_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_tqCorLrnDragRedIni8_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_tqCorLrnNeutIni1_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_tqCorLrnNeutIni2_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_tqCorLrnNeutIni3_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_tqCorLrnNeutIni4_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_tqCorLrnNeutIni5_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_tqCorLrnNeutIni6_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_tqCorLrnNeutIni7_MP; /* BIN4 */
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_tqCorLrnNeutIni8_MP; /* BIN4 */
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* NONE */

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define TQADPCMP_START_SEC_CODE
#include "TqAdpCmp_MemMap.h"

/* STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : TQADPCMP_Loss_Nvm
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQADPCMP_Loss_Nvm(void)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.36.0 */

    if((UInt32)loss_nvm_lec_done != (UInt32)DDS_TRUE)
    {
        loss_nvm_lec_done = DDS_TRUE;

        TqAdp_tqCorLrnDragRedIni1_MP = TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnDragRed_NV[0];
        TqAdp_tqCorLrnDragRedIni2_MP = TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnDragRed_NV[1];
        TqAdp_tqCorLrnDragRedIni3_MP = TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnDragRed_NV[2];
        TqAdp_tqCorLrnDragRedIni4_MP = TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnDragRed_NV[3];
        TqAdp_tqCorLrnDragRedIni5_MP = TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnDragRed_NV[4];
        TqAdp_tqCorLrnDragRedIni6_MP = TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnDragRed_NV[5];
        TqAdp_tqCorLrnDragRedIni7_MP = TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnDragRed_NV[6];
        TqAdp_tqCorLrnDragRedIni8_MP = TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnDragRed_NV[7];

        TqAdp_prm_tqCorLrnDragRedIni[0] = TqAdp_tqCorLrnDragRedIni1_MP;
        TqAdp_prm_tqCorLrnDragRedIni[1] = TqAdp_tqCorLrnDragRedIni2_MP;
        TqAdp_prm_tqCorLrnDragRedIni[2] = TqAdp_tqCorLrnDragRedIni3_MP;
        TqAdp_prm_tqCorLrnDragRedIni[3] = TqAdp_tqCorLrnDragRedIni4_MP;
        TqAdp_prm_tqCorLrnDragRedIni[4] = TqAdp_tqCorLrnDragRedIni5_MP;
        TqAdp_prm_tqCorLrnDragRedIni[5] = TqAdp_tqCorLrnDragRedIni6_MP;
        TqAdp_prm_tqCorLrnDragRedIni[6] = TqAdp_tqCorLrnDragRedIni7_MP;
        TqAdp_prm_tqCorLrnDragRedIni[7] = TqAdp_tqCorLrnDragRedIni8_MP;

        TqAdp_tqCorLrnNeutIni1_MP = TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnNeut_NV[0];
        TqAdp_tqCorLrnNeutIni2_MP = TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnNeut_NV[1];
        TqAdp_tqCorLrnNeutIni3_MP = TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnNeut_NV[2];
        TqAdp_tqCorLrnNeutIni4_MP = TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnNeut_NV[3];
        TqAdp_tqCorLrnNeutIni5_MP = TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnNeut_NV[4];
        TqAdp_tqCorLrnNeutIni6_MP = TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnNeut_NV[5];
        TqAdp_tqCorLrnNeutIni7_MP = TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnNeut_NV[6];
        TqAdp_tqCorLrnNeutIni8_MP = TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnNeut_NV[7];

        TqAdp_prm_tqCorLrnNeutIni[0] = TqAdp_tqCorLrnNeutIni1_MP;
        TqAdp_prm_tqCorLrnNeutIni[1] = TqAdp_tqCorLrnNeutIni2_MP;
        TqAdp_prm_tqCorLrnNeutIni[2] = TqAdp_tqCorLrnNeutIni3_MP;
        TqAdp_prm_tqCorLrnNeutIni[3] = TqAdp_tqCorLrnNeutIni4_MP;
        TqAdp_prm_tqCorLrnNeutIni[4] = TqAdp_tqCorLrnNeutIni5_MP;
        TqAdp_prm_tqCorLrnNeutIni[5] = TqAdp_tqCorLrnNeutIni6_MP;
        TqAdp_prm_tqCorLrnNeutIni[6] = TqAdp_tqCorLrnNeutIni7_MP;
        TqAdp_prm_tqCorLrnNeutIni[7] = TqAdp_tqCorLrnNeutIni8_MP;
    }
    else
    {
        TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnDragRed_NV[0] = TqAdp_prm_tqCorLrnDragRed[0];
        TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnDragRed_NV[1] = TqAdp_prm_tqCorLrnDragRed[1];
        TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnDragRed_NV[2] = TqAdp_prm_tqCorLrnDragRed[2];
        TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnDragRed_NV[3] = TqAdp_prm_tqCorLrnDragRed[3];
        TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnDragRed_NV[4] = TqAdp_prm_tqCorLrnDragRed[4];
        TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnDragRed_NV[5] = TqAdp_prm_tqCorLrnDragRed[5];
        TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnDragRed_NV[6] = TqAdp_prm_tqCorLrnDragRed[6];
        TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnDragRed_NV[7] = TqAdp_prm_tqCorLrnDragRed[7];

        TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnNeut_NV[0] = TqAdp_prm_tqCorLrnNeut[0];
        TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnNeut_NV[1] = TqAdp_prm_tqCorLrnNeut[1];
        TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnNeut_NV[2] = TqAdp_prm_tqCorLrnNeut[2];
        TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnNeut_NV[3] = TqAdp_prm_tqCorLrnNeut[3];
        TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnNeut_NV[4] = TqAdp_prm_tqCorLrnNeut[4];
        TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnNeut_NV[5] = TqAdp_prm_tqCorLrnNeut[5];
        TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnNeut_NV[6] = TqAdp_prm_tqCorLrnNeut[6];
        TqAdpCmp_sNV_Z1_CST_16BIT.TqAdp_prm_tqCorLrnNeut_NV[7] = TqAdp_prm_tqCorLrnNeut[7];
    }
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : Local_Function
* Description :
*
*******************************************************************************/
/* STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter) */
/* { */
/* } */


/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQADPCMP_Loss_Nvm_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQADPCMP_Loss_Nvm_Init(void)
{
    loss_nvm_lec_done = DDS_FALSE;
}



#define TQADPCMP_STOP_SEC_CODE
/* <PRQA_COMMENT><0862> Warning due to Autosar Memory Mapping </0862></PRQA_COMMENT> */
#include "TqAdpCmp_MemMap.h"

