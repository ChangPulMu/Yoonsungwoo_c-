#include <iostream>
using std::cout;
using std::endl;

int main(void){
	const int num = 12;
	const int * const ptr = &num;
	const int * const (& ch) = ptr;

	cout<<*ptr<<' '<<*ch<<endl;
	
	return 0;
}
