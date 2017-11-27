#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
#define s 5010
int a[s];
priority_queue<int>pq;
int r,n;
void init(){
    r = 0;
    memset(a,0,sizeof(a));
}

int main(){

    int p,q;

    while(scanf("%d",&n) != 0){
        if(n == 0)
        break;

        init();
        for(int i = 0; i < n; i++){
            scanf("%d",&a[i]);
            pq.push(-a[i]);
        }

        while(!pq.empty()){
            p = pq.top();
            pq.pop();
            q = pq.top();
            pq.pop();

            r += p + q;
            if(!pq.empty()){
                pq.push(p+q);
            }
        }

        printf("%d\n",-r);


    }
    return 0;
}
