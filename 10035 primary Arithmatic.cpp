#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

int main()
{
    int a,b;
    while(1)
    {
        scanf("%d%d",&a,&b);
        if(a==0 && b==0)
        break;

        int c=0,k=0,j=0;

        while(a!=0 || b!=0)
        {
            j = a%10 + b%10 + k;
            if(j >9)
            {
                c++;
                k = 1;
                a=a/10;
                b=b/10;
            }
            else
            {
                k = 0;
                a=a/10;
                b=b/10;
            }

        }

        if(c==1)
        {
            printf("%d carry operation.\n",c);
        }
        else if(c>1)
        {
            printf("%d carry operations.\n",c);
        }
        else
        {
            printf("No carry operation.\n",c);
        }
    }

    return 0;

}
