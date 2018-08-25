#include <iostream>
using namespace std;

int main(void){
	int num;
	
	while(1){
		cout<<"판매 금액을 만원 단위로 입력(-1 to end): ";
		cin>>num;

		if(num == -1){
			cout<<"프로그램을 종료합니다."<<endl;
			break;
		}

		cout<<"이번 달 급여: "<<50+num*0.12<<"만원"<<endl;
		//(int)50+num*0.12 형 변환해주면 만원단위로 말해줄 수 있음
	}

	return 0;
}
