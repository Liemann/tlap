#include <stdio.h>

const char sub[] = {'Q','S','P','B','R','N','A','T','L','O','C','M','K','E','V','D','J','U','F','X','I','G','W','Z','H','Y'};

int main() {
  char letr;
  printf("Enter a sentence ended by either '.', '!' or '?'\n");
  while(1){
    scanf("%c", &letr);
    if(letr == ' ') {
      printf(" ");
    } else if(letr != '.' && letr != '!' && letr != '?') {
      int index = letr - 65;
      printf("%c",sub[index]);
    } else {
      printf(".\n");
      return 0;
    }
  }
  return 0;
}
