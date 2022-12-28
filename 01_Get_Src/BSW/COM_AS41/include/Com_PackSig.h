/* !Component: Com                                                           */
#ifndef COM_PACKSIG_H
#define COM_PACKSIG_H

#include "Com_LCfg.h"
#include "Com_Internal.h"


/* !Deviation: [3453]  the following functions like macros , helps to increase
  the readability of the code , by accessing the required configuration parameter
  , through a macro . Macros were used instead of functions in order to increase
  the code performance  by reducing the time required by the context switching*/
 /* PRQA S 3453 ++ */
 
#if (Com_bPB_VARIANT == STD_ON)
#define Com_pku8GET_IPDU_BUFF_PTR(u16IPduBufferIx) \
(&(Com_pkstreMainConfig->pu8IPduBuffer[(u16IPduBufferIx)]))
#else
#define Com_pku8GET_IPDU_BUFF_PTR(u16IPduBufferIx) \
(&(Com_au8IPduBuffer[(u16IPduBufferIx)]))
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define Com_u8GET_IPDU_DIR(u16IpduId) \
(Com_pkstreMainConfig->pkstrIPduLookUp[(u16IpduId)].u8Direction)
#else
#define Com_u8GET_IPDU_DIR(u16IpduId) \
(akstrIPduLookUp[(u16IpduId)].u8Direction)
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define Com_pku8GET_SIG_OBJ_VALUEU8(u16SigObjIx) \
	(&(Com_pkstreMainConfig->pu8SignalObjectU8U8N[(u16SigObjIx)]))
#else
#define Com_pku8GET_SIG_OBJ_VALUEU8(u16SigObjIx) \
		(&(Com_au8SignalObjectU8U8N[(u16SigObjIx)]))
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define Com_u16GET_SIGNAL_INDEX(u16SigId) \
		(Com_pkstreMainConfig->pkstrSignalLookUp[u16SigId].u16Index)
#else
#define Com_u16GET_SIGNAL_INDEX(u16SigId) \
	     (akstrSignalLookUp[(u16SigId)].u16Index)
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define Com_pkstrGET_PBSIGPTR_IX(u16SigIx) \
(&(Com_pkstreMainConfig->pkstrSignalPB[u16SigIx]))
#else
#define Com_pkstrGET_PBSIGPTR_IX(u16SigIx) \
(&(akstrSignalPB[u16SigIx]))
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define Com_pkstrGET_PBGRPSIGPTR_IX(u16SigIx) \
(&( Com_pkstreMainConfig->pkstrGroupSignalPB[(u16SigIx)]))
#else
#define Com_pkstrGET_PBGRPSIGPTR_IX(u16SigIx) \
(&(akstrGroupSignalPB[(u16SigIx)]))
#endif



#if (Com_bPB_VARIANT == STD_ON)
#define Com_pkstrGET_PBSRC_DESCPTR_IX(u16SigIx) \
(&( Com_pkstreMainConfig->pkstrGWSrcDesc[(u16SigIx)]))
#else
#if u16NO_OF_GW_SRC_DESC > 0u 
#define Com_pkstrGET_PBSRC_DESCPTR_IX(u16SigIx) \
(&(akstrGWSrcDesc[(u16SigIx)]))
#else
#define Com_pkstrGET_PBSRC_DESCPTR_IX(u16SigIx) NULL_PTR
#endif
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define Com_pkstrGET_PBDSTDESCPTR_IX(u16SigIx) \
(&( Com_pkstreMainConfig->pkstrGWDstDesc[(u16SigIx)]))
#else
#if u16NO_OF_GW_DST_DESC > 0u
#define Com_pkstrGET_PBDSTDESCPTR_IX(u16SigIx) \
(&(akstrGWDstDesc[(u16SigIx)]))
#else
#define Com_pkstrGET_PBDSTDESCPTR_IX(u16SigIx) NULL_PTR
#endif
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define Com_bGET_SIG_OBJ_VALUEB(u16SigObjIx) \
	(&(Com_pkstreMainConfig->pbSignalObjectB[(u16SigObjIx)]))
#else
#if u16NO_OF_SIG_B_OBJ > 0u
#define Com_bGET_SIG_OBJ_VALUEB(u16SigObjIx) \
		(&(Com_au8SignalObjectB[(u16SigObjIx)]))

#else
#define Com_bGET_SIG_OBJ_VALUEB(u16SigObjIx) NULL_PTR
#endif
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define Com_u8GET_SIG_OBJ_VALUEU8(u16SigObjIx) \
	(&(Com_pkstreMainConfig->pu8SignalObjectU8U8N[(u16SigObjIx)]))
#else
#if u16NO_OF_SIG_U8U8N_OBJ > 0u
#define Com_u8GET_SIG_OBJ_VALUEU8(u16SigObjIx) \
		(&(Com_au8SignalObjectU8U8N[(u16SigObjIx)]))

#else
#define Com_u8GET_SIG_OBJ_VALUEU8(u16SigObjIx) NULL_PTR
#endif
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define Com_s8GET_SIG_OBJ_VALUES8(u16SigObjIx) \
	(&(Com_pkstreMainConfig->ps8SignalObjectS8[(u16SigObjIx)]))
#else
#if u16NO_OF_SIG_S8_OBJ > 0u
#define Com_s8GET_SIG_OBJ_VALUES8(u16SigObjIx) \
		(&(Com_as8SignalObjectS8[(u16SigObjIx)]))
#else
#define Com_s8GET_SIG_OBJ_VALUES8(u16SigObjIx) NULL_PTR
#endif
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define Com_u16GET_SIG_OBJ_VALUEU16(u16SigObjIx) \
	(&(Com_pkstreMainConfig->pu16SignalObjectU16[(u16SigObjIx)]))
#else
#if u16NO_OF_SIG_U16_OBJ > 0u
#define Com_u16GET_SIG_OBJ_VALUEU16(u16SigObjIx) \
		(&(Com_au16SignalObjectU16[(u16SigObjIx)]))

#else
#define Com_u16GET_SIG_OBJ_VALUEU16(u16SigObjIx) NULL_PTR
#endif
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define Com_s16GET_SIG_OBJ_VALUES16(u16SigObjIx) \
	(&(Com_pkstreMainConfig->ps16SignalObjectS16[(u16SigObjIx)]))
#else
#if u16NO_OF_SIG_S16_OBJ > 0u
#define Com_s16GET_SIG_OBJ_VALUES16(u16SigObjIx) \
		(&(Com_as16SignalObjectS16[(u16SigObjIx)]))
#else
#define Com_s16GET_SIG_OBJ_VALUES16(u16SigObjIx) NULL_PTR
#endif
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define Com_u32GET_SIG_OBJ_VALUEU32(u16SigObjIx) \
	(&(Com_pkstreMainConfig->pu32SignalObjectU32[(u16SigObjIx)]))
#else
#if u16NO_OF_SIG_U32_OBJ > 0u
#define Com_u32GET_SIG_OBJ_VALUEU32(u16SigObjIx) \
		(&(Com_au32SignalObjectU32[(u16SigObjIx)]))
#else
#define Com_u32GET_SIG_OBJ_VALUEU32(u16SigObjIx) NULL_PTR
#endif
#endif


#if (Com_bPB_VARIANT == STD_ON)
#define Com_s32GET_SIG_OBJ_VALUES32(u16SigObjIx) \
	(&(Com_pkstreMainConfig->ps32SignalObjectS32[(u16SigObjIx)]))
#else
#if u16NO_OF_SIG_S32_OBJ > 0u
#define Com_s32GET_SIG_OBJ_VALUES32(u16SigObjIx) \
		(&(Com_as32SignalObjectS32[(u16SigObjIx)]))
#else
#define Com_s32GET_SIG_OBJ_VALUES32(u16SigObjIx) NULL_PTR
#endif
#endif



#if (Com_bPB_VARIANT == STD_ON)
#define Com_f32GET_SIG_OBJ_VALUEF32(u16SigObjIx) \
	(&(Com_pkstreMainConfig->pf32SignalObjectF32[(u16SigObjIx)]))
#else
#if u16NO_OF_SIG_F32_OBJ > 0u
#define Com_f32GET_SIG_OBJ_VALUEF32(u16SigObjIx) \
		(&(Com_af32SignalObjectF32[(u16SigObjIx)]))

