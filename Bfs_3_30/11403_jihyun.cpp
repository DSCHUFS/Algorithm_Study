#include <iostream>
#include <queue>

using namespace std;

int i,j,n,k;
queue<pair<int, int>> Q;
int graph[100][100];
int result[100][100]={0};

void bfs(int a, int b){
    result[a][b] = 1;
    Q.push({a,b});
    
    while(!Q.empty()) {
        for(int i = 0; i < n; i++)
            if(graph[Q.front().second][i] && !result[a][i]) {
                result[a][i] = 1;
                Q.push({Q.front().second, i});
            }
        Q.pop();
    }
}

int main(int argc, const char * argv[]) {
    
    cin >> n;
    
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            cin >> graph[i][j];
        }
    }
    
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(graph[i][j])
                bfs(i,j);
        }
    }
    
    
    for(i=0;i<n;i++){
        for (j=0; j<n; j++) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
