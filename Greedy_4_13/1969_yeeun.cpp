//백준 1969번
//DNA
//hamming distance합이 최소가 되는 DNA찾기

#include <iostream>
#include <string>

using namespace std;

string DNA[1001]; //DNA들을 입력받을 string 배열
int bindo[4]; //0=A, 1=C, 2=G, 3=T

int main(){
	int N, M;
	int hamingdistance=0; //해밍거리 변수
	string result; //결과 DNA를 저장할 변수
	cin >> N >> M;

	for(int i=0; i<N; i++){ //DNA값들을 입력 받는다.
		cin >> DNA[i];
	}

	for(int i=0; i<M; i++){ //큰 for문은 index num
		for(int j=0; j<N; j++){ //작은 for문은 DNA 0부터 N까지
			if(DNA[j][i] == 'A'){ //빈도를 측정한다.
				bindo[0]++;
			}
			else if(DNA[j][i] == 'C'){
				bindo[1]++;
			}
			else if(DNA[j][i] == 'G'){
				bindo[2]++;
			}
			else{
				bindo[3]++;
			}
		}
		int maxn = 0; //가장 빈도가 높은 DNA를 알아낸다. ACGT중 누구?
		int alpha =0; //가장 빈도가 높은 DNA위치를 알아야 알파벳을 알 수 있다.

		for(int j=0; j<4; j++){
			if(bindo[j] > maxn){
				//빈도가 가장 큰 값을 찾는다. 빈도가 같을 경우, 사전식 순서가 우선순위 이므로, =은 넣지 않는다.
				maxn = bindo[j];
				alpha = j;
			}
			bindo[j] = 0; //다음 index를 조사해야 하므로, 0으로 초기화 해준다.
		}

		hamingdistance += (N - maxn); //해밍거리는 계속 누적해준다.

		if(alpha == 0) result.insert(i, "A"); //결과에다 DNA를 저장해준다.
		else if(alpha == 1) result.insert(i, "C");
		else if(alpha == 2) result.insert(i, "G");
		else {result.insert(i, "T");};
	}

	cout << result << endl;
	cout << hamingdistance << endl;

	return 0;
}




