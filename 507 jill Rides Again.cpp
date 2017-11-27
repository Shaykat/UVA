#include<bits/stdc++.h>
using namespace std;
#define sz 20010

int a[sz];
int r,n;
int main(){
    int sum,mx,st,ed,s,e;
    cin >> r;
    for(int i = 1; i <= r; i++){
        cin >> n;
        for(int i = 1; i < n; i++){
            cin >> a[i];
        }
        sum = 0,mx = 0,s = 1, e = 1,st = 1, ed = 2;
        int  j = 1;
        while(j < n){
            if(sum + a[j] < 0){
                if(sum > mx){
                    mx = sum;
                    st = s;
                    ed = e+1;
                }
                sum = 0;
                s = ++j;
                e = s;
                //cout << "start: " << s << endl;
            }
            else {
                sum += a[j];
                e = j;
                if(sum > mx || (sum >= mx && (ed-st) < (e-s))){
                    mx = sum;
                    st = s;
                    ed = e+1;
                }
                j++;
            }
        }
        if(mx > 0){
            printf("The nicest part of route %d is between stops %d and %d\n",i,st,ed);
        }
        else{
            printf("Route %d has no nice parts\n",i);
        }
        //cout << st << " " << ed << endl;
    }
    return 0;
}
