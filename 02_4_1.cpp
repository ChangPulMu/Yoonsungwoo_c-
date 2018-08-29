#include <iostream>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;

int main(void){
	char * name1 = new char[30];
	char * name2 = new char[30];

	cout<<"첫 번째 문자열 입력 : ";
	cin>>name1;

	cout<<"두 번째 문자열 입력 : ";
	cin>>name2;

	cout<<"문자열 길이 : "<<strlen(name1)<<' '<<strlen(name2)<<endl;

	strcat(name1, name2);

	cout<<"덧붙이기 : "<<name1<<' '<<name2<<endl;

	strcpy(name1, name2);

	cout<<"복사 : "<<name1<<' '<<name2<<endl;

	cout<<"문자열 비교 : "<<strcmp(name1,name2)<<endl;

	return 0;
}
