/***************************************************************************
;**
;** FILE NAME      : ACQPWD.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef ACQPWD_H
#define ACQPWD_H

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

extern const uint32  Ext_PtNeutPWDTimeOutVal_C;
extern const uint16  CoFan_StFanPWDTimeOutVal_C;
extern const uint16  Ext_rCluPWDTimeOutVal_C;
extern const uint16  FuPmp_tiFuPmpPWDTimeOutVal_C;

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

void Clu_EveRst_CluPedFreqAcqPwd(void);
void Clu_SdlFast_CluPedFreqAcqPwd(void);
void CoFan_EveRst_CmdDiagCoFanAcqPwd(void);
void CoFan_SdlMid_CmdDiagCoFanAcqPwd(void);
void Ext_EveRst_AcqPwd(void);
void FuPmp_EveRst_PropFuPmpPwd(void);
void FuPmp_SdlSlow_PropFuPmpDiagPwd(void);
void Gear_EveRst_NeutPosnAcqPwd(void);
void Gear_SdlFast_NeutPosnAcqPwd(void);


#endif /* ACQPWD_H */

/*-------------------------------- end of file -------------------------------*/
