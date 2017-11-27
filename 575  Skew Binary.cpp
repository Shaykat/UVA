#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string.h>
using namespace std;

int main()
{
    char n[100];
    long long int m;
    int a,p,i,len,b;
    while(gets(n))
    {
        m=0;
        p=2;
        a=0;
        len = strlen(n);
        for(i=len-1;i>=0;i--)
        {
            a = n[i]-'0';
            b = a*(p-1);
            m = m+b;
            p = p*2;
        }
        if(m == 0)
        break;

        printf("%lld\n",m);
    }
}
