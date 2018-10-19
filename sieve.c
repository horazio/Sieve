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
  //------------make seive-------------

  int len = 1.3 * target * log(target) + 10;
  char * nums = calloc(len, 1);


  int point = 0;
  int pointy;
  int count = 0;
  int cap = pow(target, .5);
  
  while(point < len){
    pointy = point;
    if(nums[point] == 0){
      count++;
      if(count == target){
	//print(nums, len);
	return point + 2;
      }
    }

    while(pointy + point < len){
      pointy += point + 2;
      nums[pointy] = 1;
    }
    point++;
  }

  printf("failed------------ :(");
  //print(nums, len);
  /*
  //------------count primes-------------

  point = 0;
  pointy = 0;
  while(point < target){
    pointy++;
    if(!nums[pointy]){
      point++;
      //printf("%d ", pointy);
    }
  }
  */
  return pointy;
}
