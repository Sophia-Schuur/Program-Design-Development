/* Sophia Schuur
PA5
10/11/2016
This program plays a game of yahtzee*/


#include "header.h"

int main(void)
{
	srand((unsigned int)time(NULL));


	int dice[5] = { 0 }, score[14] = { 0 }, score2[14] = { 0 }, dice_values_count[6] = { 0 }, is_used2[14] = { 0 },
		is_used[14] = { 0 }, option = 0, selection = 0, total = 0, reroll = 0, die_value = 0, sum_score = 0, check = 0, sum_score2 = 0;
	char yes_or_no_reroll = '\0', play_again = 'y';

	
	

	do
	{
		printf("\nLets play Yahtzee! Select an option to start! Just input 1, 2 or 3!\n\n");
		printf("1. Print game rules!\n\n");
		printf("2. Play the game!\n\n");
		printf("3. Exit game\n\n");
		scanf("%d", &option);
		system("cls");
		if (option == 1)
		{

				print_game_rules();
				system("pause");
				system("cls");
		}
	} 
	while ((option < 2) || (option > 3));
	
	
	
	
	switch (option)
	{
	case RULES: // print_game_rules ()

		print_game_rules();
		system("pause");
		system("cls");
		break;

	case PLAY:
		while (play_again == 'y')
		{


			//ROUND 1
			roll_dice(dice, 5);
			print_dice(dice, 5);

			reroll_dice_function(dice, die_value);    // IF YOU SAY YOU DONT WANNA REROLL IT IT ASKS YOU IF YOU WANT TO TWICE. COULDNT FIGURE OUT HOW TO FIX BUT IT STILL WORKS.
			do {
				reroll_dice_function(dice, die_value);

			} while (yes_or_no_reroll == 'y');


			selection = get_selection(is_used, dice);
			process(selection, is_used, score, dice, dice_values_count);

			sum_score = 0;
			for (int z = 0; z < 14; z++)
			{
				sum_score += score[z];
			}
			printf("Your total score is %d\n", sum_score);

			system("pause");
			system("cls");



			//ROUND 2
			roll_dice(dice, 5);
			print_dice(dice, 5);
			reroll_dice_function(dice, die_value);
			do {
				reroll_dice_function(dice, die_value);

			} while (yes_or_no_reroll == 'y');


			selection = get_selection(is_used, dice);
			process(selection, is_used, score, dice, dice_values_count);


			sum_score = 0;
			for (int z = 0; z < 13; z++)
			{
				sum_score += score[z];
			}
			printf("Your total score is %d\n", sum_score);


			system("pause");
			system("cls");

			//ROUND 3

			roll_dice(dice, 5);
			print_dice(dice, 5);

			reroll_dice_function(dice, die_value);
			do {
				reroll_dice_function(dice, die_value);

			} while (yes_or_no_reroll == 'y');


			selection = get_selection(is_used, dice);
			process(selection, is_used, score, dice, dice_values_count);

			sum_score = 0;
			for (int z = 0; z < 14; z++)
			{
				sum_score += score[z];
			}
			printf("Your total score is %d\n", sum_score);

			system("pause");
			system("cls");


			//////ROUND 4

			roll_dice(dice, 5);
			print_dice(dice, 5);

			reroll_dice_function(dice, die_value);
			do {
				reroll_dice_function(dice, die_value);

			} while (yes_or_no_reroll == 'y');


			selection = get_selection(is_used, dice);
			process(selection, is_used, score, dice, dice_values_count);

			sum_score = 0;
			for (int z = 0; z < 14; z++)
			{
				sum_score += score[z];
			}
			printf("Your total score is %d\n", sum_score);

			system("pause");
			system("cls");



			//////ROUND 5

			roll_dice(dice, 5);
			print_dice(dice, 5);

			reroll_dice_function(dice, die_value);
			do {
				reroll_dice_function(dice, die_value);

			} while (yes_or_no_reroll == 'y');


			selection = get_selection(is_used, dice);
			process(selection, is_used, score, dice, dice_values_count);

			sum_score = 0;
			for (int z = 0; z < 14; z++)
			{
				sum_score += score[z];
			}
			printf("Your total score is %d\n", sum_score);

			system("pause");
			system("cls");


			//////ROUND 6


			roll_dice(dice, 5);
			print_dice(dice, 5);

			reroll_dice_function(dice, die_value);
			do {
				reroll_dice_function(dice, die_value);

			} while (yes_or_no_reroll == 'y');


			selection = get_selection(is_used, dice);
			process(selection, is_used, score, dice, dice_values_count);

			sum_score = 0;
			for (int z = 0; z < 14; z++)
			{
				sum_score += score[z];
			}
			printf("Your total score is %d\n", sum_score);

			system("pause");
			system("cls");

			//////ROUND 7

			roll_dice(dice, 5);
			print_dice(dice, 5);

			reroll_dice_function(dice, die_value);
			do {
				reroll_dice_function(dice, die_value);

			} while (yes_or_no_reroll == 'y');


			selection = get_selection(is_used, dice);
			process(selection, is_used, score, dice, dice_values_count);

			sum_score = 0;
			for (int z = 0; z < 14; z++)
			{
				sum_score += score[z];
			}
			printf("Your total score is %d\n", sum_score);

			system("pause");
			system("cls");


			//////ROUND 8

			roll_dice(dice, 5);
			print_dice(dice, 5);

			reroll_dice_function(dice, die_value);
			do {
				reroll_dice_function(dice, die_value);

			} while (yes_or_no_reroll == 'y');


			selection = get_selection(is_used, dice);
			process(selection, is_used, score, dice, dice_values_count);

			sum_score = 0;
			for (int z = 0; z < 14; z++)
			{
				sum_score += score[z];
			}
			printf("Your total score is %d\n", sum_score);

			system("pause");
			system("cls");


			//////ROUND 9

			roll_dice(dice, 5);
			print_dice(dice, 5);

			reroll_dice_function(dice, die_value);
			do {
				reroll_dice_function(dice, die_value);

			} while (yes_or_no_reroll == 'y');


			selection = get_selection(is_used, dice);
			process(selection, is_used, score, dice, dice_values_count);

			sum_score = 0;
			for (int z = 0; z < 14; z++)
			{
				sum_score += score[z];
			}
			printf("Your total score is %d\n", sum_score);

			system("pause");
			system("cls");

			//////ROUND 10


			roll_dice(dice, 5);
			print_dice(dice, 5);

			reroll_dice_function(dice, die_value);
			do {
				reroll_dice_function(dice, die_value);

			} while (yes_or_no_reroll == 'y');


			selection = get_selection(is_used, dice);
			process(selection, is_used, score, dice, dice_values_count);

			sum_score = 0;
			for (int z = 0; z < 14; z++)
			{
				sum_score += score[z];
			}
			printf("Your total score is %d\n", sum_score);

			system("pause");
			system("cls");

			//////ROUND 11

			roll_dice(dice, 5);
			print_dice(dice, 5);

			reroll_dice_function(dice, die_value);
			do {
				reroll_dice_function(dice, die_value);

			} while (yes_or_no_reroll == 'y');


			selection = get_selection(is_used, dice);
			process(selection, is_used, score, dice, dice_values_count);

			sum_score = 0;
			for (int z = 0; z < 14; z++)
			{
				sum_score += score[z];
			}
			printf("Your total score is %d\n", sum_score);

			system("pause");
			system("cls");


			//////ROUND 12

			roll_dice(dice, 5);
			print_dice(dice, 5);

			reroll_dice_function(dice, die_value);
			do {
				reroll_dice_function(dice, die_value);

			} while (yes_or_no_reroll == 'y');


			selection = get_selection(is_used, dice);
			process(selection, is_used, score, dice, dice_values_count);

			sum_score = 0;
			for (int z = 0; z < 14; z++)
			{
				sum_score += score[z];
			}
			printf("Your total score is %d\n", sum_score);

			system("pause");
			system("cls");


			//////ROUND 13

			roll_dice(dice, 5);
			print_dice(dice, 5);

			reroll_dice_function(dice, die_value);
			do {
				reroll_dice_function(dice, die_value);

			} while (yes_or_no_reroll == 'y');


			selection = get_selection(is_used, dice);
			process(selection, is_used, score, dice, dice_values_count);

			sum_score = 0;
			for (int z = 0; z < 14; z++)
			{
				sum_score += score[z];
			}
			printf("Your total score is %d\n", sum_score);

			system("pause");
			system("cls");

			//COUNT SCORE
			int upper_section = 0, t = 0;

			for (int t = 7; t < 13; t++)
			{
				upper_section += score[t];
				if (upper_section >= 63)
				{
					sum_score = sum_score + 35;
					printf("Player 1 earned more than 63 points in upper section. Final Score is: %d\n", sum_score);

				}



			}
			printf("Player 1 score: %d\n", sum_score);
			printf("Switch to player 2 now!\n");
			system("pause");
			system("cls");


			//PLAYER 2 START


						//ROUND 1
			roll_dice(dice, 5);
			print_dice(dice, 5);

			reroll_dice_function(dice, die_value);    // IF YOU SAY YOU DONT WANNA REROLL IT IT ASKS YOU IF YOU WANT TO TWICE. COULDNT FIGURE OUT HOW TO FIX BUT IT STILL WORKS.
			do {
				reroll_dice_function(dice, die_value);

			} while (yes_or_no_reroll == 'y');


			selection = get_selection2(is_used2, dice);
			process(selection, is_used2, score2, dice, dice_values_count);

			sum_score2 = 0;
			for (int z = 0; z < 14; z++)
			{
				sum_score2 += score2[z];
			}
			printf("Your total score is %d\n", sum_score2);

			system("pause");
			system("cls");



			//ROUND 2
			roll_dice(dice, 5);
			print_dice(dice, 5);
			reroll_dice_function(dice, die_value);
			do {
				reroll_dice_function(dice, die_value);

			} while (yes_or_no_reroll == 'y');


			selection = get_selection2(is_used2, dice);
			process2(selection, is_used2, score2, dice, dice_values_count);


			sum_score2 = 0;
			for (int z = 0; z < 13; z++)
			{
				sum_score2 += score2[z];
			}
			printf("Your total score is %d\n", sum_score2);


			system("pause");
			system("cls");

			//ROUND 3

			roll_dice(dice, 5);
			print_dice(dice, 5);

			reroll_dice_function(dice, die_value);
			do {
				reroll_dice_function(dice, die_value);

			} while (yes_or_no_reroll == 'y');


			selection = get_selection2(is_used2, dice);
			process2(selection, is_used2, score2, dice, dice_values_count);

			sum_score2 = 0;
			for (int z = 0; z < 14; z++)
			{
				sum_score2 += score2[z];
			}
			printf("Your total score is %d\n", sum_score2);

			system("pause");
			system("cls");


			////ROUND 4

			roll_dice(dice, 5);
			print_dice(dice, 5);

			reroll_dice_function(dice, die_value);
			do {
				reroll_dice_function(dice, die_value);

			} while (yes_or_no_reroll == 'y');


			selection = get_selection2(is_used2, dice);
			process2(selection, is_used2, score2, dice, dice_values_count);

			sum_score2 = 0;
			for (int z = 0; z < 14; z++)
			{
				sum_score2 += score2[z];
			}
			printf("Your total score is %d\n", sum_score2);

			system("pause");
			system("cls");



			////ROUND 5

			roll_dice(dice, 5);
			print_dice(dice, 5);

			reroll_dice_function(dice, die_value);
			do {
				reroll_dice_function(dice, die_value);

			} while (yes_or_no_reroll == 'y');


			selection = get_selection2(is_used2, dice);
			process2(selection, is_used2, score2, dice, dice_values_count);

			sum_score2 = 0;
			for (int z = 0; z < 14; z++)
			{
				sum_score2 += score2[z];
			}
			printf("Your total score is %d\n", sum_score2);

			system("pause");
			system("cls");


			////ROUND 6


			roll_dice(dice, 5);
			print_dice(dice, 5);

			reroll_dice_function(dice, die_value);
			do {
				reroll_dice_function(dice, die_value);

			} while (yes_or_no_reroll == 'y');


			selection = get_selection2(is_used2, dice);
			process2(selection, is_used2, score2, dice, dice_values_count);

			sum_score2 = 0;
			for (int z = 0; z < 14; z++)
			{
				sum_score2 += score2[z];
			}
			printf("Your total score is %d\n", sum_score2);

			system("pause");
			system("cls");

			////ROUND 7

			roll_dice(dice, 5);
			print_dice(dice, 5);

			reroll_dice_function(dice, die_value);
			do {
				reroll_dice_function(dice, die_value);

			} while (yes_or_no_reroll == 'y');


			selection = get_selection2(is_used2, dice);
			process2(selection, is_used2, score2, dice, dice_values_count);

			sum_score2 = 0;
			for (int z = 0; z < 14; z++)
			{
				sum_score2 += score2[z];
			}
			printf("Your total score is %d\n", sum_score2);

			system("pause");
			system("cls");


			////ROUND 8

			roll_dice(dice, 5);
			print_dice(dice, 5);

			reroll_dice_function(dice, die_value);
			do {
				reroll_dice_function(dice, die_value);

			} while (yes_or_no_reroll == 'y');


			selection = get_selection2(is_used2, dice);
			process2(selection, is_used2, score2, dice, dice_values_count);

			sum_score2 = 0;
			for (int z = 0; z < 14; z++)
			{
				sum_score2 += score2[z];
			}
			printf("Your total score is %d\n", sum_score2);

			system("pause");
			system("cls");


			////ROUND 9

			roll_dice(dice, 5);
			print_dice(dice, 5);

			reroll_dice_function(dice, die_value);
			do {
				reroll_dice_function(dice, die_value);

			} while (yes_or_no_reroll == 'y');


			selection = get_selection2(is_used2, dice);
			process2(selection, is_used2, score2, dice, dice_values_count);

			sum_score2 = 0;
			for (int z = 0; z < 14; z++)
			{
				sum_score2 += score2[z];
			}
			printf("Your total score is %d\n", sum_score2);

			system("pause");
			system("cls");

			////ROUND 10


			roll_dice(dice, 5);
			print_dice(dice, 5);

			reroll_dice_function(dice, die_value);
			do {
				reroll_dice_function(dice, die_value);

			} while (yes_or_no_reroll == 'y');


			selection = get_selection2(is_used2, dice);
			process2(selection, is_used2, score2, dice, dice_values_count);

			sum_score2 = 0;
			for (int z = 0; z < 14; z++)
			{
				sum_score2 += score2[z];
			}
			printf("Your total score is %d\n", sum_score2);

			system("pause");
			system("cls");

			////ROUND 11

			roll_dice(dice, 5);
			print_dice(dice, 5);

			reroll_dice_function(dice, die_value);
			do {
				reroll_dice_function(dice, die_value);

			} while (yes_or_no_reroll == 'y');


			selection = get_selection2(is_used2, dice);
			process2(selection, is_used2, score2, dice, dice_values_count);

			sum_score2 = 0;
			for (int z = 0; z < 14; z++)
			{
				sum_score2 += score2[z];
			}
			printf("Your total score is %d\n", sum_score2);

			system("pause");
			system("cls");


			////ROUND 12

			roll_dice(dice, 5);
			print_dice(dice, 5);

			reroll_dice_function(dice, die_value);
			do {
				reroll_dice_function(dice, die_value);

			} while (yes_or_no_reroll == 'y');


			selection = get_selection2(is_used2, dice);
			process2(selection, is_used2, score2, dice, dice_values_count);

			sum_score2 = 0;
			for (int z = 0; z < 14; z++)
			{
				sum_score2 += score2[z];
			}
			printf("Your total score is %d\n", sum_score2);

			system("pause");
			system("cls");


			////ROUND 13

			roll_dice(dice, 5);
			print_dice(dice, 5);

			reroll_dice_function(dice, die_value);
			do {
				reroll_dice_function(dice, die_value);

			} while (yes_or_no_reroll == 'y');


			selection = get_selection2(is_used2, dice);
			process2(selection, is_used2, score2, dice, dice_values_count);

			sum_score2 = 0;
			for (int z = 0; z < 14; z++)
			{
				sum_score2 += score2[z];
			}
			printf("Your total score is %d\n", sum_score2);

			system("pause");
			system("cls");

			//COUNT SCORE
			int upper_section2 = 0, v = 0;

			for (int v = 7; v < 13; v++)
			{
				upper_section2 += score2[v];
				if (upper_section2 >= 63)
				{
					sum_score2 = sum_score2 + 35;
					printf("Player 2 earned more than 63 points in upper section. Final Score is: %d\n", sum_score2);

				}



			}


			printf("Player 1 score: %d\n", sum_score);

			printf("Player 2 score: %d\n", sum_score2);



			if (sum_score > sum_score2)
			{
				printf("Player 1 wins!\n");
			}
			else if (sum_score < sum_score2)
			{
				printf("Player 2 wins!\n");
			}
			else
			{
				printf("Tie!\n");
			}



			printf("\nWould you like to play again? Enter y to play again. Enter n to exit.\n");
			scanf(" %c", &play_again);
			system("cls");


		}
		return 0;

		
		
		
		break;


	case EXIT:
		printf("Thanks for playing!\n");
		return 0;


	}
	
	return 0;
}