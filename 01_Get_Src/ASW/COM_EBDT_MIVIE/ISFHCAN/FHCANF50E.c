/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF50E.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF50E.H"
#include "FHCANF50E_PRIVATE.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_50E(void)
{
	ISCAN_u8N2F50EP232 = 0;
	ISCAN_bF50EPM1386 = 0;
	ISCAN_bF50EP209 = 0;
	ISCAN_u8N6F50EP046 = 0;
	ISCAN_u8N2F50EPM1425 = 0;
	ISCAN_bF50EP189 = 0;
	ISCAN_u8N2F50EPM1388 = 0;
	ISCAN_u8N2F50EP417 = 0;
	ISCAN_u8N8F50EP210 = 0;
	ISCAN_u8N8F50EP208 = 0;
	ISCAN_u8N8F50EP219 = 255;
	ISCAN_bF50EP220 = 0;
	ISCAN_u8N2F50EP221 = 0;
	ISCAN_bF50EP222 = 0;
	ISCAN_u8N4F50EP231 = 0;

	VEMS_vidSET(Ext_noCks50E, 0);
	VEMS_vidSET(Ext_bDgoBody, 0);
	VEMS_vidSET(AC_bACClu, 0);
	VEMS_vidSET(Ext_bACCluAuth, 0);
	VEMS_vidSET(AC_rSpdFanReq, 0);
	VEMS_vidSET(CoReqVeh_stEngRStrtReq, 0);
	VEMS_vidSET(AltCtl_bCmpReq, 0);
	VEMS_vidSET(CoReqVeh_stEngStopAuth, 0);
	VEMS_vidSET(Veh_stDrvAvl, 0);
	VEMS_vidSET(AC_pwrAC, 0);
	VEMS_vidSET(Clm_nTarIdl, 0);
	VEMS_vidSET(Ext_spdVehVSCtlReq, 255);
	VEMS_vidSET(Ext_bVSRegDVSRegReq, 0);
	VEMS_vidSET(Ext_stVSCtlReq, 0);
	VEMS_vidSET(Ext_stModRegVSCtlReq, 0);
	VEMS_vidSET(Cc_regulation_speed_on_mux, 0);
	VEMS_vidSET(Cc_limitation_speed_on_mux, 0);
	VEMS_vidSET(Cc_acc_regulation_type_mux, 0);
	VEMS_vidSET(Ext_bVSLimReq, 0);
	VEMS_vidSET(Ext_ctBSIFrame, 0);
	Ext_bMonRunBSIAbsent = FHCAN_DISABLE;
	Ext_bDgoBSIAbsent = FHCAN_NOT_DETECTED;

	Ext_bMonRunMissF50E = FHCAN_DISABLE;
	Ext_bMonRunShoF50E = FHCAN_DISABLE;
	Ext_bMonRunInvldF50EPM1386 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF50EP046 = FHCAN_DISABLE;
	Ext_bMonRunInvldF50EP046 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF50EP417 = FHCAN_DISABLE;
	Ext_bMonRunInvldF50EP210 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF50EP208 = FHCAN_DISABLE;

	Ext_bDgoMissF50E = FHCAN_NOT_DETECTED;
	Ext_bDgoShoF50E = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF50EPM1386 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF50EP046 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF50EP046 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF50EP417 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF50EP210 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF50EP208 = FHCAN_NOT_DETECTED;
}

