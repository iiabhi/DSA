#include <iostream>
#include <cmath>
using namespace std;
int decimalToBinary(int num){
    int res = 0;
    int pow = 1;
    while(num>0){
        int rem = num%2;
        num = num/2;
        res = res + rem*pow;
        pow = pow*10;
    }
    return res;
}
int binaryToDecimal(int num){
    int len = to_string(num).length();
    int res = 0;
    for(int i=0; i<len; i++){
        int rem = num%10;
        num = num/10;
        res = res + rem*(pow(2,i)); 
    }
    return res;
}
int main()
{
    int number;
    cout<<"Enter decimal number:";
    cin>>number;
    cout<<"Binary equivalent of "<<number<<" is "<<decimalToBinary(number)<<endl;

    int binNumber;
    cout<<"Enter Binary number:";
    cin>>binNumber;
    cout<<"Decimal equivalent of "<<binNumber<<" is "<<binaryToDecimal(binNumber)<<endl;
    return 0;
}