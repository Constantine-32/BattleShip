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

Coord_t get_coord_from_ai(const Table_t *table) {
  Coord_t coord;

  for (coord.row = 0; coord.row < table->dim; coord.row++) {
    for (coord.col = 0; coord.col < table->dim; coord.col++) {
      if (is_ship_not_sunk(table, &coord)) {
        if (is_ship_horizont(table, &coord)) {
          if (coord.row - 1 >= 0 && table->grid[coord.row - 1][coord.col] == UNKNOWN) {
            coord.row--;
          } else {
            while (table->grid[coord.row][coord.col] == SHIP) coord.row++;
          }
        } else if (is_ship_vertical(table, &coord)) {
          if (coord.col - 1 >= 0 && table->grid[coord.row][coord.col - 1] == UNKNOWN) {
            coord.col--;
          } else {
            while (table->grid[coord.row][coord.col] == SHIP) coord.col++;
          }
        } else {
          Coord_t temp;
          do {
            temp = random_adjacent_coord(coord);
          } while (!valid_coord(&temp, table->dim) || table->grid[temp.row][temp.col] != UNKNOWN);
          return temp;
        }
        return coord;
      }
    }
  }

  int ship_1 = SHIP_1_NUMB;
  int ship_2 = SHIP_2_NUMB;
  int ship_3 = SHIP_3_NUMB;

  for (int row = 0; row < table->dim; row++) {
    for (int col = 0; col < table->dim; col++) {
      if (table->grid[row][col] == SHIP) {
        if (row + 1 < table->dim && table->grid[row + 1][col] == SHIP) {
          if (row + 2 < table->dim && table->grid[row + 2][col] == SHIP) {
            if (row + 3 < table->dim && table->grid[row + 3][col] == SHIP) {
              ship_1--;
            } else if (row - 1 < 0 || row - 1 >= 0 && table->dim && table->grid[row - 1][col] != SHIP) {
              ship_2--;
            }
          } else if (row - 1 < 0 || row - 1 >= 0 && table->dim && table->grid[row - 1][col] != SHIP) {
            ship_3--;
          }
        } else if (col + 1 < table->dim && table->grid[row][col + 1] == SHIP) {
          if (col + 2 < table->dim && table->grid[row][col + 2] == SHIP) {
            if (col + 3 < table->dim && table->grid[row][col + 3] == SHIP) {
              ship_1--;
            } else if (col - 1 < 0 || col - 1 >= 0 && table->dim && table->grid[row][col - 1] != SHIP) {
              ship_2--;
            }
          } else if (col - 1 < 0 || col - 1 >= 0 && table->dim && table->grid[row][col - 1] != SHIP) {
            ship_3--;
          }
        }
      }
    }
  }

  int prob_table[table->dim][table->dim];

  for (int i = 0; i < table->dim; i++) {
    for (int j = 0; j < table->dim; j++) {
      prob_table[i][j] = 0;
    }
  }

  for (int i = 0; i < table->dim; i++) {
    for (int j = 0; j < table->dim; j++) {
      if (ship_1 > 0) {
        if ((table->grid[i][j] == UNKNOWN) &&
            (i + 1 < table->dim && table->grid[i + 1][j] == UNKNOWN) &&
            (i + 2 < table->dim && table->grid[i + 2][j] == UNKNOWN) &&
            (i + 3 < table->dim && table->grid[i + 3][j] == UNKNOWN)) {
          prob_table[i][j]++;
          prob_table[i + 1][j]++;
          prob_table[i + 2][j]++;
          prob_table[i + 3][j]++;
        }
        if ((table->grid[i][j] == UNKNOWN) &&
            (j + 1 < table->dim && table->grid[i][j + 1] == UNKNOWN) &&
            (j + 2 < table->dim && table->grid[i][j + 2] == UNKNOWN) &&
            (j + 3 < table->dim && table->grid[i][j + 3] == UNKNOWN)) {
          prob_table[i][j]++;
          prob_table[i][j + 1]++;
          prob_table[i][j + 2]++;
          prob_table[i][j + 3]++;
        }
      }
      if (ship_2 > 0) {
        if ((table->grid[i][j] == UNKNOWN) &&
            (i + 1 < table->dim && table->grid[i + 1][j] == UNKNOWN) &&
            (i + 2 < table->dim && table->grid[i + 2][j] == UNKNOWN)) {
          prob_table[i][j]++;
          prob_table[i + 1][j]++;
          prob_table[i + 2][j]++;
        }
        if ((table->grid[i][j] == UNKNOWN) &&
            (j + 1 < table->dim && table->grid[i][j + 1] == UNKNOWN) &&
            (j + 2 < table->dim && table->grid[i][j + 2] == UNKNOWN)) {
          prob_table[i][j]++;
          prob_table[i][j + 1]++;
          prob_table[i][j + 2]++;
        }
      }
      if (ship_3 > 0) {
        if ((table->grid[i][j] == UNKNOWN) &&
            (i + 1 < table->dim && table->grid[i + 1][j] == UNKNOWN)) {
          prob_table[i][j]++;
          prob_table[i + 1][j]++;
        }
        if ((table->grid[i][j] == UNKNOWN) &&
            (j + 1 < table->dim && table->grid[i][j + 1] == UNKNOWN)) {
          prob_table[i][j]++;
          prob_table[i][j + 1]++;
        }
      }
    }
  }

  int highest_prob = 0;

  for (int i = 0; i < table->dim; i++) {
    for (int j = 0; j < table->dim; j++) {
      if (prob_table[i][j] > highest_prob) {
        highest_prob = prob_table[i][j];
      }
    }
  }

  do {
    coord.row = rand() % table->dim;
    coord.col = rand() % table->dim;
  } while (table->grid[coord.row][coord.col] != UNKNOWN ||
           prob_table[coord.row][coord.col] != highest_prob);

  return coord;
}

bool is_ship_not_sunk(const Table_t *table, const Coord_t *coord) {
  return table->grid[coord->row][coord->col] == SHIP && (
          coord->row - 1 >= 0 && table->grid[coord->row - 1][coord->col] == UNKNOWN ||
          coord->col - 1 >= 0 && table->grid[coord->row][coord->col - 1] == UNKNOWN ||
          coord->row + 1 < table->dim && table->grid[coord->row + 1][coord->col] == UNKNOWN ||
          coord->col + 1 < table->dim && table->grid[coord->row][coord->col + 1] == UNKNOWN);
}

bool is_ship_horizont(const Table_t *table, const Coord_t *coord) {
  return coord->row - 1 >= 0 && table->grid[coord->row - 1][coord->col] == SHIP ||
         coord->row + 1 < table->dim && table->grid[coord->row + 1][coord->col] == SHIP;
}

bool is_ship_vertical(const Table_t *table, const Coord_t *coord) {
  return coord->col - 1 >= 0 && table->grid[coord->row][coord->col - 1] == SHIP ||
         coord->col + 1 < table->dim && table->grid[coord->row][coord->col + 1] == SHIP;
}

Coord_t random_adjacent_coord(Coord_t coord) {
  rand() % 2 == 0 ? (rand() % 2 == 0 ? coord.row++ : coord.row--) : (rand() % 2 == 0 ? coord.col++ : coord.col--);
  return coord;
}