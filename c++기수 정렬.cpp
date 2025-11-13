#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int count[10001] = {0};
	int N,num = 0;
	cin >> N;
	for(int i = 0; i < N; ++i){
		cin >> num;
		count[num]++;
	}
	for(int i = 0; i <= 10000; ++i){
		if(count[i] != 0)
			for(int j = 0; j < count[i]; ++j)
				cout << i << "\n";
		
	}
	return 0;
}
