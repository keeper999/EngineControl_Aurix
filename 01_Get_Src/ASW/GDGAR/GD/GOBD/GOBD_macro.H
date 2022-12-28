/***************************************************************************
;**
;** FILE NAME      : GOBD.H
;**
;** FILE AUTHOR    : lthibau (VEES)
;**
;**************************************************************************/

#ifndef GOBD_MACRO_H
#define GOBD_MACRO_H

#include "STD_Types.h"
#include "GDFRM.h"
#include "GOBD_L.h"

#pragma inline(GOBD_bMngAutomateTrans_opt)
static  boolean GOBD_bMngAutomateTrans_opt
(
   uint16 u16IdxDft
)
{
   GDFRM_tenuGOBDState  enuLocalStDgo;     /* Automate state                  */
   boolean              bLocalRet;         /* Return value                    */

   enuLocalStDgo = GOBD_enustDgo[u16IdxDft];
   bLocalRet = FALSE;

   
   switch (GOBD_enustDgo[u16IdxDft])
   {
   case GOBD_ETAT_OK:
      GOBD_vidTransOK(u16IdxDft);
      break;
   case GOBD_ETAT_PENDING1:
      GOBD_vidTransPending1(u16IdxDft);
      break;
   case GOBD_ETAT_PENDING2:
      GOBD_vidTransPending2(u16IdxDft);
      break;
   case GOBD_ETAT_ENREGISTRE:
      GOBD_vidTransEnregistre(u16IdxDft);
      break;
   case GOBD_ETAT_HISTORIQUE_ON:
      GOBD_vidTransHistoOn (u16IdxDft);
      break;
   case GOBD_ETAT_HISTORIQUE_OFF:
      GOBD_vidTransHistoOff (u16IdxDft);
      break;

   default:
  //    SWFAIL_vidSoftwareErrorHook();
      break;
   }

   /* check that the GDU manager state has changed to return true. Return true
    is equivalent to generate a event which call all the API link to it */

   if(enuLocalStDgo != GOBD_enustDgo[u16IdxDft])
   {
      bLocalRet = TRUE;
   }
   return bLocalRet;

}



/* --------------------------------------------------------------------- */
/* Macro : GOBD_vidCntWUC_opt                                            */
/* Defintion                                                            :*/
/* --------------------------------------------------------------------- */
#define GOBD_vidCntWUC_opt(u16IdxDft)\
{\
   uint8 u8LocalGOBD_u8ctWUC;\
   if( (WUC_bWupSt == TRUE) && (GOBD_u8ctDC[u16IdxDft] == 0) )\
   {\
      if(GOBD_u8ctWUC[u16IdxDft] > 0)\
      {\
         u8LocalGOBD_u8ctWUC = (uint8)(GOBD_u8ctWUC[u16IdxDft] - 1);\
         GOBD_u8ctWUC[u16IdxDft] =\
            (uint8)MATHSRV_udtMIN(u8LocalGOBD_u8ctWUC, 100);\
      }\
   }\
}

/* --------------------------------------------------------------------- */
/* Macro : GOBD_vidGlbDC_opt                                             */
/* Defintion :                                                          :*/
/* --------------------------------------------------------------------- */
#define GOBD_vidGlbDC_opt(u16IdxDft,u8LocalDivision,u8LocalMask)\
{\
   uint8    u8LocalGOBD_u8ctDC;\
   \
   if((!((GD_astrDftEep[u16IdxDft].u8GduGobdManagement) & 0x01))\
      && (DC_au8DC_EEPROM[u8LocalDivision] & u8LocalMask))\
      /* LTHI : erreur sur l'opérateur, ne devrait il pas être un "&" simple\
         pareil pour les deux conditions      */\
   {  /* Start -> function F01_GOBD_DecCntDC */\
\
      if((GD_astrDftEep[u16IdxDft].u8GduGobdManagement) & 0x02)\
      /* LTHI : erreur sur l'operateur comme précédemment */\
      {\
         if(GOBD_u8ctDC[u16IdxDft] > 0)\
         {\
            u8LocalGOBD_u8ctDC = (uint8)(GOBD_u8ctDC[u16IdxDft] - 1);\
            GOBD_u8ctDC[u16IdxDft] =\
               (uint8)MATHSRV_udtMIN(u8LocalGOBD_u8ctDC, 10);\
         }\
      }\
      else\
      {\
         GOBD_u8ctDC[u16IdxDft] = 0;\
      }\
   }\
   /* End -> function F01_GOBD_DecCntDC */\
   /* Start -> function F01_GOBD_RstbNCf */\
   if (  (GOBD_u8ctWUC[u16IdxDft] == 0)\
      && (!((GD_astrDftEep[u16IdxDft].u8GduGobdManagement) & 0x01)))\
   {\
      /*QAC WARNING Macro use if else*/\
      GD_vidBitWrite(GD_astrDftEep[u16IdxDft].u8GduGobdManagement,\
                           BNCFDC,FALSE);\
   }\
   /* End -> function F01_GOBD_RstbNCf */\
   /*QAC WARNING Macro use if else*/\
   GD_vidBitWrite(GD_astrDftEep[u16IdxDft].u8GduGobdManagement,\
                     BPRESDC,FALSE);\
}

