#include<bits/stdc++.h>
using namespace std;

#define s 1005
#define p pair<int,int>

int visited[s][s];
int cell[s][s];
int level[s][s];
//int parent[s][s];
int row,colom;
queue<pair<int,int> >Q;
int fx[] = {1,-1,0,0};
int fy[] = {0,0,1,-1};

void tdbfs(int g,int h){
    visited[g][h] = 1;
    Q.push(make_pair(g,h));
    int p1,p2,x,y;
   while(!Q.empty()){
        //cout << "hjhgjh" << endl;
        p mp = Q.front();
        Q.pop();
        p1 = mp.first;
        p2 = mp.second;
        int i;
        for(i = 0; i < 4; i++){
            x = p1+fy[i];
            y = p2+fx[i];
            if(x>=0 && x<row && y>=0 && y<colom && visited[x][y] == 0){
                visited[x][y] = 1;
                if(level[x][y] == 0){
                    level[x][y] = level[p1][p2]+1;
                    cout << level[x][y] << endl;
                    Q.push(make_pair(x,y));
                }
            }
        }
   }
   //cout << level[8][8] << endl;
}
void init(){
    memset(visited,0,sizeof(visited));
    memset(level,0,sizeof(level));
    //memset(parent,0,sizeof(parent));

}
int main(){
    int pi;
    int q;
    int r,x,y,w,z;
    init();
    while(scanf("%d%d",&row,&colom) != 0){
        if(row == 0 && colom == 0){
            break;
        }
        cin >> r;
        for(int i=0; i<r; i++){
            cin >> pi;
            for(int j = 0; j < pi; j++){
                cin >> q;
                cell [pi][q] = 1;
            }
        }
        cin >> x >> y;
        cin >> w >> z;
        tdbfs(x,y);
        //cout << level[w][z] << endl;
        //init();
    }
}
/*
4 3
1 2 3
4 5 6
7 8 9
10 11 12
*/

