#include<iostream>
#include<vector>
#include<queue> 
#include<algorithm>
using namespace std;
vector<vector<int>> g;
vector<int> visited;
vector<int> ans;
void bfs(int node) {
	queue<int> q;
	q.push(node);
	visited[node] = 1;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int i : g[cur]) {
			if(!visited[i]){
				visited[i] = 1;
				ans[i]++;
				q.push(i);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N,M;
	cin >> N >> M;
	ans.resize(N+1);
	g.resize(N+1);
	visited.resize(N+1,0);
	for(int i = 0; i < M; i++){
		int s,e;
		cin >> s >> e;
		g[s].push_back(e);
	}
	for(int i = 0; i <= N; i++)
		bfs(i) , fill(visited.begin(),visited.end(),0);
	int maxVal = 0;
	for(int i = 1; i <= N; i++)
		 maxVal = max(maxVal,ans[i]);
	for(int i = 1; i <= N; i++){
		if(maxVal == ans[i]) cout << i << " ";
	}
	return 0;
}
