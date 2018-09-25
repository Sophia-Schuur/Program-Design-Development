
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RULES 1
#define PLAY 2
#define EXIT 3

#define ROWS 10
#define COLS 10

#define PLAYER 1
#define COMPUTER 2

typedef enum boolean
{
	FALSE, TRUE
} BOOL;

typedef enum direction
{
	HOR, VER
} Dir;

typedef struct stats
{
	int hits;
	int misses;
	int total_shots;
	int hitMissRatio;
}STATS;

typedef struct pieces
{
	int carrier_hp;
	int battleship_hp;
	int cruiser_hp;
	int submarine_hp;
	int destroyer_hp;
	int player_hp;

}PIECES;

void print_game_rules(void);
void init_board(char board[][10], int rows, int cols);
void print_board(char board[][10], int rows, int cols, int player);

Dir generate_dir(void);
void generate_strt_pt(int *row_ptr, int *col_ptr, Dir direction, int length);

void place_ships(char board[][10], int rows, int cols, int player_num);


int is_hit_or_miss(int row, int col, char board[][10], PIECES *player, STATS *stats, FILE *outfile, int player_num);
int get_coordinate(char p1_board[][10], char p2_board[][10], PIECES *player, STATS *stats, FILE *outfile, int player_num);
void random_board(char board[][10], int player_num);
int place_ran_ships(char board[][10], int row, int col, Dir direction, char ship, int length);

int get_computer_coordinate(char p1_board[][10], char p2_board[][10], PIECES *player, STATS *stats, FILE *outfile, int player_num);
int generate_rand_comp_row();
int generate_rand_comp_col();


