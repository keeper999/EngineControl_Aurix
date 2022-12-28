/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : OBDSRV06                                                */
/* !Description     : OBDSRV06 Component                                      */
/*                                                                            */
/* !Module          : OBDSRV06                                                */
/* !Description     : Definition des Trames EOBD pour le Mode06               */
/*                                                                            */
/* !File            : OBDSRV06_API.c                                          */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : 32BIT                                                   */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / GetDTRValue_OBDMID01_TID01                                           */
/*   2 / GetDTRValue_OBDMID01_TID02                                           */
/*   3 / GetDTRValue_OBDMID01_TID03                                           */
/*   4 / GetDTRValue_OBDMID01_TID04                                           */
/*   5 / GetDTRValue_OBDMID01_TID07                                           */
/*   6 / GetDTRValue_OBDMID01_TID08                                           */
/*   7 / GetDTRValue_OBDMID01_TID0A                                           */
/*   8 / GetDTRValue_OBDMID01_TIDA0                                           */
/*   9 / GetDTRValue_OBDMID01_TIDA1                                           */
/*   10 / GetDTRValue_OBDMID02_TID01                                          */
/*   11 / GetDTRValue_OBDMID02_TID02                                          */
/*   12 / GetDTRValue_OBDMID02_TID03                                          */
/*   13 / GetDTRValue_OBDMID02_TID04                                          */
/*   14 / GetDTRValue_OBDMID02_TID07                                          */
/*   15 / GetDTRValue_OBDMID02_TID08                                          */
/*   16 / GetDTRValue_OBDMID02_TIDC0                                          */
/*   17 / GetDTRValue_OBDMID02_TIDC1                                          */
/*   18 / GetDTRValue_OBDMID02_TIDC2                                          */
/*   19 / GetDTRValue_OBDMID21_TID81                                          */
/*   20 / GetDTRValue_OBDMID41_TIDD0                                          */
/*   21 / GetDTRValue_OBDMID42_TIDDA                                          */
/*   22 / GetDTRValue_OBDMIDA2_TID0B                                          */
/*   23 / GetDTRValue_OBDMIDA2_TID0C                                          */
/*   24 / GetDTRValue_OBDMIDA3_TID0B                                          */
/*   25 / GetDTRValue_OBDMIDA3_TID0C                                          */
/*   26 / GetDTRValue_OBDMIDA4_TID0B                                          */
/*   27 / GetDTRValue_OBDMIDA4_TID0C                                          */
/*   28 / GetDTRValue_OBDMIDA5_TID0B                                          */
/*   29 / GetDTRValue_OBDMIDA5_TID0C                                          */
/*                                                                            */
/* !Reference   : V02 NT 11 04787 / 03                                        */
/* !OtherRefs   : VEMS V02 ECU#061812                                         */
/* !OtherRefs   : VEMS V02 ECU#062507                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/OBD_HAT/OBDSRV06/OBDSRV06_API.c_$*/
/* $Revision::   1.8      $$Author::   pbakabad       $$Date::   Jul 05 2013 $*/
/* $Author::   pbakabad                               $$Date::   Jul 05 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "OBDSRV06_im.h"
#include "OBDSRV06.h"
#include "OBDSRV06_L.h"
#include "VEMS.h"
#include "GDGAR.H"
#include "SWFAIL.h"
#include "MATHSRV.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GetDTRValue_OBDMID01_TID01                                 */
/* !Description :  Sonde Amont : OBDMID 01, TID 01                            */
/* !Number      :  API.1                                                      */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Manu_inh_mode_6_scantool;                                   */
/*  input uint8 Mode_6_s1_01_data_a;                                          */
/*  input uint16 Seuil_sonde_amont_pauvre;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GetDTRValue_OBDMID01_TID01
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   if( DCM_INITIAL == OpStatus )
   {
      if( ( FALSE == Manu_inh_mode_6_scantool      ) &&
          ( 0x80 == ( Mode_6_s1_01_data_a & 0x80 ) ) )
      {
         *Testval = Seuil_sonde_amont_pauvre;
         *Minlimit = Seuil_sonde_amont_pauvre;
         *Maxlimit = Seuil_sonde_amont_pauvre;
         *Status = DCM_DTRSTATUS_VISIBLE;
      }
      else
      {
         *Status = DCM_DTRSTATUS_INVISIBLE;
      }

      u8LocalReturn = E_OK;
   }
   else if( DCM_CANCEL == OpStatus )
   {
      u8LocalReturn = E_OK;
   }
   else
   {
      /* Normalement impossible */
      u8LocalReturn = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GetDTRValue_OBDMID01_TID02                                 */
/* !Description :  Sonde Amont : OBDMID 01, TID 02                            */
/* !Number      :  API.2                                                      */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Manu_inh_mode_6_scantool;                                   */
/*  input uint8 Mode_6_s1_01_data_a;                                          */
/*  input uint16 Seuil_sonde_amont_riche;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GetDTRValue_OBDMID01_TID02
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   if( DCM_INITIAL == OpStatus )
   {
      if( ( FALSE == Manu_inh_mode_6_scantool      ) &&
          ( 0x40 == ( Mode_6_s1_01_data_a & 0x40 ) ) )
      {
         *Testval = Seuil_sonde_amont_riche;
         *Minlimit = Seuil_sonde_amont_riche;
         *Maxlimit = Seuil_sonde_amont_riche;
         *Status = DCM_DTRSTATUS_VISIBLE;
      }
      else
      {
         *Status = DCM_DTRSTATUS_INVISIBLE;
      }

      u8LocalReturn = E_OK;
   }
   else if( DCM_CANCEL == OpStatus )
   {
      u8LocalReturn = E_OK;
   }
   else
   {
      /* Normalement impossible */
      u8LocalReturn = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GetDTRValue_OBDMID01_TID03                                 */
/* !Description :  Sonde Amont : OBDMID 01, TID 03                            */
/* !Number      :  API.3                                                      */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Manu_inh_mode_6_scantool;                                   */
/*  input uint8 Mode_6_s1_01_data_a;                                          */
/*  input uint16 Oxy_sens_lower_voltage_thresh_c;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GetDTRValue_OBDMID01_TID03
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   if( DCM_INITIAL == OpStatus )
   {
      if( ( FALSE == Manu_inh_mode_6_scantool      ) &&
          ( 0x20 == ( Mode_6_s1_01_data_a & 0x20 ) ) )
      {
         *Testval = Oxy_sens_lower_voltage_thresh_c;
         *Minlimit = Oxy_sens_lower_voltage_thresh_c;
         *Maxlimit = Oxy_sens_lower_voltage_thresh_c;
         *Status = DCM_DTRSTATUS_VISIBLE;
      }
      else
      {
         *Status = DCM_DTRSTATUS_INVISIBLE;
      }

      u8LocalReturn = E_OK;
   }
   else if( DCM_CANCEL == OpStatus )
   {
      u8LocalReturn = E_OK;
   }
   else
   {
      /* Normalement impossible */
      u8LocalReturn = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GetDTRValue_OBDMID01_TID04                                 */
/* !Description :  Sonde Amont : OBDMID 01, TID 04                            */
/* !Number      :  API.4                                                      */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Manu_inh_mode_6_scantool;                                   */
/*  input uint8 Mode_6_s1_01_data_a;                                          */
/*  input uint16 Oxy_sens_upper_voltage_thresh_c;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GetDTRValue_OBDMID01_TID04
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   if( DCM_INITIAL == OpStatus )
   {
      if( ( FALSE == Manu_inh_mode_6_scantool      ) &&
          ( 0x10 == ( Mode_6_s1_01_data_a & 0x10 ) ) )
      {
         *Testval = Oxy_sens_upper_voltage_thresh_c;
         *Minlimit = Oxy_sens_upper_voltage_thresh_c;
         *Maxlimit = Oxy_sens_upper_voltage_thresh_c;
         *Status = DCM_DTRSTATUS_VISIBLE;
      }
      else
      {
         *Status = DCM_DTRSTATUS_INVISIBLE;
      }

      u8LocalReturn = E_OK;
   }
   else if( DCM_CANCEL == OpStatus )
   {
      u8LocalReturn = E_OK;
   }
   else
   {
      /* Normalement impossible */
      u8LocalReturn = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GetDTRValue_OBDMID01_TID07                                 */
