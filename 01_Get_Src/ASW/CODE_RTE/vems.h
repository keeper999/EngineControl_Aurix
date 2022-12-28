/*****************************************************************************/
/*                                                                           */
/* !Layer          : VEMS_INTERFACE                                          */
/*                                                                           */
/* !Component      : VEMS_INTERFACE                                          */
/*                                                                           */
/* !Module         : VEMS                                                    */
/* !Description    : Declaration des constantes inter T4 qui doivent etre    */
/*                   visualisées par des outils                              */
/* !File           : vems.h                                          */
/*                                                                           */
/* !Scope          : Public Component                                        */
/*                                                                           */
/* !Target         : All                                                     */
/*                                                                           */
/* !Vendor         : Valeo                                                   */
/*                                                                           */
/* Coding language : C                                                       */
/*                                                                           */
/* COPYRIGHT 2006 VALEO                                                      */
/* all rights reserved                                                       */
/*                                                                           */
/*****************************************************************************/
/*       Fichier genere automatiquement (T3ToRte version 2.07)               */
/*****************************************************************************/
/* PVCS Information                                                          */
/* $Archive::   I:/PROJETS/EBX6_2/LOG/ASW/REF/MODULES/CODE_RTE/vems.h_v      $*/
/* $Revision::   1.1      $$Author::   ygorget        $$Date::   29 Aug 2014 $*/
/*****************************************************************************/
/* génére le mercredi 9 décembre 2009 a 10:38:56                             */
/*****************************************************************************/

#ifndef VEMS_H_AUTOCODE_H
#define VEMS_H_AUTOCODE_H

/*****************************************************************************/
#include "SWFAIL.h"
#include "Rte_VEMS_Interface.h"

#include "VEMS_RTE.h"
#include "VEMS_GLOBAL.h"

/* Temporaire, devra être suppirmé par la suite */
#include "VEMS_manual.h" /* A laisser en attendant que les vidGet/Set sur les variables locales soient supprimées */
/* Fin tempraire */

/**********************************************************************************
   Macros generique du vidSet (variable simple)
 **********************************************************************************/
#define VEMS_vidSET(name,value) vidSET_VALUE_##name(value)
#define VEMS_vidGET(varName,tempVar) vidGET_VALUE_##varName(tempVar)

/**********************************************************************************
   Macros generique du vidSet (pour les tableaux)
 **********************************************************************************/
#define VEMS_vidSET1DArray(tabname,size,tabvalue) vidSET_ARRAY_##tabname(tabvalue,size)
#define VEMS_vidGET1DArray(tabname,size,tabvalue) vidGET_ARRAY_##tabname(tabvalue,size)

#define VEMS_vidSET1DArrayElement(tabname,pos,variable) vidSET_ARRAY_ELEMENT_##tabname(variable,pos)
#define VEMS_vidGET1DArrayElement(tabname,pos,variable) vidGET_ARRAY_ELEMENT_##tabname(variable,pos)

/**********************************************************************************
   Macros generique du vidSet (pour les matrices)
 **********************************************************************************/
#define VEMS_vidSET2DArray(matname,lines,columns,matvalue) vidSET_ARRAY2D_##matname(matvalue,lines*columns)
#define VEMS_vidGET2DArray(matname,lines,columns,matvalue) vidGET_ARRAY2D_##matname(matvalue,lines*columns)

#define VEMS_vidSET2DArrayElement(matname,PosLin,PosCol,variable) vidSET_ARRAY2D_ELEMENT_##matname(variable,PosLin,PosCol)
#define VEMS_vidGET2DArrayElement(matname,PosLin,PosCol,variable) vidGET_ARRAY2D_ELEMENT_##matname(variable,PosLin,PosCol)

/**********************************************************************************
                                   Fin de fichier
 **********************************************************************************/

#endif
