/******************************************************************************
*
* FILE:
*   SQRT.h         1999/03/31
*
* RELATED FILES:
*
* DESCRIPTION:
*   Calculates an integer square root from argument 'ar'. The result 'rslt' is
*   the largest integer whose square is less than or equal 'ar'.
*   Expression for 'ar' possible.
*
* NOTE:
*   For the algorithm are several formulas used:
*   1. Getting next square in a loop (the last added digit is also the number
*      whose square you were taking):
*       (n+1)^2 = n^2 + n + (n+1)
*   2. Shifting to the next pair of digits (always calculating numbers in pairs)
*      ar   = 10p + q  (two digits, decimal number)
*      ar^2 = 100p^2 + 20pq + q^2
*      q    = (ar^2-100p^2) / (20p+q)
*
* - This file contains several macro definitions and function declarations
*   for square-root operations
* - C-macros are characterized by a leading "C__".
*   Ansi-C-functions are characterized by a leading "F__".
* - The macro/function-name represents the implemented operation(s):
*	(C__|F__) + output_type + OPERATION + input_type {+ input_type} [+ _SAT]
*
*   C__U8SQRTU8():	      sqrt(UInt8)	full
*   C__U8SQRTU16():       sqrt(UInt16)	full
*   C__U8SQRTU32():       sqrt(UInt32)	range [0, 0xffff]
*   C__U8SQRTU32_SAT():   sqrt(UInt32), full range
*   C__U16SQRTU32():      sqrt(UInt32)	full
*
*   C__U8SQRTI8():	      sqrt(Int8)	range [0, 0x7f]
*   C__U8SQRTI8_SAT():    sqrt(Int8)	full
*   C__U8SQRTI16():       sqrt(Int16)	range [0, 0x7fff]
*   C__U8SQRTI16_SAT():   sqrt(Int16)	full
*   C__U8SQRTI32():       sqrt(Int32)	range [0, 0x0000ffff]
*   C__U8SQRTI32_SAT():   sqrt(Int32),  full
*   C__U16SQRTI32():      sqrt(Int32)	range [0, 0x7fffffff]
*   C__U16SQRTI32()_SAT:  sqrt(Int32)	full
*
*
*   C__I8SQRTU8():	      sqrt(UInt8)	full
*   C__I8SQRTU16():       sqrt(UInt16)	range [0, 0x3fff]
*   C__I8SQRTU16_SAT():   sqrt(UInt16)	full range
*   C__I8SQRTU32():       sqrt(UInt32)	range [0, 0x3fff]
*   C__I8SQRTU32_SAT():   sqrt(UInt32), full range
*   C__I16SQRTU32():      sqrt(UInt32)	range [0, 0x3FFFFFFF]
*   C__I16SQRTU32_SAT():  sqrt(UInt32), full range
*   C__I16SQRTU16():      sqrt(UInt16)	full
*   C__I32SQRTU32():      sqrt(UInt32)	full
*
*   C__I8SQRTI8():	      sqrt(Int8)	full
*   C__I8SQRTI16():       sqrt(Int16)	range [-(0x3fff), 0x3fff]
*   C__I8SQRTI16_SAT():   sqrt(Int16)	full range
*   C__I8SQRTI32():       sqrt(Int32)	range [-(0x3fff), 0x3fff]
*   C__I8SQRTI32_SAT():   sqrt(Int32),  full range
*   C__I16SQRTI32():      sqrt(Int32)	range [-(0x3FFFFFFF), 0x3FFFFFFF]
*   C__I16SQRTI32_SAT():  sqrt(Int32),  full range
*   C__I16SQRTI16():      sqrt(Int16)	full
*   C__I32SQRTI32():      sqrt(Int32)	full
*
*
*  AUTHOR(S):
*    H. Steenblock, O. Grajetzky, F. Lünstroth
*
*  Copyright (c) 1999 dSPACE GmbH, GERMANY
*
*  $Workfile: sqrt.h $ $Revision: 1.1 $ $Date: 2004/04/28 11:44:52GMT+01:00 $ $Author: FrankL $
******************************************************************************/


#ifndef __sqrt_h__
#define __sqrt_h__


