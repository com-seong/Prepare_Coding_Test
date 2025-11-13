#include<iostream>
#include<string> 
using namespace std;

int main()
{
	string s;
	cout << "문자열 입력 입력 끝은 &\n" << endl;
	getline(cin,s,'&');
	cin.ignore(); //&뒤에 따라오는 enter 제거
	string f,r;
	cout << "find:";
	getline(cin,f,'\n');
	cout << "replace:";
	getline(cin,r,'\n');
	int startidx = 0;
	while(true){
		int fIdx = s.find(f,startidx); //index 반환 (문자열,탐색위치)
		if(fIdx == -1) break; //끝까지 변경 
		s.replace(fIdx,f.length(),r); //fIdx부터 문자열f의 길이만큼 문자열 r로 변경 
		startidx = fIdx + r.length(); 
	} 
	cout << s << endl;
	return 0;
}
