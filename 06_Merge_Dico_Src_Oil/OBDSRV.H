/***************************************************************************
;**
;** FILE NAME      : OBDSRV.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef OBDSRV_H
#define OBDSRV_H

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

extern const uint8  Srv_bfMod9InfTypAvl_C;

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

void Srv_EveCrcChkEnd_ObdSrv(void);
Std_ReturnType OBDMODE1_Pid_00(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_03(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_04(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_05(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_06(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_07(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_0B(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_0C(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_0D(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_0E(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_0F(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_11(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_13(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_14(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_15(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_1C(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_1F(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_20(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_21(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_23(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_2E(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_30(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_31(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_33(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_3C(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_40(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_42(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_44(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_47(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_49(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_4A(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_4C(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_4D(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_4E(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_4F(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_50(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_60(uint8  *Data);
Std_ReturnType OBDMODE1_Pid_72(uint8  *Data);
Std_ReturnType OBDMODE1_Pid1F(uint8  *Data);
Std_ReturnType OBDMODE6(uint8  *Data);
Std_ReturnType OBDMODE9_Inftyp_00(uint8  *Data);
Std_ReturnType OBDMODE9_Inftyp_02(uint8  *Data);
Std_ReturnType OBDMODE9_Inftyp_08(uint8  *Data);
Std_ReturnType OBDMODE9_Inftyp_04(Dcm_OpStatusType OpStatus, uint8  *DataValueBuffer);


#endif /* OBDSRV_H */

/*-------------------------------- end of file -------------------------------*/
