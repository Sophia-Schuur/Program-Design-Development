/*Sophia Schuur
CptS 121
9/20/2016
Program that  performs character processing on 10 characters read in from a file, and writes the results to output files.*/

#include "equations.h"

int main(void)
{
	FILE *read_file = NULL, *output_stats = NULL, *output_ascii = NULL;
	// RESUBMISSION
	// RESUBMISSION
	// THANK YOU SO MUCH FOR YOUR EMAIL SPENCER. IT STUMPED ME FOR HOURS

	char character = '\0', char1 = '\0', char2 = '\0', char3 = '\0', char4 = '\0', char5 = '\0', char6 = '\0', char7 = '\0', char8 = '\0', char9 = '\0', char10 = '\0';
	int lines = 0, vowels = 0, digits = 0, alphas = 0, lowers = 0, uppers = 0, spaces = 0, alnums = 0, puncts = 0;
	
	read_file = open_input_file();
	output_ascii = fopen("output_ascii.dat", "w");
	output_stats = fopen("output_stats.dat", "w");



	char1 = read_character(read_file);
	char2 = read_character(read_file);
	char3 = read_character(read_file);
	char4 = read_character(read_file);
	char5 = read_character(read_file);
	char6 = read_character(read_file);
	char7 = read_character(read_file);
	char8 = read_character(read_file);
	char9 = read_character(read_file);
	char10 = read_character(read_file);

	
	print_int(output_ascii, char1);
	print_int(output_ascii, char2);
	print_int(output_ascii, char3);
	print_int(output_ascii, char4);
	print_int(output_ascii, char5);
	print_int(output_ascii, char6);
	print_int(output_ascii, char7);
	print_int(output_ascii, char8);
	print_int(output_ascii, char9);
	print_int(output_ascii, char10);

	lines = number_lines(char1, lines);
	lines = number_lines(char2, lines);
	lines = number_lines(char3, lines);
	lines = number_lines(char4, lines);
	lines = number_lines(char5, lines);
	lines = number_lines(char6, lines);
	lines = number_lines(char7, lines);
	lines = number_lines(char8, lines);
	lines = number_lines(char9, lines);
	lines = number_lines(char10, lines);

	vowels = number_vowels(char1, vowels);
	vowels = number_vowels(char2, vowels);
	vowels = number_vowels(char3, vowels);
	vowels = number_vowels(char4, vowels);
	vowels = number_vowels(char5, vowels);
	vowels = number_vowels(char6, vowels);
	vowels = number_vowels(char7, vowels);
	vowels = number_vowels(char8, vowels);
	vowels = number_vowels(char9, vowels);
	vowels = number_vowels(char10, vowels);


	digits = number_digits(char1, digits);
	digits = number_digits(char2, digits);
	digits = number_digits(char3, digits);
	digits = number_digits(char4, digits);
	digits = number_digits(char5, digits);
	digits = number_digits(char6, digits);
	digits = number_digits(char7, digits);
	digits = number_digits(char8, digits);
	digits = number_digits(char9, digits);
	digits = number_digits(char10, digits);



	alphas = number_alphas(char1, alphas);
	alphas = number_alphas(char1, alphas);
	alphas = number_alphas(char1, alphas);
	alphas = number_alphas(char1, alphas);
	alphas = number_alphas(char1, alphas);
	alphas = number_alphas(char1, alphas);
	alphas = number_alphas(char1, alphas);
	alphas = number_alphas(char1, alphas);
	alphas = number_alphas(char1, alphas);
	alphas = number_alphas(char1, alphas);
	alphas = number_alphas(char1, alphas);

	lowers = number_lowers(char1, lowers);
	lowers = number_lowers(char2, lowers);
	lowers = number_lowers(char3, lowers);
	lowers = number_lowers(char4, lowers);
	lowers = number_lowers(char5, lowers);
	lowers = number_lowers(char6, lowers);
	lowers = number_lowers(char7, lowers);
	lowers = number_lowers(char8, lowers);
	lowers = number_lowers(char9, lowers);
	lowers = number_lowers(char10, lowers);

	uppers = number_uppers(char1, uppers);
	uppers = number_uppers(char2, uppers);
	uppers = number_uppers(char3, uppers);
	uppers = number_uppers(char4, uppers);
	uppers = number_uppers(char5, uppers);
	uppers = number_uppers(char6, uppers);
	uppers = number_uppers(char7, uppers);
	uppers = number_uppers(char8, uppers);
	uppers = number_uppers(char9, uppers);
	uppers = number_uppers(char10, uppers);

	spaces = number_spaces(char1, spaces);
	spaces = number_spaces(char2, spaces);
	spaces = number_spaces(char3, spaces);
	spaces = number_spaces(char4, spaces);
	spaces = number_spaces(char5, spaces);
	spaces = number_spaces(char6, spaces);
	spaces = number_spaces(char7, spaces);
	spaces = number_spaces(char8, spaces);
	spaces = number_spaces(char9, spaces);
	spaces = number_spaces(char10, spaces);

	alnums = number_alnums(char1, alnums);
	alnums = number_alnums(char2, alnums);
	alnums = number_alnums(char3, alnums);
	alnums = number_alnums(char4, alnums);
	alnums = number_alnums(char5, alnums);
	alnums = number_alnums(char6, alnums);
	alnums = number_alnums(char7, alnums);
	alnums = number_alnums(char8, alnums);
	alnums = number_alnums(char9, alnums);
	alnums = number_alnums(char10, alnums);

	puncts = number_puncts(char1, puncts);
	puncts = number_puncts(char2, puncts);
	puncts = number_puncts(char3, puncts);
	puncts = number_puncts(char4, puncts);
	puncts = number_puncts(char5, puncts);
	puncts = number_puncts(char6, puncts);
	puncts = number_puncts(char7, puncts);
	puncts = number_puncts(char8, puncts);
	puncts = number_puncts(char9, puncts);
	puncts = number_puncts(char10, puncts);


	print_stats(output_stats, "lines", lines);
	print_stats(output_stats, "vowels", vowels);
	print_stats(output_stats, "digits", digits);
	print_stats(output_stats, "alphas", alphas);
	print_stats(output_stats, "lowers", lowers);
	print_stats(output_stats, "uppers", uppers);
	print_stats(output_stats, "spaces", spaces);
	print_stats(output_stats, "alnums", alnums);
	print_stats(output_stats, "puncts", puncts);

	
	fclose(read_file);
	fclose(output_stats);
	fclose(output_ascii);


	return 0;

}