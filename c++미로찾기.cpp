#include<iostream>
#include<queue>
using namespace std;

static int dx[] = {0,1,0,-1};		//dx[] = {1,-1,0,0,0,0}
static int dy[] = {1,0,-1,0};		//dy[]={0,0,1,-1,0,0}
static int A[101][101];				//dz[]={0,0,0,0,1,-1}
static bool visited[101][101] = {false};
static int N,M;

void bfs(int X,int Y)
{
	queue<pair<int,int>> myqueue; 		 //좌표 
	myqueue.push(make_pair(X,Y)); //queue[(x,y) , (x,y), (x,y), . . . .] 
	//일단 하나 넣고 
	while(!myqueue.empty()){
		int now[2];
		now[0] = myqueue.front().first;  //하나 꺼내고 
		now[1] = myqueue.front().second;
		myqueue.pop();
		visited[X][Y] = true;	//방문표시 하고 
		
		for(int k = 0; k < 4; ++k){ //갈 수 있는 k로 이동 (인접 정점)
			int x = now[0] + dx[k]; //갈 수 있는지 없는지 판단 (상 하 좌 우)
			int y = now[1] + dy[k];
			
			if(x >= 0 && y >= 0 && x < N && y < M){ //경계에 있고 
				if(A[x][y] != 0 && !visited[x][y]){  //0 이 아니고(갈 수 있고) 방문 x면 
					visited[x][y] = true;	//방문 표시 하고 
					A[x][y] = A[now[0]][now[1]] + 1; //갈 수 있으면 그 부분 ++ 
					myqueue.push(make_pair(x,y)); //push
				}
			}
		}
	}
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> N >> M;
	for(int i = 0; i < N; ++i){
		string s;
		cin >> s;
		for(int j = 0; j < M; ++j)
			A[i][j] = s[j] - '0';
	}
	bfs(0,0);
	cout << A[N-1][M-1];
	return 0;
}
