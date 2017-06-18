/*----------------------------------------------------------------
|   Autor: Christian Callau Romero
|   e-mail: christian.callau@estudiants.urv.cat
|   Data: Desembre 2015                 Versio: 1.0
|-----------------------------------------------------------------|
|   Nom projecte: Vaixells
|   Nom: tipus.h
|   Descripcio del Programa:   Tipus i constants del projecte.
| ----------------------------------------------------------------*/

#ifndef BATTLESHIP_TIPUS_H
#define BATTLESHIP_TIPUS_H

/* Incloure E/S i llibreries estandard */
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Definicio de constants del projecte*/
#define DIM_MAX         10
#define DIM_MIN         8
#define MAX_NOM         10    /* Doneu un valor a la constant */
#define MAX_RECORDS     25    /* Doneu un valor a la constant */

#define FITXER_RECORDS  "records.txt"   /* Doneu un nom al fitxer */
#define FITXER_JOC      "partida.bin"   /* Doneu un nom al fitxer */

enum orientacio
{
    HORITZONTAL = 0,
    VERTICAL = 1
};

enum casella
{
    CASELLA_BUIDA = '?',
    CASELLA_AIGUA = '.',
    CASELLA_VAIXELL = '@',
    CASELLA_VAIXELL_TOCAT = 'X',
    CASELLA_AIGUA_TOCADA = '-'
};

enum tret
{
    ERROR = -1,
    REPETIT = 0,
    AIGUA = 1,
    TOCAT = 2,
    ENFONSAT = 3
};


/* Definicio de nous tipus del projecte*/
/** -------------------------------------------------------
  NIVEL 1
  ------------------------------------------------------- */
typedef char nom_tipus[MAX_NOM];

typedef struct
{
    nom_tipus nom;
    int punts;

} record_tipus;

/** -------------------------------------------------------
  NIVEL 2
  ------------------------------------------------------- */
typedef struct
{
    char lletra;
    int nombre;

} coor_tipus;

typedef struct
{
    nom_tipus nom;
    coor_tipus coor;
    char vaixells[DIM_MAX][DIM_MAX], llancaments[DIM_MAX][DIM_MAX];
    int vaixells_enfonsats;
    int sum_resultats;
    int num_trets;
    int resultat;

} jugador_tipus;

#endif //BATTLESHIP_TIPUS_H
