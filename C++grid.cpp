#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int dr[4] = {-1,0,1,0};
int dc[4] = {0,-1,0,1};
int N;
void dfs(int r,int c,vector<vector<int>> &grid,vector<vector<bool>> &visited,int &cnt)
{
	if(r < 0 || c < 0 || r >= N || c >= N) return;
	if(visited[r][c]) return;
	if(grid[r][c] == 0) return;
	
	visited[r][c] = true;
	cnt++;
	
	for(int k = 0;  k < 4; ++k){
		int nr = r + dr[k];
		int nc = c + dc[k];
		dfs(nr,nc,grid,visited,cnt);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> N;
	vector<vector<int>> grid(N,vector<int> (N,0));
	vector<vector<bool>> visited(N,vector<bool>(N,false));
	vector<int> cntVec;
	for(int i = 0; i < N; ++i){
		string s;
		cin >> s;		
		for(int j = 0; j < N; ++j)
			grid[i][j] = s[j] - '0';
	}
	int res = 0;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			int cnt = 0;
			if(grid[i][j] == 1 && !visited[i][j]){ //참조전달이라 필요없긴 하지만 이게 정석 
				dfs(i,j,grid,visited,cnt);
				if(cnt > 0){
					cntVec.push_back(cnt);
					res++;
				}
			}
		}
	}
	sort(cntVec.begin(),cntVec.end());
	cout << res << "\n";
	for(int x : cntVec){
		cout << x << "\n";
	}
	return 0;
}