#else
#define Com_f32GET_SIG_OBJ_VALUEF32(u16SigObjIx) NULL_PTR
#endif
#endif



#if (Com_bPB_VARIANT == STD_ON)
#define Com_f64GET_SIG_OBJ_VALUEF64(u16SigObjIx) \
	(&(Com_pkstreMainConfig->pf64SignalObjectF64[(u16SigObjIx)]))
#else
#if u16NO_OF_SIG_F64_OBJ > 0u
#define Com_f64GET_SIG_OBJ_VALUEF64(u16SigObjIx) \
		(&(Com_af64SignalObjectF64[(u16SigObjIx)]))


#else
#define Com_f64GET_SIG_OBJ_VALUEF64(u16SigObjIx) NULL_PTR
#endif
#endif




#if (Com_bPB_VARIANT == STD_ON)
#define Com_u32GET_TX_IPDU_BUFF_IX(u16IpduId) \
(Com_pkstreMainConfig->pkstrTxIPdu[(Com_pkstreMainConfig->pkstrIPduLookUp[\
(u16IpduId)].u16Index)].u32IPduBufferIndex)

#else
#define Com_u32GET_TX_IPDU_BUFF_IX(u16IpduId) \
(akstrTxIPdu[(akstrIPduLookUp[\
(u16IpduId)].u16Index)].u32IPduBufferIndex)
#endif

#if (Com_bPB_VARIANT == STD_ON)
#define Com_u32GET_RX_IPDU_BUFF_IX(u16IpduId) \
(Com_pkstreMainConfig->pkstrRxIPdu[(Com_pkstreMainConfig->pkstrIPduLookUp[\
(u16IpduId)].u16Index)].u32IPduBufferIndex)

#else
#define Com_u32GET_RX_IPDU_BUFF_IX(u16IpduId) \
(akstrRxIPdu[(akstrIPduLookUp[\
(u16IpduId)].u16Index)].u32IPduBufferIndex)
#endif

/* PRQA S 3453 -- */

/* PRQA S 3459,3410,3412 ++ */
#define Com_vidCPY2_IPDU_BOOL_BUFF(bVal,u16StartByteNumber,u8StartBitPosition,\
          u8RemainingSigBits,u32IpduRamBufferIndex)\
do{\
	P2VAR(uint8,AUTOMATIC,TYPEDEF) pu8IPduBuf;\
	(u32IpduRamBufferIndex) +=(uint32)(u16StartByteNumber) ;\
	pu8IPduBuf = Com_pku8GET_IPDU_BUFF_PTR(0);\
   if (u8StartBitPosition != 0)\
   {\
     if(bVal != FALSE)\
     {\
       SchM_Enter_Com_IPduBuff();\
       pu8IPduBuf[u32IpduRamBufferIndex] |= \
         (uint8)(((uint8)0xFFu >> ((uint8)8u -(u8RemainingSigBits)))<<(u8StartBitPosition));\
       SchM_Exit_Com_IPduBuff();\
     }\
     else\
     {\
       SchM_Enter_Com_IPduBuff();\
       pu8IPduBuf[u32IpduRamBufferIndex] &= \
         ((uint8)(((uint8)0xFFu >> ((uint8)8u -(u8RemainingSigBits)))<<(u8StartBitPosition))^(uint8)0xFFu);\
       SchM_Exit_Com_IPduBuff();\
     }\
   }\
   else\
   {\
     if(bVal != FALSE)\
     {\
       SchM_Enter_Com_IPduBuff();\
       pu8IPduBuf[u32IpduRamBufferIndex] |= (uint8)0x01u;\
       SchM_Exit_Com_IPduBuff();\
     }\
     else\
     {\
       SchM_Enter_Com_IPduBuff();\
       pu8IPduBuf[u32IpduRamBufferIndex] &= ((uint8)0x01u^(uint8)0xFFu);\
       SchM_Exit_Com_IPduBuff();\
     }   \
   }\
}while(0)


#define Com_vidCPY2_IPDU_8BIT_BUFF(u8Val,u16StartByteNumber,u8StartBitPosition,\
          u8RemainingSigBits,u8SignalEndianess,u32IpduRamBufferIndex)\
do{\
   uint16 u16Mask = 0xFFFFU;\
   uint16 u16TempVal;\
   uint8 u8Mask = 0xFFU;\
   uint8 u8TempVal;\
   P2VAR(uint8,AUTOMATIC,TYPEDEF) pu8IPduBuf;\
   (u32IpduRamBufferIndex) +=(uint32)(u16StartByteNumber) ;\
   pu8IPduBuf = Com_pku8GET_IPDU_BUFF_PTR(0);\
   if (u8StartBitPosition != 0)\
   {\
      if (u8StartBitPosition + u8RemainingSigBits > 8U)\
      {\
         u16Mask = (uint16) (u16Mask >> (16U - u8RemainingSigBits));\
         u16Mask = (uint16) (u16Mask << u8StartBitPosition);\
         u16TempVal = (uint16)(((uint16)u8Val) << u8StartBitPosition);\
         u16TempVal = (uint16)(u16TempVal & u16Mask);\
         SchM_Enter_Com_IPduBuff();\
         pu8IPduBuf[u32IpduRamBufferIndex] =\
           (uint8)((uint8) (pu8IPduBuf[u32IpduRamBufferIndex] & (uint8) (~u16Mask)) | ((uint8) (u16TempVal & 0xFFU)));\
         SchM_Exit_Com_IPduBuff();\
         u16TempVal = u16TempVal >> 8U;\
	       u16Mask = u16Mask >> 8U;\
         if (u8SignalEndianess==Com_u8ENDIANESS_BIG)\
         {\
	        u32IpduRamBufferIndex--;\
         }\
         else\
         {\
	        u32IpduRamBufferIndex++;\
         }\
         SchM_Enter_Com_IPduBuff();\
         pu8IPduBuf[u32IpduRamBufferIndex] =\
           (uint8)((uint8) (pu8IPduBuf[u32IpduRamBufferIndex] & (uint8) (~u16Mask)) | ((uint8) (u16TempVal & 0xFFU)));\
         SchM_Exit_Com_IPduBuff();\
	    }\
	    else\
	    {\
		 u8Mask = (uint8) (u8Mask >> (8U - u8RemainingSigBits));\
         u8Mask = (uint8) (u8Mask << u8StartBitPosition);\
         u8TempVal = (uint8)(u8Val << u8StartBitPosition);\
         u8TempVal = (uint8)(u8TempVal & u8Mask);\
         SchM_Enter_Com_IPduBuff();\
         pu8IPduBuf[u32IpduRamBufferIndex] =\
           (uint8)((uint8) (pu8IPduBuf[u32IpduRamBufferIndex] & (uint8) (~u8Mask)) | u8TempVal);\
         SchM_Exit_Com_IPduBuff();\
	    }\
	}\
	else\
	{\
     u8Mask = (uint8) (u8Mask >> (8U - u8RemainingSigBits));\
     u8TempVal = u8Val;\
     u8TempVal = (uint8)(u8TempVal & u8Mask);\
     SchM_Enter_Com_IPduBuff();\
     pu8IPduBuf[u32IpduRamBufferIndex] =\
       (uint8)((uint8) (pu8IPduBuf[u32IpduRamBufferIndex] & (uint8) (~u8Mask)) | u8TempVal);\
     SchM_Exit_Com_IPduBuff();\
	}\
}while(0)

#define Com_vidCPY2_IPDU_16BIT_BUFF(u16Val,u16StartByteNumber,u8StartBitPosition,\
          u8RemainingSigBits,u8SignalEndianess,u32IpduRamBufferIndex)\
