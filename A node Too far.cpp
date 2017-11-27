#include<bits/stdc++.h>
using namespace std;

// input output
#define pf              printf
#define sf(n)           scanf("%d", &n)
#define sfl(n)          scanf("%lld", &n)
#define sfc(n)          scanf("%c", &n)
#define sff(a,b)        scanf("%d %d", &a, &b)
#define sfff(a,b,c)     scanf("%d %d %d", &a, &b, &c)
#define INP             freopen("in.txt", "r", stdin);  // file input
#define OUT             freopen("out.txt", "w", stdout);  // file output

// operations
#define pb              push_back
#define ppb             pop_back
#define mem(n, val)     memset((n), val, sizeof(n))
#define mp              make_pair
#define ff first
#define se second

// Loop
#define For(i, a, b)    for(int i = a; i <= b; i++)
#define Ror(i, a, b)    for(int i = a; i >= b; i--)
#define all(v)          v.begin(), v.end()

// functions
#define gcd(a,b)        ll _gcd(int a,int b){ if(b%a == 0) return a; _gcd(b%a,a); }
#define lcm(a,b)        ((a*b)/gcd(a,b))

// binary tree || segment tree
#define cnd             tr[idx]
#define lnd             tr[idx << 1]
#define rnd             tr[lnd + 1]
#define leftcl          lnd,st,mid
#define rightcl         rnd,mid+1,ed

// compare
// functions
#define cmpr            bool compare(const pair<int,int>&i,const pair<int,int>&j)   {return i.first < j.first;}
#define tostring(a)     string To_Upper(string a)   {for(int i = 0;i < a.size()-1;i++){  if(islower(a[i])) a[i] = toupper(a[i]); } return a; }

//operator overloading
class Compare{
    public:
    bool operator()(const int& l, const int& r){
       return l > r;
   }
};

// typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<int, string> pis;
typedef priority_queue<int> pq; // for max heap
typedef priority_queue<int,vector<int>, Compare > PQ; // for min heap

// constants
const int MOD = 1000000007;
const double EPS = 1e-11;
const double INF = 2e30;
const double PI = 2 * acos( 0.0 );

// manual division
int divide(string a,int base)   {int b = a.size(),c = 0,r = 0,i = 0;
    while(i < b)    {c = c*base + a[i++]-'0';
    if(c/b > 0) {r = r*base + c/b; c = c%b;}}
    if(c == 0) return r;
    return 0;
}

// binary operations
int Bset(int N,int pos){return N=N | (1<<pos);}
int Breset(int N,int pos){return N= N & ~(1<<pos);}
bool Bcheck(int N,int pos){return (bool)(N & (1<<pos));}

/////////////////////////////////// template //////////////////////////////

int level[1000010],visited[1000010],visit[1000010],lvlcnt = 0,tc = 0;
vector<int>graph[100];
queue<int>Q;

int nc,t = 0,mn = 1000010, mx = 0,comp;
void BFS(int src)
{
    int u,v;
    queue<int>Q;
    Q.push(src);
    lvlcnt++;
    visited[src] = 1;
    level[src] = 0;
    while(!Q.empty())
    {
        u = Q.front();
        for(int i=0;i<graph[u].size();i++)
        {
            v = graph[u][i];
            if(!visited[v])
            {
                visited[v] = 1;
                level[v] = level[u] + 1;
                if(level[v] <= comp){
                    lvlcnt++;
                    //cout << v << endl;
                }
                Q.push(v);
            }
        }
        Q.pop();
    }
}

void init(){
    while(!Q.empty()){
        Q.pop();
    }
    mem(visited,0);
    mem(level,0);
    lvlcnt = 0;
}
int main(){
    int x,y,c = 0,p,q;
    while(1){
        sf(nc);
        if(nc == 0) break;
        while(nc--){
            sff(x,y);
            graph[x].pb(y);
            graph[y].pb(x);
            if(!visit[x]) tc++;
            visit[x] = 1;
            if(!visit[y]) tc++;
            visit[y] = 1;

        }
        while(1){
            sff(x,comp);
            if(x == 0 && comp == 0){
                break;
            }
            if(visit[x]) BFS(x);
            pf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++c,(tc-lvlcnt),x,comp);
            //cout << tc << " " << lvlcnt << endl;
            init();
        }
        tc = 0;
        For(i,1,33){
            graph[i].clear();
        }
        mem(visit,0);
        init();
    }
}
