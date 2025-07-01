#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter n:";
    cin>>n;
    int num =1;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout<<num; //or cout<<i+1; and line 13 need not exist.
        }
        num++;
        cout<<endl;
    }
    return 0;
}