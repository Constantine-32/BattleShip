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

  player_t players[2];
  records_t records;
  records.num_records = 0;

  int dim = 8;
  int mode = 0;

  bool exit = false;
  bool game = false;

  while (!exit) {
    switch (main_menu(game)) {
    case 1:
      new_game(&dim, &mode, players);
      game = true;
      break;
    case 2:
      load_game();
      game = true;
      break;
    case 3:
      play_game(dim, mode, players);
      game = false;
      break;
    case 4:
      save_game();
      break;
    case 5:
      scoreboard(records);
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