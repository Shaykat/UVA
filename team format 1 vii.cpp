#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
  int a,b,t,s=0 ;
  cin >>a>>b;
  for (int i = 0; i < b; i ++)
  {
    cin >> t;
    if (t+s>a)
    {
       s=(t+s-a);
    }
    else
    {
        s=0;
    }
  }
  cout << s << endl;
  return (0);
}
