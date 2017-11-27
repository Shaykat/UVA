#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

int main()
{
    long int i,j,p,k,n,m,a,b;

    while(scanf("%ld%ld",&a,&b) == 2)
    {
        if(a>0 && a<1000000 && b>0 && b<1000000)
        {

         m=0;
         i=a;
         j=b;

         if(a>b)
         {
             i=b;
             j=a;

         }

        for(k=i;k<=j;k++)
        {
            p=k;
            n=1;
            while(p != 1)
            {
                if(p%2 == 0)
                {
                    p=p/2;
                    n=n+1;
                }

                else
                {
                    p = 3*p+1;
                    n=n+1;
                }
            }
            if(n>m)
            {
                m=n;
            }
        }

        cout << a << ' ' << b << ' ' << m << endl;

        }

    }

    return 0;
}
