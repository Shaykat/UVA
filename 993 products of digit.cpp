#include<iostream>
using namespace std;
#define a 1000
int array[a];
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
        }
    }
}
void product_digit(int i,int n)
{

        if(n == 1 || n == 2)
        {
            cout << n << endl;
        }
        else if(array[n] == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            for(i=2;n%i != 0;i++)
            {

            }
            if(i < 10 && (n/i) < 10)
            {
                cout << i << n << endl;
            }
            else if(i<10 && (n/i)>9)
            {
                cout << i << " ";
                n = n/i;
                product_digit(2,n);
            }
            else if(i>9 && (n/i)<9)
            {
                cout << n;
                n = i;
                product_digit(2,n);
            }

        }

}


int main()
{
    sieve();
    int i=0,j=0,k,n;

    cin >> k;
    for(j=0;j<k;j++)
    {
        cin >> n;
        product_digit(i,n);
    }

    return 0;
}
