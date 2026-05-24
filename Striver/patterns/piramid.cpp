// #include <bits/stdc++.h>

// using namespace std;

// void pattern(int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for(int j = 0; j < n-i-1; j++)
//         {
//             cout<<" ";
//         }

//         for(int k = 0; k < 2*i+1; k++)
//         {
//             cout<<"#";
//         }

//         cout<<endl;
//     }
// }

// int main(void)
// {
//     int n = 5;
//     pattern(n);
// }



///////////oppoosite of taht one like  **********     ***  *  


#include <bits/stdc++.h>
using namespace std;

void pattern (int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            cout<<" ";
        }
        
        for(int k = 0; k < 2*n - (2 * i +1); k++)
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