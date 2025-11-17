#include<iostream>
#include<vector>
using namespace std;
vector<int> parent;
int find(int a) {
    if(a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
}
void union_func(int a,int b) {
    a = find(a);
    b = find(b);
    if(a != b) parent[b] = a;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M;
    cin >> N;
    cin >> M;
    parent.resize(N+1);
    for(int i = 1; i <= N; i++) parent[i] = i;
    int map[201][201];
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> map[i][j];  
        }
    }
    int route[1001];
    for(int i = 1; i <= M; i++){
        cin >> route[i];
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(map[i][j] == 1) union_func(i,j);
        }
    } 
    int idx = find(route[1]);
    bool connect = true;
    for(int i = 2; i <= M; i++){
        if(idx != find(route[i])) {
            cout << "NO" << "\n";
            connect = false;
            break;
        }
    }
    if(connect) cout << "YES" << "\n";
    return 0;
}