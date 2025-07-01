#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            cout << " ";
        }
        cout << "*";
        for (int k = 0; k < 2 * i - 1; k++)
        {
            cout << " ";
        }
        if (i)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 1; j<=i+1; j++)
        {
            cout << " ";
        }
        cout << "*";
        for (int k = 0;k< 2*(n-i)-5;  k++)
        {
            cout << " ";
        }
        if (i<n-2)
        {
            cout << "*";
        }
        cout << endl;
    }
    
    return 0;
}