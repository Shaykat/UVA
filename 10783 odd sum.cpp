#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

int main()
{
    int a,b,t,c=1;

    scanf("%d",&t);

    while(t--)
    {

        int sum=0;
        scanf("%d%d",&a,&b);

        for(int i=a;i<=b;i++)
        {
            if(i%2 != 0)
            {
                sum = sum + i;
            }
        }

        printf("case %d: %d\n",c++,sum);

    }
    return 0;
}
