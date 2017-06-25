/*----------------------------------------------------------------
|   Author: Christian Callau Romero
|   e-mail: id.32@outlook.com
|   Date: July 2017                 Version: 2.0
|-----------------------------------------------------------------|
|	Project name: BattleShip
|	Name: logic.c
|   File description:   Game logic functions.
| ----------------------------------------------------------------*/

#include "types.h"
#include "functions.h"

void new_ships_table(Table_t *table) {
  for (int i = 0; i < DIM_MAX; i++) {
    for (int j = 0; j < DIM_MAX; j++) {
      table->grid[i][j] = CELL_WATER;
    }
  }
//  int x = rand() % table.dim;
//  int y = rand() % table.dim;
}

void new_shots_table(Table_t *table) {
  for (int i = 0; i < DIM_MAX; i++) {
    for (int j = 0; j < DIM_MAX; j++) {
      table->grid[i][j] = CELL_UNKNOWN;
    }
  }
}

bool play_game(Game_t *game) {
  system("cls");
  print_tables(game->player1.ships, game->player1.shots);
  getchar();
  return false;
}