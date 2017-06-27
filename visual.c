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
  show_menu(game);
  printf("  Select an option: ");
  while (scanf("%d", &option) != 1 || !valid_option(game, option)) {
    while (getchar() != '\n');
    system("cls");
    show_menu(game);
    printf("  Invalid option, try again: ");
  }
  while (getchar() != '\n');
  if (!game && option > 2) option += 2;
  return option;
}

void show_menu(bool game) {
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
}

bool valid_option(bool game, int option) {
  return option > 0 && ((game && option < 7) || (!game && option < 5));
}

int get_mode() {
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

int get_dim() {
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

int get_ini() {
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
      printf("%c ", table.grid[col][row]);
    }
  }
  printf("\n");
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
      printf("%c ", table1.grid[col][row]);
    }
    printf(" \t");
    printf("%2d ", row+1);
    for (col = 0; col < table2.dim; col++) {
      printf("%c ", table2.grid[col][row]);
    }
  }
  printf("\n");
}

void scoreboard(Scores_t records) {
  system("cls");
  if (records.num > 0) {
    printf("\n  Player\t\tPoints\n\n");
    for (int i = 0; i < records.num; i++) {
      printf("%2d. %s\t\t%d\n", i+1, records.score[i].name, records.score[i].points);
    }
  } else printf("\n  There are no records to show.\n");
  pause();
}

void pause() {
  printf("\n  Press enter to return to the main menu...");
  getchar();
}

void print_shoot(Shoot_e shoot) {
  switch (shoot) {
  case ERROR:
    printf("Error");
    break;
  case REPEATED:
    printf("Repeated");
    break;
  case MISS:
    printf("Water");
    break;
  case HIT:
    printf("Hit");
    break;
  case SUNK:
    printf("Sunk");
    break;
  default:
    break;
  }
}