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
  if (file != NULL) return false;
  fread(game, sizeof(Game_t), 1, file);
  fclose(file);
  return true;
}

bool save_game(Game_t game) {
  FILE *file = fopen(GAME_FILE, "wb");
  if (file != NULL) return false;
  fwrite(&game, sizeof(Game_t), 1, file);
  fclose(file);
  return true;
}

bool load_scores(Scores_t *scores) {
  FILE *file = fopen(SCORE_FILE, "r");
  if (file == NULL) return false;
  while (!feof(file) && scores->num < SCORE_MAX) {
    if (fscanf(file, "%s\t%d\n", scores->score[scores->num].name, &scores->score[scores->num].points) == 2) {
      scores->num++;
    }
  }
  fclose(file);
  return true;
}

bool save_scores(Scores_t scores) {
  FILE *file = fopen(SCORE_FILE, "w");
  if (file == NULL) return false;
  for (int i = 0; i < scores.num; i++) {
    fprintf(file, "%s\t%d\n", scores.score[i].name, scores.score[i].points);
  }
  fclose(file);
  return true;
}