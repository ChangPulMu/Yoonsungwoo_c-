#include <iostream>
using namespace std;
void swap(int *,int *);
void swap(char *,char *);
void swap(double *,double *);

int main(void){
	int num1 = 20, num2 = 30;
	swap(&num1, &num2);
	cout<<num1<<' '<<num2<<endl;

	char ch1 = 'A', ch2 = 'Z';
	swap(&ch1, &ch2);
	cout<<ch1<<' '<<ch2<<endl;

	double dbl1 = 1.111, dbl2 = 5.555;
	swap(&dbl1, &dbl2);
	cout<<dbl1<<' '<<dbl2<<endl;

	return 0;
}

void swap(int * a, int * b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void swap(char * c1, char * c2){
	char tmc;
	tmc = *c1;
	*c1 = *c2;
	*c2 = tmc;
}

void swap(double * d1, double * d2){
	double tmd;
	tmd = *d1;
	*d1 = *d2;
	*d2 = tmd;
}