do{\
   uint32 u32Mask = 0xFFFFFFFFUL;\
   uint32 u32TempVal;\
   uint16 u16Mask = 0xFFFFU;\
   uint16 u16TempVal;\
   sint8 s8Step;\
    P2VAR(uint8,AUTOMATIC,TYPEDEF) pu8IPduBuf;\
	pu8IPduBuf = Com_pku8GET_IPDU_BUFF_PTR(0);\
   (u32IpduRamBufferIndex) +=(uint32)(u16StartByteNumber) ;\
   if (u8SignalEndianess == Com_u8ENDIANESS_BIG)\
   {          \
	  s8Step = -1;\
   }\
   else\
   {\
	  s8Step = 1;\
   }\
   if (u8StartBitPosition != 0)\
   {\
      if (u8StartBitPosition + u8RemainingSigBits > 16U)\
      {\
         u32Mask = (uint32) (u32Mask >> (32U - u8RemainingSigBits));\
         u32Mask = (uint32) (u32Mask << u8StartBitPosition);\
         u32TempVal = (uint32)(((uint32)u16Val) << u8StartBitPosition);\
         u32TempVal = (uint32)(u32TempVal & u32Mask);\
         SchM_Enter_Com_IPduBuff();\
         pu8IPduBuf[u32IpduRamBufferIndex] =\
           (uint8)((uint8) (pu8IPduBuf[u32IpduRamBufferIndex] & (uint8) (~u32Mask)) | ((uint8) (u32TempVal & 0xFFU)));\
         SchM_Exit_Com_IPduBuff();  \
         u32TempVal = (uint32)(u32TempVal >> 8U);\
	       u32Mask = (uint32)(u32Mask >> 8U);\
         u32IpduRamBufferIndex = (uint32)(u32IpduRamBufferIndex + s8Step);\
         SchM_Enter_Com_IPduBuff();\
         pu8IPduBuf[u32IpduRamBufferIndex] =\
           (uint8)((uint8) (pu8IPduBuf[u32IpduRamBufferIndex] & (uint8) (~u32Mask)) | ((uint8) (u32TempVal & 0xFFU)));\
         SchM_Exit_Com_IPduBuff();\
         u32TempVal = (uint32)(u32TempVal >> 8U);\
	       u32Mask = (uint32)(u32Mask >> 8U);\
         u32IpduRamBufferIndex = (uint32)(u32IpduRamBufferIndex + s8Step);\
         SchM_Enter_Com_IPduBuff();\
         pu8IPduBuf[u32IpduRamBufferIndex] =\
           (uint8)((uint8) (pu8IPduBuf[u32IpduRamBufferIndex] & (uint8) (~u32Mask)) | ((uint8) (u32TempVal & 0xFFU)));\
         SchM_Exit_Com_IPduBuff(); 		 \
	    }\
	    else\
	    {\
         u16Mask = (uint16) (u16Mask >> (16U - u8RemainingSigBits));\
         u16Mask = (uint16) (u16Mask << u8StartBitPosition);\
         u16TempVal = (uint16)(u16Val << u8StartBitPosition);\
         u16TempVal = (uint16)(u16TempVal & u16Mask);         \
         SchM_Enter_Com_IPduBuff();\
         pu8IPduBuf[u32IpduRamBufferIndex] =\
           (uint8)((uint8) (pu8IPduBuf[u32IpduRamBufferIndex] & (uint8) (~u16Mask)) | ((uint8) (u16TempVal & 0xFFU)));\
         SchM_Exit_Com_IPduBuff();\
         u16TempVal = (uint16)(u16TempVal >> 8U);\
	       u16Mask = (uint16)(u16Mask >> 8U);\
         u32IpduRamBufferIndex = (uint32)(u32IpduRamBufferIndex + s8Step);		 \
         SchM_Enter_Com_IPduBuff();\
         pu8IPduBuf[u32IpduRamBufferIndex] =\
           (uint8)( ((uint8) (pu8IPduBuf[u32IpduRamBufferIndex] & (uint8) (~u16Mask))) | ((uint8) (u16TempVal & 0xFFU)));\
         SchM_Exit_Com_IPduBuff(); 		 \
	    }	  \
	}\
	else\
	{\
     u16Mask = (uint16) (u16Mask >> (16U - u8RemainingSigBits));\
     u16TempVal = u16Val;\
     u16TempVal = (uint16)(u16TempVal & u16Mask);     \
	 SchM_Enter_Com_IPduBuff();\
	 pu8IPduBuf[u32IpduRamBufferIndex] =\
	   (uint8)( (uint8) (pu8IPduBuf[u32IpduRamBufferIndex] & (uint8) (~u16Mask)) | ((uint8) (u16TempVal & 0xFFU)) );\
	 SchM_Exit_Com_IPduBuff();\
	 u16TempVal = (uint16)(u16TempVal >> 8U);\
	 u16Mask = (uint16)(u16Mask >> 8U);\
   u32IpduRamBufferIndex = (uint32)(u32IpduRamBufferIndex + s8Step);	 \
	 SchM_Enter_Com_IPduBuff();\
	 pu8IPduBuf[u32IpduRamBufferIndex] =\
	   (uint8)( (uint8) (pu8IPduBuf[u32IpduRamBufferIndex] & (uint8) (~u16Mask)) | ((uint8) (u16TempVal & 0xFFU)) );\
	 SchM_Exit_Com_IPduBuff();\
	}\
}while(0)

#define Com_vidCPY2_IPDU_32BIT_BUFF(u32Val,u16StartByteNumber,u8StartBitPosition,\
          u8SigBitsSize,u8SignalEndianess,u32IpduRamBufferIndex)\
