#include <iostream>
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<limits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    if (!(cin >> N >> K)) return 0;
	
    vector<long long> A(N);           // gifts
    for (int i = 0; i < N; ++i) cin >> A[i];

    vector<long long> B(N);           // boxes
    for (int i = 0; i < N; ++i) cin >> B[i];

    // 앞사람이 가져간 상자 크기 빈도 차감
    unordered_map<long long, int> rm;
    //reserve 용량확보 
    rm.reserve(K * 2);
    for (int i = 0; i < K; ++i) {
        long long x; cin >> x;
        rm[x]++;
    }

    // 남은 상자 목록 구성
    vector<long long> boxes;
    //용량 확보 
    boxes.reserve(N - K);
    for (long long x : B) {
        auto it = rm.find(x); //value를 앞사람이 가져간 횟수로 사용 
        if (it != rm.end() && it->second > 0) {
            (it->second)--;           // 이 상자는 앞사람에게 간 것
        } else {
            boxes.push_back(x);       // 남아 있는 상자
        }
    }
    // 남은 상자 중 최댓값을 우리 상자로 선택
    				  //최댓값 위치	
    long long myBox = *max_element(boxes.begin(), boxes.end());

    // 우리 상자 1개 제거 → 나머지 작은 상자 배열
    bool removed = false;
    vector<long long> smallBoxes; smallBoxes.reserve(boxes.size() - 1);
    for (long long x : boxes) {
        if (!removed && x == myBox) { removed = true; continue; }
        smallBoxes.push_back(x);
    }

    // 정렬
    sort(A.begin(), A.end());                  // 선물: 오름차순
    sort(smallBoxes.begin(), smallBoxes.end()); // 작은 상자: 오름차순

    // 작은 상자부터, 가장 작은 선물 배정(그리디)
    // 투포인터: gi = 아직 배정되지 않은 가장 작은 선물의 인덱스
    int gi = 0;
    for (long long bx : smallBoxes) {
        if (gi >= N) { /*이론상 불가(문제 보장)*/ break; }
        if (A[gi] <= bx) {
            // 가장 작은 선물을 이 상자에 배정
            gi++;
        } else {
            // 현재 가장 작은 선물조차 bx에 못 들어가면 전역 배치 불가
            // (문제에서 항상 가능하다고 보장하므로 실제 입력에선 발생하지 않음)
            cout << -1 << "\n";
            return 0;
        }
    }

    // 이제 남은 선물은 [gi .. N-1].
    // 그 중 myBox 이하의 최댓값을 선택
    // upper_bound로 myBox를 초과하는 첫 위치를 찾고 한 칸 뒤로
    //반복자 반환 
    auto it = upper_bound(A.begin() + gi, A.end(), myBox);
    if (it == A.begin() + gi) {
        // myBox 이하의 남은 선물이 없다면, 어떤 배정으로도 우리 상자를 채울 수 없음
        // (문제 보장상 이 케이스는 발생하지 않음)
        cout << -1 << "\n";
        return 0;
    }
    it--;
    //역참조로 값 반환 
    cout << *it << "\n";
    return 0;
}

