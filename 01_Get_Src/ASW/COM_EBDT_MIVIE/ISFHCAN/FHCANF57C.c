/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF57C.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF57C.H"
#include "FHCANF57C_PRIVATE.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_57C(void)
{
	ISCAN_u8N3F57CPM1418 = 0;

	VEMS_vidSET(Ext_bVSSNwAcvSt, 0);
	Ext_bMonRunDMTRAbsent = FHCAN_DISABLE;
	Ext_bDgoDMTRAbsent = FHCAN_NOT_DETECTED;

	Ext_bMonRunMissF57C = FHCAN_DISABLE;
	Ext_bMonRunShoF57C = FHCAN_DISABLE;
	Ext_bMonRunInvldF57CPM1418 = FHCAN_DISABLE;

	Ext_bDgoMissF57C = FHCAN_NOT_DETECTED;
	Ext_bDgoShoF57C = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF57CPM1418 = FHCAN_NOT_DETECTED;
}

void FHCANF57C_vidFrameReceived(void)
{
	boolean Local_bCtrl_DMTR_57C;
	boolean Local_bCtrl_bVSSNwAcvSt;

	VEMS_vidGET(Ctrl_DMTR_57C, Local_bCtrl_DMTR_57C);
	if (ACTIVATED == Local_bCtrl_DMTR_57C)
	{
		ISCAN_EveRxn_57C();
		FHCAN57C_vidCalcMonDMTRWindow();
		FHCAN57C_vidCalcMonWindow();

		if (FHCAN_ENABLE == Ext_bMonRunDMTRAbsent)
		{
			Ext_bDgoDMTRAbsent = FHCAN_NOT_DETECTED;
			GDGAR_vidGdu(GD_DFT_DMTRABSENT,
						Ext_bDgoDMTRAbsent,
						Ext_bMonRunDMTRAbsent,
						DIAG_DISPO);
		}
	  	if (FHCAN_ENABLE == Ext_bMonRunMissF57C)
      {
         Ext_bDgoMissF57C = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF57C,
                  Ext_bDgoMissF57C,
                  Ext_bMonRunMissF57C,
                  DIAG_DISPO);
      }
            
		VEMS_vidGET(Ctrl_bVSSNwAcvSt, Local_bCtrl_bVSSNwAcvSt);
		if (ACTIVATED == Local_bCtrl_bVSSNwAcvSt)
		{
			FHCAN57C_vidCalcMonFPM1418Window();
			Com_ReceiveSignal(Com_ETAT_DMTR_DMTR_57C, (void*) &ISCAN_u8N3F57CPM1418);

			FHCAN57C_vidMonInvldPM1418Update();

			FHCANF57C_vidUpdateSignalPM1418();
		}
		else
		{
			VEMS_vidSET(Ext_bVSSNwAcvSt, 0);

			Ext_bMonRunInvldF57CPM1418 = FHCAN_DISABLE;
			Ext_bDgoInvldF57CPM1418 = FHCAN_NOT_DETECTED;
		}
	}
	else
	{
		Ext_bMonRunDMTRAbsent = FHCAN_DISABLE;
		Ext_bDgoDMTRAbsent = FHCAN_NOT_DETECTED;
		Ext_bMonRunMissF57C = FHCAN_DISABLE;
		Ext_bMonRunShoF57C = FHCAN_DISABLE;
		Ext_bMonRunInvldF57CPM1418 = FHCAN_DISABLE;

		Ext_bDgoMissF57C = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF57C = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF57CPM1418 = FHCAN_NOT_DETECTED;
	}
}



void FHCANF57C_vidFrameNotReceived(void)
{
	boolean FRM_bAcvRcvF57CPM1418_in;
	boolean FRM_bAcvRcvF57C_in;
	boolean Local_bCtrl_DMTR_57C;
	boolean Local_bCtrl_bVSSNwAcvSt;


	VEMS_vidGET(Ctrl_DMTR_57C, Local_bCtrl_DMTR_57C);
	if (ACTIVATED == Local_bCtrl_DMTR_57C)
	{
		FHCAN57C_vidCalcMonDMTRWindow();
		FHCAN57C_vidCalcMonWindow();

		if (FHCAN_ENABLE == Ext_bMonRunDMTRAbsent)
		{
			Ext_bDgoDMTRAbsent = FHCAN_DETECTED;
			GDGAR_vidGdu(GD_DFT_DMTRABSENT,
						Ext_bDgoDMTRAbsent,
						Ext_bMonRunDMTRAbsent,
						DIAG_DISPO);
		}
      if (FHCAN_ENABLE == Ext_bMonRunMissF57C)
      {
         Ext_bDgoMissF57C = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF57C,
                  Ext_bDgoMissF57C,
                  Ext_bMonRunMissF57C,
                  DIAG_DISPO);
      }
      else
      {
		   VEMS_vidSET(Ext_bVSSNwAcvSt, 0);
      }

		FRM_bAcvRcvF57CPM1418_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF57CPM1418);
		FRM_bAcvRcvF57C_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF57C);

		VEMS_vidGET(Ctrl_bVSSNwAcvSt, Local_bCtrl_bVSSNwAcvSt);
		if (ACTIVATED == Local_bCtrl_bVSSNwAcvSt)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF57CPM1418_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF57C_in))
			{
		      VEMS_vidSET(Ext_bVSSNwAcvSt, Ext_bVSSNwAcvStRcf_C);
			}
		}
	}
	else
	{
		Ext_bMonRunDMTRAbsent = FHCAN_DISABLE;
		Ext_bDgoDMTRAbsent = FHCAN_NOT_DETECTED;
		Ext_bMonRunMissF57C = FHCAN_DISABLE;
		Ext_bMonRunShoF57C = FHCAN_DISABLE;
		Ext_bMonRunInvldF57CPM1418 = FHCAN_DISABLE;

		Ext_bDgoMissF57C = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF57C = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF57CPM1418 = FHCAN_NOT_DETECTED;
	}
}

void FHCANF57C_vidUpdateSignalPM1418(void)
{
	boolean FRM_bAcvRcvF57CPM1418_in;
	boolean FRM_bAcvRcvF57C_in;

	FRM_bAcvRcvF57CPM1418_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF57CPM1418);
	FRM_bAcvRcvF57C_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF57C);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF57CPM1418_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF57C_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF57CPM1418)
	   && (FHCAN_DETECTED != Ext_bDgoShoF57C)
	   )
	{
      if (ISCAN_u8N3F57CPM1418 >= 1)
      {
         VEMS_vidSET(Ext_bVSSNwAcvSt, 1);
      }
      else
      {
         VEMS_vidSET(Ext_bVSSNwAcvSt, 0);
      }
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF57CPM1418_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF57C_in))
      {
			VEMS_vidSET(Ext_bVSSNwAcvSt, Ext_bVSSNwAcvStRcf_C);
		}
	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
