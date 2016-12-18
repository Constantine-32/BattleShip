/*----------------------------------------------------------------
|   Autor: Christian Callau Romero
|   e-mail: christian.callau@estudiants.urv.cat
|   Data: Desembre 2015                 Versio: 1.0
|-----------------------------------------------------------------|
|   Nom projecte: Vaixells
|   Nom: funcions.c
|   Descripcio del Programa:   Implementacio dels procediments.
| ----------------------------------------------------------------*/

/* Incloure llibreries espeficiques */
#include "tipus.h"
#include "funcions.h"

/** Funcions propies */
void pantalla_inici(void)
{
  printf("\n      _____  _   _  _____ _____  _   _  _____   ___   _____     _       ___      _____  _      _____  _____  ___ \n");
  printf("     |  ___|| \\ | ||  ___|  _  || \\ | |/  ___| / _ \\ | ___ \\   | |     / _ \\    |  ___|| |    |  _  ||_   _|/ _ \\ \n");
  printf("     | |__  |  \\| || |_  | | | ||  \\| |\\ `--. / /_\\ \\| |_/ /   | |    / /_\\ \\   | |_   | |    | | | |  | | / /_\\ \\ \n");
  printf("     |  __| | . ` ||  _| | | | || . ` | `--. \\|  _  ||    /    | |    |  _  |   |  _|  | |    | | | |  | | |  _  | \n");
  printf("     | |___ | |\\  || |   \\ \\_/ /| |\\  |/\\__/ /| | | || |\\ \\    | |____| | | |   | |    | |____\\ \\_/ /  | | | | | | \n");
  printf("     \\____/ \\_| \\_/\\_|    \\___/ \\_| \\_/\\____/ \\_| |_/\\_| \\_|   \\_____/\\_| |_/   \\_|    \\_____/ \\___/   \\_/ \\_| |_/ \n\n");
  printf("                                                         |__ \n");
  printf("                                                         |\\/ \n");
  printf("                                                         --- \n");
  printf("                                                         / | [ \n");
  printf("                                                  !      | ||| \n");
  printf("                                                _/|     _/|-++' \n");
  printf("                                            +  +--|    |--|--|_ |- \n");
  printf("                                          /|__|  |/\\__|  |--- |||__/ \n");
  printf("                                        +---------------___[}-_===_.'____ \n");
  printf("                                    ____`-' ||___- ]_| -[ -  |     |_[___\\==--            \\/   _ \n");
  printf("                     __..._____--==/___]_|__|_____________________________[___\\==--____,------' .7 \n");
  printf("                    |                                                                           / \n");
  printf("                     \\_________________________________________________________________________| \n\n\n\n");
  printf("    Autor: Christian Callau Romero\n    Versi\242: 2.0\n\n");
  printf("    Prem intro per continuar . . .");
  getchar();
  system("cls");
}

void copiar_cadena(char *c, char *s)
{
  while (*s)
    *c++ = *s++;
  *c = '\0';
}

int menu_principal(bool joc)
{
  int i, j;

  j = joc ? 0 : 1;

  system("cls");
  printf("\n\n");
  printf("  1. Crear un nou joc\n");
  printf("  2. Carrega un joc emmagatzemat\n");
  if (joc)
  {
    printf("  3. Jugar partida\n");
    printf("  4. Emmagatzemar el joc\n");
  }
  printf("  5. Veure p\225dium\n");
  printf("  6. Sortir del joc\n");
  printf("\n  Selecciona una opci\242: ");

  while (scanf("%d", &i) != 1 || i < 1 || i > 6 || i == 3*j || i == 4*j)
  {
    while (getchar()!='\n');
    system("cls");
    printf("\n\n");
    printf("  1. Crear un nou joc\n");
    printf("  2. Carrega un joc emmagatzemat\n");
    if (joc)
    {
      printf("  3. Jugar partida\n");
      printf("  4. Emmagatzemar el joc\n");
    }
    printf("  5. Veure p\225dium\n");
    printf("  6. Sortir del joc\n");
    printf("\n  Error! Selecciona una opci\242 correcta: ");
  }

  while (getchar()!='\n');
  system("cls");

  return i;
}

void crea_joc(int *dim, int *num_jugadors, jugador_tipus jugadors[])
{
  int opcio;

  system("cls");
  printf("\n\n  Tria la mida del taulell (minim: %d, maxim: %d)\n", DIM_MIN, DIM_MAX);
  printf("\n  Mida: ");

  while (scanf("%d", dim) != 1 || *dim < DIM_MIN || *dim > DIM_MAX)
  {
    while (getchar()!='\n');
    system("cls");
    printf("\n\n  Tria la mida del taulell (minim: %d, maxim: %d)\n", DIM_MIN, DIM_MAX);
    printf("\n  Error! Selecciona una mida correcta: ");
  }

  while (getchar()!='\n');

  system("cls");
  printf("\n\n");
  printf("  1. Cap jugador\n");
  printf("  2. Un jugador\n");
  printf("  3. Dos jugadors\n");
  printf("\n  Selecciona una opci\242: ");

  while (scanf("%d", num_jugadors) != 1 || *num_jugadors < 1 || *num_jugadors > 3)
  {
    while (getchar()!='\n');
    system("cls");
    printf("\n\n");
    printf("  1. Cap jugador\n");
    printf("  2. Un jugador\n");
    printf("  3. Dos jugadors\n");
    printf("\n  Error! Selecciona una opci\242 correcta: ");
  }

  (*num_jugadors)--;

  while (getchar()!='\n');

  if (*num_jugadors == 2)
  {
    system("cls");
    printf("\n\n  De quina manera vols posicionar els vaixells?\n\n");
    printf("  1. Autom\205tica\n");
    printf("  2. Manual\n");
    printf("\n  Selecciona una opci\242: ");

    while (scanf("%d", &opcio) != 1 || opcio < 1 || opcio > 2)
    {
      while (getchar()!='\n');
      system("cls");
      printf("\n\n  De quina manera vols posicionar els vaixells?\n\n");
      printf("  1. Autom\205tica\n");
      printf("  2. Manual\n");
      printf("\n  Error! Selecciona una opci\242 correcta: ");
    }

    while (getchar()!='\n');
  }

  inicia_taulell(*dim, jugadors[0].vaixells);
  inicia_taulell_llancaments (*dim, jugadors[0].llancaments);
  jugadors[0].vaixells_enfonsats = 0;
  jugadors[0].sum_resultats = 0;
  jugadors[0].num_trets = 0;
  jugadors[0].resultat = 0;

  jugadors[0].coor.nombre = -1;

  if (*num_jugadors == 0 || *num_jugadors == 2)
    copiar_cadena(jugadors[0].nom, "maquina");
  if (*num_jugadors == 1)
    copiar_cadena(jugadors[0].nom, "jugador");

  if (*num_jugadors == 2)
  {
    if (opcio == 1)
      inicia_taulell(*dim, jugadors[1].vaixells);
    if (opcio == 2)
      inicia_elmeu_taulell(*dim, jugadors[1].vaixells);

    inicia_taulell_llancaments (*dim, jugadors[1].llancaments);
    jugadors[1].vaixells_enfonsats = 0;
    jugadors[1].sum_resultats = 0;
    jugadors[1].num_trets = 0;
    jugadors[1].resultat = 0;

    jugadors[1].coor.nombre = -1;

    copiar_cadena(jugadors[1].nom, "jugador");
  }
}

