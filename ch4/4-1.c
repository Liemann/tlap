// Pop a char from string
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef char * arrayString;


int lenCh(arrayString str) {
  int len = 0;
  
  while(str[len] != 0) {
    len++;
  }

  return len;
}

arrayString popChar(arrayString str, int index) {
  int len = lenCh(str);
  if(index < 0 || index - 1 > len) {
    return str;
  }
  arrayString new = malloc((len) * sizeof(char));
  
  bool indPass = false;

  for(int i = 0; i < len; i++) {
    if(i == index) {
      indPass = true;
    }
    if(indPass) {
      new[i] = str[i+1];
    } else {
      new[i] = str[i];
    }
  }
  new[len] = 0;
  return new;
}

int main() {
  arrayString word;

  word = malloc(6*sizeof(char));
  word[0] = 'H';
  word[1] = 'e';
  word[2] = 'l';
  word[3] = 'l';
  word[4] = 'o';
  word[5] = 0;
  
  int index;
  printf("Enter an index: \n");
  scanf("%i", &index);

  arrayString str = popChar(word,index);
  int len = lenCh(str);
  for(int i = 0; i < len; i++) {
    printf("%c",str[i]);
  }
  printf("\n");
  free(word);
  free(str);

  return 0;
}
