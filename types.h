/*----------------------------------------------------------------
|   Author: Christian Callau Romero
|   e-mail: id.32@outlook.com
|   Date: July 2017                 Version: 2.0
|-----------------------------------------------------------------|
|	Project name: BattleShip
|	Name: types.h
|   File description:   Types and constants.
| ----------------------------------------------------------------*/

#ifndef BATTLESHIP_TIPUS_H
#define BATTLESHIP_TIPUS_H

/* Standard libraries */
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Project constants */
#define DIM_MAX         10
#define DIM_MIN         8
#define MAX_NAME        10
#define MAX_RECORDS     25

#define FITXER_RECORDS  "records.txt"
#define FITXER_JOC      "partida.bin"

/* Enums */
enum orientation {
  HORIZONTAL = 0,
  VERTICAL = 1
};

enum cell {
  CELL_EMPTY = '?',
  CELL_WATER = '.',
  CELL_WATER_HIT = '-',
  CELL_SHIP = '@',
  CELL_SHIP_HIT = 'X'
};

enum shoot {
  ERROR = -1,
  REPEATED = 0,
  WATER = 1,
  HIT = 2,
  SUNK = 3
};

/* Types */
typedef char name_t[MAX_NAME];

typedef struct {
  name_t name;
  int points;
} record_t;

typedef struct {
  int num_records;
  record_t record[MAX_RECORDS];
} records_t;

typedef struct {
  char col;
  int row;
} coord_t;

typedef struct {
  name_t name;
  coord_t coord;
  char ships[DIM_MAX][DIM_MAX];
  char shots[DIM_MAX][DIM_MAX];
  int sunk_ships;
  int shot_count;
  int result_sum;
  int result;
} player_t;

#endif //BATTLESHIP_TIPUS_H
