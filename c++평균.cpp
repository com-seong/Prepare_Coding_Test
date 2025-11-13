#include<iostream>
using namespace std;

int main()
{
	int N; 
	cin >> N;
	int num[N];
	long sum = 0,max = 0;
	for(int i = 0; i < N; ++i){
		cin >> num[i];
	}
	for(int i = 0; i < N; ++i){
		if(max < num[i])
			max = num[i];
			
		sum += num[i];
	}
	double result = sum * 100.0 / max / N;
	cout << result << "\n";
	return 0;
}