void imprimir_taules(int dim, char taula_1[][DIM_MAX], char taula_2[][DIM_MAX])
{
  int f, c;
  char lletra[] = "ABCDEFGHIJ";

  printf("\n\n  Taulell de vaixells \tTaulell de llan\207aments\n\n");
  printf("     ");

  for (c=0; c<dim; c++)
    printf("%c ", lletra[c]);

  printf(" \t   ");

  for (c=0; c<dim; c++)
    printf("%c ", lletra[c]);

  for (f=0; f<dim; f++)
  {
    printf("\n  %2d ", f+1);

    for (c=0; c<dim; c++)
      printf("%c ", taula_1[c][f]);

    printf(" \t");
    printf("%2d ", f+1);

    for (c=0; c<dim; c++)
      printf("%c ", taula_2[c][f]);
  }

  printf("\n");
}

void imprimir_taula(int dim, char taula[][DIM_MAX])
{
  int f, c;
  char lletra[] = "ABCDEFGHIJ";

  printf("\n     ");

  for (c=0; c<dim; c++)
    printf("%c ", lletra[c]);

  for (f=0; f<dim; f++)
  {
    printf("\n  %2d ", f+1);

    for (c=0; c<dim; c++)
      printf("%c ", taula[c][f]);
  }

  printf("\n");
}

void inicia_taulell_llancaments(int dim, char taulell_llancaments[][DIM_MAX])
{
  int i, j;

  for (i = 0; i < dim; i++)
    for (j = 0; j < dim; j++)
      taulell_llancaments[i][j] = CASELLA_BUIDA;
}

void nova_jugada(int dim, coor_tipus *coor)
{
  while (scanf("%c%d", &coor->lletra, &coor->nombre) != 2 || coor->nombre < 1 || coor->nombre > dim || coor->lletra < 64 || coor->lletra > dim+64)
  {
    printf("  Coordenades no v\205lides! Torna a intentar-ho: ");
    while (getchar()!='\n');
  }
}

void nova_orientacio(int *orientacio)
{
  while (scanf("%d", orientacio) != 1 || *orientacio < 0 || *orientacio > 1 )
  {
    printf("  Orientaci\242 no v\205lida! Torna a intentar-ho: ");
    while (getchar()!='\n');
  }
}

void descobrir_voltants(int x1, int y1, int dim, char taula[][DIM_MAX])
{
  int x2, y2, i, j;

  x2 = x1;
  y2 = y1;

  while (taula[x1-1][y1] == CASELLA_VAIXELL && x1 - 1 >= 0)
    x1--;
  while (taula[x1][y1-1] == CASELLA_VAIXELL && y1 - 1 >= 0)
    y1--;

  if (x1 - 1 >= 0)
    x1--;
  if (y1 - 1 >= 0)
    y1--;

  while (taula[x2+1][y2] == CASELLA_VAIXELL && x2 + 1 < dim)
    x2++;
  while (taula[x2][y2+1] == CASELLA_VAIXELL && y2 + 1 < dim)
    y2++;

  if (x2 + 1 < dim)
    x2++;
  if (y2 + 1 < dim)
    y2++;

  for (i = x1; i <= x2; i++)
    for (j = y1; j <= y2; j++)
      if (taula[i][j] == CASELLA_BUIDA)
        taula[i][j] = CASELLA_AIGUA;
}

void actualitza(char f, int c, int res, int dim, char taula[][DIM_MAX])
{
  int x, y;

  x = f - 65;
  y = c - 1;

  switch (res)
  {
    case 1:
      taula[x][y] = CASELLA_AIGUA;
      break;
    case 2:
      taula[x][y] = CASELLA_VAIXELL;
      break;
    case 3:
      taula[x][y] = CASELLA_VAIXELL;
      descobrir_voltants(x, y, dim, taula);
      break;
  }
}

int dispara(char f, int c, char t[][DIM_MAX])
{
  int i, x, y;

  x = f - 65;
  y = c - 1;

  if (t[x][y] == CASELLA_AIGUA_TOCADA || t[x][y] == CASELLA_VAIXELL_TOCAT)
    i = 0;
  else if (t[x][y] == CASELLA_AIGUA)
  {
    t[x][y] = CASELLA_AIGUA_TOCADA;
    i = 1;
  }
  else if (t[x][y] == CASELLA_VAIXELL)
  {
    t[x][y] = CASELLA_VAIXELL_TOCAT;

    i = 3;
    
    /* es posiciona a la casella mes al nord-oest del vaixell */

    while ((t[x-1][y] == CASELLA_VAIXELL || t[x-1][y] == CASELLA_VAIXELL_TOCAT) && x-1 >= 0)
      x--;
    while ((t[x][y-1] == CASELLA_VAIXELL || t[x][y-1] == CASELLA_VAIXELL_TOCAT) && y-1 >= 0)
      y--;
    
    /* segons si el vaixell esta en vertical o horitzontal abança casella per casella, si detecta una casella
    CASELLA_VAIXELL vol dir que el vaixell encara esta per enfonsar per tant retorna 2 */

    while (t[x+1][y] == CASELLA_VAIXELL || t[x+1][y] == CASELLA_VAIXELL_TOCAT)
    {
      if (t[x][y] == CASELLA_VAIXELL)
        i = 2;
      x++;
    }

    if (t[x][y] == CASELLA_VAIXELL)
      i = 2;

    while (t[x][y+1] == CASELLA_VAIXELL || t[x][y+1] == CASELLA_VAIXELL_TOCAT)
    {
      if (t[x][y] == CASELLA_VAIXELL)
        i = 2;
      y++;
    }

    if (t[x][y] == CASELLA_VAIXELL)
      i = 2;
  }
  else
    i = -1;

  return i;
}

