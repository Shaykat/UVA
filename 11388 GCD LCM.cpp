#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int g,l,d,t;
    scanf("%d",&t);
    while(t--)
    {
    scanf("%d%d",&g,&l);
    d = g*l;
    int a = g,b = g,c=0;

    for(a=g;a<=b;a+=a)
    {
        c=0;
        for(b=a;b<=l;b+=b)
        {
            if(a*b == d)
            {
                printf("%d %d\n",a,b);
                c=1;
                break;
            }
        }
        if(c == 1)
        break;
    }
    if(c == 0)
    {
        printf("-1\n");
    }

    }
}
