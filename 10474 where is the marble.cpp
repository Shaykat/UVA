#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define s 10010

int marble[s];
int query[s];
int freq[s];
int n,q,maxi,r;

void init(){
    memset(marble,0,sizeof(marble));
    memset(query,0,sizeof(query));
    memset(freq,0,sizeof(freq));
    maxi = 0;
}

void cumulative_sum(){

    int sum = 0;
    r = 0;
    for(int i = 0; i <=maxi; i++){
        if(marble[i] != 0){
            sum = sum + marble[i] + r;
            marble[i] = sum;
            r = freq[i] - 1;
        }

    }
}

int main(){

    int m,p,t;
    t = 1;
    init();
    while(1){
        scanf("%d%d",&n,&q);
        if(n == 0 && q == 0){
            break;
        }
        else{
            for(int i = 0; i < n; i++){
                scanf("%d",&m);
                if(m > maxi)
                maxi = m;
                freq[m]++;
                marble[m] = 1;
            }
            cumulative_sum();
            for(int i = 0; i < q; i++){
                scanf("%d",&query[i]);
            }

            printf("CASE# %d:\n",t);
            for(int i = 0; i < q; i++){
                //cout << "kl;kh;\n";
                p = query[i];
                if(marble[p] != 0){
                    printf("%d found at %d\n",p,marble[p]);
                }
                else {
                    printf("%d not found\n",p);
                }
            }
        }

        t++;
        init();
    }

    return 0;
}
