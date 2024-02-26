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

arrayString substring(arrayString str, int from, int to) {
  int len = lenCh(str);
  if(to > len || from < 0 || to < 0 || from >= len) {
    return str;
  }
  arrayString new = malloc((to + 1) * sizeof(char));

  for(int i = 0; i < to; i++) {
    new[i] = str[from + i];
  }

  new[to] = 0;

  return new;
}

int main() {
  arrayString str = malloc(10 * sizeof(char));
  str[0] = 'a';
  str[1] = 'b';
  str[2] = 'c';
  str[3] = 'd';
  str[4] = 'e';
  str[5] = 'f';
  str[6] = 'g';
  str[7] = 'h';
  str[8] = 'i';
  str[9] = 0;

  int from,to;

  printf("Enter a starting index and a length of the substring:\n");
  scanf("%i",&from);
  scanf("%i",&to);

  arrayString new = substring(str, from, to);
  
  printf("The original string was: \n");
  for(int i = 0; i < lenCh(str); i++) {
    printf("%c",str[i]);
  }
  printf("\nAnd the substring is: \n");

  for(int i = 0; i < lenCh(new); i++) {
    printf("%c",new[i]);
  }
  printf("\n");
  free(new);
  free(str);

  return 0;
}
