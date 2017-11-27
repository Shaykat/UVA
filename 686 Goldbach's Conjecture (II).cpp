#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
const int a=32800;
int array[a];
int main()
{
    int i,j,sn=0;
    array[0] =1;
    sn = sqrt((double)a);
    for(i=3;i<=sn;i+=2)
    {
        if(array[i] == 0)
        {
            for(j= i*i;j<a;j+=2*i)
            {
                array[j] = 1;
            }
        }
    }

    int n,k;
    while(scanf("%d",&n))
    {
        if (n == 0)	{
			break;
		}
        k=0;
        if(n == 4)
        {
            printf("1\n");
        }
        else
        {
            for(j=3;j<n/2+1;j+=2)
            {
                if(array[j] == 0 && array[n-j] == 0)
                {
                k++;
                }
            }

            printf("%d\n",k);
        }
    }

    return 0;
}
