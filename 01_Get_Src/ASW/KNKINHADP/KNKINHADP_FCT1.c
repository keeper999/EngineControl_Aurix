/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : KNKINHADP                                               */
/* !Description     : KNKINHADP Component                                     */
/*                                                                            */
/* !Module          : KNKINHADP                                               */
/* !Description     : GESTION DE LA PHASE DE DECOLLAGE DANS LE BUT D’INHIBER  */
/*                    L’ADAPTATION D’AVANCE                                   */
/*                                                                            */
/* !File            : KNKINHADP_FCT1.C                                        */
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
/*   1 / KNKINHADP_vidInitCounter                                             */
/*   2 / KNKINHADP_vidUpdateCounter                                           */
/*                                                                            */
/* !Reference   : V02 NT 09 02295 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/IGLIM/KNKINHADP/KNKINHADP_FCT1.C_v$*/
/* $Revision::   1.0      $$Author::   wbouach        $$Date::   06 Jul 2009 $*/
/* $Author::   wbouach                                $$Date::   06 Jul 2009 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.H"
#include "KNKINHADP.H"
#include "KNKINHADP_L.H"
#include "KNKINHADP_IM.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKINHADP_vidInitCounter                                   */
/* !Description :  Lors du reset du calculateur, la variable                  */
/*                 Ids_decoll_inhib_cliq_counter est mise à 0                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 Ids_decoll_inhib_cliq_counter;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : A.BEN AMAR                                                  */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKINHADP_vidInitCounter(void)
{
   VEMS_vidSET(Ids_decoll_inhib_cliq_counter, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  KNKINHADP_vidUpdateCounter                                 */
/* !Description :  Lorsque l’on détecte un décollage engagé, le compteur      */
/*                 Ids_decoll_inhib_cliq_counter est maintenu à sa valeur     */
/*                 maximale calibrée. Lorsque l’on n’est plus ou pas en phase */
/*                 de décollage, le compteur est décrémenté                   */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 TqSys_nTarIdl;                                               */
/*  input uint8 Ids_decoll_regime_stat_offset;                                */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint8 Gear_engaged;                                                 */
/*  input uint8 Vitesse_vehicule;                                             */
/*  input uint8 Ids_decoll_vit_veh_thresh;                                    */
/*  input uint8 Ids_decollage_inhib_cliq_delay;                               */
/*  input uint8 Ids_decoll_inhib_cliq_counter;                                */
/*  output uint8 Ids_decoll_inhib_cliq_counter;                               */
/*  output uint8 Ids_decollage_inhib_cliq_delay;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : A.BEN AMAR                                                  */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void KNKINHADP_vidUpdateCounter(void)
{
   uint8  u8LocalGear_engaged;
   uint8  u8LocalVitesse_vehicule;
   uint8  u8LocalKnkCnt;
   uint16 u16LocalExt_nEng;
   uint16 u16LocalTqSys_nTarIdl;
   uint16 u16LocalOffset;
   uint16 u16LocalTarIdlEngSpd;


   VEMS_vidGET(TqSys_nTarIdl, u16LocalTqSys_nTarIdl);
   u16LocalOffset = (uint16)(Ids_decoll_regime_stat_offset * 128);
   u16LocalTarIdlEngSpd = (uint16)((uint32)( u16LocalOffset
                                           + u16LocalTqSys_nTarIdl)
                          /         4);

   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(Gear_engaged, u8LocalGear_engaged);
   VEMS_vidGET(Vitesse_vehicule, u8LocalVitesse_vehicule);

   if (  (u16LocalExt_nEng >= u16LocalTarIdlEngSpd)
      && (u8LocalGear_engaged == 0)
      && (u8LocalVitesse_vehicule <= Ids_decoll_vit_veh_thresh))
   {
      VEMS_vidSET(Ids_decoll_inhib_cliq_counter,
                  Ids_decollage_inhib_cliq_delay);
   }
   else
   {
      VEMS_vidGET(Ids_decoll_inhib_cliq_counter, u8LocalKnkCnt);
      if (u8LocalKnkCnt > 0)
      {
         u8LocalKnkCnt = (uint8)(u8LocalKnkCnt - 1);
         VEMS_vidSET(Ids_decoll_inhib_cliq_counter, u8LocalKnkCnt);
      }
   }
}
/*------------------------------- end of file --------------------------------*/