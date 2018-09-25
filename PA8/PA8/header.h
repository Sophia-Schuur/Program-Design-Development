
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void my_str_n_cpy(char * destination, char * source, int n);
int binary_search(int values[], int size, int target);
void bubble_sort(char * strings[], int size);
int is_palindrome(char string[], int right);


int is_prime(unsigned int n);
int sum_primes(unsigned int n, int sum);


typedef struct occurrences
{
	int num_occurrences;
	double frequency;
} Occurrences;

void maximum_occurences(char string[], Occurrences occur[], int * i_ptr, char * c_ptr);
int smallest_sum_sequence(int array[], int size);

