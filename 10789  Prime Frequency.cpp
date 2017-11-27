#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;

int count[130];
const int a=2010;
int array[a];
void sieve()
{
    int i,j;
    int sn = sqrt((double)a);
    array[0] = 1;
    array[1] = 1;
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

    char string[2010];
    int temp,t,a,b,len;

    scanf("%d",&t);
    for(a=1;a<=t;a++)
    {
        int f=0;
        for(int c=0;c<123;c++)//count array initialization
        {
            count[c] = 0;
        }
        scanf("%s",string); // input string
        len = strlen(string);

        for(b=0;b<=len;b++)
        {
            temp = (int)string[b]; // check string and count the frequency
            count[temp]++;
        }
        printf("Case %d: ",a);
        char k;
        k='0'; // k is a char variable to print the letter which frequency is prime
        for(b=48;b<=123;b++) // check where the frequency is a prime from 48 to 122
        {
            k = k;
            if(array[count[b]] == 0 && count[b]%2 !=0 )
            {
                printf("%c",k);
                f=1; // use a flag to identify when there is no prime frequency
            }
            else if(count[b] == 2)
            {
                printf("%c",k);
                f = 1; // use a flag to identify when there is no prime frequency
            }

            k = (char)(k+1); // incriment k by 1 in every loop
        }
        if(f == 0)
        {
            printf("empty"); // if flag is 0 then there is no prime frequency
        }
        printf("\n");
    }

    return 0;


}

