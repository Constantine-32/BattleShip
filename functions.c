/*----------------------------------------------------------------
|   Author: Christian Callau Romero
|   e-mail: id.32@outlook.com
|   Date: July 2017                 Version: 2.0
|-----------------------------------------------------------------|
|	Project name: BattleShip
|	Name: functions.c
|   File description:   Function implementation.
| ----------------------------------------------------------------*/

#include "types.h"
#include "functions.h"

int main_menu(bool game) {
  int option;
  system("cls");
  show_menu(game);
  printf("Select an option: ");
  while (scanf("%d", &option) != 1 || !valid_option(game, option)) {
    while (getchar() != '\n');
    system("cls");
    show_menu(game);
    printf("Invalid option, try again: ");
  }
  while (getchar() != '\n');
  if (!game && option > 2) option += 2;
  return option;
}

void show_menu(bool game) {
  printf("BattleShip Game: Main menu\n");
  printf("1. New game\n");
  printf("2. Load game\n");
  if (game) {
    printf("3. Play game\n");
    printf("4. Save game\n");
    printf("5. Scoreboard\n");
    printf("6. Exit\n");
  } else {
    printf("3. Scoreboard\n");
    printf("4. Exit\n");
  }
}

bool valid_option(bool game, int option) {
  return option > 0 && ((game && option < 7) || (!game && option < 5));
}

void new_game(int *dim, int *mode, player_t players[]) {
  *dim = 10;
  *mode = 2;
  new_player(*dim, players[0]);
  new_player(*dim, players[1]);
}

void new_player(int dim, player_t player) {
  player.coord.col = '\0';
  player.coord.row = -1;
  new_ships_table(dim, player.ships);
  new_shots_table(dim, player.shots);
  player.sunk_ships = 0;
  player.shot_count = 0;
  player.result_sum = 0;
  player.result = 0;
}

void new_ships_table(int dim, char table[][DIM_MAX]) {
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      table[i][j] = CELL_EMPTY;
    }
  }
}

void new_shots_table(int dim, char table[][DIM_MAX]) {
  for (int i = 0; i < dim; i++) {
    for (int j = 0; j < dim; j++) {
      table[i][j] = CELL_EMPTY;
    }
  }
}

void load_game() {
  printf("load_game()");
  getchar();
}

void play_game(int dim, int mode, player_t players[]) {
  print_tables(dim, players[0].ships, players[0].shots);
  getchar();
}

void print_tables(int dim, char table1[][DIM_MAX], char table2[][DIM_MAX]) {
  int row, col;
  char abc[] = "ABCDEFGHIJ";

  printf("\n\n  Ship table \tShooting table\n\n");
  printf("     ");

  for (col = 0; col < dim; col++) {
    printf("%c ", abc[col]);
  }

  printf(" \t   ");

  for (col = 0; col < dim; col++) {
    printf("%c ", abc[col]);
  }

  for (row = 0; row < dim; row++) {
    printf("\n  %2d ", row+1);

    for (col = 0; col < dim; col++) {
      printf("%c ", table1[col][row]);
    }

    printf(" \t");
    printf("%2d ", row+1);

    for (col = 0; col < dim; col++) {
      printf("%c ", table2[col][row]);
    }
  }

  printf("\n");
}

void save_game() {
  printf("save_game()");
  getchar();
}

void scoreboard(records_t records) {
  system("cls");
  if (records.num_records > 0) {
    printf("Player\t\tPoints\n\n");
    for (int i = 0; i < records.num_records; i++) {
      printf("%2d. %s\t\t%d\n", i+1, records.record[i].name, records.record[i].points);
    }
  } else printf("There are no records to show.\n");
  printf("\nPress enter to return to the main menu...");
  getchar();
}

void sort_records(records_t records) {
  // TODO.
}