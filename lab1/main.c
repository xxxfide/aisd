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
	int sums[matr.lines];
	sum(matr,sums);
	int maxsum = max(sums, matr.lines);
	int minsum = min(sums, matr.lines);
	double res[matr.lines];
	finalfunc(res,sums,matr.lines,minsum,maxsum);
	output("Source matrix", matr);
	printf("Result: \n");
	printf(" ");
	for (int i = 0; i<matr.lines; i++){
		printf("b[%d] = %lf \n ",i+1,res[i]);
	}
	printf("%ld", sizeof(res));
	erase(&matr);
	return 0;
}
 // сделать динамические массивы
