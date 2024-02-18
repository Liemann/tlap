#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Helper functions
int power(int x, int y) {
  int ret = 1;
  for(int i = 0; i < y; i++) {
    ret *= x;
  }
  return ret;
}

char hexL(int rem) {
  switch(rem) {
    case 10:
      return 'A';
      break;
    case 11:
      return 'B';
      break;
    case 12:
      return 'C';
      break;
    case 13:
      return 'D';
      break;
    case 14:
      return 'E';
      break;
    case 15:
      return 'F';
      break;
  }
  return 'x';
}
int numPlaces (int n) {
    if (n == 0) return 1;
    return floor(log10(abs(n))) + 1;
}

// Dec to bin and hex
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

void dec2hex(int dec) {
  char hex[numPlaces(dec)];
  int counter = 0;
  int rem;
  while (dec > 0) {
    rem = dec%16;
    if(rem > 9) {
      hex[counter] = hexL(rem);
    } else {
      char a[2];
      sprintf(a,"%d",rem);
      hex[counter] = a[0];
    }
    dec = dec/16;
    counter += 1;
  }
  for(int i = 0; i < counter; i++) {
    printf("%c", hex[counter - i - 1]);
  }
  printf("\n");
}

// Bin to dec and hex
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

void bin2hex(int bin) {
  char bins[numPlaces(bin)];
  sprintf(bins,"%d", bin);
  // for(int i = 0; i < numPlaces(bin); i++) {
  //   printf("%c", bins[i]);
  // }

  int finallen;
  int add = 0;

  // Pad array to be of length 4n
  if(numPlaces(bin)%4 != 0){
    add = 4 - numPlaces(bin)%4;
    finallen = add + numPlaces(bin);
  } else {
    finallen = numPlaces(bin);
  }

  // Here is the padded bin as a char array
  char new[finallen];
  for(int i = 0; i < numPlaces(bin); i++) {
    new[finallen - numPlaces(bin) + i] = bins[i];
  }
  for(int i = 0; i < add; i++) {
    new[i] = '0';
  }

  //FOR TESTING
  // printf("Thisis whats in new\n");
  // for(int i = 0; i < sizeof(new)/sizeof(new[0]); i++) {
  //   printf("%c\n", new[i]);
  // }

  char hex[finallen/4];
  char four[4];
  //numPlaces is messing up!!!
  // printf("This is nums in bin: %i\n", numPlaces(bin));
  // printf("This is nums in bins: %lu\n", sizeof(bins)/sizeof(bins[0]));
  // printf("This is finallen: %i\n", finallen);

  for(int i = 0; i < finallen/4; i++){
    four[0] = new[i*4];
    four[1] = new[i*4+1];
    four[2] = new[i*4+2];
    four[3] = new[i*4+3];


    // printf("This is iter %i\n", i);
    // printf("And this is four array\n");
    // for(int a = 0; a < 4; a++) {
    //   printf("%c\n",four[a]);
    //   printf("And as an int: %i\n",four[a]-'0');
    // }



    int fournum = (four[0] - '0') * 1000 + (four[1] - '0') * 100 + (four[2] - '0') * 10 + (four[3] - '0');
    // printf("this is the fournum:\n");
    // printf("%i\n", fournum);
    switch (fournum) {
      case 0:
        hex[i] = '0';
        break;
      case 1:
        hex[i] = '1';
        break;
      case 10:
        hex[i] = '2';
        break;
      case 11:
        hex[i] = '3';
        break;
      case 100:
        hex[i] = '4';
        break;
      case 101:
        hex[i] = '5';
        break;
      case 110:
        hex[i] = '6';
        break;
      case 111:
        hex[i] = '7';
        break;
      case 1000:
        hex[i] = '8';
        break;
      case 1001:
        hex[i] = '9';
        break;
      case 1010:
        hex[i] = 'A';
        break;
      case 1011:
        hex[i] = 'B';
        break;
      case 1100:
        hex[i] = 'C';
        break;
      case 1101:
        hex[i] = 'D';
        break;
      case 1110:
        hex[i] = 'E';
        break;
      case 1111:
        hex[i] = 'F';
        break;
    }
    // printf("And this is what is in hex[i]: %c\n",hex[i]);
  }
  printf("Here is your hex:\n");
  for(int i = 0; i < finallen/4; i++) {
    printf("%c", hex[i]);
  }
  printf("\n");

}

