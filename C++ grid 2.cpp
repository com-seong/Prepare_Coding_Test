#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int dr[4] = {-1,0,1,0};
int dc[4] = {0,-1,0,1};
int N;
static vector<vector<int>> grid;
static vector<vector<bool>> visited;
void bfs(int r,int c,int w)
{
	queue<pair<int,int>> q;
	visited[r][c] = true;
	q.push({r,c});
	while(!q.empty()){
		auto cur = q.front();
		q.pop();
		int cr = cur.first;
		int cc = cur.second;
		
		for(int i = 0; i < 4; ++i){
			int nr = cr + dr[i];
			int nc = cc + dc[i];
			if(nr >= 0 && nr < N && nc >= 0 && nc < N){
				if(!visited[nr][nc] && grid[nr][nc] > w){
					visited[nr][nc] = true;
					q.push({nr,nc});
				}
			}
		}
	}
}
int main()
{
	cin >> N;
	grid.assign(N,vector<int>(N,0));
	int hi=0;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			cin >> grid[i][j];
			//가장 높은 지점 기록 
			if(grid[i][j] > hi) hi = grid[i][j];
		}
	}

	int res = 0,max = 0;
	for(int w = 0; w <= hi; ++w){
		visited.assign(N,vector<bool> (N,false));
		res = 0;
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < N; ++j){
				if(!visited[i][j] && grid[i][j] > w){
					bfs(i,j,w);
					res++;
				}
			}
		}
		if(res > max) max = res;
	}
	cout << max;
	return 0;
}
