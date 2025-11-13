#include<iostream>
using namespace std;

class Storage{
	private:
		double temp[10];
		int next;
	public:
		Storage();
		void put(double tmp);
		void dump();
		double getAvg();
};
Storage::Storage() : next(0){}
void Storage::put(double tmp){
	if(next < 10){
		temp[next] = tmp;
		next++;
	}
	else{
		cout << "저장 공간 가득 찼어요" << endl;
	}
}
void Storage::dump(){
	for(int i = 0; i < next; ++i)
		cout << temp[i] << " ";
	cout << "\n"; 
}
double Storage::getAvg(){
	double sum = 0;
	if(next == 0) return 0;
	for(int i = 0; i < next; ++i) 	sum += temp[i];
	return sum / (next);
}
int main()
{
	Storage a;
	a.put(36.7);
	a.put(36.9);
	a.put(36.4);
	a.dump();
	cout << "평균 체온은 " << a.getAvg() << "입니다." << endl;
	return 0;
} 