void FHCANF50E_vidFrameReceived(void)
{
	boolean Local_bCtrl_CLIM_50E;
	boolean Local_bCtrl_noCks50E;
	boolean Local_bCtrl_bDgoBody;
	boolean Local_bCtrl_bACClu;
	boolean Local_bCtrl_rSpdFanReq;
	boolean Local_bCtrl_stEngRStrtReq;
	boolean Local_bCtrl_bCmpReq;
	boolean Local_bCtrl_stEngStopAuth;
	boolean Local_bCtrl_stDrvAvl;
	boolean Local_bCtrl_pwrAC;
	boolean Local_bCtrl_nTarIdl;
	boolean Local_bCtrl_spdVehVSCtlReq;
	boolean Local_bCtrl_bVSRegDVSRegReq;
	boolean Local_bCtrl_stVSCtlReq;
	boolean Local_bCtrl_bVSLimReq;
	boolean Local_bCtrl_ctBSIFrame;

	VEMS_vidGET(Ctrl_CLIM_50E, Local_bCtrl_CLIM_50E);
	if (ACTIVATED == Local_bCtrl_CLIM_50E)
	{
		ISCAN_EveRxn_50E();
		FHCAN50E_vidCalcMonBSIWindow();
		FHCAN50E_vidCalcMonWindow();

		if (FHCAN_ENABLE == Ext_bMonRunBSIAbsent)
		{
			Ext_bDgoBSIAbsent = FHCAN_NOT_DETECTED;
			GDGAR_vidGdu(GD_DFT_BSIABSENT,
						Ext_bDgoBSIAbsent,
						Ext_bMonRunBSIAbsent,
						DIAG_DISPO);
		}
	  	if (FHCAN_ENABLE == Ext_bMonRunMissF50E)
      {
         Ext_bDgoMissF50E = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF50E,
                  Ext_bDgoMissF50E,
                  Ext_bMonRunMissF50E,
                  DIAG_DISPO);
      }
            
		VEMS_vidGET(Ctrl_noCks50E, Local_bCtrl_noCks50E);
		if (ACTIVATED == Local_bCtrl_noCks50E)
		{
			Com_ReceiveSignal(Com_CHKSUM_CONS_RVV_LVV_CLIM_50E, (void*) &ISCAN_u8N2F50EP232);


			FHCANF50E_vidUpdateSignalP232();
		}
		else
		{
			VEMS_vidSET(Ext_noCks50E, 0);

		}
		VEMS_vidGET(Ctrl_bDgoBody, Local_bCtrl_bDgoBody);
		if (ACTIVATED == Local_bCtrl_bDgoBody)
		{
			FHCAN50E_vidCalcMonFPM1386Window();
			Com_ReceiveSignal(Com_DEF_IDENT_HAB_CLIM_50E, (void*) &ISCAN_bF50EPM1386);

			FHCAN50E_vidMonInvldPM1386Update();

			FHCANF50E_vidUpdateSignalPM1386();
		}
		else
		{
			VEMS_vidSET(Ext_bDgoBody, 0);

			Ext_bMonRunInvldF50EPM1386 = FHCAN_DISABLE;
			Ext_bDgoInvldF50EPM1386 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_bACClu, Local_bCtrl_bACClu);
		if (ACTIVATED == Local_bCtrl_bACClu)
		{
			Com_ReceiveSignal(Com_ETAT_EMB_COMP_CLIM_50E, (void*) &ISCAN_bF50EP209);


			FHCANF50E_vidUpdateSignalP209();
		}
		else
		{
			VEMS_vidSET(AC_bACClu, 0);
			VEMS_vidSET(Ext_bACCluAuth, 0);

		}
		VEMS_vidGET(Ctrl_rSpdFanReq, Local_bCtrl_rSpdFanReq);
		if (ACTIVATED == Local_bCtrl_rSpdFanReq)
		{
			FHCAN50E_vidCalcMonFP046Window();
			Com_ReceiveSignal(Com_CNS_CONT_GMV_CLIM_CLIM_50E, (void*) &ISCAN_u8N6F50EP046);

			FHCAN50E_vidMonInvldP046Update();
			FHCAN50E_vidMonFrbdP046Update();

			FHCANF50E_vidUpdateSignalP046();
		}
		else
		{
			VEMS_vidSET(AC_rSpdFanReq, 0);

			Ext_bMonRunFrbdF50EP046 = FHCAN_DISABLE;
			Ext_bMonRunInvldF50EP046 = FHCAN_DISABLE;
			Ext_bDgoFrbdF50EP046 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF50EP046 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_stEngRStrtReq, Local_bCtrl_stEngRStrtReq);
		if (ACTIVATED == Local_bCtrl_stEngRStrtReq)
		{
			Com_ReceiveSignal(Com_DDE_REDEM_MOT_HAB_CLIM_50E, (void*) &ISCAN_u8N2F50EPM1425);


			FHCANF50E_vidUpdateSignalPM1425();
		}
		else
		{
			VEMS_vidSET(CoReqVeh_stEngRStrtReq, 0);

		}
		VEMS_vidGET(Ctrl_bCmpReq, Local_bCtrl_bCmpReq);
		if (ACTIVATED == Local_bCtrl_bCmpReq)
		{
			Com_ReceiveSignal(Com_NIV_DELESTAGE_SEV_CLIM_50E, (void*) &ISCAN_bF50EP189);


			FHCANF50E_vidUpdateSignalP189();
		}
		else
		{
			VEMS_vidSET(AltCtl_bCmpReq, 0);

		}
		VEMS_vidGET(Ctrl_stEngStopAuth, Local_bCtrl_stEngStopAuth);
		if (ACTIVATED == Local_bCtrl_stEngStopAuth)
		{
			Com_ReceiveSignal(Com_INTERD_ARRET_HAB_CLIM_50E, (void*) &ISCAN_u8N2F50EPM1388);


			FHCANF50E_vidUpdateSignalPM1388();
		}
		else
		{
			VEMS_vidSET(CoReqVeh_stEngStopAuth, 0);

		}
		VEMS_vidGET(Ctrl_stDrvAvl, Local_bCtrl_stDrvAvl);
		if (ACTIVATED == Local_bCtrl_stDrvAvl)
		{
			FHCAN50E_vidCalcMonFP417Window();
			Com_ReceiveSignal(Com_PRES_COND_CLIM_50E, (void*) &ISCAN_u8N2F50EP417);

			FHCAN50E_vidMonFrbdP417Update();

			FHCANF50E_vidUpdateSignalP417();
		}
		else
		{
			VEMS_vidSET(Veh_stDrvAvl, 0);

			Ext_bMonRunFrbdF50EP417 = FHCAN_DISABLE;
			Ext_bDgoFrbdF50EP417 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_pwrAC, Local_bCtrl_pwrAC);
		if (ACTIVATED == Local_bCtrl_pwrAC)
		{
			FHCAN50E_vidCalcMonFP210Window();
			Com_ReceiveSignal(Com_PUISS_MECA_CLIM_CLIM_50E, (void*) &ISCAN_u8N8F50EP210);

			FHCAN50E_vidMonInvldP210Update();

			FHCANF50E_vidUpdateSignalP210();
		}
		else
		{
			VEMS_vidSET(AC_pwrAC, 0);

			Ext_bMonRunInvldF50EP210 = FHCAN_DISABLE;
			Ext_bDgoInvldF50EP210 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_nTarIdl, Local_bCtrl_nTarIdl);
		if (ACTIVATED == Local_bCtrl_nTarIdl)
		{
			FHCAN50E_vidCalcMonFP208Window();
			Com_ReceiveSignal(Com_DEM_RAL_HAB_CLIM_50E, (void*) &ISCAN_u8N8F50EP208);

			FHCAN50E_vidMonFrbdP208Update();

			FHCANF50E_vidUpdateSignalP208();
		}
		else
		{
			VEMS_vidSET(Clm_nTarIdl, 0);

			Ext_bMonRunFrbdF50EP208 = FHCAN_DISABLE;
			Ext_bDgoFrbdF50EP208 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_spdVehVSCtlReq, Local_bCtrl_spdVehVSCtlReq);
		if (ACTIVATED == Local_bCtrl_spdVehVSCtlReq)
		{
			Com_ReceiveSignal(Com_CONS_LIM_VITESSE_VEH_CLIM_50E, (void*) &ISCAN_u8N8F50EP219);


			FHCANF50E_vidUpdateSignalP219();
		}
		else
		{
			VEMS_vidSET(Ext_spdVehVSCtlReq, 255);

		}
		VEMS_vidGET(Ctrl_bVSRegDVSRegReq, Local_bCtrl_bVSRegDVSRegReq);
		if (ACTIVATED == Local_bCtrl_bVSRegDVSRegReq)
		{
			Com_ReceiveSignal(Com_DDE_ACTIVATION_RVV_ACC_CLIM_50E, (void*) &ISCAN_bF50EP220);


			FHCANF50E_vidUpdateSignalP220();
		}
		else
		{
			VEMS_vidSET(Ext_bVSRegDVSRegReq, 0);

		}
		VEMS_vidGET(Ctrl_stVSCtlReq, Local_bCtrl_stVSCtlReq);
		if (ACTIVATED == Local_bCtrl_stVSCtlReq)
		{
			Com_ReceiveSignal(Com_TYPE_REGUL_LONGI_CLIM_50E, (void*) &ISCAN_u8N2F50EP221);


			FHCANF50E_vidUpdateSignalP221();
		}
		else
		{
			VEMS_vidSET(Ext_stVSCtlReq, 0);
			VEMS_vidSET(Ext_stModRegVSCtlReq, 0);
			VEMS_vidSET(Cc_regulation_speed_on_mux, 0);
			VEMS_vidSET(Cc_limitation_speed_on_mux, 0);
			VEMS_vidSET(Cc_acc_regulation_type_mux, 0);

		}
		VEMS_vidGET(Ctrl_bVSLimReq, Local_bCtrl_bVSLimReq);
		if (ACTIVATED == Local_bCtrl_bVSLimReq)
		{
			Com_ReceiveSignal(Com_DDE_ACTIVATION_LVV_CLIM_50E, (void*) &ISCAN_bF50EP222);


			FHCANF50E_vidUpdateSignalP222();
		}
		else
		{
			VEMS_vidSET(Ext_bVSLimReq, 0);

		}
		VEMS_vidGET(Ctrl_ctBSIFrame, Local_bCtrl_ctBSIFrame);
		if (ACTIVATED == Local_bCtrl_ctBSIFrame)
		{
			Com_ReceiveSignal(Com_CPT_TRAME_BSI_CLIM_50E, (void*) &ISCAN_u8N4F50EP231);


			FHCANF50E_vidUpdateSignalP231();
		}
		else
		{
			VEMS_vidSET(Ext_ctBSIFrame, 0);

		}
	}
	else
	{
		Ext_bMonRunBSIAbsent = FHCAN_DISABLE;
		Ext_bDgoBSIAbsent = FHCAN_NOT_DETECTED;
		Ext_bMonRunMissF50E = FHCAN_DISABLE;
		Ext_bMonRunShoF50E = FHCAN_DISABLE;
		Ext_bMonRunInvldF50EPM1386 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF50EP046 = FHCAN_DISABLE;
		Ext_bMonRunInvldF50EP046 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF50EP417 = FHCAN_DISABLE;
		Ext_bMonRunInvldF50EP210 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF50EP208 = FHCAN_DISABLE;

		Ext_bDgoMissF50E = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF50E = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF50EPM1386 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF50EP046 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF50EP046 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF50EP417 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF50EP210 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF50EP208 = FHCAN_NOT_DETECTED;
	}
}



