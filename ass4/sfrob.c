#include <stdio.h> // for program's I/O functionality 
#include <stdlib.h>  // for malloc, realloc, and free, qsort
#include <stdbool.h> // for the different_strings variable

// TO DO:
// -Report errors of any kind (e.g. input/output, memory allocation failure)
// 		Do this by printf'ing the error to stderr and exiting with status 1
//		Otherwise program should succeed and exit with status 0
// 		Slightly meta but: you dont have to report stderr output errors
//
// -TAKE IN (frob'd) TEXTLINES FROM STDIN, WRITE SORTED (still frob'd) VERSION TO STDOUT 

// This program sorts encoded data, skipping intermediary step of decoding first 
// Using a C function I write, frobcmp 


// frombcmp acts as translator tool for program's input 
// Return Value: negative if a < b; zero if a == b; positive if a > b 
// Should behave same as memcmp on unfrobnicated versions of arrays a and b
int frobcmp (char const * a, char const* b)
{
	int i = 0;
	char last_a, last_b;

	// If we encounter even 1 difference between a and b's unfrobnicated characters,
	// a and b cannot be the same exact cstrings, so flag true!
	bool different_strings = false;

	//Loop through a and b, checking if we've reached the space character of at least one
	while (a[i] != ' ' && b[i] != ' ')
	{	
		// If current char in a != b 
		// Then, either a or b must be lesser or greater 
		if ((a[i]^42) != (b[i]^42))
		{
			different_strings = true;

			if (a[i] != ' ' && b[i] != ' ')
			{
				// Unfrobnicate the currently-examined byte
				// to check if the comparison should return negative or positive
				if ((a[i]^42) < (b[i]^42))
				{
					printf("%c < %c\n", a[i], b[i]); 
					return -1;

				}
		
				else if ((a[i]^42) > (b[i]^42))
				{
					printf("%c > %c\n", a[i], b[i]); 
					return 1; 
				}
			}
		}
		
		// Retain the last value accesed in both strings before brekaing out the loop
		// We know at least one of these should hold a space character (the condition to exit the loop)
		last_a = a[i];
		last_b = b[i];

		// Check the next corresponding bytes between a and b
		i++;
		//printf("iter: %d\n", i);
	}

	// Double checking that these weren't prefixes of each other 
	if (!different_strings && last_a == ' ' && last_b!= ' ')
	{
		return -1; 
	}

	else if (!different_strings && last_a != ' ' && last_b != ' ')
	{
		// 
		return 1; 
	
	}

	else // a == b
	{
		return 0;
	}
}


// look at frobnicated bytes on at a time, unfrobnicated "by hand" 



 int main () 
 {

if (ferror(stdin))
  {
    fprintf(stderr, "Error reading STDIN");
    exit(1);
  }

 	// int c;
 	// getchar();
 	// c = getchar(); 
  //i = frobcmp("*{_CIA\030\031 ", "*`_GZY\v ");


  // Barber < charger so why is it outputting positive 1??? 
  // test strings
  	char* str1 = "harBer";
  	char* str2 = "harger"; 
  	

	int i;
  	//frobnicate the test strings 
  	for (i=0 ; i != '\0'; i++)
  	{
  		str1[i] = (str1[i]^42);
  		str2[i] = (str2[i]^42);

  		i++;
  	}
  	
// int      getc(FILE *);
// int      getchar(void); //gets char from STDIN 

// ssize_t  getdelim(char **restrict, size_t *restrict, int, FILE *restrict);
// ssize_t  getline(char **restrict, size_t *restrict, FILE *restrict);

// char    *gets(char *); //Reads characters from the standard input (stdin) 
  						  //and stores them as a C string into str until a newline character 
  						 //or the end-of-file is reached.
// int 		putchar(int char); // writes a character (an unsigned char) specified by the argument char to stdout.
  	


  	//check return value of frobcmp
 	int frobcmp_return;
 	frobcmp_return = frobcmp(str1, str2);
	printf("%d\n", frobcmp_return);

 	if (ferror(stdout))
 	{
	 	fprintf(stderr, "Error writing to STDOUT");
	 	exit(1);
	}
 }
