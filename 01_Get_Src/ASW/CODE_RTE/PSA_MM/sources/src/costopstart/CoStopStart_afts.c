/*******************************************************************************
*                           P. C. A.
*
*                    Peugeot Citroen Automobile
*
*        This file is the property of PCA. All rights are reserved
*        by PCA and this file must not be copied or disclosed
*       (in whole or in part) without prior written consent of PCA.
*
********************************************************************************
*
* %name:  CoStopStart_afts.c %
*
* %version:  11.4 %
*
* %date_modified:  Thu Apr 19 09:39:05 2012 %
*
*
* %derived_by:  u349799 %
* %release:CoStopStart/11.0 %
* %full_filespec:  CoStopStart_afts.c-11.4:csrc:1 %
*
*******************************************************************************/

#ifndef _COSTOPSTART_AFTS_C_
#define _COSTOPSTART_AFTS_C_

#include "Rte_Type.h"
#include "PSA_afts.h"
#include "CoStopStart_nvm.h"
#include "Rte_CoStopStart.h"
#include "CoStopStart_004_TEV_fct.h"
#include "CoStopStart_016_TEV_fct.h"

#define COSTOPSTART_START_SEC_CODE
#include "CoStopStart_MemMap.h"

void RE_CoStopStart_AftsNvramRead_1(UInt8 *CoStopStart_tabNvram_1)
{
    /*
    Concerned structs :
    - [0..13] = CoStopStart_sNV_Z1_CST_16BIT_1
	- [14..16] = CoStopStart_sNV_Z1_CST_8BIT_2
	- [17] = CoStopStart_sNV_Z1_CST_8BIT_3
	- [18] = CoStopStart_sNV_Z1_CST_BOOLEAN_1
	- [19..20] = CoStopStart_sNV_Z1_CST_BOOLEAN_2
    */
    
    UInt16 position = 0;
    UInt16 *Ptr16;
    UInt8 *Ptr8;

    Ptr16 = &CoStopStart_sNV_Z1_CST_16BIT_1.CoReqRstrt_ctRStrtMem_NV;
    PSA_UInt16ToTabUInt8(*Ptr16, &CoStopStart_tabNvram_1[position]);
    position+= 2;
    Ptr16 = &CoStopStart_sNV_Z1_CST_16BIT_1.CoReqRstrt_tiRStrtSlowMem_NV;
    PSA_UInt16ToTabUInt8(*Ptr16, &CoStopStart_tabNvram_1[position]);
    position+= 2;
    Ptr16 = &CoStopStart_sNV_Z1_CST_16BIT_1.CoReqRstrt_nTDC2SlowMem_NV;
    PSA_UInt16ToTabUInt8(*Ptr16, &CoStopStart_tabNvram_1[position]);
    position+= 2;
    Ptr16 = &CoStopStart_sNV_Z1_CST_16BIT_1.CoReqRstrt_nTDC1SlowMem_NV;
    PSA_UInt16ToTabUInt8(*Ptr16, &CoStopStart_tabNvram_1[position]);
    position+= 2;
    Ptr16 = &CoStopStart_sNV_Z1_CST_16BIT_1.CoReqRstrt_nTDC2FastMem_NV;
    PSA_UInt16ToTabUInt8(*Ptr16, &CoStopStart_tabNvram_1[position]);
    position+= 2;
    Ptr16 = &CoStopStart_sNV_Z1_CST_16BIT_1.CoReqRstrt_nTDC1FastMem_NV;
    PSA_UInt16ToTabUInt8(*Ptr16, &CoStopStart_tabNvram_1[position]);
    position+= 2;
    Ptr16 = &CoStopStart_sNV_Z1_CST_16BIT_1.CoReqRstrt_tiRStrtFastMem_NV;
    PSA_UInt16ToTabUInt8(*Ptr16, &CoStopStart_tabNvram_1[position]);
    position+= 2;
    Ptr8 = &CoStopStart_sNV_Z1_CST_8BIT_2.CoPtUH_stAftsRStrtSuc_NV;
    CoStopStart_tabNvram_1[position] = *Ptr8;
    position++;
    Ptr8 = &CoStopStart_sNV_Z1_CST_8BIT_2.CoPtUH_stFbSpcFactRStrtSuc_NV;
    CoStopStart_tabNvram_1[position] = *Ptr8;
    position++;
    Ptr8 = &CoStopStart_sNV_Z1_CST_8BIT_2.CoReqRstrt_ctRstrtFail_NV;
    CoStopStart_tabNvram_1[position] = *Ptr8;
    position++;
    Ptr8 = &CoStopStart_sNV_Z1_CST_8BIT_3.DgoFct_noMemValHealLvl2_NV;
    CoStopStart_tabNvram_1[position] = *Ptr8;
    position++;    
    Ptr8 = &CoStopStart_sNV_Z1_CST_BOOLEAN_1.MgtDrv_bDftHld_NV;
    CoStopStart_tabNvram_1[position] = *Ptr8;
    position++;    
    Ptr8 = &CoStopStart_sNV_Z1_CST_BOOLEAN_2.DgoFct_bMemValPrvtLvl1_NV;
    CoStopStart_tabNvram_1[position] = *Ptr8;
    position++;
    Ptr8 = &CoStopStart_sNV_Z1_CST_BOOLEAN_2.DgoFct_bMemValHealLvl1_NV;
    CoStopStart_tabNvram_1[position] = *Ptr8;
    position++;

}

