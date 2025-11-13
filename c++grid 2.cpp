#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> map;
vector<vector<int>> visited;
int dr[4] = {-1,0,1,0};
int dc[4] = {0,-1,0,1};
int M,N;
void dfs(int r,int c){
	if(r >= N || r < 0 || c >= M || c < 0) return;
	if(visited[r][c]) return;
	if(map[r][c] == 0) return;
	
	visited[r][c] = 1;
	
	for(int k = 0; k < 4; k++){
		int nr = r + dr[k];
		int nc = c + dc[k];
		dfs(nr,nc);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T,x,y;
	cin >> T;
	int K;
	
	for(int i = 0; i < T; i++){
		cin >> M >> N >> K;
		map.assign(N,vector<int> (M,0));
		visited.assign(N,vector<int> (M,0));
		
		for(int k = 0; k < K; k++){
			cin >> x >> y;
			map[y][x] = 1;
		} 
		
		int res = 0;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(map[i][j] == 1 && !visited[i][j]){
					res++;
					dfs(i,j);
				}
			}
		}
		
		cout << res << "\n";
	}
	return 0;
}
