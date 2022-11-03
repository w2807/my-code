#include <stdio.h>
#include <stdlib.h>

typedef union
{
  char  ch[8];
  double fa;
}float_char;
int main(void)
{

  float_char gundam;

  setvbuf(stdout, 0, 2, 0);
  setvbuf(stdin, 0, 2, 0);

  printf("please give me the core float!!!\n");
  for (int i = 0; i < 8; i++)
  {
    gundam.ch[i] = getchar();
  }

  if (gundam.fa == 0.618)
  {
    printf("Gundam Rising!!");
    system("cat /tmp/flag");
  }
  else
    printf("false!\n");

  return 0;

}
