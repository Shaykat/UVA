#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
    long long n,s=0,p,r,t,c=1;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld",&n);
        p=n;
        while(1)
        {
            s=0;
            while(n)
            {
                r = n%10;
                s =s + (r*r);
                n = n/10;
            }
            n = s;

            if(n <= 9)
            {
               break;
            }

        }
        if(n==1 || n==7)
        {
            printf("Case #%lld: %lld is a Happy number.\n",c++,p);
        }
        else
        {
            printf("Case #%lld: %lld is an Unhappy number.\n",c++,p);
        }

    }
    return 0;
}
