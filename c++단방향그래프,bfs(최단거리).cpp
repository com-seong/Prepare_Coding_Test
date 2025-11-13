#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<int> visited;
vector<vector<int>> g;
vector<int> ans;
int N;
void bfs(int node){
	queue<int> q;
	q.push(node);
	visited[node]++;
	
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(int i : g[now]){
			if(visited[i] == -1){
				visited[i] = visited[now]+1;
				q.push(i);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M,K,X;
	cin >> N >> M >> K >> X;
	g.resize(N+1);
	visited.resize(N+1);
	for(int i = 0; i < M; i++){
		int s,e;
		cin >> s >> e;
		g[s].push_back(e);
	}
	for(int i = 0; i <= N; i++)
		visited[i] = -1;
	//가중치가 1일땐 bfs가 최단거리를 보장한다. 
	bfs(X);
	for(int i = 0; i <= N; i++)
		if(visited[i] == K) ans.push_back(i);
	if(ans.empty()) cout << -1 << "\n";
	else {
		sort(ans.begin(),ans.end());
		for(int temp : ans) cout << temp << "\n";
	}
	return 0;
}
