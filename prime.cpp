#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;
    bool isPrime=true;
    if(n==1 || n==0){
        cout<<"No prime"<<endl;
    }else{
    for(int i=2; i<=n; i++){
        isPrime = true;
        for(int j=2; j*j<=i; j++){
            if(i%j == 0){
                isPrime = false;
            } 
        }
        if(isPrime == true){
            cout<<i<<endl;
        }  
    }
}
    return 0;
}