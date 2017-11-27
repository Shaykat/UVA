#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<cstdlib>
using namespace std;

#define s 110
int visited[s];
vector<int>G[s];
int node;

void vertex(int u){
    for(int i = 0; i < G[u].size();i++){
        int v = G[u][i];
        if(visited[v] == 0){
            visited[v] = 1;
            node++;
            vertex(v);
        }
    }
}

int main(){
    int n;
    int x,y,nStartVertex,a;

    while(1){
        cin >> n;
        if(n == 0){
            break;
        }
        else {
            while(1){
                cin >> x;
                if(x == 0){
                    break;
                }
                else {
                    while(1){
                        cin >> y;
                        if(y == 0){
                            break;
                        }
                        else{
                            G[x].push_back(y);
                        }
                    }
                }
            }
        }
        /*for(int i = 1; i <= n; i++){
            for(int j = 0; j < G[i].size(); j++){
                printf("%d: %d\n",i,G[i][j]);
            }
        }*/

        cin >> nStartVertex;
        while(nStartVertex--){
            cin >> a;
            node = 0;
            vertex(a);
            cout << n - node;
            for(int i = 1; i <= n; i++){
                if(!visited[i]){
                    cout <<" " << i;
                }
            }
            cout<<endl;
            memset(visited,0,sizeof(visited));

        }
        for(int i = 0; i <= n; i++){
            G[i].clear();
        }
    }
}