void FHCANF50E_vidFrameNotReceived(void)
{
	boolean FRM_bAcvRcvF50EPM1386_in;
	boolean FRM_bAcvRcvF50EP046_in;
	boolean FRM_bAcvRcvF50EP417_in;
	boolean FRM_bAcvRcvF50EP210_in;
	boolean FRM_bAcvRcvF50EP208_in;
	boolean FRM_bAcvRcvF50E_in;
	boolean Local_bCtrl_CLIM_50E;
	boolean Local_bCtrl_noCks50E;
	boolean Local_bCtrl_bDgoBody;
	boolean Local_bCtrl_bACClu;
	boolean Local_bCtrl_rSpdFanReq;
	boolean Local_bCtrl_stEngRStrtReq;
	boolean Local_bCtrl_bCmpReq;
	boolean Local_bCtrl_stEngStopAuth;
	boolean Local_bCtrl_stDrvAvl;
	boolean Local_bCtrl_pwrAC;
	boolean Local_bCtrl_nTarIdl;
	boolean Local_bCtrl_spdVehVSCtlReq;
	boolean Local_bCtrl_bVSRegDVSRegReq;
	boolean Local_bCtrl_stVSCtlReq;
	boolean Local_bCtrl_bVSLimReq;
	boolean Local_bCtrl_ctBSIFrame;
	uint8 Local_Ext_noCks50E;
	uint8 Local_Ext_spdVehVSCtlReq;
	boolean Local_Ext_bVSRegDVSRegReq;
	uint8 Local_Ext_stVSCtlReq;
	boolean Local_Ext_bVSLimReq;
	uint8 Local_Ext_ctBSIFrame;


	VEMS_vidGET(Ctrl_CLIM_50E, Local_bCtrl_CLIM_50E);
	if (ACTIVATED == Local_bCtrl_CLIM_50E)
	{
		FHCAN50E_vidCalcMonBSIWindow();
		FHCAN50E_vidCalcMonWindow();

		if (FHCAN_ENABLE == Ext_bMonRunBSIAbsent)
		{
			Ext_bDgoBSIAbsent = FHCAN_DETECTED;
			GDGAR_vidGdu(GD_DFT_BSIABSENT,
						Ext_bDgoBSIAbsent,
						Ext_bMonRunBSIAbsent,
						DIAG_DISPO);
		}
      if (FHCAN_ENABLE == Ext_bMonRunMissF50E)
      {
         Ext_bDgoMissF50E = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF50E,
                  Ext_bDgoMissF50E,
                  Ext_bMonRunMissF50E,
                  DIAG_DISPO);
      }
      else
      {
		   VEMS_vidSET(Ext_noCks50E, 0);
		   VEMS_vidSET(Ext_bDgoBody, 0);
		   VEMS_vidSET(AC_bACClu, 0);
		   VEMS_vidSET(Ext_bACCluAuth, 0);
		   VEMS_vidSET(AC_rSpdFanReq, 0);
		   VEMS_vidSET(CoReqVeh_stEngRStrtReq, 0);
		   VEMS_vidSET(AltCtl_bCmpReq, 0);
		   VEMS_vidSET(CoReqVeh_stEngStopAuth, 0);
		   VEMS_vidSET(Veh_stDrvAvl, 0);
		   VEMS_vidSET(AC_pwrAC, 0);
		   VEMS_vidSET(Clm_nTarIdl, 0);
		   VEMS_vidSET(Ext_spdVehVSCtlReq, 255);
		   VEMS_vidSET(Ext_bVSRegDVSRegReq, 0);
		   VEMS_vidSET(Ext_stVSCtlReq, 0);
		   VEMS_vidSET(Ext_stModRegVSCtlReq, 0);
		   VEMS_vidSET(Cc_regulation_speed_on_mux, 0);
		   VEMS_vidSET(Cc_limitation_speed_on_mux, 0);
		   VEMS_vidSET(Cc_acc_regulation_type_mux, 0);
		   VEMS_vidSET(Ext_bVSLimReq, 0);
		   VEMS_vidSET(Ext_ctBSIFrame, 0);
      }

		FRM_bAcvRcvF50EPM1386_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF50EPM1386);
		FRM_bAcvRcvF50EP046_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF50EP046);
		FRM_bAcvRcvF50EP417_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF50EP417);
		FRM_bAcvRcvF50EP210_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF50EP210);
		FRM_bAcvRcvF50EP208_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF50EP208);
		FRM_bAcvRcvF50E_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF50E);

		VEMS_vidGET(Ctrl_noCks50E, Local_bCtrl_noCks50E);
		if (ACTIVATED == Local_bCtrl_noCks50E)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF50E_in)
			{
		      VEMS_vidGET(Ext_noCks50E, Local_Ext_noCks50E);
		      VEMS_vidSET(Ext_noCks50E, Local_Ext_noCks50E);
			}
		}
		VEMS_vidGET(Ctrl_bDgoBody, Local_bCtrl_bDgoBody);
		if (ACTIVATED == Local_bCtrl_bDgoBody)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF50EPM1386_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF50E_in))
			{
		      VEMS_vidSET(Ext_bDgoBody, Ext_bDgoBodyRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bACClu, Local_bCtrl_bACClu);
		if (ACTIVATED == Local_bCtrl_bACClu)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF50E_in)
			{
		      VEMS_vidSET(AC_bACClu, AC_bACCluRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_rSpdFanReq, Local_bCtrl_rSpdFanReq);
		if (ACTIVATED == Local_bCtrl_rSpdFanReq)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF50EP046_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF50E_in))
			{
		      VEMS_vidSET(AC_rSpdFanReq, AC_rSpdFanReqRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_stEngRStrtReq, Local_bCtrl_stEngRStrtReq);
		if (ACTIVATED == Local_bCtrl_stEngRStrtReq)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF50E_in)
			{
		      VEMS_vidSET(CoReqVeh_stEngRStrtReq, CoReqVeh_stEngRStrtReqRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_bCmpReq, Local_bCtrl_bCmpReq);
		if (ACTIVATED == Local_bCtrl_bCmpReq)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF50E_in)
			{
		      VEMS_vidSET(AltCtl_bCmpReq, AltCtl_bCmpReqRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_stEngStopAuth, Local_bCtrl_stEngStopAuth);
		if (ACTIVATED == Local_bCtrl_stEngStopAuth)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF50E_in)
			{
		      VEMS_vidSET(CoReqVeh_stEngStopAuth, CoReqVeh_stEngStopAuthRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_stDrvAvl, Local_bCtrl_stDrvAvl);
		if (ACTIVATED == Local_bCtrl_stDrvAvl)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF50EP417_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF50E_in))
			{
		      VEMS_vidSET(Veh_stDrvAvl, Veh_stDrvAvlRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_pwrAC, Local_bCtrl_pwrAC);
		if (ACTIVATED == Local_bCtrl_pwrAC)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF50EP210_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF50E_in))
			{
		      VEMS_vidSET(AC_pwrAC, AC_pwrACRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_nTarIdl, Local_bCtrl_nTarIdl);
		if (ACTIVATED == Local_bCtrl_nTarIdl)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF50EP208_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF50E_in))
			{
		      VEMS_vidSET(Clm_nTarIdl, Clm_nTarIdlRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_spdVehVSCtlReq, Local_bCtrl_spdVehVSCtlReq);
		if (ACTIVATED == Local_bCtrl_spdVehVSCtlReq)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF50E_in)
			{
		      VEMS_vidGET(Ext_spdVehVSCtlReq, Local_Ext_spdVehVSCtlReq);
		      VEMS_vidSET(Ext_spdVehVSCtlReq, Local_Ext_spdVehVSCtlReq);
			}
		}
		VEMS_vidGET(Ctrl_bVSRegDVSRegReq, Local_bCtrl_bVSRegDVSRegReq);
		if (ACTIVATED == Local_bCtrl_bVSRegDVSRegReq)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF50E_in)
			{
		      VEMS_vidGET(Ext_bVSRegDVSRegReq, Local_Ext_bVSRegDVSRegReq);
		      VEMS_vidSET(Ext_bVSRegDVSRegReq, Local_Ext_bVSRegDVSRegReq);
			}
		}
		VEMS_vidGET(Ctrl_stVSCtlReq, Local_bCtrl_stVSCtlReq);
		if (ACTIVATED == Local_bCtrl_stVSCtlReq)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF50E_in)
			{
		      VEMS_vidGET(Ext_stVSCtlReq, Local_Ext_stVSCtlReq);
		      VEMS_vidSET(Ext_stVSCtlReq, Local_Ext_stVSCtlReq);
			}
		}
		VEMS_vidGET(Ctrl_bVSLimReq, Local_bCtrl_bVSLimReq);
		if (ACTIVATED == Local_bCtrl_bVSLimReq)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF50E_in)
			{
		      VEMS_vidGET(Ext_bVSLimReq, Local_Ext_bVSLimReq);
		      VEMS_vidSET(Ext_bVSLimReq, Local_Ext_bVSLimReq);
			}
		}
		VEMS_vidGET(Ctrl_ctBSIFrame, Local_bCtrl_ctBSIFrame);
		if (ACTIVATED == Local_bCtrl_ctBSIFrame)
		{
			if (FHCAN_STORED == FRM_bAcvRcvF50E_in)
			{
		      VEMS_vidGET(Ext_ctBSIFrame, Local_Ext_ctBSIFrame);
		      VEMS_vidSET(Ext_ctBSIFrame, Local_Ext_ctBSIFrame);
			}
		}
	}
	else
	{
		Ext_bMonRunBSIAbsent = FHCAN_DISABLE;
		Ext_bDgoBSIAbsent = FHCAN_NOT_DETECTED;
		Ext_bMonRunMissF50E = FHCAN_DISABLE;
		Ext_bMonRunShoF50E = FHCAN_DISABLE;
		Ext_bMonRunInvldF50EPM1386 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF50EP046 = FHCAN_DISABLE;
		Ext_bMonRunInvldF50EP046 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF50EP417 = FHCAN_DISABLE;
		Ext_bMonRunInvldF50EP210 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF50EP208 = FHCAN_DISABLE;

		Ext_bDgoMissF50E = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF50E = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF50EPM1386 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF50EP046 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF50EP046 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF50EP417 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF50EP210 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF50EP208 = FHCAN_NOT_DETECTED;
	}
}