/* !Description :  Sonde Amont : OBDMID 01, TID 07                            */
/* !Number      :  API.5                                                      */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  Dem_GetEventStatus(argin uint16 u16Variable,  */
/*  argout uint8 *u8OutVariable);                                             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Manu_inh_mode_6_scantool;                                   */
/*  input uint8 Mode_6_s1_01_data_a;                                          */
/*  input uint16 Tension_sonde_am_min_cycle;                                  */
/*  input uint16 Tension_sonde_am_max_cycle;                                  */
/*  input boolean Ext_bCondDiag_uUpLs;                                        */
/*  input uint16 Tension_sonde_am_min_cycle_eep;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GetDTRValue_OBDMID01_TID07
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   uint16                      u16LocalMinVar;
   uint16                      u16LocalMaxVar;
   Std_ReturnType              u8LocalReturn;
   Dem_EventStatusExtendedType u8LocalEventStatusExtScg_uUpLs;
   Dem_EventStatusExtendedType u8LocalEventStatusExtScp_uUpLs;
   Dem_EventStatusExtendedType u8LocalEventStatusExtOc_uUpLs;

   if( DCM_INITIAL == OpStatus )
   {
      if( ( FALSE == Manu_inh_mode_6_scantool      ) &&
          ( 0x02 == ( Mode_6_s1_01_data_a & 0x02 ) ) )
      {
         u8LocalReturn = Dem_GetEventStatus( (uint16)GD_DFT_SCG_UUPLS,
                                             &u8LocalEventStatusExtScg_uUpLs );

         if( E_OK == u8LocalReturn )
         {
            u8LocalReturn =
                     Dem_GetEventStatus( (uint16)GD_DFT_SCP_UUPLS,
                                         &u8LocalEventStatusExtScp_uUpLs );

            if( E_OK == u8LocalReturn )
            {
               u8LocalReturn =
                     Dem_GetEventStatus( (uint16)GD_DFT_OC_UUPLS,
                                         &u8LocalEventStatusExtOc_uUpLs );

               if( E_OK == u8LocalReturn )
               {
                  if( ( 0x10 == ( u8LocalEventStatusExtScg_uUpLs & 0x10 ) ) ||
                      ( 0x10 == ( u8LocalEventStatusExtScp_uUpLs & 0x10 ) ) ||
                      ( 0x10 == ( u8LocalEventStatusExtOc_uUpLs & 0x10  ) ) )
                  {
                     *Testval = 0;
                     *Minlimit = 0;
                     *Maxlimit = 0;
                  }
                  else
                  {
                     *Minlimit = 0;
                     *Maxlimit = 0x03FF;

                     VEMS_vidGET(Tension_sonde_am_min_cycle,u16LocalMinVar);
                     VEMS_vidGET(Tension_sonde_am_max_cycle,u16LocalMaxVar);

                     if( ( TRUE == Ext_bCondDiag_uUpLs  ) &&
                         ( ( u16LocalMinVar != 0x03FF ) ||
                           ( u16LocalMaxVar != 0x0000 ) ) )
                     {
                        *Testval =
                           (uint16)MATHSRV_udtMIN(u16LocalMinVar,0x03FE);
                     }
                     else
                     {
                        VEMS_vidGET(Tension_sonde_am_min_cycle_eep,
                           u16LocalMinVar);
                        *Testval = u16LocalMinVar;
                     }
                  }
                  *Status = DCM_DTRSTATUS_VISIBLE;
               }
               else
               {
                  /* u8LocalReturn déjà positionné */
               }
            }
            else
            {
               /* u8LocalReturn déjà positionné */
            }
         }
         else
         {
            /* u8LocalReturn déjà positionné */
         }
      }
      else
      {
         u8LocalReturn = E_OK;
         *Status = DCM_DTRSTATUS_INVISIBLE;
      }
   }
   else if( DCM_CANCEL == OpStatus )
   {
      u8LocalReturn = E_OK;
   }
   else
   {
      /* Normalement impossible */
      u8LocalReturn = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GetDTRValue_OBDMID01_TID08                                 */
/* !Description :  Sonde Amont : OBDMID 01, TID 08                            */
/* !Number      :  API.6                                                      */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  Dem_GetEventStatus(argin uint16 u16Variable,  */
/*  argout uint8 *u8OutVariable);                                             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Manu_inh_mode_6_scantool;                                   */
/*  input uint8 Mode_6_s1_01_data_a;                                          */
/*  input uint16 Tension_sonde_am_min_cycle;                                  */
/*  input uint16 Tension_sonde_am_max_cycle;                                  */
/*  input boolean Ext_bCondDiag_uUpLs;                                        */
/*  input uint16 Tension_sonde_am_max_cycle_eep;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GetDTRValue_OBDMID01_TID08
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   uint16                      u16LocalMinVar;
   uint16                      u16LocalMaxVar;
   Std_ReturnType              u8LocalReturn;
   Dem_EventStatusExtendedType u8LocalEventStatusExtScg_uUpLs;
   Dem_EventStatusExtendedType u8LocalEventStatusExtScp_uUpLs;
   Dem_EventStatusExtendedType u8LocalEventStatusExtOc_uUpLs;

   if( DCM_INITIAL == OpStatus )
   {
      if( ( FALSE == Manu_inh_mode_6_scantool      ) &&
          ( 0x01 == ( Mode_6_s1_01_data_a & 0x01 ) ) )
      {
         u8LocalReturn = Dem_GetEventStatus( (uint16)GD_DFT_SCG_UUPLS,
                                             &u8LocalEventStatusExtScg_uUpLs );

         if( E_OK == u8LocalReturn )
         {
            u8LocalReturn =
                  Dem_GetEventStatus( (uint16)GD_DFT_SCP_UUPLS,
                                      &u8LocalEventStatusExtScp_uUpLs );

            if( E_OK == u8LocalReturn )
            {
               u8LocalReturn =
                  Dem_GetEventStatus( (uint16)GD_DFT_OC_UUPLS,
                                      &u8LocalEventStatusExtOc_uUpLs );

               if( E_OK == u8LocalReturn )
               {
                  if( ( 0x10 == ( u8LocalEventStatusExtScg_uUpLs & 0x10 ) ) ||
                      ( 0x10 == ( u8LocalEventStatusExtScp_uUpLs & 0x10 ) ) ||
                      ( 0x10 == ( u8LocalEventStatusExtOc_uUpLs & 0x10  ) ) )
                  {
                     *Testval = 0;
                     *Minlimit = 0;
                     *Maxlimit = 0;
                  }
                  else
                  {
                     *Minlimit = 0;
                     *Maxlimit = 0x03FF;

                     VEMS_vidGET(Tension_sonde_am_min_cycle,u16LocalMinVar);
                     VEMS_vidGET(Tension_sonde_am_max_cycle,u16LocalMaxVar);

                     if( ( TRUE == Ext_bCondDiag_uUpLs  ) &&
                         ( ( u16LocalMinVar != 0x03FF ) ||
                           ( u16LocalMaxVar != 0x0000 ) ) )
                     {
                        *Testval =
                           (uint16)MATHSRV_udtMIN(u16LocalMaxVar,0x03FE);
                     }
                     else
                     {
                        VEMS_vidGET(Tension_sonde_am_max_cycle_eep,
                           u16LocalMaxVar);
                        *Testval = u16LocalMaxVar;
                     }
                  }
                  *Status = DCM_DTRSTATUS_VISIBLE;
               }
               else
               {
                  /* u8LocalReturn déjà positionné */
               }
            }
            else
            {
               /* u8LocalReturn déjà positionné */
            }
         }
         else
         {
            /* u8LocalReturn déjà positionné */
         }
      }
      else
      {
         u8LocalReturn = E_OK;
         *Status = DCM_DTRSTATUS_INVISIBLE;
      }
   }
   else if( DCM_CANCEL == OpStatus )
   {
      u8LocalReturn = E_OK;
   }
   else
   {
      /* Normalement impossible */
      u8LocalReturn = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GetDTRValue_OBDMID01_TID0A                                 */
/* !Description :  Sonde Amont : OBDMID 01, TID 0A                            */
/* !Number      :  API.7                                                      */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  Dem_GetEventStatus(argin uint16 u16Variable,  */
/*  argout uint8 *u8OutVariable);                                             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Manu_inh_mode_6_scantool;                                   */
/*  input uint8 Mode_6_s1_01_data_b;                                          */
/*  input uint16 SenO2Us_PerDiag_FacMax_Obd6Mod;                              */
/*  input boolean Ext_bCondDiag_OxySensPerd;                                  */
/*  input uint16 SenO2Us_PerDiag_FacMes_Obd6Mod;                              */
/*  input uint16 Oxy_sens_period_var_eep;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GetDTRValue_OBDMID01_TID0A
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   uint16                      u16LocalVar;
   Std_ReturnType              u8LocalReturn;
   Dem_EventStatusExtendedType u8LocalEventStatusORng_OxySensPerd;

   if( DCM_INITIAL == OpStatus )
   {
      if( ( FALSE == Manu_inh_mode_6_scantool      ) &&
          ( 0x40 == ( Mode_6_s1_01_data_b & 0x40 ) ) )
      {
         u8LocalReturn =
            Dem_GetEventStatus( (uint16)GD_DFT_ORNG_OXYSENSPERD,
                                &u8LocalEventStatusORng_OxySensPerd );

         if( E_OK == u8LocalReturn )
         {
            if( 0x10 == ( u8LocalEventStatusORng_OxySensPerd & 0x10 ) )
            {
               *Testval = 0;
               *Minlimit = 0;
               *Maxlimit = 0;
            }
            else
            {
               VEMS_vidGET(SenO2Us_PerDiag_FacMax_Obd6Mod, u16LocalVar);
               *Minlimit = 0;
               *Maxlimit = u16LocalVar;
               if( TRUE == Ext_bCondDiag_OxySensPerd )
               {
                  VEMS_vidGET(SenO2Us_PerDiag_FacMes_Obd6Mod, u16LocalVar);
                  *Testval = u16LocalVar;
               }
               else
               {
                  VEMS_vidGET(Oxy_sens_period_var_eep, u16LocalVar);
                  *Testval = u16LocalVar;
               }
            }
            *Status = DCM_DTRSTATUS_VISIBLE;
         }
         else
         {
            /* u8LocalReturn déjà positionné */
         }
      }
      else
      {
         u8LocalReturn = E_OK;
         *Status = DCM_DTRSTATUS_INVISIBLE;
      }
   }
   else if( DCM_CANCEL == OpStatus )
   {
      u8LocalReturn = E_OK;
   }
   else
   {
      /* Normalement impossible */
      u8LocalReturn = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GetDTRValue_OBDMID01_TIDA0                                 */
/* !Description :  Sonde Amont : OBDMID 01, TID A0                            */
/* !Number      :  API.8                                                      */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  Dem_GetEventStatus(argin uint16 u16Variable,  */
/*  argout uint8 *u8OutVariable);                                             */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16Variable);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Manu_inh_mode_6_scantool;                                   */
/*  input uint8 Mode_6_s1_81_data_d;                                          */
/*  input uint16 SenO2Us_FldPlausFacMin_Obd6Mod;                              */
/*  input boolean Ext_bCondDiag_UsPlausFld;                                   */
/*  input uint16 SenO2Us_FldPlausFacMes_Obd6Mod;                              */
/*  input uint16 SenO2Us_FldPlausMes_Obd6Mod_eep;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GetDTRValue_OBDMID01_TIDA0
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   uint16                      u16LocalVar;
   Std_ReturnType              u8LocalReturn;
   boolean                     bLocalFRM_bInhDiagSenO2UsElDiag;
   Dem_EventStatusExtendedType u8LocalEventStatusORng_UsPlausFld;

   if( DCM_INITIAL == OpStatus )
   {
      if( ( FALSE == Manu_inh_mode_6_scantool      ) &&
          ( 0x01 == ( Mode_6_s1_81_data_d & 0x01 ) ) )
      {
         u8LocalReturn =
            Dem_GetEventStatus( (uint16)GD_DFT_ORNG_USPLAUSFLD,
                                &u8LocalEventStatusORng_UsPlausFld );

         if( E_OK == u8LocalReturn )
         {
            bLocalFRM_bInhDiagSenO2UsElDiag =
                  GDGAR_bGetFRM(FRM_FRM_INHDIAGSENO2USEIDIAG);

            if( ( 0x10 == ( u8LocalEventStatusORng_UsPlausFld & 0x10 ) ) ||
                ( TRUE == bLocalFRM_bInhDiagSenO2UsElDiag              ) )
            {
               *Testval = 0;
               *Minlimit = 0;
               *Maxlimit = 0;
            }
            else
            {
               VEMS_vidGET(SenO2Us_FldPlausFacMin_Obd6Mod, u16LocalVar);
               *Minlimit = u16LocalVar;
               *Maxlimit = 0xFFFF;

               if( TRUE == Ext_bCondDiag_UsPlausFld )
               {
                  VEMS_vidGET(SenO2Us_FldPlausFacMes_Obd6Mod, u16LocalVar);
                  *Testval = u16LocalVar;
               }
               else
               {
                  VEMS_vidGET(SenO2Us_FldPlausMes_Obd6Mod_eep, u16LocalVar);
                  *Testval = u16LocalVar;
               }
            }
            *Status = DCM_DTRSTATUS_VISIBLE;
         }
         else
         {
            /* u8LocalReturn déjà positionné */
         }
      }
      else
      {
         u8LocalReturn = E_OK;
         *Status = DCM_DTRSTATUS_INVISIBLE;
      }
   }
   else if( DCM_CANCEL == OpStatus )
   {
      u8LocalReturn = E_OK;
   }
   else
   {
      /* Normalement impossible */
      u8LocalReturn = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GetDTRValue_OBDMID01_TIDA1                                 */
/* !Description :  Sonde Amont : OBDMID 01, TID A1                            */
/* !Number      :  API.9                                                      */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  Dem_GetEventStatus(argin uint16 u16Variable,  */
/*  argout uint8 *u8OutVariable);                                             */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16Variable);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Manu_inh_mode_6_scantool;                                   */
/*  input uint8 Mode_6_s1_A1_data_a;                                          */
/*  input uint16 SenO2Us_FcoPlausFacMax_Obd6Mod;                              */
/*  input boolean Ext_bCondDiag_UsPlausFco;                                   */
/*  input uint16 SenO2Us_FcoPlausFacMes_Obd6Mod;                              */
/*  input uint16 SenO2Us_FcoPlausMes_Obd6Mod_eep;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GetDTRValue_OBDMID01_TIDA1
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   uint16                      u16LocalVar;
   Std_ReturnType              u8LocalReturn;
   boolean                     bLocalFRM_bInhDiagSenO2UsElDiag;
   Dem_EventStatusExtendedType u8LocalEventStatusORng_UsPlausFco;

   if( DCM_INITIAL == OpStatus )
   {
      if( ( FALSE == Manu_inh_mode_6_scantool      ) &&
          ( 0x80 == ( Mode_6_s1_A1_data_a & 0x80 ) ) )
      {
         u8LocalReturn =
               Dem_GetEventStatus( (uint16)GD_DFT_ORNG_USPLAUSFLD,
                                   &u8LocalEventStatusORng_UsPlausFco );

         if( E_OK == u8LocalReturn )
         {
            bLocalFRM_bInhDiagSenO2UsElDiag =
                  GDGAR_bGetFRM(FRM_FRM_INHDIAGSENO2USEIDIAG);

            if( ( 0x10 == ( u8LocalEventStatusORng_UsPlausFco & 0x10 ) ) ||
                ( TRUE == bLocalFRM_bInhDiagSenO2UsElDiag              ) )
            {
               *Testval = 0;
               *Minlimit = 0;
               *Maxlimit = 0;
            }
            else
            {
               VEMS_vidGET(SenO2Us_FcoPlausFacMax_Obd6Mod, u16LocalVar);
               *Minlimit = 0x0000;
               *Maxlimit = u16LocalVar;

               if( TRUE == Ext_bCondDiag_UsPlausFco )
               {
                  VEMS_vidGET(SenO2Us_FcoPlausFacMes_Obd6Mod, u16LocalVar);
                  *Testval = u16LocalVar;
               }
               else
               {
                  VEMS_vidGET(SenO2Us_FcoPlausMes_Obd6Mod_eep, u16LocalVar);
                  *Testval = u16LocalVar;
               }
            }
            *Status = DCM_DTRSTATUS_VISIBLE;
         }
         else
         {
            /* u8LocalReturn déjà positionné */
         }
      }
      else
      {
         u8LocalReturn = E_OK;
         *Status = DCM_DTRSTATUS_INVISIBLE;
      }
   }
   else if( DCM_CANCEL == OpStatus )
   {
      u8LocalReturn = E_OK;
   }
   else
   {
      /* Normalement impossible */
      u8LocalReturn = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GetDTRValue_OBDMID02_TID01                                 */
/* !Description :  Sonde aval : OBDMID 02, TID 01                             */
/* !Number      :  API.10                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Manu_inh_mode_6_scantool;                                   */
/*  input uint8 Mode_6_s2_01_data_a;                                          */
/*  input uint16 Seuil_sonde_aval_pauvre;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GetDTRValue_OBDMID02_TID01
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   if( DCM_INITIAL == OpStatus )
   {
      if( ( FALSE == Manu_inh_mode_6_scantool      ) &&
          ( 0x80 == ( Mode_6_s2_01_data_a & 0x80 ) ) )
      {
         *Testval = Seuil_sonde_aval_pauvre;
         *Minlimit = Seuil_sonde_aval_pauvre;
         *Maxlimit = Seuil_sonde_aval_pauvre;
         *Status = DCM_DTRSTATUS_VISIBLE;
      }
      else
      {
         *Status = DCM_DTRSTATUS_INVISIBLE;
      }
      u8LocalReturn = E_OK;
   }
   else if( DCM_CANCEL == OpStatus )
   {
      u8LocalReturn = E_OK;
   }
   else
   {
      /* Normalement impossible */
      u8LocalReturn = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GetDTRValue_OBDMID02_TID02                                 */
/* !Description :  Sonde aval : OBDMID 02, TID 02                             */
/* !Number      :  API.11                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Manu_inh_mode_6_scantool;                                   */
/*  input uint8 Mode_6_s2_01_data_a;                                          */
/*  input uint16 Seuil_sonde_aval_riche;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GetDTRValue_OBDMID02_TID02
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   if( DCM_INITIAL == OpStatus )
   {
      if( ( FALSE == Manu_inh_mode_6_scantool      ) &&
          ( 0x40 == ( Mode_6_s2_01_data_a & 0x40 ) ) )
      {
         *Testval = Seuil_sonde_aval_riche;
         *Minlimit = Seuil_sonde_aval_riche;
         *Maxlimit = Seuil_sonde_aval_riche;
         *Status = DCM_DTRSTATUS_VISIBLE;
      }
      else
      {
         *Status = DCM_DTRSTATUS_INVISIBLE;
      }
      u8LocalReturn = E_OK;
   }
   else if( DCM_CANCEL == OpStatus )
   {
      u8LocalReturn = E_OK;
   }
   else
   {
      /* Normalement impossible */
      u8LocalReturn = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GetDTRValue_OBDMID02_TID03                                 */
/* !Description :  Sonde avl : OBDMID 02, TID 03                              */
/* !Number      :  API.12                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Manu_inh_mode_6_scantool;                                   */
/*  input uint8 Mode_6_s2_01_data_a;                                          */
/*  input uint16 Oxy_sens_lower_voltage_thresh_c;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GetDTRValue_OBDMID02_TID03
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   if( DCM_INITIAL == OpStatus )
   {
      if( ( FALSE == Manu_inh_mode_6_scantool      ) &&
          ( 0x20 == ( Mode_6_s2_01_data_a & 0x20 ) ) )
      {
         *Testval = Oxy_sens_lower_voltage_thresh_c;
         *Minlimit = Oxy_sens_lower_voltage_thresh_c;
         *Maxlimit = Oxy_sens_lower_voltage_thresh_c;
         *Status = DCM_DTRSTATUS_VISIBLE;
      }
      else
      {
         *Status = DCM_DTRSTATUS_INVISIBLE;
      }
      u8LocalReturn = E_OK;
   }
   else if( DCM_CANCEL == OpStatus )
   {
      u8LocalReturn = E_OK;
   }
   else
   {
      /* Normalement impossible */
      u8LocalReturn = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GetDTRValue_OBDMID02_TID04                                 */
/* !Description :  Sonde aval : OBDMID 02, TID 04                             */
/* !Number      :  API.13                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Manu_inh_mode_6_scantool;                                   */
/*  input uint8 Mode_6_s2_01_data_a;                                          */
/*  input uint16 Oxy_sens_upper_voltage_thresh_c;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GetDTRValue_OBDMID02_TID04
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   Std_ReturnType u8LocalReturn;

   if( DCM_INITIAL == OpStatus )
   {
      if( ( FALSE == Manu_inh_mode_6_scantool      ) &&
          ( 0x10 == ( Mode_6_s2_01_data_a & 0x10 ) ) )
      {
         *Testval = Oxy_sens_upper_voltage_thresh_c;
         *Minlimit = Oxy_sens_upper_voltage_thresh_c;
         *Maxlimit = Oxy_sens_upper_voltage_thresh_c;
         *Status = DCM_DTRSTATUS_VISIBLE;
      }
      else
      {
         *Status = DCM_DTRSTATUS_INVISIBLE;
      }
      u8LocalReturn = E_OK;
   }
   else if( DCM_CANCEL == OpStatus )
   {
      u8LocalReturn = E_OK;
   }
   else
   {
      /* Normalement impossible */
      u8LocalReturn = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GetDTRValue_OBDMID02_TID07                                 */
/* !Description :  Sonde aval : OBDMID 02, TID 07                             */
/* !Number      :  API.14                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  Dem_GetEventStatus(argin uint16 u16Variable,  */
/*  argout uint8 *u8OutVariable);                                             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Manu_inh_mode_6_scantool;                                   */
/*  input uint8 Mode_6_s2_01_data_a;                                          */
/*  input uint16 Tension_sonde_av_min_cycle;                                  */
/*  input uint16 Tension_sonde_av_max_cycle;                                  */
/*  input boolean Ext_bCondDiag_uDsLs;                                        */
/*  input uint16 Tension_sonde_av_min_cycle_eep;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GetDTRValue_OBDMID02_TID07
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   uint16                      u16LocalMinVar;
   uint16                      u16LocalMaxVar;
   Std_ReturnType              u8LocalReturn;
   Dem_EventStatusExtendedType u8LocalEventStatusExtScg_uDsLs;
   Dem_EventStatusExtendedType u8LocalEventStatusExtScp_uDsLs;
   Dem_EventStatusExtendedType u8LocalEventStatusExtOc_uDsLs;

   if( DCM_INITIAL == OpStatus )
   {
      if( ( FALSE == Manu_inh_mode_6_scantool      ) &&
          ( 0x02 == ( Mode_6_s2_01_data_a & 0x02 ) ) )
      {
         u8LocalReturn = Dem_GetEventStatus( (uint16)GD_DFT_SCG_UDSLS,
                                             &u8LocalEventStatusExtScg_uDsLs );

         if( E_OK == u8LocalReturn )
         {
            u8LocalReturn =
                  Dem_GetEventStatus( (uint16)GD_DFT_SCP_UDSLS,
                                      &u8LocalEventStatusExtScp_uDsLs );

            if( E_OK == u8LocalReturn )
            {
               u8LocalReturn =
                  Dem_GetEventStatus( (uint16)GD_DFT_OC_UDSLS,
                                      &u8LocalEventStatusExtOc_uDsLs );

               if( E_OK == u8LocalReturn )
               {
                  if( ( 0x10 == ( u8LocalEventStatusExtScg_uDsLs & 0x10 ) ) ||
                      ( 0x10 == ( u8LocalEventStatusExtScp_uDsLs & 0x10 ) ) ||
                      ( 0x10 == ( u8LocalEventStatusExtOc_uDsLs & 0x10  ) ) )
                  {
                     *Testval = 0;
                     *Minlimit = 0;
                     *Maxlimit = 0;
                  }
                  else
                  {
                     *Minlimit = 0;
                     *Maxlimit = 0x03FF;

                     VEMS_vidGET(Tension_sonde_av_min_cycle,u16LocalMinVar);
                     VEMS_vidGET(Tension_sonde_av_max_cycle,u16LocalMaxVar);

                     if( ( TRUE == Ext_bCondDiag_uDsLs  ) &&
                         ( ( u16LocalMinVar != 0x03FF ) ||
                           ( u16LocalMaxVar != 0x0000 ) ) )
                     {
                        *Testval =
                           (uint16)MATHSRV_udtMIN(u16LocalMinVar,0x03FE);
                     }
                     else
                     {
                        VEMS_vidGET(Tension_sonde_av_min_cycle_eep,
                           u16LocalMinVar);
                        *Testval = u16LocalMinVar;
                     }
                  }
                  *Status = DCM_DTRSTATUS_VISIBLE;
               }
               else
               {
                  /* u8LocalReturn déjà positionné */
               }
            }
            else
            {
               /* u8LocalReturn déjà positionné */
            }
         }
         else
         {
            /* u8LocalReturn déjà positionné */
         }
      }
      else
      {
         u8LocalReturn = E_OK;
         *Status = DCM_DTRSTATUS_INVISIBLE;
      }
   }
   else if( DCM_CANCEL == OpStatus )
   {
      u8LocalReturn = E_OK;
   }
   else
   {
      /* Normalement impossible */
      u8LocalReturn = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GetDTRValue_OBDMID02_TID08                                 */
/* !Description :  Sonde aval : OBDMID 02, TID 08                             */
/* !Number      :  API.15                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  Dem_GetEventStatus(argin uint16 u16Variable,  */
/*  argout uint8 *u8OutVariable);                                             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Manu_inh_mode_6_scantool;                                   */
/*  input uint8 Mode_6_s2_01_data_a;                                          */
/*  input uint16 Tension_sonde_av_min_cycle;                                  */
/*  input uint16 Tension_sonde_av_max_cycle;                                  */
/*  input boolean Ext_bCondDiag_uDsLs;                                        */
/*  input uint16 Tension_sonde_av_max_cycle_eep;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GetDTRValue_OBDMID02_TID08
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   uint16                      u16LocalMinVar;
   uint16                      u16LocalMaxVar;
   Std_ReturnType              u8LocalReturn;
   Dem_EventStatusExtendedType u8LocalEventStatusExtScg_uDsLs;
   Dem_EventStatusExtendedType u8LocalEventStatusExtScp_uDsLs;
   Dem_EventStatusExtendedType u8LocalEventStatusExtOc_uDsLs;

   if( DCM_INITIAL == OpStatus )
   {
      if( ( FALSE == Manu_inh_mode_6_scantool      ) &&
          ( 0x01 == ( Mode_6_s2_01_data_a & 0x01 ) ) )
      {
         u8LocalReturn = Dem_GetEventStatus( (uint16)GD_DFT_SCG_UDSLS,
                                             &u8LocalEventStatusExtScg_uDsLs );

         if( E_OK == u8LocalReturn )
         {
            u8LocalReturn =
                  Dem_GetEventStatus( (uint16)GD_DFT_SCP_UDSLS,
                                      &u8LocalEventStatusExtScp_uDsLs );

            if( E_OK == u8LocalReturn )
            {
               u8LocalReturn =
                  Dem_GetEventStatus( (uint16)GD_DFT_OC_UDSLS,
                                      &u8LocalEventStatusExtOc_uDsLs );

               if( E_OK == u8LocalReturn )
               {
                  if( ( 0x10 == ( u8LocalEventStatusExtScg_uDsLs & 0x10 ) ) ||
                      ( 0x10 == ( u8LocalEventStatusExtScp_uDsLs & 0x10 ) ) ||
                      ( 0x10 == ( u8LocalEventStatusExtOc_uDsLs & 0x10  ) ) )
                  {
                     *Testval = 0;
                     *Minlimit = 0;
                     *Maxlimit = 0;
                  }
                  else
                  {
                     *Minlimit = 0;
                     *Maxlimit = 0x03FF;

                     VEMS_vidGET(Tension_sonde_av_min_cycle,u16LocalMinVar);
                     VEMS_vidGET(Tension_sonde_av_max_cycle,u16LocalMaxVar);

                     if( ( TRUE == Ext_bCondDiag_uDsLs  ) &&
                         ( ( u16LocalMinVar != 0x03FF ) ||
                           ( u16LocalMaxVar != 0x0000 ) ) )
                     {
                        *Testval =
                           (uint16)MATHSRV_udtMIN(u16LocalMaxVar,0x03FE);
                     }
                     else
                     {
                        VEMS_vidGET(Tension_sonde_av_max_cycle_eep,
                           u16LocalMaxVar);
                        *Testval = u16LocalMaxVar;
                     }
                  }
                  *Status = DCM_DTRSTATUS_VISIBLE;
               }
               else
               {
                  /* u8LocalReturn déjà positionné */
               }
            }
            else
            {
               /* u8LocalReturn déjà positionné */
            }
         }
         else
         {
            /* u8LocalReturn déjà positionné */
         }
      }
      else
      {
         u8LocalReturn = E_OK;
         *Status = DCM_DTRSTATUS_INVISIBLE;
      }
   }
   else if( DCM_CANCEL == OpStatus )
   {
      u8LocalReturn = E_OK;
   }
   else
   {
      /* Normalement impossible */
      u8LocalReturn = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GetDTRValue_OBDMID02_TIDC0                                 */
/* !Description :  Sonde aval : OBDMID 02, TID C0                             */
/* !Number      :  API.16                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  Dem_GetEventStatus(argin uint16 u16Variable,  */
/*  argout uint8 *u8OutVariable);                                             */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16Variable);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Manu_inh_mode_6_scantool;                                   */
/*  input uint8 Mode_6_s2_A1_data_d;                                          */
/*  input uint16 SenO2Ds_FldPlausFacMin_Obd6Mod;                              */
/*  input boolean Ext_bCondDiag_DsPlausFld;                                   */
/*  input uint16 SenO2Ds_FldPlausFacMes_Obd6Mod;                              */
/*  input uint16 SenO2Ds_FldPlausMes_Obd6Mod_eep;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GetDTRValue_OBDMID02_TIDC0
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   uint16                      u16LocalVar;
   Std_ReturnType              u8LocalReturn;
   boolean                     bLocalFRM_bInhDiagSenO2DsElDiag;
   Dem_EventStatusExtendedType u8LocalEventStatusORng_DsPlausFld;

   if( DCM_INITIAL == OpStatus )
   {
      if( ( FALSE == Manu_inh_mode_6_scantool      ) &&
          ( 0x01 == ( Mode_6_s2_A1_data_d & 0x01 ) ) )
      {
         u8LocalReturn =
            Dem_GetEventStatus( (uint16)GD_DFT_ORNG_DSPLAUSFLD,
                                &u8LocalEventStatusORng_DsPlausFld );

         if( E_OK == u8LocalReturn )
         {
            bLocalFRM_bInhDiagSenO2DsElDiag =
                  GDGAR_bGetFRM(FRM_FRM_INHDIAGSENO2DSEIDIAG);

            if( ( 0x10 == ( u8LocalEventStatusORng_DsPlausFld & 0x10 ) ) ||
                ( TRUE == bLocalFRM_bInhDiagSenO2DsElDiag              ) )
            {
               *Testval = 0;
               *Minlimit = 0;
               *Maxlimit = 0;
            }
            else
            {
               VEMS_vidGET(SenO2Ds_FldPlausFacMin_Obd6Mod, u16LocalVar);
               *Minlimit = u16LocalVar;
               *Maxlimit = 0xFFFF;

               if( TRUE == Ext_bCondDiag_DsPlausFld )
               {
                  VEMS_vidGET(SenO2Ds_FldPlausFacMes_Obd6Mod, u16LocalVar);
                  *Testval = u16LocalVar;
               }
               else
               {
                  VEMS_vidGET(SenO2Ds_FldPlausMes_Obd6Mod_eep, u16LocalVar);
                  *Testval = u16LocalVar;
               }
            }
            *Status = DCM_DTRSTATUS_VISIBLE;
         }
         else
         {
            /* u8LocalReturn déjà positionné */
         }
      }
      else
      {
         u8LocalReturn = E_OK;
         *Status = DCM_DTRSTATUS_INVISIBLE;
      }
   }
   else if( DCM_CANCEL == OpStatus )
   {
      u8LocalReturn = E_OK;
   }
   else
   {
      /* Normalement impossible */
      u8LocalReturn = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GetDTRValue_OBDMID02_TIDC1                                 */
/* !Description :  Sonde aval : OBDMID 02, TID C1                             */
/* !Number      :  API.17                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  Dem_GetEventStatus(argin uint16 u16Variable,  */
/*  argout uint8 *u8OutVariable);                                             */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16Variable);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Manu_inh_mode_6_scantool;                                   */
/*  input uint8 Mode_6_s2_C1_data_a;                                          */
/*  input uint16 SenO2Ds_FcoPlausFacMax_Obd6Mod;                              */
/*  input boolean Ext_bCondDiag_DsPlausFco;                                   */
/*  input uint16 SenO2Ds_FcoPlausFacMes_Obd6Mod;                              */
/*  input uint16 SenO2Ds_FcoPlausMes_Obd6Mod_eep;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GetDTRValue_OBDMID02_TIDC1
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   uint16                      u16LocalVar;
   Std_ReturnType              u8LocalReturn;
   boolean                     bLocalFRM_bInhDiagSenO2DsElDiag;
   Dem_EventStatusExtendedType u8LocalEventStatusORng_DsPlausFco;

   if( DCM_INITIAL == OpStatus )
   {
      if( ( FALSE == Manu_inh_mode_6_scantool      ) &&
          ( 0x80 == ( Mode_6_s2_C1_data_a & 0x80 ) ) )
      {
         u8LocalReturn =
               Dem_GetEventStatus( (uint16)GD_DFT_ORNG_DSPLAUSFCO,
                                   &u8LocalEventStatusORng_DsPlausFco );

         if( E_OK == u8LocalReturn )
         {
            bLocalFRM_bInhDiagSenO2DsElDiag =
                  GDGAR_bGetFRM(FRM_FRM_INHDIAGSENO2DSEIDIAG);

            if( ( 0x10 == ( u8LocalEventStatusORng_DsPlausFco & 0x10 ) ) ||
                ( TRUE == bLocalFRM_bInhDiagSenO2DsElDiag              ) )
            {
               *Testval = 0;
               *Minlimit = 0;
               *Maxlimit = 0;
            }
            else
            {
               VEMS_vidGET(SenO2Ds_FcoPlausFacMax_Obd6Mod, u16LocalVar);
               *Minlimit = 0;
               *Maxlimit = u16LocalVar;

               if( TRUE == Ext_bCondDiag_DsPlausFco )
               {
                  VEMS_vidGET(SenO2Ds_FcoPlausFacMes_Obd6Mod, u16LocalVar);
                  *Testval = u16LocalVar;
               }
               else
               {
                  VEMS_vidGET(SenO2Ds_FcoPlausMes_Obd6Mod_eep, u16LocalVar);
                  *Testval = u16LocalVar;
               }
            }
            *Status = DCM_DTRSTATUS_VISIBLE;
         }
         else
         {
            /* u8LocalReturn déjà positionné */
         }
      }
      else
      {
         u8LocalReturn = E_OK;
         *Status = DCM_DTRSTATUS_INVISIBLE;
      }
   }
   else if( DCM_CANCEL == OpStatus )
   {
      u8LocalReturn = E_OK;
   }
   else
   {
      /* Normalement impossible */
      u8LocalReturn = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GetDTRValue_OBDMID02_TIDC2                                 */
/* !Description :  Sonde aval : OBDMID 02, TID C2                             */
/* !Number      :  API.18                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  Dem_GetEventStatus(argin uint16 u16Variable,  */
/*  argout uint8 *u8OutVariable);                                             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Manu_inh_mode_6_scantool;                                   */
/*  input uint8 Mode_6_s2_C1_data_a;                                          */
/*  input uint16 SenO2Ds_SigGrdFacMin_Obd6Mod;                                */
/*  input boolean Ext_bCondDiag_SigGrdDiag;                                   */
/*  input uint16 SenO2Ds_SigGrd_Obd6Mod;                                      */
/*  input uint16 SenO2Ds_SigGrd_Obd6Mod_eep;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GetDTRValue_OBDMID02_TIDC2
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   uint16                      u16LocalVar;
   Std_ReturnType              u8LocalReturn;
   Dem_EventStatusExtendedType u8LocalEventStatusORng_SigGrdDiag;

   if( DCM_INITIAL == OpStatus )
   {
      if( ( FALSE == Manu_inh_mode_6_scantool      ) &&
          ( 0x40 == ( Mode_6_s2_C1_data_a & 0x40 ) ) )
      {
         u8LocalReturn =
               Dem_GetEventStatus( (uint16)GD_DFT_ORNG_SIGGRDDIAG,
                                   &u8LocalEventStatusORng_SigGrdDiag );

         if( E_OK == u8LocalReturn )
         {
            if( 0x10 == ( u8LocalEventStatusORng_SigGrdDiag & 0x10 ) )
            {
               *Testval = 0;
               *Minlimit = 0;
               *Maxlimit = 0;
            }
            else
            {
               VEMS_vidGET(SenO2Ds_SigGrdFacMin_Obd6Mod,u16LocalVar);
               *Minlimit = 0;
               *Maxlimit = u16LocalVar;

               if( TRUE == Ext_bCondDiag_SigGrdDiag )
               {
                  *Testval = SenO2Ds_SigGrd_Obd6Mod;
               }
               else
               {
                  VEMS_vidGET(SenO2Ds_SigGrd_Obd6Mod_eep,u16LocalVar);
                  *Testval = u16LocalVar;
               }
            }
            *Status = DCM_DTRSTATUS_VISIBLE;
         }
         else
         {
            /* u8LocalReturn déjà positionné */
         }
      }
      else
      {
         u8LocalReturn = E_OK;
         *Status = DCM_DTRSTATUS_INVISIBLE;
      }
   }
   else if( DCM_CANCEL == OpStatus )
   {
      u8LocalReturn = E_OK;
   }
   else
   {
      /* Normalement impossible */
      u8LocalReturn = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GetDTRValue_OBDMID21_TID81                                 */
/* !Description :  Catalyseur : OBDMID 21, TID 81                             */
/* !Number      :  API.19                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  Dem_GetEventStatus(argin uint16 u16Variable,  */
/*  argout uint8 *u8OutVariable);                                             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Manu_inh_mode_6_scantool;                                   */
/*  input boolean Mode_6_obdmid_21_tid_81;                                    */
/*  input uint16 CatMon_facMin_Obd6Mod;                                       */
/*  input uint16 CatMon_facMax_Obd6Mod;                                       */
/*  input boolean Ext_bCondDiag_Cat;                                          */
/*  input uint16 CatMon_facMes_Obd6Mod;                                       */
/*  input uint16 CatMon_facMes_Obd6Mod_eep;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GetDTRValue_OBDMID21_TID81
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   uint16                      u16LocalMinVar;
   uint16                      u16LocalMaxVar;
   uint16                      u16LocalMesVar;
   Std_ReturnType              u8LocalReturn;
   Dem_EventStatusExtendedType u8LocalEventStatusORng_Cat;

   if( DCM_INITIAL == OpStatus )
   {
      if( ( FALSE == Manu_inh_mode_6_scantool ) &&
          ( TRUE == Mode_6_obdmid_21_tid_81   ) )
      {
         u8LocalReturn = Dem_GetEventStatus( (uint16)GD_DFT_ORNG_CAT,
                                             &u8LocalEventStatusORng_Cat );

         if( E_OK == u8LocalReturn )
         {
            if( 0x10 == ( u8LocalEventStatusORng_Cat & 0x10 ) )
            {
               *Testval = 0;
               *Minlimit = 0;
               *Maxlimit = 0;
            }
            else
            {
               VEMS_vidGET(CatMon_facMin_Obd6Mod,u16LocalMinVar);
               VEMS_vidGET(CatMon_facMax_Obd6Mod,u16LocalMaxVar);
               *Minlimit = u16LocalMinVar;
               *Maxlimit = u16LocalMaxVar;

               if( TRUE == Ext_bCondDiag_Cat )
               {
                  VEMS_vidGET(CatMon_facMes_Obd6Mod,u16LocalMesVar);
                  *Testval = u16LocalMesVar;
               }
               else
               {
                  VEMS_vidGET(CatMon_facMes_Obd6Mod_eep,u16LocalMaxVar);
                  *Testval = u16LocalMaxVar;
               }
            }
            *Status = DCM_DTRSTATUS_VISIBLE;
         }
         else
         {
            /* u8LocalReturn déjà positionné */
         }
      }
      else
      {
         u8LocalReturn = E_OK;
         *Status = DCM_DTRSTATUS_INVISIBLE;
      }
   }
   else if( DCM_CANCEL == OpStatus )
   {
      u8LocalReturn = E_OK;
   }
   else
   {
      /* Normalement impossible */
      u8LocalReturn = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GetDTRValue_OBDMID41_TIDD0                                 */
/* !Description :  Chauffage sonde amont : OBDMID 41, TID D0                  */
/* !Number      :  API.20                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  Dem_GetEventStatus(argin uint16 u16Variable,  */
/*  argout uint8 *u8OutVariable);                                             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Manu_inh_mode_6_scantool;                                   */
/*  input boolean Mode_6_obdmid_41_tid_D0;                                    */
/*  input uint16 HeatSenO2_UsFacMax_Obd6Mod;                                  */
/*  input boolean Ext_bCondDiag_UsHeat;                                       */
/*  input uint16 HeatSenO2_UsFacMes_Obd6Mod;                                  */
/*  input uint16 HeatSenO2_UsFacMes_Obd6Mod_eep;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GetDTRValue_OBDMID41_TIDD0
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   uint16                      u16LocalVar;
   Std_ReturnType              u8LocalReturn;
   Dem_EventStatusExtendedType u8LocalEventStatusORng_UsHeat;

   if( DCM_INITIAL == OpStatus )
   {
      if( ( FALSE == Manu_inh_mode_6_scantool ) &&
          ( TRUE == Mode_6_obdmid_41_tid_D0   ) )
      {
         u8LocalReturn = Dem_GetEventStatus( (uint16)GD_DFT_ORNG_USHEAT,
                                             &u8LocalEventStatusORng_UsHeat );

         if( E_OK == u8LocalReturn )
         {
            if( 0x10 == ( u8LocalEventStatusORng_UsHeat & 0x10 ) )
            {
               *Testval = 0;
               *Minlimit = 0;
               *Maxlimit = 0;
            }
            else
            {
               VEMS_vidGET(HeatSenO2_UsFacMax_Obd6Mod,u16LocalVar);
               *Minlimit = 0;
               *Maxlimit = u16LocalVar;

               if( TRUE == Ext_bCondDiag_UsHeat )
               {
                  VEMS_vidGET(HeatSenO2_UsFacMes_Obd6Mod,u16LocalVar);
                  *Testval = u16LocalVar;
               }
               else
               {
                  VEMS_vidGET(HeatSenO2_UsFacMes_Obd6Mod_eep,u16LocalVar);
                  *Testval = u16LocalVar;
               }
            }
            *Status = DCM_DTRSTATUS_VISIBLE;
         }
         else
         {
            /* u8LocalReturn déjà positionné */
         }
      }
      else
      {
         u8LocalReturn = E_OK;
         *Status = DCM_DTRSTATUS_INVISIBLE;
      }
   }
   else if( DCM_CANCEL == OpStatus )
   {
      u8LocalReturn = E_OK;
   }
   else
   {
      /* Normalement impossible */
      u8LocalReturn = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GetDTRValue_OBDMID42_TIDDA                                 */
/* !Description :  Chauffage sonde aval : OBDMID 42, TID DA                   */
/* !Number      :  API.21                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret Std_ReturnType  Dem_GetEventStatus(argin uint16 u16Variable,  */
/*  argout uint8 *u8OutVariable);                                             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Manu_inh_mode_6_scantool;                                   */
/*  input boolean Mode_6_obdmid_42_tid_DA;                                    */
/*  input uint16 HeatSenO2_DsFacMax_Obd6Mod;                                  */
/*  input boolean Ext_bCondDiag_DsHeat;                                       */
/*  input uint16 HeatSenO2_DsFacMes_Obd6Mod;                                  */
/*  input uint16 HeatSenO2_DsFacMes_Obd6Mod_eep;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GetDTRValue_OBDMID42_TIDDA
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   uint16                      u16LocalVar;
   Std_ReturnType              u8LocalReturn;
   Dem_EventStatusExtendedType u8LocalEventStatusORng_DsHeat;

   if( DCM_INITIAL == OpStatus )
   {
      if( ( FALSE == Manu_inh_mode_6_scantool ) &&
          ( TRUE == Mode_6_obdmid_42_tid_DA   ) )
      {
         u8LocalReturn = Dem_GetEventStatus( (uint16)GD_DFT_ORNG_DSHEAT,
                                             &u8LocalEventStatusORng_DsHeat );

         if( E_OK == u8LocalReturn )
         {
            if( 0x10 == ( u8LocalEventStatusORng_DsHeat & 0x10 ) )
            {
               *Testval = 0;
               *Minlimit = 0;
               *Maxlimit = 0;
            }
            else
            {
               VEMS_vidGET(HeatSenO2_DsFacMax_Obd6Mod,u16LocalVar);
               *Minlimit = 0;
               *Maxlimit = u16LocalVar;

               if( TRUE == Ext_bCondDiag_DsHeat )
               {
                  VEMS_vidGET(HeatSenO2_DsFacMes_Obd6Mod,u16LocalVar);
                  *Testval = u16LocalVar;
               }
               else
               {
                  VEMS_vidGET(HeatSenO2_DsFacMes_Obd6Mod_eep,u16LocalVar);
                  *Testval = u16LocalVar;
               }
            }
            *Status = DCM_DTRSTATUS_VISIBLE;
         }
         else
         {
            /* u8LocalReturn déjà positionné */
         }
      }
      else
      {
         u8LocalReturn = E_OK;
         *Status = DCM_DTRSTATUS_INVISIBLE;
      }
   }
   else if( DCM_CANCEL == OpStatus )
   {
      u8LocalReturn = E_OK;
   }
   else
   {
      /* Normalement impossible */
      u8LocalReturn = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GetDTRValue_OBDMIDA2_TID0B                                 */
/* !Description :  Misifre cylindre 1 :  OBDMID A2, TID 0B                    */
/* !Number      :  API.22                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Manu_inh_mode_6_scantool;                                   */
/*  input boolean Mode_6_obdmid_A2_tid_0B;                                    */
/*  input boolean Ext_bCondDiag_Misf;                                         */
/*  input uint16 MonMisf_ctOccurMfAvg10DCCyl1;                                */
/*  input uint16 MonMisf_ctOccurMfAvg10DCCyl1_eep;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GetDTRValue_OBDMIDA2_TID0B
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   uint16                      u16LocalVar;
   Std_ReturnType              u8LocalReturn;

   if( DCM_INITIAL == OpStatus )
   {
      if( ( FALSE == Manu_inh_mode_6_scantool ) &&
          ( TRUE == Mode_6_obdmid_A2_tid_0B   ) )
      {
         *Minlimit = 0;
         *Maxlimit = 0xFFFF;
         *Status = DCM_DTRSTATUS_VISIBLE;

         if( TRUE == Ext_bCondDiag_Misf )
         {
            VEMS_vidGET(MonMisf_ctOccurMfAvg10DCCyl1,u16LocalVar);
            *Testval = u16LocalVar;
         }
         else
         {
            VEMS_vidGET(MonMisf_ctOccurMfAvg10DCCyl1_eep,u16LocalVar);
            *Testval = u16LocalVar;
         }
      }
      else
      {
         *Status = DCM_DTRSTATUS_INVISIBLE;
      }
      u8LocalReturn = E_OK;
   }
   else if( DCM_CANCEL == OpStatus )
   {
      u8LocalReturn = E_OK;
   }
   else
   {
      /* Normalement impossible */
      u8LocalReturn = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GetDTRValue_OBDMIDA2_TID0C                                 */
/* !Description :  Misifre cylindre 1 : OBDMID A2, TID 0C                     */
/* !Number      :  API.23                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Manu_inh_mode_6_scantool;                                   */
/*  input boolean Mode_6_obdmid_A2_tid_0C;                                    */
/*  input boolean Ext_bCondDiag_Misf;                                         */
/*  input uint16 MonMisf_ctOccurMfDCCyl1;                                     */
/*  input uint16 MonMisf_ctOccurMfDCCyl1_eep;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GetDTRValue_OBDMIDA2_TID0C
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   uint16         u16LocalVar;
   Std_ReturnType u8LocalReturn;

   if( DCM_INITIAL == OpStatus )
   {
      if( ( FALSE == Manu_inh_mode_6_scantool ) &&
          ( TRUE == Mode_6_obdmid_A2_tid_0C   ) )
      {
         *Minlimit = 0;
         *Maxlimit = 0xFFFF;
         *Status = DCM_DTRSTATUS_VISIBLE;

         if( TRUE == Ext_bCondDiag_Misf )
         {
            VEMS_vidGET(MonMisf_ctOccurMfDCCyl1,u16LocalVar);
            *Testval = u16LocalVar;
         }
         else
         {
            VEMS_vidGET(MonMisf_ctOccurMfDCCyl1_eep,u16LocalVar);
            *Testval = u16LocalVar;
         }
      }
      else
      {
         *Status = DCM_DTRSTATUS_INVISIBLE;
      }
      u8LocalReturn = E_OK;
   }
   else if( DCM_CANCEL == OpStatus )
   {
      u8LocalReturn = E_OK;
   }
   else
   {
      /* Normalement impossible */
      u8LocalReturn = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GetDTRValue_OBDMIDA3_TID0B                                 */
/* !Description :  Misifre cylindre 2 : OBDMID A3, TID 0B                     */
/* !Number      :  API.24                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Manu_inh_mode_6_scantool;                                   */
/*  input boolean Mode_6_obdmid_A3_tid_0B;                                    */
/*  input boolean Ext_bCondDiag_Misf;                                         */
/*  input uint16 MonMisf_ctOccurMfAvg10DCCyl2;                                */
/*  input uint16 MonMisf_ctOccurMfAvg10DCCyl2_eep;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GetDTRValue_OBDMIDA3_TID0B
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   uint16         u16LocalVar;
   Std_ReturnType u8LocalReturn;

   if( DCM_INITIAL == OpStatus )
   {
      if( ( FALSE == Manu_inh_mode_6_scantool ) &&
          ( TRUE == Mode_6_obdmid_A3_tid_0B   ) )
      {
         *Minlimit = 0;
         *Maxlimit = 0xFFFF;
         *Status = DCM_DTRSTATUS_VISIBLE;

         if( TRUE == Ext_bCondDiag_Misf )
         {
            VEMS_vidGET(MonMisf_ctOccurMfAvg10DCCyl2,u16LocalVar);
            *Testval = u16LocalVar;
         }
         else
         {
            VEMS_vidGET(MonMisf_ctOccurMfAvg10DCCyl2_eep,u16LocalVar);
            *Testval = u16LocalVar;
         }
      }
      else
      {
         *Status = DCM_DTRSTATUS_INVISIBLE;
      }
      u8LocalReturn = E_OK;
   }
   else if( DCM_CANCEL == OpStatus )
   {
      u8LocalReturn = E_OK;
   }
   else
   {
      /* Normalement impossible */
      u8LocalReturn = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GetDTRValue_OBDMIDA3_TID0C                                 */
/* !Description :  Misifre cylindre 2 : OBDMID A3, TID 0C                     */
/* !Number      :  API.25                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Manu_inh_mode_6_scantool;                                   */
/*  input boolean Mode_6_obdmid_A3_tid_0C;                                    */
/*  input boolean Ext_bCondDiag_Misf;                                         */
/*  input uint16 MonMisf_ctOccurMfDCCyl2;                                     */
/*  input uint16 MonMisf_ctOccurMfDCCyl2_eep;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GetDTRValue_OBDMIDA3_TID0C
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   uint16         u16LocalVar;
   Std_ReturnType u8LocalReturn;

   if( DCM_INITIAL == OpStatus )
   {
      if( ( FALSE == Manu_inh_mode_6_scantool ) &&
          ( TRUE == Mode_6_obdmid_A3_tid_0C   ) )
      {
         *Minlimit = 0;
         *Maxlimit = 0xFFFF;
         *Status = DCM_DTRSTATUS_VISIBLE;

         if( TRUE == Ext_bCondDiag_Misf )
         {
            VEMS_vidGET(MonMisf_ctOccurMfDCCyl2,u16LocalVar);
            *Testval = u16LocalVar;
         }
         else
         {
            VEMS_vidGET(MonMisf_ctOccurMfDCCyl2_eep,u16LocalVar);
            *Testval = u16LocalVar;
         }
      }
      else
      {
         *Status = DCM_DTRSTATUS_INVISIBLE;
      }
      u8LocalReturn = E_OK;
   }
   else if( DCM_CANCEL == OpStatus )
   {
      u8LocalReturn = E_OK;
   }
   else
   {
      /* Normalement impossible */
      u8LocalReturn = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GetDTRValue_OBDMIDA4_TID0B                                 */
/* !Description :  Misifre cylindre 3 : OBDMID A4, TID 0B                     */
/* !Number      :  API.26                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Manu_inh_mode_6_scantool;                                   */
/*  input boolean Mode_6_obdmid_A4_tid_0B;                                    */
/*  input boolean Ext_bCondDiag_Misf;                                         */
/*  input uint16 MonMisf_ctOccurMfAvg10DCCyl3;                                */
/*  input uint16 MonMisf_ctOccurMfAvg10DCCyl3_eep;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GetDTRValue_OBDMIDA4_TID0B
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   uint16         u16LocalVar;
   Std_ReturnType u8LocalReturn;

   if( DCM_INITIAL == OpStatus )
   {
      if( ( FALSE == Manu_inh_mode_6_scantool ) &&
          ( TRUE == Mode_6_obdmid_A4_tid_0B   ) )
      {
         *Minlimit = 0;
         *Maxlimit = 0xFFFF;
         *Status = DCM_DTRSTATUS_VISIBLE;

         if( TRUE == Ext_bCondDiag_Misf )
         {
            VEMS_vidGET(MonMisf_ctOccurMfAvg10DCCyl3,u16LocalVar);
            *Testval = u16LocalVar;
         }
         else
         {
            VEMS_vidGET(MonMisf_ctOccurMfAvg10DCCyl3_eep,u16LocalVar);
            *Testval = u16LocalVar;
         }
      }
      else
      {
         *Status = DCM_DTRSTATUS_INVISIBLE;
      }
      u8LocalReturn = E_OK;
   }
   else if( DCM_CANCEL == OpStatus )
   {
      u8LocalReturn = E_OK;
   }
   else
   {
      /* Normalement impossible */
      u8LocalReturn = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GetDTRValue_OBDMIDA4_TID0C                                 */
/* !Description :  Misifre cylindre 3 : OBDMID A4, TID 0C                     */
/* !Number      :  API.27                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Manu_inh_mode_6_scantool;                                   */
/*  input boolean Mode_6_obdmid_A4_tid_0C;                                    */
/*  input boolean Ext_bCondDiag_Misf;                                         */
/*  input uint16 MonMisf_ctOccurMfDCCyl3;                                     */
/*  input uint16 MonMisf_ctOccurMfDCCyl3_eep;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GetDTRValue_OBDMIDA4_TID0C
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   uint16         u16LocalVar;
   Std_ReturnType u8LocalReturn;

   if( DCM_INITIAL == OpStatus )
   {
      if( ( FALSE == Manu_inh_mode_6_scantool ) &&
          ( TRUE == Mode_6_obdmid_A4_tid_0C   ) )
      {
         *Minlimit = 0;
         *Maxlimit = 0xFFFF;
         *Status = DCM_DTRSTATUS_VISIBLE;

         if( TRUE == Ext_bCondDiag_Misf )
         {
            VEMS_vidGET(MonMisf_ctOccurMfDCCyl3,u16LocalVar);
            *Testval = u16LocalVar;
         }
         else
         {
            VEMS_vidGET(MonMisf_ctOccurMfDCCyl3_eep,u16LocalVar);
            *Testval = u16LocalVar;
         }
      }
      else
      {
         *Status = DCM_DTRSTATUS_INVISIBLE;
      }
      u8LocalReturn = E_OK;
   }
   else if( DCM_CANCEL == OpStatus )
   {
      u8LocalReturn = E_OK;
   }
   else
   {
      /* Normalement impossible */
      u8LocalReturn = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GetDTRValue_OBDMIDA5_TID0B                                 */
/* !Description :  Misifre cylindre 4 : OBDMID A5, TID 0B                     */
/* !Number      :  API.28                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Manu_inh_mode_6_scantool;                                   */
/*  input boolean Mode_6_obdmid_A5_tid_0B;                                    */
/*  input boolean Ext_bCondDiag_Misf;                                         */
/*  input uint16 MonMisf_ctOccurMfAvg10DCCyl4;                                */
/*  input uint16 MonMisf_ctOccurMfAvg10DCCyl4_eep;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GetDTRValue_OBDMIDA5_TID0B
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   uint16         u16LocalVar;
   Std_ReturnType u8LocalReturn;

   if( DCM_INITIAL == OpStatus )
   {
      if( ( FALSE == Manu_inh_mode_6_scantool ) &&
          ( TRUE == Mode_6_obdmid_A5_tid_0B   ) )
      {
         *Minlimit = 0;
         *Maxlimit = 0xFFFF;
         *Status = DCM_DTRSTATUS_VISIBLE;

         if( TRUE == Ext_bCondDiag_Misf )
         {
            VEMS_vidGET(MonMisf_ctOccurMfAvg10DCCyl4,u16LocalVar);
            *Testval = u16LocalVar;
         }
         else
         {
            VEMS_vidGET(MonMisf_ctOccurMfAvg10DCCyl4_eep,u16LocalVar);
            *Testval = u16LocalVar;
         }
      }
      else
      {
         *Status = DCM_DTRSTATUS_INVISIBLE;
      }
      u8LocalReturn = E_OK;
   }
   else if( DCM_CANCEL == OpStatus )
   {
      u8LocalReturn = E_OK;
   }
   else
   {
      /* Normalement impossible */
      u8LocalReturn = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }

   return u8LocalReturn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  GetDTRValue_OBDMIDA5_TID0C                                 */
