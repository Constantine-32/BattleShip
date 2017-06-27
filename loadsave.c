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

bool load_game(Game_t *game) {
  FILE *file = fopen(GAME_FILE, "rb");
  if (file != NULL) {
    fread(game, sizeof(Game_t), 1, file);
    fclose(file);
    return true;
  } else return false;
}

bool save_game(Game_t game) {
  FILE *file = fopen(GAME_FILE, "wb");
  if (file != NULL) {
    fwrite(&game, sizeof(Game_t), 1, file);
    fclose(file);
    return true;
  } else return false;
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