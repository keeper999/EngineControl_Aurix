/******************************************************************************/
/* !Layer           : MCAL                                                    */
/* !Component       : KRN                                                     */
/* !Description     :                                                         */
/*                                                                            */
/* !File            : KRN_4.c                                                 */
/* !Description     : Real Time Checksum check                                */
/*                                                                            */
/* !Reference       :                                                         */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT VALEO all rights reserved                                        */
/******************************************************************************/
/* Dimension Informations
 * %PCMS_HEADER_SUBSTITUTION_START:%
 * The PID has this format: <Product ID>:<Item ID>.<Variant>-<Item Type>;<Revision>
 * %PID: P2017_BSW:0A192556.A-SRC;2 %
 * %PCMS_HEADER_SUBSTITUTION_END:%
 ******************************************************************************/

#include "Std_Types.h"
#include "Std_Limits.h"
#include "DEVHAL.h"
#include "DGOHAL.h"
#include "RTMCKS.h"
#include "Wdg.h"
#include "KRN.h"
#include "KRN_Private.h"


/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/

#define KRN_START_SEC_CODE
#include "KRN_MemMap.h"

/******************************************************************************/
/* !Description : Initialize the checksum check                               */
/* !Reference   : NONE                                                        */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidInitChecksumCheck(void)
{
   boolean bLocalEmulCardChecked;


   KRN_u16SoftChecksum     = KRN_ku16SoftChecksum;
   KRN_u16CalibChecksum    = KRN_ku16CalibChecksum;
   KRN_u16TmsSoftChecksum  = KRN_ku16TmsSoftChecksum;
   KRN_u16TmsCalibChecksum = KRN_ku16TmsCalibChecksum;

   KRN_bFirstSoftChecksumDone    = FALSE;
   KRN_vbFirstTmsSoftChecksumDone = FALSE;
   KRN_bInitTmsChecksumOK        = TRUE;

   RTMCKS_vidInit();
   bLocalEmulCardChecked = DEVHAL_bCheckEmulCard();
   if (bLocalEmulCardChecked != 0)
   {
      KRN_bFirstCalibChecksumDone    = TRUE;
      KRN_vbFirstTmsCalibChecksumDone = TRUE;
      RTMCKS_vidAreaCheckDisable(GLOBAL_CKS, GLOBAL_CALIB);
      RTMCKS_vidAreaCheckDisable(TMS_CKS, TMS_CALIB);
   }
   else
   {
      KRN_bFirstCalibChecksumDone    = FALSE;
      KRN_vbFirstTmsCalibChecksumDone = FALSE;
   }

   while (  (KRN_vbFirstTmsSoftChecksumDone  == FALSE)
         || (KRN_vbFirstTmsCalibChecksumDone == FALSE))
   {
      RTMCKS_vidMainFunction(TMS_CKS);
      Wdg_vidRefreshWatchdog();
   }
}


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

/******************************************************************************/
/* !Description : Notification of the software checksum calculation end       */
/* !Reference   : NONE                                                        */
/*                                                                            */
/* !LastAuthor  : E. Riad                                                     */
/******************************************************************************/
void KRN_vidCheckSoftChecksum(RTMCKS_tResult KRN_udtChecksum)
{
   KRN_bFirstSoftChecksumDone = TRUE;

   if ((uint16)KRN_udtChecksum != KRN_ku16SoftChecksum)
   {
      DGOHAL_vidWrite(DGOHAL_udtMMCDGN, DGOHAL_bfVALID_MMCDGN_CKS,
                      DGOHAL_bfFAULT_MMCDGN_CKS);
   }
   else
   {
      DGOHAL_vidWrite(DGOHAL_udtMMCDGN, DGOHAL_bfVALID_MMCDGN_CKS,
                      DGOHAL_bfNO_FAULT_MMCDGN_CKS);
   }
   KRN_u16SoftChecksum = (uint16)KRN_udtChecksum;
}

