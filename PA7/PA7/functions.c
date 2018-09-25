
#include "header.h"

//PRINT INITIAL INTERFACE
int print_interface1(int option)
{/*
	do
	{
		printf("Enter the number to the left of the option you would like to choose.\n\n");
		printf("1. Need a tutorial?\n\n");
		printf("2. Enter your 3 initials\n\n");
		printf("3. Choose a difficulty and do some math\n\n");
		printf("4. Exit program\n\n");
		scanf("%d", &option);
		system("cls");
		if (option == 1)
		{

			print_tutorial();
			system("pause");
			system("cls");
		}
		if (option == 2)
		{

			printf("Enter your initials: ");
			scanf("%s", initials);
			fprintf(output_stats, "\nYour initials: %s", initials);
		}
	} while ((option < 2) || (option > 4));
	return option;*/
}

//PRINTS OPTION 1 OF INITIAL INTERFACE. JUST TUTORIAL FOR USING PROGRAM
void print_tutorial()
{
	printf("You are going to learn how to math!\n");
	printf("Enter the correct answer to a problem to earn some points!\n");
	printf("The harder the problem, the more points you earn.\n");
	printf("Careful, you only get one try per question.\n");
	printf("Earn as many points as you can to be the envy of your classmates!\n");
	printf(" \n");

}

//RUNS EASY MODE
int easy_mode()
{
	
	
	printf("Let's add and subtract! Enter the correct answer to earn one point!\n");
	int turn = 1, digit1 = 0, digit2 = 0, digit3 = 0, digit4 = 0, digit5 = 0, score1 = 0;
	int digit6 = 0, digit7 = 0, digit8 = 0;
	
	
	//EASIER PROBLEMS
	while (turn < 5)
	{
		int answer = 0;
		digit1 = generate_easy_single_digit();
		digit2 = generate_easy_single_digit();
		printf("\nProblem %d: %d + %d = ", turn, digit1, digit2);
		scanf("%d", &answer);
		if (answer == (digit1 + digit2))
		{
			printf("Correct!\n");
			score1++;
		}
		else
		{
			printf("Incorrect! The answer is %d\n", (digit1 + digit2));
		}
		turn++;
	}
	
	//ONE MEDIUM PROBLEM
	int answer = 0;
	digit3 = generate_hard_single_digit();
	digit4 = generate_easy_single_digit();
	digit5 = generate_easy_single_digit();
	printf("\nProblem 5: %d + %d + %d = ", digit3, digit4, digit5);
	scanf("%d", &answer);
	if (answer == (digit3 + digit4 + digit5))
	{
		printf("Correct!\n");
		score1 = score1 + 2;
	}
	else
	{
		printf("Incorrect! The answer is %d\n", (digit3 + digit4 + digit5));
	}
	turn++;

	//HARD PROBLEMS
	while (turn < 11)
	{
		int answer = 0;
		digit6 = generate_hard_single_digit();
		digit7 = generate_hard_single_digit();
		digit8 = generate_easy_single_digit();
		printf("\nProblem %d: %d + %d - %d = ", turn, digit6, digit7, digit8);
		scanf("%d", &answer);
		if (answer == (digit6 + digit7 - digit8))
		{
			printf("Correct!\n");
			score1 = score1 + 3;
		}
		else
		{
			printf("Incorrect! The answer is %d\n", (digit6 + digit7 - digit8));
		}
		turn++;
		
	}
	return score1;
}

//RUNS FAIR MODE
int fair_mode()
{
	int digit1 = 0, digit2 = 0, turn = 1, score2 = 0;

	while (turn < 6)
	{
		int answer = 0;
		digit1 = generate_easy_single_digit();
		digit2 = generate_easy_single_digit();
		printf("\nProblem %d: %d * %d = ", turn, digit1, digit2);
		scanf("%d", &answer);
		if (answer == (digit1 * digit2))
		{
			printf("Correct!\n");
			score2++;
		}
		else
		{
			printf("Incorrect! The answer is %d\n", (digit1 * digit2));
		}
		turn++;
	}
	while (turn < 11)
	{
		int answer = 0;
		digit1 = generate_hard_single_digit();
		digit2 = generate_hard_single_digit();
		printf("\nProblem %d: %d * %d = ", turn, digit1, digit2);
		scanf("%d", &answer);
		if (answer == (digit1 * digit2))
		{
			printf("Correct!\n");
			score2 = score2 + 2;
		}
		else
		{
			printf("Incorrect! The answer is %d\n", (digit1 * digit2));
		}
		turn++;
	}
	return score2;
}

