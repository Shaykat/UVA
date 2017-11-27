#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
    int t,c;
    int rev[1000],i,temp,k;
    long long rev_sum,a,p,b;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&a);
        p = a;
        i=0;
        while(1)
        {
            if(a == 196)
            {
                break;
            }
            k=1;
            b=0;
            c=0;
            while(a) // reverse the initial number
            {
                temp = a%10;
                rev[c++] = temp;
                a = a/10;
            }
            for(int n=c-1;n>=0;n--)
            {
                b = b+rev[n]*k;
                k = k*10;
            }
            rev_sum = p+b; // sum the initial & reverse value
            if(rev_sum > 4294967295)
            {
                break;
            }
            k=1;
            b=0;
            c=0;
            p=rev_sum;
            while(rev_sum) // reverse the initial number
            {
                temp = rev_sum%10;
                rev[c++] = temp;
                rev_sum = rev_sum/10;
            }
            for(int n=c-1;n>=0;n--)
            {
                b = b+rev[n]*k;
                k = k*10;
            }
            i++; // iteration
            if(p == b) // check where the rev_sum is pelinfrom
            {
                printf("%d %lld\n",i,p);
                break;
            }
            a = p;

        }
    }


    return 0;
}
