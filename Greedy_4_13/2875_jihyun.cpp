#include <iostream>

using namespace std;

int findMax (int N, int M, int K){ //참가할 수 있는 최대 팀 개수 구하기
    while(1){
        if (2*M <= N) { //가능한 2:1 조합의 팀 개수 구하기
            return M; //남자가 팀 당 1명이 참가하니까 남자 수가 팀 개수라고 할 수 있음
        }
        else{
            M--;
        }
    }
}


int main(int argc, const char * argv[]) {
    
    int n,m,k;
    int num_b, result; //num_b는 팀에 참여하는 남자 인원수 = 팀의 수
    
    cin >> n >> m >> k;
    
    num_b = findMax(n, m, k);
    
    while (1) {
        //원래 인원 수에서 참가하는 사람 인원 수 뺀 것이 인턴쉽에 참여하는 사람보다 크면 정답
        if(k <= n + m - (num_b + num_b*2)){
            result = num_b;
            break;
        }
        //아니면 팀의 개수를 줄이기
        else{
            num_b--;
        }
    }
    
    cout << result;
    
    return 0;
}
