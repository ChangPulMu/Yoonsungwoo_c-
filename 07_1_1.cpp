#include <iostream>
using std::cout;
using std::endl;

class Car{
	private:
		int gasolineGauge;
	public:
		Car(int n=0) : gasolineGauge(n) {}
		int GetGasGauge(){
			return gasolineGauge;
		}
};

class HybridCar : public Car {
	private:
		int electricGauge;
	public:
		HybridCar(int n1=0, int n2=0) : Car(n1), electricGauge(n2) {}
		int GetElecGauge(){
			return electricGauge;
		}
};

class HybridWaterCar : public HybridCar {
	private:
		int waterGauge;
	public:
		HybridWaterCar(int n1=0, int n2=0, int n3=0) : HybridCar(n1, n2), waterGauge(n3) {}
		void ShowCurrentGauge(){
			cout<<"잔여 가솔린: "<<GetGasGauge()<<endl;
			cout<<"잔여 전기량: "<<GetElecGauge()<<endl;
			cout<<"잔여 워터량: "<<waterGauge<<endl;
		}
};

int main(void){
	HybridWaterCar hwc(1000,200,50);
	
	hwc.ShowCurrentGauge();

	return 0;
}
