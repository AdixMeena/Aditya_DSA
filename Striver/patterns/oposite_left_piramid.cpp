// // thats the simple version of **** *** ** *

// #include <bits/stdc++.h>
// using namespace std;

// void pattern(int n)
// {
//     for(int i = 0; i < n; i++)
//     {
//         for (int j  = n; j > i; j--)
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


// thats the version of 4321 321 21 1

// #include <bits/stdc++.h>
// using namespace std;

// void pattern(int n)
// {
//     for(int i = 0; i < n; i++)
//     {
//         for (int j  = n; j > i; j--)
//         {
//             cout<<j;
//         }
//         cout<<endl;
//     }
// }

// int main(void)
// {
//     int n = 5;
//     pattern(n);

// }



// // thats the version of 1234 123 12 1 

#include <bits/stdc++.h>
using namespace std;

void pattern(int n)
{
    for(int i = 0; i < n; i++)
    {
        for (int j  = 1; j <= n-i ; j++)
        {
            cout<<j;
        }
        cout<<endl;
    }
}

int main(void)
{
    int n = 5;
    pattern(n);
}