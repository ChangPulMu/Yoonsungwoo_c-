#include <iostream>
using std::cout;
using std::cin;
using std::endl;
struct Account{
	int ac_num;
	char name[10];
	int money;
};
int SelectMenu();
void Create_Account(Account &);
void Deposit(Account *);
void Withdraw(Account *);
void Info(Account *, int);

int main(void){
	Account ac[100];
	int num_people=0;

	while(1){
		switch(SelectMenu()){
			case 1:
				Create_Account(ac[num_people]);
				num_people++;
				break;
			case 2:
				Deposit(ac);
				break;
			case 3:
				Withdraw(ac);
				break;
			case 4:
				Info(ac,num_people);
				break;
			case 5:
				cout<<"프로그램 종료"<<endl;
				return 0;
			default: //잘못된 입력이라고 명시해주는 cout! 표기하는것이 좋다다
				cout<<"잘못된 입력입니다"<<endl;
			}
	}
}

int SelectMenu(){
	int mn;

	cout<<"-----Menu-----"<<endl;
	cout<<"1. 계좌개설"<<endl;
	cout<<"2. 입 금"<<endl;
	cout<<"3. 출 금"<<endl;
	cout<<"4. 계좌정보 전체 출력"<<endl;
	cout<<"5. 프로그램 종료"<<endl;
	cout<<"선택 : ";

	cin>>mn;

	return mn;
}

void Create_Account(Account & actmp){
	cout<<"[계좌개설]"<<endl;
	cout<<"계좌ID: ";
	cin>>actmp.ac_num;
	cout<<"이 름: ";
	cin>>actmp.name;
	cout<<"입금액: ";
	cin>>actmp.money;
}

void Deposit(Account * acptr){
	int tmp, i;

	cout<<"[입    금]"<<endl;
	cout<<"계좌ID: ";
	cin>>tmp;

	for(i=0;i<100;i++)
		if(acptr[i].ac_num==tmp)
			break;

	if(i==100){ //잘못된 입력을 했을때의 예외처리
		cout<<"잘못된 입력입니다!"<<endl;
		return;
	}

	cout<<"입금액: ";
	cin>>tmp;

	acptr[i].money += tmp;

	cout<<"입금완료"<<endl;
}

void Withdraw(Account * acptr){
	int tmp, i;

	cout<<"[출    금]"<<endl;
	cout<<"계좌ID: ";
	cin>>tmp;

	for(i=0;i<100;i++)
		if(acptr[i].ac_num==tmp)
			break;
	
	if(i==100){ //잘못된 입력을 했을때 예외처리
		cout<<"잘못된 입력입니다!"<<endl;
		return;
	}

	cout<<"출금액: ";
	cin>>tmp;

	acptr[i].money -= tmp;

	cout<<"출금완료"<<endl;
}

void Info(Account * acptr, int nm){
	for(int i=0;i<nm;i++)
		cout<<"계좌ID: "<<acptr[i].ac_num<<endl<<"이 름: "<<acptr[i].name<<endl<<"입금액: "<<acptr[i].money<<endl<<endl;
}
