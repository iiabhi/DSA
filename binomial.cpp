#include <iostream>
using namespace std;

int fact(int num){
    int fact = 1;
    for(int i=1; i<=num; i++){
        fact = fact*i;
    }
    return fact;
}

float nCr(int n, int r){
    if(n>r){
    float res = fact(n) / ((fact(n-r))*(fact(r)));
    return res;
    }else{
        cout<<"Invalid Attempt"<<endl;
        return -1;
    }
}
int main()
{

    int n,r;
    cout<<"Enter value for n:"<<endl;
    cin>>n;
    cout<<"Enter value for r:"<<endl;
    cin>>r;
    cout<<"The binomial coefficient is: "<< nCr(n,r)<<endl;
    return 0;
}