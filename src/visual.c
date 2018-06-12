/*----------------------------------------------------------------
|   Author: Christian Callau Romero
|   e-mail: id.32@outlook.com
|   Date: July 2017                 Version: 2.0
|-----------------------------------------------------------------|
|   Project name: Battleship
|   Name: visual.c
|   File description:   Menus and data display functions.
| ----------------------------------------------------------------*/

#include "types.h"
#include "functions.h"

int main_menu(bool game) {
  bool first_iteration = true;
  int option;
  do {
    fflush(stdin);
    system("cls");
    printf("\n  Battleship Game: Main menu\n\n");
    printf("  1. New game\n");
    printf("  2. Load game\n");
    if (game) {
      printf("  3. Play game\n");
      printf("  4. Save game\n");
      printf("  5. Scoreboard\n");
      printf("  6. Exit\n");
    } else {
      printf("  3. Scoreboard\n");
      printf("  4. Exit\n");
    }
    printf(first_iteration ?
           "\n  Select an option: " : "\n  Invalid option, try again: ");
    first_iteration = false;
  } while (scanf("%d", &option) != 1 || option < 1 ||
           (game && option > 6) || (!game && option > 4));
  fflush(stdin);
  if (!game && option > 2) option += 2;
  return option;
}

int mode_menu(void) {
  bool first_iteration = true;
  int option;
  do {
    fflush(stdin);
    system("cls");
    printf("\n  Select the game mode:\n\n");
    printf("  1. AI solo\n");
    printf("  2. Player solo\n");
    printf("  3. Player vs AI\n");
    printf(first_iteration ?
           "\n  Select an option: " : "\n  Invalid option, try again: ");
    first_iteration = false;
  } while (scanf("%d", &option) != 1 || option < 1 || option > 3);
  fflush(stdin);
  return option - 1;
}

int size_menu(void) {
  bool first_iteration = true;
  int option;
  do {
    fflush(stdin);
    system("cls");
    printf("\n  Select the table size:\n\n");
    printf("  1. 8x8\n");
    printf("  2. 9x9\n");
    printf("  3. 10x10\n");
    printf(first_iteration ?
           "\n  Select an option: " : "\n  Invalid option, try again: ");
    first_iteration = false;
  } while (scanf("%d", &option) != 1 || option < 1 || option > 3);
  fflush(stdin);
  return option + 7;
}

int init_menu(void) {
  bool first_iteration = true;
  int option;
  do {
    fflush(stdin);
    system("cls");
    printf("\n  How do you want to initialize your ships table?:\n\n");
    printf("  1. Automatic\n");
    printf("  2. Manual\n");
    printf(first_iteration ?
           "\n  Select an option: " : "\n  Invalid option, try again: ");
    first_iteration = false;
  } while (scanf("%d", &option) != 1 || option < 1 || option > 2);
  fflush(stdin);
  return option - 1;
}

void print_game_0(const Player_t *player) {
  print_table_2(&player->ships, &player->shots);
  if (player->shot_count > 0) {
    printf("\n");
    printf("  A.I. last shot: %c-%d\n", player->coord.col + 'A',
           player->coord.row + 1);
    printf("  Result: %s\n", shot_to_string(player->result));
    printf("  Shots: %d\n", player->shot_count);
    printf("  Ships left: %d\n", TOTAL_SHIPS - player->sunk_ships);
  }
}

void print_game_1(const Player_t *player) {
  print_table_1(&player->shots);
  if (player->shot_count > 0) {
    printf("\n");
    printf("  Your last shot: %c-%d\n", player->coord.col + 'A',
           player->coord.row + 1);
    printf("  Result: %s\n", shot_to_string(player->result));
    printf("  Shots: %d\n", player->shot_count);
    printf("  Ships left: %d\n", TOTAL_SHIPS - player->sunk_ships);
  }
}

