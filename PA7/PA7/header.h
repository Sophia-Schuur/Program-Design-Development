#include <stdio.h>

#define TUTORIAL 1
#define INITIALS 2
#define DO_MATH 3
#define EXIT 4

#define EASY 1
#define FAIR 2
#define MEDIUM 3
#define HARD 4
#define IMPOSSIBLE 5

int print_interface1(int option);
void print_tutorial();

int easy_mode();
int fair_mode();
int intermediate_mode();
int hard_mode();
int impossible_mode();


int generate_easy_single_digit();
int generate_hard_single_digit();