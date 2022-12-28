/******************************************************************************/
/*                                                                            */
/* !Layer :                 APPLI                                             */
/*                                                                            */
/* !Component :             FISA                                              */
/* !Description :                                                             */
/*                                                                            */
/* !Module :               FISA_Fixed                                         */
/* !Description :        Librairie de calcul de nombres a virgule fixe        */
/*                                                                            */
/* !File :                     FISA_Fixed.c                                   */
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
/* $Archive::   P:/LIBPSA/LOG/Ref/SWC_VEMS/FISA/LOG/FISA_fixed.c_v          $*/
/* $Revision::   1.11      $$Author::   flavergn   $$Date::   21 Jul 2010 15:$*/
/******************************************************************************/
/* !VnrOff : Names imposed by the customer                                    */
/******************************************************************************/
/*U16_to_fixed                                                                */
/*S16_to_fixed                                                                */
/*S32_to_fixed                                                                */
/*fixed_to_S16                                                                */
/*fixed_to_S32                                                                */
/*max_mantisse32                                                              */
/*min_mantisse                                                                */
/*multiplier_fixed                                                            */
/*diviser_fixed                                                               */
/*minimum_fixed                                                               */
/*maximum_fixed                                                               */
/*aligner_virgule                                                             */
/*additionner_fixed                                                           */
/*soustraire_fixed                                                            */
/******************************************************************************/
#include "FISA_fixed.h"
#include "FISA_lib.h"


#define FIXED_ERROR FISA_erreur(FISA_ERREUR_FIXED)

FUNC(_STATIC_ void,FISA_CODE) max_mantisse32(
                P2VAR(UInt32, FISA_APPL_DATA, AUTOMATIC) mantisse,
                P2VAR(SInt16, FISA_APPL_DATA, AUTOMATIC) exposant);

FUNC(_STATIC_ void,FISA_CODE) min_mantisse(
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) mantisse,
                P2VAR(SInt16, FISA_APPL_DATA, AUTOMATIC) exposant);

FUNC(_STATIC_ void,FISA_CODE) aligner_virgule(
                P2VAR(UInt32, FISA_APPL_DATA, AUTOMATIC)   f1_mantisse,
                SInt16 f1_exposant,
                P2VAR(UInt32, FISA_APPL_DATA, AUTOMATIC)   f2_mantisse,
                SInt16 f2_exposant,
                P2VAR(ts_fixed, FISA_APPL_DATA, AUTOMATIC) f3);

#define FISA_START_SEC_CODE
#include "FISA_MemMap.h"
/************************************************************************************/
/*                                                                                  */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : S.Corbe (GEENSYS)                                                 */
/************************************************************************************/

/* Transformer un UInt16 en virgule fixe */
FUNC(void,FISA_CODE) U16_to_fixed(Boolean sign, UInt16 mantisse, SInt16 exposant,
                  P2VAR(ts_fixed, FISA_APPL_DATA, AUTOMATIC) fixed)
{
    if (!fixed)
    {
      FIXED_ERROR;
    }
    else
    {
      fixed->sign = sign;
      fixed->mantisse = mantisse;
      fixed->exposant = exposant;
    }
}
/************************************************************************************/
/*                                                                                  */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : S.Corbe (GEENSYS)                                                 */
/************************************************************************************/
/* Transformer un SInt16 en virgule fixe */
FUNC(void,FISA_CODE) S16_to_fixed(SInt16 mantisse, SInt16 exposant,
                  P2VAR(ts_fixed, FISA_APPL_DATA, AUTOMATIC) fixed)
{
    if (!fixed)
    {
      FIXED_ERROR;
    }
    else
    {
      if (mantisse>0)
      {
          fixed->sign = SIGNE_PLUS;
          fixed->mantisse = (UInt16) mantisse;
      }
      else
      {
          fixed->sign = SIGNE_MOINS;
          fixed->mantisse = (UInt16) -mantisse;
      }
      fixed->exposant = exposant;
    }
}

/************************************************************************************/
/*                                                                                  */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : S.Corbe (GEENSYS)                                                 */
/************************************************************************************/
/* Transformer un virgule fixe en UInt16 */

