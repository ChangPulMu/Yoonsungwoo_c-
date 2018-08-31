#include <iostream>
#include <cstdio>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;
class Account{
	private:
		int ac_num;
		char * name;
		int money;
	public:
		Account(int, char *, int);
		~Account();
		int Get_ac_num() const;
		void Deposit_money(int);
		void Withdraw_money(int);
		void Info() const;
};

int SelectMenu();
void Make_Account(Account **,int);
void Deposit(Account **,int);
void Withdraw(Account **,int);

int main(void){
	Account * ac[100];
	int num_people=0;

	while(1){
		switch(SelectMenu()){
			case 1:
				Make_Account(ac,num_people);
				num_people++;
				break;
			case 2:
				Deposit(ac,num_people);
				break;
			case 3:
				Withdraw(ac,num_people);
				break;
			case 4:
				for(int i=0;i<num_people;i++)
					ac[i]->Info();
				break;
			case 5:
				cout<<"프로그램 종료"<<endl;
				for(int i=0;i<num_people;i++) //소멸자를 해줬어도 클래스 포인터 배열에서 동적 할당해준것에 대한 소멸자는 없으므로 이렇게 해줘야함!
					delete ac[i];
				return 0;
			}
	}
}

Account::Account(int b, char * n, int m){
	name = new char[strlen(n)+1];
	strcpy(name,n);
	ac_num = b;
	money = m;

	cout<<"계정 생성!"<<endl<<endl;
}

Account::~Account(){
	delete []name;
}

int Account::Get_ac_num() const{
	return ac_num;
}

void Account::Deposit_money(int mn){
	money += mn;
	cout<<"입금 완료!"<<endl<<endl;
}

void Account::Withdraw_money(int mn){
	if(money<0){ //예외 처리해줘야징 ㅎㅅㅎ
		cout<<"돈이.. 없습니다..."<<endl;
		return;
	}
	money -= mn;
	cout<<"출금 완료!"<<endl<<endl;
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

	while(1){
		cin>>mn;
		if(mn>0&&mn<=5)
			break;
		cout<<"잘못된 번호입니다! 다시 입력하시오 : ";
		while(getchar()!='\n'){}
	}

	return mn;
}

void Make_Account(Account * acptr[100],int np){
	int tmp_num, tmp_money;
	char tmp_name[100];

	cout<<"[계좌개설]"<<endl;
	cout<<"계좌ID: ";
	cin>>tmp_num;
	cout<<"이 름: ";
	cin>>tmp_name;
	cout<<"입금액: ";
	cin>>tmp_money;

	acptr[np] = new Account(tmp_num,tmp_name,tmp_money);
}

void Deposit(Account * acptr[100], int np){
	int tmp, i;

	cout<<"[입    금]"<<endl;
	cout<<"계좌ID: ";
	cin>>tmp;

	for(i=0;i<np;i++)
		if(acptr[i]->Get_ac_num()==tmp){
			cout<<"입금액: ";
			cin>>tmp;
			acptr[i]->Deposit_money(tmp);
			return;
		}
	
	cout<<"잘못된 입력입니다!"<<endl;
	return;
}

void Withdraw(Account * acptr[100], int np){
	int tmp, i;

	cout<<"[출    금]"<<endl;
	cout<<"계좌ID: ";
	cin>>tmp;

	for(i=0;i<np;i++)
		if(acptr[i]->Get_ac_num()==tmp){
			cout<<"출금액: ";
			cin>>tmp;
			acptr[i]->Withdraw_money(tmp);
			return;
		}
	
	cout<<"잘못된 입력입니다!"<<endl;
	return;
}

void Account::Info() const{
	cout<<"계좌ID: "<<ac_num<<endl<<"이 름: "<<name<<endl<<"입금액: "<<money<<endl<<endl;
}