void inicia_taulell(int dim, char taula[][DIM_MAX])
{
  int x, y , i , j, cont;
  bool fin = false,  hi_ha_lloc;

  while (!fin && dim >= 8 && dim <= DIM_MAX)
  {
    /* inicia el taulell */
    
    for (i = 0; i < dim; i++)
      for (j = 0; j < dim; j++)
        taula[i][j] = CASELLA_AIGUA;

    cont = 0;
    
    /* tria dues coordenades aleatories i intenta posar el vaixell de quatre caselles, tambe canvia les
    caselles que envolten el vaixell per aigua tocada, serà util mes endavant */

    while (cont < 1)
    {
      x = rand() % dim;
      y = rand() % dim;

      if (rand() % 2 == HORITZONTAL && taula[x][y] == CASELLA_AIGUA && taula[x+1][y] == CASELLA_AIGUA && taula[x+2][y] == CASELLA_AIGUA && taula[x+3][y] == CASELLA_AIGUA && x+3 < dim)
      {
        for (i = x - 1; i <= x + 4; i++)
          for (j = y - 1; j <= y + 1; j++)
            if (i >= 0 && i < dim && j >= 0 && j < dim)
              taula[i][j] = CASELLA_AIGUA_TOCADA;

        for (i = 0; i <= 3; i++)
          taula[x+i][y] = CASELLA_VAIXELL;

        cont++;
      }
      else if (taula[x][y] == CASELLA_AIGUA && taula[x][y+1] == CASELLA_AIGUA && taula[x][y+2] == CASELLA_AIGUA && taula[x][y+3] == CASELLA_AIGUA && y+3 < dim)
      {
        for (i = x - 1; i <= x + 1; i++)
          for (j = y - 1; j <= y + 4; j++)
            if (i >= 0 && i < dim && j >= 0 && j < dim)
              taula[i][j] = CASELLA_AIGUA_TOCADA;

        for (i = 0; i <= 3; i++)
          taula[x][y+i] = CASELLA_VAIXELL;

        cont++;
      }
    }

    cont = 0;
    
    /* el mateix que abans, en aquest cas el loop es repeteix dues vegades, tan sols fica el vaixell
    si totes les caselles son CASELLA_AIGUA, per tant no es tocara amb els altres vaixells ja que estan
    envoltats de CASELLA_AIGUA_TOCADA */

    while (cont < 2)
    {
      x = rand() % dim;
      y = rand() % dim;

      if (rand() % 2 == HORITZONTAL && taula[x][y] == CASELLA_AIGUA && taula[x+1][y] == CASELLA_AIGUA && taula[x+2][y] == CASELLA_AIGUA && x+2 < dim)
      {
        for (i = x - 1; i <= x + 3; i++)
          for (j = y - 1; j <= y + 1; j++)
            if (i >= 0 && i < dim && j >= 0 && j < dim)
              taula[i][j] = CASELLA_AIGUA_TOCADA;

        for (i = 0; i <= 2; i++)
          taula[x+i][y] = CASELLA_VAIXELL;

        cont++;
      }
      else if (taula[x][y] == CASELLA_AIGUA && taula[x][y+1] == CASELLA_AIGUA && taula[x][y+2] == CASELLA_AIGUA && y+2 < dim)
      {
        for (i = x - 1; i <= x + 1; i++)
          for (j = y - 1; j <= y + 3; j++)
            if (i >= 0 && i < dim && j >= 0 && j < dim)
              taula[i][j] = CASELLA_AIGUA_TOCADA;

        for (i = 0; i <= 2; i++)
          taula[x][y+i] = CASELLA_VAIXELL;

        cont++;
      }
    }

    cont = 0;
    
    /* en aquest cas comproba que hi hagi lloc, en cas contrari modifica la variable cont per a sortir
    del loop i tornar a començar */

    while (cont < 3)
    {
      hi_ha_lloc = false;

      for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
          if (taula[i][j] == CASELLA_AIGUA)
            hi_ha_lloc = true;

      if (!hi_ha_lloc)
        cont = 5;

      x = rand() % dim;
      y = rand() % dim;

      if (rand() % 2 == HORITZONTAL && taula[x][y] == CASELLA_AIGUA && taula[x+1][y] == CASELLA_AIGUA && x+1 < dim)
      {
        for (i = x - 1; i <= x + 2; i++)
          for (j = y - 1; j <= y + 1; j++)
            if (i >= 0 && i < dim && j >= 0 && j < dim)
              taula[i][j] = CASELLA_AIGUA_TOCADA;

        for (i = 0; i <= 1; i++)
          taula[x+i][y] = CASELLA_VAIXELL;

        cont++;
      }
      else if (taula[x][y] == CASELLA_AIGUA && taula[x][y+1] == CASELLA_AIGUA && y+1 < dim)
      {
        for (i = x - 1; i <= x + 1; i++)
          for (j = y - 1; j <= y + 2; j++)
            if (i >= 0 && i < dim && j >= 0 && j < dim)
              taula[i][j] = CASELLA_AIGUA_TOCADA;

        for (i = 0; i <= 1; i++)
          taula[x][y+i] = CASELLA_VAIXELL;

        cont++;
      }
    }

    cont = 0;

    while (cont < 4)
    {
      hi_ha_lloc = false;

      for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
          if (taula[i][j] == CASELLA_AIGUA)
            hi_ha_lloc = true;

      if (!hi_ha_lloc)
        cont = 5;

      x = rand() % dim;
      y = rand() % dim;

      if (taula[x][y] == CASELLA_AIGUA)
      {
        for (i = x - 1; i <= x + 1; i++)
          for (j = y - 1; j <= y + 1; j++)
            if (i >= 0 && i < dim && j >= 0 && j < dim)
              taula[i][j] = CASELLA_AIGUA_TOCADA;

        taula[x][y] = CASELLA_VAIXELL;

        cont++;
      }
    }
    
    /* si hem arribat aqui i cont = 4 vol dir que s'han ficat tots els vaixells
    per tant final = cert */

    if (cont == 4)
      fin = true;
    
    /* canvia les caselles d'aigua tocada per aigua */

    for (i = 0; i < dim; i++)
      for (j = 0; j < dim; j++)
        if (taula[i][j] == CASELLA_AIGUA_TOCADA)
          taula[i][j] = CASELLA_AIGUA;
  }
}

