#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "func.h"

int main(){
	Matrix matr = {0, NULL};
	if (input(&matr)==0){
		printf("%s\n","End of file occured");
		return 1;
	}
	int *sums;
	sums = (int *)malloc(sizeof(int)*matr.lines);
	sum(matr,sums);
	int maxsum = max(sums, matr.lines);
	int minsum = min(sums, matr.lines);
	float *res;
	res = (float *)malloc(sizeof(float)*matr.lines);
	finalfunc(res,sums,matr.lines,minsum,maxsum);
	output("Source matrix", matr);
	printf("Result: \n");
	printf(" ");
	for (int i = 0; i<matr.lines; i++){
		printf("b[%d] = %lf \n ",i+1,res[i]);
	}
	printf("%ld", sizeof(res));
	erase(&matr);
	free(sums);
	free(res);
	return 0;
}
 // сделать динамические массивы
