#include <iostream>
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

int binarySum(int binNum1, int binNum2){
    int x = binaryToDecimal(binNum1);
    int y = binaryToDecimal(binNum2);
    int sum = x+y;
    int binSum = decimalToBinary(sum);
    return binSum;
}

string twoSComplement(string bin){
    //inverse
    for(int i=0; i<bin.length(); i++){
        if(bin[i] == '0'){
            bin[i] = '1';
        }else{
            bin[i] = '0';
        }
    }
    //add 1
    int carry = 1;
    for(int i= bin.length()-1; i>=0; i--){
        if(bin[i]=='1' && carry == 1){
            bin[i]='0';
        }else if(carry == 1){
            bin[i]='1';
            carry = '0';
            break;
        }
    }
    if(carry == 1){
        bin = '1'+bin;
    }
    return bin;

}

//To print binary of a decimal number
void printBin(int num){
    for(int i=31; i>=0; i--){
        cout<<((num>>i)&1);
    }
    cout<<endl;
}

int main()
{
    int n1;
    cout<<"Enter binary num 1:";
    cin>>n1;
    int n2;
    cout<<"Enter binary num 2:";
    cin>>n2;
    int decNum;
    cout<<"Enter the decimal number:";
    cin>>decNum;
    string bin1;
    cout<<"Enter the binary number:";
    cin>>bin1;


    cout<<"Addition of binary numbers:"<<binarySum(n1,n2)<<endl;

    cout<<"Two's Complement of n1:"<<twoSComplement(bin1)<<endl;
    
    
    cout<<"Binary equivalent :"<<endl;
    printBin(decNum);

    return 0;
}