FUNC(UInt16,FISA_CODE) fixed_to_U16(P2CONST(ts_fixed, FISA_APPL_DATA, AUTOMATIC) f,
                  SInt16 exposant)
{
  VAR(UInt16,AUTOMATIC)  tmp;
  VAR(UInt16,AUTOMATIC)  i;
  VAR(Boolean,AUTOMATIC) err = FALSE;

  if (!f)
  {
    FIXED_ERROR;
    tmp = 0;
  }
  else
  {
    tmp = f->mantisse;

    if (exposant > f->exposant)
    {
      for (i=0; i<(UInt16)(exposant-f->exposant); i++)
      {
        tmp = (UInt16) ( (tmp+5)/10 );
      }
    }
    else
    {
      if (exposant < f->exposant)
      {
        for (i=0; (i<(UInt16)(f->exposant-exposant)) && (FALSE==err); i++)
        {
          if (tmp > (MAXUSHORT/10))
          {
            FIXED_ERROR;
            err = TRUE; /* Overflow */
          }
          else
          {
            tmp *= 10;
          }
        }
      }
    }
  }
  if (TRUE==err)
  {
    tmp = MAXUSHORT;
  }
  return tmp;
}

/************************************************************************************/
/*                                                                                  */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : S.Corbe (GEENSYS)                                                 */
/************************************************************************************/
/* Transformer un virgule fixe en UInt32 */

FUNC(UInt32,FISA_CODE) fixed_to_U32(P2CONST(ts_fixed, FISA_APPL_DATA, AUTOMATIC) f,
                  SInt16 exposant)

{
  VAR(UInt32,AUTOMATIC)  tmp;
  VAR(UInt16,AUTOMATIC)  i;
  VAR(Boolean,AUTOMATIC) err = FALSE;

  if (!f)
  {
    FIXED_ERROR;
    tmp = 0;
  }
  else
  {
    tmp = f->mantisse;

    if (exposant > f->exposant)
    {
      for (i=0; i<(UInt16)(exposant-f->exposant); i++)
      {
        tmp = (tmp+5)/10;
      }
    }
    else
    {
      if (exposant < f->exposant)
      {
        for (i=0; (i<(UInt16)(f->exposant-exposant)) && (FALSE==err); i++)
        {
          if (tmp > (MAXULONG/10))
          {
            FIXED_ERROR;
            err = TRUE; /* Overflow */
          }
          else
          {
            tmp *= 10;
          }
        }
      }
    }
  }
  if (TRUE==err)
  {
    tmp = MAXULONG;
  }
  return tmp;
}

/************************************************************************************/
/*                                                                                  */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : S.Corbe (GEENSYS)                                                 */
/************************************************************************************/
/* Transformer un SInt32 en virgule fixe */

FUNC(void,FISA_CODE) S32_to_fixed(  SInt32 mantisse,
                  SInt16 exposant,
                  P2VAR(ts_fixed, FISA_APPL_DATA, AUTOMATIC) fixed)
{
  VAR(UInt32,AUTOMATIC) tmp;

  if (!fixed)
  {
    FIXED_ERROR;
  }
  else
  {
    if (mantisse>0)
    {
      fixed->sign = SIGNE_PLUS;
    }
    else
    {
      fixed->sign = SIGNE_MOINS;
      mantisse = -mantisse;
    }
    fixed->exposant = exposant;

    tmp = (UInt32)mantisse;

    while(tmp>MAXUSHORT)
    {
      tmp = (tmp+5)/10;
      fixed->exposant++;
    }

    fixed->mantisse = (UInt16)tmp;
  }
}

/************************************************************************************/
/*                                                                                  */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : S.Corbe (GEENSYS)                                                 */
/************************************************************************************/
/* Transformer un virgule fixe en SInt16 */

