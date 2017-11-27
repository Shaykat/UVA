#include<bits/stdc++.h>
using namespace std;

// input output
#define pf           printf
#define sf(n)        scanf("%d", &n)
#define sfl(n)        scanf("%lld", &n)
#define sfc(n)        scanf("%c", &n)
#define sff(a,b)     scanf("%d %d", &a, &b)
#define sfff(a,b,c)  scanf("%d %d %d", &a, &b, &c)
#define INP          freopen("in.txt", "r", stdin);  // file input
#define OUT          freopen("out.txt", "w", stdout);  // file output

// operations
#define pb           push_back
#define mem(n, val)  memset((n), val, sizeof(n))
#define mp           make_pair
#define ff first
#define se second

// constant
#define MOD          1000000007
#define inf   1<<30                                           //infinity value
#define eps   1e-9

// Loop
#define For(i, a, b) for(int i = a; i <= b; i++)
#define Ror(i, a, b) for(int i = a; i >= b; i--)
#define all(v)       v.begin(), v.end()

// functions
#define gcd(a,b)     ll _gcd(int a,int b){ if(b%a == 0) return a; _gcd(b%a,a); }
#define lcm(a,b)     ((a*b)/gcd(a,b))

// binary tree || segment tree
#define cnd          tr[idx]
#define lnd          tr[idx << 1]
#define rnd          tr[lnd + 1]
#define leftcl       lnd,st,mid
#define rightcl      rnd,mid+1,ed

// typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<int, string> pis;
typedef priority_queue<int> pq;

// @Shaykat@
/////////////////////////////////// template //////////////////////////////
#define sz 100050
ll t,n;
char c;
string p,q;
ll par[sz],res[sz];
map<string,int>m;

void makset(ll n){
    par[n] = n;
}

int find(int a){
    if(par[a] == a) return a;
    par[a] = find(par[a]);
    return par[a];
}

void unin(int a, int b){
    int u = find(a);
    int v = find(b);
    find(b);
    par[v] = u;
}

int main(){
    sf(t);
    int v;
    while(t--){
        v = 1;
        cin >> c;
        n = (int)c - 64;
        For(i,1,2*n+5){
            res[i] = 1;
            makset(i);
        }
        while(1){
            cin >> p;
            if(p == "\r") break;
            if(m.find(p[0]) == m.end()){
                m[p[0]] = v++;
            }
            if(m.find(p[1]) == m.end()) {
                m[p[1]] = v++;
            }
            unin(m[p[0]],m[p[1]]);
        }
        int k = 0,cnt = 0;
        For(i,1,v-1){
            if(res[par[i]] == 0) cnt++;
            res[par[i]] = 1;
        }
        cout << cnt << endl;
        m.clear();
    }
    return 0;
}


