#include <stdio.h>
#include <stdbool.h>

int sumIsbn(char isbn[]){
  int sum = 0;
  for(int i = 0; i < 13; i++) {
    sum += (int)(isbn[i]-'0');
  }
  return sum;
}

int lefts(int sum){
  int num = 10;
  while(num - sum < 0) {
    num += 10;
  }
  return num - sum;
}

bool validate(char isbn[], char vbit) {
  int sum = sumIsbn(isbn) + (int)(vbit - '0');
  return (sum % 10 == 0);
}

int main(){
  printf("Would you like to generate valid bit or check validation?\n");
  printf("g for generate or c for check\n");
  char choice;
  scanf("%s", &choice);

  if(choice == 'g') {
    printf("Enter ISBN:\n");

    char isbn[13];
    scanf("%s", isbn);

    int middle = sumIsbn(isbn);

    int left = lefts(middle);

    printf("The validation digit is %i\n", left);
  } else if(choice == 'c') {
    printf("Enter ISBN and a validation digit:");
    char isbnn[13];
    char bit;
    scanf("%s", isbnn);
    scanf(" %c",&bit);
    bool valid = validate(isbnn,bit);
    if(valid) {
      printf("It's valid!\n");
    } else {
      printf("It's not valid!\n");
    }
  }
}
