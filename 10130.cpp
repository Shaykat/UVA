#include<bits/stdc++.h>
using namespace std;

#define s 1010
#define s1 35

int a[s],b[s];
int c[s][s1];
int t,n,g,cnt,p;

int knapsack(int i,int w){
    //int profit1 = 0,profit2 = 0;
    if(i == n+1){
        return 0;
    }
    if(c[i][w] != -1){
        return c[i][w];
    }
    int profit1 = 0,profit2 = 0;
    if(w+b[i] <= p){
        profit1 = a[i] + knapsack(i+1,w+b[i]);
    }

    profit2 = knapsack(i+1,w);
    c[i][w] = max(profit1,profit2);
    return c[i][w];
}

int main(){
    cin >> t;
    while(t--){
        memset(c,-1,sizeof(c));
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            cin >> b[i];
        }
        cin >> g;
        cnt = 0;
        for(int i = 1; i <= g; i++){
            cin >> p;
            cnt += knapsack(1,0);
            memset(c,-1,sizeof(c));
        }
        cout << cnt << endl;
    }
    return 0;
}
