#include "header.h"


//PRINTS GAME RULES
void print_game_rules(void)
{
	printf("This program simulates the game of Battleship.The game will be\n");
	printf("completely text - based. Battleship is a two player Navy game.\n");
		printf("The objective of the game is to sink all ships in your enemy's \n");
			printf("fleet.The Player to sink his / her enemy's fleet first wins. Both\n");
printf("players' fleets consist of 5 ships that are hidden from the \n");
printf("enemy.Each ship may be differentiated by its length besides\n");
printf("the Cruiser and Submarine or number of cells it expands on the\n");
printf("game board.The Carrier has 5 cells, Battleship has 4 cells,\n");
printf("Cruiser has 3 cells, Submarine has 3 cells, and the Destroyer\n");
printf("has 2 cells.\n");
}



//INITIALIZES BOARD
void init_board(char board[][10], int rows, int cols)
{
	int row_index = 0, col_index = 0;

	for (row_index = 0; row_index < rows; ++row_index) // controls which row
	{
		for (col_index = 0; col_index < cols; ++col_index) // controls which column
		{
			board[row_index][col_index] = '~';
		}
	}
}

//PRINTS BOARD
void print_board(char board[][10], int rows, int cols, int player_num)
{
	int row_index = 0, col_index = 0, index = 0, index2 = 0;
	putchar('\n');
	
	
	if (player_num == PLAYER)
	{
		printf("      PLAYER \n");
		printf("  0 1 2 3 4 5 6 7 8 9\n");
		for (row_index = 0; row_index < rows; ++row_index, index++) // controls which row
		{
			printf("%d", index);
			for (col_index = 0; col_index < cols; ++col_index) // controls which column
			{
				printf(" %c", board[row_index][col_index]);
			}
			putchar('\n');
		}
	}
	
	//else if (player_num == COMPUTER)
	else
		{
			printf("      COMPUTER \n");
			printf("  0 1 2 3 4 5 6 7 8 9\n");
			for (row_index = 0; row_index < rows; ++row_index, index2++) // controls which row
			{
				
				printf("%d", index2);
				for (col_index = 0; col_index < cols; ++col_index) // controls which column
				{
					if ((board[row_index][col_index] != 'm') && (board[row_index][col_index] != '*'))
					{
						printf(" ~", board[row_index][col_index]);
					}
					else
					{
						printf(" %c", board[row_index][col_index]);
					}

				}
				putchar('\n');
			}
		
	}
}

//GENERATE RANDOM DIRECTION FOR RANDOM SHIPS
Dir generate_dir(void)
{
	Dir direction = HOR;

	direction = (Dir)(rand() % 2);

	return direction;
}

//GENERATE RANDOM START POINT OF SHIP
void generate_strt_pt(int *row_ptr, int *col_ptr, Dir direction, int length)
{
	if (direction == HOR) // horizontal
	{
		*row_ptr = rand() % ROWS;
		*col_ptr = rand() % (COLS - length + 1);
	}
	else // vertical
	{
		*row_ptr = rand() % (ROWS - length + 1);
		*col_ptr = rand() % COLS;
	}
}


