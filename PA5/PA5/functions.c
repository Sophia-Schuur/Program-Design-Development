#include "header.h"


void print_game_rules(void)
{
	printf("The scorecard used for Yahtzee is composed of two sections. A upper section and a lower section.\n");
	printf("A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections. \n");
	printf("The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box.\n");
	printf("If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12. \n");
	printf("Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds.\n");
	printf("If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are added \n");
	printf("to the players overall score as a bonus. The lower section contains a number of poker like combinations.\n");
}

void roll_dice(int dice[], int size)
{
	int index = 0;

	for (index = 0; index < size; ++index)
	{
		dice[index] = rand() % 6 + 1;
	}
}


int reroll_die(void)
{
	int die_value = 0;

	die_value = rand() % 6 + 1;

	return die_value;
}




int reroll_dice_function(int dice[], int die_value)
{

	int index = 0, num_dice_reroll = 0, reroll_index = 0, reroll = 0;
	char yes_or_no_reroll = '\0';
	do
	{
		printf("Do you want to reroll the dice? Enter y for yes or n for no.\n\n");
		scanf(" %c", &yes_or_no_reroll);



		if (yes_or_no_reroll == 'n')
		{
			return 0; //lEAVES
		}


		if (yes_or_no_reroll == 'y')
		{


			while (reroll < 3)
			{
				printf("How many dice do you want to reroll?\n");
				scanf("%d", &num_dice_reroll);

				if (num_dice_reroll == 5)
				{
					roll_dice(dice, 5);
					print_dice(dice, 5);

					return 0;
				}
				else
				{
					for (int x = 0; x < num_dice_reroll; ++reroll, ++x)
					{
						printf("Which dice do you want to reroll? Enter one index - not the face value.\n\n");
						scanf("%d", &reroll_index);
						dice[reroll_index - 1] = reroll_die();
						print_dice(dice, 5);

						

					}
				}return 0;
			}
		}
	} while (yes_or_no_reroll == 'y' && yes_or_no_reroll == 'n');
}



// precondition: dice_ptr must be referring to contiguous memory
void print_dice(int *dice_ptr, int size)
{
	int index = 0;

	for (index = 0; index < size; ++index)
	{
		printf("Die %d: %d\n", index + 1, *(dice_ptr + index));
	}
}







void print_13_menu(void)
{
	printf("\nEnter the number of the scoring you would like to use for this roll.\nEnter a number from 1-13.\n\n");
	printf("	TYPE				COMBINATION			SCORE\n");
	printf("1.	Ones 				Any combination 	The sum of dice with the number 1\n");
	printf("2.	Twos 				Any combination 	The sum of dice with the number 2\n");
	printf("3.	Threes 				Any combination 	The sum of dice with the number 3\n");
	printf("4.	Fours 				Any combination		The sum of dice with the number 4\n");
	printf("5.	Fives 				Any combination 	The sum of dice with the number 5\n");
	printf("6.	Sixes 				Any combination 	The sum of dice with the number 6\n");
	printf("7.	Three-Of-A-Kind		At least three dice the same 	Sum of all dice \n");
	printf("8.	Four-Of-A-Kind 		At least four dice the same 	Sum of all dice\n");
	printf("9.	Full House 		Three of one number and two of another	25\n");
	printf("10.	Small Straight 		Four sequential dice		30\n");
	printf("11.	Large Straight 		Five sequential dice		40\n");
	printf("12.	Yahtzee 		All five dice the same		50\n");
	printf("13.	Chance 			Any combination 		Sum of all dice\n\n\n");
	

}


int get_selection(int is_used[], int dice[])
{
	print_13_menu();
	int is_option = 0, selection = 0, check = 0;
	while (is_option != 1)
	{
		scanf("%d", &selection);
		if (selection > 13 || selection < 1)
		{
			is_option = 0;
			printf("Not a valid option! Pick again.\n");
		}
		else
		{
			is_option = 1;
		}
	}

	check = check_is_used(selection, is_used, dice);
	while (check == 1)
	{
		selection = get_selection(is_used, dice);
		check = check_is_used(selection, is_used, dice);
	}

	return selection;

}


