#ifndef FUNC_H_
#define FUNC_H_

typedef struct Line{
	int n;
	int *arritem;
} Line;

typedef struct Matrix{
	int lines;
	Line *arrline;
} Matrix;

int getInt(int *);
int input(Matrix *a);
void output(const char *msg, Matrix a);
void erase(Matrix *a);
int max(int a[], int m);
int min(int a[], int m);
int sum(Matrix a, int res[]);
int finalfunc(float a[],int sums[], int m, int min, int max);

#endif