/* --------------------------------------------------------------------- */
/* Macro : GOBD_vidCDThdUp_opt                                           */
/* Defintion :                                                          :*/
/* --------------------------------------------------------------------- */
#define GOBD_vidCDThdUp_opt(u16IdxDft)\
{\
   boolean bLocalNcfDc;\
   boolean bLocalPresDc;\
   uint8   u8LocalNoNCfDC;\
   uint8   u8LocalNoHealDC;\
   u8LocalNoNCfDC = GD_astrClasObd[GD_au8IdxClasObd[u16IdxDft]].u8NoNCfDC;\
   u8LocalNoHealDC = GD_astrClasObd[GD_au8IdxClasObd[u16IdxDft]].u8NoHealDC;\
   bLocalPresDc = GD_bBitRead(GD_astrDftEep[u16IdxDft].u8GduGobdManagement,\
                             BPRESDC);\
   if(bLocalPresDc == FALSE)\
   {\
      GD_vidBitWrite(GD_astrDftEep[u16IdxDft].u8GduGobdManagement,\
                     BPRESDC,TRUE);\
      bLocalNcfDc = GD_bBitRead(GD_astrDftEep[u16IdxDft].u8GduGobdManagement,\
                             BNCFDC);\
      if(bLocalNcfDc == TRUE)\
      {\
         GOBD_u8ctDC[u16IdxDft] = u8LocalNoHealDC;\
      }\
      else\
      {  \
         if(GOBD_u8ctDC[u16IdxDft] < u8LocalNoNCfDC)\
         {\
            GOBD_u8ctDC[u16IdxDft] = (uint8)(GOBD_u8ctDC[u16IdxDft] + 1);\
         }\
         /* Check if the meter has reached the threshold */\
         if(GOBD_u8ctDC[u16IdxDft] >=  u8LocalNoNCfDC)\
         {\
            GOBD_u8ctDC[u16IdxDft] = u8LocalNoHealDC;\
         /*QAC WARNING Macro use if else*/\
         GD_vidBitWrite(GD_astrDftEep[u16IdxDft].u8GduGobdManagement,\
                           BNCFDC,TRUE);\
         }\
      }\
   }\
}
/* --------------------------------------------------------------------- */
/* Macro : GOBD_vidExitEveStObd_opt                                      */
/* Defintion :                                                          :*/
/* --------------------------------------------------------------------- */
#define GOBD_vidExitEveStObd_opt(u16IdxDft)\
{\
   if(GOBD_u8Inhib != 0x5A)\
   {\
      StatusOfDtc_StGOBD_opt(u16IdxDft);\
   }\
}

/* --------------------------------------------------------------------- */
/* Macro : GOBD_vidAutomate_opt                                          */
/* Defintion :                                                          :*/
/* --------------------------------------------------------------------- */
#define GOBD_vidAutomate_opt(u16IdxDft)\
{\
   boolean bLocalEvo;\
   bLocalEvo = GOBD_bMngAutomateTrans_opt(u16IdxDft);\
   if (FALSE == bLocalEvo)\
   {\
   }\
   else\
   {\
      GOBD_vidExitEveStObd_opt(u16IdxDft);\
   }\
}

/* --------------------------------------------------------------------- */
/* Macro : GOBD_vidIniCntWUC_opt                                         */
/* Defintion :                                                          :*/
/* --------------------------------------------------------------------- */
#define  GOBD_vidIniCntWUC_opt(u16IdxDft)\
{\
   GOBD_u8ctWUC[u16IdxDft] = (uint8)MATHSRV_udtMIN(GOBD_noWUCClr_C, 100);\
}


/* --------------------------------------------------------------------- */
/* Macro : GOBD_vidMngEveCDThdUp_opt                                     */
/* Defintion :                                                          :*/
/* --------------------------------------------------------------------- */
#define GOBD_vidMngEveCDThdUp_opt(u16IdxDft)\
{\
   if(GOBD_u8Inhib != 0x5A)\
   {\
      GOBD_vidCDThdUp_opt(u16IdxDft);\
      GOBD_vidAutomate_opt (u16IdxDft);\
      GOBD_vidIniCntWUC_opt (u16IdxDft);\
   }\
}




#endif /* GOBD_MACRO_H */



/*-------------------------------- end of file -------------------------------*/
