#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;

#define s 1010

int a[s];
vector< int >sum;
int n,m,t,suml,diff,min_diff;

void init(){
    suml = 0;
    sum.clear();
    diff = 0;
    min_diff = 1000000000;
}
int main(){
    t =1;
    init();
    int q,cs;

    while(scanf("%d",&n) && n){
        if(n == 0) break;

        for(int i = 0; i < n; i++){
            scanf("%d",&a[i]);
        }

        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                suml = a[i] + a[j];
                sum.push_back(suml);
            }
        }
        /*for(int i = 0; i < sum.size(); i++){
            cout << sum[i] << "\n";
        }*/

        scanf("%d",&m);
        printf("Case %d:\n",t++);
        for(int i = 0; i < m; i++){
            scanf("%d",&q);
            for(int j = 0; j <sum.size(); j++){
                diff = q - sum[j];
                if(diff < 0) diff = diff * (-1);
                //cout << sum[j] << ": " << diff << endl;
                if(diff < min_diff) {
                    min_diff = diff;
                    cs = sum[j];
                }
            }
            min_diff = 100000000;
            printf("Closest sum to %d is %d.\n",q,cs);
        }
        init();
    }
    return 0;
}
