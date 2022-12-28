
   /* Auto-Code from ISFHCAN_ut8.xml, project.xml and Adaptations.xml files */
   /* 13/10/2014 16:01:16 */
   /* File: ISFHCAN_CFG.H */
   

#ifndef _ISFHCAN_CFG_H_
#define _ISFHCAN_CFG_H_
#include "Std_Types.h"
#define ISFHCAN_TX_NB 17
#define ISFHCAN_FREQ_PGCD_TX 5

typedef struct
{
   const uint16 Freq;
   uint16 Offset;
   void (* const pkfTxFrameAction) (void);
} ISFHCAN_tstrTxFrame;

extern uint16 au16TabCompteurTX[ISFHCAN_TX_NB];
extern ISFHCAN_tstrTxFrame ISFHCAN_pakTxFrame[ISFHCAN_TX_NB];

#endif /* _ISFHCAN_CFG_H_ */