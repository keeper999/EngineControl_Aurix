/*******************************************************************************
* CE DOCUMENT EST LA PROPRIETE DES SOCIETES AUTOMOBILES PEUGEOT
* AUTOMOBILES CITROEN ET NE PEUT ETRE REPRODUIT OU COMMUNIQUE SANS
* L'AUTORISATION DE PSA PEUGEOT CITROEN
********************************************************************************
* NomFichier    : ProdElEm_afts.c
* Auteur        : CLCO/CLO
* Creation      : 11-Mai-2011
*******************************************************************************/

#ifndef _PRODELEM_AFTS_C_
#define _PRODELEM_AFTS_C_

#include "Rte_Type.h"
#include "ProdElEm_nvm.h"
#include "Rte_ProdElEm.h"
#include "Rte_ProdElEm.h"
#include "PSA_afts.h"

#define PRODELEM_START_SEC_CODE
#include "ProdElEm_MemMap.h"

Void RE_ProdElEm_AftsNvramReset_1()
{

	ProdElEm_sNV_Z1_CST_BOOLEAN_2=ProdElEm_sNV_Z1_CST_BOOLEAN_2_r;
	ProdElEm_sNV_Z1_CST_8BIT_2=ProdElEm_sNV_Z1_CST_8BIT_2_r;
	ProdElEm_sNV_Z1_CST_16BIT_2=ProdElEm_sNV_Z1_CST_16BIT_2_r;
	ProdElEm_sNV_Z1_CST_32BIT_2=ProdElEm_sNV_Z1_CST_32BIT_2_r;

}

void RE_ProdElEm_AftsNvramRead_1(ProdElEm_tabNvram_Type1 ProdElEm_tabNvram_1)
{
    /*
    Concerned structs :
    - [0..7] = ProdElEm_sNV_Z1_CST_32BIT_3
	- [8] = ProdElEm_sNV_Z1_CST_BOOLEAN_1
    */

    UInt16 position = 0;

    PSA_UInt32ToTabUInt8((UInt32)ProdElEm_sNV_Z1_CST_32BIT_3.BatMgt_tiBattSoCClcLrn_NV,&(ProdElEm_tabNvram_1[position]));
    position += 4;
    PSA_UInt32ToTabUInt8((UInt32)ProdElEm_sNV_Z1_CST_32BIT_3.BatMgt_rBattSocClc_NV,&(ProdElEm_tabNvram_1[position]));
    position += 4;
    ProdElEm_tabNvram_1[position++] = (UInt8)ProdElEm_sNV_Z1_CST_BOOLEAN_1.BatMgt_bBattSoCSub_NV;
}

void RE_ProdElEm_AftsNvramWrite_1(ProdElEm_tabNvram_Type1 ProdElEm_tabNvram_1)
{
    /*
    Concerned structs :
    - [0..7] = ProdElEm_sNV_Z1_CST_32BIT_3
	- [8] = ProdElEm_sNV_Z1_CST_BOOLEAN_1
    */
    UInt16 position = 0;

    ProdElEm_sNV_Z1_CST_32BIT_3.BatMgt_tiBattSoCClcLrn_NV = PSA_TabUInt8ToUInt32(&(ProdElEm_tabNvram_1[position]));
    position+= 4;
    ProdElEm_sNV_Z1_CST_32BIT_3.BatMgt_rBattSocClc_NV = PSA_TabUInt8ToUInt32(&(ProdElEm_tabNvram_1[position]));
    position+= 4;
    ProdElEm_sNV_Z1_CST_BOOLEAN_1.BatMgt_bBattSoCSub_NV = ProdElEm_tabNvram_1[position];
}

#define PRODELEM_STOP_SEC_CODE
#include "ProdElEm_MemMap.h"

#endif /*_PRODELEM_AFTS_C_ */
