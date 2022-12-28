/***************************************************************************
;**
;** FILE NAME      : FRM.H
;**
;** FILE AUTHOR    : lthibau (VEES)
;**
;**************************************************************************/

#ifndef FRM_MACRO_H
#define FRM_MACRO_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
#include "GD.h"
#include "GD_api.h"
#include "GDFRM.h"
#include "GDFRMDEF.h"
#include "FRM_21.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/
#define FRM_vidF01_PrmDft_Init_opt(u16Index,u8StatusOld,u8Status)\
{\
   boolean             bLocalGDUDft;\
   boolean             bLocalMajDft;\
   boolean             bLocalGDUDftOld;\
   boolean             bLocalTemp_0;\
   uint16              u16localLDIndex;\
\
   bLocalGDUDft = GD_bBitRead(u8Status,0);\
   bLocalGDUDftOld = GD_bBitRead(u8StatusOld,0);\
\
   bLocalMajDft = 0;\
   if  (  (bLocalGDUDft == TRUE)\
       && (bLocalGDUDftOld == FALSE))\
   {\
      FRM_au8DU[u16Index] = FRM_u8SNG_DFT_TRUE;\
      bLocalMajDft = 1;\
   }\
   else\
   {\
      if (  (bLocalGDUDft == FALSE)\
         && (bLocalGDUDftOld == TRUE))\
      {\
         FRM_au8DU[u16Index] = FRM_u8SNG_DFT_FALSE;\
         bLocalMajDft = 1;\
      }\
   }\
\
   u16localLDIndex = FRM_u16convDftIdtoLDId(u16Index);\
   if (  (bLocalMajDft == 1)\
	  && (u16localLDIndex != FRM_INVALID_LD_ID))\
   {\
      bLocalTemp_0 = FRM_abDftTypCc_NameVar[u16localLDIndex];\
      if (TRUE == FRM_abAuthTypCc_NameVar_C[u16localLDIndex])\
      {\
         FRM_avidF02_FidMng_F01_FRM_RawDft[u16localLDIndex]();\
      }\
      else\
      {\
         FRM_abDftTypCc_NameVar[u16localLDIndex] = FALSE;\
      }\
\
      if (bLocalTemp_0 != FRM_abDftTypCc_NameVar[u16localLDIndex])\
      {\
         FRM_vidF02_FidMng_F02_AcvTable(u16localLDIndex);\
      }\
   }\
}\

#define Fim_DemTriggerOnEventStatus_opt(u16DftIdx,u8StatusOld,u8Status)\
{\
   FRM_vidF01_PrmDft_Init_opt(u16DftIdx, u8StatusOld, u8Status);\
}

#endif /* FRM_MACRO_H */

/*-------------------------------- end of file -------------------------------*/
