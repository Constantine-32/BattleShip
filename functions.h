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
void print_tables(Table_t t1, Table_t t2);
void scoreboard(Scores_t records);

// logic.c
void new_ships_table(Table_t *table);
void new_shots_table(Table_t *table);
bool play_game(Game_t *game);

// loadsave.c
void new_game(Game_t *game);
void new_player(int dim, Player_t *player, char *name);
bool load_game(Game_t *game);
bool save_game(Game_t game);
bool load_scores(Scores_t *scores);
bool save_scores(Scores_t scores);
void sort_scores(Scores_t *scores);
void scpy(char *c, char *s);

#endif //BATTLESHIP_FUNCIONS_H
