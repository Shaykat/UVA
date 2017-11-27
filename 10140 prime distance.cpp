#include<bits/stdc++.h>
using namespace std;
#define s 1000000010
int arr[100010];
int prime[10000];

void sieve(){
    int i,j,k = 1,sq;
    sq = sqrt(s);
    prime[0] = 2;
    for(i = 3; i < sq; i+= 2){
        if(arr[i/2] == 0){
            prime[k++] = i;
            cout << "sss" << endl;
            for(j = i*i; j < s; j += 2*i){
                arr[j/2] = 1;
            }
        }
    }
}

int main(){
    sieve();
    for(int i = 0; i < 100; i++){
        cout << prime[i] << "  " << endl;
    }
    return 0;
}
