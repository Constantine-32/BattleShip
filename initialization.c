/*----------------------------------------------------------------
|   Author: Christian Callau Romero
|   e-mail: id.32@outlook.com
|   Date: July 2017                 Version: 2.0
|-----------------------------------------------------------------|
|	Project name: BattleShip
|	Name: initialization.c
|   File description:   Game initialization functions.
| ----------------------------------------------------------------*/

#include "types.h"
#include "functions.h"

void new_game(Game_t *game) {
  game->mode = get_mode();
  int dim = get_dim();
  new_player(dim, &game->player1, "Player1");
  new_player(dim, &game->player2, "Plater2");
//  int ini = get_ini();
  game->game = true;
}

void new_player(int dim, Player_t *player, char *name) {
  scpy(player->name, name);
  player->coord.col = -1;
  player->coord.row = -1;
  player->ships.dim = dim;
  new_ships_table(&player->ships);
  player->shots.dim = dim;
  new_shots_table(&player->shots);
  player->sunk_ships = 0;
  player->shot_count = 0;
  player->result_sum = 0;
  player->result = 0;
}

void new_shots_table(Table_t *table) {
  fill_table(table, UNKNOWN);
}

void new_ships_table(Table_t *table) {
  int count;
  bool repeat = true;
  while (repeat) {
    repeat = false;
    fill_table(table, WATER);
    count = 0;
    while (!repeat && count++ < SHIP_1_NUMB) if (!place_ship(table, SHIP_1_SIZE)) repeat = true;
    count = 0;
    while (!repeat && count++ < SHIP_2_NUMB) if (!place_ship(table, SHIP_2_SIZE)) repeat = true;
    count = 0;
    while (!repeat && count++ < SHIP_3_NUMB) if (!place_ship(table, SHIP_3_SIZE)) repeat = true;
    count = 0;
    while (!repeat && count++ < SHIP_4_NUMB) if (!place_ship(table, SHIP_4_SIZE)) repeat = true;
  }
}

void fill_table(Table_t *table, Cell_e cell) {
  for (int i = 0; i < DIM_MAX; i++) {
    for (int j = 0; j < DIM_MAX; j++) {
      table->grid[i][j] = cell;
    }
  }
}

bool place_ship(Table_t *table, int size) {
  Ship_t ship;
  ship.size = size;

  int iterations = 0;
  do {
    if (iterations++ > ITERATIONS_MAX) return false;
    ship.orientation = (rand() % 2 == 0) ? HORIZONTAL : VERTICAL;
    ship.coord.row = rand() % (ship.orientation == HORIZONTAL ? table->dim : table->dim - (size - 1));
    ship.coord.col = rand() % (ship.orientation == VERTICAL ? table->dim : table->dim - (size - 1));
  } while (!ship_fits(*table, ship));

  while (size--) {
    table->grid[ship.coord.row][ship.coord.col] = SHIP;
    ship.orientation == HORIZONTAL ? ship.coord.col++ : ship.coord.row++;
  }

  return true;
}

bool ship_fits(Table_t table, Ship_t ship) {
  Coord_t stop;
  stop.row = (ship.orientation == HORIZONTAL) ? ship.coord.row + 1 : ship.coord.row + ship.size;
  stop.col = (ship.orientation == VERTICAL) ? ship.coord.col + 1 : ship.coord.col + ship.size;
  Coord_t pivot;
  pivot.row = ship.coord.row - 1;
  while (pivot.row <= stop.row) {
    pivot.col = ship.coord.col - 1;
    while (pivot.col <= stop.col) {
      if (valid_coord(pivot, table.dim) && table.grid[pivot.row][pivot.col] != WATER) {
        return false;
      }
      pivot.col++;
    }
    pivot.row++;
  }
  return true;
}

bool valid_coord(Coord_t coord, int dim) {
  return coord.row >= 0 && coord.row < dim && coord.col >= 0 && coord.col < dim;
}

void scpy(char *c, char *s) {
  while (*s) {
    *c++ = *s++;
  }
  *c = '\0';
}