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
}

// If source is abcdabee, target is ab and replaceText is xyz, source becomes xyzcdxyzee
void replaceString(arrayString source, arrayString target, arrayString replaceText) {
  // Add start of index to be replaced
 arrayString replaceIndexes; 
  for(int i = 0; i < lenCh(source); i++) {
    int step = 0;
    while(source[i + step] == target[step] && step < lenCh(source) && step < lenCh(target)) {
      if(step == lenCh(target) - 1) {
        printf("%i\n",i);
        append(replaceIndexes, i);
      }
      step++;
    }
  }
  append(replaceIndexes, 0);
  // Now all indexes that are the starting point of target in source should be in replaceIndexes
//
  arrayString new = malloc((lenCh(replaceIndexes)*lenCh(replaceText) + (lenCh(source) - lenCh(target)*lenCh(replaceIndexes)) + 1) * sizeof(char));
  int count = 0;
  while(count < lenCh(source)) {
    for(int j = 0; j < lenCh(replaceIndexes); j++) {
      if(count == replaceIndexes[j]) {
        for(int i = 0; i < lenCh(replaceText); i++) {
          new[count+i] = replaceText[i];
        }
      } else {
        new[count] = source[count];
      }
    }
    count++;
  }
}

int main() {
  arrayString str = malloc(9 * sizeof(char));
  str[0] = 'a';
  str[1] = 'b';
  str[2] = 'c';
  str[3] = 'd';
  str[4] = 'a';
  str[5] = 'b';
  str[6] = 'e';
  str[7] = 'e';
  str[8] = 0;
  
  arrayString target = malloc(3 * sizeof(char));
  target[0] =  'a';
  target[1] =  'b';
  target[2] =  0;

  arrayString replaceText = malloc(4 * sizeof(char));
  replaceText[0] =  'x';
  replaceText[1] =  'y';
  replaceText[2] =  'z';
  replaceText[3] =  0;


  printf("The original string was: \n");
  for(int i = 0; i < lenCh(str); i++) {
    printf("%c",str[i]);
  }
  printf("\nAnd the substring is: \n");

  replaceString(str, target, replaceText);

  for(int i = 0; i < lenCh(str); i++) {
    printf("%c",str[i]);
  }
  printf("\n");


  return 0;
}
