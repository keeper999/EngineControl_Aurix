/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SFTYMNGR                                                */
/* !Description     : SFTYMNGR Component                                      */
/*                                                                            */
/* !Module          : SFTYMNGR                                                */
/* !Description     : SAFETY TMS :SAFETY MANAGER                              */
/*                                                                            */
/* !File            : SFTYMNGR_FCT2.C                                         */
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
/*   1 / SFTYMNGR_vidGereEscalade                                             */
/*   2 / SFTYMNGR_vidEscaladeVSCtl                                            */
/*   3 / SFTYMNGR_vidEscaladeSTT                                              */
/*   4 / SFTYMNGR_vidEscaladeEM                                               */
/*   5 / SFTYMNGR_vidCoordinationDiagECU                                      */
/*   6 / SFTYMNGR_vidEscaladeDftECU                                           */
/*   7 / SFTYMNGR_vidEscaladeAttenteECU                                       */
/*   8 / SFTYMNGR_vidCoordinatDefautDgo                                       */
/*   9 / SFTYMNGR_vidCoordDefautEdgeECU                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_5199559 / 01                                        */
/* !OtherRefs   : CSCT_CGMT09_2399 / 1.8 br1                                  */
/* !OtherRefs   : VEMS V02 ECU#056956                                         */
/* !OtherRefs   : VEMS V02 ECU#061218                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/SFTYMNGR/SFTYMNGR_FCT2$*/
/* $Revision::   1.11     $$Author::   mbenfrad       $$Date::   21 May 2013 $*/
/* $Author::   mbenfrad                               $$Date::   21 May 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "SFTYMNGR.h"
#include "SFTYMNGR_l.h"
#include "SFTYMNGR_IM.h"
#include "MATHSRV.h"
#include "NVMSRV.h"
#include "VEMS.h"
#include "SWFAIL.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidGereEscalade                                   */
/* !Description :  gèrer l’escalade des défauts ECU et des modes de           */
/*                 recouvrement locaux VSCtl, STT et EM                       */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_015.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SFTYMNGR_vidEscaladeVSCtl();                             */
/*  extf argret void SFTYMNGR_vidEscaladeSTT();                               */
/*  extf argret void SFTYMNGR_vidEscaladeEM();                                */
/*  extf argret void SFTYMNGR_vidCoordinationDiagECU();                       */
/*  extf argret void SFTYMNGR_vidEscaladeDftECU();                            */
/*  extf argret void SFTYMNGR_vidCoordinatDefautDgo();                        */
/*  extf argret void SFTYMNGR_vidCoordDefautEdgeECU();                        */
/*  input boolean SFTYMNGR_bResetAutomate;                                    */
/*  input uint8 SftyMgt_ctDftLaddPrev;                                        */
/*  input uint8 SftyMgt_ctDftLaddCord;                                        */
/*  input uint8 SftyMgt_stDftLadd_T[10];                                      */
/*  output uint8 SftyMgt_ctDftLadd;                                           */
/*  output uint8 SFTYMNGR_u8ctDftLaddPrev;                                    */
/*  output uint8 SftyMgt_stDftLaddIp;                                         */
/*  output boolean SFTYMNGR_bResetAutomate;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidGereEscalade(void)
{
   uint8 u8LocalCtDftLadd;
   uint8 u8LocalstDftLaddIp;
   uint8 u8LocalCtDftLaddPrev;


   if (SFTYMNGR_bResetAutomate == 0)
   {
      VEMS_vidGET(SftyMgt_ctDftLaddPrev,u8LocalCtDftLaddPrev);
      u8LocalCtDftLadd =
            (uint8)MATHSRV_udtMAX(u8LocalCtDftLaddPrev, SftyMgt_ctDftLaddCord);
      u8LocalCtDftLadd = (uint8)MATHSRV_udtMIN(u8LocalCtDftLadd, 9);
      VEMS_vidSET(SftyMgt_ctDftLadd, u8LocalCtDftLadd);
      SFTYMNGR_u8ctDftLaddPrev = u8LocalCtDftLadd;
      u8LocalstDftLaddIp = SftyMgt_stDftLadd_T[u8LocalCtDftLadd];
      SftyMgt_stDftLaddIp = (uint8)MATHSRV_udtMIN(u8LocalstDftLaddIp, 4);
      SFTYMNGR_bResetAutomate = 1;
   }
   SFTYMNGR_vidEscaladeVSCtl();
   SFTYMNGR_vidEscaladeSTT();
   SFTYMNGR_vidEscaladeEM();
   SFTYMNGR_vidCoordinationDiagECU();
   SFTYMNGR_vidEscaladeDftECU();
   SFTYMNGR_vidCoordinatDefautDgo();
   SFTYMNGR_vidCoordDefautEdgeECU();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidEscaladeVSCtl                                  */
