#include<iostream>
#include<queue>
using namespace std;
int sender[]={0,0,1,1,2,2};
int receiver[]={1,2,0,2,0,1};
bool visited[201][201];
bool answer[201];
int now[3];
void bfs(){
    queue<pair<int,int>> queue;
    queue.push(make_pair(0,0));
    visited[0][0] = true;
    answer[now[2]] = true;

    while(!queue.empty()){
        pair<int,int> p = queue.front();
        queue.pop();
        int A = p.first;
        int B = p.second;
        int C = now[2] - A - B;

        for(int k = 0; k < 6; k++){
            int next[] = {A,B,C};
            next[receiver[k]] += next[sender[k]];
            next[sender[k]] = 0;

            if(next[receiver[k]] > now[receiver[k]]){
                next[sender[k]] = next[receiver[k]] - now[receiver[k]];
                next[receiver[k]] = now[receiver[k]];
            }
            if(!visited[next[0]][next[1]]){
                visited[next[0]][next[1]] = true;
                queue.push(make_pair(next[0],next[1]));
                if(next[0] == 0) answer[next[2]] = true;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> now[0] >> now[1] >> now[2];
    bfs();
    for(int i = 0; i < 201; i++){
        if(answer[i]) cout << i << ' ';
    }
    return 0;
}