do{\
   uint32 u32Mask;\
   uint32 u32TempVal;\
   uint8_least u8LoopIdx;\
   uint8 u8RemSigBits;\
   sint8 s8Step;\
   uint16 u16Mask;\
   uint16 u16TempVal;\
   uint16 u16Val = (uint16)((u32Val)&0xFFFFU);\
   boolean bIsSigSize2Bytes;\
	P2VAR(uint8,AUTOMATIC,TYPEDEF) pu8IPduBuf;  \
	if((u8SigBitsSize) < 17U)\
	{\
		bIsSigSize2Bytes = TRUE;\
		u8RemSigBits = u8SigBitsSize;\
	}\
	else\
	{\
		bIsSigSize2Bytes = FALSE;\
			u8RemSigBits = 16U;\
	}\
   (u32IpduRamBufferIndex) +=(uint32)(u16StartByteNumber) ;\
   if (u8SignalEndianess == Com_u8ENDIANESS_BIG)\
   {          \
	   s8Step = -1;\
   }\
   else\
   {\
	   s8Step = 1;\
   }\
	pu8IPduBuf = Com_pku8GET_IPDU_BUFF_PTR(0);\
   if (u8StartBitPosition != 0)\
   {  	  \
      for(u8LoopIdx=0U; u8LoopIdx<2U; u8LoopIdx++)\
	    {	  \
		    if (u8StartBitPosition + u8RemSigBits > 16U)\
		    {\
               u32Mask = 0xFFFFFFFFUL;\
			   u32Mask = (uint32) (u32Mask >> (32U - u8RemSigBits));\
			   u32Mask = (uint32) (u32Mask << u8StartBitPosition);\
			   u32TempVal = (uint32)(((uint32)u16Val) << u8StartBitPosition);\
			   u32TempVal = (uint32)(u32TempVal & u32Mask);\
			   SchM_Enter_Com_IPduBuff();\
			   pu8IPduBuf[u32IpduRamBufferIndex] =\
			     (uint8)((uint8) (pu8IPduBuf[u32IpduRamBufferIndex] & (uint8) (~u32Mask)) | ((uint8) (u32TempVal & 0xFFU)));\
			   SchM_Exit_Com_IPduBuff();  \
			   u32TempVal = (uint32)(u32TempVal >> 8U);\
				  u32Mask = (uint32)(u32Mask >> 8U);           \
			   u32IpduRamBufferIndex = (uint32)(u32IpduRamBufferIndex + s8Step);\
			   SchM_Enter_Com_IPduBuff();\
			   pu8IPduBuf[u32IpduRamBufferIndex] =\
			     (uint8)( (uint8) (pu8IPduBuf[u32IpduRamBufferIndex] &\
                 (uint8) (~u32Mask)) | ((uint8) (u32TempVal & 0xFFU)) );\
			   SchM_Exit_Com_IPduBuff();\
			   u32TempVal = (uint32)(u32TempVal >> 8U);\
			     u32Mask = (uint32)(u32Mask >> 8U);\
			   u32IpduRamBufferIndex = (uint32)(u32IpduRamBufferIndex + s8Step);\
			   SchM_Enter_Com_IPduBuff();\
			   pu8IPduBuf[u32IpduRamBufferIndex] =\
			     (uint8)((uint8) (pu8IPduBuf[u32IpduRamBufferIndex] & (uint8) (~u32Mask)) | ((uint8) (u32TempVal & 0xFFU)));\
			   SchM_Exit_Com_IPduBuff();\
         }\
			  else\
			  {\
			   u16Mask = 0xFFFFU;\
			   u16Mask = (uint16) (u16Mask >> (16U - u8RemSigBits));\
			   u16Mask = (uint16) (u16Mask << u8StartBitPosition);\
			   u16TempVal = (uint16)(u16Val << u8StartBitPosition);\
			   u16TempVal = (uint16)(u16TempVal & u16Mask);  			 \
			   SchM_Enter_Com_IPduBuff();\
			   pu8IPduBuf[u32IpduRamBufferIndex] =\
			     (uint8)((uint8) (pu8IPduBuf[u32IpduRamBufferIndex] & (uint8) (~u16Mask)) | ((uint8) (u16TempVal & 0xFFU)));\
			   SchM_Exit_Com_IPduBuff();\
			   u16TempVal = (uint16)(u16TempVal >> 8U);\
			   u16Mask = (uint16)(u16Mask >> 8U);  			 \
			   u32IpduRamBufferIndex = (uint32)(u32IpduRamBufferIndex + s8Step);  			 \
			   SchM_Enter_Com_IPduBuff();\
			   pu8IPduBuf[u32IpduRamBufferIndex] =\
			     (uint8)( ((uint8) (pu8IPduBuf[u32IpduRamBufferIndex] & (uint8) (~u16Mask))) | ((uint8) (u16TempVal & 0xFFU)));\
			   SchM_Exit_Com_IPduBuff();  			 \
			   u32IpduRamBufferIndex = (uint32)(u32IpduRamBufferIndex + s8Step);				 \
			  }  			\
			  if(bIsSigSize2Bytes == TRUE)\
			  {\
				  break;\
			  }\
			  else\
			  {			   \
			   u16Val = (uint16)(((uint32)(u32Val >> 16U))&0xFFFFU);\
			   u8RemSigBits = u8SigBitsSize - 16U;			 \
			  }\
		}\
	}\
	else\
	{\
	 u32Mask = 0xFFFFFFFFUL;\
   u32Mask = (uint32) (u32Mask >> (32U - u8SigBitsSize));\
   u32TempVal = (uint32)(u32Val & u32Mask);   \
	 SchM_Enter_Com_IPduBuff();\
	 pu8IPduBuf[u32IpduRamBufferIndex] =\
	   (uint8)( (uint8) (pu8IPduBuf[u32IpduRamBufferIndex] & (uint8) (~u32Mask)) | ((uint8) (u32TempVal & 0xFFU)) );\
	 SchM_Exit_Com_IPduBuff();\
	 u32TempVal = (uint32)(u32TempVal >> 8U);\
	 u32Mask = (uint32)(u32Mask >> 8U);\
	 u32IpduRamBufferIndex = (uint32)(u32IpduRamBufferIndex + s8Step);	 \
	 SchM_Enter_Com_IPduBuff();\
	 pu8IPduBuf[u32IpduRamBufferIndex] =\
	   (uint8)( (uint8) (pu8IPduBuf[u32IpduRamBufferIndex] & (uint8) (~u32Mask)) | ((uint8) (u32TempVal & 0xFFU)) );\
	 SchM_Exit_Com_IPduBuff();\
	 u32TempVal = (uint32)(u32TempVal >> 8U);\
	 u32Mask = (uint32)(u32Mask >> 8U);\
	 u32IpduRamBufferIndex = (uint32)(u32IpduRamBufferIndex + s8Step);	 \
	 SchM_Enter_Com_IPduBuff();\
	 pu8IPduBuf[u32IpduRamBufferIndex] =\
	   (uint8)( (uint8) (pu8IPduBuf[u32IpduRamBufferIndex] & (uint8) (~u32Mask)) | ((uint8) (u32TempVal & 0xFFU)) );\
	 SchM_Exit_Com_IPduBuff();	 \
	 u32TempVal = (uint32)(u32TempVal >> 8U);\
	 u32Mask = (uint32)(u32Mask >> 8U);\
	 u32IpduRamBufferIndex = (uint32)(u32IpduRamBufferIndex + s8Step);\
	 SchM_Enter_Com_IPduBuff();\
	 pu8IPduBuf[u32IpduRamBufferIndex] =\
	   (uint8)( (uint8) (pu8IPduBuf[u32IpduRamBufferIndex] & (uint8) (~u32Mask)) | ((uint8) (u32TempVal & 0xFFU)) );\
	 SchM_Exit_Com_IPduBuff();	 \
	}\
}while(0)

#define Com_vidCPY2_IPDU_F32_BUFF(u32Val,u16StartByteNumber,u8StartBitPosition,\
          u8SignalEndianess,u32IpduRamBufferIndex)\
do{\
   uint32 u32Mask;\
   uint32 u32TempVal;   \
   uint8_least u8LoopIdx;\
   sint8 s8Step;\
   P2VAR(uint8,AUTOMATIC,TYPEDEF) pu8IPduBuf;\
   uint16 u16Val = (uint16)((u32Val)&0xFFFFU);\
   u32IpduRamBufferIndex +=(uint32)u16StartByteNumber ;\
   if (u8SignalEndianess == Com_u8ENDIANESS_BIG)\
   {          \
	   s8Step = -1;\
   }\
   else\
   {\
	   s8Step = 1;\
   }	\
   pu8IPduBuf = Com_pku8GET_IPDU_BUFF_PTR(0);\
   if (u8StartBitPosition != 0)\
   {    \
      for(u8LoopIdx=0U; u8LoopIdx<2U; u8LoopIdx++)\
	    {	  \
               u32Mask = (uint32)0xFFFFL;\
			   u32Mask = (uint32) (u32Mask << u8StartBitPosition);\
			   u32TempVal = (uint32)(((uint32)u16Val) << u8StartBitPosition);\
			   u32TempVal = (uint32)(u32TempVal & u32Mask);\
			   SchM_Enter_Com_IPduBuff();\
			   pu8IPduBuf[u32IpduRamBufferIndex] =\
			     (uint8)((uint8) (pu8IPduBuf[u32IpduRamBufferIndex] &\
				 (uint8) (~u32Mask)) | ((uint8) (u32TempVal & 0xFFU)));\
			   SchM_Exit_Com_IPduBuff();  \
			   u32TempVal = (uint32)(u32TempVal >> 8U);\
			   u32Mask = (uint32)(u32Mask >> 8U);           \
			   u32IpduRamBufferIndex = (uint32)(u32IpduRamBufferIndex + s8Step);\
			   SchM_Enter_Com_IPduBuff();\
			   pu8IPduBuf[u32IpduRamBufferIndex] =\
			     (uint8)( (uint8) (pu8IPduBuf[u32IpduRamBufferIndex] &\
                 (uint8) (~u32Mask)) | ((uint8) (u32TempVal & 0xFFU)) );\
			   SchM_Exit_Com_IPduBuff();  			 \
			   u32TempVal = (uint32)(u32TempVal >> 8U);\
			   u32Mask = (uint32)(u32Mask >> 8U);\
			   u32IpduRamBufferIndex = (uint32)(u32IpduRamBufferIndex + s8Step);\
			   SchM_Enter_Com_IPduBuff();\
			   pu8IPduBuf[u32IpduRamBufferIndex] =\
			     (uint8)((uint8) (pu8IPduBuf[u32IpduRamBufferIndex] & (uint8) (~u32Mask)) | ((uint8) (u32TempVal & 0xFFU)));\
			   SchM_Exit_Com_IPduBuff();  			\
			   u16Val = (uint16)(((uint32)(u32Val >> 16U))&0xFFFFU);	 \
		}\
	}\
	else\
	{\
    u32TempVal = u32Val;\
	 SchM_Enter_Com_IPduBuff();\
	 pu8IPduBuf[u32IpduRamBufferIndex] = (uint8) (u32TempVal & 0xFFU);\
	 SchM_Exit_Com_IPduBuff();\
	 u32TempVal = (uint32)(u32TempVal >> 8U);\
	 u32IpduRamBufferIndex = (uint32)(u32IpduRamBufferIndex + s8Step);	 \
	 SchM_Enter_Com_IPduBuff();\
	 pu8IPduBuf[u32IpduRamBufferIndex] = (uint8) (u32TempVal & 0xFFU);\
	 SchM_Exit_Com_IPduBuff();	 \
	 u32TempVal = (uint32)(u32TempVal >> 8U);\
	 u32IpduRamBufferIndex = (uint32)(u32IpduRamBufferIndex + s8Step);	 \
	 SchM_Enter_Com_IPduBuff();\
	 pu8IPduBuf[u32IpduRamBufferIndex] = (uint8) (u32TempVal & 0xFFU);\
	 SchM_Exit_Com_IPduBuff();	\
	 u32TempVal = (uint32)(u32TempVal >> 8U);\
	 u32IpduRamBufferIndex = (uint32)(u32IpduRamBufferIndex + s8Step);\
	 SchM_Enter_Com_IPduBuff();\
	 pu8IPduBuf[u32IpduRamBufferIndex] = (uint8) (u32TempVal & 0xFFU);\
	 SchM_Exit_Com_IPduBuff();	 \
	}\
}while(0)