/* !Description :  Misifre cylindre 4 : OBDMID A5, TID 0C                     */
/* !Number      :  API.29                                                     */
/* !Author      :  PBAKABAD                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean Manu_inh_mode_6_scantool;                                   */
/*  input boolean Mode_6_obdmid_A5_tid_0C;                                    */
/*  input boolean Ext_bCondDiag_Misf;                                         */
/*  input uint16 MonMisf_ctOccurMfDCCyl4;                                     */
/*  input uint16 MonMisf_ctOccurMfDCCyl4_eep;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
Std_ReturnType GetDTRValue_OBDMIDA5_TID0C
(
   Dcm_OpStatusType OpStatus,
   uint16* Testval,
   uint16* Minlimit,
   uint16* Maxlimit,
   Dcm_DTRStatusType* Status
)
{
   uint16         u16LocalVar;
   Std_ReturnType u8LocalReturn;

   if( DCM_INITIAL == OpStatus )
   {
      if( ( FALSE == Manu_inh_mode_6_scantool ) &&
          ( TRUE == Mode_6_obdmid_A5_tid_0C   ) )
      {
         *Minlimit = 0;
         *Maxlimit = 0xFFFF;
         *Status = DCM_DTRSTATUS_VISIBLE;

         if( TRUE == Ext_bCondDiag_Misf )
         {
            VEMS_vidGET(MonMisf_ctOccurMfDCCyl4,u16LocalVar);
            *Testval = u16LocalVar;
         }
         else
         {
            VEMS_vidGET(MonMisf_ctOccurMfDCCyl4_eep,u16LocalVar);
            *Testval = u16LocalVar;
         }
      }
      else
      {
         *Status = DCM_DTRSTATUS_INVISIBLE;
      }
      u8LocalReturn = E_OK;
   }
   else if( DCM_CANCEL == OpStatus )
   {
      u8LocalReturn = E_OK;
   }
   else
   {
      /* Normalement impossible */
      u8LocalReturn = E_NOT_OK;
      SWFAIL_vidSoftwareErrorHook();
   }

   return u8LocalReturn;
}

/*-------------------------------- end of file -------------------------------*/