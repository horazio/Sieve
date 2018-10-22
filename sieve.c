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


int sieve(int target){
  int len;
  if(target == 1){
    return 2;
  }
  target--;
  if(target < 5000){
    len = .65 * target * log(target) + 100;
  }else{
    len = .575 * target * log(target); 
  }  
  char * nums = calloc(len, 1);

  int point = -1;
  int pointy;
  int cap = sqrt(len);
  
  while(++point <= len){
    if(nums[point] == 0 && !--target){
      return point * 2 + 3;
    }
    if(point <= cap){
      pointy = point;
      while((pointy += point * 2 + 3) < len){
	if(nums[pointy] == 0){
	  nums[pointy] = 1;
	}
      }
    }
  }

  return 0;
}