//MANUALLY PLACE SHIPS
void place_ships(char board[][10], int rows, int cols, int player_num)
{

	/*HORIZ OR VERT
		ROW AND COLIMN
		CHECK IF CAN
		IF YES PLACE
		LOOP THAT
*/
	int column_carrier = 0, row_carrier = 0, column_bs = 0, row_bs = 0, column_cruiser = 0, row_cruiser = 0,
		column_sub = 0, row_sub = 0, column_d = 0, row_d = 0, check = 0, check2 = 1;
	int row_index = 0, col_index = 0;

	char placement = '/0';
	
		//CARRIER

	do
	{
		check2 = 1;
		
		printf("Do you want to place your Carrier ship horizontally or vertically?\n");
		scanf(" %c", &placement);
		
		while ((placement != 'v') && (placement != 'V') && (placement != 'h') && (placement != 'H'))
		{

			printf("Do you want to place your Carrier ship horizontally or vertically?\n");
			scanf(" %c", &placement);
		}
			
		printf("Enter first row number for Carrier, 5 tiles:\n ");
			scanf(" %d", &row_carrier);

			printf("Enter column number for Carrier, 5 tiles:\n ");
			scanf(" %d", &column_carrier);

			if (placement == 'v' || placement == 'V')
			{
				if (row_carrier + 5 <= 9)
				{
					for (int index = row_carrier, count = 0; count < 5; index++, count++)
					{
						if (board[index][column_carrier] != '~')
						{
							printf("You've already placed a ship there. Try another spot.\n");
							check2 = 0;
						}
					}
				}
				if (check2 == 1) 
				{
					//puts ship on board
					for (int index = 0; index < 5; ++index)
					{
						board[row_carrier + index][column_carrier] = 'c';
					}
				}
				else
				{
					check = 0;
				}
			}
			
			//for horizontal

			if (placement == 'h' || placement == 'H')
			{
				if (column_carrier + 5 <= 9)
				{
					for (int index = column_carrier, count = 0; count < 5; index++, count++)
					{
						if (board[row_carrier][index] != '~')
						{
							printf("You've already placed a ship there. Try another spot.\n");
							check2 = 0;
						}
					}
				}
				if (check2 == 1)
				{
					//puts ship on board
					for (int index = 0; index < 5; ++index)
					{
						board[row_carrier][column_carrier + index] = 'c';
					}
				}
				else
				{
					check = 0;
				}
			}

		}while (check2 == 0 && check == 0);
		print_board(board, 10, 10, player_num);
		
		


		//BATTLESHIP
		do
		{
			check2 = 1;
			
			printf("Do you want to place your Battleship horizontally or vertically?\n");
			scanf(" %c", &placement);

			while ((placement != 'v') && (placement != 'V') && (placement != 'h') && (placement != 'H'))
			{
				printf("Do you want to place your Battleship horizontally or vertically?\n");
				scanf(" %c", &placement);
			}

			printf("Enter first row number for Battleship, 4 tiles:\n ");
			scanf(" %d", &row_bs);

			printf("Enter column number for Battleship, 4 tiles:\n ");
			scanf(" %d", &column_bs);

			if (placement == 'v' || placement == 'V')
			{
				if (row_bs + 4 <= 9)
				{
					for (int index = row_bs, count = 0; count < 5; index++, count++)
					{
						if (board[index][column_bs] != '~')
						{
							printf("You've already placed a ship there. Try another spot.\n");
							check2 = 0;
						}
					}
				}
				if (check2 == 1)
				{
					//puts ship on board
					for (int index = 0; index < 4; ++index)
					{
						board[row_bs + index][column_bs] = 'b';
					}
				}
				else
				{
					check = 0;
				}
			}

			//for horizontal

			if (placement == 'h' || placement == 'H')
			{
				if (column_bs + 4 <= 9)
				{
					for (int index = column_bs, count = 0; count < 5; index++, count++)
					{
						if (board[row_bs][index] != '~')
						{
							printf("You've already placed a ship there. Try another spot.\n");
							check2 = 0;
						}
					}
				}
				if (check2 == 1)
				{
					//puts ship on board
					for (int index = 0; index < 4; ++index)
					{
						board[row_bs][column_bs + index] = 'b';
					}
				}
				else
				{
					check = 0;
				}
			}

		} while (check2 == 0 && check == 0);
		print_board(board, 10, 10, player_num);



		////CRUISER

		do
		{
			check2 = 1;
			
			printf("Do you want to place your Cruiser horizontally or vertically?\n");
			scanf(" %c", &placement);

			while ((placement != 'v') && (placement != 'V') && (placement != 'h') && (placement != 'H'))
			{
				printf("Do you want to place your Cruiser horizontally or vertically?\n");
				scanf(" %c", &placement);
			}

			printf("Enter first row number for Cruiser, 3 tiles:\n ");
			scanf(" %d", &row_cruiser);

			printf("Enter column number for Cruiser, 3 tiles:\n ");
			scanf(" %d", &column_cruiser);

			if (placement == 'v' || placement == 'V')
			{
				if (row_bs + 3 <= 9)
				{
					for (int index = row_cruiser, count = 0; count < 5; index++, count++)
					{
						if (board[index][column_cruiser] != '~')
						{
							printf("You've already placed a ship there. Try another spot.\n");
							check2 = 0;
						}
					}
				}
				if (check2 == 1)
				{
					//puts ship on board
					for (int index = 0; index < 3; ++index)
					{
						board[row_cruiser + index][column_cruiser] = 'r';
					}
				}
				else
				{
					check = 0;
				}
			}

			//for horizontal

			if (placement == 'h' || placement == 'H')
			{
				if (column_cruiser + 3 <= 9)
				{
					for (int index = column_cruiser, count = 0; count < 5; index++, count++)
					{
						if (board[row_cruiser][index] != '~')
						{
							printf("You've already placed a ship there. Try another spot.\n");
							check2 = 0;
						}
					}
				}
				if (check2 == 1)
				{
					//puts ship on board
					for (int index = 0; index < 3; ++index)
					{
						board[row_cruiser][column_cruiser + index] = 'r';
					}
				}
				else
				{
					check = 0;
				}
			}

		} while (check2 == 0 && check == 0);
		print_board(board, 10, 10, player_num);


		////SUBMARINE

		do
		{
			check2 = 1;
			printf("Do you want to place your Submarine horizontally or vertically?\n");
			scanf(" %c", &placement);

			while ((placement != 'v') && (placement != 'V') && (placement != 'h') && (placement != 'H'))
			{
				printf("Do you want to place your Submarine horizontally or vertically?\n");
				scanf(" %c", &placement);
			}

			printf("Enter first row number for Submarine, 3 tiles:\n ");
			scanf(" %d", &row_sub);

			printf("Enter column number for Submarine, 3 tiles:\n ");
			scanf(" %d", &column_sub);

			if (placement == 'v' || placement == 'V')
			{
				if (row_sub + 3 <= 9)
				{
					for (int index = row_sub, count = 0; count < 5; index++, count++)
					{
						if (board[index][column_sub] != '~')
						{
							printf("You've already placed a ship there. Try another spot.\n");
							check2 = 0;
						}
					}
				}
				if (check2 == 1)
				{
					//puts ship on board
					for (int index = 0; index < 3; ++index)
					{
						board[row_sub + index][column_sub] = 's';
					}
				}
				else
				{
					check = 0;
				}
			}

			//for horizontal

			if (placement == 'h' || placement == 'H')
			{
				if (column_sub + 3 <= 9)
				{
					for (int index = column_sub, count = 0; count < 5; index++, count++)
					{
						if (board[row_sub][index] != '~')
						{
							printf("You've already placed a ship there. Try another spot.\n");
							check2 = 0;
						}
					}
				}
				if (check2 == 1)
				{
					//puts ship on board
					for (int index = 0; index < 3; ++index)
					{
						board[row_sub][column_sub + index] = 's';
					}
				}
				else
				{
					check = 0;
				}
			}

		} while (check2 == 0 && check == 0);
		print_board(board, 10, 10, player_num);



		/////DESTROYER

		do
		{
			check2 = 1;
			printf("Do you want to place your Destroyer horizontally or vertically?\n");
			scanf(" %c", &placement);

			while ((placement != 'v') && (placement != 'V') && (placement != 'h') && (placement != 'H'))
			{
				printf("Do you want to place your Destroyer horizontally or vertically?\n");
				scanf(" %c", &placement);
			}

				printf("Enter first row number for Destroyer, 2 tiles:\n ");
				scanf(" %d", &row_d);

				printf("Enter column number for Destroyer, 2 tiles:\n ");
				scanf(" %d", &column_d);

			

			if (placement == 'v' || placement == 'V')
			{
				if (row_d + 2 <= 9)
				{
					for (int index = row_d, count = 0; count < 5; index++, count++)
					{
						if (board[index][column_d] != '~')
						{
							printf("You've already placed a ship there. Try another spot.\n");
							check2 = 0;
						}
					}
				}
				if (check2 == 1)
				{
					//puts ship on board
					for (int index = 0; index < 2; ++index)
					{
						board[row_d + index][column_d] = 'd';
					}
				}
				else
				{
					check = 0;
				}
			}

			//for horizontal

			if (placement == 'h' || placement == 'H')
			{
				if (column_d + 2 <= 9)
				{
					for (int index = column_d, count = 0; count < 5; index++, count++)
					{
						if (board[row_d][index] != '~')
						{
							printf("You've already placed a ship there. Try another spot.\n");
							check2 = 0;
						}
					}
				}
				if (check2 == 1)
				{
					//puts ship on board
					for (int index = 0; index < 2; ++index)
					{
						board[row_d][column_d + index] = 'd';
					}
				}
				else
				{
					check = 0;
				}
			}

		} while (check2 == 0 && check == 0);
		print_board(board, 10, 10, player_num);

}