FUNC(SInt16,FISA_CODE) fixed_to_S16(P2CONST(ts_fixed, FISA_APPL_DATA, AUTOMATIC) f,
                  SInt16 exposant)
{
  VAR(SInt32,AUTOMATIC)  tmp;
  VAR(UInt16,AUTOMATIC)  i;
  VAR(Boolean,AUTOMATIC) err = FALSE;

  if (!f)
  {
    FIXED_ERROR;
    tmp = 0;
  }
  else
  {
    tmp = (SInt32)f->mantisse;

    if (exposant > f->exposant)
    {
      for (i=0; i<(UInt16)(exposant-f->exposant); i++)
      {
        tmp = (tmp+5)/10;
      }
    }
    else
    {
      if (exposant < f->exposant)
      {
        for (i=0; (i<(UInt16)(f->exposant-exposant)) && (FALSE==err); i++)
        {
          if (tmp > (MAXSSHORT/10))
          {
            FIXED_ERROR;
            err = TRUE; /* Overflow */
          }
          else
          {
            tmp *= 10;
          }
        }
      }
    }

    if (SIGNE_MOINS == f->sign)
    {
      tmp = -tmp;
    }

    if (TRUE==err)
    {
      if (SIGNE_MOINS == f->sign)
      {
        tmp = MINSSHORT;
      }
      else
      {
        tmp = MAXSSHORT;
      }
    }
  }

  return (SInt16)tmp;
}

/************************************************************************************/
/*                                                                                  */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : S.Corbe (GEENSYS)                                                 */
/************************************************************************************/
/* Transformer un virgule fixe en SInt32 */

FUNC(SInt32,FISA_CODE) fixed_to_S32(P2CONST(ts_fixed, FISA_APPL_DATA, AUTOMATIC) f,
                  SInt16 exposant)
{
  VAR(UInt32,AUTOMATIC)  tmp;
  VAR(SInt32,AUTOMATIC)  stmp;
  VAR(UInt16,AUTOMATIC)  i;
  VAR(Boolean,AUTOMATIC) err = FALSE;

  if (!f)
  {
    FIXED_ERROR;
    stmp = 0;
  }
  else
  {
    tmp = f->mantisse;

    if (exposant > f->exposant)
    {
      for (i=0; i<(UInt16)(exposant-f->exposant); i++)
      {
        tmp = (tmp+5)/10;
      }
    }
    else
    {
      if (exposant < f->exposant)
      {
        for (i=0; (i<(UInt16)(f->exposant-exposant)) && (FALSE==err); i++)
        {
          if (tmp > (MAXSLONG/10))
          {
            FIXED_ERROR;  /* Overflow */
            err = TRUE;
          }
          else
          {
            tmp *= 10;
          }
        }
      }
    }

    if (TRUE==err)
    {
      if (SIGNE_MOINS == f->sign)
      {
        stmp = MINSLONG;
      }
      else
      {
        stmp = MAXSLONG;
      }
    }
    else
    {
      if (SIGNE_MOINS == f->sign)
      {
        stmp = -(SInt32)tmp;
      }
      else
      {
        stmp = (SInt32)tmp;
      }
    }
  }
  return stmp;
}

/************************************************************************************/
/*                                                                                  */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : S.Corbe (GEENSYS)                                                 */
/************************************************************************************/
/* max_mantise32 : Coder le meme nombre, mais en utilisant pleinement la mantisse */

_STATIC_ FUNC(void,FISA_CODE) max_mantisse32(
                P2VAR(UInt32, FISA_APPL_DATA, AUTOMATIC) mantisse,
                P2VAR(SInt16, FISA_APPL_DATA, AUTOMATIC) exposant)
{
  if ((!mantisse) || (!exposant))
  {
    FIXED_ERROR;
  }
  else
  {
    /* Si la mantisse est nulle, il n'y a rien a faire */
    if (!*mantisse)
    {
      *exposant = 0;
    }
    else
    {
      while (*mantisse < (MAXULONG/10))
      {
        *mantisse *= 10;
        *exposant -= 1;
      } /* QAC croit que la variable de controle est mantisse, alors que c'est *mantisse */
    }
  }
}

/************************************************************************************/
/*                                                                                  */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : S.Corbe (GEENSYS)                                                 */
/************************************************************************************/
/* min_mantise : Coder le meme nombre, mais en utilisant le moins possible la mantisse */

_STATIC_ FUNC(void,FISA_CODE) min_mantisse(
                P2VAR(UInt16, FISA_APPL_DATA, AUTOMATIC) mantisse,
                P2VAR(SInt16, FISA_APPL_DATA, AUTOMATIC) exposant)
{
  VAR(Boolean,AUTOMATIC) sortie = 0;

  if ((!mantisse) || (!exposant))
  {
    FIXED_ERROR;
  }
  else
  {
    do
    {
      if ((*mantisse % 10)==0)
      {
        *mantisse /= 10;
        *exposant += 1;
      }
      else
      {
         sortie=1;
      }
    } while (!sortie);
  }
}

