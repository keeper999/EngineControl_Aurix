/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF412.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF412.H"
#include "FHCANF412_PRIVATE.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_412(void)
{
	ISCAN_bF412PM1436 = 0;
	ISCAN_bF412P013 = 0;
	ISCAN_bF412PM1437 = 1;
	ISCAN_bF412PM1339 = 0;
	ISCAN_bF412P103 = 0;
	ISCAN_bF412P040 = 0;
	ISCAN_bF412P298 = 0;
	ISCAN_bF412P277 = 0;
	ISCAN_u8N2F412P104 = 0;
	ISCAN_u8N2F412P086 = 0;
	ISCAN_bF412P012 = 0;

	VEMS_vidSET(Ext_bModSptReq, 0);
	VEMS_vidSET(CoReqVeh_bMainBrkPedPrss, 0);
	VEMS_vidSET(Ext_bDynFctAcvCplm, 1);
	VEMS_vidSET(Ext_bBrkPark, 0);
	VEMS_vidSET(Ext_bRvsMux, 0);
	VEMS_vidSET(CoReqVeh_bMainBrkPedPrssHS, 0);
	VEMS_vidSET(Veh_bHeatReq, 0);
	VEMS_vidSET(CoReqVeh_bOilMesReq, 0);
	VEMS_vidSET(CoReqVeh_stAdHeat, 0);
	VEMS_vidSET(WaHt_bWaHt1Out, 0);
	VEMS_vidSET(WaHt_bWaHt2Out, 0);
	VEMS_vidSET(Ext_stFuLvlDft, 0);
	VEMS_vidSET(Ext_bFuLvlDft, 0);
	VEMS_vidSET(Fuel_gauge_diag_mux, 0);
	VEMS_vidSET(Ext_bFuTnkEmp, 0);
	VEMS_vidSET(Flev_low_fuel_level_mux, 0);

	Ext_bMonRunMissF412 = FHCAN_DISABLE;
	Ext_bMonRunShoF412 = FHCAN_DISABLE;
	Ext_bMonRunInvldF412P040 = FHCAN_DISABLE;

	Ext_bDgoMissF412 = FHCAN_NOT_DETECTED;
	Ext_bDgoShoF412 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF412P040 = FHCAN_NOT_DETECTED;
}

