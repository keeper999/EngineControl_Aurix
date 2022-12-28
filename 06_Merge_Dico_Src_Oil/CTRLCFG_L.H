/***************************************************************************
;**
;** FILE NAME      : CTRLCFG_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef CTRLCFG_L_H
#define CTRLCFG_L_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const uint8  CTRLCFG_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void CTRLCFG_vidBrkUCFrame(void);
void CTRLCFG_vidBrkUCFrame2(void);
void CTRLCFG_vidBSIFrame(void);
void CTRLCFG_vidBSIFrame2(void);
void CTRLCFG_vidBSIFrame3(void);
void CTRLCFG_vidBSIFrame4(void);
void CTRLCFG_vidBSIFrame5(void);
void CTRLCFG_vidCluFrames(void);
void CTRLCFG_vidCtrlCfg(void);
void CTRLCFG_vidCtrlCfg2(void);
void CTRLCFG_vidECUFrames(void);
void CTRLCFG_vidECUFrames2(void);
void CTRLCFG_vidECUFrames3(void);
void CTRLCFG_vidFrameCfg(void);
void CTRLCFG_vidFrameCfg2(void);
void CTRLCFG_vidFrameCfg3(void);
void CTRLCFG_vidGearBoxFrame(void);
void CTRLCFG_vidOther_Frames_Param(void);
void CTRLCFG_vidPSFrames(void);


#endif /* CTRLCFG_L_H */

/*-------------------------------- end of file -------------------------------*/
