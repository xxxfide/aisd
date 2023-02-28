#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int getInt(int *a){
	int n;
	do{
		n = scanf("%d",a,sizeof(int));
		if(n<0)
			return 0;
		if (n==0){
			printf("%s\n","Error input");
			scanf("%*c",0);
		}
	} while (n == 0);
	return 1;
}

int input(Matrix *rm){
	const char *pr = "";
	int m;
	int i,j;
	int *p;
	do{
		printf("%s\n",pr);
		printf("Enter nubmer of lines: --> ");
		pr = "You are wrong; repeat";
		if(getInt(&m)==0)
			return 0;
	} while(m<1);
	rm->lines = m;

	rm->arrline = (Line *)calloc(m,sizeof(Line));
	for (i=0; i < rm->lines; ++i){
		pr = "";
		do{
			printf("%s\n",pr);
			printf("Enter number of items in line %d: --> ", i+1);
			pr = "You are wrong; repeat";
			if(getInt(&m)==0){
				rm->lines = i;
				erase(rm);
				return 0;
			}
		} while (m<1);
		rm->arrline[i].n = m;
		p = (int *)malloc(sizeof(int)*m);
		rm->arrline[i].arritem = p;

		printf("Enter items for matrix line #%d: \n",i+1);
		for (j=0; j<m;++j,++p)
		if (getInt(p) == 0){
			rm->lines = i+1;
			erase(rm);
			return 0;
		}
	}
	return 1;
}

void erase(Matrix *a){
	int i;
	for (i=0; i< a->lines; ++i)
		free(a->arrline[i].arritem);
	free(a->arrline);
	a->lines = 0;
	a->arrline = NULL;
}

void output(const char *msg, Matrix a){
	int i,j;
	int *p;
	printf("%s: \n",msg);
	for (i=0; i<a.lines; ++i){
		p = a.arrline[i].arritem;
		for(j=0;j<a.arrline[i].n;++j,++p)
			printf("%10d",*p);
		printf("\n");
	}
}

int sum (Matrix a, int res[]){
	int sum = 0;
	int i,j;
	for (i=0; i<a.lines;++i){
		for (j=0;j<a.arrline->n;j++){
			sum += a.arrline[i].arritem[j];
		}
		res[i] = sum;
		sum = 0;
	}
	return 0;
}

int max(int a[], int m){
	int res = *a;
	for (;m-- > 0; ++a)
	if (*a > res)
		res = *a;
	return res;
}

int min(int a[], int m){
	int res = *a;
	for (;m-- > 0; ++a)
	if (*a < res)
		res = *a;
	return res;
}

int finalfunc(float a[], int sums[], int m, int min, int max){
	for (int i = 0; i<m;i++){
		a[i]=(float)(((float)sums[i]-(float)min)/((float)max-(float)min));
	}
	return 0;
}
