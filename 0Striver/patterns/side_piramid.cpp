#include <bits/stdc++.h>
using namespace std;

void pattern (int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i+1; j++)
        {
            cout<<"#";
        }
        cout<<endl;
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = n; j > i+1; j--)
        {
            cout<<"#";
        }
        cout<<endl;
    }

}

 
int main(void)
{
    int n = 5;
    pattern(n);
}