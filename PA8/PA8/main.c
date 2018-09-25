//Sophia Schuur
//PA 8
//12/1/2016
//Performs multiple separate functions.



#include "header.h"

int main(void)
{
	//my_str_n_cpy
	char destination[20] = { "Sophie" };
	char source[20] = { "Ryan" };
	my_str_n_cpy(destination, source, 2);
	printf("Copied string: ");
	printf(" %s\n", destination);

	//BINARY SEARCH - returns 1 if value exists. returns 0 if it doesn't.
	int values[4] = { 0,3,4,6 };
	int found = binary_search(values, 4, 3);
	printf("Binary search: %d\n", found);
	

	////BUBBLE SORT
	char *strings[] = { "bear", "apple", "zed", "dog" };
	bubble_sort(strings, 4);

	//PALINDROME
	char string[] = { "racecar" };
	int x = 0;
	int length = strlen(string);
	x = is_palindrome(string, length);
	if (x == 1)
	{
		printf("Is a palindrome\n");
	}
	else
	{
		printf("Not a palindrome\n");
	}
	
	//SUM PRIMES
	int prime = 11, sum = 0;
	sum = sum_primes(prime, sum);
	printf("\nSum of primes from 2 to %d: %d\n", prime, sum);


	//MAX OCCURRENCES
	char string_occurences[] = { "sophiei" };
	Occurrences occurrences[128];
	int i = 0;
	for (i = 0; i < 128; i++)
	{
		occurrences[i].frequency = 0.0;
		occurrences[i].num_occurrences = 0;
	}
	char t = '\0';
	int i_ptr = 0;
	char c_ptr = '\0';
	
	maximum_occurences(string_occurences, occurrences, &i_ptr, &c_ptr);



	//smallest_sum_sequence
	int integers[5] = { -2,-1,0,1,2 };				//SHOULD PRINT -3
	int lowsum = 0;
	lowsum = smallest_sum_sequence(integers, 5);
	printf("\nMin sum sequence: %d\n", lowsum);


	
		return 0;
	
}