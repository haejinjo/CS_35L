#include <stdio.h> // for program's I/O functionality 
#include <stdlib.h>  // for malloc, realloc, and free, qsort
#include <stdbool.h> // for the different_strings variable

// TO DO:
// -Report errors of any kind (e.g. input/output, memory allocation failure)
// Do this by fprintf'ing the error to stderr and exiting with status 1
//Otherwise program should succeed and exit with status 0
// Slightly meta but: you dont have to report stderr output errors
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
  char defrob_a, defrob_b, last_a, last_b;

  // If we encounter even 1 difference between a and b's unfrobnicated characters,
  // a and b cannot be the same exact cstrings, so flag true!
  bool different_strings = false;
  bool both_completed = false;

  //Loop through a and b, checking if we've reached the space character of at least one
  // Note: frobnicated ' ' is still a ' ' so don't worry
  while (a[i] != ' ' && b[i] != ' ')
    {
      // fprintf ("a[i]: %c\n", a[i]); 
      // fprintf ("b[i]: %c\n\n", b[i]); 

      // Look at frobnicated bytes on at a time, unfrobnicated "by hand" 
      defrob_a = a[i]^42;
      defrob_b = b[i]^42; 

      // fprintf ("defrob_a: %c\n", defrob_a); 
      // fprintf ("defrob_b: %c\n\n", defrob_b); 

      // If current char in a != b 
      // Then, either a or b must be lesser or greater 
      if (defrob_a != defrob_b)
	{
	  // fprintf("a!=b\n"); 
	  different_strings = true;

	  if (a[i] != ' ' && b[i] != ' ')
	    {
	      // Unfrobnicate the currently-examined byte
	      // to check if the comparison should return negative or positive
	      if (defrob_a < defrob_b)
		{
		  // fprintf("%c < %c\n", a[i], b[i]); 
		  return -1;

		}
	      
	      else if (defrob_a > defrob_b)
		{
		  // fprintf("%c > %c\n", a[i], b[i]); 
		  return 1; 
		}
	    }
	}
      
      //fprintf("On iteration %d, a[i] is %c and b[i] is %c\n\n", i, a[i], b[i]); 

      // Check the next corresponding bytes between a and b
      i++;

      //fprintf("iter: %d\n", i);

      // Retain the last value accesed in both strings before brekaing out the loop
      // We know at least one of these should hold a space character (the condition to exit the loop)
      last_a = a[i];
      last_b = b[i];
    }

  // Double checking that these weren't prefixes of each other 
  if (!different_strings && last_a == ' ' && last_b!= ' ')
    {
      //fprintf("a < b\n");
      return -1; 
    }

  else if (!different_strings && last_a != ' ' && last_b == ' ')
    {
      

     // fprintf("a > b\n");
      return 1; 
      
    }

  else // a == b
    {
      // fprintf("Last a: %c\n", last_a);
      // fprintf("Last b: %c\n", last_b);
      // fprintf("a == b\n");
      return 0;
    }
}

int comp_func(const void* a, const void* b)
{
	return frobcmp( *((char**)a), *((char**)b) ); 
}



// FOR REFERENCE  
// int      getc(FILE *);
// int      getchar(void); //gets char from STDIN 

// char    *gets(char *); //Reads characters from the standard input (stdin) 
//and stores them as a C string into str until a newline character 
//or the end-of-file is reached.
// int putchar(int char); // writes a character (an unsigned char) specified by the argument char to stdout.

//void* malloc(size_t size)  allocates requestsed size of bytes; returns pointer to first byte of allocated space
//void* realloc(void* ptr, size_t size) changes size of memory block pointed to by ptr; returns address of newly resized mem block
//void  free(void* ptr) dellocates previously allocated space pointed to by ptr; 