/************************************************************************************/
/*                                                                                  */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : S.Corbe (GEENSYS)                                                 */
/************************************************************************************/
/* Multiplication de deux virgules fixes */

FUNC(void,FISA_CODE) multiplier_fixed(  Boolean f1_sign,
                    UInt16  f1_mantisse,
                    SInt16  f1_exposant,
                    Boolean f2_sign,
                    UInt16  f2_mantisse,
                    SInt16  f2_exposant,
                    P2VAR(ts_fixed, FISA_APPL_DATA, AUTOMATIC) f3)
{
  VAR(UInt32,AUTOMATIC) tmp;

  if (!f3)
  {
    FIXED_ERROR;
  }
  else
  {
    f3->sign = (Boolean) ( f1_sign ^ f2_sign );
    f3->exposant = (SInt16) (f1_exposant + f2_exposant);
    tmp = f1_mantisse;
    tmp = tmp*(UInt32)f2_mantisse;

    /* Si la multiplication est en overflow, on diminue la mantisse et augmente l'exposant jusqu'a ce que ca rentre */
    while(tmp>MAXUSHORT)
    {
      tmp = (tmp+5)/10;
      f3->exposant++;
    }
    f3->mantisse = (UInt16)tmp;
  }
}

/************************************************************************************/
/*                                                                                  */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : S.Corbe (GEENSYS)                                                 */
/************************************************************************************/
/* Division de deux virgules fixes */

FUNC(void,FISA_CODE) diviser_fixed(  Boolean f1_sign,
                  UInt16  f1_mantisse,
                  SInt16  f1_exposant,
                  Boolean f2_sign,
                  UInt16  f2_mantisse,
                  SInt16  f2_exposant,
                  P2VAR(ts_fixed, FISA_APPL_DATA, AUTOMATIC) f3)
{
  VAR(UInt32,AUTOMATIC) tmp;

  if ((!f3) || (!f2_mantisse))
  {
    FIXED_ERROR;
  }
  else
  {
    f3->sign = (Boolean) (f1_sign ^ f2_sign);

    switch(f2_mantisse)
    {
      case (UInt16)1:
          f3->mantisse = f1_mantisse;
          f3->exposant = (SInt16) (f1_exposant - f2_exposant);
          break;

      case (UInt16)10:
          f3->mantisse = f1_mantisse;
          f3->exposant = (SInt16) (f1_exposant - f2_exposant -1);
          break;

      case (UInt16)100:
          f3->mantisse = f1_mantisse;
          f3->exposant = (SInt16) (f1_exposant - f2_exposant -2);
          break;

      case (UInt16)1000:
          f3->mantisse = f1_mantisse;
          f3->exposant = (SInt16) (f1_exposant - f2_exposant -3);
          break;

      case (UInt16)10000:
          f3->mantisse = f1_mantisse;
          f3->exposant = (SInt16) (f1_exposant - f2_exposant -4);
          break;

      default:
      /* Cas non simple, on va maximiser la mantisse du dividende et minimiser celle du diviseur
       pour eviter de perdre trop de precision */

        tmp = (UInt32)f1_mantisse;
        max_mantisse32(&tmp, &f1_exposant);
        min_mantisse(&f2_mantisse, &f2_exposant);

        f3->exposant = (SInt16) (f1_exposant - f2_exposant);
        tmp = tmp / f2_mantisse; /* QAC croit que f2_mantisse peut etre null, alors qu'il a ete teste */

        while(tmp>MAXUSHORT)
        {
          tmp = (tmp+5)/10;
          f3->exposant++;
        }
        f3->mantisse = (UInt16)tmp;
    }
  }
}

/************************************************************************************/
/*                                                                                  */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : S.Corbe (GEENSYS)                                                 */
/************************************************************************************/
/* Minimum entre deux virgules fixes */

