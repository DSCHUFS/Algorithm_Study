//백준 2875번
//대회 or 인턴
//그리디 알고리즘은 미리 정한 기준에 따라 매번 가장 최적인 해를 구하는 알고리즘
//팀은 여학생 2명 + 남학생 1명으로 이루어진다
//k명은 인턴쉽을 참가하는대신 대회는 나가지 못한다.
//만들 수 있는 가장 많은 팀의 갯수는?

#include <iostream>

using namespace std;

int main(){
	int N, M, K;
	int result = 0;
	cin >> N >> M >> K;
	int n=N, m=M, k=K;
	int people=0;

	//처음엔 k를 생각하지 않고, 여학생 남학생 수로 만들 수 있는 가장 많은 팀 갯수를 먼저 세준다.
	//그리고 나서, k만큼 필요한 인원을 계산해서 팀 갯수에서 빼준다.

	if(N >= M){
		if(n >= M*2){
			result = M;
			n -= M*2;
			m = 0;
		}
		else{
			result = n/2;
			n -= result*2;
			m -= N/2;
		}
	}
	else{ //N<M
		result = N/2;
		n -= result*2;
		m -= result;
	}

	people = n+m;
	if(people < K){
		k -= people;
		for(int i=0; i*3 < k; i++){
			result--;
		}
	}
	cout << result;
	return 0;
}

//이렇게 반복문으로 표현할 수도 있다.
//while (1) {
//	if (K <= (N - 2 + M - 1) && N>=2 && M>=1) {
//		N -= 2;
//		M -= 1;
//		num++;
//	}
//	else break;
//}
