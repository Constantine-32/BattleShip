/*----------------------------------------------------------------
|   Author: Christian Callau Romero
|   e-mail: id.32@outlook.com
|   Date: July 2017                 Version: 2.0
|-----------------------------------------------------------------|
|   Project name: Battleship
|   Name: ai.c
|   File description:   AI main and auxiliar functions.
| ----------------------------------------------------------------*/

#include "types.h"
#include "functions.h"

Coord_t get_coord_from_ai(const Table_t *shots_table) {
  Coord_t coord;
  ProbTable_t prob_table = ini_prob_table(shots_table);

  if (get_undestr_ship(shots_table, &coord)) {
    switch (get_ship_orientation(shots_table, &coord)) {
    case HORIZONTAL:
      get_single_prob(shots_table, &prob_table, &coord, HORIZONTAL);
      return random_horizont_coord(shots_table, &prob_table, &coord);
    case VERTICAL:
      get_single_prob(shots_table, &prob_table, &coord, VERTICAL);
      return random_vertical_coord(shots_table, &prob_table, &coord);
    case NONE:
      get_single_prob(shots_table, &prob_table, &coord, HORIZONTAL);
      get_single_prob(shots_table, &prob_table, &coord, VERTICAL);
      return random_adjacent_coord(shots_table, &prob_table, &coord);
    }
  }

  get_overall_prob(shots_table, &prob_table);
  do {
    coord.row = rand() % shots_table->dim;
    coord.col = rand() % shots_table->dim;
  } while (shots_table->grid[coord.row][coord.col] != UNKNOWN ||
           prob_table.table[coord.row][coord.col] != prob_table.highest_prob);

  return coord;
}

ProbTable_t ini_prob_table(const Table_t *shots_table) {
  ProbTable_t prob_table;
  Coord_t coord;

  for (coord.row = 0; coord.row < shots_table->dim; coord.row++)
    for (coord.col = 0; coord.col < shots_table->dim; coord.col++)
      prob_table.table[coord.row][coord.col] = 0;

  int ship_1_left = SHIP_1_NUMB;
  int ship_2_left = SHIP_2_NUMB;
  int ship_3_left = SHIP_3_NUMB;

  for (coord.row = 0; coord.row < shots_table->dim; coord.row++) {
    for (coord.col = 0; coord.col < shots_table->dim; coord.col++) {
      if (shots_table->grid[coord.row][coord.col] == SHIP) {
        switch (get_ship_size(shots_table, coord)) {
        case SHIP_1_SIZE: ship_1_left--; break;
        case SHIP_2_SIZE: ship_2_left--; break;
        case SHIP_3_SIZE: ship_3_left--; break;
        default: break;
        }
      }
    }
  }

  prob_table.highest_prob = 0;

  return prob_table;
}

int get_ship_size(const Table_t *shots_table, Coord_t coord) {
  if (coord.row-1 >= 0 && shots_table->grid[coord.row - 1][coord.col] == SHIP ||
      coord.col-1 >= 0 && shots_table->grid[coord.row][coord.col - 1] == SHIP ||
      has_any_adjacent(shots_table, &coord, UNKNOWN))
    return -1;

  int size = 1;

  while (coord.row + 1 < shots_table->dim &&
         shots_table->grid[coord.row + 1][coord.col] == SHIP) {
    coord.row++;
    if (has_any_adjacent(shots_table, &coord, UNKNOWN)) return -1;
    size++;
  }
  while (coord.col + 1 < shots_table->dim &&
         shots_table->grid[coord.row][coord.col + 1] == SHIP) {
    coord.col++;
    if (has_any_adjacent(shots_table, &coord, UNKNOWN)) return -1;
    size++;
  }

  return size;
}

bool has_any_adjacent(const Table_t *shots_table, const Coord_t *coord,
                      Cell_e cell) {
  return coord->row - 1 >= 0 &&
         shots_table->grid[coord->row - 1][coord->col] == cell ||
         coord->row + 1 < shots_table->dim &&
         shots_table->grid[coord->row + 1][coord->col] == cell ||
         coord->col - 1 >= 0 &&
         shots_table->grid[coord->row][coord->col - 1] == cell ||
         coord->col + 1 < shots_table->dim &&
         shots_table->grid[coord->row][coord->col + 1] == cell;
}

bool get_undestr_ship(const Table_t *shots_table, Coord_t *coord) {
  for (coord->row = 0; coord->row < shots_table->dim; coord->row++)
    for (coord->col = 0; coord->col < shots_table->dim; coord->col++)
      if (shots_table->grid[coord->row][coord->col] == SHIP &&
          has_any_adjacent(shots_table, coord, UNKNOWN))
        return true;
  return false;
}