//DETERMINES IF A SHOT IS A HIT OR MISS. ALSO INCREMENTS HP AND PRINTS STATS TO OUTFILE. WORKS ON BOTH COMPUTER AND PLAYER.
int is_hit_or_miss(int row, int col, char board[][10], PIECES *player, STATS *stats, FILE *outfile, int player_num)
{
	
	
	int result = 0;
	
	if ((board[row][col] == '*') || (board[row][col] == 'm'))
	{
		printf("You've already selected this coordinate. Try again.\n");

		return -1;
	}




	if (board[row][col] != '~')
	{
		printf("It's a hit!\n");
		
		switch (board[row][col])
		{
		case 'c':
			fprintf(outfile, "Carrier hit!\n");
			player->carrier_hp--;

			if (player->carrier_hp == 0)
			{
				printf("Carrier has sunk!\n");
				fprintf(outfile, "Carrier ship sunk!\n");
			}
			break;

		case 'b':
			fprintf(outfile, "Battleship hit!\n");
			player->battleship_hp--;
			
			if (player->battleship_hp == 0)
			{
				printf("Battleship has sunk!\n");
				fprintf(outfile, "Battleship sunk!\n");
			}
			break;
		case 'r':
			fprintf(outfile, "Cruiser hit!\n");
			player->cruiser_hp--;

			if (player->cruiser_hp == 0)
			{
				printf("Cruiser has sunk!\n");
				fprintf(outfile, "Cruiser sunk!\n");
			}
			break;

		case 's':
			fprintf(outfile, "Submarine hit!\n");
			player->submarine_hp--;
			if (player->submarine_hp == 0)
			{
				printf("Submarine has sunk!\n");
				fprintf(outfile, "Submarine sunk!\n");
			}
			break;

		case 'd':
			fprintf(outfile, "Destroyer hit!\n");
			player->destroyer_hp--;
			if (player->destroyer_hp == 0)
			{
				printf("Destroyer has sunk!\n");
				fprintf(outfile, "Destroyer sunk!\n");
			}
			break;

		}
		player->player_hp--;

		stats->hits++;
		stats->total_shots = stats->misses + stats->hits;
		board[row][col] = '*';
		
		return 1;
	}
	else if (board[row][col] == '~')
	{
		printf("It's a miss!\n");
		board[row][col] = 'm';
		return 0;
		stats->misses++;
	}
	
	
	
}

