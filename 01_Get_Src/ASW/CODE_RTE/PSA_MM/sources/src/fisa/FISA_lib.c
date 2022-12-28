/******************************************************************************/
/*                                                                            */
/* !Layer :                 APPLI                                             */
/*                                                                            */
/* !Component :             FISA                                              */
/* !Description :                                                             */
/*                                                                            */
/* !Module :               FISA_lib                                           */
/* !Description :       librairie math                                        */
/*                                                                            */
/* !File :                     FISA_lib.c                                     */
/*                                                                            */
/* !Scope :                 Public                                            */
/*                                                                            */
/* !Target :                All                                               */
/*                                                                            */
/* !Vendor :                Valeo                                             */
/*                                                                            */
/* Coding language :  C                                                       */
/*                                                                            */
/* COPYRIGHT 2008 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/LIBPSA/LOG/Ref/SWC_VEMS/FISA/LOG/FISA_lib.c_v          $*/
/* $Revision::   1.14      $$Author::   flavergn$$Date::   21 Jul 2010 15:$*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/
/*FISA_erreur_                                                                */
/*Delay1_Boolean                                                              */
/*Delay1_UINT8                                                                */
/*Delay1_SInt16                                                               */
/*Delay1_UINT16                                                               */
/*Delay2                                                                      */
/*Delay2_boolean                                                              */
/*Delay2_SINT16                                                               */
/*Delay2_UINT16                                                               */
/*FISA_MAX                                                                    */
/*FISA_MIN                                                                    */
/*FISA_UMIN16                                                                 */
/*FISA_MIN16                                                                  */
/*FISA_MIN_8_16                                                               */
/*FISA_UMAX                                                                   */
/*FISA_U8MAX                                                                  */
/*FISA_U16MAX                                                                 */
/*FISA_MAX_8_16                                                               */
/*FISA_UMIN                                                                   */
/*FISA_U8MIN                                                                  */
/*Accum_Sat_Analisys_without_FIX                                              */
/*Saturation_tout_FIX                                                         */
/*Saturation_FIX                                                              */
/*DivWithAntiDiVByZero                                                        */
/*DivWithAntiDiVByZeroFix                                                     */
/*Saturation_INT                                                              */
/*Saturation_INT_S8                                                           */
/*Saturation_INT_U8                                                           */
/*Saturation_INT_U16                                                          */
/*lookup2D                                                                    */
/*lookup2D_yU16_U16                                                           */
/*lookup2D_xyU16_U16                                                          */
/*lookup2D_rS32_U8                                                            */
/*lookup2D_rS32_S8                                                            */
/*lookup1D                                                                    */
/*lookup1D_U16                                                                */
/*lookup1D_rU32_U16                                                           */
/*lookup1D_U8                                                                 */
/*lookup1D_rS16_U8                                                            */
/*lookup1D_rS16_xU16_U8                                                       */
/*Accum_Sat_Analyse_SInt16                                                    */
/******************************************************************************/




#include "FISA_lib.h"
#include "FISA_Runnables.h"

#define FISA_START_SEC_VAR_8BIT
#include "FISA_MemMap.h"

VAR(UInt8,FISA_VAR) FISA_ErreurCode;

#define FISA_STOP_SEC_VAR_8BIT
#include "FISA_MemMap.h"


#define FISA_START_SEC_CODE
#include "FISA_MemMap.h"

_STATIC_ FUNC(UInt16,FISA_CODE) FISA_UMIN16 (UInt16 Value1, UInt16 Value2);
_STATIC_ FUNC(SInt8,FISA_CODE)  FISA_MIN_8_16 (SInt16 Value1, SInt16 Value2);
_STATIC_ FUNC(SInt8,FISA_CODE)  FISA_MAX_8_16 (SInt16 Value1, SInt16 Value2);


/*==============================================================================
** Name: FISA_erreur_
** Description: Traitement des erreurs FISA
**------------------------------------------------------------------------------
** IN:
** UInt8 type_erreur : code de l'erreur
**------------------------------------------------------------------------------
** OUT:
** Rien
**
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  :																 						*/
/*********************************************************************************/

FUNC(void,FISA_CODE) FISA_erreur_(UInt8 type_erreur)
{
  VAR(UInt16,AUTOMATIC)         Ext_nEng;
  VAR(UInt8,AUTOMATIC)          u8localFISA_facRich_C;

  FISA_ErreurCode = type_erreur;
  FISA_GetExt_nEng(&Ext_nEng);

  if (Ext_nEng>0)
  {
    /* Si le moteur est demarre */
    /* Ne rien faire : FISA_facAdp_NV deja a jour*/
  }
  else
  {
    /* Si le moteur est arrete */
	 u8localFISA_facRich_C = (UInt8) ((FISA_facRich_C * 128 +50) /100);
	 FISA_Update_facAdp(u8localFISA_facRich_C);
  }
}


/*==============================================================================
** Name: Delay1_Boolean
** Description: permet de cree un retard de 1
**------------------------------------------------------------------------------
** IN:
** Boolean *current_value : valeur courante de l'entree
** Boolean *delay1 : valeur avec un retard de 1
**------------------------------------------------------------------------------
** OUT:
** Boolean : nouvelle valeur avec le retard de 1
**
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

FUNC(Boolean,FISA_CODE) Delay1_Boolean ( P2CONST(Boolean, FISA_APPL_DATA, AUTOMATIC) current_value,
                P2VAR(Boolean, FISA_APPL_DATA, AUTOMATIC) delay1)
{
  VAR(Boolean,AUTOMATIC) output;

  if (delay1 && current_value)
  {
    output = *delay1;           /*l'ancien retard de 1 est mis dans la valeur de retour*/
    *delay1 = *current_value;   /*le retard de 1 prend la valeur courante*/
  }
  else
  {
    FISA_erreur(FISA_ERREUR_NULL_POINTER);
    output = 0;
  }

  return output;
}


/*==============================================================================
** Name: Delay1_SInt16
** Description: permet de cree un retard de 1
**------------------------------------------------------------------------------
** IN:
** SInt16 *current_value : valeur courante de l'entree
** SInt16 *delay1 : valeur avec un retard de 1
**------------------------------------------------------------------------------
** OUT:
** SInt16 : nouvelle valeur avec le retard de 1
**
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

FUNC(SInt16,FISA_CODE) Delay1_SINT16(  P2CONST(SInt16, FISA_APPL_DATA, AUTOMATIC) current_value,
                  P2VAR(SInt16, FISA_APPL_DATA, AUTOMATIC) delay1)
{
  VAR(SInt16,AUTOMATIC) output;

  if (delay1 && current_value)
  {
    output = *delay1;           /*l'ancien retard de 1 est mis dans la valeur de retour*/
    *delay1 = *current_value;   /*le retard de 1 prend la valeur courante*/
  }
  else
  {
    FISA_erreur(FISA_ERREUR_NULL_POINTER);
    output = 0;
  }
  return output;
}

/*==============================================================================
** Name: Delay1_UInt16
** Description: permet de cree un retard de 1
**------------------------------------------------------------------------------
** IN:
** UInt16 *current_value : valeur courante de l'entree
** UInt16 *delay1 : valeur avec un retard de 1
**------------------------------------------------------------------------------
** OUT:
** UInt16 : nouvelle valeur avec le retard de 1
**
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

FUNC(UInt16,FISA_CODE) Delay1_UINT16(  P2CONST(UInt16, FISA_APPL_DATA, AUTOMATIC) current_value,
                  P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) delay1)
{
  VAR(UInt16,AUTOMATIC) output;

  if (delay1 && current_value)
  {
    output = *delay1;           /*l'ancien retard de 1 est mis dans la valeur de retour*/
    *delay1 = *current_value;   /*le retard de 1 prend la valeur courante*/
  }
  else
  {
    FISA_erreur(FISA_ERREUR_NULL_POINTER);
    output = 0;
  }
  return output;
}

/*==============================================================================
** Name: FISA_MAX
** Description: retourne la plus grande des deux valeurs d'entree
**------------------------------------------------------------------------------
** IN:
** SInt32 Value1 : premiere valeur
** SInt32 Value2 : seconde valeur
**------------------------------------------------------------------------------
** OUT:
** SInt32 Output : la plus grande des deux valeurs d'entree
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

FUNC(SInt32,FISA_CODE) FISA_MAX (SInt32 Value1, SInt32 Value2)
{
  VAR(SInt32,AUTOMATIC) output;

  if ( Value1 >= Value2 ) /*Si Value1 est superieur ou egale a Value2 on retourne Value1*/
  {
    output = Value1;
  }
  else
  {
    output = Value2;
  }
  return output;
}

/*==============================================================================
** Name: FISA_MIN
** Description: retourne la plus petite des deux valeurs d'entree
**------------------------------------------------------------------------------
** IN:
** SInt32 Value1 : premiere valeur
** SInt32 Value2 : seconde valeur
**------------------------------------------------------------------------------
** OUT:
** SInt32 Output : la plus petite des deux valeurs d'entree
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

FUNC(SInt32,FISA_CODE) FISA_MIN (SInt32 Value1, SInt32 Value2)
{
  VAR(SInt32,AUTOMATIC) output;

  if ( Value1 <= Value2 ) /*Si Value1 est inferieure ou egale a Value2 on retourne Value1*/
  {
    output = Value1;
  }
  else
  {
    output = Value2;
  }
  return output;
}

/*==============================================================================
** Name: FISA_UMIN16
** Description: retourne la plus petite des deux valeurs d'entree
**------------------------------------------------------------------------------
** IN:
** UInt16 Value1 : premiere valeur
** UInt16 Value2 : seconde valeur
**------------------------------------------------------------------------------
** OUT:
** UInt16 Output : la plus petite des deux valeurs d'entree
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

_STATIC_ FUNC(UInt16,FISA_CODE) FISA_UMIN16 (UInt16 Value1, UInt16 Value2)
{
  VAR(UInt16,AUTOMATIC) output;

  if ( Value1 <= Value2 ) /*Si Value1 est inferieure ou egale a Value2 on retourne Value1*/
  {
    output = Value1;
  }
  else
  {
    output = Value2;
  }
  return output;
}

/*==============================================================================
** Name: FISA_MIN16
** Description: retourne la plus petite des deux valeurs d'entree
**------------------------------------------------------------------------------
** IN:
** SInt16 Value1 : premiere valeur
** SInt16 Value2 : seconde valeur
**------------------------------------------------------------------------------
** OUT:
** SInt16 Output : la plus petite des deux valeurs d'entree
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

FUNC(SInt16,FISA_CODE) FISA_MIN16 (SInt16 Value1, SInt16 Value2)
{
  VAR(SInt16,AUTOMATIC) output;

  if ( Value1 <= Value2 ) /*Si Value1 est inferieure ou egale a Value2 on retourne Value1*/
  {
    output = Value1;
  }
  else
  {
    output = Value2;
  }
  return output;
}

/*==============================================================================
** Name: FISA_MIN_8_16
** Description: retourne la plus petite des deux valeurs d'entree
**------------------------------------------------------------------------------
** IN:
** SInt16 Value1 : premiere valeur
** SInt16 Value2 : seconde valeur
**------------------------------------------------------------------------------
** OUT:
** SInt8 Output : la plus petite des deux valeurs d'entree
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

_STATIC_ FUNC(SInt8,FISA_CODE) FISA_MIN_8_16 (SInt16 Value1, SInt16 Value2)
{
  VAR(SInt8,AUTOMATIC) output;

  if ( Value1 <= Value2 ) /*Si Value1 est inferieure ou egale a Value2 on retourne Value1*/
  {
    output = (SInt8)Value1;
  }
  else
  {
    output = (SInt8)Value2;
  }
  return output;
}


/*==============================================================================
** Name: FISA_UMAX
** Description: retourne la plus grande des deux valeurs d'entree, en non signe
**------------------------------------------------------------------------------
** IN:
** UInt32 Value1 : premiere valeur
** UInt32 Value2 : seconde valeur
**------------------------------------------------------------------------------
** OUT:
** UInt32 Output : la plus grande des deux valeurs d'entree
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

FUNC(UInt32,FISA_CODE) FISA_UMAX (UInt32 Value1, UInt32 Value2)
{
  VAR(UInt32,AUTOMATIC) output;

  if ( Value1 >= Value2 ) /*Si Value1 est superieur ou egale a Value2 on retourne Value1*/
  {
    output = Value1;
  }
  else
  {
    output = Value2;
  }

  return (output);
}

/*==============================================================================
** Name: FISA_U8MAX
** Description: retourne la plus grande des deux valeurs d'entree, en non signe
**------------------------------------------------------------------------------
** IN:
** UInt8 Value1 : premiere valeur
** UInt8 Value2 : seconde valeur
**------------------------------------------------------------------------------
** OUT:
** UInt8 Output : la plus grande des deux valeurs d'entree
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

FUNC(UInt8,FISA_CODE) FISA_U8MAX (UInt8 Value1, UInt8 Value2)
{
  VAR(UInt8,AUTOMATIC) output;

  if ( Value1 >= Value2 ) /*Si Value1 est superieur ou egale a Value2 on retourne Value1*/
  {
    output = Value1;
  }
  else
  {
    output = Value2;
  }

  return (output);
}

