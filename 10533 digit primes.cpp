#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;
//#define a 1000000
const int a=1000010;
int prime[a];
int array[a];
int k=0;
int dprime[a];

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
    prime[k++] = 2;
    for(i=3;i<a;i+=2)
    {
        if(array[i] == 0)
        {
            prime[k++] = i;
        }
    }
}
void Digit_prime()
{
    int sum=0,v;
    for(int i=0;i<k;i++)
    {
        v = prime[i];
        while(prime[i])
        {
            sum += prime[i]%10;
            prime[i] = prime[i]/10;
        }

        if(sum == 2)
        {
            dprime[v]=1;
        }
        else if(sum%2 == 0)
        {
            dprime[v]=0;
        }
        else if(array[sum] == 1)
        {
            dprime[v]=0;
        }
        else
            dprime[v]=1;

        sum = 0;

    }
    for(int i=1;i<=a;i++)
    {
        dprime[i] += dprime[i-1];
    }
}

int main()
{
    sieve();
    Digit_prime();
    int n,t1,t2;

    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&t1,&t2);

        if(t1 > t2)
        {
            int temp =t1;
            t1 = t2;
            t2 = temp;
        }

        if(t1 == 0)
        {
            printf("%d\n",dprime[t2]);
        }
        else
        {
            printf("%d\n",dprime[t2] - dprime[t1-1]);
        }
    }
    return 0;

}
