/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : DGOTEST                                                  */
/* !Description     : DGOTEST Component                                        */
/*                                                                            */
/* !Module          : DGOTEST                                                  */
/* !Description     : Gestionnaire de défauts unitaires                       */
/*                                                                            */
/* !File            : DGOTEST_SCH.c                                            */
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
/*   1 / DGOTEST_vidSdlSlow                                                    */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
#include "DGOTEST_L.h"
#include "DGOTEST.h"
#include "DGOTEST_im.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : Slow task of the OS                                         */
/* !Number      : SCH01                                                       */
/* !Reference   : V02 NT 08 07048 / 01                                        */
/*                                                                            */
/******************************************************************************/
/*   extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo,*/
/*   argin boolean bMonRun, argin boolean Ns_bMonWait);                       */
/*   input boolean DgoTest_bDgoAaStart_Bidon_C;                               */
/*   input boolean DgoTest_bDgoZzEnd_Bidon_C;                                 */
/*   input boolean DgoTest_bMonRunAaStart_Bidon_C;                            */
/*   input boolean DgoTest_bMonRunZzEnd_Bidon_C;                              */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Runnable : DGOTEST_vidSdlSlow                                              */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/* !LastAuthor  : S.BIET                                                      */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void DGOTEST_vidSdlSlow(void)
{
   uint16  u16LocalIdxStart;
   uint16  u16LocalIdxEnd;

   /* Affectation of the start and the end of the tableGDU_astrDftUnit */
   u16LocalIdxStart = (uint16)0;
   u16LocalIdxEnd = (uint16)(GD_DFT_NB - 1);

   /* Affectation of the calibrations */
   DgoTest_bDgoAaStart_Bidon = DgoTest_bDgoAaStart_Bidon_C;
   DgoTest_bDgoZzEnd_Bidon = DgoTest_bDgoZzEnd_Bidon_C;
   DgoTest_bMonRunAaStart_Bidon = DgoTest_bMonRunAaStart_Bidon_C;
   DgoTest_bMonRunZzEnd_Bidon = DgoTest_bMonRunZzEnd_Bidon_C;

   /* Call of the GDU */
   GDGAR_vidGdu(u16LocalIdxStart,
                DgoTest_bDgoAaStart_Bidon,
                DgoTest_bMonRunAaStart_Bidon,
                DIAG_DISPO);

   GDGAR_vidGdu(u16LocalIdxEnd,
                DgoTest_bDgoZzEnd_Bidon,
                DgoTest_bMonRunZzEnd_Bidon,
                DIAG_DISPO);
}