#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
#define Com_vidCPY2_IPDU_F64_BUFF(pu8Val,u16StartByteNumber,u8StartBitPosition,\
          u8SignalEndianess,u32IpduRamBufferIndex)\
do{\
   uint32 u32Mask;\
   uint32 u32TempVal;   \
   uint8_least u8LoopIdx;\
   sint8 s8Step;\
   uint16 au16ValArr[4U];   \
	P2VAR(uint8,AUTOMATIC,TYPEDEF) pu8IPduBuf;\
   u32IpduRamBufferIndex +=(uint32)(u16StartByteNumber);   \
   if (u8SignalEndianess == Com_u8ENDIANESS_BIG)\
   {          \
	   s8Step = -1;\
   }\
   else\
   {\
	   s8Step = 1;\
   }\
	pu8IPduBuf = Com_pku8GET_IPDU_BUFF_PTR(0);\
   if (u8StartBitPosition != 0)\
   {\
	   au16ValArr [3U] = (uint16)((uint16)(pu8Val)[0U]<<8) + (uint16)(pu8Val)[1U];\
	   au16ValArr [2U] = (uint16)((uint16)(pu8Val)[2U]<<8) + (uint16)(pu8Val)[3U];   \
	   au16ValArr [1U] = (uint16)((uint16)(pu8Val)[4U]<<8) + (uint16)(pu8Val)[5U];  \
	   au16ValArr [0U] = (uint16)((uint16)(pu8Val)[6U]<<8) + (uint16)(pu8Val)[7U];	   \
		for(u8LoopIdx=0U; u8LoopIdx<4U; u8LoopIdx++)\
	    {	  \
		   u32Mask = (uint32)0xFFFFL;		   \
		   u32Mask = (uint32) (u32Mask << u8StartBitPosition);\
		   u32TempVal = (uint32)(((uint32)au16ValArr[u8LoopIdx]) << u8StartBitPosition);\
		   u32TempVal = (uint32)(u32TempVal & u32Mask);\
		   SchM_Enter_Com_IPduBuff();\
		   pu8IPduBuf[u32IpduRamBufferIndex] =\
			 (uint8)((uint8) (pu8IPduBuf[u32IpduRamBufferIndex] &\
			 (uint8) (~u32Mask)) | ((uint8) (u32TempVal & 0xFFU)));\
		   SchM_Exit_Com_IPduBuff();  \
		   u32TempVal = (uint32)(u32TempVal >> 8U);\
		   u32Mask = (uint32)(u32Mask >> 8U);	   \
		   u32IpduRamBufferIndex = (uint32)(u32IpduRamBufferIndex + s8Step);\
		   SchM_Enter_Com_IPduBuff();\
		   pu8IPduBuf[u32IpduRamBufferIndex] =\
			 (uint8)( (uint8) (pu8IPduBuf[u32IpduRamBufferIndex] &\
			 (uint8) (~u32Mask)) | ((uint8) (u32TempVal & 0xFFU)) );\
		   SchM_Exit_Com_IPduBuff();\
		   u32TempVal = (uint32)(u32TempVal >> 8U);\
		   u32Mask = (uint32)(u32Mask >> 8U);\
		   u32IpduRamBufferIndex = (uint32)(u32IpduRamBufferIndex + s8Step);\
		   SchM_Enter_Com_IPduBuff();\
		   pu8IPduBuf[u32IpduRamBufferIndex] =\
			 (uint8)((uint8) (pu8IPduBuf[u32IpduRamBufferIndex] & (uint8) (~u32Mask)) | ((uint8) (u32TempVal & 0xFFU)));\
		   SchM_Exit_Com_IPduBuff();						   	 \
		}\
	}\
	else\
	{\
	  for(u8LoopIdx=8U; u8LoopIdx>0U; u8LoopIdx--)\
	  {\
	  SchM_Enter_Com_IPduBuff();	  \
	  pu8IPduBuf[u32IpduRamBufferIndex] = (pu8Val)[u8LoopIdx-1];\
	  SchM_Exit_Com_IPduBuff();		\
	  u32IpduRamBufferIndex = (uint32)(u32IpduRamBufferIndex + s8Step);	\
	  }\
	}\
}while(0)

#else
#define Com_vidCPY2_IPDU_F64_BUFF(pu8Val,u16StartByteNumber,u8StartBitPosition,\
          u8SignalEndianess,u32IpduRamBufferIndex)\
do{\
   uint32 u32Mask;\
   uint32 u32TempVal;   \
   uint8_least u8LoopIdx;\
   sint8 s8Step;\
   uint16 au16ValArr[4U];   \
	P2VAR(uint8,AUTOMATIC,TYPEDEF) pu8IPduBuf;\
   u32IpduRamBufferIndex +=(uint32)u16StartByteNumber; \
   if (u8SignalEndianess == Com_u8ENDIANESS_BIG)\
   {          \
	   s8Step = -1;\
   }\
   else\
   {\
	   s8Step = 1;\
   }\
	pu8IPduBuf = Com_pku8GET_IPDU_BUFF_PTR(0);\
   if (u8StartBitPosition != 0)\
   {   \
		au16ValArr [0U] = (uint16)((uint16)(pu8Val)[1U]<<8) + (uint16)(pu8Val)[0U];\
		au16ValArr [1U] = (uint16)((uint16)(pu8Val)[3U]<<8) + (uint16)(pu8Val)[2U];   \
		au16ValArr [2U] = (uint16)((uint16)(pu8Val)[5U]<<8) + (uint16)(pu8Val)[4U];  \
		au16ValArr [3U] = (uint16)((uint16)(pu8Val)[7U]<<8) + (uint16)(pu8Val)[6U];\
		for(u8LoopIdx=0U; u8LoopIdx<4U; u8LoopIdx++)\
	    {	  \
		   u32Mask = (uint32)0xFFFFL;\
		   u32Mask = (uint32) (u32Mask << u8StartBitPosition);\
		   u32TempVal = (uint32)(((uint32)au16ValArr[u8LoopIdx]) << u8StartBitPosition);\
		   u32TempVal = (uint32)(u32TempVal & u32Mask);\
		   SchM_Enter_Com_IPduBuff();\
		   pu8IPduBuf[u32IpduRamBufferIndex] =\
			 (uint8)((uint8) (pu8IPduBuf[u32IpduRamBufferIndex] &\
			 (uint8) (~u32Mask)) | ((uint8) (u32TempVal & 0xFFU)));\
		   SchM_Exit_Com_IPduBuff();  \
		   u32TempVal = (uint32)(u32TempVal >> 8U);\
		   u32Mask = (uint32)(u32Mask >> 8U);	   \
		   u32IpduRamBufferIndex = (uint32)(u32IpduRamBufferIndex + s8Step);\
		   SchM_Enter_Com_IPduBuff();\
		   pu8IPduBuf[u32IpduRamBufferIndex] =\
			 (uint8)( (uint8) (pu8IPduBuf[u32IpduRamBufferIndex] &\
			 (uint8) (~u32Mask)) | ((uint8) (u32TempVal & 0xFFU)) );\
		   SchM_Exit_Com_IPduBuff();\
		   u32TempVal = (uint32)(u32TempVal >> 8U);\
		   u32Mask = (uint32)(u32Mask >> 8U);\
		   u32IpduRamBufferIndex = (uint32)(u32IpduRamBufferIndex + s8Step);\
		   SchM_Enter_Com_IPduBuff();\
		   pu8IPduBuf[u32IpduRamBufferIndex] =\
			 (uint8)((uint8) (pu8IPduBuf[u32IpduRamBufferIndex] & (uint8) (~u32Mask)) | ((uint8) (u32TempVal & 0xFFU)));\
		   SchM_Exit_Com_IPduBuff();						   	 \
		}\
	}\
	else\
	{\
	  for(u8LoopIdx=0U; u8LoopIdx<8U; u8LoopIdx++)\
	  {	  \
	  SchM_Enter_Com_IPduBuff();	  \
	  pu8IPduBuf[u32IpduRamBufferIndex] = (pu8Val)[u8LoopIdx];\
	  SchM_Exit_Com_IPduBuff();\
	  u32IpduRamBufferIndex = (uint32)(u32IpduRamBufferIndex + s8Step);	\
	  }\
	}\
}while(0)
#endif