/* !Description :  gérer le mode de recouvrement local VSCtl                  */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_016.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean SftyMgt_bDgoIrvVSCtlPrev;                                   */
/*  input st101 SFTYMNGR_stDiagVSCtlState;                                    */
/*  input boolean SftyMgt_bKeyOffEdge;                                        */
/*  input boolean SftyMgt_bDftIpEnaVSCtl;                                     */
/*  output st101 SFTYMNGR_stDiagVSCtlState;                                   */
/*  output boolean SftyMgt_bDgoIrvVSCtlTmp;                                   */
/*  output boolean SftyMgt_bDgoIrvEdgeVSCtl;                                  */
/*  output boolean SftyMgt_bDftIpVSCtlLadd;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidEscaladeVSCtl(void)
{
   boolean bLocalSftyMgtDgoIrvVSCtlPrev;


   VEMS_vidGET(SftyMgt_bDgoIrvVSCtlPrev,bLocalSftyMgtDgoIrvVSCtlPrev);
   switch (SFTYMNGR_stDiagVSCtlState)
   {
      case NOMINAL_VSCTL:
         if (SftyMgt_bKeyOffEdge != 0)
         {
            SFTYMNGR_stDiagVSCtlState = NOMINAL_VSCTL;
            SftyMgt_bDgoIrvVSCtlTmp = 0;
            SftyMgt_bDgoIrvEdgeVSCtl = 0;
            SftyMgt_bDftIpVSCtlLadd = 0;
         }
         else
         {
            if (SftyMgt_bDftIpEnaVSCtl != 0)
            {
               SFTYMNGR_stDiagVSCtlState = DEFAUT_VSCTL;
               SftyMgt_bDgoIrvVSCtlTmp = 1;
               SftyMgt_bDgoIrvEdgeVSCtl = 1;
            }
         }
         break;

      case DEFAUT_VSCTL:
         if (SftyMgt_bKeyOffEdge != 0)
         {
            SFTYMNGR_stDiagVSCtlState = NOMINAL_VSCTL;
            SftyMgt_bDgoIrvVSCtlTmp = 0;
            SftyMgt_bDgoIrvEdgeVSCtl = 0;
            SftyMgt_bDftIpVSCtlLadd = 0;
         }
         else
         {
            if (SftyMgt_bDftIpEnaVSCtl != 0)
            {
               SFTYMNGR_stDiagVSCtlState = LADDER_VSCTL;
               SftyMgt_bDgoIrvEdgeVSCtl = 0;
               SftyMgt_bDftIpVSCtlLadd = 1;
            }
            else
            {
               SFTYMNGR_stDiagVSCtlState = IRV_VSCTL;
               SftyMgt_bDgoIrvEdgeVSCtl = 0;
               SftyMgt_bDftIpVSCtlLadd = 0;
            }
         }
         break;

      case IRV_VSCTL:
         if (SftyMgt_bKeyOffEdge != 0)
         {
            SFTYMNGR_stDiagVSCtlState = NOMINAL_VSCTL;
            SftyMgt_bDgoIrvVSCtlTmp = 0;
            SftyMgt_bDgoIrvEdgeVSCtl = 0;
            SftyMgt_bDftIpVSCtlLadd = 0;
         }
         else
         {
            if (SftyMgt_bDftIpEnaVSCtl != 0)
            {
               SFTYMNGR_stDiagVSCtlState = LADDER_VSCTL;
               SftyMgt_bDftIpVSCtlLadd = 1;
            }
         }
         break;

      case LADDER_VSCTL:
         if (SftyMgt_bKeyOffEdge != 0)
         {
            SFTYMNGR_stDiagVSCtlState = NOMINAL_VSCTL;
            SftyMgt_bDgoIrvVSCtlTmp = 0;
            SftyMgt_bDgoIrvEdgeVSCtl = 0;
            SftyMgt_bDftIpVSCtlLadd = 0;
         }
         else
         {
            if (SftyMgt_bDftIpEnaVSCtl != 0)
            {
               SFTYMNGR_stDiagVSCtlState = LADDER_VSCTL;
               SftyMgt_bDftIpVSCtlLadd = 1;
            }
            else
            {
               SFTYMNGR_stDiagVSCtlState = IRV_VSCTL;
               SftyMgt_bDftIpVSCtlLadd = 0;
            }
         }
         break;

      default:
         if (  (bLocalSftyMgtDgoIrvVSCtlPrev != 0)
            && (SftyMgt_bKeyOffEdge == 0) )
         {
            SFTYMNGR_stDiagVSCtlState = IRV_VSCTL;
            SftyMgt_bDgoIrvVSCtlTmp = 1;
            SftyMgt_bDftIpVSCtlLadd = 0;
         }
         else
         {
            SFTYMNGR_stDiagVSCtlState = NOMINAL_VSCTL;
            SftyMgt_bDgoIrvVSCtlTmp = 0;
            SftyMgt_bDgoIrvEdgeVSCtl = 0;
            SftyMgt_bDftIpVSCtlLadd = 0;
         }
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidEscaladeSTT                                    */
/* !Description :  gérer le mode de recouvrement local STT                    */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean SftyMgt_bDgoIrvSTTPrev;                                     */
/*  input st102 SFTYMNGR_stDiagSTTState;                                      */
/*  input boolean SftyMgt_bKeyOffEdge;                                        */
/*  input boolean SftyMgt_bDftIpEnaSTT;                                       */
/*  output st102 SFTYMNGR_stDiagSTTState;                                     */
/*  output boolean SftyMgt_bDgoIrvSTTTmp;                                     */
/*  output boolean SftyMgt_bDgoIrvEdgeSTT;                                    */
/*  output boolean SftyMgt_bDftIpSTTLadd;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidEscaladeSTT(void)
{
   boolean bLocalSftyMgtDgoIrvSTTPrev;


   VEMS_vidGET(SftyMgt_bDgoIrvSTTPrev,bLocalSftyMgtDgoIrvSTTPrev);
   switch (SFTYMNGR_stDiagSTTState)
   {
      case NOMINAL_STT:
         if (SftyMgt_bKeyOffEdge != 0)
         {
            SFTYMNGR_stDiagSTTState = NOMINAL_STT;
            SftyMgt_bDgoIrvSTTTmp = 0;
            SftyMgt_bDgoIrvEdgeSTT = 0;
            SftyMgt_bDftIpSTTLadd = 0;
         }
         else
         {
            if (SftyMgt_bDftIpEnaSTT != 0)
            {
               SFTYMNGR_stDiagSTTState = DEFAUT_STT;
               SftyMgt_bDgoIrvSTTTmp = 1;
               SftyMgt_bDgoIrvEdgeSTT = 1;
            }
         }
         break;

      case DEFAUT_STT:
         if (SftyMgt_bKeyOffEdge != 0)
         {
            SFTYMNGR_stDiagSTTState = NOMINAL_STT;
            SftyMgt_bDgoIrvSTTTmp = 0;
            SftyMgt_bDgoIrvEdgeSTT = 0;
            SftyMgt_bDftIpSTTLadd = 0;
         }
         else
         {
            if (SftyMgt_bDftIpEnaSTT != 0)
            {
               SFTYMNGR_stDiagSTTState = LADDER_STT;
               SftyMgt_bDgoIrvEdgeSTT = 0;
               SftyMgt_bDftIpSTTLadd = 1;
            }
            else
            {
               SFTYMNGR_stDiagSTTState = IRV_STT;
               SftyMgt_bDgoIrvEdgeSTT = 0;
               SftyMgt_bDftIpSTTLadd = 0;
            }
         }
         break;

      case IRV_STT:
         if (SftyMgt_bKeyOffEdge != 0)
         {
            SFTYMNGR_stDiagSTTState = NOMINAL_STT;
            SftyMgt_bDgoIrvSTTTmp = 0;
            SftyMgt_bDgoIrvEdgeSTT = 0;
            SftyMgt_bDftIpSTTLadd = 0;
         }
         else
         {
            if (SftyMgt_bDftIpEnaSTT != 0)
            {
               SFTYMNGR_stDiagSTTState = LADDER_STT;
               SftyMgt_bDftIpSTTLadd = 1;
            }
         }
         break;

      case LADDER_STT:
         if (SftyMgt_bKeyOffEdge != 0)
         {
            SFTYMNGR_stDiagSTTState = NOMINAL_STT;
            SftyMgt_bDgoIrvSTTTmp = 0;
            SftyMgt_bDgoIrvEdgeSTT = 0;
            SftyMgt_bDftIpSTTLadd = 0;
         }
         else
         {
            if (SftyMgt_bDftIpEnaSTT != 0)
            {
               SFTYMNGR_stDiagSTTState = LADDER_STT;
               SftyMgt_bDftIpSTTLadd = 1;
            }
            else
            {
               SFTYMNGR_stDiagSTTState = IRV_STT;
               SftyMgt_bDftIpSTTLadd = 0;
            }
         }
         break;

      default:
         if (  (bLocalSftyMgtDgoIrvSTTPrev != 0)
            && (SftyMgt_bKeyOffEdge == 0) )
         {
            SFTYMNGR_stDiagSTTState = IRV_STT;
            SftyMgt_bDgoIrvSTTTmp = 1;
            SftyMgt_bDftIpSTTLadd = 0;
         }
         else
         {
            SFTYMNGR_stDiagSTTState = NOMINAL_STT;
            SftyMgt_bDgoIrvSTTTmp = 0;
            SftyMgt_bDgoIrvEdgeSTT = 0;
            SftyMgt_bDftIpSTTLadd = 0;
         }
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidEscaladeEM                                     */
/* !Description :  gérer le mode de recouvrement local VSCtl                  */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_018.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean SftyMgt_bDgoIrvEMPrev;                                      */
/*  input st104 SFTYMNGR_stDiagEMState;                                       */
/*  input boolean SftyMgt_bKeyOffEdge;                                        */
/*  input boolean SftyMgt_bDftIpEnaEM;                                        */
/*  output st104 SFTYMNGR_stDiagEMState;                                      */
/*  output boolean SftyMgt_bDgoIrvEMTmp;                                      */
/*  output boolean SftyMgt_bDgoIrvEdgeEM;                                     */
/*  output boolean SftyMgt_bDftIpEMLadd;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidEscaladeEM(void)
{
   boolean bLocalSftyMgtDgoIrvEMPrev;


   VEMS_vidGET(SftyMgt_bDgoIrvEMPrev,bLocalSftyMgtDgoIrvEMPrev);
   switch (SFTYMNGR_stDiagEMState)
   {
      case NOMINAL_EM:
         if (SftyMgt_bKeyOffEdge != 0)
         {
            SFTYMNGR_stDiagEMState = NOMINAL_EM;
            SftyMgt_bDgoIrvEMTmp = 0;
            SftyMgt_bDgoIrvEdgeEM = 0;
            SftyMgt_bDftIpEMLadd = 0;
         }
         else
         {
            if (SftyMgt_bDftIpEnaEM != 0)
            {
               SFTYMNGR_stDiagEMState = DEFAUT_EM;
               SftyMgt_bDgoIrvEMTmp = 1;
               SftyMgt_bDgoIrvEdgeEM = 1;
            }
         }
         break;

      case DEFAUT_EM:
         if (SftyMgt_bKeyOffEdge != 0)
         {
            SFTYMNGR_stDiagEMState = NOMINAL_EM;
            SftyMgt_bDgoIrvEMTmp = 0;
            SftyMgt_bDgoIrvEdgeEM = 0;
            SftyMgt_bDftIpEMLadd = 0;
         }
         else
         {
            if (SftyMgt_bDftIpEnaEM != 0)
            {
               SFTYMNGR_stDiagEMState = LADDER_EM;
               SftyMgt_bDgoIrvEdgeEM = 0;
               SftyMgt_bDftIpEMLadd = 1;
            }
            else
            {
               SFTYMNGR_stDiagEMState = IRV_EM;
               SftyMgt_bDgoIrvEdgeEM = 0;
               SftyMgt_bDftIpEMLadd = 0;
            }
         }
         break;

      case IRV_EM:
         if (SftyMgt_bKeyOffEdge != 0)
         {
            SFTYMNGR_stDiagEMState = NOMINAL_EM;
            SftyMgt_bDgoIrvEMTmp = 0;
            SftyMgt_bDgoIrvEdgeEM = 0;
            SftyMgt_bDftIpEMLadd = 0;
         }
         else
         {
            if (SftyMgt_bDftIpEnaEM != 0)
            {
               SFTYMNGR_stDiagEMState = LADDER_EM;
               SftyMgt_bDftIpEMLadd = 1;
            }
         }
         break;

      case LADDER_EM:
         if (SftyMgt_bKeyOffEdge != 0)
         {
            SFTYMNGR_stDiagEMState = NOMINAL_EM;
            SftyMgt_bDgoIrvEMTmp = 0;
            SftyMgt_bDgoIrvEdgeEM = 0;
            SftyMgt_bDftIpEMLadd = 0;
         }
         else
         {
            if (SftyMgt_bDftIpEnaEM != 0)
            {
               SFTYMNGR_stDiagEMState = LADDER_EM;
               SftyMgt_bDftIpEMLadd = 1;
            }
            else
            {
               SFTYMNGR_stDiagEMState = IRV_EM;
               SftyMgt_bDftIpEMLadd = 0;
            }
         }
         break;

      default:
         if (  (bLocalSftyMgtDgoIrvEMPrev != 0)
            && (SftyMgt_bKeyOffEdge == 0) )
         {
            SFTYMNGR_stDiagEMState = IRV_EM;
            SftyMgt_bDgoIrvEMTmp = 1;
            SftyMgt_bDftIpEMLadd = 0;
         }
         else
         {
            SFTYMNGR_stDiagEMState = NOMINAL_EM;
            SftyMgt_bDgoIrvEMTmp = 0;
            SftyMgt_bDgoIrvEdgeEM = 0;
            SftyMgt_bDftIpEMLadd = 0;
         }
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidCoordinationDiagECU                            */
/* !Description :  synthétiser les défauts remontant de l’escalade VSCtl, STT */
/*                 et EM                                                      */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_019.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean SftyMgt_bDftIpEnaECU;                                       */
/*  input boolean SftyMgt_bDftIpVSCtlLadd;                                    */
/*  input boolean SftyMgt_bDftIpSTTLadd;                                      */
/*  input boolean SftyMgt_bDftIpEMLadd;                                       */
/*  output boolean SftyMgt_bDftIpECUCord;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidCoordinationDiagECU(void)
{
   if (  (SftyMgt_bDftIpEnaECU != 0)
      || (SftyMgt_bDftIpVSCtlLadd != 0)
      || (SftyMgt_bDftIpSTTLadd != 0)
      || (SftyMgt_bDftIpEMLadd != 0) )
   {
      SftyMgt_bDftIpECUCord = 1;
   }
   else
   {
      SftyMgt_bDftIpECUCord = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidEscaladeDftECU                                 */
