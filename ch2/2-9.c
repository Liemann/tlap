#include <stdio.h>

// Helper functions
#define MAX(a,b) (a > b) ? a : b
#define MIN(a,b) (a < b) ? a : b

int main() {
  int words = 0;
  int longest = 0;
  int mostVow = 0;
  int count = 0;
  int vowCount = 0;
  int brk = 0;
  char vowels[10] = {'a','A','e','E','i','I','o','O','u','U'};
  char letr;

  // Seems like you're able to enter an entire sentence at once!
  printf("Enter a sentence ended by either '.', '!' or '?'\n");
  while(1){//letr != '.' && letr != '!' && letr != '?') 
    scanf("%c", &letr);
    if(letr == '.' || letr == '!' || letr == '?') {
      words++;
      longest = MAX(count, longest);
      break;
    }
    // printf("letr is: %c\n",letr);
    if(letr != ' ' && letr != ',') {
      count++;
      // Added for vowel counting:
      for(int i = 0; i < 10; i++) {
        if(vowels[i] == letr) {
          vowCount++;
        }
      }
      //printf("Count is inc to: %i\n",count);
    } else {
      words++;
      // printf("Words is inc to: %i\n",words);
      longest = MAX(count, longest);
      count = 0;
      mostVow = MAX(vowCount, mostVow);
      vowCount = 0;
      // printf("And longest is now: %i",longest);
    }
  }
  printf("There are %i words in this sentence and the longest word was %i characters long!\n",words,longest);
  printf("And the word with the most vowels had %i vowels!\n",mostVow);
return 0;
}


//TODO
//count # of words, DONE!
//identify length of the longest word, DONE!
//greatest number of vowels in a word