/*this function will be used to unpack the array signal types */
/* i.e Com_u8SIGNAL_TYPE_UINT8N or Com_u8SIGNAL_TYPE_UINT8DYN */
/*! \Trace_To : */
#define Com_u8PACK_ARRAY_SIGNAL(u8SigType,u16SigObjIx,u16SigLen,u16StartBytePos,\
            u16DynSigMaxLen,pkvidSigDataPtr,pu8IpduFirstByte)\
do{\
  VAR(uint16_least,AUTOMATIC) u16LoopIx ;\
  VAR(uint16,AUTOMATIC) u16ObjStartByteIx ;    \
  P2VAR(uint8,AUTOMATIC,TYPEDEF) pu8SigObjU8U8N;  \
  switch (u8SigType)\
  {\
    case Com_u8SIGNAL_TYPE_UINT8N :\
      u16ObjStartByteIx =  (u16SigObjIx);\
    break;\
    case Com_u8SIGNAL_TYPE_UINT8DYN :      \
      u16ObjStartByteIx = ( ((u16SigObjIx) + Com_u8U8DYN_OBJ_IX_OFFSET +u16DynSigMaxLen) - u16SigLen) ;  \
    break; \
    default:\
      u16ObjStartByteIx = (uint16) 0;\
    break;\
  }  \
  pu8SigObjU8U8N = Com_pku8GET_SIG_OBJ_VALUEU8(0);\
  if ( \
  (pu8SigObjU8U8N != \
      (P2VAR(uint8,AUTOMATIC,COM_APPL_DATA)) NULL_PTR) &&     \
      ((pkvidSigDataPtr) !=( P2CONST(void,AUTOMATIC,COM_APPL_DATA) )NULL_PTR) &&\
      ((pu8IpduFirstByte) != (P2VAR(uint8,AUTOMATIC,COM_APPL_DATA)) NULL_PTR))\
  {    \
    SchM_Enter_Com_IPduBuff();\
    SchM_Enter_Com_SigObjU8U8N();    \
    for(u16LoopIx = (uint16)0 ; u16LoopIx < u16SigLen ; u16LoopIx++ )\
    {         \
       (pu8IpduFirstByte)[( u16StartBytePos + u16LoopIx ) ] = \
      ((P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)) (pkvidSigDataPtr))[u16LoopIx];\
      pu8SigObjU8U8N[(u16ObjStartByteIx + u16LoopIx)] = \
      ((P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))(pkvidSigDataPtr))[u16LoopIx];\
    }\
    SchM_Exit_Com_SigObjU8U8N();\
    SchM_Exit_Com_IPduBuff();\
    if (u8SigType == Com_u8SIGNAL_TYPE_UINT8DYN )\
    {      \
     SchM_Enter_Com_IPduBuff();\
     (pu8IpduFirstByte)[( u16StartBytePos + u16DynSigMaxLen ) ] = \
     (uint8)((uint16)( ( u16StartBytePos + u16SigLen ) & (uint16)0xFF00u )>>(uint16)8 ) ;\
     (pu8IpduFirstByte)[( u16StartBytePos + u16DynSigMaxLen + 1 ) ] = \
     (uint8)((uint16) ( u16StartBytePos + u16SigLen ) & (uint16)0x00FFu ); \
     SchM_Exit_Com_IPduBuff();\
    SchM_Enter_Com_SigObjU8U8N();	 \
	pu8SigObjU8U8N[u16SigObjIx] = \
	(uint8)((uint16) ( (u16SigLen ) & (uint16)0xFF00u )>>(uint16)8 ) ;\
	pu8SigObjU8U8N[u16SigObjIx +(uint16)1 ] = (uint8)(( u16SigLen ) & (uint16)0x00FFu );\
    SchM_Exit_Com_SigObjU8U8N();     \
    }\
  }\
}while(0)
/* !Deviation: [4700]  ( here has been an infringement of a threshold on the
specified metric)
The Com_vidSignalPackSignal function deviate the complexity threshold, but no
more division/simplification can be done
for performance issues*/
/* PRQA S 4700 ++ */

 /*This service performs endianess conversion-if exist- to signal/group signal,
 identified by SignalId then pack it into data structure to the I-PDU object .
 This service is used at the sender side only.
 N.B : The difference between Little endian and Big endian is as follow :
 if a memory location had the following structure at address [n] :
 [n]   [X]
 [n+1] [Y]
 [n+2] [Z]
 [n+3] [W]

 - a pointer always point to the low address
 In BIG ENDIAN system this will be read (*pu32)as     =>XYZW ,
 In LITTLE ENDIAN system this will be read (*pu32)as  =>WZYX

 */
/* !Deviation: [3205]  ( Some of the varaibles defined in the function  
are not used depending on the configuration.) */
/*PRQA S 3205 ++ */
#if(Com_u16NO_OF_SIGNAL > 0u)
#define Com_vidPACK_SIGNALS(u16SigIndex)\
case Com_u8SIG_STRUCT_SIG:\
	/*u16SigIndex = Com_u16GET_SIGNAL_INDEX(u16SigId);\*/\
    pkstrLclSigPB = Com_pkstrGET_PBSIGPTR_IX(u16SigIndex);\
    u8SigType =  pkstrLclSigPB->u8SignalType;\
   /*Set the u8RemainingSigBits to the signal size*/\
    u8RemainingSigBits = pkstrLclSigPB->u8BitSize;\
   /*Calculate the starting byte number inside the IPDU of this signal\
   StartingByteNumer = BitPosition / 8 */\
   u16StartByteNumber =  (pkstrLclSigPB->u16BitPosition)>>3;\
   /*Calculate the StartBitPosition Inside the NewByte\
    Start Bit Position Inside The New Byte = BitPosition % 8 */\
    /*range = 0..7 */\
	u8StartBitPosition = (uint8)(pkstrLclSigPB->u16BitPosition & (uint16) 7);\
    /*Get the Ipdu Id of the signal*/\
    u16IpduId = pkstrLclSigPB->u16IPduIndex ;\
    /*Get the signal endianess*/\
    u8SignalEndianess = (uint8)(pkstrLclSigPB->udteSignalFlags & Com_u8SIGNAL_ENDIANESS);\
    u16ArrSigByteLength = Com_akstreSignalLT[u16SigIndex].u16SignalLength;\
    u16SigObjIndex = pkstrLclSigPB->u16SignalObjectIndex;\
    break;
#else
#define Com_vidPACK_SIGNALS(u16SigId)
#endif

