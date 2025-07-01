#include <iostream>
using namespace std;
//reversing an integer
int reverseInt(int num){
    int len = to_string(num).length();
    int res = 0;
    for(int i=0; i<len; i++){
        int rem = num%10;
        res = res + rem*(pow(10,len-i-1));
        num = num/10;
    }
    return res;
}

int main()
{
    int n;
    cout<<"Enter the number:";
    cin>>n;

    cout<<"Reverse of the number is:"<<reverseInt(n)<<endl;

    return 0;
}