// Trivial check: If input file is empty
// Check how much memory we need to allocate 
// 1) Start with reasonable amount of bytespace to play around with by malloc'ing char-size by arbitrary number, x
// 2) In a loop that starts by checking our iterator has not reached x and the current char from the stream is not the EOF char, 
//  
int main () 
{

  //if given empty file, don't do anything, just end program 
  if (feof(stdin))
    {
      return 0; 
    }

  //  LEAST 
  // *hXE]D = \0Brown
  // *{_CIA = \0Quick
  // *~BO   = \0The 
  // *LER   = \0fox
  // #NEM\4 = \tdog
  // #@_GZY = \tjumps
  // #FKPS  = \tlazy
  // #E\\OX = \tover
  // #^BO   = \tthe
  // GREATEST 

  // test strings
  //char* str1 = "*hXE]D "; 
  //char* str2 = "#^BO "; 


  //TESTING FROBCMP 
  //check return value of frobcmp
  //int frobcmp_return;
  
  //frobcmp_return = frobcmp(str1, str2);
  //fprintf("%d\n", frobcmp_return);


  // Start with an arbitrary (chosen-by-me) amount of char-memory to allocate 
  int starting_dmem = 15;
  int wordcount = 0; 
  char curr_char = getchar(); //init with first char from STDIN 
  int i = 0;

  char* word_buffer = (char*)malloc( (sizeof(char))*(starting_dmem) ); // number of bytes in a char x 15

  // Everything good under the hood? 
  if (word_buffer == NULL)
    {
      fprintf(stderr, "Word buffer memory allocation failed");
      exit(1);
    }


  //if its eof char, break out 

   //Loop through file contents and prepare the buffer space necessary 
  while(curr_char != EOF)
    {
      // If we've reached the limit of my arbitrary number of allocated bytes 
	    if(i == starting_dmem)
		{
			 // Then, double the bytes of dynamic memory (see next line)
			 starting_dmem *= 2; 
			 word_buffer = (char*)realloc(word_buffer, starting_dmem); 

			 // Good with that memory still? 
		      if (word_buffer == NULL)
			{
			  fprintf(stderr, "Word buffer memory allocation failed");
			  exit(1);
			}
		}

	  
	     // If current char is a space, we know we've found another word...
	     // UNLESS this space is the first char of the file OR we've encountered multiple spaces in a row 
	      if (curr_char == ' ')
	      {
			     word_buffer[i] = curr_char;
			     i++; 
			     wordcount++;  // recognize anad keep a count of words for mallocing word space later 
		  }

	      // Otherwise, current char is a letter and should simply be stored in the buffer 
	      else 
	      {
			  word_buffer[i] = curr_char;
			  i++; 
		  }

	      // Need this at end or you won't keep getting fresh input (initial getchar was before loop)
	      curr_char = getchar();

    } // end of while loop 


  //TO DO: Assume last word from STDIN is not followed by a space byte  
  // the program should still behave as if a space were appended to the input 

  // If we need more storage bytes
  if (i == starting_dmem)
    {
	     // Allocate more to make room for one space
	     starting_dmem += 1; 
	     word_buffer = (char*)realloc(word_buffer, starting_dmem);

	    if (word_buffer == NULL)
		{
		  fprintf(stderr, "Trailing space memory allocation failed");
		  exit(1);
		}

    }

  // Append the space byte at EOF, guaranteed to have room for it 
  if (word_buffer[i-1] != ' ') 
    {
      word_buffer[i] = ' ';
      wordcount++; 
    }

  // All good with the input? 
  if (ferror(stdin))
    {
      fprintf(stderr, "Error reading STDIN");
      exit(1);
    }

  char** words = (char**)malloc(sizeof(char*)*wordcount);

  if (words == NULL)
    {
      fprintf(stderr, "Words array allocation failed");
      exit(1);
    }

  // Array of pointers to pointers to chars, a place to keep file input as it is happening 

  //Loop through file input (outer loop = file, inner loop = words?) storing words before spaces
  // exit loop after last word in file is input

  int j;
  char* OG_buffer = word_buffer;  // preserve so you can modify the buffer var 

  //creating new word after every ' ' character
  for(j=0; j < wordcount; j++)
    {
	    // Store current word chunk into array of char* 
	    words[j] = word_buffer;

	     // If we're at the last word (words[j-1]), stop
	    if (j+1 == wordcount)
		{
		  break; 
		}

	      // Trying to get each index in this arrray to contain a pointer to 
		  // the beginning of each new char* word
	    while ((*word_buffer) != ' ')
		{
		  word_buffer++; 
		}

	      // One more time to skip over space and start at new word
	      word_buffer++; 
    }
  
  //keep taking in chars, storing them into char* variable until you reach a space
  // if at a space, store the char* holding the just-finished cstring into a dynamically allocated array 

    //frobcmp(*((char**)x), *((char**)y))
  int n; 
  char* sorted_output; 

  // SORT SORT SORT SORT SORT SORT SORT THE WORDS 
  qsort(words, wordcount, sizeof(char*), comp_func);
	

	//Print out final sorted output to STDOUT
	for (n=0; n < wordcount; n++)
	  {
	    sorted_output = words[n];

	    // start by outputting the first char in the known word
	    putchar(*sorted_output);

	    while(*sorted_output != ' ')
	     {
			sorted_output++; //grab next letter, and the next, etc. 
			putchar(*sorted_output); // push it to stdout
	     }

	  	// sorted_output = *words;
	  	// if (n > 0)
	  	// {
	  	// putchar(*sorted_output);
	  	// } 
	  	// while(*sorted_output != ' ')
	  	// {
	  	// 	words++;
	  	// 	putchar(*sorted_output); 
	  	// }
	  }


	if (ferror(stdout))
	  {
	    fprintf(stderr, "Error writing to STDOUT");
	    exit(1);
	  }

	free(words);
	free(OG_buffer); 

	return 0; 

} // end of main 



 
