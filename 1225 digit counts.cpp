#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
using namespace std;

int main()
{
    string integer;
    int n,t;
    int i,j;

    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int one=0,two=0,three=0,four=0,five=0,six=0,seven=0,eight=0,nine=0,zero=0;
        int s;
        scanf("%d",&n);
        for(j=1;j<=n;j++)
        {
            s=j;
            while(s)
            {
                //cout << j << endl;

                if(s%10 == 1)
                {
                    one ++;

                }
                else if(s%10 == 2)
                {
                    two ++ ;

                }
                else if(s%10 == 3)
                {
                    three ++ ;

                }
                else if(s%10 == 4)
                {
                    four ++ ;

                }
                else if(s%10 == 5)
                {
                    five ++ ;

                }
                else if(s%10 == 6)
                {
                    six ++ ;

                }
                else if(s%10 == 7)
                {
                    seven ++ ;

                }
                else if(s%10 == 8)
                {
                    eight ++ ;

                }
                else if(s%10 == 9)
                {
                    nine ++ ;

                }
                else if(s%10 == 0)
                {
                    zero ++ ;

                }
                 s= s/10;

            }
        }
        printf("%d %d %d %d %d %d %d %d %d %d\n",zero,one,two,three,four,five,six,seven,eight,nine);
    }

}
