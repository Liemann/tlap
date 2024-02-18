#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char enc[26] = {0};
const char alph[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

int charIndex(char c, char chs[]) {
  int index = -1;
  for(int i = 0; i < 26; i++) {
    if(c == chs[i]) {
      index = i;
    }
  }
  return index;
}

void randomize() {
  for(int i = 0; i < 26; i++) {
    int index = rand()%26;
    // If the last spot available happens to be the same as the remaining characters
    if(i == 25 && enc[25] == 0) {
      int rndInd  = rand()%26;
      while(rndInd == 25) {
        rndInd = rand()%26;
      }
      int tmp = enc[rndInd];
      enc[rndInd] = alph[i];
      enc[i] = tmp;
    }
    // Assign characters in alphabetical order into random spots in the array that are available and not the same
    while(enc[index] != 0 || index == i) {
      index = rand()%26;
    }
    enc[index] = alph[i];
  }
}

int main() {
  srand(time(NULL));
  randomize();
  char letr;
  printf("Enter a sentence ended by either '.', '!' or '?'\n");
  while(1){
    scanf("%c", &letr);
    if(letr == ' ') {
      printf(" ");
    } else if(letr != '.' && letr != '!' && letr != '?') {
      int index = letr - 65;
      printf("Character enc: %c ",enc[index]);
      printf("And character dec: %c\n",alph[charIndex(enc[index], enc)]);
    } else {
      printf(".\n");
      return 0;
    }
  }
  // Print the randomized cipher array
  // for(int i = 0; i < 26; i++) {
  //   printf("%c",enc[i]);
  // }
  // printf("\n");
  return 0;
}
