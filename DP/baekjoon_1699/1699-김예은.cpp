#include <iostream>
#include <math.h>
//백준 1699번
//제곱수의 합
using namespace std;

int dp[100001];

int main(){
	int N;
	int minN = 100001;
	cin >> N;

	for(int i=1; i<=N; i++) dp[i] = i;

	for(int i=1; i<=N; i++){
		for(int j=2; j*j<=i; j++){
			dp[i] = min(dp[i], dp[i-j*j] + 1);
		}
	}

//	for(int i=1; i*i<=N; i++){ //실패한 코드
//		dp[i*i] = 1;
//		for(int j=i*i + 1; j<=N; j++){
//			dp[j] = dp[j - i*i] + 1;
//		}
//		if(minN > dp[N]){ //가장 작은 갯수로 N을 만든 경우
//			minN = dp[N];
//		}
//	}
	cout << dp[N];

	return 0;
}



