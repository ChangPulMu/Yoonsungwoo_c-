#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

class MyFriendInfo{
	private:
		char * name;
		int age;
	public:
		MyFriendInfo(char * n, int a) : age(a) {
			name = new char[strlen(n)+1];
			strcpy(name, n);
		}
		~MyFriendInfo(){
			delete []name;
		}
		void ShowMyFriendInfo(){
			cout<<"이름: "<<name<<endl;
			cout<<"나이: "<<age<<endl;
		}
};

class MyFriendDetailInfo : public MyFriendInfo {
	private:
		char * addr;
		char * phone;
	public:
		MyFriendDetailInfo(char * n, int a, char * ad, char * ph) : MyFriendInfo(n,a) {
			addr = new char[strlen(ad)+1];
			phone = new char[strlen(ph)+1];

			strcpy(addr,ad);
			strcpy(phone,ph);
		}
		~MyFriendDetailInfo(){
			delete []addr;
			delete []phone;
		}
		void ShowMyFriendDetailInfo(){
			ShowMyFriendInfo();
			cout<<"주소: "<<addr<<endl;
			cout<<"전화: "<<phone<<endl<<endl;
		}
};

int main(void){
	MyFriendDetailInfo mfdi("Chang Du Hyeok", 22, "Seoul", "010 1234 5678");

	mfdi.ShowMyFriendDetailInfo();

	return 0;
}
