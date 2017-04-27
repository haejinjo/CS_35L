#include <stdio.h>

// Double checking that the (mem)frobnicated value of the nullbyte is indeed '*'
// Spoiler alert: It is. 

int main () 
{
  char x = '\0'^42; //42 is 00101010

  printf("%c\n", x);

}
