#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>
#include <vector>

//벽 부수고 이동하는 문제
//백준 2206번 문제
using namespace std;

int nXm[1001][1001];
int visited[1001][1001][2];
int dir[4][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}}; //위, 좌, 하, 우
int bfs(int i, int j, int N, int M);

int main(){

	int fi=0, fj=0;
	int N, M;

	cin >> N >> M;

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			scanf("%1d", &nXm[i][j]);
		}
	}

	visited[fi][fj][1] = 1;

	cout << bfs(fi, fj, N, M);

	return 0;
}

int bfs(int i, int j, int N, int M){
	queue<pair<pair<int, int>, int>> que;
	que.push(make_pair(make_pair(i, j), 1));

	while(!que.empty()){
		int y = que.front().first.first;
		int x = que.front().first.second;
		int wall = que.front().second;
		que.pop();

		if(y == N-1 && x == M-1) return visited[y][x][wall];

		for(int i=0; i<4; i++){ //상, 하, 좌, 우 확인
			int next_x = x + dir[i][1];
			int next_y = y + dir[i][0];

			if(next_x >= 0 && next_x < M && next_y >= 0 && next_y < N){
				if(nXm[next_y][next_x] == 0 && visited[next_y][next_x][wall] == 0 ){ //벽없고, 방문 x
					que.push(make_pair(make_pair(next_y, next_x), wall));
					visited[next_y][next_x][wall] = visited[y][x][wall] + 1;
				}
				else if (nXm[next_y][next_x] == 1 && wall){ //벽있고, 벽 안뚫림.
					visited[next_y][next_x][wall-1] = visited[y][x][wall] + 1; //wall-1 은 벽이 뚫렸음을 의미
					que.push(make_pair(make_pair(next_y, next_x), wall-1));
				}
			}
		}
	}

	return -1;
}