void imp_resultat(int res)
{
  switch(res)
  {
    case ERROR:
      printf("Error");
      break;
    case REPETIT:
      printf("Repetit");
      break;
    case AIGUA:
      printf("Aigua");
      break;
    case TOCAT:
      printf("Tocat");
      break;
    case ENFONSAT:
      printf("Tocat i enfonsat");
      break;
    default:
      break;
  }
}

bool continuar(void)
{
  int i;

  printf("\n  Continuar? (0/1): ");

  while (scanf("%d", &i) != 1 || (i != 0 && i != 1))
  {
    printf("  Error! Continuar? (0/1): ");
    while (getchar()!='\n');
  }

  return i;
}

bool jugar_partida(int dim, int num_jugadors, jugador_tipus jugadors[], int *num_records, record_tipus records[])
{
  int pts;
  bool retorn;

  retorn = true;

  system("cls");
  imprimir_taules (dim, jugadors[0].vaixells, jugadors[0].llancaments);
  printf("\n  Jugades: %d\n", jugadors[0].num_trets);
  printf("\n  0 = NO, 1 = SI");

  while (jugadors[0].vaixells_enfonsats < 10 && continuar())
  {
    while (getchar()!='\n');

    if (num_jugadors == 0)
      jugar(&jugadors[0].coor.lletra, &jugadors[0].coor.nombre, dim, jugadors[0].llancaments);
    if (num_jugadors == 1)
    {
      printf("  Fila [A-%c] Columna [1-%d]: ", dim+64, dim);
      nova_jugada(dim, &jugadors[0].coor);
      while (getchar()!='\n');
    }

    jugadors[0].resultat = dispara(jugadors[0].coor.lletra, jugadors[0].coor.nombre, jugadors[0].vaixells);
    actualitza (jugadors[0].coor.lletra, jugadors[0].coor.nombre, jugadors[0].resultat, dim, jugadors[0].llancaments);

    jugadors[0].sum_resultats += jugadors[0].resultat - 1;

    if (jugadors[0].resultat == ENFONSAT)
      jugadors[0].vaixells_enfonsats++;
    jugadors[0].num_trets++;

    system("cls");
    imprimir_taules (dim, jugadors[0].vaixells, jugadors[0].llancaments);
    printf("\n  Coordenades anteriors: %c-%d\n", jugadors[0].coor.lletra, jugadors[0].coor.nombre);
    printf("\n  Resultat: ");
    imp_resultat(jugadors[0].resultat);
    printf("\n  Jugades: %d\n", jugadors[0].num_trets);
  }

  if (jugadors[0].vaixells_enfonsats == 10)
  {
    printf("\n  Partida finalitzada!\n\n  Prem intro per veure la puntuaci\242 . . .");
    getchar();

    remove(FITXER_JOC);
    retorn = false;

    pts = calcular_puntuacio(jugadors[0].num_trets, jugadors[0].sum_resultats, dim);
    system("cls");
    printf("\n  Puntuaci\242: %d\n", pts);

    if (*num_records == MAX_RECORDS && pts > records[*num_records-1].punts)
    {
      records[*num_records-1].punts = pts;
      copiar_cadena(records[*num_records-1].nom, jugadors[0].nom);
    }
    else if (*num_records < MAX_RECORDS)
    {
      records[*num_records].punts = pts;
      copiar_cadena(records[*num_records].nom, jugadors[0].nom);
      (*num_records)++;
    }

    ordena_records (*num_records, records);
    emmagatzema_records(FITXER_RECORDS, num_records, records);
    veure_records (10, *num_records, records);
  }

  return retorn;
}

bool jugar_partida_dos(int dim, jugador_tipus jugadors[], int *num_records, record_tipus records[])
{
  int pts, guanyador;
  bool retorn;

  retorn = true;

  system("cls");
  imprimir_taules (dim, jugadors[1].vaixells, jugadors[1].llancaments);

  if (jugadors[0].coor.nombre >= 1 && jugadors[0].coor.nombre <= dim && jugadors[0].coor.lletra >= 64 && jugadors[0].coor.lletra <= dim+64)
  {
    printf("\n  Coordenades anteriors: %c-%d\n", jugadors[1].coor.lletra, jugadors[1].coor.nombre);
    printf("  Resultat: ");
    imp_resultat(jugadors[1].resultat);
    printf("\n");
  }

  if (jugadors[0].coor.nombre >= 1 && jugadors[0].coor.nombre <= dim && jugadors[0].coor.lletra >= 64 && jugadors[0].coor.lletra <= dim+64)
  {
    printf("\n  La maquina dispara a les coordenades: %c-%d\n", jugadors[0].coor.lletra, jugadors[0].coor.nombre);
    printf("  Resultat: ");
    imp_resultat(jugadors[0].resultat);
    printf("\n");
  }

  printf("\n  0 = NO, 1 = SI");

  while (jugadors[0].vaixells_enfonsats < 10 && jugadors[1].vaixells_enfonsats < 10 && continuar())
  {
    while (getchar()!='\n');

    /* torn jugador */

    if (jugadors[0].resultat != 2 && jugadors[0].resultat != 3)
    {
      printf("  Fila [A-%c] Columna [1-%d]: ", dim+64, dim);
      nova_jugada(dim, &jugadors[1].coor);
      while (getchar()!='\n');

      jugadors[1].resultat = dispara(jugadors[1].coor.lletra, jugadors[1].coor.nombre, jugadors[0].vaixells);
      actualitza (jugadors[1].coor.lletra, jugadors[1].coor.nombre, jugadors[1].resultat, dim, jugadors[1].llancaments);

      jugadors[1].sum_resultats += jugadors[1].resultat - 1;

      if (jugadors[1].resultat == ENFONSAT)
        jugadors[1].vaixells_enfonsats++;

      jugadors[1].num_trets++;

    }

    /* torn maquina */

    if (jugadors[1].resultat != 2 && jugadors[1].resultat != 3)
    {
      jugar(&jugadors[0].coor.lletra, &jugadors[0].coor.nombre, dim, jugadors[0].llancaments);

      jugadors[0].resultat = dispara(jugadors[0].coor.lletra, jugadors[0].coor.nombre, jugadors[1].vaixells);
      actualitza (jugadors[0].coor.lletra, jugadors[0].coor.nombre, jugadors[0].resultat, dim, jugadors[0].llancaments);

      jugadors[0].sum_resultats += jugadors[0].resultat - 1;

      if (jugadors[0].resultat == ENFONSAT)
        jugadors[0].vaixells_enfonsats++;
      jugadors[0].num_trets++;

    }

    /* imprimir resultats */

    system("cls");
    imprimir_taules (dim, jugadors[1].vaixells, jugadors[1].llancaments);

    if (jugadors[0].coor.nombre >= 1 && jugadors[0].coor.nombre <= dim && jugadors[0].coor.lletra >= 64 && jugadors[0].coor.lletra <= dim+64)
    {
      printf("\n  Coordenades anteriors: %c-%d\n", jugadors[1].coor.lletra, jugadors[1].coor.nombre);
      printf("  Resultat: ");
      imp_resultat(jugadors[1].resultat);
      printf("\n");
    }

    if (jugadors[0].coor.nombre >= 1 && jugadors[0].coor.nombre <= dim && jugadors[0].coor.lletra >= 64 && jugadors[0].coor.lletra <= dim+64)
    {
      printf("\n  La maquina dispara a les coordenades: %c-%d\n", jugadors[0].coor.lletra, jugadors[0].coor.nombre);
      printf("  Resultat: ");
      imp_resultat(jugadors[0].resultat);
      printf("\n");
    }
  }

  if (jugadors[0].vaixells_enfonsats == 10 || jugadors[1].vaixells_enfonsats == 10)
  {
    printf("\n  Partida finalitzada!\n\n  Prem intro per veure la puntuaci\242 . . .");
    getchar();

    remove(FITXER_JOC);
    retorn = false;

    if (jugadors[0].vaixells_enfonsats == 10)
      guanyador = 0;
    if (jugadors[1].vaixells_enfonsats == 10)
      guanyador = 1;

    pts = calcular_puntuacio (jugadors[guanyador].num_trets, jugadors[guanyador].sum_resultats, dim);
    system("cls");
    printf("\n  Guanyador: %s", jugadors[guanyador].nom);
    printf("\n  Puntuaci\242: %d\n", pts);

    if (*num_records == MAX_RECORDS && pts > records[*num_records-1].punts)
    {
      records[*num_records-1].punts = pts;
      copiar_cadena(records[*num_records-1].nom, jugadors[guanyador].nom);
    }
    else if (*num_records < MAX_RECORDS)
    {
      records[*num_records].punts = pts;
      copiar_cadena(records[*num_records].nom, jugadors[guanyador].nom);
      (*num_records)++;
    }

    ordena_records (*num_records, records);
    emmagatzema_records(FITXER_RECORDS, num_records, records);
    veure_records (10, *num_records, records);
  }

  return retorn;
}

