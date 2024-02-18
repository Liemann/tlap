#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void mostFreq(int arr[], int size) {
  int mode;
  int current = 1;
  int longest = 0;
  int i = 0;
  bool once = true;
  if(size == 1) {
    printf("The mode is: %i\n",arr[0]);
    return;
  }
  qsort(arr,size,sizeof(int),cmpfunc);
  mode = arr[0];
  for(int i = 1; i < size; i++) {
    // printf("This is int #%i\n",arr[i]);
    if(arr[i] == arr[i-1]) {
      current++;
    } else {
      if(current > 1) {
        once = false;
      }
      if(current > longest) {
        mode = arr[i-1];
        longest = current;
        current = 1;
      }
    }
  }
  if(once) {
    printf("There was no mode!\n");
  } else {
    printf("The mode is: %i\n",mode);
  }
}

int main() {
  int a[10] = {1,10,2,3,4,5,6,7,9,9};
  mostFreq(a,sizeof(a)/sizeof(int));
  return 0;
}
