#include <iostream>
using std::cout;
using std::endl;

class Rectangle{
	private:
		int x;
		int y;
	public:
		Rectangle(int tmp_x, int tmp_y) : x(tmp_x), y(tmp_y) {}
		void ShowAreaInfo() const{
			cout<<"면적: "<<x*y<<endl;
		}
};

class Square : public Rectangle {
	public:
		Square(int xy) : Rectangle(xy, xy) {}
};

int main(void){
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();

	return 0;
}
