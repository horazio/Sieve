#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void print(char * nums, int len){
  int i = 0;
  printf("\n\n");
  while( i < len){
    printf("%d", nums[i]);
    i++;
  }
  printf("\n\n");
}


int sieveer(int target){
  target++;
  int len = 1.3 * target * log(target) + 10;
  char * nums = calloc(len, 1);

  int point = 2;
  nums[1] = 1;
  int pointy;
  
  int cap = pow(target, .5);
 
  while(point <= target){
    pointy = point;
    while(pointy < len){
      pointy += point;
      nums[pointy] = 1;
    }
    point++;
  }
  //print(nums, len);
  // printf("%d", nums[0]);
  point = 1;
  pointy = 0;
  while(point < target){
    pointy++;
    if(!nums[pointy]){
      point++;
      //printf("%d ", pointy);
    }
  }
  
  return pointy;
}