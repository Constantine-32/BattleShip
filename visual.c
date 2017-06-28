/*----------------------------------------------------------------
|   Author: Christian Callau Romero
|   e-mail: id.32@outlook.com
|   Date: July 2017                 Version: 2.0
|-----------------------------------------------------------------|
|	Project name: BattleShip
|	Name: visual.c
|   File description:   Menus and data display functions.
| ----------------------------------------------------------------*/

#include "types.h"
#include "functions.h"

int main_menu(bool game) {
  int option;
  system("cls");
  printf("\n  BattleShip Game: Main menu\n");
  printf("  1. New game\n");
  printf("  2. Load game\n");
  if (game) {
    printf("  3. Play game\n");
    printf("  4. Save game\n");
    printf("  5. Scoreboard\n");
    printf("  6. Exit\n");
  } else {
    printf("  3. Scoreboard\n");
    printf("  4. Exit\n");
  }
  printf("  Select an option: ");
  while (scanf("%d", &option) != 1 || option < 1 || (game && option > 6) || (!game && option > 4)) {
    while (getchar() != '\n');
    system("cls");
    printf("\n  BattleShip Game: Main menu\n");
    printf("  1. New game\n");
    printf("  2. Load game\n");
    if (game) {
      printf("  3. Play game\n");
      printf("  4. Save game\n");
      printf("  5. Scoreboard\n");
      printf("  6. Exit\n");
    } else {
      printf("  3. Scoreboard\n");
      printf("  4. Exit\n");
    }
    printf("  Invalid option, try again: ");
  }
  while (getchar() != '\n');
  if (!game && option > 2) option += 2;
  return option;
}

int mode_menu() {
  int option;
  system("cls");
  printf("\n  Select the game mode:\n");
  printf("  1. AI solo\n");
  printf("  2. Player solo\n");
  printf("  3. Player vs AI\n");
  printf("  Select an option: ");
  while (scanf("%d", &option) != 1 || option < 1 || option > 3) {
    while (getchar() != '\n');
    system("cls");
    printf("\n  Select the game mode:\n");
    printf("  1. AI solo\n");
    printf("  2. Player solo\n");
    printf("  3. Player vs AI\n");
    printf("  Invalid option, try again: ");
  }
  while (getchar() != '\n');
  return option - 1;
}

int size_menu() {
  int option;
  system("cls");
  printf("\n  Select the table size:\n");
  printf("  1. 8x8\n");
  printf("  2. 9x9\n");
  printf("  3. 10x10\n");
  printf("  Select an option: ");
  while (scanf("%d", &option) != 1 || option < 1 || option > 3) {
    while (getchar() != '\n');
    system("cls");
    printf("\n  Select the table size:\n");
    printf("  1. 8x8\n");
    printf("  2. 9x9\n");
    printf("  3. 10x10\n");
    printf("  Invalid option, try again: ");
  }
  while (getchar() != '\n');
  return option + 7;
}

int init_menu() {
  int option;
  system("cls");
  printf("\n  How do you want to initialize your ships table?:\n");
  printf("  1. Automatic\n");
  printf("  2. Manual\n");
  printf("  Select an option: ");
  while (scanf("%d", &option) != 1 || option < 1 || option > 2) {
    while (getchar() != '\n');
    system("cls");
    printf("\n  How do you want to initialize your ships table?:\n");
    printf("  1. Automatic\n");
    printf("  2. Manual\n");
    printf("  Invalid option, try again: ");
  }
  while (getchar() != '\n');
  return option - 1;
}

void print_table(Table_t table) {
  int row, col;
  char lletra[] = "ABCDEFGHIJ";
  printf("\n     ");
  for (col = 0; col < table.dim; col++) {
    printf("%c ", lletra[col]);
  }
  for (row = 0; row < table.dim; row++) {
    printf("\n  %2d ", row+1);
    for (col = 0; col < table.dim; col++) {
      printf("%c ", table.grid[row][col]);
    }
  }
  printf("\n\n");
}

void print_tables(Table_t table1, Table_t table2) {
  int row, col;
  char abc[] = "ABCDEFGHIJ";
  printf("\n  Ship table\t\t\tShooting table\n\n");
  printf("     ");
  for (col = 0; col < table1.dim; col++) {
    printf("%c ", abc[col]);
  }
  printf(" \t   ");
  for (col = 0; col < table2.dim; col++) {
    printf("%c ", abc[col]);
  }
  for (row = 0; row < table1.dim; row++) {
    printf("\n  %2d ", row+1);
    for (col = 0; col < table1.dim; col++) {
      printf("%c ", table1.grid[row][col]);
    }
    printf(" \t");
    printf("%2d ", row+1);
    for (col = 0; col < table2.dim; col++) {
      printf("%c ", table2.grid[row][col]);
    }
  }
  printf("\n\n");
}

void print_scoreboard(Scores_t scores) {
  system("cls");
  if (scores.num > 0) {
    printf("\n  Player\t\tPoints\n\n");
    for (int i = 0; i < scores.num; i++) {
      printf("%2d. %s\t\t%d\n", i+1, scores.score[i].name, scores.score[i].points);
    }
  } else printf("\n  There are no scores to show.\n");
  pause();
}

void pause() {
  printf("\n  Press enter to return to the main menu...");
  getchar();
}

const char *shot_to_string(Shot_e shot) {
  switch (shot) {
  case ERROR:
    return "Error";
  case REPEATED:
    return "Repeated";
  case MISS:
    return "Water";
  case HIT:
    return "Hit";
  case SUNK:
    return "Sunk";
  default:
    return "Unknown_Case";
  }
}