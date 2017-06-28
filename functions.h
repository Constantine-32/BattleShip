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
int mode_menu();
int size_menu();
int init_menu();
void print_table(Table_t table);
void print_tables(Table_t table1, Table_t table2);
void print_scoreboard(Scores_t scores);
const char *shot_to_string(Shot_e shot);
void pause();

// initialization.c
void new_game(Game_t *game);
void new_player(int dim, Player_t *player, char *name);
void new_shots_table(Table_t *table);
void new_ships_table(Table_t *table);
void fill_table(Table_t *table, Cell_e cell);
bool place_ship(Table_t *table, int size);
bool ship_fits(Table_t table, Ship_t ship);
bool valid_coord(Coord_t coord, int dim);
void scpy(char *c, char *s);

// logic.c
bool play_game(Game_t *game, Scores_t *scores);
bool play_game_solo_AI(Game_t *game, Scores_t *scores);
bool play_game_solo_Player(Game_t *game, Scores_t *scores);
bool play_game_Player_vs_AI(Game_t *game, Scores_t *scores);
Shot_e shoot(Table_t *ships_table, Coord_t coord);
bool is_ship_sunk(Table_t ships_table, Coord_t coord);
bool is_water(Cell_e cell);
void update_shots_table(Table_t *shots_table, Coord_t coord, Shot_e result);
void unveil_surroundings(Table_t *shots_table, Coord_t coord);
Coord_t get_coord_from_Player(Table_t table);
Coord_t get_coord_from_AI(Table_t table);
int get_score(Player_t player);

// loadsave.c
bool load_game(Game_t *game);
bool save_game(Game_t game);
bool load_scores(Scores_t *scores);
bool save_scores(Scores_t scores);

#endif //BATTLESHIP_FUNCIONS_H
