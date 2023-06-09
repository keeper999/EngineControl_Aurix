
#ifndef _COSTOPSTART_CALIBRATIONS_H_
#define _COSTOPSTART_CALIBRATIONS_H_

/*----------------------------------------------------------------------------*\
  DEFINES (OPT)
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  INCLUDES
\*----------------------------------------------------------------------------*/
#include "tl_defines.h"
#include "tl_basetypes.h"
/*----------------------------------------------------------------------------*\
  DEFINES
\*----------------------------------------------------------------------------*/
#ifndef AR_MERGEABLE_CALIB_16BIT
#define AR_MERGEABLE_CALIB_16BIT const volatile 
#endif
#ifndef AR_MERGEABLE_CALIB_8BIT
#define AR_MERGEABLE_CALIB_8BIT const volatile 
#endif
#ifndef AR_MERGEABLE_CALIB_BOOLEAN
#define AR_MERGEABLE_CALIB_BOOLEAN const volatile 
#endif
#ifndef AR_MERGEABLE_EXT_CALIB_16BIT
#define AR_MERGEABLE_EXT_CALIB_16BIT extern const volatile 
#endif
#ifndef AR_MERGEABLE_EXT_CALIB_8BIT
#define AR_MERGEABLE_EXT_CALIB_8BIT extern const volatile 
#endif
#ifndef AR_MERGEABLE_EXT_CALIB_BOOLEAN
#define AR_MERGEABLE_EXT_CALIB_BOOLEAN extern const volatile 
#endif
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
   AR_MERGEABLE_EXT_CALIB_16BIT: Mergeable Calib 16 bits for AUTOSAR modules | Width: 16
\******************************************************************************/
AR_MERGEABLE_EXT_CALIB_16BIT UInt16 MonDrv_rCluPMinRstrt_C /* 75. */ /* 
   Unit       : %
   Description: Position_embrayage_redem_PM
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 100 */;
   
AR_MERGEABLE_EXT_CALIB_16BIT UInt16 MonDrv_rCluPMaxStop_C /* 25. */ /* 
   Unit       : %
   Description: Position_embrayage_Stop_PM
   LSB: 2^-4 OFF:  0 MIN/MAX:  0 .. 100 */;

AR_MERGEABLE_EXT_CALIB_16BIT UInt16 MonGB_tiMAPToutGc_C /* 
   Unit       : s
   Description: Temps � partir du quel le changement de rapport MAP est d�fini comme trop long.
   LSB: 0.1 OFF:  0 MIN/MAX:  0 .. 60 */;
      
#define COSTOPSTART_STOP_SEC_CALIB_16BIT
#include "CoStopStart_MemMap.h"

#define COSTOPSTART_START_SEC_CALIB_8BIT
#include "CoStopStart_MemMap.h"

/******************************************************************************\
   AR_MERGEABLE_EXT_CALIB_8BIT: Mergeable Calib 8 bits for AUTOSAR modules | Width: 8
\******************************************************************************/
AR_MERGEABLE_EXT_CALIB_8BIT UInt8 CoRStrt_spdRstrtAuth_C /* 
   Unit       : km/h
   Description: Seuil de vitesse red�marrage chaine de traction ferm�e
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 50 */;
   
AR_MERGEABLE_EXT_CALIB_8BIT UInt8 CoRStrt_stModInhSpdVehCoPtUH_C /* 
   Description: Mode pour traiter signal logique reconfiguration demandant d'ignorer la vitesse v�hi
   cule
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;
   
AR_MERGEABLE_EXT_CALIB_8BIT UInt8 MgtDrv_stModPush_C /* 
   Description: Mode pour traiter signal logique Push
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;
   
AR_MERGEABLE_EXT_CALIB_8BIT UInt8 CoStop_stModInhStopCoPtUH_C /* 
   Description: Mode pour traiter signal logique reconfiguration demandant inhibition des stops
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;
   
AR_MERGEABLE_EXT_CALIB_8BIT UInt8 CoRStrt_stModAcvRstrtCoPtUH_C /* 
   Description: Mode pour traiter signal logique reconfiguration type 2.1 (red�marrage normal)
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;
   
AR_MERGEABLE_EXT_CALIB_8BIT UInt8 CoRStrt_stModAcvFastRstrt_C /* 
   Description: Mode pour traiter signal logique reconfiguration type 2.2 (red�marrage urgent)
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;
   
AR_MERGEABLE_EXT_CALIB_8BIT UInt8 CoCut_stModAcvCutTotCoPtUH_C /* 
   Description: Mode pour traiter signal logique reconfiguration demandant coupure totale
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;
   
AR_MERGEABLE_EXT_CALIB_8BIT UInt8 CoCut_stModAcvCutCoPtUH_C /* 
   Description: Mode pour traiter signal logique reconfiguration demandant la coupure
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;
   
AR_MERGEABLE_EXT_CALIB_8BIT UInt8 CoStop_stModSftyInhStopCoPtUH_C /* 
   Description: Mode pour traiter signal logique Reconfiguration par le niveau 2 inhibant le stop
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;

AR_MERGEABLE_EXT_CALIB_8BIT UInt8 MonVeh_spdCluClsRstrtReq_C /* 20 */ /*
   Unit       : kmh
   Description: Seuil besoin vitesse BVM, CDT ferm�e
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 50 */;

AR_MERGEABLE_EXT_CALIB_8BIT UInt8 MonGB_stModAMTStopAuth_C /* 
   Description: Traitement bool�en pour traiter signal logique autorisation de stop BVMP
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 3 */;   
   
#define COSTOPSTART_STOP_SEC_CALIB_8BIT
#include "CoStopStart_MemMap.h"

#define COSTOPSTART_START_SEC_CALIB_BOOLEAN
#include "CoStopStart_MemMap.h"

/******************************************************************************\
   AR_MERGEABLE_EXT_CALIB_BOOLEAN: Mergeable Calib 1 bit for AUTOSAR modules | Width: 8
\******************************************************************************/
AR_MERGEABLE_EXT_CALIB_BOOLEAN Boolean MgtAlt_bStraAltRstrtAcv_C /* 
   Description: Choix de la strat�gie pour demander le redem machine �lectrique
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;

AR_MERGEABLE_EXT_CALIB_BOOLEAN Boolean MonVeh_bAcvSpdCluClsRstrtReq_C /* 
   Description: Activation du besoin vitesse CdT ferm�e
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;

AR_MERGEABLE_EXT_CALIB_BOOLEAN Boolean MonEE_bAcvAvlRStrtReq_C /* 
   Description: Activation du besoin red�marrabilit�
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;   
   
AR_MERGEABLE_EXT_CALIB_BOOLEAN Boolean CoRstrt_bAcvSpdVehSecu_C /* 
   Description: Activation de la prise en compte de la vitesse v�hicule s�curis�e
   LSB: 2^0 OFF:  0 MIN/MAX:  0 .. 1 */;
   
#define COSTOPSTART_STOP_SEC_CALIB_BOOLEAN
#include "CoStopStart_MemMap.h"

/*----------------------------------------------------------------------------*\
  PARAMETERIZED MACROS
\*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*\
  FUNCTION PROTOTYPES
\*----------------------------------------------------------------------------*/

#endif/*_COSTOPSTART_CALIBRATIONS_H_ */
/*----------------------------------------------------------------------------*\
  END OF FILE
\*----------------------------------------------------------------------------*/
