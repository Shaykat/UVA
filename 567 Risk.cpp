#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
#include<cstring>
#include<iomanip>
using namespace std;
#define s 25
vector<int>board[s];
queue<int>Q;
int level[s],parent[s],visited[s];
int t,f;

void min_country(int src,int d)
{
    Q.push(src);
    int u,v;
    visited[src] = 1;
    level[src] = 0;
    f = 0;
    while(!Q.empty())
    {
        u = Q.front();
        for(int i=0;i<board[u].size();i++)
        {
            v = board[u][i];
            if(!visited[v])
            {
                visited[v] = 1;
                level[v] = level[u] + 1;
                parent[v] = u;
                if(v == d){
                    f = 1;
                    break;
                }
                Q.push(v);
            }
        }
        Q.pop();
        if(f == 1){
            break;
        }
    }
}

void init(){
    memset(visited,0,sizeof(visited));
    memset(parent,0,sizeof(parent));
    memset(level,0,sizeof(level));
    while(!Q.empty()){
        Q.pop();
    }
}

int main(){
    int m,n,l;
    int x,y;
    init();
    t = 1;
    while(scanf("%d",&n) != EOF){
        while(n--){
            scanf("%d",&m);
            board[1].push_back(m);
            board[m].push_back(1);
        }
        for(int i = 2; i < 20; i++){
            scanf("%d",&n);
            while(n--){
                scanf("%d",&m);
                board[i].push_back(m);
                board[m].push_back(i);
            }
        }
        scanf("%d",&m);
        printf("Test Set #%d\n",t++);
        while(m--){
            scanf("%d%d",&x,&y);
            min_country(x,y);
            cout<< setw(2) << x << " to " << setw(2) << y << ": ";
            cout<< level[y] << endl;
            init();
        }

        for(int k = 0; k <= 20; k++){
            board[k].clear();
        }
        cout << endl;

    }
}
