#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int agentID;
  float sales[12];
} agent;

#define NUM_AGENTS 3

float mean(agent a) {
  return (a.sales[5] + a.sales[6])/2;

}

agent agents[NUM_AGENTS] = {
  {1, {4,3,2,1,7,5,6,9,8,21,11,10}},
  {2, {2,2,2,2,2,2,2,2,2,2,2,2}},
  {3, {214,3456,1234,756,1234,867,234,456,34,567,234,67}}
};

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main() {
  // Sort each agents monthly sales
  for(int i = 0; i < NUM_AGENTS; i++) {
    qsort(agents[i].sales, 12, sizeof(int), cmpfunc);
  }
  float highestMean = mean(agents[0]);
  agent meanAgent = agents[0];
  for(int i = 1; i < NUM_AGENTS; i++) {
    if(mean(agents[i]) > highestMean) {
      highestMean = mean(agents[i]);
      meanAgent = agents[i];
    }
  }
  printf("The highest mean was: %f which belonged to agent with ID: %i\n",highestMean, meanAgent.agentID);
  return 0;
}
