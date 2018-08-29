#include <iostream>
#include <ctime>
#include <cstdlib>
using std::cout;
using std::endl;

int main(void){
	int * random = new int[5];

	srand(time(NULL));

	for(int i=0;i<5;i++){
		random[i] = rand()%100;
		cout<<random[i]<<' ';
	}

	cout<<endl;

	return 0;
}
