#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
   int n,k,sum,p;

   while(scanf("%d %d",&n,&k) != EOF)
   {
       sum = n;
       while(n>=k)
       {

           p = n/k;
           n = p + n%k;
           sum = sum+p;
       }

       printf("%d\n",sum);

   }
   return 0;
}
