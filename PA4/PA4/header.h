#include <stdio.h>

#include <stdlib.h> 
#include <time.h>

#define RULES 1
#define PLAY 2
#define EXIT 3

#define TOO_HIGH 0
#define OK 1

void print_game_rules(void);
double get_bank_balance(void);
double get_wager_amount(void);

int check_wager_amount(double wager, double balance);
int roll_die(void);
int calculate_sum_dice(int die1, int die2);
int is_win_loss_or_point(int sum);
int is_point_loss_or_neither(int sum_dice, int point_value);
double adjust_bank_balance(double balance, double wager, int add_or_subtract);
//void function_play(play_again);
void chatter_messages(double balance, double current_bank_balance);


