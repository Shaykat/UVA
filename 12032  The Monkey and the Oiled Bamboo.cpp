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
#define s 100010
int t,n;
int a[s],b[s];
int main(){
    sf(t);
    int res = 0,mx = 0,p,q;
    for(int i = 1; i <= t; i++){
        sf(n);
        a[0] = 0;
        mx = 0;
        for(int j = 1; j <= n; j++){
            sf(a[j]);
            p = a[j]-a[j-1];
            b[j-1] = p;
            if(p > mx){
                mx = p;
                q = j-1;
            }
            //cout << b[j-1] << endl;
        }
        //sort(b,b+(n));
        int k = mx-1;
        res = mx;
        //cout << res << endl;
        for(int j = q+1; j < n; j++){
            //cout << "gap: " << b[j] << endl;
            if(b[j] > k){
                 res++;
                 break;
            }
            if(b[j] == k) k--;
        }
        pf("Case %d: %d\n",i,res);
        mem(a,-1);
        mem(b,-1);
    }
    return 0;
}
/*
5
19
97 188 263 301 390 422 433 440 537 635 695 724 784 868 945 979 984 997 1061
*/
