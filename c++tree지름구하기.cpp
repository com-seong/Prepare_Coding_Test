#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef pair<int,int> edge;
static vector<vector<edge>> G;
static vector<bool> visited;
static vector<int> dist;
void bfs(int v)
{
	queue<int> my_queue;
	visited[v] = true;
	my_queue.push(v);
	
	while(!my_queue.empty()){
		int u = my_queue.front();
		my_queue.pop();
		for(edge i : G[u]){
			if(!visited[i.first]){
				visited[i.first] = true;
				my_queue.push(i.first);
				dist[i.first] = dist[u] + i.second;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int V;
	cin >> V;
	G.resize(V+1);
	dist.resize(V+1,0);
	visited = vector<bool> (V+1,false);
	for(int i = 0; i < V; ++i){
		int v;
		cin >> v;
		while(true){
			int u,w;
			cin >> u;
			if(u == -1) break;
			cin >> w;
			G[v].push_back(edge(u,w));
		}
	}
	bfs(1);   //임의의 정점에서 bfs + 거리배열 업데이트 
	int max = 1;
	for(int i = 2; i <= V; ++i)
		if(dist[max] < dist[i]) max = i;   //가장 먼 정점 찾기 
		
	fill(dist.begin(),dist.end(),0);
	fill(visited.begin(),visited.end(),false);
	bfs(max); //가장 먼 정점에서 bfs + 거리배열 업데이트 
	sort(dist.begin(),dist.end());
	cout << dist[V]; //가장 먼 곳. 
	return 0;
}
