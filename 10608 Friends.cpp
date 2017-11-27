#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<stack>
using namespace std;

#define s 500010
vector<int>citizen[s];
int visit[s];
int maxi;
int n,m,cnt;

void init(){
    cnt = 1;
    maxi = 0;
    memset(visit,0,sizeof(visit));
    for(int i = 0; i < s; i++){
        citizen[i].clear();
    }
    //memset(component,0,sizeof(component));
}

void friends(int u){
    visit[u] = 1;
    for(int i = 0; i < citizen[u].size(); i++){
        int v = citizen[u][i];

        if(visit[v] == 0){
            cnt++;
            friends(v);
        }
    }

}

int main(){

    int t,x,y;

    init();
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i = 0; i < m; i++){
            scanf("%d%d",&x,&y);
            citizen[x].push_back(y);
            citizen[y].push_back(x);
        }

        for(int i = 1; i < n; i++){
            if(visit[i] == 0){
                friends(i);
                if(cnt > maxi)
                maxi = cnt;
                cnt = 1;
            }
        }
        printf("%d",maxi);

        init();
    }
}