void FHCANF50E_vidUpdateSignalP232(void)
{
	boolean FRM_bAcvRcvF50E_in;
   uint8 u8LocalExt_noCks50E;

	uint8 Local_Ext_noCks50E;

	FRM_bAcvRcvF50E_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF50E);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF50E_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF50E)
	   )
	{
      u8LocalExt_noCks50E = (uint8)(MATHSRV_udtMIN(ISCAN_u8N2F50EP232,
                                             3));
      VEMS_vidSET(Ext_noCks50E,
                  u8LocalExt_noCks50E);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF50E_in)
      {
			VEMS_vidGET(Ext_noCks50E, Local_Ext_noCks50E);
			VEMS_vidSET(Ext_noCks50E, Local_Ext_noCks50E);
		}
	}
}

void FHCANF50E_vidUpdateSignalPM1386(void)
{
	boolean FRM_bAcvRcvF50EPM1386_in;
	boolean FRM_bAcvRcvF50E_in;

	FRM_bAcvRcvF50EPM1386_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF50EPM1386);
	FRM_bAcvRcvF50E_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF50E);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF50EPM1386_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF50E_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF50EPM1386)
	   && (FHCAN_DETECTED != Ext_bDgoShoF50E)
	   )
	{
      VEMS_vidSET(Ext_bDgoBody,
                  ISCAN_bF50EPM1386);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF50EPM1386_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF50E_in))
      {
			VEMS_vidSET(Ext_bDgoBody, Ext_bDgoBodyRcf_C);
		}
	}
}