#if(Com_u16NO_OF_GROUP_SIGSLT > 0u)
#define Com_vidPACK_GROUP_SIGNALS(u16SigIndex) \
case Com_u8SIG_STRUCT_GROUPSIG:\
	/*u16SigIndex = Com_u16GET_SIGNAL_INDEX(u16SigId);\*/\
    pkstrLclGrpSigPB = Com_pkstrGET_PBGRPSIGPTR_IX(u16SigIndex);\
    u8SigType =  pkstrLclGrpSigPB->u8SignalType;\
   /*Set the u8RemainingSigBits to the signal size*/\
    u8RemainingSigBits = pkstrLclGrpSigPB->u8BitSize;\
   /*Calculate the starting byte number inside the IPDU of this signal\
   StartingByteNumer = BitPosition / 8 */\
   u16StartByteNumber =  (pkstrLclGrpSigPB->u16BitPosition)>>3;\
   /*Calculate the StartBitPosition Inside the NewByte\
    Start Bit Position Inside The New Byte = BitPosition % 8 */\
    /*range = 0..7 */\
	u8StartBitPosition = (uint8)(pkstrLclGrpSigPB->u16BitPosition & (uint16) 7);\
    /*Get the Ipdu Id of the signal*/\
    u16IpduId = pkstrLclGrpSigPB->u16IPduIndex ;\
    /*Get the signal endianess*/\
    u8SignalEndianess = (uint8)(pkstrLclGrpSigPB->udteGroupSignalFlags & Com_u8GRPSIGNAL_ENDIANESS);\
    u16ArrSigByteLength = Com_akstreGroupSignalLT[u16SigIndex].u16SignalLength;\
    u16SigObjIndex = pkstrLclGrpSigPB->u16SignalObjectIndex;\
    break;
#else
#define Com_vidPACK_GROUP_SIGNALS(u16SigId)
#endif

#if(Com_u16GW_SIG_LENGTH_SIZE > 0u)
#define Com_u16PACK_GW_SRC u16ArrSigByteLength=Com_aku16eGWSignalLength[pkstrLclSrcDscPB->u16LengthIndex];
#define Com_u16PACK_GW_DST u16ArrSigByteLength=Com_aku16eGWSignalLength[pkstrLclDstDscPB->u16LengthIndex];
#else
#define Com_u16PACK_GW_SRC
#define Com_u16PACK_GW_DST
#endif

