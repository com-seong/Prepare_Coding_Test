#include<iostream>
using namespace std;
class Circle{
	int radius;
	public:
		Circle(){radius=1;}
		Circle(int r){radius = r;}
		void setRadius(int r){radius = r;}
		double getArea();
};
double Circle::getArea(){
	return 3.14*radius*radius;
}
int main()
{
	Circle circleArray[3];
	//이런식으로 직접 초기화 하면 매개변수 있는 생성자 사용 가능. 
	Circle circleArray[3] = {Circle(10),Circle(20),Circle()};
	
	//객체 배열은 매개변수 있는 생성자 Circle(int r)을 호출할 수 없기 때문에 setRadius필요. 
	//기본 생성자 없으면 컴파일 오류 
	circleArray[0].setRadius(10);
	circleArray[1].setRadius(20);
	circleArray[2].setRadius(30);
	
	for(int i = 0; i < 3; i++){
		cout << "Circle" << i << "의 면적은" << circleArray[i].getArea() << endl;
	}
	
	Circle *p;
	p = circleArray;
	for(int i = 0; i < 3; i++){
		cout << "Circle" << i << "의 면적은" << p->getArea() << endl;
		p++;
	}
	return 0;
}
