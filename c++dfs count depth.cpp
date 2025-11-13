#include<iostream>
#include<vector>
using namespace std;
static bool arrive;
static vector<vector<int>> A;
static vector<bool> visited;

void dfs(int v,int depth)
{
	if(depth == 5 || arrive){
		arrive = true;
		return;
	}
	visited[v] = true;
	for(int i : A[v])
		if(!visited[i])
			dfs(i,depth+1);
	visited[v] = false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N,M;
	cin >> N >> M;
	A.resize(N);
	visited = vector<bool> (N,false);
	arrive = false;
	for(int i = 0; i < M; ++i){
		int s,e;
		cin >> s >> e;
		A[s].push_back(e);
		A[e].push_back(s);
	}
	for(int i = 0; i < N; ++i){
		dfs(i,1);	
		if(arrive) break;
	}
	if(arrive) cout << 1 << "\n";
	else cout << 0 << "\n";
	
	return 0;
}
