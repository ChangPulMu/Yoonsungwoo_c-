#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

class Book{
	private:
		char * title;
		char * isbn;
		int price;
	public:
		Book(char * t, char * i, int p) : price(p) {
			title = new char[strlen(t)+1];
			isbn = new char[strlen(i)+1];

			strcpy(title, t);
			strcpy(isbn, i);
		}
		~Book(){ //동적 할당을 했으면 꼭 소멸자 잘 만들어 주자~
			delete []title;
			delete []isbn;
		}
		void ShowBookInfo(){
			cout<<"제목: "<<title<<endl;
			cout<<"ISBN: "<<isbn<<endl;
			cout<<"가격: "<<price<<endl;
		}
};

class EBook : public Book {
	private:
		char * DRMKey;
	public:
		EBook(char * t, char * i, int p, char * d) : Book(t,i,p) {
			DRMKey = new char[strlen(d)+1];
			strcpy(DRMKey, d);
		}
		~EBook(){ //마찬가지~
			delete []DRMKey;
		}
		void ShowEBookInfo(){
			ShowBookInfo();
			cout<<"인증키: "<<DRMKey<<endl;
		}
};

int main(void){
	Book book("좋은 C++", "555-122345-890-0", 20000);
	book.ShowBookInfo();
	cout<<endl;

	EBook ebook("좋은 C++ ebook", "555-122345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();

	return 0;
}