int get_selection2(int is_used2[], int dice[])
{
	print_13_menu();
	int is_option = 0, selection = 0, check = 0;
	while (is_option != 1)
	{
		scanf("%d", &selection);
		if (selection > 13 || selection < 1)
		{
			is_option = 0;
			printf("Not a valid option! Pick again.\n");
		}
		else
		{
			is_option = 1;
		}
	}

	check = check_is_used2(selection, is_used2, dice);
	while (check == 1)
	{
		selection = get_selection2(is_used2, dice);
		check = check_is_used2(selection, is_used2, dice);
	}

	return selection;

}



int check_is_used(int selection, int is_used[], int dice[])
{
	if (is_used[selection] == 1)

	{
		printf("You've already used this! Pick another selection.\n");
		system("pause");
		system("cls");
		print_dice(dice, 5);
		return 1;
		
	}
	return 0;
}



int check_is_used2(int selection, int is_used2[], int dice[])
{
	if (is_used2[selection] == 1)

	{
		printf("You've already used this! Pick another selection.\n");
		system("pause");
		system("cls");
		print_dice(dice, 5);
		return 1;

	}
	return 0;
}

//use every time after reroll
void count_values(int dice[], int dice_values_count[])
{
	int index = 0;
	for (int i = 0; i < 5; ++i)
	{
		dice_values_count[dice[index]- 1]++;

	}
	

}



int sum_ones(int dice[])
{
	int i = 0, sum = 0;
	for (i = 0; i < 5; i++)
	{
		if (dice[i] == 1)
		{
			sum += dice[i];
			
		}
	}
	return sum;
}

int sum_twos(int dice[])
{
	int i = 0, sum = 0;
	for (i = 0; i < 5; i++)
	{
		if (dice[i] == 2)
		{
			sum += dice[i];
		
		}
	}
	return sum;
}


int sum_threes(int dice[])
{
	int i = 0, sum = 0;
	for (i = 0; i < 5; i++)
	{
		if (dice[i] == 3)
		{
			sum += dice[i];
			
		}
	}
	return sum;
}

int sum_fours(int dice[])
{
	int i = 0, sum = 0;
	for (i = 0; i < 5; i++)
	{
		if (dice[i] == 4)
		{
			sum += dice[i];
			
		}
	}
	return sum;
}

int sum_fives(int dice[])
{
	int i = 0, sum = 0;
	for (i = 0; i < 5; i++)
	{
		if (dice[i] == 5)
		{
			sum += dice[i];
			
		}
	}
	return sum;
}


int sum_sixes(int dice[])
{
	int i = 0, sum = 0;
	for (i = 0; i < 5; i++)
	{
		if (dice[i] == 6)
		{
			sum += dice[i];
			
			
		}
	}
	return sum;
}

int sum_dice(int dice[], int sum)
{
	
	for (int i = 0; i < 6; i++)
	{
		sum += dice[i];
	}
	return sum;
}


int three_of_a_kind(int dice_values_count[], int dice[], int sum)  
{
	
	int index = 0;
	for (index = 0; index < 5; index++)
	{
		if (dice_values_count[index] >= 3)
		{
			sum = sum_dice(dice, sum);
			
		}
		else
		{
			sum = 0;
		}
	
	}
	
	return sum;
	
	
}


int four_of_a_kind(int dice_values_count[], int dice[])
{
	int sum = 0;
	for (int index = 0; index < 6; index++)
	{
		if (dice[index] >= 4)
		{
			sum += dice[index];
			
		}
		else
		{
			sum = 0;
		}
	}
	return sum;
	printf("You scored a %d\n", sum);
}


//case 10
int small_straight(int dice_values_count[], int dice[])
{
	int count = 0;
	int sum = 0;
	for (int index = 0; index < 6; ++index)
	{
		if (dice_values_count[index] >= 1)
		{
			count++;
		}
		else
		{
			count = 0;
		}
		if (count == 4)
		{
			printf("You rolled a small straight!\n");
			sum = 30;
		}
		else
		{
			sum = 0;
		}
		return sum;
		
	}
}


