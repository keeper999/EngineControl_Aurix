/***************************************************************************
;**
;** FILE NAME      : REFIDETA.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef REFIDETA_H
#define REFIDETA_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define REF_IDENT_ETAL_LONGUEUR           10
#define REF_IDENT_ETAL_LONGWITHCRC        12
#define WAIT_GET_STATUS                   1
#define WAIT_WRITE_STATUS                 2
#define WAIT_WRITING                      4

/*-------------------------------------------------------------------------
    Typedef
-------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------
    Enums
-------------------------------------------------------------------------*/

/* enum st34 */
/*extern uint8 Srv_stRefidetaWrChck;*/


/*-------------------------------------------------------------------------
    Calibrations
-------------------------------------------------------------------------*/
#pragma section ".calib" a

extern const boolean  Manu_inh_ref_ident_etal;

#pragma section
/*-------------------------------------------------------------------------
    Variables
-------------------------------------------------------------------------*/

#define MEMSEC_START_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
extern uint8 Srv_stRefidetaWrChck;
extern boolean Srv_bDgoInv_CalId;
extern uint8 Ref_ident_etal_ecriture_status;
#define MEMSEC_STOP_SEC_VAR_UNSPECIFIED_CPU1
#include "MemMap.h"
/*-------------------------------------------------------------------------
    Porteurs de bits
-------------------------------------------------------------------------*/


/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

void REFIDETA_Init(void);
void REFIDETA_sdlFast(void);
void Srv_EveRst_RefIdEta(void);
void Srv_SdlFast_RefIdEta(void);
Std_ReturnType REFIDETA_ReadData_Obd(Dcm_OpStatusType OpStatus, uint8  *Data);
Std_ReturnType REFIDETA_ReadData_Uds(Dcm_OpStatusType OpStatus, uint8  *Data);
Std_ReturnType REFIDETA_ReadDataLength(uint16  *DataLength);
Std_ReturnType REFIDETA_CheckCondition(Dcm_NegativeResponseCodeType  *ErrorCode);
Std_ReturnType REFIDETA_WriteData(uint8  *Data, uint16 DataLength, Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType  *ErrorCode);
Std_ReturnType REFIDETA_ConditionCheck_ReadData(Dcm_OpStatusType OpStatus, Dcm_NegativeResponseCodeType  *ErrorCode);


#endif /* REFIDETA_H */

/*-------------------------------- end of file -------------------------------*/
