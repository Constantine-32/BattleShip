/*----------------------------------------------------------------
|   Autor: Christian Callau Romero
|   e-mail: christian.callau@estudiants.urv.cat
|   Data: Desembre 2015                 Versio: 1.0
|-----------------------------------------------------------------|
|   Nom projecte: Vaixells
|   Nom: main.c
|   Descripcio del Programa:   Main del programa.
| ----------------------------------------------------------------*/

/* Incloure llibreries espeficiques */
#include "tipus.h"
#include "funcions.h"

/* Programa principal */
int main(void)
{
  /** Declara variables */
  int dim, num_jugadors, num_records;
  bool fin = false, joc = false;

  jugador_tipus jugadors[2];
  record_tipus records[MAX_RECORDS];

  srand((unsigned)time(NULL));

  /** Inici Algorisme */

  system("color 9f");
  pantalla_inici();

  if (recupera_records(FITXER_RECORDS, &num_records, records))
  {
    ordena_records(num_records, records);
    emmagatzema_records(FITXER_RECORDS, &num_records, records);
  }

  while (!fin)
  {
    switch (menu_principal(joc))
    {
    case 1:
      crea_joc(&dim, &num_jugadors, jugadors);
      joc = true;
      break;
    case 2:
      if (recupera_joc(FITXER_JOC, &dim, &num_jugadors, jugadors))
      {
        printf("\n\n  S'ha carregat una partida guardada.\n");
        printf("  Dimensio: %d\n", dim);
        printf("  Nombre de jugadors: %d\n", num_jugadors);
        printf("\n  Prem intro per continuar . . .");
        getchar();
        joc = true;
      }
      else
      {
        printf("\n\n  No hi ha cap joc emmagatzemat.");
        printf("\n  Prem intro per continuar . . .");
        getchar();
      }
      break;
    case 3:
      if (joc)
      {
        if (num_jugadors == 0 || num_jugadors == 1)
          joc = jugar_partida(dim, num_jugadors, jugadors, &num_records, records);
        if (num_jugadors == 2)
          joc = jugar_partida_dos(dim, jugadors, &num_records, records);
      }
      break;
    case 4:
      if (joc)
      {
        if (emmagatzema_joc(FITXER_JOC, dim, num_jugadors, jugadors))
        {
          printf("\n\n  Joc emmagatzemat!");
          printf("\n  Prem intro per continuar . . .");
          getchar();
        }
        else
        {
          printf("\n\n  Error! No s'ha pogut emmagatzemar el joc.");
          printf("\n  Prem intro per continuar . . .");
          getchar();
        }
      }
      break;
    case 5:
      veure_records(MAX_RECORDS, num_records, records);
      break;
    case 6:
      fin = true;
      break;
    default:
      break;
    }
  }
  return 0;
}