//RUNS INTERMEDIATE MODE
int intermediate_mode()
{
	int digit1 = 0, digit2 = 0, turn = 1, score3 = 0;

	while (turn < 6)
	{
		int num = 0, remainder = 0;
		digit1 = rand() % 4 + 3; //generates 3,4,5,6
		digit2 = rand() % 3 + 1; //generates 1,2,3
		printf("\nProblem %d: %d / %d = ", turn, digit1, digit2);

		scanf("%d", &num);
		printf(" R ");
		scanf("%d", &remainder);
		/*if ((digit2 * 2 == digit1) && num == (digit1/digit2) && remainder == 0)
		{
		printf("Correct!\n");
		}*/
		/*else */if (num == (digit1 / digit2) && remainder == (digit1 - (digit2*(digit1 / digit2))))
		{
			printf("Correct!\n");
			score3 = score3 + 2;
		}
		else
		{
			printf("Incorrect! The answer is %d R %d\n", (digit1 / digit2), (digit1 - (digit2*(digit1 / digit2))));
		}
		turn++;
	}
	
	while (turn < 11)
	{
		int num = 0, remainder = 0, digit1 = 0, digit2 = 0;
		digit1 = rand() % 5 + 5;
		digit2 = rand() % 5 + 1;
		printf("\nProblem %d: %d / %d = ", turn, digit1, digit2);

		scanf(" %d", &num);
		printf(" R ");
		scanf(" %d", &remainder);
		if (num == (digit1 / digit2) && remainder == (digit1 - (digit2*(digit1/digit2))))
		{
			printf("Correct!\n");
			score3 = score3 + 3;
		}
		else
		{
			printf("Incorrect! The answer is %d R %d\n", (digit1 / digit2), (digit1 - (digit2*(digit1 / digit2))));
		}
		turn++;
	}
	return score3;
}


//RUNS HARD MODE
int hard_mode()
{
	int digit1 = 0, digit2 = 0, digit3 =0, turn = 1, score4 = 0;
	printf("Let's test what you really know!\n");
	while (turn < 6)
	{
		int answer = 0, num = 0, remainder = 0, sign = 0;
		digit1 = rand() % 12 - 3; //generates -3,-2,-1,0,1,2,3,4,5,6,7,8
		digit2 = rand() % 6; //generates 0,1,2,3,4,5
		digit3 = rand() % 6 + 1; //generates 1-6
		sign = rand() % 2 + 1; //generates number 1-2 to determine random sign of equation

		if (sign == 1)//ADDS
		{
			printf("\nProblem %d: %d + %d * %d = ", turn, digit1, digit2, digit3);
			scanf("%d", &answer);
			if (answer == digit1 + (digit2 * digit3))
			{
				printf("Correct!\n");
				score4 = score4 + 3;
			}
			else
			{
				printf("Incorrect! The answer is %d\n", (digit1 + (digit2 * digit3)));
			}
		}
		else if (sign == 2)//SUBTRACTS
		{
			printf("\nProblem %d: %d - %d * %d = ", turn, digit1, digit2, digit3);
			scanf("%d", &answer);
			if (answer == digit1 - (digit2 * digit3))
			{
				printf("Correct!\n");
				score4 = score4 + 3;
			}
			else
			{
				printf("Incorrect! The answer is %d", (digit1 - (digit2 * digit3)));
			}

		}
		turn++;
	}
	printf("\nRemember your order of operations!\n");
		while (turn < 11)
		{
			int answer = 0, num = 0, remainder = 0, sign = 0;
			digit1 = rand() % 14 - 4; //generates -4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9
			digit2 = rand() % 5 + 5; //generates 5-9
			digit3 = rand() % 5 + 1; //generates 1-5
			sign = rand() % 2 + 1; //generates number 1-2 to determine random sign of equation

			if (sign == 1)//ADDS
			{
				printf("\nProblem %d: %d + %d / %d = \n", turn, digit1, digit2, digit3);
				scanf(" %d", &num);
				printf(" R ");
				scanf(" %d", &remainder);
				if (num == (digit1 + (digit2 / digit3)) && remainder == (digit2 - (digit3*(digit2 / digit3))))
				{
					printf("Correct!\n");
					score4 = score4 + 4;
				}
				else
				{
					printf("Incorrect! The answer is %d R %d\n", (digit1 + (digit2 / digit3)), (digit2 - (digit3*(digit2 / digit3))));
				}
			}
			else if (sign == 2)//SUBTRACTS
			{
				printf("\nProblem %d: %d - %d / %d = \n", turn, digit1, digit2, digit3);
				scanf(" %d", &num);
				printf(" R ");
				scanf(" %d", &remainder);
				if (num == (digit1 - (digit2 / digit3)) && remainder == (digit2 - (digit3*(digit2 / digit3))))
				{
					printf("Correct!\n");
					score4 = score4 + 4;
				}
				else
				{
					printf("Incorrect! The answer is %d R %d\n", (digit1 - (digit2 / digit3)), (digit2 - (digit3*(digit2 / digit3))));
				}

			}
			turn++;
		}
	
}

