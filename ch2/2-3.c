#include <stdio.h>

int main() {
  for(int row = 0; row < 4; row++) {
    for(int i = 0; i < row; i++) {
      printf(" ");
    }
    for(int i = 0; i < row+1; i++) {
      printf("#");
    }
    for(int i = 0; i < 12 -row*4; i++) {
      printf(" ");
    }
    for(int i = 0; i < row+1; i++){
      printf("#");
    }
    printf("\n");
  }

  for(int row = 0; row < 4; row++) {
    for(int i = 0; i < 3-row; i++) {
      printf(" ");
    }
    for(int i = 0; i < 4-row; i++) {
      printf("#");
    }
    for(int i = 0; i < 4*row; i++){
      printf(" ");
    }
    for(int i = 0; i < 4-row; i++){
      printf("#");
    }
  printf("\n");
  }


  for(int row2 = 0; row2 < 4; row2++) {

  }
}

//#            #
// ##        ##
//  ###    ###
//   ########
//   ########
//  ###    ###
// ##        ##
//#            #
