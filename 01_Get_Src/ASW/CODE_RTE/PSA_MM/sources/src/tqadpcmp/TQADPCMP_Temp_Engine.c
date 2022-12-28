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
* Ref X:\integration_view_00PSASWC_E511D01\blois_psa_sstg\Software\Appli\TqAdpCmp\src\TQADPCMP_Temp_Engine.c
* Version int :/main/L03_02/1 Date: 23/4/2012 11 h 58 m User:meme 
*    TWK_model:TQADPCMP_Temp_Engine_L03_020_IMPL1
*    comments :for TqAdpCmp: spec update
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 16/4/2012 11 h 36 m User:morisseau 
*    TWK_model:TQADPCMP_Temp_Engine_L03_020_IMPL1
*    comments :for TqAdpCmp: spec update
* Version int :/main/L03_01/1 Date: 21/3/2012 15 h 10 m User:esnault
*    TWK_model:TQADPCMP_Temp_Engine_L03_010_IMPL1
*    comments :For TqAdpCmp_11_0_e6
* Version int :/main/L02_01/2 Date: 14/9/2011 16 h 27 m User:meme
*    TWK_model:TQADPCMP_Temp_Engine_L02_010_IMPL1_D
*    comments :TU corrections for TqAdpCmp 10.6
* Version int :/main/L02_01/1 Date: 18/11/2010 12 h 47 m User:meme
*    TWK_model:TQADPCMP_Temp_Engine_L02_010_IMPL1
*    comments :for TqAdpCmp 10.2
* Version int :/main/L01_01/1 Date: 13/9/2010 14 h 21 m User:esnault
*    TWK_model:TQADPCMP_Temp_Engine_L01_010_IMPL2
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\6 Date: 25/8/2010 17 h 22 m User:morisseau
*    TWK_model:TQADPCMP_Temp_Engine_L01_010_IMPL2
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\5 Date: 22/7/2010 16 h 6 m User:morisseau
*    TWK_model:TQADPCMP_Temp_Engine_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\4 Date: 9/7/2010 16 h 23 m User:morisseau
*    TWK_model:TQADPCMP_Temp_Engine_L01_010_IMPL1
*    comments :for TqAdpCmp
* Version dev :\main\branch_morisseau_tqadpcmp_view\3 Date: 7/7/2010 9 h 24 m User:morisseau
*    TWK_model:TQADPCMP_Temp_Engine_L01_010_IMPL1
*    comments :work in progress
* Version dev :\main\branch_morisseau_tqadpcmp_view\2 Date: 24/6/2010 11 h 22 m User:morisseau
*    TWK_model:TQADPCMP_Temp_Engine_L01_010_IMPL1
*    comments :for TqAdpCmp 1.0
* Version dev :\main\branch_morisseau_tqadpcmp_view\1 Date: 23/6/2010 14 h 22 m User:morisseau
*    TWK_model:TQADPCMP_Temp_Engine_L01_010_IMPL1
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


/*******************************************************************************
* File Macro Definitions
*******************************************************************************/

#define TQADPCMP_BVA        (UInt32)1

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
* Software Component Level Non-displayable Variables: Outputs to other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* Software Component Level Displayable Variables: Outputs to other Files
*******************************************************************************/

/* 16-bits variables definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"
VAR(UInt16, AUTOMATIC) TqAdp_idxTEngRaw; /* BIN7 */
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"

/* 8-bits variables definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"
VAR(UInt8, AUTOMATIC) TqAdp_bDragRed;
VAR(UInt8, AUTOMATIC) TqAdp_idxTEng; /* BIN0 */
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_8BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* Software Component Level Constants: Outputs to other Files
*******************************************************************************/

/* NONE */


/*******************************************************************************
* File Scope Scalar Calibration Definitions
*******************************************************************************/

/* 8-bits scalar calibration definition */
#define TQADPCMP_START_SEC_CALIB_8BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(UInt8, AUTOMATIC) TqAdp_bCfTEng_C = DDS_TRUE;
STATIC volatile CONST(UInt8, AUTOMATIC) TqAdp_bDragRedCf_C = DDS_FALSE;
#define TQADPCMP_STOP_SEC_CALIB_8BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Map Calibration Definitions
*******************************************************************************/

/* 16-bits MAP and TABLE calibration definition */
#define TQADPCMP_START_SEC_CARTO_16BIT
#include "TqAdpCmp_MemMap.h"
STATIC volatile CONST(UInt16, AUTOMATIC) TqAdp_idxTEng_T
[TQADPCMP_16_SIZE] = {
(UInt16)(1 * BIN7), (UInt16)(1 * BIN7), (UInt16)(2 * BIN7),
(UInt16)(2 * BIN7), (UInt16)(3 * BIN7), (UInt16)(3 * BIN7),
(UInt16)(4 * BIN7), (UInt16)(4 * BIN7), (UInt16)(5 * BIN7),
(UInt16)(5 * BIN7), (UInt16)(6 * BIN7), (UInt16)(6 * BIN7),
(UInt16)(7 * BIN7), (UInt16)(7 * BIN7), (UInt16)(8 * BIN7),
(UInt16)(8 * BIN7)
};

STATIC volatile CONST(SInt16, AUTOMATIC) TqAdp_tEng_A[TQADPCMP_16_SIZE] = {
(SInt16)(-40 * BIN2), (SInt16)(-20 * BIN2), (SInt16)(-19 * BIN2),
(SInt16)(0 * BIN2), (SInt16)(1 * BIN2), (SInt16)(20 * BIN2),
(SInt16)(21 * BIN2), (SInt16)(40 * BIN2), (SInt16)(41 * BIN2),
(SInt16)(60 * BIN2), (SInt16)(61 * BIN2), (SInt16)(80 * BIN2),
(SInt16)(81 * BIN2), (SInt16)(100 * BIN2), (SInt16)(101 * BIN2),
(SInt16)(120 * BIN2)
};

