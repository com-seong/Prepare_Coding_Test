#include<iostream>
using namespace std;
class Cube{
	private:
		int x, y, z;
	public:
		Cube(int x,int y,int z);
		int getVolume();
		void increase(int px,int py,int pz);
		bool isZero();
};
Cube::Cube(int x,int y,int z) : x(x),y(y),z(z){}
int Cube::getVolume(){
	return x*y*z;
}
void Cube::increase(int px,int py,int pz){
	x += px , y += py, z += pz;
}
bool Cube::isZero(){
	if(x*y*z == 0) return true;
	else return false;
}
int main()
{
	Cube cube(1,2,3);
	cout << "큐브의 부피는 " << cube.getVolume() << endl;
	cube.increase(1,2,3);
	cout << "큐브의 부피는 " << cube.getVolume() << endl;
	if(cube.isZero()) cout << "큐브의 부피는 0" << endl;
	else cout << "큐브의 부피는 0이 아님" << endl;
	return 0;
}
