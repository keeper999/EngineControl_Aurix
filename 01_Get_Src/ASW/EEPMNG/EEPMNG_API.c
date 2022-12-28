/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : EEPMNG                                                  */
/* !Description     : EEPMNG Component                                        */
/*                                                                            */
/* !Module          : EEPMNG                                                  */
/* !Description     : Management of the EEPROM                                */
/*                                                                            */
/* !File            : EEPMNG_API.C                                            */
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
/*   1 / EEPMNG_bF02_Conditions                                               */
/*                                                                            */
/* !Reference   : V02 NT 09 03285 / 1                                         */
/* !OtherRefs   : VEMS V02 ECU#065305                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                          $*/
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/EEPMNG/EEPMNG_API.c_v           $*/
/* $Revision::   1.1                                                         $*/
/* $Author::   mbenfrad                               $$Date::   24 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "EEPMNG.h"
#include "EEPMNG_L.h"
#include "EEPMNG_im.h"
#include "NVMSRV.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  EEPMNG_bF02_Conditions                                     */
/* !Description :  Vérifie si les conditions sont réunies pour une remise à   */
/*                 zéro de l'eeprom. Appelé par le driver eeprom, cette       */
/*                 fonction  retourne un booléen à TRUE si le RAZ de l'eeprom */
/*                 est necessaire.                                            */
/* !Number      :  API.1                                                      */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret uint8  NVMSRV_u8GetStatus(argin NVMSRV_tudtObjectList         */
/*  udtObject);                                                               */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Mng_init_eeprom;                                            */
/*  input uint8 Objet_status;                                                 */
/*  input uint16 Version_eeprom;                                              */
/*  output uint8 Objet_status;                                                */
/*  output boolean Raz_eeprom_conditions;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Task     : task_name                                                      */
/* !Runnable : EEPMNG_bF02_Conditions                                         */
/* !Trigger  : Time (example: 256ms) or Event (example: key_off_on)           */
/*                                                                            */
/* !LastAuthor  : C.BANCHIERI                                                 */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
boolean EEPMNG_bF02_Conditions(void)
{
   boolean bLocalRaz_eeprom_conditions;
   Objet_status = 0;
   bLocalRaz_eeprom_conditions = FALSE;

   if (TRUE == Mng_init_eeprom)
   {
      Objet_status = NVMSRV_u8GetStatus(NVMSRV_u16OBJ_EEPROM_VERSION);

      if ((NVMSRV_u8DEFAULT == Objet_status) ||
          (Version_eeprom_def != Version_eeprom))
      {
         bLocalRaz_eeprom_conditions = TRUE;
      }
   }
   VEMS_vidSET(Raz_eeprom_conditions, bLocalRaz_eeprom_conditions);
   return (bLocalRaz_eeprom_conditions);
}

/*------------------------------- end of file --------------------------------*/