void FHCANF50E_vidUpdateSignalP209(void)
{
	boolean FRM_bAcvRcvF50E_in;

	FRM_bAcvRcvF50E_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF50E);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF50E_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF50E)
	   )
	{
      VEMS_vidSET(AC_bACClu,
                  ISCAN_bF50EP209);
      VEMS_vidSET(Ext_bACCluAuth,
                  ISCAN_bF50EP209);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF50E_in)
      {
			VEMS_vidSET(AC_bACClu, AC_bACCluRcf_C);
		}
	}
}

void FHCANF50E_vidUpdateSignalP046(void)
{
	boolean FRM_bAcvRcvF50EP046_in;
	boolean FRM_bAcvRcvF50E_in;
   uint16 u16LocalIscanCLIM_50E;
   uint8 u8LocalAC_rSpdFanReq;

	FRM_bAcvRcvF50EP046_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF50EP046);
	FRM_bAcvRcvF50E_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF50E);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF50EP046_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF50E_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF50EP046)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF50EP046)
	   && (FHCAN_DETECTED != Ext_bDgoShoF50E)
	   )
	{
      u16LocalIscanCLIM_50E = (uint16)(2 * ISCAN_u8N6F50EP046);
      u8LocalAC_rSpdFanReq = (uint8)(MATHSRV_udtMIN(u16LocalIscanCLIM_50E,
                                             110));
      VEMS_vidSET(AC_rSpdFanReq,
                  u8LocalAC_rSpdFanReq);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF50EP046_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF50E_in))
      {
			VEMS_vidSET(AC_rSpdFanReq, AC_rSpdFanReqRcf_C);
		}
	}
}

