#include<iostream>
#include<cstring>
#include<string> 
using namespace std;

int main()
{
	//3번 
	int num;
	cout << "정수를 입력하세요>>";
	cin >> num; 
	num /= 10;
	cout << num << "의 10자리 수는 " << num%10 << "입니다." << "\n";
	
	//4번
	double data;
	double sum = 0;
	cout << "실수를 5개 입력하세요>>";
	for(int i = 0; i < 5; ++i){
		cin >> data; 
		if(data > 0){
			sum += data;
		}
	}
	cout << "양수 합은" << sum << "입니다." << "\n";
	
	//5번
	char buf1[100];
	char buf2[100];
	cout << "문자열을 입력하세요>>" << "\n"; 
	cin >> buf1;
	cout << "문자열을 입력하세요>>" << "\n"; 
	cin >> buf2;
	if(strcmp(buf1,buf2) == 0) cout << "Yes" << "\n";
	else cout << "NO" << "\n";
	
	//6번
	string str1;
	string str2; 
	cout << "문자열을 입력하세요>>" << "\n"; 
	cin >> str1;
	cout << "문자열을 입력하세요>>" << "\n"; 
	cin >> str2;
	if(str1 == str2) cout << "Yes" << "\n";
	else cout << "NO" << "\n";
	
	//7번
	string str;
	cout << "문자열을 입력하세요 >>";
	cin >> str;
	for(int i = 0; i < str.length(); ++i){
		cout << str[i] << " ";
	} 
	
	return 0;
}
