#include <iostream>
using namespace std;

int main(void){
	int arr[5], result=0;

	for(int i=0;i<5;i++){
		cout<<i+1<<"번째 정수 입력 : ";
		cin>>arr[i];
		result += arr[i];
	}

	/*for(int i=0;i<5;i++)
		result += arr[i];*///정신차리자..!

	cout<<"합계 : "<<result<<endl;

	return 0;
}
