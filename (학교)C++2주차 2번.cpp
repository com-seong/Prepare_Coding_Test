#include<iostream>
using namespace std;
class Coffee{
	private:
		int coffee,sugar,milk,water;
	public:
		Coffee();
		Coffee(int c,int s,int m,int w);
		void show();
};
Coffee::Coffee() : coffee(10),sugar(0),milk(0),water(0){}
Coffee::Coffee(int c,int s,int m,int w) : coffee(c),sugar(s),milk(m),water(w){}
void Coffee::show(){
		cout << "coffee" << " ";
		for(int j = 0; j < coffee; ++j) cout << "*";
		cout << endl; 
		cout << "sugar"<< " ";
		for(int j = 0; j < sugar; ++j) cout << "*";
		cout << endl;
		cout << "milk"<< " ";
		for(int j = 0; j < milk; ++j) cout << "*";
		cout << endl;
		cout << "water"<< " ";
		for(int j = 0; j < water; ++j) cout << "*";
		cout << endl;
}
int main()
{
	Coffee espresso;
	Coffee americano(5,0,0,10);
	Coffee cappucchino(5,1,5,2);
	Coffee mySweet(3,7,5,5);
	
	espresso.show();
	cout << endl;
	mySweet.show();
	return 0;
}
