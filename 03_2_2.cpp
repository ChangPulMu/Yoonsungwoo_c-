#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
class Printer{
	private:
		char * str;
	public:
		void SetString(const char *); //가리키는 곳의 값을 바꾸지 않기 위해 const선언 컴파일러는 문자열을 주어진것을 바꿀 위험이 있기 때문에 warning을 띄운거 같음음
		void ShowString();
		void Init(int);
		void Delete();
};

int main(void){
	Printer pnt;

	pnt.SetString("Hello world!");
	pnt.ShowString();

	pnt.SetString("I love C++");
	pnt.ShowString();

	pnt.Delete();

	return 0;
}

void Printer::SetString(const char * tmp){
	Init(strlen(tmp));
	strcpy(str,tmp);
}

void Printer::ShowString(){
	cout<<str<<endl;
}

void Printer::Init(int n){
	str = new char[n];
}

void Printer::Delete(){
	delete []str;
}