//RUNS IMPOSSIBLE MODE
int impossible_mode()
{
	int digit1 = 0, digit2 = 0, digit3 = 0, digit4 = 0, turn = 1, score5 = 0;
	while (turn < 6)
	{
		int answer = 0, num = 0, remainder = 0, sign = 0;
		digit1 = rand() % 70 - 30; //generates -30-40
		digit2 = rand() % 75 - 20;
		digit3 = rand() % 40 - 10; // generates -10-30
		sign = rand() % 2 + 1; //generates number 1-2 to determine random sign of equation
		if (sign == 1)//ADDS
		{
			printf("\nProblem %d: %d + %d * %d = ", turn, digit1, digit2, digit3);
			scanf("%d", &answer);
			if (answer == digit1 + (digit2 * digit3))
			{
				printf("Correct!\n");
				score5 = score5 + 4;
			}
			else
			{
				printf("Incorrect! The answer is %d\n", (digit1 + (digit2 * digit3)));
			}
		}
		else if (sign == 2)//SUBTRACTS
		{
			printf("\nProblem %d: %d - %d * %d = ", turn, digit1, digit2, digit3);
			scanf("%d", &answer);
			if (answer == digit1 - (digit2 * digit3))
			{
				printf("Correct!\n");
				score5 = score5 + 4;
			}
			else

			{
				printf("Incorrect! The answer is %d\n", (digit1 - (digit2 * digit3)));
			}

		}
		turn++;

	}
	while (turn < 11)
		{
			int answer = 0, num = 0, remainder = 0, sign = 0;
			digit1 = rand() % 70 - 30; //generates -30-40
			digit2 = rand() % 75 - 20;
			digit3 = rand() % 30 - -35;// generates -35 - -5
			digit4 = rand() % 50 - 5;  // generates -5 - 45
			sign = rand() % 2 + 1;
			if (sign == 1)//ADDS
			{
				printf("\nProblem %d: %d * %d + %d / %d = \n", turn, digit1, digit2, digit3, digit4);
				scanf(" %d", &num);
				printf(" R ");
				scanf(" %d", &remainder);
				if (num == (digit1 * digit2 + digit3 / digit4) && remainder == (digit3 - (digit4*(digit3 / digit4))))
				{
					printf("Correct!\n");
					score5 = score5 + 5;
				}
				else
				{
					printf("Incorrect! The answer is %d R %d\n", (digit1 * digit2 + digit3 / digit4), (digit3 - (digit4*(digit3 / digit4))));
				}
			}
			else if (sign == 2)//SUBTRACTS
			{
				printf("\nProblem %d: %d * %d - %d / %d = \n", turn, digit1, digit2, digit3, digit4);
				scanf(" %d", &num);
				printf(" R ");
				scanf(" %d", &remainder);
				if (num == (digit1 * digit2 - digit3 / digit4) && remainder == (digit3 - (digit4*(digit3 / digit4))))
				{
					printf("Correct!\n");
					score5 = score5 + 5;
				}
				else
				{
					printf("Incorrect! The answer is %d R %d\n", (digit1 * digit2 - digit3 / digit4), (digit3 - (digit4*(digit3 / digit4))));
				}

			}
			turn++;
		}
	return score5;
	}

//GENERATE SINGLE DIGIT 0-5
int generate_easy_single_digit()
{
	int digit = 0;
	digit = rand() % 5;
	return digit;
}

//GENERATE SINGLE DIGIT 5-9
int generate_hard_single_digit()
{
	int digit = 0;
	digit = rand() % 5 + 5;
	return digit;
}