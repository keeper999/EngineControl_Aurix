/* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
/* 13/10/2014 16:01:16 */
/* File: ISFHCAN_Tx_Manager.c */
#include "ISFHCAN_Cfg.H"
#include "ISFHCAN_DEF.H"
#include "ISCANF072.H"
#include "ISCANF0E8.H"
#include "ISCANF108.H"
#include "ISCANF1E8.H"
#include "ISCANF208.H"
#include "ISCANF228.H"
#include "ISCANF2E8.H"
#include "ISCANF348.H"
#include "ISCANF388.H"
#include "ISCANF3B8.H"
#include "ISCANF3C8.H"
#include "ISCANF438.H"
#include "ISCANF468.H"
#include "ISCANF488.H"
#include "ISCANF588.H"
#include "ISCANF5F8.H"
#include "ISCANF608.H"
#include "ISCANF768.H"
#include "ISCANF788.H"
#include "ISCANF7A8.H"


uint16 au16TabCompteurTX[ISFHCAN_TX_NB]
   = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


ISFHCAN_tstrTxFrame ISFHCAN_pakTxFrame[ISFHCAN_TX_NB] = {
{10, 0, ISCAN_vidEve_Tx_RQD_CMM_BSI_072},
{1000, 0, ISCAN_vidEve_Tx_1E8},
{10, 5, ISCAN_vidEve_Tx_208},
{10, 0, ISCAN_vidEve_Tx_228},
{20, 5, ISCAN_vidEve_Tx_2E8},
{20, 15, ISCAN_vidEve_Tx_348},
{40, 0, ISCAN_vidEve_Tx_388},
{40, 15, ISCAN_vidEve_Tx_3B8},
{20, 5, ISCAN_vidEve_Tx_3C8},
{50, 20, ISCAN_vidEve_Tx_438},
{40, 5, ISCAN_vidEve_Tx_468},
{100, 10, ISCAN_vidEve_Tx_488},
{100, 5, ISCAN_vidEve_Tx_588},
{1000, 0, ISCAN_vidEve_Tx_5F8},
{100, 0, ISCAN_vidEve_Tx_608},
{1000, 0, ISCAN_vidEve_Tx_788},
{1000, 0, ISCAN_vidEve_Tx_7A8},
};

#define ISFHCAN_START_SEC_CODE
#include "ISFHCAN_MemMap.h"

void ISFHCAN_EveRst_IniPrm(void)
{
ISCAN_vidInit_Tx_072();
ISCAN_vidInit_Tx_0E8();
ISCAN_vidInit_Tx_108();
ISCAN_vidInit_Tx_1E8();
ISCAN_vidInit_Tx_208();
ISCAN_vidInit_Tx_228();
ISCAN_vidInit_Tx_2E8();
ISCAN_vidInit_Tx_348();
ISCAN_vidInit_Tx_388();
ISCAN_vidInit_Tx_3B8();
ISCAN_vidInit_Tx_3C8();
ISCAN_vidInit_Tx_438();
ISCAN_vidInit_Tx_468();
ISCAN_vidInit_Tx_488();
ISCAN_vidInit_Tx_588();
ISCAN_vidInit_Tx_5F8();
ISCAN_vidInit_Tx_608();
ISCAN_vidInit_Tx_768();
ISCAN_vidInit_Tx_788();
ISCAN_vidInit_Tx_7A8();
}


void ISFHCAN_vidTxManagerPrivate(void)
{
   uint32 u32LocalIndex;

   if (ISFHCAN_u8Inhib != 0x5A)
   {
        for (u32LocalIndex = 0 ; u32LocalIndex < ISFHCAN_TX_NB ; u32LocalIndex++)
        {
            if (ISFHCAN_pakTxFrame[u32LocalIndex].Freq > 0)
            {
               if (au16TabCompteurTX[u32LocalIndex] ==                   
                    ISFHCAN_pakTxFrame[u32LocalIndex].Offset)
               {
                  ISFHCAN_pakTxFrame[u32LocalIndex].pkfTxFrameAction();
               }

               au16TabCompteurTX[u32LocalIndex] += ISFHCAN_FREQ_PGCD_TX;
               if (au16TabCompteurTX[u32LocalIndex] >=
                   (ISFHCAN_pakTxFrame[u32LocalIndex].Freq))
               {
                  au16TabCompteurTX[u32LocalIndex] = 0;      
               }
            }
        }
   }
}

#define ISFHCAN_STOP_SEC_CODE
#include "ISFHCAN_MemMap.h"

/*-------------------------------- end of file -------------------------------*/
