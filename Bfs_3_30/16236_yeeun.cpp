#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <cstring>

//아기상어 문제
//백준 16236번
using namespace std;

int space[1000][1000];
int visited[1000][1000];
int dir[4][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}}; //위, 좌, 하, 우
int shark=2;
int fish=0;
int time=0;
int now_x, now_y;
int minV;
vector <pair<int,int>> eat;

void bfs(int i, int j, int N);

int main(){
	int N, shark_i, shark_j;
	cin >> N;

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> space[i][j];
			//0은 빈칸, 1 2 3 4 5 6은 물고기의 크기, 9는 상어의 위치
			if(space[i][j] == 9){
				shark_i=i;
				shark_j=j;
			}
		}
	}
	space[shark_i][shark_j] = 0;


	while(true){
		bfs(shark_i, shark_j, N);

		if(eat.empty()) break;

		else{
			if(eat.size()==1){
				shark_i = now_y;
				shark_j = now_x;
			}
			else{ //먹을 수 있는 물고기가 2개 이상일 때, 가장 가까운 거 부터 먹음.
				for(int i=0; i<eat.size(); i++){
					int y = eat[i].first;
					int x = eat[i].second;

					if(visited[y][x] == minV) { //같은 거리일 때

						if(now_y == y){ //높이가 같을 때

							if(now_x > x){ //왼쪽부터

								now_x = x;
								now_y = y;
							}
						}
						else if(now_y > y){ //더 가까운게 존재할 때
							now_x = x;
							now_y = y;
						}
					}
				}
			}
			fish++;
			shark_i = now_y;
			shark_j = now_x;
			space[shark_i][shark_j] = 0;

			time += visited[shark_i][shark_j]; //거리는 누적해서 더해줌
			if(shark == fish){
				shark++;
				fish = 0;
			}
		}
	}

	cout << time;


	return 0;
}

void bfs(int i, int j, int N){
	minV = 9999999;
	eat.clear();
	queue<pair<int, int>> que;
	que.push(pair<int, int>(i, j));
	memset(visited, 0, sizeof(visited)); //visited를 모두 0으로 초기화

	while(!que.empty()){
		int y = que.front().first;
		int x = que.front().second;
		que.pop();

		for(int i=0; i<4; i++){ 
			int next_x = x + dir[i][1];
			int next_y = y + dir[i][0];
			if(next_x >= 0 && next_x < N && next_y >= 0 && next_y < N){ 
				if(space[next_y][next_x] <= shark && visited[next_y][next_x] == 0){
					visited[next_y][next_x] = visited[y][x] + 1;
					if(space[next_y][next_x] != 0 && space[next_y][next_x] < shark){ //먹을 수 있는 물고기
						if(minV >= visited[next_y][next_x]){ //minV는 상어위치와의 거리 최솟값
							eat.push_back(make_pair(next_y, next_x));
							minV = visited[next_y][next_x];
							now_x = next_x;
							now_y = next_y;
						}
					}
					que.push(pair<int ,int>(next_y, next_x));
				}
			}
		}
	}
}


