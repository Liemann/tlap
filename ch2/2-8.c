#include <limits.h>
#include <stdio.h>
// Link for formulas:
//https://calculator.name/baseconvert/pentadecimal/duodecimal/1A2
// Helper functions
int power(int x, int y) {
  int ret = 1;
  for(int i = 0; i < y; i++) {
    ret *= x;
  }
  return ret;
}

int numPlaces (int n) {
  int r = 1;
  if (n < 0) n = (n == INT_MIN) ? INT_MAX: -n;
  while (n > 9) {
    n /= 10;
    r++;
  }
  return r;
}

void convert(int to, int from, int num) {
  int numC = 0;
  int numUse = 0;
  if(to == from) {
    numC = num;
  } else if(to < 11 && from < 11) {
    // First convert into dec
    if(from != 10) {
      int len = numPlaces(num);
      char digits[len];
      sprintf(digits,"%d", num);
      for(int i = 0; i < len; i++) {
        numUse += (digits[len-1-i] - '0') * power(from,i);
      }
    } else {
      // If num is already in base 10 do nothing
      numUse = num;
    }
    // Then do remainder
    int counter = 1;
    while(numUse > 0) {
      numC += counter*(numUse%to);
      numUse = numUse/to;
      counter *= 10;
    }
  } else {
  }
  printf("Here is %i in base %i converted to base %i: %i\n", num, from, to, numC);
}

//TODO I/O is getting messed up here...
void convertBig(int from, int to) {
  // Conversion from/to base greater than 10
  // Loop through the string
  char letr;
  int numUse = 0;
  printf("Enter the number digit by digit and end with 'x':\n");
  while(letr != 'x') {
    printf("Please enter a digit:\n");
    scanf(" %c", &letr);
    printf("This is letr %c\n",letr);
    // Conv to base 10
      switch(letr) {
        case '0':
          numUse = numUse * from + 0;
          break;
        case '1':
          numUse = numUse * from + 1;
          break;
        case '2':
          numUse = numUse * from + 2;
          break;
        case '3':
          numUse = numUse * from + 3;
          break;
        case '4':
          numUse = numUse * from + 4;
          break;
        case '5':
          numUse = numUse * from + 5;
          break;
        case '6':
          numUse = numUse * from + 6;
          break;
        case '7':
          numUse = numUse * from + 7;
          break;
        case '8':
          numUse = numUse * from + 8;
          break;
        case '9':
          numUse = numUse * from + 9;
          break;
        case 'A':
          numUse = numUse * from + 10;
          break;
        case 'B':
          numUse = numUse * from + 11;
          break;
        case 'C':
          numUse = numUse * from + 12;
          break;
        case 'D':
          numUse = numUse * from + 13;
          break;
        case 'E':
          numUse = numUse * from + 14;
          break;
        case 'F':
          numUse = numUse * from + 15;
          break;
      }
    printf("This is numUse: %i\n", numUse);
  }
     
    // numUse will be base 10
    printf("This is the value converted to base 10 from base %i: %i\n",from, numUse);
    
    // Calc buffer len
    int bufferlen = 0;
    int numCopy = numUse;
    while(numCopy > 0) {
      bufferlen += 1;
      numCopy = numCopy/to;
    }
    // Then do remainder
    int counter = 1;
    char buffer[bufferlen];
    int buffcount = 0;
    // Add corresponding base 10 value into buffer
    while(numUse > 0) {
      switch(numUse%to) {
        case 10:
          buffer[buffcount] = 'A';
          break;
        case 11:
          buffer[buffcount] = 'B';
          break;
        case 12:
          buffer[buffcount] = 'C';
          break;
        case 13:
          buffer[buffcount] = 'D';
          break;
        case 14:
          buffer[buffcount] = 'E';
          break;
        case 15:
          buffer[buffcount] = 'F';
          break;
        default:
          buffer[buffcount] = numUse%to + '0';
          break;
      }
      buffcount += 1;
      numUse = numUse/to;
      counter *= 10;
    }
    // Iterate through buffer in reverse and print each char
    printf("This is from base 10 to base %i:\n",to);
    for(int i = 0; i < bufferlen; i++) {
      printf("%c",buffer[bufferlen-1-i]);
    }
    printf("\n");
}

int main() {
  int from;
  int to;
  int num;

  printf("What base to you want to convert from:\n");
  scanf("%i",&from);
  if(from > 16) {
    printf("Conversion from base greater than 16 is not allowed\n");
    return 1;
  } else if (from < 2) {
    printf("Conversion from base less than 2 is not allowed\n");
    return 1;
  }
  printf("And what base do you want to convert to:\n");
  scanf("%i",&to);
  if(to > 16) {
    printf("Conversion to base greater than 16 is not allowed\n");
    return 1;
  } else if (to < 2) {
    printf("Conversion to base less than 2 is not allowed\n");
    return 1;
  }
  if(to < 11 && from < 11) {
    printf("Enter a number in base %i:\n",from);
    scanf("%i",&num);
    convert(to, from, num);
  } else {
    convertBig(from, to);
  }
  return 0;
}