#define TQADPCMP_STOP_SEC_CARTO_16BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Non-displayable Variable Definitions
*******************************************************************************/

/* Complex variable definition */
#define TQADPCMP_START_SEC_VAR_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"
STATIC VAR(t_dds_m_map2d_sav, AUTOMATIC) tqadp_idxteng_t_sav;
#define TQADPCMP_STOP_SEC_VAR_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Displayable Variable Definitions
*******************************************************************************/

/* 16-bits variable definition */
#define TQADPCMP_START_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"
_DDS_STATIC_ VAR(SInt16, AUTOMATIC) TqAdp_tEng_MP; /* BIN2 */
#define TQADPCMP_STOP_SEC_INTERNAL_VAR_16BIT
#include "TqAdpCmp_MemMap.h"


/*******************************************************************************
* File Scope Constant Definitions
*******************************************************************************/

/* Complex constant definition */
#define TQADPCMP_START_SEC_CONST_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"
STATIC CONST(t_dds_m_map2d_su16, AUTOMATIC) TQADP_IDXTENG_T_APM = {
&tqadp_idxteng_t_sav,
TQADPCMP_16_SIZE,
(P2VAR(SInt16, AUTOMATIC, AUTOMATIC))&TqAdp_tEng_A[0],
(P2VAR(UInt16, AUTOMATIC, AUTOMATIC))&TqAdp_idxTEng_T[0]
};

#define TQADPCMP_STOP_SEC_CONST_UNSPECIFIED
#include "TqAdpCmp_MemMap.h"

/*******************************************************************************
* File Local Function Prototypes
*******************************************************************************/

#define TQADPCMP_START_SEC_CODE
#include "TqAdpCmp_MemMap.h"

/* STATIC FUNC(t_rettype, AUTOMATIC) Local_Function (t_paramtype parameter); */
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_01_01_Determiner_Zone_Temperature_Moteur(SInt16 ext_tcomes_par, /* BIN0 */
                                                                                     SInt16 ext_toilmes_par /* DEC1 */);

STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_01_02_Determiner_Configuration_Boite(UInt8 ext_stgbxcf_par,
                                                                                 UInt8 CoPt_stDragRed_par);

/*******************************************************************************
* Runnables Definition
*******************************************************************************/


/*******************************************************************************
*
* Function Name : TQADPCMP_Temp_Engine
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQADPCMP_Temp_Engine(UInt8 CoPt_stDragRed_swc_in,
                                           UInt8 Ext_stGBxCf_swc_in,
                                           SInt16 Ext_tCoMes_swc_in, /* BIN0 */
                                           SInt16 Ext_tOilMes_swc_in /* DEC1 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.38.1 */

    TQADPCMP_01_02_01_01_Determiner_Zone_Temperature_Moteur(Ext_tCoMes_swc_in, /* BIN0 */
                                                            Ext_tOilMes_swc_in /* DEC1 */);

    TQADPCMP_01_02_01_02_Determiner_Configuration_Boite(Ext_stGBxCf_swc_in,
                                                        CoPt_stDragRed_swc_in);
}


/*******************************************************************************
* Local Task Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_01_01_Determiner_Zone_Temperature_Moteur
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_01_01_Determiner_Zone_Temperature_Moteur(SInt16 ext_tcomes_par, /* BIN0 */
                                                                                     SInt16 ext_toilmes_par /* DEC1 */)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.41.0 */

    if((UInt32)TqAdp_bCfTEng_C!=(UInt32)DDS_FALSE)
    {
        TqAdp_tEng_MP = (SInt16)(DDS_M_MIN((SInt32)ext_tcomes_par,(SInt32)200) * BIN2);
    }
    else
    {
        TqAdp_tEng_MP = (SInt16)(((SInt32)ext_toilmes_par * BIN2) / DEC1);
    }

    TqAdp_idxTEngRaw = DDS_M_MAP2D_SU16(&TQADP_IDXTENG_T_APM,TqAdp_tEng_MP);

    TqAdp_idxTEng = (UInt8)((UInt32)TqAdp_idxTEngRaw / BIN7);
}

/*******************************************************************************
*
* Function Name : TQADPCMP_01_02_01_02_Determiner_Configuration_Boite
* Description :
*
*******************************************************************************/
STATIC FUNC(void, AUTOMATIC) TQADPCMP_01_02_01_02_Determiner_Configuration_Boite(UInt8 ext_stgbxcf_par,
                                                                                 UInt8 CoPt_stDragRed_par)
{
    /* SSTG_REQ_TAG CSMT_CGMT06_2117.FR.42.1 */

    if((UInt32)ext_stgbxcf_par != TQADPCMP_BVA)
    {
        TqAdp_bDragRed = TqAdp_bDragRedCf_C;
    }
    else
    {
       if((UInt32)CoPt_stDragRed_par == TQADPCMP_BVA)
        {
            TqAdp_bDragRed = DDS_TRUE;
        }
       else

       {
           TqAdp_bDragRed = DDS_FALSE;
        }
    }
}



/*******************************************************************************
* Task Initialisation Function Definition
*******************************************************************************/

/*******************************************************************************
*
* Function Name : TQADPCMP_Temp_Engine_Init
* Description :
*
*******************************************************************************/
FUNC(void, AUTOMATIC) TQADPCMP_Temp_Engine_Init(void)
{
    TqAdp_bDragRed = DDS_FALSE;
    TqAdp_idxTEng = 1;
    TqAdp_idxTEngRaw = (UInt16)(1 * BIN7);
}


#define TQADPCMP_STOP_SEC_CODE
#include "TqAdpCmp_MemMap.h"

