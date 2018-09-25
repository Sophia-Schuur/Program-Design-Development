#include "equations.h"


FILE * open_input_file(void)
{
	FILE * infile = NULL;
	infile = fopen("input.dat", "r");
	return infile;
}

char read_character(FILE *infile)
{
	char character = '\0';
	fscanf(infile, "%c", &character);
	return character;

}


int determine_ascii_value(char character)
{
	int ascii_value = 0;
	ascii_value = (int)character;
	return ascii_value;
}

//int is_line(char character)
//{
//	if (character == '\n')
//	{
//		return NEWLINE;
//	}
//	else
//	{
//		return NOT_NEWLINE;
//	}
//}
//
//int number_lines(char character, int current_number_lines)
//{
//	if (is_line(character))
//	{
//		current_number_lines = current_number_lines + 1;
//	}
//	else
//	{
//		current_number_lines = current_number_lines;
//	}
//
//	return current_number_lines;
//}




int is_line(char character)
{

	if (character == '\n')
	{
		return NEWLINE;
	}
	else
	{
		return NOT_NEWLINE;
	}
}

int number_lines(char character, int current_number_lines)
{
	if (is_line(character) == NEWLINE)
	{
		current_number_lines + current_number_lines + 1;
		return current_number_lines;
	}
	else
	{
		return current_number_lines;
	}
}

int is_vowel(char character)
{
	if (character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u' || character == 'A' || character == 'E' || character == 'I' || character == 'O' || character == 'U')
	{
		return VOWEL;
	}
	else
	{
		return NOT_VOWEL;
	}
}

int number_vowels(char character, int current_number_vowels)
{
	if (is_vowel(character) == VOWEL)
	{
		current_number_vowels = current_number_vowels + 1;
		return current_number_vowels;
	}
	else
	{
		return current_number_vowels;
	}
}

int is_digit(char character)
{
	if ((character >='1') && (character <= '9'))
	{
		return DIGIT;
	}
	else
	{
		return NOT_DIGIT;
	}
}

int number_digits(char character, int current_number_digits)
{
	if (is_digit(character) == DIGIT)
	{
		current_number_digits = current_number_digits + 1;
		return current_number_digits;
	}
	else
	{
		return current_number_digits;
	}
}

int is_alpha(char character)
{
	if (((character >= 'a') && (character <= 'z')) ||
		((character >= 'A') && (character <= 'Z')))
	{
		return ALPHA;
	}
	else
	{
		return NOT_ALPHA;
	}
}

int number_alphas(char character, int current_number_alphas)
{
	if (is_alpha(character) == ALPHA)

	{
		current_number_alphas = current_number_alphas + 1;
		return current_number_alphas;
	}
	else
	{
		return current_number_alphas;
	}
}


int is_lower(char character)
{
	if ((character >= 'a') && (character <= 'z'))
	{
		return LOWER;
	}
	else
	{
		return NOT_LOWER;
	}
}

int number_lowers(char character, int current_number_lowers)
{
	if (is_lower(character) == LOWER)
	{
		current_number_lowers = current_number_lowers + 1;
		return current_number_lowers;
	}
	else
	{
		return current_number_lowers;
	}
}

int is_upper(char character)
{
	if ((character >= 'A') && (character <= 'Z'))
	{
		return UPPER;
	}
	else
	{
		return NOT_UPPER;
	}
}

int number_uppers(char character, int current_number_uppers)
{
	if (is_upper(character) == UPPER)
	{
		current_number_uppers = current_number_uppers + 1;
		return current_number_uppers;
	}
	else
	{
		return current_number_uppers;
	}
}


int is_space(char character)
{
	if ((character == ' ') || (character == '\f') || (character == '\r') || (character == '\t') || (character == '\v') || (character == '\n'))
	{
		return WHITESPACE;
	}
	else 
	{
		return NOT_WHITESPACE;
	}
}


int number_spaces(char character, int current_number_spaces)
{
	if (is_space(character) == WHITESPACE)
	{
		current_number_spaces = current_number_spaces + 1;
		return current_number_spaces;
	}
	else
	{
		return current_number_spaces;
	}
}


int is_alnum(char character)
{
	if ((is_alpha(character) == ALPHA) || (is_digit(character) == DIGIT))
	{
		return ALNUM;
	}
	else
	{
		return NOT_ALNUM;
	}
}

int number_alnums(char character, int current_number_alnums)
{
	if (is_alnum(character) == ALNUM)
	{
		current_number_alnums = current_number_alnums + 1;
		return current_number_alnums;
	}
	else
	{
		return current_number_alnums;
	}
}


int is_punct(char character)
{
	if ((character == '.') || (character == ',') || (character == '?') || (character == '-') || (character == '"') || (character == ':') || (character == '!') || (character == ';') || (character == '()'))
	{
		return PUNCT;
	}
	else
	{
		return NOT_PUNCT;
	}
}

int number_puncts(char character, int current_number_puncts)
{
	if (is_punct(character) == PUNCT)
	{
		current_number_puncts = current_number_puncts + 1;
		return current_number_puncts;
	}
	else
	{
		return current_number_puncts;
	}
}

void print_stats(FILE *outfile, char header[], int number)
{
	fprintf(outfile, "Number of %s: %d\n", header, number);
}

void print_int(FILE *outfile, int ascii_value)
{
	fprintf(outfile, "%d\n", ascii_value);
	return;
}
