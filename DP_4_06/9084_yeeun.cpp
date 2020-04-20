#include <iostream>
#include <cstring>
#include <queue>

//백준 9084번
//동전
using namespace std;

int dp[10000];
int arr[21];
int result[1000];

int main(){
	int testN, coinN, money;
	queue<int> que;
	cin >> testN;

	while(testN != 0){
		cin >> coinN;
		for(int i=0; i<coinN; i++){
			cin >> arr[i];
		}
		cin >> money;

		dp[0] = 1; //0원을 만드는 방법은 한 가지 이다.

		for(int i=0; i<coinN; i++){
			for(int j=0; j<=money - arr[i]; j++){
				if(dp[j] ==0 && j%arr[i] == 0){ //아직 만들어진적 없는 금액인데, 지금 동전으로 만들 수 있을 때
					dp[j]++; //현재 dp값 증가
					dp[j+arr[i]] += dp[j]; //이 동전을 하나 더 써서 만들 수 있을 때 값 증가
				}
				else if(dp[j] != 0){ //만들어진 적 있는 금액일때,
					dp[j+arr[i]] += dp[j];
				}
			}
		}

		//이렇게 간단하게 짤 수 있다.
//		for(int i= 0; i<coinN; i++){
//			for(int j=arr[i]; j<=money; j++){
//				dp[j] += dp[j-arr[i]];
//			}
//		}
		cout << dp[money] << endl;
		memset(dp, 0, sizeof(dp));
		testN--;
	}

	return 0;
}




