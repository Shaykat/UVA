#include<bits/stdc++.h>
using namespace std;
#define s 25
#define mini 1000000000
vector<int>res;
int dp[s][1000000];
int a[s];
int n,t,bana;

int call(int i,int make){
    if(i >= t){
        return 0;
    }
    if(dp[i][make] != -1){
        return dp[i][make];
    }
    int ret1 = 0, ret2 = 0;
    if(make + a[i] <= n) ret1 = a[i] + call(i+1,make + a[i]);
    ret2 = call(i+1,make);

    return dp[i][make] = max(ret1,ret2);
}
bool dp2[s][10000];
bool call2(int i , int make){
    if(i >= t){
        if(bana == make) return dp2[i][make] = 1;
        else return dp2[i][make] = 0;
    }
    //if(dp[i][make] != -1) return dp[i][make];

    int ret1 = 0, ret2 = 0;

    if(make + a[i] <= n) ret1 = call2(i+1,make+a[i]);
    ret2 =  call2(i+1,make);

    dp2[i][make] = ret1 || ret2;
    return dp2[i][make];
}

void call3(int i,int make){
    if(i >= t) return;

    //if(dp2[i][make] == 1) return dp[i][make];

    int ret1 = 0, ret2 = 0;
    if(make + a[i] <= n) {
        if(dp2[i+1][make+a[i]] == 1){
            res.push_back(a[i]);
            call3(i+1,make+a[i]);
            return;
        }
    }
    if(dp2[i][make] == 1){
        call3(i+1,make);
        return;
    }
}

void init(){
    memset(dp,-1,sizeof(dp));
    memset(dp2,0,sizeof(dp2));
    res.clear();
}

int main(){
    while(scanf("%d",&n) != EOF){
        init();
        cin >> t;
        for(int i = 0; i < t; i++){
            cin >> a[i];
        }
        bana = call(0,0);
        call2(0,0);
        call3(0,0);
        for(int i = 0; i < res.size(); i++){
            cout << res[i] << " ";
        }
        cout << "Sum:" << bana << endl;
    }
}