/* !Description :  gèrer l’escalade et la priorisation des défauts ECU et     */
/*                 safety 3                                                   */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_020.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SFTYMNGR_vidEscaladeAttenteECU();                        */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st103 SFTYMNGR_stEscaladeDefautsState;                              */
/*  input uint8 SftyMgt_stDftLadd_T[10];                                      */
/*  input boolean SftyMgt_bKeyOffEdge;                                        */
/*  input boolean SftyMgt_bEnaDftKeyOff_C;                                    */
/*  input boolean SftyMgt_bDftIpECUCord;                                      */
/*  input boolean SftyMgt_bSfty3RstHwReqEdge;                                 */
/*  input boolean SftyMgt_bDftIpEnaAutChkPrio;                                */
/*  input boolean SftyMgt_bSfty3EngStopReqEdge;                               */
/*  input uint8 SftyMgt_stDftLaddIp;                                          */
/*  input uint8 SftyMgt_ctDftLaddPrev;                                        */
/*  input uint8 SftyMgt_ctDftLaddCord;                                        */
/*  output uint8 SftyMgt_ctDftLadd;                                           */
/*  output boolean SftyMgt_bEveKeyOffWrMem;                                   */
/*  output uint8 SftyMgt_stDftLaddIp;                                         */
/*  output st103 SFTYMNGR_stEscaladeDefautsState;                             */
/*  output boolean SftyMgt_bDgoIrvEdgeECU;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidEscaladeDftECU(void)
{
   uint8  u8LocalCtDftLadd;
   uint8  u8LocalCtDftLaddPrev;


   switch (SFTYMNGR_stEscaladeDefautsState)
   {
      case KEYOFF:
         u8LocalCtDftLadd = 0;
         VEMS_vidSET(SftyMgt_ctDftLadd,u8LocalCtDftLadd);
         SftyMgt_bEveKeyOffWrMem = 0;
         SftyMgt_stDftLaddIp = SftyMgt_stDftLadd_T[u8LocalCtDftLadd];
         SFTYMNGR_stEscaladeDefautsState = DEFAUT_INACTIF;
         SftyMgt_bDgoIrvEdgeECU = 0;
         break;

      case DEFAUT_INACTIF:
         if (SftyMgt_bKeyOffEdge != 0)
         {
            if (SftyMgt_bEnaDftKeyOff_C != 0)
            {
               SftyMgt_bEveKeyOffWrMem = 1;
            }
            else
            {
               SftyMgt_bEveKeyOffWrMem = 0;
            }
            SFTYMNGR_stEscaladeDefautsState = KEYOFF;
         }
         else
         {
               SFTYMNGR_vidEscaladeAttenteECU();
            if (  (SftyMgt_bDftIpECUCord != 0)
               || (SftyMgt_bSfty3RstHwReqEdge != 0)
               || (SftyMgt_bDftIpEnaAutChkPrio != 0)
               || (SftyMgt_bSfty3EngStopReqEdge != 0) )
            {
               if (SftyMgt_stDftLaddIp != 4)
               {
                  SFTYMNGR_stEscaladeDefautsState = DEFAUT_ACTIF;
               }
               else
               {
                  SFTYMNGR_stEscaladeDefautsState = FIN_ESCALADE_DEFAUT_ACTIF;
               }
               SftyMgt_bDgoIrvEdgeECU = 1;
            }
         }
         break;

      case DEFAUT_ACTIF:
         if (SftyMgt_bKeyOffEdge != 0)
         {
            if (SftyMgt_bEnaDftKeyOff_C != 0)
            {
               SftyMgt_bEveKeyOffWrMem = 1;
            }
            else
            {
               SftyMgt_bEveKeyOffWrMem = 0;
            }
            SFTYMNGR_stEscaladeDefautsState = KEYOFF;
         }
         else
         {
            SFTYMNGR_vidEscaladeAttenteECU();
            if (  (SftyMgt_bDftIpECUCord != 0)
               || (SftyMgt_bSfty3RstHwReqEdge != 0)
               || (SftyMgt_bDftIpEnaAutChkPrio != 0)
               || (SftyMgt_bSfty3EngStopReqEdge != 0) )
            {
               if (SftyMgt_stDftLaddIp == 4)
               {
                  SFTYMNGR_stEscaladeDefautsState = FIN_ESCALADE_DEFAUT_ACTIF;
               }
               else
               {
                  SFTYMNGR_stEscaladeDefautsState = DEFAUT_ACTIF;
               }
               SftyMgt_bDgoIrvEdgeECU = 1;
            }
            else
            {
               SFTYMNGR_stEscaladeDefautsState = DEFAUT_INACTIF;
               SftyMgt_bDgoIrvEdgeECU = 0;
            }
         }
         break;

       case FIN_ESCALADE_DEFAUT_ACTIF:
         if (SftyMgt_bKeyOffEdge != 0)
         {
            if (SftyMgt_bEnaDftKeyOff_C != 0)
            {
               SftyMgt_bEveKeyOffWrMem = 1;
            }
            else
            {
               SftyMgt_bEveKeyOffWrMem = 0;
            }
            SFTYMNGR_stEscaladeDefautsState = KEYOFF;
         }
         else
         {
            SFTYMNGR_vidEscaladeAttenteECU();
            SFTYMNGR_stEscaladeDefautsState = FIN_ESCALADE_DEFAUT_INACTIF;
            SftyMgt_bDgoIrvEdgeECU = 0;
         }
         break;

      case FIN_ESCALADE_DEFAUT_INACTIF:
         if (SftyMgt_bKeyOffEdge != 0)
         {
            if (SftyMgt_bEnaDftKeyOff_C != 0)
            {
               SftyMgt_bEveKeyOffWrMem = 1;
            }
            else
            {
               SftyMgt_bEveKeyOffWrMem = 0;
            }
            SFTYMNGR_stEscaladeDefautsState = KEYOFF;
         }
         else
         {
            SFTYMNGR_vidEscaladeAttenteECU();
         }
         break;

      default:
         VEMS_vidGET(SftyMgt_ctDftLaddPrev,u8LocalCtDftLaddPrev);
         u8LocalCtDftLadd =
            (uint8)MATHSRV_udtMAX(u8LocalCtDftLaddPrev, SftyMgt_ctDftLaddCord);
         u8LocalCtDftLadd = (uint8)MATHSRV_udtMIN(u8LocalCtDftLadd, 9);
         SftyMgt_stDftLaddIp = SftyMgt_stDftLadd_T[u8LocalCtDftLadd];
         SFTYMNGR_stEscaladeDefautsState = DEFAUT_INACTIF;
         SftyMgt_bDgoIrvEdgeECU = 0;
         VEMS_vidSET(SftyMgt_ctDftLadd, u8LocalCtDftLadd);
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidEscaladeAttenteECU                             */
/* !Description :  gèrer la priorisation des défauts ECU                      */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 SftyMgt_ctDftLadd;                                            */
/*  input uint8 SftyMgt_stDftLaddIp;                                          */
/*  input boolean SftyMgt_bDftIpEnaAutChkPrio;                                */
/*  input boolean SftyMgt_bSfty3RstHwReqEdge;                                 */
/*  input uint8 SftyMgt_stSfty3RstHwReq_C;                                    */
/*  input boolean SftyMgt_bSfty3EngStopReqEdge;                               */
/*  input uint8 SftyMgt_stSfty3EngStopReq_C;                                  */
/*  input boolean SftyMgt_bDftIpECUCord;                                      */
/*  input uint8 SftyMgt_stDftLadd_T[10];                                      */
/*  output uint8 SftyMgt_stDftLaddIp;                                         */
/*  output uint8 SftyMgt_ctDftLadd;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidEscaladeAttenteECU(void)
{
   uint8  u8LocalCtDftLadd;
   uint16 u16LocalCtDftLaddCnt;


   VEMS_vidGET(SftyMgt_ctDftLadd, u8LocalCtDftLadd);

   if (SftyMgt_stDftLaddIp != 4)
   {
      if (SftyMgt_bDftIpEnaAutChkPrio != 0)
      {
         SftyMgt_stDftLaddIp = 4;
      }
      else
      {
         if (SftyMgt_bSfty3RstHwReqEdge !=0)
         {
            SftyMgt_stDftLaddIp =
               (uint8)MATHSRV_udtMIN (SftyMgt_stSfty3RstHwReq_C, 4);
         }
         else
         {
            if (SftyMgt_bSfty3EngStopReqEdge !=0)
            {
               SftyMgt_stDftLaddIp =
                  (uint8)MATHSRV_udtMIN (SftyMgt_stSfty3EngStopReq_C, 4);
            }
            else
            {
               if (SftyMgt_bDftIpECUCord !=0)
               {
                  u16LocalCtDftLaddCnt= (uint16)(u8LocalCtDftLadd + 1);
                  u8LocalCtDftLadd =
                     (uint8) MATHSRV_udtMIN(u16LocalCtDftLaddCnt, 9);
                  SftyMgt_stDftLaddIp = SftyMgt_stDftLadd_T[u8LocalCtDftLadd];
                  VEMS_vidSET(SftyMgt_ctDftLadd, u8LocalCtDftLadd);
               }
            }
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidCoordinatDefautDgo                             */
/* !Description :  synthétisés les demande d’inhibition après action de       */
/*                 recouvrement et/ou de reset provenant des blocs escalade   */
/*                 globale, VSCtl, STT et EM                                  */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_021.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 SftyMgt_stDftLaddIp;                                          */
/*  input uint8 SftyMgt_stNom_C;                                              */
/*  input boolean SftyMgt_bDgoIrvVSCtlTmp;                                    */
/*  input boolean SftyMgt_bDgoIrvSTTTmp;                                      */
/*  input boolean SftyMgt_bDgoIrvEMTmp;                                       */
/*  output boolean SftyMgt_bDgoIrvECUTmp;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidCoordinatDefautDgo(void)
{
   if (  (SftyMgt_stDftLaddIp != SftyMgt_stNom_C)
      || (SftyMgt_bDgoIrvVSCtlTmp != 0)
      || (SftyMgt_bDgoIrvSTTTmp != 0)
      || (SftyMgt_bDgoIrvEMTmp != 0) )
   {
      SftyMgt_bDgoIrvECUTmp = 1;
   }
   else
   {
      SftyMgt_bDgoIrvECUTmp = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SFTYMNGR_vidCoordDefautEdgeECU                             */
