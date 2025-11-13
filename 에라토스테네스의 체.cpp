#include <stdio.h>

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[1001] = {0};  // 인덱스 2 ~ n 사용
    int count = 0;

    for (int i = 2; i <= n; i++) {
        if (arr[i] == 0) {  // 아직 지워지지 않은 수라면
            for (int j = i; j <= n; j += i) {
                if (arr[j] == 0) {
                    arr[j] = 1;  // 지운 표시
                    count++;
                    if (count == k) {
                        printf("%d\n", j);
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}

