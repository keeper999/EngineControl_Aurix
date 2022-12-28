#define ENUSTDGO                  0     /* index for the field enuStDgo */
#define GOBD_CTDC                 1     /* index for the field GOBD_ctDc */
#define GOBD_BNCFDC               2     /* index for the field GOBD_bNCfDC */
#define GOBD_CTWUC                3     /* index for the field GOBD_ctWuc */
#define NOHEALDC                  4     /* index for the field noHealDC */
#define EXITEVESTOBDREC           5     /* index for the field ExitEveStObdRec */
#define EXITEVESTOBD              6     /* index for the field ExitEveStObd */
#define STOREEVESTOBD             7     /* index for the field StoreEveStObd */
#define EXITEVESTOBDCLEAR         8     /* index for the field ExitEveStObdClear */

#define NB_TEST         19
#define NB_FIELD        9



uint8 TabIn[ NB_TEST ][ NB_FIELD ] =
{
   {GOBD_ETAT_OK,5,0,1,0,0,1,0,0},
   {GOBD_ETAT_OK,0,1,1,0,1,1,1,0},
   {GOBD_ETAT_OK,0,0,1,0,0,0,0,0},
   {GOBD_ETAT_PENDING1,0,0,1,0,0,1,0,0},
   {GOBD_ETAT_PENDING1,2,1,1,0,1,1,1,0},
   {GOBD_ETAT_PENDING1,6,0,1,0,0,0,0,0},
   {GOBD_ETAT_PENDING2,3,1,1,0,0,1,1,0},
   {GOBD_ETAT_PENDING2,0,0,1,0,0,1,0,0},
   {GOBD_ETAT_PENDING2,4,0,1,0,0,0,0,0},
   {GOBD_ETAT_ENREGISTRE,7,0,1,8,0,1,0,0},
   {GOBD_ETAT_ENREGISTRE,0,0,1,0,0,1,0,0},
   {GOBD_ETAT_ENREGISTRE,5,0,1,4,0,0,0,0},
   {GOBD_ETAT_HISTORIQUE_ON,7,0,1,7,0,1,1,0},
   {GOBD_ETAT_HISTORIQUE_ON,0,0,1,7,0,1,0,0},
   {GOBD_ETAT_HISTORIQUE_ON,4,0,1,7,0,0,0,0},
   {GOBD_ETAT_HISTORIQUE_OFF,4,1,1,3,0,1,1,0},
   {GOBD_ETAT_HISTORIQUE_OFF,5,0,1,7,0,1,0,0},
   {GOBD_ETAT_HISTORIQUE_OFF,0,0,0,4,0,1,0,1},
   {GOBD_ETAT_HISTORIQUE_OFF,0,0,1,8,0,0,0,0}
};

uint8 TabOut[ NB_TEST ][ NB_FIELD ] =
{
   {GOBD_ETAT_PENDING1,5,0,1,0,0,0,0,0},
   {GOBD_ETAT_ENREGISTRE,0,1,1,0,0,0,0,0},
   {GOBD_ETAT_OK,0,0,1,0,0,0,0,0},
   {GOBD_ETAT_OK,0,0,1,0,0,0,0,0},
   {GOBD_ETAT_ENREGISTRE,2,1,1,0,0,0,0,0},
   {GOBD_ETAT_PENDING1,6,0,1,0,0,0,0,0},
   {GOBD_ETAT_ENREGISTRE,3,1,1,0,0,0,0,0},
   {GOBD_ETAT_HISTORIQUE_OFF,0,0,1,0,0,0,0,0},
   {GOBD_ETAT_PENDING2,4,0,1,0,0,0,0,0},
   {GOBD_ETAT_HISTORIQUE_ON,7,0,1,8,0,0,0,0},
   {GOBD_ETAT_HISTORIQUE_OFF,0,0,1,0,0,0,0,0},
   {GOBD_ETAT_ENREGISTRE,5,0,1,4,0,0,0,0},
   {GOBD_ETAT_ENREGISTRE,7,0,1,7,0,0,0,0},
   {GOBD_ETAT_HISTORIQUE_OFF,0,0,1,7,0,0,0,0},
   {GOBD_ETAT_HISTORIQUE_ON,4,0,1,7,0,0,0,0},
   {GOBD_ETAT_ENREGISTRE,4,1,1,3,0,0,0,0},
   {GOBD_ETAT_PENDING2,5,0,1,7,0,0,0,0},
   {GOBD_ETAT_OK,0,0,0,4,0,0,0,0},
   {GOBD_ETAT_HISTORIQUE_OFF,0,0,1,8,0,0,0,0}
};
