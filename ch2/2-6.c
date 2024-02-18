#include <stdio.h>

int power(int x, int y) {
  int ret = 1;
  for(int i = 0; i < y; i++) {
    ret *= x;
  }
  return ret;
}

int dec2bin(int dec){
  int bin = 0;
  int counter = 1;
  while(dec > 0) {
    bin += counter*(dec%2);
    dec = dec/2;
    counter *= 10;
  }
  return bin;
}

int bin2dec(int bin){
  int dec = 0;
  int counter = 0;
  while(bin > 0) {
    dec += (bin%10) * power(2, counter);
    bin = bin/10;
    counter += 1;
  }
  return dec;
}

int bin2hex(int bin) {
  return 0;
}

int hex2bin(int hex) {
  return 0;
}

int hex2dec(int hex) {
  return 0;
}

int dec2hex(int dec) {
  return 0;
}

int main(){
  printf("Do you want to convert from bin or from dec?\n");
  char choice;
  scanf("%c", &choice);
  if(choice == 'b') {
    int bin;
    printf("Enter a bin:\n");
    scanf("%i", &bin);
    int dec = bin2dec(bin);
    printf("Here is your dec: %i\n", dec);
  }else if(choice == 'd') {
    int dec;
    printf("Enter a dec:\n");
    scanf("%i", &dec);
    int bin = dec2bin(dec);
    printf("Here is your bin: %i\n", bin);
  }
}
