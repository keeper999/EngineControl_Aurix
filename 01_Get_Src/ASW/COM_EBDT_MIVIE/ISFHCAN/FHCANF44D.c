/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: FHCANF44D.c */

#include "ISFHCAN_DEF.H"
#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "FHCANF44D.H"
#include "FHCANF44D_PRIVATE.H"
#include "CTRLCFG.H"
#include "GDGAR.H"
#include "COM.h"
#include "VEMS.h"

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void FHCAN_vidInit_Rx_44D(void)
{
	ISCAN_u16N16F44DFP0535 = 0;
	ISCAN_u16N16F44DP330 = 0;
	ISCAN_u16N16F44DP331 = 0;
	ISCAN_u16N16F44DP354 = 0;

	VEMS_vidSET(Ext_spdVehAvrFrntWhl, 0);
	VEMS_vidSET(Ext_vLeReWhlMes, 0);
	VEMS_vidSET(Ext_vRiReWhlMes, 0);
	VEMS_vidSET(Ext_nAvrFrntWhl, 0);
	VEMS_vidSET(Ext_nAvrFrntWhlCAN, 0);
	VEMS_vidSET(Ext_nFrntWhl, 0);

	Ext_bMonRunMissF44D = FHCAN_DISABLE;
	Ext_bMonRunShoF44D = FHCAN_DISABLE;
	Ext_bMonRunInvldF44DFP0535 = FHCAN_DISABLE;
	Ext_bMonRunInvldF44DP330 = FHCAN_DISABLE;
	Ext_bMonRunInvldF44DP331 = FHCAN_DISABLE;
	Ext_bMonRunFrbdF44DP354 = FHCAN_DISABLE;
	Ext_bMonRunInvldF44DP354 = FHCAN_DISABLE;

	Ext_bDgoMissF44D = FHCAN_NOT_DETECTED;
	Ext_bDgoShoF44D = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF44DFP0535 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF44DP330 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF44DP331 = FHCAN_NOT_DETECTED;
	Ext_bDgoFrbdF44DP354 = FHCAN_NOT_DETECTED;
	Ext_bDgoInvldF44DP354 = FHCAN_NOT_DETECTED;
}

