//UNBUFFERED I/O
#include <unistd.h> //for read write with nbytes set to 1 (for 1 char at a time)
#include <stdbool.h> 
#include <stdio.h>


int main (int argc, char** argv) 
{
	
	/* error check for number of args user gives us (argv[0] is the command name itself) */ 
  if (argc != 3)
  {
  	const char arg_msg[] = "Error -- tr2b needs 2 arguments\n";
  	 write(2, arg_msg, sizeof(arg_msg)-1);

    return -1;
  }

   /* Store the src and dst strings...note: argv[1] holds first argument, skipping program name */
  char* src = argv[1];
  char* dst = argv[2]; 

  char curr_char[1];
  bool curr_char_printed = false;
  char output_char;
  char* i; 
  char* j;
  

	while((read(0, curr_char, 1) != 0))
	{
		j = dst;
		curr_char_printed = false;

		for (i=src; *i != '\0'; i++)
		{
			//printf("seen by Vivian Sun\n");
			if (*curr_char == *i)
			{
				output_char = *j;

				write(1, &output_char, 1);
				curr_char_printed = true;
				break;
			}
			j++;

		}

		if(!curr_char_printed)
		{
			write(1, &curr_char, 1);
		}

	}

  return 0;
}
