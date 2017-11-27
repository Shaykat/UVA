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

#define sz 1000010

// @Shaykat@
/////////////////////////////////// template //////////////////////////////
ll n,m;
ll a[sz],b[sz];

int main(){
    ll lb,ub;
    sf(n);
    int i = 0, j = 0;
    For(i,j,n-1){
        sf(a[i]);
    }
    sf(m);
    For(i,j,m-1){
        sf(b[i]);
        lb = lower_bound(a,a+n,b[i])-a;
        ub = upper_bound(a,a+n,b[i])-a;
        if(lb > 0){
            cout << a[lb-1] << " ";
        }
        else cout << "X ";

        if(ub < n){
            cout << a[ub] << endl;
        }
        else {
            cout << "X\n";
        }
    }
    return 0;
}
