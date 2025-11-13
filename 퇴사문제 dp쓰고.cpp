#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	vector<pair<int,int>> tp;
	vector<int> dp;
	tp.assign(N+2,{0,0});
	dp.resize(N+2,0);
	for(int i = 1; i <= N; i++)
		cin >> tp[i].first >> tp[i].second;
		
	//뒤에서 부터 채워서 미래값이 이미 완성되어있음. 
	for(int i = N; i >= 1; i--){
		int next = i + tp[i].first;
									//가능 
									//건너뛴 날이 큰지, 다음날이 큰지==상담한다,안한다. 
									//오늘 상담 돈  그 상담이 끝난 이후 이득
		//기준 상담 시작일 
		//P[1] = 50, T[1] = 5 → next = 6
		//즉 "1일에 상담하면 1~5일까지 바쁘고 6일부터 다시 일 가능”
		//그때 얻는 총 이익: 50 + dp[6]
		//만약 1일 상담을 안 하면 그냥 dp[2]로 넘어감
		//이 두 개 중 큰 값이 dp[1]이 되는 것입니다. 
		if(next <= N+1) dp[i] = max(tp[i].second + dp[next],dp[i+1]); 
		else dp[i] = dp[i+1]; //불가능 
	}
	cout << dp[1];
	return 0;
}
