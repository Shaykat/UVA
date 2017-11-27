#include<bits/stdc++.h>
using namespace std;
#define s 100010
map<string,int>m;
vector<int>G[s];
stack<int>stk;
string st[s];
int v = 0;
int parent[s],visited[s];
void BFS(int src)
{
    queue<int>Q;
    Q.push(src);
    int level[100],parent[100],visited[100]={0};
    int u,v;
    visited[src] = 1;
    level[src] = 0;
    while(!Q.empty())
    {
        u = Q.front();
        for(int i=0;i<G[u].size();i++)
        {
            v = G[u][i];
            if(!visited[v])
            {
                visited[v] = 1;
                parent[v] = u;
                Q.push(v);
            }
        }
        Q.pop();
    }

}

void back_track(int a,int b){
    cout << "recurssion" << endl;
    while(parent[b] != a){
        //back_track(a,parent[b]);
        //cout << "recurssion" << endl;
        stk.push(b);
        b = parent[b];
    }
    stk.push(b);
    stk.push(parent[b]);
    int top;
    while(!stk.empty()){
        top = stk.top();
        stk.pop();
        cout << st[top] << " " << st[stk.top()] << endl;
    }


}

void init(){
    memset(visited,0,sizeof(visited));
    memset(parent,0,sizeof(parent));
    //memset(level,0,sizeof(level));
    v = 0;
}

int main(){
    string a,b;
    int n;

    while(cin >> n){
        init();
        while(n--){
            cin >> a >> b;
            if(m.find(a) == m.end()){
            m[a] = v;
            st[v++] = a;
            }
            if(m.find(b) == m.end()){
                m[b] = v;
                st[v++] = b;
            }
            G[m[a]].push_back(m[b]);
            G[m[b]].push_back(m[a]);
        }
        cin >> a >> b ;
        BFS(m[a]);
        back_track(m[a],m[b]);
        init();

    }
}