FUNC(void,FISA_CODE) minimum_fixed(  Boolean f1_sign,
                  UInt16  f1_mantisse_p,
                  SInt16  f1_exposant,
                  Boolean f2_sign,
                  UInt16  f2_mantisse_p,
                  SInt16  f2_exposant,
                  P2VAR(ts_fixed, FISA_APPL_DATA, AUTOMATIC) f3)
{
  VAR(UInt32,AUTOMATIC) f1_mantisse;
  VAR(UInt32,AUTOMATIC) f2_mantisse;

  if (!f3)
  {
    FIXED_ERROR;
  }
  else
  {
    if ( (f1_sign ^ f2_sign) != 0 )
    {
      /* Les deux nombres sont de signes differents
         donc on renvoie le negatif */
      f3->sign = SIGNE_MOINS;

      if (SIGNE_MOINS == f1_sign)
      {
        f3->mantisse = f1_mantisse_p;
        f3->exposant = f1_exposant;
      }
      else
      {
        f3->mantisse = f2_mantisse_p;
        f3->exposant = f2_exposant;
      }
    }
    else
    {
      f1_mantisse = f1_mantisse_p;
      f2_mantisse = f2_mantisse_p;

      /* Sinon il faut aligner la virgule pour comparer les mantisses */
      aligner_virgule(&f1_mantisse, f1_exposant, &f2_mantisse, f2_exposant, f3);
      f3->sign = f1_sign;

      if (SIGNE_MOINS == f1_sign)
      {
          f3->mantisse = (UInt16)FISA_UMAX(f1_mantisse, f2_mantisse);
      }
      else
      {
          f3->mantisse = (UInt16)FISA_UMIN(f1_mantisse, f2_mantisse);
      }
    }
  }
}

/************************************************************************************/
/*                                                                                  */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : S.Corbe (GEENSYS)                                                 */
/************************************************************************************/
/* Maximum deux virgules fixes */

FUNC(void,FISA_CODE) maximum_fixed(  Boolean f1_sign,
                  UInt16  f1_mantisse_p,
                  SInt16  f1_exposant,
                  Boolean f2_sign,
                  UInt16  f2_mantisse_p,
                  SInt16  f2_exposant,
                  P2VAR(ts_fixed, FISA_APPL_DATA, AUTOMATIC) f3)
{
  VAR(UInt32,AUTOMATIC) f1_mantisse;
  VAR(UInt32,AUTOMATIC) f2_mantisse;

  if (!f3)
  {
    FIXED_ERROR;
  }
  else
  {
    if ( (f1_sign ^ f2_sign) != 0)
    {
      /* Les deux nombres sont de signes differents
         donc on renvoie le positif */
      f3->sign = SIGNE_PLUS;

      if (SIGNE_PLUS == f1_sign)
      {
        f3->mantisse = f1_mantisse_p;
        f3->exposant = f1_exposant;
      }
      else
      {
        f3->mantisse = f2_mantisse_p;
        f3->exposant = f2_exposant;
      }
    }
    else
    {
      f1_mantisse = f1_mantisse_p;
      f2_mantisse = f2_mantisse_p;

      /* Sinon il faut aligner la virgule pour comparer les mantisses */
      aligner_virgule(&f1_mantisse, f1_exposant, &f2_mantisse, f2_exposant, f3);
      f3->sign = f1_sign;

      if (SIGNE_PLUS == f1_sign)
      {
        f3->mantisse = (UInt16)FISA_UMAX(f1_mantisse, f2_mantisse);
      }
      else
      {
        f3->mantisse = (UInt16)FISA_UMIN(f1_mantisse, f2_mantisse);
      }
    }
  }
}

/************************************************************************************/
/*                                                                                  */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : S.Corbe (GEENSYS)                                                 */
/************************************************************************************/
/* Aligner deux virgules fixes sur leurs virgules, permet d'effectuer l'addition et la soustraction */