/******************************************************************************
*
*   C__U8SQRTU8():	      sqrt(UInt8)
*
******************************************************************************/
#define C__U8SQRTU8(ar, rslt)\
{\
    UInt8 a       = ar;                      /* argument of macro           */\
    UInt8 rem     = 0,                       /* remainder                   */\
          root    = 0,                       /* result of sqrt              */\
          divisor;\
    UInt8 i;                                 /* loop index                  */\
\
    for (i=0; i<4; i++)\
    {\
        root <<= 1;                           /* shift for next bit result   */\
        rem = (UInt8)((rem<<2) + (a>>6));     /* shift input argument in rem */\
        divisor = (UInt8)((root<<1) + 1);     /* divisor = (root<<2) + 1     */\
        if (divisor <= rem)                   /* bit division                */\
        {\
            rem -= divisor;\
            root++;\
        }\
        a <<= 2;                              /* prepare a for next loop     */\
    }\
    rslt = root;\
}
/* END C__U8SQRTU8() */



/******************************************************************************
*
*   C__U8SQRTU16():       sqrt(UInt16)
*
******************************************************************************/
#define C__U8SQRTU16(ar, rslt)\
{\
    UInt16 a       = ar;                      /* argument of macro           */\
    UInt16 rem     = 0,                       /* remainder                   */\
           root    = 0,                       /* result of sqrt              */\
           divisor;\
    UInt8 i;                                  /* loop index                  */\
\
    for (i=0; i<8; i++)\
    {\
        root <<= 1;                           /* shift for next bit result   */\
        rem = (UInt16)((rem<<2) + (a>>14));   /* shift input argument in rem */\
        divisor = (UInt16)((root<<1) + 1);    /* divisor = (root<<2) + 1     */\
        if (divisor <= rem)                   /* bit division                */\
        {\
            rem -= divisor;\
            root++;\
        }\
        a <<= 2;                              /* prepare a for next loop     */\
    }\
    rslt = (UInt8)root;\
}
/* END C__U8SQRTU16() */



/******************************************************************************
*
*   C__U8SQRTU32():       sqrt(UInt32)	range [0, 0xffff]
*
******************************************************************************/
#define C__U8SQRTU32(ar, rslt)\
{\
     UInt32 rem  = 0,                         /* remainder                   */\
            root = 0;                         /* result of sqrt              */\
     UInt32 a    = ar;                        /* argument of macro           */\
     UInt8 i;                                 /* loop index                  */\
\
    for (i=0; i<16; i++)\
    {\
        root <<= 1;                           /* shift for next bit result   */\
        rem = (UInt32)((rem<<2) + (a >>30));  /* shift input argument in rem */\
        a <<= 2;                              /* prepare a for next loop     */\
        root++;\
        if (root <= rem)                      /* bit division                */\
        {\
            rem -= root;\
            root++;\
        }\
        else root--;\
    }\
    rslt = (UInt8)(root>>1);\
}
/* END C__U8SQRTU32() */



/******************************************************************************
*
*   C__U8SQRTU32_SAT():   sqrt(UInt32), full range
*
******************************************************************************/
#define C__U8SQRTU32_SAT(ar, rslt)\
{\
     UInt32 rem  = 0,                         /* remainder                   */\
            root = 0;                         /* result of sqrt              */\
     UInt32 a    = ar;                        /* argument of macro           */\
     UInt8 i;                                 /* loop index                  */\
\
    for (i=0; i<16; i++)\
    {\
        root <<= 1;                           /* shift for next bit result   */\
        rem = (UInt32)((rem<<2) + (a >>30));  /* shift input argument in rem */\
        a <<= 2;                              /* prepare a for next loop     */\
        root++;\
        if (root <= rem)                      /* bit division                */\
        {\
            rem -= root;\
            root++;\
        }\
        else root--;\
    }\
    root >>= 1;\
    if (root > UINT8MAX)\
	    rslt = UINT8MAX;\
	else\
	    rslt = (UInt8)(root);\
}
/* END C__U8SQRTU32_SAT() */



