#include<bits/stdc++.h>
using namespace std;
#define ll long long
int coin[12] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
int bound=-1,amount;
double n;
ll dp[12][30010];
void Bound(){
    for(int i = 0; i < 11; i++){
        if(amount < coin[i]) {
            bound = i;
            break;
        }
    }
    if(bound == -1) bound = 11;
}

ll call(int i,int make){
    if(i == bound){
        if(make == 0) return 1;
        else return 0;
    }
    if(dp[i][make] != -1) return dp[i][make];
    ll ret1 = 0,ret2 = 0;
    if(make-coin[i] >= 0) ret1 = call(i,make - coin[i]);
    ret2 = call(i+1,make);

    return dp[i][make] = ret1 + ret2;
}

int main(){
    memset(dp,-1,sizeof(dp));
    while(1){
        scanf("%lf",&n);
        if(n == 0.00) break;
        amount = n*100;
        Bound();
        //cout << n << "\t" << call(0,amount) << endl;
        printf("%lf %d",n,call(0,amount));
    }
    //cin >> n;
}
