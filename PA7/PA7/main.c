//Sophia Schuur
//CptS 121
//11/9/2016
//PA7 - math program for elementary school age children
//


#include "header.h"


int main(void)
{
	int option = 0, score1 = 0, score2 = 0, score3 = 0, score4 = 0, score5 = 0, total_score = 0;
	srand((unsigned int)time(NULL));
	char initials[10];
	char play_again = 'y';
		
	//PRINT INITIAL INTERFACE
	
	
		FILE *output_stats = NULL;
		output_stats = fopen("output_stats.txt", "w");
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
		} while ((option < 3) || (option > 4));
		switch (option)
		{


		case DO_MATH:
			while (play_again == 'y')
			{
				option = 0;
				do
				{
					printf("Enter the number to the left of the option you would like to choose.\n\n");
					printf("1. Easy Mode - Addition and subtraction\n\n");
					printf("2. Fair mode - Multiplication\n\n");
					printf("3. Medium mode - Division\n\n");
					printf("4. Hard mode - Easy addition, subtraction, multiplication and division\n\n");
					printf("5. Impossible mode - Hard addition, subtraction, multiplication and division\n\n");
					scanf("%d", &option);
					system("cls");

				} while ((option < 1) || (option > 5));


				switch (option)
				{
					//Includes addition and subtraction problems, 
					//with positive single digit operands and up to three terms only
					//(i.e.d1 + d2 - d3 = )
				case EASY:
					score1 = easy_mode();
					break;

				case FAIR:
					score2 = fair_mode();
					break;

				case MEDIUM:
					score3 = intermediate_mode();
					break;

				case HARD:
					score4 = hard_mode();
					break;

				case IMPOSSIBLE:
					score5 = impossible_mode();
					break;

				}
				total_score = score1 + score2 + score3 + score4 + score5;

				fprintf(output_stats, "\nYour total score is: %d\n", total_score);
				fclose(output_stats);

				printf("Would you like to try again For a better score? Enter y to try again\n");
				scanf(" %c", &play_again);
				system("cls");

			}
		case EXIT:
			printf("\nStudy Hard!\n");
			return 0;

			break;

		}
	
}