// dp 동전 갯수

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio();
    cin.tie(NULL);
    
    int T; // 수행하는 TC 갯수
    int N; // 동전 갯수
    int M; // 만들어야 하는 금액
    int coin[21] = {0,}; // 동전 가짓수 저장하는 배열
    
    
    cin >> T;
    
    for(int i = 0; i < T; i++) {
        cin >> N;
        for(int j = 1; j <= N; j++) {
            cin >> coin[j];
        }
        cin >> M;
        int sol[10001] = {0,}; // 금액별 만드는 방법 저장하는 배열
        sol[0] = 1; // 초기값
        
        for(int i = 1; i <= N; i++) {
            for(int j = coin[i]; j <= M; j++) {
                sol[j] += sol[ j - coin[i] ];
            }
        }
        cout << sol[M] << endl;
        
    }
    return 0;
}
