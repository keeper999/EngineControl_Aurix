/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : CANTXMIXMOD                                             */
/* !Description     : CANTXMIXMOD Component                                   */
/*                                                                            */
/* !Module          : CANTXMIXMOD                                             */
/* !Description     : SPECIFICATION D’INTERFACE MESSAGERIE CAN POUR GESTION   */
/*                    DES TRAMES MIXTES                                       */
/*                                                                            */
/* !File            : CANTXMIXMOD_FCT1.c                                      */
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
/*   1 / CANTXMIXMOD_vidInitOutput                                            */
/*   2 / CANTXMIXMOD_vidFastCheck                                             */
/*   3 / CANTXMIXMOD_vidSlowCheck                                             */
/*                                                                            */
/* !Reference   : PTS_DOC_5708641 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/ISCAN/CANTXMIXMOD/CANTXMIXMOD_FCT1$*/
/* $Revision::   1.0      $$Author::   hmelloul       $$Date::   02 Dec 2013 $*/
/* $Author::   hmelloul                               $$Date::   02 Dec 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "VEMS.H"
#include "CANTXMIXMOD.H"
#include "CANTXMIXMOD_L.H"
#include "CANTXMIXMOD_IM.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CANTXMIXMOD_vidInitOutput                                  */
/* !Description :  Cette fonction permet l'initialisation des variables       */
/*                 CANTXMIXMOD_bCoPtUHbRStrtAntPrev,                          */
/*                 CANTXMIXMOD_u8CoOptmElstElEPrev et                         */
/*                 CANTXMIXMOD_bThMgtbPosnFSFPrev.                            */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean CANTXMIXMOD_bCoPtUHbRStrtAntPrev;                          */
/*  output uint8 CANTXMIXMOD_u8CoOptmElstElEPrev;                             */
/*  output uint8 CANTXMIXMOD_u8CoEmSTTstTypEmPrev;                            */
/*  output boolean CANTXMIXMOD_bThMgtbPosnFSFPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CANTXMIXMOD_vidInitOutput(void)
{
   CANTXMIXMOD_bCoPtUHbRStrtAntPrev = 0;
   CANTXMIXMOD_u8CoOptmElstElEPrev = 0;
   CANTXMIXMOD_u8CoEmSTTstTypEmPrev = 0;
   CANTXMIXMOD_bThMgtbPosnFSFPrev = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CANTXMIXMOD_vidFastCheck                                   */
/* !Description :  Après rafraichissement des flux CoOptmEl_stElEProv,        */
/*                 CoPtUH_bRStrtAnt et CoEmSTT_stTypEmPredRstrt récurrence    */
/*                 10ms,  cette fonction permet de déclencher une émission de */
/*                 la trame  468h et/ou 1E8h.                                 */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean CoPtUH_bRStrtAnt;                                           */
/*  input uint8 CoEmSTT_stTypEmPredRstrt;                                     */
/*  input uint8 CoOptmEl_stElEProv;                                           */
/*  input boolean CANTXMIXMOD_bCoPtUHbRStrtAntPrev;                           */
/*  input uint8 CANTXMIXMOD_u8CoOptmElstElEPrev;                              */
/*  input uint8 CANTXMIXMOD_u8CoEmSTTstTypEmPrev;                             */
/*  output boolean ISCAN_bFastTxn468Req;                                      */
/*  output boolean ISCAN_bFastTxn1E8Req;                                      */
/*  output boolean CANTXMIXMOD_bCoPtUHbRStrtAntPrev;                          */
/*  output uint8 CANTXMIXMOD_u8CoEmSTTstTypEmPrev;                            */
/*  output uint8 CANTXMIXMOD_u8CoOptmElstElEPrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CANTXMIXMOD_vidFastCheck(void)
{
   boolean bLocalCoPtUH_bRStrtAnt;
   uint8   u8LocalCoEmSTT_stTypEmPredRstrt;
   uint8   u8LocalCoOptmEl_stElEProv;


   VEMS_vidGET(CoPtUH_bRStrtAnt, bLocalCoPtUH_bRStrtAnt);
   VEMS_vidGET(CoEmSTT_stTypEmPredRstrt, u8LocalCoEmSTT_stTypEmPredRstrt);
   VEMS_vidGET(CoOptmEl_stElEProv, u8LocalCoOptmEl_stElEProv);

   if (bLocalCoPtUH_bRStrtAnt != CANTXMIXMOD_bCoPtUHbRStrtAntPrev)
   {
      ISCAN_bFastTxn468Req = 1;
      ISCAN_bFastTxn1E8Req = 1;
   }
   else
   {
      if (u8LocalCoOptmEl_stElEProv != CANTXMIXMOD_u8CoOptmElstElEPrev)
      {
         ISCAN_bFastTxn468Req = 1;
      }
      else
      {
         ISCAN_bFastTxn468Req = 0;
      }

      if (u8LocalCoEmSTT_stTypEmPredRstrt != CANTXMIXMOD_u8CoEmSTTstTypEmPrev)
      {
         ISCAN_bFastTxn1E8Req = 1;
      }
      else
      {
         ISCAN_bFastTxn1E8Req = 0;
      }
   }
   CANTXMIXMOD_bCoPtUHbRStrtAntPrev = bLocalCoPtUH_bRStrtAnt;
   CANTXMIXMOD_u8CoEmSTTstTypEmPrev =
      (uint8)MATHSRV_udtMIN(u8LocalCoEmSTT_stTypEmPredRstrt, 3);
   CANTXMIXMOD_u8CoOptmElstElEPrev =
      (uint8)MATHSRV_udtMIN(u8LocalCoOptmEl_stElEProv, 15);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  CANTXMIXMOD_vidSlowCheck                                   */
/* !Description :  Après rafraichissement du flux ThMgt_bPosnFSF  à récurrence*/
/*                 1000ms,  cette fonction permet de déclencher une émission  */
/*                 de de la trame 1E8h.                                       */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Mohamed ali lihiouel                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean ThMgt_bPosnFSF;                                             */
/*  input boolean CANTXMIXMOD_bThMgtbPosnFSFPrev;                             */
/*  output boolean ISCAN_bTxnSlow1E8Req;                                      */
/*  output boolean CANTXMIXMOD_bThMgtbPosnFSFPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void CANTXMIXMOD_vidSlowCheck(void)
{
   boolean bLocalThMgtbPosnFSF;


   VEMS_vidGET(ThMgt_bPosnFSF, bLocalThMgtbPosnFSF);

   if (bLocalThMgtbPosnFSF != CANTXMIXMOD_bThMgtbPosnFSFPrev)
   {
      ISCAN_bTxnSlow1E8Req = 1;
   }
   else
   {
      ISCAN_bTxnSlow1E8Req = 0;
   }
   CANTXMIXMOD_bThMgtbPosnFSFPrev = bLocalThMgtbPosnFSF;
}
/*-------------------------------- end of file -------------------------------*/