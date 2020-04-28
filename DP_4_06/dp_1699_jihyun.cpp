#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int S[100001]; //최소항의 개수
    int n; //자연수 N
    cin >> n;
    
    S[0]=0;
    S[1]=1; //1*1 = 1
    for(int i=2; i<=n; i++){ //자연수 N까지 LOOP
        S[i]=i;
        for(int j=1; j*j <= i ; j++){
            S[i]=min(S[i],S[i-j*j]+1); //S[i]와 j의 제곱이 최소항에 포함될 때 중 최소값
        }
    }
    cout << S[n];
    return 0;
}

//12 = 3^2 + 1 + 1 + 1 //4
//12 = 2^2 + 2^2 + 2^2 //3
