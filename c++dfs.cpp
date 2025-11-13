#include<iostream>
#include<vector>
using namespace std;
static vector<vector<int>> A;
static vector<bool> visited;
void dfs(int v);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N,M,s,e;
	cin >> N >> M;
	A.resize(N+1);         //벡터 초기화 
	visited = vector<bool>(N+1,false);  //방문 벡터 초기화 
	for(int i = 0; i < M; ++i){
		cin >> s >> e;
		A[s].push_back(e);         //2차원 벡터를 생성하고 각 행에 push_back을 함으로써 인접리스트처럼 
		A[e].push_back(s);        //표현 
	}
	int count = 0;
	for(int i = 1; i <= N; ++i){
		if(!visited[i]){
			count++;
			dfs(i);
		}
	}
	cout << count;
	return 0;
}
void dfs(int v)
{
	if(visited[v]) return;   //방문 했다면 return 
	visited[v] = true;      // 방문 배열을 방문 표시 
	for(int u : A[v]){        //u가 다시 v로  
		if(!visited[u])       //방문하지 않았다면 dfs 
			dfs(u);
	}
}
