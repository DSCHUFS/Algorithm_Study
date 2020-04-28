#include <iostream>
#include <vector>

using namespace std;

int N;
int odd[5] = {1, 3, 5, 7, 9};
int tmp;

//n이 소수인지 확인
bool is_prime(int n){
    for(int i=2; i*i <= n; i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}


void find_primes(int k,vector<int> v){
    if(k!=N){
        vector<int> new_v;
        for(int i=0; i<v.size(); i++){
            for(int h=0; h<5; h++){
                tmp = v[i]*10;
                tmp += odd[h];
                if(is_prime(tmp) == true){
                    new_v.push_back(tmp);
                }
            }
        }
        find_primes(k+1, new_v);
    }
    else{
        for(int i=0; i<v.size(); i++){
             cout << v[i] << endl;
        }
    }
    
}

int main(int argc, const char * argv[]) {

    cin >> N;
    vector<int> s;
    s.push_back(2);
    s.push_back(3);
    s.push_back(5);
    s.push_back(7);
    
    find_primes(1, s);
    
    return 0;
}
