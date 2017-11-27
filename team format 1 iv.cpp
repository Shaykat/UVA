#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    double x1[12],y1[12],x2[12],y2[12];
    double x,y;
    char r;

    for(int i = 1; i <= 10;i++){
        if(scanf("%c",&r) == '*')
        break;

        else {
            scanf("%c",&r) == '*';
            scanf("%lf",&x1);
            scanf("%lf",&y1);
            scanf("%lf",&x2);
            scanf("%lf",&y2);
        }
    }
    int k = 1;
    while(1){
        scanf("%lf%lf",&x,&y);
        if(x == 9999.9 && y == 9999.9){
            break;
        }

        else {
            cout << "cccccc" << endl;
            int f = 0;
            for(int i = 1; i <= 10; i++){
                if(x > x1[i] && x < x2[i] && y > y1[i] && y < y2[i]){
                    printf("point %d is contained in figure %d\n",k,i);
                    f = 1;
                }


            }
            if(f == 0){
                printf("point %d is contained in any figure\n",k);
            }
        }
        k++;
    }
    return 0;
}
