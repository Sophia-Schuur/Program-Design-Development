#include <stdio.h>
#include <math.h>

#include <stdlib.h> 
#include <time.h>

#define RULES 1
#define PLAY 2
#define EXIT 3

void count_values(int dice[], int dice_values_count[]);
void print_game_rules(void);
void roll_dice(int dice[], int size);
int reroll_die(void);
int reroll_dice_function(int dice[], int die_value);
void update_score2(int score2[], int selection, int total, int is_used[]);
// precondition: dice_ptr must be referring to contiguous memory
void print_dice(int *dice_ptr, int size);

//void count_dice(int dice[], int size, int dice_value_count[], int size_count);
void print_13_menu(void);
//int sum_num(int value, int n);
int get_selection(int is_used[], int dice[]);
int get_selection2(int is_used2[], int dice[]);
int check_is_used(int selection, int is_used[], int dice[]);
int check_is_used2(int selection, int is_used2[], int dice[]);

void update_score(int score[], int selection, int total, int is_used[]);

int sum_ones(int dice[]);
int sum_twos(int dice[]);
int sum_threes(int dice[]);
int sum_fours(int dice[]);
int sum_fives(int dice[]);
int sum_sixes(int dice[]);
int three_of_a_kind(int dice_values_count[], int dice[], int sum);
int four_of_a_kind(int dice_values_count[], int dice[]);

int full_house(int dice_values_count[], int dice[]);
int small_straight(int dice_values_count[], int dice[]);
int large_straight(int dice_values_count[], int dice[]);
int yahtzee(int dice_values_count[], int dice[]);
int chance(int dice_values_count[], int dice[]);

void process2(int selection, int is_used2[], int score2[], int dice[], int dice_values_count[]);


int sum_dice(int dice[], int sum);