void FHCANF412_vidFrameReceived(void)
{
	boolean Local_bCtrl_BSI_412;
	boolean Local_bCtrl_bAcv_bModSptReq;
	boolean Local_bCtrl_bMainBrkPedPrss;
	boolean Local_bCtrl_bDynFctAcvCplm;
	boolean Local_bCtrl_bAcv_bBrkPark;
	boolean Local_bCtrl_bRvs;
	boolean Local_bCtrl_bMainBrkPedPrssHSVeh;
	boolean Local_bCtrl_bHeatReq;
	boolean Local_bCtrl_bOilMesReq;
	boolean Local_bCtrl_stAdHeat;
	boolean Local_bCtrl_stFuLvlDft;
	boolean Local_bCtrl_bFuTnkEmp;

	VEMS_vidGET(Ctrl_BSI_412, Local_bCtrl_BSI_412);
	if (ACTIVATED == Local_bCtrl_BSI_412)
	{
		ISCAN_EveRxn_412();
		FHCAN412_vidCalcMonWindow();

	  	if (FHCAN_ENABLE == Ext_bMonRunMissF412)
      {
         Ext_bDgoMissF412 = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF412,
                  Ext_bDgoMissF412,
                  Ext_bMonRunMissF412,
                  DIAG_DISPO);
      }
            
		VEMS_vidGET(Ctrl_bAcv_bModSptReq, Local_bCtrl_bAcv_bModSptReq);
		if (ACTIVATED == Local_bCtrl_bAcv_bModSptReq)
		{
			Com_ReceiveSignal(Com_ACTIVATION_DYN_BSI_412, (void*) &ISCAN_bF412PM1436);


			FHCANF412_vidUpdateSignalPM1436();
		}
		else
		{
			VEMS_vidSET(Ext_bModSptReq, 0);

		}
		VEMS_vidGET(Ctrl_bMainBrkPedPrss, Local_bCtrl_bMainBrkPedPrss);
		if (ACTIVATED == Local_bCtrl_bMainBrkPedPrss)
		{
			Com_ReceiveSignal(Com_CONTACT_FREIN1_BSI_412, (void*) &ISCAN_bF412P013);


			FHCANF412_vidUpdateSignalP013();
		}
		else
		{
			VEMS_vidSET(CoReqVeh_bMainBrkPedPrss, 0);

		}
		VEMS_vidGET(Ctrl_bDynFctAcvCplm, Local_bCtrl_bDynFctAcvCplm);
		if (ACTIVATED == Local_bCtrl_bDynFctAcvCplm)
		{
			Com_ReceiveSignal(Com_CPLMNT_ACTIVATION_DYN_BSI_412, (void*) &ISCAN_bF412PM1437);


			FHCANF412_vidUpdateSignalPM1437();
		}
		else
		{
			VEMS_vidSET(Ext_bDynFctAcvCplm, 1);

		}
		VEMS_vidGET(Ctrl_bAcv_bBrkPark, Local_bCtrl_bAcv_bBrkPark);
		if (ACTIVATED == Local_bCtrl_bAcv_bBrkPark)
		{
			Com_ReceiveSignal(Com_CONTACT_FREIN_PRK_BSI_412, (void*) &ISCAN_bF412PM1339);


			FHCANF412_vidUpdateSignalPM1339();
		}
		else
		{
			VEMS_vidSET(Ext_bBrkPark, 0);

		}
		VEMS_vidGET(Ctrl_bRvs, Local_bCtrl_bRvs);
		if (ACTIVATED == Local_bCtrl_bRvs)
		{
			Com_ReceiveSignal(Com_MARCHE_AR_BVM_BSI_412, (void*) &ISCAN_bF412P103);


			FHCANF412_vidUpdateSignalP103();
		}
		else
		{
			VEMS_vidSET(Ext_bRvsMux, 0);

		}
		VEMS_vidGET(Ctrl_bMainBrkPedPrssHSVeh, Local_bCtrl_bMainBrkPedPrssHSVeh);
		if (ACTIVATED == Local_bCtrl_bMainBrkPedPrssHSVeh)
		{
			FHCAN412_vidCalcMonFP040Window();
			Com_ReceiveSignal(Com_CONTACT_FREIN1_HS_BSI_412, (void*) &ISCAN_bF412P040);

			FHCAN412_vidMonInvldP040Update();

			FHCANF412_vidUpdateSignalP040();
		}
		else
		{
			VEMS_vidSET(CoReqVeh_bMainBrkPedPrssHS, 0);

			Ext_bMonRunInvldF412P040 = FHCAN_DISABLE;
			Ext_bDgoInvldF412P040 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_bHeatReq, Local_bCtrl_bHeatReq);
		if (ACTIVATED == Local_bCtrl_bHeatReq)
		{
			Com_ReceiveSignal(Com_DDE_CHAUF_HAB_BSI_412, (void*) &ISCAN_bF412P298);


			FHCANF412_vidUpdateSignalP298();
		}
		else
		{
			VEMS_vidSET(Veh_bHeatReq, 0);

		}
		VEMS_vidGET(Ctrl_bOilMesReq, Local_bCtrl_bOilMesReq);
		if (ACTIVATED == Local_bCtrl_bOilMesReq)
		{
			Com_ReceiveSignal(Com_DDE_MES_HUILE_MOT_BSI_412, (void*) &ISCAN_bF412P277);


			FHCANF412_vidUpdateSignalP277();
		}
		else
		{
			VEMS_vidSET(CoReqVeh_bOilMesReq, 0);

		}
		VEMS_vidGET(Ctrl_stAdHeat, Local_bCtrl_stAdHeat);
		if (ACTIVATED == Local_bCtrl_stAdHeat)
		{
			Com_ReceiveSignal(Com_REQ_CHAUF_HAB_BSI_412, (void*) &ISCAN_u8N2F412P104);


			FHCANF412_vidUpdateSignalP104();
		}
		else
		{
			VEMS_vidSET(CoReqVeh_stAdHeat, 0);
			VEMS_vidSET(WaHt_bWaHt1Out, 0);
			VEMS_vidSET(WaHt_bWaHt2Out, 0);

		}
		VEMS_vidGET(Ctrl_stFuLvlDft, Local_bCtrl_stFuLvlDft);
		if (ACTIVATED == Local_bCtrl_stFuLvlDft)
		{
			Com_ReceiveSignal(Com_DIAG_MINI_CARB_BSI_412, (void*) &ISCAN_u8N2F412P086);


			FHCANF412_vidUpdateSignalP086();
		}
		else
		{
			VEMS_vidSET(Ext_stFuLvlDft, 0);
			VEMS_vidSET(Ext_bFuLvlDft, 0);
			VEMS_vidSET(Fuel_gauge_diag_mux, 0);

		}
		VEMS_vidGET(Ctrl_bFuTnkEmp, Local_bCtrl_bFuTnkEmp);
		if (ACTIVATED == Local_bCtrl_bFuTnkEmp)
		{
			Com_ReceiveSignal(Com_MINI_CARB_BSI_412, (void*) &ISCAN_bF412P012);


			FHCANF412_vidUpdateSignalP012();
		}
		else
		{
			VEMS_vidSET(Ext_bFuTnkEmp, 0);
			VEMS_vidSET(Flev_low_fuel_level_mux, 0);

		}
	}
	else
	{
		Ext_bMonRunMissF412 = FHCAN_DISABLE;
		Ext_bMonRunShoF412 = FHCAN_DISABLE;
		Ext_bMonRunInvldF412P040 = FHCAN_DISABLE;

		Ext_bDgoMissF412 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF412 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF412P040 = FHCAN_NOT_DETECTED;
	}
}



