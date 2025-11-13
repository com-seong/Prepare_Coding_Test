#include<iostream>
#include<vector>
#include<queue>
using namespace std;
static vector<vector<int>> grid;
static vector<vector<int>> visited;
int dr[4] = {-1,0,1,0};
int dc[4] = {0,-1,0,1};
int n,m,cnt;
void bfs(int r,int c){
	cnt = 1;
	queue<pair<int,int>> q;
	q.push({r,c});
	visited[r][c] = 1;
	while(!q.empty()){
		auto cur = q.front();
		q.pop();
		int cr = cur.first;
		int cc = cur.second;
		for(int i = 0; i < 4; i++){
			int nr = cr + dr[i];
			int mc = cc + dc[i];
			if(nr >= 0 && nr < n && mc >= 0 && mc < m){
				if(!visited[nr][mc] && grid[nr][mc]){
					visited[nr][mc] = 1;
					q.push({nr,mc});
					cnt++;
				}
			}		
		}	
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	grid.assign(n,vector<int> (m,0));
	visited.assign(n,vector<int> (m,0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> grid[i][j];
		}
	}
	int res = 0; int max = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!visited[i][j] && grid[i][j]){
				bfs(i,j);
				res++;
				if(cnt > max) max = cnt;
			}
		}
	}
	cout << res << "\n";
	cout << max;
	return 0;
}
