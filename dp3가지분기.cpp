#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	int dp[N+1];
	//마지막이 1이면 카운트 없음. 
	dp[1] = 0;
	for(int x = 2; x <= N; x++){
		//기준 값 
		dp[x] = dp[x-1]+1;   //더 클때만 작은걸로 최신화 
		if(x % 2 == 0 && dp[x] > dp[x/2]+1)
			dp[x] = dp[x/2] + 1;
		if(x % 3 == 0 && dp[x] > dp[x/3]+1)
			dp[x] = dp[x/3] + 1;
	}
	cout << dp[N];
	return 0;
}
