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
* %name: PSA_afts.c %
*
* %version: 4.2 %
*
* %date_modified: Fri Aug 12 13:32:03 2011 %
*
*
* %derived_by: u152920 %
* %release: Pack_Integrateur/4.0 %
* %full_filespec: PSA_afts.c-4.2:csrc:1 %
*
*******************************************************************************/

/*******************************************************************************
* Description : Fonctions pour l'APV
* Auteur      : CLO
*******************************************************************************/

#ifndef _PSA_AFTS_C_
#define _PSA_AFTS_C_

#include "PSA_afts.h"
#include "dsfxp.h"
#include "Rte_Type.h"

#define BITS24 16777216
#define BITS16 65536
#define BITS8 256

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"

void PSA_UInt32ToTabUInt8 (UInt32 Var32, UInt8 *Tab8)
{
    Tab8[0] = Var32/BITS24;
    Tab8[1] = (Var32/BITS16)%BITS8;
    Tab8[2] = (Var32/BITS8)%BITS8;
    Tab8[3] = Var32%BITS8;
}


void PSA_UInt16ToTabUInt8 (UInt16 Var16, UInt8 *Tab8)
{
    Tab8[0] = Var16/BITS8;
    Tab8[1] = Var16%BITS8;
}


UInt32 PSA_TabUInt8ToUInt32 (UInt8 *Tab8)
{
    UInt32 Var32;
    Var32 = Tab8[3] +(Tab8[2]*BITS8) +(Tab8[1]*BITS16) + (Tab8[0]*BITS24);
    return Var32;
}


UInt16 PSA_TabUInt8ToUInt16 (UInt8 *Tab8)
{
    UInt16 var16;
    var16 = Tab8[1] + (Tab8[0]*BITS8);
    return var16;
}


SInt16 PSA_TabUInt8ToSInt16 (UInt8 *Tab8)
{
    SInt16 var16;
    var16 = Tab8[1] + (Tab8[0]*BITS8);
    return var16;
}


SInt32 PSA_TabUInt8ToSInt32 (UInt8 *Tab8)
{
    SInt32 var32;
    var32 = Tab8[3] + (Tab8[2]*BITS8) + (Tab8[1]*BITS16) + (Tab8[0]*BITS24);
    return var32;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#endif/*_PSA_AFTS_C_ */

