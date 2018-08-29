#include <iostream>
using std::cout;
using std::cin;
using std::endl;
void SwapPointer(int *&, int*&);

int main(void){
	int num1 = 5, num2 = 10;
	int * ptr1 = &num1, * ptr2 = &num2;

	SwapPointer(ptr1, ptr2);

	cout<<*ptr1<<' '<<*ptr2<<endl;

	return 0;
}

void SwapPointer(int *(&pr1), int *(&pr2)){
	int * tmp;
	tmp = pr1;
	pr1 = pr2;
	pr2 = tmp;
} //포인터의 저장값을 바꾸냐 아니면 포인터가 가르키는 곳 안의 값을 바꾸냐에 따라 함수 정의가 달라진다!
