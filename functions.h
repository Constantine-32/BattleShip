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
void show_menu(bool game);
bool valid_option(bool game, int option);
int get_mode();
int get_dim();
int get_ini();
void print_table(Table_t table);
void print_tables(Table_t table1, Table_t table2);
void scoreboard(Scores_t records);
void pause();
void print_shoot(Shoot_e shoot);

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
Shoot_e shoot(Table_t table, Coord_t coord);
Coord_t get_coord_from_Player(Table_t table);
Coord_t get_coord_from_AI(Table_t table);

// loadsave.c
bool load_game(Game_t *game);
bool save_game(Game_t game);
bool load_scores(Scores_t *scores);
bool save_scores(Scores_t scores);
void sort_scores(Scores_t *scores);

#endif //BATTLESHIP_FUNCIONS_H
