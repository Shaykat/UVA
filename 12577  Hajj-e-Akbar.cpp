#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
    char haj[20];
    int c=1;

    while(fgets(haj,20,stdin) != "*")
    {
        //scanf("%s%c",haj,&k);

        //if(haj == "*")
        //break;

        //else
        //{
            if(haj == "Hajj")
            {
                printf("Case %d: Hajj-e-Akbar\n",c++);
            }
            else if(haj == "Umrah")
            {
                printf("Case %d: Hajj-e-Asghar\n",c++);
            }
       // }
    }

    return 0;
}
