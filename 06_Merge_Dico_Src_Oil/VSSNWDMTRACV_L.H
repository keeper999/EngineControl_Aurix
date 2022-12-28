/***************************************************************************
;**
;** FILE NAME      : VSSNWDMTRACV_L.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef VSSNWDMTRACV_L_H
#define VSSNWDMTRACV_L_H

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

extern const uint8  VSSNWDMTRACV_u8Inhib;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
extern boolean Ext_bDgoScg_VSSNwAcvReq;
extern boolean Ext_bDgoScp_VSSNwAcvReq;
extern boolean Ext_bMonRunScg_VSSNwAcvReq;
extern boolean Ext_bMonRunScp_VSSNwAcvReq;
extern boolean Ext_bVSSNwAcvAuth;
extern boolean Ext_bVSSNwAcvReq;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU2
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void VSSNWDMTRACV_vidCallMng(void);
void VSSNWDMTRACV_vidDiag(void);
void VSSNWDMTRACV_vidDMTR_AcvReq(void);
void VSSNWDMTRACV_vidDMTR_Cmd(void);
void VSSNWDMTRACV_vidInitOutput(void);


#endif /* VSSNWDMTRACV_L_H */

/*-------------------------------- end of file -------------------------------*/
