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
* %name: PSA_TL_LibC.c %
*
* %version: 1.4 %
*
* %date_modified: Wed Nov 21 11:40:33 2012 %
*
*
* %derived_by: u261238 %
* %release: Pack_Integrateur/5.0 %
* %full_filespec: PSA_TL_LibC.c-1.4:csrc:9 %
*
*******************************************************************************/

#include "PSA_TL_LibC.h"

#define CMAXUINT32 4294967295U
#define CMAXUINT16 65535U

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
Boolean PSALib_bBasculeRS(Boolean bSetIn, Boolean bRstIn, UInt8 *puiMemInOut)
{
  if(*puiMemInOut & 0x02){
	*puiMemInOut&=0x01;
  }
  else {
    *puiMemInOut = (UInt8)((!(bRstIn)) && (bSetIn || *puiMemInOut));
  }
  return (Boolean)(*puiMemInOut);
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
Boolean PSALib_bTurnOnDelay16(Boolean bCmdIn, UInt16 uiDelayIn, UInt16 *puiTimeInOut)
{
  if (bCmdIn) {
    if (*puiTimeInOut < CMAXUINT16) {
      *puiTimeInOut = *puiTimeInOut + 1;
    }
  }
  else {
    *puiTimeInOut = 0 /* 0. */;
  }
  return (Boolean)(bCmdIn && (*puiTimeInOut > uiDelayIn));
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
Boolean PSALib_bTurnOnDelay32(Boolean bCmdIn, UInt32 uiDelayIn, UInt32 *puiTimeInOut)
{
  if (bCmdIn) {
    if (*puiTimeInOut < CMAXUINT32) {
      *puiTimeInOut = *puiTimeInOut + 1;
    }
  }
  else {
    *puiTimeInOut = 0 /* 0. */;
  }
  return (Boolean)(bCmdIn && (*puiTimeInOut > uiDelayIn));
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
Boolean PSALib_bTurnOnDelayASY16(Boolean bCmdIn, UInt16 uiDelayIn, UInt16 uiSampleIn, UInt16 *puiTimeInOut)
{
  if (bCmdIn) {
    if (*puiTimeInOut <= CMAXUINT16-uiSampleIn) {
      *puiTimeInOut = *puiTimeInOut + uiSampleIn;
    }
    else {
      *puiTimeInOut = CMAXUINT16;
    }
  }
  else {
    *puiTimeInOut = 0 /* 0. */;
  }
  return (Boolean)(bCmdIn && (*puiTimeInOut > uiDelayIn));
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
Boolean PSALib_bTurnOnDelayASY32(Boolean bCmdIn, UInt32 uiDelayIn, UInt16 uiSampleIn, UInt32 *puiTimeInOut)
{
  if (bCmdIn) {
    if (*puiTimeInOut <= CMAXUINT32-uiSampleIn) {
      *puiTimeInOut = *puiTimeInOut + uiSampleIn;
    }
    else {
      *puiTimeInOut = CMAXUINT32;
    }
  }
  else {
    *puiTimeInOut = 0 /* 0. */;
  }
  return (Boolean)(bCmdIn && (*puiTimeInOut > uiDelayIn));
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
Boolean PSALib_bTurnOffDelay16(Boolean bCmdIn, UInt16 uiDelayIn, UInt16 *puiTimeInOut)
 {
  if (bCmdIn) {
    *puiTimeInOut = 0 /* 0. */;
  }
  else {
    if (*puiTimeInOut < CMAXUINT16) {
      *puiTimeInOut = *puiTimeInOut + 1;
    }
  }
  return (Boolean)(bCmdIn || (*puiTimeInOut <= uiDelayIn));
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
Boolean PSALib_bTurnOffDelay32(Boolean bCmdIn, UInt32 uiDelayIn, UInt32 *puiTimeInOut)
 {
  if (bCmdIn) {
    *puiTimeInOut = 0 /* 0. */;
  }
  else {
    if (*puiTimeInOut < CMAXUINT32) {
      *puiTimeInOut = *puiTimeInOut + 1;
    }
   }
  return (Boolean)(bCmdIn || (*puiTimeInOut <= uiDelayIn));
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
Boolean PSALib_bTurnOffDelayASY16(Boolean bCmdIn, UInt16 uiDelayIn, UInt16 uiSampleIn, UInt16 *puiTimeInOut)
{
 if (bCmdIn) {
    *puiTimeInOut = 0 /* 0. */;
  }
  else {
    if (*puiTimeInOut <= CMAXUINT16-uiSampleIn) {
      *puiTimeInOut = *puiTimeInOut + uiSampleIn;
    }
     else {
      *puiTimeInOut = CMAXUINT16;
    }
 }
  return (Boolean)(bCmdIn || (*puiTimeInOut <= uiDelayIn));
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
Boolean PSALib_bTurnOffDelayASY32(Boolean bCmdIn, UInt32 uiDelayIn, UInt16 uiSampleIn, UInt32 *puiTimeInOut)
{
 if (bCmdIn) {
    *puiTimeInOut = 0 /* 0. */;
  }
  else {
    if (*puiTimeInOut <= CMAXUINT32-uiSampleIn) {
      *puiTimeInOut = *puiTimeInOut + uiSampleIn;
    }
     else {
      *puiTimeInOut = CMAXUINT32;
    }
 }
  return (Boolean)(bCmdIn || (*puiTimeInOut <= uiDelayIn));
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
SInt32 PSALib_iFiltreT32(SInt32 iCmdIn, SInt32 iInitIn, UInt32 uiDelayIn, Boolean bRstIn, Boolean *pbFirstInOut, SInt32 *piSaveInOut)
{
  
  if (bRstIn) {
    *piSaveInOut = iInitIn ;
  }
  else {
    UInt16 uiFac1Low, uiFac2Low, uiFac1High, uiFac2High;
    UInt32 uiProdMid,uiProdLow,uiProdHigh;
    
    uiDelayIn = (UInt32) (2147483648 / (uiDelayIn + 1)); /* delay in [0 1] 2^-31*/
    if (*pbFirstInOut) {
       *piSaveInOut = iInitIn;
    }
    /* reuse of iCmdIn as temporary variable */
    /* loose 1 LSB to protect from overflow */
    iCmdIn = (iCmdIn >> 1) - ((*piSaveInOut) >> 1);

    /*64 bits multiplication*/
    uiFac1Low = (UInt16)(iCmdIn);
    uiFac2Low = (UInt16)uiDelayIn;
    uiFac1High = (UInt16) ( (UInt32)(iCmdIn) >> 16 );
    uiFac2High = (UInt16) ( uiDelayIn >> 16 );

    uiProdLow = (UInt32)uiFac1High * (UInt32)uiFac2Low;
    uiProdHigh = (UInt32)uiFac1High * (UInt32)uiFac2High;
    /* add the pieces */
    uiProdMid   = uiProdLow + (((UInt32)uiFac1Low * (UInt32)uiFac2Low)>>16);
    /* mid = uiProdMid + f1Lf2H */
    uiProdLow = uiProdMid + (UInt32)uiFac1Low * (UInt32)uiFac2High;
    if(uiProdLow < uiProdMid) uiProdHigh += 0x10000; /* high-part + carry */

    /* switch result to compensate the 2^-31 from delay and get back the 1LSB lost */
    if((iCmdIn)<0) {
    /* Booth-algorithm */
     iCmdIn = (SInt32)(((UInt32)((uiProdLow & 0x0000FFFF)>>14)) | ((UInt32)((SInt32)(uiProdHigh + (uiProdLow>>16))- uiDelayIn) << 2));
    }
    else{
     iCmdIn = (SInt32)(((UInt32)((uiProdLow & 0x0000FFFF)>>14)) | ((UInt32)((SInt32)(uiProdHigh + (uiProdLow>>16))       )  << 2));
    }
    *piSaveInOut = *piSaveInOut + iCmdIn;
  }
  if (*pbFirstInOut) {
    *pbFirstInOut=0;
    return iInitIn;
  }
  else {
    return *piSaveInOut;
  }
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
SInt32 PSALib_iFiltreTASY32(SInt32 iCmdIn, SInt32 iInitIn, UInt32 uiDelayIn, Boolean bRstIn, UInt16 uiSampleIn, Boolean *pbFirstInOut, SInt32 *piSaveInOut)
{
  
  if (bRstIn) {
    *piSaveInOut = iInitIn ;
  }
  else {
    UInt16 uiFac1Low, uiFac2Low, uiFac1High, uiFac2High;
    UInt32 uiProdMid,uiProdLow,uiProdHigh;
    
    uiDelayIn = (UInt32) (2147483648 / (uiDelayIn + uiSampleIn)); /* delay in [0 1] 2^-31*/
    uiDelayIn *= uiSampleIn;
    
    if (*pbFirstInOut) {
       *piSaveInOut = iInitIn;
    }
    /* reuse of iCmdIn as temporary variable */
    /* loose 1 LSB to protect from overflow */
    iCmdIn = (iCmdIn >> 1) - ((*piSaveInOut) >> 1);

    /*64 bits multiplication*/
    uiFac1Low = (UInt16)(iCmdIn);
    uiFac2Low = (UInt16)uiDelayIn;
    uiFac1High = (UInt16) ( (UInt32)(iCmdIn) >> 16 );
    uiFac2High = (UInt16) ( uiDelayIn >> 16 );

    uiProdLow = (UInt32)uiFac1High * (UInt32)uiFac2Low;
    uiProdHigh = (UInt32)uiFac1High * (UInt32)uiFac2High;
    /* add the pieces */
    uiProdMid   = uiProdLow + (((UInt32)uiFac1Low * (UInt32)uiFac2Low)>>16);
    /* mid = uiProdMid + f1Lf2H */
    uiProdLow = uiProdMid + (UInt32)uiFac1Low * (UInt32)uiFac2High;
    if(uiProdLow < uiProdMid) uiProdHigh += 0x10000; /* high-part + carry */

    /* switch result to compensate the 2^-31 from delay and get back the 1LSB lost */
    if((iCmdIn)<0) {
    /* Booth-algorithm */
     iCmdIn = (SInt32)(((UInt32)((uiProdLow & 0x0000FFFF)>>14)) | ((UInt32)((SInt32)(uiProdHigh + (uiProdLow>>16))- uiDelayIn) << 2));
    }
    else{
     iCmdIn = (SInt32)(((UInt32)((uiProdLow & 0x0000FFFF)>>14)) | ((UInt32)((SInt32)(uiProdHigh + (uiProdLow>>16))       )  << 2));
    }
    *piSaveInOut = *piSaveInOut + iCmdIn;
  }
  if (*pbFirstInOut) {
    *pbFirstInOut=0;
    return iInitIn;
  }
  else {
    return *piSaveInOut;
  }
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
SInt32 PSALib_iFiltreK32(SInt32 iCmdIn, SInt32 iInitIn, UInt16 uiCoefIn, Boolean bRstIn, Boolean *pbFirstInOut, SInt32 *piSaveInOut)
{
  if (bRstIn) {
    *piSaveInOut = iInitIn ;
  }
  else {
    UInt32 uiProdLow,uiProdHigh;

      if (*pbFirstInOut) {
       *piSaveInOut = iInitIn;
    }
    /* reuse iCmdIn as temporary variable */
    /* loose 1 LSB to protect from overflow */
    iCmdIn = (iCmdIn >> 1) - ((*piSaveInOut) >> 1);

  /* 64 bits multiplication */
  uiProdLow = (UInt32)((UInt16)iCmdIn) * (UInt32)uiCoefIn; /* convenient multiplication */
  uiProdHigh = ((UInt32)iCmdIn >> 16) * (UInt32)uiCoefIn + (uiProdLow>>16);
 
  /* switch result to compensate the 2^-15 from coef and get back the 1LSB lost */
  if(iCmdIn<0) {
  /* Booth-algorithm */
  iCmdIn = (SInt32)((((UInt32)( (uiProdHigh<<16) + (uiProdLow & 0x0000FFFF) )) >> 14) | (UInt32)((((SInt32)(uiProdHigh>>16)) - uiCoefIn)<< 18));
  }
  else {
  iCmdIn = (SInt32)((((UInt32)( (uiProdHigh<<16) + (uiProdLow & 0x0000FFFF) )) >> 14) | (UInt32)(uiProdHigh<<2));
  }
  
  *piSaveInOut = *piSaveInOut + iCmdIn;
  }
  if (*pbFirstInOut) {
    *pbFirstInOut=0;
    return iInitIn;
  }
  else {
    return *piSaveInOut;
  }
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
SInt32 PSALib_iRateLimiter32(SInt32 iCmdIn, SInt32 iInitIn, SInt32 iIncrIn, SInt32 iDecrIn, Boolean bEnableIn, SInt32 *piSavInOut, Boolean *pbFirstInOut)
{
  if (*pbFirstInOut) {
      *piSavInOut = iInitIn;
      *pbFirstInOut = 0;
  }
  else {
      
  }

  if (bEnableIn) {
    /* use iCmdIn as a temporary variable */
    iCmdIn = iCmdIn - (*piSavInOut);
    if (iCmdIn <= iDecrIn) {
      iCmdIn = iDecrIn;
    }
    if (iCmdIn > iIncrIn) {
      iCmdIn = iIncrIn;
    }
    *piSavInOut = (*piSavInOut) + iCmdIn;
  }
  else {
    *piSavInOut = iInitIn;
  }
   
  return *piSavInOut;
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt32 PSALib_uiTimerRst32(Boolean bStrtIn, UInt32 uiInitIn, Boolean bRstIn, Boolean *pbCmdOut, UInt32 *puiSaveInOut, Boolean *pbPrevStrtInOut)
{
  if (!(bRstIn)) {
    if (bStrtIn && (!(*pbPrevStrtInOut))) {
      *puiSaveInOut = uiInitIn;
    }
    else {
      if (*puiSaveInOut != 0){
        *puiSaveInOut = *puiSaveInOut - 1;
      }
    }
  }
  else {
    *puiSaveInOut = 0 /* 0. */;
  }
  *pbPrevStrtInOut = bStrtIn;
  *pbCmdOut = (Boolean)(*puiSaveInOut != 0);
  
  /* saturation ici pour etre isofonctionnel du simulink */
  if (uiInitIn < *puiSaveInOut) {
    *puiSaveInOut = uiInitIn;
  }
  return (*puiSaveInOut); 
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt16 PSALib_uiTimerRst16(Boolean bStrtIn, UInt16 uiInitIn, Boolean bRstIn, Boolean *pbCmdOut, UInt16 *puiSaveInOut, Boolean *pbPrevStrtInOut)
{
  if (!(bRstIn)) {
    if (bStrtIn && (!(*pbPrevStrtInOut))) {
      *puiSaveInOut = uiInitIn;
    }
    else {
      if (*puiSaveInOut != 0){
        *puiSaveInOut = *puiSaveInOut - 1;
      }
    }
  }
  else {
    *puiSaveInOut = 0 /* 0. */;
  }
  *pbPrevStrtInOut = bStrtIn;
  *pbCmdOut = (Boolean)(*puiSaveInOut != 0);
  
  /* saturation ici pour etre isofonctionnel du simulink */
  if (uiInitIn < *puiSaveInOut) {
    *puiSaveInOut = uiInitIn;
  }
  return (*puiSaveInOut); 
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt32 PSALib_uiTimerReset32(Boolean bStrtIn, UInt32 uiInitIn, Boolean bRstIn, Boolean *pbCmdOut, UInt32 *puiSaveInOut, Boolean *pbPrevStrtInOut)
{
  if (!(bRstIn)) {
    if (bStrtIn && (!(*pbPrevStrtInOut))) {
      *puiSaveInOut = uiInitIn;
    }
    else {
      if (*puiSaveInOut != 0){
        *puiSaveInOut = *puiSaveInOut - 1;
      }
    }
  }
  else {
    *puiSaveInOut = 0 /* 0. */;
  }
  *pbPrevStrtInOut = bStrtIn;
  *pbCmdOut = (Boolean)(*puiSaveInOut != 0);
  
  return (*puiSaveInOut); 
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt16 PSALib_uiTimerReset16(Boolean bStrtIn, UInt16 uiInitIn, Boolean bRstIn, Boolean *pbCmdOut, UInt16 *puiSaveInOut, Boolean *pbPrevStrtInOut)
{
  if (!(bRstIn)) {
    if (bStrtIn && (!(*pbPrevStrtInOut))) {
      *puiSaveInOut = uiInitIn;
    }
    else {
      if (*puiSaveInOut != 0){
        *puiSaveInOut = *puiSaveInOut - 1;
      }
    }
  }
  else {
    *puiSaveInOut = 0 /* 0. */;
  }
  *pbPrevStrtInOut = bStrtIn;
  *pbCmdOut = (Boolean)(*puiSaveInOut != 0);
  
  return (*puiSaveInOut); 
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt32 PSALib_uiTimerRstASY32(Boolean bStrtIn, UInt32 uiInitIn, Boolean bRstIn, UInt16 uiSampleIn, Boolean *pbCmdOut, UInt32 *puiSaveInOut, Boolean *pbPrevStrtInOut)
{
  if (!(bRstIn)) {
    if (bStrtIn && (!(*pbPrevStrtInOut))) {
      *puiSaveInOut = uiInitIn;
    }
    else {
      if (*puiSaveInOut >= uiSampleIn){
        *puiSaveInOut = *puiSaveInOut - uiSampleIn;
      }
      else {
        *puiSaveInOut = 0;
      }
    }
  }
  else {
    *puiSaveInOut = 0 /* 0. */;
  }
  *pbPrevStrtInOut = bStrtIn;
  *pbCmdOut = (Boolean)(*puiSaveInOut != 0);
  
  /* saturation ici pour etre isofonctionnel du simulink */
  if (uiInitIn < *puiSaveInOut) {
    *puiSaveInOut = uiInitIn;
  }
  return (*puiSaveInOut); 
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt16 PSALib_uiTimerRstASY16(Boolean bStrtIn, UInt16 uiInitIn, Boolean bRstIn, UInt16 uiSampleIn, Boolean *pbCmdOut, UInt16 *puiSaveInOut, Boolean *pbPrevStrtInOut)
{
  if (!(bRstIn)) {
    if (bStrtIn && (!(*pbPrevStrtInOut))) {
      *puiSaveInOut = uiInitIn;
    }
    else {
      if (*puiSaveInOut >= uiSampleIn){
        *puiSaveInOut = *puiSaveInOut - uiSampleIn;
      }
      else {
        *puiSaveInOut = 0;
      }
    }
  }
  else {
    *puiSaveInOut = 0 /* 0. */;
  }
  *pbPrevStrtInOut = bStrtIn;
  *pbCmdOut = (Boolean)(*puiSaveInOut != 0);
  
  /* saturation ici pour etre isofonctionnel du simulink */
  if (uiInitIn < *puiSaveInOut) {
    *puiSaveInOut = uiInitIn;
  }
  return (*puiSaveInOut); 
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt32 PSALib_uiTimerResetASY32(Boolean bStrtIn, UInt32 uiInitIn, Boolean bRstIn, UInt16 uiSampleIn, Boolean *pbCmdOut, UInt32 *puiSaveInOut, Boolean *pbPrevStrtInOut)
{
  if (!(bRstIn)) {
    if (bStrtIn && (!(*pbPrevStrtInOut))) {
      *puiSaveInOut = uiInitIn;
    }
    else {
      if (*puiSaveInOut >= uiSampleIn){
        *puiSaveInOut = *puiSaveInOut - uiSampleIn;
      }
      else {
        *puiSaveInOut = 0;
      }
    }
  }
  else {
    *puiSaveInOut = 0 /* 0. */;
  }
  *pbPrevStrtInOut = bStrtIn;
  *pbCmdOut = (Boolean)(*puiSaveInOut != 0);
  
  return (*puiSaveInOut); 
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt16 PSALib_uiTimerResetASY16(Boolean bStrtIn, UInt16 uiInitIn, Boolean bRstIn, UInt16 uiSampleIn, Boolean *pbCmdOut, UInt16 *puiSaveInOut, Boolean *pbPrevStrtInOut)
{
  if (!(bRstIn)) {
    if (bStrtIn && (!(*pbPrevStrtInOut))) {
      *puiSaveInOut = uiInitIn;
    }
    else {
      if (*puiSaveInOut >= uiSampleIn){
        *puiSaveInOut = *puiSaveInOut - uiSampleIn;
      }
      else {
        *puiSaveInOut = 0;
      }
    }
  }
  else {
    *puiSaveInOut = 0 /* 0. */;
  }
  *pbPrevStrtInOut = bStrtIn;
  *pbCmdOut = (Boolean)(*puiSaveInOut != 0);
  
  return (*puiSaveInOut); 
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt32 PSALib_uiCounter32(Boolean bEnaIn, Boolean bRstIn, UInt32 uiIncIn, UInt32 *puiSavInOut, Boolean *pbPrevRstInOut)
{
  if (bRstIn && (!(*pbPrevRstInOut))) {
    *puiSavInOut = 0 /* 0. */;
  }
  else {
    if (bEnaIn && (*puiSavInOut <= (CMAXUINT32-uiIncIn))) {
      *puiSavInOut =  *puiSavInOut + uiIncIn;
    }
  }
  *pbPrevRstInOut = bRstIn;
  return (*puiSavInOut);
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt16 PSALib_uiCounter16(Boolean bEnaIn, Boolean bRstIn, UInt16 uiIncIn, UInt16 *puiSavInOut, Boolean *pbPrevRstInOut)
{
  if (bRstIn && (!(*pbPrevRstInOut))) {
    *puiSavInOut = 0 /* 0. */;
  }
  else {
    if (bEnaIn && (*puiSavInOut <= (CMAXUINT16-uiIncIn))) {
      *puiSavInOut =  *puiSavInOut + uiIncIn;
    }
  }
  *pbPrevRstInOut = bRstIn;
  return (*puiSavInOut);
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt32 PSALib_uiIncCounter32(Boolean bEnaIn, Boolean bRstIn, UInt32 uiIncIn, UInt32 *puiSavInOut, UInt8 *puiPrevInInOut)
{
  if ((bRstIn && !(*puiPrevInInOut&0x01)) || ((*puiSavInOut <= uiIncIn) && bEnaIn && !(*puiPrevInInOut&0x02))){
    *puiSavInOut = 0 /* 0. */;
  }
  else {
    if (bEnaIn && (*puiSavInOut <= (CMAXUINT32-uiIncIn))) {
      *puiSavInOut =  *puiSavInOut + uiIncIn;
    }
  }
  *puiPrevInInOut = (UInt8)bRstIn+((UInt8)bEnaIn)*2;
  return (*puiSavInOut);
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
UInt16 PSALib_uiIncCounter16(Boolean bEnaIn, Boolean bRstIn, UInt16 uiIncIn, UInt16 *puiSavInOut, UInt8 *puiPrevInInOut)
{
  if ((bRstIn && !(*puiPrevInInOut&0x01)) || ((*puiSavInOut <= uiIncIn) && bEnaIn && !(*puiPrevInInOut&0x02))){
    *puiSavInOut = 0 /* 0. */;
  }
  else {
    if (bEnaIn && (*puiSavInOut <= (CMAXUINT16-uiIncIn))) {
      *puiSavInOut =  *puiSavInOut + uiIncIn;
    }
  }
  *puiPrevInInOut = (UInt8)bRstIn+((UInt8)bEnaIn)*2;
  return (*puiSavInOut);
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
Boolean PSALib_bHysPos32(SInt32 iCmdIn, SInt32 iLimLoIn, SInt32 iLimHiIn, Boolean *pbFirstInOut, Boolean *pbSaveInOut)
{
  if (*pbFirstInOut) {
    *pbFirstInOut = 0;
  }
  else {
    if (iLimLoIn < iLimHiIn) {
      *pbSaveInOut = (iCmdIn > iLimLoIn) && ((iCmdIn >= iLimHiIn) || (*pbSaveInOut));
    }
    else {
      *pbSaveInOut = (iCmdIn >= iLimLoIn);
    }
  }
  return (*pbSaveInOut);
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
Boolean PSALib_bHysNeg32(SInt32 iCmdIn, SInt32 iLimLoIn, SInt32 iLimHiIn, Boolean *pbFirstInOut, Boolean *pbSaveInOut)
{
  if (*pbFirstInOut) {
    *pbFirstInOut = 0;
  }
  else {
    if (iLimLoIn < iLimHiIn) {
      *pbSaveInOut = (iCmdIn < iLimHiIn) && ((iCmdIn <= iLimLoIn) || (*pbSaveInOut));
    }
    else {
      *pbSaveInOut = (iCmdIn <= iLimHiIn);
    }
  }
  return (*pbSaveInOut);
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
Boolean PSALib_bHysPos16(SInt16 iCmdIn, SInt16 iLimLoIn, SInt16 iLimHiIn, Boolean *pbFirstInOut, Boolean *pbSaveInOut)
{
  if (*pbFirstInOut) {
    *pbFirstInOut = 0;
  }
  else {
    if (iLimLoIn < iLimHiIn) {
      *pbSaveInOut = (iCmdIn > iLimLoIn) && ((iCmdIn >= iLimHiIn) || (*pbSaveInOut));
    }
    else {
      *pbSaveInOut = (iCmdIn >= iLimLoIn);
    }
  }
  return (*pbSaveInOut);
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
Boolean PSALib_bHysNeg16(SInt16 iCmdIn, SInt16 iLimLoIn, SInt16 iLimHiIn, Boolean *pbFirstInOut, Boolean *pbSaveInOut)
{
  if (*pbFirstInOut) {
    *pbFirstInOut = 0;
  }
  else {
    if (iLimLoIn < iLimHiIn) {
      *pbSaveInOut = (iCmdIn < iLimHiIn) && ((iCmdIn <= iLimLoIn) || (*pbSaveInOut));
    }
    else {
      *pbSaveInOut = (iCmdIn <= iLimHiIn);
    }
  }
  return (*pbSaveInOut);
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
SInt32 PSALib_iBaryCentre32(SInt32 iCmd1In, SInt32 iCmd2In, UInt16 uiCoefIn)
{
  UInt32 uiProdLow,uiProdHigh;
    
  /* reuse iCmd1In as temporary variable */
  /* loose 1 LSB to protect from overflow */
  iCmd1In = (iCmd1In >> 1) - (iCmd2In >> 1);
  /* 64 bits multiplication */
  uiProdLow = (UInt32)((UInt16)iCmd1In * (UInt32)uiCoefIn); /* convenient multiplication */
  uiProdHigh = ((UInt32)iCmd1In >> 16) * (UInt32)uiCoefIn + (uiProdLow>>16);
 
  /* switch result to compensate the 2^-15 from coef and get back the 1LSB lost */
  if(iCmd1In<0) {
  /* Booth-algorithm */
    return (SInt32)((((UInt32)( (uiProdHigh<<16) + (uiProdLow & 0x0000FFFF) )) >> 14) | (UInt32)((((SInt32)(uiProdHigh>>16)) - uiCoefIn)<< 18) ) + iCmd2In;
  }
  else {
    return (SInt32)((((UInt32)( (uiProdHigh<<16) + (uiProdLow & 0x0000FFFF) )) >> 14) | (UInt32)(uiProdHigh<<2)  ) + iCmd2In;
  }
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
SInt16 PSALib_iBaryCentre16(SInt16 iCmd1In, SInt16 iCmd2In, UInt16 uiCoefIn)
{
  return (SInt16) (((((SInt32)iCmd1In-(SInt32)iCmd2In)*(SInt32)uiCoefIn) >> 15) + iCmd2In);
}
#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"

/* PSALib_BasculeRS ajoutée pour assurer la compatibilite ascendante */
#define PSA_START_SEC_CODE_LIB
#include "PSA_MemMap.h"
void PSALib_BasculeRS(Boolean bSetIn, Boolean bRstIn, Boolean *pbQOut, Boolean *pbFirstInOut, Boolean *pbPrevQInOut)
{
  if (*pbFirstInOut) {
    *pbFirstInOut = 0;
 }
  else {
    *pbPrevQInOut = ((!(bRstIn)) && (bSetIn || *pbPrevQInOut));
  }
  *pbQOut = *pbPrevQInOut;
}

#define PSA_STOP_SEC_CODE_LIB
#include "PSA_MemMap.h"
