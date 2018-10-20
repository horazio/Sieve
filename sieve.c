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
  int len;
  if(target > 5000){
    len = 1.3 * target * log(target) + 10;
  }else{
    len = 1.15 * target * log(target); 
  }  
  char * nums = calloc(len, 1);

  int point = 0;
  int pointy;
  int count = 0;
  int cap = sqrt(len);
  
  while(point <= len){
    if(nums[point] == 0 && !target--){
	return point + 2;
    }
    if(point <= cap){
      pointy = point;
      while((pointy += point + 2) < len){
	if(nums[pointy] == 0){
	  nums[pointy] = 1;
	}
      }
    }
    point++;
  }

  return 0;
}
