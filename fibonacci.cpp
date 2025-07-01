#include <iostream>
using namespace std;

void fibonacci(double num){
    if(num == 1){
        cout<<0;
    }else if(num == 2){
        cout<<0<<" "<<1;
    }else if(num>2){
        cout<<0<<" "<<1<<" ";
        double secondLastNum = 0;
        double lastNum = 1;
        for(int i=2; i<num;i++){
            double sum = lastNum + secondLastNum;
            secondLastNum = lastNum;
            lastNum = sum;
            cout<<sum<<" ";
        }
        cout<<endl;
    }else{
        cout<<"invalid input"<<endl;
    }
}
int main()
{
    double n;
    cout<<"Enter the no.:";
    cin>>n;
    fibonacci(n);
    return 0;
}