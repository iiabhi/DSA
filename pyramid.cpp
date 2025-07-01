#include <iostream>
using namespace std;
int main()
{int n;
    cout<<"Enter n:";
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=n-1; j>i; j--){
            cout<<" ";
        }
        for(int k=0; k<i+1; k++){
            cout<<k+1;
        }
        for(int l=i;l>0; l--){
            cout<<l;
        }
        cout<<endl;

    }
    return 0;
}