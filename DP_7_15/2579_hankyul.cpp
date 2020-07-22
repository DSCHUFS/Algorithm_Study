/*
    dp
    계단 최댓수 구하기
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int stairs;

int main() {
    ios::sync_with_stdio();
    cin.tie(NULL);

    cin >> stairs;

    int dp[stairs];
    int s[stairs];

    for(int i = 0; i < stairs; i++) {
        cin >> s[i];
    }

    dp[0] = s[0];
    dp[1] = max(s[1], s[0]+s[1]);
    dp[2] = max(s[0]+s[2], s[1]+s[2]);

    for(int i = 3; i < stairs; i++) {
        dp[i] = max(dp[i-2]+s[i], dp[i-3]+s[i-1]+s[i]);
    }
    
    cout << dp[stairs-1];
    return 0;
}