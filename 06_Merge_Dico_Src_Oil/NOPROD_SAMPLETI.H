/***************************************************************************
;**
;** FILE NAME      : NOPROD_SAMPLETI.H
;**
;** FILE AUTHOR    : ynicaise (VEES)
;**
;**************************************************************************/

#ifndef NOPROD_SAMPLETI_H
#define NOPROD_SAMPLETI_H

#include "MATHSRV_Portability.h"
#include "RTE_TYPE.h"
#include "STD_Types.h"
/*-------------------------------------------------------------------------
    Defines
-------------------------------------------------------------------------*/

#define AC_SampleTiMid_SC                 100
#define AccP_SampleTiMid_SC               40
#define AccP_SampleTiSlow_SC              100
#define AirPres_SampleTiFast_SC           10
#define AirPres_SampleTiMid_SC            40
#define AirPres_SampleTiSlow_SC           100
#define CAN_SampleTi50ms_SC               50
#define Can_SampleTiMid_SC                100
#define CatMon_SampleTiFast_SC            1
#define CatMon_SampleTiMid_SC             1
#define CatMon_SampleTiSlow_SC            1
#define Cf_SampleTiSlow_SC                1000
#define Clu_SampleTiFast_SC               10
#define Clu_SampleTiMid_SC                20
#define Clu_SampleTiSlow_SC               4000
#define CoFan_SampleTiMid_SC              100
#define CoT_SampleTiMid_SC                200
#define CoT_SampleTiSlow_SC               1000
#define Cstr_SampleTiFast_SC              20
#define Cstr_SampleTiSlow_SC              1000
#define DmpVlv_SampleTiFast_SC            10
#define EcuSt_SampleTiFast_SC             10
#define EcuSt_SampleTiMid_SC              40
#define EcuSt_SampleTiSlow_SC             1000
#define EngSt_SampleTiFast_SC             10
#define EngSt_SampleTiMid_SC              100
#define EngSt_SampleTiSlow_SC             1000
#define Flex_SampleTiFast_SC              20
#define Fu_SampleTiFast_SC                20
#define Fu_SampleTiMid_SC                 100
#define FuPmp_SampleTiFast_SC             20
#define FuPmp_SampleTiMid_SC              40
#define FuSysM_tiSampleSlow_SC            1000
#define Gear_SampleTiMid_SC               40
#define HeatSenO2_SampleTiFast_SC         25
#define HeatSenO2_SampleTiMid_SC          100
#define HeatSenO2_SampleTiSlow_SC         1000
#define IgCmd_SampleTiFast_SC             10
#define IgLim_SampleTiMid_SC              20
#define IgSys_SampleTiMid_SC              128
#define Inj_SampleTiFast_SC               10
#define InjCrk_SampleTiFast_SC            10
#define InjCtl_SampleTiFast_SC            10
#define InjCtl_SampleTiMid_SC             100
#define InjCtl_SampleTiSlow_SC            1000
#define KnkTreat_SampleTiFast_SC          10
#define KnkTreat_SampleTiMid_SC           20
#define KnkTreat_SampleTiSlow_SC          100
#define Misf_SampleTiFast_SC              20
#define Misf_SampleTiMid_SC               40
#define Misf_SampleTiSlow_SC              200
#define MisfFaiCtr_SampleTiSlow_SC        100
#define Mux_SampleTiMid_SC                100
#define Oil_SampleTiFast_SC               10
#define Oil_SampleTiMid_SC                10
#define OilSys_SampleTiMid_SC             100
#define PFuCtl_tiSampleMid_SC             40
#define PwrRly_SampleTiSlow_SC            200
#define Rly_SampleTiFast_SC               40
#define RlyPwr_SampleTiFast_SC            40
#define RlyPwr_SampleTiMid_SC             40
#define RlyPwr_SampleTiSlow_SC            200
#define SenO2Ds_SampleTiFast_SC           2.5
#define SenO2Ds_SampleTiMid_SC            10
#define SenO2Ds_SampleTiSlow_SC           40
#define SftyMgt_SampleTiMid_SC            40
#define SftyMgt_tiSdlTqLoss_SC            40
#define Srv_SampleTiFast_SC               20
#define Srv_SampleTiMid_SC                50
#define SrvRc_SampleTiMid_SC              50
#define StraMon_SampleTiMid_SC            40
#define Strtr_SampleTiMid_SC              10
#define STT_SampleTiFast_SC               10
#define Sync_SampleTiMid_SC               10
#define Sync_SampleTiSlow_SC              40
#define ThMgt_ECTSampleTiMid_SC           100
#define ThMgt_SampleTiMid_SC              100
#define Thr_SampleTiMid_SC                10
#define TqSys_SampleTiFast_SC             5
#define TrbWaPmp_SampleTiSlow_SC          1000
#define VehSpd_SampleTiFast_SC            10
#define VehSpd_SampleVSTop_SC             5
#define VlvAct_SampleTiFast_SC            10
#define VlvActEx_SampleTiFast_SC          10
#define VlvActEx_SampleTiSlow_SC          4000
#define VlvActIn_SampleTiFast_SC          10
#define VlvActIn_SampleTiSlow_SC          4000
#define Volt_SampleTiFast_SC              10

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

extern const boolean  Ext_bPresAltMgt_SC;

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



#endif /* NOPROD_SAMPLETI_H */

/*-------------------------------- end of file -------------------------------*/
