#include <iostream>
using namespace std;
int main()
{
    int n= 1;
    cout<<__builtin_popcount(n)<<endl;

    long a = 10;
    cout<<__builtin_popcountl(a)<<endl;

    long long b = 1639309;
    cout<<__builtin_popcountll(b)<<endl;

    char str[100];
    cin.getline(str, 100, '.');
    cout<<str<<endl;
    return 0;
}