int calcular_puntuacio (int jugades, int resultats, int dim)
{
  return ( (float)dim / jugades ) * resultats * 100;
}

void veure_records (int num, int num_records, record_tipus records[])
{
  if (num_records > 0)
  {
    int i = 0;

    printf("\n  Jugador\t\tPuntuaci\242\n\n");

    while (i < num && i < num_records)
    {
      printf("  %2d. %s\t\t%d\n", i+1, records[i].nom, records[i].punts);
      i++;
    }
  }
  else
    printf("\n  No hi ha r\212cords per veure.\n");

  printf("\n  Prem intro per tornar al menu principal . . .");
  getchar();
}

void ordena_records (int num_records, record_tipus records[])
{
  int i, j, temp;
  nom_tipus ctemp;

  for (i = 1; i < num_records; i++)
  {
    j = i;

    while (j > 0 && records[j].punts > records[j-1].punts)
    {
      temp = records[j].punts;
      records[j].punts = records[j-1].punts;
      records[j-1].punts = temp;

      copiar_cadena(ctemp, records[j].nom);
      copiar_cadena(records[j].nom, records[j-1].nom);
      copiar_cadena(records[j-1].nom, ctemp);

      j--;
    }
  }
}

/** NIVEL 1 */
/*
accio jugar(var f:caracter, var c:enter, dim:enter, taulell_llancament:taula de
caracters);
*/
void jugar(char *f, int *c, int dim, char taula[][DIM_MAX])
{
  int i = 0, j = 0, port = 1, dest = 2, drag = 3, pmax = 0;
  bool fin = false;
  char prob [DIM_MAX][DIM_MAX];

  /* recorre totes les caselles buscan un vaixell que estigue per enfonsar */

  while (i < dim && !fin)
  {
    j = 0;
    while (j < dim && !fin)
    {
      if (taula[i][j] == CASELLA_VAIXELL && ((i-1 > -1 && taula[i-1][j] == CASELLA_BUIDA) || (j-1 > -1 && taula[i][j-1] == CASELLA_BUIDA) || (i+1 < dim && taula[i+1][j] == CASELLA_BUIDA) || (j+1 < dim && taula[i][j+1] == CASELLA_BUIDA)))
      {
        /* comproba si el vaixell esta en posicio horitzontal, vertical o si no es sap tria un punt cardinal aleatori on disparar */

        if ((i-1 > -1 && taula[i-1][j] == CASELLA_VAIXELL) || (i+1 < dim && taula[i+1][j] == CASELLA_VAIXELL))
        {
          if (i-1 > -1 && taula[i-1][j] == CASELLA_BUIDA)
          {
            *f = i;
            *c = j + 1;
            fin = true;
          }
          else
          {
            while (taula[i][j] == CASELLA_VAIXELL)
              i++;
            *f = i + 1;
            *c = j + 1;
            fin = true;
          }
        }
        else if ((j-1 > -1 && taula[i][j-1] == CASELLA_VAIXELL) || (j+1 < dim && taula[i][j+1] == CASELLA_VAIXELL))
        {
          if (j-1 > -1 && taula[i][j-1] == CASELLA_BUIDA)
          {
            *f = i + 1;
            *c = j;
            fin = true;
          }
          else
          {
            while (taula[i][j] == CASELLA_VAIXELL)
              j++;
            *f = i + 1;
            *c = j + 1;
            fin = true;
          }
        }
        else
        {
          while(!fin)
          {
            switch (rand() % 4)
            {
              case 0:
                if (i-1 > -1 && taula[i-1][j] == CASELLA_BUIDA)
                  {
                    *f = i;
                    *c = j + 1;
                    fin = true;
                  }
                break;
              case 1:
                if (j-1 > -1 && taula[i][j-1] == CASELLA_BUIDA)
                  {
                    *f = i + 1;
                    *c = j;
                    fin = true;
                  }
                break;
              case 2:
                if (i+1 < dim && taula[i+1][j] == CASELLA_BUIDA)
                  {
                    *f = i + 2;
                    *c = j + 1;
                    fin = true;
                  }
                break;
              case 3:
                if (j+1 < dim && taula[i][j+1] == CASELLA_BUIDA)
                  {
                    *f = i + 1;
                    *c = j + 2;
                    fin = true;
                  }
                break;
            }
          }
        }
      }
      j++;
    }
    i++;
  }

  /* si no hi ha cap vaixell penden d'enfonsar */

  if (!fin)
  {
    /* inicia la taula de probablititats a 0 */

    for (i = 0; i < dim; i++)
      for (j = 0; j < dim; j++)
        prob[i][j] = 0;

    /* identifica quins vaixells estan enfonsats i quins queden per enfonsar */

    for (i = 0; i < dim; i++)
    {
      for (j = 0; j < dim; j++)
      {
        if (taula[i][j] == CASELLA_VAIXELL)
        {
          if (i+1 < dim && taula[i+1][j] == CASELLA_VAIXELL)
          {
            if (i+2 < dim && taula[i+2][j] == CASELLA_VAIXELL)
            {
              if (i+3 < dim && taula[i+3][j] == CASELLA_VAIXELL)
                port--;
              else if (i-1 < 0 || (i-1 > -1 && taula[i-1][j] != CASELLA_VAIXELL))
                dest--;
            }
            else if (i-1 < 0 || (i-1 > -1 && taula[i-1][j] != CASELLA_VAIXELL))
              drag--;
          }
          else if (j+1 < dim && taula[i][j+1] == CASELLA_VAIXELL)
          {
            if (j+2 < dim && taula[i][j+2] == CASELLA_VAIXELL)
            {
              if (j+3 < dim && taula[i][j+3] == CASELLA_VAIXELL)
                port--;
              else if (j-1 < 0 || (j-1 > -1 && taula[i][j-1] != CASELLA_VAIXELL))
                dest--;
            }
            else if (j-1 < 0 || (j-1 > -1 && taula[i][j-1] != CASELLA_VAIXELL))
              drag--;
          }
        }
      }
    }

    /* calcula les probablitiats de cada casella segons els vaixells que quedin per enfonsar */

    for (i = 0; i < dim; i++)
    {
      for (j = 0; j < dim; j++)
      {
        if (port > 0)
        {
          if ((taula[i][j] == CASELLA_BUIDA) && (taula[i+1][j] == CASELLA_BUIDA && i+1 < dim) && (taula[i+2][j] == CASELLA_BUIDA && i+2 < dim) && (taula[i+3][j] == CASELLA_BUIDA && i+3 < dim))
          {
            prob[i][j]++;
            prob[i+1][j]++;
            prob[i+2][j]++;
            prob[i+3][j]++;
          }

          if ((taula[i][j] == CASELLA_BUIDA) && (taula[i][j+1] == CASELLA_BUIDA && j+1 < dim) && (taula[i][j+2] == CASELLA_BUIDA && j+2 < dim) && (taula[i][j+3] == CASELLA_BUIDA && j+3 < dim))
          {
            prob[i][j]++;
            prob[i][j+1]++;
            prob[i][j+2]++;
            prob[i][j+3]++;
          }
        }

        if (dest > 0)
        {
          if ((taula[i][j] == CASELLA_BUIDA) && (taula[i+1][j] == CASELLA_BUIDA && i+1 < dim) && (taula[i+2][j] == CASELLA_BUIDA && i+2 < dim))
          {
            prob[i][j]++;
            prob[i+1][j]++;
            prob[i+2][j]++;
          }

          if ((taula[i][j] == CASELLA_BUIDA) && (taula[i][j+1] == CASELLA_BUIDA && j+1 < dim) && (taula[i][j+2] == CASELLA_BUIDA && j+2 < dim))
          {
            prob[i][j]++;
            prob[i][j+1]++;
            prob[i][j+2]++;
          }
        }

        if (drag > 0)
        {
          if ((taula[i][j] == CASELLA_BUIDA) && (taula[i+1][j] == CASELLA_BUIDA && i+1 < dim))
          {
            prob[i][j]++;
            prob[i+1][j]++;
          }

          if ((taula[i][j] == CASELLA_BUIDA) && (taula[i][j+1] == CASELLA_BUIDA && j+1 < dim))
          {
            prob[i][j]++;
            prob[i][j+1]++;
          }
        }
      }
    }

    /* busca la probablitiat mes alta i la guarda a la variable pmax */

    for (i = 0; i < dim; i++)
      for (j = 0; j < dim; j++)
        if (prob[i][j] > pmax)
          pmax = prob[i][j];

    /* tria una coordenada aleatoria entre les caselles que tingin la probabilitat mes alta */

    while (*f < 1 || *c < 1 || *f > dim || *c > dim || taula[*f-1][*c-1] != CASELLA_BUIDA || prob[*f-1][*c-1] != pmax)
    {
      *c = rand() % dim + 1;
      *f = rand() % dim + 1;
    }
  }

  *f = *f + 64;
}

