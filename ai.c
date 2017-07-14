/*----------------------------------------------------------------
|   Author: Christian Callau Romero
|   e-mail: id.32@outlook.com
|   Date: July 2017                 Version: 2.0
|-----------------------------------------------------------------|
|	Project name: BattleShip
|	Name: ai.c
|   File description:   AI main and auxiliar functions.
| ----------------------------------------------------------------*/

#include "types.h"
#include "functions.h"

Coord_t get_coord_from_ai(const Table_t *shots_table) {
  Coord_t coord;
  ProbTable_t prob_table = get_prob_table(shots_table);

  if (is_ship_not_sunk(shots_table, &coord)) {
    if (is_ship_horizont(shots_table, &coord)) return random_horizont_coord(shots_table, &prob_table, &coord);
    if (is_ship_vertical(shots_table, &coord)) return random_vertical_coord(shots_table, &prob_table, &coord);
    return random_adjacent_coord(shots_table, &prob_table, &coord);
  }

  do {
    coord.row = rand() % shots_table->dim;
    coord.col = rand() % shots_table->dim;
  } while (shots_table->grid[coord.row][coord.col] != UNKNOWN ||
           prob_table.table[coord.row][coord.col] != prob_table.highest_prob);

  return coord;
}

ProbTable_t get_prob_table(const Table_t *shots_table) {
  ProbTable_t prob_table;
  Coord_t coord;

  for (coord.row = 0; coord.row < shots_table->dim; coord.row++) {
    for (coord.col = 0; coord.col < shots_table->dim; coord.col++) {
      prob_table.table[coord.row][coord.col] = 0;
    }
  }

  int ship_1_left = SHIP_1_NUMB;
  int ship_2_left = SHIP_2_NUMB;
  int ship_3_left = SHIP_3_NUMB;

  for (coord.row = 0; coord.row < shots_table->dim; coord.row++) {
    for (coord.col = 0; coord.col < shots_table->dim; coord.col++) {
      if (shots_table->grid[coord.row][coord.col] == SHIP) {
        int size = get_ship_size(shots_table, coord);
        if      (size == SHIP_1_SIZE) ship_1_left--;
        else if (size == SHIP_2_SIZE) ship_2_left--;
        else if (size == SHIP_3_SIZE) ship_3_left--;
      }
    }
  }

  if (SHIP_1_SIZE > 1 && ship_1_left > 0) add_ship_prob(shots_table, &prob_table, SHIP_1_SIZE);
  if (SHIP_2_SIZE > 1 && ship_2_left > 0) add_ship_prob(shots_table, &prob_table, SHIP_2_SIZE);
  if (SHIP_3_SIZE > 1 && ship_3_left > 0) add_ship_prob(shots_table, &prob_table, SHIP_3_SIZE);

  prob_table.highest_prob = 0;

  for (coord.row = 0; coord.row < shots_table->dim; coord.row++) {
    for (coord.col = 0; coord.col < shots_table->dim; coord.col++) {
      if (shots_table->grid[coord.row][coord.col] == UNKNOWN &&
          prob_table.table[coord.row][coord.col] > prob_table.highest_prob) {
        prob_table.highest_prob = prob_table.table[coord.row][coord.col];
      }
    }
  }

  return prob_table;
}

int get_ship_size(const Table_t *shots_table, Coord_t coord) {
  if (coord.row - 1 >= 0 && shots_table->grid[coord.row - 1][coord.col] == SHIP ||
      coord.col - 1 >= 0 && shots_table->grid[coord.row][coord.col - 1] == SHIP ||
      has_any_adjacent_unknown(shots_table, &coord)) {
    return -1;
  }

  int size = 1;

  while (coord.row + 1 < shots_table->dim && shots_table->grid[coord.row + 1][coord.col] == SHIP) {
    coord.row++;
    if (has_any_adjacent_unknown(shots_table, &coord)) return -1;
    size++;
  }
  while (coord.col + 1 < shots_table->dim && shots_table->grid[coord.row][coord.col + 1] == SHIP) {
    coord.col++;
    if (has_any_adjacent_unknown(shots_table, &coord)) return -1;
    size++;
  }

  return size;
}

bool has_any_adjacent_unknown(const Table_t *shots_table, const Coord_t *coord) {
  return coord->row - 1 >= 0 && shots_table->grid[coord->row - 1][coord->col] == UNKNOWN ||
         coord->row + 1 < shots_table->dim && shots_table->grid[coord->row + 1][coord->col] == UNKNOWN ||
         coord->col - 1 >= 0 && shots_table->grid[coord->row][coord->col - 1] == UNKNOWN ||
         coord->col + 1 < shots_table->dim && shots_table->grid[coord->row][coord->col + 1] == UNKNOWN;
}

void add_ship_prob(const Table_t *shots_table, ProbTable_t *prob_table, int ship_size) {
  for (int row = 0; row < shots_table->dim; row++) {
    for (int col = 0; col < shots_table->dim; col++) {
      int pivot = 0;
      while (pivot < ship_size && row + pivot < shots_table->dim && shots_table->grid[row + pivot][col] != WATER) {
        pivot++;
      }
      if (pivot == ship_size) {
        for (int add = 0; add < ship_size; add++) {
          prob_table->table[row + add][col]++;
        }
      }
      pivot = 0;
      while (pivot < ship_size && col + pivot < shots_table->dim && shots_table->grid[row][col + pivot] != WATER) {
        pivot++;
      }
      if (pivot == ship_size) {
        for (int add = 0; add < ship_size; add++) {
          prob_table->table[row][col + add]++;
        }
      }
    }
  }
}

