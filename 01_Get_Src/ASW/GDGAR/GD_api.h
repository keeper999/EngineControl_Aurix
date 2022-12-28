/***************************************************************************
;**
;** FILE NAME      : GD_api.h
;**
;** FILE AUTHOR    : sbiet (VEMS)
;**
;**************************************************************************/

#ifndef GD_API_H
#define GD_API_H

#include "STD_TYPES.h"

/*-------------------------------------------------------------------------
    Prototypes
-------------------------------------------------------------------------*/

#define GD_vidBitWrite(u8Variable,u8BitToTreat,bValue)\
{\
   if(!bValue)\
   {\
      u8Variable = (uint8)(u8Variable & ~(0x01 << u8BitToTreat));\
   }\
   else\
   {\
      u8Variable = (uint8)(u8Variable | (0x01 << u8BitToTreat));\
   }\
}

#define GD_vidBitWrite_opt_mask(u8Variable,u8BitMask,bValue)\
{\
   if(!bValue)\
   {\
      u8Variable = (uint8)(u8Variable & ~(u8BitMask));\
   }\
   else\
   {\
      u8Variable = (uint8)(u8Variable | (u8BitMask));\
   }\
}


#define GD_vidBitWrite16(u16Variable,u8BitToTreat,bValue)\
{\
   if(!bValue)\
   {\
      u16Variable = (uint16)(u16Variable & ~(0x01 << u8BitToTreat));\
   }\
   else\
   {\
      u16Variable = (uint16)(u16Variable | (0x01 << u8BitToTreat));\
   }\
}

#define GD_vidBitWrite32(u32Variable,u8BitToTreat,bValue)\
{\
   if(!bValue)\
   {\
      u32Variable = (uint32)(u32Variable & ~(0x01 << u8BitToTreat));\
   }\
   else\
   {\
      u32Variable = (uint32)(u32Variable | (0x01 << u8BitToTreat));\
   }\
}

#define GD_bBitRead(u8Variable,u8BitToTreat) \
   (boolean)((u8Variable >> u8BitToTreat) & 0x01)


#define GD_bBitCheck_opt_mask(Variable,BitMask) \
   ((Variable ) & (BitMask))

#define GD_bBitRead16(u16Variable,u8BitToTreat)\
   (boolean)((u16Variable >> u8BitToTreat) & 0x01);


#define GD_bBitRead32(u32Variable,u8BitToTreat)\
   (boolean)((u32Variable >> u8BitToTreat) & 0x01);

#endif /* GD_API_H */

/*-------------------------------- end of file -------------------------------*/
