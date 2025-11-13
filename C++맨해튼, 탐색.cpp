#include<iostream>
#include<vector>
#include<cstdlib>
#include<queue>
using namespace std;
int manhaten(pair<int,int> a,pair<int,int> b){
	return abs(a.first - b.first) + abs(a.second - b.second);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		pair<int,int> home;
		cin >> home.first >> home.second;
		vector<pair<int,int>> gs(n);
		for(int i = 0; i < n; i++)
			cin >> gs[i].first >> gs[i].second;
		pair<int,int> fest;
		cin >> fest.first >> fest.second;
		
		vector<bool> visited(n,false);
		queue<pair<int,int>> q;
		q.push(home);
		bool ok = false;
		while(!q.empty()){
			auto cur = q.front();
			q.pop();
			
			//한번에 직행
			if(manhaten(cur,fest) <= 1000){
				ok = true;
				break;
			}
			//편의점 들리기 
			for(int i = 0; i < n; i++){
				if(visited[i]) continue;
				if(manhaten(cur,gs[i]) <= 1000){
					visited[i] = true;
					q.push(gs[i]);
				}
			}
		}
		cout << (ok ? "happy" : "sad") << "\n";
	}
	return 0;
}