/******************************************************************************
*
*   C__U16SQRTU32():      sqrt(UInt32)
*
******************************************************************************/
#define C__U16SQRTU32(ar, rslt)\
{\
     UInt32 rem  = 0,                         /* remainder                   */\
            root = 0;                         /* result of sqrt              */\
     UInt32 a    = ar;                        /* argument of macro           */\
     UInt8 i;                                 /* loop index                  */\
\
    for (i=0; i<16; i++)\
    {\
        root <<= 1;                           /* shift for next bit result   */\
        rem = (UInt32)((rem<<2) + (a >>30));  /* shift input argument in rem */\
        a <<= 2;                              /* prepare a for next loop     */\
        root++;\
        if (root <= rem)                      /* bit division                */\
        {\
            rem -= root;\
            root++;\
        }\
        else root--;\
    }\
    rslt = (UInt16)(root>>1);\
}
/* END C__U16SQRTU32() */



/******************************************************************************
*
*   C__U8SQRTI8():	      sqrt(Int8)
*
******************************************************************************/
#define C__U8SQRTI8(ar, rslt)\
{\
    Int8 a_ = ar;\
\
    if (a_ < 0)\
    {\
        a_ = (Int8)(-a_);\
    }\
    C__U8SQRTU8((UInt8)a_, rslt);\
}
/* END C__U8SQRTI8() */



/******************************************************************************
*
*   C__U8SQRTI8_SAT():	      sqrt(Int8)
*
******************************************************************************/
#define C__U8SQRTI8_SAT(ar, rslt)\
{\
    if (ar < 0)\
    {\
        rslt = 0;\
    }\
	else\
	{\
	    C__U8SQRTU8((UInt8)ar, rslt);\
	}\
}
/* END C__U8SQRTI8_SAT() */



/******************************************************************************
*
*   C__U8SQRTI16():       sqrt(Int16)
*
******************************************************************************/
#define C__U8SQRTI16(ar, rslt)\
{\
    Int16 a_ = ar;\
\
    if (a_ < 0)\
    {\
        a_ = (Int16)(-a_);\
    }\
    C__U8SQRTU16((UInt16)(a_), rslt);\
}
/* END C__U8SQRTI16() */



/******************************************************************************
*
*   C__U8SQRTI16_SAT():       sqrt(Int16)
*
******************************************************************************/
#define C__U8SQRTI16_SAT(ar, rslt)\
{\
\
    if (ar < 0)\
    {\
        rslt = 0;\
    }\
	else\
	{\
    	C__U8SQRTU16((UInt16)ar, rslt);\
	}\
}
/* END C__U8SQRTI16_SAT() */



/******************************************************************************
*
*   C__U8SQRTI32():       sqrt(Int32)	range [-(0xffff),0xffff]
*
******************************************************************************/
#define C__U8SQRTI32(ar, rslt)\
{\
    Int32 a_ = ar;\
\
    if (a_ < 0)\
    {\
        a_ = (Int32)(-a_);\
    }\
    C__U8SQRTU32((UInt32)(a_), rslt);\
}
/* END C__U8SQRTI32() */



/******************************************************************************
*
*   C__U8SQRTI32_SAT():   sqrt(Int32),  full range
*
******************************************************************************/
#define C__U8SQRTI32_SAT(ar, rslt)\
{\
    if (ar < 0)\
    {\
        rslt = 0;\
    }\
	else\
	{\
	    C__U8SQRTU32_SAT((UInt32)ar, rslt);\
	}\
}
/* END C__U8SQRTI32_SAT() */



/******************************************************************************
*
*   C__U16SQRTI32():      sqrt(Int32)
*
******************************************************************************/
#define C__U16SQRTI32(ar, rslt)\
{\
    Int32 a_ = ar;\
\
    if (a_ < 0)\
    {\
        a_ = (Int32)(-a_);\
    }\
    C__U16SQRTU32((UInt32)(a_), rslt);\
}
/* END C__U16SQRTI32() */



/******************************************************************************
*
*   C__U16SQRTI32_SAT():      sqrt(Int32)
*
******************************************************************************/
#define C__U16SQRTI32_SAT(ar, rslt)\
{\
    if (ar < 0)\
    {\
        rslt = 0;\
    }\
	else\
	{\
	    C__U16SQRTU32((UInt32)ar, rslt);\
	}\
}
/* END C__U16SQRTI32_SAT() */






/******************************************************************************
*
*   C__I8SQRTU8():	      sqrt(UInt8)
*
******************************************************************************/
#define C__I8SQRTU8(ar, rslt)\
{\
    UInt8 y;      		                   /* intermediate result       */\
\
	C__U8SQRTU8(ar, y)\
    rslt = (Int8)y;\
}
/* END C__I8SQRTU8() */



