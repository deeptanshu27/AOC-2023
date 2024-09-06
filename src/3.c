#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int sol(char **code, int codeLen);
void isSymbol(char **code, int i, int j, int* isSymbol);

int main()
{
  FILE *file;
  file = fopen("input.txt", "r");

  int sum = 0;
  int i = 0;

  char *res[500];
  char code[500];
  while(fgets(code, 500, file))
  {
    res[i] = malloc((strlen(code) + 1) * sizeof(char));
    strcpy(res[i], code);
    i++;
  }


  sol(res, i);

  fclose(file);
  return 0;
}

int sol(char **code, int codeLen) {
  int hasSymbol = 0;

  char curr[200];
  int currLen = 0;
  int sum = 0;
  int falsePos = 0;
  
  for (int i = 0; i < codeLen; i <= i++) {
    for (int j = 0; j < strlen(code[i]); j++) {
      if (!(code[i][j] >= '0' && code[i][j] <= '9')) {
        if (falsePos == 1 && currLen > 0) {
          curr[currLen] = '\0';
          sum += atoi(curr);
        }
        curr[0] = '\0';
        currLen = 0;
        falsePos = 0;
        continue;
      }


      if (i > 0) isSymbol(code, i - 1, j, &hasSymbol);
      if (i < codeLen - 1) isSymbol(code, i + 1, j, &hasSymbol);
      if (j > 0) isSymbol(code, i, j - 1, &hasSymbol);
      if (j < codeLen - 1) isSymbol(code, i, j + 1, &hasSymbol);
      if (i > 0 && j > 0) isSymbol(code, i - 1, j - 1, &hasSymbol);
      if (i < codeLen - 1 && j < codeLen - 1) isSymbol(code, i + 1, j + 1, &hasSymbol);
      if (i > 0 && j < codeLen - 1) isSymbol(code, i - 1, j + 1, &hasSymbol);
      if (i < codeLen - 1 && j > 0) isSymbol(code, i + 1, j - 1, &hasSymbol);


      curr[currLen] = code[i][j];
      currLen++;
      if (hasSymbol == 1) {
        falsePos = 1;
      }

      hasSymbol = 0;
    }
  }


  // check again if number is at end
  if (falsePos == 1 && currLen > 0) {
    curr[currLen] = '\0';
    sum += atoi(curr);
  }
  curr[0] = '\0';
  currLen = 0;
  falsePos = 0;

  printf("%d\n", sum);
}

void isSymbol(char **code, int i, int j, int* isSymbol) {
  char c = code[i][j];
  if (c >= '0' && c <= '9') {}
  else if (c == '.') {}
  else *isSymbol = 1;
}