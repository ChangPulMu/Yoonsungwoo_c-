#include <iostream>
using namespace std;

int main(void){
	int dan;

	cout<<"몇 단을 출력할까요? : ";
	cin>>dan;

	for(int i=1;i<10;i++)
		cout<<dan<<" X "<<i<<" = "<<dan*i<<endl;

	return 0;
}
