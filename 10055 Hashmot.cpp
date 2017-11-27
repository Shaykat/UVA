#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

int main()
{
    long long int hs,os;
    long int ds=0;

    while(scanf("%lld%lld",&hs,&os) != EOF)
    {
       if(hs < os)
       {
           ds = os - hs;
       }
       else
       {
           ds = hs - os;
       }

       cout << ds << endl;
    }

    return 0;
}