// Hex to dec and bin
int hex2bin(char hexCh, int bin) {
  switch(hexCh) {
    case '0':
      bin = bin * 10000;
      break;
    case '1':
      bin = bin * 10000 + 1;
      break;
    case '2':
      bin = bin * 10000 + 10;
      break;
    case '3':
      bin = bin * 10000 + 11;
      break;
    case '4':
      bin = bin * 10000 + 100;
      break;
    case '5':
      bin = bin * 10000 + 101;
      break;
    case '6':
      bin = bin * 10000 + 110;
      break;
    case '7':
      bin = bin * 10000 + 111;
      break;
    case '8':
      bin = bin * 10000 + 1000;
      break;
    case '9':
      bin = bin * 10000 + 1001;
      break;
    case 'A':
      bin = bin * 10000 + 1010;
      break;
    case 'B':
      bin = bin * 10000 + 1011;
      break;
    case 'C':
      bin = bin * 10000 + 1100;
      break;
    case 'D':
      bin = bin * 10000 + 1101;
      break;
    case 'E':
      bin = bin * 10000 + 1110;
      break;
    case 'F':
      bin = bin * 10000 + 1111;
      break;
  }
  return bin;
}

int hex2dec(char hexCh, int dec) {
  switch(hexCh) {
    case '0':
      dec = dec*16 + 0;
      break;
    case '1':
      dec = dec * 16 + 1;
      break;
    case '2':
      dec = dec * 16 + 2;
      break;
    case '3':
      dec = dec * 16 + 3;
      break;
    case '4':
      dec = dec * 16 + 4;
      break;
    case '5':
      dec = dec * 16 + 5;
      break;
    case '6':
      dec = dec * 16 + 6;
      break;
    case '7':
      dec = dec * 16 + 7;
      break;
    case '8':
      dec = dec * 16 + 8;
      break;
    case '9':
      dec = dec * 16 + 9;
      break;
    case 'A':
      dec = dec * 16 + 10;
      break;
    case 'B':
      dec = dec * 16 + 11;
      break;
    case 'C':
      dec = dec * 16 + 12;
      break;
    case 'D':
      dec = dec * 16 + 13;
      break;
    case 'E':
      dec = dec * 16 + 14;
      break;
    case 'F':
      dec = dec * 16 + 15;
      break;
  }
  return dec;
}

int main(){
  printf("Do you want to convert from bin (b), dec (d) or hex (h)?\n");
  char from;
  char to;
  scanf("%c", &from);
  scanf(" %c",&to);
  if(from == 'b' && to == 'd') {
    int bin;
    printf("Enter a bin:\n");
    scanf("%i", &bin);
    int dec = bin2dec(bin);
    printf("Here is your dec: %i\n", dec);
  }else if(from == 'd' && to == 'd') {
    int dec;
    printf("Enter a dec:\n");
    scanf("%i", &dec);
    int bin = dec2bin(dec);
    printf("Here is your bin: %i\n", bin);
  }else if(from == 'b'&& to == 'h') {
    int bin;
    printf("Enter a bin:\n");
    scanf("%i", &bin);
    bin2hex(bin);
  }else if(from == 'd' && to == 'h'){
    int dec;
    printf("Enter a dec:\n");
    scanf("%i", &dec);
    printf("Here is your hex:\n");
    dec2hex(dec);
  }else if(from == 'h' && to == 'b') {
    int bin = 0;
    char hexCh;
    while(hexCh != 'x') {
      printf("Enter a hex followed by enter, if done, enter 'x':\n");
      scanf("%c",&hexCh);
      bin = hex2bin(hexCh, bin);
    }
    printf("Here is your bin: %i\n", bin);

  }else if(from == 'h' && to == 'd') {
    int dec = 0;
    char hexCh;
    while(hexCh != 'x') {
      printf("Enter a hex followed by enter, if done, enter 'x':\n");
      scanf("%c",&hexCh);
      dec = hex2dec(hexCh, dec);
    }
    printf("Here is your dec: %i\n", dec);
  }
}