void FHCANF412_vidFrameNotReceived(void)
{
	boolean FRM_bAcvRcvF412P040_in;
	boolean FRM_bAcvRcvF412_in;
	boolean Local_bCtrl_BSI_412;
	boolean Local_bCtrl_bAcv_bModSptReq;
	boolean Local_bCtrl_bMainBrkPedPrss;
	boolean Local_bCtrl_bDynFctAcvCplm;
	boolean Local_bCtrl_bAcv_bBrkPark;
	boolean Local_bCtrl_bRvs;
	boolean Local_bCtrl_bMainBrkPedPrssHSVeh;
	boolean Local_bCtrl_bHeatReq;
	boolean Local_bCtrl_bOilMesReq;
	boolean Local_bCtrl_stAdHeat;
	boolean Local_bCtrl_stFuLvlDft;
	boolean Local_bCtrl_bFuTnkEmp;


	VEMS_vidGET(Ctrl_BSI_412, Local_bCtrl_BSI_412);
	if (ACTIVATED == Local_bCtrl_BSI_412)
	{
		FHCAN412_vidCalcMonWindow();

      if (FHCAN_ENABLE == Ext_bMonRunMissF412)
      {
         Ext_bDgoMissF412 = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF412,
                  Ext_bDgoMissF412,
                  Ext_bMonRunMissF412,
                  DIAG_DISPO);
      }
      else
      {
		   VEMS_vidSET(Ext_bModSptReq, 0);
		   VEMS_vidSET(CoReqVeh_bMainBrkPedPrss, 0);
		   VEMS_vidSET(Ext_bDynFctAcvCplm, 1);
		   VEMS_vidSET(Ext_bBrkPark, 0);
		   VEMS_vidSET(Ext_bRvsMux, 0);
		   VEMS_vidSET(CoReqVeh_bMainBrkPedPrssHS, 0);
		   VEMS_vidSET(Veh_bHeatReq, 0);
		   VEMS_vidSET(CoReqVeh_bOilMesReq, 0);
		   VEMS_vidSET(CoReqVeh_stAdHeat, 0);
		   VEMS_vidSET(WaHt_bWaHt1Out, 0);
		   VEMS_vidSET(WaHt_bWaHt2Out, 0);
		   VEMS_vidSET(Ext_stFuLvlDft, 0);
		   VEMS_vidSET(Ext_bFuLvlDft, 0);
		   VEMS_vidSET(Fuel_gauge_diag_mux, 0);
		   VEMS_vidSET(Ext_bFuTnkEmp, 0);
		   VEMS_vidSET(Flev_low_fuel_level_mux, 0);
      }

		FRM_bAcvRcvF412P040_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF412P040);
		FRM_bAcvRcvF412_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF412);

		VEMS_vidGET(Ctrl_bAcv_bModSptReq, Local_bCtrl_bAcv_bModSptReq);
		if (ACTIVATED == Local_bCtrl_bAcv_bModSptReq)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF412_in)
			{
		      VEMS_vidSET(Ext_bModSptReq, Ext_bModSptReqRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bMainBrkPedPrss, Local_bCtrl_bMainBrkPedPrss);
		if (ACTIVATED == Local_bCtrl_bMainBrkPedPrss)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF412_in)
			{
		      VEMS_vidSET(CoReqVeh_bMainBrkPedPrss, CoReqVeh_bMainBrkPedPrssRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bDynFctAcvCplm, Local_bCtrl_bDynFctAcvCplm);
		if (ACTIVATED == Local_bCtrl_bDynFctAcvCplm)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF412_in)
			{
		      VEMS_vidSET(Ext_bDynFctAcvCplm, Ext_bDynFctAcvCplmRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bAcv_bBrkPark, Local_bCtrl_bAcv_bBrkPark);
		if (ACTIVATED == Local_bCtrl_bAcv_bBrkPark)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF412_in)
			{
		      VEMS_vidSET(Ext_bBrkPark, Ext_bBrkParkRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bRvs, Local_bCtrl_bRvs);
		if (ACTIVATED == Local_bCtrl_bRvs)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF412_in)
			{
		      VEMS_vidSET(Ext_bRvsMux, Ext_bRvsRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bMainBrkPedPrssHSVeh, Local_bCtrl_bMainBrkPedPrssHSVeh);
		if (ACTIVATED == Local_bCtrl_bMainBrkPedPrssHSVeh)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF412P040_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF412_in))
			{
		      VEMS_vidSET(CoReqVeh_bMainBrkPedPrssHS, CoReqVeh_bMainBrkPedPrssHSRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bHeatReq, Local_bCtrl_bHeatReq);
		if (ACTIVATED == Local_bCtrl_bHeatReq)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF412_in)
			{
		      VEMS_vidSET(Veh_bHeatReq, Veh_bHeatReqRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bOilMesReq, Local_bCtrl_bOilMesReq);
		if (ACTIVATED == Local_bCtrl_bOilMesReq)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF412_in)
			{
		      VEMS_vidSET(CoReqVeh_bOilMesReq, CoReqVeh_bOilMesReqRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_stAdHeat, Local_bCtrl_stAdHeat);
		if (ACTIVATED == Local_bCtrl_stAdHeat)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF412_in)
			{
		      VEMS_vidSET(CoReqVeh_stAdHeat, CoReqVeh_stAdHeatRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_stFuLvlDft, Local_bCtrl_stFuLvlDft);
		if (ACTIVATED == Local_bCtrl_stFuLvlDft)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF412_in)
			{
		      VEMS_vidSET(Ext_stFuLvlDft, Ext_stFuLvlDftRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bFuTnkEmp, Local_bCtrl_bFuTnkEmp);
		if (ACTIVATED == Local_bCtrl_bFuTnkEmp)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF412_in)
			{
		      VEMS_vidSET(Ext_bFuTnkEmp, Ext_bFuTnkEmpRcf_C);
			}
		}
	}
	else
	{
		Ext_bMonRunMissF412 = FHCAN_DISABLE;
		Ext_bMonRunShoF412 = FHCAN_DISABLE;
		Ext_bMonRunInvldF412P040 = FHCAN_DISABLE;

		Ext_bDgoMissF412 = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF412 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF412P040 = FHCAN_NOT_DETECTED;
	}
}

