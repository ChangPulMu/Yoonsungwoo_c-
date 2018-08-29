#include <iostream>
using std::cout;
using std::cin;
using std::endl;
struct Point{
	int xpos;
	int ypos;
};
Point& PntAdder(const Point &, const Point &);

int main(void){
	Point * ptr1 = new Point;
	Point * ptr2 = new Point;
	Point * ptr = new Point;

	cout<<"첫 번째 점의 x, y 좌표 입력 : ";
	cin>>(*ptr1).xpos>>(*ptr1).ypos;

	cout<<"두 번째 점의 x, y 좌표 입력 : ";
	cin>>(*ptr2).xpos>>(*ptr2).ypos;

	(*ptr) = PntAdder(*ptr1,*ptr2);

	cout<<(*ptr).xpos<<' '<<(*ptr).ypos<<endl;

	delete ptr1;
	delete ptr2;
	delete ptr;

	return 0;
}

Point& PntAdder(const Point &p1, const Point &p2){
	Point * ptmp = new Point;

	(*ptmp).xpos = p1.xpos + p2.xpos;
	(*ptmp).ypos = p1.ypos + p2.ypos;

	return *ptmp;
}
