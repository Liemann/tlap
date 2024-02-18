#include <stdio.h>
#include <stdbool.h>

bool sorted(int arr[], int len) {
  if(len == 1) {
    return true;
  }
  for(int i = 1; i < len; i++) {
    if(arr[i] < arr[i-1]) {
      return false;
    }
  }
  return true;
}

int main() {
  int a[] = {1,2,3,4,5};
  int b[] = {1,2,3,4,5,6,8,7};
  int c[] = {2,1};
  int d[] = {4};

  if(sorted(a,5)){printf("Array a is sorted!\n");}
  if(sorted(b,8)){printf("Array b is sorted!\n");}
  if(sorted(c,2)){printf("Array c is sorted!\n");}
  if(sorted(d,1)){printf("Array d is sorted!\n");}
  return 0;
}
