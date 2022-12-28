/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : OILPROPPRESACQ                                          */
/* !Description     : OILPROPPRESACQ Component                                */
/*                                                                            */
/* !Module          : OILPROPPRESACQ                                          */
/* !Description     : OIL PROPORTIONAL PRESSURE ACQUISITION AND DIAGNOSIS     */
/*                                                                            */
/* !File            : OILPROPPRESACQ_FCT2.C                                   */
/*                                                                            */
/* !Scope           : Public                                                  */
/*                                                                            */
/* !Target          : All                                                     */
/*                                                                            */
/* !Vendor          : Valeo VEMS                                              */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/*   1 / OILPROPPRESACQ_vidOilPresAcqMean                                     */
/*   2 / OILPROPPRESACQ_vidInitPrsAcqMean                                     */
/*   3 / OILPROPPRESACQ_vidInitOilPrsFilt                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_6978050 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "OILPROPPRESACQ.h"
#include "OILPROPPRESACQ_L.h"
#include "OILPROPPRESACQ_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILPROPPRESACQ_vidOilPresAcqMean                           */
/* !Description :  cette focntcion calcule la valeur moyenne de la tension    */
/*                 proportionnelle de pression d'huile.                       */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_upOilMes;                                                */
/*  input uint16 Ext_prm_uPresOilMesMem[12];                                  */
/*  output uint16 Ext_prm_uPresOilMesMem[12];                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILPROPPRESACQ_vidOilPresAcqMean(void)
{
   uint8  u8LocalIndex;
   uint8  u8LocalIndex2;
   uint16 u16LocalExt_upOilMes;


   VEMS_vidGET(Ext_upOilMes, u16LocalExt_upOilMes);
   u16LocalExt_upOilMes = (uint16)MATHSRV_udtMIN(u16LocalExt_upOilMes, 4096);

   for (u8LocalIndex = 0; u8LocalIndex < 11; u8LocalIndex ++)
   {
      u8LocalIndex2 = (uint8)(11 - u8LocalIndex);
      Ext_prm_uPresOilMesMem[u8LocalIndex2] =
         Ext_prm_uPresOilMesMem[u8LocalIndex2 - 1];
   }
   Ext_prm_uPresOilMesMem[0] = u16LocalExt_upOilMes;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILPROPPRESACQ_vidInitPrsAcqMean                           */
/* !Description :  Fonction d'initialisation relative au bloc                 */
/*                 Oil_Presure_Acquisition_Mean                               */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_upOilMes;                                                */
/*  output uint16 Ext_prm_uPresOilMesMem[12];                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILPROPPRESACQ_vidInitPrsAcqMean(void)
{
   uint8  u8LocalIndex;
   uint16 u16LocalExt_upOilMes;


   /*F02_Oil_Presure_Acquisition_Mean*/
   VEMS_vidGET(Ext_upOilMes, u16LocalExt_upOilMes);
   u16LocalExt_upOilMes = (uint16)MATHSRV_udtMIN(u16LocalExt_upOilMes, 4096);

   for (u8LocalIndex = 0; u8LocalIndex < 12; u8LocalIndex ++)
   {
      Ext_prm_uPresOilMesMem[u8LocalIndex] = u16LocalExt_upOilMes;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  OILPROPPRESACQ_vidInitOilPrsFilt                           */
/* !Description :  Fonction d'initialisation relative au bloc                 */
/*                 _Oil_Pressure_Filtering                                    */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Oil_prm_noAcqOilPresLstSample_T[12];                          */
/*  input uint16 Ext_prm_uPresOilMesMem[12];                                  */
/*  input boolean CoPTSt_bEngRun;                                             */
/*  input uint16 Oil_upOilMesMean;                                            */
/*  input uint16 Ext_upOilMes;                                                */
/*  input uint16 Ext_uptOilSenPwr;                                            */
/*  input uint16 Oil_upOilMesAct;                                             */
/*  output uint16 Oil_upOilMesMean;                                           */
/*  output uint16 Oil_upOilMesAct;                                            */
/*  output uint32 OILPROPPRESACQ_u32OilActFilMEM;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void OILPROPPRESACQ_vidInitOilPrsFilt(void)
{
   boolean bLocalCoPTSt_bEngRun;
   uint8   u8LocalIndex;
   uint16  u16LocalFilterInput;
   uint16  u16LocalExt_uptOilSenPwr;
   uint16  u16LocalExt_upOilMes;
   uint32  u32Localsomme1;
   uint32  u32Localsomme2;
   uint32  u32LocalOil_upOilMesMean;
   uint32  u32LocalOil_upOilMesAct;


   /*F03_Oil_Pressure_Filtering*/
   u32Localsomme1 = 0;
   u32Localsomme2 = 0;
   for (u8LocalIndex = 0; u8LocalIndex < 12; u8LocalIndex ++)
   {
      u32Localsomme1 = ( u32Localsomme1
                       + ( Oil_prm_noAcqOilPresLstSample_T[u8LocalIndex]
                         * Ext_prm_uPresOilMesMem[u8LocalIndex]));

      u32Localsomme2 = ( u32Localsomme2
                       + Oil_prm_noAcqOilPresLstSample_T[u8LocalIndex]);
   }

   if (u32Localsomme2 != 0)
   {
      u32LocalOil_upOilMesMean = (u32Localsomme1 / u32Localsomme2);
      Oil_upOilMesMean = (uint16)(u32LocalOil_upOilMesMean);
   }
   else
   {
      Oil_upOilMesMean = 0;
   }

   VEMS_vidGET(CoPTSt_bEngRun, bLocalCoPTSt_bEngRun);
   if (bLocalCoPTSt_bEngRun != 0)
   {
      u16LocalFilterInput = Oil_upOilMesMean;
   }
   else
   {
      VEMS_vidGET(Ext_upOilMes, u16LocalExt_upOilMes);
      u16LocalFilterInput = u16LocalExt_upOilMes;
   }

   VEMS_vidGET(Ext_uptOilSenPwr, u16LocalExt_uptOilSenPwr);
   if (u16LocalExt_uptOilSenPwr != 0)
   {
      u32LocalOil_upOilMesAct = (uint32)( ( u16LocalFilterInput
                                          * 4096)
                                        / u16LocalExt_uptOilSenPwr);
      Oil_upOilMesAct = (uint16)MATHSRV_udtMIN(u32LocalOil_upOilMesAct, 4096);
   }
   else
   {
      Oil_upOilMesAct = 4096;
   }
   OILPROPPRESACQ_u32OilActFilMEM = (uint32)(Oil_upOilMesAct * 256);
}
/*---------------------------- end of file -----------------------------------*/