/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DE PSA PEUGEOT CITROEN
********************************************************************************
* NomFichier    : CoEmSTT_afts.c
* Auteur        : CLCO/CLO
* Creation      : 12-Mai-2011
*******************************************************************************/

#ifndef _CoEmSTT_AFTS_C_
#define _CoEmSTT_AFTS_C_

#include "Rte_Type.h"
#include "PSA_afts.h"
#include "CoEmSTT_nvm.h"
#include "Rte_CoEmSTT.h"

#define COEMSTT_START_SEC_CODE
#include "CoEmSTT_MemMap.h"

void RE_CoEmSTT_AftsNvramRead_1(CoEmSTT_tabNvram_Type1 CoEmSTT_tabNvram_1)
{
  UInt16 position = 0;
	
  PSA_UInt32ToTabUInt8((UInt32)CoEmSTT_sNV_Z1_CST_32BIT_1.CoEmSTT_ctBoostUcap_NV,&(CoEmSTT_tabNvram_1[position]));
  position += 4;
  
	CoEmSTT_tabNvram_1[position++] = (UInt8)CoEmSTT_sNV_Z1_CST_8BIT_1.CoEmSTT_iDevRstrt1_NV;
	CoEmSTT_tabNvram_1[position++] = (UInt8)CoEmSTT_sNV_Z1_CST_8BIT_1.CoEmSTT_uBattStrtMin1_NV;
	CoEmSTT_tabNvram_1[position++] = (UInt8)CoEmSTT_sNV_Z1_CST_8BIT_1.CoEmSTT_uBattStrtMin2_NV;
	CoEmSTT_tabNvram_1[position++] = (UInt8)CoEmSTT_sNV_Z1_CST_8BIT_1.CoEmSTT_uBattStrtMin3_NV;
	CoEmSTT_tabNvram_1[position++] = (UInt8)CoEmSTT_sNV_Z1_CST_8BIT_1.CoEmSTT_uBattStrtMin4_NV;
	CoEmSTT_tabNvram_1[position++] = (UInt8)CoEmSTT_sNV_Z1_CST_8BIT_1.CoEmSTT_uBattStrtMin5_NV;
	CoEmSTT_tabNvram_1[position++] = (UInt8)CoEmSTT_sNV_Z1_CST_8BIT_1.CoEmSTT_uBattStrtMin6_NV;
	CoEmSTT_tabNvram_1[position++] = (UInt8)CoEmSTT_sNV_Z1_CST_8BIT_1.CoEmSTT_uBattStrtMin7_NV;
	CoEmSTT_tabNvram_1[position++] = (UInt8)CoEmSTT_sNV_Z1_CST_8BIT_1.CoEmSTT_uBattStrtMin8_NV;
	CoEmSTT_tabNvram_1[position++] = (UInt8)CoEmSTT_sNV_Z1_CST_8BIT_1.CoEmSTT_uBattStrtMin9_NV;
	CoEmSTT_tabNvram_1[position++] = (UInt8)CoEmSTT_sNV_Z1_CST_8BIT_1.CoEmSTT_tiDevRstrt_NV;
	CoEmSTT_tabNvram_1[position++] = (UInt8)CoEmSTT_sNV_Z1_CST_8BIT_1.CoEmSTT_iDevRstrt2_NV;
}

void RE_CoEmSTT_AftsNvramWrite_1(CoEmSTT_tabNvram_Type1 CoEmSTT_tabNvram_1)
{
    UInt16 position = 0;

    CoEmSTT_sNV_Z1_CST_32BIT_1.CoEmSTT_ctBoostUcap_NV = PSA_TabUInt8ToUInt32(&(CoEmSTT_tabNvram_1[position]));
    position+= 4;
}

void RE_CoEmSTT_AftsNvramReset_1(void)
{
	CoEmSTT_sNV_Z1_CST_32BIT_1 = CoEmSTT_sNV_Z1_CST_32BIT_1_r;
	CoEmSTT_sNV_Z1_CST_16BIT_1 = CoEmSTT_sNV_Z1_CST_16BIT_1_r;
	CoEmSTT_sNV_Z1_CST_8BIT_1  = CoEmSTT_sNV_Z1_CST_8BIT_1_r;
}

#define COEMSTT_STOP_SEC_CODE
#include "CoEmSTT_MemMap.h"

#endif /*_CoEmSTT_AFTS_C_ */
