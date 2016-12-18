/*----------------------------------------------------------------
|   Autor: Christian Callau Romero
|   e-mail: christian.callau@estudiants.urv.cat
|   Data: Desembre 2015                 Versio: 1.0
|-----------------------------------------------------------------|
|	Nom projecte: Vaixells
|	Nom: funcions.h
|   Descripcio del Programa:   Cap dels procediments.
| ----------------------------------------------------------------*/

#ifndef FUNCIONS_H_INCLUDED
#define FUNCIONS_H_INCLUDED

/* Incloure llibreries espeficiques */
#include "tipus.h"

/* Cap dels procediments */

/** -------------------------------------------------------
    ALTRES
    ------------------------------------------------------- */

/* pantalla que es mostra cuan s'ejecuta el joc */
extern void pantalla_inici(void);
/* accio feta per l'alumne per copiar cadenes de caracters */
extern void copiar_cadena(char *c, char *s);
/* retorna un valor enter corresponent a l'opcio triada */
extern int menu_principal(bool b);
/* inicia les taules i variables pertinents segons el mode de joc triat */
extern void crea_joc(int *dim, int *num_jugadors, jugador_tipus jugadors[]);
/* imprimeix la taula de vaixells i la taula de llançaments */
extern void imprimir_taules(int dim, char taula_1[][DIM_MAX], char taula_2[][DIM_MAX]);
/* sols imprimeix una taula */
extern void imprimir_taula(int dim, char taula[][DIM_MAX]);
/* inicia taulell de llançaments */
extern void inicia_taulell_llancaments(int dim, char taulell_llancaments[][DIM_MAX]);
/* obte coordenades valides del usuari */
extern void nova_jugada(int dim, coor_tipus *coor);
/* obte l'orientacio */
extern void nova_orientacio(int *orientacio);
/* busca els extrems nord-est i sud-oest del vaixell, delimita el quadre que conte el vaixell i tots els
punts adjacents a aquest amb dos punts(x1, x1),(y2, y2), finalment reemplaça les caselles vuides per aigua */
extern void descobrir_voltants(int f1, int c1, int dim, char taula[][DIM_MAX]);
/* actualitza la taula de llançaments segons el resultat de la funcio disparar */
extern void actualitza(char f, int c, int res, int dim, char taula[][DIM_MAX]);
/* funcio dispara feta per l'alumne */
extern int dispara(char fila, int col, char t[][DIM_MAX]);
/* funcio inicia_taulell feta per l'alumne */
extern void inicia_taulell(int dim, char taula[][DIM_MAX]);
/* imprimeix el resultat segons el valor de la funcio dispara */
extern void imp_resultat(int res);
/* pregunta si es vol continuar */
extern bool continuar(void);
/* s'encarrega de les mecaniques de jugar */
extern bool jugar_partida(int dim, int num_jugadors, jugador_tipus jugadors[], int *num_records, record_tipus records[]);
/* partida jugador vs maquina */
extern bool jugar_partida_dos(int dim, jugador_tipus jugadors[], int *num_records, record_tipus records[]);
/* calcula la puntuació al finalitzar cada partida */
extern int calcular_puntuacio(int jugades, int resultats, int dim);
/* si hi han records per veure els imprimeix per pantalla */
extern void veure_records(int num, int num_records, record_tipus records[]);
/* ordena els records en ordre descendent */
extern void ordena_records(int num_records, record_tipus records[]);

/** -------------------------------------------------------
    NIVEL 1
    ------------------------------------------------------- */
/*
accio jugar(var f:caracter, var c:enter, dim:enter,
              taulell_llancament:taula de caracters);
*/
extern void jugar(char *f, int *c, int dim, char taula[][DIM_MAX]);

/*
funcio emmagatzema_records(fitxer_record:taula de caracters, var
                             num_records:enter,
                             records:taula de record_tipus) retorna boolea.
*/
extern bool emmagatzema_records(char fitxer_record[], int *num_records, record_tipus records[]);

/*
funcio recupera_records(fitxer_record:taula de caracters, var num_records:enter,
                          records:taula de record_tipus) retorna boolea.
*/
extern bool recupera_records(char fitxer_record[], int *num_records, record_tipus records[]);

/** -------------------------------------------------------
    NIVEL 2
    ------------------------------------------------------- */
/*
funcio emmagatzema_joc(nom_fitxer:taula de caracters, dim, num_jugadors: enter,
                         jugadors:taula de jugador_tipus) retorna boolea;
*/
extern bool emmagatzema_joc(char fitxer_record[], int dim, int num_jugadors, jugador_tipus jugadors[]);

/*
funcio recupera_joc(nom_fitxer:taula de caracters, var dim, var num_jugadors: enter,
                         var jugadors:taula de jugador_tipus) retorna boolea;
*/
extern bool recupera_joc(char fitxer_record[], int *dim, int *num_jugadors, jugador_tipus jugadors[]);

/** -------------------------------------------------------
    NIVEL 3
    ------------------------------------------------------- */
/*
accio inicia_elmeu_taulell(dim:enter, taulell_vaixells:taula de caracters) ;
*/
extern void inicia_elmeu_taulell(int dim, char taulell_vaixells[][DIM_MAX]);

#endif /* FUNCIONS_H_INCLUDED */
