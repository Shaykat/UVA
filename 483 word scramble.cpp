#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;

int main()
{
    char str[10000];
    int i,c,j;

    while(cin.getline(str,9999))
    {
        int len = strlen(str);
        for(i=0;i<=len;i++)
        {
            c = i;
            while(str[i] != ' ' && str[i] != '\0')
            {
                i++;
            }
            if(str[i] == ' ' || str[i] == '\0')
            {
                for(j=i-1;j>=c;j--)
                {
                    printf("%c",str[j]);
                }
                if(str[i] != '\0')
                {
                   printf(" ");
                }
            }
        }
        printf("\n");
    }
    return 0;

}
