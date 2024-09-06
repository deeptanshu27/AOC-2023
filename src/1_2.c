#include "stdio.h"
#include "string.h"

int sol(char *code);

int main()
{
  FILE *file;
  file = fopen("input.txt", "r");

  int sum = 0;

  char code[100];
  while(fgets(code, 100, file))
  {
    sum += sol(code);
  }

  printf("Sum: %d\n", sum);

  fclose(file);
  return 0;
}

int sol(char *code) {
  int word[50];
  int wordLen = 0;
  char *numWords[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

  int firstNum = -1;
  int secondNum = -1;

  for (int i = 0; i < strlen(code); i++) {
    if (code[i] >= '0' && code[i] <= '9') {
      if (firstNum == -1) {
        firstNum = code[i] - '0';
      }
      secondNum = code[i] - '0';
      word[0] = '\0';
      wordLen = 0;
    }
    else {
      word[wordLen] = code[i];
      word[wordLen + 1] = '\0';
      wordLen++;
      
      for (int j = 0; j < wordLen - 2; j++) {
        char newWord[100];
        int newWordLen = 0;
        for (int k = j; k < wordLen; k++) {
          newWord[newWordLen] = word[k];
          newWordLen++;
        }
        newWord[newWordLen] = '\0';

        for (int k = 0; k < 10; k++) {
          if (strcmp(newWord, numWords[k]) == 0) {
            if (firstNum == -1) {
              firstNum = k;
            }
            secondNum = k;

            word[0] = word[wordLen - 1];
            word[1] = '\0';
            wordLen = 1;
            break;
          }

        }

        if (wordLen == 1) {
          break;
        }

      }

    }
  }
  printf("%s -- %d\n", code, firstNum * 10 + secondNum);
  return firstNum * 10 + secondNum;

}