/***************************************************************************
;**
;** FILE NAME      : FRT.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef FRT_H
#define FRT_H

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

Std_ReturnType FRunTime_GetTimer_100ms_U32(uint32* CurrentTime100msPtr);
Std_ReturnType FRunTime_GetTimer_100us_U32(uint32* CurrentTime100usPtr);
Std_ReturnType FRunTime_GetTimer_1min_U32(uint32* CurrentTime1minPtr);
Std_ReturnType FRunTime_GetTimer_1ms_U32(uint32* CurrentTime1msPtr);
Std_ReturnType FRunTime_GetTimer_1s_U32(uint32* CurrentTime1sPtr);
Std_ReturnType FRunTime_GetTimer100msU32(uint32* CurrentTime100msPtr);
Std_ReturnType FRunTime_GetTimer100usU32(uint32* CurrentTime100usPtr);
Std_ReturnType FRunTime_GetTimer1minU32(uint32* CurrentTime1minPtr);
Std_ReturnType FRunTime_GetTimer1msU32(uint32* CurrentTime1msPtr);
Std_ReturnType FRunTime_GetTimer1sU32(uint32* CurrentTime1sPtr);
void FRunTime_Init(void);
void FRunTime_SdlFast(void);
void FRunTime_SdlMid(void);
void FRunTime_SdlSlow(void);


#endif /* FRT_H */

/*-------------------------------- end of file -------------------------------*/