/******************************************************************************
*
*   C__I8SQRTU16():       sqrt(UInt16)	range [0, 0x3fff]
*
******************************************************************************/
#define C__I8SQRTU16(ar, rslt)\
{\
    UInt8 y;      		                   /* intermediate result       */\
\
	C__U8SQRTU16(ar, y)\
    rslt = (Int8)y;\
}
/* END C__I8SQRTU16() */



/******************************************************************************
*
*   C__I8SQRTU16_SAT():   sqrt(UInt16)	full range
*
******************************************************************************/
#define C__I8SQRTU16_SAT(ar, rslt)\
{\
    UInt8 y;      		                   /* intermediate result       */\
\
	C__U8SQRTU16(ar, y)\
    if (y > INT8MAX)\
	    rslt = INT8MAX;\
	else\
        rslt = (Int8)y;\
}
/* END C__I8SQRTU16_SAT() */



/******************************************************************************
*
*   C__I8SQRTU32():       sqrt(UInt32)	range [0, 0x3fff]
*
******************************************************************************/
#define C__I8SQRTU32(ar, rslt)\
{\
    UInt8 y;      		                   /* intermediate result       */\
\
	C__U8SQRTU32(ar, y)\
    rslt = (Int8)y;\
}
/* END C__I8SQRTU32() */



/******************************************************************************
*
*   C__I8SQRTU32_SAT():   sqrt(UInt32), full range
*
******************************************************************************/
#define C__I8SQRTU32_SAT(ar, rslt)\
{\
     UInt32 rem  = 0,                         /* remainder                   */\
            root = 0;                         /* result of sqrt              */\
     UInt32 a    = ar;                        /* argument of macro           */\
     UInt8 i;                                 /* loop index                  */\
\
    for (i=0; i<16; i++)\
    {\
        root <<= 1;                           /* shift for next bit result   */\
        rem = (UInt32)((rem<<2) + (a >>30));  /* shift input argument in rem */\
        a <<= 2;                              /* prepare a for next loop     */\
        root++;\
        if (root <= rem)                      /* bit division                */\
        {\
            rem -= root;\
            root++;\
        }\
        else root--;\
    }\
    root >>= 1;\
    if (root > INT8MAX)\
	    rslt = INT8MAX;\
	else\
	    rslt = (Int8)(root);\
}
/* END C__I8SQRTU32_SAT() */



/******************************************************************************
*
*   C__I16SQRTU32():      sqrt(UInt32)	range [0, 0x3FFFFFFF]
*
******************************************************************************/
#define C__I16SQRTU32(ar, rslt)\
{\
    UInt16 y;     		                   /* intermediate result       */\
\
	C__U16SQRTU32(ar, y)\
    rslt = (Int16)y;\
}
/* END C__I16SQRTU32() */



/******************************************************************************
*
*   C__I16SQRTU32_SAT():  sqrt(UInt32), full range
*
******************************************************************************/
#define C__I16SQRTU32_SAT(ar, rslt)\
{\
    UInt16 y;      		                   /* intermediate result       */\
\
	C__U16SQRTU32(ar, y)\
    if (y > INT16MAX)\
	    rslt = INT16MAX;\
	else\
        rslt = (Int16)y;\
}
/* END C__I16SQRTU32_SAT() */



/******************************************************************************
*
*   C__I16SQRTU16():      sqrt(UInt16)
*
******************************************************************************/
#define C__I16SQRTU16(ar, rslt)\
{\
    UInt8 y;      		                   /* intermediate result       */\
\
	C__U8SQRTU16(ar, y)\
    rslt = (Int16)y;\
}
/* END C__I16SQRTU16() */



/******************************************************************************
*
*   C__I16SQRTU32():      sqrt(UInt32)
*
******************************************************************************/
#define C__I32SQRTU32(ar, rslt) \
{\
    UInt16 y;                              /* intermediate result       */\
\
    C__U16SQRTU32(ar, y)\
    rslt = (Int32)y;\
}
/* END C__I32SQRTU32() */



