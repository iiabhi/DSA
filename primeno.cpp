#include <iostream>
using namespace std;
void primeSeries(int number){
    for(int i=2; i<=number; i++){
        bool isPrime = true;
        for(int j=2; j*j<=i; j++){
            if(i%j == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime){
            cout<<i<<" ";
        }

        
    }
}
int main()
{
    int n;
    cout<<"Enter no.";
    cin>>n;
    primeSeries(n);

    return 0;
}