#include<iostream>
using namespace std;

int n, m;
int map[51][51];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int ans;
void dfs(int cx, int cy, int cd) {
	if (map[cx][cy] == 0) { //청소 완료 표시 
		map[cx][cy] = 2;
		ans++;
	}

	for (int i = 0; i < 4; i++) {   //4곳 확인 
		int nd = (cd + 3 - i) % 4;
		int nx = cx + dx[nd];
		int ny = cy + dy[nd];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
			continue;
		}

		if (map[nx][ny] == 0) {  //청소할 곳 있다.  
			dfs(nx, ny, nd);  //전진 
			return;
		}
	}    
	int nd = (cd + 2) % 4; //뒤 확인 
	int nx = cx + dx[nd]; 
	int ny = cy + dy[nd];

	if (map[nx][ny] == 1) { //뒤가 벽 -> 종료 
		cout << ans;
		exit(0);
	}
	//뒤가 벽 X 재탐색 
	dfs(nx, ny, cd); //후진 앞에서는 이동할 곳이 없었고,
 					 //여기서는 “뒤로 이동할 수 있다면 계속 탐색”
}
int main(void) {
	cin >> n >> m;

	int r, c, dir;
	cin >> r >> c >> dir;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	dfs(r, c, dir);

	return 0;
}