//GETS A USER COORDINATE. PRINTS BOARD. CHECKS IF COORDINATE HAS ALREADY BEEN USED OR NOT. 
int get_coordinate(char p1_board[][10], char p2_board[][10], PIECES *player, STATS *stats, FILE *outfile, int player_num)
{
	int row = 0, col = 0, result = 0;
	do
	{
	printf("Enter a coordinate by row and column.\n");
	scanf("%d%d", &row, &col);
	
	print_board(p1_board, 10, 10, player_num);
	fprintf(outfile, "You fired at row %d column %d\n", row, col);
	
		
		result = is_hit_or_miss(row, col, p2_board, player, stats, outfile, player_num);
	} while (result == -1);
	
}

//GETS A RANDOMLY GENERATED COMPUTER COORDINATE.  CHECKS IF COORDINATE HAS ALREADY BEEN USED OR NOT. 
int get_computer_coordinate(char p1_board[][10], char p2_board[][10], PIECES *player, STATS *stats, FILE *outfile, int player_num)
{
	int row = 0, col = 0, result = 0;
	do
	{
	row = generate_rand_comp_row();
	col = generate_rand_comp_col();


	print_board(p2_board, 10, 10, player_num);
	printf("Computer fired at %d, %d\n", row, col);
	fprintf(outfile, "Computer fired at row %d column %d\n", row, col);
	
		result = is_hit_or_miss(row, col, p1_board, player, stats, outfile, player_num);
	} while (result == -1);

	
	
}

