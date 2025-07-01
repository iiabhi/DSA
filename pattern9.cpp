#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter n:";
    cin>>n;
    int num=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cout<<num-j;
        }
        num++;
        cout<<endl;
    }
    // or
    for(int i=0; i<n; i++){
        for(int j=i+1; j>0; j--){
            cout<<j;
        }
        cout<<endl;
    }
    return 0;
}