void FHCANF412_vidUpdateSignalPM1436(void)
{
	boolean FRM_bAcvRcvF412_in;

	FRM_bAcvRcvF412_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF412);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF412_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF412)
	   )
	{
      VEMS_vidSET(Ext_bModSptReq,
                  ISCAN_bF412PM1436);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF412_in)
      {
			VEMS_vidSET(Ext_bModSptReq, Ext_bModSptReqRcf_C);
		}
	}
}

void FHCANF412_vidUpdateSignalP013(void)
{
	boolean FRM_bAcvRcvF412_in;

	FRM_bAcvRcvF412_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF412);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF412_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF412)
	   )
	{
      VEMS_vidSET(CoReqVeh_bMainBrkPedPrss,
                  ISCAN_bF412P013);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF412_in)
      {
			VEMS_vidSET(CoReqVeh_bMainBrkPedPrss, CoReqVeh_bMainBrkPedPrssRcf_C);
		}
	}
}

void FHCANF412_vidUpdateSignalPM1437(void)
{
	boolean FRM_bAcvRcvF412_in;

	FRM_bAcvRcvF412_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF412);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF412_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF412)
	   )
	{
      VEMS_vidSET(Ext_bDynFctAcvCplm,
                  ISCAN_bF412PM1437);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF412_in)
      {
			VEMS_vidSET(Ext_bDynFctAcvCplm, Ext_bDynFctAcvCplmRcf_C);
		}
	}
}

