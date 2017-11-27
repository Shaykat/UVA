#include<bits/stdc++.h>
using namespace std;
#define p pair<int,int>
#define s 10
int visited[s][s];
int cell[s][s];
int level[s][s];
int sx,sy,dx,dy,row = 8,colom = 8;
queue<pair<int,int> >Q;
int fx[] = {2,2,-2,-2,1,-1,1,-1};
int fy[] = {1,-1,1,-1,2,2,-2,-2};

void tdbfs(int g,int h){
    visited[g][h] = 1;
    Q.push(make_pair(g,h));
    int p1,p2,x,y;
   while(!Q.empty()){
        p mp = Q.front();
        Q.pop();
        p1 = mp.first;
        p2 = mp.second;
        int i;
        for(i = 0; i < 8; i++){
            x = p1+fx[i];
            y = p2+fy[i];
            if(x>=0 && x<colom && y>=0 && y<row && cell[x][y] == 0 && visited[x][y] == 0){
                visited[x][y] = 1;
                level[x][y] = level[p1][p2]+1;
                //cout << "x : " << x << "y : " << y << " " << level[x][y] << endl;
                Q.push(make_pair(x,y));
            }
        }
   }
}

void init(){
    memset(visited,0,sizeof(visited));
    memset(level,0,sizeof(level));
    memset(cell,0,sizeof(cell));
}

int main(){
    string a,b;
    while(cin >> a >> b){
            init();
        // convert string input to int
        sx = a[0] - 96;
        sy = a[1] - '0';
        dx = b[0] - 96;
        dy = b[1] - '0';
        //cout << sx << sy << dx << dy << endl;

        tdbfs(sy-1,sx-1);
        cout << "To get from " << a << " to " << b << " takes " << level[dy-1][dx-1] << " knight moves." << endl;
        //printf("To get from %s to %s takes %d knight moves.",a,b,level[dy][dx]);
        init();
    }
}
