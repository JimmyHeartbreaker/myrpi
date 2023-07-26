#include <stdio.h>
#include "../include/examples.h"



int main(void) 
{
  int a = getInt();
  int b = 3;
  callback();
  int c = 0;

  c = add(a,b);

  printf("Results of %d + %d = %d\n", a, b, c);
}
