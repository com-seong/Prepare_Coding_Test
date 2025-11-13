#include<iostream>
#include<vector>
using namespace std;
int N,e,cnt = 0;
int ans = -1;
void dfs(int s,vector<vector<int>> &graph, vector<bool> &visited)
{
	if(s == e) {
		ans = cnt;
		return;
	}
	if(visited[s]) return;
	visited[s] = true;
	for(int u : graph[s]){
		if(!visited[u]){
			cnt++;
			dfs(u,graph,visited);
			if(ans != -1) return;
		} 
	}
	cnt--; //for문이 끝나고 호출이 끝났으니 다시 올라가면서 cnt--를하여 ++한만큼 정상화 
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int s,C,u,v;
	cin >> N;
	cin >> s >> e;
	cin >> C;
	
	vector<vector<int>> graph(N+1);
	vector<bool> visited(N,false);
	for(int i = 0; i < C; ++i){
		cin >> v >> u;
		graph[v].push_back(u);
		graph[u].push_back(v);
	}
	dfs(s,graph,visited);
	cout << ans;
	return 0;
}
