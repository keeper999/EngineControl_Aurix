
#ifndef _COSTOPSTART_CALIBRATIONS_C_
#define _COSTOPSTART_CALIBRATIONS_C_

/*----------------------------------------------------------------------------*\
  DEFINES (OPT)
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  INCLUDES
\*----------------------------------------------------------------------------*/
#include "CoStopStart_calibrations.h"
/*----------------------------------------------------------------------------*\
  DEFINES
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  TYPEDEFS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  ENUMS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  VARIABLES
\*----------------------------------------------------------------------------*/

#define COSTOPSTART_START_SEC_CALIB_16BIT
#include "CoStopStart_MemMap.h"
/******************************************************************************\
   AR_MERGEABLE_CALIB_16BIT: Mergeable Calib 16 bits for AUTOSAR modules | Width: 16
\******************************************************************************/
AR_MERGEABLE_CALIB_16BIT UInt16 MonDrv_rCluPMinRstrt_C = 1200 /* 75. */ /* 
   Unit       : %
   Description: Position_embrayage_redem_PM
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 100 */;
   
AR_MERGEABLE_CALIB_16BIT UInt16 MonDrv_rCluPMaxStop_C = 400 /* 25. */ /* 
   Unit       : %
   Description: Position_embrayage_Stop_PM
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 100 */;
   
AR_MERGEABLE_CALIB_16BIT UInt16 MonGB_tiMAPToutGc_C = 10 /* 1. */ /* 
   Unit       : s
   Description: Temps à partir du quel le changement de rapport MAP est défini comme trop long.
   LSB: 0.1 OFF:  0 MIN/MAX:  0 .. 60 */;
   
#define COSTOPSTART_STOP_SEC_CALIB_16BIT
#include "CoStopStart_MemMap.h"

#define COSTOPSTART_START_SEC_CALIB_8BIT
#include "CoStopStart_MemMap.h"

/******************************************************************************\
   AR_MERGEABLE_CALIB_8BIT: Mergeable Calib 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
AR_MERGEABLE_CALIB_8BIT UInt8 CoRStrt_spdRstrtAuth_C = 3 /* 
   Unit       : km/h
   Description: Seuil de vitesse redémarrage chaine de traction fermée
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 50 */;
   
AR_MERGEABLE_CALIB_8BIT UInt8 CoRStrt_stModInhSpdVehCoPtUH_C = 0 /* 
   Description: Mode pour traiter signal logique reconfiguration demandant d'ignorer la vitesse véhi
   cule
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;
   
AR_MERGEABLE_CALIB_8BIT UInt8 MgtDrv_stModPush_C = 0 /* 
   Description: Mode pour traiter signal logique Push
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;
   
AR_MERGEABLE_CALIB_8BIT UInt8 CoStop_stModInhStopCoPtUH_C = 0 /* 
   Description: Mode pour traiter signal logique reconfiguration demandant inhibition des stops
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;
   
AR_MERGEABLE_CALIB_8BIT UInt8 CoRStrt_stModAcvRstrtCoPtUH_C = 0 /* 
   Description: Mode pour traiter signal logique reconfiguration type 2.1 (redémarrage normal)
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;
   
AR_MERGEABLE_CALIB_8BIT UInt8 CoRStrt_stModAcvFastRstrt_C = 0 /* 
   Description: Mode pour traiter signal logique reconfiguration type 2.2 (redémarrage urgent)
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;
   
AR_MERGEABLE_CALIB_8BIT UInt8 CoCut_stModAcvCutTotCoPtUH_C = 0 /* 
   Description: Mode pour traiter signal logique reconfiguration demandant coupure totale
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;
   
AR_MERGEABLE_CALIB_8BIT UInt8 CoCut_stModAcvCutCoPtUH_C = 0 /* 
   Description: Mode pour traiter signal logique reconfiguration demandant la coupure
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;
   
AR_MERGEABLE_CALIB_8BIT UInt8 CoStop_stModSftyInhStopCoPtUH_C = 0 /* 
   Description: Mode pour traiter signal logique Reconfiguration par le niveau 2 inhibant le stop
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;

AR_MERGEABLE_CALIB_8BIT UInt8 MonVeh_spdCluClsRstrtReq_C = 20 /* 20 */ /*
   Unit       : kmh
   Description: Seuil besoin vitesse BVM, CDT fermée
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 50 */;

AR_MERGEABLE_CALIB_8BIT UInt8 MonGB_stModAMTStopAuth_C = 0 /* 
   Description: Traitement booléen pour traiter signal logique autorisation de stop BVMP
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;   
   
#define COSTOPSTART_STOP_SEC_CALIB_8BIT
#include "CoStopStart_MemMap.h"

#define COSTOPSTART_START_SEC_CALIB_BOOLEAN
#include "CoStopStart_MemMap.h"

/******************************************************************************\
   AR_MERGEABLE_CALIB_BOOLEAN: Mergeable Calib 1 bit for AUTOSAR modules | Width: 8
\******************************************************************************/
AR_MERGEABLE_CALIB_BOOLEAN Boolean MgtAlt_bStraAltRstrtAcv_C = 1 /* 
   Description: Choix de la stratégie pour demander le redem machine électrique
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;

AR_MERGEABLE_CALIB_BOOLEAN Boolean MonVeh_bAcvSpdCluClsRstrtReq_C = 1 /* 
   Description: Activation du besoin vitesse CdT fermée
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;

AR_MERGEABLE_CALIB_BOOLEAN Boolean MonEE_bAcvAvlRStrtReq_C = 0 /* 
   Description: Activation du besoin redémarrabilité
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
   
AR_MERGEABLE_CALIB_BOOLEAN Boolean CoRstrt_bAcvSpdVehSecu_C = 0 /* 
   Description: Activation de la prise en compte de la vitesse véhicule sécurisée
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
   
   #define COSTOPSTART_STOP_SEC_CALIB_BOOLEAN
#include "CoStopStart_MemMap.h"

/*----------------------------------------------------------------------------*\
  PARAMETERIZED MACROS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION PROTOTYPES
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  INLINE FUNCTIONS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION DEFINITIONS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  MODULE LOCAL FUNCTION DEFINITIONS
\*----------------------------------------------------------------------------*/

#endif/*_COSTOPSTART_CALIBRATIONS_C_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
