#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
static vector<vector<int>> A;
static vector<bool> visited;

void dfs(int v)
{
	cout << v << " ";
	visited[v] = true;
	for(int u : A[v])
		if(!visited[u]) dfs(u);
}
void bfs(int v)
{
	queue<int> myqueue;
	myqueue.push(v);
	visited[v] = true;
	
	while(!myqueue.empty()){
		int u = myqueue.front();
		myqueue.pop();
		cout << u << " ";
		for(int w : A[u])
			if(!visited[w]){
				visited[w] = true;
				myqueue.push(w);
			}
	}	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N,M,Start;
	cin >> N >> M >> Start;
	A.resize(N+1);
	
	for(int i = 0; i < M; ++i){
		int s,e;
		cin >> s >> e;
		A[s].push_back(e);
		A[e].push_back(s);
	}
	for(int i = 1; i <= N; ++i)
		sort(A[i].begin(),A[i].end());
		
	visited = vector<bool> (N+1,false);
	
	dfs(Start);
	cout << "\n";
	
	fill(visited.begin(),visited.end(),false); //방문배열 초기화 
	
	bfs(Start);
	cout << "\n";
	
	return 0;
}
