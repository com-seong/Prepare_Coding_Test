#include<iostream>
#include<sstream>
using namespace std;

int main()
{
	string txt;
	while(1){
		int count = 0;
		cout << "영문의 텍스트를 입력하세요>>";
		//getline(스트림객체, 저장할변수, '구분자');

		getline(cin,txt);
		if(txt == "exit") break;
		stringstream ss(txt);
		string word;
		while(ss >> word) count++;
		cout << "단어의 개수는 " << count << "개이다." << "\n";
	}
	return 0;
}
