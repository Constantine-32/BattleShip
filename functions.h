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

// Menu control
int main_menu(bool game);
void show_menu(bool game);
bool valid_option(bool game, int option);
// New game
void new_game(int *dim, int *mode, player_t players[]);
void new_player(int dim, player_t player);
void new_ships_table(int dim, char table[][DIM_MAX]);
void new_shots_table(int dim, char table[][DIM_MAX]);
// Asd
void load_game();
void play_game(int dim, int player_num, player_t players[]);
void print_tables(int dim, char table1[][DIM_MAX], char table2[][DIM_MAX]);
void save_game();
void scoreboard(records_t records);

#endif //BATTLESHIP_FUNCIONS_H
