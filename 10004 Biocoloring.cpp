#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<cstring>
#include<cstdlib>
#include<queue>
using namespace std;

#define sz 210
vector<int>g[sz];
int level[sz];
int color[sz];
queue<int> Q;
int flag;

void graph_traverse(int u){

    color[u] = 1;
    level[u] = 0;
    //cout << "level: " << level[u] << endl;
    Q.push(u);
    int v;

    while(!Q.empty()){
        u = Q.front();
        Q.pop();
        for(int i = 0; i < g[u].size(); i++){

            v = g[u][i];
            if(color[v] == 0){
                color[v] = 1;
                level[v] = level[u] + 1;
                cout << "level_u: " << level[u] << "level_v: " << level[v] << endl;
                Q.push(v);
            }
            else if(color[v] == 1 && level[u] == level[v]) {

                flag = 1;
                break;
            }
            else {
                flag = 0;
            }
        }
    }
}

int main(){

    memset(color,0,sz);
    memset(level,0,sz);

    int n,e,x,y;
    int p;
    flag = 0;

   while(scanf("%d",&n) != -1){

        flag = 0;
        if(n == 0)
        break;

        scanf("%d",&e);

        for(int j = 0; j < e; j++){

            scanf("%d%d",&x,&y);
            if(j == 0)
            p = x;

            g[x].push_back(y);
            g[y].push_back(x);
        }
        graph_traverse(p);

        if(flag == 1){
            printf("NOT BICOLORABLE.\n");
        }
        else {
            printf("BICOLORABLE.\n");
        }

        memset(color,0,sizeof(color));
        memset(level,0,sizeof(level));
        for(int k=0;k<sz;k++){
            g[k].clear();
        }
        while(!Q.empty()){
            Q.pop();
        }
    }

    return 0;
}