/* !Description :  synthétiser les demande d’inhibition après action de       */
/*                 recouvrement et/ou de reset provenant des blocs escalade   */
/*                 globale, VSCtl, STT et EM et les demandes d'écritures      */
/*                 mémoire sauvegardée                                        */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_10_01256_022.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean SftyMgt_bInhDftVSCtlEdge_C;                                 */
/*  input boolean SftyMgt_bDgoIrvEdgeVSCtl;                                   */
/*  input boolean SftyMgt_bInhDftSTTEdge_C;                                   */
/*  input boolean SftyMgt_bDgoIrvEdgeSTT;                                     */
/*  input boolean SftyMgt_bInhDftEMEdge_C;                                    */
/*  input boolean SftyMgt_bDgoIrvEdgeEM;                                      */
/*  input boolean SftyMgt_bDgoIrvEdgeECU;                                     */
/*  output boolean SftyMgt_bInhDftEdge;                                       */
/*  output boolean SftyMgt_bEveDftWrMem;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SFTYMNGR_vidCoordDefautEdgeECU(void)
{
   boolean bLocalDgoIrvEdgeVSCtl;
   boolean bLocalDgoIrvEdgeSTT;
   boolean bLocalDgoIrvEdgeEM;


   if (SftyMgt_bInhDftVSCtlEdge_C != 0)
   {
      bLocalDgoIrvEdgeVSCtl = 0;
   }
   else
   {
      bLocalDgoIrvEdgeVSCtl = SftyMgt_bDgoIrvEdgeVSCtl;
   }

   if (SftyMgt_bInhDftSTTEdge_C != 0)
   {
      bLocalDgoIrvEdgeSTT = 0;
   }
   else
   {
      bLocalDgoIrvEdgeSTT = SftyMgt_bDgoIrvEdgeSTT;
   }

   if (SftyMgt_bInhDftEMEdge_C != 0)
   {
      bLocalDgoIrvEdgeEM = 0;
   }
   else
   {
      bLocalDgoIrvEdgeEM = SftyMgt_bDgoIrvEdgeEM;
   }

   if (  (SftyMgt_bDgoIrvEdgeECU != 0)
      || (bLocalDgoIrvEdgeVSCtl != 0)
      || (bLocalDgoIrvEdgeSTT != 0)
      || (bLocalDgoIrvEdgeEM != 0) )
   {
      SftyMgt_bInhDftEdge = 1;

   }
   else
   {
      SftyMgt_bInhDftEdge = 0;

   }
   if(  (SftyMgt_bDgoIrvEdgeECU != 0)
     || (SftyMgt_bDgoIrvEdgeVSCtl != 0)
     || (SftyMgt_bDgoIrvEdgeSTT != 0)
     || (SftyMgt_bDgoIrvEdgeEM != 0))
   {
      SftyMgt_bEveDftWrMem = 1;
   }
   else
   {
      SftyMgt_bEveDftWrMem = 0;
   }
}

#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/