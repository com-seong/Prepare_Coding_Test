#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> g;
vector<int> visited;
vector<int> ans;
int cnt = 1;
void dfs(int v){
    if(visited[v]) return;
    visited[v] = 1;
    ans[v] = cnt++;
    for(int i : g[v]){
        if(!visited[i])
         dfs(i);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M,R,s,e;
    cin >> N >> M >> R;
    g.resize(N+1);
    visited = vector<int> (N+1,0);
    ans.resize(N+1,0);
    for(int i = 0; i < M; i++){
        cin >> s >> e;
        g[s].push_back(e);
        g[e].push_back(s);
    }
    for(int i = 1; i <= N; i++)
        sort(g[i].begin(), g[i].end());
    
    dfs(R);
    for(int i = 1; i <= N; i++)
        cout << ans[i] << '\n';
    return 0;
}