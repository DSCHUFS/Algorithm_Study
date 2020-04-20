// BFS, DFS 미로 + 벽 뿌수기

#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int N, M;

const int MAX = 1001;
int visit[MAX][MAX][2] = {0,};
int house[MAX][MAX];

//상하좌우용

int dx[4] = { 0, 0, -1, 1};
int dy[4] = { 1, -1, 0, 0};
int block;

void bfs(int x, int y) {
    queue<pair<pair<int, int>,int>> q;

    visit[x][y][1] = 1; 
    q.push(make_pair(make_pair(x, y),1));

    pair<pair<int, int>,int> a;

    while(!q.empty()) {
        a = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = a.first.first + dx[i];
            int ny = a.first.second + dy[i];
            block = a.second;
            

            if( 0 <= nx && nx < N && 0 <= ny && ny < M) {
                if(visit[nx][ny][block] == 0 && block == 1 && house[nx][ny] == 1) { //벽 O 안뚫림
                    q.push(make_pair(make_pair(nx, ny),block-1));
                    visit[nx][ny][block-1] = visit[a.first.first][a.first.second][block] + 1;
                }
                if(visit[nx][ny][block] == 0 && house[nx][ny] == 0) { //벽 X 안둟림
                    q.push(make_pair(make_pair(nx, ny),block));
                    visit[nx][ny][block] = visit[a.first.first][a.first.second][block] + 1;
                }
            }
        }
    }


}

int main() {

    cin >> N >> M;

    for(int i = 0; i< N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%1d", &house[i][j]);
        }
    }

    bfs(0,0);

// 출력 테스트용
//    for(int i = 0; i< N; i++) {
//        for(int j = 0; j < M; j++) {
//            cout << visit[i][j][block] << " ";
//        }
//        cout << "\n";
//    }


    if(visit[N-1][M-1][block] == 0)
        cout << -1;
    else
        cout << visit[N-1][M-1][block];





    return 0;
}
