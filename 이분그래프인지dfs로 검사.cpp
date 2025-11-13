#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> check;
bool isEven;
void dfs(int node,vector<vector<int>>& g,vector<int>& visited){
	visited[node] = 1;
	for(int i : g[node]){
		if(!visited[i]){  //È¦Â¦À¸·Î ÁýÇÕ ±¸ºÐ 
			check[i] = (check[node] + 1) % 2;
			dfs(i,g,visited);
		}
		else if(check[i] == check[node]) isEven = false;
	}
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K,V,E; 
    cin >> K;
    vector<vector<int>> g;
    vector<int> visited;
    while(K--){
    	cin >> V >> E;
    	g.resize(V+1);
    	visited.resize(V+1);
    	check.resize(V+1);
    	isEven = true;
    	for(int i = 0; i < E; i++){
    			int s,e;
  	 	 		cin >> s >> e;
  		  		g[s].push_back(e);
   		 		g[e].push_back(s);
		}
		for(int i = 1; i <= V; i++) 
			dfs(i,g,visited);
			
		if(isEven) cout << "YES" << "\n";
		else cout << "NO" << "\n";
		for(int i = 0; i <= V; i++){
			g[i].clear();
			visited[i] = 0;
			check[i] = 0;
		}
	}
	
    return 0;
}

