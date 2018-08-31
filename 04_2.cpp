#include <iostream>
using std::cout;
using std::endl;

class Point{
	private:
		int xpos, ypos;
	public:
		void Init(int x, int y){
			xpos = x;
			ypos = y;
		}
		void ShowPointInfo() const{
			cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
		}
};

class Circle{
	private:
		Point p;
		int rad;
	public:
		void Init(int x, int y, int r){
			p.Init(x,y);
			rad = r;
		}
		int Get_rad() const{
			return rad;
		}
		void ShowCircleInfo() const{
			cout<<"radius: "<<rad<<endl;
			p.ShowPointInfo();
		}
};

class Ring{
	private:
		Circle c1, c2;
	public:
		void Init(int x1, int y1, int r1, int x2, int y2, int r2){
			c1.Init(x1,y1,r1);
			c2.Init(x2,y2,r2);
		}
		void ShowRingInfo() const{
			if(c1.Get_rad()<c2.Get_rad()){
				cout<<"Inner Circle Info..."<<endl;
				c1.ShowCircleInfo();
				cout<<"Outter Circle Info..."<<endl;
				c2.ShowCircleInfo();
			}
			else{
				cout<<"Inner Circle Info..."<<endl;
				c2.ShowCircleInfo();
				cout<<"Outter Circle Info..."<<endl;
				c1.ShowCircleInfo();
			}
		}
};

int main(void){
	Ring ring;

	ring.Init(1,1,4,2,2,9);
	ring.ShowRingInfo();

	ring.Init(2,4,15,2,2,9);
	ring.ShowRingInfo();

	return 0;
}