/******************************************************************************
*
*   C__I8SQRTI8():	      sqrt(Int8)
*
******************************************************************************/
#define C__I8SQRTI8(ar, rslt)\
{\
    Int8 neg = 0;                         /* 0 = positive, 1 = negative */\
    UInt8 y;                              /* intermediate result        */\
    Int8 a_ = ar;\
\
    if (a_ < 0)                           /* negative ?                 */\
    {\
        a_ = (Int8)(-a_);\
        neg = 1;\
    }\
    C__U8SQRTU8((UInt8)(a_), y);\
    rslt = (neg) ? (Int8)(-y) : (Int8)y;\
}
/* END C__I8SQRTI8() */



/******************************************************************************
*
*   C__I8SQRTI16():       sqrt(Int16)	range [-(0x3fff), 0x3fff]
*
******************************************************************************/
#define C__I8SQRTI16(ar, rslt)\
{\
    Int8 neg = 0;                     /* 0 = positive, 1 = negative */\
    UInt8 y;                          /* intermediate result       */\
    Int16 a_ = ar;\
\
    if (a_ < 0)                       /* negative ?               */\
    {\
        a_ = (Int16)(-a_);\
        neg = 1;\
    }\
    C__U8SQRTU16((UInt16)(a_), y);\
    rslt = (neg) ? (Int8)(-y) : (Int8)y;\
}
/* END C__I8SQRTI16() */



/******************************************************************************
*
*   C__I8SQRTI16_SAT():   sqrt(Int16)	full range
*
******************************************************************************/
#define C__I8SQRTI16_SAT(ar, rslt)\
{\
    Int8 neg = 0;                     /* 0 = positive, 1 = negative */\
    UInt8 y;                          /* intermediate result       */\
    Int16 a_ = ar;\
\
    if (a_ < 0)                       /* negative ?                */\
    {\
        a_ = (Int16)(-a_);\
        neg = 1;\
    }\
    C__U8SQRTU16((UInt16)(a_), y);\
\
    if (y > INT8MAX)                  /* saturation                */\
        rslt = (neg) ? ~INT8MAX : INT8MAX;\
    else\
        rslt = (neg) ? (Int8)(-y) : (Int8)y;\
}
/* END C__I8SQRTI16_SAT() */



/******************************************************************************
*
*   C__I8SQRTI32():       sqrt(Int32)	range [-(0x3fff), 0x3fff]
*
******************************************************************************/
#define C__I8SQRTI32(ar, rslt)\
{\
    Int8 neg = 0;                     /* 0 = positive, 1 = negative */\
    UInt8 y;                          /* intermediate result       */\
    Int32 a_ = ar;\
\
    if (a_ < 0)                       /* negative ?               */\
    {\
        a_ = (Int32)(-a_);\
        neg = 1;\
    }\
    C__U8SQRTU32((UInt32)(a_), y);\
    rslt = (neg) ? (Int8)(-y) : (Int8)y;\
}
/* END C__I8SQRTI32() */



/******************************************************************************
*
*   C__I8SQRTI32_SAT():   sqrt(Int32),  full range
*
******************************************************************************/
#define C__I8SQRTI32_SAT(ar, rslt)\
{\
    Int8 neg = 0;                     /* 0 = positive, 1 = negative */\
    UInt16 y;                           /* intermediate result       */\
    Int32 a_ = ar;\
\
    if (a_ < 0)                       /* negative ?                */\
    {\
        a_ = (Int32)(-a_);\
        neg = 1;\
    }\
    C__U16SQRTU32((UInt32)(a_), y);\
\
    if (y > INT8MAX)                  /* saturation                */\
        rslt = (neg) ? ~INT8MAX : INT8MAX;\
    else\
        rslt = (neg) ? (Int8)(-y) : (Int8)y;\
}
/* END C__I8SQRTI32_SAT() */



/******************************************************************************
*
*   C__I16SQRTI32():      sqrt(Int32)	range [-(0x3FFFFFFF), 0x3FFFFFFF]
*
******************************************************************************/
#define C__I16SQRTI32(ar, rslt)\
{\
    Int8 neg = 0;                     /* 0 = positive, 1 = negative */\
    UInt16 y;                         /* intermediate result       */\
    Int32 a_ = ar;\
\
    if (a_ < 0)                       /* negative ?               */\
    {\
        a_ = (Int32)(-a_);\
        neg = 1;\
    }\
    C__U16SQRTU32((UInt32)(a_), y);\
    rslt = (neg) ? (Int16)(-y) : (Int16)y;\
}
/* END C__I16SQRTI32() */



