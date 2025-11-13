#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int>> tp;
int ans = 0;
int N;
void dfs(int day, int sum){
	if(day > N + 1) return; //종료조건 1 
	if(day == N + 1){  //종료조건 2 
		ans = max(ans,sum);
		return;
	}
	//상담 한다 
	if(day + tp[day].first <= N + 1) dfs(day + tp[day].first , sum + tp[day].second);
	//상담 안하면 다음날
	dfs(day+1,sum); 
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	tp.assign(N+2,{0,0});
	for(int i = 1; i <= N; i++)
		cin >> tp[i].first >> tp[i].second;
	dfs(1,0);
	cout << ans;
	return 0;
}