/*==============================================================================
** Name: FISA_U16MAX
** Description: retourne la plus grande des deux valeurs d'entree, en non signe
**------------------------------------------------------------------------------
** IN:
** UInt16 Value1 : premiere valeur
** UInt16 Value2 : seconde valeur
**------------------------------------------------------------------------------
** OUT:
** UInt16 Output : la plus grande des deux valeurs d'entree
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

FUNC(UInt16,FISA_CODE) FISA_U16MAX (UInt16 Value1, UInt16 Value2)
{
  VAR(UInt16,AUTOMATIC) output;

  if ( Value1 >= Value2 ) /*Si Value1 est superieur ou egale a Value2 on retourne Value1*/
  {
    output = Value1;
  }
  else
  {
    output = Value2;
  }

  return (output);
}


/*==============================================================================
** Name: FISA_UMAX
** Description: retourne la plus grande des deux valeurs d'entree, en non signe
**------------------------------------------------------------------------------
** IN:
** SInt16 Value1 : premiere valeur
** SInt16 Value2 : seconde valeur
**------------------------------------------------------------------------------
** OUT:
** SInt8 Output : la plus grande des deux valeurs d'entree
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

_STATIC_ FUNC(SInt8,FISA_CODE) FISA_MAX_8_16 (SInt16 Value1, SInt16 Value2)
{
  VAR(SInt8,AUTOMATIC) output;

  if ( Value1 >= Value2 ) /*Si Value1 est superieur ou egale a Value2 on retourne Value1*/
  {
    output = (SInt8)Value1;
  }
  else
  {
    output = (SInt8)Value2;
  }

  return (output);
}

/*==============================================================================
** Name: FISA_UMIN
** Description: retourne la plus petite des deux valeurs d'entree, en non signe
**------------------------------------------------------------------------------
** IN:
** UInt32 Value1 : premiere valeur
** UInt32 Value2 : seconde valeur
**------------------------------------------------------------------------------
** OUT:
** UInt32 Output : la plus petite des deux valeurs d'entree
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

FUNC(UInt32,FISA_CODE) FISA_UMIN (UInt32 Value1, UInt32 Value2)
{
  VAR(UInt32,AUTOMATIC) output;

  if ( Value1 <= Value2 ) /*Si Value1 est inferieure ou egale a Value2 on retourne Value1*/
  {
    output = Value1;
  }
  else
  {
    output = Value2;
  }

    return (output);
}

/*==============================================================================
** Name: FISA_U8MIN
** Description: retourne la plus petite des deux valeurs d'entree, en non signe
**------------------------------------------------------------------------------
** IN:
** UInt8 Value1 : premiere valeur
** UInt8 Value2 : seconde valeur
**------------------------------------------------------------------------------
** OUT:
** UInt8 Output : la plus petite des deux valeurs d'entree
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

FUNC(UInt8,FISA_CODE) FISA_U8MIN (UInt8 Value1, UInt8 Value2)
{
  VAR(UInt8,AUTOMATIC) output;

  if ( Value1 <= Value2 ) /*Si Value1 est inferieure ou egale a Value2 on retourne Value1*/
  {
    output = Value1;
  }
  else
  {
    output = Value2;
  }
  return output;
}

/*==============================================================================
** Name: Accum_Sat_Analisys_without_FIX
** Description: permet de calculer le delta du coefficient d'entree
**------------------------------------------------------------------------------
** IN:
** SInt16 Inc : valeur du coefficient en entree (mantisse)
** Boolean On : autorisation du calcul
** SInt16 Min : valeur minimale de la saturation (mantisse)
** SInt16 Max : valeur maximale de la saturation (mantisse)
** SInt16 *Mem : valeur du retard de 1
** Boolean firstTime :
**------------------------------------------------------------------------------
** OUT:
** SInt16 :
**
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

FUNC(SInt16,FISA_CODE) Accum_Sat_Analisys_without_FIX ( SInt16 Inc, Boolean On, SInt16 Min, SInt16 Max, P2VAR(SInt16, FISA_APPL_DATA, AUTOMATIC) Mem, Boolean firstTime)
{
  VAR(SInt16,AUTOMATIC) output;             /*sortie de la fonction*/

  if (!Mem)
  {
    FISA_erreur(FISA_ERREUR_NULL_POINTER);
    output = 0;
  }
  else
  {
    if ( On != 0) /* si On == 1*/
    {
      Inc = (SInt16) (Inc + *Mem);      /*addition de la valeur courante avec l'ancienne*/

      output = (SInt16) Saturation_INT((SInt32)Inc,(SInt32)Max,(SInt32)Min);
    }
    else /*si On == 0*/
    {
      output = (SInt16) Saturation_INT((SInt32)(*Mem),(SInt32)Max,(SInt32)Min);
    }

    if (TRUE == firstTime)
    {
      *Mem = 0;
    }
    else
    {
      *Mem = output ;
    }
  }

  return output;
}

/*==============================================================================
** Name: Saturation_tout_FIX
** Description: permet de limiter la valeur d'entree entre les deux valeurs Min et Max
**------------------------------------------------------------------------------
** IN:
** ts_fixed *Value_f : pointeur sur l'entre en fixed
** ts_fixed *Max_f : pointeur sur la valeur maximale de la saturation en fixed
** ts_fixed *Min_f : pointeur sur la valeur minimale de la saturation en fixed
** SInt16 output_exp : precision de la sortie (utlisee pour passer de fixe en SInt32)
**------------------------------------------------------------------------------
** OUT:
** SInt32 value_returned : valeur de sortie saturee (ou non) entre Min et Max
**
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

FUNC(SInt32,FISA_CODE) Saturation_tout_FIX (P2CONST(ts_fixed, FISA_APPL_DATA, AUTOMATIC) Value_f,
                                       P2CONST(ts_fixed, FISA_APPL_DATA, AUTOMATIC) Max_f,
                                       P2CONST(ts_fixed, FISA_APPL_DATA, AUTOMATIC) Min_f, SInt16 output_exp)
{
  VAR(SInt32,AUTOMATIC)   value_returned;         /*valeur saturee (ou non) retounree par la fonction*/
  VAR(ts_fixed,AUTOMATIC) tmp;
  VAR(ts_fixed,AUTOMATIC) Middle_value_f;

  if ((Value_f != 0) && (Max_f!=0) && (Min_f!=0))
  {
    MIN_FIX ((*Value_f), (*Max_f), &Middle_value_f); /*retourne la plus petite des deux valeurs d'entree*/
    MAX_FIX (Middle_value_f, (*Min_f), &tmp);        /*retourne la plus grande des deux valeurs d'entree*/

    value_returned = fixed_to_S32(&tmp, output_exp);
  }
  else
  {
    FISA_erreur(FISA_ERREUR_NULL_POINTER);
    value_returned=0;
  }

  return value_returned;
}

/*==============================================================================
** Name: Saturation_FIX
** Description: permet de limiter la valeur d'entree entre les deux valeurs Min et Max
**------------------------------------------------------------------------------
** IN:
** ts_fixed *Value_f : pointeur sur l'entre en fixed
** SInt32 Max_man : valeur maximale de la saturation (mantisse)
** SInt16 Max_exp : precision de Max (exposant)
** SInt32 Min_man : valeur minimale de la saturation (mantisse)
** SInt16 Min_exp : precision de Min (exposant)
**------------------------------------------------------------------------------
** OUT:
** SInt32 value_returned : valeur de sortie saturee (ou non) entre Min et Max
**
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

FUNC(SInt32,FISA_CODE) Saturation_FIX (P2CONST(ts_fixed, FISA_APPL_DATA, AUTOMATIC) Value_f, SInt32 Max_man, SInt16 Max_exp, SInt32 Min_man , SInt16 Min_exp )
{
  VAR(SInt32,AUTOMATIC)   value_returned;         /*valeur saturee (ou non) retournee par la fonction*/
  VAR(ts_fixed,AUTOMATIC) Min_f;
  VAR(ts_fixed,AUTOMATIC) Max_f;
  VAR(ts_fixed,AUTOMATIC) tmp;
  VAR(ts_fixed,AUTOMATIC) Middle_value_f;

  if (Value_f != 0)
  {
    /*Mise en fixe des variables*/
    S32_to_fixed(Min_man, Min_exp, &Min_f);
    S32_to_fixed(Max_man, Max_exp, &Max_f);

    MIN_FIX ((*Value_f), Max_f, &Middle_value_f); /*retourne la plus petite des deux valeurs d'entree*/
    MAX_FIX (Middle_value_f, Min_f, &tmp);        /*retourne la plus grande des deux valeurs d'entree*/

    value_returned = fixed_to_S32(&tmp, Value_f->exposant);
  }
  else
  {
    FISA_erreur(FISA_ERREUR_NULL_POINTER);
    value_returned=0;
  }

  return value_returned;
}

/*==============================================================================
** Name: DivWithAntiDiVByZero
** Description: division (on empeche la division par zero en remplacant la valeur du diviseur par epsilon le cas echeant)
**------------------------------------------------------------------------------
** IN:
** SInt32 dividend_man : valeur du dividende (mantisse)
** SInt16 dividend_exp : precision du dividende (exposant)
** SInt32 divisor_man : valeur du diviseur (mantisse)
** SInt16 divisor_exp : precision du diviseur (exposant)
** SInt16 output_exp : precision de la sortie (utlisee pour passer de fixe en SInt32)
**------------------------------------------------------------------------------
** OUT:
** SInt32 value_returned : valeur de la division
**
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

FUNC(SInt32,FISA_CODE) DivWithAntiDiVByZero(SInt32 dividend_man, SInt16 dividend_exp , SInt32 divisor_man, SInt16 divisor_exp , SInt16 output_exp)
{
  VAR(SInt32,AUTOMATIC)   value_returned; /*resultat de la division*/

  /*declaration des structures utilsees pour le travail en fixe*/
  VAR(ts_fixed,AUTOMATIC) divisor_f;
  VAR(ts_fixed,AUTOMATIC) dividend_f;
  VAR(ts_fixed,AUTOMATIC) result_f;

  if (0 != dividend_man)
  {
    /*transformation en fixe du dividend et du diviseur*/
    S32_to_fixed(dividend_man, dividend_exp, &dividend_f);
    S32_to_fixed(divisor_man, divisor_exp, &divisor_f);

    if ( 0 == divisor_f.mantisse )/*si le diviseur est nul on le remplace par epsilon*/
    {
      if (dividend_man<0)
      {
        value_returned = MINSLONG;
      }
      else
      {
        value_returned = MAXSLONG;
      }
    }
    else
    {
      /*appel de la fonction de division en fixe*/
      DIV_FIX(dividend_f, divisor_f, &result_f);
      value_returned = fixed_to_S32(&result_f, output_exp);/*la valeur de sortie est passee de fixe en SInt32*/
    }
  }
  else
  {
    value_returned = 0;
  }
  return (value_returned);
}

/*==============================================================================
** Name: DivWithAntiDiVByZeroFix
** Description: division (on empeche la division par zero en remplacant la valeur du diviseur par epsilon le cas echeant)
**------------------------------------------------------------------------------
** IN:
** SInt32 dividend_man : valeur du dividende (mantisse)
** SInt16 dividend_exp : precision du dividende (exposant)
** SInt32 divisor_man : valeur du diviseur (mantisse)
** SInt16 divisor_exp : precision du diviseur (exposant)
** ts_fixed *result_f
**------------------------------------------------------------------------------
** OUT:
**
**
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

FUNC(void,FISA_CODE) DivWithAntiDiVByZeroFix(SInt32 dividend_man, SInt16 dividend_exp , SInt32 divisor_man, SInt16 divisor_exp , ts_fixed *result_f)
{
  /*declaration des structures utilisees pour le travail en fixe*/
  VAR(ts_fixed,AUTOMATIC) divisor_f;
  VAR(ts_fixed,AUTOMATIC) dividend_f;

  if (result_f!=0)
  {
    if (0 != dividend_man)
    {
      /*transformation en fixe du dividende et du diviseur*/
      S32_to_fixed(dividend_man, dividend_exp, &dividend_f);
      S32_to_fixed(divisor_man, divisor_exp, &divisor_f);

      if ( 0 == divisor_f.mantisse )/*si le diviseur est nul on le remplace par epsilon*/
      {
        divisor_f.sign = SIGNE_PLUS;
        divisor_f.mantisse = FISA_epsilon;
        divisor_f.exposant = FISA_EPSILON_EXP;
      }
      /*appel de la fonction de division en fixe*/
      DIV_FIX(dividend_f, divisor_f, result_f);
    }
    else
    {
       result_f->mantisse = 0;
    }
  }
}