_STATIC_ FUNC(void,FISA_CODE) aligner_virgule(
                P2VAR(UInt32, FISA_APPL_DATA, AUTOMATIC)   f1_mantisse,
                SInt16 f1_exposant,
                P2VAR(UInt32, FISA_APPL_DATA, AUTOMATIC)   f2_mantisse,
                SInt16 f2_exposant,
                P2VAR(ts_fixed, FISA_APPL_DATA, AUTOMATIC) f3)
{
  VAR(UInt16,AUTOMATIC) i;

  if ((!f3) || (!f1_mantisse) || (!f2_mantisse))
  {
    FIXED_ERROR;
  }
  else
  {
    if (f1_exposant == f2_exposant)
    {
      /* La virgule est deja alignee */
      f3->exposant = f1_exposant;
    }
    else
    {
      /* sinon on s'aligne sur l'exposant le plus petit */
      if (f1_exposant > f2_exposant)
      {
        f3->exposant = f2_exposant;
        for (i=0; i<(UInt16)(f1_exposant-f2_exposant); i++)
        {
          *f1_mantisse *= 10;
        }
      }
      else
      /* f2_exposant > f1_exposant */
      {
        f3->exposant = f1_exposant;
        for (i=0; i<(UInt16)(f2_exposant-f1_exposant); i++)
        {
          *f2_mantisse *= 10;
        }
      }
    }
  }
}

/************************************************************************************/
/*                                                                                  */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : S.Corbe (GEENSYS)                                                 */
/************************************************************************************/
/* Addition de deux virgules fixes */

FUNC(void,FISA_CODE) additionner_fixed(  Boolean f1_sign,
                    UInt16  f1_mantisse_p,
                    SInt16  f1_exposant,
                    Boolean f2_sign,
                    UInt16  f2_mantisse_p,
                    SInt16  f2_exposant,
                    P2VAR(ts_fixed, FISA_APPL_DATA, AUTOMATIC) f3)
{
  VAR(UInt32,AUTOMATIC) f1_mantisse;
  VAR(UInt32,AUTOMATIC) f2_mantisse;
  VAR(UInt32,AUTOMATIC) tmp;

  if (!f3)
  {
    FIXED_ERROR;
  }
  else
  {
    /* Si un des deux arguments est negligeable, retourner l'autre */
    if ((f1_exposant-f2_exposant) > 4)
    {
      f3->sign = f1_sign;
      f3->mantisse = f1_mantisse_p;
      f3->exposant = f1_exposant;
    }
    else
    {
      if ((f2_exposant-f1_exposant) > 4)
      {
        f3->sign = f2_sign;
        f3->mantisse = f2_mantisse_p;
        f3->exposant = f2_exposant;
      }
      else
      {
        f1_mantisse = f1_mantisse_p;
        f2_mantisse = f2_mantisse_p;

        /* Pour l'addition, il faut d'abord aligner la virgule */
        aligner_virgule(&f1_mantisse, f1_exposant, &f2_mantisse, f2_exposant, f3);

        /* Maintenant que les mantisses sont de meme ordre, on peut les additionner, mais en tenant compte du signe */
        if (f1_sign == f2_sign)
        {
          f3->sign = f1_sign;
          tmp = f1_mantisse+f2_mantisse;
        }
        else
        {
          if (SIGNE_MOINS == f1_sign)
          {
            if (f1_mantisse > f2_mantisse)
            {
              f3->sign = SIGNE_MOINS;
              tmp = f1_mantisse - f2_mantisse;
            }
            else
            {
              f3->sign = SIGNE_PLUS;
              tmp = f2_mantisse - f1_mantisse;
            }
          }
          else
          /*if (SIGNE_MOINS == f2_sign)*/
          {
            if (f2_mantisse > f1_mantisse)
            {
              f3->sign = SIGNE_MOINS;
              tmp = f2_mantisse - f1_mantisse;
            }
            else
            {
              f3->sign = SIGNE_PLUS;
              tmp = f1_mantisse - f2_mantisse;
            }
          }
        }

        /* Si l'addition est en overflow, on diminue la mantisse et augmente l'exposant jusqu'a ce que ca rentre */
        while(tmp>MAXUSHORT)
        {
          tmp = (tmp+5)/10;
          f3->exposant++;
        }
        f3->mantisse = (UInt16)tmp;
      }
    }
  }
}

/************************************************************************************/
/*                                                                                  */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : S.Corbe (GEENSYS)                                                 */
/************************************************************************************/
/* Soustraction de deux virgules fixes */

