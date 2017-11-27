#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;
#define s 2505
vector <int> G[s];
queue <int> Q;
int level[s];
int visited[s];

void BFS(int src)
{
    //cout << "bfs" << endl;
    int d,mx,day=0;
    Q.push(src);

    int u,v,fnd = 0,p;
    mx = 0;
    d = 0;
    visited[src] = 1;
    level[src] = 0;
    while(!Q.empty())
    {
        u = Q.front();
        if(level[u] > day){
            if(fnd > mx){
                //cout << level[v] << endl;
                d = level[u];
                mx = fnd;
            }
            day++;
            fnd = 0;
        }
        for(int i=0;i<G[u].size();i++)
        {
            v = G[u][i];
            if(!visited[v])
            {
                visited[v] = 1;
                fnd++;
                level[v] = level[u] + 1;
                Q.push(v);
            }
        }
        Q.pop();
    }

    cout << mx << " " << d << endl;
}

void init(){
    memset(visited,0,sizeof(visited));
    memset(level,0,sizeof(level));
}

int main(){
    int nf,n,t,b,a;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> nf;
        while(nf--){
            cin >> a;
            G[i].push_back(a);
        }
    }
    //test
    /*for(int i = 0; i < n; i++){
        for(int j = 0; j < G[i].size(); j++){
            cout << G[i][j] << " ";
        }
        cout << endl;
    }*/

    cin >> t;
    while(t--){
        cin >> b;
        BFS(b);
        init();
    }
}


