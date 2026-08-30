#include<bits/stdc++.h>
using namespace std;

void pattern(int n)
{
    
    for (int i = 0; i < n; i++)
    {
        
        for(int j = 1; j <= n-i-1; j++ )
        {
            cout<<" ";
        }
        char ch = 'A';
        int breakpoint = (2*i+1)/2;
        for (int k = 1; k <= (2*i)+1; k++)
        {
            cout<<ch;
            if(k <= breakpoint)
            {ch++;}
            else
            {
                ch--;
            }            
        }  
        cout<<endl;
    }
}


void pattern2(int n)


{
    for (int i = 0;i < n; i++)
    {
        for (char ch = ('A'+n-1) - i; ch <= ('A'+n); ch++)
        {
            cout<<ch<<" ";
        }
        
        cout<<endl;
    }
}



void pattern3(int n )
{
    int space = 0;
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            cout<<"#";           
        }

        for (int k = 0; k < space; k++)
        {
           cout<<" ";
        }

        for (int j = 0; j < n-i; j++)
        {
            cout<<"#";           
        }

        space += 2;
        cout<<endl;
    }
}

void pattern31(int n )
{
    int space = 8;
    for(int i = 0; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout<<"#";           
        }

        for (int k = 0; k < space; k++)
        {
           cout<<" ";
        }

        for (int j = 0; j < i; j++)
        {
            cout<<"#";           
        }

        space -= 2;
        cout<<endl;
    }
}



void pattern4(int n )
{
    int space = 2*n;
    for(int i = 1; i <= n+1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout<<"#";           
        }

        for (int k = 0; k < space; k++)
        {
           cout<<" ";
        }

        for (int j = 0; j < i; j++)
        {
            cout<<"#";           
        }

        space -= 2;
        cout<<endl;
    }
}



int main()
{
    int n = 4;
 
    pattern3(n);
    pattern31(n);
}