/*
funcio emmagatzema_records(fitxer_record:taula de caracters, var
num_records:enter, records:taula de record_tipus) retorna boolea.
*/
bool emmagatzema_records(char fitxer_record[], int *num_records, record_tipus records[])
{
  FILE *f = fopen(fitxer_record, "w");
  bool retorn;
  int i;

  if (f == NULL)
    retorn = false;
  else
  {
    for (i = 0; i < *num_records; i++)
      fprintf(f, "%s\t%d\n", records[i].nom, records[i].punts);

    fclose(f);
    retorn = true;
  }

  return retorn;
}

/*
funcio recupera_records(fitxer_record:taula de caracters, var num_records:enter,
records:taula de record_tipus) retorna boolea.
*/
bool recupera_records(char fitxer_record[], int *num_records, record_tipus records[])
{
  FILE *f = fopen(fitxer_record, "r");
  bool retorn;

  *num_records = 0;

  if (f == NULL)
    retorn = false;
  else
  {
    while (!feof(f) && *num_records < MAX_RECORDS)
      if (fscanf(f, "%s\t%d\n", records[*num_records].nom, &records[*num_records].punts) == 2)
        (*num_records)++;

    fclose(f);
    retorn = true;
  }

  return retorn;
}

/** NIVEL 2 */
/*
funcio emmagatzema_joc(nom_fitxer:taula de caracters, dim, num_jugadors: enter,
             jugadors:taula de jugador_tipus) retorna boolea;
*/
bool emmagatzema_joc(char fitxer_record[], int dim, int num_jugadors, jugador_tipus jugadors[])
{
  FILE* f = fopen(fitxer_record, "wb");
  bool retorn;

  if (f == NULL)
    retorn = false;
  else
  {
    fwrite (&dim, sizeof(int), 1, f);
    fwrite (&num_jugadors, sizeof(int), 1, f);

    if (num_jugadors == 0 || num_jugadors == 1)
      fwrite (jugadors, sizeof(jugador_tipus), 1, f);
    if (num_jugadors == 2)
      fwrite (jugadors, sizeof(jugador_tipus), 2, f);

    fclose(f);
    retorn = true;
  }

  return retorn;
}

