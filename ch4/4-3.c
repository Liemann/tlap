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

arrayString append(arrayString str, char c) {
  int oldLen = lenCh(str);
  arrayString new = malloc((oldLen + 2) * sizeof(char));
  for(int i = 0; i < oldLen; i ++) {
    new[i] = str[i];
  }
  new[oldLen] = c;
  new[oldLen + 1] = 0;
  return new;
}

// If source is abcdabee, target is ab and replaceText is xyz, source becomes xyzcdxyzee
arrayString replaceString(arrayString source, arrayString target, arrayString replaceText) {
  // Add start of index to be replaced
  arrayString replaceIndexes = malloc(sizeof(char)); 

  for(int i = 0; i < lenCh(source); i++) {
    int step = 0;
    while(source[i + step] == target[step] && step < lenCh(source) && step < lenCh(target)) {
      if(step == lenCh(target) - 1) {
        printf("%i\n",i);
        replaceIndexes = append(replaceIndexes, i + '0');
      }
      step++;
    }
  }
  replaceIndexes = append(replaceIndexes, 0);
  printf("Len of replaceIndexes: %i\n",lenCh(replaceIndexes));
  for(int i = 0; i < lenCh(replaceIndexes); i++) {
    printf("ReplaceIndexex: %c\n",replaceIndexes[i]);
  }
  // Now all indexes that are the starting point of target in source should be in replaceIndexes
//
  arrayString new = malloc((lenCh(replaceIndexes)*lenCh(replaceText) + (lenCh(source) - lenCh(target)*lenCh(replaceIndexes)) + 1) * sizeof(char));
  printf("This is the len of the new array: %i\n",lenCh(replaceIndexes)*lenCh(replaceText) + (lenCh(source) - lenCh(target)*lenCh(replaceIndexes)) + 1);
  printf("Target: %i\n",lenCh(target));
  printf("Source: %i\n",lenCh(source));
  printf("ReplaceText: %i\n",lenCh(replaceText));
  printf("ReplaceIndexes: %i\n",lenCh(replaceIndexes));


  int count = 0;
  while(count < lenCh(source)) {
    for(int j = 0; j < lenCh(replaceIndexes); j++) {
      if(count == replaceIndexes[j] - '0') {
        for(int i = 0; i < lenCh(replaceText); i++) {
          new[count+i] = replaceText[i];
        }
      } else {
        new[count] = source[count];
      }
    }
    count++;
  }
  new[count+1] = 0;
  return new;
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

  str = replaceString(str, target, replaceText);

  for(int i = 0; i < lenCh(str); i++) {
    printf("%c",str[i]);
  }
  printf("\n");


  return 0;
}