void FHCANF44D_vidFrameReceived(void)
{
	boolean Local_bCtrl_ABR_44D;
	boolean Local_bCtrl_spdVehAvrFrntWhl;
	boolean Local_bCtrl_vLeReWhlMes;
	boolean Local_bCtrl_vRiReWhlMes;
	boolean Local_bCtrl_nAvrFrntWhl;

	VEMS_vidGET(Ctrl_ABR_44D, Local_bCtrl_ABR_44D);
	if (ACTIVATED == Local_bCtrl_ABR_44D)
	{
		ISCAN_EveRxn_44D();
		FHCAN44D_vidCalcMonWindow();

	  	if (FHCAN_ENABLE == Ext_bMonRunMissF44D)
      {
         Ext_bDgoMissF44D = FHCAN_NOT_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF44D,
                  Ext_bDgoMissF44D,
                  Ext_bMonRunMissF44D,
                  DIAG_DISPO);
      }
            
		VEMS_vidGET(Ctrl_spdVehAvrFrntWhl, Local_bCtrl_spdVehAvrFrntWhl);
		if (ACTIVATED == Local_bCtrl_spdVehAvrFrntWhl)
		{
			FHCAN44D_vidCalcMonFFP0535Window();
			Com_ReceiveSignal(Com_VITESSE_VEH_ROUES_AV_ABR_44D, (void*) &ISCAN_u16N16F44DFP0535);

			FHCAN44D_vidMonInvldFP0535Update();

			FHCANF44D_vidUpdateSignalFP0535();
		}
		else
		{
			VEMS_vidSET(Ext_spdVehAvrFrntWhl, 0);

			Ext_bMonRunInvldF44DFP0535 = FHCAN_DISABLE;
			Ext_bDgoInvldF44DFP0535 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_vLeReWhlMes, Local_bCtrl_vLeReWhlMes);
		if (ACTIVATED == Local_bCtrl_vLeReWhlMes)
		{
			FHCAN44D_vidCalcMonFP330Window();
			Com_ReceiveSignal(Com_VITESSE_ROUE_ARG_ABR_44D, (void*) &ISCAN_u16N16F44DP330);

			FHCAN44D_vidMonInvldP330Update();

			FHCANF44D_vidUpdateSignalP330();
		}
		else
		{
			VEMS_vidSET(Ext_vLeReWhlMes, 0);

			Ext_bMonRunInvldF44DP330 = FHCAN_DISABLE;
			Ext_bDgoInvldF44DP330 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_vRiReWhlMes, Local_bCtrl_vRiReWhlMes);
		if (ACTIVATED == Local_bCtrl_vRiReWhlMes)
		{
			FHCAN44D_vidCalcMonFP331Window();
			Com_ReceiveSignal(Com_VITESSE_ROUE_ARD_ABR_44D, (void*) &ISCAN_u16N16F44DP331);

			FHCAN44D_vidMonInvldP331Update();

			FHCANF44D_vidUpdateSignalP331();
		}
		else
		{
			VEMS_vidSET(Ext_vRiReWhlMes, 0);

			Ext_bMonRunInvldF44DP331 = FHCAN_DISABLE;
			Ext_bDgoInvldF44DP331 = FHCAN_NOT_DETECTED;
		}
		VEMS_vidGET(Ctrl_nAvrFrntWhl, Local_bCtrl_nAvrFrntWhl);
		if (ACTIVATED == Local_bCtrl_nAvrFrntWhl)
		{
			FHCAN44D_vidCalcMonFP354Window();
			Com_ReceiveSignal(Com_REGIME_MOYEN_ROUES_AV_ABR_44D, (void*) &ISCAN_u16N16F44DP354);

			FHCAN44D_vidMonInvldP354Update();
			FHCAN44D_vidMonFrbdP354Update();

			FHCANF44D_vidUpdateSignalP354();
		}
		else
		{
			VEMS_vidSET(Ext_nAvrFrntWhl, 0);
			VEMS_vidSET(Ext_nAvrFrntWhlCAN, 0);
			VEMS_vidSET(Ext_nFrntWhl, 0);

			Ext_bMonRunFrbdF44DP354 = FHCAN_DISABLE;
			Ext_bMonRunInvldF44DP354 = FHCAN_DISABLE;
			Ext_bDgoFrbdF44DP354 = FHCAN_NOT_DETECTED;
			Ext_bDgoInvldF44DP354 = FHCAN_NOT_DETECTED;
		}
	}
	else
	{
		Ext_bMonRunMissF44D = FHCAN_DISABLE;
		Ext_bMonRunShoF44D = FHCAN_DISABLE;
		Ext_bMonRunInvldF44DFP0535 = FHCAN_DISABLE;
		Ext_bMonRunInvldF44DP330 = FHCAN_DISABLE;
		Ext_bMonRunInvldF44DP331 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF44DP354 = FHCAN_DISABLE;
		Ext_bMonRunInvldF44DP354 = FHCAN_DISABLE;

		Ext_bDgoMissF44D = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF44D = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF44DFP0535 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF44DP330 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF44DP331 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF44DP354 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF44DP354 = FHCAN_NOT_DETECTED;
	}
}



