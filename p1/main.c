#include <stdio.h>
#include <stdbool.h>

int main()
{
    int N = 0, i, j, k;     // N: 목표 값, i/j/k: 각각 900, 750, 200의 개수
    bool count = false;     // 조건을 만족하는 경우가 있는지 체크하는 변수

    scanf("%d", &N);        // 사용자로부터 정수 N 입력받기
    
    // i는 900의 개수 (최대 N/900까지 가능)
    for (i = 1; i <= N / 900; i++) {
        
        // j는 750의 개수 (짝수만 사용: 2부터 시작해서 2씩 증가)
        for (j = 2; j <= N / 750; j += 2) {
            
            // k는 200의 개수 (최대 N/200까지 가능)
            for (k = 1; k <= N / 200; k++) {
                
                // 현재 조합의 총합 계산
                int sum = (900 * i) + (750 * j) + (200 * k);
                
                // 잔돈이 남지 않을 때
                if (sum == N) {
                    
                    // k가 i보다 작거나 또는 j보다 작은 경우만 출력
                    if (k < i || k < j) {
                        printf("%d %d %d\n", i, j, k);       // 조건 만족 시 출력
                        count = true;                      // 결과가 하나라도 있음을 표시
                    }
                }
            }
        }
    }
    
    // 조건을 만족하는 경우가 하나도 없을 때
    if (count == false) {
        printf("none");
    }
    
    return 0;
}
