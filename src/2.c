#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int sol(char *code);

int main()
{
  FILE *file;
  file = fopen("input.txt", "r");

  int sum = 0;
  int i = 1;

  char code[500];
  while(fgets(code, 500, file))
  {
    if (sol(code)) {
      sum += i;
      printf("%d\n", i);
    }
    i++;
  }

  printf("Sum: %d\n", sum);

  fclose(file);
  return 0;
}

int sol(char *code) {
  int maxBlue  = 0;
  int maxRed   = 0;
  int maxGreen = 0;

  int onHold = 0;

  char *rel = strtok(code, " ");
  rel = strtok(NULL, " ");
  
  while (rel != NULL) {
    if (atoi(rel) == 0) {
      if (memcmp(rel, "red", 3) == 0) {
        if (onHold > maxRed) maxRed = onHold;
      }
      else if (memcmp(rel, "blue", 4) == 0) {
        if (onHold > maxBlue) maxBlue = onHold;
      }
      else if (memcmp(rel, "green", 5) == 0) {
        if (onHold > maxGreen) maxGreen = onHold;
      }
    }
    onHold = atoi(rel);

    rel = strtok(NULL, " ");
  }

  return (maxRed <= 12 && maxGreen <= 13 && maxBlue <= 14);
}