void print_game_2(const Player_t *player1, const Player_t *player2) {
  print_table_2(&player1->ships, &player1->shots);
  if (player1->shot_count > 0) {
    printf("\n");
    printf("  Your last shot: %c-%d\n", player1->coord.col + 'A',
           player1->coord.row + 1);
    printf("  Result: %s\n", shot_to_string(player1->result));
    printf("  Shots: %d\n", player1->shot_count);
    printf("  Ships left: %d\n", TOTAL_SHIPS - player2->sunk_ships);
    printf("\n");
    printf("  A.I. last shot: %c-%d\n", player2->coord.col + 'A',
           player2->coord.row + 1);
    printf("  Result: %s\n", shot_to_string(player2->result));
    printf("  Shots: %d\n", player2->shot_count);
    printf("  Ships left: %d\n", TOTAL_SHIPS - player1->sunk_ships);
  }
}

void print_table_1(const Table_t *table) {
  printf("\n  You can type 'EXIT' to exit the game at any time.\n");
  printf("\n     ");
  for (int col = 0; col < table->dim; col++)
    printf("%c ", col + 'A');
  for (int row = 0; row < table->dim; row++) {
    printf("\n  %2d ", row + 1);
    for (int col = 0; col < table->dim; col++)
      printf("%c ", table->grid[row][col]);
  }
  printf("\n");
}

void print_table_2(const Table_t *ships_table, const Table_t *shots_table) {
  printf("\n  You can type 'EXIT' to exit the game at any time.\n");
  printf("\n     ");
  for (int col = 0; col < ships_table->dim; col++)
    printf("%c ", col + 'A');
  printf(" \t   ");
  for (int col = 0; col < shots_table->dim; col++)
    printf("%c ", col + 'A');
  for (int row = 0; row < ships_table->dim; row++) {
    printf("\n  %2d ", row + 1);
    for (int col = 0; col < ships_table->dim; col++)
      printf("%c ", ships_table->grid[row][col]);
    printf(" \t");
    printf("%2d ", row + 1);
    for (int col = 0; col < shots_table->dim; col++)
      printf("%c ", shots_table->grid[row][col]);
  }
  printf("\n");
}

void print_scoreboard(const Scores_t *scores) {
  system("cls");
  if (scores->num > 0) {
    printf("\n  Player\t\tPoints\n\n");
    for (int i = 0; i < scores->num && i < SCORE_SHOW_MAX; i++)
      printf("  %2d. %s\t\t%d\n", i+1, scores->score[i].name,
             scores->score[i].points);
  } else printf("\n  There are no scores to show.\n");
  pause();
}

void pause(void) {
  printf("\n  Press enter to continue...");
  getchar();
}

bool pause_exit(void) {
  char string[6];
  printf("\n  A.I.'s turn. Press enter to continue...");
  fgets(string, 6, stdin);
  fflush(stdin);
  return !(strcmp(string, "EXIT\n") == 0 || strcmp(string, "exit\n") == 0);
}

bool pause_coord(Coord_t *coord, int dim) {
  bool first_iteration = true;
  char string[10];
  int row;
  char col;
  do {
    printf(first_iteration ?
           "\n  Your turn. Type the coords [A-%c][1-%d]: " :
           "  Invalid coord, try again: ",
           dim + 64, dim );
    fgets(string, 10, stdin);
    fflush(stdin);
    if (strcmp(string, "EXIT\n") == 0 || strcmp(string, "exit\n") == 0)
      return false;
    first_iteration = false;
  } while (sscanf(string, "%c%d", &col, &row) != 2 ||
           row < 1 || row > dim ||
           col < 'A' || col >= dim + 'A');
  coord->row = row - 1;
  coord->col = col - 'A';
  return true;
}

const char *shot_to_string(Shot_e shot) {
  switch (shot) {
  case ERROR:
    return "Error";
  case REPEATED:
    return "Repeated";
  case MISS:
    return "Water";
  case HIT:
    return "Hit";
  case SUNK:
    return "Sunk";
  default:
    return "Unknown_Case";
  }
}
