#include "header.h"


void my_str_n_cpy(char *destination, char *source, int n)
{
	int i = 0;
	for (i = 0; source[i] != '\0', i < n; i++)
	{
		destination[i] = source[i];
	}
	return destination;
}

int binary_search(int list[], int size, int target)
{
	int left = 0;
	int right = size - 1;
	int found = 0;
	int targetindex = -1;
	while (found == 0 && left <= right)
	{
		int mid = (left + right) / 2;
		if (list[mid] == target)
		{
			found = 1;
			targetindex = mid;
		}
		else if (list[mid] > target)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}

	}
	return found;
}

void bubble_sort(char *strings[], int size)
{
	int i = 1, i2 = 0;
	char*temp = NULL;
	for (i = 1; i < size; i++)
	{
		for (i2 = 0; i2 < size - i; i2++)
		{
			int x = strcmp(strings[i2], strings[i2 + 1]);
			if (x > 0)
			{
				temp = strings[i2];
				strings[i2] = strings[i2 + 1];
				strings[i2 + 1] = temp;
			}
		}
	}
}

int is_palindrome(char string[], int right)
{
	if (right <= 0)
	{
		return 1;
	}
	if (string[0] == string[right -1])
	{
		
		return is_palindrome(string + 1, right - 2);
		return 1;
	}
	else
	{
		return 0;
	}
}

//DETERIMES IF NUMBERS ARE PRIME
int is_prime(unsigned int n)
{
	int i = 2;
	//for (int i = 2; i <= (n / 2); i++)
	//{
	//	if (n % i == 0) //NOT PRIME
	//	{
	//		return 1;
	//	}
	//	else
	//	{				//PRIME
	//		return n;
	//	}
	//}

	int remainder = n % 2;					//CREDIT TO GITHUB FOR CHECKING IF A NUMBER IS PRIME OR NOT. I AM NOT SURE WHY MY OWN SOLUTION DID NOT WORK. IT IS IN THE COMMENTS ABOVE.

	while (i != n && remainder != 0)
	
	{
		remainder = n % i;
		i++;
	}
	if (i == n)
	{
		return n;
	}
	else
	{
		return 0;
	}



}

//RECURSIVE STEP
int sum_primes(unsigned int n, int sum)
{
	if (n < 2)
	{
		return sum;
	}
	if (is_prime(n))
	{
		sum += n;
	}
	sum_primes(n - 1, sum);

}

void maximum_occurences(char string[], Occurrences occur[], int * i_ptr, char * c_ptr)
{
	int i = 0;
	
	
	//FIND OCCURRENCES
	for(i = 0; string[i] != '\0'; i++)
	{
		int ascii = (int)(string[i]);
		
		occur[ascii].num_occurrences++;

		/*printf("\nNumber of %c: %d", ascii, i);*/
	}
	
	//FIND FREQUENCY
	*i_ptr = i;
	for (i = 0; i < 128; i++)
	{
		occur[i].frequency = ((double)occur[i].num_occurrences) / (double)*i_ptr;
	}
	
	//FIND MOST FREQUENT
	int most = occur[0].num_occurrences;
	for (i = 1; i < 128; i++)
	{
		if (occur[i].num_occurrences > most)
		{
			most = occur[i].num_occurrences;
			*c_ptr = (char)i;
			
		}
	}
	int ascii = (int)*c_ptr;
	printf("\nMost occurred character: %c %d times", *c_ptr, occur[ascii].num_occurrences); //*LETS US GET INDIRECT VARIABLE & GIVES US WHERE THE POINTER IS
	printf("\nFrequency: %lf\n", occur[ascii].frequency);		
	/*printf("\n%d", *i_ptr);	*/																	//PTR BY ITSELF GIVES ADDRESS OF OTHER VARIABLE 


}

int smallest_sum_sequence(int array[], int size)
{
	int i = 0, j = 0, sum = 0, min = 0;
	min = array[0];
	for (i = 0; i < size; i++)
	{
		sum = array[i];
		if (sum < min)
		{
			min = sum;
		}

		for (j = i + 1; j < size; j++)
		{
			sum = array[j] + sum;
			if (sum < min)
			{
				min = sum;
			}
		}
	}
	return min;
}