/*==============================================================================
** Name: Saturation_INT
** Description: permet de limiter la valeur d'entree entre les deux valeurs Min et Max
**------------------------------------------------------------------------------
** IN:
** SInt32 Value : valeur d'entree qui sera saturee le cas echeant
** SInt32 Max : valeur Maximale de saturation
** SInt32 Min : valeur Minimale de saturation
**------------------------------------------------------------------------------
** OUT:
** SInt32 value_returned : valeur de sortie saturee (ou non) entre Min et Max
**
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/* !Trace_To : GEENSYS_EXI_CODE_RES_SATURATION_INT                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/


FUNC(SInt32,FISA_CODE) Saturation_INT (SInt32 Value, SInt32 Max, SInt32 Min)
{
  VAR(SInt32,AUTOMATIC) value_returned;

  value_returned = FISA_MIN ( Value , Max ); /*retourne la plus petite des deux valeurs*/
  value_returned = FISA_MAX ( value_returned , Min ); /*retourne la plus grande des deux valeurs*/

  return (value_returned);
}

/*==============================================================================
** Name: Saturation_INT_S8
** Description: permet de limiter la valeur d'entree entre les deux valeurs Min et Max
**------------------------------------------------------------------------------
** IN:
** SInt16 Value : valeur d'entree qui sera saturee le cas echeant
** SInt16 Max : valeur Maximale de saturation
** SInt16 Min : valeur Minimale de saturation
**------------------------------------------------------------------------------
** OUT:
** SInt8 value_returned : valeur de sortie saturee (ou non) entre Min et Max
**
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/* !Trace_To : GEENSYS_EXI_CODE_RES_SATURATION_INT                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/



FUNC(SInt8,FISA_CODE) Saturation_INT_S8 (SInt16 Value, SInt16 Max, SInt16 Min)
{
  VAR(SInt8,AUTOMATIC) value_returned;

  value_returned = FISA_MIN_8_16 ( Value , Max ); /*retourne la plus petite des deux valeurs*/
  value_returned = FISA_MAX_8_16 ( (SInt16) value_returned , Min ); /*retourne la plus grande des deux valeurs*/

  return (value_returned);
}

/*==============================================================================
** Name: Saturation_INT_U8
** Description: permet de limiter la valeur d'entree entre les deux valeurs Min et Max
**------------------------------------------------------------------------------
** IN:
** UInt8 Value : valeur d'entree qui sera saturee le cas echeant
** UInt8 Max : valeur Maximale de saturation
** UInt8 Min : valeur Minimale de saturation
**------------------------------------------------------------------------------
** OUT:
** UInt8 value_returned : valeur de sortie saturee (ou non) entre Min et Max
**
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/* !Trace_To : GEENSYS_EXI_CODE_RES_SATURATION_INT                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/


FUNC(UInt8,FISA_CODE) Saturation_INT_U8 (UInt8 Value, UInt8 Max, UInt8 Min)
{
  VAR(UInt8,AUTOMATIC) value_returned;

  value_returned = FISA_U8MIN ( Value , Max ); /*retourne la plus petite des deux valeurs*/
  value_returned = FISA_U8MAX ( value_returned , Min ); /*retourne la plus grande des deux valeurs*/

  return (value_returned);
}

/*==============================================================================
** Name: Saturation_INT_U16
** Description: permet de limiter la valeur d'entree entre les deux valeurs Min et Max
**------------------------------------------------------------------------------
** IN:
** UInt16 Value : valeur d'entree qui sera saturee le cas echeant
** UInt16 Max : valeur Maximale de saturation
** UInt16 Min : valeur Minimale de saturation
**------------------------------------------------------------------------------
** OUT:
** UInt16 value_returned : valeur de sortie saturee (ou non) entre Min et Max
**
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/* !Trace_To : GEENSYS_EXI_CODE_RES_SATURATION_INT                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/


FUNC(UInt16,FISA_CODE) Saturation_INT_U16 (UInt16 Value, UInt16 Max, UInt16 Min)
{
  VAR(UInt16,AUTOMATIC) value_returned;

  value_returned = FISA_UMIN16 ( Value , Max ); /*retourne la plus petite des deux valeurs*/
  value_returned = FISA_U16MAX ( value_returned , Min ); /*retourne la plus grande des deux valeurs*/

  return (value_returned);
}

/*==============================================================================
** Name: lookup2D
** Description:
**------------------------------------------------------------------------------
** IN:
** const MAP_Table_2D *map
** SInt16 x
** SInt16 y
** UInt16 *local_xLow
** UInt16 *local_yLow
** SInt16 fm
**------------------------------------------------------------------------------
** OUT:
** SInt16 valeur_sortie : valeur de sortie
**
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

FUNC(SInt16,FISA_CODE) lookup2D(P2CONST(MAP_Table_2D, FISA_APPL_DATA, AUTOMATIC) map,
                SInt16 x, SInt16 y,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_xLow,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_yLow,
                SInt16 fm)
{
   /*Default storage class for local variables | Width: 16 */
   VAR(SInt16,AUTOMATIC)                      val_sat_X;
   VAR(SInt16,AUTOMATIC)                      val_sat_Y;
   VAR(SInt16,AUTOMATIC)                      diff_Y_avant;
   VAR(SInt16,AUTOMATIC)                      diff_X_avant;
   VAR(SInt16,AUTOMATIC)                      diff_Y_apres;
   VAR(SInt16,AUTOMATIC)                      diff_X_apres;
   VAR(SInt16,AUTOMATIC)                      somme_diff;
   VAR(SInt16,AUTOMATIC)                      valeur_sortie1;
   VAR(SInt16,AUTOMATIC)                      valeur_sortie2;
   VAR(SInt16,AUTOMATIC)                      valeur_sortie;

   /*Default storage class for local variables | Width: 16 */
   VAR(UInt16,AUTOMATIC)                      nb_entree_Y;

   /*Default storage class for local variables | Width: 16 */
   P2CONST(SInt16, FISA_APPL_DATA, AUTOMATIC) x_table_v;
   P2CONST(SInt16, FISA_APPL_DATA, AUTOMATIC) y_table_v;
   P2CONST(SInt16, FISA_APPL_DATA, AUTOMATIC) z_table_v;
   VAR(UInt16,AUTOMATIC)                      x_index;
   VAR(UInt16,AUTOMATIC)                      y_index;
   VAR(UInt16,AUTOMATIC)                      z_index;

   if ((NULL_PTR != (const void*)map) && (NULL_PTR != (void*)local_xLow) && (NULL_PTR != (void*)local_yLow))
   {
     x_table_v = map->x_table;
     y_table_v = map->y_table;
     z_table_v = map->z_table;
     nb_entree_Y  = (UInt16)map->Ny;

     if ((NULL_PTR != (const void*)x_table_v) && (NULL_PTR != (const void*)y_table_v) && (NULL_PTR != (const void*)z_table_v))
     {
       x_index = 0;
       y_index = 0;
       z_index = 0;

       /* Saturation. */
       if (x < x_table_v[x_index])
       {
          x = x_table_v[x_index];
       }
       val_sat_X = x_table_v[ map->Nx - 1];
       if (x > val_sat_X)
       {
          x = val_sat_X;
       }
       x_index = (UInt16) ( x_index + *(local_xLow) );

       /* Local search. */
       if (x < x_table_v[x_index])
       {
          /* Search algorithm for row axis.
             Linear search, start high. */
          do
          {
             (*(local_xLow))--;
             x_index--;
          }
          while (x < x_table_v[x_index]);
       }
       else
       {
          /* Search algorithm for row axis. */
          x_index++;

          /* Linear search, start low. */
          while (x > x_table_v[x_index])
          {
            x_index++;
            (*(local_xLow))++;
          }
          x_index--;
       }
       z_index = (UInt16) (z_index + (nb_entree_Y * (*(local_xLow))) );

       /* Saturation. */
       if (y < y_table_v[y_index])
       {
          y = y_table_v[y_index];
       }
       val_sat_Y = y_table_v[nb_entree_Y - 1];
       if (y > val_sat_Y)
       {
          y = val_sat_Y;
       }
       y_index = (UInt16) ( y_index + *(local_yLow) );

       /* Local search. */
       if (y < y_table_v[y_index])
       {
          /* Search algorithm for column axis.
             Linear search, start high. */
          do
          {
             (*(local_yLow))--;
             y_index--;
          }
          while (y < y_table_v[y_index]);
       }
       else
       {
          /* Search algorithm for column axis. */
          y_index++;

          /* Linear search, start low. */
          while (y > y_table_v[y_index])
          {
             y_index++;
             (*(local_yLow))++;
          }
          y_index--;
       }
       z_index = (UInt16) ( z_index + *(local_yLow) );

       /* Differences in column axis. */
       diff_Y_avant = (SInt16) ( y - y_table_v[y_index] );
       diff_Y_apres = (SInt16) ( y_table_v[y_index+1] - y );
       somme_diff = (SInt16) (diff_Y_avant + diff_Y_apres);

       /* Interpolation. */
       if (0  == somme_diff)
       {
          valeur_sortie1 = (SInt16) ( z_table_v[z_index]*fm );
          valeur_sortie2 = (SInt16) ( z_table_v[nb_entree_Y]*fm );
       }
       else
       {
          /* 1. Y-Interpolation. */
          valeur_sortie1 = (SInt16) (( ( (((SInt32) diff_Y_apres) * ((SInt32) (z_table_v[z_index]*fm)))) + ((SInt32)
           (((SInt32) diff_Y_avant) * ((SInt32) (z_table_v[z_index+1]*fm))))) / (SInt32)somme_diff);
          z_index = (UInt16) (z_index + nb_entree_Y);

          /* 2. Y-Interpolation. */
          valeur_sortie2 = (SInt16)  (( ( (((SInt32) diff_Y_apres) * ((SInt32) (z_table_v[z_index]*fm)))) + ((SInt32)
           (((SInt32) diff_Y_avant) * ((SInt32) (z_table_v[z_index+1]*fm))))) / (SInt32)somme_diff);
       }

       /* Differences in row axis. */
       diff_X_avant = (SInt16) ( x - x_table_v[x_index] );
       diff_X_apres = (SInt16) ( x_table_v[x_index+1] - x_table_v[x_index] );
       if (diff_X_apres != 0)
       {
          if (valeur_sortie1 < valeur_sortie2)
          {
             /* Positive slope. */
             valeur_sortie = (SInt16) ( valeur_sortie1 + (SInt16) ((((SInt32) (valeur_sortie2 - valeur_sortie1)) * ((SInt32) diff_X_avant))
             / (SInt32)diff_X_apres) );
          }
          else
          {
             /* Negative slope. */
             valeur_sortie = (SInt16) ( valeur_sortie1 - (SInt16) ((((SInt32) (valeur_sortie1 - valeur_sortie2)) * ((SInt32) diff_X_avant))
              / (SInt32)diff_X_apres) );
          }
       }
       else
       {
         valeur_sortie = (SInt16) ( (valeur_sortie1+valeur_sortie2)/2 );
       }
     }
     else
     {
        FISA_erreur(FISA_ERREUR_NULL_POINTER);
        valeur_sortie =  0;
     }
   }
   else
   {
     FISA_erreur(FISA_ERREUR_NULL_POINTER);
     valeur_sortie =  0;
   }
   return valeur_sortie;
}


