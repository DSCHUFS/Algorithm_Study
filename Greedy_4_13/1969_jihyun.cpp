#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int n,m; //dna 수 n, 문자열 길이 m
    string dna[1001];
    string result=""; //빈문자열
    int hd=0,max_c;
    int num_t, num_a, num_c,num_g;
    
    cin >> n >> m;
    
    for(int i=1; i<n+1; i++){
        cin >> dna[i];
    }
    
    for(int i=0; i<m; i++){
        num_g=0;
        num_a=0;
        num_c=0;
        num_t=0;
        max_c=0; //최댓값
        for(int j=1; j<n+1; j++){
            if (dna[j][i]=='A') {
                num_a++;
            }else if (dna[j][i]=='C') {
                num_c++;
            }
            else if (dna[j][i]=='G') {
                num_g++;
            }
            else if (dna[j][i]=='T') {
                num_t++;
            }
        }
        max_c = max(max(max(num_a,num_c),num_g),num_t);
        if(max_c == num_a){
            result+="A";
            hd += num_t + num_c + num_g;
        }else if(max_c == num_c){
            result+="C";
            hd += num_t + num_a + num_g;
        }else if(max_c == num_g){
            result+="G";
            hd += num_t + num_c + num_a;
        }else{
            result+="T";
            hd += num_a + num_c + num_g;
        }
    }
    result += "\n";
    
    cout << result;
    cout << hd << endl;
    
    return 0;
}

/*
5 8
TATGATAC
TAAGCTAC
AAAGATCC
TGAGATAC
TAAGATGT
*/