void FHCANF412_vidUpdateSignalPM1339(void)
{
	boolean FRM_bAcvRcvF412_in;

	FRM_bAcvRcvF412_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF412);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF412_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF412)
	   )
	{
      VEMS_vidSET(Ext_bBrkPark,
                  ISCAN_bF412PM1339);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF412_in)
      {
			VEMS_vidSET(Ext_bBrkPark, Ext_bBrkParkRcf_C);
		}
	}
}

void FHCANF412_vidUpdateSignalP103(void)
{
	boolean FRM_bAcvRcvF412_in;

	FRM_bAcvRcvF412_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF412);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF412_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF412)
	   )
	{
      VEMS_vidSET(Ext_bRvsMux,
                  ISCAN_bF412P103);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF412_in)
      {
			VEMS_vidSET(Ext_bRvsMux, Ext_bRvsRcf_C);
		}
	}
}

void FHCANF412_vidUpdateSignalP040(void)
{
	boolean FRM_bAcvRcvF412P040_in;
	boolean FRM_bAcvRcvF412_in;

	FRM_bAcvRcvF412P040_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF412P040);
	FRM_bAcvRcvF412_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF412);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF412P040_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF412_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF412P040)
	   && (FHCAN_DETECTED != Ext_bDgoShoF412)
	   )
	{
      VEMS_vidSET(CoReqVeh_bMainBrkPedPrssHS,
                  ISCAN_bF412P040);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF412P040_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF412_in))
      {
			VEMS_vidSET(CoReqVeh_bMainBrkPedPrssHS, CoReqVeh_bMainBrkPedPrssHSRcf_C);
		}
	}
}

