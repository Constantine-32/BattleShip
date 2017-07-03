/*----------------------------------------------------------------
|   Author: Christian Callau Romero
|   e-mail: id.32@outlook.com
|   Date: July 2017                 Version: 2.0
|-----------------------------------------------------------------|
|	Project name: BattleShip
|	Name: functions.h
|   File description:   Function header.
| ----------------------------------------------------------------*/

#ifndef BATTLESHIP_FUNCIONS_H
#define BATTLESHIP_FUNCIONS_H

#include "types.h"

// viusal.c
int main_menu(bool game);
int mode_menu(void);
int size_menu(void);
int init_menu(void);
void print_game_0(const Player_t *player);
void print_game_1(const Player_t *player);
void print_game_2(const Player_t *player1, const Player_t *player2);
void print_table_1(const Table_t *table);
void print_table_2(const Table_t *ships_table, const Table_t *shots_table);
const char *shot_to_string(Shot_e shot);
void print_scoreboard(const Scores_t *scores);
void pause(void);
bool pause_exit(void);
bool pause_coord(Coord_t *coord, int dim);

// initialization.c
void new_game(Game_t *game);
void new_player(int dim, Player_t *player, const char *name);
void new_shots_table(Table_t *shots_table);
void new_ships_table(Table_t *ships_table);
void new_ships_table_manual(Table_t *ships_table);
void fill_table(Table_t *table, Cell_e cell);
bool place_ship(Table_t *ships_table, int size);
bool ship_fits(const Table_t *ships_table, const Ship_t *ship);
bool valid_coord(const Coord_t *coord, int dim);

// logic.c
bool play_game(Game_t *game, Scores_t *scores);
bool play_game_0(Game_t *game, Scores_t *scores);
bool play_game_1(Game_t *game, Scores_t *scores);
bool play_game_2(Game_t *game, Scores_t *scores);
Shot_e shoot(Table_t *ships_table, const Coord_t *coord);
bool is_ship_sunk(const Table_t *ships_table, const Coord_t *coord);
bool is_water(Cell_e cell);
void update_shots_table(Table_t *shots_table, const Coord_t *coord, Shot_e result);
void unveil_surroundings(Table_t *shots_table, const Coord_t *coord);
int get_score(const Player_t *player);
bool add_score(Scores_t *scores, const Score_t *score);
void sort_scores(Scores_t *scores);

// ai.
Coord_t get_coord_from_ai(const Table_t *shots_table);
bool is_ship_not_sunk(const Table_t *shots_table, const Coord_t *coord);
bool is_ship_horizont(const Table_t *shots_table, const Coord_t *coord);
bool is_ship_vertical(const Table_t *shots_table, const Coord_t *coord);
Coord_t random_adjacent_coord(Coord_t coord);

// loadsave.c
bool load_game(Game_t *game);
bool save_game(const Game_t *game);
bool load_scores(Scores_t *scores);
bool save_scores(const Scores_t *scores);

#endif //BATTLESHIP_FUNCIONS_H