int large_straight(int dice_values_count[], int dice[])
{
	int count = 0;
	int sum = 0;
	for (int index = 0; index < 6; ++index)
	{
		if (dice_values_count[index] >= 1)
		{
			count++;
		}
		else
		{
			count = 0;
		}
		if (count == 5)
		{
			printf("You rolled a large straight!\n");
			sum = 40;
		}
		else
		{
			sum = 0;
		}
	
		return sum;
	}
}



int full_house(int dice_values_count[], int dice[])
{
	int two = 0, three = 0, index = 0;
	int sum = 0;
	for (index = 0; index < 6; ++index)
	{
		if (dice_values_count[index] == 3)
		{
			three = 1;
		}
		else if (dice_values_count[index] == 2)
		{
			two = 1;
		}
	}
	if (two == 1 && three == 1)
	{
		sum = 25;
	}
	else
	{
		sum = 0;
	}

	return sum;
}

int yahtzee(int dice_values_count[], int dice[])
{
	int sum = 0;
	for (int index = 0; index < 6; index++)

	{
		if (dice_values_count[index] == 5)
		{
			sum = 50;
			
		
		}
		else
		{
			
			sum = 0;
		}
	}return sum;
}

int chance(int dice[], int sum)
{
	
	for (int index = 0; index < 6; index++)
	{
		sum += dice[index];
		
	}
	return sum;
}


void update_score(int score[], int selection, int total, int is_used[]) //just updates. must calculate in the 13 other functions
{
	score[selection] = total;
	is_used[selection] = 1;
}

void update_score2(int score2[], int selection, int total, int is_used[]) //just updates. must calculate in the 13 other functions
{
	score2[selection] = total;
	is_used[selection] = 1;
}



void process(int selection, int is_used[], int score[], int dice[], int dice_values_count[])
{
	int sum = 0, total = 0;
	
	
	switch (selection)
	{
	case 1:
		check_is_used(selection, is_used, dice);
		sum = sum_ones(dice);
		update_score(score, selection, sum, is_used);
		printf("You scored a %d\n", sum);
		

		break;

	case 2:
		check_is_used(selection, is_used, dice);
		sum = sum_twos(dice);
		
		update_score(score, selection, sum, is_used);
		printf("You scored a %d\n", sum);
		

		break;

	case 3:
		check_is_used(selection, is_used, dice);
		sum = sum_threes(dice);
		
		update_score(score, selection, sum, is_used);
		printf("You scored a %d\n", sum);
		

		break;

	case 4:
		check_is_used(selection, is_used, dice);
		sum = sum_fours(dice);
		
		update_score(score, selection, sum, is_used);
		printf("You scored a %d\n", sum);
		

		break;

	case 5:
		check_is_used(selection, is_used, dice);
		sum = sum_fives(dice);
		
		update_score(score, selection, sum, is_used);
		printf("You scored a %d\n", sum);

		break;


	case 6:
		check_is_used(selection, is_used, dice);
		sum = sum_sixes(dice);
		
		update_score(score, selection, sum, is_used);
		printf("You scored a %d\n", sum);

		break;


	// 3 of a kind
	case 7:
		check_is_used(selection, is_used, dice);
		count_values(dice, dice_values_count);
		sum = three_of_a_kind(dice_values_count, dice, sum);

		update_score(score, selection, sum, is_used);
		
		printf("You scored a %d\n", sum);


		break;
	//4 of a kind
	case 8:
		check_is_used(selection, is_used, dice);
		count_values(dice, dice_values_count);
		sum = four_of_a_kind(dice_values_count, dice);
		
		update_score(score, selection, sum, is_used);
		printf("You scored a %d\n", sum);

		break;


	// full house
	case 9:
		check_is_used(selection, is_used, dice);
		count_values(dice, dice_values_count);
		sum = full_house(dice_values_count, dice);
	
		update_score(score, selection, sum, is_used);
		printf("You scored a %d\n", sum);

		break;
	
	
	// small straight
	case 10:
		check_is_used(selection, is_used, dice);
		count_values(dice, dice_values_count);
		sum = small_straight(dice_values_count, dice);
	
		update_score(score, selection, sum, is_used);
		printf("You scored a %d\n", sum);

	case 11:
		check_is_used(selection, is_used, dice);
		count_values(dice, dice_values_count);
		sum = large_straight(dice_values_count, dice);
		
		update_score(score, selection, sum, is_used);
		printf("You scored a %d\n", sum);


		break;

	case 12: 
		check_is_used(selection, is_used, dice);
		count_values(dice, dice_values_count);
		sum = yahtzee(dice_values_count, dice);
		
		update_score(score, selection, sum, is_used);
		printf("You scored a %d\n", sum);

		break;

	case 13:
		check_is_used(selection, is_used, dice);
		sum = chance(dice, sum);
	
		update_score(score, selection, sum, is_used);
		printf("You scored a %d\n", sum);

		break;


	}

}


