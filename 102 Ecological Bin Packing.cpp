#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    int bin[9],i,mov=0,max=0,max_i=0;
    int g1=0,b1=1,c1=2;

    for(i=0;i<9;i++)
    {
       cin >> bin[i]
       if(bin[i] > max)
       {
           max = bin[i];
           max_i = i;
       }
    }
    if(max_i == g1)
    {
        mov = bin[g1+3] + bin[g1+6];
    }
    else if(max_i == g1+3)
    {
        mov = bin[g1] + bin[g1+6];
    }
    else if(max_i == g1+6)
    {
        mov = bin[g1+3] + bin[g1+6];
    }


    /*else if(max_i == b1)
    {
        mov = bin[b1+3] + bin[b1+6];
    }
    else if(max_i == b1+3)
    {
        mov = bin[b1] + bin[b1+6];
    }
   else if(max_i == b1+6)
    {
        mov = bin[b1] + bin[b1+3];
    }
    else if(max_i == c1)
    {
        mov = bin[c1+3] + bin[c1+6];
    }
    else if(max_i == c1+3)
    {
        mov = bin[c1] + bin[c1+6];
    }
    else if(max_i == c1+6)
    {
        mov = bin[c1] + bin[c1+3];
    }*/
}
