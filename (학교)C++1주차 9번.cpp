#include<iostream>
#include<ctime>
using namespace std;

int main()
{
	cout << "***구구단 맞추기 퀴즈입니다.***" << "\n";
	int wrong = 0;
	int ans; 
	//시드 초기화는 한번만 
	srand(time(0));
	while(wrong <= 1){
		//랜덤 정수를 9이하로 설정 % 9 = 0 ~ 8 
		int n = rand() % 9 + 1;
		int m = rand() % 9 + 1;
		cout << n << "x" << m << "=";
		cin >> ans;
		if(ans == n*m) cout << "정답입니다.잘했습니다." << "\n";
		else{
			wrong++;
			if(wrong == 2){
				cout << wrong << "번 틀렸습니다.종료합니다.";	
				break;
			} 
			cout << wrong << "번 틀렸습니다. 분발하세요" << "\n";	
		} 
		
	}
	return 0;
}
