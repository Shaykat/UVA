#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define a 100000
int array[a];

void sieve()
{
    int i,j,sn=0;
    array[0] =1;
    array[1] = 1;
    sn = sqrt((double)a);
    for(i=3;i<a;i+=2)
    {
        if(array[i] == 0)
        {
            for(j= i*i;j<a;j+=2*i)
            {
                array[j] = 1;
            }
        }
    }
}

int main()
{
    sieve();
    array[0] = 2;

    int j=2,sqn=0,n;
    scanf("%d",&n);
    sqn = sqrt((double)n);
    for(int i=3;i<a;i+=2)
    {
        if(array[i] == 0)
        {
            array[++j] = i;
        }
    }
    while(n != 0)
    {
     if (n<0)
     {
         printf("%d = -1 x ",n);
         n = n*-1;
     }
     else
     {
         printf("%d = ",n);
     }

     if(n%k == 0)
     {
         while(n%k == 0)
         {
             n=n/2;
         }
         if(n == 1)
         {
             printf("%d\n",k);
         }
         else
         {
             printf("%d x ",k);
         }
         sqn = sqrt((double)n);

     }

     for(k=3;k<=sqn;k+=2)
     {
         if(n%k == 0)
         {
             while(n%k == 0)
             {
                 n = n/k;
             }
             if(n == 1)
             {
                 printf("%d\n",k);
             }
             else
             {
                 printf("%d x ",k);
             }

             sqn = sqrt((double)n);
         }
     }

     if( n > 1)
     {
         printf("%d\n",n);
     }
     scanf("%d",&n);
     sqn = sqrt((double)n);
    }

    return 0;

}


