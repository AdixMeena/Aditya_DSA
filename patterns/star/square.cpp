#include <bits/stdc++.h>

using namespace std;


void square(int n)
{
    for(int i = 0; i < n; i++)
    {
            
        for(int j = 0; j < n; j++)
        {
            cout << "*";
        }
        cout<<endl;
    }
}
int main(void)
{
    int n = 5;
    
    square(n);
}



