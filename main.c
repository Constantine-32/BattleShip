/*----------------------------------------------------------------
|   Author: Christian Callau Romero
|   e-mail: id.32@outlook.com
|   Date: July 2017                 Version: 2.0
|-----------------------------------------------------------------|
|	Project name: BattleShip
|	Name: main.c
|   File description:   Main.
| ----------------------------------------------------------------*/

#include "types.h"
#include "functions.h"

int main() {

  srand((unsigned)time(NULL));
  system("color 1f");

  Game_t game;
  Scores_t scores;

  bool exit = false;
  bool isGame = false;

  if (!load_scores(&scores)) {
    scores.num = 0;
  }

  while (!exit) {
    switch (main_menu(isGame)) {
    case 1:
      new_game(&game);
      isGame = true;
      break;
    case 2:
      isGame = load_game(&game);
      break;
    case 3:
      isGame = play_game(&game);
      break;
    case 4:
      save_game(game);
      break;
    case 5:
      scoreboard(scores);
      break;
    case 6:
      exit = true;
      break;
    default:
      break;
    }
  }

  return 0;
}