void FHCANF50E_vidUpdateSignalPM1425(void)
{
	boolean FRM_bAcvRcvF50E_in;

	FRM_bAcvRcvF50E_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF50E);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF50E_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF50E)
	   )
	{
		switch (ISCAN_u8N2F50EPM1425)
		{
		case 0:
      VEMS_vidSET(CoReqVeh_stEngRStrtReq, 0);
			break;
		case 1:
      VEMS_vidSET(CoReqVeh_stEngRStrtReq, 4);
			break;
		case 2:
      VEMS_vidSET(CoReqVeh_stEngRStrtReq, 1);
			break;
		case 3:
      VEMS_vidSET(CoReqVeh_stEngRStrtReq, 3);
			break;
		default:	
		break;
		}
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF50E_in)
      {
			VEMS_vidSET(CoReqVeh_stEngRStrtReq, CoReqVeh_stEngRStrtReqRcf_C);
		}
	}
}

void FHCANF50E_vidUpdateSignalP189(void)
{
	boolean FRM_bAcvRcvF50E_in;

	FRM_bAcvRcvF50E_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF50E);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF50E_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF50E)
	   )
	{
      VEMS_vidSET(AltCtl_bCmpReq,
                  ISCAN_bF50EP189);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF50E_in)
      {
			VEMS_vidSET(AltCtl_bCmpReq, AltCtl_bCmpReqRcf_C);
		}
	}
}

