#include <stdio.h>

int main() {
  for(int row = 0; row < 4; row++) {
    for(int k = 0; k < row; k++) {
      printf(" ");
    }
    for(int i = 0; i < 8 - row*2; i++) {
      printf("#");
    }
    for(int j = 0; j < row; j++) {
      printf(" ");
    }
    printf("\n");
  }
}


//########
// ######
//  ####
//   ##
