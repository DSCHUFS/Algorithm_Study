#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    return a > b;
}

int main(int argc, const char * argv[]) {
    int n; //로프 개수
    int rope[100000];
    int max_weight;
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> rope[i];
    }
    
    sort(rope, rope+n, compare); //내림차순으로 rope[0]~rope[n-1]까지 정렬
    
    max_weight = rope[0]; //가장 큰 값인 rope[0]을 최대값으로 지정
    
    for(int i=1; i<n; i++){
        if(rope[i]*(i+1) >= max_weight){ //현재 최대 중량보다 그 다음으로 큰 값을 가능한 로프 개수로 곱한 것이 큰 경우
            max_weight = rope[i] * (i+1); //최대 중량에 새로운 값 저장
        }
    }
    
    cout << max_weight;
    return 0;
}