void FHCANF44D_vidFrameNotReceived(void)
{
	boolean FRM_bAcvRcvF44DFP0535_in;
	boolean FRM_bAcvRcvF44DP330_in;
	boolean FRM_bAcvRcvF44DP331_in;
	boolean FRM_bAcvRcvF44DP354_in;
	boolean FRM_bAcvRcvF44D_in;
	boolean Local_bCtrl_ABR_44D;
	boolean Local_bCtrl_spdVehAvrFrntWhl;
	boolean Local_bCtrl_vLeReWhlMes;
	boolean Local_bCtrl_vRiReWhlMes;
	boolean Local_bCtrl_nAvrFrntWhl;


	VEMS_vidGET(Ctrl_ABR_44D, Local_bCtrl_ABR_44D);
	if (ACTIVATED == Local_bCtrl_ABR_44D)
	{
		FHCAN44D_vidCalcMonWindow();

      if (FHCAN_ENABLE == Ext_bMonRunMissF44D)
      {
         Ext_bDgoMissF44D = FHCAN_DETECTED;
         GDGAR_vidGdu(GD_DFT_MISSF44D,
                  Ext_bDgoMissF44D,
                  Ext_bMonRunMissF44D,
                  DIAG_DISPO);
      }
      else
      {
		   VEMS_vidSET(Ext_spdVehAvrFrntWhl, 0);
		   VEMS_vidSET(Ext_vLeReWhlMes, 0);
		   VEMS_vidSET(Ext_vRiReWhlMes, 0);
		   VEMS_vidSET(Ext_nAvrFrntWhl, 0);
		   VEMS_vidSET(Ext_nAvrFrntWhlCAN, 0);
		   VEMS_vidSET(Ext_nFrntWhl, 0);
      }

		FRM_bAcvRcvF44DFP0535_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF44DFP0535);
		FRM_bAcvRcvF44DP330_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF44DP330);
		FRM_bAcvRcvF44DP331_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF44DP331);
		FRM_bAcvRcvF44DP354_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF44DP354);
		FRM_bAcvRcvF44D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF44D);

		VEMS_vidGET(Ctrl_spdVehAvrFrntWhl, Local_bCtrl_spdVehAvrFrntWhl);
		if (ACTIVATED == Local_bCtrl_spdVehAvrFrntWhl)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF44DFP0535_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF44D_in))
			{
		      VEMS_vidSET(Ext_spdVehAvrFrntWhl, Ext_spdVehAvrFrntWhlRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_vLeReWhlMes, Local_bCtrl_vLeReWhlMes);
		if (ACTIVATED == Local_bCtrl_vLeReWhlMes)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF44DP330_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF44D_in))
			{
		      VEMS_vidSET(Ext_vLeReWhlMes, Ext_vLeReWhlMesRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_vRiReWhlMes, Local_bCtrl_vRiReWhlMes);
		if (ACTIVATED == Local_bCtrl_vRiReWhlMes)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF44DP331_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF44D_in))
			{
		      VEMS_vidSET(Ext_vRiReWhlMes, Ext_vRiReWhlMesRcf_C);
			}
		}
		VEMS_vidGET(Ctrl_nAvrFrntWhl, Local_bCtrl_nAvrFrntWhl);
		if (ACTIVATED == Local_bCtrl_nAvrFrntWhl)
		{
			if (  (FHCAN_STORED == FRM_bAcvRcvF44DP354_in)
			   || (FHCAN_STORED == FRM_bAcvRcvF44D_in))
			{
		      VEMS_vidSET(Ext_nAvrFrntWhl, Ext_nAvrFrntWhlRcf_C);
			}
		}
	}
	else
	{
		Ext_bMonRunMissF44D = FHCAN_DISABLE;
		Ext_bMonRunShoF44D = FHCAN_DISABLE;
		Ext_bMonRunInvldF44DFP0535 = FHCAN_DISABLE;
		Ext_bMonRunInvldF44DP330 = FHCAN_DISABLE;
		Ext_bMonRunInvldF44DP331 = FHCAN_DISABLE;
		Ext_bMonRunFrbdF44DP354 = FHCAN_DISABLE;
		Ext_bMonRunInvldF44DP354 = FHCAN_DISABLE;

		Ext_bDgoMissF44D = FHCAN_NOT_DETECTED;
		Ext_bDgoShoF44D = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF44DFP0535 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF44DP330 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF44DP331 = FHCAN_NOT_DETECTED;
		Ext_bDgoFrbdF44DP354 = FHCAN_NOT_DETECTED;
		Ext_bDgoInvldF44DP354 = FHCAN_NOT_DETECTED;
	}
}

void FHCANF44D_vidUpdateSignalFP0535(void)
{
	boolean FRM_bAcvRcvF44DFP0535_in;
	boolean FRM_bAcvRcvF44D_in;
   uint32 u32LocalIscanABR_44D;
   uint16 u16LocalExt_spdVehAvrFrntWhl;

	FRM_bAcvRcvF44DFP0535_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF44DFP0535);
	FRM_bAcvRcvF44D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF44D);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF44DFP0535_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF44D_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF44DFP0535)
	   && (FHCAN_DETECTED != Ext_bDgoShoF44D)
	   )
	{
      u32LocalIscanABR_44D = (uint32)(((32 * ISCAN_u16N16F44DFP0535) / 25));
      u16LocalExt_spdVehAvrFrntWhl = (uint16)(MATHSRV_udtMIN(u32LocalIscanABR_44D,
                                             32640));
      VEMS_vidSET(Ext_spdVehAvrFrntWhl,
                  u16LocalExt_spdVehAvrFrntWhl);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF44DFP0535_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF44D_in))
      {
			VEMS_vidSET(Ext_spdVehAvrFrntWhl, Ext_spdVehAvrFrntWhlRcf_C);
		}
	}
}

