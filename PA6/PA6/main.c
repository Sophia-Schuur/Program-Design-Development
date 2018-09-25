//Sophia Schuur
//CptS 121
//PA6
//10/26/2016
//This program simulates battleship
//no AI used


#include "header.h"

int main(void)
{
	srand((unsigned int)time(NULL));
	

	char p1_board[10][10] = { { '\0', '~' },{ '~' } }, p2_board[10][10] = { '\0' }, placement = '\0', choice = '\0';
	int option = 0, row = 0, col = 0;
	FILE *output_stats = NULL;
	output_stats = fopen("output_stats.txt", "w");

	
	PIECES player1 = { 5, 4, 3, 3, 2, 17 };
	PIECES player2 = { 5, 4, 3, 3, 2, 17 };

	STATS stats1 = { 0, 0, 0, 0 };
	STATS stats2 = { 0, 0, 0, 0 };
	

	do
	{
		printf("\nLets play Battleship! Select an option to start! Just input 1, 2 or 3!\n\n");
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
	} while ((option < 2) || (option > 3));
	
	
	switch (option)
	{
	case RULES:
		print_game_rules();
		system("pause");
		system("cls");
		break;
		//p1 - player
		//p2 - computer
		
	case PLAY:
		init_board(p1_board, 10, 10);
		init_board(p2_board, 10, 10); // set each cell in the 2-D array to the water '~' symbol
		
		putchar('\n');
		print_board(p1_board, 10, 10, 1);
		putchar('\n');
		print_board(p2_board, 10, 10, 2);
		


		printf("Do you want to place your ships manually? Enter y for yes and n for no.\n");
		scanf(" %c", &choice);
		system("cls");
		
		//MANUALLY PLACE SHIPS
		if (choice == 'y')
		{
			place_ships(p1_board, 10, 10, 1);
		}
		//RANDOMLY PLACE SHIPS
		else
		{
			random_board(p1_board, 1);
		}
		

		//randomly place computer ships 
		random_board(p2_board, 2);
		
		

		//this condition should be based on the lives remaining of the player or the computer

		while (player1.player_hp > 0 && player2.player_hp > 0)
		{
			//GET COORDINATE
			
			get_coordinate(p1_board, p2_board, &player1, &stats1, output_stats, PLAYER);
			get_computer_coordinate(p1_board, p2_board, &player2, &stats2, output_stats, COMPUTER);


			
			system("pause");
			system("cls");
			
		}
		



		//DETERMINES WINNER
		if (player1.player_hp < player2.player_hp) //THIS SEEMS ILLOGICAL BUT WHEN I TESTED IT OUT, IT CORRECTLY DISPLAYED THE WINNER WHEN 
													//I GOT MORE HITS THAN THE COMPUTER. 
		{											//THIS CODE IMPLIES IT SHOULD BE THE OTHER WAY AROUND. WORKS ANYWAY
			printf("Player 1 has sunk all ships! You win!\n");
			fprintf(output_stats, "Player 1 wins!\n");
		}
		else
		{
			printf("The computer wins!\n");
			fprintf(output_stats, "The computer wins!\n");
		}
		
		//OUTPUT STATS TO FILE

		//HITS MISS RATIO SHOWS UP AS VERY LARGE NEGATIVE NUMBER WHILE DEBUGGING, BUT ALWAYS 0.00 IN THE TEXT FILE.
		//COULD NOT FIGURE OUT WHY.

		//SOMETIMES IT WILL PRINT VALUES TO FILE OF ONLY THE WINNER. SOMETIMES IT PRINTS BOTH. SOMETIMES IT DOES NOT.
		//I COULD NOT FIND A PATTERN. I APOLOGIZE.
		stats1.hitMissRatio = ((double)stats1.hits / (double)stats1.misses) * 100;
		stats2.hitMissRatio = ((double)stats2.hits / (double)stats2.misses) * 100;
		
		fprintf(output_stats, "\n\nPlayer 1 - you - total number hits: %d\n", stats1.hits);
		fprintf(output_stats, "Player 1 - you - total number misses: %d\n", stats1.misses);
		fprintf(output_stats, "Player 1 - you - total number shots: %d\n", stats1.total_shots);
		fprintf(output_stats, "Player 1 - you - hits to miss ratio : %.2lf\n\n", stats1.hitMissRatio);
		
		fprintf(output_stats, "Player 2 - computer - total number hits: %d\n", stats2.hits);
		fprintf(output_stats, "Player 2 - computer - total number misses: %d\n", stats2.misses);
		fprintf(output_stats, "Player 2 - computer - total number shots: %d\n", stats2.total_shots);
		fprintf(output_stats, "Player 2 - computer - hits to miss ratio : %.2lf", stats2.hitMissRatio);

		
		
		fclose(output_stats);

		break;

	case EXIT:
		printf("Thanks for playing!\n");
		return 0;
	}
	return 0;
}
