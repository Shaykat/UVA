#include<bits/stdc++.h>
using namespace std;
#define s 110
int t,n,av,res,tmp;
int a[s],dp[110][100010];

int coin(int i,int make){
    if(i >= n){
        return 0;
    }
    if(dp[i][make] != -1) return dp[i][make];
    int ret1 = 0,ret2 = 0;
    if(make + a[i] <= av){
        ret1 = a[i] + coin(i+1,make+a[i]);
    }
    ret2 = coin(i+1,make);
//cout << "ret1: " << ret1 << " ret2: " << ret2 << endl;

    return dp[i][make] = max(ret1,ret2);
}

int main(){
    int sum =  0;
    cin >> t;
    for(int i = 1; i <= t; i++){
        memset(dp,-1,sizeof(dp));
        sum = 0;
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> a[j];
            sum += a[j];
        }
        av = sum/2;
        //cout << av << endl;
        tmp = coin(0,0);
        res = sum - tmp;
        cout << abs(res - tmp) << endl;
    }
}
