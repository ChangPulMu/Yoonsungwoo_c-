#include <iostream>
using std::cout;
using std::cin;
using std::endl;
void Plus_One(int &);
void Change_Buho(int &);

int main(void){
	int num;

	cout<<"수를 입력하시오 : ";
	cin>>num;

	Plus_One(num);
	cout<<"+1 : "<<num<<endl;

	Change_Buho(num);
	cout<<"부호 교체 : "<<num<<endl;

	return 0;
}

void Plus_One(int & tmp1){
	tmp1++;
}

void Change_Buho(int & tmp2){
	tmp2 = tmp2 * (-1); //tmp2 *= -1;
}