#define Com_vidSignalPackSignal(u16SignalIx,pkvidSignalDataPtr,u8SigStructType,\
																u16DynLength)\
  do{\
   /*local variables declaration */\
/* !Deviation: [8018]  (The name of the constant (const) does not respect the\
naming conventions.) */\
/*[ 8318]  ( the Component ID of the constant (const) doesn't respect the naming\
 conventions.)*/\
/*[8518] (The Separator of the constant (const) doesn't respect the naming\
conventions.)*/\
/*Limitation in the current QAC check , the name is correct*/\
/*PRQA S 8018 , 8318, 8518  ++ */\
  P2CONST(Com_tstrSignalPB,AUTOMATIC,COM_CALIB_CONST)   pkstrLclSigPB;\
  P2CONST(Com_tstrGroupSignalPB,AUTOMATIC,COM_CALIB_CONST) pkstrLclGrpSigPB;\
  P2CONST(Com_tstrGWSrcDesc,AUTOMATIC,COM_CALIB_CONST) pkstrLclSrcDscPB;\
  P2CONST(Com_tstrGWDstDesc,AUTOMATIC,COM_CALIB_CONST) pkstrLclDstDscPB;\
 /*PRQA S 8018 , 8318, 8518 -- */\
   /*hold the Byte Number of the signal inside the IPDU buffer */\
   VAR(uint16,AUTOMATIC)                                 u16StartByteNumber;\
   /*hold the starting bit position of the signal in a specific Ipdu Buffer\
   Byte*/\
   VAR(uint8,AUTOMATIC)                                  u8StartBitPosition;\
   /*hold the signal value after being filled in a Byte which will be Orred with\
   the Ipdu buffer byte later to constract the new buffer byte */\
   /*hold the remaining signal length */\
   /*range 0..64 for normal data types , not for dynmaic nor uint8N types*/\
   VAR(uint8,AUTOMATIC)                                  u8RemainingSigBits;\
   VAR(uint32,AUTOMATIC)                                 u32IpduRamBufferIndex =\
                                                        Com_u32INVALID_BUFFER_INDEX;\
   /*hold the size from the new START bit to the STOP bit position inside the\
   ram buffer */\
   VAR(uint16,AUTOMATIC)                                 u16IpduId;\
   VAR(uint8,AUTOMATIC)                                  u8SignalEndianess;\
   VAR(uint8,AUTOMATIC)                                  u8SigType;\
   VAR(uint16,AUTOMATIC)           						u16ArrSigByteLength;\
   VAR(uint16,AUTOMATIC)                                 u16SigObjIndex;\
u16ArrSigByteLength = (uint16)0;\
   switch (u8SigStructType)\
  {\
	Com_vidPACK_SIGNALS(u16SignalIx)\
	Com_vidPACK_GROUP_SIGNALS(u16SignalIx)\
    case Com_u8GW_STRUCT_SRC_DESC:\
	/*u16SigIndex = Com_u16GET_SIGNAL_INDEX(u16SignalId);\*/\
	pkstrLclSrcDscPB = Com_pkstrGET_PBSRC_DESCPTR_IX(u16SignalIx);\
    u8SigType =  pkstrLclSrcDscPB->u8SignalType;\
    u8RemainingSigBits = pkstrLclSrcDscPB->u8BitSize;\
   /*Calculate the starting byte number inside the IPDU of this signal\
   StartingByteNumer = BitPosition / 8 */\
   u16StartByteNumber =  (pkstrLclSrcDscPB->u16BitPosition)>>3;\
   /*Calculate the StartBitPosition Inside the NewByte\
    Start Bit Position Inside The New Byte = BitPosition % 8 */\
    /*range = 0..7 */\
	u8StartBitPosition =(uint8)(pkstrLclSrcDscPB->u16BitPosition & (uint16)7);\
    /*Get the Ipdu Id of the signal*/\
    u16IpduId = pkstrLclSrcDscPB->u16IPduIndex ;\
    /*Get the signal endianess*/\
    u8SignalEndianess = (uint8)(pkstrLclSrcDscPB->udteSignalFlags & Com_u8SIGNAL_ENDIANESS);\
	Com_u16PACK_GW_SRC\
    u16SigObjIndex = pkstrLclSrcDscPB->u16SignalObjectIndex;\
    break;\
    case Com_u8GW_STRUCT_DST_DESC:\
	/*u16SigIndex = Com_u16GET_SIGNAL_INDEX(u16SignalId);\*/\
    pkstrLclDstDscPB = Com_pkstrGET_PBDSTDESCPTR_IX(u16SignalIx);\
    u8SigType =  pkstrLclDstDscPB->u8SignalType;\
    u8RemainingSigBits = pkstrLclDstDscPB->u8BitSize;\
   /*Calculate the starting byte number inside the IPDU of this signal\
   StartingByteNumer = BitPosition / 8 */\
   u16StartByteNumber =  (pkstrLclDstDscPB->u16BitPosition)>>3;\
   /*Calculate the StartBitPosition Inside the NewByte\
    Start Bit Position Inside The New Byte = BitPosition % 8 */\
    /*range = 0..7 */\
	u8StartBitPosition =(uint8)(pkstrLclDstDscPB->u16BitPosition & (uint16)7);\
    /*Get the Ipdu Id of the signal*/\
    u16IpduId = pkstrLclDstDscPB->u16IPduIndex ;\
    /*Get the signal endianess*/\
    u8SignalEndianess = (uint8)(pkstrLclDstDscPB->udteSignalFlags & Com_u8SIGNAL_ENDIANESS);\
	Com_u16PACK_GW_DST\
    u16SigObjIndex = pkstrLclDstDscPB->u16SignalObjectIndex;\
    break;\
    default:\
    /*shall not enter here*/\
    u8SigType = (uint8)0xFF ;\
    u8RemainingSigBits = (uint8)0;\
    u16IpduId =(uint16)0;\
    u8StartBitPosition = (uint8)0x00u;\
    u16SigObjIndex = (uint16)0;\
    u16StartByteNumber = (uint16)0;\
    u8SignalEndianess = (uint8)0xFFu;\
    break;\
  }\
     switch (Com_u8GET_IPDU_DIR(u16IpduId))\
    {\
      case Com_u8DIRECTION_TX:\
      u32IpduRamBufferIndex = Com_u32GET_TX_IPDU_BUFF_IX(u16IpduId);\
      break;\
      case Com_u8DIRECTION_RX:\
      u32IpduRamBufferIndex = Com_u32GET_RX_IPDU_BUFF_IX(u16IpduId);\
      break;\
      default:\
      /*it shall not enter here !*/\
    break;\
    }\
 /* !Deviation: [3356]  ( The value of this control expression is always 'false' due to\
 some special configuration but in the normal case this part is normally reachable.) */\
/*PRQA S 3356 ++ */\
 if( (u8RemainingSigBits > (uint8)0)  || (u16ArrSigByteLength > (uint16)0 ) )\
 /*PRQA S 3356 -- */\
 {\
  /*Non Zero Length signals*/\
  /*pack the signal data into the signal objects*/\
   switch (u8SigType)\
   {\
     case Com_u8SIGNAL_TYPE_BOOLEAN:\
        (*(P2VAR(boolean,AUTOMATIC,COM_CALIB_DATA)) Com_bGET_SIG_OBJ_VALUEB(u16SigObjIndex)) =\
        * (P2CONST(boolean,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)) (pkvidSignalDataPtr) ;\
        Com_vidCPY2_IPDU_BOOL_BUFF((*(P2CONST(boolean,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)) pkvidSignalDataPtr),\
          u16StartByteNumber, u8StartBitPosition, u8RemainingSigBits, u32IpduRamBufferIndex );\
     break;\
     case Com_u8SIGNAL_TYPE_UINT8:\
        (* (P2VAR(uint8,AUTOMATIC,COM_CALIB_DATA)) Com_u8GET_SIG_OBJ_VALUEU8(u16SigObjIndex)) =\
        * (P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)) pkvidSignalDataPtr ;\
        Com_vidCPY2_IPDU_8BIT_BUFF( * (P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)) pkvidSignalDataPtr,\
          u16StartByteNumber, u8StartBitPosition, u8RemainingSigBits, u8SignalEndianess, u32IpduRamBufferIndex );\
     break;\
     case Com_u8SIGNAL_TYPE_SINT8:\
        (*(P2VAR(sint8,AUTOMATIC,COM_CALIB_DATA))  Com_s8GET_SIG_OBJ_VALUES8(u16SigObjIndex)) =\
        * (P2CONST(sint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)) pkvidSignalDataPtr ;\
        Com_vidCPY2_IPDU_8BIT_BUFF( * (P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)) pkvidSignalDataPtr,\
          u16StartByteNumber, u8StartBitPosition, u8RemainingSigBits, u8SignalEndianess, u32IpduRamBufferIndex );\
     break;\
     case Com_u8SIGNAL_TYPE_UINT16:\
       SchM_Enter_Com_SigObjU16();\
        (*(P2VAR(uint16,AUTOMATIC,COM_CALIB_DATA))  Com_u16GET_SIG_OBJ_VALUEU16(u16SigObjIndex)) =\
        * (P2CONST(uint16,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)) pkvidSignalDataPtr ;\
        SchM_Exit_Com_SigObjU16();\
        Com_vidCPY2_IPDU_16BIT_BUFF( * (P2CONST(uint16,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)) pkvidSignalDataPtr,\
          u16StartByteNumber, u8StartBitPosition, u8RemainingSigBits, u8SignalEndianess, u32IpduRamBufferIndex );\
     break;\
     case Com_u8SIGNAL_TYPE_SINT16:\
       SchM_Enter_Com_SigObjS16();\
        (*(P2VAR(sint16,AUTOMATIC,COM_CALIB_DATA)) Com_s16GET_SIG_OBJ_VALUES16(u16SigObjIndex)) =\
        * (P2CONST(sint16,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)) pkvidSignalDataPtr ;\
        SchM_Exit_Com_SigObjS16();\
        Com_vidCPY2_IPDU_16BIT_BUFF( * (P2CONST(uint16,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)) pkvidSignalDataPtr,\
          u16StartByteNumber, u8StartBitPosition, u8RemainingSigBits, u8SignalEndianess, u32IpduRamBufferIndex );\
     break;\
     case Com_u8SIGNAL_TYPE_UINT32:\
       SchM_Enter_Com_SigObjU32();\
        (*(P2VAR(uint32,AUTOMATIC,COM_CALIB_DATA)) Com_u32GET_SIG_OBJ_VALUEU32(u16SigObjIndex)) =\
        * (P2CONST(uint32,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)) pkvidSignalDataPtr ;\
        SchM_Exit_Com_SigObjU32();\
        Com_vidCPY2_IPDU_32BIT_BUFF( * (P2CONST(uint32,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSignalDataPtr,\
          u16StartByteNumber, u8StartBitPosition, u8RemainingSigBits, u8SignalEndianess, u32IpduRamBufferIndex );\
     break;\
     case Com_u8SIGNAL_TYPE_SINT32:\
       SchM_Enter_Com_SigObjS32();\
        (*(P2VAR(sint32,AUTOMATIC,COM_CALIB_DATA)) Com_s32GET_SIG_OBJ_VALUES32(u16SigObjIndex)) =\
        * (P2CONST(sint32,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)) pkvidSignalDataPtr ;\
        SchM_Exit_Com_SigObjS32();\
        Com_vidCPY2_IPDU_32BIT_BUFF( * (P2CONST(uint32,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSignalDataPtr,\
        u16StartByteNumber, u8StartBitPosition, u8RemainingSigBits, u8SignalEndianess, u32IpduRamBufferIndex );\
     break;\
     case Com_u8SIGNAL_TYPE_FLOAT32:\
       SchM_Enter_Com_SigObjF32();\
        (*(P2VAR(float32,AUTOMATIC,COM_CALIB_DATA)) Com_f32GET_SIG_OBJ_VALUEF32(u16SigObjIndex)) =\
        * (P2CONST(float32,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)) pkvidSignalDataPtr ;\
        SchM_Exit_Com_SigObjF32();\
        Com_vidCPY2_IPDU_F32_BUFF( * (P2CONST(uint32,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSignalDataPtr,\
          u16StartByteNumber, u8StartBitPosition, u8SignalEndianess, u32IpduRamBufferIndex );\
     break;\
     case Com_u8SIGNAL_TYPE_FLOAT64:\
       SchM_Enter_Com_SigObjF64();\
       (*(P2VAR(float64,AUTOMATIC,COM_CALIB_DATA)) Com_f64GET_SIG_OBJ_VALUEF64(u16SigObjIndex)) =\
        * (P2CONST(float64,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST)) pkvidSignalDataPtr ;\
        SchM_Exit_Com_SigObjF64();\
        Com_vidCPY2_IPDU_F64_BUFF(  (P2CONST(uint8,AUTOMATIC,COM_MAX_CALIB_APPL_CFGCONST))pkvidSignalDataPtr,\
          u16StartByteNumber, u8StartBitPosition, u8SignalEndianess, u32IpduRamBufferIndex );\
     break;\
     case  Com_u8SIGNAL_TYPE_UINT8N :\
       Com_u8PACK_ARRAY_SIGNAL(\
            Com_u8SIGNAL_TYPE_UINT8N,\
            u16SigObjIndex,\
            u16ArrSigByteLength,\
            u16StartByteNumber,\
            (uint16)0,\
            pkvidSignalDataPtr,\
            Com_pku8GET_IPDU_BUFF_PTR(u32IpduRamBufferIndex)) ;\
     break;\
     case Com_u8SIGNAL_TYPE_UINT8DYN:\
       Com_u8PACK_ARRAY_SIGNAL(\
            Com_u8SIGNAL_TYPE_UINT8DYN,\
            u16SigObjIndex,\
            u16DynLength ,\
            u16StartByteNumber,\
            u16ArrSigByteLength,\
            pkvidSignalDataPtr,\
            Com_pku8GET_IPDU_BUFF_PTR(u32IpduRamBufferIndex)) ;\
     break;\
     default:\
     break;\
   }\
  }\
} while(0)
/* PRQA S 3205 --*/
/* PRQA S 4700 -- */
/* PRQA S 3459,3410,3412 -- */
/******************************************************************************/
#endif /* COM_PACKSIG_H */