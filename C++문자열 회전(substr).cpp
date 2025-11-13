#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	cout << "문자열 입력" << endl;
				  //문자형 주의	
	getline(cin,s,'\n');
	for(int i = 0; i < s.length(); i++){
		string first = s.substr(0,1);
		string sub = s.substr(1,s.length()-1);
		s = sub + first;
		cout << s << endl;
	}
	return 0;
}