/******************************************************************************
*
*   C__I16SQRTI32_SAT():  sqrt(Int32),  full range
*
******************************************************************************/
#define C__I16SQRTI32_SAT(ar, rslt)\
{\
    Int8 neg = 0;                     /* 0 = positive, 1 = negative */\
    UInt16 y;                         /* intermediate result       */\
    Int32 a_ = ar;\
\
    if (a_ < 0)                       /* negative ?                */\
    {\
        a_ = (Int32)(-a_);\
        neg = 1;\
    }\
    C__U16SQRTU32((UInt32)(a_), y);\
\
    if (y > INT16MAX)                  /* saturation                */\
        rslt = (neg) ? ~INT16MAX : INT16MAX;\
    else\
        rslt = (neg) ? (Int16)(-y) : (Int16)y;\
}
/* END C__I16SQRTI32_SAT() */


/******************************************************************************
*
*   C__I16SQRTI16():      sqrt(Int16)
*
******************************************************************************/
#define C__I16SQRTI16(ar, rslt)\
{\
    Int8 neg = 0;                     /* 0 = positive, 1 = negative */\
    UInt8 y;                          /* intermediate result       */\
    Int16 a_ = ar;\
\
    if (a_ < 0)                       /* negative ?               */\
    {\
        a_ = (Int16)(-a_);\
        neg = 1;\
    }\
    C__U8SQRTU16((UInt16)(a_), y);\
    rslt = (neg) ? (Int16)(-y) : (Int16)y;\
}
/* END C__I16SQRTI16() */




/******************************************************************************
*
*   C__I16SQRTI32():      sqrt(Int32)
*
******************************************************************************/
#define C__I32SQRTI32(ar, rslt)\
{\
    Int8 neg = 0;                     /* 0 = positive, 1 = negative */\
    UInt16 y;                         /* intermediate result       */\
    Int32 a_ = ar;\
\
    if (a_ < 0)                       /* negative ?               */\
    {\
        a_ = (Int32)(-a_);\
        neg = 1;\
    }\
    C__U16SQRTU32((UInt32)(a_), y);\
    rslt = (neg) ? (Int32)(-y) : (Int32)y;\
}
/* END C__I32SQRTI32() */








UInt8  F__U8SQRTU8(       UInt8 ar);
UInt8  F__U8SQRTU16(      UInt16 ar);
UInt8  F__U8SQRTU32(      UInt32 ar);
UInt8  F__U8SQRTU32_SAT(  UInt32 ar);
UInt16 F__U16SQRTU32(     UInt32 ar);

UInt8  F__U8SQRTI8(        Int8 ar);
UInt8  F__U8SQRTI8_SAT(    Int8 ar);
UInt8  F__U8SQRTI16(       Int16 ar);
UInt8  F__U8SQRTI16_SAT(   Int16 ar);
UInt8  F__U8SQRTI32(       Int32 ar);
UInt8  F__U8SQRTI32_SAT(   Int32 ar);
UInt16 F__U16SQRTI32(      Int32 ar);
UInt16 F__U16SQRTI32_SAT(  Int32 ar);

Int8   F__I8SQRTU8(       UInt8 ar);
Int8   F__I8SQRTU16(      UInt16 ar);
Int8   F__I8SQRTU16_SAT(  UInt16 ar);
Int8   F__I8SQRTU32(      UInt32 ar);
Int8   F__I8SQRTU32_SAT(  UInt32 ar);
Int16  F__I16SQRTU32(     UInt32 ar);
Int16  F__I16SQRTU32_SAT( UInt32 ar);
Int16  F__I16SQRTU16(     UInt16 ar);
Int32  F__I32SQRTU32(     UInt32 ar);

Int8   F__I8SQRTI8(        Int8 ar);
Int8   F__I8SQRTI16(       Int16 ar);
Int8   F__I8SQRTI16_SAT(   Int16 ar);
Int8   F__I8SQRTI32(       Int32 ar);
Int8   F__I8SQRTI32_SAT(   Int32 ar);
Int16  F__I16SQRTI32(      Int32 ar);
Int16  F__I16SQRTI32_SAT(  Int32 ar);
Int16  F__I16SQRTI16(      Int16 ar);
Int32  F__I32SQRTI32(      Int32 ar);


#endif /* #ifndef __sqrt_h__ */
