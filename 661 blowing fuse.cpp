#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define sz 100
int on_off[sz];
int amp[sz];
int n_operation[sz];

void init(){

    memset(on_off,0,sizeof(on_off));
    memset(amp,0,sizeof(amp));
    memset(n_operation,0,sizeof(n_operation));
}

int main(){

    init();

    int n,m,c,f,t=1;
    int max = 0,sum = 0;

    while(scanf("%d%d%d",&n,&m,&c)){

        if(n == 0)
        break;

        max = 0,f = 0,sum = 0;
        for(int i = 1; i <= n; i++){
            cin >> amp[i];
        }
        for(int i = 0; i < m; i++){
            cin >> n_operation[i];
        }

        for(int i = 0; i < m; i++){
            if(on_off[n_operation[i]] == 0 ){
                on_off[n_operation[i]] = 1;
                sum += amp[n_operation[i]];
                if(sum > max)
                max = sum;
                if(sum > c){
                    f = 1;
                    break;
                }
            }
            else {
                on_off[n_operation[i]] = 0;
                sum -= amp[n_operation[i]];
            }
        }

        cout << "Sequence " << t << endl;
        if(f == 1){

            cout << "Fuse was blown.\n";
            //cout << sum << endl;
        }
        else {
            cout << "Fuse was not blown.\n";
            cout << "Maximal power consumption was " <<  max << " amperes.\n";
        }

        t++;
        init();
        sum = 0,f = 0,max = 0;
    }
}