/*
funcio recupera_joc(nom_fitxer:taula de caràcters, var dim, var num_jugadors: enter,
             var jugadors:taula de jugador_tipus) retorna boolea;
*/
bool recupera_joc(char fitxer_record[], int *dim, int *num_jugadors, jugador_tipus jugadors[]) {

  FILE *f = fopen(fitxer_record, "rb");
  bool retorn;

  if (f == NULL) {
    retorn = false;
  } else {
    fread(dim, sizeof(int), 1 , f);
    fread(num_jugadors, sizeof(int), 1 , f);

    if (*num_jugadors == 0 || *num_jugadors == 1) {
      fread(jugadors, sizeof(jugador_tipus), 1, f);
    }
    if (*num_jugadors == 2) {
      fread(jugadors, sizeof(jugador_tipus), 2, f);
    }

    fclose(f);
    retorn = true;
  }

  return retorn;
}

/** NIVEL 3 */
/*
accio inicia_elmeu_taulell(dim:enter, taulell_vaixells:taula de caracters) ;
*/
void inicia_elmeu_taulell(int dim, char taulell_vaixells[][DIM_MAX]) {

  int i, j, x, y, orientacio, cont, cambi;
  bool fin = false, hi_ha_lloc = true;
  coor_tipus coor;
  
  /* el mateix que inicia_taulell pero preguntan les coordenades i l'orientacio en comptes de
  generar-ho aleatoriament */

  while (!fin && dim >= 8 && dim <= DIM_MAX)
  {
    for (i = 0; i < dim; i++) {
      for (j = 0; j < dim; j++) {
        taulell_vaixells[i][j] = CASELLA_AIGUA;
      }
    }

    cont = 0;

    system("cls");
    imprimir_taula(dim, taulell_vaixells);
    printf("\n  Vaixell: Portaavions (4 caselles)\n");
    printf("\n  Coordenades, Fila [A-%c] Columna [1-%d]: ", dim+64, dim);
    nova_jugada(dim, &coor);
    while (getchar()!='\n');
    printf("  Orientaci\242, Horitzontal [%d] Vertical [%d]: ", HORITZONTAL, VERTICAL);
    nova_orientacio(&orientacio);
    while (getchar()!='\n');

    x = coor.lletra - 65;
    y = coor.nombre - 1;

    while (cont < 1)
    {
      if (orientacio == HORITZONTAL && taulell_vaixells[x][y] == CASELLA_AIGUA && taulell_vaixells[x+1][y] == CASELLA_AIGUA && taulell_vaixells[x+2][y] == CASELLA_AIGUA && taulell_vaixells[x+3][y] == CASELLA_AIGUA && x+3 < dim)
      {
        for (i = x - 1; i <= x + 4; i++)
          for (j = y - 1; j <= y + 1; j++)
            if (i >= 0 && i < dim && j >= 0 && j < dim)
              taulell_vaixells[i][j] = CASELLA_AIGUA_TOCADA;

        for (i = 0; i <= 3; i++)
          taulell_vaixells[x+i][y] = CASELLA_VAIXELL;

        cont++;
      }
      else if (taulell_vaixells[x][y] == CASELLA_AIGUA && taulell_vaixells[x][y+1] == CASELLA_AIGUA && taulell_vaixells[x][y+2] == CASELLA_AIGUA && taulell_vaixells[x][y+3] == CASELLA_AIGUA && y+3 < dim)
      {
        for (i = x - 1; i <= x + 1; i++)
          for (j = y - 1; j <= y + 4; j++)
            if (i >= 0 && i < dim && j >= 0 && j < dim)
              taulell_vaixells[i][j] = CASELLA_AIGUA_TOCADA;

        for (i = 0; i <= 3; i++)
          taulell_vaixells[x][y+i] = CASELLA_VAIXELL;

        cont++;
      }
      else
      {
        system("cls");
        imprimir_taula(dim, taulell_vaixells);
        printf("\n  Posici\242 no v\205lida!\n");
        printf("\n  Coordenades Fila [A-%c] Columna [1-%d]: ", dim+64, dim);
        nova_jugada(dim, &coor);
        while (getchar()!='\n');
        printf("  Orientaci\242 (%d = Horitzontal, %d = Vertical): ", HORITZONTAL, VERTICAL);
        nova_orientacio(&orientacio);
        while (getchar()!='\n');

        x = coor.lletra - 65;
        y = coor.nombre - 1;
      }
    }

    cambi = cont;
    cont = 0;

    while (cont < 2)
    {
      if (cambi != cont)
      {
        cambi = cont;

        system("cls");
        imprimir_taula(dim, taulell_vaixells);
        printf("\n  Vaixell: Destructor (3 caselles)\n");
        printf("\n  Coordenades, Fila [A-%c] Columna [1-%d]: ", dim+64, dim);
        nova_jugada(dim, &coor);
        while (getchar()!='\n');
        printf("  Orientaci\242, Horitzontal [%d] Vertical [%d]: ", HORITZONTAL, VERTICAL);
        nova_orientacio(&orientacio);
        while (getchar()!='\n');

        x = coor.lletra - 65;
        y = coor.nombre - 1;
      }

      if (orientacio == HORITZONTAL && taulell_vaixells[x][y] == CASELLA_AIGUA && taulell_vaixells[x+1][y] == CASELLA_AIGUA && taulell_vaixells[x+2][y] == CASELLA_AIGUA && x+2 < dim)
      {
        for (i = x - 1; i <= x + 3; i++)
          for (j = y - 1; j <= y + 1; j++)
            if (i >= 0 && i < dim && j >= 0 && j < dim)
              taulell_vaixells[i][j] = CASELLA_AIGUA_TOCADA;

        for (i = 0; i <= 2; i++)
          taulell_vaixells[x+i][y] = CASELLA_VAIXELL;

        cont++;
      }
      else if (taulell_vaixells[x][y] == CASELLA_AIGUA && taulell_vaixells[x][y+1] == CASELLA_AIGUA && taulell_vaixells[x][y+2] == CASELLA_AIGUA && y+2 < dim)
      {
        for (i = x - 1; i <= x + 1; i++)
          for (j = y - 1; j <= y + 3; j++)
            if (i >= 0 && i < dim && j >= 0 && j < dim)
              taulell_vaixells[i][j] = CASELLA_AIGUA_TOCADA;

        for (i = 0; i <= 2; i++)
          taulell_vaixells[x][y+i] = CASELLA_VAIXELL;

        cont++;
      }
      else
      {
        system("cls");
        imprimir_taula(dim, taulell_vaixells);
        printf("\n  Posici\242 no v\205lida!\n");
        printf("\n  Coordenades, Fila [A-%c] Columna [1-%d]: ", dim+64, dim);
        nova_jugada(dim, &coor);
        while (getchar()!='\n');
        printf("  Orientaci\242, Horitzontal [%d] Vertical [%d]: ", HORITZONTAL, VERTICAL);
        nova_orientacio(&orientacio);
        while (getchar()!='\n');

        x = coor.lletra - 65;
        y = coor.nombre - 1;
      }
    }

    cambi = cont;
    cont = 0;

    while (cont < 3 && hi_ha_lloc)
    {
      if (cambi != cont)
      {
        cambi = cont;

        system("cls");
        imprimir_taula(dim, taulell_vaixells);
        printf("\n  Vaixell: Dragamines (2 caselles)\n");
        printf("\n  Coordenades, Fila [A-%c] Columna [1-%d]: ", dim+64, dim);
        nova_jugada(dim, &coor);
        while (getchar()!='\n');
        printf("  Orientaci\242, Horitzontal [%d] Vertical [%d]: ", HORITZONTAL, VERTICAL);
        nova_orientacio(&orientacio);
        while (getchar()!='\n');

        x = coor.lletra - 65;
        y = coor.nombre - 1;
      }

      if (orientacio == HORITZONTAL && taulell_vaixells[x][y] == CASELLA_AIGUA && taulell_vaixells[x+1][y] == CASELLA_AIGUA && x+1 < dim)
      {
        for (i = x - 1; i <= x + 2; i++)
          for (j = y - 1; j <= y + 1; j++)
            if (i >= 0 && i < dim && j >= 0 && j < dim)
              taulell_vaixells[i][j] = CASELLA_AIGUA_TOCADA;

        for (i = 0; i <= 1; i++)
          taulell_vaixells[x+i][y] = CASELLA_VAIXELL;

        cont++;
      }
      else if (taulell_vaixells[x][y] == CASELLA_AIGUA && taulell_vaixells[x][y+1] == CASELLA_AIGUA && y+1 < dim)
      {
        for (i = x - 1; i <= x + 1; i++)
          for (j = y - 1; j <= y + 2; j++)
            if (i >= 0 && i < dim && j >= 0 && j < dim)
              taulell_vaixells[i][j] = CASELLA_AIGUA_TOCADA;

        for (i = 0; i <= 1; i++)
          taulell_vaixells[x][y+i] = CASELLA_VAIXELL;

        cont++;
      }
      else
      {
        system("cls");
        imprimir_taula(dim, taulell_vaixells);
        printf("\n  Posici\242 no v\205lida!\n");
        printf("\n  Coordenades, Fila [A-%c] Columna [1-%d]: ", dim+64, dim);
        nova_jugada(dim, &coor);
        while (getchar()!='\n');
        printf("  Orientaci\242, Horitzontal [%d] Vertical [%d]: ", HORITZONTAL, VERTICAL);
        nova_orientacio(&orientacio);
        while (getchar()!='\n');

        x = coor.lletra - 65;
        y = coor.nombre - 1;
      }

      hi_ha_lloc = false;

      for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
          if (taulell_vaixells[i][j] == CASELLA_AIGUA)
            hi_ha_lloc = true;
    }

    cambi = cont;
    cont = 0;

    while (cont < 4 && hi_ha_lloc)
    {
      if (cambi != cont)
      {
        cambi = cont;

        system("cls");
        imprimir_taula(dim, taulell_vaixells);
        printf("\n  Vaixell: Submar\241 (1 casella)\n");
        printf("\n  Coordenades, Fila [A-%c] Columna [1-%d]: ", dim+64, dim);
        nova_jugada(dim, &coor);
        while (getchar()!='\n');

        x = coor.lletra - 65;
        y = coor.nombre - 1;
      }

      if (taulell_vaixells[x][y] == CASELLA_AIGUA)
      {
        for (i = x - 1; i <= x + 1; i++)
          for (j = y - 1; j <= y + 1; j++)
            if (i >= 0 && i < dim && j >= 0 && j < dim)
              taulell_vaixells[i][j] = CASELLA_AIGUA_TOCADA;

        taulell_vaixells[x][y] = CASELLA_VAIXELL;

        cont++;
      }
      else
      {
        system("cls");
        imprimir_taula(dim, taulell_vaixells);
        printf("\n  Posici\242 no v\205lida!\n");
        printf("\n  Coordenades, Fila [A-%c] Columna [1-%d]: ", dim+64, dim);
        nova_jugada(dim, &coor);
        while (getchar()!='\n');

        x = coor.lletra - 65;
        y = coor.nombre - 1;
      }

      hi_ha_lloc = false;

      for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
          if (taulell_vaixells[i][j] == CASELLA_AIGUA)
            hi_ha_lloc = true;
    }

    if (!hi_ha_lloc)
    {
      system("cls");
      imprimir_taula(dim, taulell_vaixells);
      printf("\n  No hi ha lloc!\n\n  Prem intro per tornar a comen\207ar . . .");
      getchar();
    }
    else
    {
      for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++)
          if (taulell_vaixells[i][j] == CASELLA_AIGUA_TOCADA)
            taulell_vaixells[i][j] = CASELLA_AIGUA;

      fin = true;

      system("cls");
      imprimir_taula(dim, taulell_vaixells);
      printf("\n  Taula completa!\n\n  Prem intro per continuar . . .");
      getchar();
    }
  }
}
