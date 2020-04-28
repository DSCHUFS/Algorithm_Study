#include <iostream>
#include <queue>


using namespace std;

#define SIZE 105 // 105


queue<pair<int, int>> Q;

int n;
int minVal = 201;
int maxVal;
int ans;
int map[SIZE][SIZE];
int visit[SIZE][SIZE] = {0};
int head, tail, mid;
int diff;
int x, y, nx, ny;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int range_st, range_ed;


int bfs(int mid) {
    for (int l = minVal; l <= maxVal - mid; l++) {
        //갈 수 없는 곳에 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] < l) visit[i][j] = 1;
                else if (map[i][j] >= l && map[i][j] <= l + mid) visit[i][j] = 0;
                else visit[i][j] = 1;
            }
        }
        if (visit[0][0]) continue;
        visit[0][0] = 1;

        Q.push({ 0, 0 });
        while (!Q.empty()) {
            x = Q.front().first;
            y = Q.front().second;
            Q.pop();

            if (x == (n - 1) && y == (n - 1)){
                return 1;
            }

            for (int i = 0; i < 4; i++) {
                nx = x + dx[i];
                ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                    if (visit[nx][ny] == 0) {
                        visit[nx][ny] = 1;
                        Q.push({ nx,ny });
                    }
                }
            }
        }
    }
    return 0;
}



int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            if (map[i][j] > maxVal) maxVal = map[i][j];
            if (map[i][j] < minVal) minVal = map[i][j];
        }
    }
    
    int start = 0;
    int end = maxVal - minVal; //차이가 가장 클 때

    while (start <= end) {
        mid = (start + end) / 2;
        if (bfs(mid)) end = mid - 1;
        else start = mid + 1;
    }

    cout << end + 1 << endl;

    return 0;

}

