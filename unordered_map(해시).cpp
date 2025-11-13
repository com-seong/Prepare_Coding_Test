#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    cin >> N;

    unordered_map<string, bool> dance;
    dance["ChongChong"] = true;   // 시작 상태

    for (int i = 0; i < N; ++i) {
        string a, b;
        cin >> a >> b;

        // 존재하지 않으면 기본값 false로 생성됨 (operator[])
        bool da = dance[a];
        bool db = dance[b];

        if (da || db) {
            dance[a] = true;
            dance[b] = true;
        }
        // da==false && db==false면 아무 변화 없음
    }

    int cnt = 0;
    for (auto &kv : dance) if (kv.second) ++cnt;
    cout << cnt << '\n';
    return 0;
}

