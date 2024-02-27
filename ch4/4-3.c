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

arrayString concat(arrayString s1, arrayString s2) {
  int s1len = lenCh(s1);
  int s2len = lenCh(s2);
  arrayString new = malloc((s1len+s2len+1) * sizeof(char));
  for(int i = 0; i < s1len; i++) {
    new[i] = s1[i];
  }
  for(int i = 0; i < s2len; i++) {
    new[s1len+i] = s2[i];
  }
  new[s1len+s2len] = 0;
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
  arrayString new = malloc(sizeof(char));
  int count = 0;
  while(count < lenCh(source)) {
    for(int j = 0; j < lenCh(replaceIndexes); j++) {
      if(count == replaceIndexes[j] - '0') {
        new = concat(new, replaceText);
        count += lenCh(target);
      } else {
        arrayString ch = malloc(2*sizeof(char));
        ch[0] = source[count];
        ch[1] = 0;
        new = concat(new, ch);
        free(ch);
        count++;
      }
    }
    
  }
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
  
  arrayString str2 = malloc(9 * sizeof(char));
  str2[0] = 'a';
  str2[1] = 'b';
  str2[2] = 'a';
  str2[3] = 'b';
  str2[4] = 'a';
  str2[5] = 'b';
  str2[6] = 'a';
  str2[7] = 'b';
  str2[8] = 0;
  
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

  str = replaceString(str2, target, replaceText);

  for(int i = 0; i < lenCh(str); i++) {
    printf("%c",str[i]);
  }
  printf("\n");


  return 0;
}
