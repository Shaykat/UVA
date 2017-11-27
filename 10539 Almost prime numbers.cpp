#include<iostream>
using namespace std;
#define a 1000
long int nop;
int array[a];
int prime[a];
void sieve()
{
    int i,j;
    for(i=0;i<a;i++)
    {
        array[i] = 0;
    }
    array[0] = 1;
    array[1] = 1;
    for(i=2;i<a;i++)
    {
        if(array[i] == 0)
        {
            for(j=i+i;j<a;j+=i)
            {
                array[j] = 1;
            }
            prime[nop++] = i;
        }
    }
}
int main()
{
    sieve();
    int n;
    int i,j,k,hl,ll,nmp=0,c=0;
    cin >> n;
    cin >> ll >> hl;

    for(k=0;k<n;k++)
    {
        for(i=ll;i<=hl;i++)
        {
            if(array[i] == 1)
            {
                for(j=0;prime[j]<i;j++)
                {
                    if(i%prime[j] == 0)
                    c++;

                    if(c>1)
                    break;
                }
                if(c == 1)
                nmp++;
                c=0;
            }
        }

        cout << nmp;

    }


}
