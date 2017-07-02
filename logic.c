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
  switch (game->mode) {
    case 0:
      return play_game_solo_ai(game, scores);
    case 1:
      return play_game_solo_player(game, scores);
    case 2:
      return play_game_player_vs_ai(game, scores);
    default:
      return true;
  }
}

bool play_game_solo_ai(Game_t *game, Scores_t *scores) {

  while (game->player1.sunk_ships < TOTAL_SHIPS) {
    system("cls");
    print_game_solo_ai(&game->player1);
    if (!pause_exit()) return false;

    game->player1.coord = get_coord_from_ai(&game->player1.shots);
    game->player1.result = shoot(&game->player1.ships, &game->player1.coord);
    game->player1.shot_count++;
    game->player1.result_sum += game->player1.result - 1;
    if (game->player1.result == SUNK) game->player1.sunk_ships++;
    update_shots_table(&game->player1.shots, &game->player1.coord, game->player1.result);
  }

  system("cls");
  print_game_solo_ai(&game->player1);

  game->game = false;
  remove(GAME_FILE);

  Score_t score;
  strcpy(score.name, game->player1.name);
  score.points = get_score(&game->player1);

  printf("\n");
  printf("  Game Over!\n");
  printf("  Score: %d\n", score.points);
  pause();

  if (add_score(scores, &score)) {
    save_scores(scores);
    print_scoreboard(scores);
  }

  return true;
}

bool play_game_solo_player(Game_t *game, Scores_t *scores) {

  while (game->player1.sunk_ships < TOTAL_SHIPS) {
    system("cls");
    print_game_solo_ai(&game->player1);

    if (!pause_coord(&game->player1.coord)) return false;
    game->player1.result = shoot(&game->player1.ships, &game->player1.coord);
    game->player1.shot_count++;
    game->player1.result_sum += game->player1.result - 1;
    if (game->player1.result == SUNK) game->player1.sunk_ships++;
    update_shots_table(&game->player1.shots, &game->player1.coord, game->player1.result);
  }

  system("cls");
  print_game_solo_ai(&game->player1);

  game->game = false;
  remove(GAME_FILE);

  Score_t score;
  strcpy(score.name, game->player1.name);
  score.points = get_score(&game->player1);

  printf("\n");
  printf("  Game Over!\n");
  printf("  Score: %d\n", score.points);
  pause();

  if (add_score(scores, &score)) {
    save_scores(scores);
    print_scoreboard(scores);
  }

  return true;
}

bool play_game_player_vs_ai(Game_t *game, Scores_t *scores) {
  // TODO
  return true;
}

Shot_e shoot(Table_t *ships_table, const Coord_t *coord) {
  switch (ships_table->grid[coord->row][coord->col]) {
  case WATER_HIT: case SHIP_HIT:
    return REPEATED;
  case WATER:
    ships_table->grid[coord->row][coord->col] = WATER_HIT;
    return MISS;
  case SHIP:
    ships_table->grid[coord->row][coord->col] = SHIP_HIT;
    if (is_ship_sunk(ships_table, coord)) return SUNK;
    else return HIT;
  default:
    return ERROR;
  }
}

bool is_ship_sunk(const Table_t *ships_table, const Coord_t *coord) {
  int add = -1;
  while (coord->row + add >= 0 && !is_water(ships_table->grid[coord->row + add][coord->col])) {
    if (ships_table->grid[coord->row + add][coord->col] == SHIP) return false;
    add--;
  }
  add = -1;
  while (coord->col + add >= 0 && !is_water(ships_table->grid[coord->row][coord->col + add])) {
    if (ships_table->grid[coord->row][coord->col + add] == SHIP) return false;
    add--;
  }
  add = 1;
  while (coord->row + add < ships_table->dim && !is_water(ships_table->grid[coord->row + add ][coord->col])) {
    if (ships_table->grid[coord->row + add][coord->col] == SHIP) return false;
    add++;
  }
  add = 1;
  while (coord->col + add < ships_table->dim && !is_water(ships_table->grid[coord->row][coord->col + add ])) {
    if (ships_table->grid[coord->row][coord->col + add] == SHIP) return false;
    add++;
  }
  return true;
}

bool is_water(Cell_e cell) {
  return cell == WATER || cell == WATER_HIT;
}

void update_shots_table(Table_t *shots_table, const Coord_t *coord, Shot_e result) {
  switch (result) {
  case MISS:
    shots_table->grid[coord->row][coord->col] = WATER;
    break;
  case HIT:
    shots_table->grid[coord->row][coord->col] = SHIP;
    break;
  case SUNK:
    shots_table->grid[coord->row][coord->col] = SHIP;
    unveil_surroundings(shots_table, coord);
    break;
  default:
    break;
  }
}

void unveil_surroundings(Table_t *shots_table, const Coord_t *coord) {
  Coord_t upper_left;
  Coord_t lower_right;

  upper_left.row = lower_right.row = coord->row;
  upper_left.col = lower_right.col = coord->col;

  while (upper_left.row - 1 >= 0 && shots_table->grid[upper_left.row - 1][upper_left.col] == SHIP) {
    upper_left.row--;
  }
  while (upper_left.col - 1 >= 0 && shots_table->grid[upper_left.row][upper_left.col - 1] == SHIP) {
    upper_left.col--;
  }
  if (upper_left.row - 1 >= 0) {
    upper_left.row--;
  }
  if (upper_left.col - 1 >= 0) {
    upper_left.col--;
  }

  while (lower_right.row + 1 < shots_table->dim && shots_table->grid[lower_right.row + 1][lower_right.col] == SHIP) {
    lower_right.row++;
  }
  while (lower_right.col + 1 < shots_table->dim && shots_table->grid[lower_right.row][lower_right.col + 1] == SHIP) {
    lower_right.col++;
  }
  if (lower_right.row + 1 < shots_table->dim) {
    lower_right.row++;
  }
  if (lower_right.col + 1 < shots_table->dim) {
    lower_right.col++;
  }

  for (int row = upper_left.row; row <= lower_right.row; row++) {
    for (int col = upper_left.col; col <= lower_right.col; col++) {
      if (shots_table->grid[row][col] == UNKNOWN) {
        shots_table->grid[row][col] = WATER;
      }
    }
  }
}

int get_score(const Player_t *player) {
  return (int) ((float) player->ships.dim / player->shot_count * player->result_sum * 100);
}

bool add_score(Scores_t *scores, const Score_t *score) {
  if (scores->num < SCORE_MAX || score->points > scores->score[scores->num - 1].points) {
    scores->score[scores->num < SCORE_MAX ? scores->num++ : scores->num - 1] = *score;
    sort_scores(scores);
    return true;
  } else return false;
}

void sort_scores(Scores_t *scores) {
  for (int i = 1; i < scores->num; i++) {
    int j = i;
    while (j > 0 && scores->score[j].points > scores->score[j - 1].points) {
      Score_t aux = scores->score[j];
      scores->score[j] = scores->score[j - 1];
      scores->score[j - 1] = aux;
      j--;
    }
  }
}