/*==============================================================================
** Name: lookup2D_yU16_S16
** Description:
**------------------------------------------------------------------------------
** IN:
** const MAP_Table_2D_yU16_S16 *map
** SInt16 x
** UInt16 y
** UInt16 *local_xLow
** UInt16 *local_yLow
** SInt16 fm
**------------------------------------------------------------------------------
** OUT:
** SInt16 valeur_sortie : valeur de sortie
**
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

FUNC(SInt16,FISA_CODE) lookup2D_yU16_S16(P2CONST(MAP_Table_2D_yU16_S16, FISA_APPL_DATA, AUTOMATIC) map,
                SInt16 x, UInt16 y,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_xLow,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_yLow,
                SInt16 fm)
{
   /*Default storage class for local variables | Width: 16 */
   VAR(SInt16,AUTOMATIC)                      val_sat_X;
   VAR(UInt16,AUTOMATIC)                      val_sat_Y;
   VAR(UInt16,AUTOMATIC)                      diff_Y_avant;
   VAR(SInt16,AUTOMATIC)                      diff_X_avant;
   VAR(UInt16,AUTOMATIC)                      diff_Y_apres;
   VAR(SInt16,AUTOMATIC)                      diff_X_apres;
   VAR(UInt16,AUTOMATIC)                      somme_diff;
   VAR(SInt16,AUTOMATIC)                      valeur_sortie1;
   VAR(SInt16,AUTOMATIC)                      valeur_sortie2;
   VAR(SInt16,AUTOMATIC)                      valeur_sortie;

   /*Default storage class for local variables | Width: 16 */
   VAR(UInt16,AUTOMATIC)                      nb_entree_Y;

   /*Default storage class for local variables | Width: 16 */
   P2CONST(SInt16, FISA_APPL_DATA, AUTOMATIC) x_table_v;
   P2CONST(UInt16, FISA_APPL_DATA, AUTOMATIC) y_table_v;
   P2CONST(SInt16, FISA_APPL_DATA, AUTOMATIC) z_table_v;
   VAR(UInt16,AUTOMATIC)                      x_index;
   VAR(UInt16,AUTOMATIC)                      y_index;
   VAR(UInt16,AUTOMATIC)                      z_index;

   if ((NULL_PTR != (const void*)map) && (NULL_PTR != (void*)local_xLow) && (NULL_PTR != (void*)local_yLow))
   {
     x_table_v = map->x_table;
     y_table_v = map->y_table;
     z_table_v = map->z_table;
     nb_entree_Y  = (UInt16)map->Ny;

     if ((NULL_PTR != (const void*)x_table_v) && (NULL_PTR != (const void*)y_table_v) && (NULL_PTR != (const void*)z_table_v))
     {
       x_index = 0;
       y_index = 0;
       z_index = 0;

       /* Saturation. */
       if (x < x_table_v[x_index])
       {
          x = x_table_v[x_index];
       }
       val_sat_X = x_table_v[ map->Nx - 1];
       if (x > val_sat_X)
       {
          x = val_sat_X;
       }
       x_index = (UInt16) ( x_index + *(local_xLow) );

       /* Local search. */
       if (x < x_table_v[x_index])
       {
          /* Search algorithm for row axis.
             Linear search, start high. */
          do
          {
             (*(local_xLow))--;
             x_index--;
          }
          while (x < x_table_v[x_index]);
       }
       else
       {
          /* Search algorithm for row axis. */
          x_index++;

          /* Linear search, start low. */
          while (x > x_table_v[x_index])
          {
            x_index++;
            (*(local_xLow))++;
          }
          x_index--;
       }
       z_index =  (UInt16) (z_index + (nb_entree_Y * (*(local_xLow))) );

       /* Saturation. */
       if (y < y_table_v[y_index])
       {
          y = y_table_v[y_index];
       }
       val_sat_Y = y_table_v[nb_entree_Y - 1];
       if (y > val_sat_Y)
       {
          y = val_sat_Y;
       }
       y_index = (UInt16) (y_index + *(local_yLow));

       /* Local search. */
       if (y < y_table_v[y_index])
       {
          /* Search algorithm for column axis.
             Linear search, start high. */
          do
          {
             (*(local_yLow))--;
             y_index--;
          }
          while (y < y_table_v[y_index]);
       }
       else
       {
          /* Search algorithm for column axis. */
          y_index++;

          /* Linear search, start low. */
          while (y > y_table_v[y_index])
          {
             y_index++;
             (*(local_yLow))++;
          }
          y_index--;
       }
       z_index = (UInt16) (z_index + *(local_yLow));

       /* Differences in column axis. */
       diff_Y_avant = (UInt16) ( y - y_table_v[y_index] );
       diff_Y_apres = (UInt16) ( y_table_v[y_index+1] - y );
       somme_diff = (UInt16) (diff_Y_avant + diff_Y_apres);

       /* Interpolation. */
       if (0  == somme_diff)
       {
          valeur_sortie1 = (SInt16) ( z_table_v[z_index]*fm );
          valeur_sortie2 = (SInt16) ( z_table_v[nb_entree_Y]*fm );
       }
       else
       {
          /* 1. Y-Interpolation. */
          valeur_sortie1 = (SInt16) (( ( (((SInt32) diff_Y_apres) * ((SInt32) (z_table_v[z_index]*fm)))) + ((SInt32)
           (((SInt32) diff_Y_avant) * ((SInt32) (z_table_v[z_index+1]*fm))))) / (SInt32)somme_diff);
          z_index = (UInt16) (z_index + nb_entree_Y);

          /* 2. Y-Interpolation. */
          valeur_sortie2 = (SInt16)  (( ( (((SInt32) diff_Y_apres) * ((SInt32) (z_table_v[z_index]*fm)))) + ((SInt32)
           (((SInt32) diff_Y_avant) * ((SInt32) (z_table_v[z_index+1]*fm))))) / (SInt32)somme_diff);
       }

       /* Differences in row axis. */
       diff_X_avant = (SInt16) ( x - x_table_v[x_index] );
       diff_X_apres = (SInt16) ( x_table_v[x_index+1] - x_table_v[x_index] );
       if (diff_X_apres != 0)
       {
          if (valeur_sortie1 < valeur_sortie2)
          {
             /* Positive slope. */
             valeur_sortie = (SInt16) ( valeur_sortie1 + (SInt16) ((((SInt32) (valeur_sortie2 - valeur_sortie1)) * ((SInt32) diff_X_avant))
              / (SInt32)diff_X_apres) );
          }
          else
          {
             /* Negative slope. */
             valeur_sortie = (SInt16) ( valeur_sortie1 - (SInt16) ((((SInt32) (valeur_sortie1 - valeur_sortie2)) * ((SInt32) diff_X_avant))
              / (SInt32)diff_X_apres) );
          }
       }
       else
       {
         valeur_sortie = (SInt16) ( (valeur_sortie1+valeur_sortie2)/2 );
       }
     }
     else
     {
        FISA_erreur(FISA_ERREUR_NULL_POINTER);
        valeur_sortie =  0;
     }
   }
   else
   {
     FISA_erreur(FISA_ERREUR_NULL_POINTER);
     valeur_sortie =  0;
   }
   return valeur_sortie;
}

/*==============================================================================
** Name: lookup2D_yU16_U16
** Description:
**------------------------------------------------------------------------------
** IN:
** const MAP_Table_2D_U16 *map
** SInt16 x
** SInt16 y
** UInt16 *local_xLow
** UInt16 *local_yLow
** UInt16 fm
**------------------------------------------------------------------------------
** OUT:
** UInt16 value_returned : valeur de sortie saturee (ou non) entre Min et Max
**
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

FUNC(UInt16,FISA_CODE) lookup2D_yU16_U16(P2CONST(MAP_Table_2D_U16, FISA_APPL_DATA, AUTOMATIC) map,
                SInt16 x, UInt16 y,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_xLow,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_yLow,
                UInt16 fm)
{
   /*Default storage class for local variables | Width: 16 */
   VAR(SInt16,AUTOMATIC)                      val_sat_X;
   VAR(UInt16,AUTOMATIC)                      val_sat_Y;
   VAR(UInt16,AUTOMATIC)                      diff_Y_avant;
   VAR(SInt16,AUTOMATIC)                      diff_X_avant;
   VAR(UInt16,AUTOMATIC)                      diff_Y_apres;
   VAR(SInt16,AUTOMATIC)                      diff_X_apres;
   VAR(UInt16,AUTOMATIC)                      somme_diff; /* Sur les Y */
   VAR(UInt16,AUTOMATIC)                      valeur_sortie1;
   VAR(UInt16,AUTOMATIC)                      valeur_sortie2;
   VAR(UInt16,AUTOMATIC)                      valeur_sortie;


   /*Default storage class for local variables | Width: 16 */
   VAR(UInt16,AUTOMATIC)                      nb_entree_Y;

   /*Default storage class for local variables | Width: 16 */
   P2CONST(SInt16, FISA_APPL_DATA, AUTOMATIC) x_table_v;
   P2CONST(UInt16, FISA_APPL_DATA, AUTOMATIC) y_table_v;
   P2CONST(UInt16, FISA_APPL_DATA, AUTOMATIC) z_table_v;
   VAR(UInt16,AUTOMATIC)                      x_index;
   VAR(UInt16,AUTOMATIC)                      y_index;
   VAR(UInt16,AUTOMATIC)                      z_index;

   if ((NULL_PTR != (const void*)map) && (NULL_PTR != (void*)local_xLow) && (NULL_PTR != (void*)local_yLow))
   {
     x_table_v = map->x_table;
     y_table_v = map->y_table;
     z_table_v = map->z_table;
     nb_entree_Y  = (UInt16)map->Ny;

     if ((NULL_PTR != (const void*)x_table_v) && (NULL_PTR != (const void*)y_table_v) && (NULL_PTR != (const void*)z_table_v))
     {
       x_index = 0;
       y_index = 0;
       z_index = 0;

       /* Saturation. */
       if (x < x_table_v[x_index])
       {
          x = x_table_v[x_index];
       }
       val_sat_X = x_table_v[ map->Nx - 1];
       if (x > val_sat_X)
       {
          x = val_sat_X;
       }
       x_index = (UInt16) (x_index + *(local_xLow));

       /* Local search. */
       if (x < x_table_v[x_index])
       {
          /* Search algorithm for row axis.
             Linear search, start high. */
          do
          {
             (*(local_xLow))--;
             x_index--;
          }
          while (x < x_table_v[x_index]);
       }
       else
       {
          /* Search algorithm for row axis. */
          x_index++;

          /* Linear search, start low. */
          while (x > x_table_v[x_index])
          {
            x_index++;
            (*(local_xLow))++;
          }
          x_index--;
       }
       z_index = (UInt16) (z_index + (nb_entree_Y * (*(local_xLow))) );

       /* Saturation. */
       if (y < y_table_v[y_index])
       {
          y = y_table_v[y_index];
       }
       val_sat_Y = y_table_v[nb_entree_Y - 1];
       if (y > val_sat_Y)
       {
          y = val_sat_Y;
       }
       y_index = (UInt16) (y_index + *(local_yLow));

       /* Local search. */
       if (y < y_table_v[y_index])
       {
          /* Search algorithm for column axis.
             Linear search, start high. */
          do
          {
             (*(local_yLow))--;
             y_index--;
          }
          while (y < y_table_v[y_index]);
       }
       else
       {
          /* Search algorithm for column axis. */
          y_index++;

          /* Linear search, start low. */
          while (y > y_table_v[y_index])
          {
             y_index++;
             (*(local_yLow))++;
          }
          y_index--;
       }
       z_index = (UInt16) ( z_index + *(local_yLow) );

       /* Differences in column axis. */
       diff_Y_avant = (UInt16) ( y - y_table_v[y_index] );
       diff_Y_apres = (UInt16) ( y_table_v[y_index+1] - y );
       somme_diff = (UInt16) (diff_Y_avant + diff_Y_apres);

       /* Interpolation. */
       if (0  == somme_diff)
       {
          valeur_sortie1 = (UInt16) ( z_table_v[z_index]*fm );
          valeur_sortie2 = (UInt16) ( z_table_v[nb_entree_Y]*fm );
       }
       else
       {
          /* 1. Y-Interpolation. */
          valeur_sortie1 = (UInt16) (( ( (((UInt32) diff_Y_apres) * ((UInt32) (z_table_v[z_index]*fm)))) + ((UInt32)
           (((UInt32) diff_Y_avant) * ((UInt32) (z_table_v[z_index+1]*fm))))) / (UInt32)somme_diff);
          z_index = (UInt16) (z_index + nb_entree_Y);

          /* 2. Y-Interpolation. */
          valeur_sortie2 = (UInt16)  (( ( (((UInt32) diff_Y_apres) * ((UInt32) (z_table_v[z_index]*fm)))) + ((UInt32)
           (((UInt32) diff_Y_avant) * ((UInt32) (z_table_v[z_index+1]*fm))))) / (UInt32)somme_diff);
       }

       /* Differences in row axis. */
       diff_X_avant = (SInt16) ( x - x_table_v[x_index] );
       diff_X_apres = (SInt16) ( x_table_v[x_index+1] - x_table_v[x_index] );
       if (diff_X_apres != 0)
       {
          if (valeur_sortie1 < valeur_sortie2)
          {
             /* Positive slope. */
             valeur_sortie = (UInt16) ( valeur_sortie1 + (UInt16) ((((UInt32) (valeur_sortie2 - valeur_sortie1)) * ((UInt32) diff_X_avant))
              / (UInt32)diff_X_apres) );
             /* QAC pense qu'une division par zero est possible hors diff_X_apres est teste juste au dessus */
          }
          else
          {
             /* Negative slope. */
             valeur_sortie = (UInt16) ( valeur_sortie1 - (UInt16) ((((UInt32) (valeur_sortie1 - valeur_sortie2)) * ((UInt32) diff_X_avant))
              / (UInt32)diff_X_apres) );
             /* QAC pense qu'une division par zero est possible hors diff_X_apres est teste juste au dessus */
          }
       }
       else
       {
         valeur_sortie = (UInt16) ( (valeur_sortie1+valeur_sortie2)/2 );
       }
     }
     else
     {
        FISA_erreur(FISA_ERREUR_NULL_POINTER);
        valeur_sortie =  0;
     }
   }
   else
   {
     FISA_erreur(FISA_ERREUR_NULL_POINTER);
     valeur_sortie =  0;
   }
   return valeur_sortie;
}

