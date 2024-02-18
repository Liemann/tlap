#include <stdio.h>

int main() {
  for(int row = 0; row < 4; row++) {
    for(int k = 0; k < 3 - row; k++) {
      printf(" ");
    }
    for(int i = 0; i < 2 + row*2; i++) {
      printf("#");
    }
    printf("\n");
  }
  for(int v = 0; v < 4; v++) {
    for(int i = 0; i < v; i++) {
      printf(" ");
    }
    for(int j = 0; j < 8 - 2*v; j++) {
      printf("#");
    }
    printf("\n");
  }
}

//   ## 
//  ####
// ######
//########
//########
// ######
//  ####
//   ##