Orientation_e get_ship_orientation(const Table_t *shots_table,
                                   const Coord_t *coord) {
  if (is_ship_horizont(shots_table, coord)) return HORIZONTAL;
  if (is_ship_vertical(shots_table, coord)) return VERTICAL;
  return NONE;
}

bool is_ship_horizont(const Table_t *shots_table, const Coord_t *coord) {
  return coord->col - 1 >= 0 &&
         shots_table->grid[coord->row][coord->col - 1] == SHIP ||
         coord->col + 1 < shots_table->dim &&
         shots_table->grid[coord->row][coord->col + 1] == SHIP;
}

bool is_ship_vertical(const Table_t *shots_table, const Coord_t *coord) {
  return coord->row - 1 >= 0 &&
         shots_table->grid[coord->row - 1][coord->col] == SHIP ||
         coord->row + 1 < shots_table->dim &&
         shots_table->grid[coord->row + 1][coord->col] == SHIP;
}

void get_single_prob(const Table_t *shots_table, ProbTable_t *prob_table,
                     const Coord_t *coord, Orientation_e orientation) {
  Ship_t ship;
  ship.coord = *coord;
  ship.orientation = orientation;
  if (prob_table->ship_1) {
    ship.size = SHIP_1_SIZE;
    ship_single_prob(shots_table, prob_table, &ship);
  }
  if (prob_table->ship_2) {
    ship.size = SHIP_2_SIZE;
    ship_single_prob(shots_table, prob_table, &ship);
  }
  if (prob_table->ship_3) {
    ship.size = SHIP_3_SIZE;
    ship_single_prob(shots_table, prob_table, &ship);
  }
}

void ship_single_prob(const Table_t *shots_table, ProbTable_t *prob_table,
                      const Ship_t *ship) {
  int pivot = ship->orientation == VERTICAL ? ship->coord.row : ship->coord.col;
  while (pivot - 1 >= 0 &&
         shots_table->grid[
           ship->orientation == HORIZONTAL ? ship->coord.row : pivot - 1
         ][
           ship->orientation == HORIZONTAL ? pivot - 1 : ship->coord.col
         ] == SHIP)
    pivot--;

  int ship_size = 1;
  while (pivot + ship_size < shots_table->dim &&
         shots_table->grid[
           ship->orientation == HORIZONTAL ? ship->coord.row : pivot + ship_size
         ][
           ship->orientation == HORIZONTAL ? pivot + ship_size : ship->coord.col
         ] == SHIP)
    ship_size++;

  for (int i = 0; i < ship->size - ship_size + 1; i++) {
    if (pivot >= 0 && pivot + ship->size - 1 < shots_table->dim) {
      bool ship_fits = true;
      for (int j = 0; j < ship->size; j++)
        if (shots_table->grid[
              ship->orientation == HORIZONTAL ? ship->coord.row : pivot + j
            ][
              ship->orientation == HORIZONTAL ? pivot + j : ship->coord.col
            ] == WATER)
          ship_fits = false;

      if (ship_fits)
        for (int j = 0; j < ship->size; j++)
          prob_table->table[
            ship->orientation == HORIZONTAL ? ship->coord.row : pivot + j
          ][
            ship->orientation == HORIZONTAL ? pivot + j : ship->coord.col
          ]++;
    }
    pivot--;
  }
}

void get_overall_prob(const Table_t *shots_table, ProbTable_t *prob_table) {
  Coord_t coord;

  if (prob_table->ship_1)
    ship_overal_prob(shots_table, prob_table, SHIP_1_SIZE);
  if (prob_table->ship_2)
    ship_overal_prob(shots_table, prob_table, SHIP_2_SIZE);
  if (prob_table->ship_3)
    ship_overal_prob(shots_table, prob_table, SHIP_3_SIZE);

  prob_table->highest_prob = 0;

  for (coord.row = 0; coord.row < shots_table->dim; coord.row++)
    for (coord.col = 0; coord.col < shots_table->dim; coord.col++)
      if (shots_table->grid[coord.row][coord.col] == UNKNOWN &&
          prob_table->table[coord.row][coord.col] > prob_table->highest_prob)
        prob_table->highest_prob = prob_table->table[coord.row][coord.col];
}