/*==============================================================================
** Name: lookup2D_xyU16_U16
** Description:
**------------------------------------------------------------------------------
** IN:
** const MAP_Table_2D_xU16_U16 *map
** UInt16 x
** UInt16 y
** UInt16 *local_xLow
** UInt16 *local_yLow
** UInt16 fm
**------------------------------------------------------------------------------
** OUT:
** UInt16 value_returned : valeur de sortie saturee (ou non) entre Min et Max
**
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

FUNC(UInt16,FISA_CODE) lookup2D_xyU16_U16(P2CONST(MAP_Table_2D_xU16_U16, FISA_APPL_DATA, AUTOMATIC) map,
                UInt16 x, UInt16 y,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_xLow,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_yLow,
                UInt16 fm)
{
   /*Default storage class for local variables | Width: 16 */
   VAR(UInt16,AUTOMATIC)                      val_sat_X;
   VAR(UInt16,AUTOMATIC)                      val_sat_Y;
   VAR(UInt16,AUTOMATIC)                      diff_Y_avant;
   VAR(UInt16,AUTOMATIC)                      diff_X_avant;
   VAR(UInt16,AUTOMATIC)                      diff_Y_apres;
   VAR(UInt16,AUTOMATIC)                      diff_X_apres;
   VAR(UInt16,AUTOMATIC)                      somme_diff; /* Sur les Y */
   VAR(UInt16,AUTOMATIC)                      valeur_sortie1;
   VAR(UInt16,AUTOMATIC)                      valeur_sortie2;
   VAR(UInt16,AUTOMATIC)                      valeur_sortie;


   /*Default storage class for local variables | Width: 16 */
   VAR(UInt16,AUTOMATIC)                      nb_entree_Y;

   /*Default storage class for local variables | Width: 16 */
   P2CONST(UInt16, FISA_APPL_DATA, AUTOMATIC) x_table_v;
   P2CONST(UInt16, FISA_APPL_DATA, AUTOMATIC) y_table_v;
   P2CONST(UInt16, FISA_APPL_DATA, AUTOMATIC) z_table_v;
   VAR(UInt16,AUTOMATIC)                      x_index;
   VAR(UInt16,AUTOMATIC)                      y_index;
   VAR(UInt16,AUTOMATIC)                      z_index;

   if ((NULL_PTR != (const void*)map) && (NULL_PTR != (void*)local_xLow) && (NULL_PTR != (void*)local_yLow))
   {
     x_table_v = map->x_table;
     y_table_v = map->y_table;
     z_table_v = map->z_table;
     nb_entree_Y  = (UInt16)map->Ny;

     if ((NULL_PTR != (const void*)x_table_v) && (NULL_PTR != (const void*)y_table_v) && (NULL_PTR != (const void*)z_table_v))
     {
       x_index = 0;
       y_index = 0;
       z_index = 0;

       /* Saturation. */
       if (x < x_table_v[x_index])
       {
          x = x_table_v[x_index];
       }
       val_sat_X = x_table_v[ map->Nx - 1];
       if (x > val_sat_X)
       {
          x = val_sat_X;
       }
       x_index = (UInt16) (x_index + *(local_xLow));

       /* Local search. */
       if (x < x_table_v[x_index])
       {
          /* Search algorithm for row axis.
             Linear search, start high. */
          do
          {
             (*(local_xLow))--;
             x_index--;
          }
          while (x < x_table_v[x_index]);
       }
       else
       {
          /* Search algorithm for row axis. */
          x_index++;

          /* Linear search, start low. */
          while (x > x_table_v[x_index])
          {
            x_index++;
            (*(local_xLow))++;
          }
          x_index--;
       }
       z_index = (UInt16) (z_index + (nb_entree_Y * (*(local_xLow))) );

       /* Saturation. */
       if (y < y_table_v[y_index])
       {
          y = y_table_v[y_index];
       }
       val_sat_Y = y_table_v[nb_entree_Y - 1];
       if (y > val_sat_Y)
       {
          y = val_sat_Y;
       }
       y_index = (UInt16) (y_index + *(local_yLow));

       /* Local search. */
       if (y < y_table_v[y_index])
       {
          /* Search algorithm for column axis.
             Linear search, start high. */
          do
          {
             (*(local_yLow))--;
             y_index--;
          }
          while (y < y_table_v[y_index]);
       }
       else
       {
          /* Search algorithm for column axis. */
          y_index++;

          /* Linear search, start low. */
          while (y > y_table_v[y_index])
          {
             y_index++;
             (*(local_yLow))++;
          }
          y_index--;
       }
       z_index = (UInt16) ( z_index + *(local_yLow) );

       /* Differences in column axis. */
       diff_Y_avant = (UInt16) ( y - y_table_v[y_index] );
       diff_Y_apres = (UInt16) ( y_table_v[y_index+1] - y );
       somme_diff = (UInt16) (diff_Y_avant + diff_Y_apres);

       /* Interpolation. */
       if (0  == somme_diff)
       {
          valeur_sortie1 = (UInt16) ( z_table_v[z_index]*fm );
          valeur_sortie2 = (UInt16) ( z_table_v[nb_entree_Y]*fm );
       }
       else
       {
          /* 1. Y-Interpolation. */
          valeur_sortie1 = (UInt16) (( ( (((UInt32) diff_Y_apres) * ((UInt32) (z_table_v[z_index]*fm)))) + ((UInt32)
           (((UInt32) diff_Y_avant) * ((UInt32) (z_table_v[z_index+1]*fm))))) / (UInt32)somme_diff);
          z_index = (UInt16) (z_index + nb_entree_Y);

          /* 2. Y-Interpolation. */
          valeur_sortie2 = (UInt16)  (( ( (((UInt32) diff_Y_apres) * ((UInt32) (z_table_v[z_index]*fm)))) + ((UInt32)
           (((UInt32) diff_Y_avant) * ((UInt32) (z_table_v[z_index+1]*fm))))) / (UInt32)somme_diff);
       }

       /* Differences in row axis. */
       diff_X_avant = (UInt16) ( x - x_table_v[x_index] );
       diff_X_apres = (UInt16) ( x_table_v[x_index+1] - x_table_v[x_index] );
       if (diff_X_apres != 0)
       {
          if (valeur_sortie1 < valeur_sortie2)
          {
             /* Positive slope. */
             valeur_sortie = (UInt16) ( valeur_sortie1 + (UInt16) ((((UInt32) (valeur_sortie2 - valeur_sortie1)) * ((UInt32) diff_X_avant))
              / (UInt32)diff_X_apres) );
             /* QAC pense qu'une division par zero est possible hors diff_X_apres est teste juste au dessus */
          }
          else
          {
             /* Negative slope. */
             valeur_sortie = (UInt16) ( valeur_sortie1 - (UInt16) ((((UInt32) (valeur_sortie1 - valeur_sortie2)) * ((UInt32) diff_X_avant))
              / (UInt32)diff_X_apres) );
             /* QAC pense qu'une division par zero est possible hors diff_X_apres est teste juste au dessus */
          }
       }
       else
       {
         valeur_sortie = (UInt16) ( (valeur_sortie1+valeur_sortie2)/2 );
       }
     }
     else
     {
        FISA_erreur(FISA_ERREUR_NULL_POINTER);
        valeur_sortie =  0;
     }
   }
   else
   {
     FISA_erreur(FISA_ERREUR_NULL_POINTER);
     valeur_sortie =  0;
   }
   return valeur_sortie;
}

/*==============================================================================
** Name: lookup2D_rS32_U8
** Description:
**------------------------------------------------------------------------------
** IN:
** const MAP_Table_2D_U8 *map
** SInt16 x
** UInt16 y
** UInt16 *local_xLow
** UInt16 *local_yLow
** SInt16 fm
**------------------------------------------------------------------------------
** OUT:
** SInt32 value_returned : valeur de sortie saturee (ou non) entre Min et Max
**
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

FUNC(SInt32,FISA_CODE) lookup2D_rS32_U8(P2CONST(MAP_Table_2D_U8, FISA_APPL_DATA, AUTOMATIC) map,
                SInt16 x, UInt16 y,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_xLow,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_yLow,
                SInt16 fm)
{
   /*Default storage class for local variables | Width: 16 */
   VAR(SInt16,AUTOMATIC)                      val_sat_X;
   VAR(UInt16,AUTOMATIC)                      val_sat_Y;
   VAR(UInt16,AUTOMATIC)                      diff_Y_avant;
   VAR(SInt16,AUTOMATIC)                      diff_X_avant;
   VAR(UInt16,AUTOMATIC)                      diff_Y_apres;
   VAR(SInt16,AUTOMATIC)                      diff_X_apres;
   VAR(UInt16,AUTOMATIC)                      somme_diff;
   VAR(UInt16,AUTOMATIC)                      valeur_sortie1;
   VAR(UInt16,AUTOMATIC)                      valeur_sortie2;
   VAR(SInt32,AUTOMATIC)                      valeur_sortie;


   /*Default storage class for local variables | Width: 16 */
   VAR(UInt16,AUTOMATIC)                      nb_entree_Y;

   /*Default storage class for local variables | Width: 32 */
   P2CONST(SInt16, FISA_APPL_DATA, AUTOMATIC) x_table_v;
   P2CONST(UInt16, FISA_APPL_DATA, AUTOMATIC) y_table_v;
   P2CONST(UInt8, FISA_APPL_DATA, AUTOMATIC)  z_table_v;
   VAR(UInt16,AUTOMATIC)                      x_index;
   VAR(UInt16,AUTOMATIC)                      y_index;
   VAR(UInt16,AUTOMATIC)                      z_index;

   if ((NULL_PTR != (const void*)map) && (NULL_PTR != (void*)local_xLow) && (NULL_PTR != (void*)local_yLow))
   {
     x_table_v = map->x_table;
     y_table_v = map->y_table;
     z_table_v = map->z_table;
     nb_entree_Y  = (UInt16)map->Ny;

     if ((NULL_PTR != (const void*)x_table_v) && (NULL_PTR != (const void*)y_table_v) && (NULL_PTR != (const void*)z_table_v))
     {
       x_index = 0;
       y_index = 0;
       z_index = 0;

       /* Saturation. */
       if (x < x_table_v[x_index])
       {
          x = x_table_v[x_index];
       }
       val_sat_X = x_table_v[ map->Nx - 1];
       if (x > val_sat_X)
       {
          x = val_sat_X;
       }
       x_index = (UInt16) (x_index + *(local_xLow));

       /* Local search. */
       if (x < x_table_v[x_index])
       {
          /* Search algorithm for row axis.
             Linear search, start high. */
          do
          {
             (*(local_xLow))--;
             x_index--;
          }
          while (x < x_table_v[x_index]);
       }
       else
       {
          /* Search algorithm for row axis. */
          x_index++;

          /* Linear search, start low. */
          while (x > x_table_v[x_index])
          {
            x_index++;
            (*(local_xLow))++;
          }
          x_index--;
       }
       z_index = (UInt16) (z_index + (nb_entree_Y * (*(local_xLow))) );

       /* Saturation. */
       if (y < y_table_v[y_index])
       {
          y = y_table_v[y_index];
       }
       val_sat_Y = y_table_v[nb_entree_Y - 1];
       if (y > val_sat_Y)
       {
          y = val_sat_Y;
       }
       y_index = (UInt16) ( y_index + *(local_yLow) );

       /* Local search. */
       if (y < y_table_v[y_index])
       {
          /* Search algorithm for column axis.
             Linear search, start high. */
          do
          {
             (*(local_yLow))--;
             y_index--;
          }
          while (y < y_table_v[y_index]);
       }
       else
       {
          /* Search algorithm for column axis. */
          y_index++;

          /* Linear search, start low. */
          while (y > y_table_v[y_index])
          {
             y_index++;
             (*(local_yLow))++;
          }
          y_index--;
       }
       z_index = (UInt16) (z_index + *(local_yLow));

       /* Differences in column axis. */
       diff_Y_avant = (UInt16) ( y - y_table_v[y_index] );
       diff_Y_apres = (UInt16) ( y_table_v[y_index+1] - y ) ;
       somme_diff = (UInt16) (diff_Y_avant + diff_Y_apres);

       /* Interpolation. */
       if (0  == somme_diff)
       {
          valeur_sortie1 = (UInt16) ( ((UInt16)z_table_v[z_index])*(UInt16)fm );
          valeur_sortie2 = (UInt16) ( ((UInt16)z_table_v[nb_entree_Y])*(UInt16)fm );
       }
       else
       {
          /* 1. Y-Interpolation. */
          valeur_sortie1 = (UInt16) ( ( ( (diff_Y_apres * (((UInt16)z_table_v[z_index])*(UInt16)fm))) + ((diff_Y_avant * (((UInt16)z_table_v[z_index+1])*(UInt16)fm))))
            / somme_diff );
          z_index = (UInt16) (z_index + nb_entree_Y);

          /* 2. Y-Interpolation. */
          valeur_sortie2 = (UInt16) ( ( ( (diff_Y_apres * (((UInt16)z_table_v[z_index]*(UInt16)fm)))) + ((diff_Y_avant * (((UInt16)z_table_v[z_index+1])*(UInt16)fm))))
           / somme_diff );
       }

       /* Differences in row axis. */
       diff_X_avant = (SInt16) ( x - x_table_v[x_index] );
       diff_X_apres = (SInt16) ( x_table_v[x_index+1] - x_table_v[x_index] );
       if (diff_X_apres != 0)
       {
          if (valeur_sortie1 < valeur_sortie2)
          {
             /* Positive slope. */
             valeur_sortie = ((SInt32)valeur_sortie1) + ( ((SInt32)(valeur_sortie2 - valeur_sortie1) * (SInt32)diff_X_avant)
              / (SInt32)diff_X_apres);
          }
          else
          {
             /* Negative slope. */
             valeur_sortie = ((SInt32)valeur_sortie1) - ( ((SInt32)(valeur_sortie1 - valeur_sortie2) * (SInt32)diff_X_avant)
              / (SInt32)diff_X_apres);
          }
       }
       else
       {
         valeur_sortie = ((SInt32)valeur_sortie1+(SInt32)valeur_sortie2)/2;
       }
     }
     else
     {
        FISA_erreur(FISA_ERREUR_NULL_POINTER);
        valeur_sortie =  0;
     }
   }
   else
   {
     FISA_erreur(FISA_ERREUR_NULL_POINTER);
     valeur_sortie =  0;
   }
   return valeur_sortie;
}


