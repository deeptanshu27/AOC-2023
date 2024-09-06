#include "stdio.h"
#include "string.h"

int main()
{
  FILE *file;
  file = fopen("input.txt", "r");

  char code[100];

  char *nums = "1234567890";

  char first;
  char second;

  int sum = 0;

  while(fgets(code, 100, file))
  {
    first = '@';
    second = '@';
    for (int i = 0; i < strlen(code); i++)
    {
      for (int j = 0; j < strlen(nums); j++)
      {
        if (code[i] == nums[j])
        {
          if (first != '@')
          {
            second = nums[j];
          }
          else
          {
            first = nums[j];
            second = nums[j];
          }
        }
      }
    }
    printf("%c%c\n", first, second);
    sum += (first - '0') * 10 + (second - '0');
  }

  printf("Sum: %d\n", sum);

  fclose(file);
  return 0;



}