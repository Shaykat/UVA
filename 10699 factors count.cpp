#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define a  100000
int array[a];
void sieve()
{
    int i,j;
    int sn = sqrt((double)a);
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
}

int main()
{
    sieve();
    array[0] = 2;
    int j=0;
    for(int i=3;i<a;i+=2)

    {
        if(array[i] == 0)
        {
            array[++j] = i;
        }
    }

    int i=0,size=0,sqrtn=0,n;
    scanf("%d",&n);
    sqrtn = sqrt((double)n);

    while(n != 0)
    {
    printf("%d : ",n);

    for(i=0;i<=sqrtn;i++)
    {
        if(n%array[i] == 0)
        {
            size++;
            while(n%array[i] == 0)
            {
                n = n/array[i];
            }
            sqrtn = sqrt((double)n);
        }

    }

    if(n>1)
    {
        size++;
    }

    printf("%d\n",size);
    size = 0;

    scanf("%d",&n);
    sqrtn = sqrt((double)n);


    }

    return 0;


}


