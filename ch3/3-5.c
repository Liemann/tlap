#include <stdio.h>

const char sub[] = {'Q','S','P','B','R','N','A','T','L','O','C','M','K','E','V','D','J','U','F','X','I','W','G','Z','H','Y'};
const char alph[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

int charIndex(char c, const char chs[]) {
  int index = -1;
  for(int i = 0; i < 26; i++) {
    if(c == chs[i]) {
      index = i;
    }
  }
  return index;
}

int main() {
  char letr;
  printf("Enter a sentence ended by either '.', '!' or '?'\n");
  while(1){
    scanf("%c", &letr);
    if(letr == ' ') {
      printf(" ");
    } else if(letr != '.' && letr != '!' && letr != '?') {
      int index = letr - 65;
      printf("Character enc: %c ",sub[index]);
      printf("And character dec: %c\n",alph[charIndex(sub[index], sub)]);
      //printf("%c",alph[charIndex(letr, sub)]); Just for decrypting
    } else {
      printf(".\n");
      return 0;
    }
  }
  return 0;
}
