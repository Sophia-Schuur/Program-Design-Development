/*Name: Sophia Schuur
Ace Programmer 
Not really, I have no experience 
Date: 9/3/2016 
Description: Program to calculate seven varying equations commonly found in mathematics and physics. 
*/

#include <stdio.h>
#define Pi 3.1415
#include <math.h>

int main(void)
{
	//3. Character encoding
	char character = '\0';
	printf("Enter a character: ");
	scanf("%c", &character);
	character = character - 'a' + 'A' + 3;
	printf("Character: %c\n", character);
	
	
	
	//1. Newton's Second Law
	printf("Please enter the mass and acceleration for use in Newton's Second Law: ");
	double mass = 0, acceleration = 0, f = 0;
	scanf("%lf%lf", &mass, &acceleration);
	f = mass * acceleration;
	printf("Newton's Second Law: force = mass * acceleration= " "%lf\n", f);



	//2. Volume of a cylinder
	printf("Please enter the radius and height for use in the volume of a cylinder: ");
	double radius = 0, height = 0, v = 0;
	scanf("%lf%lf", &radius, &height);
	v = Pi * (radius * radius) * height;
	printf("Volume of a cylinder: Pi * radius^2 * height= " "%lf\n", v);

	

	//4. Equivalent Parallel Resistance 
	printf("Enter resistance of three individual resisitors in a parallel circuit: ");
	int r1 = 0, r2 = 0, r3 = 0;
	double pr = 0.0;
	scanf("%d%d%d", &r1, &r2, &r3);
	pr = 1 / (1 / (double)r1 + 1 / (double)r2 + 1 / (double)r3);
	printf("Total parallel resistance: " "%lf\n", pr);



	//5.Resistive divider
	printf("Enter two resistances and an initial voltage for resistive divider: ");
	double R1 = 0, R2 = 0, vin = 0, vout = 0;
	scanf("%lf%lf%lf", &R1, &R2, &vin);
	vout = R2 / (R1 + R2) * vin;
	printf("Resistive divider: " "%lf\n", vout);



	//6. Distance between two points 
	printf("Enter two x values and two y values to calculate the distance between these points: ");
	double x2 = 0, x1 = 0, y2 = 0, y1 = 0;
	scanf("%lf%lf%lf%lf", &x1, &x2, &y1, &y2);
	double dx = (x2 - x1);
	double dy = (y2 - y1);
	double dist = sqrt(dx*dx + dy*dy);
	printf("The distance between those two points at ((x1 - x2)2 + (y1 - y2)2) is: " "%lf\n", dist);



	//7. General Equation 
	// I couldn't get the percent 2 to show up in the program. I'm not sure what it does so I just left it. 
	printf("Enter values in the order of x, z and a to put into the formuala y = -x * (3 / 4) - z + a / (a % 2): ");
	int a = 0;
	double x = 0, y = 0, z = 0;
	scanf("%lf%lf%d", &x, &z, &a);
	y = -x * (double)(3 / (double)4) - z + a / (a % 2);
	printf("Your answer is: " "%lf\n", y);



	return 0;
}