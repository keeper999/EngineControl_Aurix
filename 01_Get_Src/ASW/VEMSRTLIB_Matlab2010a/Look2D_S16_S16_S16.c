/***************************** <AUTO_FILE_HEADER> *****************************/
/*                                                                            */
/* !Layer           : SRV                                                     */
/*                                                                            */
/* !Component       : VemsRtLib                                               */
/* !Description     : Shared utilities provided by TMW                        */
/*                                                                            */
/* !Module          : Look2D_S16_S16_S16                                      */
/*                                                                            */
/* !File            : Look2D_S16_S16_S16.c                                    */
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
/*   Code generated on: Thu Mar 24 19:49:03 2011                              */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/ACT_EMS/LOG/REF/SWC_VEMS/VEMSRTLIB/Matlab2010a/Look2D_S16_$*/
/* $Revision::   1.1                                                         $*/
/* $Author::   ADELVARE                               $$Date::   25 Mar 2011 $*/
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
/* !Comment: Define code in section "SEC_CODE_LIB" */
#define VemsRtLib_START_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*********************************************************************
 * Lookup 2D Lookup Utility Look2D_S16_S16_S16
 */
void Look2D_S16_S16_S16( SInt16 *pY, const SInt16 *pYData, SInt16 u0, const
  SInt16 *pU0Data, UInt32 iHiU0, SInt16 u1, const SInt16 *pU1Data, UInt32
  iHiU1)
{
  UInt32 iLeftU0, iRghtU0, iLeftU1, iRghtU1;
  BINARYSEARCH_S16( &(iLeftU0), &(iRghtU0), u0, pU0Data, iHiU0);
  BINARYSEARCH_S16( &(iLeftU1), &(iRghtU1), u1, pU1Data, iHiU1);

  {
    SInt16 u0Left = pU0Data[iLeftU0];
    SInt16 u0Rght = pU0Data[iRghtU0];
    SInt16 u1Left = pU1Data[iLeftU1];
    SInt16 u1Rght = pU1Data[iRghtU1];
    SInt16 yTemp;
    SInt16 yLeftLeft;
    SInt16 yLeftRght;
    SInt16 yRghtLeft;
    SInt16 yRghtRght;
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
    INTERPOLATE_S16_S16( pY, yLeftLeft, yLeftRght, u1, u1Left, u1Rght);

    /* Interpolate along U1 variable
     *    with the u0 variable locked on the right u0
     */
    INTERPOLATE_S16_S16( (&(yTemp)), yRghtLeft, yRghtRght, u1, u1Left, u1Rght);

    /*
     * Interpolate along u0 variable
     *    with the u1 variable locked on its interpolated value
     */
    INTERPOLATE_S16_S16( pY, (*pY), yTemp, u0, u0Left, u0Rght);
  }
}

/* end function Look2D_S16_S16_S16
 *********************************************************************/
#define VemsRtLib_STOP_SEC_CODE_LIB
#include "VemsRtLib_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