/******************************************************************************/
/* !Description : Notification of the calibration checksum calculation end    */
/* !Reference   : NONE                                                        */
/*                                                                            */
/* !LastAuthor  : E. Riad                                                     */
/******************************************************************************/
void KRN_vidCheckCalibChecksum(RTMCKS_tResult KRN_udtChecksum)
{
   KRN_bFirstCalibChecksumDone = TRUE;

   if ((uint16)KRN_udtChecksum != KRN_ku16CalibChecksum)
   {
      DGOHAL_vidWrite(DGOHAL_udtMMCDGN, DGOHAL_bfVALID_MMCDGN_CKS,
                      DGOHAL_bfFAULT_MMCDGN_CKS);
   }
   else
   {
      DGOHAL_vidWrite(DGOHAL_udtMMCDGN, DGOHAL_bfVALID_MMCDGN_CKS,
                      DGOHAL_bfNO_FAULT_MMCDGN_CKS);
   }
   KRN_u16CalibChecksum = (uint16)KRN_udtChecksum;
}

/******************************************************************************/
/* !Description : Notification of the TMS software checksum calculation end   */
/* !Reference   : NONE                                                        */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidTmsCheckSoftChecksum(RTMCKS_tResult KRN_udtTmsChecksum)
{
   if (KRN_vbFirstTmsSoftChecksumDone != FALSE)
   {
      if ((uint16)KRN_udtTmsChecksum != KRN_ku16TmsSoftChecksum)
      {
         DGOHAL_vidWrite(DGOHAL_udtTMS, DGOHAL_bfVALID_TMSDGN_CODE_CKS,
                         DGOHAL_bfFAULT_TMSDGN_CODE_CKS);
      }
      else
      {
         DGOHAL_vidWrite(DGOHAL_udtTMS, DGOHAL_bfVALID_TMSDGN_CODE_CKS,
                         DGOHAL_bfNO_FAULT_TMSDGN_CODE_CKS);
      }
      KRN_u16TmsSoftChecksum = (uint16)KRN_udtTmsChecksum;
   }
   else
   {
      KRN_vbFirstTmsSoftChecksumDone = TRUE;
      if ((uint16)KRN_udtTmsChecksum != KRN_ku16TmsSoftChecksum)
      {
         KRN_bInitTmsChecksumOK = FALSE;
      }
      KRN_u16InitTmsSoftChecksum = (uint16)KRN_udtTmsChecksum;
   }
}

/******************************************************************************/
/* !Description : Notification of the TMS calibration checksum calculation end*/
/* !Reference   : NONE                                                        */
/*                                                                            */
/* !LastAuthor  : L. Baglin                                                   */
/******************************************************************************/
void KRN_vidTmsCheckCalibChecksum(RTMCKS_tResult KRN_udtTmsChecksum)
{
   if (KRN_vbFirstTmsCalibChecksumDone != FALSE)
   {
      if ((uint16)KRN_udtTmsChecksum != KRN_ku16TmsCalibChecksum)
      {
         DGOHAL_vidWrite(DGOHAL_udtTMS, DGOHAL_bfVALID_TMSDGN_CALIB_CKS,
                         DGOHAL_bfFAULT_TMSDGN_CALIB_CKS);
      }
      else
      {
         DGOHAL_vidWrite(DGOHAL_udtTMS, DGOHAL_bfVALID_TMSDGN_CALIB_CKS,
                         DGOHAL_bfNO_FAULT_TMSDGN_CALIB_CKS);
      }
      KRN_u16TmsCalibChecksum = (uint16)KRN_udtTmsChecksum;
   }
   else
   {
      KRN_vbFirstTmsCalibChecksumDone = TRUE;
      if ((uint16)KRN_udtTmsChecksum != KRN_ku16TmsCalibChecksum)
      {
         KRN_bInitTmsChecksumOK = FALSE;
      }
      KRN_u16InitTmsCalibChecksum = (uint16)KRN_udtTmsChecksum;
   }
}

#define KRN_STOP_SEC_CODE
#include "KRN_MemMap.h"

/*------------------------------- end of file --------------------------------*/