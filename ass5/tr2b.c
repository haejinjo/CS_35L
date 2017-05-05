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
  //char output_string[]="";
  char* i; 
  char* j; /* cstring iterator */
  // int index = 0;   //cstring char index iterator  


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
    //TO DO: FIGURE OUT WHY 2 NEWLINES AT THE END 
    //printf("%c\n", curr_char);

    //LOOP THRU ARG1 CHARS
    //Note: should be ok since arguments are not gonna be super long 
    //printf("input string char being examined: %c\n", curr_char);

    //i = src; 
    j = dst;
   // curr_char_printed = false; 

    //printf("Printing src and dst\n %s\n",src);


    // CHECK INPUT CHAR AGAINST ARG CHAR(S)
   for (i = src; *i != '\0' ; i++)
    { 
      //printf("src char is %c\n", *i);
        // IF INPUT CHAR MATCHES ARG1 CHAR 
        if(curr_char == *i)
        { 
           // printf("curr char is equal to %c\n", *i);

          //REASSIGN TO ARG2'S CHAR 
           output_char = *j; 
           putchar(output_char); 
           curr_char_printed = true; 
           break; 
          //printf("curr char is now %c\n", *j);
           // OUTPUT WHATEVER GOT PLACED INTO CURR_CHAR 
        
        }
      
       j++; 
    } //END OF FOR LOOP
    
    if (!curr_char_printed)
    {
      putchar(curr_char);
    }

    curr_char_printed = false; 
  }

  return 0;
}