FUNC(void,FISA_CODE) soustraire_fixed(  Boolean f1_sign,
                    UInt16  f1_mantisse_p,
                    SInt16  f1_exposant,
                    Boolean f2_sign,
                    UInt16  f2_mantisse_p,
                    SInt16  f2_exposant,
                    P2VAR(ts_fixed, FISA_APPL_DATA, AUTOMATIC) f3)
{
  VAR(UInt32,AUTOMATIC) f1_mantisse;
  VAR(UInt32,AUTOMATIC) f2_mantisse;
  VAR(UInt32,AUTOMATIC) tmp;

  if (!f3)
  {
    FIXED_ERROR;
  }
  else
  {
    /* Si un des deux arguments est negligeable, retourner l'autre */
    if ((f1_exposant-f2_exposant) > 4)
    {
      f3->sign = f1_sign;
      f3->mantisse = f1_mantisse_p;
      f3->exposant = f1_exposant;
    }
    else
    {
      if ((f2_exposant-f1_exposant) > 4)
      {
        f3->sign = !f2_sign;
        f3->mantisse = f2_mantisse_p;
        f3->exposant = f2_exposant;
      }
      else
      {
        f1_mantisse = f1_mantisse_p;
        f2_mantisse = f2_mantisse_p;

        /* Pour la soustraction, il faut d'abord aligner la virgule */
        aligner_virgule(&f1_mantisse, f1_exposant, &f2_mantisse, f2_exposant, f3);

        /* Maintenant que les mantisses sont de meme ordre, on peut les soustraire, mais en tenant compte du signe */
        if (f1_sign != f2_sign)
        {
          f3->sign = f1_sign;
          tmp = f1_mantisse+f2_mantisse;
        }
        else
        {
          if (SIGNE_MOINS == f1_sign)
          {
            if (f1_mantisse > f2_mantisse)
            {
              f3->sign = SIGNE_MOINS;
              tmp = f1_mantisse - f2_mantisse;
            }
            else
            {
              f3->sign = SIGNE_PLUS;
              tmp = f2_mantisse - f1_mantisse;
            }
          }
          else
          /*if (SIGNE_PLUS == f1_sign)*/
          {
            if (f2_mantisse > f1_mantisse)
            {
              f3->sign = SIGNE_MOINS;
              tmp = f2_mantisse - f1_mantisse;
            }
            else
            {
              f3->sign = SIGNE_PLUS;
              tmp = f1_mantisse - f2_mantisse;
            }
          }
        }
        /* Si la mantisse est en overflow, on diminue la mantisse et augmente l'exposant jusqu'a ce que ca rentre */
        while(tmp>MAXUSHORT)
        {
          tmp = (tmp+5)/10;
          f3->exposant++;
        }
        f3->mantisse = (UInt16)tmp;
      }
    }
  }
}

/************************************************************************************/
/*                                                                                  */
/*                                                                                  */
/************************************************************************************/
/* !LastAuthor  : S.Corbe (GEENSYS)                                                 */
/************************************************************************************/
/* Transformer un virgule fixe en UInt8 */

FUNC(UInt8,FISA_CODE) fixed_to_U8(P2CONST(ts_fixed, FISA_APPL_DATA, AUTOMATIC) f,
                  SInt16 exposant)
{
  VAR(UInt16,AUTOMATIC)  tmp;
  VAR(UInt16,AUTOMATIC)  i;
  VAR(Boolean,AUTOMATIC) err = FALSE;

  if (!f)
  {
    FIXED_ERROR;
    tmp = 0;
  }
  else
  {
    tmp = f->mantisse;

    if (exposant > f->exposant)
    {
      for (i=0; i<(UInt16)(exposant-f->exposant); i++)
      {
        tmp = (UInt16) ( (tmp+5)/10 );
      }
    }
    else
    {
      if (exposant < f->exposant)
      {
        for (i=0; (i<(UInt16)(f->exposant-exposant)) && (FALSE==err); i++)
        {
          if (tmp > (MAXUCHAR/10))
          {
            FIXED_ERROR;
            err=TRUE; /* Overflow */
          }
          else
          {
            tmp *= 10;
          }
        }
      }
    }

    if (TRUE==err)
    {
      tmp = MAXUCHAR;
    }
    else
    {
      if (tmp>MAXUCHAR)
      {
        FIXED_ERROR;
        tmp = MAXUCHAR; /* Overflow */
      }
    }
  }
  return (UInt8)tmp;
}

#define FISA_STOP_SEC_CODE
#include "FISA_MemMap.h"
