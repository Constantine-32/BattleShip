/*----------------------------------------------------------------
|   Author: Christian Callau Romero
|   e-mail: id.32@outlook.com
|   Date: July 2017                 Version: 2.0
|-----------------------------------------------------------------|
|	Project name: BattleShip
|	Name: logic.c
|   File description:   Game logic functions.
| ----------------------------------------------------------------*/

#include "types.h"
#include "functions.h"

bool play_game(Game_t *game, Scores_t *scores) {
  system("cls");
  print_tables(game->player1.ships, game->player1.shots);
  printf("\n  Shots: %d\n", game->player1.shot_count);
  get_coord_from_Player(game->player1.shots);
  pause();

  while (game->player1.sunk_ships < TOTAL_SHIPS) {
    Shot_e result = shoot(game->player2.shots, game->player2.coord);
  }

  return false;
}

Shot_e shoot(Table_t table, Coord_t coord) {

}

Coord_t get_coord_from_Player(Table_t table) {
  char col;
  int row;
  printf("  Column [A-%c] Row [1-%d]: ", table.dim + 64, table.dim);
  while (scanf("%c%d", &col, &row) != 2 || col < 64 || col > 64 + table.dim || row < 1 || row > table.dim) {
    printf("  Invalid coord, try again: ");
    while (getchar()!='\n');
  }
  while (getchar()!='\n');
  Coord_t coord;
  coord.row = row - 1;
  coord.col = col - 1 - 64;
  return coord;
}

Coord_t get_coord_from_AI(Table_t table) {
  Coord_t coord;
  coord.row = rand() % table.dim;
  coord.col = rand() % table.dim;
  return coord;
}

int calc_points(Player_t player) {
  return (int) ((float) (player.ships.dim / player.shot_count) * player.result_sum * 100);
}