#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int a=20000010;
int tprime[a];
int array[a];
int k=1;


void sieve()
{
    int i,j;
    int sn = sqrt((double)a);
    array[0] = 1;
    array[1] = 1;
    array[2] = 0;
    for(i=3;i<=sn;i+=2)
    {
        if(array[i] == 0)
        {
            for(j=i*i;j<a;j+=2*i)
            {
                array[j] = 1;
            }
        }
    }
    for(i=3;i<=a;i+=2)
    {
        if(array[i] == 0 && array[i+2] == 0)
        {
            tprime[k++] = i;
        }
    }
}

int main()
{
    sieve();
    int x;

    while(scanf("%d",&x) != EOF)
    {
        printf("(%d, %d)\n",tprime[x],tprime[x]+2);
    }

    return 0;
}
