#include<iostream>

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N,start=1,end=1,count=1,sum=1;
	
	cin >> N;
	while(end != N){
		if(sum == N){
			count++;
			end++;
			sum = sum + end;
		}
		else if(sum > N){
			sum = sum - start;
			start++;
		}
		else{
			end++;
			sum = sum + end;
		}
	}
	cout << count << "\n";
	return 0;
}
