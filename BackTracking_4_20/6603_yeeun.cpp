//백준 6603번
//로또
#include <iostream>

using namespace std;

int arr[49]; //집합S 배열
int result[7]; //결과 배열
void backT(int x, int n, int apt);

int main() {
	int n = 1;	//while을 돌기위해 처음에 1로 선언

	while(n!=0){ //0을입력받으면 종료
		cin >> n;
		if(n==0) break; //0을 입력받으면 종료
		for(int i=0; i<n; i++){ //집합S입력 받음
			cin >> arr[i];
		}

		backT(0, n, 0);	//트리탐색 시작
		cout << endl;
	}


	return 0;
}

void backT(int x, int n, int apt){
	if(x==6){	//result배열이 모두 찼을때
		for(int i=0; i<6; i++){
			cout << result[i] << " ";
		}
		cout << endl;
		return;
	}

	for(int i=apt; i<n; i++){ //result배열에 오름차순으로 값 저장
		result[x] = arr[i];
		backT(x+1, n, i+1); //배열의 다음칸에는
	}
}
