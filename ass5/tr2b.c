#include <stdio.h> /* for getchar putchar */ 
#include <stdbool.h> 
  /* This program is a simplified tr command with no options, using buffered I/O */
/* Replaces each char that matches a char in first string with the corresponding char in seconnd string */

/* takes two arguments: src and dst character strings */ 
int main (int argc, char** argv) {
  
  /* error check for number of args user gives us (argv[0] is the command name itself) */ 
  if (argc != 3)
  {
    printf("Error -- tr2b needs 2 arguments\n");
    return -1;
  }

  /* Store the src and dst strings...note: argv[1] holds first argument, skipping program name */
  char* src = argv[1];
  char* dst = argv[2]; 


 bool curr_char_printed = false;
  char curr_char; 
  char output_char;
  char* i; 
  char* j; 

// TESTING HOW THE POINTERS TO CHARS ARE BEING INTERPRETED
// FORGOT TO DEREFERENCE THE char* i POINTER WHEN COMPARING IT TO NULL BYTE => UNDEFINED OUTPUT
  // for (i = src; *i != '\0'; i++)
  //   {
  //     printf("%c", src[index]);
  //     index++;
  //   }
  //   printf("\n");

  // index = 0; 
  // for (i= dst; *i !='\0'; i++)
  // {
  //   printf("%c", dst[index]);
  //   index++;
  // }
  //  printf("\n");

  //Loop through chars of file input getchar stores as many as possible in buffer 
  while((curr_char = getchar()) != EOF)
  {
    curr_char_printed = false; 
    j = dst;

    // CHECK INPUT CHAR AGAINST ARG CHAR(S)
   for (i = src; *i != '\0' ; i++)
    { 
        // if input char maps to a src char
        if(curr_char == *i)
        { 
          //output corresponding dst char  
           output_char = *j; 
           putchar(output_char); 
           curr_char_printed = true; //set flag
           break;  
        }
      
       j++; 

    } //END OF FOR LOOP
    
    //USE FLAG TO PREVENT DOUBLE PRINTING
    if (!curr_char_printed)
    {
      //output original input char
      putchar(curr_char);
    }
    
  } //END OF FILE INPUT CHARS LOOP 




  return 0;
} // END OF MAIN 
