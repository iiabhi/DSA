#include <iostream>
#include <cstring>
using namespace std;
int digitSum(int number){
    int sum=0;
    int length= to_string(number).length();
    for(int i=0; i<length; i++){
        int rem = number%10;
        sum = sum + rem;
        number = number/10;
    }
    return sum;
}
int main()
{
    int num;
    cout<<"Enter your number:";
    cin>>num;
    int res = digitSum(num);
    cout<<"The result is: "<<res<<endl;
    return 0;
}