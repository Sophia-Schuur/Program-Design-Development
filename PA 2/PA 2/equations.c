#include "equations.h"
#include <math.h>

/*************************************************************
* Function: double calculate_newtons_2nd_law(double mass, double acceleration)                     
* Date Created:                                             *
* Date Last Modified:                                       *
* Description: This function calculated Newtons second law.              
* Input parameters: mass, acceleration                                    *
* Returns: The force as a double.                *
* Preconditions: None                                       *
* Postconditions: The force is returned.*
*************************************************************/

double calculate_newtons_2nd_law(double mass, double acceleration)
{
	
	double f = 0;
	scanf("%lf%lf", &mass, &acceleration);
	f = mass * acceleration;
	return f;
}


/*************************************************************
* Function: calculate_volume_cylinder                        *
* Date Created:                                             *
* Date Last Modified:                                       *
* Description: This function calcs v of cylinder              *
* Input parameters: radius, height                                    *
* Returns: The volume of cylinder.                *
* Preconditions: None                                       *
* Postconditions: The volume is returned.*
*************************************************************/

double calculate_volume_cylinder(double radius, double height)
{
	double v = 0;
	scanf("%lf%lf", &radius, &height);
	v = Pi * (radius * radius) * height;
	return v;
}

/*************************************************************
* Function: perform_character_encoding                       *
* Date Created:                                             *
* Date Last Modified:                                       *
* Description: This function moves a character around according to the ASCII chart         *
* Input parameters: character, integer                                    *
* Returns: new character.                *
* Preconditions: None                                       *
* Postconditions: The new character is returned.*
*************************************************************/

char perform_character_encoding(char plaintext_character, int shift)
{
	char encoded_character = '\0';
	scanf(" %c%d", &plaintext_character, &shift);
	encoded_character = (plaintext_character - 'A') + 'a' - shift;
	return encoded_character;
}

/*************************************************************
* Function: calculate_parallel_resistance                    *
* Date Created:                                             *
* Date Last Modified:                                       *
* Description: This function calculates parallel resistance              *
* Input parameters: r1, r2, r3                                    *
* Returns: The parallel resistance a double.                *
* Preconditions: None                                       *
* Postconditions: The parallel resistance is returned.*
*************************************************************/

double calculate_parallel_resistance(int r1, int r2, int r3)
{

	double pr = 0.0;
	scanf("%d%d%d", &r1, &r2, &r3);
	pr = 1 / (1 / (double)r1 + 1 / (double)r2 + 1 / (double)r3);
	return pr;
}

/*************************************************************
* Function: calculate_resistive_divider()                         *
* Date Created:                                             *
* Date Last Modified:                                       *
* Description: This function calculates resistive divider voltage            *
* Input parameters: r1, r2, initial voltage                                    *
* Returns: The final voltage as a double.                *
* Preconditions: None                                       *
* Postconditions: The final voltage is returned.*
*************************************************************/


double calculate_resistive_divider(int R1, int R2, double vin)
{

	double vout = 0;
	scanf("%d%d%lf", &R1, &R2, &vin);
	vout = (double)R2 / ((double)R1 + (double)R2) * vin;
	return vout;

}

/*************************************************************
* Function:  calculate_distance_between_2pts()                         *
* Date Created:                                             *
* Date Last Modified:                                       *
* Description: This function calculates distance between two points            *
* Input parameters: x1, y1, x2, y2                                    *
* Returns: The distance as a double.                *
* Preconditions: None                                       *
* Postconditions: The distance is returned.*
*************************************************************/

double calculate_distance_between_2pts(double x1, double x2, double y1, double y2)
{
	
	double dist = 0, dx = 0, dy = 0;
	scanf("%lf%lf%lf%lf", &x1, &x2, &y1, &y2);
	dx = (x2 - x1);
	dy = (y2 - y1);
	dist = sqrt(dx*dx + dy*dy);
	return dist;
	
}

/*************************************************************
* Function: calculate_general_equation ()                         *
* Date Created:                                             *
* Date Last Modified:                                       *
* Description: This function calculates a genera l equation             *
* Input parameters: a, x, z                                    *
* Returns: The answer as a double.                *
* Preconditions: None                                       *
* Postconditions: The answer is returned.*
*************************************************************/

double calculate_general_equation(int a, double x, double z)
{
	
	double y = 0;
	scanf("%lf%lf%d", &x, &z, &a);
	y = -x * (double)(3 / (double)4) - z + a / (a % 2);
	return y;
	
}
