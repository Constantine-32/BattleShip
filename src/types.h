/*----------------------------------------------------------------
|   Author: Christian Callau Romero
|   e-mail: id.32@outlook.com
|   Date: July 2017                 Version: 2.0
|-----------------------------------------------------------------|
|	Project name: Battleship
|	Name: types.h
|   File description:   Types and constants.
| ----------------------------------------------------------------*/

#ifndef BATTLESHIP_TYPES_H
#define BATTLESHIP_TYPES_H

/* Standard libraries */
#include <mem.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Project constants */
#define DIM_MAX         10
#define NAME_MAX        10
#define SCORE_MAX       500
#define SCORE_SHOW_MAX  10

#define GAME_FILE      "game.bin"
#define SCORE_FILE     "scores.txt"

#define SHIP_1_SIZE     4
#define SHIP_2_SIZE     3
#define SHIP_3_SIZE     2
#define SHIP_4_SIZE     1

#define SHIP_1_NUMB     1
#define SHIP_2_NUMB     2
#define SHIP_3_NUMB     3
#define SHIP_4_NUMB     4

#define TOTAL_SHIPS     (SHIP_1_NUMB + SHIP_2_NUMB + SHIP_3_NUMB + SHIP_4_NUMB)
#define ITERATIONS_MAX  100

/* Enums */
typedef enum {
  HORIZONTAL,
  VERTICAL,
  NONE
} Orientation_e;

typedef enum {
  UNKNOWN = '?',
  WATER = '.',
  WATER_HIT = '-',
  SHIP = '@',
  SHIP_HIT = 'X'
} Cell_e;

typedef enum {
  ERROR = -1,
  REPEATED,
  MISS,
  HIT,
  SUNK
} Shot_e;

/* Types */
typedef char Name_t[NAME_MAX];

typedef struct {
  Name_t name;
  int points;
  int turns;
  int size;
  int mode;
} Score_t;

typedef struct {
  Score_t score[SCORE_MAX];
  int num;
} Scores_t;

typedef struct {
  int row;
  int col;
} Coord_t;

typedef struct {
  Cell_e grid[DIM_MAX][DIM_MAX];
  int dim;
} Table_t;

typedef struct {
  int table[DIM_MAX][DIM_MAX];
  int highest_prob;
  bool ship_1;
  bool ship_2;
  bool ship_3;
} ProbTable_t;

typedef struct {
  Coord_t coord;
  Orientation_e orientation;
  int size;
} Ship_t;

typedef struct {
  Name_t name;
  Coord_t coord;
  Table_t ships;
  Table_t shots;
  Shot_e result;
  int sunk_ships;
  int shot_count;
  int result_sum;
} Player_t;

typedef struct {
  Player_t player1;
  Player_t player2;
  int mode;
  bool game;
} Game_t;

#endif //BATTLESHIP_TYPES_H
