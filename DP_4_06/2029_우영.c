// 우영
#include <stdio.h>
 
int dp[210][4010];
int numbers[210];
 
int main(void){
 
    int t, a, s, b;
    int total = 0;
    scanf("%d %d %d %d", &t, &a, &s, &b);
    dp[0][0] = 1;
    
    //숫자를 받는 과정 
    for (int i = 0; i < A; i++)
    {
        int temp;
        scanf("%d", &temp);
        numbers[temp]++;
    }
    //연산속도가 빠른 언어 C C++의 경우에는 3차 반복문까지도 런타임 안걸림. 
    //DP로 푼 경우.
    for (int i = 1; i <= T; i++)
    {
        // 숫자 하나로만 만들 경우 추가하는 연산.
        for (int k = 0; k <= numbers[i]; k++){
            dp[i][k] += 1;
        }
        
        for (int j = 1; j <= A; j++){
            // 전에 있는 숫자들의 조합 그대로 가져옴.
            dp[i][j] += dp[i - 1][j];
            // 새로운 숫자들과 지난번에 있는 숫자들로 추가해서 새로운 조합을 만들어 냅니다.
            for (int k = 1; k <= numbers[i]; k++){
                if (j - k>0){
                    dp[i][j] += dp[i - 1][j - k];
                    dp[i][j] %=1000000;
                }
            }
        }
    }
    //덧셈과정 + 숫자 나눠주기.
    for (int i = S; i <= B; i++)
        total += dp[T][i] % 1000000;
 
    printf("%d\n", total % 1000000);
 
 
    return 0;
}