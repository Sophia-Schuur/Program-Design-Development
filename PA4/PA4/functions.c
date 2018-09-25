#include "header.h"

void print_game_rules(void)//Prints out the rules of the game of "craps".
{
	printf("You will roll two six sided dice.\nAfter the dice have come to rest, the sum of the spots on the two upward faces is calculated.\n If the sum is 7 or 11 on the first throw, you win!\nIf the sum is 2, 3, or 12 on the first throw, you lose!\n If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes your point.\n To win, you must continue rolling the dice until you roll that sum again and make you point.\n You lose if you roll a 7 before making the point!\n");
}


double get_bank_balance(void)//Prompts the player for an initial bank balance from which wagering will be added or subtracted. The player entered bank balance (in dollars, i.e. $100.00) is returned.
{
	double balance = 0.0;
	printf("Enter initial bank balance from which wagering will be added or subtracted.\nHow much you got?\n");
	scanf("%lf", &balance);
	return balance;
}

double get_wager_amount(void) //Prompts the player for a wager on a particular roll.The wager is returned.
{
	double wager = 0.0;
	printf("How much of that would you like to bet?\n");
	scanf("%lf", &wager);
	return wager;
}



int check_wager_amount(double wager, double balance) //Checks to see if the wager is within the limits of the player's available balance. If the wager exceeds the player's allowable balance, then 0 is returned; otherwise 1 is returned.
{

	int check = 0;
		if ((wager <= balance) && (wager >= 0))
		{

			return OK;
		}
		else
		{
			return TOO_HIGH;
		}


}




int roll_die(void)
{
	int die_value = 0;

	die_value = rand() % 6 + 1;

	return die_value;
}

int calculate_sum_dice(int die1, int die2) //Sums together the values of the two dice and returns the result.Note: this result may become the player's point in future rolls.
{
	int sum = 0;
	sum = die1 + die2;
	printf("You rolled a %d\n", sum);
	return sum;

}





//Determines the result of the first dice roll.If the sum is 7 or 11 on the roll, 
//the player wins and 1 is returned.If the sum is 2, 3, or 12 on the first throw (called "craps"), the player loses(i.e.the "house" wins) and 0 is returned.
//If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's "point" and -1 is returned
int is_win_loss_or_point(int sum)
{
	int point = 0;
	if ((sum == 7) || (sum == 11))
	{
		printf("You win!\n");
		return 1;
	}
	else if ((sum == 2) || (sum == 3) || (sum == 12))
	{
		printf("You lose!\n");
		return 0;
	}
	else
	{
		return -1;
	}
}

int is_point_loss_or_neither(int point, int roll)// Determines the result of any successive roll after the first roll
															//If the sum of the roll is the point_value, then 1 is returned.If the sum of the roll is a 7, then 0 is returned.
															//Otherwise, -1 is returned
	
{
		
		if (roll == 7)
		{
			printf("Oh no! You rolled a 7, You Lose!\n");
			return 0;
		}
		else if (roll == point)
		{
			printf("You rolled a %d! You win!\n\n", point);
			return 1;
		}
		else
		{
			printf("Roll again!\n");
			return -1;
		}

}

double adjust_bank_balance(double balance, double wager, int add_or_subtract) //If add_or_subtract is 1, then the wager amount is added to the bank_balance
																						//If add_or_subtract is 0, then the wager amount is subtracted from the bank_balance.
																						//Otherwise, the bank_balance remains the same.The bank_balance result is returned.
{
	if (add_or_subtract == 1)
	{
		balance = balance + wager;
		printf("Your balance is now %lf\n", balance);
	}
	else if (add_or_subtract == 0)
	{
		balance = balance - wager;
		printf("Your balance is now %lf\n", balance);
	}
	else
	{
		balance = balance;
	}
	return balance;
}

void chatter_messages(double balance, double current_bank_balance) //Prints an appropriate message dependent on the number of rolls taken so far by the player, the current balance, and whether or not the player just won his roll
																														//The parameter win_loss_neither indicates the result of the previous roll.
{
	if (current_bank_balance / balance < .5)
	{
		printf("You have lost a lot, maybe consider quitting soon.");
	}
	else if (current_bank_balance > (2 * balance))
	{
		printf("You've made over double your wager!");
	}
}

