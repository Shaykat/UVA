    #include<iostream>
    #include<cstdio>
    #include<cstdlib>
    #include<cmath>
    using namespace std;
    const int a = 1000010;
    int array[a];
    int ar[100000];
    int main()
    {
    	//cout << "hi\n";
    	int i, j, sn = 0;
    	array[0] = 1;
    	array[1] = 1;
    	sn = sqrt((double)a);
    	for (i = 3; i <= sn; i += 2)
    	{
    		if (array[i] == 0)
    		{
    			for (j = i * i; j < a; j += 2 * i)
    			{
    				array[j] = 1;
    			}
    		}
    	}

    	int n, f, k, max, temp;
    	while (scanf("%d", &n))
    	{
    		if (n == 0)	{
    			break;
    		}
    		f = 0;
    		k = -1;
    		max = 0;
    		for (j = 3; j<(n/2)+1; j += 2)
    		{
    			if (array[j] == 0 && array[n - j] == 0)
    			{
    				ar[++k] = j;
    				f = 1;
    			}
    		}
    		if (f == 1)
    		{
    			for (int l = 0; l <= k; l++)
    			{
    				if ((n - 2 * ar[l])>max)
    				{
    					max = (n - 2 * ar[l]);
    					temp = ar[l];
    				}
    				else if(n == 6)
    				{
    				    temp = 3;
    				}
    			}
    			printf("%d = %d + %d\n", n, temp, n - temp);
    		}
    		else
    		{
    			printf("Goldbach's conjecture is wrong.\n");
    		}
    	}

    	return 0;
    }
