#include<iostream>
using namespace std;
class Test
{
public:
	Test(){
		cout << "생성자 함수 호출 됨." << endl;
		num = 100;
		name = "성혁이에요";
	}
	int num;
	const char *name;
	void print(void){
		cout << "num : " << num << endl;
		cout << "name: " << name << endl;
	}		
};
int main(int argc,char *argv[])
{	
	cout << "main start" << endl;
	Test t;
	t.print();
	cout << "finish" << endl;
	return 0;
}