void process2(int selection, int is_used2[], int score2[], int dice[], int dice_values_count[])
{
	int sum = 0, total = 0;


	switch (selection)
	{
	case 1:
		check_is_used2(selection, is_used2, dice);
		sum = sum_ones(dice);
		update_score2(score2, selection, sum, is_used2);
		printf("You scored a %d\n", sum);


		break;

	case 2:
		check_is_used2(selection, is_used2, dice);
		sum = sum_twos(dice);

		update_score2(score2, selection, sum, is_used2);
		printf("You scored a %d\n", sum);


		break;

	case 3:
		check_is_used2(selection, is_used2, dice);
		sum = sum_threes(dice);

		update_score2(score2, selection, sum, is_used2);
		printf("You scored a %d\n", sum);


		break;

	case 4:
		check_is_used2(selection, is_used2, dice);
		sum = sum_fours(dice);

		update_score2(score2, selection, sum, is_used2);
		printf("You scored a %d\n", sum);


		break;

	case 5:
		check_is_used2(selection, is_used2, dice);
		sum = sum_fives(dice);

		update_score2(score2, selection, sum, is_used2);
		printf("You scored a %d\n", sum);

		break;


	case 6:
		check_is_used2(selection, is_used2, dice);
		sum = sum_sixes(dice);

		update_score2(score2, selection, sum, is_used2);
		printf("You scored a %d\n", sum);

		break;


		// 3 of a kind
	case 7:
		check_is_used2(selection, is_used2, dice);
		count_values(dice, dice_values_count);
		sum = three_of_a_kind(dice_values_count, dice, sum);

		update_score2(score2, selection, sum, is_used2);

		printf("You scored a %d\n", sum);


		break;
		//4 of a kind
	case 8:
		check_is_used2(selection, is_used2, dice);
		count_values(dice, dice_values_count);
		sum = four_of_a_kind(dice_values_count, dice);

		update_score2(score2, selection, sum, is_used2);
		printf("You scored a %d\n", sum);

		break;


		// full house
	case 9:
		check_is_used2(selection, is_used2, dice);
		count_values(dice, dice_values_count);
		sum = full_house(dice_values_count, dice);

		update_score2(score2, selection, sum, is_used2);
		printf("You scored a %d\n", sum);

		break;


		// small straight
		//idk why this one says it is already used. it seems to work anyways.
	case 10:
		check_is_used2(selection, is_used2, dice);
		count_values(dice, dice_values_count);
		sum = small_straight(dice_values_count, dice);

		update_score2(score2, selection, sum, is_used2);
		printf("You scored a %d\n", sum);

	case 11:
		check_is_used2(selection, is_used2, dice);
		count_values(dice, dice_values_count);
		sum = large_straight(dice_values_count, dice);

		update_score2(score2, selection, sum, is_used2);
		printf("You scored a %d\n", sum);


		break;

	case 12:
		check_is_used2(selection, is_used2, dice);
		count_values(dice, dice_values_count);
		sum = yahtzee(dice_values_count, dice);

		update_score2(score2, selection, sum, is_used2);
		printf("You scored a %d\n", sum);

		break;

	case 13:
		check_is_used2(selection, is_used2, dice);
		count_values(dice, dice_values_count);
		sum = chance(dice_values_count, dice, sum);

		update_score2(score2, selection, sum, is_used2);
		printf("You scored a %d\n", sum);

		break;


	}

}