/*==============================================================================
** Name: lookup2D_rS32_S8
** Description:
**------------------------------------------------------------------------------
** IN:
** const MAP_Table_2D_S8 *map
** SInt16 x
** SInt16 y
** UInt16 *local_xLow
** UInt16 *local_yLow
**------------------------------------------------------------------------------
** OUT:
** SInt32 value_returned : valeur de sortie saturee (ou non) entre Min et Max
**
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

FUNC(SInt32,FISA_CODE) lookup2D_rS32_S8(P2CONST(MAP_Table_2D_S8, FISA_APPL_DATA, AUTOMATIC) map,
                SInt16 x, SInt16 y,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_xLow,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_yLow)
{
   /*Default storage class for local variables | Width: 16 */
   VAR(SInt16,AUTOMATIC)                      val_sat_X;
   VAR(SInt16,AUTOMATIC)                      val_sat_Y;
   VAR(SInt16,AUTOMATIC)                      diff_Y_avant;
   VAR(SInt16,AUTOMATIC)                      diff_X_avant;
   VAR(SInt16,AUTOMATIC)                      diff_Y_apres;
   VAR(SInt16,AUTOMATIC)                      diff_X_apres;
   VAR(SInt16,AUTOMATIC)                      somme_diff;
   VAR(SInt32,AUTOMATIC)                      valeur_sortie1;
   VAR(SInt32,AUTOMATIC)                      valeur_sortie2;
   VAR(SInt32,AUTOMATIC)                      valeur_sortie;


   /*Default storage class for local variables | Width: 16 */
   VAR(UInt16,AUTOMATIC)                      nb_entree_Y;

   /*Default storage class for local variables | Width: 32 */
   P2CONST(SInt16, FISA_APPL_DATA, AUTOMATIC) x_table_v;
   P2CONST(SInt16, FISA_APPL_DATA, AUTOMATIC) y_table_v;
   P2CONST(SInt8, FISA_APPL_DATA, AUTOMATIC)  z_table_v;
   VAR(UInt16,AUTOMATIC)                      x_index;
   VAR(UInt16,AUTOMATIC)                      y_index;
   VAR(UInt16,AUTOMATIC)                      z_index;

   if ((NULL_PTR != (const void*)map) && (NULL_PTR != (void*)local_xLow) && (NULL_PTR != (void*)local_yLow))
   {
     x_table_v = map->x_table;
     y_table_v = map->y_table;
     z_table_v = map->z_table;
     nb_entree_Y  = (UInt16)map->Ny;

     if ((NULL_PTR != (const void*)x_table_v) && (NULL_PTR != (const void*)y_table_v) && (NULL_PTR != (const void*)z_table_v))
     {
       x_index = 0;
       y_index = 0;
       z_index = 0;

       /* Saturation. */
       if (x < x_table_v[x_index])
       {
          x = x_table_v[x_index];
       }
       val_sat_X = x_table_v[ map->Nx - 1];
       if (x > val_sat_X)
       {
          x = val_sat_X;
       }
       x_index = (UInt16) (x_index + *(local_xLow));

       /* Local search. */
       if (x < x_table_v[x_index])
       {
          /* Search algorithm for row axis.
             Linear search, start high. */
          do
          {
             (*(local_xLow))--;
             x_index--;
          }
          while (x < x_table_v[x_index]);
       }
       else
       {
          /* Search algorithm for row axis. */
          x_index++;

          /* Linear search, start low. */
          while (x > x_table_v[x_index])
          {
            x_index++;
            (*(local_xLow))++;
          }
          x_index--;
       }
       z_index = (UInt16) (z_index + (nb_entree_Y * (*(local_xLow))) );

       /* Saturation. */
       if (y < y_table_v[y_index])
       {
          y = y_table_v[y_index];
       }
       val_sat_Y = y_table_v[nb_entree_Y - 1];
       if (y > val_sat_Y)
       {
          y = val_sat_Y;
       }
       y_index = (UInt16) (y_index + *(local_yLow));

       /* Local search. */
       if (y < y_table_v[y_index])
       {
          /* Search algorithm for column axis.
             Linear search, start high. */
          do
          {
             (*(local_yLow))--;
             y_index--;
          }
          while (y < y_table_v[y_index]);
       }
       else
       {
          /* Search algorithm for column axis. */
          y_index++;

          /* Linear search, start low. */
          while (y > y_table_v[y_index])
          {
             y_index++;
             (*(local_yLow))++;
          }
          y_index--;
       }
       z_index = (UInt16) (z_index + *(local_yLow));

       /* Differences in column axis. */
       diff_Y_avant = (SInt16) ( y - y_table_v[y_index] );
       diff_Y_apres = (SInt16) ( y_table_v[y_index+1] - y );
       somme_diff = (SInt16) (diff_Y_avant + diff_Y_apres);

       /* Interpolation. */
       if (0  == somme_diff)
       {
          valeur_sortie1 = z_table_v[z_index];
          valeur_sortie2 = z_table_v[nb_entree_Y];
       }
       else
       {
          /* 1. Y-Interpolation. */
          valeur_sortie1 = ( ( (((SInt32) diff_Y_apres) * ((SInt32) z_table_v[z_index]))) + ((SInt32)
           (((SInt32) diff_Y_avant) * ((SInt32) z_table_v[z_index+1])))) / (SInt32)somme_diff;
          z_index = (UInt16) (z_index + nb_entree_Y);

          /* 2. Y-Interpolation. */
          valeur_sortie2 = ( ( (((SInt32) diff_Y_apres) * ((SInt32) z_table_v[z_index]))) + ((SInt32)
           (((SInt32) diff_Y_avant) * ((SInt32) z_table_v[z_index+1])))) / (SInt32)somme_diff;
       }

       /* Differences in row axis. */
       diff_X_avant = (SInt16) ( x - x_table_v[x_index] );
       diff_X_apres = (SInt16) ( x_table_v[x_index+1] - x_table_v[x_index] );
       if (diff_X_apres != 0)
       {
          if (valeur_sortie1 < valeur_sortie2)
          {
             /* Positive slope. */
             valeur_sortie = valeur_sortie1 + ( (((SInt32) (valeur_sortie2 - valeur_sortie1)) * ((SInt32) diff_X_avant))
              / (SInt32)diff_X_apres);
          }
          else
          {
             /* Negative slope. */
             valeur_sortie = valeur_sortie1 - ( (((SInt32) (valeur_sortie1 - valeur_sortie2)) * ((SInt32) diff_X_avant))
              / (SInt32)diff_X_apres);
          }
       }
       else
       {
         valeur_sortie = (valeur_sortie1+valeur_sortie2)/2;
       }
     }
     else
     {
        FISA_erreur(FISA_ERREUR_NULL_POINTER);
        valeur_sortie =  0;
     }
   }
   else
   {
     FISA_erreur(FISA_ERREUR_NULL_POINTER);
     valeur_sortie =  0;
   }
   return valeur_sortie;
}


/*==============================================================================
** Name: lookup1D
** Description:
**------------------------------------------------------------------------------
** IN:
** const MAP_Table_1D *map
** SInt16 x
** UInt16 *local_xLow
** SInt16 fm
**------------------------------------------------------------------------------
** OUT:
** SInt32 value_returned : valeur de sortie saturee (ou non) entre Min et Max
**
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

FUNC(SInt16,FISA_CODE) lookup1D(P2CONST(MAP_Table_1D, FISA_APPL_DATA, AUTOMATIC) map,
                SInt16 x,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_xLow,
                SInt16 fm)
{
   /* SLLocal: Default storage class for local variables | Width: 32 */
   VAR(SInt16,AUTOMATIC)                      diff_X_avant;
   VAR(SInt16,AUTOMATIC)                      diff_X_apres;

   /* SLLocal: Default storage class for local variables | Width: 16 */
   VAR(SInt16,AUTOMATIC)                      valeur_sortie1;
   VAR(SInt16,AUTOMATIC)                      valeur_sortie2;
   VAR(SInt16,AUTOMATIC)                      valeur_sortie;

   VAR(UInt16,AUTOMATIC)                      x_index;
   VAR(UInt16,AUTOMATIC)                      z_index;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   P2CONST(SInt16, FISA_APPL_DATA, AUTOMATIC) x_table_v;
   P2CONST(SInt16, FISA_APPL_DATA, AUTOMATIC) z_table_v;

   if ((NULL_PTR != (const void*)map) && (NULL_PTR != (void*)local_xLow))
   {

     x_table_v = map->x_table;
     z_table_v = map->z_table;
     x_index = 0;
     z_index = 0;

     if ((NULL_PTR != (const void*)x_table_v) && (NULL_PTR != (const void*)z_table_v))
     {
       if (x <= x_table_v[x_index])
       {
          *(local_xLow) = 0;

          /* Saturation. */
          valeur_sortie = (SInt16) (z_table_v[0]*fm);
       }
       else
       {
         if (x >= x_table_v[map->Nx - 1])
         {
            *(local_xLow) = (UInt16) (map->Nx - 2);
            valeur_sortie = (SInt16) ( z_table_v[map->Nx - 1]*fm );
         }
         else
         {
           x_index = (UInt16) (x_index + *(local_xLow));

           /* Local search. */
           if (x < x_table_v[x_index])
           {
              /* Linear search, start high. */
              do
              {
                 (*(local_xLow))--;
                 x_index--;
              }
              while (x < x_table_v[x_index]);
           }
           else
           {
              /* Linear search, start low. */
              x_index++;

              while (x > x_table_v[x_index])
              {
                x_index++;
                (*(local_xLow))++;
              }
              x_index--;
           }

           z_index = (UInt16) (z_index + *(local_xLow));
           valeur_sortie1 = (SInt16) (z_table_v[z_index]*fm);
           valeur_sortie2 = (SInt16) (z_table_v[z_index+1]*fm);

           /* Interpolation. */
           diff_X_avant = (SInt16) ( x - x_table_v[x_index] );
           diff_X_apres = (SInt16) ( x_table_v[x_index+1] - x_table_v[x_index] );

           if (diff_X_apres != 0)
           {
             if (valeur_sortie1 <= valeur_sortie2)
             {
                /* Positive slope. */
                valeur_sortie = (SInt16) ( valeur_sortie1 + (SInt16) ((((valeur_sortie2 - valeur_sortie1) * diff_X_avant) + (diff_X_apres/2)) /
                 diff_X_apres) );
             }
             else
             {
                /* Negative slope. */
                valeur_sortie = (SInt16) ( valeur_sortie1 - (SInt16) ((((valeur_sortie1 - valeur_sortie2) * diff_X_avant) - (diff_X_apres/2)) /
                 diff_X_apres) );
             }
           }
           else
           {
             valeur_sortie = (SInt16) ( (valeur_sortie1+valeur_sortie2)/2 );
           }
         }
       }
     }
     else
     {
        FISA_erreur(FISA_ERREUR_NULL_POINTER);
        valeur_sortie =  0;
     }
   }
   else
   {
      FISA_erreur(FISA_ERREUR_NULL_POINTER);
      valeur_sortie =  0;
   }
   return valeur_sortie;
}