void ship_overal_prob(const Table_t *shots_table, ProbTable_t *prob_table,
                      int ship_size) {
  for (int row = 0; row < shots_table->dim; row++) {
    for (int col = 0; col < shots_table->dim; col++) {
      int pivot = 0;
      while (pivot < ship_size && row + pivot < shots_table->dim &&
             shots_table->grid[row + pivot][col] != WATER)
        pivot++;

      if (pivot == ship_size)
        for (int add = 0; add < ship_size; add++)
          prob_table->table[row + add][col]++;

      pivot = 0;
      while (pivot < ship_size && col + pivot < shots_table->dim &&
             shots_table->grid[row][col + pivot] != WATER)
        pivot++;

      if (pivot == ship_size)
        for (int add = 0; add < ship_size; add++)
          prob_table->table[row][col + add]++;
    }
  }
}

Coord_t random_horizont_coord(const Table_t *shots_table,
                              const ProbTable_t *prob_table,
                              const Coord_t *coord) {
  Coord_t temp1, temp2;
  temp1.row = temp2.row = coord->row;
  temp1.col = temp2.col = coord->col;

  while (temp1.col - 1 >= 0 &&
         shots_table->grid[temp1.row][temp1.col - 1] == SHIP)
    temp1.col--;
  if (temp1.col - 1 >= 0 &&
      shots_table->grid[temp1.row][temp1.col - 1] == UNKNOWN)
    temp1.col--;

  while (temp2.col + 1 < shots_table->dim &&
         shots_table->grid[temp2.row][temp2.col + 1] == SHIP)
    temp2.col++;
  if (temp2.col + 1 < shots_table->dim &&
      shots_table->grid[temp2.row][temp2.col + 1] == UNKNOWN)
    temp2.col++;

  if (shots_table->grid[temp1.row][temp1.col] != UNKNOWN) return temp2;
  if (shots_table->grid[temp2.row][temp2.col] != UNKNOWN) return temp1;

  int prob_temp1 = prob_table->table[temp1.row][temp1.col];
  int prob_temp2 = prob_table->table[temp2.row][temp2.col];

  if (prob_temp1 > prob_temp2) return temp1;
  if (prob_temp1 < prob_temp2) return temp2;

  return rand() % 2 == 0 ? temp1 : temp2;
}

Coord_t random_vertical_coord(const Table_t *shots_table,
                              const ProbTable_t *prob_table,
                              const Coord_t *coord) {
  Coord_t temp1, temp2;
  temp1.row = temp2.row = coord->row;
  temp1.col = temp2.col = coord->col;

  while (temp1.row - 1 >= 0 &&
         shots_table->grid[temp1.row - 1][temp1.col] == SHIP) temp1.row--;
  if (temp1.row - 1 >= 0 &&
      shots_table->grid[temp1.row - 1][temp1.col] == UNKNOWN) temp1.row--;

  while (temp2.row + 1 < shots_table->dim &&
         shots_table->grid[temp2.row + 1][temp2.col] == SHIP) temp2.row++;
  if (temp2.row + 1 < shots_table->dim &&
      shots_table->grid[temp2.row + 1][temp2.col] == UNKNOWN) temp2.row++;

  if (shots_table->grid[temp1.row][temp1.col] != UNKNOWN) return temp2;
  if (shots_table->grid[temp2.row][temp2.col] != UNKNOWN) return temp1;

  int prob_temp1 = prob_table->table[temp1.row][temp1.col];
  int prob_temp2 = prob_table->table[temp2.row][temp2.col];

  if (prob_temp1 > prob_temp2) return temp1;
  if (prob_temp1 < prob_temp2) return temp2;

  return rand() % 2 == 0 ? temp1 : temp2;
}

Coord_t random_adjacent_coord(const Table_t *shots_table,
                              const ProbTable_t *prob_table,
                              const Coord_t *coord) {
  Coord_t temp;
  int rowShift[] = {-1, 0, 1, 0};
  int colShift[] = {0, 1, 0, -1};
  int highest_prob = 0;
  int index;

  for (index = 0; index < 4; index++) {
    temp.row = coord->row + rowShift[index];
    temp.col = coord->col + colShift[index];
    if (is_valid_coord(&temp, shots_table->dim) &&
        shots_table->grid[temp.row][temp.col] == UNKNOWN &&
        prob_table->table[temp.row][temp.col] > highest_prob)
      highest_prob = prob_table->table[temp.row][temp.col];
  }

  do {
    index = rand() % 4;
    temp.row = coord->row + rowShift[index];
    temp.col = coord->col + colShift[index];
  } while (!is_valid_coord(&temp, shots_table->dim) ||
           shots_table->grid[temp.row][temp.col] != UNKNOWN ||
           prob_table->table[temp.row][temp.col] < highest_prob);

  return temp;
}

bool is_valid_coord(const Coord_t *coord, int dim) {
  return coord->row >= 0 && coord->row < dim &&
         coord->col >= 0 && coord->col < dim;
}
