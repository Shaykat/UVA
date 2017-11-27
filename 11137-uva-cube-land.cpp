#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define s 10010
#define mod 100000000000

ll dp[25][s];
ll a[25],amount,bound;
ll check_bound(){
    int k;
    for(int i = 1; i <= 21; i++){
        if(a[i] > amount){
            k = i;
            break;
        }
    }
    return k;
}

ll call(ll i, ll am){
    if(i >= bound){
        if(am == 0){
            return 1;
        }
        else {
            return 0;
        }
    }
    if(dp[i][am] != -1){
        return dp[i][am];
    }
    ll ret1 = 0,ret2 = 0;

    if(am - a[i] >= 0){
        ret1  = call(i,am-a[i]);
    }
    ret2 = call(i+1,am);
    dp[i][am] = (ret1+ret2);
    dp[i][am] = dp[i][am]%mod;
    cout << dp[i][am] << endl;
    return dp[i][am];
}

void init(){
    for(int i = 0; i <= 22; i++){
        for(int j = 0; j <= s; j++){
            dp[i][j] = -1;
        }
    }
}

int main(){
    init();
    for(int i = 1; i <= 21; i++){
        a[i] = i*i*i;
    }
    while(1){
        if(scanf("%lld",&amount) == EOF){
            break;
        }
        bound = check_bound();
        cout << call(1,amount)%mod << endl;
    }
}
