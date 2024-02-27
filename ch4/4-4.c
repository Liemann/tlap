#include <stdio.h>
#include <stdlib.h>

typedef int * arrayString;

arrayString append(arrayString str, char c) {
  int oldLen = str[0];
  arrayString new = malloc((oldLen + 2) * sizeof(char));
  for(int i = 1; i < oldLen + 1; i++) {
    new[i] = str[i];
  }
  new[0] = oldLen + 1;
  new[oldLen + 1] = c-'0';
  return new;
}

arrayString concat(arrayString s1, arrayString s2) {
  int s1len = s1[0];
  int s2len = s2[0];
  arrayString new = malloc((s1len+s2len+1) * sizeof(char));
  for(int i = 1; i < s1len+1; i++) {
    new[i] = s1[i];
  }
  for(int i = 1; i < s2len+1; i++) {
    new[s1len+i] = s2[i];
  }
  new[0] = s1len+s2len;
  return new;
}

char charAt(arrayString str, int index) {
  if(index > str[0] || index == 0) {
    return 0;
  }
  return str[index] + '0';
}

void output(arrayString str) {
  for(int i = 1; i < str[0] + 1; i++) {
    printf("%c",str[i] + '0');
  }
  printf("\n");
}

int main() {
  arrayString str = malloc(sizeof(char));
  str[0] = 0;
  arrayString ap = append(str, 'c');
  output(ap);
  arrayString con = malloc(sizeof(char));
  con[0] = 0;
  con = append(con, 'a');
  con = append(con, 'b');
  ap = concat(ap, con);
  output(ap);
  char c = charAt(ap, 2);
  printf("Char at: %c\n",c);

  return 0;
}