//GENERATES RANDOM ROW VALUE BETWEEN 0-9 FOR COMPUTER TURN.
int generate_rand_comp_row()
{
	int row = 0;
	row = rand() % 10;
	return row;
}


//GENERATES RANDOM COL VALUE BETWEEN 0-9 FOR COMPUTER TURN.
int generate_rand_comp_col()
{
	int col = 0;
	col = rand() % 10;
	return col;
}

// CHECKS IF A SHIP IS ON ANOTHER SHIP FOR RANDOM BOARD PRINTING. WORKS ON BOTH HUMAN AND COMPUTER
void random_board(char board[][10], int player_num)
{
	int check = 0;
	int row = 0, col = 0;
	
	//CARRIER
	while (check == 0)
	{
		Dir direction = generate_dir();
		generate_strt_pt(&row, &col, direction, 5);
		check = place_ran_ships(board, row, col, direction, 'c', 5);
		
	}
	
	
	//BATTLESHIP
	check = 0;
	while (check == 0)
	{
		Dir direction = generate_dir();
		generate_strt_pt(&row, &col, direction, 4);
		check = place_ran_ships(board, row, col, direction, 'b', 4);
	}
	

	//CRUISER
	check = 0;
	while (check == 0)
	{
		Dir direction = generate_dir();
		generate_strt_pt(&row, &col, direction, 3);
		check = place_ran_ships(board, row, col, direction, 'r', 3);
	}
	

	//SUBMARINE
	check = 0;
	while (check == 0)
	{
		Dir direction = generate_dir();
		generate_strt_pt(&row, &col, direction, 3);
		check = place_ran_ships(board, row, col, direction, 's', 3);
	}
	

	//DESTROYER
	check = 0;
	while (check == 0)
	{
		Dir direction = generate_dir();
		generate_strt_pt(&row, &col, direction, 2);
		check = place_ran_ships(board, row, col, direction, 'd', 2);
	}
	print_board(board, 10, 10, player_num);

}


//RANDOMLY PLACES SHIPS ON BOARD.
int place_ran_ships(char board[][10], int row, int col, Dir direction, char ship, int length)
{

	int i = 0, count = 0;

	if (direction == HOR)
	{
		
		for (i = col, count = 0; count < length; count++, i++)
		{
			if (board[row][i] != '~')
			{
				return 0;
			}
			
		}
		
		for (i = col, count = 0; count < length; count++, i++)
		{
			board[row][i] = ship;
			
			
		}
		return 1;
	}
	

	if (direction == VER)
	{
		for (i = row, count = 0; count < length; count++, i++)
		{
			if (board[i][col] != '~')
			{
				return 0;
			}
		}
		for (i = row, count = 0; count < length; count++, i++)
		{
			board[i][col] = ship;
		}
		return 1;
	}


}




