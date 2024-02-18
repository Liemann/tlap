#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int agentID;
  float sales[12];
} agent;

#define NUM_AGENTS 5

float mean(agent a) {
  int j = 0;
  int end;
  while(a.sales[j] != -1) {
    if(j == 11) {
      return (a.sales[5] + a.sales[6])/2;
    }
    j++;
  }
  if(j == 0) {
    return 0;
  }
  end = j-1;
  if(end%2 == 0) {
    return a.sales[end/2];
  } else {
    return (a.sales[end/2] + a.sales[end/2 + 1])/2;
  }

  // IF CMPFUNC WOULD PUT -1 IN THE BEGINNING!!!!
  // int j = 0;
  // int start;
  // while(a.sales[j] == -1) {
  //   if(j == 11) {
  //     return 0;
  //   }
  //   j++;
  // }
  // start = j;
  // // Unneven, get middle index value
  // if(start%2 == 1) {
  //   return a.sales[(11+start)/2];
  // } else {
  //   return (a.sales[(11+start)/2+1] + a.sales[(11-start)/2+2])/2;
  // }
}

float average(agent a) {
  int working = 0;
  float mean = 0;
  for(int i = 0; i < 12; i++) {
    if(a.sales[i] != -1) {
      mean += a.sales[i];
      working++;
    }
  }
  return mean/working;
}

agent agents[NUM_AGENTS] = {
  {1, {4,3,2,1,7,5,6,9,8,21,10,10}},
  {2, {2,2,2,2,2,2,2,2,2,2,2,2}},//       34         67
  {3, {-1,3456,1234,756,1234,867,234,456,-1,567,234,-1}},
  {4,{-1,-1,-1,-1,1234,234,345,675,86,234,567,123}},
  {5,{-1,-1,-1,-1,1,2,3,4,5,6,7,-1}}
};

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main() {
  // Sort each agents monthly sales
  for(int i = 0; i < NUM_AGENTS; i++) {
    qsort(agents[i].sales, 12, sizeof(int), cmpfunc);
    if(i == 2) {
      for(int k = 0; k < 12; k++) {
        printf("Agent %i: %f\n",i+1,agents[i].sales[k]);
      } 
    }
  }

  float highestMean = mean(agents[0]);
  agent meanAgent = agents[0];
  for(int i = 1; i < NUM_AGENTS; i++) {
    if(mean(agents[i]) > highestMean) {
      highestMean = mean(agents[i]);
      meanAgent = agents[i];
    }
  }

  float highestAvg = average(agents[0]);
  agent avgAgent = agents[0];
  
  for(int i = 1; i < NUM_AGENTS; i++) {
    if(average(agents[i]) > highestAvg) {
      highestAvg = average(agents[i]);
      avgAgent = agents[i];
    }
  }
  printf("The highest mean was: %f which belonged to agent with ID: %i\n",highestMean, meanAgent.agentID);
  printf("The highest average was: %f which belonged to agent with ID: %i\n",highestAvg, avgAgent.agentID);
  return 0;
}