void FHCANF50E_vidUpdateSignalPM1388(void)
{
	boolean FRM_bAcvRcvF50E_in;
   uint8 u8LocalCoReqVeh_stEngStopAuth;

	FRM_bAcvRcvF50E_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF50E);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF50E_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF50E)
	   )
	{
      u8LocalCoReqVeh_stEngStopAuth = (uint8)(MATHSRV_udtMIN(ISCAN_u8N2F50EPM1388,
                                             3));
      VEMS_vidSET(CoReqVeh_stEngStopAuth,
                  u8LocalCoReqVeh_stEngStopAuth);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF50E_in)
      {
			VEMS_vidSET(CoReqVeh_stEngStopAuth, CoReqVeh_stEngStopAuthRcf_C);
		}
	}
}

void FHCANF50E_vidUpdateSignalP417(void)
{
	boolean FRM_bAcvRcvF50EP417_in;
	boolean FRM_bAcvRcvF50E_in;

	FRM_bAcvRcvF50EP417_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF50EP417);
	FRM_bAcvRcvF50E_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF50E);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF50EP417_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF50E_in)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF50EP417)
	   && (FHCAN_DETECTED != Ext_bDgoShoF50E)
	   )
	{
		if (ISCAN_u8N2F50EP417 == 1)
		{
         VEMS_vidSET(Veh_stDrvAvl, 0);
		}
		else
		{
			if (ISCAN_u8N2F50EP417 == 2)
			{
            VEMS_vidSET(Veh_stDrvAvl, 1);
			}
		}
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF50EP417_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF50E_in))
      {
			VEMS_vidSET(Veh_stDrvAvl, Veh_stDrvAvlRcf_C);
		}
	}
}

void FHCANF50E_vidUpdateSignalP210(void)
{
	boolean FRM_bAcvRcvF50EP210_in;
	boolean FRM_bAcvRcvF50E_in;
   uint8 u8LocalAC_pwrAC;

	FRM_bAcvRcvF50EP210_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF50EP210);
	FRM_bAcvRcvF50E_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF50E);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF50EP210_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF50E_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF50EP210)
	   && (FHCAN_DETECTED != Ext_bDgoShoF50E)
	   )
	{
      u8LocalAC_pwrAC = (uint8)(MATHSRV_udtMIN(ISCAN_u8N8F50EP210,
                                             254));
      VEMS_vidSET(AC_pwrAC,
                  u8LocalAC_pwrAC);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF50EP210_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF50E_in))
      {
			VEMS_vidSET(AC_pwrAC, AC_pwrACRcf_C);
		}
	}
}

void FHCANF50E_vidUpdateSignalP208(void)
{
	boolean FRM_bAcvRcvF50EP208_in;
	boolean FRM_bAcvRcvF50E_in;
   uint16 u16LocalIscanCLIM_50E;
   uint16 u16LocalClm_nTarIdl;

	FRM_bAcvRcvF50EP208_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF50EP208);
	FRM_bAcvRcvF50E_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF50E);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF50EP208_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF50E_in)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF50EP208)
	   && (FHCAN_DETECTED != Ext_bDgoShoF50E)
	   )
	{
      u16LocalIscanCLIM_50E = (uint16)(32 * ISCAN_u8N8F50EP208);
      u16LocalClm_nTarIdl = (uint16)(MATHSRV_udtMIN(u16LocalIscanCLIM_50E,
                                             32000));
      VEMS_vidSET(Clm_nTarIdl,
                  u16LocalClm_nTarIdl);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF50EP208_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF50E_in))
      {
			VEMS_vidSET(Clm_nTarIdl, Clm_nTarIdlRcf_C);
		}
	}
}

void FHCANF50E_vidUpdateSignalP219(void)
{
	boolean FRM_bAcvRcvF50E_in;
   uint8 u8LocalExt_spdVehVSCtlReq;

	uint8 Local_Ext_spdVehVSCtlReq;

	FRM_bAcvRcvF50E_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF50E);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF50E_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF50E)
	   )
	{
      u8LocalExt_spdVehVSCtlReq = ISCAN_u8N8F50EP219;
      VEMS_vidSET(Ext_spdVehVSCtlReq,
                  u8LocalExt_spdVehVSCtlReq);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF50E_in)
      {
			VEMS_vidGET(Ext_spdVehVSCtlReq, Local_Ext_spdVehVSCtlReq);
			VEMS_vidSET(Ext_spdVehVSCtlReq, Local_Ext_spdVehVSCtlReq);
		}
	}
}

