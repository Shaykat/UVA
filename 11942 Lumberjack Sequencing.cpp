#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n,i,f=0;
    int t[10];

    scanf("%d",&n);
    printf("Lumberjacks:\n");
    while(n--)
    {
        for(i=0;i<10;i++)
        {
            scanf("%d",&t[i]);
        }
        if(t[0] > t[1])
        {
            f=1;
            for(i=1;i<9;i++)
            {
                if(t[i] > t[i+1])
                f=1;
                else
                {
                    f=0;
                    break;
                }
            }
            if(f == 1)
            {
                printf("Ordered\n");
            }
            else
            {
                printf("Unordered\n");
            }
        }
        else
        {
            f=0;
            for(i=1;i<9;i++)
            {
                if(t[i] < t[i+1])
                f=0;
                else
                {
                    f=1;
                    break;
                }
            }
            if(f == 0)
            {
                printf("Ordered\n");
            }
            else
            {
                printf("Unordered\n");
            }
        }
    }
    return 0;
}
