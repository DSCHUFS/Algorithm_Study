/*
 암호 맞추는 프로그램
 암호는 대충 알파벳 순서대로
 조건: 자음 2개 이상, 모음 2개 이상
 백트래킹
 */


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int L; // 암호 길이
int C; // 주어지는 알파벳 길이
vector<char> v; // 알파벳 저장 vector 생성

void make_pwd(int tmp, string pw, int ja, int mo) { // 암호 생성 함수
    
    if(pw.size() == L) {
        if( ja >= 2 && mo >= 1)
            cout << pw << endl;
    }
    for(int i = tmp; i < C; i++) {
        if(v[i] == 'a' || v[i] == 'e' || v[i] == 'o' || v[i] == 'u' || v[i] == 'i')
            make_pwd(i+1,pw+v[i],ja,mo+1);
        else
            make_pwd(i+1,pw+v[i], ja+1, mo);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    

    
    cin >> L >> C;
    
    
    
    for(int i = 0; i < C; i++) { // 입력해서 다 넣기
        char a;
        cin >> a;
        v.push_back(a);
    }
    
    sort(v.begin(), v.end()); // 정렬
    
    make_pwd(0, "", 0, 0); // 함수 실행
    
    return 0;
}