void FHCANF50E_vidUpdateSignalP220(void)
{
	boolean FRM_bAcvRcvF50E_in;

	boolean Local_Ext_bVSRegDVSRegReq;

	FRM_bAcvRcvF50E_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF50E);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF50E_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF50E)
	   )
	{
      VEMS_vidSET(Ext_bVSRegDVSRegReq,
                  ISCAN_bF50EP220);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF50E_in)
      {
			VEMS_vidGET(Ext_bVSRegDVSRegReq, Local_Ext_bVSRegDVSRegReq);
			VEMS_vidSET(Ext_bVSRegDVSRegReq, Local_Ext_bVSRegDVSRegReq);
		}
	}
}

void FHCANF50E_vidUpdateSignalP221(void)
{
	boolean FRM_bAcvRcvF50E_in;
   uint8 u8LocalExt_stVSCtlReq;
   uint8 u8LocalExt_stModRegVSCtlReq;

	uint8 Local_Ext_stVSCtlReq;

	FRM_bAcvRcvF50E_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF50E);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF50E_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF50E)
	   )
	{
      u8LocalExt_stVSCtlReq = (uint8)(MATHSRV_udtMIN(ISCAN_u8N2F50EP221,
                                             3));
      VEMS_vidSET(Ext_stVSCtlReq,
                  u8LocalExt_stVSCtlReq);
      u8LocalExt_stModRegVSCtlReq = (uint8)(MATHSRV_udtMIN(ISCAN_u8N2F50EP221,
                                             3));
      VEMS_vidSET(Ext_stModRegVSCtlReq,
                  u8LocalExt_stModRegVSCtlReq);
		if (ISCAN_u8N2F50EP221 == 1)
		{
         VEMS_vidSET(Cc_regulation_speed_on_mux, 1);
         VEMS_vidSET(Cc_limitation_speed_on_mux, 0);
         VEMS_vidSET(Cc_acc_regulation_type_mux, 0);
		}
		else
		{
         VEMS_vidSET(Cc_regulation_speed_on_mux, 0);
			if (ISCAN_u8N2F50EP221 == 2)
			{
            VEMS_vidSET(Cc_limitation_speed_on_mux, 1);
            VEMS_vidSET(Cc_acc_regulation_type_mux, 0);
			}
			else
			{
            VEMS_vidSET(Cc_limitation_speed_on_mux, 0);
				if (ISCAN_u8N2F50EP221 == 3)
				{
               VEMS_vidSET(Cc_acc_regulation_type_mux, 1);
				}
				else
				{
               VEMS_vidSET(Cc_acc_regulation_type_mux, 0);
				}
			}   
		}
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF50E_in)
      {
			VEMS_vidGET(Ext_stVSCtlReq, Local_Ext_stVSCtlReq);
			VEMS_vidSET(Ext_stVSCtlReq, Local_Ext_stVSCtlReq);
		}
	}
}

void FHCANF50E_vidUpdateSignalP222(void)
{
	boolean FRM_bAcvRcvF50E_in;

	boolean Local_Ext_bVSLimReq;

	FRM_bAcvRcvF50E_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF50E);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF50E_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF50E)
	   )
	{
      VEMS_vidSET(Ext_bVSLimReq,
                  ISCAN_bF50EP222);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF50E_in)
      {
			VEMS_vidGET(Ext_bVSLimReq, Local_Ext_bVSLimReq);
			VEMS_vidSET(Ext_bVSLimReq, Local_Ext_bVSLimReq);
		}
	}
}

void FHCANF50E_vidUpdateSignalP231(void)
{
	boolean FRM_bAcvRcvF50E_in;
   uint8 u8LocalExt_ctBSIFrame;

	uint8 Local_Ext_ctBSIFrame;

	FRM_bAcvRcvF50E_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF50E);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF50E_in)
	   && (FHCAN_DETECTED != Ext_bDgoShoF50E)
	   )
	{
      u8LocalExt_ctBSIFrame = (uint8)(MATHSRV_udtMIN(ISCAN_u8N4F50EP231,
                                             15));
      VEMS_vidSET(Ext_ctBSIFrame,
                  u8LocalExt_ctBSIFrame);
	}
	else
	{
		if (FHCAN_STORED == FRM_bAcvRcvF50E_in)
      {
			VEMS_vidGET(Ext_ctBSIFrame, Local_Ext_ctBSIFrame);
			VEMS_vidSET(Ext_ctBSIFrame, Local_Ext_ctBSIFrame);
		}
	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
