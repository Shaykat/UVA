#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
#include<cstring>
#include<iomanip>
using namespace std;
#define s 2510
vector<int>emp[s];
queue<int>Q;
int level[s],visited[s];
int t,f;

void min_country(int src)
{
    Q.push(src);
    int u,v;
    visited[src] = 1;
    level[src] = 0;

    while(!Q.empty()){
        u = Q.front();
        Q.pop();
        for(int i=0;i<emp[u].size();i++){
            v = emp[u][i];
            if(!visited[v]){
                visited[v] = 1;
                level[v] = level[u] + 1;
                Q.push(v);
            }
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