void RE_CoStopStart_AftsNvramWrite_1(UInt8 *CoStopStart_tabNvram_1)
{

    /*
    Concerned structs :
	- [0..13] = CoStopStart_sNV_Z1_CST_16BIT_1
	- [17] = CoStopStart_sNV_Z1_CST_8BIT_3
	- [19..20] = CoStopStart_sNV_Z1_CST_BOOLEAN_2
    */
    
    UInt16 position = 0;

    CoStopStart_sNV_Z1_CST_16BIT_1.CoReqRstrt_ctRStrtMem_NV = PSA_TabUInt8ToUInt16(&CoStopStart_tabNvram_1[position]);
    position+= 2;
    CoStopStart_sNV_Z1_CST_16BIT_1.CoReqRstrt_tiRStrtSlowMem_NV = PSA_TabUInt8ToSInt16(&CoStopStart_tabNvram_1[position]);
    position+= 2;
    CoStopStart_sNV_Z1_CST_16BIT_1.CoReqRstrt_nTDC2SlowMem_NV = PSA_TabUInt8ToSInt16(&CoStopStart_tabNvram_1[position]);
    position+= 2;
    CoStopStart_sNV_Z1_CST_16BIT_1.CoReqRstrt_nTDC1SlowMem_NV = PSA_TabUInt8ToSInt16(&CoStopStart_tabNvram_1[position]);
    position+= 2;
    CoStopStart_sNV_Z1_CST_16BIT_1.CoReqRstrt_nTDC2FastMem_NV = PSA_TabUInt8ToSInt16(&CoStopStart_tabNvram_1[position]);
    position+= 2;
    CoStopStart_sNV_Z1_CST_16BIT_1.CoReqRstrt_nTDC1FastMem_NV = PSA_TabUInt8ToSInt16(&CoStopStart_tabNvram_1[position]);
    position+= 2;
    CoStopStart_sNV_Z1_CST_16BIT_1.CoReqRstrt_tiRStrtFastMem_NV = PSA_TabUInt8ToSInt16(&CoStopStart_tabNvram_1[position]);
    position+= 2;
    /*CoStopStart_sNV_Z1_CST_8BIT_2.CoPtUH_stAftsRStrtSuc_NV = CoStopStart_tabNvram_1[position];   NOT WRITE*/  
    position++;
    /*CoStopStart_sNV_Z1_CST_8BIT_2.CoPtUH_stFbSpcFactRStrtSuc_NV = CoStopStart_tabNvram_1[position];   NOT WRITE*/
    position++;
    /*CoStopStart_sNV_Z1_CST_8BIT_2.CoReqRstrt_ctRstrtFail_NV = CoStopStart_tabNvram_1[position];   NOT WRITE*/
    position++;
    CoStopStart_sNV_Z1_CST_8BIT_3.DgoFct_noMemValHealLvl2_NV = CoStopStart_tabNvram_1[position];
    position++;
    /*CoStopStart_sNV_Z1_CST_BOOLEAN_1.MgtDrv_bDftHld_NV = CoStopStart_tabNvram_1[position];   NOT WRITE*/
    position++;    
    CoStopStart_sNV_Z1_CST_BOOLEAN_2.DgoFct_bMemValPrvtLvl1_NV = CoStopStart_tabNvram_1[position];
    position++;    
    CoStopStart_sNV_Z1_CST_BOOLEAN_2.DgoFct_bMemValHealLvl1_NV = CoStopStart_tabNvram_1[position];
    position++;
    
    CoReqRstrt_tiRStrtSlowMem_NV_init = 0; // Force runnable CoStopStart_004 to take the new value
	CoReqRstrt_nTDC2SlowMem_NV_init = 0; // Force runnable CoStopStart_004 to take the new value
	CoReqRstrt_nTDC1SlowMem_NV_init = 0; // Force runnable CoStopStart_004 to take the new value    
	CoReqRstrt_nTDC2FastMem_NV_init = 0; // Force runnable CoStopStart_004 to take the new value    
	CoReqRstrt_nTDC1FastMem_NV_init = 0; // Force runnable CoStopStart_004 to take the new value    
	CoReqRstrt_tiRStrtFastMem_NV_init = 0; // Force runnable CoStopStart_004 to take the new value
	CoReqRstrt_ctRStrtMem_NV_init = 0; // Force runnable CoStopStart_004 to take the new value
	DgoFct_noMemValHealLvl2_NV_init = 0; // Force runnable CoStopStart_016 to take the new value    
	DgoFct_bMemValPrvtLvl1_NV_init = 0; // Force runnable CoStopStart_016 to take the new value
	DgoFct_bMemValHealLvl1_NV_init = 0; // Force runnable CoStopStart_016 to take the new value
    
}

void RE_CoStopStart_AftsNvramReset_1()
{
    CoStopStart_sNV_Z1_CST_16BIT_1 = CoStopStart_sNV_Z1_CST_16BIT_1_r;
	// Force runnable CoStopStart_004 to take new values
	CoReqRstrt_tiRStrtSlowMem_NV_init = 0;
	CoReqRstrt_nTDC2SlowMem_NV_init = 0;
	CoReqRstrt_nTDC1SlowMem_NV_init = 0;
	CoReqRstrt_nTDC2FastMem_NV_init = 0;
	CoReqRstrt_nTDC1FastMem_NV_init = 0;
	CoReqRstrt_tiRStrtFastMem_NV_init = 0;
	CoReqRstrt_ctRStrtMem_NV_init = 0;  
}

#define COSTOPSTART_STOP_SEC_CODE
#include "CoStopStart_MemMap.h"


#endif
