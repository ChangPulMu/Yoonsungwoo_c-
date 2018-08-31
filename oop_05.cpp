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
		Account(const Account &);
		~Account();
		int Get_ac_num() const;
		void Deposit_money(int);
		void Withdraw_money(int);
		void Info() const;
};

class AccountHandler{
	private:
		Account * ac[100];
		int num_people;
	public:
		AccountHandler() : num_people(0) {};
		~AccountHandler();
		int SelectMenu() const;
		void Make_Account();
		void Deposit();
		void Withdraw();
		void Info() const;
};

int main(void){
	AccountHandler ah;
	
	while(1){
		switch(ah.SelectMenu()){
			case 1:
				ah.Make_Account();
				break;
			case 2:
				ah.Deposit();
				break;
			case 3:
				ah.Withdraw();
				break;
			case 4:
				ah.Info();
				break;
			case 5:
				cout<<"프로그램 종료"<<endl;
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

Account::Account(const Account & cp) : ac_num(cp.ac_num), money(cp.money) {
	name = new char[strlen(cp.name)+1];
	strcpy(name, cp.name);
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
	if(money<=0){ //예외 처리해줘야징 ㅎㅅㅎ
		cout<<"돈이.. 없습니다..."<<endl<<endl;
		return;
	}
	money -= mn;
	cout<<"출금 완료!"<<endl<<endl;
}

AccountHandler::~AccountHandler(){
	for(int i=0;i<num_people;i++) //소멸자를 해줬어도 클래스 포인터 배열에서 동적 할당해준것에 대한 소멸자는 없으므로 이렇게 해줘야함!
		delete ac[i];
}

int AccountHandler::SelectMenu() const{
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

void AccountHandler::Make_Account(){
	int tmp_num, tmp_money;
	char tmp_name[100];

	cout<<"[계좌개설]"<<endl;
	cout<<"계좌ID: ";
	cin>>tmp_num;
	cout<<"이 름: ";
	cin>>tmp_name;
	cout<<"입금액: ";
	cin>>tmp_money;

	ac[num_people++] = new Account(tmp_num,tmp_name,tmp_money); //++을 포함시키는게 더 짧겠지?
}

void AccountHandler::Deposit(){
	int tmp, i;

	cout<<"[입    금]"<<endl;
	cout<<"계좌ID: ";
	cin>>tmp;

	for(i=0;i<num_people;i++)
		if(ac[i]->Get_ac_num()==tmp){
			cout<<"입금액: ";
			cin>>tmp;
			ac[i]->Deposit_money(tmp);
			return;
		}
	
	cout<<"잘못된 입력입니다!"<<endl;
	return;
}

void AccountHandler::Withdraw(){
	int tmp, i;

	cout<<"[출    금]"<<endl;
	cout<<"계좌ID: ";
	cin>>tmp;

	for(i=0;i<num_people;i++)
		if(ac[i]->Get_ac_num()==tmp){
			cout<<"출금액: ";
			cin>>tmp;
			ac[i]->Withdraw_money(tmp);
			return;
		}
	
	cout<<"잘못된 입력입니다!"<<endl;
	return;
}

void AccountHandler::Info() const{
	for(int i=0;i<num_people;i++)
		ac[i]->Info();
}

void Account::Info() const{
	cout<<"계좌ID: "<<ac_num<<endl<<"이 름: "<<name<<endl<<"입금액: "<<money<<endl<<endl;
}
