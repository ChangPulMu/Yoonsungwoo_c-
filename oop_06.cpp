#include <iostream>
#include <cstdio>
#include <cstring>
using std::cout;
using std::cin;
using std::endl;
namespace LEVEL_ACCOUNT{ enum {A=7, B=4, C=2}; };
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
		void Put_money(int); //Put_money()나 Get_percent()같은 함수 안만들고 Account::Deposit_money 함수를 money+=mn; 이걸로 만들어주면 노말어카운트는 원금으로 한번 불러주고 이자로 한번 불러주면 효율적임, 하이어카운트는 노말어카운트 Deposit_money 함수를 부르고 Account::Deposit_money로 추가 이자금을 예치해주면 더 효율적임임
		virtual void Deposit_money(int) = 0;
		void Withdraw_money(int);
		virtual void Info() const;
};

class NormalAccount : public Account {
	private:
		int percent;
	public:
		NormalAccount(int, char *, int, int);
		int Get_percent() const;
		virtual void Deposit_money(int);
		virtual void Info() const;
};

class HighCreditAccount : public NormalAccount {
	private:
		int level;
		char Level;
	public:
		HighCreditAccount(int, char *, int, int, int);
		virtual void Deposit_money(int);
		virtual void Info() const;
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

void Account::Put_money(int mnm) {
	money += mnm;
}

/*void Account::Deposit_money(int mn){
	Put_money(mn);
	cout<<"입금 완료!"<<endl<<endl;
}*/

void Account::Withdraw_money(int mn){
	if(money<=0){ //예외 처리해줘야징 ㅎㅅㅎ
		cout<<"돈이.. 없습니다..."<<endl<<endl;
		return;
	}
	money -= mn;
	cout<<"출금 완료!"<<endl<<endl;
}

NormalAccount::NormalAccount(int b, char * n, int m, int p) : Account(b, n, m), percent(p) {}

int NormalAccount::Get_percent() const {
	return percent;
}

void NormalAccount::Deposit_money(int mn){
	Put_money((int)mn + mn*((double)percent/100));
}

HighCreditAccount::HighCreditAccount(int b, char * n, int m, int p, int l) : NormalAccount(b, n, m, p) {
	switch(l){
		case 1:
			level = LEVEL_ACCOUNT::A;
			Level = 'A';
			break;
		case 2:
			level = LEVEL_ACCOUNT::B;
			Level = 'B';
			break;
		case 3:
			level = LEVEL_ACCOUNT::C;
			Level = 'C';
			break;
	}
}

void HighCreditAccount::Deposit_money(int mn){
	Put_money((int)mn + mn*((double)(Get_percent()+level)/100));
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
	int tmp_num, tmp_money, tmp_percent, kind, tmp_level;
	char tmp_name[100];

	cout<<"[계좌종류선택]"<<endl<<"1. 보통예금계좌 2. 신용신뢰계좌"<<endl<<"선택: ";
	cin>>kind;

	cout<<"[계좌개설]"<<endl;
	cout<<"계좌ID: ";
	cin>>tmp_num;
	cout<<"이 름: ";
	cin>>tmp_name;
	cout<<"입금액: ";
	cin>>tmp_money;
	cout<<"이자율: ";
	cin>>tmp_percent;

	if(kind==1)
		ac[num_people++] = new NormalAccount(tmp_num,tmp_name,tmp_money,tmp_percent); //++을 포함시키는게 더 짧겠지?
	else if(kind==2){
		cout<<"신용등급(1toA, 2toB, 3toC): ";
		cin>>tmp_level;

		ac[num_people++] = new HighCreditAccount(tmp_num,tmp_name,tmp_money,tmp_percent,tmp_level);
	}
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
	for(int i=0;i<num_people;i++){
		ac[i]->Info();
		cout<<endl;
	}
}

void Account::Info() const{
	cout<<"계좌ID: "<<ac_num<<endl<<"이 름: "<<name<<endl<<"입금액: "<<money<<endl;
}

void NormalAccount::Info() const{
	Account::Info();
	cout<<"이자율: "<<percent<<endl;
}

void HighCreditAccount::Info() const{
	NormalAccount::Info();
	cout<<"신용등급: "<<Level<<endl;
}
