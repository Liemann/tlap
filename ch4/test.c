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

void append(arrayString str, char c) {
  int oldLen = lenCh(str);
  arrayString new = malloc((oldLen + 2) * sizeof(char));
  for(int i = 0; i < oldLen; i ++) {
    new[i] = str[i];
  }
  new[oldLen] = c;
  new[oldLen + 1] = 0;
  str = new;
  free(new);
}

int main() {
  arrayString str = malloc(sizeof(char));
  str[0] = 'c';
  append(str, 'c');
  append(str, 'a');
  append(str, 'b');
  append(str, 0);
  for(int i = 0; i < lenCh(str); i++) {
    printf("%c",str[i]);
  }
  printf("\n");
  free(str);
  return 0;
}