bool is_ship_not_sunk(const Table_t *shots_table, Coord_t *coord) {
  for (coord->row = 0; coord->row < shots_table->dim; coord->row++) {
    for (coord->col = 0; coord->col < shots_table->dim; coord->col++) {
      if (shots_table->grid[coord->row][coord->col] == SHIP && has_any_adjacent_unknown(shots_table, coord)) {
        return true;
      }
    }
  }
  return false;
}

bool is_ship_horizont(const Table_t *shots_table, const Coord_t *coord) {
  return coord->col - 1 >= 0 && shots_table->grid[coord->row][coord->col - 1] == SHIP ||
         coord->col + 1 < shots_table->dim && shots_table->grid[coord->row][coord->col + 1] == SHIP;
}

bool is_ship_vertical(const Table_t *shots_table, const Coord_t *coord) {
  return coord->row - 1 >= 0 && shots_table->grid[coord->row - 1][coord->col] == SHIP ||
         coord->row + 1 < shots_table->dim && shots_table->grid[coord->row + 1][coord->col] == SHIP;
}

Coord_t random_horizont_coord(const Table_t *shots_table, const ProbTable_t *prob_table, const Coord_t *coord) {
  Coord_t temp1, temp2;
  temp1.row = temp2.row = coord->row;
  temp1.col = temp2.col = coord->col;

  while (temp1.col - 1 >= 0 && shots_table->grid[temp1.row][temp1.col - 1] == SHIP) temp1.col--;
  if (temp1.col - 1 >= 0 && shots_table->grid[temp1.row][temp1.col - 1] == UNKNOWN) temp1.col--;

  while (temp2.col + 1 < shots_table->dim && shots_table->grid[temp2.row][temp2.col + 1] == SHIP) temp2.col++;
  if (temp2.col + 1 < shots_table->dim && shots_table->grid[temp2.row][temp2.col + 1] == UNKNOWN) temp2.col++;

  if (shots_table->grid[temp1.row][temp1.col] != UNKNOWN) return temp2;
  if (shots_table->grid[temp2.row][temp2.col] != UNKNOWN) return temp1;

  int prob_temp1 = prob_table->table[temp1.row][temp1.col];
  int prob_temp2 = prob_table->table[temp2.row][temp2.col];

  if (prob_temp1 > prob_temp2) return temp1;
  if (prob_temp1 < prob_temp2) return temp2;

  return rand() % 2 == 0 ? temp1 : temp2;
}

Coord_t random_vertical_coord(const Table_t *shots_table, const ProbTable_t *prob_table, const Coord_t *coord) {
  Coord_t temp1, temp2;
  temp1.row = temp2.row = coord->row;
  temp1.col = temp2.col = coord->col;

  while (temp1.row - 1 >= 0 && shots_table->grid[temp1.row - 1][temp1.col] == SHIP) temp1.row--;
  if (temp1.row - 1 >= 0 && shots_table->grid[temp1.row - 1][temp1.col] == UNKNOWN) temp1.row--;

  while (temp2.row + 1 < shots_table->dim && shots_table->grid[temp2.row + 1][temp2.col] == SHIP) temp2.row++;
  if (temp2.row + 1 < shots_table->dim && shots_table->grid[temp2.row + 1][temp2.col] == UNKNOWN) temp2.row++;

  if (shots_table->grid[temp1.row][temp1.col] != UNKNOWN) return temp2;
  if (shots_table->grid[temp2.row][temp2.col] != UNKNOWN) return temp1;

  int prob_temp1 = prob_table->table[temp1.row][temp1.col];
  int prob_temp2 = prob_table->table[temp2.row][temp2.col];

  if (prob_temp1 > prob_temp2) return temp1;
  if (prob_temp1 < prob_temp2) return temp2;

  return rand() % 2 == 0 ? temp1 : temp2;
}

Coord_t random_adjacent_coord(const Table_t *shots_table, const ProbTable_t *prob_table, const Coord_t *coord) {
  Coord_t temp;
  int rowShift[] = {-1, 0, 1, 0};
  int colShift[] = {0, 1, 0, -1};
  int highest_prob = 0;
  int index;

  for (index = 0; index < 4; index++) {
    temp.row = coord->row + rowShift[index];
    temp.col = coord->col + colShift[index];
    if (is_valid_coord(&temp, shots_table->dim) && shots_table->grid[temp.row][temp.col] == UNKNOWN &&
        prob_table->table[temp.row][temp.col] > highest_prob) {
      highest_prob = prob_table->table[temp.row][temp.col];
    }
  }

  do {
    index = rand() % 4;
    temp.row = coord->row + rowShift[index];
    temp.col = coord->col + colShift[index];
  } while (!is_valid_coord(&temp, shots_table->dim) || shots_table->grid[temp.row][temp.col] != UNKNOWN ||
           prob_table->table[temp.row][temp.col] < highest_prob);

  return temp;
}

bool is_valid_coord(const Coord_t *coord, int dim) {
  return coord->row >= 0 && coord->row < dim && coord->col >= 0 && coord->col < dim;
}