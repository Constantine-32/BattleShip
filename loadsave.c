/*----------------------------------------------------------------
|   Author: Christian Callau Romero
|   e-mail: id.32@outlook.com
|   Date: July 2017                 Version: 2.0
|-----------------------------------------------------------------|
|	Project name: BattleShip
|	Name: loadsave.c
|   File description:   Storing and loading of game data.
| ----------------------------------------------------------------*/

#include "types.h"
#include "functions.h"

void new_game(Game_t *game) {
  game->mode = get_mode();
  int dim = get_dim();
  new_player(dim, &game->player1, "Player1");
  new_player(dim, &game->player2, "Plater2");
}

void new_player(int dim, Player_t *player, char *name) {
  scpy(player->name, name);
  player->coord.col = '\0';
  player->coord.row = -1;
  player->ships.dim = dim;
  new_ships_table(&player->ships);
  player->shots.dim = dim;
  new_shots_table(&player->shots);
  player->sunk_ships = 0;
  player->shot_count = 0;
  player->result_sum = 0;
  player->result = 0;
}

bool load_game(Game_t *game) {
  FILE *file = fopen(GAME_FILE, "rb");
  if (file == NULL) {
    return false;
  }
  fread(game, sizeof(Game_t), 1, file);
  fclose(file);
  return true;
}

bool save_game(Game_t game) {
  FILE *file = fopen(GAME_FILE, "wb");
  if (file == NULL) {
    return false;
  }
  fwrite(&game, sizeof(Game_t), 1, file);
  fclose(file);
  return true;
}

bool load_scores(Scores_t *scores) {
  FILE *file = fopen(SCORE_FILE, "r");
  if (file == NULL) {
    return false;
  }
  return true;
}

bool save_scores(Scores_t scores) {
  FILE *file = fopen(SCORE_FILE, "w");
  if (file == NULL) {
    return false;
  }
  return true;
}

void sort_scores(Scores_t *scores) {
  printf("sort_scores()");
  getchar();
}

void scpy(char *c, char *s) {
  while (*s) {
    *c++ = *s++;
  }
  *c = '\0';
}