/*==============================================================================
** Name: lookup1D_U16
** Description:
**------------------------------------------------------------------------------
** IN:
** const MAP_Table_1D_U16 *map
** SInt16 x
** UInt16 *local_xLow
** UInt16 fm
**------------------------------------------------------------------------------
** OUT:
** UInt16 value_returned : valeur de sortie saturee (ou non) entre Min et Max
**
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

FUNC(UInt16,FISA_CODE) lookup1D_U16(P2CONST(MAP_Table_1D_U16, FISA_APPL_DATA, AUTOMATIC) map,
                SInt16 x,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_xLow,
                UInt16 fm)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   VAR(SInt32,AUTOMATIC)                      diff_X_avant;
   VAR(SInt32,AUTOMATIC)                      diff_X_apres;

   /* SLLocal: Default storage class for local variables | Width: 32 */
   VAR(UInt32,AUTOMATIC)                      valeur_sortie1;
   VAR(UInt32,AUTOMATIC)                      valeur_sortie2;
   VAR(UInt32,AUTOMATIC)                      valeur_sortie;

   VAR(UInt16,AUTOMATIC)                      x_index;
   VAR(UInt16,AUTOMATIC)                      z_index;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   P2CONST(SInt16, FISA_APPL_DATA, AUTOMATIC) x_table_v;
   P2CONST(UInt16, FISA_APPL_DATA, AUTOMATIC) z_table_v;

   if ((NULL_PTR != (const void*)map) && (NULL_PTR != (void*)local_xLow))
   {

     x_table_v = map->x_table;
     z_table_v = map->z_table;
     x_index = 0;
     z_index = 0;

     if ((NULL_PTR != (const void*)x_table_v) && (NULL_PTR != (const void*)z_table_v))
     {
       if (x <= x_table_v[x_index])
       {
          *(local_xLow) = 0;

          /* Saturation. */
          valeur_sortie = (UInt32)z_table_v[0]*(UInt32)fm;
       }
       else
       {
         if (x >= x_table_v[map->Nx - 1])
         {
            *(local_xLow) = (UInt16) (map->Nx - 2);
            valeur_sortie = (UInt32)z_table_v[map->Nx - 1]*(UInt32)fm;
         }
         else
         {
           x_index = (UInt16) ( x_index + *(local_xLow) );

           /* Local search. */
           if (x < x_table_v[x_index])
           {
              /* Linear search, start high. */
              do
              {
                 (*(local_xLow))--;
                 x_index--;
              }
              while (x < x_table_v[x_index]);
           }
           else
           {
              /* Linear search, start low. */
              x_index++;

              while (x > x_table_v[x_index])
              {
                x_index++;
                (*(local_xLow))++;
              }
              x_index--;
           }

           z_index = (UInt16) (z_index + *(local_xLow));
           valeur_sortie1 = (UInt32)z_table_v[z_index]*(UInt32)fm;
           valeur_sortie2 = (UInt32)z_table_v[z_index+1]*(UInt32)fm;

           /* Interpolation. */
           diff_X_avant = (SInt32)x - x_table_v[x_index];
           diff_X_apres = (SInt32)x_table_v[x_index+1] - x_table_v[x_index];

           if (diff_X_apres != 0)
           {
             if (valeur_sortie1 <= valeur_sortie2)
             {
                /* Positive slope. */
                valeur_sortie = valeur_sortie1 + ( (((valeur_sortie2 - valeur_sortie1) * (UInt32)diff_X_avant) + ((UInt32)diff_X_apres/2)) /
                 (UInt32)diff_X_apres);
             }
             else
             {
                /* Negative slope. */
                valeur_sortie = valeur_sortie1 - ( (((valeur_sortie1 - valeur_sortie2) * (UInt32)diff_X_avant) - ((UInt32)diff_X_apres/2)) /
                 (UInt32)diff_X_apres);
             }
           }
           else
           {
             valeur_sortie = (valeur_sortie1+valeur_sortie2)/2;
           }
         }
       }
     }
     else
     {
        FISA_erreur(FISA_ERREUR_NULL_POINTER);
        valeur_sortie =  0;
     }
   }
   else
   {
      FISA_erreur(FISA_ERREUR_NULL_POINTER);
      valeur_sortie =  0;
   }
   /* Les entrees etant en U16, le resultat est forcement dans la plage U16 */
   return (UInt16)valeur_sortie;
}

/*==============================================================================
** Name: lookup1D_rU32_U16
** Description:
**------------------------------------------------------------------------------
** IN:
** const MAP_Table_1D_U16 *map
** SInt16 x
** UInt16 *local_xLow
**------------------------------------------------------------------------------
** OUT:
** UInt32 value_returned : valeur de sortie saturee (ou non) entre Min et Max
**
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

FUNC(UInt32,FISA_CODE) lookup1D_rU32_U16(P2CONST(MAP_Table_1D_U16, FISA_APPL_DATA, AUTOMATIC) map,
                SInt16 x,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_xLow)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   VAR(SInt16,AUTOMATIC)                      diff_X_avant;
   VAR(SInt16,AUTOMATIC)                      diff_X_apres;

   /* SLLocal: Default storage class for local variables | Width: 32 */
   VAR(UInt32,AUTOMATIC)                      valeur_sortie1;
   VAR(UInt32,AUTOMATIC)                      valeur_sortie2;
   VAR(UInt32,AUTOMATIC)                      valeur_sortie;

   VAR(UInt16,AUTOMATIC)                      x_index;
   VAR(UInt16,AUTOMATIC)                      z_index;

   /* SLLutLocalConst: Default storage class for local variables | Width: 32 */
   P2CONST(SInt16, FISA_APPL_DATA, AUTOMATIC) x_table_v;
   P2CONST(UInt16, FISA_APPL_DATA, AUTOMATIC) z_table_v;

   if ((NULL_PTR != (const void*)map) && (NULL_PTR != (void*)local_xLow))
   {

     x_table_v = map->x_table;
     z_table_v = map->z_table;
     x_index = 0;
     z_index = 0;

     if ((NULL_PTR != (const void*)x_table_v) && (NULL_PTR != (const void*)z_table_v))
     {
       if (x <= x_table_v[x_index])
       {
          *(local_xLow) = 0;

          /* Saturation. */
          valeur_sortie = z_table_v[0];
       }
       else
       {
         if (x >= x_table_v[map->Nx - 1])
         {
            *(local_xLow) = (UInt16) (map->Nx - 2);
            valeur_sortie = z_table_v[map->Nx - 1];
         }
         else
         {
           x_index = (UInt16) (x_index + *(local_xLow));

           /* Local search. */
           if (x < x_table_v[x_index])
           {
              /* Linear search, start high. */
              do
              {
                 (*(local_xLow))--;
                 x_index--;
              }
              while (x < x_table_v[x_index]);
           }
           else
           {
              /* Linear search, start low. */
              x_index++;

              while (x > x_table_v[x_index])
              {
                x_index++;
                (*(local_xLow))++;
              }
              x_index--;
           }

           z_index = (UInt16) (z_index + *(local_xLow));
           valeur_sortie1 = z_table_v[z_index];
           valeur_sortie2 = z_table_v[z_index+1];

           /* Interpolation. */
           diff_X_avant = (SInt16) ( x - x_table_v[x_index] );
           diff_X_apres = (SInt16) ( x_table_v[x_index+1] - x_table_v[x_index] );

           if (diff_X_apres != 0)
           {
             if (valeur_sortie1 <= valeur_sortie2)
             {
                /* Positive slope. */
                valeur_sortie = valeur_sortie1 + ((((valeur_sortie2 - valeur_sortie1) * (UInt32)diff_X_avant) + ((UInt32)diff_X_apres/2)) /
                 (UInt32)diff_X_apres);
                /* QAC pense qu'une division par zero est possible hors diff_X_apres est teste juste au dessus */
             }
             else
             {
                /* Negative slope. */
                valeur_sortie = valeur_sortie1 - ((((valeur_sortie1 - valeur_sortie2) * (UInt32)diff_X_avant) - ((UInt32)diff_X_apres/2)) /
                 (UInt32)diff_X_apres);
                /* QAC pense qu'une division par zero est possible hors diff_X_apres est teste juste au dessus */
             }
           }
           else
           {
             valeur_sortie = (valeur_sortie1+valeur_sortie2)/2;
           }
         }
       }
     }
     else
     {
        FISA_erreur(FISA_ERREUR_NULL_POINTER);
        valeur_sortie =  0;
     }
   }
   else
   {
      FISA_erreur(FISA_ERREUR_NULL_POINTER);
      valeur_sortie =  0;
   }
   return valeur_sortie;
}


/*==============================================================================
** Name: lookup1D_U8
** Description:
**------------------------------------------------------------------------------
** IN:
** const MAP_Table_1D_U8 *map
** SInt16 x
** UInt16 *local_xLow
** UInt8 fm
** UInt8 fd
**----------------------------------
** OUT:
** UInt8 value_returned : valeur de sortie saturee (ou non) entre Min et Max
**
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

FUNC(UInt8,FISA_CODE) lookup1D_U8(P2CONST(MAP_Table_1D_U8, FISA_APPL_DATA, AUTOMATIC) map,
                SInt16 x,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_xLow,
                UInt16 fm,UInt16 fd)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   VAR(SInt16,AUTOMATIC)                      diff_X_avant;
   VAR(SInt16,AUTOMATIC)                      diff_X_apres;

   /* SLLocal: Default storage class for local variables | Width: 8 */
   VAR(UInt16,AUTOMATIC)                      valeur_sortie1;
   VAR(UInt16,AUTOMATIC)                      valeur_sortie2;
   VAR(UInt16,AUTOMATIC)                      valeur_sortie;

   VAR(UInt16,AUTOMATIC)                      x_index;
   VAR(UInt16,AUTOMATIC)                      z_index;

   VAR(UInt8,AUTOMATIC)                       ret;

   /* SLLutLocalConst: Default storage class for local variables | Width: 16 */
   P2CONST(SInt16, FISA_APPL_DATA, AUTOMATIC) x_table_v;
   P2CONST(UInt8, FISA_APPL_DATA, AUTOMATIC)  z_table_v;

   if ((NULL_PTR != (const void*)map) && (NULL_PTR != (void*)local_xLow))
   {
     x_table_v = map->x_table;
     z_table_v = map->z_table;
     x_index = 0;
     z_index = 0;

     if ((NULL_PTR != (const void*)x_table_v) && (NULL_PTR != (const void*)z_table_v))
     {
       if (x <= x_table_v[x_index])
       {
          *(local_xLow) = 0;

          /* Saturation. */
          valeur_sortie = (UInt16) ( ((UInt16)z_table_v[0])*fm );
       }
       else
       {
         if (x >= x_table_v[map->Nx - 1])
         {
            *(local_xLow) = (UInt16) (map->Nx - 2);
            valeur_sortie = (UInt16) ( ( (UInt16)z_table_v[map->Nx - 1])*fm );
         }
         else
         {
           x_index = (UInt16) ( x_index + *(local_xLow) );

           /* Local search. */
           if (x < x_table_v[x_index])
           {
              /* Linear search, start high. */
              do
              {
                 (*(local_xLow))--;
                 x_index--;
              }
              while (x < x_table_v[x_index]);
           }
           else
           {
              /* Linear search, start low. */
              x_index++;

              while (x > x_table_v[x_index])
              {
                x_index++;
                (*(local_xLow))++;
              }
              x_index--;
           }

           z_index = (UInt16) ( z_index + *(local_xLow) );
           valeur_sortie1 = (UInt16) ( ((UInt16)z_table_v[z_index])*fm );
           valeur_sortie2 = (UInt16) ( ((UInt16)z_table_v[z_index+1])*fm );

           /* Interpolation. */
           diff_X_avant = (SInt16) ( x - x_table_v[x_index] );
           diff_X_apres = (SInt16) ( x_table_v[x_index+1] - x_table_v[x_index] );

           if (diff_X_apres != 0)
           {
             if (valeur_sortie1 <= valeur_sortie2)
             {
                /* Positive slope. */
                valeur_sortie = (UInt16)((SInt32)valeur_sortie1 + ((((((SInt32)valeur_sortie2 - (SInt32)valeur_sortie1) * ((SInt32)diff_X_avant))) + ((SInt32)diff_X_apres/2)) /
                 (SInt32)diff_X_apres));
             }
             else
             {
                /* Negative slope. */
                valeur_sortie = (UInt16)((SInt32)valeur_sortie1 - ((((((SInt32)valeur_sortie1 - (SInt32)valeur_sortie2) * ((SInt16) diff_X_avant))) - ((SInt32)diff_X_apres/2)) /
                 (SInt32)diff_X_apres));
             }
           }
           else
           {
             valeur_sortie = (UInt16) ( (valeur_sortie1+valeur_sortie2)/2 );
           }
         }
       }
     }
     else
     {
        FISA_erreur(FISA_ERREUR_NULL_POINTER);
        valeur_sortie =  0;
     }
   }
   else
   {
      FISA_erreur(FISA_ERREUR_NULL_POINTER);
      valeur_sortie =  0;
   }
   /* Les entrees etant en U8, le resultat est forcement dans la plage U8 */
   if (fd)
   {
     ret = (UInt8)(valeur_sortie/fd);
   }
   else
   {
     ret = (UInt8)valeur_sortie;
   }

   return ret;
}

