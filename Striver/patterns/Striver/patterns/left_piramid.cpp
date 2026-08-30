
////its simple one like * ** *** 

#include<bits/stdc++.h>

using namespace std;


void tringle(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
}

int main(void)
{
    int n = 5;
    tringle(n);
}



// /// its like with 1   12    123 
// #include<bits/stdc++.h>

// using namespace std;


// void tringle(int n)
// {
//     for(int i = 0; i < n; i++)
//     {
//         for(int j = 1; j <= i+1; j++)
//         {
//             cout<<i;
//         }
//         cout<<endl;
//     }
// }

// int main(void)
// {
//     int n = 5;
//     tringle(n);
// }



// /// its like with 1   22   333 


// #include<bits/stdc++.h>

// using namespace std;


// void tringle(int n)
// {
//     for(int i = 1; i < n+1; i++)
//     {
//         for(int j = 0; j <= i; j++)
//         {
//             cout<<i;
//         }
//         cout<<endl;
//     }
// }

// int main(void)
// {
//     int n = 5;
//     tringle(n);
// }