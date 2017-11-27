#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
const int L = 22;
char str[L];

const int a = 1100;
int array[a];
void sieve()
{
    int i,j;
    int sn = sqrt((double)a);
    array[0] = 1;
    array[1] = 0;// as per problem
    array[2] = 0;
    for(i=3;i<=sn;i+=2)
    {
        if(array[i] == 0)
        {
            for(j=i*i;j<a;j+=2*i)
            {
                array[j] = 1;
            }
        }
    }
}

int main()
{
    sieve();
    char c;
    int sum,value;

    while(scanf("%s",str) != EOF)
    {
        int len = strlen(str);
        sum =0;
        for(int i=0;i<len;i++)
        {
            if(str[i] > 96)
            {
                value = str[i] - 96;
                sum += value;

            }
            else if(str[i] > 64)
            {
                value = str[i] - 38;
                sum += value;
            }
        }
        if(sum%2 == 0 && sum != 2)
        {
            printf("It is not a prime word.\n");
        }
        else if(array[sum] == 0 || sum == 2)
        {
            printf("It is a prime word.\n");
        }
        else
        {
            printf("It is not a prime word.\n");
        }

    }

    return 0;

}
