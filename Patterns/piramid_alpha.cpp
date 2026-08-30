// #include<bits/stdc++.h>
// using namespace std;

// void pattern(int n )
// {
//     char letter = 'A';
//     for (int i = 0; i < n; i++)
//     {
//         for(int j = 0; j <= i; j++)
//         {
//             cout<<letter<<" ";

//             letter+= 1;
//         }
//         cout<<endl;
//     }
// }

// int main()
// {
//     int n = 5;

//     pattern(n);
// }


////////its opposite 

// #include<bits/stdc++.h>
// using namespace std;

// void pattern(int n )
// {
//     char letter = 'A';
//     for (int i = 0; i < n; i++)
//     {
//         for(int j = n; j >= i; j--)
//         {
//             cout<<letter<<" ";

//             letter+= 1;
//         }
//         cout<<endl;
//     }
// }

// int main()
// {
//     int n = 5;

//     pattern(n);
// }




///////now same but it shoud like reset everline start with a 



// #include<bits/stdc++.h>
// using namespace std;

// void pattern(int n )
// {
//     char letter = 'A';
//     for (int i = 0; i <= n; i++)
//     {
//         letter = 'A';
//         for(int j = n; j >= i; j--)
//         {
            
//             cout<<letter<<" ";

//             letter+= 1;
//         }
//         cout<<endl;
//     }
// }

// int main()
// {
//     int n = 5;

//     pattern(n);
// }



////////////NOW EVERLINE HAVE LIKE AAAAA BBBBBB CCCCCCCC

// #include<bits/stdc++.h>
// using namespace std;

// void pattern(int n )
// {
//     char letter = 'A';
//     for (int i = 0; i < n; i++)
//     {
//         for(int j = 0; j <= i; j++)
//         {
//             cout<<letter<<" ";            
//         }
//         cout<<endl;
//         letter++;
//     }
// }

// int main()
// {
//     int n = 5;

//     pattern(n);
// }