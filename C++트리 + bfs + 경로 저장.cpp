#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,S,E;
	cin >> N >> S >> E;
	vector<vector<int>> g(N+1);
	for(int i = 0; i < N-1; ++i){
		int u,v; 
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	//경로 수집 복원용
	vector<int> parent(N+1,-1);
	queue<int> q;
	q.push(S);
	parent[S] = S;
	while(!q.empty()) {
		int v = q.front();
		q.pop();
		for(int w : g[v]) 
			if(parent[w] == -1){
				parent[w] = v;
				q.push(w);
			}
	}
	//수집한 부모노드 E -> S(7,5,3,1) 경로 복원 후 reverse (1,3,5,7)
	vector<int> path;
	for(int cur = E; cur != S; cur = parent[cur]) path.push_back(cur);
	path.push_back(S);
	reverse(path.begin(),path.end());
	int L = (int)path.size() - 1;
	
	
	vector<int> pos(N+1,-1);
	for(int i = 0; i < (int)path.size(); ++i) pos[path[i]] = i;
	//경로를 벗어남 검사 
	bool secondWins = false;
	for(int i = 0; i < L; ++i){
		if((i&1)==0) continue;
		int u = path[i];
		for(int w : g[u]){
			if(pos[w] == -1){
				secondWins = true;
				break;
			}
		}
		if(secondWins) break;
	}
	cout << (secondWins ? "Second" : "First") << "\n";
	return 0;
}
