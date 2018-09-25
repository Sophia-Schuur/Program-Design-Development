#include "header.h"
/* Sophie Schuur
	CptS 121
	10/4/2016
	This is a game of craps! Betting included.*/

int main(void)
{
	srand((unsigned int)time(NULL));
	int option = 0, die1 = 0, die2 = 0, sum = 0, check = -1, add_or_subtract = -1;
	double wager = 0.0, balance = 0.0, roll = 0, result = 0, point = 0, point2 = 0, new_balance = 0;
	char play_again = 'y';


	do
	{
		printf("\nLets play CRAPS! Select an option to start! Just input 1, 2 or 3!\n\n");
		printf("1. Print game rules!\n\n");
		printf("2. Play the game!\n\n");
		printf("3. Exit game\n\n");
		scanf("%d", &option);
		system("cls"); 
	} while ((option < 1) || (option > 3)); 

	
	
	
	switch (option) // 
	{
	case RULES: // print_game_rules ()
		
		print_game_rules();

		break;
	
	
	
	case PLAY: // play_craps ()
		while(play_again == 'y')
		{
			balance = get_bank_balance();
			wager = get_wager_amount();

			while (check != OK)
			{
				check = check_wager_amount(wager, balance);


				if (check == TOO_HIGH)
				{
					wager = get_wager_amount();

				}
			}


			//1st roll
			die1 = roll_die();
			die2 = roll_die();
			sum = calculate_sum_dice(die1, die2);
			point = is_win_loss_or_point(sum);

		


			//2nd roll
			while ((point != 1) && (point != 0))
			{
				die1 = roll_die();
				die2 = roll_die();
				roll = calculate_sum_dice(die1, die2);
				point = is_point_loss_or_neither(sum, roll);

				
			}
			double current_bank_balance = balance;
			balance = adjust_bank_balance(balance, wager, point);
			printf("Your balance is now: %lf\n", balance);
			chatter_messages(current_bank_balance, balance);
		
			printf("Would you like to play again? Enter y to play again. Enter n to exit.\n");
			scanf(" %c", &play_again);
	
		}
		return 0;
		
		//roll = calculate_sum_dice(die1, die2);
		//point2 = is_point_loss_or_neither(sum, roll);

		break;
	case EXIT: // exit ()
		
		return 0;

		break;
	default: 
		break;
	}
	
	return 0;
}