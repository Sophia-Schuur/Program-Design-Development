/* Sophia Schuur
CptS 121
PA 2
9/13/2016
Use functions to calculate several equations.*/

#include "equations.h"

int main(void)
{
	/*when I printed results in main I could not figure out how to get the program to display the user inputted
	values, but they showed up in the equations.c. I figured it was better to adhere to printing and displaying
	in main.c as the assignment asks than to print values in equations.c*/
	/*printf("Newton's Second Law: force = mass * acceleration= " "%.2lf * %.2lf = %.2lf\n", mass, acceleration, f);
		Could not get user-inputted values to print when this line was used in main, but they printed in equations.c*/



	double mass = 0, acceleration = 0, f = 0, radius = 0, height = 0, v = 0, shift = 0, pr = 0, vin = 0, vout = 0, x2 = 0, x1 = 0, y2 = 0, y1 = 0, dist = 0, x = 0, z = 0, y = 0;
	int r1 = 0, r2 = 0, r3 = 0, R1 = 0, R2 = 0, a = 0;
	char plaintext_character = '\0', encoded_character = '\0';

	printf("Enter a character and integer: ");
	encoded_character = perform_character_encoding(plaintext_character, shift);
	printf("Character = %c\n", encoded_character);
	
	printf("Please enter the mass and acceleration for use in Newton's Second Law: ");
	f = calculate_newtons_2nd_law(mass, acceleration);
	printf("Newton's Second Law: force = mass * acceleration = %.2lf\n", f);
	
	
	printf("Please enter the radius and height for use in the volume of a cylinder: ");
	v = calculate_volume_cylinder(radius, height);
	printf("Volume of a cylinder: Pi * radius^2 * height= " "%.2lf\n", v);



	printf("Enter resistance of three individual resisitors in a parallel circuit: ");
	pr = calculate_parallel_resistance(r1, r2, r3);
	printf("Total parallel resistance: " "%.2lf\n", pr);


	printf("Enter two resistances and an initial voltage for resistive divider: ");
	vout = calculate_resistive_divider(R1, R2, vin);
	printf("Resistive divider: " "%.2lf\n", vout);

	
	printf("Enter two x values and two y values to calculate the distance between these points: ");
	dist = calculate_distance_between_2pts(x2, x1, y2, y1);
	printf("The distance between those two points at ((x1 - x2)2 + (y1 - y2)2) is: " "%lf\n", dist);

	
	printf("Enter values in the order of x, z and a to put into the formuala y = -x * (3 / 4) - z + a / (a %% 2): ");
	y = calculate_general_equation(a, x, z);
	printf("Your answer is: " "%lf\n", y);

	
	
	
	return 0;

}