void FHCANF412_vidUpdateSignalP298(void)
{
	boolean FRM_bAcvRcvF412_in;

	FRM_bAcvRcvF412_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF412);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF412_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF412)
	   )
	{
      VEMS_vidSET(Veh_bHeatReq,
                  ISCAN_bF412P298);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF412_in)
      {
			VEMS_vidSET(Veh_bHeatReq, Veh_bHeatReqRcf_C);
		}
	}
}

void FHCANF412_vidUpdateSignalP277(void)
{
	boolean FRM_bAcvRcvF412_in;

	FRM_bAcvRcvF412_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF412);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF412_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF412)
	   )
	{
      VEMS_vidSET(CoReqVeh_bOilMesReq,
                  ISCAN_bF412P277);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF412_in)
      {
			VEMS_vidSET(CoReqVeh_bOilMesReq, CoReqVeh_bOilMesReqRcf_C);
		}
	}
}

void FHCANF412_vidUpdateSignalP104(void)
{
	boolean FRM_bAcvRcvF412_in;
   uint8 u8LocalCoReqVeh_stAdHeat;

	FRM_bAcvRcvF412_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF412);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF412_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF412)
	   )
	{
      u8LocalCoReqVeh_stAdHeat = (uint8)(MATHSRV_udtMIN(ISCAN_u8N2F412P104,
                                             3));
      VEMS_vidSET(CoReqVeh_stAdHeat,
                  u8LocalCoReqVeh_stAdHeat);
      if (ISCAN_u8N2F412P104 >= 1)
      {
         VEMS_vidSET(WaHt_bWaHt1Out, 1);
      }
      else
      {
         VEMS_vidSET(WaHt_bWaHt1Out, 0);
      }
      if (ISCAN_u8N2F412P104 >= 1)
      {
         VEMS_vidSET(WaHt_bWaHt2Out, 1);
      }
      else
      {
         VEMS_vidSET(WaHt_bWaHt2Out, 0);
      }
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF412_in)
      {
			VEMS_vidSET(CoReqVeh_stAdHeat, CoReqVeh_stAdHeatRcf_C);
		}
	}
}

void FHCANF412_vidUpdateSignalP086(void)
{
	boolean FRM_bAcvRcvF412_in;
   uint8 u8LocalExt_stFuLvlDft;
   uint8 u8LocalFuel_gauge_diag_mux;

	FRM_bAcvRcvF412_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF412);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF412_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF412)
	   )
	{
      u8LocalExt_stFuLvlDft = (uint8)(MATHSRV_udtMIN(ISCAN_u8N2F412P086,
                                             3));
      VEMS_vidSET(Ext_stFuLvlDft,
                  u8LocalExt_stFuLvlDft);
      u8LocalFuel_gauge_diag_mux = (uint8)(MATHSRV_udtMIN(ISCAN_u8N2F412P086,
                                             4));
      VEMS_vidSET(Fuel_gauge_diag_mux,
                  u8LocalFuel_gauge_diag_mux);
		if (ISCAN_u8N2F412P086 == 0)
		{
         VEMS_vidSET(Ext_bFuLvlDft, 0);
		}
		else
		{
         VEMS_vidSET(Ext_bFuLvlDft, 1);
		}
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF412_in)
      {
			VEMS_vidSET(Ext_stFuLvlDft, Ext_stFuLvlDftRcf_C);
		}
	}
}

void FHCANF412_vidUpdateSignalP012(void)
{
	boolean FRM_bAcvRcvF412_in;

	FRM_bAcvRcvF412_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF412);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF412_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF412)
	   )
	{
      VEMS_vidSET(Ext_bFuTnkEmp,
                  ISCAN_bF412P012);
      VEMS_vidSET(Flev_low_fuel_level_mux,
                  ISCAN_bF412P012);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF412_in)
      {
			VEMS_vidSET(Ext_bFuTnkEmp, Ext_bFuTnkEmpRcf_C);
		}
	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
