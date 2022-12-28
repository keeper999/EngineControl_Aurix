/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : Look2D_S8_S8_S8                                         */
/*                                                                            */
/* !File            : Look2D_S8_S8_S8.c                                       */
/*                                                                            */
/* !Target          : All (optimized for "Generic->Custom")                   */
/*                                                                            */
/* !Vendor          : Valeo                                                   */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/* Autocoding Information                                                     */
/*   Tool             : RTW-EC 7.5  (R2010a)  25-Jan-2010                     */
/*   CodeGen toolbox  : version 003                                           */
/*   Code generated on: Wed Oct 13 14:57:22 2010                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/Look2D_S8_S$*/
/* $Revision::   1.0                                                         $*/
/* $Author::   ADELVARE                               $$Date::   13 Oct 2010 $*/
/******************************************************************************/
/* !CompReq : FLOAT                                                           */
/******************************************************************************/
#include "rtwtypes.h"
#include "rtw_shared_utils.h"

/******************************************************************************/
/* Check that Conditionnal Compilation options are defined                    */
/******************************************************************************/
/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS DEFINITION                                                       */
/******************************************************************************/
#define VemsRtLib_START_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*********************************************************************
 * Lookup 2D Lookup Utility Look2D_S8_S8_S8
 */
void Look2D_S8_S8_S8( SInt8 *pY, const SInt8 *pYData, SInt8 u0, const SInt8 *
                     pU0Data, UInt32 iHiU0, SInt8 u1, const SInt8 *pU1Data,
                     UInt32 iHiU1)
{
  UInt32 iLeftU0, iRghtU0, iLeftU1, iRghtU1;
  BINARYSEARCH_S8( &(iLeftU0), &(iRghtU0), u0, pU0Data, iHiU0);
  BINARYSEARCH_S8( &(iLeftU1), &(iRghtU1), u1, pU1Data, iHiU1);

  {
    SInt8 u0Left = pU0Data[iLeftU0];
    SInt8 u0Rght = pU0Data[iRghtU0];
    SInt8 u1Left = pU1Data[iLeftU1];
    SInt8 u1Rght = pU1Data[iRghtU1];
    SInt8 yTemp;
    SInt8 yLeftLeft;
    SInt8 yLeftRght;
    SInt8 yRghtLeft;
    SInt8 yRghtRght;
    iHiU0++;
    iLeftU1 *= iHiU0;
    iRghtU1 *= iHiU0;
    yRghtLeft = pYData[(iRghtU0+iLeftU1)];
    yRghtRght = pYData[(iRghtU0+iRghtU1)];
    yLeftLeft = pYData[(iLeftU0+iLeftU1)];
    yLeftRght = pYData[(iLeftU0+iRghtU1)];

    /* Interpolate along U1 variable
     *    with the u0 variable locked on the left u0
     */
    INTERPOLATE_S8_S8( pY, yLeftLeft, yLeftRght, u1, u1Left, u1Rght);

    /* Interpolate along U1 variable
     *    with the u0 variable locked on the right u0
     */
    INTERPOLATE_S8_S8( (&(yTemp)), yRghtLeft, yRghtRght, u1, u1Left, u1Rght);

    /*
     * Interpolate along u0 variable
     *    with the u1 variable locked on its interpolated value
     */
    INTERPOLATE_S8_S8( pY, (*pY), yTemp, u0, u0Left, u0Rght);
  }
}

/* end function Look2D_S8_S8_S8
 *********************************************************************/
#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
