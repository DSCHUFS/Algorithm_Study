#include <iostream>
//i에서 j로 갈 수 있다면 1을 출력
//경로 찾기 문제. 백준 11403번
using namespace std;

int graph[1000][1000];
int result[1000][1000];
int visited[1000];

void dfs(int i, int N);

int main(){

	int N;
	cin >> N;

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> graph[i][j];
		}
	}

	for(int i=0; i<N; i++){
		dfs(i, N);
		for(int j=0; j<N; j++){
			result[i][j] = visited[j];
		}
		for(int k=0; k<N; k++){
			visited[k] = 0;
		}
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout << result[i][j] << " ";
		}
		cout <<"\n";
	}


	return 0;
}

void dfs(int i, int N){
	for(int k=0; k<N; k++){
		if(graph[i][k]==1 && visited[k] != 1){
			visited[k] = 1;
			dfs(k, N);
		}
	}

}

