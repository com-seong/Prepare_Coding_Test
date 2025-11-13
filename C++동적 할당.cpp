#include<iostream>
using namespace std;
class Circle{
	public:
	int r;
	Circle(){r=1;}
	Circle(int r){this->r=r;}
	int getRadius();
};
int Circle::getRadius(){
	return r;
}
int main()
{
	//동적으로 할당받지 않은 포인터를 메모리 반환하면 오류 
	//두번 반환하면 오류 
	int *p = new int;
	if(!p) cout << "할당 실패" << endl;
	*p = 5;
	int n = *p;
	cout << "*p=" << *p << "\n";
	cout << "n=" << n << "\n";
	delete p;
	//배열 동적할당. 
	int *parr = new int[5];
	for(int i =0; i < 5; i++)
		parr[i] = i;
	cout << "동적배열" << endl;
	for(int i = 0; i < 5; i++)
	    cout << parr[i] << " ";
	cout << "\n할당 해제 = delete [] p\n";
	delete []p;
	//동적할당 초기화
	int *pint = new int(20);
	char *pchar = new char('a');
	cout << "*pint = " << *pint << endl;
	cout << "*pchar = " << *pchar << endl;
	//다 쓰기 전에 delete하면 dangling pointer 때매 쓰레기값 들간다잉. 
	delete pint;
	delete pchar; 
	//배열은 동적할당시 초기화 불가능;
	//객체 동적 생성,반환
	Circle *obp = new Circle; //r = 1 인 Circle 객체 
	Circle *obq = new Circle(20); //r=20 인 Circle 객체 
	cout << "*obp의 r = " << obp->getRadius() << endl;
	cout << "*obq의 r = " << obq->getRadius() << endl;
	cout << "할당 해제" << endl;
	delete obp;
	delete obq;  
	return 0;
}