void FHCANF44D_vidUpdateSignalP330(void)
{
	boolean FRM_bAcvRcvF44DP330_in;
	boolean FRM_bAcvRcvF44D_in;
   uint16 u16LocalExt_vLeReWhlMes;

	FRM_bAcvRcvF44DP330_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF44DP330);
	FRM_bAcvRcvF44D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF44D);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF44DP330_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF44D_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF44DP330)
	   && (FHCAN_DETECTED != Ext_bDgoShoF44D)
	   )
	{
      u16LocalExt_vLeReWhlMes = (uint16)(MATHSRV_udtMIN(ISCAN_u16N16F44DP330,
                                             65534));
      VEMS_vidSET(Ext_vLeReWhlMes,
                  u16LocalExt_vLeReWhlMes);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF44DP330_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF44D_in))
      {
			VEMS_vidSET(Ext_vLeReWhlMes, Ext_vLeReWhlMesRcf_C);
		}
	}
}

void FHCANF44D_vidUpdateSignalP331(void)
{
	boolean FRM_bAcvRcvF44DP331_in;
	boolean FRM_bAcvRcvF44D_in;
   uint16 u16LocalExt_vRiReWhlMes;

	FRM_bAcvRcvF44DP331_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF44DP331);
	FRM_bAcvRcvF44D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF44D);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF44DP331_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF44D_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF44DP331)
	   && (FHCAN_DETECTED != Ext_bDgoShoF44D)
	   )
	{
      u16LocalExt_vRiReWhlMes = (uint16)(MATHSRV_udtMIN(ISCAN_u16N16F44DP331,
                                             65534));
      VEMS_vidSET(Ext_vRiReWhlMes,
                  u16LocalExt_vRiReWhlMes);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF44DP331_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF44D_in))
      {
			VEMS_vidSET(Ext_vRiReWhlMes, Ext_vRiReWhlMesRcf_C);
		}
	}
}

void FHCANF44D_vidUpdateSignalP354(void)
{
	boolean FRM_bAcvRcvF44DP354_in;
	boolean FRM_bAcvRcvF44D_in;
   uint32 u32LocalIscanABR_44D;
   uint16 u16LocalExt_nAvrFrntWhl;
   uint32 u32LocalExt_nAvrFrntWhlCAN;
   uint32 u32LocalExt_nFrntWhl;

	FRM_bAcvRcvF44DP354_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF44DP354);
	FRM_bAcvRcvF44D_in = GDGAR_bGetFRM(FRM_FRM_ACVRCVF44D);


	if (  (FHCAN_NOT_STORED == FRM_bAcvRcvF44DP354_in)
	   && (FHCAN_NOT_STORED == FRM_bAcvRcvF44D_in)
	   && (FHCAN_DETECTED != Ext_bDgoInvldF44DP354)
	   && (FHCAN_DETECTED != Ext_bDgoFrbdF44DP354)
	   && (FHCAN_DETECTED != Ext_bDgoShoF44D)
	   )
	{
      u32LocalIscanABR_44D = (uint32)(((32 * ISCAN_u16N16F44DP354) / 25));
      u16LocalExt_nAvrFrntWhl = (uint16)(MATHSRV_udtMIN(u32LocalIscanABR_44D,
                                             83872));
      VEMS_vidSET(Ext_nAvrFrntWhl,
                  u16LocalExt_nAvrFrntWhl);
      u32LocalIscanABR_44D = (uint32)(((32 * ISCAN_u16N16F44DP354) / 25));
      u32LocalExt_nAvrFrntWhlCAN = (uint32)(MATHSRV_udtMIN(u32LocalIscanABR_44D,
                                             83872));
      VEMS_vidSET(Ext_nAvrFrntWhlCAN,
                  u32LocalExt_nAvrFrntWhlCAN);
      u32LocalIscanABR_44D = (uint32)(((128 * ISCAN_u16N16F44DP354) / 25));
      u32LocalExt_nFrntWhl = (uint32)(MATHSRV_udtMIN(u32LocalIscanABR_44D,
                                             1280000));
      VEMS_vidSET(Ext_nFrntWhl,
                  u32LocalExt_nFrntWhl);
	}
	else
	{
		if (  (FHCAN_STORED == FRM_bAcvRcvF44DP354_in)
		   || (FHCAN_STORED == FRM_bAcvRcvF44D_in))
      {
			VEMS_vidSET(Ext_nAvrFrntWhl, Ext_nAvrFrntWhlRcf_C);
		}
	}
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"
