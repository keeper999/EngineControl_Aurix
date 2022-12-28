/***************************************************************************
;**
;** FILE NAME      : OBDSRV06.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef OBDSRV06_H
#define OBDSRV06_H

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

extern const boolean  Manu_inh_mode_6_scantool;
extern const boolean  Manu_inh_obdmid_01;
extern const boolean  Manu_inh_obdmid_02;
extern const boolean  Manu_inh_obdmid_21;
extern const boolean  Manu_inh_obdmid_41;
extern const boolean  Manu_inh_obdmid_42;
extern const boolean  Manu_inh_obdmid_A2;
extern const boolean  Manu_inh_obdmid_A3;
extern const boolean  Manu_inh_obdmid_A4;
extern const boolean  Manu_inh_obdmid_A5;
extern const boolean  Mode_6_obdmid_21_tid_81;
extern const boolean  Mode_6_obdmid_41_tid_D0;
extern const boolean  Mode_6_obdmid_42_tid_DA;
extern const boolean  Mode_6_obdmid_A2_tid_0B;
extern const boolean  Mode_6_obdmid_A2_tid_0C;
extern const boolean  Mode_6_obdmid_A3_tid_0B;
extern const boolean  Mode_6_obdmid_A3_tid_0C;
extern const boolean  Mode_6_obdmid_A4_tid_0B;
extern const boolean  Mode_6_obdmid_A4_tid_0C;
extern const boolean  Mode_6_obdmid_A5_tid_0B;
extern const boolean  Mode_6_obdmid_A5_tid_0C;
extern const uint8  Mode_6_s1_01_data_a;
extern const uint8  Mode_6_s1_01_data_b;
extern const uint8  Mode_6_s1_81_data_d;
extern const uint8  Mode_6_s1_A1_data_a;
extern const uint8  Mode_6_s2_01_data_a;
extern const uint8  Mode_6_s2_A1_data_d;
extern const uint8  Mode_6_s2_C1_data_a;

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

void OBDSRV06_NVMSRV_vidInit(void);
void Srv_EvePwrl_ObdSrv06(void);
void Srv_EveRst_ObdSrv06(void);
void Srv_EveRstDft_ObdSrv06(void);
void Srv_EveRstDftObd_ObdSrv06(void);
void Srv_SdlMid_ObdSrv06(void);
Std_ReturnType GetDTRValue_OBDMID01_TID01(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType GetDTRValue_OBDMID01_TID02(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType GetDTRValue_OBDMID01_TID03(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType GetDTRValue_OBDMID01_TID04(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType GetDTRValue_OBDMID01_TID07(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType GetDTRValue_OBDMID01_TID08(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType GetDTRValue_OBDMID01_TID0A(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType GetDTRValue_OBDMID01_TIDA0(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType GetDTRValue_OBDMID01_TIDA1(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType GetDTRValue_OBDMID02_TID01(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType GetDTRValue_OBDMID02_TID02(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType GetDTRValue_OBDMID02_TID03(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType GetDTRValue_OBDMID02_TID04(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType GetDTRValue_OBDMID02_TID07(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType GetDTRValue_OBDMID02_TID08(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType GetDTRValue_OBDMID02_TIDC0(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType GetDTRValue_OBDMID02_TIDC1(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType GetDTRValue_OBDMID02_TIDC2(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType GetDTRValue_OBDMID21_TID81(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType GetDTRValue_OBDMID41_TIDD0(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType GetDTRValue_OBDMID42_TIDDA(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType GetDTRValue_OBDMIDA2_TID0B(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType GetDTRValue_OBDMIDA2_TID0C(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType GetDTRValue_OBDMIDA3_TID0B(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType GetDTRValue_OBDMIDA3_TID0C(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType GetDTRValue_OBDMIDA4_TID0B(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType GetDTRValue_OBDMIDA4_TID0C(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType GetDTRValue_OBDMIDA5_TID0B(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);
Std_ReturnType GetDTRValue_OBDMIDA5_TID0C(Dcm_OpStatusType OpStatus, uint16  *Testval, uint16  *Minlimit, uint16  *Maxlimit, Dcm_DTRStatusType  *Status);


#endif /* OBDSRV06_H */

/*-------------------------------- end of file -------------------------------*/
