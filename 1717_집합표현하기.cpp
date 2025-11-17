#include<iostream>
#include<vector>
using namespace std;
vector<int> arr;
int find(int a){
    //find parent node
    if(a == arr[a]) return a;
    else return arr[a] = find(arr[a]);
}
void union_func(int a,int b){
    //find a, b 's parent
    //union parents
    a = find(a);
    b = find(b);
    if(a != b) arr[b] = a;
}
bool check_same(int a,int b){
    a = find(a);
    b = find(b);
    if(a == b) return true;
    else return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M, q,a,b;
    cin >> N >> M;
    arr.resize(N+1);
    //init array
    for(int i = 1; i <= N; i++)
        arr[i] = i;

    for(int i = 0; i < M; i++){
        cin >> q >> a >> b;
        if(q == 0) union_func(a,b);
        else {
            if(check_same(a,b)) cout << "YES" << "\n";
            else cout << "NO" << "\n";
        }
        
    }
    return 0;
}