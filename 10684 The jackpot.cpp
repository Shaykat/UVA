#include<bits/stdc++.h>
using namespace std;
#define s 10010
int a[s];
int n;
int main(){
    int j,k,cnt = 0,mx = 0,sum = 0;
    while(1){
        cin >> n;
        if(n == 0) break;
        mx = 0,sum = 0;
        for(int  i = 0; i < n; i++){
            cin >> a[i];
        }
        j = 0;
        while(j < n){
            if(sum + a[j] > 0){
                sum += a[j];
                if(sum > mx) mx = sum;
                j++;
            }
            else {
                sum = 0;
                j++;
            }
        }
        if(mx > 0){
            printf("The maximum winning streak is %d.\n",mx);
        }
        else {
            printf("Losing streak.\n");
        }
        //cout << mx << endl;
    }
    return 0;
}
