// 그리디 1080

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[50][50], b[50][50];

void change(int n, int m) { // 뒤집는 함수
    for(int i = n; i <= n+2; i++) {
        for(int j = m; j <= m+2; j++) {
            a[i][j] = 1 - a[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio();
    cin.tie(NULL);
    
    int N, M;
    
    cin >> N >> M;
    
    int count = 0; // 최소 횟수 저장 변수
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%1d", &a[i][j]);
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%1d", &b[i][j]);
        }
    }
    
    for(int i = 0; i < N-2; i++) {
        for(int j = 0; j < M-2; j++) {
            if(a[i][j] != b[i][j]) {    // 다르면 변경
                change(i,j);
                count++;    //뒤집기 때문에
            }
        }
    }
    
    int check = 0;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(a[i][j] != b[i][j]) {
                count = -1;
                check = 1;
                break;
            }
            if(check == 1)
                break;
        }
    }
    
    cout << count << endl;
    
    return 0;
}