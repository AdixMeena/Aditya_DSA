#include <bits/stdc++.h>
using namespace std;

void pattern(int n )
{
    int space = n*2-1;
    for (int i = 1; i <= n; i++)
    {
        //some numbers piramid 
        for (int j = 1; j <= i; j++)
        {
            cout<<j;
        }

        //some space 
        for (int s = 1; s < space; s++)
        {
            cout<<" ";
        }

        //again the piramid 
        for (int k = i;k >= 1; k--)
        {
            cout<<k;
        }

        cout<<endl;
        space -= 2;
        

    }
}

int main()
{
    int n = 5;

    pattern(n);
}