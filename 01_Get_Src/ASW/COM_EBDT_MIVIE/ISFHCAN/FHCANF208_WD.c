/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF208_WD.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "STD_LIMITS.H"
#include "FHCANF208_PRIVATE.H"
#include "GDGAR.H"
#include "VEMS.h"


#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN208_vidCalcMonCMMWindow(void)
{
   boolean Ext_bDiagMuxOn_in;
   boolean FRM_bBusOff_in;


   VEMS_vidGET(Ext_bDiagMuxOn, Ext_bDiagMuxOn_in);
   FRM_bBusOff_in = GDGAR_bGetFRM(FRM_FRM_BUSOFF);

   if (  (FHCAN_ENABLE == Ext_bDiagMuxOn_in)
      && (FHCAN_NOT_STORED == FRM_bBusOff_in))
   {
      Ext_bMonRunCMMAbsent = FHCAN_ENABLE;
   }
   else
   {
      Ext_bMonRunCMMAbsent = FHCAN_DISABLE;
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
