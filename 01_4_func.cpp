#include <iostream>
#include "01_4.h" //출력을 쓰니까 iostream 포함해주고 네임스페이스 있는 01_4.h 헤더파일도 포함해줘야함!
using namespace std;

void BestComImpl::SimpleFunc(void){
	cout<<"BestCom이 정의한 함수"<<endl;
}
void ProgComImpl::SimpleFunc(void){
	cout<<"ProgCom이 정의한 함수"<<endl;
}
