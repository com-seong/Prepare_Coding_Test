#include<iostream>
using namespace std;
class Picture{
	private:
		int width , height;
		string place;
	public:
		Picture();
		Picture(int w,int h,string p);
		int getWidth();
		int getHeight();
		string getPlace();
};
//위임 개념 예시
Rectangle::Rectangle() : Rectangle(1){}
Rectangle::Rectangle(int a) : Rectangle(a,a){}
Rectangle::Rectangle(int a,int b):width(a),height(b){}
 
Picture::Picture() : Picture(5,7,"모름"){}
Picture::Picture(int w,int h,string p) : width(w),height(h),place(p){}
int Picture::getHeight(){
	return height;
}
int Picture::getWidth(){
	return width;
}
string Picture::getPlace(){
	return place;
}
int main()
{
	Picture pic;
	Picture mt(10,14,"한라산");
	cout << pic.getWidth() << "x" << pic.getHeight() << " " << pic.getPlace() << endl;
	cout << mt.getWidth() << "x" << mt.getHeight() << " " << mt.getPlace() << endl;
	return 0;
}