/*==============================================================================
** Name: lookup1D_rS16_U8
** Description:
**------------------------------------------------------------------------------
** IN:
** const MAP_Table_1D_U8 *map
** SInt16 x
** UInt16 *local_xLow
** UInt8 fm
**------------------------------------------------------------------------------
** OUT:
** SInt16 value_returned : valeur de sortie saturee (ou non) entre Min et Max
**
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

FUNC(SInt16,FISA_CODE) lookup1D_rS16_U8(P2CONST(MAP_Table_1D_U8, FISA_APPL_DATA, AUTOMATIC) map,
                SInt16 x,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_xLow,
                UInt16 fm)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   VAR(SInt16,AUTOMATIC)                      diff_X_avant;
   VAR(SInt16,AUTOMATIC)                      diff_X_apres;

   /* SLLocal: Default storage class for local variables | Width: 16 */
   VAR(UInt16,AUTOMATIC)                      valeur_sortie1;
   VAR(UInt16,AUTOMATIC)                      valeur_sortie2;
   VAR(UInt16,AUTOMATIC)                      valeur_sortie;

   VAR(UInt16,AUTOMATIC)                      x_index;
   VAR(UInt16,AUTOMATIC)                      z_index;

   /* SLLutLocalConst: Default storage class for local variables | Width: 16 */
   P2CONST(SInt16, FISA_APPL_DATA, AUTOMATIC) x_table_v;
   P2CONST(UInt8, FISA_APPL_DATA, AUTOMATIC)  z_table_v;

   if ((NULL_PTR != (const void*)map) && (NULL_PTR != (void*)local_xLow))
   {
     x_table_v = map->x_table;
     z_table_v = map->z_table;
     x_index = 0;
     z_index = 0;

     if ((NULL_PTR != (const void*)x_table_v) && (NULL_PTR != (const void*)z_table_v))
     {
       if (x <= x_table_v[x_index])
       {
          *(local_xLow) = 0;

          /* Saturation. */
          valeur_sortie = (UInt16) ( ((UInt16)z_table_v[0])*fm );
       }
       else
       {
         if (x >= x_table_v[map->Nx - 1])
         {
            *(local_xLow) = (UInt16) (map->Nx - 2);
            valeur_sortie = (UInt16) ( ((UInt16)z_table_v[map->Nx - 1])*fm );
         }
         else
         {
           x_index = (UInt16) ( x_index + *(local_xLow) );

           /* Local search. */
           if (x < x_table_v[x_index])
           {
              /* Linear search, start high. */
              do
              {
                 (*(local_xLow))--;
                 x_index--;
              }
              while (x < x_table_v[x_index]);
           }
           else
           {
              /* Linear search, start low. */
              x_index++;

              while (x > x_table_v[x_index])
              {
                x_index++;
                (*(local_xLow))++;
              }
              x_index--;
           }

           z_index = (UInt16) ( z_index + *(local_xLow) );
           valeur_sortie1 = (UInt16) ( ((UInt16)z_table_v[z_index])*fm );
           valeur_sortie2 = (UInt16) ( ((UInt16)z_table_v[z_index+1])*fm );

           /* Interpolation. */
           diff_X_avant = (SInt16) ( x - x_table_v[x_index] );
           diff_X_apres = (SInt16) ( x_table_v[x_index+1] - x_table_v[x_index] );

           if (diff_X_apres != 0)
           {
             if (valeur_sortie1 <= valeur_sortie2)
             {
                /* Positive slope. */
                valeur_sortie = (UInt16)((SInt32)valeur_sortie1 + (((((SInt32)valeur_sortie2 - (SInt32)valeur_sortie1) * (SInt32)diff_X_avant) + ((SInt32)diff_X_apres/2)) /
                 (SInt32)diff_X_apres));
             }
             else
             {
                /* Negative slope. */
                valeur_sortie = (UInt16)((SInt32)valeur_sortie1 - (((((SInt32)valeur_sortie1 - (SInt32)valeur_sortie2) * (SInt32)diff_X_avant) - ((SInt32)diff_X_apres/2)) /
                 (SInt32)diff_X_apres));
             }
           }
           else
           {
             valeur_sortie = (UInt16) ( (valeur_sortie1+valeur_sortie2)/2 );
           }
         }
       }
     }
     else
     {
        FISA_erreur(FISA_ERREUR_NULL_POINTER);
        valeur_sortie = 0;
     }
   }
   else
   {
      FISA_erreur(FISA_ERREUR_NULL_POINTER);
      valeur_sortie = 0;
   }
   return (SInt16) valeur_sortie;
}

/*==============================================================================
** Name: lookup1D_rS16_xU16_U8
** Description:
**------------------------------------------------------------------------------
** IN:
** const MAP_Table_1D_xU16_U8 *map
** UInt16 x
** UInt16 *local_xLow
** UInt8 fm
**------------------------------------------------------------------------------
** OUT:
** SInt32 value_returned : valeur de sortie saturee (ou non) entre Min et Max
**
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

FUNC(SInt16,FISA_CODE) lookup1D_rS16_xU16_U8(P2CONST(MAP_Table_1D_xU16_U8, FISA_APPL_DATA, AUTOMATIC) map,
                UInt16 x,
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) local_xLow,
                UInt16 fm)
{
   /* SLLocal: Default storage class for local variables | Width: 16 */
   VAR(UInt16,AUTOMATIC)                      diff_X_avant;
   VAR(UInt16,AUTOMATIC)                      diff_X_apres;

   /* SLLocal: Default storage class for local variables | Width: 16 */
   VAR(UInt16,AUTOMATIC)                      valeur_sortie1;
   VAR(UInt16,AUTOMATIC)                      valeur_sortie2;
   VAR(UInt16,AUTOMATIC)                      valeur_sortie;

   VAR(UInt16,AUTOMATIC)                      x_index;
   VAR(UInt16,AUTOMATIC)                      z_index;

   /* SLLutLocalConst: Default storage class for local variables | Width: 16 */
   P2CONST(UInt16, FISA_APPL_DATA, AUTOMATIC) x_table_v;
   P2CONST(UInt8, FISA_APPL_DATA, AUTOMATIC)  z_table_v;

   if ((NULL_PTR != (const void*)map) && (NULL_PTR != (void*)local_xLow))
   {
     x_table_v = map->x_table;
     z_table_v = map->z_table;
     x_index = 0;
     z_index = 0;

     if ((NULL_PTR != (const void*)x_table_v) && (NULL_PTR != (const void*)z_table_v))
     {
       if (x <= x_table_v[x_index])
       {
          *(local_xLow) = 0;

          /* Saturation. */
          valeur_sortie = (UInt16) ( ((UInt16)z_table_v[0])*fm );
       }
       else
       {
         if (x >= x_table_v[map->Nx - 1])
         {
            *(local_xLow) = (UInt16) (map->Nx - 2);
            valeur_sortie = (UInt16) ( ((UInt16)z_table_v[map->Nx - 1])*fm );
         }
         else
         {
           x_index = (UInt16) ( x_index + *(local_xLow) );

           /* Local search. */
           if (x < x_table_v[x_index])
           {
              /* Linear search, start high. */
              do
              {
                 (*(local_xLow))--;
                 x_index--;
              }
              while (x < x_table_v[x_index]);
           }
           else
           {
              /* Linear search, start low. */
              x_index++;

              while (x > x_table_v[x_index])
              {
                x_index++;
                (*(local_xLow))++;
              }
              x_index--;
           }

           z_index = (UInt16) (z_index + *(local_xLow));
           valeur_sortie1 = (UInt16) ( ((UInt16)z_table_v[z_index])*fm );
           valeur_sortie2 = (UInt16) ( ((UInt16)z_table_v[z_index+1])*fm );

           /* Interpolation. */
           diff_X_avant = (UInt16) ( x - x_table_v[x_index] );
           diff_X_apres = (UInt16) ( x_table_v[x_index+1] - x_table_v[x_index] );

           if (diff_X_apres != 0)
           {
             if (valeur_sortie1 <= valeur_sortie2)
             {
                /* Positive slope. */
                valeur_sortie = (UInt16)((SInt32)valeur_sortie1 + (((((SInt32)valeur_sortie2 - (SInt32)valeur_sortie1) * (SInt32)diff_X_avant) + ((SInt32)diff_X_apres/2)) /
                 (SInt32)diff_X_apres));
             }
             else
             {
                /* Negative slope. */
                valeur_sortie = (UInt16)((SInt32)valeur_sortie1 - (((((SInt32)valeur_sortie1 - (SInt32)valeur_sortie2) * (SInt32)diff_X_avant) - ((SInt32)diff_X_apres/2)) /
                 (SInt32)diff_X_apres));
             }
           }
           else
           {
             valeur_sortie = (UInt16) ( (valeur_sortie1+valeur_sortie2)/2 );
           }
         }
       }
     }
     else
     {
        FISA_erreur(FISA_ERREUR_NULL_POINTER);
        valeur_sortie =  0;
     }
   }
   else
   {
      FISA_erreur(FISA_ERREUR_NULL_POINTER);
      valeur_sortie =  0;
   }
   return (SInt16) valeur_sortie;
}

/*==============================================================================
** Name: Accum_Sat_Analisys_SInt16
** Description: permet de calculer le delta du coefficient d'entree
**------------------------------------------------------------------------------
** IN:
** SInt32 Inc_man : valeur du coefficient en entree (mantisse)
** SInt16 Inc_exp : precision de Inc (exposant)
** Boolean On : autorisation du calcul
** SInt16 Max_man : valeur maximale de la saturation (mantisse)
** SInt16 Max_exp : precision de Max (exposant)
** SInt32 Min_man : valeur minimale de la saturation (mantisse)
** SInt16 Min_exp : precision de Min (exposant)
** SInt16 *Mem_man : valeur du retard de 1
** SInt16 output_exp : precision de la sortie (utlisee pour passer de fixe en SInt32)
** Boolean firstTime
**------------------------------------------------------------------------------
** OUT:
** SInt16 : valeur du delta qui est retournee
**
**============================================================================*/
/*********************************************************************************/
/*                                                                               */
/*                                                                               */
/*********************************************************************************/
/* !LastAuthor  : P. Aupoix (GEENSYS)                                            */
/*********************************************************************************/

FUNC(SInt16,FISA_CODE) Accum_Sat_Analyse_SInt16 (  SInt16 Inc_man, SInt16 Inc_exp, Boolean On, SInt16 Min_man , SInt16 Min_exp, SInt16 Max_man, SInt16 Max_exp,
                      P2VAR(SInt16, FISA_APPL_DATA, AUTOMATIC) Mem_man, SInt16 output_exp, Boolean firstTime)
{
  VAR(SInt16,AUTOMATIC)   output;             /*sortie de la fonction*/
  VAR(ts_fixed,AUTOMATIC) Inc_f;
  VAR(ts_fixed,AUTOMATIC) Mem_f;
  VAR(ts_fixed,AUTOMATIC) Add_f;/*fixe contenant le resultat de l'addition*/
  VAR(SInt16,AUTOMATIC)   add_tmp;             /*mise à la precision de sortie de la valeur retournee par l'addition*/


  if (Mem_man!=NULL_PTR)
  {
    S16_to_fixed(Inc_man, Inc_exp, &Inc_f);
    S16_to_fixed(*Mem_man, output_exp, &Mem_f);/*la donnee Mem est equivalent a la sortie a t -1 donc meme precision*/

    if ( On != 0 ) /* si On == 1*/
    {
      ADD_FIX(Inc_f,Mem_f,&Add_f) ;       /*fonction d'addition de 2 fixes*/

      add_tmp = fixed_to_S16(&Add_f, output_exp);
      S16_to_fixed(add_tmp, output_exp, &Add_f);

      output = (SInt16)Saturation_FIX (&Add_f, (SInt32)Max_man, Max_exp, (SInt32)Min_man, Min_exp);/*retourne la valeur d'entree saturee (ou non)*/
    }
    else /*si On == 0*/
    {
      output = (SInt16)Saturation_FIX (&Mem_f, (SInt32)Max_man, Max_exp, (SInt32)Min_man, Min_exp);/*retourne la valeur d'entree saturee (ou non)*/
    }

    *Mem_man = fixed_to_S16(&Mem_f, output_exp);
    *Mem_man = Delay1_SINT16 (&output, Mem_man); /*appel de la fonction qui cree un retard de 1*/

    if (TRUE==firstTime)
    {
      *Mem_man = 0;
      output = 0;
    }
    else
    {
      *Mem_man = output;
      *Mem_man = Delay1_SINT16 (&output, Mem_man); /*appel de la fonction qui cree un retard de 1*/
    }
  }
  else
  {
    FISA_erreur(FISA_ERREUR_NULL_POINTER);
    output = 0;
  }

  return (output);
}

#define FISA_STOP_SEC_CODE
#include "FISA_MemMap.h"
