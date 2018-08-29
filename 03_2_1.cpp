#include <iostream>
using std::cout;
using std::endl;
class Calculator{
	private:
		int Add_count;
		int Min_count;
		int Mul_count;
		int Div_count;
	public:
		void Init();
		double Add(const double &, const double &);
		double Min(const double &, const double &);
		double Mul(const double &, const double &);
		double Div(const double &, const double &);
		void ShowOpCount();
};

int main(void){
	Calculator cal;

	cal.Init();

	cout<<"3.2 + 2.4 = "<<cal.Add(3.2,2.4)<<endl;
	cout<<"3.5 / 1.7 = "<<cal.Div(3.5,1.7)<<endl;
	cout<<"2.2 - 1.5 = "<<cal.Min(2.2,1.5)<<endl;
	cout<<"4.9 + 1.2 = "<<cal.Div(4.9,1.2)<<endl;
	cout<<"5.0 * 1.2 = "<<cal.Mul(5.0,1.2)<<endl;

	cal.ShowOpCount();

	return 0;
}

void Calculator::Init(){
	Add_count = 0;
	Min_count = 0;
	Mul_count = 0;
	Div_count = 0;
}

double Calculator::Add(const double & n1, const double & n2){
	Add_count++;
	return n1+n2;
}

double Calculator::Min(const double & n1, const double & n2){
	Min_count++;
	return n1-n2;
}

double Calculator::Mul(const double & n1, const double & n2){
	Mul_count++;
	return n1*n2;
}

double Calculator::Div(const double & n1, const double & n2){
	Div_count++;
	return n1/n2;
}

void Calculator::ShowOpCount(){
	cout<<"덧셈: "<<Add_count<<' '<<"뺄셈: "<<Min_count<<' '<<"곱셈: "<<Mul_count<<' '<<"나눗셈: "<<Div_count<<endl;
}
