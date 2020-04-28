#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    int rank[500001];
    long long int angry=0; //최대값....
    
    cin >> n;
    for(int i=1; i<n+1; i++){
        cin >> rank[i];
    }
    
    sort(rank+1, rank+n+1);
    
    for(int i=1; i<n+1; i++){
        angry += abs(i - rank[i]);
    }
    cout << angry << endl;
    return 0;
}
