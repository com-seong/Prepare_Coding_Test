#include <iostream>
using namespace std;

const int MAXN = 100;
int N, K;
int W[MAXN], V[MAXN];
int best = 0;

void dfs(int idx, int curW, int curV) {
    // 1. 무게 초과 시 중단
    if (curW > K) return;    //종료조건 1 

    // 2. 모든 물건 확인 완료    //종료조건 2 
    if (idx == N) {
        if (curV > best) best = curV;
        return;
    }
     //그냥 dfs는 한가지 조합 탐색 -> 방향이 한가지 뿐 
    // 3. 현재 물건을 안 담는 경우		 행동이 2개 분기로 분리 2^n 
    dfs(idx + 1, curW, curV);

    // 4. 현재 물건을 담는 경우
    dfs(idx + 1, curW + W[idx], curV + V[idx]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> W[i] >> V[i];

    dfs(0, 0, 0);

    cout << best << '\n';
    return 0;
}

